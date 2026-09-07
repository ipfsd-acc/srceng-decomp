// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/scenemanager/snd_audio_source.cpp
// Functions: 3
// ============================================================

#include "utils\scenemanager\snd_audio_source.h"

//------------------------------------------------------------------------------
// Address: 0x00402570
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
// Address: 0x00402590
// Name: public: virtual CAudioSource::~CAudioSource(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAudioSource::~CAudioSource(CAudioSource *this)
{
  CAudioMixer *i; // eax

  this->__vftable = (CAudioSource_vtbl *)&CAudioSource::`vftable';
  for ( i = sound->FindMixer(this: sound, a2: this); i != nullptr; i = sound->FindMixer(this: sound, a2: this) )
    sound->StopSound(this: sound, a2: i);
}

//------------------------------------------------------------------------------
// Address: 0x00402610
// Name: public: CAudioSource::CAudioSource(void)
// Source: json
//------------------------------------------------------------------------------
CAudioSource *__thiscall CAudioSource::CAudioSource(CAudioSource *this)
{
  this->__vftable = (CAudioSource_vtbl *)&CAudioSource::`vftable';
  return this;
}
