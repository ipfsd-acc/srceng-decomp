// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: engine/sys_engine.cpp
// Functions: 8
// ============================================================

#include "engine\sys_engine.h"

//------------------------------------------------------------------------------
// Address: 0x1000BBD0
// Name: public: virtual enum IEngine::EngineState_t CEngine::GetState(void)
// Source: json
//------------------------------------------------------------------------------
INetChannel *__thiscall CEngine::GetState(CNetMessage *this)
{
  return this->m_NetChannel;
}

//------------------------------------------------------------------------------
// Address: 0x10075DA0
// Name: public: virtual void CEngine::SetQuitting(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngine::SetQuitting(CBaseDemoAction *this, DEMOACTION actionType)
{
  this->m_Type = actionType;
}

//------------------------------------------------------------------------------
// Address: 0x101E9BD0
// Name: public: virtual void CEngine::Unload(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngine::Unload(CEngine *this)
{
  Sys_ShutdownGame();
  this->m_nDLLState = DLL_INACTIVE;
  this->m_nNextDLLState = DLL_INACTIVE;
}

//------------------------------------------------------------------------------
// Address: 0x101E9BF0
// Name: public: virtual bool CEngine::Load(bool,char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __userpurge CEngine::Load@<al>(CEngine *this@<ecx>, int a2@<edi>, bool dedicated, const char *rootdir)
{
  char v4; // bl
  HWND__ **v5; // eax

  this->m_nNextDLLState = DLL_ACTIVE;
  this->m_nDLLState = DLL_ACTIVE;
  v4 = 0;
  v5 = (HWND__ **)game->GetMainWindowAddress(this: game);
  if ( Sys_InitGame(
         a1: 0,
         a2,
         appSystemFactory: g_AppSystemFactory,
         pBaseDir: rootdir,
         pwnd: v5,
         bIsDedicated: dedicated) != 0 )
  {
    v4 = 1;
    UpdateMaterialSystemConfig();
  }
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x101E9C40
// Name: public: virtual void CEngine::SetNextState(enum IEngine::EngineState_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngine::SetNextState(bf_write *this, int bitPos)
{
  this->m_iCurBit = bitPos;
}

//------------------------------------------------------------------------------
// Address: 0x101E9C50
// Name: public: virtual float CEngine::GetCurTime(void)
// Source: json
//------------------------------------------------------------------------------
long double __thiscall CEngine::GetCurTime(CEngine *this)
{
  return this->m_flCurrentTime;
}

//------------------------------------------------------------------------------
// Address: 0x101E9C90
// Name: private: bool CEngine::FilterTime(float)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CEngine::FilterTime(CEngine *this, float dt)
{
  float m_fValue; // xmm0_4
  bool result; // al
  double value; // [esp+0h] [ebp-8h]
  float value_4; // [esp+4h] [ebp-4h]

  if ( !sv.m_bIsDedicated
    && (sv_cheats.m_pParent == nullptr || sv_cheats.m_pParent->m_Value.m_nValue == 0)
    && !Cmd_IsRptActive() )
  {
    m_fValue = fps_max.m_pParent->m_Value.m_fValue;
    if ( m_fValue < 30.0 && m_fValue != 0.0 )
    {
      _Warning(a1: "sv_cheats is 0 and fps_max is being limited to a minimum of 30 (or set to 0).\n");
      ConVar::SetValue(this: (ConVar *)&fps_max.IConVar, value: 30.0);
    }
  }
  value_4 = fps_max.m_pParent->m_Value.m_fValue;
  if ( value_4 <= 0.0 )
    return true;
  value = value_4 <= 1000.0 ? value_4 : 1000.0;
  result = demoplayer->IsPlayingTimeDemo(this: demoplayer);
  if ( result || g_bDedicatedServerBenchmarkMode || 1.0 / value <= dt )
    return true;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101E9D70
// Name: public: virtual void CEngine::Frame(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngine::Frame(CEngine *this)
{
  long double v2; // st7
  float v3; // xmm0_4
  ConVar *(__thiscall *FindVar_2)(ICvar *, const char *); // edx
  ConVar *v5; // eax
  ConVar *m_pParent; // ecx
  bool v7; // bl
  int m_nValue; // edi
  ConVar *v9; // ecx
  IEngine::EngineState_t m_nNextDLLState; // eax
  __int32 v11; // eax
  float v12; // [esp+Ch] [ebp-4h]

  if ( !game->IsActiveApp(this: game) && !sv.m_bIsDedicated )
    g_pInputSystem->SleepUntilInput(this: g_pInputSystem, a2: 50);
  v2 = _Plat_FloatTime();
  this->m_flCurrentTime = v2;
  v12 = v2 - this->m_flPreviousTime;
  v3 = v12 + this->m_flFrameTime;
  this->m_flPreviousTime = v2;
  this->m_flFrameTime = v3;
  if ( v3 >= 0.0 )
  {
    if ( CEngine::FilterTime(this, dt: v3) )
    {
      if ( async_serialize.m_pParent != nullptr && async_serialize.m_pParent->m_Value.m_nValue != 0 )
      {
        if ( (_S2_17 & 1) != 0 )
        {
          v5 = pSyncReportConVar;
        }
        else
        {
          FindVar_2 = g_pCVar->FindVar_2;
          _S2_17 |= 1u;
          v5 = FindVar_2(this: g_pCVar, a2: "fs_report_sync_opens");
          pSyncReportConVar = v5;
        }
        v7 = false;
        if ( v5 != nullptr )
        {
          m_pParent = v5->m_pParent;
          if ( m_pParent != nullptr && m_pParent->m_Value.m_nValue != 0 )
            v7 = true;
        }
        m_nValue = 0;
        if ( v7 )
        {
          v9 = v5->m_pParent;
          if ( v9 != nullptr )
            m_nValue = v9->m_Value.m_nValue;
          else
            m_nValue = 0;
          v5->SetValue_2(this: &v5->IConVar, a2: 0);
        }
        g_pFileSystem->AsyncFinishAll(this: g_pFileSystem, a2: 0);
        if ( v7 )
          pSyncReportConVar->SetValue_2(this: &pSyncReportConVar->IConVar, a2: m_nValue);
      }
      PreUpdateProfile(filteredtime: this->m_flFilteredTime);
      this->m_flFilteredTime = 0.0;
      if ( !sv.m_bIsDedicated )
        ClientDLL_FrameStageNotify(frameStage: FRAME_START);
      PostUpdateProfile();
      CVProfile::EnterScope(
        this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
        a2: "CEngine::Frame",
        a3: 0,
        a4: "Unaccounted",
        a5: false,
        a6: 4);
      if ( (unsigned int)(this->m_nDLLState - 1) <= 2 )
        HostState_Frame(time: this->m_flFrameTime);
      m_nNextDLLState = this->m_nNextDLLState;
      if ( m_nNextDLLState != this->m_nDLLState )
      {
        this->m_nDLLState = m_nNextDLLState;
        v11 = m_nNextDLLState - 2;
        if ( v11 != 0 )
        {
          if ( v11 == 1 )
            this->SetQuitting(this, a2: 2);
        }
        else
        {
          this->SetQuitting(this, a2: 1);
        }
      }
      CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
      this->m_flFrameTime = 0.0;
    }
    else
    {
      this->m_flFilteredTime = this->m_flFilteredTime + v12;
    }
  }
}

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x1003E300
// Name: public: virtual enum IEngine::EngineState_t CEngine::GetState(void)
// Source: json
//------------------------------------------------------------------------------
INetChannel *__thiscall CEngine::GetState(CNetMessage *this)
{
  return this->m_NetChannel;
}

//------------------------------------------------------------------------------
// Address: 0x10075A70
// Name: public: virtual void CEngine::SetQuitting(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngine::SetQuitting(CBaseDemoAction *this, DEMOACTION actionType)
{
  this->m_Type = actionType;
}

//------------------------------------------------------------------------------
// Address: 0x101E9EA0
// Name: public: virtual void CEngine::Unload(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngine::Unload(CEngine *this)
{
  Sys_ShutdownGame();
  this->m_nDLLState = DLL_INACTIVE;
  this->m_nNextDLLState = DLL_INACTIVE;
}

//------------------------------------------------------------------------------
// Address: 0x101E9EC0
// Name: public: virtual bool CEngine::Load(bool,char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CEngine::Load(CEngine *this, bool dedicated, const char *rootdir)
{
  char v3; // bl
  void **v4; // eax

  this->m_nNextDLLState = DLL_ACTIVE;
  this->m_nDLLState = DLL_ACTIVE;
  v3 = 0;
  v4 = game->GetMainWindowAddress(this: game);
  if ( Sys_InitGame(appSystemFactory: g_AppSystemFactory, pBaseDir: rootdir, pwnd: v4, bIsDedicated: dedicated) != 0 )
  {
    v3 = 1;
    UpdateMaterialSystemConfig();
  }
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x101E9F10
// Name: public: virtual float CEngine::GetCurTime(void)
// Source: json
//------------------------------------------------------------------------------
long double __thiscall CEngine::GetCurTime(CEngine *this)
{
  return this->m_flCurrentTime;
}

//------------------------------------------------------------------------------
// Address: 0x101E9F70
// Name: private: bool CEngine::FilterTime(float)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CEngine::FilterTime(CEngine *this, float dt)
{
  float m_fValue; // xmm0_4
  bool result; // al
  double v4; // [esp+4h] [ebp-8h]
  float fps; // [esp+8h] [ebp-4h]

  if ( !sv.m_bIsDedicated
    && (sv_cheats.m_pParent == nullptr || sv_cheats.m_pParent->m_Value.m_nValue == 0)
    && !Cmd_IsRptActive() )
  {
    m_fValue = fps_max.m_pParent->m_Value.m_fValue;
    if ( m_fValue < 30.0 && m_fValue != 0.0 )
    {
      _Warning(a1: "sv_cheats is 0 and fps_max is being limited to a minimum of 30 (or set to 0).\n");
      ConVar::SetValue(this: (ConVar *)&fps_max.IConVar, value: 30.0);
    }
  }
  fps = fps_max.m_pParent->m_Value.m_fValue;
  if ( fps <= 0.0 )
    return true;
  v4 = fps <= 1000.0 ? fps : 1000.0;
  result = demoplayer->IsPlayingTimeDemo(this: demoplayer);
  if ( result || g_bDedicatedServerBenchmarkMode || 1.0 / v4 <= dt )
    return true;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101EA050
// Name: public: virtual void CEngine::Frame(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngine::Frame(CEngine *this)
{
  int v2; // ecx
  long double v3; // st7
  float v4; // xmm0_4
  ConVar *(__thiscall *FindVar_2)(ICvar *, const char *); // edx
  ConVar *v6; // eax
  ConVar *m_pParent; // ecx
  bool v8; // bl
  int m_nValue; // edi
  ConVar *v10; // ecx
  IEngine::EngineState_t m_nNextDLLState; // eax
  __int32 v12; // eax
  float dt; // [esp+30h] [ebp-4h]

  if ( !game->IsActiveApp(this: game) && !sv.m_bIsDedicated )
    g_pInputSystem->SleepUntilInput(this: g_pInputSystem, a2: 50);
  v3 = _Plat_FloatTime(a1: v2);
  this->m_flCurrentTime = v3;
  dt = v3 - this->m_flPreviousTime;
  v4 = dt + this->m_flFrameTime;
  this->m_flPreviousTime = v3;
  this->m_flFrameTime = v4;
  if ( v4 >= 0.0 )
  {
    if ( CEngine::FilterTime(this, dt: v4) )
    {
      if ( async_serialize.m_pParent != nullptr && async_serialize.m_pParent->m_Value.m_nValue != 0 )
      {
        if ( (_S2_17 & 1) != 0 )
        {
          v6 = pSyncReportConVar;
        }
        else
        {
          FindVar_2 = g_pCVar->FindVar_2;
          _S2_17 |= 1u;
          v6 = FindVar_2(this: g_pCVar, a2: "fs_report_sync_opens");
          pSyncReportConVar = v6;
        }
        v8 = false;
        if ( v6 != nullptr )
        {
          m_pParent = v6->m_pParent;
          if ( m_pParent != nullptr && m_pParent->m_Value.m_nValue != 0 )
            v8 = true;
        }
        m_nValue = 0;
        if ( v8 )
        {
          v10 = v6->m_pParent;
          if ( v10 != nullptr )
            m_nValue = v10->m_Value.m_nValue;
          else
            m_nValue = 0;
          v6->SetValue_2(this: &v6->IConVar, a2: 0);
        }
        g_pFileSystem->AsyncFinishAll(this: g_pFileSystem, a2: 0);
        if ( v8 )
          pSyncReportConVar->SetValue_2(this: &pSyncReportConVar->IConVar, a2: m_nValue);
      }
      PreUpdateProfile(filteredtime: this->m_flFilteredTime);
      this->m_flFilteredTime = 0.0;
      if ( !sv.m_bIsDedicated )
        ClientDLL_FrameStageNotify(frameStage: FRAME_START);
      PostUpdateProfile();
      CVProfile::EnterScope(
        this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
        a2: "CEngine::Frame",
        a3: 0,
        a4: "Unaccounted",
        a5: false,
        a6: 4);
      if ( (unsigned int)(this->m_nDLLState - 1) <= 2 )
        HostState_Frame(time: this->m_flFrameTime);
      m_nNextDLLState = this->m_nNextDLLState;
      if ( m_nNextDLLState != this->m_nDLLState )
      {
        this->m_nDLLState = m_nNextDLLState;
        v12 = m_nNextDLLState - 2;
        if ( v12 != 0 )
        {
          if ( v12 == 1 )
            this->SetQuitting(this, a2: 2);
        }
        else
        {
          this->SetQuitting(this, a2: 1);
        }
      }
      CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
      this->m_flFrameTime = 0.0;
    }
    else
    {
      this->m_flFilteredTime = this->m_flFilteredTime + dt;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10272420
// Name: public: virtual void CEngine::SetNextState(enum IEngine::EngineState_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngine::SetNextState(bf_write *this, int bitPos)
{
  this->m_iCurBit = bitPos;
}

} // namespace engine_xlsp
