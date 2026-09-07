// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/hlfaceposer/snd_audio_source.cpp
// Functions: 4
// ============================================================

#include "utils\hlfaceposer\snd_audio_source.h"

//------------------------------------------------------------------------------
// Address: 0x00401000
// Name: class CAudioSource __near * AudioSource_Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CAudioSource *__cdecl AudioSource_Create(const char *pName)
{
  if ( pName == nullptr || *pName == 42 )
    return nullptr;
  else
    return Audio_CreateMemoryWave(pName);
}

//------------------------------------------------------------------------------
// Address: 0x00401020
// Name: public: virtual CAudioSource::~CAudioSource(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAudioSource::~CAudioSource(CAudioSource *this)
{
  CAudioMixer *i; // eax

  this->__vftable = (CAudioSource_vtbl *)&CAudioSource::`vftable';
  for ( i = sound->FindMixer(this: sound, a2: this); i != nullptr; i = sound->FindMixer(this: sound, a2: this) )
    sound->StopSound(this: sound, a2: i);
  sound->EnsureNoModelReferences(this: sound, a2: this);
}

//------------------------------------------------------------------------------
// Address: 0x004010A0
// Name: public: CAudioSource::CAudioSource(void)
// Source: json
//------------------------------------------------------------------------------
CAudioSource *__thiscall CAudioSource::CAudioSource(CAudioSource *this)
{
  this->__vftable = (CAudioSource_vtbl *)&CAudioSource::`vftable';
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00464DA0
// Name: public: virtual class CSentence __near * CAudioSource::GetSentence(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CAudioSource::GetSentence(ConVar *this)
{
  return 0;
}
