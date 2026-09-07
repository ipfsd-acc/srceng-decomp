// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: public/soundparametersinternal.cpp
// Functions: 10
// ============================================================

#include "public\soundparametersinternal.h"

//------------------------------------------------------------------------------
// Address: 0x00412E90
// Name: public: static float float16::Convert16bitFloatTo32bits(unsigned short)
// Source: json
//------------------------------------------------------------------------------
double __cdecl float16::Convert16bitFloatTo32bits(unsigned int input)
{
  int v1; // ecx
  float v3; // xmm0_4

  v1 = (input >> 10) & 0x1F;
  if ( v1 == 31 )
  {
    if ( (input & 0x3FF) != 0 )
    {
      return 0.0;
    }
    else if ( (input & 0x8000) != 0 )
    {
      return -1.0 * 65504.0;
    }
    else
    {
      return 1.0 * 65504.0;
    }
  }
  else if ( (_WORD)v1 != 0 || (input & 0x3FF) == 0 )
  {
    return COERCE_FLOAT((input & 0x3FF
                       | (8
                        * (input & 0x8000
                         | ((((((unsigned __int16)input >> 10) & 0x1F) + 112)
                           * ((((unsigned __int16)input >> 10) & 0x1F) != 0)) << 7)))) << 13);
  }
  else
  {
    if ( (input & 0x8000) != 0 )
      v3 = -1.0;
    else
      v3 = 1.0;
    return (float)((float)(v3 * (float)((float)(input & 0x3FF) * 0.0009765625)) * 0.000061035156);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00412F90
// Name: public: struct SoundFile const __near * CSoundParametersInternal::GetSoundNames(void)const
// Source: json
//------------------------------------------------------------------------------
const SoundFile *__thiscall CSoundParametersInternal::GetSoundNames(CSoundParametersInternal *this)
{
  const SoundFile *result; // eax

  result = (const SoundFile *)this;
  if ( this->m_nSoundNames != 1 )
    return this->m_pSoundNames;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00412FA0
// Name: public: CSoundParametersInternal::~CSoundParametersInternal(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSoundParametersInternal::~CSoundParametersInternal(CSoundParametersInternal *this)
{
  KeyValues *m_pOperatorsKV; // ecx

  if ( this->m_nSoundNames > 1u )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_pSoundNames);
  if ( this->m_nConvertedNames > 1u )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_pConvertedNames);
  m_pOperatorsKV = this->m_pOperatorsKV;
  if ( m_pOperatorsKV != nullptr )
  {
    KeyValues::deleteThis(this: m_pOperatorsKV);
    this->m_pOperatorsKV = nullptr;
  }
  this->m_pConvertedNames = nullptr;
  this->m_pSoundNames = nullptr;
  *(_DWORD *)&this->m_nSoundNames = 0;
}

//------------------------------------------------------------------------------
// Address: 0x00413000
// Name: public: void CSoundParametersInternal::SetOperatorsKV(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSoundParametersInternal::SetOperatorsKV(CSoundParametersInternal *this, KeyValues *src)
{
  KeyValues *m_pOperatorsKV; // ecx
  KeyValues *v4; // eax
  KeyValues *v5; // eax

  m_pOperatorsKV = this->m_pOperatorsKV;
  if ( m_pOperatorsKV != nullptr )
    KeyValues::deleteThis(this: m_pOperatorsKV);
  this->m_pOperatorsKV = nullptr;
  v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v4 != nullptr )
  {
    v5 = KeyValues::KeyValues(this: v4, setName: "Operators");
    this->m_pOperatorsKV = v5;
    KeyValues::CopySubkeys(this: src, pParent: v5);
  }
  else
  {
    this->m_pOperatorsKV = nullptr;
    KeyValues::CopySubkeys(this: src, pParent: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00413060
// Name: public: void CSoundParametersInternal::CopyFrom(struct CSoundParametersInternal const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSoundParametersInternal::CopyFrom(CSoundParametersInternal *this, const CSoundParametersInternal *src)
{
  char v3; // dl
  unsigned int m_nSoundNames; // eax
  SoundFile *v5; // eax
  unsigned int v6; // ecx
  unsigned int m_nConvertedNames; // eax
  SoundFile *v8; // eax
  unsigned int v9; // ecx

  if ( this->m_nSoundNames > 1u )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_pSoundNames);
  if ( this->m_nConvertedNames > 1u )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_pConvertedNames);
  this->channel = src->channel;
  this->volume = src->volume;
  this->pitch = src->pitch;
  v3 = *((_BYTE *)this + 28);
  this->soundlevel = src->soundlevel;
  this->delay_msec = src->delay_msec;
  *((_BYTE *)this + 28) ^= (*((_BYTE *)src + 28) ^ v3) & 1;
  m_nSoundNames = src->m_nSoundNames;
  this->m_nSoundNames = m_nSoundNames;
  if ( (_WORD)m_nSoundNames != 0 )
  {
    if ( m_nSoundNames <= 1 )
    {
      this->m_pSoundNames = src->m_pSoundNames;
    }
    else
    {
      v5 = (SoundFile *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 4 * m_nSoundNames);
      v6 = 4 * this->m_nSoundNames;
      this->m_pSoundNames = v5;
      memcpy(dst: (unsigned __int8 *)v5, src: (unsigned __int8 *)src->m_pSoundNames, count: v6);
    }
  }
  else
  {
    this->m_pSoundNames = nullptr;
  }
  m_nConvertedNames = src->m_nConvertedNames;
  this->m_nConvertedNames = m_nConvertedNames;
  if ( (_WORD)m_nConvertedNames != 0 )
  {
    if ( m_nConvertedNames <= 1 )
    {
      this->m_pConvertedNames = src->m_pConvertedNames;
    }
    else
    {
      v8 = (SoundFile *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 4 * m_nConvertedNames);
      v9 = 4 * this->m_nConvertedNames;
      this->m_pConvertedNames = v8;
      memcpy(dst: (unsigned __int8 *)v8, src: (unsigned __int8 *)src->m_pConvertedNames, count: v9);
    }
  }
  else
  {
    this->m_pConvertedNames = nullptr;
  }
  if ( src->m_pOperatorsKV != nullptr )
    CSoundParametersInternal::SetOperatorsKV(this, src: src->m_pOperatorsKV);
  *((_BYTE *)this + 28) ^= (*((_BYTE *)src + 28) ^ *((_BYTE *)this + 28)) & 2;
  *((_BYTE *)this + 28) ^= (*((_BYTE *)this + 28) ^ *((_BYTE *)src + 28)) & 4;
}

//------------------------------------------------------------------------------
// Address: 0x004131A0
// Name: public: bool CSoundParametersInternal::operator==(struct CSoundParametersInternal const __near &)const
// Source: json
//------------------------------------------------------------------------------
char __thiscall CSoundParametersInternal::operator==(CSoundParametersInternal *this, CSoundParametersInternal *other)
{
  CSoundParametersInternal *v3; // ecx
  int v5; // esi
  const SoundFile *SoundNames; // ebx
  int c; // [esp+4h] [ebp-4h]

  v3 = other;
  if ( this == other )
    return 1;
  if ( this->channel != other->channel
    || *(_DWORD *)&this->volume != *(_DWORD *)&other->volume
    || other->pitch.start != this->pitch.start
    || other->pitch.range != this->pitch.range
    || *(_DWORD *)&this->soundlevel != *(_DWORD *)&other->soundlevel
    || this->delay_msec != other->delay_msec
    || ((*((_BYTE *)this + 28) ^ *((_BYTE *)other + 28)) & 1) != 0
    || this->m_nSoundNames != other->m_nSoundNames )
  {
    return 0;
  }
  v5 = 0;
  c = this->m_nSoundNames;
  if ( this->m_nSoundNames == 0 )
    return 1;
  while ( 1 )
  {
    SoundNames = CSoundParametersInternal::GetSoundNames(this: v3);
    if ( CSoundParametersInternal::GetSoundNames(this)[v5].symbol.m_Id != SoundNames[v5].symbol.m_Id )
      break;
    if ( ++v5 >= c )
      return 1;
    v3 = other;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x00413260
// Name: public: static unsigned short float16::ConvertFloatTo16bitsNonDefault<0>(float)
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __cdecl float16::ConvertFloatTo16bitsNonDefault<0>(float input)
{
  float v1; // xmm0_4
  int v2; // xmm1_4
  int v3; // eax
  int v4; // ecx
  int v5; // ecx
  float16::float16bits output; // [esp+8h] [ebp+8h]

  v1 = input;
  v2 = 1199562752;
  if ( input > 65504.0 || (v2 = -947920896, input < -65504.0) )
    v1 = *(float *)&v2;
  v3 = LOWORD(v1) & 0x7FFF | (LODWORD(v1) >> 31 << 15);
  v4 = (unsigned __int8)(LODWORD(v1) >> 23);
  output.rawWord = LOWORD(v1) & 0x7FFF | (LODWORD(v1) >> 31 << 15);
  if ( (unsigned __int8)(LODWORD(v1) >> 23) != 0 )
  {
    if ( v4 == 255 )
    {
      if ( (LODWORD(v1) & 0x7FFFFF) != 0 )
        LOWORD(v3) = LODWORD(v1) >> 31 << 15;
      else
        LOWORD(v3) = LOWORD(v1) & 0x7BFF | (LODWORD(v1) >> 31 << 15) | 0x7BFF;
    }
    else
    {
      v5 = v4 - 127;
      if ( v5 < -24 )
      {
        LOWORD(v3) = LODWORD(v1) >> 31 << 15;
        output.rawWord = v3;
      }
      if ( v5 >= -14 )
      {
        if ( v5 <= 15 )
          return (((_WORD)v5 + 15) << 10) & 0x7C00 | (LODWORD(v1) >> 13) & 0x3FF | output.rawWord & 0x8000;
        else
          LOWORD(v3) = output.rawWord & 0x8000 | 0x7BFF;
      }
      else
      {
        LOWORD(v3) = v3 & 0x83FF;
        if ( (unsigned int)(-14 - v5 - 1) <= 9 )
          LOWORD(v3) = (v3 ^ ((1 << (10 - (-14 - v5))) + ((LODWORD(v1) & 0x7FFFFFu) >> (-14 - v5 + 13)))) & 0x3FF ^ v3;
      }
    }
  }
  else
  {
    LOWORD(v3) = LODWORD(v1) >> 31 << 15;
  }
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x00413380
// Name: public: CSoundParametersInternal::CSoundParametersInternal(void)
// Source: json
//------------------------------------------------------------------------------
CSoundParametersInternal *__thiscall CSoundParametersInternal::CSoundParametersInternal(CSoundParametersInternal *this)
{
  this->m_pSoundNames = nullptr;
  this->m_pConvertedNames = nullptr;
  *(_DWORD *)&this->m_nSoundNames = 0;
  this->channel = 0;
  this->volume.start.m_storage.rawWord = float16::ConvertFloatTo16bitsNonDefault<0>(input: 1.0);
  this->volume.range.m_storage.rawWord = float16::ConvertFloatTo16bitsNonDefault<0>(input: 0.0);
  *((_BYTE *)this + 28) &= 0xF8u;
  this->m_pOperatorsKV = nullptr;
  this->m_pGameData = nullptr;
  this->pitch = (sound_interval_t<unsigned char>)100;
  this->soundlevel = (sound_interval_t<unsigned short>)75;
  *(_DWORD *)&this->delay_msec = 0x10000;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004133F0
// Name: public: char const __near * CSoundParametersInternal::VolumeToString(void)const
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CSoundParametersInternal::VolumeToString(CSoundParametersInternal *this)
{
  unsigned int rawWord; // edi
  VolumeLevel *v2; // ecx
  unsigned int v4; // esi
  double v5; // st7
  double v6; // [esp+8h] [ebp-14h]
  float v7; // [esp+18h] [ebp-4h]
  float v8; // [esp+18h] [ebp-4h]

  rawWord = this->volume.range.m_storage.rawWord;
  if ( (_WORD)rawWord == ZERO_FLOAT16.m_storage.rawWord )
  {
    v7 = float16::Convert16bitFloatTo32bits(input: this->volume.start.m_storage.rawWord);
    v2 = g_pVolumeLevels;
    while ( v2->volume != v7 )
    {
      if ( (int)++v2 >= (int)g_pPitchLookup )
      {
        V_snprintf(pDest: pDest, maxLen: 32, pFormat: "%.3f", v7);
        return pDest;
      }
    }
    return (char *)v2->name;
  }
  else
  {
    v4 = this->volume.start.m_storage.rawWord;
    v8 = float16::Convert16bitFloatTo32bits(input: v4);
    v6 = float16::Convert16bitFloatTo32bits(input: rawWord) + v8;
    v5 = float16::Convert16bitFloatTo32bits(input: v4);
    V_snprintf(pDest: sz, maxLen: 64, pFormat: "%.3f, %.3f", v5, v6);
    return sz;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004134B0
// Name: public: void CSoundParametersInternal::VolumeFromString(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSoundParametersInternal::VolumeFromString(CSoundParametersInternal *this, const char *sz)
{
  float16::float16bits v3; // ax
  float range; // xmm0_4
  interval_t input; // [esp+Ch] [ebp-8h]

  if ( V_strcasecmp(s1: sz, s2: "VOL_NORM") != 0 )
  {
    input = ReadInterval(pString: sz);
    v3.rawWord = float16::ConvertFloatTo16bitsNonDefault<0>(input: input.start);
    range = input.range;
  }
  else
  {
    v3.rawWord = float16::ConvertFloatTo16bitsNonDefault<0>(input: 1.0);
    range = 0.0;
  }
  this->volume.start.m_storage = v3;
  this->volume.range.m_storage.rawWord = float16::ConvertFloatTo16bitsNonDefault<0>(input: range);
}

// ============================================================
// Overlay from scenemanager (Missing functions)
// ============================================================
namespace scenemanager {

//------------------------------------------------------------------------------
// Address: 0x0040FBE0
// Name: public: static float float16::Convert16bitFloatTo32bits(unsigned short)
// Source: json
//------------------------------------------------------------------------------
double __cdecl float16::Convert16bitFloatTo32bits(unsigned int input)
{
  int v1; // ecx
  float v3; // xmm0_4

  v1 = (input >> 10) & 0x1F;
  if ( v1 == 31 )
  {
    if ( (input & 0x3FF) != 0 )
    {
      return 0.0;
    }
    else if ( (input & 0x8000) != 0 )
    {
      return -1.0 * 65504.0;
    }
    else
    {
      return 1.0 * 65504.0;
    }
  }
  else if ( (_WORD)v1 != 0 || (input & 0x3FF) == 0 )
  {
    return COERCE_FLOAT((input & 0x3FF
                       | (8
                        * (input & 0x8000
                         | ((((((unsigned __int16)input >> 10) & 0x1F) + 112)
                           * ((((unsigned __int16)input >> 10) & 0x1F) != 0)) << 7)))) << 13);
  }
  else
  {
    if ( (input & 0x8000) != 0 )
      v3 = -1.0;
    else
      v3 = 1.0;
    return (float)((float)(v3 * (float)((float)(input & 0x3FF) * 0.0009765625)) * 0.000061035156);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040FCE0
// Name: enum soundlevel_t TextToSoundLevel(char const __near *)
// Source: json
//------------------------------------------------------------------------------
soundlevel_t __cdecl TextToSoundLevel(const char *key)
{
  soundlevel_t result; // eax
  SoundLevelLookup *v2; // esi
  int v3; // eax
  int v4; // eax

  if ( key == nullptr )
    return SNDLVL_NORM;
  v2 = g_pSoundLevels;
  do
  {
    if ( V_strcasecmp(s1: key, s2: v2->name) == 0 )
      return v2->level;
    ++v2;
  }
  while ( (int)v2 < (int)&CStatusWindow `RTTI Type Descriptor' );
  v3 = _V_strlen(str: "SNDLVL_");
  if ( V_strnicmp(s1: key, s2: "SNDLVL_", n: v3) != 0
    || (v4 = _V_strlen(str: "SNDLVL_"), (unsigned int)((result = atoi(nptr: &key[v4])) - 1) > 0xB3) )
  {
    DevMsg(a1: "CSoundEmitterSystem:  Unknown sound level %s\n", key);
    return SNDLVL_NORM;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0040FD70
// Name: int TextToChannel(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl TextToChannel(const char *name)
{
  int v2; // esi

  if ( name == nullptr )
    return 0;
  if ( V_strncasecmp(s1: name, s2: "chan_", n: 5) != 0 )
    return atoi(nptr: name);
  v2 = 0;
  while ( V_strcasecmp(s1: name, s2: g_pChannelNames[v2].name) != 0 )
  {
    if ( ++v2 >= 7 )
    {
      DevMsg(a1: "CSoundEmitterSystem:  Warning, unknown channel type in sounds.txt (%s)\n", name);
      return 0;
    }
  }
  return g_pChannelNames[v2].channel;
}

//------------------------------------------------------------------------------
// Address: 0x0040FDE0
// Name: public: CSoundParametersInternal::~CSoundParametersInternal(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSoundParametersInternal::~CSoundParametersInternal(CSoundParametersInternal *this)
{
  KeyValues *m_pOperatorsKV; // ecx

  if ( this->m_nSoundNames > 1u )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_pSoundNames);
  if ( this->m_nConvertedNames > 1u )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_pConvertedNames);
  m_pOperatorsKV = this->m_pOperatorsKV;
  if ( m_pOperatorsKV != nullptr )
  {
    KeyValues::deleteThis(this: m_pOperatorsKV);
    this->m_pOperatorsKV = nullptr;
  }
  this->m_pConvertedNames = nullptr;
  this->m_pSoundNames = nullptr;
  *(_DWORD *)&this->m_nSoundNames = 0;
}

//------------------------------------------------------------------------------
// Address: 0x0040FE40
// Name: public: void CSoundParametersInternal::SetOperatorsKV(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSoundParametersInternal::SetOperatorsKV(CSoundParametersInternal *this, KeyValues *src)
{
  KeyValues *m_pOperatorsKV; // ecx
  KeyValues *v4; // eax
  KeyValues *v5; // eax

  m_pOperatorsKV = this->m_pOperatorsKV;
  if ( m_pOperatorsKV != nullptr )
    KeyValues::deleteThis(this: m_pOperatorsKV);
  this->m_pOperatorsKV = nullptr;
  v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v4 != nullptr )
  {
    v5 = KeyValues::KeyValues(this: v4, setName: "Operators");
    this->m_pOperatorsKV = v5;
    KeyValues::CopySubkeys(this: src, pParent: v5);
  }
  else
  {
    this->m_pOperatorsKV = nullptr;
    KeyValues::CopySubkeys(this: src, pParent: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040FEA0
// Name: public: void CSoundParametersInternal::CopyFrom(struct CSoundParametersInternal const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSoundParametersInternal::CopyFrom(CSoundParametersInternal *this, const CSoundParametersInternal *src)
{
  char v3; // dl
  unsigned int m_nSoundNames; // eax
  SoundFile *v5; // eax
  unsigned int v6; // ecx
  unsigned int m_nConvertedNames; // eax
  SoundFile *v8; // eax
  unsigned int v9; // ecx

  if ( this->m_nSoundNames > 1u )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_pSoundNames);
  if ( this->m_nConvertedNames > 1u )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_pConvertedNames);
  this->channel = src->channel;
  this->volume = src->volume;
  this->pitch = src->pitch;
  v3 = *((_BYTE *)this + 28);
  this->soundlevel = src->soundlevel;
  this->delay_msec = src->delay_msec;
  *((_BYTE *)this + 28) ^= (*((_BYTE *)src + 28) ^ v3) & 1;
  m_nSoundNames = src->m_nSoundNames;
  this->m_nSoundNames = m_nSoundNames;
  if ( (_WORD)m_nSoundNames != 0 )
  {
    if ( m_nSoundNames <= 1 )
    {
      this->m_pSoundNames = src->m_pSoundNames;
    }
    else
    {
      v5 = (SoundFile *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 4 * m_nSoundNames);
      v6 = 4 * this->m_nSoundNames;
      this->m_pSoundNames = v5;
      memcpy(dst: (unsigned __int8 *)v5, src: (unsigned __int8 *)src->m_pSoundNames, count: v6);
    }
  }
  else
  {
    this->m_pSoundNames = nullptr;
  }
  m_nConvertedNames = src->m_nConvertedNames;
  this->m_nConvertedNames = m_nConvertedNames;
  if ( (_WORD)m_nConvertedNames != 0 )
  {
    if ( m_nConvertedNames <= 1 )
    {
      this->m_pConvertedNames = src->m_pConvertedNames;
    }
    else
    {
      v8 = (SoundFile *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 4 * m_nConvertedNames);
      v9 = 4 * this->m_nConvertedNames;
      this->m_pConvertedNames = v8;
      memcpy(dst: (unsigned __int8 *)v8, src: (unsigned __int8 *)src->m_pConvertedNames, count: v9);
    }
  }
  else
  {
    this->m_pConvertedNames = nullptr;
  }
  if ( src->m_pOperatorsKV != nullptr )
    CSoundParametersInternal::SetOperatorsKV(this, src: src->m_pOperatorsKV);
  *((_BYTE *)this + 28) ^= (*((_BYTE *)src + 28) ^ *((_BYTE *)this + 28)) & 2;
  *((_BYTE *)this + 28) ^= (*((_BYTE *)this + 28) ^ *((_BYTE *)src + 28)) & 4;
}

//------------------------------------------------------------------------------
// Address: 0x0040FFE0
// Name: public: char const __near * CSoundParametersInternal::ChannelToString(void)const
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CSoundParametersInternal::ChannelToString(CSoundParametersInternal *this)
{
  int channel; // ecx
  SoundChannels *v2; // eax

  channel = this->channel;
  v2 = g_pChannelNames;
  while ( v2->channel != channel )
  {
    if ( (int)++v2 >= (int)g_pVolumeLevels )
    {
      V_snprintf(pDest: pDest, maxLen: 32, pFormat: "%i", channel);
      return pDest;
    }
  }
  return (char *)v2->name;
}

//------------------------------------------------------------------------------
// Address: 0x00410020
// Name: public: char const __near * CSoundParametersInternal::SoundLevelToString(void)const
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CSoundParametersInternal::SoundLevelToString(CSoundParametersInternal *this)
{
  int range; // edx
  int start; // ecx
  SoundLevelLookup *v3; // eax

  range = this->soundlevel.range;
  if ( (_WORD)range != 0 )
  {
    V_snprintf(pDest: sz, maxLen: 64, pFormat: "%i, %i", this->soundlevel.start, this->soundlevel.start + range);
    return sz;
  }
  else
  {
    start = this->soundlevel.start;
    v3 = g_pSoundLevels;
    while ( v3->level != start )
    {
      if ( (int)++v3 >= (int)&CStatusWindow `RTTI Type Descriptor' )
      {
        V_snprintf(pDest: byte_48CBAC, maxLen: 32, pFormat: "%i", start);
        return byte_48CBAC;
      }
    }
    return (char *)v3->name;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00410090
// Name: public: char const __near * CSoundParametersInternal::PitchToString(void)const
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CSoundParametersInternal::PitchToString(CSoundParametersInternal *this)
{
  unsigned __int8 range; // dl
  int start; // eax
  float v3; // xmm0_4
  PitchLookup *v4; // ecx

  range = this->pitch.range;
  start = this->pitch.start;
  if ( range != 0 )
  {
    V_snprintf(pDest: sz_0, maxLen: 64, pFormat: "%i, %i", start, start + range);
    return sz_0;
  }
  else
  {
    v3 = (float)start;
    v4 = g_pPitchLookup;
    while ( v4->pitch != v3 )
    {
      if ( (int)++v4 >= (int)g_pSoundLevels )
      {
        V_snprintf(pDest: byte_48CC0C, maxLen: 32, pFormat: "%.3f", v3);
        return byte_48CC0C;
      }
    }
    return (char *)v4->name;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00410110
// Name: public: void CSoundParametersInternal::ChannelFromString(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSoundParametersInternal::ChannelFromString(CSoundParametersInternal *this, const char *sz)
{
  this->channel = TextToChannel(name: sz);
}

//------------------------------------------------------------------------------
// Address: 0x00410130
// Name: public: static unsigned short float16::ConvertFloatTo16bitsNonDefault<0>(float)
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __cdecl float16::ConvertFloatTo16bitsNonDefault<0>(float input)
{
  float v1; // xmm0_4
  int v2; // xmm1_4
  int v3; // eax
  int v4; // ecx
  int v5; // ecx
  float16::float16bits output; // [esp+8h] [ebp+8h]

  v1 = input;
  v2 = 1199562752;
  if ( input > 65504.0 || (v2 = -947920896, input < -65504.0) )
    v1 = *(float *)&v2;
  v3 = LOWORD(v1) & 0x7FFF | (LODWORD(v1) >> 31 << 15);
  v4 = (unsigned __int8)(LODWORD(v1) >> 23);
  output.rawWord = LOWORD(v1) & 0x7FFF | (LODWORD(v1) >> 31 << 15);
  if ( (unsigned __int8)(LODWORD(v1) >> 23) != 0 )
  {
    if ( v4 == 255 )
    {
      if ( (LODWORD(v1) & 0x7FFFFF) != 0 )
        LOWORD(v3) = LODWORD(v1) >> 31 << 15;
      else
        LOWORD(v3) = LOWORD(v1) & 0x7BFF | (LODWORD(v1) >> 31 << 15) | 0x7BFF;
    }
    else
    {
      v5 = v4 - 127;
      if ( v5 < -24 )
      {
        LOWORD(v3) = LODWORD(v1) >> 31 << 15;
        output.rawWord = v3;
      }
      if ( v5 >= -14 )
      {
        if ( v5 <= 15 )
          return (((_WORD)v5 + 15) << 10) & 0x7C00 | (LODWORD(v1) >> 13) & 0x3FF | output.rawWord & 0x8000;
        else
          LOWORD(v3) = output.rawWord & 0x8000 | 0x7BFF;
      }
      else
      {
        LOWORD(v3) = v3 & 0x83FF;
        if ( (unsigned int)(-14 - v5 - 1) <= 9 )
          LOWORD(v3) = (v3 ^ ((1 << (10 - (-14 - v5))) + ((LODWORD(v1) & 0x7FFFFFu) >> (-14 - v5 + 13)))) & 0x3FF ^ v3;
      }
    }
  }
  else
  {
    LOWORD(v3) = LODWORD(v1) >> 31 << 15;
  }
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x00410250
// Name: public: CSoundParametersInternal::CSoundParametersInternal(void)
// Source: json
//------------------------------------------------------------------------------
CSoundParametersInternal *__thiscall CSoundParametersInternal::CSoundParametersInternal(CSoundParametersInternal *this)
{
  this->m_pSoundNames = nullptr;
  this->m_pConvertedNames = nullptr;
  *(_DWORD *)&this->m_nSoundNames = 0;
  this->channel = 0;
  this->volume.start.m_storage.rawWord = float16::ConvertFloatTo16bitsNonDefault<0>(input: 1.0);
  this->volume.range.m_storage.rawWord = float16::ConvertFloatTo16bitsNonDefault<0>(input: 0.0);
  *((_BYTE *)this + 28) &= 0xF8u;
  this->m_pOperatorsKV = nullptr;
  this->m_pGameData = nullptr;
  this->pitch = (sound_interval_t<unsigned char>)100;
  this->soundlevel = (sound_interval_t<unsigned short>)75;
  *(_DWORD *)&this->delay_msec = 0x10000;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004102C0
// Name: public: char const __near * CSoundParametersInternal::VolumeToString(void)const
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CSoundParametersInternal::VolumeToString(CSoundParametersInternal *this)
{
  unsigned int rawWord; // edi
  VolumeLevel *v2; // ecx
  unsigned int v4; // esi
  double v5; // st7
  double v6; // [esp+8h] [ebp-14h]
  float v7; // [esp+18h] [ebp-4h]
  float v8; // [esp+18h] [ebp-4h]

  rawWord = this->volume.range.m_storage.rawWord;
  if ( (_WORD)rawWord == ZERO_FLOAT16.m_storage.rawWord )
  {
    v7 = float16::Convert16bitFloatTo32bits(input: this->volume.start.m_storage.rawWord);
    v2 = g_pVolumeLevels;
    while ( v2->volume != v7 )
    {
      if ( (int)++v2 >= (int)g_pPitchLookup )
      {
        V_snprintf(pDest: byte_48CBEC, maxLen: 32, pFormat: "%.3f", v7);
        return byte_48CBEC;
      }
    }
    return (char *)v2->name;
  }
  else
  {
    v4 = this->volume.start.m_storage.rawWord;
    v8 = float16::Convert16bitFloatTo32bits(input: v4);
    v6 = float16::Convert16bitFloatTo32bits(input: rawWord) + v8;
    v5 = float16::Convert16bitFloatTo32bits(input: v4);
    V_snprintf(pDest: sz_1, maxLen: 64, pFormat: "%.3f, %.3f", v5, v6);
    return sz_1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00410380
// Name: public: void CSoundParametersInternal::PitchFromString(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSoundParametersInternal::PitchFromString(CSoundParametersInternal *this, const char *sz)
{
  interval_t Interval; // [esp+8h] [ebp-8h]

  if ( V_strcasecmp(s1: sz, s2: "PITCH_NORM") != 0 )
  {
    if ( V_strcasecmp(s1: sz, s2: "PITCH_LOW") != 0 )
    {
      if ( V_strcasecmp(s1: sz, s2: "PITCH_HIGH") != 0 )
      {
        Interval = ReadInterval(pString: sz);
        this->pitch.start = (int)Interval.start;
        this->pitch.range = (int)Interval.range;
      }
      else
      {
        this->pitch = (sound_interval_t<unsigned char>)120;
      }
    }
    else
    {
      this->pitch = (sound_interval_t<unsigned char>)95;
    }
  }
  else
  {
    this->pitch = (sound_interval_t<unsigned char>)100;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00410420
// Name: public: void CSoundParametersInternal::SoundLevelFromString(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSoundParametersInternal::SoundLevelFromString(CSoundParametersInternal *this, const char *sz)
{
  interval_t Interval; // [esp+8h] [ebp-8h]

  if ( V_strncasecmp(s1: sz, s2: "SNDLVL_", n: 7) != 0 )
  {
    Interval = ReadInterval(pString: sz);
    this->soundlevel.start = (int)Interval.start;
    this->soundlevel.range = (int)Interval.range;
  }
  else
  {
    this->soundlevel.start = TextToSoundLevel(key: sz);
    this->soundlevel.range = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00410490
// Name: private: void CSoundParametersInternal::AddToTail(struct SoundFile __near * __near *,unsigned short __near *,struct SoundFile const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSoundParametersInternal::AddToTail(
        CSoundParametersInternal *this,
        SoundFile **pDest,
        unsigned __int16 *pDestCount,
        const SoundFile *source)
{
  unsigned __int16 v5; // ax
  __int16 v6; // bx
  SoundFile *v7; // eax
  __int16 *v8; // esi
  __int16 temp_2; // [esp+12h] [ebp+Eh]

  v5 = ++*pDestCount;
  if ( *pDestCount == 1 )
  {
    *pDest = (SoundFile *)*source;
  }
  else
  {
    v6 = -1;
    temp_2 = 256;
    if ( v5 == 2 )
    {
      v6 = *(_WORD *)pDest;
      temp_2 = *((_WORD *)pDest + 1);
      *pDest = nullptr;
    }
    v7 = (SoundFile *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: *pDest, a3: 4 * *pDestCount);
    *pDest = v7;
    v7[*pDestCount - 1] = *source;
    if ( *pDestCount == 2 )
    {
      v8 = (__int16 *)*pDest;
      *v8 = v6;
      v8[1] = temp_2;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00410540
// Name: public: void CSoundParametersInternal::VolumeFromString(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSoundParametersInternal::VolumeFromString(CSoundParametersInternal *this, const char *sz)
{
  float16::float16bits v3; // ax
  float range; // xmm0_4
  interval_t input; // [esp+Ch] [ebp-8h]

  if ( V_strcasecmp(s1: sz, s2: "VOL_NORM") != 0 )
  {
    input = ReadInterval(pString: sz);
    v3.rawWord = float16::ConvertFloatTo16bitsNonDefault<0>(input: input.start);
    range = input.range;
  }
  else
  {
    v3.rawWord = float16::ConvertFloatTo16bitsNonDefault<0>(input: 1.0);
    range = 0.0;
  }
  this->volume.start.m_storage = v3;
  this->volume.range.m_storage.rawWord = float16::ConvertFloatTo16bitsNonDefault<0>(input: range);
}

} // namespace scenemanager

// ============================================================
// Overlay from SoundEmitterSystem (Missing functions)
// ============================================================
namespace SoundEmitterSystem {

//------------------------------------------------------------------------------
// Address: 0x100012D0
// Name: public: struct SoundFile const __near * CSoundParametersInternal::GetSoundNames(void)const
// Source: json
//------------------------------------------------------------------------------
SoundFile *__thiscall CSoundParametersInternal::GetSoundNames(CSoundParametersInternal *this)
{
  SoundFile *result; // eax

  result = (SoundFile *)this;
  if ( this->m_nSoundNames != 1 )
    return this->m_pSoundNames;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10007DC0
// Name: enum soundlevel_t TextToSoundLevel(char const __near *)
// Source: json
//------------------------------------------------------------------------------
soundlevel_t __cdecl TextToSoundLevel(const char *key)
{
  soundlevel_t result; // eax
  SoundLevelLookup *v2; // esi
  int v3; // eax
  int v4; // eax

  if ( key == nullptr )
    return SNDLVL_NORM;
  v2 = g_pSoundLevels;
  do
  {
    if ( V_strcasecmp(s1: key, s2: v2->name) == 0 )
      return v2->level;
    ++v2;
  }
  while ( (int)v2 < (int)&vec2_invalid_0 );
  v3 = _V_strlen(str: "SNDLVL_");
  if ( V_strnicmp(s1: key, s2: "SNDLVL_", n: v3) != 0
    || (v4 = _V_strlen(str: "SNDLVL_"), (unsigned int)((result = atoi(nptr: &key[v4])) - 1) > 0xB3) )
  {
    DevMsg(a1: "CSoundEmitterSystem:  Unknown sound level %s\n", key);
    return SNDLVL_NORM;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10007E50
// Name: int TextToChannel(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl TextToChannel(const char *name)
{
  int v2; // esi

  if ( name == nullptr )
    return 0;
  if ( V_strncasecmp(s1: name, s2: "chan_", n: 5) != 0 )
    return atoi(nptr: name);
  v2 = 0;
  while ( V_strcasecmp(s1: name, s2: g_pChannelNames[v2].name) != 0 )
  {
    if ( ++v2 >= 7 )
    {
      DevMsg(a1: "CSoundEmitterSystem:  Warning, unknown channel type in sounds.txt (%s)\n", name);
      return 0;
    }
  }
  return g_pChannelNames[v2].channel;
}

//------------------------------------------------------------------------------
// Address: 0x10007EC0
// Name: public: CSoundParametersInternal::~CSoundParametersInternal(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSoundParametersInternal::~CSoundParametersInternal(CSoundParametersInternal *this)
{
  KeyValues *m_pOperatorsKV; // ecx

  if ( this->m_nSoundNames > 1u )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_pSoundNames);
  if ( this->m_nConvertedNames > 1u )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_pConvertedNames);
  m_pOperatorsKV = this->m_pOperatorsKV;
  if ( m_pOperatorsKV != nullptr )
  {
    KeyValues::deleteThis(this: m_pOperatorsKV);
    this->m_pOperatorsKV = nullptr;
  }
  this->m_pConvertedNames = nullptr;
  this->m_pSoundNames = nullptr;
  *(_DWORD *)&this->m_nSoundNames = 0;
}

//------------------------------------------------------------------------------
// Address: 0x10007F20
// Name: public: void CSoundParametersInternal::SetOperatorsKV(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSoundParametersInternal::SetOperatorsKV(CSoundParametersInternal *this, KeyValues *src)
{
  KeyValues *m_pOperatorsKV; // ecx
  KeyValues *v4; // eax
  KeyValues *v5; // eax

  m_pOperatorsKV = this->m_pOperatorsKV;
  if ( m_pOperatorsKV != nullptr )
    KeyValues::deleteThis(this: m_pOperatorsKV);
  this->m_pOperatorsKV = nullptr;
  v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v4 != nullptr )
  {
    v5 = KeyValues::KeyValues(this: v4, setName: "Operators");
    this->m_pOperatorsKV = v5;
    KeyValues::CopySubkeys(this: src, pParent: v5);
  }
  else
  {
    this->m_pOperatorsKV = nullptr;
    KeyValues::CopySubkeys(this: src, pParent: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10007F90
// Name: public: void CSoundParametersInternal::CopyFrom(struct CSoundParametersInternal const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSoundParametersInternal::CopyFrom(CSoundParametersInternal *this, const CSoundParametersInternal *src)
{
  char v3; // dl
  unsigned int m_nSoundNames; // eax
  SoundFile *v5; // eax
  unsigned int v6; // ecx
  unsigned int m_nConvertedNames; // eax
  SoundFile *v8; // eax
  unsigned int v9; // ecx

  if ( this->m_nSoundNames > 1u )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_pSoundNames);
  if ( this->m_nConvertedNames > 1u )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_pConvertedNames);
  this->channel = src->channel;
  this->volume = src->volume;
  this->pitch = src->pitch;
  v3 = *((_BYTE *)this + 28);
  this->soundlevel = src->soundlevel;
  this->delay_msec = src->delay_msec;
  *((_BYTE *)this + 28) ^= (*((_BYTE *)src + 28) ^ v3) & 1;
  m_nSoundNames = src->m_nSoundNames;
  this->m_nSoundNames = m_nSoundNames;
  if ( (_WORD)m_nSoundNames != 0 )
  {
    if ( m_nSoundNames <= 1 )
    {
      this->m_pSoundNames = src->m_pSoundNames;
    }
    else
    {
      v5 = (SoundFile *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 4 * m_nSoundNames);
      v6 = 4 * this->m_nSoundNames;
      this->m_pSoundNames = v5;
      memcpy(dst: (unsigned __int8 *)v5, src: (unsigned __int8 *)src->m_pSoundNames, count: v6);
    }
  }
  else
  {
    this->m_pSoundNames = nullptr;
  }
  m_nConvertedNames = src->m_nConvertedNames;
  this->m_nConvertedNames = m_nConvertedNames;
  if ( (_WORD)m_nConvertedNames != 0 )
  {
    if ( m_nConvertedNames <= 1 )
    {
      this->m_pConvertedNames = src->m_pConvertedNames;
    }
    else
    {
      v8 = (SoundFile *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 4 * m_nConvertedNames);
      v9 = 4 * this->m_nConvertedNames;
      this->m_pConvertedNames = v8;
      memcpy(dst: (unsigned __int8 *)v8, src: (unsigned __int8 *)src->m_pConvertedNames, count: v9);
    }
  }
  else
  {
    this->m_pConvertedNames = nullptr;
  }
  if ( src->m_pOperatorsKV != nullptr )
    CSoundParametersInternal::SetOperatorsKV(this, src: src->m_pOperatorsKV);
  *((_BYTE *)this + 28) ^= (*((_BYTE *)src + 28) ^ *((_BYTE *)this + 28)) & 2;
  *((_BYTE *)this + 28) ^= (*((_BYTE *)this + 28) ^ *((_BYTE *)src + 28)) & 4;
}

//------------------------------------------------------------------------------
// Address: 0x100080D0
// Name: public: bool CSoundParametersInternal::operator==(struct CSoundParametersInternal const __near &)const
// Source: json
//------------------------------------------------------------------------------
char __thiscall CSoundParametersInternal::operator==(CSoundParametersInternal *this, CSoundParametersInternal *other)
{
  CSoundParametersInternal *v3; // ecx
  int v5; // esi
  SoundFile *SoundNames; // ebx
  int c; // [esp+4h] [ebp-4h]

  v3 = other;
  if ( this == other )
    return 1;
  if ( this->channel != other->channel
    || *(_DWORD *)&this->volume != *(_DWORD *)&other->volume
    || other->pitch.start != this->pitch.start
    || other->pitch.range != this->pitch.range
    || *(_DWORD *)&this->soundlevel != *(_DWORD *)&other->soundlevel
    || this->delay_msec != other->delay_msec
    || ((*((_BYTE *)this + 28) ^ *((_BYTE *)other + 28)) & 1) != 0
    || this->m_nSoundNames != other->m_nSoundNames )
  {
    return 0;
  }
  v5 = 0;
  c = this->m_nSoundNames;
  if ( this->m_nSoundNames == 0 )
    return 1;
  while ( 1 )
  {
    SoundNames = CSoundParametersInternal::GetSoundNames(this: v3);
    if ( CSoundParametersInternal::GetSoundNames(this)[v5].symbol.m_Id != SoundNames[v5].symbol.m_Id )
      break;
    if ( ++v5 >= c )
      return 1;
    v3 = other;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10008190
// Name: public: char const __near * CSoundParametersInternal::ChannelToString(void)const
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CSoundParametersInternal::ChannelToString(CSoundParametersInternal *this)
{
  int channel; // ecx
  SoundChannels *v2; // eax

  channel = this->channel;
  v2 = g_pChannelNames;
  while ( v2->channel != channel )
  {
    if ( (int)++v2 >= (int)g_pVolumeLevels )
    {
      V_snprintf(pDest: pDest, maxLen: 32, pFormat: "%i", channel);
      return pDest;
    }
  }
  return (char *)v2->name;
}

//------------------------------------------------------------------------------
// Address: 0x100081D0
// Name: public: char const __near * CSoundParametersInternal::SoundLevelToString(void)const
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CSoundParametersInternal::SoundLevelToString(CSoundParametersInternal *this)
{
  int range; // edx
  int start; // ecx
  SoundLevelLookup *v3; // eax

  range = this->soundlevel.range;
  if ( (_WORD)range != 0 )
  {
    V_snprintf(pDest: sz, maxLen: 64, pFormat: "%i, %i", this->soundlevel.start, this->soundlevel.start + range);
    return sz;
  }
  else
  {
    start = this->soundlevel.start;
    v3 = g_pSoundLevels;
    while ( v3->level != start )
    {
      if ( (int)++v3 >= (int)&vec2_invalid_0 )
      {
        V_snprintf(pDest: byte_100246C0, maxLen: 32, pFormat: "%i", start);
        return byte_100246C0;
      }
    }
    return (char *)v3->name;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10008240
// Name: public: char const __near * CSoundParametersInternal::PitchToString(void)const
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CSoundParametersInternal::PitchToString(CSoundParametersInternal *this)
{
  unsigned __int8 range; // dl
  int start; // eax
  float v3; // xmm0_4
  PitchLookup *v4; // ecx

  range = this->pitch.range;
  start = this->pitch.start;
  if ( range != 0 )
  {
    V_snprintf(pDest: sz_0, maxLen: 64, pFormat: "%i, %i", start, start + range);
    return sz_0;
  }
  else
  {
    v3 = (float)start;
    v4 = g_pPitchLookup;
    while ( v4->pitch != v3 )
    {
      if ( (int)++v4 >= (int)g_pSoundLevels )
      {
        V_snprintf(pDest: byte_10024720, maxLen: 32, pFormat: "%.3f", v3);
        return byte_10024720;
      }
    }
    return (char *)v4->name;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100082C0
// Name: public: void CSoundParametersInternal::ChannelFromString(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSoundParametersInternal::ChannelFromString(CSoundParametersInternal *this, const char *sz)
{
  this->channel = TextToChannel(name: sz);
}

//------------------------------------------------------------------------------
// Address: 0x100082E0
// Name: public: static unsigned short float16::ConvertFloatTo16bitsNonDefault<0>(float)
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __cdecl float16::ConvertFloatTo16bitsNonDefault<0>(float input)
{
  float v1; // xmm0_4
  int v2; // xmm1_4
  int v3; // eax
  int v4; // ecx
  int v5; // ecx
  float16::float16bits output; // [esp+8h] [ebp+8h]

  v1 = input;
  v2 = 1199562752;
  if ( input > 65504.0 || (v2 = -947920896, input < -65504.0) )
    v1 = *(float *)&v2;
  v3 = LOWORD(v1) & 0x7FFF | (LODWORD(v1) >> 31 << 15);
  v4 = (unsigned __int8)(LODWORD(v1) >> 23);
  output.rawWord = LOWORD(v1) & 0x7FFF | (LODWORD(v1) >> 31 << 15);
  if ( (unsigned __int8)(LODWORD(v1) >> 23) != 0 )
  {
    if ( v4 == 255 )
    {
      if ( (LODWORD(v1) & 0x7FFFFF) != 0 )
        LOWORD(v3) = LODWORD(v1) >> 31 << 15;
      else
        LOWORD(v3) = LOWORD(v1) & 0x7BFF | (LODWORD(v1) >> 31 << 15) | 0x7BFF;
    }
    else
    {
      v5 = v4 - 127;
      if ( v5 < -24 )
      {
        LOWORD(v3) = LODWORD(v1) >> 31 << 15;
        output.rawWord = v3;
      }
      if ( v5 >= -14 )
      {
        if ( v5 <= 15 )
          return (((_WORD)v5 + 15) << 10) & 0x7C00 | (LODWORD(v1) >> 13) & 0x3FF | output.rawWord & 0x8000;
        else
          LOWORD(v3) = output.rawWord & 0x8000 | 0x7BFF;
      }
      else
      {
        LOWORD(v3) = v3 & 0x83FF;
        if ( (unsigned int)(-14 - v5 - 1) <= 9 )
          LOWORD(v3) = (v3 ^ ((1 << (10 - (-14 - v5))) + ((LODWORD(v1) & 0x7FFFFFu) >> (-14 - v5 + 13)))) & 0x3FF ^ v3;
      }
    }
  }
  else
  {
    LOWORD(v3) = LODWORD(v1) >> 31 << 15;
  }
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x10008400
// Name: public: CSoundParametersInternal::CSoundParametersInternal(void)
// Source: json
//------------------------------------------------------------------------------
CSoundParametersInternal *__thiscall CSoundParametersInternal::CSoundParametersInternal(CSoundParametersInternal *this)
{
  this->m_pSoundNames = nullptr;
  this->m_pConvertedNames = nullptr;
  *(_DWORD *)&this->m_nSoundNames = 0;
  this->channel = 0;
  this->volume.start.m_storage.rawWord = float16::ConvertFloatTo16bitsNonDefault<0>(input: 1.0);
  this->volume.range.m_storage.rawWord = float16::ConvertFloatTo16bitsNonDefault<0>(input: 0.0);
  *((_BYTE *)this + 28) &= 0xF8u;
  this->m_pOperatorsKV = nullptr;
  this->m_pGameData = nullptr;
  this->pitch = (sound_interval_t<unsigned char>)100;
  this->soundlevel = (sound_interval_t<unsigned short>)75;
  *(_DWORD *)&this->delay_msec = 0x10000;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10008470
// Name: public: char const __near * CSoundParametersInternal::VolumeToString(void)const
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CSoundParametersInternal::VolumeToString(CSoundParametersInternal *this)
{
  unsigned int rawWord; // edi
  VolumeLevel *v2; // ecx
  unsigned int v4; // esi
  double v5; // st7
  double v6; // [esp+8h] [ebp-14h]
  float v7; // [esp+18h] [ebp-4h]
  float v8; // [esp+18h] [ebp-4h]

  rawWord = this->volume.range.m_storage.rawWord;
  if ( (_WORD)rawWord == ZERO_FLOAT16.m_storage.rawWord )
  {
    v7 = float16::Convert16bitFloatTo32bits(input: this->volume.start.m_storage.rawWord);
    v2 = g_pVolumeLevels;
    while ( v2->volume != v7 )
    {
      if ( (int)++v2 >= (int)g_pPitchLookup )
      {
        V_snprintf(pDest: byte_10024700, maxLen: 32, pFormat: "%.3f", v7);
        return byte_10024700;
      }
    }
    return (char *)v2->name;
  }
  else
  {
    v4 = this->volume.start.m_storage.rawWord;
    v8 = float16::Convert16bitFloatTo32bits(input: v4);
    v6 = float16::Convert16bitFloatTo32bits(input: rawWord) + v8;
    v5 = float16::Convert16bitFloatTo32bits(input: v4);
    V_snprintf(pDest: sz_1, maxLen: 64, pFormat: "%.3f, %.3f", v5, v6);
    return sz_1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10008530
// Name: public: void CSoundParametersInternal::PitchFromString(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSoundParametersInternal::PitchFromString(CSoundParametersInternal *this, const char *sz)
{
  interval_t Interval; // [esp+8h] [ebp-8h]

  if ( V_strcasecmp(s1: sz, s2: "PITCH_NORM") != 0 )
  {
    if ( V_strcasecmp(s1: sz, s2: "PITCH_LOW") != 0 )
    {
      if ( V_strcasecmp(s1: sz, s2: "PITCH_HIGH") != 0 )
      {
        Interval = ReadInterval(pString: sz);
        this->pitch.start = (int)Interval.start;
        this->pitch.range = (int)Interval.range;
      }
      else
      {
        this->pitch = (sound_interval_t<unsigned char>)120;
      }
    }
    else
    {
      this->pitch = (sound_interval_t<unsigned char>)95;
    }
  }
  else
  {
    this->pitch = (sound_interval_t<unsigned char>)100;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100085D0
// Name: public: void CSoundParametersInternal::SoundLevelFromString(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSoundParametersInternal::SoundLevelFromString(CSoundParametersInternal *this, const char *sz)
{
  interval_t Interval; // [esp+8h] [ebp-8h]

  if ( V_strncasecmp(s1: sz, s2: "SNDLVL_", n: 7) != 0 )
  {
    Interval = ReadInterval(pString: sz);
    this->soundlevel.start = (int)Interval.start;
    this->soundlevel.range = (int)Interval.range;
  }
  else
  {
    this->soundlevel.start = TextToSoundLevel(key: sz);
    this->soundlevel.range = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10008640
// Name: private: void CSoundParametersInternal::AddToTail(struct SoundFile __near * __near *,unsigned short __near *,struct SoundFile const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSoundParametersInternal::AddToTail(
        CSoundParametersInternal *this,
        SoundFile **pDest,
        unsigned __int16 *pDestCount,
        const SoundFile *source)
{
  unsigned __int16 v5; // ax
  __int16 v6; // bx
  SoundFile *v7; // eax
  __int16 *v8; // esi
  __int16 temp_2; // [esp+12h] [ebp+Eh]

  v5 = ++*pDestCount;
  if ( *pDestCount == 1 )
  {
    *pDest = (SoundFile *)*source;
  }
  else
  {
    v6 = -1;
    temp_2 = 256;
    if ( v5 == 2 )
    {
      v6 = *(_WORD *)pDest;
      temp_2 = *((_WORD *)pDest + 1);
      *pDest = nullptr;
    }
    v7 = (SoundFile *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: *pDest, a3: 4 * *pDestCount);
    *pDest = v7;
    v7[*pDestCount - 1] = *source;
    if ( *pDestCount == 2 )
    {
      v8 = (__int16 *)*pDest;
      *v8 = v6;
      v8[1] = temp_2;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100086F0
// Name: public: void CSoundParametersInternal::VolumeFromString(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSoundParametersInternal::VolumeFromString(CSoundParametersInternal *this, const char *sz)
{
  float16::float16bits v3; // ax
  float range; // xmm0_4
  interval_t input; // [esp+Ch] [ebp-8h]

  if ( V_strcasecmp(s1: sz, s2: "VOL_NORM") != 0 )
  {
    input = ReadInterval(pString: sz);
    v3.rawWord = float16::ConvertFloatTo16bitsNonDefault<0>(input: input.start);
    range = input.range;
  }
  else
  {
    v3.rawWord = float16::ConvertFloatTo16bitsNonDefault<0>(input: 1.0);
    range = 0.0;
  }
  this->volume.start.m_storage = v3;
  this->volume.range.m_storage.rawWord = float16::ConvertFloatTo16bitsNonDefault<0>(input: range);
}

} // namespace SoundEmitterSystem

// ============================================================
// Overlay from vsoundedit (Missing functions)
// ============================================================
namespace vsoundedit {

//------------------------------------------------------------------------------
// Address: 0x00412B50
// Name: enum soundlevel_t TextToSoundLevel(char const __near *)
// Source: json
//------------------------------------------------------------------------------
soundlevel_t __cdecl TextToSoundLevel(const char *key)
{
  soundlevel_t result; // eax
  SoundLevelLookup *v2; // esi
  int v3; // eax
  int v4; // eax

  if ( key == nullptr )
    return SNDLVL_NORM;
  v2 = g_pSoundLevels;
  do
  {
    if ( V_strcasecmp(s1: key, s2: v2->name) == 0 )
      return v2->level;
    ++v2;
  }
  while ( (int)v2 < (int)&vec2_invalid_9 );
  v3 = _V_strlen(str: "SNDLVL_");
  if ( V_strnicmp(s1: key, s2: "SNDLVL_", n: v3) != 0
    || (v4 = _V_strlen(str: "SNDLVL_"), (unsigned int)((result = atoi(nptr: &key[v4])) - 1) > 0xB3) )
  {
    DevMsg(a1: "CSoundEmitterSystem:  Unknown sound level %s\n", key);
    return SNDLVL_NORM;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00412BE0
// Name: int TextToChannel(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl TextToChannel(const char *name)
{
  int v2; // esi

  if ( name == nullptr )
    return 0;
  if ( V_strncasecmp(s1: name, s2: "chan_", n: 5) != 0 )
    return atoi(nptr: name);
  v2 = 0;
  while ( V_strcasecmp(s1: name, s2: g_pChannelNames[v2].name) != 0 )
  {
    if ( ++v2 >= 7 )
    {
      DevMsg(a1: "CSoundEmitterSystem:  Warning, unknown channel type in sounds.txt (%s)\n", name);
      return 0;
    }
  }
  return g_pChannelNames[v2].channel;
}

//------------------------------------------------------------------------------
// Address: 0x00412C50
// Name: char const __near * SoundLevelToString(enum soundlevel_t)
// Source: json
//------------------------------------------------------------------------------
char *__cdecl SoundLevelToString(soundlevel_t level)
{
  SoundLevelLookup *v1; // eax

  v1 = g_pSoundLevels;
  while ( v1->level != level )
  {
    if ( (int)++v1 >= (int)&vec2_invalid_9 )
    {
      V_snprintf(pDest: sz, maxLen: 32, pFormat: "%i", level);
      return sz;
    }
  }
  return (char *)v1->name;
}

//------------------------------------------------------------------------------
// Address: 0x00412C90
// Name: char const __near * ChannelToString(int)
// Source: json
//------------------------------------------------------------------------------
char *__cdecl ChannelToString(int channel)
{
  SoundChannels *v1; // eax

  v1 = g_pChannelNames;
  while ( v1->channel != channel )
  {
    if ( (int)++v1 >= (int)g_pVolumeLevels )
    {
      V_snprintf(pDest: sz_0, maxLen: 32, pFormat: "%i", channel);
      return sz_0;
    }
  }
  return (char *)v1->name;
}

} // namespace vsoundedit

// ============================================================
// Overlay from client (Missing functions)
// ============================================================
namespace client {

//------------------------------------------------------------------------------
// Address: 0x1016B2E0
// Name: public: struct SoundFile const __near * CSoundParametersInternal::GetSoundNames(void)const
// Source: json
//------------------------------------------------------------------------------
SoundFile *__thiscall CSoundParametersInternal::GetSoundNames(CSoundParametersInternal *this)
{
  SoundFile *result; // eax

  result = (SoundFile *)this;
  if ( this->m_nSoundNames != 1 )
    return this->m_pSoundNames;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1016ECD0
// Name: enum soundlevel_t TextToSoundLevel(char const __near *)
// Source: json
//------------------------------------------------------------------------------
soundlevel_t __cdecl TextToSoundLevel(const char *key)
{
  soundlevel_t result; // eax
  SoundLevelLookup *v2; // esi
  int v3; // eax
  int v4; // eax

  if ( key == nullptr )
    return SNDLVL_NORM;
  v2 = g_pSoundLevels;
  do
  {
    if ( V_strcasecmp(s1: key, s2: v2->name) == 0 )
      return v2->level;
    ++v2;
  }
  while ( (int)v2 < (int)&s_CatmullRom );
  v3 = _V_strlen(str: "SNDLVL_");
  if ( V_strnicmp(s1: key, s2: "SNDLVL_", n: v3) != 0
    || (v4 = _V_strlen(str: "SNDLVL_"), (unsigned int)((result = atoi(nptr: &key[v4])) - 1) > 0xB3) )
  {
    DevMsg(a1: "CSoundEmitterSystem:  Unknown sound level %s\n", key);
    return SNDLVL_NORM;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1016ED60
// Name: public: CSoundParametersInternal::~CSoundParametersInternal(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSoundParametersInternal::~CSoundParametersInternal(CSoundParametersInternal *this)
{
  KeyValues *m_pOperatorsKV; // ecx

  if ( this->m_nSoundNames > 1u )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_pSoundNames);
  if ( this->m_nConvertedNames > 1u )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_pConvertedNames);
  m_pOperatorsKV = this->m_pOperatorsKV;
  if ( m_pOperatorsKV != nullptr )
  {
    KeyValues::deleteThis(this: m_pOperatorsKV);
    this->m_pOperatorsKV = nullptr;
  }
  this->m_pConvertedNames = nullptr;
  this->m_pSoundNames = nullptr;
  *(_DWORD *)&this->m_nSoundNames = 0;
}

//------------------------------------------------------------------------------
// Address: 0x1016EDC0
// Name: public: void CSoundParametersInternal::SetOperatorsKV(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSoundParametersInternal::SetOperatorsKV(CSoundParametersInternal *this, KeyValues *src)
{
  KeyValues *m_pOperatorsKV; // ecx
  KeyValues *v4; // eax
  KeyValues *v5; // eax

  m_pOperatorsKV = this->m_pOperatorsKV;
  if ( m_pOperatorsKV != nullptr )
    KeyValues::deleteThis(this: m_pOperatorsKV);
  this->m_pOperatorsKV = nullptr;
  v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v4 != nullptr )
  {
    v5 = KeyValues::KeyValues(this: v4, setName: "Operators");
    this->m_pOperatorsKV = v5;
    KeyValues::CopySubkeys(this: src, pParent: v5);
  }
  else
  {
    this->m_pOperatorsKV = nullptr;
    KeyValues::CopySubkeys(this: src, pParent: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1016EE20
// Name: public: void CSoundParametersInternal::CopyFrom(struct CSoundParametersInternal const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSoundParametersInternal::CopyFrom(CSoundParametersInternal *this, const CSoundParametersInternal *src)
{
  char v3; // dl
  unsigned int m_nSoundNames; // eax
  SoundFile *v5; // eax
  unsigned int v6; // ecx
  unsigned int m_nConvertedNames; // eax
  SoundFile *v8; // eax
  unsigned int v9; // ecx

  if ( this->m_nSoundNames > 1u )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_pSoundNames);
  if ( this->m_nConvertedNames > 1u )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_pConvertedNames);
  this->channel = src->channel;
  this->volume = src->volume;
  this->pitch = src->pitch;
  v3 = *((_BYTE *)this + 28);
  this->soundlevel = src->soundlevel;
  this->delay_msec = src->delay_msec;
  *((_BYTE *)this + 28) ^= (*((_BYTE *)src + 28) ^ v3) & 1;
  m_nSoundNames = src->m_nSoundNames;
  this->m_nSoundNames = m_nSoundNames;
  if ( (_WORD)m_nSoundNames != 0 )
  {
    if ( m_nSoundNames <= 1 )
    {
      this->m_pSoundNames = src->m_pSoundNames;
    }
    else
    {
      v5 = (SoundFile *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 4 * m_nSoundNames);
      v6 = 4 * this->m_nSoundNames;
      this->m_pSoundNames = v5;
      memcpy(dst: (unsigned __int8 *)v5, src: (unsigned __int8 *)src->m_pSoundNames, count: v6);
    }
  }
  else
  {
    this->m_pSoundNames = nullptr;
  }
  m_nConvertedNames = src->m_nConvertedNames;
  this->m_nConvertedNames = m_nConvertedNames;
  if ( (_WORD)m_nConvertedNames != 0 )
  {
    if ( m_nConvertedNames <= 1 )
    {
      this->m_pConvertedNames = src->m_pConvertedNames;
    }
    else
    {
      v8 = (SoundFile *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 4 * m_nConvertedNames);
      v9 = 4 * this->m_nConvertedNames;
      this->m_pConvertedNames = v8;
      memcpy(dst: (unsigned __int8 *)v8, src: (unsigned __int8 *)src->m_pConvertedNames, count: v9);
    }
  }
  else
  {
    this->m_pConvertedNames = nullptr;
  }
  if ( src->m_pOperatorsKV != nullptr )
    CSoundParametersInternal::SetOperatorsKV(this, src: src->m_pOperatorsKV);
  *((_BYTE *)this + 28) ^= (*((_BYTE *)src + 28) ^ *((_BYTE *)this + 28)) & 2;
  *((_BYTE *)this + 28) ^= (*((_BYTE *)this + 28) ^ *((_BYTE *)src + 28)) & 4;
}

//------------------------------------------------------------------------------
// Address: 0x1016EF60
// Name: public: bool CSoundParametersInternal::operator==(struct CSoundParametersInternal const __near &)const
// Source: json
//------------------------------------------------------------------------------
char __thiscall CSoundParametersInternal::operator==(CSoundParametersInternal *this, CSoundParametersInternal *other)
{
  CSoundParametersInternal *v3; // ecx
  int v5; // esi
  SoundFile *SoundNames; // ebx
  int c; // [esp+4h] [ebp-4h]

  v3 = other;
  if ( this == other )
    return 1;
  if ( this->channel != other->channel
    || *(_DWORD *)&this->volume != *(_DWORD *)&other->volume
    || other->pitch.start != this->pitch.start
    || other->pitch.range != this->pitch.range
    || *(_DWORD *)&this->soundlevel != *(_DWORD *)&other->soundlevel
    || this->delay_msec != other->delay_msec
    || ((*((_BYTE *)this + 28) ^ *((_BYTE *)other + 28)) & 1) != 0
    || this->m_nSoundNames != other->m_nSoundNames )
  {
    return 0;
  }
  v5 = 0;
  c = this->m_nSoundNames;
  if ( this->m_nSoundNames == 0 )
    return 1;
  while ( 1 )
  {
    SoundNames = CSoundParametersInternal::GetSoundNames(this: v3);
    if ( CSoundParametersInternal::GetSoundNames(this)[v5].symbol.m_Id != SoundNames[v5].symbol.m_Id )
      break;
    if ( ++v5 >= c )
      return 1;
    v3 = other;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1016F020
// Name: public: void CSoundParametersInternal::SoundLevelFromString(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSoundParametersInternal::SoundLevelFromString(CSoundParametersInternal *this, char *sz)
{
  interval_t Interval; // [esp+8h] [ebp-8h]

  if ( V_strncasecmp(s1: sz, s2: "SNDLVL_", n: 7) != 0 )
  {
    Interval = ReadInterval(pString: sz);
    this->soundlevel.start = (int)Interval.start;
    this->soundlevel.range = (int)Interval.range;
  }
  else
  {
    this->soundlevel.start = TextToSoundLevel(key: sz);
    this->soundlevel.range = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1016F090
// Name: public: CSoundParametersInternal::CSoundParametersInternal(void)
// Source: json
//------------------------------------------------------------------------------
CSoundParametersInternal *__thiscall CSoundParametersInternal::CSoundParametersInternal(CSoundParametersInternal *this)
{
  this->m_pSoundNames = nullptr;
  this->m_pConvertedNames = nullptr;
  *(_DWORD *)&this->m_nSoundNames = 0;
  this->channel = 0;
  this->volume.start.m_storage.rawWord = float16::ConvertFloatTo16bitsNonDefault<0>(input: 1.0);
  this->volume.range.m_storage.rawWord = float16::ConvertFloatTo16bitsNonDefault<0>(input: 0.0);
  *((_BYTE *)this + 28) &= 0xF8u;
  this->m_pOperatorsKV = nullptr;
  this->m_pGameData = nullptr;
  this->pitch = (sound_interval_t<unsigned char>)100;
  this->soundlevel = (sound_interval_t<unsigned short>)75;
  *(_DWORD *)&this->delay_msec = 0x10000;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1016F100
// Name: public: void CSoundParametersInternal::VolumeFromString(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSoundParametersInternal::VolumeFromString(CSoundParametersInternal *this, char *sz)
{
  float16::float16bits v3; // ax
  float range; // xmm0_4
  interval_t input; // [esp+Ch] [ebp-8h]

  if ( V_strcasecmp(s1: sz, s2: "VOL_NORM") != 0 )
  {
    input = ReadInterval(pString: sz);
    v3.rawWord = float16::ConvertFloatTo16bitsNonDefault<0>(input: input.start);
    range = input.range;
  }
  else
  {
    v3.rawWord = float16::ConvertFloatTo16bitsNonDefault<0>(input: 1.0);
    range = 0.0;
  }
  this->volume.start.m_storage = v3;
  this->volume.range.m_storage.rawWord = float16::ConvertFloatTo16bitsNonDefault<0>(input: range);
}

} // namespace client

// ============================================================
// Overlay from server (Missing functions)
// ============================================================
namespace server {

//------------------------------------------------------------------------------
// Address: 0x1021F4A0
// Name: public: static float float16::Convert16bitFloatTo32bits(unsigned short)
// Source: json
//------------------------------------------------------------------------------
double __cdecl float16::Convert16bitFloatTo32bits(unsigned int input)
{
  int v1; // ecx
  float v3; // xmm0_4

  v1 = (input >> 10) & 0x1F;
  if ( v1 == 31 )
  {
    if ( (input & 0x3FF) != 0 )
    {
      return 0.0;
    }
    else if ( (input & 0x8000) != 0 )
    {
      return -1.0 * 65504.0;
    }
    else
    {
      return 1.0 * 65504.0;
    }
  }
  else if ( (_WORD)v1 != 0 || (input & 0x3FF) == 0 )
  {
    return COERCE_FLOAT((input & 0x3FF
                       | (8
                        * (input & 0x8000
                         | ((((((unsigned __int16)input >> 10) & 0x1F) + 112)
                           * ((((unsigned __int16)input >> 10) & 0x1F) != 0)) << 7)))) << 13);
  }
  else
  {
    if ( (input & 0x8000) != 0 )
      v3 = -1.0;
    else
      v3 = 1.0;
    return (float)((float)(v3 * (float)((float)(input & 0x3FF) * 0.0009765625)) * 0.000061035156);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1021F5A0
// Name: public: static unsigned short float16::ConvertFloatTo16bitsNonDefault<0>(float)
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __cdecl float16::ConvertFloatTo16bitsNonDefault<0>(float input)
{
  float v1; // xmm0_4
  int v2; // xmm1_4
  int v3; // eax
  int v4; // ecx
  int v5; // ecx
  float16::float16bits output; // [esp+8h] [ebp+8h]

  v1 = input;
  v2 = 1199562752;
  if ( input > 65504.0 || (v2 = -947920896, input < -65504.0) )
    v1 = *(float *)&v2;
  v3 = LOWORD(v1) & 0x7FFF | (LODWORD(v1) >> 31 << 15);
  v4 = (unsigned __int8)(LODWORD(v1) >> 23);
  output.rawWord = LOWORD(v1) & 0x7FFF | (LODWORD(v1) >> 31 << 15);
  if ( (unsigned __int8)(LODWORD(v1) >> 23) != 0 )
  {
    if ( v4 == 255 )
    {
      if ( (LODWORD(v1) & 0x7FFFFF) != 0 )
        LOWORD(v3) = LODWORD(v1) >> 31 << 15;
      else
        LOWORD(v3) = LOWORD(v1) & 0x7BFF | (LODWORD(v1) >> 31 << 15) | 0x7BFF;
    }
    else
    {
      v5 = v4 - 127;
      if ( v5 < -24 )
      {
        LOWORD(v3) = LODWORD(v1) >> 31 << 15;
        output.rawWord = v3;
      }
      if ( v5 >= -14 )
      {
        if ( v5 <= 15 )
          return (((_WORD)v5 + 15) << 10) & 0x7C00 | (LODWORD(v1) >> 13) & 0x3FF | output.rawWord & 0x8000;
        else
          LOWORD(v3) = output.rawWord & 0x8000 | 0x7BFF;
      }
      else
      {
        LOWORD(v3) = v3 & 0x83FF;
        if ( (unsigned int)(-14 - v5 - 1) <= 9 )
          LOWORD(v3) = (v3 ^ ((1 << (10 - (-14 - v5))) + ((LODWORD(v1) & 0x7FFFFFu) >> (-14 - v5 + 13)))) & 0x3FF ^ v3;
      }
    }
  }
  else
  {
    LOWORD(v3) = LODWORD(v1) >> 31 << 15;
  }
  return v3;
}

} // namespace server
