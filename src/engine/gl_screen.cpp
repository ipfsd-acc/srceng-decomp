// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: engine/gl_screen.cpp
// Functions: 6
// ============================================================

#include "engine\gl_screen.h"

//------------------------------------------------------------------------------
// Address: 0x100D9350
// Name: void SCR_Init(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SCR_Init()
{
  scr_initialized = true;
}

//------------------------------------------------------------------------------
// Address: 0x100D9360
// Name: void SCR_Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SCR_Shutdown()
{
  scr_initialized = false;
}

//------------------------------------------------------------------------------
// Address: 0x100D9370
// Name: void SCR_EndLoadingPlaque(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SCR_EndLoadingPlaque()
{
  IEngineVGuiInternal *v0; // eax
  IEngineVGuiInternal *v1; // eax
  KeyValues *v2; // eax
  KeyValues *v3; // esi
  KeyValues *Copy; // edi
  IEngineVGuiInternal *v5; // eax
  KeyValues *v6; // eax
  IMatchEventsSubscription *v7; // eax

  if ( scr_drawloading )
  {
    scr_engineevent_loadingstarted = false;
    v0 = EngineVGui();
    v0->HideLoadingPlaque(this: v0);
    if ( g_pMatchFramework == nullptr )
      return;
    scr_engineevent_loadingstarted = false;
    v1 = EngineVGui();
    v1->HideLoadingPlaque(this: v1);
    v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v2 != nullptr )
      v3 = KeyValues::KeyValues(this: v2, setName: "OnEngineLevelLoadingFinished");
    else
      v3 = nullptr;
    if ( gfExtendedError )
    {
      KeyValues::SetInt(this: v3, keyName: "error", value: gfExtendedError);
      KeyValues::SetString(this: v3, keyName: "reason", value: gszDisconnectReason);
    }
    if ( toolframework->InToolMode(this: toolframework) )
    {
      Copy = KeyValues::MakeCopy(this: v3);
      toolframework->PostMessageA(this: toolframework, a2: Copy);
      KeyValues::deleteThis(this: Copy);
    }
    goto LABEL_16;
  }
  if ( gfExtendedError )
  {
    v5 = EngineVGui();
    v5->ShowErrorMessage(this: v5);
  }
  if ( scr_engineevent_loadingstarted )
  {
    v6 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v6 != nullptr )
      v3 = KeyValues::KeyValues(this: v6, setName: "OnEngineLevelLoadingTick");
    else
      v3 = nullptr;
