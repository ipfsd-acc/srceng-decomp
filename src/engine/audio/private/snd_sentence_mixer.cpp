// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: engine/audio/private/snd_sentence_mixer.cpp
// Functions: 14
// ============================================================

#include "engine\audio\private\snd_sentence_mixer.h"

//------------------------------------------------------------------------------
// Address: 0x10035F20
// Name: public: virtual bool CSentenceMixer::IsReadyToMix(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CSentenceMixer::IsReadyToMix(CSentenceMixer *this)
{
  int m_currentWordIndex; // edi
  CAudioMixer **v4; // ebx
  char *v5; // eax
  int v6; // edi
  int v7; // ebx
  CAudioSource *v8; // eax
  int v9; // eax
  int sampleCount; // [esp+4h] [ebp-4h]

  if ( this->m_pCurrentWordMixer == nullptr )
    return 1;
  m_currentWordIndex = this->m_currentWordIndex;
  if ( m_currentWordIndex >= this->m_nNumWords )
  {
LABEL_8:
    if ( this->m_bNewWord )
    {
      v5 = (char *)this + 36 * this->m_currentWordIndex;
      this->m_bNewWord = false;
      v6 = *((_DWORD *)v5 + 6);
      v7 = *((_DWORD *)v5 + 7);
      if ( v7 <= v6 )
        v7 = 0;
      if ( v6 != 0 || v7 != 0 )
      {
        v8 = this->m_pCurrentWordMixer->GetSource(this: this->m_pCurrentWordMixer);
        v9 = v8->SampleCount(this: v8);
        sampleCount = v9;
        if ( (unsigned int)(v6 - 1) <= 0x62 )
        {
          this->m_pCurrentWordMixer->SetSampleStart(
            this: this->m_pCurrentWordMixer,
            a2: (int)(float)((float)((float)v9 * 0.0099999998) * (float)v6));
          v9 = sampleCount;
        }
        if ( (unsigned int)(v7 - 1) <= 0x62 )
          this->m_pCurrentWordMixer->SetSampleEnd(
            this: this->m_pCurrentWordMixer,
            a2: (int)(float)((float)((float)v9 * 0.0099999998) * (float)v7));
      }
    }
    return 1;
  }
  else
  {
    v4 = &this->m_pWordMixers[m_currentWordIndex];
    while ( *v4 == nullptr || (*v4)->IsReadyToMix(this: *v4) )
    {
      ++m_currentWordIndex;
      ++v4;
      if ( m_currentWordIndex >= this->m_nNumWords )
        goto LABEL_8;
    }
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10036030
// Name: public: virtual bool CSentenceMixer::ShouldContinueMixing(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CSentenceMixer::ShouldContinueMixing(CSentenceMixer *this)
{
  return this->m_pCurrentWordMixer != nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10036040
// Name: public: virtual class CAudioSource __near * CSentenceMixer::GetSource(void)
// Source: json
//------------------------------------------------------------------------------
CAudioSource *__thiscall CSentenceMixer::GetSource(CSentenceMixer *this)
{
  if ( this->m_pCurrentWordMixer != nullptr )
    return this->m_pCurrentWordMixer->GetSource(this: this->m_pCurrentWordMixer);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10036060
// Name: public: virtual int CSentenceMixer::GetSamplePosition(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CSentenceMixer::GetSamplePosition(CSentenceMixer *this)
{
  if ( this->m_pCurrentWordMixer != nullptr )
    return this->m_pCurrentWordMixer->GetSamplePosition(this: this->m_pCurrentWordMixer);
  else
    return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10036080
// Name: public: virtual void CSentenceMixer::SetSampleStart(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSentenceMixer::SetSampleStart(CSentenceMixer *this, int newPosition)
{
  if ( this->m_pCurrentWordMixer != nullptr )
    this->m_pCurrentWordMixer->SetSampleStart(this: this->m_pCurrentWordMixer, a2: newPosition);
}

//------------------------------------------------------------------------------
// Address: 0x100360A0
// Name: public: virtual void CSentenceMixer::SetSampleEnd(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSentenceMixer::SetSampleEnd(CSentenceMixer *this, int newEndPosition)
{
  if ( this->m_pCurrentWordMixer != nullptr )
    this->m_pCurrentWordMixer->SetSampleEnd(this: this->m_pCurrentWordMixer, a2: newEndPosition);
}

//------------------------------------------------------------------------------
// Address: 0x100360C0
// Name: public: virtual void CSentenceMixer::SetStartupDelaySamples(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSentenceMixer::SetStartupDelaySamples(CSentenceMixer *this, int delaySamples)
{
  if ( this->m_pCurrentWordMixer != nullptr )
    this->m_pCurrentWordMixer->SetStartupDelaySamples(this: this->m_pCurrentWordMixer, a2: delaySamples);
}

//------------------------------------------------------------------------------
// Address: 0x100360E0
// Name: public: virtual float CSentenceMixer::ModifyPitch(float)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CSentenceMixer::ModifyPitch(CSentenceMixer *this, float pitch)
{
  int v2; // ecx

  if ( this->m_pCurrentWordMixer != nullptr )
  {
    v2 = this->m_VoxWords[this->m_currentWordIndex].pitch;
    if ( v2 > 0 )
      return (float)((float)((float)(v2 - 100) * 0.0099999998) + pitch);
  }
  return pitch;
}

//------------------------------------------------------------------------------
// Address: 0x10036120
// Name: public: virtual float CSentenceMixer::GetVolumeScale(void)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CSentenceMixer::GetVolumeScale(CSentenceMixer *this)
{
  double result; // st7
  int volume; // [esp+0h] [ebp-4h]

  result = 1.0;
  if ( this->m_pCurrentWordMixer != nullptr )
  {
    volume = this->m_VoxWords[this->m_currentWordIndex].volume;
    if ( volume != 0 )
    {
      result = (double)volume * 0.01;
      if ( result >= 1.0 )
        return 1.0;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10036160
// Name: public: virtual int CSentenceMixer::MixDataToDevice(class IAudioDevice __near *,struct channel_t __near *,int,int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CSentenceMixer::MixDataToDevice(
        CSentenceMixer *this,
        IAudioDevice *pDevice,
        channel_t *pChannel,
        int sampleCount,
        int outputRate,
        int outputOffset)
{
  int v8; // ebx
  int v9; // edi
  CAudioMixer *m_pCurrentWordMixer; // ecx
  int v11; // eax
  int m_nNumWords; // edx
  int v13; // eax
  CAudioMixer *v14; // ecx

  if ( this->m_pCurrentWordMixer == nullptr )
    return 0;
  v8 = outputOffset;
  v9 = sampleCount;
  while ( v9 > 0 )
  {
    m_pCurrentWordMixer = this->m_pCurrentWordMixer;
    if ( m_pCurrentWordMixer == nullptr )
      break;
    v11 = m_pCurrentWordMixer->MixDataToDevice(
            this: m_pCurrentWordMixer,
            a2: pDevice,
            a3: pChannel,
            a4: v9,
            a5: outputRate,
            a6: v8);
    v8 += v11;
    v9 -= v11;
    if ( !this->m_pCurrentWordMixer->ShouldContinueMixing(this: this->m_pCurrentWordMixer) )
    {
      if ( (*((_BYTE *)&pChannel->flags + 1) & 0x40) != 0 )
        SND_ClearMouth(pChannel);
      m_nNumWords = this->m_nNumWords;
      do
      {
        v13 = ++this->m_currentWordIndex;
        if ( v13 >= m_nNumWords )
        {
          this->m_pCurrentWordMixer = nullptr;
          goto LABEL_12;
        }
        v14 = this->m_pWordMixers[v13];
        this->m_pCurrentWordMixer = v14;
      }
      while ( v14 == nullptr );
      this->m_bNewWord = true;
      pChannel->sfx = this->m_VoxWords[v13].sfx;
      if ( !this->IsReadyToMix(this) )
        return v8 - outputOffset;
    }
LABEL_12:
    ;
  }
  return v8 - outputOffset;
}

//------------------------------------------------------------------------------
// Address: 0x10036270
// Name: public: CSentenceMixer::CSentenceMixer(struct voxword_t __near *)
// Source: json
//------------------------------------------------------------------------------
CSentenceMixer *__thiscall CSentenceMixer::CSentenceMixer(CSentenceMixer *this, voxword_t *pWords)
{
  bool v3; // cc
  int v4; // edi
  CAudioSource *v5; // eax
  CAudioSource *v6; // esi
  CAudioMixer **v7; // ecx
  int v8; // eax
  int v9; // eax
  CAudioMixer **i; // ecx
  SoundError v12; // [esp+Ch] [ebp-10h] BYREF
  SoundError soundError; // [esp+10h] [ebp-Ch] BYREF
  CAudioMixer **m_pWordMixers; // [esp+14h] [ebp-8h]
  int nWord; // [esp+18h] [ebp-4h]
  CSfxTable **pWordsa; // [esp+24h] [ebp+8h]

  this->__vftable = (CSentenceMixer_vtbl *)&CSentenceMixer::`vftable';
  this->m_nNumWords = 0;
  if ( pWords->sfx != nullptr )
  {
    do
    {
      qmemcpy(
        &this->m_VoxWords[this->m_nNumWords],
        &pWords[this->m_nNumWords],
        sizeof(this->m_VoxWords[this->m_nNumWords]));
      ++this->m_nNumWords;
    }
    while ( this->m_nNumWords < 0x20u && pWords[this->m_nNumWords].sfx != nullptr );
  }
  v3 = this->m_nNumWords <= 0;
  nWord = 0;
  if ( !v3 )
  {
    m_pWordMixers = this->m_pWordMixers;
    pWordsa = &this->m_VoxWords[0].sfx;
    do
    {
      v4 = 0;
      if ( *pWordsa != nullptr )
      {
        v5 = S_LoadSound(pSfx: *pWordsa, ch: nullptr, &soundError);
        v6 = v5;
        if ( v5 != nullptr )
        {
          v5->SetSentenceWord(this: v5, a2: true);
          v4 = (int)v6->CreateMixer(this: v6, a2: 0, a3: 0, a4: false, a5: &v12);
        }
      }
      v7 = m_pWordMixers;
      v8 = nWord;
      pWordsa += 9;
      *m_pWordMixers = (CAudioMixer *)v4;
      nWord = v8 + 1;
      m_pWordMixers = v7 + 1;
    }
    while ( v8 + 1 < this->m_nNumWords );
  }
  v9 = 0;
  this->m_currentWordIndex = 0;
  this->m_pCurrentWordMixer = nullptr;
  if ( this->m_nNumWords > 0 )
  {
    for ( i = this->m_pWordMixers; *i == nullptr; ++i )
    {
      if ( ++v9 >= this->m_nNumWords )
      {
        this->m_bNewWord = this->m_pCurrentWordMixer != nullptr;
        return this;
      }
    }
    this->m_currentWordIndex = v9;
    this->m_pCurrentWordMixer = this->m_pWordMixers[v9];
  }
  this->m_bNewWord = this->m_pCurrentWordMixer != nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100363B0
// Name: public: virtual int CSentenceMixer::GetMixSampleSize(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CSentenceMixer::GetMixSampleSize(CSentenceMixer *this)
{
  if ( this->m_pCurrentWordMixer != nullptr )
    return this->m_pCurrentWordMixer->GetMixSampleSize(this: this->m_pCurrentWordMixer);
  else
    return 0;
}

//------------------------------------------------------------------------------
// Address: 0x100363E0
// Name: public: virtual CSentenceMixer::~CSentenceMixer(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSentenceMixer::~CSentenceMixer(CSentenceMixer *this)
{
  bool v2; // cc
  CSfxTable **p_sfx; // esi
  CAudioMixer **m_pWordMixers; // edi
  CAudioSource *pSource; // ecx
  int nWord; // [esp+4h] [ebp-4h]

  v2 = this->m_nNumWords <= 0;
  this->__vftable = (CSentenceMixer_vtbl *)&CSentenceMixer::`vftable';
  nWord = 0;
  if ( !v2 )
  {
    p_sfx = &this->m_VoxWords[0].sfx;
    m_pWordMixers = this->m_pWordMixers;
    do
    {
      if ( *m_pWordMixers != nullptr )
      {
        ((void (__thiscall *)(CAudioMixer *, int))(*m_pWordMixers)->dtr_CAudioMixer)(a1: *m_pWordMixers, a2: 1);
        *m_pWordMixers = nullptr;
      }
      if ( *p_sfx != nullptr && *(p_sfx - 3) == nullptr && (*p_sfx)->pSource->CanDelete(this: (*p_sfx)->pSource) )
      {
        pSource = (*p_sfx)->pSource;
        if ( pSource != nullptr )
          ((void (__thiscall *)(CAudioSource *, int))pSource->dtr_CAudioSource)(a1: pSource, a2: 1);
        (*p_sfx)->pSource = nullptr;
      }
      ++m_pWordMixers;
      p_sfx += 9;
      ++nWord;
    }
    while ( nWord < this->m_nNumWords );
  }
  this->__vftable = (CSentenceMixer_vtbl *)&CAudioMixer::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x10036480
// Name: class CAudioMixer __near * CreateSentenceMixer(struct voxword_t __near *)
// Source: json
//------------------------------------------------------------------------------
CSentenceMixer *__cdecl CreateSentenceMixer(voxword_t *pWords)
{
  CSentenceMixer *v1; // eax

  if ( pWords != nullptr && (v1 = (CSentenceMixer *)MemAlloc_Alloc(nSize: 0x514u)) != nullptr )
    return CSentenceMixer::CSentenceMixer(this: v1, pWords);
  else
    return nullptr;
}

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x10035C50
// Name: public: virtual bool CSentenceMixer::IsReadyToMix(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CSentenceMixer::IsReadyToMix(CSentenceMixer *this)
{
  int m_currentWordIndex; // edi
  CAudioMixer **v4; // ebx
  char *v5; // eax
  int v6; // edi
  int v7; // ebx
  CAudioSource *v8; // eax
  int v9; // eax
  int sampleCount; // [esp+4h] [ebp-4h]

  if ( this->m_pCurrentWordMixer == nullptr )
    return 1;
  m_currentWordIndex = this->m_currentWordIndex;
  if ( m_currentWordIndex >= this->m_nNumWords )
  {
LABEL_8:
    if ( this->m_bNewWord )
    {
      v5 = (char *)this + 36 * this->m_currentWordIndex;
      this->m_bNewWord = false;
      v6 = *((_DWORD *)v5 + 6);
      v7 = *((_DWORD *)v5 + 7);
      if ( v7 <= v6 )
        v7 = 0;
      if ( v6 != 0 || v7 != 0 )
      {
        v8 = this->m_pCurrentWordMixer->GetSource(this: this->m_pCurrentWordMixer);
        v9 = v8->SampleCount(this: v8);
        sampleCount = v9;
        if ( (unsigned int)(v6 - 1) <= 0x62 )
        {
          this->m_pCurrentWordMixer->SetSampleStart(
            this: this->m_pCurrentWordMixer,
            a2: (int)(float)((float)((float)v9 * 0.0099999998) * (float)v6));
          v9 = sampleCount;
        }
        if ( (unsigned int)(v7 - 1) <= 0x62 )
          this->m_pCurrentWordMixer->SetSampleEnd(
            this: this->m_pCurrentWordMixer,
            a2: (int)(float)((float)((float)v9 * 0.0099999998) * (float)v7));
      }
    }
    return 1;
  }
  else
  {
    v4 = &this->m_pWordMixers[m_currentWordIndex];
    while ( *v4 == nullptr || (*v4)->IsReadyToMix(this: *v4) )
    {
      ++m_currentWordIndex;
      ++v4;
      if ( m_currentWordIndex >= this->m_nNumWords )
        goto LABEL_8;
    }
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10035D60
// Name: public: virtual bool CSentenceMixer::ShouldContinueMixing(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CSentenceMixer::ShouldContinueMixing(CSentenceMixer *this)
{
  return this->m_pCurrentWordMixer != nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10035D70
// Name: public: virtual class CAudioSource __near * CSentenceMixer::GetSource(void)
// Source: json
//------------------------------------------------------------------------------
CAudioSource *__thiscall CSentenceMixer::GetSource(CSentenceMixer *this)
{
  if ( this->m_pCurrentWordMixer != nullptr )
    return this->m_pCurrentWordMixer->GetSource(this: this->m_pCurrentWordMixer);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10035D90
// Name: public: virtual int CSentenceMixer::GetSamplePosition(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CSentenceMixer::GetSamplePosition(CSentenceMixer *this)
{
  if ( this->m_pCurrentWordMixer != nullptr )
    return this->m_pCurrentWordMixer->GetSamplePosition(this: this->m_pCurrentWordMixer);
  else
    return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10035DB0
// Name: public: virtual void CSentenceMixer::SetSampleStart(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSentenceMixer::SetSampleStart(CSentenceMixer *this, int newPosition)
{
  if ( this->m_pCurrentWordMixer != nullptr )
    this->m_pCurrentWordMixer->SetSampleStart(this: this->m_pCurrentWordMixer, a2: newPosition);
}

//------------------------------------------------------------------------------
// Address: 0x10035DD0
// Name: public: virtual void CSentenceMixer::SetSampleEnd(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSentenceMixer::SetSampleEnd(CSentenceMixer *this, int newEndPosition)
{
  if ( this->m_pCurrentWordMixer != nullptr )
    this->m_pCurrentWordMixer->SetSampleEnd(this: this->m_pCurrentWordMixer, a2: newEndPosition);
}

//------------------------------------------------------------------------------
// Address: 0x10035DF0
// Name: public: virtual void CSentenceMixer::SetStartupDelaySamples(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSentenceMixer::SetStartupDelaySamples(CSentenceMixer *this, int delaySamples)
{
  if ( this->m_pCurrentWordMixer != nullptr )
    this->m_pCurrentWordMixer->SetStartupDelaySamples(this: this->m_pCurrentWordMixer, a2: delaySamples);
}

//------------------------------------------------------------------------------
// Address: 0x10035E10
// Name: public: virtual float CSentenceMixer::ModifyPitch(float)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CSentenceMixer::ModifyPitch(CSentenceMixer *this, float pitch)
{
  int v2; // ecx

  if ( this->m_pCurrentWordMixer != nullptr )
  {
    v2 = this->m_VoxWords[this->m_currentWordIndex].pitch;
    if ( v2 > 0 )
      return (float)((float)((float)(v2 - 100) * 0.0099999998) + pitch);
  }
  return pitch;
}

//------------------------------------------------------------------------------
// Address: 0x10035E50
// Name: public: virtual float CSentenceMixer::GetVolumeScale(void)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CSentenceMixer::GetVolumeScale(CSentenceMixer *this)
{
  double result; // st7
  int volume; // [esp+0h] [ebp-4h]

  result = 1.0;
  if ( this->m_pCurrentWordMixer != nullptr )
  {
    volume = this->m_VoxWords[this->m_currentWordIndex].volume;
    if ( volume != 0 )
    {
      result = (double)volume * 0.01;
      if ( result >= 1.0 )
        return 1.0;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10035EA0
// Name: public: virtual int CSentenceMixer::MixDataToDevice(class IAudioDevice __near *,struct channel_t __near *,int,int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CSentenceMixer::MixDataToDevice(
        CSentenceMixer *this,
        IAudioDevice *pDevice,
        channel_t *pChannel,
        int sampleCount,
        int outputRate,
        int outputOffset)
{
  int v8; // ebx
  int v9; // edi
  CAudioMixer *m_pCurrentWordMixer; // ecx
  int v11; // eax
  int m_nNumWords; // edx
  int v13; // eax
  CAudioMixer *v14; // ecx

  if ( this->m_pCurrentWordMixer == nullptr )
    return 0;
  v8 = outputOffset;
  v9 = sampleCount;
  while ( v9 > 0 )
  {
    m_pCurrentWordMixer = this->m_pCurrentWordMixer;
    if ( m_pCurrentWordMixer == nullptr )
      break;
    v11 = m_pCurrentWordMixer->MixDataToDevice(
            this: m_pCurrentWordMixer,
            a2: pDevice,
            a3: pChannel,
            a4: v9,
            a5: outputRate,
            a6: v8);
    v8 += v11;
    v9 -= v11;
    if ( !this->m_pCurrentWordMixer->ShouldContinueMixing(this: this->m_pCurrentWordMixer) )
    {
      if ( (*((_BYTE *)&pChannel->flags + 1) & 0x40) != 0 )
        SND_ClearMouth(pChannel);
      m_nNumWords = this->m_nNumWords;
      do
      {
        v13 = ++this->m_currentWordIndex;
        if ( v13 >= m_nNumWords )
        {
          this->m_pCurrentWordMixer = nullptr;
          goto LABEL_12;
        }
        v14 = this->m_pWordMixers[v13];
        this->m_pCurrentWordMixer = v14;
      }
      while ( v14 == nullptr );
      this->m_bNewWord = true;
      pChannel->sfx = this->m_VoxWords[v13].sfx;
      if ( !this->IsReadyToMix(this) )
        return v8 - outputOffset;
    }
LABEL_12:
    ;
  }
  return v8 - outputOffset;
}

//------------------------------------------------------------------------------
// Address: 0x10035FB0
// Name: public: CSentenceMixer::CSentenceMixer(struct voxword_t __near *)
// Source: json
//------------------------------------------------------------------------------
CSentenceMixer *__thiscall CSentenceMixer::CSentenceMixer(CSentenceMixer *this, voxword_t *pWords)
{
  bool v3; // cc
  int v4; // edi
  CAudioSource *v5; // eax
  CAudioSource *v6; // esi
  CAudioMixer **v7; // ecx
  int v8; // eax
  int v9; // eax
  CAudioMixer **i; // ecx
  SoundError v12; // [esp+Ch] [ebp-10h] BYREF
  SoundError soundError; // [esp+10h] [ebp-Ch] BYREF
  CAudioMixer **m_pWordMixers; // [esp+14h] [ebp-8h]
  int nWord; // [esp+18h] [ebp-4h]
  CSfxTable **pWordsa; // [esp+24h] [ebp+8h]

  this->__vftable = (CSentenceMixer_vtbl *)&CSentenceMixer::`vftable';
  this->m_nNumWords = 0;
  if ( pWords->sfx != nullptr )
  {
    do
    {
      qmemcpy(
        &this->m_VoxWords[this->m_nNumWords],
        &pWords[this->m_nNumWords],
        sizeof(this->m_VoxWords[this->m_nNumWords]));
      ++this->m_nNumWords;
    }
    while ( this->m_nNumWords < 0x20u && pWords[this->m_nNumWords].sfx != nullptr );
  }
  v3 = this->m_nNumWords <= 0;
  nWord = 0;
  if ( !v3 )
  {
    m_pWordMixers = this->m_pWordMixers;
    pWordsa = &this->m_VoxWords[0].sfx;
    do
    {
      v4 = 0;
      if ( *pWordsa != nullptr )
      {
        v5 = S_LoadSound(pSfx: *pWordsa, ch: nullptr, &soundError);
        v6 = v5;
        if ( v5 != nullptr )
        {
          v5->SetSentenceWord(this: v5, a2: true);
          v4 = (int)v6->CreateMixer(this: v6, a2: 0, a3: 0, a4: false, a5: &v12);
        }
      }
      v7 = m_pWordMixers;
      v8 = nWord;
      pWordsa += 9;
      *m_pWordMixers = (CAudioMixer *)v4;
      nWord = v8 + 1;
      m_pWordMixers = v7 + 1;
    }
    while ( v8 + 1 < this->m_nNumWords );
  }
  v9 = 0;
  this->m_currentWordIndex = 0;
  this->m_pCurrentWordMixer = nullptr;
  if ( this->m_nNumWords > 0 )
  {
    for ( i = this->m_pWordMixers; *i == nullptr; ++i )
    {
      if ( ++v9 >= this->m_nNumWords )
      {
        this->m_bNewWord = this->m_pCurrentWordMixer != nullptr;
        return this;
      }
    }
    this->m_currentWordIndex = v9;
    this->m_pCurrentWordMixer = this->m_pWordMixers[v9];
  }
  this->m_bNewWord = this->m_pCurrentWordMixer != nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100360F0
// Name: public: virtual int CSentenceMixer::GetMixSampleSize(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CSentenceMixer::GetMixSampleSize(CSentenceMixer *this)
{
  if ( this->m_pCurrentWordMixer != nullptr )
    return this->m_pCurrentWordMixer->GetMixSampleSize(this: this->m_pCurrentWordMixer);
  else
    return 0;
}

//------------------------------------------------------------------------------
// Address: 0x100361C0
// Name: class CAudioMixer __near * CreateSentenceMixer(struct voxword_t __near *)
// Source: json
//------------------------------------------------------------------------------
CSentenceMixer *__cdecl CreateSentenceMixer(voxword_t *pWords)
{
  CSentenceMixer *v1; // eax

  if ( pWords != nullptr && (v1 = (CSentenceMixer *)MemAlloc_Alloc(nSize: 0x514u)) != nullptr )
    return CSentenceMixer::CSentenceMixer(this: v1, pWords);
  else
    return nullptr;
}

} // namespace engine_xlsp
