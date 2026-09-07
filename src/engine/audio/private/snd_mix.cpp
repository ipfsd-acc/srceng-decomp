// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: engine/audio/private/snd_mix.cpp
// Functions: 90
// ============================================================

#include "engine\audio\private\snd_mix.h"

//------------------------------------------------------------------------------
// Address: 0x1002B6E0
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
// Address: 0x1002B750
// Name: double MIX_GetMaxRate(double,int)
// Source: json
//------------------------------------------------------------------------------
double __cdecl MIX_GetMaxRate(double rate)
{
  double result; // st7

  result = rate;
  if ( rate > 2.0 )
  {
    result = 8.031372549019608;
    if ( rate <= 8.031372549019608 )
      return rate;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1002B780
// Name: void S_Interpolate2xCubic(struct portable_samplepair_t __near *,struct portable_samplepair_t __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl S_Interpolate2xCubic(
        portable_samplepair_t *pbuffer,
        portable_samplepair_t *pfiltermem,
        int cfltmem,
        int count)
{
  portable_samplepair_t *v4; // edx
  int v5; // esi
  int v6; // ecx
  portable_samplepair_t *v7; // edi
  int v8; // esi
  int v9; // eax
  int *p_left; // eax
  portable_samplepair_t *v11; // ebx
  int v12; // ecx
  int right; // edi
  int v14; // ecx
  int v15; // ebx
  int v16; // kr20_4
  int v17; // eax
  int v18; // eax
  int v19; // [esp+Ch] [ebp-18h]
  int x2; // [esp+10h] [ebp-14h]
  portable_samplepair_t *psamp1; // [esp+14h] [ebp-10h]
  portable_samplepair_t *psamp2; // [esp+18h] [ebp-Ch]
  int psamp2a; // [esp+18h] [ebp-Ch]
  portable_samplepair_t *psamp0; // [esp+20h] [ebp-4h]

  v4 = pfiltermem;
  v5 = 2 * count;
  v6 = 0;
  v7 = pbuffer;
  if ( count > 0 )
  {
    v8 = 0;
    do
    {
      if ( v6 != 0 )
      {
        if ( v6 == 1 )
        {
          v9 = (int)&v4[1];
        }
        else if ( v6 == 2 )
        {
          v9 = (int)&v4[2];
        }
        else
        {
          v9 = (int)&v7[2 * v6 - 5];
        }
        psamp0 = (portable_samplepair_t *)v9;
      }
      else
      {
        psamp0 = v4;
      }
      if ( v6 == -1 )
      {
        p_left = &v4->left;
        psamp1 = v4;
      }
      else
      {
        if ( v6 != 0 )
        {
          if ( v6 == 1 )
            p_left = &v4[2].left;
          else
            p_left = &v7[2 * v6 - 3].left;
        }
        else
        {
          p_left = &v4[1].left;
        }
        psamp1 = (portable_samplepair_t *)p_left;
      }
      v19 = v6 + 1;
      if ( v6 == -2 )
      {
        v11 = v4;
        psamp2 = v4;
      }
      else
      {
        if ( v6 == -1 )
        {
          v11 = v4 + 1;
        }
        else if ( v6 != 0 )
        {
          v11 = &v7[2 * v6 - 1];
        }
        else
        {
          v11 = v4 + 2;
        }
        psamp2 = v11;
      }
      v12 = v6 + 2;
      if ( v12 != -1 )
      {
        if ( v12 != 0 )
        {
          if ( v12 == 1 )
            v4 += 2;
          else
            v4 = &v7[2 * v12 - 3];
        }
        else
        {
          ++v4;
        }
      }
      g_temppaintbuffer[v8].left = *p_left;
      g_temppaintbuffer[v8].right = p_left[1];
      g_temppaintbuffer[v8 + 1].left = (psamp0->left + 2 * v11->left - (*p_left + v4->left + 4 * *p_left) / 2) / 4
                                     + *p_left
                                     + (v4->left + 3 * (*p_left - v11->left) - psamp0->left) / 2 / 8
                                     + (psamp2->left - psamp0->left) / 2 / 2;
      right = psamp0->right;
      v14 = psamp1->right;
      v15 = psamp2->right;
      x2 = v4->right;
      psamp2a = (right + 2 * v15 - (v14 + x2 + 4 * v14) / 2) / 4;
      v8 += 2;
      v16 = (x2 + 3 * (v14 - v15) - right) / 2;
      v17 = v15 - right;
      v7 = pbuffer;
      v4 = pfiltermem;
      g_temppaintbuffer[v8 - 1].right = psamp2a + v14 + v16 / 8 + v17 / 2 / 2;
      v6 = v19;
    }
    while ( v19 < count );
    v5 = 2 * count;
  }
  v4->left = v7[v5 - 5].left;
  v4->right = *((_DWORD *)&v7[v5 - 4] - 1);
  v4[1].left = v7[v5 - 3].left;
  v4[1].right = *((_DWORD *)&v7[v5 - 2] - 1);
  v4[2].left = v7[v5 - 1].left;
  v18 = 0;
  for ( v4[2].right = v7[v5 - 1].right; v18 < v5; ++v18 )
    v7[v18] = g_temppaintbuffer[v18];
}

//------------------------------------------------------------------------------
// Address: 0x1002B9B0
// Name: void S_Interpolate2xLinear(struct portable_samplepair_t __near *,struct portable_samplepair_t __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl S_Interpolate2xLinear(
        portable_samplepair_t *pbuffer,
        portable_samplepair_t *pfiltermem,
        int cfltmem,
        int count)
{
  int *p_right; // eax
  unsigned int v5; // ecx
  int v6; // ebx

  pbuffer->left = (pfiltermem->left + pbuffer->left) >> 1;
  pbuffer->right = (pbuffer->right + pfiltermem->right) >> 1;
  if ( 2 * count > 2 )
  {
    p_right = &pbuffer[2].right;
    v5 = ((unsigned int)(2 * count - 3) >> 1) + 1;
    do
    {
      v6 = *(p_right - 1) + *(p_right - 3);
      p_right += 4;
      *(p_right - 5) = v6 >> 1;
      --v5;
      *(p_right - 4) = (*(p_right - 4) + *(p_right - 6)) >> 1;
    }
    while ( v5 != 0 );
  }
  *pfiltermem = pbuffer[2 * count - 1];
}

//------------------------------------------------------------------------------
// Address: 0x1002BA10
// Name: void S_Interpolate2xLinear_2(int,struct portable_samplepair_t __near *,struct portable_samplepair_t __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl S_Interpolate2xLinear_2(int count, portable_samplepair_t *pbuffer, portable_samplepair_t *pfiltermem)
{
  portable_samplepair_t *v3; // ecx
  int left; // esi
  portable_samplepair_t *v5; // edx
  int right; // edi
  portable_samplepair_t *v7; // eax
  portable_samplepair_t *v8; // edx
  int *p_left; // ecx
  int v10; // esi
  int v11; // edi
  int v12; // esi
  int v13; // edi
  int v14; // esi
  int v15; // edi
  int v16; // esi
  int v17; // edi
  int v18; // esi
  int v19; // edi
  int v20; // esi
  int v21; // edi
  int v22; // esi
  int v23; // edi
  int *p_right; // eax
  portable_samplepair_t *v25; // [esp+Ch] [ebp-4h]
  unsigned int counta; // [esp+18h] [ebp+8h]

  v3 = pbuffer;
  left = pbuffer[count - 1].left;
  v5 = &pbuffer[count - 1];
  right = v5->right;
  v7 = &pbuffer[2 * count - 1];
  v8 = v5 - 1;
  v25 = v7;
  if ( count - 1 >= 8 )
  {
    p_left = &v8[-1].left;
    counta = (unsigned int)(count - 1) >> 3;
    do
    {
      v7->left = left;
      v7->right = right;
      v7[-1].left = (left + v8->left) >> 1;
      v7[-1].right = (right + p_left[3]) >> 1;
      v10 = v8->left;
      v11 = v8->right;
      v7[-2].left = v8->left;
      v7[-2].right = v11;
      v7[-3].left = (v10 + *p_left) >> 1;
      v7[-3].right = (v11 + p_left[1]) >> 1;
      v12 = *p_left;
      v13 = p_left[1];
      v7[-4].left = *p_left;
      v7[-4].right = v13;
      v7[-5].left = (v12 + *(p_left - 2)) >> 1;
      v7[-5].right = (v13 + *(p_left - 1)) >> 1;
      v14 = *(p_left - 2);
      v15 = *(p_left - 1);
      v7[-6].left = v14;
      v7[-6].right = v15;
      v7[-7].left = (v14 + *(p_left - 4)) >> 1;
      v7[-7].right = (v15 + *(p_left - 3)) >> 1;
      v16 = *(p_left - 4);
      v17 = *(p_left - 3);
      v7[-8].left = v16;
      v7[-8].right = v17;
      v7[-9].left = (v16 + *(p_left - 6)) >> 1;
      v7[-9].right = (v17 + *(p_left - 5)) >> 1;
      v18 = *(p_left - 6);
      v19 = *(p_left - 5);
      v7[-10].left = v18;
      v7[-10].right = v19;
      v7[-11].left = (v18 + *(p_left - 8)) >> 1;
      v7[-11].right = (v19 + *(p_left - 7)) >> 1;
      v20 = *(p_left - 8);
      v21 = *(p_left - 7);
      v7[-12].left = v20;
      v7[-12].right = v21;
      v7[-13].left = (v20 + *(p_left - 10)) >> 1;
      v7[-13].right = (v21 + *(p_left - 9)) >> 1;
      v22 = *(p_left - 10);
      v23 = *(p_left - 9);
      v7[-14].left = v22;
      v7[-14].right = v23;
      v7[-15].left = (v22 + *(p_left - 12)) >> 1;
      v7[-15].right = (v23 + *(p_left - 11)) >> 1;
      left = *(p_left - 12);
      right = *(p_left - 11);
      v8 -= 8;
      p_left -= 16;
      v7 -= 16;
      --counta;
    }
    while ( counta != 0 );
    v3 = pbuffer;
  }
  if ( v8 >= v3 )
  {
    p_right = &v7[-1].right;
    do
    {
      p_right[1] = left;
      p_right[2] = right;
      *(p_right - 1) = (left + v8->left) >> 1;
      *p_right = (right + v8->right) >> 1;
      left = v8->left;
      right = v8->right;
      --v8;
      p_right -= 4;
    }
    while ( v8 >= v3 );
  }
  v3[1].left = left;
  v3[1].right = right;
  v3->left = (left + pfiltermem->left) >> 1;
  v3->right = (right + pfiltermem->right) >> 1;
  *pfiltermem = *v25;
}

//------------------------------------------------------------------------------
// Address: 0x1002BBC0
// Name: void S_Interpolate2xLinear_3(int,struct portable_samplepair_t __near *,struct portable_samplepair_t __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl S_Interpolate2xLinear_3(int count, portable_samplepair_t *pbuffer, portable_samplepair_t *pfiltermem)
{
  portable_samplepair_t *v3; // ebx
  int left; // edx
  int right; // esi
  portable_samplepair_t *v6; // edi
  portable_samplepair_t *v7; // ecx
  int *p_right; // eax
  int v9; // edi
  int v10; // ebx
  int v11; // edx
  int v12; // esi
  int v13; // ebx
  int v14; // edi
  int v15; // edx
  int v16; // esi
  int v17; // ebx
  int v18; // edi
  int v19; // edx
  int v20; // esi
  int v21; // edi
  int v22; // ebx
  bool v23; // zf
  int *v24; // eax
  int v25; // edi
  int v26; // edx
  int v27; // eax
  int v28; // esi
  portable_samplepair_t *v29; // [esp+Ch] [ebp-8h]
  int sample; // [esp+10h] [ebp-4h]
  int samplea; // [esp+10h] [ebp-4h]
  int nLeft; // [esp+1Ch] [ebp+8h]
  int nRight; // [esp+20h] [ebp+Ch]

  v3 = pbuffer;
  left = pbuffer[count - 1].left;
  right = pbuffer[count - 1].right;
  v6 = &pbuffer[2 * count - 1];
  v7 = &pbuffer[count - 2];
  sample = count - 1;
  v29 = v6;
  nLeft = (int)v6;
  if ( sample >= 8 )
  {
    p_right = &v6[-2].right;
    samplea = (unsigned int)sample >> 3;
    do
    {
      v6->left = left;
      p_right[4] = right;
      v9 = v7->left;
      v10 = v7->right;
      p_right[1] = (v7->left + left) >> 1;
      p_right[2] = (v10 + right) >> 1;
      *(p_right - 1) = v9;
      *p_right = v10;
      v11 = v7[-1].left;
      v12 = v7[-1].right;
      *(p_right - 3) = (v11 + v9) >> 1;
      *(p_right - 2) = (v12 + v10) >> 1;
      *(p_right - 5) = v11;
      *(p_right - 4) = v12;
      v13 = v7[-2].right;
      v14 = v7[-2].left;
      *(p_right - 7) = (v14 + v11) >> 1;
      *(p_right - 6) = (v13 + v12) >> 1;
      *(p_right - 9) = v14;
      *(p_right - 8) = v13;
      v15 = v7[-3].left;
      v16 = v7[-3].right;
      *(p_right - 11) = (v15 + v14) >> 1;
      *(p_right - 10) = (v16 + v13) >> 1;
      *(p_right - 13) = v15;
      *(p_right - 12) = v16;
      v17 = v7[-4].right;
      v18 = v7[-4].left;
      *(p_right - 15) = (v18 + v15) >> 1;
      *(p_right - 14) = (v17 + v16) >> 1;
      *(p_right - 17) = v18;
      *(p_right - 16) = v17;
      v19 = v7[-5].left;
      v20 = v7[-5].right;
      *(p_right - 19) = (v19 + v18) >> 1;
      *(p_right - 18) = (v20 + v17) >> 1;
      *(p_right - 21) = v19;
      *(p_right - 20) = v20;
      v21 = v7[-6].left;
      v22 = v7[-6].right;
      *(p_right - 23) = (v21 + v19) >> 1;
      *(p_right - 22) = (v22 + v20) >> 1;
      *(p_right - 25) = v21;
      *(p_right - 24) = v22;
      left = v7[-7].left;
      right = v7[-7].right;
      *(p_right - 27) = (left + v21) >> 1;
      *(p_right - 26) = (right + v22) >> 1;
      v7 -= 8;
      v6 = (portable_samplepair_t *)(nLeft - 128);
      p_right -= 32;
      v23 = samplea-- == 1;
      nLeft -= 128;
    }
    while ( !v23 );
    v3 = pbuffer;
  }
  if ( v7 >= v3 )
  {
    v24 = &v6->right;
    do
    {
      *(v24 - 1) = left;
      *v24 = right;
      nRight = v7->right;
      v25 = v7->left;
      *(v24 - 3) = (v7->left + left) >> 1;
      v26 = right + nRight;
      right = nRight;
      *(v24 - 2) = v26 >> 1;
      --v7;
      v24 -= 4;
      left = v25;
    }
    while ( v7 >= v3 );
  }
  v3[1].right = right;
  v3[1].left = left;
  v27 = right + pfiltermem->right;
  v28 = pfiltermem->left;
  v3->right = v27 >> 1;
  v3->left = (left + v28) >> 1;
  *pfiltermem = *v29;
}

//------------------------------------------------------------------------------
// Address: 0x1002BD60
// Name: _MIX_SetCurrentPaintbuffer
// Source: json
//------------------------------------------------------------------------------
void __cdecl MIX_SetCurrentPaintbuffer(int ipaintbuffer)
{
  paintbuffer_t *v1; // eax

  v1 = &g_paintBuffers[ipaintbuffer];
  g_curpaintbuffer = v1->pbuf;
  if ( v1->fsurround )
  {
    g_currearpaintbuffer = v1->pbufrear;
    g_curcenterpaintbuffer = nullptr;
    if ( v1->fsurround_center )
      g_curcenterpaintbuffer = v1->pbufcenter;
  }
  else
  {
    g_currearpaintbuffer = nullptr;
    g_curcenterpaintbuffer = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002BDB0
// Name: _MIX_GetCurrentPaintbufferIndex
// Source: json
//------------------------------------------------------------------------------
int __cdecl MIX_GetCurrentPaintbufferIndex()
{
  int result; // eax
  portable_samplepair_t **i; // ecx

  result = 0;
  for ( i = &g_paintBuffers->pbuf; g_curpaintbuffer != *i; i += 78 )
  {
    if ( ++result >= 6 )
      return 0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1002BDE0
// Name: _MIX_GetCurrentPaintbufferPtr
// Source: json
//------------------------------------------------------------------------------
paintbuffer_t *__cdecl MIX_GetCurrentPaintbufferPtr()
{
  int v0; // eax
  portable_samplepair_t **i; // ecx

  v0 = 0;
  for ( i = &g_paintBuffers->pbuf; g_curpaintbuffer != *i; i += 78 )
  {
    if ( ++v0 >= 6 )
    {
      v0 = 0;
      return &g_paintBuffers[v0];
    }
  }
  return &g_paintBuffers[v0];
}

//------------------------------------------------------------------------------
// Address: 0x1002BE10
// Name: struct portable_samplepair_t __near * MIX_GetPRearFromIPaint(int)
// Source: json
//------------------------------------------------------------------------------
portable_samplepair_t *__cdecl MIX_GetPRearFromIPaint(int ipaintbuffer)
{
  if ( g_paintBuffers[ipaintbuffer].fsurround )
    return g_paintBuffers[ipaintbuffer].pbufrear;
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1002BE40
// Name: struct portable_samplepair_t __near * MIX_GetPCenterFromIPaint(int)
// Source: json
//------------------------------------------------------------------------------
portable_samplepair_t *__cdecl MIX_GetPCenterFromIPaint(int ipaintbuffer)
{
  if ( g_paintBuffers[ipaintbuffer].fsurround_center )
    return g_paintBuffers[ipaintbuffer].pbufcenter;
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1002BE70
// Name: void MIX_ConvertBufferToSurround(int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MIX_ConvertBufferToSurround(int ipaintbuffer)
{
  int v1; // esi
  paintbuffer_t *v2; // edi
  portable_samplepair_t *pbuf; // edi
  portable_samplepair_t *pbufrear; // ecx
  portable_samplepair_t *pbufcenter; // esi

  v1 = ipaintbuffer;
  v2 = &g_paintBuffers[ipaintbuffer];
  if ( g_AudioDevice->IsSurround(this: g_AudioDevice) )
  {
    v2->fsurround = g_AudioDevice->IsSurround(this: g_AudioDevice);
    v2->fsurround_center = g_AudioDevice->IsSurroundCenter(this: g_AudioDevice);
    pbuf = g_paintBuffers[v1].pbuf;
    if ( g_paintBuffers[v1].fsurround )
      pbufrear = g_paintBuffers[v1].pbufrear;
    else
      pbufrear = nullptr;
    if ( g_paintBuffers[v1].fsurround_center )
      pbufcenter = g_paintBuffers[v1].pbufcenter;
    else
      pbufcenter = nullptr;
    _V_memcpy(dest: pbufrear, src: pbuf, count: 8160);
    if ( g_AudioDevice->IsSurroundCenter(this: g_AudioDevice) )
      _V_memcpy(dest: pbufcenter, src: pbuf, count: 8160);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002BF20
// Name: _MIX_ClearAllPaintBuffers
// Source: json
//------------------------------------------------------------------------------
void __cdecl MIX_ClearAllPaintBuffers(int SampleCount, bool clearFilters)
{
  paintbuffer_t *v2; // eax
  int v3; // edi
  int i; // esi
  portable_samplepair_t *pbuf; // ecx
  portable_samplepair_t *pbufrear; // ecx
  portable_samplepair_t *pbufcenter; // ecx

  v2 = g_paintBuffers;
  if ( g_paintBuffers != nullptr )
  {
    v3 = SampleCount;
    if ( SampleCount >= 1020 )
      v3 = 1020;
    for ( i = 0; i < 6; ++i )
    {
      pbuf = v2[i].pbuf;
      if ( pbuf != nullptr )
      {
        _V_memset(dest: pbuf, fill: 0, count: 8 * v3 + 8);
        v2 = g_paintBuffers;
      }
      pbufrear = v2[i].pbufrear;
      if ( pbufrear != nullptr )
      {
        _V_memset(dest: pbufrear, fill: 0, count: 8 * v3 + 8);
        v2 = g_paintBuffers;
      }
      pbufcenter = v2[i].pbufcenter;
      if ( pbufcenter != nullptr )
      {
        _V_memset(dest: pbufcenter, fill: 0, count: 8 * v3 + 8);
        v2 = g_paintBuffers;
      }
      if ( clearFilters )
      {
        _V_memset(dest: v2[i].fltmem, fill: 0, count: 96);
        _V_memset(dest: g_paintBuffers[i].fltmemrear, fill: 0, count: 96);
        _V_memset(dest: g_paintBuffers[i].fltmemcenter, fill: 0, count: 96);
        v2 = g_paintBuffers;
      }
    }
    if ( clearFilters )
    {
      v2->ifilter = 0;
      g_paintBuffers[1].ifilter = 0;
      g_paintBuffers[2].ifilter = 0;
      g_paintBuffers[3].ifilter = 0;
      g_paintBuffers[4].ifilter = 0;
      g_paintBuffers[5].ifilter = 0;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002C050
// Name: void Mix255_SIMD(class CMixData __near &)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __usercall Mix255_SIMD(__m128i *a1@<ebp>, CMixData *data)
{
  __m128i *count; // ecx
  portable_samplepair_t *pbufrear2; // edx
  portable_samplepair_t *pbuf3; // esi
  portable_samplepair_t *pbuf1; // ecx
  portable_samplepair_t *pbufcenter3; // edx
  const __m128i *pbuf2; // edi
  __m128i *v8; // eax
  int v9; // eax
  __m128 si128; // xmm1
  __m128 v11; // xmm2
  __m128 v12; // xmm3
  __m128i v13; // xmm5
  __m128i v14; // xmm6
  __m128 v15; // xmm0
  __m128i v16; // xmm7
  __m128i *v17; // edx
  __m128i v18; // xmm4
  __m128i v19; // xmm5
  __m128i v20; // xmm6
  __m128i v21; // xmm7
  __m128i v22; // xmm4
  __m128i v23; // xmm5
  __m128i v24; // xmm6
  __m128i v25; // xmm7
  const __m128i *v26; // edx
  __m128i v27; // xmm1
  __m128i v28; // xmm4
  __m128i v29; // xmm2
  __m128i v30; // xmm5
  __m128i *v31; // edx
  bool v32; // zf
  portable_samplepair_t *v33; // edx
  int *v34; // esi
  int left; // eax
  int v36; // edx
  signed int v37; // eax
  _BYTE v38[28]; // [esp-Ch] [ebp-4Ch] OVERLAPPED BYREF
  char *v39; // [esp+10h] [ebp-30h]
  unsigned int v40; // [esp+14h] [ebp-2Ch]
  int v41; // [esp+18h] [ebp-28h]
  unsigned int v42; // [esp+1Ch] [ebp-24h]
  __m128i *v43; // [esp+20h] [ebp-20h]
  portable_samplepair_t *pbufcenter2; // [esp+24h] [ebp-1Ch]
  int r; // [esp+28h] [ebp-18h]
  __m128i *pCenterDst; // [esp+2Ch] [ebp-14h]
  __m128i *pCenterSrc2; // [esp+30h] [ebp-10h]
  __m128i *pRearDst; // [esp+34h] [ebp-Ch]
  int nCount; // [esp+38h] [ebp-8h]
  int retaddr; // [esp+40h] [ebp+0h]

  pRearDst = a1;
  nCount = retaddr;
  count = (__m128i *)data->count;
  r = (int)data->pbufrear3;
  pbufrear2 = data->pbufrear2;
  pbuf3 = data->pbuf3;
  pCenterDst = count;
  pbuf1 = data->pbuf1;
  pCenterSrc2 = (__m128i *)pbufrear2;
  pbufcenter3 = data->pbufcenter3;
  pbuf2 = (const __m128i *)data->pbuf2;
  pbufcenter2 = data->pbufcenter2;
  v42 = (unsigned int)pbuf3;
  v43 = (__m128i *)pbufcenter3;
  v8 = pCenterDst;
  if ( (((unsigned __int8)pbuf3
       | (unsigned __int8)((unsigned __int8)pbuf1
                         | (unsigned __int8)pbuf2
                         | r
                         | (unsigned __int8)pCenterSrc2
                         | (unsigned __int8)pbufcenter3
                         | (unsigned __int8)pbufcenter2))
      & 0xF) == 0
    && (int)pCenterDst >= 8 )
  {
    v42 = (unsigned int)pCenterDst >> 3;
    pCenterDst = (__m128i *)((char *)pCenterDst - 8 * ((unsigned int)pCenterDst >> 3));
    v9 = r;
    do
    {
      si128 = (__m128)_mm_load_si128((const __m128i *)&pbuf1[2]);
      v11 = (__m128)_mm_load_si128((const __m128i *)&pbuf1[4]);
      v12 = (__m128)_mm_load_si128((const __m128i *)&pbuf1[6]);
      v13 = _mm_load_si128(pbuf2 + 1);
      v14 = _mm_load_si128(pbuf2 + 2);
      v15 = (__m128)_mm_load_si128((const __m128i *)pbuf1);
      v16 = _mm_load_si128(pbuf2 + 3);
      v17 = pCenterSrc2;
      pCenterSrc2 += 4;
      v18 = _mm_add_epi32((__m128i)si128, v13);
      v19 = _mm_add_epi32((__m128i)v11, v14);
      v20 = _mm_add_epi32((__m128i)v12, v16);
      v21 = _mm_load_si128(pbuf2);
      *(__m128i *)&pbuf3[2].left = v18;
      *(__m128i *)&pbuf3[4].left = v19;
      *(__m128i *)v38 = v20;
      *(__m128i *)&pbuf3[6].left = _mm_load_si128((const __m128i *)v38);
      *(__m128i *)&pbuf3->left = _mm_add_epi32((__m128i)v15, v21);
      v22 = _mm_add_epi32((__m128i)si128, _mm_load_si128(v17 + 1));
      v23 = _mm_add_epi32((__m128i)v11, _mm_load_si128(v17 + 2));
      v24 = _mm_add_epi32((__m128i)v12, _mm_load_si128(v17 + 3));
      v25 = _mm_load_si128(v17);
      v26 = (const __m128i *)pbufcenter2;
      pbufcenter2 += 8;
      *(__m128i *)(v9 + 16) = v22;
      *(__m128i *)(v9 + 32) = v23;
      *(__m128i *)v38 = v24;
      *(__m128i *)(v9 + 48) = _mm_load_si128((const __m128i *)v38);
      *(__m128i *)v9 = _mm_add_epi32((__m128i)v15, v25);
      v27 = _mm_add_epi32(
              _mm_srai_epi32(_mm_add_epi32((__m128i)si128, (__m128i)_mm_shuffle_ps(si128, si128, 177)), 1u),
              _mm_load_si128(v26 + 1));
      v28 = _mm_load_si128(v26);
      v29 = _mm_add_epi32(
              _mm_srai_epi32(_mm_add_epi32((__m128i)v11, (__m128i)_mm_shuffle_ps(v11, v11, 177)), 1u),
              _mm_load_si128(v26 + 2));
      v30 = _mm_load_si128(v26 + 3);
      v31 = v43;
      v43 += 4;
      pbuf3 += 8;
      pbuf1 += 8;
      pbuf2 += 4;
      v9 += 64;
      v32 = v42-- == 1;
      *v31 = _mm_add_epi32(_mm_srai_epi32(_mm_add_epi32((__m128i)v15, (__m128i)_mm_shuffle_ps(v15, v15, 177)), 1u), v28);
      v31[1] = v27;
      v31[2] = v29;
      v31[3] = _mm_add_epi32(
                 _mm_srai_epi32(_mm_add_epi32((__m128i)v12, (__m128i)_mm_shuffle_ps(v12, v12, 177)), 1u),
                 v30);
    }
    while ( !v32 );
    r = v9;
    v8 = pCenterDst;
    v42 = (unsigned int)pbuf3;
  }
  if ( (int)v8 > 0 )
  {
    v41 = (char *)pbuf1 - (char *)pbuf2;
    v40 = v42 - (_DWORD)pbuf2;
    *(_DWORD *)&v38[24] = r - (_DWORD)pbuf2;
    v39 = (char *)((char *)pCenterSrc2 - (char *)pbuf2);
    *(_DWORD *)&v38[20] = (char *)pbufcenter2 - (char *)pbuf1;
    r -= (int)pbuf1;
    *(_DWORD *)&v38[16] = (char *)v43 - (char *)pbuf1;
    v33 = (portable_samplepair_t *)(v42 - (_DWORD)pbuf1);
    v34 = &pbuf2->m128i_i32[1];
    pbufcenter2 = (portable_samplepair_t *)(v42 - (_DWORD)pbuf1);
    v43 = (__m128i *)((char *)pCenterSrc2 - (char *)pbuf1);
    while ( 1 )
    {
      left = pbuf1->left;
      v42 = *(int *)((char *)v34 + v41);
      *(int *)((char *)&v33->left + (_DWORD)pbuf1) = left + *(v34 - 1);
      *(int *)((char *)v34 + v40) = v42 + *v34;
      v36 = left + *(int *)((char *)v43->m128i_i32 + (_DWORD)pbuf1);
      v37 = v42 + left;
      *(int *)((char *)&pbuf1->left + r) = v36;
      *(int *)((char *)v34 + *(_DWORD *)&v38[24]) = v42 + *(int *)((char *)v34 + (_DWORD)v39);
      *(int *)((char *)&pbuf1->left + *(_DWORD *)&v38[16]) = *(int *)((char *)&pbuf1->left + *(_DWORD *)&v38[20])
                                                           + v37 / 2;
      ++pbuf1;
      v34 += 2;
      pCenterDst = (__m128i *)((char *)pCenterDst - 1);
      if ( (int)pCenterDst <= 0 )
        break;
      v33 = pbufcenter2;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002C2F0
// Name: void Mix255(class CMixData __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Mix255(CMixData *data)
{
  int i; // ecx
  portable_samplepair_t *v2; // edx
  int left; // eax
  int right; // edx

  for ( i = 0; i < data->count; ++i )
  {
    v2 = &data->pbuf1[i];
    left = v2->left;
    right = v2->right;
    data->pbuf3[i].left = left + data->pbuf2[i].left;
    data->pbuf3[i].right = right + data->pbuf2[i].right;
    data->pbufrear3[i].left = left + data->pbufrear2[i].left;
    data->pbufrear3[i].right = right + data->pbufrear2[i].right;
    data->pbufcenter3[i].left = data->pbufcenter2[i].left + (right + left) / 2;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002C370
// Name: void Mix555_SIMD(class CMixData __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Mix555_SIMD(__m128i *data)
{
  int v2; // eax
  const __m128i *v3; // esi
  portable_samplepair_t *v4; // eax
  const __m128i *v5; // edi
  int v6; // ecx
  __m128i *v7; // ecx
  __m128i si128; // xmm4
  __m128i v9; // xmm1
  __m128i v10; // xmm2
  __m128i v11; // xmm3
  __m128i v12; // xmm1
  __m128i v13; // xmm2
  __m128i v14; // xmm3
  __m128i v15; // xmm4
  __m128i v16; // xmm0
  __m128i v17; // xmm1
  __m128i v18; // xmm2
  const __m128i *v19; // edx
  __m128i v20; // xmm2
  __m128i v21; // xmm3
  __m128i v22; // xmm4
  __m128i *v23; // edx
  bool v24; // zf
  int *v25; // ecx
  int v26; // edx
  int v27; // edi
  int v28; // esi
  int v29; // [esp+8h] [ebp-30h]
  int v30; // [esp+Ch] [ebp-2Ch]
  int v31; // [esp+10h] [ebp-28h]
  int v32; // [esp+14h] [ebp-24h]
  int v33; // [esp+18h] [ebp-20h]
  unsigned int v34; // [esp+1Ch] [ebp-1Ch]
  int v35; // [esp+1Ch] [ebp-1Ch]
  __m128i *pCenterDst; // [esp+20h] [ebp-18h]
  __m128i *pCenterDsta; // [esp+20h] [ebp-18h]
  __m128i *pRearDst; // [esp+24h] [ebp-14h]
  __m128i *pRearDsta; // [esp+24h] [ebp-14h]
  int nCount; // [esp+28h] [ebp-10h]
  __m128i *pCenterSrc1; // [esp+2Ch] [ebp-Ch]
  __m128i *pCenterSrc2; // [esp+30h] [ebp-8h]
  __m128i *pCenterSrc2a; // [esp+30h] [ebp-8h]
  __m128i *pRearSrc1; // [esp+34h] [ebp-4h]
  __m128i *pRearSrc1a; // [esp+34h] [ebp-4h]
  __m128i *pRearSrc2; // [esp+40h] [ebp+8h]
  __m128i *pRearSrc2a; // [esp+40h] [ebp+8h]

  v2 = data->m128i_i32[0];
  pRearDst = (__m128i *)data[1].m128i_i32[2];
  pRearSrc1 = (__m128i *)data[1].m128i_i32[0];
  pRearSrc2 = (__m128i *)data[1].m128i_i32[1];
  v3 = (const __m128i *)data->m128i_i32[1];
  nCount = v2;
  v4 = (portable_samplepair_t *)data->m128i_i32[3];
  pCenterDst = (__m128i *)data[2].m128i_i32[1];
  v5 = (const __m128i *)data->m128i_i32[2];
  pCenterSrc2 = (__m128i *)data[2].m128i_i32[0];
  pCenterSrc1 = (__m128i *)data[1].m128i_i32[3];
  v6 = nCount;
  if ( (((unsigned __int8)v4
       | (unsigned __int8)((unsigned __int8)v3
                         | (unsigned __int8)v5
                         | (unsigned __int8)pRearDst
                         | (unsigned __int8)pRearSrc1
                         | (unsigned __int8)pRearSrc2
                         | (unsigned __int8)pCenterDst
                         | (unsigned __int8)pCenterSrc1
                         | (unsigned __int8)pCenterSrc2))
      & 0xF) == 0
    && nCount >= 8 )
  {
    v34 = (unsigned int)nCount >> 3;
    nCount -= 8 * ((unsigned int)nCount >> 3);
    v7 = pRearDst;
    do
    {
      si128 = _mm_load_si128(v5);
      v9 = _mm_add_epi32(_mm_load_si128(v3 + 2), _mm_load_si128(v5 + 2));
      v10 = _mm_add_epi32(_mm_load_si128(v3 + 3), _mm_load_si128(v5 + 3));
      v11 = _mm_load_si128(v3);
      *(__m128i *)&v4[2].left = _mm_add_epi32(_mm_load_si128(v3 + 1), _mm_load_si128(v5 + 1));
      *(__m128i *)&v4[4].left = v9;
      *(__m128i *)&v4[6].left = v10;
      *(__m128i *)&v4->left = _mm_add_epi32(v11, si128);
      v12 = _mm_add_epi32(_mm_load_si128(pRearSrc1 + 2), _mm_load_si128(pRearSrc2 + 2));
      v13 = _mm_add_epi32(_mm_load_si128(pRearSrc1 + 3), _mm_load_si128(pRearSrc2 + 3));
      v14 = _mm_load_si128(pRearSrc1);
      v15 = _mm_load_si128(pRearSrc2);
      v7[1] = _mm_add_epi32(_mm_load_si128(pRearSrc1 + 1), _mm_load_si128(pRearSrc2 + 1));
      v7[2] = v12;
      v7[3] = v13;
      pRearSrc1 += 4;
      pRearSrc2 += 4;
      *v7 = _mm_add_epi32(v14, v15);
      v16 = _mm_add_epi32(_mm_load_si128(pCenterSrc1 + 1), _mm_load_si128(pCenterSrc2 + 1));
      v17 = _mm_add_epi32(_mm_load_si128(pCenterSrc1 + 2), _mm_load_si128(pCenterSrc2 + 2));
      v18 = _mm_load_si128(pCenterSrc1 + 3);
      v19 = pCenterSrc1;
      pCenterSrc1 += 4;
      v20 = _mm_add_epi32(v18, _mm_load_si128(pCenterSrc2 + 3));
      v21 = _mm_load_si128(v19);
      v22 = _mm_load_si128(pCenterSrc2);
      v23 = pCenterDst;
      pCenterDst += 4;
      pCenterSrc2 += 4;
      v4 += 8;
      v3 += 4;
      v5 += 4;
      v7 += 4;
      v24 = v34-- == 1;
      *v23 = _mm_add_epi32(v21, v22);
      v23[1] = v16;
      v23[2] = v17;
      v23[3] = v20;
    }
    while ( !v24 );
    pRearDst = v7;
    v6 = nCount;
  }
  if ( v6 > 0 )
  {
    v33 = (char *)v5 - (char *)v3;
    v32 = (char *)v4 - (char *)v3;
    v25 = &v3->m128i_i32[1];
    v29 = (char *)pRearSrc2 - (char *)v3;
    v30 = (char *)pRearSrc1 - (char *)v3;
    v26 = (char *)pRearDst - (char *)v3;
    v31 = (char *)pRearSrc2 - (char *)v4;
    pRearSrc2a = (__m128i *)((char *)pRearSrc1 - (char *)v4);
    pRearDsta = (__m128i *)((char *)pRearDst - (char *)v4);
    pCenterSrc2a = (__m128i *)((char *)pCenterSrc2 - (char *)v4);
    pRearSrc1a = (__m128i *)((char *)pCenterDst - (char *)v4);
    v27 = (char *)v5 - (char *)v4;
    v35 = v27;
    pCenterDsta = (__m128i *)((char *)pCenterSrc1 - (char *)v4);
    while ( 1 )
    {
      v4->left = *(v25 - 1) + *(int *)((char *)&v4->left + v27);
      v28 = *v25 + *(int *)((char *)v25 + v33);
      v25 += 2;
      *(int *)((char *)v25 + v32 - 8) = v28;
      *(int *)((char *)pRearDsta->m128i_i32 + (_DWORD)v4) = *(int *)((char *)&v4->left + v31)
                                                          + *(int *)((char *)pRearSrc2a->m128i_i32 + (_DWORD)v4);
      *(int *)((char *)v25 + v26 - 8) = *(int *)((char *)v25 + v29 - 8) + *(int *)((char *)v25 + v30 - 8);
      *(int *)((char *)pRearSrc1a->m128i_i32 + (_DWORD)v4) = *(int *)((char *)pCenterSrc2a->m128i_i32 + (_DWORD)v4)
                                                           + *(int *)((char *)pCenterDsta->m128i_i32 + (_DWORD)v4);
      ++v4;
      if ( --nCount <= 0 )
        break;
      v27 = v35;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002C600
// Name: void Mix555(class CMixData __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Mix555(CMixData *data)
{
  int i; // eax

  for ( i = 0; i < data->count; ++i )
  {
    data->pbuf3[i].left = data->pbuf1[i].left + data->pbuf2[i].left;
    data->pbuf3[i].right = data->pbuf1[i].right + data->pbuf2[i].right;
    data->pbufrear3[i].left = data->pbufrear1[i].left + data->pbufrear2[i].left;
    data->pbufrear3[i].right = data->pbufrear1[i].right + data->pbufrear2[i].right;
    data->pbufcenter3[i].left = data->pbufcenter1[i].left + data->pbufcenter2[i].left;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002C680
// Name: void MIX_ScalePaintBuffer(int,int,float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MIX_ScalePaintBuffer(portable_samplepair_t *bufferIndex, int count, float fgain)
{
  int v3; // eax
  paintbuffer_t *v4; // edi
  portable_samplepair_t *pbuf; // edx
  int v6; // ecx
  int j; // eax
  int v8; // ebx
  int v9; // esi
  int *p_right; // eax
  int i; // eax
  portable_samplepair_t *pbufcenter; // [esp+0h] [ebp-8h]
  int v13; // [esp+4h] [ebp-4h]
  portable_samplepair_t *pbufrear; // [esp+10h] [ebp+8h]

  v3 = 312 * (_DWORD)bufferIndex;
  v4 = g_paintBuffers;
  pbuf = g_paintBuffers[(_DWORD)bufferIndex].pbuf;
  pbufrear = g_paintBuffers[(_DWORD)bufferIndex].pbufrear;
  pbufcenter = *(portable_samplepair_t **)((char *)&g_paintBuffers->pbufcenter + v3);
  v6 = (int)(float)(fgain * 256.0);
  v13 = v3;
  if ( v6 != 256 )
  {
    if ( *(&g_paintBuffers->fsurround + v3) )
    {
      v8 = count;
      v9 = 0;
      if ( count > 0 )
      {
        p_right = &pbufrear->right;
        do
        {
          pbuf[v9].left = (v6 * pbuf[v9].left) >> 8;
          *(int *)((char *)p_right + (char *)pbuf - (char *)pbufrear) = (v6
                                                                       * *(int *)((char *)p_right
                                                                                + (char *)pbuf
                                                                                - (char *)pbufrear)) >> 8;
          *(p_right - 1) = (v6 * *(p_right - 1)) >> 8;
          *p_right = (v6 * *p_right) >> 8;
          v8 = count;
          ++v9;
          p_right += 2;
        }
        while ( v9 < count );
        v4 = g_paintBuffers;
        v3 = v13;
      }
      if ( *(&v4->fsurround_center + v3) )
      {
        for ( i = 0; i < v8; ++i )
          pbufcenter[i].left = (v6 * pbufcenter[i].left) >> 8;
      }
    }
    else
    {
      for ( j = 0; j < count; ++j )
      {
        pbuf[j].left = (v6 * pbuf[j].left) >> 8;
        pbuf[j].right = (v6 * pbuf[j].right) >> 8;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002C790
// Name: void SDEBUG_ShowAvgValue(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SDEBUG_ShowAvgValue()
{
  if ( sdebug_in_count > 132300.0 )
  {
    if ( (double)(int)sdebug_avg_in > 20.0 && (double)(int)sdebug_avg_out > 20.0 )
      DevMsg(
        a1: "dsp avg gain:%1.2f in:%1.2f out:%1.2f 1/gain:%1.2f\n",
        sdebug_avg_out / sdebug_avg_in,
        sdebug_avg_in,
        sdebug_avg_out,
        sdebug_avg_in / sdebug_avg_out);
    sdebug_avg_in = 0.0;
    sdebug_avg_out = 0.0;
    sdebug_in_count = 0.0;
    sdebug_out_count = 0.0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002C840
// Name: ChannelVolComparator
// Source: json
//------------------------------------------------------------------------------
int __cdecl ChannelVolComparator(_DWORD *a, _DWORD *b)
{
  return b[1] - a[1];
}

//------------------------------------------------------------------------------
// Address: 0x1002C860
// Name: void Snd_WriteLinearBlastStereo16(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Snd_WriteLinearBlastStereo16()
{
  int *v0; // ebx
  __int16 *v1; // edi
  int v2; // ecx
  int v3; // esi
  int v4; // eax
  int v5; // edx

  v0 = snd_p;
  v1 = snd_out;
  v2 = snd_linear_count;
  v3 = snd_vol;
  do
  {
    v4 = (v3 * v0[v2 - 2]) >> 8;
    if ( v4 > 0x7FFF )
    {
      LOWORD(v4) = 0x7FFF;
    }
    else if ( v4 < -32768 )
    {
      LOWORD(v4) = 0x8000;
    }
    v5 = (v3 * v0[v2 - 1]) >> 8;
    if ( v5 > 0x7FFF )
    {
      v5 = 0x7FFF;
    }
    else if ( v5 < -32768 )
    {
      v5 = -32768;
    }
    *(_DWORD *)&v1[v2 - 2] = (unsigned __int16)v4 | (v5 << 16);
    v2 -= 2;
  }
  while ( v2 != 0 );
}

//------------------------------------------------------------------------------
// Address: 0x1002C8E0
// Name: void SND_InitScaletable(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SND_InitScaletable()
{
  int v0; // edx
  int *v1; // ecx
  int i; // eax

  v0 = 0;
  v1 = snd_scaletable[0];
  do
  {
    for ( i = 0; i < 256; ++i )
      *v1++ = 2 * v0 * (char)i;
    ++v0;
  }
  while ( (int)v1 < (int)&g_dsp_volume );
}

//------------------------------------------------------------------------------
// Address: 0x1002C910
// Name: void SND_PaintChannelFrom8(struct portable_samplepair_t __near *,int __near *,unsigned char __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SND_PaintChannelFrom8(portable_samplepair_t *pOutput, int *volume, unsigned __int8 *pData8, int count)
{
  int v4; // ecx
  char *v5; // eax
  char *v6; // edx
  int v7; // ebx
  int v8; // ebp
  int v9; // ebp
  int v10; // ebp
  int v11; // [esp+0h] [ebp-10h] BYREF

  tempStore = (int)pOutput;
  _InterlockedExchange(&tempStore, (__int32)&v11);
  v4 = count;
  v5 = (char *)snd_scaletable + 512 * (*volume & 0xFE);
  v6 = (char *)snd_scaletable + 512 * (volume[1] & 0xFE);
  v7 = pData8[count - 1];
  if ( (count & 1) == 0
    || (v8 = *(&v11 + 2 * count - 1) + *(_DWORD *)&v6[4 * v7],
        *(&v11 + 2 * count - 2) += *(_DWORD *)&v5[4 * v7],
        *(&v11 + 2 * count - 1) = v8,
        LOBYTE(v7) = pData8[count - 2],
        v4 = count - 1,
        count != 1) )
  {
    do
    {
      v9 = *(&v11 + 2 * v4 - 1) + *(_DWORD *)&v6[4 * v7];
      *(&v11 + 2 * v4 - 2) += *(_DWORD *)&v5[4 * v7];
      *(&v11 + 2 * v4 - 1) = v9;
      LOBYTE(v7) = pData8[v4 - 2];
      v10 = *(&v11 + 2 * v4 - 3) + *(_DWORD *)&v6[4 * v7];
      *(&v11 + 2 * v4 - 4) += *(_DWORD *)&v5[4 * v7];
      *(&v11 + 2 * v4 - 3) = v10;
      LOBYTE(v7) = pData8[v4 - 3];
      v4 -= 2;
    }
    while ( v4 != 0 );
  }
  _InterlockedExchange(&tempStore, (__int32)&v11);
}

//------------------------------------------------------------------------------
// Address: 0x1002C9C0
// Name: void SW_Mix8StereoDopplerLeft(struct portable_samplepair_t __near *,int __near *,unsigned char __near *,int,unsigned int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SW_Mix8StereoDopplerLeft(
        portable_samplepair_t *pOutput,
        int *volume,
        unsigned __int8 *pData,
        int *inputOffset,
        unsigned int rateScaleFix,
        int outCount)
{
  int v7; // edi
  int *v8; // edi
  int v9; // eax
  int v10; // esi
  int v11; // edx
  int *rscale; // [esp+14h] [ebp+Ch]
  int *lscale; // [esp+1Ch] [ebp+14h]

  v7 = *volume >> 1 << 10;
  rscale = snd_scaletable[volume[1] >> 1];
  v8 = (int *)((char *)snd_scaletable[0] + v7);
  v9 = 0;
  v10 = 0;
  lscale = v8;
  if ( outCount > 0 )
  {
    while ( 1 )
    {
      pOutput[v9].left += v8[pData[v10]];
      pOutput[v9].right += rscale[pData[v10]];
      v11 = (int)inputOffset + rateScaleFix;
      ++v9;
      v10 += (v11 >> 27) & 0xFFFFFFFE;
      inputOffset = (int *)(v11 & 0xFFFFFFF);
      if ( v9 >= outCount )
        break;
      v8 = lscale;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002CA40
// Name: void SW_Mix8StereoDopplerRight(struct portable_samplepair_t __near *,int __near *,unsigned char __near *,int,unsigned int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SW_Mix8StereoDopplerRight(
        portable_samplepair_t *pOutput,
        int *volume,
        unsigned __int8 *pData,
        int *inputOffset,
        unsigned int rateScaleFix,
        int outCount)
{
  int v7; // edi
  int *v8; // edi
  int v9; // eax
  int v10; // esi
  int v11; // edx
  int *rscale; // [esp+14h] [ebp+Ch]
  int *lscale; // [esp+1Ch] [ebp+14h]

  v7 = *volume >> 1 << 10;
  rscale = snd_scaletable[volume[1] >> 1];
  v8 = (int *)((char *)snd_scaletable[0] + v7);
  v9 = 0;
  v10 = 0;
  lscale = v8;
  if ( outCount > 0 )
  {
    while ( 1 )
    {
      pOutput[v9].left += v8[pData[v10 + 1]];
      pOutput[v9].right += rscale[pData[v10 + 1]];
      v11 = (int)inputOffset + rateScaleFix;
      ++v9;
      v10 += (v11 >> 27) & 0xFFFFFFFE;
      inputOffset = (int *)(v11 & 0xFFFFFFF);
      if ( v9 >= outCount )
        break;
      v8 = lscale;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002CAD0
// Name: void SW_Mix16StereoDopplerLeft(struct portable_samplepair_t __near *,int __near *,short __near *,int,unsigned int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SW_Mix16StereoDopplerLeft(
        portable_samplepair_t *pOutput,
        int *volume,
        __int16 *pData,
        int inputOffset,
        unsigned int rateScaleFix,
        int outCount)
{
  int v7; // eax
  int i; // esi
  int v9; // edx

  v7 = 0;
  for ( i = 0; v7 < outCount; inputOffset = v9 & 0xFFFFFFF )
  {
    v9 = rateScaleFix + inputOffset;
    pOutput[v7].left += (*volume * pData[i]) >> 8;
    pOutput[v7++].right += (volume[1] * pData[i]) >> 8;
    i += (v9 >> 27) & 0xFFFFFFFE;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002CB30
// Name: void SW_Mix16StereoDopplerLeft_Interp(struct portable_samplepair_t __near *,int __near *,short __near *,int,unsigned int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SW_Mix16StereoDopplerLeft_Interp(
        portable_samplepair_t *pOutput,
        int *volume,
        __int16 *pData,
        unsigned int inputOffset,
        unsigned int rateScaleFix,
        int outCount)
{
  int v6; // ecx
  int v7; // edi
  unsigned int v8; // edx
  int v9; // eax
  int v10; // edx
  unsigned int rateScaleFix14; // [esp+1Ch] [ebp+18h]

  v6 = 0;
  v7 = 0;
  v8 = inputOffset >> 14;
  for ( rateScaleFix14 = rateScaleFix >> 14; v6 < outCount; v8 = v10 & 0x3FFF )
  {
    v9 = pData[v7] + ((int)(v8 * (pData[v7 + 2] - pData[v7])) >> 14);
    v10 = rateScaleFix14 + v8;
    pOutput[v6].left += (v9 * *volume) >> 8;
    pOutput[v6++].right += (v9 * volume[1]) >> 8;
    v7 += (v10 >> 13) & 0xFFFFFFFE;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002CBB0
// Name: void SW_Mix16StereoDopplerRight(struct portable_samplepair_t __near *,int __near *,short __near *,int,unsigned int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SW_Mix16StereoDopplerRight(
        portable_samplepair_t *pOutput,
        int *volume,
        __int16 *pData,
        int inputOffset,
        unsigned int rateScaleFix,
        int outCount)
{
  int v7; // eax
  int i; // esi
  int v9; // edx

  v7 = 0;
  for ( i = 0; v7 < outCount; inputOffset = v9 & 0xFFFFFFF )
  {
    v9 = rateScaleFix + inputOffset;
    pOutput[v7].left += (*volume * pData[i + 1]) >> 8;
    pOutput[v7++].right += (volume[1] * pData[i + 1]) >> 8;
    i += (v9 >> 27) & 0xFFFFFFFE;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002CC20
// Name: void SW_Mix16StereoDopplerRight_Interp(struct portable_samplepair_t __near *,int __near *,short __near *,int,unsigned int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SW_Mix16StereoDopplerRight_Interp(
        portable_samplepair_t *pOutput,
        int *volume,
        __int16 *pData,
        unsigned int inputOffset,
        unsigned int rateScaleFix,
        int outCount)
{
  SW_Mix16StereoDopplerLeft_Interp(pOutput, volume, pData: pData + 1, inputOffset, rateScaleFix, outCount);
}

//------------------------------------------------------------------------------
// Address: 0x1002CC50
// Name: void SW_Mix8StereoDirectional(float,struct portable_samplepair_t __near *,int __near *,unsigned char __near *,int,unsigned int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SW_Mix8StereoDirectional(
        float soundfacing,
        portable_samplepair_t *pOutput,
        int *volume,
        unsigned __int8 *pData,
        int inputOffset,
        unsigned int rateScaleFix,
        int outCount)
{
  int v8; // eax
  int v10; // ecx
  int v11; // edi
  int v12; // esi
  int v13; // eax
  int *rscale; // [esp+0h] [ebp-4h]
  int *lscale; // [esp+14h] [ebp+10h]

  lscale = snd_scaletable[*volume >> 1];
  v8 = volume[1] >> 1 << 10;
  v10 = 0;
  v11 = 0;
  for ( rscale = (int *)((char *)snd_scaletable[0] + v8); v10 < outCount; inputOffset = v12 & 0xFFFFFFF )
  {
    v12 = rateScaleFix + inputOffset;
    v13 = (unsigned __int8)(pData[v11 + 1]
                          + ((unsigned __int16)((int)(float)((float)((float)(soundfacing + 1.0) * 0.5) * 256.0)
                                              * ((char)pData[v11] - (char)pData[v11 + 1])) >> 8));
    pOutput[v10].left += lscale[v13];
    pOutput[v10++].right += rscale[v13];
    v11 += (v12 >> 27) & 0xFFFFFFFE;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002CD10
// Name: void SW_Mix8StereoDirectional_Interp(float,struct portable_samplepair_t __near *,int __near *,unsigned char __near *,int,unsigned int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SW_Mix8StereoDirectional_Interp(
        float soundfacing,
        portable_samplepair_t *pOutput,
        int *volume,
        unsigned __int8 *pData,
        int *inputOffset,
        unsigned int rateScaleFix,
        int outCount)
{
  int v8; // edx
  int v9; // edi
  unsigned int v10; // esi
  int v11; // ecx
  int v12; // eax
  int v13; // esi
  int v14; // eax
  int *rscale; // [esp+14h] [ebp+10h]
  int *lscale; // [esp+1Ch] [ebp+18h]

  lscale = snd_scaletable[*volume >> 1];
  v8 = 0;
  v9 = 0;
  v10 = (unsigned int)inputOffset >> 14;
  for ( rscale = snd_scaletable[volume[1] >> 1]; v8 < outCount; v10 = v13 & 0x3FFF )
  {
    v11 = (char)pData[v9 + 1] + ((int)(v10 * ((char)pData[v9 + 3] - (char)pData[v9 + 1])) >> 14);
    v12 = (int)(float)((float)((float)(soundfacing + 1.0) * 0.5) * 256.0)
        * ((char)pData[v9] + ((int)(v10 * ((char)pData[v9 + 2] - (char)pData[v9])) >> 14) - v11);
    v13 = (rateScaleFix >> 14) + v10;
    v14 = (unsigned __int8)(v11 + BYTE1(v12));
    pOutput[v8].left += lscale[v14];
    pOutput[v8++].right += rscale[v14];
    v9 += (v13 >> 13) & 0xFFFFFFFE;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002CE00
// Name: void SW_Mix16StereoDirectional(float,struct portable_samplepair_t __near *,int __near *,short __near *,int,unsigned int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SW_Mix16StereoDirectional(
        float soundfacing,
        portable_samplepair_t *pOutput,
        int *volume,
        __int16 *pData,
        int inputOffset,
        unsigned int rateScaleFix,
        int outCount)
{
  int v8; // ecx
  int i; // edi
  int v10; // eax
  int v11; // esi

  v8 = 0;
  for ( i = 0; v8 < outCount; inputOffset = v11 & 0xFFFFFFF )
  {
    v10 = pData[i + 1]
        + (((int)(float)((float)((float)(soundfacing + 1.0) * 0.5) * 256.0) * (pData[i] - pData[i + 1])) >> 8);
    v11 = rateScaleFix + inputOffset;
    pOutput[v8].left += (v10 * *volume) >> 8;
    pOutput[v8++].right += (v10 * volume[1]) >> 8;
    i += (v11 >> 27) & 0xFFFFFFFE;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002CEA0
// Name: void SW_Mix16StereoDirectional_Interp(float,struct portable_samplepair_t __near *,int __near *,short __near *,int,unsigned int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SW_Mix16StereoDirectional_Interp(
        float soundfacing,
        portable_samplepair_t *pOutput,
        int *volume,
        __int16 *pData,
        unsigned int inputOffset,
        unsigned int rateScaleFix,
        int outCount)
{
  int v7; // edx
  int v8; // edi
  unsigned int i; // esi
  int v10; // ebx
  int v11; // ecx
  int v12; // eax
  int v13; // esi

  v7 = 0;
  v8 = 0;
  for ( i = inputOffset >> 14; v7 < outCount; i = v13 & 0x3FFF )
  {
    v10 = pData[v8 + 1];
    v11 = v10 + ((int)(i * (pData[v8 + 3] - v10)) >> 14);
    v12 = v11
        + (((int)(float)((float)((float)(soundfacing + 1.0) * 0.5) * 256.0)
          * (pData[v8] + ((int)(i * (pData[v8 + 2] - pData[v8])) >> 14) - v11)) >> 8);
    v13 = (rateScaleFix >> 14) + i;
    pOutput[v7].left += (v12 * *volume) >> 8;
    pOutput[v7++].right += (v12 * volume[1]) >> 8;
    v8 += (v13 >> 13) & 0xFFFFFFFE;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002CF60
// Name: void SW_Mix8StereoDistVar(float,struct portable_samplepair_t __near *,int __near *,unsigned char __near *,int,unsigned int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SW_Mix8StereoDistVar(
        float distmix,
        portable_samplepair_t *pOutput,
        portable_samplepair_t *volume,
        unsigned __int8 *pData,
        unsigned __int8 *inputOffset,
        int *rateScaleFix,
        int outCount)
{
  int v8; // ebx
  int v9; // eax
  int *v10; // ebx
  int v11; // edx
  int v12; // eax
  int v13; // ecx
  int v14; // esi
  int v15; // ecx
  int v16; // esi
  int i; // esi
  int v18; // ecx
  int v19; // [esp+0h] [ebp-4h]
  portable_samplepair_t *pOutputa; // [esp+14h] [ebp+10h]
  unsigned __int8 *pDataa; // [esp+1Ch] [ebp+18h]

  v8 = volume->left >> 1;
  pOutputa = (portable_samplepair_t *)snd_scaletable[volume->right >> 1];
  v9 = (int)(float)(distmix * 256.0);
  v10 = snd_scaletable[v8];
  v11 = 0;
  pDataa = (unsigned __int8 *)v10;
  if ( (int)(float)((float)(1.0 - distmix) * 256.0) != 0 )
  {
    if ( v9 != 0 )
    {
      for ( i = 0; i < outCount; inputOffset = (unsigned __int8 *)(v18 & 0xFFFFFFF) )
      {
        v18 = (int)&inputOffset[(_DWORD)rateScaleFix];
        v19 = (unsigned __int8)(pData[v11] + ((unsigned __int16)(v9 * ((char)pData[v11 + 1] - (char)pData[v11])) >> 8));
        pOutput[i].left += v10[v19];
        pOutput[i++].right += *(int *)((char *)&pOutputa->left + v19 * 4);
        v11 += (v18 >> 27) & 0xFFFFFFFE;
      }
    }
    else if ( outCount > 0 )
    {
      while ( 1 )
      {
        v15 = (int)&inputOffset[(_DWORD)rateScaleFix];
        v16 = pData[v11];
        pOutput[v9].left += v10[v16];
        pOutput[v9++].right += *(int *)((char *)&pOutputa->left + v16 * 4);
        v11 += (v15 >> 27) & 0xFFFFFFFE;
        inputOffset = (unsigned __int8 *)(v15 & 0xFFFFFFF);
        if ( v9 >= outCount )
          break;
        v10 = (int *)pDataa;
      }
    }
  }
  else
  {
    v12 = 0;
    if ( outCount > 0 )
    {
      while ( 1 )
      {
        v13 = (int)&inputOffset[(_DWORD)rateScaleFix];
        v14 = pData[v11 + 1];
        pOutput[v12].left += v10[v14];
        pOutput[v12++].right += *(int *)((char *)&pOutputa->left + v14 * 4);
        v11 += (v13 >> 27) & 0xFFFFFFFE;
        inputOffset = (unsigned __int8 *)(v13 & 0xFFFFFFF);
        if ( v12 >= outCount )
          break;
        v10 = (int *)pDataa;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002D0E0
// Name: void SW_Mix8StereoDistVar_Interp(float,struct portable_samplepair_t __near *,int __near *,unsigned char __near *,int,unsigned int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SW_Mix8StereoDistVar_Interp(
        float distmix,
        portable_samplepair_t *pOutput,
        int *volume,
        unsigned __int8 *pData,
        unsigned int inputOffset,
        int *rateScaleFix,
        int outCount)
{
  int v8; // edx
  unsigned int v9; // ecx
  int k; // esi
  int v11; // ebx
  int v12; // eax
  int v13; // ecx
  int v14; // eax
  int j; // esi
  int v16; // ebx
  int v17; // eax
  int v18; // ecx
  int i; // edi
  int v20; // esi
  int v21; // eax
  int v22; // ecx
  int v23; // eax
  unsigned int rateScaleFix14; // [esp+4h] [ebp-4h]
  int *lscale; // [esp+10h] [ebp+8h]
  int inputOffseta; // [esp+20h] [ebp+18h]
  int *rscale; // [esp+24h] [ebp+1Ch]

  rateScaleFix14 = (unsigned int)rateScaleFix >> 14;
  lscale = snd_scaletable[*volume >> 1];
  rscale = snd_scaletable[volume[1] >> 1];
  v8 = 0;
  v9 = inputOffset >> 14;
  if ( (int)(float)((float)(1.0 - distmix) * 256.0) != 0 )
  {
    if ( (int)(float)(distmix * 256.0) != 0 )
    {
      for ( i = 0; i < outCount; v9 = v22 & 0x3FFF )
      {
        v20 = (char)pData[v8] + ((int)(v9 * ((char)pData[v8 + 2] - (char)pData[v8])) >> 14);
        v21 = (int)(float)(distmix * 256.0)
            * ((char)pData[v8 + 1] + ((int)(v9 * ((char)pData[v8 + 3] - (char)pData[v8 + 1])) >> 14) - v20);
        v22 = rateScaleFix14 + v9;
        v23 = (unsigned __int8)(v20 + BYTE1(v21));
        pOutput[i].left += lscale[v23];
        pOutput[i++].right += rscale[v23];
        v8 += (v22 >> 13) & 0xFFFFFFFE;
      }
    }
    else
    {
      for ( j = 0; j < outCount; v9 = v18 & 0x3FFF )
      {
        v16 = (char)pData[v8];
        v17 = v9 * ((char)pData[v8 + 2] - v16);
        v18 = rateScaleFix14 + v9;
        inputOffseta = (unsigned __int8)(v16 + (v17 >> 14));
        pOutput[j].left += lscale[inputOffseta];
        pOutput[j++].right += rscale[inputOffseta];
        v8 += (v18 >> 13) & 0xFFFFFFFE;
      }
    }
  }
  else
  {
    for ( k = 0; k < outCount; v9 = v13 & 0x3FFF )
    {
      v11 = (char)pData[v8 + 1];
      v12 = v9 * ((char)pData[v8 + 3] - v11);
      v13 = rateScaleFix14 + v9;
      v14 = (unsigned __int8)(v11 + (v12 >> 14));
      pOutput[k].left += lscale[v14];
      pOutput[k++].right += rscale[v14];
      v8 += (v13 >> 13) & 0xFFFFFFFE;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002D2B0
// Name: void SW_Mix8Mono(struct portable_samplepair_t __near *,int __near *,unsigned char __near *,int,unsigned int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SW_Mix8Mono(
        portable_samplepair_t *pOutput,
        int *volume,
        unsigned __int8 *pData,
        int inputOffset,
        unsigned int rateScaleFix,
        int outCount)
{
  int *v7; // edi
  int v8; // eax
  int v9; // esi
  int v10; // edx
  int *rscale; // [esp+0h] [ebp-8h]
  int *lscale; // [esp+4h] [ebp-4h]

  if ( rateScaleFix == 0x10000000 )
  {
    SND_PaintChannelFrom8(pOutput, volume, pData8: pData, count: outCount);
  }
  else
  {
    rscale = snd_scaletable[volume[1] >> 1];
    v7 = snd_scaletable[*volume >> 1];
    v8 = 0;
    v9 = 0;
    lscale = v7;
    if ( outCount > 0 )
    {
      while ( 1 )
      {
        pOutput[v8].left += v7[pData[v9]];
        v10 = rateScaleFix + inputOffset;
        pOutput[v8++].right += rscale[pData[v9]];
        v9 += v10 >> 28;
        inputOffset = v10 & 0xFFFFFFF;
        if ( v8 >= outCount )
          break;
        v7 = lscale;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002D350
// Name: void SW_Mix8Mono_Interp(struct portable_samplepair_t __near *,int __near *,unsigned char __near *,int,unsigned int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SW_Mix8Mono_Interp(
        portable_samplepair_t *pOutput,
        int *volume,
        unsigned __int8 *pData,
        int *inputOffset,
        int *rateScaleFix,
        int outCount)
{
  int v6; // ecx
  int v7; // edi
  unsigned int v8; // edx
  int v9; // ebx
  int v10; // eax
  int v11; // edx
  int v12; // eax
  unsigned int rateScaleFix14; // [esp+4h] [ebp-4h]
  int *rscale; // [esp+1Ch] [ebp+14h]
  int *lscale; // [esp+20h] [ebp+18h]

  rateScaleFix14 = (unsigned int)rateScaleFix >> 14;
  lscale = snd_scaletable[*volume >> 1];
  v6 = 0;
  v7 = 0;
  v8 = (unsigned int)inputOffset >> 14;
  for ( rscale = snd_scaletable[volume[1] >> 1]; v6 < outCount; v8 = v11 & 0x3FFF )
  {
    v9 = (char)pData[v7];
    v10 = v8 * ((char)pData[v7 + 1] - v9);
    v11 = rateScaleFix14 + v8;
    v12 = (unsigned __int8)(v9 + (v10 >> 14));
    pOutput[v6].left += lscale[v12];
    pOutput[v6++].right += rscale[v12];
    v7 += v11 >> 14;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002D3F0
// Name: void SW_Mix8Stereo(struct portable_samplepair_t __near *,int __near *,unsigned char __near *,int,unsigned int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SW_Mix8Stereo(
        portable_samplepair_t *pOutput,
        int *volume,
        unsigned __int8 *pData,
        int *inputOffset,
        unsigned int rateScaleFix,
        int outCount)
{
  int v7; // edi
  int *v8; // edi
  int v9; // eax
  int v10; // esi
  int v11; // edx
  int *rscale; // [esp+14h] [ebp+Ch]
  int *lscale; // [esp+1Ch] [ebp+14h]

  v7 = *volume >> 1 << 10;
  rscale = snd_scaletable[volume[1] >> 1];
  v8 = (int *)((char *)snd_scaletable[0] + v7);
  v9 = 0;
  v10 = 0;
  lscale = v8;
  if ( outCount > 0 )
  {
    while ( 1 )
    {
      pOutput[v9].left += v8[pData[v10]];
      pOutput[v9].right += rscale[pData[v10 + 1]];
      v11 = (int)inputOffset + rateScaleFix;
      ++v9;
      v10 += (v11 >> 27) & 0xFFFFFFFE;
      inputOffset = (int *)(v11 & 0xFFFFFFF);
      if ( v9 >= outCount )
        break;
      v8 = lscale;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002D470
// Name: void SW_Mix8Stereo_Interp(struct portable_samplepair_t __near *,int __near *,unsigned char __near *,int,unsigned int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SW_Mix8Stereo_Interp(
        portable_samplepair_t *pOutput,
        int *volume,
        unsigned __int8 *pData,
        int *inputOffset,
        int *rateScaleFix,
        int outCount)
{
  int v6; // edx
  int v7; // edi
  unsigned int v8; // esi
  int v9; // ebx
  unsigned __int8 v10; // al
  int v11; // ecx
  int v12; // esi
  unsigned int rateScaleFix14; // [esp+8h] [ebp-4h]
  int *rscale; // [esp+20h] [ebp+14h]
  int *lscale; // [esp+24h] [ebp+18h]

  rateScaleFix14 = (unsigned int)rateScaleFix >> 14;
  lscale = snd_scaletable[*volume >> 1];
  v6 = 0;
  v7 = 0;
  v8 = (unsigned int)inputOffset >> 14;
  for ( rscale = snd_scaletable[volume[1] >> 1]; v6 < outCount; v8 = v12 & 0x3FFF )
  {
    v9 = (char)pData[v7 + 1];
    v10 = pData[v7] + ((int)(v8 * ((char)pData[v7 + 2] - (char)pData[v7])) >> 14);
    v11 = v8 * ((char)pData[v7 + 3] - v9);
    v12 = rateScaleFix14 + v8;
    pOutput[v6].left += lscale[v10];
    pOutput[v6++].right += rscale[(unsigned __int8)(v9 + (v11 >> 14))];
    v7 += (v12 >> 13) & 0xFFFFFFFE;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002D520
// Name: void SW_Mix16Mono_Shift(struct portable_samplepair_t __near *,int __near *,short __near *,int,unsigned int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SW_Mix16Mono_Shift(
        __m64 *pOutput,
        int *volume,
        __int16 *pData,
        int inputOffset,
        int rateScaleFix,
        int outCount)
{
  unsigned int v6; // eax
  __m64 v7; // mm0
  __int64 v10; // kr08_8
  __m64 v11; // mm2
  __m64 v12; // mm3
  __m64 v13; // mm3
  __m64 v14; // mm2
  __m64 v15; // mm5
  __m64 v16; // mm4
  unsigned int rateScaleFrac; // [esp+Ch] [ebp-Ch]
  int vol0; // [esp+10h] [ebp-8h]
  int vol1; // [esp+14h] [ebp-4h]
  int rateScaleInt; // [esp+30h] [ebp+18h]

  vol0 = *volume;
  v6 = 16 * rateScaleFix;
  vol1 = volume[1];
  rateScaleInt = (unsigned __int64)rateScaleFix >> 28;
  rateScaleFrac = v6;
  v7 = _m_packssdw(*(__m64 *)volume, *(__m64 *)volume);
  v10 = (unsigned int)inputOffset;
  do
  {
    v11 = _mm_cvtsi32_si64(*(_DWORD *)&pData[HIDWORD(v10)]);
    v12 = _mm_cvtsi32_si64(*(_DWORD *)&pData[(__PAIR64__(rateScaleInt, rateScaleFrac) + v10) >> 32]);
    v10 += __PAIR64__(rateScaleInt, rateScaleFrac) + __PAIR64__(rateScaleInt, rateScaleFrac);
    v13 = _m_punpckldq(_m_punpcklwd(v11, v11), _m_punpcklwd(v12, v12));
    v14 = _m_pmullw(v13, v7);
    v15 = _m_pmulhw(v13, v7);
    outCount -= 2;
    v16 = _m_paddd(_m_psradi(_m_punpckhwd(v14, v15), 8u), pOutput[1]);
    pOutput->m64_u64 = (unsigned __int64)_m_paddd(_m_psradi(_m_punpcklwd(v14, v15), 8u), (__m64)pOutput->m64_u64);
    pOutput[1].m64_u64 = (unsigned __int64)v16;
    pOutput += 2;
  }
  while ( outCount > 1 );
  if ( outCount >= 1 )
  {
    pOutput->m64_i32[0] += (vol0 * pData[HIDWORD(v10)]) >> 8;
    pOutput->m64_i32[1] += (vol1 * pData[HIDWORD(v10)]) >> 8;
  }
  _m_empty();
}

//------------------------------------------------------------------------------
// Address: 0x1002D5E0
// Name: void SW_Mix16Mono_NoShift(struct portable_samplepair_t __near *,int __near *,short __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SW_Mix16Mono_NoShift(__m64 *pOutput, int *volume, __int16 *pData, int outCount)
{
  __m64 v4; // mm0
  __m64 v8; // mm2
  __int16 *v9; // edx
  __m64 v10; // mm3
  __m64 v11; // mm3
  __m64 v12; // mm2
  __m64 v13; // mm5
  __m64 v14; // mm4
  int v15; // esi
  int vol0; // [esp+8h] [ebp-8h]
  int vol1; // [esp+Ch] [ebp-4h]

  vol0 = *volume;
  vol1 = volume[1];
  v4 = _m_packssdw(*(__m64 *)volume, *(__m64 *)volume);
  do
  {
    v8 = _mm_cvtsi32_si64(*(_DWORD *)pData);
    v9 = pData + 1;
    v10 = _mm_cvtsi32_si64(*(_DWORD *)v9);
    pData = v9 + 1;
    v11 = _m_punpckldq(_m_punpcklwd(v8, v8), _m_punpcklwd(v10, v10));
    v12 = _m_pmullw(v11, v4);
    v13 = _m_pmulhw(v11, v4);
    outCount -= 2;
    v14 = _m_paddd(_m_psradi(_m_punpckhwd(v12, v13), 8u), pOutput[1]);
    pOutput->m64_u64 = (unsigned __int64)_m_paddd(_m_psradi(_m_punpcklwd(v12, v13), 8u), (__m64)pOutput->m64_u64);
    pOutput[1].m64_u64 = (unsigned __int64)v14;
    pOutput += 2;
  }
  while ( outCount > 1 );
  if ( outCount >= 1 )
  {
    v15 = *pData;
    pOutput->m64_i32[0] += (vol0 * v15) >> 8;
    pOutput->m64_i32[1] += (vol1 * v15) >> 8;
  }
  _m_empty();
}

//------------------------------------------------------------------------------
// Address: 0x1002D680
// Name: void SW_Mix16Mono(struct portable_samplepair_t restrict __near *,int restrict __near *,short restrict __near *,int,unsigned int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SW_Mix16Mono(
        portable_samplepair_t *pOutput,
        int *volume,
        __int16 *pData,
        int inputOffset,
        unsigned int rateScaleFix,
        int outCount)
{
  if ( rateScaleFix == 0x10000000 )
    SW_Mix16Mono_NoShift((__m64 *)pOutput, volume, pData, outCount);
  else
    SW_Mix16Mono_Shift((__m64 *)pOutput, volume, pData, inputOffset, rateScaleFix, outCount);
}

//------------------------------------------------------------------------------
// Address: 0x1002D6D0
// Name: void SW_Mix16Mono_Interp(struct portable_samplepair_t restrict __near *,int restrict __near *,short restrict __near *,int,unsigned int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SW_Mix16Mono_Interp(
        portable_samplepair_t *pOutput,
        int *volume,
        __int16 *pData,
        unsigned int inputOffset,
        unsigned int rateScaleFix,
        int outCount)
{
  int v6; // ecx
  int v7; // edi
  unsigned int v8; // edx
  int v9; // ebx
  int v10; // eax
  int v11; // edx
  int v12; // eax
  unsigned int rateScaleFix14; // [esp+4h] [ebp-4h]
  int inputOffseta; // [esp+1Ch] [ebp+14h]
  unsigned int rateScaleFixa; // [esp+20h] [ebp+18h]

  v6 = 0;
  v7 = 0;
  v8 = inputOffset >> 14;
  rateScaleFix14 = rateScaleFix >> 14;
  if ( outCount > 0 )
  {
    rateScaleFixa = *volume;
    inputOffseta = volume[1];
    do
    {
      v9 = pData[v7];
      v10 = v8 * (pData[v7 + 1] - v9);
      v11 = rateScaleFix14 + v8;
      v12 = v9 + (v10 >> 14);
      pOutput[v6].left += (int)(v12 * rateScaleFixa) >> 8;
      pOutput[v6++].right += (v12 * inputOffseta) >> 8;
      v7 += v11 >> 14;
      v8 = v11 & 0x3FFF;
    }
    while ( v6 < outCount );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002D750
// Name: void SW_Mix16Stereo_NoOpt(struct portable_samplepair_t restrict __near *,int restrict __near *,short restrict __near *,int,unsigned int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SW_Mix16Stereo_NoOpt(
        portable_samplepair_t *pOutput,
        int *pVolume,
        __int16 *pData,
        int nInputOffset,
        unsigned int nRateScaleFix,
        int nOutCount)
{
  int v7; // eax
  int v8; // esi
  int v9; // edx
  int v10; // [esp+4h] [ebp-4h]
  int nInputOffseta; // [esp+1Ch] [ebp+14h]

  v7 = 0;
  v8 = 0;
  if ( nOutCount > 0 )
  {
    v10 = pVolume[1];
    nInputOffseta = *pVolume;
    do
    {
      v9 = nRateScaleFix + nInputOffset;
      pOutput[v7].left += (nInputOffseta * pData[v8]) >> 8;
      pOutput[v7++].right += (v10 * pData[v8 + 1]) >> 8;
      v8 += (v9 >> 27) & 0xFFFFFFFE;
      nInputOffset = v9 & 0xFFFFFFF;
    }
    while ( v7 < nOutCount );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002D7C0
// Name: void SW_Mix16Stereo_Interp(struct portable_samplepair_t restrict __near *,int restrict __near *,short restrict __near *,int,unsigned int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SW_Mix16Stereo_Interp(
        portable_samplepair_t *pOutput,
        int *pVolume,
        __int16 *pData,
        unsigned int inputOffset,
        unsigned int rateScaleFix,
        int outCount)
{
  int v6; // ecx
  int v7; // esi
  unsigned int v8; // edx
  int v9; // eax
  int v10; // ebx
  int v11; // edx
  unsigned int rateScaleFix14; // [esp+4h] [ebp-4h]
  int inputOffseta; // [esp+1Ch] [ebp+14h]
  unsigned int rateScaleFixa; // [esp+20h] [ebp+18h]

  v6 = 0;
  v7 = 0;
  v8 = inputOffset >> 14;
  rateScaleFix14 = rateScaleFix >> 14;
  if ( outCount > 0 )
  {
    rateScaleFixa = *pVolume;
    inputOffseta = pVolume[1];
    do
    {
      pOutput[v6].left += (int)((pData[v7] + ((int)(v8 * (pData[v7 + 2] - pData[v7])) >> 14)) * rateScaleFixa) >> 8;
      v9 = pData[v7 + 1];
      v10 = v8 * (pData[v7 + 3] - v9);
      v11 = rateScaleFix14 + v8;
      pOutput[v6++].right += (inputOffseta * (v9 + (v10 >> 14))) >> 8;
      v7 += (v11 >> 13) & 0xFFFFFFFE;
      v8 = v11 & 0x3FFF;
    }
    while ( v6 < outCount );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002D860
// Name: _SND_InitMouth
// Source: json
//------------------------------------------------------------------------------
void __cdecl SND_InitMouth(channel_t *pChannel)
{
  IClientEntityList *v1; // ecx
  CSfxTable *sfx; // eax
  int speakerentity; // eax
  int v4; // eax
  int v5; // eax
  CMouthInfo *v6; // edi
  char v7; // cl
  CSfxTable *v8; // eax

  v1 = entitylist;
  if ( entitylist != nullptr )
  {
    if ( pChannel->entchannel != 2 )
    {
      sfx = pChannel->sfx;
      if ( sfx == nullptr || sfx->pSource == nullptr || sfx->pSource->GetSentence(this: sfx->pSource) == nullptr )
        return;
      v1 = entitylist;
    }
    speakerentity = pChannel->speakerentity;
    if ( speakerentity == -1 )
      speakerentity = pChannel->soundsource;
    v4 = (int)v1->GetClientEntity(this: v1, a2: speakerentity);
    if ( v4 != 0 )
    {
      v5 = (*(int (__thiscall **)(int))(*(_DWORD *)v4 + 48))(a1: v4);
      v6 = (CMouthInfo *)v5;
      if ( v5 != 0 )
      {
        *(_DWORD *)(v5 + 4) = 0;
        *(_WORD *)v5 = 0;
        *((_BYTE *)&pChannel->flags + 1) |= 0x40u;
        v7 = *((_BYTE *)&pChannel->flags + 1) & 0x7F | ((*(_WORD *)(v5 + 10) != 0) << 7);
        v8 = pChannel->sfx;
        *((_BYTE *)&pChannel->flags + 1) = v7;
        if ( v8->pSource != nullptr && v8->pSource->GetSentence(this: v8->pSource) != nullptr )
          CMouthInfo::AddSource(
            this: v6,
            source: pChannel->sfx->pSource,
            bIgnorePhonemes: (*((_BYTE *)&pChannel->flags + 1) & 0x20) != 0);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002D950
// Name: void SND_MovieEnd(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SND_MovieEnd()
{
  if ( cl_movieinfo.moviename[0] != 0 && (cl_movieinfo.type & 4) != 0 )
    WaveFixupTmpFile(filename: cl_movieinfo.moviename);
}

//------------------------------------------------------------------------------
// Address: 0x1002D980
// Name: void SW_Mix16Stereo_NoShift_OptMeta<0>(struct portable_samplepair_t restrict __near *,int restrict __near *,short restrict __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SW_Mix16Stereo_NoShift_OptMeta<0>(
        portable_samplepair_t *pOutput,
        int *pVolume,
        __int16 *pData,
        unsigned int nOutCount)
{
  int v4; // ebx
  portable_samplepair_t *v5; // esi
  int v6; // edx
  __int16 *v7; // ecx
  __int16 *v8; // edi
  int *p_right; // eax
  int v10; // eax
  int v11; // ecx
  unsigned int v12; // [esp+Ch] [ebp-4h]
  int nOutCounta; // [esp+24h] [ebp+14h]

  v4 = nOutCount;
  v5 = pOutput;
  if ( (int)nOutCount < 4 )
  {
    v8 = pData;
  }
  else
  {
    v6 = *pVolume;
    v12 = nOutCount >> 2;
    v7 = pData + 5;
    nOutCounta = nOutCount - 4 * (nOutCount >> 2);
    v8 = pData;
    p_right = &pOutput[2].right;
    do
    {
      v5->left += (v6 * *v8) >> 8;
      *(p_right - 4) += (v6 * *(v7 - 4)) >> 8;
      *(p_right - 3) += (v6 * *(v7 - 3)) >> 8;
      *(p_right - 2) += (v6 * *(v7 - 2)) >> 8;
      *(p_right - 1) += (v6 * *(v7 - 1)) >> 8;
      *p_right += (v6 * *v7) >> 8;
      p_right[1] += (v6 * v7[1]) >> 8;
      p_right[2] += (v6 * v7[2]) >> 8;
      v5 += 4;
      p_right += 8;
      v8 += 8;
      v7 += 8;
      --v12;
    }
    while ( v12 != 0 );
    v4 = nOutCounta;
  }
  if ( v4 > 0 )
  {
    v10 = *pVolume;
    do
    {
      v11 = v10 * v8[1];
      v5->left += (v10 * *v8) >> 8;
      v5->right += v11 >> 8;
      --v4;
      ++v5;
      v8 += 2;
    }
    while ( v4 > 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002DA70
// Name: void SW_Mix16Stereo_NoShift_OptMeta<1>(struct portable_samplepair_t restrict __near *,int restrict __near *,short restrict __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SW_Mix16Stereo_NoShift_OptMeta<1>(
        portable_samplepair_t *pOutput,
        int *pVolume,
        __int16 *pData,
        unsigned int nOutCount)
{
  int v4; // esi
  int v5; // edx
  unsigned int v6; // edi
  int *p_right; // eax
  __int16 *v8; // ecx
  int v9; // edx
  int *v10; // eax
  __int16 *v11; // ecx

  v4 = nOutCount;
  if ( (int)nOutCount < 4 )
  {
    v8 = pData;
  }
  else
  {
    v5 = pVolume[1];
    v6 = nOutCount >> 2;
    v4 = nOutCount - 4 * (nOutCount >> 2);
    p_right = &pOutput[2].right;
    pOutput += 4 * (nOutCount >> 2);
    v8 = pData;
    do
    {
      *(p_right - 4) += (v5 * v8[1]) >> 8;
      *(p_right - 2) += (v5 * v8[3]) >> 8;
      *p_right += (v5 * v8[5]) >> 8;
      p_right[2] += (v5 * v8[7]) >> 8;
      p_right += 8;
      v8 += 8;
      --v6;
    }
    while ( v6 != 0 );
  }
  if ( v4 > 0 )
  {
    v9 = pVolume[1];
    v10 = &pOutput->right;
    v11 = v8 + 1;
    do
    {
      *v10 += (v9 * *v11) >> 8;
      --v4;
      v10 += 2;
      v11 += 2;
    }
    while ( v4 > 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002DB20
// Name: void SW_Mix16Stereo_NoShift_OptMeta<2>(struct portable_samplepair_t restrict __near *,int restrict __near *,short restrict __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SW_Mix16Stereo_NoShift_OptMeta<2>(
        portable_samplepair_t *pOutput,
        int *pVolume,
        __int16 *pData,
        unsigned int nOutCount)
{
  int v4; // esi
  int v5; // edx
  portable_samplepair_t *v6; // eax
  unsigned int v7; // edi
  __int16 *v8; // ecx
  int v9; // edx

  v4 = nOutCount;
  if ( (int)nOutCount < 4 )
  {
    v8 = pData;
    v6 = pOutput;
  }
  else
  {
    v5 = *pVolume;
    v6 = pOutput;
    v7 = nOutCount >> 2;
    v4 = nOutCount - 4 * (nOutCount >> 2);
    v8 = pData;
    do
    {
      v6->left += (v5 * *v8) >> 8;
      v6[1].left += (v5 * v8[2]) >> 8;
      v6[2].left += (v5 * v8[4]) >> 8;
      v6[3].left += (v5 * v8[6]) >> 8;
      v6 += 4;
      v8 += 8;
      --v7;
    }
    while ( v7 != 0 );
  }
  if ( v4 > 0 )
  {
    v9 = *pVolume;
    do
    {
      v6->left += (v9 * *v8) >> 8;
      --v4;
      ++v6;
      v8 += 2;
    }
    while ( v4 > 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002DBB0
// Name: void SW_Mix16Stereo_NoShift_OptMeta<3>(struct portable_samplepair_t restrict __near *,int restrict __near *,short restrict __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SW_Mix16Stereo_NoShift_OptMeta<3>(
        portable_samplepair_t *pOutput,
        int *pVolume,
        __int16 *pData,
        unsigned int nOutCount)
{
  int *v4; // ecx
  portable_samplepair_t *v5; // edx
  __int16 *v6; // esi
  int v7; // edi
  int *p_right; // eax
  __int16 *v9; // ecx
  int v10; // eax
  int v11; // ecx
  unsigned int v12; // [esp+Ch] [ebp-Ch]
  int v13; // [esp+10h] [ebp-8h]
  int v14; // [esp+14h] [ebp-4h]
  int nOutCounta; // [esp+2Ch] [ebp+14h]

  v4 = pVolume;
  v5 = pOutput;
  v6 = pData;
  v7 = nOutCount;
  if ( (int)nOutCount >= 4 )
  {
    v12 = nOutCount >> 2;
    v14 = *pVolume;
    v13 = pVolume[1];
    p_right = &pOutput[2].right;
    v9 = pData + 5;
    nOutCounta = nOutCount - 4 * (nOutCount >> 2);
    do
    {
      v5->left += (v14 * *v6) >> 8;
      *(p_right - 4) += (v13 * *(v9 - 4)) >> 8;
      *(p_right - 3) += (v14 * *(v9 - 3)) >> 8;
      *(p_right - 2) += (v13 * *(v9 - 2)) >> 8;
      *(p_right - 1) += (v14 * *(v9 - 1)) >> 8;
      *p_right += (v13 * *v9) >> 8;
      p_right[1] += (v14 * v9[1]) >> 8;
      p_right[2] += (v13 * v9[2]) >> 8;
      v5 += 4;
      p_right += 8;
      v6 += 8;
      v9 += 8;
      --v12;
    }
    while ( v12 != 0 );
    v4 = pVolume;
    v7 = nOutCounta;
  }
  if ( v7 > 0 )
  {
    v10 = *v4;
    v11 = v4[1];
    do
    {
      v5->left += (v10 * *v6) >> 8;
      v5->right += (v11 * v6[1]) >> 8;
      --v7;
      ++v5;
      v6 += 2;
    }
    while ( v7 > 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002DCB0
// Name: void SW_Mix16Stereo_Shift_OptMeta<0>(struct portable_samplepair_t restrict __near *,int restrict __near *,short restrict __near *,int,unsigned int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SW_Mix16Stereo_Shift_OptMeta<0>(
        portable_samplepair_t *pOutput,
        int *pVolume,
        __int16 *pData,
        int nInputOffset,
        unsigned int nRateScaleFix,
        unsigned int nOutCount)
{
  int v7; // ebx
  portable_samplepair_t *v8; // edi
  int v9; // edx
  __int16 *v10; // esi
  int *p_right; // eax
  int v12; // ecx
  __int16 *v13; // esi
  int v14; // ecx
  __int16 *v15; // esi
  int v16; // ecx
  __int16 *v17; // esi
  int v18; // ecx
  unsigned int v19; // ebx
  bool v20; // zf
  int v21; // eax
  int v22; // ecx
  unsigned int v23; // edx
  unsigned int nInputOffseta; // [esp+20h] [ebp+14h]
  int nOutCounta; // [esp+28h] [ebp+1Ch]

  v7 = nOutCount;
  v8 = pOutput;
  if ( (int)nOutCount < 4 )
  {
    v10 = pData;
  }
  else
  {
    v9 = *pVolume;
    nInputOffseta = nOutCount >> 2;
    nOutCounta = nOutCount - 4 * (nOutCount >> 2);
    v10 = pData;
    p_right = &pOutput[2].right;
    do
    {
      v8->left += (v9 * *v10) >> 8;
      v12 = nRateScaleFix + nInputOffset;
      *(p_right - 4) += (v9 * v10[1]) >> 8;
      v13 = &v10[(v12 >> 27) & 0xFFFFFFFE];
      *(p_right - 3) += (v9 * *v13) >> 8;
      *(p_right - 2) += (v9 * v13[1]) >> 8;
      v14 = nRateScaleFix + (v12 & 0xFFFFFFF);
      v8 += 4;
      v15 = &v13[(v14 >> 27) & 0xFFFFFFFE];
      *(p_right - 1) += (v9 * *v15) >> 8;
      *p_right += (v9 * v15[1]) >> 8;
      v16 = nRateScaleFix + (v14 & 0xFFFFFFF);
      p_right += 8;
      v17 = &v15[(v16 >> 27) & 0xFFFFFFFE];
      *(p_right - 7) += (v9 * *v17) >> 8;
      *(p_right - 6) += (v9 * v17[1]) >> 8;
      v18 = nRateScaleFix + (v16 & 0xFFFFFFF);
      v19 = (v18 >> 27) & 0xFFFFFFFE;
      nInputOffset = v18 & 0xFFFFFFF;
      v20 = nInputOffseta-- == 1;
      v10 = &v17[v19];
    }
    while ( !v20 );
    v7 = nOutCounta;
  }
  if ( v7 > 0 )
  {
    v21 = *pVolume;
    do
    {
      v22 = nRateScaleFix + nInputOffset;
      v8->left += (v21 * *v10) >> 8;
      v8->right += (v21 * v10[1]) >> 8;
      v23 = (v22 >> 27) & 0xFFFFFFFE;
      --v7;
      nInputOffset = v22 & 0xFFFFFFF;
      ++v8;
      v10 += v23;
    }
    while ( v7 > 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002DDF0
// Name: void SW_Mix16Stereo_Shift_OptMeta<1>(struct portable_samplepair_t restrict __near *,int restrict __near *,short restrict __near *,int,unsigned int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SW_Mix16Stereo_Shift_OptMeta<1>(
        portable_samplepair_t *pOutput,
        int *pVolume,
        __int16 *pData,
        int nInputOffset,
        unsigned int nRateScaleFix,
        unsigned int nOutCount)
{
  int v7; // ebx
  int v8; // edi
  int *p_right; // eax
  __int16 *v10; // edx
  int v11; // ecx
  __int16 *v12; // edx
  int v13; // ecx
  __int16 *v14; // edx
  int v15; // ecx
  __int16 *v16; // edx
  int v17; // ecx
  unsigned int v18; // ebx
  bool v19; // zf
  int v20; // edi
  int *v21; // eax
  int v22; // ecx
  unsigned int nInputOffseta; // [esp+20h] [ebp+14h]

  v7 = nOutCount;
  if ( (int)nOutCount < 4 )
  {
    v10 = pData;
  }
  else
  {
    v8 = pVolume[1];
    nInputOffseta = nOutCount >> 2;
    nOutCount -= 4 * (nOutCount >> 2);
    p_right = &pOutput[2].right;
    pOutput += 4 * ((unsigned int)v7 >> 2);
    v10 = pData;
    do
    {
      *(p_right - 4) += (v8 * v10[1]) >> 8;
      v11 = nRateScaleFix + nInputOffset;
      v12 = &v10[(v11 >> 27) & 0xFFFFFFFE];
      *(p_right - 2) += (v8 * v12[1]) >> 8;
      v13 = nRateScaleFix + (v11 & 0xFFFFFFF);
      v14 = &v12[(v13 >> 27) & 0xFFFFFFFE];
      *p_right += (v8 * v14[1]) >> 8;
      v15 = nRateScaleFix + (v13 & 0xFFFFFFF);
      v16 = &v14[(v15 >> 27) & 0xFFFFFFFE];
      p_right[2] += (v8 * v16[1]) >> 8;
      v17 = nRateScaleFix + (v15 & 0xFFFFFFF);
      v18 = (v17 >> 27) & 0xFFFFFFFE;
      nInputOffset = v17 & 0xFFFFFFF;
      p_right += 8;
      v19 = nInputOffseta-- == 1;
      v10 = &v16[v18];
    }
    while ( !v19 );
    v7 = nOutCount;
  }
  if ( v7 > 0 )
  {
    v20 = pVolume[1];
    v21 = &pOutput->right;
    do
    {
      *v21 += (v20 * v10[1]) >> 8;
      v22 = nRateScaleFix + nInputOffset;
      v10 += (v22 >> 27) & 0xFFFFFFFE;
      nInputOffset = v22 & 0xFFFFFFF;
      v21 += 2;
      --nOutCount;
    }
    while ( (int)nOutCount > 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002DF10
// Name: void SW_Mix16Stereo_Shift_OptMeta<2>(struct portable_samplepair_t restrict __near *,int restrict __near *,short restrict __near *,int,unsigned int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SW_Mix16Stereo_Shift_OptMeta<2>(
        portable_samplepair_t *pOutput,
        int *pVolume,
        __int16 *pData,
        int nInputOffset,
        unsigned int nRateScaleFix,
        unsigned int nOutCount)
{
  int v7; // ebx
  int v8; // edi
  portable_samplepair_t *v9; // eax
  __int16 *v10; // edx
  int v11; // ecx
  __int16 *v12; // edx
  int v13; // ecx
  __int16 *v14; // edx
  int v15; // ecx
  __int16 *v16; // edx
  int v17; // ecx
  unsigned int v18; // ebx
  bool v19; // zf
  int v20; // ebx
  int v21; // ecx
  unsigned int nInputOffseta; // [esp+20h] [ebp+14h]

  v7 = nOutCount;
  if ( (int)nOutCount < 4 )
  {
    v10 = pData;
    v9 = pOutput;
  }
  else
  {
    v8 = *pVolume;
    nInputOffseta = nOutCount >> 2;
    v9 = pOutput;
    nOutCount -= 4 * (nOutCount >> 2);
    v10 = pData;
    do
    {
      v9->left += (v8 * *v10) >> 8;
      v11 = nRateScaleFix + nInputOffset;
      v12 = &v10[(v11 >> 27) & 0xFFFFFFFE];
      v9[1].left += (v8 * *v12) >> 8;
      v13 = nRateScaleFix + (v11 & 0xFFFFFFF);
      v14 = &v12[(v13 >> 27) & 0xFFFFFFFE];
      v9[2].left += (v8 * *v14) >> 8;
      v15 = nRateScaleFix + (v13 & 0xFFFFFFF);
      v16 = &v14[(v15 >> 27) & 0xFFFFFFFE];
      v9[3].left += (v8 * *v16) >> 8;
      v17 = nRateScaleFix + (v15 & 0xFFFFFFF);
      v18 = (v17 >> 27) & 0xFFFFFFFE;
      nInputOffset = v17 & 0xFFFFFFF;
      v9 += 4;
      v19 = nInputOffseta-- == 1;
      v10 = &v16[v18];
    }
    while ( !v19 );
    v7 = nOutCount;
  }
  if ( v7 > 0 )
  {
    v20 = *pVolume;
    do
    {
      v9->left += (v20 * *v10) >> 8;
      v21 = nRateScaleFix + nInputOffset;
      v10 += (v21 >> 27) & 0xFFFFFFFE;
      nInputOffset = v21 & 0xFFFFFFF;
      ++v9;
      --nOutCount;
    }
    while ( (int)nOutCount > 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002E020
// Name: void SW_Mix16Stereo_Shift_OptMeta<3>(struct portable_samplepair_t restrict __near *,int restrict __near *,short restrict __near *,int,unsigned int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SW_Mix16Stereo_Shift_OptMeta<3>(
        portable_samplepair_t *pOutput,
        int *pVolume,
        __int16 *pData,
        int nInputOffset,
        unsigned int nRateScaleFix,
        unsigned int nOutCount)
{
  int *v7; // eax
  int v8; // ebx
  portable_samplepair_t *v9; // esi
  unsigned int v10; // edi
  __int16 *v11; // edx
  int *p_right; // eax
  int v13; // ecx
  int v14; // ecx
  int v15; // ecx
  int v16; // ecx
  unsigned int v17; // edx
  bool v18; // zf
  int v19; // ecx
  unsigned int v20; // [esp+Ch] [ebp-8h]
  int v21; // [esp+10h] [ebp-4h]
  int v22; // [esp+10h] [ebp-4h]
  __int16 *pDataa; // [esp+24h] [ebp+10h]
  __int16 *pDatab; // [esp+24h] [ebp+10h]
  __int16 *pDatac; // [esp+24h] [ebp+10h]
  int nInputOffseta; // [esp+28h] [ebp+14h]
  int nInputOffsetb; // [esp+28h] [ebp+14h]

  v7 = pVolume;
  v8 = nOutCount;
  v9 = pOutput;
  v10 = nRateScaleFix;
  if ( (int)nOutCount < 4 )
  {
    v11 = pData;
  }
  else
  {
    nInputOffseta = *pVolume;
    v20 = nOutCount >> 2;
    v21 = pVolume[1];
    nOutCount -= 4 * (nOutCount >> 2);
    v11 = pData;
    p_right = &pOutput[2].right;
    do
    {
      v9->left += (nInputOffseta * *v11) >> 8;
      *(p_right - 4) += (v21 * v11[1]) >> 8;
      v10 = nRateScaleFix;
      v13 = nRateScaleFix + nInputOffset;
      pDataa = &v11[(v13 >> 27) & 0xFFFFFFFE];
      *(p_right - 3) += (nInputOffseta * *pDataa) >> 8;
      *(p_right - 2) += (v21 * pDataa[1]) >> 8;
      v14 = nRateScaleFix + (v13 & 0xFFFFFFF);
      pDatab = &pDataa[(v14 >> 27) & 0xFFFFFFFE];
      *(p_right - 1) += (nInputOffseta * *pDatab) >> 8;
      *p_right += (v21 * pDatab[1]) >> 8;
      v15 = nRateScaleFix + (v14 & 0xFFFFFFF);
      pDatac = &pDatab[(v15 >> 27) & 0xFFFFFFFE];
      p_right[1] += (nInputOffseta * *pDatac) >> 8;
      p_right[2] += (v21 * pDatac[1]) >> 8;
      v16 = nRateScaleFix + (v15 & 0xFFFFFFF);
      v17 = (v16 >> 27) & 0xFFFFFFFE;
      nInputOffset = v16 & 0xFFFFFFF;
      v9 += 4;
      p_right += 8;
      v18 = v20-- == 1;
      v11 = &pDatac[v17];
    }
    while ( !v18 );
    v8 = nOutCount;
    v7 = pVolume;
  }
  if ( v8 > 0 )
  {
    nInputOffsetb = *v7;
    v22 = v7[1];
    do
    {
      v9->left += (nInputOffsetb * *v11) >> 8;
      v9->right += (v22 * v11[1]) >> 8;
      v19 = v10 + nInputOffset;
      v11 += (v19 >> 27) & 0xFFFFFFFE;
      nInputOffset = v19 & 0xFFFFFFF;
      ++v9;
      --nOutCount;
    }
    while ( (int)nOutCount > 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002E1B0
// Name: public: void CMouthInfo::RemoveSource(class CAudioSource __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMouthInfo::RemoveSource(CMouthInfo *this, CAudioSource *source)
{
  __int16 m_nVoiceSources; // si
  int v3; // eax
  CVoiceData *i; // edx
  CVoiceData *v5; // edx
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
      this->m_nVoiceSources = m_nVoiceSources - 1;
      if ( (__int16)(m_nVoiceSources - 1) > 0 )
      {
        v5 = &this->m_VoiceSources[(__int16)(m_nVoiceSources - 1)];
        v6 = &this->m_VoiceSources[v3];
        v6->m_flElapsed = v5->m_flElapsed;
        v6->m_pAudioSource = v5->m_pAudioSource;
        *(_DWORD *)&v6->m_bIgnorePhonemes = *(_DWORD *)&v5->m_bIgnorePhonemes;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002E230
// Name: _MIX_FreeAllPaintbuffers
// Source: json
//------------------------------------------------------------------------------
void MIX_FreeAllPaintbuffers()
{
  int i; // esi
  portable_samplepair_t *pbuf; // eax
  portable_samplepair_t *pbufrear; // eax
  portable_samplepair_t *pbufcenter; // eax

  if ( g_paintBuffers != nullptr )
  {
    if ( g_temppaintbuffer != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: *(void **)(((unsigned int)g_temppaintbuffer & 0xFFFFFFFC) - 4));
      g_temppaintbuffer = nullptr;
    }
    for ( i = 0; i < 6; ++i )
    {
      pbuf = g_paintBuffers[i].pbuf;
      if ( pbuf != nullptr )
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: *(void **)(((unsigned int)pbuf & 0xFFFFFFFC) - 4));
      pbufrear = g_paintBuffers[i].pbufrear;
      if ( pbufrear != nullptr )
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: *(void **)(((unsigned int)pbufrear & 0xFFFFFFFC) - 4));
      pbufcenter = g_paintBuffers[i].pbufcenter;
      if ( pbufcenter != nullptr )
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: *(void **)(((unsigned int)pbufcenter & 0xFFFFFFFC) - 4));
    }
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: g_paintBuffers);
    g_paintBuffers = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002E310
// Name: _MIX_InitAllPaintbuffers
// Source: json
//------------------------------------------------------------------------------
char __cdecl MIX_InitAllPaintbuffers()
{
  void *v0; // eax
  portable_samplepair_t *v1; // ecx
  int i; // esi
  void *v3; // eax
  portable_samplepair_t *v4; // ecx
  void *v5; // eax
  portable_samplepair_t *v6; // ecx
  void *v7; // eax
  portable_samplepair_t *v8; // ecx
  bool bSurroundCenter; // [esp+6h] [ebp-2h]
  bool bSurround; // [esp+7h] [ebp-1h]

  bSurroundCenter = g_AudioDevice->IsSurroundCenter(this: g_AudioDevice);
  if ( g_AudioDevice->IsSurround(this: g_AudioDevice) || (bSurround = false, bSurroundCenter) )
    bSurround = true;
  g_paintBuffers = (paintbuffer_t *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 1872);
  _V_memset(dest: g_paintBuffers, fill: 0, count: 1872);
  v0 = _g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 32787);
  if ( v0 != nullptr )
  {
    v1 = (portable_samplepair_t *)(((unsigned int)v0 + 19) & 0xFFFFFFF0);
    v1[-1].right = (int)v0;
  }
  else
  {
    v1 = nullptr;
  }
  g_temppaintbuffer = v1;
  _V_memset(dest: v1, fill: 0, count: 0x8000);
  for ( i = 0; i < 6; ++i )
  {
    v3 = _g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 8211);
    if ( v3 != nullptr )
    {
      v4 = (portable_samplepair_t *)(((unsigned int)v3 + 19) & 0xFFFFFFF0);
      v4[-1].right = (int)v3;
    }
    else
    {
      v4 = nullptr;
    }
    g_paintBuffers[i].pbuf = v4;
    _V_memset(dest: g_paintBuffers[i].pbuf, fill: 0, count: 0x2000);
    if ( bSurround )
    {
      v5 = _g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 8211);
      if ( v5 != nullptr )
      {
        v6 = (portable_samplepair_t *)(((unsigned int)v5 + 19) & 0xFFFFFFF0);
        v6[-1].right = (int)v5;
      }
      else
      {
        v6 = nullptr;
      }
      g_paintBuffers[i].pbufrear = v6;
      _V_memset(dest: g_paintBuffers[i].pbufrear, fill: 0, count: 0x2000);
    }
    if ( bSurroundCenter )
    {
      v7 = _g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 8211);
      if ( v7 != nullptr )
      {
        v8 = (portable_samplepair_t *)(((unsigned int)v7 + 19) & 0xFFFFFFF0);
        v8[-1].right = (int)v7;
      }
      else
      {
        v8 = nullptr;
      }
      g_paintBuffers[i].pbufcenter = v8;
      _V_memset(dest: g_paintBuffers[i].pbufcenter, fill: 0, count: 0x2000);
    }
  }
  g_paintbuffer = g_paintBuffers->pbuf;
  g_paintBuffers[1].flags = 1;
  g_paintBuffers[2].flags = 2;
  g_paintBuffers[3].flags = 4;
  g_paintBuffers[5].flags = 8;
  g_paintBuffers[4].flags = 16;
  g_paintBuffers->fsurround = bSurround;
  g_paintBuffers[2].fsurround = bSurround;
  g_paintBuffers[3].fsurround = bSurround;
  g_paintBuffers[4].fsurround = bSurround;
  g_paintBuffers->fsurround_center = bSurroundCenter;
  g_paintBuffers[2].fsurround_center = bSurroundCenter;
  g_paintBuffers[3].fsurround_center = bSurroundCenter;
  g_paintBuffers[4].fsurround_center = bSurroundCenter;
  g_paintBuffers[1].fsurround = false;
  g_paintBuffers[1].fsurround_center = false;
  g_paintBuffers[5].fsurround = false;
  g_paintBuffers[5].fsurround_center = false;
  g_curpaintbuffer = g_paintBuffers->pbuf;
  if ( g_paintBuffers->fsurround )
  {
    g_currearpaintbuffer = g_paintBuffers->pbufrear;
    g_curcenterpaintbuffer = nullptr;
    if ( g_paintBuffers->fsurround_center )
    {
      g_curcenterpaintbuffer = g_paintBuffers->pbufcenter;
      return 1;
    }
  }
  else
  {
    g_currearpaintbuffer = nullptr;
    g_curcenterpaintbuffer = nullptr;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1002E5D0
// Name: void SDEBUG_GetAvgValue(int,int,float __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SDEBUG_GetAvgValue(int ibuf, int count, float *pav)
{
  float v3; // xmm1_4
  int v4; // esi
  unsigned int v5; // eax
  float v6; // xmm0_4
  float v7; // xmm0_4
  int v8; // eax

  if ( snd_showstart.m_pParent != nullptr && snd_showstart.m_pParent->m_Value.m_nValue == 4 )
  {
    v3 = 0.0;
    v4 = 0;
    if ( count >= 4 )
    {
      v5 = ((unsigned int)(count - 4) >> 2) + 1;
      v6 = (float)(int)(abs32(g_paintBuffers[ibuf].pbuf->left) + abs32(g_paintBuffers[ibuf].pbuf->right)) * 0.5;
      v4 = 4 * v5;
      do
      {
        --v5;
        v3 = (float)((float)((float)(v3 + v6) + v6) + v6) + v6;
      }
      while ( v5 != 0 );
    }
    if ( v4 < count )
    {
      v7 = (float)(int)(abs32(g_paintBuffers[ibuf].pbuf->left) + abs32(g_paintBuffers[ibuf].pbuf->right)) * 0.5;
      v8 = count - v4;
      do
      {
        --v8;
        v3 = v3 + v7;
      }
      while ( v8 != 0 );
    }
    *pav = v3 / (float)count;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002E6C0
// Name: public: void CChannelCullList::Initialize(class CChannelList __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChannelCullList::Initialize(CChannelCullList *this, CChannelList *list)
{
  CChannelList *v2; // ebx
  int m_count; // esi
  int v5; // esi
  unsigned int *p_m_nameHash; // eax
  __int16 *v7; // ebx
  int v8; // ebx
  bool v9; // zf
  channel_t *v10; // ebx
  int m_numChans; // edx
  CChannelCullList::sChannelVolData *v12; // eax
  int v13; // ecx
  int v14; // edx
  __int16 *m_list; // ebx
  channel_t *v16; // ecx
  int v17; // ebx
  int v18; // eax
  CChannelCullList *v19; // esi
  __int16 *v20; // [esp+Ch] [ebp-8h]
  __int16 *v21; // [esp+Ch] [ebp-8h]
  unsigned int *v22; // [esp+10h] [ebp-4h]
  int cutoff; // [esp+1Ch] [ebp+8h]

  v2 = list;
  m_count = list->m_count;
  this->m_numChans = list->m_count;
  v5 = m_count - 1;
  if ( v5 >= 0 )
  {
    p_m_nameHash = &this->m_channelInfo[v5].m_nameHash;
    v7 = &list->m_list[v5];
    v22 = p_m_nameHash;
    v20 = v7;
    while ( 1 )
    {
      v8 = *v7;
      v9 = &channels[v8] == nullptr;
      v10 = &channels[v8];
      *(p_m_nameHash - 2) = v5;
      if ( v9 )
        goto LABEL_7;
      if ( !v10->pMixer->IsReadyToMix(this: v10->pMixer) )
        break;
      *(v22 - 1) = (int)ChannelLoudestCurVolume(pch: v10);
      *v22 = (unsigned int)v10->sfx;
      p_m_nameHash = v22;
LABEL_8:
      v7 = v20 - 1;
      p_m_nameHash -= 3;
      --v5;
      --v20;
      v22 = p_m_nameHash;
      if ( v5 < 0 )
      {
        v2 = list;
        goto LABEL_10;
      }
    }
    p_m_nameHash = v22;
LABEL_7:
    *(p_m_nameHash - 1) = -1;
    *p_m_nameHash = 0;
    goto LABEL_8;
  }
LABEL_10:
  m_numChans = this->m_numChans;
  if ( m_numChans < 128 )
  {
    v12 = &this->m_channelInfo[m_numChans];
    v13 = 128 - m_numChans;
    do
    {
      v12->m_channelNum = -1;
      v12->m_vol = -1;
      ++v12;
      --v13;
    }
    while ( v13 != 0 );
  }
  qsort(base: this, num: 0x80u, width: 0xCu, comp: ChannelVolComparator);
  v14 = 0;
  if ( snd_cull_duplicates.m_pParent != nullptr )
    cutoff = snd_cull_duplicates.m_pParent->m_Value.m_nValue;
  else
    cutoff = 0;
  if ( this->m_numChans > 0 )
  {
    m_list = v2->m_list;
    v21 = m_list;
    do
    {
      v16 = &channels[*m_list];
      v17 = 0;
      v18 = 0;
      if ( this->m_channelInfo[0].m_channelNum != v14 )
      {
        v19 = this;
        do
        {
          if ( v19->m_channelInfo[0].m_vol < 0 || v18 >= 128 )
            break;
          if ( (CSfxTable *)v19->m_channelInfo[0].m_nameHash == v16->sfx )
            ++v17;
          ++v18;
          v19 = (CChannelCullList *)((char *)this + 12 * v18);
        }
        while ( v19->m_channelInfo[0].m_channelNum != v14 );
      }
      this->m_bShouldCull[v14++] = v17 >= cutoff;
      m_list = ++v21;
    }
    while ( v14 < this->m_numChans );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002E830
// Name: bool MIX_ScaleChannelVolume(struct paintbuffer_t __near *,struct channel_t __near *,int __near * const,int)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl MIX_ScaleChannelVolume(paintbuffer_t *ppaint, channel_t *pChannel, int *volume)
{
  float v4; // xmm3_4
  int v5; // edi
  CAudioSource *v6; // eax
  int i; // eax
  int v8; // ecx
  int j; // eax
  float v10; // xmm0_4
  int k; // eax
  int m; // eax
  int v13; // edi
  int v14; // ebx
  int v15; // kr00_4
  int v16; // eax
  char v17; // cl
  int *v18; // esi
  int n; // edx
  int v20; // eax
  int v21; // eax
  int v22; // eax
  int v23; // eax
  int v24; // eax
  int v25; // eax
  int mixflag; // [esp+Ch] [ebp-8h]
  float dspmix; // [esp+10h] [ebp-4h]
  int nFrontRightD; // [esp+1Ch] [ebp+8h]
  int nFrontLeftD; // [esp+20h] [ebp+Ch]
  char nFrontLeftD_3; // [esp+23h] [ebp+Fh]

  mixflag = ppaint->flags;
  nFrontLeftD_3 = pChannel->wavtype;
  ChannelCopyVolumes(pch: pChannel, pvolume_dest: volume, ivol_start: 0, cvol: 12);
  dspmix = pChannel->dspmix * 256.0;
  if ( g_bDspOff || DSP_RoomDSPIsOff() )
  {
    v4 = 0.0;
    dspmix = 0.0;
  }
  else
  {
    v4 = dspmix;
  }
  v5 = g_SND_VoiceOverdriveInt;
  if ( g_DuckScaleInt256 < g_SND_VoiceOverdriveInt )
    v5 = g_DuckScaleInt256;
  if ( v5 < 256 && pChannel->pMixer != nullptr )
  {
    v6 = pChannel->pMixer->GetSource(this: pChannel->pMixer);
    if ( !v6->IsVoiceSource(this: v6) )
    {
      for ( i = 0; i < 12; ++i )
        volume[i] = (v5 * volume[i]) >> 8;
    }
    v4 = dspmix;
  }
  if ( (mixflag & 1) != 0 )
  {
    v8 = (int)(float)(g_dsp_volume * v4);
    if ( v8 >= 256 )
      v8 = 256;
    for ( j = 0; j < 12; ++j )
      volume[j] = (v8 * volume[j]) >> 8;
  }
  if ( g_dsp_volume < 1.0 )
    v4 = g_dsp_volume * v4;
  v10 = (float)((float)(pChannel->dspface + 1.0) * 0.5) * 1.6666666;
  if ( v10 >= 0.0 )
  {
    if ( v10 > 1.0 )
      v10 = 1.0;
  }
  else
  {
    v10 = 0.0;
  }
  if ( !g_bdirectionalfx || nFrontLeftD_3 != 60 )
    v10 = 1.0;
  if ( (mixflag & 2) != 0 )
  {
    for ( k = 0; k < 12; ++k )
      volume[k] = ((int)(float)((float)(256.0 - v4) * v10) * volume[k]) >> 8;
  }
  else if ( (mixflag & 4) != 0 )
  {
    for ( m = 0; m < 12; ++m )
      volume[m] = ((int)(float)((float)(1.0 - v10) * (float)(256.0 - v4)) * volume[m]) >> 8;
  }
  if ( g_AudioDevice->IsSurround(this: g_AudioDevice) && !ppaint->fsurround )
  {
    v13 = volume[1] + volume[3];
    v14 = volume[2] + *volume;
    nFrontRightD = volume[7] + volume[9];
    nFrontLeftD = volume[6] + volume[8];
    if ( g_AudioDevice->IsSurroundCenter(this: g_AudioDevice) )
    {
      v15 = volume[4];
      v13 += v15 / 2;
      v14 += v15 / 2;
      v16 = volume[10] / 2;
      nFrontRightD += v16;
      nFrontLeftD += v16;
    }
    volume[1] = v13;
    *volume = v14;
    volume[7] = nFrontRightD;
    volume[6] = nFrontLeftD;
    volume[3] = 0;
    volume[2] = 0;
    volume[4] = 0;
    volume[9] = 0;
    volume[8] = 0;
    volume[10] = 0;
  }
  v17 = 1;
  v18 = volume + 2;
  for ( n = 2; n != 0; --n )
  {
    v20 = *(v18 - 2);
    if ( v20 >= 0 )
    {
      if ( v20 > 255 )
        v20 = 255;
    }
    else
    {
      v20 = 0;
    }
    *(v18 - 2) = v20;
    if ( v20 != 0 )
      v17 = 0;
    v21 = *(v18 - 1);
    if ( v21 >= 0 )
    {
      if ( v21 > 255 )
        v21 = 255;
    }
    else
    {
      v21 = 0;
    }
    *(v18 - 1) = v21;
    if ( v21 != 0 )
      v17 = 0;
    v22 = *v18;
    if ( *v18 >= 0 )
    {
      if ( v22 > 255 )
        v22 = 255;
    }
    else
    {
      v22 = 0;
    }
    *v18 = v22;
    if ( v22 != 0 )
      v17 = 0;
    v23 = v18[1];
    if ( v23 >= 0 )
    {
      if ( v23 > 255 )
        v23 = 255;
    }
    else
    {
      v23 = 0;
    }
    v18[1] = v23;
    if ( v23 != 0 )
      v17 = 0;
    v24 = v18[2];
    if ( v24 >= 0 )
    {
      if ( v24 > 255 )
        v24 = 255;
    }
    else
    {
      v24 = 0;
    }
    v18[2] = v24;
    if ( v24 != 0 )
      v17 = 0;
    v25 = v18[3];
    if ( v25 >= 0 )
    {
      if ( v25 > 255 )
        v25 = 255;
    }
    else
    {
      v25 = 0;
    }
    v18[3] = v25;
    if ( v25 != 0 )
      v17 = 0;
    v18 += 6;
  }
  return v17 == 0;
}

//------------------------------------------------------------------------------
// Address: 0x1002EB60
// Name: void SW_Mix16StereoDistVar(float,struct portable_samplepair_t __near *,int __near *,short __near *,int,unsigned int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SW_Mix16StereoDistVar(
        float distmix,
        portable_samplepair_t *pOutput,
        int *volume,
        __int16 *pData,
        int inputOffset,
        unsigned int rateScaleFix,
        int outCount)
{
  int v8; // esi
  int k; // eax
  int v10; // edi
  int v11; // ecx
  int j; // eax
  int v13; // edi
  int v14; // ecx
  int i; // edx
  int v16; // eax
  int v17; // ecx
  int inputOffseta; // [esp+24h] [ebp+18h]

  v8 = 0;
  inputOffseta = (int)(float)(distmix * 256.0);
  if ( (int)(float)((float)(1.0 - distmix) * 256.0) != 0 )
  {
    if ( inputOffseta != 0 )
    {
      for ( i = 0; i < outCount; inputOffset = v17 & 0xFFFFFFF )
      {
        v16 = pData[v8] + ((inputOffseta * (pData[v8 + 1] - pData[v8])) >> 8);
        v17 = rateScaleFix + inputOffset;
        pOutput[i].left += (v16 * *volume) >> 8;
        pOutput[i++].right += (v16 * volume[1]) >> 8;
        v8 += (v17 >> 27) & 0xFFFFFFFE;
      }
    }
    else
    {
      for ( j = 0; j < outCount; inputOffset = v14 & 0xFFFFFFF )
      {
        v13 = pData[v8];
        v14 = rateScaleFix + inputOffset;
        pOutput[j].left += (v13 * *volume) >> 8;
        pOutput[j++].right += (v13 * volume[1]) >> 8;
        v8 += (v14 >> 27) & 0xFFFFFFFE;
      }
    }
  }
  else
  {
    for ( k = 0; k < outCount; inputOffset = v11 & 0xFFFFFFF )
    {
      v10 = pData[v8 + 1];
      v11 = rateScaleFix + inputOffset;
      pOutput[k].left += (v10 * *volume) >> 8;
      pOutput[k++].right += (v10 * volume[1]) >> 8;
      v8 += (v11 >> 27) & 0xFFFFFFFE;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002ED00
// Name: void SW_Mix16StereoDistVar_Interp(float,struct portable_samplepair_t __near *,int __near *,short __near *,int,unsigned int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SW_Mix16StereoDistVar_Interp(
        float distmix,
        portable_samplepair_t *pOutput,
        int *volume,
        __int16 *pData,
        unsigned int inputOffset,
        unsigned int rateScaleFix,
        int outCount)
{
  int v7; // edx
  unsigned int v8; // ecx
  int k; // esi
  int v10; // ebx
  int v11; // eax
  int v12; // ecx
  int j; // esi
  int v14; // eax
  int v15; // ecx
  int i; // edi
  int v17; // ebx
  int v18; // esi
  int v19; // eax
  int v20; // ecx
  unsigned int rateScaleFix14; // [esp+8h] [ebp-4h]
  unsigned int rateScaleFixa; // [esp+28h] [ebp+1Ch]

  v7 = 0;
  rateScaleFix14 = rateScaleFix >> 14;
  v8 = inputOffset >> 14;
  rateScaleFixa = (int)(float)(distmix * 256.0);
  if ( (int)(float)((float)(1.0 - distmix) * 256.0) != 0 )
  {
    if ( rateScaleFixa != 0 )
    {
      for ( i = 0; i < outCount; v8 = v20 & 0x3FFF )
      {
        v17 = pData[v7 + 1];
        v18 = pData[v7] + ((int)(v8 * (pData[v7 + 2] - pData[v7])) >> 14);
        v19 = v18 + ((int)(rateScaleFixa * (v17 + ((int)(v8 * (pData[v7 + 3] - v17)) >> 14) - v18)) >> 8);
        v20 = rateScaleFix14 + v8;
        pOutput[i].left += (v19 * *volume) >> 8;
        pOutput[i++].right += (v19 * volume[1]) >> 8;
        v7 += (v20 >> 13) & 0xFFFFFFFE;
      }
    }
    else
    {
      for ( j = 0; j < outCount; v8 = v15 & 0x3FFF )
      {
        v14 = pData[v7] + ((int)(v8 * (pData[v7 + 2] - pData[v7])) >> 14);
        v15 = rateScaleFix14 + v8;
        pOutput[j].left += (v14 * *volume) >> 8;
        pOutput[j++].right += (v14 * volume[1]) >> 8;
        v7 += (v15 >> 13) & 0xFFFFFFFE;
      }
    }
  }
  else
  {
    for ( k = 0; k < outCount; v8 = v12 & 0x3FFF )
    {
      v10 = pData[v7 + 1];
      v11 = v10 + ((int)(v8 * (pData[v7 + 3] - v10)) >> 14);
      v12 = rateScaleFix14 + v8;
      pOutput[k].left += (v11 * *volume) >> 8;
      pOutput[k++].right += (v11 * volume[1]) >> 8;
      v7 += (v12 >> 13) & 0xFFFFFFFE;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002EEF0
// Name: void SW_Mix16Stereo_Opt(struct portable_samplepair_t restrict __near *,int restrict __near *,short restrict __near *,int,unsigned int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SW_Mix16Stereo_Opt(
        portable_samplepair_t *pOutput,
        int *pVolume,
        __int16 *pData,
        int nInputOffset,
        unsigned int nRateScaleFix,
        unsigned int nOutCount)
{
  int v6; // ecx
  int v7; // edx

  v6 = *pVolume;
  v7 = pVolume[1];
  if ( nRateScaleFix == 0x10000000 )
  {
    if ( v6 == v7 )
    {
      SW_Mix16Stereo_NoShift_OptMeta<0>(pOutput, pVolume, pData, nOutCount);
    }
    else if ( v6 > 1 )
    {
      if ( v7 > 1 )
        SW_Mix16Stereo_NoShift_OptMeta<3>(pOutput, pVolume, pData, nOutCount);
      else
        SW_Mix16Stereo_NoShift_OptMeta<2>(pOutput, pVolume, pData, nOutCount);
    }
    else
    {
      SW_Mix16Stereo_NoShift_OptMeta<1>(pOutput, pVolume, pData, nOutCount);
    }
  }
  else if ( v6 == v7 )
  {
    SW_Mix16Stereo_Shift_OptMeta<0>(pOutput, pVolume, pData, nInputOffset, nRateScaleFix, nOutCount);
  }
  else if ( v6 > 1 )
  {
    if ( v7 > 1 )
      SW_Mix16Stereo_Shift_OptMeta<3>(pOutput, pVolume, pData, nInputOffset, nRateScaleFix, nOutCount);
    else
      SW_Mix16Stereo_Shift_OptMeta<2>(pOutput, pVolume, pData, nInputOffset, nRateScaleFix, nOutCount);
  }
  else
  {
    SW_Mix16Stereo_Shift_OptMeta<1>(pOutput, pVolume, pData, nInputOffset, nRateScaleFix, nOutCount);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002EFD0
// Name: bool FUseHighQualityPitch(struct channel_t __near *)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl FUseHighQualityPitch(channel_t *pChannel)
{
  float pitch; // [esp+0h] [ebp-4h]

  if ( snd_pitchquality.m_pParent == nullptr
    || snd_pitchquality.m_pParent->m_Value.m_nValue == 0
    || (*((_BYTE *)&pChannel->flags + 1) & 2) != 0 )
  {
    return false;
  }
  pitch = pChannel->pitch;
  return pitch != floor(X: pitch);
}

//------------------------------------------------------------------------------
// Address: 0x1002F030
// Name: _Mix8MonoWavtype
// Source: json
//------------------------------------------------------------------------------
void __cdecl Mix8MonoWavtype(
        channel_t *pChannel,
        portable_samplepair_t *pOutput,
        int *volume,
        unsigned __int8 *pData,
        portable_samplepair_t *inputOffset,
        int *rateScaleFix,
        unsigned __int8 *outCount)
{
  float pitch; // [esp+0h] [ebp-4h]

  if ( snd_pitchquality.m_pParent == nullptr
    || snd_pitchquality.m_pParent->m_Value.m_nValue == 0
    || (*((_BYTE *)&pChannel->flags + 1) & 2) != 0
    || (pitch = pChannel->pitch) == floor(X: pitch) )
  {
    SW_Mix8Mono(pOutput, volume, pData, (int)inputOffset, (unsigned int)rateScaleFix, (int)outCount);
  }
  else
  {
    SW_Mix8Mono_Interp(pOutput, volume, pData, inputOffset: &inputOffset->left, rateScaleFix, (int)outCount);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002F0C0
// Name: _Mix16MonoWavtype
// Source: json
//------------------------------------------------------------------------------
void __cdecl Mix16MonoWavtype(
        channel_t *pChannel,
        portable_samplepair_t *pOutput,
        int *volume,
        __int16 *pData,
        int inputOffset,
        unsigned int rateScaleFix,
        int outCount)
{
  if ( *volume + volume[1] > 2 )
  {
    if ( FUseHighQualityPitch(pChannel) )
      SW_Mix16Mono_Interp(pOutput, volume, pData, inputOffset, rateScaleFix, outCount);
    else
      SW_Mix16Mono(pOutput, volume, pData, inputOffset, rateScaleFix, outCount);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002F130
// Name: void SND_MovieStart(void)
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __cdecl SND_MovieStart()
{
  unsigned int v0; // [esp-8h] [ebp-8h]
  int v1; // [esp-4h] [ebp-4h]

  if ( cl_movieinfo.moviename[0] != 0 )
  {
    g_soundtimeerror = 0.0;
    g_nMovieStartTick = host_tickcount;
    g_paintedtime = 0;
    g_soundtime = 0;
    g_moviestart = host_time;
    if ( snd_surround.m_pParent == nullptr || snd_surround.m_pParent->m_Value.m_nValue != 2 )
      CLoaderMemAlloc::CrtIsValidPointer(this: (ConVar *)&snd_surround.IConVar, value: 2, a2: v0, a3: v1);
    if ( (cl_movieinfo.type & 4) != 0 )
      WaveCreateTmpFile(filename: cl_movieinfo.moviename, rate: 44100, bits: 16, channels: 2);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002F1C0
// Name: _S_TransferPaintBuffer
// Source: json
//------------------------------------------------------------------------------
void __cdecl S_TransferPaintBuffer(
        _WORD *pOutput,
        const portable_samplepair_t *pfront,
        __int64 lpaintedtime,
        __int64 endtime)
{
  int v4; // edi
  int v5; // esi
  int v6; // ebx
  int v7; // eax
  int v8; // ebx
  int v9; // eax
  int v10; // [esp+20h] [ebp+14h]
  int v11; // [esp+28h] [ebp+1Ch]

  v4 = (endtime - lpaintedtime) * g_AudioDevice->DeviceChannels(this: g_AudioDevice);
  v11 = g_AudioDevice->DeviceSampleCount(this: g_AudioDevice) - 1;
  v5 = v11 & (lpaintedtime * g_AudioDevice->DeviceChannels(this: g_AudioDevice));
  v6 = 3 - g_AudioDevice->DeviceChannels(this: g_AudioDevice);
  v10 = (int)(S_GetMasterVolume() * 256.0);
  if ( g_AudioDevice->DeviceSampleBits(this: g_AudioDevice) == 16 )
  {
    for ( ; v4 != 0; v5 = v11 & (v5 + 1) )
    {
      v7 = (v10 * pfront->left) >> 8;
      --v4;
      pfront = (const portable_samplepair_t *)((char *)pfront + 4 * v6);
      if ( v7 >= -32767 )
      {
        if ( v7 > 0x7FFF )
          LOWORD(v7) = 0x7FFF;
      }
      else
      {
        LOWORD(v7) = -32767;
      }
      pOutput[v5] = v7;
    }
  }
  else if ( g_AudioDevice->DeviceSampleBits(this: g_AudioDevice) == 8 && v4 != 0 )
  {
    v8 = 4 * v6;
    do
    {
      v9 = (v10 * pfront->left) >> 8;
      --v4;
      pfront = (const portable_samplepair_t *)((char *)pfront + v8);
      if ( v9 >= -32767 )
      {
        if ( v9 > 0x7FFF )
          BYTE1(v9) = 127;
      }
      else
      {
        BYTE1(v9) = 0x80;
      }
      *((_BYTE *)pOutput + v5) = BYTE1(v9) + 0x80;
      v5 = v11 & (v5 + 1);
    }
    while ( v4 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002F300
// Name: _S_MixBufferUpsample2x
// Source: json
//------------------------------------------------------------------------------
void __cdecl S_MixBufferUpsample2x(
        int count,
        portable_samplepair_t *pbuffer,
        portable_samplepair_t *pfiltermem,
        int cfltmem,
        int filtertype)
{
  int v5; // edx
  portable_samplepair_t *v6; // eax
  portable_samplepair_t *v7; // ecx

  if ( filtertype == 1 )
  {
    if ( snd_mix_optimization.m_pParent != nullptr && snd_mix_optimization.m_pParent->m_Value.m_nValue != 0 )
      S_Interpolate2xLinear_3(count, pbuffer, pfiltermem);
    else
      S_Interpolate2xLinear_2(count, pbuffer, pfiltermem);
  }
  else
  {
    v5 = count - 1;
    if ( count - 1 >= 0 )
    {
      v6 = &pbuffer[2 * count - 1];
      v7 = &pbuffer[v5];
      do
      {
        v6->left = v7->left;
        v6->right = v7->right;
        v6[-1].left = v7->left;
        v6[-1].right = v7->right;
        v6 -= 2;
        --v7;
        --v5;
      }
      while ( v5 >= 0 );
    }
    if ( filtertype == 2 )
      S_Interpolate2xCubic(pbuffer, pfiltermem, cfltmem, count);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002F3C0
// Name: void MIX_MixPaintbuffers(int,int,int,int,float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MIX_MixPaintbuffers(
        int ibuf1,
        portable_samplepair_t *ibuf2,
        int ibuf3,
        portable_samplepair_t *count,
        float fgain_out)
{
  paintbuffer_t *v6; // edx
  portable_samplepair_t *pbuf; // ecx
  bool v8; // zf
  int v9; // edx
  portable_samplepair_t *v10; // esi
  portable_samplepair_t *v11; // eax
  portable_samplepair_t *pbufrear; // edi
  unsigned int v13; // edx
  portable_samplepair_t *v14; // edx
  portable_samplepair_t *v15; // edx
  char *v16; // ebx
  int *p_right; // edx
  portable_samplepair_t *v18; // edi
  int v19; // eax
  int v20; // ecx
  int v21; // ecx
  int i; // eax
  int *v23; // edx
  char *v24; // ebx
  char *v25; // edi
  portable_samplepair_t *v26; // eax
  int v27; // ecx
  char *v28; // ebx
  portable_samplepair_t *v29; // edi
  int v30; // ecx
  int *v31; // eax
  portable_samplepair_t *v32; // ebx
  int *v33; // edx
  int *p_left; // edi
  int v35; // eax
  int v36; // ecx
  int v37; // ebx
  portable_samplepair_t *v38; // edx
  int *v39; // eax
  int v40; // ebx
  portable_samplepair_t *v41; // edx
  int v42; // ecx
  int v43; // edi
  char *v44; // ebx
  portable_samplepair_t *v45; // eax
  int v46; // ebx
  int v47; // edi
  int v48; // ecx
  portable_samplepair_t *v49; // eax
  portable_samplepair_t *v50; // edx
  int v51; // ecx
  int v52; // ebx
  int v53; // edi
  int v54; // edi
  int v55; // ecx
  char *v56; // ebx
  char *v57; // eax
  int *v58; // ecx
  portable_samplepair_t *v59; // edx
  char *v60; // edi
  int v61; // eax
  int *v62; // edx
  portable_samplepair_t *v63; // ecx
  portable_samplepair_t *v64; // eax
  int v65; // ecx
  int v66; // edi
  int *v67; // edx
  char *v68; // ecx
  portable_samplepair_t *v69; // ebx
  int v70; // ecx
  int v71; // edi
  char *v72; // ebx
  portable_samplepair_t **v73; // edx
  portable_samplepair_t *v74; // ecx
  int left; // eax
  int v76; // edi
  portable_samplepair_t *v77; // ebx
  int v78; // edi
  int *v79; // edx
  int *v80; // ecx
  int v81; // eax
  int v82; // edi
  int v83; // ebx
  int v84; // edi
  portable_samplepair_t *v85; // eax
  int *v86; // edx
  int v87; // ecx
  int v88; // edi
  int v89; // ebx
  int v90; // ebx
  char *v91; // edi
  int v92; // edx
  int v93; // ecx
  int *v94; // eax
  int *v95; // edi
  char *v96; // eax
  int v97; // ebx
  char *v98; // eax
  int *v99; // ebx
  int v100; // edi
  int v101; // edx
  int *v102; // eax
  char *v103; // ebx
  portable_samplepair_t *v104; // eax
  int *v105; // ecx
  portable_samplepair_t *v106; // edi
  int v107; // ebx
  int v108; // eax
  char *v109; // ebx
  portable_samplepair_t *v110; // eax
  int v111; // ecx
  portable_samplepair_t *v112; // edi
  int v113; // eax
  int v114; // edx
  int v115; // edx
  portable_samplepair_t *v116; // ecx
  int v117; // edi
  int *v118; // eax
  int v119; // esi
  CMixData data; // [esp+4h] [ebp-60h] BYREF
  int *v121; // [esp+2Ch] [ebp-38h]
  portable_samplepair_t *pbufcentert; // [esp+30h] [ebp-34h]
  int gain_out; // [esp+34h] [ebp-30h]
  portable_samplepair_t *pbufrear1; // [esp+38h] [ebp-2Ch]
  int cchan3; // [esp+3Ch] [ebp-28h]
  portable_samplepair_t *pbufcenter3; // [esp+40h] [ebp-24h]
  int l2; // [esp+44h] [ebp-20h]
  portable_samplepair_t *pbufcenter1; // [esp+48h] [ebp-1Ch]
  char *v129; // [esp+4Ch] [ebp-18h]
  int v130; // [esp+50h] [ebp-14h]
  int *v131; // [esp+54h] [ebp-10h]
  char *v132; // [esp+58h] [ebp-Ch]
  int r2; // [esp+5Ch] [ebp-8h]
  char *v134; // [esp+60h] [ebp-4h]
  int savedregs; // [esp+64h] [ebp+0h] BYREF
  paintbuffer_t *cchan2q; // [esp+6Ch] [ebp+8h]
  unsigned int cchan2; // [esp+6Ch] [ebp+8h]
  int cchan2a; // [esp+6Ch] [ebp+8h]
  int cchan2b; // [esp+6Ch] [ebp+8h]
  int cchan2c; // [esp+6Ch] [ebp+8h]
  int cchan2d; // [esp+6Ch] [ebp+8h]
  portable_samplepair_t *cchan2e; // [esp+6Ch] [ebp+8h]
  int cchan2f; // [esp+6Ch] [ebp+8h]
  int cchan2g; // [esp+6Ch] [ebp+8h]
  int cchan2h; // [esp+6Ch] [ebp+8h]
  int cchan2i; // [esp+6Ch] [ebp+8h]
  int cchan2j; // [esp+6Ch] [ebp+8h]
  int cchan2k; // [esp+6Ch] [ebp+8h]
  int cchan2l; // [esp+6Ch] [ebp+8h]
  int cchan2m; // [esp+6Ch] [ebp+8h]
  int cchan2n; // [esp+6Ch] [ebp+8h]
  int cchan2o; // [esp+6Ch] [ebp+8h]
  int cchan2p; // [esp+6Ch] [ebp+8h]
  portable_samplepair_t *pbufcenter2; // [esp+70h] [ebp+Ch]
  portable_samplepair_t *pbufcenter2a; // [esp+70h] [ebp+Ch]
  portable_samplepair_t *pbufcenter2e; // [esp+70h] [ebp+Ch]
  portable_samplepair_t *pbufcenter2f; // [esp+70h] [ebp+Ch]
  portable_samplepair_t *pbufcenter2b; // [esp+70h] [ebp+Ch]
  portable_samplepair_t *pbufcenter2c; // [esp+70h] [ebp+Ch]
  portable_samplepair_t *pbufcenter2g; // [esp+70h] [ebp+Ch]
  portable_samplepair_t *pbufcenter2d; // [esp+70h] [ebp+Ch]
  portable_samplepair_t *pbufcenter2h; // [esp+70h] [ebp+Ch]
  portable_samplepair_t *pbufcenter2i; // [esp+70h] [ebp+Ch]
  portable_samplepair_t *pbufcenter2j; // [esp+70h] [ebp+Ch]
  unsigned int cchan1; // [esp+74h] [ebp+10h]
  int cchan1a; // [esp+74h] [ebp+10h]
  int cchan1b; // [esp+74h] [ebp+10h]
  int cchan1c; // [esp+74h] [ebp+10h]
  int cchan1d; // [esp+74h] [ebp+10h]
  int cchan1e; // [esp+74h] [ebp+10h]
  int cchan1f; // [esp+74h] [ebp+10h]
  int cchan1g; // [esp+74h] [ebp+10h]
  int cchan1h; // [esp+74h] [ebp+10h]
  int cchan1i; // [esp+74h] [ebp+10h]
  int cchan1j; // [esp+74h] [ebp+10h]
  int cchan1k; // [esp+74h] [ebp+10h]
  portable_samplepair_t *pbufrear3; // [esp+7Ch] [ebp+18h]
  portable_samplepair_t *pbufrear3a; // [esp+7Ch] [ebp+18h]
  portable_samplepair_t *pbufrear3b; // [esp+7Ch] [ebp+18h]
  portable_samplepair_t *pbufrear3c; // [esp+7Ch] [ebp+18h]
  portable_samplepair_t *pbufrear3d; // [esp+7Ch] [ebp+18h]
  portable_samplepair_t *pbufrear3e; // [esp+7Ch] [ebp+18h]
  portable_samplepair_t *pbufrear3f; // [esp+7Ch] [ebp+18h]

  v6 = &g_paintBuffers[ibuf1];
  pbuf = v6->pbuf;
  pbufrear1 = v6->pbufrear;
  cchan3 = (int)&g_paintBuffers[ibuf3];
  pbufrear3 = *(portable_samplepair_t **)(cchan3 + 12);
  pbufcenter1 = v6->pbufcenter;
  cchan2q = &g_paintBuffers[(_DWORD)ibuf2];
  pbufcenter2 = cchan2q->pbufcenter;
  pbufcenter3 = *(portable_samplepair_t **)(cchan3 + 16);
  v8 = !v6->fsurround_center;
  v9 = v6->fsurround ? 2 : 0;
  v10 = *(portable_samplepair_t **)(cchan3 + 8);
  gain_out = (int)(float)(fgain_out * 256.0);
  v11 = cchan2q->pbuf;
  cchan1 = !v8 + v9 + 2;
  pbufrear = cchan2q->pbufrear;
  cchan2 = cchan2q->fsurround_center + (cchan2q->fsurround ? 2 : 0) + 2;
  cchan3 = (*(_BYTE *)(cchan3 + 2) != 0) + (*(_BYTE *)(cchan3 + 1) != 0 ? 2 : 0) + 2;
  v13 = cchan1;
  if ( cchan2 >= cchan1 )
  {
    v15 = pbufrear1;
  }
  else
  {
    cchan1 = cchan2;
    pbufcentert = pbufcenter1;
    cchan2 = v13;
    v14 = pbuf;
    pbuf = v11;
    pbufcenter1 = pbufcenter2;
    v11 = v14;
    v15 = pbufrear;
    pbufrear = pbufrear1;
    pbufcenter2 = pbufcentert;
  }
  data.count = (int)count;
  data.pbufcenter1 = pbufcenter1;
  data.pbufcenter2 = pbufcenter2;
  data.pbufcenter3 = pbufcenter3;
  data.pbufrear3 = pbufrear3;
  data.pbuf1 = pbuf;
  data.pbuf2 = v11;
  data.pbuf3 = v10;
  data.pbufrear1 = v15;
  data.pbufrear2 = pbufrear;
  if ( cchan3 == 2 )
  {
    if ( cchan1 == 2 )
    {
      if ( cchan2 == 2 )
      {
        if ( (int)count > 0 )
        {
          cchan2a = (char *)v11 - (char *)pbuf;
          v16 = (char *)((char *)v10 - (char *)pbuf);
          p_right = &pbuf->right;
          v18 = v10;
          v19 = (char *)v11 - (char *)v10;
          pbufrear3a = count;
          do
          {
            v20 = *(p_right - 1) + *(int *)((char *)&v18->left + v19);
            p_right += 2;
            v18->left = v20;
            ++v18;
            v8 = pbufrear3a == (portable_samplepair_t *)1;
            pbufrear3a = (portable_samplepair_t *)((char *)pbufrear3a - 1);
            *(int *)((char *)p_right + (_DWORD)v16 - 8) = *(p_right - 2) + *(int *)((char *)p_right + cchan2a - 8);
          }
          while ( !v8 );
        }
      }
      else if ( cchan2 == 4 )
      {
        if ( (int)count > 0 )
        {
          cchan1a = (char *)pbufrear - (char *)v11;
          cchan2b = (char *)pbuf - (char *)v11;
          v23 = &v11->right;
          v24 = (char *)((char *)v10 - (char *)v11);
          v25 = (char *)((char *)pbufrear - (char *)pbuf);
          v134 = (char *)((char *)v10 - (char *)pbuf);
          pbufrear3b = count;
          v132 = v25;
          v26 = pbuf;
          while ( 1 )
          {
            v27 = *(v23 - 1) + *(int *)((char *)&v26->left + (_DWORD)v25);
            v23 += 2;
            *(_DWORD *)&v134[(_DWORD)v26] = v26->left + (v27 >> 1);
            ++v26;
            v8 = pbufrear3b == (portable_samplepair_t *)1;
            pbufrear3b = (portable_samplepair_t *)((char *)pbufrear3b - 1);
            *(int *)((char *)v23 + (_DWORD)v24 - 8) = *(int *)((char *)v23 + cchan2b - 8)
                                                    + ((*(v23 - 2) + *(int *)((char *)v23 + cchan1a - 8)) >> 1);
            if ( v8 )
              break;
            v25 = v132;
          }
        }
      }
      else if ( cchan2 == 5 && (int)count > 0 )
      {
        cchan2d = (char *)v11 - (char *)pbufrear;
        pbufcentert = (portable_samplepair_t *)((char *)pbuf - (char *)pbufrear);
        pbufrear1 = (portable_samplepair_t *)((char *)v10 - (char *)pbufrear);
        pbufrear3d = (portable_samplepair_t *)((char *)pbuf - (char *)pbufcenter2);
        v32 = (portable_samplepair_t *)((char *)v11 - (char *)pbufcenter2);
        v33 = &pbufrear->right;
        p_left = &pbufcenter2->left;
        pbufcenter1 = (portable_samplepair_t *)((char *)v11 - (char *)pbufcenter2);
        v129 = (char *)((char *)v10 - (char *)pbufcenter2);
        pbufcenter2a = count;
        while ( 1 )
        {
          v35 = *p_left >> 1;
          v36 = v35 + *(int *)((char *)v33 + cchan2d);
          *(int *)((char *)p_left + (_DWORD)v129) = *(int *)((char *)p_left + (_DWORD)pbufrear3d)
                                                  + ((v35 + *(v33 - 1) + *(int *)((char *)p_left + (_DWORD)v32)) >> 1);
          *(int *)((char *)v33 + (_DWORD)pbufrear1) = *(int *)((char *)v33 + (_DWORD)pbufcentert) + ((v36 + *v33) >> 1);
          p_left += 2;
          v33 += 2;
          pbufcenter2a = (portable_samplepair_t *)((char *)pbufcenter2a - 1);
          if ( pbufcenter2a == nullptr )
            break;
          v32 = pbufcenter1;
        }
      }
    }
    else if ( cchan1 == 4 )
    {
      if ( cchan2 == 4 )
      {
        if ( (int)count > 0 )
        {
          pbufcentert = (portable_samplepair_t *)&v11->right;
          cchan1b = (char *)pbufrear - (char *)v11;
          v134 = (char *)((char *)v15 - (char *)v11);
          cchan2c = (char *)pbuf - (char *)v11;
          v28 = (char *)((char *)v10 - (char *)v11);
          v29 = (portable_samplepair_t *)((char *)pbufrear - (char *)v15);
          v30 = (char *)pbuf - (char *)v15;
          l2 = (char *)v10 - (char *)v15;
          v31 = &v11->right;
          pbufrear3c = count;
          pbufcenter3 = v29;
          cchan3 = v30;
          while ( 1 )
          {
            *(int *)((char *)&v15->left + l2) = ((v15->left + *(int *)((char *)&v15->left + v30)) >> 1)
                                              + ((*(v31 - 1) + *(int *)((char *)&v15->left + (_DWORD)v29)) >> 1);
            *(_DWORD *)&v28[(_DWORD)v31] = ((*v31 + *(int *)((char *)v31 + cchan1b)) >> 1)
                                         + ((*(int *)((char *)v31 + cchan2c) + *(int *)((char *)v31 + (_DWORD)v134)) >> 1);
            v31 += 2;
            ++v15;
            pbufrear3c = (portable_samplepair_t *)((char *)pbufrear3c - 1);
            if ( pbufrear3c == nullptr )
              break;
            v30 = cchan3;
            v29 = pbufcenter3;
          }
        }
      }
      else if ( cchan2 == 5 && (int)count > 0 )
      {
        pbufcentert = (portable_samplepair_t *)&v15->right;
        pbufrear1 = (portable_samplepair_t *)((char *)v11 - (char *)v15);
        cchan3 = (char *)pbuf - (char *)v15;
        pbufcenter3 = (portable_samplepair_t *)((char *)pbufrear - (char *)v15);
        v37 = (char *)v10 - (char *)v15;
        v38 = v11;
        v39 = &pbufcenter2->left;
        l2 = v37;
        pbufrear3e = (portable_samplepair_t *)((char *)pbuf - (char *)pbufcenter2);
        pbufcenter1 = (portable_samplepair_t *)((char *)v38 - (char *)pbufcenter2);
        v40 = (char *)pbufrear - (char *)pbufcenter2;
        cchan2e = count;
        v41 = pbufcentert;
        v129 = (char *)((char *)v10 - (char *)pbufcenter2);
        do
        {
          v42 = *v39 >> 1;
          pbufcenter2e = (portable_samplepair_t *)(v42 + *(int *)((char *)&v41->left + (_DWORD)pbufrear1));
          v43 = *(int *)((char *)v39 + v40) + *(int *)((char *)v39 + (_DWORD)pbufcenter1);
          v39 += 2;
          *(int *)((char *)v39 + (_DWORD)v129 - 8) = ((v41[-1].right + *(int *)((char *)v39 + (_DWORD)pbufrear3e - 8)) >> 1)
                                                   + ((v42 + v43) >> 1);
          *(int *)((char *)&v41->left + l2) = (((int)pbufcenter2e + *(int *)((char *)&v41->left + (_DWORD)pbufcenter3)) >> 1)
                                            + ((v41->left + *(int *)((char *)&v41->left + cchan3)) >> 1);
          ++v41;
          cchan2e = (portable_samplepair_t *)((char *)cchan2e - 1);
        }
        while ( cchan2e != nullptr );
      }
    }
    else if ( cchan1 == 5 && cchan2 == 5 && (int)count > 0 )
    {
      pbufcentert = pbufcenter1;
      pbufrear1 = (portable_samplepair_t *)&v11->right;
      cchan2f = (char *)pbuf - (char *)v11;
      cchan1c = (char *)pbufrear - (char *)v11;
      v134 = (char *)((char *)v15 - (char *)v11);
      v44 = (char *)((char *)v10 - (char *)v11);
      v45 = pbufcenter1;
      v132 = v44;
      pbufcenter3 = (portable_samplepair_t *)((char *)pbuf - (char *)pbufcenter1);
      v46 = (char *)pbufcenter2 - (char *)pbufcenter1;
      v47 = (char *)pbufrear - (char *)pbufcenter1;
      pbufcenter1 = (portable_samplepair_t *)((char *)v15 - (char *)pbufcenter1);
      v48 = (char *)v10 - (char *)v45;
      v49 = pbufrear1;
      pbufrear3f = count;
      v50 = pbufcentert;
      cchan3 = v46;
      v130 = v47;
      l2 = v48;
      while ( 1 )
      {
        v51 = v50->left >> 1;
        pbufcenter2f = (portable_samplepair_t *)(v51 + *(int *)((char *)&v49->left + cchan2f));
        v52 = *(int *)((char *)&v50->left + v46) >> 1;
        r2 = v52 + v49->left;
        v53 = *(int *)((char *)&v50->left + (_DWORD)pbufcenter1);
        pbufcentert = (portable_samplepair_t *)v52;
        ++v49;
        v54 = v51 + *(int *)((char *)&v50->left + (_DWORD)pbufcenter3) + v53;
        v55 = v52 + v49[-2].right + *(int *)((char *)&v50->left + v130);
        ++v50;
        *(int *)((char *)&v50[-1].left + l2) = (v55 >> 1) + (v54 >> 1);
        v8 = pbufrear3f == (portable_samplepair_t *)1;
        pbufrear3f = (portable_samplepair_t *)((char *)pbufrear3f - 1);
        *(int *)((char *)&v49[-1].left + (_DWORD)v132) = ((r2 + *(int *)((char *)&v49[-1].left + cchan1c)) >> 1)
                                                       + (((int)pbufcenter2f
                                                         + *(int *)((char *)&v49[-1].left + (_DWORD)v134)) >> 1);
        if ( v8 )
          break;
        v46 = cchan3;
      }
    }
    goto gain2ch;
  }
  if ( cchan3 == 4 )
  {
    if ( cchan1 == 4 )
    {
      if ( cchan2 == 4 )
      {
        if ( (int)count > 0 )
        {
          pbufcentert = (portable_samplepair_t *)&pbuf->right;
          cchan2g = (char *)v11 - (char *)pbuf;
          v134 = (char *)((char *)v10 - (char *)pbuf);
          v132 = (char *)((char *)pbufrear - (char *)pbuf);
          l2 = (char *)v15 - (char *)pbuf;
          v56 = (char *)((char *)pbufrear3 - (char *)pbuf);
          v57 = (char *)((char *)v11 - (char *)v10);
          cchan3 = (char *)v15 - (char *)v10;
          v130 = (char *)pbufrear3 - (char *)v10;
          v58 = &pbuf->right;
          pbufcenter2b = count;
          v129 = v57;
          v131 = (int *)((char *)pbufrear - (char *)v10);
          v59 = v10;
          while ( 1 )
          {
            v60 = v134;
            v59->left = *(v58 - 1) + *(_DWORD *)&v57[(_DWORD)v59];
            v61 = *v58 + *(int *)((char *)v58 + cchan2g);
            v58 += 2;
            *(_DWORD *)&v60[(_DWORD)v58 - 8] = v61;
            *(int *)((char *)&v59->left + v130) = *(int *)((char *)&v59->left + (_DWORD)v131)
                                                + *(int *)((char *)&v59->left + cchan3);
            ++v59;
            v8 = pbufcenter2b == (portable_samplepair_t *)1;
            pbufcenter2b = (portable_samplepair_t *)((char *)pbufcenter2b - 1);
            *(int *)((char *)v58 + (_DWORD)v56 - 8) = *(int *)((char *)v58 + l2 - 8) + *(_DWORD *)&v132[(_DWORD)v58 - 8];
            if ( v8 )
              break;
            v57 = v129;
          }
        }
gain4ch:
        v92 = gain_out;
        if ( gain_out != 256 )
        {
          v93 = 0;
          if ( (int)count > 0 )
          {
            v94 = &pbufrear3->right;
            do
            {
              v10[v93].left = (v92 * v10[v93].left) >> 8;
              *(int *)((char *)v94 + (char *)v10 - (char *)pbufrear3) = (v92
                                                                       * *(int *)((char *)v94
                                                                                + (char *)v10
                                                                                - (char *)pbufrear3)) >> 8;
              *(v94 - 1) = (v92 * *(v94 - 1)) >> 8;
              *v94 = (v92 * *v94) >> 8;
              ++v93;
              v94 += 2;
            }
            while ( v93 < (int)count );
          }
        }
        return;
      }
      if ( cchan2 == 5 )
      {
        if ( (int)count > 0 )
        {
          pbufcentert = pbufcenter2;
          pbufrear1 = (portable_samplepair_t *)&pbuf->right;
          cchan2k = (char *)v11 - (char *)pbuf;
          v134 = (char *)((char *)v10 - (char *)pbuf);
          v132 = (char *)((char *)pbufrear - (char *)pbuf);
          l2 = (char *)v15 - (char *)pbuf;
          cchan1f = (char *)pbufrear3 - (char *)pbuf;
          v129 = (char *)((char *)v10 - (char *)pbufcenter2);
          v77 = (portable_samplepair_t *)((char *)v11 - (char *)pbufcenter2);
          v78 = (char *)pbufrear - (char *)pbufcenter2;
          pbufcenter3 = (portable_samplepair_t *)((char *)pbufrear3 - (char *)pbufcenter2);
          v130 = (char *)v15 - (char *)pbufcenter2;
          v79 = &pbufcenter2->left;
          pbufcenter2d = count;
          v80 = &pbuf->right;
          pbufcenter1 = v77;
          cchan3 = v78;
          while ( 1 )
          {
            v81 = *v79 >> 1;
            v82 = v81 + *(int *)((char *)v80 + cchan2k);
            *(int *)((char *)v79 + (_DWORD)v129) = v81 + *(v80 - 1) + *(int *)((char *)v79 + (_DWORD)v77);
            *(int *)((char *)v80 + (_DWORD)v134) = v82 + *v80;
            *(int *)((char *)&pbufcenter3->left + (_DWORD)v79) = *(int *)((char *)v79 + cchan3)
                                                               + *(int *)((char *)v79 + v130);
            *(int *)((char *)v80 + cchan1f) = *(int *)((char *)v80 + l2) + *(int *)((char *)v80 + (_DWORD)v132);
            v79 += 2;
            v80 += 2;
            pbufcenter2d = (portable_samplepair_t *)((char *)pbufcenter2d - 1);
            if ( pbufcenter2d == nullptr )
              break;
            v77 = pbufcenter1;
          }
        }
        goto gain4ch;
      }
    }
    else if ( cchan1 == 2 )
    {
      switch ( cchan2 )
      {
        case 4u:
          if ( (int)count > 0 )
          {
            cchan2h = (char *)pbuf - (char *)v11;
            v132 = (char *)((char *)v10 - (char *)v11);
            cchan1d = (char *)pbufrear - (char *)v11;
            v62 = &v11->right;
            v63 = (portable_samplepair_t *)((char *)pbuf - (char *)v10);
            v130 = (char *)pbufrear3 - (char *)v10;
            pbufrear1 = count;
            v129 = (char *)((char *)pbufrear3 - (char *)v11);
            pbufcenter1 = v63;
            v131 = (int *)((char *)pbufrear - (char *)v10);
            v64 = v10;
            while ( 1 )
            {
              v65 = *(int *)((char *)&v64->left + (_DWORD)v63);
              v66 = *(int *)((char *)v62 + cchan2h);
              v64->left = v65 + *(v62 - 1);
              *(int *)((char *)v62 + (_DWORD)v132) = v66 + *v62;
              *(int *)((char *)&v64->left + v130) = v65 + *(int *)((char *)&v64->left + (_DWORD)v131);
              *(int *)((char *)v62 + (_DWORD)v129) = v66 + *(int *)((char *)v62 + cchan1d);
              v62 += 2;
              ++v64;
              pbufrear1 = (portable_samplepair_t *)((char *)pbufrear1 - 1);
              if ( pbufrear1 == nullptr )
                break;
              v63 = pbufcenter1;
            }
          }
          goto gain4ch;
        case 2u:
          if ( (int)count > 0 )
          {
            cchan2i = (char *)v11 - (char *)pbuf;
            v134 = (char *)((char *)v10 - (char *)pbuf);
            v67 = &pbuf->right;
            cchan1e = (char *)pbufrear3 - (char *)pbuf;
            v68 = (char *)((char *)v11 - (char *)v10);
            v69 = v10;
            v129 = (char *)((char *)v11 - (char *)v10);
            pbufcenter2c = count;
            while ( 1 )
            {
              v70 = *(v67 - 1) + *(_DWORD *)&v68[(_DWORD)v69];
              v71 = *v67 + *(int *)((char *)v67 + cchan2i);
              v69->left = v70;
              *(int *)((char *)&v69->left + (char *)pbufrear3 - (char *)v10) = v70;
              *(_DWORD *)&v134[(_DWORD)v67] = v71;
              *(int *)((char *)v67 + cchan1e) = v71;
              v67 += 2;
              ++v69;
              pbufcenter2c = (portable_samplepair_t *)((char *)pbufcenter2c - 1);
              if ( pbufcenter2c == nullptr )
                break;
              v68 = v129;
            }
          }
          goto gain4ch;
        case 5u:
          if ( (int)count > 0 )
          {
            cchan2j = (char *)v11 - (char *)pbuf;
            v134 = (char *)((char *)v10 - (char *)pbuf);
            v132 = (char *)((char *)pbufrear - (char *)pbuf);
            v72 = (char *)((char *)pbufrear3 - (char *)pbuf);
            v73 = (portable_samplepair_t **)&pbuf->right;
            v74 = pbufcenter2;
            pbufcenter1 = (portable_samplepair_t *)((char *)v11 - (char *)pbufcenter2);
            v129 = (char *)((char *)v10 - (char *)pbufcenter2);
            pbufcenter3 = (portable_samplepair_t *)((char *)pbufrear3 - (char *)pbufcenter2);
            cchan3 = (char *)pbufrear - (char *)pbufcenter2;
            for ( l2 = (int)count; l2 != 0; --l2 )
            {
              left = v74->left;
              v76 = *(int *)((char *)v73 + cchan2j);
              pbufrear1 = *(v73 - 1);
              pbufcenter2g = *v73;
              left >>= 1;
              *(int *)((char *)&v74->left + (_DWORD)v129) = (int)pbufrear1
                                                          + left
                                                          + *(int *)((char *)&v74->left + (_DWORD)pbufcenter1);
              *(_DWORD *)&v134[(_DWORD)v73] = (char *)pbufcenter2g + left + v76;
              *(int *)((char *)&pbufcenter3->left + (_DWORD)v74) = (int)pbufrear1
                                                                 + *(int *)((char *)&v74->left + cchan3);
              *(char **)((char *)v73 + (_DWORD)v72) = (char *)pbufcenter2g + *(_DWORD *)&v132[(_DWORD)v73];
              v73 += 2;
              ++v74;
            }
          }
          goto gain4ch;
        default:
          break;
      }
    }
    else if ( cchan1 == 5 && cchan2 == 5 )
    {
      if ( (int)count > 0 )
      {
        pbufcentert = pbufcenter1;
        v131 = &v11->right;
        cchan2l = (char *)pbuf - (char *)v11;
        v132 = (char *)((char *)v10 - (char *)v11);
        cchan1g = (char *)pbufrear - (char *)v11;
        v134 = (char *)((char *)v15 - (char *)v11);
        pbufcenter3 = (portable_samplepair_t *)((char *)pbuf - (char *)pbufcenter1);
        v129 = (char *)((char *)pbufrear3 - (char *)v11);
        l2 = (char *)v10 - (char *)pbufcenter1;
        v83 = (char *)pbufcenter2 - (char *)pbufcenter1;
        v84 = (char *)pbufrear - (char *)pbufcenter1;
        v85 = pbufcenter1;
        v121 = (int *)((char *)pbufrear3 - (char *)pbufcenter1);
        pbufcenter1 = (portable_samplepair_t *)((char *)v15 - (char *)pbufcenter1);
        v86 = v131;
        cchan3 = v83;
        v130 = v84;
        pbufrear1 = count;
        while ( 1 )
        {
          v87 = v85->left >> 1;
          pbufcenter2h = (portable_samplepair_t *)(v87 + *(int *)((char *)v86 + cchan2l));
          v88 = *(int *)((char *)&v85->left + v83) >> 1;
          r2 = v88 + *v86;
          v89 = *(v86 - 1) + *(int *)((char *)&pbufcenter3->left + (_DWORD)v85++);
          v90 = v88 + v87 + v89;
          v91 = (char *)pbufcenter2h + r2;
          *(int *)((char *)&v85[-1].left + l2) = v90;
          *(_DWORD *)&v132[(_DWORD)v86] = v91;
          *(int *)((char *)&v85[-1].left + (_DWORD)v121) = *(int *)((char *)&v85[-1].left + v130)
                                                         + *(int *)((char *)&pbufcenter1[-1].left + (_DWORD)v85);
          *(_DWORD *)&v129[(_DWORD)v86] = *(_DWORD *)&v134[(_DWORD)v86] + *(int *)((char *)v86 + cchan1g);
          v86 += 2;
          pbufrear1 = (portable_samplepair_t *)((char *)pbufrear1 - 1);
          if ( pbufrear1 == nullptr )
            break;
          v83 = cchan3;
        }
      }
      goto gain4ch;
    }
gain2ch:
    v21 = gain_out;
    if ( gain_out != 256 )
    {
      for ( i = 0; i < (int)count; ++i )
      {
        v10[i].left = (v21 * v10[i].left) >> 8;
        v10[i].right = (v21 * v10[i].right) >> 8;
      }
    }
    return;
  }
  if ( cchan3 != 5 )
    goto gain2ch;
  if ( cchan1 == 2 )
  {
    switch ( cchan2 )
    {
      case 2u:
        if ( (int)count > 0 )
        {
          v132 = (char *)((char *)v10 - (char *)v11);
          cchan2m = (char *)pbuf - (char *)v11;
          v129 = (char *)((char *)pbufrear3 - (char *)v11);
          v95 = &v11->right;
          cchan1h = (char *)pbufrear3 - (char *)pbuf;
          v96 = (char *)((char *)v10 - (char *)pbuf);
          cchan3 = (char *)pbufcenter3 - (char *)pbuf;
          v134 = (char *)((char *)v10 - (char *)pbuf);
          pbufrear1 = count;
          while ( 1 )
          {
            v97 = pbuf->left;
            pbufcenter2i = *(portable_samplepair_t **)((char *)v95 + cchan2m);
            l2 = *(v95 - 1);
            r2 = *v95;
            *(_DWORD *)&v96[(_DWORD)pbuf] = v97 + l2;
            *(int *)((char *)v95 + (_DWORD)v132) = (int)pbufcenter2i + r2;
            *(int *)((char *)&pbuf->left + cchan1h) = pbuf->left + *(v95 - 1);
            *(_DWORD *)&v129[(_DWORD)v95] = *(int *)((char *)v95 + cchan2m) + *v95;
            v95 += 2;
            *(int *)((char *)&pbuf->left + cchan3) = ((int)pbufcenter2i + v97) / 2 + (l2 + r2) / 2;
            ++pbuf;
            pbufrear1 = (portable_samplepair_t *)((char *)pbufrear1 - 1);
            if ( pbufrear1 == nullptr )
              break;
            v96 = v134;
          }
        }
        break;
      case 4u:
        if ( (int)count > 0 )
        {
          v129 = (char *)((char *)v11 - (char *)v10);
          v131 = (int *)((char *)pbufrear - (char *)v10);
          pbufcenter1 = (portable_samplepair_t *)((char *)pbuf - (char *)v10);
          v130 = (char *)pbufrear3 - (char *)v10;
          cchan2n = (char *)v11 - (char *)pbufrear;
          cchan1i = (char *)pbufrear3 - (char *)pbuf;
          v98 = (char *)((char *)pbufrear - (char *)pbuf);
          pbufrear1 = count;
          v99 = &v10->right;
          v132 = (char *)((char *)pbufrear - (char *)pbuf);
          cchan3 = (char *)pbufcenter3 - (char *)pbuf;
          while ( 1 )
          {
            v100 = pbuf->left;
            pbufcenter2j = *(portable_samplepair_t **)((char *)&pbufcenter1->left + (_DWORD)v99);
            v121 = (int *)&v98[(_DWORD)pbuf];
            v101 = *(_DWORD *)&v129[(_DWORD)v99];
            l2 = *(_DWORD *)&v98[(_DWORD)pbuf + cchan2n];
            *(v99 - 1) = v100 + l2;
            v102 = v121;
            r2 = v101;
            v99 += 2;
            *(v99 - 2) = (int)pbufcenter2j + v101;
            *(int *)((char *)&pbuf->left + cchan1i) = *v102 + pbuf->left;
            *(int *)((char *)v99 + v130 - 8) = *(int *)((char *)&pbufcenter1[-1].left + (_DWORD)v99)
                                             + *(int *)((char *)v99 + (_DWORD)v131 - 8);
            ++pbuf;
            v8 = pbufrear1 == (portable_samplepair_t *)1;
            pbufrear1 = (portable_samplepair_t *)((char *)pbufrear1 - 1);
            *(int *)((char *)&pbuf[-1].left + cchan3) = ((int)pbufcenter2j + v100) / 2 + (l2 + r2) / 2;
            if ( v8 )
              break;
            v98 = v132;
          }
        }
        break;
      case 5u:
        if ( snd_mix_optimization.m_pParent != nullptr && snd_mix_optimization.m_pParent->m_Value.m_nValue != 0 )
          Mix255_SIMD(a1: (__m128i *)&savedregs, &data);
        else
          Mix255(&data);
        break;
      default:
        goto gain2ch;
    }
  }
  else if ( cchan1 == 4 )
  {
    if ( cchan2 == 4 )
    {
      if ( (int)count > 0 )
      {
        v121 = &v11->right;
        cchan2o = (char *)pbuf - (char *)v11;
        v132 = (char *)((char *)v10 - (char *)v11);
        cchan1j = (char *)pbufrear - (char *)v11;
        v134 = (char *)((char *)v15 - (char *)v11);
        v103 = (char *)((char *)pbufrear3 - (char *)v11);
        v130 = (char *)pbufrear3 - (char *)v10;
        v104 = (portable_samplepair_t *)((char *)pbuf - (char *)v10);
        pbufrear1 = (portable_samplepair_t *)((char *)pbufcenter3 - (char *)v10);
        v131 = (int *)((char *)pbufrear - (char *)v10);
        pbufcentert = count;
        v105 = v121;
        v129 = v103;
        pbufcenter1 = v104;
        cchan3 = (char *)v15 - (char *)v10;
        v106 = v10;
        while ( 1 )
        {
          v107 = *(int *)((char *)&v106->left + (_DWORD)v104);
          v108 = *(int *)((char *)v105 + cchan2o);
          l2 = *(v105 - 1);
          r2 = *v105;
          v106->left = v107 + l2;
          *(int *)((char *)v105 + (_DWORD)v132) = v108 + r2;
          *(int *)((char *)&v106->left + v130) = *(int *)((char *)&v106->left + (_DWORD)v131)
                                               + *(int *)((char *)&v106->left + cchan3);
          *(int *)((char *)v105 + (_DWORD)v129) = *(int *)((char *)v105 + cchan1j)
                                                + *(int *)((char *)v105 + (_DWORD)v134);
          v105 += 2;
          *(int *)((char *)&v106->left + (_DWORD)pbufrear1) = (v108 + v107) / 2 + (r2 + l2) / 2;
          ++v106;
          pbufcentert = (portable_samplepair_t *)((char *)pbufcentert - 1);
          if ( pbufcentert == nullptr )
            break;
          v104 = pbufcenter1;
        }
      }
    }
    else
    {
      if ( cchan2 != 5 )
        goto gain2ch;
      if ( (int)count > 0 )
      {
        l2 = (int)&v11->right;
        cchan2p = (char *)pbuf - (char *)v11;
        v132 = (char *)((char *)v10 - (char *)v11);
        cchan1k = (char *)pbufrear - (char *)v11;
        v134 = (char *)((char *)v15 - (char *)v11);
        v109 = (char *)((char *)pbufrear3 - (char *)v11);
        v130 = (char *)pbufrear3 - (char *)v10;
        r2 = (char *)pbufcenter2 - (char *)v10;
        v110 = (portable_samplepair_t *)((char *)pbuf - (char *)v10);
        pbufrear1 = (portable_samplepair_t *)((char *)pbufcenter3 - (char *)v10);
        v131 = (int *)((char *)pbufrear - (char *)v10);
        pbufcentert = count;
        v111 = l2;
        v129 = v109;
        pbufcenter1 = v110;
        cchan3 = (char *)v15 - (char *)v10;
        v112 = v10;
        while ( 1 )
        {
          v113 = *(int *)((char *)&v110->left + (_DWORD)v112);
          v114 = *(_DWORD *)(v111 + cchan2p);
          v112->left = v113 + *(_DWORD *)(v111 - 4);
          *(_DWORD *)&v132[v111] = v114 + *(_DWORD *)v111;
          *(int *)((char *)&v112->left + v130) = *(int *)((char *)&v112->left + (_DWORD)v131)
                                               + *(int *)((char *)&v112->left + cchan3);
          *(_DWORD *)&v129[v111] = *(_DWORD *)(v111 + cchan1k) + *(_DWORD *)&v134[v111];
          *(int *)((char *)&pbufrear1->left + (_DWORD)v112) = *(int *)((char *)&v112->left + r2) + (v114 + v113) / 2;
          v111 += 8;
          ++v112;
          pbufcentert = (portable_samplepair_t *)((char *)pbufcentert - 1);
          if ( pbufcentert == nullptr )
            break;
          v110 = pbufcenter1;
        }
      }
    }
  }
  else
  {
    if ( cchan2 != 5 || cchan1 != 5 )
      goto gain2ch;
    if ( snd_mix_optimization.m_pParent != nullptr && snd_mix_optimization.m_pParent->m_Value.m_nValue != 0 )
      Mix555_SIMD((__m128i *)&data);
    else
      Mix555(&data);
  }
  v115 = gain_out;
  if ( gain_out != 256 && (int)count > 0 )
  {
    v116 = pbufcenter3;
    v117 = (char *)v10 - (char *)pbufrear3;
    v118 = &pbufrear3->right;
    v119 = (char *)v10 - (char *)pbufcenter3;
    do
    {
      *(int *)((char *)&v116->left + v119) = (v115 * *(int *)((char *)&v116->left + v119)) >> 8;
      *(int *)((char *)v118 + v117) = (v115 * *(int *)((char *)v118 + v117)) >> 8;
      *(v118 - 1) = (v115 * *(v118 - 1)) >> 8;
      *v118 = (v115 * *v118) >> 8;
      v116->left = (v115 * v116->left) >> 8;
      v118 += 2;
      ++v116;
      count = (portable_samplepair_t *)((char *)count - 1);
    }
    while ( count != nullptr );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10030270
// Name: void ClipStereo(struct portable_samplepair_t __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ClipStereo(portable_samplepair_t *pBuffer, unsigned int nCount)
{
  int v2; // esi
  unsigned int v3; // edx
  portable_samplepair_t *v4; // eax
  int left; // ecx
  int right; // ecx
  int v7; // ecx
  int v8; // ecx
  int v9; // ecx
  int v10; // ecx
  int v11; // ecx
  int v12; // ecx
  int v13; // ecx
  int v14; // ecx

  v2 = nCount;
  if ( (int)nCount < 4 )
  {
    v4 = pBuffer;
  }
  else
  {
    v3 = nCount >> 2;
    v2 = nCount - 4 * (nCount >> 2);
    v4 = pBuffer;
    do
    {
      left = v4->left;
      if ( v4->left >= -32767 )
      {
        if ( left > 0x7FFF )
          left = 0x7FFF;
      }
      else
      {
        left = -32767;
      }
      v4->left = left;
      right = v4->right;
      if ( right >= -32767 )
      {
        if ( right > 0x7FFF )
          right = 0x7FFF;
      }
      else
      {
        right = -32767;
      }
      v4->right = right;
      v7 = v4[1].left;
      if ( v7 >= -32767 )
      {
        if ( v7 > 0x7FFF )
          v7 = 0x7FFF;
      }
      else
      {
        v7 = -32767;
      }
      v4[1].left = v7;
      v8 = v4[1].right;
      if ( v8 >= -32767 )
      {
        if ( v8 > 0x7FFF )
          v8 = 0x7FFF;
      }
      else
      {
        v8 = -32767;
      }
      v4[1].right = v8;
      v9 = v4[2].left;
      if ( v9 >= -32767 )
      {
        if ( v9 > 0x7FFF )
          v9 = 0x7FFF;
      }
      else
      {
        v9 = -32767;
      }
      v4[2].left = v9;
      v10 = v4[2].right;
      if ( v10 >= -32767 )
      {
        if ( v10 > 0x7FFF )
          v10 = 0x7FFF;
      }
      else
      {
        v10 = -32767;
      }
      v4[2].right = v10;
      v11 = v4[3].left;
      if ( v11 >= -32767 )
      {
        if ( v11 > 0x7FFF )
          v11 = 0x7FFF;
      }
      else
      {
        v11 = -32767;
      }
      v4[3].left = v11;
      v12 = v4[3].right;
      if ( v12 >= -32767 )
      {
        if ( v12 > 0x7FFF )
          v12 = 0x7FFF;
      }
      else
      {
        v12 = -32767;
      }
      v4[3].right = v12;
      v4 += 4;
      --v3;
    }
    while ( v3 != 0 );
  }
  for ( ; v2 > 0; ++v4 )
  {
    v13 = v4->left;
    if ( v4->left >= -32767 )
    {
      if ( v13 > 0x7FFF )
        v13 = 0x7FFF;
    }
    else
    {
      v13 = -32767;
    }
    v4->left = v13;
    v14 = v4->right;
    if ( v14 >= -32767 )
    {
      if ( v14 > 0x7FFF )
        v14 = 0x7FFF;
    }
    else
    {
      v14 = -32767;
    }
    v4->right = v14;
    --v2;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10030400
// Name: void ClipLeft(struct portable_samplepair_t __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ClipLeft(portable_samplepair_t *pBuffer, unsigned int nCount)
{
  int v2; // edx
  unsigned int v3; // esi
  portable_samplepair_t *v4; // eax
  int left; // ecx
  int v6; // ecx
  int v7; // ecx
  int v8; // ecx
  int v9; // ecx
  int v10; // ecx
  int v11; // ecx
  int v12; // ecx
  int v13; // ecx

  v2 = nCount;
  if ( (int)nCount < 8 )
  {
    v4 = pBuffer;
  }
  else
  {
    v3 = nCount >> 3;
    v2 = nCount - 8 * (nCount >> 3);
    v4 = pBuffer;
    do
    {
      left = v4->left;
      if ( v4->left >= -32767 )
      {
        if ( left > 0x7FFF )
          left = 0x7FFF;
      }
      else
      {
        left = -32767;
      }
      v4->left = left;
      v6 = v4[1].left;
      if ( v6 >= -32767 )
      {
        if ( v6 > 0x7FFF )
          v6 = 0x7FFF;
      }
      else
      {
        v6 = -32767;
      }
      v4[1].left = v6;
      v7 = v4[2].left;
      if ( v7 >= -32767 )
      {
        if ( v7 > 0x7FFF )
          v7 = 0x7FFF;
      }
      else
      {
        v7 = -32767;
      }
      v4[2].left = v7;
      v8 = v4[3].left;
      if ( v8 >= -32767 )
      {
        if ( v8 > 0x7FFF )
          v8 = 0x7FFF;
      }
      else
      {
        v8 = -32767;
      }
      v4[3].left = v8;
      v9 = v4[4].left;
      if ( v9 >= -32767 )
      {
        if ( v9 > 0x7FFF )
          v9 = 0x7FFF;
      }
      else
      {
        v9 = -32767;
      }
      v4[4].left = v9;
      v10 = v4[5].left;
      if ( v10 >= -32767 )
      {
        if ( v10 > 0x7FFF )
          v10 = 0x7FFF;
      }
      else
      {
        v10 = -32767;
      }
      v4[5].left = v10;
      v11 = v4[6].left;
      if ( v11 >= -32767 )
      {
        if ( v11 > 0x7FFF )
          v11 = 0x7FFF;
      }
      else
      {
        v11 = -32767;
      }
      v4[6].left = v11;
      v12 = v4[7].left;
      if ( v12 >= -32767 )
      {
        if ( v12 > 0x7FFF )
          v12 = 0x7FFF;
      }
      else
      {
        v12 = -32767;
      }
      v4[7].left = v12;
      v4 += 8;
      --v3;
    }
    while ( v3 != 0 );
  }
  for ( ; v2 > 0; ++v4 )
  {
    v13 = v4->left;
    if ( v4->left >= -32767 )
    {
      if ( v13 > 0x7FFF )
        v13 = 0x7FFF;
    }
    else
    {
      v13 = -32767;
    }
    v4->left = v13;
    --v2;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10030570
// Name: void SW_Mix16Stereo(struct portable_samplepair_t restrict __near *,int restrict __near *,short restrict __near *,int,unsigned int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SW_Mix16Stereo(
        portable_samplepair_t *pOutput,
        int *pVolume,
        __int16 *pData,
        int nInputOffset,
        unsigned int nRateScaleFix,
        unsigned int nOutCount)
{
  if ( snd_mix_optimization.m_pParent != nullptr && snd_mix_optimization.m_pParent->m_Value.m_nValue != 0 )
    SW_Mix16Stereo_Opt(pOutput, pVolume, pData, nInputOffset, nRateScaleFix, nOutCount);
  else
    SW_Mix16Stereo_NoOpt(pOutput, pVolume, pData, nInputOffset, nRateScaleFix, nOutCount);
}

//------------------------------------------------------------------------------
// Address: 0x10030590
// Name: _Mix8StereoWavtype
// Source: json
//------------------------------------------------------------------------------
void __cdecl Mix8StereoWavtype(
        channel_t *pChannel,
        portable_samplepair_t *pOutput,
        portable_samplepair_t *volume,
        unsigned __int8 *pData,
        int *inputOffset,
        int *rateScaleFix,
        int outCount)
{
  char wavtype; // al
  bool v8; // zf
  float dspface; // [esp-1Ch] [ebp-20h]
  float distmix; // [esp-1Ch] [ebp-20h]

  wavtype = pChannel->wavtype;
  if ( snd_mix_soundchar_enabled.m_pParent == nullptr || snd_mix_soundchar_enabled.m_pParent->m_Value.m_nValue == 0 )
    wavtype = 0;
  switch ( wavtype )
  {
    case '(':
    case '>':
      SW_Mix8StereoDopplerLeft(pOutput, volume: &volume->left, pData, inputOffset, (unsigned int)rateScaleFix, outCount);
      SW_Mix8StereoDopplerRight(
        pOutput,
        volume: &volume[3].left,
        pData,
        inputOffset,
        (unsigned int)rateScaleFix,
        outCount);
      break;
    case '<':
      v8 = !FUseHighQualityPitch(pChannel);
      dspface = pChannel->dspface;
      if ( v8 )
        SW_Mix8StereoDirectional(
          soundfacing: dspface,
          pOutput,
          volume: &volume->left,
          pData,
          (int)inputOffset,
          (unsigned int)rateScaleFix,
          outCount);
      else
        SW_Mix8StereoDirectional_Interp(
          soundfacing: dspface,
          pOutput,
          volume: &volume->left,
          pData,
          inputOffset,
          (unsigned int)rateScaleFix,
          outCount);
      break;
    case '^':
      v8 = !FUseHighQualityPitch(pChannel);
      distmix = pChannel->distmix;
      if ( v8 )
        SW_Mix8StereoDistVar(distmix, pOutput, volume, pData, (unsigned __int8 *)inputOffset, rateScaleFix, outCount);
      else
        SW_Mix8StereoDistVar_Interp(
          distmix,
          pOutput,
          volume: &volume->left,
          pData,
          (unsigned int)inputOffset,
          rateScaleFix,
          outCount);
      break;
    default:
      if ( FUseHighQualityPitch(pChannel) )
        SW_Mix8Stereo_Interp(pOutput, volume: &volume->left, pData, inputOffset, rateScaleFix, outCount);
      else
        SW_Mix8Stereo(pOutput, volume: &volume->left, pData, inputOffset, (unsigned int)rateScaleFix, outCount);
      break;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10030720
// Name: _Mix16StereoWavtype
// Source: json
//------------------------------------------------------------------------------
void __cdecl Mix16StereoWavtype(
        channel_t *pChannel,
        portable_samplepair_t *pOutput,
        int *volume,
        __int16 *pData,
        unsigned int inputOffset,
        unsigned int rateScaleFix,
        unsigned int outCount)
{
  bool v7; // al
  char wavtype; // cl
  float dspface; // [esp-20h] [ebp-24h]
  float distmix; // [esp-20h] [ebp-24h]

  if ( *volume + volume[1] > 2 )
  {
    v7 = FUseHighQualityPitch(pChannel);
    wavtype = pChannel->wavtype;
    if ( snd_mix_soundchar_enabled.m_pParent == nullptr || snd_mix_soundchar_enabled.m_pParent->m_Value.m_nValue == 0 )
      wavtype = 0;
    switch ( wavtype )
    {
      case '(':
      case '>':
        if ( v7 )
        {
          SW_Mix16StereoDopplerLeft_Interp(pOutput, volume, pData, inputOffset, rateScaleFix, outCount);
          SW_Mix16StereoDopplerRight_Interp(pOutput, volume: volume + 6, pData, inputOffset, rateScaleFix, outCount);
        }
        else
        {
          SW_Mix16StereoDopplerLeft(pOutput, volume, pData, inputOffset, rateScaleFix, outCount);
          SW_Mix16StereoDopplerRight(pOutput, volume: volume + 6, pData, inputOffset, rateScaleFix, outCount);
        }
        break;
      case '<':
        dspface = pChannel->dspface;
        if ( v7 )
          SW_Mix16StereoDirectional_Interp(
            soundfacing: dspface,
            pOutput,
            volume,
            pData,
            inputOffset,
            rateScaleFix,
            outCount);
        else
          SW_Mix16StereoDirectional(soundfacing: dspface, pOutput, volume, pData, inputOffset, rateScaleFix, outCount);
        break;
      case '@':
        if ( v7 )
          goto LABEL_17;
        SW_Mix16Stereo(
          pOutput,
          pVolume: volume,
          pData,
          nInputOffset: inputOffset,
          nRateScaleFix: rateScaleFix,
          nOutCount: outCount);
        break;
      case '^':
        distmix = pChannel->distmix;
        if ( v7 )
          SW_Mix16StereoDistVar_Interp(distmix, pOutput, volume, pData, inputOffset, rateScaleFix, outCount);
        else
          SW_Mix16StereoDistVar(distmix, pOutput, volume, pData, inputOffset, rateScaleFix, outCount);
        break;
      default:
        if ( v7 )
        {
LABEL_17:
          SW_Mix16Stereo_Interp(pOutput, pVolume: volume, pData, inputOffset, rateScaleFix, outCount);
        }
        else if ( snd_mix_optimization.m_pParent != nullptr && snd_mix_optimization.m_pParent->m_Value.m_nValue != 0 )
        {
          SW_Mix16Stereo_Opt(
            pOutput,
            pVolume: volume,
            pData,
            nInputOffset: inputOffset,
            nRateScaleFix: rateScaleFix,
            nOutCount: outCount);
        }
        else
        {
          SW_Mix16Stereo_NoOpt(
            pOutput,
            pVolume: volume,
            pData,
            nInputOffset: inputOffset,
            nRateScaleFix: rateScaleFix,
            nOutCount: outCount);
        }
        break;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10030990
// Name: _SND_IsRecording
// Source: json
//------------------------------------------------------------------------------
bool __cdecl SND_IsRecording()
{
  return cl_movieinfo.moviename[0] != 0
      && !Con_IsVisible()
      && (host_tickcount != g_nMovieStartTick
       || snd_moviefix.m_pParent == nullptr
       || snd_moviefix.m_pParent->m_Value.m_nValue == 0);
}

//------------------------------------------------------------------------------
// Address: 0x100309D0
// Name: void SND_RecordBuffer(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SND_RecordBuffer()
{
  int v0; // esi
  unsigned int v1; // ebx
  void *v2; // esp
  int i; // ecx
  int v4; // eax
  int v5; // eax
  _WORD v6[6]; // [esp+0h] [ebp-Ch] BYREF

  if ( cl_movieinfo.moviename[0] != 0
    && !Con_IsVisible()
    && (host_tickcount != g_nMovieStartTick
     || snd_moviefix.m_pParent == nullptr
     || snd_moviefix.m_pParent->m_Value.m_nValue == 0) )
  {
    v0 = snd_linear_count;
    v1 = 2 * snd_linear_count;
    v2 = alloca(2 * snd_linear_count);
    for ( i = 0; i < snd_linear_count; i += 2 )
    {
      v4 = (snd_vol * snd_p[i]) >> 8;
      if ( v4 >= -32767 )
      {
        if ( v4 > 0x7FFF )
          LOWORD(v4) = 0x7FFF;
      }
      else
      {
        LOWORD(v4) = -32767;
      }
      v6[i] = v4;
      v5 = (snd_vol * snd_p[i + 1]) >> 8;
      if ( v5 >= -32767 )
      {
        if ( v5 > 0x7FFF )
          LOWORD(v5) = 0x7FFF;
      }
      else
      {
        LOWORD(v5) = -32767;
      }
      v6[i + 1] = v5;
      v0 = snd_linear_count;
    }
    if ( (cl_movieinfo.type & 4) != 0 )
    {
      WaveAppendTmpFile(filename: cl_movieinfo.moviename, pBuffer: v6, sampleBits: 16, numSamples: v0);
      v0 = snd_linear_count;
    }
    if ( (cl_movieinfo.type & 8) != 0 )
    {
      g_pAVI->AppendMovieSound(this: g_pAVI, a2: g_hCurrentAVI, a3: v6, a4: v1);
      v0 = snd_linear_count;
    }
    g_nMovieSamples += v0 >> 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10030B00
// Name: _S_TransferStereo16
// Source: json
//------------------------------------------------------------------------------
void __cdecl S_TransferStereo16(
        char *pOutput,
        const portable_samplepair_t *pfront,
        __int64 lpaintedtime,
        __int64 endtime)
{
  int v4; // ecx
  unsigned int v5; // ebx
  int v6; // eax
  int v7; // ecx
  unsigned int v8; // eax
  int samplePairCount; // [esp+0h] [ebp-4h]
  bool bShouldPlaySound_3; // [esp+13h] [ebp+Fh]

  snd_vol = (int)(S_GetMasterVolume() * 256.0);
  snd_p = &pfront->left;
  v4 = g_AudioDevice->DeviceSampleCount(this: g_AudioDevice) >> 1;
  samplePairCount = v4;
  bShouldPlaySound_3 = cl_movieinfo.moviename[0] == 0;
  if ( SHIDWORD(lpaintedtime) <= SHIDWORD(endtime) )
  {
    v5 = lpaintedtime;
    if ( SHIDWORD(lpaintedtime) < SHIDWORD(endtime) || (unsigned int)lpaintedtime < (unsigned int)endtime )
    {
      while ( 1 )
      {
        v6 = (v4 - 1) & v5;
        v7 = v4 - v6;
        snd_out = (__int16 *)&pOutput[4 * v6];
        if ( v7 > (__int64)(endtime - __PAIR64__(HIDWORD(lpaintedtime), v5)) )
          v7 = endtime - v5;
        snd_linear_count = 2 * v7;
        SND_RecordBuffer();
        if ( bShouldPlaySound_3 )
          Snd_WriteLinearBlastStereo16();
        snd_p += snd_linear_count;
        v8 = ((snd_linear_count >> 1) + __PAIR64__(HIDWORD(lpaintedtime), v5)) >> 32;
        v5 += snd_linear_count >> 1;
        HIDWORD(lpaintedtime) = v8;
        if ( __SPAIR64__(v8, v5) >= endtime )
          break;
        v4 = samplePairCount;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10030BF0
// Name: _SND_MouthUpdateAll
// Source: json
//------------------------------------------------------------------------------
void SND_MouthUpdateAll()
{
  int v0; // edi
  char *v1; // edi
  IClientEntity *v2; // eax
  CMouthInfo *v3; // eax
  CMouthInfo *v4; // esi
  int m_nVoiceSources; // edx
  int v6; // eax
  CVoiceData *m_VoiceSources; // ecx
  CVoiceData *v8; // eax
  const char *v9; // eax
  int v10; // ebx
  mouthenvelope_t *v11; // edi
  IClientEntity *v12; // eax
  int v13; // eax
  int v14; // esi
  int v15; // ecx
  int v16; // eax
  char nameBuf[260]; // [esp+Ch] [ebp-10Ch] BYREF
  int i; // [esp+110h] [ebp-8h]
  int v19; // [esp+114h] [ebp-4h]

  v0 = 0;
  i = 0;
  if ( g_MouthOutput.m_Size > 0 )
  {
    v19 = 0;
    do
    {
      v1 = (char *)g_MouthOutput.m_Memory.m_pMemory + v0;
      v2 = entitylist->GetClientEntity(this: entitylist, a2: *(_DWORD *)v1);
      if ( v2 == nullptr )
        goto LABEL_21;
      v3 = v2->GetMouth(this: v2);
      v4 = v3;
      if ( v3 == nullptr )
        goto LABEL_21;
      if ( *((float *)v1 + 2) >= 0.0 )
      {
        m_nVoiceSources = v3->m_nVoiceSources;
        v6 = 0;
        if ( m_nVoiceSources <= 0 )
          goto LABEL_14;
        m_VoiceSources = v4->m_VoiceSources;
        while ( m_VoiceSources == nullptr || m_VoiceSources->m_pAudioSource != *((CAudioSource **)v1 + 1) )
        {
          ++v6;
          ++m_VoiceSources;
          if ( v6 >= v4->m_nVoiceSources )
            goto LABEL_14;
        }
        if ( v6 == -1 )
        {
LABEL_14:
          v8 = CMouthInfo::AddSource(this: v4, source: *((CAudioSource **)v1 + 1), bIgnorePhonemes: false);
          if ( v8 != nullptr )
            goto LABEL_20;
          v4->m_nVoiceSources = 0;
          v9 = (const char *)(*(int (__thiscall **)(_DWORD, char *, int))(**((_DWORD **)v1 + 1) + 112))(
                               a1: *((_DWORD *)v1 + 1),
                               a2: nameBuf,
                               a3: 260);
          _DevMsg(a1: 2, a2: "out of voice sources, won't lipsync %s\n", v9);
          v8 = CMouthInfo::AddSource(this: v4, source: *((CAudioSource **)v1 + 1), bIgnorePhonemes: false);
        }
        else
        {
          if ( v6 < 0 || v6 >= m_nVoiceSources )
            goto LABEL_21;
          v8 = &v4->m_VoiceSources[v6];
        }
        if ( v8 != nullptr )
LABEL_20:
          v8->m_flElapsed = *((float *)v1 + 2);
      }
      else
      {
        CMouthInfo::RemoveSource(this: v3, source: *((CAudioSource **)v1 + 1));
        v4->mouthopen = 0;
      }
LABEL_21:
      v0 = v19 + 12;
      ++i;
      v19 += 12;
    }
    while ( i < g_MouthOutput.m_Size );
  }
  v10 = 0;
  g_MouthOutput.m_Size = 0;
  v19 = 0;
  if ( g_MouthEnvelope.m_Size <= 0 )
  {
    g_MouthEnvelope.m_Size = 0;
  }
  else
  {
    do
    {
      v11 = &g_MouthEnvelope.m_Memory.m_pMemory[v10];
      v12 = entitylist->GetClientEntity(this: entitylist, a2: g_MouthEnvelope.m_Memory.m_pMemory[v10].entityId);
      if ( v12 != nullptr )
      {
        v13 = (int)v12->GetMouth(this: v12);
        v14 = v13;
        if ( v13 != 0 )
        {
          if ( *(_WORD *)(v13 + 10) != 0 )
          {
            *(_DWORD *)(v13 + 4) += v11->sampleTotal;
            v15 = v11->sampleCount + *(unsigned __int8 *)(v13 + 1);
            v16 = *(_DWORD *)(v13 + 4);
            if ( v15 < 10 )
            {
              *(_BYTE *)(v14 + 1) = v15;
            }
            else
            {
              *(_DWORD *)(v14 + 4) = 0;
              *(_WORD *)v14 = (unsigned __int8)(v16 / v15);
            }
          }
          else
          {
            *(_BYTE *)v13 = 0;
          }
        }
      }
      ++v10;
      ++v19;
    }
    while ( v19 < g_MouthEnvelope.m_Size );
    g_MouthEnvelope.m_Size = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10030E20
// Name: _SND_CloseMouth
// Source: json
//------------------------------------------------------------------------------
void __cdecl SND_CloseMouth(channel_t *pChannel)
{
  int speakerentity; // esi
  IClientEntity *v2; // eax
  int v3; // eax

  if ( (*((_BYTE *)&pChannel->flags + 1) & 0x40) != 0 )
  {
    speakerentity = pChannel->speakerentity;
    if ( speakerentity == -1 )
      speakerentity = pChannel->soundsource;
    v2 = entitylist->GetClientEntity(this: entitylist, a2: speakerentity);
    if ( v2 != nullptr && v2->GetMouth(this: v2) != nullptr )
    {
      v3 = CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::AddToTail(this: (CUtlVector<CAppSystemGroup::Module_t,CUtlMemory<CAppSystemGroup::Module_t,int> > *)&g_MouthOutput);
      g_MouthOutput.m_Memory.m_pMemory[v3].entityId = speakerentity;
      g_MouthOutput.m_Memory.m_pMemory[v3].pSource = pChannel->sfx->pSource;
      g_MouthOutput.m_Memory.m_pMemory[v3].elapsedTime = -1.0;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10030EB0
// Name: _SND_MoveMouth8
// Source: json
//------------------------------------------------------------------------------
void __cdecl SND_MoveMouth8(channel_t *ch, CAudioSource *pSource)
{
  char v3; // cl
  int speakerentity; // eax
  int v5; // esi
  int mouthentity; // [esp+Ch] [ebp+8h]
  float mouthentitya; // [esp+Ch] [ebp+8h]

  v3 = BYTE1(ch->flagsword);
  if ( (v3 & 0x40) != 0 )
  {
    speakerentity = ch->speakerentity;
    if ( speakerentity == -1 )
      speakerentity = ch->soundsource;
    mouthentity = speakerentity;
    if ( (v3 & 0x20) == 0 && pSource->GetSentence(this: pSource) != nullptr )
    {
      v5 = CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::AddToTail(this: (CUtlVector<CAppSystemGroup::Module_t,CUtlMemory<CAppSystemGroup::Module_t,int> > *)&g_MouthOutput);
      g_MouthOutput.m_Memory.m_pMemory[v5].entityId = mouthentity;
      g_MouthOutput.m_Memory.m_pMemory[v5].pSource = pSource;
      mouthentitya = (float)ch->pMixer->GetSamplePosition(this: ch->pMixer);
      g_MouthOutput.m_Memory.m_pMemory[v5].elapsedTime = mouthentitya / (float)pSource->SampleRate(this: pSource);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10030F60
// Name: _SND_MouthEnvelopeFollower
// Source: json
//------------------------------------------------------------------------------
void __cdecl SND_MouthEnvelopeFollower(channel_t *pChannel, char *pData, int count)
{
  char v4; // cl
  int speakerentity; // ecx
  int v6; // eax
  int v7; // ecx
  int v8; // esi
  int v9; // edi
  int v10; // ebx
  int v11; // eax
  int mix_sample_size; // [esp+0h] [ebp-4h]
  int mouthentity; // [esp+Ch] [ebp+8h]

  v4 = BYTE1(pChannel->flagsword);
  if ( (v4 & 0x40) != 0 && v4 < 0 && pData != nullptr && count != 0 )
  {
    speakerentity = pChannel->speakerentity;
    if ( speakerentity == -1 )
      speakerentity = pChannel->soundsource;
    mouthentity = speakerentity;
    v6 = pChannel->pMixer->GetMixSampleSize(this: pChannel->pMixer);
    v7 = 0;
    v8 = 0;
    v9 = 0;
    v10 = 0;
    mix_sample_size = v6;
    if ( count > 0 )
    {
      while ( v8 < 10 )
      {
        if ( v6 == 1 )
        {
          v10 = pData[v7];
        }
        else if ( v6 == 2 )
        {
          v10 = pData[2 * v7 + 1];
        }
        v7 += (v10 & 0x1F) + 80;
        v9 += abs32(v10);
        ++v8;
        if ( v7 >= count )
          break;
        v6 = mix_sample_size;
      }
    }
    v11 = CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::AddToTail(this: (CUtlVector<CAppSystemGroup::Module_t,CUtlMemory<CAppSystemGroup::Module_t,int> > *)&g_MouthEnvelope);
    g_MouthEnvelope.m_Memory.m_pMemory[v11].entityId = mouthentity;
    g_MouthEnvelope.m_Memory.m_pMemory[v11].sampleTotal = v9;
    g_MouthEnvelope.m_Memory.m_pMemory[v11].sampleCount = v8;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10031040
// Name: _SND_ClearMouth
// Source: json
//------------------------------------------------------------------------------
void __cdecl SND_ClearMouth(channel_t *pChannel)
{
  int speakerentity; // edi
  int v2; // eax

  if ( (*((_BYTE *)&pChannel->flags + 1) & 0x40) != 0 && pChannel->sfx != nullptr )
  {
    speakerentity = pChannel->speakerentity;
    if ( speakerentity == -1 )
      speakerentity = pChannel->soundsource;
    v2 = CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::AddToTail(this: (CUtlVector<CAppSystemGroup::Module_t,CUtlMemory<CAppSystemGroup::Module_t,int> > *)&g_MouthOutput);
    g_MouthOutput.m_Memory.m_pMemory[v2].entityId = speakerentity;
    g_MouthOutput.m_Memory.m_pMemory[v2].pSource = pChannel->sfx->pSource;
    g_MouthOutput.m_Memory.m_pMemory[v2].elapsedTime = -1.0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100310B0
// Name: void S_FreeChannel(struct channel_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl S_FreeChannel(channel_t *ch)
{
  char v1; // al
  char *v2; // eax
  CSfxTable *sfx; // ecx
  char *m_pszString; // eax
  ISoundServices_vtbl *v5; // edi
  const char *v6; // eax
  CAudioMixer *pMixer; // ecx
  CSosOperatorStackList *m_pStackList; // edi
  char nameBuf[260]; // [esp+4h] [ebp-104h] BYREF

  v1 = BYTE1(ch->flagsword);
  if ( (v1 & 4) == 0 )
  {
    *((_BYTE *)&ch->flags + 1) = v1 | 4;
    if ( (snd_find_channel.m_nFlags & 0x1000) != 0
      || (v2 = snd_find_channel.m_pParent->m_Value.m_pszString) != nullptr && *v2 != 0 )
    {
      sfx = ch->sfx;
      if ( sfx != nullptr )
      {
        CSfxTable::GetFileName(this: sfx, pOutBuf: nameBuf, bufLen: 0x104u);
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
          PrintChannel(pText1: "FreeChannel", pFileName: nameBuf, pChannel: ch, pText2: "from ConVar snd_find_channel.");
      }
    }
    SND_CloseMouth(pChannel: ch);
    v5 = g_pSoundServices->__vftable;
    v6 = ch->sfx->getname(this: ch->sfx, a2: nameBuf, a3: 260u);
    v5->OnSoundStopped(this: g_pSoundServices, a2: ch->guid, a3: ch->soundsource, a4: ch->entchannel, a5: v6);
    pMixer = ch->pMixer;
    LOBYTE(ch->flagsword) &= ~2u;
    if ( pMixer != nullptr )
      ((void (__thiscall *)(CAudioMixer *, int))pMixer->dtr_CAudioMixer)(a1: pMixer, a2: 1);
    m_pStackList = ch->m_pStackList;
    ch->pMixer = nullptr;
    ch->sfx = nullptr;
    ch->m_nSoundScriptHandle = -1;
    if ( m_pStackList != nullptr )
    {
      CSosOperatorStackList::~CSosOperatorStackList(this: m_pStackList);
      free(pMem: m_pStackList);
      ch->m_pStackList = nullptr;
    }
    CActiveChannels::Remove(this: &g_ActiveChannels, pChannel: ch);
    _V_memset(dest: ch, fill: 0, count: 332);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10031210
// Name: void MIX_MixChannelsToPaintbuffer(class CChannelList __near &,__int64,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MIX_MixChannelsToPaintbuffer(CChannelList *list, __int64 endtime, int flags, int rate, int outputRate)
{
  int v5; // ecx
  channel_t *v6; // esi
  bool v7; // zf
  char flagsword; // al
  bool v9; // bl
  bool v10; // al
  int v11; // ebx
  CAudioMixer *pMixer; // ecx
  CAudioMixer *v13; // ecx
  CSosOperatorStackList *m_pStackList; // ecx
  int v15; // eax
  float flPitch; // [esp+4h] [ebp-10h]
  float flGlobalPitchScale; // [esp+8h] [ebp-Ch]
  int sampleCount; // [esp+Ch] [ebp-8h]
  int i; // [esp+10h] [ebp-4h]
  int v20; // [esp+24h] [ebp+10h]

  sampleCount = (endtime - g_paintedtime) / (44100 / outputRate);
  if ( sampleCount > 0 )
  {
    v5 = list->m_count - 1;
    flGlobalPitchScale = host_timescale.m_pParent->m_Value.m_fValue;
    v20 = v5;
    if ( v5 >= 0 )
    {
      for ( i = 2 * v5 + 4; ; i -= 2 )
      {
        v6 = &channels[*(__int16 *)((char *)&list->m_count + i)];
        if ( flags == 1 )
          break;
        if ( flags != 0 )
        {
          if ( flags != 2 )
            goto LABEL_13;
          v7 = (v6->flagsword & 8) == 0;
LABEL_12:
          if ( !v7 )
            goto LABEL_13;
          goto LABEL_36;
        }
        flagsword = v6->flagsword;
        if ( (flagsword & 4) == 0 && (flagsword & 8) == 0 )
        {
LABEL_13:
          if ( rate != 11025 && rate != 22050 && rate != 44100
            || rate == v6->sfx->pSource->SampleRate(this: v6->sfx->pSource) )
          {
            v9 = (*((_BYTE *)&v6->flags + 1) & 0x40) != 0;
            v10 = v9;
            if ( snd_pause_all.m_pParent != nullptr && snd_pause_all.m_pParent->m_Value.m_nValue != 0 )
              v10 = (*((_BYTE *)v6->sfx + 12) & 2) == 0;
            if ( !v10 || !g_pSoundServices->IsGamePaused(this: g_pSoundServices) )
            {
              if ( v9 && (*((_BYTE *)&v6->flags + 1) & 0x40) != 0 )
              {
                v11 = sampleCount;
                SND_MoveMouth8(ch: v6, pSource: v6->sfx->pSource);
              }
              else
              {
                v11 = sampleCount;
              }
              pMixer = v6->pMixer;
              flPitch = v6->pitch;
              v6->pitch = flPitch * flGlobalPitchScale;
              if ( list->m_quashed[v20] )
                pMixer->SkipSamples(this: pMixer, a2: v6, a3: v11, a4: outputRate, a5: 0);
              else
                pMixer->MixDataToDevice(this: pMixer, a2: g_AudioDevice, a3: v6, a4: v11, a5: outputRate, a6: 0);
              v13 = v6->pMixer;
              v6->pitch = flPitch;
              if ( !v13->ShouldContinueMixing(this: v13) )
              {
                m_pStackList = v6->m_pStackList;
                if ( m_pStackList != nullptr )
                  CSosOperatorStackList::Execute(
                    this: m_pStackList,
                    SosType: SOS_STOP,
                    pChannel: v6,
                    pScratchPad: &g_scratchpad);
                S_FreeChannel(ch: v6);
                v15 = --list->m_count;
                if ( list->m_count > 0 && v20 != v15 )
                {
                  *(_WORD *)((char *)&list->m_count + i) = list->m_list[v15];
                  list->m_quashed[v20] = list->m_quashed[list->m_count];
                }
              }
            }
          }
          v5 = v20;
        }
LABEL_36:
        v20 = --v5;
        if ( v5 < 0 )
          return;
      }
      v7 = (v6->flagsword & 4) == 0;
      goto LABEL_12;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10031430
// Name: void MIX_MixUpsampleBuffer(class CChannelList __near &,int,__int64,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MIX_MixUpsampleBuffer(CChannelList *list, int ipaintbuffer, __int64 end, int count, int flags)
{
  portable_samplepair_t *pbufcenter; // edx
  int v6; // eax
  portable_samplepair_t **p_pbuf; // ecx
  int v8; // eax
  paintbuffer_t *v9; // eax
  int ipaintcur; // [esp+Ch] [ebp-4h]

  pbufcenter = nullptr;
  v6 = 0;
  p_pbuf = &g_paintBuffers->pbuf;
  while ( g_curpaintbuffer != *p_pbuf )
  {
    ++v6;
    p_pbuf += 78;
    if ( v6 >= 6 )
    {
      ipaintcur = 0;
      goto LABEL_5;
    }
  }
  ipaintcur = v6;
LABEL_5:
  v8 = ipaintbuffer;
  g_paintBuffers[v8].ifilter = 0;
  g_paintBuffers->factive = false;
  g_paintBuffers[1].factive = false;
  g_paintBuffers[2].factive = false;
  g_paintBuffers[3].factive = false;
  g_paintBuffers[4].factive = false;
  g_paintBuffers[5].factive = false;
  g_paintBuffers[v8].factive = true;
  g_curpaintbuffer = g_paintBuffers[ipaintbuffer].pbuf;
  if ( g_paintBuffers[ipaintbuffer].fsurround )
  {
    g_currearpaintbuffer = g_paintBuffers[v8].pbufrear;
    g_curcenterpaintbuffer = nullptr;
    if ( !g_paintBuffers[v8].fsurround_center )
      goto LABEL_11;
    pbufcenter = g_paintBuffers[v8].pbufcenter;
  }
  else
  {
    g_currearpaintbuffer = nullptr;
  }
  g_curcenterpaintbuffer = pbufcenter;
LABEL_11:
  if ( (*((_BYTE *)list + 388) & 4) != 0 )
  {
    MIX_MixChannelsToPaintbuffer(list, endtime: end, flags, rate: 11025, outputRate: 11025);
    g_AudioDevice->MixUpsample(this: g_AudioDevice, a2: count / 4, a3: 1);
  }
  if ( (*((_BYTE *)list + 388) & 0xC) != 0 )
  {
    MIX_MixChannelsToPaintbuffer(list, endtime: end, flags, rate: 22050, outputRate: 22050);
    g_AudioDevice->MixUpsample(this: g_AudioDevice, a2: count / 2, a3: 1);
  }
  MIX_MixChannelsToPaintbuffer(list, endtime: end, flags, rate: 44100, outputRate: 44100);
  g_paintBuffers->factive = false;
  g_paintBuffers[1].factive = false;
  g_paintBuffers[2].factive = false;
  g_paintBuffers[3].factive = false;
  g_paintBuffers[4].factive = false;
  g_paintBuffers[5].factive = false;
  v9 = &g_paintBuffers[ipaintcur];
  g_curpaintbuffer = v9->pbuf;
  if ( v9->fsurround )
  {
    g_currearpaintbuffer = v9->pbufrear;
    g_curcenterpaintbuffer = nullptr;
    if ( v9->fsurround_center )
      g_curcenterpaintbuffer = v9->pbufcenter;
  }
  else
  {
    g_currearpaintbuffer = nullptr;
    g_curcenterpaintbuffer = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10031650
// Name: void MIX_UpsampleAllPaintbuffers(class CChannelList __near &,__int64,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MIX_UpsampleAllPaintbuffers(CChannelList *list, __int64 end, int count)
{
  if ( (*((_BYTE *)list + 388) & 2) != 0 )
    MIX_MixUpsampleBuffer(list, ipaintbuffer: 4, end, count, flags: 1);
  if ( (*((_BYTE *)list + 388) & 1) != 0 )
    MIX_MixUpsampleBuffer(list, ipaintbuffer: 5, end, count, flags: 2);
  g_paintBuffers->factive = false;
  g_paintBuffers[1].factive = false;
  g_paintBuffers[2].factive = false;
  g_paintBuffers[3].factive = false;
  g_paintBuffers[4].factive = false;
  g_paintBuffers[5].factive = false;
  g_paintBuffers->ifilter = 0;
  g_paintBuffers[1].ifilter = 0;
  g_paintBuffers[2].ifilter = 0;
  g_paintBuffers[3].ifilter = 0;
  g_paintBuffers[4].ifilter = 0;
  g_paintBuffers[5].ifilter = 0;
  if ( !g_bDspOff )
    g_paintBuffers[1].factive = true;
  g_paintBuffers[2].factive = true;
  if ( g_bdirectionalfx )
    g_paintBuffers[3].factive = true;
  MIX_MixChannelsToPaintbuffer(list, endtime: end, flags: 0, rate: 11025, outputRate: 11025);
  if ( !g_bDspOff )
  {
    g_curpaintbuffer = g_paintBuffers[1].pbuf;
    if ( g_paintBuffers[1].fsurround )
    {
      g_currearpaintbuffer = g_paintBuffers[1].pbufrear;
      g_curcenterpaintbuffer = nullptr;
      if ( g_paintBuffers[1].fsurround_center )
        g_curcenterpaintbuffer = g_paintBuffers[1].pbufcenter;
    }
    else
    {
      g_currearpaintbuffer = nullptr;
      g_curcenterpaintbuffer = nullptr;
    }
    g_AudioDevice->MixUpsample(this: g_AudioDevice, a2: count / 4, a3: 1);
  }
  g_curpaintbuffer = g_paintBuffers[2].pbuf;
  if ( g_paintBuffers[2].fsurround )
  {
    g_currearpaintbuffer = g_paintBuffers[2].pbufrear;
    g_curcenterpaintbuffer = nullptr;
    if ( g_paintBuffers[2].fsurround_center )
      g_curcenterpaintbuffer = g_paintBuffers[2].pbufcenter;
  }
  else
  {
    g_currearpaintbuffer = nullptr;
    g_curcenterpaintbuffer = nullptr;
  }
  g_AudioDevice->MixUpsample(this: g_AudioDevice, a2: count / 4, a3: 1);
  if ( g_bdirectionalfx )
  {
    g_curpaintbuffer = g_paintBuffers[3].pbuf;
    if ( g_paintBuffers[3].fsurround )
    {
      g_currearpaintbuffer = g_paintBuffers[3].pbufrear;
      g_curcenterpaintbuffer = nullptr;
      if ( g_paintBuffers[3].fsurround_center )
        g_curcenterpaintbuffer = g_paintBuffers[3].pbufcenter;
    }
    else
    {
      g_currearpaintbuffer = nullptr;
      g_curcenterpaintbuffer = nullptr;
    }
    g_AudioDevice->MixUpsample(this: g_AudioDevice, a2: count / 4, a3: 1);
  }
  MIX_MixChannelsToPaintbuffer(list, endtime: end, flags: 0, rate: 22050, outputRate: 22050);
  if ( !g_bDspOff )
  {
    g_curpaintbuffer = g_paintBuffers[1].pbuf;
    if ( g_paintBuffers[1].fsurround )
    {
      g_currearpaintbuffer = g_paintBuffers[1].pbufrear;
      g_curcenterpaintbuffer = nullptr;
      if ( g_paintBuffers[1].fsurround_center )
        g_curcenterpaintbuffer = g_paintBuffers[1].pbufcenter;
    }
    else
    {
      g_currearpaintbuffer = nullptr;
      g_curcenterpaintbuffer = nullptr;
    }
    g_AudioDevice->MixUpsample(this: g_AudioDevice, a2: count / 2, a3: 1);
  }
  g_curpaintbuffer = g_paintBuffers[2].pbuf;
  if ( g_paintBuffers[2].fsurround )
  {
    g_currearpaintbuffer = g_paintBuffers[2].pbufrear;
    g_curcenterpaintbuffer = nullptr;
    if ( g_paintBuffers[2].fsurround_center )
      g_curcenterpaintbuffer = g_paintBuffers[2].pbufcenter;
  }
  else
  {
    g_currearpaintbuffer = nullptr;
    g_curcenterpaintbuffer = nullptr;
  }
  g_AudioDevice->MixUpsample(this: g_AudioDevice, a2: count / 2, a3: 1);
  if ( g_bdirectionalfx )
  {
    g_curpaintbuffer = g_paintBuffers[3].pbuf;
    if ( g_paintBuffers[3].fsurround )
    {
      g_currearpaintbuffer = g_paintBuffers[3].pbufrear;
      g_curcenterpaintbuffer = nullptr;
      if ( g_paintBuffers[3].fsurround_center )
        g_curcenterpaintbuffer = g_paintBuffers[3].pbufcenter;
    }
    else
    {
      g_currearpaintbuffer = nullptr;
      g_curcenterpaintbuffer = nullptr;
    }
    g_AudioDevice->MixUpsample(this: g_AudioDevice, a2: count / 2, a3: 1);
  }
  MIX_MixChannelsToPaintbuffer(list, endtime: end, flags: 0, rate: 44100, outputRate: 44100);
  g_paintBuffers->factive = false;
  g_paintBuffers[1].factive = false;
  g_paintBuffers[2].factive = false;
  g_paintBuffers[3].factive = false;
  g_paintBuffers[4].factive = false;
  g_paintBuffers[5].factive = false;
  g_curpaintbuffer = g_paintBuffers->pbuf;
  if ( g_paintBuffers->fsurround )
  {
    g_currearpaintbuffer = g_paintBuffers->pbufrear;
    g_curcenterpaintbuffer = nullptr;
    if ( g_paintBuffers->fsurround_center )
      g_curcenterpaintbuffer = g_paintBuffers->pbufcenter;
  }
  else
  {
    g_currearpaintbuffer = nullptr;
    g_curcenterpaintbuffer = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10031AB0
// Name: void MIX_BuildChannelList(class CChannelList __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MIX_BuildChannelList(int list)
{
  DWORD CurrentThreadId; // ecx
  int v3; // eax
  channel_t *v4; // esi
  char v5; // bl
  bool v6; // al
  CAudioSource *v7; // ecx
  int v8; // eax
  bool v9; // al
  int v10; // eax
  int v11; // eax
  char flagsword; // al
  CChannelCullList v13; // [esp+10h] [ebp-698h] BYREF
  SoundError v14; // [esp+694h] [ebp-14h] BYREF
  int v15; // [esp+698h] [ebp-10h]
  CAudioSource *v16; // [esp+69Ch] [ebp-Ch]
  int v17; // [esp+6A0h] [ebp-8h]
  SoundError soundError; // [esp+6A4h] [ebp-4h]
  char i_3; // [esp+6B3h] [ebp+Bh]

  CActiveChannels::GetActiveChannels(this: &g_ActiveChannels, (CChannelList *)list);
  *(_BYTE *)(list + 388) &= 0xE0u;
  i_3 = 0;
  HIWORD(soundError) = g_pSoundServices->IsGamePaused(this: g_pSoundServices);
  v13.m_numChans = 0;
  if ( snd_cull_duplicates.m_pParent != nullptr && snd_cull_duplicates.m_pParent->m_Value.m_nValue > 0 )
    CChannelCullList::Initialize(this: &v13, (CChannelList *)list);
  CurrentThreadId = GetCurrentThreadId();
  if ( CurrentThreadId != g_SoundMapMutex.m_ownerID
    && _InterlockedCompareExchange((volatile signed __int32 *)&g_SoundMapMutex, CurrentThreadId, 0) != 0 )
  {
    _mm_pause();
    CThreadFastMutex::Lock(a1: &g_SoundMapMutex, a2: CurrentThreadId, a3: 0);
  }
  else
  {
    ++g_SoundMapMutex.m_depth;
  }
  v3 = *(_DWORD *)list - 1;
  v17 = v3;
  if ( v3 >= 0 )
  {
    v15 = 2 * v3 + 4;
    while ( 1 )
    {
      v4 = &channels[*(__int16 *)(v15 + list)];
      v5 = 0;
      if ( !v4->pMixer->IsReadyToMix(this: v4->pMixer) )
      {
        v11 = (int)v4->pMixer->GetSource(this: v4->pMixer);
        if ( (*(int (__thiscall **)(int))(*(_DWORD *)v11 + 60))(a1: v11) == 3 )
          S_FreeChannel(ch: v4);
        goto LABEL_23;
      }
      v16 = S_LoadSound(pSfx: v4->sfx, ch: v4, soundError: &v14);
      v6 = BChannelLowVolume(pch: v4, vol_min: 1);
      v7 = v16;
      if ( v16 == nullptr )
        break;
      if ( v6 )
      {
        if ( ((unsigned __int8 (*)(void))v16->IsLooped)() != 0 || (v4->flagsword & 4) != 0 )
          goto LABEL_17;
        if ( v16->GetSentence(this: v16) == nullptr )
          break;
LABEL_18:
        v7 = v16;
      }
      if ( BYTE2(soundError) != 0 && (*((_BYTE *)&v4->flags + 1) & 0x10) != 0 )
      {
        v5 = 1;
      }
      else if ( v5 == 0
             && snd_cull_duplicates.m_pParent != nullptr
             && snd_cull_duplicates.m_pParent->m_Value.m_nValue > 0 )
      {
        v9 = v13.m_numChans > v17 && v13.m_bShouldCull[v17];
        *(_BYTE *)(v17 + list + 260) = v9;
LABEL_33:
        if ( (v4->flagsword & 8) != 0 )
          *(_BYTE *)(list + 388) |= 1u;
        if ( (v4->flagsword & 4) != 0 )
          *(_BYTE *)(list + 388) |= 2u;
        v10 = v7->SampleRate(this: v7);
        switch ( v10 )
        {
          case 11025:
            *(_BYTE *)(list + 388) |= 4u;
            break;
          case 22050:
            *(_BYTE *)(list + 388) |= 8u;
            break;
          case 44100:
            *(_BYTE *)(list + 388) |= 0x10u;
            break;
          default:
            break;
        }
        flagsword = v4->flagsword;
        if ( (flagsword & 0x20) != 0 && (*((_BYTE *)&v4->flags + 1) & 0x40) == 0 )
        {
          if ( (flagsword & 0x40) != 0 )
            HIBYTE(soundError) = 1;
          else
            i_3 = 1;
        }
        v4->pitch = ((double (__cdecl *)(_DWORD))v4->pMixer->ModifyPitch)(a1: (float)v4->basePitch * 0.0099999998);
        goto LABEL_51;
      }
      *(_BYTE *)(v17 + list + 260) = 0;
      if ( v5 == 0 )
        goto LABEL_33;
LABEL_23:
      v8 = --*(_DWORD *)list;
      if ( *(int *)list > 0 && v17 != v8 )
      {
        *(_WORD *)(v15 + list) = *(_WORD *)(list + 2 * v8 + 4);
        *(_BYTE *)(v17 + list + 260) = *(_BYTE *)(*(_DWORD *)list + list + 260);
      }
LABEL_51:
      v15 -= 2;
      if ( --v17 < 0 )
        goto LABEL_52;
    }
    S_FreeChannel(ch: v4);
LABEL_17:
    v5 = 1;
    goto LABEL_18;
  }
LABEL_52:
  if ( BYTE2(soundError) != 0 || host_frametime_unbounded > host_frametime )
  {
    i_3 = 0;
  }
  else if ( HIBYTE(soundError) != 0 )
  {
    goto LABEL_57;
  }
  S_SyncClockAdjust(syncIndex: CLOCK_SYNC_SERVER);
LABEL_57:
  if ( i_3 == 0 )
    S_SyncClockAdjust(syncIndex: CLOCK_SYNC_CLIENT);
  if ( --g_SoundMapMutex.m_depth == 0 )
    _InterlockedExchange((volatile __int32 *)&g_SoundMapMutex, 0);
}

//------------------------------------------------------------------------------
// Address: 0x10031DA0
// Name: _MIX_PaintChannels
// Source: json
//------------------------------------------------------------------------------
void __usercall MIX_PaintChannels(
        unsigned int a1@<ebx>,
        unsigned int a2@<edi>,
        portable_samplepair_t *a3@<esi>,
        __int64 endtime,
        bool bIsUnderwater)
{
  int m_nValue; // eax
  char *m_pszString; // eax
  int v7; // eax
  float m_fValue; // xmm0_4
  unsigned int v9; // eax
  unsigned int v10; // esi
  unsigned int v11; // edx
  unsigned int v12; // ecx
  unsigned int v13; // edi
  portable_samplepair_t *v14; // esi
  bool v15; // of
  portable_samplepair_t *v16; // esi
  IAudioDevice *v17; // edi
  IAudioDevice_vtbl *v18; // ebx
  portable_samplepair_t *PRearFromIPaint; // eax
  IAudioDevice *v20; // edi
  IAudioDevice_vtbl *v21; // ebx
  portable_samplepair_t *v22; // eax
  portable_samplepair_t *pbuf; // ebx
  IAudioDevice_vtbl *v24; // edi
  int idsp_room; // eax
  paintbuffer_t *v26; // edi
  bool fsurround_center; // cl
  IAudioDevice_vtbl *v28; // ebx
  portable_samplepair_t *v29; // eax
  double v30; // st7
  bool v31; // dl
  IAudioDevice *v32; // edi
  IAudioDevice_vtbl *v33; // ebx
  portable_samplepair_t *v34; // eax
  IAudioDevice *v35; // edi
  IAudioDevice_vtbl *v36; // ebx
  portable_samplepair_t *v37; // eax
  paintbuffer_t *v38; // edi
  portable_samplepair_t *pbufrear; // ebx
  portable_samplepair_t *v40; // eax
  __int64 v41; // rdi
  portable_samplepair_t *v42; // [esp-18h] [ebp-1CCh]
  unsigned __int64 v43; // [esp-4h] [ebp-1B8h]
  portable_samplepair_t *v44; // [esp-4h] [ebp-1B8h]
  portable_samplepair_t *fgain_out; // [esp+0h] [ebp-1B4h]
  portable_samplepair_t *fgain_outa; // [esp+0h] [ebp-1B4h]
  portable_samplepair_t *fgain_outb; // [esp+0h] [ebp-1B4h]
  portable_samplepair_t *fgain_outc; // [esp+0h] [ebp-1B4h]
  portable_samplepair_t *fgain_outd; // [esp+0h] [ebp-1B4h]
  portable_samplepair_t *fgain_oute; // [esp+0h] [ebp-1B4h]
  float fgaina; // [esp+4h] [ebp-1B0h]
  CChannelList list; // [esp+8h] [ebp-1ACh] BYREF
  portable_samplepair_t *pbufcenter; // [esp+194h] [ebp-20h]
  paintbuffer_t *v55; // [esp+198h] [ebp-1Ch]
  float v56; // [esp+19Ch] [ebp-18h]
  float v57; // [esp+1A0h] [ebp-14h] BYREF
  float v58; // [esp+1A4h] [ebp-10h] BYREF
  unsigned __int64 v59; // [esp+1A8h] [ebp-Ch]
  bool v60; // [esp+1B1h] [ebp-3h]
  bool v61; // [esp+1B2h] [ebp-2h]
  bool fsurround; // [esp+1B3h] [ebp-1h]

  if ( dsp_enhance_stereo.m_pParent != nullptr )
    m_nValue = dsp_enhance_stereo.m_pParent->m_Value.m_nValue;
  else
    m_nValue = 0;
  v60 = m_nValue != 0;
  v55 = g_paintBuffers + 1;
  CheckNewDspPresets();
  if ( (snd_soundmixer.m_nFlags & 0x1000) != 0 )
  {
    m_pszString = "FCVAR_NEVER_AS_STRING";
  }
  else
  {
    m_pszString = snd_soundmixer.m_pParent->m_Value.m_pszString;
    if ( m_pszString == nullptr )
      m_pszString = (char *)defaultValue;
  }
  MXR_SetCurrentSoundMixer(szsoundmixer: m_pszString);
  if ( snd_profile.m_pParent != nullptr )
    g_snd_profile_type = snd_profile.m_pParent->m_Value.m_nValue;
  else
    g_snd_profile_type = 0;
  if ( dsp_off.m_pParent != nullptr )
    v7 = dsp_off.m_pParent->m_Value.m_nValue;
  else
    v7 = 0;
  g_bDspOff = v7 != 0;
  MIX_BuildChannelList((int)&list);
  g_dsp_volume = dsp_volume.m_pParent->m_Value.m_fValue;
  if ( g_AudioDevice->IsSurround(this: g_AudioDevice) )
  {
    if ( g_AudioDevice->IsSurroundCenter(this: g_AudioDevice) )
      m_fValue = dsp_vol_5ch.m_pParent->m_Value.m_fValue;
    else
      m_fValue = dsp_vol_4ch.m_pParent->m_Value.m_fValue;
  }
  else
  {
    m_fValue = dsp_vol_2ch.m_pParent->m_Value.m_fValue;
  }
  g_dsp_volume = m_fValue * g_dsp_volume;
  g_bdirectionalfx = !g_bDspOff
                  && dsp_facingaway.m_pParent != nullptr
                  && dsp_facingaway.m_pParent->m_Value.m_nValue != 0;
  SDEBUG_ShowAvgValue();
  v9 = HIDWORD(g_paintedtime);
  v10 = HIDWORD(endtime);
  if ( SHIDWORD(g_paintedtime) <= SHIDWORD(endtime) )
  {
    v11 = g_paintedtime;
    v12 = endtime;
    if ( SHIDWORD(g_paintedtime) < SHIDWORD(endtime) || (unsigned int)g_paintedtime < (unsigned int)endtime )
    {
      v43 = __PAIR64__(a1, a2);
      while ( 1 )
      {
        v13 = v12;
        HIDWORD(v59) = v10;
        v15 = __OFSUB__(__PAIR64__(v10, v12), __PAIR64__(v9, v11));
        v14 = (portable_samplepair_t *)((__PAIR64__(v10, v12) - __PAIR64__(v9, v11)) >> 32);
        pbufcenter = v14;
        LODWORD(v59) = v12;
        if ( (int)v14 >= 0 && (!(((int)v14 < 0) ^ v15 | (v14 == nullptr)) || v12 - v11 > 0x3FC) )
        {
          v59 = __PAIR64__(v9, v11) + 1020;
          v13 = v11 + 1020;
        }
        v16 = (portable_samplepair_t *)(v13 - v11);
        ((void (__thiscall *)(IAudioDevice *, unsigned int, _DWORD, _DWORD, portable_samplepair_t *))g_AudioDevice->MixBegin)(
          a1: g_AudioDevice,
          a2: v13 - v11,
          a3: v43,
          a4: HIDWORD(v43),
          a5: a3);
        MIX_UpsampleAllPaintbuffers(&list, end: __SPAIR64__(HIDWORD(v59), v13), count: (int)v16);
        if ( g_bdirectionalfx )
        {
          v17 = g_AudioDevice;
          v18 = g_AudioDevice->__vftable;
          fgain_out = MIX_GetPCenterFromIPaint(ipaintbuffer: 3);
          PRearFromIPaint = MIX_GetPRearFromIPaint(ipaintbuffer: 3);
          v18->ApplyDSPEffects(
            this: v17,
            a2: idsp_facingaway,
            a3: g_paintBuffers[3].pbuf,
            a4: PRearFromIPaint,
            a5: fgain_out,
            a6: (int)v16);
        }
        if ( !g_bDspOff && (*((_BYTE *)&list + 388) & 1) != 0 )
        {
          v20 = g_AudioDevice;
          v21 = g_AudioDevice->__vftable;
          fgain_outa = MIX_GetPCenterFromIPaint(ipaintbuffer: 5);
          v22 = MIX_GetPRearFromIPaint(ipaintbuffer: 5);
          v21->ApplyDSPEffects(
            this: v20,
            a2: idsp_speaker,
            a3: g_paintBuffers[5].pbuf,
            a4: v22,
            a5: fgain_outa,
            a6: (int)v16);
          MIX_ScalePaintBuffer(bufferIndex: (portable_samplepair_t *)5, count: (int)v16, fgain: 0.69999999);
          MIX_MixPaintbuffers(ibuf1: 5, ibuf2: (portable_samplepair_t *)2, ibuf3: 2, count: v16, fgain_out: 1.0);
          MIX_ScalePaintBuffer(bufferIndex: (portable_samplepair_t *)5, count: (int)v16, fgain: 0.43000001);
          MIX_MixPaintbuffers(ibuf1: 5, ibuf2: (portable_samplepair_t *)1, ibuf3: 1, count: v16, fgain_out: 1.0);
        }
        pbuf = g_paintBuffers[1].pbuf;
        v24 = g_AudioDevice->__vftable;
        fgain_outb = MIX_GetPCenterFromIPaint(ipaintbuffer: 1);
        v44 = MIX_GetPRearFromIPaint(ipaintbuffer: 1);
        idsp_room = Get_idsp_room();
        v24->ApplyDSPEffects(this: g_AudioDevice, a2: idsp_room, a3: pbuf, a4: v44, a5: fgain_outb, a6: (int)v16);
        v26 = v55;
        fsurround_center = v55->fsurround_center;
        fsurround = v55->fsurround;
        v61 = fsurround_center;
        if ( v60 && !g_bDspOff && !DSP_RoomDSPIsOff() )
        {
          MIX_ConvertBufferToSurround(ipaintbuffer: 1);
          v28 = g_AudioDevice->__vftable;
          fgain_outc = MIX_GetPCenterFromIPaint(ipaintbuffer: 1);
          v29 = MIX_GetPRearFromIPaint(ipaintbuffer: 1);
          v28->ApplyDSPEffects(
            this: g_AudioDevice,
            a2: idsp_spatial,
            a3: g_paintBuffers[1].pbuf,
            a4: v29,
            a5: fgain_outc,
            a6: (int)v16);
        }
        if ( g_bdirectionalfx )
        {
          MIX_MixPaintbuffers(
            ibuf1: 2,
            ibuf2: (portable_samplepair_t *)3,
            ibuf3: 0,
            count: v16,
            fgain_out: DSP_NOROOM_MIX);
          MIX_MixPaintbuffers(ibuf1: 1, ibuf2: nullptr, ibuf3: 0, count: v16, fgain_out: DSP_ROOM_MIX);
        }
        else
        {
          if ( g_bDspOff )
            v30 = 1.0;
          else
            v30 = DSP_ROOM_MIX;
          fgaina = v30;
          MIX_MixPaintbuffers(ibuf1: 1, ibuf2: (portable_samplepair_t *)2, ibuf3: 0, count: v16, fgain_out: fgaina);
        }
        v31 = v61;
        v26->fsurround = fsurround;
        v26->fsurround_center = v31;
        if ( bIsUnderwater )
        {
          v32 = g_AudioDevice;
          v33 = g_AudioDevice->__vftable;
          fgain_outd = MIX_GetPCenterFromIPaint(ipaintbuffer: 0);
          v34 = MIX_GetPRearFromIPaint(ipaintbuffer: 0);
          v33->ApplyDSPEffects(
            this: v32,
            a2: idsp_water,
            a3: g_paintBuffers->pbuf,
            a4: v34,
            a5: fgain_outd,
            a6: (int)v16);
        }
        v57 = 0.0;
        SDEBUG_GetAvgValue(ibuf: 0, count: (int)v16, pav: &v57);
        v35 = g_AudioDevice;
        v56 = (float)(int)v16;
        a3 = v16;
        sdebug_avg_in = (float)((float)((float)(int)v16 * v57) + (float)(sdebug_in_count * sdebug_avg_in))
                      / (float)((float)(int)v16 + sdebug_in_count);
        sdebug_in_count = (float)(int)v16 + sdebug_in_count;
        v36 = g_AudioDevice->__vftable;
        fgain_oute = MIX_GetPCenterFromIPaint(ipaintbuffer: 0);
        v37 = MIX_GetPRearFromIPaint(ipaintbuffer: 0);
        ((void (__thiscall *)(IAudioDevice *, int, portable_samplepair_t *, portable_samplepair_t *, portable_samplepair_t *))v36->ApplyDSPEffects)(
          a1: v35,
          a2: idsp_player,
          a3: g_paintBuffers->pbuf,
          a4: v37,
          a5: fgain_oute);
        v58 = 0.0;
        SDEBUG_GetAvgValue(ibuf: 0, count: (int)v16, pav: &v58);
        sdebug_avg_out = (float)((float)(v56 * v58) + (float)(sdebug_out_count * sdebug_avg_out))
                       / (float)(v56 + sdebug_out_count);
        sdebug_out_count = v56 + sdebug_out_count;
        MIX_MixPaintbuffers(ibuf1: 0, ibuf2: (portable_samplepair_t *)4, ibuf3: 0, count: v16, fgain_out: 1.0);
        v38 = g_paintBuffers;
        pbufrear = g_paintBuffers->pbufrear;
        v42 = g_paintBuffers->pbuf;
        pbufcenter = g_paintBuffers->pbufcenter;
        ClipStereo(pBuffer: v42, nCount: (unsigned int)v16);
        if ( v38->fsurround )
          ClipStereo(pBuffer: pbufrear, nCount: (unsigned int)v16);
        if ( v38->fsurround_center )
          ClipLeft(pBuffer: pbufcenter, nCount: (unsigned int)v16);
        g_curpaintbuffer = g_paintBuffers->pbuf;
        if ( g_paintBuffers->fsurround )
        {
          g_currearpaintbuffer = g_paintBuffers->pbufrear;
          g_curcenterpaintbuffer = nullptr;
          if ( !g_paintBuffers->fsurround_center )
            goto LABEL_59;
          v40 = g_paintBuffers->pbufcenter;
        }
        else
        {
          v40 = nullptr;
          g_currearpaintbuffer = nullptr;
        }
        g_curcenterpaintbuffer = v40;
LABEL_59:
        v41 = v59;
        v43 = v59;
        ((void (__thiscall *)(IAudioDevice *))g_AudioDevice->TransferSamples)(a1: g_AudioDevice);
        v9 = HIDWORD(v41);
        v11 = v41;
        g_paintedtime = v41;
        if ( v41 >= endtime )
          return;
        v10 = HIDWORD(endtime);
        v12 = endtime;
      }
    }
  }
}

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x1002B440
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
// Address: 0x1002B4B0
// Name: double MIX_GetMaxRate(double,int)
// Source: json
//------------------------------------------------------------------------------
double __cdecl MIX_GetMaxRate(double rate)
{
  double result; // st7

  result = rate;
  if ( rate > 2.0 )
  {
    result = 8.031372549019608;
    if ( rate <= 8.031372549019608 )
      return rate;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1002B4E0
// Name: void S_Interpolate2xCubic(struct portable_samplepair_t __near *,struct portable_samplepair_t __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl S_Interpolate2xCubic(
        portable_samplepair_t *pbuffer,
        portable_samplepair_t *pfiltermem,
        int cfltmem,
        int count)
{
  portable_samplepair_t *v4; // edx
  int v5; // esi
  int v6; // ecx
  portable_samplepair_t *v7; // edi
  int v8; // esi
  int v9; // eax
  int *p_left; // eax
  portable_samplepair_t *v11; // ebx
  int v12; // ecx
  int right; // edi
  int v14; // ecx
  int v15; // ebx
  int v16; // kr20_4
  int v17; // eax
  int v18; // eax
  int v19; // [esp+Ch] [ebp-18h]
  int x2; // [esp+10h] [ebp-14h]
  portable_samplepair_t *psamp1; // [esp+14h] [ebp-10h]
  portable_samplepair_t *psamp2; // [esp+18h] [ebp-Ch]
  int psamp2a; // [esp+18h] [ebp-Ch]
  portable_samplepair_t *psamp0; // [esp+20h] [ebp-4h]

  v4 = pfiltermem;
  v5 = 2 * count;
  v6 = 0;
  v7 = pbuffer;
  if ( count > 0 )
  {
    v8 = 0;
    do
    {
      if ( v6 != 0 )
      {
        if ( v6 == 1 )
        {
          v9 = (int)&v4[1];
        }
        else if ( v6 == 2 )
        {
          v9 = (int)&v4[2];
        }
        else
        {
          v9 = (int)&v7[2 * v6 - 5];
        }
        psamp0 = (portable_samplepair_t *)v9;
      }
      else
      {
        psamp0 = v4;
      }
      if ( v6 == -1 )
      {
        p_left = &v4->left;
        psamp1 = v4;
      }
      else
      {
        if ( v6 != 0 )
        {
          if ( v6 == 1 )
            p_left = &v4[2].left;
          else
            p_left = &v7[2 * v6 - 3].left;
        }
        else
        {
          p_left = &v4[1].left;
        }
        psamp1 = (portable_samplepair_t *)p_left;
      }
      v19 = v6 + 1;
      if ( v6 == -2 )
      {
        v11 = v4;
        psamp2 = v4;
      }
      else
      {
        if ( v6 == -1 )
        {
          v11 = v4 + 1;
        }
        else if ( v6 != 0 )
        {
          v11 = &v7[2 * v6 - 1];
        }
        else
        {
          v11 = v4 + 2;
        }
        psamp2 = v11;
      }
      v12 = v6 + 2;
      if ( v12 != -1 )
      {
        if ( v12 != 0 )
        {
          if ( v12 == 1 )
            v4 += 2;
          else
            v4 = &v7[2 * v12 - 3];
        }
        else
        {
          ++v4;
        }
      }
      g_temppaintbuffer[v8].left = *p_left;
      g_temppaintbuffer[v8].right = p_left[1];
      g_temppaintbuffer[v8 + 1].left = (psamp0->left + 2 * v11->left - (*p_left + v4->left + 4 * *p_left) / 2) / 4
                                     + *p_left
                                     + (v4->left + 3 * (*p_left - v11->left) - psamp0->left) / 2 / 8
                                     + (psamp2->left - psamp0->left) / 2 / 2;
      right = psamp0->right;
      v14 = psamp1->right;
      v15 = psamp2->right;
      x2 = v4->right;
      psamp2a = (right + 2 * v15 - (v14 + x2 + 4 * v14) / 2) / 4;
      v8 += 2;
      v16 = (x2 + 3 * (v14 - v15) - right) / 2;
      v17 = v15 - right;
      v7 = pbuffer;
      v4 = pfiltermem;
      g_temppaintbuffer[v8 - 1].right = psamp2a + v14 + v16 / 8 + v17 / 2 / 2;
      v6 = v19;
    }
    while ( v19 < count );
    v5 = 2 * count;
  }
  v4->left = v7[v5 - 5].left;
  v4->right = *((_DWORD *)&v7[v5 - 4] - 1);
  v4[1].left = v7[v5 - 3].left;
  v4[1].right = *((_DWORD *)&v7[v5 - 2] - 1);
  v4[2].left = v7[v5 - 1].left;
  v18 = 0;
  for ( v4[2].right = v7[v5 - 1].right; v18 < v5; ++v18 )
    v7[v18] = g_temppaintbuffer[v18];
}

//------------------------------------------------------------------------------
// Address: 0x1002B710
// Name: void S_Interpolate2xLinear(struct portable_samplepair_t __near *,struct portable_samplepair_t __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl S_Interpolate2xLinear(
        portable_samplepair_t *pbuffer,
        portable_samplepair_t *pfiltermem,
        int cfltmem,
        int count)
{
  int *p_right; // eax
  unsigned int v5; // ecx
  int v6; // ebx

  pbuffer->left = (pfiltermem->left + pbuffer->left) >> 1;
  pbuffer->right = (pbuffer->right + pfiltermem->right) >> 1;
  if ( 2 * count > 2 )
  {
    p_right = &pbuffer[2].right;
    v5 = ((unsigned int)(2 * count - 3) >> 1) + 1;
    do
    {
      v6 = *(p_right - 1) + *(p_right - 3);
      p_right += 4;
      *(p_right - 5) = v6 >> 1;
      --v5;
      *(p_right - 4) = (*(p_right - 4) + *(p_right - 6)) >> 1;
    }
    while ( v5 != 0 );
  }
  *pfiltermem = pbuffer[2 * count - 1];
}

//------------------------------------------------------------------------------
// Address: 0x1002B770
// Name: void S_Interpolate2xLinear_2(int,struct portable_samplepair_t __near *,struct portable_samplepair_t __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl S_Interpolate2xLinear_2(int count, portable_samplepair_t *pbuffer, portable_samplepair_t *pfiltermem)
{
  portable_samplepair_t *v3; // ecx
  int left; // esi
  portable_samplepair_t *v5; // edx
  int right; // edi
  portable_samplepair_t *v7; // eax
  portable_samplepair_t *v8; // edx
  int *p_left; // ecx
  int v10; // esi
  int v11; // edi
  int v12; // esi
  int v13; // edi
  int v14; // esi
  int v15; // edi
  int v16; // esi
  int v17; // edi
  int v18; // esi
  int v19; // edi
  int v20; // esi
  int v21; // edi
  int v22; // esi
  int v23; // edi
  int *p_right; // eax
  portable_samplepair_t *v25; // [esp+Ch] [ebp-4h]
  unsigned int counta; // [esp+18h] [ebp+8h]

  v3 = pbuffer;
  left = pbuffer[count - 1].left;
  v5 = &pbuffer[count - 1];
  right = v5->right;
  v7 = &pbuffer[2 * count - 1];
  v8 = v5 - 1;
  v25 = v7;
  if ( count - 1 >= 8 )
  {
    p_left = &v8[-1].left;
    counta = (unsigned int)(count - 1) >> 3;
    do
    {
      v7->left = left;
      v7->right = right;
      v7[-1].left = (left + v8->left) >> 1;
      v7[-1].right = (right + p_left[3]) >> 1;
      v10 = v8->left;
      v11 = v8->right;
      v7[-2].left = v8->left;
      v7[-2].right = v11;
      v7[-3].left = (v10 + *p_left) >> 1;
      v7[-3].right = (v11 + p_left[1]) >> 1;
      v12 = *p_left;
      v13 = p_left[1];
      v7[-4].left = *p_left;
      v7[-4].right = v13;
      v7[-5].left = (v12 + *(p_left - 2)) >> 1;
      v7[-5].right = (v13 + *(p_left - 1)) >> 1;
      v14 = *(p_left - 2);
      v15 = *(p_left - 1);
      v7[-6].left = v14;
      v7[-6].right = v15;
      v7[-7].left = (v14 + *(p_left - 4)) >> 1;
      v7[-7].right = (v15 + *(p_left - 3)) >> 1;
      v16 = *(p_left - 4);
      v17 = *(p_left - 3);
      v7[-8].left = v16;
      v7[-8].right = v17;
      v7[-9].left = (v16 + *(p_left - 6)) >> 1;
      v7[-9].right = (v17 + *(p_left - 5)) >> 1;
      v18 = *(p_left - 6);
      v19 = *(p_left - 5);
      v7[-10].left = v18;
      v7[-10].right = v19;
      v7[-11].left = (v18 + *(p_left - 8)) >> 1;
      v7[-11].right = (v19 + *(p_left - 7)) >> 1;
      v20 = *(p_left - 8);
      v21 = *(p_left - 7);
      v7[-12].left = v20;
      v7[-12].right = v21;
      v7[-13].left = (v20 + *(p_left - 10)) >> 1;
      v7[-13].right = (v21 + *(p_left - 9)) >> 1;
      v22 = *(p_left - 10);
      v23 = *(p_left - 9);
      v7[-14].left = v22;
      v7[-14].right = v23;
      v7[-15].left = (v22 + *(p_left - 12)) >> 1;
      v7[-15].right = (v23 + *(p_left - 11)) >> 1;
      left = *(p_left - 12);
      right = *(p_left - 11);
      v8 -= 8;
      p_left -= 16;
      v7 -= 16;
      --counta;
    }
    while ( counta != 0 );
    v3 = pbuffer;
  }
  if ( v8 >= v3 )
  {
    p_right = &v7[-1].right;
    do
    {
      p_right[1] = left;
      p_right[2] = right;
      *(p_right - 1) = (left + v8->left) >> 1;
      *p_right = (right + v8->right) >> 1;
      left = v8->left;
      right = v8->right;
      --v8;
      p_right -= 4;
    }
    while ( v8 >= v3 );
  }
  v3[1].left = left;
  v3[1].right = right;
  v3->left = (left + pfiltermem->left) >> 1;
  v3->right = (right + pfiltermem->right) >> 1;
  *pfiltermem = *v25;
}

//------------------------------------------------------------------------------
// Address: 0x1002B920
// Name: void S_Interpolate2xLinear_3(int,struct portable_samplepair_t __near *,struct portable_samplepair_t __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl S_Interpolate2xLinear_3(int count, portable_samplepair_t *pbuffer, portable_samplepair_t *pfiltermem)
{
  portable_samplepair_t *v3; // ebx
  int left; // edx
  int right; // esi
  portable_samplepair_t *v6; // edi
  portable_samplepair_t *v7; // ecx
  int *p_right; // eax
  int v9; // edi
  int v10; // ebx
  int v11; // edx
  int v12; // esi
  int v13; // ebx
  int v14; // edi
  int v15; // edx
  int v16; // esi
  int v17; // ebx
  int v18; // edi
  int v19; // edx
  int v20; // esi
  int v21; // edi
  int v22; // ebx
  bool v23; // zf
  int *v24; // eax
  int v25; // edi
  int v26; // edx
  int v27; // eax
  int v28; // esi
  portable_samplepair_t *v29; // [esp+Ch] [ebp-8h]
  int sample; // [esp+10h] [ebp-4h]
  int samplea; // [esp+10h] [ebp-4h]
  int nLeft; // [esp+1Ch] [ebp+8h]
  int nRight; // [esp+20h] [ebp+Ch]

  v3 = pbuffer;
  left = pbuffer[count - 1].left;
  right = pbuffer[count - 1].right;
  v6 = &pbuffer[2 * count - 1];
  v7 = &pbuffer[count - 2];
  sample = count - 1;
  v29 = v6;
  nLeft = (int)v6;
  if ( sample >= 8 )
  {
    p_right = &v6[-2].right;
    samplea = (unsigned int)sample >> 3;
    do
    {
      v6->left = left;
      p_right[4] = right;
      v9 = v7->left;
      v10 = v7->right;
      p_right[1] = (v7->left + left) >> 1;
      p_right[2] = (v10 + right) >> 1;
      *(p_right - 1) = v9;
      *p_right = v10;
      v11 = v7[-1].left;
      v12 = v7[-1].right;
      *(p_right - 3) = (v11 + v9) >> 1;
      *(p_right - 2) = (v12 + v10) >> 1;
      *(p_right - 5) = v11;
      *(p_right - 4) = v12;
      v13 = v7[-2].right;
      v14 = v7[-2].left;
      *(p_right - 7) = (v14 + v11) >> 1;
      *(p_right - 6) = (v13 + v12) >> 1;
      *(p_right - 9) = v14;
      *(p_right - 8) = v13;
      v15 = v7[-3].left;
      v16 = v7[-3].right;
      *(p_right - 11) = (v15 + v14) >> 1;
      *(p_right - 10) = (v16 + v13) >> 1;
      *(p_right - 13) = v15;
      *(p_right - 12) = v16;
      v17 = v7[-4].right;
      v18 = v7[-4].left;
      *(p_right - 15) = (v18 + v15) >> 1;
      *(p_right - 14) = (v17 + v16) >> 1;
      *(p_right - 17) = v18;
      *(p_right - 16) = v17;
      v19 = v7[-5].left;
      v20 = v7[-5].right;
      *(p_right - 19) = (v19 + v18) >> 1;
      *(p_right - 18) = (v20 + v17) >> 1;
      *(p_right - 21) = v19;
      *(p_right - 20) = v20;
      v21 = v7[-6].left;
      v22 = v7[-6].right;
      *(p_right - 23) = (v21 + v19) >> 1;
      *(p_right - 22) = (v22 + v20) >> 1;
      *(p_right - 25) = v21;
      *(p_right - 24) = v22;
      left = v7[-7].left;
      right = v7[-7].right;
      *(p_right - 27) = (left + v21) >> 1;
      *(p_right - 26) = (right + v22) >> 1;
      v7 -= 8;
      v6 = (portable_samplepair_t *)(nLeft - 128);
      p_right -= 32;
      v23 = samplea-- == 1;
      nLeft -= 128;
    }
    while ( !v23 );
    v3 = pbuffer;
  }
  if ( v7 >= v3 )
  {
    v24 = &v6->right;
    do
    {
      *(v24 - 1) = left;
      *v24 = right;
      nRight = v7->right;
      v25 = v7->left;
      *(v24 - 3) = (v7->left + left) >> 1;
      v26 = right + nRight;
      right = nRight;
      *(v24 - 2) = v26 >> 1;
      --v7;
      v24 -= 4;
      left = v25;
    }
    while ( v7 >= v3 );
  }
  v3[1].right = right;
  v3[1].left = left;
  v27 = right + pfiltermem->right;
  v28 = pfiltermem->left;
  v3->right = v27 >> 1;
  v3->left = (left + v28) >> 1;
  *pfiltermem = *v29;
}

//------------------------------------------------------------------------------
// Address: 0x1002BAC0
// Name: _MIX_SetCurrentPaintbuffer
// Source: json
//------------------------------------------------------------------------------
void __cdecl MIX_SetCurrentPaintbuffer(int ipaintbuffer)
{
  paintbuffer_t *v1; // eax

  v1 = &g_paintBuffers[ipaintbuffer];
  g_curpaintbuffer = v1->pbuf;
  if ( v1->fsurround )
  {
    g_currearpaintbuffer = v1->pbufrear;
    g_curcenterpaintbuffer = nullptr;
    if ( v1->fsurround_center )
      g_curcenterpaintbuffer = v1->pbufcenter;
  }
  else
  {
    g_currearpaintbuffer = nullptr;
    g_curcenterpaintbuffer = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002BB10
// Name: _MIX_GetCurrentPaintbufferIndex
// Source: json
//------------------------------------------------------------------------------
int __cdecl MIX_GetCurrentPaintbufferIndex()
{
  int result; // eax
  portable_samplepair_t **i; // ecx

  result = 0;
  for ( i = &g_paintBuffers->pbuf; g_curpaintbuffer != *i; i += 78 )
  {
    if ( ++result >= 6 )
      return 0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1002BB40
// Name: _MIX_GetCurrentPaintbufferPtr
// Source: json
//------------------------------------------------------------------------------
paintbuffer_t *__cdecl MIX_GetCurrentPaintbufferPtr()
{
  int v0; // eax
  portable_samplepair_t **i; // ecx

  v0 = 0;
  for ( i = &g_paintBuffers->pbuf; g_curpaintbuffer != *i; i += 78 )
  {
    if ( ++v0 >= 6 )
    {
      v0 = 0;
      return &g_paintBuffers[v0];
    }
  }
  return &g_paintBuffers[v0];
}

//------------------------------------------------------------------------------
// Address: 0x1002BB70
// Name: struct portable_samplepair_t __near * MIX_GetPRearFromIPaint(int)
// Source: json
//------------------------------------------------------------------------------
portable_samplepair_t *__cdecl MIX_GetPRearFromIPaint(int ipaintbuffer)
{
  if ( g_paintBuffers[ipaintbuffer].fsurround )
    return g_paintBuffers[ipaintbuffer].pbufrear;
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1002BBA0
// Name: struct portable_samplepair_t __near * MIX_GetPCenterFromIPaint(int)
// Source: json
//------------------------------------------------------------------------------
portable_samplepair_t *__cdecl MIX_GetPCenterFromIPaint(int ipaintbuffer)
{
  if ( g_paintBuffers[ipaintbuffer].fsurround_center )
    return g_paintBuffers[ipaintbuffer].pbufcenter;
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1002BBD0
// Name: void MIX_ConvertBufferToSurround(int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MIX_ConvertBufferToSurround(int ipaintbuffer)
{
  int v1; // esi
  paintbuffer_t *v2; // edi
  portable_samplepair_t *pbuf; // edi
  portable_samplepair_t *pbufrear; // ecx
  portable_samplepair_t *pbufcenter; // esi

  v1 = ipaintbuffer;
  v2 = &g_paintBuffers[ipaintbuffer];
  if ( g_AudioDevice->IsSurround(this: g_AudioDevice) )
  {
    v2->fsurround = g_AudioDevice->IsSurround(this: g_AudioDevice);
    v2->fsurround_center = g_AudioDevice->IsSurroundCenter(this: g_AudioDevice);
    pbuf = g_paintBuffers[v1].pbuf;
    if ( g_paintBuffers[v1].fsurround )
      pbufrear = g_paintBuffers[v1].pbufrear;
    else
      pbufrear = nullptr;
    if ( g_paintBuffers[v1].fsurround_center )
      pbufcenter = g_paintBuffers[v1].pbufcenter;
    else
      pbufcenter = nullptr;
    _V_memcpy(dest: pbufrear, src: pbuf, count: 8160);
    if ( g_AudioDevice->IsSurroundCenter(this: g_AudioDevice) )
      _V_memcpy(dest: pbufcenter, src: pbuf, count: 8160);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002BC80
// Name: _MIX_ClearAllPaintBuffers
// Source: json
//------------------------------------------------------------------------------
void __cdecl MIX_ClearAllPaintBuffers(int SampleCount, bool clearFilters)
{
  paintbuffer_t *v2; // eax
  int v3; // edi
  int i; // esi
  portable_samplepair_t *pbuf; // ecx
  portable_samplepair_t *pbufrear; // ecx
  portable_samplepair_t *pbufcenter; // ecx

  v2 = g_paintBuffers;
  if ( g_paintBuffers != nullptr )
  {
    v3 = SampleCount;
    if ( SampleCount >= 1020 )
      v3 = 1020;
    for ( i = 0; i < 6; ++i )
    {
      pbuf = v2[i].pbuf;
      if ( pbuf != nullptr )
      {
        _V_memset(dest: pbuf, fill: 0, count: 8 * v3 + 8);
        v2 = g_paintBuffers;
      }
      pbufrear = v2[i].pbufrear;
      if ( pbufrear != nullptr )
      {
        _V_memset(dest: pbufrear, fill: 0, count: 8 * v3 + 8);
        v2 = g_paintBuffers;
      }
      pbufcenter = v2[i].pbufcenter;
      if ( pbufcenter != nullptr )
      {
        _V_memset(dest: pbufcenter, fill: 0, count: 8 * v3 + 8);
        v2 = g_paintBuffers;
      }
      if ( clearFilters )
      {
        _V_memset(dest: v2[i].fltmem, fill: 0, count: 96);
        _V_memset(dest: g_paintBuffers[i].fltmemrear, fill: 0, count: 96);
        _V_memset(dest: g_paintBuffers[i].fltmemcenter, fill: 0, count: 96);
        v2 = g_paintBuffers;
      }
    }
    if ( clearFilters )
    {
      v2->ifilter = 0;
      g_paintBuffers[1].ifilter = 0;
      g_paintBuffers[2].ifilter = 0;
      g_paintBuffers[3].ifilter = 0;
      g_paintBuffers[4].ifilter = 0;
      g_paintBuffers[5].ifilter = 0;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002C0D0
// Name: void Mix555_SIMD(class CMixData __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Mix555_SIMD(__m128i *data)
{
  int v2; // eax
  const __m128i *v3; // esi
  portable_samplepair_t *v4; // eax
  const __m128i *v5; // edi
  int v6; // ecx
  __m128i *v7; // ecx
  __m128i si128; // xmm4
  __m128i v9; // xmm1
  __m128i v10; // xmm2
  __m128i v11; // xmm3
  __m128i v12; // xmm1
  __m128i v13; // xmm2
  __m128i v14; // xmm3
  __m128i v15; // xmm4
  __m128i v16; // xmm0
  __m128i v17; // xmm1
  __m128i v18; // xmm2
  const __m128i *v19; // edx
  __m128i v20; // xmm2
  __m128i v21; // xmm3
  __m128i v22; // xmm4
  __m128i *v23; // edx
  bool v24; // zf
  int *v25; // ecx
  int v26; // edx
  int v27; // edi
  int v28; // esi
  int v29; // [esp+8h] [ebp-30h]
  int v30; // [esp+Ch] [ebp-2Ch]
  int v31; // [esp+10h] [ebp-28h]
  int v32; // [esp+14h] [ebp-24h]
  int v33; // [esp+18h] [ebp-20h]
  unsigned int v34; // [esp+1Ch] [ebp-1Ch]
  int v35; // [esp+1Ch] [ebp-1Ch]
  __m128i *pCenterDst; // [esp+20h] [ebp-18h]
  __m128i *pCenterDsta; // [esp+20h] [ebp-18h]
  __m128i *pRearDst; // [esp+24h] [ebp-14h]
  __m128i *pRearDsta; // [esp+24h] [ebp-14h]
  int nCount; // [esp+28h] [ebp-10h]
  __m128i *pCenterSrc1; // [esp+2Ch] [ebp-Ch]
  __m128i *pCenterSrc2; // [esp+30h] [ebp-8h]
  __m128i *pCenterSrc2a; // [esp+30h] [ebp-8h]
  __m128i *pRearSrc1; // [esp+34h] [ebp-4h]
  __m128i *pRearSrc1a; // [esp+34h] [ebp-4h]
  __m128i *pRearSrc2; // [esp+40h] [ebp+8h]
  __m128i *pRearSrc2a; // [esp+40h] [ebp+8h]

  v2 = data->m128i_i32[0];
  pRearDst = (__m128i *)data[1].m128i_i32[2];
  pRearSrc1 = (__m128i *)data[1].m128i_i32[0];
  pRearSrc2 = (__m128i *)data[1].m128i_i32[1];
  v3 = (const __m128i *)data->m128i_i32[1];
  nCount = v2;
  v4 = (portable_samplepair_t *)data->m128i_i32[3];
  pCenterDst = (__m128i *)data[2].m128i_i32[1];
  v5 = (const __m128i *)data->m128i_i32[2];
  pCenterSrc2 = (__m128i *)data[2].m128i_i32[0];
  pCenterSrc1 = (__m128i *)data[1].m128i_i32[3];
  v6 = nCount;
  if ( (((unsigned __int8)v4
       | (unsigned __int8)((unsigned __int8)v3
                         | (unsigned __int8)v5
                         | (unsigned __int8)pRearDst
                         | (unsigned __int8)pRearSrc1
                         | (unsigned __int8)pRearSrc2
                         | (unsigned __int8)pCenterDst
                         | (unsigned __int8)pCenterSrc1
                         | (unsigned __int8)pCenterSrc2))
      & 0xF) == 0
    && nCount >= 8 )
  {
    v34 = (unsigned int)nCount >> 3;
    nCount -= 8 * ((unsigned int)nCount >> 3);
    v7 = pRearDst;
    do
    {
      si128 = _mm_load_si128(v5);
      v9 = _mm_add_epi32(_mm_load_si128(v3 + 2), _mm_load_si128(v5 + 2));
      v10 = _mm_add_epi32(_mm_load_si128(v3 + 3), _mm_load_si128(v5 + 3));
      v11 = _mm_load_si128(v3);
      *(__m128i *)&v4[2].left = _mm_add_epi32(_mm_load_si128(v3 + 1), _mm_load_si128(v5 + 1));
      *(__m128i *)&v4[4].left = v9;
      *(__m128i *)&v4[6].left = v10;
      *(__m128i *)&v4->left = _mm_add_epi32(v11, si128);
      v12 = _mm_add_epi32(_mm_load_si128(pRearSrc1 + 2), _mm_load_si128(pRearSrc2 + 2));
      v13 = _mm_add_epi32(_mm_load_si128(pRearSrc1 + 3), _mm_load_si128(pRearSrc2 + 3));
      v14 = _mm_load_si128(pRearSrc1);
      v15 = _mm_load_si128(pRearSrc2);
      v7[1] = _mm_add_epi32(_mm_load_si128(pRearSrc1 + 1), _mm_load_si128(pRearSrc2 + 1));
      v7[2] = v12;
      v7[3] = v13;
      pRearSrc1 += 4;
      pRearSrc2 += 4;
      *v7 = _mm_add_epi32(v14, v15);
      v16 = _mm_add_epi32(_mm_load_si128(pCenterSrc1 + 1), _mm_load_si128(pCenterSrc2 + 1));
      v17 = _mm_add_epi32(_mm_load_si128(pCenterSrc1 + 2), _mm_load_si128(pCenterSrc2 + 2));
      v18 = _mm_load_si128(pCenterSrc1 + 3);
      v19 = pCenterSrc1;
      pCenterSrc1 += 4;
      v20 = _mm_add_epi32(v18, _mm_load_si128(pCenterSrc2 + 3));
      v21 = _mm_load_si128(v19);
      v22 = _mm_load_si128(pCenterSrc2);
      v23 = pCenterDst;
      pCenterDst += 4;
      pCenterSrc2 += 4;
      v4 += 8;
      v3 += 4;
      v5 += 4;
      v7 += 4;
      v24 = v34-- == 1;
      *v23 = _mm_add_epi32(v21, v22);
      v23[1] = v16;
      v23[2] = v17;
      v23[3] = v20;
    }
    while ( !v24 );
    pRearDst = v7;
    v6 = nCount;
  }
  if ( v6 > 0 )
  {
    v33 = (char *)v5 - (char *)v3;
    v32 = (char *)v4 - (char *)v3;
    v25 = &v3->m128i_i32[1];
    v29 = (char *)pRearSrc2 - (char *)v3;
    v30 = (char *)pRearSrc1 - (char *)v3;
    v26 = (char *)pRearDst - (char *)v3;
    v31 = (char *)pRearSrc2 - (char *)v4;
    pRearSrc2a = (__m128i *)((char *)pRearSrc1 - (char *)v4);
    pRearDsta = (__m128i *)((char *)pRearDst - (char *)v4);
    pCenterSrc2a = (__m128i *)((char *)pCenterSrc2 - (char *)v4);
    pRearSrc1a = (__m128i *)((char *)pCenterDst - (char *)v4);
    v27 = (char *)v5 - (char *)v4;
    v35 = v27;
    pCenterDsta = (__m128i *)((char *)pCenterSrc1 - (char *)v4);
    while ( 1 )
    {
      v4->left = *(v25 - 1) + *(int *)((char *)&v4->left + v27);
      v28 = *v25 + *(int *)((char *)v25 + v33);
      v25 += 2;
      *(int *)((char *)v25 + v32 - 8) = v28;
      *(int *)((char *)pRearDsta->m128i_i32 + (_DWORD)v4) = *(int *)((char *)&v4->left + v31)
                                                          + *(int *)((char *)pRearSrc2a->m128i_i32 + (_DWORD)v4);
      *(int *)((char *)v25 + v26 - 8) = *(int *)((char *)v25 + v29 - 8) + *(int *)((char *)v25 + v30 - 8);
      *(int *)((char *)pRearSrc1a->m128i_i32 + (_DWORD)v4) = *(int *)((char *)pCenterSrc2a->m128i_i32 + (_DWORD)v4)
                                                           + *(int *)((char *)pCenterDsta->m128i_i32 + (_DWORD)v4);
      ++v4;
      if ( --nCount <= 0 )
        break;
      v27 = v35;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002C360
// Name: void Mix555(class CMixData __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Mix555(CMixData *data)
{
  int i; // eax

  for ( i = 0; i < data->count; ++i )
  {
    data->pbuf3[i].left = data->pbuf1[i].left + data->pbuf2[i].left;
    data->pbuf3[i].right = data->pbuf1[i].right + data->pbuf2[i].right;
    data->pbufrear3[i].left = data->pbufrear1[i].left + data->pbufrear2[i].left;
    data->pbufrear3[i].right = data->pbufrear1[i].right + data->pbufrear2[i].right;
    data->pbufcenter3[i].left = data->pbufcenter1[i].left + data->pbufcenter2[i].left;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002C3E0
// Name: void MIX_ScalePaintBuffer(int,int,float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MIX_ScalePaintBuffer(portable_samplepair_t *bufferIndex, int count, float fgain)
{
  int v3; // eax
  paintbuffer_t *v4; // edi
  portable_samplepair_t *pbuf; // edx
  int v6; // ecx
  int j; // eax
  int v8; // ebx
  int v9; // esi
  int *p_right; // eax
  int i; // eax
  portable_samplepair_t *pbufcenter; // [esp+0h] [ebp-8h]
  int v13; // [esp+4h] [ebp-4h]
  portable_samplepair_t *pbufrear; // [esp+10h] [ebp+8h]

  v3 = 312 * (_DWORD)bufferIndex;
  v4 = g_paintBuffers;
  pbuf = g_paintBuffers[(_DWORD)bufferIndex].pbuf;
  pbufrear = g_paintBuffers[(_DWORD)bufferIndex].pbufrear;
  pbufcenter = *(portable_samplepair_t **)((char *)&g_paintBuffers->pbufcenter + v3);
  v6 = (int)(float)(fgain * 256.0);
  v13 = v3;
  if ( v6 != 256 )
  {
    if ( *(&g_paintBuffers->fsurround + v3) )
    {
      v8 = count;
      v9 = 0;
      if ( count > 0 )
      {
        p_right = &pbufrear->right;
        do
        {
          pbuf[v9].left = (v6 * pbuf[v9].left) >> 8;
          *(int *)((char *)p_right + (char *)pbuf - (char *)pbufrear) = (v6
                                                                       * *(int *)((char *)p_right
                                                                                + (char *)pbuf
                                                                                - (char *)pbufrear)) >> 8;
          *(p_right - 1) = (v6 * *(p_right - 1)) >> 8;
          *p_right = (v6 * *p_right) >> 8;
          v8 = count;
          ++v9;
          p_right += 2;
        }
        while ( v9 < count );
        v4 = g_paintBuffers;
        v3 = v13;
      }
      if ( *(&v4->fsurround_center + v3) )
      {
        for ( i = 0; i < v8; ++i )
          pbufcenter[i].left = (v6 * pbufcenter[i].left) >> 8;
      }
    }
    else
    {
      for ( j = 0; j < count; ++j )
      {
        pbuf[j].left = (v6 * pbuf[j].left) >> 8;
        pbuf[j].right = (v6 * pbuf[j].right) >> 8;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002C4F0
// Name: void SDEBUG_ShowAvgValue(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SDEBUG_ShowAvgValue()
{
  if ( sdebug_in_count > 132300.0 )
  {
    if ( (double)(int)sdebug_avg_in > 20.0 && (double)(int)sdebug_avg_out > 20.0 )
      DevMsg(
        a1: "dsp avg gain:%1.2f in:%1.2f out:%1.2f 1/gain:%1.2f\n",
        sdebug_avg_out / sdebug_avg_in,
        sdebug_avg_in,
        sdebug_avg_out,
        sdebug_avg_in / sdebug_avg_out);
    sdebug_avg_in = 0.0;
    sdebug_avg_out = 0.0;
    sdebug_in_count = 0.0;
    sdebug_out_count = 0.0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002C5A0
// Name: ChannelVolComparator
// Source: json
//------------------------------------------------------------------------------
int __cdecl ChannelVolComparator(_DWORD *a, _DWORD *b)
{
  return b[1] - a[1];
}

//------------------------------------------------------------------------------
// Address: 0x1002C5C0
// Name: void Snd_WriteLinearBlastStereo16(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Snd_WriteLinearBlastStereo16()
{
  int *v0; // ebx
  __int16 *v1; // edi
  int v2; // ecx
  int v3; // esi
  int v4; // eax
  int v5; // edx

  v0 = snd_p;
  v1 = snd_out;
  v2 = snd_linear_count;
  v3 = snd_vol;
  do
  {
    v4 = (v3 * v0[v2 - 2]) >> 8;
    if ( v4 > 0x7FFF )
    {
      LOWORD(v4) = 0x7FFF;
    }
    else if ( v4 < -32768 )
    {
      LOWORD(v4) = 0x8000;
    }
    v5 = (v3 * v0[v2 - 1]) >> 8;
    if ( v5 > 0x7FFF )
    {
      v5 = 0x7FFF;
    }
    else if ( v5 < -32768 )
    {
      v5 = -32768;
    }
    *(_DWORD *)&v1[v2 - 2] = (unsigned __int16)v4 | (v5 << 16);
    v2 -= 2;
  }
  while ( v2 != 0 );
}

//------------------------------------------------------------------------------
// Address: 0x1002C640
// Name: void SND_InitScaletable(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SND_InitScaletable()
{
  int v0; // edx
  int *v1; // ecx
  int i; // eax

  v0 = 0;
  v1 = snd_scaletable[0];
  do
  {
    for ( i = 0; i < 256; ++i )
      *v1++ = 2 * v0 * (char)i;
    ++v0;
  }
  while ( (int)v1 < (int)&g_dsp_volume );
}

//------------------------------------------------------------------------------
// Address: 0x1002C670
// Name: void SND_PaintChannelFrom8(struct portable_samplepair_t __near *,int __near *,unsigned char __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SND_PaintChannelFrom8(portable_samplepair_t *pOutput, int *volume, unsigned __int8 *pData8, int count)
{
  int v4; // ecx
  char *v5; // eax
  char *v6; // edx
  int v7; // ebx
  int v8; // ebp
  int v9; // ebp
  int v10; // ebp
  _DWORD v11[4]; // [esp+0h] [ebp-20h]
  _BYTE v12[16]; // [esp+10h] [ebp-10h] BYREF

  tempStore = (int)pOutput;
  _InterlockedExchange(&tempStore, (__int32)v12);
  v4 = count;
  v5 = (char *)snd_scaletable + 512 * (*volume & 0xFE);
  v6 = (char *)snd_scaletable + 512 * (volume[1] & 0xFE);
  v7 = pData8[count - 1];
  if ( (count & 1) == 0
    || (v8 = v11[2 * count + 3] + *(_DWORD *)&v6[4 * v7],
        v11[2 * count + 2] += *(_DWORD *)&v5[4 * v7],
        v11[2 * count + 3] = v8,
        LOBYTE(v7) = pData8[count - 2],
        v4 = count - 1,
        count != 1) )
  {
    do
    {
      v9 = v11[2 * v4 + 3] + *(_DWORD *)&v6[4 * v7];
      v11[2 * v4 + 2] += *(_DWORD *)&v5[4 * v7];
      v11[2 * v4 + 3] = v9;
      LOBYTE(v7) = pData8[v4 - 2];
      v10 = v11[2 * v4 + 1] + *(_DWORD *)&v6[4 * v7];
      v11[2 * v4] += *(_DWORD *)&v5[4 * v7];
      v11[2 * v4 + 1] = v10;
      LOBYTE(v7) = pData8[v4 - 3];
      v4 -= 2;
    }
    while ( v4 != 0 );
  }
  _InterlockedExchange(&tempStore, (__int32)v12);
}

//------------------------------------------------------------------------------
// Address: 0x1002C720
// Name: void SW_Mix8StereoDopplerLeft(struct portable_samplepair_t __near *,int __near *,unsigned char __near *,int,unsigned int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SW_Mix8StereoDopplerLeft(
        portable_samplepair_t *pOutput,
        int *volume,
        unsigned __int8 *pData,
        int *inputOffset,
        unsigned int rateScaleFix,
        int outCount)
{
  int v7; // edi
  int *v8; // edi
  int v9; // eax
  int v10; // esi
  int v11; // edx
  int *rscale; // [esp+14h] [ebp+Ch]
  int *lscale; // [esp+1Ch] [ebp+14h]

  v7 = *volume >> 1 << 10;
  rscale = snd_scaletable[volume[1] >> 1];
  v8 = (int *)((char *)snd_scaletable[0] + v7);
  v9 = 0;
  v10 = 0;
  lscale = v8;
  if ( outCount > 0 )
  {
    while ( 1 )
    {
      pOutput[v9].left += v8[pData[v10]];
      pOutput[v9].right += rscale[pData[v10]];
      v11 = (int)inputOffset + rateScaleFix;
      ++v9;
      v10 += (v11 >> 27) & 0xFFFFFFFE;
      inputOffset = (int *)(v11 & 0xFFFFFFF);
      if ( v9 >= outCount )
        break;
      v8 = lscale;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002C7A0
// Name: void SW_Mix8StereoDopplerRight(struct portable_samplepair_t __near *,int __near *,unsigned char __near *,int,unsigned int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SW_Mix8StereoDopplerRight(
        portable_samplepair_t *pOutput,
        int *volume,
        unsigned __int8 *pData,
        int *inputOffset,
        unsigned int rateScaleFix,
        int outCount)
{
  int v7; // edi
  int *v8; // edi
  int v9; // eax
  int v10; // esi
  int v11; // edx
  int *rscale; // [esp+14h] [ebp+Ch]
  int *lscale; // [esp+1Ch] [ebp+14h]

  v7 = *volume >> 1 << 10;
  rscale = snd_scaletable[volume[1] >> 1];
  v8 = (int *)((char *)snd_scaletable[0] + v7);
  v9 = 0;
  v10 = 0;
  lscale = v8;
  if ( outCount > 0 )
  {
    while ( 1 )
    {
      pOutput[v9].left += v8[pData[v10 + 1]];
      pOutput[v9].right += rscale[pData[v10 + 1]];
      v11 = (int)inputOffset + rateScaleFix;
      ++v9;
      v10 += (v11 >> 27) & 0xFFFFFFFE;
      inputOffset = (int *)(v11 & 0xFFFFFFF);
      if ( v9 >= outCount )
        break;
      v8 = lscale;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002C830
// Name: void SW_Mix16StereoDopplerLeft(struct portable_samplepair_t __near *,int __near *,short __near *,int,unsigned int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SW_Mix16StereoDopplerLeft(
        portable_samplepair_t *pOutput,
        int *volume,
        __int16 *pData,
        int inputOffset,
        unsigned int rateScaleFix,
        int outCount)
{
  int v7; // eax
  int i; // esi
  int v9; // edx

  v7 = 0;
  for ( i = 0; v7 < outCount; inputOffset = v9 & 0xFFFFFFF )
  {
    v9 = rateScaleFix + inputOffset;
    pOutput[v7].left += (*volume * pData[i]) >> 8;
    pOutput[v7++].right += (volume[1] * pData[i]) >> 8;
    i += (v9 >> 27) & 0xFFFFFFFE;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002C890
// Name: void SW_Mix16StereoDopplerLeft_Interp(struct portable_samplepair_t __near *,int __near *,short __near *,int,unsigned int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SW_Mix16StereoDopplerLeft_Interp(
        portable_samplepair_t *pOutput,
        int *volume,
        __int16 *pData,
        unsigned int inputOffset,
        unsigned int rateScaleFix,
        int outCount)
{
  int v6; // ecx
  int v7; // edi
  unsigned int v8; // edx
  int v9; // eax
  int v10; // edx
  unsigned int rateScaleFix14; // [esp+1Ch] [ebp+18h]

  v6 = 0;
  v7 = 0;
  v8 = inputOffset >> 14;
  for ( rateScaleFix14 = rateScaleFix >> 14; v6 < outCount; v8 = v10 & 0x3FFF )
  {
    v9 = pData[v7] + ((int)(v8 * (pData[v7 + 2] - pData[v7])) >> 14);
    v10 = rateScaleFix14 + v8;
    pOutput[v6].left += (v9 * *volume) >> 8;
    pOutput[v6++].right += (v9 * volume[1]) >> 8;
    v7 += (v10 >> 13) & 0xFFFFFFFE;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002C980
// Name: void SW_Mix16StereoDopplerRight_Interp(struct portable_samplepair_t __near *,int __near *,short __near *,int,unsigned int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SW_Mix16StereoDopplerRight_Interp(
        portable_samplepair_t *pOutput,
        int *volume,
        __int16 *pData,
        unsigned int inputOffset,
        unsigned int rateScaleFix,
        int outCount)
{
  SW_Mix16StereoDopplerLeft_Interp(pOutput, volume, pData: pData + 1, inputOffset, rateScaleFix, outCount);
}

//------------------------------------------------------------------------------
// Address: 0x1002C9B0
// Name: void SW_Mix8StereoDirectional(float,struct portable_samplepair_t __near *,int __near *,unsigned char __near *,int,unsigned int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SW_Mix8StereoDirectional(
        float soundfacing,
        portable_samplepair_t *pOutput,
        int *volume,
        unsigned __int8 *pData,
        int inputOffset,
        unsigned int rateScaleFix,
        int outCount)
{
  int v8; // eax
  int v10; // ecx
  int v11; // edi
  int v12; // esi
  int v13; // eax
  int *rscale; // [esp+0h] [ebp-4h]
  int *lscale; // [esp+14h] [ebp+10h]

  lscale = snd_scaletable[*volume >> 1];
  v8 = volume[1] >> 1 << 10;
  v10 = 0;
  v11 = 0;
  for ( rscale = (int *)((char *)snd_scaletable[0] + v8); v10 < outCount; inputOffset = v12 & 0xFFFFFFF )
  {
    v12 = rateScaleFix + inputOffset;
    v13 = (unsigned __int8)(pData[v11 + 1]
                          + ((unsigned __int16)((int)(float)((float)((float)(soundfacing + 1.0) * 0.5) * 256.0)
                                              * ((char)pData[v11] - (char)pData[v11 + 1])) >> 8));
    pOutput[v10].left += lscale[v13];
    pOutput[v10++].right += rscale[v13];
    v11 += (v12 >> 27) & 0xFFFFFFFE;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002CA70
// Name: void SW_Mix8StereoDirectional_Interp(float,struct portable_samplepair_t __near *,int __near *,unsigned char __near *,int,unsigned int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SW_Mix8StereoDirectional_Interp(
        float soundfacing,
        portable_samplepair_t *pOutput,
        int *volume,
        unsigned __int8 *pData,
        int *inputOffset,
        unsigned int rateScaleFix,
        int outCount)
{
  int v8; // edx
  int v9; // edi
  unsigned int v10; // esi
  int v11; // ecx
  int v12; // eax
  int v13; // esi
  int v14; // eax
  int *rscale; // [esp+14h] [ebp+10h]
  int *lscale; // [esp+1Ch] [ebp+18h]

  lscale = snd_scaletable[*volume >> 1];
  v8 = 0;
  v9 = 0;
  v10 = (unsigned int)inputOffset >> 14;
  for ( rscale = snd_scaletable[volume[1] >> 1]; v8 < outCount; v10 = v13 & 0x3FFF )
  {
    v11 = (char)pData[v9 + 1] + ((int)(v10 * ((char)pData[v9 + 3] - (char)pData[v9 + 1])) >> 14);
    v12 = (int)(float)((float)((float)(soundfacing + 1.0) * 0.5) * 256.0)
        * ((char)pData[v9] + ((int)(v10 * ((char)pData[v9 + 2] - (char)pData[v9])) >> 14) - v11);
    v13 = (rateScaleFix >> 14) + v10;
    v14 = (unsigned __int8)(v11 + BYTE1(v12));
    pOutput[v8].left += lscale[v14];
    pOutput[v8++].right += rscale[v14];
    v9 += (v13 >> 13) & 0xFFFFFFFE;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002CB60
// Name: void SW_Mix16StereoDirectional(float,struct portable_samplepair_t __near *,int __near *,short __near *,int,unsigned int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SW_Mix16StereoDirectional(
        float soundfacing,
        portable_samplepair_t *pOutput,
        int *volume,
        __int16 *pData,
        int inputOffset,
        unsigned int rateScaleFix,
        int outCount)
{
  int v8; // ecx
  int i; // edi
  int v10; // eax
  int v11; // esi

  v8 = 0;
  for ( i = 0; v8 < outCount; inputOffset = v11 & 0xFFFFFFF )
  {
    v10 = pData[i + 1]
        + (((int)(float)((float)((float)(soundfacing + 1.0) * 0.5) * 256.0) * (pData[i] - pData[i + 1])) >> 8);
    v11 = rateScaleFix + inputOffset;
    pOutput[v8].left += (v10 * *volume) >> 8;
    pOutput[v8++].right += (v10 * volume[1]) >> 8;
    i += (v11 >> 27) & 0xFFFFFFFE;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002CC00
// Name: void SW_Mix16StereoDirectional_Interp(float,struct portable_samplepair_t __near *,int __near *,short __near *,int,unsigned int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SW_Mix16StereoDirectional_Interp(
        float soundfacing,
        portable_samplepair_t *pOutput,
        int *volume,
        __int16 *pData,
        unsigned int inputOffset,
        unsigned int rateScaleFix,
        int outCount)
{
  int v7; // edx
  int v8; // edi
  unsigned int i; // esi
  int v10; // ebx
  int v11; // ecx
  int v12; // eax
  int v13; // esi

  v7 = 0;
  v8 = 0;
  for ( i = inputOffset >> 14; v7 < outCount; i = v13 & 0x3FFF )
  {
    v10 = pData[v8 + 1];
    v11 = v10 + ((int)(i * (pData[v8 + 3] - v10)) >> 14);
    v12 = v11
        + (((int)(float)((float)((float)(soundfacing + 1.0) * 0.5) * 256.0)
          * (pData[v8] + ((int)(i * (pData[v8 + 2] - pData[v8])) >> 14) - v11)) >> 8);
    v13 = (rateScaleFix >> 14) + i;
    pOutput[v7].left += (v12 * *volume) >> 8;
    pOutput[v7++].right += (v12 * volume[1]) >> 8;
    v8 += (v13 >> 13) & 0xFFFFFFFE;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002CCC0
// Name: void SW_Mix8StereoDistVar(float,struct portable_samplepair_t __near *,int __near *,unsigned char __near *,int,unsigned int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SW_Mix8StereoDistVar(
        float distmix,
        portable_samplepair_t *pOutput,
        int *volume,
        unsigned __int8 *pData,
        int *inputOffset,
        unsigned int rateScaleFix,
        int outCount)
{
  int v8; // ebx
  int v9; // eax
  int *v10; // ebx
  int v11; // edx
  int v12; // eax
  int v13; // ecx
  int v14; // esi
  int v15; // ecx
  int v16; // esi
  int i; // esi
  int v18; // ecx
  int v19; // [esp+0h] [ebp-4h]
  int *rscale; // [esp+14h] [ebp+10h]
  int *lscale; // [esp+1Ch] [ebp+18h]

  v8 = *volume >> 1;
  rscale = snd_scaletable[volume[1] >> 1];
  v9 = (int)(float)(distmix * 256.0);
  v10 = snd_scaletable[v8];
  v11 = 0;
  lscale = v10;
  if ( (int)(float)((float)(1.0 - distmix) * 256.0) != 0 )
  {
    if ( v9 != 0 )
    {
      for ( i = 0; i < outCount; inputOffset = (int *)(v18 & 0xFFFFFFF) )
      {
        v18 = (int)inputOffset + rateScaleFix;
        v19 = (unsigned __int8)(pData[v11] + ((unsigned __int16)(v9 * ((char)pData[v11 + 1] - (char)pData[v11])) >> 8));
        pOutput[i].left += v10[v19];
        pOutput[i++].right += rscale[v19];
        v11 += (v18 >> 27) & 0xFFFFFFFE;
      }
    }
    else if ( outCount > 0 )
    {
      while ( 1 )
      {
        v15 = (int)inputOffset + rateScaleFix;
        v16 = pData[v11];
        pOutput[v9].left += v10[v16];
        pOutput[v9++].right += rscale[v16];
        v11 += (v15 >> 27) & 0xFFFFFFFE;
        inputOffset = (int *)(v15 & 0xFFFFFFF);
        if ( v9 >= outCount )
          break;
        v10 = lscale;
      }
    }
  }
  else
  {
    v12 = 0;
    if ( outCount > 0 )
    {
      while ( 1 )
      {
        v13 = (int)inputOffset + rateScaleFix;
        v14 = pData[v11 + 1];
        pOutput[v12].left += v10[v14];
        pOutput[v12++].right += rscale[v14];
        v11 += (v13 >> 27) & 0xFFFFFFFE;
        inputOffset = (int *)(v13 & 0xFFFFFFF);
        if ( v12 >= outCount )
          break;
        v10 = lscale;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002CE40
// Name: void SW_Mix8StereoDistVar_Interp(float,struct portable_samplepair_t __near *,int __near *,unsigned char __near *,int,unsigned int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SW_Mix8StereoDistVar_Interp(
        float distmix,
        portable_samplepair_t *pOutput,
        int *volume,
        unsigned __int8 *pData,
        unsigned int inputOffset,
        int *rateScaleFix,
        int outCount)
{
  int v8; // edx
  unsigned int v9; // ecx
  int k; // esi
  int v11; // ebx
  int v12; // eax
  int v13; // ecx
  int v14; // eax
  int j; // esi
  int v16; // ebx
  int v17; // eax
  int v18; // ecx
  int i; // edi
  int v20; // esi
  int v21; // eax
  int v22; // ecx
  int v23; // eax
  unsigned int rateScaleFix14; // [esp+4h] [ebp-4h]
  int *lscale; // [esp+10h] [ebp+8h]
  int inputOffseta; // [esp+20h] [ebp+18h]
  int *rscale; // [esp+24h] [ebp+1Ch]

  rateScaleFix14 = (unsigned int)rateScaleFix >> 14;
  lscale = snd_scaletable[*volume >> 1];
  rscale = snd_scaletable[volume[1] >> 1];
  v8 = 0;
  v9 = inputOffset >> 14;
  if ( (int)(float)((float)(1.0 - distmix) * 256.0) != 0 )
  {
    if ( (int)(float)(distmix * 256.0) != 0 )
    {
      for ( i = 0; i < outCount; v9 = v22 & 0x3FFF )
      {
        v20 = (char)pData[v8] + ((int)(v9 * ((char)pData[v8 + 2] - (char)pData[v8])) >> 14);
        v21 = (int)(float)(distmix * 256.0)
            * ((char)pData[v8 + 1] + ((int)(v9 * ((char)pData[v8 + 3] - (char)pData[v8 + 1])) >> 14) - v20);
        v22 = rateScaleFix14 + v9;
        v23 = (unsigned __int8)(v20 + BYTE1(v21));
        pOutput[i].left += lscale[v23];
        pOutput[i++].right += rscale[v23];
        v8 += (v22 >> 13) & 0xFFFFFFFE;
      }
    }
    else
    {
      for ( j = 0; j < outCount; v9 = v18 & 0x3FFF )
      {
        v16 = (char)pData[v8];
        v17 = v9 * ((char)pData[v8 + 2] - v16);
        v18 = rateScaleFix14 + v9;
        inputOffseta = (unsigned __int8)(v16 + (v17 >> 14));
        pOutput[j].left += lscale[inputOffseta];
        pOutput[j++].right += rscale[inputOffseta];
        v8 += (v18 >> 13) & 0xFFFFFFFE;
      }
    }
  }
  else
  {
    for ( k = 0; k < outCount; v9 = v13 & 0x3FFF )
    {
      v11 = (char)pData[v8 + 1];
      v12 = v9 * ((char)pData[v8 + 3] - v11);
      v13 = rateScaleFix14 + v9;
      v14 = (unsigned __int8)(v11 + (v12 >> 14));
      pOutput[k].left += lscale[v14];
      pOutput[k++].right += rscale[v14];
      v8 += (v13 >> 13) & 0xFFFFFFFE;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002D010
// Name: void SW_Mix8Mono(struct portable_samplepair_t __near *,int __near *,unsigned char __near *,int,unsigned int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SW_Mix8Mono(
        portable_samplepair_t *pOutput,
        int *volume,
        unsigned __int8 *pData,
        int inputOffset,
        unsigned int rateScaleFix,
        int outCount)
{
  int *v7; // edi
  int v8; // eax
  int v9; // esi
  int v10; // edx
  int *rscale; // [esp+0h] [ebp-8h]
  int *lscale; // [esp+4h] [ebp-4h]

  if ( rateScaleFix == 0x10000000 )
  {
    SND_PaintChannelFrom8(pOutput, volume, pData8: pData, count: outCount);
  }
  else
  {
    rscale = snd_scaletable[volume[1] >> 1];
    v7 = snd_scaletable[*volume >> 1];
    v8 = 0;
    v9 = 0;
    lscale = v7;
    if ( outCount > 0 )
    {
      while ( 1 )
      {
        pOutput[v8].left += v7[pData[v9]];
        v10 = rateScaleFix + inputOffset;
        pOutput[v8++].right += rscale[pData[v9]];
        v9 += v10 >> 28;
        inputOffset = v10 & 0xFFFFFFF;
        if ( v8 >= outCount )
          break;
        v7 = lscale;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002D0B0
// Name: void SW_Mix8Mono_Interp(struct portable_samplepair_t __near *,int __near *,unsigned char __near *,int,unsigned int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SW_Mix8Mono_Interp(
        portable_samplepair_t *pOutput,
        int *volume,
        unsigned __int8 *pData,
        int *inputOffset,
        int *rateScaleFix,
        int outCount)
{
  int v6; // ecx
  int v7; // edi
  unsigned int v8; // edx
  int v9; // ebx
  int v10; // eax
  int v11; // edx
  int v12; // eax
  unsigned int rateScaleFix14; // [esp+4h] [ebp-4h]
  int *rscale; // [esp+1Ch] [ebp+14h]
  int *lscale; // [esp+20h] [ebp+18h]

  rateScaleFix14 = (unsigned int)rateScaleFix >> 14;
  lscale = snd_scaletable[*volume >> 1];
  v6 = 0;
  v7 = 0;
  v8 = (unsigned int)inputOffset >> 14;
  for ( rscale = snd_scaletable[volume[1] >> 1]; v6 < outCount; v8 = v11 & 0x3FFF )
  {
    v9 = (char)pData[v7];
    v10 = v8 * ((char)pData[v7 + 1] - v9);
    v11 = rateScaleFix14 + v8;
    v12 = (unsigned __int8)(v9 + (v10 >> 14));
    pOutput[v6].left += lscale[v12];
    pOutput[v6++].right += rscale[v12];
    v7 += v11 >> 14;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002D150
// Name: void SW_Mix8Stereo(struct portable_samplepair_t __near *,int __near *,unsigned char __near *,int,unsigned int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SW_Mix8Stereo(
        portable_samplepair_t *pOutput,
        int *volume,
        unsigned __int8 *pData,
        int *inputOffset,
        unsigned int rateScaleFix,
        int outCount)
{
  int v7; // edi
  int *v8; // edi
  int v9; // eax
  int v10; // esi
  int v11; // edx
  int *rscale; // [esp+14h] [ebp+Ch]
  int *lscale; // [esp+1Ch] [ebp+14h]

  v7 = *volume >> 1 << 10;
  rscale = snd_scaletable[volume[1] >> 1];
  v8 = (int *)((char *)snd_scaletable[0] + v7);
  v9 = 0;
  v10 = 0;
  lscale = v8;
  if ( outCount > 0 )
  {
    while ( 1 )
    {
      pOutput[v9].left += v8[pData[v10]];
      pOutput[v9].right += rscale[pData[v10 + 1]];
      v11 = (int)inputOffset + rateScaleFix;
      ++v9;
      v10 += (v11 >> 27) & 0xFFFFFFFE;
      inputOffset = (int *)(v11 & 0xFFFFFFF);
      if ( v9 >= outCount )
        break;
      v8 = lscale;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002D1D0
// Name: void SW_Mix8Stereo_Interp(struct portable_samplepair_t __near *,int __near *,unsigned char __near *,int,unsigned int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SW_Mix8Stereo_Interp(
        portable_samplepair_t *pOutput,
        int *volume,
        unsigned __int8 *pData,
        int *inputOffset,
        int *rateScaleFix,
        int outCount)
{
  int v6; // edx
  int v7; // edi
  unsigned int v8; // esi
  int v9; // ebx
  unsigned __int8 v10; // al
  int v11; // ecx
  int v12; // esi
  unsigned int rateScaleFix14; // [esp+8h] [ebp-4h]
  int *rscale; // [esp+20h] [ebp+14h]
  int *lscale; // [esp+24h] [ebp+18h]

  rateScaleFix14 = (unsigned int)rateScaleFix >> 14;
  lscale = snd_scaletable[*volume >> 1];
  v6 = 0;
  v7 = 0;
  v8 = (unsigned int)inputOffset >> 14;
  for ( rscale = snd_scaletable[volume[1] >> 1]; v6 < outCount; v8 = v12 & 0x3FFF )
  {
    v9 = (char)pData[v7 + 1];
    v10 = pData[v7] + ((int)(v8 * ((char)pData[v7 + 2] - (char)pData[v7])) >> 14);
    v11 = v8 * ((char)pData[v7 + 3] - v9);
    v12 = rateScaleFix14 + v8;
    pOutput[v6].left += lscale[v10];
    pOutput[v6++].right += rscale[(unsigned __int8)(v9 + (v11 >> 14))];
    v7 += (v12 >> 13) & 0xFFFFFFFE;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002D280
// Name: void SW_Mix16Mono_Shift(struct portable_samplepair_t __near *,int __near *,short __near *,int,unsigned int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SW_Mix16Mono_Shift(
        __m64 *pOutput,
        int *volume,
        __int16 *pData,
        int inputOffset,
        int rateScaleFix,
        int outCount)
{
  unsigned int v6; // eax
  __m64 v7; // mm0
  __int64 v10; // kr08_8
  __m64 v11; // mm2
  __m64 v12; // mm3
  __m64 v13; // mm3
  __m64 v14; // mm2
  __m64 v15; // mm5
  __m64 v16; // mm4
  unsigned int rateScaleFrac; // [esp+Ch] [ebp-Ch]
  int vol0; // [esp+10h] [ebp-8h]
  int vol1; // [esp+14h] [ebp-4h]
  int rateScaleInt; // [esp+30h] [ebp+18h]

  vol0 = *volume;
  v6 = 16 * rateScaleFix;
  vol1 = volume[1];
  rateScaleInt = (unsigned __int64)rateScaleFix >> 28;
  rateScaleFrac = v6;
  v7 = _m_packssdw(*(__m64 *)volume, *(__m64 *)volume);
  v10 = (unsigned int)inputOffset;
  do
  {
    v11 = _mm_cvtsi32_si64(*(_DWORD *)&pData[HIDWORD(v10)]);
    v12 = _mm_cvtsi32_si64(*(_DWORD *)&pData[(__PAIR64__(rateScaleInt, rateScaleFrac) + v10) >> 32]);
    v10 += __PAIR64__(rateScaleInt, rateScaleFrac) + __PAIR64__(rateScaleInt, rateScaleFrac);
    v13 = _m_punpckldq(_m_punpcklwd(v11, v11), _m_punpcklwd(v12, v12));
    v14 = _m_pmullw(v13, v7);
    v15 = _m_pmulhw(v13, v7);
    outCount -= 2;
    v16 = _m_paddd(_m_psradi(_m_punpckhwd(v14, v15), 8u), pOutput[1]);
    pOutput->m64_u64 = (unsigned __int64)_m_paddd(_m_psradi(_m_punpcklwd(v14, v15), 8u), (__m64)pOutput->m64_u64);
    pOutput[1].m64_u64 = (unsigned __int64)v16;
    pOutput += 2;
  }
  while ( outCount > 1 );
  if ( outCount >= 1 )
  {
    pOutput->m64_i32[0] += (vol0 * pData[HIDWORD(v10)]) >> 8;
    pOutput->m64_i32[1] += (vol1 * pData[HIDWORD(v10)]) >> 8;
  }
  _m_empty();
}

//------------------------------------------------------------------------------
// Address: 0x1002D340
// Name: void SW_Mix16Mono_NoShift(struct portable_samplepair_t __near *,int __near *,short __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SW_Mix16Mono_NoShift(__m64 *pOutput, int *volume, __int16 *pData, int outCount)
{
  __m64 v4; // mm0
  __m64 v8; // mm2
  __int16 *v9; // edx
  __m64 v10; // mm3
  __m64 v11; // mm3
  __m64 v12; // mm2
  __m64 v13; // mm5
  __m64 v14; // mm4
  int v15; // esi
  int vol0; // [esp+8h] [ebp-8h]
  int vol1; // [esp+Ch] [ebp-4h]

  vol0 = *volume;
  vol1 = volume[1];
  v4 = _m_packssdw(*(__m64 *)volume, *(__m64 *)volume);
  do
  {
    v8 = _mm_cvtsi32_si64(*(_DWORD *)pData);
    v9 = pData + 1;
    v10 = _mm_cvtsi32_si64(*(_DWORD *)v9);
    pData = v9 + 1;
    v11 = _m_punpckldq(_m_punpcklwd(v8, v8), _m_punpcklwd(v10, v10));
    v12 = _m_pmullw(v11, v4);
    v13 = _m_pmulhw(v11, v4);
    outCount -= 2;
    v14 = _m_paddd(_m_psradi(_m_punpckhwd(v12, v13), 8u), pOutput[1]);
    pOutput->m64_u64 = (unsigned __int64)_m_paddd(_m_psradi(_m_punpcklwd(v12, v13), 8u), (__m64)pOutput->m64_u64);
    pOutput[1].m64_u64 = (unsigned __int64)v14;
    pOutput += 2;
  }
  while ( outCount > 1 );
  if ( outCount >= 1 )
  {
    v15 = *pData;
    pOutput->m64_i32[0] += (vol0 * v15) >> 8;
    pOutput->m64_i32[1] += (vol1 * v15) >> 8;
  }
  _m_empty();
}

//------------------------------------------------------------------------------
// Address: 0x1002D3E0
// Name: void SW_Mix16Mono(struct portable_samplepair_t restrict __near *,int restrict __near *,short restrict __near *,int,unsigned int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SW_Mix16Mono(
        portable_samplepair_t *pOutput,
        int *volume,
        __int16 *pData,
        int inputOffset,
        unsigned int rateScaleFix,
        int outCount)
{
  if ( rateScaleFix == 0x10000000 )
    SW_Mix16Mono_NoShift((__m64 *)pOutput, volume, pData, outCount);
  else
    SW_Mix16Mono_Shift((__m64 *)pOutput, volume, pData, inputOffset, rateScaleFix, outCount);
}

//------------------------------------------------------------------------------
// Address: 0x1002D430
// Name: void SW_Mix16Mono_Interp(struct portable_samplepair_t restrict __near *,int restrict __near *,short restrict __near *,int,unsigned int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SW_Mix16Mono_Interp(
        portable_samplepair_t *pOutput,
        int *volume,
        __int16 *pData,
        unsigned int inputOffset,
        unsigned int rateScaleFix,
        int outCount)
{
  int v6; // ecx
  int v7; // edi
  unsigned int v8; // edx
  int v9; // ebx
  int v10; // eax
  int v11; // edx
  int v12; // eax
  unsigned int rateScaleFix14; // [esp+4h] [ebp-4h]
  int inputOffseta; // [esp+1Ch] [ebp+14h]
  unsigned int rateScaleFixa; // [esp+20h] [ebp+18h]

  v6 = 0;
  v7 = 0;
  v8 = inputOffset >> 14;
  rateScaleFix14 = rateScaleFix >> 14;
  if ( outCount > 0 )
  {
    rateScaleFixa = *volume;
    inputOffseta = volume[1];
    do
    {
      v9 = pData[v7];
      v10 = v8 * (pData[v7 + 1] - v9);
      v11 = rateScaleFix14 + v8;
      v12 = v9 + (v10 >> 14);
      pOutput[v6].left += (int)(v12 * rateScaleFixa) >> 8;
      pOutput[v6++].right += (v12 * inputOffseta) >> 8;
      v7 += v11 >> 14;
      v8 = v11 & 0x3FFF;
    }
    while ( v6 < outCount );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002D4B0
// Name: void SW_Mix16Stereo_NoOpt(struct portable_samplepair_t restrict __near *,int restrict __near *,short restrict __near *,int,unsigned int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SW_Mix16Stereo_NoOpt(
        portable_samplepair_t *pOutput,
        int *pVolume,
        __int16 *pData,
        int nInputOffset,
        unsigned int nRateScaleFix,
        int nOutCount)
{
  int v7; // eax
  int v8; // esi
  int v9; // edx
  int v10; // [esp+4h] [ebp-4h]
  int nInputOffseta; // [esp+1Ch] [ebp+14h]

  v7 = 0;
  v8 = 0;
  if ( nOutCount > 0 )
  {
    v10 = pVolume[1];
    nInputOffseta = *pVolume;
    do
    {
      v9 = nRateScaleFix + nInputOffset;
      pOutput[v7].left += (nInputOffseta * pData[v8]) >> 8;
      pOutput[v7++].right += (v10 * pData[v8 + 1]) >> 8;
      v8 += (v9 >> 27) & 0xFFFFFFFE;
      nInputOffset = v9 & 0xFFFFFFF;
    }
    while ( v7 < nOutCount );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002D5C0
// Name: _SND_InitMouth
// Source: json
//------------------------------------------------------------------------------
void __cdecl SND_InitMouth(channel_t *pChannel)
{
  IClientEntityList *v1; // ecx
  CSfxTable *sfx; // eax
  int speakerentity; // eax
  int v4; // eax
  int v5; // eax
  CMouthInfo *v6; // edi
  char v7; // cl
  CSfxTable *v8; // eax

  v1 = entitylist;
  if ( entitylist != nullptr )
  {
    if ( pChannel->entchannel != 2 )
    {
      sfx = pChannel->sfx;
      if ( sfx == nullptr || sfx->pSource == nullptr || sfx->pSource->GetSentence(this: sfx->pSource) == nullptr )
        return;
      v1 = entitylist;
    }
    speakerentity = pChannel->speakerentity;
    if ( speakerentity == -1 )
      speakerentity = pChannel->soundsource;
    v4 = (int)v1->GetClientEntity(this: v1, a2: speakerentity);
    if ( v4 != 0 )
    {
      v5 = (*(int (__thiscall **)(int))(*(_DWORD *)v4 + 48))(a1: v4);
      v6 = (CMouthInfo *)v5;
      if ( v5 != 0 )
      {
        *(_DWORD *)(v5 + 4) = 0;
        *(_WORD *)v5 = 0;
        *((_BYTE *)&pChannel->flags + 1) |= 0x40u;
        v7 = *((_BYTE *)&pChannel->flags + 1) & 0x7F | ((*(_WORD *)(v5 + 10) != 0) << 7);
        v8 = pChannel->sfx;
        *((_BYTE *)&pChannel->flags + 1) = v7;
        if ( v8->pSource != nullptr && v8->pSource->GetSentence(this: v8->pSource) != nullptr )
          CMouthInfo::AddSource(
            this: v6,
            source: pChannel->sfx->pSource,
            bIgnorePhonemes: (*((_BYTE *)&pChannel->flags + 1) & 0x20) != 0);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002D6B0
// Name: void SND_MovieEnd(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SND_MovieEnd()
{
  if ( cl_movieinfo.moviename[0] != 0 && (cl_movieinfo.type & 4) != 0 )
    WaveFixupTmpFile(filename: cl_movieinfo.moviename);
}

//------------------------------------------------------------------------------
// Address: 0x1002D6E0
// Name: void SW_Mix16Stereo_NoShift_OptMeta<0>(struct portable_samplepair_t restrict __near *,int restrict __near *,short restrict __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SW_Mix16Stereo_NoShift_OptMeta<0>(
        portable_samplepair_t *pOutput,
        int *pVolume,
        __int16 *pData,
        unsigned int nOutCount)
{
  int v4; // ebx
  portable_samplepair_t *v5; // esi
  int v6; // edx
  __int16 *v7; // ecx
  __int16 *v8; // edi
  int *p_right; // eax
  int v10; // eax
  int v11; // ecx
  unsigned int v12; // [esp+Ch] [ebp-4h]
  int nOutCounta; // [esp+24h] [ebp+14h]

  v4 = nOutCount;
  v5 = pOutput;
  if ( (int)nOutCount < 4 )
  {
    v8 = pData;
  }
  else
  {
    v6 = *pVolume;
    v12 = nOutCount >> 2;
    v7 = pData + 5;
    nOutCounta = nOutCount - 4 * (nOutCount >> 2);
    v8 = pData;
    p_right = &pOutput[2].right;
    do
    {
      v5->left += (v6 * *v8) >> 8;
      *(p_right - 4) += (v6 * *(v7 - 4)) >> 8;
      *(p_right - 3) += (v6 * *(v7 - 3)) >> 8;
      *(p_right - 2) += (v6 * *(v7 - 2)) >> 8;
      *(p_right - 1) += (v6 * *(v7 - 1)) >> 8;
      *p_right += (v6 * *v7) >> 8;
      p_right[1] += (v6 * v7[1]) >> 8;
      p_right[2] += (v6 * v7[2]) >> 8;
      v5 += 4;
      p_right += 8;
      v8 += 8;
      v7 += 8;
      --v12;
    }
    while ( v12 != 0 );
    v4 = nOutCounta;
  }
  if ( v4 > 0 )
  {
    v10 = *pVolume;
    do
    {
      v11 = v10 * v8[1];
      v5->left += (v10 * *v8) >> 8;
      v5->right += v11 >> 8;
      --v4;
      ++v5;
      v8 += 2;
    }
    while ( v4 > 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002D7D0
// Name: void SW_Mix16Stereo_NoShift_OptMeta<1>(struct portable_samplepair_t restrict __near *,int restrict __near *,short restrict __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SW_Mix16Stereo_NoShift_OptMeta<1>(
        portable_samplepair_t *pOutput,
        int *pVolume,
        __int16 *pData,
        unsigned int nOutCount)
{
  int v4; // esi
  int v5; // edx
  unsigned int v6; // edi
  int *p_right; // eax
  __int16 *v8; // ecx
  int v9; // edx
  int *v10; // eax
  __int16 *v11; // ecx

  v4 = nOutCount;
  if ( (int)nOutCount < 4 )
  {
    v8 = pData;
  }
  else
  {
    v5 = pVolume[1];
    v6 = nOutCount >> 2;
    v4 = nOutCount - 4 * (nOutCount >> 2);
    p_right = &pOutput[2].right;
    pOutput += 4 * (nOutCount >> 2);
    v8 = pData;
    do
    {
      *(p_right - 4) += (v5 * v8[1]) >> 8;
      *(p_right - 2) += (v5 * v8[3]) >> 8;
      *p_right += (v5 * v8[5]) >> 8;
      p_right[2] += (v5 * v8[7]) >> 8;
      p_right += 8;
      v8 += 8;
      --v6;
    }
    while ( v6 != 0 );
  }
  if ( v4 > 0 )
  {
    v9 = pVolume[1];
    v10 = &pOutput->right;
    v11 = v8 + 1;
    do
    {
      *v10 += (v9 * *v11) >> 8;
      --v4;
      v10 += 2;
      v11 += 2;
    }
    while ( v4 > 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002D880
// Name: void SW_Mix16Stereo_NoShift_OptMeta<2>(struct portable_samplepair_t restrict __near *,int restrict __near *,short restrict __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SW_Mix16Stereo_NoShift_OptMeta<2>(
        portable_samplepair_t *pOutput,
        int *pVolume,
        __int16 *pData,
        unsigned int nOutCount)
{
  int v4; // esi
  int v5; // edx
  portable_samplepair_t *v6; // eax
  unsigned int v7; // edi
  __int16 *v8; // ecx
  int v9; // edx

  v4 = nOutCount;
  if ( (int)nOutCount < 4 )
  {
    v8 = pData;
    v6 = pOutput;
  }
  else
  {
    v5 = *pVolume;
    v6 = pOutput;
    v7 = nOutCount >> 2;
    v4 = nOutCount - 4 * (nOutCount >> 2);
    v8 = pData;
    do
    {
      v6->left += (v5 * *v8) >> 8;
      v6[1].left += (v5 * v8[2]) >> 8;
      v6[2].left += (v5 * v8[4]) >> 8;
      v6[3].left += (v5 * v8[6]) >> 8;
      v6 += 4;
      v8 += 8;
      --v7;
    }
    while ( v7 != 0 );
  }
  if ( v4 > 0 )
  {
    v9 = *pVolume;
    do
    {
      v6->left += (v9 * *v8) >> 8;
      --v4;
      ++v6;
      v8 += 2;
    }
    while ( v4 > 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002D910
// Name: void SW_Mix16Stereo_NoShift_OptMeta<3>(struct portable_samplepair_t restrict __near *,int restrict __near *,short restrict __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SW_Mix16Stereo_NoShift_OptMeta<3>(
        portable_samplepair_t *pOutput,
        int *pVolume,
        __int16 *pData,
        unsigned int nOutCount)
{
  int *v4; // ecx
  portable_samplepair_t *v5; // edx
  __int16 *v6; // esi
  int v7; // edi
  int *p_right; // eax
  __int16 *v9; // ecx
  int v10; // eax
  int v11; // ecx
  unsigned int v12; // [esp+Ch] [ebp-Ch]
  int v13; // [esp+10h] [ebp-8h]
  int v14; // [esp+14h] [ebp-4h]
  int nOutCounta; // [esp+2Ch] [ebp+14h]

  v4 = pVolume;
  v5 = pOutput;
  v6 = pData;
  v7 = nOutCount;
  if ( (int)nOutCount >= 4 )
  {
    v12 = nOutCount >> 2;
    v14 = *pVolume;
    v13 = pVolume[1];
    p_right = &pOutput[2].right;
    v9 = pData + 5;
    nOutCounta = nOutCount - 4 * (nOutCount >> 2);
    do
    {
      v5->left += (v14 * *v6) >> 8;
      *(p_right - 4) += (v13 * *(v9 - 4)) >> 8;
      *(p_right - 3) += (v14 * *(v9 - 3)) >> 8;
      *(p_right - 2) += (v13 * *(v9 - 2)) >> 8;
      *(p_right - 1) += (v14 * *(v9 - 1)) >> 8;
      *p_right += (v13 * *v9) >> 8;
      p_right[1] += (v14 * v9[1]) >> 8;
      p_right[2] += (v13 * v9[2]) >> 8;
      v5 += 4;
      p_right += 8;
      v6 += 8;
      v9 += 8;
      --v12;
    }
    while ( v12 != 0 );
    v4 = pVolume;
    v7 = nOutCounta;
  }
  if ( v7 > 0 )
  {
    v10 = *v4;
    v11 = v4[1];
    do
    {
      v5->left += (v10 * *v6) >> 8;
      v5->right += (v11 * v6[1]) >> 8;
      --v7;
      ++v5;
      v6 += 2;
    }
    while ( v7 > 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002DA10
// Name: void SW_Mix16Stereo_Shift_OptMeta<0>(struct portable_samplepair_t restrict __near *,int restrict __near *,short restrict __near *,int,unsigned int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SW_Mix16Stereo_Shift_OptMeta<0>(
        portable_samplepair_t *pOutput,
        int *pVolume,
        __int16 *pData,
        int nInputOffset,
        unsigned int nRateScaleFix,
        unsigned int nOutCount)
{
  int v7; // ebx
  portable_samplepair_t *v8; // edi
  int v9; // edx
  __int16 *v10; // esi
  int *p_right; // eax
  int v12; // ecx
  __int16 *v13; // esi
  int v14; // ecx
  __int16 *v15; // esi
  int v16; // ecx
  __int16 *v17; // esi
  int v18; // ecx
  unsigned int v19; // ebx
  bool v20; // zf
  int v21; // eax
  int v22; // ecx
  unsigned int v23; // edx
  unsigned int nInputOffseta; // [esp+20h] [ebp+14h]
  int nOutCounta; // [esp+28h] [ebp+1Ch]

  v7 = nOutCount;
  v8 = pOutput;
  if ( (int)nOutCount < 4 )
  {
    v10 = pData;
  }
  else
  {
    v9 = *pVolume;
    nInputOffseta = nOutCount >> 2;
    nOutCounta = nOutCount - 4 * (nOutCount >> 2);
    v10 = pData;
    p_right = &pOutput[2].right;
    do
    {
      v8->left += (v9 * *v10) >> 8;
      v12 = nRateScaleFix + nInputOffset;
      *(p_right - 4) += (v9 * v10[1]) >> 8;
      v13 = &v10[(v12 >> 27) & 0xFFFFFFFE];
      *(p_right - 3) += (v9 * *v13) >> 8;
      *(p_right - 2) += (v9 * v13[1]) >> 8;
      v14 = nRateScaleFix + (v12 & 0xFFFFFFF);
      v8 += 4;
      v15 = &v13[(v14 >> 27) & 0xFFFFFFFE];
      *(p_right - 1) += (v9 * *v15) >> 8;
      *p_right += (v9 * v15[1]) >> 8;
      v16 = nRateScaleFix + (v14 & 0xFFFFFFF);
      p_right += 8;
      v17 = &v15[(v16 >> 27) & 0xFFFFFFFE];
      *(p_right - 7) += (v9 * *v17) >> 8;
      *(p_right - 6) += (v9 * v17[1]) >> 8;
      v18 = nRateScaleFix + (v16 & 0xFFFFFFF);
      v19 = (v18 >> 27) & 0xFFFFFFFE;
      nInputOffset = v18 & 0xFFFFFFF;
      v20 = nInputOffseta-- == 1;
      v10 = &v17[v19];
    }
    while ( !v20 );
    v7 = nOutCounta;
  }
  if ( v7 > 0 )
  {
    v21 = *pVolume;
    do
    {
      v22 = nRateScaleFix + nInputOffset;
      v8->left += (v21 * *v10) >> 8;
      v8->right += (v21 * v10[1]) >> 8;
      v23 = (v22 >> 27) & 0xFFFFFFFE;
      --v7;
      nInputOffset = v22 & 0xFFFFFFF;
      ++v8;
      v10 += v23;
    }
    while ( v7 > 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002DB50
// Name: void SW_Mix16Stereo_Shift_OptMeta<1>(struct portable_samplepair_t restrict __near *,int restrict __near *,short restrict __near *,int,unsigned int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SW_Mix16Stereo_Shift_OptMeta<1>(
        portable_samplepair_t *pOutput,
        int *pVolume,
        __int16 *pData,
        int nInputOffset,
        unsigned int nRateScaleFix,
        unsigned int nOutCount)
{
  int v7; // ebx
  int v8; // edi
  int *p_right; // eax
  __int16 *v10; // edx
  int v11; // ecx
  __int16 *v12; // edx
  int v13; // ecx
  __int16 *v14; // edx
  int v15; // ecx
  __int16 *v16; // edx
  int v17; // ecx
  unsigned int v18; // ebx
  bool v19; // zf
  int v20; // edi
  int *v21; // eax
  int v22; // ecx
  unsigned int nInputOffseta; // [esp+20h] [ebp+14h]

  v7 = nOutCount;
  if ( (int)nOutCount < 4 )
  {
    v10 = pData;
  }
  else
  {
    v8 = pVolume[1];
    nInputOffseta = nOutCount >> 2;
    nOutCount -= 4 * (nOutCount >> 2);
    p_right = &pOutput[2].right;
    pOutput += 4 * ((unsigned int)v7 >> 2);
    v10 = pData;
    do
    {
      *(p_right - 4) += (v8 * v10[1]) >> 8;
      v11 = nRateScaleFix + nInputOffset;
      v12 = &v10[(v11 >> 27) & 0xFFFFFFFE];
      *(p_right - 2) += (v8 * v12[1]) >> 8;
      v13 = nRateScaleFix + (v11 & 0xFFFFFFF);
      v14 = &v12[(v13 >> 27) & 0xFFFFFFFE];
      *p_right += (v8 * v14[1]) >> 8;
      v15 = nRateScaleFix + (v13 & 0xFFFFFFF);
      v16 = &v14[(v15 >> 27) & 0xFFFFFFFE];
      p_right[2] += (v8 * v16[1]) >> 8;
      v17 = nRateScaleFix + (v15 & 0xFFFFFFF);
      v18 = (v17 >> 27) & 0xFFFFFFFE;
      nInputOffset = v17 & 0xFFFFFFF;
      p_right += 8;
      v19 = nInputOffseta-- == 1;
      v10 = &v16[v18];
    }
    while ( !v19 );
    v7 = nOutCount;
  }
  if ( v7 > 0 )
  {
    v20 = pVolume[1];
    v21 = &pOutput->right;
    do
    {
      *v21 += (v20 * v10[1]) >> 8;
      v22 = nRateScaleFix + nInputOffset;
      v10 += (v22 >> 27) & 0xFFFFFFFE;
      nInputOffset = v22 & 0xFFFFFFF;
      v21 += 2;
      --nOutCount;
    }
    while ( (int)nOutCount > 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002DC70
// Name: void SW_Mix16Stereo_Shift_OptMeta<2>(struct portable_samplepair_t restrict __near *,int restrict __near *,short restrict __near *,int,unsigned int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SW_Mix16Stereo_Shift_OptMeta<2>(
        portable_samplepair_t *pOutput,
        int *pVolume,
        __int16 *pData,
        int nInputOffset,
        unsigned int nRateScaleFix,
        unsigned int nOutCount)
{
  int v7; // ebx
  int v8; // edi
  portable_samplepair_t *v9; // eax
  __int16 *v10; // edx
  int v11; // ecx
  __int16 *v12; // edx
  int v13; // ecx
  __int16 *v14; // edx
  int v15; // ecx
  __int16 *v16; // edx
  int v17; // ecx
  unsigned int v18; // ebx
  bool v19; // zf
  int v20; // ebx
  int v21; // ecx
  unsigned int nInputOffseta; // [esp+20h] [ebp+14h]

  v7 = nOutCount;
  if ( (int)nOutCount < 4 )
  {
    v10 = pData;
    v9 = pOutput;
  }
  else
  {
    v8 = *pVolume;
    nInputOffseta = nOutCount >> 2;
    v9 = pOutput;
    nOutCount -= 4 * (nOutCount >> 2);
    v10 = pData;
    do
    {
      v9->left += (v8 * *v10) >> 8;
      v11 = nRateScaleFix + nInputOffset;
      v12 = &v10[(v11 >> 27) & 0xFFFFFFFE];
      v9[1].left += (v8 * *v12) >> 8;
      v13 = nRateScaleFix + (v11 & 0xFFFFFFF);
      v14 = &v12[(v13 >> 27) & 0xFFFFFFFE];
      v9[2].left += (v8 * *v14) >> 8;
      v15 = nRateScaleFix + (v13 & 0xFFFFFFF);
      v16 = &v14[(v15 >> 27) & 0xFFFFFFFE];
      v9[3].left += (v8 * *v16) >> 8;
      v17 = nRateScaleFix + (v15 & 0xFFFFFFF);
      v18 = (v17 >> 27) & 0xFFFFFFFE;
      nInputOffset = v17 & 0xFFFFFFF;
      v9 += 4;
      v19 = nInputOffseta-- == 1;
      v10 = &v16[v18];
    }
    while ( !v19 );
    v7 = nOutCount;
  }
  if ( v7 > 0 )
  {
    v20 = *pVolume;
    do
    {
      v9->left += (v20 * *v10) >> 8;
      v21 = nRateScaleFix + nInputOffset;
      v10 += (v21 >> 27) & 0xFFFFFFFE;
      nInputOffset = v21 & 0xFFFFFFF;
      ++v9;
      --nOutCount;
    }
    while ( (int)nOutCount > 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002DD80
// Name: void SW_Mix16Stereo_Shift_OptMeta<3>(struct portable_samplepair_t restrict __near *,int restrict __near *,short restrict __near *,int,unsigned int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SW_Mix16Stereo_Shift_OptMeta<3>(
        portable_samplepair_t *pOutput,
        int *pVolume,
        __int16 *pData,
        int nInputOffset,
        unsigned int nRateScaleFix,
        unsigned int nOutCount)
{
  int *v7; // eax
  int v8; // ebx
  portable_samplepair_t *v9; // esi
  unsigned int v10; // edi
  __int16 *v11; // edx
  int *p_right; // eax
  int v13; // ecx
  int v14; // ecx
  int v15; // ecx
  int v16; // ecx
  unsigned int v17; // edx
  bool v18; // zf
  int v19; // ecx
  unsigned int v20; // [esp+Ch] [ebp-8h]
  int v21; // [esp+10h] [ebp-4h]
  int v22; // [esp+10h] [ebp-4h]
  __int16 *pDataa; // [esp+24h] [ebp+10h]
  __int16 *pDatab; // [esp+24h] [ebp+10h]
  __int16 *pDatac; // [esp+24h] [ebp+10h]
  int nInputOffseta; // [esp+28h] [ebp+14h]
  int nInputOffsetb; // [esp+28h] [ebp+14h]

  v7 = pVolume;
  v8 = nOutCount;
  v9 = pOutput;
  v10 = nRateScaleFix;
  if ( (int)nOutCount < 4 )
  {
    v11 = pData;
  }
  else
  {
    nInputOffseta = *pVolume;
    v20 = nOutCount >> 2;
    v21 = pVolume[1];
    nOutCount -= 4 * (nOutCount >> 2);
    v11 = pData;
    p_right = &pOutput[2].right;
    do
    {
      v9->left += (nInputOffseta * *v11) >> 8;
      *(p_right - 4) += (v21 * v11[1]) >> 8;
      v10 = nRateScaleFix;
      v13 = nRateScaleFix + nInputOffset;
      pDataa = &v11[(v13 >> 27) & 0xFFFFFFFE];
      *(p_right - 3) += (nInputOffseta * *pDataa) >> 8;
      *(p_right - 2) += (v21 * pDataa[1]) >> 8;
      v14 = nRateScaleFix + (v13 & 0xFFFFFFF);
      pDatab = &pDataa[(v14 >> 27) & 0xFFFFFFFE];
      *(p_right - 1) += (nInputOffseta * *pDatab) >> 8;
      *p_right += (v21 * pDatab[1]) >> 8;
      v15 = nRateScaleFix + (v14 & 0xFFFFFFF);
      pDatac = &pDatab[(v15 >> 27) & 0xFFFFFFFE];
      p_right[1] += (nInputOffseta * *pDatac) >> 8;
      p_right[2] += (v21 * pDatac[1]) >> 8;
      v16 = nRateScaleFix + (v15 & 0xFFFFFFF);
      v17 = (v16 >> 27) & 0xFFFFFFFE;
      nInputOffset = v16 & 0xFFFFFFF;
      v9 += 4;
      p_right += 8;
      v18 = v20-- == 1;
      v11 = &pDatac[v17];
    }
    while ( !v18 );
    v8 = nOutCount;
    v7 = pVolume;
  }
  if ( v8 > 0 )
  {
    nInputOffsetb = *v7;
    v22 = v7[1];
    do
    {
      v9->left += (nInputOffsetb * *v11) >> 8;
      v9->right += (v22 * v11[1]) >> 8;
      v19 = v10 + nInputOffset;
      v11 += (v19 >> 27) & 0xFFFFFFFE;
      nInputOffset = v19 & 0xFFFFFFF;
      ++v9;
      --nOutCount;
    }
    while ( (int)nOutCount > 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002DF90
// Name: _MIX_FreeAllPaintbuffers
// Source: json
//------------------------------------------------------------------------------
void MIX_FreeAllPaintbuffers()
{
  int i; // esi
  portable_samplepair_t *pbuf; // eax
  portable_samplepair_t *pbufrear; // eax
  portable_samplepair_t *pbufcenter; // eax

  if ( g_paintBuffers != nullptr )
  {
    if ( g_temppaintbuffer != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: *(void **)(((unsigned int)g_temppaintbuffer & 0xFFFFFFFC) - 4));
      g_temppaintbuffer = nullptr;
    }
    for ( i = 0; i < 6; ++i )
    {
      pbuf = g_paintBuffers[i].pbuf;
      if ( pbuf != nullptr )
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: *(void **)(((unsigned int)pbuf & 0xFFFFFFFC) - 4));
      pbufrear = g_paintBuffers[i].pbufrear;
      if ( pbufrear != nullptr )
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: *(void **)(((unsigned int)pbufrear & 0xFFFFFFFC) - 4));
      pbufcenter = g_paintBuffers[i].pbufcenter;
      if ( pbufcenter != nullptr )
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: *(void **)(((unsigned int)pbufcenter & 0xFFFFFFFC) - 4));
    }
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: g_paintBuffers);
    g_paintBuffers = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002E070
// Name: _MIX_InitAllPaintbuffers
// Source: json
//------------------------------------------------------------------------------
char __cdecl MIX_InitAllPaintbuffers()
{
  void *v0; // eax
  portable_samplepair_t *v1; // ecx
  int i; // esi
  void *v3; // eax
  portable_samplepair_t *v4; // ecx
  void *v5; // eax
  portable_samplepair_t *v6; // ecx
  void *v7; // eax
  portable_samplepair_t *v8; // ecx
  bool bSurroundCenter; // [esp+6h] [ebp-2h]
  bool bSurround; // [esp+7h] [ebp-1h]

  bSurroundCenter = g_AudioDevice->IsSurroundCenter(this: g_AudioDevice);
  if ( g_AudioDevice->IsSurround(this: g_AudioDevice) || (bSurround = false, bSurroundCenter) )
    bSurround = true;
  g_paintBuffers = (paintbuffer_t *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 1872);
  _V_memset(dest: g_paintBuffers, fill: 0, count: 1872);
  v0 = _g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 32787);
  if ( v0 != nullptr )
  {
    v1 = (portable_samplepair_t *)(((unsigned int)v0 + 19) & 0xFFFFFFF0);
    v1[-1].right = (int)v0;
  }
  else
  {
    v1 = nullptr;
  }
  g_temppaintbuffer = v1;
  _V_memset(dest: v1, fill: 0, count: 0x8000);
  for ( i = 0; i < 6; ++i )
  {
    v3 = _g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 8211);
    if ( v3 != nullptr )
    {
      v4 = (portable_samplepair_t *)(((unsigned int)v3 + 19) & 0xFFFFFFF0);
      v4[-1].right = (int)v3;
    }
    else
    {
      v4 = nullptr;
    }
    g_paintBuffers[i].pbuf = v4;
    _V_memset(dest: g_paintBuffers[i].pbuf, fill: 0, count: 0x2000);
    if ( bSurround )
    {
      v5 = _g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 8211);
      if ( v5 != nullptr )
      {
        v6 = (portable_samplepair_t *)(((unsigned int)v5 + 19) & 0xFFFFFFF0);
        v6[-1].right = (int)v5;
      }
      else
      {
        v6 = nullptr;
      }
      g_paintBuffers[i].pbufrear = v6;
      _V_memset(dest: g_paintBuffers[i].pbufrear, fill: 0, count: 0x2000);
    }
    if ( bSurroundCenter )
    {
      v7 = _g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 8211);
      if ( v7 != nullptr )
      {
        v8 = (portable_samplepair_t *)(((unsigned int)v7 + 19) & 0xFFFFFFF0);
        v8[-1].right = (int)v7;
      }
      else
      {
        v8 = nullptr;
      }
      g_paintBuffers[i].pbufcenter = v8;
      _V_memset(dest: g_paintBuffers[i].pbufcenter, fill: 0, count: 0x2000);
    }
  }
  g_paintbuffer = g_paintBuffers->pbuf;
  g_paintBuffers[1].flags = 1;
  g_paintBuffers[2].flags = 2;
  g_paintBuffers[3].flags = 4;
  g_paintBuffers[5].flags = 8;
  g_paintBuffers[4].flags = 16;
  g_paintBuffers->fsurround = bSurround;
  g_paintBuffers[2].fsurround = bSurround;
  g_paintBuffers[3].fsurround = bSurround;
  g_paintBuffers[4].fsurround = bSurround;
  g_paintBuffers->fsurround_center = bSurroundCenter;
  g_paintBuffers[2].fsurround_center = bSurroundCenter;
  g_paintBuffers[3].fsurround_center = bSurroundCenter;
  g_paintBuffers[4].fsurround_center = bSurroundCenter;
  g_paintBuffers[1].fsurround = false;
  g_paintBuffers[1].fsurround_center = false;
  g_paintBuffers[5].fsurround = false;
  g_paintBuffers[5].fsurround_center = false;
  g_curpaintbuffer = g_paintBuffers->pbuf;
  if ( g_paintBuffers->fsurround )
  {
    g_currearpaintbuffer = g_paintBuffers->pbufrear;
    g_curcenterpaintbuffer = nullptr;
    if ( g_paintBuffers->fsurround_center )
    {
      g_curcenterpaintbuffer = g_paintBuffers->pbufcenter;
      return 1;
    }
  }
  else
  {
    g_currearpaintbuffer = nullptr;
    g_curcenterpaintbuffer = nullptr;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1002E330
// Name: void SDEBUG_GetAvgValue(int,int,float __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SDEBUG_GetAvgValue(int ibuf, int count, float *pav)
{
  float v3; // xmm1_4
  int v4; // esi
  unsigned int v5; // eax
  float v6; // xmm0_4
  float v7; // xmm0_4
  int v8; // eax

  if ( snd_showstart.m_pParent != nullptr && snd_showstart.m_pParent->m_Value.m_nValue == 4 )
  {
    v3 = 0.0;
    v4 = 0;
    if ( count >= 4 )
    {
      v5 = ((unsigned int)(count - 4) >> 2) + 1;
      v6 = (float)(int)(abs32(g_paintBuffers[ibuf].pbuf->left) + abs32(g_paintBuffers[ibuf].pbuf->right)) * 0.5;
      v4 = 4 * v5;
      do
      {
        --v5;
        v3 = (float)((float)((float)(v3 + v6) + v6) + v6) + v6;
      }
      while ( v5 != 0 );
    }
    if ( v4 < count )
    {
      v7 = (float)(int)(abs32(g_paintBuffers[ibuf].pbuf->left) + abs32(g_paintBuffers[ibuf].pbuf->right)) * 0.5;
      v8 = count - v4;
      do
      {
        --v8;
        v3 = v3 + v7;
      }
      while ( v8 != 0 );
    }
    *pav = v3 / (float)count;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002E420
// Name: public: void CChannelCullList::Initialize(class CChannelList __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChannelCullList::Initialize(CChannelCullList *this, CChannelList *list)
{
  CChannelList *v2; // ebx
  int m_count; // esi
  int v5; // esi
  unsigned int *p_m_nameHash; // eax
  __int16 *v7; // ebx
  int v8; // ebx
  bool v9; // zf
  channel_t *v10; // ebx
  int m_numChans; // edx
  CChannelCullList::sChannelVolData *v12; // eax
  int v13; // ecx
  int v14; // edx
  __int16 *m_list; // ebx
  channel_t *v16; // ecx
  int v17; // ebx
  int v18; // eax
  CChannelCullList *v19; // esi
  __int16 *v20; // [esp+Ch] [ebp-8h]
  __int16 *v21; // [esp+Ch] [ebp-8h]
  unsigned int *v22; // [esp+10h] [ebp-4h]
  int cutoff; // [esp+1Ch] [ebp+8h]

  v2 = list;
  m_count = list->m_count;
  this->m_numChans = list->m_count;
  v5 = m_count - 1;
  if ( v5 >= 0 )
  {
    p_m_nameHash = &this->m_channelInfo[v5].m_nameHash;
    v7 = &list->m_list[v5];
    v22 = p_m_nameHash;
    v20 = v7;
    while ( 1 )
    {
      v8 = *v7;
      v9 = &channels[v8] == nullptr;
      v10 = &channels[v8];
      *(p_m_nameHash - 2) = v5;
      if ( v9 )
        goto LABEL_7;
      if ( !v10->pMixer->IsReadyToMix(this: v10->pMixer) )
        break;
      *(v22 - 1) = (int)ChannelLoudestCurVolume(pch: v10);
      *v22 = (unsigned int)v10->sfx;
      p_m_nameHash = v22;
LABEL_8:
      v7 = v20 - 1;
      p_m_nameHash -= 3;
      --v5;
      --v20;
      v22 = p_m_nameHash;
      if ( v5 < 0 )
      {
        v2 = list;
        goto LABEL_10;
      }
    }
    p_m_nameHash = v22;
LABEL_7:
    *(p_m_nameHash - 1) = -1;
    *p_m_nameHash = 0;
    goto LABEL_8;
  }
LABEL_10:
  m_numChans = this->m_numChans;
  if ( m_numChans < 128 )
  {
    v12 = &this->m_channelInfo[m_numChans];
    v13 = 128 - m_numChans;
    do
    {
      v12->m_channelNum = -1;
      v12->m_vol = -1;
      ++v12;
      --v13;
    }
    while ( v13 != 0 );
  }
  qsort(base: this, num: 0x80u, width: 0xCu, comp: (int (__cdecl *)(const void *, const void *))ChannelVolComparator);
  v14 = 0;
  if ( snd_cull_duplicates.m_pParent != nullptr )
    cutoff = snd_cull_duplicates.m_pParent->m_Value.m_nValue;
  else
    cutoff = 0;
  if ( this->m_numChans > 0 )
  {
    m_list = v2->m_list;
    v21 = m_list;
    do
    {
      v16 = &channels[*m_list];
      v17 = 0;
      v18 = 0;
      if ( this->m_channelInfo[0].m_channelNum != v14 )
      {
        v19 = this;
        do
        {
          if ( v19->m_channelInfo[0].m_vol < 0 || v18 >= 128 )
            break;
          if ( (CSfxTable *)v19->m_channelInfo[0].m_nameHash == v16->sfx )
            ++v17;
          ++v18;
          v19 = (CChannelCullList *)((char *)this + 12 * v18);
        }
        while ( v19->m_channelInfo[0].m_channelNum != v14 );
      }
      this->m_bShouldCull[v14++] = v17 >= cutoff;
      m_list = ++v21;
    }
    while ( v14 < this->m_numChans );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002E590
// Name: bool MIX_ScaleChannelVolume(struct paintbuffer_t __near *,struct channel_t __near *,int __near * const,int)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl MIX_ScaleChannelVolume(paintbuffer_t *ppaint, channel_t *pChannel, int *volume)
{
  float v4; // xmm3_4
  int v5; // edi
  CAudioSource *v6; // eax
  int i; // eax
  int v8; // ecx
  int j; // eax
  float v10; // xmm0_4
  int k; // eax
  int m; // eax
  int v13; // edi
  int v14; // ebx
  int v15; // kr00_4
  int v16; // eax
  char v17; // cl
  int *v18; // esi
  int n; // edx
  int v20; // eax
  int v21; // eax
  int v22; // eax
  int v23; // eax
  int v24; // eax
  int v25; // eax
  int mixflag; // [esp+Ch] [ebp-8h]
  float dspmix; // [esp+10h] [ebp-4h]
  int nFrontRightD; // [esp+1Ch] [ebp+8h]
  int nFrontLeftD; // [esp+20h] [ebp+Ch]
  char nFrontLeftD_3; // [esp+23h] [ebp+Fh]

  mixflag = ppaint->flags;
  nFrontLeftD_3 = pChannel->wavtype;
  ChannelCopyVolumes(pch: pChannel, pvolume_dest: volume, ivol_start: 0, cvol: 12);
  dspmix = pChannel->dspmix * 256.0;
  if ( g_bDspOff || DSP_RoomDSPIsOff() )
  {
    v4 = 0.0;
    dspmix = 0.0;
  }
  else
  {
    v4 = dspmix;
  }
  v5 = g_SND_VoiceOverdriveInt;
  if ( g_DuckScaleInt256 < g_SND_VoiceOverdriveInt )
    v5 = g_DuckScaleInt256;
  if ( v5 < 256 && pChannel->pMixer != nullptr )
  {
    v6 = pChannel->pMixer->GetSource(this: pChannel->pMixer);
    if ( !v6->IsVoiceSource(this: v6) )
    {
      for ( i = 0; i < 12; ++i )
        volume[i] = (v5 * volume[i]) >> 8;
    }
    v4 = dspmix;
  }
  if ( (mixflag & 1) != 0 )
  {
    v8 = (int)(float)(g_dsp_volume * v4);
    if ( v8 >= 256 )
      v8 = 256;
    for ( j = 0; j < 12; ++j )
      volume[j] = (v8 * volume[j]) >> 8;
  }
  if ( g_dsp_volume < 1.0 )
    v4 = g_dsp_volume * v4;
  v10 = (float)((float)(pChannel->dspface + 1.0) * 0.5) * 1.6666666;
  if ( v10 >= 0.0 )
  {
    if ( v10 > 1.0 )
      v10 = 1.0;
  }
  else
  {
    v10 = 0.0;
  }
  if ( !g_bdirectionalfx || nFrontLeftD_3 != 60 )
    v10 = 1.0;
  if ( (mixflag & 2) != 0 )
  {
    for ( k = 0; k < 12; ++k )
      volume[k] = ((int)(float)((float)(256.0 - v4) * v10) * volume[k]) >> 8;
  }
  else if ( (mixflag & 4) != 0 )
  {
    for ( m = 0; m < 12; ++m )
      volume[m] = ((int)(float)((float)(1.0 - v10) * (float)(256.0 - v4)) * volume[m]) >> 8;
  }
  if ( g_AudioDevice->IsSurround(this: g_AudioDevice) && !ppaint->fsurround )
  {
    v13 = volume[1] + volume[3];
    v14 = volume[2] + *volume;
    nFrontRightD = volume[7] + volume[9];
    nFrontLeftD = volume[6] + volume[8];
    if ( g_AudioDevice->IsSurroundCenter(this: g_AudioDevice) )
    {
      v15 = volume[4];
      v13 += v15 / 2;
      v14 += v15 / 2;
      v16 = volume[10] / 2;
      nFrontRightD += v16;
      nFrontLeftD += v16;
    }
    volume[1] = v13;
    *volume = v14;
    volume[7] = nFrontRightD;
    volume[6] = nFrontLeftD;
    volume[3] = 0;
    volume[2] = 0;
    volume[4] = 0;
    volume[9] = 0;
    volume[8] = 0;
    volume[10] = 0;
  }
  v17 = 1;
  v18 = volume + 2;
  for ( n = 2; n != 0; --n )
  {
    v20 = *(v18 - 2);
    if ( v20 >= 0 )
    {
      if ( v20 > 255 )
        v20 = 255;
    }
    else
    {
      v20 = 0;
    }
    *(v18 - 2) = v20;
    if ( v20 != 0 )
      v17 = 0;
    v21 = *(v18 - 1);
    if ( v21 >= 0 )
    {
      if ( v21 > 255 )
        v21 = 255;
    }
    else
    {
      v21 = 0;
    }
    *(v18 - 1) = v21;
    if ( v21 != 0 )
      v17 = 0;
    v22 = *v18;
    if ( *v18 >= 0 )
    {
      if ( v22 > 255 )
        v22 = 255;
    }
    else
    {
      v22 = 0;
    }
    *v18 = v22;
    if ( v22 != 0 )
      v17 = 0;
    v23 = v18[1];
    if ( v23 >= 0 )
    {
      if ( v23 > 255 )
        v23 = 255;
    }
    else
    {
      v23 = 0;
    }
    v18[1] = v23;
    if ( v23 != 0 )
      v17 = 0;
    v24 = v18[2];
    if ( v24 >= 0 )
    {
      if ( v24 > 255 )
        v24 = 255;
    }
    else
    {
      v24 = 0;
    }
    v18[2] = v24;
    if ( v24 != 0 )
      v17 = 0;
    v25 = v18[3];
    if ( v25 >= 0 )
    {
      if ( v25 > 255 )
        v25 = 255;
    }
    else
    {
      v25 = 0;
    }
    v18[3] = v25;
    if ( v25 != 0 )
      v17 = 0;
    v18 += 6;
  }
  return v17 == 0;
}

//------------------------------------------------------------------------------
// Address: 0x1002E8C0
// Name: void SW_Mix16StereoDistVar(float,struct portable_samplepair_t __near *,int __near *,short __near *,int,unsigned int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SW_Mix16StereoDistVar(
        float distmix,
        portable_samplepair_t *pOutput,
        int *volume,
        __int16 *pData,
        int inputOffset,
        unsigned int rateScaleFix,
        int outCount)
{
  int v8; // esi
  int k; // eax
  int v10; // edi
  int v11; // ecx
  int j; // eax
  int v13; // edi
  int v14; // ecx
  int i; // edx
  int v16; // eax
  int v17; // ecx
  int inputOffseta; // [esp+24h] [ebp+18h]

  v8 = 0;
  inputOffseta = (int)(float)(distmix * 256.0);
  if ( (int)(float)((float)(1.0 - distmix) * 256.0) != 0 )
  {
    if ( inputOffseta != 0 )
    {
      for ( i = 0; i < outCount; inputOffset = v17 & 0xFFFFFFF )
      {
        v16 = pData[v8] + ((inputOffseta * (pData[v8 + 1] - pData[v8])) >> 8);
        v17 = rateScaleFix + inputOffset;
        pOutput[i].left += (v16 * *volume) >> 8;
        pOutput[i++].right += (v16 * volume[1]) >> 8;
        v8 += (v17 >> 27) & 0xFFFFFFFE;
      }
    }
    else
    {
      for ( j = 0; j < outCount; inputOffset = v14 & 0xFFFFFFF )
      {
        v13 = pData[v8];
        v14 = rateScaleFix + inputOffset;
        pOutput[j].left += (v13 * *volume) >> 8;
        pOutput[j++].right += (v13 * volume[1]) >> 8;
        v8 += (v14 >> 27) & 0xFFFFFFFE;
      }
    }
  }
  else
  {
    for ( k = 0; k < outCount; inputOffset = v11 & 0xFFFFFFF )
    {
      v10 = pData[v8 + 1];
      v11 = rateScaleFix + inputOffset;
      pOutput[k].left += (v10 * *volume) >> 8;
      pOutput[k++].right += (v10 * volume[1]) >> 8;
      v8 += (v11 >> 27) & 0xFFFFFFFE;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002EA60
// Name: void SW_Mix16StereoDistVar_Interp(float,struct portable_samplepair_t __near *,int __near *,short __near *,int,unsigned int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SW_Mix16StereoDistVar_Interp(
        float distmix,
        portable_samplepair_t *pOutput,
        int *volume,
        __int16 *pData,
        unsigned int inputOffset,
        unsigned int rateScaleFix,
        int outCount)
{
  int v7; // edx
  unsigned int v8; // ecx
  int k; // esi
  int v10; // ebx
  int v11; // eax
  int v12; // ecx
  int j; // esi
  int v14; // eax
  int v15; // ecx
  int i; // edi
  int v17; // ebx
  int v18; // esi
  int v19; // eax
  int v20; // ecx
  unsigned int rateScaleFix14; // [esp+8h] [ebp-4h]
  unsigned int rateScaleFixa; // [esp+28h] [ebp+1Ch]

  v7 = 0;
  rateScaleFix14 = rateScaleFix >> 14;
  v8 = inputOffset >> 14;
  rateScaleFixa = (int)(float)(distmix * 256.0);
  if ( (int)(float)((float)(1.0 - distmix) * 256.0) != 0 )
  {
    if ( rateScaleFixa != 0 )
    {
      for ( i = 0; i < outCount; v8 = v20 & 0x3FFF )
      {
        v17 = pData[v7 + 1];
        v18 = pData[v7] + ((int)(v8 * (pData[v7 + 2] - pData[v7])) >> 14);
        v19 = v18 + ((int)(rateScaleFixa * (v17 + ((int)(v8 * (pData[v7 + 3] - v17)) >> 14) - v18)) >> 8);
        v20 = rateScaleFix14 + v8;
        pOutput[i].left += (v19 * *volume) >> 8;
        pOutput[i++].right += (v19 * volume[1]) >> 8;
        v7 += (v20 >> 13) & 0xFFFFFFFE;
      }
    }
    else
    {
      for ( j = 0; j < outCount; v8 = v15 & 0x3FFF )
      {
        v14 = pData[v7] + ((int)(v8 * (pData[v7 + 2] - pData[v7])) >> 14);
        v15 = rateScaleFix14 + v8;
        pOutput[j].left += (v14 * *volume) >> 8;
        pOutput[j++].right += (v14 * volume[1]) >> 8;
        v7 += (v15 >> 13) & 0xFFFFFFFE;
      }
    }
  }
  else
  {
    for ( k = 0; k < outCount; v8 = v12 & 0x3FFF )
    {
      v10 = pData[v7 + 1];
      v11 = v10 + ((int)(v8 * (pData[v7 + 3] - v10)) >> 14);
      v12 = rateScaleFix14 + v8;
      pOutput[k].left += (v11 * *volume) >> 8;
      pOutput[k++].right += (v11 * volume[1]) >> 8;
      v7 += (v12 >> 13) & 0xFFFFFFFE;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002EC50
// Name: void SW_Mix16Stereo_Opt(struct portable_samplepair_t restrict __near *,int restrict __near *,short restrict __near *,int,unsigned int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SW_Mix16Stereo_Opt(
        portable_samplepair_t *pOutput,
        int *pVolume,
        __int16 *pData,
        int nInputOffset,
        unsigned int nRateScaleFix,
        unsigned int nOutCount)
{
  int v6; // ecx
  int v7; // edx

  v6 = *pVolume;
  v7 = pVolume[1];
  if ( nRateScaleFix == 0x10000000 )
  {
    if ( v6 == v7 )
    {
      SW_Mix16Stereo_NoShift_OptMeta<0>(pOutput, pVolume, pData, nOutCount);
    }
    else if ( v6 > 1 )
    {
      if ( v7 > 1 )
        SW_Mix16Stereo_NoShift_OptMeta<3>(pOutput, pVolume, pData, nOutCount);
      else
        SW_Mix16Stereo_NoShift_OptMeta<2>(pOutput, pVolume, pData, nOutCount);
    }
    else
    {
      SW_Mix16Stereo_NoShift_OptMeta<1>(pOutput, pVolume, pData, nOutCount);
    }
  }
  else if ( v6 == v7 )
  {
    SW_Mix16Stereo_Shift_OptMeta<0>(pOutput, pVolume, pData, nInputOffset, nRateScaleFix, nOutCount);
  }
  else if ( v6 > 1 )
  {
    if ( v7 > 1 )
      SW_Mix16Stereo_Shift_OptMeta<3>(pOutput, pVolume, pData, nInputOffset, nRateScaleFix, nOutCount);
    else
      SW_Mix16Stereo_Shift_OptMeta<2>(pOutput, pVolume, pData, nInputOffset, nRateScaleFix, nOutCount);
  }
  else
  {
    SW_Mix16Stereo_Shift_OptMeta<1>(pOutput, pVolume, pData, nInputOffset, nRateScaleFix, nOutCount);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002ED30
// Name: bool FUseHighQualityPitch(struct channel_t __near *)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl FUseHighQualityPitch(channel_t *pChannel)
{
  float pitch; // [esp+8h] [ebp-4h]

  if ( snd_pitchquality.m_pParent == nullptr
    || snd_pitchquality.m_pParent->m_Value.m_nValue == 0
    || (*((_BYTE *)&pChannel->flags + 1) & 2) != 0 )
  {
    return false;
  }
  pitch = pChannel->pitch;
  return pitch != floor(X: pitch);
}

//------------------------------------------------------------------------------
// Address: 0x1002ED90
// Name: _Mix8MonoWavtype
// Source: json
//------------------------------------------------------------------------------
void __cdecl Mix8MonoWavtype(
        channel_t *pChannel,
        portable_samplepair_t *pOutput,
        int *volume,
        unsigned __int8 *pData,
        int *inputOffset,
        int *rateScaleFix,
        int outCount)
{
  float pitch; // [esp+8h] [ebp-4h]

  if ( snd_pitchquality.m_pParent == nullptr
    || snd_pitchquality.m_pParent->m_Value.m_nValue == 0
    || (*((_BYTE *)&pChannel->flags + 1) & 2) != 0
    || (pitch = pChannel->pitch) == floor(X: pitch) )
  {
    SW_Mix8Mono(pOutput, volume, pData, (int)inputOffset, (unsigned int)rateScaleFix, outCount);
  }
  else
  {
    SW_Mix8Mono_Interp(pOutput, volume, pData, inputOffset, rateScaleFix, outCount);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002EE20
// Name: _Mix16MonoWavtype
// Source: json
//------------------------------------------------------------------------------
void __cdecl Mix16MonoWavtype(
        channel_t *pChannel,
        portable_samplepair_t *pOutput,
        int *volume,
        __int16 *pData,
        int inputOffset,
        unsigned int rateScaleFix,
        int outCount)
{
  if ( *volume + volume[1] > 2 )
  {
    if ( FUseHighQualityPitch(pChannel) )
      SW_Mix16Mono_Interp(pOutput, volume, pData, inputOffset, rateScaleFix, outCount);
    else
      SW_Mix16Mono(pOutput, volume, pData, inputOffset, rateScaleFix, outCount);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002EE90
// Name: void SND_MovieStart(void)
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __cdecl SND_MovieStart()
{
  if ( cl_movieinfo.moviename[0] != 0 )
  {
    g_soundtimeerror = 0.0;
    g_nMovieStartTick = host_tickcount;
    g_paintedtime = 0;
    g_soundtime = 0;
    g_moviestart = host_time;
    if ( snd_surround.m_pParent == nullptr || snd_surround.m_pParent->m_Value.m_nValue != 2 )
      CLoaderMemAlloc::CrtIsValidPointer(this: (ConVar *)&snd_surround.IConVar, value: 2);
    if ( (cl_movieinfo.type & 4) != 0 )
      WaveCreateTmpFile(filename: cl_movieinfo.moviename, rate: 44100, bits: 16, channels: 2);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002EF20
// Name: _S_TransferPaintBuffer
// Source: json
//------------------------------------------------------------------------------
void __cdecl S_TransferPaintBuffer(
        _WORD *pOutput,
        const portable_samplepair_t *pfront,
        __int64 lpaintedtime,
        __int64 endtime)
{
  int v4; // edi
  int v5; // esi
  int v6; // ebx
  int v7; // eax
  int v8; // ebx
  int v9; // eax
  int v10; // [esp+20h] [ebp+14h]
  int v11; // [esp+28h] [ebp+1Ch]

  v4 = (endtime - lpaintedtime) * g_AudioDevice->DeviceChannels(this: g_AudioDevice);
  v11 = g_AudioDevice->DeviceSampleCount(this: g_AudioDevice) - 1;
  v5 = v11 & (lpaintedtime * g_AudioDevice->DeviceChannels(this: g_AudioDevice));
  v6 = 3 - g_AudioDevice->DeviceChannels(this: g_AudioDevice);
  v10 = (int)(S_GetMasterVolume() * 256.0);
  if ( g_AudioDevice->DeviceSampleBits(this: g_AudioDevice) == 16 )
  {
    for ( ; v4 != 0; v5 = v11 & (v5 + 1) )
    {
      v7 = (v10 * pfront->left) >> 8;
      --v4;
      pfront = (const portable_samplepair_t *)((char *)pfront + 4 * v6);
      if ( v7 >= -32767 )
      {
        if ( v7 > 0x7FFF )
          LOWORD(v7) = 0x7FFF;
      }
      else
      {
        LOWORD(v7) = -32767;
      }
      pOutput[v5] = v7;
    }
  }
  else if ( g_AudioDevice->DeviceSampleBits(this: g_AudioDevice) == 8 && v4 != 0 )
  {
    v8 = 4 * v6;
    do
    {
      v9 = (v10 * pfront->left) >> 8;
      --v4;
      pfront = (const portable_samplepair_t *)((char *)pfront + v8);
      if ( v9 >= -32767 )
      {
        if ( v9 > 0x7FFF )
          BYTE1(v9) = 127;
      }
      else
      {
        BYTE1(v9) = 0x80;
      }
      *((_BYTE *)pOutput + v5) = BYTE1(v9) + 0x80;
      v5 = v11 & (v5 + 1);
    }
    while ( v4 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002F060
// Name: _S_MixBufferUpsample2x
// Source: json
//------------------------------------------------------------------------------
void __cdecl S_MixBufferUpsample2x(
        int count,
        portable_samplepair_t *pbuffer,
        portable_samplepair_t *pfiltermem,
        int cfltmem,
        int filtertype)
{
  int v5; // edx
  portable_samplepair_t *v6; // eax
  portable_samplepair_t *v7; // ecx

  if ( filtertype == 1 )
  {
    if ( snd_mix_optimization.m_pParent != nullptr && snd_mix_optimization.m_pParent->m_Value.m_nValue != 0 )
      S_Interpolate2xLinear_3(count, pbuffer, pfiltermem);
    else
      S_Interpolate2xLinear_2(count, pbuffer, pfiltermem);
  }
  else
  {
    v5 = count - 1;
    if ( count - 1 >= 0 )
    {
      v6 = &pbuffer[2 * count - 1];
      v7 = &pbuffer[v5];
      do
      {
        v6->left = v7->left;
        v6->right = v7->right;
        v6[-1].left = v7->left;
        v6[-1].right = v7->right;
        v6 -= 2;
        --v7;
        --v5;
      }
      while ( v5 >= 0 );
    }
    if ( filtertype == 2 )
      S_Interpolate2xCubic(pbuffer, pfiltermem, cfltmem, count);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002F120
// Name: void MIX_MixPaintbuffers(int,int,int,int,float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MIX_MixPaintbuffers(
        int ibuf1,
        portable_samplepair_t *ibuf2,
        int ibuf3,
        portable_samplepair_t *count,
        float fgain_out)
{
  paintbuffer_t *v6; // edx
  portable_samplepair_t *pbuf; // ecx
  bool v8; // zf
  int v9; // edx
  portable_samplepair_t *v10; // esi
  portable_samplepair_t *v11; // eax
  portable_samplepair_t *pbufrear; // edi
  unsigned int v13; // edx
  portable_samplepair_t *v14; // edx
  portable_samplepair_t *v15; // edx
  char *v16; // ebx
  int *p_right; // edx
  portable_samplepair_t *v18; // edi
  int v19; // eax
  int v20; // ecx
  int v21; // ecx
  portable_samplepair_t *i; // eax
  int *v23; // edx
  char *v24; // ebx
  char *v25; // edi
  portable_samplepair_t *v26; // eax
  int v27; // ecx
  char *v28; // ebx
  portable_samplepair_t *v29; // edi
  int v30; // ecx
  int *v31; // eax
  portable_samplepair_t *v32; // ebx
  int *v33; // edx
  int *p_left; // edi
  int v35; // eax
  int v36; // ecx
  int v37; // ebx
  portable_samplepair_t *v38; // edx
  int *v39; // eax
  int v40; // ebx
  portable_samplepair_t *v41; // edx
  int v42; // ecx
  int v43; // edi
  char *v44; // ebx
  portable_samplepair_t *v45; // eax
  int v46; // ebx
  int v47; // edi
  int v48; // ecx
  portable_samplepair_t *v49; // eax
  portable_samplepair_t *v50; // edx
  int v51; // ecx
  int v52; // ebx
  int v53; // edi
  int v54; // edi
  int v55; // ecx
  char *v56; // ebx
  char *v57; // eax
  int *v58; // ecx
  portable_samplepair_t *v59; // edx
  char *v60; // edi
  int v61; // eax
  int *v62; // edx
  portable_samplepair_t *v63; // ecx
  portable_samplepair_t *v64; // eax
  int v65; // ecx
  int v66; // edi
  int *v67; // edx
  char *v68; // ecx
  portable_samplepair_t *v69; // ebx
  int v70; // ecx
  int v71; // edi
  char *v72; // ebx
  portable_samplepair_t **v73; // edx
  portable_samplepair_t *v74; // ecx
  int left; // eax
  int v76; // edi
  portable_samplepair_t *v77; // ebx
  int v78; // edi
  int *v79; // edx
  int *v80; // ecx
  int v81; // eax
  int v82; // edi
  int v83; // ebx
  int v84; // edi
  portable_samplepair_t *v85; // eax
  int *v86; // edx
  int v87; // ecx
  int v88; // edi
  int v89; // ebx
  int v90; // ebx
  char *v91; // edi
  int v92; // edx
  portable_samplepair_t *v93; // ecx
  int *v94; // eax
  int *v95; // edi
  char *v96; // eax
  int v97; // ebx
  char *v98; // eax
  int *v99; // ebx
  int v100; // edi
  int v101; // edx
  int *v102; // eax
  char *v103; // ebx
  portable_samplepair_t *v104; // eax
  int *v105; // ecx
  portable_samplepair_t *v106; // edi
  int v107; // ebx
  int v108; // eax
  char *v109; // ebx
  portable_samplepair_t *v110; // eax
  int v111; // ecx
  portable_samplepair_t *v112; // edi
  int v113; // eax
  int v114; // edx
  int v115; // edx
  portable_samplepair_t *v116; // ecx
  int v117; // edi
  int *v118; // eax
  int v119; // esi
  CMixData data; // [esp+4h] [ebp-60h] BYREF
  int *v121; // [esp+2Ch] [ebp-38h]
  portable_samplepair_t *pbufcentert; // [esp+30h] [ebp-34h]
  int gain_out; // [esp+34h] [ebp-30h]
  portable_samplepair_t *pbufrear1; // [esp+38h] [ebp-2Ch]
  int cchan3; // [esp+3Ch] [ebp-28h]
  portable_samplepair_t *pbufcenter3; // [esp+40h] [ebp-24h]
  int l2; // [esp+44h] [ebp-20h]
  portable_samplepair_t *pbufcenter1; // [esp+48h] [ebp-1Ch]
  char *v129; // [esp+4Ch] [ebp-18h]
  int v130; // [esp+50h] [ebp-14h]
  int *v131; // [esp+54h] [ebp-10h]
  char *v132; // [esp+58h] [ebp-Ch]
  int r2; // [esp+5Ch] [ebp-8h]
  char *v134; // [esp+60h] [ebp-4h]
  paintbuffer_t *cchan2q; // [esp+6Ch] [ebp+8h]
  unsigned int cchan2; // [esp+6Ch] [ebp+8h]
  int cchan2a; // [esp+6Ch] [ebp+8h]
  int cchan2b; // [esp+6Ch] [ebp+8h]
  int cchan2c; // [esp+6Ch] [ebp+8h]
  int cchan2d; // [esp+6Ch] [ebp+8h]
  portable_samplepair_t *cchan2e; // [esp+6Ch] [ebp+8h]
  int cchan2f; // [esp+6Ch] [ebp+8h]
  int cchan2g; // [esp+6Ch] [ebp+8h]
  int cchan2h; // [esp+6Ch] [ebp+8h]
  int cchan2i; // [esp+6Ch] [ebp+8h]
  int cchan2j; // [esp+6Ch] [ebp+8h]
  int cchan2k; // [esp+6Ch] [ebp+8h]
  int cchan2l; // [esp+6Ch] [ebp+8h]
  int cchan2m; // [esp+6Ch] [ebp+8h]
  int cchan2n; // [esp+6Ch] [ebp+8h]
  int cchan2o; // [esp+6Ch] [ebp+8h]
  int cchan2p; // [esp+6Ch] [ebp+8h]
  portable_samplepair_t *pbufcenter2; // [esp+70h] [ebp+Ch]
  portable_samplepair_t *pbufcenter2a; // [esp+70h] [ebp+Ch]
  portable_samplepair_t *pbufcenter2e; // [esp+70h] [ebp+Ch]
  portable_samplepair_t *pbufcenter2f; // [esp+70h] [ebp+Ch]
  portable_samplepair_t *pbufcenter2b; // [esp+70h] [ebp+Ch]
  portable_samplepair_t *pbufcenter2c; // [esp+70h] [ebp+Ch]
  portable_samplepair_t *pbufcenter2g; // [esp+70h] [ebp+Ch]
  portable_samplepair_t *pbufcenter2d; // [esp+70h] [ebp+Ch]
  portable_samplepair_t *pbufcenter2h; // [esp+70h] [ebp+Ch]
  portable_samplepair_t *pbufcenter2i; // [esp+70h] [ebp+Ch]
  portable_samplepair_t *pbufcenter2j; // [esp+70h] [ebp+Ch]
  unsigned int cchan1; // [esp+74h] [ebp+10h]
  int cchan1a; // [esp+74h] [ebp+10h]
  int cchan1b; // [esp+74h] [ebp+10h]
  int cchan1c; // [esp+74h] [ebp+10h]
  int cchan1d; // [esp+74h] [ebp+10h]
  int cchan1e; // [esp+74h] [ebp+10h]
  int cchan1f; // [esp+74h] [ebp+10h]
  int cchan1g; // [esp+74h] [ebp+10h]
  int cchan1h; // [esp+74h] [ebp+10h]
  int cchan1i; // [esp+74h] [ebp+10h]
  int cchan1j; // [esp+74h] [ebp+10h]
  int cchan1k; // [esp+74h] [ebp+10h]
  portable_samplepair_t *pbufrear3; // [esp+7Ch] [ebp+18h]
  portable_samplepair_t *pbufrear3a; // [esp+7Ch] [ebp+18h]
  portable_samplepair_t *pbufrear3b; // [esp+7Ch] [ebp+18h]
  portable_samplepair_t *pbufrear3c; // [esp+7Ch] [ebp+18h]
  portable_samplepair_t *pbufrear3d; // [esp+7Ch] [ebp+18h]
  portable_samplepair_t *pbufrear3e; // [esp+7Ch] [ebp+18h]
  portable_samplepair_t *pbufrear3f; // [esp+7Ch] [ebp+18h]

  v6 = &g_paintBuffers[ibuf1];
  pbuf = v6->pbuf;
  pbufrear1 = v6->pbufrear;
  cchan3 = (int)&g_paintBuffers[ibuf3];
  pbufrear3 = *(portable_samplepair_t **)(cchan3 + 12);
  pbufcenter1 = v6->pbufcenter;
  cchan2q = &g_paintBuffers[(_DWORD)ibuf2];
  pbufcenter2 = cchan2q->pbufcenter;
  pbufcenter3 = *(portable_samplepair_t **)(cchan3 + 16);
  v8 = !v6->fsurround_center;
  v9 = v6->fsurround ? 2 : 0;
  v10 = *(portable_samplepair_t **)(cchan3 + 8);
  gain_out = (int)(float)(fgain_out * 256.0);
  v11 = cchan2q->pbuf;
  cchan1 = !v8 + v9 + 2;
  pbufrear = cchan2q->pbufrear;
  cchan2 = cchan2q->fsurround_center + (cchan2q->fsurround ? 2 : 0) + 2;
  cchan3 = (*(_BYTE *)(cchan3 + 2) != 0) + (*(_BYTE *)(cchan3 + 1) != 0 ? 2 : 0) + 2;
  v13 = cchan1;
  if ( cchan2 >= cchan1 )
  {
    v15 = pbufrear1;
  }
  else
  {
    cchan1 = cchan2;
    pbufcentert = pbufcenter1;
    cchan2 = v13;
    v14 = pbuf;
    pbuf = v11;
    pbufcenter1 = pbufcenter2;
    v11 = v14;
    v15 = pbufrear;
    pbufrear = pbufrear1;
    pbufcenter2 = pbufcentert;
  }
  data.count = (int)count;
  data.pbufcenter1 = pbufcenter1;
  data.pbufcenter2 = pbufcenter2;
  data.pbufcenter3 = pbufcenter3;
  data.pbufrear3 = pbufrear3;
  data.pbuf1 = pbuf;
  data.pbuf2 = v11;
  data.pbuf3 = v10;
  data.pbufrear1 = v15;
  data.pbufrear2 = pbufrear;
  if ( cchan3 == 2 )
  {
    if ( cchan1 == 2 )
    {
      if ( cchan2 == 2 )
      {
        if ( (int)count > 0 )
        {
          cchan2a = (char *)v11 - (char *)pbuf;
          v16 = (char *)((char *)v10 - (char *)pbuf);
          p_right = &pbuf->right;
          v18 = v10;
          v19 = (char *)v11 - (char *)v10;
          pbufrear3a = count;
          do
          {
            v20 = *(p_right - 1) + *(int *)((char *)&v18->left + v19);
            p_right += 2;
            v18->left = v20;
            ++v18;
            v8 = pbufrear3a == (portable_samplepair_t *)1;
            pbufrear3a = (portable_samplepair_t *)((char *)pbufrear3a - 1);
            *(int *)((char *)p_right + (_DWORD)v16 - 8) = *(p_right - 2) + *(int *)((char *)p_right + cchan2a - 8);
          }
          while ( !v8 );
        }
      }
      else if ( cchan2 == 4 )
      {
        if ( (int)count > 0 )
        {
          cchan1a = (char *)pbufrear - (char *)v11;
          cchan2b = (char *)pbuf - (char *)v11;
          v23 = &v11->right;
          v24 = (char *)((char *)v10 - (char *)v11);
          v25 = (char *)((char *)pbufrear - (char *)pbuf);
          v134 = (char *)((char *)v10 - (char *)pbuf);
          pbufrear3b = count;
          v132 = v25;
          v26 = pbuf;
          while ( 1 )
          {
            v27 = *(v23 - 1) + *(int *)((char *)&v26->left + (_DWORD)v25);
            v23 += 2;
            *(_DWORD *)&v134[(_DWORD)v26] = v26->left + (v27 >> 1);
            ++v26;
            v8 = pbufrear3b == (portable_samplepair_t *)1;
            pbufrear3b = (portable_samplepair_t *)((char *)pbufrear3b - 1);
            *(int *)((char *)v23 + (_DWORD)v24 - 8) = *(int *)((char *)v23 + cchan2b - 8)
                                                    + ((*(v23 - 2) + *(int *)((char *)v23 + cchan1a - 8)) >> 1);
            if ( v8 )
              break;
            v25 = v132;
          }
        }
      }
      else if ( cchan2 == 5 && (int)count > 0 )
      {
        cchan2d = (char *)v11 - (char *)pbufrear;
        pbufcentert = (portable_samplepair_t *)((char *)pbuf - (char *)pbufrear);
        pbufrear1 = (portable_samplepair_t *)((char *)v10 - (char *)pbufrear);
        pbufrear3d = (portable_samplepair_t *)((char *)pbuf - (char *)pbufcenter2);
        v32 = (portable_samplepair_t *)((char *)v11 - (char *)pbufcenter2);
        v33 = &pbufrear->right;
        p_left = &pbufcenter2->left;
        pbufcenter1 = (portable_samplepair_t *)((char *)v11 - (char *)pbufcenter2);
        v129 = (char *)((char *)v10 - (char *)pbufcenter2);
        pbufcenter2a = count;
        while ( 1 )
        {
          v35 = *p_left >> 1;
          v36 = v35 + *(int *)((char *)v33 + cchan2d);
          *(int *)((char *)p_left + (_DWORD)v129) = *(int *)((char *)p_left + (_DWORD)pbufrear3d)
                                                  + ((v35 + *(v33 - 1) + *(int *)((char *)p_left + (_DWORD)v32)) >> 1);
          *(int *)((char *)v33 + (_DWORD)pbufrear1) = *(int *)((char *)v33 + (_DWORD)pbufcentert) + ((v36 + *v33) >> 1);
          p_left += 2;
          v33 += 2;
          pbufcenter2a = (portable_samplepair_t *)((char *)pbufcenter2a - 1);
          if ( pbufcenter2a == nullptr )
            break;
          v32 = pbufcenter1;
        }
      }
    }
    else if ( cchan1 == 4 )
    {
      if ( cchan2 == 4 )
      {
        if ( (int)count > 0 )
        {
          pbufcentert = (portable_samplepair_t *)&v11->right;
          cchan1b = (char *)pbufrear - (char *)v11;
          v134 = (char *)((char *)v15 - (char *)v11);
          cchan2c = (char *)pbuf - (char *)v11;
          v28 = (char *)((char *)v10 - (char *)v11);
          v29 = (portable_samplepair_t *)((char *)pbufrear - (char *)v15);
          v30 = (char *)pbuf - (char *)v15;
          l2 = (char *)v10 - (char *)v15;
          v31 = &v11->right;
          pbufrear3c = count;
          pbufcenter3 = v29;
          cchan3 = v30;
          while ( 1 )
          {
            *(int *)((char *)&v15->left + l2) = ((v15->left + *(int *)((char *)&v15->left + v30)) >> 1)
                                              + ((*(v31 - 1) + *(int *)((char *)&v15->left + (_DWORD)v29)) >> 1);
            *(_DWORD *)&v28[(_DWORD)v31] = ((*v31 + *(int *)((char *)v31 + cchan1b)) >> 1)
                                         + ((*(int *)((char *)v31 + cchan2c) + *(int *)((char *)v31 + (_DWORD)v134)) >> 1);
            v31 += 2;
            ++v15;
            pbufrear3c = (portable_samplepair_t *)((char *)pbufrear3c - 1);
            if ( pbufrear3c == nullptr )
              break;
            v30 = cchan3;
            v29 = pbufcenter3;
          }
        }
      }
      else if ( cchan2 == 5 && (int)count > 0 )
      {
        pbufcentert = (portable_samplepair_t *)&v15->right;
        pbufrear1 = (portable_samplepair_t *)((char *)v11 - (char *)v15);
        cchan3 = (char *)pbuf - (char *)v15;
        pbufcenter3 = (portable_samplepair_t *)((char *)pbufrear - (char *)v15);
        v37 = (char *)v10 - (char *)v15;
        v38 = v11;
        v39 = &pbufcenter2->left;
        l2 = v37;
        pbufrear3e = (portable_samplepair_t *)((char *)pbuf - (char *)pbufcenter2);
        pbufcenter1 = (portable_samplepair_t *)((char *)v38 - (char *)pbufcenter2);
        v40 = (char *)pbufrear - (char *)pbufcenter2;
        cchan2e = count;
        v41 = pbufcentert;
        v129 = (char *)((char *)v10 - (char *)pbufcenter2);
        do
        {
          v42 = *v39 >> 1;
          pbufcenter2e = (portable_samplepair_t *)(v42 + *(int *)((char *)&v41->left + (_DWORD)pbufrear1));
          v43 = *(int *)((char *)v39 + v40) + *(int *)((char *)v39 + (_DWORD)pbufcenter1);
          v39 += 2;
          *(int *)((char *)v39 + (_DWORD)v129 - 8) = ((v41[-1].right + *(int *)((char *)v39 + (_DWORD)pbufrear3e - 8)) >> 1)
                                                   + ((v42 + v43) >> 1);
          *(int *)((char *)&v41->left + l2) = (((int)pbufcenter2e + *(int *)((char *)&v41->left + (_DWORD)pbufcenter3)) >> 1)
                                            + ((v41->left + *(int *)((char *)&v41->left + cchan3)) >> 1);
          ++v41;
          cchan2e = (portable_samplepair_t *)((char *)cchan2e - 1);
        }
        while ( cchan2e != nullptr );
      }
    }
    else if ( cchan1 == 5 && cchan2 == 5 && (int)count > 0 )
    {
      pbufcentert = pbufcenter1;
      pbufrear1 = (portable_samplepair_t *)&v11->right;
      cchan2f = (char *)pbuf - (char *)v11;
      cchan1c = (char *)pbufrear - (char *)v11;
      v134 = (char *)((char *)v15 - (char *)v11);
      v44 = (char *)((char *)v10 - (char *)v11);
      v45 = pbufcenter1;
      v132 = v44;
      pbufcenter3 = (portable_samplepair_t *)((char *)pbuf - (char *)pbufcenter1);
      v46 = (char *)pbufcenter2 - (char *)pbufcenter1;
      v47 = (char *)pbufrear - (char *)pbufcenter1;
      pbufcenter1 = (portable_samplepair_t *)((char *)v15 - (char *)pbufcenter1);
      v48 = (char *)v10 - (char *)v45;
      v49 = pbufrear1;
      pbufrear3f = count;
      v50 = pbufcentert;
      cchan3 = v46;
      v130 = v47;
      l2 = v48;
      while ( 1 )
      {
        v51 = v50->left >> 1;
        pbufcenter2f = (portable_samplepair_t *)(v51 + *(int *)((char *)&v49->left + cchan2f));
        v52 = *(int *)((char *)&v50->left + v46) >> 1;
        r2 = v52 + v49->left;
        v53 = *(int *)((char *)&v50->left + (_DWORD)pbufcenter1);
        pbufcentert = (portable_samplepair_t *)v52;
        ++v49;
        v54 = v51 + *(int *)((char *)&v50->left + (_DWORD)pbufcenter3) + v53;
        v55 = v52 + v49[-2].right + *(int *)((char *)&v50->left + v130);
        ++v50;
        *(int *)((char *)&v50[-1].left + l2) = (v55 >> 1) + (v54 >> 1);
        v8 = pbufrear3f == (portable_samplepair_t *)1;
        pbufrear3f = (portable_samplepair_t *)((char *)pbufrear3f - 1);
        *(int *)((char *)&v49[-1].left + (_DWORD)v132) = ((r2 + *(int *)((char *)&v49[-1].left + cchan1c)) >> 1)
                                                       + (((int)pbufcenter2f
                                                         + *(int *)((char *)&v49[-1].left + (_DWORD)v134)) >> 1);
        if ( v8 )
          break;
        v46 = cchan3;
      }
    }
    goto gain2ch;
  }
  if ( cchan3 == 4 )
  {
    if ( cchan1 == 4 )
    {
      if ( cchan2 == 4 )
      {
        if ( (int)count > 0 )
        {
          pbufcentert = (portable_samplepair_t *)&pbuf->right;
          cchan2g = (char *)v11 - (char *)pbuf;
          v134 = (char *)((char *)v10 - (char *)pbuf);
          v132 = (char *)((char *)pbufrear - (char *)pbuf);
          l2 = (char *)v15 - (char *)pbuf;
          v56 = (char *)((char *)pbufrear3 - (char *)pbuf);
          v57 = (char *)((char *)v11 - (char *)v10);
          cchan3 = (char *)v15 - (char *)v10;
          v130 = (char *)pbufrear3 - (char *)v10;
          v58 = &pbuf->right;
          pbufcenter2b = count;
          v129 = v57;
          v131 = (int *)((char *)pbufrear - (char *)v10);
          v59 = v10;
          while ( 1 )
          {
            v60 = v134;
            v59->left = *(v58 - 1) + *(_DWORD *)&v57[(_DWORD)v59];
            v61 = *v58 + *(int *)((char *)v58 + cchan2g);
            v58 += 2;
            *(_DWORD *)&v60[(_DWORD)v58 - 8] = v61;
            *(int *)((char *)&v59->left + v130) = *(int *)((char *)&v59->left + (_DWORD)v131)
                                                + *(int *)((char *)&v59->left + cchan3);
            ++v59;
            v8 = pbufcenter2b == (portable_samplepair_t *)1;
            pbufcenter2b = (portable_samplepair_t *)((char *)pbufcenter2b - 1);
            *(int *)((char *)v58 + (_DWORD)v56 - 8) = *(int *)((char *)v58 + l2 - 8) + *(_DWORD *)&v132[(_DWORD)v58 - 8];
            if ( v8 )
              break;
            v57 = v129;
          }
        }
gain4ch:
        v92 = gain_out;
        if ( gain_out != 256 )
        {
          v93 = nullptr;
          if ( (int)count > 0 )
          {
            v94 = &pbufrear3->right;
            do
            {
              v10[(_DWORD)v93].left = (v92 * v10[(_DWORD)v93].left) >> 8;
              *(int *)((char *)v94 + (char *)v10 - (char *)pbufrear3) = (v92
                                                                       * *(int *)((char *)v94
                                                                                + (char *)v10
                                                                                - (char *)pbufrear3)) >> 8;
              *(v94 - 1) = (v92 * *(v94 - 1)) >> 8;
              *v94 = (v92 * *v94) >> 8;
              v93 = (portable_samplepair_t *)((char *)v93 + 1);
              v94 += 2;
            }
            while ( (int)v93 < (int)count );
          }
        }
        return;
      }
      if ( cchan2 == 5 )
      {
        if ( (int)count > 0 )
        {
          pbufcentert = pbufcenter2;
          pbufrear1 = (portable_samplepair_t *)&pbuf->right;
          cchan2k = (char *)v11 - (char *)pbuf;
          v134 = (char *)((char *)v10 - (char *)pbuf);
          v132 = (char *)((char *)pbufrear - (char *)pbuf);
          l2 = (char *)v15 - (char *)pbuf;
          cchan1f = (char *)pbufrear3 - (char *)pbuf;
          v129 = (char *)((char *)v10 - (char *)pbufcenter2);
          v77 = (portable_samplepair_t *)((char *)v11 - (char *)pbufcenter2);
          v78 = (char *)pbufrear - (char *)pbufcenter2;
          pbufcenter3 = (portable_samplepair_t *)((char *)pbufrear3 - (char *)pbufcenter2);
          v130 = (char *)v15 - (char *)pbufcenter2;
          v79 = &pbufcenter2->left;
          pbufcenter2d = count;
          v80 = &pbuf->right;
          pbufcenter1 = v77;
          cchan3 = v78;
          while ( 1 )
          {
            v81 = *v79 >> 1;
            v82 = v81 + *(int *)((char *)v80 + cchan2k);
            *(int *)((char *)v79 + (_DWORD)v129) = v81 + *(v80 - 1) + *(int *)((char *)v79 + (_DWORD)v77);
            *(int *)((char *)v80 + (_DWORD)v134) = v82 + *v80;
            *(int *)((char *)&pbufcenter3->left + (_DWORD)v79) = *(int *)((char *)v79 + cchan3)
                                                               + *(int *)((char *)v79 + v130);
            *(int *)((char *)v80 + cchan1f) = *(int *)((char *)v80 + l2) + *(int *)((char *)v80 + (_DWORD)v132);
            v79 += 2;
            v80 += 2;
            pbufcenter2d = (portable_samplepair_t *)((char *)pbufcenter2d - 1);
            if ( pbufcenter2d == nullptr )
              break;
            v77 = pbufcenter1;
          }
        }
        goto gain4ch;
      }
    }
    else if ( cchan1 == 2 )
    {
      switch ( cchan2 )
      {
        case 4u:
          if ( (int)count > 0 )
          {
            cchan2h = (char *)pbuf - (char *)v11;
            v132 = (char *)((char *)v10 - (char *)v11);
            cchan1d = (char *)pbufrear - (char *)v11;
            v62 = &v11->right;
            v63 = (portable_samplepair_t *)((char *)pbuf - (char *)v10);
            v130 = (char *)pbufrear3 - (char *)v10;
            pbufrear1 = count;
            v129 = (char *)((char *)pbufrear3 - (char *)v11);
            pbufcenter1 = v63;
            v131 = (int *)((char *)pbufrear - (char *)v10);
            v64 = v10;
            while ( 1 )
            {
              v65 = *(int *)((char *)&v64->left + (_DWORD)v63);
              v66 = *(int *)((char *)v62 + cchan2h);
              v64->left = v65 + *(v62 - 1);
              *(int *)((char *)v62 + (_DWORD)v132) = v66 + *v62;
              *(int *)((char *)&v64->left + v130) = v65 + *(int *)((char *)&v64->left + (_DWORD)v131);
              *(int *)((char *)v62 + (_DWORD)v129) = v66 + *(int *)((char *)v62 + cchan1d);
              v62 += 2;
              ++v64;
              pbufrear1 = (portable_samplepair_t *)((char *)pbufrear1 - 1);
              if ( pbufrear1 == nullptr )
                break;
              v63 = pbufcenter1;
            }
          }
          goto gain4ch;
        case 2u:
          if ( (int)count > 0 )
          {
            cchan2i = (char *)v11 - (char *)pbuf;
            v134 = (char *)((char *)v10 - (char *)pbuf);
            v67 = &pbuf->right;
            cchan1e = (char *)pbufrear3 - (char *)pbuf;
            v68 = (char *)((char *)v11 - (char *)v10);
            v69 = v10;
            v129 = (char *)((char *)v11 - (char *)v10);
            pbufcenter2c = count;
            while ( 1 )
            {
              v70 = *(v67 - 1) + *(_DWORD *)&v68[(_DWORD)v69];
              v71 = *v67 + *(int *)((char *)v67 + cchan2i);
              v69->left = v70;
              *(int *)((char *)&v69->left + (char *)pbufrear3 - (char *)v10) = v70;
              *(_DWORD *)&v134[(_DWORD)v67] = v71;
              *(int *)((char *)v67 + cchan1e) = v71;
              v67 += 2;
              ++v69;
              pbufcenter2c = (portable_samplepair_t *)((char *)pbufcenter2c - 1);
              if ( pbufcenter2c == nullptr )
                break;
              v68 = v129;
            }
          }
          goto gain4ch;
        case 5u:
          if ( (int)count > 0 )
          {
            cchan2j = (char *)v11 - (char *)pbuf;
            v134 = (char *)((char *)v10 - (char *)pbuf);
            v132 = (char *)((char *)pbufrear - (char *)pbuf);
            v72 = (char *)((char *)pbufrear3 - (char *)pbuf);
            v73 = (portable_samplepair_t **)&pbuf->right;
            v74 = pbufcenter2;
            pbufcenter1 = (portable_samplepair_t *)((char *)v11 - (char *)pbufcenter2);
            v129 = (char *)((char *)v10 - (char *)pbufcenter2);
            pbufcenter3 = (portable_samplepair_t *)((char *)pbufrear3 - (char *)pbufcenter2);
            cchan3 = (char *)pbufrear - (char *)pbufcenter2;
            for ( l2 = (int)count; l2 != 0; --l2 )
            {
              left = v74->left;
              v76 = *(int *)((char *)v73 + cchan2j);
              pbufrear1 = *(v73 - 1);
              pbufcenter2g = *v73;
              left >>= 1;
              *(int *)((char *)&v74->left + (_DWORD)v129) = (int)pbufrear1
                                                          + left
                                                          + *(int *)((char *)&v74->left + (_DWORD)pbufcenter1);
              *(_DWORD *)&v134[(_DWORD)v73] = (char *)pbufcenter2g + left + v76;
              *(int *)((char *)&pbufcenter3->left + (_DWORD)v74) = (int)pbufrear1
                                                                 + *(int *)((char *)&v74->left + cchan3);
              *(char **)((char *)v73 + (_DWORD)v72) = (char *)pbufcenter2g + *(_DWORD *)&v132[(_DWORD)v73];
              v73 += 2;
              ++v74;
            }
          }
          goto gain4ch;
        default:
          break;
      }
    }
    else if ( cchan1 == 5 && cchan2 == 5 )
    {
      if ( (int)count > 0 )
      {
        pbufcentert = pbufcenter1;
        v131 = &v11->right;
        cchan2l = (char *)pbuf - (char *)v11;
        v132 = (char *)((char *)v10 - (char *)v11);
        cchan1g = (char *)pbufrear - (char *)v11;
        v134 = (char *)((char *)v15 - (char *)v11);
        pbufcenter3 = (portable_samplepair_t *)((char *)pbuf - (char *)pbufcenter1);
        v129 = (char *)((char *)pbufrear3 - (char *)v11);
        l2 = (char *)v10 - (char *)pbufcenter1;
        v83 = (char *)pbufcenter2 - (char *)pbufcenter1;
        v84 = (char *)pbufrear - (char *)pbufcenter1;
        v85 = pbufcenter1;
        v121 = (int *)((char *)pbufrear3 - (char *)pbufcenter1);
        pbufcenter1 = (portable_samplepair_t *)((char *)v15 - (char *)pbufcenter1);
        v86 = v131;
        cchan3 = v83;
        v130 = v84;
        pbufrear1 = count;
        while ( 1 )
        {
          v87 = v85->left >> 1;
          pbufcenter2h = (portable_samplepair_t *)(v87 + *(int *)((char *)v86 + cchan2l));
          v88 = *(int *)((char *)&v85->left + v83) >> 1;
          r2 = v88 + *v86;
          v89 = *(v86 - 1) + *(int *)((char *)&pbufcenter3->left + (_DWORD)v85++);
          v90 = v88 + v87 + v89;
          v91 = (char *)pbufcenter2h + r2;
          *(int *)((char *)&v85[-1].left + l2) = v90;
          *(_DWORD *)&v132[(_DWORD)v86] = v91;
          *(int *)((char *)&v85[-1].left + (_DWORD)v121) = *(int *)((char *)&v85[-1].left + v130)
                                                         + *(int *)((char *)&pbufcenter1[-1].left + (_DWORD)v85);
          *(_DWORD *)&v129[(_DWORD)v86] = *(_DWORD *)&v134[(_DWORD)v86] + *(int *)((char *)v86 + cchan1g);
          v86 += 2;
          pbufrear1 = (portable_samplepair_t *)((char *)pbufrear1 - 1);
          if ( pbufrear1 == nullptr )
            break;
          v83 = cchan3;
        }
      }
      goto gain4ch;
    }
gain2ch:
    v21 = gain_out;
    if ( gain_out != 256 )
    {
      for ( i = nullptr; (int)i < (int)count; i = (portable_samplepair_t *)((char *)i + 1) )
      {
        v10[(_DWORD)i].left = (v21 * v10[(_DWORD)i].left) >> 8;
        v10[(_DWORD)i].right = (v21 * v10[(_DWORD)i].right) >> 8;
      }
    }
    return;
  }
  if ( cchan3 != 5 )
    goto gain2ch;
  if ( cchan1 == 2 )
  {
    switch ( cchan2 )
    {
      case 2u:
        if ( (int)count > 0 )
        {
          v132 = (char *)((char *)v10 - (char *)v11);
          cchan2m = (char *)pbuf - (char *)v11;
          v129 = (char *)((char *)pbufrear3 - (char *)v11);
          v95 = &v11->right;
          cchan1h = (char *)pbufrear3 - (char *)pbuf;
          v96 = (char *)((char *)v10 - (char *)pbuf);
          cchan3 = (char *)pbufcenter3 - (char *)pbuf;
          v134 = (char *)((char *)v10 - (char *)pbuf);
          pbufrear1 = count;
          while ( 1 )
          {
            v97 = pbuf->left;
            pbufcenter2i = *(portable_samplepair_t **)((char *)v95 + cchan2m);
            l2 = *(v95 - 1);
            r2 = *v95;
            *(_DWORD *)&v96[(_DWORD)pbuf] = v97 + l2;
            *(int *)((char *)v95 + (_DWORD)v132) = (int)pbufcenter2i + r2;
            *(int *)((char *)&pbuf->left + cchan1h) = pbuf->left + *(v95 - 1);
            *(_DWORD *)&v129[(_DWORD)v95] = *(int *)((char *)v95 + cchan2m) + *v95;
            v95 += 2;
            *(int *)((char *)&pbuf->left + cchan3) = ((int)pbufcenter2i + v97) / 2 + (l2 + r2) / 2;
            ++pbuf;
            pbufrear1 = (portable_samplepair_t *)((char *)pbufrear1 - 1);
            if ( pbufrear1 == nullptr )
              break;
            v96 = v134;
          }
        }
        break;
      case 4u:
        if ( (int)count > 0 )
        {
          v129 = (char *)((char *)v11 - (char *)v10);
          v131 = (int *)((char *)pbufrear - (char *)v10);
          pbufcenter1 = (portable_samplepair_t *)((char *)pbuf - (char *)v10);
          v130 = (char *)pbufrear3 - (char *)v10;
          cchan2n = (char *)v11 - (char *)pbufrear;
          cchan1i = (char *)pbufrear3 - (char *)pbuf;
          v98 = (char *)((char *)pbufrear - (char *)pbuf);
          pbufrear1 = count;
          v99 = &v10->right;
          v132 = (char *)((char *)pbufrear - (char *)pbuf);
          cchan3 = (char *)pbufcenter3 - (char *)pbuf;
          while ( 1 )
          {
            v100 = pbuf->left;
            pbufcenter2j = *(portable_samplepair_t **)((char *)&pbufcenter1->left + (_DWORD)v99);
            v121 = (int *)&v98[(_DWORD)pbuf];
            v101 = *(_DWORD *)&v129[(_DWORD)v99];
            l2 = *(_DWORD *)&v98[(_DWORD)pbuf + cchan2n];
            *(v99 - 1) = v100 + l2;
            v102 = v121;
            r2 = v101;
            v99 += 2;
            *(v99 - 2) = (int)pbufcenter2j + v101;
            *(int *)((char *)&pbuf->left + cchan1i) = *v102 + pbuf->left;
            *(int *)((char *)v99 + v130 - 8) = *(int *)((char *)&pbufcenter1[-1].left + (_DWORD)v99)
                                             + *(int *)((char *)v99 + (_DWORD)v131 - 8);
            ++pbuf;
            v8 = pbufrear1 == (portable_samplepair_t *)1;
            pbufrear1 = (portable_samplepair_t *)((char *)pbufrear1 - 1);
            *(int *)((char *)&pbuf[-1].left + cchan3) = ((int)pbufcenter2j + v100) / 2 + (l2 + r2) / 2;
            if ( v8 )
              break;
            v98 = v132;
          }
        }
        break;
      case 5u:
        if ( snd_mix_optimization.m_pParent != nullptr && snd_mix_optimization.m_pParent->m_Value.m_nValue != 0 )
          Mix255_SIMD(&data);
        else
          Mix255(&data);
        break;
      default:
        goto gain2ch;
    }
  }
  else if ( cchan1 == 4 )
  {
    if ( cchan2 == 4 )
    {
      if ( (int)count > 0 )
      {
        v121 = &v11->right;
        cchan2o = (char *)pbuf - (char *)v11;
        v132 = (char *)((char *)v10 - (char *)v11);
        cchan1j = (char *)pbufrear - (char *)v11;
        v134 = (char *)((char *)v15 - (char *)v11);
        v103 = (char *)((char *)pbufrear3 - (char *)v11);
        v130 = (char *)pbufrear3 - (char *)v10;
        v104 = (portable_samplepair_t *)((char *)pbuf - (char *)v10);
        pbufrear1 = (portable_samplepair_t *)((char *)pbufcenter3 - (char *)v10);
        v131 = (int *)((char *)pbufrear - (char *)v10);
        pbufcentert = count;
        v105 = v121;
        v129 = v103;
        pbufcenter1 = v104;
        cchan3 = (char *)v15 - (char *)v10;
        v106 = v10;
        while ( 1 )
        {
          v107 = *(int *)((char *)&v106->left + (_DWORD)v104);
          v108 = *(int *)((char *)v105 + cchan2o);
          l2 = *(v105 - 1);
          r2 = *v105;
          v106->left = v107 + l2;
          *(int *)((char *)v105 + (_DWORD)v132) = v108 + r2;
          *(int *)((char *)&v106->left + v130) = *(int *)((char *)&v106->left + (_DWORD)v131)
                                               + *(int *)((char *)&v106->left + cchan3);
          *(int *)((char *)v105 + (_DWORD)v129) = *(int *)((char *)v105 + cchan1j)
                                                + *(int *)((char *)v105 + (_DWORD)v134);
          v105 += 2;
          *(int *)((char *)&v106->left + (_DWORD)pbufrear1) = (v108 + v107) / 2 + (r2 + l2) / 2;
          ++v106;
          pbufcentert = (portable_samplepair_t *)((char *)pbufcentert - 1);
          if ( pbufcentert == nullptr )
            break;
          v104 = pbufcenter1;
        }
      }
    }
    else
    {
      if ( cchan2 != 5 )
        goto gain2ch;
      if ( (int)count > 0 )
      {
        l2 = (int)&v11->right;
        cchan2p = (char *)pbuf - (char *)v11;
        v132 = (char *)((char *)v10 - (char *)v11);
        cchan1k = (char *)pbufrear - (char *)v11;
        v134 = (char *)((char *)v15 - (char *)v11);
        v109 = (char *)((char *)pbufrear3 - (char *)v11);
        v130 = (char *)pbufrear3 - (char *)v10;
        r2 = (char *)pbufcenter2 - (char *)v10;
        v110 = (portable_samplepair_t *)((char *)pbuf - (char *)v10);
        pbufrear1 = (portable_samplepair_t *)((char *)pbufcenter3 - (char *)v10);
        v131 = (int *)((char *)pbufrear - (char *)v10);
        pbufcentert = count;
        v111 = l2;
        v129 = v109;
        pbufcenter1 = v110;
        cchan3 = (char *)v15 - (char *)v10;
        v112 = v10;
        while ( 1 )
        {
          v113 = *(int *)((char *)&v110->left + (_DWORD)v112);
          v114 = *(_DWORD *)(v111 + cchan2p);
          v112->left = v113 + *(_DWORD *)(v111 - 4);
          *(_DWORD *)&v132[v111] = v114 + *(_DWORD *)v111;
          *(int *)((char *)&v112->left + v130) = *(int *)((char *)&v112->left + (_DWORD)v131)
                                               + *(int *)((char *)&v112->left + cchan3);
          *(_DWORD *)&v129[v111] = *(_DWORD *)(v111 + cchan1k) + *(_DWORD *)&v134[v111];
          *(int *)((char *)&pbufrear1->left + (_DWORD)v112) = *(int *)((char *)&v112->left + r2) + (v114 + v113) / 2;
          v111 += 8;
          ++v112;
          pbufcentert = (portable_samplepair_t *)((char *)pbufcentert - 1);
          if ( pbufcentert == nullptr )
            break;
          v110 = pbufcenter1;
        }
      }
    }
  }
  else
  {
    if ( cchan2 != 5 || cchan1 != 5 )
      goto gain2ch;
    if ( snd_mix_optimization.m_pParent != nullptr && snd_mix_optimization.m_pParent->m_Value.m_nValue != 0 )
      Mix555_SIMD((__m128i *)&data);
    else
      Mix555(&data);
  }
  v115 = gain_out;
  if ( gain_out != 256 && (int)count > 0 )
  {
    v116 = pbufcenter3;
    v117 = (char *)v10 - (char *)pbufrear3;
    v118 = &pbufrear3->right;
    v119 = (char *)v10 - (char *)pbufcenter3;
    do
    {
      *(int *)((char *)&v116->left + v119) = (v115 * *(int *)((char *)&v116->left + v119)) >> 8;
      *(int *)((char *)v118 + v117) = (v115 * *(int *)((char *)v118 + v117)) >> 8;
      *(v118 - 1) = (v115 * *(v118 - 1)) >> 8;
      *v118 = (v115 * *v118) >> 8;
      v116->left = (v115 * v116->left) >> 8;
      v118 += 2;
      ++v116;
      count = (portable_samplepair_t *)((char *)count - 1);
    }
    while ( count != nullptr );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002FFD0
// Name: void ClipStereo(struct portable_samplepair_t __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ClipStereo(portable_samplepair_t *pBuffer, unsigned int nCount)
{
  int v2; // esi
  unsigned int v3; // edx
  portable_samplepair_t *v4; // eax
  int left; // ecx
  int right; // ecx
  int v7; // ecx
  int v8; // ecx
  int v9; // ecx
  int v10; // ecx
  int v11; // ecx
  int v12; // ecx
  int v13; // ecx
  int v14; // ecx

  v2 = nCount;
  if ( (int)nCount < 4 )
  {
    v4 = pBuffer;
  }
  else
  {
    v3 = nCount >> 2;
    v2 = nCount - 4 * (nCount >> 2);
    v4 = pBuffer;
    do
    {
      left = v4->left;
      if ( v4->left >= -32767 )
      {
        if ( left > 0x7FFF )
          left = 0x7FFF;
      }
      else
      {
        left = -32767;
      }
      v4->left = left;
      right = v4->right;
      if ( right >= -32767 )
      {
        if ( right > 0x7FFF )
          right = 0x7FFF;
      }
      else
      {
        right = -32767;
      }
      v4->right = right;
      v7 = v4[1].left;
      if ( v7 >= -32767 )
      {
        if ( v7 > 0x7FFF )
          v7 = 0x7FFF;
      }
      else
      {
        v7 = -32767;
      }
      v4[1].left = v7;
      v8 = v4[1].right;
      if ( v8 >= -32767 )
      {
        if ( v8 > 0x7FFF )
          v8 = 0x7FFF;
      }
      else
      {
        v8 = -32767;
      }
      v4[1].right = v8;
      v9 = v4[2].left;
      if ( v9 >= -32767 )
      {
        if ( v9 > 0x7FFF )
          v9 = 0x7FFF;
      }
      else
      {
        v9 = -32767;
      }
      v4[2].left = v9;
      v10 = v4[2].right;
      if ( v10 >= -32767 )
      {
        if ( v10 > 0x7FFF )
          v10 = 0x7FFF;
      }
      else
      {
        v10 = -32767;
      }
      v4[2].right = v10;
      v11 = v4[3].left;
      if ( v11 >= -32767 )
      {
        if ( v11 > 0x7FFF )
          v11 = 0x7FFF;
      }
      else
      {
        v11 = -32767;
      }
      v4[3].left = v11;
      v12 = v4[3].right;
      if ( v12 >= -32767 )
      {
        if ( v12 > 0x7FFF )
          v12 = 0x7FFF;
      }
      else
      {
        v12 = -32767;
      }
      v4[3].right = v12;
      v4 += 4;
      --v3;
    }
    while ( v3 != 0 );
  }
  for ( ; v2 > 0; ++v4 )
  {
    v13 = v4->left;
    if ( v4->left >= -32767 )
    {
      if ( v13 > 0x7FFF )
        v13 = 0x7FFF;
    }
    else
    {
      v13 = -32767;
    }
    v4->left = v13;
    v14 = v4->right;
    if ( v14 >= -32767 )
    {
      if ( v14 > 0x7FFF )
        v14 = 0x7FFF;
    }
    else
    {
      v14 = -32767;
    }
    v4->right = v14;
    --v2;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10030160
// Name: void ClipLeft(struct portable_samplepair_t __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ClipLeft(portable_samplepair_t *pBuffer, unsigned int nCount)
{
  int v2; // edx
  unsigned int v3; // esi
  portable_samplepair_t *v4; // eax
  int left; // ecx
  int v6; // ecx
  int v7; // ecx
  int v8; // ecx
  int v9; // ecx
  int v10; // ecx
  int v11; // ecx
  int v12; // ecx
  int v13; // ecx

  v2 = nCount;
  if ( (int)nCount < 8 )
  {
    v4 = pBuffer;
  }
  else
  {
    v3 = nCount >> 3;
    v2 = nCount - 8 * (nCount >> 3);
    v4 = pBuffer;
    do
    {
      left = v4->left;
      if ( v4->left >= -32767 )
      {
        if ( left > 0x7FFF )
          left = 0x7FFF;
      }
      else
      {
        left = -32767;
      }
      v4->left = left;
      v6 = v4[1].left;
      if ( v6 >= -32767 )
      {
        if ( v6 > 0x7FFF )
          v6 = 0x7FFF;
      }
      else
      {
        v6 = -32767;
      }
      v4[1].left = v6;
      v7 = v4[2].left;
      if ( v7 >= -32767 )
      {
        if ( v7 > 0x7FFF )
          v7 = 0x7FFF;
      }
      else
      {
        v7 = -32767;
      }
      v4[2].left = v7;
      v8 = v4[3].left;
      if ( v8 >= -32767 )
      {
        if ( v8 > 0x7FFF )
          v8 = 0x7FFF;
      }
      else
      {
        v8 = -32767;
      }
      v4[3].left = v8;
      v9 = v4[4].left;
      if ( v9 >= -32767 )
      {
        if ( v9 > 0x7FFF )
          v9 = 0x7FFF;
      }
      else
      {
        v9 = -32767;
      }
      v4[4].left = v9;
      v10 = v4[5].left;
      if ( v10 >= -32767 )
      {
        if ( v10 > 0x7FFF )
          v10 = 0x7FFF;
      }
      else
      {
        v10 = -32767;
      }
      v4[5].left = v10;
      v11 = v4[6].left;
      if ( v11 >= -32767 )
      {
        if ( v11 > 0x7FFF )
          v11 = 0x7FFF;
      }
      else
      {
        v11 = -32767;
      }
      v4[6].left = v11;
      v12 = v4[7].left;
      if ( v12 >= -32767 )
      {
        if ( v12 > 0x7FFF )
          v12 = 0x7FFF;
      }
      else
      {
        v12 = -32767;
      }
      v4[7].left = v12;
      v4 += 8;
      --v3;
    }
    while ( v3 != 0 );
  }
  for ( ; v2 > 0; ++v4 )
  {
    v13 = v4->left;
    if ( v4->left >= -32767 )
    {
      if ( v13 > 0x7FFF )
        v13 = 0x7FFF;
    }
    else
    {
      v13 = -32767;
    }
    v4->left = v13;
    --v2;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100302D0
// Name: void SW_Mix16Stereo(struct portable_samplepair_t restrict __near *,int restrict __near *,short restrict __near *,int,unsigned int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SW_Mix16Stereo(
        portable_samplepair_t *pOutput,
        int *pVolume,
        __int16 *pData,
        int nInputOffset,
        unsigned int nRateScaleFix,
        unsigned int nOutCount)
{
  if ( snd_mix_optimization.m_pParent != nullptr && snd_mix_optimization.m_pParent->m_Value.m_nValue != 0 )
    SW_Mix16Stereo_Opt(pOutput, pVolume, pData, nInputOffset, nRateScaleFix, nOutCount);
  else
    SW_Mix16Stereo_NoOpt(pOutput, pVolume, pData, nInputOffset, nRateScaleFix, nOutCount);
}

//------------------------------------------------------------------------------
// Address: 0x100302F0
// Name: _Mix8StereoWavtype
// Source: json
//------------------------------------------------------------------------------
void __cdecl Mix8StereoWavtype(
        channel_t *pChannel,
        portable_samplepair_t *pOutput,
        int *volume,
        unsigned __int8 *pData,
        int *inputOffset,
        int *rateScaleFix,
        int outCount)
{
  char wavtype; // al
  bool v8; // zf
  float soundfacing; // [esp+0h] [ebp-20h]
  float soundfacinga; // [esp+0h] [ebp-20h]

  wavtype = pChannel->wavtype;
  if ( snd_mix_soundchar_enabled.m_pParent == nullptr || snd_mix_soundchar_enabled.m_pParent->m_Value.m_nValue == 0 )
    wavtype = 0;
  switch ( wavtype )
  {
    case '(':
    case '>':
      SW_Mix8StereoDopplerLeft(pOutput, volume, pData, inputOffset, (unsigned int)rateScaleFix, outCount);
      SW_Mix8StereoDopplerRight(pOutput, volume: volume + 6, pData, inputOffset, (unsigned int)rateScaleFix, outCount);
      break;
    case '<':
      v8 = !FUseHighQualityPitch(pChannel);
      soundfacing = pChannel->dspface;
      if ( v8 )
        SW_Mix8StereoDirectional(
          soundfacing,
          pOutput,
          volume,
          pData,
          (int)inputOffset,
          (unsigned int)rateScaleFix,
          outCount);
      else
        SW_Mix8StereoDirectional_Interp(
          soundfacing,
          pOutput,
          volume,
          pData,
          inputOffset,
          (unsigned int)rateScaleFix,
          outCount);
      break;
    case '^':
      v8 = !FUseHighQualityPitch(pChannel);
      soundfacinga = pChannel->distmix;
      if ( v8 )
        SW_Mix8StereoDistVar(
          distmix: soundfacinga,
          pOutput,
          volume,
          pData,
          inputOffset,
          (unsigned int)rateScaleFix,
          outCount);
      else
        SW_Mix8StereoDistVar_Interp(
          distmix: soundfacinga,
          pOutput,
          volume,
          pData,
          (unsigned int)inputOffset,
          rateScaleFix,
          outCount);
      break;
    default:
      if ( FUseHighQualityPitch(pChannel) )
        SW_Mix8Stereo_Interp(pOutput, volume, pData, inputOffset, rateScaleFix, outCount);
      else
        SW_Mix8Stereo(pOutput, volume, pData, inputOffset, (unsigned int)rateScaleFix, outCount);
      break;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10030480
// Name: _Mix16StereoWavtype
// Source: json
//------------------------------------------------------------------------------
void __cdecl Mix16StereoWavtype(
        channel_t *pChannel,
        portable_samplepair_t *pOutput,
        int *volume,
        __int16 *pData,
        int inputOffset,
        unsigned int rateScaleFix,
        int outCount)
{
  bool v7; // al
  char wavtype; // cl
  float soundfacing; // [esp+0h] [ebp-24h]
  float soundfacinga; // [esp+0h] [ebp-24h]

  if ( *volume + volume[1] > 2 )
  {
    v7 = FUseHighQualityPitch(pChannel);
    wavtype = pChannel->wavtype;
    if ( snd_mix_soundchar_enabled.m_pParent == nullptr || snd_mix_soundchar_enabled.m_pParent->m_Value.m_nValue == 0 )
      wavtype = 0;
    switch ( wavtype )
    {
      case '(':
      case '>':
        if ( v7 )
        {
          SW_Mix16StereoDopplerLeft_Interp(pOutput, volume, pData, inputOffset, rateScaleFix, outCount);
          SW_Mix16StereoDopplerRight_Interp(pOutput, volume: volume + 6, pData, inputOffset, rateScaleFix, outCount);
        }
        else
        {
          SW_Mix16StereoDopplerLeft(pOutput, volume, pData, inputOffset, rateScaleFix, outCount);
          SW_Mix16StereoDopplerRight(pOutput, volume: volume + 6, pData, inputOffset, rateScaleFix, outCount);
        }
        break;
      case '<':
        soundfacing = pChannel->dspface;
        if ( v7 )
          SW_Mix16StereoDirectional_Interp(soundfacing, pOutput, volume, pData, inputOffset, rateScaleFix, outCount);
        else
          SW_Mix16StereoDirectional(soundfacing, pOutput, volume, pData, inputOffset, rateScaleFix, outCount);
        break;
      case '@':
        if ( v7 )
          goto LABEL_17;
        SW_Mix16Stereo(
          pOutput,
          pVolume: volume,
          pData,
          nInputOffset: inputOffset,
          nRateScaleFix: rateScaleFix,
          nOutCount: outCount);
        break;
      case '^':
        soundfacinga = pChannel->distmix;
        if ( v7 )
          SW_Mix16StereoDistVar_Interp(
            distmix: soundfacinga,
            pOutput,
            volume,
            pData,
            inputOffset,
            rateScaleFix,
            outCount);
        else
          SW_Mix16StereoDistVar(distmix: soundfacinga, pOutput, volume, pData, inputOffset, rateScaleFix, outCount);
        break;
      default:
        if ( v7 )
        {
LABEL_17:
          SW_Mix16Stereo_Interp(pOutput, pVolume: volume, pData, inputOffset, rateScaleFix, outCount);
        }
        else if ( snd_mix_optimization.m_pParent != nullptr && snd_mix_optimization.m_pParent->m_Value.m_nValue != 0 )
        {
          SW_Mix16Stereo_Opt(
            pOutput,
            pVolume: volume,
            pData,
            nInputOffset: inputOffset,
            nRateScaleFix: rateScaleFix,
            nOutCount: outCount);
        }
        else
        {
          SW_Mix16Stereo_NoOpt(
            pOutput,
            pVolume: volume,
            pData,
            nInputOffset: inputOffset,
            nRateScaleFix: rateScaleFix,
            nOutCount: outCount);
        }
        break;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100306F0
// Name: _SND_IsRecording
// Source: json
//------------------------------------------------------------------------------
bool __cdecl SND_IsRecording()
{
  return cl_movieinfo.moviename[0] != 0
      && !Con_IsVisible()
      && (host_tickcount != g_nMovieStartTick
       || snd_moviefix.m_pParent == nullptr
       || snd_moviefix.m_pParent->m_Value.m_nValue == 0);
}

//------------------------------------------------------------------------------
// Address: 0x10030730
// Name: void SND_RecordBuffer(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SND_RecordBuffer()
{
  int v0; // esi
  unsigned int v1; // ebx
  void *v2; // esp
  int i; // ecx
  int v4; // eax
  int v5; // eax
  _WORD v6[6]; // [esp+0h] [ebp-Ch] BYREF

  if ( cl_movieinfo.moviename[0] != 0
    && !Con_IsVisible()
    && (host_tickcount != g_nMovieStartTick
     || snd_moviefix.m_pParent == nullptr
     || snd_moviefix.m_pParent->m_Value.m_nValue == 0) )
  {
    v0 = snd_linear_count;
    v1 = 2 * snd_linear_count;
    v2 = alloca(2 * snd_linear_count);
    for ( i = 0; i < snd_linear_count; i += 2 )
    {
      v4 = (snd_vol * snd_p[i]) >> 8;
      if ( v4 >= -32767 )
      {
        if ( v4 > 0x7FFF )
          LOWORD(v4) = 0x7FFF;
      }
      else
      {
        LOWORD(v4) = -32767;
      }
      v6[i] = v4;
      v5 = (snd_vol * snd_p[i + 1]) >> 8;
      if ( v5 >= -32767 )
      {
        if ( v5 > 0x7FFF )
          LOWORD(v5) = 0x7FFF;
      }
      else
      {
        LOWORD(v5) = -32767;
      }
      v6[i + 1] = v5;
      v0 = snd_linear_count;
    }
    if ( (cl_movieinfo.type & 4) != 0 )
    {
      WaveAppendTmpFile(filename: cl_movieinfo.moviename, pBuffer: v6, sampleBits: 16, numSamples: v0);
      v0 = snd_linear_count;
    }
    if ( (cl_movieinfo.type & 8) != 0 )
    {
      g_pAVI->AppendMovieSound(this: g_pAVI, a2: g_hCurrentAVI, a3: v6, a4: v1);
      v0 = snd_linear_count;
    }
    g_nMovieSamples += v0 >> 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10030860
// Name: _S_TransferStereo16
// Source: json
//------------------------------------------------------------------------------
void __cdecl S_TransferStereo16(
        char *pOutput,
        const portable_samplepair_t *pfront,
        __int64 lpaintedtime,
        __int64 endtime)
{
  int v4; // ecx
  unsigned int v5; // ebx
  int v6; // eax
  int v7; // ecx
  unsigned int v8; // eax
  int samplePairCount; // [esp+0h] [ebp-4h]
  bool bShouldPlaySound_3; // [esp+13h] [ebp+Fh]

  snd_vol = (int)(S_GetMasterVolume() * 256.0);
  snd_p = &pfront->left;
  v4 = g_AudioDevice->DeviceSampleCount(this: g_AudioDevice) >> 1;
  samplePairCount = v4;
  bShouldPlaySound_3 = cl_movieinfo.moviename[0] == 0;
  if ( SHIDWORD(lpaintedtime) <= SHIDWORD(endtime) )
  {
    v5 = lpaintedtime;
    if ( SHIDWORD(lpaintedtime) < SHIDWORD(endtime) || (unsigned int)lpaintedtime < (unsigned int)endtime )
    {
      while ( 1 )
      {
        v6 = (v4 - 1) & v5;
        v7 = v4 - v6;
        snd_out = (__int16 *)&pOutput[4 * v6];
        if ( v7 > (__int64)(endtime - __PAIR64__(HIDWORD(lpaintedtime), v5)) )
          v7 = endtime - v5;
        snd_linear_count = 2 * v7;
        SND_RecordBuffer();
        if ( bShouldPlaySound_3 )
          Snd_WriteLinearBlastStereo16();
        snd_p += snd_linear_count;
        v8 = ((snd_linear_count >> 1) + __PAIR64__(HIDWORD(lpaintedtime), v5)) >> 32;
        v5 += snd_linear_count >> 1;
        HIDWORD(lpaintedtime) = v8;
        if ( __SPAIR64__(v8, v5) >= endtime )
          break;
        v4 = samplePairCount;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10030950
// Name: _SND_MouthUpdateAll
// Source: json
//------------------------------------------------------------------------------
void SND_MouthUpdateAll()
{
  int v0; // edi
  char *v1; // edi
  IClientEntity *v2; // eax
  CMouthInfo *v3; // eax
  CMouthInfo *v4; // esi
  int m_nVoiceSources; // edx
  int v6; // eax
  CVoiceData *m_VoiceSources; // ecx
  CVoiceData *v8; // eax
  const char *v9; // eax
  int v10; // ebx
  mouthenvelope_t *v11; // edi
  IClientEntity *v12; // eax
  int v13; // eax
  int v14; // esi
  int v15; // ecx
  int v16; // eax
  char nameBuf[260]; // [esp+Ch] [ebp-10Ch] BYREF
  int i; // [esp+110h] [ebp-8h]
  int v19; // [esp+114h] [ebp-4h]

  v0 = 0;
  i = 0;
  if ( g_MouthOutput.m_Size > 0 )
  {
    v19 = 0;
    do
    {
      v1 = (char *)g_MouthOutput.m_Memory.m_pMemory + v0;
      v2 = entitylist->GetClientEntity(this: entitylist, a2: *(_DWORD *)v1);
      if ( v2 == nullptr )
        goto LABEL_21;
      v3 = v2->GetMouth(this: v2);
      v4 = v3;
      if ( v3 == nullptr )
        goto LABEL_21;
      if ( *((float *)v1 + 2) >= 0.0 )
      {
        m_nVoiceSources = v3->m_nVoiceSources;
        v6 = 0;
        if ( m_nVoiceSources <= 0 )
          goto LABEL_14;
        m_VoiceSources = v4->m_VoiceSources;
        while ( m_VoiceSources == nullptr || m_VoiceSources->m_pAudioSource != *((CAudioSource **)v1 + 1) )
        {
          ++v6;
          ++m_VoiceSources;
          if ( v6 >= v4->m_nVoiceSources )
            goto LABEL_14;
        }
        if ( v6 == -1 )
        {
LABEL_14:
          v8 = CMouthInfo::AddSource(this: v4, source: *((CAudioSource **)v1 + 1), bIgnorePhonemes: false);
          if ( v8 != nullptr )
            goto LABEL_20;
          v4->m_nVoiceSources = 0;
          v9 = (const char *)(*(int (__thiscall **)(_DWORD, char *, int))(**((_DWORD **)v1 + 1) + 112))(
                               a1: *((_DWORD *)v1 + 1),
                               a2: nameBuf,
                               a3: 260);
          _DevMsg(a1: 2, a2: "out of voice sources, won't lipsync %s\n", v9);
          v8 = CMouthInfo::AddSource(this: v4, source: *((CAudioSource **)v1 + 1), bIgnorePhonemes: false);
        }
        else
        {
          if ( v6 < 0 || v6 >= m_nVoiceSources )
            goto LABEL_21;
          v8 = &v4->m_VoiceSources[v6];
        }
        if ( v8 != nullptr )
LABEL_20:
          v8->m_flElapsed = *((float *)v1 + 2);
      }
      else
      {
        CMouthInfo::RemoveSource(this: v3, source: *((CAudioSource **)v1 + 1));
        v4->mouthopen = 0;
      }
LABEL_21:
      v0 = v19 + 12;
      ++i;
      v19 += 12;
    }
    while ( i < g_MouthOutput.m_Size );
  }
  v10 = 0;
  g_MouthOutput.m_Size = 0;
  v19 = 0;
  if ( g_MouthEnvelope.m_Size <= 0 )
  {
    g_MouthEnvelope.m_Size = 0;
  }
  else
  {
    do
    {
      v11 = &g_MouthEnvelope.m_Memory.m_pMemory[v10];
      v12 = entitylist->GetClientEntity(this: entitylist, a2: g_MouthEnvelope.m_Memory.m_pMemory[v10].entityId);
      if ( v12 != nullptr )
      {
        v13 = (int)v12->GetMouth(this: v12);
        v14 = v13;
        if ( v13 != 0 )
        {
          if ( *(_WORD *)(v13 + 10) != 0 )
          {
            *(_DWORD *)(v13 + 4) += v11->sampleTotal;
            v15 = v11->sampleCount + *(unsigned __int8 *)(v13 + 1);
            v16 = *(_DWORD *)(v13 + 4);
            if ( v15 < 10 )
            {
              *(_BYTE *)(v14 + 1) = v15;
            }
            else
            {
              *(_DWORD *)(v14 + 4) = 0;
              *(_WORD *)v14 = (unsigned __int8)(v16 / v15);
            }
          }
          else
          {
            *(_BYTE *)v13 = 0;
          }
        }
      }
      ++v10;
      ++v19;
    }
    while ( v19 < g_MouthEnvelope.m_Size );
    g_MouthEnvelope.m_Size = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10030B30
// Name: _SND_CloseMouth
// Source: json
//------------------------------------------------------------------------------
void __cdecl SND_CloseMouth(channel_t *pChannel)
{
  int speakerentity; // esi
  IClientEntity *v2; // eax
  int v3; // eax

  if ( (*((_BYTE *)&pChannel->flags + 1) & 0x40) != 0 )
  {
    speakerentity = pChannel->speakerentity;
    if ( speakerentity == -1 )
      speakerentity = pChannel->soundsource;
    v2 = entitylist->GetClientEntity(this: entitylist, a2: speakerentity);
    if ( v2 != nullptr && v2->GetMouth(this: v2) != nullptr )
    {
      v3 = CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::AddToTail(this: (CUtlVector<CAppSystemGroup::Module_t,CUtlMemory<CAppSystemGroup::Module_t,int> > *)&g_MouthOutput);
      g_MouthOutput.m_Memory.m_pMemory[v3].entityId = speakerentity;
      g_MouthOutput.m_Memory.m_pMemory[v3].pSource = pChannel->sfx->pSource;
      g_MouthOutput.m_Memory.m_pMemory[v3].elapsedTime = -1.0;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10030BC0
// Name: _SND_MoveMouth8
// Source: json
//------------------------------------------------------------------------------
void __cdecl SND_MoveMouth8(channel_t *ch, CAudioSource *pSource)
{
  char v3; // cl
  int speakerentity; // eax
  int v5; // esi
  int mouthentity; // [esp+Ch] [ebp+8h]
  float mouthentitya; // [esp+Ch] [ebp+8h]

  v3 = BYTE1(ch->flagsword);
  if ( (v3 & 0x40) != 0 )
  {
    speakerentity = ch->speakerentity;
    if ( speakerentity == -1 )
      speakerentity = ch->soundsource;
    mouthentity = speakerentity;
    if ( (v3 & 0x20) == 0 && pSource->GetSentence(this: pSource) != nullptr )
    {
      v5 = CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::AddToTail(this: (CUtlVector<CAppSystemGroup::Module_t,CUtlMemory<CAppSystemGroup::Module_t,int> > *)&g_MouthOutput);
      g_MouthOutput.m_Memory.m_pMemory[v5].entityId = mouthentity;
      g_MouthOutput.m_Memory.m_pMemory[v5].pSource = pSource;
      mouthentitya = (float)ch->pMixer->GetSamplePosition(this: ch->pMixer);
      g_MouthOutput.m_Memory.m_pMemory[v5].elapsedTime = mouthentitya / (float)pSource->SampleRate(this: pSource);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10030C70
// Name: _SND_MouthEnvelopeFollower
// Source: json
//------------------------------------------------------------------------------
void __cdecl SND_MouthEnvelopeFollower(channel_t *pChannel, char *pData, int count)
{
  char v4; // cl
  int speakerentity; // ecx
  int v6; // eax
  int v7; // ecx
  int v8; // esi
  int v9; // edi
  int v10; // ebx
  int v11; // eax
  int mix_sample_size; // [esp+0h] [ebp-4h]
  int mouthentity; // [esp+Ch] [ebp+8h]

  v4 = BYTE1(pChannel->flagsword);
  if ( (v4 & 0x40) != 0 && v4 < 0 && pData != nullptr && count != 0 )
  {
    speakerentity = pChannel->speakerentity;
    if ( speakerentity == -1 )
      speakerentity = pChannel->soundsource;
    mouthentity = speakerentity;
    v6 = pChannel->pMixer->GetMixSampleSize(this: pChannel->pMixer);
    v7 = 0;
    v8 = 0;
    v9 = 0;
    v10 = 0;
    mix_sample_size = v6;
    if ( count > 0 )
    {
      while ( v8 < 10 )
      {
        if ( v6 == 1 )
        {
          v10 = pData[v7];
        }
        else if ( v6 == 2 )
        {
          v10 = pData[2 * v7 + 1];
        }
        v7 += (v10 & 0x1F) + 80;
        v9 += abs32(v10);
        ++v8;
        if ( v7 >= count )
          break;
        v6 = mix_sample_size;
      }
    }
    v11 = CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::AddToTail(this: (CUtlVector<CAppSystemGroup::Module_t,CUtlMemory<CAppSystemGroup::Module_t,int> > *)&g_MouthEnvelope);
    g_MouthEnvelope.m_Memory.m_pMemory[v11].entityId = mouthentity;
    g_MouthEnvelope.m_Memory.m_pMemory[v11].sampleTotal = v9;
    g_MouthEnvelope.m_Memory.m_pMemory[v11].sampleCount = v8;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10030D50
// Name: _SND_ClearMouth
// Source: json
//------------------------------------------------------------------------------
void __cdecl SND_ClearMouth(channel_t *pChannel)
{
  int speakerentity; // edi
  int v2; // eax

  if ( (*((_BYTE *)&pChannel->flags + 1) & 0x40) != 0 && pChannel->sfx != nullptr )
  {
    speakerentity = pChannel->speakerentity;
    if ( speakerentity == -1 )
      speakerentity = pChannel->soundsource;
    v2 = CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::AddToTail(this: (CUtlVector<CAppSystemGroup::Module_t,CUtlMemory<CAppSystemGroup::Module_t,int> > *)&g_MouthOutput);
    g_MouthOutput.m_Memory.m_pMemory[v2].entityId = speakerentity;
    g_MouthOutput.m_Memory.m_pMemory[v2].pSource = pChannel->sfx->pSource;
    g_MouthOutput.m_Memory.m_pMemory[v2].elapsedTime = -1.0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10030DC0
// Name: void S_FreeChannel(struct channel_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl S_FreeChannel(channel_t *ch)
{
  char v1; // al
  char *v2; // eax
  CSfxTable *sfx; // ecx
  char *m_pszString; // eax
  ISoundServices_vtbl *v5; // edi
  const char *v6; // eax
  CAudioMixer *pMixer; // ecx
  CSosOperatorStackList *m_pStackList; // edi
  char nameBuf[260]; // [esp+4h] [ebp-104h] BYREF

  v1 = BYTE1(ch->flagsword);
  if ( (v1 & 4) == 0 )
  {
    *((_BYTE *)&ch->flags + 1) = v1 | 4;
    if ( (snd_find_channel.m_nFlags & 0x1000) != 0
      || (v2 = snd_find_channel.m_pParent->m_Value.m_pszString) != nullptr && *v2 != 0 )
    {
      sfx = ch->sfx;
      if ( sfx != nullptr )
      {
        CSfxTable::GetFileName(this: sfx, pOutBuf: nameBuf, bufLen: 0x104u);
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
          PrintChannel(pText1: "FreeChannel", pFileName: nameBuf, pChannel: ch, pText2: "from ConVar snd_find_channel.");
      }
    }
    SND_CloseMouth(pChannel: ch);
    v5 = g_pSoundServices->__vftable;
    v6 = ch->sfx->getname(this: ch->sfx, a2: nameBuf, a3: 260u);
    v5->OnSoundStopped(this: g_pSoundServices, a2: ch->guid, a3: ch->soundsource, a4: ch->entchannel, a5: v6);
    pMixer = ch->pMixer;
    LOBYTE(ch->flagsword) &= ~2u;
    if ( pMixer != nullptr )
      ((void (__thiscall *)(CAudioMixer *, int))pMixer->dtr_CAudioMixer)(a1: pMixer, a2: 1);
    m_pStackList = ch->m_pStackList;
    ch->pMixer = nullptr;
    ch->sfx = nullptr;
    ch->m_nSoundScriptHandle = -1;
    if ( m_pStackList != nullptr )
    {
      CSosOperatorStackList::~CSosOperatorStackList(this: m_pStackList);
      free(pMem: m_pStackList);
      ch->m_pStackList = nullptr;
    }
    CActiveChannels::Remove(this: &g_ActiveChannels, pChannel: ch);
    _V_memset(dest: ch, fill: 0, count: 332);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10030F20
// Name: void MIX_MixChannelsToPaintbuffer(class CChannelList __near &,__int64,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MIX_MixChannelsToPaintbuffer(CChannelList *list, __int64 endtime, int flags, int rate, int outputRate)
{
  int v5; // ecx
  channel_t *v6; // esi
  bool v7; // zf
  char flagsword; // al
  bool v9; // bl
  bool v10; // al
  int v11; // ebx
  CAudioMixer *pMixer; // ecx
  CAudioMixer *v13; // ecx
  CSosOperatorStackList *m_pStackList; // ecx
  int v15; // eax
  float flPitch; // [esp+4h] [ebp-10h]
  float flGlobalPitchScale; // [esp+8h] [ebp-Ch]
  int sampleCount; // [esp+Ch] [ebp-8h]
  int i; // [esp+10h] [ebp-4h]
  int v20; // [esp+24h] [ebp+10h]

  sampleCount = (endtime - g_paintedtime) / (44100 / outputRate);
  if ( sampleCount > 0 )
  {
    v5 = list->m_count - 1;
    flGlobalPitchScale = host_timescale.m_pParent->m_Value.m_fValue;
    v20 = v5;
    if ( v5 >= 0 )
    {
      for ( i = 2 * v5 + 4; ; i -= 2 )
      {
        v6 = &channels[*(__int16 *)((char *)&list->m_count + i)];
        if ( flags == 1 )
          break;
        if ( flags != 0 )
        {
          if ( flags != 2 )
            goto LABEL_13;
          v7 = (v6->flagsword & 8) == 0;
LABEL_12:
          if ( !v7 )
            goto LABEL_13;
          goto LABEL_36;
        }
        flagsword = v6->flagsword;
        if ( (flagsword & 4) == 0 && (flagsword & 8) == 0 )
        {
LABEL_13:
          if ( rate != 11025 && rate != 22050 && rate != 44100
            || rate == v6->sfx->pSource->SampleRate(this: v6->sfx->pSource) )
          {
            v9 = (*((_BYTE *)&v6->flags + 1) & 0x40) != 0;
            v10 = v9;
            if ( snd_pause_all.m_pParent != nullptr && snd_pause_all.m_pParent->m_Value.m_nValue != 0 )
              v10 = (*((_BYTE *)v6->sfx + 12) & 2) == 0;
            if ( !v10 || !g_pSoundServices->IsGamePaused(this: g_pSoundServices) )
            {
              if ( v9 && (*((_BYTE *)&v6->flags + 1) & 0x40) != 0 )
              {
                v11 = sampleCount;
                SND_MoveMouth8(ch: v6, pSource: v6->sfx->pSource);
              }
              else
              {
                v11 = sampleCount;
              }
              pMixer = v6->pMixer;
              flPitch = v6->pitch;
              v6->pitch = flPitch * flGlobalPitchScale;
              if ( list->m_quashed[v20] )
                pMixer->SkipSamples(this: pMixer, a2: v6, a3: v11, a4: outputRate, a5: 0);
              else
                pMixer->MixDataToDevice(this: pMixer, a2: g_AudioDevice, a3: v6, a4: v11, a5: outputRate, a6: 0);
              v13 = v6->pMixer;
              v6->pitch = flPitch;
              if ( !v13->ShouldContinueMixing(this: v13) )
              {
                m_pStackList = v6->m_pStackList;
                if ( m_pStackList != nullptr )
                  CSosOperatorStackList::Execute(
                    this: m_pStackList,
                    SosType: SOS_STOP,
                    pChannel: v6,
                    pScratchPad: &g_scratchpad);
                S_FreeChannel(ch: v6);
                v15 = --list->m_count;
                if ( list->m_count > 0 && v20 != v15 )
                {
                  *(_WORD *)((char *)&list->m_count + i) = list->m_list[v15];
                  list->m_quashed[v20] = list->m_quashed[list->m_count];
                }
              }
            }
          }
          v5 = v20;
        }
LABEL_36:
        v20 = --v5;
        if ( v5 < 0 )
          return;
      }
      v7 = (v6->flagsword & 4) == 0;
      goto LABEL_12;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10031140
// Name: void MIX_MixUpsampleBuffer(class CChannelList __near &,int,__int64,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MIX_MixUpsampleBuffer(CChannelList *list, int ipaintbuffer, __int64 end, int count, int flags)
{
  portable_samplepair_t *pbufcenter; // edx
  int v6; // eax
  portable_samplepair_t **p_pbuf; // ecx
  int v8; // eax
  paintbuffer_t *v9; // eax
  int ipaintcur; // [esp+Ch] [ebp-4h]

  pbufcenter = nullptr;
  v6 = 0;
  p_pbuf = &g_paintBuffers->pbuf;
  while ( g_curpaintbuffer != *p_pbuf )
  {
    ++v6;
    p_pbuf += 78;
    if ( v6 >= 6 )
    {
      ipaintcur = 0;
      goto LABEL_5;
    }
  }
  ipaintcur = v6;
LABEL_5:
  v8 = ipaintbuffer;
  g_paintBuffers[v8].ifilter = 0;
  g_paintBuffers->factive = false;
  g_paintBuffers[1].factive = false;
  g_paintBuffers[2].factive = false;
  g_paintBuffers[3].factive = false;
  g_paintBuffers[4].factive = false;
  g_paintBuffers[5].factive = false;
  g_paintBuffers[v8].factive = true;
  g_curpaintbuffer = g_paintBuffers[ipaintbuffer].pbuf;
  if ( g_paintBuffers[ipaintbuffer].fsurround )
  {
    g_currearpaintbuffer = g_paintBuffers[v8].pbufrear;
    g_curcenterpaintbuffer = nullptr;
    if ( !g_paintBuffers[v8].fsurround_center )
      goto LABEL_11;
    pbufcenter = g_paintBuffers[v8].pbufcenter;
  }
  else
  {
    g_currearpaintbuffer = nullptr;
  }
  g_curcenterpaintbuffer = pbufcenter;
LABEL_11:
  if ( (*((_BYTE *)list + 388) & 4) != 0 )
  {
    MIX_MixChannelsToPaintbuffer(list, endtime: end, flags, rate: 11025, outputRate: 11025);
    g_AudioDevice->MixUpsample(this: g_AudioDevice, a2: count / 4, a3: 1);
  }
  if ( (*((_BYTE *)list + 388) & 0xC) != 0 )
  {
    MIX_MixChannelsToPaintbuffer(list, endtime: end, flags, rate: 22050, outputRate: 22050);
    g_AudioDevice->MixUpsample(this: g_AudioDevice, a2: count / 2, a3: 1);
  }
  MIX_MixChannelsToPaintbuffer(list, endtime: end, flags, rate: 44100, outputRate: 44100);
  g_paintBuffers->factive = false;
  g_paintBuffers[1].factive = false;
  g_paintBuffers[2].factive = false;
  g_paintBuffers[3].factive = false;
  g_paintBuffers[4].factive = false;
  g_paintBuffers[5].factive = false;
  v9 = &g_paintBuffers[ipaintcur];
  g_curpaintbuffer = v9->pbuf;
  if ( v9->fsurround )
  {
    g_currearpaintbuffer = v9->pbufrear;
    g_curcenterpaintbuffer = nullptr;
    if ( v9->fsurround_center )
      g_curcenterpaintbuffer = v9->pbufcenter;
  }
  else
  {
    g_currearpaintbuffer = nullptr;
    g_curcenterpaintbuffer = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10031360
// Name: void MIX_UpsampleAllPaintbuffers(class CChannelList __near &,__int64,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MIX_UpsampleAllPaintbuffers(CChannelList *list, __int64 end, int count)
{
  if ( (*((_BYTE *)list + 388) & 2) != 0 )
    MIX_MixUpsampleBuffer(list, ipaintbuffer: 4, end, count, flags: 1);
  if ( (*((_BYTE *)list + 388) & 1) != 0 )
    MIX_MixUpsampleBuffer(list, ipaintbuffer: 5, end, count, flags: 2);
  g_paintBuffers->factive = false;
  g_paintBuffers[1].factive = false;
  g_paintBuffers[2].factive = false;
  g_paintBuffers[3].factive = false;
  g_paintBuffers[4].factive = false;
  g_paintBuffers[5].factive = false;
  g_paintBuffers->ifilter = 0;
  g_paintBuffers[1].ifilter = 0;
  g_paintBuffers[2].ifilter = 0;
  g_paintBuffers[3].ifilter = 0;
  g_paintBuffers[4].ifilter = 0;
  g_paintBuffers[5].ifilter = 0;
  if ( !g_bDspOff )
    g_paintBuffers[1].factive = true;
  g_paintBuffers[2].factive = true;
  if ( g_bdirectionalfx )
    g_paintBuffers[3].factive = true;
  MIX_MixChannelsToPaintbuffer(list, endtime: end, flags: 0, rate: 11025, outputRate: 11025);
  if ( !g_bDspOff )
  {
    g_curpaintbuffer = g_paintBuffers[1].pbuf;
    if ( g_paintBuffers[1].fsurround )
    {
      g_currearpaintbuffer = g_paintBuffers[1].pbufrear;
      g_curcenterpaintbuffer = nullptr;
      if ( g_paintBuffers[1].fsurround_center )
        g_curcenterpaintbuffer = g_paintBuffers[1].pbufcenter;
    }
    else
    {
      g_currearpaintbuffer = nullptr;
      g_curcenterpaintbuffer = nullptr;
    }
    g_AudioDevice->MixUpsample(this: g_AudioDevice, a2: count / 4, a3: 1);
  }
  g_curpaintbuffer = g_paintBuffers[2].pbuf;
  if ( g_paintBuffers[2].fsurround )
  {
    g_currearpaintbuffer = g_paintBuffers[2].pbufrear;
    g_curcenterpaintbuffer = nullptr;
    if ( g_paintBuffers[2].fsurround_center )
      g_curcenterpaintbuffer = g_paintBuffers[2].pbufcenter;
  }
  else
  {
    g_currearpaintbuffer = nullptr;
    g_curcenterpaintbuffer = nullptr;
  }
  g_AudioDevice->MixUpsample(this: g_AudioDevice, a2: count / 4, a3: 1);
  if ( g_bdirectionalfx )
  {
    g_curpaintbuffer = g_paintBuffers[3].pbuf;
    if ( g_paintBuffers[3].fsurround )
    {
      g_currearpaintbuffer = g_paintBuffers[3].pbufrear;
      g_curcenterpaintbuffer = nullptr;
      if ( g_paintBuffers[3].fsurround_center )
        g_curcenterpaintbuffer = g_paintBuffers[3].pbufcenter;
    }
    else
    {
      g_currearpaintbuffer = nullptr;
      g_curcenterpaintbuffer = nullptr;
    }
    g_AudioDevice->MixUpsample(this: g_AudioDevice, a2: count / 4, a3: 1);
  }
  MIX_MixChannelsToPaintbuffer(list, endtime: end, flags: 0, rate: 22050, outputRate: 22050);
  if ( !g_bDspOff )
  {
    g_curpaintbuffer = g_paintBuffers[1].pbuf;
    if ( g_paintBuffers[1].fsurround )
    {
      g_currearpaintbuffer = g_paintBuffers[1].pbufrear;
      g_curcenterpaintbuffer = nullptr;
      if ( g_paintBuffers[1].fsurround_center )
        g_curcenterpaintbuffer = g_paintBuffers[1].pbufcenter;
    }
    else
    {
      g_currearpaintbuffer = nullptr;
      g_curcenterpaintbuffer = nullptr;
    }
    g_AudioDevice->MixUpsample(this: g_AudioDevice, a2: count / 2, a3: 1);
  }
  g_curpaintbuffer = g_paintBuffers[2].pbuf;
  if ( g_paintBuffers[2].fsurround )
  {
    g_currearpaintbuffer = g_paintBuffers[2].pbufrear;
    g_curcenterpaintbuffer = nullptr;
    if ( g_paintBuffers[2].fsurround_center )
      g_curcenterpaintbuffer = g_paintBuffers[2].pbufcenter;
  }
  else
  {
    g_currearpaintbuffer = nullptr;
    g_curcenterpaintbuffer = nullptr;
  }
  g_AudioDevice->MixUpsample(this: g_AudioDevice, a2: count / 2, a3: 1);
  if ( g_bdirectionalfx )
  {
    g_curpaintbuffer = g_paintBuffers[3].pbuf;
    if ( g_paintBuffers[3].fsurround )
    {
      g_currearpaintbuffer = g_paintBuffers[3].pbufrear;
      g_curcenterpaintbuffer = nullptr;
      if ( g_paintBuffers[3].fsurround_center )
        g_curcenterpaintbuffer = g_paintBuffers[3].pbufcenter;
    }
    else
    {
      g_currearpaintbuffer = nullptr;
      g_curcenterpaintbuffer = nullptr;
    }
    g_AudioDevice->MixUpsample(this: g_AudioDevice, a2: count / 2, a3: 1);
  }
  MIX_MixChannelsToPaintbuffer(list, endtime: end, flags: 0, rate: 44100, outputRate: 44100);
  g_paintBuffers->factive = false;
  g_paintBuffers[1].factive = false;
  g_paintBuffers[2].factive = false;
  g_paintBuffers[3].factive = false;
  g_paintBuffers[4].factive = false;
  g_paintBuffers[5].factive = false;
  g_curpaintbuffer = g_paintBuffers->pbuf;
  if ( g_paintBuffers->fsurround )
  {
    g_currearpaintbuffer = g_paintBuffers->pbufrear;
    g_curcenterpaintbuffer = nullptr;
    if ( g_paintBuffers->fsurround_center )
      g_curcenterpaintbuffer = g_paintBuffers->pbufcenter;
  }
  else
  {
    g_currearpaintbuffer = nullptr;
    g_curcenterpaintbuffer = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100317C0
// Name: void MIX_BuildChannelList(class CChannelList __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MIX_BuildChannelList(CChannelList *list)
{
  bool (__thiscall *IsGamePaused)(ISoundServices *); // edx
  DWORD CurrentThreadId; // ecx
  int v4; // eax
  channel_t *v5; // esi
  char v6; // bl
  bool v7; // al
  CAudioSource *v8; // ecx
  int v9; // eax
  bool v10; // al
  int v11; // eax
  int v12; // eax
  char flagsword; // al
  CChannelCullList cullList; // [esp+18h] [ebp-698h] BYREF
  SoundError soundError; // [esp+69Ch] [ebp-14h] BYREF
  int v16; // [esp+6A0h] [ebp-10h]
  CAudioSource *pSource; // [esp+6A4h] [ebp-Ch]
  int i; // [esp+6A8h] [ebp-8h]
  bool bPaused; // [esp+6AEh] [ebp-2h]
  bool delayStartServer; // [esp+6AFh] [ebp-1h]
  char delayStartClient_3; // [esp+6BBh] [ebp+Bh]

  CActiveChannels::GetActiveChannels(this: &g_ActiveChannels, list);
  *((_BYTE *)list + 388) &= 0xE0u;
  IsGamePaused = g_pSoundServices->IsGamePaused;
  delayStartServer = false;
  delayStartClient_3 = 0;
  bPaused = IsGamePaused(this: g_pSoundServices);
  cullList.m_numChans = 0;
  if ( snd_cull_duplicates.m_pParent != nullptr && snd_cull_duplicates.m_pParent->m_Value.m_nValue > 0 )
    CChannelCullList::Initialize(this: &cullList, list);
  CurrentThreadId = GetCurrentThreadId();
  if ( CurrentThreadId != g_SoundMapMutex.m_ownerID
    && _InterlockedCompareExchange((volatile signed __int32 *)&g_SoundMapMutex, CurrentThreadId, 0) != 0 )
  {
    _mm_pause();
    CThreadFastMutex::Lock(a1: &g_SoundMapMutex, a2: CurrentThreadId, a3: 0);
  }
  else
  {
    ++g_SoundMapMutex.m_depth;
  }
  v4 = list->m_count - 1;
  i = v4;
  if ( v4 >= 0 )
  {
    v16 = 2 * v4 + 4;
    while ( 1 )
    {
      v5 = &channels[*(__int16 *)((char *)&list->m_count + v16)];
      v6 = 0;
      if ( !v5->pMixer->IsReadyToMix(this: v5->pMixer) )
      {
        v12 = (int)v5->pMixer->GetSource(this: v5->pMixer);
        if ( (*(int (__thiscall **)(int))(*(_DWORD *)v12 + 60))(a1: v12) == 3 )
          S_FreeChannel(ch: v5);
        goto LABEL_23;
      }
      pSource = S_LoadSound(pSfx: v5->sfx, ch: v5, &soundError);
      v7 = BChannelLowVolume(pch: v5, vol_min: 1);
      v8 = pSource;
      if ( pSource == nullptr )
        break;
      if ( v7 )
      {
        if ( ((unsigned __int8 (*)(void))pSource->IsLooped)() != 0 || (v5->flagsword & 4) != 0 )
          goto LABEL_17;
        if ( pSource->GetSentence(this: pSource) == nullptr )
          break;
LABEL_18:
        v8 = pSource;
      }
      if ( bPaused && (*((_BYTE *)&v5->flags + 1) & 0x10) != 0 )
      {
        v6 = 1;
      }
      else if ( v6 == 0
             && snd_cull_duplicates.m_pParent != nullptr
             && snd_cull_duplicates.m_pParent->m_Value.m_nValue > 0 )
      {
        v10 = cullList.m_numChans > i && cullList.m_bShouldCull[i];
        list->m_quashed[i] = v10;
LABEL_33:
        if ( (v5->flagsword & 8) != 0 )
          *((_BYTE *)list + 388) |= 1u;
        if ( (v5->flagsword & 4) != 0 )
          *((_BYTE *)list + 388) |= 2u;
        v11 = v8->SampleRate(this: v8);
        switch ( v11 )
        {
          case 11025:
            *((_BYTE *)list + 388) |= 4u;
            break;
          case 22050:
            *((_BYTE *)list + 388) |= 8u;
            break;
          case 44100:
            *((_BYTE *)list + 388) |= 0x10u;
            break;
          default:
            break;
        }
        flagsword = v5->flagsword;
        if ( (flagsword & 0x20) != 0 && (*((_BYTE *)&v5->flags + 1) & 0x40) == 0 )
        {
          if ( (flagsword & 0x40) != 0 )
            delayStartServer = true;
          else
            delayStartClient_3 = 1;
        }
        v5->pitch = ((double (__cdecl *)(_DWORD))v5->pMixer->ModifyPitch)(a1: (float)v5->basePitch * 0.0099999998);
        goto LABEL_51;
      }
      list->m_quashed[i] = false;
      if ( v6 == 0 )
        goto LABEL_33;
LABEL_23:
      v9 = --list->m_count;
      if ( list->m_count > 0 && i != v9 )
      {
        *(_WORD *)((char *)&list->m_count + v16) = list->m_list[v9];
        list->m_quashed[i] = list->m_quashed[list->m_count];
      }
LABEL_51:
      v16 -= 2;
      if ( --i < 0 )
        goto LABEL_52;
    }
    S_FreeChannel(ch: v5);
LABEL_17:
    v6 = 1;
    goto LABEL_18;
  }
LABEL_52:
  if ( bPaused || host_frametime_unbounded > host_frametime )
  {
    delayStartClient_3 = 0;
  }
  else if ( delayStartServer )
  {
    goto LABEL_57;
  }
  S_SyncClockAdjust(syncIndex: CLOCK_SYNC_SERVER);
LABEL_57:
  if ( delayStartClient_3 == 0 )
    S_SyncClockAdjust(syncIndex: CLOCK_SYNC_CLIENT);
  if ( --g_SoundMapMutex.m_depth == 0 )
    _InterlockedExchange((volatile __int32 *)&g_SoundMapMutex, 0);
}

} // namespace engine_xlsp