LABEL_16:
    v7 = g_pMatchFramework->GetEventsSubscription(this: g_pMatchFramework);
    v7->BroadcastEvent(this: v7, a2: v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100D94B0
// Name: public: void CMatRenderContextPtr::GetFrom(class IMaterialSystem __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatRenderContextPtr::GetFrom(CMatRenderContextPtr *this, IMaterialSystem *pFrom)
{
  IMatRenderContext *v3; // edi

  v3 = pFrom->GetRenderContext(this: pFrom);
  if ( this->m_pObject != nullptr )
  {
    this->m_pObject->EndRender(this: this->m_pObject);
    if ( this->m_pObject != nullptr )
      this->m_pObject->Release(this: this->m_pObject);
  }
  this->m_pObject = nullptr;
  if ( v3 != nullptr )
    v3->AddRef(this: v3);
  this->m_pObject = v3;
  v3->BeginRender(this: v3);
}

//------------------------------------------------------------------------------
// Address: 0x100D9570
// Name: void SCR_UpdateScreen(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SCR_UpdateScreen()
{
  IEngineVGuiInternal *v0; // eax
  bool v1; // al
  IMatRenderContext *m_pObject; // esi
  ICallQueue *v3; // eax
  IEngineVGuiInternal *v4; // eax
  IMatRenderContext *v5; // eax
  int v6; // esi
  CClientState *BaseLocalClient; // eax
  vgui::PropertyPage *v8; // ecx
  IMatRenderContext *v9; // esi
  ICallQueue *v10; // eax
  int v11; // eax
  CClientState *v12; // eax
  int v13; // eax
  int v14; // ebx
  int v15; // edi
  int v16; // eax
  int v17; // ebx
  int v18; // eax
  const char *v19; // eax
  vgui::CTreeViewListControl *v20; // ecx
  int v21; // eax
  int v22; // eax
  int v23; // eax
  int v24; // eax
  ECommandTarget_t TraceType; // eax
  const char *v26; // [esp-8h] [ebp-18h]
  IMDLCache *v27; // [esp-4h] [ebp-14h]
  IMDLCache *v28; // [esp-4h] [ebp-14h]
  CMatRenderContextPtr v29; // [esp+Ch] [ebp-4h] BYREF

  R_StudioCheckReinitLightingCache();
  V_CheckGamma();
  if ( scr_nextdrawtick != 0 )
  {
    if ( host_tickcount < scr_nextdrawtick )
      return;
    scr_nextdrawtick = 0;
  }
  if ( scr_disabled_for_loading )
  {
    if ( !Host_IsSinglePlayerGame() )
      V_RenderVGuiOnly();
    return;
  }
  if ( scr_initialized && con_initialized )
  {
    if ( demoplayer->IsPlayingBack(this: demoplayer) )
      demoplayer->InterpolateViewpoint(this: demoplayer);
    ((void (__stdcall *)(_DWORD))materials->BeginFrame)(a1: LODWORD(host_frametime));
    v29.m_pObject = nullptr;
    CMatRenderContextPtr::GetFrom(this: &v29, pFrom: materials);
    v0 = EngineVGui();
    v1 = v0->IsGameUIVisible(this: v0);
    m_pObject = v29.m_pObject;
    if ( v1 || Steam3Client()->m_bGameOverlayActive )
      m_pObject->AntiAliasingHint(this: m_pObject, a2: 8);
    if ( m_pObject->GetCallQueue(this: m_pObject) != nullptr )
    {
      v27 = g_pMDLCache;
      v3 = m_pObject->GetCallQueue(this: m_pObject);
      ICallQueue::QueueCall<IMDLCache *,IMDLCache,void>(
        this: v3,
        pObject: v27,
        pfnProxied:  __thiscall IMDLCache::`vcall'{200,{flat}});
    }
    m_pObject->EndRender(this: m_pObject);
    m_pObject->Release(this: m_pObject);
    v29.m_pObject = nullptr;
    v4 = EngineVGui();
    v4->Simulate(this: v4);
    v5 = materials->GetRenderContext(this: materials);
    v6 = (int)v5;
    if ( v5 != nullptr )
      v5->BeginRender(this: v5);
    ClientDLL_FrameStageNotify(frameStage: FRAME_RENDER_START);
    if ( v6 != 0 )
    {
      (*(void (__thiscall **)(int))(*(_DWORD *)v6 + 12))(a1: v6);
      (*(void (__thiscall **)(int))(*(_DWORD *)v6 + 4))(a1: v6);
    }
    Host_BeginThreadedSound();
    g_EngineRenderer->FrameBegin(this: g_EngineRenderer);
    toolframework->RenderFrameBegin(this: toolframework);
    BaseLocalClient = GetBaseLocalClient();
    CClientState::UpdateAreaBits_BackwardsCompatible(this: BaseLocalClient);
    CColorBalanceUIPanel::Init(this: v8);
    V_RenderView();
    CL_TakeSnapshotAndSwap(a1: 0, a2: v6);
    ClientDLL_FrameStageNotify(frameStage: FRAME_RENDER_END);
    toolframework->RenderFrameEnd(this: toolframework);
    g_EngineRenderer->FrameEnd(this: g_EngineRenderer);
    CMatRenderContextPtr::GetFrom(this: &v29, pFrom: materials);
    v9 = v29.m_pObject;
    if ( v29.m_pObject->GetCallQueue(this: v29.m_pObject) != nullptr )
    {
      v28 = g_pMDLCache;
      v10 = v9->GetCallQueue(this: v9);
      ICallQueue::QueueCall<IMDLCache *,IMDLCache,void>(
        this: v10,
        pObject: v28,
        pfnProxied:  __thiscall IMDLCache::`vcall'{204,{flat}});
    }
    v9->EndRender(this: v9);
    v9->Release(this: v9);
    materials->EndFrame(this: materials);
    v11 = g_cv_miniprofiler_dump.m_pParent != nullptr ? g_cv_miniprofiler_dump.m_pParent->m_Value.m_nValue : 0;
    _PublishAllMiniProfilers(a1: v11);
    v12 = GetBaseLocalClient();
    if ( !s_bTestedBuildCubemaps && v12->m_nSignonState == 6 )
    {
      s_bTestedBuildCubemaps = true;
      v13 = _CommandLine();
      v14 = (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v13 + 40))(a1: v13, a2: "-buildcubemaps");
      if ( v14 != 0 )
      {
        v15 = 1;
        v16 = _CommandLine();
        v17 = v14 + 1;
        if ( (*(int (__thiscall **)(int))(*(_DWORD *)v16 + 36))(a1: v16) > v17 )
        {
          v18 = _CommandLine();
          v19 = (const char *)(*(int (__thiscall **)(int, int))(*(_DWORD *)v18 + 44))(a1: v18, a2: v17);
          v15 = atoi(nptr: v19);
          if ( v15 == 0 )
            v15 = 1;
        }
        R_BuildCubemapSamples(a1: v17, a2: (char *)v15, numIterations: v15);
LABEL_39:
        v26 = "quit\n";
        goto LABEL_40;
      }
      v21 = _CommandLine();
      if ( (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v21 + 40))(a1: v21, a2: "-buildmodelforworld") != 0 )
      {
        v26 = "buildmodelforworld;quit\n";
      }
      else
      {
        v22 = _CommandLine();
        if ( (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v22 + 40))(a1: v22, a2: "-navanalyze") != 0 )
        {
          v26 = "nav_edit 1;nav_analyze_scripted\n";
        }
        else
        {
          v23 = _CommandLine();
          if ( (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v23 + 40))(a1: v23, a2: "-navforceanalyze") == 0 )
          {
            v24 = _CommandLine();
            if ( (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v24 + 40))(a1: v24, a2: "-exit") == 0 )
              return;
            goto LABEL_39;
          }
          v26 = "nav_edit 1;nav_analyze_scripted force\n";
        }
      }
