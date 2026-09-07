// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: engine/enginesoundclient.cpp
// Functions: 28
// ============================================================

#include "engine\enginesoundclient.h"

//------------------------------------------------------------------------------
// Address: 0x100010E0
// Name: void __near * MemAlloc_Alloc(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void *__cdecl MemAlloc_Alloc(unsigned int nSize)
{
  return _g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: nSize);
}

//------------------------------------------------------------------------------
// Address: 0x10001100
// Name: public: void Vector::Init(float,float,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall Vector::Init(Vector *this, float ix, float iy, float iz)
{
  this->x = ix;
  this->y = iy;
  this->z = iz;
}

//------------------------------------------------------------------------------
// Address: 0x10001130
// Name: public: class Vector __near & Vector::operator=(class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
Vector *__thiscall Vector::operator=(Vector *this, const Vector *vOther)
{
  *this = *vOther;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10001150
// Name: public: StartSoundParams_t::StartSoundParams_t(void)
// Source: json
//------------------------------------------------------------------------------
StartSoundParams_t *__thiscall StartSoundParams_t::StartSoundParams_t(StartSoundParams_t *this)
{
  StartSoundParams_t *result; // eax
  char v2; // cl

  result = this;
  this->userdata = 0;
  this->soundsource = 0;
  this->entchannel = 0;
  this->pSfx = nullptr;
  this->flags = 0;
  this->initialStreamPosition = 0;
  this->skipInitialSamples = 0;
  this->m_pSoundEntryName = nullptr;
  this->m_pOperatorsKV = nullptr;
  v2 = *((_BYTE *)this + 96);
  result->fvol = 1.0;
  result->soundlevel = SNDLVL_NORM;
  result->pitch = 100;
  result->delay = 0.0;
  result->opStackElapsedTime = 0.0;
  result->opStackElapsedStopTime = 0.0;
  result->speakerentity = -1;
  result->m_nQueuedGUID = -1;
  result->m_nSoundScriptHandle = -1;
  *((_BYTE *)result + 96) = v2 & 0xC0 | 2;
  result->origin.x = 0.0;
  result->origin.y = 0.0;
  result->origin.z = 0.0;
  result->direction.x = 0.0;
  result->direction.y = 0.0;
  result->direction.z = 0.0;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100011E0
// Name: class IEngineSound __near * EngineSoundClient(void)
// Source: json
//------------------------------------------------------------------------------
CEngineSoundClient *__cdecl EngineSoundClient()
{
  return &s_EngineSoundClient;
}

//------------------------------------------------------------------------------
// Address: 0x100011F0
// Name: public: virtual bool CEngineSoundClient::PrecacheSound(char const __near *,bool,bool)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CEngineSoundClient::PrecacheSound(
        CEngineSoundClient *this,
        const char *pSample,
        bool bPreload,
        bool bIsUISound)
{
  CSfxTable *v4; // eax

  v4 = S_PrecacheSound(name: pSample);
  if ( v4 == nullptr )
    return 0;
  if ( bIsUISound )
    S_MarkUISound(pSfx: v4);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10001220
// Name: public: virtual void CEngineSoundClient::PrefetchSound(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineSoundClient::PrefetchSound(CEngineSoundClient *this, const char *pSample)
{
  S_PrefetchSound(name: pSample, bPlayOnce: true);
}

//------------------------------------------------------------------------------
// Address: 0x10001240
// Name: public: virtual bool CEngineSoundClient::IsSoundPrecached(char const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CEngineSoundClient::IsSoundPrecached(CEngineSoundClient *this, const char *pSample)
{
  CClientState *BaseLocalClient; // eax

  if ( pSample != nullptr && TestSoundChar(pch: pSample, c: 33) )
    return true;
  BaseLocalClient = GetBaseLocalClient();
  return CClientState::LookupSoundIndex(this: BaseLocalClient, name: pSample) != -1;
}

//------------------------------------------------------------------------------
// Address: 0x10001280
// Name: public: virtual bool CEngineSoundClient::IsLoopingSound(char const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CEngineSoundClient::IsLoopingSound(CEngineSoundClient *this, const char *pSample)
{
  CSfxTable *v2; // eax

  v2 = S_PrecacheSound(name: pSample);
  return v2 != nullptr && v2->pSource != nullptr && v2->pSource->IsLooped(this: v2->pSource);
}

//------------------------------------------------------------------------------
// Address: 0x100012B0
// Name: public: virtual int CEngineSoundClient::EmitSound(class IRecipientFilter __near &,int,int,char const __near *,int,char const __near *,float,float,int,int,int,class Vector const __near *,class Vector const __near *,class CUtlVector<class Vector,class CUtlMemory<class Vector,int>> __near *,bool,float,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CEngineSoundClient::EmitSound(
        CEngineSoundClient *this,
        IRecipientFilter *filter,
        int iEntIndex,
        int iChannel,
        const char *pSoundEntry,
        int iSoundEntryIndex,
        const char *pSample,
        float flVolume,
        float flAttenuation,
        int nSeed,
        int iFlags,
        int iPitch,
        IRecipientFilter *pOrigin,
        const Vector *pDirection,
        CUtlVector<Vector,CUtlMemory<Vector,int> > *pUtlVecOrigins,
        const char *bUpdatePositions,
        float soundtime,
        const char *speakerentity)
{
  float v18; // xmm0_4

  v18 = 0.0;
  if ( flAttenuation != 0.0 )
    v18 = (float)(20.0 / flAttenuation) + 50.0;
  return ((int (__stdcall *)(IRecipientFilter *, int, int, const char *, int, const char *, _DWORD, int, int, int, int, IRecipientFilter *, const Vector *, CUtlVector<Vector,CUtlMemory<Vector,int> > *, const char *, _DWORD, const char *))this->EmitSound)(
           a1: filter,
           a2: iEntIndex,
           a3: iChannel,
           a4: pSoundEntry,
           a5: iSoundEntryIndex,
           a6: pSample,
           a7: LODWORD(flVolume),
           a8: (int)v18,
           a9: nSeed,
           a10: iFlags,
           a11: iPitch,
           a12: pOrigin,
           a13: pDirection,
           a14: pUtlVecOrigins,
           a15: bUpdatePositions,
           a16: LODWORD(soundtime),
           a17: speakerentity);
}

//------------------------------------------------------------------------------
// Address: 0x10001330
// Name: public: virtual void CEngineSoundClient::SetPlayerDSP(class IRecipientFilter __near &,int,bool)
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __thiscall CEngineSoundClient::SetPlayerDSP(
        CEngineSoundClient *this,
        IRecipientFilter *filter,
        int dspType,
        bool fastReset)
{
  CLoaderMemAlloc::CrtIsValidPointer(this: (ConVar *)&dsp_player.IConVar, value: dspType);
  if ( fastReset )
    DSP_FastReset(dspType);
}

//------------------------------------------------------------------------------
// Address: 0x10001360
// Name: public: virtual int CEngineSoundClient::EmitAmbientSound(char const __near *,float,int,int,float)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CEngineSoundClient::EmitAmbientSound(
        CEngineSoundClient *this,
        const char *pSample,
        float flVolume,
        int iPitch,
        int flags,
        float soundtime)
{
  CSfxTable *v6; // eax
  StartSoundParams_t params; // [esp+0h] [ebp-68h] BYREF
  float delay; // [esp+64h] [ebp-4h]

  delay = 0.0;
  if ( soundtime != 0.0 )
    delay = soundtime - GetBaseLocalClient()->m_flLastServerTickTime;
  v6 = S_PrecacheSound(name: pSample);
  params.m_nSoundScriptHandle = -1;
  memset(&params.direction, 0, sizeof(params.direction));
  params.origin = vec3_origin;
  *((_BYTE *)&params + 96) = *((_BYTE *)&params + 96) & 0xC0 | 3;
  params.userdata = 0;
  params.initialStreamPosition = 0;
  params.skipInitialSamples = 0;
  memset(&params.m_pSoundEntryName, 0, 16);
  params.pSfx = v6;
  params.soundlevel = SNDLVL_NONE;
  params.fvol = flVolume;
  params.speakerentity = -1;
  params.m_nQueuedGUID = -1;
  params.soundsource = -1;
  params.entchannel = 6;
  params.flags = flags;
  params.pitch = iPitch;
  params.delay = delay;
  return S_StartSound(&params);
}

