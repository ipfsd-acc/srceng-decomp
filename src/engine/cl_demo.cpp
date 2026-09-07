// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: engine/cl_demo.cpp
// Functions: 80
// ============================================================

#include "engine\cl_demo.h"

//------------------------------------------------------------------------------
// Address: 0x100712E0
// Name: public: void DemoOverlay::DrawOverlay(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall DemoOverlay::DrawOverlay(DemoOverlay *this, float fSetting)
{
  float v2; // xmm1_4
  int v4; // ebx
  int v5; // esi
  con_nprint_s xprn; // [esp+0h] [ebp-18h] BYREF

  v2 = fSetting;
  if ( fSetting >= 0.0 && (fSetting == 0.0 || this->m_maskDrawnOverlay != 0) )
  {
    v4 = 0;
  }
  else
  {
    v5 = demoplayer->IsPlayingBack(this: demoplayer) ? 4 : 0;
    v2 = fSetting;
    v4 = v5 | (demorecorder->IsRecording(this: demorecorder) ? 2 : 0);
    if ( v4 != 0 )
      goto LABEL_8;
  }
  if ( this->m_maskDrawnOverlay != 0 )
  {
    memset(xprn.color, 0, 16);
    xprn.index = 1;
    xprn.time_to_live = -1.0;
    Con_NXPrintf(info: &xprn, fmt: defaultValue);
    v2 = fSetting;
  }
LABEL_8:
  if ( (v4 & 4) != 0 )
  {
    *(_DWORD *)&xprn.fixed_width_font = 1;
    xprn.time_to_live = 0.0;
    xprn.index = 1;
    xprn.color[0] = 0.0;
    xprn.color[1] = 1.0;
    xprn.color[2] = 0.0;
    if ( v2 <= 0.0 )
      xprn.time_to_live = 1.0;
    else
      xprn.time_to_live = v2;
    Con_NXPrintf(info: &xprn, fmt: "  PLAY   ");
    v2 = fSetting;
  }
  if ( (v4 & 2) != 0 )
  {
    *(_DWORD *)&xprn.fixed_width_font = 1;
    xprn.time_to_live = 0.0;
    xprn.index = 1;
    xprn.color[0] = 1.0;
    xprn.color[1] = 0.0;
    xprn.color[2] = 0.0;
    if ( v2 <= 0.0 )
      xprn.time_to_live = 1.0;
    else
      xprn.time_to_live = v2;
    Con_NXPrintf(info: &xprn, fmt: "   REC   ");
  }
  this->m_maskDrawnOverlay = v4;
}