LABEL_40:
      TraceType = CTraceFilter::GetTraceType(this: v20);
      Cbuf_AddText(eTarget: TraceType, pText: v26, nTickDelay: 0);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100D98D0
// Name: void SCR_BeginLoadingPlaque(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __usercall SCR_BeginLoadingPlaque(CStatTime *a1@<ecx>, int a2@<edi>, const char *levelName)
{
  IEngineVGuiInternal *v3; // eax
  IEngineVGuiInternal *v4; // edi
  IEngineVGuiInternal_vtbl *v5; // esi
  bool IsTransitioningToLoad; // al
  KeyValues *v7; // eax
  KeyValues *v8; // esi
  IMatchEventsSubscription *v9; // eax
  CClientState *BaseLocalClient; // eax

  if ( !scr_drawloading )
  {
    scr_loadingStartTime = _Plat_FloatTime(this: a1);
    v3 = EngineVGui();
    v3->SetNotAllowedToShowGameUI(this: v3, a2: false);
    Host_AllowQueuedMaterialSystem(bAllow: false);
    scr_drawloading = true;
    S_StopAllSounds(bClear: true);
    S_PreventSound(bSetting: true);
    S_OnLoadScreen(value: true);
    g_pFileSystem->AsyncFinishAll(this: g_pFileSystem, a2: 0);
    g_pMDLCache->FinishPendingLoads(this: g_pMDLCache);
    Con_ClearNotify();
    if ( g_ClientDLL != nullptr )
    {
      g_ClientDLL->CenterStringOff(this: g_ClientDLL);
      g_ClientDLL->HudText(this: g_ClientDLL, a2: nullptr);
    }
    v4 = EngineVGui();
    v5 = v4->__vftable;
    IsTransitioningToLoad = HostState_IsTransitioningToLoad();
    ((void (__thiscall *)(IEngineVGuiInternal *, const char *, bool, int))v5->OnLevelLoadingStarted)(
      a1: v4,
      a2: levelName,
      a3: IsTransitioningToLoad,
      a4: a2);
    scr_engineevent_loadingstarted = true;
    v7 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v7 != nullptr )
      v8 = KeyValues::KeyValues(
             this: v7,
             setName: "OnEngineLevelLoadingStarted",
             firstKey: "name",
             firstValue: levelName);
    else
      v8 = nullptr;
    v9 = g_pMatchFramework->GetEventsSubscription(this: g_pMatchFramework);
    v9->BroadcastEvent(this: v9, a2: v8);
    g_ClientGlobalVariables.frametime = 0.0;
    g_ClientGlobalVariables.framecount = ++host_framecount;
    SCR_UpdateScreen();
    g_ClientGlobalVariables.framecount = ++host_framecount;
    SCR_UpdateScreen();
    BaseLocalClient = GetBaseLocalClient();
    g_ClientGlobalVariables.frametime = CClientState::GetFrameTime(this: BaseLocalClient);
    scr_disabled_for_loading = true;
  }
}

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x100D8F30
// Name: void SCR_Init(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SCR_Init()
{
  scr_initialized = true;
}