//------------------------------------------------------------------------------
// Address: 0x10001460
// Name: public: virtual void CEngineSoundClient::StopAllSounds(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineSoundClient::StopAllSounds(CEngineSoundClient *this, bool bClearBuffers)
{
  S_StopAllSounds(bClear: bClearBuffers);
}

//------------------------------------------------------------------------------
// Address: 0x10001480
// Name: public: virtual int CEngineSoundClient::GetGuidForLastSoundEmitted(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
int __thiscall CEngineSoundClient::GetGuidForLastSoundEmitted(CEngineSoundClient *this)
{
  return S_GetGuidForLastSoundEmitted();
}

//------------------------------------------------------------------------------
// Address: 0x100014B0
// Name: public: virtual void CEngineSoundClient::StopSoundByGuid(int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineSoundClient::StopSoundByGuid(CEngineSoundClient *this, int guid, bool bForceSync)
{
  S_StopSoundByGuid(guid, bForceSync);
}

//------------------------------------------------------------------------------
// Address: 0x100014D0
// Name: public: virtual void CEngineSoundClient::GetActiveSounds(class CUtlVector<struct SndInfo_t,class CUtlMemory<struct SndInfo_t,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineSoundClient::GetActiveSounds(
        CEngineSoundClient *this,
        CUtlVector<SndInfo_t,CUtlMemory<SndInfo_t,int> > *sndlist)
{
  S_GetActiveSounds(sndlist);
}

//------------------------------------------------------------------------------
// Address: 0x10001510
// Name: public: virtual void CEngineSoundClient::NotifyBeginMoviePlayback(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineSoundClient::NotifyBeginMoviePlayback(CEngineSoundClient *this)
{
  this->StopAllSounds(this, a2: true);
}

//------------------------------------------------------------------------------
// Address: 0x10001520
// Name: public: virtual bool CEngineSoundClient::GetSoundChannelVolume(char const __near *,float __near &,float __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CEngineSoundClient::GetSoundChannelVolume(
        CEngineSoundClient *this,
        const char *sound,
        float *flVolumeLeft,
        float *flVolumeRight)
{
  return S_GetSoundChannelVolume(sound, flVolumeLeft, flVolumeRight);
}

//------------------------------------------------------------------------------
// Address: 0x10001540
// Name: public: virtual int CEngineSingleUserFilter::GetRecipientIndex(int)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CEngineSingleUserFilter::GetRecipientIndex(CEngineSingleUserFilter *this, int slot)
{
  return this->m_nClientIndex;
}

//------------------------------------------------------------------------------
// Address: 0x10001550
// Name: public: virtual bool CEngineSingleUserFilter::IsBroadcastMessage(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CEngineSingleUserFilter::IsBroadcastMessage(CVTFTexture *this)
{
  return false;
}

