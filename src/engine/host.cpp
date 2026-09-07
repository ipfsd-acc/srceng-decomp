// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: engine/host.cpp
// Functions: 180
// ============================================================

#include "engine\host.h"

//------------------------------------------------------------------------------
// Address: 0x10014150
// Name: public: virtual int CRefCounted1<class CFunctor,class CRefCountServiceBase<1,class CRefMT>>::AddRef(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>::AddRef(
        CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT> > *this)
{
  return _InterlockedIncrement(&this->m_iRefs);
}

//------------------------------------------------------------------------------
// Address: 0x10014160
// Name: public: virtual int CRefCounted1<class CFunctor,class CRefCountServiceBase<1,class CRefMT>>::Release(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>::Release(
        CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT> > *this)
{
  CRefCountServiceBase<1,CRefMT> *v1; // esi
  int result; // eax

  v1 = &this->CRefCountServiceBase<1,CRefMT>;
  result = _InterlockedDecrement(&this->m_iRefs);
  if ( result == 0 )
  {
    if ( v1->OnFinalRelease(this: v1) )
      ((void (__thiscall *)(CRefCountServiceBase<1,CRefMT> *, int))v1->dtr_CRefCountServiceBase<1,CRefMT>)(
        a1: v1,
        a2: 1);
    return 0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100D73A0
// Name: public: virtual int CRefCounted1<class IRefCounted,class CRefCountServiceBase<1,class CRefMT>>::AddRef(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CRefCounted1<IRefCounted,CRefCountServiceBase<1,CRefMT>>::AddRef(
        CRefCounted1<IWorldRenderList,CRefCountServiceBase<1,CRefMT> > *this)
{
  return _InterlockedIncrement(&this->m_iRefs);
}

//------------------------------------------------------------------------------
// Address: 0x100D73B0
// Name: public: virtual int CRefCounted1<class IWorldRenderList,class CRefCountServiceBase<1,class CRefMT>>::Release(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CRefCounted1<IWorldRenderList,CRefCountServiceBase<1,CRefMT>>::Release(
        CRefCounted1<IWorldRenderList,CRefCountServiceBase<1,CRefMT> > *this)
{
  CRefCountServiceBase<1,CRefMT> *v1; // esi
  int result; // eax

  v1 = &this->CRefCountServiceBase<1,CRefMT>;
  result = _InterlockedDecrement(&this->m_iRefs);
  if ( result == 0 )
  {
    if ( v1->OnFinalRelease(this: v1) )
      ((void (__thiscall *)(CRefCountServiceBase<1,CRefMT> *, int))v1->dtr_CRefCountServiceBase<1,CRefMT>)(
        a1: v1,
        a2: 1);
    return 0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10183F90
// Name: public: static void CClockSpeedInit::Init(void)
// Source: json
//------------------------------------------------------------------------------
// write access to const memory has been detected, the output may be wrong!
static void __cdecl CClockSpeedInit::Init()
{
  int CPUInformation; // eax

  CPUInformation = _GetCPUInformation();
  LODWORD(_g_ClockSpeed) = *(_DWORD *)(CPUInformation + 8);
  HIDWORD(_g_ClockSpeed) = *(_DWORD *)(CPUInformation + 12);
  _g_dwClockSpeed = _g_ClockSpeed;
  _g_ClockSpeedMicrosecondsMultiplier = 1000000.0 / (double)__PAIR64__(HIDWORD(_g_ClockSpeed), _g_ClockSpeed);
  _g_ClockSpeedMillisecondsMultiplier = 1000.0 / (double)__PAIR64__(HIDWORD(_g_ClockSpeed), _g_ClockSpeed);
  _g_ClockSpeedSecondsMultiplier = 1.0 / (double)__PAIR64__(HIDWORD(_g_ClockSpeed), _g_ClockSpeed);
}

//------------------------------------------------------------------------------
// Address: 0x10184080
// Name: float Host_GetServerSimulationFrameTime(void)
// Source: json
//------------------------------------------------------------------------------
double __cdecl Host_GetServerSimulationFrameTime()
{
  return g_HostTimes.m_flLastServerTime;
}

//------------------------------------------------------------------------------
// Address: 0x10184090
// Name: mem_dump
// Source: json
//------------------------------------------------------------------------------
void __cdecl mem_dump()
{
  char *m_szMapname; // eax

  ConMsg(a1: "Writing memory stats to file memstats.txt\n");
  m_szMapname = sv.m_szMapname;
  if ( sv.m_szMapname[0] == 0 )
    m_szMapname = "nomap";
  V_FileBase(in: m_szMapname, out: mapname, maxlen: 256);
  Host_PrintMemoryStatus(mapname: mapname);
  _g_pMemAlloc->DumpStatsFileBase(this: _g_pMemAlloc, a2: mapname);
}

//------------------------------------------------------------------------------
// Address: 0x101840F0
// Name: mem_compact
// Source: json
//------------------------------------------------------------------------------
void __cdecl mem_compact()
{
  _g_pMemAlloc->CompactHeap(this: _g_pMemAlloc);
}

//------------------------------------------------------------------------------
// Address: 0x10184100
// Name: mem_incremental_compact
// Source: json
//------------------------------------------------------------------------------
void __cdecl mem_incremental_compact()
{
  _g_pMemAlloc->CompactIncremental(this: _g_pMemAlloc);
}

//------------------------------------------------------------------------------
// Address: 0x10184120
// Name: mem_eat
// Source: json
//------------------------------------------------------------------------------
void __cdecl mem_eat()
{
  _g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 0x100000u);
}

//------------------------------------------------------------------------------
// Address: 0x10184140
// Name: thread_test_tslist
// Source: json
//------------------------------------------------------------------------------
void __cdecl thread_test_tslist(const CCommand *args)
{
  int v1; // edi
  const char *v2; // eax
  const char *v3; // eax
  int v4; // eax

  if ( args->m_nArgc == 1 )
  {
    v1 = 1;
  }
  else
  {
    v2 = defaultValue;
    if ( args->m_nArgc > 1 )
      v2 = args->m_ppArgv[1];
    v1 = atoi(nptr: v2);
  }
  if ( args->m_nArgc == 2 )
  {
    _RunTSListTests(a1: v1, a2: 1);
  }
  else
  {
    v3 = defaultValue;
    if ( args->m_nArgc > 2 )
      v3 = args->m_ppArgv[2];
    v4 = atoi(nptr: v3);
    _RunTSListTests(a1: v1, a2: v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101841B0
// Name: thread_test_tsqueue
// Source: json
//------------------------------------------------------------------------------
void __cdecl thread_test_tsqueue(const CCommand *args)
{
  int v1; // edi
  const char *v2; // eax
  const char *v3; // esi
  int v4; // eax

  if ( args->m_nArgc >= 2 )
  {
    v2 = defaultValue;
    if ( args->m_nArgc > 1 )
      v2 = args->m_ppArgv[1];
    v1 = atoi(nptr: v2);
  }
  else
  {
    v1 = 10000;
  }
  if ( args->m_nArgc >= 3 )
  {
    if ( args->m_nArgc > 2 )
      v3 = args->m_ppArgv[2];
    else
      v3 = defaultValue;
    v4 = atoi(nptr: v3);
    _RunTSQueueTests(a1: v1, a2: v4);
  }
  else
  {
    _RunTSQueueTests(a1: v1, a2: 1);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10184230
// Name: threadpool_run_tests
// Source: json
//------------------------------------------------------------------------------
void __cdecl threadpool_run_tests(const CCommand *args)
{
  int m_nArgc; // eax
  const char *v2; // eax
  int i; // esi

  m_nArgc = args->m_nArgc;
  if ( args->m_nArgc != 1 )
  {
    v2 = defaultValue;
    if ( args->m_nArgc > 1 )
      v2 = args->m_ppArgv[1];
    m_nArgc = atoi(nptr: v2);
  }
  if ( m_nArgc > 0 )
  {
    for ( i = m_nArgc; i != 0; --i )
      _RunThreadPoolTests();
  }
}

//------------------------------------------------------------------------------
// Address: 0x10184270
// Name: public: struct AudioState_t const __near & CAudioState::GetPerUser(int)const
// Source: json
//------------------------------------------------------------------------------
CAudioState *__thiscall CAudioState::GetPerUser(CAudioState *this, int nSlot)
{
  CAudioState *result; // eax

  result = this;
  if ( nSlot != -1 )
    return (CAudioState *)((char *)this + 28 * nSlot);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10184290
// Name: display_elapsedtime
// Source: json
//------------------------------------------------------------------------------
void __cdecl display_elapsedtime()
{
  _Msg(a1: "Elapsed time: %.2f\n", realtime);
}

//------------------------------------------------------------------------------
// Address: 0x101842B0
// Name: public: void CCommonHostState::SetWorldModel(struct model_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCommonHostState::SetWorldModel(CCommonHostState *this, model_t *pModel)
{
  if ( this->worldmodel != pModel )
  {
    this->worldmodel = pModel;
    if ( pModel != nullptr )
      this->worldbrush = pModel->brush.pShared;
    else
      this->worldbrush = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101842E0
// Name: void Host_SetAudioState(struct AudioState_t const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Host_SetAudioState(const AudioState_t *audioState)
{
  s_AudioState.m_PerUser[0] = *audioState;
}

//------------------------------------------------------------------------------
// Address: 0x10184300
// Name: bool Host_IsLocalServer(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall Host_IsLocalServer(CEngineClient *this)
{
  return sv.m_State >= ss_active;
}

//------------------------------------------------------------------------------
// Address: 0x10184310
// Name: bool Host_IsSinglePlayerGame(void)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl Host_IsSinglePlayerGame()
{
  if ( sv.m_State < ss_active )
    return GetBaseLocalClient()->m_nMaxClients == 1;
  else
    return sv.m_nMaxclients <= 1;
}

//------------------------------------------------------------------------------
// Address: 0x10184340
// Name: void Host_EndGame(bool,char const __near *,...)
// Source: json
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x10184410
// Name: void Host_Error(char const __near *,...)
// Source: json
//------------------------------------------------------------------------------
void Host_Error(const char *error, ...)
{
  char string[1024]; // [esp+0h] [ebp-400h] BYREF
  va_list params; // [esp+40Ch] [ebp+Ch] BYREF

  va_start(params, error);
  if ( inerror )
    Sys_Error(error: "Host_Error: recursively entered");
  inerror = true;
  V_vsnprintf(pDest: string, maxLen: 1024, pFormat: error, params);
  if ( sv.m_bIsDedicated )
  {
    Sys_Error(error: "Host_Error: %s\n", string);
  }
  else
  {
    SCR_EndLoadingPlaque();
    ConMsg(a1: "\nHost_Error: %s\n\n", string);
    Host_Disconnect(bShowMainMenu: true);
    GetBaseLocalClient()->demonum = -1;
    inerror = false;
    if ( g_bAbortServerSet )
      longjmp(Buf: host_abortserver, Value: 1);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101844C0
// Name: void UseDefaultBindings(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl UseDefaultBindings()
{
  void *v0; // esi
  unsigned int v1; // edi
  void *v2; // ebx
  const char *i; // esi
  const char *v4; // esi
  ButtonCode_t v5; // eax
  char token[1024]; // [esp+4h] [ebp-608h] BYREF
  char szFileName[260]; // [esp+404h] [ebp-208h] BYREF
  char szKeyName[260]; // [esp+508h] [ebp-104h] BYREF

  V_snprintf(pDest: szFileName, maxLen: 260, pFormat: "%skb_def.lst", "scripts/");
  v0 = g_pFileSystem->Open(this: &g_pFileSystem->IBaseFileSystem, a2: szFileName, a3: "r", a4: 0);
  if ( v0 != nullptr )
  {
    v1 = g_pFileSystem->Size_2(this: &g_pFileSystem->IBaseFileSystem, a2: v0);
    v2 = MemAlloc_Alloc(nSize: v1);
    g_pFileSystem->Read(this: &g_pFileSystem->IBaseFileSystem, a2: v2, a3: v1, a4: v0);
    g_pFileSystem->Close(this: &g_pFileSystem->IBaseFileSystem, a2: v0);
    for ( i = COM_ParseFile(data: (const char *)v2, token, maxtoken: 1024);
          strlen(token) != 0;
          i = COM_ParseFile(data: v4, token, maxtoken: 1024) )
    {
      V_strncpy(pDest: szKeyName, pSrc: token, maxLen: 256);
      v4 = COM_ParseFile(data: i, token, maxtoken: 1024);
      if ( strlen(token) == 0 )
        break;
      v5 = g_pInputSystem->StringToButtonCode(this: g_pInputSystem, a2: szKeyName);
      Key_SetBinding(keynum: v5, pBinding: token);
    }
    free(pMem: v2);
  }
  else
  {
    ConMsg(a1: "Couldn't open kb_def.lst\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x10184650
// Name: void Host_ReadPreStartupConfiguration(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Host_ReadPreStartupConfiguration()
{
  void *v0; // edi
  int v1; // esi
  void *v2; // ebx
  unsigned int i; // esi
  const char *v4; // eax
  const char *v5; // eax
  ConVar *v6; // eax

  v0 = g_pFileSystem->Open(this: &g_pFileSystem->IBaseFileSystem, a2: "//mod/cfg/config.cfg", a3: "rt", a4: 0);
  if ( v0 != nullptr )
  {
    v1 = g_pFileSystem->Size_2(this: &g_pFileSystem->IBaseFileSystem, a2: v0);
    v2 = MemAlloc_Alloc(nSize: v1 + 1);
    g_pFileSystem->Read(this: &g_pFileSystem->IBaseFileSystem, a2: v2, a3: v1, a4: v0);
    *((_BYTE *)v2 + v1) = 0;
    g_pFileSystem->Close(this: &g_pFileSystem->IBaseFileSystem, a2: v0);
    for ( i = 0; i < 4; ++i )
    {
      v4 = V_stristr(pStr: (char *)v2, pSearch: s_PreStartupConfigConVars[i]);
      if ( v4 != nullptr )
      {
        v5 = COM_Parse(data: v4);
        COM_Parse(data: v5);
        v6 = g_pCVar->FindVar_2(this: g_pCVar, a2: s_PreStartupConfigConVars[i]);
        if ( v6 != nullptr )
          v6->SetValue_4(this: &v6->IConVar, a2: com_token);
      }
    }
    free(pMem: v2);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10184730
// Name: void Host_RecomputeSpeed_f(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Host_RecomputeSpeed_f()
{
  ConMsg(a1: "Recomputing clock speed...\n");
  CClockSpeedInit::Init();
  ConMsg(a1: "Clock speed: %.0f Mhz\n", (double)_g_dwClockSpeed * 0.000001);
}

//------------------------------------------------------------------------------
// Address: 0x10184780
// Name: void DTI_Flush_f(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall DTI_Flush_f(__int64 a1@<esi:edi>)
{
  vgui::PropertyPage *v1; // ecx

  DTI_Flush();
  ServerDTI_Flush(a1);
  CColorBalanceUIPanel::Init(this: v1);
}

//------------------------------------------------------------------------------
// Address: 0x10184790
// Name: void Host_GetHostInfo(float __near *,int __near *,int __near *,char __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Host_GetHostInfo(float *fps, int *nActive, int *nMaxPlayers, char *pszMap, int maxlen)
{
  int NumClients; // eax

  NumClients = CBaseServer::GetNumClients(this: &sv);
  *fps = g_fFramesPerSecond;
  *nActive = NumClients;
  if ( pszMap != nullptr )
  {
    if ( sv.m_szMapname[0] != 0 )
    {
      V_strncpy(pDest: pszMap, pSrc: sv.m_szMapname, maxLen: maxlen);
      *nMaxPlayers = CBaseServer::GetMaxClients(this: &sv);
      return;
    }
    *pszMap = 0;
  }
  *nMaxPlayers = CBaseServer::GetMaxClients(this: &sv);
}

//------------------------------------------------------------------------------
// Address: 0x10184800
// Name: AppearsNumeric
// Source: json
//------------------------------------------------------------------------------
bool __usercall AppearsNumeric@<al>(char *in@<eax>)
{
  char v2; // cl
  int v3; // ebx
  int v4; // edi
  bool result; // al
  int v6; // edx
  int i; // ecx
  int special[3]; // [esp+Ch] [ebp-Ch] BYREF

  _V_memset(dest: special, fill: 0, count: 12);
  v2 = *in;
  v3 = special[1];
  v4 = special[0];
  result = true;
  if ( *in != 0 )
  {
    v6 = special[2];
    while ( 1 )
    {
      if ( v2 == 45 )
      {
        ++v4;
      }
      else if ( v2 == 43 )
      {
        ++v3;
      }
      else if ( v2 < 48 || v2 > 57 )
      {
        if ( v2 != 46 )
          return false;
        ++v6;
      }
      v2 = *++in;
      if ( v2 == 0 )
      {
        special[2] = v6;
        special[1] = v3;
        special[0] = v4;
        break;
      }
    }
  }
  for ( i = 0; i < 3; ++i )
  {
    if ( special[i] > 1 )
      return false;
  }
  if ( v4 != 0 && v3 != 0 )
    return false;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101848A0
// Name: char const __near * Host_CleanupConVarStringValue(char const __near *)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl Host_CleanupConVarStringValue(const char *invalue)
{
  bool v1; // cc
  const char *result; // eax
  bool v3; // zf
  unsigned int v4; // eax
  char *v5; // eax

  V_snprintf(pDest: clean, maxLen: 256, pFormat: "%s", invalue);
  v1 = _V_strlen(str: clean) < 1;
  result = clean;
  if ( !v1 )
  {
    if ( AppearsNumeric(in: clean) )
    {
      v3 = _V_strstr(s1: clean, search: ".") == nullptr;
      result = clean;
      if ( v3 )
        return result;
      v4 = strlen(clean);
      v3 = byte_1066B1FF[v4] == 0;
      v5 = &byte_1066B1FF[v4];
      if ( !v3 )
      {
        while ( v5 >= clean )
        {
          if ( *v5 != 48 )
          {
            if ( *v5 == 46 )
              *v5 = v5 != clean ? 0 : 0x30;
            return clean;
          }
          *v5-- = 0;
          if ( *v5 == 0 )
            return clean;
        }
      }
    }
    return clean;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10184950
// Name: int Host_CountVariablesWithFlags(int,bool)
// Source: json
//------------------------------------------------------------------------------
int __cdecl Host_CountVariablesWithFlags(int flags, bool nonDefault)
{
  int v2; // ebx
  ICvar::ICVarIteratorInternal *v3; // edi
  ConVar *v4; // esi
  const char *m_pszString; // eax
  const char *Default; // eax
  const char *v8; // [esp-8h] [ebp-10h]

  v2 = 0;
  v3 = g_pCVar->FactoryInternalIterator(this: g_pCVar);
  v3->SetFirst(this: v3);
  while ( v3->IsValid(this: v3) )
  {
    v4 = (ConVar *)v3->Get(this: v3);
    if ( !v4->IsCommand(this: v4) && v4->IsFlagSet(this: v4, a2: flags) )
    {
      if ( !nonDefault )
        goto LABEL_10;
      if ( (v4->m_nFlags & 0x1000) != 0 )
      {
        m_pszString = "FCVAR_NEVER_AS_STRING";
      }
      else
      {
        m_pszString = v4->m_pParent->m_Value.m_pszString;
        if ( m_pszString == nullptr )
          m_pszString = defaultValue;
      }
      v8 = m_pszString;
      Default = ConVar::GetDefault(this: v4);
      if ( V_strcasecmp(s1: Default, s2: v8) != 0 )
LABEL_10:
        ++v2;
    }
    v3->Next(this: v3);
  }
  free(pMem: v3);
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x10184A10
// Name: void Host_UpdateSounds(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Host_UpdateSounds()
{
  IMDLCache *v0; // esi

  v0 = g_pMDLCache;
  g_pMDLCache->BeginCoarseLock(this: g_pMDLCache);
  if ( GetBaseLocalClient()->m_nSignonState == 6 )
    S_Update(pAudioState: &s_AudioState);
  else
    S_Update(pAudioState: nullptr);
  v0->EndCoarseLock(this: v0);
}

//------------------------------------------------------------------------------
// Address: 0x10184A50
// Name: public: void CFrameTimer::MarkFrame(void)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __thiscall CFrameTimer::MarkFrame(CFrameTimer *this)
{
  long double v1; // st7
  long double v2; // st5
  long double v3; // st4
  long double v4; // st3
  long double v5; // st2
  long double v6; // st6
  long double v7; // rt1
  long double v8; // st3
  long double v9; // st4
  double v10; // st2
  int v11; // ecx
  int v12; // edi
  edict_t *edicts; // eax
  int num_edicts; // esi
  char pDest[8]; // [esp+0h] [ebp-108h] BYREF
  __int64 sz_188; // [esp+100h] [ebp-8h] OVERLAPPED

  v1 = this->deltas[0] * 1000.0;
  v2 = this->deltas[1] * 1000.0;
  v3 = this->deltas[2] * 1000.0;
  v4 = this->deltas[3] * 1000.0;
  v5 = this->deltas[4] * 1000.0;
  *((float *)&sz_188 + 1) = this->deltas[5] * 1000.0;
  v6 = v5;
  *(float *)&sz_188 = 1000.0 * this->deltas[6];
  v7 = v4;
  v8 = v3;
  v9 = v7;
  this->m_flLastServerTime = v8;
  this->deltas[0] = 0.0;
  this->deltas[1] = 0.0;
  this->deltas[2] = 0.0;
  this->deltas[3] = 0.0;
  this->deltas[4] = 0.0;
  this->deltas[5] = 0.0;
  this->deltas[6] = 0.0;
  if ( host_frametime >= 0.0001 )
    v10 = 1.0 / host_frametime;
  else
    v10 = 999.0;
  if ( host_speeds.m_pParent != nullptr && host_speeds.m_pParent->m_Value.m_nValue != 0 )
  {
    v11 = host_tickcount - last_host_tickcount;
    v12 = 0;
    last_host_tickcount = host_tickcount;
    if ( sv.num_edicts > 0 )
    {
      edicts = sv.edicts;
      num_edicts = sv.num_edicts;
      do
      {
        if ( (edicts->m_fStateFlags & 2) == 0 )
          ++v12;
        ++edicts;
        --num_edicts;
      }
      while ( num_edicts != 0 );
    }
    V_snprintf(
      pDest,
      maxLen: 256,
      pFormat: "%3i fps -- inp(%3.1f) sv(%3.1f) cl(%3.1f) render(%3.1f) snd(%3.1f) cl_dll(%3.1f) exec(%3.1f) ents(%d) ticks(%d)",
      (int)v10,
      (double)v1,
      (double)v8,
      (double)v2,
      (double)v9,
      (double)v6,
      *((float *)&sz_188 + 1),
      *(float *)&sz_188,
      v12,
      v11);
    if ( host_speeds.m_pParent != nullptr && host_speeds.m_pParent->m_Value.m_nValue >= 2 )
      Con_NPrintf(idx: 0, fmt: pDest);
    else
      _ConDMsg(a1: "%s\n", pDest);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10184BE0
// Name: private: void CFrameTimer::ComputeFrameVariability(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFrameTimer::ComputeFrameVariability(CFrameTimer *this)
{
  int m_nFrameTimeHistoryIndex; // edx
  int v2; // esi
  float v3; // xmm2_4
  int v4; // edx
  float v5; // xmm1_4
  float v6; // xmm2_4
  int v7; // edx
  float v8; // xmm1_4
  float v9; // xmm2_4
  int v10; // edx
  float v11; // xmm1_4
  float v12; // xmm2_4
  int v13; // edx
  float v14; // xmm1_4
  float v15; // xmm1_4
  float v16; // xmm2_4
  int v17; // edx
  float v18; // xmm1_4
  int v19; // eax
  long double v20; // st6
  long double v21; // st5
  double v22; // st4
  long double v23; // st4
  long double v24; // rt0
  long double v25; // st3
  float v26; // xmm1_4
  double v27; // st7
  long double v28; // st6
  int v29; // edi
  float *v30; // edx
  float *v31; // esi
  int v32; // ebx
  double v33; // st6
  float v34; // xmm2_4
  double v35; // st4
  double v36; // st4
  float v37; // xmm2_4
  double v38; // st4
  float v39; // xmm2_4
  double v40; // st4
  float v41; // xmm2_4
  double v42; // st4
  int v43; // esi
  double v44; // st6
  float v45; // xmm2_4
  double v46; // st4
  double v47; // st4
  float v48; // xmm2_4
  double v49; // st4
  float v50; // xmm2_4
  double v51; // st4
  float v52; // xmm2_4
  double v53; // st4
  int count; // [esp+8h] [ebp-Ch]
  float counta; // [esp+8h] [ebp-Ch]
  float flExpCurveArea; // [esp+Ch] [ebp-8h]
  float flAverageTime; // [esp+10h] [ebp-4h]

  this->m_pFrameTimeHistory[this->m_nFrameTimeHistoryIndex++] = this->frametime;
  if ( this->m_nFrameTimeHistoryIndex >= 50 )
    this->m_nFrameTimeHistoryIndex = 0;
  m_nFrameTimeHistoryIndex = this->m_nFrameTimeHistoryIndex;
  v2 = 0;
  v3 = 0.0;
  do
  {
    if ( v3 > 0.5 )
      break;
    v4 = m_nFrameTimeHistoryIndex - 1;
    if ( v4 < 0 )
      v4 = 49;
    v5 = this->m_pFrameTimeHistory[v4];
    if ( v5 == 0.0 )
      break;
    v6 = v5 + v3;
    if ( v6 > 0.5 )
      goto LABEL_26;
    v7 = v4 - 1;
    if ( v7 < 0 )
      v7 = 49;
    v8 = this->m_pFrameTimeHistory[v7];
    if ( v8 == 0.0 )
    {
LABEL_26:
      ++v2;
      break;
    }
    v9 = v8 + v6;
    if ( v9 > 0.5 )
      goto LABEL_27;
    v10 = v7 - 1;
    if ( v10 < 0 )
      v10 = 49;
    v11 = this->m_pFrameTimeHistory[v10];
    if ( v11 == 0.0 )
    {
LABEL_27:
      v2 += 2;
      break;
    }
    v12 = v11 + v9;
    if ( v12 > 0.5 )
      goto LABEL_28;
    v13 = v10 - 1;
    if ( v13 < 0 )
      v13 = 49;
    v14 = this->m_pFrameTimeHistory[v13];
    if ( v14 == 0.0 )
    {
LABEL_28:
      v2 += 3;
      break;
    }
    v15 = v14 + v12;
    if ( v15 > 0.5 )
      goto LABEL_29;
    m_nFrameTimeHistoryIndex = v13 - 1;
    if ( m_nFrameTimeHistoryIndex < 0 )
      m_nFrameTimeHistoryIndex = 49;
    v16 = this->m_pFrameTimeHistory[m_nFrameTimeHistoryIndex];
    if ( v16 == 0.0 )
    {
LABEL_29:
      v2 += 4;
      break;
    }
    v2 += 5;
    v3 = v16 + v15;
  }
  while ( v2 < 50 );
  if ( v2 != 0 )
  {
    v17 = 0;
    v18 = 0.0;
    v19 = this->m_nFrameTimeHistoryIndex;
    flExpCurveArea = 0.0;
    count = 0;
    if ( v2 > 0 )
    {
      v20 = 0.0;
      v21 = 0.0;
      do
      {
        if ( --v19 < 0 )
          v19 = 49;
        v22 = (double)count;
        count = ++v17;
        v23 = v22 * (float)(-2.0 / (float)v2) * 1.442695040888963407;
        v24 = rint(v23);
        v25 = __FSCALE__(__F2XM1__(v23 - v24) + 1.0, v24);
        v21 = v21 + v25;
        v20 = v20 + v25 * this->m_pFrameTimeHistory[v19];
      }
      while ( v17 < v2 );
      flAverageTime = v20;
      v18 = flAverageTime;
      flExpCurveArea = v21;
    }
    v26 = v18 / flExpCurveArea;
    counta = 0.0;
    if ( v26 != 0.0 )
      counta = 1.0 / v26;
    v27 = 0.0;
    if ( this->frametime == 0.0 )
      v28 = 0.0;
    else
      v28 = 1.0 / this->frametime;
    v29 = 0;
    v30 = &this->m_pFrameTimeHistory[1];
    this->m_flFPSVariability = fabs(v28 - counta);
    v31 = &this->m_pFrameTimeHistory[1];
    v32 = 10;
    v33 = 0.0;
    do
    {
      v34 = *(v31 - 1);
      if ( v34 != 0.0 )
      {
        if ( v34 >= 0.25 )
          v35 = 0.25;
        else
          v35 = *(v31 - 1);
        v33 = v33 + v35;
        ++v29;
      }
      if ( *v31 != 0.0 )
      {
        if ( *v31 >= 0.25 )
          v36 = 0.25;
        else
          v36 = *v31;
        v33 = v33 + v36;
        ++v29;
      }
      v37 = v31[1];
      if ( v37 != 0.0 )
      {
        if ( v37 >= 0.25 )
          v38 = 0.25;
        else
          v38 = v31[1];
        v33 = v33 + v38;
        ++v29;
      }
      v39 = v31[2];
      if ( v39 != 0.0 )
      {
        if ( v39 >= 0.25 )
          v40 = 0.25;
        else
          v40 = v31[2];
        v33 = v33 + v40;
        ++v29;
      }
      v41 = v31[3];
      if ( v41 != 0.0 )
      {
        if ( v41 >= 0.25 )
          v42 = 0.25;
        else
          v42 = v31[3];
        v33 = v33 + v42;
        ++v29;
      }
      v31 += 5;
      --v32;
    }
    while ( v32 != 0 );
    if ( v29 > 1 )
    {
      v43 = 10;
      v44 = v33 / (double)v29;
      do
      {
        v45 = *(v30 - 1);
        if ( v45 != 0.0 )
        {
          if ( v45 >= 0.25 )
            v46 = 0.25;
          else
            v46 = *(v30 - 1);
          v27 = v27 + (v46 - v44) * (v46 - v44);
        }
        if ( *v30 != 0.0 )
        {
          if ( *v30 >= 0.25 )
            v47 = 0.25;
          else
            v47 = *v30;
          v27 = v27 + (v47 - v44) * (v47 - v44);
        }
        v48 = v30[1];
        if ( v48 != 0.0 )
        {
          if ( v48 >= 0.25 )
            v49 = 0.25;
          else
            v49 = v30[1];
          v27 = v27 + (v49 - v44) * (v49 - v44);
        }
        v50 = v30[2];
        if ( v50 != 0.0 )
        {
          if ( v50 >= 0.25 )
            v51 = 0.25;
          else
            v51 = v30[2];
          v27 = v27 + (v51 - v44) * (v51 - v44);
        }
        v52 = v30[3];
        if ( v52 != 0.0 )
        {
          if ( v52 >= 0.25 )
            v53 = 0.25;
          else
            v53 = v30[3];
          v27 = v27 + (v53 - v44) * (v53 - v44);
        }
        v30 += 5;
        --v43;
      }
      while ( v43 != 0 );
      this->m_flFPSStdDeviationSeconds = sqrt(v27 / (double)(v29 - 1));
    }
  }
  else
  {
    this->m_flFPSVariability = 0.0;
    this->m_flFPSStdDeviationSeconds = 0.0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10184FD0
// Name: bool Host_ShouldRun(void)
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
char __cdecl Host_ShouldRun()
{
  unsigned int v1; // [esp-8h] [ebp-8h]
  int v2; // [esp-4h] [ebp-4h]

  if ( singlestep.m_pParent == nullptr || singlestep.m_pParent->m_Value.m_nValue == 0 )
    return 1;
  if ( next.m_pParent != nullptr && next.m_pParent->m_Value.m_nValue != 0 )
  {
    if ( current_tick == host_tickcount - 1 )
      return 1;
    CLoaderMemAlloc::CrtIsValidPointer(this: (ConVar *)&next.IConVar, value: 0, a2: v1, a3: v2);
    return 0;
  }
  else
  {
    current_tick = host_tickcount;
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10185020
// Name: void _Host_RunFrame_Input(float,bool)
// Source: json
//------------------------------------------------------------------------------
void __usercall _Host_RunFrame_Input(int a1@<edi>, float accumulated_extra_samples, bool bFinalTick)
{
  CStatTime *v3; // ecx
  int v4; // eax
  const char *v5; // eax
  const char *v6; // esi
  CStatTime *v7; // ecx
  CStatTime *v8; // ecx
  CStatTime *v9; // ecx

  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "_Host_RunFrame_Input",
    a3: 0,
    a4: "Input",
    a5: false,
    a6: 4);
  if ( bFirstFrame )
  {
    bFirstFrame = false;
    v4 = _CommandLine();
    v5 = (const char *)(*(int (__thiscall **)(int, const char *, _DWORD))(*(_DWORD *)v4 + 32))(
                         a1: v4,
                         a2: "-testscript",
                         a3: 0);
    v6 = v5;
    if ( v5 != nullptr && CTestScriptMgr::StartTestScript(this: &g_TestScriptMgr, pFilename: v5) == 0 )
      _Error(a1: "StartTestScript( %s ) failed.", v6);
    InitNetConsole();
    NET_InitPostFork();
  }
  g_HostTimes.starttime[0] = _Plat_FloatTime(this: v3);
  ClientDLL_ProcessInput();
  g_HostTimes.starttime[6] = _Plat_FloatTime(this: v7);
  Cbuf_Execute();
  g_HostTimes.deltas[6] = _Plat_FloatTime(this: v8) - g_HostTimes.starttime[6] + g_HostTimes.deltas[6];
  CL_Move(a1, accumulated_extra_samples, bFinalTick);
  g_HostTimes.deltas[0] = _Plat_FloatTime(this: v9) - g_HostTimes.starttime[0] + g_HostTimes.deltas[0];
  CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
}

//------------------------------------------------------------------------------
// Address: 0x10185110
// Name: void _Host_RunFrame_Client(bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl _Host_RunFrame_Client(bool framefinished)
{
  CStatTime *v1; // ecx
  CClientState *BaseLocalClient; // eax
  CClientState *v3; // eax
  CClientState *v4; // eax
  CStatTime *v5; // ecx
  CSteam3Client *v6; // eax
  CStatTime *v7; // ecx

  g_HostTimes.starttime[1] = _Plat_FloatTime(this: v1);
  CL_ReadPackets(bFinalTick: framefinished);
  BaseLocalClient = GetBaseLocalClient();
  CClientState::CheckUpdatingSteamResources(this: BaseLocalClient);
  v3 = GetBaseLocalClient();
  CClientState::CheckFileCRCsWithServer(this: v3);
  v4 = GetBaseLocalClient();
  v4->RunFrame(this: v4);
  if ( CL_IsHL2Demo() || CL_IsPortalDemo() )
    CL_DemoCheckGameUIRevealTime(this: v5);
  v6 = Steam3Client();
  CSteam3Client::RunFrame(this: v6);
  g_HostTimes.deltas[1] = _Plat_FloatTime(this: v7) - g_HostTimes.starttime[1] + g_HostTimes.deltas[1];
  CL_SetPagedPoolInfo();
}

//------------------------------------------------------------------------------
// Address: 0x101851A0
// Name: float Host_GetSoundDuration(char const __near *)
// Source: json
//------------------------------------------------------------------------------
double __cdecl Host_GetSoundDuration(const char *pSample)
{
  CClientState *BaseLocalClient; // eax
  CClientState *v2; // esi
  int v3; // eax
  CSfxTable *Sound; // eax
  CSfxTable *v5; // esi

  BaseLocalClient = GetBaseLocalClient();
  v2 = BaseLocalClient;
  if ( BaseLocalClient->m_nSignonState < 2 )
    return SV_GetSoundDuration(pSample);
  v3 = CClientState::LookupSoundIndex(this: BaseLocalClient, name: pSample);
  if ( v3 < 0 )
    return SV_GetSoundDuration(pSample);
  Sound = CClientState::GetSound(this: v2, index: v3);
  v5 = Sound;
  if ( Sound != nullptr && (*((_BYTE *)Sound + 12) & 4) != 0 )
    DevMsg(a1: "    Reason for late load of '%s': Calling Host_GetSoundDuration().\n", pSample);
  return AudioSource_GetSoundDuration(pSfx: v5);
}

//------------------------------------------------------------------------------
// Address: 0x10185200
// Name: host_runofftime
// Source: json
//------------------------------------------------------------------------------
void __cdecl host_runofftime(const CCommand *args)
{
  long double v1; // st7
  float v2; // [esp+8h] [ebp+8h]

  if ( args->m_nArgc == 2 )
  {
    if ( sv.m_State >= ss_active )
    {
      if ( sv.m_nMaxclients <= 1 )
      {
        v1 = atof(nptr: args->m_ppArgv[1]);
        if ( v1 > 0.0 )
        {
          v2 = v1;
          if ( v2 <= 900.0 )
          {
            ConMsg(a1: "Skipping ahead for %f seconds\n", (double)v1);
            SCR_UpdateScreen();
            SCR_UpdateScreen();
          }
          else
          {
            ConMsg(a1: "host_runofftime would run off %.2f minutes!!! ignoring\n", (double)(v1 * 0.016666668));
          }
        }
      }
      else
      {
        ConMsg(a1: "host_runofftime:  only valid in single player\n");
      }
    }
    else
    {
      ConMsg(a1: "host_runofftime:  must be running a server\n");
    }
  }
  else
  {
    ConMsg(a1: "Usage:  host_runofftime <seconds>\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x101852B0
// Name: void Host_ShowIPCCallCount(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Host_ShowIPCCallCount()
{
  unsigned int v0; // eax
  int v1; // eax
  unsigned int IPCCallCount; // eax
  double v3; // [esp+0h] [ebp-18h]
  double v4; // [esp+8h] [ebp-10h]
  float flCurTime; // [esp+14h] [ebp-4h]

  if ( host_ShowIPCCallCount.m_pParent != nullptr && host_ShowIPCCallCount.m_pParent->m_Value.m_nValue != 0 )
  {
    v0 = _S5_1;
    if ( (_S5_1 & 1) == 0 )
    {
      v0 = _S5_1 | 1;
      _S5_1 |= 1u;
      s_nLastTick = host_tickcount;
    }
    if ( (v0 & 2) == 0 )
    {
      _S5_1 = v0 | 2;
      s_nLastFrame = host_framecount;
    }
    v4 = 0.0;
    flCurTime = host_ShowIPCCallCount.m_pParent->m_Value.m_fValue;
    if ( flCurTime > 0.0 )
      v4 = 1.0 / flCurTime;
    v3 = _Plat_FloatTime(this: (CStatTime *)host_ShowIPCCallCount.m_pParent);
    if ( v3 - s_flLastTime >= v4 )
    {
      v1 = _SteamClient();
      if ( v1 != 0 )
        IPCCallCount = (*(int (__thiscall **)(int))(*(_DWORD *)v1 + 80))(a1: v1);
      else
        IPCCallCount = _SteamGameServer_GetIPCCallCount();
      if ( host_framecount != s_nLastFrame && host_tickcount != s_nLastTick )
      {
        _Msg(
          a1: "host_ShowIPCCallCount: %d IPC calls in the past [%d frames, %d ticks]  Avg: [%.2f/frame, %.2f/tick]\n",
          IPCCallCount,
          host_framecount - s_nLastFrame,
          host_tickcount - s_nLastTick,
          (double)IPCCallCount / (double)(host_framecount - s_nLastFrame),
          (double)IPCCallCount / (double)(host_tickcount - s_nLastTick));
        s_flLastTime = v3;
        s_nLastTick = host_tickcount;
        s_nLastFrame = host_framecount;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101853E0
// Name: PrintHostFrameTimes
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __cdecl PrintHostFrameTimes(int nNumTicks, float flHostRemainder, float flMinimumTickInterval)
{
  int v3; // eax
  int v4; // edx
  float v5; // xmm2_4
  float v6; // xmm0_4
  float *v7; // eax
  float v8; // xmm1_4
  float v9; // xmm2_4
  float v10; // xmm2_4
  float v11; // xmm1_4
  float v12; // xmm2_4
  float v13; // xmm1_4
  float v14; // xmm1_4
  float v15; // xmm2_4
  con_nprint_s info; // [esp+0h] [ebp-20h] BYREF
  unsigned __int64 printinfo; // [esp+18h] [ebp-8h] OVERLAPPED

  v3 = nFrameIndex;
  flFrameTimes[nFrameIndex] = host_frametime;
  v4 = (v3 + 1) % 100;
  v5 = 0.0;
  v6 = 1.0;
  HIDWORD(printinfo) = 1065353216;
  v7 = (float *)&unk_1066B31C;
  nFrameIndex = v4;
  do
  {
    v8 = *(v7 - 1);
    if ( v6 > v8 )
      v6 = *(v7 - 1);
    v9 = v5 + v8;
    if ( v6 > *v7 )
      v6 = *v7;
    v10 = v9 + *v7;
    v11 = v7[1];
    if ( v6 > v11 )
      v6 = v7[1];
    v12 = v10 + v11;
    v13 = v7[2];
    if ( v6 > v13 )
      v6 = v7[2];
    v14 = v13 + v12;
    v15 = v7[3];
    if ( v6 > v15 )
      v6 = v7[3];
    v7 += 5;
    v5 = v15 + v14;
  }
  while ( (int)v7 < (int)&flt_1066B4AC );
  info.index = 1;
  info.fixed_width_font = true;
  printinfo = __PAIR64__(LODWORD(v6), LODWORD(v5));
  info.time_to_live = -1.0;
  info.color[2] = 1.0;
  info.color[1] = 1.0;
  info.color[0] = 1.0;
  Con_NXPrintf(
    &info,
    fmt: "ticks: %d, host_remainder: %f, host_frametime: %f, minimum interval: %f\n",
    nNumTicks,
    flHostRemainder,
    host_frametime,
    flMinimumTickInterval);
  info.index = 2;
  Con_NXPrintf(
    &info,
    fmt: "Running min frametime: %f, running avg frametime: %f\n",
    *((float *)&printinfo + 1),
    *(float *)&printinfo * 0.0099999998);
}

//------------------------------------------------------------------------------
// Address: 0x10185510
// Name: PrintFsStats
// Source: json
//------------------------------------------------------------------------------
void PrintFsStats()
{
  IIoStats *v0; // eax
  IIoStats *v1; // esi
  int v2; // edi
  int *v3; // edx
  int v4; // eax
  int v5; // esi
  int v6; // ecx
  int v7; // esi
  int v8; // ecx
  int v9; // esi
  int v10; // ecx
  int v11; // esi
  int v12; // ecx
  int v13; // esi
  int v14; // ecx
  int v15; // edi
  int j; // esi
  PrintFsStats::__l2::Mode v17; // eax
  __m128i v18; // xmm0
  float v19; // xmm0_4
  float v20; // xmm1_4
  __int32 v21; // eax
  int nMinStats[6]; // [esp+4h] [ebp-68h]
  int nAvgStats[6]; // [esp+1Ch] [ebp-50h]
  con_nprint_s printinfo; // [esp+34h] [ebp-38h] BYREF
  int nMaxStats[6]; // [esp+4Ch] [ebp-20h] BYREF
  int *v26; // [esp+64h] [ebp-8h]
  int i; // [esp+68h] [ebp-4h]

  v0 = g_pFileSystem->GetIoStats(this: g_pFileSystem);
  v1 = v0;
  if ( v0 != nullptr )
  {
    nStats[0][nFrameIndex_0] = v0->GetNumberOfFileSeeks(this: v0);
    dword_1066B640[nFrameIndex_0] = v1->GetTimeInFileSeek(this: v1);
    dword_1066B7D0[nFrameIndex_0] = v1->GetNumberOfFileReads(this: v1);
    dword_1066B960[nFrameIndex_0] = v1->GetTimeInFileReads(this: v1);
    dword_1066BAF0[nFrameIndex_0] = v1->GetFileReadTotalSize(this: v1);
    dword_1066BC80[nFrameIndex_0] = v1->GetNumberOfFileOpens(this: v1);
    v1->Reset(this: v1);
    v2 = 0;
    nFrameIndex_0 = (nFrameIndex_0 + 1) % 100;
    v3 = (int *)&unk_1066B4B4;
    v26 = (int *)&unk_1066B4B4;
    do
    {
      if ( nModes[v2] != SKIPPED )
      {
        nMinStats[v2] = 0x7FFFFFFF;
        v4 = nMinStats[v2];
        nAvgStats[v2] = 0;
        v5 = nAvgStats[v2];
        nMaxStats[v2] = 0x80000000;
        for ( i = 20; i != 0; --i )
        {
          v6 = *(v3 - 1);
          if ( v6 >= v4 )
          {
            if ( v6 > nMaxStats[v2] )
              nMaxStats[v2] = v6;
          }
          else
          {
            v4 = *(v3 - 1);
          }
          v7 = v6 + v5;
          v8 = *v3;
          if ( *v3 >= v4 )
          {
            if ( v8 > nMaxStats[v2] )
              nMaxStats[v2] = v8;
          }
          else
          {
            v4 = *v3;
          }
          v9 = v8 + v7;
          v10 = v3[1];
          if ( v10 >= v4 )
          {
            if ( v10 > nMaxStats[v2] )
              nMaxStats[v2] = v10;
          }
          else
          {
            v4 = v3[1];
          }
          v11 = v10 + v9;
          v12 = v3[2];
          if ( v12 >= v4 )
          {
            if ( v12 > nMaxStats[v2] )
              nMaxStats[v2] = v12;
          }
          else
          {
            v4 = v3[2];
          }
          v13 = v12 + v11;
          v14 = v3[3];
          if ( v14 >= v4 )
          {
            if ( v14 > nMaxStats[v2] )
              nMaxStats[v2] = v14;
          }
          else
          {
            v4 = v3[3];
          }
          v5 = v14 + v13;
          v3 += 5;
        }
        v3 = v26;
        nMinStats[v2] = v4;
        nAvgStats[v2] = v5;
      }
      v3 += 100;
      ++v2;
      v26 = v3;
    }
    while ( (int)v3 < (int)&s_HostSubscribeForProfileEvents );
    printinfo.time_to_live = -1.0;
    printinfo.index = 1;
    printinfo.color[2] = 1.0;
    printinfo.color[1] = 1.0;
    printinfo.color[0] = 1.0;
    printinfo.fixed_width_font = true;
    Con_NXPrintf(info: &printinfo, fmt: "IO stats from the last %d frames.\n", 100);
    v15 = 3;
    for ( j = 0; j < 6; ++j )
    {
      v17 = nModes[j];
      if ( v17 != SKIPPED )
      {
        v18 = _mm_cvtsi32_si128(nAvgStats[j]);
        printinfo.index = v15;
        v19 = _mm_cvtepi32_ps(v18).m128_f32[0] * 0.0099999998;
        ++v15;
        v20 = v19 * 30.0;
        if ( v17 != NORMAL )
        {
          v21 = v17 - 1;
          if ( v21 != 0 )
          {
            if ( v21 == 1 )
              Con_NXPrintf(
                info: &printinfo,
                fmt: "%s - Avg:%5d Kb - Max:%5d Kb -%5d Kb/s\n",
                pStatsTitle[j],
                (int)(float)(v19 * 0.0009765625),
                nMaxStats[j] / 1024,
                (int)(float)(v20 * 0.0009765625));
          }
          else
          {
            Con_NXPrintf(
              info: &printinfo,
              fmt: "%s - Avg:%5d ms - Max:%5d ms -%5d ms/s\n",
              pStatsTitle[j],
              (int)v19,
              nMaxStats[j],
              (int)v20);
          }
        }
        else
        {
          Con_NXPrintf(
            info: &printinfo,
            fmt: "%s - Avg:%5d    - Max:%5d    -%5d   /s\n",
            pStatsTitle[j],
            (int)v19,
            nMaxStats[j],
            (int)v20);
        }
      }
    }
    printinfo.index = v15;
    Con_NXPrintf(info: &printinfo, fmt: "Delay for choreo: %5d ms\n", (int)(float)(g_fDelayForChoreo * 1000.0));
  }
  else
  {
    nMaxStats[0] = 1;
    LOBYTE(nMaxStats[5]) = 1;
    nMaxStats[1] = -1082130432;
    nMaxStats[4] = 1065353216;
    nMaxStats[3] = 1065353216;
    nMaxStats[2] = 1065353216;
    Con_NXPrintf(info: (const con_nprint_s *)nMaxStats, fmt: "IO stats is disabled.\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x10185840
// Name: bool IsLowViolence_Registry(void)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl IsLowViolence_Registry()
{
  int v0; // eax
  bool v1; // bl
  bool v2; // cc
  bool result; // al
  char gamedir[260]; // [esp+4h] [ebp-204h] BYREF
  char szSubKey[128]; // [esp+108h] [ebp-100h] BYREF
  char szBuffer[128]; // [esp+188h] [ebp-80h] BYREF

  memset(dst: (unsigned __int8 *)szBuffer, value: 0, count: sizeof(szBuffer));
  V_snprintf(pDest: szSubKey, maxLen: 128, pFormat: "Software\\Valve\\%s\\Settings", "Source");
  V_strncpy(pDest: szBuffer, pSrc: defaultValue, maxLen: 128);
  Sys_GetRegKeyValue(
    pszSubKey: szSubKey,
    pszElement: "User Token 2",
    pszReturnString: szBuffer,
    nReturnLength: 127,
    pszDefaultValue: szBuffer);
  v0 = _V_strlen(str: szBuffer);
  v1 = v0 > 0;
  if ( v0 <= 0 )
  {
    Sys_GetRegKeyValue(
      pszSubKey: szSubKey,
      pszElement: "User Token 3",
      pszReturnString: szBuffer,
      nReturnLength: 127,
      pszDefaultValue: szBuffer);
    v1 = _V_strlen(str: szBuffer) > 0;
  }
  V_FileBase(in: com_gamedir, out: gamedir, maxlen: 260);
  V_snprintf(pDest: szSubKey, maxLen: 128, pFormat: "Software\\Valve\\%s\\%s\\Settings", "Source", gamedir);
  V_strncpy(pDest: szBuffer, pSrc: defaultValue, maxLen: 128);
  Sys_GetRegKeyValue(
    pszSubKey: szSubKey,
    pszElement: "User Token 2",
    pszReturnString: szBuffer,
    nReturnLength: 127,
    pszDefaultValue: szBuffer);
  if ( _V_strlen(str: szBuffer) > 0 )
    v1 = true;
  Sys_GetRegKeyValue(
    pszSubKey: szSubKey,
    pszElement: "User Token 3",
    pszReturnString: szBuffer,
    nReturnLength: 127,
    pszDefaultValue: szBuffer);
  v2 = _V_strlen(str: szBuffer) <= 0;
  result = true;
  if ( v2 )
    return v1;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10185990
// Name: void Host_CheckGore(void)
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __cdecl Host_CheckGore()
{
  int v0; // eax
  bool v1; // bl
  CSteam3Client *v2; // eax
  bool v3; // al
  int v4; // [esp-14h] [ebp-1Ch]
  unsigned int v5; // [esp-10h] [ebp-18h]
  int v6; // [esp-Ch] [ebp-14h]
  unsigned int v7; // [esp-8h] [ebp-10h]
  int v8; // [esp-4h] [ebp-Ch]
  unsigned int v9; // [esp+0h] [ebp-8h]
  int v10; // [esp+4h] [ebp-4h]

  v0 = _CommandLine();
  HIBYTE(v10) = (*(int (__thiscall **)(int))(*(_DWORD *)v0 + 40))(a1: v0) != 0;
  v1 = IsLowViolence_Registry();
  if ( Steam3Client()->m_pSteamApps != nullptr )
  {
    v2 = Steam3Client();
    v3 = v2->m_pSteamApps->BIsLowViolence(this: v2->m_pSteamApps);
  }
  else
  {
    v3 = false;
  }
  if ( v1 || v3 || HIBYTE(v10) != 0 )
  {
    g_bLowViolence = true;
    if ( v1 )
    {
      CLoaderMemAlloc::CrtIsValidPointer(
        this: (ConVar *)&violence_hblood.IConVar,
        value: 0,
        a2: (unsigned int)"-lv",
        a3: v4);
      CLoaderMemAlloc::CrtIsValidPointer(this: (ConVar *)&violence_hgibs.IConVar, value: 0, a2: v5, a3: v6);
      CLoaderMemAlloc::CrtIsValidPointer(this: (ConVar *)&violence_ablood.IConVar, value: 0, a2: v7, a3: v8);
      CLoaderMemAlloc::CrtIsValidPointer(this: (ConVar *)&violence_agibs.IConVar, value: 0, a2: v9, a3: v10);
    }
  }
  else
  {
    g_bLowViolence = false;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10185A30
// Name: void Host_InitProcessor(void)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __cdecl Host_InitProcessor()
{
  int CPUInformation; // eax
  _BYTE *v1; // esi
  const char *v2; // edi
  vgui::Splitter *v3; // ecx
  char v4; // bl
  unsigned __int8 v5; // al
  char pDest[16]; // [esp+Ch] [ebp-208h] BYREF
  char buffer[256]; // [esp+1Ch] [ebp-1F8h] BYREF
  double szFeatureString_240; // [esp+20Ch] [ebp-8h] OVERLAPPED

  CPUInformation = _GetCPUInformation();
  v1 = (_BYTE *)CPUInformation;
  v2 = "Mhz";
  szFeatureString_240 = (double)*(__int64 *)(CPUInformation + 8) * 0.000001;
  if ( szFeatureString_240 > 1000.0 )
  {
    v2 = "Ghz";
    szFeatureString_240 = szFeatureString_240 * 0.001;
  }
  V_strncpy(pDest: &buffer[240], pSrc: *(const char **)(CPUInformation + 16), maxLen: 256);
  V_strncat(pDest: &buffer[240], pSrc: " ", destBufferSize: 0x100u, max_chars_to_copy: -1);
  if ( (v1[4] & 8) != 0 )
  {
    if ( CBaseServer::ShouldUpdateMasterServer(this: v3) != 0 )
      V_strncat(pDest: &buffer[240], pSrc: "SSE ", destBufferSize: 0x100u, max_chars_to_copy: -1);
    else
      V_strncat(pDest: &buffer[240], pSrc: "(SSE) ", destBufferSize: 0x100u, max_chars_to_copy: -1);
  }
  if ( (v1[4] & 0x10) != 0 )
  {
    if ( CBaseServer::ShouldUpdateMasterServer(this: v3) != 0 )
      V_strncat(pDest: &buffer[240], pSrc: "SSE2 ", destBufferSize: 0x100u, max_chars_to_copy: -1);
    else
      V_strncat(pDest: &buffer[240], pSrc: "(SSE2) ", destBufferSize: 0x100u, max_chars_to_copy: -1);
  }
  if ( (v1[4] & 0x40) != 0 )
  {
    if ( CBaseServer::ShouldUpdateMasterServer(this: v3) != 0 )
      V_strncat(pDest: &buffer[240], pSrc: "MMX ", destBufferSize: 0x100u, max_chars_to_copy: -1);
    else
      V_strncat(pDest: &buffer[240], pSrc: "(MMX) ", destBufferSize: 0x100u, max_chars_to_copy: -1);
  }
  if ( (v1[4] & 1) != 0 )
    V_strncat(pDest: &buffer[240], pSrc: "RDTSC ", destBufferSize: 0x100u, max_chars_to_copy: -1);
  if ( (v1[4] & 2) != 0 )
    V_strncat(pDest: &buffer[240], pSrc: "CMOV ", destBufferSize: 0x100u, max_chars_to_copy: -1);
  if ( (v1[4] & 4) != 0 )
    V_strncat(pDest: &buffer[240], pSrc: "FCMOV ", destBufferSize: 0x100u, max_chars_to_copy: -1);
  buffer[_V_strlen(str: &buffer[240]) + 239] = 0;
  v4 = v1[5];
  if ( v4 == 1 )
  {
    _ConDMsg(a1: "1 CPU, Frequency: %.01f %s,  Features: %s\n", szFeatureString_240, v2, &buffer[240]);
  }
  else
  {
    pDest[0] = 0;
    memset(dst: (unsigned __int8 *)&pDest[1], value: 0, count: 0xFFu);
    v5 = v1[6];
    if ( v5 != v4 )
      V_snprintf(pDest, maxLen: 256, pFormat: " (%i physical)", v5);
    _ConDMsg(
      a1: "%i CPUs%s, Frequency: %.01f %s,  Features: %s\n",
      (unsigned __int8)v1[5],
      pDest,
      szFeatureString_240,
      v2,
      &buffer[240]);
  }
  if ( s_bInitPME )
    _InitPME();
}

//------------------------------------------------------------------------------
// Address: 0x10185C80
// Name: int Host_GetServerCount(void)
// Source: json
//------------------------------------------------------------------------------
int __cdecl Host_GetServerCount()
{
  if ( GetBaseLocalClient()->m_nSignonState >= 3
    || GetBaseLocalClient()->m_nSignonState >= 2 && GetBaseLocalClient()->m_bServerInfoProcessed )
  {
    return GetBaseLocalClient()->m_nServerCount;
  }
  if ( sv.m_State < ss_loading )
    return gHostSpawnCount;
  return sv.m_nSpawnCount;
}

//------------------------------------------------------------------------------
// Address: 0x10185CD0
// Name: void Host_PostInit(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Host_PostInit()
{
  IEngineVGuiInternal *v0; // eax

  if ( serverGameDLL != nullptr )
    serverGameDLL->PostInit(this: serverGameDLL);
  if ( g_ClientDLL != nullptr )
    g_ClientDLL->PostInit(this: g_ClientDLL);
  toolframework->PostInit(this: toolframework);
  if ( !sv.m_bIsDedicated )
  {
    v0 = EngineVGui();
    v0->PostInit(this: v0);
  }
  if ( serverGameDLL != nullptr )
    serverGameDLL->PostToolsInit(this: serverGameDLL);
}

//------------------------------------------------------------------------------
// Address: 0x10185D30
// Name: void GetPlatformMapPath(char const __near *,char __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GetPlatformMapPath(const char *pMapPath, char *pPlatformMapPath, int maxLength)
{
  V_strncpy(pDest: pPlatformMapPath, pSrc: pMapPath, maxLen: maxLength);
  if ( g_pMaterialSystemHardwareConfig != nullptr )
  {
    V_StripExtension(in: pMapPath, out: pPlatformMapPath, outSize: maxLength);
    V_strncat(pDest: pPlatformMapPath, pSrc: ".bsp", destBufferSize: maxLength, max_chars_to_copy: -1);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10185D80
// Name: void Host_FreeStateAndWorld(bool)
// Source: json
//------------------------------------------------------------------------------
void __usercall Host_FreeStateAndWorld(int a1@<edi>, bool server)
{
  if ( server )
  {
    if ( !sv.m_bIsDedicated )
      CL_ClearState(a1);
  }
  else if ( sv.m_State >= ss_active )
  {
    return;
  }
  if ( host_state.worldmodel != nullptr )
  {
    modelloader->UnreferenceModel(this: modelloader, a2: host_state.worldmodel, a3: FMODELLOADER_SERVER);
    modelloader->UnreferenceModel(this: modelloader, a2: host_state.worldmodel, a3: FMODELLOADER_CLIENT);
    if ( host_state.worldmodel != nullptr )
    {
      host_state.worldmodel = nullptr;
      host_state.worldbrush = nullptr;
    }
  }
  modelloader->UnloadUnreferencedModels(this: modelloader);
  g_TimeLastMemTest = 0.0;
}

//------------------------------------------------------------------------------
// Address: 0x10185E10
// Name: void Host_FreeToLowMark(bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Host_FreeToLowMark(bool server)
{
  if ( server || sv.m_State <= ss_dead )
  {
    CM_FreeMap();
    if ( host_hunklevel != 0 )
      Hunk_FreeToLowMark(mark: host_hunklevel);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10185E50
// Name: bool Host_AllowQueuedMaterialSystem(bool)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl Host_AllowQueuedMaterialSystem(BOOL bAllow)
{
  g_bAllowThreadedSound = bAllow;
  return g_pMaterialSystem->AllowThreading(this: g_pMaterialSystem, a2: bAllow, a3: g_nMaterialSystemThread);
}

//------------------------------------------------------------------------------
// Address: 0x10185E80
// Name: void Host_EnsureHostNameSet(void)
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __cdecl Host_EnsureHostNameSet()
{
  char *m_pszString; // eax
  CSteam3Client *v1; // eax
  CSteam3Client *v2; // eax
  const char *v3; // eax
  int v4; // [esp-4h] [ebp-4h]

  if ( (host_name.m_nFlags & 0x1000) == 0 )
  {
    m_pszString = host_name.m_pParent->m_Value.m_pszString;
    if ( m_pszString == nullptr || *m_pszString == 0 )
    {
      if ( sv.m_bIsDedicated
        || Steam3Client()->m_pSteamUser == nullptr
        || (v1 = Steam3Client(), !v1->m_pSteamUser->BLoggedOn(this: v1->m_pSteamUser))
        || (v2 = Steam3Client(), *(v3 = v2->m_pSteamFriends->GetPersonaName(this: v2->m_pSteamFriends)) == 0) )
      {
        v3 = serverGameDLL->GetGameDescription(this: serverGameDLL);
      }
      CLoaderMemAlloc::CrtSetReportMode(this: (ConVar *)&host_name.IConVar, value: v3, a2: v4);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10185EF0
// Name: public: bool CJob::WaitForFinishAndRelease(unsigned int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CJob::WaitForFinishAndRelease(CJob *this, unsigned int dwTimeout)
{
  int m_status; // eax
  bool v5; // bl
  CJob *v6; // [esp+4h] [ebp-4h] BYREF

  if ( this == nullptr )
    return 1;
  m_status = this->m_status;
  if ( m_status == 1 || m_status == 2 || m_status == 4 )
  {
    v6 = this;
    v5 = _g_pThreadPool->YieldWait(this: _g_pThreadPool, a2: &v6, a3: 1, a4: true, a5: dwTimeout) != 258;
    this->Release(this);
    return v5;
  }
  else
  {
    this->Release(this);
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10185F70
// Name: public: int CJob::Execute(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CJob::Execute(CJob *this)
{
  int result; // eax
  CThreadFastMutex *p_m_mutex; // edi
  DWORD CurrentThreadId; // ecx
  int (__thiscall *DoExecute)(CJob *); // edx
  int v6; // eax
  int m_status; // ebx

  result = this->m_status;
  if ( result == 1 || result == 2 || result == 4 )
  {
    p_m_mutex = &this->m_mutex;
    CurrentThreadId = GetCurrentThreadId();
    if ( CurrentThreadId != p_m_mutex->m_ownerID
      && _InterlockedCompareExchange((volatile signed __int32 *)p_m_mutex, CurrentThreadId, 0) != 0 )
    {
      _mm_pause();
      CThreadFastMutex::Lock(a1: &this->m_mutex, a2: CurrentThreadId, a3: 0);
    }
    else
    {
      ++this->m_mutex.m_depth;
    }
    this->AddRef(this);
    switch ( this->m_status )
    {
      case 1:
      case 4:
        DoExecute = this->DoExecute;
        this->m_status = 2;
        v6 = DoExecute(this);
        this->m_status = v6;
        m_status = v6;
        this->DoCleanup(this);
        CThreadEvent::Set(this: &this->m_CompleteEvent);
        break;
      default:
        m_status = this->m_status;
        break;
    }
    this->Release(this);
    if ( this->m_mutex.m_depth-- == 1 )
      _InterlockedExchange((volatile __int32 *)p_m_mutex, 0);
    return m_status;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10186040
// Name: public: CVProfSpikeDetector::~CVProfSpikeDetector(void)
// Source: json
//------------------------------------------------------------------------------
// write access to const memory has been detected, the output may be wrong!
void __thiscall CVProfSpikeDetector::~CVProfSpikeDetector(CVProfSpikeDetector *this)
{
  unsigned __int64 v2; // kr08_8
  CStatTime *v3; // ecx
  unsigned int m_Int64_high; // ecx
  unsigned int v5; // kr00_4
  unsigned __int64 v6; // [esp+4h] [ebp-Ch] BYREF
  unsigned __int64 *v7; // [esp+Ch] [ebp-4h]

  v7 = &v6;
  v6 = __rdtsc();
  v2 = v6 - this->m_Timer.m_Duration.m_Int64;
  this->m_Timer.m_Duration.m_Int64 = v2;
  if ( _Plat_FloatTime(this: (CStatTime *)v2) - *this->m_timeLast > 2.0 )
  {
    *this->m_timeLast = _Plat_FloatTime(this: v3);
    m_Int64_high = HIDWORD(this->m_Timer.m_Duration.m_Int64);
    LODWORD(v6) = this->m_Timer.m_Duration.m_Int64;
    v5 = v6;
    HIDWORD(v6) = m_Int64_high & 0x80000000;
    LODWORD(v6) = 0;
    if ( (double)__PAIR64__(m_Int64_high, v5) * _g_ClockSpeedMillisecondsMultiplier > this->m_spike )
      _g_VProfSignalSpike = true;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101860F0
// Name: MemTest
// Source: json
//------------------------------------------------------------------------------
bool __cdecl MemTest()
{
  char *m_szMapname; // eax
  bool v1; // bl
  bool verbose; // [esp+Bh] [ebp-1h]

  if ( mem_test_quiet.m_pParent != nullptr && mem_test_quiet.m_pParent->m_Value.m_nValue != 0
    || mem_test_each_frame.m_pParent != nullptr && mem_test_each_frame.m_pParent->m_Value.m_nValue != 0 )
  {
    verbose = false;
  }
  else
  {
    verbose = true;
    _Msg(a1: "\nBegin mem_test\n");
    m_szMapname = sv.m_szMapname;
    if ( sv.m_szMapname[0] == 0 )
      m_szMapname = "nomap";
    V_FileBase(in: m_szMapname, out: mapname, maxlen: 256);
    Host_PrintMemoryStatus(mapname: mapname);
  }
  v1 = _g_pMemAlloc->CrtCheckMemory(this: _g_pMemAlloc) != 0;
  if ( verbose )
    _Msg(a1: "\nEnd mem_test\n");
  return v1;
}

//------------------------------------------------------------------------------
// Address: 0x10186190
// Name: mem_test
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __cdecl mem_test()
{
  MemTest();
}

//------------------------------------------------------------------------------
// Address: 0x101861A0
// Name: void OnChangeThreadAffinity(class IConVar __near *,char const __near *,float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl OnChangeThreadAffinity()
{
  int m_nValue; // eax

  if ( _g_pThreadPool->NumThreads(this: _g_pThreadPool) != 0 )
  {
    if ( threadpool_affinity.m_pParent != nullptr )
      m_nValue = threadpool_affinity.m_pParent->m_Value.m_nValue;
    else
      m_nValue = 0;
    _g_pThreadPool->Distribute(this: _g_pThreadPool, a2: m_nValue != 0, a3: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101861E0
// Name: void ThreadPoolReserverFunction(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ThreadPoolReserverFunction()
{
  CThreadEvent::Wait(this: &g_ReleaseThreadReservation, a2: 0xFFFFFFFF);
  _InterlockedExchangeAdd(&g_NumReservedThreads.m_value, 0xFFFFFFFF);
}

//------------------------------------------------------------------------------
// Address: 0x10186200
// Name: public: bool CAudioState::IsAnyPlayerUnderwater(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CAudioState::IsAnyPlayerUnderwater(CAudioState *this)
{
  int v1; // esi
  bool result; // al

  v1 = 0;
  result = CAudioState::GetPerUser(this, nSlot: -1)->m_PerUser[0].m_bIsUnderwater;
  while ( !result )
  {
    if ( ++v1 != 0 )
      return result;
  }
  return true;
}

//------------------------------------------------------------------------------
// Address: 0x10186220
// Name: void Host_SubscribeForProfileEvents(bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Host_SubscribeForProfileEvents(bool bSubscribe)
{
  int v1; // eax

  if ( (_S3_4 & 1) == 0 )
  {
    _S3_4 |= 1u;
    s_HostSubscribeForProfileEvents.__vftable = (CHostSubscribeForProfileEvents_vtbl *)&CHostSubscribeForProfileEvents::`vftable';
    s_HostSubscribeForProfileEvents.m_bSubscribed = false;
  }
  if ( bSubscribe != s_HostSubscribeForProfileEvents.m_bSubscribed && g_pMatchFramework != nullptr )
  {
    v1 = ((int (*)(void))g_pMatchFramework->GetEventsSubscription)();
    if ( bSubscribe )
    {
      (**(void (__thiscall ***)(int, CHostSubscribeForProfileEvents *))v1)(a1: v1, a2: &s_HostSubscribeForProfileEvents);
      s_HostSubscribeForProfileEvents.m_bSubscribed = bSubscribe;
    }
    else
    {
      (*(void (__thiscall **)(int, CHostSubscribeForProfileEvents *))(*(_DWORD *)v1 + 4))(
        a1: v1,
        a2: &s_HostSubscribeForProfileEvents);
      s_HostSubscribeForProfileEvents.m_bSubscribed = false;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101862A0
// Name: void Host_ResetConfiguration(int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Host_ResetConfiguration(int iController)
{
  vgui::CTreeViewListControl *v1; // ecx
  ECommandTarget_t TraceType; // eax
  IGameEvent *v3; // esi

  TraceType = CTraceFilter::GetTraceType(this: v1);
  Cbuf_AddText(eTarget: TraceType, pText: "exec config.cfg game\n", nTickDelay: 0);
  Cbuf_Execute();
  v3 = g_GameEventManager->CreateEventA(this: g_GameEventManager, a2: "reset_game_titledata", a3: 0, a4: 0);
  if ( v3 != nullptr )
  {
    v3->SetInt(this: v3, a2: "controllerId", a3: iController);
    g_GameEventManager->FireEventClientSide(this: g_GameEventManager, a2: v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10186300
// Name: host_reset_config
// Source: json
//------------------------------------------------------------------------------
void __cdecl host_reset_config(const CCommand *args)
{
  int m_nArgc; // eax
  int v2; // eax

  m_nArgc = args->m_nArgc;
  if ( args->m_nArgc <= 1 || m_nArgc > 2 )
  {
    ConMsg(a1: "Usage:  host_reset_config <controller index>\n");
  }
  else if ( m_nArgc == 2 )
  {
    v2 = atoi(nptr: args->m_ppArgv[1]);
    Host_ResetConfiguration(iController: v2);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10186340
// Name: void Host_ShutdownServer(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall Host_ShutdownServer(int a1@<edi>, int a2@<esi>)
{
  IGameEvent *v2; // esi
  IStaticPropMgrEngine *v3; // eax
  IGameEvent *v4; // esi

  if ( sv.m_State >= ss_active )
  {
    v2 = (IGameEvent *)((int (__thiscall *)(CGameEventManager *, const char *, _DWORD, _DWORD, int))g_GameEventManager->CreateEventA)(
                         a1: g_GameEventManager,
                         a2: "server_pre_shutdown",
                         a3: 0,
                         a4: 0,
                         a5: a2);
    if ( v2 != nullptr )
    {
      v2->SetString(this: v2, a2: "reason", a3: "restart");
      g_GameEventManager->FireEvent(this: g_GameEventManager, a2: v2, a3: false);
    }
    g_pShadowMgr->LevelShutdown(this: g_pShadowMgr);
    v3 = StaticPropMgr();
    v3->LevelShutdown(this: v3);
    if ( !sv.m_bIsDedicated )
      CL_ClearState(a1);
    if ( host_state.worldmodel != nullptr )
    {
      modelloader->UnreferenceModel(this: modelloader, a2: host_state.worldmodel, a3: FMODELLOADER_SERVER);
      modelloader->UnreferenceModel(this: modelloader, a2: host_state.worldmodel, a3: FMODELLOADER_CLIENT);
      if ( host_state.worldmodel != nullptr )
      {
        host_state.worldmodel = nullptr;
        host_state.worldbrush = nullptr;
      }
    }
    modelloader->UnloadUnreferencedModels(this: modelloader);
    g_TimeLastMemTest = 0.0;
    CGameServer::Shutdown(this: &sv);
    CM_FreeMap();
    if ( host_hunklevel != 0 )
      Hunk_FreeToLowMark(mark: host_hunklevel);
    v4 = (IGameEvent *)((int (__thiscall *)(CGameEventManager *, const char *, _DWORD))g_GameEventManager->CreateEventA)(
                         a1: g_GameEventManager,
                         a2: "server_shutdown",
                         a3: 0);
    if ( v4 != nullptr )
    {
      v4->SetString(this: v4, a2: "reason", a3: "restart");
      g_GameEventManager->FireEvent(this: g_GameEventManager, a2: v4, a3: false);
    }
    CLog::Close(this: &g_Log);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10186490
// Name: void Host_AccumulateTime(float)
// Source: json
//------------------------------------------------------------------------------
void __usercall Host_AccumulateTime(float a1@<xmm14>, float dt)
{
  bool v2; // bl
  float interval_per_tick; // xmm0_4
  float m_fValue; // xmm1_4
  float v5; // xmm0_4
  long double v6; // st7
  int v7; // eax
  double v8; // st5
  double v9; // st7
  double v10; // st7
  double v11; // st5
  double v12; // st7
  double v13; // st6
  int v14; // eax
  double v15; // st7
  double v16; // st6
  double v17; // st7
  CClientState *BaseLocalClient; // eax
  double v19; // st7
  double v20; // st6
  double v21; // rt0
  double v22; // st6
  double v23; // st7
  float v24; // [esp+4h] [ebp-8h]
  float v25; // [esp+8h] [ebp-4h]
  float v26; // [esp+8h] [ebp-4h]

  realtime = realtime + dt;
  v2 = !demoplayer->IsPlayingTimeDemo(this: demoplayer);
  if ( g_bDedicatedServerBenchmarkMode || !v2 )
    interval_per_tick = host_state.interval_per_tick;
  else
    interval_per_tick = dt;
  m_fValue = 1.0;
  host_frametime = interval_per_tick;
  if ( host_timescale.m_pParent->m_Value.m_fValue > 0.0 )
  {
    if ( sv_cheats.m_pParent != nullptr && sv_cheats.m_pParent->m_Value.m_nValue != 0 || Cmd_IsRptActive() )
      m_fValue = host_timescale.m_pParent->m_Value.m_fValue;
    else
      m_fValue = 1.0;
  }
  v25 = sv.m_flTimescale * m_fValue;
  if ( demoplayer->IsPlayingBack(this: demoplayer) )
    v25 = ((double (__thiscall *)(IDemoPlayer *))demoplayer->GetPlaybackTimeScale)(a1: demoplayer) * v25;
  if ( host_framerate.m_pParent->m_Value.m_fValue != 0.0
    && (sv_cheats.m_pParent != nullptr && sv_cheats.m_pParent->m_Value.m_nValue != 0
     || Cmd_IsRptActive()
     || demoplayer->IsPlayingBack(this: demoplayer)) )
  {
    v5 = host_framerate.m_pParent->m_Value.m_fValue;
    if ( v5 <= 1.0 )
    {
      if ( v5 < -1.0 )
      {
        v6 = 1.0 / fabs(host_framerate.m_pParent->m_Value.m_fValue);
        if ( v6 <= dt )
        {
          v26 = v6;
          v5 = v26;
        }
        else
        {
          v5 = dt;
        }
      }
    }
    else
    {
      v5 = 1.0 / v5;
    }
    host_frametime = v5;
    host_frametime_unbounded = v5;
    host_frametime_unscaled = v5;
  }
  else if ( v25 == 1.0 )
  {
    v14 = _CommandLine();
    if ( (*(int (__thiscall **)(int, const char *, _DWORD))(*(_DWORD *)v14 + 12))(a1: v14, a2: "-tools", a3: 0) == 0
      || g_bReplayLoadedTools )
    {
      v15 = host_frametime;
      host_frametime_unbounded = host_frametime;
      if ( host_frametime >= 0.1 )
        v15 = 0.1;
    }
    else
    {
      host_frametime_unbounded = host_frametime;
      if ( host_frametime >= 2.0 )
        v15 = 2.0;
      else
        v15 = host_frametime;
    }
    v16 = v15;
    v17 = 0.001;
    if ( v16 > 0.001 )
      v17 = v16;
    host_frametime = v17;
    host_frametime_unscaled = v17;
  }
  else
  {
    host_frametime_unscaled = host_frametime;
    host_frametime = host_frametime * v25;
    host_frametime_unbounded = host_frametime;
    v7 = _CommandLine();
    if ( (*(int (__thiscall **)(int, const char *, _DWORD))(*(_DWORD *)v7 + 12))(a1: v7, a2: "-tools", a3: 0) != 0
      || g_bReplayLoadedTools )
    {
      v11 = v25 * 2.0;
      v12 = host_frametime;
      if ( v11 <= host_frametime )
        v12 = v11;
      v13 = v12;
      v10 = 2.0;
      host_frametime = v13;
      if ( host_frametime_unscaled < 2.0 )
        v10 = host_frametime_unscaled;
    }
    else
    {
      v8 = v25 * 0.1;
      v9 = host_frametime;
      if ( v8 <= host_frametime )
        v9 = v8;
      host_frametime = v9;
      v10 = host_frametime_unscaled;
      if ( host_frametime_unscaled >= 0.1 )
        v10 = 0.1;
    }
    if ( v10 <= 0.001 )
      host_frametime_unscaled = 0.001;
    else
      host_frametime_unscaled = v10;
  }
  BaseLocalClient = GetBaseLocalClient();
  v19 = CClockDriftMgr::AdjustFrameTime(this: &BaseLocalClient->m_ClockDriftMgr, a2: a1, inputFrameTime: host_frametime)
      - host_frametime;
  v20 = host_frametime + v19;
  host_frametime = v20;
  host_frametime_unbounded = host_frametime_unbounded + v19;
  v21 = v20;
  v22 = v19 + host_frametime_unscaled;
  v23 = v21;
  host_frametime_unscaled = v22;
  if ( g_pSoundServices != nullptr )
  {
    v24 = v23;
    ((void (__thiscall *)(ISoundServices *, _DWORD, _DWORD))g_pSoundServices->SetSoundFrametime)(
      a1: g_pSoundServices,
      a2: LODWORD(dt),
      a3: LODWORD(v24));
  }
}

//------------------------------------------------------------------------------
// Address: 0x10186820
// Name: void CL_SendVoicePacket(bool)
// Source: json
//------------------------------------------------------------------------------
void __usercall CL_SendVoicePacket(int a1@<edi>, int a2@<esi>, bool bFinal)
{
  int v3; // eax
  CClientState *BaseLocalClient; // eax
  char uchVoiceData[2048]; // [esp+0h] [ebp-858h] BYREF
  CLC_VoiceData voiceMsg; // [esp+800h] [ebp-58h] BYREF

  if ( Voice_IsRecording() )
  {
    voiceMsg.m_NetChannel = nullptr;
    voiceMsg.__vftable = (CLC_VoiceData_vtbl *)&CLC_VoiceData::`vftable';
    voiceMsg.m_DataIn.m_bOverflow = false;
    voiceMsg.m_DataIn.m_pDebugName = nullptr;
    voiceMsg.m_DataIn.m_nDataBits = -1;
    voiceMsg.m_DataIn.m_nDataBytes = 0;
    bf_write::bf_write(this: &voiceMsg.m_DataOut);
    voiceMsg.m_bReliable = false;
    voiceMsg.m_xuid = 0;
    bf_write::StartWriting(
      this: &voiceMsg.m_DataOut,
      pData: (unsigned __int8 *)uchVoiceData,
      nBytes: 2048,
      iStartBit: 0,
      nBits: -1);
    v3 = 8 * Voice_GetCompressedData(a1: 0, a2: a1, a3: a2, pchDest: uchVoiceData, nCount: 2048, bFinal);
    voiceMsg.m_nLength = v3;
    if ( v3 != 0 )
    {
      CEngine::SetNextState(this: &voiceMsg.m_DataOut, bitPos: v3);
      if ( GetBaseLocalClient()->m_nSignonState == 6 )
      {
        BaseLocalClient = GetBaseLocalClient();
        BaseLocalClient->m_NetChannel->SendNetMsg(
          this: BaseLocalClient->m_NetChannel,
          a2: &voiceMsg,
          a3: false,
          a4: false);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101868E0
// Name: void Host_CheckDumpMemoryStats(void)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __thiscall Host_CheckDumpMemoryStats(CStatTime *this)
{
  int v1; // eax
  char *m_szMapname; // eax
  int m_nValue; // eax
  int v4; // esi
  const char *v5; // eax
  const char *v6; // eax
  const char *v7; // eax
  float v8; // [esp+0h] [ebp-4Ch]
  float v9; // [esp+0h] [ebp-4Ch]
  float v10; // [esp+0h] [ebp-4Ch]
  char *v11; // [esp+Ch] [ebp-40h]
  int value[4]; // [esp+10h] [ebp-3Ch] BYREF
  _BYTE state_8[36]; // [esp+28h] [ebp-24h] OVERLAPPED

  if ( mem_test_each_frame.m_pParent != nullptr && mem_test_each_frame.m_pParent->m_Value.m_nValue != 0 )
  {
    if ( !MemTest() )
    {
      if ( (unsigned __int8)_Plat_IsInDebugSession(a1: this) != 0 )
        goto LABEL_14;
      goto LABEL_15;
    }
  }
  else if ( mem_test_every_n_seconds.m_pParent != nullptr && mem_test_every_n_seconds.m_pParent->m_Value.m_nValue > 0 )
  {
    *(float *)&state_8[32] = _Plat_FloatTime(this);
    v1 = mem_test_every_n_seconds.m_pParent != nullptr ? mem_test_every_n_seconds.m_pParent->m_Value.m_nValue : 0;
    if ( (float)(*(float *)&state_8[32] - g_TimeLastMemTest) > (float)v1 )
    {
      g_TimeLastMemTest = *(float *)&state_8[32];
      if ( !MemTest() )
      {
        if ( (unsigned __int8)_Plat_IsInDebugSession(a1: this) != 0 )
LABEL_14:
          __debugbreak();
LABEL_15:
        _Error(a1: "Heap is corrupt\n");
      }
    }
  }
  if ( mem_periodicdumps.m_pParent->m_Value.m_fValue > 0.0 )
  {
    *(double *)&state_8[28] = _Plat_FloatTime(this);
    if ( *(double *)&state_8[28] - g_flLastPeriodicMemDump > mem_periodicdumps.m_pParent->m_Value.m_fValue )
    {
      m_szMapname = sv.m_szMapname;
      if ( sv.m_szMapname[0] == 0 )
        m_szMapname = "nomap";
      V_FileBase(in: m_szMapname, out: mapname, maxlen: 256);
      Host_PrintMemoryStatus(mapname: mapname);
      v11 = mapname;
      ((void (__thiscall *)(IMemAlloc *))_g_pMemAlloc->DumpStatsFileBase)(a1: _g_pMemAlloc);
      g_flLastPeriodicMemDump = *(double *)&state_8[28];
    }
  }
  if ( mem_dumpstats.m_pParent != nullptr )
  {
    m_nValue = mem_dumpstats.m_pParent->m_Value.m_nValue;
    if ( m_nValue > 0 )
    {
      if ( m_nValue == 1 )
        CLoaderMemAlloc::CrtIsValidPointer(
          this: (ConVar *)&mem_dumpstats.IConVar,
          value: 0,
          a2: (unsigned int)v11,
          a3: value[0]);
      _V_memset(dest: value, fill: 0, count: 52);
      v4 = *(_DWORD *)&state_8[16]
         + *(_DWORD *)&state_8[12]
         + *(_DWORD *)&state_8[8]
         + *(_DWORD *)state_8
         + *(_DWORD *)&state_8[4];
      _Msg(a1: "MEMORY:  Run-time Heap\n------------------------------------\n");
      v8 = (float)*(unsigned int *)&state_8[20];
      v5 = V_pretifymem(value: v8, digitsafterdecimal: 4, usebinaryonek: false);
      _Msg(a1: "\tHigh water %s\n", v5);
      *(_DWORD *)&state_8[32] = v4;
      v9 = (float)(unsigned int)v4;
      v6 = V_pretifymem(value: v9, digitsafterdecimal: 4, usebinaryonek: false);
      _Msg(a1: "\tCurrent mem %s\n", v6);
      _Msg(a1: "------------------------------------\n");
      *(_DWORD *)&state_8[32] = v4 - Hunk_MallocSize();
      v10 = (float)*(unsigned int *)&state_8[32];
      v7 = V_pretifymem(value: v10, digitsafterdecimal: 2, usebinaryonek: false);
      _Msg(a1: "\tAllocated outside hunk:  %s\n", v7);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10186AE0
// Name: void _Host_SetGlobalTime(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl _Host_SetGlobalTime()
{
  int m_nServerCount; // eax

  g_ServerGlobalVariables.realtime = realtime;
  g_ServerGlobalVariables.absoluteframetime = host_frametime;
  g_ServerGlobalVariables.framecount = host_framecount;
  g_ServerGlobalVariables.interval_per_tick = host_state.interval_per_tick;
  if ( GetBaseLocalClient()->m_nSignonState >= 3
    || GetBaseLocalClient()->m_nSignonState >= 2 && GetBaseLocalClient()->m_bServerInfoProcessed )
  {
    m_nServerCount = GetBaseLocalClient()->m_nServerCount;
  }
  else if ( sv.m_State < ss_loading )
  {
    m_nServerCount = gHostSpawnCount;
  }
  else
  {
    m_nServerCount = sv.m_nSpawnCount;
  }
  g_ClientGlobalVariables.realtime = realtime;
  g_ClientGlobalVariables.absoluteframetime = host_frametime;
  g_ServerGlobalVariables.serverCount = m_nServerCount;
  g_ClientGlobalVariables.framecount = host_framecount;
  g_ClientGlobalVariables.interval_per_tick = host_state.interval_per_tick;
}

//------------------------------------------------------------------------------
// Address: 0x10186BA0
// Name: bool CheckVarRange_Generic(class ConVar __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
char __cdecl CheckVarRange_Generic(ConVar *pVar, int minVal, int maxVal)
{
  ConVar *m_pParent; // ecx
  int m_nValue; // eax
  int v7; // esi
  int v8; // eax
  int v9; // eax
  const char *v10; // eax
  int v11; // [esp-Ch] [ebp-Ch]

  if ( bInFunction )
    return 1;
  bInFunction = true;
  if ( (sv_cheats.m_pParent == nullptr || sv_cheats.m_pParent->m_Value.m_nValue == 0)
    && !Cmd_IsRptActive()
    && !(sv.m_State < ss_active ? GetBaseLocalClient()->m_nMaxClients == 1 : sv.m_nMaxclients <= 1) )
  {
    m_pParent = pVar->m_pParent;
    if ( m_pParent != nullptr )
      m_nValue = m_pParent->m_Value.m_nValue;
    else
      m_nValue = 0;
    v7 = minVal;
    if ( m_nValue >= minVal )
    {
      v7 = maxVal;
      if ( m_nValue <= maxVal )
        v7 = m_nValue;
    }
    if ( m_pParent != nullptr )
      v8 = m_pParent->m_Value.m_nValue;
    else
      v8 = 0;
    if ( v7 != v8 )
    {
      if ( m_pParent != nullptr )
        v9 = m_pParent->m_Value.m_nValue;
      else
        v9 = 0;
      v10 = (const char *)((int (__thiscall *)(ConVar *, int))pVar->GetName)(a1: pVar, a2: v9);
      _Warning(a1: "sv_cheats=0 prevented changing %s outside of the range [0,2] (was %d).\n", v10, v11);
      pVar->SetValue_2(this: &pVar->IConVar, a2: v7);
    }
  }
  bInFunction = false;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10186C70
// Name: void _Host_RunFrame_Render(void)
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __usercall _Host_RunFrame_Render(unsigned int a1@<esi>)
{
  ConVar *v1; // eax
  CStatTime *v2; // ecx
  int m_nValue; // esi
  CStatTime *v4; // ecx
  const char *v6; // [esp-18h] [ebp-18h]
  unsigned int v7; // [esp-14h] [ebp-14h]
  int v8; // [esp-10h] [ebp-10h]
  unsigned int v9; // [esp-Ch] [ebp-Ch]
  int v10; // [esp-8h] [ebp-8h]

  v1 = pVar;
  if ( pVar != nullptr
    || (v6 = "mat_picmip",
        v1 = (ConVar *)((int (__thiscall *)(ICvar *))g_pCVar->FindVar_2)(a1: g_pCVar),
        pVar = v1,
        v1 != nullptr) )
  {
    CheckVarRange_Generic(pVar: v1, minVal: -10, maxVal: 2);
  }
  CheckVarRange_r_rootlod();
  r_lod_f();
  if ( mat_norendering.m_pParent != nullptr )
    m_nValue = mat_norendering.m_pParent->m_Value.m_nValue;
  else
    m_nValue = 0;
  if ( cl_takesnapshot )
    CLoaderMemAlloc::CrtIsValidPointer(this: (ConVar *)&mat_norendering.IConVar, value: 0, a2: a1, a3: (int)v6);
  g_HostTimes.starttime[3] = _Plat_FloatTime(this: v2);
  CL_LatchInterpolationAmount();
  if ( r_ForceRestore.m_pParent != nullptr && r_ForceRestore.m_pParent->m_Value.m_nValue != 0 )
  {
    ForceMatSysRestore();
    CLoaderMemAlloc::CrtIsValidPointer(this: (ConVar *)&r_ForceRestore.IConVar, value: 0, a2: v7, a3: v8);
  }
  SCR_UpdateScreen();
  CL_DecayLights();
  g_HostTimes.deltas[3] = _Plat_FloatTime(this: v4) - g_HostTimes.starttime[3] + g_HostTimes.deltas[3];
  saverestore->OnFrameRendered(this: saverestore);
  CLoaderMemAlloc::CrtIsValidPointer(this: (ConVar *)&mat_norendering.IConVar, value: m_nValue, a2: v9, a3: v10);
}

//------------------------------------------------------------------------------
// Address: 0x10186D40
// Name: void _Host_RunFrame_Sound(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl _Host_RunFrame_Sound()
{
  CStatTime *v0; // ecx
  CStatTime *v1; // ecx
  IMDLCache *v2; // esi

  if ( g_pSoundJob == nullptr )
  {
    CVProfile::EnterScope(
      this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
      a2: "_Host_RunFrame_Sound",
      a3: 0,
      a4: "Sound",
      a5: false,
      a6: 4);
    g_HostTimes.starttime[4] = _Plat_FloatTime(this: v0);
    if ( host_threaded_sound.m_pParent == nullptr
      || host_threaded_sound.m_pParent->m_Value.m_nValue == 0
      || !g_bAllowThreadedSound )
    {
      v2 = g_pMDLCache;
      g_pMDLCache->BeginCoarseLock(this: g_pMDLCache);
      if ( GetBaseLocalClient()->m_nSignonState == 6 )
        S_Update(pAudioState: &s_AudioState);
      else
        S_Update(pAudioState: nullptr);
      v2->EndCoarseLock(this: v2);
    }
    g_HostTimes.deltas[4] = _Plat_FloatTime(this: v1) - g_HostTimes.starttime[4] + g_HostTimes.deltas[4];
    CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10186DF0
// Name: void HLTV_Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl HLTV_Shutdown()
{
  CHLTVTestSystem *v0; // esi

  if ( hltv != nullptr )
  {
    hltv->Shutdown(this: &hltv->CBaseServer);
    if ( hltv != nullptr )
      ((void (__thiscall *)(CHLTVServer *, int))hltv->dtr_IGameEventListener2)(a1: hltv, a2: 1);
    hltv = nullptr;
  }
  if ( hltvtest != nullptr )
  {
    v0 = hltvtest;
    CHLTVTestSystem::~CHLTVTestSystem(this: hltvtest);
    free(pMem: v0);
    hltvtest = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10186E60
// Name: void Host_Changelevel(bool,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __usercall Host_Changelevel(
        int a1@<ebx>,
        int a2@<edi>,
        int a3@<esi>,
        bool loadfromsavedgame,
        const char *mapname,
        const char *start)
{
  CStatTime *v6; // ecx
  IEngineVGuiInternal *v7; // eax
  const char *v8; // esi
  vgui::PropertyPage *v9; // ecx
  int v10; // edi
  int v11; // edi
  int v12; // ebx
  int v13; // edi
  KeyValues *v14; // eax
  KeyValues *v15; // esi
  IMatchEventsSubscription *v16; // eax
  char *v17; // edi
  vgui::CTreeViewListControl *v18; // ecx
  ECommandTarget_t TraceType; // eax
  vgui::CTreeViewListControl *v20; // ecx
  ECommandTarget_t v21; // eax
  CDownloadListGenerator *v22; // eax
  CServerPlugin_vtbl *v23; // esi
  char *v24; // eax
  int Time; // eax
  ISaveRestore_vtbl *v26; // esi
  int (__thiscall *GetMostRecentElapsedMinutes)(ISaveRestore *); // edx
  int v28; // eax
  ISaveRestore_vtbl *v29; // esi
  int v30; // edi
  CDownloadListGenerator *v31; // eax
  int v32; // [esp-8h] [ebp-23Ch]
  int v34; // [esp-4h] [ebp-238h]
  char dxMapName[260]; // [esp+0h] [ebp-234h] BYREF
  char _startspot[96]; // [esp+104h] [ebp-130h] BYREF
  char oldlevel[96]; // [esp+164h] [ebp-D0h] BYREF
  char level[96]; // [esp+1C4h] [ebp-70h] BYREF
  CAddTransitionResourcesCB addTransitionResources; // [esp+224h] [ebp-10h] BYREF
  char *startspot; // [esp+230h] [ebp-4h]

  if ( sv.m_State >= ss_active )
  {
    if ( demoplayer->IsPlayingBack(this: demoplayer) )
    {
      ConMsg(a1: "Changelevel invalid during demo playback\n");
    }
    else
    {
      if ( sv.m_bIsDedicated )
      {
        v8 = mapname;
      }
      else
      {
        v7 = EngineVGui();
        v8 = mapname;
        v7->SetProgressLevelName(this: v7, a2: mapname);
      }
      SCR_BeginLoadingPlaque(a1: v6, a2, levelName: v8);
      g_pFileSystem->AsyncFinishAll(this: g_pFileSystem, a2: 0);
      S_StopAllSounds(bClear: true);
      V_strncpy(pDest: dxMapName, pSrc: v8, maxLen: 260);
      if ( g_pMaterialSystemHardwareConfig != nullptr )
      {
        V_StripExtension(in: v8, out: dxMapName, outSize: 260);
        V_strncat(pDest: dxMapName, pSrc: ".bsp", destBufferSize: 0x104u, max_chars_to_copy: -1);
      }
      CLoaderMemAlloc::CrtSetReportMode(this: (ConVar *)&host_map.IConVar, value: dxMapName, a2: a3);
      V_strncpy(pDest: level, pSrc: v8, maxLen: 96);
      if ( start != nullptr )
      {
        V_strncpy(pDest: _startspot, pSrc: start, maxLen: 96);
        *(float *)&startspot = COERCE_FLOAT(_startspot);
      }
      else
      {
        *(float *)&startspot = 0.0;
      }
      _Warning(a1: "---- Host_Changelevel ----\n", a2, a1);
      CColorBalanceUIPanel::Init(this: v9);
      ((void (__thiscall *)(IMaterialSystem *, int, int))materials->OnLevelShutdown)(a1: materials, a2: v32, a3: v34);
      saverestore->SetIsXSave(this: saverestore, a2: false);
      v10 = (int)(float)(g_ServerGlobalVariables.curtime
                       - (float)saverestore->GetMostRecentElapsedTimeSet(this: saverestore));
      v11 = saverestore->GetMostRecentElapsedSeconds(this: saverestore) + v10;
      v12 = v11 / 60 + saverestore->GetMostRecentElapsedMinutes(this: saverestore);
      saverestore->SetMostRecentElapsedMinutes(this: saverestore, a2: v12);
      v13 = v11 % 60;
      saverestore->SetMostRecentElapsedSeconds(this: saverestore, a2: v13);
      v14 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v14 != nullptr )
        v15 = KeyValues::KeyValues(this: v14, setName: "OnHostChangeLevel");
      else
        v15 = nullptr;
      KeyValues::SetString(this: v15, keyName: "map", value: mapname);
      KeyValues::SetUint64(this: v15, keyName: "elapsed", value: v13 + 60 * v12);
      KeyValues::SetInt(this: v15, keyName: "bysave", value: 0);
      v16 = g_pMatchFramework->GetEventsSubscription(this: g_pMatchFramework);
      v16->BroadcastEvent(this: v16, a2: v15);
      V_strncpy(pDest: oldlevel, pSrc: sv.m_szMapname, maxLen: 96);
      LOBYTE(v12) = loadfromsavedgame;
      v17 = startspot;
      if ( !loadfromsavedgame
        || (addTransitionResources.m_pLevelName = level,
            addTransitionResources.__vftable = (CAddTransitionResourcesCB_vtbl *)&CAddTransitionResourcesCB::`vftable',
            addTransitionResources.m_pLandMarkName = startspot,
            saverestore->SaveGameState(this: saverestore, a2: true, a3: &addTransitionResources, a4: true, a5: false)) )
      {
        g_pServerPluginHandler->LevelShutdown(this: g_pServerPluginHandler);
        audiosourcecache->LevelShutdown(this: audiosourcecache);
        CBaseServer::InactivateClients(this: &sv);
        saverestore->FinishAsyncSave(this: saverestore);
        if ( IsUsingMasterLegacyMode()
          && (v18 = (vgui::CTreeViewListControl *)g_pMaster, g_pMaster != nullptr)
          && g_pMaster->RestartOnLevelChange(this: g_pMaster)
          || sv.m_bRestartOnLevelChange )
        {
          TraceType = CTraceFilter::GetTraceType(this: v18);
          Cbuf_Clear(eTarget: TraceType);
          v21 = CTraceFilter::GetTraceType(this: v20);
          Cbuf_AddText(eTarget: v21, pText: "quit\n", nTickDelay: 0);
        }
        else
        {
          v22 = DownloadListGenerator();
          CDownloadListGenerator::OnLevelLoadStart(this: v22, levelName: level);
          _COM_TimestampedLog(a1: "*** Map Load: %s", level);
          if ( CGameServer::SpawnServer(this: &sv, mapname: level, startspot: v17) != 0 )
          {
            g_ServerGlobalVariables.curtime = CBaseServer::GetTime(this: &sv);
            ((void (__thiscall *)(IAudioSourceCache *, char *, _DWORD))audiosourcecache->LevelInit)(
              a1: audiosourcecache,
              a2: level,
              a3: *(_DWORD *)dxMapName);
            v23 = g_pServerPluginHandler->__vftable;
            *(_DWORD *)dxMapName = 0;
            v24 = CM_EntityString();
            if ( loadfromsavedgame )
            {
              ((void (__thiscall *)(CServerPlugin *, char *, char *, char *, char *, int))v23->LevelInit)(
                a1: g_pServerPluginHandler,
                a2: level,
                a3: v24,
                a4: oldlevel,
                a5: v17,
                a6: 1);
              CBaseServer::SetPaused(this: &sv, paused: true);
              sv.m_bLoadgame = true;
            }
            else
            {
              ((void (__thiscall *)(CServerPlugin *, char *, char *, _DWORD, _DWORD, _DWORD))v23->LevelInit)(
                a1: g_pServerPluginHandler,
                a2: level,
                a3: v24,
                a4: 0,
                a5: 0,
                a6: 0);
            }
            SV_ActivateServer(a1: v12);
            Time = (int)CBaseServer::GetTime(this: &sv);
            v26 = saverestore->__vftable;
            GetMostRecentElapsedMinutes = saverestore->GetMostRecentElapsedMinutes;
            *(float *)&startspot = (float)Time;
            v28 = GetMostRecentElapsedMinutes(this: saverestore);
            v26->SetMostRecentElapsedMinutes(
              this: saverestore,
              a2: v28 - (int)(float)(*(float *)&startspot * 0.016666668));
            v29 = saverestore->__vftable;
            v30 = saverestore->GetMostRecentElapsedSeconds(this: saverestore);
            v29->SetMostRecentElapsedSeconds(this: saverestore, a2: v30 - (int)fmod(*(float *)&startspot, 60.0));
            saverestore->ForgetRecentSave(this: saverestore);
            NotifyDedicatedServerUI(message: "UpdateMap");
            v31 = DownloadListGenerator();
            CDownloadListGenerator::OnLevelLoadEnd(this: v31);
          }
        }
      }
      else
      {
        _Warning(a1: "Failed to save data for transition\n");
        SCR_EndLoadingPlaque();
      }
    }
  }
  else
  {
    ConMsg(a1: "Only the server may changelevel\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x101872F0
// Name: bool Host_NewGame(char __near *,bool,bool,bool,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __usercall Host_NewGame@<al>(
        int a1@<edi>,
        char *mapName,
        int loadGame,
        BOOL bBackgroundLevel,
        bool bSplitScreenConnect,
        const char *pszOldMap,
        const char *pszLandmark)
{
  vgui::PropertyPage *v7; // ecx
  char *m_pszString; // eax
  CStatTime *v9; // ecx
  IEngineVGuiInternal *v10; // eax
  CMapReslistGenerator *v11; // eax
  CDownloadListGenerator *v12; // eax
  int v13; // ebx
  IMatchTitle *v14; // eax
  bool v15; // al
  char *v16; // eax
  CSteam3Client *v17; // eax
  CSteam3Client *v18; // eax
  const char *v19; // eax
  const char *v21; // eax
  IEngineVGuiInternal *v22; // eax
  CServerPlugin_vtbl *v23; // edi
  char *v24; // eax
  vgui::CTreeViewListControl *v25; // ecx
  ECommandTarget_t TraceType; // eax
  vgui::PropertyPage *v27; // eax
  CDownloadListGenerator *v28; // eax
  int UDPPort; // [esp-34h] [ebp-43Ch]
  int v30; // [esp-34h] [ebp-43Ch]
  int max_splitscreen_players; // [esp-30h] [ebp-438h]
  const char *v32; // [esp-24h] [ebp-42Ch]
  const char *v33; // [esp-20h] [ebp-428h]
  BOOL v34; // [esp-18h] [ebp-420h]
  char *v35; // [esp-Ch] [ebp-414h]
  char str[512]; // [esp+0h] [ebp-408h] BYREF
  char previousMapName[260]; // [esp+200h] [ebp-208h] BYREF
  char dxMapName[260]; // [esp+304h] [ebp-104h] BYREF

  _COM_TimestampedLog(a1: "Host_NewGame");
  if ( bBackgroundLevel )
    CColorBalanceUIPanel::Init(this: v7);
  V_strncpy(pDest: dxMapName, pSrc: mapName, maxLen: 260);
  if ( g_pMaterialSystemHardwareConfig != nullptr )
  {
    V_StripExtension(in: mapName, out: dxMapName, outSize: 260);
    V_strncat(pDest: dxMapName, pSrc: ".bsp", destBufferSize: 0x104u, max_chars_to_copy: -1);
  }
  if ( (host_map.m_nFlags & 0x1000) != 0 )
  {
    m_pszString = "FCVAR_NEVER_AS_STRING";
  }
  else
  {
    m_pszString = host_map.m_pParent->m_Value.m_pszString;
    if ( m_pszString == nullptr )
      m_pszString = (char *)defaultValue;
  }
  V_strncpy(pDest: previousMapName, pSrc: m_pszString, maxLen: 260);
  CLoaderMemAlloc::CrtSetReportMode(this: (ConVar *)&host_map.IConVar, value: dxMapName, a2: a1);
  CGameServer::ExecGameTypeCfg(this: &sv, mapname: mapName);
  if ( !sv.m_bIsDedicated )
  {
    v10 = EngineVGui();
    v35 = mapName;
    ((void (__thiscall *)(IEngineVGuiInternal *))v10->SetProgressLevelName)(a1: v10);
  }
  SCR_BeginLoadingPlaque(a1: v9, a2: a1, levelName: mapName);
  _Warning(a1: "---- Host_NewGame ----\n");
  CColorBalanceUIPanel::Init(this: (vgui::PropertyPage *)previousMapName);
  materials->OnLevelShutdown(this: materials);
  v11 = MapReslistGenerator();
  CMapReslistGenerator::OnLevelLoadStart(this: v11, levelName: mapName);
  v12 = DownloadListGenerator();
  CDownloadListGenerator::OnLevelLoadStart(this: v12, levelName: mapName);
  v13 = loadGame;
  if ( (_BYTE)loadGame == 0 )
    HostState_RunGameInit();
  NET_SetMultiplayer(multiplayer: sv.m_nMaxclients > 1);
  if ( sv.m_nMaxclients <= 1 )
  {
    v14 = g_pMatchFramework->GetMatchTitle(this: g_pMatchFramework);
    v15 = (v14->GetTitleSettingsFlags(this: v14) & 1) != 0;
    NET_SetMultiplayer(multiplayer: v15);
  }
  NET_ListenSocket(sock: sv.m_Socket, bListen: true);
  if ( (host_name.m_nFlags & 0x1000) == 0 )
  {
    v16 = host_name.m_pParent->m_Value.m_pszString;
    if ( v16 == nullptr || *v16 == 0 )
    {
      if ( sv.m_bIsDedicated
        || Steam3Client()->m_pSteamUser == nullptr
        || (v17 = Steam3Client(), !v17->m_pSteamUser->BLoggedOn(this: v17->m_pSteamUser))
        || (v18 = Steam3Client(), *(v19 = v18->m_pSteamFriends->GetPersonaName(this: v18->m_pSteamFriends)) == 0) )
      {
        v19 = serverGameDLL->GetGameDescription(this: serverGameDLL);
      }
      CLoaderMemAlloc::CrtSetReportMode(this: (ConVar *)&host_name.IConVar, value: v19, a2: (int)v35);
    }
  }
  _COM_TimestampedLog(a1: "*** Map Load: %s", mapName);
  HostState_Pre_LoadMapIntoMemory();
  if ( CGameServer::SpawnServer(this: &sv, mapname: mapName, startspot: nullptr) == 0 )
  {
    HostState_Post_FlushMapFromMemory();
    return 0;
  }
  sv.m_bIsLevelMainMenuBackground = bBackgroundLevel;
  v21 = " (background map)";
  if ( !bBackgroundLevel )
    v21 = defaultValue;
  loadGame = 65280;
  ConColorMsg(a1: (const struct Color *)&loadGame, a2: "Host_NewGame on map %s%s\n", mapName, v21);
  g_ServerGlobalVariables.curtime = CBaseServer::GetTime(this: &sv);
  _COM_TimestampedLog(a1: "serverGameDLL->LevelInit");
  v22 = EngineVGui();
  v22->UpdateProgressBar(this: v22, a2: PROGRESS_LEVELINIT, a3: true);
  audiosourcecache->LevelInit(this: audiosourcecache, a2: mapName);
  v23 = g_pServerPluginHandler->__vftable;
  v34 = bBackgroundLevel;
  v33 = pszLandmark;
  v32 = pszOldMap;
  v24 = CM_EntityString();
  v23->LevelInit(this: g_pServerPluginHandler, a2: mapName, a3: v24, a4: v32, a5: v33, a6: v13, a7: v34);
  if ( (_BYTE)v13 != 0 )
  {
    CBaseServer::SetPaused(this: &sv, paused: true);
    sv.m_bLoadgame = true;
    g_ServerGlobalVariables.curtime = CBaseServer::GetTime(this: &sv);
  }
  if ( SV_ActivateServer(a1: v13) == 0 )
    return 0;
  if ( sv.m_bIsDedicated )
  {
    CTestScriptMgr::CheckPoint(this: &g_TestScriptMgr, pName: "FinishedMapLoad");
  }
  else
  {
    _COM_TimestampedLog(a1: "Stuff 'connect localhost' to console");
    if ( bSplitScreenConnect && host_state.max_splitscreen_players > 1 )
    {
      max_splitscreen_players = host_state.max_splitscreen_players;
      UDPPort = NET_GetUDPPort(socket: sv.m_Socket);
      V_snprintf(
        pDest: str,
        maxLen: 512,
        pFormat: "connect_splitscreen localhost:%d %d",
        UDPPort,
        max_splitscreen_players);
    }
    else
    {
      v30 = NET_GetUDPPort(socket: sv.m_Socket);
      V_snprintf(pDest: str, maxLen: 512, pFormat: "connect localhost:%d", v30);
    }
    TraceType = CTraceFilter::GetTraceType(this: v25);
    Cbuf_AddText(eTarget: TraceType, pText: str, nTickDelay: 0);
  }
  if ( (_BYTE)v13 == 0 )
    saverestore->ForgetRecentSave(this: saverestore);
  saverestore->SetMostRecentElapsedMinutes(this: saverestore, a2: 0);
  saverestore->SetMostRecentElapsedSeconds(this: saverestore, a2: 0);
  if ( MapReslistGenerator()->m_bLoggingEnabled )
  {
    v27 = (vgui::PropertyPage *)MapReslistGenerator();
    CColorBalanceUIPanel::Init(this: v27);
  }
  v28 = DownloadListGenerator();
  CDownloadListGenerator::OnLevelLoadEnd(this: v28);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101876E0
// Name: public: virtual char const __near * CJob::Describe(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CJob::Describe(CJob *this)
{
  return "Job";
}

//------------------------------------------------------------------------------
// Address: 0x101876F0
// Name: private: virtual int CJob::DoAbort(bool)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CJob::DoAbort(CJob *this, bool bDiscard)
{
  return 3;
}

//------------------------------------------------------------------------------
// Address: 0x10187740
// Name: public: CFunctorJob::CFunctorJob(class CFunctor __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CFunctorJob *__thiscall CFunctorJob::CFunctorJob(CFunctorJob *this, CFunctor *pFunctor, const char *pszDescription)
{
  this->m_iRefs = 1;
  this->m_priority = JP_NORMAL;
  this->CJob::CRefCounted1<IRefCounted,CRefCountServiceBase<1,CRefMT> >::IRefCounted::__vftable = (CFunctorJob_vtbl *)&CJob::`vftable'{for `IRefCounted'};
  this->CJob::CRefCounted1<IRefCounted,CRefCountServiceBase<1,CRefMT> >::CRefCountServiceBase<1,CRefMT>::__vftable = (CRefCountServiceBase<1,CRefMT>_vtbl *)&CJob::`vftable'{for `CRefCountServiceBase<1,CRefMT>'};
  this->m_status = 4;
  this->m_mutex.m_ownerID = 0;
  this->m_mutex.m_depth = 0;
  this->m_flags = 0;
  this->m_iServicingThread = -1;
  this->m_ThreadPoolData = (ThreadPoolData_t__ *)-1;
  this->m_pThreadPool = nullptr;
  CThreadEvent::CThreadEvent(this: &this->m_CompleteEvent, a2: true);
  this->CJob::CRefCounted1<IRefCounted,CRefCountServiceBase<1,CRefMT> >::IRefCounted::__vftable = (CFunctorJob_vtbl *)&CFunctorJob::`vftable'{for `IRefCounted'};
  this->CJob::CRefCounted1<IRefCounted,CRefCountServiceBase<1,CRefMT> >::CRefCountServiceBase<1,CRefMT>::__vftable = (CRefCountServiceBase<1,CRefMT>_vtbl *)&CFunctorJob::`vftable'{for `CRefCountServiceBase<1,CRefMT>'};
  this->m_pFunctor.m_pObject = pFunctor;
  if ( pszDescription != nullptr )
    V_strncpy(pDest: this->m_szDescription, pSrc: pszDescription, maxLen: 16);
  else
    this->m_szDescription[0] = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x101877F0
// Name: public: virtual int CFunctorJob::DoExecute(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CFunctorJob::DoExecute(CFunctorJob *this)
{
  this->m_pFunctor.m_pObject->operator()(this: this->m_pFunctor.m_pObject);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10187840
// Name: void _Host_RunFrame_Server(bool)
// Source: json
//------------------------------------------------------------------------------
void __usercall _Host_RunFrame_Server(int a1@<ebx>, int a2@<edi>, int finaltick)
{
  float m_fValue; // xmm0_4
  CStatTime *v4; // ecx
  CVProfSpikeDetector generated_id_17; // [esp+0h] [ebp-14h] BYREF
  CVProfSpikeDetector *p_generated_id_17; // [esp+10h] [ebp-4h]

  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "_Host_RunFrame_Server",
    a3: 0,
    a4: "Game",
    a5: false,
    a6: 4);
  if ( (_S4_1 & 1) == 0 )
  {
    _S4_1 |= 1u;
    counter_3.m_pCounter = CVProfile::FindOrCreateCounter(
                             this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
                             a2: "ticks",
                             a3: COUNTER_GROUP_DEFAULT);
    atexit(func: _Host_RunFrame_Server_::_4_::_dynamic_atexit_destructor_for___counter__);
  }
  ++*counter_3.m_pCounter;
  m_fValue = vprof_server_spike_threshold.m_pParent->m_Value.m_fValue;
  generated_id_17.m_timeLast = (float *)&`CVProfSpikeDetector::GetTimeLast'::`2'::timeLast;
  generated_id_17.m_spike = m_fValue;
  p_generated_id_17 = &generated_id_17;
  generated_id_17.m_Timer.m_Duration.m_Int64 = __rdtsc();
  g_HostTimes.starttime[2] = _Plat_FloatTime(this: (CStatTime *)&generated_id_17);
  SV_Frame(a1, a2, finalTick: finaltick);
  g_HostTimes.deltas[2] = _Plat_FloatTime(this: v4) - g_HostTimes.starttime[2] + g_HostTimes.deltas[2];
  CVProfSpikeDetector::~CVProfSpikeDetector(this: &generated_id_17);
  CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
}

//------------------------------------------------------------------------------
// Address: 0x10187920
// Name: void _Host_RunFrame_Server_Async(int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl _Host_RunFrame_Server_Async(int numticks)
{
  DWORD CurrentThreadId; // eax
  IMDLCache *v2; // edi
  int v3; // esi
  int v4; // edi
  IMDLCache *cacheCoarseCriticalSection; // [esp+Ch] [ebp-4h]

  if ( vprof_server_thread.m_pParent != nullptr && vprof_server_thread.m_pParent->m_Value.m_nValue != 0 )
  {
    if ( g_VProfTargetThread == GetCurrentThreadId() )
      goto LABEL_8;
    CurrentThreadId = GetCurrentThreadId();
  }
  else
  {
    if ( g_VProfTargetThread != GetCurrentThreadId() )
      goto LABEL_8;
    CurrentThreadId = g_MainThreadId;
  }
  g_VProfTargetThread = CurrentThreadId;
LABEL_8:
  v2 = g_pMDLCache;
  cacheCoarseCriticalSection = g_pMDLCache;
  g_pMDLCache->BeginCoarseLock(this: g_pMDLCache);
  v3 = 0;
  if ( numticks > 0 )
  {
    v4 = numticks;
    do
    {
      g_ServerGlobalVariables.tickcount = sv.m_nTickCount;
      g_ServerGlobalVariables.simTicksThisFrame = v4;
      _Host_RunFrame_Server(a1: numticks, a2: v4--, finaltick: v3++ == numticks - 1);
    }
    while ( v3 < numticks );
    v2 = cacheCoarseCriticalSection;
  }
  v2->EndCoarseLock(this: v2);
}

//------------------------------------------------------------------------------
// Address: 0x101879D0
// Name: void CL_FindInterpolatedAddAngle(float,float __near &,struct AddAngle __near * __near *,struct AddAngle __near * __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CL_FindInterpolatedAddAngle(float t, float *frac, AddAngle **prev, AddAngle **next)
{
  int m_Size; // edi
  AddAngle *v5; // ebx
  int v6; // esi
  AddAngle *m_pMemory; // edx
  float starttime; // xmm1_4
  AddAngle *v9; // eax
  float v10; // xmm1_4
  float v11; // xmm0_4
  int v12; // xmm1_4

  m_Size = GetLocalClient(nSlot: -1)->addangle.m_Size;
  v5 = nullptr;
  v6 = 0;
  *prev = nullptr;
  *next = nullptr;
  if ( m_Size > 0 )
  {
    while ( 1 )
    {
      m_pMemory = GetLocalClient(nSlot: -1)->addangle.m_Memory.m_pMemory;
      starttime = m_pMemory[v6].starttime;
      v9 = &m_pMemory[v6];
      *next = v9;
      if ( starttime > t )
        break;
      ++v6;
      *prev = v9;
      v5 = v9;
      if ( v6 >= m_Size )
        return;
    }
    if ( v6 != 0 )
    {
      v10 = v9->starttime;
      if ( v10 == v5->starttime )
      {
        *frac = 0.0;
      }
      else
      {
        v11 = (float)(t - v5->starttime) / (float)(v10 - v5->starttime);
        v12 = 0;
        *frac = v11;
        if ( v11 < 0.0 || (v12 = 1065353216, v11 > 1.0) )
          v11 = *(float *)&v12;
        *frac = v11;
      }
    }
    else
    {
      *prev = v9;
      *frac = 0.0;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10187AD0
// Name: public: virtual CDebugInputThread::~CDebugInputThread(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDebugInputThread::~CDebugInputThread(CDebugInputThread *this)
{
  bool v2; // sf

  this->__vftable = (CDebugInputThread_vtbl *)&CDebugInputThread::`vftable';
  v2 = this->m_inputString.m_Storage.m_Memory.m_nGrowSize < 0;
  this->m_inputString.m_Storage.m_nActualLength = 0;
  if ( !v2 )
  {
    if ( this->m_inputString.m_Storage.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_inputString.m_Storage.m_Memory.m_pMemory);
      this->m_inputString.m_Storage.m_Memory.m_pMemory = nullptr;
    }
    this->m_inputString.m_Storage.m_Memory.m_nAllocationCount = 0;
  }
  CThreadMutex::~CThreadMutex(this: &this->m_mx);
  CThread::~CThread(this);
}

//------------------------------------------------------------------------------
// Address: 0x10187B60
// Name: bool GetFileFromRemoteStorage(class ISteamRemoteStorage __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl GetFileFromRemoteStorage(
        ISteamRemoteStorage *pRemoteStorage,
        const char *pszRemoteFileName,
        const char *pszLocalFileName)
{
  bool v3; // bl
  int v4; // esi
  void *v5; // edi
  void *buf; // [esp+Ch] [ebp-Ch]

  v3 = false;
  v4 = pRemoteStorage->GetFileSize(this: pRemoteStorage, a2: pszRemoteFileName);
  if ( v4 > 0 )
  {
    buf = _g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v4);
    if ( pRemoteStorage->FileRead(this: pRemoteStorage, a2: pszRemoteFileName, a3: buf, a4: v4) == v4 )
    {
      v5 = g_pFileSystem->Open(this: &g_pFileSystem->IBaseFileSystem, a2: pszLocalFileName, a3: "wb", a4: "MOD");
      if ( v5 != nullptr )
      {
        v3 = g_pFileSystem->Write(this: &g_pFileSystem->IBaseFileSystem, a2: buf, a3: v4, a4: v5) == v4;
        g_pFileSystem->Close(this: &g_pFileSystem->IBaseFileSystem, a2: v5);
        if ( v3 )
          DevMsg(
            a1: "[Cloud]: SUCCEESS retrieved %s from remote storage into %s\n",
            pszRemoteFileName,
            pszLocalFileName);
        else
          DevMsg(a1: "[Cloud]: FAILED retrieved %s from remote storage into %s\n", pszRemoteFileName, pszLocalFileName);
      }
    }
    if ( buf != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: buf);
  }
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x10187C50
// Name: void CL_DiscardOldAddAngleEntries(float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CL_DiscardOldAddAngleEntries(float t)
{
  int i; // edi
  CClientState *LocalClient; // esi
  int v3; // eax
  float killtime; // [esp+8h] [ebp+8h]

  killtime = (float)(t - host_state.interval_per_tick) - 0.1;
  for ( i = 0; i < GetLocalClient(nSlot: -1)->addangle.m_Size; ++i )
  {
    if ( killtime >= GetLocalClient(nSlot: -1)->addangle.m_Memory.m_pMemory[i].starttime )
    {
      LocalClient = GetLocalClient(nSlot: -1);
      v3 = LocalClient->addangle.m_Size - i - 1;
      if ( v3 > 0 )
        _V_memmove(
          dest: &LocalClient->addangle.m_Memory.m_pMemory[i],
          src: &LocalClient->addangle.m_Memory.m_pMemory[i + 1],
          count: 8 * v3);
      --LocalClient->addangle.m_Size;
      --i;
    }
  }
  if ( GetLocalClient(nSlot: -1)->addangle.m_Size == 0 )
  {
    GetLocalClient(nSlot: -1)->addangletotal = 0.0;
    GetLocalClient(nSlot: -1)->prevaddangletotal = 0.0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10187D30
// Name: void CL_ApplyAddAngle(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CL_ApplyAddAngle()
{
  CClientState *BaseLocalClient; // eax
  float prevaddangletotal; // xmm0_4
  CClientState *LocalClient; // eax
  IPrediction_vtbl *v3; // esi
  CClientState *v4; // eax
  float v5; // [esp+14h] [ebp-10h]
  float frac; // [esp+18h] [ebp-Ch] BYREF
  AddAngle *v7; // [esp+1Ch] [ebp-8h] BYREF
  AddAngle *v8; // [esp+20h] [ebp-4h] BYREF

  BaseLocalClient = GetBaseLocalClient();
  v5 = CClientState::GetTime(this: BaseLocalClient) - host_state.interval_per_tick;
  v8 = nullptr;
  v7 = nullptr;
  frac = 0.0;
  CL_FindInterpolatedAddAngle(t: v5, &frac, prev: &v8, next: &v7);
  if ( v8 != nullptr && v7 != nullptr )
    prevaddangletotal = (float)((float)(v7->total - v8->total) * frac) + v8->total;
  else
    prevaddangletotal = GetLocalClient(nSlot: -1)->prevaddangletotal;
  v8 = (AddAngle *)LODWORD(prevaddangletotal);
  frac = prevaddangletotal - GetLocalClient(nSlot: -1)->prevaddangletotal;
  LocalClient = GetLocalClient(nSlot: -1);
  LocalClient->viewangles.y = LocalClient->viewangles.y + frac;
  v3 = g_pClientSidePrediction->__vftable;
  v4 = GetLocalClient(nSlot: -1);
  v3->SetLocalViewAngles(this: g_pClientSidePrediction, a2: &v4->viewangles);
  LODWORD(GetLocalClient(nSlot: -1)->prevaddangletotal) = v8;
  CL_DiscardOldAddAngleEntries(t: v5);
}

//------------------------------------------------------------------------------
// Address: 0x10187E30
// Name: void Snd_Restart_f(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall Snd_Restart_f(int a1@<esi>)
{
  CClientState *BaseLocalClient; // eax
  int v2; // esi
  int v3; // edi
  ConCommand *v4; // esi
  musicsave_t *m_pMemory; // eax
  CCommand cmd; // [esp+8h] [ebp-520h] BYREF
  const char *argv[1]; // [esp+510h] [ebp-18h] BYREF
  CUtlVector<musicsave_t,CUtlMemory<musicsave_t,int> > music; // [esp+514h] [ebp-14h] BYREF

  memset(&music, 0, sizeof(music));
  S_GetCurrentlyPlayingMusic(musiclist: &music);
  S_Shutdown(a1);
  snd_firsttime = true;
  BaseLocalClient = GetBaseLocalClient();
  CClientState::ClearSounds(this: BaseLocalClient);
  S_Init();
  v2 = 0;
  if ( music.m_Size > 0 )
  {
    v3 = 0;
    do
    {
      S_RestartSong(song: &music.m_Memory.m_pMemory[v3]);
      ++v2;
      ++v3;
    }
    while ( v2 < music.m_Size );
  }
  if ( audiosourcecache != nullptr && sv.m_szMapname[0] != 0 )
    ((void (__stdcall *)(char *))audiosourcecache->LevelInit)(a1: sv.m_szMapname);
  v4 = g_pCVar->FindCommand_2(this: g_pCVar, a2: "cl_soundscape_flush");
  if ( v4 != nullptr )
  {
    argv[0] = "cl_soundscape_flush";
    CCommand::CCommand(this: &cmd, nArgC: 1, ppArgV: argv);
    v4->Dispatch(this: v4, a2: &cmd);
  }
  Voice_ForceInit(a1: (int)v4);
  m_pMemory = music.m_Memory.m_pMemory;
  music.m_Size = 0;
  if ( music.m_Memory.m_nGrowSize >= 0 )
  {
    if ( music.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: music.m_Memory.m_pMemory);
      m_pMemory = nullptr;
      music.m_Memory.m_pMemory = nullptr;
    }
    music.m_Memory.m_nAllocationCount = 0;
  }
  music.m_pElements = m_pMemory;
  if ( music.m_Memory.m_nGrowSize >= 0 && m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x10187F50
// Name: void Host_WriteConfiguration(int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __usercall Host_WriteConfiguration(int a1@<ebx>, int a2@<edi>, int iController, const char *filename)
{
  const char *v4; // esi
  int v5; // eax
  int i; // esi
  int *v7; // edi
  int v8; // esi
  int HSteamPipe; // eax
  int HSteamUser; // eax
  ISteamRemoteStorage *v11; // eax
  ISteamRemoteStorage *v12; // esi
  bool (__thiscall *GetQuota)(ISteamRemoteStorage *, int *, int *); // eax
  ConVar *m_pParent; // ecx
  int m_nValue; // eax
  int v16; // eax
  char *m_pszString; // eax
  void *v18; // edi
  unsigned int v19; // esi
  void *v20; // ebx
  void *v21; // edi
  int v22; // esi
  void *v23; // ebx
  void *v24; // esi
  char szLogoFileName[260]; // [esp+4h] [ebp-244h] BYREF
  char szFileName[260]; // [esp+108h] [ebp-140h] BYREF
  int availableBytes; // [esp+20Ch] [ebp-3Ch] BYREF
  CUtlBuffer configBuff; // [esp+210h] [ebp-38h] BYREF
  int totalBytes; // [esp+240h] [ebp-8h] BYREF
  ISteamRemoteStorage *pRemoteStorage; // [esp+244h] [ebp-4h]

  v4 = filename;
  if ( filename == nullptr )
    v4 = "config.cfg";
  if ( host_initialized )
  {
    v5 = iController;
    if ( iController < 0 )
      v5 = 0;
    if ( g_bConfigCfgExecuted[v5] )
    {
      if ( g_bInEditMode )
      {
        ConMsg(a1: "skipping %s output when in map edit mode\n", v4);
        return;
      }
      if ( !sv.m_bIsDedicated )
      {
        if ( Key_CountBindings() <= 1 )
        {
          ConMsg(a1: "skipping %s output, no keys bound\n", v4);
          return;
        }
        CUtlBuffer::CUtlBuffer(this: &configBuff, growSize: 0, initSize: 0, nFlags: 1u);
        V_snprintf(pDest: szFileName, maxLen: 260, pFormat: "cfg/%s", v4);
        g_pFileSystem->CreateDirHierarchy(this: g_pFileSystem, a2: "cfg", a3: "MOD");
        if ( g_pFileSystem->FileExists(this: &g_pFileSystem->IBaseFileSystem, a2: szFileName, a3: "MOD")
          && !g_pFileSystem->IsFileWritable(this: &g_pFileSystem->IBaseFileSystem, a2: szFileName, a3: "MOD") )
        {
          ConMsg(a1: "Config file %s is read-only!!\n", szFileName);
LABEL_53:
          CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>::~CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>(this: &configBuff);
          return;
        }
        CUtlBuffer::Printf(this: &configBuff, pFmt: "unbindall\n");
        Key_WriteBindings(buf: &configBuff, iSplitscreenSlot: -1);
        CCvarUtilities::WriteVariables(
          this: cv,
          buff: &configBuff,
          iSplitscreenSlot: -1,
          bSlotRequired: false,
          pConvarsListVoid: nullptr);
        for ( i = 0; i < host_state.max_splitscreen_players; ++i )
        {
          if ( g_ClientDLL->IN_IsKeyDown(this: g_ClientDLL, a2: "in_jlook", a3: (bool *)&filename + 3)
            && HIBYTE(filename) != 0 )
          {
            CUtlBuffer::Printf(this: &configBuff, pFmt: "cmd%d +jlook\n", i + 1);
          }
        }
        if ( configBuff.m_nMaxPut == 0 )
          goto LABEL_53;
        if ( _SteamClient() == 0 )
          goto LABEL_52;
        v7 = (int *)_SteamClient();
        v8 = *v7;
        HSteamPipe = _SteamAPI_GetHSteamPipe(a1: "STEAMREMOTESTORAGE_INTERFACE_VERSION004");
        HSteamUser = _SteamAPI_GetHSteamUser(a1: HSteamPipe);
        v11 = (ISteamRemoteStorage *)(*(int (__thiscall **)(int *, int))(v8 + 52))(a1: v7, a2: HSteamUser);
        v12 = v11;
        pRemoteStorage = v11;
        if ( v11 == nullptr )
          goto LABEL_52;
        GetQuota = v11->GetQuota;
        totalBytes = 0;
        if ( !GetQuota(this: v12, a2: &totalBytes, a3: &availableBytes) || totalBytes <= 0 )
          goto LABEL_52;
        m_pParent = cl_cloud_settings.m_pParent;
        if ( cl_cloud_settings.m_pParent != nullptr )
        {
          m_nValue = cl_cloud_settings.m_pParent->m_Value.m_nValue;
          if ( m_nValue == -1 )
          {
LABEL_34:
            if ( m_pParent == nullptr )
            {
              LOBYTE(v16) = 0;
              goto LABEL_38;
            }
            v16 = m_pParent->m_Value.m_nValue;
            if ( v16 != -1 )
            {
LABEL_38:
              if ( (v16 & 2) != 0 )
              {
                if ( (cl_logofile.m_nFlags & 0x1000) != 0 )
                {
                  m_pszString = "FCVAR_NEVER_AS_STRING";
                }
                else
                {
                  m_pszString = cl_logofile.m_pParent->m_Value.m_pszString;
                  if ( m_pszString == nullptr )
                    m_pszString = (char *)defaultValue;
                }
                V_strncpy(pDest: szLogoFileName, pSrc: m_pszString, maxLen: 260);
                if ( g_pFileSystem->FileExists(this: &g_pFileSystem->IBaseFileSystem, a2: szLogoFileName, a3: "MOD") )
                {
                  v18 = (void *)((int (__thiscall *)(IBaseFileSystem *, char *, const char *, const char *, int, int))g_pFileSystem->Open)(
                                  a1: &g_pFileSystem->IBaseFileSystem,
                                  a2: szLogoFileName,
                                  a3: "rb",
                                  a4: "MOD",
                                  a5: a1,
                                  a6: a2);
                  if ( v18 != nullptr )
                  {
                    v19 = g_pFileSystem->Size_2(this: &g_pFileSystem->IBaseFileSystem, a2: v18);
                    v20 = MemAlloc_Alloc(nSize: v19);
                    if ( g_pFileSystem->Read(this: &g_pFileSystem->IBaseFileSystem, a2: v20, a3: v19, a4: v18) == v19 )
                    {
                      V_SetExtension(path: g_szDefaultLogoFileName, extension: ".vtf", pathStringLength: 31);
                      pRemoteStorage->FileWrite(this: pRemoteStorage, a2: g_szDefaultLogoFileName, a3: v20, a4: v19);
                    }
                    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v20);
                    g_pFileSystem->Close(this: &g_pFileSystem->IBaseFileSystem, a2: v18);
                  }
                  V_SetExtension(path: szLogoFileName, extension: ".vmt", pathStringLength: 260);
                  v21 = (void *)((int (__thiscall *)(IBaseFileSystem *, char *))g_pFileSystem->Open)(
                                  a1: &g_pFileSystem->IBaseFileSystem,
                                  a2: szLogoFileName);
                  if ( v21 != nullptr )
                  {
                    v22 = ((int (__thiscall *)(IBaseFileSystem *, void *, const char *, const char *))g_pFileSystem->Size_2)(
                            a1: &g_pFileSystem->IBaseFileSystem,
                            a2: v21,
                            a3: "rb",
                            a4: "MOD");
                    v23 = MemAlloc_Alloc(nSize: v22);
                    if ( g_pFileSystem->Read(this: &g_pFileSystem->IBaseFileSystem, a2: v23, a3: v22, a4: v21) == v22 )
                    {
                      V_SetExtension(path: g_szDefaultLogoFileName, extension: ".vmt", pathStringLength: 31);
                      pRemoteStorage->FileWrite(this: pRemoteStorage, a2: g_szDefaultLogoFileName, a3: v23, a4: v22);
                    }
                    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v23);
                    g_pFileSystem->Close(this: &g_pFileSystem->IBaseFileSystem, a2: v21);
                  }
                }
              }
            }
LABEL_52:
            v24 = MemAlloc_Alloc(nSize: configBuff.m_nMaxPut);
            _V_memcpy(dest: v24, src: configBuff.m_Memory.m_pMemory, count: configBuff.m_nMaxPut);
            g_pFileSystem->AsyncWrite(
              this: g_pFileSystem,
              a2: szFileName,
              a3: v24,
              a4: configBuff.m_nMaxPut,
              a5: true,
              a6: false,
              a7: nullptr);
            ConMsg(a1: "Host_WriteConfiguration: Wrote %s\n", szFileName);
            goto LABEL_53;
          }
        }
        else
        {
          LOBYTE(m_nValue) = 0;
        }
        if ( (m_nValue & 1) != 0 )
        {
          if ( v12->FileWrite(this: v12, a2: szFileName, a3: configBuff.m_Memory.m_pMemory, a4: configBuff.m_nMaxPut) != 0 )
            DevMsg(a1: "[Cloud]: SUCCEESS saving %s in remote storage\n", szFileName);
          else
            DevMsg(a1: "[Cloud]: FAILED saving %s in remote storage\n", szFileName);
          m_pParent = cl_cloud_settings.m_pParent;
        }
        goto LABEL_34;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101883F0
// Name: void Host_ReadConfiguration(int,bool)
// Source: json
//------------------------------------------------------------------------------
void __usercall Host_ReadConfiguration(int a1@<ebx>, int a2@<edi>, int a3@<esi>, int iController)
{
  char v4; // bl
  int *v5; // edi
  int v6; // esi
  int HSteamUser; // eax
  ISteamRemoteStorage *v8; // esi
  ConVar *m_pParent; // eax
  int m_nValue; // eax
  vgui::CTreeViewListControl *v11; // ecx
  ECommandTarget_t TraceType; // eax
  ECommandTarget_t v13; // eax
  int v14; // eax
  char *m_pszString; // eax
  int v16; // eax
  bool v17; // bl
  int HSteamPipe; // [esp-14h] [ebp-118h]
  int v19; // [esp-8h] [ebp-10Ch]
  char szLogoFileName[260]; // [esp+0h] [ebp-104h] BYREF

  if ( sv.m_bIsDedicated )
    return;
  if ( g_pFileSystem == nullptr )
    Sys_Error(error: "Host_ReadConfiguration:  g_pFileSystem == NULL\n");
  v4 = 0;
  if ( _SteamClient(a1: a3, a2: a1) != 0 )
  {
    v5 = (int *)_SteamClient(a1: a2, a2: v19);
    v6 = *v5;
    HSteamPipe = _SteamAPI_GetHSteamPipe(a1: "STEAMREMOTESTORAGE_INTERFACE_VERSION004");
    HSteamUser = _SteamAPI_GetHSteamUser();
    v8 = (ISteamRemoteStorage *)(*(int (__thiscall **)(int *, int))(v6 + 52))(a1: v5, a2: HSteamUser);
    if ( v8 == nullptr )
      goto LABEL_18;
    m_pParent = cl_cloud_settings.m_pParent;
    if ( cl_cloud_settings.m_pParent == nullptr )
      goto LABEL_15;
    if ( cl_cloud_settings.m_pParent->m_Value.m_nValue == -1 )
    {
      if ( ((unsigned __int8 (__thiscall *)(ISteamRemoteStorage *))v8->FileExists)(a1: v8) == 0 )
      {
        DevMsg(a1: "[Cloud]: Default setting with remote data non-existent, sync all\n");
        CLoaderMemAlloc::CrtIsValidPointer(
          this: (ConVar *)&cl_cloud_settings.IConVar,
          value: 0x7FFF,
          a2: (unsigned int)"cfg/config.cfg",
          a3: HSteamPipe);
      }
      m_pParent = cl_cloud_settings.m_pParent;
    }
    if ( m_pParent != nullptr )
    {
      m_nValue = m_pParent->m_Value.m_nValue;
      if ( m_nValue == -1 )
        goto LABEL_18;
    }
    else
    {
LABEL_15:
      LOBYTE(m_nValue) = 0;
    }
    if ( (m_nValue & 1) != 0 )
      GetFileFromRemoteStorage(
        pRemoteStorage: v8,
        pszRemoteFileName: "cfg/config.cfg",
        pszLocalFileName: "cfg/config.cfg");
  }
  else
  {
    v8 = nullptr;
  }
LABEL_18:
  if ( g_pFileSystem->FileExists(this: &g_pFileSystem->IBaseFileSystem, a2: "//mod/cfg/config.cfg", a3: nullptr) )
  {
    TraceType = CTraceFilter::GetTraceType(this: v11);
    Cbuf_AddText(eTarget: TraceType, pText: "exec config.cfg mod\n", nTickDelay: 0);
  }
  else
  {
    v13 = CTraceFilter::GetTraceType(this: v11);
    Cbuf_AddText(eTarget: v13, pText: "exec config_default.cfg\n", nTickDelay: 0);
    v4 = 1;
  }
  Cbuf_Execute();
  if ( v8 != nullptr )
  {
    if ( cl_cloud_settings.m_pParent == nullptr )
    {
      LOBYTE(v14) = 0;
      goto LABEL_26;
    }
    v14 = cl_cloud_settings.m_pParent->m_Value.m_nValue;
    if ( v14 != -1 )
    {
LABEL_26:
      if ( (v14 & 2) != 0 )
      {
        if ( (cl_logofile.m_nFlags & 0x1000) != 0 )
        {
          m_pszString = "FCVAR_NEVER_AS_STRING";
        }
        else
        {
          m_pszString = cl_logofile.m_pParent->m_Value.m_pszString;
          if ( m_pszString == nullptr )
            m_pszString = (char *)defaultValue;
        }
        V_strncpy(pDest: szLogoFileName, pSrc: m_pszString, maxLen: 260);
        V_SetExtension(path: szLogoFileName, extension: ".vtf", pathStringLength: 260);
        V_SetExtension(path: g_szDefaultLogoFileName, extension: ".vtf", pathStringLength: 31);
        GetFileFromRemoteStorage(
          pRemoteStorage: v8,
          pszRemoteFileName: g_szDefaultLogoFileName,
          pszLocalFileName: szLogoFileName);
        V_SetExtension(path: g_szDefaultLogoFileName, extension: ".vmt", pathStringLength: 31);
        V_SetExtension(path: szLogoFileName, extension: ".vmt", pathStringLength: 260);
        GetFileFromRemoteStorage(
          pRemoteStorage: v8,
          pszRemoteFileName: g_szDefaultLogoFileName,
          pszLocalFileName: szLogoFileName);
      }
    }
  }
  if ( Key_CountBindings() == 0 )
    UseDefaultBindings();
  Key_SetBinding(keynum: KEY_ESCAPE, pBinding: "cancelselect");
  if ( Key_NameForBinding(pBinding: "toggleconsole", userId: -1, iStartCount: 0, iAllowJoystick: -1) == nullptr )
    Key_SetBinding(keynum: KEY_BACKQUOTE, pBinding: "toggleconsole");
  SetupDefaultAskConnectAcceptKey();
  v16 = iController;
  if ( iController < 0 )
    v16 = 0;
  g_bConfigCfgExecuted[v16] = true;
  if ( v4 != 0 )
  {
    v17 = host_initialized;
    host_initialized = true;
    Host_WriteConfiguration(iController, filename: "config.cfg");
    host_initialized = v17;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10188670
// Name: host_writeconfig
// Source: json
//------------------------------------------------------------------------------
void __usercall host_writeconfig(int a1@<ebx>, int a2@<edi>, const CCommand *args)
{
  const char *v3; // eax
  const char *v4; // eax
  char outfile[96]; // [esp+0h] [ebp-60h] BYREF

  if ( args->m_nArgc <= 2 )
  {
    if ( args->m_nArgc == 2 )
    {
      v3 = args->m_ppArgv[1];
      if ( v3 != nullptr && *v3 != 0 )
      {
        V_FileBase(in: v3, out: outfile, maxlen: 96);
        v4 = va(format: "%s.cfg", outfile);
        Host_WriteConfiguration(a1, a2, iController: -1, filename: v4);
      }
    }
    else
    {
      Host_WriteConfiguration(a1, a2, iController: -1, filename: "config.cfg");
    }
  }
  else
  {
    ConMsg(a1: "Usage:  writeconfig <filename.cfg>\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x101886E0
// Name: host_writeconfig_ss
// Source: json
//------------------------------------------------------------------------------
void __usercall host_writeconfig_ss(int a1@<ebx>, int a2@<edi>, const CCommand *args)
{
  int m_nArgc; // eax
  const char *v4; // eax
  const char *v5; // esi
  int v6; // esi
  const char *v7; // eax
  int v8; // eax
  char outfile[96]; // [esp+4h] [ebp-60h] BYREF

  m_nArgc = args->m_nArgc;
  if ( args->m_nArgc <= 1 || m_nArgc > 3 )
  {
    ConMsg(a1: "Usage:  writeconfig <controller index> <filename.cfg>\n");
  }
  else if ( m_nArgc == 3 )
  {
    v4 = args->m_ppArgv[2];
    if ( v4 != nullptr && *v4 != 0 )
    {
      V_FileBase(in: v4, out: outfile, maxlen: 96);
      if ( args->m_nArgc > 1 )
        v5 = args->m_ppArgv[1];
      else
        v5 = defaultValue;
      v6 = atoi(nptr: v5);
      v7 = va(format: "%s.cfg", outfile);
      Host_WriteConfiguration(a1, a2, iController: v6, filename: v7);
    }
  }
  else if ( m_nArgc == 2 )
  {
    v8 = atoi(nptr: args->m_ppArgv[1]);
    Host_WriteConfiguration(a1, a2, iController: v8, filename: "config.cfg");
  }
  else
  {
    Host_WriteConfiguration(a1, a2, iController: -1, filename: "config.cfg");
  }
}

//------------------------------------------------------------------------------
// Address: 0x101887B0
// Name: void Host_BeginThreadedSound(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Host_BeginThreadedSound()
{
  CFunctorJob *v0; // esi
  CFunctor *v1; // eax
  CFunctorJob *v2; // eax

  if ( host_threaded_sound.m_pParent != nullptr
    && host_threaded_sound.m_pParent->m_Value.m_nValue != 0
    && g_bAllowThreadedSound )
  {
    v0 = (CFunctorJob *)MemAlloc_Alloc(nSize: 0x44u);
    if ( v0 != nullptr )
    {
      v1 = (CFunctor *)MemAlloc_Alloc(nSize: 0x14u);
      if ( v1 != nullptr )
      {
        v1[1].m_nUserID = 1;
        v1->__vftable = (CFunctor_vtbl *)&CFunctor0<void (__cdecl *)(void),CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>>::`vftable'{for `CFunctor'};
        v1[1].__vftable = (CFunctor_vtbl *)&CFunctor0<void (__cdecl *)(void),CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>>::`vftable'{for `CRefCountServiceBase<1,CRefMT>'};
        v1[2].__vftable = (CFunctor_vtbl *)Host_UpdateSounds;
        v2 = CFunctorJob::CFunctorJob(this: v0, pFunctor: v1, pszDescription: nullptr);
      }
      else
      {
        v2 = CFunctorJob::CFunctorJob(this: v0, pFunctor: nullptr, pszDescription: nullptr);
      }
    }
    else
    {
      v2 = nullptr;
    }
    g_pSoundJob = v2;
    _g_pThreadPool->AddJob(this: _g_pThreadPool, a2: v2);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10188840
// Name: void _Host_RunFrame(float)
// Source: json
//------------------------------------------------------------------------------
void __usercall _Host_RunFrame(float a1@<xmm14>, float time)
{
  void (*BeginCoarseLock)(void); // edx
  CHLTVClientState *v3; // edi
  CStatTime *v4; // ecx
  int v5; // eax
  long double v6; // st7
  int m_nValue; // eax
  CMapReslistGenerator *v8; // eax
  float v9; // xmm1_4
  signed int v10; // ebx
  float interval_per_tick; // xmm2_4
  float v12; // xmm0_4
  char v13; // al
  CStatTime *v14; // ecx
  CStatTime *v15; // ecx
  BOOL v16; // eax
  double v17; // st7
  CClientState *v18; // esi
  CStatTime *v19; // ecx
  CThreadEvent *v20; // esi
  long double v21; // st7
  CStatTime *v22; // ecx
  CClientState *v23; // eax
  CClientState *v24; // eax
  int v25; // edi
  CStatTime *m_nTickCount; // ecx
  int v27; // esi
  long double v28; // st7
  CStatTime *v29; // ecx
  CClientState *v30; // eax
  CClientState *v31; // eax
  CClientState *v32; // eax
  CClientState *v33; // eax
  signed int v34; // esi
  CStatTime *v35; // ecx
  long double v36; // st7
  CClientState *v37; // eax
  CClientState *v38; // eax
  CStatTime *v39; // ecx
  long double v40; // st7
  _DWORD *v41; // eax
  _DWORD *v42; // ebx
  CStatTime *v43; // ecx
  long double v44; // st7
  CStatTime *v45; // ecx
  CStatTime *v46; // ecx
  bool v47; // al
  CJob *v48; // esi
  int m_status; // eax
  vgui::PropertyPage *v51; // ecx
  CStatTime *v52; // ecx
  float v53; // xmm1_4
  int v54; // eax
  float flMinimumTickInterval_4; // [esp+4h] [ebp-40h]
  const CCommand *v56; // [esp+8h] [ebp-3Ch]
  CJob *v57; // [esp+28h] [ebp-1Ch] BYREF
  bool finaltick[4]; // [esp+2Ch] [ebp-18h]
  IMDLCache *v59; // [esp+30h] [ebp-14h]
  bool framefinished[4]; // [esp+34h] [ebp-10h]
  float v61; // [esp+38h] [ebp-Ch]
  CClientState *BaseLocalClient; // [esp+3Ch] [ebp-8h]
  bool v63; // [esp+43h] [ebp-1h]

  BeginCoarseLock = (void (*)(void))g_pMDLCache->BeginCoarseLock;
  v59 = g_pMDLCache;
  BeginCoarseLock();
  v3 = nullptr;
  BaseLocalClient = GetBaseLocalClient();
  if ( host_checkheap )
  {
    _heapchk(args: v56);
    if ( v5 != -2 )
      Sys_Error(error: "_Host_RunFrame (top):  _heapchk() != _HEAPOK\n");
  }
  if ( mem_incremental_compact_rate.m_pParent->m_Value.m_fValue > 0.0 )
  {
    v6 = _Plat_FloatTime(this: v4);
    if ( v6 - timeLastMemCompact > mem_incremental_compact_rate.m_pParent->m_Value.m_fValue )
    {
      timeLastMemCompact = v6;
      _g_pMemAlloc->CompactIncremental(this: _g_pMemAlloc);
    }
  }
  if ( host_Sleep.m_pParent != nullptr )
  {
    m_nValue = host_Sleep.m_pParent->m_Value.m_nValue;
    if ( m_nValue != 0 )
      Sys_Sleep(msec: m_nValue);
  }
  if ( g_iVCRPlaybackSleepInterval != 0 )
    Sys_Sleep(msec: g_iVCRPlaybackSleepInterval);
  v8 = MapReslistGenerator();
  CMapReslistGenerator::RunFrame(this: v8);
  if ( _setjmp3(a1: host_enddemo, a2: 0) != 0 )
  {
    v59->EndCoarseLock(this: v59);
    return;
  }
  Host_AccumulateTime(a1, dt: time);
  _Host_SetGlobalTime();
  v63 = !sv.m_bIsDedicated;
  v61 = host_remainder;
  if ( host_remainder < 0.0 )
    v61 = 0.0;
  if ( demoplayer->IsPlaybackPaused(this: demoplayer) )
  {
    v9 = host_remainder;
  }
  else
  {
    v9 = host_frametime + host_remainder;
    host_remainder = host_frametime + host_remainder;
  }
  v10 = 0;
  if ( sv_alternateticks.m_pParent == nullptr || sv_alternateticks.m_pParent->m_Value.m_nValue == 0 )
    goto LABEL_24;
  if ( GetBaseLocalClient()->m_nMaxClients != 1 )
  {
    v9 = host_remainder;
LABEL_24:
    interval_per_tick = host_state.interval_per_tick;
    v13 = 0;
    v12 = host_state.interval_per_tick;
    goto LABEL_25;
  }
  interval_per_tick = host_state.interval_per_tick;
  v9 = host_remainder;
  v12 = host_state.interval_per_tick * 2.0;
  v13 = 1;
LABEL_25:
  *(float *)framefinished = v12;
  if ( v9 >= v12 )
  {
    v10 = (int)(float)(v9 / interval_per_tick);
    if ( v13 != 0 )
      v10 = ((g_ServerGlobalVariables.tickcount + v10) & 0xFFFFFFFE) - g_ServerGlobalVariables.tickcount;
    host_remainder = v9 - (float)((float)v10 * interval_per_tick);
  }
  g_pMDLCache->MarkFrame(this: g_pMDLCache);
  if ( host_print_frame_times.m_pParent != nullptr && host_print_frame_times.m_pParent->m_Value.m_nValue != 0 )
    PrintHostFrameTimes(nNumTicks: v10, flHostRemainder: host_remainder, flMinimumTickInterval: *(float *)framefinished);
  if ( fs_enable_stats.m_pParent != nullptr && fs_enable_stats.m_pParent->m_Value.m_nValue != 0 )
    PrintFsStats();
  g_HostTimes.starttime[6] = _Plat_FloatTime(this: v14);
  Cbuf_Execute();
  if ( NET_IsDedicated() && !NET_IsMultiplayer() )
    NET_SetMultiplayer(multiplayer: true);
  v17 = _Plat_FloatTime(this: v15);
  v18 = BaseLocalClient;
  g_ServerGlobalVariables.interpolation_amount = 0.0;
  g_ClientGlobalVariables.interpolation_amount = 0.0;
  g_HostTimes.deltas[6] = v17 - g_HostTimes.starttime[6] + g_HostTimes.deltas[6];
  BaseLocalClient->insimulation = true;
  host_frameticks = v10;
  host_currentframetick = 0;
  LOBYTE(v16) = v18->m_nSignonState == 6 && scr_nextdrawtick == 0;
  g_pEngineToolInternal->SetIsInGame(this: g_pEngineToolInternal, a2: v16);
  *(_DWORD *)framefinished = 0;
  if ( g_bThreadedEngine )
  {
    v25 = numticks_last_frame;
    v18->m_tickRemainder = host_remainder_last_frame;
    v18->m_frameTime = last_frame_time;
    if ( g_ClientDLL != nullptr )
      ((void (__stdcall *)(_DWORD))g_ClientDLL->IN_SetSampleTime)(a1: LODWORD(last_frame_time));
    m_nTickCount = (CStatTime *)sv.m_nTickCount;
    v27 = 0;
    last_frame_time = host_frametime;
    g_ClientGlobalVariables.simTicksThisFrame = v25;
    g_ServerGlobalVariables.simTicksThisFrame = v10;
    for ( g_ServerGlobalVariables.tickcount = sv.m_nTickCount; v27 < v25; ++v27 )
    {
      v28 = _Plat_FloatTime(this: m_nTickCount);
      NET_RunFrame(realtime: v28);
      framefinished[0] = v27 == v25 - 1;
      if ( NET_IsDedicated() && !NET_IsMultiplayer() )
        NET_SetMultiplayer(multiplayer: true);
      g_ClientGlobalVariables.tickcount = BaseLocalClient->m_ClockDriftMgr.m_nClientTick;
      CL_CheckClientState();
      NET_SendQueuedPackets();
      if ( !sv.m_bIsDedicated )
        _Host_RunFrame_Client(framefinished: framefinished[0]);
      toolframework->Think(this: toolframework, a2: *(_DWORD *)framefinished);
    }
    CVProfile::EnterScope(
      this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
      a2: "CL_ProcessVoiceData",
      a3: 0,
      a4: "Networking",
      a5: false,
      a6: 4);
    if ( Voice_Idle(a1: v29, a2: v25, frametime: 0.016666668) != 0 )
      CL_SendVoicePacket(a1: v25, a2: v27, bFinal: false);
    CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
    if ( v25 == 0 && (demoplayer->IsPlayingTimeDemo(this: demoplayer) || demoplayer->IsSkipping(this: demoplayer)) )
      _Host_RunFrame_Client(framefinished: true);
    GetBaseLocalClient()->insimulation = false;
    v30 = GetBaseLocalClient();
    g_ClientGlobalVariables.curtime = CClientState::GetTime(this: v30);
    v31 = GetBaseLocalClient();
    g_ClientGlobalVariables.frametime = CClientState::GetFrameTime(this: v31);
    g_ClientGlobalVariables.interpolation_amount = BaseLocalClient->m_tickRemainder / host_state.interval_per_tick;
    CL_RunPrediction();
    CL_ApplyAddAngle();
    GetBaseLocalClient()->insimulation = true;
    v32 = GetBaseLocalClient();
    g_ClientGlobalVariables.curtime = CClientState::GetTime(this: v32);
    v33 = GetBaseLocalClient();
    g_ClientGlobalVariables.frametime = CClientState::GetFrameTime(this: v33);
    v34 = 0;
    for ( *(_DWORD *)finaltick = g_ClientGlobalVariables.tickcount; v34 < v10; ++v34 )
    {
      ++host_currentframetick;
      g_ClientGlobalVariables.tickcount = ++host_tickcount;
      _Host_RunFrame_Input(a1: v10 - 1, accumulated_extra_samples: v61, bFinalTick: v34 == v10 - 1);
      v61 = 0.0;
      v36 = _Plat_FloatTime(this: v35);
      NET_RunFrame(realtime: v36);
    }
    if ( v10 == 0 )
    {
      CVProfile::EnterScope(
        this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
        a2: "_Host_ProcessVoice_Server",
        a3: 0,
        a4: "Game",
        a5: false,
        a6: 4);
      SV_ProcessVoice();
      CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
    }
    GetBaseLocalClient()->insimulation = false;
    v37 = GetBaseLocalClient();
    g_ClientGlobalVariables.curtime = CClientState::GetTime(this: v37);
    v38 = GetBaseLocalClient();
    g_ClientGlobalVariables.frametime = CClientState::GetFrameTime(this: v38);
    CL_ExtraMouseUpdate(frametime: g_ClientGlobalVariables.frametime);
    g_ClientGlobalVariables.tickcount = *(_DWORD *)finaltick;
    numticks_last_frame = v10;
    host_remainder_last_frame = host_remainder;
    v40 = _Plat_FloatTime(this: v39);
    NET_SetTime(realtime: v40);
    v20 = (CThreadEvent *)MemAlloc_Alloc(nSize: 0x44u);
    if ( v20 != nullptr )
    {
      v41 = MemAlloc_Alloc(nSize: 0x18u);
      if ( v41 != nullptr )
      {
        v41[3] = 1;
        v41[5] = v10;
        *v41 = &CFunctor1<void (__cdecl *)(int),int,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>>::`vftable'{for `CFunctor'};
        v41[2] = &CFunctor1<void (__cdecl *)(int),int,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>>::`vftable'{for `CRefCountServiceBase<1,CRefMT>'};
        v41[4] = _Host_RunFrame_Server_Async;
        v42 = v41;
      }
      else
      {
        v42 = nullptr;
      }
      v20[1].m_hSyncObject = (void *)1;
      v20[2].m_hSyncObject = (void *)1;
      v20->m_hSyncObject = &CJob::`vftable'{for `IRefCounted'};
      *(_DWORD *)&v20->m_bCreatedHandle = &CJob::`vftable'{for `CRefCountServiceBase<1,CRefMT>'};
      *(_DWORD *)&v20[1].m_bCreatedHandle = 4;
      *(_DWORD *)&v20[2].m_bCreatedHandle = 0;
      v20[3].m_hSyncObject = nullptr;
      *(_WORD *)&v20[3].m_bCreatedHandle = -256;
      v20[4].m_hSyncObject = (void *)-1;
      *(_DWORD *)&v20[4].m_bCreatedHandle = 0;
      CThreadEvent::CThreadEvent(this: v20 + 5, a2: true);
      v20->m_hSyncObject = &CFunctorJob::`vftable'{for `IRefCounted'};
      *(_DWORD *)&v20->m_bCreatedHandle = &CFunctorJob::`vftable'{for `CRefCountServiceBase<1,CRefMT>'};
      v20[6].m_hSyncObject = v42;
      v20[6].m_bCreatedHandle = false;
      *(_DWORD *)framefinished = v20;
    }
    else
    {
      *(_DWORD *)framefinished = 0;
    }
    _g_pThreadPool->AddJob(this: _g_pThreadPool, a2: *(CJob **)framefinished);
  }
  else
  {
    v19 = (CStatTime *)g_ClientDLL;
    if ( g_ClientDLL != nullptr )
      ((void (__stdcall *)(_DWORD))g_ClientDLL->IN_SetSampleTime)(a1: LODWORD(host_frametime));
    g_ClientGlobalVariables.simTicksThisFrame = 1;
    v18->m_tickRemainder = host_remainder;
    v18->m_frameTime = host_frametime;
    v20 = nullptr;
    for ( g_ServerGlobalVariables.simTicksThisFrame = 1; (int)v20 < v10; v20 = (CThreadEvent *)((char *)v20 + 1) )
    {
      v21 = _Plat_FloatTime(this: v19);
      NET_RunFrame(realtime: v21);
      finaltick[0] = v20 == (CThreadEvent *)(v10 - 1);
      if ( NET_IsDedicated() && !NET_IsMultiplayer() )
        NET_SetMultiplayer(multiplayer: true);
      ++host_tickcount;
      ++host_currentframetick;
      g_ServerGlobalVariables.tickcount = sv.m_nTickCount;
      g_ClientGlobalVariables.tickcount = BaseLocalClient->m_ClockDriftMgr.m_nClientTick;
      CL_CheckClientState();
      v3 = *(CHLTVClientState **)finaltick;
      _Host_RunFrame_Input(a1: *(int *)finaltick, accumulated_extra_samples: v61, bFinalTick: finaltick[0]);
      v61 = 0.0;
      _Host_RunFrame_Server(a1: v10, a2: (int)v3, finaltick: (int)v3);
      NET_SendQueuedPackets();
      if ( !sv.m_bIsDedicated )
        _Host_RunFrame_Client(framefinished: finaltick[0]);
      toolframework->Think(this: toolframework, a2: *(_DWORD *)finaltick);
    }
    CVProfile::EnterScope(
      this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
      a2: "CL_ProcessVoiceData",
      a3: 0,
      a4: "Networking",
      a5: false,
      a6: 4);
    if ( Voice_Idle(a1: v22, a2: (int)v3, frametime: 0.016666668) != 0 )
      CL_SendVoicePacket(a1: (int)v3, a2: (int)v20, bFinal: false);
    CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
    if ( v10 == 0 )
    {
      CVProfile::EnterScope(
        this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
        a2: "_Host_ProcessVoice_Server",
        a3: 0,
        a4: "Game",
        a5: false,
        a6: 4);
      SV_ProcessVoice();
      CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
    }
    if ( hltv != nullptr )
      CHLTVServer::RunFrame(this: hltv, a2: v10, p_m_ClientState: v3);
    if ( hltvtest != nullptr )
      CHLTVTestSystem::RunFrame(this: hltvtest, a2: v10);
    if ( v10 == 0 && (demoplayer->IsPlayingTimeDemo(this: demoplayer) || demoplayer->IsSkipping(this: demoplayer)) )
      _Host_RunFrame_Client(framefinished: true);
    if ( !sv.m_bIsDedicated )
    {
      GetBaseLocalClient()->insimulation = false;
      v23 = GetBaseLocalClient();
      g_ClientGlobalVariables.curtime = CClientState::GetTime(this: v23);
      v24 = GetBaseLocalClient();
      g_ClientGlobalVariables.frametime = CClientState::GetFrameTime(this: v24);
      g_ClientGlobalVariables.interpolation_amount = BaseLocalClient->m_tickRemainder / host_state.interval_per_tick;
      CL_RunPrediction();
      CL_ApplyAddAngle();
      CL_ExtraMouseUpdate(frametime: g_ClientGlobalVariables.frametime);
    }
  }
  if ( g_pScaleformUI != nullptr && v63 )
    ((void (__stdcall *)(_DWORD))g_pScaleformUI->RunFrame)(a1: LODWORD(g_ClientGlobalVariables.frametime));
  CLog::RunFrame(this: &g_Log);
  if ( v63 )
  {
    _Host_RunFrame_Render(a1: (unsigned int)v20);
    _Host_RunFrame_Sound();
    if ( g_bVCRSingleStep )
      VCR_EnterPausedState();
  }
  v44 = _Plat_FloatTime(this: v43);
  g_HostTimes.frametime = v44 - g_HostTimes.swaptime;
  g_HostTimes.swaptime = v44;
  CFrameTimer::ComputeFrameVariability(this: &g_HostTimes);
  g_EngineStats.m_flFrameTime = g_HostTimes.frametime;
  g_EngineStats.m_flFPSVariability = g_HostTimes.m_flFPSVariability;
  host_frametime_stddeviation = g_HostTimes.m_flFPSStdDeviationSeconds;
  if ( !sv.m_bIsDedicated )
  {
    CVProfile::EnterScope(
      this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
      a2: "_Host_RunFrame - ClientDLL_Update",
      a3: 0,
      a4: "Client Simulation",
      a5: false,
      a6: 4);
    g_HostTimes.starttime[5] = _Plat_FloatTime(this: v45);
    ClientDLL_Update();
    g_HostTimes.deltas[5] = _Plat_FloatTime(this: v46) - g_HostTimes.starttime[5] + g_HostTimes.deltas[5];
    CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
  }
  if ( *(_DWORD *)framefinished != 0 )
  {
    CVProfile::EnterScope(
      this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
      a2: "WaitForAsyncServer",
      a3: 0,
      a4: "AsyncServer",
      a5: false,
      a6: 4);
    if ( sv.m_State < ss_active )
      v47 = GetBaseLocalClient()->m_nMaxClients == 1;
    else
      v47 = sv.m_nMaxclients <= 1;
    if ( v47 )
    {
      CJob::Execute(this: *(CJob **)framefinished);
      (*(void (__thiscall **)(_DWORD))(**(_DWORD **)framefinished + 4))(a1: *(_DWORD *)framefinished);
    }
    else
    {
      CJob::WaitForFinishAndRelease(this: *(CJob **)framefinished, dwTimeout: 0xFFFFFFFF);
    }
    CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
    SV_FrameExecuteThreadDeferred();
  }
  if ( g_pSoundJob != nullptr )
  {
    CVProfile::EnterScope(
      this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
      a2: "_Host_RunFrame_Sound",
      a3: 0,
      a4: "Sound",
      a5: false,
      a6: 4);
    v48 = g_pSoundJob;
    if ( g_pSoundJob != nullptr )
    {
      m_status = g_pSoundJob->m_status;
      if ( m_status == 1 || m_status == 2 || m_status == 4 )
      {
        v57 = g_pSoundJob;
        _g_pThreadPool->YieldWait(this: _g_pThreadPool, a2: &v57, a3: 1, a4: true, a5: -1u);
      }
      v48->Release(this: v48);
    }
    g_pSoundJob = nullptr;
    CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
  }
  CFrameTimer::MarkFrame(this: &g_HostTimes);
  flMinimumTickInterval_4 = g_HostTimes.m_flFPSVariability;
  CDemoPlayer::MarkFrame(this: g_pClientDemoPlayer, flFPSVariability: flMinimumTickInterval_4);
  CColorBalanceUIPanel::Init(this: v51);
  ++host_framecount;
  if ( !demoplayer->IsPlaybackPaused(this: demoplayer) )
    host_time = (float)((float)host_tickcount * host_state.interval_per_tick) + BaseLocalClient->m_tickRemainder;
  v53 = host_frametime;
  if ( host_frametime >= 0.000099999997 )
  {
    if ( host_frametime > 1.0 )
      v53 = 1.0;
  }
  else
  {
    v53 = 0.000099999997;
  }
  g_fFramesPerSecond = (float)((float)(1.0 / v53) * 0.10000002) + (float)(g_fFramesPerSecond * 0.89999998);
  if ( host_checkheap )
  {
    _heapchk(args: v56);
    if ( v54 != -2 )
      Sys_Error(error: "_Host_RunFrame (bottom):  _heapchk() != _HEAPOK\n");
  }
  Host_CheckDumpMemoryStats(this: v52);
  CTestScriptMgr::CheckPoint(this: &g_TestScriptMgr, pName: "frame_end");
  Host_ShowIPCCallCount();
  v59->EndCoarseLock(this: v59);
}

//------------------------------------------------------------------------------
// Address: 0x10189410
// Name: void Host_RunFrame(float)
// Source: json
//------------------------------------------------------------------------------
void __usercall Host_RunFrame(CStatTime *a1@<ecx>, float a2@<xmm14>, float time)
{
  int m_nValue; // eax
  int v4; // eax
  CStatTime *v5; // ecx
  long double v6; // st7
  long double v7; // st6
  int NumClients; // eax
  long double v9; // [esp+0h] [ebp-18h]
  double v10; // [esp+10h] [ebp-8h]

  if ( scr_drawloading
    || sv.m_State < ss_active
    || GetBaseLocalClient()->m_nSignonState != 6
    || sv.m_bLoadgame
    || (host_thread_mode.m_pParent == nullptr
      ? (m_nValue = 0)
      : (m_nValue = host_thread_mode.m_pParent->m_Value.m_nValue),
        m_nValue == 0) )
  {
    g_bThreadedEngine = false;
  }
  else
  {
    v4 = m_nValue - 1;
    if ( v4 != 0 )
    {
      if ( v4 == 1 )
        g_bThreadedEngine = true;
    }
    else
    {
      LOBYTE(a1) = _g_pThreadPool->NumThreads(this: _g_pThreadPool) > 0;
      g_bThreadedEngine = (char)a1;
    }
  }
  if ( host_profile.m_pParent != nullptr && host_profile.m_pParent->m_Value.m_nValue != 0 )
  {
    v10 = _Plat_FloatTime(this: a1);
    _Host_RunFrame(a1: a2, time);
    v6 = _Plat_FloatTime(this: v5);
    ++timecount;
    v7 = v6 - v10 + timetotal;
    timetotal = v7;
    if ( timecount >= 1000 )
    {
      v9 = 1000.0 / (v6 - timestart);
      NumClients = CBaseServer::GetNumClients(this: &sv);
      ConMsg(a1: "host_profile : %i clients, %.1f msec, %.1f fps\n", NumClients, (double)v7, (double)v9);
      timetotal = 0.0;
      timecount = 0;
      timestart = v6;
    }
  }
  else
  {
    _Host_RunFrame(a1: a2, time);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10189540
// Name: void Host_Init(bool)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __usercall Host_Init(int a1@<ebx>, int a2@<edi>, int a3@<esi>, bool bDedicated)
{
  int v4; // eax
  CThread *v5; // eax
  CDebugInputThread *v6; // esi
  int v7; // eax
  vgui::PropertyPage *v8; // ecx
  int v9; // eax
  int v10; // eax
  int v11; // eax
  int v12; // eax
  CStatTime *v13; // ecx
  IScaleformUI *v14; // esi
  int v15; // eax
  IStaticPropMgrEngine *v16; // eax
  IEngineVGuiInternal *v17; // eax
  void *v18; // ecx
  IEngineVGuiInternal *v19; // eax
  IStaticPropMgrEngine *v20; // eax
  EUniverse SteamUniverse; // eax
  CEngineVoiceSteam *EngineVoiceSteam; // esi
  IMatchExtensions *v23; // eax
  vgui::CTreeViewListControl *v24; // ecx
  ECommandTarget_t TraceType; // eax
  vgui::CTreeViewListControl *v26; // ecx
  ECommandTarget_t v27; // eax
  int v28; // eax
  int v29; // eax
  int v30; // eax
  int v31; // eax
  int v32; // eax
  CMapReslistGenerator *v33; // eax
  int v34; // eax
  CDevShotGenerator *v35; // eax
  int v36; // eax
  vgui::PropertyPage *v37; // ecx
  IMatRenderContext *v38; // eax
  IMatRenderContext *v39; // esi
  int v40; // eax
  vgui::CTreeViewListControl *v41; // ecx
  ECommandTarget_t v42; // eax
  const char **v43; // [esp+58h] [ebp-148h]
  const char *v44; // [esp+5Ch] [ebp-144h]
  float *v45; // [esp+64h] [ebp-13Ch]
  float v46; // [esp+88h] [ebp-118h] BYREF
  int v47; // [esp+8Ch] [ebp-114h]
  float v48; // [esp+90h] [ebp-110h]
  float v49; // [esp+94h] [ebp-10Ch]
  _BYTE v50[264]; // [esp+98h] [ebp-108h] OVERLAPPED BYREF

  realtime = 0.0;
  v4 = _CommandLine();
  if ( (*(int (__thiscall **)(int, const char *, int, int, int))(*(_DWORD *)v4 + 40))(
         a1: v4,
         a2: "-pme",
         a3: a2,
         a4: a3,
         a5: a1) != 0 )
    s_bInitPME = true;
  v46 = NAN;
  v48 = NAN;
  v47 = 2;
  v49 = NAN;
  v50[256] &= 0xFCu;
  if ( (v50[256] & 2) != 0 )
    qmemcpy(v50, nullptr, 0x100u);
  v5 = (CThread *)MemAlloc_Alloc(nSize: 0x9Cu);
  v6 = (CDebugInputThread *)v5;
  if ( v5 != nullptr )
  {
    CThread::CThread(this: v5);
    v6->__vftable = (CDebugInputThread_vtbl *)&CDebugInputThread::`vftable';
    CThreadMutex::CThreadMutex(this: &v6->m_mx);
    CUtlString::CUtlString(this: &v6->m_inputString);
    v6->m_bStop = false;
  }
  else
  {
    v6 = nullptr;
  }
  g_pDebugInputThread = v6;
  CThread::SetName(this: v6, a2: "Debug Input");
  g_pDebugInputThread->Start(this: g_pDebugInputThread, a2: 0, a3: PRIORITY_HIGH);
  v7 = _CommandLine();
  if ( (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v7 + 40))(a1: v7, a2: "-tslist") != 0 )
  {
    _Msg(a1: "Running TSList tests\n");
    _RunTSListTests(a1: 10000, a2: 1);
    _Msg(a1: "Running TSQueue tests\n");
    _RunTSQueueTests(a1: 10000, a2: 1);
    _Msg(a1: "Running Thread Pool tests\n");
    _RunThreadPoolTests();
  }
  if ( !bDedicated )
    v47 = 1;
  if ( _g_pThreadPool != nullptr )
  {
    v45 = &v46;
    ((void (__thiscall *)(IThreadPool *))_g_pThreadPool->Start_2)(a1: _g_pThreadPool);
  }
  host_state.interval_per_tick = 0.016666668;
  InstallBitBufErrorHandler();
  InstallConVarHook();
  TraceInit(i: "Con_Init()", s: "Con_Shutdown()", listnum: 0);
  Con_Init();
  TraceInit(i: "Memory_Init()", s: "Memory_Shutdown()", listnum: 0);
  Memory_Init();
  TraceInit(i: "Cbuf_Init()", s: "Cbuf_Shutdown()", listnum: 0);
  Cbuf_Init();
  TraceInit(i: "Cmd_Init()", s: "Cmd_Shutdown()", listnum: 0);
  Cmd_Init();
  TraceInit(i: "g_pCVar->Init()", s: "g_pCVar->Shutdown()", listnum: 0);
  g_pCVar->Init(this: g_pCVar);
  TraceInit(i: "V_Init()", s: "V_Shutdown()", listnum: 0);
  V_Init();
  TraceInit(i: "COM_Init()", s: "COM_Shutdown()", listnum: 0);
  COM_Init();
  TraceInit(i: "saverestore->Init()", s: "saverestore->Shutdown()", listnum: 0);
  saverestore->Init(this: saverestore);
  TraceInit(i: "Filter_Init()", s: "Filter_Shutdown()", listnum: 0);
  CColorBalanceUIPanel::Init(this: v8);
  TraceInit(i: "Key_Init()", s: "Key_Shutdown()", listnum: 0);
  Key_Init();
  v9 = _CommandLine();
  if ( (*(int (__thiscall **)(int))(*(_DWORD *)v9 + 40))(a1: v9) != 0
    || (v10 = _CommandLine(), v44 = "-allowdebug", (*(int (__thiscall **)(int))(*(_DWORD *)v10 + 40))(a1: v10) != 0)
    && (v11 = _CommandLine(),
        v43 = &stru_10369BD8.m_ppArgv[63],
        (*(int (__thiscall **)(int))(*(_DWORD *)v11 + 40))(a1: v11) == 0) )
  {
    CLoaderMemAlloc::CrtIsValidPointer(
      this: (ConVar *)&sv_cheats.IConVar,
      value: 1,
      a2: (unsigned int)v43,
      a3: (int)v44);
    CLoaderMemAlloc::CrtIsValidPointer(
      this: (ConVar *)&developer.IConVar,
      value: 1,
      a2: (unsigned int)"-dev",
      a3: (int)v45);
  }
  v12 = _CommandLine();
  if ( (*(int (__thiscall **)(int, const char **))(*(_DWORD *)v12 + 40))(a1: v12, a2: &stru_10369BD8.m_ppArgv[59]) != 0 )
    Sys_NoCrashDialog();
  *(float *)&v50[260] = _Plat_FloatTime(this: v13);
  v14 = (IScaleformUI *)(*(_DWORD *)&v50[260] & 0x7FFFFFFF);
  _RandomSeed(a1: *(_DWORD *)&v50[260] & 0x7FFFFFFF);
  DevMsg(a1: (const char *)&stru_10369BD8.m_ppArgv[47], v14, *(float *)&v50[260]);
  TraceInit(i: (const char *)&stru_10369BD8.m_ppArgv[32], s: (const char *)&stru_10369BD8.m_ppArgv[39], listnum: 0);
  g_pSteamSocketMgr->Init(this: g_pSteamSocketMgr);
  TraceInit(i: (const char *)&stru_10369BD8.m_ppArgv[22], s: (const char *)&stru_10369BD8.m_ppArgv[28], listnum: 0);
  NET_Init(bIsDedicated: bDedicated);
  TraceInit(i: (const char *)&stru_10369BD8.m_ppArgv[7], s: (const char *)&stru_10369BD8.m_ppArgv[14], listnum: 0);
  CGameEventManager::Init(this: g_GameEventManager);
  TraceInit(i: &stru_10369BD8.m_pArgvBuffer[500], s: (const char *)&stru_10369BD8.m_ppArgv[3], listnum: 0);
  CGameServer::Init(this: &sv, isDedicated: bDedicated);
  v15 = _CommandLine();
  if ( (*(int (__thiscall **)(int, char *))(*(_DWORD *)v15 + 40))(a1: v15, a2: &stru_10369BD8.m_pArgvBuffer[488]) == 0 )
    SV_InitGameDLL(a1: (int)v14);
  TraceInit(i: &stru_10369BD8.m_pArgvBuffer[444], s: &stru_10369BD8.m_pArgvBuffer[464], listnum: 0);
  g_pMaster->Init(this: g_pMaster);
  TraceInit(i: &stru_10369BD8.m_pArgvBuffer[408], s: &stru_10369BD8.m_pArgvBuffer[424], listnum: 0);
  CLog::Init(this: &g_Log);
  TraceInit(i: &stru_10369BD8.m_pArgvBuffer[380], s: &stru_10369BD8.m_pArgvBuffer[392], listnum: 0);
  _ConDMsg(a1: &stru_10369BD8.m_pArgvBuffer[364], (double)host_parms.memsize * 0.00000095367432);
  Host_CheckGore();
  if ( bDedicated )
  {
    TraceInit(i: &stru_10369BD8.m_pArgvBuffer[284], s: &stru_10369BD8.m_pArgvBuffer[308], listnum: 0);
    InitMaterialSystem(a1: (int)v14);
    TraceInit(i: &stru_10369BD8.m_pArgvBuffer[64], s: &stru_10369BD8.m_pArgvBuffer[84], listnum: 0);
    modelloader->Init(this: modelloader);
    TraceInit(i: &stru_10369BD8.m_pArgvBuffer[12], s: &stru_10369BD8.m_pArgvBuffer[36], listnum: 0);
    v20 = StaticPropMgr();
    v20->Init(this: v20);
    TraceInit(i: &stru_10369BD8.m_pArgSBuffer[480], s: &stru_10369BD8.m_pArgSBuffer[500], listnum: 0);
    InitStudioRender();
    TraceInit(i: &stru_10369BD8.m_pArgSBuffer[420], s: &stru_10369BD8.m_pArgSBuffer[448], listnum: 0);
    g_pMatchFramework->Init(this: g_pMatchFramework);
    TraceInit(i: &stru_10369BD8.m_pArgSBuffer[188], s: &stru_10369BD8.m_pArgSBuffer[204], listnum: 0);
    Decal_Init();
    GetBaseLocalClient()->m_nSignonState = 0;
  }
  else
  {
    TraceInit(i: &stru_10369BD8.m_pArgvBuffer[336], s: &stru_10369BD8.m_pArgvBuffer[348], listnum: 0);
    CL_Init();
    TraceInit(i: &stru_10369BD8.m_pArgvBuffer[284], s: &stru_10369BD8.m_pArgvBuffer[308], listnum: 0);
    InitMaterialSystem(a1: (int)v14);
    TraceInit(i: &stru_10369BD8.m_pArgvBuffer[112], s: &stru_10369BD8.m_pArgvBuffer[228], listnum: 0);
    v14 = g_pScaleformUI;
    ((void (__cdecl *)(int, const char *))g_pScaleformUI->InitSlot)(a1: 1, a2: "resource/flash/MainUIRootMovie.swf");
    v14->InitCursor(this: v14, a2: "resource/flash/Cursor.swf");
    TraceInit(i: &stru_10369BD8.m_pArgvBuffer[64], s: &stru_10369BD8.m_pArgvBuffer[84], listnum: 0);
    modelloader->Init(this: modelloader);
    TraceInit(i: &stru_10369BD8.m_pArgvBuffer[12], s: &stru_10369BD8.m_pArgvBuffer[36], listnum: 0);
    v16 = StaticPropMgr();
    v16->Init(this: v16);
    TraceInit(i: &stru_10369BD8.m_pArgSBuffer[480], s: &stru_10369BD8.m_pArgSBuffer[500], listnum: 0);
    InitStudioRender();
    TraceInit(i: &stru_10369BD8.m_pArgSBuffer[420], s: &stru_10369BD8.m_pArgSBuffer[448], listnum: 0);
    g_pMatchFramework->Init(this: g_pMatchFramework);
    TraceInit(i: &stru_10369BD8.m_pArgSBuffer[368], s: &stru_10369BD8.m_pArgSBuffer[392], listnum: 0);
    v17 = EngineVGui();
    v17->Init(this: v17);
    TraceInit(i: &stru_10369BD8.m_pArgSBuffer[324], s: &stru_10369BD8.m_pArgSBuffer[344], listnum: 0);
    TextMessageInit(this: v18);
    TraceInit(i: &stru_10369BD8.m_pArgSBuffer[280], s: &stru_10369BD8.m_pArgSBuffer[300], listnum: 0);
    ClientDLL_Init();
    TraceInit(i: &stru_10369BD8.m_pArgSBuffer[252], s: &stru_10369BD8.m_pArgSBuffer[264], listnum: 0);
    SCR_Init();
    TraceInit(i: &stru_10369BD8.m_pArgSBuffer[224], s: &stru_10369BD8.m_pArgSBuffer[236], listnum: 0);
    R_Init();
    TraceInit(i: &stru_10369BD8.m_pArgSBuffer[188], s: &stru_10369BD8.m_pArgSBuffer[204], listnum: 0);
    Decal_Init();
    v19 = EngineVGui();
    v19->Connect(this: v19);
  }
  SteamUniverse = GetSteamUniverse();
  if ( SteamUniverse == k_EUniverseBeta || SteamUniverse == k_EUniverseDev )
    CCvarUtilities::EnableDevCvars(this: cv);
  *(_WORD *)g_bConfigCfgExecuted = 0;
  Host_ReadConfiguration(a1: (int)_CommandLine, a2: 0, a3: (int)v14, iController: -1);
  TraceInit(i: &stru_10369BD8.m_pArgSBuffer[160], s: &stru_10369BD8.m_pArgSBuffer[172], listnum: 0);
  S_Init();
  EngineVoiceSteam = Audio_GetEngineVoiceSteam();
  if ( EngineVoiceSteam == nullptr )
  {
    _Warning(a1: &stru_10369BD8.m_pArgSBuffer[124]);
    EngineVoiceSteam = (CEngineVoiceSteam *)Audio_GetEngineVoiceStub();
  }
  v23 = g_pMatchFramework->GetMatchExtensions(this: g_pMatchFramework);
  v23->RegisterExtensionInterface(this: v23, a2: &stru_10369BD8.m_pArgSBuffer[108], a3: EngineVoiceSteam);
  TraceType = CTraceFilter::GetTraceType(this: v24);
  Cbuf_AddText(eTarget: TraceType, pText: &stru_10369BD8.m_pArgSBuffer[92], nTickDelay: 0);
  if ( g_pFileSystem->FileExists(
         this: &g_pFileSystem->IBaseFileSystem,
         a2: &stru_10369BD8.m_pArgSBuffer[64],
         a3: nullptr) )
  {
    v27 = CTraceFilter::GetTraceType(this: v26);
    Cbuf_AddText(eTarget: v27, pText: &stru_10369BD8.m_pArgSBuffer[36], nTickDelay: 0);
  }
  Host_InitProcessor();
  Hunk_AllocName(size: 0, name: &stru_10369BD8.m_pArgSBuffer[16], bClear: true);
  host_hunklevel = Hunk_LowMark();
  v28 = _CommandLine();
  if ( (*(int (__thiscall **)(int, char *))(*(_DWORD *)v28 + 40))(a1: v28, a2: &stru_10369BD8.m_pArgSBuffer[4]) != 0 )
  {
    g_nMaterialSystemThread = 1;
    g_nServerThread = 0;
  }
  g_bAllowThreadedSound = false;
  g_pMaterialSystem->AllowThreading(this: g_pMaterialSystem, a2: false, a3: g_nMaterialSystemThread);
  host_initialized = true;
  v29 = _CommandLine();
  v30 = (*(int (__thiscall **)(int))(*(_DWORD *)v29 + 40))(a1: v29);
  host_checkheap = v30 != 0;
  if ( v30 != 0 )
  {
    _heapchk(args: &stru_10369BD8);
    if ( v31 != -2 )
      Sys_Error(error: "Host_Init:  _heapchk() != _HEAPOK\n");
  }
  HostState_Init();
  v32 = _CommandLine();
  if ( (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v32 + 40))(a1: v32, a2: "-makereslists") != 0 )
  {
    v33 = MapReslistGenerator();
    CMapReslistGenerator::StartReslistGeneration(this: v33);
  }
  v34 = _CommandLine();
  if ( (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v34 + 40))(a1: v34, a2: "-makedevshots") != 0 )
  {
    v35 = DevShotGenerator();
    CDevShotGenerator::StartDevShotGeneration(this: v35);
  }
  if ( sv.m_bIsDedicated )
  {
    v36 = _CommandLine();
    (*(void (__thiscall **)(int, const char *))(*(_DWORD *)v36 + 40))(a1: v36, a2: "-phonehome");
  }
  Host_PostInit();
  CColorBalanceUIPanel::Init(this: v37);
  v38 = g_pMaterialSystem->GetRenderContext(this: g_pMaterialSystem);
  v39 = v38;
  if ( v38 != nullptr )
    v38->BeginRender(this: v38);
  v39->SetNonInteractiveTempFullscreenBuffer(this: v39, a2: nullptr, a3: MATERIAL_NON_INTERACTIVE_MODE_STARTUP);
  ((void (__thiscall *)(IMatRenderContext *, _DWORD, _DWORD, _DWORD, _DWORD))v39->SetNonInteractivePacifierTexture)(
    a1: v39,
    a2: 0,
    a3: 0.0,
    a4: 0.0,
    a5: 0.0);
  ((void (__thiscall *)(IMatRenderContext *, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD))v39->SetNonInteractiveLogoTexture)(
    a1: v39,
    a2: 0,
    a3: 0.0,
    a4: 0.0,
    a5: 0.0,
    a6: 0.0);
  g_pMaterialSystem->FinishRenderTargetAllocation(this: g_pMaterialSystem);
  v40 = _CommandLine();
  if ( (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v40 + 40))(a1: v40, a2: "-profileinit") != 0 )
  {
    v42 = CTraceFilter::GetTraceType(this: v41);
    Cbuf_AddText(eTarget: v42, pText: "quit\n", nTickDelay: 0);
  }
  v39->EndRender(this: v39);
  v39->Release(this: v39);
}

//------------------------------------------------------------------------------
// Address: 0x10189DF0
// Name: void Host_Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall Host_Shutdown(int a1@<ebx>, __int64 a2@<esi:edi>)
{
  int v2; // eax
  CDebugInputThread *v3; // ecx
  vgui::PropertyPage *v4; // ecx
  CEngineVGui *v5; // eax
  IScaleformUI *v6; // esi
  CStaticPropMgr *v7; // eax
  vgui::PropertyPage *v8; // ecx
  CStaticPropMgr *v9; // eax
  CSteam3Client *v10; // eax
  vgui::PropertyPage *v11; // ecx
  vgui::PropertyPage *v12; // ecx
  vgui::PropertyPage *v13; // ecx
  vgui::PropertyPage *v14; // ecx
  int v15; // eax
  int v16; // [esp-4h] [ebp-4h]

  if ( host_checkheap )
  {
    _heapchk();
    if ( v2 != -2 )
      Sys_Error(error: "Host_Shutdown (top):  _heapchk() != _HEAPOK\n");
  }
  if ( shutting_down )
  {
    _Msg(a1: "Recursive shutdown!!!\n");
  }
  else
  {
    shutting_down = true;
    if ( g_pDebugInputThread != nullptr )
    {
      v3 = g_pDebugInputThread;
      g_pDebugInputThread->m_bStop = true;
      CThread::Stop(this: v3, a2: 0);
      if ( g_pDebugInputThread != nullptr )
        ((void (__thiscall *)(CDebugInputThread *, int))g_pDebugInputThread->dtr_CThread)(
          a1: g_pDebugInputThread,
          a2: 1);
    }
    phonehome->Message(this: phonehome, a2: 2u, a3: nullptr);
    phonehome->Shutdown(this: phonehome);
    Host_WriteConfiguration(a1, a2, iController: -1, filename: "config.cfg");
    Host_Disconnect(bShowMainMenu: true);
    scr_disabled_for_loading = true;
    Voice_Deinit();
    CM_FreeMap();
    host_initialized = false;
    VProfRecord_Shutdown();
    if ( sv.m_bIsDedicated )
    {
      if ( g_pMatchFramework != nullptr )
      {
        TraceShutdown(s: &stru_10369BD8.m_pArgSBuffer[448], listnum: 0);
        g_pMatchFramework->Shutdown(this: g_pMatchFramework);
      }
      TraceShutdown(s: &stru_10369BD8.m_pArgSBuffer[172], listnum: 0);
      S_Shutdown(a1: SHIDWORD(a2));
      TraceShutdown(s: &stru_10369BD8.m_pArgSBuffer[204], listnum: 0);
      Decal_Shutdown();
      TraceShutdown(s: &stru_10369BD8.m_pArgvBuffer[84], listnum: 0);
      modelloader->Shutdown(this: modelloader);
      TraceShutdown(s: &stru_10369BD8.m_pArgSBuffer[500], listnum: 0);
      ShutdownStudioRender();
      TraceShutdown(s: &stru_10369BD8.m_pArgvBuffer[36], listnum: 0);
      v9 = StaticPropMgr();
      v9->Shutdown(this: v9);
      TraceShutdown(s: &stru_10369BD8.m_pArgvBuffer[308], listnum: 0);
      ShutdownMaterialSystem(a1: SHIDWORD(a2));
    }
    else
    {
      TraceShutdown(s: &stru_10369BD8.m_pArgSBuffer[204], listnum: 0);
      Decal_Shutdown();
      TraceShutdown(s: &stru_10369BD8.m_pArgSBuffer[236], listnum: 0);
      CColorBalanceUIPanel::Init(this: v4);
      TraceShutdown(s: &stru_10369BD8.m_pArgSBuffer[264], listnum: 0);
      SCR_Shutdown();
      if ( g_pMatchFramework != nullptr )
      {
        TraceShutdown(s: &stru_10369BD8.m_pArgSBuffer[448], listnum: 0);
        g_pMatchFramework->Shutdown(this: g_pMatchFramework);
      }
      v16 = HIDWORD(a2);
      TraceShutdown(s: &stru_10369BD8.m_pArgSBuffer[300], listnum: 0);
      ClientDLL_Shutdown();
      TraceShutdown(s: &stru_10369BD8.m_pArgSBuffer[344], listnum: 0);
      TextMessageShutdown();
      TraceShutdown(s: &stru_10369BD8.m_pArgSBuffer[392], listnum: 0);
      v5 = EngineVGui();
      v5->Shutdown(this: v5);
      TraceShutdown(s: &stru_10369BD8.m_pArgvBuffer[228], listnum: 0);
      v6 = g_pScaleformUI;
      ((void (__stdcall *)(int))g_pScaleformUI->SlotRelease)(a1: 1);
      v6->ReleaseCursor(this: v6);
      TraceShutdown(s: &stru_10369BD8.m_pArgSBuffer[172], listnum: 0);
      S_Shutdown(a1: (int)v6);
      TraceShutdown(s: &stru_10369BD8.m_pArgvBuffer[36], listnum: 0);
      v7 = StaticPropMgr();
      v7->Shutdown(this: v7);
      TraceShutdown(s: &stru_10369BD8.m_pArgvBuffer[84], listnum: 0);
      modelloader->Shutdown(this: modelloader);
      TraceShutdown(s: &stru_10369BD8.m_pArgSBuffer[500], listnum: 0);
      ShutdownStudioRender();
      TraceShutdown(s: &stru_10369BD8.m_pArgvBuffer[308], listnum: 0);
      ShutdownMaterialSystem(a1: (int)v6);
      TraceShutdown(s: &stru_10369BD8.m_pArgvBuffer[348], listnum: 0);
      CColorBalanceUIPanel::Init(this: v8);
      HIDWORD(a2) = v16;
    }
    TraceShutdown(s: &stru_10369BD8.m_pArgvBuffer[392], listnum: 0);
    HLTV_Shutdown();
    TraceShutdown(s: &stru_10369BD8.m_pArgvBuffer[424], listnum: 0);
    CLog::Shutdown(this: &g_Log);
    TraceShutdown(s: (const char *)&stru_10369BD8.m_ppArgv[14], listnum: 0);
    CGameEventManager::Shutdown(this: g_GameEventManager);
    TraceShutdown(s: &stru_10369BD8.m_pArgvBuffer[464], listnum: 0);
    g_pMaster->Shutdown(this: g_pMaster);
    if ( !sv.m_bIsDedicated )
    {
      TraceShutdown(s: "Steam3Client().Shutdown()", listnum: 0);
      v10 = Steam3Client();
      CSteam3Client::Shutdown(this: v10);
    }
    TraceShutdown(s: (const char *)&stru_10369BD8.m_ppArgv[3], listnum: 0);
    CGameServer::Shutdown(this: &sv);
    TraceShutdown(s: (const char *)&stru_10369BD8.m_ppArgv[28], listnum: 0);
    NET_Shutdown();
    TraceShutdown(s: (const char *)&stru_10369BD8.m_ppArgv[39], listnum: 0);
    g_pSteamSocketMgr->Shutdown(this: g_pSteamSocketMgr);
    TraceShutdown(s: "Key_Shutdown()", listnum: 0);
    Key_Shutdown();
    TraceShutdown(s: "ShutdownMixerControls()", listnum: 0);
    ShutdownMixerControls();
    TraceShutdown(s: "Filter_Shutdown()", listnum: 0);
    CColorBalanceUIPanel::Init(this: v11);
    TraceShutdown(s: "saverestore->Shutdown()", listnum: 0);
    saverestore->Shutdown(this: saverestore);
    TraceShutdown(s: "COM_Shutdown()", listnum: 0);
    CColorBalanceUIPanel::Init(this: v12);
    TraceShutdown(s: "V_Shutdown()", listnum: 0);
    CColorBalanceUIPanel::Init(this: v13);
    TraceShutdown(s: "g_pCVar->Shutdown()", listnum: 0);
    g_pCVar->Shutdown(this: g_pCVar);
    TraceShutdown(s: "Cmd_Shutdown()", listnum: 0);
    Cmd_Shutdown();
    TraceShutdown(s: "Cbuf_Shutdown()", listnum: 0);
    CColorBalanceUIPanel::Init(this: v14);
    TraceShutdown(s: "Con_Shutdown()", listnum: 0);
    Con_Shutdown();
    TraceShutdown(s: "Memory_Shutdown()", listnum: 0);
    Memory_Shutdown();
    if ( _g_pThreadPool != nullptr )
      _g_pThreadPool->Stop(this: _g_pThreadPool, a2: -1);
    DTI_Term();
    ServerDTI_Term(a1: a2);
    if ( s_bInitPME )
      _ShutdownPME();
    if ( host_checkheap )
    {
      _heapchk();
      if ( v15 != -2 )
        Sys_Error(error: "Host_Shutdown (bottom):  _heapchk() != _HEAPOK\n");
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1018A320
// Name: void ReserveThreads(int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ReserveThreads(int nToReserve)
{
  int v1; // eax
  int v2; // edi
  CFunctor *v3; // eax

  v1 = _g_pThreadPool->NumThreads(this: _g_pThreadPool);
  v2 = nToReserve;
  if ( nToReserve >= 0 )
  {
    if ( nToReserve > v1 )
      v2 = v1;
  }
  else
  {
    v2 = 0;
  }
  CThreadEvent::Set(this: &g_ReleaseThreadReservation);
  while ( g_NumReservedThreads.m_value != 0 )
    _ThreadSleep(a1: 0);
  CThreadEvent::Reset(this: &g_ReleaseThreadReservation);
  while ( v2 != 0 )
  {
    --v2;
    _InterlockedExchangeAdd(&g_NumReservedThreads.m_value, 1u);
    v3 = (CFunctor *)MemAlloc_Alloc(nSize: 0x14u);
    if ( v3 != nullptr )
    {
      v3[1].m_nUserID = 1;
      v3->__vftable = (CFunctor_vtbl *)&CFunctor0<void (__cdecl *)(void),CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>>::`vftable'{for `CFunctor'};
      v3[1].__vftable = (CFunctor_vtbl *)&CFunctor0<void (__cdecl *)(void),CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>>::`vftable'{for `CRefCountServiceBase<1,CRefMT>'};
      v3[2].__vftable = (CFunctor_vtbl *)ThreadPoolReserverFunction;
    }
    else
    {
      v3 = nullptr;
    }
    _g_pThreadPool->AddFunctorInternal(this: _g_pThreadPool, a2: v3, a3: (CJob **)&nToReserve, a4: nullptr, a5: 8u);
    (*(void (__thiscall **)(int))(*(_DWORD *)nToReserve + 4))(a1: nToReserve);
  }
  _Msg(a1: "%d threads being reserved\n", g_NumReservedThreads.m_value);
}

//------------------------------------------------------------------------------
// Address: 0x1018A400
// Name: void OnChangeThreadReserve(class IConVar __near *,char const __near *,float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl OnChangeThreadReserve()
{
  if ( threadpool_reserve.m_pParent != nullptr )
    ReserveThreads(nToReserve: threadpool_reserve.m_pParent->m_Value.m_nValue);
  else
    ReserveThreads(nToReserve: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1018A420
// Name: threadpool_cycle_reserve
// Source: json
//------------------------------------------------------------------------------
void __cdecl threadpool_cycle_reserve()
{
  int v0; // ecx
  int v1; // esi

  v0 = _g_pThreadPool->NumThreads(this: _g_pThreadPool) + 1;
  v1 = 2 * (v0 / (v0 - g_NumReservedThreads.m_value));
  if ( v1 <= v0 )
    ReserveThreads(nToReserve: v0 - v0 / v1);
  else
    ReserveThreads(nToReserve: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1018A470
// Name: public: virtual void CHostSubscribeForProfileEvents::OnEvent(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHostSubscribeForProfileEvents::OnEvent(CHostSubscribeForProfileEvents *this, KeyValues *pEvent)
{
  const char *Name; // edi
  int Int; // eax

  Name = KeyValues::GetName(this: pEvent);
  if ( _V_stricmp(s1: Name, s2: "OnProfileDataLoaded") == 0 )
  {
    Int = KeyValues::GetInt(this: pEvent, keyName: "iController", defaultValue: 0);
    Host_ReadConfiguration(iController: Int, readDefault: false);
  }
  _V_stricmp(s1: Name, s2: "OnProfileDataLoadFailed");
  _V_stricmp(s1: Name, s2: "OnProfileDataWriteFailed");
}

//------------------------------------------------------------------------------
// Address: 0x1018A4D0
// Name: void Host_BuildUserInfoUpdateMessage(int,class CUtlVector<struct NetMessageCvar_t,class CUtlMemory<struct NetMessageCvar_t,int>> __near &,bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Host_BuildUserInfoUpdateMessage(
        int nSplitScreenSlot,
        CUtlVector<NetMessageCvar_t,CUtlMemory<NetMessageCvar_t,int> > *rCvarList,
        bool nonDefault)
{
  ICvar::ICVarIteratorInternal *v3; // ebx
  ConVar *v4; // esi
  const char *m_pszString; // eax
  const char *Default; // eax
  const char *v7; // eax
  const char *v8; // eax
  const char *v9; // eax
  const char *v10; // [esp-10h] [ebp-220h]
  NetMessageCvar_t acvar; // [esp+0h] [ebp-210h] BYREF
  int nDisallowedFlags; // [esp+208h] [ebp-8h]
  int nRequiredFlags; // [esp+20Ch] [ebp-4h]

  nRequiredFlags = 512;
  nDisallowedFlags = 0x40000;
  if ( nSplitScreenSlot != 0 )
  {
    nDisallowedFlags = 0x8000;
    nRequiredFlags = 262656;
  }
  if ( Host_CountVariablesWithFlags(flags: nRequiredFlags, nonDefault) > 0 )
  {
    v3 = g_pCVar->FactoryInternalIterator(this: g_pCVar);
    v3->SetFirst(this: v3);
    while ( v3->IsValid(this: v3) )
    {
      v4 = (ConVar *)v3->Get(this: v3);
      if ( !v4->IsCommand(this: v4)
        && v4->IsFlagSet(this: v4, a2: nRequiredFlags)
        && !v4->IsFlagSet(this: v4, a2: nDisallowedFlags) )
      {
        if ( !nonDefault )
          goto LABEL_14;
        if ( (v4->m_nFlags & 0x1000) != 0 )
        {
          m_pszString = "FCVAR_NEVER_AS_STRING";
        }
        else
        {
          m_pszString = v4->m_pParent->m_Value.m_pszString;
          if ( m_pszString == nullptr )
            m_pszString = defaultValue;
        }
        v10 = m_pszString;
        Default = ConVar::GetDefault(this: v4);
        if ( V_strcasecmp(s1: Default, s2: v10) != 0 )
        {
LABEL_14:
          if ( v4->GetSplitScreenPlayerSlot(this: &v4->IConVar) == nSplitScreenSlot )
          {
            v7 = v4->GetBaseName(this: &v4->IConVar);
            V_strncpy(pDest: acvar.name, pSrc: v7, maxLen: 260);
            if ( (v4->m_nFlags & 0x1000) != 0 )
            {
              v8 = "FCVAR_NEVER_AS_STRING";
            }
            else
            {
              v8 = v4->m_pParent->m_Value.m_pszString;
              if ( v8 == nullptr )
                v8 = defaultValue;
            }
            v9 = Host_CleanupConVarStringValue(invalue: v8);
            V_strncpy(pDest: acvar.value, pSrc: v9, maxLen: 260);
            CUtlVector<NetMessageCvar_t,CUtlMemory<NetMessageCvar_t,int>>::InsertBefore(
              this: rCvarList,
              elem: rCvarList->m_Size,
              src: &acvar);
          }
        }
      }
      v3->Next(this: v3);
    }
    if ( rCvarList->m_Size <= 255 )
    {
      free(pMem: v3);
    }
    else
    {
      Sys_Error(error: "Engine only supports 255 ConVars marked %i\n", 512);
      free(pMem: v3);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1018A6A0
// Name: void Host_BuildConVarUpdateMessage(class CUtlVector<struct NetMessageCvar_t,class CUtlMemory<struct NetMessageCvar_t,int>> __near &,int,bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Host_BuildConVarUpdateMessage(
        CUtlVector<NetMessageCvar_t,CUtlMemory<NetMessageCvar_t,int> > *rCvarList,
        int flags,
        bool nonDefault)
{
  int v3; // eax
  ICvar::ICVarIteratorInternal *v4; // edi
  ConVar *v5; // esi
  const char *m_pszString; // eax
  const char *Default; // eax
  const char *v8; // eax
  const char *v9; // eax
  const char *v10; // eax
  const char *v11; // [esp-Ch] [ebp-218h]
  NetMessageCvar_t acvar; // [esp+4h] [ebp-208h] BYREF

  v3 = Host_CountVariablesWithFlags(flags, nonDefault);
  if ( v3 > 0 )
  {
    if ( v3 <= 255 )
    {
      v4 = g_pCVar->FactoryInternalIterator(this: g_pCVar);
      v4->SetFirst(this: v4);
      while ( v4->IsValid(this: v4) )
      {
        v5 = (ConVar *)v4->Get(this: v4);
        if ( !v5->IsCommand(this: v5) && v5->IsFlagSet(this: v5, a2: flags) )
        {
          if ( !nonDefault )
            goto LABEL_13;
          if ( (v5->m_nFlags & 0x1000) != 0 )
          {
            m_pszString = "FCVAR_NEVER_AS_STRING";
          }
          else
          {
            m_pszString = v5->m_pParent->m_Value.m_pszString;
            if ( m_pszString == nullptr )
              m_pszString = defaultValue;
          }
          v11 = m_pszString;
          Default = ConVar::GetDefault(this: v5);
          if ( V_strcasecmp(s1: Default, s2: v11) != 0 )
          {
LABEL_13:
            v8 = v5->GetName(this: v5);
            V_strncpy(pDest: acvar.name, pSrc: v8, maxLen: 260);
            if ( (v5->m_nFlags & 0x1000) != 0 )
            {
              v9 = "FCVAR_NEVER_AS_STRING";
            }
            else
            {
              v9 = v5->m_pParent->m_Value.m_pszString;
              if ( v9 == nullptr )
                v9 = defaultValue;
            }
            v10 = Host_CleanupConVarStringValue(invalue: v9);
            V_strncpy(pDest: acvar.value, pSrc: v10, maxLen: 260);
            CUtlVector<NetMessageCvar_t,CUtlMemory<NetMessageCvar_t,int>>::InsertBefore(
              this: rCvarList,
              elem: rCvarList->m_Size,
              src: &acvar);
          }
        }
        v4->Next(this: v4);
      }
      free(pMem: v4);
    }
    else
    {
      Sys_Error(error: "Engine only supports 255 ConVars marked %i\n", flags);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10313700
// Name: _dynamic_initializer_for__host_syncfps__
// Source: semantic_dyn_pfx_host
//------------------------------------------------------------------------------
int dynamic_initializer_for__host_syncfps__()
{
  ConVar::ConVar(
    this: &host_syncfps,
    pName: "host_syncfps",
    pDefaultValue: "0",
    flags: 2,
    pHelpString: "Synchronize real render time to host_framerate if possible.");
  return atexit(func: dynamic_atexit_destructor_for__host_syncfps__);
}

//------------------------------------------------------------------------------
// Address: 0x10317AF0
// Name: _dynamic_initializer_for__host_flush_threshold__
// Source: semantic_dyn_pfx_host
//------------------------------------------------------------------------------
int dynamic_initializer_for__host_flush_threshold__()
{
  ConVar::ConVar(
    this: &host_flush_threshold,
    pName: "host_flush_threshold",
    pDefaultValue: "12",
    flags: 0x80000,
    pHelpString: "Memory threshold below which the host should flush caches between server instances");
  return atexit(func: dynamic_atexit_destructor_for__host_flush_threshold__);
}

//------------------------------------------------------------------------------
// Address: 0x1031A400
// Name: player_info_s_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *player_info_s_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<player_info_s>(__formal: nullptr);
  player_info_s_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1031A7D0
// Name: _dynamic_initializer_for__host_showcachemiss__
// Source: semantic_dyn_pfx_host
//------------------------------------------------------------------------------
int dynamic_initializer_for__host_showcachemiss__()
{
  ConVar::ConVar(
    this: &host_showcachemiss,
    pName: "host_showcachemiss",
    pDefaultValue: "0",
    flags: 0,
    pHelpString: "Print a debug message when the client or server cache is missed.");
  return atexit(func: dynamic_atexit_destructor_for__host_showcachemiss__);
}

//------------------------------------------------------------------------------
// Address: 0x1031A830
// Name: _dynamic_initializer_for__host_ShowIPCCallCount__
// Source: semantic_dyn_pfx_host
//------------------------------------------------------------------------------
int dynamic_initializer_for__host_ShowIPCCallCount__()
{
  ConVar::ConVar(
    this: &host_ShowIPCCallCount,
    pName: "host_ShowIPCCallCount",
    pDefaultValue: "0",
    flags: 0,
    pHelpString: "Print # of IPC calls this number of times per second. If set to -1, the # of IPC calls is shown every frame.");
  return atexit(func: dynamic_atexit_destructor_for__host_ShowIPCCallCount__);
}

//------------------------------------------------------------------------------
// Address: 0x1031A8D0
// Name: _dynamic_initializer_for__host_thread_mode__
// Source: semantic_dyn_pfx_host
//------------------------------------------------------------------------------
int dynamic_initializer_for__host_thread_mode__()
{
  ConVar::ConVar(
    this: &host_thread_mode,
    pName: "host_thread_mode",
    pDefaultValue: "0",
    flags: 2,
    pHelpString: "Run the host in threaded mode, (0 == off, 1 == if multicore, 2 == force)");
  return atexit(func: dynamic_atexit_destructor_for__host_thread_mode__);
}

//------------------------------------------------------------------------------
// Address: 0x1031A900
// Name: _dynamic_initializer_for__host_threaded_sound__
// Source: semantic_dyn_pfx_host
//------------------------------------------------------------------------------
int dynamic_initializer_for__host_threaded_sound__()
{
  ConVar::ConVar(
    this: &host_threaded_sound,
    pName: "host_threaded_sound",
    pDefaultValue: "0",
    flags: 0,
    pHelpString: "Run the sound on a thread (independent of mix)");
  return atexit(func: dynamic_atexit_destructor_for__host_threaded_sound__);
}

//------------------------------------------------------------------------------
// Address: 0x1031AAA0
// Name: _dynamic_initializer_for__host_profile__
// Source: semantic_dyn_pfx_host
//------------------------------------------------------------------------------
int dynamic_initializer_for__host_profile__()
{
  ConVar::ConVar(this: &host_profile, pName: "host_profile", pDefaultValue: "0", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__host_profile__);
}

//------------------------------------------------------------------------------
// Address: 0x1031AB10
// Name: _dynamic_initializer_for__host_timescale__
// Source: semantic_dyn_pfx_host
//------------------------------------------------------------------------------
int dynamic_initializer_for__host_timescale__()
{
  ConVar::ConVar(
    this: &host_timescale,
    pName: "host_timescale",
    pDefaultValue: "1.0",
    flags: 24576,
    pHelpString: "Prescale the clock by this amount.");
  return atexit(func: dynamic_atexit_destructor_for__host_timescale__);
}

//------------------------------------------------------------------------------
// Address: 0x1031AB40
// Name: _dynamic_initializer_for__host_limitlocal__
// Source: semantic_dyn_pfx_host
//------------------------------------------------------------------------------
int dynamic_initializer_for__host_limitlocal__()
{
  ConVar::ConVar(
    this: &host_limitlocal,
    pName: "host_limitlocal",
    pDefaultValue: "0",
    flags: 0,
    pHelpString: "Apply cl_cmdrate and cl_updaterate to loopback connection");
  return atexit(func: dynamic_atexit_destructor_for__host_limitlocal__);
}

//------------------------------------------------------------------------------
// Address: 0x1031AB70
// Name: _dynamic_initializer_for__host_framerate__
// Source: semantic_dyn_pfx_host
//------------------------------------------------------------------------------
int dynamic_initializer_for__host_framerate__()
{
  ConVar::ConVar(
    this: &host_framerate,
    pName: "host_framerate",
    pDefaultValue: "0",
    flags: 0,
    pHelpString: "Set to lock per-frame time elapse.");
  return atexit(func: dynamic_atexit_destructor_for__host_framerate__);
}

//------------------------------------------------------------------------------
// Address: 0x1031ABA0
// Name: _dynamic_initializer_for__host_speeds__
// Source: semantic_dyn_pfx_host
//------------------------------------------------------------------------------
int dynamic_initializer_for__host_speeds__()
{
  ConVar::ConVar(
    this: &host_speeds,
    pName: "host_speeds",
    pDefaultValue: "0",
    flags: 0,
    pHelpString: "Show general system running times.");
  return atexit(func: dynamic_atexit_destructor_for__host_speeds__);
}

//------------------------------------------------------------------------------
// Address: 0x1031ACC0
// Name: _dynamic_initializer_for__host_writeconfig_command__
// Source: semantic_dyn_pfx_host
//------------------------------------------------------------------------------
int dynamic_initializer_for__host_writeconfig_command__()
{
  ConCommand::ConCommand(
    this: &host_writeconfig_command,
    pName: "host_writeconfig",
    callback: (void (__cdecl *)())host_writeconfig,
    pHelpString: "Store current settings to config.cfg (or specified .cfg file).",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__host_writeconfig_command__);
}

//------------------------------------------------------------------------------
// Address: 0x1031ACF0
// Name: _dynamic_initializer_for__host_writeconfig_ss_command__
// Source: semantic_dyn_pfx_host
//------------------------------------------------------------------------------
int dynamic_initializer_for__host_writeconfig_ss_command__()
{
  ConCommand::ConCommand(
    this: &host_writeconfig_ss_command,
    pName: "host_writeconfig_ss",
    callback: (void (__cdecl *)())host_writeconfig_ss,
    pHelpString: "Store current settings to config.cfg (or specified .cfg file) with first param as splitscreen index.",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__host_writeconfig_ss_command__);
}

//------------------------------------------------------------------------------
// Address: 0x1031AD20
// Name: _dynamic_initializer_for__host_reset_config_command__
// Source: semantic_dyn_pfx_host
//------------------------------------------------------------------------------
int dynamic_initializer_for__host_reset_config_command__()
{
  ConCommand::ConCommand(
    this: &host_reset_config_command,
    pName: "host_reset_config",
    callback: (void (__cdecl *)())host_reset_config,
    pHelpString: "reset config (for testing) with param as splitscreen index.",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__host_reset_config_command__);
}

//------------------------------------------------------------------------------
// Address: 0x1031ADE0
// Name: _dynamic_initializer_for__host_runofftime_command__
// Source: semantic_dyn_pfx_host
//------------------------------------------------------------------------------
int dynamic_initializer_for__host_runofftime_command__()
{
  ConCommand::ConCommand(
    this: &host_runofftime_command,
    pName: "host_runofftime",
    callback: (void (__cdecl *)())host_runofftime,
    pHelpString: "Run off some time without rendering/updating sounds\n",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__host_runofftime_command__);
}

//------------------------------------------------------------------------------
// Address: 0x1031AE10
// Name: _dynamic_initializer_for__host_Sleep__
// Source: semantic_dyn_pfx_host
//------------------------------------------------------------------------------
int dynamic_initializer_for__host_Sleep__()
{
  ConVar::ConVar(
    this: &host_Sleep,
    pName: "host_sleep",
    pDefaultValue: "0",
    flags: 0x4000,
    pHelpString: "Force the host to sleep a certain number of milliseconds each frame.");
  return atexit(func: dynamic_atexit_destructor_for__host_Sleep__);
}

//------------------------------------------------------------------------------
// Address: 0x1031AE40
// Name: _dynamic_initializer_for__host_print_frame_times__
// Source: semantic_dyn_pfx_host
//------------------------------------------------------------------------------
int dynamic_initializer_for__host_print_frame_times__()
{
  ConVar::ConVar(this: &host_print_frame_times, pName: "host_print_frame_times", pDefaultValue: "0", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__host_print_frame_times__);
}

//------------------------------------------------------------------------------
// Address: 0x1031AEA0
// Name: _dynamic_initializer_for__host_name__
// Source: semantic_dyn_pfx_host
//------------------------------------------------------------------------------
int dynamic_initializer_for__host_name__()
{
  ConVar::ConVar(
    this: &host_name,
    pName: "hostname",
    pDefaultValue: defaultValue,
    flags: 0x80000,
    pHelpString: "Hostname for server.",
    bMin: false,
    fMin: 0.0,
    bMax: false,
    fMax: 0.0,
    callback: (void (__cdecl *)(IConVar *, const char *, float))HostnameChanged);
  return atexit(func: dynamic_atexit_destructor_for__host_name__);
}

//------------------------------------------------------------------------------
// Address: 0x1031AEE0
// Name: _dynamic_initializer_for__host_map__
// Source: semantic_dyn_pfx_host
//------------------------------------------------------------------------------
int dynamic_initializer_for__host_map__()
{
  ConVar::ConVar(
    this: &host_map,
    pName: "host_map",
    pDefaultValue: defaultValue,
    flags: 0x80000,
    pHelpString: "Current map name.");
  return atexit(func: dynamic_atexit_destructor_for__host_map__);
}

//------------------------------------------------------------------------------
// Address: 0x103227D0
// Name: _dynamic_atexit_destructor_for__host_syncfps__
// Source: semantic_dyn_pfx_host
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__host_syncfps__()
{
  ConVar::~ConVar(this: &host_syncfps);
}

//------------------------------------------------------------------------------
// Address: 0x10324420
// Name: _dynamic_atexit_destructor_for__host_flush_threshold__
// Source: semantic_dyn_pfx_host
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__host_flush_threshold__()
{
  ConVar::~ConVar(this: &host_flush_threshold);
}

//------------------------------------------------------------------------------
// Address: 0x10325560
// Name: _dynamic_atexit_destructor_for__host_showcachemiss__
// Source: semantic_dyn_pfx_host
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__host_showcachemiss__()
{
  ConVar::~ConVar(this: &host_showcachemiss);
}

//------------------------------------------------------------------------------
// Address: 0x10325580
// Name: _dynamic_atexit_destructor_for__host_ShowIPCCallCount__
// Source: semantic_dyn_pfx_host
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__host_ShowIPCCallCount__()
{
  ConVar::~ConVar(this: &host_ShowIPCCallCount);
}

//------------------------------------------------------------------------------
// Address: 0x103255B0
// Name: _dynamic_atexit_destructor_for__host_thread_mode__
// Source: semantic_dyn_pfx_host
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__host_thread_mode__()
{
  ConVar::~ConVar(this: &host_thread_mode);
}

//------------------------------------------------------------------------------
// Address: 0x103255C0
// Name: _dynamic_atexit_destructor_for__host_threaded_sound__
// Source: semantic_dyn_pfx_host
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__host_threaded_sound__()
{
  ConVar::~ConVar(this: &host_threaded_sound);
}

//------------------------------------------------------------------------------
// Address: 0x10325640
// Name: _dynamic_atexit_destructor_for__host_profile__
// Source: semantic_dyn_pfx_host
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__host_profile__()
{
  ConVar::~ConVar(this: &host_profile);
}

//------------------------------------------------------------------------------
// Address: 0x10325660
// Name: _dynamic_atexit_destructor_for__host_timescale__
// Source: semantic_dyn_pfx_host
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__host_timescale__()
{
  ConVar::~ConVar(this: &host_timescale);
}

//------------------------------------------------------------------------------
// Address: 0x10325670
// Name: _dynamic_atexit_destructor_for__host_limitlocal__
// Source: semantic_dyn_pfx_host
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__host_limitlocal__()
{
  ConVar::~ConVar(this: &host_limitlocal);
}

//------------------------------------------------------------------------------
// Address: 0x10325680
// Name: _dynamic_atexit_destructor_for__host_framerate__
// Source: semantic_dyn_pfx_host
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__host_framerate__()
{
  ConVar::~ConVar(this: &host_framerate);
}

//------------------------------------------------------------------------------
// Address: 0x10325690
// Name: _dynamic_atexit_destructor_for__host_speeds__
// Source: semantic_dyn_pfx_host
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__host_speeds__()
{
  ConVar::~ConVar(this: &host_speeds);
}

//------------------------------------------------------------------------------
// Address: 0x103256F0
// Name: _dynamic_atexit_destructor_for__host_writeconfig_command__
// Source: semantic_dyn_pfx_host
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__host_writeconfig_command__()
{
  ConCommand::~ConCommand(this: &host_writeconfig_command);
}

//------------------------------------------------------------------------------
// Address: 0x10325700
// Name: _dynamic_atexit_destructor_for__host_writeconfig_ss_command__
// Source: semantic_dyn_pfx_host
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__host_writeconfig_ss_command__()
{
  ConCommand::~ConCommand(this: &host_writeconfig_ss_command);
}

//------------------------------------------------------------------------------
// Address: 0x10325710
// Name: _dynamic_atexit_destructor_for__host_reset_config_command__
// Source: semantic_dyn_pfx_host
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__host_reset_config_command__()
{
  ConCommand::~ConCommand(this: &host_reset_config_command);
}

//------------------------------------------------------------------------------
// Address: 0x10325760
// Name: _dynamic_atexit_destructor_for__host_runofftime_command__
// Source: semantic_dyn_pfx_host
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__host_runofftime_command__()
{
  ConCommand::~ConCommand(this: &host_runofftime_command);
}

//------------------------------------------------------------------------------
// Address: 0x10325770
// Name: _dynamic_atexit_destructor_for__host_Sleep__
// Source: semantic_dyn_pfx_host
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__host_Sleep__()
{
  ConVar::~ConVar(this: &host_Sleep);
}

//------------------------------------------------------------------------------
// Address: 0x10325780
// Name: _dynamic_atexit_destructor_for__host_print_frame_times__
// Source: semantic_dyn_pfx_host
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__host_print_frame_times__()
{
  ConVar::~ConVar(this: &host_print_frame_times);
}

//------------------------------------------------------------------------------
// Address: 0x103257B0
// Name: _dynamic_atexit_destructor_for__host_name__
// Source: semantic_dyn_pfx_host
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__host_name__()
{
  ConVar::~ConVar(this: &host_name);
}

//------------------------------------------------------------------------------
// Address: 0x103257C0
// Name: _dynamic_atexit_destructor_for__host_map__
// Source: semantic_dyn_pfx_host
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__host_map__()
{
  ConVar::~ConVar(this: &host_map);
}

//------------------------------------------------------------------------------
// Address: 0x10313730
// Name: _dynamic_initializer_for__fps_screenshot_threshold__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__fps_screenshot_threshold__()
{
  ConVar::ConVar(
    this: &fps_screenshot_threshold,
    pName: "fps_screenshot_threshold",
    pDefaultValue: "-1",
    flags: 0x4000,
    pHelpString: "Dump a screenshot when the FPS drops below the given value.");
  return atexit(func: dynamic_atexit_destructor_for__fps_screenshot_threshold__);
}

//------------------------------------------------------------------------------
// Address: 0x10313760
// Name: _dynamic_initializer_for__fps_screenshot_frequency__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__fps_screenshot_frequency__()
{
  ConVar::ConVar(
    this: &fps_screenshot_frequency,
    pName: "fps_screenshot_frequency",
    pDefaultValue: "10",
    flags: 0x4000,
    pHelpString: "While the fps is below the threshold we will dump a screen shot this often in seconds (i.e. 10 = screen shot every 1"
    "0 seconds when under the given fps.)");
  return atexit(func: dynamic_atexit_destructor_for__fps_screenshot_frequency__);
}

//------------------------------------------------------------------------------
// Address: 0x10313790
// Name: _dynamic_initializer_for__startmovie_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__startmovie_command__()
{
  ConCommand::ConCommand(
    this: &startmovie_command,
    pName: "startmovie",
    callback: (void (__cdecl *)())startmovie,
    pHelpString: "Start recording movie frames.",
    flags: 0x20000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__startmovie_command__);
}

//------------------------------------------------------------------------------
// Address: 0x103137C0
// Name: _dynamic_initializer_for__endmovie_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__endmovie_command__()
{
  ConCommand::ConCommand(
    this: &endmovie_command,
    pName: "endmovie",
    callback: endmovie,
    pHelpString: "Stop recording movie frames.",
    flags: 0x20000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__endmovie_command__);
}

//------------------------------------------------------------------------------
// Address: 0x1031A410
// Name: _dynamic_initializer_for__violence_hblood__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__violence_hblood__()
{
  ConVar::ConVar(
    this: &violence_hblood,
    pName: "violence_hblood",
    pDefaultValue: "1",
    flags: 0,
    pHelpString: "Draw human blood");
  return atexit(func: dynamic_atexit_destructor_for__violence_hblood__);
}

//------------------------------------------------------------------------------
// Address: 0x1031A440
// Name: _dynamic_initializer_for__violence_hgibs__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__violence_hgibs__()
{
  ConVar::ConVar(
    this: &violence_hgibs,
    pName: "violence_hgibs",
    pDefaultValue: "1",
    flags: 0,
    pHelpString: "Show human gib entities");
  return atexit(func: dynamic_atexit_destructor_for__violence_hgibs__);
}

//------------------------------------------------------------------------------
// Address: 0x1031A470
// Name: _dynamic_initializer_for__violence_ablood__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__violence_ablood__()
{
  ConVar::ConVar(
    this: &violence_ablood,
    pName: "violence_ablood",
    pDefaultValue: "1",
    flags: 0,
    pHelpString: "Draw alien blood");
  return atexit(func: dynamic_atexit_destructor_for__violence_ablood__);
}

//------------------------------------------------------------------------------
// Address: 0x1031A4A0
// Name: _dynamic_initializer_for__violence_agibs__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__violence_agibs__()
{
  ConVar::ConVar(
    this: &violence_agibs,
    pName: "violence_agibs",
    pDefaultValue: "1",
    flags: 0,
    pHelpString: "Show alien gib entities");
  return atexit(func: dynamic_atexit_destructor_for__violence_agibs__);
}

//------------------------------------------------------------------------------
// Address: 0x1031A4D0
// Name: _dynamic_initializer_for__closecaption__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__closecaption__()
{
  ConVar::ConVar(
    this: &closecaption,
    pName: "closecaption",
    pDefaultValue: "0",
    flags: 16777856,
    pHelpString: "Enable close captioning.");
  return atexit(func: dynamic_atexit_destructor_for__closecaption__);
}

//------------------------------------------------------------------------------
// Address: 0x1031A800
// Name: _dynamic_initializer_for__mem_dumpstats__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mem_dumpstats__()
{
  ConVar::ConVar(
    this: &mem_dumpstats,
    pName: "mem_dumpstats",
    pDefaultValue: "0",
    flags: 0,
    pHelpString: "Dump current and max heap usage info to console at end of frame ( set to 2 for continuous output )\n");
  return atexit(func: dynamic_atexit_destructor_for__mem_dumpstats__);
}

//------------------------------------------------------------------------------
// Address: 0x1031A930
// Name: _dynamic_initializer_for__threadpool_affinity__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__threadpool_affinity__()
{
  ConVar::ConVar(
    this: &threadpool_affinity,
    pName: "threadpool_affinity",
    pDefaultValue: "1",
    flags: 0,
    pHelpString: "Enable setting affinity",
    bMin: false,
    fMin: 0.0,
    bMax: false,
    fMax: 0.0,
    callback: (void (__cdecl *)(IConVar *, const char *, float))OnChangeThreadAffinity);
  return atexit(func: dynamic_atexit_destructor_for__threadpool_affinity__);
}

//------------------------------------------------------------------------------
// Address: 0x1031A970
// Name: _dynamic_initializer_for__g_ReleaseThreadReservation__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_ReleaseThreadReservation__()
{
  CThreadEvent::CThreadEvent(this: &g_ReleaseThreadReservation, a2: true);
  return atexit(func: dynamic_atexit_destructor_for__g_ReleaseThreadReservation__);
}

//------------------------------------------------------------------------------
// Address: 0x1031A990
// Name: _dynamic_initializer_for__g_NumReservedThreads__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void dynamic_initializer_for__g_NumReservedThreads__()
{
  g_NumReservedThreads.m_value = 0;
}

//------------------------------------------------------------------------------
// Address: 0x1031A9A0
// Name: _dynamic_initializer_for__threadpool_reserve__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__threadpool_reserve__()
{
  ConVar::ConVar(
    this: &threadpool_reserve,
    pName: "threadpool_reserve",
    pDefaultValue: "0",
    flags: 0,
    pHelpString: "Consume the specified number of threads in the thread pool",
    bMin: false,
    fMin: 0.0,
    bMax: false,
    fMax: 0.0,
    callback: (void (__cdecl *)(IConVar *, const char *, float))OnChangeThreadReserve);
  return atexit(func: dynamic_atexit_destructor_for__threadpool_reserve__);
}

//------------------------------------------------------------------------------
// Address: 0x1031A9E0
// Name: _dynamic_initializer_for__threadpool_cycle_reserve_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__threadpool_cycle_reserve_command__()
{
  ConCommand::ConCommand(
    this: &threadpool_cycle_reserve_command,
    pName: "threadpool_cycle_reserve",
    callback: threadpool_cycle_reserve,
    pHelpString: "Cycles threadpool reservation by powers of 2",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__threadpool_cycle_reserve_command__);
}

//------------------------------------------------------------------------------
// Address: 0x1031AAD0
// Name: _dynamic_initializer_for__skill__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__skill__()
{
  ConVar::ConVar(
    this: &skill,
    pName: "skill",
    pDefaultValue: "1",
    flags: 128,
    pHelpString: "Game skill level (1-3).",
    bMin: true,
    fMin: 1.0,
    bMax: true,
    fMax: 3.0);
  return atexit(func: dynamic_atexit_destructor_for__skill__);
}

//------------------------------------------------------------------------------
// Address: 0x1031ABD0
// Name: _dynamic_initializer_for__developer__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__developer__()
{
  ConVar::ConVar(
    this: &developer,
    pName: "developer",
    pDefaultValue: "0",
    flags: 0x4000,
    pHelpString: "Set developer message level");
  return atexit(func: dynamic_atexit_destructor_for__developer__);
}

//------------------------------------------------------------------------------
// Address: 0x1031AC00
// Name: _dynamic_initializer_for__deathmatch__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__deathmatch__()
{
  ConVar::ConVar(
    this: &deathmatch,
    pName: "deathmatch",
    pDefaultValue: "0",
    flags: 256,
    pHelpString: "Running a deathmatch server.");
  return atexit(func: dynamic_atexit_destructor_for__deathmatch__);
}

//------------------------------------------------------------------------------
// Address: 0x1031AC30
// Name: _dynamic_initializer_for__coop__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__coop__()
{
  ConVar::ConVar(this: &coop, pName: "coop", pDefaultValue: "0", flags: 256, pHelpString: "Cooperative play.");
  return atexit(func: dynamic_atexit_destructor_for__coop__);
}

//------------------------------------------------------------------------------
// Address: 0x1031AD50
// Name: _dynamic_initializer_for__recompute_speed__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__recompute_speed__()
{
  ConCommand::ConCommand(
    this: &recompute_speed,
    pName: "recompute_speed",
    callback: Host_RecomputeSpeed_f,
    pHelpString: "Recomputes clock speed (for debugging purposes).",
    flags: 0x4000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__recompute_speed__);
}

//------------------------------------------------------------------------------
// Address: 0x1031AD80
// Name: _dynamic_initializer_for__dti_flush__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__dti_flush__()
{
  ConCommand::ConCommand(
    this: &dti_flush,
    pName: "dti_flush",
    callback: (void (__cdecl *)())DTI_Flush_f,
    pHelpString: "Write out the datatable instrumentation files (you must run with -dti for this to work).",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__dti_flush__);
}

//------------------------------------------------------------------------------
// Address: 0x1031ADB0
// Name: _dynamic_initializer_for__mem_periodicdumps__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mem_periodicdumps__()
{
  ConVar::ConVar(
    this: &mem_periodicdumps,
    pName: "mem_periodicdumps",
    pDefaultValue: "0",
    flags: 0,
    pHelpString: "Write periodic memstats dumps every n seconds.");
  return atexit(func: dynamic_atexit_destructor_for__mem_periodicdumps__);
}

//------------------------------------------------------------------------------
// Address: 0x1031AE70
// Name: _dynamic_initializer_for__fs_enable_stats__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__fs_enable_stats__()
{
  ConVar::ConVar(this: &fs_enable_stats, pName: "fs_enable_stats", pDefaultValue: "0", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__fs_enable_stats__);
}

//------------------------------------------------------------------------------
// Address: 0x103227E0
// Name: _dynamic_atexit_destructor_for__fps_screenshot_threshold__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__fps_screenshot_threshold__()
{
  ConVar::~ConVar(this: &fps_screenshot_threshold);
}

//------------------------------------------------------------------------------
// Address: 0x103227F0
// Name: _dynamic_atexit_destructor_for__fps_screenshot_frequency__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__fps_screenshot_frequency__()
{
  ConVar::~ConVar(this: &fps_screenshot_frequency);
}

//------------------------------------------------------------------------------
// Address: 0x10322800
// Name: _dynamic_atexit_destructor_for__startmovie_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__startmovie_command__()
{
  ConCommand::~ConCommand(this: &startmovie_command);
}

//------------------------------------------------------------------------------
// Address: 0x10322810
// Name: _dynamic_atexit_destructor_for__endmovie_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__endmovie_command__()
{
  ConCommand::~ConCommand(this: &endmovie_command);
}

//------------------------------------------------------------------------------
// Address: 0x10325570
// Name: _dynamic_atexit_destructor_for__mem_dumpstats__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mem_dumpstats__()
{
  ConVar::~ConVar(this: &mem_dumpstats);
}

//------------------------------------------------------------------------------
// Address: 0x103255D0
// Name: _dynamic_atexit_destructor_for__threadpool_affinity__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__threadpool_affinity__()
{
  ConVar::~ConVar(this: &threadpool_affinity);
}

//------------------------------------------------------------------------------
// Address: 0x103255E0
// Name: _dynamic_atexit_destructor_for__g_ReleaseThreadReservation__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_ReleaseThreadReservation__()
{
  CThreadSyncObject::~CThreadSyncObject(this: &g_ReleaseThreadReservation);
}

//------------------------------------------------------------------------------
// Address: 0x103255F0
// Name: _dynamic_atexit_destructor_for__threadpool_reserve__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__threadpool_reserve__()
{
  ConVar::~ConVar(this: &threadpool_reserve);
}

//------------------------------------------------------------------------------
// Address: 0x10325600
// Name: _dynamic_atexit_destructor_for__threadpool_cycle_reserve_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__threadpool_cycle_reserve_command__()
{
  ConCommand::~ConCommand(this: &threadpool_cycle_reserve_command);
}

//------------------------------------------------------------------------------
// Address: 0x10325650
// Name: _dynamic_atexit_destructor_for__skill__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__skill__()
{
  ConVar::~ConVar(this: &skill);
}

//------------------------------------------------------------------------------
// Address: 0x103256A0
// Name: _dynamic_atexit_destructor_for__developer__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__developer__()
{
  ConVar::~ConVar(this: &developer);
}

//------------------------------------------------------------------------------
// Address: 0x103256B0
// Name: _dynamic_atexit_destructor_for__deathmatch__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__deathmatch__()
{
  ConVar::~ConVar(this: &deathmatch);
}

//------------------------------------------------------------------------------
// Address: 0x103256C0
// Name: _dynamic_atexit_destructor_for__coop__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__coop__()
{
  ConVar::~ConVar(this: &coop);
}

//------------------------------------------------------------------------------
// Address: 0x10325720
// Name: _dynamic_atexit_destructor_for__recompute_speed__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__recompute_speed__()
{
  ConCommand::~ConCommand(this: &recompute_speed);
}

//------------------------------------------------------------------------------
// Address: 0x10325730
// Name: _dynamic_atexit_destructor_for__dti_flush__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__dti_flush__()
{
  ConCommand::~ConCommand(this: &dti_flush);
}

//------------------------------------------------------------------------------
// Address: 0x10325740
// Name: _dynamic_atexit_destructor_for__mem_periodicdumps__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mem_periodicdumps__()
{
  ConVar::~ConVar(this: &mem_periodicdumps);
}

//------------------------------------------------------------------------------
// Address: 0x10325750
// Name: __Host_RunFrame_Server_::_4_::_dynamic_atexit_destructor_for___counter__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _Host_RunFrame_Server_::_4_::_dynamic_atexit_destructor_for___counter__()
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x10325790
// Name: _dynamic_atexit_destructor_for__fs_enable_stats__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__fs_enable_stats__()
{
  ConVar::~ConVar(this: &fs_enable_stats);
}

//------------------------------------------------------------------------------
// Address: 0x103257A0
// Name: _DataMapInit_player_info_s__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_player_info_s__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_1);
}

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x10013F20
// Name: public: virtual int CRefCounted1<class CFunctor,class CRefCountServiceBase<1,class CRefMT>>::AddRef(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>::AddRef(
        CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT> > *this)
{
  return _InterlockedIncrement(&this->m_iRefs);
}

//------------------------------------------------------------------------------
// Address: 0x10013F30
// Name: public: virtual int CRefCounted1<class CFunctor,class CRefCountServiceBase<1,class CRefMT>>::Release(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>::Release(
        CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT> > *this)
{
  CRefCountServiceBase<1,CRefMT> *v1; // esi
  int result; // eax

  v1 = &this->CRefCountServiceBase<1,CRefMT>;
  result = _InterlockedDecrement(&this->m_iRefs);
  if ( result == 0 )
  {
    if ( v1->OnFinalRelease(this: v1) )
      ((void (__thiscall *)(CRefCountServiceBase<1,CRefMT> *, int))v1->dtr_CRefCountServiceBase<1,CRefMT>)(
        a1: v1,
        a2: 1);
    return 0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100D6FA0
// Name: public: virtual int CRefCounted1<class IRefCounted,class CRefCountServiceBase<1,class CRefMT>>::AddRef(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CRefCounted1<IRefCounted,CRefCountServiceBase<1,CRefMT>>::AddRef(
        CRefCounted1<IWorldRenderList,CRefCountServiceBase<1,CRefMT> > *this)
{
  return _InterlockedIncrement(&this->m_iRefs);
}

//------------------------------------------------------------------------------
// Address: 0x10184380
// Name: public: static void CClockSpeedInit::Init(void)
// Source: json
//------------------------------------------------------------------------------
// write access to const memory has been detected, the output may be wrong!
static void __cdecl CClockSpeedInit::Init()
{
  int CPUInformation; // eax

  CPUInformation = _GetCPUInformation();
  LODWORD(_g_ClockSpeed) = *(_DWORD *)(CPUInformation + 8);
  HIDWORD(_g_ClockSpeed) = *(_DWORD *)(CPUInformation + 12);
  _g_dwClockSpeed = _g_ClockSpeed;
  _g_ClockSpeedMicrosecondsMultiplier = 1000000.0 / (double)__PAIR64__(HIDWORD(_g_ClockSpeed), _g_ClockSpeed);
  _g_ClockSpeedMillisecondsMultiplier = 1000.0 / (double)__PAIR64__(HIDWORD(_g_ClockSpeed), _g_ClockSpeed);
  _g_ClockSpeedSecondsMultiplier = 1.0 / (double)__PAIR64__(HIDWORD(_g_ClockSpeed), _g_ClockSpeed);
}

//------------------------------------------------------------------------------
// Address: 0x10184470
// Name: float Host_GetServerSimulationFrameTime(void)
// Source: json
//------------------------------------------------------------------------------
double __cdecl Host_GetServerSimulationFrameTime()
{
  return g_HostTimes.m_flLastServerTime;
}

//------------------------------------------------------------------------------
// Address: 0x10184480
// Name: mem_dump
// Source: json
//------------------------------------------------------------------------------
void __cdecl mem_dump()
{
  char *m_szMapname; // eax

  ConMsg(a1: "Writing memory stats to file memstats.txt\n");
  m_szMapname = sv.m_szMapname;
  if ( sv.m_szMapname[0] == 0 )
    m_szMapname = "nomap";
  V_FileBase(in: m_szMapname, out: mapname, maxlen: 256);
  Host_PrintMemoryStatus(mapname: mapname);
  _g_pMemAlloc->DumpStatsFileBase(this: _g_pMemAlloc, a2: mapname);
}

//------------------------------------------------------------------------------
// Address: 0x101844F0
// Name: mem_compact
// Source: json
//------------------------------------------------------------------------------
void __cdecl mem_compact()
{
  _g_pMemAlloc->CompactHeap(this: _g_pMemAlloc);
}

//------------------------------------------------------------------------------
// Address: 0x10184500
// Name: mem_incremental_compact
// Source: json
//------------------------------------------------------------------------------
void __cdecl mem_incremental_compact()
{
  _g_pMemAlloc->CompactIncremental(this: _g_pMemAlloc);
}

//------------------------------------------------------------------------------
// Address: 0x10184520
// Name: mem_eat
// Source: json
//------------------------------------------------------------------------------
void __cdecl mem_eat()
{
  _g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 0x100000u);
}

//------------------------------------------------------------------------------
// Address: 0x10184540
// Name: thread_test_tslist
// Source: json
//------------------------------------------------------------------------------
void __cdecl thread_test_tslist(const CCommand *args)
{
  int v1; // edi
  const char *v2; // eax
  const char *v3; // eax
  int v4; // eax

  if ( args->m_nArgc == 1 )
  {
    v1 = 1;
  }
  else
  {
    v2 = defaultValue;
    if ( args->m_nArgc > 1 )
      v2 = args->m_ppArgv[1];
    v1 = atoi(nptr: v2);
  }
  if ( args->m_nArgc == 2 )
  {
    _RunTSListTests(a1: v1, a2: 1);
  }
  else
  {
    v3 = defaultValue;
    if ( args->m_nArgc > 2 )
      v3 = args->m_ppArgv[2];
    v4 = atoi(nptr: v3);
    _RunTSListTests(a1: v1, a2: v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101845B0
// Name: thread_test_tsqueue
// Source: json
//------------------------------------------------------------------------------
void __cdecl thread_test_tsqueue(const CCommand *args)
{
  int v1; // edi
  const char *v2; // eax
  const char *v3; // esi
  int v4; // eax

  if ( args->m_nArgc >= 2 )
  {
    v2 = defaultValue;
    if ( args->m_nArgc > 1 )
      v2 = args->m_ppArgv[1];
    v1 = atoi(nptr: v2);
  }
  else
  {
    v1 = 10000;
  }
  if ( args->m_nArgc >= 3 )
  {
    if ( args->m_nArgc > 2 )
      v3 = args->m_ppArgv[2];
    else
      v3 = defaultValue;
    v4 = atoi(nptr: v3);
    _RunTSQueueTests(a1: v1, a2: v4);
  }
  else
  {
    _RunTSQueueTests(a1: v1, a2: 1);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10184630
// Name: threadpool_run_tests
// Source: json
//------------------------------------------------------------------------------
void __cdecl threadpool_run_tests(const CCommand *args)
{
  int m_nArgc; // eax
  const char *v2; // eax
  int i; // esi

  m_nArgc = args->m_nArgc;
  if ( args->m_nArgc != 1 )
  {
    v2 = defaultValue;
    if ( args->m_nArgc > 1 )
      v2 = args->m_ppArgv[1];
    m_nArgc = atoi(nptr: v2);
  }
  if ( m_nArgc > 0 )
  {
    for ( i = m_nArgc; i != 0; --i )
      _RunThreadPoolTests();
  }
}

//------------------------------------------------------------------------------
// Address: 0x10184670
// Name: public: struct AudioState_t const __near & CAudioState::GetPerUser(int)const
// Source: json
//------------------------------------------------------------------------------
CAudioState *__thiscall CAudioState::GetPerUser(CAudioState *this, int nSlot)
{
  CAudioState *result; // eax

  result = this;
  if ( nSlot != -1 )
    return (CAudioState *)((char *)this + 28 * nSlot);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10184690
// Name: display_elapsedtime
// Source: json
//------------------------------------------------------------------------------
void __cdecl display_elapsedtime()
{
  _Msg(a1: "Elapsed time: %.2f\n", realtime);
}

//------------------------------------------------------------------------------
// Address: 0x101846B0
// Name: public: void CCommonHostState::SetWorldModel(struct model_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCommonHostState::SetWorldModel(CCommonHostState *this, model_t *pModel)
{
  if ( this->worldmodel != pModel )
  {
    this->worldmodel = pModel;
    if ( pModel != nullptr )
      this->worldbrush = pModel->brush.pShared;
    else
      this->worldbrush = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101846E0
// Name: void Host_SetAudioState(struct AudioState_t const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Host_SetAudioState(const AudioState_t *audioState)
{
  s_AudioState.m_PerUser[0] = *audioState;
}

//------------------------------------------------------------------------------
// Address: 0x10184700
// Name: bool Host_IsLocalServer(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall Host_IsLocalServer(CEngineClient *this)
{
  return sv.m_State >= ss_active;
}

//------------------------------------------------------------------------------
// Address: 0x10184710
// Name: bool Host_IsSinglePlayerGame(void)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl Host_IsSinglePlayerGame()
{
  if ( sv.m_State < ss_active )
    return GetBaseLocalClient()->m_nMaxClients == 1;
  else
    return sv.m_nMaxclients <= 1;
}

//------------------------------------------------------------------------------
// Address: 0x10184740
// Name: void Host_EndGame(bool,char const __near *,...)
// Source: json
//------------------------------------------------------------------------------
void Host_EndGame(bool bShowMainMenu, const char *message, ...)
{
  int demonum; // esi
  char string[1024]; // [esp+4h] [ebp-400h] BYREF
  va_list params; // [esp+414h] [ebp+10h] BYREF

  va_start(params, message);
  V_vsnprintf(pDest: string, maxLen: 1024, pFormat: message, params);
  ConMsg(a1: "Host_EndGame: %s\n", string);
  scr_disabled_for_loading = true;
  demonum = GetBaseLocalClient()->demonum;
  GetBaseLocalClient()->demonum = -1;
  Host_Disconnect(bShowMainMenu);
  GetBaseLocalClient()->demonum = demonum;
  if ( sv.m_bIsDedicated )
  {
    Sys_Error(error: "Host_EndGame: %s\n", string);
  }
  else
  {
    if ( GetBaseLocalClient()->demonum != -1 )
    {
      CL_NextDemo();
      longjmp(Buf: host_enddemo, Value: 1);
    }
    scr_disabled_for_loading = false;
    if ( g_bAbortServerSet )
      longjmp(Buf: host_abortserver, Value: 1);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10184810
// Name: void Host_Error(char const __near *,...)
// Source: json
//------------------------------------------------------------------------------
void Host_Error(const char *error, ...)
{
  char string[1024]; // [esp+0h] [ebp-400h] BYREF
  va_list params; // [esp+40Ch] [ebp+Ch] BYREF

  va_start(params, error);
  if ( inerror )
    Sys_Error(error: "Host_Error: recursively entered");
  inerror = true;
  V_vsnprintf(pDest: string, maxLen: 1024, pFormat: error, params);
  if ( sv.m_bIsDedicated )
  {
    Sys_Error(error: "Host_Error: %s\n", string);
  }
  else
  {
    SCR_EndLoadingPlaque();
    ConMsg(a1: "\nHost_Error: %s\n\n", string);
    Host_Disconnect(bShowMainMenu: true);
    GetBaseLocalClient()->demonum = -1;
    inerror = false;
    if ( g_bAbortServerSet )
      longjmp(Buf: host_abortserver, Value: 1);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101848C0
// Name: void UseDefaultBindings(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl UseDefaultBindings()
{
  void *v0; // esi
  unsigned int v1; // edi
  void *v2; // ebx
  const char *i; // esi
  const char *v4; // esi
  ButtonCode_t v5; // eax
  char token[1024]; // [esp+4h] [ebp-608h] BYREF
  char szFileName[260]; // [esp+404h] [ebp-208h] BYREF
  char szKeyName[260]; // [esp+508h] [ebp-104h] BYREF

  V_snprintf(pDest: szFileName, maxLen: 260, pFormat: "%skb_def.lst", "scripts/");
  v0 = g_pFileSystem->Open(this: &g_pFileSystem->IBaseFileSystem, a2: szFileName, a3: "r", a4: 0);
  if ( v0 != nullptr )
  {
    v1 = g_pFileSystem->Size_2(this: &g_pFileSystem->IBaseFileSystem, a2: v0);
    v2 = MemAlloc_Alloc(nSize: v1);
    g_pFileSystem->Read(this: &g_pFileSystem->IBaseFileSystem, a2: v2, a3: v1, a4: v0);
    g_pFileSystem->Close(this: &g_pFileSystem->IBaseFileSystem, a2: v0);
    for ( i = COM_ParseFile(data: (const char *)v2, token, maxtoken: 1024);
          strlen(token) != 0;
          i = COM_ParseFile(data: v4, token, maxtoken: 1024) )
    {
      V_strncpy(pDest: szKeyName, pSrc: token, maxLen: 256);
      v4 = COM_ParseFile(data: i, token, maxtoken: 1024);
      if ( strlen(token) == 0 )
        break;
      v5 = g_pInputSystem->StringToButtonCode(this: g_pInputSystem, a2: szKeyName);
      Key_SetBinding(keynum: v5, pBinding: token);
    }
    free(pMem: v2);
  }
  else
  {
    ConMsg(a1: "Couldn't open kb_def.lst\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x10184B30
// Name: void Host_RecomputeSpeed_f(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Host_RecomputeSpeed_f()
{
  ConMsg(a1: "Recomputing clock speed...\n");
  CClockSpeedInit::Init();
  ConMsg(a1: "Clock speed: %.0f Mhz\n", (double)_g_dwClockSpeed * 0.000001);
}

//------------------------------------------------------------------------------
// Address: 0x10184B80
// Name: void DTI_Flush_f(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DTI_Flush_f()
{
  vgui::PropertyPage *v0; // ecx

  DTI_Flush();
  ServerDTI_Flush();
  CColorBalanceUIPanel::Init(this: v0);
}

//------------------------------------------------------------------------------
// Address: 0x10184B90
// Name: void Host_GetHostInfo(float __near *,int __near *,int __near *,char __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Host_GetHostInfo(float *fps, int *nActive, int *nMaxPlayers, char *pszMap, int maxlen)
{
  int NumClients; // eax

  NumClients = CBaseServer::GetNumClients(this: &sv);
  *fps = g_fFramesPerSecond;
  *nActive = NumClients;
  if ( pszMap != nullptr )
  {
    if ( sv.m_szMapname[0] != 0 )
    {
      V_strncpy(pDest: pszMap, pSrc: sv.m_szMapname, maxLen: maxlen);
      *nMaxPlayers = CBaseServer::GetMaxClients(this: &sv);
      return;
    }
    *pszMap = 0;
  }
  *nMaxPlayers = CBaseServer::GetMaxClients(this: &sv);
}

//------------------------------------------------------------------------------
// Address: 0x10184C00
// Name: AppearsNumeric
// Source: json
//------------------------------------------------------------------------------
bool __usercall AppearsNumeric@<al>(char *in@<eax>)
{
  char v2; // cl
  int v3; // ebx
  int v4; // edi
  bool result; // al
  int v6; // edx
  int i; // ecx
  int special[3]; // [esp+Ch] [ebp-Ch] BYREF

  _V_memset(dest: special, fill: 0, count: 12);
  v2 = *in;
  v3 = special[1];
  v4 = special[0];
  result = true;
  if ( *in != 0 )
  {
    v6 = special[2];
    while ( 1 )
    {
      if ( v2 == 45 )
      {
        ++v4;
      }
      else if ( v2 == 43 )
      {
        ++v3;
      }
      else if ( v2 < 48 || v2 > 57 )
      {
        if ( v2 != 46 )
          return false;
        ++v6;
      }
      v2 = *++in;
      if ( v2 == 0 )
      {
        special[2] = v6;
        special[1] = v3;
        special[0] = v4;
        break;
      }
    }
  }
  for ( i = 0; i < 3; ++i )
  {
    if ( special[i] > 1 )
      return false;
  }
  if ( v4 != 0 && v3 != 0 )
    return false;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10184CA0
// Name: char const __near * Host_CleanupConVarStringValue(char const __near *)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl Host_CleanupConVarStringValue(const char *invalue)
{
  bool v1; // cc
  const char *result; // eax
  bool v3; // zf
  unsigned int v4; // eax
  char *v5; // eax

  V_snprintf(pDest: clean, maxLen: 256, pFormat: "%s", invalue);
  v1 = _V_strlen(str: clean) < 1;
  result = clean;
  if ( !v1 )
  {
    if ( AppearsNumeric(in: clean) )
    {
      v3 = _V_strstr(s1: clean, search: ".") == nullptr;
      result = clean;
      if ( v3 )
        return result;
      v4 = strlen(clean);
      v3 = byte_1066B1FF[v4] == 0;
      v5 = &byte_1066B1FF[v4];
      if ( !v3 )
      {
        while ( v5 >= clean )
        {
          if ( *v5 != 48 )
          {
            if ( *v5 == 46 )
              *v5 = v5 != clean ? 0 : 0x30;
            return clean;
          }
          *v5-- = 0;
          if ( *v5 == 0 )
            return clean;
        }
      }
    }
    return clean;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10184D50
// Name: int Host_CountVariablesWithFlags(int,bool)
// Source: json
//------------------------------------------------------------------------------
int __cdecl Host_CountVariablesWithFlags(int flags, bool nonDefault)
{
  int v2; // ebx
  ICvar::ICVarIteratorInternal *v3; // edi
  ConVar *v4; // esi
  const char *m_pszString; // eax
  const char *Default; // eax
  const char *v8; // [esp-8h] [ebp-10h]

  v2 = 0;
  v3 = g_pCVar->FactoryInternalIterator(this: g_pCVar);
  v3->SetFirst(this: v3);
  while ( v3->IsValid(this: v3) )
  {
    v4 = (ConVar *)v3->Get(this: v3);
    if ( !v4->IsCommand(this: v4) && v4->IsFlagSet(this: v4, a2: flags) )
    {
      if ( !nonDefault )
        goto LABEL_10;
      if ( (v4->m_nFlags & 0x1000) != 0 )
      {
        m_pszString = "FCVAR_NEVER_AS_STRING";
      }
      else
      {
        m_pszString = v4->m_pParent->m_Value.m_pszString;
        if ( m_pszString == nullptr )
          m_pszString = defaultValue;
      }
      v8 = m_pszString;
      Default = ConVar::GetDefault(this: v4);
      if ( V_strcasecmp(s1: Default, s2: v8) != 0 )
LABEL_10:
        ++v2;
    }
    v3->Next(this: v3);
  }
  free(pMem: v3);
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x10184E10
// Name: void Host_UpdateSounds(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Host_UpdateSounds()
{
  IMDLCache *v0; // esi

  v0 = g_pMDLCache;
  g_pMDLCache->BeginCoarseLock(this: g_pMDLCache);
  if ( GetBaseLocalClient()->m_nSignonState == 6 )
    S_Update(pAudioState: &s_AudioState);
  else
    S_Update(pAudioState: nullptr);
  v0->EndCoarseLock(this: v0);
}

//------------------------------------------------------------------------------
// Address: 0x10184E50
// Name: public: void CFrameTimer::MarkFrame(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFrameTimer::MarkFrame(CFrameTimer *this)
{
  long double v1; // st7
  long double v2; // st5
  long double v3; // st4
  long double v4; // st3
  long double v5; // st2
  long double v6; // st6
  long double v7; // rt1
  long double v8; // st3
  long double v9; // st4
  double v10; // st2
  int v11; // ecx
  int v12; // edi
  edict_t *edicts; // eax
  int num_edicts; // esi
  char sz[256]; // [esp+44h] [ebp-108h] BYREF
  float fs_exec; // [esp+144h] [ebp-8h]
  float fs_cldll; // [esp+148h] [ebp-4h]

  v1 = this->deltas[0] * 1000.0;
  v2 = this->deltas[1] * 1000.0;
  v3 = this->deltas[2] * 1000.0;
  v4 = this->deltas[3] * 1000.0;
  v5 = this->deltas[4] * 1000.0;
  fs_cldll = this->deltas[5] * 1000.0;
  v6 = v5;
  fs_exec = 1000.0 * this->deltas[6];
  v7 = v4;
  v8 = v3;
  v9 = v7;
  this->m_flLastServerTime = v8;
  this->deltas[0] = 0.0;
  this->deltas[1] = 0.0;
  this->deltas[2] = 0.0;
  this->deltas[3] = 0.0;
  this->deltas[4] = 0.0;
  this->deltas[5] = 0.0;
  this->deltas[6] = 0.0;
  if ( host_frametime >= 0.0001 )
    v10 = 1.0 / host_frametime;
  else
    v10 = 999.0;
  if ( host_speeds.m_pParent != nullptr && host_speeds.m_pParent->m_Value.m_nValue != 0 )
  {
    v11 = host_tickcount - last_host_tickcount;
    v12 = 0;
    last_host_tickcount = host_tickcount;
    if ( sv.num_edicts > 0 )
    {
      edicts = sv.edicts;
      num_edicts = sv.num_edicts;
      do
      {
        if ( (edicts->m_fStateFlags & 2) == 0 )
          ++v12;
        ++edicts;
        --num_edicts;
      }
      while ( num_edicts != 0 );
    }
    V_snprintf(
      pDest: sz,
      maxLen: 256,
      pFormat: "%3i fps -- inp(%3.1f) sv(%3.1f) cl(%3.1f) render(%3.1f) snd(%3.1f) cl_dll(%3.1f) exec(%3.1f) ents(%d) ticks(%d)",
      (int)v10,
      (double)v1,
      (double)v8,
      (double)v2,
      (double)v9,
      (double)v6,
      fs_cldll,
      fs_exec,
      v12,
      v11);
    if ( host_speeds.m_pParent != nullptr && host_speeds.m_pParent->m_Value.m_nValue >= 2 )
      Con_NPrintf(idx: 0, fmt: sz);
    else
      _ConDMsg(a1: "%s\n", sz);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10184FE0
// Name: private: void CFrameTimer::ComputeFrameVariability(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFrameTimer::ComputeFrameVariability(CFrameTimer *this)
{
  int m_nFrameTimeHistoryIndex; // edx
  int v2; // esi
  float v3; // xmm2_4
  int v4; // edx
  float v5; // xmm1_4
  float v6; // xmm2_4
  int v7; // edx
  float v8; // xmm1_4
  float v9; // xmm2_4
  int v10; // edx
  float v11; // xmm1_4
  float v12; // xmm2_4
  int v13; // edx
  float v14; // xmm1_4
  float v15; // xmm1_4
  float v16; // xmm2_4
  int v17; // edx
  float v18; // xmm1_4
  int v19; // eax
  long double v20; // st6
  long double v21; // st5
  double v22; // st4
  long double v23; // st4
  long double v24; // rt0
  long double v25; // st3
  float v26; // xmm1_4
  double v27; // st7
  long double v28; // st6
  int v29; // edi
  float *v30; // edx
  float *v31; // esi
  int v32; // ebx
  double v33; // st6
  float v34; // xmm2_4
  double v35; // st4
  double v36; // st4
  float v37; // xmm2_4
  double v38; // st4
  float v39; // xmm2_4
  double v40; // st4
  float v41; // xmm2_4
  double v42; // st4
  int v43; // esi
  double v44; // st6
  float v45; // xmm2_4
  double v46; // st4
  double v47; // st4
  float v48; // xmm2_4
  double v49; // st4
  float v50; // xmm2_4
  double v51; // st4
  float v52; // xmm2_4
  double v53; // st4
  int count; // [esp+8h] [ebp-Ch]
  float counta; // [esp+8h] [ebp-Ch]
  float flExpCurveArea; // [esp+Ch] [ebp-8h]
  float flAverageTime; // [esp+10h] [ebp-4h]

  this->m_pFrameTimeHistory[this->m_nFrameTimeHistoryIndex++] = this->frametime;
  if ( this->m_nFrameTimeHistoryIndex >= 50 )
    this->m_nFrameTimeHistoryIndex = 0;
  m_nFrameTimeHistoryIndex = this->m_nFrameTimeHistoryIndex;
  v2 = 0;
  v3 = 0.0;
  do
  {
    if ( v3 > 0.5 )
      break;
    v4 = m_nFrameTimeHistoryIndex - 1;
    if ( v4 < 0 )
      v4 = 49;
    v5 = this->m_pFrameTimeHistory[v4];
    if ( v5 == 0.0 )
      break;
    v6 = v5 + v3;
    if ( v6 > 0.5 )
      goto LABEL_26;
    v7 = v4 - 1;
    if ( v7 < 0 )
      v7 = 49;
    v8 = this->m_pFrameTimeHistory[v7];
    if ( v8 == 0.0 )
    {
LABEL_26:
      ++v2;
      break;
    }
    v9 = v8 + v6;
    if ( v9 > 0.5 )
      goto LABEL_27;
    v10 = v7 - 1;
    if ( v10 < 0 )
      v10 = 49;
    v11 = this->m_pFrameTimeHistory[v10];
    if ( v11 == 0.0 )
    {
LABEL_27:
      v2 += 2;
      break;
    }
    v12 = v11 + v9;
    if ( v12 > 0.5 )
      goto LABEL_28;
    v13 = v10 - 1;
    if ( v13 < 0 )
      v13 = 49;
    v14 = this->m_pFrameTimeHistory[v13];
    if ( v14 == 0.0 )
    {
LABEL_28:
      v2 += 3;
      break;
    }
    v15 = v14 + v12;
    if ( v15 > 0.5 )
      goto LABEL_29;
    m_nFrameTimeHistoryIndex = v13 - 1;
    if ( m_nFrameTimeHistoryIndex < 0 )
      m_nFrameTimeHistoryIndex = 49;
    v16 = this->m_pFrameTimeHistory[m_nFrameTimeHistoryIndex];
    if ( v16 == 0.0 )
    {
LABEL_29:
      v2 += 4;
      break;
    }
    v2 += 5;
    v3 = v16 + v15;
  }
  while ( v2 < 50 );
  if ( v2 != 0 )
  {
    v17 = 0;
    v18 = 0.0;
    v19 = this->m_nFrameTimeHistoryIndex;
    flExpCurveArea = 0.0;
    count = 0;
    if ( v2 > 0 )
    {
      v20 = 0.0;
      v21 = 0.0;
      do
      {
        if ( --v19 < 0 )
          v19 = 49;
        v22 = (double)count;
        count = ++v17;
        v23 = v22 * (float)(-2.0 / (float)v2) * 1.442695040888963407;
        v24 = rint(v23);
        v25 = __FSCALE__(__F2XM1__(v23 - v24) + 1.0, v24);
        v21 = v21 + v25;
        v20 = v20 + v25 * this->m_pFrameTimeHistory[v19];
      }
      while ( v17 < v2 );
      flAverageTime = v20;
      v18 = flAverageTime;
      flExpCurveArea = v21;
    }
    v26 = v18 / flExpCurveArea;
    counta = 0.0;
    if ( v26 != 0.0 )
      counta = 1.0 / v26;
    v27 = 0.0;
    if ( this->frametime == 0.0 )
      v28 = 0.0;
    else
      v28 = 1.0 / this->frametime;
    v29 = 0;
    v30 = &this->m_pFrameTimeHistory[1];
    this->m_flFPSVariability = fabs(v28 - counta);
    v31 = &this->m_pFrameTimeHistory[1];
    v32 = 10;
    v33 = 0.0;
    do
    {
      v34 = *(v31 - 1);
      if ( v34 != 0.0 )
      {
        if ( v34 >= 0.25 )
          v35 = 0.25;
        else
          v35 = *(v31 - 1);
        v33 = v33 + v35;
        ++v29;
      }
      if ( *v31 != 0.0 )
      {
        if ( *v31 >= 0.25 )
          v36 = 0.25;
        else
          v36 = *v31;
        v33 = v33 + v36;
        ++v29;
      }
      v37 = v31[1];
      if ( v37 != 0.0 )
      {
        if ( v37 >= 0.25 )
          v38 = 0.25;
        else
          v38 = v31[1];
        v33 = v33 + v38;
        ++v29;
      }
      v39 = v31[2];
      if ( v39 != 0.0 )
      {
        if ( v39 >= 0.25 )
          v40 = 0.25;
        else
          v40 = v31[2];
        v33 = v33 + v40;
        ++v29;
      }
      v41 = v31[3];
      if ( v41 != 0.0 )
      {
        if ( v41 >= 0.25 )
          v42 = 0.25;
        else
          v42 = v31[3];
        v33 = v33 + v42;
        ++v29;
      }
      v31 += 5;
      --v32;
    }
    while ( v32 != 0 );
    if ( v29 > 1 )
    {
      v43 = 10;
      v44 = v33 / (double)v29;
      do
      {
        v45 = *(v30 - 1);
        if ( v45 != 0.0 )
        {
          if ( v45 >= 0.25 )
            v46 = 0.25;
          else
            v46 = *(v30 - 1);
          v27 = v27 + (v46 - v44) * (v46 - v44);
        }
        if ( *v30 != 0.0 )
        {
          if ( *v30 >= 0.25 )
            v47 = 0.25;
          else
            v47 = *v30;
          v27 = v27 + (v47 - v44) * (v47 - v44);
        }
        v48 = v30[1];
        if ( v48 != 0.0 )
        {
          if ( v48 >= 0.25 )
            v49 = 0.25;
          else
            v49 = v30[1];
          v27 = v27 + (v49 - v44) * (v49 - v44);
        }
        v50 = v30[2];
        if ( v50 != 0.0 )
        {
          if ( v50 >= 0.25 )
            v51 = 0.25;
          else
            v51 = v30[2];
          v27 = v27 + (v51 - v44) * (v51 - v44);
        }
        v52 = v30[3];
        if ( v52 != 0.0 )
        {
          if ( v52 >= 0.25 )
            v53 = 0.25;
          else
            v53 = v30[3];
          v27 = v27 + (v53 - v44) * (v53 - v44);
        }
        v30 += 5;
        --v43;
      }
      while ( v43 != 0 );
      this->m_flFPSStdDeviationSeconds = sqrt(v27 / (double)(v29 - 1));
    }
  }
  else
  {
    this->m_flFPSVariability = 0.0;
    this->m_flFPSStdDeviationSeconds = 0.0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101853D0
// Name: bool Host_ShouldRun(void)
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
char __cdecl Host_ShouldRun()
{
  if ( singlestep.m_pParent == nullptr || singlestep.m_pParent->m_Value.m_nValue == 0 )
    return 1;
  if ( next.m_pParent != nullptr && next.m_pParent->m_Value.m_nValue != 0 )
  {
    if ( current_tick == host_tickcount - 1 )
      return 1;
    CLoaderMemAlloc::CrtIsValidPointer(this: (ConVar *)&next.IConVar, value: 0);
    return 0;
  }
  else
  {
    current_tick = host_tickcount;
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10185420
// Name: void _Host_RunFrame_Input(float,bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl _Host_RunFrame_Input(float accumulated_extra_samples, bool bFinalTick)
{
  int v2; // eax
  const char *v3; // eax
  const char *v4; // esi

  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "_Host_RunFrame_Input",
    a3: 0,
    a4: "Input",
    a5: false,
    a6: 4);
  if ( bFirstFrame )
  {
    bFirstFrame = false;
    v2 = _CommandLine();
    v3 = (const char *)(*(int (__thiscall **)(int, const char *, _DWORD))(*(_DWORD *)v2 + 32))(
                         a1: v2,
                         a2: "-testscript",
                         a3: 0);
    v4 = v3;
    if ( v3 != nullptr && !CTestScriptMgr::StartTestScript(this: &g_TestScriptMgr, pFilename: v3) )
      _Error(a1: "StartTestScript( %s ) failed.", v4);
    InitNetConsole();
    NET_InitPostFork();
  }
  g_HostTimes.starttime[0] = _Plat_FloatTime();
  ClientDLL_ProcessInput();
  g_HostTimes.starttime[6] = _Plat_FloatTime();
  Cbuf_Execute();
  g_HostTimes.deltas[6] = _Plat_FloatTime() - g_HostTimes.starttime[6] + g_HostTimes.deltas[6];
  CL_Move(accumulated_extra_samples, bFinalTick);
  g_HostTimes.deltas[0] = _Plat_FloatTime() - g_HostTimes.starttime[0] + g_HostTimes.deltas[0];
  CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
}

//------------------------------------------------------------------------------
// Address: 0x101855A0
// Name: float Host_GetSoundDuration(char const __near *)
// Source: json
//------------------------------------------------------------------------------
double __cdecl Host_GetSoundDuration(const char *pSample)
{
  CClientState *BaseLocalClient; // eax
  CClientState *v2; // esi
  int v3; // eax
  CSfxTable *Sound; // eax
  CSfxTable *v5; // esi

  BaseLocalClient = GetBaseLocalClient();
  v2 = BaseLocalClient;
  if ( BaseLocalClient->m_nSignonState < 2 )
    return SV_GetSoundDuration(pSample);
  v3 = CClientState::LookupSoundIndex(this: BaseLocalClient, name: pSample);
  if ( v3 < 0 )
    return SV_GetSoundDuration(pSample);
  Sound = CClientState::GetSound(this: v2, index: v3);
  v5 = Sound;
  if ( Sound != nullptr && (*((_BYTE *)Sound + 12) & 4) != 0 )
    DevMsg(a1: "    Reason for late load of '%s': Calling Host_GetSoundDuration().\n", pSample);
  return AudioSource_GetSoundDuration(pSfx: v5);
}

//------------------------------------------------------------------------------
// Address: 0x10185600
// Name: host_runofftime
// Source: json
//------------------------------------------------------------------------------
void __cdecl host_runofftime(const CCommand *args)
{
  long double v1; // st7
  float advanceTime; // [esp+10h] [ebp+8h]

  if ( args->m_nArgc == 2 )
  {
    if ( sv.m_State >= ss_active )
    {
      if ( sv.m_nMaxclients <= 1 )
      {
        v1 = atof(nptr: args->m_ppArgv[1]);
        if ( v1 > 0.0 )
        {
          advanceTime = v1;
          if ( advanceTime <= 900.0 )
          {
            ConMsg(a1: "Skipping ahead for %f seconds\n", (double)v1);
            SCR_UpdateScreen();
            SCR_UpdateScreen();
          }
          else
          {
            ConMsg(a1: "host_runofftime would run off %.2f minutes!!! ignoring\n", (double)(v1 * 0.016666668));
          }
        }
      }
      else
      {
        ConMsg(a1: "host_runofftime:  only valid in single player\n");
      }
    }
    else
    {
      ConMsg(a1: "host_runofftime:  must be running a server\n");
    }
  }
  else
  {
    ConMsg(a1: "Usage:  host_runofftime <seconds>\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x101856B0
// Name: void Host_ShowIPCCallCount(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Host_ShowIPCCallCount()
{
  unsigned int v0; // eax
  int v1; // eax
  unsigned int IPCCallCount; // eax
  double flCurTime; // [esp+14h] [ebp-18h]
  double flInterval; // [esp+1Ch] [ebp-10h]
  int tickCount; // [esp+28h] [ebp-4h]

  if ( host_ShowIPCCallCount.m_pParent != nullptr && host_ShowIPCCallCount.m_pParent->m_Value.m_nValue != 0 )
  {
    v0 = _S5_1;
    if ( (_S5_1 & 1) == 0 )
    {
      v0 = _S5_1 | 1;
      _S5_1 |= 1u;
      s_nLastTick = host_tickcount;
    }
    if ( (v0 & 2) == 0 )
    {
      _S5_1 = v0 | 2;
      s_nLastFrame = host_framecount;
    }
    flInterval = 0.0;
    tickCount = SLODWORD(host_ShowIPCCallCount.m_pParent->m_Value.m_fValue);
    if ( *(float *)&tickCount > 0.0 )
      flInterval = 1.0 / *(float *)&tickCount;
    flCurTime = _Plat_FloatTime();
    if ( flCurTime - s_flLastTime >= flInterval )
    {
      v1 = _SteamClient();
      if ( v1 != 0 )
        IPCCallCount = (*(int (__thiscall **)(int))(*(_DWORD *)v1 + 80))(a1: v1);
      else
        IPCCallCount = _SteamGameServer_GetIPCCallCount();
      if ( host_framecount != s_nLastFrame && host_tickcount != s_nLastTick )
      {
        _Msg(
          a1: "host_ShowIPCCallCount: %d IPC calls in the past [%d frames, %d ticks]  Avg: [%.2f/frame, %.2f/tick]\n",
          IPCCallCount,
          host_framecount - s_nLastFrame,
          host_tickcount - s_nLastTick,
          (double)IPCCallCount / (double)(host_framecount - s_nLastFrame),
          (double)IPCCallCount / (double)(host_tickcount - s_nLastTick));
        s_flLastTime = flCurTime;
        s_nLastTick = host_tickcount;
        s_nLastFrame = host_framecount;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101857E0
// Name: PrintHostFrameTimes
// Source: json
//------------------------------------------------------------------------------
void __cdecl PrintHostFrameTimes(int nNumTicks, float flHostRemainder, float flMinimumTickInterval)
{
  int v3; // eax
  int v4; // edx
  float v5; // xmm2_4
  float v6; // xmm0_4
  float *v7; // eax
  float v8; // xmm1_4
  float v9; // xmm2_4
  float v10; // xmm2_4
  float v11; // xmm1_4
  float v12; // xmm2_4
  float v13; // xmm1_4
  float v14; // xmm1_4
  float v15; // xmm2_4
  con_nprint_s printinfo; // [esp+18h] [ebp-20h] BYREF
  float flAvgFrameTime; // [esp+30h] [ebp-8h]
  float flMinFrameTime; // [esp+34h] [ebp-4h]

  v3 = nFrameIndex;
  flFrameTimes[nFrameIndex] = host_frametime;
  v4 = (v3 + 1) % 100;
  v5 = 0.0;
  v6 = 1.0;
  flMinFrameTime = 1.0;
  v7 = (float *)&unk_1066B31C;
  nFrameIndex = v4;
  do
  {
    v8 = *(v7 - 1);
    if ( v6 > v8 )
      v6 = *(v7 - 1);
    v9 = v5 + v8;
    if ( v6 > *v7 )
      v6 = *v7;
    v10 = v9 + *v7;
    v11 = v7[1];
    if ( v6 > v11 )
      v6 = v7[1];
    v12 = v10 + v11;
    v13 = v7[2];
    if ( v6 > v13 )
      v6 = v7[2];
    v14 = v13 + v12;
    v15 = v7[3];
    if ( v6 > v15 )
      v6 = v7[3];
    v7 += 5;
    v5 = v15 + v14;
  }
  while ( (int)v7 < (int)&flt_1066B4AC );
  printinfo.index = 1;
  printinfo.fixed_width_font = true;
  flMinFrameTime = v6;
  flAvgFrameTime = v5;
  printinfo.time_to_live = -1.0;
  printinfo.color[2] = 1.0;
  printinfo.color[1] = 1.0;
  printinfo.color[0] = 1.0;
  Con_NXPrintf(
    info: &printinfo,
    fmt: "ticks: %d, host_remainder: %f, host_frametime: %f, minimum interval: %f\n",
    nNumTicks,
    flHostRemainder,
    host_frametime,
    flMinimumTickInterval);
  printinfo.index = 2;
  Con_NXPrintf(
    info: &printinfo,
    fmt: "Running min frametime: %f, running avg frametime: %f\n",
    flMinFrameTime,
    flAvgFrameTime * 0.0099999998);
}

//------------------------------------------------------------------------------
// Address: 0x10185910
// Name: PrintFsStats
// Source: json
//------------------------------------------------------------------------------
void PrintFsStats()
{
  IIoStats *v0; // eax
  IIoStats *v1; // esi
  int v2; // edi
  int *v3; // edx
  int v4; // eax
  int v5; // esi
  int v6; // ecx
  int v7; // esi
  int v8; // ecx
  int v9; // esi
  int v10; // ecx
  int v11; // esi
  int v12; // ecx
  int v13; // esi
  int v14; // ecx
  int v15; // edi
  int j; // esi
  PrintFsStats::__l2::Mode v17; // eax
  __m128i v18; // xmm0
  float v19; // xmm0_4
  float v20; // xmm1_4
  __int32 v21; // eax
  int nMinStats[6]; // [esp+4h] [ebp-68h]
  int nAvgStats[6]; // [esp+1Ch] [ebp-50h]
  con_nprint_s printinfo; // [esp+34h] [ebp-38h] BYREF
  int nMaxStats[6]; // [esp+4Ch] [ebp-20h] BYREF
  int *v26; // [esp+64h] [ebp-8h]
  int i; // [esp+68h] [ebp-4h]

  v0 = g_pFileSystem->GetIoStats(this: g_pFileSystem);
  v1 = v0;
  if ( v0 != nullptr )
  {
    nStats[0][nFrameIndex_0] = v0->GetNumberOfFileSeeks(this: v0);
    dword_1066B640[nFrameIndex_0] = v1->GetTimeInFileSeek(this: v1);
    dword_1066B7D0[nFrameIndex_0] = v1->GetNumberOfFileReads(this: v1);
    dword_1066B960[nFrameIndex_0] = v1->GetTimeInFileReads(this: v1);
    dword_1066BAF0[nFrameIndex_0] = v1->GetFileReadTotalSize(this: v1);
    dword_1066BC80[nFrameIndex_0] = v1->GetNumberOfFileOpens(this: v1);
    v1->Reset(this: v1);
    v2 = 0;
    nFrameIndex_0 = (nFrameIndex_0 + 1) % 100;
    v3 = (int *)&unk_1066B4B4;
    v26 = (int *)&unk_1066B4B4;
    do
    {
      if ( nModes[v2] != SKIPPED )
      {
        nMinStats[v2] = 0x7FFFFFFF;
        v4 = nMinStats[v2];
        nAvgStats[v2] = 0;
        v5 = nAvgStats[v2];
        nMaxStats[v2] = 0x80000000;
        for ( i = 20; i != 0; --i )
        {
          v6 = *(v3 - 1);
          if ( v6 >= v4 )
          {
            if ( v6 > nMaxStats[v2] )
              nMaxStats[v2] = v6;
          }
          else
          {
            v4 = *(v3 - 1);
          }
          v7 = v6 + v5;
          v8 = *v3;
          if ( *v3 >= v4 )
          {
            if ( v8 > nMaxStats[v2] )
              nMaxStats[v2] = v8;
          }
          else
          {
            v4 = *v3;
          }
          v9 = v8 + v7;
          v10 = v3[1];
          if ( v10 >= v4 )
          {
            if ( v10 > nMaxStats[v2] )
              nMaxStats[v2] = v10;
          }
          else
          {
            v4 = v3[1];
          }
          v11 = v10 + v9;
          v12 = v3[2];
          if ( v12 >= v4 )
          {
            if ( v12 > nMaxStats[v2] )
              nMaxStats[v2] = v12;
          }
          else
          {
            v4 = v3[2];
          }
          v13 = v12 + v11;
          v14 = v3[3];
          if ( v14 >= v4 )
          {
            if ( v14 > nMaxStats[v2] )
              nMaxStats[v2] = v14;
          }
          else
          {
            v4 = v3[3];
          }
          v5 = v14 + v13;
          v3 += 5;
        }
        v3 = v26;
        nMinStats[v2] = v4;
        nAvgStats[v2] = v5;
      }
      v3 += 100;
      ++v2;
      v26 = v3;
    }
    while ( (int)v3 < (int)&s_HostSubscribeForProfileEvents );
    printinfo.time_to_live = -1.0;
    printinfo.index = 1;
    printinfo.color[2] = 1.0;
    printinfo.color[1] = 1.0;
    printinfo.color[0] = 1.0;
    printinfo.fixed_width_font = true;
    Con_NXPrintf(info: &printinfo, fmt: "IO stats from the last %d frames.\n", 100);
    v15 = 3;
    for ( j = 0; j < 6; ++j )
    {
      v17 = nModes[j];
      if ( v17 != SKIPPED )
      {
        v18 = _mm_cvtsi32_si128(nAvgStats[j]);
        printinfo.index = v15;
        v19 = _mm_cvtepi32_ps(v18).m128_f32[0] * 0.0099999998;
        ++v15;
        v20 = v19 * 30.0;
        if ( v17 != NORMAL )
        {
          v21 = v17 - 1;
          if ( v21 != 0 )
          {
            if ( v21 == 1 )
              Con_NXPrintf(
                info: &printinfo,
                fmt: "%s - Avg:%5d Kb - Max:%5d Kb -%5d Kb/s\n",
                pStatsTitle[j],
                (int)(float)(v19 * 0.0009765625),
                nMaxStats[j] / 1024,
                (int)(float)(v20 * 0.0009765625));
          }
          else
          {
            Con_NXPrintf(
              info: &printinfo,
              fmt: "%s - Avg:%5d ms - Max:%5d ms -%5d ms/s\n",
              pStatsTitle[j],
              (int)v19,
              nMaxStats[j],
              (int)v20);
          }
        }
        else
        {
          Con_NXPrintf(
            info: &printinfo,
            fmt: "%s - Avg:%5d    - Max:%5d    -%5d   /s\n",
            pStatsTitle[j],
            (int)v19,
            nMaxStats[j],
            (int)v20);
        }
      }
    }
    printinfo.index = v15;
    Con_NXPrintf(info: &printinfo, fmt: "Delay for choreo: %5d ms\n", (int)(float)(g_fDelayForChoreo * 1000.0));
  }
  else
  {
    nMaxStats[0] = 1;
    LOBYTE(nMaxStats[5]) = 1;
    nMaxStats[1] = -1082130432;
    nMaxStats[4] = 1065353216;
    nMaxStats[3] = 1065353216;
    nMaxStats[2] = 1065353216;
    Con_NXPrintf(info: (const con_nprint_s *)nMaxStats, fmt: "IO stats is disabled.\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x10185C40
// Name: bool IsLowViolence_Registry(void)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl IsLowViolence_Registry()
{
  int v0; // eax
  bool v1; // bl
  bool v2; // cc
  bool result; // al
  char gamedir[260]; // [esp+4h] [ebp-204h] BYREF
  char szSubKey[128]; // [esp+108h] [ebp-100h] BYREF
  char szBuffer[128]; // [esp+188h] [ebp-80h] BYREF

  memset(dst: (unsigned __int8 *)szBuffer, value: 0, count: sizeof(szBuffer));
  V_snprintf(pDest: szSubKey, maxLen: 128, pFormat: "Software\\Valve\\%s\\Settings", "Source");
  V_strncpy(pDest: szBuffer, pSrc: defaultValue, maxLen: 128);
  Sys_GetRegKeyValue(
    pszSubKey: szSubKey,
    pszElement: "User Token 2",
    pszReturnString: szBuffer,
    nReturnLength: 127,
    pszDefaultValue: szBuffer);
  v0 = _V_strlen(str: szBuffer);
  v1 = v0 > 0;
  if ( v0 <= 0 )
  {
    Sys_GetRegKeyValue(
      pszSubKey: szSubKey,
      pszElement: "User Token 3",
      pszReturnString: szBuffer,
      nReturnLength: 127,
      pszDefaultValue: szBuffer);
    v1 = _V_strlen(str: szBuffer) > 0;
  }
  V_FileBase(in: com_gamedir, out: gamedir, maxlen: 260);
  V_snprintf(pDest: szSubKey, maxLen: 128, pFormat: "Software\\Valve\\%s\\%s\\Settings", "Source", gamedir);
  V_strncpy(pDest: szBuffer, pSrc: defaultValue, maxLen: 128);
  Sys_GetRegKeyValue(
    pszSubKey: szSubKey,
    pszElement: "User Token 2",
    pszReturnString: szBuffer,
    nReturnLength: 127,
    pszDefaultValue: szBuffer);
  if ( _V_strlen(str: szBuffer) > 0 )
    v1 = true;
  Sys_GetRegKeyValue(
    pszSubKey: szSubKey,
    pszElement: "User Token 3",
    pszReturnString: szBuffer,
    nReturnLength: 127,
    pszDefaultValue: szBuffer);
  v2 = _V_strlen(str: szBuffer) <= 0;
  result = true;
  if ( v2 )
    return v1;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10185D90
// Name: void Host_CheckGore(void)
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __cdecl Host_CheckGore()
{
  int v0; // eax
  bool v1; // bl
  CSteam3Client *v2; // eax
  bool v3; // al
  bool bLowViolenceCommandLine; // [esp+7h] [ebp-1h]

  v0 = _CommandLine();
  bLowViolenceCommandLine = (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v0 + 40))(a1: v0, a2: "-lv") != 0;
  v1 = IsLowViolence_Registry();
  if ( Steam3Client()->m_pSteamApps != nullptr )
  {
    v2 = Steam3Client();
    v3 = v2->m_pSteamApps->BIsLowViolence(this: v2->m_pSteamApps);
  }
  else
  {
    v3 = false;
  }
  if ( v1 || v3 || bLowViolenceCommandLine )
  {
    g_bLowViolence = true;
    if ( v1 )
    {
      CLoaderMemAlloc::CrtIsValidPointer(this: (ConVar *)&violence_hblood.IConVar, value: 0);
      CLoaderMemAlloc::CrtIsValidPointer(this: (ConVar *)&violence_hgibs.IConVar, value: 0);
      CLoaderMemAlloc::CrtIsValidPointer(this: (ConVar *)&violence_ablood.IConVar, value: 0);
      CLoaderMemAlloc::CrtIsValidPointer(this: (ConVar *)&violence_agibs.IConVar, value: 0);
    }
  }
  else
  {
    g_bLowViolence = false;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10185E30
// Name: void Host_InitProcessor(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Host_InitProcessor()
{
  int CPUInformation; // eax
  _BYTE *v1; // esi
  const char *v2; // edi
  vgui::Splitter *v3; // ecx
  char v4; // bl
  unsigned __int8 v5; // al
  char buffer[256]; // [esp+1Ch] [ebp-208h] BYREF
  char szFeatureString[256]; // [esp+11Ch] [ebp-108h] BYREF
  double fFrequency; // [esp+21Ch] [ebp-8h]

  CPUInformation = _GetCPUInformation();
  v1 = (_BYTE *)CPUInformation;
  v2 = "Mhz";
  fFrequency = (double)*(__int64 *)(CPUInformation + 8) * 0.000001;
  if ( fFrequency > 1000.0 )
  {
    v2 = "Ghz";
    fFrequency = fFrequency * 0.001;
  }
  V_strncpy(pDest: szFeatureString, pSrc: *(const char **)(CPUInformation + 16), maxLen: 256);
  V_strncat(pDest: szFeatureString, pSrc: " ", destBufferSize: 0x100u, max_chars_to_copy: -1);
  if ( (v1[4] & 8) != 0 )
  {
    if ( CBaseServer::ShouldUpdateMasterServer(this: v3) )
      V_strncat(pDest: szFeatureString, pSrc: "SSE ", destBufferSize: 0x100u, max_chars_to_copy: -1);
    else
      V_strncat(pDest: szFeatureString, pSrc: "(SSE) ", destBufferSize: 0x100u, max_chars_to_copy: -1);
  }
  if ( (v1[4] & 0x10) != 0 )
  {
    if ( CBaseServer::ShouldUpdateMasterServer(this: v3) )
      V_strncat(pDest: szFeatureString, pSrc: "SSE2 ", destBufferSize: 0x100u, max_chars_to_copy: -1);
    else
      V_strncat(pDest: szFeatureString, pSrc: "(SSE2) ", destBufferSize: 0x100u, max_chars_to_copy: -1);
  }
  if ( (v1[4] & 0x40) != 0 )
  {
    if ( CBaseServer::ShouldUpdateMasterServer(this: v3) )
      V_strncat(pDest: szFeatureString, pSrc: "MMX ", destBufferSize: 0x100u, max_chars_to_copy: -1);
    else
      V_strncat(pDest: szFeatureString, pSrc: "(MMX) ", destBufferSize: 0x100u, max_chars_to_copy: -1);
  }
  if ( (v1[4] & 1) != 0 )
    V_strncat(pDest: szFeatureString, pSrc: "RDTSC ", destBufferSize: 0x100u, max_chars_to_copy: -1);
  if ( (v1[4] & 2) != 0 )
    V_strncat(pDest: szFeatureString, pSrc: "CMOV ", destBufferSize: 0x100u, max_chars_to_copy: -1);
  if ( (v1[4] & 4) != 0 )
    V_strncat(pDest: szFeatureString, pSrc: "FCMOV ", destBufferSize: 0x100u, max_chars_to_copy: -1);
  buffer[_V_strlen(str: szFeatureString) + 255] = 0;
  v4 = v1[5];
  if ( v4 == 1 )
  {
    _ConDMsg(a1: "1 CPU, Frequency: %.01f %s,  Features: %s\n", fFrequency, v2, szFeatureString);
  }
  else
  {
    memset(buffer, 0, sizeof(buffer));
    v5 = v1[6];
    if ( v5 != v4 )
      V_snprintf(pDest: buffer, maxLen: 256, pFormat: " (%i physical)", v5);
    _ConDMsg(
      a1: "%i CPUs%s, Frequency: %.01f %s,  Features: %s\n",
      (unsigned __int8)v1[5],
      buffer,
      fFrequency,
      v2,
      szFeatureString);
  }
  if ( s_bInitPME )
    _InitPME();
}

//------------------------------------------------------------------------------
// Address: 0x10186080
// Name: int Host_GetServerCount(void)
// Source: json
//------------------------------------------------------------------------------
int __cdecl Host_GetServerCount()
{
  if ( GetBaseLocalClient()->m_nSignonState >= 3
    || GetBaseLocalClient()->m_nSignonState >= 2 && GetBaseLocalClient()->m_bServerInfoProcessed )
  {
    return GetBaseLocalClient()->m_nServerCount;
  }
  if ( sv.m_State < ss_loading )
    return gHostSpawnCount;
  return sv.m_nSpawnCount;
}

//------------------------------------------------------------------------------
// Address: 0x101860D0
// Name: void Host_PostInit(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Host_PostInit()
{
  IEngineVGuiInternal *v0; // eax

  if ( serverGameDLL != nullptr )
    serverGameDLL->PostInit(this: serverGameDLL);
  if ( g_ClientDLL != nullptr )
    g_ClientDLL->PostInit(this: g_ClientDLL);
  toolframework->PostInit(this: toolframework);
  if ( !sv.m_bIsDedicated )
  {
    v0 = EngineVGui();
    v0->PostInit(this: v0);
  }
  if ( serverGameDLL != nullptr )
    serverGameDLL->PostToolsInit(this: serverGameDLL);
}

//------------------------------------------------------------------------------
// Address: 0x10186130
// Name: void GetPlatformMapPath(char const __near *,char __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GetPlatformMapPath(const char *pMapPath, char *pPlatformMapPath, int maxLength)
{
  V_strncpy(pDest: pPlatformMapPath, pSrc: pMapPath, maxLen: maxLength);
  if ( g_pMaterialSystemHardwareConfig != nullptr )
  {
    V_StripExtension(in: pMapPath, out: pPlatformMapPath, outSize: maxLength);
    V_strncat(pDest: pPlatformMapPath, pSrc: ".bsp", destBufferSize: maxLength, max_chars_to_copy: -1);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10186180
// Name: void Host_FreeStateAndWorld(bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Host_FreeStateAndWorld(bool server)
{
  if ( server )
  {
    if ( !sv.m_bIsDedicated )
      CL_ClearState();
  }
  else if ( sv.m_State >= ss_active )
  {
    return;
  }
  if ( host_state.worldmodel != nullptr )
  {
    modelloader->UnreferenceModel(this: modelloader, a2: host_state.worldmodel, a3: FMODELLOADER_SERVER);
    modelloader->UnreferenceModel(this: modelloader, a2: host_state.worldmodel, a3: FMODELLOADER_CLIENT);
    if ( host_state.worldmodel != nullptr )
    {
      host_state.worldmodel = nullptr;
      host_state.worldbrush = nullptr;
    }
  }
  modelloader->UnloadUnreferencedModels(this: modelloader);
  g_TimeLastMemTest = 0.0;
}

//------------------------------------------------------------------------------
// Address: 0x10186210
// Name: void Host_FreeToLowMark(bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Host_FreeToLowMark(bool server)
{
  if ( server || sv.m_State <= ss_dead )
  {
    CM_FreeMap();
    if ( host_hunklevel != 0 )
      Hunk_FreeToLowMark(mark: host_hunklevel);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10186250
// Name: bool Host_AllowQueuedMaterialSystem(bool)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl Host_AllowQueuedMaterialSystem(BOOL bAllow)
{
  g_bAllowThreadedSound = bAllow;
  return g_pMaterialSystem->AllowThreading(this: g_pMaterialSystem, a2: bAllow, a3: g_nMaterialSystemThread);
}

//------------------------------------------------------------------------------
// Address: 0x10186280
// Name: void Host_EnsureHostNameSet(void)
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __cdecl Host_EnsureHostNameSet()
{
  char *m_pszString; // eax
  CSteam3Client *v1; // eax
  CSteam3Client *v2; // eax
  const char *v3; // eax

  if ( (host_name.m_nFlags & 0x1000) == 0 )
  {
    m_pszString = host_name.m_pParent->m_Value.m_pszString;
    if ( m_pszString == nullptr || *m_pszString == 0 )
    {
      if ( sv.m_bIsDedicated
        || Steam3Client()->m_pSteamUser == nullptr
        || (v1 = Steam3Client(), !v1->m_pSteamUser->BLoggedOn(this: v1->m_pSteamUser))
        || (v2 = Steam3Client(), *(v3 = v2->m_pSteamFriends->GetPersonaName(this: v2->m_pSteamFriends)) == 0) )
      {
        v3 = serverGameDLL->GetGameDescription(this: serverGameDLL);
      }
      CLoaderMemAlloc::CrtSetReportMode(this: (ConVar *)&host_name.IConVar, value: v3);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101862F0
// Name: public: bool CJob::WaitForFinishAndRelease(unsigned int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CJob::WaitForFinishAndRelease(CJob *this, unsigned int dwTimeout)
{
  int m_status; // eax
  bool v5; // bl
  CJob *v6; // [esp+4h] [ebp-4h] BYREF

  if ( this == nullptr )
    return 1;
  m_status = this->m_status;
  if ( m_status == 1 || m_status == 2 || m_status == 4 )
  {
    v6 = this;
    v5 = _g_pThreadPool->YieldWait(this: _g_pThreadPool, a2: &v6, a3: 1, a4: true, a5: dwTimeout) != 258;
    this->Release(this);
    return v5;
  }
  else
  {
    this->Release(this);
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10186370
// Name: public: int CJob::Execute(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CJob::Execute(CJob *this)
{
  int result; // eax
  CThreadFastMutex *p_m_mutex; // edi
  DWORD CurrentThreadId; // ecx
  int (__thiscall *DoExecute)(CJob *); // edx
  int v6; // eax
  int m_status; // ebx

  result = this->m_status;
  if ( result == 1 || result == 2 || result == 4 )
  {
    p_m_mutex = &this->m_mutex;
    CurrentThreadId = GetCurrentThreadId();
    if ( CurrentThreadId != p_m_mutex->m_ownerID
      && _InterlockedCompareExchange((volatile signed __int32 *)p_m_mutex, CurrentThreadId, 0) != 0 )
    {
      _mm_pause();
      CThreadFastMutex::Lock(a1: &this->m_mutex, a2: CurrentThreadId, a3: 0);
    }
    else
    {
      ++this->m_mutex.m_depth;
    }
    this->AddRef(this);
    switch ( this->m_status )
    {
      case 1:
      case 4:
        DoExecute = this->DoExecute;
        this->m_status = 2;
        v6 = DoExecute(this);
        this->m_status = v6;
        m_status = v6;
        this->DoCleanup(this);
        CThreadEvent::Set(this: &this->m_CompleteEvent);
        break;
      default:
        m_status = this->m_status;
        break;
    }
    this->Release(this);
    if ( this->m_mutex.m_depth-- == 1 )
      _InterlockedExchange((volatile __int32 *)p_m_mutex, 0);
    return m_status;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10186440
// Name: public: CVProfSpikeDetector::~CVProfSpikeDetector(void)
// Source: json
//------------------------------------------------------------------------------
// write access to const memory has been detected, the output may be wrong!
void __thiscall CVProfSpikeDetector::~CVProfSpikeDetector(CVProfSpikeDetector *this)
{
  unsigned int m_Int64_high; // ecx
  unsigned int v3; // kr00_4
  unsigned __int64 v4; // [esp+4h] [ebp-Ch] BYREF
  unsigned __int64 *v5; // [esp+Ch] [ebp-4h]

  v5 = &v4;
  v4 = __rdtsc();
  this->m_Timer.m_Duration.m_Int64 = v4 - this->m_Timer.m_Duration.m_Int64;
  if ( _Plat_FloatTime() - *this->m_timeLast > 2.0 )
  {
    *this->m_timeLast = _Plat_FloatTime();
    m_Int64_high = HIDWORD(this->m_Timer.m_Duration.m_Int64);
    LODWORD(v4) = this->m_Timer.m_Duration.m_Int64;
    v3 = v4;
    HIDWORD(v4) = m_Int64_high & 0x80000000;
    LODWORD(v4) = 0;
    if ( (double)__PAIR64__(m_Int64_high, v3) * _g_ClockSpeedMillisecondsMultiplier > this->m_spike )
      _g_VProfSignalSpike = true;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101864F0
// Name: MemTest
// Source: json
//------------------------------------------------------------------------------
bool __cdecl MemTest()
{
  char *m_szMapname; // eax
  bool v1; // bl
  bool verbose; // [esp+Bh] [ebp-1h]

  if ( mem_test_quiet.m_pParent != nullptr && mem_test_quiet.m_pParent->m_Value.m_nValue != 0
    || mem_test_each_frame.m_pParent != nullptr && mem_test_each_frame.m_pParent->m_Value.m_nValue != 0 )
  {
    verbose = false;
  }
  else
  {
    verbose = true;
    _Msg(a1: "\nBegin mem_test\n");
    m_szMapname = sv.m_szMapname;
    if ( sv.m_szMapname[0] == 0 )
      m_szMapname = "nomap";
    V_FileBase(in: m_szMapname, out: mapname, maxlen: 256);
    Host_PrintMemoryStatus(mapname: mapname);
  }
  v1 = _g_pMemAlloc->CrtCheckMemory(this: _g_pMemAlloc) != 0;
  if ( verbose )
    _Msg(a1: "\nEnd mem_test\n");
  return v1;
}

//------------------------------------------------------------------------------
// Address: 0x10186590
// Name: mem_test
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __cdecl mem_test()
{
  MemTest();
}

//------------------------------------------------------------------------------
// Address: 0x101865A0
// Name: void OnChangeThreadAffinity(class IConVar __near *,char const __near *,float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl OnChangeThreadAffinity()
{
  int m_nValue; // eax

  if ( _g_pThreadPool->NumThreads(this: _g_pThreadPool) != 0 )
  {
    if ( threadpool_affinity.m_pParent != nullptr )
      m_nValue = threadpool_affinity.m_pParent->m_Value.m_nValue;
    else
      m_nValue = 0;
    _g_pThreadPool->Distribute(this: _g_pThreadPool, a2: m_nValue != 0, a3: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101865E0
// Name: void ThreadPoolReserverFunction(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ThreadPoolReserverFunction()
{
  CThreadEvent::Wait(this: &g_ReleaseThreadReservation, a2: 0xFFFFFFFF);
  _InterlockedExchangeAdd(&g_NumReservedThreads.m_value, 0xFFFFFFFF);
}

//------------------------------------------------------------------------------
// Address: 0x10186600
// Name: public: bool CAudioState::IsAnyPlayerUnderwater(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CAudioState::IsAnyPlayerUnderwater(CAudioState *this)
{
  int v1; // esi
  bool result; // al

  v1 = 0;
  result = CAudioState::GetPerUser(this, nSlot: -1)->m_PerUser[0].m_bIsUnderwater;
  while ( !result )
  {
    if ( ++v1 != 0 )
      return result;
  }
  return true;
}

//------------------------------------------------------------------------------
// Address: 0x10186620
// Name: void Host_SubscribeForProfileEvents(bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Host_SubscribeForProfileEvents(bool bSubscribe)
{
  int v1; // eax

  if ( (_S3_4 & 1) == 0 )
  {
    _S3_4 |= 1u;
    s_HostSubscribeForProfileEvents.__vftable = (CHostSubscribeForProfileEvents_vtbl *)&CHostSubscribeForProfileEvents::`vftable';
    s_HostSubscribeForProfileEvents.m_bSubscribed = false;
  }
  if ( bSubscribe != s_HostSubscribeForProfileEvents.m_bSubscribed && g_pMatchFramework != nullptr )
  {
    v1 = ((int (*)(void))g_pMatchFramework->GetEventsSubscription)();
    if ( bSubscribe )
    {
      (**(void (__thiscall ***)(int, CHostSubscribeForProfileEvents *))v1)(a1: v1, a2: &s_HostSubscribeForProfileEvents);
      s_HostSubscribeForProfileEvents.m_bSubscribed = bSubscribe;
    }
    else
    {
      (*(void (__thiscall **)(int, CHostSubscribeForProfileEvents *))(*(_DWORD *)v1 + 4))(
        a1: v1,
        a2: &s_HostSubscribeForProfileEvents);
      s_HostSubscribeForProfileEvents.m_bSubscribed = false;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101866A0
// Name: void Host_ResetConfiguration(int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Host_ResetConfiguration(int iController)
{
  vgui::CTreeViewListControl *v1; // ecx
  ECommandTarget_t TraceType; // eax
  IGameEvent *v3; // esi

  TraceType = CTraceFilter::GetTraceType(this: v1);
  Cbuf_AddText(eTarget: TraceType, pText: "exec config.cfg game\n", nTickDelay: 0);
  Cbuf_Execute();
  v3 = g_GameEventManager->CreateEventA(this: g_GameEventManager, a2: "reset_game_titledata", a3: 0, a4: 0);
  if ( v3 != nullptr )
  {
    v3->SetInt(this: v3, a2: "controllerId", a3: iController);
    g_GameEventManager->FireEventClientSide(this: g_GameEventManager, a2: v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10186700
// Name: host_reset_config
// Source: json
//------------------------------------------------------------------------------
void __cdecl host_reset_config(const CCommand *args)
{
  int m_nArgc; // eax
  int v2; // eax

  m_nArgc = args->m_nArgc;
  if ( args->m_nArgc <= 1 || m_nArgc > 2 )
  {
    ConMsg(a1: "Usage:  host_reset_config <controller index>\n");
  }
  else if ( m_nArgc == 2 )
  {
    v2 = atoi(nptr: args->m_ppArgv[1]);
    Host_ResetConfiguration(iController: v2);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10186740
// Name: void Host_ShutdownServer(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall Host_ShutdownServer(int a1@<esi>)
{
  IGameEvent *v1; // esi
  IStaticPropMgrEngine *v2; // eax
  IGameEvent *v3; // esi

  if ( sv.m_State >= ss_active )
  {
    v1 = (IGameEvent *)((int (__thiscall *)(CGameEventManager *, const char *, _DWORD, _DWORD, int))g_GameEventManager->CreateEventA)(
                         a1: g_GameEventManager,
                         a2: "server_pre_shutdown",
                         a3: 0,
                         a4: 0,
                         a5: a1);
    if ( v1 != nullptr )
    {
      v1->SetString(this: v1, a2: "reason", a3: "restart");
      g_GameEventManager->FireEvent(this: g_GameEventManager, a2: v1, a3: false);
    }
    g_pShadowMgr->LevelShutdown(this: g_pShadowMgr);
    v2 = StaticPropMgr();
    v2->LevelShutdown(this: v2);
    if ( !sv.m_bIsDedicated )
      CL_ClearState();
    if ( host_state.worldmodel != nullptr )
    {
      modelloader->UnreferenceModel(this: modelloader, a2: host_state.worldmodel, a3: FMODELLOADER_SERVER);
      modelloader->UnreferenceModel(this: modelloader, a2: host_state.worldmodel, a3: FMODELLOADER_CLIENT);
      if ( host_state.worldmodel != nullptr )
      {
        host_state.worldmodel = nullptr;
        host_state.worldbrush = nullptr;
      }
    }
    modelloader->UnloadUnreferencedModels(this: modelloader);
    g_TimeLastMemTest = 0.0;
    CGameServer::Shutdown(this: &sv);
    CM_FreeMap();
    if ( host_hunklevel != 0 )
      Hunk_FreeToLowMark(mark: host_hunklevel);
    v3 = (IGameEvent *)((int (__thiscall *)(CGameEventManager *, const char *, _DWORD))g_GameEventManager->CreateEventA)(
                         a1: g_GameEventManager,
                         a2: "server_shutdown",
                         a3: 0);
    if ( v3 != nullptr )
    {
      v3->SetString(this: v3, a2: "reason", a3: "restart");
      g_GameEventManager->FireEvent(this: g_GameEventManager, a2: v3, a3: false);
    }
    CLog::Close(this: &g_Log);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10186890
// Name: void Host_AccumulateTime(float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Host_AccumulateTime(float dt)
{
  bool v1; // bl
  float interval_per_tick; // xmm0_4
  float m_fValue; // xmm1_4
  float v4; // xmm0_4
  long double v5; // st7
  int v6; // eax
  double v7; // st5
  double v8; // st7
  double v9; // st7
  double v10; // st5
  double v11; // st7
  double v12; // st6
  int v13; // eax
  double v14; // st7
  double v15; // st6
  double v16; // st7
  CClientState *BaseLocalClient; // eax
  double v18; // st7
  double v19; // st6
  double v20; // rt0
  double v21; // st6
  double v22; // st7
  float inputFrameTime; // [esp+Ch] [ebp-8h]
  float fps; // [esp+10h] [ebp-4h]
  float fpsa; // [esp+10h] [ebp-4h]

  realtime = realtime + dt;
  v1 = !demoplayer->IsPlayingTimeDemo(this: demoplayer);
  if ( g_bDedicatedServerBenchmarkMode || !v1 )
    interval_per_tick = host_state.interval_per_tick;
  else
    interval_per_tick = dt;
  m_fValue = 1.0;
  host_frametime = interval_per_tick;
  if ( host_timescale.m_pParent->m_Value.m_fValue > 0.0 )
  {
    if ( sv_cheats.m_pParent != nullptr && sv_cheats.m_pParent->m_Value.m_nValue != 0 || Cmd_IsRptActive() )
      m_fValue = host_timescale.m_pParent->m_Value.m_fValue;
    else
      m_fValue = 1.0;
  }
  fps = sv.m_flTimescale * m_fValue;
  if ( demoplayer->IsPlayingBack(this: demoplayer) )
    fps = ((double (__thiscall *)(IDemoPlayer *))demoplayer->GetPlaybackTimeScale)(a1: demoplayer) * fps;
  if ( host_framerate.m_pParent->m_Value.m_fValue != 0.0
    && (sv_cheats.m_pParent != nullptr && sv_cheats.m_pParent->m_Value.m_nValue != 0
     || Cmd_IsRptActive()
     || demoplayer->IsPlayingBack(this: demoplayer)) )
  {
    v4 = host_framerate.m_pParent->m_Value.m_fValue;
    if ( v4 <= 1.0 )
    {
      if ( v4 < -1.0 )
      {
        v5 = 1.0 / fabs(host_framerate.m_pParent->m_Value.m_fValue);
        if ( v5 <= dt )
        {
          fpsa = v5;
          v4 = fpsa;
        }
        else
        {
          v4 = dt;
        }
      }
    }
    else
    {
      v4 = 1.0 / v4;
    }
    host_frametime = v4;
    host_frametime_unbounded = v4;
    host_frametime_unscaled = v4;
  }
  else if ( fps == 1.0 )
  {
    v13 = _CommandLine();
    if ( (*(int (__thiscall **)(int, const char *, _DWORD))(*(_DWORD *)v13 + 12))(a1: v13, a2: "-tools", a3: 0) == 0
      || g_bReplayLoadedTools )
    {
      v14 = host_frametime;
      host_frametime_unbounded = host_frametime;
      if ( host_frametime >= 0.1 )
        v14 = 0.1;
    }
    else
    {
      host_frametime_unbounded = host_frametime;
      if ( host_frametime >= 2.0 )
        v14 = 2.0;
      else
        v14 = host_frametime;
    }
    v15 = v14;
    v16 = 0.001;
    if ( v15 > 0.001 )
      v16 = v15;
    host_frametime = v16;
    host_frametime_unscaled = v16;
  }
  else
  {
    host_frametime_unscaled = host_frametime;
    host_frametime = host_frametime * fps;
    host_frametime_unbounded = host_frametime;
    v6 = _CommandLine();
    if ( (*(int (__thiscall **)(int, const char *, _DWORD))(*(_DWORD *)v6 + 12))(a1: v6, a2: "-tools", a3: 0) != 0
      || g_bReplayLoadedTools )
    {
      v10 = fps * 2.0;
      v11 = host_frametime;
      if ( v10 <= host_frametime )
        v11 = v10;
      v12 = v11;
      v9 = 2.0;
      host_frametime = v12;
      if ( host_frametime_unscaled < 2.0 )
        v9 = host_frametime_unscaled;
    }
    else
    {
      v7 = fps * 0.1;
      v8 = host_frametime;
      if ( v7 <= host_frametime )
        v8 = v7;
      host_frametime = v8;
      v9 = host_frametime_unscaled;
      if ( host_frametime_unscaled >= 0.1 )
        v9 = 0.1;
    }
    if ( v9 <= 0.001 )
      host_frametime_unscaled = 0.001;
    else
      host_frametime_unscaled = v9;
  }
  BaseLocalClient = GetBaseLocalClient();
  v18 = CClockDriftMgr::AdjustFrameTime(this: &BaseLocalClient->m_ClockDriftMgr, inputFrameTime: host_frametime)
      - host_frametime;
  v19 = host_frametime + v18;
  host_frametime = v19;
  host_frametime_unbounded = host_frametime_unbounded + v18;
  v20 = v19;
  v21 = v18 + host_frametime_unscaled;
  v22 = v20;
  host_frametime_unscaled = v21;
  if ( g_pSoundServices != nullptr )
  {
    inputFrameTime = v22;
    ((void (__thiscall *)(ISoundServices *, _DWORD, _DWORD))g_pSoundServices->SetSoundFrametime)(
      a1: g_pSoundServices,
      a2: LODWORD(dt),
      a3: LODWORD(inputFrameTime));
  }
}

//------------------------------------------------------------------------------
// Address: 0x10186C20
// Name: void CL_SendVoicePacket(bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CL_SendVoicePacket(bool bFinal)
{
  int v1; // eax
  CClientState *BaseLocalClient; // eax
  char uchVoiceData[2048]; // [esp+0h] [ebp-858h] BYREF
  CLC_VoiceData voiceMsg; // [esp+800h] [ebp-58h] BYREF

  if ( Voice_IsRecording() )
  {
    voiceMsg.m_NetChannel = nullptr;
    voiceMsg.__vftable = (CLC_VoiceData_vtbl *)&CLC_VoiceData::`vftable';
    voiceMsg.m_DataIn.m_bOverflow = false;
    voiceMsg.m_DataIn.m_pDebugName = nullptr;
    voiceMsg.m_DataIn.m_nDataBits = -1;
    voiceMsg.m_DataIn.m_nDataBytes = 0;
    bf_write::bf_write(this: &voiceMsg.m_DataOut);
    voiceMsg.m_bReliable = false;
    voiceMsg.m_xuid = 0;
    bf_write::StartWriting(this: &voiceMsg.m_DataOut, pData: uchVoiceData, nBytes: 2048, iStartBit: 0, nBits: -1);
    v1 = 8 * Voice_GetCompressedData(pchDest: uchVoiceData, nCount: 2048, bFinal);
    voiceMsg.m_nLength = v1;
    if ( v1 != 0 )
    {
      CEngine::SetNextState(this: &voiceMsg.m_DataOut, bitPos: v1);
      if ( GetBaseLocalClient()->m_nSignonState == 6 )
      {
        BaseLocalClient = GetBaseLocalClient();
        BaseLocalClient->m_NetChannel->SendNetMsg(
          this: BaseLocalClient->m_NetChannel,
          a2: &voiceMsg,
          a3: false,
          a4: false);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10186CE0
// Name: void Host_CheckDumpMemoryStats(void)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __cdecl Host_CheckDumpMemoryStats()
{
  int v0; // eax
  char *m_szMapname; // eax
  int m_nValue; // eax
  unsigned int v3; // esi
  const char *v4; // eax
  const char *v5; // eax
  const char *v6; // eax
  float value; // [esp+0h] [ebp-4Ch]
  float valuea; // [esp+0h] [ebp-4Ch]
  float valueb; // [esp+0h] [ebp-4Ch]
  _CrtMemState state; // [esp+10h] [ebp-3Ch] BYREF
  double v11; // [esp+44h] [ebp-8h] OVERLAPPED

  if ( mem_test_each_frame.m_pParent != nullptr && mem_test_each_frame.m_pParent->m_Value.m_nValue != 0 )
  {
    if ( !MemTest() )
    {
      if ( (unsigned __int8)_Plat_IsInDebugSession() != 0 )
        goto LABEL_14;
      goto LABEL_15;
    }
  }
  else if ( mem_test_every_n_seconds.m_pParent != nullptr && mem_test_every_n_seconds.m_pParent->m_Value.m_nValue > 0 )
  {
    *((float *)&v11 + 1) = _Plat_FloatTime();
    v0 = mem_test_every_n_seconds.m_pParent != nullptr ? mem_test_every_n_seconds.m_pParent->m_Value.m_nValue : 0;
    if ( (float)(*((float *)&v11 + 1) - g_TimeLastMemTest) > (float)v0 )
    {
      g_TimeLastMemTest = *((float *)&v11 + 1);
      if ( !MemTest() )
      {
        if ( (unsigned __int8)_Plat_IsInDebugSession() != 0 )
LABEL_14:
          __debugbreak();
LABEL_15:
        _Error(a1: "Heap is corrupt\n");
      }
    }
  }
  if ( mem_periodicdumps.m_pParent->m_Value.m_fValue > 0.0 )
  {
    v11 = _Plat_FloatTime();
    if ( v11 - g_flLastPeriodicMemDump > mem_periodicdumps.m_pParent->m_Value.m_fValue )
    {
      m_szMapname = sv.m_szMapname;
      if ( sv.m_szMapname[0] == 0 )
        m_szMapname = "nomap";
      V_FileBase(in: m_szMapname, out: mapname, maxlen: 256);
      Host_PrintMemoryStatus(mapname: mapname);
      _g_pMemAlloc->DumpStatsFileBase(this: _g_pMemAlloc, a2: mapname);
      g_flLastPeriodicMemDump = v11;
    }
  }
  if ( mem_dumpstats.m_pParent != nullptr )
  {
    m_nValue = mem_dumpstats.m_pParent->m_Value.m_nValue;
    if ( m_nValue > 0 )
    {
      if ( m_nValue == 1 )
        CLoaderMemAlloc::CrtIsValidPointer(this: (ConVar *)&mem_dumpstats.IConVar, value: 0);
      _V_memset(dest: &state, fill: 0, count: 52);
      v3 = state.lSizes[4] + state.lSizes[3] + state.lSizes[2] + state.lSizes[0] + state.lSizes[1];
      _Msg(a1: "MEMORY:  Run-time Heap\n------------------------------------\n");
      value = (float)state.lHighWaterCount;
      v4 = V_pretifymem(value, digitsafterdecimal: 4, usebinaryonek: false);
      _Msg(a1: "\tHigh water %s\n", v4);
      HIDWORD(v11) = v3;
      valuea = (float)v3;
      v5 = V_pretifymem(value: valuea, digitsafterdecimal: 4, usebinaryonek: false);
      _Msg(a1: "\tCurrent mem %s\n", v5);
      _Msg(a1: "------------------------------------\n");
      HIDWORD(v11) = v3 - Hunk_MallocSize();
      valueb = (float)HIDWORD(v11);
      v6 = V_pretifymem(value: valueb, digitsafterdecimal: 2, usebinaryonek: false);
      _Msg(a1: "\tAllocated outside hunk:  %s\n", v6);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10186EE0
// Name: void _Host_SetGlobalTime(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl _Host_SetGlobalTime()
{
  int m_nServerCount; // eax

  g_ServerGlobalVariables.realtime = realtime;
  g_ServerGlobalVariables.absoluteframetime = host_frametime;
  g_ServerGlobalVariables.framecount = host_framecount;
  g_ServerGlobalVariables.interval_per_tick = host_state.interval_per_tick;
  if ( GetBaseLocalClient()->m_nSignonState >= 3
    || GetBaseLocalClient()->m_nSignonState >= 2 && GetBaseLocalClient()->m_bServerInfoProcessed )
  {
    m_nServerCount = GetBaseLocalClient()->m_nServerCount;
  }
  else if ( sv.m_State < ss_loading )
  {
    m_nServerCount = gHostSpawnCount;
  }
  else
  {
    m_nServerCount = sv.m_nSpawnCount;
  }
  g_ClientGlobalVariables.realtime = realtime;
  g_ClientGlobalVariables.absoluteframetime = host_frametime;
  g_ServerGlobalVariables.serverCount = m_nServerCount;
  g_ClientGlobalVariables.framecount = host_framecount;
  g_ClientGlobalVariables.interval_per_tick = host_state.interval_per_tick;
}

//------------------------------------------------------------------------------
// Address: 0x10186FA0
// Name: bool CheckVarRange_Generic(class ConVar __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
char __cdecl CheckVarRange_Generic(ConVar *pVar, int minVal, int maxVal)
{
  ConVar *m_pParent; // ecx
  int m_nValue; // eax
  int v7; // esi
  int v8; // eax
  int v9; // eax
  const char *v10; // eax
  int v11; // [esp-Ch] [ebp-Ch]

  if ( bInFunction )
    return 1;
  bInFunction = true;
  if ( (sv_cheats.m_pParent == nullptr || sv_cheats.m_pParent->m_Value.m_nValue == 0)
    && !Cmd_IsRptActive()
    && !(sv.m_State < ss_active ? GetBaseLocalClient()->m_nMaxClients == 1 : sv.m_nMaxclients <= 1) )
  {
    m_pParent = pVar->m_pParent;
    if ( m_pParent != nullptr )
      m_nValue = m_pParent->m_Value.m_nValue;
    else
      m_nValue = 0;
    v7 = minVal;
    if ( m_nValue >= minVal )
    {
      v7 = maxVal;
      if ( m_nValue <= maxVal )
        v7 = m_nValue;
    }
    if ( m_pParent != nullptr )
      v8 = m_pParent->m_Value.m_nValue;
    else
      v8 = 0;
    if ( v7 != v8 )
    {
      if ( m_pParent != nullptr )
        v9 = m_pParent->m_Value.m_nValue;
      else
        v9 = 0;
      v10 = (const char *)((int (__thiscall *)(ConVar *, int))pVar->GetName)(a1: pVar, a2: v9);
      _Warning(a1: "sv_cheats=0 prevented changing %s outside of the range [0,2] (was %d).\n", v10, v11);
      pVar->SetValue_2(this: &pVar->IConVar, a2: v7);
    }
  }
  bInFunction = false;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10187070
// Name: void _Host_RunFrame_Render(void)
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __usercall _Host_RunFrame_Render(IConVar *a1@<esi>)
{
  ConVar *v1; // eax
  int m_nValue; // esi
  const char *v3; // [esp-18h] [ebp-18h]
  float v4; // [esp-14h] [ebp-14h]

  v1 = pVar;
  if ( pVar != nullptr
    || (v3 = "mat_picmip",
        v1 = (ConVar *)((int (__thiscall *)(ICvar *))g_pCVar->FindVar_2)(a1: g_pCVar),
        pVar = v1,
        v1 != nullptr) )
  {
    CheckVarRange_Generic(pVar: v1, minVal: -10, maxVal: 2);
  }
  CheckVarRange_r_rootlod();
  r_lod_f(var: a1, pOldValue: v3, flOldValue: v4);
  if ( mat_norendering.m_pParent != nullptr )
    m_nValue = mat_norendering.m_pParent->m_Value.m_nValue;
  else
    m_nValue = 0;
  if ( cl_takesnapshot )
    CLoaderMemAlloc::CrtIsValidPointer(this: (ConVar *)&mat_norendering.IConVar, value: 0);
  g_HostTimes.starttime[3] = _Plat_FloatTime();
  CL_LatchInterpolationAmount();
  if ( r_ForceRestore.m_pParent != nullptr && r_ForceRestore.m_pParent->m_Value.m_nValue != 0 )
  {
    ForceMatSysRestore();
    CLoaderMemAlloc::CrtIsValidPointer(this: (ConVar *)&r_ForceRestore.IConVar, value: 0);
  }
  SCR_UpdateScreen();
  CL_DecayLights();
  g_HostTimes.deltas[3] = _Plat_FloatTime() - g_HostTimes.starttime[3] + g_HostTimes.deltas[3];
  saverestore->OnFrameRendered(this: saverestore);
  CLoaderMemAlloc::CrtIsValidPointer(this: (ConVar *)&mat_norendering.IConVar, value: m_nValue);
}

//------------------------------------------------------------------------------
// Address: 0x10187140
// Name: void _Host_RunFrame_Sound(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl _Host_RunFrame_Sound()
{
  IMDLCache *v0; // esi

  if ( g_pSoundJob == nullptr )
  {
    CVProfile::EnterScope(
      this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
      a2: "_Host_RunFrame_Sound",
      a3: 0,
      a4: "Sound",
      a5: false,
      a6: 4);
    g_HostTimes.starttime[4] = _Plat_FloatTime();
    if ( host_threaded_sound.m_pParent == nullptr
      || host_threaded_sound.m_pParent->m_Value.m_nValue == 0
      || !g_bAllowThreadedSound )
    {
      v0 = g_pMDLCache;
      g_pMDLCache->BeginCoarseLock(this: g_pMDLCache);
      if ( GetBaseLocalClient()->m_nSignonState == 6 )
        S_Update(pAudioState: &s_AudioState);
      else
        S_Update(pAudioState: nullptr);
      v0->EndCoarseLock(this: v0);
    }
    g_HostTimes.deltas[4] = _Plat_FloatTime() - g_HostTimes.starttime[4] + g_HostTimes.deltas[4];
    CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101871F0
// Name: void HLTV_Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl HLTV_Shutdown()
{
  CHLTVTestSystem *v0; // esi

  if ( hltv != nullptr )
  {
    hltv->Shutdown(this: &hltv->CBaseServer);
    if ( hltv != nullptr )
      ((void (__thiscall *)(CHLTVServer *, int))hltv->dtr_IGameEventListener2)(a1: hltv, a2: 1);
    hltv = nullptr;
  }
  if ( hltvtest != nullptr )
  {
    v0 = hltvtest;
    CHLTVTestSystem::~CHLTVTestSystem(this: hltvtest);
    free(pMem: v0);
    hltvtest = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10187250
// Name: void Host_Changelevel(bool,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __usercall Host_Changelevel(
        int a1@<ebx>,
        int a2@<edi>,
        bool loadfromsavedgame,
        const char *mapname,
        const char *start)
{
  IEngineVGuiInternal *v5; // eax
  const char *v6; // esi
  vgui::PropertyPage *v7; // ecx
  int v8; // edi
  int v9; // edi
  int v10; // ebx
  int v11; // edi
  KeyValues *v12; // eax
  KeyValues *v13; // esi
  IMatchEventsSubscription *v14; // eax
  char *v15; // edi
  vgui::CTreeViewListControl *v16; // ecx
  ECommandTarget_t TraceType; // eax
  vgui::CTreeViewListControl *v18; // ecx
  ECommandTarget_t v19; // eax
  CDownloadListGenerator *v20; // eax
  CServerPlugin_vtbl *v21; // esi
  char *v22; // eax
  int Time; // eax
  ISaveRestore_vtbl *v24; // esi
  int (__thiscall *GetMostRecentElapsedMinutes)(ISaveRestore *); // edx
  int v26; // eax
  ISaveRestore_vtbl *v27; // esi
  int v28; // edi
  CDownloadListGenerator *v29; // eax
  int v30; // [esp-8h] [ebp-23Ch]
  int v31; // [esp-4h] [ebp-238h]
  char dxMapName[260]; // [esp+0h] [ebp-234h] BYREF
  char _startspot[96]; // [esp+104h] [ebp-130h] BYREF
  char oldlevel[96]; // [esp+164h] [ebp-D0h] BYREF
  char level[96]; // [esp+1C4h] [ebp-70h] BYREF
  CAddTransitionResourcesCB addTransitionResources; // [esp+224h] [ebp-10h] BYREF
  char *startspot; // [esp+230h] [ebp-4h]

  if ( sv.m_State >= ss_active )
  {
    if ( demoplayer->IsPlayingBack(this: demoplayer) )
    {
      ConMsg(a1: "Changelevel invalid during demo playback\n");
    }
    else
    {
      if ( sv.m_bIsDedicated )
      {
        v6 = mapname;
      }
      else
      {
        v5 = EngineVGui();
        v6 = mapname;
        v5->SetProgressLevelName(this: v5, a2: mapname);
      }
      SCR_BeginLoadingPlaque(levelName: v6);
      g_pFileSystem->AsyncFinishAll(this: g_pFileSystem, a2: 0);
      S_StopAllSounds(bClear: true);
      V_strncpy(pDest: dxMapName, pSrc: v6, maxLen: 260);
      if ( g_pMaterialSystemHardwareConfig != nullptr )
      {
        V_StripExtension(in: v6, out: dxMapName, outSize: 260);
        V_strncat(pDest: dxMapName, pSrc: ".bsp", destBufferSize: 0x104u, max_chars_to_copy: -1);
      }
      CLoaderMemAlloc::CrtSetReportMode(this: (ConVar *)&host_map.IConVar, value: dxMapName);
      V_strncpy(pDest: level, pSrc: v6, maxLen: 96);
      if ( start != nullptr )
      {
        V_strncpy(pDest: _startspot, pSrc: start, maxLen: 96);
        *(float *)&startspot = COERCE_FLOAT(_startspot);
      }
      else
      {
        *(float *)&startspot = 0.0;
      }
      _Warning(a1: "---- Host_Changelevel ----\n", a2, a1);
      CColorBalanceUIPanel::Init(this: v7);
      ((void (__thiscall *)(IMaterialSystem *, int, int))materials->OnLevelShutdown)(a1: materials, a2: v30, a3: v31);
      saverestore->SetIsXSave(this: saverestore, a2: false);
      v8 = (int)(float)(g_ServerGlobalVariables.curtime
                      - (float)saverestore->GetMostRecentElapsedTimeSet(this: saverestore));
      v9 = saverestore->GetMostRecentElapsedSeconds(this: saverestore) + v8;
      v10 = v9 / 60 + saverestore->GetMostRecentElapsedMinutes(this: saverestore);
      saverestore->SetMostRecentElapsedMinutes(this: saverestore, a2: v10);
      v11 = v9 % 60;
      saverestore->SetMostRecentElapsedSeconds(this: saverestore, a2: v11);
      v12 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v12 != nullptr )
        v13 = KeyValues::KeyValues(this: v12, setName: "OnHostChangeLevel");
      else
        v13 = nullptr;
      KeyValues::SetString(this: v13, keyName: "map", value: mapname);
      KeyValues::SetUint64(this: v13, keyName: "elapsed", value: v11 + 60 * v10);
      KeyValues::SetInt(this: v13, keyName: "bysave", value: 0);
      v14 = g_pMatchFramework->GetEventsSubscription(this: g_pMatchFramework);
      v14->BroadcastEvent(this: v14, a2: v13);
      V_strncpy(pDest: oldlevel, pSrc: sv.m_szMapname, maxLen: 96);
      v15 = startspot;
      if ( !loadfromsavedgame
        || (addTransitionResources.m_pLevelName = level,
            addTransitionResources.__vftable = (CAddTransitionResourcesCB_vtbl *)&CAddTransitionResourcesCB::`vftable',
            addTransitionResources.m_pLandMarkName = startspot,
            saverestore->SaveGameState(this: saverestore, a2: true, a3: &addTransitionResources, a4: true, a5: false)) )
      {
        g_pServerPluginHandler->LevelShutdown(this: g_pServerPluginHandler);
        audiosourcecache->LevelShutdown(this: audiosourcecache);
        CBaseServer::InactivateClients(this: &sv);
        saverestore->FinishAsyncSave(this: saverestore);
        if ( IsUsingMasterLegacyMode()
          && (v16 = (vgui::CTreeViewListControl *)g_pMaster, g_pMaster != nullptr)
          && g_pMaster->RestartOnLevelChange(this: g_pMaster)
          || sv.m_bRestartOnLevelChange )
        {
          TraceType = CTraceFilter::GetTraceType(this: v16);
          Cbuf_Clear(eTarget: TraceType);
          v19 = CTraceFilter::GetTraceType(this: v18);
          Cbuf_AddText(eTarget: v19, pText: "quit\n", nTickDelay: 0);
        }
        else
        {
          v20 = DownloadListGenerator();
          CDownloadListGenerator::OnLevelLoadStart(this: v20, levelName: level);
          _COM_TimestampedLog(a1: "*** Map Load: %s", level);
          if ( CGameServer::SpawnServer(this: &sv, mapname: level, startspot: v15) )
          {
            g_ServerGlobalVariables.curtime = CBaseServer::GetTime(this: &sv);
            ((void (__thiscall *)(IAudioSourceCache *, char *, _DWORD))audiosourcecache->LevelInit)(
              a1: audiosourcecache,
              a2: level,
              a3: *(_DWORD *)dxMapName);
            v21 = g_pServerPluginHandler->__vftable;
            *(_DWORD *)dxMapName = 0;
            v22 = CM_EntityString();
            if ( loadfromsavedgame )
            {
              ((void (__thiscall *)(CServerPlugin *, char *, char *, char *, char *, int))v21->LevelInit)(
                a1: g_pServerPluginHandler,
                a2: level,
                a3: v22,
                a4: oldlevel,
                a5: v15,
                a6: 1);
              CBaseServer::SetPaused(this: &sv, paused: true);
              sv.m_bLoadgame = true;
            }
            else
            {
              ((void (__thiscall *)(CServerPlugin *, char *, char *, _DWORD, _DWORD, _DWORD))v21->LevelInit)(
                a1: g_pServerPluginHandler,
                a2: level,
                a3: v22,
                a4: 0,
                a5: 0,
                a6: 0);
            }
            SV_ActivateServer();
            Time = (int)CBaseServer::GetTime(this: &sv);
            v24 = saverestore->__vftable;
            GetMostRecentElapsedMinutes = saverestore->GetMostRecentElapsedMinutes;
            *(float *)&startspot = (float)Time;
            v26 = GetMostRecentElapsedMinutes(this: saverestore);
            v24->SetMostRecentElapsedMinutes(
              this: saverestore,
              a2: v26 - (int)(float)(*(float *)&startspot * 0.016666668));
            v27 = saverestore->__vftable;
            v28 = saverestore->GetMostRecentElapsedSeconds(this: saverestore);
            v27->SetMostRecentElapsedSeconds(this: saverestore, a2: v28 - (int)fmod(*(float *)&startspot, 60.0));
            saverestore->ForgetRecentSave(this: saverestore);
            NotifyDedicatedServerUI(message: "UpdateMap");
            v29 = DownloadListGenerator();
            CDownloadListGenerator::OnLevelLoadEnd(this: v29);
          }
        }
      }
      else
      {
        _Warning(a1: "Failed to save data for transition\n");
        SCR_EndLoadingPlaque();
      }
    }
  }
  else
  {
    ConMsg(a1: "Only the server may changelevel\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x10187AE0
// Name: private: virtual int CJob::DoAbort(bool)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CJob::DoAbort(CJob *this, bool bDiscard)
{
  return 3;
}

//------------------------------------------------------------------------------
// Address: 0x10187B00
// Name: public: virtual int CRefCounted1<class IWorldRenderList,class CRefCountServiceBase<1,class CRefMT>>::Release(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CRefCounted1<IWorldRenderList,CRefCountServiceBase<1,CRefMT>>::Release(
        CRefCounted1<IWorldRenderList,CRefCountServiceBase<1,CRefMT> > *this)
{
  CRefCountServiceBase<1,CRefMT> *v1; // esi
  int result; // eax

  v1 = &this->CRefCountServiceBase<1,CRefMT>;
  result = _InterlockedDecrement(&this->m_iRefs);
  if ( result == 0 )
  {
    if ( v1->OnFinalRelease(this: v1) )
      ((void (__thiscall *)(CRefCountServiceBase<1,CRefMT> *, int))v1->dtr_CRefCountServiceBase<1,CRefMT>)(
        a1: v1,
        a2: 1);
    return 0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10187C00
// Name: public: virtual int CFunctorJob::DoExecute(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CFunctorJob::DoExecute(CFunctorJob *this)
{
  this->m_pFunctor.m_pObject->operator()(this: this->m_pFunctor.m_pObject);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10187DE0
// Name: void CL_FindInterpolatedAddAngle(float,float __near &,struct AddAngle __near * __near *,struct AddAngle __near * __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CL_FindInterpolatedAddAngle(float t, float *frac, AddAngle **prev, AddAngle **next)
{
  int m_Size; // edi
  AddAngle *v5; // ebx
  int v6; // esi
  AddAngle *m_pMemory; // edx
  float starttime; // xmm1_4
  AddAngle *v9; // eax
  float v10; // xmm1_4
  float v11; // xmm0_4
  int v12; // xmm1_4

  m_Size = GetLocalClient(nSlot: -1)->addangle.m_Size;
  v5 = nullptr;
  v6 = 0;
  *prev = nullptr;
  *next = nullptr;
  if ( m_Size > 0 )
  {
    while ( 1 )
    {
      m_pMemory = GetLocalClient(nSlot: -1)->addangle.m_Memory.m_pMemory;
      starttime = m_pMemory[v6].starttime;
      v9 = &m_pMemory[v6];
      *next = v9;
      if ( starttime > t )
        break;
      ++v6;
      *prev = v9;
      v5 = v9;
      if ( v6 >= m_Size )
        return;
    }
    if ( v6 != 0 )
    {
      v10 = v9->starttime;
      if ( v10 == v5->starttime )
      {
        *frac = 0.0;
      }
      else
      {
        v11 = (float)(t - v5->starttime) / (float)(v10 - v5->starttime);
        v12 = 0;
        *frac = v11;
        if ( v11 < 0.0 || (v12 = 1065353216, v11 > 1.0) )
          v11 = *(float *)&v12;
        *frac = v11;
      }
    }
    else
    {
      *prev = v9;
      *frac = 0.0;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10187ED0
// Name: public: virtual CDebugInputThread::~CDebugInputThread(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDebugInputThread::~CDebugInputThread(CDebugInputThread *this)
{
  bool v2; // sf

  this->__vftable = (CDebugInputThread_vtbl *)&CDebugInputThread::`vftable';
  v2 = this->m_inputString.m_Storage.m_Memory.m_nGrowSize < 0;
  this->m_inputString.m_Storage.m_nActualLength = 0;
  if ( !v2 )
  {
    if ( this->m_inputString.m_Storage.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_inputString.m_Storage.m_Memory.m_pMemory);
      this->m_inputString.m_Storage.m_Memory.m_pMemory = nullptr;
    }
    this->m_inputString.m_Storage.m_Memory.m_nAllocationCount = 0;
  }
  CThreadMutex::~CThreadMutex(this: &this->m_mx);
  CThread::~CThread(this);
}

//------------------------------------------------------------------------------
// Address: 0x10187F60
// Name: bool GetFileFromRemoteStorage(class ISteamRemoteStorage __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl GetFileFromRemoteStorage(
        ISteamRemoteStorage *pRemoteStorage,
        const char *pszRemoteFileName,
        const char *pszLocalFileName)
{
  bool v3; // bl
  int v4; // esi
  void *v5; // edi
  void *buf; // [esp+Ch] [ebp-Ch]

  v3 = false;
  v4 = pRemoteStorage->GetFileSize(this: pRemoteStorage, a2: pszRemoteFileName);
  if ( v4 > 0 )
  {
    buf = _g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v4);
    if ( pRemoteStorage->FileRead(this: pRemoteStorage, a2: pszRemoteFileName, a3: buf, a4: v4) == v4 )
    {
      v5 = g_pFileSystem->Open(this: &g_pFileSystem->IBaseFileSystem, a2: pszLocalFileName, a3: "wb", a4: "MOD");
      if ( v5 != nullptr )
      {
        v3 = g_pFileSystem->Write(this: &g_pFileSystem->IBaseFileSystem, a2: buf, a3: v4, a4: v5) == v4;
        g_pFileSystem->Close(this: &g_pFileSystem->IBaseFileSystem, a2: v5);
        if ( v3 )
          DevMsg(
            a1: "[Cloud]: SUCCEESS retrieved %s from remote storage into %s\n",
            pszRemoteFileName,
            pszLocalFileName);
        else
          DevMsg(a1: "[Cloud]: FAILED retrieved %s from remote storage into %s\n", pszRemoteFileName, pszLocalFileName);
      }
    }
    if ( buf != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: buf);
  }
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x10188050
// Name: void CL_DiscardOldAddAngleEntries(float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CL_DiscardOldAddAngleEntries(float t)
{
  int i; // edi
  CClientState *LocalClient; // esi
  int v3; // eax
  float killtime; // [esp+8h] [ebp+8h]

  killtime = (float)(t - host_state.interval_per_tick) - 0.1;
  for ( i = 0; i < GetLocalClient(nSlot: -1)->addangle.m_Size; ++i )
  {
    if ( killtime >= GetLocalClient(nSlot: -1)->addangle.m_Memory.m_pMemory[i].starttime )
    {
      LocalClient = GetLocalClient(nSlot: -1);
      v3 = LocalClient->addangle.m_Size - i - 1;
      if ( v3 > 0 )
        _V_memmove(
          dest: &LocalClient->addangle.m_Memory.m_pMemory[i],
          src: &LocalClient->addangle.m_Memory.m_pMemory[i + 1],
          count: 8 * v3);
      --LocalClient->addangle.m_Size;
      --i;
    }
  }
  if ( GetLocalClient(nSlot: -1)->addangle.m_Size == 0 )
  {
    GetLocalClient(nSlot: -1)->addangletotal = 0.0;
    GetLocalClient(nSlot: -1)->prevaddangletotal = 0.0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10188130
// Name: void CL_ApplyAddAngle(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CL_ApplyAddAngle()
{
  CClientState *BaseLocalClient; // eax
  float prevaddangletotal; // xmm0_4
  CClientState *LocalClient; // eax
  IPrediction_vtbl *v3; // esi
  CClientState *v4; // eax
  float curtime; // [esp+14h] [ebp-10h]
  float amove; // [esp+18h] [ebp-Ch] BYREF
  AddAngle *next; // [esp+1Ch] [ebp-8h] BYREF
  AddAngle *prev; // [esp+20h] [ebp-4h] BYREF

  BaseLocalClient = GetBaseLocalClient();
  curtime = CClientState::GetTime(this: BaseLocalClient) - host_state.interval_per_tick;
  prev = nullptr;
  next = nullptr;
  amove = 0.0;
  CL_FindInterpolatedAddAngle(t: curtime, frac: &amove, &prev, &next);
  if ( prev != nullptr && next != nullptr )
    prevaddangletotal = (float)((float)(next->total - prev->total) * amove) + prev->total;
  else
    prevaddangletotal = GetLocalClient(nSlot: -1)->prevaddangletotal;
  prev = (AddAngle *)LODWORD(prevaddangletotal);
  amove = prevaddangletotal - GetLocalClient(nSlot: -1)->prevaddangletotal;
  LocalClient = GetLocalClient(nSlot: -1);
  LocalClient->viewangles.y = LocalClient->viewangles.y + amove;
  v3 = g_pClientSidePrediction->__vftable;
  v4 = GetLocalClient(nSlot: -1);
  v3->SetLocalViewAngles(this: g_pClientSidePrediction, a2: &v4->viewangles);
  LODWORD(GetLocalClient(nSlot: -1)->prevaddangletotal) = prev;
  CL_DiscardOldAddAngleEntries(t: curtime);
}

//------------------------------------------------------------------------------
// Address: 0x10188230
// Name: void Snd_Restart_f(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall Snd_Restart_f(int a1@<esi>)
{
  CClientState *BaseLocalClient; // eax
  int v2; // esi
  int v3; // edi
  ConCommand *v4; // esi
  musicsave_t *m_pMemory; // eax
  CCommand cmd; // [esp+8h] [ebp-520h] BYREF
  const char *argv[1]; // [esp+510h] [ebp-18h] BYREF
  CUtlVector<musicsave_t,CUtlMemory<musicsave_t,int> > music; // [esp+514h] [ebp-14h] BYREF

  memset(&music, 0, sizeof(music));
  S_GetCurrentlyPlayingMusic(musiclist: &music);
  S_Shutdown(a1);
  snd_firsttime = true;
  BaseLocalClient = GetBaseLocalClient();
  CClientState::ClearSounds(this: BaseLocalClient);
  S_Init();
  v2 = 0;
  if ( music.m_Size > 0 )
  {
    v3 = 0;
    do
    {
      S_RestartSong(song: &music.m_Memory.m_pMemory[v3]);
      ++v2;
      ++v3;
    }
    while ( v2 < music.m_Size );
  }
  if ( audiosourcecache != nullptr && sv.m_szMapname[0] != 0 )
    ((void (__stdcall *)(char *))audiosourcecache->LevelInit)(a1: sv.m_szMapname);
  v4 = g_pCVar->FindCommand_2(this: g_pCVar, a2: "cl_soundscape_flush");
  if ( v4 != nullptr )
  {
    argv[0] = "cl_soundscape_flush";
    CCommand::CCommand(this: &cmd, nArgC: 1, ppArgV: argv);
    v4->Dispatch(this: v4, a2: &cmd);
  }
  Voice_ForceInit();
  m_pMemory = music.m_Memory.m_pMemory;
  music.m_Size = 0;
  if ( music.m_Memory.m_nGrowSize >= 0 )
  {
    if ( music.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: music.m_Memory.m_pMemory);
      m_pMemory = nullptr;
      music.m_Memory.m_pMemory = nullptr;
    }
    music.m_Memory.m_nAllocationCount = 0;
  }
  music.m_pElements = m_pMemory;
  if ( music.m_Memory.m_nGrowSize >= 0 && m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x10188350
// Name: void Host_WriteConfiguration(int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __usercall Host_WriteConfiguration(int a1@<ebx>, int a2@<edi>, int iController, const char *filename)
{
  const char *v4; // esi
  int v5; // eax
  int i; // esi
  int *v7; // edi
  int v8; // esi
  int HSteamPipe; // eax
  int HSteamUser; // eax
  ISteamRemoteStorage *v11; // eax
  ISteamRemoteStorage *v12; // esi
  bool (__thiscall *GetQuota)(ISteamRemoteStorage *, int *, int *); // eax
  ConVar *m_pParent; // ecx
  int m_nValue; // eax
  int v16; // eax
  char *m_pszString; // eax
  void *v18; // edi
  unsigned int v19; // esi
  void *v20; // ebx
  void *v21; // edi
  int v22; // esi
  void *v23; // ebx
  void *v24; // esi
  char szLogoFileName[260]; // [esp+4h] [ebp-244h] BYREF
  char szFileName[260]; // [esp+108h] [ebp-140h] BYREF
  int availableBytes; // [esp+20Ch] [ebp-3Ch] BYREF
  CUtlBuffer configBuff; // [esp+210h] [ebp-38h] BYREF
  int totalBytes; // [esp+240h] [ebp-8h] BYREF
  ISteamRemoteStorage *pRemoteStorage; // [esp+244h] [ebp-4h]

  v4 = filename;
  if ( filename == nullptr )
    v4 = "config.cfg";
  if ( host_initialized )
  {
    v5 = iController;
    if ( iController < 0 )
      v5 = 0;
    if ( g_bConfigCfgExecuted[v5] )
    {
      if ( g_bInEditMode )
      {
        ConMsg(a1: "skipping %s output when in map edit mode\n", v4);
        return;
      }
      if ( !sv.m_bIsDedicated )
      {
        if ( Key_CountBindings() <= 1 )
        {
          ConMsg(a1: "skipping %s output, no keys bound\n", v4);
          return;
        }
        CUtlBuffer::CUtlBuffer(this: &configBuff, growSize: 0, initSize: 0, nFlags: 1);
        V_snprintf(pDest: szFileName, maxLen: 260, pFormat: "cfg/%s", v4);
        g_pFileSystem->CreateDirHierarchy(this: g_pFileSystem, a2: "cfg", a3: "MOD");
        if ( g_pFileSystem->FileExists(this: &g_pFileSystem->IBaseFileSystem, a2: szFileName, a3: "MOD")
          && !g_pFileSystem->IsFileWritable(this: &g_pFileSystem->IBaseFileSystem, a2: szFileName, a3: "MOD") )
        {
          ConMsg(a1: "Config file %s is read-only!!\n", szFileName);
LABEL_53:
          CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>::~CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>(this: &configBuff);
          return;
        }
        CUtlBuffer::Printf(this: &configBuff, pFmt: "unbindall\n");
        Key_WriteBindings(buf: &configBuff, iSplitscreenSlot: -1);
        CCvarUtilities::WriteVariables(
          this: cv,
          buff: &configBuff,
          iSplitscreenSlot: -1,
          bSlotRequired: false,
          pConvarsListVoid: nullptr);
        for ( i = 0; i < host_state.max_splitscreen_players; ++i )
        {
          if ( g_ClientDLL->IN_IsKeyDown(this: g_ClientDLL, a2: "in_jlook", a3: (bool *)&filename + 3)
            && HIBYTE(filename) != 0 )
          {
            CUtlBuffer::Printf(this: &configBuff, pFmt: "cmd%d +jlook\n", i + 1);
          }
        }
        if ( configBuff.m_nMaxPut == 0 )
          goto LABEL_53;
        if ( _SteamClient() == 0 )
          goto LABEL_52;
        v7 = (int *)_SteamClient();
        v8 = *v7;
        HSteamPipe = _SteamAPI_GetHSteamPipe(a1: "STEAMREMOTESTORAGE_INTERFACE_VERSION004");
        HSteamUser = _SteamAPI_GetHSteamUser(a1: HSteamPipe);
        v11 = (ISteamRemoteStorage *)(*(int (__thiscall **)(int *, int))(v8 + 52))(a1: v7, a2: HSteamUser);
        v12 = v11;
        pRemoteStorage = v11;
        if ( v11 == nullptr )
          goto LABEL_52;
        GetQuota = v11->GetQuota;
        totalBytes = 0;
        if ( !GetQuota(this: v12, a2: &totalBytes, a3: &availableBytes) || totalBytes <= 0 )
          goto LABEL_52;
        m_pParent = cl_cloud_settings.m_pParent;
        if ( cl_cloud_settings.m_pParent != nullptr )
        {
          m_nValue = cl_cloud_settings.m_pParent->m_Value.m_nValue;
          if ( m_nValue == -1 )
          {
LABEL_34:
            if ( m_pParent == nullptr )
            {
              LOBYTE(v16) = 0;
              goto LABEL_38;
            }
            v16 = m_pParent->m_Value.m_nValue;
            if ( v16 != -1 )
            {
LABEL_38:
              if ( (v16 & 2) != 0 )
              {
                if ( (cl_logofile.m_nFlags & 0x1000) != 0 )
                {
                  m_pszString = "FCVAR_NEVER_AS_STRING";
                }
                else
                {
                  m_pszString = cl_logofile.m_pParent->m_Value.m_pszString;
                  if ( m_pszString == nullptr )
                    m_pszString = (char *)defaultValue;
                }
                V_strncpy(pDest: szLogoFileName, pSrc: m_pszString, maxLen: 260);
                if ( g_pFileSystem->FileExists(this: &g_pFileSystem->IBaseFileSystem, a2: szLogoFileName, a3: "MOD") )
                {
                  v18 = (void *)((int (__thiscall *)(IBaseFileSystem *, char *, const char *, const char *, int, int))g_pFileSystem->Open)(
                                  a1: &g_pFileSystem->IBaseFileSystem,
                                  a2: szLogoFileName,
                                  a3: "rb",
                                  a4: "MOD",
                                  a5: a1,
                                  a6: a2);
                  if ( v18 != nullptr )
                  {
                    v19 = g_pFileSystem->Size_2(this: &g_pFileSystem->IBaseFileSystem, a2: v18);
                    v20 = MemAlloc_Alloc(nSize: v19);
                    if ( g_pFileSystem->Read(this: &g_pFileSystem->IBaseFileSystem, a2: v20, a3: v19, a4: v18) == v19 )
                    {
                      V_SetExtension(path: g_szDefaultLogoFileName, extension: ".vtf", pathStringLength: 31);
                      pRemoteStorage->FileWrite(this: pRemoteStorage, a2: g_szDefaultLogoFileName, a3: v20, a4: v19);
                    }
                    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v20);
                    g_pFileSystem->Close(this: &g_pFileSystem->IBaseFileSystem, a2: v18);
                  }
                  V_SetExtension(path: szLogoFileName, extension: ".vmt", pathStringLength: 260);
                  v21 = (void *)((int (__thiscall *)(IBaseFileSystem *, char *))g_pFileSystem->Open)(
                                  a1: &g_pFileSystem->IBaseFileSystem,
                                  a2: szLogoFileName);
                  if ( v21 != nullptr )
                  {
                    v22 = ((int (__thiscall *)(IBaseFileSystem *, void *, const char *, const char *))g_pFileSystem->Size_2)(
                            a1: &g_pFileSystem->IBaseFileSystem,
                            a2: v21,
                            a3: "rb",
                            a4: "MOD");
                    v23 = MemAlloc_Alloc(nSize: v22);
                    if ( g_pFileSystem->Read(this: &g_pFileSystem->IBaseFileSystem, a2: v23, a3: v22, a4: v21) == v22 )
                    {
                      V_SetExtension(path: g_szDefaultLogoFileName, extension: ".vmt", pathStringLength: 31);
                      pRemoteStorage->FileWrite(this: pRemoteStorage, a2: g_szDefaultLogoFileName, a3: v23, a4: v22);
                    }
                    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v23);
                    g_pFileSystem->Close(this: &g_pFileSystem->IBaseFileSystem, a2: v21);
                  }
                }
              }
            }
LABEL_52:
            v24 = MemAlloc_Alloc(nSize: configBuff.m_nMaxPut);
            _V_memcpy(dest: v24, src: configBuff.m_Memory.m_pMemory, count: configBuff.m_nMaxPut);
            g_pFileSystem->AsyncWrite(
              this: g_pFileSystem,
              a2: szFileName,
              a3: v24,
              a4: configBuff.m_nMaxPut,
              a5: true,
              a6: false,
              a7: nullptr);
            ConMsg(a1: "Host_WriteConfiguration: Wrote %s\n", szFileName);
            goto LABEL_53;
          }
        }
        else
        {
          LOBYTE(m_nValue) = 0;
        }
        if ( (m_nValue & 1) != 0 )
        {
          if ( v12->FileWrite(this: v12, a2: szFileName, a3: configBuff.m_Memory.m_pMemory, a4: configBuff.m_nMaxPut) != 0 )
            DevMsg(a1: "[Cloud]: SUCCEESS saving %s in remote storage\n", szFileName);
          else
            DevMsg(a1: "[Cloud]: FAILED saving %s in remote storage\n", szFileName);
          m_pParent = cl_cloud_settings.m_pParent;
        }
        goto LABEL_34;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101887F0
// Name: void Host_ReadConfiguration(int,bool)
// Source: json
//------------------------------------------------------------------------------
void __usercall Host_ReadConfiguration(int a1@<ebx>, int a2@<edi>, int a3@<esi>, int iController)
{
  char v4; // bl
  int *v5; // edi
  int v6; // esi
  int HSteamPipe; // eax
  int HSteamUser; // eax
  ISteamRemoteStorage *v9; // esi
  ConVar *m_pParent; // eax
  int m_nValue; // eax
  vgui::CTreeViewListControl *v12; // ecx
  ECommandTarget_t TraceType; // eax
  ECommandTarget_t v14; // eax
  int v15; // eax
  char *m_pszString; // eax
  int v17; // eax
  int v18; // [esp-18h] [ebp-11Ch]
  int v19; // [esp-8h] [ebp-10Ch]
  int v20; // [esp-4h] [ebp-108h]
  char szLogoFileName[260]; // [esp+0h] [ebp-104h] BYREF

  if ( sv.m_bIsDedicated )
    return;
  if ( g_pFileSystem == nullptr )
    Sys_Error(error: "Host_ReadConfiguration:  g_pFileSystem == NULL\n");
  v20 = a1;
  v4 = 0;
  if ( _SteamClient(a1: a3, a2: v20) != 0 )
  {
    v5 = (int *)_SteamClient(a1: a2, a2: v19);
    v6 = *v5;
    HSteamPipe = _SteamAPI_GetHSteamPipe(a1: "STEAMREMOTESTORAGE_INTERFACE_VERSION004");
    HSteamUser = _SteamAPI_GetHSteamUser(a1: HSteamPipe);
    v9 = (ISteamRemoteStorage *)(*(int (__thiscall **)(int *, int))(v6 + 52))(a1: v5, a2: HSteamUser);
    a2 = v18;
    if ( v9 == nullptr )
      goto LABEL_18;
    m_pParent = cl_cloud_settings.m_pParent;
    if ( cl_cloud_settings.m_pParent == nullptr )
      goto LABEL_15;
    if ( cl_cloud_settings.m_pParent->m_Value.m_nValue == -1 )
    {
      if ( !v9->FileExists(this: v9, a2: "cfg/config.cfg") )
      {
        DevMsg(a1: "[Cloud]: Default setting with remote data non-existent, sync all\n");
        CLoaderMemAlloc::CrtIsValidPointer(this: (ConVar *)&cl_cloud_settings.IConVar, value: 0x7FFF);
      }
      m_pParent = cl_cloud_settings.m_pParent;
    }
    if ( m_pParent != nullptr )
    {
      m_nValue = m_pParent->m_Value.m_nValue;
      if ( m_nValue == -1 )
        goto LABEL_18;
    }
    else
    {
LABEL_15:
      LOBYTE(m_nValue) = 0;
    }
    if ( (m_nValue & 1) != 0 )
      GetFileFromRemoteStorage(
        pRemoteStorage: v9,
        pszRemoteFileName: "cfg/config.cfg",
        pszLocalFileName: "cfg/config.cfg");
  }
  else
  {
    v9 = nullptr;
  }
LABEL_18:
  if ( g_pFileSystem->FileExists(this: &g_pFileSystem->IBaseFileSystem, a2: "//mod/cfg/config.cfg", a3: nullptr) )
  {
    TraceType = CTraceFilter::GetTraceType(this: v12);
    Cbuf_AddText(eTarget: TraceType, pText: "exec config.cfg mod\n", nTickDelay: 0);
  }
  else
  {
    v14 = CTraceFilter::GetTraceType(this: v12);
    Cbuf_AddText(eTarget: v14, pText: "exec config_default.cfg\n", nTickDelay: 0);
    v4 = 1;
  }
  Cbuf_Execute();
  if ( v9 != nullptr )
  {
    if ( cl_cloud_settings.m_pParent == nullptr )
    {
      LOBYTE(v15) = 0;
      goto LABEL_26;
    }
    v15 = cl_cloud_settings.m_pParent->m_Value.m_nValue;
    if ( v15 != -1 )
    {
LABEL_26:
      if ( (v15 & 2) != 0 )
      {
        if ( (cl_logofile.m_nFlags & 0x1000) != 0 )
        {
          m_pszString = "FCVAR_NEVER_AS_STRING";
        }
        else
        {
          m_pszString = cl_logofile.m_pParent->m_Value.m_pszString;
          if ( m_pszString == nullptr )
            m_pszString = (char *)defaultValue;
        }
        V_strncpy(pDest: szLogoFileName, pSrc: m_pszString, maxLen: 260);
        V_SetExtension(path: szLogoFileName, extension: ".vtf", pathStringLength: 260);
        V_SetExtension(path: g_szDefaultLogoFileName, extension: ".vtf", pathStringLength: 31);
        GetFileFromRemoteStorage(
          pRemoteStorage: v9,
          pszRemoteFileName: g_szDefaultLogoFileName,
          pszLocalFileName: szLogoFileName);
        V_SetExtension(path: g_szDefaultLogoFileName, extension: ".vmt", pathStringLength: 31);
        V_SetExtension(path: szLogoFileName, extension: ".vmt", pathStringLength: 260);
        GetFileFromRemoteStorage(
          pRemoteStorage: v9,
          pszRemoteFileName: g_szDefaultLogoFileName,
          pszLocalFileName: szLogoFileName);
      }
    }
  }
  if ( Key_CountBindings() == 0 )
    UseDefaultBindings();
  Key_SetBinding(keynum: KEY_ESCAPE, pBinding: "cancelselect");
  if ( Key_NameForBinding(pBinding: "toggleconsole", userId: -1, iStartCount: 0, iAllowJoystick: -1) == nullptr )
    Key_SetBinding(keynum: KEY_BACKQUOTE, pBinding: "toggleconsole");
  SetupDefaultAskConnectAcceptKey();
  v17 = iController;
  if ( iController < 0 )
    v17 = 0;
  g_bConfigCfgExecuted[v17] = true;
  if ( v4 != 0 )
  {
    LOBYTE(a1) = host_initialized;
    host_initialized = true;
    Host_WriteConfiguration(a1, a2, iController, filename: "config.cfg");
    host_initialized = a1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10188A70
// Name: host_writeconfig
// Source: json
//------------------------------------------------------------------------------
void __usercall host_writeconfig(int a1@<ebx>, int a2@<edi>, const CCommand *args)
{
  const char *v3; // eax
  const char *v4; // eax
  char outfile[96]; // [esp+0h] [ebp-60h] BYREF

  if ( args->m_nArgc <= 2 )
  {
    if ( args->m_nArgc == 2 )
    {
      v3 = args->m_ppArgv[1];
      if ( v3 != nullptr && *v3 != 0 )
      {
        V_FileBase(in: v3, out: outfile, maxlen: 96);
        v4 = va(format: "%s.cfg", outfile);
        Host_WriteConfiguration(a1, a2, iController: -1, filename: v4);
      }
    }
    else
    {
      Host_WriteConfiguration(a1, a2, iController: -1, filename: "config.cfg");
    }
  }
  else
  {
    ConMsg(a1: "Usage:  writeconfig <filename.cfg>\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x10188AE0
// Name: host_writeconfig_ss
// Source: json
//------------------------------------------------------------------------------
void __usercall host_writeconfig_ss(int a1@<ebx>, int a2@<edi>, const CCommand *args)
{
  int m_nArgc; // eax
  const char *v4; // eax
  const char *v5; // esi
  int v6; // esi
  const char *v7; // eax
  int v8; // eax
  char outfile[96]; // [esp+4h] [ebp-60h] BYREF

  m_nArgc = args->m_nArgc;
  if ( args->m_nArgc <= 1 || m_nArgc > 3 )
  {
    ConMsg(a1: "Usage:  writeconfig <controller index> <filename.cfg>\n");
  }
  else if ( m_nArgc == 3 )
  {
    v4 = args->m_ppArgv[2];
    if ( v4 != nullptr && *v4 != 0 )
    {
      V_FileBase(in: v4, out: outfile, maxlen: 96);
      if ( args->m_nArgc > 1 )
        v5 = args->m_ppArgv[1];
      else
        v5 = defaultValue;
      v6 = atoi(nptr: v5);
      v7 = va(format: "%s.cfg", outfile);
      Host_WriteConfiguration(a1, a2, iController: v6, filename: v7);
    }
  }
  else if ( m_nArgc == 2 )
  {
    v8 = atoi(nptr: args->m_ppArgv[1]);
    Host_WriteConfiguration(a1, a2, iController: v8, filename: "config.cfg");
  }
  else
  {
    Host_WriteConfiguration(a1, a2, iController: -1, filename: "config.cfg");
  }
}

//------------------------------------------------------------------------------
// Address: 0x10188BB0
// Name: void Host_BeginThreadedSound(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Host_BeginThreadedSound()
{
  CFunctorJob *v0; // esi
  CFunctor *v1; // eax
  CFunctorJob *v2; // eax

  if ( host_threaded_sound.m_pParent != nullptr
    && host_threaded_sound.m_pParent->m_Value.m_nValue != 0
    && g_bAllowThreadedSound )
  {
    v0 = (CFunctorJob *)MemAlloc_Alloc(nSize: 0x44u);
    if ( v0 != nullptr )
    {
      v1 = (CFunctor *)MemAlloc_Alloc(nSize: 0x14u);
      if ( v1 != nullptr )
      {
        v1[1].m_nUserID = 1;
        v1->__vftable = (CFunctor_vtbl *)&CFunctor0<void (__cdecl *)(void),CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>>::`vftable'{for `CFunctor'};
        v1[1].__vftable = (CFunctor_vtbl *)&CFunctor0<void (__cdecl *)(void),CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>>::`vftable'{for `CRefCountServiceBase<1,CRefMT>'};
        v1[2].__vftable = (CFunctor_vtbl *)Host_UpdateSounds;
        v2 = CFunctorJob::CFunctorJob(this: v0, pFunctor: v1, pszDescription: nullptr);
      }
      else
      {
        v2 = CFunctorJob::CFunctorJob(this: v0, pFunctor: nullptr, pszDescription: nullptr);
      }
    }
    else
    {
      v2 = nullptr;
    }
    g_pSoundJob = v2;
    _g_pThreadPool->AddJob(this: _g_pThreadPool, a2: v2);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10188C40
// Name: void _Host_RunFrame(float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl _Host_RunFrame(float time)
{
  void (*BeginCoarseLock)(void); // edx
  int v2; // eax
  double v3; // st7
  int m_nValue; // eax
  CMapReslistGenerator *v5; // eax
  float v6; // xmm1_4
  signed int v7; // ebx
  float interval_per_tick; // xmm2_4
  float v9; // xmm0_4
  char v10; // al
  BOOL v11; // eax
  double v12; // st7
  CClientState *v13; // esi
  CJob *v14; // esi
  long double v15; // st7
  CClientState *v16; // eax
  CClientState *v17; // eax
  int v18; // edi
  int v19; // esi
  long double v20; // st7
  CClientState *v21; // eax
  CClientState *v22; // eax
  CClientState *v23; // eax
  CClientState *v24; // eax
  signed int v25; // esi
  long double v26; // st7
  CClientState *v27; // eax
  CClientState *v28; // eax
  long double v29; // st7
  CJob_vtbl *v30; // eax
  CJob_vtbl *v31; // ebx
  long double v32; // st7
  bool v33; // al
  CJob *v34; // esi
  int m_status; // eax
  vgui::PropertyPage *v37; // ecx
  float v38; // xmm1_4
  int v39; // eax
  float dt; // [esp+88h] [ebp-40h]
  const CCommand *v41; // [esp+8Ch] [ebp-3Ch]
  const CCommand *v42; // [esp+8Ch] [ebp-3Ch]
  CJob *v43; // [esp+ACh] [ebp-1Ch] BYREF
  int saveTick; // [esp+B0h] [ebp-18h]
  CMDLCacheCoarseCriticalSection cacheCoarseCriticalSection; // [esp+B4h] [ebp-14h]
  float bFinalTick; // [esp+B8h] [ebp-10h]
  float prevremainder; // [esp+BCh] [ebp-Ch]
  CClientState *BaseLocalClient; // [esp+C0h] [ebp-8h]
  bool shouldrender; // [esp+C7h] [ebp-1h]

  BeginCoarseLock = (void (*)(void))g_pMDLCache->BeginCoarseLock;
  cacheCoarseCriticalSection.m_pCache = g_pMDLCache;
  BeginCoarseLock();
  BaseLocalClient = GetBaseLocalClient();
  if ( host_checkheap )
  {
    _heapchk(args: v41);
    if ( v2 != -2 )
      Sys_Error(error: "_Host_RunFrame (top):  _heapchk() != _HEAPOK\n");
  }
  if ( mem_incremental_compact_rate.m_pParent->m_Value.m_fValue > 0.0 )
  {
    v3 = _Plat_FloatTime();
    if ( v3 - timeLastMemCompact > mem_incremental_compact_rate.m_pParent->m_Value.m_fValue )
    {
      timeLastMemCompact = v3;
      _g_pMemAlloc->CompactIncremental(this: _g_pMemAlloc);
    }
  }
  if ( host_Sleep.m_pParent != nullptr )
  {
    m_nValue = host_Sleep.m_pParent->m_Value.m_nValue;
    if ( m_nValue != 0 )
      Sys_Sleep(msec: m_nValue);
  }
  if ( g_iVCRPlaybackSleepInterval != 0 )
    Sys_Sleep(msec: g_iVCRPlaybackSleepInterval);
  v5 = MapReslistGenerator();
  CMapReslistGenerator::RunFrame(this: v5);
  if ( _setjmp3(a1: host_enddemo, a2: 0, a3: v41) != 0 )
  {
    cacheCoarseCriticalSection.m_pCache->EndCoarseLock(this: cacheCoarseCriticalSection.m_pCache);
    return;
  }
  Host_AccumulateTime(dt: time);
  _Host_SetGlobalTime();
  shouldrender = !sv.m_bIsDedicated;
  prevremainder = host_remainder;
  if ( host_remainder < 0.0 )
    prevremainder = 0.0;
  if ( demoplayer->IsPlaybackPaused(this: demoplayer) )
  {
    v6 = host_remainder;
  }
  else
  {
    v6 = host_frametime + host_remainder;
    host_remainder = host_frametime + host_remainder;
  }
  v7 = 0;
  if ( sv_alternateticks.m_pParent == nullptr || sv_alternateticks.m_pParent->m_Value.m_nValue == 0 )
    goto LABEL_24;
  if ( GetBaseLocalClient()->m_nMaxClients != 1 )
  {
    v6 = host_remainder;
LABEL_24:
    interval_per_tick = host_state.interval_per_tick;
    v10 = 0;
    v9 = host_state.interval_per_tick;
    goto LABEL_25;
  }
  interval_per_tick = host_state.interval_per_tick;
  v6 = host_remainder;
  v9 = host_state.interval_per_tick * 2.0;
  v10 = 1;
LABEL_25:
  bFinalTick = v9;
  if ( v6 >= v9 )
  {
    v7 = (int)(float)(v6 / interval_per_tick);
    if ( v10 != 0 )
      v7 = ((g_ServerGlobalVariables.tickcount + v7) & 0xFFFFFFFE) - g_ServerGlobalVariables.tickcount;
    host_remainder = v6 - (float)((float)v7 * interval_per_tick);
  }
  g_pMDLCache->MarkFrame(this: g_pMDLCache);
  if ( host_print_frame_times.m_pParent != nullptr && host_print_frame_times.m_pParent->m_Value.m_nValue != 0 )
    PrintHostFrameTimes(nNumTicks: v7, flHostRemainder: host_remainder, flMinimumTickInterval: bFinalTick);
  if ( fs_enable_stats.m_pParent != nullptr && fs_enable_stats.m_pParent->m_Value.m_nValue != 0 )
    PrintFsStats();
  g_HostTimes.starttime[6] = _Plat_FloatTime();
  Cbuf_Execute();
  if ( NET_IsDedicated() && !NET_IsMultiplayer() )
    NET_SetMultiplayer(multiplayer: true);
  v12 = _Plat_FloatTime();
  v13 = BaseLocalClient;
  g_ServerGlobalVariables.interpolation_amount = 0.0;
  g_ClientGlobalVariables.interpolation_amount = 0.0;
  g_HostTimes.deltas[6] = v12 - g_HostTimes.starttime[6] + g_HostTimes.deltas[6];
  BaseLocalClient->insimulation = true;
  host_frameticks = v7;
  host_currentframetick = 0;
  LOBYTE(v11) = v13->m_nSignonState == 6 && scr_nextdrawtick == 0;
  g_pEngineToolInternal->SetIsInGame(this: g_pEngineToolInternal, a2: v11);
  bFinalTick = 0.0;
  if ( g_bThreadedEngine )
  {
    v18 = numticks_last_frame;
    v13->m_tickRemainder = host_remainder_last_frame;
    v13->m_frameTime = last_frame_time;
    if ( g_ClientDLL != nullptr )
      ((void (__stdcall *)(_DWORD))g_ClientDLL->IN_SetSampleTime)(a1: LODWORD(last_frame_time));
    v19 = 0;
    last_frame_time = host_frametime;
    g_ClientGlobalVariables.simTicksThisFrame = v18;
    g_ServerGlobalVariables.simTicksThisFrame = v7;
    for ( g_ServerGlobalVariables.tickcount = sv.m_nTickCount; v19 < v18; ++v19 )
    {
      v20 = _Plat_FloatTime();
      NET_RunFrame(realtime: v20);
      LOBYTE(bFinalTick) = v19 == v18 - 1;
      if ( NET_IsDedicated() && !NET_IsMultiplayer() )
        NET_SetMultiplayer(multiplayer: true);
      g_ClientGlobalVariables.tickcount = BaseLocalClient->m_ClockDriftMgr.m_nClientTick;
      CL_CheckClientState();
      NET_SendQueuedPackets();
      if ( !sv.m_bIsDedicated )
        _Host_RunFrame_Client(framefinished: SLOBYTE(bFinalTick));
      toolframework->Think(this: toolframework, a2: LODWORD(bFinalTick));
    }
    CVProfile::EnterScope(
      this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
      a2: "CL_ProcessVoiceData",
      a3: 0,
      a4: "Networking",
      a5: false,
      a6: 4);
    if ( Voice_Idle(frametime: 0.016666668) )
      CL_SendVoicePacket(bFinal: false);
    CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
    if ( v18 == 0 && (demoplayer->IsPlayingTimeDemo(this: demoplayer) || demoplayer->IsSkipping(this: demoplayer)) )
      _Host_RunFrame_Client(framefinished: true);
    GetBaseLocalClient()->insimulation = false;
    v21 = GetBaseLocalClient();
    g_ClientGlobalVariables.curtime = CClientState::GetTime(this: v21);
    v22 = GetBaseLocalClient();
    g_ClientGlobalVariables.frametime = CClientState::GetFrameTime(this: v22);
    g_ClientGlobalVariables.interpolation_amount = BaseLocalClient->m_tickRemainder / host_state.interval_per_tick;
    CL_RunPrediction(reason: PREDICTION_NORMAL);
    CL_ApplyAddAngle();
    GetBaseLocalClient()->insimulation = true;
    v23 = GetBaseLocalClient();
    g_ClientGlobalVariables.curtime = CClientState::GetTime(this: v23);
    v24 = GetBaseLocalClient();
    g_ClientGlobalVariables.frametime = CClientState::GetFrameTime(this: v24);
    v25 = 0;
    for ( saveTick = g_ClientGlobalVariables.tickcount; v25 < v7; ++v25 )
    {
      ++host_currentframetick;
      g_ClientGlobalVariables.tickcount = ++host_tickcount;
      _Host_RunFrame_Input(accumulated_extra_samples: prevremainder, bFinalTick: v25 == v7 - 1);
      prevremainder = 0.0;
      v26 = _Plat_FloatTime();
      NET_RunFrame(realtime: v26);
    }
    if ( v7 == 0 )
    {
      CVProfile::EnterScope(
        this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
        a2: "_Host_ProcessVoice_Server",
        a3: 0,
        a4: "Game",
        a5: false,
        a6: 4);
      SV_ProcessVoice();
      CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
    }
    GetBaseLocalClient()->insimulation = false;
    v27 = GetBaseLocalClient();
    g_ClientGlobalVariables.curtime = CClientState::GetTime(this: v27);
    v28 = GetBaseLocalClient();
    g_ClientGlobalVariables.frametime = CClientState::GetFrameTime(this: v28);
    CL_ExtraMouseUpdate(frametime: g_ClientGlobalVariables.frametime);
    g_ClientGlobalVariables.tickcount = saveTick;
    numticks_last_frame = v7;
    host_remainder_last_frame = host_remainder;
    v29 = _Plat_FloatTime();
    NET_SetTime(realtime: v29);
    v14 = (CJob *)MemAlloc_Alloc(nSize: 0x44u);
    if ( v14 != nullptr )
    {
      v30 = (CJob_vtbl *)MemAlloc_Alloc(nSize: 0x18u);
      if ( v30 != nullptr )
      {
        v30->DoExecute = (int (__thiscall *)(CJob *))1;
        v30->DoCleanup = (void (__thiscall *)(CJob *))v7;
        v30->AddRef = (int (__thiscall *)(struct CJob *))&CFunctor1<void (__cdecl *)(int),int,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>>::`vftable'{for `CFunctor'};
        v30->Describe = (const char *(__thiscall *)(CJob *))&CFunctor1<void (__cdecl *)(int),int,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>>::`vftable'{for `CRefCountServiceBase<1,CRefMT>'};
        v30->DoAbort = (int (__thiscall *)(CJob *, bool))_Host_RunFrame_Server_Async;
        v31 = v30;
      }
      else
      {
        v31 = nullptr;
      }
      v14->m_iRefs = 1;
      v14->m_priority = JP_NORMAL;
      v14->CRefCounted1<IRefCounted,CRefCountServiceBase<1,CRefMT> >::IRefCounted::__vftable = (CJob_vtbl *)&CJob::`vftable'{for `IRefCounted'};
      v14->CRefCounted1<IRefCounted,CRefCountServiceBase<1,CRefMT> >::CRefCountServiceBase<1,CRefMT>::__vftable = (CRefCountServiceBase<1,CRefMT>_vtbl *)&CJob::`vftable'{for `CRefCountServiceBase<1,CRefMT>'};
      v14->m_status = 4;
      v14->m_mutex.m_ownerID = 0;
      v14->m_mutex.m_depth = 0;
      *(_WORD *)&v14->m_flags = -256;
      v14->m_ThreadPoolData = (ThreadPoolData_t__ *)-1;
      v14->m_pThreadPool = nullptr;
      CThreadEvent::CThreadEvent(this: &v14->m_CompleteEvent, a2: true);
      v14->CRefCounted1<IRefCounted,CRefCountServiceBase<1,CRefMT> >::IRefCounted::__vftable = (CJob_vtbl *)&CFunctorJob::`vftable'{for `IRefCounted'};
      v14->CRefCounted1<IRefCounted,CRefCountServiceBase<1,CRefMT> >::CRefCountServiceBase<1,CRefMT>::__vftable = (CRefCountServiceBase<1,CRefMT>_vtbl *)&CFunctorJob::`vftable'{for `CRefCountServiceBase<1,CRefMT>'};
      v14[1].CRefCounted1<IRefCounted,CRefCountServiceBase<1,CRefMT> >::IRefCounted::__vftable = v31;
      LOBYTE(v14[1].CRefCounted1<IRefCounted,CRefCountServiceBase<1,CRefMT> >::CRefCountServiceBase<1,CRefMT>::__vftable) = 0;
      bFinalTick = *(float *)&v14;
    }
    else
    {
      bFinalTick = 0.0;
    }
    _g_pThreadPool->AddJob(this: _g_pThreadPool, a2: (CJob *)LODWORD(bFinalTick));
  }
  else
  {
    if ( g_ClientDLL != nullptr )
      ((void (__stdcall *)(_DWORD))g_ClientDLL->IN_SetSampleTime)(a1: LODWORD(host_frametime));
    g_ClientGlobalVariables.simTicksThisFrame = 1;
    v13->m_tickRemainder = host_remainder;
    v13->m_frameTime = host_frametime;
    v14 = nullptr;
    for ( g_ServerGlobalVariables.simTicksThisFrame = 1; (int)v14 < v7; v14 = (CJob *)((char *)v14 + 1) )
    {
      v15 = _Plat_FloatTime();
      NET_RunFrame(realtime: v15);
      LOBYTE(saveTick) = v14 == (CJob *)(v7 - 1);
      if ( NET_IsDedicated() && !NET_IsMultiplayer() )
        NET_SetMultiplayer(multiplayer: true);
      ++host_tickcount;
      ++host_currentframetick;
      g_ServerGlobalVariables.tickcount = sv.m_nTickCount;
      g_ClientGlobalVariables.tickcount = BaseLocalClient->m_ClockDriftMgr.m_nClientTick;
      CL_CheckClientState();
      _Host_RunFrame_Input(accumulated_extra_samples: prevremainder, bFinalTick: saveTick);
      prevremainder = 0.0;
      _Host_RunFrame_Server(finaltick: saveTick);
      NET_SendQueuedPackets();
      if ( !sv.m_bIsDedicated )
        _Host_RunFrame_Client(framefinished: saveTick);
      toolframework->Think(this: toolframework, a2: saveTick);
    }
    CVProfile::EnterScope(
      this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
      a2: "CL_ProcessVoiceData",
      a3: 0,
      a4: "Networking",
      a5: false,
      a6: 4);
    if ( Voice_Idle(frametime: 0.016666668) )
      CL_SendVoicePacket(bFinal: false);
    CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
    if ( v7 == 0 )
    {
      CVProfile::EnterScope(
        this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
        a2: "_Host_ProcessVoice_Server",
        a3: 0,
        a4: "Game",
        a5: false,
        a6: 4);
      SV_ProcessVoice();
      CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
    }
    if ( hltv != nullptr )
      CHLTVServer::RunFrame(this: hltv);
    if ( hltvtest != nullptr )
      CHLTVTestSystem::RunFrame(this: hltvtest);
    if ( v7 == 0 && (demoplayer->IsPlayingTimeDemo(this: demoplayer) || demoplayer->IsSkipping(this: demoplayer)) )
      _Host_RunFrame_Client(framefinished: true);
    if ( !sv.m_bIsDedicated )
    {
      GetBaseLocalClient()->insimulation = false;
      v16 = GetBaseLocalClient();
      g_ClientGlobalVariables.curtime = CClientState::GetTime(this: v16);
      v17 = GetBaseLocalClient();
      g_ClientGlobalVariables.frametime = CClientState::GetFrameTime(this: v17);
      g_ClientGlobalVariables.interpolation_amount = BaseLocalClient->m_tickRemainder / host_state.interval_per_tick;
      CL_RunPrediction(reason: PREDICTION_NORMAL);
      CL_ApplyAddAngle();
      CL_ExtraMouseUpdate(frametime: g_ClientGlobalVariables.frametime);
    }
  }
  if ( g_pScaleformUI != nullptr && shouldrender )
    ((void (__stdcall *)(_DWORD))g_pScaleformUI->RunFrame)(a1: LODWORD(g_ClientGlobalVariables.frametime));
  CLog::RunFrame(this: &g_Log);
  if ( shouldrender )
  {
    _Host_RunFrame_Render(a1: (IConVar *)v14);
    _Host_RunFrame_Sound();
    if ( g_bVCRSingleStep )
      VCR_EnterPausedState();
  }
  v32 = _Plat_FloatTime();
  g_HostTimes.frametime = v32 - g_HostTimes.swaptime;
  g_HostTimes.swaptime = v32;
  CFrameTimer::ComputeFrameVariability(this: &g_HostTimes);
  g_EngineStats.m_flFrameTime = g_HostTimes.frametime;
  g_EngineStats.m_flFPSVariability = g_HostTimes.m_flFPSVariability;
  host_frametime_stddeviation = g_HostTimes.m_flFPSStdDeviationSeconds;
  if ( !sv.m_bIsDedicated )
  {
    CVProfile::EnterScope(
      this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
      a2: "_Host_RunFrame - ClientDLL_Update",
      a3: 0,
      a4: "Client Simulation",
      a5: false,
      a6: 4);
    g_HostTimes.starttime[5] = _Plat_FloatTime();
    ClientDLL_Update();
    g_HostTimes.deltas[5] = _Plat_FloatTime() - g_HostTimes.starttime[5] + g_HostTimes.deltas[5];
    CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
  }
  if ( bFinalTick != 0.0 )
  {
    CVProfile::EnterScope(
      this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
      a2: "WaitForAsyncServer",
      a3: 0,
      a4: "AsyncServer",
      a5: false,
      a6: 4);
    if ( sv.m_State < ss_active )
      v33 = GetBaseLocalClient()->m_nMaxClients == 1;
    else
      v33 = sv.m_nMaxclients <= 1;
    if ( v33 )
    {
      CJob::Execute(this: (CJob *)LODWORD(bFinalTick));
      (*(void (__thiscall **)(_DWORD))(*(_DWORD *)LODWORD(bFinalTick) + 4))(a1: LODWORD(bFinalTick));
    }
    else
    {
      CJob::WaitForFinishAndRelease(this: (CJob *)LODWORD(bFinalTick), dwTimeout: 0xFFFFFFFF);
    }
    CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
    SV_FrameExecuteThreadDeferred();
  }
  if ( g_pSoundJob != nullptr )
  {
    CVProfile::EnterScope(
      this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
      a2: "_Host_RunFrame_Sound",
      a3: 0,
      a4: "Sound",
      a5: false,
      a6: 4);
    v34 = g_pSoundJob;
    if ( g_pSoundJob != nullptr )
    {
      m_status = g_pSoundJob->m_status;
      if ( m_status == 1 || m_status == 2 || m_status == 4 )
      {
        v43 = g_pSoundJob;
        _g_pThreadPool->YieldWait(this: _g_pThreadPool, a2: &v43, a3: 1, a4: true, a5: -1u);
      }
      v34->Release(this: v34);
    }
    g_pSoundJob = nullptr;
    CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
  }
  CFrameTimer::MarkFrame(this: &g_HostTimes);
  dt = g_HostTimes.m_flFPSVariability;
  CDemoPlayer::MarkFrame(this: g_pClientDemoPlayer, flFPSVariability: dt);
  CColorBalanceUIPanel::Init(this: v37);
  ++host_framecount;
  if ( !demoplayer->IsPlaybackPaused(this: demoplayer) )
    host_time = (float)((float)host_tickcount * host_state.interval_per_tick) + BaseLocalClient->m_tickRemainder;
  v38 = host_frametime;
  if ( host_frametime >= 0.000099999997 )
  {
    if ( host_frametime > 1.0 )
      v38 = 1.0;
  }
  else
  {
    v38 = 0.000099999997;
  }
  g_fFramesPerSecond = (float)((float)(1.0 / v38) * 0.10000002) + (float)(g_fFramesPerSecond * 0.89999998);
  if ( host_checkheap )
  {
    _heapchk(args: v42);
    if ( v39 != -2 )
      Sys_Error(error: "_Host_RunFrame (bottom):  _heapchk() != _HEAPOK\n");
  }
  Host_CheckDumpMemoryStats();
  CTestScriptMgr::CheckPoint(this: &g_TestScriptMgr, pName: "frame_end");
  Host_ShowIPCCallCount();
  cacheCoarseCriticalSection.m_pCache->EndCoarseLock(this: cacheCoarseCriticalSection.m_pCache);
}

//------------------------------------------------------------------------------
// Address: 0x10189810
// Name: void Host_RunFrame(float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Host_RunFrame(float time)
{
  int m_nValue; // eax
  int v2; // eax
  double v3; // st7
  long double v4; // st6
  int NumClients; // eax
  long double v6; // [esp+8h] [ebp-18h]
  double time1; // [esp+18h] [ebp-8h]

  if ( scr_drawloading
    || sv.m_State < ss_active
    || GetBaseLocalClient()->m_nSignonState != 6
    || sv.m_bLoadgame
    || (host_thread_mode.m_pParent == nullptr
      ? (m_nValue = 0)
      : (m_nValue = host_thread_mode.m_pParent->m_Value.m_nValue),
        m_nValue == 0) )
  {
    g_bThreadedEngine = false;
  }
  else
  {
    v2 = m_nValue - 1;
    if ( v2 != 0 )
    {
      if ( v2 == 1 )
        g_bThreadedEngine = true;
    }
    else
    {
      g_bThreadedEngine = _g_pThreadPool->NumThreads(this: _g_pThreadPool) > 0;
    }
  }
  if ( host_profile.m_pParent != nullptr && host_profile.m_pParent->m_Value.m_nValue != 0 )
  {
    time1 = _Plat_FloatTime();
    _Host_RunFrame(time);
    v3 = _Plat_FloatTime();
    ++timecount;
    v4 = v3 - time1 + timetotal;
    timetotal = v4;
    if ( timecount >= 1000 )
    {
      v6 = 1000.0 / (v3 - timestart);
      NumClients = CBaseServer::GetNumClients(this: &sv);
      ConMsg(a1: "host_profile : %i clients, %.1f msec, %.1f fps\n", NumClients, (double)v4, (double)v6);
      timetotal = 0.0;
      timecount = 0;
      timestart = v3;
    }
  }
  else
  {
    _Host_RunFrame(time);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10189940
// Name: void Host_Init(bool)
// Source: json
//------------------------------------------------------------------------------
void __usercall Host_Init(int a1@<ebx>, int a2@<edi>, int a3@<esi>, bool bDedicated)
{
  int v4; // eax
  CThread *v5; // eax
  CDebugInputThread *v6; // esi
  int v7; // eax
  vgui::PropertyPage *v8; // ecx
  int v9; // eax
  int v10; // eax
  int v11; // eax
  int v12; // eax
  float v13; // esi
  int v14; // eax
  IStaticPropMgrEngine *v15; // eax
  IEngineVGuiInternal *v16; // eax
  IEngineVGuiInternal *v17; // eax
  IStaticPropMgrEngine *v18; // eax
  EUniverse SteamUniverse; // eax
  CEngineVoiceStub *EngineVoiceSteam; // esi
  IMatchExtensions *v21; // eax
  vgui::CTreeViewListControl *v22; // ecx
  ECommandTarget_t TraceType; // eax
  vgui::CTreeViewListControl *v24; // ecx
  ECommandTarget_t v25; // eax
  int v26; // eax
  int v27; // eax
  int v28; // eax
  int v29; // eax
  int v30; // eax
  CMapReslistGenerator *v31; // eax
  int v32; // eax
  CDevShotGenerator *v33; // eax
  int v34; // eax
  vgui::PropertyPage *v35; // ecx
  IMatRenderContext *v36; // eax
  IMatRenderContext *v37; // esi
  int v38; // eax
  vgui::CTreeViewListControl *v39; // ecx
  ECommandTarget_t v40; // eax
  ThreadPoolStartParams_t startParams; // [esp+88h] [ebp-118h] BYREF
  float flTimeToSeed; // [esp+19Ch] [ebp-4h]

  realtime = 0.0;
  v4 = _CommandLine();
  if ( (*(int (__thiscall **)(int, const char *, int, int, int))(*(_DWORD *)v4 + 40))(
         a1: v4,
         a2: "-pme",
         a3: a2,
         a4: a3,
         a5: a1) != 0 )
    s_bInitPME = true;
  startParams.nThreads = -1;
  startParams.nStackSize = -1;
  startParams.fDistribute = TRS_NONE;
  startParams.iThreadPriority = -32768;
  *((_BYTE *)&startParams + 272) &= 0xFCu;
  if ( (*((_BYTE *)&startParams + 272) & 2) != 0 )
    qmemcpy(startParams.iAffinityTable, nullptr, sizeof(startParams.iAffinityTable));
  v5 = (CThread *)MemAlloc_Alloc(nSize: 0x9Cu);
  v6 = (CDebugInputThread *)v5;
  if ( v5 != nullptr )
  {
    CThread::CThread(this: v5);
    v6->__vftable = (CDebugInputThread_vtbl *)&CDebugInputThread::`vftable';
    CThreadMutex::CThreadMutex(this: &v6->m_mx);
    CUtlString::CUtlString(this: &v6->m_inputString);
    v6->m_bStop = false;
  }
  else
  {
    v6 = nullptr;
  }
  g_pDebugInputThread = v6;
  CThread::SetName(this: v6, a2: "Debug Input");
  g_pDebugInputThread->Start(this: g_pDebugInputThread, a2: 0, a3: PRIORITY_HIGH);
  v7 = _CommandLine();
  if ( (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v7 + 40))(a1: v7, a2: "-tslist") != 0 )
  {
    _Msg(a1: "Running TSList tests\n");
    _RunTSListTests(a1: 10000, a2: 1);
    _Msg(a1: "Running TSQueue tests\n");
    _RunTSQueueTests(a1: 10000, a2: 1);
    _Msg(a1: "Running Thread Pool tests\n");
    _RunThreadPoolTests();
  }
  if ( !bDedicated )
    startParams.fDistribute = TRS_TRUE;
  if ( _g_pThreadPool != nullptr )
    _g_pThreadPool->Start_2(this: _g_pThreadPool, a2: &startParams);
  host_state.interval_per_tick = 0.016666668;
  InstallBitBufErrorHandler();
  InstallConVarHook();
  TraceInit(i: "Con_Init()", s: "Con_Shutdown()", listnum: 0);
  Con_Init();
  TraceInit(i: "Memory_Init()", s: "Memory_Shutdown()", listnum: 0);
  Memory_Init();
  TraceInit(i: "Cbuf_Init()", s: "Cbuf_Shutdown()", listnum: 0);
  Cbuf_Init();
  TraceInit(i: "Cmd_Init()", s: "Cmd_Shutdown()", listnum: 0);
  Cmd_Init();
  TraceInit(i: "g_pCVar->Init()", s: "g_pCVar->Shutdown()", listnum: 0);
  g_pCVar->Init(this: g_pCVar);
  TraceInit(i: "V_Init()", s: "V_Shutdown()", listnum: 0);
  V_Init();
  TraceInit(i: "COM_Init()", s: "COM_Shutdown()", listnum: 0);
  COM_Init();
  TraceInit(i: "saverestore->Init()", s: "saverestore->Shutdown()", listnum: 0);
  saverestore->Init(this: saverestore);
  TraceInit(i: "Filter_Init()", s: "Filter_Shutdown()", listnum: 0);
  CColorBalanceUIPanel::Init(this: v8);
  TraceInit(i: "Key_Init()", s: "Key_Shutdown()", listnum: 0);
  Key_Init();
  v9 = _CommandLine();
  if ( (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v9 + 40))(a1: v9, a2: "-dev") != 0
    || (v10 = _CommandLine(),
        (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v10 + 40))(a1: v10, a2: "-allowdebug") != 0)
    && (v11 = _CommandLine(),
        (*(int (__thiscall **)(int, const char **))(*(_DWORD *)v11 + 40))(a1: v11, a2: &stru_10369C78.m_ppArgv[63]) == 0) )
  {
    CLoaderMemAlloc::CrtIsValidPointer(this: (ConVar *)&sv_cheats.IConVar, value: 1);
    CLoaderMemAlloc::CrtIsValidPointer(this: (ConVar *)&developer.IConVar, value: 1);
  }
  v12 = _CommandLine();
  if ( (*(int (__thiscall **)(int, const char **))(*(_DWORD *)v12 + 40))(a1: v12, a2: &stru_10369C78.m_ppArgv[59]) != 0 )
    Sys_NoCrashDialog();
  flTimeToSeed = _Plat_FloatTime();
  v13 = fabs(flTimeToSeed);
  _RandomSeed(a1: LODWORD(flTimeToSeed) & 0x7FFFFFFF);
  DevMsg(a1: (const char *)&stru_10369C78.m_ppArgv[47], v13, flTimeToSeed);
  TraceInit(i: (const char *)&stru_10369C78.m_ppArgv[32], s: (const char *)&stru_10369C78.m_ppArgv[39], listnum: 0);
  g_pSteamSocketMgr->Init(this: g_pSteamSocketMgr);
  TraceInit(i: (const char *)&stru_10369C78.m_ppArgv[22], s: (const char *)&stru_10369C78.m_ppArgv[28], listnum: 0);
  NET_Init(a1: 0, bIsDedicated: bDedicated);
  TraceInit(i: (const char *)&stru_10369C78.m_ppArgv[7], s: (const char *)&stru_10369C78.m_ppArgv[14], listnum: 0);
  CGameEventManager::Init(this: g_GameEventManager);
  TraceInit(i: &stru_10369C78.m_pArgvBuffer[500], s: (const char *)&stru_10369C78.m_ppArgv[3], listnum: 0);
  CGameServer::Init(this: &sv, isDedicated: bDedicated);
  v14 = _CommandLine();
  if ( (*(int (__thiscall **)(int, char *))(*(_DWORD *)v14 + 40))(a1: v14, a2: &stru_10369C78.m_pArgvBuffer[488]) == 0 )
    SV_InitGameDLL();
  TraceInit(i: &stru_10369C78.m_pArgvBuffer[444], s: &stru_10369C78.m_pArgvBuffer[464], listnum: 0);
  g_pMaster->Init(this: g_pMaster);
  TraceInit(i: &stru_10369C78.m_pArgvBuffer[408], s: &stru_10369C78.m_pArgvBuffer[424], listnum: 0);
  CLog::Init(this: &g_Log);
  TraceInit(i: &stru_10369C78.m_pArgvBuffer[380], s: &stru_10369C78.m_pArgvBuffer[392], listnum: 0);
  _ConDMsg(a1: &stru_10369C78.m_pArgvBuffer[364], (double)host_parms.memsize * 0.00000095367432);
  Host_CheckGore();
  if ( bDedicated )
  {
    TraceInit(i: &stru_10369C78.m_pArgvBuffer[284], s: &stru_10369C78.m_pArgvBuffer[308], listnum: 0);
    InitMaterialSystem();
    TraceInit(i: &stru_10369C78.m_pArgvBuffer[64], s: &stru_10369C78.m_pArgvBuffer[84], listnum: 0);
    modelloader->Init(this: modelloader);
    TraceInit(i: &stru_10369C78.m_pArgvBuffer[12], s: &stru_10369C78.m_pArgvBuffer[36], listnum: 0);
    v18 = StaticPropMgr();
    v18->Init(this: v18);
    TraceInit(i: &stru_10369C78.m_pArgSBuffer[480], s: &stru_10369C78.m_pArgSBuffer[500], listnum: 0);
    InitStudioRender();
    TraceInit(i: &stru_10369C78.m_pArgSBuffer[420], s: &stru_10369C78.m_pArgSBuffer[448], listnum: 0);
    g_pMatchFramework->Init(this: g_pMatchFramework);
    TraceInit(i: &stru_10369C78.m_pArgSBuffer[188], s: &stru_10369C78.m_pArgSBuffer[204], listnum: 0);
    Decal_Init();
    GetBaseLocalClient()->m_nSignonState = 0;
  }
  else
  {
    TraceInit(i: &stru_10369C78.m_pArgvBuffer[336], s: &stru_10369C78.m_pArgvBuffer[348], listnum: 0);
    CL_Init();
    TraceInit(i: &stru_10369C78.m_pArgvBuffer[284], s: &stru_10369C78.m_pArgvBuffer[308], listnum: 0);
    InitMaterialSystem();
    TraceInit(i: &stru_10369C78.m_pArgvBuffer[112], s: &stru_10369C78.m_pArgvBuffer[228], listnum: 0);
    v13 = *(float *)&g_pScaleformUI;
    ((void (__cdecl *)(int, const char *))g_pScaleformUI->InitSlot)(a1: 1, a2: "resource/flash/MainUIRootMovie.swf");
    (*(void (__thiscall **)(float, const char *))(*(_DWORD *)LODWORD(v13) + 120))(
      a1: COERCE_FLOAT(LODWORD(v13)),
      a2: "resource/flash/Cursor.swf");
    TraceInit(i: &stru_10369C78.m_pArgvBuffer[64], s: &stru_10369C78.m_pArgvBuffer[84], listnum: 0);
    modelloader->Init(this: modelloader);
    TraceInit(i: &stru_10369C78.m_pArgvBuffer[12], s: &stru_10369C78.m_pArgvBuffer[36], listnum: 0);
    v15 = StaticPropMgr();
    v15->Init(this: v15);
    TraceInit(i: &stru_10369C78.m_pArgSBuffer[480], s: &stru_10369C78.m_pArgSBuffer[500], listnum: 0);
    InitStudioRender();
    TraceInit(i: &stru_10369C78.m_pArgSBuffer[420], s: &stru_10369C78.m_pArgSBuffer[448], listnum: 0);
    g_pMatchFramework->Init(this: g_pMatchFramework);
    TraceInit(i: &stru_10369C78.m_pArgSBuffer[368], s: &stru_10369C78.m_pArgSBuffer[392], listnum: 0);
    v16 = EngineVGui();
    v16->Init(this: v16);
    TraceInit(i: &stru_10369C78.m_pArgSBuffer[324], s: &stru_10369C78.m_pArgSBuffer[344], listnum: 0);
    TextMessageInit();
    TraceInit(i: &stru_10369C78.m_pArgSBuffer[280], s: &stru_10369C78.m_pArgSBuffer[300], listnum: 0);
    ClientDLL_Init();
    TraceInit(i: &stru_10369C78.m_pArgSBuffer[252], s: &stru_10369C78.m_pArgSBuffer[264], listnum: 0);
    SCR_Init();
    TraceInit(i: &stru_10369C78.m_pArgSBuffer[224], s: &stru_10369C78.m_pArgSBuffer[236], listnum: 0);
    R_Init();
    TraceInit(i: &stru_10369C78.m_pArgSBuffer[188], s: &stru_10369C78.m_pArgSBuffer[204], listnum: 0);
    Decal_Init();
    v17 = EngineVGui();
    v17->Connect(this: v17);
  }
  SteamUniverse = GetSteamUniverse();
  if ( SteamUniverse == k_EUniverseBeta || SteamUniverse == k_EUniverseDev )
    CCvarUtilities::EnableDevCvars(this: cv);
  *(_WORD *)g_bConfigCfgExecuted = 0;
  Host_ReadConfiguration(a1: (int)_CommandLine, a2: 0, a3: SLODWORD(v13), iController: -1);
  TraceInit(i: &stru_10369C78.m_pArgSBuffer[160], s: &stru_10369C78.m_pArgSBuffer[172], listnum: 0);
  S_Init();
  EngineVoiceSteam = (CEngineVoiceStub *)Audio_GetEngineVoiceSteam();
  if ( EngineVoiceSteam == nullptr )
  {
    _Warning(a1: &stru_10369C78.m_pArgSBuffer[124]);
    EngineVoiceSteam = Audio_GetEngineVoiceStub();
  }
  v21 = g_pMatchFramework->GetMatchExtensions(this: g_pMatchFramework);
  v21->RegisterExtensionInterface(this: v21, a2: &stru_10369C78.m_pArgSBuffer[108], a3: EngineVoiceSteam);
  TraceType = CTraceFilter::GetTraceType(this: v22);
  Cbuf_AddText(eTarget: TraceType, pText: &stru_10369C78.m_pArgSBuffer[92], nTickDelay: 0);
  if ( g_pFileSystem->FileExists(
         this: &g_pFileSystem->IBaseFileSystem,
         a2: &stru_10369C78.m_pArgSBuffer[64],
         a3: nullptr) )
  {
    v25 = CTraceFilter::GetTraceType(this: v24);
    Cbuf_AddText(eTarget: v25, pText: &stru_10369C78.m_pArgSBuffer[36], nTickDelay: 0);
  }
  Host_InitProcessor();
  Hunk_AllocName(size: 0, name: &stru_10369C78.m_pArgSBuffer[16], bClear: true);
  host_hunklevel = Hunk_LowMark();
  v26 = _CommandLine();
  if ( (*(int (__thiscall **)(int, char *))(*(_DWORD *)v26 + 40))(a1: v26, a2: &stru_10369C78.m_pArgSBuffer[4]) != 0 )
  {
    g_nMaterialSystemThread = 1;
    g_nServerThread = 0;
  }
  g_bAllowThreadedSound = false;
  g_pMaterialSystem->AllowThreading(this: g_pMaterialSystem, a2: false, a3: g_nMaterialSystemThread);
  host_initialized = true;
  v27 = _CommandLine();
  v28 = (*(int (__thiscall **)(int))(*(_DWORD *)v27 + 40))(a1: v27);
  host_checkheap = v28 != 0;
  if ( v28 != 0 )
  {
    _heapchk(args: &stru_10369C78);
    if ( v29 != -2 )
      Sys_Error(error: "Host_Init:  _heapchk() != _HEAPOK\n");
  }
  HostState_Init();
  v30 = _CommandLine();
  if ( (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v30 + 40))(a1: v30, a2: "-makereslists") != 0 )
  {
    v31 = MapReslistGenerator();
    CMapReslistGenerator::StartReslistGeneration(this: v31);
  }
  v32 = _CommandLine();
  if ( (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v32 + 40))(a1: v32, a2: "-makedevshots") != 0 )
  {
    v33 = DevShotGenerator();
    CDevShotGenerator::StartDevShotGeneration(this: v33);
  }
  if ( sv.m_bIsDedicated )
  {
    v34 = _CommandLine();
    (*(void (__thiscall **)(int, const char *))(*(_DWORD *)v34 + 40))(a1: v34, a2: "-phonehome");
  }
  Host_PostInit();
  CColorBalanceUIPanel::Init(this: v35);
  v36 = g_pMaterialSystem->GetRenderContext(this: g_pMaterialSystem);
  v37 = v36;
  if ( v36 != nullptr )
    v36->BeginRender(this: v36);
  v37->SetNonInteractiveTempFullscreenBuffer(this: v37, a2: nullptr, a3: MATERIAL_NON_INTERACTIVE_MODE_STARTUP);
  ((void (__thiscall *)(IMatRenderContext *, _DWORD, _DWORD, _DWORD, _DWORD))v37->SetNonInteractivePacifierTexture)(
    a1: v37,
    a2: 0,
    a3: 0.0,
    a4: 0.0,
    a5: 0.0);
  ((void (__thiscall *)(IMatRenderContext *, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD))v37->SetNonInteractiveLogoTexture)(
    a1: v37,
    a2: 0,
    a3: 0.0,
    a4: 0.0,
    a5: 0.0,
    a6: 0.0);
  g_pMaterialSystem->FinishRenderTargetAllocation(this: g_pMaterialSystem);
  v38 = _CommandLine();
  if ( (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v38 + 40))(a1: v38, a2: "-profileinit") != 0 )
  {
    v40 = CTraceFilter::GetTraceType(this: v39);
    Cbuf_AddText(eTarget: v40, pText: "quit\n", nTickDelay: 0);
  }
  v37->EndRender(this: v37);
  v37->Release(this: v37);
}

//------------------------------------------------------------------------------
// Address: 0x1018A1F0
// Name: void Host_Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x1018A720
// Name: void ReserveThreads(int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ReserveThreads(int nToReserve)
{
  int v1; // eax
  int v2; // edi
  CFunctor *v3; // eax

  v1 = _g_pThreadPool->NumThreads(this: _g_pThreadPool);
  v2 = nToReserve;
  if ( nToReserve >= 0 )
  {
    if ( nToReserve > v1 )
      v2 = v1;
  }
  else
  {
    v2 = 0;
  }
  CThreadEvent::Set(this: &g_ReleaseThreadReservation);
  while ( g_NumReservedThreads.m_value != 0 )
    _ThreadSleep(a1: 0);
  CThreadEvent::Reset(this: &g_ReleaseThreadReservation);
  while ( v2 != 0 )
  {
    --v2;
    _InterlockedExchangeAdd(&g_NumReservedThreads.m_value, 1u);
    v3 = (CFunctor *)MemAlloc_Alloc(nSize: 0x14u);
    if ( v3 != nullptr )
    {
      v3[1].m_nUserID = 1;
      v3->__vftable = (CFunctor_vtbl *)&CFunctor0<void (__cdecl *)(void),CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>>::`vftable'{for `CFunctor'};
      v3[1].__vftable = (CFunctor_vtbl *)&CFunctor0<void (__cdecl *)(void),CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>>::`vftable'{for `CRefCountServiceBase<1,CRefMT>'};
      v3[2].__vftable = (CFunctor_vtbl *)ThreadPoolReserverFunction;
    }
    else
    {
      v3 = nullptr;
    }
    _g_pThreadPool->AddFunctorInternal(this: _g_pThreadPool, a2: v3, a3: (CJob **)&nToReserve, a4: nullptr, a5: 8u);
    (*(void (__thiscall **)(int))(*(_DWORD *)nToReserve + 4))(a1: nToReserve);
  }
  _Msg(a1: "%d threads being reserved\n", g_NumReservedThreads.m_value);
}

//------------------------------------------------------------------------------
// Address: 0x1018A800
// Name: void OnChangeThreadReserve(class IConVar __near *,char const __near *,float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl OnChangeThreadReserve()
{
  if ( threadpool_reserve.m_pParent != nullptr )
    ReserveThreads(nToReserve: threadpool_reserve.m_pParent->m_Value.m_nValue);
  else
    ReserveThreads(nToReserve: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1018A820
// Name: threadpool_cycle_reserve
// Source: json
//------------------------------------------------------------------------------
void __cdecl threadpool_cycle_reserve()
{
  int v0; // ecx
  int v1; // esi

  v0 = _g_pThreadPool->NumThreads(this: _g_pThreadPool) + 1;
  v1 = 2 * (v0 / (v0 - g_NumReservedThreads.m_value));
  if ( v1 <= v0 )
    ReserveThreads(nToReserve: v0 - v0 / v1);
  else
    ReserveThreads(nToReserve: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1018A870
// Name: public: virtual void CHostSubscribeForProfileEvents::OnEvent(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CHostSubscribeForProfileEvents::OnEvent(
        CHostSubscribeForProfileEvents *this@<ecx>,
        int a2@<ebx>,
        KeyValues *pEvent)
{
  const char *Name; // edi
  int Int; // eax

  Name = KeyValues::GetName(this: pEvent);
  if ( _V_stricmp(s1: Name, s2: "OnProfileDataLoaded") == 0 )
  {
    Int = KeyValues::GetInt(this: pEvent, keyName: "iController", defaultValue: 0);
    Host_ReadConfiguration(a1: a2, a2: (int)Name, a3: (int)pEvent, iController: Int);
  }
  _V_stricmp(s1: Name, s2: "OnProfileDataLoadFailed");
  _V_stricmp(s1: Name, s2: "OnProfileDataWriteFailed");
}

//------------------------------------------------------------------------------
// Address: 0x1018A8D0
// Name: void Host_BuildUserInfoUpdateMessage(int,class CUtlVector<struct NetMessageCvar_t,class CUtlMemory<struct NetMessageCvar_t,int>> __near &,bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Host_BuildUserInfoUpdateMessage(
        int nSplitScreenSlot,
        CUtlVector<NetMessageCvar_t,CUtlMemory<NetMessageCvar_t,int> > *rCvarList,
        bool nonDefault)
{
  ICvar::ICVarIteratorInternal *v3; // ebx
  ConVar *v4; // esi
  const char *m_pszString; // eax
  const char *Default; // eax
  const char *v7; // eax
  const char *v8; // eax
  const char *v9; // eax
  const char *v10; // [esp-10h] [ebp-220h]
  NetMessageCvar_t acvar; // [esp+0h] [ebp-210h] BYREF
  int nDisallowedFlags; // [esp+208h] [ebp-8h]
  int nRequiredFlags; // [esp+20Ch] [ebp-4h]

  nRequiredFlags = 512;
  nDisallowedFlags = 0x40000;
  if ( nSplitScreenSlot != 0 )
  {
    nDisallowedFlags = 0x8000;
    nRequiredFlags = 262656;
  }
  if ( Host_CountVariablesWithFlags(flags: nRequiredFlags, nonDefault) > 0 )
  {
    v3 = g_pCVar->FactoryInternalIterator(this: g_pCVar);
    v3->SetFirst(this: v3);
    while ( v3->IsValid(this: v3) )
    {
      v4 = (ConVar *)v3->Get(this: v3);
      if ( !v4->IsCommand(this: v4)
        && v4->IsFlagSet(this: v4, a2: nRequiredFlags)
        && !v4->IsFlagSet(this: v4, a2: nDisallowedFlags) )
      {
        if ( !nonDefault )
          goto LABEL_14;
        if ( (v4->m_nFlags & 0x1000) != 0 )
        {
          m_pszString = "FCVAR_NEVER_AS_STRING";
        }
        else
        {
          m_pszString = v4->m_pParent->m_Value.m_pszString;
          if ( m_pszString == nullptr )
            m_pszString = defaultValue;
        }
        v10 = m_pszString;
        Default = ConVar::GetDefault(this: v4);
        if ( V_strcasecmp(s1: Default, s2: v10) != 0 )
        {
LABEL_14:
          if ( v4->GetSplitScreenPlayerSlot(this: &v4->IConVar) == nSplitScreenSlot )
          {
            v7 = v4->GetBaseName(this: &v4->IConVar);
            V_strncpy(pDest: acvar.name, pSrc: v7, maxLen: 260);
            if ( (v4->m_nFlags & 0x1000) != 0 )
            {
              v8 = "FCVAR_NEVER_AS_STRING";
            }
            else
            {
              v8 = v4->m_pParent->m_Value.m_pszString;
              if ( v8 == nullptr )
                v8 = defaultValue;
            }
            v9 = Host_CleanupConVarStringValue(invalue: v8);
            V_strncpy(pDest: acvar.value, pSrc: v9, maxLen: 260);
            CUtlVector<NetMessageCvar_t,CUtlMemory<NetMessageCvar_t,int>>::InsertBefore(
              this: rCvarList,
              elem: rCvarList->m_Size,
              src: &acvar);
          }
        }
      }
      v3->Next(this: v3);
    }
    if ( rCvarList->m_Size <= 255 )
    {
      free(pMem: v3);
    }
    else
    {
      Sys_Error(error: "Engine only supports 255 ConVars marked %i\n", 512);
      free(pMem: v3);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1018AAA0
// Name: void Host_BuildConVarUpdateMessage(class CUtlVector<struct NetMessageCvar_t,class CUtlMemory<struct NetMessageCvar_t,int>> __near &,int,bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Host_BuildConVarUpdateMessage(
        CUtlVector<NetMessageCvar_t,CUtlMemory<NetMessageCvar_t,int> > *rCvarList,
        int flags,
        bool nonDefault)
{
  int v3; // eax
  ICvar::ICVarIteratorInternal *v4; // edi
  ConVar *v5; // esi
  const char *m_pszString; // eax
  const char *Default; // eax
  const char *v8; // eax
  const char *v9; // eax
  const char *v10; // eax
  const char *v11; // [esp-Ch] [ebp-218h]
  NetMessageCvar_t acvar; // [esp+4h] [ebp-208h] BYREF

  v3 = Host_CountVariablesWithFlags(flags, nonDefault);
  if ( v3 > 0 )
  {
    if ( v3 <= 255 )
    {
      v4 = g_pCVar->FactoryInternalIterator(this: g_pCVar);
      v4->SetFirst(this: v4);
      while ( v4->IsValid(this: v4) )
      {
        v5 = (ConVar *)v4->Get(this: v4);
        if ( !v5->IsCommand(this: v5) && v5->IsFlagSet(this: v5, a2: flags) )
        {
          if ( !nonDefault )
            goto LABEL_13;
          if ( (v5->m_nFlags & 0x1000) != 0 )
          {
            m_pszString = "FCVAR_NEVER_AS_STRING";
          }
          else
          {
            m_pszString = v5->m_pParent->m_Value.m_pszString;
            if ( m_pszString == nullptr )
              m_pszString = defaultValue;
          }
          v11 = m_pszString;
          Default = ConVar::GetDefault(this: v5);
          if ( V_strcasecmp(s1: Default, s2: v11) != 0 )
          {
LABEL_13:
            v8 = v5->GetName(this: v5);
            V_strncpy(pDest: acvar.name, pSrc: v8, maxLen: 260);
            if ( (v5->m_nFlags & 0x1000) != 0 )
            {
              v9 = "FCVAR_NEVER_AS_STRING";
            }
            else
            {
              v9 = v5->m_pParent->m_Value.m_pszString;
              if ( v9 == nullptr )
                v9 = defaultValue;
            }
            v10 = Host_CleanupConVarStringValue(invalue: v9);
            V_strncpy(pDest: acvar.value, pSrc: v10, maxLen: 260);
            CUtlVector<NetMessageCvar_t,CUtlMemory<NetMessageCvar_t,int>>::InsertBefore(
              this: rCvarList,
              elem: rCvarList->m_Size,
              src: &acvar);
          }
        }
        v4->Next(this: v4);
      }
      free(pMem: v4);
    }
    else
    {
      Sys_Error(error: "Engine only supports 255 ConVars marked %i\n", flags);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x103138C0
// Name: _dynamic_initializer_for__host_syncfps__
// Source: semantic_dyn_pfx_host
//------------------------------------------------------------------------------
int dynamic_initializer_for__host_syncfps__()
{
  ConVar::ConVar(
    this: &host_syncfps,
    pName: "host_syncfps",
    pDefaultValue: "0",
    flags: 2,
    pHelpString: "Synchronize real render time to host_framerate if possible.");
  return atexit(func: dynamic_atexit_destructor_for__host_syncfps__);
}

//------------------------------------------------------------------------------
// Address: 0x10317CC0
// Name: _dynamic_initializer_for__host_flush_threshold__
// Source: semantic_dyn_pfx_host
//------------------------------------------------------------------------------
int dynamic_initializer_for__host_flush_threshold__()
{
  ConVar::ConVar(
    this: &host_flush_threshold,
    pName: "host_flush_threshold",
    pDefaultValue: "12",
    flags: 0x80000,
    pHelpString: "Memory threshold below which the host should flush caches between server instances");
  return atexit(func: dynamic_atexit_destructor_for__host_flush_threshold__);
}

//------------------------------------------------------------------------------
// Address: 0x1031A5F0
// Name: player_info_s_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *player_info_s_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<player_info_s>(__formal: nullptr);
  player_info_s_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1031A9C0
// Name: _dynamic_initializer_for__host_showcachemiss__
// Source: semantic_dyn_pfx_host
//------------------------------------------------------------------------------
int dynamic_initializer_for__host_showcachemiss__()
{
  ConVar::ConVar(
    this: &host_showcachemiss,
    pName: "host_showcachemiss",
    pDefaultValue: "0",
    flags: 0,
    pHelpString: "Print a debug message when the client or server cache is missed.");
  return atexit(func: dynamic_atexit_destructor_for__host_showcachemiss__);
}

//------------------------------------------------------------------------------
// Address: 0x1031AA20
// Name: _dynamic_initializer_for__host_ShowIPCCallCount__
// Source: semantic_dyn_pfx_host
//------------------------------------------------------------------------------
int dynamic_initializer_for__host_ShowIPCCallCount__()
{
  ConVar::ConVar(
    this: &host_ShowIPCCallCount,
    pName: "host_ShowIPCCallCount",
    pDefaultValue: "0",
    flags: 0,
    pHelpString: "Print # of IPC calls this number of times per second. If set to -1, the # of IPC calls is shown every frame.");
  return atexit(func: dynamic_atexit_destructor_for__host_ShowIPCCallCount__);
}

//------------------------------------------------------------------------------
// Address: 0x1031AAC0
// Name: _dynamic_initializer_for__host_thread_mode__
// Source: semantic_dyn_pfx_host
//------------------------------------------------------------------------------
int dynamic_initializer_for__host_thread_mode__()
{
  ConVar::ConVar(
    this: &host_thread_mode,
    pName: "host_thread_mode",
    pDefaultValue: "0",
    flags: 2,
    pHelpString: "Run the host in threaded mode, (0 == off, 1 == if multicore, 2 == force)");
  return atexit(func: dynamic_atexit_destructor_for__host_thread_mode__);
}

//------------------------------------------------------------------------------
// Address: 0x1031AAF0
// Name: _dynamic_initializer_for__host_threaded_sound__
// Source: semantic_dyn_pfx_host
//------------------------------------------------------------------------------
int dynamic_initializer_for__host_threaded_sound__()
{
  ConVar::ConVar(
    this: &host_threaded_sound,
    pName: "host_threaded_sound",
    pDefaultValue: "0",
    flags: 0,
    pHelpString: "Run the sound on a thread (independent of mix)");
  return atexit(func: dynamic_atexit_destructor_for__host_threaded_sound__);
}

//------------------------------------------------------------------------------
// Address: 0x1031AC90
// Name: _dynamic_initializer_for__host_profile__
// Source: semantic_dyn_pfx_host
//------------------------------------------------------------------------------
int dynamic_initializer_for__host_profile__()
{
  ConVar::ConVar(this: &host_profile, pName: "host_profile", pDefaultValue: "0", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__host_profile__);
}

//------------------------------------------------------------------------------
// Address: 0x1031AD00
// Name: _dynamic_initializer_for__host_timescale__
// Source: semantic_dyn_pfx_host
//------------------------------------------------------------------------------
int dynamic_initializer_for__host_timescale__()
{
  ConVar::ConVar(
    this: &host_timescale,
    pName: "host_timescale",
    pDefaultValue: "1.0",
    flags: 24576,
    pHelpString: "Prescale the clock by this amount.");
  return atexit(func: dynamic_atexit_destructor_for__host_timescale__);
}

//------------------------------------------------------------------------------
// Address: 0x1031AD30
// Name: _dynamic_initializer_for__host_limitlocal__
// Source: semantic_dyn_pfx_host
//------------------------------------------------------------------------------
int dynamic_initializer_for__host_limitlocal__()
{
  ConVar::ConVar(
    this: &host_limitlocal,
    pName: "host_limitlocal",
    pDefaultValue: "0",
    flags: 0,
    pHelpString: "Apply cl_cmdrate and cl_updaterate to loopback connection");
  return atexit(func: dynamic_atexit_destructor_for__host_limitlocal__);
}

//------------------------------------------------------------------------------
// Address: 0x1031AD60
// Name: _dynamic_initializer_for__host_framerate__
// Source: semantic_dyn_pfx_host
//------------------------------------------------------------------------------
int dynamic_initializer_for__host_framerate__()
{
  ConVar::ConVar(
    this: &host_framerate,
    pName: "host_framerate",
    pDefaultValue: "0",
    flags: 0,
    pHelpString: "Set to lock per-frame time elapse.");
  return atexit(func: dynamic_atexit_destructor_for__host_framerate__);
}

//------------------------------------------------------------------------------
// Address: 0x1031AD90
// Name: _dynamic_initializer_for__host_speeds__
// Source: semantic_dyn_pfx_host
//------------------------------------------------------------------------------
int dynamic_initializer_for__host_speeds__()
{
  ConVar::ConVar(
    this: &host_speeds,
    pName: "host_speeds",
    pDefaultValue: "0",
    flags: 0,
    pHelpString: "Show general system running times.");
  return atexit(func: dynamic_atexit_destructor_for__host_speeds__);
}

//------------------------------------------------------------------------------
// Address: 0x1031AEB0
// Name: _dynamic_initializer_for__host_writeconfig_command__
// Source: semantic_dyn_pfx_host
//------------------------------------------------------------------------------
int dynamic_initializer_for__host_writeconfig_command__()
{
  ConCommand::ConCommand(
    this: &host_writeconfig_command,
    pName: "host_writeconfig",
    callback: (void (__cdecl *)(const CCommand *))host_writeconfig,
    pHelpString: "Store current settings to config.cfg (or specified .cfg file).",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__host_writeconfig_command__);
}

//------------------------------------------------------------------------------
// Address: 0x1031AF10
// Name: _dynamic_initializer_for__host_reset_config_command__
// Source: semantic_dyn_pfx_host
//------------------------------------------------------------------------------
int dynamic_initializer_for__host_reset_config_command__()
{
  ConCommand::ConCommand(
    this: &host_reset_config_command,
    pName: "host_reset_config",
    callback: host_reset_config,
    pHelpString: "reset config (for testing) with param as splitscreen index.",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__host_reset_config_command__);
}

//------------------------------------------------------------------------------
// Address: 0x1031AFD0
// Name: _dynamic_initializer_for__host_runofftime_command__
// Source: semantic_dyn_pfx_host
//------------------------------------------------------------------------------
int dynamic_initializer_for__host_runofftime_command__()
{
  ConCommand::ConCommand(
    this: &host_runofftime_command,
    pName: "host_runofftime",
    callback: host_runofftime,
    pHelpString: "Run off some time without rendering/updating sounds\n",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__host_runofftime_command__);
}

//------------------------------------------------------------------------------
// Address: 0x1031B000
// Name: _dynamic_initializer_for__host_Sleep__
// Source: semantic_dyn_pfx_host
//------------------------------------------------------------------------------
int dynamic_initializer_for__host_Sleep__()
{
  ConVar::ConVar(
    this: &host_Sleep,
    pName: "host_sleep",
    pDefaultValue: "0",
    flags: 0x4000,
    pHelpString: "Force the host to sleep a certain number of milliseconds each frame.");
  return atexit(func: dynamic_atexit_destructor_for__host_Sleep__);
}

//------------------------------------------------------------------------------
// Address: 0x1031B030
// Name: _dynamic_initializer_for__host_print_frame_times__
// Source: semantic_dyn_pfx_host
//------------------------------------------------------------------------------
int dynamic_initializer_for__host_print_frame_times__()
{
  ConVar::ConVar(this: &host_print_frame_times, pName: "host_print_frame_times", pDefaultValue: "0", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__host_print_frame_times__);
}

//------------------------------------------------------------------------------
// Address: 0x1031B090
// Name: _dynamic_initializer_for__host_name__
// Source: semantic_dyn_pfx_host
//------------------------------------------------------------------------------
int dynamic_initializer_for__host_name__()
{
  ConVar::ConVar(
    this: &host_name,
    pName: "hostname",
    pDefaultValue: defaultValue,
    flags: 0x80000,
    pHelpString: "Hostname for server.",
    bMin: false,
    fMin: 0.0,
    bMax: false,
    fMax: 0.0,
    callback: HostnameChanged);
  return atexit(func: dynamic_atexit_destructor_for__host_name__);
}

//------------------------------------------------------------------------------
// Address: 0x1031B0D0
// Name: _dynamic_initializer_for__host_map__
// Source: semantic_dyn_pfx_host
//------------------------------------------------------------------------------
int dynamic_initializer_for__host_map__()
{
  ConVar::ConVar(
    this: &host_map,
    pName: "host_map",
    pDefaultValue: defaultValue,
    flags: 0x80000,
    pHelpString: "Current map name.");
  return atexit(func: dynamic_atexit_destructor_for__host_map__);
}

//------------------------------------------------------------------------------
// Address: 0x103229A0
// Name: _dynamic_atexit_destructor_for__host_syncfps__
// Source: semantic_dyn_pfx_host
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__host_syncfps__()
{
  ConVar::~ConVar(this: &host_syncfps);
}

//------------------------------------------------------------------------------
// Address: 0x10324600
// Name: _dynamic_atexit_destructor_for__host_flush_threshold__
// Source: semantic_dyn_pfx_host
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__host_flush_threshold__()
{
  ConVar::~ConVar(this: &host_flush_threshold);
}

//------------------------------------------------------------------------------
// Address: 0x10325830
// Name: _dynamic_atexit_destructor_for__host_profile__
// Source: semantic_dyn_pfx_host
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__host_profile__()
{
  ConVar::~ConVar(this: &host_profile);
}

//------------------------------------------------------------------------------
// Address: 0x10325850
// Name: _dynamic_atexit_destructor_for__host_timescale__
// Source: semantic_dyn_pfx_host
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__host_timescale__()
{
  ConVar::~ConVar(this: &host_timescale);
}

//------------------------------------------------------------------------------
// Address: 0x10325860
// Name: _dynamic_atexit_destructor_for__host_limitlocal__
// Source: semantic_dyn_pfx_host
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__host_limitlocal__()
{
  ConVar::~ConVar(this: &host_limitlocal);
}

//------------------------------------------------------------------------------
// Address: 0x10325870
// Name: _dynamic_atexit_destructor_for__host_framerate__
// Source: semantic_dyn_pfx_host
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__host_framerate__()
{
  ConVar::~ConVar(this: &host_framerate);
}

//------------------------------------------------------------------------------
// Address: 0x10325880
// Name: _dynamic_atexit_destructor_for__host_speeds__
// Source: semantic_dyn_pfx_host
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__host_speeds__()
{
  ConVar::~ConVar(this: &host_speeds);
}

//------------------------------------------------------------------------------
// Address: 0x103258E0
// Name: _dynamic_atexit_destructor_for__host_writeconfig_command__
// Source: semantic_dyn_pfx_host
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__host_writeconfig_command__()
{
  ConCommand::~ConCommand(this: &host_writeconfig_command);
}

//------------------------------------------------------------------------------
// Address: 0x103258F0
// Name: _dynamic_atexit_destructor_for__host_writeconfig_ss_command__
// Source: semantic_dyn_pfx_host
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__host_writeconfig_ss_command__()
{
  ConCommand::~ConCommand(this: &host_writeconfig_ss_command);
}

//------------------------------------------------------------------------------
// Address: 0x10325900
// Name: _dynamic_atexit_destructor_for__host_reset_config_command__
// Source: semantic_dyn_pfx_host
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__host_reset_config_command__()
{
  ConCommand::~ConCommand(this: &host_reset_config_command);
}

//------------------------------------------------------------------------------
// Address: 0x10325950
// Name: _dynamic_atexit_destructor_for__host_runofftime_command__
// Source: semantic_dyn_pfx_host
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__host_runofftime_command__()
{
  ConCommand::~ConCommand(this: &host_runofftime_command);
}

//------------------------------------------------------------------------------
// Address: 0x10325960
// Name: _dynamic_atexit_destructor_for__host_Sleep__
// Source: semantic_dyn_pfx_host
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__host_Sleep__()
{
  ConVar::~ConVar(this: &host_Sleep);
}

//------------------------------------------------------------------------------
// Address: 0x10325970
// Name: _dynamic_atexit_destructor_for__host_print_frame_times__
// Source: semantic_dyn_pfx_host
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__host_print_frame_times__()
{
  ConVar::~ConVar(this: &host_print_frame_times);
}

//------------------------------------------------------------------------------
// Address: 0x103259A0
// Name: _dynamic_atexit_destructor_for__host_name__
// Source: semantic_dyn_pfx_host
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__host_name__()
{
  ConVar::~ConVar(this: &host_name);
}

//------------------------------------------------------------------------------
// Address: 0x103259B0
// Name: _dynamic_atexit_destructor_for__host_map__
// Source: semantic_dyn_pfx_host
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__host_map__()
{
  ConVar::~ConVar(this: &host_map);
}

//------------------------------------------------------------------------------
// Address: 0x103138F0
// Name: _dynamic_initializer_for__fps_screenshot_threshold__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__fps_screenshot_threshold__()
{
  ConVar::ConVar(
    this: &fps_screenshot_threshold,
    pName: "fps_screenshot_threshold",
    pDefaultValue: "-1",
    flags: 0x4000,
    pHelpString: "Dump a screenshot when the FPS drops below the given value.");
  return atexit(func: dynamic_atexit_destructor_for__fps_screenshot_threshold__);
}

//------------------------------------------------------------------------------
// Address: 0x10313920
// Name: _dynamic_initializer_for__fps_screenshot_frequency__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__fps_screenshot_frequency__()
{
  ConVar::ConVar(
    this: &fps_screenshot_frequency,
    pName: "fps_screenshot_frequency",
    pDefaultValue: "10",
    flags: 0x4000,
    pHelpString: "While the fps is below the threshold we will dump a screen shot this often in seconds (i.e. 10 = screen shot every 1"
    "0 seconds when under the given fps.)");
  return atexit(func: dynamic_atexit_destructor_for__fps_screenshot_frequency__);
}

//------------------------------------------------------------------------------
// Address: 0x10313950
// Name: _dynamic_initializer_for__startmovie_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__startmovie_command__()
{
  ConCommand::ConCommand(
    this: &startmovie_command,
    pName: "startmovie",
    callback: startmovie,
    pHelpString: "Start recording movie frames.",
    flags: 0x20000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__startmovie_command__);
}

//------------------------------------------------------------------------------
// Address: 0x10313980
// Name: _dynamic_initializer_for__endmovie_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__endmovie_command__()
{
  ConCommand::ConCommand(
    this: &endmovie_command,
    pName: "endmovie",
    callback: endmovie,
    pHelpString: "Stop recording movie frames.",
    flags: 0x20000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__endmovie_command__);
}

//------------------------------------------------------------------------------
// Address: 0x1031A600
// Name: _dynamic_initializer_for__violence_hblood__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__violence_hblood__()
{
  ConVar::ConVar(
    this: &violence_hblood,
    pName: "violence_hblood",
    pDefaultValue: "1",
    flags: 0,
    pHelpString: "Draw human blood");
  return atexit(func: dynamic_atexit_destructor_for__violence_hblood__);
}

//------------------------------------------------------------------------------
// Address: 0x1031A630
// Name: _dynamic_initializer_for__violence_hgibs__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__violence_hgibs__()
{
  ConVar::ConVar(
    this: &violence_hgibs,
    pName: "violence_hgibs",
    pDefaultValue: "1",
    flags: 0,
    pHelpString: "Show human gib entities");
  return atexit(func: dynamic_atexit_destructor_for__violence_hgibs__);
}

//------------------------------------------------------------------------------
// Address: 0x1031A660
// Name: _dynamic_initializer_for__violence_ablood__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__violence_ablood__()
{
  ConVar::ConVar(
    this: &violence_ablood,
    pName: "violence_ablood",
    pDefaultValue: "1",
    flags: 0,
    pHelpString: "Draw alien blood");
  return atexit(func: dynamic_atexit_destructor_for__violence_ablood__);
}

//------------------------------------------------------------------------------
// Address: 0x1031A690
// Name: _dynamic_initializer_for__violence_agibs__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__violence_agibs__()
{
  ConVar::ConVar(
    this: &violence_agibs,
    pName: "violence_agibs",
    pDefaultValue: "1",
    flags: 0,
    pHelpString: "Show alien gib entities");
  return atexit(func: dynamic_atexit_destructor_for__violence_agibs__);
}

//------------------------------------------------------------------------------
// Address: 0x1031A6C0
// Name: _dynamic_initializer_for__closecaption__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__closecaption__()
{
  ConVar::ConVar(
    this: &closecaption,
    pName: "closecaption",
    pDefaultValue: "0",
    flags: 16777856,
    pHelpString: "Enable close captioning.");
  return atexit(func: dynamic_atexit_destructor_for__closecaption__);
}

//------------------------------------------------------------------------------
// Address: 0x1031A9F0
// Name: _dynamic_initializer_for__mem_dumpstats__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mem_dumpstats__()
{
  ConVar::ConVar(
    this: &mem_dumpstats,
    pName: "mem_dumpstats",
    pDefaultValue: "0",
    flags: 0,
    pHelpString: "Dump current and max heap usage info to console at end of frame ( set to 2 for continuous output )\n");
  return atexit(func: dynamic_atexit_destructor_for__mem_dumpstats__);
}

//------------------------------------------------------------------------------
// Address: 0x1031AB20
// Name: _dynamic_initializer_for__threadpool_affinity__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__threadpool_affinity__()
{
  ConVar::ConVar(
    this: &threadpool_affinity,
    pName: "threadpool_affinity",
    pDefaultValue: "1",
    flags: 0,
    pHelpString: "Enable setting affinity",
    bMin: false,
    fMin: 0.0,
    bMax: false,
    fMax: 0.0,
    callback: (void (__cdecl *)(IConVar *, const char *, float))OnChangeThreadAffinity);
  return atexit(func: dynamic_atexit_destructor_for__threadpool_affinity__);
}

//------------------------------------------------------------------------------
// Address: 0x1031AB60
// Name: _dynamic_initializer_for__g_ReleaseThreadReservation__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_ReleaseThreadReservation__()
{
  CThreadEvent::CThreadEvent(this: &g_ReleaseThreadReservation, a2: true);
  return atexit(func: dynamic_atexit_destructor_for__g_ReleaseThreadReservation__);
}

//------------------------------------------------------------------------------
// Address: 0x1031AB80
// Name: _dynamic_initializer_for__g_NumReservedThreads__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void dynamic_initializer_for__g_NumReservedThreads__()
{
  g_NumReservedThreads.m_value = 0;
}

//------------------------------------------------------------------------------
// Address: 0x1031AB90
// Name: _dynamic_initializer_for__threadpool_reserve__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__threadpool_reserve__()
{
  ConVar::ConVar(
    this: &threadpool_reserve,
    pName: "threadpool_reserve",
    pDefaultValue: "0",
    flags: 0,
    pHelpString: "Consume the specified number of threads in the thread pool",
    bMin: false,
    fMin: 0.0,
    bMax: false,
    fMax: 0.0,
    callback: (void (__cdecl *)(IConVar *, const char *, float))OnChangeThreadReserve);
  return atexit(func: dynamic_atexit_destructor_for__threadpool_reserve__);
}

//------------------------------------------------------------------------------
// Address: 0x1031ADC0
// Name: _dynamic_initializer_for__developer__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__developer__()
{
  ConVar::ConVar(
    this: &developer,
    pName: "developer",
    pDefaultValue: "0",
    flags: 0x4000,
    pHelpString: "Set developer message level");
  return atexit(func: dynamic_atexit_destructor_for__developer__);
}

//------------------------------------------------------------------------------
// Address: 0x1031ADF0
// Name: _dynamic_initializer_for__deathmatch__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__deathmatch__()
{
  ConVar::ConVar(
    this: &deathmatch,
    pName: "deathmatch",
    pDefaultValue: "0",
    flags: 256,
    pHelpString: "Running a deathmatch server.");
  return atexit(func: dynamic_atexit_destructor_for__deathmatch__);
}

//------------------------------------------------------------------------------
// Address: 0x1031AE20
// Name: _dynamic_initializer_for__coop__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__coop__()
{
  ConVar::ConVar(this: &coop, pName: "coop", pDefaultValue: "0", flags: 256, pHelpString: "Cooperative play.");
  return atexit(func: dynamic_atexit_destructor_for__coop__);
}

//------------------------------------------------------------------------------
// Address: 0x1031AF40
// Name: _dynamic_initializer_for__recompute_speed__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__recompute_speed__()
{
  ConCommand::ConCommand(
    this: &recompute_speed,
    pName: "recompute_speed",
    callback: Host_RecomputeSpeed_f,
    pHelpString: "Recomputes clock speed (for debugging purposes).",
    flags: 0x4000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__recompute_speed__);
}

//------------------------------------------------------------------------------
// Address: 0x1031AF70
// Name: _dynamic_initializer_for__dti_flush__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__dti_flush__()
{
  ConCommand::ConCommand(
    this: &dti_flush,
    pName: "dti_flush",
    callback: DTI_Flush_f,
    pHelpString: "Write out the datatable instrumentation files (you must run with -dti for this to work).",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__dti_flush__);
}

//------------------------------------------------------------------------------
// Address: 0x1031AFA0
// Name: _dynamic_initializer_for__mem_periodicdumps__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mem_periodicdumps__()
{
  ConVar::ConVar(
    this: &mem_periodicdumps,
    pName: "mem_periodicdumps",
    pDefaultValue: "0",
    flags: 0,
    pHelpString: "Write periodic memstats dumps every n seconds.");
  return atexit(func: dynamic_atexit_destructor_for__mem_periodicdumps__);
}

//------------------------------------------------------------------------------
// Address: 0x1031B060
// Name: _dynamic_initializer_for__fs_enable_stats__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__fs_enable_stats__()
{
  ConVar::ConVar(this: &fs_enable_stats, pName: "fs_enable_stats", pDefaultValue: "0", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__fs_enable_stats__);
}

//------------------------------------------------------------------------------
// Address: 0x103229B0
// Name: _dynamic_atexit_destructor_for__fps_screenshot_threshold__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__fps_screenshot_threshold__()
{
  ConVar::~ConVar(this: &fps_screenshot_threshold);
}

//------------------------------------------------------------------------------
// Address: 0x103229C0
// Name: _dynamic_atexit_destructor_for__fps_screenshot_frequency__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__fps_screenshot_frequency__()
{
  ConVar::~ConVar(this: &fps_screenshot_frequency);
}

//------------------------------------------------------------------------------
// Address: 0x103229D0
// Name: _dynamic_atexit_destructor_for__startmovie_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__startmovie_command__()
{
  ConCommand::~ConCommand(this: &startmovie_command);
}

//------------------------------------------------------------------------------
// Address: 0x103229E0
// Name: _dynamic_atexit_destructor_for__endmovie_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__endmovie_command__()
{
  ConCommand::~ConCommand(this: &endmovie_command);
}

//------------------------------------------------------------------------------
// Address: 0x103257D0
// Name: _dynamic_atexit_destructor_for__g_ReleaseThreadReservation__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_ReleaseThreadReservation__()
{
  CThreadSyncObject::~CThreadSyncObject(this: &g_ReleaseThreadReservation);
}

//------------------------------------------------------------------------------
// Address: 0x103257E0
// Name: _dynamic_atexit_destructor_for__threadpool_reserve__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__threadpool_reserve__()
{
  ConVar::~ConVar(this: &threadpool_reserve);
}

//------------------------------------------------------------------------------
// Address: 0x103257F0
// Name: _dynamic_atexit_destructor_for__threadpool_cycle_reserve_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__threadpool_cycle_reserve_command__()
{
  ConCommand::~ConCommand(this: &threadpool_cycle_reserve_command);
}

//------------------------------------------------------------------------------
// Address: 0x10325840
// Name: _dynamic_atexit_destructor_for__skill__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__skill__()
{
  ConVar::~ConVar(this: &skill);
}

//------------------------------------------------------------------------------
// Address: 0x10325890
// Name: _dynamic_atexit_destructor_for__developer__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__developer__()
{
  ConVar::~ConVar(this: &developer);
}

//------------------------------------------------------------------------------
// Address: 0x103258A0
// Name: _dynamic_atexit_destructor_for__deathmatch__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__deathmatch__()
{
  ConVar::~ConVar(this: &deathmatch);
}

//------------------------------------------------------------------------------
// Address: 0x103258B0
// Name: _dynamic_atexit_destructor_for__coop__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__coop__()
{
  ConVar::~ConVar(this: &coop);
}

//------------------------------------------------------------------------------
// Address: 0x10325910
// Name: _dynamic_atexit_destructor_for__recompute_speed__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__recompute_speed__()
{
  ConCommand::~ConCommand(this: &recompute_speed);
}

//------------------------------------------------------------------------------
// Address: 0x10325920
// Name: _dynamic_atexit_destructor_for__dti_flush__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__dti_flush__()
{
  ConCommand::~ConCommand(this: &dti_flush);
}

//------------------------------------------------------------------------------
// Address: 0x10325930
// Name: _dynamic_atexit_destructor_for__mem_periodicdumps__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mem_periodicdumps__()
{
  ConVar::~ConVar(this: &mem_periodicdumps);
}

//------------------------------------------------------------------------------
// Address: 0x10325940
// Name: __Host_RunFrame_Server_::_4_::_dynamic_atexit_destructor_for___counter__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _Host_RunFrame_Server_::_4_::_dynamic_atexit_destructor_for___counter__()
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x10325980
// Name: _dynamic_atexit_destructor_for__fs_enable_stats__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__fs_enable_stats__()
{
  ConVar::~ConVar(this: &fs_enable_stats);
}

//------------------------------------------------------------------------------
// Address: 0x10325990
// Name: _DataMapInit_player_info_s__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_player_info_s__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_1);
}

} // namespace engine_xlsp
