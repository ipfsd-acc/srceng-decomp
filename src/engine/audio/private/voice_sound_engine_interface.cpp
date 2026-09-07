// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: engine/audio/private/voice_sound_engine_interface.cpp
// Functions: 16
// ============================================================

#include "engine\audio\private\voice_sound_engine_interface.h"

//------------------------------------------------------------------------------
// Address: 0x100575F0
// Name: public: virtual char const __near * CVoiceSfx::getname(char __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CVoiceSfx::getname(CVoiceSfx *this, char *pBuf, unsigned int bufLen)
{
  V_strncpy(pDest: pBuf, pSrc: "?VoiceSfx", maxLen: bufLen);
  return pBuf;
}

//------------------------------------------------------------------------------
// Address: 0x10057610
// Name: public: CAudioSourceVoice::CAudioSourceVoice(class CSfxTable __near *,int)
// Source: json
//------------------------------------------------------------------------------
CAudioSourceVoice *__thiscall CAudioSourceVoice::CAudioSourceVoice(
        CAudioSourceVoice *this,
        CSfxTable *pSfx,
        int iChannel)
{
  tWAVEFORMATEX tmp; // [esp+4h] [ebp-14h] BYREF

  CAudioSourceWave::CAudioSourceWave(this, pSfx);
  this->__vftable = (CAudioSourceVoice_vtbl *)&CAudioSourceVoice::`vftable';
  this->m_iChannel = iChannel;
  this->m_refCount = 0;
  *(_DWORD *)&tmp.wFormatTag = *(_DWORD *)&g_VoiceSampleFormat.wFormatTag;
  *(_DWORD *)&tmp.nBlockAlign = *(_DWORD *)&g_VoiceSampleFormat.nBlockAlign;
  tmp.cbSize = g_VoiceSampleFormat.cbSize;
  tmp.nSamplesPerSec = Voice_SamplesPerSec();
  tmp.nAvgBytesPerSec = Voice_AvgBytesPerSec();
  CAudioSourceWave::Init(this, pHeaderBuffer: (const char *)&tmp, headerSize: 18);
  this->m_sampleCount = tmp.nSamplesPerSec;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10057690
// Name: public: virtual int CAudioSourceVoice::GetOutputData(void __near * __near *,__int64,int,char __near * const)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CAudioSourceVoice::GetOutputData(
        CAudioSourceVoice *this,
        void **pData,
        __int64 samplePosition,
        int sampleCount,
        char *copyBuf)
{
  int result; // eax

  result = Voice_GetOutputData(
             iChannel: this->m_iChannel,
             copyBufBytes: copyBuf,
             copyBufSize: 4096,
             samplePosition,
             sampleCount);
  if ( result >= sampleCount )
  {
    *pData = copyBuf;
  }
  else
  {
    if ( copyBuf != nullptr )
      memset(dst: (unsigned __int8 *)&copyBuf[result], value: 0, count: 2 * (sampleCount - result));
    *pData = copyBuf;
    return sampleCount;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100576F0
// Name: public: virtual int CAudioSourceVoice::SampleRate(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CAudioSourceVoice::SampleRate(CAudioSourceVoice *this)
{
  return 11025;
}

//------------------------------------------------------------------------------
// Address: 0x10057700
// Name: public: virtual void CAudioSourceVoice::ReferenceAdd(class CAudioMixer __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAudioSourceVoice::ReferenceAdd(CAudioSourceVoice *this, CAudioMixer *pMixer)
{
  ++this->m_refCount;
}

//------------------------------------------------------------------------------
// Address: 0x10057710
// Name: public: virtual void CAudioSourceVoice::ReferenceRemove(class CAudioMixer __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAudioSourceVoice::ReferenceRemove(CAudioSourceVoice *this, CAudioMixer *pMixer)
{
  if ( --this->m_refCount <= 0 )
    ((void (__thiscall *)(CAudioSourceVoice *, int))this->dtr_CAudioSource)(a1: this, a2: 1);
}

//------------------------------------------------------------------------------
// Address: 0x10057730
// Name: public: virtual bool CAudioSourceVoice::CanDelete(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CAudioSourceVoice::CanDelete(CAudioSourceVoice *this)
{
  return this->m_refCount == 0;
}

//------------------------------------------------------------------------------
// Address: 0x10057740
// Name: bool VoiceSE_Init(void)
// Source: json
//------------------------------------------------------------------------------
char __cdecl VoiceSE_Init()
{
  if ( !snd_initialized )
    return 0;
  g_SND_VoiceOverdriveInt = 256;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10057760
// Name: void VoiceSE_Term(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl VoiceSE_Term()
{
  g_SND_VoiceOverdriveInt = 256;
}

//------------------------------------------------------------------------------
// Address: 0x10057770
// Name: void VoiceSE_EndChannel(int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl VoiceSE_EndChannel(int iChannel, int iEntity)
{
  S_StopSound(soundsource: iEntity, entchannel: iChannel + 7);
  (&g_CVoiceSfx.pSource)[7 * iChannel] = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x100577A0
// Name: void VoiceSE_StartOverdrive(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl VoiceSE_StartOverdrive()
{
  g_bVoiceOverdriveOn = true;
}

//------------------------------------------------------------------------------
// Address: 0x100577B0
// Name: void VoiceSE_EndOverdrive(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl VoiceSE_EndOverdrive()
{
  g_bVoiceOverdriveOn = false;
}

//------------------------------------------------------------------------------
// Address: 0x100577C0
// Name: class CAudioSource __near * Voice_SetupAudioSource(int,int)
// Source: json
//------------------------------------------------------------------------------
CAudioSourceVoice *__cdecl Voice_SetupAudioSource(int soundsource, int entchannel)
{
  CAudioSourceVoice *v2; // eax

  if ( (unsigned int)(entchannel - 7) <= 4 && (v2 = (CAudioSourceVoice *)MemAlloc_Alloc(nSize: 0x60u)) != nullptr )
    return CAudioSourceVoice::CAudioSourceVoice(this: v2, pSfx: &g_CVoiceSfx + entchannel - 7, iChannel: entchannel - 7);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10057840
// Name: public: virtual class CAudioMixer __near * CAudioSourceVoice::CreateMixer(int,int,bool,enum SoundError __near &)
// Source: json
//------------------------------------------------------------------------------
CAudioMixer *__thiscall CAudioSourceVoice::CreateMixer(
        CAudioSourceVoice *this,
        int initialStreamPosition,
        int skipInitialSamples,
        bool bUpdateDelayForChoreo,
        SoundError *soundError)
{
  IWaveData *v6; // esi
  CAudioMixer *WaveMixer; // edi

  *soundError = SE_OK;
  v6 = (IWaveData *)MemAlloc_Alloc(nSize: 8u);
  if ( v6 != nullptr )
  {
    v6->__vftable = (IWaveData_vtbl *)&CAudioSourceVoice::CWaveDataVoice::`vftable';
    v6[1].__vftable = (IWaveData_vtbl *)this;
    WaveMixer = CreateWaveMixer(
                  data: v6,
                  format: 1,
                  channels: 1,
                  bits: 16,
                  initialStreamPosition,
                  skipInitialSamples,
                  bUpdateDelayForChoreo);
    if ( WaveMixer != nullptr )
    {
      this->ReferenceAdd(this, a2: WaveMixer);
      return WaveMixer;
    }
    else
    {
      ((void (__thiscall *)(IWaveData *, int))v6->dtr_IWaveData)(a1: v6, a2: 1);
      *soundError = SE_CANT_CREATE_MIXER;
      return nullptr;
    }
  }
  else
  {
    *soundError = SE_CANT_CREATE_MIXER;
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100578D0
// Name: void VoiceSE_Idle(float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl VoiceSE_Idle(float frametime)
{
  float v1; // xmm0_4
  float m_fValue; // xmm1_4
  bool v3; // cc

  g_SND_VoiceOverdriveInt = 256;
  if ( g_bVoiceOverdriveOn )
  {
    v1 = g_VoiceOverdriveDuration + frametime;
    m_fValue = voice_overdrivefadetime.m_pParent->m_Value.m_fValue;
    v3 = m_fValue <= (float)(g_VoiceOverdriveDuration + frametime);
  }
  else
  {
    m_fValue = 0.0;
    if ( g_VoiceOverdriveDuration == 0.0 )
      return;
    v1 = g_VoiceOverdriveDuration - frametime;
    v3 = (float)(g_VoiceOverdriveDuration - frametime) <= 0.0;
  }
  if ( v3 )
    g_VoiceOverdriveDuration = m_fValue;
  else
    g_VoiceOverdriveDuration = v1;
  g_SND_VoiceOverdriveInt = (int)(256.0
                                / ((voice_overdrive.m_pParent->m_Value.m_fValue - 1.0)
                                 * (0.5
                                  - cos(
                                      g_VoiceOverdriveDuration
                                    / voice_overdrivefadetime.m_pParent->m_Value.m_fValue
                                    * 3.1415926535)
                                  * 0.5)
                                 + 1.0));
}

//------------------------------------------------------------------------------
// Address: 0x10057970
// Name: int VoiceSE_StartChannel(int,int,bool,int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl VoiceSE_StartChannel(int iChannel, int iEntity, bool bProximity, int nViewEntityIndex)
{
  char v4; // al
  StartSoundParams_t params; // [esp+0h] [ebp-64h] BYREF

  params.speakerentity = -1;
  params.m_nQueuedGUID = -1;
  params.m_nSoundScriptHandle = -1;
  v4 = *((_BYTE *)&params + 96) & 0xC0 | 2;
  params.delay = 0.0;
  params.opStackElapsedTime = 0.0;
  params.opStackElapsedStopTime = 0.0;
  memset(&params.origin, 0, 24);
  (&g_CVoiceSfx.pSource)[7 * iChannel] = nullptr;
  params.pSfx = &g_CVoiceSfx + iChannel;
  params.userdata = 0;
  params.initialStreamPosition = 0;
  params.skipInitialSamples = 0;
  params.m_pSoundEntryName = nullptr;
  params.m_pOperatorsKV = nullptr;
  *((_BYTE *)&params + 96) = v4;
  params.entchannel = iChannel + 7;
  params.fvol = 1.0;
  params.flags = 0;
  params.pitch = 100;
  if ( bProximity )
  {
    *((_BYTE *)&params + 96) = v4 | 2;
    params.soundlevel = SNDLVL_80dB;
    params.soundsource = iEntity;
  }
  else
  {
    params.soundlevel = SNDLVL_IDLE;
    params.soundsource = nViewEntityIndex;
  }
  return S_StartSound(&params);
}

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x100573B0
// Name: public: virtual char const __near * CVoiceSfx::getname(char __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CVoiceSfx::getname(CVoiceSfx *this, char *pBuf, unsigned int bufLen)
{
  V_strncpy(pDest: pBuf, pSrc: "?VoiceSfx", maxLen: bufLen);
  return pBuf;
}

//------------------------------------------------------------------------------
// Address: 0x100573D0
// Name: public: CAudioSourceVoice::CAudioSourceVoice(class CSfxTable __near *,int)
// Source: json
//------------------------------------------------------------------------------
CAudioSourceVoice *__thiscall CAudioSourceVoice::CAudioSourceVoice(
        CAudioSourceVoice *this,
        CSfxTable *pSfx,
        int iChannel)
{
  tWAVEFORMATEX tmp; // [esp+4h] [ebp-14h] BYREF

  CAudioSourceWave::CAudioSourceWave(this, pSfx);
  this->__vftable = (CAudioSourceVoice_vtbl *)&CAudioSourceVoice::`vftable';
  this->m_iChannel = iChannel;
  this->m_refCount = 0;
  *(_DWORD *)&tmp.wFormatTag = *(_DWORD *)&g_VoiceSampleFormat.wFormatTag;
  *(_DWORD *)&tmp.nBlockAlign = *(_DWORD *)&g_VoiceSampleFormat.nBlockAlign;
  tmp.cbSize = g_VoiceSampleFormat.cbSize;
  tmp.nSamplesPerSec = Voice_SamplesPerSec();
  tmp.nAvgBytesPerSec = Voice_AvgBytesPerSec();
  CAudioSourceWave::Init(this, pHeaderBuffer: (char *)&tmp, headerSize: 18);
  this->m_sampleCount = tmp.nSamplesPerSec;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10057470
// Name: public: virtual int CAudioSourceVoice::GetOutputData(void __near * __near *,__int64,int,char __near * const)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CAudioSourceVoice::GetOutputData(
        CAudioSourceVoice *this,
        void **pData,
        __int64 samplePosition,
        int sampleCount,
        char *copyBuf)
{
  int result; // eax

  result = Voice_GetOutputData(
             iChannel: this->m_iChannel,
             copyBufBytes: (vgui::PropertyPage *)copyBuf,
             copyBufSize: 4096,
             samplePosition,
             sampleCount);
  if ( result >= sampleCount )
  {
    *pData = copyBuf;
  }
  else
  {
    if ( copyBuf != nullptr )
      memset(dst: (unsigned __int8 *)&copyBuf[result], value: 0, count: 2 * (sampleCount - result));
    *pData = copyBuf;
    return sampleCount;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100574D0
// Name: public: virtual int CAudioSourceVoice::SampleRate(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CAudioSourceVoice::SampleRate(CAudioSourceVoice *this)
{
  return 11025;
}

//------------------------------------------------------------------------------
// Address: 0x100574E0
// Name: public: virtual void CAudioSourceVoice::ReferenceAdd(class CAudioMixer __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAudioSourceVoice::ReferenceAdd(CAudioSourceVoice *this, CAudioMixer *pMixer)
{
  ++this->m_refCount;
}

//------------------------------------------------------------------------------
// Address: 0x100574F0
// Name: public: virtual void CAudioSourceVoice::ReferenceRemove(class CAudioMixer __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAudioSourceVoice::ReferenceRemove(CAudioSourceVoice *this, CAudioMixer *pMixer)
{
  if ( --this->m_refCount <= 0 )
    ((void (__thiscall *)(CAudioSourceVoice *, int))this->dtr_CAudioSource)(a1: this, a2: 1);
}

//------------------------------------------------------------------------------
// Address: 0x10057510
// Name: public: virtual bool CAudioSourceVoice::CanDelete(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CAudioSourceVoice::CanDelete(CAudioSourceVoice *this)
{
  return this->m_refCount == 0;
}

//------------------------------------------------------------------------------
// Address: 0x10057520
// Name: bool VoiceSE_Init(void)
// Source: json
//------------------------------------------------------------------------------
char __cdecl VoiceSE_Init()
{
  if ( !snd_initialized )
    return 0;
  g_SND_VoiceOverdriveInt = 256;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10057540
// Name: void VoiceSE_Term(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl VoiceSE_Term()
{
  g_SND_VoiceOverdriveInt = 256;
}

//------------------------------------------------------------------------------
// Address: 0x10057550
// Name: void VoiceSE_EndChannel(int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl VoiceSE_EndChannel(int iChannel, int iEntity)
{
  S_StopSound(soundsource: iEntity, entchannel: iChannel + 7);
  (&g_CVoiceSfx.pSource)[7 * iChannel] = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10057580
// Name: void VoiceSE_StartOverdrive(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl VoiceSE_StartOverdrive()
{
  g_bVoiceOverdriveOn = true;
}

//------------------------------------------------------------------------------
// Address: 0x10057590
// Name: void VoiceSE_EndOverdrive(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl VoiceSE_EndOverdrive()
{
  g_bVoiceOverdriveOn = false;
}

//------------------------------------------------------------------------------
// Address: 0x100575A0
// Name: class CAudioSource __near * Voice_SetupAudioSource(int,int)
// Source: json
//------------------------------------------------------------------------------
CAudioSourceVoice *__cdecl Voice_SetupAudioSource(int soundsource, int entchannel)
{
  CAudioSourceVoice *v2; // eax

  if ( (unsigned int)(entchannel - 7) <= 4 && (v2 = (CAudioSourceVoice *)MemAlloc_Alloc(nSize: 0x60u)) != nullptr )
    return CAudioSourceVoice::CAudioSourceVoice(this: v2, pSfx: &g_CVoiceSfx + entchannel - 7, iChannel: entchannel - 7);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10057620
// Name: public: virtual class CAudioMixer __near * CAudioSourceVoice::CreateMixer(int,int,bool,enum SoundError __near &)
// Source: json
//------------------------------------------------------------------------------
CAudioMixerWave8Mono *__thiscall CAudioSourceVoice::CreateMixer(
        CAudioSourceVoice *this,
        int initialStreamPosition,
        int skipInitialSamples,
        bool bUpdateDelayForChoreo,
        SoundError *soundError)
{
  IWaveData *v6; // esi
  CAudioMixerWave8Mono *WaveMixer; // edi

  *soundError = SE_OK;
  v6 = (IWaveData *)MemAlloc_Alloc(nSize: 8u);
  if ( v6 != nullptr )
  {
    v6->__vftable = (IWaveData_vtbl *)&CAudioSourceVoice::CWaveDataVoice::`vftable';
    v6[1].__vftable = (IWaveData_vtbl *)this;
    WaveMixer = CreateWaveMixer(data: v6, format: 1, channels: 1, bits: 16);
    if ( WaveMixer != nullptr )
    {
      this->ReferenceAdd(this, a2: WaveMixer);
      return WaveMixer;
    }
    else
    {
      ((void (__thiscall *)(IWaveData *, int))v6->dtr_IWaveData)(a1: v6, a2: 1);
      *soundError = SE_CANT_CREATE_MIXER;
      return nullptr;
    }
  }
  else
  {
    *soundError = SE_CANT_CREATE_MIXER;
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100576B0
// Name: void VoiceSE_Idle(float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl VoiceSE_Idle(float frametime)
{
  float v1; // xmm0_4
  float m_fValue; // xmm1_4
  bool v3; // cc

  g_SND_VoiceOverdriveInt = 256;
  if ( g_bVoiceOverdriveOn )
  {
    v1 = g_VoiceOverdriveDuration + frametime;
    m_fValue = voice_overdrivefadetime.m_pParent->m_Value.m_fValue;
    v3 = m_fValue <= (float)(g_VoiceOverdriveDuration + frametime);
  }
  else
  {
    m_fValue = 0.0;
    if ( g_VoiceOverdriveDuration == 0.0 )
      return;
    v1 = g_VoiceOverdriveDuration - frametime;
    v3 = (float)(g_VoiceOverdriveDuration - frametime) <= 0.0;
  }
  if ( v3 )
    g_VoiceOverdriveDuration = m_fValue;
  else
    g_VoiceOverdriveDuration = v1;
  g_SND_VoiceOverdriveInt = (int)(256.0
                                / ((voice_overdrive.m_pParent->m_Value.m_fValue - 1.0)
                                 * (0.5
                                  - cos(
                                      g_VoiceOverdriveDuration
                                    / voice_overdrivefadetime.m_pParent->m_Value.m_fValue
                                    * 3.1415926535)
                                  * 0.5)
                                 + 1.0));
}

//------------------------------------------------------------------------------
// Address: 0x10057750
// Name: int VoiceSE_StartChannel(int,int,bool,int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl VoiceSE_StartChannel(int iChannel, int iEntity, bool bProximity, int nViewEntityIndex)
{
  char v4; // al
  StartSoundParams_t params; // [esp+0h] [ebp-64h] BYREF

  params.speakerentity = -1;
  params.m_nQueuedGUID = -1;
  params.m_nSoundScriptHandle = -1;
  v4 = *((_BYTE *)&params + 96) & 0xC0 | 2;
  params.delay = 0.0;
  params.opStackElapsedTime = 0.0;
  params.opStackElapsedStopTime = 0.0;
  memset(&params.origin, 0, 24);
  (&g_CVoiceSfx.pSource)[7 * iChannel] = nullptr;
  params.pSfx = &g_CVoiceSfx + iChannel;
  params.userdata = 0;
  params.initialStreamPosition = 0;
  params.skipInitialSamples = 0;
  params.m_pSoundEntryName = nullptr;
  params.m_pOperatorsKV = nullptr;
  *((_BYTE *)&params + 96) = v4;
  params.entchannel = iChannel + 7;
  params.fvol = 1.0;
  params.flags = 0;
  params.pitch = 100;
  if ( bProximity )
  {
    *((_BYTE *)&params + 96) = v4 | 2;
    params.soundlevel = SNDLVL_80dB;
    params.soundsource = iEntity;
  }
  else
  {
    params.soundlevel = SNDLVL_IDLE;
    params.soundsource = nViewEntityIndex;
  }
  return S_StartSound(&params);
}

} // namespace engine_xlsp
