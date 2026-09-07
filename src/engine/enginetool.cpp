// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: engine/enginetool.cpp
// Functions: 82
// ============================================================

#include "engine\enginetool.h"

//------------------------------------------------------------------------------
// Address: 0x10001490
// Name: public: virtual bool CEngineTool::IsSoundStillPlaying(int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CEngineTool::IsSoundStillPlaying(CEngineSoundClient *this, int guid)
{
  return S_IsSoundStillPlaying(guid);
}

//------------------------------------------------------------------------------
// Address: 0x100014F0
// Name: public: virtual float CEngineTool::GetSoundElapsedTime(int)
// Source: json
//------------------------------------------------------------------------------
float __thiscall CEngineTool::GetSoundElapsedTime(CEngineSoundClient *this, int guid)
{
  return S_GetElapsedTimeByGuid(guid);
}

//------------------------------------------------------------------------------
// Address: 0x1006F1B0
// Name: public: virtual void CEngineTool::SetAudioState(struct AudioState_t const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineTool::SetAudioState(CEngineClient *this, const AudioState_t *audioState)
{
  Host_SetAudioState(audioState);
}

//------------------------------------------------------------------------------
// Address: 0x1006F330
// Name: public: virtual bool CEngineTool::IsGamePaused(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CEngineTool::IsGamePaused(CEngineClient *this)
{
  CClientState *BaseLocalClient; // eax

  BaseLocalClient = GetBaseLocalClient();
  return CClientState::IsPaused(this: BaseLocalClient);
}

