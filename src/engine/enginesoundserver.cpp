// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: engine/enginesoundserver.cpp
// Functions: 26
// ============================================================

#include "engine\enginesoundserver.h"

//------------------------------------------------------------------------------
// Address: 0x10001B90
// Name: public: virtual bool CEngineSoundServer::IsLoopingSound(char const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CEngineSoundServer::IsLoopingSound(CEngineSoundServer *this, const char *pSample)
{
  _Warning(a1: "Can't call IsLoopingSound from server\n");
  return false;
}

//------------------------------------------------------------------------------
// Address: 0x10001BB0
// Name: public: virtual int CEngineSoundServer::GetGuidForLastSoundEmitted(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CEngineSoundServer::GetGuidForLastSoundEmitted(CEngineSoundServer *this)
{
  _Warning(a1: "Can't call GetGuidForLastSoundEmitted from server\n");
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10001BD0
// Name: public: virtual bool CEngineSoundServer::IsSoundStillPlaying(int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CEngineSoundServer::IsSoundStillPlaying(CEngineSoundServer *this, int guid)
{
  _Warning(a1: "Can't call IsSoundStillPlaying from server\n");
  return false;
}

//------------------------------------------------------------------------------
// Address: 0x10001BF0
// Name: public: virtual void CEngineSoundServer::StopSoundByGuid(int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineSoundServer::StopSoundByGuid(CEngineSoundServer *this, int guid, bool bForce)
{
  _Warning(a1: "Can't call StopSoundByGuid from server\n");
}

//------------------------------------------------------------------------------
// Address: 0x10001C00
// Name: public: virtual void CEngineSoundServer::GetActiveSounds(class CUtlVector<struct SndInfo_t,class CUtlMemory<struct SndInfo_t,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineSoundServer::GetActiveSounds(
        CEngineSoundServer *this,
        CUtlVector<SndInfo_t,CUtlMemory<SndInfo_t,int> > *sndlist)
{
  _Warning(a1: "Can't call GetActiveSounds from server\n");
}

//------------------------------------------------------------------------------
// Address: 0x10001C10
// Name: public: virtual void CEngineSoundServer::SetVolumeByGuid(int,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineSoundServer::SetVolumeByGuid(CEngineSoundServer *this, int guid, float fvol)
{
  _Warning(a1: "Can't call SetVolumeByGuid from server\n");
}

//------------------------------------------------------------------------------
// Address: 0x10001C20
// Name: public: virtual float CEngineSoundServer::GetElapsedTimeByGuid(int)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CEngineSoundServer::GetElapsedTimeByGuid(CEngineSoundServer *this, int guid)
{
  _Warning(a1: "Can't call GetElapsedTimeByGuid from server\n");
  return 0.0;
}