//------------------------------------------------------------------------------
// Address: 0x10071460
// Name: public: virtual void CDemoRecorder::RecordCustomData(int,void const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDemoRecorder::RecordCustomData(
        CDemoRecorder *this,
        int iCallbackIndex,
        const void *pData,
        unsigned int iDataLength)
{
  int v5; // eax

  if ( CDemoFile::IsOpen(this: &this->m_DemoFile) )
  {
    v5 = this->GetRecordingTick(this);
    CDemoFile::WriteCustomData(this: &this->m_DemoFile, iCallbackIndex, pData, iDataSize: iDataLength, tick: v5);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100714A0
// Name: public: virtual void CDemoRecorder::ResetDemoInterpolation(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDemoRecorder::ResetDemoInterpolation(CDemoRecorder *this)
{
  this->m_bResetInterpolation = true;
}

//------------------------------------------------------------------------------
// Address: 0x100714B0
// Name: public: virtual class CDemoFile __near * CDemoPlayer::GetDemoFile(void)
// Source: json
//------------------------------------------------------------------------------
CDemoFile *__thiscall CDemoPlayer::GetDemoFile(CDemoPlayer *this)
{
  return &this->m_DemoFile;
}

//------------------------------------------------------------------------------
// Address: 0x100714C0
// Name: public: virtual bool CDemoPlayer::IsSkipping(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CDemoPlayer::IsSkipping(CDemoPlayer *this)
{
  return this->m_bPlayingBack && this->m_nSkipToTick != -1;
}

//------------------------------------------------------------------------------
// Address: 0x100714E0
// Name: public: virtual int CDemoPlayer::GetTotalTicks(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDemoPlayer::GetTotalTicks(CDemoPlayer *this)
{
  return this->m_DemoFile.m_DemoHeader.playback_ticks;
}

//------------------------------------------------------------------------------
// Address: 0x100714F0
// Name: public: virtual void CDemoPlayer::SkipToTick(int,bool,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDemoPlayer::SkipToTick(CDemoPlayer *this, int tick, bool bRelative, bool bPause)
{
  int v5; // edi
  char pDest[12]; // [esp+Ch] [ebp-104h] BYREF

  if ( bRelative )
    v5 = this->GetPlaybackTick(this) + tick;
  else
    v5 = tick;
  if ( v5 >= 0 )
  {
    if ( v5 < this->GetPlaybackTick(this) )
    {
      V_strncpy(pDest, pSrc: this->m_DemoFile.m_szFileName, maxLen: 260);
      this->StartPlayback(this, a2: pDest, a3: this->m_bTimeDemo);
      if ( v5 > 0 )
        v5 |= 0x88000000;
    }
    this->m_nSkipToTick = v5;
    if ( bPause )
      ((void (__thiscall *)(CDemoPlayer *, _DWORD))this->PausePlayback)(a1: this, a2: -1.0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10071590
// Name: public: virtual bool CDemoPlayer::IsPlayingTimeDemo(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CDemoPlayer::IsPlayingTimeDemo(CDemoPlayer *this)
{
  return this->m_bTimeDemo && this->m_bPlayingBack;
}

//------------------------------------------------------------------------------
// Address: 0x100715B0
// Name: public: virtual bool CDemoPlayer::IsPlayingBack(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDemoPlayer::IsPlayingBack(CDemoPlayer *this)
{
  return this->m_bPlayingBack;
}

//------------------------------------------------------------------------------
// Address: 0x100715C0
// Name: public: void CDemoPlayer::MarkFrame(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDemoPlayer::MarkFrame(CDemoPlayer *this, float flFPSVariability)
{
  this->m_flTotalFPSVariability = flFPSVariability + this->m_flTotalFPSVariability;
}

//------------------------------------------------------------------------------
// Address: 0x100715E0
// Name: public: virtual void CDemoPlayer::PausePlayback(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDemoPlayer::PausePlayback(CDemoPlayer *this, float seconds)
{
  this->m_bPlaybackPaused = true;
  if ( seconds <= 0.0 )
    this->m_flAutoResumeTime = 0.0;
  else
    this->m_flAutoResumeTime = _Plat_FloatTime() + seconds;
}

//------------------------------------------------------------------------------
// Address: 0x10071620
// Name: public: virtual void CDemoPlayer::ResumePlayback(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDemoPlayer::ResumePlayback(CDemoPlayer *this)
{
  this->m_bPlaybackPaused = false;
  this->m_flAutoResumeTime = 0.0;
}

//------------------------------------------------------------------------------
// Address: 0x10071640
// Name: public: virtual bool CDemoPlayer::IsPlaybackPaused(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDemoPlayer::IsPlaybackPaused(CDemoPlayer *this)
{
  return this->IsPlayingBack(this)
      && this->m_nTimeDemoCurrentFrame >= 0
      && !this->IsSkipping(this)
      && this->m_bPlaybackPaused;
}

//------------------------------------------------------------------------------
// Address: 0x10071670
// Name: public: virtual int CDemoPlayer::GetPlaybackStartTick(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDemoPlayer::GetPlaybackStartTick(CDemoPlayer *this)
{
  return this->m_nStartTick;
}

//------------------------------------------------------------------------------
// Address: 0x10071680
// Name: public: virtual int CDemoPlayer::GetPlaybackTick(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDemoPlayer::GetPlaybackTick(CDemoPlayer *this)
{
  return host_tickcount - this->m_nStartTick;
}

//------------------------------------------------------------------------------
// Address: 0x10071690
// Name: public: virtual float CDemoPlayer::GetPlaybackTimeScale(void)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CDemoPlayer::GetPlaybackTimeScale(CDemoPlayer *this)
{
  return this->m_flPlaybackRateModifier;
}

//------------------------------------------------------------------------------
// Address: 0x100716A0
// Name: public: virtual void CDemoPlayer::SetPlaybackTimeScale(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDemoPlayer::SetPlaybackTimeScale(CDemoPlayer *this, float timescale)
{
  this->m_flPlaybackRateModifier = timescale;
}

//------------------------------------------------------------------------------
// Address: 0x100716C0
// Name: ComputeNextIncrementalDemoFilename
// Source: json
//------------------------------------------------------------------------------
char __usercall ComputeNextIncrementalDemoFilename@<al>(char *name@<edi>, int a2@<esi>, int namesize)
{
  void *v3; // eax
  int v5; // esi
  void *v6; // eax
  char basename[260]; // [esp+0h] [ebp-208h] BYREF
  char newname[260]; // [esp+104h] [ebp-104h] BYREF

  v3 = g_pFileSystem->Open(this: &g_pFileSystem->IBaseFileSystem, a2: name, a3: "rb", a4: 0);
  if ( v3 == nullptr )
    return 1;
  ((void (__thiscall *)(IBaseFileSystem *, void *, int))g_pFileSystem->Close)(
    a1: &g_pFileSystem->IBaseFileSystem,
    a2: v3,
    a3: a2);
  V_StripExtension(in: name, out: basename, outSize: 260);
  v5 = 0;
  while ( 1 )
  {
    V_snprintf(pDest: newname, maxLen: 260, pFormat: "%s%03i.dem", basename, v5);
    v6 = g_pFileSystem->Open(this: &g_pFileSystem->IBaseFileSystem, a2: newname, a3: "rb", a4: 0);
    if ( v6 == nullptr )
      break;
    g_pFileSystem->Close(this: &g_pFileSystem->IBaseFileSystem, a2: v6);
    if ( ++v5 >= 1000 )
    {
      ConMsg(
        a1: "Unable to find a valid incremental demo filename for %s, try clearing the directory of %snnn.dem\n",
        name,
        basename);
      return 0;
    }
  }
  V_strncpy(pDest: name, pSrc: newname, maxLen: namesize);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100717B0
// Name: stop
// Source: json
//------------------------------------------------------------------------------
void __cdecl stop()
{
  if ( cmd_source == src_command )
  {
    if ( demorecorder->IsRecording(this: demorecorder) )
    {
      demorecorder->StopRecording(this: demorecorder);
      g_ClientDLL->OnDemoRecordStop(this: g_ClientDLL);
    }
    else
    {
      _ConDMsg(a1: "Not recording a demo.\n");
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10071800
// Name: DemoRecord
// Source: json
//------------------------------------------------------------------------------
void __usercall DemoRecord(const char *pchDemoFileName@<esi>, BOOL incremental)
{
  char name[260]; // [esp+4h] [ebp-104h] BYREF

  if ( g_ClientDLL != nullptr )
  {
    if ( demorecorder->IsRecording(this: demorecorder) )
    {
      ConMsg(a1: "Already recording.\n");
    }
    else if ( demoplayer->IsPlayingBack(this: demoplayer) )
    {
      ConMsg(a1: "Can't record during demo playback.\n");
    }
    else if ( COM_IsValidPath(pszFilename: pchDemoFileName) )
    {
      if ( g_ClientDLL->CanRecordDemo(this: g_ClientDLL, a2: name, a3: 260) )
      {
        V_StripExtension(in: pchDemoFileName, out: name, outSize: 260);
        if ( !incremental || ComputeNextIncrementalDemoFilename(name, a2: (int)pchDemoFileName, namesize: 260) != 0 )
        {
          g_ClientDLL->OnDemoRecordStart(this: g_ClientDLL, a2: name);
          demorecorder->StartRecording(this: demorecorder, a2: name, a3: incremental);
        }
      }
      else
      {
        ConMsg(a1: "%s\n", name);
      }
    }
    else
    {
      ConMsg(a1: "record %s: invalid path.\n", pchDemoFileName);
    }
  }
  else
  {
    ConMsg(a1: "Can't record on dedicated server.\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x10071930
// Name: void CL_TimeDemo_Helper(char const __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CL_TimeDemo_Helper(const char *pDemoName, const char *pStatsFileName, const char *pVProfStatsFileName)
{
  const char *v3; // eax
  char name[260]; // [esp+0h] [ebp-104h] BYREF

  v3 = pStatsFileName;
  if ( pStatsFileName == nullptr )
    v3 = "UNKNOWN";
  V_strncpy(pDest: g_pStatsFile, pSrc: v3, maxLen: 260);
  demoplayer = g_pClientDemoPlayer;
  V_strncpy(pDest: name, pSrc: pDemoName, maxLen: 260);
  V_DefaultExtension(path: name, extension: ".dem", pathStringLength: 260);
  if ( pVProfStatsFileName != nullptr )
    CEngineStats::EnableVProfStatsRecording(this: &g_EngineStats, pFileName: pVProfStatsFileName);
  if ( !demoplayer->StartPlayback(this: demoplayer, a2: name, a3: true) )
    SCR_EndLoadingPlaque();
}

//------------------------------------------------------------------------------
// Address: 0x100719D0
// Name: g_playdemo_CompletionFunc
// Source: json
//------------------------------------------------------------------------------
int __cdecl g_playdemo_CompletionFunc(char *partial, char (*commands)[64])
{
  if ( (_S3_0 & 1) == 0 )
  {
    _S3_0 |= 1u;
    playdemoComplete.m_pszCommandName = "playdemo";
    playdemoComplete.m_pszSubDir = nullptr;
    playdemoComplete.m_pszExtension = "dem";
  }
  return CBaseAutoCompleteFileList::AutoCompletionFunc(this: &playdemoComplete, partial, commands);
}

//------------------------------------------------------------------------------
// Address: 0x10071A20
// Name: g_timedemo_CompletionFunc
// Source: json
//------------------------------------------------------------------------------
int __cdecl g_timedemo_CompletionFunc(char *partial, char (*commands)[64])
{
  if ( (_S4 & 1) == 0 )
  {
    _S4 |= 1u;
    timedemoComplete.m_pszCommandName = "timedemo";
    timedemoComplete.m_pszSubDir = nullptr;
    timedemoComplete.m_pszExtension = "dem";
  }
  return CBaseAutoCompleteFileList::AutoCompletionFunc(this: &timedemoComplete, partial, commands);
}

//------------------------------------------------------------------------------
// Address: 0x10071A70
// Name: g_timedemoquit_CompletionFunc
// Source: json
//------------------------------------------------------------------------------
int __cdecl g_timedemoquit_CompletionFunc(char *partial, char (*commands)[64])
{
  if ( (_S5 & 1) == 0 )
  {
    _S5 |= 1u;
    timedemoquitComplete.m_pszCommandName = "timedemoquit";
    timedemoquitComplete.m_pszSubDir = nullptr;
    timedemoquitComplete.m_pszExtension = "dem";
  }
  return CBaseAutoCompleteFileList::AutoCompletionFunc(this: &timedemoquitComplete, partial, commands);
}

//------------------------------------------------------------------------------
// Address: 0x10071AC0
// Name: g_listdemo_CompletionFunc
// Source: json
//------------------------------------------------------------------------------
int __cdecl g_listdemo_CompletionFunc(char *partial, char (*commands)[64])
{
  if ( (_S6 & 1) == 0 )
  {
    _S6 |= 1u;
    listdemoComplete.m_pszCommandName = "listdemo";
    listdemoComplete.m_pszSubDir = nullptr;
    listdemoComplete.m_pszExtension = "dem";
  }
  return CBaseAutoCompleteFileList::AutoCompletionFunc(this: &listdemoComplete, partial, commands);
}

//------------------------------------------------------------------------------
// Address: 0x10071B10
// Name: g_benchframe_CompletionFunc
// Source: json
//------------------------------------------------------------------------------
int __cdecl g_benchframe_CompletionFunc(char *partial, char (*commands)[64])
{
  if ( (_S7_0 & 1) == 0 )
  {
    _S7_0 |= 1u;
    benchframeComplete.m_pszCommandName = "benchframe";
    benchframeComplete.m_pszSubDir = nullptr;
    benchframeComplete.m_pszExtension = "dem";
  }
  return CBaseAutoCompleteFileList::AutoCompletionFunc(this: &benchframeComplete, partial, commands);
}

//------------------------------------------------------------------------------
// Address: 0x10071B60
// Name: g_timedemo_vprofrecord_CompletionFunc
// Source: json
//------------------------------------------------------------------------------
int __cdecl g_timedemo_vprofrecord_CompletionFunc(char *partial, char (*commands)[64])
{
  if ( (_S8 & 1) == 0 )
  {
    _S8 |= 1u;
    timedemo_vprofrecordComplete.m_pszCommandName = "timedemo_vprofrecord";
    timedemo_vprofrecordComplete.m_pszSubDir = nullptr;
    timedemo_vprofrecordComplete.m_pszExtension = "dem";
  }
  return CBaseAutoCompleteFileList::AutoCompletionFunc(this: &timedemo_vprofrecordComplete, partial, commands);
}

//------------------------------------------------------------------------------
// Address: 0x10071BB0
// Name: demo_resume
// Source: json
//------------------------------------------------------------------------------
void __cdecl demo_resume()
{
  demoplayer->ResumePlayback(this: demoplayer);
}

//------------------------------------------------------------------------------
// Address: 0x10071BC0
// Name: demo_togglepause
// Source: json
//------------------------------------------------------------------------------
void __cdecl demo_togglepause()
{
  bool v0; // zf
  IDemoPlayer_vtbl *v1; // eax

  if ( demoplayer->IsPlayingBack(this: demoplayer) )
  {
    v0 = !demoplayer->IsPlaybackPaused(this: demoplayer);
    v1 = demoplayer->__vftable;
    if ( v0 )
      ((void (__stdcall *)(_DWORD))v1->PausePlayback)(a1: -1.0);
    else
      ((void (*)(void))v1->ResumePlayback)();
  }
}

//------------------------------------------------------------------------------
// Address: 0x10071C00
// Name: protected: bool CDemoPlayer::OverrideView(struct democmdinfo_t __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDemoPlayer::OverrideView(CDemoPlayer *this, democmdinfo_t *info)
{
  CDemoUIPanel_vtbl *v3; // ebx
  int v4; // eax
  bool result; // al
  CDemoUIPanel2_vtbl *v6; // ebx
  int v7; // eax
  IDemoActionManager_vtbl *v8; // ebx
  int v9; // eax

  result = true;
  if ( g_pDemoUI == nullptr
    || (v3 = g_pDemoUI->__vftable, v4 = this->GetPlaybackTick(this),
                                   !v3->OverrideView(this: g_pDemoUI, a2: info, a3: v4)) )
  {
    if ( g_pDemoUI2 == nullptr
      || (v6 = g_pDemoUI2->__vftable,
          v7 = this->GetPlaybackTick(this),
          !v6->OverrideView(this: g_pDemoUI2, a2: info, a3: v7)) )
    {
      if ( demoaction == nullptr )
        return false;
      v8 = demoaction->__vftable;
      v9 = this->GetPlaybackTick(this);
      if ( !v8->OverrideView(this: demoaction, a2: info, a3: v9) )
        return false;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10071C90
// Name: public: virtual void CDemoPlayer::ResetDemoInterpolation(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDemoPlayer::ResetDemoInterpolation(CDemoPlayer *this)
{
  this->m_bResetInterpolation = true;
}

//------------------------------------------------------------------------------
// Address: 0x10071CA0
// Name: public: ICvar::Iterator::~Iterator(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ICvar::Iterator::~Iterator(ICvar::Iterator *this)
{
  free(pMem: this->m_pIter);
}

//------------------------------------------------------------------------------
// Address: 0x10071CB0
// Name: public: void bf_write::WriteUBitLong(unsigned int,int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall bf_write::WriteUBitLong(bf_write *this, unsigned int curData, int numbits, bool bCheckRange)
{
  int m_iCurBit; // ecx
  int m_nDataBits; // eax
  int v7; // edx
  int v8; // ecx
  int v9; // edx

  m_iCurBit = this->m_iCurBit;
  m_nDataBits = this->m_nDataBits;
  if ( m_iCurBit + numbits <= m_nDataBits )
  {
    v7 = m_iCurBit;
    v8 = m_iCurBit & 0x1F;
    v9 = v7 >> 5;
    *(_DWORD *)&this->m_pData[4 * v9] = (curData << v8)
                                      | *(_DWORD *)&this->m_pData[4 * v9] & g_BitWriteMasks[0][32 * v8 + v8 + numbits];
    if ( 32 - v8 < numbits )
      *(_DWORD *)&this->m_pData[4 * v9 + 4] = (curData >> (32 - v8))
                                            | *(_DWORD *)&this->m_pData[4 * v9 + 4]
                                            & g_BitWriteMasks[0][numbits - (32 - v8)];
    this->m_iCurBit += numbits;
  }
  else
  {
    this->m_iCurBit = m_nDataBits;
    this->m_bOverflow = true;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10071D40
// Name: public: void democmdinfo_t::Reset(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall democmdinfo_t::Reset(democmdinfo_t *this)
{
  this->u[0].flags = 0;
  this->u[0].viewOrigin2 = this->u[0].viewOrigin;
  this->u[0].viewAngles2 = this->u[0].viewAngles;
  this->u[0].localViewAngles2 = this->u[0].localViewAngles;
  this->u[1].flags = 0;
  this->u[1].viewOrigin2 = this->u[1].viewOrigin;
  this->u[1].viewAngles2 = this->u[1].viewAngles;
  this->u[1].localViewAngles2 = this->u[1].localViewAngles;
}

//------------------------------------------------------------------------------
// Address: 0x10071DD0
// Name: public: struct democmdinfo_t __near & democmdinfo_t::operator=(struct democmdinfo_t const __near &)
// Source: json
//------------------------------------------------------------------------------
democmdinfo_t *__thiscall democmdinfo_t::operator=(democmdinfo_t *this, const democmdinfo_t *__that)
{
  democmdinfo_t *result; // eax

  result = this;
  if ( this != __that )
    this->u[0] = __that->u[0];
  if ( &this->u[1] != &__that->u[1] )
    this->u[1] = __that->u[1];
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10071F00
// Name: public: virtual int CDemoRecorder::GetRecordingTick(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDemoRecorder::GetRecordingTick(CDemoRecorder *this)
{
  if ( GetBaseLocalClient()->m_nMaxClients <= 1 )
    return GetBaseLocalClient()->m_ClockDriftMgr.m_nClientTick - this->m_nStartTick;
  else
    return (int)(net_time / host_state.interval_per_tick + 0.5) - this->m_nStartTick;
}

//------------------------------------------------------------------------------
// Address: 0x10071F50
// Name: protected: void CDemoRecorder::ResyncDemoClock(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDemoRecorder::ResyncDemoClock(CDemoRecorder *this)
{
  if ( GetBaseLocalClient()->m_nMaxClients <= 1 )
    this->m_nStartTick = GetBaseLocalClient()->m_ClockDriftMgr.m_nClientTick;
  else
    this->m_nStartTick = (int)(net_time / host_state.interval_per_tick + 0.5);
}

//------------------------------------------------------------------------------
// Address: 0x10071FA0
// Name: protected: void CDemoRecorder::GetClientCmdInfo(struct democmdinfo_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDemoRecorder::GetClientCmdInfo(CDemoRecorder *this, democmdinfo_t *cmdInfo)
{
  int v2; // edi
  float *p_z; // esi

  v2 = 0;
  if ( host_state.max_splitscreen_players > 0 )
  {
    p_z = &cmdInfo->u[0].viewAngles.z;
    do
    {
      *(p_z - 6) = 0.0;
      if ( this->m_bResetInterpolation )
      {
        *((_DWORD *)p_z - 6) = 4;
        this->m_bResetInterpolation = false;
      }
      g_pClientSidePrediction->GetViewOrigin(this: g_pClientSidePrediction, a2: (Vector *)(p_z - 5));
      *(QAngle *)(p_z - 2) = GetLocalClient(nSlot: -1)->viewangles;
      g_pClientSidePrediction->GetLocalViewAngles(this: g_pClientSidePrediction, a2: (QAngle *)(p_z + 1));
      p_z[4] = 0.0;
      p_z[5] = 0.0;
      p_z[6] = 0.0;
      p_z[7] = 0.0;
      p_z[8] = 0.0;
      p_z[9] = 0.0;
      p_z[10] = 0.0;
      p_z[11] = 0.0;
      p_z[12] = 0.0;
      ++v2;
      p_z += 19;
    }
    while ( v2 < host_state.max_splitscreen_players );
  }
  this->m_bResetInterpolation = false;
}

//------------------------------------------------------------------------------
// Address: 0x10072080
// Name: public: virtual void CDemoRecorder::RecordUserInput(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDemoRecorder::RecordUserInput(CDemoRecorder *this, int cmdnumber)
{
  int v3; // esi
  int v4; // eax
  char buffer[256]; // [esp+4h] [ebp-11Ch] BYREF
  bf_write msg; // [esp+104h] [ebp-1Ch] BYREF
  CDemoFile *p_m_DemoFile; // [esp+11Ch] [ebp-4h]

  p_m_DemoFile = &this->m_DemoFile;
  if ( CDemoFile::IsOpen(this: &this->m_DemoFile) )
  {
    bf_write::bf_write(this: &msg, pDebugName: "CDemo::WriteUserCmd", pData: buffer, nBytes: 256, nBits: -1);
    ((void (__thiscall *)(IBaseClientDLL *, _DWORD, bf_write *))g_ClientDLL->EncodeUserCmdToBuffer)(
      a1: g_ClientDLL,
      a2: 0,
      a3: &msg);
    v3 = (msg.m_iCurBit + 7) >> 3;
    v4 = ((int (__thiscall *)(CDemoRecorder *, _DWORD))this->GetRecordingTick)(a1: this, a2: 0);
    CDemoFile::WriteUserCmd(this: p_m_DemoFile, cmdnumber, buffer, bytes: v3, tick: v4, nPlayerSlot: cmdnumber);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10072100
// Name: protected: void CDemoRecorder::WriteDemoCvars(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDemoRecorder::WriteDemoCvars(CDemoRecorder *this)
{
  ICvar::ICVarIteratorInternal *v2; // ebx
  ConCommandBase *v3; // esi
  const char *m_pszName; // eax
  const char *v5; // eax
  const char *v6; // eax
  int v7; // eax
  const char *v8; // [esp-Ch] [ebp-114h]
  char cvarcmd[260]; // [esp+4h] [ebp-104h] BYREF

  if ( CDemoFile::IsOpen(this: &this->m_DemoFile) )
  {
    v2 = g_pCVar->FactoryInternalIterator(this: g_pCVar);
    v2->SetFirst(this: v2);
    while ( v2->IsValid(this: v2) )
    {
      v3 = v2->Get(this: v2);
      if ( !v3->IsCommand(this: v3) && v3->IsFlagSet(this: v3, a2: 0x10000) )
      {
        if ( (v3->m_nFlags & 0x1000) != 0 )
        {
          m_pszName = "FCVAR_NEVER_AS_STRING";
        }
        else
        {
          m_pszName = v3[1].m_pNext[1].m_pszName;
          if ( m_pszName == nullptr )
            m_pszName = defaultValue;
        }
        v5 = Host_CleanupConVarStringValue(invalue: m_pszName);
        v6 = (const char *)((int (__thiscall *)(ConCommandBase *, const char *))v3->GetName)(a1: v3, a2: v5);
        V_snprintf(pDest: cvarcmd, maxLen: 260, pFormat: "%s \"%s\"", v6, v8);
        v7 = this->GetRecordingTick(this);
        CDemoFile::WriteConsoleCommand(this: &this->m_DemoFile, cmdstring: cvarcmd, tick: v7, nPlayerSlot: 0);
      }
      v2->Next(this: v2);
    }
    free(pMem: v2);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10072210
// Name: public: virtual void CDemoRecorder::RecordCommand(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDemoRecorder::RecordCommand(CDemoRecorder *this, const char *cmdstring)
{
  int v3; // eax

  if ( this->IsRecording(this)
    && cmdstring != nullptr
    && *cmdstring != 0
    && demo_recordcommands.m_pParent != nullptr
    && demo_recordcommands.m_pParent->m_Value.m_nValue != 0 )
  {
    v3 = this->GetRecordingTick(this);
    CDemoFile::WriteConsoleCommand(this: &this->m_DemoFile, cmdstring, tick: v3, nPlayerSlot: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10072260
// Name: protected: void CDemoRecorder::CloseDemoFile(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDemoRecorder::CloseDemoFile(CDemoRecorder *this)
{
  int v2; // eax
  float v3; // xmm0_4
  int m_nFrameCount; // eax
  int Size; // eax
  unsigned __int8 *m_pData; // eax

  if ( CDemoFile::IsOpen(this: &this->m_DemoFile) )
  {
    if ( !this->m_bIsDemoHeader )
    {
      v2 = this->GetRecordingTick(this);
      CDemoFile::WriteCmdHeader(this: &this->m_DemoFile, cmd: 7, tick: v2, nPlayerSlot: 0);
      this->m_DemoFile.m_DemoHeader.playback_ticks = this->GetRecordingTick(this);
      v3 = (float)this->GetRecordingTick(this) * host_state.interval_per_tick;
      m_nFrameCount = this->m_nFrameCount;
      this->m_DemoFile.m_DemoHeader.playback_time = v3;
      this->m_DemoFile.m_DemoHeader.playback_frames = m_nFrameCount;
      CDemoFile::WriteDemoHeader(this: &this->m_DemoFile);
      ConMsg(
        a1: "Completed demo, recording time %.1f, game frames %i.\n",
        this->m_DemoFile.m_DemoHeader.playback_time,
        this->m_DemoFile.m_DemoHeader.playback_frames);
    }
    if ( demo_debug.m_pParent != nullptr && demo_debug.m_pParent->m_Value.m_nValue != 0 )
    {
      Size = CDemoFile::GetSize(this: &this->m_DemoFile);
      ConMsg(a1: "Closed demo file, %i bytes.\n", Size);
    }
    CDemoFile::Close(this: &this->m_DemoFile);
  }
  m_pData = this->m_MessageData.m_pData;
  *(_WORD *)&this->m_bIsDemoHeader = 0;
  if ( m_pData != nullptr )
  {
    free(pMem: m_pData);
    bf_write::StartWriting(this: &this->m_MessageData, pData: nullptr, nBytes: 0, iStartBit: 0, nBits: -1);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10072360
// Name: public: virtual void CDemoRecorder::RecordMessages(class bf_read __near &,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDemoRecorder::RecordMessages(CDemoRecorder *this, bf_read *data, int bits)
{
  bf_write *p_m_MessageData; // ecx

  p_m_MessageData = &this->m_MessageData;
  if ( p_m_MessageData->m_pData != nullptr && bits > 0 )
    bf_write::WriteBitsFromBuffer(this: p_m_MessageData, pIn: data, nBits: bits);
}

//------------------------------------------------------------------------------
// Address: 0x10072390
// Name: public: virtual void CDemoRecorder::StopRecording(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDemoRecorder::StopRecording(CDemoRecorder *this)
{
  unsigned __int8 *m_pData; // eax
  double v3; // st7
  float m_fValue; // xmm0_4
  float v5; // [esp+4h] [ebp-4h]

  if ( this->IsRecording(this) )
  {
    m_pData = this->m_MessageData.m_pData;
    if ( m_pData != nullptr )
    {
      free(pMem: m_pData);
      bf_write::StartWriting(this: &this->m_MessageData, pData: nullptr, nBytes: 0, iStartBit: 0, nBits: -1);
    }
    CDemoRecorder::CloseDemoFile(this);
    this->m_bRecording = false;
    this->m_nDemoNumber = 0;
    if ( !g_DemoOverlay.m_bTick )
    {
      g_DemoOverlay.m_bTick = true;
      v3 = _Plat_FloatTime();
      if ( g_DemoOverlay.m_fLastTickTime != v3 )
      {
        g_DemoOverlay.m_fLastTickTime = v3;
        m_fValue = cl_showdemooverlay.m_pParent->m_Value.m_fValue;
        if ( m_fValue <= 0.0 || (float)((v5 = v3) - g_DemoOverlay.m_fLastTickOverlay) >= m_fValue )
        {
          g_DemoOverlay.m_fLastTickOverlay = v3;
          DemoOverlay::DrawOverlay(this: &g_DemoOverlay, fSetting: m_fValue);
        }
      }
      g_DemoOverlay.m_bTick = false;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10072470
// Name: public: virtual void CDemoRecorder::StartRecording(char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDemoRecorder::StartRecording(CDemoRecorder *this, const char *name, bool bContinuously)
{
  double v4; // st7
  float m_fValue; // xmm0_4
  CClientState *BaseLocalClient; // eax
  float v7; // [esp+8h] [ebp+8h]

  V_strncpy(pDest: this->m_szDemoBaseName, pSrc: name, maxLen: 260);
  this->m_bRecording = true;
  this->m_nDemoNumber = 1;
  this->m_bResetInterpolation = false;
  if ( !g_DemoOverlay.m_bTick )
  {
    g_DemoOverlay.m_bTick = true;
    v4 = _Plat_FloatTime();
    if ( g_DemoOverlay.m_fLastTickTime != v4 )
    {
      g_DemoOverlay.m_fLastTickTime = v4;
      m_fValue = cl_showdemooverlay.m_pParent->m_Value.m_fValue;
      if ( m_fValue <= 0.0 || (float)((v7 = v4) - g_DemoOverlay.m_fLastTickOverlay) >= m_fValue )
      {
        g_DemoOverlay.m_fLastTickOverlay = v4;
        DemoOverlay::DrawOverlay(this: &g_DemoOverlay, fSetting: m_fValue);
      }
    }
    g_DemoOverlay.m_bTick = false;
  }
  BaseLocalClient = GetBaseLocalClient();
  CBaseClientState::ForceFullUpdate(this: BaseLocalClient, pchReason: "recording demo");
}

//------------------------------------------------------------------------------
// Address: 0x10072540
// Name: public: virtual bool CDemoRecorder::IsRecording(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDemoRecorder::IsRecording(CDemoRecorder *this)
{
  double v2; // st7
  float m_fValue; // xmm0_4
  float v5; // [esp+4h] [ebp-4h]

  if ( !g_DemoOverlay.m_bTick )
  {
    g_DemoOverlay.m_bTick = true;
    v2 = _Plat_FloatTime();
    if ( g_DemoOverlay.m_fLastTickTime != v2 )
    {
      g_DemoOverlay.m_fLastTickTime = v2;
      m_fValue = cl_showdemooverlay.m_pParent->m_Value.m_fValue;
      if ( m_fValue <= 0.0 || (float)((v5 = v2) - g_DemoOverlay.m_fLastTickOverlay) >= m_fValue )
      {
        g_DemoOverlay.m_fLastTickOverlay = v2;
        DemoOverlay::DrawOverlay(this: &g_DemoOverlay, fSetting: m_fValue);
      }
    }
    g_DemoOverlay.m_bTick = false;
  }
  return this->m_bRecording;
}

//------------------------------------------------------------------------------
// Address: 0x100725D0
// Name: public: virtual bool CDemoPlayer::StartPlayback(char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDemoPlayer::StartPlayback(CDemoPlayer *this, const char *filename, bool bAsTimeDemo)
{
  int demonum; // edi
  int v6; // ecx
  CClientState *BaseLocalClient; // eax
  INetChannel *NetChannel; // ebx
  CClientState *v9; // eax

  SCR_BeginLoadingPlaque(levelName: nullptr);
  demonum = GetBaseLocalClient()->demonum;
  GetBaseLocalClient()->demonum = -1;
  Host_Disconnect(bShowMainMenu: false);
  GetBaseLocalClient()->demonum = demonum;
  if ( CDemoFile::Open(this: &this->m_DemoFile, name: filename, bReadOnly: true, bMemoryBuffer: false) == 0 )
    goto LABEL_4;
  if ( CDemoFile::ReadDemoHeader(this: &this->m_DemoFile) == nullptr )
  {
    ConMsg(a1: "Failed to read demo header.\n");
    CDemoFile::Close(this: &this->m_DemoFile);
LABEL_4:
    GetBaseLocalClient()->demonum = -1;
    return 0;
  }
  ConMsg(a1: "Playing demo from %s.\n", filename);
  this->m_bPlayingBack = true;
  GetBaseLocalClient()->m_nSignonState = 2;
  v6 = host_tickcount;
  this->m_nStartTick = host_tickcount;
  this->m_nPreviousTick = v6;
  BaseLocalClient = GetBaseLocalClient();
  NetChannel = NET_CreateNetChannel(
                 socket: 0,
                 adr: nullptr,
                 name: "DEMO",
                 handler: BaseLocalClient,
                 bForceNewChannel: false);
  GetBaseLocalClient()->m_NetChannel = NetChannel;
  if ( GetBaseLocalClient()->m_NetChannel == nullptr )
  {
    ConMsg(a1: "CDemo::Play: failed to create demo net channel\n");
    CDemoFile::Close(this: &this->m_DemoFile);
    GetBaseLocalClient()->demonum = -1;
    Host_Disconnect(bShowMainMenu: true);
  }
  v9 = GetBaseLocalClient();
  ((void (__thiscall *)(INetChannel *, _DWORD, _DWORD))v9->m_NetChannel->SetTimeout)(
    a1: v9->m_NetChannel,
    a2: -1.0,
    a3: 0);
  _V_memset(dest: &this->m_DemoPacket, fill: 0, count: 80);
  this->m_DemoPacket.data = (unsigned __int8 *)MemAlloc_Alloc(nSize: 0x17700u);
  netadr_s::SetType(this: &this->m_DemoPacket.from, newtype: NA_LOOPBACK);
  GetBaseLocalClient()->chokedcommands = 0;
  GetBaseLocalClient()->lastoutgoingcommand = -1;
  GetBaseLocalClient()->m_flNextCmdTime = net_time;
  this->m_bTimeDemo = bAsTimeDemo;
  this->m_nTimeDemoCurrentFrame = -1;
  this->m_nTimeDemoStartFrame = -1;
  if ( bAsTimeDemo )
    SeedRandomNumberGenerator(random_invariant: true);
  demoaction->StartPlaying(this: demoaction, a2: filename);
  this->m_flAutoResumeTime = 0.0;
  this->m_flPlaybackRateModifier = 1.0;
  scr_demo_override_fov = 0.0;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100727D0
// Name: public: bool CDemoPlayer::CheckPausedPlayback(void)
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
bool __thiscall CDemoPlayer::CheckPausedPlayback(CDemoPlayer *this)
{
  int m_nServerTick; // eax
  int v3; // ecx
  CClientState *BaseLocalClient; // eax
  int m_nSkipToTick; // edi

  if ( demo_pauseatservertick.m_pParent != nullptr && demo_pauseatservertick.m_pParent->m_Value.m_nValue > 0 )
  {
    m_nServerTick = GetBaseLocalClient()->m_ClockDriftMgr.m_nServerTick;
    v3 = demo_pauseatservertick.m_pParent != nullptr ? demo_pauseatservertick.m_pParent->m_Value.m_nValue : 0;
    if ( m_nServerTick >= v3 )
    {
      ((void (__thiscall *)(CDemoPlayer *, _DWORD))this->PausePlayback)(a1: this, a2: -1.0);
      this->m_nSkipToTick = -1;
      CLoaderMemAlloc::CrtIsValidPointer(this: (ConVar *)&demo_pauseatservertick.IConVar, value: 0);
      BaseLocalClient = GetBaseLocalClient();
      _Msg(a1: "Demo paused at server tick %i\n", BaseLocalClient->m_ClockDriftMgr.m_nServerTick);
    }
  }
  if ( this->IsSkipping(this) )
  {
    m_nSkipToTick = this->m_nSkipToTick;
    if ( m_nSkipToTick > this->GetPlaybackTick(this) || (m_nSkipToTick & 0x88000000) == 0x88000000 )
      return false;
    this->m_nSkipToTick = -1;
  }
  if ( !this->IsPlaybackPaused(this) )
    return false;
  if ( this->m_bPlaybackPaused && this->m_flAutoResumeTime > 0.0 && _Plat_FloatTime() >= this->m_flAutoResumeTime )
    this->ResumePlayback(this);
  return this->m_bPlaybackPaused;
}

//------------------------------------------------------------------------------
// Address: 0x100728D0
// Name: void CL_ListDemo_f(class CCommand const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CL_ListDemo_f(const CCommand *args)
{
  const char *v1; // eax
  CDemoFile v2; // [esp+0h] [ebp-63Ch] BYREF
  char v3[12]; // [esp+538h] [ebp-104h] BYREF

  if ( cmd_source == src_command )
  {
    if ( args->m_nArgc > 1 )
      v1 = args->m_ppArgv[1];
    else
      v1 = defaultValue;
    V_snprintf(pDest: v3, maxLen: 260, pFormat: "%s", v1);
    V_DefaultExtension(path: v3, extension: ".dem", pathStringLength: 260);
    ConMsg(a1: "Demo contents for %s:\n", v3);
    CDemoFile::CDemoFile(this: &v2);
    if ( CDemoFile::Open(this: &v2, name: v3, bReadOnly: true, bMemoryBuffer: false) != 0 )
    {
      CDemoFile::ReadDemoHeader(this: &v2);
      if ( _V_strcmp(s1: v2.m_DemoHeader.demofilestamp, s2: "HL2DEMO") != 0 )
      {
        ConMsg(a1: "%s is not a valid demo file\n", v3);
      }
      else
      {
        ConMsg(a1: "Network protocol: %i\n", v2.m_DemoHeader.networkprotocol);
        ConMsg(a1: "Demo version    : %i\n", v2.m_DemoHeader.demoprotocol);
        ConMsg(a1: "Server name     : %s\n", v2.m_DemoHeader.servername);
        ConMsg(a1: "Map name        : %s\n", v2.m_DemoHeader.mapname);
        ConMsg(a1: "Game            : %s\n", v2.m_DemoHeader.gamedirectory);
        ConMsg(a1: "Player name     : %s\n", v2.m_DemoHeader.clientname);
        ConMsg(a1: "Time            : %.1f\n", v2.m_DemoHeader.playback_time);
        ConMsg(a1: "Ticks           : %i\n", v2.m_DemoHeader.playback_ticks);
        ConMsg(a1: "Frames          : %i\n", v2.m_DemoHeader.playback_frames);
        ConMsg(a1: "Signon size     : %i\n", v2.m_DemoHeader.signonlength);
      }
      CDemoFile::~CDemoFile(this: &v2);
    }
    else
    {
      ConMsg(a1: "ERROR: couldn't open.\n");
      CDemoFile::~CDemoFile(this: &v2);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10072A70
// Name: record
// Source: json
//------------------------------------------------------------------------------
void __cdecl record(const CCommand *args)
{
  const CCommand *v1; // esi
  int m_nArgc; // eax

  v1 = args;
  m_nArgc = args->m_nArgc;
  if ( args->m_nArgc == 2 || m_nArgc == 3 )
  {
    LOBYTE(args) = 0;
    if ( m_nArgc == 3 )
      LOBYTE(args) = _V_stricmp(s1: v1->m_ppArgv[2], s2: "incremental") == 0;
    if ( v1->m_nArgc > 1 )
      DemoRecord(pchDemoFileName: v1->m_ppArgv[1], incremental: (BOOL)args);
    else
      DemoRecord(pchDemoFileName: defaultValue, incremental: (BOOL)args);
  }
  else
  {
    ConMsg(a1: "record <demoname> [incremental]\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x10072AF0
// Name: _record
// Source: json
//------------------------------------------------------------------------------
void __cdecl record(const CCommand *args)
{
  if ( g_ClientDLL != nullptr )
  {
    if ( args->m_nArgc == 2 )
      DemoRecord(pchDemoFileName: args->m_ppArgv[1], incremental: true);
    else
      ConMsg(a1: "_record <demoname>\n");
  }
  else
  {
    ConMsg(a1: "Can't record on dedicated server.\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x10072B40
// Name: void CL_PlayDemo_f(class CCommand const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CL_PlayDemo_f(const CCommand *args)
{
  const char *v1; // eax
  char basename[260]; // [esp+0h] [ebp-208h] BYREF
  char name[260]; // [esp+104h] [ebp-104h] BYREF

  if ( cmd_source == src_command )
  {
    if ( args->m_nArgc == 2 )
    {
      demoplayer = g_pClientDemoPlayer;
      if ( args->m_nArgc > 1 )
        v1 = args->m_ppArgv[1];
      else
        v1 = defaultValue;
      V_strncpy(pDest: name, pSrc: v1, maxLen: 260);
      V_DefaultExtension(path: name, extension: ".dem", pathStringLength: 260);
      if ( demoplayer->StartPlayback(this: demoplayer, a2: name, a3: false) )
      {
        V_StripExtension(in: name, out: basename, outSize: 260);
        g_ClientDLL->OnDemoPlaybackStart(this: g_ClientDLL, a2: basename);
      }
      else
      {
        SCR_EndLoadingPlaque();
      }
    }
    else
    {
      ConMsg(a1: "playdemo <demoname> : plays a demo file\n");
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10072C20
// Name: void CL_TimeDemo_f(class CCommand const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CL_TimeDemo_f(const CCommand *args)
{
  int m_nArgc; // eax
  const char *v2; // ecx
  bool v3; // cc
  const char *v4; // eax

  if ( cmd_source == src_command )
  {
    m_nArgc = args->m_nArgc;
    if ( args->m_nArgc < 2 || m_nArgc > 3 )
    {
      ConMsg(a1: "timedemo <demoname> <optional stats.txt> : gets demo speeds, writing perf resutls to the optional stats.txt\n");
    }
    else
    {
      if ( m_nArgc < 3 )
        v2 = nullptr;
      else
        v2 = args->m_ppArgv[2];
      v3 = m_nArgc <= 1;
      v4 = defaultValue;
      if ( !v3 )
        v4 = args->m_ppArgv[1];
      CL_TimeDemo_Helper(pDemoName: v4, pStatsFileName: v2, pVProfStatsFileName: nullptr);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10072C80
// Name: void CL_TimeDemo_VProfRecord_f(class CCommand const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CL_TimeDemo_VProfRecord_f(const CCommand *args)
{
  if ( cmd_source == src_command )
  {
    if ( args->m_nArgc == 3 )
      CL_TimeDemo_Helper(pDemoName: args->m_ppArgv[1], pStatsFileName: nullptr, pVProfStatsFileName: args->m_ppArgv[2]);
    else
      ConMsg(
        a1: "timedemo_vprofrecord <demoname> <vprof stats filename> : gets demo speeds, recording perf data to a vprof stats file\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x10072CC0
// Name: void CL_TimeDemoQuit_f(class CCommand const __near &)
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __cdecl CL_TimeDemoQuit_f(const CCommand *args)
{
  unsigned int v1; // [esp-8h] [ebp-8h]
  int v2; // [esp-4h] [ebp-4h]

  CLoaderMemAlloc::CrtIsValidPointer(this: (ConVar *)&demo_quitafterplayback.IConVar, value: 1, a2: v1, a3: v2);
  CL_TimeDemo_f(args);
}

//------------------------------------------------------------------------------
// Address: 0x10072CE0
// Name: void CL_BenchFrame_f(class CCommand const __near &)
// Source: json
//------------------------------------------------------------------------------
void __usercall CL_BenchFrame_f(unsigned int a1@<esi>, const CCommand *args)
{
  int v2; // eax
  const char *v3; // eax
  const char *v4; // ecx
  CDemoPlayer *v5; // edx
  const char *v6; // eax
  bool (__thiscall *StartPlayback)(IDemoPlayer *, const char *, bool); // eax
  char name[260]; // [esp+0h] [ebp-104h] BYREF

  if ( cmd_source == src_command )
  {
    if ( args->m_nArgc == 4 )
    {
      if ( atoi(nptr: args->m_ppArgv[2]) >= 0 )
      {
        v3 = defaultValue;
        if ( args->m_nArgc > 2 )
          v3 = args->m_ppArgv[2];
        v2 = atoi(nptr: v3);
      }
      else
      {
        v2 = 0;
      }
      v4 = defaultValue;
      if ( args->m_nArgc > 3 )
        v4 = args->m_ppArgv[3];
      v5 = g_pClientDemoPlayer;
      g_pClientDemoPlayer->m_nSnapshotTick = v2;
      if ( v4 != nullptr )
        V_strncpy(pDest: v5->m_SnapshotFilename, pSrc: v4, maxLen: 260);
      s_bBenchframe = true;
      CLoaderMemAlloc::CrtIsValidPointer(this: (ConVar *)&mat_norendering.IConVar, value: 1, a2: a1, a3: *(int *)name);
      demoplayer = g_pClientDemoPlayer;
      v6 = defaultValue;
      if ( args->m_nArgc > 1 )
        v6 = args->m_ppArgv[1];
      V_strncpy(pDest: name, pSrc: v6, maxLen: 260);
      V_DefaultExtension(path: name, extension: ".dem", pathStringLength: 260);
      StartPlayback = demoplayer->StartPlayback;
      *(_DWORD *)name = 1;
      if ( ((unsigned __int8 (__thiscall *)(IDemoPlayer *, char *))StartPlayback)(a1: demoplayer, a2: name) == 0 )
        SCR_EndLoadingPlaque();
    }
    else
    {
      ConMsg(a1: "benchframe <demoname> <frame> <tgafilename>: takes a snapshot of a particular frame in a demo\n");
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10072E00
// Name: vtune_0
// Source: json
//------------------------------------------------------------------------------
void __cdecl vtune_0(const CCommand *args)
{
  const char *v1; // esi

  if ( args->m_nArgc == 2 )
  {
    if ( V_strcasecmp(s1: args->m_ppArgv[1], s2: "pause") != 0 )
    {
      if ( args->m_nArgc > 1 )
        v1 = args->m_ppArgv[1];
      else
        v1 = defaultValue;
      if ( V_strcasecmp(s1: v1, s2: "resume") != 0 )
      {
        ConMsg(a1: "Unknown vtune option.\n");
      }
      else if ( (unsigned __int8)_vtune(a1: 1) != 0 )
      {
        ConMsg(a1: "VTune sampling resumed.\n");
      }
      else
      {
        ConMsg(a1: "Failed to find \"VTResume()\" in \"vtuneapi.dll\".\n");
      }
    }
    else if ( (unsigned __int8)_vtune(a1: 0) != 0 )
    {
      ConMsg(a1: "VTune sampling paused.\n");
    }
    else
    {
      ConMsg(a1: "Failed to find \"VTPause()\" in \"vtuneapi.dll\".\n");
    }
  }
  else
  {
    ConMsg(a1: "vtune \"pause\" | \"resume\" : Suspend or resume VTune's sampling.\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x10072ED0
// Name: demo_pause
// Source: json
//------------------------------------------------------------------------------
void __cdecl demo_pause(const CCommand *args)
{
  long double v1; // st7
  float v2; // [esp+0h] [ebp-8h]

  if ( args->m_nArgc == 2 )
    v1 = atof(nptr: args->m_ppArgv[1]);
  else
    v1 = -1.0;
  v2 = v1;
  ((void (__stdcall *)(_DWORD))demoplayer->PausePlayback)(a1: LODWORD(v2));
}

//------------------------------------------------------------------------------
// Address: 0x10072F20
// Name: demo_gototick
// Source: json
//------------------------------------------------------------------------------
void __cdecl demo_gototick(const CCommand *args)
{
  const char *v1; // eax
  int v2; // edi
  const char *v3; // eax
  const char *v4; // esi
  bool bRelative; // [esp+4h] [ebp-8h]
  bool bPause; // [esp+8h] [ebp-4h]

  bRelative = false;
  bPause = false;
  if ( args->m_nArgc >= 2 )
  {
    v1 = defaultValue;
    if ( args->m_nArgc > 1 )
      v1 = args->m_ppArgv[1];
    v2 = atoi(nptr: v1);
    if ( args->m_nArgc >= 3 )
    {
      v3 = defaultValue;
      if ( args->m_nArgc > 2 )
        v3 = args->m_ppArgv[2];
      bRelative = V_atoi(str: v3) != 0;
    }
    if ( args->m_nArgc >= 4 )
    {
      if ( args->m_nArgc > 3 )
        v4 = args->m_ppArgv[3];
      else
        v4 = defaultValue;
      bPause = V_atoi(str: v4) != 0;
    }
    demoplayer->SkipToTick(this: demoplayer, a2: v2, a3: bRelative, a4: bPause);
  }
  else
  {
    _Msg(a1: "Syntax: demo_gototick <tick> [relative] [pause]\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x10072FE0
// Name: demo_timescale
// Source: json
//------------------------------------------------------------------------------
void __cdecl demo_timescale(const CCommand *args)
{
  long double v1; // st7
  float v2; // xmm0_4
  int v3; // [esp+4h] [ebp-4h]
  float v4; // [esp+4h] [ebp-4h]

  v3 = 1065353216;
  if ( args->m_nArgc == 2 )
  {
    v1 = atof(nptr: args->m_ppArgv[1]);
    if ( v1 >= 0.0 )
    {
      v2 = v1;
      v4 = v1;
      if ( v4 > 100.0 )
        v2 = 100.0;
    }
    else
    {
      v2 = 0.0;
    }
    v3 = LODWORD(v2);
  }
  ((void (__stdcall *)(int))demoplayer->SetPlaybackTimeScale)(a1: v3);
}

//------------------------------------------------------------------------------
// Address: 0x10073050
// Name: public: char const __near * CFmtStrN<256>::sprintf(char const __near *,...)
// Source: json
//------------------------------------------------------------------------------
char *CFmtStrN<256>::sprintf(CFmtStrN<256> *this, const char *pszFormat, ...)
{
  CFmtStrN<256> *v2; // esi
  bool v3; // zf
  va_list params; // [esp+18h] [ebp+10h] BYREF

  va_start(params, pszFormat);
  v2 = this;
  this->InitQuietTruncation(this);
  HIBYTE(this) = 0;
  V_vsnprintfRet(pDest: v2->m_szBuf, maxLen: 255, pFormat: pszFormat, params, pbTruncated: (bool *)&this + 3);
  v3 = HIBYTE(this) == 0;
  v2->m_szBuf[255] = 0;
  if ( !v3 && !v2->m_bQuietTruncation && `CFmtStrN<256>::sprintf'::`4'::scAsserted < 5 )
    ++`CFmtStrN<256>::sprintf'::`4'::scAsserted;
  v2->m_nLength = _V_strlen(str: v2->m_szBuf);
  return v2->m_szBuf;
}

//------------------------------------------------------------------------------
// Address: 0x10073160
// Name: public: democmdinfo_t::democmdinfo_t(void)
// Source: json
//------------------------------------------------------------------------------
democmdinfo_t *__thiscall democmdinfo_t::democmdinfo_t(democmdinfo_t *this)
{
  democmdinfo_t *result; // eax
  int v2; // esi
  float *p_z; // edx

  result = this;
  v2 = 1;
  p_z = &this->u[0].viewOrigin.z;
  do
  {
    *(p_z - 3) = 0.0;
    *(p_z - 2) = 0.0;
    *(p_z - 1) = 0.0;
    *p_z = 0.0;
    p_z[1] = 0.0;
    p_z[2] = 0.0;
    p_z[3] = 0.0;
    p_z[4] = 0.0;
    p_z[5] = 0.0;
    p_z[6] = 0.0;
    p_z[7] = 0.0;
    p_z[8] = 0.0;
    p_z[9] = 0.0;
    p_z[10] = 0.0;
    p_z[11] = 0.0;
    p_z[12] = 0.0;
    p_z[13] = 0.0;
    p_z[14] = 0.0;
    p_z[15] = 0.0;
    p_z += 19;
    --v2;
  }
  while ( v2 >= 0 );
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100731E0
// Name: public: DemoCommandQueue::DemoCommandQueue(void)
// Source: json
//------------------------------------------------------------------------------
DemoCommandQueue *__thiscall DemoCommandQueue::DemoCommandQueue(DemoCommandQueue *this)
{
  DemoCommandQueue *result; // eax
  democmdinfo_t *p_info; // esi
  int v3; // edi
  float *p_z; // edx

  result = this;
  p_info = &this->info;
  v3 = 1;
  p_z = &this->info.u[0].viewOrigin.z;
  do
  {
    p_info->u[0].flags = 0;
    *(p_z - 2) = 0.0;
    *(p_z - 1) = 0.0;
    *p_z = 0.0;
    p_z[1] = 0.0;
    p_z[2] = 0.0;
    p_z[3] = 0.0;
    p_z[4] = 0.0;
    p_z[5] = 0.0;
    p_z[6] = 0.0;
    p_z[7] = 0.0;
    p_z[8] = 0.0;
    p_z[9] = 0.0;
    p_z[10] = 0.0;
    p_z[11] = 0.0;
    p_z[12] = 0.0;
    p_z[13] = 0.0;
    p_z[14] = 0.0;
    p_z[15] = 0.0;
    p_info = (democmdinfo_t *)((char *)p_info + 76);
    p_z += 19;
    --v3;
  }
  while ( v3 >= 0 );
  this->tick = 0;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10073280
// Name: protected: void CDemoRecorder::StartupDemoHeader(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDemoRecorder::StartupDemoHeader(CDemoRecorder *this)
{
  void *v2; // eax

  CDemoRecorder::CloseDemoFile(this);
  if ( CDemoFile::Open(this: &this->m_DemoFile, name: "demoheader.tmp", bReadOnly: false, bMemoryBuffer: false) != 0 )
  {
    this->m_bIsDemoHeader = true;
    v2 = MemAlloc_Alloc(nSize: 0x17700u);
    bf_write::StartWriting(this: &this->m_MessageData, pData: v2, nBytes: 96000, iStartBit: 0, nBits: -1);
    CNetworkStringTable::SetTick(this: &this->m_MessageData, pDebugName: "DemoHeaderWriteBuffer");
  }
  else
  {
    _ConDMsg(a1: "ERROR: couldn't open temporary header file.\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x100732F0
// Name: protected: void CDemoRecorder::WriteMessages(class bf_write __near &)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CDemoRecorder::WriteMessages(CDemoRecorder *this@<ecx>, int a2@<ebx>, bf_write *message)
{
  int m_iCurBit; // eax
  int v5; // ebx
  int v6; // eax
  CClientState *BaseLocalClient; // eax
  unsigned int CurPos; // eax
  democmdinfo_t info; // [esp+8h] [ebp-A8h] BYREF
  int nOutSequenceNr; // [esp+A0h] [ebp-10h] BYREF
  int nOutSequenceNrAck; // [esp+A4h] [ebp-Ch]
  int cmd; // [esp+A8h] [ebp-8h]
  int nInSequenceNr; // [esp+ACh] [ebp-4h] BYREF

  if ( CDemoFile::IsOpen(this: &this->m_DemoFile) )
  {
    m_iCurBit = message->m_iCurBit;
    v5 = (m_iCurBit + 7) >> 3;
    if ( v5 > 0 )
    {
      if ( (unsigned int)(m_iCurBit % 8 - 1) <= 1 )
        bf_write::WriteUBitLong(this: message, curData: 0, numbits: 6, bCheckRange: true);
      LOBYTE(cmd) = !this->m_bIsDemoHeader + 1;
      if ( (_BYTE)cmd == 2 )
        ++this->m_nFrameCount;
      v6 = ((int (__thiscall *)(CDemoRecorder *, _DWORD))this->GetRecordingTick)(a1: this, a2: 0);
      CDemoFile::WriteCmdHeader(this: &this->m_DemoFile, cmd, tick: v6, nPlayerSlot: a2);
      democmdinfo_t::democmdinfo_t(this: &info);
      CDemoRecorder::GetClientCmdInfo(this, cmdInfo: &info);
      CDemoFile::WriteCmdInfo(this: &this->m_DemoFile, &info);
      BaseLocalClient = GetBaseLocalClient();
      ((void (__thiscall *)(INetChannel *, int *, int *))BaseLocalClient->m_NetChannel->GetSequenceData)(
        a1: BaseLocalClient->m_NetChannel,
        a2: &nOutSequenceNr,
        a3: &nInSequenceNr);
      CDemoFile::WriteSequenceInfo(this: &this->m_DemoFile, nSeqNrIn: nInSequenceNr, nSeqNrOut: nOutSequenceNrAck);
      CDemoFile::WriteRawData(this: &this->m_DemoFile, buffer: (const char *)message->m_pData, length: v5);
      if ( demo_debug.m_pParent != nullptr && demo_debug.m_pParent->m_Value.m_nValue >= 1 )
      {
        CurPos = CDemoFile::GetCurPos(this: &this->m_DemoFile, bRead: false);
        _Msg(a1: "Writing demo message %i bytes at file pos %i\n", v5, CurPos);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10073410
// Name: public: void CDemoPlayer::InterpolateDemoCommand(int,int,struct DemoCommandQueue __near &,struct DemoCommandQueue __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDemoPlayer::InterpolateDemoCommand(
        CDemoPlayer *this,
        int nSlot,
        int targettick,
        DemoCommandQueue *prev,
        DemoCommandQueue *next)
{
  int m_Size; // edi
  int v7; // edx
  DemoCommandQueue *m_pMemory; // ebx
  DemoCommandQueue *v9; // edi
  DemoCommandQueue *v10; // esi
  DemoCommandQueue *v11; // eax
  int c; // [esp+8h] [ebp-10h]
  int savedI; // [esp+10h] [ebp-8h]
  int i; // [esp+14h] [ebp-4h]

  m_Size = this->m_DestCmdInfo.m_Size;
  c = m_Size;
  democmdinfo_t::Reset(this: &prev->info);
  democmdinfo_t::Reset(this: &next->info);
  if ( m_Size >= 2 )
  {
    v7 = targettick;
    m_pMemory = this->m_DestCmdInfo.m_Memory.m_pMemory;
    i = 0;
    savedI = -1;
    v9 = m_pMemory;
    v10 = m_pMemory + 1;
    v11 = m_pMemory;
    while ( v9->tick > v7 || v10->tick <= v7 )
    {
      if ( savedI == -1 )
      {
        v7 = targettick;
        if ( v10->tick > this->m_nPreviousTick && v10->tick <= targettick && (v10->info.u[nSlot].flags & 4) != 0 )
          savedI = i;
      }
      if ( i + 2 == c )
        return;
      ++i;
      ++v11;
      ++v10;
      v9 = v11;
    }
    if ( savedI == -1 )
    {
      prev->tick = v9->tick;
      democmdinfo_t::operator=(this: &prev->info, __that: &v9->info);
      prev->filepos = v9->filepos;
    }
    else
    {
      prev->tick = m_pMemory[savedI].tick;
      democmdinfo_t::operator=(this: &prev->info, __that: &m_pMemory[savedI].info);
      prev->filepos = m_pMemory[savedI].filepos;
      v10 = &this->m_DestCmdInfo.m_Memory.m_pMemory[savedI + 1];
    }
    next->tick = v10->tick;
    democmdinfo_t::operator=(this: &next->info, __that: &v10->info);
    next->filepos = v10->filepos;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10073550
// Name: public: virtual void CDemoPlayer::InterpolateViewpoint(void)
// Source: json
//------------------------------------------------------------------------------
// bad sp value at call has been detected, the output may be wrong!
void __usercall CDemoPlayer::InterpolateViewpoint(CDemoPlayer *this@<ecx>, float a2@<ebp>, int a3@<edi>, int a4@<esi>)
{
  bool v5; // zf
  CClientState *BaseLocalClient; // eax
  int v7; // eax
  float v8; // xmm3_4
  float v9; // xmm0_4
  float *p_info; // eax
  float v11; // edx
  democmdinfo_t *v12; // eax
  float x; // edx
  Vector *p_viewOrigin2; // eax
  float v15; // xmm1_4
  float y; // xmm2_4
  float v17; // xmm0_4
  __int128 v18; // xmm4
  float *p_z; // eax
  float v20; // edx
  float *v21; // eax
  float v22; // ecx
  float v23; // edx
  float v24; // eax
  int i; // edi
  double v26; // st7
  long double v27; // st7
  long double v28; // st7
  const QAngle *v29; // eax
  const QAngle *v30; // eax
  const QAngle *v31; // eax
  const QAngle *v32; // eax
  Vector *p_viewOrigin; // eax
  int v34; // ecx
  float z; // xmm0_4
  QAngle *p_viewAngles2; // eax
  float v37; // xmm0_4
  QAngle *p_localViewAngles2; // eax
  bool v39; // al
  int v41; // [esp-Ch] [ebp-244h] BYREF
  char v42; // [esp-8h] [ebp-240h] BYREF
  int v43; // [esp-4h] [ebp-23Ch] BYREF
  int v44; // [esp+8h] [ebp-230h] BYREF
  _BYTE v45[8]; // [esp+14h] [ebp-224h] BYREF
  DemoCommandQueue next; // [esp+1Ch] [ebp-21Ch] BYREF
  DemoCommandQueue prev; // [esp+BCh] [ebp-17Ch] BYREF
  democmdinfo_t outinfo; // [esp+15Ch] [ebp-DCh] BYREF
  int v49; // [esp+1F4h] [ebp-44h] BYREF
  QAngle destang; // [esp+1F8h] [ebp-40h]
  int flags; // [esp+204h] [ebp-34h]
  QAngle startang; // [esp+208h] [ebp-30h]
  float v53; // [esp+214h] [ebp-24h]
  float v54; // [esp+218h] [ebp-20h]
  float v55; // [esp+21Ch] [ebp-1Ch]
  Vector startorigin; // [esp+220h] [ebp-18h]
  Vector destorigin; // [esp+22Ch] [ebp-Ch]
  float vel; // [esp+238h] [ebp+0h]

  destorigin.x = a2;
  destorigin.y = vel;
  if ( ((unsigned __int8 (__thiscall *)(CDemoPlayer *, int, int))this->IsPlayingBack)(a1: this, a2: a3, a3: a4) != 0 )
  {
    democmdinfo_t::democmdinfo_t(this: (democmdinfo_t *)&prev.info.u[1].viewOrigin2);
    democmdinfo_t::Reset(this: (democmdinfo_t *)&prev.info.u[1].viewOrigin2);
    if ( vec3_origin.x != this->m_LastCmdInfo.u[0].viewOrigin.x
      || vec3_origin.y != this->m_LastCmdInfo.u[0].viewOrigin.y
      || vec3_origin.z != this->m_LastCmdInfo.u[0].viewOrigin.z
      || vec3_angle.x != this->m_LastCmdInfo.u[0].viewAngles.x
      || vec3_angle.y != this->m_LastCmdInfo.u[0].viewAngles.y
      || vec3_angle.z != this->m_LastCmdInfo.u[0].viewAngles.z
      || vec3_angle.x != this->m_LastCmdInfo.u[0].localViewAngles.x
      || vec3_angle.y != this->m_LastCmdInfo.u[0].localViewAngles.y
      || vec3_angle.z != this->m_LastCmdInfo.u[0].localViewAngles.z
      || (v5 = this->m_LastCmdInfo.u[0].flags == 0, HIBYTE(startorigin.z) = 0, !v5) )
    {
      HIBYTE(startorigin.z) = 1;
    }
    LODWORD(startorigin.y) = this->GetPlaybackTick(this);
    if ( GetBaseLocalClient()->m_nMaxClients == 1 )
    {
      if ( demo_legacy_rollback.m_pParent != nullptr && demo_legacy_rollback.m_pParent->m_Value.m_nValue != 0 )
      {
        BaseLocalClient = GetBaseLocalClient();
        v7 = (int)(CClientState::GetClientInterpAmount(this: BaseLocalClient) / host_state.interval_per_tick + 0.5);
        LODWORD(startorigin.y) += -1 - v7;
      }
      else
      {
        --LODWORD(startorigin.y);
      }
    }
    v5 = !this->m_bInterpolateView;
    startang.z = 0.0;
    v54 = 0.0;
    if ( !v5 && demo_interpolateview.m_pParent != nullptr && demo_interpolateview.m_pParent->m_Value.m_nValue != 0 )
    {
      if ( HIBYTE(startorigin.z) != 0 )
      {
        DemoCommandQueue::DemoCommandQueue(this: (DemoCommandQueue *)&next.info.u[1].viewOrigin2);
        DemoCommandQueue::DemoCommandQueue(this: (DemoCommandQueue *)&v41);
        democmdinfo_t::operator=(this: (democmdinfo_t *)&next.info.u[1].viewOrigin2.y, __that: &this->m_LastCmdInfo);
        next.info.u[1].viewOrigin2.x = NAN;
        democmdinfo_t::operator=(this: (democmdinfo_t *)&v42, __that: &this->m_LastCmdInfo);
        v41 = -1;
        CDemoPlayer::InterpolateDemoCommand(
          this,
          nSlot: 0,
          targettick: SLODWORD(startorigin.y),
          prev: (DemoCommandQueue *)&next.info.u[1].viewOrigin2,
          next: (DemoCommandQueue *)&v41);
        startorigin.x = (float)(v41 - LODWORD(next.info.u[1].viewOrigin2.x)) * host_state.interval_per_tick;
        v53 = 1.0 / startorigin.x;
        v8 = 0.0;
        v9 = (float)((float)((float)(LODWORD(startorigin.y) - LODWORD(next.info.u[1].viewOrigin2.x))
                           * host_state.interval_per_tick)
                   + GetBaseLocalClient()->m_tickRemainder)
           * v53;
        if ( v9 >= 0.0 )
        {
          v8 = 1.0;
          if ( v9 <= 1.0 )
            v8 = v9;
        }
        v55 = v8;
        p_info = (float *)&prev.info;
        if ( (LOBYTE(next.info.u[1].viewOrigin2.y) & 1) == 0 )
          p_info = &next.info.u[1].viewOrigin2.z;
        v11 = *p_info;
        destang.y = p_info[1];
        destang.x = v11;
        destang.z = p_info[2];
        v12 = &next.info;
        if ( (v42 & 1) == 0 )
          v12 = (democmdinfo_t *)&v43;
        v5 = (this->m_LastCmdInfo.u[0].flags & 1) == 0;
        flags = v12->u[0].flags;
        x = v12->u[0].viewOrigin.x;
        startang.y = v12->u[0].viewOrigin.y;
        startang.x = x;
        p_viewOrigin2 = &this->m_LastCmdInfo.u[0].viewOrigin2;
        if ( v5 )
          p_viewOrigin2 = &this->m_LastCmdInfo.u[0].viewOrigin;
        v15 = startang.x;
        y = startang.y;
        v17 = *(float *)&flags;
        v18 = 0;
        *(float *)&v18 = fsqrt(
                           (float)((float)((float)(startang.x - p_viewOrigin2->y)
                                         * (float)(startang.x - p_viewOrigin2->y))
                                 + (float)((float)(startang.y - p_viewOrigin2->z)
                                         * (float)(startang.y - p_viewOrigin2->z)))
                         + (float)((float)(*(float *)&flags - p_viewOrigin2->x)
                                 * (float)(*(float *)&flags - p_viewOrigin2->x)));
        *(_OWORD *)&outinfo.u[1].viewAngles2.x = v18;
        if ( startorigin.x > 0.0 )
        {
          startang.z = v53 * outinfo.u[1].viewAngles2.x;
          p_z = &prev.info.u[0].viewAngles.z;
          if ( (LOBYTE(next.info.u[1].viewOrigin2.y) & 2) == 0 )
            p_z = &next.info.u[1].localViewAngles2.z;
          outinfo.u[1].viewAngles2.y = *p_z;
          v20 = p_z[1];
          outinfo.u[1].localViewAngles2.x = p_z[2];
          outinfo.u[1].viewAngles2.z = v20;
          v21 = &next.info.u[0].viewAngles.z;
          if ( (v42 & 2) == 0 )
            v21 = (float *)v45;
          v22 = *v21;
          v23 = v21[1];
          v24 = v21[2];
          outinfo.u[1].viewOrigin2.x = v22;
          outinfo.u[1].viewOrigin2.y = v23;
          outinfo.u[1].viewOrigin2.z = v24;
          for ( i = 0; i < 12; i += 4 )
          {
            startorigin.x = AngleNormalizePositive(angle: *(float *)((char *)&outinfo.u[1].viewOrigin2.x + i));
            v26 = AngleNormalizePositive(angle: *(float *)((char *)&outinfo.u[1].viewAngles2.y + i));
            startorigin.y = startorigin.x - v26;
            v27 = AngleNormalize(angle: startorigin.y);
            v28 = fabs(v27) * v53;
            startorigin.x = v28;
            if ( v28 > v54 )
              v54 = startorigin.x;
          }
          y = startang.y;
          v15 = startang.x;
          v17 = *(float *)&flags;
          v8 = v55;
        }
        if ( startang.z <= demo_interplimit.m_pParent->m_Value.m_fValue
          && v54 <= demo_avellimit.m_pParent->m_Value.m_fValue
          && !this->m_bResetInterpolation )
        {
          prev.info.u[1].viewOrigin2.y = (float)((float)(v17 - destang.x) * v8) + destang.x;
          prev.info.u[1].viewOrigin2.z = (float)((float)(v15 - destang.y) * v8) + destang.y;
          prev.info.u[1].viewAngles2.x = (float)((float)(y - destang.z) * v8) + destang.z;
          v29 = (const QAngle *)&prev.info.u[0].viewOrigin.z;
          if ( (LOBYTE(next.info.u[1].viewOrigin2.y) & 2) == 0 )
            v29 = (const QAngle *)&next.info.u[1].viewAngles2.z;
          AngleQuaternion(angles: v29, outQuat: (Quaternion *)&outinfo.u[1].localViewAngles.z);
          v30 = (const QAngle *)&next.info.u[0].viewOrigin.z;
          if ( (v42 & 2) == 0 )
            v30 = (const QAngle *)&v44;
          AngleQuaternion(angles: v30, outQuat: (Quaternion *)&outinfo.u[1].viewAngles2);
          QuaternionSlerp(
            p: (const Quaternion *)&outinfo.u[1].localViewAngles.z,
            q: (const Quaternion *)&outinfo.u[1].viewAngles2,
            t: v55,
            qt: (Quaternion *)&v49);
          QuaternionAngles(q: (const Quaternion *)&v49, angles: (QAngle *)&prev.info.u[1].viewAngles2.y);
          v31 = (const QAngle *)&prev.info.u[0].viewAngles.z;
          if ( (LOBYTE(next.info.u[1].viewOrigin2.y) & 2) == 0 )
            v31 = (const QAngle *)&next.info.u[1].localViewAngles2.z;
          AngleQuaternion(angles: v31, outQuat: (Quaternion *)&outinfo.u[1].localViewAngles.z);
          v32 = (const QAngle *)&next.info.u[0].viewAngles.z;
          if ( (v42 & 2) == 0 )
            v32 = (const QAngle *)v45;
          AngleQuaternion(angles: v32, outQuat: (Quaternion *)&outinfo.u[1].viewAngles2);
          QuaternionSlerp(
            p: (const Quaternion *)&outinfo.u[1].localViewAngles.z,
            q: (const Quaternion *)&outinfo.u[1].viewAngles2,
            t: v55,
            qt: (Quaternion *)&v49);
          QuaternionAngles(q: (const Quaternion *)&v49, angles: (QAngle *)&prev.info.u[1].localViewAngles2.y);
          goto LABEL_62;
        }
        this->m_bResetInterpolation = false;
LABEL_55:
        p_viewOrigin = &this->m_LastCmdInfo.u[0].viewOrigin2;
        if ( (this->m_LastCmdInfo.u[0].flags & 1) == 0 )
          p_viewOrigin = &this->m_LastCmdInfo.u[0].viewOrigin;
        v34 = this->m_LastCmdInfo.u[0].flags & 2;
        prev.info.u[1].viewOrigin2.y = p_viewOrigin->x;
        prev.info.u[1].viewOrigin2.z = p_viewOrigin->y;
        z = p_viewOrigin->z;
        p_viewAngles2 = &this->m_LastCmdInfo.u[0].viewAngles2;
        prev.info.u[1].viewAngles2.x = z;
        if ( v34 == 0 )
          p_viewAngles2 = &this->m_LastCmdInfo.u[0].viewAngles;
        prev.info.u[1].viewAngles2.y = p_viewAngles2->x;
        prev.info.u[1].viewAngles2.z = p_viewAngles2->y;
        v37 = p_viewAngles2->z;
        p_localViewAngles2 = &this->m_LastCmdInfo.u[0].localViewAngles2;
        prev.info.u[1].localViewAngles2.x = v37;
        if ( v34 == 0 )
          p_localViewAngles2 = &this->m_LastCmdInfo.u[0].localViewAngles;
        prev.info.u[1].localViewAngles2.y = p_localViewAngles2->x;
        prev.info.u[1].localViewAngles2.z = p_localViewAngles2->y;
        prev.filepos = LODWORD(p_localViewAngles2->z);
      }
    }
    else if ( HIBYTE(startorigin.z) != 0 )
    {
      goto LABEL_55;
    }
LABEL_62:
    this->m_nPreviousTick = LODWORD(startorigin.y);
    v39 = CDemoPlayer::OverrideView(this, info: (democmdinfo_t *)&prev.info.u[1].viewOrigin2);
    if ( (HIBYTE(startorigin.z) | v39) != 0 )
    {
      g_pClientSidePrediction->SetViewOrigin(this: g_pClientSidePrediction, a2: (Vector *)&prev.info.u[1].viewOrigin2.y);
      g_pClientSidePrediction->SetViewAngles(this: g_pClientSidePrediction, a2: (QAngle *)&prev.info.u[1].viewAngles2.y);
      g_pClientSidePrediction->SetLocalViewAngles(
        this: g_pClientSidePrediction,
        a2: (QAngle *)&prev.info.u[1].localViewAngles2.y);
      GetLocalClient(nSlot: -1)->viewangles = *(QAngle *)&prev.info.u[1].viewAngles2.y;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10073BF0
// Name: protected: void CDemoRecorder::WriteSplitScreenPlayers(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CDemoRecorder::WriteSplitScreenPlayers(CDemoRecorder *this@<ecx>, int a2@<ebx>)
{
  int v3; // ebx
  int v4; // eax
  int v5; // ecx
  float *p_z; // eax
  CClientState *BaseLocalClient; // eax
  unsigned int CurPos; // eax
  _BYTE pData[96000]; // [esp+8h] [ebp-177C0h] BYREF
  democmdinfo_t cmdInfo; // [esp+17708h] [ebp-C0h] BYREF
  bf_write v12; // [esp+177A0h] [ebp-28h] BYREF
  _BYTE v13[4]; // [esp+177B8h] [ebp-10h] BYREF
  int nSeqNrIn; // [esp+177BCh] [ebp-Ch] BYREF
  unsigned __int8 cmd[4]; // [esp+177C0h] [ebp-8h]
  int nSeqNrOut; // [esp+177C4h] [ebp-4h]

  bf_write::bf_write(this: &v12);
  bf_write::StartWriting(this: &v12, pData, nBytes: 96000, iStartBit: 0, nBits: -1);
  CNetworkStringTable::SetTick(this: &v12, pDebugName: "DemoFileWriteSplitScreenPlayers");
  if ( CDemoFile::IsOpen(this: &this->m_DemoFile) )
  {
    v3 = (v12.m_iCurBit + 7) >> 3;
    if ( v3 > 0 )
    {
      if ( (unsigned int)(v12.m_iCurBit % 8 - 1) <= 1 )
        bf_write::WriteUBitLong(this: &v12, curData: 0, numbits: 6, bCheckRange: true);
      cmd[0] = !this->m_bIsDemoHeader + 1;
      if ( cmd[0] == 2 )
        ++this->m_nFrameCount;
      v4 = ((int (__thiscall *)(CDemoRecorder *, _DWORD))this->GetRecordingTick)(a1: this, a2: 0);
      CDemoFile::WriteCmdHeader(this: &this->m_DemoFile, cmd: *(int *)cmd, tick: v4, nPlayerSlot: a2);
      v5 = 1;
      p_z = &cmdInfo.u[0].viewOrigin.z;
      do
      {
        *(p_z - 3) = 0.0;
        *(p_z - 2) = 0.0;
        *(p_z - 1) = 0.0;
        *p_z = 0.0;
        p_z[1] = 0.0;
        p_z[2] = 0.0;
        p_z[3] = 0.0;
        p_z[4] = 0.0;
        p_z[5] = 0.0;
        p_z[6] = 0.0;
        p_z[7] = 0.0;
        p_z[8] = 0.0;
        p_z[9] = 0.0;
        p_z[10] = 0.0;
        p_z[11] = 0.0;
        p_z[12] = 0.0;
        p_z[13] = 0.0;
        p_z[14] = 0.0;
        p_z[15] = 0.0;
        p_z += 19;
        --v5;
      }
      while ( v5 >= 0 );
      CDemoRecorder::GetClientCmdInfo(this, &cmdInfo);
      CDemoFile::WriteCmdInfo(this: &this->m_DemoFile, info: &cmdInfo);
      BaseLocalClient = GetBaseLocalClient();
      ((void (__thiscall *)(INetChannel *, _BYTE *, int *))BaseLocalClient->m_NetChannel->GetSequenceData)(
        a1: BaseLocalClient->m_NetChannel,
        a2: v13,
        a3: &nSeqNrIn);
      CDemoFile::WriteSequenceInfo(this: &this->m_DemoFile, nSeqNrIn, nSeqNrOut);
      CDemoFile::WriteRawData(this: &this->m_DemoFile, buffer: (const char *)v12.m_pData, length: v3);
      if ( demo_debug.m_pParent != nullptr && demo_debug.m_pParent->m_Value.m_nValue >= 1 )
      {
        CurPos = CDemoFile::GetCurPos(this: &this->m_DemoFile, bRead: false);
        _Msg(a1: "Writing demo message %i bytes at file pos %i\n", v3, CurPos);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10073DA0
// Name: protected: void CDemoRecorder::WriteBSPDecals(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDemoRecorder::WriteBSPDecals(CDemoRecorder *this)
{
  int v1; // eax
  decallist_t *v2; // esi
  int v3; // edi
  __int16 *p_entityIndex; // esi
  int v5; // eax
  IClientEntity *v6; // eax
  const model_t *v7; // edi
  int v8; // eax
  CClientState *BaseLocalClient; // eax
  const char *v10; // [esp-4h] [ebp-17764h]
  _BYTE pData[96000]; // [esp+Ch] [ebp-17754h] BYREF
  bf_write buffer; // [esp+1770Ch] [ebp-54h] BYREF
  SVC_BSPDecal v13; // [esp+17724h] [ebp-3Ch] BYREF
  decallist_t *v14; // [esp+17750h] [ebp-10h]
  CDemoRecorder *v15; // [esp+17754h] [ebp-Ch]
  int i; // [esp+17758h] [ebp-8h]
  bool found; // [esp+1775Fh] [ebp-1h] BYREF

  v15 = this;
  v1 = Draw_DecalMax();
  v2 = (decallist_t *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 156 * v1);
  v14 = v2;
  v3 = DecalListCreate(pList: v2);
  bf_write::bf_write(this: &buffer);
  bf_write::StartWriting(this: &buffer, pData, nBytes: 96000, iStartBit: 0, nBits: -1);
  CNetworkStringTable::SetTick(this: &buffer, pDebugName: "DemoFileWriteBSPDecals");
  if ( v3 > 0 )
  {
    p_entityIndex = &v2->entityIndex;
    for ( i = v3; i != 0; --i )
    {
      v5 = *p_entityIndex;
      v13.m_bReliable = true;
      v13.m_NetChannel = nullptr;
      v13.__vftable = (SVC_BSPDecal_vtbl *)&SVC_BSPDecal::`vftable';
      found = false;
      v6 = entitylist->GetClientEntity(this: entitylist, a2: v5);
      if ( v6 != nullptr )
      {
        v7 = v6->GetModel(this: &v6->IClientRenderable);
        v8 = *p_entityIndex;
        v13.m_Pos = *(Vector *)(p_entityIndex - 70);
        v13.m_nEntityIndex = v8;
        v13.m_nDecalTextureIndex = Draw_DecalIndexFromName(name: (char *)p_entityIndex - 128, &found);
        v13.m_nModelIndex = 0;
        if ( v7 != nullptr )
        {
          v10 = modelloader->GetName(this: modelloader, a2: v7);
          BaseLocalClient = GetBaseLocalClient();
          v13.m_nModelIndex = CClientState::LookupModelIndex(this: BaseLocalClient, name: v10);
        }
        SVC_BSPDecal::WriteToBuffer(this: &v13, &buffer);
      }
      p_entityIndex += 78;
    }
    v2 = v14;
  }
  CDemoRecorder::WriteMessages(this: v15, a2: 0, message: &buffer);
  _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v2);
}

//------------------------------------------------------------------------------
// Address: 0x10073F00
// Name: public: virtual void CDemoRecorder::RecordStringTables(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDemoRecorder::RecordStringTables(CDemoRecorder *this)
{
  int v2; // eax
  CUtlBuffer bigBuff; // [esp+8h] [ebp-48h] BYREF
  bf_write buf; // [esp+38h] [ebp-18h] BYREF

  if ( CDemoFile::IsOpen(this: &this->m_DemoFile) )
  {
    CUtlBuffer::CUtlBuffer(this: &bigBuff, growSize: 0, initSize: 0, nFlags: 0);
    CUtlBuffer::EnsureCapacity(this: &bigBuff, num: 0x200000);
    bf_write::bf_write(this: &buf, pData: bigBuff.m_Memory.m_pMemory, nBytes: 0x200000, nBits: -1);
    CNetworkStringTableContainer::WriteStringTables(this: networkStringTableContainerClient, &buf);
    if ( buf.m_nDataBits - buf.m_iCurBit <= 0 )
      Sys_Error(error: "unable to record server classes\n");
    v2 = this->GetRecordingTick(this);
    CDemoFile::WriteStringTables(this: &this->m_DemoFile, &buf, tick: v2);
    if ( bigBuff.m_Memory.m_nGrowSize >= 0 && bigBuff.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: bigBuff.m_Memory.m_pMemory);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10073FB0
// Name: protected: void CDemoRecorder::StartupDemoFile(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDemoRecorder::StartupDemoFile(CDemoRecorder *this)
{
  void *v2; // edi
  void *v3; // eax
  const char *v4; // eax
  CClientState *BaseLocalClient; // eax
  Remote_t *v6; // eax
  const char *v7; // eax
  char *m_pszString; // eax
  int m_Size; // edi
  int v10; // esi
  const char *pszValue; // eax
  int v12; // eax
  int v13; // eax
  void *v14; // esp
  const char *v15; // eax
  unsigned int v16; // esi
  char *v17; // eax
  CClientState *v18; // eax
  int v19; // [esp+0h] [ebp-224h] BYREF
  int v20; // [esp+4h] [ebp-220h] BYREF
  char szGameDir[260]; // [esp+Ch] [ebp-218h] BYREF
  char demoFileName[260]; // [esp+110h] [ebp-114h] BYREF
  unsigned __int8 *pWriteBuffer; // [esp+214h] [ebp-10h]
  unsigned int iTotalDataSize; // [esp+218h] [ebp-Ch]
  unsigned __int8 *pWrite; // [esp+21Ch] [ebp-8h]
  int i; // [esp+220h] [ebp-4h]

  if ( this->m_bRecording && !CDemoFile::IsOpen(this: &this->m_DemoFile) )
  {
    if ( demo_enabledemos.m_pParent != nullptr && demo_enabledemos.m_pParent->m_Value.m_nValue != 0 )
    {
      if ( this->m_nDemoNumber > 1 )
        V_snprintf(pDest: demoFileName, maxLen: 260, pFormat: "%s_%i.dem", this->m_szDemoBaseName, this->m_nDemoNumber);
      else
        V_snprintf(pDest: demoFileName, maxLen: 260, pFormat: "%s.dem", this->m_szDemoBaseName);
      if ( CDemoFile::Open(this: &this->m_DemoFile, name: demoFileName, bReadOnly: false, bMemoryBuffer: false) != 0 )
      {
        v2 = g_pFileSystem->OpenEx(this: g_pFileSystem, a2: "demoheader.tmp", a3: "rb", a4: 0, a5: 0, a6: 0);
        if ( v2 != nullptr )
        {
          v3 = MemAlloc_Alloc(nSize: 0x17700u);
          bf_write::StartWriting(this: &this->m_MessageData, pData: v3, nBytes: 96000, iStartBit: 0, nBits: -1);
          CNetworkStringTable::SetTick(this: &this->m_MessageData, pDebugName: "DemoFileWriteBuffer");
          _V_memset(dest: &this->m_DemoFile.m_DemoHeader, fill: 0, count: 1072);
          this->m_DemoFile.m_DemoHeader.demoprotocol = 4;
          this->m_DemoFile.m_DemoHeader.networkprotocol = GetHostVersion();
          V_strncpy(pDest: this->m_DemoFile.m_DemoHeader.demofilestamp, pSrc: "HL2DEMO", maxLen: 8);
          v4 = modelloader->GetName(this: modelloader, a2: host_state.worldmodel);
          V_FileBase(in: v4, out: this->m_DemoFile.m_DemoHeader.mapname, maxlen: 260);
          V_strncpy(pDest: szGameDir, pSrc: com_gamedir, maxLen: 260);
          V_FileBase(in: szGameDir, out: this->m_DemoFile.m_DemoHeader.gamedirectory, maxlen: 260);
          BaseLocalClient = GetBaseLocalClient();
          v6 = CAddressList::Get(this: &BaseLocalClient->m_Remote, index: 0);
          v7 = CUtlString::operator char const *(this: &v6->m_szRetryAddress);
          V_strncpy(pDest: this->m_DemoFile.m_DemoHeader.servername, pSrc: v7, maxLen: 260);
          if ( (cl_name.m_nFlags & 0x1000) != 0 )
          {
            m_pszString = "FCVAR_NEVER_AS_STRING";
          }
          else
          {
            m_pszString = cl_name.m_pParent->m_Value.m_pszString;
            if ( m_pszString == nullptr )
              m_pszString = (char *)defaultValue;
          }
          V_strncpy(pDest: this->m_DemoFile.m_DemoHeader.clientname, pSrc: m_pszString, maxLen: 260);
          g_pFileSystem->Seek(this: &g_pFileSystem->IBaseFileSystem, a2: v2, a3: 0, a4: FILESYSTEM_SEEK_TAIL);
          this->m_DemoFile.m_DemoHeader.signonlength = g_pFileSystem->Tell(
                                                         this: &g_pFileSystem->IBaseFileSystem,
                                                         a2: v2);
          g_pFileSystem->Seek(this: &g_pFileSystem->IBaseFileSystem, a2: v2, a3: 0, a4: FILESYSTEM_SEEK_HEAD);
          CDemoFile::WriteDemoHeader(this: &this->m_DemoFile);
          CDemoFile::WriteFileBytes(this: &this->m_DemoFile, fh: v2, length: this->m_DemoFile.m_DemoHeader.signonlength);
          g_pFileSystem->Close(this: &g_pFileSystem->IBaseFileSystem, a2: v2);
          this->m_nFrameCount = 0;
          this->m_bIsDemoHeader = false;
          CDemoRecorder::ResyncDemoClock(this);
          CDemoFile::WriteCmdHeader(this: &this->m_DemoFile, cmd: 3, tick: 0, nPlayerSlot: 0);
          m_Size = g_RegisteredDemoCustomDataCallbacks.m_Size;
          v10 = 0;
          if ( g_RegisteredDemoCustomDataCallbacks.m_Size != 0 )
          {
            i = 0;
            do
            {
              pszValue = g_RegisteredDemoCustomDataCallbacks.m_Memory.m_pMemory[v10].szSaveID.pszValue;
              if ( pszValue == nullptr )
                pszValue = defaultValue;
              v12 = _V_strlen(str: pszValue);
              ++v10;
              v13 = i + v12 + 1;
              i = v13;
            }
            while ( v10 != m_Size );
            iTotalDataSize = v13 + 4;
            v14 = alloca(v13 + 4);
            pWriteBuffer = (unsigned __int8 *)&v19;
            v19 = m_Size;
            pWrite = (unsigned __int8 *)&v20;
            i = 0;
            do
            {
              v15 = g_RegisteredDemoCustomDataCallbacks.m_Memory.m_pMemory[i].szSaveID.pszValue;
              if ( v15 == nullptr )
                v15 = defaultValue;
              v16 = _V_strlen(str: v15) + 1;
              v17 = (char *)g_RegisteredDemoCustomDataCallbacks.m_Memory.m_pMemory[i].szSaveID.pszValue;
              if ( v17 == nullptr )
                v17 = (char *)defaultValue;
              memcpy(dst: pWrite, src: (unsigned __int8 *)v17, count: v16);
              pWrite += v16;
              ++i;
            }
            while ( i != m_Size );
            CDemoFile::WriteCustomData(
              this: &this->m_DemoFile,
              iCallbackIndex: -1,
              pData: pWriteBuffer,
              iDataSize: iTotalDataSize,
              tick: 0);
          }
          ((void (__thiscall *)(CDemoRecorder *, int))this->RecordStringTables)(a1: this, a2: v19);
          CDemoRecorder::WriteDemoCvars(this);
          CDemoRecorder::WriteBSPDecals(this);
          g_ClientDLL->HudReset(this: g_ClientDLL);
          if ( splitscreen->GetNumSplitScreenPlayers(this: splitscreen) > 1 )
            CDemoRecorder::WriteSplitScreenPlayers(this, a2: (int)this);
          v18 = GetBaseLocalClient();
          CBaseClientState::SendStringCmd(this: v18, command: "demorestart");
          ConMsg(a1: "Recording to %s...\n", demoFileName);
        }
        else
        {
          ConMsg(a1: "StartupDemoFile: couldn't open demo file header.\n");
        }
      }
    }
    else
    {
      _Warning(a1: "DEMO: cannot start recording a demo (set 'demo_enabledemos' to 1 and restart the map to enable demos)\n");
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100743A0
// Name: public: virtual void CDemoRecorder::RecordPacket(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDemoRecorder::RecordPacket(CDemoRecorder *this)
{
  bf_write *p_m_MessageData; // edi

  p_m_MessageData = &this->m_MessageData;
  CDemoRecorder::WriteMessages(this, message: &this->m_MessageData);
  bf_write::Reset(this: p_m_MessageData);
  if ( this->m_bCloseDemoFile )
    CDemoRecorder::CloseDemoFile(this);
}

//------------------------------------------------------------------------------
// Address: 0x100743D0
// Name: public: virtual void CDemoRecorder::SetSignonState(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDemoRecorder::SetSignonState(CDemoRecorder *this, int state)
{
  if ( !demoplayer->IsPlayingBack(this: demoplayer)
    && demo_enabledemos.m_pParent != nullptr
    && demo_enabledemos.m_pParent->m_Value.m_nValue != 0 )
  {
    if ( state == 3 )
    {
      if ( CDemoFile::IsOpen(this: &this->m_DemoFile) )
      {
        CDemoRecorder::CloseDemoFile(this);
        ++this->m_nDemoNumber;
      }
      CDemoRecorder::StartupDemoHeader(this);
    }
    else if ( state == 5 )
    {
      this->m_bCloseDemoFile = true;
    }
    else if ( state == 6 && this->m_bRecording )
    {
      CDemoRecorder::StartupDemoFile(this);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10074450
// Name: public: virtual void CDemoRecorder::RecordServerClasses(class ServerClass __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDemoRecorder::RecordServerClasses(CDemoRecorder *this, ServerClass *pClasses)
{
  int v3; // eax
  CUtlBuffer bigBuff; // [esp+8h] [ebp-48h] BYREF
  bf_write buf; // [esp+38h] [ebp-18h] BYREF

  if ( CDemoFile::IsOpen(this: &this->m_DemoFile) )
  {
    CUtlBuffer::CUtlBuffer(this: &bigBuff, growSize: 0, initSize: 0, nFlags: 0);
    CUtlBuffer::EnsureCapacity(this: &bigBuff, num: 0x200000);
    bf_write::bf_write(
      this: &buf,
      pDebugName: "CDemoRecorder::RecordServerClasses",
      pData: bigBuff.m_Memory.m_pMemory,
      nBytes: 0x200000,
      nBits: -1);
    DataTable_WriteSendTablesBuffer(pClasses, pBuf: &buf);
    DataTable_WriteClassInfosBuffer(pClasses, pBuf: &buf);
    if ( buf.m_nDataBits - buf.m_iCurBit <= 0 )
      Sys_Error(error: "unable to record server classes\n");
    v3 = this->GetRecordingTick(this);
    CDemoFile::WriteNetworkDataTables(this: &this->m_DemoFile, &buf, tick: v3);
    if ( bigBuff.m_Memory.m_nGrowSize >= 0 && bigBuff.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: bigBuff.m_Memory.m_pMemory);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10074510
// Name: void ComputeTimedemoResultsFilename(class CFmtStrN<256> __near &,class CFmtStrN<256> __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ComputeTimedemoResultsFilename(CFmtStrN<256> *fileName, CFmtStrN<256> *dateString)
{
  IMaterialSystem_vtbl *v2; // esi
  int v3; // eax
  int v4; // edi
  char *v5; // eax
  char *v6; // esi
  int v7; // eax
  char *v8; // eax
  const CUtlString *v9; // eax
  int v10; // eax
  char *v11; // eax
  const char *v12; // eax
  const char *v13; // [esp-8h] [ebp-38Ch]
  const char *v14; // [esp-4h] [ebp-388h]
  MaterialAdapterInfo_t info; // [esp+Ch] [ebp-378h] BYREF
  char host[256]; // [esp+230h] [ebp-154h] BYREF
  tm time; // [esp+330h] [ebp-54h] BYREF
  CUtlString benchmarkPath; // [esp+354h] [ebp-30h] BYREF
  CUtlString gpuName; // [esp+364h] [ebp-20h] BYREF
  CUtlString rhs; // [esp+374h] [ebp-10h] BYREF

  _Plat_GetLocalTime(a1: &time);
  CFmtStrN<256>::sprintf(
    this: dateString,
    pszFormat: "%04d_%02d_%02d__%02d_%02d_%02d",
    time.tm_year + 1900,
    time.tm_mon + 1,
    time.tm_mday,
    time.tm_hour,
    time.tm_min,
    time.tm_sec);
  v2 = materials->__vftable;
  v3 = ((int (__thiscall *)(IMaterialSystem *, MaterialAdapterInfo_t *))materials->GetCurrentAdapter)(
         a1: materials,
         a2: &info);
  ((void (__thiscall *)(IMaterialSystem *, int))v2->GetDisplayAdapterInfo)(a1: materials, a2: v3);
  CUtlString::CUtlString(this: &gpuName, pString: info.m_pDriverName);
  rhs.m_Storage.m_Memory.m_nGrowSize = (int)"nvidia";
  rhs.m_Storage.m_nActualLength = (int)"ati";
  v4 = 0;
  while ( 1 )
  {
    v14 = (const char *)*(&rhs.m_Storage.m_Memory.m_nGrowSize + v4);
    v5 = CUtlString::Get(this: &gpuName);
    v6 = V_stristr(pStr: v5, pSearch: v14);
    if ( v6 != nullptr )
      break;
    if ( (unsigned int)++v4 >= 2 )
      goto LABEL_10;
  }
  v7 = _V_strlen(str: *((const char **)&rhs.m_Storage.m_Memory.m_nGrowSize + v4));
  if ( v6[v7] == 32 )
    ++v7;
  CUtlString::CUtlString(this: &rhs, pString: &v6[v7]);
  v8 = CUtlString::Get(this: &gpuName);
  CUtlString::SetLength(this: &gpuName, nLen: v6 - v8);
  CUtlString::operator+=(this: &gpuName, &rhs);
  rhs.m_Storage.m_nActualLength = 0;
  if ( rhs.m_Storage.m_Memory.m_nGrowSize >= 0 && rhs.m_Storage.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: rhs.m_Storage.m_Memory.m_pMemory);
LABEL_10:
  v9 = CUtlString::Replace(this: &gpuName, result: &rhs, cFrom: 32, cTo: 95);
  CUtlString::operator=(this: &gpuName, src: v9);
  rhs.m_Storage.m_nActualLength = 0;
  if ( rhs.m_Storage.m_Memory.m_nGrowSize >= 0 && rhs.m_Storage.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: rhs.m_Storage.m_Memory.m_pMemory);
  memset(host, 0, sizeof(host));
  if ( gethostname(name: host, namelen: 255) < 0 )
    V_strncpy(pDest: host, pSrc: dateString->m_szBuf, maxLen: 255);
  host[255] = 0;
  v10 = _CommandLine();
  v11 = (char *)(*(int (__thiscall **)(int, const char *, _DWORD))(*(_DWORD *)v10 + 32))(
                  a1: v10,
                  a2: "-benchmark_path",
                  a3: 0);
  CUtlString::CUtlString(this: &benchmarkPath, pString: v11);
  if ( CUtlString::Length(this: &benchmarkPath) != 0 )
    CUtlString::StripTrailingSlash(this: &benchmarkPath);
  else
    CUtlString::operator=(this: &benchmarkPath, src: ".");
  v13 = CUtlString::Get(this: &gpuName);
  v12 = CUtlString::Get(this: &benchmarkPath);
  CFmtStrN<256>::sprintf(this: fileName, pszFormat: "%s\\SourceBench_%s_%s.csv", v12, v13, host);
  benchmarkPath.m_Storage.m_nActualLength = 0;
  if ( benchmarkPath.m_Storage.m_Memory.m_nGrowSize >= 0 )
  {
    if ( benchmarkPath.m_Storage.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: benchmarkPath.m_Storage.m_Memory.m_pMemory);
      benchmarkPath.m_Storage.m_Memory.m_pMemory = nullptr;
    }
    benchmarkPath.m_Storage.m_Memory.m_nAllocationCount = 0;
  }
  gpuName.m_Storage.m_nActualLength = 0;
  if ( gpuName.m_Storage.m_Memory.m_nGrowSize >= 0 && gpuName.m_Storage.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: gpuName.m_Storage.m_Memory.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x10074760
// Name: public: void CDemoPlayer::WriteTimeDemoResults(void)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __thiscall CDemoPlayer::WriteTimeDemoResults(CDemoPlayer *this)
{
  int v2; // eax
  int v3; // eax
  int v4; // esi
  bool v5; // cc
  long double v6; // st7
  float m_flTotalFPSVariability; // xmm1_4
  void *v8; // esi
  IMatRenderContext *v9; // edi
  ImageFormat v10; // eax
  IMaterialSystem_vtbl *v11; // ebx
  int v12; // eax
  int m_nValue; // ecx
  IFileSystem_vtbl *v14; // ebx
  int v15; // eax
  const char *v16; // eax
  const ImageFormatInfo_t *v17; // eax
  int v18; // eax
  int v19; // eax
  int v20; // eax
  int v21; // eax
  const char *v22; // ecx
  int v23; // eax
  const char *v24; // ecx
  _BYTE v25[60]; // [esp+2Ch] [ebp-45Ch] BYREF
  MaterialAdapterInfo_t info; // [esp+68h] [ebp-420h] BYREF
  CFmtStrN<256> dateString; // [esp+28Ch] [ebp-1FCh] BYREF
  _BYTE fileName_204[36]; // [esp+464h] [ebp-24h] OVERLAPPED BYREF

  v2 = host_framecount - this->m_nTimeDemoStartFrame;
  *(_DWORD *)&fileName_204[32] = this;
  v3 = v2 - 1;
  if ( v3 >= 1 )
  {
    *(_DWORD *)&fileName_204[28] = v3;
    v4 = v3;
  }
  else
  {
    v4 = 1;
    *(_DWORD *)&fileName_204[28] = 1;
  }
  v5 = _Plat_FloatTime() - this->m_flTimeDemoStartTime >= 1.0;
  v6 = 1.0;
  if ( v5 )
    v6 = _Plat_FloatTime() - this->m_flTimeDemoStartTime;
  m_flTotalFPSVariability = this->m_flTotalFPSVariability;
  *(float *)&fileName_204[20] = v6;
  *(float *)&fileName_204[16] = m_flTotalFPSVariability / (float)v4;
  *(float *)&fileName_204[24] = (float)v4;
  *(float *)&fileName_204[12] = (float)v4 / *(float *)&fileName_204[20];
  ConMsg(
    a1: "%i frames %5.3f seconds %5.2f fps (%5.2f ms/f) %5.3f fps variability\n",
    v4,
    (double)v6,
    *(float *)&fileName_204[12],
    (double)(1000.0 * v6 / (float)v4),
    *(float *)&fileName_204[16]);
  *(_DWORD *)&dateString.m_szBuf[203] = &CFmtStrN<256>::`vftable';
  *(_DWORD *)&info.m_pDriverName[488] = &CFmtStrN<256>::`vftable';
  *(_WORD *)&dateString.m_szBuf[207] = 1;
  *(_DWORD *)fileName_204 = 0;
  *(_WORD *)&info.m_pDriverName[492] = 1;
  *(_DWORD *)&dateString.m_szBuf[199] = 0;
  ComputeTimedemoResultsFilename(
    fileName: (CFmtStrN<256> *)&dateString.m_szBuf[203],
    dateString: (CFmtStrN<256> *)&info.m_pDriverName[488]);
  g_pFileSystem->FileExists(this: &g_pFileSystem->IBaseFileSystem, a2: &dateString.m_szBuf[208], a3: nullptr);
  v8 = g_pFileSystem->Open(this: &g_pFileSystem->IBaseFileSystem, a2: &dateString.m_szBuf[208], a3: "a+", a4: 0);
  if ( v8 != nullptr )
  {
    if ( g_pFileSystem->Size_2(this: &g_pFileSystem->IBaseFileSystem, a2: v8) == 0 )
    {
      g_pFileSystem->FPrintf(this: g_pFileSystem, a2: v8, a3: "Portal 2 Benchmark Results\n\n");
      g_pFileSystem->FPrintf(this: g_pFileSystem, a2: v8, a3: "demofile,");
      g_pFileSystem->FPrintf(this: g_pFileSystem, a2: v8, a3: "frame data csv,");
      g_pFileSystem->FPrintf(this: g_pFileSystem, a2: v8, a3: "fps,");
      g_pFileSystem->FPrintf(this: g_pFileSystem, a2: v8, a3: "fps variability,");
      g_pFileSystem->FPrintf(this: g_pFileSystem, a2: v8, a3: "total sec,");
      g_pFileSystem->FPrintf(this: g_pFileSystem, a2: v8, a3: "width,");
      g_pFileSystem->FPrintf(this: g_pFileSystem, a2: v8, a3: "height,");
      g_pFileSystem->FPrintf(this: g_pFileSystem, a2: v8, a3: "msaa,");
      g_pFileSystem->FPrintf(this: g_pFileSystem, a2: v8, a3: "aniso,");
      g_pFileSystem->FPrintf(this: g_pFileSystem, a2: v8, a3: "picmip,");
      g_pFileSystem->FPrintf(this: g_pFileSystem, a2: v8, a3: "numframes,");
      g_pFileSystem->FPrintf(this: g_pFileSystem, a2: v8, a3: "dxlevel,");
      g_pFileSystem->FPrintf(this: g_pFileSystem, a2: v8, a3: "backbuffer,");
      g_pFileSystem->FPrintf(this: g_pFileSystem, a2: v8, a3: "cmdline,");
      g_pFileSystem->FPrintf(this: g_pFileSystem, a2: v8, a3: "driver,");
      g_pFileSystem->FPrintf(this: g_pFileSystem, a2: v8, a3: "vendor id,");
      g_pFileSystem->FPrintf(this: g_pFileSystem, a2: v8, a3: "device id,");
      g_pFileSystem->FPrintf(this: g_pFileSystem, a2: v8, a3: "sound,");
      g_pFileSystem->FPrintf(this: g_pFileSystem, a2: v8, a3: "vsync,");
      g_pFileSystem->FPrintf(this: g_pFileSystem, a2: v8, a3: "gpu_level,");
      g_pFileSystem->FPrintf(this: g_pFileSystem, a2: v8, a3: "cpu_level,");
      g_pFileSystem->FPrintf(this: g_pFileSystem, a2: v8, a3: "date,");
      g_pFileSystem->FPrintf(this: g_pFileSystem, a2: v8, a3: "\n");
    }
    if ( (_S2_0 & 1) == 0 )
    {
      _S2_0 |= 1u;
      ConVarRef::ConVarRef(this: &gpu_level, pName: "gpu_level");
    }
    if ( (_S2_0 & 2) == 0 )
    {
      _S2_0 |= 2u;
      ConVarRef::ConVarRef(this: &cpu_level, pName: "cpu_level");
    }
    if ( (_S2_0 & 4) == 0 )
    {
      _S2_0 |= 4u;
      ConVarRef::ConVarRef(this: &mat_vsync, pName: "mat_vsync");
    }
    if ( (_S2_0 & 8) == 0 )
    {
      _S2_0 |= 8u;
      ConVarRef::ConVarRef(this: &mat_antialias, pName: "mat_antialias");
    }
    if ( (_S2_0 & 0x10) == 0 )
    {
      _S2_0 |= 0x10u;
      ConVarRef::ConVarRef(this: &mat_forceaniso, pName: "mat_forceaniso");
    }
    if ( (_S2_0 & 0x20) == 0 )
    {
      _S2_0 |= 0x20u;
      ConVarRef::ConVarRef(this: &mat_picmip, pName: "mat_picmip");
    }
    v9 = materials->GetRenderContext(this: materials);
    if ( v9 != nullptr )
      v9->BeginRender(this: v9);
    v9->GetWindowSize(this: v9, a2: (int *)&fileName_204[8], a3: (int *)&fileName_204[4]);
    v10 = materials->GetBackBufferFormat(this: materials);
    v11 = materials->__vftable;
    *(_DWORD *)&fileName_204[24] = v10;
    v12 = ((int (__thiscall *)(IMaterialSystem *, _BYTE *))v11->GetCurrentAdapter)(a1: materials, a2: v25);
    ((void (__thiscall *)(IMaterialSystem *, int))v11->GetDisplayAdapterInfo)(a1: materials, a2: v12);
    g_pFileSystem->Seek(this: &g_pFileSystem->IBaseFileSystem, a2: v8, a3: 0, a4: FILESYSTEM_SEEK_TAIL);
    g_pFileSystem->FPrintf(this: g_pFileSystem, a2: v8, a3: "%s,", *(_DWORD *)&fileName_204[32] + 4);
    g_pFileSystem->FPrintf(this: g_pFileSystem, a2: v8, a3: "%s,", g_pStatsFile);
    g_pFileSystem->FPrintf(this: g_pFileSystem, a2: v8, a3: "%5.1f,", *(float *)&fileName_204[12]);
    g_pFileSystem->FPrintf(this: g_pFileSystem, a2: v8, a3: "%5.1f,", *(float *)&fileName_204[16]);
    g_pFileSystem->FPrintf(this: g_pFileSystem, a2: v8, a3: "%5.1f,", *(float *)&fileName_204[20]);
    g_pFileSystem->FPrintf(this: g_pFileSystem, a2: v8, a3: "%i,", *(_DWORD *)&fileName_204[8]);
    g_pFileSystem->FPrintf(this: g_pFileSystem, a2: v8, a3: "%i,", *(_DWORD *)&fileName_204[4]);
    m_nValue = 1;
    if ( mat_antialias.m_pConVarState->m_Value.m_nValue >= 1 )
      m_nValue = mat_antialias.m_pConVarState->m_Value.m_nValue;
    g_pFileSystem->FPrintf(this: g_pFileSystem, a2: v8, a3: "%i,", m_nValue);
    g_pFileSystem->FPrintf(this: g_pFileSystem, a2: v8, a3: "%i,", mat_forceaniso.m_pConVarState->m_Value.m_nValue);
    g_pFileSystem->FPrintf(this: g_pFileSystem, a2: v8, a3: "%i,", mat_picmip.m_pConVarState->m_Value.m_nValue);
    g_pFileSystem->FPrintf(this: g_pFileSystem, a2: v8, a3: "%i,", *(_DWORD *)&fileName_204[28]);
    v14 = g_pFileSystem->IAppSystem::__vftable;
    v15 = g_pMaterialSystemHardwareConfig->GetDXSupportLevel(this: g_pMaterialSystemHardwareConfig);
    v16 = COM_DXLevelToString(dxlevel: v15);
    v14->FPrintf(this: g_pFileSystem, a2: v8, a3: "%s,", v16);
    v17 = ImageLoader::ImageFormatInfo(fmt: *(ImageFormat *)&fileName_204[24]);
    g_pFileSystem->FPrintf(this: g_pFileSystem, a2: v8, a3: "%s,", v17->m_pName);
    v18 = _CommandLine();
    *(_DWORD *)&fileName_204[32] = g_pFileSystem->IAppSystem::__vftable;
    v19 = (*(int (__thiscall **)(int))(*(_DWORD *)v18 + 8))(a1: v18);
    (*(void (**)(IFileSystem *, void *, const char *, ...))(*(_DWORD *)&fileName_204[32] + 108))(
      a1: g_pFileSystem,
      a2: v8,
      a3: "%s,",
      v19);
    g_pFileSystem->FPrintf(this: g_pFileSystem, a2: v8, a3: "%s,", v25);
    g_pFileSystem->FPrintf(this: g_pFileSystem, a2: v8, a3: "0x%x,", *(_DWORD *)&info.m_pDriverName[452]);
    g_pFileSystem->FPrintf(this: g_pFileSystem, a2: v8, a3: "0x%x,", *(_DWORD *)&info.m_pDriverName[456]);
    v20 = _CommandLine();
    v21 = (*(int (__thiscall **)(int, const char *, _DWORD))(*(_DWORD *)v20 + 12))(a1: v20, a2: "-nosound", a3: 0);
    v22 = "disabled";
    if ( v21 == 0 )
      v22 = "enabled";
    g_pFileSystem->FPrintf(this: g_pFileSystem, a2: v8, a3: "%s,", v22);
    v23 = _CommandLine();
    if ( (*(int (__thiscall **)(int, const char *, _DWORD))(*(_DWORD *)v23 + 12))(a1: v23, a2: "-mat_vsync", a3: 0) != 0
      || (v24 = "disabled", mat_vsync.m_pConVarState->m_Value.m_nValue != 0) )
    {
      v24 = "enabled";
    }
    g_pFileSystem->FPrintf(this: g_pFileSystem, a2: v8, a3: "%s,", v24);
    g_pFileSystem->FPrintf(this: g_pFileSystem, a2: v8, a3: "%d,", gpu_level.m_pConVarState->m_Value.m_nValue);
    g_pFileSystem->FPrintf(this: g_pFileSystem, a2: v8, a3: "%d,", cpu_level.m_pConVarState->m_Value.m_nValue);
    g_pFileSystem->FPrintf(this: g_pFileSystem, a2: v8, a3: "%s,", &info.m_pDriverName[493]);
    g_pFileSystem->FPrintf(this: g_pFileSystem, a2: v8, a3: "\n");
    g_pFileSystem->Close(this: &g_pFileSystem->IBaseFileSystem, a2: v8);
    v9->EndRender(this: v9);
    v9->Release(this: v9);
  }
  else
  {
    _Warning(a1: "DEMO: Failed to open %s!\n", &dateString.m_szBuf[208]);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10074F00
// Name: public: virtual void CDemoPlayer::StopPlayback(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDemoPlayer::StopPlayback(CDemoPlayer *this)
{
  int v2; // edi
  long double v3; // st6
  vgui::CTreeViewListControl *v4; // ecx
  ECommandTarget_t TraceType; // eax
  unsigned __int8 *data; // [esp-8h] [ebp-10h]

  if ( this->IsPlayingBack(this) )
  {
    demoaction->StopPlaying(this: demoaction);
    CDemoFile::Close(this: &this->m_DemoFile);
    *(_WORD *)&this->m_bPlayingBack = 0;
    this->m_flAutoResumeTime = 0.0;
    if ( this->m_bTimeDemo )
    {
      CEngineStats::EndRun(this: &g_EngineStats);
      if ( s_bBenchframe )
        CLoaderMemAlloc::CrtIsValidPointer(this: (ConVar *)&mat_norendering.IConVar, value: 0);
      else
        CDemoPlayer::WriteTimeDemoResults(this);
      this->m_bTimeDemo = false;
    }
    else
    {
      v2 = host_framecount - this->m_nTimeDemoStartFrame;
      v3 = _Plat_FloatTime() - this->m_flTimeDemoStartTime;
      if ( v3 > 0.0 )
        DevMsg(
          a1: "Demo playback finished ( %.1f seconds, %i render frames, %.2f fps).\n",
          (double)v3,
          v2,
          (double)((double)v2 / v3));
    }
    data = this->m_DemoPacket.data;
    this->m_flPlaybackRateModifier = 1.0;
    free(pMem: data);
    this->m_DemoPacket.data = nullptr;
    scr_demo_override_fov = 0.0;
    if ( demo_quitafterplayback.m_pParent != nullptr && demo_quitafterplayback.m_pParent->m_Value.m_nValue != 0 )
    {
      TraceType = CTraceFilter::GetTraceType(this: v4);
      Cbuf_AddText(eTarget: TraceType, pText: "quit\n", nTickDelay: 0);
    }
    g_ClientDLL->OnDemoPlaybackStop(this: g_ClientDLL);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10075030
// Name: public: bool CDemoPlayer::ParseAheadForInterval(int,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDemoPlayer::ParseAheadForInterval(CDemoPlayer *this, int curtick, int intervalticks)
{
  CDemoPlayer *v3; // esi
  int v4; // ecx
  float *p_z; // eax
  CDemoFile *p_m_DemoFile; // ebx
  DemoCommandQueue *m_pMemory; // eax
  int v8; // eax
  int CurPos; // edi
  int m_Size; // eax
  int v11; // ecx
  int *p_filepos; // edi
  int v13; // edi
  int m_nAllocationCount; // eax
  DemoCommandQueue *v15; // ecx
  int v16; // eax
  DemoCommandQueue *v17; // edi
  democmdinfo_t nextinfo; // [esp+0h] [ebp-150h] BYREF
  DemoCommandQueue entry; // [esp+98h] [ebp-B8h] BYREF
  CDemoPlayer *v21; // [esp+138h] [ebp-18h]
  int dummy; // [esp+13Ch] [ebp-14h] BYREF
  int starting_position; // [esp+140h] [ebp-10h]
  int tick; // [esp+144h] [ebp-Ch] BYREF
  int nPlayerSlot; // [esp+148h] [ebp-8h] BYREF
  unsigned __int8 cmd; // [esp+14Fh] [ebp-1h] BYREF

  v3 = this;
  v21 = this;
  tick = 0;
  cmd = 7;
  v4 = 1;
  p_z = &nextinfo.u[0].viewOrigin.z;
  do
  {
    *(p_z - 3) = 0.0;
    *(p_z - 2) = 0.0;
    *(p_z - 1) = 0.0;
    *p_z = 0.0;
    p_z[1] = 0.0;
    p_z[2] = 0.0;
    p_z[3] = 0.0;
    p_z[4] = 0.0;
    p_z[5] = 0.0;
    p_z[6] = 0.0;
    p_z[7] = 0.0;
    p_z[8] = 0.0;
    p_z[9] = 0.0;
    p_z[10] = 0.0;
    p_z[11] = 0.0;
    p_z[12] = 0.0;
    p_z[13] = 0.0;
    p_z[14] = 0.0;
    p_z[15] = 0.0;
    p_z += 19;
    --v4;
  }
  while ( v4 >= 0 );
  p_m_DemoFile = &v3->m_DemoFile;
  starting_position = CDemoFile::GetCurPos(this: &v3->m_DemoFile, bRead: true);
  if ( v3->m_DestCmdInfo.m_Size > 0 )
  {
    nPlayerSlot = curtick - 32;
    do
    {
      m_pMemory = v3->m_DestCmdInfo.m_Memory.m_pMemory;
      if ( m_pMemory->tick >= nPlayerSlot || m_pMemory->filepos >= starting_position )
        break;
      v8 = v3->m_DestCmdInfo.m_Size - 1;
      if ( v8 > 0 )
        _V_memmove(
          dest: v3->m_DestCmdInfo.m_Memory.m_pMemory,
          src: &v3->m_DestCmdInfo.m_Memory.m_pMemory[1],
          count: 160 * v8);
      --v3->m_DestCmdInfo.m_Size;
    }
    while ( v3->m_DestCmdInfo.m_Size > 0 );
  }
  if ( v3->m_bTimeDemo )
    return 0;
  do
  {
    while ( 2 )
    {
      nPlayerSlot = 0;
      CDemoFile::ReadCmdHeader(this: p_m_DemoFile, &cmd, &tick, &nPlayerSlot);
      switch ( cmd )
      {
        case 3u:
        case 7u:
          CDemoFile::SeekTo(this: p_m_DemoFile, position: starting_position, bRead: true);
          return 0;
        case 4u:
          CDemoFile::ReadConsoleCommand(this: p_m_DemoFile);
          continue;
        case 5u:
          CDemoFile::ReadUserCmd(this: p_m_DemoFile, buffer: nullptr, size: &dummy);
          continue;
        case 6u:
        case 9u:
          CDemoFile::ReadStringTables(this: p_m_DemoFile, buf: nullptr);
          continue;
        case 8u:
          CDemoFile::ReadCustomData(this: p_m_DemoFile, pCallbackIndex: nullptr, ppDataChunk: nullptr);
          continue;
        default:
          CurPos = CDemoFile::GetCurPos(this: p_m_DemoFile, bRead: true);
          nPlayerSlot = CurPos;
          CDemoFile::ReadCmdInfo(this: p_m_DemoFile, info: &nextinfo);
          CDemoFile::ReadSequenceInfo(this: p_m_DemoFile, nSeqNrIn: &dummy, nSeqNrOut: &dummy);
          CDemoFile::ReadRawData(this: p_m_DemoFile, buffer: nullptr, length: 0);
          DemoCommandQueue::DemoCommandQueue(this: &entry);
          democmdinfo_t::operator=(this: &entry.info, __that: &nextinfo);
          m_Size = v3->m_DestCmdInfo.m_Size;
          v11 = 0;
          entry.tick = tick;
          entry.filepos = CurPos;
          if ( m_Size <= 0 )
            goto LABEL_24;
          p_filepos = &v3->m_DestCmdInfo.m_Memory.m_pMemory->filepos;
          break;
      }
      break;
    }
    while ( *p_filepos != nPlayerSlot )
    {
      ++v11;
      p_filepos += 40;
      if ( v11 >= m_Size )
        goto LABEL_22;
    }
    if ( v11 < m_Size )
      continue;
LABEL_22:
    if ( v3->m_DestCmdInfo.m_Memory.m_pMemory[m_Size - 1].tick > tick )
      v3->m_DestCmdInfo.m_Size = 0;
LABEL_24:
    v13 = v3->m_DestCmdInfo.m_Size;
    m_nAllocationCount = v3->m_DestCmdInfo.m_Memory.m_nAllocationCount;
    if ( v13 + 1 > m_nAllocationCount )
      CUtlMemory<DemoCommandQueue,int>::Grow(this: &v3->m_DestCmdInfo.m_Memory, num: v13 - m_nAllocationCount + 1);
    ++v3->m_DestCmdInfo.m_Size;
    v15 = v3->m_DestCmdInfo.m_Memory.m_pMemory;
    v16 = v3->m_DestCmdInfo.m_Size - v13 - 1;
    v3->m_DestCmdInfo.m_pElements = v15;
    if ( v16 > 0 )
      _V_memmove(dest: &v15[v13 + 1], src: &v15[v13], count: 160 * v16);
    v17 = &v3->m_DestCmdInfo.m_Memory.m_pMemory[v13];
    if ( v17 != nullptr )
      *v17 = entry;
    v3 = v21;
  }
  while ( tick - curtick <= intervalticks );
  CDemoFile::SeekTo(this: p_m_DemoFile, position: starting_position, bRead: true);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100754D0
// Name: public: virtual struct netpacket_s __near * CDemoPlayer::ReadPacket(void)
// Source: json
//------------------------------------------------------------------------------
netpacket_s *__usercall CDemoPlayer::ReadPacket@<eax>(
        CDemoPlayer *this@<ecx>,
        int a2@<ebx>,
        const unsigned int *a3@<esi>)
{
  CDemoPlayer *v3; // edi
  char v5; // al
  int v6; // ebx
  bool v7; // zf
  int v8; // edx
  int m_nSkipToTick; // eax
  vgui::CTreeViewListControl *v10; // ecx
  char *ConsoleCommand; // esi
  ECommandTarget_t TraceType; // eax
  const unsigned int *v13; // ebx
  int UserCmd; // esi
  int v15; // eax
  int v16; // esi
  CUtlVector<DemoCustomDataCallbackMapping_t,CUtlMemory<DemoCustomDataCallbackMapping_t,int> > *p_m_CustomDataCallbackMap; // ebx
  int v18; // edi
  const unsigned int *m_pDataIn; // esi
  const unsigned int *v20; // ecx
  int v21; // esi
  const char *pszValue; // ecx
  const char *v23; // eax
  int v24; // ecx
  const char *v25; // eax
  CClientState *v26; // eax
  signed int RawData; // esi
  const unsigned int *data; // edx
  int v29; // eax
  bool v30; // al
  bool v31; // sf
  const char *m_SnapshotFilename; // ecx
  vgui::CTreeViewListControl *v33; // ecx
  ECommandTarget_t v34; // eax
  CClientState *BaseLocalClient; // eax
  int v36; // [esp+0h] [ebp-160h]
  const char *v37; // [esp+0h] [ebp-160h]
  int v38; // [esp+0h] [ebp-160h]
  unsigned int v41[3]; // [esp+10h] [ebp-150h] BYREF
  char buffer[256]; // [esp+1Ch] [ebp-144h] BYREF
  int outseqack; // [esp+11Ch] [ebp-44h]
  int iCallbackIndex; // [esp+120h] [ebp-40h] BYREF
  int inseq; // [esp+124h] [ebp-3Ch]
  int v46; // [esp+128h] [ebp-38h]
  bf_read msg; // [esp+12Ch] [ebp-34h] BYREF
  unsigned __int8 *pParse; // [esp+150h] [ebp-10h] BYREF
  int nPlayerSlot; // [esp+154h] [ebp-Ch]
  int length; // [esp+158h] [ebp-8h] BYREF
  unsigned __int8 *pData; // [esp+15Ch] [ebp-4h] BYREF

  v3 = this;
  outseqack = (int)this;
  length = 0;
  HIBYTE(pData) = 1;
  if ( !CDemoFile::IsOpen(this: &this->m_DemoFile) )
  {
    v3->m_bPlayingBack = false;
    Host_EndGame(bShowMainMenu: true, message: "Tried to read a demo message with no demo file\n");
    return nullptr;
  }
  if ( HostState_IsGameShuttingDown() || CDemoPlayer::CheckPausedPlayback(this: v3) )
    return nullptr;
  while ( 1 )
  {
LABEL_6:
    nPlayerSlot = CDemoFile::GetCurPos(this: &v3->m_DemoFile, bRead: true);
    msg.m_pBufferEnd = nullptr;
    CDemoFile::ReadCmdHeader(
      this: &v3->m_DemoFile,
      cmd: (unsigned __int8 *)&pData + 3,
      tick: &length,
      nPlayerSlot: (int *)&msg.m_pBufferEnd);
    v5 = HIBYTE(pData);
    if ( HIBYTE(pData) != 1 && HIBYTE(pData) != 7 && HIBYTE(pData) != 3 && HIBYTE(pData) != 6 && HIBYTE(pData) != 9 )
    {
      v6 = v3->GetPlaybackTick(this: v3);
      if ( v3->m_bTimeDemo )
      {
        v7 = v3->m_nTimeDemoCurrentFrame == host_framecount;
      }
      else
      {
        if ( GetBaseLocalClient()->m_nSignonState != 6 || length <= v6 )
          goto LABEL_17;
        v7 = !v3->IsSkipping(this: v3);
      }
      if ( v7 )
        break;
LABEL_17:
      v5 = HIBYTE(pData);
    }
    switch ( v5 )
    {
      case 3:
        if ( demo_debug.m_pParent != nullptr && demo_debug.m_pParent->m_Value.m_nValue != 0 )
          _Msg(a1: "%d dem_synctick\n", length);
        v8 = host_tickcount;
        v3->m_nPreviousTick = host_tickcount;
        m_nSkipToTick = v3->m_nSkipToTick;
        v3->m_nStartTick = v8;
        if ( m_nSkipToTick != -1 && (m_nSkipToTick & 0x88000000) == 0x88000000 )
          v3->m_nSkipToTick = m_nSkipToTick & 0x77FFFFFF;
        continue;
      case 4:
        ConsoleCommand = CDemoFile::ReadConsoleCommand(this: &v3->m_DemoFile);
        if ( demo_debug.m_pParent != nullptr && demo_debug.m_pParent->m_Value.m_nValue != 0 )
          _Msg(a1: "%d dem_consolecmd [%s]\n", length, ConsoleCommand);
        TraceType = CTraceFilter::GetTraceType(this: v10);
        Cbuf_AddText(eTarget: TraceType, pText: ConsoleCommand, nTickDelay: 0);
        Cbuf_Execute();
        continue;
      case 5:
        if ( demo_debug.m_pParent != nullptr && demo_debug.m_pParent->m_Value.m_nValue != 0 )
          _Msg(a1: "%d dem_usercmd\n", length);
        msg.m_pData = (const unsigned int *)256;
        UserCmd = CDemoFile::ReadUserCmd(this: &v3->m_DemoFile, buffer: (char *)v41, size: (int *)&msg.m_pData);
        LOBYTE(inseq) = 0;
        v46 = -1;
        msg.m_pDebugName = nullptr;
        iCallbackIndex = (int)"CDemo::ReadUserCmd";
        CBitRead::StartReading(
          this: (CBitRead *)&iCallbackIndex,
          pData: v41,
          nBytes: (unsigned int)msg.m_pData,
          iStartBit: 0,
          nBits: -1);
        g_ClientDLL->DecodeUserCmdFromBuffer(
          this: g_ClientDLL,
          a2: (int)msg.m_pBufferEnd,
          a3: (bf_read *)&iCallbackIndex,
          a4: UserCmd);
        GetBaseLocalClient()->lastoutgoingcommand = UserCmd;
        continue;
      case 6:
        if ( demo_debug.m_pParent != nullptr && demo_debug.m_pParent->m_Value.m_nValue != 0 )
          _Msg(a1: "%d dem_datatables\n", length);
        v13 = (const unsigned int *)((int (__thiscall *)(IMemAlloc *, int, const unsigned int *))_g_pMemAlloc->Alloc_2)(
                                      a1: _g_pMemAlloc,
                                      a2: 0x200000,
                                      a3);
        LOBYTE(inseq) = 0;
        v46 = -1;
        msg.m_pDebugName = nullptr;
        iCallbackIndex = (int)"dem_datatables";
        CBitRead::StartReading(
          this: (CBitRead *)&iCallbackIndex,
          pData: v13,
          nBytes: 0x200000u,
          iStartBit: 0,
          nBits: -1);
        CDemoFile::ReadStringTables(this: &v3->m_DemoFile, buf: (bf_read *)&iCallbackIndex);
        CBitRead::Seek(this: (CBitRead *)&iCallbackIndex, nPosition: 0);
        if ( !DataTable_LoadDataTablesFromBuffer(
                pBuf: (bf_read *)&iCallbackIndex,
                nDemoProtocol: v3->m_DemoFile.m_DemoHeader.demoprotocol) )
          Host_Error(error: "Error parsing network data tables during demo playback.");
        goto LABEL_34;
      case 7:
        if ( demo_debug.m_pParent != nullptr && demo_debug.m_pParent->m_Value.m_nValue != 0 )
          _Msg(a1: "%d dem_stop\n", length);
        BaseLocalClient = GetBaseLocalClient();
        BaseLocalClient->Disconnect(this: BaseLocalClient, a2: true);
        return nullptr;
      case 8:
        v15 = CDemoFile::ReadCustomData(
                this: &v3->m_DemoFile,
                pCallbackIndex: (int *)&buffer[248],
                ppDataChunk: &pParse);
        if ( *(_DWORD *)&buffer[248] == -1 )
        {
          v16 = *(_DWORD *)pParse;
          p_m_CustomDataCallbackMap = &v3->m_CustomDataCallbackMap;
          v36 = *(_DWORD *)pParse;
          msg.m_pDataIn = (const unsigned int *)(pParse + 4);
          CUtlVector<DemoCustomDataCallbackMapping_t,CUtlMemory<DemoCustomDataCallbackMapping_t,int>>::SetSize(
            this: &v3->m_CustomDataCallbackMap,
            size: v36);
          if ( v16 == 0 )
            continue;
          v18 = 0;
          nPlayerSlot = v16;
          while ( 1 )
          {
            m_pDataIn = msg.m_pDataIn;
            CUtlString::operator=(
              this: &p_m_CustomDataCallbackMap->m_Memory.m_pMemory[v18].name,
              src: (const char *)msg.m_pDataIn);
            v20 = (const unsigned int *)((char *)m_pDataIn + _V_strlen(str: (const char *)m_pDataIn) + 1);
            v21 = 0;
            msg.m_pDataIn = v20;
            if ( g_RegisteredDemoCustomDataCallbacks.m_Size != 0 )
            {
              while ( 1 )
              {
                pszValue = g_RegisteredDemoCustomDataCallbacks.m_Memory.m_pMemory[v21].szSaveID.pszValue;
                if ( pszValue == nullptr )
                  pszValue = defaultValue;
                v37 = pszValue;
                v23 = CUtlString::Get(this: &p_m_CustomDataCallbackMap->m_Memory.m_pMemory[v18].name);
                if ( _V_stricmp(s1: v23, s2: v37) == 0 )
                  break;
                if ( ++v21 == g_RegisteredDemoCustomDataCallbacks.m_Size )
                  goto LABEL_52;
              }
              p_m_CustomDataCallbackMap->m_Memory.m_pMemory[v18].pCallback = g_RegisteredDemoCustomDataCallbacks.m_Memory.m_pMemory[v21].pCallback;
            }
LABEL_52:
            ++v18;
            if ( --nPlayerSlot == 0 )
            {
              v3 = (CDemoPlayer *)outseqack;
              goto LABEL_6;
            }
          }
        }
        v24 = (int)&v3->m_CustomDataCallbackMap.m_Memory.m_pMemory[*(_DWORD *)&buffer[248]];
        if ( *(_DWORD *)v24 != 0 )
        {
          (*(void (__cdecl **)(unsigned __int8 *, int))v24)(a1: pParse, a2: v15);
        }
        else
        {
          v25 = CUtlString::Get(this: (CUtlString *)(v24 + 4));
          _Warning(a1: "Unable to decode custom demo data, callback \"%s\" not found.\n", v25);
        }
        break;
      case 9:
        v13 = (const unsigned int *)((int (__thiscall *)(IMemAlloc *, int, const unsigned int *))_g_pMemAlloc->Alloc_2)(
                                      a1: _g_pMemAlloc,
                                      a2: 0x200000,
                                      a3);
        LOBYTE(inseq) = 0;
        v46 = -1;
        msg.m_pDebugName = nullptr;
        iCallbackIndex = (int)"dem_stringtables";
        CBitRead::StartReading(
          this: (CBitRead *)&iCallbackIndex,
          pData: v13,
          nBytes: 0x200000u,
          iStartBit: 0,
          nBits: -1);
        CDemoFile::ReadStringTables(this: &v3->m_DemoFile, buf: (bf_read *)&iCallbackIndex);
        CBitRead::Seek(this: (CBitRead *)&iCallbackIndex, nPosition: 0);
        if ( !CNetworkStringTableContainer::ReadStringTables(
                this: networkStringTableContainerClient,
                buf: (bf_read *)&iCallbackIndex) )
          Host_Error(error: "Error parsing string tables during demo playback.");
LABEL_34:
        a3 = v13;
        ((void (__thiscall *)(IMemAlloc *))_g_pMemAlloc->Free_2)(a1: _g_pMemAlloc);
        continue;
      default:
        if ( ((unsigned __int8 (__thiscall *)(CDemoPlayer *, const unsigned int *, int))v3->IsSkipping)(
               a1: v3,
               a2: a3,
               a3: a2) != 0 )
          v3->m_nStartTick = host_tickcount - length;
        if ( HIBYTE(pData) == 2 )
          v3->m_nTimeDemoCurrentFrame = host_framecount;
        CDemoFile::ReadCmdInfo(this: &v3->m_DemoFile, info: &v3->m_LastCmdInfo);
        CDemoFile::ReadSequenceInfo(
          this: &v3->m_DemoFile,
          nSeqNrIn: (int *)&buffer[252],
          nSeqNrOut: (int *)&buffer[244]);
        v26 = GetBaseLocalClient();
        ((void (__thiscall *)(INetChannel *, _DWORD))v26->m_NetChannel->SetSequenceData)(a1: v26->m_NetChannel, a2: 0);
        RawData = CDemoFile::ReadRawData(this: &v3->m_DemoFile, buffer: (char *)v3->m_DemoPacket.data, length: 96000);
        if ( demo_debug.m_pParent != nullptr && demo_debug.m_pParent->m_Value.m_nValue != 0 )
          _Msg(a1: "%d network packet [%d]\n", length, RawData);
        if ( RawData > 0 )
        {
          data = (const unsigned int *)v3->m_DemoPacket.data;
          v3->m_DemoPacket.received = realtime;
          v3->m_DemoPacket.size = RawData;
          CBitRead::StartReading(this: &v3->m_DemoPacket.message, pData: data, nBytes: RawData, iStartBit: 0, nBits: -1);
          if ( demo_debug.m_pParent != nullptr && demo_debug.m_pParent->m_Value.m_nValue >= 1 )
          {
            v29 = ((int (__thiscall *)(CDemoPlayer *, signed int))v3->GetPlaybackTick)(a1: v3, a2: RawData);
            _Msg(a1: "Demo message, tick %i, %i bytes\n", v29, v38);
          }
        }
        v30 = CDemoPlayer::ParseAheadForInterval(this: v3, curtick: length, intervalticks: 8);
        v31 = v3->m_nTimeDemoStartFrame < 0;
        v3->m_bInterpolateView = v30;
        if ( v31 && v3->GetPlaybackTick(this: v3) > 100 )
        {
          v3->m_nTimeDemoStartFrame = host_framecount;
          v3->m_flTimeDemoStartTime = _Plat_FloatTime();
          v7 = !v3->m_bTimeDemo;
          v3->m_flTotalFPSVariability = 0.0;
          if ( !v7 )
            CEngineStats::BeginRun(this: &g_EngineStats);
        }
        if ( v3->m_nSnapshotTick > 0 && v3->m_nSnapshotTick <= v3->GetPlaybackTick(this: v3) )
        {
          m_SnapshotFilename = "benchframe";
          if ( v3->m_SnapshotFilename[0] != 0 )
            m_SnapshotFilename = v3->m_SnapshotFilename;
          CL_TakeScreenshot(name: m_SnapshotFilename);
          v7 = !s_bBenchframe;
          v3->m_nSnapshotTick = 0;
          if ( !v7 )
          {
            v34 = CTraceFilter::GetTraceType(this: v33);
            Cbuf_AddText(eTarget: v34, pText: "stopdemo\n", nTickDelay: 0);
          }
        }
        return &v3->m_DemoPacket;
    }
  }
  ((void (__stdcall *)(_DWORD, int, _DWORD))demoaction->Update)(
    a1: 0,
    a2: v6,
    a3: (float)v6 * host_state.interval_per_tick);
  CDemoFile::SeekTo(this: &v3->m_DemoFile, position: nPlayerSlot, bRead: true);
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10075BB0
// Name: public: CDemoPlayer::CDemoPlayer(void)
// Source: json
//------------------------------------------------------------------------------
CDemoPlayer *__thiscall CDemoPlayer::CDemoPlayer(CDemoPlayer *this)
{
  democmdinfo_t *p_m_LastCmdInfo; // ecx
  int v3; // edi
  float *p_z; // eax

  this->__vftable = (CDemoPlayer_vtbl *)&CDemoPlayer::`vftable';
  CDemoFile::CDemoFile(this: &this->m_DemoFile);
  netadr_s::SetIP(this: &this->m_DemoPacket.from, unIP: 0);
  netadr_s::SetPort(this: &this->m_DemoPacket.from, newport: 0);
  netadr_s::SetType(this: &this->m_DemoPacket.from, newtype: NA_IP);
  this->m_DemoPacket.message.m_bOverflow = false;
  this->m_DemoPacket.message.m_pDebugName = nullptr;
  this->m_DemoPacket.message.m_nDataBytes = 0;
  this->m_DemoPacket.message.m_nDataBits = -1;
  p_m_LastCmdInfo = &this->m_LastCmdInfo;
  this->m_DestCmdInfo.m_Memory.m_pMemory = nullptr;
  this->m_DestCmdInfo.m_Memory.m_nAllocationCount = 0;
  this->m_DestCmdInfo.m_Memory.m_nGrowSize = 0;
  this->m_DestCmdInfo.m_Size = 0;
  this->m_DestCmdInfo.m_pElements = nullptr;
  v3 = 1;
  p_z = &this->m_LastCmdInfo.u[0].viewOrigin.z;
  do
  {
    p_m_LastCmdInfo->u[0].flags = 0;
    *(p_z - 2) = 0.0;
    *(p_z - 1) = 0.0;
    *p_z = 0.0;
    p_z[1] = 0.0;
    p_z[2] = 0.0;
    p_z[3] = 0.0;
    p_z[4] = 0.0;
    p_z[5] = 0.0;
    p_z[6] = 0.0;
    p_z[7] = 0.0;
    p_z[8] = 0.0;
    p_z[9] = 0.0;
    p_z[10] = 0.0;
    p_z[11] = 0.0;
    p_z[12] = 0.0;
    p_z[13] = 0.0;
    p_z[14] = 0.0;
    p_z[15] = 0.0;
    p_m_LastCmdInfo = (democmdinfo_t *)((char *)p_m_LastCmdInfo + 76);
    p_z += 19;
    --v3;
  }
  while ( v3 >= 0 );
  this->m_CustomDataCallbackMap.m_Memory.m_pMemory = nullptr;
  this->m_CustomDataCallbackMap.m_Memory.m_nAllocationCount = 0;
  this->m_CustomDataCallbackMap.m_Memory.m_nGrowSize = 0;
  this->m_CustomDataCallbackMap.m_Size = 0;
  this->m_CustomDataCallbackMap.m_pElements = nullptr;
  this->m_flTimeDemoStartTime = 0.0;
  *(_WORD *)&this->m_bPlayingBack = 0;
  this->m_nSnapshotTick = 0;
  this->m_SnapshotFilename[0] = 0;
  *(_WORD *)&this->m_bResetInterpolation = 0;
  this->m_nPreviousTick = 0;
  this->m_flAutoResumeTime = 0.0;
  this->m_flPlaybackRateModifier = 1.0;
  this->m_nTimeDemoStartFrame = -1;
  this->m_flTotalFPSVariability = 0.0;
  this->m_nTimeDemoCurrentFrame = -1;
  this->m_nSkipToTick = -1;
  return this;
}

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x10070FC0
// Name: public: void DemoOverlay::DrawOverlay(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall DemoOverlay::DrawOverlay(DemoOverlay *this, float fSetting)
{
  float v2; // xmm1_4
  int v4; // ebx
  int v5; // esi
  con_nprint_s xprn; // [esp+0h] [ebp-18h] BYREF

  v2 = fSetting;
  if ( fSetting >= 0.0 && (fSetting == 0.0 || this->m_maskDrawnOverlay != 0) )
  {
    v4 = 0;
  }
  else
  {
    v5 = demoplayer->IsPlayingBack(this: demoplayer) ? 4 : 0;
    v2 = fSetting;
    v4 = v5 | (demorecorder->IsRecording(this: demorecorder) ? 2 : 0);
    if ( v4 != 0 )
      goto LABEL_8;
  }
  if ( this->m_maskDrawnOverlay != 0 )
  {
    memset(xprn.color, 0, 16);
    xprn.index = 1;
    xprn.time_to_live = -1.0;
    Con_NXPrintf(info: &xprn, fmt: defaultValue);
    v2 = fSetting;
  }
LABEL_8:
  if ( (v4 & 4) != 0 )
  {
    *(_DWORD *)&xprn.fixed_width_font = 1;
    xprn.time_to_live = 0.0;
    xprn.index = 1;
    xprn.color[0] = 0.0;
    xprn.color[1] = 1.0;
    xprn.color[2] = 0.0;
    if ( v2 <= 0.0 )
      xprn.time_to_live = 1.0;
    else
      xprn.time_to_live = v2;
    Con_NXPrintf(info: &xprn, fmt: "  PLAY   ");
    v2 = fSetting;
  }
  if ( (v4 & 2) != 0 )
  {
    *(_DWORD *)&xprn.fixed_width_font = 1;
    xprn.time_to_live = 0.0;
    xprn.index = 1;
    xprn.color[0] = 1.0;
    xprn.color[1] = 0.0;
    xprn.color[2] = 0.0;
    if ( v2 <= 0.0 )
      xprn.time_to_live = 1.0;
    else
      xprn.time_to_live = v2;
    Con_NXPrintf(info: &xprn, fmt: "   REC   ");
  }
  this->m_maskDrawnOverlay = v4;
}

//------------------------------------------------------------------------------
// Address: 0x10071140
// Name: public: virtual void CDemoRecorder::RecordCustomData(int,void const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDemoRecorder::RecordCustomData(
        CDemoRecorder *this,
        int iCallbackIndex,
        const void *pData,
        unsigned int iDataLength)
{
  int v5; // eax

  if ( CDemoFile::IsOpen(this: &this->m_DemoFile) )
  {
    v5 = this->GetRecordingTick(this);
    CDemoFile::WriteCustomData(this: &this->m_DemoFile, iCallbackIndex, pData, iDataSize: iDataLength, tick: v5);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10071180
// Name: public: virtual void CDemoRecorder::ResetDemoInterpolation(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDemoRecorder::ResetDemoInterpolation(CDemoRecorder *this)
{
  this->m_bResetInterpolation = true;
}

//------------------------------------------------------------------------------
// Address: 0x10071190
// Name: public: virtual class CDemoFile __near * CDemoPlayer::GetDemoFile(void)
// Source: json
//------------------------------------------------------------------------------
CDemoFile *__thiscall CDemoPlayer::GetDemoFile(CDemoPlayer *this)
{
  return &this->m_DemoFile;
}

//------------------------------------------------------------------------------
// Address: 0x100711A0
// Name: public: virtual bool CDemoPlayer::IsSkipping(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CDemoPlayer::IsSkipping(CDemoPlayer *this)
{
  return this->m_bPlayingBack && this->m_nSkipToTick != -1;
}

//------------------------------------------------------------------------------
// Address: 0x100711C0
// Name: public: virtual int CDemoPlayer::GetTotalTicks(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDemoPlayer::GetTotalTicks(CDemoPlayer *this)
{
  return this->m_DemoFile.m_DemoHeader.playback_ticks;
}

//------------------------------------------------------------------------------
// Address: 0x100711D0
// Name: public: virtual void CDemoPlayer::SkipToTick(int,bool,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDemoPlayer::SkipToTick(CDemoPlayer *this, int tick, bool bRelative, bool bPause)
{
  int v5; // edi
  char fileName[260]; // [esp+14h] [ebp-104h] BYREF

  if ( bRelative )
    v5 = this->GetPlaybackTick(this) + tick;
  else
    v5 = tick;
  if ( v5 >= 0 )
  {
    if ( v5 < this->GetPlaybackTick(this) )
    {
      V_strncpy(pDest: fileName, pSrc: this->m_DemoFile.m_szFileName, maxLen: 260);
      this->StartPlayback(this, a2: fileName, a3: this->m_bTimeDemo);
      if ( v5 > 0 )
        v5 |= 0x88000000;
    }
    this->m_nSkipToTick = v5;
    if ( bPause )
      ((void (__thiscall *)(CDemoPlayer *, _DWORD))this->PausePlayback)(a1: this, a2: -1.0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10071270
// Name: public: virtual bool CDemoPlayer::IsPlayingTimeDemo(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CDemoPlayer::IsPlayingTimeDemo(CDemoPlayer *this)
{
  return this->m_bTimeDemo && this->m_bPlayingBack;
}

//------------------------------------------------------------------------------
// Address: 0x10071290
// Name: public: virtual bool CDemoPlayer::IsPlayingBack(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDemoPlayer::IsPlayingBack(CDemoPlayer *this)
{
  return this->m_bPlayingBack;
}

//------------------------------------------------------------------------------
// Address: 0x100712A0
// Name: public: void CDemoPlayer::MarkFrame(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDemoPlayer::MarkFrame(CDemoPlayer *this, float flFPSVariability)
{
  this->m_flTotalFPSVariability = flFPSVariability + this->m_flTotalFPSVariability;
}

//------------------------------------------------------------------------------
// Address: 0x100712C0
// Name: public: virtual void CDemoPlayer::PausePlayback(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDemoPlayer::PausePlayback(CDemoPlayer *this, float seconds)
{
  this->m_bPlaybackPaused = true;
  if ( seconds <= 0.0 )
    this->m_flAutoResumeTime = 0.0;
  else
    this->m_flAutoResumeTime = _Plat_FloatTime(a1: this) + seconds;
}

//------------------------------------------------------------------------------
// Address: 0x10071300
// Name: public: virtual void CDemoPlayer::ResumePlayback(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDemoPlayer::ResumePlayback(CDemoPlayer *this)
{
  this->m_bPlaybackPaused = false;
  this->m_flAutoResumeTime = 0.0;
}

//------------------------------------------------------------------------------
// Address: 0x10071320
// Name: public: virtual bool CDemoPlayer::IsPlaybackPaused(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDemoPlayer::IsPlaybackPaused(CDemoPlayer *this)
{
  return this->IsPlayingBack(this)
      && this->m_nTimeDemoCurrentFrame >= 0
      && !this->IsSkipping(this)
      && this->m_bPlaybackPaused;
}

//------------------------------------------------------------------------------
// Address: 0x10071350
// Name: public: virtual int CDemoPlayer::GetPlaybackStartTick(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDemoPlayer::GetPlaybackStartTick(CDemoPlayer *this)
{
  return this->m_nStartTick;
}

//------------------------------------------------------------------------------
// Address: 0x10071360
// Name: public: virtual int CDemoPlayer::GetPlaybackTick(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDemoPlayer::GetPlaybackTick(CDemoPlayer *this)
{
  return host_tickcount - this->m_nStartTick;
}

//------------------------------------------------------------------------------
// Address: 0x10071370
// Name: public: virtual float CDemoPlayer::GetPlaybackTimeScale(void)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CDemoPlayer::GetPlaybackTimeScale(CDemoPlayer *this)
{
  return this->m_flPlaybackRateModifier;
}

//------------------------------------------------------------------------------
// Address: 0x10071380
// Name: public: virtual void CDemoPlayer::SetPlaybackTimeScale(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDemoPlayer::SetPlaybackTimeScale(CDemoPlayer *this, float timescale)
{
  this->m_flPlaybackRateModifier = timescale;
}

//------------------------------------------------------------------------------
// Address: 0x100713A0
// Name: ComputeNextIncrementalDemoFilename
// Source: json
//------------------------------------------------------------------------------
char __usercall ComputeNextIncrementalDemoFilename@<al>(char *name@<edi>, int a2@<esi>, int namesize)
{
  void *v3; // eax
  int v5; // esi
  void *v6; // eax
  char basename[260]; // [esp+0h] [ebp-208h] BYREF
  char newname[260]; // [esp+104h] [ebp-104h] BYREF

  v3 = g_pFileSystem->Open(this: &g_pFileSystem->IBaseFileSystem, a2: name, a3: "rb", a4: 0);
  if ( v3 == nullptr )
    return 1;
  ((void (__thiscall *)(IBaseFileSystem *, void *, int))g_pFileSystem->Close)(
    a1: &g_pFileSystem->IBaseFileSystem,
    a2: v3,
    a3: a2);
  V_StripExtension(in: name, out: basename, outSize: 260);
  v5 = 0;
  while ( 1 )
  {
    V_snprintf(pDest: newname, maxLen: 260, pFormat: "%s%03i.dem", basename, v5);
    v6 = g_pFileSystem->Open(this: &g_pFileSystem->IBaseFileSystem, a2: newname, a3: "rb", a4: 0);
    if ( v6 == nullptr )
      break;
    g_pFileSystem->Close(this: &g_pFileSystem->IBaseFileSystem, a2: v6);
    if ( ++v5 >= 1000 )
    {
      ConMsg(
        a1: "Unable to find a valid incremental demo filename for %s, try clearing the directory of %snnn.dem\n",
        name,
        basename);
      return 0;
    }
  }
  V_strncpy(pDest: name, pSrc: newname, maxLen: namesize);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10071490
// Name: stop
// Source: json
//------------------------------------------------------------------------------
void __cdecl stop()
{
  if ( cmd_source == src_command )
  {
    if ( demorecorder->IsRecording(this: demorecorder) )
    {
      demorecorder->StopRecording(this: demorecorder);
      g_ClientDLL->OnDemoRecordStop(this: g_ClientDLL);
    }
    else
    {
      _ConDMsg(a1: "Not recording a demo.\n");
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10071610
// Name: void CL_TimeDemo_Helper(char const __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CL_TimeDemo_Helper(const char *pDemoName, const char *pStatsFileName, const char *pVProfStatsFileName)
{
  const char *v3; // eax
  char name[260]; // [esp+0h] [ebp-104h] BYREF

  v3 = pStatsFileName;
  if ( pStatsFileName == nullptr )
    v3 = "UNKNOWN";
  V_strncpy(pDest: g_pStatsFile, pSrc: v3, maxLen: 260);
  demoplayer = g_pClientDemoPlayer;
  V_strncpy(pDest: name, pSrc: pDemoName, maxLen: 260);
  V_DefaultExtension(path: name, extension: ".dem", pathStringLength: 260);
  if ( pVProfStatsFileName != nullptr )
    CEngineStats::EnableVProfStatsRecording(this: &g_EngineStats, pFileName: pVProfStatsFileName);
  if ( !demoplayer->StartPlayback(this: demoplayer, a2: name, a3: true) )
    SCR_EndLoadingPlaque();
}

//------------------------------------------------------------------------------
// Address: 0x100716B0
// Name: g_playdemo_CompletionFunc
// Source: json
//------------------------------------------------------------------------------
int __cdecl g_playdemo_CompletionFunc(const char *partial, char (*commands)[64])
{
  if ( (_S3_0 & 1) == 0 )
  {
    _S3_0 |= 1u;
    playdemoComplete.m_pszCommandName = "playdemo";
    playdemoComplete.m_pszSubDir = nullptr;
    playdemoComplete.m_pszExtension = "dem";
  }
  return CBaseAutoCompleteFileList::AutoCompletionFunc(this: &playdemoComplete, partial, commands);
}

//------------------------------------------------------------------------------
// Address: 0x10071700
// Name: g_timedemo_CompletionFunc
// Source: json
//------------------------------------------------------------------------------
int __cdecl g_timedemo_CompletionFunc(const char *partial, char (*commands)[64])
{
  if ( (_S4 & 1) == 0 )
  {
    _S4 |= 1u;
    timedemoComplete.m_pszCommandName = "timedemo";
    timedemoComplete.m_pszSubDir = nullptr;
    timedemoComplete.m_pszExtension = "dem";
  }
  return CBaseAutoCompleteFileList::AutoCompletionFunc(this: &timedemoComplete, partial, commands);
}

//------------------------------------------------------------------------------
// Address: 0x10071750
// Name: g_timedemoquit_CompletionFunc
// Source: json
//------------------------------------------------------------------------------
int __cdecl g_timedemoquit_CompletionFunc(const char *partial, char (*commands)[64])
{
  if ( (_S5 & 1) == 0 )
  {
    _S5 |= 1u;
    timedemoquitComplete.m_pszCommandName = "timedemoquit";
    timedemoquitComplete.m_pszSubDir = nullptr;
    timedemoquitComplete.m_pszExtension = "dem";
  }
  return CBaseAutoCompleteFileList::AutoCompletionFunc(this: &timedemoquitComplete, partial, commands);
}

//------------------------------------------------------------------------------
// Address: 0x100717A0
// Name: g_listdemo_CompletionFunc
// Source: json
//------------------------------------------------------------------------------
int __cdecl g_listdemo_CompletionFunc(const char *partial, char (*commands)[64])
{
  if ( (_S6 & 1) == 0 )
  {
    _S6 |= 1u;
    listdemoComplete.m_pszCommandName = "listdemo";
    listdemoComplete.m_pszSubDir = nullptr;
    listdemoComplete.m_pszExtension = "dem";
  }
  return CBaseAutoCompleteFileList::AutoCompletionFunc(this: &listdemoComplete, partial, commands);
}

//------------------------------------------------------------------------------
// Address: 0x100717F0
// Name: g_benchframe_CompletionFunc
// Source: json
//------------------------------------------------------------------------------
int __cdecl g_benchframe_CompletionFunc(const char *partial, char (*commands)[64])
{
  if ( (_S7_0 & 1) == 0 )
  {
    _S7_0 |= 1u;
    benchframeComplete.m_pszCommandName = "benchframe";
    benchframeComplete.m_pszSubDir = nullptr;
    benchframeComplete.m_pszExtension = "dem";
  }
  return CBaseAutoCompleteFileList::AutoCompletionFunc(this: &benchframeComplete, partial, commands);
}

//------------------------------------------------------------------------------
// Address: 0x10071840
// Name: g_timedemo_vprofrecord_CompletionFunc
// Source: json
//------------------------------------------------------------------------------
int __cdecl g_timedemo_vprofrecord_CompletionFunc(const char *partial, char (*commands)[64])
{
  if ( (_S8 & 1) == 0 )
  {
    _S8 |= 1u;
    timedemo_vprofrecordComplete.m_pszCommandName = "timedemo_vprofrecord";
    timedemo_vprofrecordComplete.m_pszSubDir = nullptr;
    timedemo_vprofrecordComplete.m_pszExtension = "dem";
  }
  return CBaseAutoCompleteFileList::AutoCompletionFunc(this: &timedemo_vprofrecordComplete, partial, commands);
}

//------------------------------------------------------------------------------
// Address: 0x10071890
// Name: demo_resume
// Source: json
//------------------------------------------------------------------------------
void __cdecl demo_resume()
{
  demoplayer->ResumePlayback(this: demoplayer);
}

//------------------------------------------------------------------------------
// Address: 0x100718A0
// Name: demo_togglepause
// Source: json
//------------------------------------------------------------------------------
void __cdecl demo_togglepause()
{
  bool v0; // zf
  IDemoPlayer_vtbl *v1; // eax

  if ( demoplayer->IsPlayingBack(this: demoplayer) )
  {
    v0 = !demoplayer->IsPlaybackPaused(this: demoplayer);
    v1 = demoplayer->__vftable;
    if ( v0 )
      ((void (__stdcall *)(_DWORD))v1->PausePlayback)(a1: -1.0);
    else
      ((void (*)(void))v1->ResumePlayback)();
  }
}

//------------------------------------------------------------------------------
// Address: 0x100718E0
// Name: protected: bool CDemoPlayer::OverrideView(struct democmdinfo_t __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDemoPlayer::OverrideView(CDemoPlayer *this, democmdinfo_t *info)
{
  CDemoUIPanel_vtbl *v3; // ebx
  int v4; // eax
  bool result; // al
  CDemoUIPanel2_vtbl *v6; // ebx
  int v7; // eax
  IDemoActionManager_vtbl *v8; // ebx
  int v9; // eax

  result = true;
  if ( g_pDemoUI == nullptr
    || (v3 = g_pDemoUI->__vftable, v4 = this->GetPlaybackTick(this),
                                   !v3->OverrideView(this: g_pDemoUI, a2: info, a3: v4)) )
  {
    if ( g_pDemoUI2 == nullptr
      || (v6 = g_pDemoUI2->__vftable,
          v7 = this->GetPlaybackTick(this),
          !v6->OverrideView(this: g_pDemoUI2, a2: info, a3: v7)) )
    {
      if ( demoaction == nullptr )
        return false;
      v8 = demoaction->__vftable;
      v9 = this->GetPlaybackTick(this);
      if ( !v8->OverrideView(this: demoaction, a2: info, a3: v9) )
        return false;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10071970
// Name: public: virtual void CDemoPlayer::ResetDemoInterpolation(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDemoPlayer::ResetDemoInterpolation(CDemoPlayer *this)
{
  this->m_bResetInterpolation = true;
}

//------------------------------------------------------------------------------
// Address: 0x10071980
// Name: public: void bf_write::WriteUBitLong(unsigned int,int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall bf_write::WriteUBitLong(bf_write *this, unsigned int curData, int numbits, bool bCheckRange)
{
  int m_iCurBit; // ecx
  int m_nDataBits; // eax
  int v7; // edx
  int v8; // ecx
  int v9; // edx

  m_iCurBit = this->m_iCurBit;
  m_nDataBits = this->m_nDataBits;
  if ( m_iCurBit + numbits <= m_nDataBits )
  {
    v7 = m_iCurBit;
    v8 = m_iCurBit & 0x1F;
    v9 = v7 >> 5;
    *(_DWORD *)&this->m_pData[4 * v9] = (curData << v8)
                                      | *(_DWORD *)&this->m_pData[4 * v9] & g_BitWriteMasks[0][32 * v8 + v8 + numbits];
    if ( 32 - v8 < numbits )
      *(_DWORD *)&this->m_pData[4 * v9 + 4] = (curData >> (32 - v8))
                                            | *(_DWORD *)&this->m_pData[4 * v9 + 4]
                                            & g_BitWriteMasks[0][numbits - (32 - v8)];
    this->m_iCurBit += numbits;
  }
  else
  {
    this->m_iCurBit = m_nDataBits;
    this->m_bOverflow = true;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10071A10
// Name: public: void democmdinfo_t::Reset(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall democmdinfo_t::Reset(democmdinfo_t *this)
{
  this->u[0].flags = 0;
  this->u[0].viewOrigin2 = this->u[0].viewOrigin;
  this->u[0].viewAngles2 = this->u[0].viewAngles;
  this->u[0].localViewAngles2 = this->u[0].localViewAngles;
  this->u[1].flags = 0;
  this->u[1].viewOrigin2 = this->u[1].viewOrigin;
  this->u[1].viewAngles2 = this->u[1].viewAngles;
  this->u[1].localViewAngles2 = this->u[1].localViewAngles;
}

//------------------------------------------------------------------------------
// Address: 0x10071AA0
// Name: public: struct democmdinfo_t __near & democmdinfo_t::operator=(struct democmdinfo_t const __near &)
// Source: json
//------------------------------------------------------------------------------
democmdinfo_t *__thiscall democmdinfo_t::operator=(democmdinfo_t *this, const democmdinfo_t *__that)
{
  democmdinfo_t *result; // eax

  result = this;
  if ( this != __that )
    this->u[0] = __that->u[0];
  if ( &this->u[1] != &__that->u[1] )
    this->u[1] = __that->u[1];
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10071BD0
// Name: public: virtual int CDemoRecorder::GetRecordingTick(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDemoRecorder::GetRecordingTick(CDemoRecorder *this)
{
  if ( GetBaseLocalClient()->m_nMaxClients <= 1 )
    return GetBaseLocalClient()->m_ClockDriftMgr.m_nClientTick - this->m_nStartTick;
  else
    return (int)(net_time / host_state.interval_per_tick + 0.5) - this->m_nStartTick;
}

//------------------------------------------------------------------------------
// Address: 0x10071C20
// Name: protected: void CDemoRecorder::ResyncDemoClock(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDemoRecorder::ResyncDemoClock(CDemoRecorder *this)
{
  if ( GetBaseLocalClient()->m_nMaxClients <= 1 )
    this->m_nStartTick = GetBaseLocalClient()->m_ClockDriftMgr.m_nClientTick;
  else
    this->m_nStartTick = (int)(net_time / host_state.interval_per_tick + 0.5);
}

//------------------------------------------------------------------------------
// Address: 0x10071C70
// Name: protected: void CDemoRecorder::GetClientCmdInfo(struct democmdinfo_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDemoRecorder::GetClientCmdInfo(CDemoRecorder *this, democmdinfo_t *cmdInfo)
{
  int v2; // edi
  float *p_z; // esi

  v2 = 0;
  if ( host_state.max_splitscreen_players > 0 )
  {
    p_z = &cmdInfo->u[0].viewAngles.z;
    do
    {
      *(p_z - 6) = 0.0;
      if ( this->m_bResetInterpolation )
      {
        *((_DWORD *)p_z - 6) = 4;
        this->m_bResetInterpolation = false;
      }
      g_pClientSidePrediction->GetViewOrigin(this: g_pClientSidePrediction, a2: (Vector *)(p_z - 5));
      *(QAngle *)(p_z - 2) = GetLocalClient(nSlot: -1)->viewangles;
      g_pClientSidePrediction->GetLocalViewAngles(this: g_pClientSidePrediction, a2: (QAngle *)(p_z + 1));
      p_z[4] = 0.0;
      p_z[5] = 0.0;
      p_z[6] = 0.0;
      p_z[7] = 0.0;
      p_z[8] = 0.0;
      p_z[9] = 0.0;
      p_z[10] = 0.0;
      p_z[11] = 0.0;
      p_z[12] = 0.0;
      ++v2;
      p_z += 19;
    }
    while ( v2 < host_state.max_splitscreen_players );
  }
  this->m_bResetInterpolation = false;
}

//------------------------------------------------------------------------------
// Address: 0x10071D50
// Name: public: virtual void CDemoRecorder::RecordUserInput(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDemoRecorder::RecordUserInput(CDemoRecorder *this, int cmdnumber)
{
  int v3; // esi
  int v4; // eax
  char buffer[256]; // [esp+4h] [ebp-11Ch] BYREF
  bf_write msg; // [esp+104h] [ebp-1Ch] BYREF
  CDemoFile *p_m_DemoFile; // [esp+11Ch] [ebp-4h]

  p_m_DemoFile = &this->m_DemoFile;
  if ( CDemoFile::IsOpen(this: &this->m_DemoFile) )
  {
    bf_write::bf_write(this: &msg, pDebugName: "CDemo::WriteUserCmd", pData: buffer, nBytes: 256, nBits: -1);
    ((void (__thiscall *)(IBaseClientDLL *, _DWORD, bf_write *))g_ClientDLL->EncodeUserCmdToBuffer)(
      a1: g_ClientDLL,
      a2: 0,
      a3: &msg);
    v3 = (msg.m_iCurBit + 7) >> 3;
    v4 = ((int (__thiscall *)(CDemoRecorder *, _DWORD))this->GetRecordingTick)(a1: this, a2: 0);
    CDemoFile::WriteUserCmd(this: p_m_DemoFile, cmdnumber, buffer, bytes: v3, tick: v4, nPlayerSlot: cmdnumber);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10071EE0
// Name: public: virtual void CDemoRecorder::RecordCommand(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDemoRecorder::RecordCommand(CDemoRecorder *this, const char *cmdstring)
{
  int v3; // eax

  if ( this->IsRecording(this)
    && cmdstring != nullptr
    && *cmdstring != 0
    && demo_recordcommands.m_pParent != nullptr
    && demo_recordcommands.m_pParent->m_Value.m_nValue != 0 )
  {
    v3 = this->GetRecordingTick(this);
    CDemoFile::WriteConsoleCommand(this: &this->m_DemoFile, cmdstring, tick: v3, nPlayerSlot: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10071F30
// Name: protected: void CDemoRecorder::CloseDemoFile(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDemoRecorder::CloseDemoFile(CDemoRecorder *this)
{
  int v2; // eax
  float v3; // xmm0_4
  int m_nFrameCount; // eax
  int Size; // eax
  unsigned __int8 *m_pData; // eax

  if ( CDemoFile::IsOpen(this: &this->m_DemoFile) )
  {
    if ( !this->m_bIsDemoHeader )
    {
      v2 = this->GetRecordingTick(this);
      CDemoFile::WriteCmdHeader(this: &this->m_DemoFile, cmd: 7u, tick: v2, nPlayerSlot: 0);
      this->m_DemoFile.m_DemoHeader.playback_ticks = this->GetRecordingTick(this);
      v3 = (float)this->GetRecordingTick(this) * host_state.interval_per_tick;
      m_nFrameCount = this->m_nFrameCount;
      this->m_DemoFile.m_DemoHeader.playback_time = v3;
      this->m_DemoFile.m_DemoHeader.playback_frames = m_nFrameCount;
      CDemoFile::WriteDemoHeader(this: &this->m_DemoFile);
      ConMsg(
        a1: "Completed demo, recording time %.1f, game frames %i.\n",
        this->m_DemoFile.m_DemoHeader.playback_time,
        this->m_DemoFile.m_DemoHeader.playback_frames);
    }
    if ( demo_debug.m_pParent != nullptr && demo_debug.m_pParent->m_Value.m_nValue != 0 )
    {
      Size = CDemoFile::GetSize(this: &this->m_DemoFile);
      ConMsg(a1: "Closed demo file, %i bytes.\n", Size);
    }
    CDemoFile::Close(this: &this->m_DemoFile);
  }
  m_pData = this->m_MessageData.m_pData;
  *(_WORD *)&this->m_bIsDemoHeader = 0;
  if ( m_pData != nullptr )
  {
    free(pMem: m_pData);
    bf_write::StartWriting(this: &this->m_MessageData, pData: nullptr, nBytes: 0, iStartBit: 0, nBits: -1);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10072030
// Name: public: virtual void CDemoRecorder::RecordMessages(class bf_read __near &,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDemoRecorder::RecordMessages(CDemoRecorder *this, bf_read *data, int bits)
{
  bf_write *p_m_MessageData; // ecx

  p_m_MessageData = &this->m_MessageData;
  if ( p_m_MessageData->m_pData != nullptr && bits > 0 )
    bf_write::WriteBitsFromBuffer(this: p_m_MessageData, pIn: data, nBits: bits);
}

//------------------------------------------------------------------------------
// Address: 0x10072060
// Name: public: virtual void CDemoRecorder::StopRecording(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDemoRecorder::StopRecording(CDemoRecorder *this)
{
  unsigned __int8 *m_pData; // eax
  int v3; // ecx
  double v4; // st7
  float fSetting; // xmm0_4
  float v6; // [esp+8h] [ebp-4h]

  if ( this->IsRecording(this) )
  {
    m_pData = this->m_MessageData.m_pData;
    if ( m_pData != nullptr )
    {
      free(pMem: m_pData);
      bf_write::StartWriting(this: &this->m_MessageData, pData: nullptr, nBytes: 0, iStartBit: 0, nBits: -1);
    }
    CDemoRecorder::CloseDemoFile(this);
    this->m_bRecording = false;
    this->m_nDemoNumber = 0;
    if ( !g_DemoOverlay.m_bTick )
    {
      g_DemoOverlay.m_bTick = true;
      v4 = _Plat_FloatTime(a1: v3);
      if ( g_DemoOverlay.m_fLastTickTime != v4 )
      {
        g_DemoOverlay.m_fLastTickTime = v4;
        fSetting = cl_showdemooverlay.m_pParent->m_Value.m_fValue;
        if ( fSetting <= 0.0 || (float)((v6 = v4) - g_DemoOverlay.m_fLastTickOverlay) >= fSetting )
        {
          g_DemoOverlay.m_fLastTickOverlay = v4;
          DemoOverlay::DrawOverlay(this: &g_DemoOverlay, fSetting);
        }
      }
      g_DemoOverlay.m_bTick = false;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10072140
// Name: public: virtual void CDemoRecorder::StartRecording(char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDemoRecorder::StartRecording(CDemoRecorder *this, const char *name, bool bContinuously)
{
  int v4; // ecx
  double v5; // st7
  float fSetting; // xmm0_4
  CClientState *BaseLocalClient; // eax
  float namea; // [esp+Ch] [ebp+8h]

  V_strncpy(pDest: this->m_szDemoBaseName, pSrc: name, maxLen: 260);
  this->m_bRecording = true;
  this->m_nDemoNumber = 1;
  this->m_bResetInterpolation = false;
  if ( !g_DemoOverlay.m_bTick )
  {
    g_DemoOverlay.m_bTick = true;
    v5 = _Plat_FloatTime(a1: v4);
    if ( g_DemoOverlay.m_fLastTickTime != v5 )
    {
      g_DemoOverlay.m_fLastTickTime = v5;
      fSetting = cl_showdemooverlay.m_pParent->m_Value.m_fValue;
      if ( fSetting <= 0.0 || (float)((namea = v5) - g_DemoOverlay.m_fLastTickOverlay) >= fSetting )
      {
        g_DemoOverlay.m_fLastTickOverlay = v5;
        DemoOverlay::DrawOverlay(this: &g_DemoOverlay, fSetting);
      }
    }
    g_DemoOverlay.m_bTick = false;
  }
  BaseLocalClient = GetBaseLocalClient();
  CBaseClientState::ForceFullUpdate(this: BaseLocalClient, pchReason: "recording demo");
}

//------------------------------------------------------------------------------
// Address: 0x100722A0
// Name: public: virtual bool CDemoPlayer::StartPlayback(char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDemoPlayer::StartPlayback(CDemoPlayer *this, const char *filename, bool bAsTimeDemo)
{
  int demonum; // edi
  int v6; // ecx
  CClientState *BaseLocalClient; // eax
  CNetChan *NetChannel; // ebx
  CClientState *v9; // eax

  SCR_BeginLoadingPlaque(levelName: nullptr);
  demonum = GetBaseLocalClient()->demonum;
  GetBaseLocalClient()->demonum = -1;
  Host_Disconnect(bShowMainMenu: false);
  GetBaseLocalClient()->demonum = demonum;
  if ( !CDemoFile::Open(this: &this->m_DemoFile, name: filename, bReadOnly: true, bMemoryBuffer: false) )
    goto LABEL_4;
  if ( CDemoFile::ReadDemoHeader(this: &this->m_DemoFile) == nullptr )
  {
    ConMsg(a1: "Failed to read demo header.\n");
    CDemoFile::Close(this: &this->m_DemoFile);
LABEL_4:
    GetBaseLocalClient()->demonum = -1;
    return 0;
  }
  ConMsg(a1: "Playing demo from %s.\n", filename);
  this->m_bPlayingBack = true;
  GetBaseLocalClient()->m_nSignonState = 2;
  v6 = host_tickcount;
  this->m_nStartTick = host_tickcount;
  this->m_nPreviousTick = v6;
  BaseLocalClient = GetBaseLocalClient();
  NetChannel = NET_CreateNetChannel(
                 socket: 0,
                 adr: nullptr,
                 name: "DEMO",
                 handler: BaseLocalClient,
                 bForceNewChannel: false);
  GetBaseLocalClient()->m_NetChannel = NetChannel;
  if ( GetBaseLocalClient()->m_NetChannel == nullptr )
  {
    ConMsg(a1: "CDemo::Play: failed to create demo net channel\n");
    CDemoFile::Close(this: &this->m_DemoFile);
    GetBaseLocalClient()->demonum = -1;
    Host_Disconnect(bShowMainMenu: true);
  }
  v9 = GetBaseLocalClient();
  ((void (__thiscall *)(INetChannel *, _DWORD, _DWORD))v9->m_NetChannel->SetTimeout)(
    a1: v9->m_NetChannel,
    a2: -1.0,
    a3: 0);
  _V_memset(dest: &this->m_DemoPacket, fill: 0, count: 80);
  this->m_DemoPacket.data = (unsigned __int8 *)MemAlloc_Alloc(nSize: 0x17700u);
  netadr_s::SetType(this: &this->m_DemoPacket.from, newtype: NA_LOOPBACK);
  GetBaseLocalClient()->chokedcommands = 0;
  GetBaseLocalClient()->lastoutgoingcommand = -1;
  GetBaseLocalClient()->m_flNextCmdTime = net_time;
  this->m_bTimeDemo = bAsTimeDemo;
  this->m_nTimeDemoCurrentFrame = -1;
  this->m_nTimeDemoStartFrame = -1;
  if ( bAsTimeDemo )
    SeedRandomNumberGenerator(random_invariant: true);
  demoaction->StartPlaying(this: demoaction, a2: filename);
  this->m_flAutoResumeTime = 0.0;
  this->m_flPlaybackRateModifier = 1.0;
  scr_demo_override_fov = 0.0;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100724A0
// Name: public: bool CDemoPlayer::CheckPausedPlayback(void)
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
bool __thiscall CDemoPlayer::CheckPausedPlayback(CDemoPlayer *this)
{
  int m_nServerTick; // eax
  int v3; // ecx
  CClientState *BaseLocalClient; // eax
  int m_nSkipToTick; // edi
  int v6; // ecx

  if ( demo_pauseatservertick.m_pParent != nullptr && demo_pauseatservertick.m_pParent->m_Value.m_nValue > 0 )
  {
    m_nServerTick = GetBaseLocalClient()->m_ClockDriftMgr.m_nServerTick;
    v3 = demo_pauseatservertick.m_pParent != nullptr ? demo_pauseatservertick.m_pParent->m_Value.m_nValue : 0;
    if ( m_nServerTick >= v3 )
    {
      ((void (__thiscall *)(CDemoPlayer *, _DWORD))this->PausePlayback)(a1: this, a2: -1.0);
      this->m_nSkipToTick = -1;
      CLoaderMemAlloc::CrtIsValidPointer(this: (ConVar *)&demo_pauseatservertick.IConVar, value: 0);
      BaseLocalClient = GetBaseLocalClient();
      _Msg(a1: "Demo paused at server tick %i\n", BaseLocalClient->m_ClockDriftMgr.m_nServerTick);
    }
  }
  if ( this->IsSkipping(this) )
  {
    m_nSkipToTick = this->m_nSkipToTick;
    if ( m_nSkipToTick > this->GetPlaybackTick(this) || (m_nSkipToTick & 0x88000000) == 0x88000000 )
      return false;
    this->m_nSkipToTick = -1;
  }
  if ( !this->IsPlaybackPaused(this) )
    return false;
  if ( this->m_bPlaybackPaused && this->m_flAutoResumeTime > 0.0 && _Plat_FloatTime(a1: v6) >= this->m_flAutoResumeTime )
    this->ResumePlayback(this);
  return this->m_bPlaybackPaused;
}

//------------------------------------------------------------------------------
// Address: 0x100725A0
// Name: void CL_ListDemo_f(class CCommand const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CL_ListDemo_f(const CCommand *args)
{
  const char *v1; // eax
  CDemoFile demofile; // [esp+Ch] [ebp-63Ch] BYREF
  char name[260]; // [esp+544h] [ebp-104h] BYREF

  if ( cmd_source == src_command )
  {
    if ( args->m_nArgc > 1 )
      v1 = args->m_ppArgv[1];
    else
      v1 = defaultValue;
    V_snprintf(pDest: name, maxLen: 260, pFormat: "%s", v1);
    V_DefaultExtension(path: name, extension: ".dem", pathStringLength: 260);
    ConMsg(a1: "Demo contents for %s:\n", name);
    CDemoFile::CDemoFile(this: &demofile);
    if ( CDemoFile::Open(this: &demofile, name, bReadOnly: true, bMemoryBuffer: false) )
    {
      CDemoFile::ReadDemoHeader(this: &demofile);
      if ( _V_strcmp(s1: demofile.m_DemoHeader.demofilestamp, s2: "HL2DEMO") != 0 )
      {
        ConMsg(a1: "%s is not a valid demo file\n", name);
      }
      else
      {
        ConMsg(a1: "Network protocol: %i\n", demofile.m_DemoHeader.networkprotocol);
        ConMsg(a1: "Demo version    : %i\n", demofile.m_DemoHeader.demoprotocol);
        ConMsg(a1: "Server name     : %s\n", demofile.m_DemoHeader.servername);
        ConMsg(a1: "Map name        : %s\n", demofile.m_DemoHeader.mapname);
        ConMsg(a1: "Game            : %s\n", demofile.m_DemoHeader.gamedirectory);
        ConMsg(a1: "Player name     : %s\n", demofile.m_DemoHeader.clientname);
        ConMsg(a1: "Time            : %.1f\n", demofile.m_DemoHeader.playback_time);
        ConMsg(a1: "Ticks           : %i\n", demofile.m_DemoHeader.playback_ticks);
        ConMsg(a1: "Frames          : %i\n", demofile.m_DemoHeader.playback_frames);
        ConMsg(a1: "Signon size     : %i\n", demofile.m_DemoHeader.signonlength);
      }
      CDemoFile::~CDemoFile(this: &demofile);
    }
    else
    {
      ConMsg(a1: "ERROR: couldn't open.\n");
      CDemoFile::~CDemoFile(this: &demofile);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10072740
// Name: record
// Source: json
//------------------------------------------------------------------------------
void __cdecl record(const CCommand *args)
{
  int m_nArgc; // eax
  bool incremental; // [esp+Ch] [ebp+8h]

  m_nArgc = args->m_nArgc;
  if ( args->m_nArgc == 2 || m_nArgc == 3 )
  {
    incremental = false;
    if ( m_nArgc == 3 )
      incremental = _V_stricmp(s1: args->m_ppArgv[2], s2: "incremental") == 0;
    if ( args->m_nArgc > 1 )
      DemoRecord(pchDemoFileName: args->m_ppArgv[1], incremental);
    else
      DemoRecord(pchDemoFileName: defaultValue, incremental);
  }
  else
  {
    ConMsg(a1: "record <demoname> [incremental]\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x100727C0
// Name: _record
// Source: json
//------------------------------------------------------------------------------
void __cdecl record(const CCommand *args)
{
  if ( g_ClientDLL != nullptr )
  {
    if ( args->m_nArgc == 2 )
      DemoRecord(pchDemoFileName: args->m_ppArgv[1], incremental: true);
    else
      ConMsg(a1: "_record <demoname>\n");
  }
  else
  {
    ConMsg(a1: "Can't record on dedicated server.\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x10072810
// Name: void CL_PlayDemo_f(class CCommand const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CL_PlayDemo_f(const CCommand *args)
{
  const char *v1; // eax
  char basename[260]; // [esp+0h] [ebp-208h] BYREF
  char name[260]; // [esp+104h] [ebp-104h] BYREF

  if ( cmd_source == src_command )
  {
    if ( args->m_nArgc == 2 )
    {
      demoplayer = g_pClientDemoPlayer;
      if ( args->m_nArgc > 1 )
        v1 = args->m_ppArgv[1];
      else
        v1 = defaultValue;
      V_strncpy(pDest: name, pSrc: v1, maxLen: 260);
      V_DefaultExtension(path: name, extension: ".dem", pathStringLength: 260);
      if ( demoplayer->StartPlayback(this: demoplayer, a2: name, a3: false) )
      {
        V_StripExtension(in: name, out: basename, outSize: 260);
        g_ClientDLL->OnDemoPlaybackStart(this: g_ClientDLL, a2: basename);
      }
      else
      {
        SCR_EndLoadingPlaque();
      }
    }
    else
    {
      ConMsg(a1: "playdemo <demoname> : plays a demo file\n");
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100728F0
// Name: void CL_TimeDemo_f(class CCommand const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CL_TimeDemo_f(const CCommand *args)
{
  int m_nArgc; // eax
  const char *v2; // ecx
  bool v3; // cc
  const char *v4; // eax

  if ( cmd_source == src_command )
  {
    m_nArgc = args->m_nArgc;
    if ( args->m_nArgc < 2 || m_nArgc > 3 )
    {
      ConMsg(a1: "timedemo <demoname> <optional stats.txt> : gets demo speeds, writing perf resutls to the optional stats.txt\n");
    }
    else
    {
      if ( m_nArgc < 3 )
        v2 = nullptr;
      else
        v2 = args->m_ppArgv[2];
      v3 = m_nArgc <= 1;
      v4 = defaultValue;
      if ( !v3 )
        v4 = args->m_ppArgv[1];
      CL_TimeDemo_Helper(pDemoName: v4, pStatsFileName: v2, pVProfStatsFileName: nullptr);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10072950
// Name: void CL_TimeDemo_VProfRecord_f(class CCommand const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CL_TimeDemo_VProfRecord_f(const CCommand *args)
{
  if ( cmd_source == src_command )
  {
    if ( args->m_nArgc == 3 )
      CL_TimeDemo_Helper(pDemoName: args->m_ppArgv[1], pStatsFileName: nullptr, pVProfStatsFileName: args->m_ppArgv[2]);
    else
      ConMsg(
        a1: "timedemo_vprofrecord <demoname> <vprof stats filename> : gets demo speeds, recording perf data to a vprof stats file\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x10072990
// Name: void CL_TimeDemoQuit_f(class CCommand const __near &)
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __cdecl CL_TimeDemoQuit_f(const CCommand *args)
{
  CLoaderMemAlloc::CrtIsValidPointer(this: (ConVar *)&demo_quitafterplayback.IConVar, value: 1);
  CL_TimeDemo_f(args);
}

//------------------------------------------------------------------------------
// Address: 0x100729B0
// Name: void CL_BenchFrame_f(class CCommand const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CL_BenchFrame_f(const CCommand *args)
{
  int v1; // eax
  const char *v2; // eax
  const char *v3; // ecx
  CDemoPlayer *v4; // edx
  const char *v5; // eax
  bool (__thiscall *StartPlayback)(IDemoPlayer *, const char *, bool); // eax
  char name[260]; // [esp+0h] [ebp-104h] BYREF

  if ( cmd_source == src_command )
  {
    if ( args->m_nArgc == 4 )
    {
      if ( atoi(nptr: args->m_ppArgv[2]) >= 0 )
      {
        v2 = defaultValue;
        if ( args->m_nArgc > 2 )
          v2 = args->m_ppArgv[2];
        v1 = atoi(nptr: v2);
      }
      else
      {
        v1 = 0;
      }
      v3 = defaultValue;
      if ( args->m_nArgc > 3 )
        v3 = args->m_ppArgv[3];
      v4 = g_pClientDemoPlayer;
      g_pClientDemoPlayer->m_nSnapshotTick = v1;
      if ( v3 != nullptr )
        V_strncpy(pDest: v4->m_SnapshotFilename, pSrc: v3, maxLen: 260);
      s_bBenchframe = true;
      CLoaderMemAlloc::CrtIsValidPointer(this: (ConVar *)&mat_norendering.IConVar, value: 1);
      demoplayer = g_pClientDemoPlayer;
      v5 = defaultValue;
      if ( args->m_nArgc > 1 )
        v5 = args->m_ppArgv[1];
      V_strncpy(pDest: name, pSrc: v5, maxLen: 260);
      V_DefaultExtension(path: name, extension: ".dem", pathStringLength: 260);
      StartPlayback = demoplayer->StartPlayback;
      *(_DWORD *)name = 1;
      if ( ((unsigned __int8 (__thiscall *)(IDemoPlayer *, char *))StartPlayback)(a1: demoplayer, a2: name) == 0 )
        SCR_EndLoadingPlaque();
    }
    else
    {
      ConMsg(a1: "benchframe <demoname> <frame> <tgafilename>: takes a snapshot of a particular frame in a demo\n");
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10072AD0
// Name: vtune_0
// Source: json
//------------------------------------------------------------------------------
void __cdecl vtune_0(const CCommand *args)
{
  const char *v1; // esi

  if ( args->m_nArgc == 2 )
  {
    if ( V_strcasecmp(s1: args->m_ppArgv[1], s2: "pause") != 0 )
    {
      if ( args->m_nArgc > 1 )
        v1 = args->m_ppArgv[1];
      else
        v1 = defaultValue;
      if ( V_strcasecmp(s1: v1, s2: "resume") != 0 )
      {
        ConMsg(a1: "Unknown vtune option.\n");
      }
      else if ( (unsigned __int8)_vtune(a1: 1) != 0 )
      {
        ConMsg(a1: "VTune sampling resumed.\n");
      }
      else
      {
        ConMsg(a1: "Failed to find \"VTResume()\" in \"vtuneapi.dll\".\n");
      }
    }
    else if ( (unsigned __int8)_vtune(a1: 0) != 0 )
    {
      ConMsg(a1: "VTune sampling paused.\n");
    }
    else
    {
      ConMsg(a1: "Failed to find \"VTPause()\" in \"vtuneapi.dll\".\n");
    }
  }
  else
  {
    ConMsg(a1: "vtune \"pause\" | \"resume\" : Suspend or resume VTune's sampling.\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x10072BA0
// Name: demo_pause
// Source: json
//------------------------------------------------------------------------------
void __cdecl demo_pause(const CCommand *args)
{
  long double v1; // st7
  float v2; // [esp+0h] [ebp-8h]

  if ( args->m_nArgc == 2 )
    v1 = atof(nptr: args->m_ppArgv[1]);
  else
    v1 = -1.0;
  v2 = v1;
  ((void (__stdcall *)(_DWORD))demoplayer->PausePlayback)(a1: LODWORD(v2));
}

//------------------------------------------------------------------------------
// Address: 0x10072BF0
// Name: demo_gototick
// Source: json
//------------------------------------------------------------------------------
void __cdecl demo_gototick(const CCommand *args)
{
  const char *v1; // eax
  int v2; // edi
  const char *v3; // eax
  const char *v4; // esi
  bool bRelative; // [esp+4h] [ebp-8h]
  bool bPause; // [esp+8h] [ebp-4h]

  bRelative = false;
  bPause = false;
  if ( args->m_nArgc >= 2 )
  {
    v1 = defaultValue;
    if ( args->m_nArgc > 1 )
      v1 = args->m_ppArgv[1];
    v2 = atoi(nptr: v1);
    if ( args->m_nArgc >= 3 )
    {
      v3 = defaultValue;
      if ( args->m_nArgc > 2 )
        v3 = args->m_ppArgv[2];
      bRelative = V_atoi(str: v3) != 0;
    }
    if ( args->m_nArgc >= 4 )
    {
      if ( args->m_nArgc > 3 )
        v4 = args->m_ppArgv[3];
      else
        v4 = defaultValue;
      bPause = V_atoi(str: v4) != 0;
    }
    demoplayer->SkipToTick(this: demoplayer, a2: v2, a3: bRelative, a4: bPause);
  }
  else
  {
    _Msg(a1: "Syntax: demo_gototick <tick> [relative] [pause]\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x10072CB0
// Name: demo_timescale
// Source: json
//------------------------------------------------------------------------------
void __cdecl demo_timescale(const CCommand *args)
{
  long double v1; // st7
  float v2; // xmm0_4
  int fScale; // [esp+4h] [ebp-4h]
  float fScalea; // [esp+4h] [ebp-4h]

  fScale = 1065353216;
  if ( args->m_nArgc == 2 )
  {
    v1 = atof(nptr: args->m_ppArgv[1]);
    if ( v1 >= 0.0 )
    {
      v2 = v1;
      fScalea = v1;
      if ( fScalea > 100.0 )
        v2 = 100.0;
    }
    else
    {
      v2 = 0.0;
    }
    fScale = LODWORD(v2);
  }
  ((void (__stdcall *)(int))demoplayer->SetPlaybackTimeScale)(a1: fScale);
}

//------------------------------------------------------------------------------
// Address: 0x10072D20
// Name: public: char const __near * CFmtStrN<256>::sprintf(char const __near *,...)
// Source: json
//------------------------------------------------------------------------------
char *CFmtStrN<256>::sprintf(CFmtStrN<256> *this, const char *pszFormat, ...)
{
  CFmtStrN<256> *v2; // esi
  bool v3; // zf
  va_list params; // [esp+18h] [ebp+10h] BYREF

  va_start(params, pszFormat);
  v2 = this;
  this->InitQuietTruncation(this);
  HIBYTE(this) = 0;
  V_vsnprintfRet(pDest: v2->m_szBuf, maxLen: 255, pFormat: pszFormat, params, pbTruncated: (bool *)&this + 3);
  v3 = HIBYTE(this) == 0;
  v2->m_szBuf[255] = 0;
  if ( !v3 && !v2->m_bQuietTruncation && `CFmtStrN<256>::sprintf'::`4'::scAsserted < 5 )
    ++`CFmtStrN<256>::sprintf'::`4'::scAsserted;
  v2->m_nLength = _V_strlen(str: v2->m_szBuf);
  return v2->m_szBuf;
}

//------------------------------------------------------------------------------
// Address: 0x10072E30
// Name: public: democmdinfo_t::democmdinfo_t(void)
// Source: json
//------------------------------------------------------------------------------
democmdinfo_t *__thiscall democmdinfo_t::democmdinfo_t(democmdinfo_t *this)
{
  democmdinfo_t *result; // eax
  int v2; // esi
  float *p_z; // edx

  result = this;
  v2 = 1;
  p_z = &this->u[0].viewOrigin.z;
  do
  {
    *(p_z - 3) = 0.0;
    *(p_z - 2) = 0.0;
    *(p_z - 1) = 0.0;
    *p_z = 0.0;
    p_z[1] = 0.0;
    p_z[2] = 0.0;
    p_z[3] = 0.0;
    p_z[4] = 0.0;
    p_z[5] = 0.0;
    p_z[6] = 0.0;
    p_z[7] = 0.0;
    p_z[8] = 0.0;
    p_z[9] = 0.0;
    p_z[10] = 0.0;
    p_z[11] = 0.0;
    p_z[12] = 0.0;
    p_z[13] = 0.0;
    p_z[14] = 0.0;
    p_z[15] = 0.0;
    p_z += 19;
    --v2;
  }
  while ( v2 >= 0 );
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10072EB0
// Name: public: DemoCommandQueue::DemoCommandQueue(void)
// Source: json
//------------------------------------------------------------------------------
DemoCommandQueue *__thiscall DemoCommandQueue::DemoCommandQueue(DemoCommandQueue *this)
{
  DemoCommandQueue *result; // eax
  democmdinfo_t *p_info; // esi
  int v3; // edi
  float *p_z; // edx

  result = this;
  p_info = &this->info;
  v3 = 1;
  p_z = &this->info.u[0].viewOrigin.z;
  do
  {
    p_info->u[0].flags = 0;
    *(p_z - 2) = 0.0;
    *(p_z - 1) = 0.0;
    *p_z = 0.0;
    p_z[1] = 0.0;
    p_z[2] = 0.0;
    p_z[3] = 0.0;
    p_z[4] = 0.0;
    p_z[5] = 0.0;
    p_z[6] = 0.0;
    p_z[7] = 0.0;
    p_z[8] = 0.0;
    p_z[9] = 0.0;
    p_z[10] = 0.0;
    p_z[11] = 0.0;
    p_z[12] = 0.0;
    p_z[13] = 0.0;
    p_z[14] = 0.0;
    p_z[15] = 0.0;
    p_info = (democmdinfo_t *)((char *)p_info + 76);
    p_z += 19;
    --v3;
  }
  while ( v3 >= 0 );
  this->tick = 0;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10072F50
// Name: protected: void CDemoRecorder::StartupDemoHeader(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDemoRecorder::StartupDemoHeader(CDemoRecorder *this)
{
  void *v2; // eax

  CDemoRecorder::CloseDemoFile(this);
  if ( CDemoFile::Open(this: &this->m_DemoFile, name: "demoheader.tmp", bReadOnly: false, bMemoryBuffer: false) )
  {
    this->m_bIsDemoHeader = true;
    v2 = MemAlloc_Alloc(nSize: 0x17700u);
    bf_write::StartWriting(this: &this->m_MessageData, pData: v2, nBytes: 96000, iStartBit: 0, nBits: -1);
    CNetworkStringTable::SetTick(this: &this->m_MessageData, pDebugName: "DemoHeaderWriteBuffer");
  }
  else
  {
    _ConDMsg(a1: "ERROR: couldn't open temporary header file.\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x10072FC0
// Name: protected: void CDemoRecorder::WriteMessages(class bf_write __near &)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CDemoRecorder::WriteMessages(CDemoRecorder *this@<ecx>, int a2@<ebx>, bf_write *message)
{
  int m_iCurBit; // eax
  int v5; // ebx
  int v6; // eax
  CClientState *BaseLocalClient; // eax
  unsigned int CurPos; // eax
  democmdinfo_t info; // [esp+8h] [ebp-A8h] BYREF
  int nOutSequenceNr; // [esp+A0h] [ebp-10h] BYREF
  int nOutSequenceNrAck; // [esp+A4h] [ebp-Ch]
  int cmd; // [esp+A8h] [ebp-8h]
  int nInSequenceNr; // [esp+ACh] [ebp-4h] BYREF

  if ( CDemoFile::IsOpen(this: &this->m_DemoFile) )
  {
    m_iCurBit = message->m_iCurBit;
    v5 = (m_iCurBit + 7) >> 3;
    if ( v5 > 0 )
    {
      if ( (unsigned int)(m_iCurBit % 8 - 1) <= 1 )
        bf_write::WriteUBitLong(this: message, curData: 0, numbits: 6, bCheckRange: true);
      LOBYTE(cmd) = !this->m_bIsDemoHeader + 1;
      if ( (_BYTE)cmd == 2 )
        ++this->m_nFrameCount;
      v6 = ((int (__thiscall *)(CDemoRecorder *, _DWORD))this->GetRecordingTick)(a1: this, a2: 0);
      CDemoFile::WriteCmdHeader(this: &this->m_DemoFile, cmd, tick: v6, nPlayerSlot: a2);
      democmdinfo_t::democmdinfo_t(this: &info);
      CDemoRecorder::GetClientCmdInfo(this, cmdInfo: &info);
      CDemoFile::WriteCmdInfo(this: &this->m_DemoFile, &info);
      BaseLocalClient = GetBaseLocalClient();
      ((void (__thiscall *)(INetChannel *, int *, int *))BaseLocalClient->m_NetChannel->GetSequenceData)(
        a1: BaseLocalClient->m_NetChannel,
        a2: &nOutSequenceNr,
        a3: &nInSequenceNr);
      CDemoFile::WriteSequenceInfo(this: &this->m_DemoFile, nSeqNrIn: nInSequenceNr, nSeqNrOut: nOutSequenceNrAck);
      CDemoFile::WriteRawData(this: &this->m_DemoFile, buffer: (const char *)message->m_pData, length: v5);
      if ( demo_debug.m_pParent != nullptr && demo_debug.m_pParent->m_Value.m_nValue >= 1 )
      {
        CurPos = CDemoFile::GetCurPos(this: &this->m_DemoFile, bRead: false);
        _Msg(a1: "Writing demo message %i bytes at file pos %i\n", v5, CurPos);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100730E0
// Name: public: void CDemoPlayer::InterpolateDemoCommand(int,int,struct DemoCommandQueue __near &,struct DemoCommandQueue __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDemoPlayer::InterpolateDemoCommand(
        CDemoPlayer *this,
        int nSlot,
        int targettick,
        DemoCommandQueue *prev,
        DemoCommandQueue *next)
{
  int m_Size; // edi
  int v7; // edx
  DemoCommandQueue *m_pMemory; // ebx
  DemoCommandQueue *v9; // edi
  DemoCommandQueue *v10; // esi
  DemoCommandQueue *v11; // eax
  int c; // [esp+8h] [ebp-10h]
  int savedI; // [esp+10h] [ebp-8h]
  int i; // [esp+14h] [ebp-4h]

  m_Size = this->m_DestCmdInfo.m_Size;
  c = m_Size;
  democmdinfo_t::Reset(this: &prev->info);
  democmdinfo_t::Reset(this: &next->info);
  if ( m_Size >= 2 )
  {
    v7 = targettick;
    m_pMemory = this->m_DestCmdInfo.m_Memory.m_pMemory;
    i = 0;
    savedI = -1;
    v9 = m_pMemory;
    v10 = m_pMemory + 1;
    v11 = m_pMemory;
    while ( v9->tick > v7 || v10->tick <= v7 )
    {
      if ( savedI == -1 )
      {
        v7 = targettick;
        if ( v10->tick > this->m_nPreviousTick && v10->tick <= targettick && (v10->info.u[nSlot].flags & 4) != 0 )
          savedI = i;
      }
      if ( i + 2 == c )
        return;
      ++i;
      ++v11;
      ++v10;
      v9 = v11;
    }
    if ( savedI == -1 )
    {
      prev->tick = v9->tick;
      democmdinfo_t::operator=(this: &prev->info, __that: &v9->info);
      prev->filepos = v9->filepos;
    }
    else
    {
      prev->tick = m_pMemory[savedI].tick;
      democmdinfo_t::operator=(this: &prev->info, __that: &m_pMemory[savedI].info);
      prev->filepos = m_pMemory[savedI].filepos;
      v10 = &this->m_DestCmdInfo.m_Memory.m_pMemory[savedI + 1];
    }
    next->tick = v10->tick;
    democmdinfo_t::operator=(this: &next->info, __that: &v10->info);
    next->filepos = v10->filepos;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10073220
// Name: public: virtual void CDemoPlayer::InterpolateViewpoint(void)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
// bad sp value at call has been detected, the output may be wrong!
void __usercall CDemoPlayer::InterpolateViewpoint(CDemoPlayer *this@<ecx>, float a2@<ebp>, int a3@<edi>, int a4@<esi>)
{
  bool v5; // zf
  CClientState *BaseLocalClient; // eax
  int v7; // eax
  float v8; // xmm3_4
  float v9; // xmm0_4
  float *p_x; // eax
  float v11; // edx
  QAngle *p_localViewAngles; // eax
  float y; // edx
  Vector *p_viewOrigin2; // eax
  float v15; // xmm1_4
  float z; // xmm2_4
  float x; // xmm0_4
  Quaternion v18; // xmm4
  QAngle *p_viewAngles2; // eax
  float v20; // edx
  QAngle *p_viewAngles; // eax
  float v22; // ecx
  float v23; // edx
  float v24; // eax
  int i; // edi
  double v26; // st7
  long double v27; // st7
  long double v28; // st7
  Vector *p_viewOrigin; // eax
  Vector *v30; // eax
  QAngle *v31; // eax
  QAngle *v32; // eax
  Vector *v33; // eax
  int v34; // ecx
  int z_low; // xmm0_4
  QAngle *v36; // eax
  float v37; // xmm0_4
  QAngle *p_localViewAngles2; // eax
  bool v39; // al
  int v41; // [esp+10h] [ebp-244h] BYREF
  char v42; // [esp+14h] [ebp-240h] BYREF
  int v43; // [esp+18h] [ebp-23Ch] BYREF
  DemoCommandQueue next; // [esp+1Ch] [ebp-238h] BYREF
  DemoCommandQueue prev; // [esp+BCh] [ebp-198h] BYREF
  democmdinfo_t outinfo; // [esp+15Ch] [ebp-F8h] BYREF
  float v47; // [esp+1F4h] [ebp-60h]
  Quaternion destang; // [esp+1F8h] [ebp-5Ch] OVERLAPPED BYREF
  QAngle startang; // [esp+208h] [ebp-4Ch] BYREF
  float v50; // [esp+214h] [ebp-40h]
  float v51; // [esp+218h] [ebp-3Ch]
  float v52; // [esp+21Ch] [ebp-38h]
  Vector startorigin; // [esp+220h] [ebp-34h]
  Vector destorigin; // [esp+22Ch] [ebp-28h]
  float vel; // [esp+238h] [ebp-1Ch]
  float t; // [esp+23Ch] [ebp-18h]
  float angVel; // [esp+240h] [ebp-14h]
  char v58; // [esp+247h] [ebp-Dh]
  float aVel; // [esp+248h] [ebp-Ch]
  int nTargetTick; // [esp+24Ch] [ebp-8h]
  int retaddr; // [esp+254h] [ebp+0h]

  aVel = a2;
  nTargetTick = retaddr;
  if ( ((unsigned __int8 (__thiscall *)(CDemoPlayer *, int, int))this->IsPlayingBack)(a1: this, a2: a3, a3: a4) != 0 )
  {
    democmdinfo_t::democmdinfo_t(this: (democmdinfo_t *)&prev.info.u[1].localViewAngles2.y);
    democmdinfo_t::Reset(this: (democmdinfo_t *)&prev.info.u[1].localViewAngles2.y);
    if ( vec3_origin.x != this->m_LastCmdInfo.u[0].viewOrigin.x
      || vec3_origin.y != this->m_LastCmdInfo.u[0].viewOrigin.y
      || vec3_origin.z != this->m_LastCmdInfo.u[0].viewOrigin.z
      || vec3_angle.x != this->m_LastCmdInfo.u[0].viewAngles.x
      || vec3_angle.y != this->m_LastCmdInfo.u[0].viewAngles.y
      || vec3_angle.z != this->m_LastCmdInfo.u[0].viewAngles.z
      || vec3_angle.x != this->m_LastCmdInfo.u[0].localViewAngles.x
      || vec3_angle.y != this->m_LastCmdInfo.u[0].localViewAngles.y
      || vec3_angle.z != this->m_LastCmdInfo.u[0].localViewAngles.z
      || (v5 = this->m_LastCmdInfo.u[0].flags == 0, v58 = 0, !v5) )
    {
      v58 = 1;
    }
    angVel = COERCE_FLOAT(this->GetPlaybackTick(this));
    if ( GetBaseLocalClient()->m_nMaxClients == 1 )
    {
      if ( demo_legacy_rollback.m_pParent != nullptr && demo_legacy_rollback.m_pParent->m_Value.m_nValue != 0 )
      {
        BaseLocalClient = GetBaseLocalClient();
        v7 = (int)(CClientState::GetClientInterpAmount(this: BaseLocalClient) / host_state.interval_per_tick + 0.5);
        LODWORD(angVel) += -1 - v7;
      }
      else
      {
        --LODWORD(angVel);
      }
    }
    v5 = !this->m_bInterpolateView;
    destorigin.x = 0.0;
    destorigin.z = 0.0;
    if ( !v5 && demo_interpolateview.m_pParent != nullptr && demo_interpolateview.m_pParent->m_Value.m_nValue != 0 )
    {
      if ( v58 != 0 )
      {
        DemoCommandQueue::DemoCommandQueue(this: (DemoCommandQueue *)&next.info.u[1].localViewAngles2.y);
        DemoCommandQueue::DemoCommandQueue(this: (DemoCommandQueue *)&v41);
        democmdinfo_t::operator=(
          this: (democmdinfo_t *)&next.info.u[1].localViewAngles2.z,
          __that: &this->m_LastCmdInfo);
        next.info.u[1].localViewAngles2.y = NAN;
        democmdinfo_t::operator=(this: (democmdinfo_t *)&v42, __that: &this->m_LastCmdInfo);
        v41 = -1;
        CDemoPlayer::InterpolateDemoCommand(
          this,
          nSlot: 0,
          targettick: SLODWORD(angVel),
          prev: (DemoCommandQueue *)&next.info.u[1].localViewAngles2.y,
          next: (DemoCommandQueue *)&v41);
        t = (float)(v41 - LODWORD(next.info.u[1].localViewAngles2.y)) * host_state.interval_per_tick;
        destorigin.y = 1.0 / t;
        v8 = 0.0;
        v9 = (float)((float)((float)(LODWORD(angVel) - LODWORD(next.info.u[1].localViewAngles2.y))
                           * host_state.interval_per_tick)
                   + GetBaseLocalClient()->m_tickRemainder)
           * destorigin.y;
        if ( v9 >= 0.0 )
        {
          v8 = 1.0;
          if ( v9 <= 1.0 )
            v8 = v9;
        }
        vel = v8;
        p_x = &prev.info.u[0].localViewAngles.x;
        if ( (LOBYTE(next.info.u[1].localViewAngles2.z) & 1) == 0 )
          p_x = (float *)&next.filepos;
        v11 = *p_x;
        v51 = p_x[1];
        v50 = v11;
        v52 = p_x[2];
        p_localViewAngles = &next.info.u[0].localViewAngles;
        if ( (v42 & 1) == 0 )
          p_localViewAngles = (QAngle *)&v43;
        v5 = (this->m_LastCmdInfo.u[0].flags & 1) == 0;
        startorigin.x = p_localViewAngles->x;
        y = p_localViewAngles->y;
        startorigin.z = p_localViewAngles->z;
        startorigin.y = y;
        p_viewOrigin2 = &this->m_LastCmdInfo.u[0].viewOrigin2;
        if ( v5 )
          p_viewOrigin2 = &this->m_LastCmdInfo.u[0].viewOrigin;
        v15 = startorigin.y;
        z = startorigin.z;
        x = startorigin.x;
        v18 = 0;
        v18.x = fsqrt(
                  (float)((float)((float)(startorigin.y - p_viewOrigin2->y) * (float)(startorigin.y - p_viewOrigin2->y))
                        + (float)((float)(startorigin.z - p_viewOrigin2->z) * (float)(startorigin.z - p_viewOrigin2->z)))
                + (float)((float)(startorigin.x - p_viewOrigin2->x) * (float)(startorigin.x - p_viewOrigin2->x)));
        destang = v18;
        if ( t > 0.0 )
        {
          destorigin.x = destorigin.y * destang.x;
          p_viewAngles2 = &prev.info.u[0].viewAngles2;
          if ( (LOBYTE(next.info.u[1].localViewAngles2.z) & 2) == 0 )
            p_viewAngles2 = &prev.info.u[0].viewAngles;
          destang.y = p_viewAngles2->x;
          v20 = p_viewAngles2->y;
          destang.w = p_viewAngles2->z;
          destang.z = v20;
          p_viewAngles = &next.info.u[0].viewAngles2;
          if ( (v42 & 2) == 0 )
            p_viewAngles = &next.info.u[0].viewAngles;
          v22 = p_viewAngles->x;
          v23 = p_viewAngles->y;
          v24 = p_viewAngles->z;
          outinfo.u[1].localViewAngles2.y = v22;
          outinfo.u[1].localViewAngles2.z = v23;
          v47 = v24;
          for ( i = 0; i < 12; i += 4 )
          {
            t = AngleNormalizePositive(angle: *(float *)((char *)&outinfo.u[1].localViewAngles2.y + i));
            v26 = AngleNormalizePositive(angle: *(float *)((char *)&destang.y + i));
            angVel = t - v26;
            v27 = AngleNormalize(angle: angVel);
            v28 = fabs(v27) * destorigin.y;
            t = v28;
            if ( v28 > destorigin.z )
              destorigin.z = t;
          }
          z = startorigin.z;
          v15 = startorigin.y;
          x = startorigin.x;
          v8 = vel;
        }
        if ( destorigin.x <= demo_interplimit.m_pParent->m_Value.m_fValue
          && destorigin.z <= demo_avellimit.m_pParent->m_Value.m_fValue
          && !this->m_bResetInterpolation )
        {
          prev.info.u[1].localViewAngles2.z = (float)((float)(x - v50) * v8) + v50;
          *(float *)&prev.filepos = (float)((float)(v15 - v51) * v8) + v51;
          *(float *)&outinfo.u[0].flags = (float)((float)(z - v52) * v8) + v52;
          p_viewOrigin = &prev.info.u[0].viewOrigin2;
          if ( (LOBYTE(next.info.u[1].localViewAngles2.z) & 2) == 0 )
            p_viewOrigin = &prev.info.u[0].viewOrigin;
          AngleQuaternion(angles: (const QAngle *)p_viewOrigin, outQuat: (Quaternion *)&outinfo.u[1].localViewAngles2);
          v30 = &next.info.u[0].viewOrigin2;
          if ( (v42 & 2) == 0 )
            v30 = &next.info.u[0].viewOrigin;
          AngleQuaternion(angles: (const QAngle *)v30, outQuat: &destang);
          QuaternionSlerp(
            p: (const Quaternion *)&outinfo.u[1].localViewAngles2,
            q: &destang,
            t: vel,
            qt: (Quaternion *)&startang.z);
          QuaternionAngles(q: (const Quaternion *)&startang.z, angles: (QAngle *)&outinfo.u[0].viewOrigin);
          v31 = &prev.info.u[0].viewAngles2;
          if ( (LOBYTE(next.info.u[1].localViewAngles2.z) & 2) == 0 )
            v31 = &prev.info.u[0].viewAngles;
          AngleQuaternion(angles: v31, outQuat: (Quaternion *)&outinfo.u[1].localViewAngles2);
          v32 = &next.info.u[0].viewAngles2;
          if ( (v42 & 2) == 0 )
            v32 = &next.info.u[0].viewAngles;
          AngleQuaternion(angles: v32, outQuat: &destang);
          QuaternionSlerp(
            p: (const Quaternion *)&outinfo.u[1].localViewAngles2,
            q: &destang,
            t: vel,
            qt: (Quaternion *)&startang.z);
          QuaternionAngles(q: (const Quaternion *)&startang.z, angles: &outinfo.u[0].viewAngles);
          goto LABEL_62;
        }
        this->m_bResetInterpolation = false;
LABEL_55:
        v33 = &this->m_LastCmdInfo.u[0].viewOrigin2;
        if ( (this->m_LastCmdInfo.u[0].flags & 1) == 0 )
          v33 = &this->m_LastCmdInfo.u[0].viewOrigin;
        v34 = this->m_LastCmdInfo.u[0].flags & 2;
        prev.info.u[1].localViewAngles2.z = v33->x;
        prev.filepos = LODWORD(v33->y);
        z_low = LODWORD(v33->z);
        v36 = &this->m_LastCmdInfo.u[0].viewAngles2;
        outinfo.u[0].flags = z_low;
        if ( v34 == 0 )
          v36 = &this->m_LastCmdInfo.u[0].viewAngles;
        outinfo.u[0].viewOrigin.x = v36->x;
        outinfo.u[0].viewOrigin.y = v36->y;
        v37 = v36->z;
        p_localViewAngles2 = &this->m_LastCmdInfo.u[0].localViewAngles2;
        outinfo.u[0].viewOrigin.z = v37;
        if ( v34 == 0 )
          p_localViewAngles2 = &this->m_LastCmdInfo.u[0].localViewAngles;
        outinfo.u[0].viewAngles = *p_localViewAngles2;
      }
    }
    else if ( v58 != 0 )
    {
      goto LABEL_55;
    }
LABEL_62:
    *(float *)&this->m_nPreviousTick = angVel;
    v39 = CDemoPlayer::OverrideView(this, info: (democmdinfo_t *)&prev.info.u[1].localViewAngles2.y);
    if ( ((unsigned __int8)v58 | v39) != 0 )
    {
      g_pClientSidePrediction->SetViewOrigin(
        this: g_pClientSidePrediction,
        a2: (Vector *)&prev.info.u[1].localViewAngles2.z);
      g_pClientSidePrediction->SetViewAngles(this: g_pClientSidePrediction, a2: (QAngle *)&outinfo.u[0].viewOrigin);
      g_pClientSidePrediction->SetLocalViewAngles(this: g_pClientSidePrediction, a2: &outinfo.u[0].viewAngles);
      GetLocalClient(nSlot: -1)->viewangles = (QAngle)outinfo.u[0].viewOrigin;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100738C0
// Name: protected: void CDemoRecorder::WriteSplitScreenPlayers(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CDemoRecorder::WriteSplitScreenPlayers(CDemoRecorder *this@<ecx>, int a2@<ebx>)
{
  int v3; // ebx
  int v4; // eax
  int v5; // ecx
  float *p_z; // eax
  CClientState *BaseLocalClient; // eax
  unsigned int CurPos; // eax
  _BYTE pData[96000]; // [esp+8h] [ebp-177C0h] BYREF
  democmdinfo_t cmdInfo; // [esp+17708h] [ebp-C0h] BYREF
  bf_write v12; // [esp+177A0h] [ebp-28h] BYREF
  _BYTE v13[4]; // [esp+177B8h] [ebp-10h] BYREF
  int nSeqNrIn; // [esp+177BCh] [ebp-Ch] BYREF
  unsigned __int8 cmd[4]; // [esp+177C0h] [ebp-8h]
  int nSeqNrOut; // [esp+177C4h] [ebp-4h]

  bf_write::bf_write(this: &v12);
  bf_write::StartWriting(this: &v12, pData, nBytes: 96000, iStartBit: 0, nBits: -1);
  CNetworkStringTable::SetTick(this: &v12, pDebugName: "DemoFileWriteSplitScreenPlayers");
  if ( CDemoFile::IsOpen(this: &this->m_DemoFile) )
  {
    v3 = (v12.m_iCurBit + 7) >> 3;
    if ( v3 > 0 )
    {
      if ( (unsigned int)(v12.m_iCurBit % 8 - 1) <= 1 )
        bf_write::WriteUBitLong(this: &v12, curData: 0, numbits: 6, bCheckRange: true);
      cmd[0] = !this->m_bIsDemoHeader + 1;
      if ( cmd[0] == 2 )
        ++this->m_nFrameCount;
      v4 = ((int (__thiscall *)(CDemoRecorder *, _DWORD))this->GetRecordingTick)(a1: this, a2: 0);
      CDemoFile::WriteCmdHeader(this: &this->m_DemoFile, cmd: cmd[0], tick: v4, nPlayerSlot: a2);
      v5 = 1;
      p_z = &cmdInfo.u[0].viewOrigin.z;
      do
      {
        *(p_z - 3) = 0.0;
        *(p_z - 2) = 0.0;
        *(p_z - 1) = 0.0;
        *p_z = 0.0;
        p_z[1] = 0.0;
        p_z[2] = 0.0;
        p_z[3] = 0.0;
        p_z[4] = 0.0;
        p_z[5] = 0.0;
        p_z[6] = 0.0;
        p_z[7] = 0.0;
        p_z[8] = 0.0;
        p_z[9] = 0.0;
        p_z[10] = 0.0;
        p_z[11] = 0.0;
        p_z[12] = 0.0;
        p_z[13] = 0.0;
        p_z[14] = 0.0;
        p_z[15] = 0.0;
        p_z += 19;
        --v5;
      }
      while ( v5 >= 0 );
      CDemoRecorder::GetClientCmdInfo(this, &cmdInfo);
      CDemoFile::WriteCmdInfo(this: &this->m_DemoFile, info: &cmdInfo);
      BaseLocalClient = GetBaseLocalClient();
      ((void (__thiscall *)(INetChannel *, _BYTE *, int *))BaseLocalClient->m_NetChannel->GetSequenceData)(
        a1: BaseLocalClient->m_NetChannel,
        a2: v13,
        a3: &nSeqNrIn);
      CDemoFile::WriteSequenceInfo(this: &this->m_DemoFile, nSeqNrIn, nSeqNrOut);
      CDemoFile::WriteRawData(this: &this->m_DemoFile, buffer: (const char *)v12.m_pData, length: v3);
      if ( demo_debug.m_pParent != nullptr && demo_debug.m_pParent->m_Value.m_nValue >= 1 )
      {
        CurPos = CDemoFile::GetCurPos(this: &this->m_DemoFile, bRead: false);
        _Msg(a1: "Writing demo message %i bytes at file pos %i\n", v3, CurPos);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10073A70
// Name: protected: void CDemoRecorder::WriteBSPDecals(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDemoRecorder::WriteBSPDecals(CDemoRecorder *this)
{
  int v1; // eax
  decallist_t *v2; // esi
  int v3; // edi
  __int16 *p_entityIndex; // esi
  int v5; // eax
  IClientEntity *v6; // eax
  const model_t *v7; // edi
  int v8; // eax
  CClientState *BaseLocalClient; // eax
  const char *v10; // [esp-4h] [ebp-17764h]
  _BYTE pData[96000]; // [esp+Ch] [ebp-17754h] BYREF
  bf_write buffer; // [esp+1770Ch] [ebp-54h] BYREF
  SVC_BSPDecal v13; // [esp+17724h] [ebp-3Ch] BYREF
  decallist_t *v14; // [esp+17750h] [ebp-10h]
  CDemoRecorder *v15; // [esp+17754h] [ebp-Ch]
  int i; // [esp+17758h] [ebp-8h]
  bool found; // [esp+1775Fh] [ebp-1h] BYREF

  v15 = this;
  v1 = Draw_DecalMax();
  v2 = (decallist_t *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 156 * v1);
  v14 = v2;
  v3 = DecalListCreate(pList: v2);
  bf_write::bf_write(this: &buffer);
  bf_write::StartWriting(this: &buffer, pData, nBytes: 96000, iStartBit: 0, nBits: -1);
  CNetworkStringTable::SetTick(this: &buffer, pDebugName: "DemoFileWriteBSPDecals");
  if ( v3 > 0 )
  {
    p_entityIndex = &v2->entityIndex;
    for ( i = v3; i != 0; --i )
    {
      v5 = *p_entityIndex;
      v13.m_bReliable = true;
      v13.m_NetChannel = nullptr;
      v13.__vftable = (SVC_BSPDecal_vtbl *)&SVC_BSPDecal::`vftable';
      found = false;
      v6 = entitylist->GetClientEntity(this: entitylist, a2: v5);
      if ( v6 != nullptr )
      {
        v7 = v6->GetModel(this: &v6->IClientRenderable);
        v8 = *p_entityIndex;
        v13.m_Pos = *(Vector *)(p_entityIndex - 70);
        v13.m_nEntityIndex = v8;
        v13.m_nDecalTextureIndex = Draw_DecalIndexFromName(name: (char *)p_entityIndex - 128, &found);
        v13.m_nModelIndex = 0;
        if ( v7 != nullptr )
        {
          v10 = modelloader->GetName(this: modelloader, a2: v7);
          BaseLocalClient = GetBaseLocalClient();
          v13.m_nModelIndex = CClientState::LookupModelIndex(this: BaseLocalClient, name: v10);
        }
        SVC_BSPDecal::WriteToBuffer(this: &v13, &buffer);
      }
      p_entityIndex += 78;
    }
    v2 = v14;
  }
  CDemoRecorder::WriteMessages(this: v15, a2: 0, message: &buffer);
  _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v2);
}

//------------------------------------------------------------------------------
// Address: 0x10073BD0
// Name: public: virtual void CDemoRecorder::RecordStringTables(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDemoRecorder::RecordStringTables(CDemoRecorder *this)
{
  int v2; // eax
  CUtlBuffer bigBuff; // [esp+8h] [ebp-48h] BYREF
  bf_write buf; // [esp+38h] [ebp-18h] BYREF

  if ( CDemoFile::IsOpen(this: &this->m_DemoFile) )
  {
    CUtlBuffer::CUtlBuffer(this: &bigBuff, growSize: 0, initSize: 0, nFlags: 0);
    CUtlBuffer::EnsureCapacity(this: &bigBuff, num: 0x200000);
    bf_write::bf_write(this: &buf, pData: bigBuff.m_Memory.m_pMemory, nBytes: 0x200000, nBits: -1);
    CNetworkStringTableContainer::WriteStringTables(this: networkStringTableContainerClient, &buf);
    if ( buf.m_nDataBits - buf.m_iCurBit <= 0 )
      Sys_Error(error: "unable to record server classes\n");
    v2 = this->GetRecordingTick(this);
    CDemoFile::WriteStringTables(this: &this->m_DemoFile, &buf, tick: v2);
    if ( bigBuff.m_Memory.m_nGrowSize >= 0 && bigBuff.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: bigBuff.m_Memory.m_pMemory);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10073C80
// Name: protected: void CDemoRecorder::StartupDemoFile(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDemoRecorder::StartupDemoFile(CDemoRecorder *this)
{
  void *v2; // edi
  void *v3; // eax
  const char *v4; // eax
  CClientState *BaseLocalClient; // eax
  Remote_t *v6; // eax
  const char *v7; // eax
  char *m_pszString; // eax
  int m_Size; // edi
  int v10; // esi
  const char *pszValue; // eax
  int v12; // eax
  int v13; // eax
  void *v14; // esp
  const char *v15; // eax
  unsigned int v16; // esi
  char *v17; // eax
  CClientState *v18; // eax
  int v19; // [esp+0h] [ebp-224h] BYREF
  int v20; // [esp+4h] [ebp-220h] BYREF
  char szGameDir[260]; // [esp+Ch] [ebp-218h] BYREF
  char demoFileName[260]; // [esp+110h] [ebp-114h] BYREF
  unsigned __int8 *pWriteBuffer; // [esp+214h] [ebp-10h]
  unsigned int iTotalDataSize; // [esp+218h] [ebp-Ch]
  unsigned __int8 *pWrite; // [esp+21Ch] [ebp-8h]
  int i; // [esp+220h] [ebp-4h]

  if ( this->m_bRecording && !CDemoFile::IsOpen(this: &this->m_DemoFile) )
  {
    if ( demo_enabledemos.m_pParent != nullptr && demo_enabledemos.m_pParent->m_Value.m_nValue != 0 )
    {
      if ( this->m_nDemoNumber > 1 )
        V_snprintf(pDest: demoFileName, maxLen: 260, pFormat: "%s_%i.dem", this->m_szDemoBaseName, this->m_nDemoNumber);
      else
        V_snprintf(pDest: demoFileName, maxLen: 260, pFormat: "%s.dem", this->m_szDemoBaseName);
      if ( CDemoFile::Open(this: &this->m_DemoFile, name: demoFileName, bReadOnly: false, bMemoryBuffer: false) )
      {
        v2 = g_pFileSystem->OpenEx(this: g_pFileSystem, a2: "demoheader.tmp", a3: "rb", a4: 0, a5: 0, a6: 0);
        if ( v2 != nullptr )
        {
          v3 = MemAlloc_Alloc(nSize: 0x17700u);
          bf_write::StartWriting(this: &this->m_MessageData, pData: v3, nBytes: 96000, iStartBit: 0, nBits: -1);
          CNetworkStringTable::SetTick(this: &this->m_MessageData, pDebugName: "DemoFileWriteBuffer");
          _V_memset(dest: &this->m_DemoFile.m_DemoHeader, fill: 0, count: 1072);
          this->m_DemoFile.m_DemoHeader.demoprotocol = 4;
          this->m_DemoFile.m_DemoHeader.networkprotocol = GetHostVersion();
          V_strncpy(pDest: this->m_DemoFile.m_DemoHeader.demofilestamp, pSrc: "HL2DEMO", maxLen: 8);
          v4 = modelloader->GetName(this: modelloader, a2: host_state.worldmodel);
          V_FileBase(in: v4, out: this->m_DemoFile.m_DemoHeader.mapname, maxlen: 260);
          V_strncpy(pDest: szGameDir, pSrc: com_gamedir, maxLen: 260);
          V_FileBase(in: szGameDir, out: this->m_DemoFile.m_DemoHeader.gamedirectory, maxlen: 260);
          BaseLocalClient = GetBaseLocalClient();
          v6 = CAddressList::Get(this: &BaseLocalClient->m_Remote, index: 0);
          v7 = CUtlString::operator char const *(this: &v6->m_szRetryAddress);
          V_strncpy(pDest: this->m_DemoFile.m_DemoHeader.servername, pSrc: v7, maxLen: 260);
          if ( (cl_name.m_nFlags & 0x1000) != 0 )
          {
            m_pszString = "FCVAR_NEVER_AS_STRING";
          }
          else
          {
            m_pszString = cl_name.m_pParent->m_Value.m_pszString;
            if ( m_pszString == nullptr )
              m_pszString = (char *)defaultValue;
          }
          V_strncpy(pDest: this->m_DemoFile.m_DemoHeader.clientname, pSrc: m_pszString, maxLen: 260);
          g_pFileSystem->Seek(this: &g_pFileSystem->IBaseFileSystem, a2: v2, a3: 0, a4: FILESYSTEM_SEEK_TAIL);
          this->m_DemoFile.m_DemoHeader.signonlength = g_pFileSystem->Tell(
                                                         this: &g_pFileSystem->IBaseFileSystem,
                                                         a2: v2);
          g_pFileSystem->Seek(this: &g_pFileSystem->IBaseFileSystem, a2: v2, a3: 0, a4: FILESYSTEM_SEEK_HEAD);
          CDemoFile::WriteDemoHeader(this: &this->m_DemoFile);
          CDemoFile::WriteFileBytes(this: &this->m_DemoFile, fh: v2, length: this->m_DemoFile.m_DemoHeader.signonlength);
          g_pFileSystem->Close(this: &g_pFileSystem->IBaseFileSystem, a2: v2);
          this->m_nFrameCount = 0;
          this->m_bIsDemoHeader = false;
          CDemoRecorder::ResyncDemoClock(this);
          CDemoFile::WriteCmdHeader(this: &this->m_DemoFile, cmd: 3u, tick: 0, nPlayerSlot: 0);
          m_Size = g_RegisteredDemoCustomDataCallbacks.m_Size;
          v10 = 0;
          if ( g_RegisteredDemoCustomDataCallbacks.m_Size != 0 )
          {
            i = 0;
            do
            {
              pszValue = g_RegisteredDemoCustomDataCallbacks.m_Memory.m_pMemory[v10].szSaveID.pszValue;
              if ( pszValue == nullptr )
                pszValue = defaultValue;
              v12 = _V_strlen(str: pszValue);
              ++v10;
              v13 = i + v12 + 1;
              i = v13;
            }
            while ( v10 != m_Size );
            iTotalDataSize = v13 + 4;
            v14 = alloca(v13 + 4);
            pWriteBuffer = (unsigned __int8 *)&v19;
            v19 = m_Size;
            pWrite = (unsigned __int8 *)&v20;
            i = 0;
            do
            {
              v15 = g_RegisteredDemoCustomDataCallbacks.m_Memory.m_pMemory[i].szSaveID.pszValue;
              if ( v15 == nullptr )
                v15 = defaultValue;
              v16 = _V_strlen(str: v15) + 1;
              v17 = (char *)g_RegisteredDemoCustomDataCallbacks.m_Memory.m_pMemory[i].szSaveID.pszValue;
              if ( v17 == nullptr )
                v17 = (char *)defaultValue;
              memcpy(dst: pWrite, src: (unsigned __int8 *)v17, count: v16);
              pWrite += v16;
              ++i;
            }
            while ( i != m_Size );
            CDemoFile::WriteCustomData(
              this: &this->m_DemoFile,
              iCallbackIndex: -1,
              pData: pWriteBuffer,
              iDataSize: iTotalDataSize,
              tick: 0);
          }
          ((void (__thiscall *)(CDemoRecorder *, int))this->RecordStringTables)(a1: this, a2: v19);
          CDemoRecorder::WriteDemoCvars(this);
          CDemoRecorder::WriteBSPDecals(this);
          g_ClientDLL->HudReset(this: g_ClientDLL);
          if ( splitscreen->GetNumSplitScreenPlayers(this: splitscreen) > 1 )
            CDemoRecorder::WriteSplitScreenPlayers(this, a2: (int)this);
          v18 = GetBaseLocalClient();
          CBaseClientState::SendStringCmd(this: v18, command: "demorestart");
          ConMsg(a1: "Recording to %s...\n", demoFileName);
        }
        else
        {
          ConMsg(a1: "StartupDemoFile: couldn't open demo file header.\n");
        }
      }
    }
    else
    {
      _Warning(a1: "DEMO: cannot start recording a demo (set 'demo_enabledemos' to 1 and restart the map to enable demos)\n");
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10074070
// Name: public: virtual void CDemoRecorder::RecordPacket(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CDemoRecorder::RecordPacket(CDemoRecorder *this@<ecx>, int a2@<ebx>)
{
  bf_write *p_m_MessageData; // edi

  p_m_MessageData = &this->m_MessageData;
  CDemoRecorder::WriteMessages(this, a2, message: &this->m_MessageData);
  bf_write::Reset(this: p_m_MessageData);
  if ( this->m_bCloseDemoFile )
    CDemoRecorder::CloseDemoFile(this);
}

//------------------------------------------------------------------------------
// Address: 0x100740A0
// Name: public: virtual void CDemoRecorder::SetSignonState(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDemoRecorder::SetSignonState(CDemoRecorder *this, int state)
{
  if ( !demoplayer->IsPlayingBack(this: demoplayer)
    && demo_enabledemos.m_pParent != nullptr
    && demo_enabledemos.m_pParent->m_Value.m_nValue != 0 )
  {
    if ( state == 3 )
    {
      if ( CDemoFile::IsOpen(this: &this->m_DemoFile) )
      {
        CDemoRecorder::CloseDemoFile(this);
        ++this->m_nDemoNumber;
      }
      CDemoRecorder::StartupDemoHeader(this);
    }
    else if ( state == 5 )
    {
      this->m_bCloseDemoFile = true;
    }
    else if ( state == 6 && this->m_bRecording )
    {
      CDemoRecorder::StartupDemoFile(this);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10074120
// Name: public: virtual void CDemoRecorder::RecordServerClasses(class ServerClass __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDemoRecorder::RecordServerClasses(CDemoRecorder *this, ServerClass *pClasses)
{
  int v3; // eax
  CUtlBuffer bigBuff; // [esp+8h] [ebp-48h] BYREF
  bf_write buf; // [esp+38h] [ebp-18h] BYREF

  if ( CDemoFile::IsOpen(this: &this->m_DemoFile) )
  {
    CUtlBuffer::CUtlBuffer(this: &bigBuff, growSize: 0, initSize: 0, nFlags: 0);
    CUtlBuffer::EnsureCapacity(this: &bigBuff, num: 0x200000);
    bf_write::bf_write(
      this: &buf,
      pDebugName: "CDemoRecorder::RecordServerClasses",
      pData: bigBuff.m_Memory.m_pMemory,
      nBytes: 0x200000,
      nBits: -1);
    DataTable_WriteSendTablesBuffer(pClasses, pBuf: &buf);
    DataTable_WriteClassInfosBuffer(pClasses, pBuf: &buf);
    if ( buf.m_nDataBits - buf.m_iCurBit <= 0 )
      Sys_Error(error: "unable to record server classes\n");
    v3 = this->GetRecordingTick(this);
    CDemoFile::WriteNetworkDataTables(this: &this->m_DemoFile, &buf, tick: v3);
    if ( bigBuff.m_Memory.m_nGrowSize >= 0 && bigBuff.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: bigBuff.m_Memory.m_pMemory);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100741E0
// Name: void ComputeTimedemoResultsFilename(class CFmtStrN<256> __near &,class CFmtStrN<256> __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ComputeTimedemoResultsFilename(CFmtStrN<256> *fileName, CFmtStrN<256> *dateString)
{
  IMaterialSystem_vtbl *v2; // esi
  int v3; // eax
  int v4; // edi
  char *v5; // eax
  char *v6; // esi
  int v7; // eax
  char *v8; // eax
  const CUtlString *v9; // eax
  int v10; // eax
  const char *v11; // eax
  const char *v12; // eax
  const char *v13; // [esp-8h] [ebp-38Ch]
  const char *v14; // [esp-4h] [ebp-388h]
  MaterialAdapterInfo_t info; // [esp+Ch] [ebp-378h] BYREF
  char host[256]; // [esp+230h] [ebp-154h] BYREF
  tm time; // [esp+330h] [ebp-54h] BYREF
  CUtlString benchmarkPath; // [esp+354h] [ebp-30h] BYREF
  CUtlString gpuName; // [esp+364h] [ebp-20h] BYREF
  CUtlString rhs; // [esp+374h] [ebp-10h] BYREF

  _Plat_GetLocalTime(a1: &time);
  CFmtStrN<256>::sprintf(
    this: dateString,
    pszFormat: "%04d_%02d_%02d__%02d_%02d_%02d",
    time.tm_year + 1900,
    time.tm_mon + 1,
    time.tm_mday,
    time.tm_hour,
    time.tm_min,
    time.tm_sec);
  v2 = materials->__vftable;
  v3 = ((int (__thiscall *)(IMaterialSystem *, MaterialAdapterInfo_t *))materials->GetCurrentAdapter)(
         a1: materials,
         a2: &info);
  ((void (__thiscall *)(IMaterialSystem *, int))v2->GetDisplayAdapterInfo)(a1: materials, a2: v3);
  CUtlString::CUtlString(this: &gpuName, pString: info.m_pDriverName);
  rhs.m_Storage.m_Memory.m_nGrowSize = (int)"nvidia";
  rhs.m_Storage.m_nActualLength = (int)"ati";
  v4 = 0;
  while ( 1 )
  {
    v14 = (const char *)*(&rhs.m_Storage.m_Memory.m_nGrowSize + v4);
    v5 = CUtlString::Get(this: &gpuName);
    v6 = V_stristr(pStr: v5, pSearch: v14);
    if ( v6 != nullptr )
      break;
    if ( (unsigned int)++v4 >= 2 )
      goto LABEL_10;
  }
  v7 = _V_strlen(str: *((const char **)&rhs.m_Storage.m_Memory.m_nGrowSize + v4));
  if ( v6[v7] == 32 )
    ++v7;
  CUtlString::CUtlString(this: &rhs, pString: &v6[v7]);
  v8 = CUtlString::Get(this: &gpuName);
  CUtlString::SetLength(this: &gpuName, nLen: v6 - v8);
  CUtlString::operator+=(this: &gpuName, &rhs);
  rhs.m_Storage.m_nActualLength = 0;
  if ( rhs.m_Storage.m_Memory.m_nGrowSize >= 0 && rhs.m_Storage.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: rhs.m_Storage.m_Memory.m_pMemory);
LABEL_10:
  v9 = CUtlString::Replace(this: &gpuName, result: &rhs, cFrom: 32, cTo: 95);
  CUtlString::operator=(this: &gpuName, src: v9);
  rhs.m_Storage.m_nActualLength = 0;
  if ( rhs.m_Storage.m_Memory.m_nGrowSize >= 0 && rhs.m_Storage.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: rhs.m_Storage.m_Memory.m_pMemory);
  memset(host, 0, sizeof(host));
  if ( gethostname(name: host, namelen: 255) < 0 )
    V_strncpy(pDest: host, pSrc: dateString->m_szBuf, maxLen: 255);
  host[255] = 0;
  v10 = _CommandLine();
  v11 = (const char *)(*(int (__thiscall **)(int, const char *, _DWORD))(*(_DWORD *)v10 + 32))(
                        a1: v10,
                        a2: "-benchmark_path",
                        a3: 0);
  CUtlString::CUtlString(this: &benchmarkPath, pString: v11);
  if ( CUtlString::Length(this: &benchmarkPath) != 0 )
    CUtlString::StripTrailingSlash(this: &benchmarkPath);
  else
    CUtlString::operator=(this: &benchmarkPath, src: ".");
  v13 = CUtlString::Get(this: &gpuName);
  v12 = CUtlString::Get(this: &benchmarkPath);
  CFmtStrN<256>::sprintf(this: fileName, pszFormat: "%s\\SourceBench_%s_%s.csv", v12, v13, host);
  benchmarkPath.m_Storage.m_nActualLength = 0;
  if ( benchmarkPath.m_Storage.m_Memory.m_nGrowSize >= 0 )
  {
    if ( benchmarkPath.m_Storage.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: benchmarkPath.m_Storage.m_Memory.m_pMemory);
      benchmarkPath.m_Storage.m_Memory.m_pMemory = nullptr;
    }
    benchmarkPath.m_Storage.m_Memory.m_nAllocationCount = 0;
  }
  gpuName.m_Storage.m_nActualLength = 0;
  if ( gpuName.m_Storage.m_Memory.m_nGrowSize >= 0 && gpuName.m_Storage.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: gpuName.m_Storage.m_Memory.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x10074430
// Name: public: void CDemoPlayer::WriteTimeDemoResults(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDemoPlayer::WriteTimeDemoResults(CDemoPlayer *this)
{
  int v2; // eax
  int v3; // eax
  int v4; // esi
  bool v5; // cc
  int v6; // ecx
  long double v7; // st7
  float m_flTotalFPSVariability; // xmm1_4
  void *v9; // esi
  IMatRenderContext *v10; // edi
  ImageFormat v11; // eax
  IMaterialSystem_vtbl *v12; // ebx
  int v13; // eax
  int m_nValue; // ecx
  IFileSystem_vtbl *v15; // ebx
  int v16; // eax
  const char *v17; // eax
  const ImageFormatInfo_t *v18; // eax
  int v19; // eax
  int v20; // eax
  int v21; // eax
  int v22; // eax
  const char *v23; // ecx
  int v24; // eax
  const char *v25; // ecx
  MaterialAdapterInfo_t info; // [esp+48h] [ebp-45Ch] BYREF
  CFmtStrN<256> dateString; // [esp+26Ch] [ebp-238h] BYREF
  CFmtStrN<256> fileName; // [esp+378h] [ebp-12Ch] BYREF
  int height; // [esp+484h] [ebp-20h] BYREF
  int width; // [esp+488h] [ebp-1Ch] BYREF
  float v31; // [esp+48Ch] [ebp-18h]
  float flVariability; // [esp+490h] [ebp-14h]
  float time; // [esp+494h] [ebp-10h]
  ImageFormat backBufferFormat; // [esp+498h] [ebp-Ch]
  int frames; // [esp+49Ch] [ebp-8h]
  void (**v36)(IFileSystem *, void *, const char *, ...); // [esp+4A0h] [ebp-4h]

  v2 = host_framecount - this->m_nTimeDemoStartFrame;
  v36 = (void (**)(IFileSystem *, void *, const char *, ...))this;
  v3 = v2 - 1;
  if ( v3 >= 1 )
  {
    frames = v3;
    v4 = v3;
  }
  else
  {
    v4 = 1;
    frames = 1;
  }
  v5 = _Plat_FloatTime(a1: this) - this->m_flTimeDemoStartTime >= 1.0;
  v7 = 1.0;
  if ( v5 )
    v7 = _Plat_FloatTime(a1: v6) - this->m_flTimeDemoStartTime;
  m_flTotalFPSVariability = this->m_flTotalFPSVariability;
  time = v7;
  flVariability = m_flTotalFPSVariability / (float)v4;
  *(float *)&backBufferFormat = (float)v4;
  v31 = (float)v4 / time;
  ConMsg(
    a1: "%i frames %5.3f seconds %5.2f fps (%5.2f ms/f) %5.3f fps variability\n",
    v4,
    (double)v7,
    v31,
    (double)(1000.0 * v7 / (float)v4),
    flVariability);
  fileName.__vftable = (CFmtStrN<256>_vtbl *)&CFmtStrN<256>::`vftable';
  dateString.__vftable = (CFmtStrN<256>_vtbl *)&CFmtStrN<256>::`vftable';
  *(_WORD *)&fileName.m_bQuietTruncation = 1;
  fileName.m_nLength = 0;
  *(_WORD *)&dateString.m_bQuietTruncation = 1;
  dateString.m_nLength = 0;
  ComputeTimedemoResultsFilename(&fileName, &dateString);
  g_pFileSystem->FileExists(this: &g_pFileSystem->IBaseFileSystem, a2: fileName.m_szBuf, a3: nullptr);
  v9 = g_pFileSystem->Open(this: &g_pFileSystem->IBaseFileSystem, a2: fileName.m_szBuf, a3: "a+", a4: 0);
  if ( v9 != nullptr )
  {
    if ( g_pFileSystem->Size_2(this: &g_pFileSystem->IBaseFileSystem, a2: v9) == 0 )
    {
      g_pFileSystem->FPrintf(this: g_pFileSystem, a2: v9, a3: "Portal 2 Benchmark Results\n\n");
      g_pFileSystem->FPrintf(this: g_pFileSystem, a2: v9, a3: "demofile,");
      g_pFileSystem->FPrintf(this: g_pFileSystem, a2: v9, a3: "frame data csv,");
      g_pFileSystem->FPrintf(this: g_pFileSystem, a2: v9, a3: "fps,");
      g_pFileSystem->FPrintf(this: g_pFileSystem, a2: v9, a3: "fps variability,");
      g_pFileSystem->FPrintf(this: g_pFileSystem, a2: v9, a3: "total sec,");
      g_pFileSystem->FPrintf(this: g_pFileSystem, a2: v9, a3: "width,");
      g_pFileSystem->FPrintf(this: g_pFileSystem, a2: v9, a3: "height,");
      g_pFileSystem->FPrintf(this: g_pFileSystem, a2: v9, a3: "msaa,");
      g_pFileSystem->FPrintf(this: g_pFileSystem, a2: v9, a3: "aniso,");
      g_pFileSystem->FPrintf(this: g_pFileSystem, a2: v9, a3: "picmip,");
      g_pFileSystem->FPrintf(this: g_pFileSystem, a2: v9, a3: "numframes,");
      g_pFileSystem->FPrintf(this: g_pFileSystem, a2: v9, a3: "dxlevel,");
      g_pFileSystem->FPrintf(this: g_pFileSystem, a2: v9, a3: "backbuffer,");
      g_pFileSystem->FPrintf(this: g_pFileSystem, a2: v9, a3: "cmdline,");
      g_pFileSystem->FPrintf(this: g_pFileSystem, a2: v9, a3: "driver,");
      g_pFileSystem->FPrintf(this: g_pFileSystem, a2: v9, a3: "vendor id,");
      g_pFileSystem->FPrintf(this: g_pFileSystem, a2: v9, a3: "device id,");
      g_pFileSystem->FPrintf(this: g_pFileSystem, a2: v9, a3: "sound,");
      g_pFileSystem->FPrintf(this: g_pFileSystem, a2: v9, a3: "vsync,");
      g_pFileSystem->FPrintf(this: g_pFileSystem, a2: v9, a3: "gpu_level,");
      g_pFileSystem->FPrintf(this: g_pFileSystem, a2: v9, a3: "cpu_level,");
      g_pFileSystem->FPrintf(this: g_pFileSystem, a2: v9, a3: "date,");
      g_pFileSystem->FPrintf(this: g_pFileSystem, a2: v9, a3: "\n");
    }
    if ( (_S2_0 & 1) == 0 )
    {
      _S2_0 |= 1u;
      ConVarRef::ConVarRef(this: &gpu_level, pName: "gpu_level");
    }
    if ( (_S2_0 & 2) == 0 )
    {
      _S2_0 |= 2u;
      ConVarRef::ConVarRef(this: &cpu_level, pName: "cpu_level");
    }
    if ( (_S2_0 & 4) == 0 )
    {
      _S2_0 |= 4u;
      ConVarRef::ConVarRef(this: &mat_vsync, pName: "mat_vsync");
    }
    if ( (_S2_0 & 8) == 0 )
    {
      _S2_0 |= 8u;
      ConVarRef::ConVarRef(this: &mat_antialias, pName: "mat_antialias");
    }
    if ( (_S2_0 & 0x10) == 0 )
    {
      _S2_0 |= 0x10u;
      ConVarRef::ConVarRef(this: &mat_forceaniso, pName: "mat_forceaniso");
    }
    if ( (_S2_0 & 0x20) == 0 )
    {
      _S2_0 |= 0x20u;
      ConVarRef::ConVarRef(this: &mat_picmip, pName: "mat_picmip");
    }
    v10 = materials->GetRenderContext(this: materials);
    if ( v10 != nullptr )
      v10->BeginRender(this: v10);
    v10->GetWindowSize(this: v10, a2: &width, a3: &height);
    v11 = materials->GetBackBufferFormat(this: materials);
    v12 = materials->__vftable;
    backBufferFormat = v11;
    v13 = ((int (__thiscall *)(IMaterialSystem *, MaterialAdapterInfo_t *))v12->GetCurrentAdapter)(
            a1: materials,
            a2: &info);
    ((void (__thiscall *)(IMaterialSystem *, int))v12->GetDisplayAdapterInfo)(a1: materials, a2: v13);
    g_pFileSystem->Seek(this: &g_pFileSystem->IBaseFileSystem, a2: v9, a3: 0, a4: FILESYSTEM_SEEK_TAIL);
    g_pFileSystem->FPrintf(this: g_pFileSystem, a2: v9, a3: "%s,", v36 + 1);
    g_pFileSystem->FPrintf(this: g_pFileSystem, a2: v9, a3: "%s,", g_pStatsFile);
    g_pFileSystem->FPrintf(this: g_pFileSystem, a2: v9, a3: "%5.1f,", v31);
    g_pFileSystem->FPrintf(this: g_pFileSystem, a2: v9, a3: "%5.1f,", flVariability);
    g_pFileSystem->FPrintf(this: g_pFileSystem, a2: v9, a3: "%5.1f,", time);
    g_pFileSystem->FPrintf(this: g_pFileSystem, a2: v9, a3: "%i,", width);
    g_pFileSystem->FPrintf(this: g_pFileSystem, a2: v9, a3: "%i,", height);
    m_nValue = 1;
    if ( mat_antialias.m_pConVarState->m_Value.m_nValue >= 1 )
      m_nValue = mat_antialias.m_pConVarState->m_Value.m_nValue;
    g_pFileSystem->FPrintf(this: g_pFileSystem, a2: v9, a3: "%i,", m_nValue);
    g_pFileSystem->FPrintf(this: g_pFileSystem, a2: v9, a3: "%i,", mat_forceaniso.m_pConVarState->m_Value.m_nValue);
    g_pFileSystem->FPrintf(this: g_pFileSystem, a2: v9, a3: "%i,", mat_picmip.m_pConVarState->m_Value.m_nValue);
    g_pFileSystem->FPrintf(this: g_pFileSystem, a2: v9, a3: "%i,", frames);
    v15 = g_pFileSystem->IAppSystem::__vftable;
    v16 = g_pMaterialSystemHardwareConfig->GetDXSupportLevel(this: g_pMaterialSystemHardwareConfig);
    v17 = COM_DXLevelToString(dxlevel: v16);
    v15->FPrintf(this: g_pFileSystem, a2: v9, a3: "%s,", v17);
    v18 = ImageLoader::ImageFormatInfo(fmt: backBufferFormat);
    g_pFileSystem->FPrintf(this: g_pFileSystem, a2: v9, a3: "%s,", v18->m_pName);
    v19 = _CommandLine();
    v36 = (void (**)(IFileSystem *, void *, const char *, ...))g_pFileSystem->IAppSystem::__vftable;
    v20 = (*(int (__thiscall **)(int))(*(_DWORD *)v19 + 8))(a1: v19);
    v36[27](a1: g_pFileSystem, a2: v9, a3: "%s,", v20);
    g_pFileSystem->FPrintf(this: g_pFileSystem, a2: v9, a3: "%s,", &info);
    g_pFileSystem->FPrintf(this: g_pFileSystem, a2: v9, a3: "0x%x,", info.m_VendorID);
    g_pFileSystem->FPrintf(this: g_pFileSystem, a2: v9, a3: "0x%x,", info.m_DeviceID);
    v21 = _CommandLine();
    v22 = (*(int (__thiscall **)(int, const char *, _DWORD))(*(_DWORD *)v21 + 12))(a1: v21, a2: "-nosound", a3: 0);
    v23 = "disabled";
    if ( v22 == 0 )
      v23 = "enabled";
    g_pFileSystem->FPrintf(this: g_pFileSystem, a2: v9, a3: "%s,", v23);
    v24 = _CommandLine();
    if ( (*(int (__thiscall **)(int, const char *, _DWORD))(*(_DWORD *)v24 + 12))(a1: v24, a2: "-mat_vsync", a3: 0) != 0
      || (v25 = "disabled", mat_vsync.m_pConVarState->m_Value.m_nValue != 0) )
    {
      v25 = "enabled";
    }
    g_pFileSystem->FPrintf(this: g_pFileSystem, a2: v9, a3: "%s,", v25);
    g_pFileSystem->FPrintf(this: g_pFileSystem, a2: v9, a3: "%d,", gpu_level.m_pConVarState->m_Value.m_nValue);
    g_pFileSystem->FPrintf(this: g_pFileSystem, a2: v9, a3: "%d,", cpu_level.m_pConVarState->m_Value.m_nValue);
    g_pFileSystem->FPrintf(this: g_pFileSystem, a2: v9, a3: "%s,", dateString.m_szBuf);
    g_pFileSystem->FPrintf(this: g_pFileSystem, a2: v9, a3: "\n");
    g_pFileSystem->Close(this: &g_pFileSystem->IBaseFileSystem, a2: v9);
    v10->EndRender(this: v10);
    v10->Release(this: v10);
  }
  else
  {
    _Warning(a1: "DEMO: Failed to open %s!\n", fileName.m_szBuf);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10074BD0
// Name: public: virtual void CDemoPlayer::StopPlayback(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDemoPlayer::StopPlayback(CDemoPlayer *this)
{
  int v2; // ecx
  int v3; // edi
  long double v4; // st6
  vgui::CTreeViewListControl *v5; // ecx
  ECommandTarget_t TraceType; // eax
  unsigned __int8 *data; // [esp+14h] [ebp-10h]

  if ( this->IsPlayingBack(this) )
  {
    demoaction->StopPlaying(this: demoaction);
    CDemoFile::Close(this: &this->m_DemoFile);
    *(_WORD *)&this->m_bPlayingBack = 0;
    this->m_flAutoResumeTime = 0.0;
    if ( this->m_bTimeDemo )
    {
      CEngineStats::EndRun(this: &g_EngineStats);
      if ( s_bBenchframe )
        CLoaderMemAlloc::CrtIsValidPointer(this: (ConVar *)&mat_norendering.IConVar, value: 0);
      else
        CDemoPlayer::WriteTimeDemoResults(this);
      this->m_bTimeDemo = false;
    }
    else
    {
      v3 = host_framecount - this->m_nTimeDemoStartFrame;
      v4 = _Plat_FloatTime(a1: v2) - this->m_flTimeDemoStartTime;
      if ( v4 > 0.0 )
        DevMsg(
          a1: "Demo playback finished ( %.1f seconds, %i render frames, %.2f fps).\n",
          (double)v4,
          v3,
          (double)((double)v3 / v4));
    }
    data = this->m_DemoPacket.data;
    this->m_flPlaybackRateModifier = 1.0;
    free(pMem: data);
    this->m_DemoPacket.data = nullptr;
    scr_demo_override_fov = 0.0;
    if ( demo_quitafterplayback.m_pParent != nullptr && demo_quitafterplayback.m_pParent->m_Value.m_nValue != 0 )
    {
      TraceType = CTraceFilter::GetTraceType(this: v5);
      Cbuf_AddText(eTarget: TraceType, pText: "quit\n", nTickDelay: 0);
    }
    g_ClientDLL->OnDemoPlaybackStop(this: g_ClientDLL);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10074D00
// Name: public: bool CDemoPlayer::ParseAheadForInterval(int,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDemoPlayer::ParseAheadForInterval(CDemoPlayer *this, int curtick, int intervalticks)
{
  CDemoPlayer *v3; // esi
  int v4; // ecx
  float *p_z; // eax
  CDemoFile *p_m_DemoFile; // ebx
  DemoCommandQueue *m_pMemory; // eax
  int v8; // eax
  int CurPos; // edi
  int m_Size; // eax
  int v11; // ecx
  int *p_filepos; // edi
  int v13; // edi
  int m_nAllocationCount; // eax
  DemoCommandQueue *v15; // ecx
  int v16; // eax
  DemoCommandQueue *v17; // edi
  democmdinfo_t nextinfo; // [esp+0h] [ebp-150h] BYREF
  DemoCommandQueue entry; // [esp+98h] [ebp-B8h] BYREF
  CDemoPlayer *v21; // [esp+138h] [ebp-18h]
  int dummy; // [esp+13Ch] [ebp-14h] BYREF
  int starting_position; // [esp+140h] [ebp-10h]
  int tick; // [esp+144h] [ebp-Ch] BYREF
  int nPlayerSlot; // [esp+148h] [ebp-8h] BYREF
  unsigned __int8 cmd; // [esp+14Fh] [ebp-1h] BYREF

  v3 = this;
  v21 = this;
  tick = 0;
  cmd = 7;
  v4 = 1;
  p_z = &nextinfo.u[0].viewOrigin.z;
  do
  {
    *(p_z - 3) = 0.0;
    *(p_z - 2) = 0.0;
    *(p_z - 1) = 0.0;
    *p_z = 0.0;
    p_z[1] = 0.0;
    p_z[2] = 0.0;
    p_z[3] = 0.0;
    p_z[4] = 0.0;
    p_z[5] = 0.0;
    p_z[6] = 0.0;
    p_z[7] = 0.0;
    p_z[8] = 0.0;
    p_z[9] = 0.0;
    p_z[10] = 0.0;
    p_z[11] = 0.0;
    p_z[12] = 0.0;
    p_z[13] = 0.0;
    p_z[14] = 0.0;
    p_z[15] = 0.0;
    p_z += 19;
    --v4;
  }
  while ( v4 >= 0 );
  p_m_DemoFile = &v3->m_DemoFile;
  starting_position = CDemoFile::GetCurPos(this: &v3->m_DemoFile, bRead: true);
  if ( v3->m_DestCmdInfo.m_Size > 0 )
  {
    nPlayerSlot = curtick - 32;
    do
    {
      m_pMemory = v3->m_DestCmdInfo.m_Memory.m_pMemory;
      if ( m_pMemory->tick >= nPlayerSlot || m_pMemory->filepos >= starting_position )
        break;
      v8 = v3->m_DestCmdInfo.m_Size - 1;
      if ( v8 > 0 )
        _V_memmove(
          dest: v3->m_DestCmdInfo.m_Memory.m_pMemory,
          src: &v3->m_DestCmdInfo.m_Memory.m_pMemory[1],
          count: 160 * v8);
      --v3->m_DestCmdInfo.m_Size;
    }
    while ( v3->m_DestCmdInfo.m_Size > 0 );
  }
  if ( v3->m_bTimeDemo )
    return 0;
  do
  {
    while ( 2 )
    {
      nPlayerSlot = 0;
      CDemoFile::ReadCmdHeader(this: p_m_DemoFile, &cmd, &tick, &nPlayerSlot);
      switch ( cmd )
      {
        case 3u:
        case 7u:
          CDemoFile::SeekTo(this: p_m_DemoFile, position: starting_position, bRead: true);
          return 0;
        case 4u:
          CDemoFile::ReadConsoleCommand(this: p_m_DemoFile);
          continue;
        case 5u:
          CDemoFile::ReadUserCmd(this: p_m_DemoFile, buffer: nullptr, size: &dummy);
          continue;
        case 6u:
        case 9u:
          CDemoFile::ReadStringTables(this: p_m_DemoFile, buf: nullptr);
          continue;
        case 8u:
          CDemoFile::ReadCustomData(this: p_m_DemoFile, pCallbackIndex: nullptr, ppDataChunk: nullptr);
          continue;
        default:
          CurPos = CDemoFile::GetCurPos(this: p_m_DemoFile, bRead: true);
          nPlayerSlot = CurPos;
          CDemoFile::ReadCmdInfo(this: p_m_DemoFile, info: &nextinfo);
          CDemoFile::ReadSequenceInfo(this: p_m_DemoFile, nSeqNrIn: &dummy, nSeqNrOut: &dummy);
          CDemoFile::ReadRawData(this: p_m_DemoFile, buffer: nullptr, length: 0);
          DemoCommandQueue::DemoCommandQueue(this: &entry);
          democmdinfo_t::operator=(this: &entry.info, __that: &nextinfo);
          m_Size = v3->m_DestCmdInfo.m_Size;
          v11 = 0;
          entry.tick = tick;
          entry.filepos = CurPos;
          if ( m_Size <= 0 )
            goto LABEL_24;
          p_filepos = &v3->m_DestCmdInfo.m_Memory.m_pMemory->filepos;
          break;
      }
      break;
    }
    while ( *p_filepos != nPlayerSlot )
    {
      ++v11;
      p_filepos += 40;
      if ( v11 >= m_Size )
        goto LABEL_22;
    }
    if ( v11 < m_Size )
      continue;
LABEL_22:
    if ( v3->m_DestCmdInfo.m_Memory.m_pMemory[m_Size - 1].tick > tick )
      v3->m_DestCmdInfo.m_Size = 0;
LABEL_24:
    v13 = v3->m_DestCmdInfo.m_Size;
    m_nAllocationCount = v3->m_DestCmdInfo.m_Memory.m_nAllocationCount;
    if ( v13 + 1 > m_nAllocationCount )
      CUtlMemory<DemoCommandQueue,int>::Grow(this: &v3->m_DestCmdInfo.m_Memory, num: v13 - m_nAllocationCount + 1);
    ++v3->m_DestCmdInfo.m_Size;
    v15 = v3->m_DestCmdInfo.m_Memory.m_pMemory;
    v16 = v3->m_DestCmdInfo.m_Size - v13 - 1;
    v3->m_DestCmdInfo.m_pElements = v15;
    if ( v16 > 0 )
      _V_memmove(dest: &v15[v13 + 1], src: &v15[v13], count: 160 * v16);
    v17 = &v3->m_DestCmdInfo.m_Memory.m_pMemory[v13];
    if ( v17 != nullptr )
      *v17 = entry;
    v3 = v21;
  }
  while ( tick - curtick <= intervalticks );
  CDemoFile::SeekTo(this: p_m_DemoFile, position: starting_position, bRead: true);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100751A0
// Name: public: virtual struct netpacket_s __near * CDemoPlayer::ReadPacket(void)
// Source: json
//------------------------------------------------------------------------------
netpacket_s *__usercall CDemoPlayer::ReadPacket@<eax>(CDemoPlayer *this@<ecx>, int a2@<ebx>, const void *a3@<esi>)
{
  CDemoPlayer *v3; // edi
  unsigned __int8 v5; // al
  int v6; // ebx
  bool v7; // zf
  int v8; // edx
  int m_nSkipToTick; // eax
  vgui::CTreeViewListControl *v10; // ecx
  const char *ConsoleCommand; // esi
  ECommandTarget_t TraceType; // eax
  const void *v13; // ebx
  int v14; // esi
  int v15; // eax
  int v16; // esi
  CUtlVector<DemoCustomDataCallbackMapping_t,CUtlMemory<DemoCustomDataCallbackMapping_t,int> > *p_m_CustomDataCallbackMap; // ebx
  int v18; // edi
  unsigned __int8 *v19; // esi
  unsigned __int8 *v20; // ecx
  int v21; // esi
  const char *pszValue; // ecx
  const char *v23; // eax
  int v24; // ecx
  const char *v25; // eax
  CClientState *v26; // eax
  int RawData; // esi
  unsigned __int8 *data; // edx
  int v29; // eax
  char v30; // al
  bool v31; // sf
  int v32; // ecx
  const char *m_SnapshotFilename; // ecx
  vgui::CTreeViewListControl *v34; // ecx
  ECommandTarget_t v35; // eax
  CClientState *BaseLocalClient; // eax
  int v37; // [esp+0h] [ebp-160h]
  const char *v38; // [esp+0h] [ebp-160h]
  int v39; // [esp+0h] [ebp-160h]
  char buffer[256]; // [esp+10h] [ebp-150h] BYREF
  int outseqack; // [esp+110h] [ebp-50h] BYREF
  int iCallbackIndex; // [esp+114h] [ebp-4Ch] BYREF
  int inseq; // [esp+118h] [ebp-48h] BYREF
  CDemoPlayer *v46; // [esp+11Ch] [ebp-44h]
  bf_read msg; // [esp+120h] [ebp-40h] BYREF
  unsigned __int8 *pParse; // [esp+144h] [ebp-1Ch]
  int nPlayerSlot; // [esp+148h] [ebp-18h] BYREF
  int length; // [esp+14Ch] [ebp-14h] BYREF
  unsigned __int8 *pData; // [esp+150h] [ebp-10h] BYREF
  int curpos; // [esp+154h] [ebp-Ch]
  int tick; // [esp+158h] [ebp-8h] BYREF
  unsigned __int8 cmd; // [esp+15Fh] [ebp-1h] BYREF

  v3 = this;
  v46 = this;
  tick = 0;
  cmd = 1;
  if ( !CDemoFile::IsOpen(this: &this->m_DemoFile) )
  {
    v3->m_bPlayingBack = false;
    Host_EndGame(bShowMainMenu: true, message: "Tried to read a demo message with no demo file\n");
    return nullptr;
  }
  if ( HostState_IsGameShuttingDown() || CDemoPlayer::CheckPausedPlayback(this: v3) )
    return nullptr;
  while ( 1 )
  {
LABEL_6:
    curpos = CDemoFile::GetCurPos(this: &v3->m_DemoFile, bRead: true);
    nPlayerSlot = 0;
    CDemoFile::ReadCmdHeader(this: &v3->m_DemoFile, &cmd, &tick, &nPlayerSlot);
    v5 = cmd;
    if ( cmd != 1 && cmd != 7 && cmd != 3 && cmd != 6 && cmd != 9 )
    {
      v6 = v3->GetPlaybackTick(this: v3);
      if ( v3->m_bTimeDemo )
      {
        v7 = v3->m_nTimeDemoCurrentFrame == host_framecount;
      }
      else
      {
        if ( GetBaseLocalClient()->m_nSignonState != 6 || tick <= v6 )
          goto LABEL_17;
        v7 = !v3->IsSkipping(this: v3);
      }
      if ( v7 )
        break;
LABEL_17:
      v5 = cmd;
    }
    switch ( v5 )
    {
      case 3u:
        if ( demo_debug.m_pParent != nullptr && demo_debug.m_pParent->m_Value.m_nValue != 0 )
          _Msg(a1: "%d dem_synctick\n", tick);
        v8 = host_tickcount;
        v3->m_nPreviousTick = host_tickcount;
        m_nSkipToTick = v3->m_nSkipToTick;
        v3->m_nStartTick = v8;
        if ( m_nSkipToTick != -1 && (m_nSkipToTick & 0x88000000) == 0x88000000 )
          v3->m_nSkipToTick = m_nSkipToTick & 0x77FFFFFF;
        continue;
      case 4u:
        ConsoleCommand = CDemoFile::ReadConsoleCommand(this: &v3->m_DemoFile);
        if ( demo_debug.m_pParent != nullptr && demo_debug.m_pParent->m_Value.m_nValue != 0 )
          _Msg(a1: "%d dem_consolecmd [%s]\n", tick, ConsoleCommand);
        TraceType = CTraceFilter::GetTraceType(this: v10);
        Cbuf_AddText(eTarget: TraceType, pText: ConsoleCommand, nTickDelay: 0);
        Cbuf_Execute();
        continue;
      case 5u:
        if ( demo_debug.m_pParent != nullptr && demo_debug.m_pParent->m_Value.m_nValue != 0 )
          _Msg(a1: "%d dem_usercmd\n", tick);
        length = 256;
        v14 = CDemoFile::ReadUserCmd(this: &v3->m_DemoFile, buffer, size: &length);
        msg.m_bOverflow = false;
        msg.m_nDataBits = -1;
        msg.m_nDataBytes = 0;
        msg.m_pDebugName = "CDemo::ReadUserCmd";
        CBitRead::StartReading(this: &msg, pData: buffer, nBytes: length, iStartBit: 0, nBits: -1);
        g_ClientDLL->DecodeUserCmdFromBuffer(this: g_ClientDLL, a2: nPlayerSlot, a3: &msg, a4: v14);
        GetBaseLocalClient()->lastoutgoingcommand = v14;
        continue;
      case 6u:
        if ( demo_debug.m_pParent != nullptr && demo_debug.m_pParent->m_Value.m_nValue != 0 )
          _Msg(a1: "%d dem_datatables\n", tick);
        v13 = (const void *)((int (__thiscall *)(IMemAlloc *, int, const void *))_g_pMemAlloc->Alloc_2)(
                              a1: _g_pMemAlloc,
                              a2: 0x200000,
                              a3);
        msg.m_bOverflow = false;
        msg.m_nDataBits = -1;
        msg.m_nDataBytes = 0;
        msg.m_pDebugName = "dem_datatables";
        CBitRead::StartReading(this: &msg, pData: v13, nBytes: 0x200000, iStartBit: 0, nBits: -1);
        CDemoFile::ReadStringTables(this: &v3->m_DemoFile, buf: &msg);
        CBitRead::Seek(this: &msg, nPosition: 0);
        if ( !DataTable_LoadDataTablesFromBuffer(pBuf: &msg, nDemoProtocol: v3->m_DemoFile.m_DemoHeader.demoprotocol) )
          Host_Error(error: "Error parsing network data tables during demo playback.");
        goto LABEL_34;
      case 7u:
        if ( demo_debug.m_pParent != nullptr && demo_debug.m_pParent->m_Value.m_nValue != 0 )
          _Msg(a1: "%d dem_stop\n", tick);
        BaseLocalClient = GetBaseLocalClient();
        BaseLocalClient->Disconnect(this: BaseLocalClient, a2: true);
        return nullptr;
      case 8u:
        v15 = CDemoFile::ReadCustomData(this: &v3->m_DemoFile, pCallbackIndex: &iCallbackIndex, ppDataChunk: &pData);
        if ( iCallbackIndex == -1 )
        {
          v16 = *(_DWORD *)pData;
          p_m_CustomDataCallbackMap = &v3->m_CustomDataCallbackMap;
          v37 = *(_DWORD *)pData;
          pParse = pData + 4;
          CUtlVector<DemoCustomDataCallbackMapping_t,CUtlMemory<DemoCustomDataCallbackMapping_t,int>>::SetSize(
            this: &v3->m_CustomDataCallbackMap,
            size: v37);
          if ( v16 == 0 )
            continue;
          v18 = 0;
          curpos = v16;
          while ( 1 )
          {
            v19 = pParse;
            CUtlString::operator=(
              this: &p_m_CustomDataCallbackMap->m_Memory.m_pMemory[v18].name,
              src: (const char *)pParse);
            v20 = &v19[_V_strlen(str: (const char *)v19) + 1];
            v21 = 0;
            pParse = v20;
            if ( g_RegisteredDemoCustomDataCallbacks.m_Size != 0 )
            {
              while ( 1 )
              {
                pszValue = g_RegisteredDemoCustomDataCallbacks.m_Memory.m_pMemory[v21].szSaveID.pszValue;
                if ( pszValue == nullptr )
                  pszValue = defaultValue;
                v38 = pszValue;
                v23 = CUtlString::Get(this: &p_m_CustomDataCallbackMap->m_Memory.m_pMemory[v18].name);
                if ( _V_stricmp(s1: v23, s2: v38) == 0 )
                  break;
                if ( ++v21 == g_RegisteredDemoCustomDataCallbacks.m_Size )
                  goto LABEL_52;
              }
              p_m_CustomDataCallbackMap->m_Memory.m_pMemory[v18].pCallback = g_RegisteredDemoCustomDataCallbacks.m_Memory.m_pMemory[v21].pCallback;
            }
LABEL_52:
            ++v18;
            if ( --curpos == 0 )
            {
              v3 = v46;
              goto LABEL_6;
            }
          }
        }
        v24 = (int)&v3->m_CustomDataCallbackMap.m_Memory.m_pMemory[iCallbackIndex];
        if ( *(_DWORD *)v24 != 0 )
        {
          (*(void (__cdecl **)(unsigned __int8 *, int))v24)(a1: pData, a2: v15);
        }
        else
        {
          v25 = CUtlString::Get(this: (CUtlString *)(v24 + 4));
          _Warning(a1: "Unable to decode custom demo data, callback \"%s\" not found.\n", v25);
        }
        break;
      case 9u:
        v13 = (const void *)((int (__thiscall *)(IMemAlloc *, int, const void *))_g_pMemAlloc->Alloc_2)(
                              a1: _g_pMemAlloc,
                              a2: 0x200000,
                              a3);
        msg.m_bOverflow = false;
        msg.m_nDataBits = -1;
        msg.m_nDataBytes = 0;
        msg.m_pDebugName = "dem_stringtables";
        CBitRead::StartReading(this: &msg, pData: v13, nBytes: 0x200000, iStartBit: 0, nBits: -1);
        CDemoFile::ReadStringTables(this: &v3->m_DemoFile, buf: &msg);
        CBitRead::Seek(this: &msg, nPosition: 0);
        if ( CNetworkStringTableContainer::ReadStringTables(this: networkStringTableContainerClient, buf: &msg) == 0 )
          Host_Error(error: "Error parsing string tables during demo playback.");
LABEL_34:
        a3 = v13;
        ((void (__thiscall *)(IMemAlloc *))_g_pMemAlloc->Free_2)(a1: _g_pMemAlloc);
        continue;
      default:
        if ( ((unsigned __int8 (__thiscall *)(CDemoPlayer *, const void *, int))v3->IsSkipping)(a1: v3, a2: a3, a3: a2) != 0 )
          v3->m_nStartTick = host_tickcount - tick;
        if ( cmd == 2 )
          v3->m_nTimeDemoCurrentFrame = host_framecount;
        CDemoFile::ReadCmdInfo(this: &v3->m_DemoFile, info: &v3->m_LastCmdInfo);
        CDemoFile::ReadSequenceInfo(this: &v3->m_DemoFile, nSeqNrIn: &inseq, nSeqNrOut: &outseqack);
        v26 = GetBaseLocalClient();
        ((void (__thiscall *)(INetChannel *, _DWORD))v26->m_NetChannel->SetSequenceData)(a1: v26->m_NetChannel, a2: 0);
        RawData = CDemoFile::ReadRawData(this: &v3->m_DemoFile, buffer: (char *)v3->m_DemoPacket.data, length: 96000);
        if ( demo_debug.m_pParent != nullptr && demo_debug.m_pParent->m_Value.m_nValue != 0 )
          _Msg(a1: "%d network packet [%d]\n", tick, RawData);
        if ( RawData > 0 )
        {
          data = v3->m_DemoPacket.data;
          v3->m_DemoPacket.received = realtime;
          v3->m_DemoPacket.size = RawData;
          CBitRead::StartReading(this: &v3->m_DemoPacket.message, pData: data, nBytes: RawData, iStartBit: 0, nBits: -1);
          if ( demo_debug.m_pParent != nullptr && demo_debug.m_pParent->m_Value.m_nValue >= 1 )
          {
            v29 = ((int (__thiscall *)(CDemoPlayer *, int))v3->GetPlaybackTick)(a1: v3, a2: RawData);
            _Msg(a1: "Demo message, tick %i, %i bytes\n", v29, v39);
          }
        }
        v30 = CDemoPlayer::ParseAheadForInterval(this: v3, curtick: tick, intervalticks: 8);
        v31 = v3->m_nTimeDemoStartFrame < 0;
        v3->m_bInterpolateView = v30;
        if ( v31 && v3->GetPlaybackTick(this: v3) > 100 )
        {
          v32 = host_framecount;
          v3->m_nTimeDemoStartFrame = host_framecount;
          v3->m_flTimeDemoStartTime = _Plat_FloatTime(a1: v32);
          v7 = !v3->m_bTimeDemo;
          v3->m_flTotalFPSVariability = 0.0;
          if ( !v7 )
            CEngineStats::BeginRun(this: &g_EngineStats);
        }
        if ( v3->m_nSnapshotTick > 0 && v3->m_nSnapshotTick <= v3->GetPlaybackTick(this: v3) )
        {
          m_SnapshotFilename = "benchframe";
          if ( v3->m_SnapshotFilename[0] != 0 )
            m_SnapshotFilename = v3->m_SnapshotFilename;
          CL_TakeScreenshot(name: m_SnapshotFilename);
          v7 = !s_bBenchframe;
          v3->m_nSnapshotTick = 0;
          if ( !v7 )
          {
            v35 = CTraceFilter::GetTraceType(this: v34);
            Cbuf_AddText(eTarget: v35, pText: "stopdemo\n", nTickDelay: 0);
          }
        }
        return &v3->m_DemoPacket;
    }
  }
  ((void (__stdcall *)(_DWORD, int, _DWORD))demoaction->Update)(
    a1: 0,
    a2: v6,
    a3: (float)v6 * host_state.interval_per_tick);
  CDemoFile::SeekTo(this: &v3->m_DemoFile, position: curpos, bRead: true);
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10075880
// Name: public: CDemoPlayer::CDemoPlayer(void)
// Source: json
//------------------------------------------------------------------------------
CDemoPlayer *__thiscall CDemoPlayer::CDemoPlayer(CDemoPlayer *this)
{
  democmdinfo_t *p_m_LastCmdInfo; // ecx
  int v3; // edi
  float *p_z; // eax

  this->__vftable = (CDemoPlayer_vtbl *)&CDemoPlayer::`vftable';
  CDemoFile::CDemoFile(this: &this->m_DemoFile);
  netadr_s::SetIP(this: &this->m_DemoPacket.from, unIP: 0);
  netadr_s::SetPort(this: &this->m_DemoPacket.from, newport: 0);
  netadr_s::SetType(this: &this->m_DemoPacket.from, newtype: NA_IP);
  this->m_DemoPacket.message.m_bOverflow = false;
  this->m_DemoPacket.message.m_pDebugName = nullptr;
  this->m_DemoPacket.message.m_nDataBytes = 0;
  this->m_DemoPacket.message.m_nDataBits = -1;
  p_m_LastCmdInfo = &this->m_LastCmdInfo;
  this->m_DestCmdInfo.m_Memory.m_pMemory = nullptr;
  this->m_DestCmdInfo.m_Memory.m_nAllocationCount = 0;
  this->m_DestCmdInfo.m_Memory.m_nGrowSize = 0;
  this->m_DestCmdInfo.m_Size = 0;
  this->m_DestCmdInfo.m_pElements = nullptr;
  v3 = 1;
  p_z = &this->m_LastCmdInfo.u[0].viewOrigin.z;
  do
  {
    p_m_LastCmdInfo->u[0].flags = 0;
    *(p_z - 2) = 0.0;
    *(p_z - 1) = 0.0;
    *p_z = 0.0;
    p_z[1] = 0.0;
    p_z[2] = 0.0;
    p_z[3] = 0.0;
    p_z[4] = 0.0;
    p_z[5] = 0.0;
    p_z[6] = 0.0;
    p_z[7] = 0.0;
    p_z[8] = 0.0;
    p_z[9] = 0.0;
    p_z[10] = 0.0;
    p_z[11] = 0.0;
    p_z[12] = 0.0;
    p_z[13] = 0.0;
    p_z[14] = 0.0;
    p_z[15] = 0.0;
    p_m_LastCmdInfo = (democmdinfo_t *)((char *)p_m_LastCmdInfo + 76);
    p_z += 19;
    --v3;
  }
  while ( v3 >= 0 );
  this->m_CustomDataCallbackMap.m_Memory.m_pMemory = nullptr;
  this->m_CustomDataCallbackMap.m_Memory.m_nAllocationCount = 0;
  this->m_CustomDataCallbackMap.m_Memory.m_nGrowSize = 0;
  this->m_CustomDataCallbackMap.m_Size = 0;
  this->m_CustomDataCallbackMap.m_pElements = nullptr;
  this->m_flTimeDemoStartTime = 0.0;
  *(_WORD *)&this->m_bPlayingBack = 0;
  this->m_nSnapshotTick = 0;
  this->m_SnapshotFilename[0] = 0;
  *(_WORD *)&this->m_bResetInterpolation = 0;
  this->m_nPreviousTick = 0;
  this->m_flAutoResumeTime = 0.0;
  this->m_flPlaybackRateModifier = 1.0;
  this->m_nTimeDemoStartFrame = -1;
  this->m_flTotalFPSVariability = 0.0;
  this->m_nTimeDemoCurrentFrame = -1;
  this->m_nSkipToTick = -1;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10170530
// Name: public: ICvar::Iterator::~Iterator(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ICvar::Iterator::~Iterator(ICvar::Iterator *this)
{
  free(pMem: this->m_pIter);
}

} // namespace engine_xlsp