//------------------------------------------------------------------------------
// Address: 0x101FF270
// Name: public: virtual int CEngineTool::GetPointContents(class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CEngineTool::GetPointContents(CEngineTool *this, const Vector *vecPosition)
{
  return g_pEngineTraceClient->GetPointContents(this: g_pEngineTraceClient, a2: vecPosition, a3: 0, a4: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x101FF290
// Name: public: virtual int CEngineTool::GetActiveDLights(struct dlight_t __near * __near * const)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CEngineTool::GetActiveDLights(CEngineTool *this, dlight_t **pList)
{
  return g_pEfx->CL_GetActiveDLights(this: g_pEfx, a2: pList);
}

//------------------------------------------------------------------------------
// Address: 0x101FF2B0
// Name: public: virtual int CEngineTool::GetLightingConditions(class Vector const __near &,class Vector __near *,int,struct LightDesc_t __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CEngineTool::GetLightingConditions(
        CEngineTool *this,
        const Vector *vecLightingOrigin,
        Vector *pColors,
        int nMaxLocalLights,
        LightDesc_t *pLocalLights)
{
  int v5; // ebx
  int v6; // edi
  float *p_y; // esi
  float v8; // xmm0_4
  LightingState_t state; // [esp+0h] [ebp-5Ch] BYREF

  v5 = 0;
  memset(&state, 0, 76);
  LightcacheGetDynamic(
    origin: vecLightingOrigin,
    lightingState: &state,
    stats: (LightcacheGetDynamic_Stats *)&vecLightingOrigin,
    pRenderable: nullptr,
    flags: 7u,
    bDebugModel: false);
  qmemcpy(pColors, &state, 72);
  v6 = 0;
  if ( state.numlights > 0 )
  {
    p_y = &pLocalLights->m_Color.y;
    do
    {
      if ( WorldLightToMaterialLight(pWorldLight: state.locallight[v5], light: (LightDesc_t *)(p_y - 2)) )
      {
        v8 = (float)d_lightstylevalue[state.locallight[v5]->style] * 0.0037878789;
        *(p_y - 1) = *(p_y - 1) * v8;
        *p_y = *p_y * v8;
        p_y[1] = v8 * p_y[1];
        ++v6;
        p_y += 22;
        if ( v6 >= nMaxLocalLights )
          break;
      }
      ++v5;
    }
    while ( v5 < state.numlights );
  }
  return v6;
}

//------------------------------------------------------------------------------
// Address: 0x101FF3C0
// Name: public: virtual void CEngineTool::GetServerFactory(void __near * (*__near &)(char const __near *,int __near *))
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineTool::GetServerFactory(CEngineTool *this, void *(__cdecl **factory)(const char *, int *))
{
  *factory = Sys_GetFactory(pModule: g_GameDLL);
}

//------------------------------------------------------------------------------
// Address: 0x101FF3E0
// Name: public: virtual void CEngineTool::GetClientFactory(void __near * (*__near &)(char const __near *,int __near *))
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineTool::GetClientFactory(CEngineTool *this, void *(__cdecl **factory)(const char *, int *))
{
  *factory = ClientDLL_GetFactory();
}

//------------------------------------------------------------------------------
// Address: 0x101FF400
// Name: public: virtual void CEngineTool::Command(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineTool::Command(CEngineTool *this, const char *cmd)
{
  ECommandTarget_t TraceType; // eax

  TraceType = CTraceFilter::GetTraceType((vgui::CTreeViewListControl *)this);
  Cbuf_AddText(eTarget: TraceType, pText: cmd, nTickDelay: 0);
}

//------------------------------------------------------------------------------
// Address: 0x101FF420
// Name: public: virtual void CEngineTool::Execute(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall CEngineTool::Execute(CVEngineServer *this)
{
  Cbuf_Execute();
}

//------------------------------------------------------------------------------
// Address: 0x101FF430
// Name: public: virtual char const __near * CEngineTool::GetCurrentMap(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CEngineTool::GetCurrentMap(CEngineTool *this)
{
  if ( sv.m_bIsDedicated )
    return "Dedicated Server";
  if ( GetBaseLocalClient()->m_nSignonState >= 2 )
    return GetBaseLocalClient()->m_szLevelName;
  if ( sv.m_State == ss_loading )
    return sv.m_szMapname;
  return defaultValue;
}

//------------------------------------------------------------------------------
// Address: 0x101FF470
// Name: public: virtual void CEngineTool::ChangeToMap(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineTool::ChangeToMap(CEngineTool *this, const char *mapname)
{
  vgui::CTreeViewListControl *v2; // ecx
  ECommandTarget_t TraceType; // eax
  const char *v4; // [esp-8h] [ebp-Ch]

  if ( modelloader->Map_IsValid(this: modelloader, a2: mapname, a3: false) )
  {
    v4 = va(format: "map \"%s\"\n", mapname);
    TraceType = CTraceFilter::GetTraceType(this: v2);
    Cbuf_AddText(eTarget: TraceType, pText: v4, nTickDelay: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101FF4B0
// Name: public: virtual bool CEngineTool::IsMapValid(char const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CEngineTool::IsMapValid(CEngineTool *this, const char *mapname)
{
  return modelloader->Map_IsValid(this: modelloader, a2: mapname, a3: false);
}

//------------------------------------------------------------------------------
// Address: 0x101FF4D0
// Name: public: virtual void CEngineTool::RenderView(class CViewSetup __near &,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineTool::RenderView(CEngineTool *this, CViewSetup *view, int nFlags, int whatToRender)
{
  g_ClientDLL->RenderView(this: g_ClientDLL, a2: view, a3: nFlags, a4: whatToRender);
}

//------------------------------------------------------------------------------
// Address: 0x101FF4F0
// Name: public: virtual bool CEngineTool::IsInGame(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CEngineTool::IsInGame(CEngineTool *this)
{
  return this->m_bIsInGame && GetBaseLocalClient()->m_nSignonState >= 2;
}

//------------------------------------------------------------------------------
// Address: 0x101FF530
// Name: public: virtual void CEngineTool::SetGamePaused(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineTool::SetGamePaused(CEngineTool *this, bool paused)
{
  CBaseServer::SetPaused(this: &sv, paused);
}

//------------------------------------------------------------------------------
// Address: 0x101FF550
// Name: public: virtual void CEngineTool::SetTimescale(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineTool::SetTimescale(CEngineTool *this, float scale)
{
  ConVar::SetValue(this: (ConVar *)&host_timescale.IConVar, value: scale);
}

//------------------------------------------------------------------------------
// Address: 0x101FF570
// Name: public: virtual float CEngineTool::GetRealTime(void)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CEngineTool::GetRealTime(CEngineTool *this)
{
  return realtime;
}

//------------------------------------------------------------------------------
// Address: 0x101FF580
// Name: public: virtual float CEngineTool::GetRealFrameTime(void)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CEngineTool::GetRealFrameTime(CEngineTool *this)
{
  return host_frametime_unscaled;
}

//------------------------------------------------------------------------------
// Address: 0x101FF590
// Name: public: virtual float CEngineTool::HostFrameTime(void)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CEngineTool::HostFrameTime(CEngineTool *this)
{
  return host_frametime;
}

//------------------------------------------------------------------------------
// Address: 0x101FF5A0
// Name: public: virtual int CEngineTool::HostTick(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CEngineTool::HostTick(CEngineTool *this)
{
  return host_tickcount;
}

//------------------------------------------------------------------------------
// Address: 0x101FF5B0
// Name: public: virtual int CEngineTool::HostFrameCount(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CEngineTool::HostFrameCount(CEngineTool *this)
{
  return host_framecount;
}

//------------------------------------------------------------------------------
// Address: 0x101FF5C0
// Name: public: virtual float CEngineTool::ServerTime(void)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CEngineTool::ServerTime(CEngineTool *this)
{
  return g_ServerGlobalVariables.curtime;
}

//------------------------------------------------------------------------------
// Address: 0x101FF5D0
// Name: public: virtual float CEngineTool::ServerFrameTime(void)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CEngineTool::ServerFrameTime(CEngineTool *this)
{
  return g_ServerGlobalVariables.frametime;
}

//------------------------------------------------------------------------------
// Address: 0x101FF5E0
// Name: public: virtual int CEngineTool::ServerTick(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CEngineTool::ServerTick(CEngineTool *this)
{
  return g_ServerGlobalVariables.tickcount;
}

//------------------------------------------------------------------------------
// Address: 0x101FF5F0
// Name: public: virtual float CEngineTool::ServerTickInterval(void)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CEngineTool::ServerTickInterval(CEngineTool *this)
{
  return g_ServerGlobalVariables.interval_per_tick;
}

//------------------------------------------------------------------------------
// Address: 0x101FF600
// Name: public: virtual float CEngineTool::ClientTime(void)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CEngineTool::ClientTime(CEngineTool *this)
{
  return g_ClientGlobalVariables.curtime;
}

//------------------------------------------------------------------------------
// Address: 0x101FF610
// Name: public: virtual float CEngineTool::ClientFrameTime(void)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CEngineTool::ClientFrameTime(CEngineTool *this)
{
  return g_ClientGlobalVariables.frametime;
}

//------------------------------------------------------------------------------
// Address: 0x101FF620
// Name: public: virtual int CEngineTool::ClientTick(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CEngineTool::ClientTick(CEngineTool *this)
{
  return g_ClientGlobalVariables.tickcount;
}

//------------------------------------------------------------------------------
// Address: 0x101FF630
// Name: public: virtual void CEngineTool::SetClientFrameTime(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineTool::SetClientFrameTime(CEngineTool *this, float frametime)
{
  g_ClientGlobalVariables.frametime = frametime;
}

//------------------------------------------------------------------------------
// Address: 0x101FF650
// Name: public: virtual void CEngineTool::ForceSend(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall CEngineTool::ForceSend(CEngineTool *this)
{
  SV_ForceSend();
}

//------------------------------------------------------------------------------
// Address: 0x101FF670
// Name: public: virtual void CEngineTool::Con_NPrintf(int,char const __near *,...)
// Source: json
//------------------------------------------------------------------------------
void CEngineTool::Con_NPrintf(CEngineTool *this, int pos, const char *fmt, ...)
{
  char buf[1024]; // [esp+0h] [ebp-400h] BYREF
  va_list ap; // [esp+414h] [ebp+14h] BYREF

  va_start(ap, fmt);
  _vsnprintf(string: buf, count: 0x3FFu, format: fmt, ap);
  Con_NPrintf(idx: pos, fmt: "%s", buf);
}

//------------------------------------------------------------------------------
// Address: 0x101FF6B0
// Name: public: virtual void CEngineTool::Con_NXPrintf(struct con_nprint_s const __near *,char const __near *,...)
// Source: json
//------------------------------------------------------------------------------
void CEngineTool::Con_NXPrintf(CEngineTool *this, const con_nprint_s *info, const char *fmt, ...)
{
  char buf[1024]; // [esp+0h] [ebp-400h] BYREF
  va_list ap; // [esp+414h] [ebp+14h] BYREF

  va_start(ap, fmt);
  _vsnprintf(string: buf, count: 0x3FFu, format: fmt, ap);
  Con_NXPrintf(info, fmt: "%s", buf);
}

//------------------------------------------------------------------------------
// Address: 0x101FF6F0
// Name: public: virtual void CEngineTool::GetGameDir(char __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineTool::GetGameDir(CEngineTool *this, char *szGetGameDir, int maxlength)
{
  V_strncpy(pDest: szGetGameDir, pSrc: com_gamedir, maxLen: maxlength);
}

//------------------------------------------------------------------------------
// Address: 0x101FF710
// Name: public: virtual int CEngineTool::GetToolCount(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CEngineTool::GetToolCount(CEngineTool *this)
{
  return toolframework->GetToolCount(this: toolframework);
}

//------------------------------------------------------------------------------
// Address: 0x101FF720
// Name: public: virtual char const __near * CEngineTool::GetToolName(int)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CEngineTool::GetToolName(CEngineTool *this, int index)
{
  return toolframework->GetToolName(this: toolframework, a2: index);
}

//------------------------------------------------------------------------------
// Address: 0x101FF740
// Name: public: virtual void CEngineTool::SwitchToTool(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineTool::SwitchToTool(CEngineTool *this, int index)
{
  toolframework->SwitchToTool_2(this: toolframework, a2: index);
}

//------------------------------------------------------------------------------
// Address: 0x101FF760
// Name: public: virtual bool CEngineTool::IsTopmostTool(class IToolSystem const __near *)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CEngineTool::IsTopmostTool(CEngineTool *this, const IToolSystem *sys)
{
  return toolframework->IsTopmostTool(this: toolframework, a2: sys);
}

//------------------------------------------------------------------------------
// Address: 0x101FF780
// Name: public: virtual class IToolSystem __near * CEngineTool::GetTopmostTool(void)
// Source: json
//------------------------------------------------------------------------------
IToolSystem *__thiscall CEngineTool::GetTopmostTool(CEngineTool *this)
{
  return toolframework->GetTopmostTool(this: toolframework);
}

//------------------------------------------------------------------------------
// Address: 0x101FF790
// Name: public: virtual class IToolSystem const __near * CEngineTool::GetToolSystem(int)const
// Source: json
//------------------------------------------------------------------------------
const IToolSystem *__thiscall CEngineTool::GetToolSystem(CEngineTool *this, int index)
{
  return toolframework->GetToolSystem(this: toolframework, a2: index);
}

//------------------------------------------------------------------------------
// Address: 0x101FF7B0
// Name: public: virtual bool CEngineTool::LoadToolModule(char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CEngineTool::LoadToolModule(CEngineTool *this, const char *pToolModule, BOOL bSwitchToFirst)
{
  return toolframework->LoadToolModule(this: toolframework, a2: pToolModule, a3: bSwitchToFirst);
}

//------------------------------------------------------------------------------
// Address: 0x101FF7D0
// Name: public: virtual void CEngineTool::ValidateSoundCache(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineTool::ValidateSoundCache(CEngineTool *this, const char *pchSoundName)
{
  S_ValidateSoundCache(pchWavFile: pchSoundName);
}

//------------------------------------------------------------------------------
// Address: 0x101FF7F0
// Name: public: virtual void CEngineTool::PrefetchSound(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineTool::PrefetchSound(CEngineTool *this, const char *pchSoundName)
{
  S_PrefetchSound(name: pchSoundName, bPlayOnce: false);
}

//------------------------------------------------------------------------------
// Address: 0x101FF810
// Name: public: virtual int CEngineTool::StartSound(int,bool,int,int,char const __near *,float,enum soundlevel_t,class Vector const __near &,class Vector const __near &,int,int,bool,float,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CEngineTool::StartSound(
        CEngineTool *this,
        int iUserData,
        bool staticsound,
        int iEntIndex,
        int iChannel,
        const char *pSample,
        float flVolume,
        soundlevel_t iSoundlevel,
        const Vector *origin,
        const Vector *direction,
        int iFlags,
        int iPitch,
        bool bUpdatePositions,
        float delay,
        int speakerentity)
{
  float z; // xmm0_4
  StartSoundParams_t params; // [esp+0h] [ebp-64h] BYREF

  params.flags = 0;
  params.initialStreamPosition = 0;
  params.skipInitialSamples = 0;
  memset(&params.m_pSoundEntryName, 0, 16);
  params.speakerentity = -1;
  params.m_nQueuedGUID = -1;
  params.m_nSoundScriptHandle = -1;
  params.userdata = iUserData;
  *((_BYTE *)&params + 96) = (staticsound
                            ^ (*((_BYTE *)&params + 96) & 0xC0 | 2))
                           & 1
                           ^ (*((_BYTE *)&params + 96) & 0xC0 | 2);
  params.fvol = 1.0;
  params.soundlevel = SNDLVL_NORM;
  params.pitch = 100;
  params.delay = 0.0;
  memset(&params.origin, 0, 24);
  params.soundsource = iEntIndex;
  params.entchannel = iChannel;
  params.pSfx = S_PrecacheSound(name: pSample);
  params.origin = *origin;
  params.direction.x = direction->x;
  params.direction.y = direction->y;
  z = direction->z;
  params.soundlevel = iSoundlevel;
  params.direction.z = z;
  params.pitch = iPitch;
  params.flags = iFlags;
  params.fvol = flVolume;
  params.delay = delay;
  params.speakerentity = speakerentity;
  *((_BYTE *)&params + 96) = ((*((_BYTE *)&params + 96) ^ (2 * bUpdatePositions)) & 2 ^ *((_BYTE *)&params + 96)) & 0xF3
                           | 8;
  return S_StartSound(&params);
}

//------------------------------------------------------------------------------
// Address: 0x101FF950
// Name: public: virtual void CEngineTool::StopSoundByGuid(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineTool::StopSoundByGuid(CEngineTool *this, int guid)
{
  S_StopSoundByGuid(guid, bForceSync: false);
}

//------------------------------------------------------------------------------
// Address: 0x101FF970
// Name: public: virtual void CEngineTool::SetVolumeByGuid(int,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineTool::SetVolumeByGuid(CEngineSoundClient *this, int guid, float fvol)
{
  S_SetVolumeByGuid(guid, fvol);
}

//------------------------------------------------------------------------------
// Address: 0x101FF990
// Name: public: virtual float CEngineTool::GetSoundDuration(int)
// Source: json
//------------------------------------------------------------------------------
float __thiscall CEngineTool::GetSoundDuration(CEngineTool *this, int guid)
{
  return S_SoundDurationByGuid(guid);
}

//------------------------------------------------------------------------------
// Address: 0x101FF9B0
// Name: public: virtual void __near * CEngineTool::GetEngineHwnd(void)
// Source: json
//------------------------------------------------------------------------------
void *__thiscall CEngineTool::GetEngineHwnd(CEngineTool *this)
{
  return game->GetMainWindow(this: game);
}

//------------------------------------------------------------------------------
// Address: 0x101FF9E0
// Name: public: virtual void CEngineTool::ReloadSound(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineTool::ReloadSound(CEngineTool *this, const char *pSample)
{
  S_ReloadSound(name: pSample);
}

//------------------------------------------------------------------------------
// Address: 0x101FFA00
// Name: public: virtual bool CEngineTool::IsLoopingSound(int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CEngineTool::IsLoopingSound(CEngineTool *this, int guid)
{
  return S_IsLoopingSoundByGuid(guid);
}

//------------------------------------------------------------------------------
// Address: 0x101FFA20
// Name: public: virtual void CEngineTool::SetMainView(class Vector const __near &,class QAngle const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineTool::SetMainView(CVRenderView *this, const Vector *vecOrigin, const QAngle *angles)
{
  g_EngineRenderer->SetMainView(this: g_EngineRenderer, a2: vecOrigin, a3: angles);
}

//------------------------------------------------------------------------------
// Address: 0x101FFA40
// Name: public: virtual bool CEngineTool::GetPlayerView(class CViewSetup __near &,int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CEngineTool::GetPlayerView(CEngineTool *this, CViewSetup *viewSetup, int x, int y, int w, int h)
{
  bool result; // al
  float v7; // xmm0_4
  double v8; // st7

  if ( g_ClientDLL == nullptr )
    return false;
  result = g_ClientDLL->GetPlayerView(this: g_ClientDLL, a2: viewSetup);
  if ( result )
  {
    viewSetup->x = x;
    viewSetup->y = y;
    viewSetup->width = w;
    viewSetup->height = h;
    if ( h != 0 )
      v7 = (float)w / (float)h;
    else
      v7 = 1.3333334;
    *((_BYTE *)viewSetup + 240) |= 2u;
    v8 = v7 * 0.75;
    viewSetup->m_flAspectRatio = v7;
    viewSetup->fov = atan2(tan(viewSetup->fov * 0.008726646259971648) * v8, 1.0) * 57.29577951308232 * 2.0;
    viewSetup->fovViewmodel = 2.0
                            * (57.29577951308232
                             * atan2(v8 * tan(0.008726646259971648 * viewSetup->fovViewmodel), 1.0));
    return true;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101FFB20
// Name: public: virtual void CEngineTool::CreatePickingRay(class CViewSetup const __near &,int,int,class Vector __near &,class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CEngineTool::CreatePickingRay(
        CEngineTool *this@<ecx>,
        int a2@<esi>,
        const CViewSetup *viewSetup,
        int x,
        int y,
        Vector *org,
        Vector *forward)
{
  __m128i v8; // xmm2
  float v9; // xmm4_4
  float v10; // xmm3_4
  float v11; // xmm0_4
  float v12; // xmm3_4
  float v13; // xmm5_4
  float v14; // xmm0_4
  float v15; // xmm1_4
  float v16; // xmm4_4
  float v17; // xmm7_4
  float v18; // xmm1_4
  VMatrix worldToScreen; // [esp+0h] [ebp-80h] BYREF
  VMatrix screenToWorld; // [esp+40h] [ebp-40h] BYREF
  float xf; // [esp+88h] [ebp+8h]
  float yf; // [esp+8Ch] [ebp+Ch]

  v8 = _mm_cvtsi32_si128(viewSetup->height);
  xf = (float)((float)((float)x * 2.0) / (float)viewSetup->width) - 1.0;
  LODWORD(yf) = COERCE_UNSIGNED_INT((float)((float)((float)y * 2.0) / _mm_cvtepi32_ps(v8).m128_f32[0]) - 1.0)
              ^ _mask__NegFloat_;
  ((void (__thiscall *)(CEngineTool *, const CViewSetup *, VMatrix *, int))this->GetWorldToScreenMatrixForView)(
    a1: this,
    a2: viewSetup,
    a3: &worldToScreen,
    a4: a2);
  MatrixInverseGeneral(src: &worldToScreen, dst: &screenToWorld);
  v9 = screenToWorld.m[0][2];
  v10 = (float)(screenToWorld.m[3][1] * yf) + (float)(screenToWorld.m[3][0] * xf);
  v11 = (float)((float)(screenToWorld.m[3][2] * 0.0) + v10) + screenToWorld.m[3][3];
  v12 = (float)(v10 + screenToWorld.m[3][2]) + screenToWorld.m[3][3];
  v13 = 1.0 / v11;
  v14 = (float)(screenToWorld.m[0][1] * yf) + (float)(screenToWorld.m[0][0] * xf);
  v15 = (float)(screenToWorld.m[1][1] * yf) + (float)(screenToWorld.m[1][0] * xf);
  org->y = (float)((float)((float)(screenToWorld.m[1][2] * 0.0) + v15) + screenToWorld.m[1][3]) * v13;
  *(float *)v8.m128i_i32 = (float)(screenToWorld.m[2][1] * yf) + (float)(screenToWorld.m[2][0] * xf);
  v16 = (float)((float)((float)(v9 * 0.0) + v14) + screenToWorld.m[0][3]) * v13;
  v17 = (float)((float)((float)(screenToWorld.m[2][2] * 0.0) + *(float *)v8.m128i_i32) + screenToWorld.m[2][3]) * v13;
  org->x = v16;
  org->z = v17;
  v18 = (float)(v15 + screenToWorld.m[1][2]) + screenToWorld.m[1][3];
  *(float *)v8.m128i_i32 = (float)(*(float *)v8.m128i_i32 + screenToWorld.m[2][2]) + screenToWorld.m[2][3];
  forward->x = (float)((float)((float)(v14 + screenToWorld.m[0][2]) + screenToWorld.m[0][3]) * (float)(1.0 / v12)) - v16;
  forward->y = (float)(v18 * (float)(1.0 / v12)) - org->y;
  forward->z = (float)(*(float *)v8.m128i_i32 * (float)(1.0 / v12)) - org->z;
  VectorNormalize(vec: forward);
}

//------------------------------------------------------------------------------
// Address: 0x101FFCF0
// Name: public: virtual bool CEngineTool::PrecacheSound(char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CEngineTool::PrecacheSound(CEngineTool *this, const char *pName, bool bPreload)
{
  int v5; // esi
  bool bState; // [esp+Ch] [ebp+8h]

  if ( pName != nullptr && TestSoundChar(pch: pName, c: 33) )
    return true;
  bState = CNetworkStringTableContainer::Lock(this: networkStringTableContainerServer, bLock: false);
  v5 = CGameServer::PrecacheSound(this: &sv, name: pName, flags: bPreload ? 2 : 0);
  CNetworkStringTableContainer::Lock(this: networkStringTableContainerServer, bLock: bState);
  return v5 >= 0;
}

//------------------------------------------------------------------------------
// Address: 0x101FFD60
// Name: public: virtual bool CEngineTool::PrecacheModel(char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CEngineTool::PrecacheModel(CEngineTool *this, const char *pName, bool bPreload)
{
  int v3; // esi
  bool bState; // [esp+4h] [ebp-4h]

  bState = CNetworkStringTableContainer::Lock(this: networkStringTableContainerServer, bLock: false);
  v3 = CGameServer::PrecacheModel(this: &sv, name: pName, flags: bPreload ? 2 : 0, model: nullptr);
  CNetworkStringTableContainer::Lock(this: networkStringTableContainerServer, bLock: bState);
  return v3 >= 0;
}

//------------------------------------------------------------------------------
// Address: 0x101FFDB0
// Name: public: virtual void CEngineTool::TakeTGAScreenShot(char const __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineTool::TakeTGAScreenShot(CEngineTool *this, const char *filename, int width, int height)
{
  V_strncpy(pDest: this->m_szScreenshotFile, pSrc: filename, maxLen: 260);
  this->m_nScreenshotWidth = width;
  this->m_nScreenshotHeight = height;
}

//------------------------------------------------------------------------------
// Address: 0x101FFDF0
// Name: public: virtual bool CEngineTool::IsRecordingMovie(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CEngineTool::IsRecordingMovie(CEngineTool *this)
{
  return this->m_bRecordingMovie;
}

//------------------------------------------------------------------------------
// Address: 0x101FFE00
// Name: public: virtual void CEngineTool::StartMovieRecording(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineTool::StartMovieRecording(CEngineTool *this, KeyValues *pMovieParams)
{
  int v4; // edi
  int v5; // eax
  int v6; // ebx
  int v7; // eax
  float Float; // [esp+0h] [ebp-20h]
  const char *defaultValue; // [esp+14h] [ebp-Ch]
  int Int; // [esp+1Ch] [ebp-4h]
  KeyValues *v12; // [esp+28h] [ebp+8h]

  if ( CL_IsRecordingMovie() )
  {
    _Warning(a1: "Can't record movie, already recording!!!\n");
  }
  else if ( !this->m_bRecordingMovie )
  {
    v4 = 0;
    Int = 50;
    if ( KeyValues::GetInt(this: pMovieParams, keyName: "outputavi", defaultValue: 0) != 0 )
      v4 = KeyValues::GetInt(this: pMovieParams, keyName: "avisoundonly", defaultValue: 0) != 0 ? 8 : 10;
    if ( KeyValues::GetInt(this: pMovieParams, keyName: "outputtga", defaultValue: 0) != 0 )
      v4 |= 1u;
    if ( KeyValues::GetInt(this: pMovieParams, keyName: "outputjpg", defaultValue: 0) != 0 )
    {
      v4 |= 0x10u;
      Int = KeyValues::GetInt(this: pMovieParams, keyName: "jpeg_quality", defaultValue: 0);
    }
    if ( KeyValues::GetInt(this: pMovieParams, keyName: "outputwav", defaultValue: 0) != 0 )
      v4 |= 4u;
    defaultValue = KeyValues::GetString(this: pMovieParams, keyName: "filename", defaultValue: nullptr);
    if ( defaultValue != nullptr )
    {
      v5 = videomode->GetModeWidth(this: videomode);
      v6 = KeyValues::GetInt(this: pMovieParams, keyName: "width", defaultValue: v5);
      v7 = videomode->GetModeHeight(this: videomode);
      v12 = (KeyValues *)KeyValues::GetInt(this: pMovieParams, keyName: "height", defaultValue: v7);
      Float = KeyValues::GetFloat(this: pMovieParams, keyName: "framerate", defaultValue: 30.0);
      this->m_bRecordingMovie = true;
      CL_StartMovie(
        filename: defaultValue,
        flags: v4,
        nWidth: v6,
        nHeight: (int)v12,
        flFrameRate: Float,
        jpeg_quality: Int);
    }
    else
    {
      _Warning(a1: "Output filename not specified!\n");
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101FFF70
// Name: public: virtual void CEngineTool::EndMovieRecording(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineTool::EndMovieRecording(CEngineTool *this)
{
  if ( this->m_bRecordingMovie )
  {
    CL_EndMovie();
    this->m_bRecordingMovie = false;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101FFF90
// Name: public: virtual void CEngineTool::CancelMovieRecording(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineTool::CancelMovieRecording(CEngineTool *this)
{
  this->EndMovieRecording(this);
}

//------------------------------------------------------------------------------
// Address: 0x101FFFA0
// Name: public: virtual unsigned short CEngineTool::GetRecordingAVIHandle(void)
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall CEngineTool::GetRecordingAVIHandle(CEngineTool *this)
{
  if ( CL_IsRecordingMovie() )
    return g_hCurrentAVI;
  else
    return -1;
}

//------------------------------------------------------------------------------
// Address: 0x101FFFC0
// Name: public: virtual void CEngineTool::StartRecordingVoiceToFile(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineTool::StartRecordingVoiceToFile(CEngineTool *this, const char *filename, const char *pPathID)
{
  const char *v3; // ebx
  void *v5; // eax
  void *v6; // edi

  v3 = pPathID;
  v5 = g_pFileSystem->Open(this: &g_pFileSystem->IBaseFileSystem, a2: filename, a3: "wb", a4: pPathID);
  v6 = v5;
  if ( v5 != nullptr )
  {
    HIBYTE(pPathID) = 98;
    g_pFileSystem->Write(this: &g_pFileSystem->IBaseFileSystem, a2: (char *)&pPathID + 3, a3: 1, a4: v5);
    g_pFileSystem->Close(this: &g_pFileSystem->IBaseFileSystem, a2: v6);
  }
  g_pFileSystem->RelativePathToFullPath(
    this: g_pFileSystem,
    a2: filename,
    a3: v3,
    a4: this->m_szVoiceoverFile,
    a5: 260,
    a6: FILTER_NONE,
    a7: nullptr);
  g_pFileSystem->RemoveFile(this: g_pFileSystem, a2: filename, a3: v3);
  if ( this->IsVoiceRecording(this) )
    Voice_RecordStop();
  this->m_bSuppressDeInit = true;
  Voice_ForceInit();
  Voice_RecordStart(pUncompressedFile: this->m_szVoiceoverFile, pDecompressedFile: nullptr, pMicInputFile: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x10200090
// Name: public: virtual void CEngineTool::StopRecordingVoiceToFile(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineTool::StopRecordingVoiceToFile(CEngineTool *this)
{
  Voice_RecordStop();
  this->m_bSuppressDeInit = false;
}

//------------------------------------------------------------------------------
// Address: 0x102000B0
// Name: public: virtual float CEngineTool::GetMono16Samples(char const __near *,class CUtlVector<short,class CUtlMemory<short,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
float __thiscall CEngineTool::GetMono16Samples(
        CEngineTool *this,
        const char *pszName,
        CUtlVector<short,CUtlMemory<short,int> > *sampleList)
{
  return S_GetMono16Samples(pszName, sampleList);
}

//------------------------------------------------------------------------------
// Address: 0x102000D0
// Name: public: virtual void CEngineTool::GetWorldToScreenMatrixForView(class CViewSetup const __near &,class VMatrix __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineTool::GetWorldToScreenMatrixForView(
        CEngineTool *this,
        const CViewSetup *view,
        VMatrix *pVMatrix)
{
  VMatrix worldToView; // [esp+0h] [ebp-80h] BYREF
  VMatrix viewToProjection; // [esp+40h] [ebp-40h] BYREF

  ComputeViewMatrices(
    pWorldToView: &worldToView,
    pViewToProjection: &viewToProjection,
    pWorldToProjection: pVMatrix,
    viewSetup: view);
}

//------------------------------------------------------------------------------
// Address: 0x10200100
// Name: public: virtual unsigned short CEngineTool::CreatePartitionHandle(class IHandleEntity __near *,int,class Vector const __near &,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall CEngineTool::CreatePartitionHandle(
        CEngineTool *this,
        IHandleEntity *pEntity,
        int listMask,
        const Vector *mins,
        const Vector *maxs)
{
  ISpatialPartitionInternal *v5; // eax

  v5 = SpatialPartition();
  return v5->CreateHandle(this: v5, a2: pEntity, a3: listMask, a4: mins, a5: maxs);
}

//------------------------------------------------------------------------------
// Address: 0x10200120
// Name: public: virtual void CEngineTool::DestroyPartitionHandle(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineTool::DestroyPartitionHandle(CEngineTool *this, int hPartition)
{
  ISpatialPartitionInternal *v2; // eax

  v2 = SpatialPartition();
  v2->DestroyHandle(this: v2, a2: hPartition);
}

//------------------------------------------------------------------------------
// Address: 0x10200140
// Name: public: virtual void CEngineTool::InstallPartitionQueryCallback(class IPartitionQueryCallback __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineTool::InstallPartitionQueryCallback(CEngineTool *this, IPartitionQueryCallback *pQuery)
{
  ISpatialPartitionInternal *v2; // eax

  v2 = SpatialPartition();
  v2->InstallQueryCallback(this: v2, a2: pQuery);
}

//------------------------------------------------------------------------------
// Address: 0x10200160
// Name: public: virtual void CEngineTool::RemovePartitionQueryCallback(class IPartitionQueryCallback __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineTool::RemovePartitionQueryCallback(CEngineTool *this, IPartitionQueryCallback *pQuery)
{
  ISpatialPartitionInternal *v2; // eax

  v2 = SpatialPartition();
  v2->RemoveQueryCallback(this: v2, a2: pQuery);
}

//------------------------------------------------------------------------------
// Address: 0x10200180
// Name: public: virtual void CEngineTool::ElementMoved(unsigned short,class Vector const __near &,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineTool::ElementMoved(CEngineTool *this, int handle, const Vector *mins, const Vector *maxs)
{
  ISpatialPartitionInternal *v4; // eax

  v4 = SpatialPartition();
  v4->ElementMoved(this: v4, a2: handle, a3: mins, a4: maxs);
}

//------------------------------------------------------------------------------
// Address: 0x102001A0
// Name: public: virtual bool CEngineTool::IsVoiceRecording(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
bool __thiscall CEngineTool::IsVoiceRecording(CEngineTool *this)
{
  return Voice_IsRecording();
}

//------------------------------------------------------------------------------
// Address: 0x102001B0
// Name: public: virtual void CEngineTool::OnModeChanged(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineTool::OnModeChanged(CEngineTool *this, BOOL bGameMode)
{
  IEngineVGuiInternal *v2; // eax

  v2 = EngineVGui();
  v2->OnToolModeChanged(this: v2, a2: bGameMode);
}

//------------------------------------------------------------------------------
// Address: 0x102001D0
// Name: bool EngineTool_SuppressDeInit(void)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl EngineTool_SuppressDeInit()
{
  return g_EngineTool.m_bSuppressDeInit;
}

//------------------------------------------------------------------------------
// Address: 0x102001E0
// Name: void EngineTool_OverrideSampleRate(int __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl EngineTool_OverrideSampleRate(int *rate)
{
  if ( g_EngineTool.m_bSuppressDeInit )
    *rate = 11025;
}

//------------------------------------------------------------------------------
// Address: 0x10200210
// Name: void EngineTool_UpdateScreenshot(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl EngineTool_UpdateScreenshot()
{
  if ( !g_LostVideoMemory && g_EngineTool.m_szScreenshotFile[0] != 0 )
  {
    g_ClientDLL->WriteSaveGameScreenshotOfSize(
      this: g_ClientDLL,
      a2: g_EngineTool.m_szScreenshotFile,
      a3: g_EngineTool.m_nScreenshotWidth,
      a4: g_EngineTool.m_nScreenshotHeight,
      a5: false,
      a6: false);
    g_EngineTool.m_szScreenshotFile[0] = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10200260
// Name: public: virtual void CEngineTool::TraceRay(struct Ray_t const __near &,unsigned int,class ITraceFilter __near *,class CBaseTrace __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineTool::TraceRay(
        CEngineTool *this,
        const Ray_t *ray,
        unsigned int fMask,
        ITraceFilter *pTraceFilter,
        CBaseTrace *pTrace)
{
  CGameTrace tempTrace; // [esp+8h] [ebp-54h] BYREF

  g_pEngineTraceClient->TraceRay(this: g_pEngineTraceClient, a2: ray, a3: fMask, a4: pTraceFilter, a5: &tempTrace);
  *pTrace = tempTrace.CBaseTrace;
}

//------------------------------------------------------------------------------
// Address: 0x102002A0
// Name: public: virtual void CEngineTool::TraceRayServer(struct Ray_t const __near &,unsigned int,class ITraceFilter __near *,class CBaseTrace __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineTool::TraceRayServer(
        CEngineTool *this,
        const Ray_t *ray,
        unsigned int fMask,
        ITraceFilter *pTraceFilter,
        CBaseTrace *pTrace)
{
  CGameTrace tempTrace; // [esp+8h] [ebp-54h] BYREF

  g_pEngineTraceServer->TraceRay(this: g_pEngineTraceServer, a2: ray, a3: fMask, a4: pTraceFilter, a5: &tempTrace);
  *pTrace = tempTrace.CBaseTrace;
}

//------------------------------------------------------------------------------
// Address: 0x102002E0
// Name: bool EngineTool_CheckQuitHandlers(void)
// Source: json
//------------------------------------------------------------------------------
char __cdecl EngineTool_CheckQuitHandlers()
{
  int v0; // esi
  int m_Size; // edi
  CEngineTool::QuitHandler_t *m_pMemory; // ecx
  bool (__cdecl *func)(void *); // eax

  v0 = 0;
  m_Size = g_EngineTool.m_QuitHandlers.m_Size;
  if ( g_EngineTool.m_QuitHandlers.m_Size <= 0 )
    return 1;
  m_pMemory = g_EngineTool.m_QuitHandlers.m_Memory.m_pMemory;
  while ( 1 )
  {
    func = m_pMemory[v0].func;
    if ( func != nullptr )
      break;
LABEL_6:
    if ( ++v0 >= m_Size )
      return 1;
  }
  if ( func(a1: m_pMemory[v0].userdata) )
  {
    m_pMemory = g_EngineTool.m_QuitHandlers.m_Memory.m_pMemory;
    goto LABEL_6;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10200350
// Name: public: virtual void CEngineTool::InstallQuitHandler(void __near *,bool (*)(void __near *))
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineTool::InstallQuitHandler(CEngineTool *this, void *pvUserData, bool (__cdecl *func)(void *))
{
  CEngineTool::QuitHandler_t qh; // [esp+0h] [ebp-8h] BYREF

  qh.userdata = pvUserData;
  qh.func = func;
  CUtlVector<RegisteredDemoCustomDataCallbackPair_t,CUtlMemory<RegisteredDemoCustomDataCallbackPair_t,int>>::InsertBefore(
    this: (CUtlVector<vgui::PropertySheet::Page_t,CUtlMemory<vgui::PropertySheet::Page_t,int> > *)&this->m_QuitHandlers,
    elem: this->m_QuitHandlers.m_Size,
    src: (const vgui::PropertySheet::Page_t *)&qh);
}

//------------------------------------------------------------------------------
// Address: 0x10200380
// Name: void EngineTool_InstallQuitHandler(void __near *,bool (*)(void __near *))
// Source: json
//------------------------------------------------------------------------------
void __cdecl EngineTool_InstallQuitHandler(vgui::Panel *pvUserData, bool (__cdecl *func)(void *))
{
  vgui::PropertySheet::Page_t src; // [esp+0h] [ebp-8h] BYREF

  src.page = pvUserData;
  *(_DWORD *)&src.contextMenu = func;
  CUtlVector<RegisteredDemoCustomDataCallbackPair_t,CUtlMemory<RegisteredDemoCustomDataCallbackPair_t,int>>::InsertBefore(
    this: (CUtlVector<vgui::PropertySheet::Page_t,CUtlMemory<vgui::PropertySheet::Page_t,int> > *)&g_EngineTool.m_QuitHandlers,
    elem: g_EngineTool.m_QuitHandlers.m_Size,
    &src);
}

//------------------------------------------------------------------------------
// Address: 0x10200200
// Name: __CreateCEngineToolIEngineToolFramework_interface
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CEngineTool *__cdecl _CreateCEngineToolIEngineToolFramework_interface()
{
  return &g_EngineTool;
}

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x1006EED0
// Name: public: virtual void CEngineTool::SetAudioState(struct AudioState_t const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineTool::SetAudioState(CEngineClient *this, const AudioState_t *audioState)
{
  Host_SetAudioState(audioState);
}

//------------------------------------------------------------------------------
// Address: 0x1006F070
// Name: public: virtual bool CEngineTool::IsGamePaused(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CEngineTool::IsGamePaused(CEngineClient *this)
{
  CClientState *BaseLocalClient; // eax

  BaseLocalClient = GetBaseLocalClient();
  return CClientState::IsPaused(this: BaseLocalClient);
}

//------------------------------------------------------------------------------
// Address: 0x101FF4E0
// Name: public: virtual int CEngineTool::GetPointContents(class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CEngineTool::GetPointContents(CEngineTool *this, const Vector *vecPosition)
{
  return g_pEngineTraceClient->GetPointContents(this: g_pEngineTraceClient, a2: vecPosition, a3: 0, a4: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x101FF500
// Name: public: virtual int CEngineTool::GetActiveDLights(struct dlight_t __near * __near * const)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CEngineTool::GetActiveDLights(CEngineTool *this, dlight_t **pList)
{
  return g_pEfx->CL_GetActiveDLights(this: g_pEfx, a2: pList);
}

//------------------------------------------------------------------------------
// Address: 0x101FF520
// Name: public: virtual int CEngineTool::GetLightingConditions(class Vector const __near &,class Vector __near *,int,struct LightDesc_t __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CEngineTool::GetLightingConditions(
        CEngineTool *this,
        const Vector *vecLightingOrigin,
        Vector *pColors,
        int nMaxLocalLights,
        LightDesc_t *pLocalLights)
{
  int v5; // ebx
  int v6; // edi
  float *p_y; // esi
  float v8; // xmm0_4
  LightingState_t state; // [esp+0h] [ebp-5Ch] BYREF

  v5 = 0;
  memset(&state, 0, 76);
  LightcacheGetDynamic(
    origin: vecLightingOrigin,
    lightingState: &state,
    stats: (LightcacheGetDynamic_Stats *)&vecLightingOrigin,
    pRenderable: nullptr,
    flags: 7u,
    bDebugModel: false);
  qmemcpy(pColors, &state, 72);
  v6 = 0;
  if ( state.numlights > 0 )
  {
    p_y = &pLocalLights->m_Color.y;
    do
    {
      if ( WorldLightToMaterialLight(pWorldLight: state.locallight[v5], light: (LightDesc_t *)(p_y - 2)) )
      {
        v8 = (float)d_lightstylevalue[state.locallight[v5]->style] * 0.0037878789;
        *(p_y - 1) = *(p_y - 1) * v8;
        *p_y = *p_y * v8;
        p_y[1] = v8 * p_y[1];
        ++v6;
        p_y += 22;
        if ( v6 >= nMaxLocalLights )
          break;
      }
      ++v5;
    }
    while ( v5 < state.numlights );
  }
  return v6;
}

//------------------------------------------------------------------------------
// Address: 0x101FF690
// Name: public: virtual void CEngineTool::Execute(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall CEngineTool::Execute(CVEngineServer *this)
{
  Cbuf_Execute();
}

//------------------------------------------------------------------------------
// Address: 0x101FF6A0
// Name: public: virtual char const __near * CEngineTool::GetCurrentMap(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CEngineTool::GetCurrentMap(CEngineTool *this)
{
  if ( sv.m_bIsDedicated )
    return "Dedicated Server";
  if ( GetBaseLocalClient()->m_nSignonState >= 2 )
    return GetBaseLocalClient()->m_szLevelName;
  if ( sv.m_State == ss_loading )
    return sv.m_szMapname;
  return defaultValue;
}

//------------------------------------------------------------------------------
// Address: 0x101FF6E0
// Name: public: virtual void CEngineTool::ChangeToMap(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineTool::ChangeToMap(CEngineTool *this, const char *mapname)
{
  vgui::CTreeViewListControl *v2; // ecx
  ECommandTarget_t TraceType; // eax
  const char *v4; // [esp-8h] [ebp-Ch]

  if ( modelloader->Map_IsValid(this: modelloader, a2: mapname, a3: false) )
  {
    v4 = va(format: "map \"%s\"\n", mapname);
    TraceType = CTraceFilter::GetTraceType(this: v2);
    Cbuf_AddText(eTarget: TraceType, pText: v4, nTickDelay: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101FF7A0
// Name: public: virtual void CEngineTool::SetGamePaused(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineTool::SetGamePaused(CEngineTool *this, bool paused)
{
  CBaseServer::SetPaused(this: &sv, paused);
}

//------------------------------------------------------------------------------
// Address: 0x101FF7C0
// Name: public: virtual void CEngineTool::SetTimescale(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineTool::SetTimescale(CEngineTool *this, float scale)
{
  ConVar::SetValue(this: (ConVar *)&host_timescale.IConVar, value: scale);
}

//------------------------------------------------------------------------------
// Address: 0x101FF800
// Name: public: virtual float CEngineTool::GetRealFrameTime(void)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CEngineTool::GetRealFrameTime(CEngineTool *this)
{
  return host_frametime_unscaled;
}

//------------------------------------------------------------------------------
// Address: 0x101FF820
// Name: public: virtual int CEngineTool::HostTick(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CEngineTool::HostTick(CEngineTool *this)
{
  return host_tickcount;
}

//------------------------------------------------------------------------------
// Address: 0x101FF830
// Name: public: virtual int CEngineTool::HostFrameCount(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CEngineTool::HostFrameCount(CEngineTool *this)
{
  return host_framecount;
}

//------------------------------------------------------------------------------
// Address: 0x101FF840
// Name: public: virtual float CEngineTool::ServerTime(void)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CEngineTool::ServerTime(CEngineTool *this)
{
  return g_ServerGlobalVariables.curtime;
}

//------------------------------------------------------------------------------
// Address: 0x101FF850
// Name: public: virtual float CEngineTool::ServerFrameTime(void)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CEngineTool::ServerFrameTime(CEngineTool *this)
{
  return g_ServerGlobalVariables.frametime;
}

//------------------------------------------------------------------------------
// Address: 0x101FF860
// Name: public: virtual int CEngineTool::ServerTick(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CEngineTool::ServerTick(CEngineTool *this)
{
  return g_ServerGlobalVariables.tickcount;
}

//------------------------------------------------------------------------------
// Address: 0x101FF870
// Name: public: virtual float CEngineTool::ServerTickInterval(void)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CEngineTool::ServerTickInterval(CEngineTool *this)
{
  return g_ServerGlobalVariables.interval_per_tick;
}

//------------------------------------------------------------------------------
// Address: 0x101FF880
// Name: public: virtual float CEngineTool::ClientTime(void)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CEngineTool::ClientTime(CEngineTool *this)
{
  return g_ClientGlobalVariables.curtime;
}

//------------------------------------------------------------------------------
// Address: 0x101FF890
// Name: public: virtual float CEngineTool::ClientFrameTime(void)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CEngineTool::ClientFrameTime(CEngineTool *this)
{
  return g_ClientGlobalVariables.frametime;
}

//------------------------------------------------------------------------------
// Address: 0x101FF8A0
// Name: public: virtual int CEngineTool::ClientTick(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CEngineTool::ClientTick(CEngineTool *this)
{
  return g_ClientGlobalVariables.tickcount;
}

//------------------------------------------------------------------------------
// Address: 0x101FF8B0
// Name: public: virtual void CEngineTool::SetClientFrameTime(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineTool::SetClientFrameTime(CEngineTool *this, float frametime)
{
  g_ClientGlobalVariables.frametime = frametime;
}

//------------------------------------------------------------------------------
// Address: 0x101FF8D0
// Name: public: virtual void CEngineTool::ForceSend(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall CEngineTool::ForceSend(CEngineTool *this)
{
  SV_ForceSend();
}

//------------------------------------------------------------------------------
// Address: 0x101FF8E0
// Name: public: virtual void CEngineTool::Con_NPrintf(int,char const __near *,...)
// Source: json
//------------------------------------------------------------------------------
void CEngineTool::Con_NPrintf(CEngineTool *this, int pos, const char *fmt, ...)
{
  char buf[1024]; // [esp+0h] [ebp-400h] BYREF
  va_list ap; // [esp+414h] [ebp+14h] BYREF

  va_start(ap, fmt);
  _vsnprintf(string: buf, count: 0x3FFu, format: fmt, ap);
  Con_NPrintf(idx: pos, fmt: "%s", buf);
}

//------------------------------------------------------------------------------
// Address: 0x101FF920
// Name: public: virtual void CEngineTool::Con_NXPrintf(struct con_nprint_s const __near *,char const __near *,...)
// Source: json
//------------------------------------------------------------------------------
void CEngineTool::Con_NXPrintf(CEngineTool *this, const con_nprint_s *info, const char *fmt, ...)
{
  char buf[1024]; // [esp+0h] [ebp-400h] BYREF
  va_list ap; // [esp+414h] [ebp+14h] BYREF

  va_start(ap, fmt);
  _vsnprintf(string: buf, count: 0x3FFu, format: fmt, ap);
  Con_NXPrintf(info, fmt: "%s", buf);
}

//------------------------------------------------------------------------------
// Address: 0x101FF960
// Name: public: virtual void CEngineTool::GetGameDir(char __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineTool::GetGameDir(CEngineTool *this, char *szGetGameDir, int maxlength)
{
  V_strncpy(pDest: szGetGameDir, pSrc: com_gamedir, maxLen: maxlength);
}

//------------------------------------------------------------------------------
// Address: 0x101FF980
// Name: public: virtual int CEngineTool::GetToolCount(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CEngineTool::GetToolCount(CEngineTool *this)
{
  return toolframework->GetToolCount(this: toolframework);
}

//------------------------------------------------------------------------------
// Address: 0x101FF9D0
// Name: public: virtual bool CEngineTool::IsTopmostTool(class IToolSystem const __near *)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CEngineTool::IsTopmostTool(CEngineTool *this, const IToolSystem *sys)
{
  return toolframework->IsTopmostTool(this: toolframework, a2: sys);
}

//------------------------------------------------------------------------------
// Address: 0x101FF9F0
// Name: public: virtual class IToolSystem __near * CEngineTool::GetTopmostTool(void)
// Source: json
//------------------------------------------------------------------------------
IToolSystem *__thiscall CEngineTool::GetTopmostTool(CEngineTool *this)
{
  return toolframework->GetTopmostTool(this: toolframework);
}

//------------------------------------------------------------------------------
// Address: 0x101FFA60
// Name: public: virtual void CEngineTool::PrefetchSound(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineTool::PrefetchSound(CEngineTool *this, const char *pchSoundName)
{
  S_PrefetchSound(name: pchSoundName, bPlayOnce: false);
}

//------------------------------------------------------------------------------
// Address: 0x101FFA80
// Name: public: virtual int CEngineTool::StartSound(int,bool,int,int,char const __near *,float,enum soundlevel_t,class Vector const __near &,class Vector const __near &,int,int,bool,float,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CEngineTool::StartSound(
        CEngineTool *this,
        int iUserData,
        bool staticsound,
        int iEntIndex,
        int iChannel,
        const char *pSample,
        float flVolume,
        soundlevel_t iSoundlevel,
        const Vector *origin,
        const Vector *direction,
        int iFlags,
        int iPitch,
        bool bUpdatePositions,
        float delay,
        int speakerentity)
{
  float z; // xmm0_4
  StartSoundParams_t params; // [esp+0h] [ebp-64h] BYREF

  params.flags = 0;
  params.initialStreamPosition = 0;
  params.skipInitialSamples = 0;
  memset(&params.m_pSoundEntryName, 0, 16);
  params.speakerentity = -1;
  params.m_nQueuedGUID = -1;
  params.m_nSoundScriptHandle = -1;
  params.userdata = iUserData;
  *((_BYTE *)&params + 96) = (staticsound
                            ^ (*((_BYTE *)&params + 96) & 0xC0 | 2))
                           & 1
                           ^ (*((_BYTE *)&params + 96) & 0xC0 | 2);
  params.fvol = 1.0;
  params.soundlevel = SNDLVL_NORM;
  params.pitch = 100;
  params.delay = 0.0;
  memset(&params.origin, 0, 24);
  params.soundsource = iEntIndex;
  params.entchannel = iChannel;
  params.pSfx = S_PrecacheSound(name: pSample);
  params.origin = *origin;
  params.direction.x = direction->x;
  params.direction.y = direction->y;
  z = direction->z;
  params.soundlevel = iSoundlevel;
  params.direction.z = z;
  params.pitch = iPitch;
  params.flags = iFlags;
  params.fvol = flVolume;
  params.delay = delay;
  params.speakerentity = speakerentity;
  *((_BYTE *)&params + 96) = ((*((_BYTE *)&params + 96) ^ (2 * bUpdatePositions)) & 2 ^ *((_BYTE *)&params + 96)) & 0xF3
                           | 8;
  return S_StartSound(&params);
}

//------------------------------------------------------------------------------
// Address: 0x101FFBC0
// Name: public: virtual void CEngineTool::StopSoundByGuid(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineTool::StopSoundByGuid(CEngineTool *this, int guid)
{
  S_StopSoundByGuid(guid, bForceSync: false);
}

//------------------------------------------------------------------------------
// Address: 0x101FFBE0
// Name: public: virtual float CEngineTool::GetSoundDuration(int)
// Source: json
//------------------------------------------------------------------------------
float __thiscall CEngineTool::GetSoundDuration(CEngineTool *this, int guid)
{
  return S_SoundDurationByGuid(guid);
}

//------------------------------------------------------------------------------
// Address: 0x101FFC00
// Name: public: virtual float CEngineTool::GetSoundElapsedTime(int)
// Source: json
//------------------------------------------------------------------------------
float __thiscall CEngineTool::GetSoundElapsedTime(CEngineSoundClient *this, int guid)
{
  return S_GetElapsedTimeByGuid(guid);
}

//------------------------------------------------------------------------------
// Address: 0x101FFC20
// Name: public: virtual void __near * CEngineTool::GetEngineHwnd(void)
// Source: json
//------------------------------------------------------------------------------
void *__thiscall CEngineTool::GetEngineHwnd(CEngineTool *this)
{
  return game->GetMainWindow(this: game);
}

//------------------------------------------------------------------------------
// Address: 0x101FFC30
// Name: public: virtual void CEngineTool::ReloadSound(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineTool::ReloadSound(CEngineTool *this, const char *pSample)
{
  S_ReloadSound(name: pSample);
}

//------------------------------------------------------------------------------
// Address: 0x101FFC60
// Name: public: virtual bool CEngineTool::IsLoopingSound(int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CEngineTool::IsLoopingSound(CEngineTool *this, int guid)
{
  return S_IsLoopingSoundByGuid(guid);
}

//------------------------------------------------------------------------------
// Address: 0x101FFC80
// Name: public: virtual void CEngineTool::SetMainView(class Vector const __near &,class QAngle const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineTool::SetMainView(CVRenderView *this, const Vector *vecOrigin, const QAngle *angles)
{
  g_EngineRenderer->SetMainView(this: g_EngineRenderer, a2: vecOrigin, a3: angles);
}

//------------------------------------------------------------------------------
// Address: 0x101FFCA0
// Name: public: virtual bool CEngineTool::GetPlayerView(class CViewSetup __near &,int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CEngineTool::GetPlayerView(CEngineTool *this, CViewSetup *viewSetup, int x, int y, int w, int h)
{
  bool result; // al
  float v7; // xmm0_4
  double v8; // st7

  if ( g_ClientDLL == nullptr )
    return false;
  result = g_ClientDLL->GetPlayerView(this: g_ClientDLL, a2: viewSetup);
  if ( result )
  {
    viewSetup->x = x;
    viewSetup->y = y;
    viewSetup->width = w;
    viewSetup->height = h;
    if ( h != 0 )
      v7 = (float)w / (float)h;
    else
      v7 = 1.3333334;
    *((_BYTE *)viewSetup + 240) |= 2u;
    v8 = v7 * 0.75;
    viewSetup->m_flAspectRatio = v7;
    viewSetup->fov = atan2(tan(viewSetup->fov * 0.008726646259971648) * v8, 1.0) * 57.29577951308232 * 2.0;
    viewSetup->fovViewmodel = 2.0
                            * (57.29577951308232
                             * atan2(v8 * tan(0.008726646259971648 * viewSetup->fovViewmodel), 1.0));
    return true;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101FFD80
// Name: public: virtual void CEngineTool::CreatePickingRay(class CViewSetup const __near &,int,int,class Vector __near &,class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CEngineTool::CreatePickingRay(
        CEngineTool *this@<ecx>,
        int a2@<esi>,
        const CViewSetup *viewSetup,
        int x,
        int y,
        Vector *org,
        Vector *forward)
{
  __m128i v8; // xmm2
  float v9; // xmm4_4
  float v10; // xmm3_4
  float v11; // xmm0_4
  float v12; // xmm3_4
  float v13; // xmm5_4
  float v14; // xmm0_4
  float v15; // xmm1_4
  float v16; // xmm4_4
  float v17; // xmm7_4
  float v18; // xmm1_4
  VMatrix worldToScreen; // [esp+0h] [ebp-80h] BYREF
  VMatrix screenToWorld; // [esp+40h] [ebp-40h] BYREF
  float xf; // [esp+88h] [ebp+8h]
  float yf; // [esp+8Ch] [ebp+Ch]

  v8 = _mm_cvtsi32_si128(viewSetup->height);
  xf = (float)((float)((float)x * 2.0) / (float)viewSetup->width) - 1.0;
  LODWORD(yf) = COERCE_UNSIGNED_INT((float)((float)((float)y * 2.0) / _mm_cvtepi32_ps(v8).m128_f32[0]) - 1.0)
              ^ _mask__NegFloat_;
  ((void (__thiscall *)(CEngineTool *, const CViewSetup *, VMatrix *, int))this->GetWorldToScreenMatrixForView)(
    a1: this,
    a2: viewSetup,
    a3: &worldToScreen,
    a4: a2);
  MatrixInverseGeneral(src: &worldToScreen, dst: &screenToWorld);
  v9 = screenToWorld.m[0][2];
  v10 = (float)(screenToWorld.m[3][1] * yf) + (float)(screenToWorld.m[3][0] * xf);
  v11 = (float)((float)(screenToWorld.m[3][2] * 0.0) + v10) + screenToWorld.m[3][3];
  v12 = (float)(v10 + screenToWorld.m[3][2]) + screenToWorld.m[3][3];
  v13 = 1.0 / v11;
  v14 = (float)(screenToWorld.m[0][1] * yf) + (float)(screenToWorld.m[0][0] * xf);
  v15 = (float)(screenToWorld.m[1][1] * yf) + (float)(screenToWorld.m[1][0] * xf);
  org->y = (float)((float)((float)(screenToWorld.m[1][2] * 0.0) + v15) + screenToWorld.m[1][3]) * v13;
  *(float *)v8.m128i_i32 = (float)(screenToWorld.m[2][1] * yf) + (float)(screenToWorld.m[2][0] * xf);
  v16 = (float)((float)((float)(v9 * 0.0) + v14) + screenToWorld.m[0][3]) * v13;
  v17 = (float)((float)((float)(screenToWorld.m[2][2] * 0.0) + *(float *)v8.m128i_i32) + screenToWorld.m[2][3]) * v13;
  org->x = v16;
  org->z = v17;
  v18 = (float)(v15 + screenToWorld.m[1][2]) + screenToWorld.m[1][3];
  *(float *)v8.m128i_i32 = (float)(*(float *)v8.m128i_i32 + screenToWorld.m[2][2]) + screenToWorld.m[2][3];
  forward->x = (float)((float)((float)(v14 + screenToWorld.m[0][2]) + screenToWorld.m[0][3]) * (float)(1.0 / v12)) - v16;
  forward->y = (float)(v18 * (float)(1.0 / v12)) - org->y;
  forward->z = (float)(*(float *)v8.m128i_i32 * (float)(1.0 / v12)) - org->z;
  VectorNormalize(vec: forward);
}

//------------------------------------------------------------------------------
// Address: 0x101FFF50
// Name: public: virtual bool CEngineTool::PrecacheSound(char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CEngineTool::PrecacheSound(CEngineTool *this, const char *pName, bool bPreload)
{
  int v5; // esi
  bool bState; // [esp+Ch] [ebp+8h]

  if ( pName != nullptr && TestSoundChar(pch: pName, c: 33) )
    return true;
  bState = CNetworkStringTableContainer::Lock(this: networkStringTableContainerServer, bLock: false);
  v5 = CGameServer::PrecacheSound(this: &sv, name: pName, flags: bPreload ? 2 : 0);
  CNetworkStringTableContainer::Lock(this: networkStringTableContainerServer, bLock: bState);
  return v5 >= 0;
}

//------------------------------------------------------------------------------
// Address: 0x10200010
// Name: public: virtual void CEngineTool::TakeTGAScreenShot(char const __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineTool::TakeTGAScreenShot(CEngineTool *this, const char *filename, int width, int height)
{
  V_strncpy(pDest: this->m_szScreenshotFile, pSrc: filename, maxLen: 260);
  this->m_nScreenshotWidth = width;
  this->m_nScreenshotHeight = height;
}

//------------------------------------------------------------------------------
// Address: 0x10200050
// Name: public: virtual bool CEngineTool::IsRecordingMovie(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CEngineTool::IsRecordingMovie(CEngineTool *this)
{
  return this->m_bRecordingMovie;
}

//------------------------------------------------------------------------------
// Address: 0x10200060
// Name: public: virtual void CEngineTool::StartMovieRecording(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineTool::StartMovieRecording(CEngineTool *this, KeyValues *pMovieParams)
{
  int v4; // edi
  int defaultValue; // eax
  int Int; // ebx
  int v7; // eax
  float flFrameRate; // [esp+0h] [ebp-20h]
  const char *pFileName; // [esp+14h] [ebp-Ch]
  int jpeg_quality; // [esp+1Ch] [ebp-4h]
  int nHeight; // [esp+28h] [ebp+8h]

  if ( CL_IsRecordingMovie() )
  {
    _Warning(a1: "Can't record movie, already recording!!!\n");
  }
  else if ( !this->m_bRecordingMovie )
  {
    v4 = 0;
    jpeg_quality = 50;
    if ( KeyValues::GetInt(this: pMovieParams, keyName: "outputavi", defaultValue: 0) != 0 )
      v4 = KeyValues::GetInt(this: pMovieParams, keyName: "avisoundonly", defaultValue: 0) != 0 ? 8 : 10;
    if ( KeyValues::GetInt(this: pMovieParams, keyName: "outputtga", defaultValue: 0) != 0 )
      v4 |= 1u;
    if ( KeyValues::GetInt(this: pMovieParams, keyName: "outputjpg", defaultValue: 0) != 0 )
    {
      v4 |= 0x10u;
      jpeg_quality = KeyValues::GetInt(this: pMovieParams, keyName: "jpeg_quality", defaultValue: 0);
    }
    if ( KeyValues::GetInt(this: pMovieParams, keyName: "outputwav", defaultValue: 0) != 0 )
      v4 |= 4u;
    pFileName = KeyValues::GetString(this: pMovieParams, keyName: "filename", defaultValue: nullptr);
    if ( pFileName != nullptr )
    {
      defaultValue = videomode->GetModeWidth(this: videomode);
      Int = KeyValues::GetInt(this: pMovieParams, keyName: "width", defaultValue);
      v7 = videomode->GetModeHeight(this: videomode);
      nHeight = KeyValues::GetInt(this: pMovieParams, keyName: "height", defaultValue: v7);
      flFrameRate = KeyValues::GetFloat(this: pMovieParams, keyName: "framerate", defaultValue: 30.0);
      this->m_bRecordingMovie = true;
      CL_StartMovie(filename: pFileName, flags: v4, nWidth: Int, nHeight, flFrameRate, jpeg_quality);
    }
    else
    {
      _Warning(a1: "Output filename not specified!\n");
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102001F0
// Name: public: virtual void CEngineTool::CancelMovieRecording(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineTool::CancelMovieRecording(CEngineTool *this)
{
  this->EndMovieRecording(this);
}

//------------------------------------------------------------------------------
// Address: 0x10200220
// Name: public: virtual void CEngineTool::StartRecordingVoiceToFile(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineTool::StartRecordingVoiceToFile(CEngineTool *this, const char *filename, const char *pPathID)
{
  const char *v3; // ebx
  void *v5; // eax
  void *v6; // edi

  v3 = pPathID;
  v5 = g_pFileSystem->Open(this: &g_pFileSystem->IBaseFileSystem, a2: filename, a3: "wb", a4: pPathID);
  v6 = v5;
  if ( v5 != nullptr )
  {
    HIBYTE(pPathID) = 98;
    g_pFileSystem->Write(this: &g_pFileSystem->IBaseFileSystem, a2: (char *)&pPathID + 3, a3: 1, a4: v5);
    g_pFileSystem->Close(this: &g_pFileSystem->IBaseFileSystem, a2: v6);
  }
  g_pFileSystem->RelativePathToFullPath(
    this: g_pFileSystem,
    a2: filename,
    a3: v3,
    a4: this->m_szVoiceoverFile,
    a5: 260,
    a6: FILTER_NONE,
    a7: nullptr);
  g_pFileSystem->RemoveFile(this: g_pFileSystem, a2: filename, a3: v3);
  if ( this->IsVoiceRecording(this) )
    Voice_RecordStop();
  this->m_bSuppressDeInit = true;
  Voice_ForceInit();
  Voice_RecordStart(pUncompressedFile: this->m_szVoiceoverFile, pDecompressedFile: nullptr, pMicInputFile: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x102002F0
// Name: public: virtual void CEngineTool::StopRecordingVoiceToFile(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineTool::StopRecordingVoiceToFile(CEngineTool *this)
{
  Voice_RecordStop();
  this->m_bSuppressDeInit = false;
}

//------------------------------------------------------------------------------
// Address: 0x10200310
// Name: public: virtual float CEngineTool::GetMono16Samples(char const __near *,class CUtlVector<short,class CUtlMemory<short,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
float __thiscall CEngineTool::GetMono16Samples(
        CEngineTool *this,
        const char *pszName,
        CUtlVector<short,CUtlMemory<short,int> > *sampleList)
{
  return S_GetMono16Samples(pszName, sampleList);
}

//------------------------------------------------------------------------------
// Address: 0x10200330
// Name: public: virtual void CEngineTool::GetWorldToScreenMatrixForView(class CViewSetup const __near &,class VMatrix __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineTool::GetWorldToScreenMatrixForView(
        CEngineTool *this,
        const CViewSetup *view,
        VMatrix *pVMatrix)
{
  VMatrix worldToView; // [esp+0h] [ebp-80h] BYREF
  VMatrix viewToProjection; // [esp+40h] [ebp-40h] BYREF

  ComputeViewMatrices(
    pWorldToView: &worldToView,
    pViewToProjection: &viewToProjection,
    pWorldToProjection: pVMatrix,
    viewSetup: view);
}

//------------------------------------------------------------------------------
// Address: 0x10200360
// Name: public: virtual unsigned short CEngineTool::CreatePartitionHandle(class IHandleEntity __near *,int,class Vector const __near &,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall CEngineTool::CreatePartitionHandle(
        CEngineTool *this,
        IHandleEntity *pEntity,
        int listMask,
        const Vector *mins,
        const Vector *maxs)
{
  ISpatialPartitionInternal *v5; // eax

  v5 = SpatialPartition();
  return v5->CreateHandle(this: v5, a2: pEntity, a3: listMask, a4: mins, a5: maxs);
}

//------------------------------------------------------------------------------
// Address: 0x102003A0
// Name: public: virtual void CEngineTool::InstallPartitionQueryCallback(class IPartitionQueryCallback __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineTool::InstallPartitionQueryCallback(CEngineTool *this, IPartitionQueryCallback *pQuery)
{
  ISpatialPartitionInternal *v2; // eax

  v2 = SpatialPartition();
  v2->InstallQueryCallback(this: v2, a2: pQuery);
}

//------------------------------------------------------------------------------
// Address: 0x102003C0
// Name: public: virtual void CEngineTool::RemovePartitionQueryCallback(class IPartitionQueryCallback __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineTool::RemovePartitionQueryCallback(CEngineTool *this, IPartitionQueryCallback *pQuery)
{
  ISpatialPartitionInternal *v2; // eax

  v2 = SpatialPartition();
  v2->RemoveQueryCallback(this: v2, a2: pQuery);
}

//------------------------------------------------------------------------------
// Address: 0x102003E0
// Name: public: virtual void CEngineTool::ElementMoved(unsigned short,class Vector const __near &,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineTool::ElementMoved(CEngineTool *this, int handle, const Vector *mins, const Vector *maxs)
{
  ISpatialPartitionInternal *v4; // eax

  v4 = SpatialPartition();
  v4->ElementMoved(this: v4, a2: handle, a3: mins, a4: maxs);
}

//------------------------------------------------------------------------------
// Address: 0x10200400
// Name: public: virtual bool CEngineTool::IsVoiceRecording(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
bool __thiscall CEngineTool::IsVoiceRecording(CEngineTool *this)
{
  return Voice_IsRecording();
}

//------------------------------------------------------------------------------
// Address: 0x10200410
// Name: public: virtual void CEngineTool::OnModeChanged(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineTool::OnModeChanged(CEngineTool *this, BOOL bGameMode)
{
  IEngineVGuiInternal *v2; // eax

  v2 = EngineVGui();
  v2->OnToolModeChanged(this: v2, a2: bGameMode);
}

//------------------------------------------------------------------------------
// Address: 0x10200430
// Name: bool EngineTool_SuppressDeInit(void)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl EngineTool_SuppressDeInit()
{
  return g_EngineTool.m_bSuppressDeInit;
}

//------------------------------------------------------------------------------
// Address: 0x10200440
// Name: void EngineTool_OverrideSampleRate(int __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl EngineTool_OverrideSampleRate(int *rate)
{
  if ( g_EngineTool.m_bSuppressDeInit )
    *rate = 11025;
}

//------------------------------------------------------------------------------
// Address: 0x10200470
// Name: void EngineTool_UpdateScreenshot(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl EngineTool_UpdateScreenshot()
{
  if ( !g_LostVideoMemory && g_EngineTool.m_szScreenshotFile[0] != 0 )
  {
    g_ClientDLL->WriteSaveGameScreenshotOfSize(
      this: g_ClientDLL,
      a2: g_EngineTool.m_szScreenshotFile,
      a3: g_EngineTool.m_nScreenshotWidth,
      a4: g_EngineTool.m_nScreenshotHeight,
      a5: false,
      a6: false);
    g_EngineTool.m_szScreenshotFile[0] = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102004C0
// Name: public: virtual void CEngineTool::TraceRay(struct Ray_t const __near &,unsigned int,class ITraceFilter __near *,class CBaseTrace __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineTool::TraceRay(
        CEngineTool *this,
        const Ray_t *ray,
        unsigned int fMask,
        ITraceFilter *pTraceFilter,
        CBaseTrace *pTrace)
{
  CGameTrace tempTrace; // [esp+8h] [ebp-54h] BYREF

  g_pEngineTraceClient->TraceRay(this: g_pEngineTraceClient, a2: ray, a3: fMask, a4: pTraceFilter, a5: &tempTrace);
  *pTrace = tempTrace.CBaseTrace;
}

//------------------------------------------------------------------------------
// Address: 0x10200500
// Name: public: virtual void CEngineTool::TraceRayServer(struct Ray_t const __near &,unsigned int,class ITraceFilter __near *,class CBaseTrace __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineTool::TraceRayServer(
        CEngineTool *this,
        const Ray_t *ray,
        unsigned int fMask,
        ITraceFilter *pTraceFilter,
        CBaseTrace *pTrace)
{
  CGameTrace tempTrace; // [esp+8h] [ebp-54h] BYREF

  g_pEngineTraceServer->TraceRay(this: g_pEngineTraceServer, a2: ray, a3: fMask, a4: pTraceFilter, a5: &tempTrace);
  *pTrace = tempTrace.CBaseTrace;
}

//------------------------------------------------------------------------------
// Address: 0x10200540
// Name: bool EngineTool_CheckQuitHandlers(void)
// Source: json
//------------------------------------------------------------------------------
char __cdecl EngineTool_CheckQuitHandlers()
{
  int v0; // esi
  int m_Size; // edi
  CEngineTool::QuitHandler_t *m_pMemory; // ecx
  bool (__cdecl *func)(void *); // eax

  v0 = 0;
  m_Size = g_EngineTool.m_QuitHandlers.m_Size;
  if ( g_EngineTool.m_QuitHandlers.m_Size <= 0 )
    return 1;
  m_pMemory = g_EngineTool.m_QuitHandlers.m_Memory.m_pMemory;
  while ( 1 )
  {
    func = m_pMemory[v0].func;
    if ( func != nullptr )
      break;
LABEL_6:
    if ( ++v0 >= m_Size )
      return 1;
  }
  if ( func(a1: m_pMemory[v0].userdata) )
  {
    m_pMemory = g_EngineTool.m_QuitHandlers.m_Memory.m_pMemory;
    goto LABEL_6;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10200620
// Name: public: virtual void CEngineTool::InstallQuitHandler(void __near *,bool (*)(void __near *))
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineTool::InstallQuitHandler(CEngineTool *this, void *pvUserData, bool (__cdecl *func)(void *))
{
  CEngineTool::QuitHandler_t qh; // [esp+0h] [ebp-8h] BYREF

  qh.userdata = pvUserData;
  qh.func = func;
  CUtlVector<RegisteredDemoCustomDataCallbackPair_t,CUtlMemory<RegisteredDemoCustomDataCallbackPair_t,int>>::InsertBefore(
    this: (CUtlVector<vgui::PropertySheet::Page_t,CUtlMemory<vgui::PropertySheet::Page_t,int> > *)&this->m_QuitHandlers,
    elem: this->m_QuitHandlers.m_Size,
    src: (const vgui::PropertySheet::Page_t *)&qh);
}

//------------------------------------------------------------------------------
// Address: 0x10200650
// Name: void EngineTool_InstallQuitHandler(void __near *,bool (*)(void __near *))
// Source: json
//------------------------------------------------------------------------------
void __cdecl EngineTool_InstallQuitHandler(vgui::Panel *pvUserData, bool (__cdecl *func)(void *))
{
  vgui::PropertySheet::Page_t src; // [esp+0h] [ebp-8h] BYREF

  src.page = pvUserData;
  *(_DWORD *)&src.contextMenu = func;
  CUtlVector<RegisteredDemoCustomDataCallbackPair_t,CUtlMemory<RegisteredDemoCustomDataCallbackPair_t,int>>::InsertBefore(
    this: (CUtlVector<vgui::PropertySheet::Page_t,CUtlMemory<vgui::PropertySheet::Page_t,int> > *)&g_EngineTool.m_QuitHandlers,
    elem: g_EngineTool.m_QuitHandlers.m_Size,
    &src);
}

//------------------------------------------------------------------------------
// Address: 0x10200460
// Name: __CreateCEngineToolIEngineToolFramework_interface
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CEngineTool *__cdecl _CreateCEngineToolIEngineToolFramework_interface()
{
  return &g_EngineTool;
}

} // namespace engine_xlsp