//------------------------------------------------------------------------------
// Address: 0x10001C40
// Name: public: virtual void CEngineSoundServer::PrecacheSentenceGroup(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineSoundServer::PrecacheSentenceGroup(CEngineSoundClient *this, const char *pGroupName)
{
  VOX_PrecacheSentenceGroup(pSoundSystem: this, pGroupName, pPathOverride: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x10001C60
// Name: public: virtual bool CEngineSoundServer::GetSoundChannelVolume(char const __near *,float __near &,float __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CEngineSoundServer::GetSoundChannelVolume(
        CEngineSoundServer *this,
        const char *sound,
        float *flVolumeLeft,
        float *flVolumeRight)
{
  _Warning(a1: "Can't call GetSoundChannelVolume from server\n");
  return false;
}

//------------------------------------------------------------------------------
// Address: 0x10001C80
// Name: public: virtual bool CEngineSoundServer::PrecacheSound(char const __near *,bool,bool)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CEngineSoundServer::PrecacheSound(
        CEngineSoundServer *this,
        const char *pSample,
        bool bPreload,
        bool bIsUISound)
{
  IEngineVGuiInternal *v4; // eax

  v4 = EngineVGui();
  v4->UpdateProgressBar(this: v4, a2: PROGRESS_DEFAULT, a3: true);
  if ( pSample != nullptr && TestSoundChar(pch: pSample, c: 33) )
    return 1;
  if ( *pSample <= 32 )
    Host_Error(error: "CEngineSoundServer::PrecacheSound:  Bad string: %s", pSample);
  if ( SV_FindOrAddSound(name: pSample, preload: bPreload) >= 0 )
    return 1;
  Host_Error(error: "CEngineSoundServer::PrecacheSound: '%s' overflow", pSample);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10001CF0
// Name: public: virtual bool CEngineSoundServer::IsSoundPrecached(char const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CEngineSoundServer::IsSoundPrecached(CEngineSoundServer *this, const char *pSample)
{
  return pSample != nullptr && TestSoundChar(pch: pSample, c: 33) || SV_SoundIndex(name: pSample) != -1;
}

//------------------------------------------------------------------------------
// Address: 0x10001D30
// Name: private: void CEngineSoundServer::EmitSoundInternal(class IRecipientFilter __near &,int,int,char const __near *,int,char const __near *,float,enum soundlevel_t,int,int,int,class Vector const __near *,class Vector const __near *,class CUtlVector<class Vector,class CUtlMemory<class Vector,int>> __near *,bool,float,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineSoundServer::EmitSoundInternal(
        CEngineSoundServer *this,
        IRecipientFilter *filter,
        int iEntIndex,
        int iChannel,
        char *pSoundEntry,
        int iSoundEntryIndex,
        const char *pSample,
        float flVolume,
        soundlevel_t iSoundLevel,
        int nSeed,
        int iFlags,
        IRecipientFilter *iPitch,
        const Vector *pOrigin,
        const Vector *pDirection,
        CUtlVector<Vector,CUtlMemory<Vector,int> > *pUtlVecOrigins,
        bool bUpdatePositions,
        float soundtime,
        int speakerentity)
{
  edict_t *v18; // eax

  if ( flVolume < 0.0 || flVolume > 1.0 )
  {
    _Warning(a1: "EmitSound: %s volume out of bounds = %f\n", pSample, flVolume);
  }
  else if ( (unsigned int)iSoundLevel > (SNDLVL_180dB|SNDLVL_75dB|0x100) )
  {
    _Warning(a1: "EmitSound: %s soundlevel out of bounds = %d\n", pSample, iSoundLevel);
  }
  else if ( (unsigned int)iPitch > 0xFF )
  {
    _Warning(a1: "EmitSound: %s pitch out of bounds = %i\n", pSample, iPitch);
  }
  else
  {
    if ( iEntIndex < 0 )
      v18 = nullptr;
    else
      v18 = &sv.edicts[iEntIndex];
    SV_StartSound(
      filter,
      pSoundEmittingEntity: v18,
      iChannel,
      pSoundEntry,
      iSoundEntryIndex,
      pSample,
      flVolume,
      iSoundLevel,
      iFlags,
      (int)iPitch,
      pOrigin,
      soundtime,
      speakerentity,
      pUtlVecOrigins,
      nSeed);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10001E10
// Name: public: virtual void CEngineSoundServer::EmitSentenceByIndex(class IRecipientFilter __near &,int,int,int,float,enum soundlevel_t,int,int,int,class Vector const __near *,class Vector const __near *,class CUtlVector<class Vector,class CUtlMemory<class Vector,int>> __near *,bool,float,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineSoundServer::EmitSentenceByIndex(
        CEngineSoundServer *this,
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
        bool bUpdatePositions,
        float soundtime,
        int speakerentity)
{
  char pDest[12]; // [esp+4h] [ebp-8h] BYREF

  if ( iSentenceIndex >= 0 )
  {
    V_snprintf(pDest, maxLen: 8, pFormat: "!%d", iSentenceIndex);
    CEngineSoundServer::EmitSoundInternal(
      this,
      filter,
      iEntIndex,
      iChannel,
      pSoundEntry: nullptr,
      iSoundEntryIndex: -1,
      pSample: pDest,
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
  }
}

//------------------------------------------------------------------------------
// Address: 0x10001E90
// Name: public: virtual int CEngineSoundServer::EmitSound(class IRecipientFilter __near &,int,int,char const __near *,int,char const __near *,float,float,int,int,int,class Vector const __near *,class Vector const __near *,class CUtlVector<class Vector,class CUtlMemory<class Vector,int>> __near *,bool,float,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CEngineSoundServer::EmitSound(
        CEngineSoundServer *this,
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
  ((void (__stdcall *)(IRecipientFilter *, int, int, const char *, int, const char *, _DWORD, int, int, int, int, IRecipientFilter *, const Vector *, CUtlVector<Vector,CUtlMemory<Vector,int> > *, const char *, _DWORD, const char *))this->EmitSound)(
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
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x10001F20
// Name: public: virtual int CEngineSoundServer::EmitSound(class IRecipientFilter __near &,int,int,char const __near *,int,char const __near *,float,enum soundlevel_t,int,int,int,class Vector const __near *,class Vector const __near *,class CUtlVector<class Vector,class CUtlMemory<class Vector,int>> __near *,bool,float,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CEngineSoundServer::EmitSound(
        CEngineSoundServer *this,
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
  if ( pSample != 0 && TestSoundChar(pch: (const char *)pSample, c: 33) )
  {
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
      ((void (__thiscall *)(CEngineSoundServer *, IRecipientFilter *, int, int, int, _DWORD, soundlevel_t, int, int, int, IRecipientFilter *, const Vector *, CUtlVector<Vector,CUtlMemory<Vector,int> > *, const char *, _DWORD, int))this->EmitSentenceByIndex)(
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
  else
  {
    CEngineSoundServer::EmitSoundInternal(
      this,
      filter,
      iEntIndex,
      iChannel,
      pSoundEntry,
      iSoundEntryIndex,
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
    return -1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10002050
// Name: float SV_GetSoundDuration(char const __near *)
// Source: json
//------------------------------------------------------------------------------
double __cdecl SV_GetSoundDuration(const char *pSample)
{
  return AudioSource_GetSoundDuration(pName: pSample);
}

//------------------------------------------------------------------------------
// Address: 0x10002060
// Name: public: virtual float CEngineSoundServer::GetSoundDuration(char const __near *)
// Source: json
//------------------------------------------------------------------------------
float __thiscall CEngineSoundServer::GetSoundDuration(CEngineSoundServer *this, const char *pSample)
{
  return Host_GetSoundDuration(pSample);
}

//------------------------------------------------------------------------------
// Address: 0x100020A0
// Name: public: virtual int CBaseServer::GetClientCount(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBaseServer::GetClientCount(vgui::Panel *this)
{
  return this->m_nPaintBackgroundType;
}

//------------------------------------------------------------------------------
// Address: 0x100020E0
// Name: public: virtual char const __near * SVC_Prefetch::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall SVC_Prefetch::GetName(SVC_Prefetch *this)
{
  return "svc_Prefetch";
}

//------------------------------------------------------------------------------
// Address: 0x100020F0
// Name: public: virtual bool SVC_Prefetch::Process(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall SVC_Prefetch::Process(SVC_Prefetch *this)
{
  return this->m_pMessageHandler->ProcessPrefetch(this: this->m_pMessageHandler, a2: this);
}

//------------------------------------------------------------------------------
// Address: 0x10002100
// Name: public: virtual void CEngineSoundServer::PrefetchSound(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineSoundServer::PrefetchSound(CEngineSoundServer *this, const char *pSample)
{
  int v2; // eax
  SVC_Prefetch msg; // [esp+4h] [ebp-14h] BYREF

  if ( pSample == nullptr || !TestSoundChar(pch: pSample, c: 33) )
  {
    v2 = SV_SoundIndex(name: pSample);
    if ( v2 != -1 )
    {
      msg.m_fType = 0;
      msg.m_bReliable = true;
      msg.m_NetChannel = nullptr;
      msg.__vftable = (SVC_Prefetch_vtbl *)&SVC_Prefetch::`vftable';
      msg.m_nSoundIndex = v2;
      CBaseServer::BroadcastMessage(this: &sv, &msg, onlyActive: true, reliable: false);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10002160
// Name: public: virtual void CEngineSoundServer::StopSound(int,int,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineSoundServer::StopSound(
        CEngineSoundServer *this,
        int iEntIndex,
        int iChannel,
        const char *pSample,
        int nSoundEntryIndex)
{
  CEngineRecipientFilter v6; // [esp+30h] [ebp-1Ch] BYREF

  CEngineRecipientFilter::CEngineRecipientFilter(this: &v6);
  CEngineRecipientFilter::AddAllPlayers(this: &v6);
  CEngineRecipientFilter::MakeReliable(this: &v6);
  ((void (__thiscall *)(CEngineSoundServer *, CEngineRecipientFilter *, int, int, const char *, int, const char *, _DWORD, _DWORD, _DWORD, int, int, _DWORD, _DWORD, _DWORD, int, _DWORD, int))this->EmitSound)(
    a1: this,
    a2: &v6,
    a3: iEntIndex,
    a4: iChannel,
    a5: pSample,
    a6: nSoundEntryIndex,
    a7: pSample,
    a8: 0.0,
    a9: 0,
    a10: 0,
    a11: (nSoundEntryIndex <= -1 ? 0 : 0x400) | 4,
    a12: 100,
    a13: 0,
    a14: 0,
    a15: 0,
    a16: 1,
    a17: 0.0,
    a18: -1);
  CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&v6.m_Recipients);
}

//------------------------------------------------------------------------------
// Address: 0x100021E0
// Name: void BuildRecipientList(class CUtlVector<struct edict_t __near *,class CUtlMemory<struct edict_t __near *,int>> __near &,class IRecipientFilter const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl BuildRecipientList(
        CUtlVector<vgui::PageTab *,CUtlMemory<vgui::PageTab *,int> > *list,
        IRecipientFilter *filter)
{
  IRecipientFilter *v2; // esi
  int v3; // edi
  int v4; // eax
  CBaseClient *v5; // ebx
  int c; // [esp+8h] [ebp-4h]

  v2 = filter;
  v3 = 0;
  c = filter->GetRecipientCount(this: filter);
  if ( c > 0 )
  {
    do
    {
      v4 = v2->GetRecipientIndex(this: v2, a2: v3);
      if ( v4 >= 1 && v4 <= sv.m_Clients.m_Size )
      {
        v5 = sv.m_Clients.m_Memory.m_pMemory[v4 - 1];
        if ( !v5->IsFakeClient(this: &v5->IClient) && v5->IsSpawned(this: &v5->IClient) )
          CUtlVector<RequestContext *,CUtlMemory<RequestContext *,int>>::InsertBefore(
            this: list,
            elem: list->m_Size,
            src: (vgui::PageTab *const *)v5[1].m_GUID);
        v2 = filter;
      }
      ++v3;
    }
    while ( v3 < c );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10002270
// Name: public: virtual void CEngineSoundServer::SetRoomType(class IRecipientFilter __near &,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineSoundServer::SetRoomType(CEngineSoundServer *this, IRecipientFilter *filter, int roomType)
{
  int v3; // esi
  int m_Size; // edi
  edict_t **m_pMemory; // ebx
  CUtlVector<edict_t *,CUtlMemory<edict_t *,int> > players; // [esp+Ch] [ebp-14h] BYREF

  v3 = 0;
  memset(&players, 0, sizeof(players));
  BuildRecipientList(list: &players, filter);
  m_Size = players.m_Size;
  m_pMemory = players.m_Memory.m_pMemory;
  if ( players.m_Size > 0 )
  {
    do
      g_pVEngineServer->ClientCommand(this: g_pVEngineServer, a2: m_pMemory[v3++], a3: "room_type %i\n", roomType);
    while ( v3 < m_Size );
  }
  if ( players.m_Memory.m_nGrowSize >= 0 && m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x100022F0
// Name: public: virtual void CEngineSoundServer::SetPlayerDSP(class IRecipientFilter __near &,int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineSoundServer::SetPlayerDSP(
        CEngineSoundServer *this,
        IRecipientFilter *filter,
        int dspType,
        bool fastReset)
{
  int v4; // esi
  int m_Size; // edi
  edict_t **m_pMemory; // ebx
  CUtlVector<edict_t *,CUtlMemory<edict_t *,int> > players; // [esp+0h] [ebp-14h] BYREF

  if ( fastReset )
    _Warning(a1: "SetPlayerDSP:  fastReset only valid from client\n");
  v4 = 0;
  memset(&players, 0, sizeof(players));
  BuildRecipientList(list: &players, filter);
  m_Size = players.m_Size;
  m_pMemory = players.m_Memory.m_pMemory;
  if ( players.m_Size > 0 )
  {
    do
      g_pVEngineServer->ClientCommand(this: g_pVEngineServer, a2: m_pMemory[v4++], a3: "dsp_player %i\n", dspType);
    while ( v4 < m_Size );
  }
  if ( players.m_Memory.m_nGrowSize >= 0 && m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x101C2CA0
// Name: public: virtual void CNetMessage::SetReliable(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNetMessage::SetReliable(CNetMessage *this, bool state)
{
  this->m_bReliable = state;
}

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x10001B80
// Name: public: virtual bool CEngineSoundServer::IsLoopingSound(char const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CEngineSoundServer::IsLoopingSound(CEngineSoundServer *this, const char *pSample)
{
  _Warning(a1: "Can't call IsLoopingSound from server\n");
  return false;
}

//------------------------------------------------------------------------------
// Address: 0x10001BA0
// Name: public: virtual int CEngineSoundServer::GetGuidForLastSoundEmitted(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CEngineSoundServer::GetGuidForLastSoundEmitted(CEngineSoundServer *this)
{
  _Warning(a1: "Can't call GetGuidForLastSoundEmitted from server\n");
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10001BC0
// Name: public: virtual bool CEngineSoundServer::IsSoundStillPlaying(int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CEngineSoundServer::IsSoundStillPlaying(CEngineSoundServer *this, int guid)
{
  _Warning(a1: "Can't call IsSoundStillPlaying from server\n");
  return false;
}

//------------------------------------------------------------------------------
// Address: 0x10001BE0
// Name: public: virtual void CEngineSoundServer::StopSoundByGuid(int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineSoundServer::StopSoundByGuid(CEngineSoundServer *this, int guid, bool bForce)
{
  _Warning(a1: "Can't call StopSoundByGuid from server\n");
}

//------------------------------------------------------------------------------
// Address: 0x10001C30
// Name: public: virtual void CEngineSoundServer::PrecacheSentenceGroup(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineSoundServer::PrecacheSentenceGroup(CEngineSoundClient *this, const char *pGroupName)
{
  VOX_PrecacheSentenceGroup(pSoundSystem: this, pGroupName, pPathOverride: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x10001C50
// Name: public: virtual bool CEngineSoundServer::GetSoundChannelVolume(char const __near *,float __near &,float __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CEngineSoundServer::GetSoundChannelVolume(
        CEngineSoundServer *this,
        const char *sound,
        float *flVolumeLeft,
        float *flVolumeRight)
{
  _Warning(a1: "Can't call GetSoundChannelVolume from server\n");
  return false;
}

//------------------------------------------------------------------------------
// Address: 0x10001C70
// Name: public: virtual bool CEngineSoundServer::PrecacheSound(char const __near *,bool,bool)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CEngineSoundServer::PrecacheSound(
        CEngineSoundServer *this,
        const char *pSample,
        bool bPreload,
        bool bIsUISound)
{
  IEngineVGuiInternal *v4; // eax

  v4 = EngineVGui();
  v4->UpdateProgressBar(this: v4, a2: PROGRESS_DEFAULT, a3: true);
  if ( pSample != nullptr && TestSoundChar(pch: pSample, c: 33) )
    return 1;
  if ( *pSample <= 32 )
    Host_Error(error: "CEngineSoundServer::PrecacheSound:  Bad string: %s", pSample);
  if ( SV_FindOrAddSound(name: pSample, preload: bPreload) >= 0 )
    return 1;
  Host_Error(error: "CEngineSoundServer::PrecacheSound: '%s' overflow", pSample);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10001CE0
// Name: public: virtual bool CEngineSoundServer::IsSoundPrecached(char const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CEngineSoundServer::IsSoundPrecached(CEngineSoundServer *this, const char *pSample)
{
  return pSample != nullptr && TestSoundChar(pch: pSample, c: 33) || SV_SoundIndex(name: pSample) != -1;
}

//------------------------------------------------------------------------------
// Address: 0x10001D20
// Name: private: void CEngineSoundServer::EmitSoundInternal(class IRecipientFilter __near &,int,int,char const __near *,int,char const __near *,float,enum soundlevel_t,int,int,int,class Vector const __near *,class Vector const __near *,class CUtlVector<class Vector,class CUtlMemory<class Vector,int>> __near *,bool,float,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineSoundServer::EmitSoundInternal(
        CEngineSoundServer *this,
        IRecipientFilter *filter,
        int iEntIndex,
        int iChannel,
        const char *pSoundEntry,
        int iSoundEntryIndex,
        const char *pSample,
        float flVolume,
        soundlevel_t iSoundLevel,
        int nSeed,
        int iFlags,
        unsigned int iPitch,
        const Vector *pOrigin,
        const Vector *pDirection,
        CUtlVector<Vector,CUtlMemory<Vector,int> > *pUtlVecOrigins,
        bool bUpdatePositions,
        float soundtime,
        int speakerentity)
{
  edict_t *v18; // eax

  if ( flVolume < 0.0 || flVolume > 1.0 )
  {
    _Warning(a1: "EmitSound: %s volume out of bounds = %f\n", pSample, flVolume);
  }
  else if ( (unsigned int)iSoundLevel > (SNDLVL_180dB|SNDLVL_75dB|0x100) )
  {
    _Warning(a1: "EmitSound: %s soundlevel out of bounds = %d\n", pSample, iSoundLevel);
  }
  else if ( iPitch > 0xFF )
  {
    _Warning(a1: "EmitSound: %s pitch out of bounds = %i\n", pSample, iPitch);
  }
  else
  {
    if ( iEntIndex < 0 )
      v18 = nullptr;
    else
      v18 = &sv.edicts[iEntIndex];
    SV_StartSound(
      filter,
      pSoundEmittingEntity: v18,
      iChannel,
      pSoundEntry,
      iSoundEntryIndex,
      pSample,
      flVolume,
      iSoundLevel,
      iFlags,
      iPitch,
      pOrigin,
      soundtime,
      speakerentity,
      pUtlVecOrigins,
      nSeed);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10001E00
// Name: public: virtual void CEngineSoundServer::EmitSentenceByIndex(class IRecipientFilter __near &,int,int,int,float,enum soundlevel_t,int,int,int,class Vector const __near *,class Vector const __near *,class CUtlVector<class Vector,class CUtlMemory<class Vector,int>> __near *,bool,float,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineSoundServer::EmitSentenceByIndex(
        CEngineSoundServer *this,
        IRecipientFilter *filter,
        int iEntIndex,
        int iChannel,
        int iSentenceIndex,
        float flVolume,
        soundlevel_t iSoundLevel,
        int nSeed,
        int iFlags,
        unsigned int iPitch,
        const Vector *pOrigin,
        const Vector *pDirection,
        CUtlVector<Vector,CUtlMemory<Vector,int> > *pUtlVecOrigins,
        bool bUpdatePositions,
        float soundtime,
        int speakerentity)
{
  char pName[8]; // [esp+30h] [ebp-8h] BYREF

  if ( iSentenceIndex >= 0 )
  {
    V_snprintf(pDest: pName, maxLen: 8, pFormat: "!%d", iSentenceIndex);
    CEngineSoundServer::EmitSoundInternal(
      this,
      filter,
      iEntIndex,
      iChannel,
      pSoundEntry: nullptr,
      iSoundEntryIndex: -1,
      pSample: pName,
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
  }
}

//------------------------------------------------------------------------------
// Address: 0x10001E80
// Name: public: virtual int CEngineSoundServer::EmitSound(class IRecipientFilter __near &,int,int,char const __near *,int,char const __near *,float,float,int,int,int,class Vector const __near *,class Vector const __near *,class CUtlVector<class Vector,class CUtlMemory<class Vector,int>> __near *,bool,float,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CEngineSoundServer::EmitSound(
        CEngineSoundServer *this,
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
  ((void (__stdcall *)(IRecipientFilter *, int, int, const char *, int, const char *, _DWORD, int, int, int, int, const Vector *, const Vector *, CUtlVector<Vector,CUtlMemory<Vector,int> > *, int, _DWORD, int))this->EmitSound)(
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
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x10001F10
// Name: public: virtual int CEngineSoundServer::EmitSound(class IRecipientFilter __near &,int,int,char const __near *,int,char const __near *,float,enum soundlevel_t,int,int,int,class Vector const __near *,class Vector const __near *,class CUtlVector<class Vector,class CUtlMemory<class Vector,int>> __near *,bool,float,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CEngineSoundServer::EmitSound(
        CEngineSoundServer *this,
        IRecipientFilter *filter,
        int iEntIndex,
        int iChannel,
        const char *pSoundEntry,
        int iSoundEntryIndex,
        int pSample,
        float flVolume,
        soundlevel_t iSoundLevel,
        int nSeed,
        int iFlags,
        unsigned int iPitch,
        const Vector *pOrigin,
        const Vector *pDirection,
        CUtlVector<Vector,CUtlMemory<Vector,int> > *pUtlVecOrigins,
        BOOL bUpdatePositions,
        float soundtime,
        int speakerentity)
{
  const char *v18; // esi
  const char *v20; // eax
  const char *v22; // eax

  v18 = (const char *)pSample;
  if ( pSample != 0 && TestSoundChar(pch: (const char *)pSample, c: 33) )
  {
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
      ((void (__thiscall *)(CEngineSoundServer *, IRecipientFilter *, int, int, int, _DWORD, soundlevel_t, int, int, unsigned int, const Vector *, const Vector *, CUtlVector<Vector,CUtlMemory<Vector,int> > *, BOOL, _DWORD, int))this->EmitSentenceByIndex)(
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
  else
  {
    CEngineSoundServer::EmitSoundInternal(
      this,
      filter,
      iEntIndex,
      iChannel,
      pSoundEntry,
      iSoundEntryIndex,
      pSample: v18,
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
    return -1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10002030
// Name: float SV_GetSoundDuration(char const __near *)
// Source: json
//------------------------------------------------------------------------------
double __cdecl SV_GetSoundDuration(const char *pSample)
{
  return AudioSource_GetSoundDuration(pName: pSample);
}

//------------------------------------------------------------------------------
// Address: 0x10002040
// Name: public: virtual float CEngineSoundServer::GetSoundDuration(char const __near *)
// Source: json
//------------------------------------------------------------------------------
float __thiscall CEngineSoundServer::GetSoundDuration(CEngineSoundServer *this, const char *pSample)
{
  return Host_GetSoundDuration(pSample);
}

//------------------------------------------------------------------------------
// Address: 0x100020D0
// Name: public: virtual char const __near * SVC_Prefetch::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall SVC_Prefetch::GetName(SVC_Prefetch *this)
{
  return "svc_Prefetch";
}

//------------------------------------------------------------------------------
// Address: 0x10002150
// Name: public: virtual void CEngineSoundServer::StopSound(int,int,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineSoundServer::StopSound(
        CEngineSoundServer *this,
        int iEntIndex,
        int iChannel,
        const char *pSample,
        int nSoundEntryIndex)
{
  CEngineRecipientFilter filter; // [esp+30h] [ebp-1Ch] BYREF

  CEngineRecipientFilter::CEngineRecipientFilter(this: &filter);
  CEngineRecipientFilter::AddAllPlayers(this: &filter);
  CEngineRecipientFilter::MakeReliable(this: &filter);
  ((void (__thiscall *)(CEngineSoundServer *, CEngineRecipientFilter *, int, int, const char *, int, const char *, _DWORD, _DWORD, _DWORD, int, int, _DWORD, _DWORD, _DWORD, int, _DWORD, int))this->EmitSound)(
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
    a11: (nSoundEntryIndex <= -1 ? 0 : 0x400) | 4,
    a12: 100,
    a13: 0,
    a14: 0,
    a15: 0,
    a16: 1,
    a17: 0.0,
    a18: -1);
  CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&filter.m_Recipients);
}

//------------------------------------------------------------------------------
// Address: 0x100021D0
// Name: void BuildRecipientList(class CUtlVector<struct edict_t __near *,class CUtlMemory<struct edict_t __near *,int>> __near &,class IRecipientFilter const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl BuildRecipientList(
        CUtlVector<vgui::PageTab *,CUtlMemory<vgui::PageTab *,int> > *list,
        IRecipientFilter *filter)
{
  IRecipientFilter *v2; // esi
  int v3; // edi
  int v4; // eax
  CBaseClient *v5; // ebx
  int c; // [esp+8h] [ebp-4h]

  v2 = filter;
  v3 = 0;
  c = filter->GetRecipientCount(this: filter);
  if ( c > 0 )
  {
    do
    {
      v4 = v2->GetRecipientIndex(this: v2, a2: v3);
      if ( v4 >= 1 && v4 <= sv.m_Clients.m_Size )
      {
        v5 = sv.m_Clients.m_Memory.m_pMemory[v4 - 1];
        if ( !v5->IsFakeClient(this: &v5->IClient) && v5->IsSpawned(this: &v5->IClient) )
          CUtlVector<RequestContext *,CUtlMemory<RequestContext *,int>>::InsertBefore(
            this: list,
            elem: list->m_Size,
            src: (vgui::PageTab *const *)v5[1].m_GUID);
        v2 = filter;
      }
      ++v3;
    }
    while ( v3 < c );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10002260
// Name: public: virtual void CEngineSoundServer::SetRoomType(class IRecipientFilter __near &,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineSoundServer::SetRoomType(CEngineSoundServer *this, IRecipientFilter *filter, int roomType)
{
  int v3; // esi
  int m_Size; // edi
  edict_t **m_pMemory; // ebx
  CUtlVector<edict_t *,CUtlMemory<edict_t *,int> > players; // [esp+Ch] [ebp-14h] BYREF

  v3 = 0;
  memset(&players, 0, sizeof(players));
  BuildRecipientList(list: (CUtlVector<vgui::PageTab *,CUtlMemory<vgui::PageTab *,int> > *)&players, filter);
  m_Size = players.m_Size;
  m_pMemory = players.m_Memory.m_pMemory;
  if ( players.m_Size > 0 )
  {
    do
      g_pVEngineServer->ClientCommand(this: g_pVEngineServer, a2: m_pMemory[v3++], a3: "room_type %i\n", roomType);
    while ( v3 < m_Size );
  }
  if ( players.m_Memory.m_nGrowSize >= 0 && m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x100022E0
// Name: public: virtual void CEngineSoundServer::SetPlayerDSP(class IRecipientFilter __near &,int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineSoundServer::SetPlayerDSP(
        CEngineSoundServer *this,
        IRecipientFilter *filter,
        int dspType,
        bool fastReset)
{
  int v4; // esi
  int m_Size; // edi
  edict_t **m_pMemory; // ebx
  CUtlVector<edict_t *,CUtlMemory<edict_t *,int> > players; // [esp+0h] [ebp-14h] BYREF

  if ( fastReset )
    _Warning(a1: "SetPlayerDSP:  fastReset only valid from client\n");
  v4 = 0;
  memset(&players, 0, sizeof(players));
  BuildRecipientList(list: (CUtlVector<vgui::PageTab *,CUtlMemory<vgui::PageTab *,int> > *)&players, filter);
  m_Size = players.m_Size;
  m_pMemory = players.m_Memory.m_pMemory;
  if ( players.m_Size > 0 )
  {
    do
      g_pVEngineServer->ClientCommand(this: g_pVEngineServer, a2: m_pMemory[v4++], a3: "dsp_player %i\n", dspType);
    while ( v4 < m_Size );
  }
  if ( players.m_Memory.m_nGrowSize >= 0 && m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x101C3130
// Name: public: virtual void CNetMessage::SetReliable(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNetMessage::SetReliable(CNetMessage *this, bool state)
{
  this->m_bReliable = state;
}

//------------------------------------------------------------------------------
// Address: 0x102873F0
// Name: public: virtual int CBaseServer::GetClientCount(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBaseServer::GetClientCount(vgui::Panel *this)
{
  return this->m_nPaintBackgroundType;
}

} // namespace engine_xlsp
