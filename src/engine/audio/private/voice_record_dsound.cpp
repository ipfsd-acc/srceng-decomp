// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: engine/audio/private/voice_record_dsound.cpp
// Functions: 7
// ============================================================

#include "engine\audio\private\voice_record_dsound.h"

//------------------------------------------------------------------------------
// Address: 0x100571A0
// Name: public: virtual void VoiceRecord_DSound::Release(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall VoiceRecord_DSound::Release(VoiceRecord_DSound *this)
{
  if ( this != nullptr )
    ((void (__thiscall *)(VoiceRecord_DSound *, int))this->dtr_IVoiceRecord)(a1: this, a2: 1);
}

//------------------------------------------------------------------------------
// Address: 0x100571B0
// Name: IsRunningWindows7
// Source: json
//------------------------------------------------------------------------------
bool __cdecl IsRunningWindows7()
{
  _OSVERSIONINFOEXA osvi; // [esp+0h] [ebp-9Ch] BYREF

  memset(dst: (unsigned __int8 *)&osvi, value: 0, count: sizeof(osvi));
  osvi.dwOSVersionInfoSize = 156;
  return GetVersionExA(lpVersionInformation: (LPOSVERSIONINFOA)&osvi)
      && (osvi.dwMajorVersion > 6 || osvi.dwMajorVersion == 6 && osvi.dwMinorVersion != 0);
}

//------------------------------------------------------------------------------
// Address: 0x10057210
// Name: public: virtual int VoiceRecord_DSound::GetRecordedData(short __near *,int)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall VoiceRecord_DSound::GetRecordedData(
        VoiceRecord_DSound *this,
        __int16 *pOut,
        unsigned int nSamples)
{
  IDirectSoundCaptureBuffer *m_pCaptureBuffer; // eax
  int v6; // edi
  unsigned int v7; // ecx
  unsigned int m_LastReadPos; // eax
  unsigned int v9; // edi
  unsigned int v10; // eax
  void *pData[2]; // [esp+4h] [ebp-18h] BYREF
  unsigned int dataLen[2]; // [esp+Ch] [ebp-10h] BYREF
  unsigned int dwStatus; // [esp+14h] [ebp-8h] BYREF
  unsigned int dwReadPos; // [esp+18h] [ebp-4h] BYREF
  unsigned int nBytesWanted; // [esp+28h] [ebp+Ch]

  m_pCaptureBuffer = this->m_pCaptureBuffer;
  if ( m_pCaptureBuffer == nullptr
    || m_pCaptureBuffer->GetStatus(this: m_pCaptureBuffer, a2: &dwStatus) < 0
    || (dwStatus & 1) == 0 )
  {
    return 0;
  }
  this->Idle(this);
  v6 = 2 * nSamples;
  nBytesWanted = 2 * nSamples;
  if ( this->m_pCaptureBuffer->GetCurrentPosition(this: this->m_pCaptureBuffer, a2: nullptr, a3: &dwReadPos) < 0 )
    return 0;
  v7 = this->m_WrapOffset + dwReadPos;
  m_LastReadPos = v7 != v6 ? v7 - v6 : 0;
  if ( m_LastReadPos < this->m_LastReadPos )
    m_LastReadPos = this->m_LastReadPos;
  dwReadPos += this->m_WrapOffset;
  if ( this->m_pCaptureBuffer->Lock(
         this: this->m_pCaptureBuffer,
         a2: m_LastReadPos % this->m_nCaptureBufferBytes,
         a3: v7 - m_LastReadPos,
         a4: pData,
         a5: dataLen,
         a6: &pData[1],
         a7: &dataLen[1],
         a8: 0) < 0 )
    return 0;
  v9 = dataLen[0];
  if ( dataLen[1] + dataLen[0] > nBytesWanted )
  {
    this->m_pCaptureBuffer->Unlock(
      this: this->m_pCaptureBuffer,
      a2: pData[0],
      a3: dataLen[0],
      a4: pData[1],
      a5: dataLen[1]);
    return 0;
  }
  memcpy(dst: (unsigned __int8 *)pOut, src: (unsigned __int8 *)pData[0], count: dataLen[0]);
  memcpy(dst: (unsigned __int8 *)&pOut[v9 >> 1], src: (unsigned __int8 *)pData[1], count: dataLen[1]);
  this->m_pCaptureBuffer->Unlock(
    this: this->m_pCaptureBuffer,
    a2: pData[0],
    a3: dataLen[0],
    a4: pData[1],
    a5: dataLen[1]);
  v10 = dataLen[0] + dataLen[1];
  this->m_LastReadPos = dwReadPos;
  return v10 >> 1;
}

