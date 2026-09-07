// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: engine/audio/private/snd_win.cpp
// Functions: 4
// ============================================================

#include "engine\audio\private\snd_win.h"

//------------------------------------------------------------------------------
// Address: 0x10044FF0
// Name: void S_BlockSound(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl S_BlockSound()
{
  if ( g_AudioDevice != nullptr )
    g_AudioDevice->Pause(this: g_AudioDevice);
}

//------------------------------------------------------------------------------
// Address: 0x10045010
// Name: void S_UnblockSound(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl S_UnblockSound()
{
  if ( g_AudioDevice != nullptr )
    g_AudioDevice->UnPause(this: g_AudioDevice);
}

//------------------------------------------------------------------------------
// Address: 0x10045030
// Name: public: static class IAudioDevice __near * IAudioDevice::AutoDetectInit(bool)
// Source: json
//------------------------------------------------------------------------------
IAudioDevice *__cdecl IAudioDevice::AutoDetectInit(bool waveOnly)
{
  IAudioDevice *result; // eax

  if ( waveOnly || !snd_firsttime || (result = Audio_CreateDirectSoundDevice()) == nullptr )
    result = Audio_CreateWaveDevice();
  snd_firsttime = false;
  if ( result == nullptr )
    return Audio_GetNullDevice();
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10045070
// Name: void SNDDMA_Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SNDDMA_Shutdown()
{
  if ( g_AudioDevice != Audio_GetNullDevice() )
  {
    if ( g_AudioDevice != nullptr )
    {
      ((void (*)(void))g_AudioDevice->Shutdown)();
      if ( g_AudioDevice != nullptr )
        ((void (__thiscall *)(IAudioDevice *, int))g_AudioDevice->dtr_IAudioDevice)(a1: g_AudioDevice, a2: 1);
    }
    g_AudioDevice = Audio_GetNullDevice();
  }
}

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x10044D00
// Name: void S_BlockSound(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl S_BlockSound()
{
  if ( g_AudioDevice != nullptr )
    g_AudioDevice->Pause(this: g_AudioDevice);
}

//------------------------------------------------------------------------------
// Address: 0x10044D20
// Name: void S_UnblockSound(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl S_UnblockSound()
{
  if ( g_AudioDevice != nullptr )
    g_AudioDevice->UnPause(this: g_AudioDevice);
}

//------------------------------------------------------------------------------
// Address: 0x10044D40
// Name: public: static class IAudioDevice __near * IAudioDevice::AutoDetectInit(bool)
// Source: json
//------------------------------------------------------------------------------
IAudioDevice *__cdecl IAudioDevice::AutoDetectInit(bool waveOnly)
{
  IAudioDevice *result; // eax

  if ( waveOnly || !snd_firsttime || (result = Audio_CreateDirectSoundDevice()) == nullptr )
    result = Audio_CreateWaveDevice();
  snd_firsttime = false;
  if ( result == nullptr )
    return Audio_GetNullDevice();
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10044D80
// Name: void SNDDMA_Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SNDDMA_Shutdown()
{
  if ( g_AudioDevice != Audio_GetNullDevice() )
  {
    if ( g_AudioDevice != nullptr )
    {
      ((void (*)(void))g_AudioDevice->Shutdown)();
      if ( g_AudioDevice != nullptr )
        ((void (__thiscall *)(IAudioDevice *, int))g_AudioDevice->dtr_IAudioDevice)(a1: g_AudioDevice, a2: 1);
    }
    g_AudioDevice = Audio_GetNullDevice();
  }
}

} // namespace engine_xlsp