//------------------------------------------------------------------------------
// Address: 0x100015C0
// Name: public: virtual void CEngineSoundClient::StopSound(int,int,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineSoundClient::StopSound(
        CEngineSoundClient *this,
        int iEntIndex,
        int iChannel,
        const char *pSample,
        int nSoundEntryIndex)
{
  CClientState *LocalClient; // eax
  int (__thiscall *EmitSound)(struct CEngineSoundClient *, IRecipientFilter *, int, int, const char *, int, const char *, float, soundlevel_t, int, int, int, const Vector *, const Vector *, CUtlVector<Vector,CUtlMemory<Vector,int> > *, bool, float, int); // edx
  _DWORD v8[2]; // [esp+30h] [ebp-Ch] BYREF
  char v9; // [esp+38h] [ebp-4h]

  LocalClient = GetLocalClient(nSlot: -1);
  EmitSound = this->EmitSound;
  v8[1] = LocalClient->m_nPlayerSlot + 1;
  v8[0] = &CEngineSingleUserFilter::`vftable';
  v9 = 0;
  ((void (__thiscall *)(CEngineSoundClient *, _DWORD *, int, int, const char *, int, const char *, _DWORD, _DWORD, _DWORD, int, int, _DWORD, _DWORD, _DWORD, int, _DWORD, int))EmitSound)(
    a1: this,
    a2: v8,
    a3: iEntIndex,
    a4: iChannel,
    a5: pSample,
    a6: nSoundEntryIndex,
    a7: pSample,
    a8: 0.0,
    a9: 0,
    a10: 0,
    a11: 4,
    a12: 100,
    a13: 0,
    a14: 0,
    a15: 0,
    a16: 1,
    a17: 0.0,
    a18: -1);
}

//------------------------------------------------------------------------------
// Address: 0x10001630
// Name: public: virtual void CEngineSoundClient::SetRoomType(class IRecipientFilter __near &,int)
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __thiscall CEngineSoundClient::SetRoomType(CEngineSoundClient *this, IRecipientFilter *filter, int roomType)
{
  if ( snd_dsp_spew_changes.m_pParent != nullptr && snd_dsp_spew_changes.m_pParent->m_Value.m_nValue != 0 )
    DevMsg(a1: "Changing to room type %d.\n", roomType);
  CLoaderMemAlloc::CrtIsValidPointer(this: (ConVar *)&dsp_room.IConVar, value: roomType);
}

//------------------------------------------------------------------------------
// Address: 0x10001670
// Name: private: int CEngineSoundClient::EmitSoundInternal(class IRecipientFilter __near &,int,int,char const __near *,int,char const __near *,float,enum soundlevel_t,int,int,int,class Vector const __near *,class Vector const __near *,class CUtlVector<class Vector,class CUtlMemory<class Vector,int>> __near *,bool,float,int)
// Source: json
//------------------------------------------------------------------------------
// bad sp value at call has been detected, the output may be wrong!
int __userpurge CEngineSoundClient::EmitSoundInternal@<eax>(
        CEngineSoundClient *this@<ecx>,
        int a2@<ebx>,
        int a3@<edi>,
        int a4@<esi>,
        IRecipientFilter *filter,
        int iEntIndex,
        int iChannel,
        const char *pSoundEntry,
        __int16 nSoundEntryIndex,
        const char *pSample,
        float flVolume,
        soundlevel_t iSoundLevel,
        int nSeed,
        unsigned int iFlags,
        const char *iPitch,
        const Vector *pOrigin,
        Vector *pDirection,
        CUtlVector<Vector,CUtlMemory<Vector,int> > *pUtlVecOrigins,
        bool bUpdatePositions,
        float soundtime,
        int speakerentity)
{
  CClientState *LocalClient; // eax
  int v23; // esi
  int v24; // ebx
  const Vector *v26; // edi
  IClientEntity *v27; // eax
  int v28; // eax
  Vector *v29; // esi
  IClientEntity *v30; // eax
  int v31; // eax
  float v32; // xmm0_4
  double v33; // st7
  float x; // xmm0_4
  float z; // xmm0_4
  char v36; // al
  float v37; // xmm0_4
  CSfxTable *v38; // eax
  StartSoundParams_t pStartParams; // [esp+8h] [ebp-88h] BYREF
  QAngle v42; // [esp+6Ch] [ebp-24h] BYREF
  Vector v43; // [esp+78h] [ebp-18h] BYREF
  int v44; // [esp+84h] [ebp-Ch] BYREF
  QAngle angles; // [esp+88h] [ebp-8h]
  int vecDirection_4; // [esp+98h] [ebp+8h]
  float vecDirection_4a; // [esp+98h] [ebp+8h]

  if ( flVolume < 0.0 || flVolume > 1.0 )
  {
    _Warning(a1: "EmitSound: %s volume out of bounds = %f\n", pSample, flVolume);
    return 0;
  }
  else if ( (unsigned int)iSoundLevel > (SNDLVL_180dB|SNDLVL_75dB|0x100) )
  {
    _Warning(a1: "EmitSound: %s soundlevel out of bounds = %d\n", pSample, iSoundLevel);
    return 0;
  }
  else if ( (unsigned int)iPitch > 0xFF )
  {
    _Warning(a1: "EmitSound: %s pitch out of bounds = %i\n", pSample, iPitch);
    return 0;
  }
  else
  {
    if ( iEntIndex < 0 )
    {
      LocalClient = GetLocalClient(nSlot: -1);
      iEntIndex = CBaseClientState::GetViewEntity(this: LocalClient);
    }
    v23 = 0;
    vecDirection_4 = ((int (__thiscall *)(IRecipientFilter *, int, int, int, int, int, int, CSfxTable *, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, soundlevel_t, int, int, _DWORD, int, int, int, int, _DWORD, const char *, KeyValues *, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD))filter->GetRecipientCount)(
                       a1: filter,
                       a2: a3,
                       a3: a4,
                       a4: a2,
                       a5: pStartParams.userdata,
                       a6: pStartParams.soundsource,
                       a7: pStartParams.entchannel,
                       a8: pStartParams.pSfx,
                       a9: LODWORD(pStartParams.origin.x),
                       a10: LODWORD(pStartParams.origin.y),
                       a11: LODWORD(pStartParams.origin.z),
                       a12: LODWORD(pStartParams.direction.x),
                       a13: LODWORD(pStartParams.direction.y),
                       a14: LODWORD(pStartParams.direction.z),
                       a15: LODWORD(pStartParams.fvol),
                       a16: pStartParams.soundlevel,
                       a17: pStartParams.flags,
                       a18: pStartParams.pitch,
                       a19: LODWORD(pStartParams.delay),
                       a20: pStartParams.speakerentity,
                       a21: pStartParams.initialStreamPosition,
                       a22: pStartParams.skipInitialSamples,
                       a23: pStartParams.m_nQueuedGUID,
                       a24: *(_DWORD *)&pStartParams.m_nSoundScriptHandle,
                       a25: pStartParams.m_pSoundEntryName,
                       a26: pStartParams.m_pOperatorsKV,
                       a27: LODWORD(pStartParams.opStackElapsedTime),
                       a28: LODWORD(pStartParams.opStackElapsedStopTime),
                       a29: *((_DWORD *)&pStartParams + 24),
                       a30: LODWORD(v42.x),
                       a31: LODWORD(v42.y),
                       a32: LODWORD(v42.z),
                       a33: LODWORD(v43.x),
                       a34: LODWORD(v43.y),
                       a35: LODWORD(v43.z));
    if ( vecDirection_4 <= 0 )
      return 0;
    while ( 1 )
    {
      v24 = filter->GetRecipientIndex(this: filter, a2: v23);
      if ( v24 == GetLocalClient(nSlot: -1)->m_nPlayerSlot + 1 )
        break;
      if ( ++v23 >= vecDirection_4 )
        return 0;
    }
    if ( v23 >= vecDirection_4 )
      return 0;
    v26 = pOrigin;
    if ( pOrigin == nullptr )
    {
      v27 = entitylist->GetClientEntity(this: entitylist, a2: iEntIndex);
      if ( v27 == nullptr || (iFlags & 4) != 0 )
      {
        v44 = 0;
        angles.x = 0.0;
        angles.y = 0.0;
        v26 = (const Vector *)&v44;
      }
      else
      {
        v28 = (int)v27->GetRenderOrigin(this: &v27->IClientRenderable);
        v44 = *(_DWORD *)v28;
        angles.x = *(float *)(v28 + 4);
        angles.y = *(float *)(v28 + 8);
        v26 = (const Vector *)&v44;
      }
    }
    v29 = pDirection;
    if ( pDirection == nullptr )
    {
      v30 = entitylist->GetClientEntity(this: entitylist, a2: iEntIndex);
      if ( v30 == nullptr || (iFlags & 4) != 0 )
      {
        memset(&v43, 0, sizeof(v43));
      }
      else
      {
        v31 = (int)v30->GetAbsAngles(this: v30);
        v42.x = *(float *)v31;
        v32 = *(float *)(v31 + 4);
        LODWORD(v43.z) = &v43;
        v42.y = v32;
        v42.z = *(float *)(v31 + 8);
        AngleVectors(angles: &v42, forward: &v43);
      }
      v29 = &v43;
    }
    if ( pUtlVecOrigins != nullptr )
      CUtlVector<Vector,CUtlMemory<Vector,int>>::InsertBefore(
        this: pUtlVecOrigins,
        elem: pUtlVecOrigins->m_Size,
        src: v26);
    vecDirection_4a = soundtime;
    if ( soundtime > 0.0 )
    {
      v33 = S_ComputeDelayForSoundtime(soundtime, syncIndex: CLOCK_SYNC_CLIENT);
      vecDirection_4a = v33;
      if ( v33 < 0.0 && vecDirection_4a > -0.1 )
        vecDirection_4a = 0.0;
    }
    StartSoundParams_t::StartSoundParams_t(this: &pStartParams);
    x = v26->x;
    pStartParams.entchannel = iChannel;
    pStartParams.origin.x = x;
    pStartParams.origin.y = v26->y;
    z = v26->z;
    pStartParams.pitch = (int)iPitch;
    pStartParams.origin.z = z;
    pStartParams.direction.x = v29->x;
    v36 = (((*((_BYTE *)&pStartParams + 96)
           ^ (iChannel == 6))
          & 1
          ^ *((_BYTE *)&pStartParams + 96)
          ^ (2 * bUpdatePositions))
         & 2
         ^ (*((_BYTE *)&pStartParams + 96)
          ^ (iChannel == 6))
         & 1
         ^ *((_BYTE *)&pStartParams + 96))
        & 0xFB;
    pStartParams.direction.y = v29->y;
    v37 = v29->z;
    pStartParams.soundsource = iEntIndex;
    pStartParams.direction.z = v37;
    pStartParams.soundlevel = iSoundLevel;
    pStartParams.fvol = flVolume;
    pStartParams.flags = iFlags;
    pStartParams.delay = vecDirection_4a;
    pStartParams.speakerentity = speakerentity;
    *((_BYTE *)&pStartParams + 96) = (v36 ^ (16 * (iFlags >> 10))) & 0x10 ^ v36;
    if ( (iFlags & 0x1000) != 0 )
      pStartParams.m_nQueuedGUID = -2;
    if ( (iFlags & 0x400) != 0 )
    {
      pStartParams.m_nSoundScriptHandle = nSoundEntryIndex;
      return S_StartSoundEntry(&pStartParams, nSeed);
    }
    v38 = S_PrecacheSound(name: pSample);
    if ( v38 != nullptr )
    {
      pStartParams.pSfx = v38;
      return S_StartSound(params: &pStartParams);
    }
    else
    {
      return 0;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100019E0
// Name: public: virtual void CEngineSoundClient::EmitSentenceByIndex(class IRecipientFilter __near &,int,int,int,float,enum soundlevel_t,int,int,int,class Vector const __near *,class Vector const __near *,class CUtlVector<class Vector,class CUtlMemory<class Vector,int>> __near *,bool,float,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineSoundClient::EmitSentenceByIndex(
        CEngineSoundClient *this,
        IRecipientFilter *filter,
        int iEntIndex,
        int iChannel,
        int iSentenceIndex,
        float flVolume,
        soundlevel_t iSoundLevel,
        int nSeed,
        int iFlags,
        int iPitch,
        const Vector *pOrigin,
        const Vector *pDirection,
        CUtlVector<Vector,CUtlMemory<Vector,int> > *pUtlVecOrigins,
        bool bUpdatePosition,
        float soundtime,
        int speakerentity)
{
  char pDest[12]; // [esp+4h] [ebp-8h] BYREF

  if ( iSentenceIndex >= 0 )
  {
    V_snprintf(pDest, maxLen: 8, pFormat: "!%d", iSentenceIndex);
    CEngineSoundClient::EmitSoundInternal(
      this,
      filter,
      iEntIndex,
      iChannel,
      pSoundEntry: nullptr,
      nSoundEntryIndex: -1,
      pSample: pDest,
      flVolume,
      iSoundLevel,
      nSeed,
      iFlags,
      iPitch,
      pOrigin,
      pDirection,
      pUtlVecOrigins,
      bUpdatePositions: bUpdatePosition,
      soundtime,
      speakerentity);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10001A60
// Name: public: virtual int CEngineSoundClient::EmitSound(class IRecipientFilter __near &,int,int,char const __near *,int,char const __near *,float,enum soundlevel_t,int,int,int,class Vector const __near *,class Vector const __near *,class CUtlVector<class Vector,class CUtlMemory<class Vector,int>> __near *,bool,float,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CEngineSoundClient::EmitSound(
        CEngineSoundClient *this,
        IRecipientFilter *filter,
        int iEntIndex,
        int iChannel,
        char *pSoundEntry,
        int iSoundEntryIndex,
        int pSample,
        float flVolume,
        soundlevel_t iSoundLevel,
        int nSeed,
        int iFlags,
        int iPitch,
        IRecipientFilter *pOrigin,
        const Vector *pDirection,
        CUtlVector<Vector,CUtlMemory<Vector,int> > *pUtlVecOrigins,
        const char *bUpdatePositions,
        float soundtime,
        int speakerentity)
{
  const char *v18; // esi
  const char *v20; // eax
  const char *v22; // eax

  v18 = (const char *)pSample;
  if ( pSample == 0 || !TestSoundChar(pch: (const char *)pSample, c: 33) )
    return CEngineSoundClient::EmitSoundInternal(
             this,
             filter,
             iEntIndex,
             iChannel,
             pSoundEntry,
             nSoundEntryIndex: iSoundEntryIndex,
             pSample: v18,
             flVolume,
             iSoundLevel,
             nSeed,
             iFlags,
             iPitch,
             (const Vector *)pOrigin,
             pDirection,
             pUtlVecOrigins,
             (bool)bUpdatePositions,
             soundtime,
             speakerentity);
  pSample = -1;
  v20 = PSkipSoundChars(pch: v18);
  VOX_LookupString(
    pSentenceName: v20,
    psentencenum: &pSample,
    pbEmitCaption: nullptr,
    pCaptionSymbol: nullptr,
    pflDuration: nullptr);
  if ( pSample < 0 )
  {
    v22 = PSkipSoundChars(pch: v18);
    _DevWarning(a1: 2, a2: "Unable to find %s in sentences.txt\n", v22);
  }
  else
  {
    ((void (__thiscall *)(CEngineSoundClient *, IRecipientFilter *, int, int, int, _DWORD, soundlevel_t, int, int, int, IRecipientFilter *, const Vector *, CUtlVector<Vector,CUtlMemory<Vector,int> > *, const char *, _DWORD, int))this->EmitSentenceByIndex)(
      a1: this,
      a2: filter,
      a3: iEntIndex,
      a4: iChannel,
      a5: pSample,
      a6: LODWORD(flVolume),
      a7: iSoundLevel,
      a8: nSeed,
      a9: iFlags,
      a10: iPitch,
      a11: pOrigin,
      a12: pDirection,
      a13: pUtlVecOrigins,
      a14: bUpdatePositions,
      a15: LODWORD(soundtime),
      a16: speakerentity);
  }
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x10002080
// Name: public: virtual float CEngineSoundClient::GetDistGainFromSoundLevel(enum soundlevel_t,float)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CEngineSoundClient::GetDistGainFromSoundLevel(
        CEngineSoundClient *this,
        soundlevel_t soundlevel,
        float dist)
{
  return S_GetGainFromSoundLevel(soundlevel, dist);
}

//------------------------------------------------------------------------------
// Address: 0x101FF9C0
// Name: public: virtual float CEngineSoundClient::GetSoundDuration(char const __near *)
// Source: json
//------------------------------------------------------------------------------
float __thiscall CEngineSoundClient::GetSoundDuration(CEngineSoundClient *this, const char *pSample)
{
  return AudioSource_GetSoundDuration(pName: pSample);
}

//------------------------------------------------------------------------------
// Address: 0x10001B80
// Name: __CreateCEngineSoundServerIEngineSound_interface
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CEngineSoundServer *__cdecl _CreateCEngineSoundServerIEngineSound_interface()
{
  return &s_EngineSoundServer;
}

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x10001110
// Name: public: class Vector __near & Vector::operator=(class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
Vector *__thiscall Vector::operator=(Vector *this, const Vector *vOther)
{
  *this = *vOther;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100011C0
// Name: class IEngineSound __near * EngineSoundClient(void)
// Source: json
//------------------------------------------------------------------------------
CEngineSoundClient *__cdecl EngineSoundClient()
{
  return &s_EngineSoundClient;
}

//------------------------------------------------------------------------------
// Address: 0x100011D0
// Name: public: virtual bool CEngineSoundClient::PrecacheSound(char const __near *,bool,bool)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CEngineSoundClient::PrecacheSound(
        CEngineSoundClient *this,
        const char *pSample,
        bool bPreload,
        bool bIsUISound)
{
  CSfxTable *v4; // eax

  v4 = S_PrecacheSound(name: pSample);
  if ( v4 == nullptr )
    return 0;
  if ( bIsUISound )
    S_MarkUISound(pSfx: v4);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10001200
// Name: public: virtual void CEngineSoundClient::PrefetchSound(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineSoundClient::PrefetchSound(CEngineSoundClient *this, const char *pSample)
{
  S_PrefetchSound(name: pSample, bPlayOnce: true);
}

//------------------------------------------------------------------------------
// Address: 0x10001260
// Name: public: virtual bool CEngineSoundClient::IsLoopingSound(char const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CEngineSoundClient::IsLoopingSound(CEngineSoundClient *this, const char *pSample)
{
  CSfxTable *v2; // eax

  v2 = S_PrecacheSound(name: pSample);
  return v2 != nullptr && v2->pSource != nullptr && v2->pSource->IsLooped(this: v2->pSource);
}

//------------------------------------------------------------------------------
// Address: 0x10001290
// Name: public: virtual int CEngineSoundClient::EmitSound(class IRecipientFilter __near &,int,int,char const __near *,int,char const __near *,float,float,int,int,int,class Vector const __near *,class Vector const __near *,class CUtlVector<class Vector,class CUtlMemory<class Vector,int>> __near *,bool,float,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CEngineSoundClient::EmitSound(
        CEngineSoundClient *this,
        IRecipientFilter *filter,
        int iEntIndex,
        int iChannel,
        const char *pSoundEntry,
        int iSoundEntryIndex,
        const char *pSample,
        float flVolume,
        float flAttenuation,
        int nSeed,
        int iFlags,
        int iPitch,
        const Vector *pOrigin,
        const Vector *pDirection,
        CUtlVector<Vector,CUtlMemory<Vector,int> > *pUtlVecOrigins,
        int bUpdatePositions,
        float soundtime,
        int speakerentity)
{
  float v18; // xmm0_4

  v18 = 0.0;
  if ( flAttenuation != 0.0 )
    v18 = (float)(20.0 / flAttenuation) + 50.0;
  return ((int (__stdcall *)(IRecipientFilter *, int, int, const char *, int, const char *, _DWORD, int, int, int, int, const Vector *, const Vector *, CUtlVector<Vector,CUtlMemory<Vector,int> > *, int, _DWORD, int))this->EmitSound)(
           a1: filter,
           a2: iEntIndex,
           a3: iChannel,
           a4: pSoundEntry,
           a5: iSoundEntryIndex,
           a6: pSample,
           a7: LODWORD(flVolume),
           a8: (int)v18,
           a9: nSeed,
           a10: iFlags,
           a11: iPitch,
           a12: pOrigin,
           a13: pDirection,
           a14: pUtlVecOrigins,
           a15: bUpdatePositions,
           a16: LODWORD(soundtime),
           a17: speakerentity);
}

//------------------------------------------------------------------------------
// Address: 0x10001310
// Name: public: virtual void CEngineSoundClient::SetPlayerDSP(class IRecipientFilter __near &,int,bool)
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __thiscall CEngineSoundClient::SetPlayerDSP(
        CEngineSoundClient *this,
        IRecipientFilter *filter,
        int dspType,
        bool fastReset)
{
  CLoaderMemAlloc::CrtIsValidPointer(this: (ConVar *)&dsp_player.IConVar, value: dspType);
  if ( fastReset )
    DSP_FastReset(dspType);
}

//------------------------------------------------------------------------------
// Address: 0x10001340
// Name: public: virtual int CEngineSoundClient::EmitAmbientSound(char const __near *,float,int,int,float)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CEngineSoundClient::EmitAmbientSound(
        CEngineSoundClient *this,
        const char *pSample,
        float flVolume,
        int iPitch,
        int flags,
        float soundtime)
{
  CSfxTable *v6; // eax
  StartSoundParams_t params; // [esp+0h] [ebp-68h] BYREF
  float delay; // [esp+64h] [ebp-4h]

  delay = 0.0;
  if ( soundtime != 0.0 )
    delay = soundtime - GetBaseLocalClient()->m_flLastServerTickTime;
  v6 = S_PrecacheSound(name: pSample);
  params.m_nSoundScriptHandle = -1;
  memset(&params.direction, 0, sizeof(params.direction));
  params.origin = vec3_origin;
  *((_BYTE *)&params + 96) = *((_BYTE *)&params + 96) & 0xC0 | 3;
  params.userdata = 0;
  params.initialStreamPosition = 0;
  params.skipInitialSamples = 0;
  memset(&params.m_pSoundEntryName, 0, 16);
  params.pSfx = v6;
  params.soundlevel = SNDLVL_NONE;
  params.fvol = flVolume;
  params.speakerentity = -1;
  params.m_nQueuedGUID = -1;
  params.soundsource = -1;
  params.entchannel = 6;
  params.flags = flags;
  params.pitch = iPitch;
  params.delay = delay;
  return S_StartSound(&params);
}

//------------------------------------------------------------------------------
// Address: 0x10001440
// Name: public: virtual void CEngineSoundClient::StopAllSounds(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineSoundClient::StopAllSounds(CEngineSoundClient *this, bool bClearBuffers)
{
  S_StopAllSounds(bClear: bClearBuffers);
}

//------------------------------------------------------------------------------
// Address: 0x100015B0
// Name: public: virtual void CEngineSoundClient::StopSound(int,int,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineSoundClient::StopSound(
        CEngineSoundClient *this,
        int iEntIndex,
        int iChannel,
        const char *pSample,
        int nSoundEntryIndex)
{
  CClientState *LocalClient; // eax
  int (__thiscall *EmitSound)(struct CEngineSoundClient *, IRecipientFilter *, int, int, const char *, int, const char *, float, soundlevel_t, int, int, int, const Vector *, const Vector *, CUtlVector<Vector,CUtlMemory<Vector,int> > *, bool, float, int); // edx
  CEngineSingleUserFilter filter; // [esp+30h] [ebp-Ch] BYREF

  LocalClient = GetLocalClient(nSlot: -1);
  EmitSound = this->EmitSound;
  filter.m_nClientIndex = LocalClient->m_nPlayerSlot + 1;
  filter.__vftable = (CEngineSingleUserFilter_vtbl *)&CEngineSingleUserFilter::`vftable';
  filter.m_bReliable = false;
  ((void (__thiscall *)(CEngineSoundClient *, CEngineSingleUserFilter *, int, int, const char *, int, const char *, _DWORD, _DWORD, _DWORD, int, int, _DWORD, _DWORD, _DWORD, int, _DWORD, int))EmitSound)(
    a1: this,
    a2: &filter,
    a3: iEntIndex,
    a4: iChannel,
    a5: pSample,
    a6: nSoundEntryIndex,
    a7: pSample,
    a8: 0.0,
    a9: 0,
    a10: 0,
    a11: 4,
    a12: 100,
    a13: 0,
    a14: 0,
    a15: 0,
    a16: 1,
    a17: 0.0,
    a18: -1);
}