//------------------------------------------------------------------------------
// Address: 0x10057340
// Name: private: void VoiceRecord_DSound::Term(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall VoiceRecord_DSound::Term(VoiceRecord_DSound *this)
{
  IDirectSoundCaptureBuffer *m_pCaptureBuffer; // eax
  IDirectSoundCapture *m_pCapture; // eax

  m_pCaptureBuffer = this->m_pCaptureBuffer;
  if ( m_pCaptureBuffer != nullptr )
    m_pCaptureBuffer->Release(this: m_pCaptureBuffer);
  m_pCapture = this->m_pCapture;
  if ( m_pCapture != nullptr )
    m_pCapture->Release(this: this->m_pCapture);
  if ( this->m_hWrapEvent != nullptr )
    DeleteObject(ho: this->m_hWrapEvent);
  if ( this->m_hInstDS != nullptr )
  {
    FreeLibrary(hLibModule: this->m_hInstDS);
    this->m_hInstDS = nullptr;
  }
  this->m_pCapture = nullptr;
  this->m_pCaptureBuffer = nullptr;
  this->m_WrapOffset = 0;
  this->m_LastReadPos = 0;
  this->m_hWrapEvent = nullptr;
  this->m_hInstDS = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x100573A0
// Name: public: virtual void VoiceRecord_DSound::Idle(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall VoiceRecord_DSound::Idle(VoiceRecord_DSound *this)
{
  if ( this->m_pCaptureBuffer != nullptr && WaitForSingleObject(hHandle: this->m_hWrapEvent, dwMilliseconds: 0) == 0 )
    this->m_WrapOffset += this->m_nCaptureBufferBytes;
}

//------------------------------------------------------------------------------
// Address: 0x100573D0
// Name: class IVoiceRecord __near * CreateVoiceRecord_DSound(int)
// Source: json
//------------------------------------------------------------------------------
IVoiceRecord *__cdecl CreateVoiceRecord_DSound(int sampleRate)
{
  _DWORD *v1; // esi

  v1 = MemAlloc_Alloc(nSize: 0x20u);
  if ( v1 != nullptr )
  {
    *v1 = &VoiceRecord_DSound::`vftable';
    v1[2] = 0;
    v1[3] = 0;
    v1[5] = 0;
    v1[7] = 0;
    v1[6] = 0;
    v1[1] = 0;
    if ( (*(unsigned __int8 (__thiscall **)(_DWORD *, int))(*v1 + 24))(a1: v1, a2: sampleRate) != 0 )
      return (IVoiceRecord *)v1;
    (*(void (__thiscall **)(_DWORD *))(*v1 + 4))(a1: v1);
  }
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10057430
// Name: public: virtual bool VoiceRecord_DSound::Init(int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall VoiceRecord_DSound::Init(VoiceRecord_DSound *this, unsigned int sampleRate)
{
  HINSTANCE__ *LibraryA; // eax
  HRESULT (__stdcall *DirectSoundCaptureCreate)(LPCGUID, LPDIRECTSOUNDCAPTURE *, LPUNKNOWN); // edi
  IDirectSoundCapture *m_pCapture; // eax
  IDirectSoundCaptureBuffer **p_m_pCaptureBuffer; // edi
  IDirectSoundCaptureBuffer *v7; // eax
  HANDLE EventA; // eax
  int v9; // ebx
  _DSCBUFFERDESC dscDesc; // [esp+Ch] [ebp-4Ch] BYREF
  tWAVEFORMATEX recordFormat; // [esp+28h] [ebp-30h] BYREF
  _DSCBCAPS caps; // [esp+3Ch] [ebp-1Ch] BYREF
  _DSBPOSITIONNOTIFY dsbNotify; // [esp+4Ch] [ebp-Ch] BYREF
  IDirectSoundNotify *pNotify; // [esp+54h] [ebp-4h] BYREF
  _GUID *pGuid; // [esp+60h] [ebp+8h]

  VoiceRecord_DSound::Term(this);
  recordFormat.nAvgBytesPerSec = 2 * sampleRate;
  *(_DWORD *)&recordFormat.wFormatTag = 65537;
  recordFormat.nSamplesPerSec = sampleRate;
  *(_DWORD *)&recordFormat.nBlockAlign = 1048578;
  recordFormat.cbSize = 18;
  LibraryA = LoadLibraryA(lpLibFileName: "dsound.dll");
  this->m_hInstDS = LibraryA;
  if ( LibraryA != nullptr )
  {
    DirectSoundCaptureCreate = (HRESULT (__stdcall *)(LPCGUID, LPDIRECTSOUNDCAPTURE *, LPUNKNOWN))GetProcAddress(
                                                                                                    hModule: LibraryA,
                                                                                                    lpProcName: "DirectSoundCaptureCreate");
    if ( DirectSoundCaptureCreate != nullptr )
    {
      pGuid = &DSDEVID_DefaultVoiceCapture;
      if ( IsRunningWindows7() )
        pGuid = nullptr;
      if ( DirectSoundCaptureCreate(pcGuidDevice: pGuid, ppDSC: &this->m_pCapture, pUnkOuter: nullptr) >= 0 )
      {
        memset(&dscDesc.lpwfxFormat, 0, 12);
        memset((void *)&dscDesc, 0, 16);
        m_pCapture = this->m_pCapture;
        dscDesc.lpwfxFormat = &recordFormat;
        p_m_pCaptureBuffer = &this->m_pCaptureBuffer;
        dscDesc.dwSize = 28;
        dscDesc.dwBufferBytes = recordFormat.nAvgBytesPerSec;
        if ( m_pCapture->CreateCaptureBuffer(this: m_pCapture, a2: &dscDesc, a3: &this->m_pCaptureBuffer, a4: nullptr) >= 0 )
        {
          memset(&caps, 0, sizeof(caps));
          v7 = *p_m_pCaptureBuffer;
          caps.dwSize = 16;
          if ( v7->GetCaps(this: v7, a2: &caps) >= 0 )
          {
            this->m_nCaptureBufferBytes = caps.dwBufferBytes;
            EventA = CreateEventA(
                       lpEventAttributes: nullptr,
                       bManualReset: false,
                       bInitialState: false,
                       lpName: nullptr);
            this->m_hWrapEvent = EventA;
            if ( EventA != nullptr )
            {
              dsbNotify.dwOffset = dscDesc.dwBufferBytes - 1;
              dsbNotify.hEventNotify = EventA;
              if ( (*p_m_pCaptureBuffer)->QueryInterface(
                     this: *p_m_pCaptureBuffer,
                     a2: &IID_IDirectSoundNotify,
                     a3: (void **)&pNotify) >= 0 )
              {
                v9 = pNotify->SetNotificationPositions(this: pNotify, a2: 1u, a3: &dsbNotify);
                pNotify->Release(this: pNotify);
                if ( v9 >= 0 )
                  return (*p_m_pCaptureBuffer)->Start(this: *p_m_pCaptureBuffer, a2: 1u) >= 0;
              }
            }
          }
        }
      }
    }
  }
  VoiceRecord_DSound::Term(this);
  return false;
}

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x10056F60
// Name: public: virtual void VoiceRecord_DSound::Release(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall VoiceRecord_DSound::Release(VoiceRecord_DSound *this)
{
  if ( this != nullptr )
    ((void (__thiscall *)(VoiceRecord_DSound *, int))this->dtr_IVoiceRecord)(a1: this, a2: 1);
}

//------------------------------------------------------------------------------
// Address: 0x10056F70
// Name: IsRunningWindows7
// Source: json
//------------------------------------------------------------------------------
bool __cdecl IsRunningWindows7()
{
  _OSVERSIONINFOEXA osvi; // [esp+0h] [ebp-9Ch] BYREF

  memset(dst: (unsigned __int8 *)&osvi, value: 0, count: sizeof(osvi));
  osvi.dwOSVersionInfoSize = 156;
  return GetVersionExA(lpVersionInformation: (LPOSVERSIONINFOA)&osvi)
      && (osvi.dwMajorVersion > 6 || osvi.dwMajorVersion == 6 && osvi.dwMinorVersion != 0);
}

//------------------------------------------------------------------------------
// Address: 0x10056FD0
// Name: public: virtual int VoiceRecord_DSound::GetRecordedData(short __near *,int)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall VoiceRecord_DSound::GetRecordedData(
        VoiceRecord_DSound *this,
        __int16 *pOut,
        unsigned int nSamples)
{
  IDirectSoundCaptureBuffer *m_pCaptureBuffer; // eax
  int v6; // edi
  unsigned int v7; // ecx
  unsigned int m_LastReadPos; // eax
  unsigned int v9; // edi
  unsigned int v10; // eax
  void *pData[2]; // [esp+4h] [ebp-18h] BYREF
  unsigned int dataLen[2]; // [esp+Ch] [ebp-10h] BYREF
  unsigned int dwStatus; // [esp+14h] [ebp-8h] BYREF
  unsigned int dwReadPos; // [esp+18h] [ebp-4h] BYREF
  unsigned int nBytesWanted; // [esp+28h] [ebp+Ch]

  m_pCaptureBuffer = this->m_pCaptureBuffer;
  if ( m_pCaptureBuffer == nullptr
    || m_pCaptureBuffer->GetStatus(this: m_pCaptureBuffer, a2: &dwStatus) < 0
    || (dwStatus & 1) == 0 )
  {
    return 0;
  }
  this->Idle(this);
  v6 = 2 * nSamples;
  nBytesWanted = 2 * nSamples;
  if ( this->m_pCaptureBuffer->GetCurrentPosition(this: this->m_pCaptureBuffer, a2: nullptr, a3: &dwReadPos) < 0 )
    return 0;
  v7 = this->m_WrapOffset + dwReadPos;
  m_LastReadPos = v7 != v6 ? v7 - v6 : 0;
  if ( m_LastReadPos < this->m_LastReadPos )
    m_LastReadPos = this->m_LastReadPos;
  dwReadPos += this->m_WrapOffset;
  if ( this->m_pCaptureBuffer->Lock(
         this: this->m_pCaptureBuffer,
         a2: m_LastReadPos % this->m_nCaptureBufferBytes,
         a3: v7 - m_LastReadPos,
         a4: pData,
         a5: dataLen,
         a6: &pData[1],
         a7: &dataLen[1],
         a8: 0) < 0 )
    return 0;
  v9 = dataLen[0];
  if ( dataLen[1] + dataLen[0] > nBytesWanted )
  {
    this->m_pCaptureBuffer->Unlock(
      this: this->m_pCaptureBuffer,
      a2: pData[0],
      a3: dataLen[0],
      a4: pData[1],
      a5: dataLen[1]);
    return 0;
  }
  memcpy(dst: (unsigned __int8 *)pOut, src: (unsigned __int8 *)pData[0], count: dataLen[0]);
  memcpy(dst: (unsigned __int8 *)&pOut[v9 >> 1], src: (unsigned __int8 *)pData[1], count: dataLen[1]);
  this->m_pCaptureBuffer->Unlock(
    this: this->m_pCaptureBuffer,
    a2: pData[0],
    a3: dataLen[0],
    a4: pData[1],
    a5: dataLen[1]);
  v10 = dataLen[0] + dataLen[1];
  this->m_LastReadPos = dwReadPos;
  return v10 >> 1;
}

//------------------------------------------------------------------------------
// Address: 0x10057100
// Name: private: void VoiceRecord_DSound::Term(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall VoiceRecord_DSound::Term(VoiceRecord_DSound *this)
{
  IDirectSoundCaptureBuffer *m_pCaptureBuffer; // eax
  IDirectSoundCapture *m_pCapture; // eax

  m_pCaptureBuffer = this->m_pCaptureBuffer;
  if ( m_pCaptureBuffer != nullptr )
    m_pCaptureBuffer->Release(this: m_pCaptureBuffer);
  m_pCapture = this->m_pCapture;
  if ( m_pCapture != nullptr )
    m_pCapture->Release(this: this->m_pCapture);
  if ( this->m_hWrapEvent != nullptr )
    DeleteObject(ho: this->m_hWrapEvent);
  if ( this->m_hInstDS != nullptr )
  {
    FreeLibrary(hLibModule: this->m_hInstDS);
    this->m_hInstDS = nullptr;
  }
  this->m_pCapture = nullptr;
  this->m_pCaptureBuffer = nullptr;
  this->m_WrapOffset = 0;
  this->m_LastReadPos = 0;
  this->m_hWrapEvent = nullptr;
  this->m_hInstDS = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10057160
// Name: public: virtual void VoiceRecord_DSound::Idle(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall VoiceRecord_DSound::Idle(VoiceRecord_DSound *this)
{
  if ( this->m_pCaptureBuffer != nullptr && WaitForSingleObject(hHandle: this->m_hWrapEvent, dwMilliseconds: 0) == 0 )
    this->m_WrapOffset += this->m_nCaptureBufferBytes;
}

//------------------------------------------------------------------------------
// Address: 0x10057190
// Name: class IVoiceRecord __near * CreateVoiceRecord_DSound(int)
// Source: json
//------------------------------------------------------------------------------
IVoiceRecord *__cdecl CreateVoiceRecord_DSound(int sampleRate)
{
  _DWORD *v1; // esi

  v1 = MemAlloc_Alloc(nSize: 0x20u);
  if ( v1 != nullptr )
  {
    *v1 = &VoiceRecord_DSound::`vftable';
    v1[2] = 0;
    v1[3] = 0;
    v1[5] = 0;
    v1[7] = 0;
    v1[6] = 0;
    v1[1] = 0;
    if ( (*(unsigned __int8 (__thiscall **)(_DWORD *, int))(*v1 + 24))(a1: v1, a2: sampleRate) != 0 )
      return (IVoiceRecord *)v1;
    (*(void (__thiscall **)(_DWORD *))(*v1 + 4))(a1: v1);
  }
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x100571F0
// Name: public: virtual bool VoiceRecord_DSound::Init(int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall VoiceRecord_DSound::Init(VoiceRecord_DSound *this, unsigned int sampleRate)
{
  HINSTANCE__ *LibraryA; // eax
  HRESULT (__stdcall *DirectSoundCaptureCreate)(LPCGUID, LPDIRECTSOUNDCAPTURE *, LPUNKNOWN); // edi
  IDirectSoundCapture *m_pCapture; // eax
  IDirectSoundCaptureBuffer **p_m_pCaptureBuffer; // edi
  IDirectSoundCaptureBuffer *v7; // eax
  HANDLE EventA; // eax
  int v9; // ebx
  _DSCBUFFERDESC dscDesc; // [esp+Ch] [ebp-4Ch] BYREF
  tWAVEFORMATEX recordFormat; // [esp+28h] [ebp-30h] BYREF
  _DSCBCAPS caps; // [esp+3Ch] [ebp-1Ch] BYREF
  _DSBPOSITIONNOTIFY dsbNotify; // [esp+4Ch] [ebp-Ch] BYREF
  IDirectSoundNotify *pNotify; // [esp+54h] [ebp-4h] BYREF
  _GUID *pGuid; // [esp+60h] [ebp+8h]

  VoiceRecord_DSound::Term(this);
  recordFormat.nAvgBytesPerSec = 2 * sampleRate;
  *(_DWORD *)&recordFormat.wFormatTag = 65537;
  recordFormat.nSamplesPerSec = sampleRate;
  *(_DWORD *)&recordFormat.nBlockAlign = 1048578;
  recordFormat.cbSize = 18;
  LibraryA = LoadLibraryA(lpLibFileName: "dsound.dll");
  this->m_hInstDS = LibraryA;
  if ( LibraryA != nullptr )
  {
    DirectSoundCaptureCreate = (HRESULT (__stdcall *)(LPCGUID, LPDIRECTSOUNDCAPTURE *, LPUNKNOWN))GetProcAddress(
                                                                                                    hModule: LibraryA,
                                                                                                    lpProcName: "DirectSoundCaptureCreate");
    if ( DirectSoundCaptureCreate != nullptr )
    {
      pGuid = &DSDEVID_DefaultVoiceCapture;
      if ( IsRunningWindows7() )
        pGuid = nullptr;
      if ( DirectSoundCaptureCreate(pcGuidDevice: pGuid, ppDSC: &this->m_pCapture, pUnkOuter: nullptr) >= 0 )
      {
        memset(&dscDesc.lpwfxFormat, 0, 12);
        memset((void *)&dscDesc, 0, 16);
        m_pCapture = this->m_pCapture;
        dscDesc.lpwfxFormat = &recordFormat;
        p_m_pCaptureBuffer = &this->m_pCaptureBuffer;
        dscDesc.dwSize = 28;
        dscDesc.dwBufferBytes = recordFormat.nAvgBytesPerSec;
        if ( m_pCapture->CreateCaptureBuffer(this: m_pCapture, a2: &dscDesc, a3: &this->m_pCaptureBuffer, a4: nullptr) >= 0 )
        {
          memset(&caps, 0, sizeof(caps));
          v7 = *p_m_pCaptureBuffer;
          caps.dwSize = 16;
          if ( v7->GetCaps(this: v7, a2: &caps) >= 0 )
          {
            this->m_nCaptureBufferBytes = caps.dwBufferBytes;
            EventA = CreateEventA(
                       lpEventAttributes: nullptr,
                       bManualReset: false,
                       bInitialState: false,
                       lpName: nullptr);
            this->m_hWrapEvent = EventA;
            if ( EventA != nullptr )
            {
              dsbNotify.dwOffset = dscDesc.dwBufferBytes - 1;
              dsbNotify.hEventNotify = EventA;
              if ( (*p_m_pCaptureBuffer)->QueryInterface(
                     this: *p_m_pCaptureBuffer,
                     a2: &IID_IDirectSoundNotify,
                     a3: (void **)&pNotify) >= 0 )
              {
                v9 = pNotify->SetNotificationPositions(this: pNotify, a2: 1u, a3: &dsbNotify);
                pNotify->Release(this: pNotify);
                if ( v9 >= 0 )
                  return (*p_m_pCaptureBuffer)->Start(this: *p_m_pCaptureBuffer, a2: 1u) >= 0;
              }
            }
          }
        }
      }
    }
  }
  VoiceRecord_DSound::Term(this);
  return false;
}

} // namespace engine_xlsp

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x10310520
// Name: _dynamic_initializer_for__voice_steal__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__voice_steal__()
{
  ConVar::ConVar(this: &voice_steal, pName: "voice_steal", pDefaultValue: "2", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__voice_steal__);
}

//------------------------------------------------------------------------------
// Address: 0x103108D0
// Name: _dynamic_initializer_for__voice_minimum_gain__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__voice_minimum_gain__()
{
  ConVar::ConVar(this: &voice_minimum_gain, pName: "voice_minimum_gain", pDefaultValue: "0.5", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__voice_minimum_gain__);
}

//------------------------------------------------------------------------------
// Address: 0x10312260
// Name: _dynamic_initializer_for__voice_avggain__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__voice_avggain__()
{
  ConVar::ConVar(this: &voice_avggain, pName: "voice_avggain", pDefaultValue: "0.5", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__voice_avggain__);
}

//------------------------------------------------------------------------------
// Address: 0x10312290
// Name: _dynamic_initializer_for__voice_maxgain__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__voice_maxgain__()
{
  ConVar::ConVar(this: &voice_maxgain, pName: "voice_maxgain", pDefaultValue: "10", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__voice_maxgain__);
}

//------------------------------------------------------------------------------
// Address: 0x103122C0
// Name: _dynamic_initializer_for__voice_scale__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__voice_scale__()
{
  ConVar::ConVar(this: &voice_scale, pName: "voice_scale", pDefaultValue: "1", flags: 128);
  return atexit(func: dynamic_atexit_destructor_for__voice_scale__);
}

//------------------------------------------------------------------------------
// Address: 0x103122F0
// Name: _dynamic_initializer_for__voice_loopback__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__voice_loopback__()
{
  ConVar::ConVar(this: &voice_loopback, pName: "voice_loopback", pDefaultValue: "0", flags: 512);
  return atexit(func: dynamic_atexit_destructor_for__voice_loopback__);
}

//------------------------------------------------------------------------------
// Address: 0x10312320
// Name: _dynamic_initializer_for__voice_fadeouttime__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__voice_fadeouttime__()
{
  ConVar::ConVar(this: &voice_fadeouttime, pName: "voice_fadeouttime", pDefaultValue: "0.1", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__voice_fadeouttime__);
}

//------------------------------------------------------------------------------
// Address: 0x10312350
// Name: _dynamic_initializer_for__voice_threshold_delay__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__voice_threshold_delay__()
{
  ConVar::ConVar(this: &voice_threshold_delay, pName: "voice_thresold_delay", pDefaultValue: "0.5", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__voice_threshold_delay__);
}

//------------------------------------------------------------------------------
// Address: 0x10312380
// Name: _dynamic_initializer_for__voice_profile__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__voice_profile__()
{
  ConVar::ConVar(this: &voice_profile, pName: "voice_profile", pDefaultValue: "0", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__voice_profile__);
}

//------------------------------------------------------------------------------
// Address: 0x103123B0
// Name: _dynamic_initializer_for__voice_showchannels__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__voice_showchannels__()
{
  ConVar::ConVar(this: &voice_showchannels, pName: "voice_showchannels", pDefaultValue: "0", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__voice_showchannels__);
}

//------------------------------------------------------------------------------
// Address: 0x103123E0
// Name: _dynamic_initializer_for__voice_showincoming__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__voice_showincoming__()
{
  ConVar::ConVar(this: &voice_showincoming, pName: "voice_showincoming", pDefaultValue: "0", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__voice_showincoming__);
}

//------------------------------------------------------------------------------
// Address: 0x10312410
// Name: _dynamic_initializer_for__voice_enable__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__voice_enable__()
{
  ConVar::ConVar(
    this: &voice_enable,
    pName: "voice_enable",
    pDefaultValue: "1",
    flags: 128,
    pHelpString: "Toggle voice transmit and receive.",
    callback: VoiceEnableCallback);
  return atexit(func: dynamic_atexit_destructor_for__voice_enable__);
}

//------------------------------------------------------------------------------
// Address: 0x10312440
// Name: _dynamic_initializer_for__voice_threshold__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__voice_threshold__()
{
  ConVar::ConVar(this: &voice_threshold, pName: "voice_threshold", pDefaultValue: "2000", flags: 128);
  return atexit(func: dynamic_atexit_destructor_for__voice_threshold__);
}

//------------------------------------------------------------------------------
// Address: 0x10312470
// Name: _dynamic_initializer_for__voice_forcemicrecord__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__voice_forcemicrecord__()
{
  ConVar::ConVar(this: &voice_forcemicrecord, pName: "voice_forcemicrecord", pDefaultValue: "1", flags: 128);
  return atexit(func: dynamic_atexit_destructor_for__voice_forcemicrecord__);
}

//------------------------------------------------------------------------------
// Address: 0x103124F0
// Name: _dynamic_initializer_for__voice_writevoices__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__voice_writevoices__()
{
  ConVar::ConVar(
    this: &voice_writevoices,
    pName: "voice_writevoices",
    pDefaultValue: "0",
    flags: 0,
    pHelpString: "Saves each speaker's voice data into separate .wav files\n");
  return atexit(func: dynamic_atexit_destructor_for__voice_writevoices__);
}

//------------------------------------------------------------------------------
// Address: 0x10312530
// Name: _dynamic_initializer_for__voice_mixer_mute__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__voice_mixer_mute__()
{
  ConVar::ConVar(this: &voice_mixer_mute, pName: "voice_mixer_mute", pDefaultValue: "0", flags: 128);
  return atexit(func: dynamic_atexit_destructor_for__voice_mixer_mute__);
}

//------------------------------------------------------------------------------
// Address: 0x10312560
// Name: _dynamic_initializer_for__voice_mixer_boost__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__voice_mixer_boost__()
{
  ConVar::ConVar(this: &voice_mixer_boost, pName: "voice_mixer_boost", pDefaultValue: "0", flags: 128);
  return atexit(func: dynamic_atexit_destructor_for__voice_mixer_boost__);
}

//------------------------------------------------------------------------------
// Address: 0x10312590
// Name: _dynamic_initializer_for__voice_mixer_volume__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__voice_mixer_volume__()
{
  ConVar::ConVar(this: &voice_mixer_volume, pName: "voice_mixer_volume", pDefaultValue: "1.0", flags: 128);
  return atexit(func: dynamic_atexit_destructor_for__voice_mixer_volume__);
}

//------------------------------------------------------------------------------
// Address: 0x103125F0
// Name: _dynamic_initializer_for__voice_overdrive__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__voice_overdrive__()
{
  ConVar::ConVar(this: &voice_overdrive, pName: "voice_overdrive", pDefaultValue: "2", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__voice_overdrive__);
}

//------------------------------------------------------------------------------
// Address: 0x10312620
// Name: _dynamic_initializer_for__voice_overdrivefadetime__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__voice_overdrivefadetime__()
{
  ConVar::ConVar(this: &voice_overdrivefadetime, pName: "voice_overdrivefadetime", pDefaultValue: "0.4", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__voice_overdrivefadetime__);
}

//------------------------------------------------------------------------------
// Address: 0x10318390
// Name: _dynamic_initializer_for__voice_debugfeedbackfrom__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__voice_debugfeedbackfrom__()
{
  ConVar::ConVar(this: &voice_debugfeedbackfrom, pName: "voice_debugfeedbackfrom", pDefaultValue: "0", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__voice_debugfeedbackfrom__);
}

//------------------------------------------------------------------------------
// Address: 0x1031B100
// Name: _dynamic_initializer_for__voice_recordtofile__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__voice_recordtofile__()
{
  ConVar::ConVar(
    this: &voice_recordtofile,
    pName: "voice_recordtofile",
    pDefaultValue: "0",
    flags: 0x80000,
    pHelpString: "Record mic data and decompressed voice data into 'voice_micdata.wav' and 'voice_decompressed.wav'");
  return atexit(func: dynamic_atexit_destructor_for__voice_recordtofile__);
}

//------------------------------------------------------------------------------
// Address: 0x1031B130
// Name: _dynamic_initializer_for__voice_inputfromfile__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__voice_inputfromfile__()
{
  ConVar::ConVar(
    this: &voice_inputfromfile,
    pName: "voice_inputfromfile",
    pDefaultValue: "0",
    flags: 0x80000,
    pHelpString: "Get voice input from 'voice_input.wav' rather than from the microphone.");
  return atexit(func: dynamic_atexit_destructor_for__voice_inputfromfile__);
}

//------------------------------------------------------------------------------
// Address: 0x1031B580
// Name: _dynamic_initializer_for__voice_vox__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__voice_vox__()
{
  ConVar::ConVar(this: &voice_vox, pName: "voice_vox", pDefaultValue: "false", flags: 2);
  return atexit(func: dynamic_atexit_destructor_for__voice_vox__);
}

//------------------------------------------------------------------------------
// Address: 0x1031CEB0
// Name: _dynamic_initializer_for__voice_verbose__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__voice_verbose__()
{
  ConVar::ConVar(
    this: &voice_verbose,
    pName: "voice_verbose",
    pDefaultValue: "0",
    flags: 2,
    pHelpString: "Turns on debug output with detailed spew about voice data processing.");
  return atexit(func: dynamic_atexit_destructor_for__voice_verbose__);
}

//------------------------------------------------------------------------------
// Address: 0x1031CEE0
// Name: _dynamic_initializer_for__voice_xsend_debug__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__voice_xsend_debug__()
{
  ConVar::ConVar(this: &voice_xsend_debug, pName: "voice_xsend_debug", pDefaultValue: "0", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__voice_xsend_debug__);
}

//------------------------------------------------------------------------------
// Address: 0x1031D720
// Name: _dynamic_initializer_for__voice_debugfeedback__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__voice_debugfeedback__()
{
  ConVar::ConVar(this: &voice_debugfeedback, pName: "voice_debugfeedback", pDefaultValue: "0", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__voice_debugfeedback__);
}

//------------------------------------------------------------------------------
// Address: 0x10320E50
// Name: _dynamic_atexit_destructor_for__voice_steal__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__voice_steal__()
{
  ConVar::~ConVar(this: &voice_steal);
}

//------------------------------------------------------------------------------
// Address: 0x10320F70
// Name: _dynamic_atexit_destructor_for__voice_minimum_gain__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__voice_minimum_gain__()
{
  ConVar::~ConVar(this: &voice_minimum_gain);
}

//------------------------------------------------------------------------------
// Address: 0x103221A0
// Name: _dynamic_atexit_destructor_for__voice_avggain__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__voice_avggain__()
{
  ConVar::~ConVar(this: &voice_avggain);
}

//------------------------------------------------------------------------------
// Address: 0x103221B0
// Name: _dynamic_atexit_destructor_for__voice_maxgain__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__voice_maxgain__()
{
  ConVar::~ConVar(this: &voice_maxgain);
}

//------------------------------------------------------------------------------
// Address: 0x103221C0
// Name: _dynamic_atexit_destructor_for__voice_scale__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__voice_scale__()
{
  ConVar::~ConVar(this: &voice_scale);
}

//------------------------------------------------------------------------------
// Address: 0x103221D0
// Name: _dynamic_atexit_destructor_for__voice_loopback__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__voice_loopback__()
{
  ConVar::~ConVar(this: &voice_loopback);
}

//------------------------------------------------------------------------------
// Address: 0x103221E0
// Name: _dynamic_atexit_destructor_for__voice_fadeouttime__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__voice_fadeouttime__()
{
  ConVar::~ConVar(this: &voice_fadeouttime);
}

//------------------------------------------------------------------------------
// Address: 0x103221F0
// Name: _dynamic_atexit_destructor_for__voice_threshold_delay__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__voice_threshold_delay__()
{
  ConVar::~ConVar(this: &voice_threshold_delay);
}

//------------------------------------------------------------------------------
// Address: 0x10322200
// Name: _dynamic_atexit_destructor_for__voice_profile__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__voice_profile__()
{
  ConVar::~ConVar(this: &voice_profile);
}

//------------------------------------------------------------------------------
// Address: 0x10322210
// Name: _dynamic_atexit_destructor_for__voice_showchannels__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__voice_showchannels__()
{
  ConVar::~ConVar(this: &voice_showchannels);
}

//------------------------------------------------------------------------------
// Address: 0x10322220
// Name: _dynamic_atexit_destructor_for__voice_showincoming__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__voice_showincoming__()
{
  ConVar::~ConVar(this: &voice_showincoming);
}

//------------------------------------------------------------------------------
// Address: 0x10322230
// Name: _dynamic_atexit_destructor_for__voice_enable__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__voice_enable__()
{
  ConVar::~ConVar(this: &voice_enable);
}

//------------------------------------------------------------------------------
// Address: 0x10322240
// Name: _dynamic_atexit_destructor_for__voice_threshold__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__voice_threshold__()
{
  ConVar::~ConVar(this: &voice_threshold);
}

//------------------------------------------------------------------------------
// Address: 0x10322250
// Name: _dynamic_atexit_destructor_for__voice_forcemicrecord__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__voice_forcemicrecord__()
{
  ConVar::~ConVar(this: &voice_forcemicrecord);
}

//------------------------------------------------------------------------------
// Address: 0x10322260
// Name: _dynamic_atexit_destructor_for__voice_writevoices__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__voice_writevoices__()
{
  ConVar::~ConVar(this: &voice_writevoices);
}

//------------------------------------------------------------------------------
// Address: 0x10322280
// Name: _dynamic_atexit_destructor_for__voice_mixer_mute__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__voice_mixer_mute__()
{
  ConVar::~ConVar(this: &voice_mixer_mute);
}

//------------------------------------------------------------------------------
// Address: 0x10322290
// Name: _dynamic_atexit_destructor_for__voice_mixer_boost__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__voice_mixer_boost__()
{
  ConVar::~ConVar(this: &voice_mixer_boost);
}

//------------------------------------------------------------------------------
// Address: 0x103222A0
// Name: _dynamic_atexit_destructor_for__voice_mixer_volume__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__voice_mixer_volume__()
{
  ConVar::~ConVar(this: &voice_mixer_volume);
}

//------------------------------------------------------------------------------
// Address: 0x103222B0
// Name: _dynamic_atexit_destructor_for__voice_overdrive__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__voice_overdrive__()
{
  ConVar::~ConVar(this: &voice_overdrive);
}

//------------------------------------------------------------------------------
// Address: 0x103222C0
// Name: _dynamic_atexit_destructor_for__voice_overdrivefadetime__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__voice_overdrivefadetime__()
{
  ConVar::~ConVar(this: &voice_overdrivefadetime);
}

//------------------------------------------------------------------------------
// Address: 0x103247D0
// Name: _dynamic_atexit_destructor_for__voice_debugfeedbackfrom__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__voice_debugfeedbackfrom__()
{
  ConVar::~ConVar(this: &voice_debugfeedbackfrom);
}

//------------------------------------------------------------------------------
// Address: 0x103259C0
// Name: _dynamic_atexit_destructor_for__voice_recordtofile__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__voice_recordtofile__()
{
  ConVar::~ConVar(this: &voice_recordtofile);
}

//------------------------------------------------------------------------------
// Address: 0x103259D0
// Name: _dynamic_atexit_destructor_for__voice_inputfromfile__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__voice_inputfromfile__()
{
  ConVar::~ConVar(this: &voice_inputfromfile);
}

//------------------------------------------------------------------------------
// Address: 0x10325B40
// Name: _dynamic_atexit_destructor_for__voice_vox__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__voice_vox__()
{
  ConVar::~ConVar(this: &voice_vox);
}

//------------------------------------------------------------------------------
// Address: 0x10326510
// Name: _dynamic_atexit_destructor_for__voice_verbose__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__voice_verbose__()
{
  ConVar::~ConVar(this: &voice_verbose);
}

//------------------------------------------------------------------------------
// Address: 0x10326520
// Name: _dynamic_atexit_destructor_for__voice_xsend_debug__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__voice_xsend_debug__()
{
  ConVar::~ConVar(this: &voice_xsend_debug);
}

//------------------------------------------------------------------------------
// Address: 0x103268A0
// Name: _dynamic_atexit_destructor_for__voice_debugfeedback__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__voice_debugfeedback__()
{
  ConVar::~ConVar(this: &voice_debugfeedback);
}

//------------------------------------------------------------------------------
// Address: 0x10310550
// Name: _dynamic_initializer_for__dsp_dist_min__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__dsp_dist_min__()
{
  ConVar::ConVar(this: &dsp_dist_min, pName: "dsp_dist_min", pDefaultValue: "0.0", flags: 81920);
  return atexit(func: dynamic_atexit_destructor_for__dsp_dist_min__);
}

//------------------------------------------------------------------------------
// Address: 0x10310580
// Name: _dynamic_initializer_for__dsp_dist_max__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__dsp_dist_max__()
{
  ConVar::ConVar(this: &dsp_dist_max, pName: "dsp_dist_max", pDefaultValue: "1440.0", flags: 81920);
  return atexit(func: dynamic_atexit_destructor_for__dsp_dist_max__);
}

//------------------------------------------------------------------------------
// Address: 0x103105B0
// Name: _dynamic_initializer_for__dsp_mix_min__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__dsp_mix_min__()
{
  ConVar::ConVar(this: &dsp_mix_min, pName: "dsp_mix_min", pDefaultValue: "0.2", flags: 0x10000);
  return atexit(func: dynamic_atexit_destructor_for__dsp_mix_min__);
}

//------------------------------------------------------------------------------
// Address: 0x103105E0
// Name: _dynamic_initializer_for__dsp_mix_max__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__dsp_mix_max__()
{
  ConVar::ConVar(this: &dsp_mix_max, pName: "dsp_mix_max", pDefaultValue: "0.8", flags: 0x10000);
  return atexit(func: dynamic_atexit_destructor_for__dsp_mix_max__);
}

//------------------------------------------------------------------------------
// Address: 0x10310610
// Name: _dynamic_initializer_for__dsp_db_min__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__dsp_db_min__()
{
  ConVar::ConVar(this: &dsp_db_min, pName: "dsp_db_min", pDefaultValue: "80", flags: 0x10000);
  return atexit(func: dynamic_atexit_destructor_for__dsp_db_min__);
}

//------------------------------------------------------------------------------
// Address: 0x10310640
// Name: _dynamic_initializer_for__dsp_db_mixdrop__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__dsp_db_mixdrop__()
{
  ConVar::ConVar(this: &dsp_db_mixdrop, pName: "dsp_db_mixdrop", pDefaultValue: "0.5", flags: 0x10000);
  return atexit(func: dynamic_atexit_destructor_for__dsp_db_mixdrop__);
}

//------------------------------------------------------------------------------
// Address: 0x103124A0
// Name: _dynamic_initializer_for__g_VoiceChannels__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CAutoGain *dynamic_initializer_for__g_VoiceChannels__()
{
  int v0; // ebx
  CAutoGain *p_m_AutoGain; // esi
  CAutoGain *result; // eax

  v0 = 4;
  p_m_AutoGain = &g_VoiceChannels[0].m_AutoGain;
  do
  {
    CCircularBuffer::CCircularBuffer(this: (CCircularBuffer *)&p_m_AutoGain[-503].m_FixedCurrentGain, size: 22050);
    result = CAutoGain::CAutoGain(this: p_m_AutoGain);
    p_m_AutoGain[-503].m_NextGain = NAN;
    p_m_AutoGain[-1].m_GainMultiplier = 0;
    p_m_AutoGain[1].m_AvgToMaxVal = NAN;
    p_m_AutoGain[1].m_CurBlockOffset = -1;
    p_m_AutoGain = (CAutoGain *)((char *)p_m_AutoGain + 22160);
    --v0;
  }
  while ( v0 >= 0 );
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10312520
// Name: _dynamic_initializer_for__g_VoiceWriter__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_VoiceWriter__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_VoiceWriter__);
}

//------------------------------------------------------------------------------
// Address: 0x103125C0
// Name: _dynamic_initializer_for__g_CVoiceSfx__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CSfxTable *dynamic_initializer_for__g_CVoiceSfx__()
{
  CSfxTable *v0; // esi
  int i; // edi
  CSfxTable *result; // eax

  v0 = &g_CVoiceSfx;
  for ( i = 4; i >= 0; --i )
  {
    result = CSfxTable::CSfxTable(this: v0);
    v0->__vftable = (CSfxTable_vtbl *)&CVoiceSfx::`vftable';
    ++v0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10312650
// Name: _dynamic_initializer_for__g_Sentences__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_Sentences__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_Sentences__);
}

//------------------------------------------------------------------------------
// Address: 0x10312660
// Name: _dynamic_initializer_for__vox_reload__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__vox_reload__()
{
  ConCommand::ConCommand(
    this: &vox_reload,
    pName: "vox_reload",
    callback: VOX_Reload,
    pHelpString: "Reload sentences.txt file",
    flags: 0x4000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__vox_reload__);
}

//------------------------------------------------------------------------------
// Address: 0x10312690
// Name: _dynamic_initializer_for__g_GroupLRU__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_GroupLRU__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_GroupLRU__);
}

//------------------------------------------------------------------------------
// Address: 0x103126A0
// Name: _dynamic_initializer_for__g_SentenceFile__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_SentenceFile__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_SentenceFile__);
}

//------------------------------------------------------------------------------
// Address: 0x103126B0
// Name: _dynamic_initializer_for__g_SentenceGroups__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_SentenceGroups__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_SentenceGroups__);
}

//------------------------------------------------------------------------------
// Address: 0x103126C0
// Name: _dynamic_initializer_for__sentencegroup_t::s_SymbolTable__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__sentencegroup_t::s_SymbolTable__()
{
  CUtlSymbolTable::CUtlSymbolTable(
    this: &sentencegroup_t::s_SymbolTable,
    growSize: 0,
    initSize: 256,
    caseInsensitive: true);
  return atexit(func: dynamic_atexit_destructor_for__sentencegroup_t::s_SymbolTable__);
}

//------------------------------------------------------------------------------
// Address: 0x103183C0
// Name: _dynamic_initializer_for__setmaster__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__setmaster__()
{
  ConCommand::ConCommand(
    this: &setmaster,
    pName: "setmaster",
    callback: SetMaster_f,
    pHelpString: "add/remove/enable/disable master servers",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__setmaster__);
}

//------------------------------------------------------------------------------
// Address: 0x103183F0
// Name: _dynamic_initializer_for__heartbeat__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__heartbeat__()
{
  ConCommand::ConCommand(
    this: &heartbeat,
    pName: "heartbeat",
    callback: Heartbeat_f,
    pHelpString: "Force heartbeat of master servers",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__heartbeat__);
}

//------------------------------------------------------------------------------
// Address: 0x1031B160
// Name: _dynamic_initializer_for___restart_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for___restart_command__()
{
  ConCommand::ConCommand(
    this: &restart_command,
    pName: "_restart",
    callback: restart,
    pHelpString: "Shutdown and restart the engine.",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for___restart_command__);
}

//------------------------------------------------------------------------------
// Address: 0x1031B5B0
// Name: _dynamic_initializer_for__listmodels_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__listmodels_command__()
{
  ConCommand::ConCommand(
    this: &listmodels_command,
    pName: "listmodels",
    callback: listmodels,
    pHelpString: "List loaded models.",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__listmodels_command__);
}

//------------------------------------------------------------------------------
// Address: 0x1031B5E0
// Name: _dynamic_initializer_for__incrementvar_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__incrementvar_command__()
{
  ConCommand::ConCommand(
    this: &incrementvar_command,
    pName: "incrementvar",
    callback: incrementvar,
    pHelpString: "Increment specified convar value.",
    flags: 0x20000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__incrementvar_command__);
}

//------------------------------------------------------------------------------
// Address: 0x1031B610
// Name: _dynamic_initializer_for__multvar_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__multvar_command__()
{
  ConCommand::ConCommand(
    this: &multvar_command,
    pName: "multvar",
    callback: multvar,
    pHelpString: "Multiply specified convar value.",
    flags: 0x20000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__multvar_command__);
}

//------------------------------------------------------------------------------
// Address: 0x1031B640
// Name: _dynamic_initializer_for__dumpstringtables_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__dumpstringtables_command__()
{
  ConCommand::ConCommand(
    this: &dumpstringtables_command,
    pName: "dumpstringtables",
    callback: dumpstringtables,
    pHelpString: "Print string tables to console.",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__dumpstringtables_command__);
}

//------------------------------------------------------------------------------
// Address: 0x1031B670
// Name: _dynamic_initializer_for__stringtabledictionary_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__stringtabledictionary_command__()
{
  ConCommand::ConCommand(
    this: &stringtabledictionary_command,
    pName: "stringtabledictionary",
    callback: stringtabledictionary,
    pHelpString: "Create dictionary for current strings.",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__stringtabledictionary_command__);
}

//------------------------------------------------------------------------------
// Address: 0x1031B6A0
// Name: _dynamic_initializer_for__quit__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__quit__()
{
  ConCommand::ConCommand(
    this: &quit,
    pName: "quit",
    callback: Host_Quit_f,
    pHelpString: "Exit the engine.",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__quit__);
}

//------------------------------------------------------------------------------
// Address: 0x1031B6D0
// Name: _dynamic_initializer_for__cmd_exit__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__cmd_exit__()
{
  ConCommand::ConCommand(
    this: &cmd_exit,
    pName: "exit",
    callback: Host_Quit_f,
    pHelpString: "Exit the engine.",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__cmd_exit__);
}

//------------------------------------------------------------------------------
// Address: 0x1031B700
// Name: _dynamic_initializer_for__startvoicerecord__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__startvoicerecord__()
{
  ConCommand::ConCommand(
    this: &startvoicerecord,
    pName: "+voicerecord",
    callback: Host_VoiceRecordStart_f,
    pHelpString: nullptr,
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__startvoicerecord__);
}

//------------------------------------------------------------------------------
// Address: 0x1031B730
// Name: _dynamic_initializer_for__endvoicerecord__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__endvoicerecord__()
{
  ConCommand::ConCommand(
    this: &endvoicerecord,
    pName: "-voicerecord",
    callback: Host_VoiceRecordStop_f,
    pHelpString: nullptr,
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__endvoicerecord__);
}

//------------------------------------------------------------------------------
// Address: 0x1031B760
// Name: _dynamic_initializer_for__togglevoicerecord__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__togglevoicerecord__()
{
  ConCommand::ConCommand(
    this: &togglevoicerecord,
    pName: "voicerecord_toggle",
    callback: Host_VoiceToggle_f,
    pHelpString: nullptr,
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__togglevoicerecord__);
}

//------------------------------------------------------------------------------
// Address: 0x1031B790
// Name: _dynamic_initializer_for__crash_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__crash_command__()
{
  ConCommand::ConCommand(
    this: &crash_command,
    pName: "crash",
    callback: crash,
    pHelpString: "Cause the engine to crash (Debug!!)",
    flags: 0x4000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__crash_command__);
}

//------------------------------------------------------------------------------
// Address: 0x1031B7C0
// Name: _dynamic_initializer_for__flush_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__flush_command__()
{
  ConCommand::ConCommand(
    this: &flush_command,
    pName: "flush",
    callback: flush,
    pHelpString: "Flush unlocked cache memory.",
    flags: 0x4000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__flush_command__);
}

//------------------------------------------------------------------------------
// Address: 0x1031B7F0
// Name: _dynamic_initializer_for__flush_locked_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__flush_locked_command__()
{
  ConCommand::ConCommand(
    this: &flush_locked_command,
    pName: "flush_locked",
    callback: flush_locked,
    pHelpString: "Flush unlocked and locked cache memory.",
    flags: 0x4000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__flush_locked_command__);
}

//------------------------------------------------------------------------------
// Address: 0x1031CF10
// Name: _dynamic_initializer_for__loopback_t::s_Allocator__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__loopback_t::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &loopback_t::s_Allocator,
    blockSize: 2056,
    numElements: 2,
    growMode: 2,
    pszAllocOwner: "loopback_t pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__loopback_t::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x10320E60
// Name: _dynamic_atexit_destructor_for__dsp_dist_min__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__dsp_dist_min__()
{
  ConVar::~ConVar(this: &dsp_dist_min);
}

//------------------------------------------------------------------------------
// Address: 0x10320E70
// Name: _dynamic_atexit_destructor_for__dsp_dist_max__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__dsp_dist_max__()
{
  ConVar::~ConVar(this: &dsp_dist_max);
}

//------------------------------------------------------------------------------
// Address: 0x10320E80
// Name: _dynamic_atexit_destructor_for__dsp_mix_min__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__dsp_mix_min__()
{
  ConVar::~ConVar(this: &dsp_mix_min);
}

//------------------------------------------------------------------------------
// Address: 0x10320E90
// Name: _dynamic_atexit_destructor_for__dsp_mix_max__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__dsp_mix_max__()
{
  ConVar::~ConVar(this: &dsp_mix_max);
}

//------------------------------------------------------------------------------
// Address: 0x10320EA0
// Name: _dynamic_atexit_destructor_for__dsp_db_min__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__dsp_db_min__()
{
  ConVar::~ConVar(this: &dsp_db_min);
}

//------------------------------------------------------------------------------
// Address: 0x10320EB0
// Name: _dynamic_atexit_destructor_for__dsp_db_mixdrop__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__dsp_db_mixdrop__()
{
  ConVar::~ConVar(this: &dsp_db_mixdrop);
}

//------------------------------------------------------------------------------
// Address: 0x10322270
// Name: _dynamic_atexit_destructor_for__g_VoiceWriter__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_VoiceWriter__()
{
  CUtlRBTree<CVoiceWriterData,unsigned short,bool (__cdecl *)(CVoiceWriterData const &,CVoiceWriterData const &),CUtlMemory<UtlRBTreeNode_t<CVoiceWriterData,unsigned short>,unsigned short>>::~CUtlRBTree<CVoiceWriterData,unsigned short,bool (__cdecl *)(CVoiceWriterData const &,CVoiceWriterData const &),CUtlMemory<UtlRBTreeNode_t<CVoiceWriterData,unsigned short>,unsigned short>>(this: &g_VoiceWriter.m_VoiceWriter);
}

//------------------------------------------------------------------------------
// Address: 0x103222D0
// Name: _dynamic_atexit_destructor_for__vox_reload__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__vox_reload__()
{
  ConCommand::~ConCommand(this: &vox_reload);
}

//------------------------------------------------------------------------------
// Address: 0x103222E0
// Name: _dynamic_atexit_destructor_for__sentencegroup_t::s_SymbolTable__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__sentencegroup_t::s_SymbolTable__()
{
  CUtlSymbolTable::~CUtlSymbolTable(this: &sentencegroup_t::s_SymbolTable);
}

//------------------------------------------------------------------------------
// Address: 0x103247E0
// Name: _dynamic_atexit_destructor_for__g_AreasNetworked__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_AreasNetworked__()
{
  CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&g_AreasNetworked);
}

//------------------------------------------------------------------------------
// Address: 0x103247F0
// Name: _dynamic_atexit_destructor_for__g_ClustersNetworked__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_ClustersNetworked__()
{
  CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&g_ClustersNetworked);
}

//------------------------------------------------------------------------------
// Address: 0x10324800
// Name: _dynamic_atexit_destructor_for__sv__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__sv__()
{
  CGameServer::~CGameServer(this: &sv);
}

//------------------------------------------------------------------------------
// Address: 0x10324810
// Name: _dynamic_atexit_destructor_for__setmaster__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__setmaster__()
{
  ConCommand::~ConCommand(this: &setmaster);
}

//------------------------------------------------------------------------------
// Address: 0x10324820
// Name: _dynamic_atexit_destructor_for__heartbeat__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__heartbeat__()
{
  ConCommand::~ConCommand(this: &heartbeat);
}

//------------------------------------------------------------------------------
// Address: 0x103259E0
// Name: _dynamic_atexit_destructor_for___restart_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for___restart_command__()
{
  ConCommand::~ConCommand(this: &restart_command);
}

//------------------------------------------------------------------------------
// Address: 0x10325B50
// Name: _dynamic_atexit_destructor_for__listmodels_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__listmodels_command__()
{
  ConCommand::~ConCommand(this: &listmodels_command);
}

//------------------------------------------------------------------------------
// Address: 0x10325B60
// Name: _dynamic_atexit_destructor_for__incrementvar_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__incrementvar_command__()
{
  ConCommand::~ConCommand(this: &incrementvar_command);
}

//------------------------------------------------------------------------------
// Address: 0x10325B70
// Name: _dynamic_atexit_destructor_for__multvar_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__multvar_command__()
{
  ConCommand::~ConCommand(this: &multvar_command);
}

//------------------------------------------------------------------------------
// Address: 0x10325B80
// Name: _dynamic_atexit_destructor_for__dumpstringtables_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__dumpstringtables_command__()
{
  ConCommand::~ConCommand(this: &dumpstringtables_command);
}

//------------------------------------------------------------------------------
// Address: 0x10325B90
// Name: _dynamic_atexit_destructor_for__stringtabledictionary_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__stringtabledictionary_command__()
{
  ConCommand::~ConCommand(this: &stringtabledictionary_command);
}

//------------------------------------------------------------------------------
// Address: 0x10325BA0
// Name: _dynamic_atexit_destructor_for__quit__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__quit__()
{
  ConCommand::~ConCommand(this: &quit);
}

//------------------------------------------------------------------------------
// Address: 0x10325BB0
// Name: _dynamic_atexit_destructor_for__cmd_exit__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cmd_exit__()
{
  ConCommand::~ConCommand(this: &cmd_exit);
}

//------------------------------------------------------------------------------
// Address: 0x10325BC0
// Name: _dynamic_atexit_destructor_for__startvoicerecord__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__startvoicerecord__()
{
  ConCommand::~ConCommand(this: &startvoicerecord);
}

//------------------------------------------------------------------------------
// Address: 0x10325BD0
// Name: _dynamic_atexit_destructor_for__endvoicerecord__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__endvoicerecord__()
{
  ConCommand::~ConCommand(this: &endvoicerecord);
}

//------------------------------------------------------------------------------
// Address: 0x10325BE0
// Name: _dynamic_atexit_destructor_for__togglevoicerecord__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__togglevoicerecord__()
{
  ConCommand::~ConCommand(this: &togglevoicerecord);
}

//------------------------------------------------------------------------------
// Address: 0x10325BF0
// Name: _dynamic_atexit_destructor_for__crash_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__crash_command__()
{
  ConCommand::~ConCommand(this: &crash_command);
}

//------------------------------------------------------------------------------
// Address: 0x10325C00
// Name: _dynamic_atexit_destructor_for__flush_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__flush_command__()
{
  ConCommand::~ConCommand(this: &flush_command);
}

//------------------------------------------------------------------------------
// Address: 0x10325C10
// Name: _dynamic_atexit_destructor_for__flush_locked_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__flush_locked_command__()
{
  ConCommand::~ConCommand(this: &flush_locked_command);
}

//------------------------------------------------------------------------------
// Address: 0x10326530
// Name: _dynamic_atexit_destructor_for__loopback_t::s_Allocator__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__loopback_t::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &loopback_t::s_Allocator);
}

} // namespace engine_xlsp
