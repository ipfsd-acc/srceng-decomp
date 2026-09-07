// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: engine/audio/private/snd_dev_wave.cpp
// Functions: 24
// ============================================================

#include "engine\audio\private\snd_dev_wave.h"

//------------------------------------------------------------------------------
// Address: 0x1000B590
// Name: private: void CAudioDeviceWave::FreeOutputBuffers(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAudioDeviceWave::FreeOutputBuffers(CAudioDeviceWave *this)
{
  int v2; // edi

  v2 = 0;
  if ( this->m_pWaveHdr != nullptr )
  {
    do
      waveOutUnprepareHeader(hwo: this->m_waveOutHandle, pwh: &this->m_pWaveHdr[v2++], cbwh: 0x20u);
    while ( v2 < 64 );
  }
  this->m_pWaveHdr = nullptr;
  this->m_pBuffer = nullptr;
  if ( this->m_hWaveData != nullptr )
  {
    GlobalUnlock(hMem: this->m_hWaveData);
    GlobalFree(hMem: this->m_hWaveData);
    this->m_hWaveData = nullptr;
  }
  if ( this->m_hWaveHdr != nullptr )
  {
    GlobalUnlock(hMem: this->m_hWaveHdr);
    GlobalFree(hMem: this->m_hWaveHdr);
    this->m_hWaveHdr = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000B600
// Name: public: virtual __int64 CAudioDeviceWave::PaintBegin(float,__int64,__int64)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CAudioDeviceWave::PaintBegin(
        CAudioDeviceWave *this,
        float mixAheadTime,
        __int64 soundtime,
        __int64 paintedtime)
{
  int v5; // edi
  int v6; // eax
  int mixAheadTimea; // [esp+18h] [ebp+8h]

  v5 = (unsigned __int64)((double)this->DeviceDmaSpeed(this) * mixAheadTime + (double)soundtime);
  mixAheadTimea = this->DeviceChannels(this) - 1;
  v6 = this->DeviceSampleCount(this) >> mixAheadTimea;
  if ( v5 - (int)soundtime > v6 )
    v5 = soundtime + v6;
  if ( (((_BYTE)v5 - (_BYTE)paintedtime) & 3) != 0 )
    v5 -= ((_BYTE)v5 - (_BYTE)paintedtime) & 3;
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x1000B680
// Name: public: virtual void CAudioDeviceWave::PaintEnd(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAudioDeviceWave::PaintEnd(CAudioDeviceWave *this)
{
  int m_buffersSent; // ecx
  wavehdr_tag *m_pWaveHdr; // edx
  int v4; // eax
  wavehdr_tag *v5; // eax

  m_buffersSent = this->m_buffersSent;
  if ( this->m_buffersCompleted != m_buffersSent )
  {
    m_pWaveHdr = this->m_pWaveHdr;
    do
    {
      if ( (m_pWaveHdr[this->m_buffersCompleted & 0x3F].dwFlags & 1) == 0 )
        break;
      v4 = this->m_buffersCompleted + 1;
      this->m_buffersCompleted = v4;
    }
    while ( v4 != m_buffersSent );
  }
  if ( (int)((m_buffersSent - this->m_buffersCompleted) & 0xFFFFFFFE) < 16 )
  {
    while ( 1 )
    {
      v5 = &this->m_pWaveHdr[this->m_buffersSent++ & 0x3F];
      if ( waveOutWrite(hwo: this->m_waveOutHandle, pwh: v5, cbwh: 0x20u) != 0 )
        break;
      if ( (int)((this->m_buffersSent - this->m_buffersCompleted) & 0xFFFFFFFE) >= 16 )
        return;
    }
    _Warning(a1: "Failed to write block to device\n");
    this->Shutdown(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000B710
// Name: public: virtual int CAudioDeviceWave::GetOutputPosition(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CAudioDeviceWave::GetOutputPosition(CAudioDeviceWave *this)
{
  int v2; // edi
  int v3; // edi

  v2 = this->m_buffersSent << 10 >> 1;
  v3 = (((int (*)(void))this->DeviceSampleCount)() - 1) & v2;
  return v3 / this->DeviceChannels(this);
}

//------------------------------------------------------------------------------
// Address: 0x1000B740
// Name: public: virtual void CAudioDeviceWave::Pause(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAudioDeviceWave::Pause(CAudioDeviceWave *this)
{
  if ( ++this->m_pauseCount == 1 )
    waveOutReset(hwo: this->m_waveOutHandle);
}

//------------------------------------------------------------------------------
// Address: 0x1000B760
// Name: public: virtual void CAudioDeviceWave::UnPause(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAudioDeviceWave::UnPause(CAudioDeviceWave *this)
{
  int m_pauseCount; // eax

  m_pauseCount = this->m_pauseCount;
  if ( m_pauseCount > 0 )
    this->m_pauseCount = m_pauseCount - 1;
}

//------------------------------------------------------------------------------
// Address: 0x1000B770
// Name: public: virtual bool CAudioDeviceWave::IsActive(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CAudioDeviceWave::IsActive(CAudioDeviceWave *this)
{
  return this->m_pauseCount == 0;
}

//------------------------------------------------------------------------------
// Address: 0x1000B780
// Name: public: virtual void CAudioDeviceWave::ClearBuffer(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAudioDeviceWave::ClearBuffer(CAudioDeviceWave *this)
{
  int v2; // edi
  int v3; // eax

  if ( this->m_pBuffer != nullptr )
  {
    v2 = this->DeviceSampleCount(this);
    v3 = this->DeviceSampleBytes(this);
    _V_memset(dest: this->m_pBuffer, fill: 0, count: v3 * v2);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000B7C0
// Name: public: virtual void CAudioDeviceWave::MixBegin(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAudioDeviceWave::MixBegin(CAudioDeviceBase *this, int sampleCount)
{
  MIX_ClearAllPaintBuffers(SampleCount: sampleCount, clearFilters: false);
}

//------------------------------------------------------------------------------
// Address: 0x1000B7E0
// Name: public: virtual void CAudioDeviceWave::MixUpsample(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAudioDeviceWave::MixUpsample(CAudioDeviceWave *this, int sampleCount, int filtertype)
{
  paintbuffer_t *CurrentPaintbufferPtr; // esi

  CurrentPaintbufferPtr = MIX_GetCurrentPaintbufferPtr();
  S_MixBufferUpsample2x(
    count: sampleCount,
    pbuffer: CurrentPaintbufferPtr->pbuf,
    pfiltermem: CurrentPaintbufferPtr->fltmem[CurrentPaintbufferPtr->ifilter],
    cfltmem: 3,
    filtertype);
  ++CurrentPaintbufferPtr->ifilter;
}

//------------------------------------------------------------------------------
// Address: 0x1000B820
// Name: public: virtual void CAudioDeviceWave::Mix8Mono(struct channel_t __near *,char __near *,int,int,unsigned int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAudioDeviceWave::Mix8Mono(
        CAudioDeviceWave *this,
        channel_t *pChannel,
        char *pData,
        int outputOffset,
        int inputOffset,
        unsigned int rateScaleFix,
        int outCount,
        int timecompress)
{
  paintbuffer_t *CurrentPaintbufferPtr; // esi
  int volume[12]; // [esp+8h] [ebp-30h] BYREF

  CurrentPaintbufferPtr = MIX_GetCurrentPaintbufferPtr();
  if ( MIX_ScaleChannelVolume(ppaint: CurrentPaintbufferPtr, pChannel, volume, mixchans: 1) )
    Mix8MonoWavtype(
      pChannel,
      pOutput: &CurrentPaintbufferPtr->pbuf[outputOffset],
      volume,
      (unsigned __int8 *)pData,
      inputOffset,
      rateScaleFix,
      outCount);
}

//------------------------------------------------------------------------------
// Address: 0x1000B880
// Name: public: virtual void CAudioDeviceWave::Mix8Stereo(struct channel_t __near *,char __near *,int,int,unsigned int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAudioDeviceWave::Mix8Stereo(
        CAudioDeviceWave *this,
        channel_t *pChannel,
        char *pData,
        int outputOffset,
        int inputOffset,
        unsigned int rateScaleFix,
        int outCount,
        int timecompress)
{
  paintbuffer_t *CurrentPaintbufferPtr; // esi
  int volume[12]; // [esp+8h] [ebp-30h] BYREF

  CurrentPaintbufferPtr = MIX_GetCurrentPaintbufferPtr();
  if ( MIX_ScaleChannelVolume(ppaint: CurrentPaintbufferPtr, pChannel, volume, mixchans: 2) )
    Mix8StereoWavtype(
      pChannel,
      pOutput: &CurrentPaintbufferPtr->pbuf[outputOffset],
      volume,
      (unsigned __int8 *)pData,
      inputOffset,
      rateScaleFix,
      outCount);
}

//------------------------------------------------------------------------------
// Address: 0x1000B8E0
// Name: public: virtual void CAudioDeviceWave::Mix16Mono(struct channel_t __near *,short __near *,int,int,unsigned int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAudioDeviceWave::Mix16Mono(
        CAudioDeviceWave *this,
        channel_t *pChannel,
        __int16 *pData,
        int outputOffset,
        int inputOffset,
        unsigned int rateScaleFix,
        int outCount,
        int timecompress)
{
  paintbuffer_t *CurrentPaintbufferPtr; // esi
  int volume[12]; // [esp+8h] [ebp-30h] BYREF

  CurrentPaintbufferPtr = MIX_GetCurrentPaintbufferPtr();
  if ( MIX_ScaleChannelVolume(ppaint: CurrentPaintbufferPtr, pChannel, volume, mixchans: 1) )
    Mix16MonoWavtype(
      pChannel,
      pOutput: &CurrentPaintbufferPtr->pbuf[outputOffset],
      volume,
      pData,
      inputOffset,
      rateScaleFix,
      outCount);
}

//------------------------------------------------------------------------------
// Address: 0x1000B940
// Name: public: virtual void CAudioDeviceWave::Mix16Stereo(struct channel_t __near *,short __near *,int,int,unsigned int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAudioDeviceWave::Mix16Stereo(
        CAudioDeviceWave *this,
        channel_t *pChannel,
        __int16 *pData,
        int outputOffset,
        int inputOffset,
        unsigned int rateScaleFix,
        int outCount,
        int timecompress)
{
  paintbuffer_t *CurrentPaintbufferPtr; // esi
  int volume[12]; // [esp+8h] [ebp-30h] BYREF

  CurrentPaintbufferPtr = MIX_GetCurrentPaintbufferPtr();
  if ( MIX_ScaleChannelVolume(ppaint: CurrentPaintbufferPtr, pChannel, volume, mixchans: 2) )
    Mix16StereoWavtype(
      pChannel,
      pOutput: &CurrentPaintbufferPtr->pbuf[outputOffset],
      volume,
      pData,
      inputOffset,
      rateScaleFix,
      outCount);
}

//------------------------------------------------------------------------------
// Address: 0x1000B9A0
// Name: public: virtual void CAudioDeviceWave::TransferSamples(__int64)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAudioDeviceWave::TransferSamples(CAudioDeviceWave *this, __int64 end)
{
  void *m_pBuffer; // eax

  m_pBuffer = this->m_pBuffer;
  if ( m_pBuffer != nullptr )
    S_TransferStereo16(pOutput: m_pBuffer, pfront: g_curpaintbuffer, lpaintedtime: g_paintedtime, endtime: end);
}

//------------------------------------------------------------------------------
// Address: 0x1000B9E0
// Name: public: virtual void CAudioDeviceWave::ApplyDSPEffects(int,struct portable_samplepair_t __near *,struct portable_samplepair_t __near *,struct portable_samplepair_t __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAudioDeviceWave::ApplyDSPEffects(
        CAudioDeviceWave *this,
        int idsp,
        portable_samplepair_t *pbuffront,
        portable_samplepair_t *pbufrear,
        portable_samplepair_t *pbufcenter,
        int samplecount)
{
  DSP_Process(idsp, pbfront: pbuffront, pbrear: pbufrear, pbcenter: pbufcenter, sampleCount: samplecount);
}

//------------------------------------------------------------------------------
// Address: 0x1000BA10
// Name: private: void __near * CAudioDeviceWave::AllocOutputMemory(int,void __near * __near &)
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 *__thiscall CAudioDeviceWave::AllocOutputMemory(CAudioDeviceWave *this, SIZE_T nSize, void **hMemory)
{
  HGLOBAL v4; // eax
  unsigned __int8 *v6; // eax
  unsigned __int8 *v7; // edi

  v4 = GlobalAlloc(uFlags: 0x2002u, dwBytes: nSize);
  *hMemory = v4;
  if ( v4 != nullptr )
  {
    v6 = (unsigned __int8 *)GlobalLock(hMem: v4);
    v7 = v6;
    if ( v6 != nullptr )
    {
      memset(dst: v6, value: 0, count: nSize);
      return v7;
    }
    else
    {
      DevWarning(a1: "Sound: Failed to lock.\n");
      GlobalFree(hMem: *hMemory);
      *hMemory = nullptr;
      if ( this->m_waveOutHandle != nullptr )
      {
        waveOutReset(hwo: this->m_waveOutHandle);
        CAudioDeviceWave::FreeOutputBuffers(this);
        waveOutClose(hwo: this->m_waveOutHandle);
        this->m_waveOutHandle = nullptr;
      }
      return nullptr;
    }
  }
  else
  {
    DevWarning(a1: "Sound: Out of memory.\n");
    if ( this->m_waveOutHandle != nullptr )
    {
      waveOutReset(hwo: this->m_waveOutHandle);
      CAudioDeviceWave::FreeOutputBuffers(this);
      waveOutClose(hwo: this->m_waveOutHandle);
      this->m_waveOutHandle = nullptr;
    }
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000BAE0
// Name: private: void CAudioDeviceWave::AllocateOutputBuffers(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAudioDeviceWave::AllocateOutputBuffers(CAudioDeviceWave *this)
{
  unsigned __int8 *v2; // ebx
  unsigned __int8 *v3; // eax
  wavehdr_tag *j; // esi
  int v5; // eax
  wavehdr_tag *lpWaveHdr; // [esp+8h] [ebp-Ch]
  char *lpData; // [esp+Ch] [ebp-8h]
  int i; // [esp+10h] [ebp-4h]

  v2 = CAudioDeviceWave::AllocOutputMemory(this, nSize: 0x10000u, hMemory: &this->m_hWaveData);
  lpData = (char *)v2;
  if ( v2 != nullptr )
  {
    v3 = CAudioDeviceWave::AllocOutputMemory(this, nSize: 0x800u, hMemory: &this->m_hWaveHdr);
    lpWaveHdr = (wavehdr_tag *)v3;
    if ( v3 != nullptr )
    {
      i = 0;
      for ( j = (wavehdr_tag *)v3; ; ++j )
      {
        j->dwBufferLength = 1024;
        j->lpData = (char *)v2;
        if ( waveOutPrepareHeader(hwo: this->m_waveOutHandle, pwh: j, cbwh: 0x20u) != 0 )
          break;
        v2 += 1024;
        if ( ++i >= 64 )
        {
          v5 = this->DeviceSampleBytes(this);
          this->m_pBuffer = lpData;
          this->m_deviceSampleCount = 0x10000 / v5;
          this->m_pWaveHdr = lpWaveHdr;
          return;
        }
      }
      DevWarning(a1: "Sound: failed to prepare wave headers\n");
      if ( this->m_waveOutHandle != nullptr )
      {
        waveOutReset(hwo: this->m_waveOutHandle);
        CAudioDeviceWave::FreeOutputBuffers(this);
        waveOutClose(hwo: this->m_waveOutHandle);
        this->m_waveOutHandle = nullptr;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000BBC0
// Name: public: virtual char const __near * CAudioDeviceWave::DeviceName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CAudioDeviceWave::DeviceName(CAudioDeviceWave *this)
{
  return "Windows WAVE";
}

//------------------------------------------------------------------------------
// Address: 0x1000BBE0
// Name: public: virtual void CAudioDeviceWave::Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAudioDeviceWave::Shutdown(CAudioDeviceWave *this)
{
  if ( this->m_waveOutHandle != nullptr )
  {
    waveOutReset(hwo: this->m_waveOutHandle);
    CAudioDeviceWave::FreeOutputBuffers(this);
    waveOutClose(hwo: this->m_waveOutHandle);
    this->m_waveOutHandle = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000BC10
// Name: private: void CAudioDeviceWave::OpenWaveOut(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAudioDeviceWave::OpenWaveOut(CAudioDeviceWave *this)
{
  CAudioDeviceWave_vtbl *v2; // edx
  int (__thiscall *DeviceChannels)(struct CAudioDeviceWave *); // eax
  unsigned __int16 v4; // ax
  CAudioDeviceWave_vtbl *v5; // edx
  unsigned __int16 v6; // ax
  CAudioDeviceWave_vtbl *v7; // edx
  unsigned int v8; // eax
  HWAVEOUT__ **p_m_waveOutHandle; // edi
  MMRESULT v10; // eax
  tWAVEFORMATEX waveFormat; // [esp+Ch] [ebp-14h] BYREF

  v2 = this->__vftable;
  memset(&waveFormat, 0, 16);
  waveFormat.cbSize = 18;
  DeviceChannels = v2->DeviceChannels;
  waveFormat.wFormatTag = 1;
  v4 = DeviceChannels(this);
  v5 = this->__vftable;
  waveFormat.nChannels = v4;
  v6 = v5->DeviceSampleBits(this);
  v7 = this->__vftable;
  waveFormat.wBitsPerSample = v6;
  v8 = v7->DeviceDmaSpeed(this);
  waveFormat.nBlockAlign = waveFormat.nChannels * waveFormat.wBitsPerSample / 8;
  waveFormat.nSamplesPerSec = v8;
  p_m_waveOutHandle = &this->m_waveOutHandle;
  waveFormat.nAvgBytesPerSec = v8 * waveFormat.nBlockAlign;
  v10 = waveOutOpen(
          phwo: &this->m_waveOutHandle,
          uDeviceID: 0xFFFFFFFF,
          pwfx: &waveFormat,
          dwCallback: 0,
          dwInstance: 0,
          fdwOpen: 0);
  if ( v10 != 0 )
  {
    while ( 1 )
    {
      if ( v10 != 4 )
      {
        DevWarning(a1: "waveOutOpen failed\n");
        *p_m_waveOutHandle = nullptr;
        return;
      }
      if ( MessageBoxA(
             hWnd: nullptr,
             lpText: "The sound hardware is in use by another app.\n"
             "\n"
             "Select Retry to try to start sound again or Cancel to run with no sound.",
             lpCaption: "Sound not available",
             uType: 0x10035u) != 4 )
        break;
      v10 = waveOutOpen(
              phwo: &this->m_waveOutHandle,
              uDeviceID: 0xFFFFFFFF,
              pwfx: &waveFormat,
              dwCallback: 0,
              dwInstance: 0,
              fdwOpen: 0);
      if ( v10 == 0 )
        goto LABEL_5;
    }
    DevWarning(a1: "waveOutOpen failure--hardware already in use\n");
    *p_m_waveOutHandle = nullptr;
  }
  else
  {
LABEL_5:
    CAudioDeviceWave::AllocateOutputBuffers(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000BD20
// Name: class IAudioDevice __near * Audio_CreateWaveDevice(void)
// Source: json
//------------------------------------------------------------------------------
CAudioDeviceWave *__cdecl Audio_CreateWaveDevice()
{
  CAudioDeviceWave *v0; // ecx
  CAudioDeviceWave *v1; // eax

  v0 = wave;
  if ( wave == nullptr )
  {
    v1 = (CAudioDeviceWave *)MemAlloc_Alloc(nSize: 0x2Cu);
    if ( v1 != nullptr )
    {
      v1->__vftable = (CAudioDeviceWave_vtbl *)&CAudioDeviceWave::`vftable';
      v0 = v1;
    }
    else
    {
      v0 = nullptr;
    }
    wave = v0;
  }
  if ( v0->Init(this: v0) )
    return wave;
  if ( wave != nullptr )
    ((void (__thiscall *)(CAudioDeviceWave *, int))wave->dtr_IAudioDevice)(a1: wave, a2: 1);
  wave = nullptr;
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1000BD80
// Name: public: virtual bool CAudioDeviceWave::Init(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CAudioDeviceWave::Init(CAudioDeviceWave *this)
{
  *(_WORD *)&this->m_bSurround = 0;
  this->m_bHeadphone = false;
  this->m_buffersSent = 0;
  this->m_buffersCompleted = 0;
  this->m_pauseCount = 0;
  this->m_waveOutHandle = nullptr;
  this->m_pBuffer = nullptr;
  this->m_pWaveHdr = nullptr;
  this->m_hWaveHdr = nullptr;
  this->m_hWaveData = nullptr;
  CAudioDeviceWave::OpenWaveOut(this);
  if ( snd_firsttime )
    DevMsg(a1: "Wave sound initialized\n");
  return this->m_waveOutHandle != nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x101CC4E0
// Name: public: virtual float CAudioDeviceWave::MixDryVolume(void)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CAudioDeviceWave::MixDryVolume(CAudioDeviceNull *this)
{
  return 0.0;
}

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x10008930
// Name: public: virtual float CAudioDeviceWave::MixDryVolume(void)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CAudioDeviceWave::MixDryVolume(CAudioDeviceNull *this)
{
  return 0.0;
}

//------------------------------------------------------------------------------
// Address: 0x1000B560
// Name: private: void CAudioDeviceWave::FreeOutputBuffers(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAudioDeviceWave::FreeOutputBuffers(CAudioDeviceWave *this)
{
  int v2; // edi

  v2 = 0;
  if ( this->m_pWaveHdr != nullptr )
  {
    do
      waveOutUnprepareHeader(hwo: this->m_waveOutHandle, pwh: &this->m_pWaveHdr[v2++], cbwh: 0x20u);
    while ( v2 < 64 );
  }
  this->m_pWaveHdr = nullptr;
  this->m_pBuffer = nullptr;
  if ( this->m_hWaveData != nullptr )
  {
    GlobalUnlock(hMem: this->m_hWaveData);
    GlobalFree(hMem: this->m_hWaveData);
    this->m_hWaveData = nullptr;
  }
  if ( this->m_hWaveHdr != nullptr )
  {
    GlobalUnlock(hMem: this->m_hWaveHdr);
    GlobalFree(hMem: this->m_hWaveHdr);
    this->m_hWaveHdr = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000B5D0
// Name: public: virtual __int64 CAudioDeviceWave::PaintBegin(float,__int64,__int64)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CAudioDeviceWave::PaintBegin(
        CAudioDeviceWave *this,
        float mixAheadTime,
        __int64 soundtime,
        __int64 paintedtime)
{
  int v5; // edi
  int v6; // eax
  int mixAheadTimea; // [esp+18h] [ebp+8h]

  v5 = (unsigned __int64)((double)this->DeviceDmaSpeed(this) * mixAheadTime + (double)soundtime);
  mixAheadTimea = this->DeviceChannels(this) - 1;
  v6 = this->DeviceSampleCount(this) >> mixAheadTimea;
  if ( v5 - (int)soundtime > v6 )
    v5 = soundtime + v6;
  if ( (((_BYTE)v5 - (_BYTE)paintedtime) & 3) != 0 )
    v5 -= ((_BYTE)v5 - (_BYTE)paintedtime) & 3;
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x1000B650
// Name: public: virtual void CAudioDeviceWave::PaintEnd(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAudioDeviceWave::PaintEnd(CAudioDeviceWave *this)
{
  int m_buffersSent; // ecx
  wavehdr_tag *m_pWaveHdr; // edx
  int v4; // eax
  wavehdr_tag *v5; // eax

  m_buffersSent = this->m_buffersSent;
  if ( this->m_buffersCompleted != m_buffersSent )
  {
    m_pWaveHdr = this->m_pWaveHdr;
    do
    {
      if ( (m_pWaveHdr[this->m_buffersCompleted & 0x3F].dwFlags & 1) == 0 )
        break;
      v4 = this->m_buffersCompleted + 1;
      this->m_buffersCompleted = v4;
    }
    while ( v4 != m_buffersSent );
  }
  if ( (int)((m_buffersSent - this->m_buffersCompleted) & 0xFFFFFFFE) < 16 )
  {
    while ( 1 )
    {
      v5 = &this->m_pWaveHdr[this->m_buffersSent++ & 0x3F];
      if ( waveOutWrite(hwo: this->m_waveOutHandle, pwh: v5, cbwh: 0x20u) != 0 )
        break;
      if ( (int)((this->m_buffersSent - this->m_buffersCompleted) & 0xFFFFFFFE) >= 16 )
        return;
    }
    _Warning(a1: "Failed to write block to device\n");
    this->Shutdown(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000B6E0
// Name: public: virtual int CAudioDeviceWave::GetOutputPosition(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CAudioDeviceWave::GetOutputPosition(CAudioDeviceWave *this)
{
  int v2; // edi
  int v3; // edi

  v2 = this->m_buffersSent << 10 >> 1;
  v3 = (((int (*)(void))this->DeviceSampleCount)() - 1) & v2;
  return v3 / this->DeviceChannels(this);
}

//------------------------------------------------------------------------------
// Address: 0x1000B730
// Name: public: virtual void CAudioDeviceWave::UnPause(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAudioDeviceWave::UnPause(CAudioDeviceWave *this)
{
  int m_pauseCount; // eax

  m_pauseCount = this->m_pauseCount;
  if ( m_pauseCount > 0 )
    this->m_pauseCount = m_pauseCount - 1;
}

//------------------------------------------------------------------------------
// Address: 0x1000B750
// Name: public: virtual void CAudioDeviceWave::ClearBuffer(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAudioDeviceWave::ClearBuffer(CAudioDeviceWave *this)
{
  int v2; // edi
  int v3; // eax

  if ( this->m_pBuffer != nullptr )
  {
    v2 = this->DeviceSampleCount(this);
    v3 = this->DeviceSampleBytes(this);
    _V_memset(dest: this->m_pBuffer, fill: 0, count: v3 * v2);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000B790
// Name: public: virtual void CAudioDeviceWave::MixBegin(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAudioDeviceWave::MixBegin(CAudioDeviceBase *this, int sampleCount)
{
  MIX_ClearAllPaintBuffers(SampleCount: sampleCount, clearFilters: false);
}

//------------------------------------------------------------------------------
// Address: 0x1000B7B0
// Name: public: virtual void CAudioDeviceWave::MixUpsample(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAudioDeviceWave::MixUpsample(CAudioDeviceWave *this, int sampleCount, int filtertype)
{
  paintbuffer_t *CurrentPaintbufferPtr; // esi

  CurrentPaintbufferPtr = MIX_GetCurrentPaintbufferPtr();
  S_MixBufferUpsample2x(
    count: sampleCount,
    pbuffer: CurrentPaintbufferPtr->pbuf,
    pfiltermem: CurrentPaintbufferPtr->fltmem[CurrentPaintbufferPtr->ifilter],
    cfltmem: 3,
    filtertype);
  ++CurrentPaintbufferPtr->ifilter;
}

//------------------------------------------------------------------------------
// Address: 0x1000B7F0
// Name: public: virtual void CAudioDeviceWave::Mix8Mono(struct channel_t __near *,char __near *,int,int,unsigned int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAudioDeviceWave::Mix8Mono(
        CAudioDeviceWave *this,
        channel_t *pChannel,
        char *pData,
        int outputOffset,
        int inputOffset,
        unsigned int rateScaleFix,
        int outCount,
        int timecompress)
{
  paintbuffer_t *CurrentPaintbufferPtr; // esi
  int volume[12]; // [esp+8h] [ebp-30h] BYREF

  CurrentPaintbufferPtr = MIX_GetCurrentPaintbufferPtr();
  if ( MIX_ScaleChannelVolume(ppaint: CurrentPaintbufferPtr, pChannel, volume, mixchans: 1) )
    Mix8MonoWavtype(
      pChannel,
      pOutput: &CurrentPaintbufferPtr->pbuf[outputOffset],
      volume,
      (unsigned __int8 *)pData,
      inputOffset,
      rateScaleFix,
      outCount);
}

//------------------------------------------------------------------------------
// Address: 0x1000B850
// Name: public: virtual void CAudioDeviceWave::Mix8Stereo(struct channel_t __near *,char __near *,int,int,unsigned int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAudioDeviceWave::Mix8Stereo(
        CAudioDeviceWave *this,
        channel_t *pChannel,
        char *pData,
        int outputOffset,
        int inputOffset,
        unsigned int rateScaleFix,
        int outCount,
        int timecompress)
{
  paintbuffer_t *CurrentPaintbufferPtr; // esi
  int volume[12]; // [esp+8h] [ebp-30h] BYREF

  CurrentPaintbufferPtr = MIX_GetCurrentPaintbufferPtr();
  if ( MIX_ScaleChannelVolume(ppaint: CurrentPaintbufferPtr, pChannel, volume, mixchans: 2) )
    Mix8StereoWavtype(
      pChannel,
      pOutput: &CurrentPaintbufferPtr->pbuf[outputOffset],
      volume,
      (unsigned __int8 *)pData,
      inputOffset,
      rateScaleFix,
      outCount);
}

//------------------------------------------------------------------------------
// Address: 0x1000B8B0
// Name: public: virtual void CAudioDeviceWave::Mix16Mono(struct channel_t __near *,short __near *,int,int,unsigned int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAudioDeviceWave::Mix16Mono(
        CAudioDeviceWave *this,
        channel_t *pChannel,
        __int16 *pData,
        int outputOffset,
        int inputOffset,
        unsigned int rateScaleFix,
        int outCount,
        int timecompress)
{
  paintbuffer_t *CurrentPaintbufferPtr; // esi
  int volume[12]; // [esp+8h] [ebp-30h] BYREF

  CurrentPaintbufferPtr = MIX_GetCurrentPaintbufferPtr();
  if ( MIX_ScaleChannelVolume(ppaint: CurrentPaintbufferPtr, pChannel, volume, mixchans: 1) )
    Mix16MonoWavtype(
      pChannel,
      pOutput: &CurrentPaintbufferPtr->pbuf[outputOffset],
      volume,
      pData,
      inputOffset,
      rateScaleFix,
      outCount);
}

//------------------------------------------------------------------------------
// Address: 0x1000B910
// Name: public: virtual void CAudioDeviceWave::Mix16Stereo(struct channel_t __near *,short __near *,int,int,unsigned int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAudioDeviceWave::Mix16Stereo(
        CAudioDeviceWave *this,
        channel_t *pChannel,
        __int16 *pData,
        int outputOffset,
        int inputOffset,
        unsigned int rateScaleFix,
        int outCount,
        int timecompress)
{
  paintbuffer_t *CurrentPaintbufferPtr; // esi
  int volume[12]; // [esp+8h] [ebp-30h] BYREF

  CurrentPaintbufferPtr = MIX_GetCurrentPaintbufferPtr();
  if ( MIX_ScaleChannelVolume(ppaint: CurrentPaintbufferPtr, pChannel, volume, mixchans: 2) )
    Mix16StereoWavtype(
      pChannel,
      pOutput: &CurrentPaintbufferPtr->pbuf[outputOffset],
      volume,
      pData,
      inputOffset,
      rateScaleFix,
      outCount);
}

//------------------------------------------------------------------------------
// Address: 0x1000B970
// Name: public: virtual void CAudioDeviceWave::TransferSamples(__int64)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAudioDeviceWave::TransferSamples(CAudioDeviceWave *this, __int64 end)
{
  void *m_pBuffer; // eax

  m_pBuffer = this->m_pBuffer;
  if ( m_pBuffer != nullptr )
    S_TransferStereo16(pOutput: m_pBuffer, pfront: g_curpaintbuffer, lpaintedtime: g_paintedtime, endtime: end);
}

//------------------------------------------------------------------------------
// Address: 0x1000B9B0
// Name: public: virtual void CAudioDeviceWave::ApplyDSPEffects(int,struct portable_samplepair_t __near *,struct portable_samplepair_t __near *,struct portable_samplepair_t __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAudioDeviceWave::ApplyDSPEffects(
        CAudioDeviceWave *this,
        int idsp,
        portable_samplepair_t *pbuffront,
        portable_samplepair_t *pbufrear,
        portable_samplepair_t *pbufcenter,
        int samplecount)
{
  DSP_Process(idsp, pbfront: pbuffront, pbrear: pbufrear, pbcenter: pbufcenter, sampleCount: samplecount);
}

//------------------------------------------------------------------------------
// Address: 0x1000BAB0
// Name: private: void CAudioDeviceWave::AllocateOutputBuffers(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAudioDeviceWave::AllocateOutputBuffers(CAudioDeviceWave *this)
{
  char *v2; // ebx
  wavehdr_tag *v3; // eax
  wavehdr_tag *j; // esi
  int v5; // eax
  wavehdr_tag *lpWaveHdr; // [esp+8h] [ebp-Ch]
  char *lpData; // [esp+Ch] [ebp-8h]
  int i; // [esp+10h] [ebp-4h]

  v2 = (char *)CAudioDeviceWave::AllocOutputMemory(this, nSize: 0x10000, hMemory: &this->m_hWaveData);
  lpData = v2;
  if ( v2 != nullptr )
  {
    v3 = (wavehdr_tag *)CAudioDeviceWave::AllocOutputMemory(this, nSize: 2048, hMemory: &this->m_hWaveHdr);
    lpWaveHdr = v3;
    if ( v3 != nullptr )
    {
      i = 0;
      for ( j = v3; ; ++j )
      {
        j->dwBufferLength = 1024;
        j->lpData = v2;
        if ( waveOutPrepareHeader(hwo: this->m_waveOutHandle, pwh: j, cbwh: 0x20u) != 0 )
          break;
        v2 += 1024;
        if ( ++i >= 64 )
        {
          v5 = this->DeviceSampleBytes(this);
          this->m_pBuffer = lpData;
          this->m_deviceSampleCount = 0x10000 / v5;
          this->m_pWaveHdr = lpWaveHdr;
          return;
        }
      }
      DevWarning(a1: "Sound: failed to prepare wave headers\n");
      if ( this->m_waveOutHandle != nullptr )
      {
        waveOutReset(hwo: this->m_waveOutHandle);
        CAudioDeviceWave::FreeOutputBuffers(this);
        waveOutClose(hwo: this->m_waveOutHandle);
        this->m_waveOutHandle = nullptr;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000BB90
// Name: public: virtual char const __near * CAudioDeviceWave::DeviceName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CAudioDeviceWave::DeviceName(CAudioDeviceWave *this)
{
  return "Windows WAVE";
}

//------------------------------------------------------------------------------
// Address: 0x1000BBD0
// Name: public: virtual void CAudioDeviceWave::Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAudioDeviceWave::Shutdown(CAudioDeviceWave *this)
{
  if ( this->m_waveOutHandle != nullptr )
  {
    waveOutReset(hwo: this->m_waveOutHandle);
    CAudioDeviceWave::FreeOutputBuffers(this);
    waveOutClose(hwo: this->m_waveOutHandle);
    this->m_waveOutHandle = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000BC00
// Name: private: void CAudioDeviceWave::OpenWaveOut(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAudioDeviceWave::OpenWaveOut(CAudioDeviceWave *this)
{
  CAudioDeviceWave_vtbl *v2; // edx
  int (__thiscall *DeviceChannels)(struct CAudioDeviceWave *); // eax
  unsigned __int16 v4; // ax
  CAudioDeviceWave_vtbl *v5; // edx
  unsigned __int16 v6; // ax
  CAudioDeviceWave_vtbl *v7; // edx
  unsigned int v8; // eax
  HWAVEOUT__ **p_m_waveOutHandle; // edi
  MMRESULT v10; // eax
  tWAVEFORMATEX waveFormat; // [esp+Ch] [ebp-14h] BYREF

  v2 = this->__vftable;
  memset(&waveFormat, 0, 16);
  waveFormat.cbSize = 18;
  DeviceChannels = v2->DeviceChannels;
  waveFormat.wFormatTag = 1;
  v4 = DeviceChannels(this);
  v5 = this->__vftable;
  waveFormat.nChannels = v4;
  v6 = v5->DeviceSampleBits(this);
  v7 = this->__vftable;
  waveFormat.wBitsPerSample = v6;
  v8 = v7->DeviceDmaSpeed(this);
  waveFormat.nBlockAlign = waveFormat.nChannels * waveFormat.wBitsPerSample / 8;
  waveFormat.nSamplesPerSec = v8;
  p_m_waveOutHandle = &this->m_waveOutHandle;
  waveFormat.nAvgBytesPerSec = v8 * waveFormat.nBlockAlign;
  v10 = waveOutOpen(
          phwo: &this->m_waveOutHandle,
          uDeviceID: 0xFFFFFFFF,
          pwfx: &waveFormat,
          dwCallback: 0,
          dwInstance: 0,
          fdwOpen: 0);
  if ( v10 != 0 )
  {
    while ( 1 )
    {
      if ( v10 != 4 )
      {
        DevWarning(a1: "waveOutOpen failed\n");
        *p_m_waveOutHandle = nullptr;
        return;
      }
      if ( MessageBoxA(
             hWnd: nullptr,
             lpText: "The sound hardware is in use by another app.\n"
             "\n"
             "Select Retry to try to start sound again or Cancel to run with no sound.",
             lpCaption: "Sound not available",
             uType: 0x10035u) != 4 )
        break;
      v10 = waveOutOpen(
              phwo: &this->m_waveOutHandle,
              uDeviceID: 0xFFFFFFFF,
              pwfx: &waveFormat,
              dwCallback: 0,
              dwInstance: 0,
              fdwOpen: 0);
      if ( v10 == 0 )
        goto LABEL_5;
    }
    DevWarning(a1: "waveOutOpen failure--hardware already in use\n");
    *p_m_waveOutHandle = nullptr;
  }
  else
  {
LABEL_5:
    CAudioDeviceWave::AllocateOutputBuffers(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000BD10
// Name: class IAudioDevice __near * Audio_CreateWaveDevice(void)
// Source: json
//------------------------------------------------------------------------------
CAudioDeviceWave *__cdecl Audio_CreateWaveDevice()
{
  CAudioDeviceWave *v0; // ecx
  CAudioDeviceWave *v1; // eax

  v0 = wave;
  if ( wave == nullptr )
  {
    v1 = (CAudioDeviceWave *)MemAlloc_Alloc(nSize: 0x2Cu);
    if ( v1 != nullptr )
    {
      v1->__vftable = (CAudioDeviceWave_vtbl *)&CAudioDeviceWave::`vftable';
      v0 = v1;
    }
    else
    {
      v0 = nullptr;
    }
    wave = v0;
  }
  if ( v0->Init(this: v0) )
    return wave;
  if ( wave != nullptr )
    ((void (__thiscall *)(CAudioDeviceWave *, int))wave->dtr_IAudioDevice)(a1: wave, a2: 1);
  wave = nullptr;
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1000BD70
// Name: public: virtual bool CAudioDeviceWave::Init(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CAudioDeviceWave::Init(CAudioDeviceWave *this)
{
  *(_WORD *)&this->m_bSurround = 0;
  this->m_bHeadphone = false;
  this->m_buffersSent = 0;
  this->m_buffersCompleted = 0;
  this->m_pauseCount = 0;
  this->m_waveOutHandle = nullptr;
  this->m_pBuffer = nullptr;
  this->m_pWaveHdr = nullptr;
  this->m_hWaveHdr = nullptr;
  this->m_hWaveData = nullptr;
  CAudioDeviceWave::OpenWaveOut(this);
  if ( snd_firsttime )
    DevMsg(a1: "Wave sound initialized\n");
  return this->m_waveOutHandle != nullptr;
}

} // namespace engine_xlsp
