// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: engine/enginestats.cpp
// Functions: 8
// ============================================================

#include "engine\enginestats.h"

//------------------------------------------------------------------------------
// Address: 0x10174A30
// Name: public: CEngineStats::CEngineStats(void)
// Source: json
//------------------------------------------------------------------------------
CEngineStats *__thiscall CEngineStats::CEngineStats(CEngineStats *this)
{
  this->m_InFrame = false;
  this->m_bInRun = false;
  this->m_szVProfStatsFileName[0] = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10174A40
// Name: public: void CEngineStats::BeginRun(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineStats::BeginRun(CEngineStats *this)
{
  bool v2; // zf

  v2 = this->m_szVProfStatsFileName[0] == 0;
  this->m_bInRun = true;
  this->m_totalNumFrames = 0;
  if ( !v2 )
    VProf_StartRecording(pFilename: this->m_szVProfStatsFileName);
  this->m_runStartTime = _Plat_FloatTime();
}

//------------------------------------------------------------------------------
// Address: 0x10174A70
// Name: public: void CEngineStats::EndRun(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineStats::EndRun(CEngineStats *this)
{
  bool v2; // zf

  this->m_runEndTime = _Plat_FloatTime();
  v2 = this->m_szVProfStatsFileName[0] == 0;
  this->m_bInRun = false;
  if ( !v2 )
  {
    VProfRecord_Shutdown();
    this->m_szVProfStatsFileName[0] = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10174AA0
// Name: public: void CEngineStats::BeginFrame(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineStats::BeginFrame(CEngineStats *this)
{
  *(_WORD *)&this->m_InFrame = 0;
}

//------------------------------------------------------------------------------
// Address: 0x10174AB0
// Name: public: void CEngineStats::EnableVProfStatsRecording(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineStats::EnableVProfStatsRecording(CEngineStats *this, const char *pFileName)
{
  V_strncpy(pDest: this->m_szVProfStatsFileName, pSrc: pFileName, maxLen: 260);
}

//------------------------------------------------------------------------------
// Address: 0x10174AD0
// Name: public: virtual float CStatTime::GetTime(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
double __thiscall CStatTime::GetTime(CStatTime *this)
{
  return _Plat_FloatTime(this);
}

//------------------------------------------------------------------------------
// Address: 0x10174AE0
// Name: __CreateCEngineTraceServerIEngineTrace_interface
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CEngineTraceServer *__cdecl _CreateCEngineTraceServerIEngineTrace_interface()
{
  return &s_EngineTraceServer;
}

//------------------------------------------------------------------------------
// Address: 0x10174AF0
// Name: __CreateCEngineTraceClientIEngineTrace_interface
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CEngineTraceClient *__cdecl _CreateCEngineTraceClientIEngineTrace_interface()
{
  return &s_EngineTraceClient;
}

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x10174D90
// Name: public: CEngineStats::CEngineStats(void)
// Source: json
//------------------------------------------------------------------------------
CEngineStats *__thiscall CEngineStats::CEngineStats(CEngineStats *this)
{
  this->m_InFrame = false;
  this->m_bInRun = false;
  this->m_szVProfStatsFileName[0] = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10174DA0
// Name: public: void CEngineStats::BeginRun(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineStats::BeginRun(CEngineStats *this)
{
  bool v2; // zf

  v2 = this->m_szVProfStatsFileName[0] == 0;
  this->m_bInRun = true;
  this->m_totalNumFrames = 0;
  if ( !v2 )
    VProf_StartRecording(pFilename: this->m_szVProfStatsFileName);
  this->m_runStartTime = _Plat_FloatTime();
}

//------------------------------------------------------------------------------
// Address: 0x10174DD0
// Name: public: void CEngineStats::EndRun(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineStats::EndRun(CEngineStats *this)
{
  bool v2; // zf

  this->m_runEndTime = _Plat_FloatTime();
  v2 = this->m_szVProfStatsFileName[0] == 0;
  this->m_bInRun = false;
  if ( !v2 )
  {
    VProfRecord_Shutdown();
    this->m_szVProfStatsFileName[0] = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10174E00
// Name: public: void CEngineStats::BeginFrame(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineStats::BeginFrame(CEngineStats *this)
{
  *(_WORD *)&this->m_InFrame = 0;
}

//------------------------------------------------------------------------------
// Address: 0x10174E10
// Name: public: void CEngineStats::EnableVProfStatsRecording(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineStats::EnableVProfStatsRecording(CEngineStats *this, const char *pFileName)
{
  V_strncpy(pDest: this->m_szVProfStatsFileName, pSrc: pFileName, maxLen: 260);
}

//------------------------------------------------------------------------------
// Address: 0x101FF7E0
// Name: public: virtual float CStatTime::GetTime(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
double __thiscall CStatTime::GetTime(CStatTime *this)
{
  return _Plat_FloatTime(this);
}

//------------------------------------------------------------------------------
// Address: 0x10318940
// Name: _dynamic_initializer_for__stats__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__stats__()
{
  ConCommand::ConCommand(
    this: &stats,
    pName: "stats",
    callback: Host_Stats_f,
    pHelpString: "Prints server performance variables",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__stats__);
}

//------------------------------------------------------------------------------
// Address: 0x10324A30
// Name: _dynamic_atexit_destructor_for__stats__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__stats__()
{
  ConCommand::~ConCommand(this: &stats);
}

//------------------------------------------------------------------------------
// Address: 0x10174E30
// Name: __CreateCEngineTraceServerIEngineTrace_interface
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CEngineTraceServer *__cdecl _CreateCEngineTraceServerIEngineTrace_interface()
{
  return &s_EngineTraceServer;
}

//------------------------------------------------------------------------------
// Address: 0x10174E40
// Name: __CreateCEngineTraceClientIEngineTrace_interface
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CEngineTraceClient *__cdecl _CreateCEngineTraceClientIEngineTrace_interface()
{
  return &s_EngineTraceClient;
}

//------------------------------------------------------------------------------
// Address: 0x10324A40
// Name: _dynamic_atexit_destructor_for__g_ServerRemoteAccess__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_ServerRemoteAccess__()
{
  CServerRemoteAccess::~CServerRemoteAccess(this: &g_ServerRemoteAccess);
}

} // namespace engine_xlsp