//------------------------------------------------------------------------------
// Address: 0x100D8F40
// Name: void SCR_Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SCR_Shutdown()
{
  scr_initialized = false;
}

//------------------------------------------------------------------------------
// Address: 0x100D8F60
// Name: void SCR_EndLoadingPlaque(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SCR_EndLoadingPlaque()
{
  IEngineVGuiInternal *v0; // eax
  IEngineVGuiInternal *v1; // eax
  KeyValues *v2; // eax
  KeyValues *v3; // esi
  KeyValues *Copy; // edi
  IEngineVGuiInternal *v5; // eax
  KeyValues *v6; // eax
  IMatchEventsSubscription *v7; // eax

  if ( scr_drawloading )
  {
    scr_engineevent_loadingstarted = false;
    v0 = EngineVGui();
    v0->HideLoadingPlaque(this: v0);
    if ( g_pMatchFramework == nullptr )
      return;
    scr_engineevent_loadingstarted = false;
    v1 = EngineVGui();
    v1->HideLoadingPlaque(this: v1);
    v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v2 != nullptr )
      v3 = KeyValues::KeyValues(this: v2, setName: "OnEngineLevelLoadingFinished");
    else
      v3 = nullptr;
    if ( gfExtendedError )
    {
      KeyValues::SetInt(this: v3, keyName: "error", value: gfExtendedError);
      KeyValues::SetString(this: v3, keyName: "reason", value: gszDisconnectReason);
    }
    if ( toolframework->InToolMode(this: toolframework) )
    {
      Copy = KeyValues::MakeCopy(this: v3);
      toolframework->PostMessageA(this: toolframework, a2: Copy);
      KeyValues::deleteThis(this: Copy);
    }
    goto LABEL_16;
  }
  if ( gfExtendedError )
  {
    v5 = EngineVGui();
    v5->ShowErrorMessage(this: v5);
  }
  if ( scr_engineevent_loadingstarted )
  {
    v6 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v6 != nullptr )
      v3 = KeyValues::KeyValues(this: v6, setName: "OnEngineLevelLoadingTick");
    else
      v3 = nullptr;