//------------------------------------------------------------------------------
// Address: 0x10001620
// Name: public: virtual void CEngineSoundClient::SetRoomType(class IRecipientFilter __near &,int)
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __thiscall CEngineSoundClient::SetRoomType(CEngineSoundClient *this, IRecipientFilter *filter, int roomType)
{
  if ( snd_dsp_spew_changes.m_pParent != nullptr && snd_dsp_spew_changes.m_pParent->m_Value.m_nValue != 0 )
    DevMsg(a1: "Changing to room type %d.\n", roomType);
  CLoaderMemAlloc::CrtIsValidPointer(this: (ConVar *)&dsp_room.IConVar, value: roomType);
}

//------------------------------------------------------------------------------
// Address: 0x10001660
// Name: private: int CEngineSoundClient::EmitSoundInternal(class IRecipientFilter __near &,int,int,char const __near *,int,char const __near *,float,enum soundlevel_t,int,int,int,class Vector const __near *,class Vector const __near *,class CUtlVector<class Vector,class CUtlMemory<class Vector,int>> __near *,bool,float,int)
// Source: json
//------------------------------------------------------------------------------
// bad sp value at call has been detected, the output may be wrong!
int __userpurge CEngineSoundClient::EmitSoundInternal@<eax>(
        CEngineSoundClient *this@<ecx>,
        int a2@<ebx>,
        int a3@<edi>,
        int a4@<esi>,
        IRecipientFilter *filter,
        int iEntIndex,
        int iChannel,
        const char *pSoundEntry,
        __int16 nSoundEntryIndex,
        const char *pSample,
        float flVolume,
        soundlevel_t iSoundLevel,
        int nSeed,
        unsigned int iFlags,
        unsigned int iPitch,
        Vector *pOrigin,
        Vector *pDirection,
        CUtlVector<Vector,CUtlMemory<Vector,int> > *pUtlVecOrigins,
        bool bUpdatePositions,
        float soundtime,
        int speakerentity)
{
  CClientState *LocalClient; // eax
  int v23; // esi
  int v24; // ebx
  Vector *p_vecDummyOrigin; // edi
  IClientEntity *v27; // eax
  Vector *p_vecDirection; // esi
  IClientEntity *v29; // eax
  int v30; // eax
  float v31; // xmm0_4
  double v32; // st7
  float x; // xmm0_4
  float z; // xmm0_4
  char v35; // al
  float v36; // xmm0_4
  CSfxTable *v37; // eax
  StartSoundParams_t params; // [esp+1Ch] [ebp-88h] BYREF
  QAngle angles; // [esp+80h] [ebp-24h] BYREF
  Vector vecDirection; // [esp+8Ch] [ebp-18h] BYREF
  Vector vecDummyOrigin; // [esp+98h] [ebp-Ch] BYREF
  int c; // [esp+ACh] [ebp+8h]
  float ca; // [esp+ACh] [ebp+8h]

  if ( flVolume < 0.0 || flVolume > 1.0 )
  {
    _Warning(a1: "EmitSound: %s volume out of bounds = %f\n", pSample, flVolume);
    return 0;
  }
  else if ( (unsigned int)iSoundLevel > (SNDLVL_180dB|SNDLVL_75dB|0x100) )
  {
    _Warning(a1: "EmitSound: %s soundlevel out of bounds = %d\n", pSample, iSoundLevel);
    return 0;
  }
  else if ( iPitch > 0xFF )
  {
    _Warning(a1: "EmitSound: %s pitch out of bounds = %i\n", pSample, iPitch);
    return 0;
  }
  else
  {
    if ( iEntIndex < 0 )
    {
      LocalClient = GetLocalClient(nSlot: -1);
      iEntIndex = CBaseClientState::GetViewEntity(this: LocalClient);
    }
    v23 = 0;
    c = ((int (__thiscall *)(IRecipientFilter *, int, int, int, int, int, int, CSfxTable *, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, soundlevel_t, int, int, _DWORD, int, int, int, int, _DWORD, const char *, KeyValues *, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD))filter->GetRecipientCount)(
          a1: filter,
          a2: a3,
          a3: a4,
          a4: a2,
          a5: params.userdata,
          a6: params.soundsource,
          a7: params.entchannel,
          a8: params.pSfx,
          a9: LODWORD(params.origin.x),
          a10: LODWORD(params.origin.y),
          a11: LODWORD(params.origin.z),
          a12: LODWORD(params.direction.x),
          a13: LODWORD(params.direction.y),
          a14: LODWORD(params.direction.z),
          a15: LODWORD(params.fvol),
          a16: params.soundlevel,
          a17: params.flags,
          a18: params.pitch,
          a19: LODWORD(params.delay),
          a20: params.speakerentity,
          a21: params.initialStreamPosition,
          a22: params.skipInitialSamples,
          a23: params.m_nQueuedGUID,
          a24: *(_DWORD *)&params.m_nSoundScriptHandle,
          a25: params.m_pSoundEntryName,
          a26: params.m_pOperatorsKV,
          a27: LODWORD(params.opStackElapsedTime),
          a28: LODWORD(params.opStackElapsedStopTime),
          a29: *((_DWORD *)&params + 24),
          a30: LODWORD(angles.x),
          a31: LODWORD(angles.y),
          a32: LODWORD(angles.z),
          a33: LODWORD(vecDirection.x),
          a34: LODWORD(vecDirection.y),
          a35: LODWORD(vecDirection.z));
    if ( c <= 0 )
      return 0;
    while ( 1 )
    {
      v24 = filter->GetRecipientIndex(this: filter, a2: v23);
      if ( v24 == GetLocalClient(nSlot: -1)->m_nPlayerSlot + 1 )
        break;
      if ( ++v23 >= c )
        return 0;
    }
    if ( v23 >= c )
      return 0;
    p_vecDummyOrigin = pOrigin;
    if ( pOrigin == nullptr )
    {
      v27 = entitylist->GetClientEntity(this: entitylist, a2: iEntIndex);
      if ( v27 == nullptr || (iFlags & 4) != 0 )
      {
        memset(&vecDummyOrigin, 0, sizeof(vecDummyOrigin));
        p_vecDummyOrigin = &vecDummyOrigin;
      }
      else
      {
        vecDummyOrigin = *v27->GetRenderOrigin(this: &v27->IClientRenderable);
        p_vecDummyOrigin = &vecDummyOrigin;
      }
    }
    p_vecDirection = pDirection;
    if ( pDirection == nullptr )
    {
      v29 = entitylist->GetClientEntity(this: entitylist, a2: iEntIndex);
      if ( v29 == nullptr || (iFlags & 4) != 0 )
      {
        memset(&vecDirection, 0, sizeof(vecDirection));
      }
      else
      {
        v30 = (int)v29->GetAbsAngles(this: v29);
        angles.x = *(float *)v30;
        v31 = *(float *)(v30 + 4);
        LODWORD(vecDirection.z) = &vecDirection;
        angles.y = v31;
        angles.z = *(float *)(v30 + 8);
        AngleVectors(&angles, forward: &vecDirection);
      }
      p_vecDirection = &vecDirection;
    }
    if ( pUtlVecOrigins != nullptr )
      CUtlVector<Vector,CUtlMemory<Vector,int>>::InsertBefore(
        this: pUtlVecOrigins,
        elem: pUtlVecOrigins->m_Size,
        src: p_vecDummyOrigin);
    ca = soundtime;
    if ( soundtime > 0.0 )
    {
      v32 = S_ComputeDelayForSoundtime(soundtime, syncIndex: CLOCK_SYNC_CLIENT);
      ca = v32;
      if ( v32 < 0.0 && ca > -0.1 )
        ca = 0.0;
    }
    StartSoundParams_t::StartSoundParams_t(this: &params);
    x = p_vecDummyOrigin->x;
    params.entchannel = iChannel;
    params.origin.x = x;
    params.origin.y = p_vecDummyOrigin->y;
    z = p_vecDummyOrigin->z;
    params.pitch = iPitch;
    params.origin.z = z;
    params.direction.x = p_vecDirection->x;
    v35 = (((*((_BYTE *)&params + 96)
           ^ (iChannel == 6))
          & 1
          ^ *((_BYTE *)&params + 96)
          ^ (2 * bUpdatePositions))
         & 2
         ^ (*((_BYTE *)&params + 96)
          ^ (iChannel == 6))
         & 1
         ^ *((_BYTE *)&params + 96))
        & 0xFB;
    params.direction.y = p_vecDirection->y;
    v36 = p_vecDirection->z;
    params.soundsource = iEntIndex;
    params.direction.z = v36;
    params.soundlevel = iSoundLevel;
    params.fvol = flVolume;
    params.flags = iFlags;
    params.delay = ca;
    params.speakerentity = speakerentity;
    *((_BYTE *)&params + 96) = (v35 ^ (16 * (iFlags >> 10))) & 0x10 ^ v35;
    if ( (iFlags & 0x1000) != 0 )
      params.m_nQueuedGUID = -2;
    if ( (iFlags & 0x400) != 0 )
    {
      params.m_nSoundScriptHandle = nSoundEntryIndex;
      return S_StartSoundEntry(pStartParams: &params, nSeed);
    }
    v37 = S_PrecacheSound(name: pSample);
    if ( v37 != nullptr )
    {
      params.pSfx = v37;
      return S_StartSound(&params);
    }
    else
    {
      return 0;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100019D0
// Name: public: virtual void CEngineSoundClient::EmitSentenceByIndex(class IRecipientFilter __near &,int,int,int,float,enum soundlevel_t,int,int,int,class Vector const __near *,class Vector const __near *,class CUtlVector<class Vector,class CUtlMemory<class Vector,int>> __near *,bool,float,int)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CEngineSoundClient::EmitSentenceByIndex(
        CEngineSoundClient *this@<ecx>,
        int a2@<ebx>,
        int a3@<edi>,
        IRecipientFilter *filter,
        int iEntIndex,
        int iChannel,
        int iSentenceIndex,
        float flVolume,
        soundlevel_t iSoundLevel,
        int nSeed,
        unsigned int iFlags,
        unsigned int iPitch,
        Vector *pOrigin,
        Vector *pDirection,
        CUtlVector<Vector,CUtlMemory<Vector,int> > *pUtlVecOrigins,
        bool bUpdatePosition,
        float soundtime,
        int speakerentity)
{
  char pName[8]; // [esp+30h] [ebp-8h] BYREF

  if ( iSentenceIndex >= 0 )
  {
    V_snprintf(pDest: pName, maxLen: 8, pFormat: "!%d", iSentenceIndex);
    CEngineSoundClient::EmitSoundInternal(
      this,
      a2,
      a3,
      a4: (int)this,
      filter,
      iEntIndex,
      iChannel,
      pSoundEntry: nullptr,
      nSoundEntryIndex: -1,
      pSample: pName,
      flVolume,
      iSoundLevel,
      nSeed,
      iFlags,
      iPitch,
      pOrigin,
      pDirection,
      pUtlVecOrigins,
      bUpdatePositions: bUpdatePosition,
      soundtime,
      speakerentity);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10001A50
// Name: public: virtual int CEngineSoundClient::EmitSound(class IRecipientFilter __near &,int,int,char const __near *,int,char const __near *,float,enum soundlevel_t,int,int,int,class Vector const __near *,class Vector const __near *,class CUtlVector<class Vector,class CUtlMemory<class Vector,int>> __near *,bool,float,int)
// Source: json
//------------------------------------------------------------------------------
int __userpurge CEngineSoundClient::EmitSound@<eax>(
        CEngineSoundClient *this@<ecx>,
        int a2@<ebx>,
        IRecipientFilter *filter,
        int iEntIndex,
        int iChannel,
        const char *pSoundEntry,
        __int16 iSoundEntryIndex,
        int pSample,
        float flVolume,
        soundlevel_t iSoundLevel,
        int nSeed,
        unsigned int iFlags,
        unsigned int iPitch,
        Vector *pOrigin,
        Vector *pDirection,
        CUtlVector<Vector,CUtlMemory<Vector,int> > *pUtlVecOrigins,
        BOOL bUpdatePositions,
        float soundtime,
        int speakerentity)
{
  const char *v19; // esi
  const char *v21; // eax
  const char *v23; // eax

  v19 = (const char *)pSample;
  if ( pSample == 0 || !TestSoundChar(pch: (const char *)pSample, c: 33) )
    return CEngineSoundClient::EmitSoundInternal(
             this,
             a2,
             a3: (int)this,
             a4: (int)v19,
             filter,
             iEntIndex,
             iChannel,
             pSoundEntry,
             nSoundEntryIndex: iSoundEntryIndex,
             pSample: v19,
             flVolume,
             iSoundLevel,
             nSeed,
             iFlags,
             iPitch,
             pOrigin,
             pDirection,
             pUtlVecOrigins,
             bUpdatePositions,
             soundtime,
             speakerentity);
  pSample = -1;
  v21 = PSkipSoundChars(pch: v19);
  VOX_LookupString(
    pSentenceName: v21,
    psentencenum: &pSample,
    pbEmitCaption: nullptr,
    pCaptionSymbol: nullptr,
    pflDuration: nullptr);
  if ( pSample < 0 )
  {
    v23 = PSkipSoundChars(pch: v19);
    _DevWarning(a1: 2, a2: "Unable to find %s in sentences.txt\n", v23);
  }
  else
  {
    ((void (__thiscall *)(CEngineSoundClient *, IRecipientFilter *, int, int, int, _DWORD, soundlevel_t, int, unsigned int, unsigned int, Vector *, Vector *, CUtlVector<Vector,CUtlMemory<Vector,int> > *, BOOL, _DWORD, int))this->EmitSentenceByIndex)(
      a1: this,
      a2: filter,
      a3: iEntIndex,
      a4: iChannel,
      a5: pSample,
      a6: LODWORD(flVolume),
      a7: iSoundLevel,
      a8: nSeed,
      a9: iFlags,
      a10: iPitch,
      a11: pOrigin,
      a12: pDirection,
      a13: pUtlVecOrigins,
      a14: bUpdatePositions,
      a15: LODWORD(soundtime),
      a16: speakerentity);
  }
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x10002060
// Name: public: virtual float CEngineSoundClient::GetDistGainFromSoundLevel(enum soundlevel_t,float)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CEngineSoundClient::GetDistGainFromSoundLevel(
        CEngineSoundClient *this,
        soundlevel_t soundlevel,
        float dist)
{
  return S_GetGainFromSoundLevel(soundlevel, dist);
}

//------------------------------------------------------------------------------
// Address: 0x100A1970
// Name: public: virtual bool CEngineSingleUserFilter::IsBroadcastMessage(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CEngineSingleUserFilter::IsBroadcastMessage(CVTFTexture *this)
{
  return false;
}

//------------------------------------------------------------------------------
// Address: 0x101A4A80
// Name: void __near * MemAlloc_Alloc(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void *__cdecl MemAlloc_Alloc(unsigned int nSize)
{
  return _g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: nSize);
}

//------------------------------------------------------------------------------
// Address: 0x10001B70
// Name: __CreateCEngineSoundServerIEngineSound_interface
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CEngineSoundServer *__cdecl _CreateCEngineSoundServerIEngineSound_interface()
{
  return &s_EngineSoundServer;
}

} // namespace engine_xlsp
