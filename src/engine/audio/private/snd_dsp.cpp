// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: engine/audio/private/snd_dsp.cpp
// Functions: 182
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x1001D780
// Name: char const __near * GetIndentationText(int)
// Source: json
//------------------------------------------------------------------------------
char *__cdecl GetIndentationText(int nIndentation)
{
  int v1; // ecx

  if ( sFirstTime )
  {
    strcpy(sIndentationBuffer, "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t");
    sFirstTime = false;
  }
  v1 = nIndentation;
  if ( nIndentation > 32 )
    v1 = 32;
  return &byte_1045F364[-v1];
}

//------------------------------------------------------------------------------
// Address: 0x1001D7E0
// Name: int IIRFilter_Update_Order1(int __near *,int,int __near *,int __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl IIRFilter_Update_Order1(int *denom, int cnumer, int *numer, int *psamp, int in)
{
  int result; // eax
  int v6; // esi
  int v7; // ecx

  if ( *psamp == 0 && psamp[1] == 0 && in == 0 )
    return 0;
  v6 = psamp[1];
  v7 = in - ((v6 * denom[1]) >> 12);
  *psamp = v7;
  result = (v7 * *numer + v6 * numer[1]) >> 12;
  psamp[1] = v7;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1001D830
// Name: void ReverbSimple_Opt(int,int,int __near *,int __near * __near *,int,int,int __near *,int __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ReverbSimple_Opt(
        int delaysize,
        int tdelay,
        int *psamps,
        int **ppsamp,
        int fbgain,
        int outgain,
        int *pIn,
        int *pOut,
        int nCount)
{
  int *v10; // eax
  int v11; // eax
  int v12; // eax
  int v13; // [esp+4h] [ebp-4h]

  if ( nCount > 0 )
  {
    v13 = 4 * delaysize;
    do
    {
      --nCount;
      v10 = &(*ppsamp)[tdelay];
      if ( v10 > &psamps[delaysize] )
        v11 = v10[v13 / 0xFFFFFFFC - 1];
      else
        v11 = *v10;
      v12 = *pIn + ((fbgain * v11) >> 12);
      *(*ppsamp)-- = v12;
      if ( *ppsamp < psamps )
        *ppsamp = (int *)((char *)*ppsamp + v13 + 4);
      pIn += 2;
      *pOut++ += (outgain * v12) >> 12;
    }
    while ( nCount > 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001D8B0
// Name: int ReverbSimple_multitap(int,int,int,int,int,int __near *,int __near * __near *,int,int,int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ReverbSimple_multitap(
        int delaysize,
        int tdelay0,
        int tdelay1,
        int tdelay2,
        int tdelay3,
        int *psamps,
        int **ppsamp,
        int fbgain,
        int outgain,
        int in)
{
  _DWORD *v11; // edx
  int v12; // edi
  int *v13; // eax
  int *v14; // ecx
  int v15; // eax
  int *v16; // eax
  int v17; // eax
  int *v18; // eax
  int v19; // ebx
  int *v20; // eax
  int v21; // eax
  int s1; // [esp+18h] [ebp+Ch]
  int s2; // [esp+2Ch] [ebp+20h]

  v11 = *ppsamp;
  v12 = 4 * delaysize;
  v13 = &(*ppsamp)[tdelay0];
  v14 = &psamps[delaysize];
  if ( v13 > v14 )
    v15 = v13[v12 / 0xFFFFFFFC - 1];
  else
    v15 = *v13;
  s1 = v15;
  v16 = &v11[tdelay1];
  if ( v16 > v14 )
    v17 = v16[v12 / 0xFFFFFFFC - 1];
  else
    v17 = *v16;
  s2 = v17;
  v18 = &v11[tdelay2];
  if ( v18 > v14 )
    v19 = v18[v12 / 0xFFFFFFFC - 1];
  else
    v19 = *v18;
  v20 = &v11[tdelay3];
  if ( v20 > v14 )
    v21 = v20[v12 / 0xFFFFFFFC - 1];
  else
    v21 = *v20;
  *v11 = in + ((fbgain * v21) >> 12);
  if ( --*ppsamp < psamps )
    *ppsamp = (int *)((char *)*ppsamp + v12 + 4);
  return (outgain * (s1 + s2 + v21 + v19 + in)) >> 12;
}

//------------------------------------------------------------------------------
// Address: 0x1001D950
// Name: void ReverbSimple_multitap_Opt(int,int,int,int,int,int __near *,int __near * __near *,int,int,int __near *,int __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ReverbSimple_multitap_Opt(
        int delaysize,
        int tdelay0,
        int tdelay1,
        int tdelay2,
        int tdelay3,
        int *psamps,
        int **ppsamp,
        int fbgain,
        int outgain,
        int *pIn,
        int *pOut,
        int nCount)
{
  int v12; // ecx
  int *v13; // ebx
  int v14; // edi
  _DWORD *v15; // edx
  int *v16; // eax
  int v17; // eax
  int *v18; // eax
  int v19; // eax
  int *v20; // eax
  int v21; // ecx
  int *v22; // eax
  int v23; // eax
  int v24; // ecx
  int v25; // [esp+4h] [ebp-Ch]
  int v26; // [esp+8h] [ebp-8h]
  int v27; // [esp+Ch] [ebp-4h]

  if ( nCount > 0 )
  {
    v12 = 4 * delaysize;
    v13 = &psamps[delaysize];
    v27 = 4 * delaysize;
    while ( 1 )
    {
      v14 = *pIn;
      v15 = *ppsamp;
      --nCount;
      v16 = &(*ppsamp)[tdelay0];
      v17 = v16 > v13 ? v16[v12 / 0xFFFFFFFC - 1] : *v16;
      v25 = v17;
      v18 = &v15[tdelay1];
      v19 = v18 > v13 ? v18[v12 / 0xFFFFFFFC - 1] : *v18;
      v26 = v19;
      v20 = &v15[tdelay2];
      v21 = v20 > v13 ? v20[v12 / 0xFFFFFFFC - 1] : *v20;
      v22 = &v15[tdelay3];
      v23 = v22 > v13 ? v22[v27 / 0xFFFFFFFC - 1] : *v22;
      v24 = v25 + v26 + v23 + v21;
      *v15 = v14 + ((fbgain * v23) >> 12);
      if ( --*ppsamp < psamps )
        *ppsamp = (int *)((char *)*ppsamp + v27 + 4);
      pIn += 2;
      *pOut++ += (outgain * (v14 + v24)) >> 12;
      if ( nCount <= 0 )
        break;
      v13 = &psamps[delaysize];
      v12 = 4 * delaysize;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001DA40
// Name: int ReverbSimple_multitap_xfade(int,int,int,int,int,int,int,int __near *,int __near * __near *,int,int,int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ReverbSimple_multitap_xfade(
        int delaysize,
        int tdelay0,
        int tdelaynew,
        int xf,
        int tdelay1,
        int tdelay2,
        int tdelay3,
        int *psamps,
        int **ppsamp,
        int fbgain,
        int outgain,
        int in)
{
  _DWORD *v13; // edx
  int v14; // ebx
  int *v15; // eax
  int *v16; // esi
  int v17; // ecx
  int *v18; // eax
  int v19; // eax
  int v20; // eax
  int *v21; // ecx
  int v22; // ecx
  int *v23; // ecx
  int v24; // ecx
  int *v25; // ecx
  int v26; // ecx
  int v27; // ecx
  int s1; // [esp+2Ch] [ebp+20h]
  int s2; // [esp+34h] [ebp+28h]

  v13 = *ppsamp;
  v14 = 4 * delaysize;
  v15 = &(*ppsamp)[tdelay3];
  v16 = &psamps[delaysize];
  if ( v15 > v16 )
    v17 = v15[v14 / 0xFFFFFFFC - 1];
  else
    v17 = *v15;
  v18 = &v13[tdelaynew];
  if ( v18 > v16 )
    v19 = v18[v14 / 0xFFFFFFFC - 1];
  else
    v19 = *v18;
  v20 = v17 + ((xf * (v19 - v17)) >> 12);
  v21 = &v13[tdelay0];
  if ( v21 > v16 )
    v22 = v21[v14 / 0xFFFFFFFC - 1];
  else
    v22 = *v21;
  s1 = v22;
  v23 = &v13[tdelay1];
  if ( v23 > v16 )
    v24 = v23[v14 / 0xFFFFFFFC - 1];
  else
    v24 = *v23;
  s2 = v24;
  v25 = &v13[tdelay2];
  if ( v25 > v16 )
    v26 = v25[v14 / 0xFFFFFFFC - 1];
  else
    v26 = *v25;
  v27 = v20 + s1 + s2 + v26;
  *v13 = in + ((fbgain * v20) >> 12);
  if ( --*ppsamp < psamps )
    *ppsamp = (int *)((char *)*ppsamp + v14 + 4);
  return (outgain * (v27 + in)) >> 12;
}

//------------------------------------------------------------------------------
// Address: 0x1001DB00
// Name: int DelayLinear(int,int,int __near *,int __near * __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl DelayLinear(int delaysize, int tdelay, int *psamps, int **ppsamp, int in)
{
  int v5; // edx
  int *v6; // eax
  int result; // eax

  v5 = 4 * delaysize;
  v6 = &(*ppsamp)[tdelay];
  if ( v6 > &psamps[delaysize] )
    result = v6[v5 / 0xFFFFFFFC - 1];
  else
    result = *v6;
  *(*ppsamp)-- = in;
  if ( *ppsamp < psamps )
    *ppsamp = (int *)((char *)*ppsamp + v5 + 4);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1001DB50
// Name: void DelayLinear_Opt(int,int,int __near *,int __near * __near *,int __near *,int __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DelayLinear_Opt(int delaysize, int tdelay, int *psamps, int **ppsamp, int *pIn, int *pOut, int nCount)
{
  int *v8; // eax
  int v9; // eax
  int v10; // [esp+4h] [ebp-4h]

  if ( nCount > 0 )
  {
    v10 = 4 * delaysize;
    do
    {
      --nCount;
      v8 = &(*ppsamp)[tdelay];
      if ( v8 > &psamps[delaysize] )
        v9 = v8[v10 / 0xFFFFFFFC - 1];
      else
        v9 = *v8;
      *(*ppsamp)-- = *pIn;
      if ( *ppsamp < psamps )
        *ppsamp = (int *)((char *)*ppsamp + v10 + 4);
      *pOut += v9;
      pIn += 2;
      ++pOut;
    }
    while ( nCount > 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001DBC0
// Name: int DelayLinear_xfade(int,int,int,int,int __near *,int __near * __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl DelayLinear_xfade(int delaysize, int tdelay, int tdelaynew, int xf, int *psamps, int **ppsamp, int in)
{
  _DWORD *v7; // esi
  int v8; // edi
  int *v9; // eax
  int *v10; // ebx
  int v11; // eax
  int *v12; // ecx
  int v13; // ecx
  int result; // eax

  v7 = *ppsamp;
  v8 = 4 * delaysize;
  v9 = &(*ppsamp)[tdelay];
  v10 = &psamps[delaysize];
  if ( v9 > v10 )
    v11 = v9[v8 / 0xFFFFFFFC - 1];
  else
    v11 = *v9;
  v12 = &v7[tdelaynew];
  if ( v12 > v10 )
    v13 = v12[v8 / 0xFFFFFFFC - 1];
  else
    v13 = *v12;
  result = ((xf * (v13 - v11)) >> 12) + v11;
  *v7 = in;
  if ( --*ppsamp < psamps )
    *ppsamp = (int *)((char *)*ppsamp + v8 + 4);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1001DC30
// Name: int DelayLowPass(int,int,int __near *,int __near * __near *,int,int,int __near *,int,int __near *,int __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl DelayLowPass(
        int delaysize,
        int tdelay,
        int *psamps,
        int **ppsamp,
        int fbgain,
        int outgain,
        int *denom,
        int Ll,
        int *numer,
        int *pfsamps,
        int in)
{
  int v11; // edi
  int *v12; // eax
  int v13; // eax
  int v14; // edi
  int v15; // ecx
  int v16; // eax
  int v17; // eax

  v11 = 4 * delaysize;
  v12 = &(*ppsamp)[tdelay];
  if ( v12 > &psamps[delaysize] )
    v13 = v12[v11 / 0xFFFFFFFC - 1];
  else
    v13 = *v12;
  if ( *pfsamps != 0 || pfsamps[1] != 0 || v13 != 0 )
  {
    v14 = pfsamps[1];
    v15 = v13 - ((v14 * denom[1]) >> 12);
    *pfsamps = v15;
    v16 = v15 * *numer + v14 * numer[1];
    v11 = 4 * delaysize;
    v13 = v16 >> 12;
    pfsamps[1] = v15;
  }
  v17 = in + v13;
  *(*ppsamp)-- = v17;
  if ( *ppsamp < psamps )
    *ppsamp = (int *)((char *)*ppsamp + v11 + 4);
  return (outgain * v17) >> 12;
}

//------------------------------------------------------------------------------
// Address: 0x1001DCD0
// Name: void DelayLowPass_Opt2(int,int,int __near *,int __near * __near *,int,int,int __near *,int,int __near *,int __near *,int __near *,int __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DelayLowPass_Opt2(
        int nDelaySize,
        int tdelay,
        int *psamps,
        int **ppsamp,
        int fbgain,
        int outgain,
        int *denom,
        int Ll,
        int *numer,
        int *pfsamps,
        int *pIn,
        int *pOut,
        int nCount)
{
  int *v13; // edx
  int *v14; // edi
  int v15; // esi
  int v16; // ecx
  int v18; // eax
  int v19; // ecx
  int v20; // eax
  int numer1; // [esp+8h] [ebp-8h]
  int numer0; // [esp+Ch] [ebp-4h]
  int nDelaySizeP1; // [esp+18h] [ebp+8h]
  int denom1; // [esp+30h] [ebp+20h]
  int *pSampsPDelaySize; // [esp+38h] [ebp+28h]

  numer0 = *numer;
  denom1 = denom[1];
  numer1 = numer[1];
  v13 = *ppsamp;
  v14 = pfsamps;
  v15 = pfsamps[1];
  pSampsPDelaySize = &psamps[nDelaySize];
  v16 = nDelaySize + 1;
  nDelaySizeP1 = nDelaySize + 1;
  if ( nCount > 0 )
  {
    do
    {
      v18 = v13[tdelay - (v16 & (((char *)pSampsPDelaySize - (char *)&v13[tdelay]) >> 31))] - ((v15 * denom1) >> 12);
      --nCount;
      v19 = v15 * numer1 + numer0 * v18;
      v15 = v18;
      v20 = (v19 >> 12) + *pIn;
      v16 = nDelaySizeP1;
      *v13 = v20;
      pIn += 2;
      *pOut++ += (outgain * v20) >> 12;
      v13 = &v13[(nDelaySizeP1 & (((char *)(v13 - 1) - (char *)psamps) >> 31)) - 1];
    }
    while ( nCount > 0 );
    v14 = pfsamps;
  }
  *ppsamp = v13;
  *v14 = v15;
  v14[1] = v15;
}

//------------------------------------------------------------------------------
// Address: 0x1001DDA0
// Name: void DelayLowPass_Opt3(int,int,int __near *,int __near * __near *,int,int,int __near *,int,int __near *,int __near *,int __near *,int __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DelayLowPass_Opt3(
        int nDelaySize,
        int *tdelay,
        int *psamps,
        int **ppsamp,
        int fbgain,
        int outgain,
        int *denom,
        int Ll,
        int *numer,
        int *pfsamps,
        int *pIn,
        int *pOut,
        unsigned int nCount)
{
  int v13; // eax
  int v14; // edi
  int v15; // ebx
  int *v16; // ecx
  int v17; // esi
  int *v18; // edx
  int *v19; // esi
  int v20; // eax
  int v21; // edx
  int v22; // eax
  int v23; // edx
  int v24; // eax
  int v25; // ecx
  int v26; // edx
  int v27; // eax
  int v28; // ecx
  int v29; // edx
  unsigned int v30; // [esp+0h] [ebp-30h]
  int outA; // [esp+4h] [ebp-2Ch]
  int denom1; // [esp+8h] [ebp-28h]
  int *pSampsPDelaySize; // [esp+Ch] [ebp-24h]
  int pInputDelaySampleD; // [esp+10h] [ebp-20h]
  int *v35; // [esp+14h] [ebp-1Ch]
  int *pDelaySampleA; // [esp+18h] [ebp-18h]
  int numer0; // [esp+1Ch] [ebp-14h]
  int numer1; // [esp+20h] [ebp-10h]
  int nFilteredOutputA; // [esp+24h] [ebp-Ch]
  int *pDelaySampleC; // [esp+28h] [ebp-8h]
  int *pDelaySampleB; // [esp+2Ch] [ebp-4h]
  int *pDelaySampleD; // [esp+3Ch] [ebp+Ch]

  v13 = nDelaySize;
  if ( (int *)nDelaySize == tdelay )
  {
    v14 = pfsamps[1];
    numer0 = *numer;
    v15 = denom[1];
    numer1 = numer[1];
    v16 = *ppsamp;
    v17 = nDelaySize + 1;
    denom1 = v15;
    pSampsPDelaySize = &psamps[nDelaySize];
    nFilteredOutputA = nDelaySize + 1;
    if ( (nCount & 3) != 0 )
    {
      while ( 1 )
      {
        v20 = v16[v13 - (nFilteredOutputA & (((char *)pSampsPDelaySize - (char *)&v16[v13]) >> 31))]
            - ((v14 * v15) >> 12);
        --nCount;
        v21 = (v14 * numer1 + numer0 * v20) >> 12;
        v14 = v20;
        v22 = v21 + *pIn;
        *v16 = v22;
        pIn += 2;
        v17 = nDelaySize + 1;
        v16 = &v16[((nDelaySize + 1) & (((char *)(v16 - 1) - (char *)psamps) >> 31)) - 1];
        *pOut += (outgain * v22) >> 12;
        v18 = pOut + 1;
        nFilteredOutputA = nDelaySize + 1;
        ++pOut;
        if ( (nCount & 3) == 0 )
          break;
        v13 = nDelaySize;
      }
    }
    else
    {
      v18 = pOut;
    }
    pDelaySampleA = v16;
    pDelaySampleB = &v16[(v17 & (((char *)(v16 - 1) - (char *)psamps) >> 31)) - 1];
    pDelaySampleC = &v16[(v17 & (((char *)(v16 - 2) - (char *)psamps) >> 31)) - 2];
    pDelaySampleD = &v16[(v17 & (((char *)(v16 - 3) - (char *)psamps) >> 31)) - 3];
    if ( (int)nCount >= 4 )
    {
      v19 = v18 + 2;
      v35 = pIn + 4;
      v30 = nCount >> 2;
      while ( 1 )
      {
        v23 = *pDelaySampleB - ((v14 * v15) >> 12);
        v24 = numer1 * v23;
        v25 = *pDelaySampleC - ((v15 * v23) >> 12);
        v26 = *pDelaySampleD - ((v15 * v25) >> 12);
        pInputDelaySampleD = pDelaySampleD[nDelaySize
                                         - ((nDelaySize + 1)
                                          & (((char *)pSampsPDelaySize - (char *)&pDelaySampleD[nDelaySize]) >> 31))]
                           - ((denom1 * v26) >> 12);
        outA = ((v14 * numer1 + numer0 * (*pDelaySampleB - ((v14 * v15) >> 12))) >> 12) + *(v35 - 4);
        v27 = *(v35 - 2) + ((numer0 * v25 + v24) >> 12);
        v28 = *v35 + ((numer0 * v26 + numer1 * v25) >> 12);
        v29 = v35[2] + ((numer0 * pInputDelaySampleD + numer1 * v26) >> 12);
        v35 += 8;
        *pDelaySampleA = outA;
        *pDelaySampleB = v27;
        *pDelaySampleC = v28;
        *pDelaySampleD = v29;
        pDelaySampleA = &pDelaySampleA[((nDelaySize + 1) & (((char *)(pDelaySampleA - 4) - (char *)psamps) >> 31)) - 4];
        v19 += 4;
        pDelaySampleB = &pDelaySampleB[((nDelaySize + 1) & (((char *)(pDelaySampleB - 4) - (char *)psamps) >> 31)) - 4];
        pDelaySampleC = &pDelaySampleC[((nDelaySize + 1) & (((char *)(pDelaySampleC - 4) - (char *)psamps) >> 31)) - 4];
        pDelaySampleD = &pDelaySampleD[((nDelaySize + 1) & (((char *)(pDelaySampleD - 4) - (char *)psamps) >> 31)) - 4];
        *(v19 - 6) += (outgain * outA) >> 12;
        v14 = pInputDelaySampleD;
        *(v19 - 5) += (outgain * v27) >> 12;
        *(v19 - 4) += (outgain * v28) >> 12;
        *(v19 - 3) += (outgain * v29) >> 12;
        if ( --v30 == 0 )
          break;
        v15 = denom1;
      }
    }
    *ppsamp = pDelaySampleA;
    *pfsamps = v14;
    pfsamps[1] = v14;
  }
  else
  {
    DelayLowPass_Opt2(
      nDelaySize,
      (int)tdelay,
      psamps,
      ppsamp,
      fbgain,
      outgain,
      denom,
      Ll,
      numer,
      pfsamps,
      pIn,
      pOut,
      nCount);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001E0C0
// Name: int DelayLowpass_xfade(int,int,int,int,int __near *,int __near * __near *,int,int,int __near *,int,int __near *,int __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl DelayLowpass_xfade(
        int delaysize,
        int tdelay,
        int tdelaynew,
        int xf,
        int *psamps,
        int **ppsamp,
        int fbgain,
        int outgain,
        int *denom,
        int Ll,
        int *numer,
        int *pfsamps,
        int in)
{
  int v13; // ebx
  int *v14; // eax
  int *v15; // esi
  int v16; // ecx
  int *v17; // eax
  int v18; // eax
  int v19; // ecx
  int v20; // eax
  int v21; // esi
  int v22; // ecx
  int v23; // eax

  v13 = 4 * delaysize;
  v14 = &(*ppsamp)[tdelay];
  v15 = &psamps[delaysize];
  if ( v14 > v15 )
    v16 = v14[v13 / 0xFFFFFFFC - 1];
  else
    v16 = *v14;
  v17 = &(*ppsamp)[tdelaynew];
  if ( v17 > v15 )
    v18 = v17[v13 / 0xFFFFFFFC - 1];
  else
    v18 = *v17;
  v19 = ((xf * (v18 - v16)) >> 12) + v16;
  if ( *pfsamps != 0 || pfsamps[1] != 0 || v19 != 0 )
  {
    v21 = pfsamps[1];
    v22 = v19 - ((v21 * denom[1]) >> 12);
    *pfsamps = v22;
    v13 = 4 * delaysize;
    v20 = (v22 * *numer + v21 * numer[1]) >> 12;
    pfsamps[1] = v22;
  }
  else
  {
    v20 = 0;
  }
  v23 = in + v20;
  *(*ppsamp)-- = v23;
  if ( *ppsamp < psamps )
    *ppsamp = (int *)((char *)*ppsamp + v13 + 4);
  return (outgain * v23) >> 12;
}

//------------------------------------------------------------------------------
// Address: 0x1001E180
// Name: int DelayLowpass_multitap(int,int,int,int,int,int __near *,int __near * __near *,int,int,int __near *,int,int __near *,int __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl DelayLowpass_multitap(
        int delaysize,
        int tdelay0,
        int tdelay1,
        int tdelay2,
        int tdelay3,
        int *psamps,
        int **ppsamp,
        int fbgain,
        int outgain,
        int *denom,
        int Ll,
        int *numer,
        int *pfsamps,
        int in)
{
  char *v14; // ecx
  int *v15; // eax
  int v16; // ebx
  int *v17; // edx
  int v18; // eax
  int *v19; // esi
  int v20; // eax
  int *v21; // esi
  int v22; // esi
  int *v23; // ecx
  int v24; // ecx
  int v25; // edi
  int v26; // eax
  int v27; // esi
  int v28; // ecx
  int delaysizea; // [esp+10h] [ebp+8h]
  int s1; // [esp+14h] [ebp+Ch]

  v14 = (char *)*ppsamp;
  v15 = &(*ppsamp)[tdelay0];
  v16 = 4 * delaysize;
  v17 = &psamps[delaysize];
  delaysizea = 4 * delaysize;
  if ( v15 > v17 )
    v18 = *(int *)((char *)v15 - v16 - 4);
  else
    v18 = *v15;
  s1 = v18;
  v19 = (int *)&v14[4 * tdelay1];
  if ( v19 > v17 )
    v20 = *(int *)((char *)v19 - v16 - 4);
  else
    v20 = *v19;
  v21 = (int *)&v14[4 * tdelay2];
  if ( v21 > v17 )
    v22 = *(int *)((char *)v21 - v16 - 4);
  else
    v22 = *v21;
  v23 = (int *)&v14[4 * tdelay3];
  if ( v23 > v17 )
    v24 = *(int *)((char *)v23 - v16 - 4);
  else
    v24 = *v23;
  v25 = s1 + v20 + v24 + v22;
  if ( *pfsamps != 0 || pfsamps[1] != 0 || v24 != 0 )
  {
    v27 = pfsamps[1];
    v28 = v24 - ((v27 * denom[1]) >> 12);
    *pfsamps = v28;
    v16 = delaysizea;
    v26 = (v28 * *numer + v27 * numer[1]) >> 12;
    pfsamps[1] = v28;
  }
  else
  {
    v26 = 0;
  }
  *(*ppsamp)-- = in + v26;
  if ( *ppsamp < psamps )
    *ppsamp = (int *)((char *)*ppsamp + v16 + 4);
  return (outgain * (v25 + in)) >> 12;
}

//------------------------------------------------------------------------------
// Address: 0x1001E260
// Name: void DelayLowpass_multitap_Opt(int,int,int,int,int,int __near *,int __near * __near *,int,int,int __near *,int,int __near *,int __near *,int __near *,int __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DelayLowpass_multitap_Opt(
        int delaysize,
        int tdelay0,
        int tdelay1,
        int tdelay2,
        int tdelay3,
        int *psamps,
        int **ppsamp,
        int fbgain,
        int outgain,
        int *denom,
        int Ll,
        int *numer,
        int *pfsamps,
        int *pIn,
        int *pOut,
        int nCount)
{
  int v16; // edx
  int *v17; // esi
  char *v18; // ecx
  int *v19; // eax
  int *v20; // edx
  int v21; // esi
  int *v22; // edx
  int v23; // edx
  int *v24; // ecx
  int v25; // ecx
  int v26; // edx
  int v27; // eax
  int v28; // esi
  int v29; // ecx
  int v30; // [esp+0h] [ebp-10h]
  int v31; // [esp+4h] [ebp-Ch]
  int *v32; // [esp+8h] [ebp-8h]
  int v33; // [esp+Ch] [ebp-4h]

  if ( nCount > 0 )
  {
    v16 = 4 * delaysize;
    v17 = &psamps[delaysize];
    v33 = 4 * delaysize;
    v32 = v17;
    while ( 1 )
    {
      v18 = (char *)*ppsamp;
      --nCount;
      v30 = *pIn;
      v19 = &(*ppsamp)[tdelay0];
      v31 = v19 > v17 ? v19[v16 / 0xFFFFFFFC - 1] : *v19;
      v20 = (int *)&v18[4 * tdelay1];
      v21 = v20 > v17 ? v20[v33 / 0xFFFFFFFC - 1] : *v20;
      v22 = (int *)&v18[4 * tdelay2];
      v23 = v22 > v32 ? v22[v33 / 0xFFFFFFFC - 1] : *v22;
      v24 = (int *)&v18[4 * tdelay3];
      v25 = v24 > v32 ? v24[v33 / 0xFFFFFFFC - 1] : *v24;
      v26 = v31 + v21 + v25 + v23;
      if ( *pfsamps != 0 || pfsamps[1] != 0 || v25 != 0 )
      {
        v28 = pfsamps[1];
        v29 = v25 - ((v28 * denom[1]) >> 12);
        *pfsamps = v29;
        v27 = (v29 * *numer + v28 * numer[1]) >> 12;
        pfsamps[1] = v29;
      }
      else
      {
        v27 = 0;
      }
      *(*ppsamp)-- = v30 + v27;
      if ( *ppsamp < psamps )
        *ppsamp = (int *)((char *)*ppsamp + v33 + 4);
      pIn += 2;
      *pOut++ += (outgain * (v30 + v26)) >> 12;
      if ( nCount <= 0 )
        break;
      v17 = &psamps[delaysize];
      v16 = 4 * delaysize;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001E390
// Name: int DelayLowpass_multitap_xfade(int,int,int,int,int,int,int,int __near *,int __near * __near *,int,int,int __near *,int,int __near *,int __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl DelayLowpass_multitap_xfade(
        int delaysize,
        int tdelay0,
        int tdelaynew,
        int xf,
        int tdelay1,
        int tdelay2,
        int tdelay3,
        int *psamps,
        int **ppsamp,
        int fbgain,
        int outgain,
        int *denom,
        int Ll,
        int *numer,
        int *pfsamps,
        int in)
{
  char *v16; // esi
  int v17; // ebx
  int *v18; // eax
  int *v19; // edi
  int v20; // ecx
  int *v21; // eax
  int v22; // eax
  int *v23; // edx
  int v24; // ecx
  int *v25; // eax
  int v26; // eax
  int *v27; // esi
  int v28; // esi
  int v29; // edi
  int v30; // eax
  int v31; // esi
  int v32; // ecx
  int delaysizea; // [esp+14h] [ebp+8h]
  int s1; // [esp+2Ch] [ebp+20h]

  v16 = (char *)*ppsamp;
  v17 = 4 * delaysize;
  v18 = &(*ppsamp)[tdelay3];
  v19 = &psamps[delaysize];
  delaysizea = 4 * delaysize;
  if ( v18 > v19 )
    v20 = *(int *)((char *)v18 - v17 - 4);
  else
    v20 = *v18;
  v21 = (int *)&v16[4 * tdelaynew];
  if ( v21 > v19 )
    v22 = *(int *)((char *)v21 - v17 - 4);
  else
    v22 = *v21;
  v23 = (int *)&v16[4 * tdelay0];
  v24 = ((xf * (v22 - v20)) >> 12) + v20;
  if ( v23 > v19 )
    s1 = *(int *)((char *)v23 - v17 - 4);
  else
    s1 = *v23;
  v25 = (int *)&v16[4 * tdelay1];
  if ( v25 > v19 )
    v26 = *(int *)((char *)v25 - v17 - 4);
  else
    v26 = *v25;
  v27 = (int *)&v16[4 * tdelay2];
  if ( v27 > v19 )
    v28 = *(int *)((char *)v27 - v17 - 4);
  else
    v28 = *v27;
  v29 = v24 + s1 + v28 + v26;
  if ( *pfsamps != 0 || pfsamps[1] != 0 || v24 != 0 )
  {
    v31 = pfsamps[1];
    v32 = v24 - ((v31 * denom[1]) >> 12);
    *pfsamps = v32;
    v17 = delaysizea;
    v30 = (v32 * *numer + v31 * numer[1]) >> 12;
    pfsamps[1] = v32;
  }
  else
  {
    v30 = 0;
  }
  *(*ppsamp)-- = in + v30;
  if ( *ppsamp < psamps )
    *ppsamp = (int *)((char *)*ppsamp + v17 + 4);
  return (outgain * (v29 + in)) >> 12;
}

//------------------------------------------------------------------------------
// Address: 0x1001E490
// Name: int DelayLinearLowPass(int,int,int __near *,int __near * __near *,int,int,int __near *,int,int __near *,int __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl DelayLinearLowPass(
        int delaysize,
        int tdelay,
        int *psamps,
        int **ppsamp,
        int fbgain,
        int outgain,
        int *denom,
        int cnumer,
        int *numer,
        int *pfsamps,
        int in)
{
  int v11; // esi
  int *v12; // eax
  int v13; // eax
  int v14; // esi
  int v15; // ecx
  int v16; // eax

  v11 = 4 * delaysize;
  v12 = &(*ppsamp)[tdelay];
  if ( v12 > &psamps[delaysize] )
    v13 = v12[v11 / 0xFFFFFFFC - 1];
  else
    v13 = *v12;
  if ( *pfsamps != 0 || pfsamps[1] != 0 || v13 != 0 )
  {
    v14 = pfsamps[1];
    v15 = v13 - ((v14 * denom[1]) >> 12);
    *pfsamps = v15;
    v16 = v15 * *numer + v14 * numer[1];
    v11 = 4 * delaysize;
    v13 = v16 >> 12;
    pfsamps[1] = v15;
  }
  *(*ppsamp)-- = in;
  if ( *ppsamp < psamps )
    *ppsamp = (int *)((char *)*ppsamp + v11 + 4);
  return (outgain * v13) >> 12;
}

//------------------------------------------------------------------------------
// Address: 0x1001E530
// Name: void DelayLinearLowPass_Opt2(int,int,int __near *,int __near * __near *,int,int,int __near *,int,int __near *,int __near *,int __near *,int __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DelayLinearLowPass_Opt2(
        int nDelaySize,
        int tdelay,
        int *psamps,
        int **ppsamp,
        int fbgain,
        int outgain,
        int *denom,
        int Ll,
        int *numer,
        int *pfsamps,
        int *pIn,
        int *pOut,
        int nCount)
{
  int *v13; // ecx
  int *v14; // edi
  int v15; // esi
  int v16; // edx
  int v18; // edx
  int v19; // eax
  int numer1; // [esp+8h] [ebp-8h]
  int numer0; // [esp+Ch] [ebp-4h]
  int nDelaySizeP1; // [esp+18h] [ebp+8h]
  int denom1; // [esp+30h] [ebp+20h]
  int *pSampsPDelaySize; // [esp+38h] [ebp+28h]

  numer1 = numer[1];
  numer0 = *numer;
  denom1 = denom[1];
  v13 = *ppsamp;
  v14 = pfsamps;
  v15 = pfsamps[1];
  pSampsPDelaySize = &psamps[nDelaySize];
  v16 = nDelaySize + 1;
  nDelaySizeP1 = nDelaySize + 1;
  if ( nCount > 0 )
  {
    do
    {
      v18 = v13[tdelay - (v16 & (((char *)pSampsPDelaySize - (char *)&v13[tdelay]) >> 31))] - ((v15 * denom1) >> 12);
      --nCount;
      v19 = outgain * ((v15 * numer1 + numer0 * v18) >> 12);
      v15 = v18;
      *v13 = *pIn;
      *pOut += v19 >> 12;
      pIn += 2;
      v16 = nDelaySizeP1;
      ++pOut;
      v13 = &v13[(nDelaySizeP1 & (((char *)(v13 - 1) - (char *)psamps) >> 31)) - 1];
    }
    while ( nCount > 0 );
    v14 = pfsamps;
  }
  *ppsamp = v13;
  *v14 = v15;
  v14[1] = v15;
}

//------------------------------------------------------------------------------
// Address: 0x1001E600
// Name: void DelayLinearLowPass_Opt3(int,int,int __near *,int __near * __near *,int,int,int __near *,int,int __near *,int __near *,int __near *,int __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DelayLinearLowPass_Opt3(
        int nDelaySize,
        int tdelay,
        int *psamps,
        int **ppsamp,
        int fbgain,
        int outgain,
        int *denom,
        int Ll,
        int *numer,
        int *pfsamps,
        int *pIn,
        int *pOut,
        unsigned int nCount)
{
  int v13; // esi
  int v14; // ebx
  int v15; // edi
  int *v16; // ecx
  int v17; // edx
  int v18; // eax
  int *v19; // edx
  int v20; // eax
  int v21; // ecx
  int v22; // edx
  bool v23; // zf
  unsigned int v24; // [esp+4h] [ebp-2Ch]
  int *v25; // [esp+8h] [ebp-28h]
  int denom1; // [esp+Ch] [ebp-24h]
  int *pInputDelaySampleD; // [esp+10h] [ebp-20h]
  int pInputDelaySampleDa; // [esp+10h] [ebp-20h]
  int *pSampsPDelaySize; // [esp+14h] [ebp-1Ch]
  int numer1; // [esp+18h] [ebp-18h]
  int numer0; // [esp+1Ch] [ebp-14h]
  int *pDelaySampleA; // [esp+20h] [ebp-10h]
  int *v33; // [esp+24h] [ebp-Ch]
  int *pDelaySampleD; // [esp+28h] [ebp-8h]
  int *pDelaySampleC; // [esp+2Ch] [ebp-4h]
  int nDelaySizeP1; // [esp+3Ch] [ebp+Ch]
  int *nDelaySizeP1a; // [esp+3Ch] [ebp+Ch]

  v13 = nDelaySize;
  if ( nDelaySize == tdelay )
  {
    v14 = pfsamps[1];
    numer1 = numer[1];
    v15 = denom[1];
    numer0 = *numer;
    v16 = *ppsamp;
    v17 = nDelaySize + 1;
    denom1 = v15;
    pSampsPDelaySize = &psamps[nDelaySize];
    for ( nDelaySizeP1 = nDelaySize + 1; (nCount & 3) != 0; nDelaySizeP1 = nDelaySize + 1 )
    {
      --nCount;
      v18 = v14 * numer1
          + numer0
          * (v16[v13 - (nDelaySizeP1 & (((char *)pSampsPDelaySize - (char *)&v16[v13]) >> 31))] - ((v14 * v15) >> 12));
      v14 = v16[v13 - (nDelaySizeP1 & (((char *)pSampsPDelaySize - (char *)&v16[v13]) >> 31))] - ((v14 * v15) >> 12);
      *v16 = *pIn;
      pIn += 2;
      v17 = nDelaySize + 1;
      v16 = &v16[((nDelaySize + 1) & (((char *)(v16 - 1) - (char *)psamps) >> 31)) - 1];
      *pOut++ += (outgain * (v18 >> 12)) >> 12;
      v13 = nDelaySize;
    }
    pDelaySampleA = v16;
    nDelaySizeP1a = &v16[(v17 & (((char *)(v16 - 1) - (char *)psamps) >> 31)) - 1];
    pDelaySampleC = &v16[(v17 & (((char *)(v16 - 2) - (char *)psamps) >> 31)) - 2];
    v19 = &v16[(v17 & (((char *)(v16 - 3) - (char *)psamps) >> 31)) - 3];
    pDelaySampleD = v19;
    if ( (int)nCount >= 4 )
    {
      v25 = pOut + 2;
      v33 = pIn + 4;
      v24 = nCount >> 2;
      while ( 1 )
      {
        pInputDelaySampleD = &v19[v13];
        v20 = *nDelaySizeP1a - ((v14 * v15) >> 12);
        v21 = *pDelaySampleC - ((v15 * v20) >> 12);
        v22 = *v19 - ((v15 * v21) >> 12);
        pInputDelaySampleDa = pInputDelaySampleD[-((nDelaySize + 1)
                                                 & (((char *)pSampsPDelaySize - (char *)pInputDelaySampleD) >> 31))]
                            - ((denom1 * v22) >> 12);
        *pDelaySampleA = *(v33 - 4);
        *nDelaySizeP1a = *(v33 - 2);
        *pDelaySampleC = *v33;
        *pDelaySampleD = v33[2];
        v33 += 8;
        pDelaySampleA = &pDelaySampleA[((nDelaySize + 1) & (((char *)(pDelaySampleA - 4) - (char *)psamps) >> 31)) - 4];
        nDelaySizeP1a = &nDelaySizeP1a[((nDelaySize + 1) & (((char *)(nDelaySizeP1a - 4) - (char *)psamps) >> 31)) - 4];
        pDelaySampleC = &pDelaySampleC[((nDelaySize + 1) & (((char *)(pDelaySampleC - 4) - (char *)psamps) >> 31)) - 4];
        pDelaySampleD = &pDelaySampleD[((nDelaySize + 1) & (((char *)(pDelaySampleD - 4) - (char *)psamps) >> 31)) - 4];
        *(v25 - 2) += (outgain * ((v14 * numer1 + numer0 * v20) >> 12)) >> 12;
        *(v25 - 1) += (outgain * ((numer0 * v21 + numer1 * v20) >> 12)) >> 12;
        v14 = pInputDelaySampleDa;
        *v25 += (outgain * ((numer0 * v22 + numer1 * v21) >> 12)) >> 12;
        v25[1] += (outgain * ((numer0 * pInputDelaySampleDa + numer1 * v22) >> 12)) >> 12;
        v23 = v24-- == 1;
        v25 += 4;
        if ( v23 )
          break;
        v13 = nDelaySize;
        v15 = denom1;
        v19 = pDelaySampleD;
      }
    }
    *ppsamp = pDelaySampleA;
    *pfsamps = v14;
    pfsamps[1] = v14;
  }
  else
  {
    DelayLinearLowPass_Opt2(
      nDelaySize,
      tdelay,
      psamps,
      ppsamp,
      fbgain,
      outgain,
      denom,
      Ll,
      numer,
      pfsamps,
      pIn,
      pOut,
      nCount);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001E910
// Name: int DelayLinear_lowpass_xfade(int,int,int,int,int __near *,int __near * __near *,int,int,int __near *,int,int __near *,int __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl DelayLinear_lowpass_xfade(
        int delaysize,
        int tdelay,
        int tdelaynew,
        int xf,
        int *psamps,
        int **ppsamp,
        int fbgain,
        int outgain,
        int *denom,
        int cnumer,
        int *numer,
        int *pfsamps,
        int in)
{
  int **v13; // edi
  int v14; // ebx
  int *v15; // eax
  int *v16; // esi
  int v17; // ecx
  int *v18; // eax
  int v19; // eax
  int v20; // ecx
  int v21; // eax
  int v22; // esi
  int v23; // ecx

  v13 = ppsamp;
  v14 = 4 * delaysize;
  v15 = &(*ppsamp)[tdelay];
  v16 = &psamps[delaysize];
  if ( v15 > v16 )
    v17 = v15[v14 / 0xFFFFFFFC - 1];
  else
    v17 = *v15;
  v18 = &(*ppsamp)[tdelaynew];
  if ( v18 > v16 )
    v19 = v18[v14 / 0xFFFFFFFC - 1];
  else
    v19 = *v18;
  v20 = ((xf * (v19 - v17)) >> 12) + v17;
  if ( *pfsamps != 0 || pfsamps[1] != 0 || v20 != 0 )
  {
    v22 = pfsamps[1];
    v23 = v20 - ((v22 * denom[1]) >> 12);
    *pfsamps = v23;
    v13 = ppsamp;
    v21 = (v23 * *numer + v22 * numer[1]) >> 12;
    pfsamps[1] = v23;
  }
  else
  {
    v21 = 0;
  }
  *(*v13)-- = in;
  if ( *v13 < psamps )
    *v13 = (int *)((char *)*v13 + v14 + 4);
  return (outgain * v21) >> 12;
}

//------------------------------------------------------------------------------
// Address: 0x1001E9C0
// Name: int DelayAllpass(int,int,int __near *,int __near * __near *,int,int,int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl DelayAllpass(int delaysize, int tdelay, int *psamps, int **ppsamp, int fbgain, int outgain, int in)
{
  int v7; // ebx
  int *v8; // eax
  int v9; // esi

  v7 = 4 * delaysize;
  v8 = &(*ppsamp)[tdelay];
  if ( v8 > &psamps[delaysize] )
    v9 = v8[v7 / 0xFFFFFFFC - 1];
  else
    v9 = *v8;
  *(*ppsamp)-- = in + ((fbgain * v9) >> 12);
  if ( *ppsamp < psamps )
    *ppsamp = (int *)((char *)*ppsamp + v7 + 4);
  return (outgain * (v9 + (-(fbgain * (in + ((fbgain * v9) >> 12))) >> 12))) >> 12;
}

//------------------------------------------------------------------------------
// Address: 0x1001EA30
// Name: int DelayAllpass_xfade(int,int,int,int,int __near *,int __near * __near *,int,int,int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl DelayAllpass_xfade(
        int delaysize,
        int tdelay,
        int tdelaynew,
        int xf,
        int *psamps,
        int **ppsamp,
        int fbgain,
        int outgain,
        int in)
{
  _DWORD *v9; // edi
  int v10; // ebx
  int *v11; // eax
  int *v12; // ecx
  int v13; // edx
  int *v14; // eax
  int v15; // eax
  int v16; // edx

  v9 = *ppsamp;
  v10 = 4 * delaysize;
  v11 = &(*ppsamp)[tdelay];
  v12 = &psamps[delaysize];
  if ( v11 > v12 )
    v13 = v11[v10 / 0xFFFFFFFC - 1];
  else
    v13 = *v11;
  v14 = &v9[tdelaynew];
  if ( v14 > v12 )
    v15 = v14[v10 / 0xFFFFFFFC - 1];
  else
    v15 = *v14;
  v16 = ((xf * (v15 - v13)) >> 12) + v13;
  *v9 = in + ((fbgain * v16) >> 12);
  if ( --*ppsamp < psamps )
    *ppsamp = (int *)((char *)*ppsamp + v10 + 4);
  return (outgain * (v16 + (-(fbgain * (in + ((fbgain * v16) >> 12))) >> 12))) >> 12;
}

//------------------------------------------------------------------------------
// Address: 0x1001EAB0
// Name: void FLT_Free(struct flt_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl FLT_Free(flt_t *pf)
{
  flt_t *pf1; // eax
  flt_t *pf2; // eax
  flt_t *pf3; // eax

  if ( pf != nullptr )
  {
    pf1 = pf->pf1;
    if ( pf1 != nullptr )
      _V_memset(dest: pf1, fill: 0, count: 184);
    pf2 = pf->pf2;
    if ( pf2 != nullptr )
      _V_memset(dest: pf2, fill: 0, count: 184);
    pf3 = pf->pf3;
    if ( pf3 != nullptr )
      _V_memset(dest: pf3, fill: 0, count: 184);
    _V_memset(dest: pf, fill: 0, count: 184);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001EB20
// Name: void FLT_FreeAll(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl FLT_FreeAll()
{
  flt_t **p_pf2; // esi
  void *v1; // eax
  flt_t *v2; // eax

  p_pf2 = &flts[0].pf2;
  do
  {
    if ( p_pf2 != (flt_t **)176 )
    {
      v1 = *(p_pf2 - 1);
      if ( v1 != nullptr )
        _V_memset(dest: v1, fill: 0, count: 184);
      if ( *p_pf2 != nullptr )
        _V_memset(dest: *p_pf2, fill: 0, count: 184);
      v2 = p_pf2[1];
      if ( v2 != nullptr )
        _V_memset(dest: v2, fill: 0, count: 184);
      _V_memset(dest: p_pf2 - 44, fill: 0, count: 184);
    }
    p_pf2 += 46;
  }
  while ( (int)p_pf2 < (int)&snd_dsp_spew_changes.m_fnChangeCallbacks.m_Memory.m_nAllocationCount );
}

//------------------------------------------------------------------------------
// Address: 0x1001EBA0
// Name: struct flt_t __near * FLT_Alloc(int,int,int,int __near *,int __near *,float)
// Source: json
//------------------------------------------------------------------------------
flt_t *__cdecl FLT_Alloc(int N, int M, int L, int *a, int *b, float gain)
{
  flt_t *result; // eax
  int v7; // ecx
  flt_t *v8; // edx
  int v9; // edx
  int *v10; // esi
  int v11; // edx
  int *v12; // ecx

  result = nullptr;
  v7 = 0;
  v8 = flts;
  while ( v8->fused )
  {
    ++v8;
    ++v7;
    if ( (int)v8 >= (int)nuls )
      return result;
  }
  result = &flts[v7];
  result->N = N;
  v9 = 0;
  result->M = M;
  result->L = L;
  if ( M >= 0 )
  {
    v10 = result->a;
    do
      *v10++ = a[v9++];
    while ( v9 <= M );
  }
  v11 = 0;
  if ( L >= 0 )
  {
    v12 = result->b;
    do
      *v12++ = (int)(float)((float)b[v11++] * gain);
    while ( v11 <= L );
  }
  result->pf1 = nullptr;
  result->pf2 = nullptr;
  result->pf3 = nullptr;
  result->fused = true;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1001EC60
// Name: void FLT_Print(struct flt_t const __near &,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl FLT_Print(const flt_t *filter, int nIndentation)
{
  char *IndentationText; // edi
  flt_t *pf1; // eax
  flt_t *pf2; // eax
  int j; // [esp+Ch] [ebp-8h]
  int k; // [esp+Ch] [ebp-8h]
  int m; // [esp+Ch] [ebp-8h]
  int i; // [esp+10h] [ebp-4h]
  int *filtera; // [esp+1Ch] [ebp+8h]
  int *filterb; // [esp+1Ch] [ebp+8h]
  int *filterc; // [esp+1Ch] [ebp+8h]

  for ( i = nIndentation + 1; ; ++i )
  {
    IndentationText = GetIndentationText(nIndentation: i - 1);
    DevMsg(a1: "%sFilter: %08X [Addr]\n", IndentationText, filter);
    DevMsg(a1: "%sb[] = ", IndentationText);
    filtera = filter->b;
    for ( j = 13; j != 0; --j )
      DevMsg(a1: "%d ", *filtera++);
    DevMsg(a1: "\n");
    DevMsg(a1: "%sa[] = ", IndentationText);
    filterb = filter->a;
    for ( k = 13; k != 0; --k )
      DevMsg(a1: "%d ", *filterb++);
    DevMsg(a1: "\n");
    DevMsg(a1: "%sw[] = ", IndentationText);
    filterc = filter->w;
    for ( m = 13; m != 0; --m )
      DevMsg(a1: "%d ", *filterc++);
    DevMsg(a1: "\n");
    DevMsg(a1: "%sL: %d\n", IndentationText, filter->L);
    DevMsg(a1: "%sM: %d\n", IndentationText, filter->M);
    DevMsg(a1: "%sN: %d\n", IndentationText, filter->N);
    DevMsg(a1: "%spf1:", IndentationText);
    pf1 = filter->pf1;
    if ( pf1 != nullptr )
      FLT_Print(filter: pf1, nIndentation: i);
    else
      DevMsg(a1: "NULL\n");
    DevMsg(a1: "%spf2:", IndentationText);
    pf2 = filter->pf2;
    if ( pf2 != nullptr )
      FLT_Print(filter: pf2, nIndentation: i);
    else
      DevMsg(a1: "NULL\n");
    DevMsg(a1: "%spf3:", IndentationText);
    filter = filter->pf3;
    if ( filter == nullptr )
      break;
  }
  DevMsg(a1: "NULL\n");
}

//------------------------------------------------------------------------------
// Address: 0x1001EE00
// Name: void FLT_Design_3db_IIR(float,float,int __near *,int __near *,int __near *,int __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl FLT_Design_3db_IIR(float cutoff, float ftype, int *pM, int *pL, int *a, int *b)
{
  long double v6; // st6
  long double v7; // st6
  long double v8; // st7
  long double v9; // st7

  v6 = tan(cutoff * 6.283185307179586 * 0.00002267573696145125 * 0.5);
  v7 = (1.0 - v6) / (v6 + 1.0);
  if ( ftype == 1.0 )
    v8 = 0.5 * (v7 + 1.0);
  else
    v8 = (1.0 - v7) * 0.5;
  *a = 0;
  v9 = v8 * 4096.0;
  a[1] = (int)(v7 * -4096.0);
  *b = (int)v9;
  b[1] = (int)v9;
  if ( ftype == 1.0 )
    b[1] = -(int)v9;
  *pL = 1;
  *pM = 1;
}

//------------------------------------------------------------------------------
// Address: 0x1001EEC0
// Name: int FLT_GetNext(struct flt_t __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl FLT_GetNext(flt_t *pf, int x)
{
  flt_t *v3; // esi
  flt_t *v4; // edi
  flt_t *pf3; // ebx
  int v6; // eax
  int v7; // eax
  int v8; // eax
  flt_t *v9; // esi
  flt_t *pf2; // edi
  int v11; // eax
  int v12; // eax
  flt_t *pf1; // esi
  int updated; // eax

  switch ( pf->N )
  {
    case 1:
      pf1 = pf->pf1;
      updated = IIRFilter_Update_Order1(denom: pf->a, cnumer: pf->L, numer: pf->b, psamp: pf->w, in: x);
      return IIRFilter_Update_Order1(denom: pf1->a, cnumer: pf1->L, numer: pf1->b, psamp: pf1->w, in: updated);
    case 2:
      v9 = pf->pf1;
      pf2 = pf->pf2;
      v11 = IIRFilter_Update_Order1(denom: pf->a, cnumer: pf->L, numer: pf->b, psamp: pf->w, in: x);
      v12 = IIRFilter_Update_Order1(denom: v9->a, cnumer: v9->L, numer: v9->b, psamp: v9->w, in: v11);
      return IIRFilter_Update_Order1(denom: pf2->a, cnumer: pf2->L, numer: pf2->b, psamp: pf2->w, in: v12);
    case 3:
      v3 = pf->pf1;
      v4 = pf->pf2;
      pf3 = pf->pf3;
      v6 = IIRFilter_Update_Order1(denom: pf->a, cnumer: pf->L, numer: pf->b, psamp: pf->w, in: x);
      v7 = IIRFilter_Update_Order1(denom: v3->a, cnumer: v3->L, numer: v3->b, psamp: v3->w, in: v6);
      v8 = IIRFilter_Update_Order1(denom: v4->a, cnumer: v4->L, numer: v4->b, psamp: v4->w, in: v7);
      return IIRFilter_Update_Order1(denom: pf3->a, cnumer: pf3->L, numer: pf3->b, psamp: pf3->w, in: v8);
    default:
      return IIRFilter_Update_Order1(denom: pf->a, cnumer: pf->L, numer: pf->b, psamp: pf->w, in: x);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001F020
// Name: void FLT_GetNextN(struct flt_t __near *,struct portable_samplepair_t __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl FLT_GetNextN(flt_t *pflt, portable_samplepair_t *pbuffer, portable_samplepair_t *SampleCount, int op)
{
  int v5; // edi
  portable_samplepair_t *v6; // ebx
  int left; // ecx
  int v8; // esi
  int v9; // edx
  int v10; // ecx
  flt_t *pf3; // edi
  flt_t *v12; // edx
  flt_t *v13; // esi
  int v14; // ebx
  int v15; // edi
  int v16; // ecx
  int v17; // ebx
  int v18; // edi
  int v19; // ecx
  int v20; // ebx
  int v21; // edx
  int v22; // ecx
  int v23; // esi
  int v24; // edx
  flt_t *v25; // edx
  flt_t *pf2; // edi
  int v27; // ebx
  int v28; // esi
  int v29; // ecx
  int v30; // ebx
  int v31; // esi
  int v32; // ecx
  int v33; // esi
  int v34; // edx
  flt_t *pf1; // edx
  int v36; // edi
  int v37; // esi
  int v38; // edi
  int v39; // esi
  int Next; // eax
  int *p_right; // esi
  int count; // [esp+Ch] [ebp-4h]
  int counta; // [esp+Ch] [ebp-4h]
  portable_samplepair_t *pbuffera; // [esp+1Ch] [ebp+Ch]
  portable_samplepair_t *pb; // [esp+20h] [ebp+10h]

  v5 = (int)SampleCount;
  count = (int)SampleCount;
  v6 = pbuffer;
  pb = pbuffer;
  if ( op == 1 )
  {
    if ( SampleCount != nullptr )
    {
      p_right = &pbuffer->right;
      do
      {
        --count;
        *p_right = FLT_GetNext(pf: pflt, x: *p_right);
        p_right += 2;
      }
      while ( count != 0 );
    }
  }
  else if ( op == 2 )
  {
    if ( SampleCount != nullptr )
    {
      do
      {
        Next = FLT_GetNext(pf: pflt, x: v6->left);
        v6->right = Next;
        v6->left = Next;
        ++v6;
        --v5;
      }
      while ( v5 != 0 );
    }
  }
  else if ( SampleCount != nullptr )
  {
    do
    {
      left = v6->left;
      counta = v5 - 1;
      switch ( pflt->N )
      {
        case 1:
          pf1 = pflt->pf1;
          if ( pflt->w[0] != 0 || pflt->w[1] != 0 || left != 0 )
          {
            v36 = pflt->w[1];
            v37 = left - ((v36 * pflt->a[1]) >> 12);
            pflt->w[0] = v37;
            left = (v37 * pflt->b[0] + v36 * pflt->b[1]) >> 12;
            pflt->w[1] = v37;
          }
          if ( pf1->w[0] == 0 && pf1->w[1] == 0 && left == 0 )
            goto LABEL_48;
          v38 = pf1->w[1];
          v39 = left - ((v38 * pf1->a[1]) >> 12);
          pf1->w[0] = v39;
          v10 = v39 * pf1->b[0] + v38 * pf1->b[1];
          pf1->w[1] = v39;
          break;
        case 2:
          v25 = pflt->pf1;
          pf2 = pflt->pf2;
          if ( pflt->w[0] != 0 || pflt->w[1] != 0 || left != 0 )
          {
            v27 = pflt->w[1];
            v28 = left - ((v27 * pflt->a[1]) >> 12);
            pflt->w[0] = v28;
            v29 = v28 * pflt->b[0] + v27 * pflt->b[1];
            v6 = pb;
            left = v29 >> 12;
            pflt->w[1] = v28;
          }
          if ( v25->w[0] != 0 || v25->w[1] != 0 || left != 0 )
          {
            v30 = v25->w[1];
            v31 = left - ((v30 * v25->a[1]) >> 12);
            v25->w[0] = v31;
            v32 = v31 * v25->b[0] + v30 * v25->b[1];
            v6 = pb;
            left = v32 >> 12;
            v25->w[1] = v31;
          }
          if ( pf2->w[0] == 0 && pf2->w[1] == 0 && left == 0 )
            goto LABEL_48;
          v33 = pf2->w[1];
          v34 = left - ((v33 * pf2->a[1]) >> 12);
          pf2->w[0] = v34;
          v10 = v34 * pf2->b[0] + v33 * pf2->b[1];
          pf2->w[1] = v34;
          break;
        case 3:
          pf3 = pflt->pf3;
          v12 = pflt->pf1;
          v13 = pflt->pf2;
          pbuffera = (portable_samplepair_t *)pf3;
          if ( pflt->w[0] != 0 || pflt->w[1] != 0 || left != 0 )
          {
            v14 = pflt->w[1];
            v15 = left - ((v14 * pflt->a[1]) >> 12);
            pflt->w[0] = v15;
            v16 = v15 * pflt->b[0] + v14 * pflt->b[1];
            v6 = pb;
            pflt->w[1] = v15;
            pf3 = (flt_t *)pbuffera;
            left = v16 >> 12;
          }
          if ( v12->w[0] != 0 || v12->w[1] != 0 || left != 0 )
          {
            v17 = v12->w[1];
            v18 = left - ((v17 * v12->a[1]) >> 12);
            v12->w[0] = v18;
            v19 = v18 * v12->b[0] + v17 * v12->b[1];
            v6 = pb;
            v12->w[1] = v18;
            pf3 = (flt_t *)pbuffera;
            left = v19 >> 12;
          }
          if ( v13->w[0] != 0 || v13->w[1] != 0 || left != 0 )
          {
            v20 = v13->w[1];
            v21 = left - ((v20 * v13->a[1]) >> 12);
            v13->w[0] = v21;
            v22 = v21 * v13->b[0] + v20 * v13->b[1];
            v6 = pb;
            left = v22 >> 12;
            v13->w[1] = v21;
          }
          if ( pf3->w[0] == 0 && pf3->w[1] == 0 && left == 0 )
            goto LABEL_48;
          v23 = pf3->w[1];
          v24 = left - ((v23 * pf3->a[1]) >> 12);
          pf3->w[0] = v24;
          v10 = v24 * pf3->b[0] + v23 * pf3->b[1];
          pf3->w[1] = v24;
          break;
        default:
          if ( pflt->w[0] == 0 && pflt->w[1] == 0 && left == 0 )
            goto LABEL_48;
          v8 = pflt->w[1];
          v9 = left - ((v8 * pflt->a[1]) >> 12);
          pflt->w[0] = v9;
          v10 = v9 * pflt->b[0] + v8 * pflt->b[1];
          pflt->w[1] = v9;
          break;
      }
      left = v10 >> 12;
LABEL_48:
      v5 = counta;
      v6->left = left;
      pb = ++v6;
    }
    while ( counta != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001F380
// Name: void POS_ONE_Print(struct pos_one_t const __near &,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl POS_ONE_Print(const pos_one_t *posOne, const char *nIndentation)
{
  char *IndentationText; // ebx
  char *pIndent; // [esp+18h] [ebp+Ch]

  pIndent = GetIndentationText((int)nIndentation);
  DevMsg(a1: "%sPosOne: %08X [Addr]\n", pIndent, posOne);
  IndentationText = GetIndentationText(nIndentation: (int)(nIndentation + 1));
  DevMsg(a1: "%sPos: %08X [Addr]\n", IndentationText, posOne);
  DevMsg(a1: "%sstep: %d\n", IndentationText, posOne->p.step);
  DevMsg(a1: "%scstep: %d\n", IndentationText, posOne->p.cstep);
  DevMsg(a1: "%spos: %d\n", IndentationText, posOne->p.pos);
  DevMsg(a1: "%sD: %d\n", IndentationText, posOne->p.D);
  DevMsg(a1: "%sfhitend: %d\n", pIndent, posOne->fhitend);
}

//------------------------------------------------------------------------------
// Address: 0x1001F400
// Name: void DLY_Free(struct dly_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DLY_Free(dly_t *pdly)
{
  if ( pdly != nullptr )
  {
    FLT_Free(pf: pdly->pflt);
    if ( pdly->w != nullptr )
      free(pMem: pdly->w);
    _V_memset(dest: pdly, fill: 0, count: 72);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001F440
// Name: void DLY_FreeAll(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DLY_FreeAll()
{
  int **p_w; // edi
  int *v1; // esi
  void *v2; // eax
  void *v3; // eax
  void *v4; // eax

  p_w = &dlys[0].w;
  do
  {
    if ( p_w != (int **)56 )
    {
      v1 = p_w[3];
      if ( v1 != nullptr )
      {
        v2 = (void *)v1[43];
        if ( v2 != nullptr )
          _V_memset(dest: v2, fill: 0, count: 184);
        v3 = (void *)v1[44];
        if ( v3 != nullptr )
          _V_memset(dest: v3, fill: 0, count: 184);
        v4 = (void *)v1[45];
        if ( v4 != nullptr )
          _V_memset(dest: v4, fill: 0, count: 184);
        _V_memset(dest: v1, fill: 0, count: 184);
      }
      if ( *p_w != nullptr )
        free(pMem: *p_w);
      _V_memset(dest: p_w - 14, fill: 0, count: 72);
    }
    p_w += 18;
  }
  while ( (int)p_w < (int)flts[0].a );
}

//------------------------------------------------------------------------------
// Address: 0x1001F500
// Name: void DLY_Print(struct dly_t const __near &,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DLY_Print(const dly_t *delay, int nIndentation)
{
  char *IndentationText; // ebx
  int *w; // eax
  int v5; // ecx
  _DWORD *v6; // eax
  flt_t *pflt; // esi
  int nFirstValue; // [esp+Ch] [ebp-8h]
  int nValues; // [esp+10h] [ebp-4h]
  int nValuesa; // [esp+10h] [ebp-4h]
  int i; // [esp+1Ch] [ebp+8h]
  char i_3; // [esp+1Fh] [ebp+Bh]

  IndentationText = GetIndentationText(nIndentation);
  DevMsg(a1: "%sDelay: %08X [Addr]\n", IndentationText, delay);
  DevMsg(a1: "%sfused: %d\n", IndentationText, delay->fused);
  DevMsg(a1: "%stype: %d\n", IndentationText, delay->type);
  DevMsg(a1: "%sD: %d\n", IndentationText, delay->D);
  DevMsg(a1: "%st: %d\n", IndentationText, delay->t);
  DevMsg(a1: "%stnew: %d\n", IndentationText, delay->tnew);
  DevMsg(a1: "%sxf: %d\n", IndentationText, delay->xf);
  DevMsg(a1: "%st1: %d - t2: %d - t3: %d\n", IndentationText, delay->t1, delay->t2, delay->t3);
  DevMsg(a1: "%sa1: %d - a2: %d - a3: %d\n", IndentationText, delay->a1, delay->a2, delay->a3);
  DevMsg(a1: "%sD0: %d\n", IndentationText, delay->D0);
  DevMsg(a1: "%sw: %d\n", IndentationText, delay->p - delay->w);
  w = delay->w;
  nFirstValue = *w;
  i_3 = 1;
  v5 = delay->D + 1;
  if ( v5 <= 1 )
    goto LABEL_7;
  v6 = w + 1;
  nValues = delay->D;
  do
  {
    if ( *v6 != nFirstValue )
      i_3 = 0;
    ++v6;
    --nValues;
  }
  while ( nValues != 0 );
  if ( i_3 != 0 )
  {
LABEL_7:
    DevMsg(a1: "%sAll %d values are equal to %d.\n", IndentationText, v5, nFirstValue);
  }
  else
  {
    nValuesa = delay->D + 1;
    if ( v5 > 256 )
    {
      nValuesa = 256;
      DevMsg(a1: "%sDisplay only the first %d samples.\n", IndentationText, 256);
    }
    i = 0;
    do
    {
      if ( (i & 0x3F) == 0 )
        DevMsg(a1: "\n%s    ", IndentationText);
      DevMsg(a1: "%d ", delay->w[i++]);
    }
    while ( i < nValuesa );
    DevMsg(a1: "\n");
  }
  DevMsg(a1: "%sa: %d\n", IndentationText, delay->a);
  DevMsg(a1: "%sb: %d\n", IndentationText, delay->b);
  DevMsg(a1: "%spflt: ", IndentationText);
  pflt = delay->pflt;
  if ( pflt != nullptr )
    FLT_Print(filter: pflt, nIndentation: nIndentation + 1);
  else
    DevMsg(a1: "NULL\n");
}

//------------------------------------------------------------------------------
// Address: 0x1001F6D0
// Name: int DLY_GetNext(struct dly_t __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl DLY_GetNext(dly_t *pdly, int x)
{
  int result; // eax
  int *p; // esi
  int t; // eax
  int v6; // edi
  int *w; // edx
  int v8; // edi
  int *v9; // eax
  int v10; // eax
  int v11; // eax
  int *v12; // esi
  int pdlya; // [esp+Ch] [ebp+8h]

  switch ( pdly->type )
  {
    case 1:
      result = DelayAllpass(
                 delaysize: pdly->D,
                 tdelay: pdly->t,
                 psamps: pdly->w,
                 ppsamp: &pdly->p,
                 fbgain: pdly->a,
                 outgain: pdly->b,
                 in: x);
      break;
    case 2:
      result = DelayLowPass(
                 delaysize: pdly->D,
                 tdelay: pdly->t,
                 psamps: pdly->w,
                 ppsamp: &pdly->p,
                 fbgain: pdly->a,
                 outgain: pdly->b,
                 denom: pdly->pflt->a,
                 Ll: pdly->pflt->L,
                 numer: pdly->pflt->b,
                 pfsamps: pdly->pflt->w,
                 in: x);
      break;
    case 3:
      result = DelayLinear(delaysize: pdly->D, tdelay: pdly->t, psamps: pdly->w, ppsamp: &pdly->p, in: x);
      break;
    case 4:
      result = DelayLinearLowPass(
                 delaysize: pdly->D,
                 tdelay: pdly->t,
                 psamps: pdly->w,
                 ppsamp: &pdly->p,
                 fbgain: pdly->a,
                 outgain: pdly->b,
                 denom: pdly->pflt->a,
                 cnumer: pdly->pflt->L,
                 numer: pdly->pflt->b,
                 pfsamps: pdly->pflt->w,
                 in: x);
      break;
    case 5:
      result = DelayLowpass_multitap(
                 delaysize: pdly->D,
                 tdelay0: pdly->t,
                 tdelay1: pdly->t1,
                 tdelay2: pdly->t2,
                 tdelay3: pdly->t3,
                 psamps: pdly->w,
                 ppsamp: &pdly->p,
                 fbgain: pdly->a,
                 outgain: pdly->b,
                 denom: pdly->pflt->a,
                 Ll: pdly->pflt->L,
                 numer: pdly->pflt->b,
                 pfsamps: pdly->pflt->w,
                 in: x);
      break;
    case 6:
      result = ReverbSimple_multitap(
                 delaysize: pdly->D,
                 tdelay0: pdly->t,
                 tdelay1: pdly->t1,
                 tdelay2: pdly->t2,
                 tdelay3: pdly->t3,
                 psamps: pdly->w,
                 ppsamp: &pdly->p,
                 fbgain: pdly->a,
                 outgain: pdly->b,
                 in: x);
      break;
    default:
      p = pdly->p;
      t = pdly->t;
      v6 = 2 * pdly->D;
      pdlya = pdly->b;
      w = pdly->w;
      v8 = 2 * v6;
      v9 = &p[t];
      if ( v9 > (int *)((char *)w + v8) )
        v10 = *(int *)((char *)v9 - v8 - 4);
      else
        v10 = *v9;
      v11 = x + ((pdly->a * v10) >> 12);
      *p = v11;
      v12 = --pdly->p;
      if ( v12 < w )
        pdly->p = (int *)((char *)v12 + v8 + 4);
      result = (pdlya * v11) >> 12;
      break;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1001F8A0
// Name: int DLY_GetNextXfade(struct dly_t __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl DLY_GetNextXfade(dly_t *pdly, int x)
{
  int result; // eax
  flt_t *pflt; // eax
  int *w; // esi
  int *p; // edx
  int v7; // ebx
  int *v8; // eax
  dly_t *v9; // eax
  int *v10; // eax
  int v11; // eax
  int v12; // eax
  int *v13; // edx
  int b; // [esp+4h] [ebp-4h]
  dly_t *pdlya; // [esp+10h] [ebp+8h]

  switch ( pdly->type )
  {
    case 1:
      result = DelayAllpass_xfade(
                 delaysize: pdly->D,
                 tdelay: pdly->t,
                 tdelaynew: pdly->tnew,
                 xf: pdly->xf,
                 psamps: pdly->w,
                 ppsamp: &pdly->p,
                 fbgain: pdly->a,
                 outgain: pdly->b,
                 in: x);
      break;
    case 2:
      result = DelayLowpass_xfade(
                 delaysize: pdly->D,
                 tdelay: pdly->t,
                 tdelaynew: pdly->tnew,
                 xf: pdly->xf,
                 psamps: pdly->w,
                 ppsamp: &pdly->p,
                 fbgain: pdly->a,
                 outgain: pdly->b,
                 denom: pdly->pflt->a,
                 Ll: pdly->pflt->L,
                 numer: pdly->pflt->b,
                 pfsamps: pdly->pflt->w,
                 in: x);
      break;
    case 3:
      result = DelayLinear_xfade(
                 delaysize: pdly->D,
                 tdelay: pdly->t,
                 tdelaynew: pdly->tnew,
                 xf: pdly->xf,
                 psamps: pdly->w,
                 ppsamp: &pdly->p,
                 in: x);
      break;
    case 4:
      result = DelayLinear_lowpass_xfade(
                 delaysize: pdly->D,
                 tdelay: pdly->t,
                 tdelaynew: pdly->tnew,
                 xf: pdly->xf,
                 psamps: pdly->w,
                 ppsamp: &pdly->p,
                 fbgain: pdly->a,
                 outgain: pdly->b,
                 denom: pdly->pflt->a,
                 cnumer: pdly->pflt->L,
                 numer: pdly->pflt->b,
                 pfsamps: pdly->pflt->w,
                 in: x);
      break;
    case 5:
      pflt = pdly->pflt;
      result = DelayLowpass_multitap_xfade(
                 delaysize: pdly->D,
                 tdelay0: pdly->t,
                 tdelaynew: pdly->tnew,
                 xf: pdly->xf,
                 tdelay1: pdly->t1,
                 tdelay2: pdly->t2,
                 tdelay3: pdly->t3,
                 psamps: pdly->w,
                 ppsamp: &pdly->p,
                 fbgain: pdly->a,
                 outgain: pdly->b,
                 denom: pflt->a,
                 Ll: pflt->L,
                 numer: pflt->b,
                 pfsamps: pflt->w,
                 in: x);
      break;
    case 6:
      result = ReverbSimple_multitap_xfade(
                 delaysize: pdly->D,
                 tdelay0: pdly->t,
                 tdelaynew: pdly->tnew,
                 xf: pdly->xf,
                 tdelay1: pdly->t1,
                 tdelay2: pdly->t2,
                 tdelay3: pdly->t3,
                 psamps: pdly->w,
                 ppsamp: &pdly->p,
                 fbgain: pdly->a,
                 outgain: pdly->b,
                 in: x);
      break;
    default:
      w = pdly->w;
      b = pdly->b;
      p = pdly->p;
      v7 = 4 * pdly->D;
      v8 = &p[pdly->t];
      if ( v8 > &w[v7 / 4u] )
        v9 = (dly_t *)v8[v7 / 0xFFFFFFFC - 1];
      else
        v9 = (dly_t *)*v8;
      pdlya = v9;
      v10 = &p[pdly->tnew];
      if ( v10 > &w[v7 / 4u] )
        v11 = v10[v7 / 0xFFFFFFFC - 1];
      else
        v11 = *v10;
      v12 = x + ((pdly->a * ((int)pdlya + ((pdly->xf * (v11 - (int)pdlya)) >> 12))) >> 12);
      *p = v12;
      v13 = --pdly->p;
      if ( v13 < w )
        pdly->p = &v13[v7 / 4u + 1];
      result = (b * v12) >> 12;
      break;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1001FAD0
// Name: void DLY_GetNextN(struct dly_t __near *,struct portable_samplepair_t __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DLY_GetNextN(dly_t *pdly, portable_samplepair_t *pbuffer, int SampleCount, int op)
{
  portable_samplepair_t *v4; // ebx
  int **p_p; // edi
  int left; // ecx
  int v7; // eax
  int *w; // edx
  int *v9; // eax
  int *v10; // eax
  int *v11; // edx
  int v12; // eax
  int v13; // eax
  int Next; // eax
  int *p_right; // esi
  int b; // [esp+Ch] [ebp-4h]
  int opa; // [esp+24h] [ebp+14h]
  int opb; // [esp+24h] [ebp+14h]

  v4 = pbuffer;
  if ( op == 1 )
  {
    if ( SampleCount != 0 )
    {
      p_right = &pbuffer->right;
      do
      {
        --SampleCount;
        *p_right = DLY_GetNext(pdly, x: *p_right);
        p_right += 2;
      }
      while ( SampleCount != 0 );
    }
  }
  else if ( op == 2 )
  {
    for ( ; SampleCount != 0; ++v4 )
    {
      --SampleCount;
      Next = DLY_GetNext(pdly, x: v4->left);
      v4->right = Next;
      v4->left = Next;
    }
  }
  else if ( SampleCount != 0 )
  {
    p_p = &pdly->p;
    do
    {
      --SampleCount;
      left = v4->left;
      switch ( pdly->type )
      {
        case 1:
          v7 = DelayAllpass(
                 delaysize: pdly->D,
                 tdelay: pdly->t,
                 psamps: pdly->w,
                 ppsamp: p_p,
                 fbgain: pdly->a,
                 outgain: pdly->b,
                 in: v4->left);
          break;
        case 2:
          v7 = DelayLowPass(
                 delaysize: pdly->D,
                 tdelay: pdly->t,
                 psamps: pdly->w,
                 ppsamp: p_p,
                 fbgain: pdly->a,
                 outgain: pdly->b,
                 denom: pdly->pflt->a,
                 Ll: pdly->pflt->L,
                 numer: pdly->pflt->b,
                 pfsamps: pdly->pflt->w,
                 in: v4->left);
          break;
        case 3:
          w = pdly->w;
          v9 = &(*p_p)[pdly->t];
          opa = 4 * pdly->D;
          if ( v9 > &w[opa / 4u] )
            v7 = v9[opa / 0xFFFFFFFC - 1];
          else
            v7 = *v9;
          *(*p_p)-- = left;
          if ( *p_p < w )
            *p_p = (int *)((char *)*p_p + opa + 4);
          goto LABEL_22;
        case 4:
          v7 = DelayLinearLowPass(
                 delaysize: pdly->D,
                 tdelay: pdly->t,
                 psamps: pdly->w,
                 ppsamp: p_p,
                 fbgain: pdly->a,
                 outgain: pdly->b,
                 denom: pdly->pflt->a,
                 cnumer: pdly->pflt->L,
                 numer: pdly->pflt->b,
                 pfsamps: pdly->pflt->w,
                 in: v4->left);
          break;
        case 5:
          v7 = DelayLowpass_multitap(
                 delaysize: pdly->D,
                 tdelay0: pdly->t,
                 tdelay1: pdly->t1,
                 tdelay2: pdly->t2,
                 tdelay3: pdly->t3,
                 psamps: pdly->w,
                 ppsamp: p_p,
                 fbgain: pdly->a,
                 outgain: pdly->b,
                 denom: pdly->pflt->a,
                 Ll: pdly->pflt->L,
                 numer: pdly->pflt->b,
                 pfsamps: pdly->pflt->w,
                 in: v4->left);
          break;
        case 6:
          v7 = ReverbSimple_multitap(
                 delaysize: pdly->D,
                 tdelay0: pdly->t,
                 tdelay1: pdly->t1,
                 tdelay2: pdly->t2,
                 tdelay3: pdly->t3,
                 psamps: pdly->w,
                 ppsamp: p_p,
                 fbgain: pdly->a,
                 outgain: pdly->b,
                 in: v4->left);
          break;
        default:
          v10 = &(*p_p)[pdly->t];
          b = pdly->b;
          v11 = pdly->w;
          opb = 4 * pdly->D;
          if ( v10 > &v11[opb / 4u] )
            v12 = v10[opb / 0xFFFFFFFC - 1];
          else
            v12 = *v10;
          v13 = left + ((pdly->a * v12) >> 12);
          *(*p_p)-- = v13;
          if ( *p_p < v11 )
            *p_p = (int *)((char *)*p_p + opb + 4);
          v7 = (b * v13) >> 12;
LABEL_22:
          v4 = pbuffer;
          break;
      }
      v4->left = v7;
      pbuffer = ++v4;
    }
    while ( SampleCount != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001FD50
// Name: void DLY_ChangeTaps(struct dly_t __near *,int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DLY_ChangeTaps(dly_t *pdly, int t0, int t1, int t2, int t3)
{
  int v10; // edx
  int v11; // edx
  int v12; // edx
  int D0; // edx
  int pdlya; // [esp+Ch] [ebp+8h]

  if ( pdly != nullptr )
  {
    for ( pdlya = 4; pdlya != 0; --pdlya )
    {
      if ( t0 > t1 )
      {
        v10 = t0;
        t0 = t1;
        t1 = v10;
      }
      if ( t1 > t2 )
      {
        v11 = t1;
        t1 = t2;
        t2 = v11;
      }
      if ( t2 > t3 )
      {
        v12 = t2;
        t2 = t3;
        t3 = v12;
      }
    }
    D0 = pdly->D0;
    if ( t0 >= D0 )
      t0 = pdly->D0;
    pdly->t = t0;
    if ( t1 >= D0 )
      t1 = D0;
    pdly->t1 = t1;
    if ( t2 >= D0 )
      t2 = D0;
    pdly->t2 = t2;
    if ( t3 < D0 )
      D0 = t3;
    pdly->t3 = D0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001FDC0
// Name: void RMP_Init(struct rmp_t __near *,float,int,int,bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl RMP_Init(rmp_t *prmp, float ramptime, int initval, int targetval, bool bEndAtTime)
{
  int v6; // eax
  float v7; // xmm0_4
  int v8; // ecx
  int v9; // [esp+0h] [ebp-Ch]
  int rise; // [esp+14h] [ebp+8h]
  float risea; // [esp+14h] [ebp+8h]

  if ( prmp != nullptr )
  {
    _V_memset(dest: prmp, fill: 0, count: 44);
    v6 = abs32(targetval - initval);
    *(float *)&rise = fabs((double)(targetval - initval)) / (double)(int)(float)(ramptime * 44100.0);
    v7 = *(float *)&rise;
    if ( (int)*(float *)&rise > 4095 )
      v7 = (float)(*(float *)&rise - (float)(int)*(float *)&rise) + 4095.0;
    prmp->ps.p.D = v6;
    prmp->ps.p.step = (int)(float)(v7 * 1048576.0);
    prmp->ps.p.cstep = 0;
    prmp->ps.p.pos = 0;
    prmp->ps.fhitend = false;
    prmp->yprev = initval;
    prmp->initval = initval;
    prmp->target = targetval;
    prmp->sign = 2 * (targetval - initval >= 0) - 1;
    if ( ramptime <= 0.016000001 )
      risea = 0.016000001;
    else
      risea = ramptime;
    v8 = _Plat_MSTime(a1: v9);
    prmp->bEndAtTime = bEndAtTime;
    prmp->nEndRampTimeInMs = (__int64)(risea * 1000.0) + v8;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001FED0
// Name: int RMP_GetNext(struct rmp_t __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl RMP_GetNext(rmp_t *prmp)
{
  int pos; // esi
  int step; // edx
  int v3; // eax
  int v4; // eax
  int sign; // edi
  int initval; // eax
  int v7; // eax
  int yprev; // esi

  if ( !prmp->fhitend )
  {
    pos = prmp->ps.p.pos;
    if ( prmp->ps.fhitend
      || ((step = prmp->ps.p.step,
           v3 = step + prmp->ps.p.cstep,
           prmp->ps.p.pos = pos + (v3 >> 20),
           prmp->ps.p.cstep = v3 - (v3 & 0xFFF00000),
           step == 0)
       || (v4 = prmp->ps.p.pos) < 0
       || v4 >= prmp->ps.p.D
        ? (prmp->ps.fhitend = true)
        : (pos = prmp->ps.p.pos),
          prmp->ps.fhitend) )
    {
      prmp->fhitend = true;
    }
    sign = prmp->sign;
    initval = prmp->initval;
    if ( sign <= 0 )
      v7 = initval - pos;
    else
      v7 = pos + initval;
    if ( prmp->bEndAtTime )
    {
      yprev = prmp->yprev;
      if ( (int)abs32(v7 - yprev) >= 1 )
      {
        prmp->yprev = yprev + sign;
        return prmp->yprev;
      }
    }
    else
    {
      prmp->yprev = v7;
    }
  }
  return prmp->yprev;
}

//------------------------------------------------------------------------------
// Address: 0x1001FF70
// Name: void RMP_Print(struct rmp_t const __near &,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl RMP_Print(const rmp_t *rmp, int nIndentation)
{
  char *IndentationText; // esi

  IndentationText = GetIndentationText(nIndentation);
  DevMsg(a1: "%sRmp: %08X [Addr]\n", IndentationText, rmp);
  DevMsg(a1: "%sinitval: %d\n", IndentationText, rmp->initval);
  DevMsg(a1: "%starget: %d\n", IndentationText, rmp->target);
  DevMsg(a1: "%ssign: %d\n", IndentationText, rmp->sign);
  DevMsg(a1: "%sfhitend: %d\n", IndentationText, rmp->fhitend);
  DevMsg(a1: "%sbEndAtTime: %d\n", IndentationText, rmp->bEndAtTime);
  POS_ONE_Print(posOne: &rmp->ps, nIndentation: (const char *)(nIndentation + 1));
}

//------------------------------------------------------------------------------
// Address: 0x1001FFF0
// Name: void MDY_Free(struct mdy_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MDY_Free(mdy_t *pmdy)
{
  dly_t *pdly; // esi

  if ( pmdy != nullptr )
  {
    pdly = pmdy->pdly;
    if ( pdly != nullptr )
    {
      FLT_Free(pf: pdly->pflt);
      if ( pdly->w != nullptr )
        free(pMem: pdly->w);
      _V_memset(dest: pdly, fill: 0, count: 72);
    }
    _V_memset(dest: pmdy, fill: 0, count: 76);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10020040
// Name: void MDY_FreeAll(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MDY_FreeAll()
{
  mdy_t *v0; // edi
  dly_t *pdly; // esi

  v0 = mdys;
  do
  {
    if ( v0 != nullptr )
    {
      pdly = v0->pdly;
      if ( pdly != nullptr )
      {
        FLT_Free(pf: pdly->pflt);
        if ( pdly->w != nullptr )
          free(pMem: pdly->w);
        _V_memset(dest: pdly, fill: 0, count: 72);
      }
      _V_memset(dest: v0, fill: 0, count: 76);
    }
    ++v0;
  }
  while ( (int)v0 < (int)dlys );
}

//------------------------------------------------------------------------------
// Address: 0x100200A0
// Name: struct mdy_t __near * MDY_Alloc(struct dly_t __near *,float,float,float,float)
// Source: json
//------------------------------------------------------------------------------
mdy_t *__cdecl MDY_Alloc(dly_t *pdly, float ramptime, float modtime, float depth, float mix)
{
  int v6; // esi
  mdy_t *v7; // eax
  mdy_t *v8; // esi
  int v9; // eax

  if ( pdly == nullptr )
    return nullptr;
  v6 = 0;
  v7 = mdys;
  while ( v7->fused )
  {
    ++v7;
    ++v6;
    if ( (int)v7 >= (int)dlys )
    {
      DevMsg(a1: "DSP: Warning, failed to allocate mod delay.\n");
      return nullptr;
    }
  }
  v8 = &mdys[v6];
  if ( v8 != nullptr )
    _V_memset(dest: v8, fill: 0, count: 76);
  v8->ramptime = ramptime;
  v9 = (int)(float)(modtime * 44100.0);
  v8->depth = depth;
  v8->mtime = v9;
  v8->mtimecur = v9;
  v8->mix = (int)(float)(mix * 4096.0);
  v8->pdly = pdly;
  v8->fused = true;
  v8->bPhaseInvert = false;
  return v8;
}

//------------------------------------------------------------------------------
// Address: 0x10020150
// Name: void MDY_Print(struct mdy_t const __near &,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MDY_Print(const mdy_t *modDelay, int nIndentation)
{
  char *IndentationText; // esi
  dly_t *pdly; // eax

  IndentationText = GetIndentationText(nIndentation);
  DevMsg(a1: "%sModDelay: %08X [Addr]\n", IndentationText, modDelay);
  DevMsg(a1: "%sfused: %d\n", IndentationText, modDelay->fused);
  DevMsg(a1: "%sfchanging: %d\n", IndentationText, modDelay->fchanging);
  DevMsg(a1: "%spdly: ", IndentationText);
  pdly = modDelay->pdly;
  if ( pdly != nullptr )
    DLY_Print(delay: pdly, nIndentation: nIndentation + 1);
  else
    DevMsg(a1: "NULL\n");
  DevMsg(a1: "%sramptime: %f\n", IndentationText, modDelay->ramptime);
  DevMsg(a1: "%smtime: %d\n", IndentationText, modDelay->mtime);
  DevMsg(a1: "%smtimecur: %d\n", IndentationText, modDelay->mtimecur);
  DevMsg(a1: "%sdepth: %f\n", IndentationText, modDelay->depth);
  DevMsg(a1: "%smix: %d\n", IndentationText, modDelay->mix);
  RMP_Print(rmp: &modDelay->rmp_interp, nIndentation: nIndentation + 1);
  DevMsg(a1: "%sbPhaseInvert: %d\n", IndentationText, modDelay->bPhaseInvert);
}

//------------------------------------------------------------------------------
// Address: 0x10020230
// Name: void MDY_ChangeVal(struct mdy_t __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MDY_ChangeVal(mdy_t *pmdy, int t)
{
  int D0; // edi
  float ramptime; // [esp-10h] [ebp-18h]

  D0 = t;
  ramptime = pmdy->ramptime;
  if ( pmdy->pdly->D0 < t )
    D0 = pmdy->pdly->D0;
  pmdy->fchanging = true;
  RMP_Init(prmp: &pmdy->rmp_interp, ramptime, initval: 0, targetval: 4096, bEndAtTime: false);
  pmdy->pdly->tnew = D0;
  pmdy->pdly->xf = 0;
}

//------------------------------------------------------------------------------
// Address: 0x10020280
// Name: int MDY_GetNext(struct mdy_t __near *,int)
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
int __cdecl MDY_GetNext(mdy_t *pmdy, int x)
{
  int NextXfade; // edi
  dly_t *pdly; // eax
  int tnew; // ecx
  int mtime; // ecx
  int mtimecur; // eax
  dly_t *v7; // eax
  float v8; // xmm0_4
  int v9; // eax
  int mix; // esi

  if ( pmdy->fchanging )
  {
    NextXfade = DLY_GetNextXfade(pdly: pmdy->pdly, x);
    pmdy->pdly->xf = RMP_GetNext(prmp: &pmdy->rmp_interp);
    if ( pmdy->rmp_interp.fhitend )
    {
      pdly = pmdy->pdly;
      tnew = pdly->tnew;
      if ( tnew >= pdly->D0 )
        tnew = pdly->D0;
      pdly->t = tnew;
      pmdy->pdly->t = pmdy->pdly->tnew;
      pmdy->fchanging = false;
    }
  }
  else
  {
    NextXfade = DLY_GetNext(pdly: pmdy->pdly, x);
    if ( pmdy->mtime == 0 )
      goto mdy_return;
  }
  mtime = pmdy->mtime;
  if ( mtime != 0 )
  {
    mtimecur = pmdy->mtimecur;
    pmdy->mtimecur = mtimecur - 1;
    if ( mtimecur == 0 )
    {
      v7 = pmdy->pdly;
      v8 = 1.0 - pmdy->depth;
      pmdy->mtimecur = mtime;
      v9 = _RandomInt(
             this: (IUniformRandomStream *)(int)(float)(v8 * (float)v7->D0),
             a2: (int)(float)(v8 * (float)v7->D0),
             a3: v7->D0);
      MDY_ChangeVal(pmdy, t: v9);
    }
  }
mdy_return:
  if ( pmdy->bPhaseInvert )
    NextXfade = -NextXfade;
  mix = pmdy->mix;
  if ( mix == 4096 )
    return NextXfade;
  if ( mix == 2048 )
    return (NextXfade + x) >> 1;
  return x + ((mix * (NextXfade - x)) >> 12);
}

//------------------------------------------------------------------------------
// Address: 0x10020380
// Name: void MDY_GetNextN(struct mdy_t __near *,struct portable_samplepair_t __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __cdecl MDY_GetNextN(mdy_t *pmdy, portable_samplepair_t *pbuffer, mdy_t *SampleCount, portable_samplepair_t *op)
{
  portable_samplepair_t *v4; // ebx
  int v5; // edi
  int NextXfade; // edi
  dly_t *pdly; // eax
  int tnew; // ecx
  int mtime; // eax
  int mtimecur; // ecx
  float v11; // xmm0_4
  float v12; // xmm0_4
  int D0; // ebx
  int mix; // eax
  int Next; // eax
  int *p_right; // esi
  float ramptime; // [esp-8h] [ebp-1Ch]
  int left; // [esp-4h] [ebp-18h]
  mdy_t *pmdya; // [esp+24h] [ebp+10h]
  portable_samplepair_t *pb; // [esp+28h] [ebp+14h]

  v4 = pbuffer;
  v5 = (int)SampleCount;
  if ( op == (portable_samplepair_t *)1 )
  {
    if ( SampleCount != nullptr )
    {
      p_right = &pbuffer->right;
      do
      {
        *p_right = MDY_GetNext(pmdy, x: *p_right);
        p_right += 2;
        --v5;
      }
      while ( v5 != 0 );
    }
  }
  else if ( op == (portable_samplepair_t *)2 )
  {
    if ( SampleCount != nullptr )
    {
      do
      {
        Next = MDY_GetNext(pmdy, x: v4->left);
        v4->right = Next;
        v4->left = Next;
        ++v4;
        --v5;
      }
      while ( v5 != 0 );
    }
  }
  else if ( SampleCount != nullptr )
  {
    while ( 1 )
    {
      pb = (portable_samplepair_t *)(v5 - 1);
      pmdya = (mdy_t *)v4->left;
      left = v4->left;
      if ( pmdy->fchanging )
      {
        NextXfade = DLY_GetNextXfade(pdly: pmdy->pdly, x: left);
        pmdy->pdly->xf = RMP_GetNext(prmp: &pmdy->rmp_interp);
        if ( pmdy->rmp_interp.fhitend )
        {
          pdly = pmdy->pdly;
          tnew = pdly->tnew;
          if ( tnew >= pdly->D0 )
            tnew = pdly->D0;
          pdly->t = tnew;
          pmdy->pdly->t = pmdy->pdly->tnew;
          pmdy->fchanging = false;
        }
      }
      else
      {
        NextXfade = DLY_GetNext(pdly: pmdy->pdly, x: left);
      }
      mtime = pmdy->mtime;
      if ( mtime != 0 )
      {
        mtimecur = pmdy->mtimecur;
        pmdy->mtimecur = mtimecur - 1;
        if ( mtimecur == 0 )
        {
          v11 = 1.0 - pmdy->depth;
          pmdy->mtimecur = mtime;
          v12 = v11 * (float)pmdy->pdly->D0;
          D0 = _RandomInt(this: (IUniformRandomStream *)(int)v12, a2: (int)v12, a3: pmdy->pdly->D0);
          if ( pmdy->pdly->D0 < D0 )
            D0 = pmdy->pdly->D0;
          ramptime = pmdy->ramptime;
          pmdy->fchanging = true;
          RMP_Init(prmp: &pmdy->rmp_interp, ramptime, initval: 0, targetval: 4096, bEndAtTime: false);
          pmdy->pdly->tnew = D0;
          v4 = pbuffer;
          pmdy->pdly->xf = 0;
        }
      }
      if ( pmdy->bPhaseInvert )
        NextXfade = -NextXfade;
      mix = pmdy->mix;
      if ( mix != 4096 )
      {
        if ( mix == 2048 )
          NextXfade = ((int)pmdya + NextXfade) >> 1;
        else
          NextXfade = (int)pmdya + ((mix * (NextXfade - (int)pmdya)) >> 12);
      }
      v4->left = NextXfade;
      pbuffer = ++v4;
      if ( pb == nullptr )
        break;
      v5 = (int)pb;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10020530
// Name: void MDY_Mod(struct mdy_t __near *,float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MDY_Mod(mdy_t *pmdy, float v)
{
  float v2; // xmm0_4
  dly_t *pdly; // eax
  int D0; // ecx
  int v5; // eax
  int v6; // edi
  float ramptime; // [esp-18h] [ebp-18h]

  v2 = v;
  pdly = pmdy->pdly;
  D0 = pdly->D0;
  if ( v >= -2.0 )
  {
    pmdy->bPhaseInvert = false;
  }
  else
  {
    v2 = v + 10.0;
    pmdy->bPhaseInvert = true;
  }
  v5 = pdly->D0;
  v6 = D0 + (int)(float)((float)((float)(v2 + 1.0) * -0.5) * (float)D0);
  if ( v5 < v6 )
    v6 = v5;
  ramptime = pmdy->ramptime;
  pmdy->fchanging = true;
  RMP_Init(prmp: &pmdy->rmp_interp, ramptime, initval: 0, targetval: 4096, bEndAtTime: false);
  pmdy->pdly->tnew = v6;
  pmdy->pdly->xf = 0;
}

//------------------------------------------------------------------------------
// Address: 0x100205C0
// Name: void RVA_Free(struct rva_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl RVA_Free(rva_t *prva)
{
  dly_t **pdlys; // edi
  int i; // ebx
  dly_t *v3; // esi
  mdy_t **v4; // eax
  int j; // edx
  int v6; // ecx
  mdy_t *v7; // ecx
  mdy_t *v8; // ecx
  mdy_t *v9; // ecx
  mdy_t *v10; // ecx
  mdy_t *v11; // ebx
  dly_t *pdly; // edi
  flt_t *pflt; // esi
  flt_t *pf1; // eax
  flt_t *pf2; // eax
  flt_t *pf3; // eax
  flt_t *v17; // esi
  flt_t *v18; // eax
  flt_t *v19; // eax
  flt_t *v20; // eax
  int k; // [esp+4h] [ebp-8h]
  mdy_t **pmdlys; // [esp+8h] [ebp-4h]

  if ( prva != nullptr )
  {
    pdlys = prva->pdlys;
    for ( i = 12; i != 0; --i )
    {
      v3 = *pdlys;
      if ( *pdlys != nullptr )
      {
        FLT_Free(pf: v3->pflt);
        if ( v3->w != nullptr )
          free(pMem: v3->w);
        _V_memset(dest: v3, fill: 0, count: 72);
      }
      ++pdlys;
    }
    v4 = &prva->pmdlys[1];
    for ( j = 2; j != 0; --j )
    {
      v6 = (int)*(v4 - 1);
      if ( v6 != 0 )
        *(_DWORD *)(v6 + 4) = 0;
      if ( *v4 != nullptr )
        (*v4)->pdly = nullptr;
      v7 = v4[1];
      if ( v7 != nullptr )
        v7->pdly = nullptr;
      v8 = v4[2];
      if ( v8 != nullptr )
        v8->pdly = nullptr;
      v9 = v4[3];
      if ( v9 != nullptr )
        v9->pdly = nullptr;
      v10 = v4[4];
      if ( v10 != nullptr )
        v10->pdly = nullptr;
      v4 += 6;
    }
    pmdlys = prva->pmdlys;
    for ( k = 12; k != 0; --k )
    {
      v11 = *pmdlys;
      if ( *pmdlys != nullptr )
      {
        pdly = v11->pdly;
        if ( pdly != nullptr )
        {
          pflt = pdly->pflt;
          if ( pflt != nullptr )
          {
            pf1 = pflt->pf1;
            if ( pf1 != nullptr )
              _V_memset(dest: pf1, fill: 0, count: 184);
            pf2 = pflt->pf2;
            if ( pf2 != nullptr )
              _V_memset(dest: pf2, fill: 0, count: 184);
            pf3 = pflt->pf3;
            if ( pf3 != nullptr )
              _V_memset(dest: pf3, fill: 0, count: 184);
            _V_memset(dest: pflt, fill: 0, count: 184);
          }
          if ( pdly->w != nullptr )
            free(pMem: pdly->w);
          _V_memset(dest: pdly, fill: 0, count: 72);
        }
        _V_memset(dest: v11, fill: 0, count: 76);
      }
      ++pmdlys;
    }
    v17 = prva->pflt;
    if ( v17 != nullptr )
    {
      v18 = v17->pf1;
      if ( v18 != nullptr )
        _V_memset(dest: v18, fill: 0, count: 184);
      v19 = v17->pf2;
      if ( v19 != nullptr )
        _V_memset(dest: v19, fill: 0, count: 184);
      v20 = v17->pf3;
      if ( v20 != nullptr )
        _V_memset(dest: v20, fill: 0, count: 184);
      _V_memset(dest: v17, fill: 0, count: 184);
    }
    _V_memset(dest: prva, fill: 0, count: 116);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100207B0
// Name: void RVA_FreeAll(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl RVA_FreeAll()
{
  rva_t *v0; // esi
  dly_t *v1; // edi
  flt_t *pflt; // esi
  flt_t *pf1; // eax
  flt_t *pf2; // eax
  flt_t *pf3; // eax
  mdy_t **v6; // eax
  int j; // edx
  int v8; // ecx
  mdy_t *v9; // ecx
  mdy_t *v10; // ecx
  mdy_t *v11; // ecx
  mdy_t *v12; // ecx
  mdy_t **pmdlys; // esi
  mdy_t *v14; // ebx
  dly_t *pdly; // edi
  flt_t *v16; // esi
  flt_t *v17; // eax
  flt_t *v18; // eax
  flt_t *v19; // eax
  bool v20; // zf
  flt_t *v21; // esi
  flt_t *v22; // eax
  flt_t *v23; // eax
  flt_t *v24; // eax
  int i; // [esp+Ch] [ebp-Ch]
  mdy_t **v26; // [esp+Ch] [ebp-Ch]
  dly_t **pdlys; // [esp+10h] [ebp-8h]
  int v28; // [esp+10h] [ebp-8h]
  rva_t *dest; // [esp+14h] [ebp-4h]

  v0 = rvas;
  dest = rvas;
  do
  {
    if ( v0 != nullptr )
    {
      pdlys = v0->pdlys;
      for ( i = 12; i != 0; --i )
      {
        v1 = *pdlys;
        if ( *pdlys != nullptr )
        {
          pflt = v1->pflt;
          if ( pflt != nullptr )
          {
            pf1 = pflt->pf1;
            if ( pf1 != nullptr )
              _V_memset(dest: pf1, fill: 0, count: 184);
            pf2 = pflt->pf2;
            if ( pf2 != nullptr )
              _V_memset(dest: pf2, fill: 0, count: 184);
            pf3 = pflt->pf3;
            if ( pf3 != nullptr )
              _V_memset(dest: pf3, fill: 0, count: 184);
            _V_memset(dest: pflt, fill: 0, count: 184);
          }
          if ( v1->w != nullptr )
            free(pMem: v1->w);
          _V_memset(dest: v1, fill: 0, count: 72);
          v0 = dest;
        }
        ++pdlys;
      }
      v6 = &v0->pmdlys[1];
      for ( j = 2; j != 0; --j )
      {
        v8 = (int)*(v6 - 1);
        if ( v8 != 0 )
          *(_DWORD *)(v8 + 4) = 0;
        if ( *v6 != nullptr )
          (*v6)->pdly = nullptr;
        v9 = v6[1];
        if ( v9 != nullptr )
          v9->pdly = nullptr;
        v10 = v6[2];
        if ( v10 != nullptr )
          v10->pdly = nullptr;
        v11 = v6[3];
        if ( v11 != nullptr )
          v11->pdly = nullptr;
        v12 = v6[4];
        if ( v12 != nullptr )
          v12->pdly = nullptr;
        v6 += 6;
      }
      pmdlys = v0->pmdlys;
      v26 = pmdlys;
      v28 = 12;
      do
      {
        v14 = *pmdlys;
        if ( *pmdlys != nullptr )
        {
          pdly = v14->pdly;
          if ( pdly != nullptr )
          {
            v16 = pdly->pflt;
            if ( v16 != nullptr )
            {
              v17 = v16->pf1;
              if ( v17 != nullptr )
                _V_memset(dest: v17, fill: 0, count: 184);
              v18 = v16->pf2;
              if ( v18 != nullptr )
                _V_memset(dest: v18, fill: 0, count: 184);
              v19 = v16->pf3;
              if ( v19 != nullptr )
                _V_memset(dest: v19, fill: 0, count: 184);
              _V_memset(dest: v16, fill: 0, count: 184);
            }
            if ( pdly->w != nullptr )
              free(pMem: pdly->w);
            _V_memset(dest: pdly, fill: 0, count: 72);
          }
          _V_memset(dest: v14, fill: 0, count: 76);
        }
        pmdlys = v26 + 1;
        v20 = v28-- == 1;
        ++v26;
      }
      while ( !v20 );
      v21 = dest->pflt;
      if ( v21 != nullptr )
      {
        v22 = v21->pf1;
        if ( v22 != nullptr )
          _V_memset(dest: v22, fill: 0, count: 184);
        v23 = v21->pf2;
        if ( v23 != nullptr )
          _V_memset(dest: v23, fill: 0, count: 184);
        v24 = v21->pf3;
        if ( v24 != nullptr )
          _V_memset(dest: v24, fill: 0, count: 184);
        _V_memset(dest: v21, fill: 0, count: 184);
      }
      _V_memset(dest, fill: 0, count: 116);
      v0 = dest;
    }
    dest = ++v0;
  }
  while ( (int)v0 < (int)mdys );
}

//------------------------------------------------------------------------------
// Address: 0x10020A20
// Name: void RVA_Print(struct rva_t const __near &,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl RVA_Print(const rva_t *rva, int nIndentation)
{
  char *IndentationText; // edi
  flt_t *pflt; // ebx
  int v4; // ebx
  int v5; // ebx
  dly_t **pdlys; // [esp+Ch] [ebp-4h]
  mdy_t **pmdlys; // [esp+Ch] [ebp-4h]

  IndentationText = GetIndentationText(nIndentation);
  DevMsg(a1: "%sRVA: %08X [Addr]\n", IndentationText, rva);
  DevMsg(a1: "%sfused: %d\n", IndentationText, rva->fused);
  DevMsg(a1: "%sm: %d\n", IndentationText, rva->m);
  DevMsg(a1: "%sfparallel: %d\n", IndentationText, rva->fparallel);
  DevMsg(a1: "%sFilter:", IndentationText);
  pflt = rva->pflt;
  if ( pflt != nullptr )
    FLT_Print(filter: pflt, nIndentation: nIndentation + 1);
  else
    DevMsg(a1: "NULL\n");
  v4 = 0;
  pdlys = rva->pdlys;
  do
  {
    DevMsg(a1: "%sDelay[%d]: ", IndentationText, v4);
    if ( *pdlys != nullptr )
      DLY_Print(delay: *pdlys, nIndentation: nIndentation + 1);
    else
      DevMsg(a1: "NULL\n");
    ++pdlys;
    ++v4;
  }
  while ( v4 < 12 );
  v5 = 0;
  pmdlys = rva->pmdlys;
  do
  {
    DevMsg(a1: "%sModDelay[%d]: ", IndentationText, v5);
    if ( *pmdlys != nullptr )
      MDY_Print(modDelay: *pmdlys, nIndentation: nIndentation + 1);
    else
      DevMsg(a1: "NULL\n");
    ++pmdlys;
    ++v5;
  }
  while ( v5 < 12 );
  DevMsg(a1: "%sfmoddly: %d\n", IndentationText, rva->fmoddly);
}

//------------------------------------------------------------------------------
// Address: 0x10020B40
// Name: int RVA_GetNext(struct rva_t __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl RVA_GetNext(rva_t *prva, int x)
{
  rva_t *v2; // esi
  int m; // eax
  int v4; // edi
  mdy_t **pmdlys; // esi
  int v6; // ebx
  dly_t **pdlys; // esi
  int v8; // ebx
  flt_t *pflt; // esi

  v2 = prva;
  m = prva->m;
  v4 = 0;
  if ( prva->fmoddly )
  {
    if ( m > 0 )
    {
      pmdlys = prva->pmdlys;
      v6 = prva->m;
      do
      {
        v4 += MDY_GetNext(pmdy: *pmdlys++, x);
        --v6;
      }
      while ( v6 != 0 );
LABEL_9:
      v2 = prva;
    }
  }
  else if ( m > 0 )
  {
    pdlys = prva->pdlys;
    v8 = prva->m;
    do
    {
      v4 += DLY_GetNext(pdly: *pdlys++, x);
      --v8;
    }
    while ( v8 != 0 );
    goto LABEL_9;
  }
  if ( v2->fparallel == 0 )
  {
    pflt = v2->pflt;
    if ( pflt != nullptr )
      return FLT_GetNext(pf: pflt, x: v4);
  }
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x10020BC0
// Name: void RVA_GetNextN(struct rva_t __near *,struct portable_samplepair_t __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl RVA_GetNextN(rva_t *prva, portable_samplepair_t *pbuffer, portable_samplepair_t *SampleCount, int op)
{
  portable_samplepair_t *v5; // edi
  rva_t *v6; // eax
  int left; // ebx
  int m; // ecx
  int v9; // esi
  mdy_t **pmdlys; // edi
  dly_t **pdlys; // edi
  flt_t *pflt; // eax
  int Next; // eax
  int *p_right; // edi
  portable_samplepair_t *pbuffera; // [esp+18h] [ebp+Ch]
  portable_samplepair_t *pbufferb; // [esp+18h] [ebp+Ch]
  portable_samplepair_t *pb; // [esp+1Ch] [ebp+10h]
  int count; // [esp+20h] [ebp+14h]

  v5 = pbuffer;
  pb = pbuffer;
  if ( op == 1 )
  {
    if ( SampleCount != nullptr )
    {
      p_right = &pbuffer->right;
      do
      {
        *p_right = RVA_GetNext(prva, x: *p_right);
        p_right += 2;
        SampleCount = (portable_samplepair_t *)((char *)SampleCount - 1);
      }
      while ( SampleCount != nullptr );
    }
  }
  else if ( op == 2 )
  {
    for ( ; SampleCount != nullptr; SampleCount = (portable_samplepair_t *)((char *)SampleCount - 1) )
    {
      Next = RVA_GetNext(prva, x: v5->left);
      v5->right = Next;
      v5->left = Next;
      ++v5;
    }
  }
  else if ( SampleCount != nullptr )
  {
    while ( 1 )
    {
      v6 = prva;
      left = v5->left;
      m = prva->m;
      count = (int)&SampleCount[-1].right + 3;
      v9 = 0;
      if ( prva->fmoddly )
      {
        if ( m <= 0 )
          goto LABEL_15;
        pmdlys = prva->pmdlys;
        pbuffera = (portable_samplepair_t *)prva->m;
        do
        {
          v9 += MDY_GetNext(pmdy: *pmdlys++, x: left);
          pbuffera = (portable_samplepair_t *)((char *)pbuffera - 1);
        }
        while ( pbuffera != nullptr );
      }
      else
      {
        if ( m <= 0 )
          goto LABEL_15;
        pdlys = prva->pdlys;
        pbufferb = (portable_samplepair_t *)prva->m;
        do
        {
          v9 += DLY_GetNext(pdly: *pdlys++, x: left);
          pbufferb = (portable_samplepair_t *)((char *)pbufferb - 1);
        }
        while ( pbufferb != nullptr );
      }
      v5 = pb;
      v6 = prva;
LABEL_15:
      if ( v6->fparallel == 0 )
      {
        pflt = v6->pflt;
        if ( pflt != nullptr )
          v9 = FLT_GetNext(pf: pflt, x: v9);
      }
      v5->left = v9;
      pb = ++v5;
      if ( count == 0 )
        return;
      SampleCount = (portable_samplepair_t *)count;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10020CD0
// Name: void RVA_ConstructDelays(float __near *,float __near *,int,int __near *,int __near *,int __near *,float,float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl RVA_ConstructDelays(float *rgd, float *rgf, int m, int *D, int *a, int *b, float gain, float feedback)
{
  float *v8; // ebx
  float v9; // xmm0_4
  float v10; // xmm1_4
  int v12; // xmm0_4
  float v13; // xmm1_4
  int v14; // xmm0_4
  int v15; // xmm0_4
  float v16; // xmm0_4
  float v17; // xmm1_4
  int v18; // xmm0_4
  float v19; // xmm1_4
  float v20; // xmm0_4
  int *v21; // esi
  int v22; // eax
  float v23; // xmm1_4
  float v24; // xmm0_4
  float v25; // xmm2_4
  int v26; // ebx
  long double v27; // st7
  double v28; // st5
  double v29; // st6
  long double v30; // st6
  long double v31; // st7
  float dm; // [esp+10h] [ebp-14h]
  int d; // [esp+1Ch] [ebp-8h]
  int i; // [esp+20h] [ebp-4h]
  char bpredelay_3; // [esp+33h] [ebp+Fh]

  v8 = rgd;
  v9 = rgd[2];
  v10 = rgd[1];
  if ( v9 > v10 )
  {
    rgd[2] = v10;
    rgd[1] = v9;
    v12 = *((_DWORD *)rgf + 2);
    rgf[2] = rgf[1];
    *((_DWORD *)rgf + 1) = v12;
  }
  v13 = rgd[1];
  v14 = *(_DWORD *)rgd;
  if ( v13 > *rgd )
  {
    *rgd = v13;
    *((_DWORD *)rgd + 1) = v14;
    v15 = *(_DWORD *)rgf;
    *rgf = rgf[1];
    *((_DWORD *)rgf + 1) = v15;
  }
  v16 = rgd[2];
  v17 = rgd[1];
  if ( v16 > v17 )
  {
    rgd[2] = v17;
    rgd[1] = v16;
    v18 = *((_DWORD *)rgf + 2);
    rgf[2] = rgf[1];
    *((_DWORD *)rgf + 1) = v18;
  }
  if ( *rgf == 0.0 && rgf[1] == 0.0 && rgf[2] == 0.0 )
  {
    rgf[2] = feedback;
    rgf[1] = feedback;
    *rgf = feedback;
    *rgf = pow(feedback, (double)(int)*rgd / (double)(int)rgd[2]);
    rgf[1] = pow(feedback, (double)(int)rgd[1] / (double)(int)rgd[2]);
  }
  v19 = rgd[1] - rgd[2];
  v20 = (float)(7 * (m / 3));
  if ( v20 >= v19 )
    rgd[1] = (float)(v20 - v19) + rgd[1];
  if ( v20 >= (float)(*rgd - rgd[1]) )
    *rgd = (float)(v20 - v19) + *rgd;
  i = 0;
  if ( m > 0 )
  {
    v21 = a;
    while ( 1 )
    {
      v22 = (int)fmod((double)i, 3.0);
      v23 = rgf[v22];
      v24 = v8[v22];
      v25 = 0.0;
      v26 = (int)v24;
      d = (int)v24;
      v27 = fabs(v23);
      if ( v23 >= 0.0 || (bpredelay_3 = 1, i >= 3) )
        bpredelay_3 = 0;
      if ( v23 < 0.0 && bpredelay_3 == 0 )
      {
        v26 = (int)(float)(v24 * 0.25);
        if ( v26 <= 7 )
          v26 = 7;
        d = v26;
      }
      if ( i >= 3 )
      {
        v28 = (double)(int)(7 * (i / 3u));
        v29 = (double)d * 0.18 * (double)(i / 3u);
        if ( v28 > v29 )
          v29 = v28;
        dm = v29;
        v25 = dm;
      }
      v30 = v27 * 4096.0;
      v31 = 4091.904;
      *(int *)((char *)v21 + (char *)D - (char *)a) = 44100 * (v26 + (int)v25) / 1000;
      if ( v30 <= 4091.904 )
        v31 = v30;
      *v21 = (int)v31;
      if ( bpredelay_3 != 0 )
        *v21 = -(int)v31;
      *(int *)((char *)v21++ + (char *)b - (char *)a) = (int)(float)((float)(gain * 4096.0) / (float)m);
      if ( ++i >= m )
        break;
      v8 = rgd;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10020FA0
// Name: void DFR_Free(struct dfr_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DFR_Free(dfr_t *pdfr)
{
  dly_t **pdlys; // edi
  int i; // ebx
  dly_t *v3; // esi

  if ( pdfr != nullptr )
  {
    pdlys = pdfr->pdlys;
    for ( i = 16; i != 0; --i )
    {
      v3 = *pdlys;
      if ( *pdlys != nullptr )
      {
        FLT_Free(pf: v3->pflt);
        if ( v3->w != nullptr )
          free(pMem: v3->w);
        _V_memset(dest: v3, fill: 0, count: 72);
      }
      ++pdlys;
    }
    _V_memset(dest: pdfr, fill: 0, count: 136);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10021010
// Name: void DFR_Print(struct dfr_t const __near &,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DFR_Print(const dfr_t *dfr, int nIndentation)
{
  char *IndentationText; // ebx
  int v3; // esi
  dly_t **pdlys; // edi

  IndentationText = GetIndentationText(nIndentation);
  DevMsg(a1: "%sDFR: %08X [Addr]\n", IndentationText, dfr);
  DevMsg(a1: "%sfused: %d\n", IndentationText, dfr->fused);
  v3 = 0;
  pdlys = dfr->pdlys;
  do
  {
    DevMsg(a1: "%sDelay[%d]: ", IndentationText, v3);
    if ( *pdlys != nullptr )
      DLY_Print(delay: *pdlys, nIndentation: nIndentation + 1);
    else
      DevMsg(a1: "NULL\n");
    ++v3;
    ++pdlys;
  }
  while ( v3 < 16 );
}

//------------------------------------------------------------------------------
// Address: 0x10021090
// Name: int DFR_GetNext(struct dfr_t __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl DFR_GetNext(dfr_t *pdfr, int x)
{
  int result; // eax
  dly_t *v3; // ecx
  int *w; // edi
  int *p; // ebx
  int a; // esi
  int *v7; // edx
  int *v8; // edx
  int b; // [esp+0h] [ebp-14h]
  int i; // [esp+4h] [ebp-10h]
  int y; // [esp+8h] [ebp-Ch]
  int v12; // [esp+Ch] [ebp-8h]
  dly_t **pdlys; // [esp+10h] [ebp-4h]
  int xa; // [esp+20h] [ebp+Ch]

  result = x;
  y = x;
  i = 0;
  if ( pdfr->n > 0 )
  {
    pdlys = pdfr->pdlys;
    do
    {
      v3 = *pdlys;
      w = (*pdlys)->w;
      p = (*pdlys)->p;
      a = (*pdlys)->a;
      b = (*pdlys)->b;
      v12 = 4 * (*pdlys)->D;
      v7 = &p[(*pdlys)->t];
      if ( v7 > &w[v12 / 4u] )
        xa = v7[v12 / 0xFFFFFFFC - 1];
      else
        xa = *v7;
      *p = y + ((a * xa) >> 12);
      v8 = --v3->p;
      if ( v8 < w )
        v3->p = &v8[v12 / 4u + 1];
      ++pdlys;
      result = (b * (xa + (-(a * (y + ((a * xa) >> 12))) >> 12))) >> 12;
      y = result;
      ++i;
    }
    while ( i < pdfr->n );
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10021160
// Name: void DFR_GetNextN(struct dfr_t __near *,struct portable_samplepair_t __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DFR_GetNextN(dfr_t *pdfr, portable_samplepair_t *pbuffer, int SampleCount, int op)
{
  portable_samplepair_t *v4; // esi
  int v5; // edi
  int left; // eax
  dly_t *v7; // ecx
  int *w; // edi
  int *p; // ebx
  int a; // esi
  int *v11; // edx
  int *v12; // edx
  int Next; // eax
  int *p_right; // esi
  int count; // [esp+Ch] [ebp-14h]
  int b; // [esp+10h] [ebp-10h]
  portable_samplepair_t *pb; // [esp+14h] [ebp-Ch]
  int v18; // [esp+18h] [ebp-8h]
  int v19; // [esp+1Ch] [ebp-4h]
  dly_t **pbuffera; // [esp+2Ch] [ebp+Ch]
  int SampleCounta; // [esp+30h] [ebp+10h]
  int opa; // [esp+34h] [ebp+14h]

  v4 = pbuffer;
  v5 = SampleCount;
  pb = pbuffer;
  if ( op == 1 )
  {
    if ( SampleCount != 0 )
    {
      p_right = &pbuffer->right;
      do
      {
        *p_right = DFR_GetNext(pdfr, x: *p_right);
        p_right += 2;
        --v5;
      }
      while ( v5 != 0 );
    }
  }
  else if ( op == 2 )
  {
    if ( SampleCount != 0 )
    {
      do
      {
        Next = DFR_GetNext(pdfr, x: v4->left);
        v4->right = Next;
        v4->left = Next;
        ++v4;
        --v5;
      }
      while ( v5 != 0 );
    }
  }
  else if ( SampleCount != 0 )
  {
    do
    {
      left = v4->left;
      count = --v5;
      v19 = v4->left;
      v18 = 0;
      if ( pdfr->n > 0 )
      {
        pbuffera = pdfr->pdlys;
        do
        {
          v7 = *pbuffera;
          w = (*pbuffera)->w;
          p = (*pbuffera)->p;
          a = (*pbuffera)->a;
          b = (*pbuffera)->b;
          opa = 4 * (*pbuffera)->D;
          v11 = &p[(*pbuffera)->t];
          if ( v11 > &w[opa / 4u] )
            SampleCounta = v11[opa / 0xFFFFFFFC - 1];
          else
            SampleCounta = *v11;
          *p = v19 + ((a * SampleCounta) >> 12);
          v12 = --v7->p;
          if ( v12 < w )
            v7->p = &v12[opa / 4u + 1];
          ++pbuffera;
          left = (b * (SampleCounta + (-(a * (v19 + ((a * SampleCounta) >> 12))) >> 12))) >> 12;
          v19 = left;
          ++v18;
        }
        while ( v18 < pdfr->n );
        v5 = count;
        v4 = pb;
      }
      v4->left = left;
      pb = ++v4;
    }
    while ( v5 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x100212B0
// Name: void __near * MemAlloc_AllocAlignedUnattributed(unsigned int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void *__cdecl MemAlloc_AllocAlignedUnattributed(unsigned int size, unsigned int align)
{
  unsigned int v2; // eax
  void *result; // eax
  unsigned int v4; // esi

  v2 = align;
  if ( ((align - 1) & align) != 0 )
    return nullptr;
  if ( align <= 4 )
    v2 = 4;
  v4 = v2 - 1;
  result = _g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: size + v2 - 1 + 4);
  if ( result != nullptr )
  {
    *(_DWORD *)((~v4 & ((unsigned int)result + v4 + 4)) - 4) = result;
    return (void *)(~v4 & ((unsigned int)result + v4 + 4));
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10021300
// Name: void LFOWAV_FreeAll(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl LFOWAV_FreeAll()
{
  lfowav_t *v0; // edi
  dly_t *pdly; // esi

  v0 = lfowavs;
  do
  {
    if ( v0 != nullptr )
    {
      pdly = v0->pdly;
      if ( pdly != nullptr )
      {
        FLT_Free(pf: pdly->pflt);
        if ( pdly->w != nullptr )
          free(pMem: pdly->w);
        _V_memset(dest: pdly, fill: 0, count: 72);
      }
    }
    _V_memset(dest: v0++, fill: 0, count: 8);
  }
  while ( (int)v0 < (int)dfrs );
}

//------------------------------------------------------------------------------
// Address: 0x10021360
// Name: void LFOWAV_Fill(int __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl LFOWAV_Fill(int *w, int count, int type)
{
  IUniformRandomStream *v3; // ecx
  int v4; // ecx
  int v5; // edx
  float v6; // xmm0_4
  int j; // ecx
  _BOOL2 v8; // dx
  int k; // eax
  int m; // esi
  int v11; // esi
  int v12; // esi
  int n; // eax
  int ii; // eax
  int v15; // esi
  int i; // [esp+20h] [ebp+10h]
  int ia; // [esp+20h] [ebp+10h]
  int ib; // [esp+20h] [ebp+10h]

  switch ( type )
  {
    case 1:
      v4 = 0;
      if ( count > 0 )
      {
        v5 = 0;
        do
        {
          v6 = (float)v5 / (float)count;
          w[v4] = (int)v6;
          if ( v4 > count / 2 )
            w[v4] = (int)(float)(32766.0 - v6);
          ++v4;
          v5 += 32766;
        }
        while ( v4 < count );
      }
      break;
    case 2:
      for ( j = 0; j < count; w[j - 1] = v8 ? 0 : 0x3FFF )
        v8 = j++ > count / 2;
      break;
    case 3:
      for ( k = 0; k < count; ++k )
        w[k] = (int)(float)((float)((float)k * 16383.0) / (float)count);
      break;
    case 4:
      for ( m = 0; m < count; ++m )
        w[m] = _RandomInt(this: v3, a2: 0, a3: 0x3FFF);
      break;
    case 5:
      v11 = 0;
      for ( i = 0; v11 < count; i = v11 )
        w[v11++] = (int)(pow((double)i / (float)count, 2.0) * 16383.0);
      break;
    case 6:
      v12 = 0;
      for ( ia = 0; v12 < count; ia = v12 )
        w[v12++] = (int)(pow(1.0 - (double)ia / (float)count, 2.0) * 16383.0);
      break;
    case 7:
      for ( n = 0; n < count; ++n )
        w[n] = (int)(float)((float)((float)n * 16383.0) / (float)count);
      break;
    case 8:
      for ( ii = 0; ii < count; ++ii )
        w[ii] = 0x3FFF - (int)(float)((float)((float)ii * 16383.0) / (float)count);
      break;
    default:
      v15 = 0;
      for ( ib = 0; v15 < count; ib = v15 )
        w[v15++] = (0x3FFF - (int)(sin((double)ib * 6.283185307179586 / (float)count + 4.71238898038469) * -16383.0))
                 / 2;
      break;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10021640
// Name: void LFO_Free(struct lfo_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl LFO_Free(lfo_t *plfo)
{
  if ( plfo != nullptr )
    _V_memset(dest: plfo, fill: 0, count: 56);
}

//------------------------------------------------------------------------------
// Address: 0x10021660
// Name: struct lfo_t __near * LFO_Alloc(int,float,bool,float)
// Source: json
//------------------------------------------------------------------------------
lfo_t *__cdecl LFO_Alloc(int wtype, float freqHz, bool foneshot, float gain)
{
  int v4; // edi
  int v5; // ecx
  lfo_t *v6; // eax
  lfo_t *v8; // esi
  int v9; // eax
  float v10; // xmm0_4
  int v11; // eax
  int v12; // ecx

  v4 = 8;
  if ( wtype <= 8 )
    v4 = wtype;
  v5 = 0;
  v6 = lfos;
  while ( v6->fused )
  {
    ++v6;
    ++v5;
    if ( (int)v6 >= (int)lfowavs )
    {
      DevMsg(a1: "DSP: Warning, failed to allocate LFO.\n");
      return nullptr;
    }
  }
  v8 = &lfos[v5];
  if ( v8 != nullptr )
    _V_memset(dest: &lfos[v5], fill: 0, count: 56);
  v9 = dword_10454424[2 * v4];
  v8->foneshot = foneshot;
  v8->f = freqHz;
  v10 = freqHz * 0.011609977;
  v8->fused = true;
  v8->pdly = (dly_t *)v9;
  v8->gain = (int)(float)(gain * 4096.0);
  v11 = *(_DWORD *)(v9 + 8);
  v12 = (int)(float)(freqHz * 0.011609977);
  if ( foneshot )
  {
    if ( v12 > 4095 )
      v10 = (float)(v10 - (float)v12) + 4095.0;
    v8->pos1.p.D = v11;
    v8->pos1.p.cstep = 0;
    v8->pos1.p.pos = 0;
    v8->pos1.fhitend = false;
    v8->pos1.p.step = (int)(float)(v10 * 1048576.0);
    return v8;
  }
  else
  {
    if ( v12 > 4095 )
      v10 = (float)(v10 - (float)v12) + 4095.0;
    v8->pos.D = v11;
    v8->pos.cstep = 0;
    v8->pos.pos = 0;
    v8->pos.step = (int)(float)(v10 * 1048576.0);
    return v8;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10021790
// Name: int LFO_GetNext(struct lfo_t __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl LFO_GetNext(lfo_t *plfo)
{
  int v1; // ecx
  int D; // edx
  int v3; // ecx
  int v4; // ecx
  int pos; // esi
  int step; // edx
  int v7; // ecx
  int v8; // ecx
  int gain; // ecx
  int result; // eax

  if ( plfo->foneshot != 0 )
  {
    pos = plfo->pos1.p.pos;
    if ( !plfo->pos1.fhitend )
    {
      step = plfo->pos1.p.step;
      v7 = step + plfo->pos1.p.cstep;
      plfo->pos1.p.pos = pos + (v7 >> 20);
      plfo->pos1.p.cstep = v7 - (v7 & 0xFFF00000);
      if ( step != 0 && (v8 = plfo->pos1.p.pos) >= 0 && v8 < plfo->pos1.p.D )
        pos = plfo->pos1.p.pos;
      else
        plfo->pos1.fhitend = true;
    }
  }
  else
  {
    v1 = plfo->pos.cstep + plfo->pos.step;
    plfo->pos.pos += v1 >> 20;
    D = plfo->pos.D;
    plfo->pos.cstep = v1 - (v1 & 0xFFF00000);
    v3 = plfo->pos.pos;
    if ( v3 > D )
      plfo->pos.pos = v3 - D - 1;
    v4 = plfo->pos.pos;
    if ( v4 < 0 )
      plfo->pos.pos = v4 + D + 1;
    pos = plfo->pos.pos;
  }
  gain = plfo->gain;
  result = plfo->pdly->w[pos];
  if ( gain != 4096 )
    return (gain * result) >> 12;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10021840
// Name: void LFO_GetNextN(struct lfo_t __near *,struct portable_samplepair_t __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl LFO_GetNextN(lfo_t *plfo, portable_samplepair_t *pbuffer, int SampleCount, int op)
{
  portable_samplepair_t *v4; // esi
  int v5; // edi
  int v6; // ecx
  int D; // edx
  int v8; // ecx
  int v9; // ecx
  int pos; // ecx
  int step; // edx
  int v12; // ecx
  int gain; // edx
  int v14; // ecx
  int Next; // eax
  int *p_right; // esi
  int SampleCounta; // [esp+1Ch] [ebp+10h]

  v4 = pbuffer;
  v5 = SampleCount;
  if ( op == 1 )
  {
    if ( SampleCount != 0 )
    {
      p_right = &pbuffer->right;
      do
      {
        *p_right = LFO_GetNext(plfo);
        p_right += 2;
        --v5;
      }
      while ( v5 != 0 );
    }
  }
  else if ( op == 2 )
  {
    if ( SampleCount != 0 )
    {
      do
      {
        Next = LFO_GetNext(plfo);
        v4->right = Next;
        v4->left = Next;
        ++v4;
        --v5;
      }
      while ( v5 != 0 );
    }
  }
  else if ( SampleCount != 0 )
  {
    do
    {
      --v5;
      if ( plfo->foneshot != 0 )
      {
        pos = plfo->pos1.p.pos;
        SampleCounta = pos;
        if ( !plfo->pos1.fhitend )
        {
          step = plfo->pos1.p.step;
          v12 = step + plfo->pos1.p.cstep;
          plfo->pos1.p.pos = SampleCounta + (v12 >> 20);
          plfo->pos1.p.cstep = v12 - (v12 & 0xFFF00000);
          if ( step == 0 || (pos = plfo->pos1.p.pos) < 0 || pos >= plfo->pos1.p.D )
          {
            pos = SampleCounta;
            plfo->pos1.fhitend = true;
          }
        }
      }
      else
      {
        v6 = plfo->pos.step + plfo->pos.cstep;
        plfo->pos.pos += v6 >> 20;
        D = plfo->pos.D;
        plfo->pos.cstep = v6 - (v6 & 0xFFF00000);
        v8 = plfo->pos.pos;
        if ( v8 > D )
          plfo->pos.pos = v8 - D - 1;
        v9 = plfo->pos.pos;
        if ( v9 < 0 )
          plfo->pos.pos = v9 + D + 1;
        pos = plfo->pos.pos;
      }
      gain = plfo->gain;
      if ( gain == 4096 )
        v14 = plfo->pdly->w[pos];
      else
        v14 = (gain * plfo->pdly->w[pos]) >> 12;
      v4->left = v14;
      ++v4;
    }
    while ( v5 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10021970
// Name: void LFO_Mod(struct lfo_t __near *,float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl LFO_Mod(lfo_t *plfo, float v)
{
  float v2; // xmm0_4

  v2 = (float)((float)((float)(v + 1.0) * plfo->f) * 0.011609977) * 1048576.0;
  if ( plfo->foneshot != 0 )
    plfo->pos.step = (int)v2;
  else
    plfo->pos1.p.step = (int)v2;
}

//------------------------------------------------------------------------------
// Address: 0x100219B0
// Name: void PTC_Free(struct ptc_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl PTC_Free(ptc_t *pptc)
{
  dly_t *pdly_in; // esi
  dly_t *pdly_out; // esi

  if ( pptc != nullptr )
  {
    pdly_in = pptc->pdly_in;
    if ( pdly_in != nullptr )
    {
      FLT_Free(pf: pdly_in->pflt);
      if ( pdly_in->w != nullptr )
        free(pMem: pdly_in->w);
      _V_memset(dest: pdly_in, fill: 0, count: 72);
    }
    pdly_out = pptc->pdly_out;
    if ( pdly_out != nullptr )
    {
      FLT_Free(pf: pdly_out->pflt);
      if ( pdly_out->w != nullptr )
        free(pMem: pdly_out->w);
      _V_memset(dest: pdly_out, fill: 0, count: 72);
    }
    _V_memset(dest: pptc, fill: 0, count: 72);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10021A30
// Name: void PTC_FreeAll(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl PTC_FreeAll()
{
  ptc_t *v0; // edi
  dly_t *pdly_in; // esi
  dly_t *pdly_out; // esi

  v0 = ptcs;
  do
  {
    if ( v0 != nullptr )
    {
      pdly_in = v0->pdly_in;
      if ( pdly_in != nullptr )
      {
        FLT_Free(pf: pdly_in->pflt);
        if ( pdly_in->w != nullptr )
          free(pMem: pdly_in->w);
        _V_memset(dest: pdly_in, fill: 0, count: 72);
      }
      pdly_out = v0->pdly_out;
      if ( pdly_out != nullptr )
      {
        FLT_Free(pf: pdly_out->pflt);
        if ( pdly_out->w != nullptr )
          free(pMem: pdly_out->w);
        _V_memset(dest: pdly_out, fill: 0, count: 72);
      }
      _V_memset(dest: v0, fill: 0, count: 72);
    }
    ++v0;
  }
  while ( (int)v0 < (int)lfos );
}

//------------------------------------------------------------------------------
// Address: 0x10021AC0
// Name: void TimeExpand(int __near *,int __near *,int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl TimeExpand(int *w, int *v, int cin, int cout, int cxfade, int cduplicate)
{
  int *v6; // edx
  int v7; // ebx
  int v8; // esi
  int v9; // eax
  int v10; // edi
  int *v11; // ecx
  int *v12; // edi
  int v13; // edx
  int v14; // ebx
  int *v15; // ecx
  int v16; // esi
  int v17; // edi
  int v18; // eax
  int v19; // edx
  int v20; // eax
  int *v21; // ecx
  int m; // [esp+Ch] [ebp-8h]
  int D; // [esp+10h] [ebp-4h]
  int cina; // [esp+24h] [ebp+10h]
  int cduplicatea; // [esp+30h] [ebp+1Ch]
  int *cduplicateb; // [esp+30h] [ebp+1Ch]

  v6 = w;
  v7 = cin - cduplicate;
  v8 = cin - 1;
  v9 = cin - cxfade;
  v10 = cin - cduplicate - cxfade;
  D = cin - 1;
  m = cin - cduplicate;
  if ( cin - cxfade > 0 )
  {
    v11 = v;
    cduplicatea = cin - cxfade;
    do
    {
      *v11 = *(int *)((char *)v11 + (char *)w - (char *)v);
      ++v11;
      --cduplicatea;
    }
    while ( cduplicatea != 0 );
    v6 = w;
  }
  if ( v9 <= v8 )
  {
    v12 = &v6[v10];
    v13 = (char *)v6 - (char *)v;
    v14 = 0;
    v15 = &v[v9];
    cduplicateb = v12;
    cina = v13;
    v16 = v8 - v9 + 1;
    while ( 1 )
    {
      v17 = *(int *)((char *)v15 + v13);
      v18 = v14 / cxfade;
      v19 = *cduplicateb++;
      v14 += 4096;
      ++v15;
      --v16;
      *(v15 - 1) = (v17 + (v19 - v17) * v18) >> 12;
      if ( v16 == 0 )
        break;
      v13 = cina;
    }
    v8 = D;
    v6 = w;
    v7 = m;
  }
  v20 = v7;
  if ( v7 <= v8 )
  {
    v21 = &v[v8 + 1];
    do
      *v21++ = v6[v20++];
    while ( v20 <= v8 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10021B90
// Name: void TimeCompress(int __near *,int __near *,int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl TimeCompress(int *w, int *v, int cin, int cout, int cxfade, int ccut)
{
  int v6; // eax
  int v7; // edx
  int *v8; // ecx
  int *v9; // edi
  int v10; // esi
  int v11; // edi
  int *v12; // ecx
  int v13; // ebx
  int v14; // eax
  int v15; // esi
  bool v16; // zf
  int cina; // [esp+20h] [ebp+10h]
  int *cinb; // [esp+20h] [ebp+10h]
  int p; // [esp+2Ch] [ebp+1Ch]
  int pa; // [esp+2Ch] [ebp+1Ch]

  v6 = cin - ccut;
  v7 = cin - ccut - cxfade;
  p = cin - cxfade;
  v8 = v;
  if ( v7 > 0 )
  {
    v9 = v;
    for ( cina = v7; cina != 0; --cina )
    {
      *v9 = *(int *)((char *)v9 + (char *)w - (char *)v);
      ++v9;
    }
    v8 = v;
  }
  if ( v7 < v6 )
  {
    v10 = (char *)w - (char *)v;
    v11 = 0;
    v12 = &v8[v7];
    cinb = &w[p];
    pa = v6 - v7;
    while ( 1 )
    {
      v13 = *cinb;
      v14 = v11 / cxfade;
      v15 = *(int *)((char *)v12 + v10);
      ++cinb;
      v11 += 4096;
      ++v12;
      v16 = pa-- == 1;
      *(v12 - 1) = (v15 + v14 * (v13 - v15)) >> 12;
      if ( v16 )
        break;
      v10 = (char *)w - (char *)v;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10021C30
// Name: int PTC_GetNext(struct ptc_t __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl PTC_GetNext(ptc_t *pptc, int x)
{
  bool v2; // bl
  int pos; // esi
  int step; // edx
  int v5; // ecx
  int v6; // ecx
  int v7; // esi
  float fstep; // xmm0_4
  int cout; // edx

  pptc->pin[pptc->iin++] = x;
  v2 = pptc->iin >= pptc->cin;
  pos = pptc->psn.p.pos;
  if ( !pptc->psn.fhitend )
  {
    step = pptc->psn.p.step;
    v5 = step + pptc->psn.p.cstep;
    pptc->psn.p.pos += v5 >> 20;
    pptc->psn.p.cstep = v5 - (v5 & 0xFFF00000);
    if ( step != 0 && (v6 = pptc->psn.p.pos) >= 0 && v6 < pptc->psn.p.D )
      pos = pptc->psn.p.pos;
    else
      pptc->psn.fhitend = true;
  }
  v7 = pptc->pout[pos];
  if ( v2 )
  {
    fstep = pptc->fstep;
    cout = pptc->cout;
    pptc->iin = 0;
    if ( (int)fstep > 4095 )
      fstep = (float)(fstep - (float)(int)fstep) + 4095.0;
    pptc->psn.p.step = (int)(float)(fstep * 1048576.0);
    pptc->psn.p.cstep = 0;
    pptc->psn.p.pos = 0;
    pptc->psn.p.D = cout;
    pptc->psn.fhitend = false;
    if ( pptc->fdup )
    {
      TimeExpand(
        w: pptc->pin,
        v: pptc->pout,
        cin: pptc->cin,
        cout: pptc->cout,
        cxfade: pptc->cxfade,
        cduplicate: pptc->cduplicate);
      return v7;
    }
    TimeCompress(w: pptc->pin, v: pptc->pout, cin: pptc->cin, cout: pptc->cout, cxfade: pptc->cxfade, ccut: pptc->ccut);
  }
  return v7;
}

//------------------------------------------------------------------------------
// Address: 0x10021D40
// Name: void PTC_GetNextN(struct ptc_t __near *,struct portable_samplepair_t __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl PTC_GetNextN(ptc_t *pptc, portable_samplepair_t *pbuffer, int SampleCount, int op)
{
  int v4; // ebx
  portable_samplepair_t *v5; // edi
  int pos; // eax
  int step; // ecx
  int v8; // eax
  float fstep; // xmm0_4
  int cout; // ecx
  int v11; // eax
  int cxfade; // edx
  int Next; // eax
  int *p_right; // esi
  portable_samplepair_t *pbuffera; // [esp+18h] [ebp+Ch]
  portable_samplepair_t *pbufferb; // [esp+18h] [ebp+Ch]
  bool SampleCount_3; // [esp+1Fh] [ebp+13h]

  v4 = SampleCount;
  v5 = pbuffer;
  if ( op == 1 )
  {
    if ( SampleCount != 0 )
    {
      p_right = &pbuffer->right;
      do
      {
        *p_right = PTC_GetNext(pptc, x: *p_right);
        p_right += 2;
        --v4;
      }
      while ( v4 != 0 );
    }
  }
  else if ( op == 2 )
  {
    if ( SampleCount != 0 )
    {
      do
      {
        Next = PTC_GetNext(pptc, x: v5->left);
        v5->right = Next;
        v5->left = Next;
        ++v5;
        --v4;
      }
      while ( v4 != 0 );
    }
  }
  else if ( SampleCount != 0 )
  {
    do
    {
      pptc->pin[pptc->iin++] = v5->left;
      --v4;
      SampleCount_3 = pptc->iin >= pptc->cin;
      pos = pptc->psn.p.pos;
      pbuffera = (portable_samplepair_t *)pos;
      if ( !pptc->psn.fhitend )
      {
        step = pptc->psn.p.step;
        v8 = step + pptc->psn.p.cstep;
        pptc->psn.p.pos += v8 >> 20;
        pptc->psn.p.cstep = v8 - (v8 & 0xFFF00000);
        if ( step == 0 || (pos = pptc->psn.p.pos) < 0 || pos >= pptc->psn.p.D )
        {
          pos = (int)pbuffera;
          pptc->psn.fhitend = true;
        }
      }
      pbufferb = (portable_samplepair_t *)pptc->pout[pos];
      if ( SampleCount_3 )
      {
        fstep = pptc->fstep;
        cout = pptc->cout;
        pptc->iin = 0;
        if ( (int)fstep > 4095 )
          fstep = (float)(fstep - (float)(int)fstep) + 4095.0;
        pptc->psn.p.step = (int)(float)(fstep * 1048576.0);
        pptc->psn.p.cstep = 0;
        pptc->psn.p.pos = 0;
        pptc->psn.p.D = cout;
        pptc->psn.fhitend = false;
        v11 = pptc->cout;
        cxfade = pptc->cxfade;
        if ( pptc->fdup )
          TimeExpand(w: pptc->pin, v: pptc->pout, cin: pptc->cin, cout: v11, cxfade, cduplicate: pptc->cduplicate);
        else
          TimeCompress(w: pptc->pin, v: pptc->pout, cin: pptc->cin, cout: v11, cxfade, ccut: pptc->ccut);
      }
      v5->left = (int)pbufferb;
      ++v5;
    }
    while ( v4 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10021ED0
// Name: void ENV_Free(struct env_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ENV_Free(env_t *penv)
{
  if ( penv != nullptr )
    _V_memset(dest: penv, fill: 0, count: 184);
}

//------------------------------------------------------------------------------
// Address: 0x10021EF0
// Name: struct env_t __near * ENV_Alloc(int,float,float,float,float,float,float,float,bool)
// Source: json
//------------------------------------------------------------------------------
env_t *__cdecl ENV_Alloc(
        int type,
        float famp1,
        float famp2,
        float famp3,
        float attack,
        float decay,
        float sustain,
        float release,
        bool fexp)
{
  int v9; // esi
  env_t *v10; // eax
  int v12; // esi
  bool v13; // zf
  env_t *v14; // esi
  int v15; // edi
  int v16; // ebx
  int targetval; // [esp+1Ch] [ebp-4h]

  v9 = 0;
  v10 = envs;
  while ( v10->fused )
  {
    ++v10;
    ++v9;
    if ( (int)v10 >= (int)ptcs )
    {
      DevMsg(a1: "DSP: Warning, failed to allocate envelope.\n");
      return nullptr;
    }
  }
  v12 = v9;
  v13 = &envs[v12] == nullptr;
  v14 = &envs[v12];
  v15 = (int)(float)(famp1 * 16384.0);
  v16 = (int)(float)(famp2 * 16384.0);
  targetval = (int)(float)(famp3 * 16384.0);
  if ( !v13 )
    _V_memset(dest: v14, fill: 0, count: 184);
  RMP_Init(prmp: v14->rmps, ramptime: attack, initval: 0, targetval: v15, bEndAtTime: true);
  RMP_Init(prmp: &v14->rmps[1], ramptime: decay, initval: v15, targetval: v16, bEndAtTime: true);
  RMP_Init(prmp: &v14->rmps[2], ramptime: sustain, initval: v16, targetval, bEndAtTime: true);
  RMP_Init(prmp: &v14->rmps[3], ramptime: release, initval: targetval, targetval: 0, bEndAtTime: true);
  v14->ienv = 0;
  *(_WORD *)&v14->fused = 1;
  v14->fexp = fexp;
  return v14;
}

//------------------------------------------------------------------------------
// Address: 0x10022000
// Name: int ENV_GetNext(struct env_t __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ENV_GetNext(env_t *penv, int x)
{
  int ienv; // edi
  int Next; // eax
  int v4; // ecx
  int result; // eax

  if ( penv->fhitend )
    return 0;
  ienv = penv->ienv;
  Next = RMP_GetNext(prmp: &penv->rmps[ienv]);
  v4 = Next;
  if ( penv->rmps[ienv].fhitend )
    ++ienv;
  penv->ienv = ienv;
  if ( ienv > 3 )
    penv->fhitend = true;
  result = (x * Next) >> 14;
  if ( penv->fexp )
    return (v4 * result) >> 14;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10022060
// Name: void ENV_GetNextN(struct env_t __near *,struct portable_samplepair_t __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ENV_GetNextN(env_t *penv, portable_samplepair_t *pbuffer, int SampleCount, int op)
{
  int v4; // esi
  portable_samplepair_t *v5; // ebx
  int v6; // esi
  bool *v7; // edi
  int v8; // eax
  int v9; // ecx
  int v10; // esi
  bool *v11; // edi
  int v12; // eax
  int v13; // ecx
  int *p_right; // edx
  int ienv; // esi
  int Next; // eax
  int v17; // ecx
  int pbuffera; // [esp+18h] [ebp+Ch]
  int pbufferb; // [esp+18h] [ebp+Ch]
  int pbufferc; // [esp+18h] [ebp+Ch]
  int count; // [esp+1Ch] [ebp+10h]
  int counta; // [esp+1Ch] [ebp+10h]
  int countb; // [esp+1Ch] [ebp+10h]
  int *opa; // [esp+20h] [ebp+14h]

  v4 = SampleCount;
  v5 = pbuffer;
  if ( op == 1 )
  {
    if ( SampleCount != 0 )
    {
      p_right = &pbuffer->right;
      opa = &pbuffer->right;
      do
      {
        countb = v4 - 1;
        pbufferc = *p_right;
        if ( penv->fhitend )
        {
          v17 = 0;
        }
        else
        {
          ienv = penv->ienv;
          Next = RMP_GetNext(prmp: &penv->rmps[ienv]);
          if ( penv->rmps[ienv].fhitend )
            ++ienv;
          penv->ienv = ienv;
          if ( ienv > 3 )
            penv->fhitend = true;
          if ( penv->fexp )
            v17 = (Next * ((pbufferc * Next) >> 14)) >> 14;
          else
            v17 = (pbufferc * Next) >> 14;
        }
        v4 = countb;
        *opa = v17;
        p_right = opa + 2;
        opa += 2;
      }
      while ( countb != 0 );
    }
  }
  else if ( op == 2 )
  {
    if ( SampleCount != 0 )
    {
      do
      {
        pbufferb = v5->left;
        counta = v4 - 1;
        if ( penv->fhitend )
        {
          v13 = 0;
        }
        else
        {
          v10 = penv->ienv;
          v11 = &penv->fused + 44 * v10;
          v12 = RMP_GetNext(prmp: (rmp_t *)(v11 + 8));
          if ( v11[28] )
            ++v10;
          penv->ienv = v10;
          if ( v10 > 3 )
            penv->fhitend = true;
          if ( penv->fexp )
            v13 = (v12 * ((pbufferb * v12) >> 14)) >> 14;
          else
            v13 = (pbufferb * v12) >> 14;
        }
        v4 = counta;
        v5->right = v13;
        v5->left = v13;
        ++v5;
      }
      while ( counta != 0 );
    }
  }
  else if ( SampleCount != 0 )
  {
    do
    {
      pbuffera = v5->left;
      count = v4 - 1;
      if ( penv->fhitend )
      {
        v9 = 0;
      }
      else
      {
        v6 = penv->ienv;
        v7 = &penv->fused + 44 * v6;
        v8 = RMP_GetNext(prmp: (rmp_t *)(v7 + 8));
        if ( v7[28] )
          ++v6;
        penv->ienv = v6;
        if ( v6 > 3 )
          penv->fhitend = true;
        if ( penv->fexp )
          v9 = (v8 * ((pbuffera * v8) >> 14)) >> 14;
        else
          v9 = (pbuffera * v8) >> 14;
      }
      v4 = count;
      v5->left = v9;
      ++v5;
    }
    while ( count != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10022200
// Name: struct env_t __near * ENV_Params(struct prc_t __near *)
// Source: json
//------------------------------------------------------------------------------
env_t *__cdecl ENV_Params(prc_t *pprc)
{
  float v2; // [esp-14h] [ebp-20h]
  float v3; // [esp-10h] [ebp-1Ch]
  float v4; // [esp-Ch] [ebp-18h]
  float v5; // [esp-8h] [ebp-14h]

  v5 = 0.001 * pprc->prm[7];
  v4 = pprc->prm[6] * 0.001;
  v3 = pprc->prm[5] * 0.001;
  v2 = pprc->prm[4] * 0.001;
  return ENV_Alloc(
           type: (int)pprc->prm[0],
           famp1: pprc->prm[1],
           famp2: pprc->prm[2],
           famp3: pprc->prm[3],
           attack: v2,
           decay: v3,
           sustain: v4,
           release: v5,
           fexp: pprc->prm[8] > 0.0);
}

//------------------------------------------------------------------------------
// Address: 0x100222A0
// Name: void EFO_Free(struct efo_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl EFO_Free(efo_t *pefo)
{
  if ( pefo != nullptr )
    _V_memset(dest: pefo, fill: 0, count: 116);
}

//------------------------------------------------------------------------------
// Address: 0x100222C0
// Name: struct efo_t __near * EFO_Alloc(float,float,float,bool)
// Source: json
//------------------------------------------------------------------------------
efo_t *__cdecl EFO_Alloc(float threshold, float attack_sec, float decay_sec, bool bexp)
{
  int v4; // esi
  efo_t *v5; // eax
  efo_t *v7; // esi
  float v8; // xmm0_4

  v4 = 0;
  v5 = efos;
  while ( v5->fused )
  {
    ++v5;
    ++v4;
    if ( (int)v5 >= (int)envs )
    {
      DevMsg(a1: "DSP: Warning, failed to allocate envelope follower.\n");
      return nullptr;
    }
  }
  v7 = &efos[v4];
  if ( v7 != nullptr )
    _V_memset(dest: v7, fill: 0, count: 116);
  v7->xout = 0;
  v7->fused = true;
  v7->bgate = threshold > 0.0;
  if ( threshold > 0.0 )
  {
    v7->attack_time = attack_sec;
    v7->decay_time = decay_sec;
    RMP_Init(prmp: &v7->rmp_attack, ramptime: attack_sec, initval: 0, targetval: 4096, bEndAtTime: false);
    RMP_Init(prmp: &v7->rmp_decay, ramptime: decay_sec, initval: 4096, targetval: 0, bEndAtTime: false);
    v8 = threshold - 1000.0;
    v7->rmp_attack.fhitend = true;
    v7->rmp_decay.fhitend = true;
    v7->thresh = (int)threshold;
    if ( (float)(threshold - 1000.0) < 1.0 )
      v8 = 1.0;
    v7->thresh_off = (int)v8;
    v7->bgateon = false;
    v7->bexp = bexp;
  }
  return v7;
}

//------------------------------------------------------------------------------
// Address: 0x100223D0
// Name: int EFO_GetNext(struct efo_t __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl EFO_GetNext(efo_t *pefo, int x)
{
  unsigned int v2; // eax
  int result; // eax
  bool v4; // zf
  bool bgateon; // cl
  int Next; // edi
  double attack_time; // st7
  int v8; // edi
  int v9; // ecx
  float v10; // [esp-14h] [ebp-1Ch]
  float decay_time; // [esp-14h] [ebp-1Ch]

  v2 = abs32(x);
  result = ((int)(2047 * (pefo->xout - v2)) >> 11) + v2;
  v4 = !pefo->bgate;
  pefo->xout = result;
  if ( !v4 )
  {
    bgateon = pefo->bgateon;
    if ( bgateon )
      pefo->bgateon = result >= pefo->thresh_off;
    else
      pefo->bgateon = result >= pefo->thresh;
    if ( pefo->bgateon )
    {
      if ( bgateon )
      {
        if ( pefo->rmp_attack.fhitend )
          return x;
        else
          return (x * RMP_GetNext(prmp: &pefo->rmp_attack)) >> 12;
      }
      else
      {
        if ( pefo->rmp_decay.fhitend )
          Next = 0;
        else
          Next = RMP_GetNext(prmp: &pefo->rmp_decay);
        attack_time = pefo->attack_time;
        pefo->rmp_decay.fhitend = true;
        v10 = attack_time;
        RMP_Init(prmp: &pefo->rmp_attack, ramptime: v10, initval: Next, targetval: 4096, bEndAtTime: false);
        return (x * Next) >> 12;
      }
    }
    else if ( bgateon )
    {
      if ( pefo->rmp_attack.fhitend )
        v8 = 4096;
      else
        v8 = RMP_GetNext(prmp: &pefo->rmp_attack);
      decay_time = pefo->decay_time;
      pefo->rmp_attack.fhitend = true;
      RMP_Init(prmp: &pefo->rmp_decay, ramptime: decay_time, initval: v8, targetval: 0, bEndAtTime: false);
      result = (x * v8) >> 12;
      if ( pefo->bexp )
        return (v8 * result) >> 12;
    }
    else if ( pefo->rmp_decay.fhitend )
    {
      return 0;
    }
    else
    {
      v9 = RMP_GetNext(prmp: &pefo->rmp_decay);
      result = (x * v9) >> 12;
      if ( pefo->bexp )
        return (v9 * result) >> 12;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10022520
// Name: void EFO_GetNextN(struct efo_t __near *,struct portable_samplepair_t __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl EFO_GetNextN(efo_t *pefo, portable_samplepair_t *pbuffer, int SampleCount, int op)
{
  portable_samplepair_t *v5; // edi
  int left; // ebx
  unsigned int v7; // eax
  int v8; // eax
  bool v9; // zf
  bool bgateon; // cl
  int v11; // edi
  int v12; // eax
  int v13; // eax
  int Next; // eax
  int *p_right; // esi
  float attack_time; // [esp-10h] [ebp-1Ch]
  float decay_time; // [esp-10h] [ebp-1Ch]
  int v18; // [esp+18h] [ebp+Ch]
  portable_samplepair_t *v19; // [esp+1Ch] [ebp+10h]

  v5 = pbuffer;
  v19 = pbuffer;
  if ( op == 1 )
  {
    if ( SampleCount != 0 )
    {
      p_right = &pbuffer->right;
      do
      {
        *p_right = EFO_GetNext(pefo, x: *p_right);
        p_right += 2;
        --SampleCount;
      }
      while ( SampleCount != 0 );
    }
  }
  else if ( op == 2 )
  {
    for ( ; SampleCount != 0; --SampleCount )
    {
      Next = EFO_GetNext(pefo, x: v5->left);
      v5->right = Next;
      v5->left = Next;
      ++v5;
    }
  }
  else if ( SampleCount != 0 )
  {
    while ( 1 )
    {
      v18 = SampleCount - 1;
      left = v5->left;
      v7 = abs32(v5->left);
      v8 = ((int)(2047 * (pefo->xout - v7)) >> 11) + v7;
      v9 = !pefo->bgate;
      pefo->xout = v8;
      if ( v9 )
        goto LABEL_31;
      bgateon = pefo->bgateon;
      if ( bgateon )
        pefo->bgateon = v8 >= pefo->thresh_off;
      else
        pefo->bgateon = v8 >= pefo->thresh;
      if ( pefo->bgateon )
      {
        if ( !bgateon )
        {
          if ( pefo->rmp_decay.fhitend )
            v11 = 0;
          else
            v11 = RMP_GetNext(prmp: &pefo->rmp_decay);
          attack_time = pefo->attack_time;
          pefo->rmp_decay.fhitend = true;
          RMP_Init(prmp: &pefo->rmp_attack, ramptime: attack_time, initval: v11, targetval: 4096, bEndAtTime: false);
LABEL_18:
          v8 = (left * v11) >> 12;
          v5 = v19;
          goto LABEL_31;
        }
        if ( pefo->rmp_attack.fhitend )
          v8 = left;
        else
          v8 = (left * RMP_GetNext(prmp: &pefo->rmp_attack)) >> 12;
      }
      else if ( bgateon )
      {
        if ( pefo->rmp_attack.fhitend )
          v11 = 4096;
        else
          v11 = RMP_GetNext(prmp: &pefo->rmp_attack);
        decay_time = pefo->decay_time;
        pefo->rmp_attack.fhitend = true;
        RMP_Init(prmp: &pefo->rmp_decay, ramptime: decay_time, initval: v11, targetval: 0, bEndAtTime: false);
        if ( !pefo->bexp )
          goto LABEL_18;
        v12 = v11 * ((left * v11) >> 12);
        v5 = v19;
        v8 = v12 >> 12;
      }
      else if ( pefo->rmp_decay.fhitend )
      {
        v8 = 0;
      }
      else
      {
        v13 = RMP_GetNext(prmp: &pefo->rmp_decay);
        if ( pefo->bexp )
          v8 = (v13 * ((left * v13) >> 12)) >> 12;
        else
          v8 = (left * v13) >> 12;
      }
LABEL_31:
      v5->left = v8;
      v19 = ++v5;
      if ( v18 == 0 )
        return;
      SampleCount = v18;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10022700
// Name: struct efo_t __near * EFO_Params(struct prc_t __near *)
// Source: json
//------------------------------------------------------------------------------
efo_t *__cdecl EFO_Params(prc_t *pprc)
{
  double v1; // st7
  float v3; // [esp-Ch] [ebp-10h]
  float v4; // [esp-8h] [ebp-Ch]
  float v5; // [esp-4h] [ebp-8h]
  float v6; // [esp-4h] [ebp-8h]

  v5 = dB_To_Gain(dB: pprc->prm[0]);
  v1 = Gain_To_Amplitude(gain: v5);
  if ( pprc->prm[0] == 0.0 )
    v1 = 0.0;
  v6 = 0.001 * pprc->prm[2];
  v4 = pprc->prm[1] * 0.001;
  v3 = v1;
  return EFO_Alloc(threshold: v3, attack_sec: v4, decay_sec: v6, bexp: pprc->prm[3] > 0.0);
}

//------------------------------------------------------------------------------
// Address: 0x10022780
// Name: void CRS_Free(struct crs_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CRS_Free(crs_t *pcrs)
{
  mdy_t *pmdy; // edi
  dly_t *pdly; // esi
  lfo_t *plfo; // eax

  if ( pcrs != nullptr )
  {
    pmdy = pcrs->pmdy;
    if ( pmdy != nullptr )
    {
      pdly = pmdy->pdly;
      if ( pdly != nullptr )
      {
        FLT_Free(pf: pdly->pflt);
        if ( pdly->w != nullptr )
          free(pMem: pdly->w);
        _V_memset(dest: pdly, fill: 0, count: 72);
      }
      _V_memset(dest: pmdy, fill: 0, count: 76);
    }
    plfo = pcrs->plfo;
    if ( plfo != nullptr )
      _V_memset(dest: plfo, fill: 0, count: 56);
    _V_memset(dest: pcrs, fill: 0, count: 16);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10022800
// Name: void CRS_FreeAll(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CRS_FreeAll()
{
  crs_t *v0; // ebx
  mdy_t *pmdy; // edi
  dly_t *pdly; // esi
  lfo_t *plfo; // eax

  v0 = crss;
  do
  {
    if ( v0 != nullptr )
    {
      pmdy = v0->pmdy;
      if ( pmdy != nullptr )
      {
        pdly = pmdy->pdly;
        if ( pdly != nullptr )
        {
          FLT_Free(pf: pdly->pflt);
          if ( pdly->w != nullptr )
            free(pMem: pdly->w);
          _V_memset(dest: pdly, fill: 0, count: 72);
        }
        _V_memset(dest: pmdy, fill: 0, count: 76);
      }
      plfo = v0->plfo;
      if ( plfo != nullptr )
        _V_memset(dest: plfo, fill: 0, count: 56);
      _V_memset(dest: v0, fill: 0, count: 16);
    }
    ++v0;
  }
  while ( (int)v0 < (int)efos );
}

//------------------------------------------------------------------------------
// Address: 0x10022880
// Name: int CRS_GetNext(struct crs_t __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl CRS_GetNext(crs_t *pcrs, int x)
{
  int Next; // esi
  int v4; // eax
  int v5; // edi
  mdy_t *pmdy; // esi
  dly_t *pdly; // edx
  float ramptime; // [esp+0h] [ebp-20h]
  int v10; // [esp+1Ch] [ebp-4h]
  int D0; // [esp+28h] [ebp+8h]

  Next = MDY_GetNext(pmdy: pcrs->pmdy, x);
  v10 = Next;
  v4 = LFO_GetNext(plfo: pcrs->plfo);
  v5 = v4;
  if ( v4 == pcrs->lfoprev )
    return Next;
  pmdy = pcrs->pmdy;
  pdly = pmdy->pdly;
  if ( v4 < 0 )
    v5 = 0;
  D0 = pdly->D0 - ((v5 * pdly->D0) >> 14);
  if ( pdly->D0 < D0 )
    D0 = pdly->D0;
  ramptime = pmdy->ramptime;
  pmdy->fchanging = true;
  RMP_Init(prmp: &pmdy->rmp_interp, ramptime, initval: 0, targetval: 4096, bEndAtTime: false);
  pmdy->pdly->tnew = D0;
  pmdy->pdly->xf = 0;
  pcrs->lfoprev = v5;
  return v10;
}

//------------------------------------------------------------------------------
// Address: 0x10022920
// Name: void CRS_GetNextN(struct crs_t __near *,struct portable_samplepair_t __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CRS_GetNextN(crs_t *pcrs, portable_samplepair_t *pbuffer, int SampleCount, int op)
{
  int v4; // esi
  portable_samplepair_t *v5; // edi
  int v6; // ebx
  mdy_t *pmdy; // esi
  dly_t *pdly; // ecx
  int D0; // eax
  int v10; // ecx
  dly_t *v11; // edx
  int Next; // eax
  int *p_right; // edi
  float ramptime; // [esp-10h] [ebp-1Ch]
  int v15; // [esp+18h] [ebp+Ch]
  int v16; // [esp+1Ch] [ebp+10h]
  int v17; // [esp+20h] [ebp+14h]

  v4 = SampleCount;
  v5 = pbuffer;
  if ( op == 1 )
  {
    if ( SampleCount != 0 )
    {
      p_right = &pbuffer->right;
      do
      {
        *p_right = CRS_GetNext(pcrs, x: *p_right);
        p_right += 2;
        --v4;
      }
      while ( v4 != 0 );
    }
  }
  else if ( op == 2 )
  {
    if ( SampleCount != 0 )
    {
      do
      {
        Next = CRS_GetNext(pcrs, x: v5->left);
        v5->right = Next;
        v5->left = Next;
        ++v5;
        --v4;
      }
      while ( v4 != 0 );
    }
  }
  else if ( SampleCount != 0 )
  {
    do
    {
      v15 = --v4;
      v17 = MDY_GetNext(pmdy: pcrs->pmdy, x: v5->left);
      v6 = LFO_GetNext(plfo: pcrs->plfo);
      if ( v6 != pcrs->lfoprev )
      {
        pmdy = pcrs->pmdy;
        pdly = pmdy->pdly;
        D0 = pdly->D0;
        if ( v6 < 0 )
          v6 = 0;
        v10 = pdly->D0;
        v16 = D0 - ((v6 * D0) >> 14);
        if ( v10 < v16 )
          v16 = v10;
        ramptime = pmdy->ramptime;
        pmdy->fchanging = true;
        RMP_Init(prmp: &pmdy->rmp_interp, ramptime, initval: 0, targetval: 4096, bEndAtTime: false);
        pmdy->pdly->tnew = v16;
        v11 = pmdy->pdly;
        v4 = v15;
        v11->xf = 0;
        pcrs->lfoprev = v6;
      }
      v5->left = v17;
      ++v5;
    }
    while ( v4 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10022A40
// Name: void AMP_Free(struct amp_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl AMP_Free(amp_t *pamp)
{
  if ( pamp != nullptr )
    _V_memset(dest: pamp, fill: 0, count: 92);
}

//------------------------------------------------------------------------------
// Address: 0x10022A60
// Name: struct amp_t __near * AMP_Alloc(float,float,float,float,float,float,float,bool)
// Source: json
//------------------------------------------------------------------------------
amp_t *__cdecl AMP_Alloc(
        float gain,
        float vthresh,
        float distmix,
        float vfeed,
        float ramptime,
        float modtime,
        float depth,
        bool brand)
{
  int v8; // esi
  amp_t *v9; // eax
  amp_t *v11; // esi
  int v12; // eax
  int v13; // eax

  v8 = 0;
  v9 = &amps[1];
  while ( v9[-1].fused )
  {
    if ( !v9->fused )
    {
      ++v8;
      break;
    }
    if ( !v9[1].fused )
    {
      v8 += 2;
      break;
    }
    if ( !v9[2].fused )
    {
      v8 += 3;
      break;
    }
    v9 += 4;
    v8 += 4;
    if ( (int)v9 >= (int)&crss[5].lfoprev )
      break;
  }
  if ( v8 == 64 )
  {
    DevMsg(a1: "DSP: Warning, failed to allocate amp.\n");
    return nullptr;
  }
  else
  {
    v11 = &amps[v8];
    if ( v11 != nullptr )
      _V_memset(dest: v11, fill: 0, count: 92);
    v12 = (int)(float)(gain * 4096.0);
    v11->gain = v12;
    v11->gain_max = v12;
    v11->fused = true;
    v11->distmix = (int)(float)(distmix * 4096.0);
    v11->vfeed = (int)(float)(vfeed * 4096.0);
    v11->ramptime = ramptime;
    v11->vthresh = (int)(vthresh * 32767.0);
    v13 = (int)(float)(modtime * 44100.0);
    v11->mtime = v13;
    v11->mtimecur = v13;
    v11->brand = brand;
    v11->depth = (int)(float)(depth * 4096.0);
    return v11;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10022B70
// Name: int AMP_GetNext(struct amp_t __near *,int)
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
int __cdecl AMP_GetNext(amp_t *pamp, int x)
{
  int v2; // ecx
  int vthresh; // eax
  int distmix; // edx
  int v5; // edi
  int Next; // eax
  bool v7; // zf
  int mtime; // eax
  int mtimecur; // ecx
  int gain_max; // ecx
  int v11; // edx
  int v12; // edx
  int v13; // eax
  int v14; // edx
  double ramptime; // st7
  float v17; // [esp-8h] [ebp-18h]
  int gain; // [esp-4h] [ebp-14h]

  v2 = x;
  vthresh = pamp->vthresh;
  if ( vthresh < 4096 )
  {
    distmix = pamp->distmix;
    if ( distmix != 0 )
    {
      if ( x <= vthresh )
      {
        vthresh = -vthresh;
        if ( x >= vthresh )
          vthresh = x;
      }
      if ( distmix < 4096 )
        vthresh = x + ((distmix * (vthresh - x)) >> 12);
      v2 = vthresh;
    }
  }
  v5 = (v2 * pamp->gain) >> 12;
  if ( pamp->fchanging )
  {
    Next = RMP_GetNext(prmp: &pamp->rmp_interp);
    v7 = !pamp->rmp_interp.fhitend;
    pamp->gain = Next;
    if ( !v7 )
      pamp->fchanging = false;
  }
  else if ( pamp->mtime == 0 )
  {
    return v5;
  }
  mtime = pamp->mtime;
  if ( mtime != 0 )
  {
    mtimecur = pamp->mtimecur;
    pamp->mtimecur = mtimecur - 1;
    if ( mtimecur == 0 )
    {
      gain_max = pamp->gain_max;
      v11 = gain_max * pamp->depth;
      pamp->mtimecur = mtime;
      v12 = v11 >> 12;
      v13 = gain_max - v12;
      if ( pamp->brand )
      {
        v14 = gain_max - v12;
        if ( v13 > gain_max || (v14 = gain_max, v13 >= gain_max) )
          v13 = gain_max;
        v13 = _RandomInt(this: (IUniformRandomStream *)gain_max, a2: v13, a3: v14);
      }
      else if ( pamp->gain == v13 )
      {
        v13 = gain_max;
      }
      ramptime = pamp->ramptime;
      gain = pamp->gain;
      pamp->fchanging = true;
      v17 = ramptime;
      RMP_Init(prmp: &pamp->rmp_interp, ramptime: v17, initval: gain, targetval: v13, bEndAtTime: false);
    }
  }
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x10022C60
// Name: void AMP_GetNextN(struct amp_t __near *,struct portable_samplepair_t __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __cdecl AMP_GetNextN(amp_t *pamp, portable_samplepair_t *pbuffer, int SampleCount, int op)
{
  int v4; // ebx
  portable_samplepair_t *v5; // edi
  int vthresh; // eax
  int left; // ecx
  int distmix; // edx
  int v9; // ebx
  int v10; // eax
  bool v11; // zf
  int mtime; // eax
  int mtimecur; // ecx
  int gain_max; // ecx
  int v15; // edx
  int v16; // edx
  int v17; // eax
  int v18; // edx
  int Next; // eax
  int *p_right; // esi
  float ramptime; // [esp-8h] [ebp-1Ch]
  int gain; // [esp-4h] [ebp-18h]
  int v23; // [esp+24h] [ebp+10h]

  v4 = SampleCount;
  v5 = pbuffer;
  if ( op == 1 )
  {
    if ( SampleCount != 0 )
    {
      p_right = &pbuffer->right;
      do
      {
        *p_right = AMP_GetNext(pamp, x: *p_right);
        p_right += 2;
        --v4;
      }
      while ( v4 != 0 );
    }
  }
  else if ( op == 2 )
  {
    if ( SampleCount != 0 )
    {
      do
      {
        Next = AMP_GetNext(pamp, x: v5->left);
        v5->right = Next;
        v5->left = Next;
        ++v5;
        --v4;
      }
      while ( v4 != 0 );
    }
  }
  else if ( SampleCount != 0 )
  {
    while ( 1 )
    {
      vthresh = pamp->vthresh;
      left = v5->left;
      v23 = v4 - 1;
      if ( vthresh < 4096 )
      {
        distmix = pamp->distmix;
        if ( distmix != 0 )
        {
          if ( left <= vthresh )
          {
            vthresh = -vthresh;
            if ( left >= vthresh )
              vthresh = v5->left;
          }
          if ( distmix >= 4096 )
            left = vthresh;
          else
            left += (distmix * (vthresh - left)) >> 12;
        }
      }
      v9 = (left * pamp->gain) >> 12;
      if ( pamp->fchanging )
      {
        v10 = RMP_GetNext(prmp: &pamp->rmp_interp);
        v11 = !pamp->rmp_interp.fhitend;
        pamp->gain = v10;
        if ( !v11 )
          pamp->fchanging = false;
      }
      else if ( pamp->mtime == 0 )
      {
        goto LABEL_29;
      }
      mtime = pamp->mtime;
      if ( mtime != 0 )
      {
        mtimecur = pamp->mtimecur;
        pamp->mtimecur = mtimecur - 1;
        if ( mtimecur == 0 )
        {
          gain_max = pamp->gain_max;
          v15 = gain_max * pamp->depth;
          pamp->mtimecur = mtime;
          v16 = v15 >> 12;
          v17 = gain_max - v16;
          if ( pamp->brand )
          {
            v18 = gain_max - v16;
            if ( v17 > gain_max || (v18 = gain_max, v17 >= gain_max) )
              v17 = gain_max;
            v17 = _RandomInt(this: (IUniformRandomStream *)gain_max, a2: v17, a3: v18);
          }
          else if ( pamp->gain == v17 )
          {
            v17 = gain_max;
          }
          gain = pamp->gain;
          ramptime = pamp->ramptime;
          pamp->fchanging = true;
          RMP_Init(prmp: &pamp->rmp_interp, ramptime, initval: gain, targetval: v17, bEndAtTime: false);
        }
      }
LABEL_29:
      v5->left = v9;
      ++v5;
      if ( v23 == 0 )
        return;
      v4 = v23;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10022DD0
// Name: struct amp_t __near * AMP_Params(struct prc_t __near *)
// Source: json
//------------------------------------------------------------------------------
amp_t *__cdecl AMP_Params(prc_t *pprc)
{
  float v2; // xmm2_4
  double v3; // st7
  double v4; // st6
  double v5; // st6
  float v7; // [esp-10h] [ebp-1Ch]
  float v8; // [esp-Ch] [ebp-18h]
  float distmix; // [esp+8h] [ebp-4h]
  float v10; // [esp+14h] [ebp+8h]

  v2 = pprc->prm[7];
  distmix = 0.0;
  v10 = pprc->prm[4];
  if ( v10 <= 0.0 )
  {
    v3 = 0.0;
    v5 = 0.0;
  }
  else
  {
    v3 = pprc->prm[6] * 0.001;
    v4 = 0.01;
    if ( v10 > 0.01 )
      v4 = v10;
    distmix = pprc->prm[5];
    v5 = 1.0 / v4;
  }
  v8 = v5;
  v7 = v3;
  return AMP_Alloc(
           gain: pprc->prm[0],
           vthresh: pprc->prm[1],
           distmix: pprc->prm[2],
           vfeed: pprc->prm[3],
           ramptime: v7,
           modtime: v8,
           depth: distmix,
           brand: v2 > 0.0);
}

//------------------------------------------------------------------------------
// Address: 0x10022E90
// Name: int NULL_GetNext(void __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl NULL_GetNext(void *p, int x)
{
  return x;
}

//------------------------------------------------------------------------------
// Address: 0x10022EA0
// Name: void __near * NULL_VParams(void __near *)
// Source: json
//------------------------------------------------------------------------------
nul_t *__cdecl NULL_VParams()
{
  return nuls;
}

//------------------------------------------------------------------------------
// Address: 0x10022EB0
// Name: void PRC_FreeAll(struct prc_t __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl PRC_FreeAll(prc_t *prcs, int count)
{
  void **p_pdata; // esi
  int i; // edi
  void (__cdecl *v4)(void *); // ecx

  if ( count > 0 )
  {
    p_pdata = &prcs->pdata;
    for ( i = count; i != 0; --i )
    {
      v4 = (void (__cdecl *)(void *))*(p_pdata - 2);
      if ( v4 != nullptr && *p_pdata != nullptr )
        v4(a1: *p_pdata);
      p_pdata += 23;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10022EF0
// Name: void PRC_Print(struct prc_t const __near &,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl PRC_Print(const prc_t *prc, int nIndentation)
{
  char *IndentationText; // edi
  int type; // eax
  float *prm; // edi
  const char *v6; // [esp+14h] [ebp-8h]
  int i; // [esp+18h] [ebp-4h]
  const char *v8; // [esp+24h] [ebp+8h]

  IndentationText = GetIndentationText(nIndentation);
  v6 = IndentationText;
  DevMsg(a1: "%sPRC: %08X [Addr]\n", IndentationText, prc);
  type = prc->type;
  v8 = "Unknown";
  switch ( type )
  {
    case 0:
      v8 = "NULL";
      break;
    case 1:
      v8 = "DLY - Simple feedback reverb";
      break;
    case 2:
      v8 = "RVA - Parallel reverbs";
      break;
    case 3:
      v8 = "FLT - Lowpass or highpass filter";
      break;
    case 4:
      v8 = "CRS - Chorus";
      break;
    case 5:
      v8 = "PTC - Pitch shifter";
      break;
    case 6:
      v8 = "ENV - Adsr envelope";
      break;
    case 7:
      v8 = "LFO";
      break;
    case 8:
      v8 = "EFO - Envelope follower";
      break;
    case 9:
      v8 = "MDY - Mod delay";
      break;
    case 10:
      v8 = "DFR - Diffusor - n series allpass delays";
      break;
    case 11:
      v8 = "AMP - Amplifier with distortion";
      break;
    default:
      break;
  }
  DevMsg(a1: "%sprm: ", IndentationText);
  prm = prc->prm;
  for ( i = 16; i != 0; --i )
    DevMsg(a1: "%f ", *prm++);
  DevMsg(a1: "\n");
  DevMsg(a1: "%sType: %s -", v6, v8);
  switch ( prc->type )
  {
    case 1:
      DLY_Print(delay: (const dly_t *)prc->pdata, nIndentation: nIndentation + 1);
      break;
    case 2:
      RVA_Print(rva: (const rva_t *)prc->pdata, nIndentation: nIndentation + 1);
      break;
    case 3:
      FLT_Print(filter: (const flt_t *)prc->pdata, nIndentation: nIndentation + 1);
      break;
    case 4:
      DevMsg(a1: "CRS_Print is not implemented\n");
      break;
    case 5:
      DevMsg(a1: "PTC_Print is not implemented\n");
      break;
    case 6:
      DevMsg(a1: "ENV_Print is not implemented\n");
      break;
    case 7:
      DevMsg(a1: "LFO_Print is not implemented\n");
      break;
    case 8:
      DevMsg(a1: "EFO_Print is not implemented\n");
      break;
    case 9:
      MDY_Print(modDelay: (const mdy_t *)prc->pdata, nIndentation: nIndentation + 1);
      break;
    case 0xA:
      DFR_Print(dfr: (const dfr_t *)prc->pdata, nIndentation: nIndentation + 1);
      break;
    case 0xB:
      DevMsg(a1: "AMP_Print is not implemented\n");
      break;
    default:
      return;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10023130
// Name: void PSET_UpdateDuration(struct pset_t __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl PSET_UpdateDuration(pset_t *ppset, int SampleCount)
{
  int csamp_duration; // eax

  if ( ppset != nullptr && ppset->duration > 0.0 )
  {
    csamp_duration = ppset->csamp_duration;
    if ( csamp_duration > 0 )
      ppset->csamp_duration = csamp_duration - SampleCount;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10023160
// Name: void PSET_Print(struct pset_t const __near &,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl PSET_Print(const pset_t *pset, int nIndentation)
{
  char *IndentationText; // ebx
  int v4; // [esp+10h] [ebp-4h]
  int i; // [esp+10h] [ebp-4h]
  prc_t *prcs; // [esp+1Ch] [ebp+8h]
  int *w; // [esp+1Ch] [ebp+8h]

  IndentationText = GetIndentationText(nIndentation);
  DevMsg(a1: "%sPSET: %08x [Addr]\n", IndentationText, pset);
  DevMsg(a1: "%sType: %d\n", IndentationText, pset->type);
  DevMsg(a1: "%scprcs: %d\n", IndentationText, pset->cprcs);
  v4 = 0;
  if ( pset->cprcs > 0 )
  {
    prcs = pset->prcs;
    do
    {
      PRC_Print(prc: prcs++, nIndentation: nIndentation + 1);
      ++v4;
    }
    while ( v4 < pset->cprcs );
  }
  DevMsg(a1: "%smix_min: %f\n", IndentationText, pset->mix_min);
  DevMsg(a1: "%smix_max: %f\n", IndentationText, pset->mix_max);
  DevMsg(a1: "%sdb_min: %f\n", IndentationText, pset->db_min);
  DevMsg(a1: "%sdb_mixdrop: %f\n", IndentationText, pset->db_mixdrop);
  DevMsg(a1: "%sduration: %f\n", IndentationText, pset->duration);
  DevMsg(a1: "%sfade: %f\n", IndentationText, pset->fade);
  DevMsg(a1: "%scsamp_duration: %d\n", IndentationText, pset->csamp_duration);
  DevMsg(a1: "%sw: ", IndentationText);
  w = pset->w;
  for ( i = 8; i != 0; --i )
    DevMsg(a1: "%d ", *w++);
  DevMsg(a1: "\n");
  DevMsg(a1: "%sfused: %d\n", IndentationText, pset->fused);
}

//------------------------------------------------------------------------------
// Address: 0x100232C0
// Name: void PSET_GetNextN(struct pset_t __near *,struct portable_samplepair_t __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl PSET_GetNextN(pset_t *ppset, portable_samplepair_t *pbuffer, int SampleCount, int op)
{
  int cprcs; // edi
  void **p_pdata; // esi

  cprcs = ppset->cprcs;
  if ( ppset->type == 1 )
  {
    if ( cprcs > 0 )
    {
      p_pdata = &ppset->prcs[0].pdata;
      do
      {
        ((void (__cdecl *)(void *, portable_samplepair_t *, int, int))*(p_pdata - 3))(
          a1: *p_pdata,
          a2: pbuffer,
          a3: SampleCount,
          a4: op);
        p_pdata += 23;
        --cprcs;
      }
      while ( cprcs != 0 );
    }
  }
  else
  {
    ppset->prcs[0].pfnGetNextN(a1: ppset->prcs[0].pdata, a2: pbuffer, a3: SampleCount, a4: op);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10023320
// Name: int PSET_GetNext(struct pset_t __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl PSET_GetNext(pset_t *ppset, int x)
{
  int result; // eax
  int v3; // eax
  prc_t *prcs; // edi
  int v5; // edx
  int v6; // eax
  int v7; // edx
  int v8; // eax
  int v9; // edx
  int v10; // eax
  int v11; // edx
  int v12; // eax
  int v13; // ecx
  int v14; // eax
  int v15; // ecx
  int v16; // eax
  int v17; // ecx
  int v18; // eax
  int v19; // ecx
  int v20; // eax
  int v21; // ecx
  int v22; // edx
  int v23; // eax
  int v24; // edx
  int v25; // eax
  int v26; // edx
  int v27; // eax
  int v28; // eax
  __m128i v29; // xmm0
  int v30; // eax
  int v31; // edx
  int v32; // eax
  int v33; // ecx
  int v34; // eax
  __m128i v35; // xmm0
  int v36; // eax
  int v37; // ecx

  if ( ppset->type == 0 )
    return ppset->prcs[0].pfnGetNext(a1: ppset->prcs[0].pdata, a2: x);
  v3 = x;
  if ( ppset->type == 1 )
  {
    prcs = ppset->prcs;
    switch ( ppset->cprcs )
    {
      case 0:
      case 1:
        goto $LN12_3;
      case 2:
        goto $LN13;
      case 3:
        goto $LN14_2;
      case 4:
        goto $LN15_2;
      default:
        v3 = ppset->prcs[0].pfnGetNext(a1: ppset->prcs[0].pdata, a2: x);
        prcs = &ppset->prcs[1];
$LN15_2:
        v3 = prcs->pfnGetNext(a1: prcs->pdata, a2: v3);
        ++prcs;
$LN14_2:
        v3 = prcs->pfnGetNext(a1: prcs->pdata, a2: v3);
        ++prcs;
$LN13:
        v3 = prcs->pfnGetNext(a1: prcs->pdata, a2: v3);
        ++prcs;
$LN12_3:
        result = prcs->pfnGetNext(a1: prcs->pdata, a2: v3);
        break;
    }
  }
  else
  {
    ppset->w[0] = x;
    switch ( ppset->type )
    {
      case 6:
        v5 = ppset->w[1];
        ppset->w[5] = ppset->w[4] + ppset->w[2];
        v6 = ppset->prcs[1].pfnGetNext(a1: ppset->prcs[1].pdata, a2: v5);
        v7 = ppset->w[3];
        ppset->w[2] = v6;
        v8 = ppset->prcs[3].pfnGetNext(a1: ppset->prcs[3].pdata, a2: v7);
        v9 = ppset->w[0];
        ppset->w[4] = v8;
        v10 = ppset->prcs[0].pfnGetNext(a1: ppset->prcs[0].pdata, a2: v9);
        v11 = ppset->w[0];
        ppset->w[1] = v10;
        ppset->w[3] = ppset->prcs[2].pfnGetNext(a1: ppset->prcs[2].pdata, a2: v11);
        result = ppset->w[5];
        break;
      case 7:
        v12 = ppset->w[1];
        ppset->w[5] = ppset->w[4] + ppset->w[2];
        ppset->w[2] = ppset->prcs[1].pfnGetNext(a1: ppset->prcs[1].pdata, a2: v12);
        ppset->w[4] = ppset->prcs[3].pfnGetNext(a1: ppset->prcs[3].pdata, a2: ppset->w[3]);
        ppset->w[1] = ppset->prcs[0].pfnGetNext(a1: ppset->prcs[0].pdata, a2: ppset->w[0]);
        ppset->w[3] = ppset->prcs[2].pfnGetNext(a1: ppset->prcs[2].pdata, a2: ppset->w[0]);
        result = ppset->prcs[4].pfnGetNext(a1: ppset->prcs[4].pdata, a2: ppset->w[5]);
        break;
      case 8:
        v13 = ppset->w[5];
        ppset->w[2] = ppset->w[1] + ppset->w[6];
        v14 = ppset->prcs[4].pfnGetNext(a1: ppset->prcs[4].pdata, a2: v13);
        v15 = ppset->w[4];
        ppset->w[6] = v14;
        v16 = ppset->prcs[3].pfnGetNext(a1: ppset->prcs[3].pdata, a2: v15);
        v17 = ppset->w[3];
        ppset->w[5] = v16;
        v18 = ppset->prcs[2].pfnGetNext(a1: ppset->prcs[2].pdata, a2: v17);
        v19 = ppset->w[2];
        ppset->w[4] = v18;
        v20 = ppset->prcs[1].pfnGetNext(a1: ppset->prcs[1].pdata, a2: v19);
        v21 = ppset->w[0];
        ppset->w[3] = v20;
        ppset->w[1] = ppset->prcs[0].pfnGetNext(a1: ppset->prcs[0].pdata, a2: v21);
        result = ppset->w[4];
        break;
      case 9:
        v22 = ppset->w[3];
        ppset->w[1] = x + ppset->w[4];
        v23 = ppset->prcs[2].pfnGetNext(a1: ppset->prcs[2].pdata, a2: v22);
        v24 = ppset->w[2];
        ppset->w[4] = v23;
        v25 = ppset->prcs[1].pfnGetNext(a1: ppset->prcs[1].pdata, a2: v24);
        v26 = ppset->w[1];
        ppset->w[3] = v25;
        result = ppset->prcs[0].pfnGetNext(a1: ppset->prcs[0].pdata, a2: v26);
        ppset->w[2] = result;
        break;
      case 0xA:
        v27 = ppset->w[2];
        ppset->w[1] = x + ppset->w[4];
        ppset->w[5] = ppset->prcs[3].pfnGetNext(a1: ppset->prcs[3].pdata, a2: v27);
        ppset->w[4] = ppset->prcs[2].pfnGetNext(a1: ppset->prcs[2].pdata, a2: ppset->w[3]);
        ppset->w[3] = ppset->prcs[1].pfnGetNext(a1: ppset->prcs[1].pdata, a2: ppset->w[2]);
        result = ppset->prcs[0].pfnGetNext(a1: ppset->prcs[0].pdata, a2: ppset->w[1]);
        ppset->w[2] = result;
        break;
      case 0xB:
        ppset->w[4] = ppset->prcs[3].pfnGetNext(a1: ppset->prcs[3].pdata, a2: ppset->w[3]);
        v28 = ppset->prcs[2].pfnGetNext(a1: ppset->prcs[2].pdata, a2: ppset->w[1]);
        v29 = _mm_cvtsi32_si128(ppset->w[2]);
        ppset->w[3] = v28;
        ((void (__cdecl *)(void *, _DWORD))ppset->prcs[2].pfnMod)(
          a1: ppset->prcs[2].pdata,
          a2: _mm_cvtepi32_ps(v29).m128_f32[0] * 0.00024414062);
        v30 = ppset->prcs[0].pfnGetNext(a1: ppset->prcs[0].pdata, a2: ppset->w[0]);
        v31 = ppset->w[0];
        ppset->w[2] = v30;
        ppset->w[1] = ppset->prcs[1].pfnGetNext(a1: ppset->prcs[1].pdata, a2: v31);
        result = ppset->w[4];
        break;
      case 0xC:
        ((void (__cdecl *)(void *, _DWORD))ppset->prcs[1].pfnMod)(
          a1: ppset->prcs[1].pdata,
          a2: (float)ppset->w[1] * 0.00024414062);
        v32 = ppset->prcs[0].pfnGetNext(a1: ppset->prcs[0].pdata, a2: ppset->w[0]);
        v33 = ppset->w[0];
        ppset->w[1] = v32;
        result = ppset->prcs[1].pfnGetNext(a1: ppset->prcs[1].pdata, a2: v33);
        ppset->w[2] = result;
        break;
      case 0xD:
        v34 = ppset->prcs[2].pfnGetNext(a1: ppset->prcs[2].pdata, a2: ppset->w[2]);
        v35 = _mm_cvtsi32_si128(ppset->w[1]);
        ppset->w[3] = v34;
        ((void (__cdecl *)(void *, _DWORD))ppset->prcs[1].pfnMod)(
          a1: ppset->prcs[1].pdata,
          a2: _mm_cvtepi32_ps(v35).m128_f32[0] * 0.00024414062);
        ppset->w[1] = ppset->prcs[0].pfnGetNext(a1: ppset->prcs[0].pdata, a2: ppset->w[0]);
        result = ppset->prcs[1].pfnGetNext(a1: ppset->prcs[1].pdata, a2: ppset->w[0]);
        ppset->w[2] = result;
        break;
      default:
        ppset->w[3] = ppset->w[1] + ppset->w[2];
        v36 = ppset->prcs[0].pfnGetNext(a1: ppset->prcs[0].pdata, a2: x);
        v37 = ppset->w[0];
        ppset->w[1] = v36;
        ppset->w[2] = ppset->prcs[1].pfnGetNext(a1: ppset->prcs[1].pdata, a2: v37);
        result = ppset->w[3];
        break;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10023870
// Name: void DSP_Free(int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DSP_Free(dsp_t *idsp)
{
  dsp_t *v1; // eax
  int v2; // ebx
  pset_t **ppsetprev; // edi
  int v4; // esi
  pset_t *v5; // esi
  dsp_t *pdsp; // [esp+8h] [ebp+8h]

  if ( (unsigned int)idsp <= 0x1F )
  {
    v1 = &dsps[(_DWORD)idsp];
    v2 = 0;
    pdsp = v1;
    if ( v1->cchan > 0 )
    {
      ppsetprev = v1->ppsetprev;
      do
      {
        v4 = (int)*(ppsetprev - 6);
        if ( v4 != 0 )
        {
          PRC_FreeAll(prcs: (prc_t *)(v4 + 8), count: *(_DWORD *)(v4 + 4));
          _V_memset(dest: (void *)v4, fill: 0, count: 536);
        }
        v5 = *ppsetprev;
        if ( *ppsetprev != nullptr )
        {
          PRC_FreeAll(prcs: v5->prcs, count: v5->cprcs);
          _V_memset(dest: v5, fill: 0, count: 536);
        }
        ++v2;
        ++ppsetprev;
      }
      while ( v2 < pdsp->cchan );
      v1 = pdsp;
    }
    _V_memset(dest: v1, fill: 0, count: 116);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10023900
// Name: _DSP_FreeAll
// Source: json
//------------------------------------------------------------------------------
void DSP_FreeAll()
{
  int i; // esi
  amp_t *v1; // esi
  efo_t *v2; // esi
  env_t *v3; // esi
  lfo_t *v4; // esi

  for ( i = 0; i < 32; ++i )
    DSP_Free(idsp: (dsp_t *)i);
  v1 = amps;
  do
  {
    if ( v1 != nullptr )
      _V_memset(dest: v1, fill: 0, count: 92);
    ++v1;
  }
  while ( (int)v1 < (int)crss );
  MDY_FreeAll();
  v2 = efos;
  do
  {
    if ( v2 != nullptr )
      _V_memset(dest: v2, fill: 0, count: 116);
    ++v2;
  }
  while ( (int)v2 < (int)envs );
  v3 = envs;
  do
  {
    if ( v3 != nullptr )
      _V_memset(dest: v3, fill: 0, count: 184);
    ++v3;
  }
  while ( (int)v3 < (int)ptcs );
  PTC_FreeAll();
  CRS_FreeAll();
  v4 = lfos;
  do
  {
    if ( v4 != nullptr )
      _V_memset(dest: v4, fill: 0, count: 56);
    ++v4;
  }
  while ( (int)v4 < (int)lfowavs );
  LFOWAV_FreeAll();
  RVA_FreeAll();
  DLY_FreeAll();
  FLT_FreeAll();
}

//------------------------------------------------------------------------------
// Address: 0x100239D0
// Name: void DSP_ChangePresetValue(int,int,int,float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DSP_ChangePresetValue(unsigned int idsp, int channel, int iproc, float value)
{
  pset_t *v4; // ecx
  char *v5; // eax
  void (__cdecl *v6)(_DWORD, _DWORD); // ecx

  if ( idsp <= 0x1F && channel < 5 && iproc < 5 )
  {
    v4 = dsps[idsp].ppset[channel];
    if ( v4 != nullptr )
    {
      v5 = (char *)v4 + 92 * iproc;
      v6 = *((void (__cdecl **)(_DWORD, _DWORD))v5 + 23);
      if ( v6 != nullptr )
        v6(a1: *((_DWORD *)v5 + 24), a2: LODWORD(value));
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10023A20
// Name: void DSP_Print(struct dsp_t const __near &,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DSP_Print(const dsp_t *dsp, int nIndentation)
{
  char *IndentationText; // edi
  const char *v3; // eax
  const char *v4; // eax
  const pset_t *v5; // ebx
  int v6; // ebx
  const char *v7; // eax
  int v8; // ecx
  rmp_t *p_xramp; // ebx
  const char *v10; // edi
  pos_one_t *p_ps; // ebx
  int v12; // ecx
  int v13; // ecx
  const char *v14; // edi
  pset_t **ppset; // [esp+Ch] [ebp-8h]
  pset_t **ppsetprev; // [esp+Ch] [ebp-8h]
  int v17; // [esp+10h] [ebp-4h]
  const pset_t *v18; // [esp+10h] [ebp-4h]
  const char *v19; // [esp+1Ch] [ebp+8h]

  IndentationText = GetIndentationText(nIndentation);
  DevMsg(a1: "%sDSP: %08x [Addr]\n", IndentationText, dsp);
  v3 = "True";
  if ( !dsp->fused )
    v3 = "False";
  DevMsg(a1: "%sfused: %s\n", IndentationText, v3);
  v4 = "True";
  if ( !dsp->bEnabled )
    v4 = "False";
  DevMsg(a1: "%sbEnabled: %s\n", IndentationText, v4);
  DevMsg(a1: "%scchan: %d\n", IndentationText, dsp->cchan);
  DevMsg(a1: "%sCurrent preset: %d\n", IndentationText, dsp->ipset);
  v17 = 0;
  ppset = dsp->ppset;
  do
  {
    v5 = *ppset;
    DevMsg(a1: "%sPSET[%d]: ", IndentationText, v17);
    if ( v5 != nullptr )
      PSET_Print(pset: v5, nIndentation: nIndentation + 1);
    else
      DevMsg(a1: "None\n");
    ++ppset;
    ++v17;
  }
  while ( v17 < 5 );
  DevMsg(a1: "%sPrevious preset: %d\n", IndentationText, dsp->ipsetprev);
  v6 = 0;
  ppsetprev = dsp->ppsetprev;
  do
  {
    v18 = *ppsetprev;
    DevMsg(a1: "%sPSET[%d]: ", IndentationText, v6);
    if ( v18 != nullptr )
      PSET_Print(pset: v18, nIndentation: nIndentation + 1);
    else
      DevMsg(a1: "None\n");
    ++ppsetprev;
    ++v6;
  }
  while ( v6 < 5 );
  DevMsg(a1: "%sxfade: %f\n", IndentationText, dsp->xfade);
  DevMsg(a1: "%sxfade default: %f\n", IndentationText, dsp->xfade_default);
  v7 = "True";
  if ( !dsp->bexpfade )
    v7 = "False";
  DevMsg(a1: "%sbexpfade: %s\n", IndentationText, v7);
  v8 = nIndentation + 1;
  p_xramp = &dsp->xramp;
  if ( sFirstTime )
  {
    strcpy(sIndentationBuffer, "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t");
    sFirstTime = false;
  }
  if ( v8 > 32 )
    v8 = 32;
  v10 = &byte_1045F364[-v8];
  DevMsg(a1: "%sRmp: %08X [Addr]\n", &byte_1045F364[-v8], p_xramp);
  DevMsg(a1: "%sinitval: %d\n", v10, p_xramp->initval);
  DevMsg(a1: "%starget: %d\n", v10, dsp->xramp.target);
  DevMsg(a1: "%ssign: %d\n", v10, dsp->xramp.sign);
  DevMsg(a1: "%sfhitend: %d\n", v10, dsp->xramp.fhitend);
  DevMsg(a1: "%sbEndAtTime: %d\n", v10, dsp->xramp.bEndAtTime);
  p_ps = &dsp->xramp.ps;
  v12 = nIndentation + 2;
  if ( sFirstTime )
  {
    strcpy(sIndentationBuffer, "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t");
    sFirstTime = false;
  }
  if ( nIndentation + 2 > 32 )
    v12 = 32;
  v19 = &byte_1045F364[-v12];
  DevMsg(a1: "%sPosOne: %08X [Addr]\n", &byte_1045F364[-v12], p_ps);
  v13 = nIndentation + 3;
  if ( sFirstTime )
  {
    strcpy(sIndentationBuffer, "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t");
    sFirstTime = false;
  }
  if ( v13 > 32 )
    v13 = 32;
  v14 = &byte_1045F364[-v13];
  DevMsg(a1: "%sPos: %08X [Addr]\n", &byte_1045F364[-v13], p_ps);
  DevMsg(a1: "%sstep: %d\n", v14, p_ps->p.step);
  DevMsg(a1: "%scstep: %d\n", v14, p_ps->p.cstep);
  DevMsg(a1: "%spos: %d\n", v14, p_ps->p.pos);
  DevMsg(a1: "%sD: %d\n", v14, p_ps->p.D);
  DevMsg(a1: "%sfhitend: %d\n", v19, p_ps->fhitend);
}

//------------------------------------------------------------------------------
// Address: 0x10023D50
// Name: void DSP_SetDspAuto(int)
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __cdecl DSP_SetDspAuto(int dsp_preset)
{
  unsigned int v1; // [esp-8h] [ebp-8h]
  int v2; // [esp-4h] [ebp-4h]

  CLoaderMemAlloc::CrtIsValidPointer(this: (ConVar *)&dsp_automatic.IConVar, value: dsp_preset, a2: v1, a3: v2);
}

//------------------------------------------------------------------------------
// Address: 0x10023D70
// Name: void ADSP_GetSize(struct adsp_auto_params_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ADSP_GetSize(adsp_auto_params_t *pa)
{
  double length; // st7
  BOOL v2; // edi
  BOOL v3; // esi
  BOOL v4; // edx
  BOOL v5; // eax
  double v6; // st6
  double v7; // st7
  BOOL v8; // edi
  double v9; // st5
  double v10; // st6
  BOOL v11; // esi
  double v12; // st4
  double v13; // st5
  BOOL v14; // edx
  BOOL v15; // eax
  double width; // st3
  double v17; // st4
  double v18; // st4
  double v19; // st7
  int v20; // edi
  double v21; // rt1
  double v22; // st5
  double v23; // st6
  int v24; // esi
  double v25; // rt1
  BOOL v26; // edx
  int v27; // ebx
  int height; // edx
  double v29; // st6
  BOOL v30; // edi
  BOOL v31; // esi
  BOOL v32; // edx
  double freflectivity; // st7
  float v34; // xmm1_4
  BOOL v35; // esi
  BOOL v36; // edx
  double fdiffusion; // st6
  BOOL v38; // esi
  BOOL v39; // edx
  int shape; // eax
  int v41; // [esp+Ch] [ebp-4h]

  length = (double)pa->length;
  v2 = length > 120.0 && length <= 240.0;
  v3 = length > 240.0 && length <= 480.0;
  v4 = length > 480.0 && length <= 1200.0;
  v5 = length > 1200.0;
  v6 = length;
  v7 = 144.0;
  pa->size = v4 + v2 + 2 * v4 + 2 * (v3 + 2 * v5);
  v8 = v6 > 144.0 && v6 <= 288.0;
  v9 = v6;
  v10 = 288.0;
  v11 = v9 > 288.0 && v9 <= 576.0;
  v12 = v9;
  v13 = 576.0;
  v14 = v12 > 576.0 && v12 <= 1152.0;
  v15 = v12 > 1152.0;
  width = (double)pa->width;
  v17 = width;
  v41 = v14 + v8 + 2 * v14 + 2 * (v11 + 2 * v15);
  pa->len = v41;
  if ( width > 72.0 )
  {
    v18 = 144.0;
    v19 = width;
    if ( width <= 144.0 )
    {
      v20 = 1;
      goto LABEL_30;
    }
    v17 = width;
    v7 = 144.0;
  }
  v20 = 0;
  v21 = v17;
  v18 = v7;
  v19 = v21;
LABEL_30:
  if ( v19 <= v18 )
  {
LABEL_34:
    v24 = 0;
    v25 = v13;
    v22 = v10;
    v23 = v25;
    goto LABEL_35;
  }
  v22 = 288.0;
  v23 = 576.0;
  if ( v19 > 288.0 )
  {
    v13 = 576.0;
    v10 = 288.0;
    goto LABEL_34;
  }
  v24 = 1;
LABEL_35:
  v26 = v19 > v22 && v23 >= v19;
  v27 = v26 + v20 + 2 * v26 + 2 * (v24 + 2 * (v19 > v23));
  height = pa->height;
  v29 = (double)height;
  pa->wid = v27;
  v30 = v29 > 48.0 && height <= 128;
  v31 = height > 128 && v29 <= 216.0;
  v32 = v29 > 216.0 && v29 <= 384.0;
  freflectivity = pa->freflectivity;
  v34 = pa->freflectivity;
  pa->ht = v32 + v30 + 2 * v32 + 2 * (v31 + 2 * (v29 > 384.0));
  v35 = freflectivity > 0.04 && v34 <= 0.5;
  v36 = v34 > 0.5 && freflectivity <= 0.8;
  fdiffusion = pa->fdiffusion;
  pa->reflectivity = (freflectivity > 0.8) + v35 + 2 * (freflectivity > 0.8) + 2 * v36;
  v38 = fdiffusion > 0.01 && fdiffusion <= 0.1;
  v39 = fdiffusion > 0.1 && fdiffusion <= 0.3;
  shape = pa->shape;
  pa->diffusion = (fdiffusion > 0.3) + v38 + 2 * (fdiffusion > 0.3) + 2 * v39;
  if ( shape != 6 && shape != 10 )
  {
    if ( shape == 4 || shape == 5 )
      pa->size = v27;
    else
      pa->size = (v27 + v41) / 2;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10024050
// Name: void ADSP_InterpParam(struct pset_t __near *,struct pset_t __near *,struct pset_t __near *,int,int,int,int,int,bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ADSP_InterpParam(
        pset_t *pnew,
        pset_t *pmin,
        pset_t *pmax,
        int proc_type,
        int skipprocs,
        int iparam,
        int index,
        int index_max,
        bool bexp)
{
  int cprcs; // ecx
  int v10; // edi
  int v11; // eax
  int v12; // esi
  prc_t *prcs; // edx
  int v14; // edx
  int v15; // ecx
  int v16; // eax
  int v17; // esi
  prc_t *v18; // edx
  int v19; // esi
  int v20; // ecx
  int v21; // eax
  prc_t *v22; // edx
  float v23; // xmm2_4
  float v24; // xmm1_4
  float v25; // xmm0_4
  int iproc_new; // [esp+24h] [ebp+18h]

  cprcs = pnew->cprcs;
  v10 = skipprocs;
  v11 = 0;
  v12 = skipprocs;
  if ( cprcs <= 0 )
  {
LABEL_7:
    v14 = -1;
    iproc_new = -1;
    goto LABEL_8;
  }
  prcs = pnew->prcs;
  while ( prcs->type != proc_type )
  {
LABEL_6:
    ++v11;
    ++prcs;
    if ( v11 >= cprcs )
      goto LABEL_7;
  }
  if ( v12 != 0 )
  {
    --v12;
    goto LABEL_6;
  }
  v14 = v11;
  iproc_new = v11;
LABEL_8:
  v15 = pmin->cprcs;
  v16 = 0;
  v17 = v10;
  if ( v15 <= 0 )
  {
LABEL_15:
    v19 = -1;
    goto LABEL_16;
  }
  v18 = pmin->prcs;
  while ( 2 )
  {
    if ( v18->type != proc_type )
    {
LABEL_13:
      ++v16;
      ++v18;
      if ( v16 >= v15 )
      {
        v14 = iproc_new;
        goto LABEL_15;
      }
      continue;
    }
    break;
  }
  if ( v17 != 0 )
  {
    --v17;
    goto LABEL_13;
  }
  v14 = iproc_new;
  v19 = v16;
LABEL_16:
  v20 = pmax->cprcs;
  v21 = 0;
  if ( v20 > 0 )
  {
    v22 = pmax->prcs;
    while ( 1 )
    {
      if ( v22->type == proc_type )
      {
        if ( v10 == 0 )
        {
          v14 = iproc_new;
          goto LABEL_24;
        }
        --v10;
      }
      ++v21;
      ++v22;
      if ( v21 >= v20 )
      {
        v14 = iproc_new;
        break;
      }
    }
  }
  v21 = -1;
LABEL_24:
  if ( v14 >= 0 && v19 >= 0 && v21 >= 0 )
  {
    v23 = pmin->prcs[v19].prm[iparam];
    v24 = (float)index / (float)index_max;
    v25 = (float)(pmax->prcs[v21].prm[iparam] - v23) * v24;
    if ( bexp )
      v25 = v25 * v24;
    pnew->prcs[v14].prm[iparam] = v25 + v23;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10024170
// Name: void ADSP_SetParam(struct pset_t __near *,int,int,int,float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ADSP_SetParam(pset_t *pnew, int proc_type, int skipprocs, int iparam, float value)
{
  int cprcs; // ecx
  int v7; // eax
  prc_t *prcs; // edx

  cprcs = pnew->cprcs;
  v7 = 0;
  if ( cprcs > 0 )
  {
    prcs = pnew->prcs;
    do
    {
      if ( prcs->type == proc_type )
      {
        if ( skipprocs == 0 )
        {
          if ( v7 >= 0 )
            pnew->prcs[v7].prm[iparam] = value;
          return;
        }
        --skipprocs;
      }
      ++v7;
      ++prcs;
    }
    while ( v7 < cprcs );
  }
}

//------------------------------------------------------------------------------
// Address: 0x100241C0
// Name: void ADSP_SetParamIfNegative(struct pset_t __near *,struct pset_t __near *,struct pset_t __near *,int,int,int,int,int,bool,float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ADSP_SetParamIfNegative(
        pset_t *pnew,
        pset_t *pmin,
        pset_t *pmax,
        pset_t *proc_type,
        int skipprocs,
        int iparam,
        int index,
        int index_max,
        bool bexp,
        float value)
{
  int cprcs; // ecx
  int v11; // eax
  int v12; // esi
  prc_t *prcs; // edx
  int v14; // edx
  int v15; // ecx
  int v16; // edi
  prc_t *v17; // esi
  int v18; // edi
  int v19; // edx
  int v20; // ecx
  prc_t *v21; // esi
  int v22; // [esp+10h] [ebp-8h]
  int iproc_min; // [esp+14h] [ebp-4h]

  cprcs = pnew->cprcs;
  v11 = 0;
  v12 = skipprocs;
  if ( cprcs <= 0 )
  {
LABEL_7:
    iproc_min = -1;
    goto LABEL_8;
  }
  prcs = pnew->prcs;
  while ( (pset_t *)prcs->type != proc_type )
  {
LABEL_6:
    ++v11;
    ++prcs;
    if ( v11 >= cprcs )
      goto LABEL_7;
  }
  if ( v12 != 0 )
  {
    --v12;
    goto LABEL_6;
  }
  iproc_min = v11;
LABEL_8:
  v14 = pmin->cprcs;
  v15 = 0;
  v16 = skipprocs;
  if ( v14 <= 0 )
  {
LABEL_14:
    v22 = -1;
    goto LABEL_15;
  }
  v17 = pmin->prcs;
  while ( 2 )
  {
    if ( (pset_t *)v17->type != proc_type )
    {
LABEL_13:
      ++v15;
      ++v17;
      if ( v15 >= v14 )
        goto LABEL_14;
      continue;
    }
    break;
  }
  if ( v16 != 0 )
  {
    --v16;
    goto LABEL_13;
  }
  v22 = v15;
LABEL_15:
  v18 = skipprocs;
  v19 = pmax->cprcs;
  v20 = 0;
  if ( v19 > 0 )
  {
    v21 = pmax->prcs;
    do
    {
      if ( (pset_t *)v21->type == proc_type )
      {
        if ( v18 == 0 )
          goto LABEL_22;
        --v18;
      }
      ++v20;
      ++v21;
    }
    while ( v20 < v19 );
  }
  v20 = -1;
LABEL_22:
  if ( iproc_min >= 0 && v22 >= 0 && v20 >= 0 )
  {
    if ( pmin->prcs[v22].prm[iparam] < 0.0 || pmax->prcs[v20].prm[iparam] < 0.0 )
      ADSP_SetParam(pnew, (int)proc_type, skipprocs, iparam, value);
    else
      ADSP_InterpParam(pnew, pmin, pmax, (int)proc_type, skipprocs, iparam, index, index_max, bexp);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10024300
// Name: bool FBatchPreset(struct pset_t __near *)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl FBatchPreset(pset_t *ppset)
{
  return ppset->type < 2u;
}

//------------------------------------------------------------------------------
// Address: 0x10024320
// Name: void DSP_ProcessStereoToMono(struct dsp_t __near *,struct portable_samplepair_t __near *,struct portable_samplepair_t __near *,int,bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DSP_ProcessStereoToMono(
        dsp_t *pdsp,
        portable_samplepair_t *pbfront,
        portable_samplepair_t *pbrear,
        int sampleCount,
        bool bcrossfading)
{
  portable_samplepair_t *v5; // ebx
  int v6; // esi
  int v7; // eax
  int v8; // eax
  dsp_t *v9; // ecx
  int v10; // edi
  int Next; // esi
  int v12; // edi
  int v13; // eax
  int v14; // esi
  int v15; // esi
  int left; // edi
  int right; // esi
  int v18; // eax
  dsp_t *v19; // ecx
  int v20; // eax
  int v21; // eax
  int v22; // edi
  int v23; // edi
  int v24; // ecx
  int v25; // esi
  int frp; // [esp+Ch] [ebp-4h]
  int count; // [esp+1Ch] [ebp+Ch]
  int counta; // [esp+1Ch] [ebp+Ch]
  int flp; // [esp+24h] [ebp+14h]
  int flpa; // [esp+24h] [ebp+14h]
  bool bexp; // [esp+2Bh] [ebp+1Bh]

  v5 = pbfront;
  v6 = sampleCount;
  if ( bcrossfading )
  {
    v9 = pdsp;
    bexp = pdsp->bexpfade;
    if ( pdsp->ipset != 0 && pdsp->ipsetprev != 0 )
    {
      if ( sampleCount != 0 )
      {
        while ( 1 )
        {
          v10 = (v5->right + v5->left) >> 1;
          count = v6 - 1;
          Next = PSET_GetNext(ppset: v9->ppset[0], x: v10);
          v12 = PSET_GetNext(ppset: pdsp->ppsetprev[0], x: v10);
          v13 = RMP_GetNext(prmp: &pdsp->xramp);
          v14 = (v13 * (Next - v12)) >> 12;
          if ( bexp )
            v14 = (v13 * v14) >> 12;
          v15 = v12 + v14;
          v5->left = v15;
          v5->right = v15;
          ++v5;
          if ( count == 0 )
            break;
          v9 = pdsp;
          v6 = count;
        }
      }
    }
    else if ( sampleCount != 0 )
    {
      while ( 1 )
      {
        left = v5->left;
        counta = v6 - 1;
        right = v5->right;
        v18 = (v5->left + right) >> 1;
        flp = v18;
        if ( v9->ipset != 0 )
        {
          right = PSET_GetNext(ppset: v9->ppset[0], x: (left + right) >> 1);
          v18 = flp;
          left = right;
        }
        v19 = pdsp;
        if ( pdsp->ipsetprev != 0 )
        {
          v20 = PSET_GetNext(ppset: pdsp->ppsetprev[0], x: v18);
          v19 = pdsp;
          frp = v20;
        }
        else
        {
          v20 = v5->left;
          frp = v5->right;
        }
        flpa = v20;
        v21 = RMP_GetNext(prmp: &v19->xramp);
        v22 = (v21 * (left - flpa)) >> 12;
        if ( bexp )
        {
          v23 = flpa + ((v21 * v22) >> 12);
          v24 = frp;
          v25 = (v21 * (right - frp)) >> 12;
        }
        else
        {
          v23 = flpa + v22;
          v24 = frp;
          v25 = right - frp;
        }
        v5->left = v23;
        v5->right = v24 + ((v21 * v25) >> 12);
        ++v5;
        if ( counta == 0 )
          break;
        v9 = pdsp;
        v6 = counta;
      }
    }
  }
  else if ( pdsp->ipset != 0 )
  {
    if ( pdsp->ppset[0]->type > 1u )
    {
      if ( sampleCount != 0 )
      {
        do
        {
          v8 = PSET_GetNext(ppset: pdsp->ppset[0], x: (v5->right + v5->left) >> 1);
          v5->right = v8;
          v5->left = v8;
          ++v5;
          --v6;
        }
        while ( v6 != 0 );
      }
    }
    else
    {
      if ( sampleCount != 0 )
      {
        do
        {
          v7 = v5->left + v5->right;
          ++v5;
          --v6;
          v5[-1].left = v7 >> 1;
        }
        while ( v6 != 0 );
      }
      PSET_GetNextN(ppset: pdsp->ppset[0], pbuffer: pbfront, SampleCount: sampleCount, op: 2);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10024500
// Name: void DSP_ProcessStereoToStereo(struct dsp_t __near *,struct portable_samplepair_t __near *,struct portable_samplepair_t __near *,int,bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DSP_ProcessStereoToStereo(
        dsp_t *pdsp,
        portable_samplepair_t *pbfront,
        portable_samplepair_t *pbrear,
        int sampleCount,
        bool bcrossfading)
{
  portable_samplepair_t *v5; // ebx
  int v6; // edi
  pset_t *v7; // ecx
  int v8; // eax
  int Next; // esi
  int v10; // edi
  int v11; // eax
  int v12; // esi
  int v13; // esi
  int v14; // ecx
  int v15; // edi
  int count; // [esp+Ch] [ebp-4h]
  int flp; // [esp+1Ch] [ebp+Ch]
  int frp; // [esp+24h] [ebp+14h]
  int bexp; // [esp+28h] [ebp+18h]
  bool bexp_3; // [esp+2Bh] [ebp+1Bh]

  v5 = pbfront;
  v6 = sampleCount;
  if ( bcrossfading )
  {
    bexp_3 = pdsp->bexpfade;
    if ( sampleCount != 0 )
    {
      while ( 1 )
      {
        count = v6 - 1;
        Next = PSET_GetNext(ppset: pdsp->ppset[0], x: v5->left);
        v10 = PSET_GetNext(ppset: pdsp->ppset[1], x: v5->right);
        flp = PSET_GetNext(ppset: pdsp->ppsetprev[0], x: v5->left);
        frp = PSET_GetNext(ppset: pdsp->ppsetprev[1], x: v5->right);
        v11 = RMP_GetNext(prmp: &pdsp->xramp);
        v12 = (v11 * (Next - flp)) >> 12;
        if ( bexp_3 )
        {
          v13 = flp + ((v11 * v12) >> 12);
          v14 = frp;
          v15 = (v11 * (v10 - frp)) >> 12;
        }
        else
        {
          v13 = flp + v12;
          v14 = frp;
          v15 = v10 - frp;
        }
        v5->left = v13;
        v5->right = v14 + ((v11 * v15) >> 12);
        ++v5;
        if ( count == 0 )
          break;
        v6 = count;
      }
    }
  }
  else if ( pdsp->ipset != 0 )
  {
    v7 = pdsp->ppset[0];
    if ( v7->type > 1u || pdsp->ppset[1]->type > 1u )
    {
      if ( sampleCount != 0 )
      {
        do
        {
          bexp = PSET_GetNext(ppset: pdsp->ppset[0], x: v5->left);
          v8 = PSET_GetNext(ppset: pdsp->ppset[1], x: v5->right);
          v5->left = bexp;
          v5->right = v8;
          ++v5;
          --v6;
        }
        while ( v6 != 0 );
      }
    }
    else
    {
      PSET_GetNextN(ppset: v7, pbuffer: pbfront, SampleCount: sampleCount, op: 0);
      PSET_GetNextN(ppset: pdsp->ppset[1], pbuffer: pbfront, SampleCount: sampleCount, op: 1);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10024660
// Name: void DSP_ProcessQuadToMono(struct dsp_t __near *,struct portable_samplepair_t __near *,struct portable_samplepair_t __near *,int,bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DSP_ProcessQuadToMono(
        dsp_t *pdsp,
        portable_samplepair_t *pbfront,
        portable_samplepair_t *pbrear,
        int sampleCount,
        bool bcrossfading)
{
  portable_samplepair_t *v5; // eax
  int v6; // edi
  dsp_t *v7; // edx
  int v8; // edx
  int v9; // edx
  portable_samplepair_t *v10; // ecx
  int *v11; // eax
  portable_samplepair_t *v12; // ebx
  int *v13; // esi
  int v14; // ecx
  int v15; // eax
  int v16; // eax
  int *p_right; // ebx
  int v18; // esi
  int Next; // edi
  int v20; // esi
  int v21; // eax
  int v22; // edi
  int v23; // edi
  int *v24; // ecx
  int v25; // eax
  int v26; // edx
  int left; // ebx
  int v28; // esi
  int v29; // eax
  int v30; // eax
  int v31; // edi
  dsp_t *v32; // edx
  int v33; // eax
  int v34; // eax
  int v35; // edi
  int v36; // edi
  int v37; // esi
  int v38; // ebx
  int v39; // ecx
  int rrp; // [esp+Ch] [ebp-18h]
  int rrpa; // [esp+Ch] [ebp-18h]
  int rr; // [esp+10h] [ebp-14h]
  int rlp; // [esp+14h] [ebp-10h]
  int frp; // [esp+18h] [ebp-Ch]
  int flp; // [esp+1Ch] [ebp-8h]
  portable_samplepair_t *v46; // [esp+20h] [ebp-4h]
  int count; // [esp+30h] [ebp+Ch]
  int counta; // [esp+30h] [ebp+Ch]
  portable_samplepair_t *pbreara; // [esp+34h] [ebp+10h]
  portable_samplepair_t *pbrearb; // [esp+34h] [ebp+10h]
  portable_samplepair_t *pbrearc; // [esp+34h] [ebp+10h]
  portable_samplepair_t *sampleCounta; // [esp+38h] [ebp+14h]
  int *sampleCountb; // [esp+38h] [ebp+14h]
  bool bexp; // [esp+3Fh] [ebp+1Bh]

  v5 = pbfront;
  v6 = sampleCount;
  if ( bcrossfading )
  {
    bexp = pdsp->bexpfade;
    if ( pdsp->ipset != 0 && pdsp->ipsetprev != 0 )
    {
      if ( sampleCount != 0 )
      {
        sampleCounta = pbrear;
        v16 = (char *)pbrear - (char *)pbfront;
        p_right = &pbfront->right;
        for ( pbrearb = (portable_samplepair_t *)((char *)pbrear - (char *)pbfront); ; v16 = (int)pbrearb )
        {
          v18 = (*p_right + *(int *)((char *)p_right + v16) + *(p_right - 1) + sampleCounta->left) >> 2;
          count = v6 - 1;
          Next = PSET_GetNext(ppset: pdsp->ppset[0], x: v18);
          v20 = PSET_GetNext(ppset: pdsp->ppsetprev[0], x: v18);
          v21 = RMP_GetNext(prmp: &pdsp->xramp);
          v22 = (v21 * (Next - v20)) >> 12;
          if ( bexp )
            v22 = (v21 * v22) >> 12;
          v23 = v20 + v22;
          *(p_right - 1) = v23;
          *p_right = v23;
          sampleCounta->left = v23;
          *(int *)((char *)&pbrearb->left + (_DWORD)p_right) = v23;
          p_right += 2;
          ++sampleCounta;
          if ( count == 0 )
            break;
          v6 = count;
        }
      }
    }
    else if ( sampleCount != 0 )
    {
      v46 = pbrear;
      v24 = &pbfront->right;
      v25 = (char *)pbrear - (char *)pbfront;
      sampleCountb = &pbfront->right;
      for ( pbrearc = (portable_samplepair_t *)((char *)pbrear - (char *)pbfront); ; v25 = (int)pbrearc )
      {
        v26 = *(int *)((char *)v24 + v25);
        left = v46->left;
        v28 = *v24;
        counta = v6 - 1;
        v29 = (v46->left + v26 + *v24 + *(v24 - 1)) >> 2;
        rrp = v29;
        if ( pdsp->ipset != 0 )
        {
          v30 = PSET_GetNext(ppset: pdsp->ppset[0], x: v29);
          v24 = sampleCountb;
          v28 = v30;
          v29 = rrp;
          v31 = v28;
          rr = v28;
          left = v28;
        }
        else
        {
          v31 = *(v24 - 1);
          rr = v26;
        }
        v32 = pdsp;
        if ( pdsp->ipsetprev != 0 )
        {
          v33 = PSET_GetNext(ppset: pdsp->ppsetprev[0], x: v29);
          v32 = pdsp;
          flp = v33;
          frp = v33;
          rlp = v33;
          rrpa = v33;
        }
        else
        {
          flp = *(v24 - 1);
          frp = *v24;
          rlp = v46->left;
          rrpa = *(int *)((char *)&pbrearc->left + (_DWORD)v24);
        }
        v34 = RMP_GetNext(prmp: &v32->xramp);
        v35 = (v34 * (v31 - flp)) >> 12;
        if ( bexp )
        {
          v36 = flp + ((v34 * v35) >> 12);
          v37 = frp + ((v34 * ((v34 * (v28 - frp)) >> 12)) >> 12);
          v38 = rlp + ((v34 * ((v34 * (left - rlp)) >> 12)) >> 12);
          v39 = (v34 * (rr - rrpa)) >> 12;
        }
        else
        {
          v36 = flp + v35;
          v37 = frp + ((v34 * (v28 - frp)) >> 12);
          v38 = rlp + ((v34 * (left - rlp)) >> 12);
          v39 = rr - rrpa;
        }
        *sampleCountb = v37;
        *(sampleCountb - 1) = v36;
        v46->left = v38;
        *(int *)((char *)&pbrearc->left + (_DWORD)sampleCountb) = rrpa + ((v34 * v39) >> 12);
        sampleCountb += 2;
        ++v46;
        if ( counta == 0 )
          break;
        v24 = sampleCountb;
        v6 = counta;
      }
    }
  }
  else
  {
    v7 = pdsp;
    if ( pdsp->ipset != 0 )
    {
      if ( pdsp->ppset[0]->type > 1u )
      {
        if ( sampleCount != 0 )
        {
          v12 = pbrear;
          v13 = &pbfront->right;
          v14 = (char *)pbrear - (char *)pbfront;
          pbreara = (portable_samplepair_t *)((char *)pbrear - (char *)pbfront);
          do
          {
            v15 = PSET_GetNext(
                    ppset: pdsp->ppset[0],
                    x: (*v13 + *(int *)((char *)v13 + v14) + *(v13 - 1) + v12->left) >> 2);
            v14 = (int)pbreara;
            *v13 = v15;
            *(v13 - 1) = v15;
            *(int *)((char *)&pbreara->left + (_DWORD)v13) = v15;
            v12->left = v15;
            v13 += 2;
            ++v12;
            --v6;
          }
          while ( v6 != 0 );
        }
      }
      else
      {
        if ( sampleCount != 0 )
        {
          do
          {
            v8 = *(int *)((char *)&v5->right + (char *)pbrear - (char *)pbfront)
               + *(int *)((char *)&v5->left + (char *)pbrear - (char *)pbfront);
            ++v5;
            --v6;
            v5[-1].left = (v5[-1].right + v5[-1].left + v8) >> 2;
          }
          while ( v6 != 0 );
          v7 = pdsp;
        }
        PSET_GetNextN(ppset: v7->ppset[0], pbuffer: pbfront, SampleCount: sampleCount, op: 2);
        v9 = sampleCount;
        if ( sampleCount != 0 )
        {
          v10 = pbrear;
          v11 = &pbfront->right;
          do
          {
            v10->left = *(v11 - 1);
            *(int *)((char *)v11 + (char *)pbrear - (char *)pbfront) = *v11;
            v11 += 2;
            ++v10;
            --v9;
          }
          while ( v9 != 0 );
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10024970
// Name: void DSP_ProcessQuadToStereo(struct dsp_t __near *,struct portable_samplepair_t __near *,struct portable_samplepair_t __near *,int,bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DSP_ProcessQuadToStereo(
        dsp_t *pdsp,
        portable_samplepair_t *pbfront,
        portable_samplepair_t *pbrear,
        int sampleCount,
        bool bcrossfading)
{
  portable_samplepair_t *v5; // eax
  int v6; // edi
  dsp_t *v7; // edx
  portable_samplepair_t *v8; // esi
  int v9; // ecx
  int v10; // esi
  int v11; // edx
  portable_samplepair_t *v12; // ecx
  int *v13; // eax
  int v14; // esi
  portable_samplepair_t *v15; // ebx
  int *v16; // esi
  int v17; // eax
  dsp_t *v18; // esi
  int *p_right; // eax
  int v20; // ecx
  int v21; // edi
  int v22; // ebx
  int Next; // esi
  int v24; // ebx
  int v25; // edi
  int v26; // eax
  int v27; // esi
  int v28; // ebx
  int v29; // ebx
  int v30; // esi
  int *v31; // ecx
  int v32; // edx
  int left; // ebx
  int v34; // eax
  int v35; // edi
  int v36; // esi
  int v37; // eax
  int v38; // edi
  dsp_t *v39; // edx
  int v40; // eax
  int v41; // eax
  int v42; // esi
  int v43; // esi
  int v44; // edi
  int v45; // ebx
  int v46; // ecx
  int avl; // [esp+Ch] [ebp-18h]
  int avla; // [esp+Ch] [ebp-18h]
  int rr; // [esp+10h] [ebp-14h]
  int rlp; // [esp+14h] [ebp-10h]
  int flp; // [esp+18h] [ebp-Ch]
  int *v52; // [esp+1Ch] [ebp-8h]
  portable_samplepair_t *v53; // [esp+1Ch] [ebp-8h]
  portable_samplepair_t *v54; // [esp+20h] [ebp-4h]
  int *v55; // [esp+20h] [ebp-4h]
  portable_samplepair_t *pbfronta; // [esp+30h] [ebp+Ch]
  portable_samplepair_t *pbfrontb; // [esp+30h] [ebp+Ch]
  portable_samplepair_t *pbfrontc; // [esp+30h] [ebp+Ch]
  int frpc; // [esp+34h] [ebp+10h]
  int frp; // [esp+34h] [ebp+10h]
  int frpa; // [esp+34h] [ebp+10h]
  int frpb; // [esp+34h] [ebp+10h]
  int count; // [esp+38h] [ebp+14h]
  int counta; // [esp+38h] [ebp+14h]
  int bexp; // [esp+3Ch] [ebp+18h]
  bool bexp_3; // [esp+3Fh] [ebp+1Bh]

  v5 = pbfront;
  v6 = sampleCount;
  if ( bcrossfading )
  {
    v18 = pdsp;
    bexp_3 = pdsp->bexpfade;
    if ( pdsp->ipset != 0 && pdsp->ipsetprev != 0 )
    {
      if ( sampleCount != 0 )
      {
        p_right = &pbfront->right;
        v54 = pbrear;
        v20 = (char *)pbrear - (char *)pbfront;
        v52 = &pbfront->right;
        for ( pbfrontb = (portable_samplepair_t *)((char *)pbrear - (char *)pbfront); ; v20 = (int)pbfrontb )
        {
          count = v6 - 1;
          v21 = (*(p_right - 1) + v54->left) >> 1;
          v22 = (*p_right + *(int *)((char *)p_right + v20)) >> 1;
          frpc = v22;
          Next = PSET_GetNext(ppset: v18->ppset[0], x: v21);
          v24 = PSET_GetNext(ppset: pdsp->ppset[1], x: v22);
          v25 = PSET_GetNext(ppset: pdsp->ppsetprev[0], x: v21);
          frp = PSET_GetNext(ppset: pdsp->ppsetprev[1], x: frpc);
          v26 = RMP_GetNext(prmp: &pdsp->xramp);
          v27 = (v26 * (Next - v25)) >> 12;
          v28 = (v26 * (v24 - frp)) >> 12;
          if ( bexp_3 )
          {
            v27 = (v26 * v27) >> 12;
            v28 = (v26 * v28) >> 12;
          }
          v29 = frp + v28;
          v30 = v25 + v27;
          *(v52 - 1) = v30;
          *v52 = v29;
          v54->left = v30;
          *(int *)((char *)&pbfrontb->left + (_DWORD)v52) = v29;
          v52 += 2;
          ++v54;
          if ( count == 0 )
            break;
          p_right = v52;
          v6 = count;
          v18 = pdsp;
        }
      }
    }
    else if ( sampleCount != 0 )
    {
      v53 = pbrear;
      v31 = &pbfront->right;
      v32 = (char *)pbrear - (char *)pbfront;
      v55 = &pbfront->right;
      pbfrontc = (portable_samplepair_t *)((char *)pbrear - (char *)pbfront);
      while ( 1 )
      {
        left = v53->left;
        counta = v6 - 1;
        rr = *(int *)((char *)v31 + v32);
        v34 = (v53->left + *(v31 - 1)) >> 1;
        v35 = (*v31 + rr) >> 1;
        avl = v34;
        frpa = v35;
        if ( v18->ipset != 0 )
        {
          v36 = PSET_GetNext(ppset: v18->ppset[0], x: v34);
          left = v36;
          v37 = PSET_GetNext(ppset: pdsp->ppset[0], x: v35);
          v31 = v55;
          v38 = v37;
          v34 = avl;
          rr = v38;
        }
        else
        {
          v36 = *(v31 - 1);
          v38 = *v31;
        }
        v39 = pdsp;
        if ( pdsp->ipsetprev != 0 )
        {
          flp = PSET_GetNext(ppset: pdsp->ppsetprev[0], x: v34);
          rlp = flp;
          v40 = PSET_GetNext(ppset: pdsp->ppsetprev[0], x: frpa);
          v39 = pdsp;
          frpb = v40;
          avla = v40;
        }
        else
        {
          flp = *(v31 - 1);
          frpb = *v31;
          rlp = v53->left;
          avla = *(int *)((char *)v31 + (_DWORD)pbfrontc);
        }
        v41 = RMP_GetNext(prmp: &v39->xramp);
        v42 = (v41 * (v36 - flp)) >> 12;
        if ( bexp_3 )
        {
          v43 = flp + ((v41 * v42) >> 12);
          v44 = frpb + ((v41 * ((v41 * (v38 - frpb)) >> 12)) >> 12);
          v45 = rlp + ((v41 * ((v41 * (left - rlp)) >> 12)) >> 12);
          v46 = (v41 * (rr - avla)) >> 12;
        }
        else
        {
          v43 = flp + v42;
          v44 = frpb + ((v41 * (v38 - frpb)) >> 12);
          v45 = rlp + ((v41 * (left - rlp)) >> 12);
          v46 = rr - avla;
        }
        *(v55 - 1) = v43;
        *v55 = v44;
        v53->left = v45;
        *(int *)((char *)v55 + (_DWORD)pbfrontc) = avla + ((v41 * v46) >> 12);
        v55 += 2;
        ++v53;
        if ( counta == 0 )
          break;
        v31 = v55;
        v6 = counta;
        v32 = (int)pbfrontc;
        v18 = pdsp;
      }
    }
  }
  else
  {
    v7 = pdsp;
    if ( pdsp->ipset != 0 )
    {
      if ( pdsp->ppset[0]->type > 1u || pdsp->ppset[1]->type > 1u )
      {
        if ( sampleCount != 0 )
        {
          v15 = pbrear;
          v16 = &pbfront->right;
          pbfronta = (portable_samplepair_t *)((char *)pbrear - (char *)pbfront);
          while ( 1 )
          {
            bexp = PSET_GetNext(ppset: v7->ppset[0], x: (v15->left + *(v16 - 1)) >> 1);
            v17 = PSET_GetNext(ppset: pdsp->ppset[1], x: (*(int *)((char *)&pbfronta->left + (_DWORD)v16) + *v16) >> 1);
            *(v16 - 1) = bexp;
            v15->left = bexp;
            *v16 = v17;
            *(int *)((char *)&pbfronta->left + (_DWORD)v16) = v17;
            v16 += 2;
            ++v15;
            if ( --v6 == 0 )
              break;
            v7 = pdsp;
          }
        }
      }
      else
      {
        v8 = pbrear;
        if ( sampleCount != 0 )
        {
          v9 = (char *)pbrear - (char *)pbfront;
          do
          {
            v10 = *(int *)((char *)&v5->left + v9) + v5->left;
            ++v5;
            v5[-1].left = v10 >> 1;
            --v6;
            v5[-1].right = (v5[-1].right + *(_DWORD *)((char *)v5 + v9 - 4)) >> 1;
          }
          while ( v6 != 0 );
          v5 = pbfront;
          v8 = pbrear;
        }
        PSET_GetNextN(ppset: pdsp->ppset[0], pbuffer: v5, SampleCount: sampleCount, op: 0);
        PSET_GetNextN(ppset: pdsp->ppset[1], pbuffer: pbfront, SampleCount: sampleCount, op: 1);
        v11 = sampleCount;
        if ( sampleCount != 0 )
        {
          v12 = v8;
          v13 = &pbfront->right;
          v14 = (char *)v8 - (char *)pbfront;
          do
          {
            v12->left = *(v13 - 1);
            *(int *)((char *)v13 + v14) = *v13;
            v13 += 2;
            ++v12;
            --v11;
          }
          while ( v11 != 0 );
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10024D40
// Name: void DSP_ProcessQuadToQuad(struct dsp_t __near *,struct portable_samplepair_t __near *,struct portable_samplepair_t __near *,int,bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DSP_ProcessQuadToQuad(
        dsp_t *pdsp,
        portable_samplepair_t *pbfront,
        portable_samplepair_t *pbrear,
        int sampleCount,
        bool bcrossfading)
{
  portable_samplepair_t *v5; // ebx
  int *v6; // esi
  int v7; // eax
  dsp_t *v8; // ebx
  int *p_right; // edi
  int v10; // eax
  int Next; // esi
  int v12; // edi
  int v13; // ebx
  int v14; // eax
  int v15; // esi
  int v16; // esi
  int v17; // edi
  int v18; // ebx
  int v19; // ecx
  int rrpa; // [esp+Ch] [ebp-18h]
  int rrp; // [esp+Ch] [ebp-18h]
  int rr; // [esp+10h] [ebp-14h]
  int rlp; // [esp+14h] [ebp-10h]
  int frp; // [esp+18h] [ebp-Ch]
  int flp; // [esp+1Ch] [ebp-8h]
  portable_samplepair_t *v26; // [esp+20h] [ebp-4h]
  portable_samplepair_t *pbfronta; // [esp+30h] [ebp+Ch]
  portable_samplepair_t *pbfrontb; // [esp+30h] [ebp+Ch]
  int fra; // [esp+34h] [ebp+10h]
  int *fr; // [esp+34h] [ebp+10h]
  int bexp; // [esp+3Ch] [ebp+18h]
  bool bexp_3; // [esp+3Fh] [ebp+1Bh]

  if ( bcrossfading )
  {
    v8 = pdsp;
    bexp_3 = pdsp->bexpfade;
    if ( sampleCount != 0 )
    {
      v26 = pbrear;
      p_right = &pbfront->right;
      v10 = (char *)pbrear - (char *)pbfront;
      fr = &pbfront->right;
      pbfrontb = (portable_samplepair_t *)v10;
      while ( 1 )
      {
        --sampleCount;
        Next = PSET_GetNext(ppset: v8->ppset[0], x: *(p_right - 1));
        v12 = PSET_GetNext(ppset: v8->ppset[1], x: *p_right);
        v13 = PSET_GetNext(ppset: v8->ppset[2], x: v26->left);
        rr = PSET_GetNext(ppset: pdsp->ppset[3], x: *(int *)((char *)&pbfrontb->left + (_DWORD)fr));
        flp = PSET_GetNext(ppset: pdsp->ppsetprev[0], x: *(fr - 1));
        frp = PSET_GetNext(ppset: pdsp->ppsetprev[1], x: *fr);
        rlp = PSET_GetNext(ppset: pdsp->ppsetprev[2], x: v26->left);
        rrp = PSET_GetNext(ppset: pdsp->ppsetprev[3], x: *(int *)((char *)&pbfrontb->left + (_DWORD)fr));
        v14 = RMP_GetNext(prmp: &pdsp->xramp);
        v15 = (v14 * (Next - flp)) >> 12;
        if ( bexp_3 )
        {
          v16 = flp + ((v14 * v15) >> 12);
          v17 = frp + ((v14 * ((v14 * (v12 - frp)) >> 12)) >> 12);
          v18 = rlp + ((v14 * ((v14 * (v13 - rlp)) >> 12)) >> 12);
          v19 = (v14 * (rr - rrp)) >> 12;
        }
        else
        {
          v16 = flp + v15;
          v17 = frp + ((v14 * (v12 - frp)) >> 12);
          v18 = rlp + ((v14 * (v13 - rlp)) >> 12);
          v19 = rr - rrp;
        }
        *(fr - 1) = v16;
        *fr = v17;
        v26->left = v18;
        *(int *)((char *)&pbfrontb->left + (_DWORD)fr) = rrp + ((v14 * v19) >> 12);
        fr += 2;
        ++v26;
        if ( sampleCount == 0 )
          break;
        p_right = fr;
        v8 = pdsp;
      }
    }
  }
  else if ( pdsp->ipset != 0 )
  {
    if ( pdsp->ppset[0]->type <= 1u
      && pdsp->ppset[1]->type <= 1u
      && pdsp->ppset[2]->type <= 1u
      && FBatchPreset(ppset: pdsp->ppset[3]) )
    {
      PSET_GetNextN(ppset: pdsp->ppset[0], pbuffer: pbfront, SampleCount: sampleCount, op: 0);
      PSET_GetNextN(ppset: pdsp->ppset[1], pbuffer: pbfront, SampleCount: sampleCount, op: 1);
      PSET_GetNextN(ppset: pdsp->ppset[2], pbuffer: pbrear, SampleCount: sampleCount, op: 0);
      PSET_GetNextN(ppset: pdsp->ppset[3], pbuffer: pbrear, SampleCount: sampleCount, op: 1);
    }
    else if ( sampleCount != 0 )
    {
      v5 = pbrear;
      v6 = &pbfront->right;
      pbfronta = (portable_samplepair_t *)((char *)pbrear - (char *)pbfront);
      do
      {
        --sampleCount;
        bexp = PSET_GetNext(ppset: pdsp->ppset[0], x: *(v6 - 1));
        fra = PSET_GetNext(ppset: pdsp->ppset[1], x: *v6);
        rrpa = PSET_GetNext(ppset: pdsp->ppset[2], x: v5->left);
        v7 = PSET_GetNext(ppset: pdsp->ppset[3], x: *(int *)((char *)&pbfronta->left + (_DWORD)v6));
        *(v6 - 1) = bexp;
        *v6 = fra;
        v5->left = rrpa;
        *(int *)((char *)&pbfronta->left + (_DWORD)v6) = v7;
        v6 += 2;
        ++v5;
      }
      while ( sampleCount != 0 );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10025000
// Name: void DSP_Process5To1(struct dsp_t __near *,struct portable_samplepair_t __near *,struct portable_samplepair_t __near *,struct portable_samplepair_t __near *,int,bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DSP_Process5To1(
        dsp_t *pdsp,
        portable_samplepair_t *pbfront,
        portable_samplepair_t *pbrear,
        portable_samplepair_t *pbcenter,
        int sampleCount,
        bool bcrossfading)
{
  int v6; // ebx
  portable_samplepair_t *v7; // esi
  portable_samplepair_t *v8; // eax
  dsp_t *v9; // edx
  int v10; // edi
  int v11; // edx
  _DWORD *v12; // ecx
  int v13; // edi
  portable_samplepair_t *v14; // eax
  int v15; // edx
  int *v16; // ecx
  int v17; // esi
  int v18; // ecx
  int *v19; // edi
  int v20; // edx
  int v21; // eax
  portable_samplepair_t *v22; // eax
  portable_samplepair_t *v23; // ecx
  portable_samplepair_t *v24; // edi
  int v25; // esi
  int Next; // ebx
  int v27; // esi
  int v28; // eax
  int v29; // ebx
  int v30; // ebx
  int v31; // eax
  portable_samplepair_t *v32; // ecx
  int v33; // edx
  int left; // edi
  int right; // esi
  int v36; // eax
  int v37; // eax
  int v38; // ebx
  dsp_t *v39; // edx
  int v40; // eax
  int v41; // eax
  int v42; // edi
  int v43; // edi
  int v44; // esi
  int v45; // ebx
  int v46; // ecx
  int v47; // edx
  int fcp; // [esp+Ch] [ebp-20h]
  int fcpa; // [esp+Ch] [ebp-20h]
  int fc; // [esp+10h] [ebp-1Ch]
  int rrp; // [esp+14h] [ebp-18h]
  int rrpa; // [esp+14h] [ebp-18h]
  int rr; // [esp+18h] [ebp-14h]
  int rlp; // [esp+1Ch] [ebp-10h]
  int frp; // [esp+20h] [ebp-Ch]
  int flp; // [esp+24h] [ebp-8h]
  int *p_right; // [esp+28h] [ebp-4h]
  portable_samplepair_t *pbfronta; // [esp+38h] [ebp+Ch]
  portable_samplepair_t *pbreara; // [esp+3Ch] [ebp+10h]
  portable_samplepair_t *pbrearb; // [esp+3Ch] [ebp+10h]
  portable_samplepair_t *pbrearc; // [esp+3Ch] [ebp+10h]
  portable_samplepair_t *pbcentera; // [esp+40h] [ebp+14h]
  portable_samplepair_t *pbcenterb; // [esp+40h] [ebp+14h]
  portable_samplepair_t *pbcenterc; // [esp+40h] [ebp+14h]
  int count; // [esp+44h] [ebp+18h]
  int counta; // [esp+44h] [ebp+18h]
  bool bcrossfading_3; // [esp+4Bh] [ebp+1Fh]

  v6 = sampleCount;
  v7 = pbfront;
  v8 = pbfront;
  if ( bcrossfading )
  {
    bcrossfading_3 = pdsp->bexpfade;
    if ( pdsp->ipset != 0 && pdsp->ipsetprev != 0 )
    {
      if ( sampleCount != 0 )
      {
        pbfronta = (portable_samplepair_t *)&pbrear->right;
        v22 = (portable_samplepair_t *)((char *)pbcenter - (char *)v7);
        v23 = (portable_samplepair_t *)((char *)pbrear - (char *)v7);
        v24 = v7;
        pbrearb = (portable_samplepair_t *)((char *)pbcenter - (char *)v7);
        pbcenterb = v23;
        while ( 1 )
        {
          count = v6 - 1;
          v25 = (51
               * (v24->left
                + v24->right
                + *(int *)((char *)&v24->left + (_DWORD)v22)
                + *(int *)((char *)&v24->left + (_DWORD)v23)
                + pbfronta->left)) >> 8;
          Next = PSET_GetNext(ppset: pdsp->ppset[0], x: v25);
          v27 = PSET_GetNext(ppset: pdsp->ppsetprev[0], x: v25);
          v28 = RMP_GetNext(prmp: &pdsp->xramp);
          v29 = (v28 * (Next - v27)) >> 12;
          if ( bcrossfading_3 )
            v29 = (v28 * v29) >> 12;
          v23 = pbcenterb;
          v30 = v27 + v29;
          v24->left = v30;
          v24->right = v30;
          *(int *)((char *)&v24->left + (_DWORD)pbcenterb) = v30;
          pbfronta->left = v30;
          *(int *)((char *)&v24->left + (_DWORD)pbrearb) = v30;
          ++v24;
          ++pbfronta;
          if ( count == 0 )
            break;
          v6 = count;
          v22 = pbrearb;
        }
      }
    }
    else if ( sampleCount != 0 )
    {
      p_right = &pbrear->right;
      v31 = (char *)pbcenter - (char *)pbfront;
      v32 = pbfront;
      v33 = (char *)pbrear - (char *)pbfront;
      pbrearc = (portable_samplepair_t *)((char *)pbcenter - (char *)pbfront);
      pbcenterc = (portable_samplepair_t *)v33;
      while ( 1 )
      {
        left = v32->left;
        right = v32->right;
        counta = v6 - 1;
        v36 = (51
             * (*p_right
              + right
              + v32->left
              + *(int *)((char *)&v32->left + v31)
              + *(int *)((char *)&v32->left + (_DWORD)pbcenterc))) >> 8;
        fcp = v36;
        if ( pdsp->ipset != 0 )
        {
          v37 = PSET_GetNext(ppset: pdsp->ppset[0], x: v36);
          v32 = pbfront;
          right = v37;
          v36 = fcp;
          left = right;
          rr = right;
          v38 = right;
          fc = right;
        }
        else
        {
          v38 = *(int *)((char *)&v32->left + (_DWORD)pbcenterc);
          rr = *p_right;
          fc = *(int *)((char *)&v32->left + (_DWORD)pbrearc);
        }
        v39 = pdsp;
        if ( pdsp->ipsetprev != 0 )
        {
          v40 = PSET_GetNext(ppset: pdsp->ppsetprev[0], x: v36);
          v39 = pdsp;
          flp = v40;
          frp = v40;
          rlp = v40;
          rrp = v40;
          fcpa = v40;
        }
        else
        {
          flp = v32->left;
          frp = v32->right;
          rlp = *(int *)((char *)&v32->left + (_DWORD)pbcenterc);
          rrp = *p_right;
          fcpa = *(int *)((char *)&v32->left + (_DWORD)pbrearc);
        }
        v41 = RMP_GetNext(prmp: &v39->xramp);
        v42 = (v41 * (left - flp)) >> 12;
        if ( bcrossfading_3 )
        {
          v43 = flp + ((v41 * v42) >> 12);
          v44 = frp + ((v41 * ((v41 * (right - frp)) >> 12)) >> 12);
          v45 = rlp + ((v41 * ((v41 * (v38 - rlp)) >> 12)) >> 12);
          rrpa = rrp + ((v41 * ((v41 * (rr - rrp)) >> 12)) >> 12);
          v46 = fcpa;
          v47 = (v41 * (fc - fcpa)) >> 12;
        }
        else
        {
          v43 = flp + v42;
          v44 = frp + ((v41 * (right - frp)) >> 12);
          v45 = rlp + ((v41 * (v38 - rlp)) >> 12);
          rrpa = rrp + ((v41 * (rr - rrp)) >> 12);
          v46 = fcpa;
          v47 = fc - fcpa;
        }
        pbfront->right = v44;
        pbfront->left = v43;
        *(int *)((char *)&pbfront->left + (_DWORD)pbcenterc) = v45;
        *p_right = rrpa;
        *(int *)((char *)&pbfront->left + (_DWORD)pbrearc) = v46 + ((v41 * v47) >> 12);
        ++pbfront;
        p_right += 2;
        if ( counta == 0 )
          break;
        v32 = pbfront;
        v6 = counta;
        v31 = (int)pbrearc;
      }
    }
  }
  else
  {
    v9 = pdsp;
    if ( pdsp->ipset != 0 )
    {
      if ( pdsp->ppset[0]->type > 1u )
      {
        if ( sampleCount != 0 )
        {
          v18 = (char *)pbcenter - (char *)pbfront;
          v19 = &pbrear->right;
          v20 = (char *)pbrear - (char *)pbfront;
          pbreara = (portable_samplepair_t *)((char *)pbcenter - (char *)pbfront);
          for ( pbcentera = (portable_samplepair_t *)v20; ; v20 = (int)pbcentera )
          {
            v21 = PSET_GetNext(
                    ppset: pdsp->ppset[0],
                    x: (51
                   * (v7->left + *(int *)((char *)&v7->left + v18)
                               + *(int *)((char *)&v7->left + v20)
                               + *v19
                               + v7->right)) >> 8);
            *(int *)((char *)&v7->left + (_DWORD)pbreara) = v21;
            v7->right = v21;
            v7->left = v21;
            *v19 = v21;
            *(int *)((char *)&pbcentera->left + (_DWORD)v7++) = v21;
            v19 += 2;
            if ( --v6 == 0 )
              break;
            v18 = (int)pbreara;
          }
        }
      }
      else
      {
        if ( sampleCount != 0 )
        {
          v10 = (char *)pbcenter - (char *)pbrear;
          v11 = (char *)pbrear - (char *)pbfront;
          while ( 1 )
          {
            v12 = (int *)((char *)&v8->left + v11);
            v13 = *(int *)((char *)&v8->right + v11) + *(int *)((char *)&v8->left + v11 + v10);
            ++v8;
            --v6;
            v8[-1].left = (51 * (v8[-1].right + *v12 + v8[-1].left + v13)) >> 8;
            if ( v6 == 0 )
              break;
            v10 = (char *)pbcenter - (char *)pbrear;
          }
          v6 = sampleCount;
          v9 = pdsp;
        }
        PSET_GetNextN(ppset: v9->ppset[0], pbuffer: pbfront, SampleCount: v6, op: 2);
        v14 = pbfront;
        if ( v6 != 0 )
        {
          v15 = (char *)pbrear - (char *)pbfront;
          do
          {
            v16 = (int *)((char *)&v14->left + v15);
            *v16 = v14->left;
            *(int *)((char *)&v14->right + v15) = v14->right;
            v17 = v14->left;
            ++v14;
            --v6;
            *(int *)((char *)v16 + (char *)pbcenter - (char *)pbrear) = v17;
          }
          while ( v6 != 0 );
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100253D0
// Name: void DSP_Process5To5(struct dsp_t __near *,struct portable_samplepair_t __near *,struct portable_samplepair_t __near *,struct portable_samplepair_t __near *,int,bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DSP_Process5To5(
        dsp_t *pdsp,
        portable_samplepair_t *pbfront,
        portable_samplepair_t *pbrear,
        portable_samplepair_t *pbcenter,
        int sampleCount,
        bool bcrossfading)
{
  dsp_t *v6; // edi
  portable_samplepair_t *v7; // esi
  int *v8; // ebx
  int v9; // eax
  portable_samplepair_t *v10; // ebx
  int v11; // eax
  int Next; // esi
  int v13; // edi
  int v14; // ebx
  int v15; // eax
  int v16; // esi
  int v17; // esi
  int v18; // edi
  int v19; // ebx
  int v20; // ecx
  int v21; // edx
  int fcpa; // [esp+Ch] [ebp-20h]
  int fcp; // [esp+Ch] [ebp-20h]
  int fca; // [esp+10h] [ebp-1Ch]
  int fc; // [esp+10h] [ebp-1Ch]
  int rrp; // [esp+14h] [ebp-18h]
  int rrpa; // [esp+14h] [ebp-18h]
  int v28; // [esp+18h] [ebp-14h]
  int rlp; // [esp+1Ch] [ebp-10h]
  int frp; // [esp+20h] [ebp-Ch]
  int flp; // [esp+24h] [ebp-8h]
  int *p_right; // [esp+28h] [ebp-4h]
  portable_samplepair_t *pbfronta; // [esp+38h] [ebp+Ch]
  portable_samplepair_t *pbfrontb; // [esp+38h] [ebp+Ch]
  int fra; // [esp+3Ch] [ebp+10h]
  portable_samplepair_t *fr; // [esp+3Ch] [ebp+10h]
  portable_samplepair_t *pbcentera; // [esp+40h] [ebp+14h]
  portable_samplepair_t *pbcenterb; // [esp+40h] [ebp+14h]
  int bexp; // [esp+48h] [ebp+1Ch]
  bool bexp_3; // [esp+4Bh] [ebp+1Fh]

  v6 = pdsp;
  if ( bcrossfading )
  {
    bexp_3 = pdsp->bexpfade;
    if ( sampleCount != 0 )
    {
      v10 = pbfront;
      p_right = &pbrear->right;
      v11 = (char *)pbrear - (char *)pbfront;
      fr = pbfront;
      pbcenterb = (portable_samplepair_t *)((char *)pbcenter - (char *)pbfront);
      pbfrontb = (portable_samplepair_t *)v11;
      while ( 1 )
      {
        --sampleCount;
        Next = PSET_GetNext(ppset: v6->ppset[0], x: v10->left);
        v13 = PSET_GetNext(ppset: v6->ppset[1], x: v10->right);
        v14 = PSET_GetNext(ppset: pdsp->ppset[2], x: *(int *)((char *)&pbfrontb->left + (_DWORD)v10));
        v28 = PSET_GetNext(ppset: pdsp->ppset[3], x: *p_right);
        fc = PSET_GetNext(ppset: pdsp->ppset[4], x: *(int *)((char *)&pbcenterb->left + (_DWORD)fr));
        flp = PSET_GetNext(ppset: pdsp->ppsetprev[0], x: fr->left);
        frp = PSET_GetNext(ppset: pdsp->ppsetprev[1], x: fr->right);
        rlp = PSET_GetNext(ppset: pdsp->ppsetprev[2], x: *(int *)((char *)&pbfrontb->left + (_DWORD)fr));
        rrp = PSET_GetNext(ppset: pdsp->ppsetprev[3], x: *p_right);
        fcp = PSET_GetNext(ppset: pdsp->ppsetprev[4], x: *(int *)((char *)&pbcenterb->left + (_DWORD)fr));
        v15 = RMP_GetNext(prmp: &pdsp->xramp);
        v16 = (v15 * (Next - flp)) >> 12;
        if ( bexp_3 )
        {
          v17 = flp + ((v15 * v16) >> 12);
          v18 = frp + ((v15 * ((v15 * (v13 - frp)) >> 12)) >> 12);
          v19 = rlp + ((v15 * ((v15 * (v14 - rlp)) >> 12)) >> 12);
          rrpa = rrp + ((v15 * ((v15 * (v28 - rrp)) >> 12)) >> 12);
          v20 = fcp;
          v21 = (v15 * (fc - fcp)) >> 12;
        }
        else
        {
          v17 = flp + v16;
          v18 = frp + ((v15 * (v13 - frp)) >> 12);
          v19 = rlp + ((v15 * (v14 - rlp)) >> 12);
          rrpa = rrp + ((v15 * (v28 - rrp)) >> 12);
          v20 = fcp;
          v21 = fc - fcp;
        }
        fr->left = v17;
        fr->right = v18;
        *(int *)((char *)&pbfrontb->left + (_DWORD)fr) = v19;
        *p_right = rrpa;
        *(int *)((char *)&pbcenterb->left + (_DWORD)fr++) = v20 + ((v15 * v21) >> 12);
        p_right += 2;
        if ( sampleCount == 0 )
          break;
        v10 = fr;
        v6 = pdsp;
      }
    }
  }
  else if ( pdsp->ipset != 0 )
  {
    if ( pdsp->ppset[0]->type <= 1u
      && pdsp->ppset[1]->type <= 1u
      && pdsp->ppset[2]->type <= 1u
      && FBatchPreset(ppset: pdsp->ppset[3]) )
    {
      PSET_GetNextN(ppset: pdsp->ppset[0], pbuffer: pbfront, SampleCount: sampleCount, op: 0);
      PSET_GetNextN(ppset: pdsp->ppset[1], pbuffer: pbfront, SampleCount: sampleCount, op: 1);
      PSET_GetNextN(ppset: pdsp->ppset[2], pbuffer: pbrear, SampleCount: sampleCount, op: 0);
      PSET_GetNextN(ppset: pdsp->ppset[3], pbuffer: pbrear, SampleCount: sampleCount, op: 1);
      PSET_GetNextN(ppset: pdsp->ppset[4], pbuffer: pbcenter, SampleCount: sampleCount, op: 0);
    }
    else if ( sampleCount != 0 )
    {
      v7 = pbfront;
      v8 = &pbrear->right;
      pbcentera = (portable_samplepair_t *)((char *)pbcenter - (char *)pbfront);
      pbfronta = (portable_samplepair_t *)((char *)pbrear - (char *)pbfront);
      do
      {
        --sampleCount;
        bexp = PSET_GetNext(ppset: pdsp->ppset[0], x: v7->left);
        fra = PSET_GetNext(ppset: pdsp->ppset[1], x: v7->right);
        fcpa = PSET_GetNext(ppset: pdsp->ppset[2], x: *(int *)((char *)&v7->left + (_DWORD)pbfronta));
        fca = PSET_GetNext(ppset: pdsp->ppset[3], x: *v8);
        v9 = PSET_GetNext(ppset: pdsp->ppset[4], x: *(int *)((char *)&v7->left + (_DWORD)pbcentera));
        v7->left = bexp;
        v7->right = fra;
        *(int *)((char *)&v7->left + (_DWORD)pbfronta) = fcpa;
        *v8 = fca;
        *(int *)((char *)&v7->left + (_DWORD)pbcentera) = v9;
        ++v7;
        v8 += 2;
      }
      while ( sampleCount != 0 );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10025730
// Name: int DSP_CountFilePresets(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl DSP_CountFilePresets(const char *pstart)
{
  int v1; // edi
  char v2; // bl
  const char *i; // esi
  bool v4; // zf
  bool binpreset; // [esp+13h] [ebp-1h]

  v1 = 0;
  binpreset = false;
  v2 = 0;
  for ( i = COM_Parse(data: pstart); strlen(com_token) != 0; i = COM_Parse(data: i) )
  {
    if ( com_token[0] == 123 )
    {
      if ( binpreset )
      {
        v2 = 0;
      }
      else
      {
        v2 = 1;
        ++v1;
        binpreset = true;
      }
    }
    else if ( com_token[0] == 125 )
    {
      if ( binpreset )
      {
        v4 = v2 == 0;
        v2 = 1;
        if ( !v4 )
          binpreset = false;
      }
      else
      {
        DevMsg(a1: "PARSE ERROR!!! dsp_presets.txt: unexpected '}' \n");
      }
    }
  }
  return v1;
}

//------------------------------------------------------------------------------
// Address: 0x100257D0
// Name: float DSP_LookupStringToken(char __near *,int)
// Source: json
//------------------------------------------------------------------------------
double __cdecl DSP_LookupStringToken(char *psz, int ipset)
{
  char v2; // al
  int v3; // esi
  dsp_stringmap_t *v4; // edi
  float v6; // [esp+Ch] [ebp+Ch]

  v2 = *psz;
  v6 = (float)ipset;
  if ( *psz == 43
    || v2 == 45
    || v2 == 48
    || v2 == 49
    || v2 == 50
    || v2 == 51
    || v2 == 52
    || v2 == 53
    || v2 == 54
    || v2 == 55
    || v2 == 56
    || v2 == 57 )
  {
    return atof(nptr: psz);
  }
  v3 = 0;
  if ( gcdsp_stringmap <= 0 )
  {
LABEL_17:
    DevMsg(a1: "DSP PARSE ERROR! token not found in dsp_presets.txt. Preset: %3.0f \n", v6);
    return 0.0;
  }
  else
  {
    v4 = gdsp_stringmap;
    while ( _V_stricmp(s1: v4->sz, s2: psz) != 0 )
    {
      ++v3;
      ++v4;
      if ( v3 >= gcdsp_stringmap )
        goto LABEL_17;
    }
    return (double)dword_10411F24[10 * v3];
  }
}

//------------------------------------------------------------------------------
// Address: 0x10025890
// Name: void DSP_FastReset(int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DSP_FastReset(int dspType)
{
  PreserveDSP_t *v1; // eax

  v1 = g_PreserveDSP;
  while ( v1->cvar != &dsp_player )
  {
    if ( (int)++v1 >= (int)&unk_10411EFC )
      return;
  }
  v1->oldvalue = (float)dspType;
}

//------------------------------------------------------------------------------
// Address: 0x100258C0
// Name: void DelayAllpass_Opt2<2,0>(int,int,int __near *,int __near * __near *,int,int,int __near *,int __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DelayAllpass_Opt2<2,0>(
        int *nDelaySize,
        int tdelay,
        int *psamps,
        int **ppsamp,
        int fbgain,
        int outgain,
        int *pIn,
        int *pOut,
        int nCount)
{
  int *v9; // ecx
  int v10; // edi
  int v12; // ebx
  int v13; // edx
  int v14; // eax
  int nDelaySizeP1; // [esp+8h] [ebp-4h]
  int *pSampsPDelaySize; // [esp+14h] [ebp+8h]

  v9 = *ppsamp;
  v10 = (int)nDelaySize + 1;
  pSampsPDelaySize = &psamps[(_DWORD)nDelaySize];
  nDelaySizeP1 = v10;
  if ( nCount <= 0 )
  {
    *ppsamp = v9;
  }
  else
  {
    v12 = fbgain;
    do
    {
      v13 = v9[tdelay - (v10 & (((char *)pSampsPDelaySize - (char *)&v9[tdelay]) >> 31))];
      v14 = *pIn + ((v12 * v13) >> 12);
      *v9 = v14;
      pIn += 2;
      v10 = nDelaySizeP1;
      v9 = &v9[(nDelaySizeP1 & (((char *)(v9 - 1) - (char *)psamps) >> 31)) - 1];
      v12 = fbgain;
      --nCount;
      *pOut++ += (outgain * (v13 + (-(fbgain * v14) >> 12))) >> 12;
    }
    while ( nCount > 0 );
    *ppsamp = v9;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10025970
// Name: void DelayAllpass_Opt2<2,1>(int,int,int __near *,int __near * __near *,int,int,int __near *,int __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DelayAllpass_Opt2<2,1>(
        int *nDelaySize,
        int tdelay,
        int *psamps,
        int **ppsamp,
        int fbgain,
        int outgain,
        int *pIn,
        int *pOut,
        int nCount)
{
  int *v10; // ecx
  int v11; // esi
  int v12; // edi
  int v13; // ebx
  int v14; // edx
  int v15; // eax
  int nDelaySizeP1; // [esp+8h] [ebp-4h]
  int *pSampsPDelaySize; // [esp+14h] [ebp+8h]

  v10 = *ppsamp;
  pSampsPDelaySize = &psamps[(_DWORD)nDelaySize];
  v11 = nCount;
  v12 = (int)nDelaySize + 1;
  nDelaySizeP1 = (int)nDelaySize + 1;
  if ( nCount <= 0 )
  {
    *ppsamp = v10;
  }
  else
  {
    v13 = fbgain;
    do
    {
      v14 = v10[tdelay - (v12 & (((char *)pSampsPDelaySize - (char *)&v10[tdelay]) >> 31))];
      v15 = *pIn + ((v13 * v14) >> 12);
      *v10 = v15;
      pIn += 2;
      v12 = nDelaySizeP1;
      v10 = &v10[(nDelaySizeP1 & (((char *)(v10 - 1) - (char *)psamps) >> 31)) - 1];
      v13 = fbgain;
      --v11;
      *pOut++ = (outgain * (v14 + (-(fbgain * v15) >> 12))) >> 12;
    }
    while ( v11 > 0 );
    *ppsamp = v10;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10025A20
// Name: void DelayAllpass_Opt2<1,1>(int,int,int __near *,int __near * __near *,int,int,int __near *,int __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DelayAllpass_Opt2<1,1>(
        int *nDelaySize,
        int tdelay,
        int *psamps,
        int **ppsamp,
        int fbgain,
        int outgain,
        int *pIn,
        int *pOut,
        int nCount)
{
  int **v9; // edx
  int *v10; // ecx
  int v11; // edi
  int *v12; // edx
  int v13; // ebx
  int v14; // esi
  int v15; // eax
  int nDelaySizeP1; // [esp+8h] [ebp-8h]
  int *pSampsPDelaySize; // [esp+18h] [ebp+8h]

  v9 = ppsamp;
  v10 = *ppsamp;
  v11 = (int)nDelaySize + 1;
  pSampsPDelaySize = &psamps[(_DWORD)nDelaySize];
  nDelaySizeP1 = v11;
  if ( nCount > 0 )
  {
    v12 = pOut;
    v13 = fbgain;
    do
    {
      v14 = v10[tdelay - (v11 & (((char *)pSampsPDelaySize - (char *)&v10[tdelay]) >> 31))];
      v15 = *(int *)((char *)v12 + (char *)pIn - (char *)pOut) + ((v13 * v14) >> 12);
      v11 = nDelaySizeP1;
      *v10 = v15;
      v10 = &v10[(nDelaySizeP1 & (((char *)(v10 - 1) - (char *)psamps) >> 31)) - 1];
      v13 = fbgain;
      --nCount;
      *v12++ = (outgain * (v14 + (-(fbgain * v15) >> 12))) >> 12;
    }
    while ( nCount > 0 );
    v9 = ppsamp;
  }
  *v9 = v10;
}

//------------------------------------------------------------------------------
// Address: 0x10025AC0
// Name: struct flt_t __near * FLT_Params(struct prc_t __near *)
// Source: json
//------------------------------------------------------------------------------
flt_t *__cdecl FLT_Params(prc_t *pprc)
{
  int v1; // xmm1_4
  float v2; // xmm2_4
  flt_t *v3; // ebx
  float v4; // xmm0_4
  int v5; // eax
  int v6; // eax
  int v7; // eax
  int v8; // edi
  float v9; // xmm0_4
  int i; // eax
  int v11; // edx
  flt_t *result; // eax
  flt_t *v13; // esi
  flt_t *v14; // eax
  int v15; // ecx
  float v16; // [esp-10h] [ebp-16Ch]
  float v17; // [esp-10h] [ebp-16Ch]
  int v18; // [esp+0h] [ebp-15Ch] BYREF
  int b_scaled[13]; // [esp+24h] [ebp-138h] BYREF
  int b_bp_scaled[13]; // [esp+58h] [ebp-104h] BYREF
  int b_bp[13]; // [esp+8Ch] [ebp-D0h] BYREF
  int a_bp[13]; // [esp+C0h] [ebp-9Ch] BYREF
  int b[13]; // [esp+F4h] [ebp-68h] BYREF
  int a[13]; // [esp+128h] [ebp-34h] BYREF
  char qual_3; // [esp+167h] [ebp+Bh]

  v1 = LODWORD(pprc->prm[4]);
  v2 = pprc->prm[0];
  v3 = nullptr;
  a[6] = LODWORD(pprc->prm[3]);
  a[12] = LODWORD(pprc->prm[1]);
  v4 = pprc->prm[2];
  a[4] = v1;
  *(float *)&a[7] = v4;
  memset(&a[8], 0, 16);
  qual_3 = 0;
  if ( v4 > 0.0 )
  {
    qual_3 = 1;
    a[5] = 0;
    FLT_Design_3db_IIR(cutoff: *(float *)&a[12], ftype: 1.0, pM: &a[8], pL: &a[9], a: &b_bp[4], b: &b_bp_scaled[4]);
    v5 = a[8];
    if ( a[8] >= 1 )
    {
      if ( a[8] > 12 )
        v5 = 12;
    }
    else
    {
      v5 = 1;
    }
    a[8] = v5;
    v6 = a[9];
    if ( a[9] >= 1 )
    {
      if ( a[9] > 12 )
        v6 = 12;
    }
    else
    {
      v6 = 1;
    }
    v2 = *(float *)&a[5];
    a[9] = v6;
    *(float *)&a[12] = *(float *)&a[7] + *(float *)&a[12];
  }
  FLT_Design_3db_IIR(cutoff: *(float *)&a[12], ftype: (float)(int)v2, pM: &a[10], pL: &a[11], a: &b[4], b: &a_bp[4]);
  if ( a[10] >= 1 )
  {
    a[12] = 12;
    if ( a[10] <= 12 )
      a[12] = a[10];
  }
  else
  {
    a[12] = 1;
  }
  v7 = a[11];
  if ( a[11] >= 1 )
  {
    a[11] = 12;
    if ( v7 <= 12 )
      a[11] = v7;
  }
  else
  {
    a[11] = 1;
  }
  v8 = (int)*(float *)&a[6];
  if ( (int)*(float *)&a[6] >= 0 )
  {
    if ( v8 > 3 )
      v8 = 3;
  }
  else
  {
    v8 = 0;
  }
  if ( qual_3 != 0 && v8 <= 1 )
    v8 = 1;
  v9 = *(float *)&a[4];
  a[7] = 0;
  a[10] = 0;
  for ( i = 0; i < 12; ++i )
  {
    v11 = (int)(float)((float)a_bp[i + 4] * v9);
    b_scaled[i + 4] = (int)(float)((float)b_bp_scaled[i + 4] * v9);
    *(int *)((char *)b_scaled + i * 4 + 28) = v11;
  }
  v16 = 1.0;
  if ( qual_3 != 0 )
    result = FLT_Alloc(N: v8, M: a[8], L: a[9], a: &b_bp[4], b: &b_scaled[4], gain: v16);
  else
    result = FLT_Alloc(N: v8, M: a[12], L: a[11], a: &b[4], b: &v18, gain: v16);
  v13 = result;
  if ( result != nullptr )
  {
    if ( v8 != 1 )
    {
      if ( v8 != 2 )
      {
        if ( v8 != 3 )
        {
LABEL_41:
          v15 = a[10];
          v13->pf2 = (flt_t *)a[7];
          v13->pf1 = v3;
          v13->pf3 = (flt_t *)v15;
          return v13;
        }
        v17 = 1.0;
        if ( qual_3 != 0 )
          v14 = FLT_Alloc(N: 0, M: a[8], L: a[9], a: &b_bp[4], b: &b_bp_scaled[4], gain: v17);
        else
          v14 = FLT_Alloc(N: 0, M: a[12], L: a[11], a: &b[4], b: &a_bp[4], gain: v17);
        a[10] = (int)v14;
      }
      a[7] = (int)FLT_Alloc(N: 0, M: a[12], L: a[11], a: &b[4], b: &a_bp[4], gain: 1.0);
    }
    v3 = FLT_Alloc(N: 0, M: a[12], L: a[11], a: &b[4], b: &a_bp[4], gain: 1.0);
    goto LABEL_41;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10025D80
// Name: void DLY_SetNormalizingGain(struct dly_t __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DLY_SetNormalizingGain(dly_t *pdly, int feedback)
{
  double v2; // st6
  double v3; // st7
  int b; // esi
  int v5; // xmm1_4
  float v6; // xmm0_4

  v2 = (double)feedback * 0.00024414062;
  v3 = 0.9990000128746033;
  if ( v2 <= 0.9990000128746033 )
    v3 = v2;
  b = pdly->b;
  if ( b == 0 )
    b = 4096;
  v5 = 1149239296;
  v6 = (float)(int)(1.0 / (1.0 / (1.0 - v3)) * 4096.0) * 4.0;
  if ( v6 < 1024.0 || (v5 = 1166016512, v6 > 4096.0) )
    v6 = *(float *)&v5;
  pdly->b = (int)(float)((float)((float)b * 0.00024414062) * v6);
}

//------------------------------------------------------------------------------
// Address: 0x10025E20
// Name: struct dly_t __near * DLY_AllocLP(int,int,int,int,int,int,int __near *,int __near *)
// Source: json
//------------------------------------------------------------------------------
dly_t *__cdecl DLY_AllocLP(int D, int a, int b, int type, int M, int L, int *fa, int *fb)
{
  dly_t *v8; // esi
  int v9; // edi
  dly_t *v10; // eax
  flt_t *v12; // eax
  int *v13; // eax
  int *v14; // ebx
  int v15; // eax
  int v16; // ebx

  v8 = nullptr;
  v9 = 0;
  v10 = dlys;
  while ( v10->fused )
  {
    ++v10;
    ++v9;
    if ( (int)v10 >= (int)flts )
      goto LABEL_7;
  }
  v8 = &dlys[v9];
  if ( v8 != nullptr )
    _V_memset(dest: &dlys[v9], fill: 0, count: 72);
LABEL_7:
  if ( v9 == 128 )
  {
    DevMsg(a1: "DSP: Warning, failed to allocate delay line.\n");
    return nullptr;
  }
  else
  {
    if ( type == 5 || type == 6 )
      b = (int)(float)((float)b * 0.25);
    if ( (type == 4 || type == 2 || type == 5)
      && (v12 = FLT_Alloc(N: 0, M, L, a: fa, b: fb, gain: (float)a * 0.00024414062), v8->pflt = v12, v12 == nullptr) )
    {
      DevMsg(a1: "DSP: Warning, failed to allocate filter for delay line.\n");
      return nullptr;
    }
    else
    {
      v13 = (int *)MemAlloc_Alloc(nSize: (unsigned __int64)(unsigned int)(D + 1) >> 30 != 0 ? -1 : 4 * (D + 1));
      v14 = v13;
      if ( v13 != nullptr )
      {
        _V_memset(dest: v13, fill: 0, count: 4 * D + 4);
        v15 = type;
        v8->p = v14;
        v8->w = v14;
        v8->type = type;
        v8->D = D;
        v8->t = D;
        v8->tnew = D;
        v8->xf = 0;
        v8->D0 = D;
        v16 = a;
        if ( a >= 4095 )
          v16 = 4095;
        v8->a = v16;
        v8->b = b;
        v8->fused = true;
        if ( type == 3 || type == 4 )
        {
          v8->a = 0;
          v8->b = 4096;
        }
        else
        {
          DLY_SetNormalizingGain(pdly: v8, feedback: a);
          v15 = type;
        }
        if ( v15 == 5 || v15 == 6 )
          DLY_ChangeTaps(pdly: v8, t0: D, t1: D, t2: D, t3: D);
        return v8;
      }
      else
      {
        _Warning(a1: "Sound DSP: Failed to lock.\n");
        FLT_Free(pf: v8->pflt);
        return nullptr;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10025FD0
// Name: struct dly_t __near * DLY_Params(struct prc_t __near *)
// Source: json
//------------------------------------------------------------------------------
dly_t *__cdecl DLY_Params(prc_t *pprc)
{
  long double v1; // st7
  float v2; // xmm0_4
  long double v3; // st7
  float v4; // xmm0_4
  float v5; // xmm0_4
  int v6; // edi
  dly_t *v7; // ebx
  long double v8; // st7
  long double v9; // st7
  int v10; // ecx
  float v11; // xmm1_4
  flt_t *v12; // eax
  flt_t *v13; // esi
  prc_t prcf; // [esp+8h] [ebp-80h] BYREF
  float t1; // [esp+64h] [ebp-24h]
  float t2; // [esp+68h] [ebp-20h]
  float t3; // [esp+6Ch] [ebp-1Ch]
  int a; // [esp+70h] [ebp-18h]
  int b; // [esp+74h] [ebp-14h]
  float qwidth; // [esp+78h] [ebp-10h]
  float ftype; // [esp+7Ch] [ebp-Ch]
  float cutoff; // [esp+80h] [ebp-8h]
  float qual; // [esp+84h] [ebp-4h]
  int D; // [esp+90h] [ebp+8h]

  v1 = fabs(pprc->prm[8]);
  ftype = pprc->prm[4];
  v2 = pprc->prm[5];
  t1 = v1;
  v3 = pprc->prm[9];
  cutoff = v2;
  v4 = pprc->prm[6];
  t2 = fabs(v3);
  qwidth = v4;
  v5 = pprc->prm[7];
  v6 = (int)pprc->prm[0];
  t3 = fabs(pprc->prm[10]);
  v7 = nullptr;
  v8 = fabs(pprc->prm[1]);
  qual = v5;
  v9 = v8 * 44100.0 * 0.001;
  v10 = (int)(float)(pprc->prm[2] * 4096.0);
  v11 = pprc->prm[3] * 4096.0;
  D = (int)v9;
  a = v10;
  b = (int)v11;
  switch ( v6 )
  {
    case 0:
    case 1:
    case 3:
    case 6:
      v7 = DLY_AllocLP(D: (int)v9, a: v10, b: (int)v11, type: v6, M: 0, L: 0, fa: nullptr, fb: nullptr);
      goto LABEL_6;
    case 2:
    case 4:
    case 5:
      prcf.prm[3] = qual;
      prcf.prm[1] = cutoff;
      prcf.prm[0] = ftype;
      prcf.prm[2] = qwidth;
      prcf.prm[4] = 1.0;
      v12 = FLT_Params(pprc: &prcf);
      v13 = v12;
      if ( v12 != nullptr )
      {
        v7 = DLY_AllocLP(D, a, b, type: v6, M: v12->M, L: v12->L, fa: v12->a, fb: v12->b);
        FLT_Free(pf: v13);
LABEL_6:
        if ( v7 != nullptr && (v6 == 5 || v6 == 6) )
          DLY_ChangeTaps(
            pdly: v7,
            t0: D,
            t1: (int)(float)((float)(t1 * 44100.0) * 0.001),
            t2: (int)(float)((float)(t2 * 44100.0) * 0.001),
            t3: (int)(float)((float)(t3 * 44100.0) * 0.001));
        return v7;
      }
      else
      {
        DevMsg(a1: "DSP: Warning, failed to allocate filter.\n");
        return nullptr;
      }
    default:
      return v7;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100261B0
// Name: struct mdy_t __near * MDY_Params(struct prc_t __near *)
// Source: json
//------------------------------------------------------------------------------
dly_t *__cdecl MDY_Params(prc_t *pprc)
{
  float v2; // xmm1_4
  dly_t *result; // eax
  float v4; // [esp+0h] [ebp-Ch]
  float v5; // [esp+4h] [ebp-8h]
  float v6; // [esp+8h] [ebp-4h]
  float depth; // [esp+14h] [ebp+8h]

  v2 = pprc->prm[8];
  v4 = pprc->prm[10] * 0.001;
  depth = 0.0;
  if ( v2 != 0.0 )
    depth = 1.0 / v2;
  v5 = pprc->prm[9];
  v6 = pprc->prm[11];
  result = DLY_Params(pprc);
  if ( result != nullptr )
    return (dly_t *)MDY_Alloc(pdly: result, ramptime: v4, modtime: depth, depth: v5, mix: v6);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10026240
// Name: struct rva_t __near * RVA_Alloc(int __near *,int __near *,int __near *,int,struct flt_t __near *,int,float,float,float)
// Source: json
//------------------------------------------------------------------------------
rva_t *__cdecl RVA_Alloc(
        rva_t *D,
        char *a,
        char *b,
        flt_t *m,
        flt_t *pflt,
        int fparallel,
        float fmoddly,
        float fmodrate,
        float ftaps)
{
  int v9; // ecx
  rva_t *v10; // eax
  rva_t *v12; // esi
  flt_t *v13; // edi
  int v14; // edx
  int *p_fused; // edi
  int v16; // ecx
  int v17; // eax
  int v18; // esi
  double v19; // st7
  double v20; // st6
  double v21; // st4
  double v22; // st4
  double v23; // st7
  dly_t **pdlys; // edi
  int v25; // ebx
  double v26; // st6
  float v27; // xmm0_4
  double v28; // st6
  double v29; // st7
  int v30; // eax
  dly_t **v31; // ecx
  flt_t *pf1; // eax
  flt_t *pf2; // eax
  flt_t *pf3; // eax
  int v35; // [esp-1Ch] [ebp-44h]
  float v36; // [esp-1Ch] [ebp-44h]
  int L; // [esp-18h] [ebp-40h]
  float v38; // [esp-18h] [ebp-40h]
  int *v39; // [esp-14h] [ebp-3Ch]
  int *v40; // [esp-10h] [ebp-38h]
  float ramptime; // [esp+0h] [ebp-28h]
  float ramptimea; // [esp+0h] [ebp-28h]
  double modtime; // [esp+4h] [ebp-24h]
  float modtime_4; // [esp+8h] [ebp-20h]
  rva_t *v45; // [esp+14h] [ebp-14h]
  flt_t *v46; // [esp+18h] [ebp-10h]
  dly_t **depth; // [esp+1Ch] [ebp-Ch]
  flt_t *v48; // [esp+20h] [ebp-8h]

  v48 = nullptr;
  v9 = 0;
  v10 = &rvas[1];
  while ( v10[-1].fused )
  {
    if ( !v10->fused )
    {
      ++v9;
      break;
    }
    if ( !v10[1].fused )
    {
      v9 += 2;
      break;
    }
    if ( !v10[2].fused )
    {
      v9 += 3;
      break;
    }
    v10 += 4;
    v9 += 4;
    if ( (int)v10 >= (int)&mdys[1].rmp_interp.nEndRampTimeInMs )
      break;
  }
  if ( v9 == 64 )
  {
    DevMsg(a1: "DSP: Warning, failed to allocate reverb.\n");
    return nullptr;
  }
  v12 = &rvas[v9];
  v45 = v12;
  if ( pflt != nullptr && fparallel == 0 )
  {
    v13 = FLT_Alloc(N: 0, M: pflt->M, L: pflt->L, a: pflt->a, b: pflt->b, gain: 1.0);
    v48 = v13;
    if ( v13 == nullptr )
    {
      DevMsg(a1: "DSP: Warning, failed to allocate flt for reverb.\n");
      return nullptr;
    }
    v13->pf1 = FLT_Alloc(N: 0, M: pflt->M, L: pflt->L, a: pflt->a, b: pflt->b, gain: 1.0);
    v13->N = 1;
  }
  v14 = (int)m;
  if ( (int)m > 0 )
  {
    p_fused = (int *)&D->fused;
    v16 = b - a;
    v17 = a - (char *)D;
    depth = v12->pdlys;
    v46 = m;
    while ( 1 )
    {
      if ( pflt != nullptr && fparallel != 0 )
        v18 = 2 * (*(int *)((char *)p_fused + v17) < 0) + 2;
      else
        v18 = ftaps > 0.0 ? 6 : 0;
      if ( v18 == 2 )
      {
        if ( ftaps > 0.0 )
          v18 = 5;
      }
      else if ( v18 != 4 && v18 != 5 )
      {
        v40 = nullptr;
        v39 = nullptr;
        L = 0;
        v35 = 0;
        goto LABEL_29;
      }
      v40 = pflt->b;
      v39 = pflt->a;
      L = pflt->L;
      v35 = pflt->M;
LABEL_29:
      *depth = DLY_AllocLP(
                 D: *p_fused,
                 a: abs32(*(int *)((char *)p_fused + v17)),
                 b: *(int *)((char *)p_fused + v17 + v16),
                 type: v18,
                 M: v35,
                 L,
                 fa: v39,
                 fb: v40);
      if ( v18 == 5 || v18 == 6 )
      {
        v19 = (double)*p_fused;
        v20 = ftaps;
        v21 = (1.0 - 3.141592 * ftaps) * v19;
        if ( v21 < 220.0 )
          v21 = 220.0;
        ramptime = v21;
        v22 = (1.0 - v20 * 1.697043) * v19;
        if ( v22 < 308.0 )
          v22 = 308.0;
        v23 = v19 * (1.0 - v20 * 0.9632500000000001);
        if ( v23 < 441.0 )
          v23 = 441.0;
        modtime_4 = v22;
        DLY_ChangeTaps(pdly: *depth, t0: (int)ramptime, t1: (int)modtime_4, t2: (int)v23, t3: *p_fused);
      }
      ++depth;
      ++p_fused;
      v46 = (flt_t *)((char *)v46 - 1);
      if ( v46 == nullptr )
      {
        v14 = (int)m;
        v12 = v45;
        break;
      }
      v17 = a - (char *)D;
      v16 = b - a;
    }
  }
  if ( fmoddly > 0.0 )
  {
    if ( v14 > 0 )
    {
      pdlys = v12->pdlys;
      v25 = v14;
      modtime = fmoddly * 0.001;
      do
      {
        v26 = (double)(*pdlys)->D * 0.000022675737;
        if ( modtime / v26 >= 0.01 )
        {
          if ( modtime / v26 <= 0.99 )
          {
            ramptimea = modtime / v26;
            v27 = ramptimea;
          }
          else
          {
            v27 = 0.99000001;
          }
        }
        else
        {
          v27 = 0.0099999998;
        }
        v28 = v26 * fmodrate;
        v29 = 0.5 * v28;
        if ( v29 >= 0.02 )
          v29 = 0.02;
        v38 = v28;
        v36 = v29;
        pdlys[12] = (dly_t *)MDY_Alloc(pdly: *pdlys, ramptime: v36, modtime: v38, depth: v27, mix: 1.0);
        ++pdlys;
        --v25;
      }
      while ( v25 != 0 );
      v14 = (int)m;
    }
    v12->fmoddly = true;
  }
  v30 = 0;
  if ( v14 <= 0 )
  {
LABEL_60:
    v12->fparallel = fparallel;
    v12->fused = true;
    v12->m = v14;
    v12->pflt = v48;
    return v12;
  }
  else
  {
    v31 = v12->pdlys;
    while ( *v31 != nullptr )
    {
      ++v30;
      ++v31;
      if ( v30 >= v14 )
        goto LABEL_60;
    }
    if ( v48 != nullptr )
    {
      pf1 = v48->pf1;
      if ( pf1 != nullptr )
        _V_memset(dest: pf1, fill: 0, count: 184);
      pf2 = v48->pf2;
      if ( pf2 != nullptr )
        _V_memset(dest: pf2, fill: 0, count: 184);
      pf3 = v48->pf3;
      if ( pf3 != nullptr )
        _V_memset(dest: pf3, fill: 0, count: 184);
      _V_memset(dest: v48, fill: 0, count: 184);
    }
    RVA_Free(prva: v12);
    DevMsg(a1: "DSP: Warning, failed to allocate delay for reverb.\n");
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10026650
// Name: struct rva_t __near * RVA_Params(struct prc_t __near *)
// Source: json
//------------------------------------------------------------------------------
rva_t *__cdecl RVA_Params(prc_t *pprc)
{
  float v2; // xmm4_4
  float v3; // xmm7_4
  float v4; // xmm2_4
  float v5; // xmm0_4
  float v6; // xmm3_4
  float v7; // xmm1_4
  int v8; // xmm5_4
  float v9; // xmm6_4
  long double v10; // st7
  float v11; // xmm4_4
  int v12; // xmm7_4
  float v13; // xmm2_4
  int v14; // xmm4_4
  int v15; // edi
  int v16; // esi
  long double v17; // st7
  double v18; // st6
  long double v19; // st5
  float v20; // xmm2_4
  long double v21; // st4
  long double v22; // st5
  flt_t *v23; // esi
  rva_t *v24; // edi
  int v26; // [esp+0h] [ebp-12Ch] BYREF
  int b[12]; // [esp+14h] [ebp-118h] BYREF
  prc_t prcf; // [esp+44h] [ebp-E8h] BYREF
  int a[12]; // [esp+A0h] [ebp-8Ch] BYREF
  int D[12]; // [esp+D0h] [ebp-5Ch] BYREF
  float rgd[3]; // [esp+100h] [ebp-2Ch]
  float rgfb[3]; // [esp+10Ch] [ebp-20h]
  float gain; // [esp+118h] [ebp-14h]
  float ftaps; // [esp+11Ch] [ebp-10h]
  int fmoddly; // [esp+120h] [ebp-Ch]
  int cutoff; // [esp+124h] [ebp-8h]
  int size_min; // [esp+128h] [ebp-4h]
  float depth; // [esp+134h] [ebp+8h]

  v2 = pprc->prm[5];
  v3 = pprc->prm[15];
  v4 = pprc->prm[3];
  *(float *)&cutoff = fabs(pprc->prm[9]);
  v5 = pprc->prm[2];
  v6 = pprc->prm[1];
  v7 = pprc->prm[0];
  *(float *)&fmoddly = fabs(pprc->prm[10]);
  v8 = LODWORD(pprc->prm[13]);
  v9 = pprc->prm[14];
  v10 = fabs(pprc->prm[11]);
  rgfb[1] = v2;
  *(float *)&size_min = v10;
  gain = pprc->prm[6];
  rgfb[0] = pprc->prm[7];
  v11 = pprc->prm[8];
  rgd[2] = v3;
  *(float *)&v12 = 1.0;
  depth = v4;
  v13 = pprc->prm[4];
  ftaps = v11;
  v14 = LODWORD(pprc->prm[12]);
  rgfb[2] = v6;
  rgd[1] = v13;
  if ( v5 < 1.0 || (*(float *)&v12 = 12.0, v5 > 12.0) )
    v5 = *(float *)&v12;
  v15 = (int)v5;
  if ( (int)*(float *)&cutoff != 0 || (int)*(float *)&size_min != 0 || (int)*(float *)&fmoddly != 0 )
  {
    if ( v15 >= 3 )
    {
      if ( (unsigned int)(v15 - 4) > 1 )
      {
        if ( (unsigned int)(v15 - 7) > 1 )
        {
          if ( v15 > 9 )
            v15 = 12;
        }
        else
        {
          v15 = 9;
        }
      }
      else
      {
        v15 = 6;
      }
    }
    else
    {
      v15 = 3;
    }
    D[7] = cutoff;
    D[8] = fmoddly;
    D[10] = v14;
    D[11] = v8;
    D[9] = size_min;
    rgd[0] = v9;
    RVA_ConstructDelays(
      rgd: (float *)&D[7],
      rgf: (float *)&D[10],
      m: v15,
      D: &a[7],
      a: (int *)&prcf.pfnGetNext,
      b: &v26,
      gain: rgd[1],
      feedback: depth);
  }
  else
  {
    v16 = 0;
    if ( v15 > 0 )
    {
      v17 = depth;
      v18 = 4096.0;
      v19 = 4091.904;
      v20 = (float)(v13 * 4096.0) / (float)v15;
      *(float *)&cutoff = (float)(v7 - v6) / (float)v15;
      while ( 1 )
      {
        size_min = (int)(float)((float)((float)((float)(int)(float)((float)v16 * *(float *)&cutoff) + v6) * 44100.0)
                              * 0.001);
        a[v16 + 7] = size_min;
        if ( v16 != 0 )
        {
          v18 = 4096.0;
          v22 = pow(v17, (double)size_min / (double)a[7]) * 4096.0;
          if ( v22 > 4091.904 )
            v22 = 4091.904;
          *((_DWORD *)&prcf.pfnGetNext + v16) = (int)v22;
          v19 = 4091.904;
          v17 = depth;
        }
        else
        {
          v21 = v17 * v18;
          if ( v17 * v18 > v19 )
            v21 = v19;
          prcf.pfnGetNext = (int (__cdecl *)(void *, int))(int)v21;
        }
        b[v16++ + 3] = (int)v20;
        if ( v16 >= v15 )
          break;
        v6 = rgfb[2];
      }
    }
  }
  v23 = nullptr;
  if ( rgfb[1] != 0.0 )
  {
    b[11] = 0;
    b[8] = 0;
    b[10] = 0;
    *(float *)&b[9] = rgfb[1];
    prcf.type = 1065353216;
    v23 = FLT_Params(pprc: (prc_t *)&b[7]);
  }
  v24 = RVA_Alloc(
          D: (rva_t *)&a[7],
          a: (char *)&prcf.pfnGetNext,
          b: (char *)&v26,
          m: (flt_t *)v15,
          pflt: v23,
          fparallel: (int)gain,
          fmoddly: rgfb[0],
          fmodrate: ftaps,
          ftaps: rgd[2]);
  FLT_Free(pf: v23);
  return v24;
}

//------------------------------------------------------------------------------
// Address: 0x10026950
// Name: struct dfr_t __near * DFR_Alloc(int __near *,int __near *,int __near *,int)
// Source: json
//------------------------------------------------------------------------------
dfr_t *__cdecl DFR_Alloc(int *D, int *a, int *b, int n)
{
  int v4; // ecx
  dfr_t *v5; // eax
  int v7; // ecx
  bool v8; // zf
  dfr_t *v9; // ecx
  dfr_t *v10; // esi
  int v11; // edx
  int *v12; // ebx
  int v13; // eax
  int v14; // ecx
  int v15; // edi
  dly_t *v16; // esi
  int v17; // ecx
  dly_t *v18; // eax
  void *v19; // ebx
  flt_t *pflt; // esi
  flt_t *pf1; // eax
  flt_t *pf2; // eax
  flt_t *pf3; // eax
  int v24; // eax
  int v25; // edi
  double v26; // st6
  double v27; // st7
  int v28; // xmm1_4
  float v29; // xmm0_4
  int v30; // eax
  dly_t **v31; // ecx
  dfr_t *pdfr; // [esp+0h] [ebp-24h]
  int v33; // [esp+4h] [ebp-20h]
  int v34; // [esp+10h] [ebp-14h]
  dly_t **pdlys; // [esp+14h] [ebp-10h]
  int v36; // [esp+18h] [ebp-Ch]
  int *v37; // [esp+1Ch] [ebp-8h]
  int v38; // [esp+20h] [ebp-4h]

  v4 = 0;
  v5 = &dfrs[1];
  while ( v5[-1].fused )
  {
    if ( !v5->fused )
    {
      ++v4;
      break;
    }
    if ( !v5[1].fused )
    {
      v4 += 2;
      break;
    }
    if ( !v5[2].fused )
    {
      v4 += 3;
      break;
    }
    v5 += 4;
    v4 += 4;
    if ( (int)v5 >= (int)&rvas[1].pdlys[1] )
      break;
  }
  if ( v4 == 64 )
  {
    DevMsg(a1: "DSP: Warning, failed to allocate diffusor.\n");
    return nullptr;
  }
  else
  {
    v7 = v4;
    v8 = &dfrs[v7] == nullptr;
    v9 = &dfrs[v7];
    v10 = v9;
    pdfr = v9;
    if ( !v8 )
      _V_memset(dest: v9, fill: 0, count: 136);
    v11 = n;
    if ( n > 0 )
    {
      v12 = D;
      v13 = (char *)a - (char *)D;
      v14 = (char *)b - (char *)D;
      v37 = D;
      pdlys = v10->pdlys;
      v34 = n;
      while ( 1 )
      {
        v15 = *v12;
        v36 = *(int *)((char *)v12 + v13);
        v33 = *(int *)((char *)v12 + v14);
        v16 = nullptr;
        v17 = 0;
        v18 = dlys;
        while ( v18->fused )
        {
          ++v18;
          ++v17;
          if ( (int)v18 >= (int)flts )
            goto LABEL_24;
        }
        v16 = &dlys[v17];
        v38 = v17;
        if ( v16 != nullptr )
        {
          _V_memset(dest: &dlys[v17], fill: 0, count: 72);
          v17 = v38;
        }
LABEL_24:
        if ( v17 == 128 )
        {
          DevMsg(a1: "DSP: Warning, failed to allocate delay line.\n");
          v16 = nullptr;
        }
        else
        {
          v19 = MemAlloc_Alloc(nSize: (unsigned __int64)(unsigned int)(v15 + 1) >> 30 != 0 ? -1 : 4 * (v15 + 1));
          if ( v19 != nullptr )
          {
            _V_memset(dest: v19, fill: 0, count: 4 * v15 + 4);
            v24 = v36;
            v16->type = 1;
            v16->D = v15;
            v16->t = v15;
            v16->tnew = v15;
            v16->xf = 0;
            v16->D0 = v15;
            v16->p = (int *)v19;
            v16->w = (int *)v19;
            if ( v36 >= 4095 )
              v24 = 4095;
            v25 = v33;
            v16->a = v24;
            v16->b = v33;
            v16->fused = true;
            v26 = (double)v36 * 0.00024414062;
            v27 = 0.9990000128746033;
            if ( v26 <= 0.9990000128746033 )
              v27 = v26;
            if ( v33 == 0 )
              v25 = 4096;
            v28 = 1149239296;
            v29 = (float)(int)(1.0 / (1.0 / (1.0 - v27)) * 4096.0) * 4.0;
            if ( v29 < 1024.0 || (v28 = 1166016512, v29 > 4096.0) )
              v29 = *(float *)&v28;
            v16->b = (int)(float)((float)((float)v25 * 0.00024414062) * v29);
          }
          else
          {
            _Warning(a1: "Sound DSP: Failed to lock.\n");
            pflt = v16->pflt;
            if ( pflt != nullptr )
            {
              pf1 = pflt->pf1;
              if ( pf1 != nullptr )
                _V_memset(dest: pf1, fill: 0, count: 184);
              pf2 = pflt->pf2;
              if ( pf2 != nullptr )
                _V_memset(dest: pf2, fill: 0, count: 184);
              pf3 = pflt->pf3;
              if ( pf3 != nullptr )
                _V_memset(dest: pf3, fill: 0, count: 184);
              _V_memset(dest: pflt, fill: 0, count: 184);
            }
            v16 = nullptr;
          }
          v12 = v37;
        }
        *pdlys = v16;
        ++v12;
        v8 = v34-- == 1;
        v37 = v12;
        ++pdlys;
        if ( v8 )
          break;
        v13 = (char *)a - (char *)D;
        v14 = (char *)b - (char *)D;
      }
      v11 = n;
      v10 = pdfr;
    }
    v30 = 0;
    if ( v11 <= 0 )
    {
LABEL_53:
      v10->fused = true;
      v10->n = v11;
      return v10;
    }
    else
    {
      v31 = v10->pdlys;
      while ( *v31 != nullptr )
      {
        ++v30;
        ++v31;
        if ( v30 >= v11 )
          goto LABEL_53;
      }
      DFR_Free(pdfr: v10);
      DevMsg(a1: "DSP: Warning, failed to allocate delay for diffusor.\n");
      return nullptr;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10026C50
// Name: struct dfr_t __near * DFR_Params(struct prc_t __near *)
// Source: json
//------------------------------------------------------------------------------
dfr_t *__cdecl DFR_Params(prc_t *pprc)
{
  float v2; // xmm0_4
  int v3; // xmm2_4
  float v4; // xmm1_4
  float v5; // xmm0_4
  int v6; // ebx
  int v7; // esi
  double v8; // st4
  int D[16]; // [esp+0h] [ebp-C4h] BYREF
  int a[16]; // [esp+40h] [ebp-84h] BYREF
  int b[16]; // [esp+80h] [ebp-44h] BYREF
  float size; // [esp+C0h] [ebp-4h]
  float feedback; // [esp+CCh] [ebp+8h]

  v2 = pprc->prm[0];
  *(float *)&v3 = 1.0;
  feedback = pprc->prm[2];
  v4 = pprc->prm[3];
  size = v2;
  v5 = pprc->prm[1];
  if ( v4 == 0.0 )
    v4 = 1.0;
  if ( v5 < 1.0 || (*(float *)&v3 = 8.0, v5 > 8.0) )
    v5 = *(float *)&v3;
  v6 = (int)v5;
  v7 = 0;
  if ( (int)v5 > 0 )
  {
    memset32(b, (int)(float)(v4 * 4096.0), v6);
    do
    {
      v8 = dfrfbs[v7] * 4096.0 * feedback;
      D[v7] = 44100 * (int)(float)(dfrdlys[v7] * size) / 1000;
      if ( v8 > 4091.904 )
        v8 = 4091.904;
      a[v7++] = (int)v8;
    }
    while ( v7 < v6 );
  }
  return DFR_Alloc(D, a, b, n: v6);
}

//------------------------------------------------------------------------------
// Address: 0x10026D60
// Name: void LFOWAV_InitAll(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl LFOWAV_InitAll()
{
  dly_t *v0; // esi
  int v1; // edi
  dly_t *v2; // eax
  int *v3; // eax
  int *v4; // edi
  flt_t *pflt; // esi
  flt_t *pf1; // eax
  flt_t *pf2; // eax
  flt_t *pf3; // eax
  int *v9; // esi
  int *w; // [esp-10h] [ebp-1Ch]
  int i; // [esp+8h] [ebp-4h]

  _V_memset(dest: lfowavs, fill: 0, count: 72);
  for ( i = 0; i < 9; ++i )
  {
    v0 = nullptr;
    v1 = 0;
    v2 = dlys;
    while ( v2->fused )
    {
      ++v2;
      ++v1;
      if ( (int)v2 >= (int)flts )
        goto LABEL_8;
    }
    v0 = &dlys[v1];
    if ( v0 != nullptr )
      _V_memset(dest: &dlys[v1], fill: 0, count: 72);
LABEL_8:
    if ( v1 == 128 )
    {
      DevMsg(a1: "DSP: Warning, failed to allocate delay line.\n");
      v0 = nullptr;
    }
    else
    {
      v3 = (int *)MemAlloc_Alloc(nSize: 0x804u);
      v4 = v3;
      if ( v3 != nullptr )
      {
        _V_memset(dest: v3, fill: 0, count: 2052);
        v0->type = 0;
        v0->D = 512;
        v0->t = 512;
        v0->tnew = 512;
        v0->xf = 0;
        v0->D0 = 512;
        v0->p = v4;
        v0->w = v4;
        v0->a = 0;
        v0->b = 0;
        v0->fused = true;
        DLY_SetNormalizingGain(pdly: v0, feedback: 0);
      }
      else
      {
        _Warning(a1: "Sound DSP: Failed to lock.\n");
        pflt = v0->pflt;
        if ( pflt != nullptr )
        {
          pf1 = pflt->pf1;
          if ( pf1 != nullptr )
            _V_memset(dest: pf1, fill: 0, count: 184);
          pf2 = pflt->pf2;
          if ( pf2 != nullptr )
            _V_memset(dest: pf2, fill: 0, count: 184);
          pf3 = pflt->pf3;
          if ( pf3 != nullptr )
            _V_memset(dest: pf3, fill: 0, count: 184);
          _V_memset(dest: pflt, fill: 0, count: 184);
        }
        v0 = nullptr;
      }
    }
    w = v0->w;
    dword_10454424[2 * i] = (int)v0;
    lfowavs[i].type = i;
    LFOWAV_Fill(w, count: 512, type: i);
  }
  v9 = dword_10454424;
  do
  {
    if ( *v9 == 0 )
      LFOWAV_FreeAll();
    v9 += 2;
  }
  while ( (int)v9 < (int)&dfrs[0].n );
}

//------------------------------------------------------------------------------
// Address: 0x10026F00
// Name: struct ptc_t __near * PTC_Alloc(float,float,float)
// Source: json
//------------------------------------------------------------------------------
ptc_t *__cdecl PTC_Alloc(float timeslice, float timexfade, float fstep)
{
  int v3; // ecx
  ptc_t *v4; // eax
  ptc_t *v6; // edi
  double v7; // st7
  long double v8; // st6
  double v9; // st5
  long double v10; // st7
  long double v11; // rt2
  long double v12; // st6
  long double v13; // st7
  long double v14; // st3
  long double v15; // st5
  long double v16; // rt1
  long double v17; // st5
  long double v18; // st7
  int v19; // eax
  dly_t *v20; // esi
  int v21; // ebx
  dly_t *v22; // eax
  void *v23; // ebx
  flt_t *pflt; // esi
  flt_t *pf1; // eax
  flt_t *pf2; // eax
  flt_t *pf3; // eax
  dly_t *v28; // esi
  int v29; // ebx
  dly_t *v30; // eax
  void *v31; // ebx
  flt_t *v32; // esi
  flt_t *v33; // eax
  flt_t *v34; // eax
  flt_t *v35; // eax
  dly_t *pdly_in; // eax
  float v37; // xmm0_4
  float tslice; // [esp+0h] [ebp-4h]
  int cout; // [esp+Ch] [ebp+8h]
  int couta; // [esp+Ch] [ebp+8h]
  int cin; // [esp+10h] [ebp+Ch]

  v3 = 0;
  v4 = &ptcs[1];
  while ( v4[-1].fused )
  {
    if ( !v4->fused )
    {
      ++v3;
      break;
    }
    if ( !v4[1].fused )
    {
      v3 += 2;
      break;
    }
    if ( !v4[2].fused )
    {
      v3 += 3;
      break;
    }
    v4 += 4;
    v3 += 4;
    if ( (int)v4 >= (int)&lfos[1].pos )
      break;
  }
  if ( v3 == 64 )
  {
    DevMsg(a1: "DSP: Warning, failed to allocate pitch shifter.\n");
    return nullptr;
  }
  else
  {
    v6 = &ptcs[v3];
    if ( v6 != nullptr )
      _V_memset(dest: &ptcs[v3], fill: 0, count: 72);
    v7 = timeslice;
    v8 = fabs((fstep - 1.0) * timeslice);
    *(float *)&cout = v8;
    v9 = v7;
    v10 = 1.1 * v8;
    if ( v9 > v10 )
      v10 = v9;
    v11 = v8;
    v12 = v10;
    v13 = v11;
    tslice = v12;
    v14 = v11 * 0.9;
    v15 = timexfade;
    if ( v14 <= timexfade )
      v15 = v14;
    v16 = v15;
    v17 = v12 - v13;
    v18 = v16;
    if ( 0.9 * v17 <= v16 )
      v18 = 0.9 * v17;
    v6->cxfade = (int)(v18 * 44100.0 * 0.001);
    v19 = (int)(float)((float)(*(float *)&cout * 44100.0) * 0.001);
    v6->ccut = v19;
    v6->cduplicate = v19;
    cin = (int)(float)((float)(tslice * 44100.0) * 0.001);
    v20 = nullptr;
    couta = (int)(float)((float)((float)(tslice * fstep) * 44100.0) * 0.001);
    v21 = 0;
    v22 = dlys;
    while ( v22->fused )
    {
      ++v22;
      ++v21;
      if ( (int)v22 >= (int)flts )
        goto LABEL_27;
    }
    v20 = &dlys[v21];
    if ( v20 != nullptr )
      _V_memset(dest: &dlys[v21], fill: 0, count: 72);
LABEL_27:
    if ( v21 == 128 )
    {
      DevMsg(a1: "DSP: Warning, failed to allocate delay line.\n");
      v20 = nullptr;
    }
    else
    {
      v23 = MemAlloc_Alloc(nSize: (unsigned __int64)(unsigned int)(cin + 1) >> 30 != 0 ? -1 : 4 * (cin + 1));
      if ( v23 != nullptr )
      {
        _V_memset(dest: v23, fill: 0, count: 4 * cin + 4);
        v20->type = 3;
        v20->D = cin;
        v20->t = cin;
        v20->tnew = cin;
        v20->xf = 0;
        v20->D0 = cin;
        v20->p = (int *)v23;
        v20->w = (int *)v23;
        v20->fused = true;
        v20->a = 0;
        v20->b = 4096;
      }
      else
      {
        _Warning(a1: "Sound DSP: Failed to lock.\n");
        pflt = v20->pflt;
        if ( pflt != nullptr )
        {
          pf1 = pflt->pf1;
          if ( pf1 != nullptr )
            _V_memset(dest: pf1, fill: 0, count: 184);
          pf2 = pflt->pf2;
          if ( pf2 != nullptr )
            _V_memset(dest: pf2, fill: 0, count: 184);
          pf3 = pflt->pf3;
          if ( pf3 != nullptr )
            _V_memset(dest: pf3, fill: 0, count: 184);
          _V_memset(dest: pflt, fill: 0, count: 184);
        }
        v20 = nullptr;
      }
    }
    v6->pdly_in = v20;
    v28 = nullptr;
    v29 = 0;
    v30 = dlys;
    while ( v30->fused )
    {
      ++v30;
      ++v29;
      if ( (int)v30 >= (int)flts )
        goto LABEL_46;
    }
    v28 = &dlys[v29];
    if ( v28 != nullptr )
      _V_memset(dest: &dlys[v29], fill: 0, count: 72);
LABEL_46:
    if ( v29 == 128 )
    {
      DevMsg(a1: "DSP: Warning, failed to allocate delay line.\n");
      v28 = nullptr;
    }
    else
    {
      v31 = MemAlloc_Alloc(nSize: (unsigned __int64)(unsigned int)(couta + 1) >> 30 != 0 ? -1 : 4 * (couta + 1));
      if ( v31 != nullptr )
      {
        _V_memset(dest: v31, fill: 0, count: 4 * couta + 4);
        v28->type = 3;
        v28->D = couta;
        v28->t = couta;
        v28->tnew = couta;
        v28->xf = 0;
        v28->D0 = couta;
        v28->p = (int *)v31;
        v28->w = (int *)v31;
        v28->fused = true;
        v28->a = 0;
        v28->b = 4096;
      }
      else
      {
        _Warning(a1: "Sound DSP: Failed to lock.\n");
        v32 = v28->pflt;
        if ( v32 != nullptr )
        {
          v33 = v32->pf1;
          if ( v33 != nullptr )
            _V_memset(dest: v33, fill: 0, count: 184);
          v34 = v32->pf2;
          if ( v34 != nullptr )
            _V_memset(dest: v34, fill: 0, count: 184);
          v35 = v32->pf3;
          if ( v35 != nullptr )
            _V_memset(dest: v35, fill: 0, count: 184);
          _V_memset(dest: v32, fill: 0, count: 184);
        }
        v28 = nullptr;
      }
    }
    pdly_in = v6->pdly_in;
    v6->pdly_out = v28;
    if ( pdly_in != nullptr && v28 != nullptr )
    {
      v6->pin = pdly_in->w;
      v6->pout = v28->w;
      v6->iin = 0;
      v37 = fstep;
      if ( (int)fstep > 4095 )
        v37 = (float)(fstep - (float)(int)fstep) + 4095.0;
      v6->psn.p.cstep = 0;
      v6->psn.p.pos = 0;
      v6->psn.p.step = (int)(float)(v37 * 1048576.0);
      v6->psn.p.D = couta;
      v6->psn.fhitend = false;
      v6->fdup = fstep > 1.0;
      v6->cin = cin;
      v6->cout = couta;
      v6->fstep = fstep;
      v6->fused = true;
      return v6;
    }
    else
    {
      PTC_Free(pptc: v6);
      DevMsg(a1: "DSP: Warning, failed to allocate delay for pitch shifter.\n");
      return nullptr;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10027360
// Name: struct crs_t __near * CRS_Alloc(int,float,float,float)
// Source: json
//------------------------------------------------------------------------------
crs_t *__cdecl CRS_Alloc(int lfotype, float fHz, float fdepth, float mix)
{
  int v4; // ecx
  crs_t *v5; // eax
  int v7; // ecx
  bool v8; // zf
  crs_t *v9; // ecx
  dly_t *v10; // esi
  int v11; // edi
  int v12; // ebx
  dly_t *v13; // eax
  void *v14; // ebx
  flt_t *pflt; // esi
  flt_t *pf1; // eax
  flt_t *pf2; // eax
  flt_t *pf3; // eax
  mdy_t *v19; // edi
  lfo_t *v20; // eax
  dly_t *pdly; // esi
  crs_t *ramptime; // [esp+0h] [ebp-4h]

  v4 = 0;
  v5 = &crss[1];
  while ( v5[-1].fused )
  {
    if ( !v5->fused )
    {
      ++v4;
      break;
    }
    if ( !v5[1].fused )
    {
      v4 += 2;
      break;
    }
    if ( !v5[2].fused )
    {
      v4 += 3;
      break;
    }
    v5 += 4;
    v4 += 4;
    if ( (int)v5 >= (int)&efos[0].thresh_off )
      break;
  }
  if ( v4 == 64 )
  {
    DevMsg(a1: "DSP: Warning, failed to allocate chorus.\n");
    return nullptr;
  }
  v7 = v4;
  v8 = &crss[v7] == nullptr;
  v9 = &crss[v7];
  ramptime = v9;
  if ( !v8 )
    _V_memset(dest: v9, fill: 0, count: 16);
  v10 = nullptr;
  v11 = (int)(float)(fdepth * 4410.0);
  v12 = 0;
  v13 = dlys;
  while ( v13->fused )
  {
    ++v13;
    ++v12;
    if ( (int)v13 >= (int)flts )
      goto LABEL_21;
  }
  v10 = &dlys[v12];
  if ( v10 != nullptr )
    _V_memset(dest: &dlys[v12], fill: 0, count: 72);
LABEL_21:
  if ( v12 == 128 )
  {
    DevMsg(a1: "DSP: Warning, failed to allocate delay line.\n");
    v10 = nullptr;
  }
  else
  {
    v14 = MemAlloc_Alloc(nSize: (unsigned __int64)(unsigned int)(v11 + 1) >> 30 != 0 ? -1 : 4 * (v11 + 1));
    if ( v14 != nullptr )
    {
      _V_memset(dest: v14, fill: 0, count: 4 * v11 + 4);
      v10->type = 3;
      v10->D = v11;
      v10->t = v11;
      v10->tnew = v11;
      v10->xf = 0;
      v10->D0 = v11;
      v10->p = (int *)v14;
      v10->w = (int *)v14;
      v10->fused = true;
      v10->a = 0;
      v10->b = 4096;
    }
    else
    {
      _Warning(a1: "Sound DSP: Failed to lock.\n");
      pflt = v10->pflt;
      if ( pflt != nullptr )
      {
        pf1 = pflt->pf1;
        if ( pf1 != nullptr )
          _V_memset(dest: pf1, fill: 0, count: 184);
        pf2 = pflt->pf2;
        if ( pf2 != nullptr )
          _V_memset(dest: pf2, fill: 0, count: 184);
        pf3 = pflt->pf3;
        if ( pf3 != nullptr )
          _V_memset(dest: pf3, fill: 0, count: 184);
        _V_memset(dest: pflt, fill: 0, count: 184);
      }
      v10 = nullptr;
    }
  }
  v19 = MDY_Alloc(pdly: v10, ramptime: 0.0049999999, modtime: 0.0, depth: 0.0, mix);
  v20 = LFO_Alloc(wtype: lfotype, freqHz: fHz, foneshot: false, gain: 1.0);
  if ( v20 != nullptr )
  {
    if ( v19 != nullptr )
    {
      ramptime->pmdy = v19;
      ramptime->plfo = v20;
      ramptime->fused = true;
      return ramptime;
    }
    _V_memset(dest: v20, fill: 0, count: 56);
  }
  else if ( v19 != nullptr )
  {
    pdly = v19->pdly;
    if ( pdly != nullptr )
    {
      FLT_Free(pf: pdly->pflt);
      if ( pdly->w != nullptr )
        free(pMem: pdly->w);
      _V_memset(dest: pdly, fill: 0, count: 72);
    }
    _V_memset(dest: v19, fill: 0, count: 76);
  }
  DevMsg(a1: "DSP: Warning, failed to allocate lfo or mdy for chorus.\n");
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x100275D0
// Name: void PRC_CheckParams(struct prc_t __near *,struct prm_rng_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl PRC_CheckParams(prc_t *pprc, prm_rng_t *prng)
{
  float *prm; // edi
  float *p_lo; // esi
  int iprm; // ebx
  float v5; // xmm0_4
  float v6; // xmm0_4
  float v7; // xmm1_4

  if ( prng->iprm > 0 )
  {
    prm = pprc->prm;
    p_lo = &prng[1].lo;
    iprm = prng->iprm;
    do
    {
      v5 = *prm;
      if ( *prm != 0.0 && (v5 > p_lo[1] || *p_lo > v5) )
      {
        DevMsg(a1: "DSP: Warning, clamping out of range parameter.\n");
        v6 = *prm;
        v7 = *p_lo;
        if ( *p_lo > *prm || (v7 = p_lo[1], v6 > v7) )
          v6 = v7;
        *prm = v6;
      }
      p_lo += 3;
      ++prm;
      --iprm;
    }
    while ( iprm != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10027650
// Name: bool DSP_CheckDspAutoEnabled(void)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl DSP_CheckDspAutoEnabled()
{
  return dsp_room.m_pParent != nullptr && dsp_room.m_pParent->m_Value.m_nValue == 1;
}

//------------------------------------------------------------------------------
// Address: 0x10027670
// Name: int dsp_room_GetInt(void)
// Source: json
//------------------------------------------------------------------------------
int __cdecl dsp_room_GetInt()
{
  int result; // eax

  if ( dsp_room.m_pParent == nullptr )
    return 0;
  result = dsp_room.m_pParent->m_Value.m_nValue;
  if ( result != 1 )
    return result;
  if ( dsp_automatic.m_pParent != nullptr )
    return dsp_automatic.m_pParent->m_Value.m_nValue;
  else
    return 0;
}

//------------------------------------------------------------------------------
// Address: 0x100276A0
// Name: int Get_idsp_room(void)
// Source: json
//------------------------------------------------------------------------------
int __cdecl Get_idsp_room()
{
  if ( dsp_room.m_pParent != nullptr && dsp_room.m_pParent->m_Value.m_nValue == 1 )
    return idsp_automatic;
  else
    return idsp_room;
}

//------------------------------------------------------------------------------
// Address: 0x100276C0
// Name: void ADSP_GetAutoShape(struct adsp_auto_params_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ADSP_GetAutoShape(adsp_auto_params_t *pa)
{
  char v1; // bl
  int height; // ecx
  int length; // edx
  double width; // st6
  double v5; // st5
  double v6; // st7
  int v7; // eax
  double v8; // st4
  float v9; // xmm4_4
  int v10; // ecx
  float v11; // xmm3_4
  float v12; // xmm2_4
  float v13; // xmm1_4
  int v14; // ecx
  double v15; // st6

  v1 = 0;
  if ( !pa->bskyabove )
  {
    height = pa->height;
    length = pa->length;
    if ( (double)height > (double)length * 3.0 )
    {
      pa->height = length;
      pa->length = height;
      v1 = 1;
      if ( das_debug.m_pParent != nullptr && das_debug.m_pParent->m_Value.m_nValue > 1 )
        DevMsg(a1: "VERTICAL SHAFT Detected \n");
    }
    width = (double)pa->width;
    v5 = (double)pa->length;
    v6 = 4.0 * width;
    if ( v5 > v6 && width <= 48.0 )
    {
      pa->shape = 1;
      ADSP_GetSize(pa);
      if ( das_debug.m_pParent != nullptr && das_debug.m_pParent->m_Value.m_nValue > 1 )
        DevMsg(a1: "DUCT Detected \n");
autoshape_exit:
      if ( v1 != 0 )
      {
        v7 = pa->height;
        pa->height = pa->length;
        pa->length = v7;
      }
      return;
    }
    if ( v5 <= width * 2.5 )
    {
      v8 = 96.0;
    }
    else
    {
      v8 = 96.0;
      if ( width > 48.0 && width <= 96.0 )
      {
        pa->shape = 2;
        ADSP_GetSize(pa);
        if ( das_debug.m_pParent != nullptr && das_debug.m_pParent->m_Value.m_nValue > 1 )
          DevMsg(a1: "HALL Detected \n");
        goto autoshape_exit;
      }
    }
    if ( v5 <= v6 || width <= v8 )
    {
      pa->shape = 0;
      ADSP_GetSize(pa);
      if ( das_debug.m_pParent != nullptr && das_debug.m_pParent->m_Value.m_nValue > 1 )
        DevMsg(a1: "ROOM Detected \n");
    }
    else
    {
      pa->shape = 3;
      ADSP_GetSize(pa);
      if ( das_debug.m_pParent != nullptr && das_debug.m_pParent->m_Value.m_nValue > 1 )
        DevMsg(a1: "TUNNEL Detected \n");
    }
    goto autoshape_exit;
  }
  v9 = pa->surface_refl[0];
  v10 = v9 == 0.0;
  v11 = pa->surface_refl[1];
  if ( v11 == 0.0 )
    ++v10;
  v12 = pa->surface_refl[2];
  if ( v12 == 0.0 )
    ++v10;
  v13 = pa->surface_refl[3];
  if ( v13 == 0.0 )
    ++v10;
  if ( v10 <= 0 )
  {
    v15 = (double)pa->width;
    if ( 2.5 * v15 < (double)pa->length )
    {
      if ( v15 > 144.0 )
      {
        pa->shape = 4;
        ADSP_GetSize(pa);
        if ( das_debug.m_pParent != nullptr && das_debug.m_pParent->m_Value.m_nValue > 1 )
          DevMsg(a1: "OUTSIDE STREET Detected \n");
      }
      else
      {
        pa->shape = 5;
        ADSP_GetSize(pa);
        if ( das_debug.m_pParent != nullptr && das_debug.m_pParent->m_Value.m_nValue > 1 )
          DevMsg(a1: "OUTSIDE ALLEY Detected \n");
      }
    }
    else
    {
      pa->shape = 6;
      ADSP_GetSize(pa);
      if ( das_debug.m_pParent != nullptr && das_debug.m_pParent->m_Value.m_nValue > 1 )
        DevMsg(a1: "OUTSIDE COURTYARD Detected \n");
    }
  }
  else
  {
    v14 = v9 == 0.0;
    if ( v11 == 0.0 )
      ++v14;
    if ( v12 == 0.0 )
      ++v14;
    if ( v13 == 0.0 )
      ++v14;
    pa->shape = 11 - v14;
    ADSP_GetSize(pa);
    if ( das_debug.m_pParent != nullptr && das_debug.m_pParent->m_Value.m_nValue > 1 )
      DevMsg(a1: "OPEN SIDED OUTDOOR AREA Detected \n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x100279F0
// Name: void ADSP_InterpolatePreset(struct pset_t __near *,struct pset_t __near *,struct pset_t __near *,struct adsp_auto_params_t __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ADSP_InterpolatePreset(pset_t *pnew, pset_t *pmin, pset_t *pmax, pset_t *pa, adsp_auto_params_t *iskip)
{
  pset_t *v5; // esi
  int i; // esi
  double v8; // st7
  double v9; // st7
  double v10; // st4
  double v11; // st3
  double v12; // st5
  double v13; // st5
  double v14; // st6
  double v15; // rtt
  double v16; // st4
  double v17; // st5
  double v18; // st6
  double v19; // st7
  double v20; // rt0
  double v21; // st5
  double v22; // st6
  double v23; // rt1
  double v24; // st7
  double v25; // st4
  double v26; // st7
  double v27; // st3
  double v28; // st3
  double v29; // st6
  double v30; // st5
  double v31; // st4
  double v32; // st7
  float v33; // [esp+0h] [ebp-18h]
  float v34; // [esp+0h] [ebp-18h]
  float v35; // [esp+0h] [ebp-18h]
  float v36; // [esp+0h] [ebp-18h]
  float paj; // [esp+30h] [ebp+18h]
  float paa; // [esp+30h] [ebp+18h]
  int pab; // [esp+30h] [ebp+18h]
  int pac; // [esp+30h] [ebp+18h]
  int pad; // [esp+30h] [ebp+18h]
  int pae; // [esp+30h] [ebp+18h]
  int paf; // [esp+30h] [ebp+18h]
  int pag; // [esp+30h] [ebp+18h]
  int pah; // [esp+30h] [ebp+18h]
  int pai; // [esp+30h] [ebp+18h]

  if ( iskip == nullptr )
  {
    v5 = pmax;
    if ( SLODWORD(pa->prcs[0].prm[10]) <= 1 )
      v5 = pmin;
    *pnew = *v5;
  }
  for ( i = 0; i < 4; ++i )
    ADSP_InterpParam(
      pnew,
      pmin,
      pmax,
      proc_type: 10,
      skipprocs: (int)iskip,
      iparam: i,
      index: LODWORD(pa->prcs[0].prm[10]),
      index_max: 5,
      bexp: false);
  ADSP_InterpParam(
    pnew,
    pmin,
    pmax,
    proc_type: 2,
    skipprocs: (int)iskip,
    iparam: 3,
    index: LODWORD(pa->prcs[0].prm[10]),
    index_max: 5,
    bexp: false);
  ADSP_InterpParam(
    pnew,
    pmin,
    pmax,
    proc_type: 2,
    skipprocs: (int)iskip,
    iparam: 1,
    index: LODWORD(pa->prcs[0].prm[10]),
    index_max: 5,
    bexp: true);
  ADSP_InterpParam(
    pnew,
    pmin,
    pmax,
    proc_type: 2,
    skipprocs: (int)iskip,
    iparam: 0,
    index: LODWORD(pa->prcs[0].prm[10]),
    index_max: 5,
    bexp: true);
  ADSP_InterpParam(
    pnew,
    pmin,
    pmax,
    proc_type: 2,
    skipprocs: (int)iskip,
    iparam: 4,
    index: LODWORD(pa->prcs[0].prm[10]),
    index_max: 5,
    bexp: false);
  ADSP_InterpParam(
    pnew,
    pmin,
    pmax,
    proc_type: 2,
    skipprocs: (int)iskip,
    iparam: 2,
    index: LODWORD(pa->prcs[0].prm[10]),
    index_max: 5,
    bexp: false);
  ADSP_InterpParam(
    pnew,
    pmin,
    pmax,
    proc_type: 2,
    skipprocs: (int)iskip,
    iparam: 7,
    index: LODWORD(pa->prcs[0].prm[10]),
    index_max: 5,
    bexp: false);
  ADSP_InterpParam(
    pnew,
    pmin,
    pmax,
    proc_type: 2,
    skipprocs: (int)iskip,
    iparam: 8,
    index: LODWORD(pa->prcs[0].prm[10]),
    index_max: 5,
    bexp: false);
  v8 = (double)pa->cprcs * 0.083333336;
  if ( v8 >= 6.0 )
  {
    v10 = v8;
    v9 = 500.0;
    if ( v10 > 500.0 )
      v10 = 500.0;
  }
  else
  {
    v9 = 500.0;
    v10 = 6.0;
  }
  v11 = 6.0;
  v12 = (double)pa->prcs[0].type * 0.083333336;
  if ( v12 >= 6.0 )
  {
    v11 = v12;
    v13 = 6.0;
    if ( v11 > v9 )
      v11 = v9;
  }
  else
  {
    v13 = 6.0;
  }
  v14 = 0.083333336 * (double)SLODWORD(pa->prcs[0].prm[0]);
  v15 = v10;
  v16 = v13;
  v17 = v15;
  if ( v16 <= v14 )
  {
    v20 = v17;
    v21 = v14;
    v22 = v20;
    if ( v21 <= v9 )
      v9 = v21;
    v23 = v22;
    v18 = v9;
    v19 = v23;
  }
  else
  {
    v18 = v16;
    v19 = v17;
  }
  v33 = v19;
  ADSP_SetParamIfNegative(
    pnew,
    pmin,
    pmax,
    proc_type: (pset_t *)2,
    skipprocs: (int)iskip,
    iparam: 9,
    index: LODWORD(pa->prcs[0].prm[12]),
    index_max: 5,
    bexp: true,
    value: v33);
  paj = v11;
  ADSP_SetParamIfNegative(
    pnew,
    pmin,
    pmax,
    proc_type: (pset_t *)2,
    skipprocs: (int)iskip,
    iparam: 10,
    index: LODWORD(pa->prcs[0].prm[11]),
    index_max: 5,
    bexp: true,
    value: paj);
  v34 = v18;
  ADSP_SetParamIfNegative(
    pnew,
    pmin,
    pmax,
    proc_type: (pset_t *)2,
    skipprocs: (int)iskip,
    iparam: 11,
    index: LODWORD(pa->prcs[0].prm[13]),
    index_max: 5,
    bexp: true,
    value: v34);
  ADSP_InterpParam(
    pnew,
    pmin,
    pmax,
    proc_type: 2,
    skipprocs: (int)iskip,
    iparam: 12,
    index: LODWORD(pa->prcs[0].prm[12]),
    index_max: 5,
    bexp: false);
  ADSP_InterpParam(
    pnew,
    pmin,
    pmax,
    proc_type: 2,
    skipprocs: (int)iskip,
    iparam: 13,
    index: LODWORD(pa->prcs[0].prm[11]),
    index_max: 5,
    bexp: false);
  ADSP_InterpParam(
    pnew,
    pmin,
    pmax,
    proc_type: 2,
    skipprocs: (int)iskip,
    iparam: 14,
    index: LODWORD(pa->prcs[0].prm[13]),
    index_max: 5,
    bexp: false);
  ADSP_InterpParam(
    pnew,
    pmin: pmax,
    pmax: pmin,
    proc_type: 2,
    skipprocs: (int)iskip,
    iparam: 5,
    index: LODWORD(pa->prcs[0].prm[14]),
    index_max: 4,
    bexp: false);
  v24 = (double)pa->prcs[0].type * 2.0 * 0.08333333333333333;
  v25 = 14.0;
  if ( v24 >= 14.0 )
  {
    v28 = v24;
    if ( v24 > 500.0 )
      v28 = 500.0;
    v25 = v28;
    v27 = 500.0;
    v26 = 14.0;
  }
  else
  {
    v26 = 14.0;
    v27 = 500.0;
  }
  paa = v25;
  v29 = v25;
  v30 = 0.08333333333333333 * (2.0 * (double)pa->cprcs);
  v31 = v26;
  v32 = v27;
  if ( v31 <= v30 )
  {
    if ( v30 > v27 )
      goto LABEL_28;
  }
  else
  {
    v30 = v31;
  }
  v32 = v30;
LABEL_28:
  v35 = v29;
  ADSP_SetParamIfNegative(
    pnew,
    pmin,
    pmax,
    proc_type: (pset_t *)1,
    skipprocs: (int)iskip,
    iparam: 1,
    index: LODWORD(pa->prcs[0].prm[11]),
    index_max: 5,
    bexp: true,
    value: v35);
  ADSP_InterpParam(
    pnew,
    pmin,
    pmax,
    proc_type: 1,
    skipprocs: (int)iskip,
    iparam: 2,
    index: LODWORD(pa->prcs[0].prm[11]),
    index_max: 5,
    bexp: false);
  ADSP_InterpParam(
    pnew,
    pmin,
    pmax,
    proc_type: 1,
    skipprocs: (int)iskip,
    iparam: 3,
    index: LODWORD(pa->prcs[0].prm[11]),
    index_max: 5,
    bexp: false);
  v36 = v32;
  ADSP_SetParamIfNegative(
    pnew,
    pmin,
    pmax,
    proc_type: (pset_t *)1,
    skipprocs: (int)iskip,
    iparam: 8,
    index: LODWORD(pa->prcs[0].prm[11]),
    index_max: 5,
    bexp: true,
    value: v36);
  ADSP_SetParamIfNegative(
    pnew,
    pmin,
    pmax,
    proc_type: (pset_t *)1,
    skipprocs: (int)iskip,
    iparam: 9,
    index: LODWORD(pa->prcs[0].prm[11]),
    index_max: 5,
    bexp: true,
    value: paa);
  ADSP_SetParamIfNegative(
    pnew,
    pmin,
    pmax,
    proc_type: (pset_t *)1,
    skipprocs: (int)iskip,
    iparam: 10,
    index: LODWORD(pa->prcs[0].prm[11]),
    index_max: 5,
    bexp: true,
    value: paa);
  ADSP_InterpParam(
    pnew,
    pmin: pmax,
    pmax: pmin,
    proc_type: 1,
    skipprocs: (int)iskip,
    iparam: 5,
    index: LODWORD(pa->prcs[0].prm[11]),
    index_max: 5,
    bexp: false);
  ADSP_InterpParam(
    pnew,
    pmin: pmax,
    pmax: pmin,
    proc_type: 1,
    skipprocs: (int)iskip,
    iparam: 6,
    index: LODWORD(pa->prcs[0].prm[11]),
    index_max: 5,
    bexp: false);
  for ( pab = 0; pab < 13; ++pab )
    ADSP_InterpParam(
      pnew,
      pmin,
      pmax,
      proc_type: 9,
      skipprocs: (int)iskip,
      iparam: pab,
      index: LODWORD(pa->prcs[0].prm[11]),
      index_max: 5,
      bexp: false);
  for ( pac = 0; pac < 8; ++pac )
    ADSP_InterpParam(
      pnew,
      pmin,
      pmax,
      proc_type: 11,
      skipprocs: (int)iskip,
      iparam: pac,
      index: LODWORD(pa->prcs[0].prm[10]),
      index_max: 5,
      bexp: false);
  for ( pad = 0; pad < 5; ++pad )
    ADSP_InterpParam(
      pnew,
      pmin,
      pmax,
      proc_type: 3,
      skipprocs: (int)iskip,
      iparam: pad,
      index: LODWORD(pa->prcs[0].prm[10]),
      index_max: 5,
      bexp: false);
  for ( pae = 0; pae < 3; ++pae )
    ADSP_InterpParam(
      pnew,
      pmin,
      pmax,
      proc_type: 5,
      skipprocs: (int)iskip,
      iparam: pae,
      index: LODWORD(pa->prcs[0].prm[10]),
      index_max: 5,
      bexp: false);
  for ( paf = 0; paf < 4; ++paf )
    ADSP_InterpParam(
      pnew,
      pmin,
      pmax,
      proc_type: 4,
      skipprocs: (int)iskip,
      iparam: paf,
      index: LODWORD(pa->prcs[0].prm[10]),
      index_max: 5,
      bexp: false);
  for ( pag = 0; pag < 9; ++pag )
    ADSP_InterpParam(
      pnew,
      pmin,
      pmax,
      proc_type: 6,
      skipprocs: (int)iskip,
      iparam: pag,
      index: LODWORD(pa->prcs[0].prm[10]),
      index_max: 5,
      bexp: false);
  for ( pah = 0; pah < 4; ++pah )
    ADSP_InterpParam(
      pnew,
      pmin,
      pmax,
      proc_type: 8,
      skipprocs: (int)iskip,
      iparam: pah,
      index: LODWORD(pa->prcs[0].prm[10]),
      index_max: 5,
      bexp: false);
  for ( pai = 0; pai < 4; ++pai )
    ADSP_InterpParam(
      pnew,
      pmin,
      pmax,
      proc_type: 7,
      skipprocs: (int)iskip,
      iparam: pai,
      index: LODWORD(pa->prcs[0].prm[10]),
      index_max: 5,
      bexp: false);
}

//------------------------------------------------------------------------------
// Address: 0x10027F90
// Name: int DSP_ConstructPreset(bool,int,int,int,float,float,float __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl DSP_ConstructPreset(
        bool bskyabove,
        int width,
        int length,
        int height,
        float fdiffusion,
        float freflectivity,
        float *psurf_refl,
        int inode)
{
  float v9; // xmm0_4
  ConVar *m_pParent; // eax
  int m_nValue; // eax
  pset_t *v12; // ebx
  pset_t new_pset; // [esp+0h] [ebp-694h] BYREF
  pset_t pset_min; // [esp+218h] [ebp-47Ch] BYREF
  pset_t pset_max; // [esp+430h] [ebp-264h] BYREF
  adsp_auto_params_t ap; // [esp+648h] [ebp-4Ch] BYREF

  if ( inode >= 40 )
    return 0;
  ap.fdiffusion = fdiffusion;
  ap.width = width;
  ap.freflectivity = freflectivity;
  ap.height = height;
  ap.surface_refl[0] = *psurf_refl;
  ap.surface_refl[1] = psurf_refl[1];
  ap.surface_refl[2] = psurf_refl[2];
  ap.surface_refl[3] = psurf_refl[3];
  ap.surface_refl[4] = psurf_refl[4];
  v9 = psurf_refl[5];
  ap.bskyabove = bskyabove;
  ap.length = length;
  ap.surface_refl[5] = v9;
  if ( bskyabove )
    ap.surface_refl[4] = 0.0;
  ADSP_GetAutoShape(pa: &ap);
  switch ( ap.shape )
  {
    case 1:
      m_pParent = adsp_duct_min.m_pParent;
      break;
    case 2:
      m_pParent = adsp_hall_min.m_pParent;
      break;
    case 3:
      m_pParent = adsp_tunnel_min.m_pParent;
      break;
    case 4:
      m_pParent = adsp_street_min.m_pParent;
      break;
    case 5:
      m_pParent = adsp_alley_min.m_pParent;
      break;
    case 6:
      m_pParent = adsp_courtyard_min.m_pParent;
      break;
    case 7:
      m_pParent = adsp_openspace_min.m_pParent;
      break;
    case 8:
      m_pParent = adsp_openwall_min.m_pParent;
      break;
    case 9:
      m_pParent = adsp_openstreet_min.m_pParent;
      break;
    case 0xA:
      m_pParent = adsp_opencourtyard_min.m_pParent;
      break;
    default:
      m_pParent = adsp_room_min.m_pParent;
      break;
  }
  if ( m_pParent != nullptr )
    m_nValue = m_pParent->m_Value.m_nValue;
  else
    m_nValue = 0;
  if ( ap.diffusion > 1 )
    m_nValue += 2;
  v12 = g_psettemplates;
  pset_min = g_psettemplates[m_nValue];
  pset_max = g_psettemplates[m_nValue + 1];
  if ( das_debug.m_pParent != nullptr && das_debug.m_pParent->m_Value.m_nValue != 0 )
  {
    DevMsg(a1: "DAS: Min Preset Index: %i\nDAS: Max Preset Index: %i\n", m_nValue, m_nValue + 1);
    v12 = g_psettemplates;
  }
  ADSP_InterpolatePreset(pnew: &new_pset, pmin: &pset_min, pmax: &pset_max, pa: (pset_t *)&ap, iskip: nullptr);
  ADSP_InterpolatePreset(
    pnew: &new_pset,
    pmin: &pset_min,
    pmax: &pset_max,
    pa: (pset_t *)&ap,
    iskip: (adsp_auto_params_t *)1);
  v12[inode + 60] = new_pset;
  return inode + 60;
}

//------------------------------------------------------------------------------
// Address: 0x10028190
// Name: bool DSP_RoomDSPIsOff(void)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl DSP_RoomDSPIsOff()
{
  unsigned int v0; // eax
  dsp_t *v1; // eax
  bool result; // al

  if ( dsp_room.m_pParent != nullptr && dsp_room.m_pParent->m_Value.m_nValue == 1 )
    v0 = idsp_automatic;
  else
    v0 = idsp_room;
  result = true;
  if ( v0 <= 0x1F )
  {
    v1 = &dsps[v0];
    if ( v1->ipset != 0 || v1->ipsetprev != 0 )
      return false;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100281D0
// Name: _FreeDsps
// Source: json
//------------------------------------------------------------------------------
void __cdecl FreeDsps(bool bReleaseTemplateMemory)
{
  DSP_Free(idsp: (dsp_t *)idsp_room);
  DSP_Free(idsp: (dsp_t *)idsp_water);
  DSP_Free(idsp: (dsp_t *)idsp_player);
  DSP_Free(idsp: (dsp_t *)idsp_facingaway);
  DSP_Free(idsp: (dsp_t *)idsp_speaker);
  DSP_Free(idsp: (dsp_t *)idsp_spatial);
  DSP_Free(idsp: (dsp_t *)idsp_automatic);
  idsp_room = 0;
  idsp_water = 0;
  idsp_player = 0;
  idsp_facingaway = 0;
  idsp_speaker = 0;
  idsp_spatial = 0;
  idsp_automatic = 0;
  DSP_FreeAll();
  if ( bReleaseTemplateMemory && g_psettemplates != nullptr )
  {
    free(pMem: g_psettemplates);
    g_psettemplates = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10028280
// Name: snd_print_dsp_effect
// Source: json
//------------------------------------------------------------------------------
void __cdecl snd_print_dsp_effect(const CCommand *args)
{
  unsigned int v1; // eax

  if ( args->m_nArgc == 2 )
  {
    v1 = atoi(nptr: args->m_ppArgv[1]);
    if ( v1 > 0x1F )
      _Warning(a1: "DSP index is out of range. It should be between 0 and %d.\n", 32);
    else
      DSP_Print(dsp: &dsps[v1], nIndentation: 0);
  }
  else
  {
    _Warning(a1: "Incorrect usage of snd_print_dsp_effect. snd_print_dsp_effect <dspindex>.\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x100282E0
// Name: void DelayAllpass_Opt3<2,0>(int,int,int __near *,int __near * __near *,int,int,int __near *,int __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DelayAllpass_Opt3<2,0>(
        int nDelaySize,
        int tdelay,
        int *psamps,
        int **ppsamp,
        int fbgain,
        int outgain,
        int *pIn,
        int *pOut,
        unsigned int nCount)
{
  int v9; // edx
  int *v10; // ecx
  int v11; // ebx
  int v12; // esi
  int v13; // eax
  int *v14; // edi
  int *v15; // eax
  int *v16; // edi
  int v17; // eax
  int v18; // ecx
  int v19; // edx
  int v20; // esi
  bool v21; // zf
  int sDD; // [esp+0h] [ebp-2Ch]
  int sDB; // [esp+4h] [ebp-28h]
  unsigned int v24; // [esp+Ch] [ebp-20h]
  _DWORD *v25; // [esp+10h] [ebp-1Ch]
  int sDC; // [esp+14h] [ebp-18h]
  int sDA; // [esp+18h] [ebp-14h]
  int *pSampsPDelaySize; // [esp+1Ch] [ebp-10h]
  int *pDelaySampleA; // [esp+20h] [ebp-Ch]
  int *pDelaySampleD; // [esp+24h] [ebp-8h]
  int *pDelaySampleC; // [esp+28h] [ebp-4h]
  int sDa; // [esp+38h] [ebp+Ch]
  int *sD; // [esp+38h] [ebp+Ch]

  v9 = nDelaySize;
  if ( nDelaySize == tdelay )
  {
    v10 = *ppsamp;
    v11 = fbgain;
    pSampsPDelaySize = &psamps[nDelaySize];
    v12 = nDelaySize + 1;
    if ( (nCount & 3) != 0 )
    {
      do
      {
        sDa = v10[nDelaySize - (v12 & (((char *)pSampsPDelaySize - (char *)&v10[nDelaySize]) >> 31))];
        v13 = *pIn + ((fbgain * sDa) >> 12);
        --nCount;
        *v10 = v13;
        pIn += 2;
        v12 = nDelaySize + 1;
        v10 = &v10[((nDelaySize + 1) & (((char *)(v10 - 1) - (char *)psamps) >> 31)) - 1];
        *pOut += (outgain * (sDa + (-(fbgain * v13) >> 12))) >> 12;
        v14 = ++pOut;
      }
      while ( (nCount & 3) != 0 );
    }
    else
    {
      v14 = pOut;
    }
    pDelaySampleA = v10;
    sD = &v10[(v12 & (((char *)(v10 - 1) - (char *)psamps) >> 31)) - 1];
    pDelaySampleC = &v10[(v12 & (((char *)(v10 - 2) - (char *)psamps) >> 31)) - 2];
    v15 = &v10[(v12 & (((char *)(v10 - 3) - (char *)psamps) >> 31)) - 3];
    pDelaySampleD = v15;
    if ( (int)nCount >= 4 )
    {
      v25 = v14 + 2;
      v16 = pIn + 4;
      v24 = nCount >> 2;
      while ( 1 )
      {
        sDC = *v15;
        sDA = *sD;
        sDB = *pDelaySampleC;
        sDD = v15[v9 - ((v9 + 1) & (((char *)pSampsPDelaySize - (char *)&v15[v9]) >> 31))];
        v17 = *(v16 - 4) + ((v11 * *sD) >> 12);
        v18 = *(v16 - 2) + ((v11 * *pDelaySampleC) >> 12);
        *pDelaySampleA = v17;
        *sD = v18;
        v19 = *v16 + ((v11 * sDC) >> 12);
        v20 = v16[2] + ((v11 * sDD) >> 12);
        *pDelaySampleC = v19;
        *pDelaySampleD = v20;
        pDelaySampleA = &pDelaySampleA[((nDelaySize + 1) & (((char *)(pDelaySampleA - 4) - (char *)psamps) >> 31)) - 4];
        sD = &sD[((nDelaySize + 1) & (((char *)(sD - 4) - (char *)psamps) >> 31)) - 4];
        pDelaySampleC = &pDelaySampleC[((nDelaySize + 1) & (((char *)(pDelaySampleC - 4) - (char *)psamps) >> 31)) - 4];
        v11 = fbgain;
        pDelaySampleD = &pDelaySampleD[((nDelaySize + 1) & (((char *)(pDelaySampleD - 4) - (char *)psamps) >> 31)) - 4];
        *(v25 - 2) += (outgain * (sDA + (-(fbgain * v17) >> 12))) >> 12;
        *(v25 - 1) += (outgain * (sDB + (-(fbgain * v18) >> 12))) >> 12;
        *v25 += (outgain * (sDC + (-(fbgain * v19) >> 12))) >> 12;
        v25[1] += (outgain * (sDD + (-(fbgain * v20) >> 12))) >> 12;
        v21 = v24-- == 1;
        v25 += 4;
        if ( v21 )
          break;
        v9 = nDelaySize;
        v16 += 8;
        v15 = pDelaySampleD;
      }
    }
    *ppsamp = pDelaySampleA;
  }
  else
  {
    DelayAllpass_Opt2<2,0>((int *)nDelaySize, tdelay, psamps, ppsamp, fbgain, outgain, pIn, pOut, nCount);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10028580
// Name: void DelayAllpass_Opt3<2,1>(int,int,int __near *,int __near * __near *,int,int,int __near *,int __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DelayAllpass_Opt3<2,1>(
        int nDelaySize,
        int tdelay,
        int *psamps,
        int **ppsamp,
        int fbgain,
        int outgain,
        int *pIn,
        int *pOut,
        unsigned int nCount)
{
  int v9; // edx
  int *v10; // ecx
  int *v11; // ebx
  int v12; // edi
  int v13; // esi
  int v14; // eax
  int *v15; // eax
  int *v16; // ebx
  int v17; // ecx
  int v18; // eax
  int v19; // ecx
  int v20; // edx
  int v21; // esi
  bool v22; // zf
  int sDD; // [esp+0h] [ebp-2Ch]
  int sDB; // [esp+4h] [ebp-28h]
  unsigned int v25; // [esp+Ch] [ebp-20h]
  int *v26; // [esp+10h] [ebp-1Ch]
  int sDC; // [esp+14h] [ebp-18h]
  int sDA; // [esp+18h] [ebp-14h]
  int *pSampsPDelaySize; // [esp+1Ch] [ebp-10h]
  int *pDelaySampleA; // [esp+20h] [ebp-Ch]
  int *pDelaySampleD; // [esp+24h] [ebp-8h]
  int *pDelaySampleC; // [esp+28h] [ebp-4h]
  int sDa; // [esp+38h] [ebp+Ch]
  int *sD; // [esp+38h] [ebp+Ch]

  v9 = nDelaySize;
  if ( nDelaySize == tdelay )
  {
    v10 = *ppsamp;
    v11 = psamps;
    v12 = fbgain;
    pSampsPDelaySize = &psamps[nDelaySize];
    v13 = nDelaySize + 1;
    if ( (nCount & 3) != 0 )
    {
      do
      {
        sDa = v10[nDelaySize - (v13 & (((char *)pSampsPDelaySize - (char *)&v10[nDelaySize]) >> 31))];
        v14 = *pIn + ((fbgain * sDa) >> 12);
        --nCount;
        *v10 = v14;
        pIn += 2;
        v13 = nDelaySize + 1;
        v10 = &v10[((nDelaySize + 1) & (((char *)(v10 - 1) - (char *)psamps) >> 31)) - 1];
        *pOut++ = (outgain * (sDa + (-(fbgain * v14) >> 12))) >> 12;
      }
      while ( (nCount & 3) != 0 );
      v11 = psamps;
    }
    pDelaySampleA = v10;
    sD = &v10[(v13 & (((char *)(v10 - 1) - (char *)v11) >> 31)) - 1];
    pDelaySampleC = &v10[(v13 & (((char *)(v10 - 2) - (char *)v11) >> 31)) - 2];
    v15 = &v10[(v13 & (((char *)(v10 - 3) - (char *)v11) >> 31)) - 3];
    pDelaySampleD = v15;
    if ( (int)nCount >= 4 )
    {
      v16 = pIn + 4;
      v26 = pOut + 2;
      v25 = nCount >> 2;
      while ( 1 )
      {
        sDC = *v15;
        sDA = *sD;
        sDB = *pDelaySampleC;
        v17 = v12 * *pDelaySampleC;
        sDD = v15[v9 - ((v9 + 1) & (((char *)pSampsPDelaySize - (char *)&v15[v9]) >> 31))];
        v18 = *(v16 - 4) + ((v12 * *sD) >> 12);
        v16 += 8;
        *pDelaySampleA = v18;
        v19 = *(v16 - 10) + (v17 >> 12);
        *sD = v19;
        v20 = *(v16 - 8) + ((v12 * sDC) >> 12);
        v21 = *(v16 - 6) + ((v12 * sDD) >> 12);
        *pDelaySampleC = v20;
        *pDelaySampleD = v21;
        pDelaySampleA = &pDelaySampleA[((nDelaySize + 1) & (((char *)(pDelaySampleA - 4) - (char *)psamps) >> 31)) - 4];
        sD = &sD[((nDelaySize + 1) & (((char *)(sD - 4) - (char *)psamps) >> 31)) - 4];
        pDelaySampleC = &pDelaySampleC[((nDelaySize + 1) & (((char *)(pDelaySampleC - 4) - (char *)psamps) >> 31)) - 4];
        pDelaySampleD = &pDelaySampleD[((nDelaySize + 1) & (((char *)(pDelaySampleD - 4) - (char *)psamps) >> 31)) - 4];
        v12 = fbgain;
        *(v26 - 2) = (outgain * (sDA + (-(fbgain * v18) >> 12))) >> 12;
        *(v26 - 1) = (outgain * (sDB + (-(fbgain * v19) >> 12))) >> 12;
        *v26 = (outgain * (sDC + (-(fbgain * v20) >> 12))) >> 12;
        v26[1] = (outgain * (sDD + (-(fbgain * v21) >> 12))) >> 12;
        v22 = v25-- == 1;
        v26 += 4;
        if ( v22 )
          break;
        v9 = nDelaySize;
        v15 = pDelaySampleD;
      }
    }
    *ppsamp = pDelaySampleA;
  }
  else
  {
    DelayAllpass_Opt2<2,1>((int *)nDelaySize, tdelay, psamps, ppsamp, fbgain, outgain, pIn, pOut, nCount);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10028820
// Name: void DelayAllpass_Opt3<1,1>(int,int,int __near *,int __near * __near *,int,int,int __near *,int __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DelayAllpass_Opt3<1,1>(
        int nDelaySize,
        int tdelay,
        int *psamps,
        int **ppsamp,
        int fbgain,
        int outgain,
        int *pIn,
        int *pOut,
        unsigned int nCount)
{
  int v9; // edx
  int *v10; // ecx
  int *v11; // ebx
  int v12; // edi
  int v13; // esi
  int v14; // eax
  int *v15; // eax
  int *v16; // ebx
  int v17; // eax
  int v18; // ecx
  int v19; // edx
  int v20; // esi
  bool v21; // zf
  int sDD; // [esp+0h] [ebp-30h]
  int sDB; // [esp+4h] [ebp-2Ch]
  unsigned int v24; // [esp+Ch] [ebp-24h]
  int *v25; // [esp+10h] [ebp-20h]
  int *v26; // [esp+14h] [ebp-1Ch]
  int sDC; // [esp+18h] [ebp-18h]
  int sDA; // [esp+1Ch] [ebp-14h]
  int *pSampsPDelaySize; // [esp+20h] [ebp-10h]
  int *pDelaySampleA; // [esp+24h] [ebp-Ch]
  int *pDelaySampleAa; // [esp+24h] [ebp-Ch]
  int *pDelaySampleD; // [esp+28h] [ebp-8h]
  int *pDelaySampleC; // [esp+2Ch] [ebp-4h]
  int sDa; // [esp+3Ch] [ebp+Ch]
  int *sD; // [esp+3Ch] [ebp+Ch]

  v9 = nDelaySize;
  if ( nDelaySize == tdelay )
  {
    v10 = *ppsamp;
    v11 = psamps;
    v12 = fbgain;
    pSampsPDelaySize = &psamps[nDelaySize];
    v13 = nDelaySize + 1;
    if ( (nCount & 3) != 0 )
    {
      do
      {
        sDa = v10[nDelaySize - (v13 & (((char *)pSampsPDelaySize - (char *)&v10[nDelaySize]) >> 31))];
        v14 = *pIn + ((fbgain * sDa) >> 12);
        --nCount;
        *v10 = v14;
        ++pIn;
        v13 = nDelaySize + 1;
        v10 = &v10[((nDelaySize + 1) & (((char *)(v10 - 1) - (char *)psamps) >> 31)) - 1];
        *pOut++ = (outgain * (sDa + (-(fbgain * v14) >> 12))) >> 12;
      }
      while ( (nCount & 3) != 0 );
      v11 = psamps;
    }
    pDelaySampleA = v10;
    sD = &v10[(v13 & (((char *)(v10 - 1) - (char *)v11) >> 31)) - 1];
    pDelaySampleC = &v10[(v13 & (((char *)(v10 - 2) - (char *)v11) >> 31)) - 2];
    v15 = &v10[(v13 & (((char *)(v10 - 3) - (char *)v11) >> 31)) - 3];
    pDelaySampleD = v15;
    if ( (int)nCount >= 4 )
    {
      v25 = pOut + 2;
      v16 = pIn + 2;
      v26 = pIn + 2;
      v24 = nCount >> 2;
      while ( 1 )
      {
        sDC = *v15;
        sDA = *sD;
        sDB = *pDelaySampleC;
        sDD = v15[v9 - ((v9 + 1) & (((char *)pSampsPDelaySize - (char *)&v15[v9]) >> 31))];
        pDelaySampleAa = pDelaySampleA - 4;
        v17 = *(v16 - 2) + ((v12 * *sD) >> 12);
        v18 = *(v16 - 1) + ((v12 * *pDelaySampleC) >> 12);
        pDelaySampleAa[4] = v17;
        v19 = *v16 + ((v12 * sDC) >> 12);
        v20 = v16[1] + ((v12 * sDD) >> 12);
        *sD = v18;
        *pDelaySampleC = v19;
        *pDelaySampleD = v20;
        pDelaySampleA = &pDelaySampleAa[(nDelaySize + 1) & (((char *)pDelaySampleAa - (char *)psamps) >> 31)];
        sD = &sD[((nDelaySize + 1) & (((char *)(sD - 4) - (char *)psamps) >> 31)) - 4];
        pDelaySampleC = &pDelaySampleC[((nDelaySize + 1) & (((char *)(pDelaySampleC - 4) - (char *)psamps) >> 31)) - 4];
        pDelaySampleD = &pDelaySampleD[((nDelaySize + 1) & (((char *)(pDelaySampleD - 4) - (char *)psamps) >> 31)) - 4];
        *(int *)((char *)v26 + (char *)pOut - (char *)pIn - 8) = (outgain * (sDA + (-(fbgain * v17) >> 12))) >> 12;
        v12 = fbgain;
        *(v25 - 1) = (outgain * (sDB + (-(fbgain * v18) >> 12))) >> 12;
        *v25 = (outgain * (sDC + (-(fbgain * v19) >> 12))) >> 12;
        v25[1] = (outgain * (sDD + (-(fbgain * v20) >> 12))) >> 12;
        v16 = v26 + 4;
        v21 = v24-- == 1;
        v26 += 4;
        v25 += 4;
        if ( v21 )
          break;
        v9 = nDelaySize;
        v15 = pDelaySampleD;
      }
    }
    *ppsamp = pDelaySampleA;
  }
  else
  {
    DelayAllpass_Opt2<1,1>((int *)nDelaySize, tdelay, psamps, ppsamp, fbgain, outgain, pIn, pOut, nCount);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10028AD0
// Name: void __near * FLT_VParams(void __near *)
// Source: json
//------------------------------------------------------------------------------
flt_t *__cdecl FLT_VParams(prc_t *p)
{
  PRC_CheckParams(pprc: p, prng: flt_rng);
  return FLT_Params(pprc: p);
}

//------------------------------------------------------------------------------
// Address: 0x10028AF0
// Name: void __near * DLY_VParams(void __near *)
// Source: json
//------------------------------------------------------------------------------
dly_t *__cdecl DLY_VParams(prc_t *p)
{
  PRC_CheckParams(pprc: p, prng: dly_rng);
  return DLY_Params(pprc: p);
}

//------------------------------------------------------------------------------
// Address: 0x10028B10
// Name: void DLY_GetNext_Opt(struct dly_t __near *,int __near *,int __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DLY_GetNext_Opt(dly_t *pdly, int *pIn, int *pOut, int nCount)
{
  switch ( pdly->type )
  {
    case 1:
      DelayAllpass_Opt3<2,0>(
        nDelaySize: pdly->D,
        tdelay: pdly->t,
        psamps: pdly->w,
        ppsamp: &pdly->p,
        fbgain: pdly->a,
        outgain: pdly->b,
        pIn,
        pOut,
        nCount);
      break;
    case 2:
      DelayLowPass_Opt3(
        nDelaySize: pdly->D,
        tdelay: (int *)pdly->t,
        psamps: pdly->w,
        ppsamp: &pdly->p,
        fbgain: pdly->a,
        outgain: pdly->b,
        denom: pdly->pflt->a,
        Ll: pdly->pflt->L,
        numer: pdly->pflt->b,
        pfsamps: pdly->pflt->w,
        pIn,
        pOut,
        nCount);
      break;
    case 3:
      DelayLinear_Opt(delaysize: pdly->D, tdelay: pdly->t, psamps: pdly->w, ppsamp: &pdly->p, pIn, pOut, nCount);
      break;
    case 4:
      DelayLinearLowPass_Opt3(
        nDelaySize: pdly->D,
        tdelay: pdly->t,
        psamps: pdly->w,
        ppsamp: &pdly->p,
        fbgain: pdly->a,
        outgain: pdly->b,
        denom: pdly->pflt->a,
        Ll: pdly->pflt->L,
        numer: pdly->pflt->b,
        pfsamps: pdly->pflt->w,
        pIn,
        pOut,
        nCount);
      break;
    case 5:
      DelayLowpass_multitap_Opt(
        delaysize: pdly->D,
        tdelay0: pdly->t,
        tdelay1: pdly->t1,
        tdelay2: pdly->t2,
        tdelay3: pdly->t3,
        psamps: pdly->w,
        ppsamp: &pdly->p,
        fbgain: pdly->a,
        outgain: pdly->b,
        denom: pdly->pflt->a,
        Ll: pdly->pflt->L,
        numer: pdly->pflt->b,
        pfsamps: pdly->pflt->w,
        pIn,
        pOut,
        nCount);
      break;
    case 6:
      ReverbSimple_multitap_Opt(
        delaysize: pdly->D,
        tdelay0: pdly->t,
        tdelay1: pdly->t1,
        tdelay2: pdly->t2,
        tdelay3: pdly->t3,
        psamps: pdly->w,
        ppsamp: &pdly->p,
        fbgain: pdly->a,
        outgain: pdly->b,
        pIn,
        pOut,
        nCount);
      break;
    default:
      ReverbSimple_Opt(
        delaysize: pdly->D,
        tdelay: pdly->t,
        psamps: pdly->w,
        ppsamp: &pdly->p,
        fbgain: pdly->a,
        outgain: pdly->b,
        pIn,
        pOut,
        nCount);
      break;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10028CE0
// Name: void __near * MDY_VParams(void __near *)
// Source: json
//------------------------------------------------------------------------------
dly_t *__cdecl MDY_VParams(prc_t *p)
{
  PRC_CheckParams(pprc: p, prng: mdy_rng);
  return MDY_Params(pprc: p);
}

//------------------------------------------------------------------------------
// Address: 0x10028D00
// Name: void __near * RVA_VParams(void __near *)
// Source: json
//------------------------------------------------------------------------------
rva_t *__cdecl RVA_VParams(prc_t *p)
{
  PRC_CheckParams(pprc: p, prng: rva_rng);
  return RVA_Params(pprc: p);
}

//------------------------------------------------------------------------------
// Address: 0x10028D20
// Name: void __near * DFR_VParams(void __near *)
// Source: json
//------------------------------------------------------------------------------
dfr_t *__cdecl DFR_VParams(prc_t *p)
{
  PRC_CheckParams(pprc: p, prng: dfr_rng);
  return DFR_Params(pprc: p);
}

//------------------------------------------------------------------------------
// Address: 0x10028D40
// Name: void __near * LFO_VParams(void __near *)
// Source: json
//------------------------------------------------------------------------------
lfo_t *__cdecl LFO_VParams(prc_t *p)
{
  PRC_CheckParams(pprc: p, prng: lfo_rng);
  return LFO_Alloc(wtype: (int)p->prm[0], freqHz: p->prm[1], foneshot: p->prm[2] > 0.0, gain: p->prm[3]);
}

//------------------------------------------------------------------------------
// Address: 0x10028D90
// Name: void __near * PTC_VParams(void __near *)
// Source: json
//------------------------------------------------------------------------------
ptc_t *__cdecl PTC_VParams(prc_t *p)
{
  PRC_CheckParams(pprc: p, prng: ptc_rng);
  return PTC_Alloc(timeslice: p->prm[1], timexfade: p->prm[2], fstep: p->prm[0]);
}

//------------------------------------------------------------------------------
// Address: 0x10028DD0
// Name: void __near * ENV_VParams(void __near *)
// Source: json
//------------------------------------------------------------------------------
env_t *__cdecl ENV_VParams(prc_t *p)
{
  PRC_CheckParams(pprc: p, prng: env_rng);
  return ENV_Params(pprc: p);
}

//------------------------------------------------------------------------------
// Address: 0x10028DF0
// Name: void __near * EFO_VParams(void __near *)
// Source: json
//------------------------------------------------------------------------------
efo_t *__cdecl EFO_VParams(prc_t *p)
{
  PRC_CheckParams(pprc: p, prng: efo_rng);
  return EFO_Params(pprc: p);
}

//------------------------------------------------------------------------------
// Address: 0x10028E10
// Name: void __near * CRS_VParams(void __near *)
// Source: json
//------------------------------------------------------------------------------
crs_t *__cdecl CRS_VParams(prc_t *p)
{
  PRC_CheckParams(pprc: p, prng: crs_rng);
  return CRS_Alloc(lfotype: (int)p->prm[0], fHz: p->prm[1], fdepth: p->prm[2], mix: p->prm[3]);
}

//------------------------------------------------------------------------------
// Address: 0x10028E50
// Name: void __near * AMP_VParams(void __near *)
// Source: json
//------------------------------------------------------------------------------
amp_t *__cdecl AMP_VParams(prc_t *p)
{
  PRC_CheckParams(pprc: p, prng: amp_rng);
  return AMP_Params(pprc: p);
}

//------------------------------------------------------------------------------
// Address: 0x10028E70
// Name: void DSP_FreePrevPreset(struct dsp_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DSP_FreePrevPreset(dsp_t *pdsp)
{
  dsp_t *v1; // esi
  pset_t *v2; // edi
  void **p_pdata; // esi
  int cprcs; // ebx
  void (__cdecl *v5)(void *); // ecx
  int i; // [esp+4h] [ebp-8h]
  pset_t **ppsetprev; // [esp+8h] [ebp-4h]

  v1 = pdsp;
  if ( pdsp->ipsetprev != 0 )
  {
    if ( snd_dsp_spew_changes.m_pParent != nullptr && snd_dsp_spew_changes.m_pParent->m_Value.m_nValue != 0 )
      DevMsg(a1: "[Sound DSP] Free previous preset %d.\n", pdsp->ipsetprev);
    i = 0;
    if ( pdsp->cchan > 0 )
    {
      ppsetprev = pdsp->ppsetprev;
      do
      {
        v2 = *ppsetprev;
        if ( *ppsetprev != nullptr )
        {
          if ( v2->cprcs > 0 )
          {
            p_pdata = &v2->prcs[0].pdata;
            cprcs = v2->cprcs;
            do
            {
              v5 = (void (__cdecl *)(void *))*(p_pdata - 2);
              if ( v5 != nullptr && *p_pdata != nullptr )
                v5(a1: *p_pdata);
              p_pdata += 23;
              --cprcs;
            }
            while ( cprcs != 0 );
            v1 = pdsp;
          }
          _V_memset(dest: v2, fill: 0, count: 536);
          *ppsetprev = nullptr;
        }
        ++ppsetprev;
        ++i;
      }
      while ( i < v1->cchan );
    }
    v1->ipsetprev = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10028F30
// Name: _DSP_ClearState
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __usercall DSP_ClearState(unsigned int a1@<esi>)
{
  PreserveDSP_t *v1; // esi
  int v2; // ecx
  int v3; // [esp-4h] [ebp-8h]

  if ( !g_bNeedPresetRestore )
  {
    CLoaderMemAlloc::CrtIsValidPointer(this: (ConVar *)&dsp_automatic.IConVar, value: 0, a2: a1, a3: v3);
    v1 = g_PreserveDSP;
    do
    {
      v2 = (int)&v1->cvar->IConVar;
      v1->oldvalue = v1->cvar->m_pParent->m_Value.m_fValue;
      (*(void (__thiscall **)(int, _DWORD))(*(_DWORD *)v2 + 4))(a1: v2, a2: 0);
      ++v1;
    }
    while ( (int)v1 < (int)&unk_10411EFC );
    DSP_Free(idsp: (dsp_t *)idsp_room);
    DSP_Free(idsp: (dsp_t *)idsp_water);
    DSP_Free(idsp: (dsp_t *)idsp_player);
    DSP_Free(idsp: (dsp_t *)idsp_facingaway);
    DSP_Free(idsp: (dsp_t *)idsp_speaker);
    DSP_Free(idsp: (dsp_t *)idsp_spatial);
    DSP_Free(idsp: (dsp_t *)idsp_automatic);
    idsp_room = 0;
    idsp_water = 0;
    idsp_player = 0;
    idsp_facingaway = 0;
    idsp_speaker = 0;
    idsp_spatial = 0;
    idsp_automatic = 0;
    DSP_FreeAll();
    g_bNeedPresetRestore = true;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10029000
// Name: _DSP_Process
// Source: json
//------------------------------------------------------------------------------
void __usercall DSP_Process(
        int a1@<ebx>,
        unsigned int idsp,
        portable_samplepair_t *pbfront,
        portable_samplepair_t *pbrear,
        portable_samplepair_t *pbcenter,
        int sampleCount)
{
  dsp_t *v6; // esi
  bool v7; // bl
  unsigned int v8; // edi
  int cchan; // edi
  int v10; // edx
  int v11; // [esp-8h] [ebp-14h]
  int cchan_in; // [esp+4h] [ebp-8h]
  bool bcrossfading; // [esp+8h] [ebp-4h]

  if ( idsp > 0x1F )
    return;
  if ( !g_pSoundServices->IsConnected(this: g_pSoundServices) )
    return;
  v6 = &dsps[idsp];
  if ( dsp_off.m_pParent != nullptr && dsp_off.m_pParent->m_Value.m_nValue != 0 )
    return;
  if ( !v6->bEnabled || v6->ipset == 0 && v6->ipsetprev == 0 || sampleCount < 0 )
    return;
  v11 = a1;
  v7 = !v6->xramp.fhitend;
  bcrossfading = v7;
  if ( v6->ipsetprev != 0 && v6->xramp.nEndRampTimeInMs < _Plat_MSTime(a1: v11) )
  {
    if ( snd_dsp_spew_changes.m_pParent != nullptr && snd_dsp_spew_changes.m_pParent->m_Value.m_nValue != 0 )
      DevMsg(
        a1: "[Sound DSP] For Dsp %d, suppress cross fading from presets %d to %d as previous preset is expired.\n",
        idsp,
        v6->ipsetprev,
        v6->ipset);
    v7 = false;
    v6->xramp.fhitend = true;
    bcrossfading = false;
    goto LABEL_16;
  }
  if ( !v7 )
LABEL_16:
    DSP_FreePrevPreset(pdsp: &dsps[idsp]);
  if ( v6->ipset != 0 || v6->ipsetprev != 0 )
  {
    v8 = _Plat_MSTime(a1: v11);
    if ( snd_dsp_spew_changes.m_pParent != nullptr && snd_dsp_spew_changes.m_pParent->m_Value.m_nValue != 0 )
    {
      if ( v7 )
      {
        DevMsg(
          a1: "[Sound DSP] Dsp %d processed. Cross-fading presets from %d to %d.\n",
          idsp,
          v6->ipsetprev,
          v6->ipset);
      }
      else if ( v8 > sLastDisplay + 1000 )
      {
        DevMsg(a1: "[Sound DSP] Dsp %d processed.\n", idsp);
        sLastDisplay = v8;
      }
    }
    if ( v6->ipset != 0 )
      v6->ppset[0]->nLastUpdatedTimeInMilliseconds = v8;
    if ( v6->ipsetprev != 0 )
      v6->ppsetprev[0]->nLastUpdatedTimeInMilliseconds = v8;
    cchan = v6->cchan;
    cchan_in = (pbcenter != nullptr) + 2 * (pbrear != nullptr) + 2;
    PSET_UpdateDuration(ppset: v6->ppset[0], SampleCount: sampleCount);
    if ( snd_spew_dsp_process.m_pParent != nullptr && snd_spew_dsp_process.m_pParent->m_Value.m_nValue != 0 )
    {
      _Msg(a1: "[Sound] DSP_Process() called. DSP index: %d - Sample cout: %d\n", idsp, v10);
      v10 = sampleCount;
    }
    switch ( cchan_in )
    {
      case 2:
        if ( cchan == 1 )
        {
          DSP_ProcessStereoToMono(pdsp: v6, pbfront, pbrear, sampleCount: v10, bcrossfading);
        }
        else if ( cchan >= 2 )
        {
          DSP_ProcessStereoToStereo(pdsp: v6, pbfront, pbrear, sampleCount: v10, bcrossfading);
        }
        break;
      case 4:
        switch ( cchan )
        {
          case 1:
            DSP_ProcessQuadToMono(pdsp: v6, pbfront, pbrear, sampleCount: v10, bcrossfading);
            break;
          case 2:
            DSP_ProcessQuadToStereo(pdsp: v6, pbfront, pbrear, sampleCount: v10, bcrossfading);
            break;
          case 4:
            DSP_ProcessQuadToQuad(pdsp: v6, pbfront, pbrear, sampleCount: v10, bcrossfading);
            break;
          default:
            break;
        }
        break;
      case 5:
        if ( cchan == 1 )
        {
          DSP_Process5To1(pdsp: v6, pbfront, pbrear, pbcenter, sampleCount: v10, bcrossfading);
        }
        else if ( cchan == 5 )
        {
          DSP_Process5To5(pdsp: v6, pbfront, pbrear, pbcenter, sampleCount: v10, bcrossfading);
        }
        break;
      default:
        break;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100292B0
// Name: void RVA_GetNext_Opt<0,1>(struct rva_t __near *,struct portable_samplepair_t __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl RVA_GetNext_Opt<0,1>(
        flt_t *pRva,
        portable_samplepair_t *pBuffer,
        int nCount,
        int a4,
        int a5,
        int a6,
        int a7,
        int a8,
        int a9,
        int a10,
        int a11,
        int a12,
        int a13,
        int a14,
        int a15,
        int a16,
        int a17,
        int a18,
        int a19,
        int a20,
        int a21,
        int a22,
        int a23,
        int a24,
        int a25)
{
  int v25; // ebx
  unsigned int v26; // esi
  void *v27; // esp
  unsigned int v28; // edi
  int v29; // esi
  rva_t *v30; // esi
  mdy_t **v31; // esi
  mdy_t *v32; // eax
  int v33; // esi
  bool v34; // zf
  dly_t **v35; // esi
  flt_t *pflt; // ecx
  int v37; // esi
  portable_samplepair_t *v38; // eax
  int *v39; // ecx
  unsigned int v40; // edx
  mdy_t *pModDelay; // [esp+Ch] [ebp-8h]
  int m; // [esp+10h] [ebp-4h]
  flt_t *pFilter; // [esp+1Ch] [ebp+8h]
  unsigned int pCurrentCacheLine; // [esp+24h] [ebp+10h]
  int *pCurrentCacheLinea; // [esp+24h] [ebp+10h]
  int *pCurrentCacheLineb; // [esp+24h] [ebp+10h]

  v25 = nCount;
  v26 = (4 * nCount + 127) & 0xFFFFFF80;
  m = pRva->b[0];
  v27 = alloca(v26 + 128);
  v28 = ((unsigned int)&a25 + 3) & 0xFFFFFF80;
  v29 = (int)((v26 + 127) & 0xFFFFFF80) / 128;
  for ( pCurrentCacheLine = ((unsigned int)&a25 + 3) & 0xFFFFFF80; v29 > 0; --v29 )
  {
    memset(dst: (unsigned __int8 *)(pCurrentCacheLine & 0xFFFFFF80), value: 0, count: 0x80u);
    pCurrentCacheLine += 128;
  }
  v30 = (rva_t *)pRva;
  if ( LOBYTE(pRva->w[1]) != 0 )
  {
    if ( m > 0 )
    {
      v31 = (mdy_t **)&pRva->a[2];
      pCurrentCacheLinea = &pRva->a[2];
      do
      {
        v32 = *v31;
        v33 = 0;
        for ( pModDelay = v32; v33 < v25; ++v33 )
          *(_DWORD *)(v28 + 4 * v33) += MDY_GetNext(pmdy: pModDelay, x: pBuffer[v33].left);
        v31 = (mdy_t **)(pCurrentCacheLinea + 1);
        v34 = m-- == 1;
        ++pCurrentCacheLinea;
      }
      while ( !v34 );
      goto LABEL_13;
    }
  }
  else if ( m > 0 )
  {
    v35 = (dly_t **)&pRva->b[3];
    for ( pCurrentCacheLineb = (int *)m;
          pCurrentCacheLineb != nullptr;
          pCurrentCacheLineb = (int *)((char *)pCurrentCacheLineb - 1) )
    {
      DLY_GetNext_Opt(
        pdly: *v35++,
        pIn: &pBuffer->left,
        pOut: (int *)(((unsigned int)&a25 + 3) & 0xFFFFFF80),
        nCount: v25);
    }
LABEL_13:
    v30 = (rva_t *)pRva;
  }
  if ( v30->fparallel == 0 )
  {
    pflt = v30->pflt;
    pFilter = pflt;
    if ( pflt != nullptr )
    {
      v37 = 0;
      if ( v25 > 0 )
      {
        while ( 1 )
        {
          *(_DWORD *)(v28 + 4 * v37) = FLT_GetNext(pf: pflt, x: *(_DWORD *)(v28 + 4 * v37));
          if ( ++v37 >= v25 )
            break;
          pflt = pFilter;
        }
      }
    }
  }
  v38 = pBuffer;
  v39 = (int *)(((unsigned int)&a25 + 3) & 0xFFFFFF80);
  if ( v25 >= 16 )
  {
    v40 = (unsigned int)v25 >> 4;
    v25 += -16 * ((unsigned int)v25 >> 4);
    do
    {
      v38->left = *v39;
      v38[1].left = v39[1];
      v38[2].left = v39[2];
      v38[3].left = v39[3];
      v38[4].left = v39[4];
      v38[5].left = v39[5];
      v38[6].left = v39[6];
      v38[7].left = v39[7];
      v38[8].left = v39[8];
      v38[9].left = v39[9];
      v38[10].left = v39[10];
      v38[11].left = v39[11];
      v38[12].left = v39[12];
      v38[13].left = v39[13];
      v38[14].left = v39[14];
      v38[15].left = v39[15];
      v38 += 16;
      v39 += 16;
      --v40;
    }
    while ( v40 != 0 );
  }
  if ( v25 >= 1 )
  {
    do
    {
      v38->left = *v39;
      ++v38;
      ++v39;
      --v25;
    }
    while ( v25 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10029460
// Name: void RVA_GetNext_Opt<1,2>(struct rva_t __near *,struct portable_samplepair_t __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl RVA_GetNext_Opt<1,2>(
        flt_t *pRva,
        portable_samplepair_t *pBuffer,
        int nCount,
        int a4,
        int a5,
        int a6,
        int a7,
        int a8,
        int a9,
        int a10,
        int a11,
        int a12,
        int a13,
        int a14,
        int a15,
        int a16,
        int a17,
        int a18,
        int a19,
        int a20,
        int a21,
        int a22,
        int a23,
        int a24,
        int a25)
{
  int v25; // ebx
  unsigned int v26; // esi
  void *v27; // esp
  unsigned int v28; // edi
  int v29; // esi
  rva_t *v30; // esi
  mdy_t **v31; // esi
  mdy_t *v32; // eax
  int v33; // esi
  bool v34; // zf
  dly_t **v35; // esi
  flt_t *pflt; // ecx
  int v37; // esi
  portable_samplepair_t *v38; // ecx
  int *v39; // eax
  unsigned int v40; // edx
  int *p_right; // ecx
  mdy_t *pModDelay; // [esp+Ch] [ebp-8h]
  int m; // [esp+10h] [ebp-4h]
  flt_t *pFilter; // [esp+1Ch] [ebp+8h]
  unsigned int pCurrentCacheLine; // [esp+24h] [ebp+10h]
  int *pCurrentCacheLinea; // [esp+24h] [ebp+10h]
  int *pCurrentCacheLineb; // [esp+24h] [ebp+10h]

  v25 = nCount;
  v26 = (4 * nCount + 127) & 0xFFFFFF80;
  m = pRva->b[0];
  v27 = alloca(v26 + 128);
  v28 = ((unsigned int)&a25 + 3) & 0xFFFFFF80;
  v29 = (int)((v26 + 127) & 0xFFFFFF80) / 128;
  for ( pCurrentCacheLine = ((unsigned int)&a25 + 3) & 0xFFFFFF80; v29 > 0; --v29 )
  {
    memset(dst: (unsigned __int8 *)(pCurrentCacheLine & 0xFFFFFF80), value: 0, count: 0x80u);
    pCurrentCacheLine += 128;
  }
  v30 = (rva_t *)pRva;
  if ( LOBYTE(pRva->w[1]) != 0 )
  {
    if ( m > 0 )
    {
      v31 = (mdy_t **)&pRva->a[2];
      pCurrentCacheLinea = &pRva->a[2];
      do
      {
        v32 = *v31;
        v33 = 0;
        for ( pModDelay = v32; v33 < v25; ++v33 )
          *(_DWORD *)(v28 + 4 * v33) += MDY_GetNext(pmdy: pModDelay, x: pBuffer[v33].right);
        v31 = (mdy_t **)(pCurrentCacheLinea + 1);
        v34 = m-- == 1;
        ++pCurrentCacheLinea;
      }
      while ( !v34 );
      goto LABEL_13;
    }
  }
  else if ( m > 0 )
  {
    v35 = (dly_t **)&pRva->b[3];
    for ( pCurrentCacheLineb = (int *)m;
          pCurrentCacheLineb != nullptr;
          pCurrentCacheLineb = (int *)((char *)pCurrentCacheLineb - 1) )
    {
      DLY_GetNext_Opt(
        pdly: *v35++,
        pIn: &pBuffer->right,
        pOut: (int *)(((unsigned int)&a25 + 3) & 0xFFFFFF80),
        nCount: v25);
    }
LABEL_13:
    v30 = (rva_t *)pRva;
  }
  if ( v30->fparallel == 0 )
  {
    pflt = v30->pflt;
    pFilter = pflt;
    if ( pflt != nullptr )
    {
      v37 = 0;
      if ( v25 > 0 )
      {
        while ( 1 )
        {
          *(_DWORD *)(v28 + 4 * v37) = FLT_GetNext(pf: pflt, x: *(_DWORD *)(v28 + 4 * v37));
          if ( ++v37 >= v25 )
            break;
          pflt = pFilter;
        }
      }
    }
  }
  v38 = pBuffer;
  v39 = (int *)(((unsigned int)&a25 + 3) & 0xFFFFFF80);
  if ( v25 >= 16 )
  {
    v40 = (unsigned int)v25 >> 4;
    v25 += -16 * ((unsigned int)v25 >> 4);
    do
    {
      v38->right = *v39;
      v38[1].right = v39[1];
      v38[2].right = v39[2];
      v38[3].right = v39[3];
      v38[4].right = v39[4];
      v38[5].right = v39[5];
      v38[6].right = v39[6];
      v38[7].right = v39[7];
      v38[8].right = v39[8];
      v38[9].right = v39[9];
      v38[10].right = v39[10];
      v38[11].right = v39[11];
      v38[12].right = v39[12];
      v38[13].right = v39[13];
      v38[14].right = v39[14];
      v38[15].right = v39[15];
      v38 += 16;
      v39 += 16;
      --v40;
    }
    while ( v40 != 0 );
  }
  if ( v25 >= 1 )
  {
    p_right = &v38->right;
    do
    {
      *p_right = *v39;
      p_right += 2;
      ++v39;
      --v25;
    }
    while ( v25 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10029610
// Name: void RVA_GetNext_Opt<0,3>(struct rva_t __near *,struct portable_samplepair_t __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl RVA_GetNext_Opt<0,3>(
        flt_t *pRva,
        portable_samplepair_t *pBuffer,
        int nCount,
        int a4,
        int a5,
        int a6,
        int a7,
        int a8,
        int a9,
        int a10,
        int a11,
        int a12,
        int a13,
        int a14,
        int a15,
        int a16,
        int a17,
        int a18,
        int a19,
        int a20,
        int a21,
        int a22,
        int a23,
        int a24,
        int a25)
{
  int v25; // ebx
  unsigned int v26; // esi
  void *v27; // esp
  unsigned int v28; // edi
  int v29; // esi
  rva_t *v30; // esi
  mdy_t **v31; // esi
  mdy_t *v32; // eax
  int v33; // esi
  bool v34; // zf
  dly_t **v35; // esi
  flt_t *pflt; // ecx
  int v37; // esi
  portable_samplepair_t *v38; // eax
  int *v39; // ecx
  unsigned int v40; // esi
  int v41; // edx
  int v42; // edx
  int v43; // edx
  int v44; // edx
  int v45; // edx
  int v46; // edx
  int v47; // edx
  int v48; // edx
  int v49; // edx
  int v50; // edx
  int v51; // edx
  int v52; // edx
  int v53; // edx
  int v54; // edx
  int v55; // edx
  int v56; // edx
  int v57; // edx
  mdy_t *pModDelay; // [esp+Ch] [ebp-8h]
  int m; // [esp+10h] [ebp-4h]
  flt_t *pFilter; // [esp+1Ch] [ebp+8h]
  unsigned int pCurrentCacheLine; // [esp+24h] [ebp+10h]
  int *pCurrentCacheLinea; // [esp+24h] [ebp+10h]
  int *pCurrentCacheLineb; // [esp+24h] [ebp+10h]

  v25 = nCount;
  v26 = (4 * nCount + 127) & 0xFFFFFF80;
  m = pRva->b[0];
  v27 = alloca(v26 + 128);
  v28 = ((unsigned int)&a25 + 3) & 0xFFFFFF80;
  v29 = (int)((v26 + 127) & 0xFFFFFF80) / 128;
  for ( pCurrentCacheLine = ((unsigned int)&a25 + 3) & 0xFFFFFF80; v29 > 0; --v29 )
  {
    memset(dst: (unsigned __int8 *)(pCurrentCacheLine & 0xFFFFFF80), value: 0, count: 0x80u);
    pCurrentCacheLine += 128;
  }
  v30 = (rva_t *)pRva;
  if ( LOBYTE(pRva->w[1]) != 0 )
  {
    if ( m > 0 )
    {
      v31 = (mdy_t **)&pRva->a[2];
      pCurrentCacheLinea = &pRva->a[2];
      do
      {
        v32 = *v31;
        v33 = 0;
        for ( pModDelay = v32; v33 < v25; ++v33 )
          *(_DWORD *)(v28 + 4 * v33) += MDY_GetNext(pmdy: pModDelay, x: pBuffer[v33].left);
        v31 = (mdy_t **)(pCurrentCacheLinea + 1);
        v34 = m-- == 1;
        ++pCurrentCacheLinea;
      }
      while ( !v34 );
      goto LABEL_13;
    }
  }
  else if ( m > 0 )
  {
    v35 = (dly_t **)&pRva->b[3];
    for ( pCurrentCacheLineb = (int *)m;
          pCurrentCacheLineb != nullptr;
          pCurrentCacheLineb = (int *)((char *)pCurrentCacheLineb - 1) )
    {
      DLY_GetNext_Opt(
        pdly: *v35++,
        pIn: &pBuffer->left,
        pOut: (int *)(((unsigned int)&a25 + 3) & 0xFFFFFF80),
        nCount: v25);
    }
LABEL_13:
    v30 = (rva_t *)pRva;
  }
  if ( v30->fparallel == 0 )
  {
    pflt = v30->pflt;
    pFilter = pflt;
    if ( pflt != nullptr )
    {
      v37 = 0;
      if ( v25 > 0 )
      {
        while ( 1 )
        {
          *(_DWORD *)(v28 + 4 * v37) = FLT_GetNext(pf: pflt, x: *(_DWORD *)(v28 + 4 * v37));
          if ( ++v37 >= v25 )
            break;
          pflt = pFilter;
        }
      }
    }
  }
  v38 = pBuffer;
  v39 = (int *)(((unsigned int)&a25 + 3) & 0xFFFFFF80);
  if ( v25 >= 16 )
  {
    v40 = (unsigned int)v25 >> 4;
    v25 += -16 * ((unsigned int)v25 >> 4);
    do
    {
      v41 = *v39;
      v38->right = *v39;
      v38->left = v41;
      v42 = v39[1];
      v38[1].right = v42;
      v38[1].left = v42;
      v43 = v39[2];
      v38[2].right = v43;
      v38[2].left = v43;
      v44 = v39[3];
      v38[3].right = v44;
      v38[3].left = v44;
      v45 = v39[4];
      v38[4].right = v45;
      v38[4].left = v45;
      v46 = v39[5];
      v38[5].right = v46;
      v38[5].left = v46;
      v47 = v39[6];
      v38[6].right = v47;
      v38[6].left = v47;
      v48 = v39[7];
      v38[7].right = v48;
      v38[7].left = v48;
      v49 = v39[8];
      v38[8].right = v49;
      v38[8].left = v49;
      v50 = v39[9];
      v38[9].right = v50;
      v38[9].left = v50;
      v51 = v39[10];
      v38[10].right = v51;
      v38[10].left = v51;
      v52 = v39[11];
      v38[11].right = v52;
      v38[11].left = v52;
      v53 = v39[12];
      v38[12].right = v53;
      v38[12].left = v53;
      v54 = v39[13];
      v38[13].right = v54;
      v38[13].left = v54;
      v55 = v39[14];
      v38[14].right = v55;
      v38[14].left = v55;
      v56 = v39[15];
      v38[15].right = v56;
      v38[15].left = v56;
      v38 += 16;
      v39 += 16;
      --v40;
    }
    while ( v40 != 0 );
  }
  if ( v25 >= 1 )
  {
    do
    {
      v57 = *v39;
      v38->right = *v39;
      v38->left = v57;
      ++v38;
      ++v39;
      --v25;
    }
    while ( v25 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10029800
// Name: void DFR_GetNext_Opt<0,1>(struct dfr_t __near *,struct portable_samplepair_t __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DFR_GetNext_Opt<0,1>(
        dfr_t *pdfr,
        portable_samplepair_t *pBuffer,
        unsigned int nCount,
        int a4,
        int a5,
        int a6,
        int a7,
        int a8,
        int a9,
        int a10,
        int a11,
        int a12,
        int a13,
        int a14,
        int a15,
        int a16,
        int a17,
        int a18,
        int a19,
        int a20,
        int a21,
        int a22,
        int a23,
        int a24,
        int a25,
        int a26,
        int a27)
{
  unsigned int v27; // edi
  void *v28; // esp
  int v29; // edi
  unsigned int i; // ebx
  int v31; // ebx
  dly_t *v32; // eax
  int v33; // edi
  dly_t **v34; // ebx
  portable_samplepair_t *v35; // eax
  int *v36; // ecx
  unsigned int v37; // edx
  int j; // edx

  v27 = (4 * nCount + 127) & 0xFFFFFF80;
  v28 = alloca(v27 + 128);
  v29 = (int)((v27 + 127) & 0xFFFFFF80) / 128;
  for ( i = ((unsigned int)&a27 + 3) & 0xFFFFFF80; v29 > 0; i += 128 )
  {
    memset(dst: (unsigned __int8 *)(i & 0xFFFFFF80), value: 0, count: 0x80u);
    --v29;
  }
  v31 = nCount;
  if ( pdfr->n != 0 )
  {
    v32 = pdfr->pdlys[0];
    DelayAllpass_Opt3<2,1>(
      nDelaySize: v32->D,
      tdelay: v32->t,
      psamps: v32->w,
      ppsamp: &v32->p,
      fbgain: v32->a,
      outgain: v32->b,
      pIn: &pBuffer->left,
      pOut: (int *)(((unsigned int)&a27 + 3) & 0xFFFFFF80),
      nCount);
  }
  v33 = 1;
  if ( pdfr->n > 1 )
  {
    v34 = &pdfr->pdlys[1];
    do
    {
      DelayAllpass_Opt3<1,1>(
        nDelaySize: (*v34)->D,
        tdelay: (*v34)->t,
        psamps: (*v34)->w,
        ppsamp: &(*v34)->p,
        fbgain: (*v34)->a,
        outgain: (*v34)->b,
        pIn: (int *)(((unsigned int)&a27 + 3) & 0xFFFFFF80),
        pOut: (int *)(((unsigned int)&a27 + 3) & 0xFFFFFF80),
        nCount);
      ++v33;
      ++v34;
    }
    while ( v33 < pdfr->n );
    v31 = nCount;
  }
  v35 = pBuffer;
  v36 = (int *)(((unsigned int)&a27 + 3) & 0xFFFFFF80);
  if ( v31 >= 16 )
  {
    v37 = (unsigned int)v31 >> 4;
    v31 += -16 * ((unsigned int)v31 >> 4);
    do
    {
      v35->left = *v36;
      v35[1].left = v36[1];
      v35[2].left = v36[2];
      v35[3].left = v36[3];
      v35[4].left = v36[4];
      v35[5].left = v36[5];
      v35[6].left = v36[6];
      v35[7].left = v36[7];
      v35[8].left = v36[8];
      v35[9].left = v36[9];
      v35[10].left = v36[10];
      v35[11].left = v36[11];
      v35[12].left = v36[12];
      v35[13].left = v36[13];
      v35[14].left = v36[14];
      v35[15].left = v36[15];
      v35 += 16;
      v36 += 16;
      --v37;
    }
    while ( v37 != 0 );
  }
  if ( v31 >= 1 )
  {
    for ( j = v31; j != 0; --j )
    {
      v35->left = *v36;
      ++v35;
      ++v36;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10029980
// Name: void DFR_GetNext_Opt<1,2>(struct dfr_t __near *,struct portable_samplepair_t __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DFR_GetNext_Opt<1,2>(
        dfr_t *pdfr,
        portable_samplepair_t *pBuffer,
        unsigned int nCount,
        int a4,
        int a5,
        int a6,
        int a7,
        int a8,
        int a9,
        int a10,
        int a11,
        int a12,
        int a13,
        int a14,
        int a15,
        int a16,
        int a17,
        int a18,
        int a19,
        int a20,
        int a21,
        int a22,
        int a23,
        int a24,
        int a25,
        int a26,
        int a27)
{
  unsigned int v27; // edi
  void *v28; // esp
  int v29; // edi
  unsigned int i; // ebx
  int v31; // ebx
  dly_t *v32; // eax
  int v33; // edi
  dly_t **v34; // ebx
  portable_samplepair_t *v35; // ecx
  int *v36; // eax
  unsigned int v37; // edx
  int *p_right; // ecx
  int j; // edx

  v27 = (4 * nCount + 127) & 0xFFFFFF80;
  v28 = alloca(v27 + 128);
  v29 = (int)((v27 + 127) & 0xFFFFFF80) / 128;
  for ( i = ((unsigned int)&a27 + 3) & 0xFFFFFF80; v29 > 0; i += 128 )
  {
    memset(dst: (unsigned __int8 *)(i & 0xFFFFFF80), value: 0, count: 0x80u);
    --v29;
  }
  v31 = nCount;
  if ( pdfr->n != 0 )
  {
    v32 = pdfr->pdlys[0];
    DelayAllpass_Opt3<2,1>(
      nDelaySize: v32->D,
      tdelay: v32->t,
      psamps: v32->w,
      ppsamp: &v32->p,
      fbgain: v32->a,
      outgain: v32->b,
      pIn: &pBuffer->right,
      pOut: (int *)(((unsigned int)&a27 + 3) & 0xFFFFFF80),
      nCount);
  }
  v33 = 1;
  if ( pdfr->n > 1 )
  {
    v34 = &pdfr->pdlys[1];
    do
    {
      DelayAllpass_Opt3<1,1>(
        nDelaySize: (*v34)->D,
        tdelay: (*v34)->t,
        psamps: (*v34)->w,
        ppsamp: &(*v34)->p,
        fbgain: (*v34)->a,
        outgain: (*v34)->b,
        pIn: (int *)(((unsigned int)&a27 + 3) & 0xFFFFFF80),
        pOut: (int *)(((unsigned int)&a27 + 3) & 0xFFFFFF80),
        nCount);
      ++v33;
      ++v34;
    }
    while ( v33 < pdfr->n );
    v31 = nCount;
  }
  v35 = pBuffer;
  v36 = (int *)(((unsigned int)&a27 + 3) & 0xFFFFFF80);
  if ( v31 >= 16 )
  {
    v37 = (unsigned int)v31 >> 4;
    v31 += -16 * ((unsigned int)v31 >> 4);
    do
    {
      v35->right = *v36;
      v35[1].right = v36[1];
      v35[2].right = v36[2];
      v35[3].right = v36[3];
      v35[4].right = v36[4];
      v35[5].right = v36[5];
      v35[6].right = v36[6];
      v35[7].right = v36[7];
      v35[8].right = v36[8];
      v35[9].right = v36[9];
      v35[10].right = v36[10];
      v35[11].right = v36[11];
      v35[12].right = v36[12];
      v35[13].right = v36[13];
      v35[14].right = v36[14];
      v35[15].right = v36[15];
      v35 += 16;
      v36 += 16;
      --v37;
    }
    while ( v37 != 0 );
  }
  if ( v31 >= 1 )
  {
    p_right = &v35->right;
    for ( j = v31; j != 0; --j )
    {
      *p_right = *v36;
      p_right += 2;
      ++v36;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10029B00
// Name: void DFR_GetNext_Opt<0,3>(struct dfr_t __near *,struct portable_samplepair_t __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DFR_GetNext_Opt<0,3>(
        dfr_t *pdfr,
        portable_samplepair_t *pBuffer,
        unsigned int nCount,
        int a4,
        int a5,
        int a6,
        int a7,
        int a8,
        int a9,
        int a10,
        int a11,
        int a12,
        int a13,
        int a14,
        int a15,
        int a16,
        int a17,
        int a18,
        int a19,
        int a20,
        int a21,
        int a22,
        int a23,
        int a24,
        int a25,
        int a26,
        int a27)
{
  unsigned int v27; // edi
  void *v28; // esp
  int v29; // edi
  unsigned int i; // ebx
  dly_t *v31; // eax
  int v32; // edi
  dly_t **v33; // ebx
  int v34; // edi
  portable_samplepair_t *v35; // eax
  int *v36; // ecx
  unsigned int v37; // esi
  int v38; // edx
  int v39; // edx
  int v40; // edx
  int v41; // edx
  int v42; // edx
  int v43; // edx
  int v44; // edx
  int v45; // edx
  int v46; // edx
  int v47; // edx
  int v48; // edx
  int v49; // edx
  int v50; // edx
  int v51; // edx
  int v52; // edx
  int v53; // edx
  int j; // esi
  int v55; // edx

  v27 = (4 * nCount + 127) & 0xFFFFFF80;
  v28 = alloca(v27 + 128);
  v29 = (int)((v27 + 127) & 0xFFFFFF80) / 128;
  for ( i = ((unsigned int)&a27 + 3) & 0xFFFFFF80; v29 > 0; i += 128 )
  {
    memset(dst: (unsigned __int8 *)(i & 0xFFFFFF80), value: 0, count: 0x80u);
    --v29;
  }
  if ( pdfr->n != 0 )
  {
    v31 = pdfr->pdlys[0];
    DelayAllpass_Opt3<2,1>(
      nDelaySize: v31->D,
      tdelay: v31->t,
      psamps: v31->w,
      ppsamp: &v31->p,
      fbgain: v31->a,
      outgain: v31->b,
      pIn: &pBuffer->left,
      pOut: (int *)(((unsigned int)&a27 + 3) & 0xFFFFFF80),
      nCount);
  }
  v32 = 1;
  if ( pdfr->n > 1 )
  {
    v33 = &pdfr->pdlys[1];
    do
    {
      DelayAllpass_Opt3<1,1>(
        nDelaySize: (*v33)->D,
        tdelay: (*v33)->t,
        psamps: (*v33)->w,
        ppsamp: &(*v33)->p,
        fbgain: (*v33)->a,
        outgain: (*v33)->b,
        pIn: (int *)(((unsigned int)&a27 + 3) & 0xFFFFFF80),
        pOut: (int *)(((unsigned int)&a27 + 3) & 0xFFFFFF80),
        nCount);
      ++v32;
      ++v33;
    }
    while ( v32 < pdfr->n );
  }
  v34 = nCount;
  v35 = pBuffer;
  v36 = (int *)(((unsigned int)&a27 + 3) & 0xFFFFFF80);
  if ( (int)nCount >= 16 )
  {
    v37 = nCount >> 4;
    v34 = -16 * (nCount >> 4) + nCount;
    do
    {
      v38 = *v36;
      v35->right = *v36;
      v35->left = v38;
      v39 = v36[1];
      v35[1].right = v39;
      v35[1].left = v39;
      v40 = v36[2];
      v35[2].right = v40;
      v35[2].left = v40;
      v41 = v36[3];
      v35[3].right = v41;
      v35[3].left = v41;
      v42 = v36[4];
      v35[4].right = v42;
      v35[4].left = v42;
      v43 = v36[5];
      v35[5].right = v43;
      v35[5].left = v43;
      v44 = v36[6];
      v35[6].right = v44;
      v35[6].left = v44;
      v45 = v36[7];
      v35[7].right = v45;
      v35[7].left = v45;
      v46 = v36[8];
      v35[8].right = v46;
      v35[8].left = v46;
      v47 = v36[9];
      v35[9].right = v47;
      v35[9].left = v47;
      v48 = v36[10];
      v35[10].right = v48;
      v35[10].left = v48;
      v49 = v36[11];
      v35[11].right = v49;
      v35[11].left = v49;
      v50 = v36[12];
      v35[12].right = v50;
      v35[12].left = v50;
      v51 = v36[13];
      v35[13].right = v51;
      v35[13].left = v51;
      v52 = v36[14];
      v35[14].right = v52;
      v35[14].left = v52;
      v53 = v36[15];
      v35[15].right = v53;
      v35[15].left = v53;
      v35 += 16;
      v36 += 16;
      --v37;
    }
    while ( v37 != 0 );
  }
  if ( v34 >= 1 )
  {
    for ( j = v34; j != 0; --j )
    {
      v55 = *v36;
      v35->right = *v36;
      v35->left = v55;
      ++v35;
      ++v36;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10029CB0
// Name: void RVA_GetNextN_Opt(struct rva_t __near *,struct portable_samplepair_t __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x10029D10
// Name: void DFR_GetNextN_Opt(struct dfr_t __near *,struct portable_samplepair_t __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x10029D70
// Name: bool PRC_InitAll(struct prc_t __near *,int)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl PRC_InitAll(prc_t *prcs, int count)
{
  int v2; // ecx
  bool result; // al
  bool v4; // cc
  int (__cdecl **p_pfnGetNext)(void *, int); // ebx
  void (__cdecl *v6)(flt_t *); // ecx
  int (__cdecl *v7)(lfo_t *); // edx
  void (__thiscall *v8)(vgui::PropertyPage *); // esi
  dly_t *(__cdecl *v9)(prc_t *); // eax
  void (__thiscall *v10)(vgui::PropertyPage *); // edi
  dly_t *v11; // eax
  bool fok; // [esp+3h] [ebp-1h]
  int counta; // [esp+10h] [ebp+Ch]

  v2 = count;
  result = true;
  fok = true;
  v4 = count <= 0;
  if ( count == 0 )
  {
    v2 = 1;
    v4 = false;
  }
  if ( !v4 )
  {
    p_pfnGetNext = &prcs->pfnGetNext;
    counta = v2;
    do
    {
      switch ( (unsigned int)*(p_pfnGetNext - 18) )
      {
        case 1u:
          v6 = (void (__cdecl *)(flt_t *))DLY_Free;
          v7 = (int (__cdecl *)(lfo_t *))DLY_GetNext;
          v8 = (void (__thiscall *)(vgui::PropertyPage *))DLY_GetNextN;
          v9 = DLY_VParams;
          v10 = CColorBalanceUIPanel::Init;
          break;
        case 2u:
          v6 = (void (__cdecl *)(flt_t *))RVA_Free;
          v7 = (int (__cdecl *)(lfo_t *))RVA_GetNext;
          v8 = (void (__thiscall *)(vgui::PropertyPage *))RVA_GetNextN_Opt;
          v9 = (dly_t *(__cdecl *)(prc_t *))RVA_VParams;
          v10 = CColorBalanceUIPanel::Init;
          break;
        case 3u:
          v6 = FLT_Free;
          v7 = (int (__cdecl *)(lfo_t *))FLT_GetNext;
          v8 = (void (__thiscall *)(vgui::PropertyPage *))FLT_GetNextN;
          v9 = (dly_t *(__cdecl *)(prc_t *))FLT_VParams;
          v10 = CColorBalanceUIPanel::Init;
          break;
        case 4u:
          v6 = (void (__cdecl *)(flt_t *))CRS_Free;
          v7 = (int (__cdecl *)(lfo_t *))CRS_GetNext;
          v8 = (void (__thiscall *)(vgui::PropertyPage *))CRS_GetNextN;
          v9 = (dly_t *(__cdecl *)(prc_t *))CRS_VParams;
          v10 = CColorBalanceUIPanel::Init;
          break;
        case 5u:
          v6 = (void (__cdecl *)(flt_t *))PTC_Free;
          v7 = (int (__cdecl *)(lfo_t *))PTC_GetNext;
          v8 = (void (__thiscall *)(vgui::PropertyPage *))PTC_GetNextN;
          v9 = (dly_t *(__cdecl *)(prc_t *))PTC_VParams;
          v10 = CColorBalanceUIPanel::Init;
          break;
        case 6u:
          v6 = (void (__cdecl *)(flt_t *))ENV_Free;
          v7 = (int (__cdecl *)(lfo_t *))ENV_GetNext;
          v8 = (void (__thiscall *)(vgui::PropertyPage *))ENV_GetNextN;
          v9 = (dly_t *(__cdecl *)(prc_t *))ENV_VParams;
          v10 = CColorBalanceUIPanel::Init;
          break;
        case 7u:
          v6 = (void (__cdecl *)(flt_t *))LFO_Free;
          v7 = LFO_GetNext;
          v8 = (void (__thiscall *)(vgui::PropertyPage *))LFO_GetNextN;
          v9 = (dly_t *(__cdecl *)(prc_t *))LFO_VParams;
          v10 = (void (__thiscall *)(vgui::PropertyPage *))LFO_Mod;
          break;
        case 8u:
          v6 = (void (__cdecl *)(flt_t *))EFO_Free;
          v7 = (int (__cdecl *)(lfo_t *))EFO_GetNext;
          v8 = (void (__thiscall *)(vgui::PropertyPage *))EFO_GetNextN;
          v9 = (dly_t *(__cdecl *)(prc_t *))EFO_VParams;
          v10 = CColorBalanceUIPanel::Init;
          break;
        case 9u:
          v6 = (void (__cdecl *)(flt_t *))MDY_Free;
          v7 = (int (__cdecl *)(lfo_t *))MDY_GetNext;
          v8 = (void (__thiscall *)(vgui::PropertyPage *))MDY_GetNextN;
          v9 = MDY_VParams;
          v10 = (void (__thiscall *)(vgui::PropertyPage *))MDY_Mod;
          break;
        case 0xAu:
          v6 = (void (__cdecl *)(flt_t *))DFR_Free;
          v7 = (int (__cdecl *)(lfo_t *))DFR_GetNext;
          v8 = (void (__thiscall *)(vgui::PropertyPage *))DFR_GetNextN_Opt;
          v9 = (dly_t *(__cdecl *)(prc_t *))DFR_VParams;
          v10 = CColorBalanceUIPanel::Init;
          break;
        case 0xBu:
          v6 = (void (__cdecl *)(flt_t *))AMP_Free;
          v7 = (int (__cdecl *)(lfo_t *))AMP_GetNext;
          v8 = (void (__thiscall *)(vgui::PropertyPage *))AMP_GetNextN;
          v9 = (dly_t *(__cdecl *)(prc_t *))AMP_VParams;
          v10 = CColorBalanceUIPanel::Init;
          break;
        default:
          v6 = (void (__cdecl *)(flt_t *))CColorBalanceUIPanel::Init;
          v7 = (int (__cdecl *)(lfo_t *))NULL_GetNext;
          v8 = CColorBalanceUIPanel::Init;
          v9 = (dly_t *(__cdecl *)(prc_t *))NULL_VParams;
          v10 = CColorBalanceUIPanel::Init;
          break;
      }
      p_pfnGetNext[2] = (int (__cdecl *)(void *, int))v6;
      *(p_pfnGetNext - 1) = (int (__cdecl *)(void *, int))v9;
      *p_pfnGetNext = (int (__cdecl *)(void *, int))v7;
      p_pfnGetNext[1] = (int (__cdecl *)(void *, int))v8;
      p_pfnGetNext[3] = (int (__cdecl *)(void *, int))v10;
      v11 = v9(p: (prc_t *)(p_pfnGetNext - 18));
      p_pfnGetNext[4] = (int (__cdecl *)(void *, int))v11;
      if ( v11 == nullptr )
        fok = false;
      p_pfnGetNext += 23;
      --counta;
    }
    while ( counta != 0 );
    return fok;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10029F70
// Name: struct pset_t __near * PSET_Alloc(int)
// Source: json
//------------------------------------------------------------------------------
pset_t *__cdecl PSET_Alloc(int ipsettemplate)
{
  int v1; // esi
  int v2; // ebx
  int *p_fused; // eax
  int v4; // ecx
  int *v5; // eax
  pset_t *v6; // ebx
  int cprcs; // eax
  void (__cdecl **p_pfnFree)(void *); // ebx
  int i; // esi
  float duration; // xmm0_4

  v1 = ipsettemplate;
  if ( ipsettemplate >= g_cpsettemplates )
    v1 = 0;
  v2 = 0;
  p_fused = &psets[1].fused;
  while ( *(p_fused - 134) != 0 )
  {
    if ( *p_fused == 0 )
    {
      ++v2;
      break;
    }
    if ( p_fused[134] == 0 )
    {
      v2 += 2;
      break;
    }
    if ( p_fused[268] == 0 )
    {
      v2 += 3;
      break;
    }
    p_fused += 536;
    v2 += 4;
    if ( (int)p_fused >= (int)&amps[11].rmp_interp.target )
      break;
  }
  if ( v2 == 64 )
    return nullptr;
  if ( das_debug.m_pParent != nullptr && das_debug.m_pParent->m_Value.m_nValue != 0 )
  {
    v4 = 0;
    v5 = &psets[1].fused;
    do
    {
      if ( *(v5 - 134) != 0 )
        ++v4;
      if ( *v5 != 0 )
        ++v4;
      if ( v5[134] != 0 )
        ++v4;
      if ( v5[268] != 0 )
        ++v4;
      v5 += 536;
    }
    while ( (int)v5 < (int)&amps[11].rmp_interp.target );
    DevMsg(a1: "total preset slots used: %d \n", v4);
  }
  v6 = &psets[v2];
  _V_memset(dest: v6, fill: 0, count: 536);
  qmemcpy(v6, &g_psettemplates[v1], sizeof(pset_t));
  v6->fused = 1;
  _V_memset(dest: v6->w, fill: 0, count: 32);
  if ( !PRC_InitAll(prcs: v6->prcs, count: v6->cprcs) )
  {
    _Warning(a1: "Sound DSP: preset failed to init.\n");
    cprcs = v6->cprcs;
    if ( cprcs > 0 )
    {
      p_pfnFree = &v6->prcs[0].pfnFree;
      for ( i = cprcs; i != 0; --i )
      {
        if ( *p_pfnFree != nullptr && p_pfnFree[2] != nullptr )
          (*p_pfnFree)(a1: p_pfnFree[2]);
        p_pfnFree += 23;
      }
    }
    return nullptr;
  }
  duration = v6->duration;
  if ( duration > 0.0 )
    v6->csamp_duration = (int)(float)(duration * 44100.0);
  return v6;
}

//------------------------------------------------------------------------------
// Address: 0x1002A0F0
// Name: int DSP_Alloc(int,float,int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl DSP_Alloc(int ipset, float xfade, int cchan)
{
  int v3; // ebx
  int v4; // edi
  dsp_t *v5; // eax
  dsp_t *v7; // esi
  pset_t **ppsetprev; // edi
  pset_t *v9; // eax
  double v10; // st7
  int cchans; // [esp+0h] [ebp-4h]
  int idsp; // [esp+14h] [ebp+10h]

  if ( cchan >= 1 )
  {
    cchans = 5;
    if ( cchan <= 5 )
      cchans = cchan;
  }
  else
  {
    cchans = 1;
  }
  v3 = 0;
  v4 = 0;
  v5 = &dsps[1];
  while ( v5[-1].fused )
  {
    if ( !v5->fused )
    {
      ++v4;
      break;
    }
    if ( !v5[1].fused )
    {
      v4 += 2;
      break;
    }
    if ( !v5[2].fused )
    {
      v4 += 3;
      break;
    }
    v5 += 4;
    v4 += 4;
    if ( (int)v5 >= (int)&psets[0].prcs[0].prm[10] )
      return -1;
  }
  idsp = v4;
  if ( v4 >= 32 )
    return -1;
  v7 = &dsps[v4];
  if ( (unsigned int)v4 <= 0x1F )
    _V_memset(dest: &dsps[v4], fill: 0, count: 116);
  *(_WORD *)&v7->fused = 257;
  v7->cchan = cchans;
  v7->ipset = ipset;
  v7->ipsetprev = 0;
  v7->ipsetsav_oneshot = 0;
  ppsetprev = v7->ppsetprev;
  do
  {
    if ( v7->ipset != 0 )
      v9 = PSET_Alloc(ipsettemplate: ipset);
    else
      v9 = nullptr;
    *(ppsetprev - 6) = v9;
    *ppsetprev = nullptr;
    ++v3;
    ++ppsetprev;
  }
  while ( v3 < v7->cchan );
  v7->xramp.fhitend = true;
  v10 = xfade * 0.001;
  v7->xfade = v10;
  v7->xfade_default = v10;
  return idsp;
}

//------------------------------------------------------------------------------
// Address: 0x1002A1F0
// Name: void DSP_SetPreset(int,int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __usercall DSP_SetPreset(int a1@<edi>, int idsp, int ipsetnew, const char *pDspName)
{
  dsp_t *v4; // esi
  int ipset; // eax
  int v6; // edi
  pset_t *v7; // eax
  int v8; // ecx
  pset_t **ppset; // eax
  int v10; // eax
  unsigned int v11; // eax
  int v12; // ecx
  float *p_type; // eax
  pset_t *v14; // eax
  pset_t *v15; // eax
  pset_t *v16; // ecx
  long double v17; // st7
  double xfade_default; // st7
  int v20; // [esp+1Ch] [ebp-18h]
  float ppsetnew; // [esp+30h] [ebp-4h] OVERLAPPED
  float ppsetnew_12; // [esp+3Ch] [ebp+8h]
  float ppsetnew_12a; // [esp+3Ch] [ebp+8h]
  float ppsetnew_16; // [esp+40h] [ebp+Ch]

  v4 = &dsps[idsp];
  if ( ipsetnew < g_cpsettemplates && ipsetnew >= 0 )
  {
    ipset = v4->ipset;
    if ( ipsetnew != ipset )
    {
      if ( snd_dsp_spew_changes.m_pParent != nullptr && snd_dsp_spew_changes.m_pParent->m_Value.m_nValue != 0 )
        DevMsg(a1: "[Sound DSP] For Dsp %d, %s switch presets from %d to %d.\n", idsp, pDspName, ipset, ipsetnew);
      v6 = 0;
      if ( v4->cchan <= 0 )
      {
LABEL_10:
        DSP_FreePrevPreset(pdsp: v4);
        v8 = 0;
        if ( v4->cchan > 0 )
        {
          ppset = v4->ppset;
          do
          {
            ppset[6] = *ppset;
            *ppset++ = (pset_t *)*(&v20 + v8++);
          }
          while ( v8 < v4->cchan );
        }
        v10 = v4->ipset;
        v4->ipsetprev = v10;
        v4->ipset = ipsetnew;
        if ( v10 != 0 )
        {
          v11 = _Plat_MSTime(a1);
          v12 = snd_dsp_cancel_old_preset_after_N_milliseconds.m_pParent != nullptr
              ? snd_dsp_cancel_old_preset_after_N_milliseconds.m_pParent->m_Value.m_nValue
              : 0;
          if ( v11 > v12 + v4->ppsetprev[0]->nLastUpdatedTimeInMilliseconds )
          {
            if ( snd_dsp_spew_changes.m_pParent != nullptr && snd_dsp_spew_changes.m_pParent->m_Value.m_nValue != 0 )
              DevMsg(
                a1: "[Sound DSP] For Dsp %d, %s previous preset %d has not been updated for a while. Do not cross-fade form it.\n",
                idsp,
                pDspName,
                v4->ipsetprev);
            DSP_FreePrevPreset(pdsp: v4);
          }
        }
        if ( idsp == idsp_room || idsp == idsp_automatic )
        {
          p_type = (float *)&v4->ppset[0]->type;
          ppsetnew_12 = p_type[118];
          ppsetnew_16 = p_type[119];
          ppsetnew = p_type[120];
          ConVar::SetValue(this: (ConVar *)&dsp_mix_min.IConVar, value: p_type[117]);
          ConVar::SetValue(this: (ConVar *)&dsp_mix_max.IConVar, value: ppsetnew_12);
          ConVar::SetValue(this: (ConVar *)&dsp_db_min.IConVar, value: ppsetnew_16);
          ConVar::SetValue(this: (ConVar *)&dsp_db_mixdrop.IConVar, value: ppsetnew);
        }
        v14 = v4->ppset[0];
        v4->xramp.fhitend = true;
        v4->ipsetsav_oneshot = 0;
        if ( v14 != nullptr && v14->duration > 0.0 )
        {
          v15 = v4->ppsetprev[0];
          if ( v15 == nullptr || v15->duration <= 0.0 )
            v4->ipsetsav_oneshot = v4->ipsetprev;
        }
        v16 = v4->ppsetprev[0];
        if ( v16 != nullptr && (v17 = fabs(v16->fade)) > 0.0 )
        {
          ppsetnew_12a = v17;
          v4->xfade = ppsetnew_12a;
          v4->bexpfade = v16->fade < 0.0;
        }
        else
        {
          xfade_default = v4->xfade_default;
          v4->bexpfade = false;
          v4->xfade = xfade_default;
        }
        RMP_Init(prmp: &v4->xramp, ramptime: v4->xfade, initval: 0, targetval: 4096, bEndAtTime: false);
      }
      else
      {
        while ( 1 )
        {
          v7 = PSET_Alloc(ipsettemplate: ipsetnew);
          *(&v20 + v6) = (int)v7;
          if ( v7 == nullptr )
            break;
          if ( ++v6 >= v4->cchan )
            goto LABEL_10;
        }
        DevMsg(a1: "WARNING: DSP preset failed to allocate.\n");
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002A430
// Name: bool HandlePresetChange(int,int __near &,int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __usercall HandlePresetChange@<al>(
        int a1@<edi>,
        unsigned int nDspIndex,
        int *nPrevPreset,
        int nNewPreset,
        const char *pDspName)
{
  dsp_t *v6; // esi

  if ( *nPrevPreset == nNewPreset )
    return 0;
  if ( nDspIndex > 0x1F )
    goto LABEL_10;
  v6 = &dsps[nDspIndex];
  if ( v6->ipsetprev != 0 && v6->xramp.nEndRampTimeInMs < _Plat_MSTime(a1) )
  {
    if ( snd_dsp_spew_changes.m_pParent != nullptr && snd_dsp_spew_changes.m_pParent->m_Value.m_nValue != 0 )
      DevMsg(
        a1: "[Sound DSP] For Dsp %d, don't consider cross fading from presets %d to %d as previous preset is expired.\n",
        nDspIndex,
        v6->ipsetprev,
        v6->ipset);
    goto LABEL_10;
  }
  if ( v6->xramp.fhitend )
  {
LABEL_10:
    DSP_SetPreset(a1: nDspIndex, idsp: nDspIndex, ipsetnew: nNewPreset, pDspName);
    *nPrevPreset = nNewPreset;
    return 1;
  }
  if ( snd_dsp_spew_changes.m_pParent != nullptr && snd_dsp_spew_changes.m_pParent->m_Value.m_nValue != 0 )
    DevMsg(
      a1: "[Sound DSP] For Dsp %d, %s changed presets from %d to %d. Have to wait end of cross-fading.\n",
      nDspIndex,
      pDspName,
      *nPrevPreset,
      nNewPreset);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1002A4F0
// Name: bool DSP_LoadPresetFile(void)
// Source: json
//------------------------------------------------------------------------------
char __cdecl DSP_LoadPresetFile()
{
  char v0; // bl
  const char *v2; // esi
  int v3; // edi
  pset_t *v4; // eax
  const char *v5; // eax
  const char *v6; // esi
  int v7; // edi
  const char *v8; // esi
  const char *v9; // esi
  const char *v10; // esi
  const char *v11; // esi
  const char *v12; // esi
  const char *v13; // esi
  long double v14; // st7
  double v15; // st6
  int v16; // esi
  double v17; // st6
  const char *v18; // ebx
  int v19; // eax
  int v20; // edi
  int m_nOffset; // ebx
  double v22; // st7
  int v23; // ebx
  CByteswap v24; // edi
  bool v25; // cc
  int m_Byteswap; // ecx
  char pDest[40]; // [esp+14h] [ebp-15Ch] BYREF
  char szFile[260]; // [esp+3Ch] [ebp-134h] BYREF
  CUtlBuffer buf; // [esp+140h] [ebp-30h]

  v0 = 0;
  V_snprintf(pDest, maxLen: 260, pFormat: "scripts/dsp_presets.txt");
  CUtlBuffer::CUtlBuffer(this: (CUtlBuffer *)&szFile[220], growSize: 0, initSize: 0, nFlags: 0);
  if ( g_pFullFileSystem->ReadFile(
         this: &g_pFullFileSystem->IBaseFileSystem,
         a2: pDest,
         a3: "GAME",
         a4: (CUtlBuffer *)&szFile[220],
         a5: 0,
         a6: 0,
         a7: nullptr) )
  {
    v2 = (const char *)(*(_DWORD *)&szFile[232] + *(_DWORD *)&szFile[220] - *(_DWORD *)&szFile[252]);
    v3 = DSP_CountFilePresets(pstart: v2);
    *(_DWORD *)&buf.m_Error = v3;
    g_cpsettemplates = v3;
    v4 = (pset_t *)MemAlloc_Alloc(nSize: (536 * (unsigned __int64)(unsigned int)v3) >> 32 != 0 ? -1 : 536 * v3);
    g_psettemplates = v4;
    if ( v4 != nullptr )
    {
      memset(dst: (unsigned __int8 *)v4, value: 0, count: 536 * v3);
      v5 = v2;
      buf.m_nMaxPut = 0;
      if ( v3 > 0 )
      {
        do
        {
          do
            v5 = COM_Parse(data: v5);
          while ( strlen(com_token) != 0 && com_token[0] != 123 );
          v6 = COM_Parse(data: v5);
          v7 = atoi(nptr: com_token);
          buf.m_nOffset = v7;
          v8 = COM_Parse(data: v6);
          buf.m_nTab = (int)DSP_LookupStringToken(psz: com_token, ipset: v7);
          v9 = COM_Parse(data: v8);
          *(float *)&buf.m_PutOverflowFunc = atof(nptr: com_token);
          v10 = COM_Parse(data: v9);
          *(float *)&buf.m_Byteswap = atof(nptr: com_token);
          v11 = COM_Parse(data: v10);
          *(float *)&buf.m_Memory.m_nGrowSize = atof(nptr: com_token);
          v12 = COM_Parse(data: v11);
          *(float *)&buf.m_Put = atof(nptr: com_token);
          v13 = COM_Parse(data: v12);
          *(float *)&buf.m_Get = atof(nptr: com_token);
          buf.m_GetOverflowFunc = (bool (__thiscall *)(CUtlBuffer *, int))COM_Parse(data: v13);
          v14 = atof(nptr: com_token);
          v15 = *(float *)&buf.m_PutOverflowFunc;
          v16 = v7;
          g_psettemplates[v16].fused = 1;
          g_psettemplates[v16].mix_min = v15;
          v17 = *(float *)&buf.m_Byteswap;
          buf.m_Byteswap = 0;
          g_psettemplates[v16].mix_max = v17;
          g_psettemplates[v16].duration = *(float *)&buf.m_Memory.m_nGrowSize;
          g_psettemplates[v16].fade = *(float *)&buf.m_Put;
          g_psettemplates[v16].db_min = *(float *)&buf.m_Get;
          g_psettemplates[v16].db_mixdrop = v14;
          while ( 1 )
          {
            v5 = COM_Parse(data: (const char *)buf.m_GetOverflowFunc);
            if ( strlen(com_token) != 0 )
              break;
LABEL_16:
            v18 = COM_Parse(data: v5);
            v19 = (int)DSP_LookupStringToken(psz: com_token, ipset: buf.m_nOffset);
            *(int *)((char *)&g_psettemplates->prcs[*(_DWORD *)&buf.m_Byteswap].type + v16 * 536) = v19;
            v20 = 0;
            for ( buf.m_GetOverflowFunc = (bool (__thiscall *)(CUtlBuffer *, int))COM_Parse(data: v18);
                  strlen(com_token) != 0;
                  buf.m_GetOverflowFunc = (bool (__thiscall *)(CUtlBuffer *, int))COM_Parse(data: (const char *)buf.m_GetOverflowFunc) )
            {
              if ( com_token[0] == 125 )
                break;
              m_nOffset = buf.m_nOffset;
              v22 = DSP_LookupStringToken(psz: com_token, ipset: buf.m_nOffset);
              v23 = v20 + 23 * *(_DWORD *)&buf.m_Byteswap + 134 * m_nOffset;
              ++v20;
              g_psettemplates->prcs[0].prm[v23] = v22;
              if ( v20 >= 16 )
                v20 = 16;
            }
            v24 = (CByteswap)(*(_DWORD *)&buf.m_Byteswap + 1);
            buf.m_Byteswap = v24;
            v25 = *(int *)&v24 < 5;
            if ( *(int *)&v24 > 5 )
            {
              DevMsg(
                a1: "DSP PARSE ERROR!!! dsp_presets.txt: missing } or too many processors in preset #: %3.0f \n",
                (double)buf.m_nOffset);
              v25 = *(int *)&v24 < 5;
            }
            if ( !v25 )
              buf.m_Byteswap = (CByteswap)5;
          }
          while ( 1 )
          {
            if ( com_token[0] == 123 )
              goto LABEL_16;
            if ( com_token[0] == 125 )
              break;
            v5 = COM_Parse(data: v5);
            if ( strlen(com_token) == 0 )
              goto LABEL_16;
          }
          m_Byteswap = (int)buf.m_Byteswap;
          if ( *(_DWORD *)&buf.m_Byteswap == 1 )
            buf.m_nTab = 0;
          g_psettemplates[v16].type = buf.m_nTab;
          g_psettemplates[v16].cprcs = m_Byteswap;
          ++buf.m_nMaxPut;
        }
        while ( buf.m_nMaxPut < *(int *)&buf.m_Error );
      }
      v0 = 1;
    }
    else
    {
      _Warning(a1: "DSP Preset Loader: Out of memory.\n");
    }
    if ( *(int *)&szFile[228] >= 0 && *(_DWORD *)&szFile[220] != 0 )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: *(void **)&szFile[220]);
    return v0;
  }
  else
  {
    _Error(a1: "DSP_LoadPresetFile: unable to open '%s'\n", pDest);
    if ( *(int *)&szFile[228] >= 0 && *(_DWORD *)&szFile[220] != 0 )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: *(void **)&szFile[220]);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002A8F0
// Name: _DSP_InitAll
// Source: json
//------------------------------------------------------------------------------
void __cdecl DSP_InitAll(bool bLoadPresetFile)
{
  flt_t *v1; // esi
  dly_t *v2; // esi
  rva_t *v3; // esi
  lfo_t *v4; // esi
  crs_t *v5; // esi
  ptc_t *v6; // esi
  env_t *v7; // esi
  efo_t *v8; // esi
  mdy_t *v9; // esi
  amp_t *v10; // esi
  pset_t *v11; // esi
  unsigned int v12; // edi
  dsp_t *v13; // esi

  if ( bLoadPresetFile )
    DSP_LoadPresetFile();
  v1 = flts;
  do
  {
    if ( v1 != nullptr )
      _V_memset(dest: v1, fill: 0, count: 184);
    ++v1;
  }
  while ( (int)v1 < (int)nuls );
  v2 = dlys;
  do
  {
    if ( v2 != nullptr )
      _V_memset(dest: v2, fill: 0, count: 72);
    ++v2;
  }
  while ( (int)v2 < (int)flts );
  v3 = rvas;
  do
  {
    if ( v3 != nullptr )
      _V_memset(dest: v3, fill: 0, count: 116);
    ++v3;
  }
  while ( (int)v3 < (int)mdys );
  LFOWAV_InitAll();
  v4 = lfos;
  do
  {
    if ( v4 != nullptr )
      _V_memset(dest: v4, fill: 0, count: 56);
    ++v4;
  }
  while ( (int)v4 < (int)lfowavs );
  v5 = crss;
  do
  {
    if ( v5 != nullptr )
      _V_memset(dest: v5, fill: 0, count: 16);
    ++v5;
  }
  while ( (int)v5 < (int)efos );
  v6 = ptcs;
  do
  {
    if ( v6 != nullptr )
      _V_memset(dest: v6, fill: 0, count: 72);
    ++v6;
  }
  while ( (int)v6 < (int)lfos );
  v7 = envs;
  do
  {
    if ( v7 != nullptr )
      _V_memset(dest: v7, fill: 0, count: 184);
    ++v7;
  }
  while ( (int)v7 < (int)ptcs );
  v8 = efos;
  do
  {
    if ( v8 != nullptr )
      _V_memset(dest: v8, fill: 0, count: 116);
    ++v8;
  }
  while ( (int)v8 < (int)envs );
  v9 = mdys;
  do
  {
    if ( v9 != nullptr )
      _V_memset(dest: v9, fill: 0, count: 76);
    ++v9;
  }
  while ( (int)v9 < (int)dlys );
  v10 = amps;
  do
  {
    if ( v10 != nullptr )
      _V_memset(dest: v10, fill: 0, count: 92);
    ++v10;
  }
  while ( (int)v10 < (int)crss );
  v11 = psets;
  do
    _V_memset(dest: v11++, fill: 0, count: 536);
  while ( (int)v11 < (int)amps );
  v12 = 0;
  v13 = dsps;
  do
  {
    if ( v12 <= 0x1F )
      _V_memset(dest: v13, fill: 0, count: 116);
    ++v13;
    ++v12;
  }
  while ( (int)v13 < (int)&idsp_automatic );
}

//------------------------------------------------------------------------------
// Address: 0x1002AAC0
// Name: _AllocDsps
// Source: json
//------------------------------------------------------------------------------
char __cdecl AllocDsps(bool bLoadPresetFile)
{
  int v1; // esi
  BOOL v2; // edi
  int m_nValue; // eax
  int v4; // eax
  int v5; // eax
  int v6; // eax
  int v7; // eax
  int v8; // esi
  int v9; // eax
  int v10; // eax
  int v11; // eax

  v1 = g_AudioDevice->IsSurround(this: g_AudioDevice) ? 2 : 0;
  v2 = g_AudioDevice->IsSurroundCenter(this: g_AudioDevice);
  DSP_InitAll(bLoadPresetFile);
  idsp_room = -1;
  idsp_water = -1;
  idsp_player = -1;
  idsp_facingaway = -1;
  idsp_speaker = -1;
  idsp_spatial = -1;
  idsp_automatic = -1;
  if ( dsp_room.m_pParent != nullptr )
    m_nValue = dsp_room.m_pParent->m_Value.m_nValue;
  else
    m_nValue = 0;
  idsp_room = DSP_Alloc(ipset: m_nValue, xfade: 200.0, cchan: 1);
  if ( dsp_automatic.m_pParent != nullptr )
    v4 = dsp_automatic.m_pParent->m_Value.m_nValue;
  else
    v4 = 0;
  idsp_automatic = DSP_Alloc(ipset: v4, xfade: 200.0, cchan: 1);
  if ( dsp_water.m_pParent != nullptr )
    v5 = dsp_water.m_pParent->m_Value.m_nValue;
  else
    v5 = 0;
  idsp_water = DSP_Alloc(ipset: v5, xfade: 100.0, cchan: 1);
  if ( dsp_player.m_pParent != nullptr )
    v6 = dsp_player.m_pParent->m_Value.m_nValue;
  else
    v6 = 0;
  idsp_player = DSP_Alloc(ipset: v6, xfade: 100.0, cchan: 1);
  if ( dsp_facingaway.m_pParent != nullptr )
    v7 = dsp_facingaway.m_pParent->m_Value.m_nValue;
  else
    v7 = 0;
  v8 = v2 + v1 + 2;
  idsp_facingaway = DSP_Alloc(ipset: v7, xfade: 100.0, cchan: v8);
  if ( dsp_speaker.m_pParent != nullptr )
    v9 = dsp_speaker.m_pParent->m_Value.m_nValue;
  else
    v9 = 0;
  idsp_speaker = DSP_Alloc(ipset: v9, xfade: 300.0, cchan: 1);
  if ( dsp_spatial.m_pParent != nullptr )
    v10 = dsp_spatial.m_pParent->m_Value.m_nValue;
  else
    v10 = 0;
  v11 = DSP_Alloc(ipset: v10, xfade: 300.0, cchan: v8);
  idsp_spatial = v11;
  if ( dsp_room.m_pParent != nullptr )
    ipset_room_prev = dsp_room.m_pParent->m_Value.m_nValue;
  else
    ipset_room_prev = 0;
  if ( dsp_water.m_pParent != nullptr )
    ipset_water_prev = dsp_water.m_pParent->m_Value.m_nValue;
  else
    ipset_water_prev = 0;
  if ( dsp_player.m_pParent != nullptr )
    ipset_player_prev = dsp_player.m_pParent->m_Value.m_nValue;
  else
    ipset_player_prev = 0;
  if ( dsp_facingaway.m_pParent != nullptr )
    ipset_facingaway_prev = dsp_facingaway.m_pParent->m_Value.m_nValue;
  else
    ipset_facingaway_prev = 0;
  if ( dsp_room_type.m_pParent != nullptr )
    ipset_room_typeprev = dsp_room_type.m_pParent->m_Value.m_nValue;
  else
    ipset_room_typeprev = 0;
  if ( dsp_speaker.m_pParent != nullptr )
    ipset_speaker_prev = dsp_speaker.m_pParent->m_Value.m_nValue;
  else
    ipset_speaker_prev = 0;
  if ( dsp_spatial.m_pParent != nullptr )
    ipset_spatial_prev = dsp_spatial.m_pParent->m_Value.m_nValue;
  else
    ipset_spatial_prev = 0;
  if ( dsp_automatic.m_pParent != nullptr )
    ipset_automatic_prev = dsp_automatic.m_pParent->m_Value.m_nValue;
  else
    ipset_automatic_prev = 0;
  if ( idsp_room >= 0
    && idsp_water >= 0
    && idsp_player >= 0
    && idsp_facingaway >= 0
    && idsp_speaker >= 0
    && v11 >= 0
    && idsp_automatic >= 0 )
  {
    return 1;
  }
  DevMsg(a1: "WARNING: DSP processor failed to initialize! \n");
  FreeDsps(bReleaseTemplateMemory: true);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1002AD90
// Name: void DSP_CheckRestorePresets(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DSP_CheckRestorePresets()
{
  PreserveDSP_t *v0; // esi
  int v1; // esi
  BOOL v2; // edi
  int m_nValue; // eax
  int v4; // eax
  int v5; // eax
  int v6; // eax
  int v7; // eax
  int v8; // esi
  int v9; // eax
  int v10; // eax
  int v11; // eax

  if ( g_bNeedPresetRestore )
  {
    g_bNeedPresetRestore = false;
    v0 = g_PreserveDSP;
    do
    {
      if ( v0->cvar->m_pParent->m_Value.m_fValue == 0.0 )
        ((void (__stdcall *)(_DWORD))v0->cvar->SetValue_3)(a1: v0->oldvalue);
      ++v0;
    }
    while ( (int)v0 < (int)&unk_10411EFC );
    v1 = g_AudioDevice->IsSurround(this: g_AudioDevice) ? 2 : 0;
    v2 = g_AudioDevice->IsSurroundCenter(this: g_AudioDevice);
    DSP_InitAll(bLoadPresetFile: false);
    idsp_room = -1;
    idsp_water = -1;
    idsp_player = -1;
    idsp_facingaway = -1;
    idsp_speaker = -1;
    idsp_spatial = -1;
    idsp_automatic = -1;
    if ( dsp_room.m_pParent != nullptr )
      m_nValue = dsp_room.m_pParent->m_Value.m_nValue;
    else
      m_nValue = 0;
    idsp_room = DSP_Alloc(ipset: m_nValue, xfade: 200.0, cchan: 1);
    if ( dsp_automatic.m_pParent != nullptr )
      v4 = dsp_automatic.m_pParent->m_Value.m_nValue;
    else
      v4 = 0;
    idsp_automatic = DSP_Alloc(ipset: v4, xfade: 200.0, cchan: 1);
    if ( dsp_water.m_pParent != nullptr )
      v5 = dsp_water.m_pParent->m_Value.m_nValue;
    else
      v5 = 0;
    idsp_water = DSP_Alloc(ipset: v5, xfade: 100.0, cchan: 1);
    if ( dsp_player.m_pParent != nullptr )
      v6 = dsp_player.m_pParent->m_Value.m_nValue;
    else
      v6 = 0;
    idsp_player = DSP_Alloc(ipset: v6, xfade: 100.0, cchan: 1);
    if ( dsp_facingaway.m_pParent != nullptr )
      v7 = dsp_facingaway.m_pParent->m_Value.m_nValue;
    else
      v7 = 0;
    v8 = v2 + v1 + 2;
    idsp_facingaway = DSP_Alloc(ipset: v7, xfade: 100.0, cchan: v8);
    if ( dsp_speaker.m_pParent != nullptr )
      v9 = dsp_speaker.m_pParent->m_Value.m_nValue;
    else
      v9 = 0;
    idsp_speaker = DSP_Alloc(ipset: v9, xfade: 300.0, cchan: 1);
    if ( dsp_spatial.m_pParent != nullptr )
      v10 = dsp_spatial.m_pParent->m_Value.m_nValue;
    else
      v10 = 0;
    v11 = DSP_Alloc(ipset: v10, xfade: 300.0, cchan: v8);
    idsp_spatial = v11;
    if ( dsp_room.m_pParent != nullptr )
      ipset_room_prev = dsp_room.m_pParent->m_Value.m_nValue;
    else
      ipset_room_prev = 0;
    if ( dsp_water.m_pParent != nullptr )
      ipset_water_prev = dsp_water.m_pParent->m_Value.m_nValue;
    else
      ipset_water_prev = 0;
    if ( dsp_player.m_pParent != nullptr )
      ipset_player_prev = dsp_player.m_pParent->m_Value.m_nValue;
    else
      ipset_player_prev = 0;
    if ( dsp_facingaway.m_pParent != nullptr )
      ipset_facingaway_prev = dsp_facingaway.m_pParent->m_Value.m_nValue;
    else
      ipset_facingaway_prev = 0;
    if ( dsp_room_type.m_pParent != nullptr )
      ipset_room_typeprev = dsp_room_type.m_pParent->m_Value.m_nValue;
    else
      ipset_room_typeprev = 0;
    if ( dsp_speaker.m_pParent != nullptr )
      ipset_speaker_prev = dsp_speaker.m_pParent->m_Value.m_nValue;
    else
      ipset_speaker_prev = 0;
    if ( dsp_spatial.m_pParent != nullptr )
      ipset_spatial_prev = dsp_spatial.m_pParent->m_Value.m_nValue;
    else
      ipset_spatial_prev = 0;
    if ( dsp_automatic.m_pParent != nullptr )
      ipset_automatic_prev = dsp_automatic.m_pParent->m_Value.m_nValue;
    else
      ipset_automatic_prev = 0;
    if ( idsp_room < 0
      || idsp_water < 0
      || idsp_player < 0
      || idsp_facingaway < 0
      || idsp_speaker < 0
      || v11 < 0
      || idsp_automatic < 0 )
    {
      DevMsg(a1: "WARNING: DSP processor failed to initialize! \n");
      FreeDsps(bReleaseTemplateMemory: true);
    }
    g_bdas_init_nodes = false;
    g_bdas_room_init = false;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002B0A0
// Name: _CheckNewDspPresets
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
char CheckNewDspPresets()
{
  int v0; // edi
  int m_nValue; // eax
  bool v2; // bl
  int v3; // ebx
  int ipsetsav_oneshot; // esi
  pset_t *v5; // eax
  unsigned int v6; // edx
  pset_t *v7; // ecx
  unsigned int v9; // [esp-8h] [ebp-28h]
  int v10; // [esp-4h] [ebp-24h]
  unsigned int v11; // [esp+0h] [ebp-20h]
  int v12; // [esp+4h] [ebp-1Ch]
  unsigned int v13; // [esp+8h] [ebp-18h]
  int iautomatic; // [esp+Ch] [ebp-14h]
  int iautomatica; // [esp+Ch] [ebp-14h]
  unsigned int ispatial; // [esp+10h] [ebp-10h]
  int ispatiala; // [esp+10h] [ebp-10h]
  int ifacingaway; // [esp+14h] [ebp-Ch]
  int ifacingawaya; // [esp+14h] [ebp-Ch]
  int iroomtype; // [esp+18h] [ebp-8h]
  int iroom; // [esp+1Ch] [ebp-4h]

  v0 = 0;
  if ( dsp_slow_cpu.m_pParent != nullptr )
    m_nValue = dsp_slow_cpu.m_pParent->m_Value.m_nValue;
  else
    m_nValue = 0;
  v2 = m_nValue != 0;
  DSP_CheckRestorePresets();
  if ( v2 )
  {
    iroom = 0;
    ifacingaway = 0;
    iroomtype = 0;
    ispatial = 0;
LABEL_6:
    iautomatic = 0;
    goto LABEL_7;
  }
  if ( dsp_room.m_pParent != nullptr )
    iroom = dsp_room.m_pParent->m_Value.m_nValue;
  else
    iroom = 0;
  if ( dsp_facingaway.m_pParent != nullptr )
    ifacingaway = dsp_facingaway.m_pParent->m_Value.m_nValue;
  else
    ifacingaway = 0;
  if ( dsp_room_type.m_pParent != nullptr )
    iroomtype = dsp_room_type.m_pParent->m_Value.m_nValue;
  else
    iroomtype = 0;
  if ( dsp_spatial.m_pParent != nullptr )
    ispatial = dsp_spatial.m_pParent->m_Value.m_nValue;
  else
    ispatial = 0;
  if ( dsp_automatic.m_pParent == nullptr )
    goto LABEL_6;
  iautomatic = dsp_automatic.m_pParent->m_Value.m_nValue;
LABEL_7:
  if ( dsp_water.m_pParent != nullptr )
    v3 = dsp_water.m_pParent->m_Value.m_nValue;
  else
    v3 = 0;
  if ( dsp_player.m_pParent != nullptr )
    ipsetsav_oneshot = dsp_player.m_pParent->m_Value.m_nValue;
  else
    ipsetsav_oneshot = 0;
  if ( dsp_speaker.m_pParent != nullptr )
    v0 = dsp_speaker.m_pParent->m_Value.m_nValue;
  if ( ipsetsav_oneshot == ipset_player_prev
    && ((unsigned int)idsp_player >= 0x20 || dsps[idsp_player].xramp.fhitend)
    && (unsigned int)idsp_player <= 0x1F )
  {
    v5 = dsps[idsp_player].ppset[0];
    if ( v5 != nullptr && v5->duration > 0.0 && v5->csamp_duration <= 0 )
    {
      ipsetsav_oneshot = dsps[idsp_player].ipsetsav_oneshot;
      CLoaderMemAlloc::CrtIsValidPointer(this: (ConVar *)&dsp_player.IConVar, value: ipsetsav_oneshot, a2: v9, a3: v10);
    }
  }
  v6 = idsp_room;
  if ( iroom == ipset_room_prev
    && ((unsigned int)idsp_room >= 0x20 || dsps[idsp_room].xramp.fhitend)
    && (unsigned int)idsp_room <= 0x1F )
  {
    v7 = dsps[idsp_room].ppset[0];
    if ( v7 != nullptr && v7->duration > 0.0 && v7->csamp_duration <= 0 )
    {
      iroom = dsps[idsp_room].ipsetsav_oneshot;
      CLoaderMemAlloc::CrtIsValidPointer(this: (ConVar *)&dsp_room.IConVar, value: iroom, a2: v11, a3: v12);
      v6 = idsp_room;
    }
  }
  if ( iroomtype != ipset_room_typeprev )
  {
    ipset_room_typeprev = iroomtype;
    CLoaderMemAlloc::CrtIsValidPointer(this: (ConVar *)&dsp_room.IConVar, value: iroomtype, a2: v13, a3: iautomatic);
    v6 = idsp_room;
  }
  if ( HandlePresetChange(a1: v0, nDspIndex: v6, nPrevPreset: &ipset_room_prev, nNewPreset: iroom, pDspName: "room") != 0 )
  {
    CLoaderMemAlloc::CrtIsValidPointer(
      this: (ConVar *)&dsp_room_type.IConVar,
      value: iroom,
      a2: ispatial,
      a3: ifacingaway);
    ipset_room_typeprev = iroom;
  }
  HandlePresetChange(a1: v0, nDspIndex: idsp_water, nPrevPreset: &ipset_water_prev, nNewPreset: v3, pDspName: "water");
  HandlePresetChange(
    a1: v0,
    nDspIndex: idsp_player,
    nPrevPreset: &ipset_player_prev,
    nNewPreset: ipsetsav_oneshot,
    pDspName: "player");
  HandlePresetChange(
    a1: v0,
    nDspIndex: idsp_facingaway,
    nPrevPreset: &ipset_facingaway_prev,
    nNewPreset: ifacingawaya,
    pDspName: "facingaway");
  HandlePresetChange(
    a1: v0,
    nDspIndex: idsp_speaker,
    nPrevPreset: &ipset_speaker_prev,
    nNewPreset: v0,
    pDspName: "speaker");
  HandlePresetChange(
    a1: v0,
    nDspIndex: idsp_spatial,
    nPrevPreset: &ipset_spatial_prev,
    nNewPreset: ispatiala,
    pDspName: "spatial");
  return HandlePresetChange(
           a1: v0,
           nDspIndex: idsp_automatic,
           nPrevPreset: &ipset_automatic_prev,
           nNewPreset: iautomatica,
           pDspName: "automatic");
}

//------------------------------------------------------------------------------
// Address: 0x1002B350
// Name: void DSP_DEBUGSetParams(int,int,float __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __usercall DSP_DEBUGSetParams(
        unsigned int a1@<ebx>,
        unsigned int a2@<edi>,
        int a3@<esi>,
        int ipreset,
        int iproc,
        float *pvalues,
        int cparams)
{
  int v7; // edx
  pset_t *v8; // eax
  int v9; // esi
  prc_t *v10; // ebx
  unsigned int v11; // edx
  float *v12; // eax
  float *v13; // ecx
  double v14; // st7
  pset_t new_pset; // [esp+0h] [ebp-21Ch] BYREF
  pset_t *v18; // [esp+218h] [ebp-4h]

  if ( cparams >= 0 )
  {
    if ( cparams <= 16 )
    {
      v7 = cparams;
    }
    else
    {
      cparams = 16;
      v7 = 16;
    }
  }
  else
  {
    v7 = 0;
    cparams = 0;
  }
  v8 = &g_psettemplates[ipreset];
  new_pset = *v8;
  v9 = 0;
  v18 = v8;
  v10 = &new_pset.prcs[iproc];
  if ( v7 >= 4 )
  {
    v11 = ((unsigned int)(v7 - 4) >> 2) + 1;
    v12 = pvalues + 1;
    v13 = &v10->prm[2];
    v9 = 4 * v11;
    do
    {
      v14 = *(v12 - 1);
      v12 += 4;
      *(float *)((char *)v12 + (char *)v10 - (char *)pvalues - 16) = v14;
      v13 += 4;
      --v11;
      *(v13 - 5) = *(v12 - 4);
      *(v13 - 4) = *(v12 - 3);
      *(v13 - 3) = *(v12 - 2);
    }
    while ( v11 != 0 );
    v7 = cparams;
    v8 = v18;
  }
  if ( v9 < v7 )
    qmemcpy(&v10->prm[v9], &pvalues[v9], 4 * (v7 - v9));
  *v8 = new_pset;
  CLoaderMemAlloc::CrtIsValidPointer(this: (ConVar *)&dsp_room.IConVar, value: 0, a2, a3);
  CheckNewDspPresets();
  CLoaderMemAlloc::CrtIsValidPointer(this: (ConVar *)&dsp_room.IConVar, value: ipreset, a2: a1, a3: new_pset.type);
  CheckNewDspPresets();
}

//------------------------------------------------------------------------------
// Address: 0x1002B450
// Name: void DSP_DEBUGReloadPresetFile(void)
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __usercall DSP_DEBUGReloadPresetFile(unsigned int a1@<ebx>, unsigned int a2@<edi>, int a3@<esi>)
{
  int m_nValue; // ebx
  int v4; // edi
  int v5; // esi
  int v9; // [esp-44h] [ebp-4Ch]
  unsigned int v10; // [esp-40h] [ebp-48h]
  int v11; // [esp-3Ch] [ebp-44h]
  unsigned int v12; // [esp-38h] [ebp-40h]
  int v13; // [esp-34h] [ebp-3Ch]
  unsigned int v14; // [esp-30h] [ebp-38h]
  int v15; // [esp-2Ch] [ebp-34h]
  unsigned int v16; // [esp-28h] [ebp-30h]
  int v17; // [esp-24h] [ebp-2Ch]
  unsigned int v18; // [esp-20h] [ebp-28h]
  int v19; // [esp-1Ch] [ebp-24h]
  unsigned int v20; // [esp-18h] [ebp-20h]
  int v21; // [esp-14h] [ebp-1Ch]
  unsigned int v22; // [esp-10h] [ebp-18h]
  int v23; // [esp-Ch] [ebp-14h]
  unsigned int v24; // [esp-8h] [ebp-10h]
  int v25; // [esp-4h] [ebp-Ch]
  int iwater; // [esp+0h] [ebp-8h]
  int iroom; // [esp+4h] [ebp-4h]

  if ( dsp_room.m_pParent != nullptr )
    iroom = dsp_room.m_pParent->m_Value.m_nValue;
  else
    iroom = 0;
  if ( dsp_water.m_pParent != nullptr )
    iwater = dsp_water.m_pParent->m_Value.m_nValue;
  else
    iwater = 0;
  if ( dsp_player.m_pParent != nullptr )
    m_nValue = dsp_player.m_pParent->m_Value.m_nValue;
  else
    m_nValue = 0;
  if ( dsp_speaker.m_pParent != nullptr )
    v4 = dsp_speaker.m_pParent->m_Value.m_nValue;
  else
    v4 = 0;
  if ( dsp_spatial.m_pParent != nullptr )
    v5 = dsp_spatial.m_pParent->m_Value.m_nValue;
  else
    v5 = 0;
  if ( g_psettemplates != nullptr )
  {
    free(pMem: g_psettemplates);
    g_psettemplates = nullptr;
  }
  DSP_LoadPresetFile();
  CLoaderMemAlloc::CrtIsValidPointer(this: (ConVar *)&dsp_room.IConVar, value: 0, a2, a3);
  CLoaderMemAlloc::CrtIsValidPointer(this: (ConVar *)&dsp_water.IConVar, value: 0, a2: a1, a3: v9);
  CLoaderMemAlloc::CrtIsValidPointer(this: (ConVar *)&dsp_player.IConVar, value: 0, a2: v10, a3: v11);
  CLoaderMemAlloc::CrtIsValidPointer(this: (ConVar *)&dsp_speaker.IConVar, value: 0, a2: v12, a3: v13);
  CLoaderMemAlloc::CrtIsValidPointer(this: (ConVar *)&dsp_spatial.IConVar, value: 0, a2: v14, a3: v15);
  CheckNewDspPresets();
  CLoaderMemAlloc::CrtIsValidPointer(this: (ConVar *)&dsp_room.IConVar, value: iroom, a2: v16, a3: v17);
  CLoaderMemAlloc::CrtIsValidPointer(this: (ConVar *)&dsp_water.IConVar, value: iwater, a2: v18, a3: v19);
  CLoaderMemAlloc::CrtIsValidPointer(this: (ConVar *)&dsp_player.IConVar, value: m_nValue, a2: v20, a3: v21);
  CLoaderMemAlloc::CrtIsValidPointer(this: (ConVar *)&dsp_speaker.IConVar, value: v4, a2: v22, a3: v23);
  CLoaderMemAlloc::CrtIsValidPointer(this: (ConVar *)&dsp_spatial.IConVar, value: v5, a2: v24, a3: v25);
  CheckNewDspPresets();
  g_bdas_init_nodes = false;
  g_bdas_room_init = false;
}

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x1001D4B0
// Name: char const __near * GetIndentationText(int)
// Source: json
//------------------------------------------------------------------------------
char *__cdecl GetIndentationText(int nIndentation)
{
  int v1; // ecx

  if ( sFirstTime )
  {
    strcpy(sIndentationBuffer, "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t");
    sFirstTime = false;
  }
  v1 = nIndentation;
  if ( nIndentation > 32 )
    v1 = 32;
  return &byte_1045F364[-v1];
}

//------------------------------------------------------------------------------
// Address: 0x1001D510
// Name: int IIRFilter_Update_Order1(int __near *,int,int __near *,int __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl IIRFilter_Update_Order1(int *denom, int cnumer, int *numer, int *psamp, int in)
{
  int result; // eax
  int v6; // esi
  int v7; // ecx

  if ( *psamp == 0 && psamp[1] == 0 && in == 0 )
    return 0;
  v6 = psamp[1];
  v7 = in - ((v6 * denom[1]) >> 12);
  *psamp = v7;
  result = (v7 * *numer + v6 * numer[1]) >> 12;
  psamp[1] = v7;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1001D560
// Name: void ReverbSimple_Opt(int,int,int __near *,int __near * __near *,int,int,int __near *,int __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ReverbSimple_Opt(
        int delaysize,
        int tdelay,
        int *psamps,
        int **ppsamp,
        int fbgain,
        int outgain,
        int *pIn,
        int *pOut,
        int nCount)
{
  int *v10; // eax
  int v11; // eax
  int v12; // eax
  int v13; // [esp+4h] [ebp-4h]

  if ( nCount > 0 )
  {
    v13 = 4 * delaysize;
    do
    {
      --nCount;
      v10 = &(*ppsamp)[tdelay];
      if ( v10 > &psamps[delaysize] )
        v11 = v10[v13 / 0xFFFFFFFC - 1];
      else
        v11 = *v10;
      v12 = *pIn + ((fbgain * v11) >> 12);
      *(*ppsamp)-- = v12;
      if ( *ppsamp < psamps )
        *ppsamp = (int *)((char *)*ppsamp + v13 + 4);
      pIn += 2;
      *pOut++ += (outgain * v12) >> 12;
    }
    while ( nCount > 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001D5E0
// Name: int ReverbSimple_multitap(int,int,int,int,int,int __near *,int __near * __near *,int,int,int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ReverbSimple_multitap(
        int delaysize,
        int tdelay0,
        int tdelay1,
        int tdelay2,
        int tdelay3,
        int *psamps,
        int **ppsamp,
        int fbgain,
        int outgain,
        int in)
{
  _DWORD *v11; // edx
  int v12; // edi
  int *v13; // eax
  int *v14; // ecx
  int v15; // eax
  int *v16; // eax
  int v17; // eax
  int *v18; // eax
  int v19; // ebx
  int *v20; // eax
  int v21; // eax
  int s1; // [esp+18h] [ebp+Ch]
  int s2; // [esp+2Ch] [ebp+20h]

  v11 = *ppsamp;
  v12 = 4 * delaysize;
  v13 = &(*ppsamp)[tdelay0];
  v14 = &psamps[delaysize];
  if ( v13 > v14 )
    v15 = v13[v12 / 0xFFFFFFFC - 1];
  else
    v15 = *v13;
  s1 = v15;
  v16 = &v11[tdelay1];
  if ( v16 > v14 )
    v17 = v16[v12 / 0xFFFFFFFC - 1];
  else
    v17 = *v16;
  s2 = v17;
  v18 = &v11[tdelay2];
  if ( v18 > v14 )
    v19 = v18[v12 / 0xFFFFFFFC - 1];
  else
    v19 = *v18;
  v20 = &v11[tdelay3];
  if ( v20 > v14 )
    v21 = v20[v12 / 0xFFFFFFFC - 1];
  else
    v21 = *v20;
  *v11 = in + ((fbgain * v21) >> 12);
  if ( --*ppsamp < psamps )
    *ppsamp = (int *)((char *)*ppsamp + v12 + 4);
  return (outgain * (s1 + s2 + v21 + v19 + in)) >> 12;
}

//------------------------------------------------------------------------------
// Address: 0x1001D680
// Name: void ReverbSimple_multitap_Opt(int,int,int,int,int,int __near *,int __near * __near *,int,int,int __near *,int __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ReverbSimple_multitap_Opt(
        int delaysize,
        int tdelay0,
        int tdelay1,
        int tdelay2,
        int tdelay3,
        int *psamps,
        int **ppsamp,
        int fbgain,
        int outgain,
        int *pIn,
        int *pOut,
        int nCount)
{
  int v12; // ecx
  int *v13; // ebx
  int v14; // edi
  _DWORD *v15; // edx
  int *v16; // eax
  int v17; // eax
  int *v18; // eax
  int v19; // eax
  int *v20; // eax
  int v21; // ecx
  int *v22; // eax
  int v23; // eax
  int v24; // ecx
  int v25; // [esp+4h] [ebp-Ch]
  int v26; // [esp+8h] [ebp-8h]
  int v27; // [esp+Ch] [ebp-4h]

  if ( nCount > 0 )
  {
    v12 = 4 * delaysize;
    v13 = &psamps[delaysize];
    v27 = 4 * delaysize;
    while ( 1 )
    {
      v14 = *pIn;
      v15 = *ppsamp;
      --nCount;
      v16 = &(*ppsamp)[tdelay0];
      v17 = v16 > v13 ? v16[v12 / 0xFFFFFFFC - 1] : *v16;
      v25 = v17;
      v18 = &v15[tdelay1];
      v19 = v18 > v13 ? v18[v12 / 0xFFFFFFFC - 1] : *v18;
      v26 = v19;
      v20 = &v15[tdelay2];
      v21 = v20 > v13 ? v20[v12 / 0xFFFFFFFC - 1] : *v20;
      v22 = &v15[tdelay3];
      v23 = v22 > v13 ? v22[v27 / 0xFFFFFFFC - 1] : *v22;
      v24 = v25 + v26 + v23 + v21;
      *v15 = v14 + ((fbgain * v23) >> 12);
      if ( --*ppsamp < psamps )
        *ppsamp = (int *)((char *)*ppsamp + v27 + 4);
      pIn += 2;
      *pOut++ += (outgain * (v14 + v24)) >> 12;
      if ( nCount <= 0 )
        break;
      v13 = &psamps[delaysize];
      v12 = 4 * delaysize;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001D770
// Name: int ReverbSimple_multitap_xfade(int,int,int,int,int,int,int,int __near *,int __near * __near *,int,int,int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ReverbSimple_multitap_xfade(
        int delaysize,
        int tdelay0,
        int tdelaynew,
        int xf,
        int tdelay1,
        int tdelay2,
        int tdelay3,
        int *psamps,
        int **ppsamp,
        int fbgain,
        int outgain,
        int in)
{
  _DWORD *v13; // edx
  int v14; // ebx
  int *v15; // eax
  int *v16; // esi
  int v17; // ecx
  int *v18; // eax
  int v19; // eax
  int v20; // eax
  int *v21; // ecx
  int v22; // ecx
  int *v23; // ecx
  int v24; // ecx
  int *v25; // ecx
  int v26; // ecx
  int v27; // ecx
  int s1; // [esp+2Ch] [ebp+20h]
  int s2; // [esp+34h] [ebp+28h]

  v13 = *ppsamp;
  v14 = 4 * delaysize;
  v15 = &(*ppsamp)[tdelay3];
  v16 = &psamps[delaysize];
  if ( v15 > v16 )
    v17 = v15[v14 / 0xFFFFFFFC - 1];
  else
    v17 = *v15;
  v18 = &v13[tdelaynew];
  if ( v18 > v16 )
    v19 = v18[v14 / 0xFFFFFFFC - 1];
  else
    v19 = *v18;
  v20 = v17 + ((xf * (v19 - v17)) >> 12);
  v21 = &v13[tdelay0];
  if ( v21 > v16 )
    v22 = v21[v14 / 0xFFFFFFFC - 1];
  else
    v22 = *v21;
  s1 = v22;
  v23 = &v13[tdelay1];
  if ( v23 > v16 )
    v24 = v23[v14 / 0xFFFFFFFC - 1];
  else
    v24 = *v23;
  s2 = v24;
  v25 = &v13[tdelay2];
  if ( v25 > v16 )
    v26 = v25[v14 / 0xFFFFFFFC - 1];
  else
    v26 = *v25;
  v27 = v20 + s1 + s2 + v26;
  *v13 = in + ((fbgain * v20) >> 12);
  if ( --*ppsamp < psamps )
    *ppsamp = (int *)((char *)*ppsamp + v14 + 4);
  return (outgain * (v27 + in)) >> 12;
}

//------------------------------------------------------------------------------
// Address: 0x1001D880
// Name: void DelayLinear_Opt(int,int,int __near *,int __near * __near *,int __near *,int __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DelayLinear_Opt(int delaysize, int tdelay, int *psamps, int **ppsamp, int *pIn, int *pOut, int nCount)
{
  int *v8; // eax
  int v9; // eax
  int v10; // [esp+4h] [ebp-4h]

  if ( nCount > 0 )
  {
    v10 = 4 * delaysize;
    do
    {
      --nCount;
      v8 = &(*ppsamp)[tdelay];
      if ( v8 > &psamps[delaysize] )
        v9 = v8[v10 / 0xFFFFFFFC - 1];
      else
        v9 = *v8;
      *(*ppsamp)-- = *pIn;
      if ( *ppsamp < psamps )
        *ppsamp = (int *)((char *)*ppsamp + v10 + 4);
      *pOut += v9;
      pIn += 2;
      ++pOut;
    }
    while ( nCount > 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001D8F0
// Name: int DelayLinear_xfade(int,int,int,int,int __near *,int __near * __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl DelayLinear_xfade(int delaysize, int tdelay, int tdelaynew, int xf, int *psamps, int **ppsamp, int in)
{
  _DWORD *v7; // esi
  int v8; // edi
  int *v9; // eax
  int *v10; // ebx
  int v11; // eax
  int *v12; // ecx
  int v13; // ecx
  int result; // eax

  v7 = *ppsamp;
  v8 = 4 * delaysize;
  v9 = &(*ppsamp)[tdelay];
  v10 = &psamps[delaysize];
  if ( v9 > v10 )
    v11 = v9[v8 / 0xFFFFFFFC - 1];
  else
    v11 = *v9;
  v12 = &v7[tdelaynew];
  if ( v12 > v10 )
    v13 = v12[v8 / 0xFFFFFFFC - 1];
  else
    v13 = *v12;
  result = ((xf * (v13 - v11)) >> 12) + v11;
  *v7 = in;
  if ( --*ppsamp < psamps )
    *ppsamp = (int *)((char *)*ppsamp + v8 + 4);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1001D960
// Name: int DelayLowPass(int,int,int __near *,int __near * __near *,int,int,int __near *,int,int __near *,int __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl DelayLowPass(
        int delaysize,
        int tdelay,
        int *psamps,
        int **ppsamp,
        int fbgain,
        int outgain,
        int *denom,
        int Ll,
        int *numer,
        int *pfsamps,
        int in)
{
  int v11; // edi
  int *v12; // eax
  int v13; // eax
  int v14; // edi
  int v15; // ecx
  int v16; // eax
  int v17; // eax

  v11 = 4 * delaysize;
  v12 = &(*ppsamp)[tdelay];
  if ( v12 > &psamps[delaysize] )
    v13 = v12[v11 / 0xFFFFFFFC - 1];
  else
    v13 = *v12;
  if ( *pfsamps != 0 || pfsamps[1] != 0 || v13 != 0 )
  {
    v14 = pfsamps[1];
    v15 = v13 - ((v14 * denom[1]) >> 12);
    *pfsamps = v15;
    v16 = v15 * *numer + v14 * numer[1];
    v11 = 4 * delaysize;
    v13 = v16 >> 12;
    pfsamps[1] = v15;
  }
  v17 = in + v13;
  *(*ppsamp)-- = v17;
  if ( *ppsamp < psamps )
    *ppsamp = (int *)((char *)*ppsamp + v11 + 4);
  return (outgain * v17) >> 12;
}

//------------------------------------------------------------------------------
// Address: 0x1001DA00
// Name: void DelayLowPass_Opt2(int,int,int __near *,int __near * __near *,int,int,int __near *,int,int __near *,int __near *,int __near *,int __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DelayLowPass_Opt2(
        int nDelaySize,
        int tdelay,
        int *psamps,
        int **ppsamp,
        int fbgain,
        int outgain,
        int *denom,
        int Ll,
        int *numer,
        int *pfsamps,
        int *pIn,
        int *pOut,
        int nCount)
{
  int *v13; // edx
  int *v14; // edi
  int v15; // esi
  int v16; // ecx
  int v18; // eax
  int v19; // ecx
  int v20; // eax
  int numer1; // [esp+8h] [ebp-8h]
  int numer0; // [esp+Ch] [ebp-4h]
  int nDelaySizeP1; // [esp+18h] [ebp+8h]
  int denom1; // [esp+30h] [ebp+20h]
  int *pSampsPDelaySize; // [esp+38h] [ebp+28h]

  numer0 = *numer;
  denom1 = denom[1];
  numer1 = numer[1];
  v13 = *ppsamp;
  v14 = pfsamps;
  v15 = pfsamps[1];
  pSampsPDelaySize = &psamps[nDelaySize];
  v16 = nDelaySize + 1;
  nDelaySizeP1 = nDelaySize + 1;
  if ( nCount > 0 )
  {
    do
    {
      v18 = v13[tdelay - (v16 & (((char *)pSampsPDelaySize - (char *)&v13[tdelay]) >> 31))] - ((v15 * denom1) >> 12);
      --nCount;
      v19 = v15 * numer1 + numer0 * v18;
      v15 = v18;
      v20 = (v19 >> 12) + *pIn;
      v16 = nDelaySizeP1;
      *v13 = v20;
      pIn += 2;
      *pOut++ += (outgain * v20) >> 12;
      v13 = &v13[(nDelaySizeP1 & (((char *)(v13 - 1) - (char *)psamps) >> 31)) - 1];
    }
    while ( nCount > 0 );
    v14 = pfsamps;
  }
  *ppsamp = v13;
  *v14 = v15;
  v14[1] = v15;
}

//------------------------------------------------------------------------------
// Address: 0x1001DAD0
// Name: void DelayLowPass_Opt3(int,int,int __near *,int __near * __near *,int,int,int __near *,int,int __near *,int __near *,int __near *,int __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DelayLowPass_Opt3(
        int nDelaySize,
        int *tdelay,
        int *psamps,
        int **ppsamp,
        int fbgain,
        int outgain,
        int *denom,
        int Ll,
        int *numer,
        int *pfsamps,
        int *pIn,
        int *pOut,
        unsigned int nCount)
{
  int v13; // eax
  int v14; // edi
  int v15; // ebx
  int *v16; // ecx
  int v17; // esi
  int *v18; // edx
  int *v19; // esi
  int v20; // eax
  int v21; // edx
  int v22; // eax
  int v23; // edx
  int v24; // eax
  int v25; // ecx
  int v26; // edx
  int v27; // eax
  int v28; // ecx
  int v29; // edx
  unsigned int v30; // [esp+0h] [ebp-30h]
  int outA; // [esp+4h] [ebp-2Ch]
  int denom1; // [esp+8h] [ebp-28h]
  int *pSampsPDelaySize; // [esp+Ch] [ebp-24h]
  int pInputDelaySampleD; // [esp+10h] [ebp-20h]
  int *v35; // [esp+14h] [ebp-1Ch]
  int *pDelaySampleA; // [esp+18h] [ebp-18h]
  int numer0; // [esp+1Ch] [ebp-14h]
  int numer1; // [esp+20h] [ebp-10h]
  int nFilteredOutputA; // [esp+24h] [ebp-Ch]
  int *pDelaySampleC; // [esp+28h] [ebp-8h]
  int *pDelaySampleB; // [esp+2Ch] [ebp-4h]
  int *pDelaySampleD; // [esp+3Ch] [ebp+Ch]

  v13 = nDelaySize;
  if ( (int *)nDelaySize == tdelay )
  {
    v14 = pfsamps[1];
    numer0 = *numer;
    v15 = denom[1];
    numer1 = numer[1];
    v16 = *ppsamp;
    v17 = nDelaySize + 1;
    denom1 = v15;
    pSampsPDelaySize = &psamps[nDelaySize];
    nFilteredOutputA = nDelaySize + 1;
    if ( (nCount & 3) != 0 )
    {
      while ( 1 )
      {
        v20 = v16[v13 - (nFilteredOutputA & (((char *)pSampsPDelaySize - (char *)&v16[v13]) >> 31))]
            - ((v14 * v15) >> 12);
        --nCount;
        v21 = (v14 * numer1 + numer0 * v20) >> 12;
        v14 = v20;
        v22 = v21 + *pIn;
        *v16 = v22;
        pIn += 2;
        v17 = nDelaySize + 1;
        v16 = &v16[((nDelaySize + 1) & (((char *)(v16 - 1) - (char *)psamps) >> 31)) - 1];
        *pOut += (outgain * v22) >> 12;
        v18 = pOut + 1;
        nFilteredOutputA = nDelaySize + 1;
        ++pOut;
        if ( (nCount & 3) == 0 )
          break;
        v13 = nDelaySize;
      }
    }
    else
    {
      v18 = pOut;
    }
    pDelaySampleA = v16;
    pDelaySampleB = &v16[(v17 & (((char *)(v16 - 1) - (char *)psamps) >> 31)) - 1];
    pDelaySampleC = &v16[(v17 & (((char *)(v16 - 2) - (char *)psamps) >> 31)) - 2];
    pDelaySampleD = &v16[(v17 & (((char *)(v16 - 3) - (char *)psamps) >> 31)) - 3];
    if ( (int)nCount >= 4 )
    {
      v19 = v18 + 2;
      v35 = pIn + 4;
      v30 = nCount >> 2;
      while ( 1 )
      {
        v23 = *pDelaySampleB - ((v14 * v15) >> 12);
        v24 = numer1 * v23;
        v25 = *pDelaySampleC - ((v15 * v23) >> 12);
        v26 = *pDelaySampleD - ((v15 * v25) >> 12);
        pInputDelaySampleD = pDelaySampleD[nDelaySize
                                         - ((nDelaySize + 1)
                                          & (((char *)pSampsPDelaySize - (char *)&pDelaySampleD[nDelaySize]) >> 31))]
                           - ((denom1 * v26) >> 12);
        outA = ((v14 * numer1 + numer0 * (*pDelaySampleB - ((v14 * v15) >> 12))) >> 12) + *(v35 - 4);
        v27 = *(v35 - 2) + ((numer0 * v25 + v24) >> 12);
        v28 = *v35 + ((numer0 * v26 + numer1 * v25) >> 12);
        v29 = v35[2] + ((numer0 * pInputDelaySampleD + numer1 * v26) >> 12);
        v35 += 8;
        *pDelaySampleA = outA;
        *pDelaySampleB = v27;
        *pDelaySampleC = v28;
        *pDelaySampleD = v29;
        pDelaySampleA = &pDelaySampleA[((nDelaySize + 1) & (((char *)(pDelaySampleA - 4) - (char *)psamps) >> 31)) - 4];
        v19 += 4;
        pDelaySampleB = &pDelaySampleB[((nDelaySize + 1) & (((char *)(pDelaySampleB - 4) - (char *)psamps) >> 31)) - 4];
        pDelaySampleC = &pDelaySampleC[((nDelaySize + 1) & (((char *)(pDelaySampleC - 4) - (char *)psamps) >> 31)) - 4];
        pDelaySampleD = &pDelaySampleD[((nDelaySize + 1) & (((char *)(pDelaySampleD - 4) - (char *)psamps) >> 31)) - 4];
        *(v19 - 6) += (outgain * outA) >> 12;
        v14 = pInputDelaySampleD;
        *(v19 - 5) += (outgain * v27) >> 12;
        *(v19 - 4) += (outgain * v28) >> 12;
        *(v19 - 3) += (outgain * v29) >> 12;
        if ( --v30 == 0 )
          break;
        v15 = denom1;
      }
    }
    *ppsamp = pDelaySampleA;
    *pfsamps = v14;
    pfsamps[1] = v14;
  }
  else
  {
    DelayLowPass_Opt2(
      nDelaySize,
      (int)tdelay,
      psamps,
      ppsamp,
      fbgain,
      outgain,
      denom,
      Ll,
      numer,
      pfsamps,
      pIn,
      pOut,
      nCount);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001DDF0
// Name: int DelayLowpass_xfade(int,int,int,int,int __near *,int __near * __near *,int,int,int __near *,int,int __near *,int __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl DelayLowpass_xfade(
        int delaysize,
        int tdelay,
        int tdelaynew,
        int xf,
        int *psamps,
        int **ppsamp,
        int fbgain,
        int outgain,
        int *denom,
        int Ll,
        int *numer,
        int *pfsamps,
        int in)
{
  int v13; // ebx
  int *v14; // eax
  int *v15; // esi
  int v16; // ecx
  int *v17; // eax
  int v18; // eax
  int v19; // ecx
  int v20; // eax
  int v21; // esi
  int v22; // ecx
  int v23; // eax

  v13 = 4 * delaysize;
  v14 = &(*ppsamp)[tdelay];
  v15 = &psamps[delaysize];
  if ( v14 > v15 )
    v16 = v14[v13 / 0xFFFFFFFC - 1];
  else
    v16 = *v14;
  v17 = &(*ppsamp)[tdelaynew];
  if ( v17 > v15 )
    v18 = v17[v13 / 0xFFFFFFFC - 1];
  else
    v18 = *v17;
  v19 = ((xf * (v18 - v16)) >> 12) + v16;
  if ( *pfsamps != 0 || pfsamps[1] != 0 || v19 != 0 )
  {
    v21 = pfsamps[1];
    v22 = v19 - ((v21 * denom[1]) >> 12);
    *pfsamps = v22;
    v13 = 4 * delaysize;
    v20 = (v22 * *numer + v21 * numer[1]) >> 12;
    pfsamps[1] = v22;
  }
  else
  {
    v20 = 0;
  }
  v23 = in + v20;
  *(*ppsamp)-- = v23;
  if ( *ppsamp < psamps )
    *ppsamp = (int *)((char *)*ppsamp + v13 + 4);
  return (outgain * v23) >> 12;
}

//------------------------------------------------------------------------------
// Address: 0x1001DEB0
// Name: int DelayLowpass_multitap(int,int,int,int,int,int __near *,int __near * __near *,int,int,int __near *,int,int __near *,int __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl DelayLowpass_multitap(
        int delaysize,
        int tdelay0,
        int tdelay1,
        int tdelay2,
        int tdelay3,
        int *psamps,
        int **ppsamp,
        int fbgain,
        int outgain,
        int *denom,
        int Ll,
        int *numer,
        int *pfsamps,
        int in)
{
  char *v14; // ecx
  int *v15; // eax
  int v16; // ebx
  int *v17; // edx
  int v18; // eax
  int *v19; // esi
  int v20; // eax
  int *v21; // esi
  int v22; // esi
  int *v23; // ecx
  int v24; // ecx
  int v25; // edi
  int v26; // eax
  int v27; // esi
  int v28; // ecx
  int delaysizea; // [esp+10h] [ebp+8h]
  int s1; // [esp+14h] [ebp+Ch]

  v14 = (char *)*ppsamp;
  v15 = &(*ppsamp)[tdelay0];
  v16 = 4 * delaysize;
  v17 = &psamps[delaysize];
  delaysizea = 4 * delaysize;
  if ( v15 > v17 )
    v18 = *(int *)((char *)v15 - v16 - 4);
  else
    v18 = *v15;
  s1 = v18;
  v19 = (int *)&v14[4 * tdelay1];
  if ( v19 > v17 )
    v20 = *(int *)((char *)v19 - v16 - 4);
  else
    v20 = *v19;
  v21 = (int *)&v14[4 * tdelay2];
  if ( v21 > v17 )
    v22 = *(int *)((char *)v21 - v16 - 4);
  else
    v22 = *v21;
  v23 = (int *)&v14[4 * tdelay3];
  if ( v23 > v17 )
    v24 = *(int *)((char *)v23 - v16 - 4);
  else
    v24 = *v23;
  v25 = s1 + v20 + v24 + v22;
  if ( *pfsamps != 0 || pfsamps[1] != 0 || v24 != 0 )
  {
    v27 = pfsamps[1];
    v28 = v24 - ((v27 * denom[1]) >> 12);
    *pfsamps = v28;
    v16 = delaysizea;
    v26 = (v28 * *numer + v27 * numer[1]) >> 12;
    pfsamps[1] = v28;
  }
  else
  {
    v26 = 0;
  }
  *(*ppsamp)-- = in + v26;
  if ( *ppsamp < psamps )
    *ppsamp = (int *)((char *)*ppsamp + v16 + 4);
  return (outgain * (v25 + in)) >> 12;
}

//------------------------------------------------------------------------------
// Address: 0x1001DF90
// Name: void DelayLowpass_multitap_Opt(int,int,int,int,int,int __near *,int __near * __near *,int,int,int __near *,int,int __near *,int __near *,int __near *,int __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DelayLowpass_multitap_Opt(
        int delaysize,
        int tdelay0,
        int tdelay1,
        int tdelay2,
        int tdelay3,
        int *psamps,
        int **ppsamp,
        int fbgain,
        int outgain,
        int *denom,
        int Ll,
        int *numer,
        int *pfsamps,
        int *pIn,
        int *pOut,
        int nCount)
{
  int v16; // edx
  int *v17; // esi
  char *v18; // ecx
  int *v19; // eax
  int *v20; // edx
  int v21; // esi
  int *v22; // edx
  int v23; // edx
  int *v24; // ecx
  int v25; // ecx
  int v26; // edx
  int v27; // eax
  int v28; // esi
  int v29; // ecx
  int v30; // [esp+0h] [ebp-10h]
  int v31; // [esp+4h] [ebp-Ch]
  int *v32; // [esp+8h] [ebp-8h]
  int v33; // [esp+Ch] [ebp-4h]

  if ( nCount > 0 )
  {
    v16 = 4 * delaysize;
    v17 = &psamps[delaysize];
    v33 = 4 * delaysize;
    v32 = v17;
    while ( 1 )
    {
      v18 = (char *)*ppsamp;
      --nCount;
      v30 = *pIn;
      v19 = &(*ppsamp)[tdelay0];
      v31 = v19 > v17 ? v19[v16 / 0xFFFFFFFC - 1] : *v19;
      v20 = (int *)&v18[4 * tdelay1];
      v21 = v20 > v17 ? v20[v33 / 0xFFFFFFFC - 1] : *v20;
      v22 = (int *)&v18[4 * tdelay2];
      v23 = v22 > v32 ? v22[v33 / 0xFFFFFFFC - 1] : *v22;
      v24 = (int *)&v18[4 * tdelay3];
      v25 = v24 > v32 ? v24[v33 / 0xFFFFFFFC - 1] : *v24;
      v26 = v31 + v21 + v25 + v23;
      if ( *pfsamps != 0 || pfsamps[1] != 0 || v25 != 0 )
      {
        v28 = pfsamps[1];
        v29 = v25 - ((v28 * denom[1]) >> 12);
        *pfsamps = v29;
        v27 = (v29 * *numer + v28 * numer[1]) >> 12;
        pfsamps[1] = v29;
      }
      else
      {
        v27 = 0;
      }
      *(*ppsamp)-- = v30 + v27;
      if ( *ppsamp < psamps )
        *ppsamp = (int *)((char *)*ppsamp + v33 + 4);
      pIn += 2;
      *pOut++ += (outgain * (v30 + v26)) >> 12;
      if ( nCount <= 0 )
        break;
      v17 = &psamps[delaysize];
      v16 = 4 * delaysize;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001E1C0
// Name: int DelayLinearLowPass(int,int,int __near *,int __near * __near *,int,int,int __near *,int,int __near *,int __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl DelayLinearLowPass(
        int delaysize,
        int tdelay,
        int *psamps,
        int **ppsamp,
        int fbgain,
        int outgain,
        int *denom,
        int cnumer,
        int *numer,
        int *pfsamps,
        int in)
{
  int v11; // esi
  int *v12; // eax
  int v13; // eax
  int v14; // esi
  int v15; // ecx
  int v16; // eax

  v11 = 4 * delaysize;
  v12 = &(*ppsamp)[tdelay];
  if ( v12 > &psamps[delaysize] )
    v13 = v12[v11 / 0xFFFFFFFC - 1];
  else
    v13 = *v12;
  if ( *pfsamps != 0 || pfsamps[1] != 0 || v13 != 0 )
  {
    v14 = pfsamps[1];
    v15 = v13 - ((v14 * denom[1]) >> 12);
    *pfsamps = v15;
    v16 = v15 * *numer + v14 * numer[1];
    v11 = 4 * delaysize;
    v13 = v16 >> 12;
    pfsamps[1] = v15;
  }
  *(*ppsamp)-- = in;
  if ( *ppsamp < psamps )
    *ppsamp = (int *)((char *)*ppsamp + v11 + 4);
  return (outgain * v13) >> 12;
}

//------------------------------------------------------------------------------
// Address: 0x1001E330
// Name: void DelayLinearLowPass_Opt3(int,int,int __near *,int __near * __near *,int,int,int __near *,int,int __near *,int __near *,int __near *,int __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DelayLinearLowPass_Opt3(
        int nDelaySize,
        int tdelay,
        int *psamps,
        int **ppsamp,
        int fbgain,
        int outgain,
        int *denom,
        int Ll,
        int *numer,
        int *pfsamps,
        int *pIn,
        int *pOut,
        unsigned int nCount)
{
  int v13; // esi
  int v14; // ebx
  int v15; // edi
  int *v16; // ecx
  int v17; // edx
  int v18; // eax
  int *v19; // edx
  int v20; // eax
  int v21; // ecx
  int v22; // edx
  bool v23; // zf
  unsigned int v24; // [esp+4h] [ebp-2Ch]
  int *v25; // [esp+8h] [ebp-28h]
  int denom1; // [esp+Ch] [ebp-24h]
  int *pInputDelaySampleD; // [esp+10h] [ebp-20h]
  int pInputDelaySampleDa; // [esp+10h] [ebp-20h]
  int *pSampsPDelaySize; // [esp+14h] [ebp-1Ch]
  int numer1; // [esp+18h] [ebp-18h]
  int numer0; // [esp+1Ch] [ebp-14h]
  int *pDelaySampleA; // [esp+20h] [ebp-10h]
  int *v33; // [esp+24h] [ebp-Ch]
  int *pDelaySampleD; // [esp+28h] [ebp-8h]
  int *pDelaySampleC; // [esp+2Ch] [ebp-4h]
  int nDelaySizeP1; // [esp+3Ch] [ebp+Ch]
  int *nDelaySizeP1a; // [esp+3Ch] [ebp+Ch]

  v13 = nDelaySize;
  if ( nDelaySize == tdelay )
  {
    v14 = pfsamps[1];
    numer1 = numer[1];
    v15 = denom[1];
    numer0 = *numer;
    v16 = *ppsamp;
    v17 = nDelaySize + 1;
    denom1 = v15;
    pSampsPDelaySize = &psamps[nDelaySize];
    for ( nDelaySizeP1 = nDelaySize + 1; (nCount & 3) != 0; nDelaySizeP1 = nDelaySize + 1 )
    {
      --nCount;
      v18 = v14 * numer1
          + numer0
          * (v16[v13 - (nDelaySizeP1 & (((char *)pSampsPDelaySize - (char *)&v16[v13]) >> 31))] - ((v14 * v15) >> 12));
      v14 = v16[v13 - (nDelaySizeP1 & (((char *)pSampsPDelaySize - (char *)&v16[v13]) >> 31))] - ((v14 * v15) >> 12);
      *v16 = *pIn;
      pIn += 2;
      v17 = nDelaySize + 1;
      v16 = &v16[((nDelaySize + 1) & (((char *)(v16 - 1) - (char *)psamps) >> 31)) - 1];
      *pOut++ += (outgain * (v18 >> 12)) >> 12;
      v13 = nDelaySize;
    }
    pDelaySampleA = v16;
    nDelaySizeP1a = &v16[(v17 & (((char *)(v16 - 1) - (char *)psamps) >> 31)) - 1];
    pDelaySampleC = &v16[(v17 & (((char *)(v16 - 2) - (char *)psamps) >> 31)) - 2];
    v19 = &v16[(v17 & (((char *)(v16 - 3) - (char *)psamps) >> 31)) - 3];
    pDelaySampleD = v19;
    if ( (int)nCount >= 4 )
    {
      v25 = pOut + 2;
      v33 = pIn + 4;
      v24 = nCount >> 2;
      while ( 1 )
      {
        pInputDelaySampleD = &v19[v13];
        v20 = *nDelaySizeP1a - ((v14 * v15) >> 12);
        v21 = *pDelaySampleC - ((v15 * v20) >> 12);
        v22 = *v19 - ((v15 * v21) >> 12);
        pInputDelaySampleDa = pInputDelaySampleD[-((nDelaySize + 1)
                                                 & (((char *)pSampsPDelaySize - (char *)pInputDelaySampleD) >> 31))]
                            - ((denom1 * v22) >> 12);
        *pDelaySampleA = *(v33 - 4);
        *nDelaySizeP1a = *(v33 - 2);
        *pDelaySampleC = *v33;
        *pDelaySampleD = v33[2];
        v33 += 8;
        pDelaySampleA = &pDelaySampleA[((nDelaySize + 1) & (((char *)(pDelaySampleA - 4) - (char *)psamps) >> 31)) - 4];
        nDelaySizeP1a = &nDelaySizeP1a[((nDelaySize + 1) & (((char *)(nDelaySizeP1a - 4) - (char *)psamps) >> 31)) - 4];
        pDelaySampleC = &pDelaySampleC[((nDelaySize + 1) & (((char *)(pDelaySampleC - 4) - (char *)psamps) >> 31)) - 4];
        pDelaySampleD = &pDelaySampleD[((nDelaySize + 1) & (((char *)(pDelaySampleD - 4) - (char *)psamps) >> 31)) - 4];
        *(v25 - 2) += (outgain * ((v14 * numer1 + numer0 * v20) >> 12)) >> 12;
        *(v25 - 1) += (outgain * ((numer0 * v21 + numer1 * v20) >> 12)) >> 12;
        v14 = pInputDelaySampleDa;
        *v25 += (outgain * ((numer0 * v22 + numer1 * v21) >> 12)) >> 12;
        v25[1] += (outgain * ((numer0 * pInputDelaySampleDa + numer1 * v22) >> 12)) >> 12;
        v23 = v24-- == 1;
        v25 += 4;
        if ( v23 )
          break;
        v13 = nDelaySize;
        v15 = denom1;
        v19 = pDelaySampleD;
      }
    }
    *ppsamp = pDelaySampleA;
    *pfsamps = v14;
    pfsamps[1] = v14;
  }
  else
  {
    DelayLinearLowPass_Opt2(
      nDelaySize,
      tdelay,
      psamps,
      ppsamp,
      fbgain,
      outgain,
      denom,
      Ll,
      numer,
      pfsamps,
      pIn,
      pOut,
      nCount);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001E640
// Name: int DelayLinear_lowpass_xfade(int,int,int,int,int __near *,int __near * __near *,int,int,int __near *,int,int __near *,int __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl DelayLinear_lowpass_xfade(
        int delaysize,
        int tdelay,
        int tdelaynew,
        int xf,
        int *psamps,
        int **ppsamp,
        int fbgain,
        int outgain,
        int *denom,
        int cnumer,
        int *numer,
        int *pfsamps,
        int in)
{
  int **v13; // edi
  int v14; // ebx
  int *v15; // eax
  int *v16; // esi
  int v17; // ecx
  int *v18; // eax
  int v19; // eax
  int v20; // ecx
  int v21; // eax
  int v22; // esi
  int v23; // ecx

  v13 = ppsamp;
  v14 = 4 * delaysize;
  v15 = &(*ppsamp)[tdelay];
  v16 = &psamps[delaysize];
  if ( v15 > v16 )
    v17 = v15[v14 / 0xFFFFFFFC - 1];
  else
    v17 = *v15;
  v18 = &(*ppsamp)[tdelaynew];
  if ( v18 > v16 )
    v19 = v18[v14 / 0xFFFFFFFC - 1];
  else
    v19 = *v18;
  v20 = ((xf * (v19 - v17)) >> 12) + v17;
  if ( *pfsamps != 0 || pfsamps[1] != 0 || v20 != 0 )
  {
    v22 = pfsamps[1];
    v23 = v20 - ((v22 * denom[1]) >> 12);
    *pfsamps = v23;
    v13 = ppsamp;
    v21 = (v23 * *numer + v22 * numer[1]) >> 12;
    pfsamps[1] = v23;
  }
  else
  {
    v21 = 0;
  }
  *(*v13)-- = in;
  if ( *v13 < psamps )
    *v13 = (int *)((char *)*v13 + v14 + 4);
  return (outgain * v21) >> 12;
}

//------------------------------------------------------------------------------
// Address: 0x1001E6F0
// Name: int DelayAllpass(int,int,int __near *,int __near * __near *,int,int,int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl DelayAllpass(int delaysize, int tdelay, int *psamps, int **ppsamp, int fbgain, int outgain, int in)
{
  int v7; // ebx
  int *v8; // eax
  int v9; // esi

  v7 = 4 * delaysize;
  v8 = &(*ppsamp)[tdelay];
  if ( v8 > &psamps[delaysize] )
    v9 = v8[v7 / 0xFFFFFFFC - 1];
  else
    v9 = *v8;
  *(*ppsamp)-- = in + ((fbgain * v9) >> 12);
  if ( *ppsamp < psamps )
    *ppsamp = (int *)((char *)*ppsamp + v7 + 4);
  return (outgain * (v9 + (-(fbgain * (in + ((fbgain * v9) >> 12))) >> 12))) >> 12;
}

//------------------------------------------------------------------------------
// Address: 0x1001E760
// Name: int DelayAllpass_xfade(int,int,int,int,int __near *,int __near * __near *,int,int,int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl DelayAllpass_xfade(
        int delaysize,
        int tdelay,
        int tdelaynew,
        int xf,
        int *psamps,
        int **ppsamp,
        int fbgain,
        int outgain,
        int in)
{
  _DWORD *v9; // edi
  int v10; // ebx
  int *v11; // eax
  int *v12; // ecx
  int v13; // edx
  int *v14; // eax
  int v15; // eax
  int v16; // edx

  v9 = *ppsamp;
  v10 = 4 * delaysize;
  v11 = &(*ppsamp)[tdelay];
  v12 = &psamps[delaysize];
  if ( v11 > v12 )
    v13 = v11[v10 / 0xFFFFFFFC - 1];
  else
    v13 = *v11;
  v14 = &v9[tdelaynew];
  if ( v14 > v12 )
    v15 = v14[v10 / 0xFFFFFFFC - 1];
  else
    v15 = *v14;
  v16 = ((xf * (v15 - v13)) >> 12) + v13;
  *v9 = in + ((fbgain * v16) >> 12);
  if ( --*ppsamp < psamps )
    *ppsamp = (int *)((char *)*ppsamp + v10 + 4);
  return (outgain * (v16 + (-(fbgain * (in + ((fbgain * v16) >> 12))) >> 12))) >> 12;
}

//------------------------------------------------------------------------------
// Address: 0x1001E7E0
// Name: void FLT_Free(struct flt_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl FLT_Free(flt_t *pf)
{
  flt_t *pf1; // eax
  flt_t *pf2; // eax
  flt_t *pf3; // eax

  if ( pf != nullptr )
  {
    pf1 = pf->pf1;
    if ( pf1 != nullptr )
      _V_memset(dest: pf1, fill: 0, count: 184);
    pf2 = pf->pf2;
    if ( pf2 != nullptr )
      _V_memset(dest: pf2, fill: 0, count: 184);
    pf3 = pf->pf3;
    if ( pf3 != nullptr )
      _V_memset(dest: pf3, fill: 0, count: 184);
    _V_memset(dest: pf, fill: 0, count: 184);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001E850
// Name: void FLT_FreeAll(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl FLT_FreeAll()
{
  flt_t **p_pf2; // esi
  void *v1; // eax
  flt_t *v2; // eax

  p_pf2 = &flts[0].pf2;
  do
  {
    if ( p_pf2 != (flt_t **)176 )
    {
      v1 = *(p_pf2 - 1);
      if ( v1 != nullptr )
        _V_memset(dest: v1, fill: 0, count: 184);
      if ( *p_pf2 != nullptr )
        _V_memset(dest: *p_pf2, fill: 0, count: 184);
      v2 = p_pf2[1];
      if ( v2 != nullptr )
        _V_memset(dest: v2, fill: 0, count: 184);
      _V_memset(dest: p_pf2 - 44, fill: 0, count: 184);
    }
    p_pf2 += 46;
  }
  while ( (int)p_pf2 < (int)&snd_dsp_spew_changes.m_fnChangeCallbacks.m_Memory.m_nAllocationCount );
}

//------------------------------------------------------------------------------
// Address: 0x1001E8D0
// Name: struct flt_t __near * FLT_Alloc(int,int,int,int __near *,int __near *,float)
// Source: json
//------------------------------------------------------------------------------
flt_t *__cdecl FLT_Alloc(int N, int M, int L, int *a, int *b, float gain)
{
  flt_t *result; // eax
  int v7; // ecx
  flt_t *v8; // edx
  int v9; // edx
  int *v10; // esi
  int v11; // edx
  int *v12; // ecx

  result = nullptr;
  v7 = 0;
  v8 = flts;
  while ( v8->fused )
  {
    ++v8;
    ++v7;
    if ( (int)v8 >= (int)nuls )
      return result;
  }
  result = &flts[v7];
  result->N = N;
  v9 = 0;
  result->M = M;
  result->L = L;
  if ( M >= 0 )
  {
    v10 = result->a;
    do
      *v10++ = a[v9++];
    while ( v9 <= M );
  }
  v11 = 0;
  if ( L >= 0 )
  {
    v12 = result->b;
    do
      *v12++ = (int)(float)((float)b[v11++] * gain);
    while ( v11 <= L );
  }
  result->pf1 = nullptr;
  result->pf2 = nullptr;
  result->pf3 = nullptr;
  result->fused = true;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1001E990
// Name: void FLT_Print(struct flt_t const __near &,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl FLT_Print(const flt_t *filter, int nIndentation)
{
  char *IndentationText; // edi
  flt_t *pf1; // eax
  flt_t *pf2; // eax
  int j; // [esp+Ch] [ebp-8h]
  int k; // [esp+Ch] [ebp-8h]
  int m; // [esp+Ch] [ebp-8h]
  int i; // [esp+10h] [ebp-4h]
  int *filtera; // [esp+1Ch] [ebp+8h]
  int *filterb; // [esp+1Ch] [ebp+8h]
  int *filterc; // [esp+1Ch] [ebp+8h]

  for ( i = nIndentation + 1; ; ++i )
  {
    IndentationText = GetIndentationText(nIndentation: i - 1);
    DevMsg(a1: "%sFilter: %08X [Addr]\n", IndentationText, filter);
    DevMsg(a1: "%sb[] = ", IndentationText);
    filtera = filter->b;
    for ( j = 13; j != 0; --j )
      DevMsg(a1: "%d ", *filtera++);
    DevMsg(a1: "\n");
    DevMsg(a1: "%sa[] = ", IndentationText);
    filterb = filter->a;
    for ( k = 13; k != 0; --k )
      DevMsg(a1: "%d ", *filterb++);
    DevMsg(a1: "\n");
    DevMsg(a1: "%sw[] = ", IndentationText);
    filterc = filter->w;
    for ( m = 13; m != 0; --m )
      DevMsg(a1: "%d ", *filterc++);
    DevMsg(a1: "\n");
    DevMsg(a1: "%sL: %d\n", IndentationText, filter->L);
    DevMsg(a1: "%sM: %d\n", IndentationText, filter->M);
    DevMsg(a1: "%sN: %d\n", IndentationText, filter->N);
    DevMsg(a1: "%spf1:", IndentationText);
    pf1 = filter->pf1;
    if ( pf1 != nullptr )
      FLT_Print(filter: pf1, nIndentation: i);
    else
      DevMsg(a1: "NULL\n");
    DevMsg(a1: "%spf2:", IndentationText);
    pf2 = filter->pf2;
    if ( pf2 != nullptr )
      FLT_Print(filter: pf2, nIndentation: i);
    else
      DevMsg(a1: "NULL\n");
    DevMsg(a1: "%spf3:", IndentationText);
    filter = filter->pf3;
    if ( filter == nullptr )
      break;
  }
  DevMsg(a1: "NULL\n");
}

//------------------------------------------------------------------------------
// Address: 0x1001EB30
// Name: void FLT_Design_3db_IIR(float,float,int __near *,int __near *,int __near *,int __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl FLT_Design_3db_IIR(float cutoff, float ftype, int *pM, int *pL, int *a, int *b)
{
  long double v6; // st6
  long double v7; // st6
  long double v8; // st7
  long double v9; // st7

  v6 = tan(cutoff * 6.283185307179586 * 0.00002267573696145125 * 0.5);
  v7 = (1.0 - v6) / (v6 + 1.0);
  if ( ftype == 1.0 )
    v8 = 0.5 * (v7 + 1.0);
  else
    v8 = (1.0 - v7) * 0.5;
  *a = 0;
  v9 = v8 * 4096.0;
  a[1] = (int)(v7 * -4096.0);
  *b = (int)v9;
  b[1] = (int)v9;
  if ( ftype == 1.0 )
    b[1] = -(int)v9;
  *pL = 1;
  *pM = 1;
}

//------------------------------------------------------------------------------
// Address: 0x1001EBF0
// Name: int FLT_GetNext(struct flt_t __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl FLT_GetNext(flt_t *pf, int x)
{
  flt_t *v3; // esi
  flt_t *v4; // edi
  flt_t *pf3; // ebx
  int v6; // eax
  int v7; // eax
  int v8; // eax
  flt_t *v9; // esi
  flt_t *pf2; // edi
  int v11; // eax
  int v12; // eax
  flt_t *pf1; // esi
  int updated; // eax

  switch ( pf->N )
  {
    case 1:
      pf1 = pf->pf1;
      updated = IIRFilter_Update_Order1(denom: pf->a, cnumer: pf->L, numer: pf->b, psamp: pf->w, in: x);
      return IIRFilter_Update_Order1(denom: pf1->a, cnumer: pf1->L, numer: pf1->b, psamp: pf1->w, in: updated);
    case 2:
      v9 = pf->pf1;
      pf2 = pf->pf2;
      v11 = IIRFilter_Update_Order1(denom: pf->a, cnumer: pf->L, numer: pf->b, psamp: pf->w, in: x);
      v12 = IIRFilter_Update_Order1(denom: v9->a, cnumer: v9->L, numer: v9->b, psamp: v9->w, in: v11);
      return IIRFilter_Update_Order1(denom: pf2->a, cnumer: pf2->L, numer: pf2->b, psamp: pf2->w, in: v12);
    case 3:
      v3 = pf->pf1;
      v4 = pf->pf2;
      pf3 = pf->pf3;
      v6 = IIRFilter_Update_Order1(denom: pf->a, cnumer: pf->L, numer: pf->b, psamp: pf->w, in: x);
      v7 = IIRFilter_Update_Order1(denom: v3->a, cnumer: v3->L, numer: v3->b, psamp: v3->w, in: v6);
      v8 = IIRFilter_Update_Order1(denom: v4->a, cnumer: v4->L, numer: v4->b, psamp: v4->w, in: v7);
      return IIRFilter_Update_Order1(denom: pf3->a, cnumer: pf3->L, numer: pf3->b, psamp: pf3->w, in: v8);
    default:
      return IIRFilter_Update_Order1(denom: pf->a, cnumer: pf->L, numer: pf->b, psamp: pf->w, in: x);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001ED50
// Name: void FLT_GetNextN(struct flt_t __near *,struct portable_samplepair_t __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl FLT_GetNextN(flt_t *pflt, portable_samplepair_t *pbuffer, portable_samplepair_t *SampleCount, int op)
{
  int v5; // edi
  portable_samplepair_t *v6; // ebx
  int left; // ecx
  int v8; // esi
  int v9; // edx
  int v10; // ecx
  flt_t *pf3; // edi
  flt_t *v12; // edx
  flt_t *v13; // esi
  int v14; // ebx
  int v15; // edi
  int v16; // ecx
  int v17; // ebx
  int v18; // edi
  int v19; // ecx
  int v20; // ebx
  int v21; // edx
  int v22; // ecx
  int v23; // esi
  int v24; // edx
  flt_t *v25; // edx
  flt_t *pf2; // edi
  int v27; // ebx
  int v28; // esi
  int v29; // ecx
  int v30; // ebx
  int v31; // esi
  int v32; // ecx
  int v33; // esi
  int v34; // edx
  flt_t *pf1; // edx
  int v36; // edi
  int v37; // esi
  int v38; // edi
  int v39; // esi
  int Next; // eax
  int *p_right; // esi
  int count; // [esp+Ch] [ebp-4h]
  int counta; // [esp+Ch] [ebp-4h]
  portable_samplepair_t *pbuffera; // [esp+1Ch] [ebp+Ch]
  portable_samplepair_t *pb; // [esp+20h] [ebp+10h]

  v5 = (int)SampleCount;
  count = (int)SampleCount;
  v6 = pbuffer;
  pb = pbuffer;
  if ( op == 1 )
  {
    if ( SampleCount != nullptr )
    {
      p_right = &pbuffer->right;
      do
      {
        --count;
        *p_right = FLT_GetNext(pf: pflt, x: *p_right);
        p_right += 2;
      }
      while ( count != 0 );
    }
  }
  else if ( op == 2 )
  {
    if ( SampleCount != nullptr )
    {
      do
      {
        Next = FLT_GetNext(pf: pflt, x: v6->left);
        v6->right = Next;
        v6->left = Next;
        ++v6;
        --v5;
      }
      while ( v5 != 0 );
    }
  }
  else if ( SampleCount != nullptr )
  {
    do
    {
      left = v6->left;
      counta = v5 - 1;
      switch ( pflt->N )
      {
        case 1:
          pf1 = pflt->pf1;
          if ( pflt->w[0] != 0 || pflt->w[1] != 0 || left != 0 )
          {
            v36 = pflt->w[1];
            v37 = left - ((v36 * pflt->a[1]) >> 12);
            pflt->w[0] = v37;
            left = (v37 * pflt->b[0] + v36 * pflt->b[1]) >> 12;
            pflt->w[1] = v37;
          }
          if ( pf1->w[0] == 0 && pf1->w[1] == 0 && left == 0 )
            goto LABEL_48;
          v38 = pf1->w[1];
          v39 = left - ((v38 * pf1->a[1]) >> 12);
          pf1->w[0] = v39;
          v10 = v39 * pf1->b[0] + v38 * pf1->b[1];
          pf1->w[1] = v39;
          break;
        case 2:
          v25 = pflt->pf1;
          pf2 = pflt->pf2;
          if ( pflt->w[0] != 0 || pflt->w[1] != 0 || left != 0 )
          {
            v27 = pflt->w[1];
            v28 = left - ((v27 * pflt->a[1]) >> 12);
            pflt->w[0] = v28;
            v29 = v28 * pflt->b[0] + v27 * pflt->b[1];
            v6 = pb;
            left = v29 >> 12;
            pflt->w[1] = v28;
          }
          if ( v25->w[0] != 0 || v25->w[1] != 0 || left != 0 )
          {
            v30 = v25->w[1];
            v31 = left - ((v30 * v25->a[1]) >> 12);
            v25->w[0] = v31;
            v32 = v31 * v25->b[0] + v30 * v25->b[1];
            v6 = pb;
            left = v32 >> 12;
            v25->w[1] = v31;
          }
          if ( pf2->w[0] == 0 && pf2->w[1] == 0 && left == 0 )
            goto LABEL_48;
          v33 = pf2->w[1];
          v34 = left - ((v33 * pf2->a[1]) >> 12);
          pf2->w[0] = v34;
          v10 = v34 * pf2->b[0] + v33 * pf2->b[1];
          pf2->w[1] = v34;
          break;
        case 3:
          pf3 = pflt->pf3;
          v12 = pflt->pf1;
          v13 = pflt->pf2;
          pbuffera = (portable_samplepair_t *)pf3;
          if ( pflt->w[0] != 0 || pflt->w[1] != 0 || left != 0 )
          {
            v14 = pflt->w[1];
            v15 = left - ((v14 * pflt->a[1]) >> 12);
            pflt->w[0] = v15;
            v16 = v15 * pflt->b[0] + v14 * pflt->b[1];
            v6 = pb;
            pflt->w[1] = v15;
            pf3 = (flt_t *)pbuffera;
            left = v16 >> 12;
          }
          if ( v12->w[0] != 0 || v12->w[1] != 0 || left != 0 )
          {
            v17 = v12->w[1];
            v18 = left - ((v17 * v12->a[1]) >> 12);
            v12->w[0] = v18;
            v19 = v18 * v12->b[0] + v17 * v12->b[1];
            v6 = pb;
            v12->w[1] = v18;
            pf3 = (flt_t *)pbuffera;
            left = v19 >> 12;
          }
          if ( v13->w[0] != 0 || v13->w[1] != 0 || left != 0 )
          {
            v20 = v13->w[1];
            v21 = left - ((v20 * v13->a[1]) >> 12);
            v13->w[0] = v21;
            v22 = v21 * v13->b[0] + v20 * v13->b[1];
            v6 = pb;
            left = v22 >> 12;
            v13->w[1] = v21;
          }
          if ( pf3->w[0] == 0 && pf3->w[1] == 0 && left == 0 )
            goto LABEL_48;
          v23 = pf3->w[1];
          v24 = left - ((v23 * pf3->a[1]) >> 12);
          pf3->w[0] = v24;
          v10 = v24 * pf3->b[0] + v23 * pf3->b[1];
          pf3->w[1] = v24;
          break;
        default:
          if ( pflt->w[0] == 0 && pflt->w[1] == 0 && left == 0 )
            goto LABEL_48;
          v8 = pflt->w[1];
          v9 = left - ((v8 * pflt->a[1]) >> 12);
          pflt->w[0] = v9;
          v10 = v9 * pflt->b[0] + v8 * pflt->b[1];
          pflt->w[1] = v9;
          break;
      }
      left = v10 >> 12;
LABEL_48:
      v5 = counta;
      v6->left = left;
      pb = ++v6;
    }
    while ( counta != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001F0B0
// Name: void POS_ONE_Print(struct pos_one_t const __near &,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl POS_ONE_Print(const pos_one_t *posOne, const char *nIndentation)
{
  char *IndentationText; // ebx
  char *pIndent; // [esp+18h] [ebp+Ch]

  pIndent = GetIndentationText((int)nIndentation);
  DevMsg(a1: "%sPosOne: %08X [Addr]\n", pIndent, posOne);
  IndentationText = GetIndentationText(nIndentation: (int)(nIndentation + 1));
  DevMsg(a1: "%sPos: %08X [Addr]\n", IndentationText, posOne);
  DevMsg(a1: "%sstep: %d\n", IndentationText, posOne->p.step);
  DevMsg(a1: "%scstep: %d\n", IndentationText, posOne->p.cstep);
  DevMsg(a1: "%spos: %d\n", IndentationText, posOne->p.pos);
  DevMsg(a1: "%sD: %d\n", IndentationText, posOne->p.D);
  DevMsg(a1: "%sfhitend: %d\n", pIndent, posOne->fhitend);
}

//------------------------------------------------------------------------------
// Address: 0x1001F130
// Name: void DLY_Free(struct dly_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DLY_Free(dly_t *pdly)
{
  if ( pdly != nullptr )
  {
    FLT_Free(pf: pdly->pflt);
    if ( pdly->w != nullptr )
      free(pMem: pdly->w);
    _V_memset(dest: pdly, fill: 0, count: 72);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001F170
// Name: void DLY_FreeAll(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DLY_FreeAll()
{
  int **p_w; // edi
  int *v1; // esi
  void *v2; // eax
  void *v3; // eax
  void *v4; // eax

  p_w = &dlys[0].w;
  do
  {
    if ( p_w != (int **)56 )
    {
      v1 = p_w[3];
      if ( v1 != nullptr )
      {
        v2 = (void *)v1[43];
        if ( v2 != nullptr )
          _V_memset(dest: v2, fill: 0, count: 184);
        v3 = (void *)v1[44];
        if ( v3 != nullptr )
          _V_memset(dest: v3, fill: 0, count: 184);
        v4 = (void *)v1[45];
        if ( v4 != nullptr )
          _V_memset(dest: v4, fill: 0, count: 184);
        _V_memset(dest: v1, fill: 0, count: 184);
      }
      if ( *p_w != nullptr )
        free(pMem: *p_w);
      _V_memset(dest: p_w - 14, fill: 0, count: 72);
    }
    p_w += 18;
  }
  while ( (int)p_w < (int)flts[0].a );
}

//------------------------------------------------------------------------------
// Address: 0x1001F230
// Name: void DLY_Print(struct dly_t const __near &,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DLY_Print(const dly_t *delay, int nIndentation)
{
  char *IndentationText; // ebx
  int *w; // eax
  int v5; // ecx
  _DWORD *v6; // eax
  flt_t *pflt; // esi
  int nFirstValue; // [esp+Ch] [ebp-8h]
  int nValues; // [esp+10h] [ebp-4h]
  int nValuesa; // [esp+10h] [ebp-4h]
  int i; // [esp+1Ch] [ebp+8h]
  char i_3; // [esp+1Fh] [ebp+Bh]

  IndentationText = GetIndentationText(nIndentation);
  DevMsg(a1: "%sDelay: %08X [Addr]\n", IndentationText, delay);
  DevMsg(a1: "%sfused: %d\n", IndentationText, delay->fused);
  DevMsg(a1: "%stype: %d\n", IndentationText, delay->type);
  DevMsg(a1: "%sD: %d\n", IndentationText, delay->D);
  DevMsg(a1: "%st: %d\n", IndentationText, delay->t);
  DevMsg(a1: "%stnew: %d\n", IndentationText, delay->tnew);
  DevMsg(a1: "%sxf: %d\n", IndentationText, delay->xf);
  DevMsg(a1: "%st1: %d - t2: %d - t3: %d\n", IndentationText, delay->t1, delay->t2, delay->t3);
  DevMsg(a1: "%sa1: %d - a2: %d - a3: %d\n", IndentationText, delay->a1, delay->a2, delay->a3);
  DevMsg(a1: "%sD0: %d\n", IndentationText, delay->D0);
  DevMsg(a1: "%sw: %d\n", IndentationText, delay->p - delay->w);
  w = delay->w;
  nFirstValue = *w;
  i_3 = 1;
  v5 = delay->D + 1;
  if ( v5 <= 1 )
    goto LABEL_7;
  v6 = w + 1;
  nValues = delay->D;
  do
  {
    if ( *v6 != nFirstValue )
      i_3 = 0;
    ++v6;
    --nValues;
  }
  while ( nValues != 0 );
  if ( i_3 != 0 )
  {
LABEL_7:
    DevMsg(a1: "%sAll %d values are equal to %d.\n", IndentationText, v5, nFirstValue);
  }
  else
  {
    nValuesa = delay->D + 1;
    if ( v5 > 256 )
    {
      nValuesa = 256;
      DevMsg(a1: "%sDisplay only the first %d samples.\n", IndentationText, 256);
    }
    i = 0;
    do
    {
      if ( (i & 0x3F) == 0 )
        DevMsg(a1: "\n%s    ", IndentationText);
      DevMsg(a1: "%d ", delay->w[i++]);
    }
    while ( i < nValuesa );
    DevMsg(a1: "\n");
  }
  DevMsg(a1: "%sa: %d\n", IndentationText, delay->a);
  DevMsg(a1: "%sb: %d\n", IndentationText, delay->b);
  DevMsg(a1: "%spflt: ", IndentationText);
  pflt = delay->pflt;
  if ( pflt != nullptr )
    FLT_Print(filter: pflt, nIndentation: nIndentation + 1);
  else
    DevMsg(a1: "NULL\n");
}

//------------------------------------------------------------------------------
// Address: 0x1001F5D0
// Name: int DLY_GetNextXfade(struct dly_t __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl DLY_GetNextXfade(dly_t *pdly, int x)
{
  int result; // eax
  flt_t *pflt; // eax
  int *w; // esi
  int *p; // edx
  int v7; // ebx
  int *v8; // eax
  dly_t *v9; // eax
  int *v10; // eax
  int v11; // eax
  int v12; // eax
  int *v13; // edx
  int b; // [esp+4h] [ebp-4h]
  dly_t *pdlya; // [esp+10h] [ebp+8h]

  switch ( pdly->type )
  {
    case 1:
      result = DelayAllpass_xfade(
                 delaysize: pdly->D,
                 tdelay: pdly->t,
                 tdelaynew: pdly->tnew,
                 xf: pdly->xf,
                 psamps: pdly->w,
                 ppsamp: &pdly->p,
                 fbgain: pdly->a,
                 outgain: pdly->b,
                 in: x);
      break;
    case 2:
      result = DelayLowpass_xfade(
                 delaysize: pdly->D,
                 tdelay: pdly->t,
                 tdelaynew: pdly->tnew,
                 xf: pdly->xf,
                 psamps: pdly->w,
                 ppsamp: &pdly->p,
                 fbgain: pdly->a,
                 outgain: pdly->b,
                 denom: pdly->pflt->a,
                 Ll: pdly->pflt->L,
                 numer: pdly->pflt->b,
                 pfsamps: pdly->pflt->w,
                 in: x);
      break;
    case 3:
      result = DelayLinear_xfade(
                 delaysize: pdly->D,
                 tdelay: pdly->t,
                 tdelaynew: pdly->tnew,
                 xf: pdly->xf,
                 psamps: pdly->w,
                 ppsamp: &pdly->p,
                 in: x);
      break;
    case 4:
      result = DelayLinear_lowpass_xfade(
                 delaysize: pdly->D,
                 tdelay: pdly->t,
                 tdelaynew: pdly->tnew,
                 xf: pdly->xf,
                 psamps: pdly->w,
                 ppsamp: &pdly->p,
                 fbgain: pdly->a,
                 outgain: pdly->b,
                 denom: pdly->pflt->a,
                 cnumer: pdly->pflt->L,
                 numer: pdly->pflt->b,
                 pfsamps: pdly->pflt->w,
                 in: x);
      break;
    case 5:
      pflt = pdly->pflt;
      result = DelayLowpass_multitap_xfade(
                 delaysize: pdly->D,
                 tdelay0: pdly->t,
                 tdelaynew: pdly->tnew,
                 xf: pdly->xf,
                 tdelay1: pdly->t1,
                 tdelay2: pdly->t2,
                 tdelay3: pdly->t3,
                 psamps: pdly->w,
                 ppsamp: &pdly->p,
                 fbgain: pdly->a,
                 outgain: pdly->b,
                 denom: pflt->a,
                 Ll: pflt->L,
                 numer: pflt->b,
                 pfsamps: pflt->w,
                 in: x);
      break;
    case 6:
      result = ReverbSimple_multitap_xfade(
                 delaysize: pdly->D,
                 tdelay0: pdly->t,
                 tdelaynew: pdly->tnew,
                 xf: pdly->xf,
                 tdelay1: pdly->t1,
                 tdelay2: pdly->t2,
                 tdelay3: pdly->t3,
                 psamps: pdly->w,
                 ppsamp: &pdly->p,
                 fbgain: pdly->a,
                 outgain: pdly->b,
                 in: x);
      break;
    default:
      w = pdly->w;
      b = pdly->b;
      p = pdly->p;
      v7 = 4 * pdly->D;
      v8 = &p[pdly->t];
      if ( v8 > &w[v7 / 4u] )
        v9 = (dly_t *)v8[v7 / 0xFFFFFFFC - 1];
      else
        v9 = (dly_t *)*v8;
      pdlya = v9;
      v10 = &p[pdly->tnew];
      if ( v10 > &w[v7 / 4u] )
        v11 = v10[v7 / 0xFFFFFFFC - 1];
      else
        v11 = *v10;
      v12 = x + ((pdly->a * ((int)pdlya + ((pdly->xf * (v11 - (int)pdlya)) >> 12))) >> 12);
      *p = v12;
      v13 = --pdly->p;
      if ( v13 < w )
        pdly->p = &v13[v7 / 4u + 1];
      result = (b * v12) >> 12;
      break;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1001F800
// Name: void DLY_GetNextN(struct dly_t __near *,struct portable_samplepair_t __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DLY_GetNextN(dly_t *pdly, portable_samplepair_t *pbuffer, int SampleCount, int op)
{
  portable_samplepair_t *v4; // ebx
  int **p_p; // edi
  int left; // ecx
  int v7; // eax
  int *w; // edx
  int *v9; // eax
  int *v10; // eax
  int *v11; // edx
  int v12; // eax
  int v13; // eax
  int Next; // eax
  int *p_right; // esi
  int b; // [esp+Ch] [ebp-4h]
  int opa; // [esp+24h] [ebp+14h]
  int opb; // [esp+24h] [ebp+14h]

  v4 = pbuffer;
  if ( op == 1 )
  {
    if ( SampleCount != 0 )
    {
      p_right = &pbuffer->right;
      do
      {
        --SampleCount;
        *p_right = DLY_GetNext(pdly, x: *p_right);
        p_right += 2;
      }
      while ( SampleCount != 0 );
    }
  }
  else if ( op == 2 )
  {
    for ( ; SampleCount != 0; ++v4 )
    {
      --SampleCount;
      Next = DLY_GetNext(pdly, x: v4->left);
      v4->right = Next;
      v4->left = Next;
    }
  }
  else if ( SampleCount != 0 )
  {
    p_p = &pdly->p;
    do
    {
      --SampleCount;
      left = v4->left;
      switch ( pdly->type )
      {
        case 1:
          v7 = DelayAllpass(
                 delaysize: pdly->D,
                 tdelay: pdly->t,
                 psamps: pdly->w,
                 ppsamp: p_p,
                 fbgain: pdly->a,
                 outgain: pdly->b,
                 in: v4->left);
          break;
        case 2:
          v7 = DelayLowPass(
                 delaysize: pdly->D,
                 tdelay: pdly->t,
                 psamps: pdly->w,
                 ppsamp: p_p,
                 fbgain: pdly->a,
                 outgain: pdly->b,
                 denom: pdly->pflt->a,
                 Ll: pdly->pflt->L,
                 numer: pdly->pflt->b,
                 pfsamps: pdly->pflt->w,
                 in: v4->left);
          break;
        case 3:
          w = pdly->w;
          v9 = &(*p_p)[pdly->t];
          opa = 4 * pdly->D;
          if ( v9 > &w[opa / 4u] )
            v7 = v9[opa / 0xFFFFFFFC - 1];
          else
            v7 = *v9;
          *(*p_p)-- = left;
          if ( *p_p < w )
            *p_p = (int *)((char *)*p_p + opa + 4);
          goto LABEL_22;
        case 4:
          v7 = DelayLinearLowPass(
                 delaysize: pdly->D,
                 tdelay: pdly->t,
                 psamps: pdly->w,
                 ppsamp: p_p,
                 fbgain: pdly->a,
                 outgain: pdly->b,
                 denom: pdly->pflt->a,
                 cnumer: pdly->pflt->L,
                 numer: pdly->pflt->b,
                 pfsamps: pdly->pflt->w,
                 in: v4->left);
          break;
        case 5:
          v7 = DelayLowpass_multitap(
                 delaysize: pdly->D,
                 tdelay0: pdly->t,
                 tdelay1: pdly->t1,
                 tdelay2: pdly->t2,
                 tdelay3: pdly->t3,
                 psamps: pdly->w,
                 ppsamp: p_p,
                 fbgain: pdly->a,
                 outgain: pdly->b,
                 denom: pdly->pflt->a,
                 Ll: pdly->pflt->L,
                 numer: pdly->pflt->b,
                 pfsamps: pdly->pflt->w,
                 in: v4->left);
          break;
        case 6:
          v7 = ReverbSimple_multitap(
                 delaysize: pdly->D,
                 tdelay0: pdly->t,
                 tdelay1: pdly->t1,
                 tdelay2: pdly->t2,
                 tdelay3: pdly->t3,
                 psamps: pdly->w,
                 ppsamp: p_p,
                 fbgain: pdly->a,
                 outgain: pdly->b,
                 in: v4->left);
          break;
        default:
          v10 = &(*p_p)[pdly->t];
          b = pdly->b;
          v11 = pdly->w;
          opb = 4 * pdly->D;
          if ( v10 > &v11[opb / 4u] )
            v12 = v10[opb / 0xFFFFFFFC - 1];
          else
            v12 = *v10;
          v13 = left + ((pdly->a * v12) >> 12);
          *(*p_p)-- = v13;
          if ( *p_p < v11 )
            *p_p = (int *)((char *)*p_p + opb + 4);
          v7 = (b * v13) >> 12;
LABEL_22:
          v4 = pbuffer;
          break;
      }
      v4->left = v7;
      pbuffer = ++v4;
    }
    while ( SampleCount != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001FA80
// Name: void DLY_ChangeTaps(struct dly_t __near *,int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DLY_ChangeTaps(dly_t *pdly, int t0, int t1, int t2, int t3)
{
  int v10; // edx
  int v11; // edx
  int v12; // edx
  int D0; // edx
  int pdlya; // [esp+Ch] [ebp+8h]

  if ( pdly != nullptr )
  {
    for ( pdlya = 4; pdlya != 0; --pdlya )
    {
      if ( t0 > t1 )
      {
        v10 = t0;
        t0 = t1;
        t1 = v10;
      }
      if ( t1 > t2 )
      {
        v11 = t1;
        t1 = t2;
        t2 = v11;
      }
      if ( t2 > t3 )
      {
        v12 = t2;
        t2 = t3;
        t3 = v12;
      }
    }
    D0 = pdly->D0;
    if ( t0 >= D0 )
      t0 = pdly->D0;
    pdly->t = t0;
    if ( t1 >= D0 )
      t1 = D0;
    pdly->t1 = t1;
    if ( t2 >= D0 )
      t2 = D0;
    pdly->t2 = t2;
    if ( t3 < D0 )
      D0 = t3;
    pdly->t3 = D0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001FAF0
// Name: void RMP_Init(struct rmp_t __near *,float,int,int,bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl RMP_Init(rmp_t *prmp, float ramptime, int initval, int targetval, bool bEndAtTime)
{
  int v6; // eax
  float v7; // xmm0_4
  int v8; // ecx
  int rise; // [esp+14h] [ebp+8h]
  float risea; // [esp+14h] [ebp+8h]

  if ( prmp != nullptr )
  {
    _V_memset(dest: prmp, fill: 0, count: 44);
    v6 = abs32(targetval - initval);
    *(float *)&rise = fabs((double)(targetval - initval)) / (double)(int)(float)(ramptime * 44100.0);
    v7 = *(float *)&rise;
    if ( (int)*(float *)&rise > 4095 )
      v7 = (float)(*(float *)&rise - (float)(int)*(float *)&rise) + 4095.0;
    prmp->ps.p.D = v6;
    prmp->ps.p.step = (int)(float)(v7 * 1048576.0);
    prmp->ps.p.cstep = 0;
    prmp->ps.p.pos = 0;
    prmp->ps.fhitend = false;
    prmp->yprev = initval;
    prmp->initval = initval;
    prmp->target = targetval;
    prmp->sign = 2 * (targetval - initval >= 0) - 1;
    if ( ramptime <= 0.016000001 )
      risea = 0.016000001;
    else
      risea = ramptime;
    v8 = _Plat_MSTime();
    prmp->bEndAtTime = bEndAtTime;
    prmp->nEndRampTimeInMs = (__int64)(risea * 1000.0) + v8;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001FC00
// Name: int RMP_GetNext(struct rmp_t __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl RMP_GetNext(rmp_t *prmp)
{
  int pos; // esi
  int step; // edx
  int v3; // eax
  int v4; // eax
  int sign; // edi
  int initval; // eax
  int v7; // eax
  int yprev; // esi

  if ( !prmp->fhitend )
  {
    pos = prmp->ps.p.pos;
    if ( prmp->ps.fhitend
      || ((step = prmp->ps.p.step,
           v3 = step + prmp->ps.p.cstep,
           prmp->ps.p.pos = pos + (v3 >> 20),
           prmp->ps.p.cstep = v3 - (v3 & 0xFFF00000),
           step == 0)
       || (v4 = prmp->ps.p.pos) < 0
       || v4 >= prmp->ps.p.D
        ? (prmp->ps.fhitend = true)
        : (pos = prmp->ps.p.pos),
          prmp->ps.fhitend) )
    {
      prmp->fhitend = true;
    }
    sign = prmp->sign;
    initval = prmp->initval;
    if ( sign <= 0 )
      v7 = initval - pos;
    else
      v7 = pos + initval;
    if ( prmp->bEndAtTime )
    {
      yprev = prmp->yprev;
      if ( (int)abs32(v7 - yprev) >= 1 )
      {
        prmp->yprev = yprev + sign;
        return prmp->yprev;
      }
    }
    else
    {
      prmp->yprev = v7;
    }
  }
  return prmp->yprev;
}

//------------------------------------------------------------------------------
// Address: 0x1001FCA0
// Name: void RMP_Print(struct rmp_t const __near &,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl RMP_Print(const rmp_t *rmp, int nIndentation)
{
  char *IndentationText; // esi

  IndentationText = GetIndentationText(nIndentation);
  DevMsg(a1: "%sRmp: %08X [Addr]\n", IndentationText, rmp);
  DevMsg(a1: "%sinitval: %d\n", IndentationText, rmp->initval);
  DevMsg(a1: "%starget: %d\n", IndentationText, rmp->target);
  DevMsg(a1: "%ssign: %d\n", IndentationText, rmp->sign);
  DevMsg(a1: "%sfhitend: %d\n", IndentationText, rmp->fhitend);
  DevMsg(a1: "%sbEndAtTime: %d\n", IndentationText, rmp->bEndAtTime);
  POS_ONE_Print(posOne: &rmp->ps, nIndentation: (const char *)(nIndentation + 1));
}

//------------------------------------------------------------------------------
// Address: 0x1001FD20
// Name: void MDY_Free(struct mdy_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MDY_Free(mdy_t *pmdy)
{
  dly_t *pdly; // esi

  if ( pmdy != nullptr )
  {
    pdly = pmdy->pdly;
    if ( pdly != nullptr )
    {
      FLT_Free(pf: pdly->pflt);
      if ( pdly->w != nullptr )
        free(pMem: pdly->w);
      _V_memset(dest: pdly, fill: 0, count: 72);
    }
    _V_memset(dest: pmdy, fill: 0, count: 76);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001FD70
// Name: void MDY_FreeAll(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MDY_FreeAll()
{
  mdy_t *v0; // edi
  dly_t *pdly; // esi

  v0 = mdys;
  do
  {
    if ( v0 != nullptr )
    {
      pdly = v0->pdly;
      if ( pdly != nullptr )
      {
        FLT_Free(pf: pdly->pflt);
        if ( pdly->w != nullptr )
          free(pMem: pdly->w);
        _V_memset(dest: pdly, fill: 0, count: 72);
      }
      _V_memset(dest: v0, fill: 0, count: 76);
    }
    ++v0;
  }
  while ( (int)v0 < (int)dlys );
}

//------------------------------------------------------------------------------
// Address: 0x1001FDD0
// Name: struct mdy_t __near * MDY_Alloc(struct dly_t __near *,float,float,float,float)
// Source: json
//------------------------------------------------------------------------------
mdy_t *__cdecl MDY_Alloc(dly_t *pdly, float ramptime, float modtime, float depth, float mix)
{
  int v6; // esi
  mdy_t *v7; // eax
  mdy_t *v8; // esi
  int v9; // eax

  if ( pdly == nullptr )
    return nullptr;
  v6 = 0;
  v7 = mdys;
  while ( v7->fused )
  {
    ++v7;
    ++v6;
    if ( (int)v7 >= (int)dlys )
    {
      DevMsg(a1: "DSP: Warning, failed to allocate mod delay.\n");
      return nullptr;
    }
  }
  v8 = &mdys[v6];
  if ( v8 != nullptr )
    _V_memset(dest: v8, fill: 0, count: 76);
  v8->ramptime = ramptime;
  v9 = (int)(float)(modtime * 44100.0);
  v8->depth = depth;
  v8->mtime = v9;
  v8->mtimecur = v9;
  v8->mix = (int)(float)(mix * 4096.0);
  v8->pdly = pdly;
  v8->fused = true;
  v8->bPhaseInvert = false;
  return v8;
}

//------------------------------------------------------------------------------
// Address: 0x1001FE80
// Name: void MDY_Print(struct mdy_t const __near &,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MDY_Print(const mdy_t *modDelay, int nIndentation)
{
  char *IndentationText; // esi
  dly_t *pdly; // eax

  IndentationText = GetIndentationText(nIndentation);
  DevMsg(a1: "%sModDelay: %08X [Addr]\n", IndentationText, modDelay);
  DevMsg(a1: "%sfused: %d\n", IndentationText, modDelay->fused);
  DevMsg(a1: "%sfchanging: %d\n", IndentationText, modDelay->fchanging);
  DevMsg(a1: "%spdly: ", IndentationText);
  pdly = modDelay->pdly;
  if ( pdly != nullptr )
    DLY_Print(delay: pdly, nIndentation: nIndentation + 1);
  else
    DevMsg(a1: "NULL\n");
  DevMsg(a1: "%sramptime: %f\n", IndentationText, modDelay->ramptime);
  DevMsg(a1: "%smtime: %d\n", IndentationText, modDelay->mtime);
  DevMsg(a1: "%smtimecur: %d\n", IndentationText, modDelay->mtimecur);
  DevMsg(a1: "%sdepth: %f\n", IndentationText, modDelay->depth);
  DevMsg(a1: "%smix: %d\n", IndentationText, modDelay->mix);
  RMP_Print(rmp: &modDelay->rmp_interp, nIndentation: nIndentation + 1);
  DevMsg(a1: "%sbPhaseInvert: %d\n", IndentationText, modDelay->bPhaseInvert);
}

//------------------------------------------------------------------------------
// Address: 0x1001FF60
// Name: void MDY_ChangeVal(struct mdy_t __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MDY_ChangeVal(mdy_t *pmdy, int t)
{
  int D0; // edi
  float ramptime; // [esp+0h] [ebp-18h]

  D0 = t;
  ramptime = pmdy->ramptime;
  if ( pmdy->pdly->D0 < t )
    D0 = pmdy->pdly->D0;
  pmdy->fchanging = true;
  RMP_Init(prmp: &pmdy->rmp_interp, ramptime, initval: 0, targetval: 4096, bEndAtTime: false);
  pmdy->pdly->tnew = D0;
  pmdy->pdly->xf = 0;
}

//------------------------------------------------------------------------------
// Address: 0x1001FFB0
// Name: int MDY_GetNext(struct mdy_t __near *,int)
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
int __cdecl MDY_GetNext(mdy_t *pmdy, int x)
{
  int NextXfade; // edi
  dly_t *pdly; // eax
  int tnew; // ecx
  int mtime; // ecx
  int mtimecur; // eax
  dly_t *v7; // eax
  float v8; // xmm0_4
  int v9; // eax
  int mix; // esi

  if ( pmdy->fchanging )
  {
    NextXfade = DLY_GetNextXfade(pdly: pmdy->pdly, x);
    pmdy->pdly->xf = RMP_GetNext(prmp: &pmdy->rmp_interp);
    if ( pmdy->rmp_interp.fhitend )
    {
      pdly = pmdy->pdly;
      tnew = pdly->tnew;
      if ( tnew >= pdly->D0 )
        tnew = pdly->D0;
      pdly->t = tnew;
      pmdy->pdly->t = pmdy->pdly->tnew;
      pmdy->fchanging = false;
    }
  }
  else
  {
    NextXfade = DLY_GetNext(pdly: pmdy->pdly, x);
    if ( pmdy->mtime == 0 )
      goto mdy_return;
  }
  mtime = pmdy->mtime;
  if ( mtime != 0 )
  {
    mtimecur = pmdy->mtimecur;
    pmdy->mtimecur = mtimecur - 1;
    if ( mtimecur == 0 )
    {
      v7 = pmdy->pdly;
      v8 = 1.0 - pmdy->depth;
      pmdy->mtimecur = mtime;
      v9 = _RandomInt(
             this: (IUniformRandomStream *)(int)(float)(v8 * (float)v7->D0),
             a2: (int)(float)(v8 * (float)v7->D0),
             a3: v7->D0);
      MDY_ChangeVal(pmdy, t: v9);
    }
  }
mdy_return:
  if ( pmdy->bPhaseInvert )
    NextXfade = -NextXfade;
  mix = pmdy->mix;
  if ( mix == 4096 )
    return NextXfade;
  if ( mix == 2048 )
    return (NextXfade + x) >> 1;
  return x + ((mix * (NextXfade - x)) >> 12);
}

//------------------------------------------------------------------------------
// Address: 0x100200B0
// Name: void MDY_GetNextN(struct mdy_t __near *,struct portable_samplepair_t __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __cdecl MDY_GetNextN(mdy_t *pmdy, portable_samplepair_t *pbuffer, int SampleCount, int op)
{
  portable_samplepair_t *v4; // ebx
  int v5; // edi
  int NextXfade; // edi
  dly_t *pdly; // eax
  int tnew; // ecx
  int mtime; // eax
  int mtimecur; // ecx
  float v11; // xmm0_4
  float v12; // xmm0_4
  int D0; // ebx
  int mix; // eax
  int Next; // eax
  int *p_right; // esi
  float ramptime; // [esp-8h] [ebp-1Ch]
  int left; // [esp-4h] [ebp-18h]
  int SampleCounta; // [esp+24h] [ebp+10h]
  int count; // [esp+28h] [ebp+14h]

  v4 = pbuffer;
  v5 = SampleCount;
  if ( op == 1 )
  {
    if ( SampleCount != 0 )
    {
      p_right = &pbuffer->right;
      do
      {
        *p_right = MDY_GetNext(pmdy, x: *p_right);
        p_right += 2;
        --v5;
      }
      while ( v5 != 0 );
    }
  }
  else if ( op == 2 )
  {
    if ( SampleCount != 0 )
    {
      do
      {
        Next = MDY_GetNext(pmdy, x: v4->left);
        v4->right = Next;
        v4->left = Next;
        ++v4;
        --v5;
      }
      while ( v5 != 0 );
    }
  }
  else if ( SampleCount != 0 )
  {
    while ( 1 )
    {
      count = v5 - 1;
      SampleCounta = v4->left;
      left = v4->left;
      if ( pmdy->fchanging )
      {
        NextXfade = DLY_GetNextXfade(pdly: pmdy->pdly, x: left);
        pmdy->pdly->xf = RMP_GetNext(prmp: &pmdy->rmp_interp);
        if ( pmdy->rmp_interp.fhitend )
        {
          pdly = pmdy->pdly;
          tnew = pdly->tnew;
          if ( tnew >= pdly->D0 )
            tnew = pdly->D0;
          pdly->t = tnew;
          pmdy->pdly->t = pmdy->pdly->tnew;
          pmdy->fchanging = false;
        }
      }
      else
      {
        NextXfade = DLY_GetNext(pdly: pmdy->pdly, x: left);
      }
      mtime = pmdy->mtime;
      if ( mtime != 0 )
      {
        mtimecur = pmdy->mtimecur;
        pmdy->mtimecur = mtimecur - 1;
        if ( mtimecur == 0 )
        {
          v11 = 1.0 - pmdy->depth;
          pmdy->mtimecur = mtime;
          v12 = v11 * (float)pmdy->pdly->D0;
          D0 = _RandomInt(this: (IUniformRandomStream *)(int)v12, a2: (int)v12, a3: pmdy->pdly->D0);
          if ( pmdy->pdly->D0 < D0 )
            D0 = pmdy->pdly->D0;
          ramptime = pmdy->ramptime;
          pmdy->fchanging = true;
          RMP_Init(prmp: &pmdy->rmp_interp, ramptime, initval: 0, targetval: 4096, bEndAtTime: false);
          pmdy->pdly->tnew = D0;
          v4 = pbuffer;
          pmdy->pdly->xf = 0;
        }
      }
      if ( pmdy->bPhaseInvert )
        NextXfade = -NextXfade;
      mix = pmdy->mix;
      if ( mix != 4096 )
      {
        if ( mix == 2048 )
          NextXfade = (SampleCounta + NextXfade) >> 1;
        else
          NextXfade = SampleCounta + ((mix * (NextXfade - SampleCounta)) >> 12);
      }
      v4->left = NextXfade;
      pbuffer = ++v4;
      if ( count == 0 )
        break;
      v5 = count;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10020260
// Name: void MDY_Mod(struct mdy_t __near *,float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MDY_Mod(mdy_t *pmdy, float v)
{
  float v2; // xmm0_4
  dly_t *pdly; // eax
  int D0; // ecx
  int v5; // eax
  int v6; // edi
  float ramptime; // [esp+0h] [ebp-18h]

  v2 = v;
  pdly = pmdy->pdly;
  D0 = pdly->D0;
  if ( v >= -2.0 )
  {
    pmdy->bPhaseInvert = false;
  }
  else
  {
    v2 = v + 10.0;
    pmdy->bPhaseInvert = true;
  }
  v5 = pdly->D0;
  v6 = D0 + (int)(float)((float)((float)(v2 + 1.0) * -0.5) * (float)D0);
  if ( v5 < v6 )
    v6 = v5;
  ramptime = pmdy->ramptime;
  pmdy->fchanging = true;
  RMP_Init(prmp: &pmdy->rmp_interp, ramptime, initval: 0, targetval: 4096, bEndAtTime: false);
  pmdy->pdly->tnew = v6;
  pmdy->pdly->xf = 0;
}

//------------------------------------------------------------------------------
// Address: 0x100202F0
// Name: void RVA_Free(struct rva_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl RVA_Free(rva_t *prva)
{
  dly_t **pdlys; // edi
  int i; // ebx
  dly_t *v3; // esi
  mdy_t **v4; // eax
  int j; // edx
  int v6; // ecx
  mdy_t *v7; // ecx
  mdy_t *v8; // ecx
  mdy_t *v9; // ecx
  mdy_t *v10; // ecx
  mdy_t *v11; // ebx
  dly_t *pdly; // edi
  flt_t *pflt; // esi
  flt_t *pf1; // eax
  flt_t *pf2; // eax
  flt_t *pf3; // eax
  flt_t *v17; // esi
  flt_t *v18; // eax
  flt_t *v19; // eax
  flt_t *v20; // eax
  int k; // [esp+4h] [ebp-8h]
  mdy_t **pmdlys; // [esp+8h] [ebp-4h]

  if ( prva != nullptr )
  {
    pdlys = prva->pdlys;
    for ( i = 12; i != 0; --i )
    {
      v3 = *pdlys;
      if ( *pdlys != nullptr )
      {
        FLT_Free(pf: v3->pflt);
        if ( v3->w != nullptr )
          free(pMem: v3->w);
        _V_memset(dest: v3, fill: 0, count: 72);
      }
      ++pdlys;
    }
    v4 = &prva->pmdlys[1];
    for ( j = 2; j != 0; --j )
    {
      v6 = (int)*(v4 - 1);
      if ( v6 != 0 )
        *(_DWORD *)(v6 + 4) = 0;
      if ( *v4 != nullptr )
        (*v4)->pdly = nullptr;
      v7 = v4[1];
      if ( v7 != nullptr )
        v7->pdly = nullptr;
      v8 = v4[2];
      if ( v8 != nullptr )
        v8->pdly = nullptr;
      v9 = v4[3];
      if ( v9 != nullptr )
        v9->pdly = nullptr;
      v10 = v4[4];
      if ( v10 != nullptr )
        v10->pdly = nullptr;
      v4 += 6;
    }
    pmdlys = prva->pmdlys;
    for ( k = 12; k != 0; --k )
    {
      v11 = *pmdlys;
      if ( *pmdlys != nullptr )
      {
        pdly = v11->pdly;
        if ( pdly != nullptr )
        {
          pflt = pdly->pflt;
          if ( pflt != nullptr )
          {
            pf1 = pflt->pf1;
            if ( pf1 != nullptr )
              _V_memset(dest: pf1, fill: 0, count: 184);
            pf2 = pflt->pf2;
            if ( pf2 != nullptr )
              _V_memset(dest: pf2, fill: 0, count: 184);
            pf3 = pflt->pf3;
            if ( pf3 != nullptr )
              _V_memset(dest: pf3, fill: 0, count: 184);
            _V_memset(dest: pflt, fill: 0, count: 184);
          }
          if ( pdly->w != nullptr )
            free(pMem: pdly->w);
          _V_memset(dest: pdly, fill: 0, count: 72);
        }
        _V_memset(dest: v11, fill: 0, count: 76);
      }
      ++pmdlys;
    }
    v17 = prva->pflt;
    if ( v17 != nullptr )
    {
      v18 = v17->pf1;
      if ( v18 != nullptr )
        _V_memset(dest: v18, fill: 0, count: 184);
      v19 = v17->pf2;
      if ( v19 != nullptr )
        _V_memset(dest: v19, fill: 0, count: 184);
      v20 = v17->pf3;
      if ( v20 != nullptr )
        _V_memset(dest: v20, fill: 0, count: 184);
      _V_memset(dest: v17, fill: 0, count: 184);
    }
    _V_memset(dest: prva, fill: 0, count: 116);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100204E0
// Name: void RVA_FreeAll(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl RVA_FreeAll()
{
  rva_t *v0; // esi
  dly_t *v1; // edi
  flt_t *pflt; // esi
  flt_t *pf1; // eax
  flt_t *pf2; // eax
  flt_t *pf3; // eax
  mdy_t **v6; // eax
  int j; // edx
  int v8; // ecx
  mdy_t *v9; // ecx
  mdy_t *v10; // ecx
  mdy_t *v11; // ecx
  mdy_t *v12; // ecx
  mdy_t **pmdlys; // esi
  mdy_t *v14; // ebx
  dly_t *pdly; // edi
  flt_t *v16; // esi
  flt_t *v17; // eax
  flt_t *v18; // eax
  flt_t *v19; // eax
  bool v20; // zf
  flt_t *v21; // esi
  flt_t *v22; // eax
  flt_t *v23; // eax
  flt_t *v24; // eax
  int i; // [esp+Ch] [ebp-Ch]
  mdy_t **v26; // [esp+Ch] [ebp-Ch]
  dly_t **pdlys; // [esp+10h] [ebp-8h]
  int v28; // [esp+10h] [ebp-8h]
  rva_t *dest; // [esp+14h] [ebp-4h]

  v0 = rvas;
  dest = rvas;
  do
  {
    if ( v0 != nullptr )
    {
      pdlys = v0->pdlys;
      for ( i = 12; i != 0; --i )
      {
        v1 = *pdlys;
        if ( *pdlys != nullptr )
        {
          pflt = v1->pflt;
          if ( pflt != nullptr )
          {
            pf1 = pflt->pf1;
            if ( pf1 != nullptr )
              _V_memset(dest: pf1, fill: 0, count: 184);
            pf2 = pflt->pf2;
            if ( pf2 != nullptr )
              _V_memset(dest: pf2, fill: 0, count: 184);
            pf3 = pflt->pf3;
            if ( pf3 != nullptr )
              _V_memset(dest: pf3, fill: 0, count: 184);
            _V_memset(dest: pflt, fill: 0, count: 184);
          }
          if ( v1->w != nullptr )
            free(pMem: v1->w);
          _V_memset(dest: v1, fill: 0, count: 72);
          v0 = dest;
        }
        ++pdlys;
      }
      v6 = &v0->pmdlys[1];
      for ( j = 2; j != 0; --j )
      {
        v8 = (int)*(v6 - 1);
        if ( v8 != 0 )
          *(_DWORD *)(v8 + 4) = 0;
        if ( *v6 != nullptr )
          (*v6)->pdly = nullptr;
        v9 = v6[1];
        if ( v9 != nullptr )
          v9->pdly = nullptr;
        v10 = v6[2];
        if ( v10 != nullptr )
          v10->pdly = nullptr;
        v11 = v6[3];
        if ( v11 != nullptr )
          v11->pdly = nullptr;
        v12 = v6[4];
        if ( v12 != nullptr )
          v12->pdly = nullptr;
        v6 += 6;
      }
      pmdlys = v0->pmdlys;
      v26 = pmdlys;
      v28 = 12;
      do
      {
        v14 = *pmdlys;
        if ( *pmdlys != nullptr )
        {
          pdly = v14->pdly;
          if ( pdly != nullptr )
          {
            v16 = pdly->pflt;
            if ( v16 != nullptr )
            {
              v17 = v16->pf1;
              if ( v17 != nullptr )
                _V_memset(dest: v17, fill: 0, count: 184);
              v18 = v16->pf2;
              if ( v18 != nullptr )
                _V_memset(dest: v18, fill: 0, count: 184);
              v19 = v16->pf3;
              if ( v19 != nullptr )
                _V_memset(dest: v19, fill: 0, count: 184);
              _V_memset(dest: v16, fill: 0, count: 184);
            }
            if ( pdly->w != nullptr )
              free(pMem: pdly->w);
            _V_memset(dest: pdly, fill: 0, count: 72);
          }
          _V_memset(dest: v14, fill: 0, count: 76);
        }
        pmdlys = v26 + 1;
        v20 = v28-- == 1;
        ++v26;
      }
      while ( !v20 );
      v21 = dest->pflt;
      if ( v21 != nullptr )
      {
        v22 = v21->pf1;
        if ( v22 != nullptr )
          _V_memset(dest: v22, fill: 0, count: 184);
        v23 = v21->pf2;
        if ( v23 != nullptr )
          _V_memset(dest: v23, fill: 0, count: 184);
        v24 = v21->pf3;
        if ( v24 != nullptr )
          _V_memset(dest: v24, fill: 0, count: 184);
        _V_memset(dest: v21, fill: 0, count: 184);
      }
      _V_memset(dest, fill: 0, count: 116);
      v0 = dest;
    }
    dest = ++v0;
  }
  while ( (int)v0 < (int)mdys );
}

//------------------------------------------------------------------------------
// Address: 0x10020750
// Name: void RVA_Print(struct rva_t const __near &,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl RVA_Print(const rva_t *rva, int nIndentation)
{
  char *IndentationText; // edi
  flt_t *pflt; // ebx
  int v4; // ebx
  int v5; // ebx
  dly_t **pdlys; // [esp+Ch] [ebp-4h]
  mdy_t **pmdlys; // [esp+Ch] [ebp-4h]

  IndentationText = GetIndentationText(nIndentation);
  DevMsg(a1: "%sRVA: %08X [Addr]\n", IndentationText, rva);
  DevMsg(a1: "%sfused: %d\n", IndentationText, rva->fused);
  DevMsg(a1: "%sm: %d\n", IndentationText, rva->m);
  DevMsg(a1: "%sfparallel: %d\n", IndentationText, rva->fparallel);
  DevMsg(a1: "%sFilter:", IndentationText);
  pflt = rva->pflt;
  if ( pflt != nullptr )
    FLT_Print(filter: pflt, nIndentation: nIndentation + 1);
  else
    DevMsg(a1: "NULL\n");
  v4 = 0;
  pdlys = rva->pdlys;
  do
  {
    DevMsg(a1: "%sDelay[%d]: ", IndentationText, v4);
    if ( *pdlys != nullptr )
      DLY_Print(delay: *pdlys, nIndentation: nIndentation + 1);
    else
      DevMsg(a1: "NULL\n");
    ++pdlys;
    ++v4;
  }
  while ( v4 < 12 );
  v5 = 0;
  pmdlys = rva->pmdlys;
  do
  {
    DevMsg(a1: "%sModDelay[%d]: ", IndentationText, v5);
    if ( *pmdlys != nullptr )
      MDY_Print(modDelay: *pmdlys, nIndentation: nIndentation + 1);
    else
      DevMsg(a1: "NULL\n");
    ++pmdlys;
    ++v5;
  }
  while ( v5 < 12 );
  DevMsg(a1: "%sfmoddly: %d\n", IndentationText, rva->fmoddly);
}

//------------------------------------------------------------------------------
// Address: 0x10020870
// Name: int RVA_GetNext(struct rva_t __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl RVA_GetNext(rva_t *prva, int x)
{
  rva_t *v2; // esi
  int m; // eax
  int v4; // edi
  mdy_t **pmdlys; // esi
  int v6; // ebx
  dly_t **pdlys; // esi
  int v8; // ebx
  flt_t *pflt; // esi

  v2 = prva;
  m = prva->m;
  v4 = 0;
  if ( prva->fmoddly )
  {
    if ( m > 0 )
    {
      pmdlys = prva->pmdlys;
      v6 = prva->m;
      do
      {
        v4 += MDY_GetNext(pmdy: *pmdlys++, x);
        --v6;
      }
      while ( v6 != 0 );
LABEL_9:
      v2 = prva;
    }
  }
  else if ( m > 0 )
  {
    pdlys = prva->pdlys;
    v8 = prva->m;
    do
    {
      v4 += DLY_GetNext(pdly: *pdlys++, x);
      --v8;
    }
    while ( v8 != 0 );
    goto LABEL_9;
  }
  if ( v2->fparallel == 0 )
  {
    pflt = v2->pflt;
    if ( pflt != nullptr )
      return FLT_GetNext(pf: pflt, x: v4);
  }
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x100208F0
// Name: void RVA_GetNextN(struct rva_t __near *,struct portable_samplepair_t __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl RVA_GetNextN(rva_t *prva, portable_samplepair_t *pbuffer, portable_samplepair_t *SampleCount, int op)
{
  portable_samplepair_t *v5; // edi
  rva_t *v6; // eax
  int left; // ebx
  int m; // ecx
  int v9; // esi
  mdy_t **pmdlys; // edi
  dly_t **pdlys; // edi
  flt_t *pflt; // eax
  int Next; // eax
  int *p_right; // edi
  portable_samplepair_t *pbuffera; // [esp+18h] [ebp+Ch]
  portable_samplepair_t *pbufferb; // [esp+18h] [ebp+Ch]
  portable_samplepair_t *pb; // [esp+1Ch] [ebp+10h]
  int count; // [esp+20h] [ebp+14h]

  v5 = pbuffer;
  pb = pbuffer;
  if ( op == 1 )
  {
    if ( SampleCount != nullptr )
    {
      p_right = &pbuffer->right;
      do
      {
        *p_right = RVA_GetNext(prva, x: *p_right);
        p_right += 2;
        SampleCount = (portable_samplepair_t *)((char *)SampleCount - 1);
      }
      while ( SampleCount != nullptr );
    }
  }
  else if ( op == 2 )
  {
    for ( ; SampleCount != nullptr; SampleCount = (portable_samplepair_t *)((char *)SampleCount - 1) )
    {
      Next = RVA_GetNext(prva, x: v5->left);
      v5->right = Next;
      v5->left = Next;
      ++v5;
    }
  }
  else if ( SampleCount != nullptr )
  {
    while ( 1 )
    {
      v6 = prva;
      left = v5->left;
      m = prva->m;
      count = (int)&SampleCount[-1].right + 3;
      v9 = 0;
      if ( prva->fmoddly )
      {
        if ( m <= 0 )
          goto LABEL_15;
        pmdlys = prva->pmdlys;
        pbuffera = (portable_samplepair_t *)prva->m;
        do
        {
          v9 += MDY_GetNext(pmdy: *pmdlys++, x: left);
          pbuffera = (portable_samplepair_t *)((char *)pbuffera - 1);
        }
        while ( pbuffera != nullptr );
      }
      else
      {
        if ( m <= 0 )
          goto LABEL_15;
        pdlys = prva->pdlys;
        pbufferb = (portable_samplepair_t *)prva->m;
        do
        {
          v9 += DLY_GetNext(pdly: *pdlys++, x: left);
          pbufferb = (portable_samplepair_t *)((char *)pbufferb - 1);
        }
        while ( pbufferb != nullptr );
      }
      v5 = pb;
      v6 = prva;
LABEL_15:
      if ( v6->fparallel == 0 )
      {
        pflt = v6->pflt;
        if ( pflt != nullptr )
          v9 = FLT_GetNext(pf: pflt, x: v9);
      }
      v5->left = v9;
      pb = ++v5;
      if ( count == 0 )
        return;
      SampleCount = (portable_samplepair_t *)count;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10020A00
// Name: void RVA_ConstructDelays(float __near *,float __near *,int,int __near *,int __near *,int __near *,float,float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl RVA_ConstructDelays(float *rgd, float *rgf, int m, int *D, int *a, int *b, float gain, float feedback)
{
  float *v8; // ebx
  float v9; // xmm0_4
  float v10; // xmm1_4
  int v12; // xmm0_4
  float v13; // xmm1_4
  int v14; // xmm0_4
  int v15; // xmm0_4
  float v16; // xmm0_4
  float v17; // xmm1_4
  int v18; // xmm0_4
  float v19; // xmm1_4
  float v20; // xmm0_4
  int *v21; // esi
  int v22; // eax
  float v23; // xmm1_4
  float v24; // xmm0_4
  float v25; // xmm2_4
  int v26; // ebx
  long double v27; // st7
  double v28; // st5
  double v29; // st6
  long double v30; // st6
  long double v31; // st7
  float dm; // [esp+10h] [ebp-14h]
  int d; // [esp+1Ch] [ebp-8h]
  int i; // [esp+20h] [ebp-4h]
  char bpredelay_3; // [esp+33h] [ebp+Fh]

  v8 = rgd;
  v9 = rgd[2];
  v10 = rgd[1];
  if ( v9 > v10 )
  {
    rgd[2] = v10;
    rgd[1] = v9;
    v12 = *((_DWORD *)rgf + 2);
    rgf[2] = rgf[1];
    *((_DWORD *)rgf + 1) = v12;
  }
  v13 = rgd[1];
  v14 = *(_DWORD *)rgd;
  if ( v13 > *rgd )
  {
    *rgd = v13;
    *((_DWORD *)rgd + 1) = v14;
    v15 = *(_DWORD *)rgf;
    *rgf = rgf[1];
    *((_DWORD *)rgf + 1) = v15;
  }
  v16 = rgd[2];
  v17 = rgd[1];
  if ( v16 > v17 )
  {
    rgd[2] = v17;
    rgd[1] = v16;
    v18 = *((_DWORD *)rgf + 2);
    rgf[2] = rgf[1];
    *((_DWORD *)rgf + 1) = v18;
  }
  if ( *rgf == 0.0 && rgf[1] == 0.0 && rgf[2] == 0.0 )
  {
    rgf[2] = feedback;
    rgf[1] = feedback;
    *rgf = feedback;
    *rgf = pow(feedback, (double)(int)*rgd / (double)(int)rgd[2]);
    rgf[1] = pow(feedback, (double)(int)rgd[1] / (double)(int)rgd[2]);
  }
  v19 = rgd[1] - rgd[2];
  v20 = (float)(7 * (m / 3));
  if ( v20 >= v19 )
    rgd[1] = (float)(v20 - v19) + rgd[1];
  if ( v20 >= (float)(*rgd - rgd[1]) )
    *rgd = (float)(v20 - v19) + *rgd;
  i = 0;
  if ( m > 0 )
  {
    v21 = a;
    while ( 1 )
    {
      v22 = (int)fmod((double)i, 3.0);
      v23 = rgf[v22];
      v24 = v8[v22];
      v25 = 0.0;
      v26 = (int)v24;
      d = (int)v24;
      v27 = fabs(v23);
      if ( v23 >= 0.0 || (bpredelay_3 = 1, i >= 3) )
        bpredelay_3 = 0;
      if ( v23 < 0.0 && bpredelay_3 == 0 )
      {
        v26 = (int)(float)(v24 * 0.25);
        if ( v26 <= 7 )
          v26 = 7;
        d = v26;
      }
      if ( i >= 3 )
      {
        v28 = (double)(int)(7 * (i / 3u));
        v29 = (double)d * 0.18 * (double)(i / 3u);
        if ( v28 > v29 )
          v29 = v28;
        dm = v29;
        v25 = dm;
      }
      v30 = v27 * 4096.0;
      v31 = 4091.904;
      *(int *)((char *)v21 + (char *)D - (char *)a) = 44100 * (v26 + (int)v25) / 1000;
      if ( v30 <= 4091.904 )
        v31 = v30;
      *v21 = (int)v31;
      if ( bpredelay_3 != 0 )
        *v21 = -(int)v31;
      *(int *)((char *)v21++ + (char *)b - (char *)a) = (int)(float)((float)(gain * 4096.0) / (float)m);
      if ( ++i >= m )
        break;
      v8 = rgd;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10020D40
// Name: void DFR_Print(struct dfr_t const __near &,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DFR_Print(const dfr_t *dfr, int nIndentation)
{
  char *IndentationText; // ebx
  int v3; // esi
  dly_t **pdlys; // edi

  IndentationText = GetIndentationText(nIndentation);
  DevMsg(a1: "%sDFR: %08X [Addr]\n", IndentationText, dfr);
  DevMsg(a1: "%sfused: %d\n", IndentationText, dfr->fused);
  v3 = 0;
  pdlys = dfr->pdlys;
  do
  {
    DevMsg(a1: "%sDelay[%d]: ", IndentationText, v3);
    if ( *pdlys != nullptr )
      DLY_Print(delay: *pdlys, nIndentation: nIndentation + 1);
    else
      DevMsg(a1: "NULL\n");
    ++v3;
    ++pdlys;
  }
  while ( v3 < 16 );
}

//------------------------------------------------------------------------------
// Address: 0x10020DC0
// Name: int DFR_GetNext(struct dfr_t __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl DFR_GetNext(dfr_t *pdfr, int x)
{
  int result; // eax
  dly_t *v3; // ecx
  int *w; // edi
  int *p; // ebx
  int a; // esi
  int *v7; // edx
  int *v8; // edx
  int b; // [esp+0h] [ebp-14h]
  int i; // [esp+4h] [ebp-10h]
  int y; // [esp+8h] [ebp-Ch]
  int v12; // [esp+Ch] [ebp-8h]
  dly_t **pdlys; // [esp+10h] [ebp-4h]
  int xa; // [esp+20h] [ebp+Ch]

  result = x;
  y = x;
  i = 0;
  if ( pdfr->n > 0 )
  {
    pdlys = pdfr->pdlys;
    do
    {
      v3 = *pdlys;
      w = (*pdlys)->w;
      p = (*pdlys)->p;
      a = (*pdlys)->a;
      b = (*pdlys)->b;
      v12 = 4 * (*pdlys)->D;
      v7 = &p[(*pdlys)->t];
      if ( v7 > &w[v12 / 4u] )
        xa = v7[v12 / 0xFFFFFFFC - 1];
      else
        xa = *v7;
      *p = y + ((a * xa) >> 12);
      v8 = --v3->p;
      if ( v8 < w )
        v3->p = &v8[v12 / 4u + 1];
      ++pdlys;
      result = (b * (xa + (-(a * (y + ((a * xa) >> 12))) >> 12))) >> 12;
      y = result;
      ++i;
    }
    while ( i < pdfr->n );
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10020E90
// Name: void DFR_GetNextN(struct dfr_t __near *,struct portable_samplepair_t __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DFR_GetNextN(dfr_t *pdfr, portable_samplepair_t *pbuffer, int SampleCount, int op)
{
  portable_samplepair_t *v4; // esi
  int v5; // edi
  int left; // eax
  dly_t *v7; // ecx
  int *w; // edi
  int *p; // ebx
  int a; // esi
  int *v11; // edx
  int *v12; // edx
  int Next; // eax
  int *p_right; // esi
  int count; // [esp+Ch] [ebp-14h]
  int b; // [esp+10h] [ebp-10h]
  portable_samplepair_t *pb; // [esp+14h] [ebp-Ch]
  int v18; // [esp+18h] [ebp-8h]
  int v19; // [esp+1Ch] [ebp-4h]
  dly_t **pbuffera; // [esp+2Ch] [ebp+Ch]
  int SampleCounta; // [esp+30h] [ebp+10h]
  int opa; // [esp+34h] [ebp+14h]

  v4 = pbuffer;
  v5 = SampleCount;
  pb = pbuffer;
  if ( op == 1 )
  {
    if ( SampleCount != 0 )
    {
      p_right = &pbuffer->right;
      do
      {
        *p_right = DFR_GetNext(pdfr, x: *p_right);
        p_right += 2;
        --v5;
      }
      while ( v5 != 0 );
    }
  }
  else if ( op == 2 )
  {
    if ( SampleCount != 0 )
    {
      do
      {
        Next = DFR_GetNext(pdfr, x: v4->left);
        v4->right = Next;
        v4->left = Next;
        ++v4;
        --v5;
      }
      while ( v5 != 0 );
    }
  }
  else if ( SampleCount != 0 )
  {
    do
    {
      left = v4->left;
      count = --v5;
      v19 = v4->left;
      v18 = 0;
      if ( pdfr->n > 0 )
      {
        pbuffera = pdfr->pdlys;
        do
        {
          v7 = *pbuffera;
          w = (*pbuffera)->w;
          p = (*pbuffera)->p;
          a = (*pbuffera)->a;
          b = (*pbuffera)->b;
          opa = 4 * (*pbuffera)->D;
          v11 = &p[(*pbuffera)->t];
          if ( v11 > &w[opa / 4u] )
            SampleCounta = v11[opa / 0xFFFFFFFC - 1];
          else
            SampleCounta = *v11;
          *p = v19 + ((a * SampleCounta) >> 12);
          v12 = --v7->p;
          if ( v12 < w )
            v7->p = &v12[opa / 4u + 1];
          ++pbuffera;
          left = (b * (SampleCounta + (-(a * (v19 + ((a * SampleCounta) >> 12))) >> 12))) >> 12;
          v19 = left;
          ++v18;
        }
        while ( v18 < pdfr->n );
        v5 = count;
        v4 = pb;
      }
      v4->left = left;
      pb = ++v4;
    }
    while ( v5 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10020FF0
// Name: void __near * MemAlloc_AllocAlignedUnattributed(unsigned int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void *__cdecl MemAlloc_AllocAlignedUnattributed(unsigned int size, unsigned int align)
{
  unsigned int v2; // eax
  void *result; // eax
  unsigned int v4; // esi

  v2 = align;
  if ( ((align - 1) & align) != 0 )
    return nullptr;
  if ( align <= 4 )
    v2 = 4;
  v4 = v2 - 1;
  result = _g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: size + v2 - 1 + 4);
  if ( result != nullptr )
  {
    *(_DWORD *)((~v4 & ((unsigned int)result + v4 + 4)) - 4) = result;
    return (void *)(~v4 & ((unsigned int)result + v4 + 4));
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10021040
// Name: void LFOWAV_FreeAll(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl LFOWAV_FreeAll()
{
  lfowav_t *v0; // edi
  dly_t *pdly; // esi

  v0 = lfowavs;
  do
  {
    if ( v0 != nullptr )
    {
      pdly = v0->pdly;
      if ( pdly != nullptr )
      {
        FLT_Free(pf: pdly->pflt);
        if ( pdly->w != nullptr )
          free(pMem: pdly->w);
        _V_memset(dest: pdly, fill: 0, count: 72);
      }
    }
    _V_memset(dest: v0++, fill: 0, count: 8);
  }
  while ( (int)v0 < (int)dfrs );
}

//------------------------------------------------------------------------------
// Address: 0x100210A0
// Name: void LFOWAV_Fill(int __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl LFOWAV_Fill(int *w, int count, int type)
{
  IUniformRandomStream *v3; // ecx
  int v4; // ecx
  int v5; // edx
  float v6; // xmm0_4
  int j; // ecx
  _BOOL2 v8; // dx
  int k; // eax
  int m; // esi
  int v11; // esi
  int v12; // esi
  int n; // eax
  int ii; // eax
  int v15; // esi
  int i; // [esp+20h] [ebp+10h]
  int ia; // [esp+20h] [ebp+10h]
  int ib; // [esp+20h] [ebp+10h]

  switch ( type )
  {
    case 1:
      v4 = 0;
      if ( count > 0 )
      {
        v5 = 0;
        do
        {
          v6 = (float)v5 / (float)count;
          w[v4] = (int)v6;
          if ( v4 > count / 2 )
            w[v4] = (int)(float)(32766.0 - v6);
          ++v4;
          v5 += 32766;
        }
        while ( v4 < count );
      }
      break;
    case 2:
      for ( j = 0; j < count; w[j - 1] = v8 ? 0 : 0x3FFF )
        v8 = j++ > count / 2;
      break;
    case 3:
      for ( k = 0; k < count; ++k )
        w[k] = (int)(float)((float)((float)k * 16383.0) / (float)count);
      break;
    case 4:
      for ( m = 0; m < count; ++m )
        w[m] = _RandomInt(this: v3, a2: 0, a3: 0x3FFF);
      break;
    case 5:
      v11 = 0;
      for ( i = 0; v11 < count; i = v11 )
        w[v11++] = (int)(pow((double)i / (float)count, 2.0) * 16383.0);
      break;
    case 6:
      v12 = 0;
      for ( ia = 0; v12 < count; ia = v12 )
        w[v12++] = (int)(pow(1.0 - (double)ia / (float)count, 2.0) * 16383.0);
      break;
    case 7:
      for ( n = 0; n < count; ++n )
        w[n] = (int)(float)((float)((float)n * 16383.0) / (float)count);
      break;
    case 8:
      for ( ii = 0; ii < count; ++ii )
        w[ii] = 0x3FFF - (int)(float)((float)((float)ii * 16383.0) / (float)count);
      break;
    default:
      v15 = 0;
      for ( ib = 0; v15 < count; ib = v15 )
        w[v15++] = (0x3FFF - (int)(sin((double)ib * 6.283185307179586 / (float)count + 4.71238898038469) * -16383.0))
                 / 2;
      break;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10021380
// Name: void LFO_Free(struct lfo_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl LFO_Free(lfo_t *plfo)
{
  if ( plfo != nullptr )
    _V_memset(dest: plfo, fill: 0, count: 56);
}

//------------------------------------------------------------------------------
// Address: 0x100213A0
// Name: struct lfo_t __near * LFO_Alloc(int,float,bool,float)
// Source: json
//------------------------------------------------------------------------------
lfo_t *__cdecl LFO_Alloc(int wtype, float freqHz, bool foneshot, float gain)
{
  int v4; // edi
  int v5; // ecx
  lfo_t *v6; // eax
  lfo_t *v8; // esi
  int v9; // eax
  float v10; // xmm0_4
  int v11; // eax
  int v12; // ecx

  v4 = 8;
  if ( wtype <= 8 )
    v4 = wtype;
  v5 = 0;
  v6 = lfos;
  while ( v6->fused )
  {
    ++v6;
    ++v5;
    if ( (int)v6 >= (int)lfowavs )
    {
      DevMsg(a1: "DSP: Warning, failed to allocate LFO.\n");
      return nullptr;
    }
  }
  v8 = &lfos[v5];
  if ( v8 != nullptr )
    _V_memset(dest: &lfos[v5], fill: 0, count: 56);
  v9 = dword_10454424[2 * v4];
  v8->foneshot = foneshot;
  v8->f = freqHz;
  v10 = freqHz * 0.011609977;
  v8->fused = true;
  v8->pdly = (dly_t *)v9;
  v8->gain = (int)(float)(gain * 4096.0);
  v11 = *(_DWORD *)(v9 + 8);
  v12 = (int)(float)(freqHz * 0.011609977);
  if ( foneshot )
  {
    if ( v12 > 4095 )
      v10 = (float)(v10 - (float)v12) + 4095.0;
    v8->pos1.p.D = v11;
    v8->pos1.p.cstep = 0;
    v8->pos1.p.pos = 0;
    v8->pos1.fhitend = false;
    v8->pos1.p.step = (int)(float)(v10 * 1048576.0);
    return v8;
  }
  else
  {
    if ( v12 > 4095 )
      v10 = (float)(v10 - (float)v12) + 4095.0;
    v8->pos.D = v11;
    v8->pos.cstep = 0;
    v8->pos.pos = 0;
    v8->pos.step = (int)(float)(v10 * 1048576.0);
    return v8;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100214D0
// Name: int LFO_GetNext(struct lfo_t __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl LFO_GetNext(lfo_t *plfo)
{
  int v1; // ecx
  int D; // edx
  int v3; // ecx
  int v4; // ecx
  int pos; // esi
  int step; // edx
  int v7; // ecx
  int v8; // ecx
  int gain; // ecx
  int result; // eax

  if ( plfo->foneshot != 0 )
  {
    pos = plfo->pos1.p.pos;
    if ( !plfo->pos1.fhitend )
    {
      step = plfo->pos1.p.step;
      v7 = step + plfo->pos1.p.cstep;
      plfo->pos1.p.pos = pos + (v7 >> 20);
      plfo->pos1.p.cstep = v7 - (v7 & 0xFFF00000);
      if ( step != 0 && (v8 = plfo->pos1.p.pos) >= 0 && v8 < plfo->pos1.p.D )
        pos = plfo->pos1.p.pos;
      else
        plfo->pos1.fhitend = true;
    }
  }
  else
  {
    v1 = plfo->pos.cstep + plfo->pos.step;
    plfo->pos.pos += v1 >> 20;
    D = plfo->pos.D;
    plfo->pos.cstep = v1 - (v1 & 0xFFF00000);
    v3 = plfo->pos.pos;
    if ( v3 > D )
      plfo->pos.pos = v3 - D - 1;
    v4 = plfo->pos.pos;
    if ( v4 < 0 )
      plfo->pos.pos = v4 + D + 1;
    pos = plfo->pos.pos;
  }
  gain = plfo->gain;
  result = plfo->pdly->w[pos];
  if ( gain != 4096 )
    return (gain * result) >> 12;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10021580
// Name: void LFO_GetNextN(struct lfo_t __near *,struct portable_samplepair_t __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl LFO_GetNextN(lfo_t *plfo, portable_samplepair_t *pbuffer, int SampleCount, int op)
{
  portable_samplepair_t *v4; // esi
  int v5; // edi
  int v6; // ecx
  int D; // edx
  int v8; // ecx
  int v9; // ecx
  int pos; // ecx
  int step; // edx
  int v12; // ecx
  int gain; // edx
  int v14; // ecx
  int Next; // eax
  int *p_right; // esi
  int SampleCounta; // [esp+1Ch] [ebp+10h]

  v4 = pbuffer;
  v5 = SampleCount;
  if ( op == 1 )
  {
    if ( SampleCount != 0 )
    {
      p_right = &pbuffer->right;
      do
      {
        *p_right = LFO_GetNext(plfo);
        p_right += 2;
        --v5;
      }
      while ( v5 != 0 );
    }
  }
  else if ( op == 2 )
  {
    if ( SampleCount != 0 )
    {
      do
      {
        Next = LFO_GetNext(plfo);
        v4->right = Next;
        v4->left = Next;
        ++v4;
        --v5;
      }
      while ( v5 != 0 );
    }
  }
  else if ( SampleCount != 0 )
  {
    do
    {
      --v5;
      if ( plfo->foneshot != 0 )
      {
        pos = plfo->pos1.p.pos;
        SampleCounta = pos;
        if ( !plfo->pos1.fhitend )
        {
          step = plfo->pos1.p.step;
          v12 = step + plfo->pos1.p.cstep;
          plfo->pos1.p.pos = SampleCounta + (v12 >> 20);
          plfo->pos1.p.cstep = v12 - (v12 & 0xFFF00000);
          if ( step == 0 || (pos = plfo->pos1.p.pos) < 0 || pos >= plfo->pos1.p.D )
          {
            pos = SampleCounta;
            plfo->pos1.fhitend = true;
          }
        }
      }
      else
      {
        v6 = plfo->pos.step + plfo->pos.cstep;
        plfo->pos.pos += v6 >> 20;
        D = plfo->pos.D;
        plfo->pos.cstep = v6 - (v6 & 0xFFF00000);
        v8 = plfo->pos.pos;
        if ( v8 > D )
          plfo->pos.pos = v8 - D - 1;
        v9 = plfo->pos.pos;
        if ( v9 < 0 )
          plfo->pos.pos = v9 + D + 1;
        pos = plfo->pos.pos;
      }
      gain = plfo->gain;
      if ( gain == 4096 )
        v14 = plfo->pdly->w[pos];
      else
        v14 = (gain * plfo->pdly->w[pos]) >> 12;
      v4->left = v14;
      ++v4;
    }
    while ( v5 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x100216B0
// Name: void LFO_Mod(struct lfo_t __near *,float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl LFO_Mod(lfo_t *plfo, float v)
{
  float v2; // xmm0_4

  v2 = (float)((float)((float)(v + 1.0) * plfo->f) * 0.011609977) * 1048576.0;
  if ( plfo->foneshot != 0 )
    plfo->pos.step = (int)v2;
  else
    plfo->pos1.p.step = (int)v2;
}

//------------------------------------------------------------------------------
// Address: 0x100216F0
// Name: void PTC_Free(struct ptc_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl PTC_Free(ptc_t *pptc)
{
  dly_t *pdly_in; // esi
  dly_t *pdly_out; // esi

  if ( pptc != nullptr )
  {
    pdly_in = pptc->pdly_in;
    if ( pdly_in != nullptr )
    {
      FLT_Free(pf: pdly_in->pflt);
      if ( pdly_in->w != nullptr )
        free(pMem: pdly_in->w);
      _V_memset(dest: pdly_in, fill: 0, count: 72);
    }
    pdly_out = pptc->pdly_out;
    if ( pdly_out != nullptr )
    {
      FLT_Free(pf: pdly_out->pflt);
      if ( pdly_out->w != nullptr )
        free(pMem: pdly_out->w);
      _V_memset(dest: pdly_out, fill: 0, count: 72);
    }
    _V_memset(dest: pptc, fill: 0, count: 72);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10021770
// Name: void PTC_FreeAll(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl PTC_FreeAll()
{
  ptc_t *v0; // edi
  dly_t *pdly_in; // esi
  dly_t *pdly_out; // esi

  v0 = ptcs;
  do
  {
    if ( v0 != nullptr )
    {
      pdly_in = v0->pdly_in;
      if ( pdly_in != nullptr )
      {
        FLT_Free(pf: pdly_in->pflt);
        if ( pdly_in->w != nullptr )
          free(pMem: pdly_in->w);
        _V_memset(dest: pdly_in, fill: 0, count: 72);
      }
      pdly_out = v0->pdly_out;
      if ( pdly_out != nullptr )
      {
        FLT_Free(pf: pdly_out->pflt);
        if ( pdly_out->w != nullptr )
          free(pMem: pdly_out->w);
        _V_memset(dest: pdly_out, fill: 0, count: 72);
      }
      _V_memset(dest: v0, fill: 0, count: 72);
    }
    ++v0;
  }
  while ( (int)v0 < (int)lfos );
}

//------------------------------------------------------------------------------
// Address: 0x10021800
// Name: void TimeExpand(int __near *,int __near *,int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl TimeExpand(int *w, int *v, int cin, int cout, int cxfade, int cduplicate)
{
  int *v6; // edx
  int v7; // ebx
  int v8; // esi
  int v9; // eax
  int v10; // edi
  int *v11; // ecx
  int *v12; // edi
  int v13; // edx
  int v14; // ebx
  int *v15; // ecx
  int v16; // esi
  int v17; // edi
  int v18; // eax
  int v19; // edx
  int v20; // eax
  int *v21; // ecx
  int m; // [esp+Ch] [ebp-8h]
  int D; // [esp+10h] [ebp-4h]
  int cina; // [esp+24h] [ebp+10h]
  int cduplicatea; // [esp+30h] [ebp+1Ch]
  int *cduplicateb; // [esp+30h] [ebp+1Ch]

  v6 = w;
  v7 = cin - cduplicate;
  v8 = cin - 1;
  v9 = cin - cxfade;
  v10 = cin - cduplicate - cxfade;
  D = cin - 1;
  m = cin - cduplicate;
  if ( cin - cxfade > 0 )
  {
    v11 = v;
    cduplicatea = cin - cxfade;
    do
    {
      *v11 = *(int *)((char *)v11 + (char *)w - (char *)v);
      ++v11;
      --cduplicatea;
    }
    while ( cduplicatea != 0 );
    v6 = w;
  }
  if ( v9 <= v8 )
  {
    v12 = &v6[v10];
    v13 = (char *)v6 - (char *)v;
    v14 = 0;
    v15 = &v[v9];
    cduplicateb = v12;
    cina = v13;
    v16 = v8 - v9 + 1;
    while ( 1 )
    {
      v17 = *(int *)((char *)v15 + v13);
      v18 = v14 / cxfade;
      v19 = *cduplicateb++;
      v14 += 4096;
      ++v15;
      --v16;
      *(v15 - 1) = (v17 + (v19 - v17) * v18) >> 12;
      if ( v16 == 0 )
        break;
      v13 = cina;
    }
    v8 = D;
    v6 = w;
    v7 = m;
  }
  v20 = v7;
  if ( v7 <= v8 )
  {
    v21 = &v[v8 + 1];
    do
      *v21++ = v6[v20++];
    while ( v20 <= v8 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x100218D0
// Name: void TimeCompress(int __near *,int __near *,int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl TimeCompress(int *w, int *v, int cin, int cout, int cxfade, int ccut)
{
  int v6; // eax
  int v7; // edx
  int *v8; // ecx
  int *v9; // edi
  int v10; // esi
  int v11; // edi
  int *v12; // ecx
  int v13; // ebx
  int v14; // eax
  int v15; // esi
  bool v16; // zf
  int cina; // [esp+20h] [ebp+10h]
  int *cinb; // [esp+20h] [ebp+10h]
  int p; // [esp+2Ch] [ebp+1Ch]
  int pa; // [esp+2Ch] [ebp+1Ch]

  v6 = cin - ccut;
  v7 = cin - ccut - cxfade;
  p = cin - cxfade;
  v8 = v;
  if ( v7 > 0 )
  {
    v9 = v;
    for ( cina = v7; cina != 0; --cina )
    {
      *v9 = *(int *)((char *)v9 + (char *)w - (char *)v);
      ++v9;
    }
    v8 = v;
  }
  if ( v7 < v6 )
  {
    v10 = (char *)w - (char *)v;
    v11 = 0;
    v12 = &v8[v7];
    cinb = &w[p];
    pa = v6 - v7;
    while ( 1 )
    {
      v13 = *cinb;
      v14 = v11 / cxfade;
      v15 = *(int *)((char *)v12 + v10);
      ++cinb;
      v11 += 4096;
      ++v12;
      v16 = pa-- == 1;
      *(v12 - 1) = (v15 + v14 * (v13 - v15)) >> 12;
      if ( v16 )
        break;
      v10 = (char *)w - (char *)v;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10021A80
// Name: void PTC_GetNextN(struct ptc_t __near *,struct portable_samplepair_t __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl PTC_GetNextN(ptc_t *pptc, portable_samplepair_t *pbuffer, int SampleCount, int op)
{
  int v4; // ebx
  portable_samplepair_t *v5; // edi
  int pos; // eax
  int step; // ecx
  int v8; // eax
  float fstep; // xmm0_4
  int cout; // ecx
  int v11; // eax
  int cxfade; // edx
  int Next; // eax
  int *p_right; // esi
  portable_samplepair_t *pbuffera; // [esp+18h] [ebp+Ch]
  portable_samplepair_t *pbufferb; // [esp+18h] [ebp+Ch]
  bool SampleCount_3; // [esp+1Fh] [ebp+13h]

  v4 = SampleCount;
  v5 = pbuffer;
  if ( op == 1 )
  {
    if ( SampleCount != 0 )
    {
      p_right = &pbuffer->right;
      do
      {
        *p_right = PTC_GetNext(pptc, x: *p_right);
        p_right += 2;
        --v4;
      }
      while ( v4 != 0 );
    }
  }
  else if ( op == 2 )
  {
    if ( SampleCount != 0 )
    {
      do
      {
        Next = PTC_GetNext(pptc, x: v5->left);
        v5->right = Next;
        v5->left = Next;
        ++v5;
        --v4;
      }
      while ( v4 != 0 );
    }
  }
  else if ( SampleCount != 0 )
  {
    do
    {
      pptc->pin[pptc->iin++] = v5->left;
      --v4;
      SampleCount_3 = pptc->iin >= pptc->cin;
      pos = pptc->psn.p.pos;
      pbuffera = (portable_samplepair_t *)pos;
      if ( !pptc->psn.fhitend )
      {
        step = pptc->psn.p.step;
        v8 = step + pptc->psn.p.cstep;
        pptc->psn.p.pos += v8 >> 20;
        pptc->psn.p.cstep = v8 - (v8 & 0xFFF00000);
        if ( step == 0 || (pos = pptc->psn.p.pos) < 0 || pos >= pptc->psn.p.D )
        {
          pos = (int)pbuffera;
          pptc->psn.fhitend = true;
        }
      }
      pbufferb = (portable_samplepair_t *)pptc->pout[pos];
      if ( SampleCount_3 )
      {
        fstep = pptc->fstep;
        cout = pptc->cout;
        pptc->iin = 0;
        if ( (int)fstep > 4095 )
          fstep = (float)(fstep - (float)(int)fstep) + 4095.0;
        pptc->psn.p.step = (int)(float)(fstep * 1048576.0);
        pptc->psn.p.cstep = 0;
        pptc->psn.p.pos = 0;
        pptc->psn.p.D = cout;
        pptc->psn.fhitend = false;
        v11 = pptc->cout;
        cxfade = pptc->cxfade;
        if ( pptc->fdup )
          TimeExpand(w: pptc->pin, v: pptc->pout, cin: pptc->cin, cout: v11, cxfade, cduplicate: pptc->cduplicate);
        else
          TimeCompress(w: pptc->pin, v: pptc->pout, cin: pptc->cin, cout: v11, cxfade, ccut: pptc->ccut);
      }
      v5->left = (int)pbufferb;
      ++v5;
    }
    while ( v4 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10021C10
// Name: void ENV_Free(struct env_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ENV_Free(env_t *penv)
{
  if ( penv != nullptr )
    _V_memset(dest: penv, fill: 0, count: 184);
}

//------------------------------------------------------------------------------
// Address: 0x10021DA0
// Name: void ENV_GetNextN(struct env_t __near *,struct portable_samplepair_t __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ENV_GetNextN(env_t *penv, portable_samplepair_t *pbuffer, int SampleCount, int op)
{
  int v4; // esi
  portable_samplepair_t *v5; // ebx
  int v6; // esi
  bool *v7; // edi
  int v8; // eax
  int v9; // ecx
  int v10; // esi
  bool *v11; // edi
  int v12; // eax
  int v13; // ecx
  int *p_right; // edx
  int ienv; // esi
  int Next; // eax
  int v17; // ecx
  int pbuffera; // [esp+18h] [ebp+Ch]
  int pbufferb; // [esp+18h] [ebp+Ch]
  int pbufferc; // [esp+18h] [ebp+Ch]
  int count; // [esp+1Ch] [ebp+10h]
  int counta; // [esp+1Ch] [ebp+10h]
  int countb; // [esp+1Ch] [ebp+10h]
  int *opa; // [esp+20h] [ebp+14h]

  v4 = SampleCount;
  v5 = pbuffer;
  if ( op == 1 )
  {
    if ( SampleCount != 0 )
    {
      p_right = &pbuffer->right;
      opa = &pbuffer->right;
      do
      {
        countb = v4 - 1;
        pbufferc = *p_right;
        if ( penv->fhitend )
        {
          v17 = 0;
        }
        else
        {
          ienv = penv->ienv;
          Next = RMP_GetNext(prmp: &penv->rmps[ienv]);
          if ( penv->rmps[ienv].fhitend )
            ++ienv;
          penv->ienv = ienv;
          if ( ienv > 3 )
            penv->fhitend = true;
          if ( penv->fexp )
            v17 = (Next * ((pbufferc * Next) >> 14)) >> 14;
          else
            v17 = (pbufferc * Next) >> 14;
        }
        v4 = countb;
        *opa = v17;
        p_right = opa + 2;
        opa += 2;
      }
      while ( countb != 0 );
    }
  }
  else if ( op == 2 )
  {
    if ( SampleCount != 0 )
    {
      do
      {
        pbufferb = v5->left;
        counta = v4 - 1;
        if ( penv->fhitend )
        {
          v13 = 0;
        }
        else
        {
          v10 = penv->ienv;
          v11 = &penv->fused + 44 * v10;
          v12 = RMP_GetNext(prmp: (rmp_t *)(v11 + 8));
          if ( v11[28] )
            ++v10;
          penv->ienv = v10;
          if ( v10 > 3 )
            penv->fhitend = true;
          if ( penv->fexp )
            v13 = (v12 * ((pbufferb * v12) >> 14)) >> 14;
          else
            v13 = (pbufferb * v12) >> 14;
        }
        v4 = counta;
        v5->right = v13;
        v5->left = v13;
        ++v5;
      }
      while ( counta != 0 );
    }
  }
  else if ( SampleCount != 0 )
  {
    do
    {
      pbuffera = v5->left;
      count = v4 - 1;
      if ( penv->fhitend )
      {
        v9 = 0;
      }
      else
      {
        v6 = penv->ienv;
        v7 = &penv->fused + 44 * v6;
        v8 = RMP_GetNext(prmp: (rmp_t *)(v7 + 8));
        if ( v7[28] )
          ++v6;
        penv->ienv = v6;
        if ( v6 > 3 )
          penv->fhitend = true;
        if ( penv->fexp )
          v9 = (v8 * ((pbuffera * v8) >> 14)) >> 14;
        else
          v9 = (pbuffera * v8) >> 14;
      }
      v4 = count;
      v5->left = v9;
      ++v5;
    }
    while ( count != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10021F40
// Name: struct env_t __near * ENV_Params(struct prc_t __near *)
// Source: json
//------------------------------------------------------------------------------
env_t *__cdecl ENV_Params(prc_t *pprc)
{
  float attack; // [esp+Ch] [ebp-20h]
  float decay; // [esp+10h] [ebp-1Ch]
  float sustain; // [esp+14h] [ebp-18h]
  float release; // [esp+18h] [ebp-14h]

  release = 0.001 * pprc->prm[7];
  sustain = pprc->prm[6] * 0.001;
  decay = pprc->prm[5] * 0.001;
  attack = pprc->prm[4] * 0.001;
  return ENV_Alloc(
           type: (int)pprc->prm[0],
           famp1: pprc->prm[1],
           famp2: pprc->prm[2],
           famp3: pprc->prm[3],
           attack,
           decay,
           sustain,
           release,
           fexp: pprc->prm[8] > 0.0);
}

//------------------------------------------------------------------------------
// Address: 0x10021FE0
// Name: void EFO_Free(struct efo_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl EFO_Free(efo_t *pefo)
{
  if ( pefo != nullptr )
    _V_memset(dest: pefo, fill: 0, count: 116);
}

//------------------------------------------------------------------------------
// Address: 0x10022110
// Name: int EFO_GetNext(struct efo_t __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl EFO_GetNext(efo_t *pefo, int x)
{
  unsigned int v2; // eax
  int result; // eax
  bool v4; // zf
  bool bgateon; // cl
  int Next; // edi
  double attack_time; // st7
  int v8; // edi
  int v9; // ecx
  float ramptime; // [esp+0h] [ebp-1Ch]
  float ramptimea; // [esp+0h] [ebp-1Ch]

  v2 = abs32(x);
  result = ((int)(2047 * (pefo->xout - v2)) >> 11) + v2;
  v4 = !pefo->bgate;
  pefo->xout = result;
  if ( !v4 )
  {
    bgateon = pefo->bgateon;
    if ( bgateon )
      pefo->bgateon = result >= pefo->thresh_off;
    else
      pefo->bgateon = result >= pefo->thresh;
    if ( pefo->bgateon )
    {
      if ( bgateon )
      {
        if ( pefo->rmp_attack.fhitend )
          return x;
        else
          return (x * RMP_GetNext(prmp: &pefo->rmp_attack)) >> 12;
      }
      else
      {
        if ( pefo->rmp_decay.fhitend )
          Next = 0;
        else
          Next = RMP_GetNext(prmp: &pefo->rmp_decay);
        attack_time = pefo->attack_time;
        pefo->rmp_decay.fhitend = true;
        ramptime = attack_time;
        RMP_Init(prmp: &pefo->rmp_attack, ramptime, initval: Next, targetval: 4096, bEndAtTime: false);
        return (x * Next) >> 12;
      }
    }
    else if ( bgateon )
    {
      if ( pefo->rmp_attack.fhitend )
        v8 = 4096;
      else
        v8 = RMP_GetNext(prmp: &pefo->rmp_attack);
      ramptimea = pefo->decay_time;
      pefo->rmp_attack.fhitend = true;
      RMP_Init(prmp: &pefo->rmp_decay, ramptime: ramptimea, initval: v8, targetval: 0, bEndAtTime: false);
      result = (x * v8) >> 12;
      if ( pefo->bexp )
        return (v8 * result) >> 12;
    }
    else if ( pefo->rmp_decay.fhitend )
    {
      return 0;
    }
    else
    {
      v9 = RMP_GetNext(prmp: &pefo->rmp_decay);
      result = (x * v9) >> 12;
      if ( pefo->bexp )
        return (v9 * result) >> 12;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10022260
// Name: void EFO_GetNextN(struct efo_t __near *,struct portable_samplepair_t __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl EFO_GetNextN(efo_t *pefo, portable_samplepair_t *pbuffer, portable_samplepair_t *SampleCount, int op)
{
  portable_samplepair_t *v5; // edi
  int left; // ebx
  unsigned int v7; // eax
  int v8; // eax
  bool v9; // zf
  bool bgateon; // cl
  int v11; // edi
  int v12; // eax
  int v13; // eax
  int Next; // eax
  int *p_right; // esi
  float ramptime; // [esp+0h] [ebp-1Ch]
  float ramptimea; // [esp+0h] [ebp-1Ch]
  int count; // [esp+28h] [ebp+Ch]
  portable_samplepair_t *pb; // [esp+2Ch] [ebp+10h]

  v5 = pbuffer;
  pb = pbuffer;
  if ( op == 1 )
  {
    if ( SampleCount != nullptr )
    {
      p_right = &pbuffer->right;
      do
      {
        *p_right = EFO_GetNext(pefo, x: *p_right);
        p_right += 2;
        SampleCount = (portable_samplepair_t *)((char *)SampleCount - 1);
      }
      while ( SampleCount != nullptr );
    }
  }
  else if ( op == 2 )
  {
    for ( ; SampleCount != nullptr; SampleCount = (portable_samplepair_t *)((char *)SampleCount - 1) )
    {
      Next = EFO_GetNext(pefo, x: v5->left);
      v5->right = Next;
      v5->left = Next;
      ++v5;
    }
  }
  else if ( SampleCount != nullptr )
  {
    while ( 1 )
    {
      count = (int)&SampleCount[-1].right + 3;
      left = v5->left;
      v7 = abs32(v5->left);
      v8 = ((int)(2047 * (pefo->xout - v7)) >> 11) + v7;
      v9 = !pefo->bgate;
      pefo->xout = v8;
      if ( v9 )
        goto LABEL_31;
      bgateon = pefo->bgateon;
      if ( bgateon )
        pefo->bgateon = v8 >= pefo->thresh_off;
      else
        pefo->bgateon = v8 >= pefo->thresh;
      if ( pefo->bgateon )
      {
        if ( !bgateon )
        {
          if ( pefo->rmp_decay.fhitend )
            v11 = 0;
          else
            v11 = RMP_GetNext(prmp: &pefo->rmp_decay);
          ramptime = pefo->attack_time;
          pefo->rmp_decay.fhitend = true;
          RMP_Init(prmp: &pefo->rmp_attack, ramptime, initval: v11, targetval: 4096, bEndAtTime: false);
LABEL_18:
          v8 = (left * v11) >> 12;
          v5 = pb;
          goto LABEL_31;
        }
        if ( pefo->rmp_attack.fhitend )
          v8 = left;
        else
          v8 = (left * RMP_GetNext(prmp: &pefo->rmp_attack)) >> 12;
      }
      else if ( bgateon )
      {
        if ( pefo->rmp_attack.fhitend )
          v11 = 4096;
        else
          v11 = RMP_GetNext(prmp: &pefo->rmp_attack);
        ramptimea = pefo->decay_time;
        pefo->rmp_attack.fhitend = true;
        RMP_Init(prmp: &pefo->rmp_decay, ramptime: ramptimea, initval: v11, targetval: 0, bEndAtTime: false);
        if ( !pefo->bexp )
          goto LABEL_18;
        v12 = v11 * ((left * v11) >> 12);
        v5 = pb;
        v8 = v12 >> 12;
      }
      else if ( pefo->rmp_decay.fhitend )
      {
        v8 = 0;
      }
      else
      {
        v13 = RMP_GetNext(prmp: &pefo->rmp_decay);
        if ( pefo->bexp )
          v8 = (v13 * ((left * v13) >> 12)) >> 12;
        else
          v8 = (left * v13) >> 12;
      }
LABEL_31:
      v5->left = v8;
      pb = ++v5;
      if ( count == 0 )
        return;
      SampleCount = (portable_samplepair_t *)count;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10022440
// Name: struct efo_t __near * EFO_Params(struct prc_t __near *)
// Source: json
//------------------------------------------------------------------------------
efo_t *__cdecl EFO_Params(prc_t *pprc)
{
  double v1; // st7
  float threshold; // [esp+0h] [ebp-10h]
  float attack_sec; // [esp+4h] [ebp-Ch]
  float dB; // [esp+8h] [ebp-8h]
  float dBa; // [esp+8h] [ebp-8h]

  dB = dB_To_Gain(dB: pprc->prm[0]);
  v1 = Gain_To_Amplitude(gain: dB);
  if ( pprc->prm[0] == 0.0 )
    v1 = 0.0;
  dBa = 0.001 * pprc->prm[2];
  attack_sec = pprc->prm[1] * 0.001;
  threshold = v1;
  return EFO_Alloc(threshold, attack_sec, decay_sec: dBa, bexp: pprc->prm[3] > 0.0);
}

//------------------------------------------------------------------------------
// Address: 0x100224C0
// Name: void CRS_Free(struct crs_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CRS_Free(crs_t *pcrs)
{
  mdy_t *pmdy; // edi
  dly_t *pdly; // esi
  lfo_t *plfo; // eax

  if ( pcrs != nullptr )
  {
    pmdy = pcrs->pmdy;
    if ( pmdy != nullptr )
    {
      pdly = pmdy->pdly;
      if ( pdly != nullptr )
      {
        FLT_Free(pf: pdly->pflt);
        if ( pdly->w != nullptr )
          free(pMem: pdly->w);
        _V_memset(dest: pdly, fill: 0, count: 72);
      }
      _V_memset(dest: pmdy, fill: 0, count: 76);
    }
    plfo = pcrs->plfo;
    if ( plfo != nullptr )
      _V_memset(dest: plfo, fill: 0, count: 56);
    _V_memset(dest: pcrs, fill: 0, count: 16);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10022540
// Name: void CRS_FreeAll(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CRS_FreeAll()
{
  crs_t *v0; // ebx
  mdy_t *pmdy; // edi
  dly_t *pdly; // esi
  lfo_t *plfo; // eax

  v0 = crss;
  do
  {
    if ( v0 != nullptr )
    {
      pmdy = v0->pmdy;
      if ( pmdy != nullptr )
      {
        pdly = pmdy->pdly;
        if ( pdly != nullptr )
        {
          FLT_Free(pf: pdly->pflt);
          if ( pdly->w != nullptr )
            free(pMem: pdly->w);
          _V_memset(dest: pdly, fill: 0, count: 72);
        }
        _V_memset(dest: pmdy, fill: 0, count: 76);
      }
      plfo = v0->plfo;
      if ( plfo != nullptr )
        _V_memset(dest: plfo, fill: 0, count: 56);
      _V_memset(dest: v0, fill: 0, count: 16);
    }
    ++v0;
  }
  while ( (int)v0 < (int)efos );
}

//------------------------------------------------------------------------------
// Address: 0x100225C0
// Name: int CRS_GetNext(struct crs_t __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl CRS_GetNext(crs_t *pcrs, int x)
{
  int Next; // esi
  int v4; // eax
  int v5; // edi
  mdy_t *pmdy; // esi
  dly_t *pdly; // edx
  float ramptime; // [esp+0h] [ebp-20h]
  int y; // [esp+1Ch] [ebp-4h]
  crs_t *pcrsa; // [esp+28h] [ebp+8h]

  Next = MDY_GetNext(pmdy: pcrs->pmdy, x);
  y = Next;
  v4 = LFO_GetNext(plfo: pcrs->plfo);
  v5 = v4;
  if ( v4 == pcrs->lfoprev )
    return Next;
  pmdy = pcrs->pmdy;
  pdly = pmdy->pdly;
  if ( v4 < 0 )
    v5 = 0;
  pcrsa = (crs_t *)(pdly->D0 - ((v5 * pdly->D0) >> 14));
  if ( pdly->D0 < (int)pcrsa )
    pcrsa = (crs_t *)pdly->D0;
  ramptime = pmdy->ramptime;
  pmdy->fchanging = true;
  RMP_Init(prmp: &pmdy->rmp_interp, ramptime, initval: 0, targetval: 4096, bEndAtTime: false);
  pmdy->pdly->tnew = (int)pcrsa;
  pmdy->pdly->xf = 0;
  pcrs->lfoprev = v5;
  return y;
}

//------------------------------------------------------------------------------
// Address: 0x10022660
// Name: void CRS_GetNextN(struct crs_t __near *,struct portable_samplepair_t __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CRS_GetNextN(crs_t *pcrs, portable_samplepair_t *pbuffer, int SampleCount, int op)
{
  int v4; // esi
  portable_samplepair_t *v5; // edi
  int v6; // ebx
  mdy_t *pmdy; // esi
  dly_t *pdly; // ecx
  int D0; // eax
  int v10; // ecx
  dly_t *v11; // edx
  int Next; // eax
  int *p_right; // edi
  float ramptime; // [esp+0h] [ebp-1Ch]
  int count; // [esp+28h] [ebp+Ch]
  int SampleCounta; // [esp+2Ch] [ebp+10h]
  int opa; // [esp+30h] [ebp+14h]

  v4 = SampleCount;
  v5 = pbuffer;
  if ( op == 1 )
  {
    if ( SampleCount != 0 )
    {
      p_right = &pbuffer->right;
      do
      {
        *p_right = CRS_GetNext(pcrs, x: *p_right);
        p_right += 2;
        --v4;
      }
      while ( v4 != 0 );
    }
  }
  else if ( op == 2 )
  {
    if ( SampleCount != 0 )
    {
      do
      {
        Next = CRS_GetNext(pcrs, x: v5->left);
        v5->right = Next;
        v5->left = Next;
        ++v5;
        --v4;
      }
      while ( v4 != 0 );
    }
  }
  else if ( SampleCount != 0 )
  {
    do
    {
      count = --v4;
      opa = MDY_GetNext(pmdy: pcrs->pmdy, x: v5->left);
      v6 = LFO_GetNext(plfo: pcrs->plfo);
      if ( v6 != pcrs->lfoprev )
      {
        pmdy = pcrs->pmdy;
        pdly = pmdy->pdly;
        D0 = pdly->D0;
        if ( v6 < 0 )
          v6 = 0;
        v10 = pdly->D0;
        SampleCounta = D0 - ((v6 * D0) >> 14);
        if ( v10 < SampleCounta )
          SampleCounta = v10;
        ramptime = pmdy->ramptime;
        pmdy->fchanging = true;
        RMP_Init(prmp: &pmdy->rmp_interp, ramptime, initval: 0, targetval: 4096, bEndAtTime: false);
        pmdy->pdly->tnew = SampleCounta;
        v11 = pmdy->pdly;
        v4 = count;
        v11->xf = 0;
        pcrs->lfoprev = v6;
      }
      v5->left = opa;
      ++v5;
    }
    while ( v4 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x100227A0
// Name: struct amp_t __near * AMP_Alloc(float,float,float,float,float,float,float,bool)
// Source: json
//------------------------------------------------------------------------------
amp_t *__cdecl AMP_Alloc(
        float gain,
        float vthresh,
        float distmix,
        float vfeed,
        float ramptime,
        float modtime,
        float depth,
        bool brand)
{
  int v8; // esi
  amp_t *v9; // eax
  amp_t *v11; // esi
  int v12; // eax
  int v13; // eax

  v8 = 0;
  v9 = &amps[1];
  while ( v9[-1].fused )
  {
    if ( !v9->fused )
    {
      ++v8;
      break;
    }
    if ( !v9[1].fused )
    {
      v8 += 2;
      break;
    }
    if ( !v9[2].fused )
    {
      v8 += 3;
      break;
    }
    v9 += 4;
    v8 += 4;
    if ( (int)v9 >= (int)&crss[5].lfoprev )
      break;
  }
  if ( v8 == 64 )
  {
    DevMsg(a1: "DSP: Warning, failed to allocate amp.\n");
    return nullptr;
  }
  else
  {
    v11 = &amps[v8];
    if ( v11 != nullptr )
      _V_memset(dest: v11, fill: 0, count: 92);
    v12 = (int)(float)(gain * 4096.0);
    v11->gain = v12;
    v11->gain_max = v12;
    v11->fused = true;
    v11->distmix = (int)(float)(distmix * 4096.0);
    v11->vfeed = (int)(float)(vfeed * 4096.0);
    v11->ramptime = ramptime;
    v11->vthresh = (int)(vthresh * 32767.0);
    v13 = (int)(float)(modtime * 44100.0);
    v11->mtime = v13;
    v11->mtimecur = v13;
    v11->brand = brand;
    v11->depth = (int)(float)(depth * 4096.0);
    return v11;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100228B0
// Name: int AMP_GetNext(struct amp_t __near *,int)
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
int __cdecl AMP_GetNext(amp_t *pamp, int x)
{
  int v2; // ecx
  int vthresh; // eax
  int distmix; // edx
  int v5; // edi
  int Next; // eax
  bool v7; // zf
  int mtime; // eax
  int mtimecur; // ecx
  int gain_max; // ecx
  int v11; // edx
  int v12; // edx
  int v13; // eax
  int v14; // edx
  double ramptime; // st7
  float v17; // [esp+0h] [ebp-18h]
  int gain; // [esp+4h] [ebp-14h]

  v2 = x;
  vthresh = pamp->vthresh;
  if ( vthresh < 4096 )
  {
    distmix = pamp->distmix;
    if ( distmix != 0 )
    {
      if ( x <= vthresh )
      {
        vthresh = -vthresh;
        if ( x >= vthresh )
          vthresh = x;
      }
      if ( distmix < 4096 )
        vthresh = x + ((distmix * (vthresh - x)) >> 12);
      v2 = vthresh;
    }
  }
  v5 = (v2 * pamp->gain) >> 12;
  if ( pamp->fchanging )
  {
    Next = RMP_GetNext(prmp: &pamp->rmp_interp);
    v7 = !pamp->rmp_interp.fhitend;
    pamp->gain = Next;
    if ( !v7 )
      pamp->fchanging = false;
  }
  else if ( pamp->mtime == 0 )
  {
    return v5;
  }
  mtime = pamp->mtime;
  if ( mtime != 0 )
  {
    mtimecur = pamp->mtimecur;
    pamp->mtimecur = mtimecur - 1;
    if ( mtimecur == 0 )
    {
      gain_max = pamp->gain_max;
      v11 = gain_max * pamp->depth;
      pamp->mtimecur = mtime;
      v12 = v11 >> 12;
      v13 = gain_max - v12;
      if ( pamp->brand )
      {
        v14 = gain_max - v12;
        if ( v13 > gain_max || (v14 = gain_max, v13 >= gain_max) )
          v13 = gain_max;
        v13 = _RandomInt(this: (IUniformRandomStream *)gain_max, a2: v13, a3: v14);
      }
      else if ( pamp->gain == v13 )
      {
        v13 = gain_max;
      }
      ramptime = pamp->ramptime;
      gain = pamp->gain;
      pamp->fchanging = true;
      v17 = ramptime;
      RMP_Init(prmp: &pamp->rmp_interp, ramptime: v17, initval: gain, targetval: v13, bEndAtTime: false);
    }
  }
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x100229A0
// Name: void AMP_GetNextN(struct amp_t __near *,struct portable_samplepair_t __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __cdecl AMP_GetNextN(amp_t *pamp, portable_samplepair_t *pbuffer, int SampleCount, int op)
{
  int v4; // ebx
  portable_samplepair_t *v5; // edi
  int vthresh; // eax
  int left; // ecx
  int distmix; // edx
  int v9; // ebx
  int v10; // eax
  bool v11; // zf
  int mtime; // eax
  int mtimecur; // ecx
  int gain_max; // ecx
  int v15; // edx
  int v16; // edx
  int v17; // eax
  int v18; // edx
  int Next; // eax
  int *p_right; // esi
  float ramptime; // [esp+0h] [ebp-1Ch]
  int gain; // [esp+4h] [ebp-18h]
  int count; // [esp+2Ch] [ebp+10h]

  v4 = SampleCount;
  v5 = pbuffer;
  if ( op == 1 )
  {
    if ( SampleCount != 0 )
    {
      p_right = &pbuffer->right;
      do
      {
        *p_right = AMP_GetNext(pamp, x: *p_right);
        p_right += 2;
        --v4;
      }
      while ( v4 != 0 );
    }
  }
  else if ( op == 2 )
  {
    if ( SampleCount != 0 )
    {
      do
      {
        Next = AMP_GetNext(pamp, x: v5->left);
        v5->right = Next;
        v5->left = Next;
        ++v5;
        --v4;
      }
      while ( v4 != 0 );
    }
  }
  else if ( SampleCount != 0 )
  {
    while ( 1 )
    {
      vthresh = pamp->vthresh;
      left = v5->left;
      count = v4 - 1;
      if ( vthresh < 4096 )
      {
        distmix = pamp->distmix;
        if ( distmix != 0 )
        {
          if ( left <= vthresh )
          {
            vthresh = -vthresh;
            if ( left >= vthresh )
              vthresh = v5->left;
          }
          if ( distmix >= 4096 )
            left = vthresh;
          else
            left += (distmix * (vthresh - left)) >> 12;
        }
      }
      v9 = (left * pamp->gain) >> 12;
      if ( pamp->fchanging )
      {
        v10 = RMP_GetNext(prmp: &pamp->rmp_interp);
        v11 = !pamp->rmp_interp.fhitend;
        pamp->gain = v10;
        if ( !v11 )
          pamp->fchanging = false;
      }
      else if ( pamp->mtime == 0 )
      {
        goto LABEL_29;
      }
      mtime = pamp->mtime;
      if ( mtime != 0 )
      {
        mtimecur = pamp->mtimecur;
        pamp->mtimecur = mtimecur - 1;
        if ( mtimecur == 0 )
        {
          gain_max = pamp->gain_max;
          v15 = gain_max * pamp->depth;
          pamp->mtimecur = mtime;
          v16 = v15 >> 12;
          v17 = gain_max - v16;
          if ( pamp->brand )
          {
            v18 = gain_max - v16;
            if ( v17 > gain_max || (v18 = gain_max, v17 >= gain_max) )
              v17 = gain_max;
            v17 = _RandomInt(this: (IUniformRandomStream *)gain_max, a2: v17, a3: v18);
          }
          else if ( pamp->gain == v17 )
          {
            v17 = gain_max;
          }
          gain = pamp->gain;
          ramptime = pamp->ramptime;
          pamp->fchanging = true;
          RMP_Init(prmp: &pamp->rmp_interp, ramptime, initval: gain, targetval: v17, bEndAtTime: false);
        }
      }
LABEL_29:
      v5->left = v9;
      ++v5;
      if ( count == 0 )
        return;
      v4 = count;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10022B10
// Name: struct amp_t __near * AMP_Params(struct prc_t __near *)
// Source: json
//------------------------------------------------------------------------------
amp_t *__cdecl AMP_Params(prc_t *pprc)
{
  float v2; // xmm2_4
  double v3; // st7
  double v4; // st6
  double v5; // st6
  float v7; // [esp+10h] [ebp-1Ch]
  float v8; // [esp+14h] [ebp-18h]
  float depth; // [esp+28h] [ebp-4h]
  float brand; // [esp+34h] [ebp+8h]

  v2 = pprc->prm[7];
  depth = 0.0;
  brand = pprc->prm[4];
  if ( brand <= 0.0 )
  {
    v3 = 0.0;
    v5 = 0.0;
  }
  else
  {
    v3 = pprc->prm[6] * 0.001;
    v4 = 0.01;
    if ( brand > 0.01 )
      v4 = brand;
    depth = pprc->prm[5];
    v5 = 1.0 / v4;
  }
  v8 = v5;
  v7 = v3;
  return AMP_Alloc(
           gain: pprc->prm[0],
           vthresh: pprc->prm[1],
           distmix: pprc->prm[2],
           vfeed: pprc->prm[3],
           ramptime: v7,
           modtime: v8,
           depth,
           brand: v2 > 0.0);
}

//------------------------------------------------------------------------------
// Address: 0x10022BD0
// Name: int NULL_GetNext(void __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl NULL_GetNext(void *p, int x)
{
  return x;
}

//------------------------------------------------------------------------------
// Address: 0x10022BE0
// Name: void __near * NULL_VParams(void __near *)
// Source: json
//------------------------------------------------------------------------------
nul_t *__cdecl NULL_VParams()
{
  return nuls;
}

//------------------------------------------------------------------------------
// Address: 0x10022BF0
// Name: void PRC_FreeAll(struct prc_t __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl PRC_FreeAll(prc_t *prcs, int count)
{
  void **p_pdata; // esi
  int i; // edi
  void (__cdecl *v4)(void *); // ecx

  if ( count > 0 )
  {
    p_pdata = &prcs->pdata;
    for ( i = count; i != 0; --i )
    {
      v4 = (void (__cdecl *)(void *))*(p_pdata - 2);
      if ( v4 != nullptr && *p_pdata != nullptr )
        v4(a1: *p_pdata);
      p_pdata += 23;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10022C30
// Name: void PRC_Print(struct prc_t const __near &,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl PRC_Print(const prc_t *prc, int nIndentation)
{
  char *IndentationText; // edi
  int type; // eax
  float *prm; // edi
  const char *pIndent; // [esp+14h] [ebp-8h]
  int i; // [esp+18h] [ebp-4h]
  const char *pType; // [esp+24h] [ebp+8h]

  IndentationText = GetIndentationText(nIndentation);
  pIndent = IndentationText;
  DevMsg(a1: "%sPRC: %08X [Addr]\n", IndentationText, prc);
  type = prc->type;
  pType = "Unknown";
  switch ( type )
  {
    case 0:
      pType = "NULL";
      break;
    case 1:
      pType = "DLY - Simple feedback reverb";
      break;
    case 2:
      pType = "RVA - Parallel reverbs";
      break;
    case 3:
      pType = "FLT - Lowpass or highpass filter";
      break;
    case 4:
      pType = "CRS - Chorus";
      break;
    case 5:
      pType = "PTC - Pitch shifter";
      break;
    case 6:
      pType = "ENV - Adsr envelope";
      break;
    case 7:
      pType = "LFO";
      break;
    case 8:
      pType = "EFO - Envelope follower";
      break;
    case 9:
      pType = "MDY - Mod delay";
      break;
    case 10:
      pType = "DFR - Diffusor - n series allpass delays";
      break;
    case 11:
      pType = "AMP - Amplifier with distortion";
      break;
    default:
      break;
  }
  DevMsg(a1: "%sprm: ", IndentationText);
  prm = prc->prm;
  for ( i = 16; i != 0; --i )
    DevMsg(a1: "%f ", *prm++);
  DevMsg(a1: "\n");
  DevMsg(a1: "%sType: %s -", pIndent, pType);
  switch ( prc->type )
  {
    case 1:
      DLY_Print(delay: (const dly_t *)prc->pdata, nIndentation: nIndentation + 1);
      break;
    case 2:
      RVA_Print(rva: (const rva_t *)prc->pdata, nIndentation: nIndentation + 1);
      break;
    case 3:
      FLT_Print(filter: (const flt_t *)prc->pdata, nIndentation: nIndentation + 1);
      break;
    case 4:
      DevMsg(a1: "CRS_Print is not implemented\n");
      break;
    case 5:
      DevMsg(a1: "PTC_Print is not implemented\n");
      break;
    case 6:
      DevMsg(a1: "ENV_Print is not implemented\n");
      break;
    case 7:
      DevMsg(a1: "LFO_Print is not implemented\n");
      break;
    case 8:
      DevMsg(a1: "EFO_Print is not implemented\n");
      break;
    case 9:
      MDY_Print(modDelay: (const mdy_t *)prc->pdata, nIndentation: nIndentation + 1);
      break;
    case 0xA:
      DFR_Print(dfr: (const dfr_t *)prc->pdata, nIndentation: nIndentation + 1);
      break;
    case 0xB:
      DevMsg(a1: "AMP_Print is not implemented\n");
      break;
    default:
      return;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10022E70
// Name: void PSET_UpdateDuration(struct pset_t __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl PSET_UpdateDuration(pset_t *ppset, int SampleCount)
{
  int csamp_duration; // eax

  if ( ppset != nullptr && ppset->duration > 0.0 )
  {
    csamp_duration = ppset->csamp_duration;
    if ( csamp_duration > 0 )
      ppset->csamp_duration = csamp_duration - SampleCount;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10023000
// Name: void PSET_GetNextN(struct pset_t __near *,struct portable_samplepair_t __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl PSET_GetNextN(pset_t *ppset, portable_samplepair_t *pbuffer, int SampleCount, int op)
{
  int cprcs; // edi
  void **p_pdata; // esi

  cprcs = ppset->cprcs;
  if ( ppset->type == 1 )
  {
    if ( cprcs > 0 )
    {
      p_pdata = &ppset->prcs[0].pdata;
      do
      {
        ((void (__cdecl *)(void *, portable_samplepair_t *, int, int))*(p_pdata - 3))(
          a1: *p_pdata,
          a2: pbuffer,
          a3: SampleCount,
          a4: op);
        p_pdata += 23;
        --cprcs;
      }
      while ( cprcs != 0 );
    }
  }
  else
  {
    ppset->prcs[0].pfnGetNextN(a1: ppset->prcs[0].pdata, a2: pbuffer, a3: SampleCount, a4: op);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10023060
// Name: int PSET_GetNext(struct pset_t __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl PSET_GetNext(pset_t *ppset, int x)
{
  int result; // eax
  int v3; // eax
  prc_t *prcs; // edi
  int v5; // edx
  int v6; // eax
  int v7; // edx
  int v8; // eax
  int v9; // edx
  int v10; // eax
  int v11; // edx
  int v12; // eax
  int v13; // ecx
  int v14; // eax
  int v15; // ecx
  int v16; // eax
  int v17; // ecx
  int v18; // eax
  int v19; // ecx
  int v20; // eax
  int v21; // ecx
  int v22; // edx
  int v23; // eax
  int v24; // edx
  int v25; // eax
  int v26; // edx
  int v27; // eax
  int v28; // eax
  __m128i v29; // xmm0
  int v30; // eax
  int v31; // edx
  int v32; // eax
  int v33; // ecx
  int v34; // eax
  __m128i v35; // xmm0
  int v36; // eax
  int v37; // ecx

  if ( ppset->type == 0 )
    return ppset->prcs[0].pfnGetNext(a1: ppset->prcs[0].pdata, a2: x);
  v3 = x;
  if ( ppset->type == 1 )
  {
    prcs = ppset->prcs;
    switch ( ppset->cprcs )
    {
      case 0:
      case 1:
        goto $LN12_3;
      case 2:
        goto $LN13;
      case 3:
        goto $LN14_2;
      case 4:
        goto $LN15_2;
      default:
        v3 = ppset->prcs[0].pfnGetNext(a1: ppset->prcs[0].pdata, a2: x);
        prcs = &ppset->prcs[1];
$LN15_2:
        v3 = prcs->pfnGetNext(a1: prcs->pdata, a2: v3);
        ++prcs;
$LN14_2:
        v3 = prcs->pfnGetNext(a1: prcs->pdata, a2: v3);
        ++prcs;
$LN13:
        v3 = prcs->pfnGetNext(a1: prcs->pdata, a2: v3);
        ++prcs;
$LN12_3:
        result = prcs->pfnGetNext(a1: prcs->pdata, a2: v3);
        break;
    }
  }
  else
  {
    ppset->w[0] = x;
    switch ( ppset->type )
    {
      case 6:
        v5 = ppset->w[1];
        ppset->w[5] = ppset->w[4] + ppset->w[2];
        v6 = ppset->prcs[1].pfnGetNext(a1: ppset->prcs[1].pdata, a2: v5);
        v7 = ppset->w[3];
        ppset->w[2] = v6;
        v8 = ppset->prcs[3].pfnGetNext(a1: ppset->prcs[3].pdata, a2: v7);
        v9 = ppset->w[0];
        ppset->w[4] = v8;
        v10 = ppset->prcs[0].pfnGetNext(a1: ppset->prcs[0].pdata, a2: v9);
        v11 = ppset->w[0];
        ppset->w[1] = v10;
        ppset->w[3] = ppset->prcs[2].pfnGetNext(a1: ppset->prcs[2].pdata, a2: v11);
        result = ppset->w[5];
        break;
      case 7:
        v12 = ppset->w[1];
        ppset->w[5] = ppset->w[4] + ppset->w[2];
        ppset->w[2] = ppset->prcs[1].pfnGetNext(a1: ppset->prcs[1].pdata, a2: v12);
        ppset->w[4] = ppset->prcs[3].pfnGetNext(a1: ppset->prcs[3].pdata, a2: ppset->w[3]);
        ppset->w[1] = ppset->prcs[0].pfnGetNext(a1: ppset->prcs[0].pdata, a2: ppset->w[0]);
        ppset->w[3] = ppset->prcs[2].pfnGetNext(a1: ppset->prcs[2].pdata, a2: ppset->w[0]);
        result = ppset->prcs[4].pfnGetNext(a1: ppset->prcs[4].pdata, a2: ppset->w[5]);
        break;
      case 8:
        v13 = ppset->w[5];
        ppset->w[2] = ppset->w[1] + ppset->w[6];
        v14 = ppset->prcs[4].pfnGetNext(a1: ppset->prcs[4].pdata, a2: v13);
        v15 = ppset->w[4];
        ppset->w[6] = v14;
        v16 = ppset->prcs[3].pfnGetNext(a1: ppset->prcs[3].pdata, a2: v15);
        v17 = ppset->w[3];
        ppset->w[5] = v16;
        v18 = ppset->prcs[2].pfnGetNext(a1: ppset->prcs[2].pdata, a2: v17);
        v19 = ppset->w[2];
        ppset->w[4] = v18;
        v20 = ppset->prcs[1].pfnGetNext(a1: ppset->prcs[1].pdata, a2: v19);
        v21 = ppset->w[0];
        ppset->w[3] = v20;
        ppset->w[1] = ppset->prcs[0].pfnGetNext(a1: ppset->prcs[0].pdata, a2: v21);
        result = ppset->w[4];
        break;
      case 9:
        v22 = ppset->w[3];
        ppset->w[1] = x + ppset->w[4];
        v23 = ppset->prcs[2].pfnGetNext(a1: ppset->prcs[2].pdata, a2: v22);
        v24 = ppset->w[2];
        ppset->w[4] = v23;
        v25 = ppset->prcs[1].pfnGetNext(a1: ppset->prcs[1].pdata, a2: v24);
        v26 = ppset->w[1];
        ppset->w[3] = v25;
        result = ppset->prcs[0].pfnGetNext(a1: ppset->prcs[0].pdata, a2: v26);
        ppset->w[2] = result;
        break;
      case 0xA:
        v27 = ppset->w[2];
        ppset->w[1] = x + ppset->w[4];
        ppset->w[5] = ppset->prcs[3].pfnGetNext(a1: ppset->prcs[3].pdata, a2: v27);
        ppset->w[4] = ppset->prcs[2].pfnGetNext(a1: ppset->prcs[2].pdata, a2: ppset->w[3]);
        ppset->w[3] = ppset->prcs[1].pfnGetNext(a1: ppset->prcs[1].pdata, a2: ppset->w[2]);
        result = ppset->prcs[0].pfnGetNext(a1: ppset->prcs[0].pdata, a2: ppset->w[1]);
        ppset->w[2] = result;
        break;
      case 0xB:
        ppset->w[4] = ppset->prcs[3].pfnGetNext(a1: ppset->prcs[3].pdata, a2: ppset->w[3]);
        v28 = ppset->prcs[2].pfnGetNext(a1: ppset->prcs[2].pdata, a2: ppset->w[1]);
        v29 = _mm_cvtsi32_si128(ppset->w[2]);
        ppset->w[3] = v28;
        ((void (__cdecl *)(void *, _DWORD))ppset->prcs[2].pfnMod)(
          a1: ppset->prcs[2].pdata,
          a2: _mm_cvtepi32_ps(v29).m128_f32[0] * 0.00024414062);
        v30 = ppset->prcs[0].pfnGetNext(a1: ppset->prcs[0].pdata, a2: ppset->w[0]);
        v31 = ppset->w[0];
        ppset->w[2] = v30;
        ppset->w[1] = ppset->prcs[1].pfnGetNext(a1: ppset->prcs[1].pdata, a2: v31);
        result = ppset->w[4];
        break;
      case 0xC:
        ((void (__cdecl *)(void *, _DWORD))ppset->prcs[1].pfnMod)(
          a1: ppset->prcs[1].pdata,
          a2: (float)ppset->w[1] * 0.00024414062);
        v32 = ppset->prcs[0].pfnGetNext(a1: ppset->prcs[0].pdata, a2: ppset->w[0]);
        v33 = ppset->w[0];
        ppset->w[1] = v32;
        result = ppset->prcs[1].pfnGetNext(a1: ppset->prcs[1].pdata, a2: v33);
        ppset->w[2] = result;
        break;
      case 0xD:
        v34 = ppset->prcs[2].pfnGetNext(a1: ppset->prcs[2].pdata, a2: ppset->w[2]);
        v35 = _mm_cvtsi32_si128(ppset->w[1]);
        ppset->w[3] = v34;
        ((void (__cdecl *)(void *, _DWORD))ppset->prcs[1].pfnMod)(
          a1: ppset->prcs[1].pdata,
          a2: _mm_cvtepi32_ps(v35).m128_f32[0] * 0.00024414062);
        ppset->w[1] = ppset->prcs[0].pfnGetNext(a1: ppset->prcs[0].pdata, a2: ppset->w[0]);
        result = ppset->prcs[1].pfnGetNext(a1: ppset->prcs[1].pdata, a2: ppset->w[0]);
        ppset->w[2] = result;
        break;
      default:
        ppset->w[3] = ppset->w[1] + ppset->w[2];
        v36 = ppset->prcs[0].pfnGetNext(a1: ppset->prcs[0].pdata, a2: x);
        v37 = ppset->w[0];
        ppset->w[1] = v36;
        ppset->w[2] = ppset->prcs[1].pfnGetNext(a1: ppset->prcs[1].pdata, a2: v37);
        result = ppset->w[3];
        break;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100235B0
// Name: void DSP_Free(int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DSP_Free(dsp_t *idsp)
{
  dsp_t *v1; // eax
  int v2; // ebx
  pset_t **ppsetprev; // edi
  int v4; // esi
  pset_t *v5; // esi
  dsp_t *pdsp; // [esp+8h] [ebp+8h]

  if ( (unsigned int)idsp <= 0x1F )
  {
    v1 = &dsps[(_DWORD)idsp];
    v2 = 0;
    pdsp = v1;
    if ( v1->cchan > 0 )
    {
      ppsetprev = v1->ppsetprev;
      do
      {
        v4 = (int)*(ppsetprev - 6);
        if ( v4 != 0 )
        {
          PRC_FreeAll(prcs: (prc_t *)(v4 + 8), count: *(_DWORD *)(v4 + 4));
          _V_memset(dest: (void *)v4, fill: 0, count: 536);
        }
        v5 = *ppsetprev;
        if ( *ppsetprev != nullptr )
        {
          PRC_FreeAll(prcs: v5->prcs, count: v5->cprcs);
          _V_memset(dest: v5, fill: 0, count: 536);
        }
        ++v2;
        ++ppsetprev;
      }
      while ( v2 < pdsp->cchan );
      v1 = pdsp;
    }
    _V_memset(dest: v1, fill: 0, count: 116);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10023640
// Name: _DSP_FreeAll
// Source: json
//------------------------------------------------------------------------------
void DSP_FreeAll()
{
  int i; // esi
  amp_t *v1; // esi
  efo_t *v2; // esi
  env_t *v3; // esi
  lfo_t *v4; // esi

  for ( i = 0; i < 32; ++i )
    DSP_Free(idsp: (dsp_t *)i);
  v1 = amps;
  do
  {
    if ( v1 != nullptr )
      _V_memset(dest: v1, fill: 0, count: 92);
    ++v1;
  }
  while ( (int)v1 < (int)crss );
  MDY_FreeAll();
  v2 = efos;
  do
  {
    if ( v2 != nullptr )
      _V_memset(dest: v2, fill: 0, count: 116);
    ++v2;
  }
  while ( (int)v2 < (int)envs );
  v3 = envs;
  do
  {
    if ( v3 != nullptr )
      _V_memset(dest: v3, fill: 0, count: 184);
    ++v3;
  }
  while ( (int)v3 < (int)ptcs );
  PTC_FreeAll();
  CRS_FreeAll();
  v4 = lfos;
  do
  {
    if ( v4 != nullptr )
      _V_memset(dest: v4, fill: 0, count: 56);
    ++v4;
  }
  while ( (int)v4 < (int)lfowavs );
  LFOWAV_FreeAll();
  RVA_FreeAll();
  DLY_FreeAll();
  FLT_FreeAll();
}

//------------------------------------------------------------------------------
// Address: 0x10023710
// Name: void DSP_ChangePresetValue(int,int,int,float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DSP_ChangePresetValue(unsigned int idsp, int channel, int iproc, float value)
{
  pset_t *v4; // ecx
  char *v5; // eax
  void (__cdecl *v6)(_DWORD, _DWORD); // ecx

  if ( idsp <= 0x1F && channel < 5 && iproc < 5 )
  {
    v4 = dsps[idsp].ppset[channel];
    if ( v4 != nullptr )
    {
      v5 = (char *)v4 + 92 * iproc;
      v6 = *((void (__cdecl **)(_DWORD, _DWORD))v5 + 23);
      if ( v6 != nullptr )
        v6(a1: *((_DWORD *)v5 + 24), a2: LODWORD(value));
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10023760
// Name: void DSP_Print(struct dsp_t const __near &,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DSP_Print(const dsp_t *dsp, int nIndentation)
{
  char *IndentationText; // edi
  const char *v3; // eax
  const char *v4; // eax
  const pset_t *v5; // ebx
  int v6; // ebx
  const char *v7; // eax
  int v8; // ecx
  rmp_t *p_xramp; // ebx
  const char *v10; // edi
  pos_one_t *p_ps; // ebx
  int v12; // ecx
  int v13; // ecx
  const char *v14; // edi
  pset_t **ppset; // [esp+14h] [ebp-8h]
  pset_t **ppsetprev; // [esp+14h] [ebp-8h]
  pset_t *pPreset; // [esp+18h] [ebp-4h]
  pset_t *pPreseta; // [esp+18h] [ebp-4h]
  const dsp_t *dspa; // [esp+24h] [ebp+8h]

  IndentationText = GetIndentationText(nIndentation);
  DevMsg(a1: "%sDSP: %08x [Addr]\n", IndentationText, dsp);
  v3 = "True";
  if ( !dsp->fused )
    v3 = "False";
  DevMsg(a1: "%sfused: %s\n", IndentationText, v3);
  v4 = "True";
  if ( !dsp->bEnabled )
    v4 = "False";
  DevMsg(a1: "%sbEnabled: %s\n", IndentationText, v4);
  DevMsg(a1: "%scchan: %d\n", IndentationText, dsp->cchan);
  DevMsg(a1: "%sCurrent preset: %d\n", IndentationText, dsp->ipset);
  pPreset = nullptr;
  ppset = dsp->ppset;
  do
  {
    v5 = *ppset;
    DevMsg(a1: "%sPSET[%d]: ", IndentationText, pPreset);
    if ( v5 != nullptr )
      PSET_Print(pset: v5, nIndentation: nIndentation + 1);
    else
      DevMsg(a1: "None\n");
    ++ppset;
    pPreset = (pset_t *)((char *)pPreset + 1);
  }
  while ( (int)pPreset < 5 );
  DevMsg(a1: "%sPrevious preset: %d\n", IndentationText, dsp->ipsetprev);
  v6 = 0;
  ppsetprev = dsp->ppsetprev;
  do
  {
    pPreseta = *ppsetprev;
    DevMsg(a1: "%sPSET[%d]: ", IndentationText, v6);
    if ( pPreseta != nullptr )
      PSET_Print(pset: pPreseta, nIndentation: nIndentation + 1);
    else
      DevMsg(a1: "None\n");
    ++ppsetprev;
    ++v6;
  }
  while ( v6 < 5 );
  DevMsg(a1: "%sxfade: %f\n", IndentationText, dsp->xfade);
  DevMsg(a1: "%sxfade default: %f\n", IndentationText, dsp->xfade_default);
  v7 = "True";
  if ( !dsp->bexpfade )
    v7 = "False";
  DevMsg(a1: "%sbexpfade: %s\n", IndentationText, v7);
  v8 = nIndentation + 1;
  p_xramp = &dsp->xramp;
  if ( sFirstTime )
  {
    strcpy(sIndentationBuffer, "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t");
    sFirstTime = false;
  }
  if ( v8 > 32 )
    v8 = 32;
  v10 = &byte_1045F364[-v8];
  DevMsg(a1: "%sRmp: %08X [Addr]\n", &byte_1045F364[-v8], p_xramp);
  DevMsg(a1: "%sinitval: %d\n", v10, p_xramp->initval);
  DevMsg(a1: "%starget: %d\n", v10, dsp->xramp.target);
  DevMsg(a1: "%ssign: %d\n", v10, dsp->xramp.sign);
  DevMsg(a1: "%sfhitend: %d\n", v10, dsp->xramp.fhitend);
  DevMsg(a1: "%sbEndAtTime: %d\n", v10, dsp->xramp.bEndAtTime);
  p_ps = &dsp->xramp.ps;
  v12 = nIndentation + 2;
  if ( sFirstTime )
  {
    strcpy(sIndentationBuffer, "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t");
    sFirstTime = false;
  }
  if ( nIndentation + 2 > 32 )
    v12 = 32;
  dspa = (const dsp_t *)&byte_1045F364[-v12];
  DevMsg(a1: "%sPosOne: %08X [Addr]\n", &byte_1045F364[-v12], p_ps);
  v13 = nIndentation + 3;
  if ( sFirstTime )
  {
    strcpy(sIndentationBuffer, "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t");
    sFirstTime = false;
  }
  if ( v13 > 32 )
    v13 = 32;
  v14 = &byte_1045F364[-v13];
  DevMsg(a1: "%sPos: %08X [Addr]\n", &byte_1045F364[-v13], p_ps);
  DevMsg(a1: "%sstep: %d\n", v14, p_ps->p.step);
  DevMsg(a1: "%scstep: %d\n", v14, p_ps->p.cstep);
  DevMsg(a1: "%spos: %d\n", v14, p_ps->p.pos);
  DevMsg(a1: "%sD: %d\n", v14, p_ps->p.D);
  DevMsg(a1: "%sfhitend: %d\n", (const char *)&dspa->fused, p_ps->fhitend);
}

//------------------------------------------------------------------------------
// Address: 0x10023A90
// Name: void DSP_SetDspAuto(int)
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __cdecl DSP_SetDspAuto(int dsp_preset)
{
  CLoaderMemAlloc::CrtIsValidPointer(this: (ConVar *)&dsp_automatic.IConVar, value: dsp_preset);
}

//------------------------------------------------------------------------------
// Address: 0x10023AB0
// Name: void ADSP_GetSize(struct adsp_auto_params_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ADSP_GetSize(adsp_auto_params_t *pa)
{
  double length; // st7
  BOOL v2; // edi
  BOOL v3; // esi
  BOOL v4; // edx
  BOOL v5; // eax
  double v6; // st6
  double v7; // st7
  BOOL v8; // edi
  double v9; // st5
  double v10; // st6
  BOOL v11; // esi
  double v12; // st4
  double v13; // st5
  BOOL v14; // edx
  BOOL v15; // eax
  double width; // st3
  double v17; // st4
  double v18; // st4
  double v19; // st7
  int v20; // edi
  double v21; // rt1
  double v22; // st5
  double v23; // st6
  int v24; // esi
  double v25; // rt1
  BOOL v26; // edx
  int v27; // ebx
  int height; // edx
  double v29; // st6
  BOOL v30; // edi
  BOOL v31; // esi
  BOOL v32; // edx
  double freflectivity; // st7
  float v34; // xmm1_4
  BOOL v35; // esi
  BOOL v36; // edx
  double fdiffusion; // st6
  BOOL v38; // esi
  BOOL v39; // edx
  int shape; // eax
  int v41; // [esp+Ch] [ebp-4h]

  length = (double)pa->length;
  v2 = length > 120.0 && length <= 240.0;
  v3 = length > 240.0 && length <= 480.0;
  v4 = length > 480.0 && length <= 1200.0;
  v5 = length > 1200.0;
  v6 = length;
  v7 = 144.0;
  pa->size = v4 + v2 + 2 * v4 + 2 * (v3 + 2 * v5);
  v8 = v6 > 144.0 && v6 <= 288.0;
  v9 = v6;
  v10 = 288.0;
  v11 = v9 > 288.0 && v9 <= 576.0;
  v12 = v9;
  v13 = 576.0;
  v14 = v12 > 576.0 && v12 <= 1152.0;
  v15 = v12 > 1152.0;
  width = (double)pa->width;
  v17 = width;
  v41 = v14 + v8 + 2 * v14 + 2 * (v11 + 2 * v15);
  pa->len = v41;
  if ( width > 72.0 )
  {
    v18 = 144.0;
    v19 = width;
    if ( width <= 144.0 )
    {
      v20 = 1;
      goto LABEL_30;
    }
    v17 = width;
    v7 = 144.0;
  }
  v20 = 0;
  v21 = v17;
  v18 = v7;
  v19 = v21;
LABEL_30:
  if ( v19 <= v18 )
  {
LABEL_34:
    v24 = 0;
    v25 = v13;
    v22 = v10;
    v23 = v25;
    goto LABEL_35;
  }
  v22 = 288.0;
  v23 = 576.0;
  if ( v19 > 288.0 )
  {
    v13 = 576.0;
    v10 = 288.0;
    goto LABEL_34;
  }
  v24 = 1;
LABEL_35:
  v26 = v19 > v22 && v23 >= v19;
  v27 = v26 + v20 + 2 * v26 + 2 * (v24 + 2 * (v19 > v23));
  height = pa->height;
  v29 = (double)height;
  pa->wid = v27;
  v30 = v29 > 48.0 && height <= 128;
  v31 = height > 128 && v29 <= 216.0;
  v32 = v29 > 216.0 && v29 <= 384.0;
  freflectivity = pa->freflectivity;
  v34 = pa->freflectivity;
  pa->ht = v32 + v30 + 2 * v32 + 2 * (v31 + 2 * (v29 > 384.0));
  v35 = freflectivity > 0.04 && v34 <= 0.5;
  v36 = v34 > 0.5 && freflectivity <= 0.8;
  fdiffusion = pa->fdiffusion;
  pa->reflectivity = (freflectivity > 0.8) + v35 + 2 * (freflectivity > 0.8) + 2 * v36;
  v38 = fdiffusion > 0.01 && fdiffusion <= 0.1;
  v39 = fdiffusion > 0.1 && fdiffusion <= 0.3;
  shape = pa->shape;
  pa->diffusion = (fdiffusion > 0.3) + v38 + 2 * (fdiffusion > 0.3) + 2 * v39;
  if ( shape != 6 && shape != 10 )
  {
    if ( shape == 4 || shape == 5 )
      pa->size = v27;
    else
      pa->size = (v27 + v41) / 2;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10023D90
// Name: void ADSP_InterpParam(struct pset_t __near *,struct pset_t __near *,struct pset_t __near *,int,int,int,int,int,bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ADSP_InterpParam(
        pset_t *pnew,
        pset_t *pmin,
        pset_t *pmax,
        int proc_type,
        int skipprocs,
        int iparam,
        int index,
        int index_max,
        bool bexp)
{
  int cprcs; // ecx
  int v10; // edi
  int v11; // eax
  int v12; // esi
  prc_t *prcs; // edx
  int v14; // edx
  int v15; // ecx
  int v16; // eax
  int v17; // esi
  prc_t *v18; // edx
  int v19; // esi
  int v20; // ecx
  int v21; // eax
  prc_t *v22; // edx
  float v23; // xmm2_4
  float v24; // xmm1_4
  float v25; // xmm0_4
  int iproc_new; // [esp+24h] [ebp+18h]

  cprcs = pnew->cprcs;
  v10 = skipprocs;
  v11 = 0;
  v12 = skipprocs;
  if ( cprcs <= 0 )
  {
LABEL_7:
    v14 = -1;
    iproc_new = -1;
    goto LABEL_8;
  }
  prcs = pnew->prcs;
  while ( prcs->type != proc_type )
  {
LABEL_6:
    ++v11;
    ++prcs;
    if ( v11 >= cprcs )
      goto LABEL_7;
  }
  if ( v12 != 0 )
  {
    --v12;
    goto LABEL_6;
  }
  v14 = v11;
  iproc_new = v11;
LABEL_8:
  v15 = pmin->cprcs;
  v16 = 0;
  v17 = v10;
  if ( v15 <= 0 )
  {
LABEL_15:
    v19 = -1;
    goto LABEL_16;
  }
  v18 = pmin->prcs;
  while ( 2 )
  {
    if ( v18->type != proc_type )
    {
LABEL_13:
      ++v16;
      ++v18;
      if ( v16 >= v15 )
      {
        v14 = iproc_new;
        goto LABEL_15;
      }
      continue;
    }
    break;
  }
  if ( v17 != 0 )
  {
    --v17;
    goto LABEL_13;
  }
  v14 = iproc_new;
  v19 = v16;
LABEL_16:
  v20 = pmax->cprcs;
  v21 = 0;
  if ( v20 > 0 )
  {
    v22 = pmax->prcs;
    while ( 1 )
    {
      if ( v22->type == proc_type )
      {
        if ( v10 == 0 )
        {
          v14 = iproc_new;
          goto LABEL_24;
        }
        --v10;
      }
      ++v21;
      ++v22;
      if ( v21 >= v20 )
      {
        v14 = iproc_new;
        break;
      }
    }
  }
  v21 = -1;
LABEL_24:
  if ( v14 >= 0 && v19 >= 0 && v21 >= 0 )
  {
    v23 = pmin->prcs[v19].prm[iparam];
    v24 = (float)index / (float)index_max;
    v25 = (float)(pmax->prcs[v21].prm[iparam] - v23) * v24;
    if ( bexp )
      v25 = v25 * v24;
    pnew->prcs[v14].prm[iparam] = v25 + v23;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10023EB0
// Name: void ADSP_SetParam(struct pset_t __near *,int,int,int,float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ADSP_SetParam(pset_t *pnew, int proc_type, int skipprocs, int iparam, float value)
{
  int cprcs; // ecx
  int v7; // eax
  prc_t *prcs; // edx

  cprcs = pnew->cprcs;
  v7 = 0;
  if ( cprcs > 0 )
  {
    prcs = pnew->prcs;
    do
    {
      if ( prcs->type == proc_type )
      {
        if ( skipprocs == 0 )
        {
          if ( v7 >= 0 )
            pnew->prcs[v7].prm[iparam] = value;
          return;
        }
        --skipprocs;
      }
      ++v7;
      ++prcs;
    }
    while ( v7 < cprcs );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10023F00
// Name: void ADSP_SetParamIfNegative(struct pset_t __near *,struct pset_t __near *,struct pset_t __near *,int,int,int,int,int,bool,float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ADSP_SetParamIfNegative(
        pset_t *pnew,
        pset_t *pmin,
        pset_t *pmax,
        int proc_type,
        int skipprocs,
        int iparam,
        int index,
        int index_max,
        bool bexp,
        float value)
{
  int cprcs; // ecx
  int v11; // eax
  int v12; // esi
  prc_t *prcs; // edx
  int v14; // edx
  int v15; // ecx
  int v16; // edi
  prc_t *v17; // esi
  int v18; // edi
  int v19; // edx
  int v20; // ecx
  prc_t *v21; // esi
  int iproc_min; // [esp+10h] [ebp-8h]
  int iproc_new; // [esp+14h] [ebp-4h]

  cprcs = pnew->cprcs;
  v11 = 0;
  v12 = skipprocs;
  if ( cprcs <= 0 )
  {
LABEL_7:
    iproc_new = -1;
    goto LABEL_8;
  }
  prcs = pnew->prcs;
  while ( prcs->type != proc_type )
  {
LABEL_6:
    ++v11;
    ++prcs;
    if ( v11 >= cprcs )
      goto LABEL_7;
  }
  if ( v12 != 0 )
  {
    --v12;
    goto LABEL_6;
  }
  iproc_new = v11;
LABEL_8:
  v14 = pmin->cprcs;
  v15 = 0;
  v16 = skipprocs;
  if ( v14 <= 0 )
  {
LABEL_14:
    iproc_min = -1;
    goto LABEL_15;
  }
  v17 = pmin->prcs;
  while ( 2 )
  {
    if ( v17->type != proc_type )
    {
LABEL_13:
      ++v15;
      ++v17;
      if ( v15 >= v14 )
        goto LABEL_14;
      continue;
    }
    break;
  }
  if ( v16 != 0 )
  {
    --v16;
    goto LABEL_13;
  }
  iproc_min = v15;
LABEL_15:
  v18 = skipprocs;
  v19 = pmax->cprcs;
  v20 = 0;
  if ( v19 > 0 )
  {
    v21 = pmax->prcs;
    do
    {
      if ( v21->type == proc_type )
      {
        if ( v18 == 0 )
          goto LABEL_22;
        --v18;
      }
      ++v20;
      ++v21;
    }
    while ( v20 < v19 );
  }
  v20 = -1;
LABEL_22:
  if ( iproc_new >= 0 && iproc_min >= 0 && v20 >= 0 )
  {
    if ( pmin->prcs[iproc_min].prm[iparam] < 0.0 || pmax->prcs[v20].prm[iparam] < 0.0 )
      ADSP_SetParam(pnew, proc_type, skipprocs, iparam, value);
    else
      ADSP_InterpParam(pnew, pmin, pmax, proc_type, skipprocs, iparam, index, index_max, bexp);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10024040
// Name: bool FBatchPreset(struct pset_t __near *)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl FBatchPreset(pset_t *ppset)
{
  return ppset->type < 2u;
}

//------------------------------------------------------------------------------
// Address: 0x10024060
// Name: void DSP_ProcessStereoToMono(struct dsp_t __near *,struct portable_samplepair_t __near *,struct portable_samplepair_t __near *,int,bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DSP_ProcessStereoToMono(
        dsp_t *pdsp,
        portable_samplepair_t *pbfront,
        portable_samplepair_t *pbrear,
        int sampleCount,
        bool bcrossfading)
{
  portable_samplepair_t *v5; // ebx
  int v6; // esi
  int v7; // eax
  int v8; // eax
  dsp_t *v9; // ecx
  int v10; // edi
  int Next; // esi
  int v12; // edi
  int v13; // eax
  int v14; // esi
  int v15; // esi
  int left; // edi
  int right; // esi
  int v18; // eax
  dsp_t *v19; // ecx
  int v20; // eax
  int v21; // eax
  int v22; // edi
  int v23; // edi
  int v24; // ecx
  int v25; // esi
  int frp; // [esp+Ch] [ebp-4h]
  int count; // [esp+1Ch] [ebp+Ch]
  int counta; // [esp+1Ch] [ebp+Ch]
  int flp; // [esp+24h] [ebp+14h]
  int flpa; // [esp+24h] [ebp+14h]
  bool bexp; // [esp+2Bh] [ebp+1Bh]

  v5 = pbfront;
  v6 = sampleCount;
  if ( bcrossfading )
  {
    v9 = pdsp;
    bexp = pdsp->bexpfade;
    if ( pdsp->ipset != 0 && pdsp->ipsetprev != 0 )
    {
      if ( sampleCount != 0 )
      {
        while ( 1 )
        {
          v10 = (v5->right + v5->left) >> 1;
          count = v6 - 1;
          Next = PSET_GetNext(ppset: v9->ppset[0], x: v10);
          v12 = PSET_GetNext(ppset: pdsp->ppsetprev[0], x: v10);
          v13 = RMP_GetNext(prmp: &pdsp->xramp);
          v14 = (v13 * (Next - v12)) >> 12;
          if ( bexp )
            v14 = (v13 * v14) >> 12;
          v15 = v12 + v14;
          v5->left = v15;
          v5->right = v15;
          ++v5;
          if ( count == 0 )
            break;
          v9 = pdsp;
          v6 = count;
        }
      }
    }
    else if ( sampleCount != 0 )
    {
      while ( 1 )
      {
        left = v5->left;
        counta = v6 - 1;
        right = v5->right;
        v18 = (v5->left + right) >> 1;
        flp = v18;
        if ( v9->ipset != 0 )
        {
          right = PSET_GetNext(ppset: v9->ppset[0], x: (left + right) >> 1);
          v18 = flp;
          left = right;
        }
        v19 = pdsp;
        if ( pdsp->ipsetprev != 0 )
        {
          v20 = PSET_GetNext(ppset: pdsp->ppsetprev[0], x: v18);
          v19 = pdsp;
          frp = v20;
        }
        else
        {
          v20 = v5->left;
          frp = v5->right;
        }
        flpa = v20;
        v21 = RMP_GetNext(prmp: &v19->xramp);
        v22 = (v21 * (left - flpa)) >> 12;
        if ( bexp )
        {
          v23 = flpa + ((v21 * v22) >> 12);
          v24 = frp;
          v25 = (v21 * (right - frp)) >> 12;
        }
        else
        {
          v23 = flpa + v22;
          v24 = frp;
          v25 = right - frp;
        }
        v5->left = v23;
        v5->right = v24 + ((v21 * v25) >> 12);
        ++v5;
        if ( counta == 0 )
          break;
        v9 = pdsp;
        v6 = counta;
      }
    }
  }
  else if ( pdsp->ipset != 0 )
  {
    if ( pdsp->ppset[0]->type > 1u )
    {
      if ( sampleCount != 0 )
      {
        do
        {
          v8 = PSET_GetNext(ppset: pdsp->ppset[0], x: (v5->right + v5->left) >> 1);
          v5->right = v8;
          v5->left = v8;
          ++v5;
          --v6;
        }
        while ( v6 != 0 );
      }
    }
    else
    {
      if ( sampleCount != 0 )
      {
        do
        {
          v7 = v5->left + v5->right;
          ++v5;
          --v6;
          v5[-1].left = v7 >> 1;
        }
        while ( v6 != 0 );
      }
      PSET_GetNextN(ppset: pdsp->ppset[0], pbuffer: pbfront, SampleCount: sampleCount, op: 2);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10024240
// Name: void DSP_ProcessStereoToStereo(struct dsp_t __near *,struct portable_samplepair_t __near *,struct portable_samplepair_t __near *,int,bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DSP_ProcessStereoToStereo(
        dsp_t *pdsp,
        portable_samplepair_t *pbfront,
        portable_samplepair_t *pbrear,
        int sampleCount,
        bool bcrossfading)
{
  portable_samplepair_t *v5; // ebx
  int v6; // edi
  pset_t *v7; // ecx
  int v8; // eax
  int Next; // esi
  int v10; // edi
  int v11; // eax
  int v12; // esi
  int v13; // esi
  int v14; // ecx
  int v15; // edi
  int count; // [esp+Ch] [ebp-4h]
  int flp; // [esp+1Ch] [ebp+Ch]
  int frp; // [esp+24h] [ebp+14h]
  int bexp; // [esp+28h] [ebp+18h]
  bool bexp_3; // [esp+2Bh] [ebp+1Bh]

  v5 = pbfront;
  v6 = sampleCount;
  if ( bcrossfading )
  {
    bexp_3 = pdsp->bexpfade;
    if ( sampleCount != 0 )
    {
      while ( 1 )
      {
        count = v6 - 1;
        Next = PSET_GetNext(ppset: pdsp->ppset[0], x: v5->left);
        v10 = PSET_GetNext(ppset: pdsp->ppset[1], x: v5->right);
        flp = PSET_GetNext(ppset: pdsp->ppsetprev[0], x: v5->left);
        frp = PSET_GetNext(ppset: pdsp->ppsetprev[1], x: v5->right);
        v11 = RMP_GetNext(prmp: &pdsp->xramp);
        v12 = (v11 * (Next - flp)) >> 12;
        if ( bexp_3 )
        {
          v13 = flp + ((v11 * v12) >> 12);
          v14 = frp;
          v15 = (v11 * (v10 - frp)) >> 12;
        }
        else
        {
          v13 = flp + v12;
          v14 = frp;
          v15 = v10 - frp;
        }
        v5->left = v13;
        v5->right = v14 + ((v11 * v15) >> 12);
        ++v5;
        if ( count == 0 )
          break;
        v6 = count;
      }
    }
  }
  else if ( pdsp->ipset != 0 )
  {
    v7 = pdsp->ppset[0];
    if ( v7->type > 1u || pdsp->ppset[1]->type > 1u )
    {
      if ( sampleCount != 0 )
      {
        do
        {
          bexp = PSET_GetNext(ppset: pdsp->ppset[0], x: v5->left);
          v8 = PSET_GetNext(ppset: pdsp->ppset[1], x: v5->right);
          v5->left = bexp;
          v5->right = v8;
          ++v5;
          --v6;
        }
        while ( v6 != 0 );
      }
    }
    else
    {
      PSET_GetNextN(ppset: v7, pbuffer: pbfront, SampleCount: sampleCount, op: 0);
      PSET_GetNextN(ppset: pdsp->ppset[1], pbuffer: pbfront, SampleCount: sampleCount, op: 1);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100243A0
// Name: void DSP_ProcessQuadToMono(struct dsp_t __near *,struct portable_samplepair_t __near *,struct portable_samplepair_t __near *,int,bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DSP_ProcessQuadToMono(
        dsp_t *pdsp,
        portable_samplepair_t *pbfront,
        portable_samplepair_t *pbrear,
        int sampleCount,
        bool bcrossfading)
{
  portable_samplepair_t *v5; // eax
  int v6; // edi
  dsp_t *v7; // edx
  int v8; // edx
  int v9; // edx
  portable_samplepair_t *v10; // ecx
  int *v11; // eax
  portable_samplepair_t *v12; // ebx
  int *v13; // esi
  int v14; // ecx
  int v15; // eax
  int v16; // eax
  int *p_right; // ebx
  int v18; // esi
  int Next; // edi
  int v20; // esi
  int v21; // eax
  int v22; // edi
  int v23; // edi
  int *v24; // ecx
  int v25; // eax
  int v26; // edx
  int left; // ebx
  int v28; // esi
  int v29; // eax
  int v30; // eax
  int v31; // edi
  dsp_t *v32; // edx
  int v33; // eax
  int v34; // eax
  int v35; // edi
  int v36; // edi
  int v37; // esi
  int v38; // ebx
  int v39; // ecx
  int rrp; // [esp+Ch] [ebp-18h]
  int rrpa; // [esp+Ch] [ebp-18h]
  int rr; // [esp+10h] [ebp-14h]
  int rlp; // [esp+14h] [ebp-10h]
  int frp; // [esp+18h] [ebp-Ch]
  int flp; // [esp+1Ch] [ebp-8h]
  portable_samplepair_t *v46; // [esp+20h] [ebp-4h]
  int count; // [esp+30h] [ebp+Ch]
  int counta; // [esp+30h] [ebp+Ch]
  portable_samplepair_t *pbreara; // [esp+34h] [ebp+10h]
  portable_samplepair_t *pbrearb; // [esp+34h] [ebp+10h]
  portable_samplepair_t *pbrearc; // [esp+34h] [ebp+10h]
  portable_samplepair_t *sampleCounta; // [esp+38h] [ebp+14h]
  int *sampleCountb; // [esp+38h] [ebp+14h]
  bool bexp; // [esp+3Fh] [ebp+1Bh]

  v5 = pbfront;
  v6 = sampleCount;
  if ( bcrossfading )
  {
    bexp = pdsp->bexpfade;
    if ( pdsp->ipset != 0 && pdsp->ipsetprev != 0 )
    {
      if ( sampleCount != 0 )
      {
        sampleCounta = pbrear;
        v16 = (char *)pbrear - (char *)pbfront;
        p_right = &pbfront->right;
        for ( pbrearb = (portable_samplepair_t *)((char *)pbrear - (char *)pbfront); ; v16 = (int)pbrearb )
        {
          v18 = (*p_right + *(int *)((char *)p_right + v16) + *(p_right - 1) + sampleCounta->left) >> 2;
          count = v6 - 1;
          Next = PSET_GetNext(ppset: pdsp->ppset[0], x: v18);
          v20 = PSET_GetNext(ppset: pdsp->ppsetprev[0], x: v18);
          v21 = RMP_GetNext(prmp: &pdsp->xramp);
          v22 = (v21 * (Next - v20)) >> 12;
          if ( bexp )
            v22 = (v21 * v22) >> 12;
          v23 = v20 + v22;
          *(p_right - 1) = v23;
          *p_right = v23;
          sampleCounta->left = v23;
          *(int *)((char *)&pbrearb->left + (_DWORD)p_right) = v23;
          p_right += 2;
          ++sampleCounta;
          if ( count == 0 )
            break;
          v6 = count;
        }
      }
    }
    else if ( sampleCount != 0 )
    {
      v46 = pbrear;
      v24 = &pbfront->right;
      v25 = (char *)pbrear - (char *)pbfront;
      sampleCountb = &pbfront->right;
      for ( pbrearc = (portable_samplepair_t *)((char *)pbrear - (char *)pbfront); ; v25 = (int)pbrearc )
      {
        v26 = *(int *)((char *)v24 + v25);
        left = v46->left;
        v28 = *v24;
        counta = v6 - 1;
        v29 = (v46->left + v26 + *v24 + *(v24 - 1)) >> 2;
        rrp = v29;
        if ( pdsp->ipset != 0 )
        {
          v30 = PSET_GetNext(ppset: pdsp->ppset[0], x: v29);
          v24 = sampleCountb;
          v28 = v30;
          v29 = rrp;
          v31 = v28;
          rr = v28;
          left = v28;
        }
        else
        {
          v31 = *(v24 - 1);
          rr = v26;
        }
        v32 = pdsp;
        if ( pdsp->ipsetprev != 0 )
        {
          v33 = PSET_GetNext(ppset: pdsp->ppsetprev[0], x: v29);
          v32 = pdsp;
          flp = v33;
          frp = v33;
          rlp = v33;
          rrpa = v33;
        }
        else
        {
          flp = *(v24 - 1);
          frp = *v24;
          rlp = v46->left;
          rrpa = *(int *)((char *)&pbrearc->left + (_DWORD)v24);
        }
        v34 = RMP_GetNext(prmp: &v32->xramp);
        v35 = (v34 * (v31 - flp)) >> 12;
        if ( bexp )
        {
          v36 = flp + ((v34 * v35) >> 12);
          v37 = frp + ((v34 * ((v34 * (v28 - frp)) >> 12)) >> 12);
          v38 = rlp + ((v34 * ((v34 * (left - rlp)) >> 12)) >> 12);
          v39 = (v34 * (rr - rrpa)) >> 12;
        }
        else
        {
          v36 = flp + v35;
          v37 = frp + ((v34 * (v28 - frp)) >> 12);
          v38 = rlp + ((v34 * (left - rlp)) >> 12);
          v39 = rr - rrpa;
        }
        *sampleCountb = v37;
        *(sampleCountb - 1) = v36;
        v46->left = v38;
        *(int *)((char *)&pbrearc->left + (_DWORD)sampleCountb) = rrpa + ((v34 * v39) >> 12);
        sampleCountb += 2;
        ++v46;
        if ( counta == 0 )
          break;
        v24 = sampleCountb;
        v6 = counta;
      }
    }
  }
  else
  {
    v7 = pdsp;
    if ( pdsp->ipset != 0 )
    {
      if ( pdsp->ppset[0]->type > 1u )
      {
        if ( sampleCount != 0 )
        {
          v12 = pbrear;
          v13 = &pbfront->right;
          v14 = (char *)pbrear - (char *)pbfront;
          pbreara = (portable_samplepair_t *)((char *)pbrear - (char *)pbfront);
          do
          {
            v15 = PSET_GetNext(
                    ppset: pdsp->ppset[0],
                    x: (*v13 + *(int *)((char *)v13 + v14) + *(v13 - 1) + v12->left) >> 2);
            v14 = (int)pbreara;
            *v13 = v15;
            *(v13 - 1) = v15;
            *(int *)((char *)&pbreara->left + (_DWORD)v13) = v15;
            v12->left = v15;
            v13 += 2;
            ++v12;
            --v6;
          }
          while ( v6 != 0 );
        }
      }
      else
      {
        if ( sampleCount != 0 )
        {
          do
          {
            v8 = *(int *)((char *)&v5->right + (char *)pbrear - (char *)pbfront)
               + *(int *)((char *)&v5->left + (char *)pbrear - (char *)pbfront);
            ++v5;
            --v6;
            v5[-1].left = (v5[-1].right + v5[-1].left + v8) >> 2;
          }
          while ( v6 != 0 );
          v7 = pdsp;
        }
        PSET_GetNextN(ppset: v7->ppset[0], pbuffer: pbfront, SampleCount: sampleCount, op: 2);
        v9 = sampleCount;
        if ( sampleCount != 0 )
        {
          v10 = pbrear;
          v11 = &pbfront->right;
          do
          {
            v10->left = *(v11 - 1);
            *(int *)((char *)v11 + (char *)pbrear - (char *)pbfront) = *v11;
            v11 += 2;
            ++v10;
            --v9;
          }
          while ( v9 != 0 );
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100246B0
// Name: void DSP_ProcessQuadToStereo(struct dsp_t __near *,struct portable_samplepair_t __near *,struct portable_samplepair_t __near *,int,bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DSP_ProcessQuadToStereo(
        dsp_t *pdsp,
        portable_samplepair_t *pbfront,
        portable_samplepair_t *pbrear,
        int sampleCount,
        bool bcrossfading)
{
  portable_samplepair_t *v5; // eax
  int v6; // edi
  dsp_t *v7; // edx
  portable_samplepair_t *v8; // esi
  int v9; // ecx
  int v10; // esi
  int v11; // edx
  portable_samplepair_t *v12; // ecx
  int *v13; // eax
  int v14; // esi
  portable_samplepair_t *v15; // ebx
  int *v16; // esi
  int v17; // eax
  dsp_t *v18; // esi
  int *p_right; // eax
  int v20; // ecx
  int v21; // edi
  int v22; // ebx
  int Next; // esi
  int v24; // ebx
  int v25; // edi
  int v26; // eax
  int v27; // esi
  int v28; // ebx
  int v29; // ebx
  int v30; // esi
  int *v31; // ecx
  int v32; // edx
  int left; // ebx
  int v34; // eax
  int v35; // edi
  int v36; // esi
  int v37; // eax
  int v38; // edi
  dsp_t *v39; // edx
  int v40; // eax
  int v41; // eax
  int v42; // esi
  int v43; // esi
  int v44; // edi
  int v45; // ebx
  int v46; // ecx
  int avl; // [esp+Ch] [ebp-18h]
  int avla; // [esp+Ch] [ebp-18h]
  int rr; // [esp+10h] [ebp-14h]
  int rlp; // [esp+14h] [ebp-10h]
  int flp; // [esp+18h] [ebp-Ch]
  int *v52; // [esp+1Ch] [ebp-8h]
  portable_samplepair_t *v53; // [esp+1Ch] [ebp-8h]
  portable_samplepair_t *v54; // [esp+20h] [ebp-4h]
  int *v55; // [esp+20h] [ebp-4h]
  portable_samplepair_t *pbfronta; // [esp+30h] [ebp+Ch]
  portable_samplepair_t *pbfrontb; // [esp+30h] [ebp+Ch]
  portable_samplepair_t *pbfrontc; // [esp+30h] [ebp+Ch]
  int frpc; // [esp+34h] [ebp+10h]
  int frp; // [esp+34h] [ebp+10h]
  int frpa; // [esp+34h] [ebp+10h]
  int frpb; // [esp+34h] [ebp+10h]
  int count; // [esp+38h] [ebp+14h]
  int counta; // [esp+38h] [ebp+14h]
  int bexp; // [esp+3Ch] [ebp+18h]
  bool bexp_3; // [esp+3Fh] [ebp+1Bh]

  v5 = pbfront;
  v6 = sampleCount;
  if ( bcrossfading )
  {
    v18 = pdsp;
    bexp_3 = pdsp->bexpfade;
    if ( pdsp->ipset != 0 && pdsp->ipsetprev != 0 )
    {
      if ( sampleCount != 0 )
      {
        p_right = &pbfront->right;
        v54 = pbrear;
        v20 = (char *)pbrear - (char *)pbfront;
        v52 = &pbfront->right;
        for ( pbfrontb = (portable_samplepair_t *)((char *)pbrear - (char *)pbfront); ; v20 = (int)pbfrontb )
        {
          count = v6 - 1;
          v21 = (*(p_right - 1) + v54->left) >> 1;
          v22 = (*p_right + *(int *)((char *)p_right + v20)) >> 1;
          frpc = v22;
          Next = PSET_GetNext(ppset: v18->ppset[0], x: v21);
          v24 = PSET_GetNext(ppset: pdsp->ppset[1], x: v22);
          v25 = PSET_GetNext(ppset: pdsp->ppsetprev[0], x: v21);
          frp = PSET_GetNext(ppset: pdsp->ppsetprev[1], x: frpc);
          v26 = RMP_GetNext(prmp: &pdsp->xramp);
          v27 = (v26 * (Next - v25)) >> 12;
          v28 = (v26 * (v24 - frp)) >> 12;
          if ( bexp_3 )
          {
            v27 = (v26 * v27) >> 12;
            v28 = (v26 * v28) >> 12;
          }
          v29 = frp + v28;
          v30 = v25 + v27;
          *(v52 - 1) = v30;
          *v52 = v29;
          v54->left = v30;
          *(int *)((char *)&pbfrontb->left + (_DWORD)v52) = v29;
          v52 += 2;
          ++v54;
          if ( count == 0 )
            break;
          p_right = v52;
          v6 = count;
          v18 = pdsp;
        }
      }
    }
    else if ( sampleCount != 0 )
    {
      v53 = pbrear;
      v31 = &pbfront->right;
      v32 = (char *)pbrear - (char *)pbfront;
      v55 = &pbfront->right;
      pbfrontc = (portable_samplepair_t *)((char *)pbrear - (char *)pbfront);
      while ( 1 )
      {
        left = v53->left;
        counta = v6 - 1;
        rr = *(int *)((char *)v31 + v32);
        v34 = (v53->left + *(v31 - 1)) >> 1;
        v35 = (*v31 + rr) >> 1;
        avl = v34;
        frpa = v35;
        if ( v18->ipset != 0 )
        {
          v36 = PSET_GetNext(ppset: v18->ppset[0], x: v34);
          left = v36;
          v37 = PSET_GetNext(ppset: pdsp->ppset[0], x: v35);
          v31 = v55;
          v38 = v37;
          v34 = avl;
          rr = v38;
        }
        else
        {
          v36 = *(v31 - 1);
          v38 = *v31;
        }
        v39 = pdsp;
        if ( pdsp->ipsetprev != 0 )
        {
          flp = PSET_GetNext(ppset: pdsp->ppsetprev[0], x: v34);
          rlp = flp;
          v40 = PSET_GetNext(ppset: pdsp->ppsetprev[0], x: frpa);
          v39 = pdsp;
          frpb = v40;
          avla = v40;
        }
        else
        {
          flp = *(v31 - 1);
          frpb = *v31;
          rlp = v53->left;
          avla = *(int *)((char *)v31 + (_DWORD)pbfrontc);
        }
        v41 = RMP_GetNext(prmp: &v39->xramp);
        v42 = (v41 * (v36 - flp)) >> 12;
        if ( bexp_3 )
        {
          v43 = flp + ((v41 * v42) >> 12);
          v44 = frpb + ((v41 * ((v41 * (v38 - frpb)) >> 12)) >> 12);
          v45 = rlp + ((v41 * ((v41 * (left - rlp)) >> 12)) >> 12);
          v46 = (v41 * (rr - avla)) >> 12;
        }
        else
        {
          v43 = flp + v42;
          v44 = frpb + ((v41 * (v38 - frpb)) >> 12);
          v45 = rlp + ((v41 * (left - rlp)) >> 12);
          v46 = rr - avla;
        }
        *(v55 - 1) = v43;
        *v55 = v44;
        v53->left = v45;
        *(int *)((char *)v55 + (_DWORD)pbfrontc) = avla + ((v41 * v46) >> 12);
        v55 += 2;
        ++v53;
        if ( counta == 0 )
          break;
        v31 = v55;
        v6 = counta;
        v32 = (int)pbfrontc;
        v18 = pdsp;
      }
    }
  }
  else
  {
    v7 = pdsp;
    if ( pdsp->ipset != 0 )
    {
      if ( pdsp->ppset[0]->type > 1u || pdsp->ppset[1]->type > 1u )
      {
        if ( sampleCount != 0 )
        {
          v15 = pbrear;
          v16 = &pbfront->right;
          pbfronta = (portable_samplepair_t *)((char *)pbrear - (char *)pbfront);
          while ( 1 )
          {
            bexp = PSET_GetNext(ppset: v7->ppset[0], x: (v15->left + *(v16 - 1)) >> 1);
            v17 = PSET_GetNext(ppset: pdsp->ppset[1], x: (*(int *)((char *)&pbfronta->left + (_DWORD)v16) + *v16) >> 1);
            *(v16 - 1) = bexp;
            v15->left = bexp;
            *v16 = v17;
            *(int *)((char *)&pbfronta->left + (_DWORD)v16) = v17;
            v16 += 2;
            ++v15;
            if ( --v6 == 0 )
              break;
            v7 = pdsp;
          }
        }
      }
      else
      {
        v8 = pbrear;
        if ( sampleCount != 0 )
        {
          v9 = (char *)pbrear - (char *)pbfront;
          do
          {
            v10 = *(int *)((char *)&v5->left + v9) + v5->left;
            ++v5;
            v5[-1].left = v10 >> 1;
            --v6;
            v5[-1].right = (v5[-1].right + *(_DWORD *)((char *)v5 + v9 - 4)) >> 1;
          }
          while ( v6 != 0 );
          v5 = pbfront;
          v8 = pbrear;
        }
        PSET_GetNextN(ppset: pdsp->ppset[0], pbuffer: v5, SampleCount: sampleCount, op: 0);
        PSET_GetNextN(ppset: pdsp->ppset[1], pbuffer: pbfront, SampleCount: sampleCount, op: 1);
        v11 = sampleCount;
        if ( sampleCount != 0 )
        {
          v12 = v8;
          v13 = &pbfront->right;
          v14 = (char *)v8 - (char *)pbfront;
          do
          {
            v12->left = *(v13 - 1);
            *(int *)((char *)v13 + v14) = *v13;
            v13 += 2;
            ++v12;
            --v11;
          }
          while ( v11 != 0 );
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10024A80
// Name: void DSP_ProcessQuadToQuad(struct dsp_t __near *,struct portable_samplepair_t __near *,struct portable_samplepair_t __near *,int,bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DSP_ProcessQuadToQuad(
        dsp_t *pdsp,
        portable_samplepair_t *pbfront,
        portable_samplepair_t *pbrear,
        int sampleCount,
        bool bcrossfading)
{
  portable_samplepair_t *v5; // ebx
  int *v6; // esi
  int v7; // eax
  dsp_t *v8; // ebx
  int *p_right; // edi
  int v10; // eax
  int Next; // esi
  int v12; // edi
  int v13; // ebx
  int v14; // eax
  int v15; // esi
  int v16; // esi
  int v17; // edi
  int v18; // ebx
  int v19; // ecx
  int rrpa; // [esp+Ch] [ebp-18h]
  int rrp; // [esp+Ch] [ebp-18h]
  int rr; // [esp+10h] [ebp-14h]
  int rlp; // [esp+14h] [ebp-10h]
  int frp; // [esp+18h] [ebp-Ch]
  int flp; // [esp+1Ch] [ebp-8h]
  portable_samplepair_t *v26; // [esp+20h] [ebp-4h]
  portable_samplepair_t *pbfronta; // [esp+30h] [ebp+Ch]
  portable_samplepair_t *pbfrontb; // [esp+30h] [ebp+Ch]
  int fra; // [esp+34h] [ebp+10h]
  int *fr; // [esp+34h] [ebp+10h]
  int bexp; // [esp+3Ch] [ebp+18h]
  bool bexp_3; // [esp+3Fh] [ebp+1Bh]

  if ( bcrossfading )
  {
    v8 = pdsp;
    bexp_3 = pdsp->bexpfade;
    if ( sampleCount != 0 )
    {
      v26 = pbrear;
      p_right = &pbfront->right;
      v10 = (char *)pbrear - (char *)pbfront;
      fr = &pbfront->right;
      pbfrontb = (portable_samplepair_t *)v10;
      while ( 1 )
      {
        --sampleCount;
        Next = PSET_GetNext(ppset: v8->ppset[0], x: *(p_right - 1));
        v12 = PSET_GetNext(ppset: v8->ppset[1], x: *p_right);
        v13 = PSET_GetNext(ppset: v8->ppset[2], x: v26->left);
        rr = PSET_GetNext(ppset: pdsp->ppset[3], x: *(int *)((char *)&pbfrontb->left + (_DWORD)fr));
        flp = PSET_GetNext(ppset: pdsp->ppsetprev[0], x: *(fr - 1));
        frp = PSET_GetNext(ppset: pdsp->ppsetprev[1], x: *fr);
        rlp = PSET_GetNext(ppset: pdsp->ppsetprev[2], x: v26->left);
        rrp = PSET_GetNext(ppset: pdsp->ppsetprev[3], x: *(int *)((char *)&pbfrontb->left + (_DWORD)fr));
        v14 = RMP_GetNext(prmp: &pdsp->xramp);
        v15 = (v14 * (Next - flp)) >> 12;
        if ( bexp_3 )
        {
          v16 = flp + ((v14 * v15) >> 12);
          v17 = frp + ((v14 * ((v14 * (v12 - frp)) >> 12)) >> 12);
          v18 = rlp + ((v14 * ((v14 * (v13 - rlp)) >> 12)) >> 12);
          v19 = (v14 * (rr - rrp)) >> 12;
        }
        else
        {
          v16 = flp + v15;
          v17 = frp + ((v14 * (v12 - frp)) >> 12);
          v18 = rlp + ((v14 * (v13 - rlp)) >> 12);
          v19 = rr - rrp;
        }
        *(fr - 1) = v16;
        *fr = v17;
        v26->left = v18;
        *(int *)((char *)&pbfrontb->left + (_DWORD)fr) = rrp + ((v14 * v19) >> 12);
        fr += 2;
        ++v26;
        if ( sampleCount == 0 )
          break;
        p_right = fr;
        v8 = pdsp;
      }
    }
  }
  else if ( pdsp->ipset != 0 )
  {
    if ( pdsp->ppset[0]->type <= 1u
      && pdsp->ppset[1]->type <= 1u
      && pdsp->ppset[2]->type <= 1u
      && FBatchPreset(ppset: pdsp->ppset[3]) )
    {
      PSET_GetNextN(ppset: pdsp->ppset[0], pbuffer: pbfront, SampleCount: sampleCount, op: 0);
      PSET_GetNextN(ppset: pdsp->ppset[1], pbuffer: pbfront, SampleCount: sampleCount, op: 1);
      PSET_GetNextN(ppset: pdsp->ppset[2], pbuffer: pbrear, SampleCount: sampleCount, op: 0);
      PSET_GetNextN(ppset: pdsp->ppset[3], pbuffer: pbrear, SampleCount: sampleCount, op: 1);
    }
    else if ( sampleCount != 0 )
    {
      v5 = pbrear;
      v6 = &pbfront->right;
      pbfronta = (portable_samplepair_t *)((char *)pbrear - (char *)pbfront);
      do
      {
        --sampleCount;
        bexp = PSET_GetNext(ppset: pdsp->ppset[0], x: *(v6 - 1));
        fra = PSET_GetNext(ppset: pdsp->ppset[1], x: *v6);
        rrpa = PSET_GetNext(ppset: pdsp->ppset[2], x: v5->left);
        v7 = PSET_GetNext(ppset: pdsp->ppset[3], x: *(int *)((char *)&pbfronta->left + (_DWORD)v6));
        *(v6 - 1) = bexp;
        *v6 = fra;
        v5->left = rrpa;
        *(int *)((char *)&pbfronta->left + (_DWORD)v6) = v7;
        v6 += 2;
        ++v5;
      }
      while ( sampleCount != 0 );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10025110
// Name: void DSP_Process5To5(struct dsp_t __near *,struct portable_samplepair_t __near *,struct portable_samplepair_t __near *,struct portable_samplepair_t __near *,int,bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DSP_Process5To5(
        dsp_t *pdsp,
        portable_samplepair_t *pbfront,
        portable_samplepair_t *pbrear,
        portable_samplepair_t *pbcenter,
        int sampleCount,
        bool bcrossfading)
{
  dsp_t *v6; // edi
  portable_samplepair_t *v7; // esi
  int *v8; // ebx
  int v9; // eax
  portable_samplepair_t *v10; // ebx
  int v11; // eax
  int Next; // esi
  int v13; // edi
  int v14; // ebx
  int v15; // eax
  int v16; // esi
  int v17; // esi
  int v18; // edi
  int v19; // ebx
  int v20; // ecx
  int v21; // edx
  int fcpa; // [esp+Ch] [ebp-20h]
  int fcp; // [esp+Ch] [ebp-20h]
  int fca; // [esp+10h] [ebp-1Ch]
  int fc; // [esp+10h] [ebp-1Ch]
  int rrp; // [esp+14h] [ebp-18h]
  int rrpa; // [esp+14h] [ebp-18h]
  int v28; // [esp+18h] [ebp-14h]
  int rlp; // [esp+1Ch] [ebp-10h]
  int frp; // [esp+20h] [ebp-Ch]
  int flp; // [esp+24h] [ebp-8h]
  int *p_right; // [esp+28h] [ebp-4h]
  portable_samplepair_t *pbfronta; // [esp+38h] [ebp+Ch]
  portable_samplepair_t *pbfrontb; // [esp+38h] [ebp+Ch]
  int fra; // [esp+3Ch] [ebp+10h]
  portable_samplepair_t *fr; // [esp+3Ch] [ebp+10h]
  portable_samplepair_t *pbcentera; // [esp+40h] [ebp+14h]
  portable_samplepair_t *pbcenterb; // [esp+40h] [ebp+14h]
  int bexp; // [esp+48h] [ebp+1Ch]
  bool bexp_3; // [esp+4Bh] [ebp+1Fh]

  v6 = pdsp;
  if ( bcrossfading )
  {
    bexp_3 = pdsp->bexpfade;
    if ( sampleCount != 0 )
    {
      v10 = pbfront;
      p_right = &pbrear->right;
      v11 = (char *)pbrear - (char *)pbfront;
      fr = pbfront;
      pbcenterb = (portable_samplepair_t *)((char *)pbcenter - (char *)pbfront);
      pbfrontb = (portable_samplepair_t *)v11;
      while ( 1 )
      {
        --sampleCount;
        Next = PSET_GetNext(ppset: v6->ppset[0], x: v10->left);
        v13 = PSET_GetNext(ppset: v6->ppset[1], x: v10->right);
        v14 = PSET_GetNext(ppset: pdsp->ppset[2], x: *(int *)((char *)&pbfrontb->left + (_DWORD)v10));
        v28 = PSET_GetNext(ppset: pdsp->ppset[3], x: *p_right);
        fc = PSET_GetNext(ppset: pdsp->ppset[4], x: *(int *)((char *)&pbcenterb->left + (_DWORD)fr));
        flp = PSET_GetNext(ppset: pdsp->ppsetprev[0], x: fr->left);
        frp = PSET_GetNext(ppset: pdsp->ppsetprev[1], x: fr->right);
        rlp = PSET_GetNext(ppset: pdsp->ppsetprev[2], x: *(int *)((char *)&pbfrontb->left + (_DWORD)fr));
        rrp = PSET_GetNext(ppset: pdsp->ppsetprev[3], x: *p_right);
        fcp = PSET_GetNext(ppset: pdsp->ppsetprev[4], x: *(int *)((char *)&pbcenterb->left + (_DWORD)fr));
        v15 = RMP_GetNext(prmp: &pdsp->xramp);
        v16 = (v15 * (Next - flp)) >> 12;
        if ( bexp_3 )
        {
          v17 = flp + ((v15 * v16) >> 12);
          v18 = frp + ((v15 * ((v15 * (v13 - frp)) >> 12)) >> 12);
          v19 = rlp + ((v15 * ((v15 * (v14 - rlp)) >> 12)) >> 12);
          rrpa = rrp + ((v15 * ((v15 * (v28 - rrp)) >> 12)) >> 12);
          v20 = fcp;
          v21 = (v15 * (fc - fcp)) >> 12;
        }
        else
        {
          v17 = flp + v16;
          v18 = frp + ((v15 * (v13 - frp)) >> 12);
          v19 = rlp + ((v15 * (v14 - rlp)) >> 12);
          rrpa = rrp + ((v15 * (v28 - rrp)) >> 12);
          v20 = fcp;
          v21 = fc - fcp;
        }
        fr->left = v17;
        fr->right = v18;
        *(int *)((char *)&pbfrontb->left + (_DWORD)fr) = v19;
        *p_right = rrpa;
        *(int *)((char *)&pbcenterb->left + (_DWORD)fr++) = v20 + ((v15 * v21) >> 12);
        p_right += 2;
        if ( sampleCount == 0 )
          break;
        v10 = fr;
        v6 = pdsp;
      }
    }
  }
  else if ( pdsp->ipset != 0 )
  {
    if ( pdsp->ppset[0]->type <= 1u
      && pdsp->ppset[1]->type <= 1u
      && pdsp->ppset[2]->type <= 1u
      && FBatchPreset(ppset: pdsp->ppset[3]) )
    {
      PSET_GetNextN(ppset: pdsp->ppset[0], pbuffer: pbfront, SampleCount: sampleCount, op: 0);
      PSET_GetNextN(ppset: pdsp->ppset[1], pbuffer: pbfront, SampleCount: sampleCount, op: 1);
      PSET_GetNextN(ppset: pdsp->ppset[2], pbuffer: pbrear, SampleCount: sampleCount, op: 0);
      PSET_GetNextN(ppset: pdsp->ppset[3], pbuffer: pbrear, SampleCount: sampleCount, op: 1);
      PSET_GetNextN(ppset: pdsp->ppset[4], pbuffer: pbcenter, SampleCount: sampleCount, op: 0);
    }
    else if ( sampleCount != 0 )
    {
      v7 = pbfront;
      v8 = &pbrear->right;
      pbcentera = (portable_samplepair_t *)((char *)pbcenter - (char *)pbfront);
      pbfronta = (portable_samplepair_t *)((char *)pbrear - (char *)pbfront);
      do
      {
        --sampleCount;
        bexp = PSET_GetNext(ppset: pdsp->ppset[0], x: v7->left);
        fra = PSET_GetNext(ppset: pdsp->ppset[1], x: v7->right);
        fcpa = PSET_GetNext(ppset: pdsp->ppset[2], x: *(int *)((char *)&v7->left + (_DWORD)pbfronta));
        fca = PSET_GetNext(ppset: pdsp->ppset[3], x: *v8);
        v9 = PSET_GetNext(ppset: pdsp->ppset[4], x: *(int *)((char *)&v7->left + (_DWORD)pbcentera));
        v7->left = bexp;
        v7->right = fra;
        *(int *)((char *)&v7->left + (_DWORD)pbfronta) = fcpa;
        *v8 = fca;
        *(int *)((char *)&v7->left + (_DWORD)pbcentera) = v9;
        ++v7;
        v8 += 2;
      }
      while ( sampleCount != 0 );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10025470
// Name: int DSP_CountFilePresets(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl DSP_CountFilePresets(const char *pstart)
{
  int v1; // edi
  char v2; // bl
  const char *i; // esi
  bool v4; // zf
  bool binpreset; // [esp+13h] [ebp-1h]

  v1 = 0;
  binpreset = false;
  v2 = 0;
  for ( i = COM_Parse(data: pstart); strlen(com_token) != 0; i = COM_Parse(data: i) )
  {
    if ( com_token[0] == 123 )
    {
      if ( binpreset )
      {
        v2 = 0;
      }
      else
      {
        v2 = 1;
        ++v1;
        binpreset = true;
      }
    }
    else if ( com_token[0] == 125 )
    {
      if ( binpreset )
      {
        v4 = v2 == 0;
        v2 = 1;
        if ( !v4 )
          binpreset = false;
      }
      else
      {
        DevMsg(a1: "PARSE ERROR!!! dsp_presets.txt: unexpected '}' \n");
      }
    }
  }
  return v1;
}

//------------------------------------------------------------------------------
// Address: 0x10025510
// Name: float DSP_LookupStringToken(char __near *,int)
// Source: json
//------------------------------------------------------------------------------
double __cdecl DSP_LookupStringToken(char *psz, int ipset)
{
  char v2; // al
  int v3; // esi
  dsp_stringmap_t *v4; // edi
  float fipset; // [esp+20h] [ebp+Ch]

  v2 = *psz;
  fipset = (float)ipset;
  if ( *psz == 43
    || v2 == 45
    || v2 == 48
    || v2 == 49
    || v2 == 50
    || v2 == 51
    || v2 == 52
    || v2 == 53
    || v2 == 54
    || v2 == 55
    || v2 == 56
    || v2 == 57 )
  {
    return atof(nptr: psz);
  }
  v3 = 0;
  if ( gcdsp_stringmap <= 0 )
  {
LABEL_17:
    DevMsg(a1: "DSP PARSE ERROR! token not found in dsp_presets.txt. Preset: %3.0f \n", fipset);
    return 0.0;
  }
  else
  {
    v4 = gdsp_stringmap;
    while ( _V_stricmp(s1: v4->sz, s2: psz) != 0 )
    {
      ++v3;
      ++v4;
      if ( v3 >= gcdsp_stringmap )
        goto LABEL_17;
    }
    return (double)dword_10411F24[10 * v3];
  }
}

//------------------------------------------------------------------------------
// Address: 0x100255D0
// Name: void DSP_FastReset(int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DSP_FastReset(int dspType)
{
  PreserveDSP_t *v1; // eax

  v1 = g_PreserveDSP;
  while ( v1->cvar != &dsp_player )
  {
    if ( (int)++v1 >= (int)&unk_10411EFC )
      return;
  }
  v1->oldvalue = (float)dspType;
}

//------------------------------------------------------------------------------
// Address: 0x10025600
// Name: void DelayAllpass_Opt2<2,0>(int,int,int __near *,int __near * __near *,int,int,int __near *,int __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DelayAllpass_Opt2<2,0>(
        int *nDelaySize,
        int tdelay,
        int *psamps,
        int **ppsamp,
        int fbgain,
        int outgain,
        int *pIn,
        int *pOut,
        int nCount)
{
  int *v9; // ecx
  int v10; // edi
  int v12; // ebx
  int v13; // edx
  int v14; // eax
  int nDelaySizeP1; // [esp+8h] [ebp-4h]
  int *pSampsPDelaySize; // [esp+14h] [ebp+8h]

  v9 = *ppsamp;
  v10 = (int)nDelaySize + 1;
  pSampsPDelaySize = &psamps[(_DWORD)nDelaySize];
  nDelaySizeP1 = v10;
  if ( nCount <= 0 )
  {
    *ppsamp = v9;
  }
  else
  {
    v12 = fbgain;
    do
    {
      v13 = v9[tdelay - (v10 & (((char *)pSampsPDelaySize - (char *)&v9[tdelay]) >> 31))];
      v14 = *pIn + ((v12 * v13) >> 12);
      *v9 = v14;
      pIn += 2;
      v10 = nDelaySizeP1;
      v9 = &v9[(nDelaySizeP1 & (((char *)(v9 - 1) - (char *)psamps) >> 31)) - 1];
      v12 = fbgain;
      --nCount;
      *pOut++ += (outgain * (v13 + (-(fbgain * v14) >> 12))) >> 12;
    }
    while ( nCount > 0 );
    *ppsamp = v9;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100256B0
// Name: void DelayAllpass_Opt2<2,1>(int,int,int __near *,int __near * __near *,int,int,int __near *,int __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DelayAllpass_Opt2<2,1>(
        int *nDelaySize,
        int tdelay,
        int *psamps,
        int **ppsamp,
        int fbgain,
        int outgain,
        int *pIn,
        int *pOut,
        int nCount)
{
  int *v10; // ecx
  int v11; // esi
  int v12; // edi
  int v13; // ebx
  int v14; // edx
  int v15; // eax
  int nDelaySizeP1; // [esp+8h] [ebp-4h]
  int *pSampsPDelaySize; // [esp+14h] [ebp+8h]

  v10 = *ppsamp;
  pSampsPDelaySize = &psamps[(_DWORD)nDelaySize];
  v11 = nCount;
  v12 = (int)nDelaySize + 1;
  nDelaySizeP1 = (int)nDelaySize + 1;
  if ( nCount <= 0 )
  {
    *ppsamp = v10;
  }
  else
  {
    v13 = fbgain;
    do
    {
      v14 = v10[tdelay - (v12 & (((char *)pSampsPDelaySize - (char *)&v10[tdelay]) >> 31))];
      v15 = *pIn + ((v13 * v14) >> 12);
      *v10 = v15;
      pIn += 2;
      v12 = nDelaySizeP1;
      v10 = &v10[(nDelaySizeP1 & (((char *)(v10 - 1) - (char *)psamps) >> 31)) - 1];
      v13 = fbgain;
      --v11;
      *pOut++ = (outgain * (v14 + (-(fbgain * v15) >> 12))) >> 12;
    }
    while ( v11 > 0 );
    *ppsamp = v10;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10025760
// Name: void DelayAllpass_Opt2<1,1>(int,int,int __near *,int __near * __near *,int,int,int __near *,int __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DelayAllpass_Opt2<1,1>(
        int *nDelaySize,
        int tdelay,
        int *psamps,
        int **ppsamp,
        int fbgain,
        int outgain,
        int *pIn,
        int *pOut,
        int nCount)
{
  int **v9; // edx
  int *v10; // ecx
  int v11; // edi
  int *v12; // edx
  int v13; // ebx
  int v14; // esi
  int v15; // eax
  int nDelaySizeP1; // [esp+8h] [ebp-8h]
  int *pSampsPDelaySize; // [esp+18h] [ebp+8h]

  v9 = ppsamp;
  v10 = *ppsamp;
  v11 = (int)nDelaySize + 1;
  pSampsPDelaySize = &psamps[(_DWORD)nDelaySize];
  nDelaySizeP1 = v11;
  if ( nCount > 0 )
  {
    v12 = pOut;
    v13 = fbgain;
    do
    {
      v14 = v10[tdelay - (v11 & (((char *)pSampsPDelaySize - (char *)&v10[tdelay]) >> 31))];
      v15 = *(int *)((char *)v12 + (char *)pIn - (char *)pOut) + ((v13 * v14) >> 12);
      v11 = nDelaySizeP1;
      *v10 = v15;
      v10 = &v10[(nDelaySizeP1 & (((char *)(v10 - 1) - (char *)psamps) >> 31)) - 1];
      v13 = fbgain;
      --nCount;
      *v12++ = (outgain * (v14 + (-(fbgain * v15) >> 12))) >> 12;
    }
    while ( nCount > 0 );
    v9 = ppsamp;
  }
  *v9 = v10;
}

//------------------------------------------------------------------------------
// Address: 0x10025800
// Name: struct flt_t __near * FLT_Params(struct prc_t __near *)
// Source: json
//------------------------------------------------------------------------------
flt_t *__cdecl FLT_Params(prc_t *pprc)
{
  float v1; // xmm1_4
  float v2; // xmm2_4
  flt_t *v3; // ebx
  float v4; // xmm0_4
  int v5; // eax
  int v6; // eax
  int v7; // eax
  int v8; // edi
  float v9; // xmm0_4
  int i; // eax
  int v11; // edx
  flt_t *result; // eax
  flt_t *v13; // esi
  flt_t *v14; // eax
  int v15; // ecx
  float v16; // [esp+14h] [ebp-16Ch]
  float v17; // [esp+14h] [ebp-16Ch]
  int b_scaled[13]; // [esp+24h] [ebp-15Ch] BYREF
  int b_bp_scaled[13]; // [esp+58h] [ebp-128h] BYREF
  int b_bp[13]; // [esp+8Ch] [ebp-F4h] BYREF
  int a_bp[13]; // [esp+C0h] [ebp-C0h] BYREF
  int b[13]; // [esp+F4h] [ebp-8Ch] BYREF
  int a[13]; // [esp+128h] [ebp-58h] BYREF
  float gain; // [esp+15Ch] [ebp-24h]
  float ftype; // [esp+160h] [ebp-20h]
  float qual; // [esp+164h] [ebp-1Ch]
  float qwidth; // [esp+168h] [ebp-18h]
  int M_bp; // [esp+16Ch] [ebp-14h] BYREF
  int L_bp; // [esp+170h] [ebp-10h] BYREF
  int M; // [esp+174h] [ebp-Ch] BYREF
  int L; // [esp+178h] [ebp-8h] BYREF
  int cutoff; // [esp+17Ch] [ebp-4h]
  char bpass_3; // [esp+18Bh] [ebp+Bh]

  v1 = pprc->prm[4];
  v2 = pprc->prm[0];
  v3 = nullptr;
  qual = pprc->prm[3];
  cutoff = SLODWORD(pprc->prm[1]);
  v4 = pprc->prm[2];
  gain = v1;
  qwidth = v4;
  L = 0;
  *(float *)&M = 0.0;
  L_bp = 0;
  M_bp = 0;
  bpass_3 = 0;
  if ( v4 > 0.0 )
  {
    bpass_3 = 1;
    ftype = 0.0;
    FLT_Design_3db_IIR(cutoff: *(float *)&cutoff, ftype: 1.0, pM: &M_bp, pL: &L_bp, a: a_bp, b: b_bp);
    v5 = M_bp;
    if ( M_bp >= 1 )
    {
      if ( M_bp > 12 )
        v5 = 12;
    }
    else
    {
      v5 = 1;
    }
    M_bp = v5;
    v6 = L_bp;
    if ( L_bp >= 1 )
    {
      if ( L_bp > 12 )
        v6 = 12;
    }
    else
    {
      v6 = 1;
    }
    v2 = ftype;
    L_bp = v6;
    *(float *)&cutoff = qwidth + *(float *)&cutoff;
  }
  FLT_Design_3db_IIR(cutoff: *(float *)&cutoff, ftype: (float)(int)v2, pM: &M, pL: &L, a, b);
  if ( M >= 1 )
  {
    cutoff = 12;
    if ( M <= 12 )
      cutoff = M;
  }
  else
  {
    cutoff = 1;
  }
  v7 = L;
  if ( L >= 1 )
  {
    L = 12;
    if ( v7 <= 12 )
      L = v7;
  }
  else
  {
    L = 1;
  }
  v8 = (int)qual;
  if ( (int)qual >= 0 )
  {
    if ( v8 > 3 )
      v8 = 3;
  }
  else
  {
    v8 = 0;
  }
  if ( bpass_3 != 0 && v8 <= 1 )
    v8 = 1;
  v9 = gain;
  qwidth = 0.0;
  *(float *)&M = 0.0;
  for ( i = 0; i < 12; ++i )
  {
    v11 = (int)(float)((float)b[i] * v9);
    b_bp_scaled[i] = (int)(float)((float)b_bp[i] * v9);
    b_scaled[i] = v11;
  }
  v16 = 1.0;
  if ( bpass_3 != 0 )
    result = FLT_Alloc(N: v8, M: M_bp, L: L_bp, a: a_bp, b: b_bp_scaled, gain: v16);
  else
    result = FLT_Alloc(N: v8, M: cutoff, L, a, b: b_scaled, gain: v16);
  v13 = result;
  if ( result != nullptr )
  {
    if ( v8 != 1 )
    {
      if ( v8 != 2 )
      {
        if ( v8 != 3 )
        {
LABEL_41:
          v15 = M;
          *(float *)&v13->pf2 = qwidth;
          v13->pf1 = v3;
          v13->pf3 = (flt_t *)v15;
          return v13;
        }
        v17 = 1.0;
        if ( bpass_3 != 0 )
          v14 = FLT_Alloc(N: 0, M: M_bp, L: L_bp, a: a_bp, b: b_bp, gain: v17);
        else
          v14 = FLT_Alloc(N: 0, M: cutoff, L, a, b, gain: v17);
        M = (int)v14;
      }
      qwidth = COERCE_FLOAT(FLT_Alloc(N: 0, M: cutoff, L, a, b, gain: 1.0));
    }
    v3 = FLT_Alloc(N: 0, M: cutoff, L, a, b, gain: 1.0);
    goto LABEL_41;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10025B60
// Name: struct dly_t __near * DLY_AllocLP(int,int,int,int,int,int,int __near *,int __near *)
// Source: json
//------------------------------------------------------------------------------
dly_t *__cdecl DLY_AllocLP(int D, int a, int b, int type, int M, int L, int *fa, int *fb)
{
  dly_t *v8; // esi
  int v9; // edi
  dly_t *v10; // eax
  flt_t *v12; // eax
  int *v13; // eax
  int *v14; // ebx
  int v15; // eax
  int v16; // ebx

  v8 = nullptr;
  v9 = 0;
  v10 = dlys;
  while ( v10->fused )
  {
    ++v10;
    ++v9;
    if ( (int)v10 >= (int)flts )
      goto LABEL_7;
  }
  v8 = &dlys[v9];
  if ( v8 != nullptr )
    _V_memset(dest: &dlys[v9], fill: 0, count: 72);
LABEL_7:
  if ( v9 == 128 )
  {
    DevMsg(a1: "DSP: Warning, failed to allocate delay line.\n");
    return nullptr;
  }
  else
  {
    if ( type == 5 || type == 6 )
      b = (int)(float)((float)b * 0.25);
    if ( (type == 4 || type == 2 || type == 5)
      && (v12 = FLT_Alloc(N: 0, M, L, a: fa, b: fb, gain: (float)a * 0.00024414062), v8->pflt = v12, v12 == nullptr) )
    {
      DevMsg(a1: "DSP: Warning, failed to allocate filter for delay line.\n");
      return nullptr;
    }
    else
    {
      v13 = (int *)MemAlloc_Alloc(nSize: (unsigned __int64)(unsigned int)(D + 1) >> 30 != 0 ? -1 : 4 * (D + 1));
      v14 = v13;
      if ( v13 != nullptr )
      {
        _V_memset(dest: v13, fill: 0, count: 4 * D + 4);
        v15 = type;
        v8->p = v14;
        v8->w = v14;
        v8->type = type;
        v8->D = D;
        v8->t = D;
        v8->tnew = D;
        v8->xf = 0;
        v8->D0 = D;
        v16 = a;
        if ( a >= 4095 )
          v16 = 4095;
        v8->a = v16;
        v8->b = b;
        v8->fused = true;
        if ( type == 3 || type == 4 )
        {
          v8->a = 0;
          v8->b = 4096;
        }
        else
        {
          DLY_SetNormalizingGain(pdly: v8, feedback: a);
          v15 = type;
        }
        if ( v15 == 5 || v15 == 6 )
          DLY_ChangeTaps(pdly: v8, t0: D, t1: D, t2: D, t3: D);
        return v8;
      }
      else
      {
        _Warning(a1: "Sound DSP: Failed to lock.\n");
        FLT_Free(pf: v8->pflt);
        return nullptr;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10025D10
// Name: struct dly_t __near * DLY_Params(struct prc_t __near *)
// Source: json
//------------------------------------------------------------------------------
dly_t *__cdecl DLY_Params(prc_t *pprc)
{
  long double v1; // st7
  float v2; // xmm0_4
  long double v3; // st7
  float v4; // xmm0_4
  float v5; // xmm0_4
  int v6; // edi
  dly_t *v7; // ebx
  long double v8; // st7
  long double v9; // st7
  int v10; // ecx
  float v11; // xmm1_4
  flt_t *v12; // eax
  flt_t *v13; // esi
  prc_t prcf; // [esp+8h] [ebp-80h] BYREF
  float t1; // [esp+64h] [ebp-24h]
  float t2; // [esp+68h] [ebp-20h]
  float t3; // [esp+6Ch] [ebp-1Ch]
  int a; // [esp+70h] [ebp-18h]
  int b; // [esp+74h] [ebp-14h]
  float qwidth; // [esp+78h] [ebp-10h]
  float ftype; // [esp+7Ch] [ebp-Ch]
  float cutoff; // [esp+80h] [ebp-8h]
  float qual; // [esp+84h] [ebp-4h]
  int D; // [esp+90h] [ebp+8h]

  v1 = fabs(pprc->prm[8]);
  ftype = pprc->prm[4];
  v2 = pprc->prm[5];
  t1 = v1;
  v3 = pprc->prm[9];
  cutoff = v2;
  v4 = pprc->prm[6];
  t2 = fabs(v3);
  qwidth = v4;
  v5 = pprc->prm[7];
  v6 = (int)pprc->prm[0];
  t3 = fabs(pprc->prm[10]);
  v7 = nullptr;
  v8 = fabs(pprc->prm[1]);
  qual = v5;
  v9 = v8 * 44100.0 * 0.001;
  v10 = (int)(float)(pprc->prm[2] * 4096.0);
  v11 = pprc->prm[3] * 4096.0;
  D = (int)v9;
  a = v10;
  b = (int)v11;
  switch ( v6 )
  {
    case 0:
    case 1:
    case 3:
    case 6:
      v7 = DLY_AllocLP(D: (int)v9, a: v10, b: (int)v11, type: v6, M: 0, L: 0, fa: nullptr, fb: nullptr);
      goto LABEL_6;
    case 2:
    case 4:
    case 5:
      prcf.prm[3] = qual;
      prcf.prm[1] = cutoff;
      prcf.prm[0] = ftype;
      prcf.prm[2] = qwidth;
      prcf.prm[4] = 1.0;
      v12 = FLT_Params(pprc: &prcf);
      v13 = v12;
      if ( v12 != nullptr )
      {
        v7 = DLY_AllocLP(D, a, b, type: v6, M: v12->M, L: v12->L, fa: v12->a, fb: v12->b);
        FLT_Free(pf: v13);
LABEL_6:
        if ( v7 != nullptr && (v6 == 5 || v6 == 6) )
          DLY_ChangeTaps(
            pdly: v7,
            t0: D,
            t1: (int)(float)((float)(t1 * 44100.0) * 0.001),
            t2: (int)(float)((float)(t2 * 44100.0) * 0.001),
            t3: (int)(float)((float)(t3 * 44100.0) * 0.001));
        return v7;
      }
      else
      {
        DevMsg(a1: "DSP: Warning, failed to allocate filter.\n");
        return nullptr;
      }
    default:
      return v7;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10025EF0
// Name: struct mdy_t __near * MDY_Params(struct prc_t __near *)
// Source: json
//------------------------------------------------------------------------------
dly_t *__cdecl MDY_Params(prc_t *pprc)
{
  float v2; // xmm1_4
  dly_t *result; // eax
  float ramptime; // [esp+10h] [ebp-Ch]
  float depth; // [esp+14h] [ebp-8h]
  float mix; // [esp+18h] [ebp-4h]
  float modtime; // [esp+24h] [ebp+8h]

  v2 = pprc->prm[8];
  ramptime = pprc->prm[10] * 0.001;
  modtime = 0.0;
  if ( v2 != 0.0 )
    modtime = 1.0 / v2;
  depth = pprc->prm[9];
  mix = pprc->prm[11];
  result = DLY_Params(pprc);
  if ( result != nullptr )
    return (dly_t *)MDY_Alloc(pdly: result, ramptime, modtime, depth, mix);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10025F80
// Name: struct rva_t __near * RVA_Alloc(int __near *,int __near *,int __near *,int,struct flt_t __near *,int,float,float,float)
// Source: json
//------------------------------------------------------------------------------
rva_t *__cdecl RVA_Alloc(
        int *D,
        int *a,
        int *b,
        int m,
        flt_t *pflt,
        int fparallel,
        float fmoddly,
        float fmodrate,
        float ftaps)
{
  int v9; // ecx
  rva_t *v10; // eax
  rva_t *v12; // esi
  flt_t *v13; // edi
  int v14; // edx
  int *v15; // edi
  int v16; // ecx
  int v17; // eax
  int v18; // esi
  double v19; // st7
  double v20; // st6
  double v21; // st4
  double v22; // st4
  double v23; // st7
  dly_t **v24; // edi
  int v25; // ebx
  double v26; // st6
  float v27; // xmm0_4
  double v28; // st6
  double v29; // st7
  int v30; // eax
  dly_t **v31; // ecx
  flt_t *pf1; // eax
  flt_t *pf2; // eax
  flt_t *pf3; // eax
  int ramptime; // [esp+0h] [ebp-44h]
  float ramptimea; // [esp+0h] [ebp-44h]
  int modtime; // [esp+4h] [ebp-40h]
  float modtimea; // [esp+4h] [ebp-40h]
  int *v39; // [esp+8h] [ebp-3Ch]
  int *gain; // [esp+Ch] [ebp-38h]
  float depth; // [esp+1Ch] [ebp-28h]
  float deptha; // [esp+1Ch] [ebp-28h]
  double v43; // [esp+20h] [ebp-24h]
  float t2; // [esp+24h] [ebp-20h]
  rva_t *prva; // [esp+30h] [ebp-14h]
  int v46; // [esp+34h] [ebp-10h]
  dly_t **pdlys; // [esp+38h] [ebp-Ch]
  flt_t *pflt2; // [esp+3Ch] [ebp-8h]

  pflt2 = nullptr;
  v9 = 0;
  v10 = &rvas[1];
  while ( v10[-1].fused )
  {
    if ( !v10->fused )
    {
      ++v9;
      break;
    }
    if ( !v10[1].fused )
    {
      v9 += 2;
      break;
    }
    if ( !v10[2].fused )
    {
      v9 += 3;
      break;
    }
    v10 += 4;
    v9 += 4;
    if ( (int)v10 >= (int)&mdys[1].rmp_interp.nEndRampTimeInMs )
      break;
  }
  if ( v9 == 64 )
  {
    DevMsg(a1: "DSP: Warning, failed to allocate reverb.\n");
    return nullptr;
  }
  v12 = &rvas[v9];
  prva = v12;
  if ( pflt != nullptr && fparallel == 0 )
  {
    v13 = FLT_Alloc(N: 0, M: pflt->M, L: pflt->L, a: pflt->a, b: pflt->b, gain: 1.0);
    pflt2 = v13;
    if ( v13 == nullptr )
    {
      DevMsg(a1: "DSP: Warning, failed to allocate flt for reverb.\n");
      return nullptr;
    }
    v13->pf1 = FLT_Alloc(N: 0, M: pflt->M, L: pflt->L, a: pflt->a, b: pflt->b, gain: 1.0);
    v13->N = 1;
  }
  v14 = m;
  if ( m > 0 )
  {
    v15 = D;
    v16 = (char *)b - (char *)a;
    v17 = (char *)a - (char *)D;
    pdlys = v12->pdlys;
    v46 = m;
    while ( 1 )
    {
      if ( pflt != nullptr && fparallel != 0 )
        v18 = 2 * (*(int *)((char *)v15 + v17) < 0) + 2;
      else
        v18 = ftaps > 0.0 ? 6 : 0;
      if ( v18 == 2 )
      {
        if ( ftaps > 0.0 )
          v18 = 5;
      }
      else if ( v18 != 4 && v18 != 5 )
      {
        gain = nullptr;
        v39 = nullptr;
        modtime = 0;
        ramptime = 0;
        goto LABEL_29;
      }
      gain = pflt->b;
      v39 = pflt->a;
      modtime = pflt->L;
      ramptime = pflt->M;
LABEL_29:
      *pdlys = DLY_AllocLP(
                 D: *v15,
                 a: abs32(*(int *)((char *)v15 + v17)),
                 b: *(int *)((char *)v15 + v17 + v16),
                 type: v18,
                 M: ramptime,
                 L: modtime,
                 fa: v39,
                 fb: gain);
      if ( v18 == 5 || v18 == 6 )
      {
        v19 = (double)*v15;
        v20 = ftaps;
        v21 = (1.0 - 3.141592 * ftaps) * v19;
        if ( v21 < 220.0 )
          v21 = 220.0;
        depth = v21;
        v22 = (1.0 - v20 * 1.697043) * v19;
        if ( v22 < 308.0 )
          v22 = 308.0;
        v23 = v19 * (1.0 - v20 * 0.9632500000000001);
        if ( v23 < 441.0 )
          v23 = 441.0;
        t2 = v22;
        DLY_ChangeTaps(pdly: *pdlys, t0: (int)depth, t1: (int)t2, t2: (int)v23, t3: *v15);
      }
      ++pdlys;
      ++v15;
      if ( --v46 == 0 )
      {
        v14 = m;
        v12 = prva;
        break;
      }
      v17 = (char *)a - (char *)D;
      v16 = (char *)b - (char *)a;
    }
  }
  if ( fmoddly > 0.0 )
  {
    if ( v14 > 0 )
    {
      v24 = v12->pdlys;
      v25 = v14;
      v43 = fmoddly * 0.001;
      do
      {
        v26 = (double)(*v24)->D * 0.000022675737;
        if ( v43 / v26 >= 0.01 )
        {
          if ( v43 / v26 <= 0.99 )
          {
            deptha = v43 / v26;
            v27 = deptha;
          }
          else
          {
            v27 = 0.99000001;
          }
        }
        else
        {
          v27 = 0.0099999998;
        }
        v28 = v26 * fmodrate;
        v29 = 0.5 * v28;
        if ( v29 >= 0.02 )
          v29 = 0.02;
        modtimea = v28;
        ramptimea = v29;
        v24[12] = (dly_t *)MDY_Alloc(pdly: *v24, ramptime: ramptimea, modtime: modtimea, depth: v27, mix: 1.0);
        ++v24;
        --v25;
      }
      while ( v25 != 0 );
      v14 = m;
    }
    v12->fmoddly = true;
  }
  v30 = 0;
  if ( v14 <= 0 )
  {
LABEL_60:
    v12->fparallel = fparallel;
    v12->fused = true;
    v12->m = v14;
    v12->pflt = pflt2;
    return v12;
  }
  else
  {
    v31 = v12->pdlys;
    while ( *v31 != nullptr )
    {
      ++v30;
      ++v31;
      if ( v30 >= v14 )
        goto LABEL_60;
    }
    if ( pflt2 != nullptr )
    {
      pf1 = pflt2->pf1;
      if ( pf1 != nullptr )
        _V_memset(dest: pf1, fill: 0, count: 184);
      pf2 = pflt2->pf2;
      if ( pf2 != nullptr )
        _V_memset(dest: pf2, fill: 0, count: 184);
      pf3 = pflt2->pf3;
      if ( pf3 != nullptr )
        _V_memset(dest: pf3, fill: 0, count: 184);
      _V_memset(dest: pflt2, fill: 0, count: 184);
    }
    RVA_Free(prva: v12);
    DevMsg(a1: "DSP: Warning, failed to allocate delay for reverb.\n");
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10026390
// Name: struct rva_t __near * RVA_Params(struct prc_t __near *)
// Source: json
//------------------------------------------------------------------------------
rva_t *__cdecl RVA_Params(prc_t *pprc)
{
  float v2; // xmm4_4
  float v3; // xmm7_4
  float v4; // xmm2_4
  float v5; // xmm0_4
  float v6; // xmm3_4
  float v7; // xmm1_4
  float v8; // xmm5_4
  float v9; // xmm6_4
  long double v10; // st7
  float v11; // xmm4_4
  int v12; // xmm7_4
  float v13; // xmm2_4
  float v14; // xmm4_4
  int v15; // edi
  int v16; // esi
  long double v17; // st7
  double v18; // st6
  long double v19; // st5
  float v20; // xmm2_4
  long double v21; // st4
  long double v22; // st5
  flt_t *v23; // esi
  rva_t *v24; // edi
  int b[12]; // [esp+14h] [ebp-12Ch] BYREF
  prc_t prcf; // [esp+44h] [ebp-FCh] BYREF
  int a[12]; // [esp+A0h] [ebp-A0h] BYREF
  int D[12]; // [esp+D0h] [ebp-70h] BYREF
  float rgd[3]; // [esp+100h] [ebp-40h] BYREF
  float rgfb[3]; // [esp+10Ch] [ebp-34h] BYREF
  float gain; // [esp+118h] [ebp-28h]
  float ftaps; // [esp+11Ch] [ebp-24h]
  float fmoddly; // [esp+120h] [ebp-20h]
  float cutoff; // [esp+124h] [ebp-1Ch]
  float size_min; // [esp+128h] [ebp-18h]
  float fparallel; // [esp+12Ch] [ebp-14h]
  float fmodrate; // [esp+130h] [ebp-10h]
  float depth; // [esp+134h] [ebp-Ch]
  float width; // [esp+138h] [ebp-8h]
  int height; // [esp+13Ch] [ebp-4h]
  float feedback; // [esp+148h] [ebp+8h]

  v2 = pprc->prm[5];
  v3 = pprc->prm[15];
  v4 = pprc->prm[3];
  width = fabs(pprc->prm[9]);
  v5 = pprc->prm[2];
  v6 = pprc->prm[1];
  v7 = pprc->prm[0];
  depth = fabs(pprc->prm[10]);
  v8 = pprc->prm[13];
  v9 = pprc->prm[14];
  v10 = fabs(pprc->prm[11]);
  cutoff = v2;
  *(float *)&height = v10;
  fparallel = pprc->prm[6];
  fmoddly = pprc->prm[7];
  v11 = pprc->prm[8];
  ftaps = v3;
  *(float *)&v12 = 1.0;
  feedback = v4;
  v13 = pprc->prm[4];
  fmodrate = v11;
  v14 = pprc->prm[12];
  size_min = v6;
  gain = v13;
  if ( v5 < 1.0 || (*(float *)&v12 = 12.0, v5 > 12.0) )
    v5 = *(float *)&v12;
  v15 = (int)v5;
  if ( (int)width != 0 || (int)*(float *)&height != 0 || (int)depth != 0 )
  {
    if ( v15 >= 3 )
    {
      if ( (unsigned int)(v15 - 4) > 1 )
      {
        if ( (unsigned int)(v15 - 7) > 1 )
        {
          if ( v15 > 9 )
            v15 = 12;
        }
        else
        {
          v15 = 9;
        }
      }
      else
      {
        v15 = 6;
      }
    }
    else
    {
      v15 = 3;
    }
    rgd[0] = width;
    rgd[1] = depth;
    rgfb[0] = v14;
    rgfb[1] = v8;
    LODWORD(rgd[2]) = height;
    rgfb[2] = v9;
    RVA_ConstructDelays(rgd, rgf: rgfb, m: v15, D, a, b, gain, feedback);
  }
  else
  {
    v16 = 0;
    if ( v15 > 0 )
    {
      v17 = feedback;
      v18 = 4096.0;
      v19 = 4091.904;
      v20 = (float)(v13 * 4096.0) / (float)v15;
      width = (float)(v7 - v6) / (float)v15;
      while ( 1 )
      {
        height = (int)(float)((float)((float)((float)(int)(float)((float)v16 * width) + v6) * 44100.0) * 0.001);
        D[v16] = height;
        if ( v16 != 0 )
        {
          v18 = 4096.0;
          v22 = pow(v17, (double)height / (double)D[0]) * 4096.0;
          if ( v22 > 4091.904 )
            v22 = 4091.904;
          a[v16] = (int)v22;
          v19 = 4091.904;
          v17 = feedback;
        }
        else
        {
          v21 = v17 * v18;
          if ( v17 * v18 > v19 )
            v21 = v19;
          a[0] = (int)v21;
        }
        b[v16++] = (int)v20;
        if ( v16 >= v15 )
          break;
        v6 = size_min;
      }
    }
  }
  v23 = nullptr;
  if ( cutoff != 0.0 )
  {
    prcf.prm[3] = 0.0;
    prcf.prm[0] = 0.0;
    prcf.prm[2] = 0.0;
    prcf.prm[1] = cutoff;
    prcf.prm[4] = 1.0;
    v23 = FLT_Params(pprc: &prcf);
  }
  v24 = RVA_Alloc(D, a, b, m: v15, pflt: v23, (int)fparallel, fmoddly, fmodrate, ftaps);
  FLT_Free(pf: v23);
  return v24;
}

//------------------------------------------------------------------------------
// Address: 0x10026690
// Name: struct dfr_t __near * DFR_Alloc(int __near *,int __near *,int __near *,int)
// Source: json
//------------------------------------------------------------------------------
dfr_t *__cdecl DFR_Alloc(int *D, int *a, int *b, int n)
{
  int v4; // ecx
  dfr_t *v5; // eax
  int v7; // ecx
  bool v8; // zf
  dfr_t *v9; // ecx
  dfr_t *v10; // esi
  int v11; // edx
  int *v12; // ebx
  int v13; // eax
  int v14; // ecx
  int v15; // edi
  dly_t *v16; // esi
  int v17; // ecx
  dly_t *v18; // eax
  void *v19; // ebx
  flt_t *pflt; // esi
  flt_t *pf1; // eax
  flt_t *pf2; // eax
  flt_t *pf3; // eax
  int v24; // eax
  int v25; // edi
  double v26; // st6
  double v27; // st7
  int v28; // xmm1_4
  float v29; // xmm0_4
  int v30; // eax
  dly_t **v31; // ecx
  dfr_t *pdfr; // [esp+0h] [ebp-24h]
  int v33; // [esp+4h] [ebp-20h]
  int v34; // [esp+10h] [ebp-14h]
  dly_t **pdlys; // [esp+14h] [ebp-10h]
  int v36; // [esp+18h] [ebp-Ch]
  int *v37; // [esp+1Ch] [ebp-8h]
  int v38; // [esp+20h] [ebp-4h]

  v4 = 0;
  v5 = &dfrs[1];
  while ( v5[-1].fused )
  {
    if ( !v5->fused )
    {
      ++v4;
      break;
    }
    if ( !v5[1].fused )
    {
      v4 += 2;
      break;
    }
    if ( !v5[2].fused )
    {
      v4 += 3;
      break;
    }
    v5 += 4;
    v4 += 4;
    if ( (int)v5 >= (int)&rvas[1].pdlys[1] )
      break;
  }
  if ( v4 == 64 )
  {
    DevMsg(a1: "DSP: Warning, failed to allocate diffusor.\n");
    return nullptr;
  }
  else
  {
    v7 = v4;
    v8 = &dfrs[v7] == nullptr;
    v9 = &dfrs[v7];
    v10 = v9;
    pdfr = v9;
    if ( !v8 )
      _V_memset(dest: v9, fill: 0, count: 136);
    v11 = n;
    if ( n > 0 )
    {
      v12 = D;
      v13 = (char *)a - (char *)D;
      v14 = (char *)b - (char *)D;
      v37 = D;
      pdlys = v10->pdlys;
      v34 = n;
      while ( 1 )
      {
        v15 = *v12;
        v36 = *(int *)((char *)v12 + v13);
        v33 = *(int *)((char *)v12 + v14);
        v16 = nullptr;
        v17 = 0;
        v18 = dlys;
        while ( v18->fused )
        {
          ++v18;
          ++v17;
          if ( (int)v18 >= (int)flts )
            goto LABEL_24;
        }
        v16 = &dlys[v17];
        v38 = v17;
        if ( v16 != nullptr )
        {
          _V_memset(dest: &dlys[v17], fill: 0, count: 72);
          v17 = v38;
        }
LABEL_24:
        if ( v17 == 128 )
        {
          DevMsg(a1: "DSP: Warning, failed to allocate delay line.\n");
          v16 = nullptr;
        }
        else
        {
          v19 = MemAlloc_Alloc(nSize: (unsigned __int64)(unsigned int)(v15 + 1) >> 30 != 0 ? -1 : 4 * (v15 + 1));
          if ( v19 != nullptr )
          {
            _V_memset(dest: v19, fill: 0, count: 4 * v15 + 4);
            v24 = v36;
            v16->type = 1;
            v16->D = v15;
            v16->t = v15;
            v16->tnew = v15;
            v16->xf = 0;
            v16->D0 = v15;
            v16->p = (int *)v19;
            v16->w = (int *)v19;
            if ( v36 >= 4095 )
              v24 = 4095;
            v25 = v33;
            v16->a = v24;
            v16->b = v33;
            v16->fused = true;
            v26 = (double)v36 * 0.00024414062;
            v27 = 0.9990000128746033;
            if ( v26 <= 0.9990000128746033 )
              v27 = v26;
            if ( v33 == 0 )
              v25 = 4096;
            v28 = 1149239296;
            v29 = (float)(int)(1.0 / (1.0 / (1.0 - v27)) * 4096.0) * 4.0;
            if ( v29 < 1024.0 || (v28 = 1166016512, v29 > 4096.0) )
              v29 = *(float *)&v28;
            v16->b = (int)(float)((float)((float)v25 * 0.00024414062) * v29);
          }
          else
          {
            _Warning(a1: "Sound DSP: Failed to lock.\n");
            pflt = v16->pflt;
            if ( pflt != nullptr )
            {
              pf1 = pflt->pf1;
              if ( pf1 != nullptr )
                _V_memset(dest: pf1, fill: 0, count: 184);
              pf2 = pflt->pf2;
              if ( pf2 != nullptr )
                _V_memset(dest: pf2, fill: 0, count: 184);
              pf3 = pflt->pf3;
              if ( pf3 != nullptr )
                _V_memset(dest: pf3, fill: 0, count: 184);
              _V_memset(dest: pflt, fill: 0, count: 184);
            }
            v16 = nullptr;
          }
          v12 = v37;
        }
        *pdlys = v16;
        ++v12;
        v8 = v34-- == 1;
        v37 = v12;
        ++pdlys;
        if ( v8 )
          break;
        v13 = (char *)a - (char *)D;
        v14 = (char *)b - (char *)D;
      }
      v11 = n;
      v10 = pdfr;
    }
    v30 = 0;
    if ( v11 <= 0 )
    {
LABEL_53:
      v10->fused = true;
      v10->n = v11;
      return v10;
    }
    else
    {
      v31 = v10->pdlys;
      while ( *v31 != nullptr )
      {
        ++v30;
        ++v31;
        if ( v30 >= v11 )
          goto LABEL_53;
      }
      DFR_Free(pdfr: v10);
      DevMsg(a1: "DSP: Warning, failed to allocate delay for diffusor.\n");
      return nullptr;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10026990
// Name: struct dfr_t __near * DFR_Params(struct prc_t __near *)
// Source: json
//------------------------------------------------------------------------------
dfr_t *__cdecl DFR_Params(prc_t *pprc)
{
  float v2; // xmm0_4
  int v3; // xmm2_4
  float v4; // xmm1_4
  float v5; // xmm0_4
  int v6; // ebx
  int v7; // esi
  double v8; // st4
  int D[16]; // [esp+0h] [ebp-C4h] BYREF
  int a[16]; // [esp+40h] [ebp-84h] BYREF
  int b[16]; // [esp+80h] [ebp-44h] BYREF
  float size; // [esp+C0h] [ebp-4h]
  float feedback; // [esp+CCh] [ebp+8h]

  v2 = pprc->prm[0];
  *(float *)&v3 = 1.0;
  feedback = pprc->prm[2];
  v4 = pprc->prm[3];
  size = v2;
  v5 = pprc->prm[1];
  if ( v4 == 0.0 )
    v4 = 1.0;
  if ( v5 < 1.0 || (*(float *)&v3 = 8.0, v5 > 8.0) )
    v5 = *(float *)&v3;
  v6 = (int)v5;
  v7 = 0;
  if ( (int)v5 > 0 )
  {
    memset32(b, (int)(float)(v4 * 4096.0), v6);
    do
    {
      v8 = dfrfbs[v7] * 4096.0 * feedback;
      D[v7] = 44100 * (int)(float)(dfrdlys[v7] * size) / 1000;
      if ( v8 > 4091.904 )
        v8 = 4091.904;
      a[v7++] = (int)v8;
    }
    while ( v7 < v6 );
  }
  return DFR_Alloc(D, a, b, n: v6);
}

//------------------------------------------------------------------------------
// Address: 0x10026AA0
// Name: void LFOWAV_InitAll(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl LFOWAV_InitAll()
{
  dly_t *v0; // esi
  int v1; // edi
  dly_t *v2; // eax
  int *v3; // eax
  int *v4; // edi
  flt_t *pflt; // esi
  flt_t *pf1; // eax
  flt_t *pf2; // eax
  flt_t *pf3; // eax
  int *v9; // esi
  int *w; // [esp-10h] [ebp-1Ch]
  int i; // [esp+8h] [ebp-4h]

  _V_memset(dest: lfowavs, fill: 0, count: 72);
  for ( i = 0; i < 9; ++i )
  {
    v0 = nullptr;
    v1 = 0;
    v2 = dlys;
    while ( v2->fused )
    {
      ++v2;
      ++v1;
      if ( (int)v2 >= (int)flts )
        goto LABEL_8;
    }
    v0 = &dlys[v1];
    if ( v0 != nullptr )
      _V_memset(dest: &dlys[v1], fill: 0, count: 72);
LABEL_8:
    if ( v1 == 128 )
    {
      DevMsg(a1: "DSP: Warning, failed to allocate delay line.\n");
      v0 = nullptr;
    }
    else
    {
      v3 = (int *)MemAlloc_Alloc(nSize: 0x804u);
      v4 = v3;
      if ( v3 != nullptr )
      {
        _V_memset(dest: v3, fill: 0, count: 2052);
        v0->type = 0;
        v0->D = 512;
        v0->t = 512;
        v0->tnew = 512;
        v0->xf = 0;
        v0->D0 = 512;
        v0->p = v4;
        v0->w = v4;
        v0->a = 0;
        v0->b = 0;
        v0->fused = true;
        DLY_SetNormalizingGain(pdly: v0, feedback: 0);
      }
      else
      {
        _Warning(a1: "Sound DSP: Failed to lock.\n");
        pflt = v0->pflt;
        if ( pflt != nullptr )
        {
          pf1 = pflt->pf1;
          if ( pf1 != nullptr )
            _V_memset(dest: pf1, fill: 0, count: 184);
          pf2 = pflt->pf2;
          if ( pf2 != nullptr )
            _V_memset(dest: pf2, fill: 0, count: 184);
          pf3 = pflt->pf3;
          if ( pf3 != nullptr )
            _V_memset(dest: pf3, fill: 0, count: 184);
          _V_memset(dest: pflt, fill: 0, count: 184);
        }
        v0 = nullptr;
      }
    }
    w = v0->w;
    dword_10454424[2 * i] = (int)v0;
    lfowavs[i].type = i;
    LFOWAV_Fill(w, count: 512, type: i);
  }
  v9 = dword_10454424;
  do
  {
    if ( *v9 == 0 )
      LFOWAV_FreeAll();
    v9 += 2;
  }
  while ( (int)v9 < (int)&dfrs[0].n );
}

//------------------------------------------------------------------------------
// Address: 0x10026C40
// Name: struct ptc_t __near * PTC_Alloc(float,float,float)
// Source: json
//------------------------------------------------------------------------------
ptc_t *__cdecl PTC_Alloc(float timeslice, float timexfade, float fstep)
{
  int v3; // ecx
  ptc_t *v4; // eax
  ptc_t *v6; // edi
  double v7; // st7
  long double v8; // st6
  double v9; // st5
  long double v10; // st7
  long double v11; // rt2
  long double v12; // st6
  long double v13; // st7
  long double v14; // st3
  long double v15; // st5
  long double v16; // rt1
  long double v17; // st5
  long double v18; // st7
  int v19; // eax
  dly_t *v20; // esi
  int v21; // ebx
  dly_t *v22; // eax
  void *v23; // ebx
  flt_t *pflt; // esi
  flt_t *pf1; // eax
  flt_t *pf2; // eax
  flt_t *pf3; // eax
  dly_t *v28; // esi
  int v29; // ebx
  dly_t *v30; // eax
  void *v31; // ebx
  flt_t *v32; // esi
  flt_t *v33; // eax
  flt_t *v34; // eax
  flt_t *v35; // eax
  dly_t *pdly_in; // eax
  float v37; // xmm0_4
  float tslice; // [esp+0h] [ebp-4h]
  int cout; // [esp+Ch] [ebp+8h]
  int couta; // [esp+Ch] [ebp+8h]
  int cin; // [esp+10h] [ebp+Ch]

  v3 = 0;
  v4 = &ptcs[1];
  while ( v4[-1].fused )
  {
    if ( !v4->fused )
    {
      ++v3;
      break;
    }
    if ( !v4[1].fused )
    {
      v3 += 2;
      break;
    }
    if ( !v4[2].fused )
    {
      v3 += 3;
      break;
    }
    v4 += 4;
    v3 += 4;
    if ( (int)v4 >= (int)&lfos[1].pos )
      break;
  }
  if ( v3 == 64 )
  {
    DevMsg(a1: "DSP: Warning, failed to allocate pitch shifter.\n");
    return nullptr;
  }
  else
  {
    v6 = &ptcs[v3];
    if ( v6 != nullptr )
      _V_memset(dest: &ptcs[v3], fill: 0, count: 72);
    v7 = timeslice;
    v8 = fabs((fstep - 1.0) * timeslice);
    *(float *)&cout = v8;
    v9 = v7;
    v10 = 1.1 * v8;
    if ( v9 > v10 )
      v10 = v9;
    v11 = v8;
    v12 = v10;
    v13 = v11;
    tslice = v12;
    v14 = v11 * 0.9;
    v15 = timexfade;
    if ( v14 <= timexfade )
      v15 = v14;
    v16 = v15;
    v17 = v12 - v13;
    v18 = v16;
    if ( 0.9 * v17 <= v16 )
      v18 = 0.9 * v17;
    v6->cxfade = (int)(v18 * 44100.0 * 0.001);
    v19 = (int)(float)((float)(*(float *)&cout * 44100.0) * 0.001);
    v6->ccut = v19;
    v6->cduplicate = v19;
    cin = (int)(float)((float)(tslice * 44100.0) * 0.001);
    v20 = nullptr;
    couta = (int)(float)((float)((float)(tslice * fstep) * 44100.0) * 0.001);
    v21 = 0;
    v22 = dlys;
    while ( v22->fused )
    {
      ++v22;
      ++v21;
      if ( (int)v22 >= (int)flts )
        goto LABEL_27;
    }
    v20 = &dlys[v21];
    if ( v20 != nullptr )
      _V_memset(dest: &dlys[v21], fill: 0, count: 72);
LABEL_27:
    if ( v21 == 128 )
    {
      DevMsg(a1: "DSP: Warning, failed to allocate delay line.\n");
      v20 = nullptr;
    }
    else
    {
      v23 = MemAlloc_Alloc(nSize: (unsigned __int64)(unsigned int)(cin + 1) >> 30 != 0 ? -1 : 4 * (cin + 1));
      if ( v23 != nullptr )
      {
        _V_memset(dest: v23, fill: 0, count: 4 * cin + 4);
        v20->type = 3;
        v20->D = cin;
        v20->t = cin;
        v20->tnew = cin;
        v20->xf = 0;
        v20->D0 = cin;
        v20->p = (int *)v23;
        v20->w = (int *)v23;
        v20->fused = true;
        v20->a = 0;
        v20->b = 4096;
      }
      else
      {
        _Warning(a1: "Sound DSP: Failed to lock.\n");
        pflt = v20->pflt;
        if ( pflt != nullptr )
        {
          pf1 = pflt->pf1;
          if ( pf1 != nullptr )
            _V_memset(dest: pf1, fill: 0, count: 184);
          pf2 = pflt->pf2;
          if ( pf2 != nullptr )
            _V_memset(dest: pf2, fill: 0, count: 184);
          pf3 = pflt->pf3;
          if ( pf3 != nullptr )
            _V_memset(dest: pf3, fill: 0, count: 184);
          _V_memset(dest: pflt, fill: 0, count: 184);
        }
        v20 = nullptr;
      }
    }
    v6->pdly_in = v20;
    v28 = nullptr;
    v29 = 0;
    v30 = dlys;
    while ( v30->fused )
    {
      ++v30;
      ++v29;
      if ( (int)v30 >= (int)flts )
        goto LABEL_46;
    }
    v28 = &dlys[v29];
    if ( v28 != nullptr )
      _V_memset(dest: &dlys[v29], fill: 0, count: 72);
LABEL_46:
    if ( v29 == 128 )
    {
      DevMsg(a1: "DSP: Warning, failed to allocate delay line.\n");
      v28 = nullptr;
    }
    else
    {
      v31 = MemAlloc_Alloc(nSize: (unsigned __int64)(unsigned int)(couta + 1) >> 30 != 0 ? -1 : 4 * (couta + 1));
      if ( v31 != nullptr )
      {
        _V_memset(dest: v31, fill: 0, count: 4 * couta + 4);
        v28->type = 3;
        v28->D = couta;
        v28->t = couta;
        v28->tnew = couta;
        v28->xf = 0;
        v28->D0 = couta;
        v28->p = (int *)v31;
        v28->w = (int *)v31;
        v28->fused = true;
        v28->a = 0;
        v28->b = 4096;
      }
      else
      {
        _Warning(a1: "Sound DSP: Failed to lock.\n");
        v32 = v28->pflt;
        if ( v32 != nullptr )
        {
          v33 = v32->pf1;
          if ( v33 != nullptr )
            _V_memset(dest: v33, fill: 0, count: 184);
          v34 = v32->pf2;
          if ( v34 != nullptr )
            _V_memset(dest: v34, fill: 0, count: 184);
          v35 = v32->pf3;
          if ( v35 != nullptr )
            _V_memset(dest: v35, fill: 0, count: 184);
          _V_memset(dest: v32, fill: 0, count: 184);
        }
        v28 = nullptr;
      }
    }
    pdly_in = v6->pdly_in;
    v6->pdly_out = v28;
    if ( pdly_in != nullptr && v28 != nullptr )
    {
      v6->pin = pdly_in->w;
      v6->pout = v28->w;
      v6->iin = 0;
      v37 = fstep;
      if ( (int)fstep > 4095 )
        v37 = (float)(fstep - (float)(int)fstep) + 4095.0;
      v6->psn.p.cstep = 0;
      v6->psn.p.pos = 0;
      v6->psn.p.step = (int)(float)(v37 * 1048576.0);
      v6->psn.p.D = couta;
      v6->psn.fhitend = false;
      v6->fdup = fstep > 1.0;
      v6->cin = cin;
      v6->cout = couta;
      v6->fstep = fstep;
      v6->fused = true;
      return v6;
    }
    else
    {
      PTC_Free(pptc: v6);
      DevMsg(a1: "DSP: Warning, failed to allocate delay for pitch shifter.\n");
      return nullptr;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100270A0
// Name: struct crs_t __near * CRS_Alloc(int,float,float,float)
// Source: json
//------------------------------------------------------------------------------
crs_t *__cdecl CRS_Alloc(int lfotype, float fHz, float fdepth, float mix)
{
  int v4; // ecx
  crs_t *v5; // eax
  int v7; // ecx
  bool v8; // zf
  crs_t *v9; // ecx
  dly_t *v10; // esi
  int v11; // edi
  int v12; // ebx
  dly_t *v13; // eax
  void *v14; // ebx
  flt_t *pflt; // esi
  flt_t *pf1; // eax
  flt_t *pf2; // eax
  flt_t *pf3; // eax
  mdy_t *v19; // edi
  lfo_t *v20; // eax
  dly_t *pdly; // esi
  crs_t *pcrs; // [esp+1Ch] [ebp-4h]

  v4 = 0;
  v5 = &crss[1];
  while ( v5[-1].fused )
  {
    if ( !v5->fused )
    {
      ++v4;
      break;
    }
    if ( !v5[1].fused )
    {
      v4 += 2;
      break;
    }
    if ( !v5[2].fused )
    {
      v4 += 3;
      break;
    }
    v5 += 4;
    v4 += 4;
    if ( (int)v5 >= (int)&efos[0].thresh_off )
      break;
  }
  if ( v4 == 64 )
  {
    DevMsg(a1: "DSP: Warning, failed to allocate chorus.\n");
    return nullptr;
  }
  v7 = v4;
  v8 = &crss[v7] == nullptr;
  v9 = &crss[v7];
  pcrs = v9;
  if ( !v8 )
    _V_memset(dest: v9, fill: 0, count: 16);
  v10 = nullptr;
  v11 = (int)(float)(fdepth * 4410.0);
  v12 = 0;
  v13 = dlys;
  while ( v13->fused )
  {
    ++v13;
    ++v12;
    if ( (int)v13 >= (int)flts )
      goto LABEL_21;
  }
  v10 = &dlys[v12];
  if ( v10 != nullptr )
    _V_memset(dest: &dlys[v12], fill: 0, count: 72);
LABEL_21:
  if ( v12 == 128 )
  {
    DevMsg(a1: "DSP: Warning, failed to allocate delay line.\n");
    v10 = nullptr;
  }
  else
  {
    v14 = MemAlloc_Alloc(nSize: (unsigned __int64)(unsigned int)(v11 + 1) >> 30 != 0 ? -1 : 4 * (v11 + 1));
    if ( v14 != nullptr )
    {
      _V_memset(dest: v14, fill: 0, count: 4 * v11 + 4);
      v10->type = 3;
      v10->D = v11;
      v10->t = v11;
      v10->tnew = v11;
      v10->xf = 0;
      v10->D0 = v11;
      v10->p = (int *)v14;
      v10->w = (int *)v14;
      v10->fused = true;
      v10->a = 0;
      v10->b = 4096;
    }
    else
    {
      _Warning(a1: "Sound DSP: Failed to lock.\n");
      pflt = v10->pflt;
      if ( pflt != nullptr )
      {
        pf1 = pflt->pf1;
        if ( pf1 != nullptr )
          _V_memset(dest: pf1, fill: 0, count: 184);
        pf2 = pflt->pf2;
        if ( pf2 != nullptr )
          _V_memset(dest: pf2, fill: 0, count: 184);
        pf3 = pflt->pf3;
        if ( pf3 != nullptr )
          _V_memset(dest: pf3, fill: 0, count: 184);
        _V_memset(dest: pflt, fill: 0, count: 184);
      }
      v10 = nullptr;
    }
  }
  v19 = MDY_Alloc(pdly: v10, ramptime: 0.0049999999, modtime: 0.0, depth: 0.0, mix);
  v20 = LFO_Alloc(wtype: lfotype, freqHz: fHz, foneshot: false, gain: 1.0);
  if ( v20 != nullptr )
  {
    if ( v19 != nullptr )
    {
      pcrs->pmdy = v19;
      pcrs->plfo = v20;
      pcrs->fused = true;
      return pcrs;
    }
    _V_memset(dest: v20, fill: 0, count: 56);
  }
  else if ( v19 != nullptr )
  {
    pdly = v19->pdly;
    if ( pdly != nullptr )
    {
      FLT_Free(pf: pdly->pflt);
      if ( pdly->w != nullptr )
        free(pMem: pdly->w);
      _V_memset(dest: pdly, fill: 0, count: 72);
    }
    _V_memset(dest: v19, fill: 0, count: 76);
  }
  DevMsg(a1: "DSP: Warning, failed to allocate lfo or mdy for chorus.\n");
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10027310
// Name: void PRC_CheckParams(struct prc_t __near *,struct prm_rng_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl PRC_CheckParams(prc_t *pprc, prm_rng_t *prng)
{
  float *prm; // edi
  float *p_lo; // esi
  int iprm; // ebx
  float v5; // xmm0_4
  float v6; // xmm0_4
  float v7; // xmm1_4

  if ( prng->iprm > 0 )
  {
    prm = pprc->prm;
    p_lo = &prng[1].lo;
    iprm = prng->iprm;
    do
    {
      v5 = *prm;
      if ( *prm != 0.0 && (v5 > p_lo[1] || *p_lo > v5) )
      {
        DevMsg(a1: "DSP: Warning, clamping out of range parameter.\n");
        v6 = *prm;
        v7 = *p_lo;
        if ( *p_lo > *prm || (v7 = p_lo[1], v6 > v7) )
          v6 = v7;
        *prm = v6;
      }
      p_lo += 3;
      ++prm;
      --iprm;
    }
    while ( iprm != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10027390
// Name: bool DSP_CheckDspAutoEnabled(void)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl DSP_CheckDspAutoEnabled()
{
  return dsp_room.m_pParent != nullptr && dsp_room.m_pParent->m_Value.m_nValue == 1;
}

//------------------------------------------------------------------------------
// Address: 0x100273B0
// Name: int dsp_room_GetInt(void)
// Source: json
//------------------------------------------------------------------------------
int __cdecl dsp_room_GetInt()
{
  int result; // eax

  if ( dsp_room.m_pParent == nullptr )
    return 0;
  result = dsp_room.m_pParent->m_Value.m_nValue;
  if ( result != 1 )
    return result;
  if ( dsp_automatic.m_pParent != nullptr )
    return dsp_automatic.m_pParent->m_Value.m_nValue;
  else
    return 0;
}

//------------------------------------------------------------------------------
// Address: 0x100273E0
// Name: int Get_idsp_room(void)
// Source: json
//------------------------------------------------------------------------------
int __cdecl Get_idsp_room()
{
  if ( dsp_room.m_pParent != nullptr && dsp_room.m_pParent->m_Value.m_nValue == 1 )
    return idsp_automatic;
  else
    return idsp_room;
}

//------------------------------------------------------------------------------
// Address: 0x10027400
// Name: void ADSP_GetAutoShape(struct adsp_auto_params_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ADSP_GetAutoShape(adsp_auto_params_t *pa)
{
  char v1; // bl
  int height; // ecx
  int length; // edx
  double width; // st6
  double v5; // st5
  double v6; // st7
  int v7; // eax
  double v8; // st4
  float v9; // xmm4_4
  int v10; // ecx
  float v11; // xmm3_4
  float v12; // xmm2_4
  float v13; // xmm1_4
  int v14; // ecx
  double v15; // st6

  v1 = 0;
  if ( !pa->bskyabove )
  {
    height = pa->height;
    length = pa->length;
    if ( (double)height > (double)length * 3.0 )
    {
      pa->height = length;
      pa->length = height;
      v1 = 1;
      if ( das_debug.m_pParent != nullptr && das_debug.m_pParent->m_Value.m_nValue > 1 )
        DevMsg(a1: "VERTICAL SHAFT Detected \n");
    }
    width = (double)pa->width;
    v5 = (double)pa->length;
    v6 = 4.0 * width;
    if ( v5 > v6 && width <= 48.0 )
    {
      pa->shape = 1;
      ADSP_GetSize(pa);
      if ( das_debug.m_pParent != nullptr && das_debug.m_pParent->m_Value.m_nValue > 1 )
        DevMsg(a1: "DUCT Detected \n");
autoshape_exit:
      if ( v1 != 0 )
      {
        v7 = pa->height;
        pa->height = pa->length;
        pa->length = v7;
      }
      return;
    }
    if ( v5 <= width * 2.5 )
    {
      v8 = 96.0;
    }
    else
    {
      v8 = 96.0;
      if ( width > 48.0 && width <= 96.0 )
      {
        pa->shape = 2;
        ADSP_GetSize(pa);
        if ( das_debug.m_pParent != nullptr && das_debug.m_pParent->m_Value.m_nValue > 1 )
          DevMsg(a1: "HALL Detected \n");
        goto autoshape_exit;
      }
    }
    if ( v5 <= v6 || width <= v8 )
    {
      pa->shape = 0;
      ADSP_GetSize(pa);
      if ( das_debug.m_pParent != nullptr && das_debug.m_pParent->m_Value.m_nValue > 1 )
        DevMsg(a1: "ROOM Detected \n");
    }
    else
    {
      pa->shape = 3;
      ADSP_GetSize(pa);
      if ( das_debug.m_pParent != nullptr && das_debug.m_pParent->m_Value.m_nValue > 1 )
        DevMsg(a1: "TUNNEL Detected \n");
    }
    goto autoshape_exit;
  }
  v9 = pa->surface_refl[0];
  v10 = v9 == 0.0;
  v11 = pa->surface_refl[1];
  if ( v11 == 0.0 )
    ++v10;
  v12 = pa->surface_refl[2];
  if ( v12 == 0.0 )
    ++v10;
  v13 = pa->surface_refl[3];
  if ( v13 == 0.0 )
    ++v10;
  if ( v10 <= 0 )
  {
    v15 = (double)pa->width;
    if ( 2.5 * v15 < (double)pa->length )
    {
      if ( v15 > 144.0 )
      {
        pa->shape = 4;
        ADSP_GetSize(pa);
        if ( das_debug.m_pParent != nullptr && das_debug.m_pParent->m_Value.m_nValue > 1 )
          DevMsg(a1: "OUTSIDE STREET Detected \n");
      }
      else
      {
        pa->shape = 5;
        ADSP_GetSize(pa);
        if ( das_debug.m_pParent != nullptr && das_debug.m_pParent->m_Value.m_nValue > 1 )
          DevMsg(a1: "OUTSIDE ALLEY Detected \n");
      }
    }
    else
    {
      pa->shape = 6;
      ADSP_GetSize(pa);
      if ( das_debug.m_pParent != nullptr && das_debug.m_pParent->m_Value.m_nValue > 1 )
        DevMsg(a1: "OUTSIDE COURTYARD Detected \n");
    }
  }
  else
  {
    v14 = v9 == 0.0;
    if ( v11 == 0.0 )
      ++v14;
    if ( v12 == 0.0 )
      ++v14;
    if ( v13 == 0.0 )
      ++v14;
    pa->shape = 11 - v14;
    ADSP_GetSize(pa);
    if ( das_debug.m_pParent != nullptr && das_debug.m_pParent->m_Value.m_nValue > 1 )
      DevMsg(a1: "OPEN SIDED OUTDOOR AREA Detected \n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x10027730
// Name: void ADSP_InterpolatePreset(struct pset_t __near *,struct pset_t __near *,struct pset_t __near *,struct adsp_auto_params_t __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ADSP_InterpolatePreset(pset_t *pnew, pset_t *pmin, pset_t *pmax, adsp_auto_params_t *pa, int iskip)
{
  pset_t *v5; // esi
  int j; // esi
  double v8; // st7
  double v9; // st7
  double v10; // st4
  double v11; // st3
  double v12; // st5
  double v13; // st5
  double v14; // st6
  double v15; // rtt
  double v16; // st4
  double v17; // st5
  double v18; // st6
  double v19; // st7
  double v20; // rt0
  double v21; // st5
  double v22; // st6
  double v23; // rt1
  double v24; // st7
  double v25; // st4
  double v26; // st7
  double v27; // st3
  double v28; // st3
  double v29; // st6
  double v30; // st5
  double v31; // st4
  double v32; // st7
  float value; // [esp+0h] [ebp-18h]
  float valuea; // [esp+0h] [ebp-18h]
  float valueb; // [esp+0h] [ebp-18h]
  float valuec; // [esp+0h] [ebp-18h]
  float ij; // [esp+30h] [ebp+18h]
  int i; // [esp+30h] [ebp+18h]
  int ia; // [esp+30h] [ebp+18h]
  int ib; // [esp+30h] [ebp+18h]
  int ic; // [esp+30h] [ebp+18h]
  int id; // [esp+30h] [ebp+18h]
  int ie; // [esp+30h] [ebp+18h]
  int ig; // [esp+30h] [ebp+18h]
  int ih; // [esp+30h] [ebp+18h]
  int ii; // [esp+30h] [ebp+18h]

  if ( iskip == 0 )
  {
    v5 = pmax;
    if ( pa->size <= 1 )
      v5 = pmin;
    *pnew = *v5;
  }
  for ( j = 0; j < 4; ++j )
    ADSP_InterpParam(
      pnew,
      pmin,
      pmax,
      proc_type: 10,
      skipprocs: iskip,
      iparam: j,
      index: pa->size,
      index_max: 5,
      bexp: false);
  ADSP_InterpParam(
    pnew,
    pmin,
    pmax,
    proc_type: 2,
    skipprocs: iskip,
    iparam: 3,
    index: pa->size,
    index_max: 5,
    bexp: false);
  ADSP_InterpParam(
    pnew,
    pmin,
    pmax,
    proc_type: 2,
    skipprocs: iskip,
    iparam: 1,
    index: pa->size,
    index_max: 5,
    bexp: true);
  ADSP_InterpParam(
    pnew,
    pmin,
    pmax,
    proc_type: 2,
    skipprocs: iskip,
    iparam: 0,
    index: pa->size,
    index_max: 5,
    bexp: true);
  ADSP_InterpParam(
    pnew,
    pmin,
    pmax,
    proc_type: 2,
    skipprocs: iskip,
    iparam: 4,
    index: pa->size,
    index_max: 5,
    bexp: false);
  ADSP_InterpParam(
    pnew,
    pmin,
    pmax,
    proc_type: 2,
    skipprocs: iskip,
    iparam: 2,
    index: pa->size,
    index_max: 5,
    bexp: false);
  ADSP_InterpParam(
    pnew,
    pmin,
    pmax,
    proc_type: 2,
    skipprocs: iskip,
    iparam: 7,
    index: pa->size,
    index_max: 5,
    bexp: false);
  ADSP_InterpParam(
    pnew,
    pmin,
    pmax,
    proc_type: 2,
    skipprocs: iskip,
    iparam: 8,
    index: pa->size,
    index_max: 5,
    bexp: false);
  v8 = (double)pa->width * 0.083333336;
  if ( v8 >= 6.0 )
  {
    v10 = v8;
    v9 = 500.0;
    if ( v10 > 500.0 )
      v10 = 500.0;
  }
  else
  {
    v9 = 500.0;
    v10 = 6.0;
  }
  v11 = 6.0;
  v12 = (double)pa->length * 0.083333336;
  if ( v12 >= 6.0 )
  {
    v11 = v12;
    v13 = 6.0;
    if ( v11 > v9 )
      v11 = v9;
  }
  else
  {
    v13 = 6.0;
  }
  v14 = 0.083333336 * (double)pa->height;
  v15 = v10;
  v16 = v13;
  v17 = v15;
  if ( v16 <= v14 )
  {
    v20 = v17;
    v21 = v14;
    v22 = v20;
    if ( v21 <= v9 )
      v9 = v21;
    v23 = v22;
    v18 = v9;
    v19 = v23;
  }
  else
  {
    v18 = v16;
    v19 = v17;
  }
  value = v19;
  ADSP_SetParamIfNegative(
    pnew,
    pmin,
    pmax,
    proc_type: 2,
    skipprocs: iskip,
    iparam: 9,
    index: pa->wid,
    index_max: 5,
    bexp: true,
    value);
  ij = v11;
  ADSP_SetParamIfNegative(
    pnew,
    pmin,
    pmax,
    proc_type: 2,
    skipprocs: iskip,
    iparam: 10,
    index: pa->len,
    index_max: 5,
    bexp: true,
    value: ij);
  valuea = v18;
  ADSP_SetParamIfNegative(
    pnew,
    pmin,
    pmax,
    proc_type: 2,
    skipprocs: iskip,
    iparam: 11,
    index: pa->ht,
    index_max: 5,
    bexp: true,
    value: valuea);
  ADSP_InterpParam(
    pnew,
    pmin,
    pmax,
    proc_type: 2,
    skipprocs: iskip,
    iparam: 12,
    index: pa->wid,
    index_max: 5,
    bexp: false);
  ADSP_InterpParam(
    pnew,
    pmin,
    pmax,
    proc_type: 2,
    skipprocs: iskip,
    iparam: 13,
    index: pa->len,
    index_max: 5,
    bexp: false);
  ADSP_InterpParam(
    pnew,
    pmin,
    pmax,
    proc_type: 2,
    skipprocs: iskip,
    iparam: 14,
    index: pa->ht,
    index_max: 5,
    bexp: false);
  ADSP_InterpParam(
    pnew,
    pmin: pmax,
    pmax: pmin,
    proc_type: 2,
    skipprocs: iskip,
    iparam: 5,
    index: pa->reflectivity,
    index_max: 4,
    bexp: false);
  v24 = (double)pa->length * 2.0 * 0.08333333333333333;
  v25 = 14.0;
  if ( v24 >= 14.0 )
  {
    v28 = v24;
    if ( v24 > 500.0 )
      v28 = 500.0;
    v25 = v28;
    v27 = 500.0;
    v26 = 14.0;
  }
  else
  {
    v26 = 14.0;
    v27 = 500.0;
  }
  *(float *)&i = v25;
  v29 = v25;
  v30 = 0.08333333333333333 * (2.0 * (double)pa->width);
  v31 = v26;
  v32 = v27;
  if ( v31 <= v30 )
  {
    if ( v30 > v27 )
      goto LABEL_28;
  }
  else
  {
    v30 = v31;
  }
  v32 = v30;
LABEL_28:
  valueb = v29;
  ADSP_SetParamIfNegative(
    pnew,
    pmin,
    pmax,
    proc_type: 1,
    skipprocs: iskip,
    iparam: 1,
    index: pa->len,
    index_max: 5,
    bexp: true,
    value: valueb);
  ADSP_InterpParam(
    pnew,
    pmin,
    pmax,
    proc_type: 1,
    skipprocs: iskip,
    iparam: 2,
    index: pa->len,
    index_max: 5,
    bexp: false);
  ADSP_InterpParam(
    pnew,
    pmin,
    pmax,
    proc_type: 1,
    skipprocs: iskip,
    iparam: 3,
    index: pa->len,
    index_max: 5,
    bexp: false);
  valuec = v32;
  ADSP_SetParamIfNegative(
    pnew,
    pmin,
    pmax,
    proc_type: 1,
    skipprocs: iskip,
    iparam: 8,
    index: pa->len,
    index_max: 5,
    bexp: true,
    value: valuec);
  ADSP_SetParamIfNegative(
    pnew,
    pmin,
    pmax,
    proc_type: 1,
    skipprocs: iskip,
    iparam: 9,
    index: pa->len,
    index_max: 5,
    bexp: true,
    value: *(float *)&i);
  ADSP_SetParamIfNegative(
    pnew,
    pmin,
    pmax,
    proc_type: 1,
    skipprocs: iskip,
    iparam: 10,
    index: pa->len,
    index_max: 5,
    bexp: true,
    value: *(float *)&i);
  ADSP_InterpParam(
    pnew,
    pmin: pmax,
    pmax: pmin,
    proc_type: 1,
    skipprocs: iskip,
    iparam: 5,
    index: pa->len,
    index_max: 5,
    bexp: false);
  ADSP_InterpParam(
    pnew,
    pmin: pmax,
    pmax: pmin,
    proc_type: 1,
    skipprocs: iskip,
    iparam: 6,
    index: pa->len,
    index_max: 5,
    bexp: false);
  for ( ia = 0; ia < 13; ++ia )
    ADSP_InterpParam(
      pnew,
      pmin,
      pmax,
      proc_type: 9,
      skipprocs: iskip,
      iparam: ia,
      index: pa->len,
      index_max: 5,
      bexp: false);
  for ( ib = 0; ib < 8; ++ib )
    ADSP_InterpParam(
      pnew,
      pmin,
      pmax,
      proc_type: 11,
      skipprocs: iskip,
      iparam: ib,
      index: pa->size,
      index_max: 5,
      bexp: false);
  for ( ic = 0; ic < 5; ++ic )
    ADSP_InterpParam(
      pnew,
      pmin,
      pmax,
      proc_type: 3,
      skipprocs: iskip,
      iparam: ic,
      index: pa->size,
      index_max: 5,
      bexp: false);
  for ( id = 0; id < 3; ++id )
    ADSP_InterpParam(
      pnew,
      pmin,
      pmax,
      proc_type: 5,
      skipprocs: iskip,
      iparam: id,
      index: pa->size,
      index_max: 5,
      bexp: false);
  for ( ie = 0; ie < 4; ++ie )
    ADSP_InterpParam(
      pnew,
      pmin,
      pmax,
      proc_type: 4,
      skipprocs: iskip,
      iparam: ie,
      index: pa->size,
      index_max: 5,
      bexp: false);
  for ( ig = 0; ig < 9; ++ig )
    ADSP_InterpParam(
      pnew,
      pmin,
      pmax,
      proc_type: 6,
      skipprocs: iskip,
      iparam: ig,
      index: pa->size,
      index_max: 5,
      bexp: false);
  for ( ih = 0; ih < 4; ++ih )
    ADSP_InterpParam(
      pnew,
      pmin,
      pmax,
      proc_type: 8,
      skipprocs: iskip,
      iparam: ih,
      index: pa->size,
      index_max: 5,
      bexp: false);
  for ( ii = 0; ii < 4; ++ii )
    ADSP_InterpParam(
      pnew,
      pmin,
      pmax,
      proc_type: 7,
      skipprocs: iskip,
      iparam: ii,
      index: pa->size,
      index_max: 5,
      bexp: false);
}

//------------------------------------------------------------------------------
// Address: 0x10027CD0
// Name: int DSP_ConstructPreset(bool,int,int,int,float,float,float __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl DSP_ConstructPreset(
        bool bskyabove,
        int width,
        int length,
        int height,
        float fdiffusion,
        float freflectivity,
        float *psurf_refl,
        int inode)
{
  float v9; // xmm0_4
  ConVar *m_pParent; // eax
  int m_nValue; // eax
  pset_t *v12; // ebx
  pset_t new_pset; // [esp+0h] [ebp-694h] BYREF
  pset_t pset_min; // [esp+218h] [ebp-47Ch] BYREF
  pset_t pset_max; // [esp+430h] [ebp-264h] BYREF
  adsp_auto_params_t ap; // [esp+648h] [ebp-4Ch] BYREF

  if ( inode >= 40 )
    return 0;
  ap.fdiffusion = fdiffusion;
  ap.width = width;
  ap.freflectivity = freflectivity;
  ap.height = height;
  ap.surface_refl[0] = *psurf_refl;
  ap.surface_refl[1] = psurf_refl[1];
  ap.surface_refl[2] = psurf_refl[2];
  ap.surface_refl[3] = psurf_refl[3];
  ap.surface_refl[4] = psurf_refl[4];
  v9 = psurf_refl[5];
  ap.bskyabove = bskyabove;
  ap.length = length;
  ap.surface_refl[5] = v9;
  if ( bskyabove )
    ap.surface_refl[4] = 0.0;
  ADSP_GetAutoShape(pa: &ap);
  switch ( ap.shape )
  {
    case 1:
      m_pParent = adsp_duct_min.m_pParent;
      break;
    case 2:
      m_pParent = adsp_hall_min.m_pParent;
      break;
    case 3:
      m_pParent = adsp_tunnel_min.m_pParent;
      break;
    case 4:
      m_pParent = adsp_street_min.m_pParent;
      break;
    case 5:
      m_pParent = adsp_alley_min.m_pParent;
      break;
    case 6:
      m_pParent = adsp_courtyard_min.m_pParent;
      break;
    case 7:
      m_pParent = adsp_openspace_min.m_pParent;
      break;
    case 8:
      m_pParent = adsp_openwall_min.m_pParent;
      break;
    case 9:
      m_pParent = adsp_openstreet_min.m_pParent;
      break;
    case 0xA:
      m_pParent = adsp_opencourtyard_min.m_pParent;
      break;
    default:
      m_pParent = adsp_room_min.m_pParent;
      break;
  }
  if ( m_pParent != nullptr )
    m_nValue = m_pParent->m_Value.m_nValue;
  else
    m_nValue = 0;
  if ( ap.diffusion > 1 )
    m_nValue += 2;
  v12 = g_psettemplates;
  pset_min = g_psettemplates[m_nValue];
  pset_max = g_psettemplates[m_nValue + 1];
  if ( das_debug.m_pParent != nullptr && das_debug.m_pParent->m_Value.m_nValue != 0 )
  {
    DevMsg(a1: "DAS: Min Preset Index: %i\nDAS: Max Preset Index: %i\n", m_nValue, m_nValue + 1);
    v12 = g_psettemplates;
  }
  ADSP_InterpolatePreset(pnew: &new_pset, pmin: &pset_min, pmax: &pset_max, pa: &ap, iskip: 0);
  ADSP_InterpolatePreset(pnew: &new_pset, pmin: &pset_min, pmax: &pset_max, pa: &ap, iskip: 1);
  v12[inode + 60] = new_pset;
  return inode + 60;
}

//------------------------------------------------------------------------------
// Address: 0x10027ED0
// Name: bool DSP_RoomDSPIsOff(void)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl DSP_RoomDSPIsOff()
{
  unsigned int v0; // eax
  dsp_t *v1; // eax
  bool result; // al

  if ( dsp_room.m_pParent != nullptr && dsp_room.m_pParent->m_Value.m_nValue == 1 )
    v0 = idsp_automatic;
  else
    v0 = idsp_room;
  result = true;
  if ( v0 <= 0x1F )
  {
    v1 = &dsps[v0];
    if ( v1->ipset != 0 || v1->ipsetprev != 0 )
      return false;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10027F10
// Name: _FreeDsps
// Source: json
//------------------------------------------------------------------------------
void __cdecl FreeDsps(bool bReleaseTemplateMemory)
{
  DSP_Free(idsp: (dsp_t *)idsp_room);
  DSP_Free(idsp: (dsp_t *)idsp_water);
  DSP_Free(idsp: (dsp_t *)idsp_player);
  DSP_Free(idsp: (dsp_t *)idsp_facingaway);
  DSP_Free(idsp: (dsp_t *)idsp_speaker);
  DSP_Free(idsp: (dsp_t *)idsp_spatial);
  DSP_Free(idsp: (dsp_t *)idsp_automatic);
  idsp_room = 0;
  idsp_water = 0;
  idsp_player = 0;
  idsp_facingaway = 0;
  idsp_speaker = 0;
  idsp_spatial = 0;
  idsp_automatic = 0;
  DSP_FreeAll();
  if ( bReleaseTemplateMemory && g_psettemplates != nullptr )
  {
    free(pMem: g_psettemplates);
    g_psettemplates = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10027FC0
// Name: snd_print_dsp_effect
// Source: json
//------------------------------------------------------------------------------
void __cdecl snd_print_dsp_effect(const CCommand *args)
{
  unsigned int v1; // eax

  if ( args->m_nArgc == 2 )
  {
    v1 = atoi(nptr: args->m_ppArgv[1]);
    if ( v1 > 0x1F )
      _Warning(a1: "DSP index is out of range. It should be between 0 and %d.\n", 32);
    else
      DSP_Print(dsp: &dsps[v1], nIndentation: 0);
  }
  else
  {
    _Warning(a1: "Incorrect usage of snd_print_dsp_effect. snd_print_dsp_effect <dspindex>.\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x10028020
// Name: void DelayAllpass_Opt3<2,0>(int,int,int __near *,int __near * __near *,int,int,int __near *,int __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DelayAllpass_Opt3<2,0>(
        int nDelaySize,
        int tdelay,
        int *psamps,
        int **ppsamp,
        int fbgain,
        int outgain,
        int *pIn,
        int *pOut,
        unsigned int nCount)
{
  int v9; // edx
  int *v10; // ecx
  int v11; // ebx
  int v12; // esi
  int v13; // eax
  int *v14; // edi
  int *v15; // eax
  int *v16; // edi
  int v17; // eax
  int v18; // ecx
  int v19; // edx
  int v20; // esi
  bool v21; // zf
  int sDD; // [esp+0h] [ebp-2Ch]
  int sDB; // [esp+4h] [ebp-28h]
  unsigned int v24; // [esp+Ch] [ebp-20h]
  _DWORD *v25; // [esp+10h] [ebp-1Ch]
  int sDC; // [esp+14h] [ebp-18h]
  int sDA; // [esp+18h] [ebp-14h]
  int *pSampsPDelaySize; // [esp+1Ch] [ebp-10h]
  int *pDelaySampleA; // [esp+20h] [ebp-Ch]
  int *pDelaySampleD; // [esp+24h] [ebp-8h]
  int *pDelaySampleC; // [esp+28h] [ebp-4h]
  int sDa; // [esp+38h] [ebp+Ch]
  int *sD; // [esp+38h] [ebp+Ch]

  v9 = nDelaySize;
  if ( nDelaySize == tdelay )
  {
    v10 = *ppsamp;
    v11 = fbgain;
    pSampsPDelaySize = &psamps[nDelaySize];
    v12 = nDelaySize + 1;
    if ( (nCount & 3) != 0 )
    {
      do
      {
        sDa = v10[nDelaySize - (v12 & (((char *)pSampsPDelaySize - (char *)&v10[nDelaySize]) >> 31))];
        v13 = *pIn + ((fbgain * sDa) >> 12);
        --nCount;
        *v10 = v13;
        pIn += 2;
        v12 = nDelaySize + 1;
        v10 = &v10[((nDelaySize + 1) & (((char *)(v10 - 1) - (char *)psamps) >> 31)) - 1];
        *pOut += (outgain * (sDa + (-(fbgain * v13) >> 12))) >> 12;
        v14 = ++pOut;
      }
      while ( (nCount & 3) != 0 );
    }
    else
    {
      v14 = pOut;
    }
    pDelaySampleA = v10;
    sD = &v10[(v12 & (((char *)(v10 - 1) - (char *)psamps) >> 31)) - 1];
    pDelaySampleC = &v10[(v12 & (((char *)(v10 - 2) - (char *)psamps) >> 31)) - 2];
    v15 = &v10[(v12 & (((char *)(v10 - 3) - (char *)psamps) >> 31)) - 3];
    pDelaySampleD = v15;
    if ( (int)nCount >= 4 )
    {
      v25 = v14 + 2;
      v16 = pIn + 4;
      v24 = nCount >> 2;
      while ( 1 )
      {
        sDC = *v15;
        sDA = *sD;
        sDB = *pDelaySampleC;
        sDD = v15[v9 - ((v9 + 1) & (((char *)pSampsPDelaySize - (char *)&v15[v9]) >> 31))];
        v17 = *(v16 - 4) + ((v11 * *sD) >> 12);
        v18 = *(v16 - 2) + ((v11 * *pDelaySampleC) >> 12);
        *pDelaySampleA = v17;
        *sD = v18;
        v19 = *v16 + ((v11 * sDC) >> 12);
        v20 = v16[2] + ((v11 * sDD) >> 12);
        *pDelaySampleC = v19;
        *pDelaySampleD = v20;
        pDelaySampleA = &pDelaySampleA[((nDelaySize + 1) & (((char *)(pDelaySampleA - 4) - (char *)psamps) >> 31)) - 4];
        sD = &sD[((nDelaySize + 1) & (((char *)(sD - 4) - (char *)psamps) >> 31)) - 4];
        pDelaySampleC = &pDelaySampleC[((nDelaySize + 1) & (((char *)(pDelaySampleC - 4) - (char *)psamps) >> 31)) - 4];
        v11 = fbgain;
        pDelaySampleD = &pDelaySampleD[((nDelaySize + 1) & (((char *)(pDelaySampleD - 4) - (char *)psamps) >> 31)) - 4];
        *(v25 - 2) += (outgain * (sDA + (-(fbgain * v17) >> 12))) >> 12;
        *(v25 - 1) += (outgain * (sDB + (-(fbgain * v18) >> 12))) >> 12;
        *v25 += (outgain * (sDC + (-(fbgain * v19) >> 12))) >> 12;
        v25[1] += (outgain * (sDD + (-(fbgain * v20) >> 12))) >> 12;
        v21 = v24-- == 1;
        v25 += 4;
        if ( v21 )
          break;
        v9 = nDelaySize;
        v16 += 8;
        v15 = pDelaySampleD;
      }
    }
    *ppsamp = pDelaySampleA;
  }
  else
  {
    DelayAllpass_Opt2<2,0>((int *)nDelaySize, tdelay, psamps, ppsamp, fbgain, outgain, pIn, pOut, nCount);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100282C0
// Name: void DelayAllpass_Opt3<2,1>(int,int,int __near *,int __near * __near *,int,int,int __near *,int __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DelayAllpass_Opt3<2,1>(
        int nDelaySize,
        int tdelay,
        int *psamps,
        int **ppsamp,
        int fbgain,
        int outgain,
        int *pIn,
        int *pOut,
        unsigned int nCount)
{
  int v9; // edx
  int *v10; // ecx
  int *v11; // ebx
  int v12; // edi
  int v13; // esi
  int v14; // eax
  int *v15; // eax
  int *v16; // ebx
  int v17; // ecx
  int v18; // eax
  int v19; // ecx
  int v20; // edx
  int v21; // esi
  bool v22; // zf
  int sDD; // [esp+0h] [ebp-2Ch]
  int sDB; // [esp+4h] [ebp-28h]
  unsigned int v25; // [esp+Ch] [ebp-20h]
  int *v26; // [esp+10h] [ebp-1Ch]
  int sDC; // [esp+14h] [ebp-18h]
  int sDA; // [esp+18h] [ebp-14h]
  int *pSampsPDelaySize; // [esp+1Ch] [ebp-10h]
  int *pDelaySampleA; // [esp+20h] [ebp-Ch]
  int *pDelaySampleD; // [esp+24h] [ebp-8h]
  int *pDelaySampleC; // [esp+28h] [ebp-4h]
  int sDa; // [esp+38h] [ebp+Ch]
  int *sD; // [esp+38h] [ebp+Ch]

  v9 = nDelaySize;
  if ( nDelaySize == tdelay )
  {
    v10 = *ppsamp;
    v11 = psamps;
    v12 = fbgain;
    pSampsPDelaySize = &psamps[nDelaySize];
    v13 = nDelaySize + 1;
    if ( (nCount & 3) != 0 )
    {
      do
      {
        sDa = v10[nDelaySize - (v13 & (((char *)pSampsPDelaySize - (char *)&v10[nDelaySize]) >> 31))];
        v14 = *pIn + ((fbgain * sDa) >> 12);
        --nCount;
        *v10 = v14;
        pIn += 2;
        v13 = nDelaySize + 1;
        v10 = &v10[((nDelaySize + 1) & (((char *)(v10 - 1) - (char *)psamps) >> 31)) - 1];
        *pOut++ = (outgain * (sDa + (-(fbgain * v14) >> 12))) >> 12;
      }
      while ( (nCount & 3) != 0 );
      v11 = psamps;
    }
    pDelaySampleA = v10;
    sD = &v10[(v13 & (((char *)(v10 - 1) - (char *)v11) >> 31)) - 1];
    pDelaySampleC = &v10[(v13 & (((char *)(v10 - 2) - (char *)v11) >> 31)) - 2];
    v15 = &v10[(v13 & (((char *)(v10 - 3) - (char *)v11) >> 31)) - 3];
    pDelaySampleD = v15;
    if ( (int)nCount >= 4 )
    {
      v16 = pIn + 4;
      v26 = pOut + 2;
      v25 = nCount >> 2;
      while ( 1 )
      {
        sDC = *v15;
        sDA = *sD;
        sDB = *pDelaySampleC;
        v17 = v12 * *pDelaySampleC;
        sDD = v15[v9 - ((v9 + 1) & (((char *)pSampsPDelaySize - (char *)&v15[v9]) >> 31))];
        v18 = *(v16 - 4) + ((v12 * *sD) >> 12);
        v16 += 8;
        *pDelaySampleA = v18;
        v19 = *(v16 - 10) + (v17 >> 12);
        *sD = v19;
        v20 = *(v16 - 8) + ((v12 * sDC) >> 12);
        v21 = *(v16 - 6) + ((v12 * sDD) >> 12);
        *pDelaySampleC = v20;
        *pDelaySampleD = v21;
        pDelaySampleA = &pDelaySampleA[((nDelaySize + 1) & (((char *)(pDelaySampleA - 4) - (char *)psamps) >> 31)) - 4];
        sD = &sD[((nDelaySize + 1) & (((char *)(sD - 4) - (char *)psamps) >> 31)) - 4];
        pDelaySampleC = &pDelaySampleC[((nDelaySize + 1) & (((char *)(pDelaySampleC - 4) - (char *)psamps) >> 31)) - 4];
        pDelaySampleD = &pDelaySampleD[((nDelaySize + 1) & (((char *)(pDelaySampleD - 4) - (char *)psamps) >> 31)) - 4];
        v12 = fbgain;
        *(v26 - 2) = (outgain * (sDA + (-(fbgain * v18) >> 12))) >> 12;
        *(v26 - 1) = (outgain * (sDB + (-(fbgain * v19) >> 12))) >> 12;
        *v26 = (outgain * (sDC + (-(fbgain * v20) >> 12))) >> 12;
        v26[1] = (outgain * (sDD + (-(fbgain * v21) >> 12))) >> 12;
        v22 = v25-- == 1;
        v26 += 4;
        if ( v22 )
          break;
        v9 = nDelaySize;
        v15 = pDelaySampleD;
      }
    }
    *ppsamp = pDelaySampleA;
  }
  else
  {
    DelayAllpass_Opt2<2,1>((int *)nDelaySize, tdelay, psamps, ppsamp, fbgain, outgain, pIn, pOut, nCount);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10028560
// Name: void DelayAllpass_Opt3<1,1>(int,int,int __near *,int __near * __near *,int,int,int __near *,int __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DelayAllpass_Opt3<1,1>(
        int nDelaySize,
        int tdelay,
        int *psamps,
        int **ppsamp,
        int fbgain,
        int outgain,
        int *pIn,
        int *pOut,
        unsigned int nCount)
{
  int v9; // edx
  int *v10; // ecx
  int *v11; // ebx
  int v12; // edi
  int v13; // esi
  int v14; // eax
  int *v15; // eax
  int *v16; // ebx
  int v17; // eax
  int v18; // ecx
  int v19; // edx
  int v20; // esi
  bool v21; // zf
  int sDD; // [esp+0h] [ebp-30h]
  int sDB; // [esp+4h] [ebp-2Ch]
  unsigned int v24; // [esp+Ch] [ebp-24h]
  int *v25; // [esp+10h] [ebp-20h]
  int *v26; // [esp+14h] [ebp-1Ch]
  int sDC; // [esp+18h] [ebp-18h]
  int sDA; // [esp+1Ch] [ebp-14h]
  int *pSampsPDelaySize; // [esp+20h] [ebp-10h]
  int *pDelaySampleA; // [esp+24h] [ebp-Ch]
  int *pDelaySampleAa; // [esp+24h] [ebp-Ch]
  int *pDelaySampleD; // [esp+28h] [ebp-8h]
  int *pDelaySampleC; // [esp+2Ch] [ebp-4h]
  int sDa; // [esp+3Ch] [ebp+Ch]
  int *sD; // [esp+3Ch] [ebp+Ch]

  v9 = nDelaySize;
  if ( nDelaySize == tdelay )
  {
    v10 = *ppsamp;
    v11 = psamps;
    v12 = fbgain;
    pSampsPDelaySize = &psamps[nDelaySize];
    v13 = nDelaySize + 1;
    if ( (nCount & 3) != 0 )
    {
      do
      {
        sDa = v10[nDelaySize - (v13 & (((char *)pSampsPDelaySize - (char *)&v10[nDelaySize]) >> 31))];
        v14 = *pIn + ((fbgain * sDa) >> 12);
        --nCount;
        *v10 = v14;
        ++pIn;
        v13 = nDelaySize + 1;
        v10 = &v10[((nDelaySize + 1) & (((char *)(v10 - 1) - (char *)psamps) >> 31)) - 1];
        *pOut++ = (outgain * (sDa + (-(fbgain * v14) >> 12))) >> 12;
      }
      while ( (nCount & 3) != 0 );
      v11 = psamps;
    }
    pDelaySampleA = v10;
    sD = &v10[(v13 & (((char *)(v10 - 1) - (char *)v11) >> 31)) - 1];
    pDelaySampleC = &v10[(v13 & (((char *)(v10 - 2) - (char *)v11) >> 31)) - 2];
    v15 = &v10[(v13 & (((char *)(v10 - 3) - (char *)v11) >> 31)) - 3];
    pDelaySampleD = v15;
    if ( (int)nCount >= 4 )
    {
      v25 = pOut + 2;
      v16 = pIn + 2;
      v26 = pIn + 2;
      v24 = nCount >> 2;
      while ( 1 )
      {
        sDC = *v15;
        sDA = *sD;
        sDB = *pDelaySampleC;
        sDD = v15[v9 - ((v9 + 1) & (((char *)pSampsPDelaySize - (char *)&v15[v9]) >> 31))];
        pDelaySampleAa = pDelaySampleA - 4;
        v17 = *(v16 - 2) + ((v12 * *sD) >> 12);
        v18 = *(v16 - 1) + ((v12 * *pDelaySampleC) >> 12);
        pDelaySampleAa[4] = v17;
        v19 = *v16 + ((v12 * sDC) >> 12);
        v20 = v16[1] + ((v12 * sDD) >> 12);
        *sD = v18;
        *pDelaySampleC = v19;
        *pDelaySampleD = v20;
        pDelaySampleA = &pDelaySampleAa[(nDelaySize + 1) & (((char *)pDelaySampleAa - (char *)psamps) >> 31)];
        sD = &sD[((nDelaySize + 1) & (((char *)(sD - 4) - (char *)psamps) >> 31)) - 4];
        pDelaySampleC = &pDelaySampleC[((nDelaySize + 1) & (((char *)(pDelaySampleC - 4) - (char *)psamps) >> 31)) - 4];
        pDelaySampleD = &pDelaySampleD[((nDelaySize + 1) & (((char *)(pDelaySampleD - 4) - (char *)psamps) >> 31)) - 4];
        *(int *)((char *)v26 + (char *)pOut - (char *)pIn - 8) = (outgain * (sDA + (-(fbgain * v17) >> 12))) >> 12;
        v12 = fbgain;
        *(v25 - 1) = (outgain * (sDB + (-(fbgain * v18) >> 12))) >> 12;
        *v25 = (outgain * (sDC + (-(fbgain * v19) >> 12))) >> 12;
        v25[1] = (outgain * (sDD + (-(fbgain * v20) >> 12))) >> 12;
        v16 = v26 + 4;
        v21 = v24-- == 1;
        v26 += 4;
        v25 += 4;
        if ( v21 )
          break;
        v9 = nDelaySize;
        v15 = pDelaySampleD;
      }
    }
    *ppsamp = pDelaySampleA;
  }
  else
  {
    DelayAllpass_Opt2<1,1>((int *)nDelaySize, tdelay, psamps, ppsamp, fbgain, outgain, pIn, pOut, nCount);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10028810
// Name: void __near * FLT_VParams(void __near *)
// Source: json
//------------------------------------------------------------------------------
flt_t *__cdecl FLT_VParams(prc_t *p)
{
  PRC_CheckParams(pprc: p, prng: flt_rng);
  return FLT_Params(pprc: p);
}

//------------------------------------------------------------------------------
// Address: 0x10028830
// Name: void __near * DLY_VParams(void __near *)
// Source: json
//------------------------------------------------------------------------------
dly_t *__cdecl DLY_VParams(prc_t *p)
{
  PRC_CheckParams(pprc: p, prng: dly_rng);
  return DLY_Params(pprc: p);
}

//------------------------------------------------------------------------------
// Address: 0x10028850
// Name: void DLY_GetNext_Opt(struct dly_t __near *,int __near *,int __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DLY_GetNext_Opt(dly_t *pdly, int *pIn, int *pOut, int nCount)
{
  switch ( pdly->type )
  {
    case 1:
      DelayAllpass_Opt3<2,0>(
        nDelaySize: pdly->D,
        tdelay: pdly->t,
        psamps: pdly->w,
        ppsamp: &pdly->p,
        fbgain: pdly->a,
        outgain: pdly->b,
        pIn,
        pOut,
        nCount);
      break;
    case 2:
      DelayLowPass_Opt3(
        nDelaySize: pdly->D,
        tdelay: (int *)pdly->t,
        psamps: pdly->w,
        ppsamp: &pdly->p,
        fbgain: pdly->a,
        outgain: pdly->b,
        denom: pdly->pflt->a,
        Ll: pdly->pflt->L,
        numer: pdly->pflt->b,
        pfsamps: pdly->pflt->w,
        pIn,
        pOut,
        nCount);
      break;
    case 3:
      DelayLinear_Opt(delaysize: pdly->D, tdelay: pdly->t, psamps: pdly->w, ppsamp: &pdly->p, pIn, pOut, nCount);
      break;
    case 4:
      DelayLinearLowPass_Opt3(
        nDelaySize: pdly->D,
        tdelay: pdly->t,
        psamps: pdly->w,
        ppsamp: &pdly->p,
        fbgain: pdly->a,
        outgain: pdly->b,
        denom: pdly->pflt->a,
        Ll: pdly->pflt->L,
        numer: pdly->pflt->b,
        pfsamps: pdly->pflt->w,
        pIn,
        pOut,
        nCount);
      break;
    case 5:
      DelayLowpass_multitap_Opt(
        delaysize: pdly->D,
        tdelay0: pdly->t,
        tdelay1: pdly->t1,
        tdelay2: pdly->t2,
        tdelay3: pdly->t3,
        psamps: pdly->w,
        ppsamp: &pdly->p,
        fbgain: pdly->a,
        outgain: pdly->b,
        denom: pdly->pflt->a,
        Ll: pdly->pflt->L,
        numer: pdly->pflt->b,
        pfsamps: pdly->pflt->w,
        pIn,
        pOut,
        nCount);
      break;
    case 6:
      ReverbSimple_multitap_Opt(
        delaysize: pdly->D,
        tdelay0: pdly->t,
        tdelay1: pdly->t1,
        tdelay2: pdly->t2,
        tdelay3: pdly->t3,
        psamps: pdly->w,
        ppsamp: &pdly->p,
        fbgain: pdly->a,
        outgain: pdly->b,
        pIn,
        pOut,
        nCount);
      break;
    default:
      ReverbSimple_Opt(
        delaysize: pdly->D,
        tdelay: pdly->t,
        psamps: pdly->w,
        ppsamp: &pdly->p,
        fbgain: pdly->a,
        outgain: pdly->b,
        pIn,
        pOut,
        nCount);
      break;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10028A20
// Name: void __near * MDY_VParams(void __near *)
// Source: json
//------------------------------------------------------------------------------
dly_t *__cdecl MDY_VParams(prc_t *p)
{
  PRC_CheckParams(pprc: p, prng: mdy_rng);
  return MDY_Params(pprc: p);
}

//------------------------------------------------------------------------------
// Address: 0x10028A40
// Name: void __near * RVA_VParams(void __near *)
// Source: json
//------------------------------------------------------------------------------
rva_t *__cdecl RVA_VParams(prc_t *p)
{
  PRC_CheckParams(pprc: p, prng: rva_rng);
  return RVA_Params(pprc: p);
}

//------------------------------------------------------------------------------
// Address: 0x10028A60
// Name: void __near * DFR_VParams(void __near *)
// Source: json
//------------------------------------------------------------------------------
dfr_t *__cdecl DFR_VParams(prc_t *p)
{
  PRC_CheckParams(pprc: p, prng: dfr_rng);
  return DFR_Params(pprc: p);
}

//------------------------------------------------------------------------------
// Address: 0x10028A80
// Name: void __near * LFO_VParams(void __near *)
// Source: json
//------------------------------------------------------------------------------
lfo_t *__cdecl LFO_VParams(prc_t *p)
{
  PRC_CheckParams(pprc: p, prng: lfo_rng);
  return LFO_Alloc(wtype: (int)p->prm[0], freqHz: p->prm[1], foneshot: p->prm[2] > 0.0, gain: p->prm[3]);
}

//------------------------------------------------------------------------------
// Address: 0x10028B30
// Name: void __near * EFO_VParams(void __near *)
// Source: json
//------------------------------------------------------------------------------
efo_t *__cdecl EFO_VParams(prc_t *p)
{
  PRC_CheckParams(pprc: p, prng: efo_rng);
  return EFO_Params(pprc: p);
}

//------------------------------------------------------------------------------
// Address: 0x10028B50
// Name: void __near * CRS_VParams(void __near *)
// Source: json
//------------------------------------------------------------------------------
crs_t *__cdecl CRS_VParams(prc_t *p)
{
  PRC_CheckParams(pprc: p, prng: crs_rng);
  return CRS_Alloc(lfotype: (int)p->prm[0], fHz: p->prm[1], fdepth: p->prm[2], mix: p->prm[3]);
}

//------------------------------------------------------------------------------
// Address: 0x10028B90
// Name: void __near * AMP_VParams(void __near *)
// Source: json
//------------------------------------------------------------------------------
amp_t *__cdecl AMP_VParams(prc_t *p)
{
  PRC_CheckParams(pprc: p, prng: amp_rng);
  return AMP_Params(pprc: p);
}

//------------------------------------------------------------------------------
// Address: 0x10028BB0
// Name: void DSP_FreePrevPreset(struct dsp_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DSP_FreePrevPreset(dsp_t *pdsp)
{
  dsp_t *v1; // esi
  pset_t *v2; // edi
  void **p_pdata; // esi
  int cprcs; // ebx
  void (__cdecl *v5)(void *); // ecx
  int i; // [esp+4h] [ebp-8h]
  pset_t **ppsetprev; // [esp+8h] [ebp-4h]

  v1 = pdsp;
  if ( pdsp->ipsetprev != 0 )
  {
    if ( snd_dsp_spew_changes.m_pParent != nullptr && snd_dsp_spew_changes.m_pParent->m_Value.m_nValue != 0 )
      DevMsg(a1: "[Sound DSP] Free previous preset %d.\n", pdsp->ipsetprev);
    i = 0;
    if ( pdsp->cchan > 0 )
    {
      ppsetprev = pdsp->ppsetprev;
      do
      {
        v2 = *ppsetprev;
        if ( *ppsetprev != nullptr )
        {
          if ( v2->cprcs > 0 )
          {
            p_pdata = &v2->prcs[0].pdata;
            cprcs = v2->cprcs;
            do
            {
              v5 = (void (__cdecl *)(void *))*(p_pdata - 2);
              if ( v5 != nullptr && *p_pdata != nullptr )
                v5(a1: *p_pdata);
              p_pdata += 23;
              --cprcs;
            }
            while ( cprcs != 0 );
            v1 = pdsp;
          }
          _V_memset(dest: v2, fill: 0, count: 536);
          *ppsetprev = nullptr;
        }
        ++ppsetprev;
        ++i;
      }
      while ( i < v1->cchan );
    }
    v1->ipsetprev = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10028C70
// Name: _DSP_ClearState
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void DSP_ClearState()
{
  PreserveDSP_t *v0; // esi
  int v1; // ecx

  if ( !g_bNeedPresetRestore )
  {
    CLoaderMemAlloc::CrtIsValidPointer(this: (ConVar *)&dsp_automatic.IConVar, value: 0);
    v0 = g_PreserveDSP;
    do
    {
      v1 = (int)&v0->cvar->IConVar;
      v0->oldvalue = v0->cvar->m_pParent->m_Value.m_fValue;
      (*(void (__thiscall **)(int, _DWORD))(*(_DWORD *)v1 + 4))(a1: v1, a2: 0);
      ++v0;
    }
    while ( (int)v0 < (int)&unk_10411EFC );
    DSP_Free(idsp: (dsp_t *)idsp_room);
    DSP_Free(idsp: (dsp_t *)idsp_water);
    DSP_Free(idsp: (dsp_t *)idsp_player);
    DSP_Free(idsp: (dsp_t *)idsp_facingaway);
    DSP_Free(idsp: (dsp_t *)idsp_speaker);
    DSP_Free(idsp: (dsp_t *)idsp_spatial);
    DSP_Free(idsp: (dsp_t *)idsp_automatic);
    idsp_room = 0;
    idsp_water = 0;
    idsp_player = 0;
    idsp_facingaway = 0;
    idsp_speaker = 0;
    idsp_spatial = 0;
    idsp_automatic = 0;
    DSP_FreeAll();
    g_bNeedPresetRestore = true;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10028FF0
// Name: void RVA_GetNext_Opt<0,1>(struct rva_t __near *,struct portable_samplepair_t __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl RVA_GetNext_Opt<0,1>(
        flt_t *pRva,
        portable_samplepair_t *pBuffer,
        int nCount,
        int a4,
        int a5,
        int a6,
        int a7,
        int a8,
        int a9,
        int a10,
        int a11,
        int a12,
        int a13,
        int a14,
        int a15,
        int a16,
        int a17,
        int a18,
        int a19,
        int a20,
        int a21,
        int a22,
        int a23,
        int a24,
        int a25)
{
  int v25; // ebx
  unsigned int v26; // esi
  void *v27; // esp
  unsigned int v28; // edi
  int v29; // esi
  rva_t *v30; // esi
  mdy_t **v31; // esi
  mdy_t *v32; // eax
  int v33; // esi
  bool v34; // zf
  dly_t **v35; // esi
  flt_t *pflt; // ecx
  int v37; // esi
  portable_samplepair_t *v38; // eax
  int *v39; // ecx
  unsigned int v40; // edx
  mdy_t *pModDelay; // [esp+Ch] [ebp-8h]
  int m; // [esp+10h] [ebp-4h]
  flt_t *pFilter; // [esp+1Ch] [ebp+8h]
  unsigned int pCurrentCacheLine; // [esp+24h] [ebp+10h]
  int *pCurrentCacheLinea; // [esp+24h] [ebp+10h]
  int *pCurrentCacheLineb; // [esp+24h] [ebp+10h]

  v25 = nCount;
  v26 = (4 * nCount + 127) & 0xFFFFFF80;
  m = pRva->b[0];
  v27 = alloca(v26 + 128);
  v28 = ((unsigned int)&a25 + 3) & 0xFFFFFF80;
  v29 = (int)((v26 + 127) & 0xFFFFFF80) / 128;
  for ( pCurrentCacheLine = ((unsigned int)&a25 + 3) & 0xFFFFFF80; v29 > 0; --v29 )
  {
    memset(dst: (unsigned __int8 *)(pCurrentCacheLine & 0xFFFFFF80), value: 0, count: 0x80u);
    pCurrentCacheLine += 128;
  }
  v30 = (rva_t *)pRva;
  if ( LOBYTE(pRva->w[1]) != 0 )
  {
    if ( m > 0 )
    {
      v31 = (mdy_t **)&pRva->a[2];
      pCurrentCacheLinea = &pRva->a[2];
      do
      {
        v32 = *v31;
        v33 = 0;
        for ( pModDelay = v32; v33 < v25; ++v33 )
          *(_DWORD *)(v28 + 4 * v33) += MDY_GetNext(pmdy: pModDelay, x: pBuffer[v33].left);
        v31 = (mdy_t **)(pCurrentCacheLinea + 1);
        v34 = m-- == 1;
        ++pCurrentCacheLinea;
      }
      while ( !v34 );
      goto LABEL_13;
    }
  }
  else if ( m > 0 )
  {
    v35 = (dly_t **)&pRva->b[3];
    for ( pCurrentCacheLineb = (int *)m;
          pCurrentCacheLineb != nullptr;
          pCurrentCacheLineb = (int *)((char *)pCurrentCacheLineb - 1) )
    {
      DLY_GetNext_Opt(
        pdly: *v35++,
        pIn: &pBuffer->left,
        pOut: (int *)(((unsigned int)&a25 + 3) & 0xFFFFFF80),
        nCount: v25);
    }
LABEL_13:
    v30 = (rva_t *)pRva;
  }
  if ( v30->fparallel == 0 )
  {
    pflt = v30->pflt;
    pFilter = pflt;
    if ( pflt != nullptr )
    {
      v37 = 0;
      if ( v25 > 0 )
      {
        while ( 1 )
        {
          *(_DWORD *)(v28 + 4 * v37) = FLT_GetNext(pf: pflt, x: *(_DWORD *)(v28 + 4 * v37));
          if ( ++v37 >= v25 )
            break;
          pflt = pFilter;
        }
      }
    }
  }
  v38 = pBuffer;
  v39 = (int *)(((unsigned int)&a25 + 3) & 0xFFFFFF80);
  if ( v25 >= 16 )
  {
    v40 = (unsigned int)v25 >> 4;
    v25 += -16 * ((unsigned int)v25 >> 4);
    do
    {
      v38->left = *v39;
      v38[1].left = v39[1];
      v38[2].left = v39[2];
      v38[3].left = v39[3];
      v38[4].left = v39[4];
      v38[5].left = v39[5];
      v38[6].left = v39[6];
      v38[7].left = v39[7];
      v38[8].left = v39[8];
      v38[9].left = v39[9];
      v38[10].left = v39[10];
      v38[11].left = v39[11];
      v38[12].left = v39[12];
      v38[13].left = v39[13];
      v38[14].left = v39[14];
      v38[15].left = v39[15];
      v38 += 16;
      v39 += 16;
      --v40;
    }
    while ( v40 != 0 );
  }
  if ( v25 >= 1 )
  {
    do
    {
      v38->left = *v39;
      ++v38;
      ++v39;
      --v25;
    }
    while ( v25 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x100291A0
// Name: void RVA_GetNext_Opt<1,2>(struct rva_t __near *,struct portable_samplepair_t __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl RVA_GetNext_Opt<1,2>(
        flt_t *pRva,
        portable_samplepair_t *pBuffer,
        int nCount,
        int a4,
        int a5,
        int a6,
        int a7,
        int a8,
        int a9,
        int a10,
        int a11,
        int a12,
        int a13,
        int a14,
        int a15,
        int a16,
        int a17,
        int a18,
        int a19,
        int a20,
        int a21,
        int a22,
        int a23,
        int a24,
        int a25)
{
  int v25; // ebx
  unsigned int v26; // esi
  void *v27; // esp
  unsigned int v28; // edi
  int v29; // esi
  rva_t *v30; // esi
  mdy_t **v31; // esi
  mdy_t *v32; // eax
  int v33; // esi
  bool v34; // zf
  dly_t **v35; // esi
  flt_t *pflt; // ecx
  int v37; // esi
  portable_samplepair_t *v38; // ecx
  int *v39; // eax
  unsigned int v40; // edx
  int *p_right; // ecx
  mdy_t *pModDelay; // [esp+Ch] [ebp-8h]
  int m; // [esp+10h] [ebp-4h]
  flt_t *pFilter; // [esp+1Ch] [ebp+8h]
  unsigned int pCurrentCacheLine; // [esp+24h] [ebp+10h]
  int *pCurrentCacheLinea; // [esp+24h] [ebp+10h]
  int *pCurrentCacheLineb; // [esp+24h] [ebp+10h]

  v25 = nCount;
  v26 = (4 * nCount + 127) & 0xFFFFFF80;
  m = pRva->b[0];
  v27 = alloca(v26 + 128);
  v28 = ((unsigned int)&a25 + 3) & 0xFFFFFF80;
  v29 = (int)((v26 + 127) & 0xFFFFFF80) / 128;
  for ( pCurrentCacheLine = ((unsigned int)&a25 + 3) & 0xFFFFFF80; v29 > 0; --v29 )
  {
    memset(dst: (unsigned __int8 *)(pCurrentCacheLine & 0xFFFFFF80), value: 0, count: 0x80u);
    pCurrentCacheLine += 128;
  }
  v30 = (rva_t *)pRva;
  if ( LOBYTE(pRva->w[1]) != 0 )
  {
    if ( m > 0 )
    {
      v31 = (mdy_t **)&pRva->a[2];
      pCurrentCacheLinea = &pRva->a[2];
      do
      {
        v32 = *v31;
        v33 = 0;
        for ( pModDelay = v32; v33 < v25; ++v33 )
          *(_DWORD *)(v28 + 4 * v33) += MDY_GetNext(pmdy: pModDelay, x: pBuffer[v33].right);
        v31 = (mdy_t **)(pCurrentCacheLinea + 1);
        v34 = m-- == 1;
        ++pCurrentCacheLinea;
      }
      while ( !v34 );
      goto LABEL_13;
    }
  }
  else if ( m > 0 )
  {
    v35 = (dly_t **)&pRva->b[3];
    for ( pCurrentCacheLineb = (int *)m;
          pCurrentCacheLineb != nullptr;
          pCurrentCacheLineb = (int *)((char *)pCurrentCacheLineb - 1) )
    {
      DLY_GetNext_Opt(
        pdly: *v35++,
        pIn: &pBuffer->right,
        pOut: (int *)(((unsigned int)&a25 + 3) & 0xFFFFFF80),
        nCount: v25);
    }
LABEL_13:
    v30 = (rva_t *)pRva;
  }
  if ( v30->fparallel == 0 )
  {
    pflt = v30->pflt;
    pFilter = pflt;
    if ( pflt != nullptr )
    {
      v37 = 0;
      if ( v25 > 0 )
      {
        while ( 1 )
        {
          *(_DWORD *)(v28 + 4 * v37) = FLT_GetNext(pf: pflt, x: *(_DWORD *)(v28 + 4 * v37));
          if ( ++v37 >= v25 )
            break;
          pflt = pFilter;
        }
      }
    }
  }
  v38 = pBuffer;
  v39 = (int *)(((unsigned int)&a25 + 3) & 0xFFFFFF80);
  if ( v25 >= 16 )
  {
    v40 = (unsigned int)v25 >> 4;
    v25 += -16 * ((unsigned int)v25 >> 4);
    do
    {
      v38->right = *v39;
      v38[1].right = v39[1];
      v38[2].right = v39[2];
      v38[3].right = v39[3];
      v38[4].right = v39[4];
      v38[5].right = v39[5];
      v38[6].right = v39[6];
      v38[7].right = v39[7];
      v38[8].right = v39[8];
      v38[9].right = v39[9];
      v38[10].right = v39[10];
      v38[11].right = v39[11];
      v38[12].right = v39[12];
      v38[13].right = v39[13];
      v38[14].right = v39[14];
      v38[15].right = v39[15];
      v38 += 16;
      v39 += 16;
      --v40;
    }
    while ( v40 != 0 );
  }
  if ( v25 >= 1 )
  {
    p_right = &v38->right;
    do
    {
      *p_right = *v39;
      p_right += 2;
      ++v39;
      --v25;
    }
    while ( v25 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10029350
// Name: void RVA_GetNext_Opt<0,3>(struct rva_t __near *,struct portable_samplepair_t __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl RVA_GetNext_Opt<0,3>(
        flt_t *pRva,
        portable_samplepair_t *pBuffer,
        int nCount,
        int a4,
        int a5,
        int a6,
        int a7,
        int a8,
        int a9,
        int a10,
        int a11,
        int a12,
        int a13,
        int a14,
        int a15,
        int a16,
        int a17,
        int a18,
        int a19,
        int a20,
        int a21,
        int a22,
        int a23,
        int a24,
        int a25)
{
  int v25; // ebx
  unsigned int v26; // esi
  void *v27; // esp
  unsigned int v28; // edi
  int v29; // esi
  rva_t *v30; // esi
  mdy_t **v31; // esi
  mdy_t *v32; // eax
  int v33; // esi
  bool v34; // zf
  dly_t **v35; // esi
  flt_t *pflt; // ecx
  int v37; // esi
  portable_samplepair_t *v38; // eax
  int *v39; // ecx
  unsigned int v40; // esi
  int v41; // edx
  int v42; // edx
  int v43; // edx
  int v44; // edx
  int v45; // edx
  int v46; // edx
  int v47; // edx
  int v48; // edx
  int v49; // edx
  int v50; // edx
  int v51; // edx
  int v52; // edx
  int v53; // edx
  int v54; // edx
  int v55; // edx
  int v56; // edx
  int v57; // edx
  mdy_t *pModDelay; // [esp+Ch] [ebp-8h]
  int m; // [esp+10h] [ebp-4h]
  flt_t *pFilter; // [esp+1Ch] [ebp+8h]
  unsigned int pCurrentCacheLine; // [esp+24h] [ebp+10h]
  int *pCurrentCacheLinea; // [esp+24h] [ebp+10h]
  int *pCurrentCacheLineb; // [esp+24h] [ebp+10h]

  v25 = nCount;
  v26 = (4 * nCount + 127) & 0xFFFFFF80;
  m = pRva->b[0];
  v27 = alloca(v26 + 128);
  v28 = ((unsigned int)&a25 + 3) & 0xFFFFFF80;
  v29 = (int)((v26 + 127) & 0xFFFFFF80) / 128;
  for ( pCurrentCacheLine = ((unsigned int)&a25 + 3) & 0xFFFFFF80; v29 > 0; --v29 )
  {
    memset(dst: (unsigned __int8 *)(pCurrentCacheLine & 0xFFFFFF80), value: 0, count: 0x80u);
    pCurrentCacheLine += 128;
  }
  v30 = (rva_t *)pRva;
  if ( LOBYTE(pRva->w[1]) != 0 )
  {
    if ( m > 0 )
    {
      v31 = (mdy_t **)&pRva->a[2];
      pCurrentCacheLinea = &pRva->a[2];
      do
      {
        v32 = *v31;
        v33 = 0;
        for ( pModDelay = v32; v33 < v25; ++v33 )
          *(_DWORD *)(v28 + 4 * v33) += MDY_GetNext(pmdy: pModDelay, x: pBuffer[v33].left);
        v31 = (mdy_t **)(pCurrentCacheLinea + 1);
        v34 = m-- == 1;
        ++pCurrentCacheLinea;
      }
      while ( !v34 );
      goto LABEL_13;
    }
  }
  else if ( m > 0 )
  {
    v35 = (dly_t **)&pRva->b[3];
    for ( pCurrentCacheLineb = (int *)m;
          pCurrentCacheLineb != nullptr;
          pCurrentCacheLineb = (int *)((char *)pCurrentCacheLineb - 1) )
    {
      DLY_GetNext_Opt(
        pdly: *v35++,
        pIn: &pBuffer->left,
        pOut: (int *)(((unsigned int)&a25 + 3) & 0xFFFFFF80),
        nCount: v25);
    }
LABEL_13:
    v30 = (rva_t *)pRva;
  }
  if ( v30->fparallel == 0 )
  {
    pflt = v30->pflt;
    pFilter = pflt;
    if ( pflt != nullptr )
    {
      v37 = 0;
      if ( v25 > 0 )
      {
        while ( 1 )
        {
          *(_DWORD *)(v28 + 4 * v37) = FLT_GetNext(pf: pflt, x: *(_DWORD *)(v28 + 4 * v37));
          if ( ++v37 >= v25 )
            break;
          pflt = pFilter;
        }
      }
    }
  }
  v38 = pBuffer;
  v39 = (int *)(((unsigned int)&a25 + 3) & 0xFFFFFF80);
  if ( v25 >= 16 )
  {
    v40 = (unsigned int)v25 >> 4;
    v25 += -16 * ((unsigned int)v25 >> 4);
    do
    {
      v41 = *v39;
      v38->right = *v39;
      v38->left = v41;
      v42 = v39[1];
      v38[1].right = v42;
      v38[1].left = v42;
      v43 = v39[2];
      v38[2].right = v43;
      v38[2].left = v43;
      v44 = v39[3];
      v38[3].right = v44;
      v38[3].left = v44;
      v45 = v39[4];
      v38[4].right = v45;
      v38[4].left = v45;
      v46 = v39[5];
      v38[5].right = v46;
      v38[5].left = v46;
      v47 = v39[6];
      v38[6].right = v47;
      v38[6].left = v47;
      v48 = v39[7];
      v38[7].right = v48;
      v38[7].left = v48;
      v49 = v39[8];
      v38[8].right = v49;
      v38[8].left = v49;
      v50 = v39[9];
      v38[9].right = v50;
      v38[9].left = v50;
      v51 = v39[10];
      v38[10].right = v51;
      v38[10].left = v51;
      v52 = v39[11];
      v38[11].right = v52;
      v38[11].left = v52;
      v53 = v39[12];
      v38[12].right = v53;
      v38[12].left = v53;
      v54 = v39[13];
      v38[13].right = v54;
      v38[13].left = v54;
      v55 = v39[14];
      v38[14].right = v55;
      v38[14].left = v55;
      v56 = v39[15];
      v38[15].right = v56;
      v38[15].left = v56;
      v38 += 16;
      v39 += 16;
      --v40;
    }
    while ( v40 != 0 );
  }
  if ( v25 >= 1 )
  {
    do
    {
      v57 = *v39;
      v38->right = *v39;
      v38->left = v57;
      ++v38;
      ++v39;
      --v25;
    }
    while ( v25 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10029540
// Name: void DFR_GetNext_Opt<0,1>(struct dfr_t __near *,struct portable_samplepair_t __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DFR_GetNext_Opt<0,1>(
        dfr_t *pdfr,
        portable_samplepair_t *pBuffer,
        unsigned int nCount,
        int a4,
        int a5,
        int a6,
        int a7,
        int a8,
        int a9,
        int a10,
        int a11,
        int a12,
        int a13,
        int a14,
        int a15,
        int a16,
        int a17,
        int a18,
        int a19,
        int a20,
        int a21,
        int a22,
        int a23,
        int a24,
        int a25,
        int a26,
        int a27)
{
  unsigned int v27; // edi
  void *v28; // esp
  int v29; // edi
  unsigned int i; // ebx
  int v31; // ebx
  dly_t *v32; // eax
  int v33; // edi
  dly_t **v34; // ebx
  portable_samplepair_t *v35; // eax
  int *v36; // ecx
  unsigned int v37; // edx
  int j; // edx

  v27 = (4 * nCount + 127) & 0xFFFFFF80;
  v28 = alloca(v27 + 128);
  v29 = (int)((v27 + 127) & 0xFFFFFF80) / 128;
  for ( i = ((unsigned int)&a27 + 3) & 0xFFFFFF80; v29 > 0; i += 128 )
  {
    memset(dst: (unsigned __int8 *)(i & 0xFFFFFF80), value: 0, count: 0x80u);
    --v29;
  }
  v31 = nCount;
  if ( pdfr->n != 0 )
  {
    v32 = pdfr->pdlys[0];
    DelayAllpass_Opt3<2,1>(
      nDelaySize: v32->D,
      tdelay: v32->t,
      psamps: v32->w,
      ppsamp: &v32->p,
      fbgain: v32->a,
      outgain: v32->b,
      pIn: &pBuffer->left,
      pOut: (int *)(((unsigned int)&a27 + 3) & 0xFFFFFF80),
      nCount);
  }
  v33 = 1;
  if ( pdfr->n > 1 )
  {
    v34 = &pdfr->pdlys[1];
    do
    {
      DelayAllpass_Opt3<1,1>(
        nDelaySize: (*v34)->D,
        tdelay: (*v34)->t,
        psamps: (*v34)->w,
        ppsamp: &(*v34)->p,
        fbgain: (*v34)->a,
        outgain: (*v34)->b,
        pIn: (int *)(((unsigned int)&a27 + 3) & 0xFFFFFF80),
        pOut: (int *)(((unsigned int)&a27 + 3) & 0xFFFFFF80),
        nCount);
      ++v33;
      ++v34;
    }
    while ( v33 < pdfr->n );
    v31 = nCount;
  }
  v35 = pBuffer;
  v36 = (int *)(((unsigned int)&a27 + 3) & 0xFFFFFF80);
  if ( v31 >= 16 )
  {
    v37 = (unsigned int)v31 >> 4;
    v31 += -16 * ((unsigned int)v31 >> 4);
    do
    {
      v35->left = *v36;
      v35[1].left = v36[1];
      v35[2].left = v36[2];
      v35[3].left = v36[3];
      v35[4].left = v36[4];
      v35[5].left = v36[5];
      v35[6].left = v36[6];
      v35[7].left = v36[7];
      v35[8].left = v36[8];
      v35[9].left = v36[9];
      v35[10].left = v36[10];
      v35[11].left = v36[11];
      v35[12].left = v36[12];
      v35[13].left = v36[13];
      v35[14].left = v36[14];
      v35[15].left = v36[15];
      v35 += 16;
      v36 += 16;
      --v37;
    }
    while ( v37 != 0 );
  }
  if ( v31 >= 1 )
  {
    for ( j = v31; j != 0; --j )
    {
      v35->left = *v36;
      ++v35;
      ++v36;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100296C0
// Name: void DFR_GetNext_Opt<1,2>(struct dfr_t __near *,struct portable_samplepair_t __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DFR_GetNext_Opt<1,2>(
        dfr_t *pdfr,
        portable_samplepair_t *pBuffer,
        unsigned int nCount,
        int a4,
        int a5,
        int a6,
        int a7,
        int a8,
        int a9,
        int a10,
        int a11,
        int a12,
        int a13,
        int a14,
        int a15,
        int a16,
        int a17,
        int a18,
        int a19,
        int a20,
        int a21,
        int a22,
        int a23,
        int a24,
        int a25,
        int a26,
        int a27)
{
  unsigned int v27; // edi
  void *v28; // esp
  int v29; // edi
  unsigned int i; // ebx
  int v31; // ebx
  dly_t *v32; // eax
  int v33; // edi
  dly_t **v34; // ebx
  portable_samplepair_t *v35; // ecx
  int *v36; // eax
  unsigned int v37; // edx
  int *p_right; // ecx
  int j; // edx

  v27 = (4 * nCount + 127) & 0xFFFFFF80;
  v28 = alloca(v27 + 128);
  v29 = (int)((v27 + 127) & 0xFFFFFF80) / 128;
  for ( i = ((unsigned int)&a27 + 3) & 0xFFFFFF80; v29 > 0; i += 128 )
  {
    memset(dst: (unsigned __int8 *)(i & 0xFFFFFF80), value: 0, count: 0x80u);
    --v29;
  }
  v31 = nCount;
  if ( pdfr->n != 0 )
  {
    v32 = pdfr->pdlys[0];
    DelayAllpass_Opt3<2,1>(
      nDelaySize: v32->D,
      tdelay: v32->t,
      psamps: v32->w,
      ppsamp: &v32->p,
      fbgain: v32->a,
      outgain: v32->b,
      pIn: &pBuffer->right,
      pOut: (int *)(((unsigned int)&a27 + 3) & 0xFFFFFF80),
      nCount);
  }
  v33 = 1;
  if ( pdfr->n > 1 )
  {
    v34 = &pdfr->pdlys[1];
    do
    {
      DelayAllpass_Opt3<1,1>(
        nDelaySize: (*v34)->D,
        tdelay: (*v34)->t,
        psamps: (*v34)->w,
        ppsamp: &(*v34)->p,
        fbgain: (*v34)->a,
        outgain: (*v34)->b,
        pIn: (int *)(((unsigned int)&a27 + 3) & 0xFFFFFF80),
        pOut: (int *)(((unsigned int)&a27 + 3) & 0xFFFFFF80),
        nCount);
      ++v33;
      ++v34;
    }
    while ( v33 < pdfr->n );
    v31 = nCount;
  }
  v35 = pBuffer;
  v36 = (int *)(((unsigned int)&a27 + 3) & 0xFFFFFF80);
  if ( v31 >= 16 )
  {
    v37 = (unsigned int)v31 >> 4;
    v31 += -16 * ((unsigned int)v31 >> 4);
    do
    {
      v35->right = *v36;
      v35[1].right = v36[1];
      v35[2].right = v36[2];
      v35[3].right = v36[3];
      v35[4].right = v36[4];
      v35[5].right = v36[5];
      v35[6].right = v36[6];
      v35[7].right = v36[7];
      v35[8].right = v36[8];
      v35[9].right = v36[9];
      v35[10].right = v36[10];
      v35[11].right = v36[11];
      v35[12].right = v36[12];
      v35[13].right = v36[13];
      v35[14].right = v36[14];
      v35[15].right = v36[15];
      v35 += 16;
      v36 += 16;
      --v37;
    }
    while ( v37 != 0 );
  }
  if ( v31 >= 1 )
  {
    p_right = &v35->right;
    for ( j = v31; j != 0; --j )
    {
      *p_right = *v36;
      p_right += 2;
      ++v36;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10029840
// Name: void DFR_GetNext_Opt<0,3>(struct dfr_t __near *,struct portable_samplepair_t __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DFR_GetNext_Opt<0,3>(
        dfr_t *pdfr,
        portable_samplepair_t *pBuffer,
        unsigned int nCount,
        int a4,
        int a5,
        int a6,
        int a7,
        int a8,
        int a9,
        int a10,
        int a11,
        int a12,
        int a13,
        int a14,
        int a15,
        int a16,
        int a17,
        int a18,
        int a19,
        int a20,
        int a21,
        int a22,
        int a23,
        int a24,
        int a25,
        int a26,
        int a27)
{
  unsigned int v27; // edi
  void *v28; // esp
  int v29; // edi
  unsigned int i; // ebx
  dly_t *v31; // eax
  int v32; // edi
  dly_t **v33; // ebx
  int v34; // edi
  portable_samplepair_t *v35; // eax
  int *v36; // ecx
  unsigned int v37; // esi
  int v38; // edx
  int v39; // edx
  int v40; // edx
  int v41; // edx
  int v42; // edx
  int v43; // edx
  int v44; // edx
  int v45; // edx
  int v46; // edx
  int v47; // edx
  int v48; // edx
  int v49; // edx
  int v50; // edx
  int v51; // edx
  int v52; // edx
  int v53; // edx
  int j; // esi
  int v55; // edx

  v27 = (4 * nCount + 127) & 0xFFFFFF80;
  v28 = alloca(v27 + 128);
  v29 = (int)((v27 + 127) & 0xFFFFFF80) / 128;
  for ( i = ((unsigned int)&a27 + 3) & 0xFFFFFF80; v29 > 0; i += 128 )
  {
    memset(dst: (unsigned __int8 *)(i & 0xFFFFFF80), value: 0, count: 0x80u);
    --v29;
  }
  if ( pdfr->n != 0 )
  {
    v31 = pdfr->pdlys[0];
    DelayAllpass_Opt3<2,1>(
      nDelaySize: v31->D,
      tdelay: v31->t,
      psamps: v31->w,
      ppsamp: &v31->p,
      fbgain: v31->a,
      outgain: v31->b,
      pIn: &pBuffer->left,
      pOut: (int *)(((unsigned int)&a27 + 3) & 0xFFFFFF80),
      nCount);
  }
  v32 = 1;
  if ( pdfr->n > 1 )
  {
    v33 = &pdfr->pdlys[1];
    do
    {
      DelayAllpass_Opt3<1,1>(
        nDelaySize: (*v33)->D,
        tdelay: (*v33)->t,
        psamps: (*v33)->w,
        ppsamp: &(*v33)->p,
        fbgain: (*v33)->a,
        outgain: (*v33)->b,
        pIn: (int *)(((unsigned int)&a27 + 3) & 0xFFFFFF80),
        pOut: (int *)(((unsigned int)&a27 + 3) & 0xFFFFFF80),
        nCount);
      ++v32;
      ++v33;
    }
    while ( v32 < pdfr->n );
  }
  v34 = nCount;
  v35 = pBuffer;
  v36 = (int *)(((unsigned int)&a27 + 3) & 0xFFFFFF80);
  if ( (int)nCount >= 16 )
  {
    v37 = nCount >> 4;
    v34 = -16 * (nCount >> 4) + nCount;
    do
    {
      v38 = *v36;
      v35->right = *v36;
      v35->left = v38;
      v39 = v36[1];
      v35[1].right = v39;
      v35[1].left = v39;
      v40 = v36[2];
      v35[2].right = v40;
      v35[2].left = v40;
      v41 = v36[3];
      v35[3].right = v41;
      v35[3].left = v41;
      v42 = v36[4];
      v35[4].right = v42;
      v35[4].left = v42;
      v43 = v36[5];
      v35[5].right = v43;
      v35[5].left = v43;
      v44 = v36[6];
      v35[6].right = v44;
      v35[6].left = v44;
      v45 = v36[7];
      v35[7].right = v45;
      v35[7].left = v45;
      v46 = v36[8];
      v35[8].right = v46;
      v35[8].left = v46;
      v47 = v36[9];
      v35[9].right = v47;
      v35[9].left = v47;
      v48 = v36[10];
      v35[10].right = v48;
      v35[10].left = v48;
      v49 = v36[11];
      v35[11].right = v49;
      v35[11].left = v49;
      v50 = v36[12];
      v35[12].right = v50;
      v35[12].left = v50;
      v51 = v36[13];
      v35[13].right = v51;
      v35[13].left = v51;
      v52 = v36[14];
      v35[14].right = v52;
      v35[14].left = v52;
      v53 = v36[15];
      v35[15].right = v53;
      v35[15].left = v53;
      v35 += 16;
      v36 += 16;
      --v37;
    }
    while ( v37 != 0 );
  }
  if ( v34 >= 1 )
  {
    for ( j = v34; j != 0; --j )
    {
      v55 = *v36;
      v35->right = *v36;
      v35->left = v55;
      ++v35;
      ++v36;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100299F0
// Name: void RVA_GetNextN_Opt(struct rva_t __near *,struct portable_samplepair_t __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x10029A50
// Name: void DFR_GetNextN_Opt(struct dfr_t __near *,struct portable_samplepair_t __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x10029AB0
// Name: bool PRC_InitAll(struct prc_t __near *,int)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl PRC_InitAll(prc_t *prcs, int count)
{
  int v2; // ecx
  bool result; // al
  bool v4; // cc
  int (__cdecl **p_pfnGetNext)(void *, int); // ebx
  void (__cdecl *v6)(flt_t *); // ecx
  int (__cdecl *v7)(lfo_t *); // edx
  void (__thiscall *v8)(vgui::PropertyPage *); // esi
  dly_t *(__cdecl *v9)(prc_t *); // eax
  void (__thiscall *v10)(vgui::PropertyPage *); // edi
  dly_t *v11; // eax
  bool fok; // [esp+3h] [ebp-1h]
  int counta; // [esp+10h] [ebp+Ch]

  v2 = count;
  result = true;
  fok = true;
  v4 = count <= 0;
  if ( count == 0 )
  {
    v2 = 1;
    v4 = false;
  }
  if ( !v4 )
  {
    p_pfnGetNext = &prcs->pfnGetNext;
    counta = v2;
    do
    {
      switch ( (unsigned int)*(p_pfnGetNext - 18) )
      {
        case 1u:
          v6 = (void (__cdecl *)(flt_t *))DLY_Free;
          v7 = (int (__cdecl *)(lfo_t *))DLY_GetNext;
          v8 = (void (__thiscall *)(vgui::PropertyPage *))DLY_GetNextN;
          v9 = DLY_VParams;
          v10 = CColorBalanceUIPanel::Init;
          break;
        case 2u:
          v6 = (void (__cdecl *)(flt_t *))RVA_Free;
          v7 = (int (__cdecl *)(lfo_t *))RVA_GetNext;
          v8 = (void (__thiscall *)(vgui::PropertyPage *))RVA_GetNextN_Opt;
          v9 = (dly_t *(__cdecl *)(prc_t *))RVA_VParams;
          v10 = CColorBalanceUIPanel::Init;
          break;
        case 3u:
          v6 = FLT_Free;
          v7 = (int (__cdecl *)(lfo_t *))FLT_GetNext;
          v8 = (void (__thiscall *)(vgui::PropertyPage *))FLT_GetNextN;
          v9 = (dly_t *(__cdecl *)(prc_t *))FLT_VParams;
          v10 = CColorBalanceUIPanel::Init;
          break;
        case 4u:
          v6 = (void (__cdecl *)(flt_t *))CRS_Free;
          v7 = (int (__cdecl *)(lfo_t *))CRS_GetNext;
          v8 = (void (__thiscall *)(vgui::PropertyPage *))CRS_GetNextN;
          v9 = (dly_t *(__cdecl *)(prc_t *))CRS_VParams;
          v10 = CColorBalanceUIPanel::Init;
          break;
        case 5u:
          v6 = (void (__cdecl *)(flt_t *))PTC_Free;
          v7 = (int (__cdecl *)(lfo_t *))PTC_GetNext;
          v8 = (void (__thiscall *)(vgui::PropertyPage *))PTC_GetNextN;
          v9 = (dly_t *(__cdecl *)(prc_t *))PTC_VParams;
          v10 = CColorBalanceUIPanel::Init;
          break;
        case 6u:
          v6 = (void (__cdecl *)(flt_t *))ENV_Free;
          v7 = (int (__cdecl *)(lfo_t *))ENV_GetNext;
          v8 = (void (__thiscall *)(vgui::PropertyPage *))ENV_GetNextN;
          v9 = (dly_t *(__cdecl *)(prc_t *))ENV_VParams;
          v10 = CColorBalanceUIPanel::Init;
          break;
        case 7u:
          v6 = (void (__cdecl *)(flt_t *))LFO_Free;
          v7 = LFO_GetNext;
          v8 = (void (__thiscall *)(vgui::PropertyPage *))LFO_GetNextN;
          v9 = (dly_t *(__cdecl *)(prc_t *))LFO_VParams;
          v10 = (void (__thiscall *)(vgui::PropertyPage *))LFO_Mod;
          break;
        case 8u:
          v6 = (void (__cdecl *)(flt_t *))EFO_Free;
          v7 = (int (__cdecl *)(lfo_t *))EFO_GetNext;
          v8 = (void (__thiscall *)(vgui::PropertyPage *))EFO_GetNextN;
          v9 = (dly_t *(__cdecl *)(prc_t *))EFO_VParams;
          v10 = CColorBalanceUIPanel::Init;
          break;
        case 9u:
          v6 = (void (__cdecl *)(flt_t *))MDY_Free;
          v7 = (int (__cdecl *)(lfo_t *))MDY_GetNext;
          v8 = (void (__thiscall *)(vgui::PropertyPage *))MDY_GetNextN;
          v9 = MDY_VParams;
          v10 = (void (__thiscall *)(vgui::PropertyPage *))MDY_Mod;
          break;
        case 0xAu:
          v6 = (void (__cdecl *)(flt_t *))DFR_Free;
          v7 = (int (__cdecl *)(lfo_t *))DFR_GetNext;
          v8 = (void (__thiscall *)(vgui::PropertyPage *))DFR_GetNextN_Opt;
          v9 = (dly_t *(__cdecl *)(prc_t *))DFR_VParams;
          v10 = CColorBalanceUIPanel::Init;
          break;
        case 0xBu:
          v6 = (void (__cdecl *)(flt_t *))AMP_Free;
          v7 = (int (__cdecl *)(lfo_t *))AMP_GetNext;
          v8 = (void (__thiscall *)(vgui::PropertyPage *))AMP_GetNextN;
          v9 = (dly_t *(__cdecl *)(prc_t *))AMP_VParams;
          v10 = CColorBalanceUIPanel::Init;
          break;
        default:
          v6 = (void (__cdecl *)(flt_t *))CColorBalanceUIPanel::Init;
          v7 = (int (__cdecl *)(lfo_t *))NULL_GetNext;
          v8 = CColorBalanceUIPanel::Init;
          v9 = (dly_t *(__cdecl *)(prc_t *))NULL_VParams;
          v10 = CColorBalanceUIPanel::Init;
          break;
      }
      p_pfnGetNext[2] = (int (__cdecl *)(void *, int))v6;
      *(p_pfnGetNext - 1) = (int (__cdecl *)(void *, int))v9;
      *p_pfnGetNext = (int (__cdecl *)(void *, int))v7;
      p_pfnGetNext[1] = (int (__cdecl *)(void *, int))v8;
      p_pfnGetNext[3] = (int (__cdecl *)(void *, int))v10;
      v11 = v9(p: (prc_t *)(p_pfnGetNext - 18));
      p_pfnGetNext[4] = (int (__cdecl *)(void *, int))v11;
      if ( v11 == nullptr )
        fok = false;
      p_pfnGetNext += 23;
      --counta;
    }
    while ( counta != 0 );
    return fok;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10029E30
// Name: int DSP_Alloc(int,float,int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl DSP_Alloc(int ipset, float xfade, int cchan)
{
  int v3; // ebx
  int v4; // edi
  dsp_t *v5; // eax
  dsp_t *v7; // esi
  pset_t **ppsetprev; // edi
  pset_t *v9; // eax
  double v10; // st7
  int cchans; // [esp+0h] [ebp-4h]
  int idsp; // [esp+14h] [ebp+10h]

  if ( cchan >= 1 )
  {
    cchans = 5;
    if ( cchan <= 5 )
      cchans = cchan;
  }
  else
  {
    cchans = 1;
  }
  v3 = 0;
  v4 = 0;
  v5 = &dsps[1];
  while ( v5[-1].fused )
  {
    if ( !v5->fused )
    {
      ++v4;
      break;
    }
    if ( !v5[1].fused )
    {
      v4 += 2;
      break;
    }
    if ( !v5[2].fused )
    {
      v4 += 3;
      break;
    }
    v5 += 4;
    v4 += 4;
    if ( (int)v5 >= (int)&psets[0].prcs[0].prm[10] )
      return -1;
  }
  idsp = v4;
  if ( v4 >= 32 )
    return -1;
  v7 = &dsps[v4];
  if ( (unsigned int)v4 <= 0x1F )
    _V_memset(dest: &dsps[v4], fill: 0, count: 116);
  *(_WORD *)&v7->fused = 257;
  v7->cchan = cchans;
  v7->ipset = ipset;
  v7->ipsetprev = 0;
  v7->ipsetsav_oneshot = 0;
  ppsetprev = v7->ppsetprev;
  do
  {
    if ( v7->ipset != 0 )
      v9 = PSET_Alloc(ipsettemplate: ipset);
    else
      v9 = nullptr;
    *(ppsetprev - 6) = v9;
    *ppsetprev = nullptr;
    ++v3;
    ++ppsetprev;
  }
  while ( v3 < v7->cchan );
  v7->xramp.fhitend = true;
  v10 = xfade * 0.001;
  v7->xfade = v10;
  v7->xfade_default = v10;
  return idsp;
}

//------------------------------------------------------------------------------
// Address: 0x10029F40
// Name: void DSP_SetPreset(int,int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DSP_SetPreset(int idsp, int ipsetnew, const char *pDspName)
{
  dsp_t *v3; // esi
  int ipset; // eax
  int v5; // edi
  pset_t *v6; // eax
  int v7; // ecx
  pset_t **ppset; // eax
  int v9; // eax
  unsigned int v10; // eax
  int v11; // ecx
  float *p_type; // eax
  pset_t *v13; // eax
  pset_t *v14; // eax
  pset_t *v15; // ecx
  long double v16; // st7
  double xfade_default; // st7
  pset_t *ppsetnew[5]; // [esp+1Ch] [ebp-18h]
  float db_mixdrop; // [esp+30h] [ebp-4h]
  float mix_max; // [esp+3Ch] [ebp+8h]
  float mix_maxa; // [esp+3Ch] [ebp+8h]
  float db_min; // [esp+40h] [ebp+Ch]

  v3 = &dsps[idsp];
  if ( ipsetnew < g_cpsettemplates && ipsetnew >= 0 )
  {
    ipset = v3->ipset;
    if ( ipsetnew != ipset )
    {
      if ( snd_dsp_spew_changes.m_pParent != nullptr && snd_dsp_spew_changes.m_pParent->m_Value.m_nValue != 0 )
        DevMsg(a1: "[Sound DSP] For Dsp %d, %s switch presets from %d to %d.\n", idsp, pDspName, ipset, ipsetnew);
      v5 = 0;
      if ( v3->cchan <= 0 )
      {
LABEL_10:
        DSP_FreePrevPreset(pdsp: v3);
        v7 = 0;
        if ( v3->cchan > 0 )
        {
          ppset = v3->ppset;
          do
          {
            ppset[6] = *ppset;
            *ppset++ = ppsetnew[v7++];
          }
          while ( v7 < v3->cchan );
        }
        v9 = v3->ipset;
        v3->ipsetprev = v9;
        v3->ipset = ipsetnew;
        if ( v9 != 0 )
        {
          v10 = _Plat_MSTime();
          v11 = snd_dsp_cancel_old_preset_after_N_milliseconds.m_pParent != nullptr
              ? snd_dsp_cancel_old_preset_after_N_milliseconds.m_pParent->m_Value.m_nValue
              : 0;
          if ( v10 > v11 + v3->ppsetprev[0]->nLastUpdatedTimeInMilliseconds )
          {
            if ( snd_dsp_spew_changes.m_pParent != nullptr && snd_dsp_spew_changes.m_pParent->m_Value.m_nValue != 0 )
              DevMsg(
                a1: "[Sound DSP] For Dsp %d, %s previous preset %d has not been updated for a while. Do not cross-fade form it.\n",
                idsp,
                pDspName,
                v3->ipsetprev);
            DSP_FreePrevPreset(pdsp: v3);
          }
        }
        if ( idsp == idsp_room || idsp == idsp_automatic )
        {
          p_type = (float *)&v3->ppset[0]->type;
          mix_max = p_type[118];
          db_min = p_type[119];
          db_mixdrop = p_type[120];
          ConVar::SetValue(this: (ConVar *)&dsp_mix_min.IConVar, value: p_type[117]);
          ConVar::SetValue(this: (ConVar *)&dsp_mix_max.IConVar, value: mix_max);
          ConVar::SetValue(this: (ConVar *)&dsp_db_min.IConVar, value: db_min);
          ConVar::SetValue(this: (ConVar *)&dsp_db_mixdrop.IConVar, value: db_mixdrop);
        }
        v13 = v3->ppset[0];
        v3->xramp.fhitend = true;
        v3->ipsetsav_oneshot = 0;
        if ( v13 != nullptr && v13->duration > 0.0 )
        {
          v14 = v3->ppsetprev[0];
          if ( v14 == nullptr || v14->duration <= 0.0 )
            v3->ipsetsav_oneshot = v3->ipsetprev;
        }
        v15 = v3->ppsetprev[0];
        if ( v15 != nullptr && (v16 = fabs(v15->fade)) > 0.0 )
        {
          mix_maxa = v16;
          v3->xfade = mix_maxa;
          v3->bexpfade = v15->fade < 0.0;
        }
        else
        {
          xfade_default = v3->xfade_default;
          v3->bexpfade = false;
          v3->xfade = xfade_default;
        }
        RMP_Init(prmp: &v3->xramp, ramptime: v3->xfade, initval: 0, targetval: 4096, bEndAtTime: false);
      }
      else
      {
        while ( 1 )
        {
          v6 = PSET_Alloc(ipsettemplate: ipsetnew);
          ppsetnew[v5] = v6;
          if ( v6 == nullptr )
            break;
          if ( ++v5 >= v3->cchan )
            goto LABEL_10;
        }
        DevMsg(a1: "WARNING: DSP preset failed to allocate.\n");
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002A180
// Name: bool HandlePresetChange(int,int __near &,int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl HandlePresetChange(unsigned int nDspIndex, int *nPrevPreset, int nNewPreset, const char *pDspName)
{
  dsp_t *v5; // esi

  if ( *nPrevPreset == nNewPreset )
    return 0;
  if ( nDspIndex > 0x1F )
    goto LABEL_10;
  v5 = &dsps[nDspIndex];
  if ( v5->ipsetprev != 0 && v5->xramp.nEndRampTimeInMs < _Plat_MSTime() )
  {
    if ( snd_dsp_spew_changes.m_pParent != nullptr && snd_dsp_spew_changes.m_pParent->m_Value.m_nValue != 0 )
      DevMsg(
        a1: "[Sound DSP] For Dsp %d, don't consider cross fading from presets %d to %d as previous preset is expired.\n",
        nDspIndex,
        v5->ipsetprev,
        v5->ipset);
    goto LABEL_10;
  }
  if ( v5->xramp.fhitend )
  {
LABEL_10:
    DSP_SetPreset(idsp: nDspIndex, ipsetnew: nNewPreset, pDspName);
    *nPrevPreset = nNewPreset;
    return 1;
  }
  if ( snd_dsp_spew_changes.m_pParent != nullptr && snd_dsp_spew_changes.m_pParent->m_Value.m_nValue != 0 )
    DevMsg(
      a1: "[Sound DSP] For Dsp %d, %s changed presets from %d to %d. Have to wait end of cross-fading.\n",
      nDspIndex,
      pDspName,
      *nPrevPreset,
      nNewPreset);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1002A240
// Name: bool DSP_LoadPresetFile(void)
// Source: json
//------------------------------------------------------------------------------
char __cdecl DSP_LoadPresetFile()
{
  char v0; // bl
  const char *v2; // esi
  int v3; // edi
  pset_t *v4; // eax
  const char *v5; // eax
  const char *v6; // esi
  int v7; // edi
  const char *v8; // esi
  const char *v9; // esi
  const char *v10; // esi
  const char *v11; // esi
  const char *v12; // esi
  const char *v13; // esi
  long double v14; // st7
  double v15; // st6
  int v16; // esi
  double v17; // st6
  const char *v18; // ebx
  int v19; // eax
  int v20; // edi
  int v21; // ebx
  double v22; // st7
  int v23; // ebx
  int v24; // edi
  bool v25; // cc
  int v26; // ecx
  char szFile[260]; // [esp+2Ch] [ebp-15Ch] BYREF
  CUtlBuffer buf; // [esp+130h] [ebp-58h] BYREF
  float duration; // [esp+160h] [ebp-28h]
  float db_min; // [esp+164h] [ebp-24h]
  float fadeout; // [esp+168h] [ebp-20h]
  int cpresets; // [esp+16Ch] [ebp-1Ch]
  int itype; // [esp+170h] [ebp-18h]
  int j; // [esp+174h] [ebp-14h]
  int ipreset; // [esp+178h] [ebp-10h]
  const char *pstart; // [esp+17Ch] [ebp-Ch]
  float mix_min; // [esp+180h] [ebp-8h]
  int cproc; // [esp+184h] [ebp-4h]

  v0 = 0;
  V_snprintf(pDest: szFile, maxLen: 260, pFormat: "scripts/dsp_presets.txt");
  CUtlBuffer::CUtlBuffer(this: &buf, growSize: 0, initSize: 0, nFlags: 0);
  if ( g_pFullFileSystem->ReadFile(
         this: &g_pFullFileSystem->IBaseFileSystem,
         a2: szFile,
         a3: "GAME",
         a4: &buf,
         a5: 0,
         a6: 0,
         a7: nullptr) )
  {
    v2 = (const char *)&buf.m_Memory.m_pMemory[buf.m_Get - buf.m_nOffset];
    v3 = DSP_CountFilePresets(pstart: v2);
    cpresets = v3;
    g_cpsettemplates = v3;
    v4 = (pset_t *)MemAlloc_Alloc(nSize: (536 * (unsigned __int64)(unsigned int)v3) >> 32 != 0 ? -1 : 536 * v3);
    g_psettemplates = v4;
    if ( v4 != nullptr )
    {
      memset(dst: (unsigned __int8 *)v4, value: 0, count: 536 * v3);
      v5 = v2;
      j = 0;
      if ( v3 > 0 )
      {
        do
        {
          do
            v5 = COM_Parse(data: v5);
          while ( strlen(com_token) != 0 && com_token[0] != 123 );
          v6 = COM_Parse(data: v5);
          v7 = atoi(nptr: com_token);
          ipreset = v7;
          v8 = COM_Parse(data: v6);
          itype = (int)DSP_LookupStringToken(psz: com_token, ipset: v7);
          v9 = COM_Parse(data: v8);
          mix_min = atof(nptr: com_token);
          v10 = COM_Parse(data: v9);
          *(float *)&cproc = atof(nptr: com_token);
          v11 = COM_Parse(data: v10);
          duration = atof(nptr: com_token);
          v12 = COM_Parse(data: v11);
          fadeout = atof(nptr: com_token);
          v13 = COM_Parse(data: v12);
          db_min = atof(nptr: com_token);
          pstart = COM_Parse(data: v13);
          v14 = atof(nptr: com_token);
          v15 = mix_min;
          v16 = v7;
          g_psettemplates[v16].fused = 1;
          g_psettemplates[v16].mix_min = v15;
          v17 = *(float *)&cproc;
          *(float *)&cproc = 0.0;
          g_psettemplates[v16].mix_max = v17;
          g_psettemplates[v16].duration = duration;
          g_psettemplates[v16].fade = fadeout;
          g_psettemplates[v16].db_min = db_min;
          g_psettemplates[v16].db_mixdrop = v14;
          while ( 1 )
          {
            v5 = COM_Parse(data: pstart);
            if ( strlen(com_token) != 0 )
              break;
LABEL_16:
            v18 = COM_Parse(data: v5);
            v19 = (int)DSP_LookupStringToken(psz: com_token, ipset: ipreset);
            *(int *)((char *)&g_psettemplates->prcs[cproc].type + v16 * 536) = v19;
            v20 = 0;
            for ( pstart = COM_Parse(data: v18); strlen(com_token) != 0; pstart = COM_Parse(data: pstart) )
            {
              if ( com_token[0] == 125 )
                break;
              v21 = ipreset;
              v22 = DSP_LookupStringToken(psz: com_token, ipset: ipreset);
              v23 = v20 + 23 * cproc + 134 * v21;
              ++v20;
              g_psettemplates->prcs[0].prm[v23] = v22;
              if ( v20 >= 16 )
                v20 = 16;
            }
            v24 = cproc + 1;
            cproc = v24;
            v25 = v24 < 5;
            if ( v24 > 5 )
            {
              DevMsg(
                a1: "DSP PARSE ERROR!!! dsp_presets.txt: missing } or too many processors in preset #: %3.0f \n",
                (double)ipreset);
              v25 = v24 < 5;
            }
            if ( !v25 )
              cproc = 5;
          }
          while ( 1 )
          {
            if ( com_token[0] == 123 )
              goto LABEL_16;
            if ( com_token[0] == 125 )
              break;
            v5 = COM_Parse(data: v5);
            if ( strlen(com_token) == 0 )
              goto LABEL_16;
          }
          v26 = cproc;
          if ( cproc == 1 )
            itype = 0;
          g_psettemplates[v16].type = itype;
          g_psettemplates[v16].cprcs = v26;
          ++j;
        }
        while ( j < cpresets );
      }
      v0 = 1;
    }
    else
    {
      _Warning(a1: "DSP Preset Loader: Out of memory.\n");
    }
    if ( buf.m_Memory.m_nGrowSize >= 0 && buf.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: buf.m_Memory.m_pMemory);
    return v0;
  }
  else
  {
    _Error(a1: "DSP_LoadPresetFile: unable to open '%s'\n", szFile);
    if ( buf.m_Memory.m_nGrowSize >= 0 && buf.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: buf.m_Memory.m_pMemory);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002A640
// Name: _DSP_InitAll
// Source: json
//------------------------------------------------------------------------------
void __cdecl DSP_InitAll(bool bLoadPresetFile)
{
  flt_t *v1; // esi
  dly_t *v2; // esi
  rva_t *v3; // esi
  lfo_t *v4; // esi
  crs_t *v5; // esi
  ptc_t *v6; // esi
  env_t *v7; // esi
  efo_t *v8; // esi
  mdy_t *v9; // esi
  amp_t *v10; // esi
  pset_t *v11; // esi
  unsigned int v12; // edi
  dsp_t *v13; // esi

  if ( bLoadPresetFile )
    DSP_LoadPresetFile();
  v1 = flts;
  do
  {
    if ( v1 != nullptr )
      _V_memset(dest: v1, fill: 0, count: 184);
    ++v1;
  }
  while ( (int)v1 < (int)nuls );
  v2 = dlys;
  do
  {
    if ( v2 != nullptr )
      _V_memset(dest: v2, fill: 0, count: 72);
    ++v2;
  }
  while ( (int)v2 < (int)flts );
  v3 = rvas;
  do
  {
    if ( v3 != nullptr )
      _V_memset(dest: v3, fill: 0, count: 116);
    ++v3;
  }
  while ( (int)v3 < (int)mdys );
  LFOWAV_InitAll();
  v4 = lfos;
  do
  {
    if ( v4 != nullptr )
      _V_memset(dest: v4, fill: 0, count: 56);
    ++v4;
  }
  while ( (int)v4 < (int)lfowavs );
  v5 = crss;
  do
  {
    if ( v5 != nullptr )
      _V_memset(dest: v5, fill: 0, count: 16);
    ++v5;
  }
  while ( (int)v5 < (int)efos );
  v6 = ptcs;
  do
  {
    if ( v6 != nullptr )
      _V_memset(dest: v6, fill: 0, count: 72);
    ++v6;
  }
  while ( (int)v6 < (int)lfos );
  v7 = envs;
  do
  {
    if ( v7 != nullptr )
      _V_memset(dest: v7, fill: 0, count: 184);
    ++v7;
  }
  while ( (int)v7 < (int)ptcs );
  v8 = efos;
  do
  {
    if ( v8 != nullptr )
      _V_memset(dest: v8, fill: 0, count: 116);
    ++v8;
  }
  while ( (int)v8 < (int)envs );
  v9 = mdys;
  do
  {
    if ( v9 != nullptr )
      _V_memset(dest: v9, fill: 0, count: 76);
    ++v9;
  }
  while ( (int)v9 < (int)dlys );
  v10 = amps;
  do
  {
    if ( v10 != nullptr )
      _V_memset(dest: v10, fill: 0, count: 92);
    ++v10;
  }
  while ( (int)v10 < (int)crss );
  v11 = psets;
  do
    _V_memset(dest: v11++, fill: 0, count: 536);
  while ( (int)v11 < (int)amps );
  v12 = 0;
  v13 = dsps;
  do
  {
    if ( v12 <= 0x1F )
      _V_memset(dest: v13, fill: 0, count: 116);
    ++v13;
    ++v12;
  }
  while ( (int)v13 < (int)&idsp_automatic );
}

//------------------------------------------------------------------------------
// Address: 0x1002A810
// Name: _AllocDsps
// Source: json
//------------------------------------------------------------------------------
char __cdecl AllocDsps(bool bLoadPresetFile)
{
  int v1; // esi
  BOOL v2; // edi
  int m_nValue; // eax
  int v4; // eax
  int v5; // eax
  int v6; // eax
  int v7; // eax
  int v8; // esi
  int v9; // eax
  int v10; // eax
  int v11; // eax

  v1 = g_AudioDevice->IsSurround(this: g_AudioDevice) ? 2 : 0;
  v2 = g_AudioDevice->IsSurroundCenter(this: g_AudioDevice);
  DSP_InitAll(bLoadPresetFile);
  idsp_room = -1;
  idsp_water = -1;
  idsp_player = -1;
  idsp_facingaway = -1;
  idsp_speaker = -1;
  idsp_spatial = -1;
  idsp_automatic = -1;
  if ( dsp_room.m_pParent != nullptr )
    m_nValue = dsp_room.m_pParent->m_Value.m_nValue;
  else
    m_nValue = 0;
  idsp_room = DSP_Alloc(ipset: m_nValue, xfade: 200.0, cchan: 1);
  if ( dsp_automatic.m_pParent != nullptr )
    v4 = dsp_automatic.m_pParent->m_Value.m_nValue;
  else
    v4 = 0;
  idsp_automatic = DSP_Alloc(ipset: v4, xfade: 200.0, cchan: 1);
  if ( dsp_water.m_pParent != nullptr )
    v5 = dsp_water.m_pParent->m_Value.m_nValue;
  else
    v5 = 0;
  idsp_water = DSP_Alloc(ipset: v5, xfade: 100.0, cchan: 1);
  if ( dsp_player.m_pParent != nullptr )
    v6 = dsp_player.m_pParent->m_Value.m_nValue;
  else
    v6 = 0;
  idsp_player = DSP_Alloc(ipset: v6, xfade: 100.0, cchan: 1);
  if ( dsp_facingaway.m_pParent != nullptr )
    v7 = dsp_facingaway.m_pParent->m_Value.m_nValue;
  else
    v7 = 0;
  v8 = v2 + v1 + 2;
  idsp_facingaway = DSP_Alloc(ipset: v7, xfade: 100.0, cchan: v8);
  if ( dsp_speaker.m_pParent != nullptr )
    v9 = dsp_speaker.m_pParent->m_Value.m_nValue;
  else
    v9 = 0;
  idsp_speaker = DSP_Alloc(ipset: v9, xfade: 300.0, cchan: 1);
  if ( dsp_spatial.m_pParent != nullptr )
    v10 = dsp_spatial.m_pParent->m_Value.m_nValue;
  else
    v10 = 0;
  v11 = DSP_Alloc(ipset: v10, xfade: 300.0, cchan: v8);
  idsp_spatial = v11;
  if ( dsp_room.m_pParent != nullptr )
    ipset_room_prev = dsp_room.m_pParent->m_Value.m_nValue;
  else
    ipset_room_prev = 0;
  if ( dsp_water.m_pParent != nullptr )
    ipset_water_prev = dsp_water.m_pParent->m_Value.m_nValue;
  else
    ipset_water_prev = 0;
  if ( dsp_player.m_pParent != nullptr )
    ipset_player_prev = dsp_player.m_pParent->m_Value.m_nValue;
  else
    ipset_player_prev = 0;
  if ( dsp_facingaway.m_pParent != nullptr )
    ipset_facingaway_prev = dsp_facingaway.m_pParent->m_Value.m_nValue;
  else
    ipset_facingaway_prev = 0;
  if ( dsp_room_type.m_pParent != nullptr )
    ipset_room_typeprev = dsp_room_type.m_pParent->m_Value.m_nValue;
  else
    ipset_room_typeprev = 0;
  if ( dsp_speaker.m_pParent != nullptr )
    ipset_speaker_prev = dsp_speaker.m_pParent->m_Value.m_nValue;
  else
    ipset_speaker_prev = 0;
  if ( dsp_spatial.m_pParent != nullptr )
    ipset_spatial_prev = dsp_spatial.m_pParent->m_Value.m_nValue;
  else
    ipset_spatial_prev = 0;
  if ( dsp_automatic.m_pParent != nullptr )
    ipset_automatic_prev = dsp_automatic.m_pParent->m_Value.m_nValue;
  else
    ipset_automatic_prev = 0;
  if ( idsp_room >= 0
    && idsp_water >= 0
    && idsp_player >= 0
    && idsp_facingaway >= 0
    && idsp_speaker >= 0
    && v11 >= 0
    && idsp_automatic >= 0 )
  {
    return 1;
  }
  DevMsg(a1: "WARNING: DSP processor failed to initialize! \n");
  FreeDsps(bReleaseTemplateMemory: true);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1002AAD0
// Name: void DSP_CheckRestorePresets(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DSP_CheckRestorePresets()
{
  PreserveDSP_t *v0; // esi
  int v1; // esi
  BOOL v2; // edi
  int m_nValue; // eax
  int v4; // eax
  int v5; // eax
  int v6; // eax
  int v7; // eax
  int v8; // esi
  int v9; // eax
  int v10; // eax
  int v11; // eax

  if ( g_bNeedPresetRestore )
  {
    g_bNeedPresetRestore = false;
    v0 = g_PreserveDSP;
    do
    {
      if ( v0->cvar->m_pParent->m_Value.m_fValue == 0.0 )
        ((void (__stdcall *)(_DWORD))v0->cvar->SetValue_3)(a1: v0->oldvalue);
      ++v0;
    }
    while ( (int)v0 < (int)&unk_10411EFC );
    v1 = g_AudioDevice->IsSurround(this: g_AudioDevice) ? 2 : 0;
    v2 = g_AudioDevice->IsSurroundCenter(this: g_AudioDevice);
    DSP_InitAll(bLoadPresetFile: false);
    idsp_room = -1;
    idsp_water = -1;
    idsp_player = -1;
    idsp_facingaway = -1;
    idsp_speaker = -1;
    idsp_spatial = -1;
    idsp_automatic = -1;
    if ( dsp_room.m_pParent != nullptr )
      m_nValue = dsp_room.m_pParent->m_Value.m_nValue;
    else
      m_nValue = 0;
    idsp_room = DSP_Alloc(ipset: m_nValue, xfade: 200.0, cchan: 1);
    if ( dsp_automatic.m_pParent != nullptr )
      v4 = dsp_automatic.m_pParent->m_Value.m_nValue;
    else
      v4 = 0;
    idsp_automatic = DSP_Alloc(ipset: v4, xfade: 200.0, cchan: 1);
    if ( dsp_water.m_pParent != nullptr )
      v5 = dsp_water.m_pParent->m_Value.m_nValue;
    else
      v5 = 0;
    idsp_water = DSP_Alloc(ipset: v5, xfade: 100.0, cchan: 1);
    if ( dsp_player.m_pParent != nullptr )
      v6 = dsp_player.m_pParent->m_Value.m_nValue;
    else
      v6 = 0;
    idsp_player = DSP_Alloc(ipset: v6, xfade: 100.0, cchan: 1);
    if ( dsp_facingaway.m_pParent != nullptr )
      v7 = dsp_facingaway.m_pParent->m_Value.m_nValue;
    else
      v7 = 0;
    v8 = v2 + v1 + 2;
    idsp_facingaway = DSP_Alloc(ipset: v7, xfade: 100.0, cchan: v8);
    if ( dsp_speaker.m_pParent != nullptr )
      v9 = dsp_speaker.m_pParent->m_Value.m_nValue;
    else
      v9 = 0;
    idsp_speaker = DSP_Alloc(ipset: v9, xfade: 300.0, cchan: 1);
    if ( dsp_spatial.m_pParent != nullptr )
      v10 = dsp_spatial.m_pParent->m_Value.m_nValue;
    else
      v10 = 0;
    v11 = DSP_Alloc(ipset: v10, xfade: 300.0, cchan: v8);
    idsp_spatial = v11;
    if ( dsp_room.m_pParent != nullptr )
      ipset_room_prev = dsp_room.m_pParent->m_Value.m_nValue;
    else
      ipset_room_prev = 0;
    if ( dsp_water.m_pParent != nullptr )
      ipset_water_prev = dsp_water.m_pParent->m_Value.m_nValue;
    else
      ipset_water_prev = 0;
    if ( dsp_player.m_pParent != nullptr )
      ipset_player_prev = dsp_player.m_pParent->m_Value.m_nValue;
    else
      ipset_player_prev = 0;
    if ( dsp_facingaway.m_pParent != nullptr )
      ipset_facingaway_prev = dsp_facingaway.m_pParent->m_Value.m_nValue;
    else
      ipset_facingaway_prev = 0;
    if ( dsp_room_type.m_pParent != nullptr )
      ipset_room_typeprev = dsp_room_type.m_pParent->m_Value.m_nValue;
    else
      ipset_room_typeprev = 0;
    if ( dsp_speaker.m_pParent != nullptr )
      ipset_speaker_prev = dsp_speaker.m_pParent->m_Value.m_nValue;
    else
      ipset_speaker_prev = 0;
    if ( dsp_spatial.m_pParent != nullptr )
      ipset_spatial_prev = dsp_spatial.m_pParent->m_Value.m_nValue;
    else
      ipset_spatial_prev = 0;
    if ( dsp_automatic.m_pParent != nullptr )
      ipset_automatic_prev = dsp_automatic.m_pParent->m_Value.m_nValue;
    else
      ipset_automatic_prev = 0;
    if ( idsp_room < 0
      || idsp_water < 0
      || idsp_player < 0
      || idsp_facingaway < 0
      || idsp_speaker < 0
      || v11 < 0
      || idsp_automatic < 0 )
    {
      DevMsg(a1: "WARNING: DSP processor failed to initialize! \n");
      FreeDsps(bReleaseTemplateMemory: true);
    }
    g_bdas_init_nodes = false;
    g_bdas_room_init = false;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002AE00
// Name: _CheckNewDspPresets
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
char CheckNewDspPresets()
{
  int v0; // edi
  int m_nValue; // eax
  bool v2; // bl
  int v3; // ebx
  int ipsetsav_oneshot; // esi
  pset_t *v5; // eax
  unsigned int v6; // edx
  pset_t *v7; // ecx
  int iautomatic; // [esp+Ch] [ebp-14h]
  int ispatial; // [esp+10h] [ebp-10h]
  int ifacingaway; // [esp+14h] [ebp-Ch]
  int iroomtype; // [esp+18h] [ebp-8h]
  int iroom; // [esp+1Ch] [ebp-4h]

  v0 = 0;
  if ( dsp_slow_cpu.m_pParent != nullptr )
    m_nValue = dsp_slow_cpu.m_pParent->m_Value.m_nValue;
  else
    m_nValue = 0;
  v2 = m_nValue != 0;
  DSP_CheckRestorePresets();
  if ( v2 )
  {
    iroom = 0;
    iroomtype = 0;
  }
  else
  {
    if ( dsp_room.m_pParent != nullptr )
      iroom = dsp_room.m_pParent->m_Value.m_nValue;
    else
      iroom = 0;
    if ( dsp_room_type.m_pParent != nullptr )
      iroomtype = dsp_room_type.m_pParent->m_Value.m_nValue;
    else
      iroomtype = 0;
  }
  if ( dsp_water.m_pParent != nullptr )
    v3 = dsp_water.m_pParent->m_Value.m_nValue;
  else
    v3 = 0;
  if ( dsp_player.m_pParent != nullptr )
    ipsetsav_oneshot = dsp_player.m_pParent->m_Value.m_nValue;
  else
    ipsetsav_oneshot = 0;
  if ( dsp_speaker.m_pParent != nullptr )
    v0 = dsp_speaker.m_pParent->m_Value.m_nValue;
  if ( ipsetsav_oneshot == ipset_player_prev
    && ((unsigned int)idsp_player >= 0x20 || dsps[idsp_player].xramp.fhitend)
    && (unsigned int)idsp_player <= 0x1F )
  {
    v5 = dsps[idsp_player].ppset[0];
    if ( v5 != nullptr && v5->duration > 0.0 && v5->csamp_duration <= 0 )
    {
      ipsetsav_oneshot = dsps[idsp_player].ipsetsav_oneshot;
      CLoaderMemAlloc::CrtIsValidPointer(this: (ConVar *)&dsp_player.IConVar, value: ipsetsav_oneshot);
    }
  }
  v6 = idsp_room;
  if ( iroom == ipset_room_prev
    && ((unsigned int)idsp_room >= 0x20 || dsps[idsp_room].xramp.fhitend)
    && (unsigned int)idsp_room <= 0x1F )
  {
    v7 = dsps[idsp_room].ppset[0];
    if ( v7 != nullptr && v7->duration > 0.0 && v7->csamp_duration <= 0 )
    {
      iroom = dsps[idsp_room].ipsetsav_oneshot;
      CLoaderMemAlloc::CrtIsValidPointer(this: (ConVar *)&dsp_room.IConVar, value: iroom);
      v6 = idsp_room;
    }
  }
  if ( iroomtype != ipset_room_typeprev )
  {
    ipset_room_typeprev = iroomtype;
    CLoaderMemAlloc::CrtIsValidPointer(this: (ConVar *)&dsp_room.IConVar, value: iroomtype);
    v6 = idsp_room;
  }
  if ( HandlePresetChange(nDspIndex: v6, nPrevPreset: &ipset_room_prev, nNewPreset: iroom, pDspName: "room") != 0 )
  {
    CLoaderMemAlloc::CrtIsValidPointer(this: (ConVar *)&dsp_room_type.IConVar, value: iroom);
    ipset_room_typeprev = iroom;
  }
  HandlePresetChange(nDspIndex: idsp_water, nPrevPreset: &ipset_water_prev, nNewPreset: v3, pDspName: "water");
  HandlePresetChange(
    nDspIndex: idsp_player,
    nPrevPreset: &ipset_player_prev,
    nNewPreset: ipsetsav_oneshot,
    pDspName: "player");
  HandlePresetChange(
    nDspIndex: idsp_facingaway,
    nPrevPreset: &ipset_facingaway_prev,
    nNewPreset: ifacingaway,
    pDspName: "facingaway");
  HandlePresetChange(nDspIndex: idsp_speaker, nPrevPreset: &ipset_speaker_prev, nNewPreset: v0, pDspName: "speaker");
  HandlePresetChange(
    nDspIndex: idsp_spatial,
    nPrevPreset: &ipset_spatial_prev,
    nNewPreset: ispatial,
    pDspName: "spatial");
  return HandlePresetChange(
           nDspIndex: idsp_automatic,
           nPrevPreset: &ipset_automatic_prev,
           nNewPreset: iautomatic,
           pDspName: "automatic");
}

//------------------------------------------------------------------------------
// Address: 0x1002B0B0
// Name: void DSP_DEBUGSetParams(int,int,float __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DSP_DEBUGSetParams(int ipreset, int iproc, float *pvalues, int cparams)
{
  int v4; // edx
  pset_t *v5; // eax
  int v6; // esi
  prc_t *v7; // ebx
  unsigned int v8; // edx
  float *v9; // eax
  float *v10; // ecx
  double v11; // st7
  pset_t new_pset; // [esp+0h] [ebp-21Ch] BYREF
  pset_t *v13; // [esp+218h] [ebp-4h]

  if ( cparams >= 0 )
  {
    if ( cparams <= 16 )
    {
      v4 = cparams;
    }
    else
    {
      cparams = 16;
      v4 = 16;
    }
  }
  else
  {
    v4 = 0;
    cparams = 0;
  }
  v5 = &g_psettemplates[ipreset];
  new_pset = *v5;
  v6 = 0;
  v13 = v5;
  v7 = &new_pset.prcs[iproc];
  if ( v4 >= 4 )
  {
    v8 = ((unsigned int)(v4 - 4) >> 2) + 1;
    v9 = pvalues + 1;
    v10 = &v7->prm[2];
    v6 = 4 * v8;
    do
    {
      v11 = *(v9 - 1);
      v9 += 4;
      *(float *)((char *)v9 + (char *)v7 - (char *)pvalues - 16) = v11;
      v10 += 4;
      --v8;
      *(v10 - 5) = *(v9 - 4);
      *(v10 - 4) = *(v9 - 3);
      *(v10 - 3) = *(v9 - 2);
    }
    while ( v8 != 0 );
    v4 = cparams;
    v5 = v13;
  }
  if ( v6 < v4 )
    qmemcpy(&v7->prm[v6], &pvalues[v6], 4 * (v4 - v6));
  *v5 = new_pset;
  CLoaderMemAlloc::CrtIsValidPointer(this: (ConVar *)&dsp_room.IConVar, value: 0);
  CheckNewDspPresets();
  CLoaderMemAlloc::CrtIsValidPointer(this: (ConVar *)&dsp_room.IConVar, value: ipreset);
  CheckNewDspPresets();
}

//------------------------------------------------------------------------------
// Address: 0x1002B1B0
// Name: void DSP_DEBUGReloadPresetFile(void)
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __cdecl DSP_DEBUGReloadPresetFile()
{
  int m_nValue; // ebx
  int v1; // edi
  int v2; // esi
  int iwater; // [esp+0h] [ebp-8h]
  int iroom; // [esp+4h] [ebp-4h]

  if ( dsp_room.m_pParent != nullptr )
    iroom = dsp_room.m_pParent->m_Value.m_nValue;
  else
    iroom = 0;
  if ( dsp_water.m_pParent != nullptr )
    iwater = dsp_water.m_pParent->m_Value.m_nValue;
  else
    iwater = 0;
  if ( dsp_player.m_pParent != nullptr )
    m_nValue = dsp_player.m_pParent->m_Value.m_nValue;
  else
    m_nValue = 0;
  if ( dsp_speaker.m_pParent != nullptr )
    v1 = dsp_speaker.m_pParent->m_Value.m_nValue;
  else
    v1 = 0;
  if ( dsp_spatial.m_pParent != nullptr )
    v2 = dsp_spatial.m_pParent->m_Value.m_nValue;
  else
    v2 = 0;
  if ( g_psettemplates != nullptr )
  {
    free(pMem: g_psettemplates);
    g_psettemplates = nullptr;
  }
  DSP_LoadPresetFile();
  CLoaderMemAlloc::CrtIsValidPointer(this: (ConVar *)&dsp_room.IConVar, value: 0);
  CLoaderMemAlloc::CrtIsValidPointer(this: (ConVar *)&dsp_water.IConVar, value: 0);
  CLoaderMemAlloc::CrtIsValidPointer(this: (ConVar *)&dsp_player.IConVar, value: 0);
  CLoaderMemAlloc::CrtIsValidPointer(this: (ConVar *)&dsp_speaker.IConVar, value: 0);
  CLoaderMemAlloc::CrtIsValidPointer(this: (ConVar *)&dsp_spatial.IConVar, value: 0);
  CheckNewDspPresets();
  CLoaderMemAlloc::CrtIsValidPointer(this: (ConVar *)&dsp_room.IConVar, value: iroom);
  CLoaderMemAlloc::CrtIsValidPointer(this: (ConVar *)&dsp_water.IConVar, value: iwater);
  CLoaderMemAlloc::CrtIsValidPointer(this: (ConVar *)&dsp_player.IConVar, value: m_nValue);
  CLoaderMemAlloc::CrtIsValidPointer(this: (ConVar *)&dsp_speaker.IConVar, value: v1);
  CLoaderMemAlloc::CrtIsValidPointer(this: (ConVar *)&dsp_spatial.IConVar, value: v2);
  CheckNewDspPresets();
  g_bdas_init_nodes = false;
  g_bdas_room_init = false;
}

} // namespace engine_xlsp