LABEL_16:
    v7 = g_pMatchFramework->GetEventsSubscription(this: g_pMatchFramework);
    v7->BroadcastEvent(this: v7, a2: v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100D90A0
// Name: public: void CMatRenderContextPtr::GetFrom(class IMaterialSystem __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatRenderContextPtr::GetFrom(CMatRenderContextPtr *this, IMaterialSystem *pFrom)
{
  IMatRenderContext *v3; // edi

  v3 = pFrom->GetRenderContext(this: pFrom);
  if ( this->m_pObject != nullptr )
  {
    this->m_pObject->EndRender(this: this->m_pObject);
    if ( this->m_pObject != nullptr )
      this->m_pObject->Release(this: this->m_pObject);
  }
  this->m_pObject = nullptr;
  if ( v3 != nullptr )
    v3->AddRef(this: v3);
  this->m_pObject = v3;
  v3->BeginRender(this: v3);
}

//------------------------------------------------------------------------------
// Address: 0x100D9160
// Name: void SCR_UpdateScreen(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SCR_UpdateScreen()
{
  IEngineVGuiInternal *v0; // eax
  bool v1; // al
  IMatRenderContext *m_pObject; // esi
  ICallQueue *v3; // eax
  IEngineVGuiInternal *v4; // eax
  IMatRenderContext *v5; // eax
  int v6; // esi
  CClientState *BaseLocalClient; // eax
  vgui::PropertyPage *v8; // ecx
  IMatRenderContext *v9; // esi
  ICallQueue *v10; // eax
  int v11; // eax
  CClientState *v12; // eax
  int v13; // eax
  int v14; // ebx
  int v15; // edi
  int v16; // eax
  int v17; // ebx
  int v18; // eax
  const char *v19; // eax
  vgui::CTreeViewListControl *v20; // ecx
  int v21; // eax
  int v22; // eax
  int v23; // eax
  int v24; // eax
  ECommandTarget_t TraceType; // eax
  const char *v26; // [esp-8h] [ebp-18h]
  IMDLCache *v27; // [esp-4h] [ebp-14h]
  IMDLCache *v28; // [esp-4h] [ebp-14h]
  CMatRenderContextPtr pRenderContext; // [esp+Ch] [ebp-4h] BYREF

  R_StudioCheckReinitLightingCache();
  V_CheckGamma();
  if ( scr_nextdrawtick != 0 )
  {
    if ( host_tickcount < scr_nextdrawtick )
      return;
    scr_nextdrawtick = 0;
  }
  if ( scr_disabled_for_loading )
  {
    if ( !Host_IsSinglePlayerGame() )
      V_RenderVGuiOnly();
    return;
  }
  if ( scr_initialized && con_initialized )
  {
    if ( demoplayer->IsPlayingBack(this: demoplayer) )
      demoplayer->InterpolateViewpoint(this: demoplayer);
    ((void (__stdcall *)(_DWORD))materials->BeginFrame)(a1: LODWORD(host_frametime));
    pRenderContext.m_pObject = nullptr;
    CMatRenderContextPtr::GetFrom(this: &pRenderContext, pFrom: materials);
    v0 = EngineVGui();
    v1 = v0->IsGameUIVisible(this: v0);
    m_pObject = pRenderContext.m_pObject;
    if ( v1 || Steam3Client()->m_bGameOverlayActive )
      m_pObject->AntiAliasingHint(this: m_pObject, a2: 8);
    if ( m_pObject->GetCallQueue(this: m_pObject) != nullptr )
    {
      v27 = g_pMDLCache;
      v3 = m_pObject->GetCallQueue(this: m_pObject);
      ICallQueue::QueueCall<IMDLCache *,IMDLCache,void>(
        this: v3,
        pObject: v27,
        pfnProxied:  __thiscall IMDLCache::`vcall'{200,{flat}});
    }
    m_pObject->EndRender(this: m_pObject);
    m_pObject->Release(this: m_pObject);
    pRenderContext.m_pObject = nullptr;
    v4 = EngineVGui();
    v4->Simulate(this: v4);
    v5 = materials->GetRenderContext(this: materials);
    v6 = (int)v5;
    if ( v5 != nullptr )
      v5->BeginRender(this: v5);
    ClientDLL_FrameStageNotify(frameStage: FRAME_RENDER_START);
    if ( v6 != 0 )
    {
      (*(void (__thiscall **)(int))(*(_DWORD *)v6 + 12))(a1: v6);
      (*(void (__thiscall **)(int))(*(_DWORD *)v6 + 4))(a1: v6);
    }
    Host_BeginThreadedSound();
    g_EngineRenderer->FrameBegin(this: g_EngineRenderer);
    toolframework->RenderFrameBegin(this: toolframework);
    BaseLocalClient = GetBaseLocalClient();
    CClientState::UpdateAreaBits_BackwardsCompatible(this: BaseLocalClient);
    CColorBalanceUIPanel::Init(this: v8);
    V_RenderView();
    CL_TakeSnapshotAndSwap(a1: 0, a2: v6);
    ClientDLL_FrameStageNotify(frameStage: FRAME_RENDER_END);
    toolframework->RenderFrameEnd(this: toolframework);
    g_EngineRenderer->FrameEnd(this: g_EngineRenderer);
    CMatRenderContextPtr::GetFrom(this: &pRenderContext, pFrom: materials);
    v9 = pRenderContext.m_pObject;
    if ( pRenderContext.m_pObject->GetCallQueue(this: pRenderContext.m_pObject) != nullptr )
    {
      v28 = g_pMDLCache;
      v10 = v9->GetCallQueue(this: v9);
      ICallQueue::QueueCall<IMDLCache *,IMDLCache,void>(
        this: v10,
        pObject: v28,
        pfnProxied:  __thiscall IMDLCache::`vcall'{204,{flat}});
    }
    v9->EndRender(this: v9);
    v9->Release(this: v9);
    materials->EndFrame(this: materials);
    v11 = g_cv_miniprofiler_dump.m_pParent != nullptr ? g_cv_miniprofiler_dump.m_pParent->m_Value.m_nValue : 0;
    _PublishAllMiniProfilers(a1: v11);
    v12 = GetBaseLocalClient();
    if ( !s_bTestedBuildCubemaps && v12->m_nSignonState == 6 )
    {
      s_bTestedBuildCubemaps = true;
      v13 = _CommandLine();
      v14 = (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v13 + 40))(a1: v13, a2: "-buildcubemaps");
      if ( v14 != 0 )
      {
        v15 = 1;
        v16 = _CommandLine();
        v17 = v14 + 1;
        if ( (*(int (__thiscall **)(int))(*(_DWORD *)v16 + 36))(a1: v16) > v17 )
        {
          v18 = _CommandLine();
          v19 = (const char *)(*(int (__thiscall **)(int, int))(*(_DWORD *)v18 + 44))(a1: v18, a2: v17);
          v15 = atoi(nptr: v19);
          if ( v15 == 0 )
            v15 = 1;
        }
        R_BuildCubemapSamples(a1: v17, numIterations: v15);
LABEL_39:
        v26 = "quit\n";
        goto LABEL_40;
      }
      v21 = _CommandLine();
      if ( (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v21 + 40))(a1: v21, a2: "-buildmodelforworld") != 0 )
      {
        v26 = "buildmodelforworld;quit\n";
      }
      else
      {
        v22 = _CommandLine();
        if ( (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v22 + 40))(a1: v22, a2: "-navanalyze") != 0 )
        {
          v26 = "nav_edit 1;nav_analyze_scripted\n";
        }
        else
        {
          v23 = _CommandLine();
          if ( (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v23 + 40))(a1: v23, a2: "-navforceanalyze") == 0 )
          {
            v24 = _CommandLine();
            if ( (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v24 + 40))(a1: v24, a2: "-exit") == 0 )
              return;
            goto LABEL_39;
          }
          v26 = "nav_edit 1;nav_analyze_scripted force\n";
        }
      }
LABEL_40:
      TraceType = CTraceFilter::GetTraceType(this: v20);
      Cbuf_AddText(eTarget: TraceType, pText: v26, nTickDelay: 0);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100D94C0
// Name: void SCR_BeginLoadingPlaque(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __usercall SCR_BeginLoadingPlaque(int a1@<ecx>, int a2@<edi>, const char *levelName)
{
  IEngineVGuiInternal *v3; // eax
  IEngineVGuiInternal *v4; // edi
  IEngineVGuiInternal_vtbl *v5; // esi
  bool IsTransitioningToLoad; // al
  KeyValues *v7; // eax
  KeyValues *v8; // esi
  IMatchEventsSubscription *v9; // eax
  CClientState *BaseLocalClient; // eax

  if ( !scr_drawloading )
  {
    scr_loadingStartTime = _Plat_FloatTime(a1);
    v3 = EngineVGui();
    v3->SetNotAllowedToShowGameUI(this: v3, a2: false);
    Host_AllowQueuedMaterialSystem(bAllow: false);
    scr_drawloading = true;
    S_StopAllSounds(bClear: true);
    S_PreventSound(bSetting: true);
    S_OnLoadScreen(value: true);
    g_pFileSystem->AsyncFinishAll(this: g_pFileSystem, a2: 0);
    g_pMDLCache->FinishPendingLoads(this: g_pMDLCache);
    Con_ClearNotify();
    if ( g_ClientDLL != nullptr )
    {
      g_ClientDLL->CenterStringOff(this: g_ClientDLL);
      g_ClientDLL->HudText(this: g_ClientDLL, a2: nullptr);
    }
    v4 = EngineVGui();
    v5 = v4->__vftable;
    IsTransitioningToLoad = HostState_IsTransitioningToLoad();
    ((void (__thiscall *)(IEngineVGuiInternal *, const char *, bool, int))v5->OnLevelLoadingStarted)(
      a1: v4,
      a2: levelName,
      a3: IsTransitioningToLoad,
      a4: a2);
    scr_engineevent_loadingstarted = true;
    v7 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v7 != nullptr )
      v8 = KeyValues::KeyValues(
             this: v7,
             setName: "OnEngineLevelLoadingStarted",
             firstKey: "name",
             firstValue: levelName);
    else
      v8 = nullptr;
    v9 = g_pMatchFramework->GetEventsSubscription(this: g_pMatchFramework);
    v9->BroadcastEvent(this: v9, a2: v8);
    g_ClientGlobalVariables.frametime = 0.0;
    g_ClientGlobalVariables.framecount = ++host_framecount;
    SCR_UpdateScreen();
    g_ClientGlobalVariables.framecount = ++host_framecount;
    SCR_UpdateScreen();
    BaseLocalClient = GetBaseLocalClient();
    g_ClientGlobalVariables.frametime = CClientState::GetFrameTime(this: BaseLocalClient);
    scr_disabled_for_loading = true;
  }
}

} // namespace engine_xlsp
