// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: engine/cbenchmark.cpp
// Functions: 13
// ============================================================

#include "engine\cbenchmark.h"

//------------------------------------------------------------------------------
// Address: 0x1006E070
// Name: public: void CBenchmarkResults::StopBenchmark(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBenchmarkResults::StopBenchmark(CBenchmarkResults *this)
{
  double v2; // st7
  KeyValues *v3; // eax
  KeyValues *v4; // esi
  int v5; // eax
  IBaseFileSystem *v6; // eax
  double value; // [esp+0h] [ebp-108h] BYREF
  char szFilename[256]; // [esp+8h] [ebp-100h]

  this->m_bIsTestRunning = false;
  CLoaderMemAlloc::CrtIsValidPointer(this: (ConVar *)&host_framerate.IConVar, value: 0);
  v2 = (double)(host_framecount - this->m_iStartFrame) / (realtime - (double)this->m_flStartTime);
  *(float *)&szFilename[252] = v2;
  _Msg(a1: "Average framerate: %.2f\n", v2);
  g_pFileSystem->CreateDirHierarchy(this: g_pFileSystem, a2: "results", a3: "MOD");
  V_snprintf(pDest: (char *)&value + 4, maxLen: 256, pFormat: "%s\\%s", "results", this->m_szFilename);
  v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v3 != nullptr )
    v4 = KeyValues::KeyValues(this: v3, setName: "benchmark");
  else
    v4 = nullptr;
  KeyValues::SetFloat(this: v4, keyName: "framerate", value: *(float *)&szFilename[252]);
  v5 = build_number();
  KeyValues::SetInt(this: v4, keyName: "build", value: v5);
  GetMaterialSystemConfigForBenchmarkUpload(dataToUpload: v4);
  if ( g_pFileSystem != nullptr )
    v6 = &g_pFileSystem->IBaseFileSystem;
  else
    v6 = nullptr;
  KeyValues::SaveToFile(this: v4, filesystem: v6, resourceName: (const char *)&value + 4, pathID: "MOD");
  KeyValues::deleteThis(this: v4);
}

//------------------------------------------------------------------------------
// Address: 0x1006E180
// Name: bench_end
// Source: json
//------------------------------------------------------------------------------
void __cdecl bench_end()
{
  CBenchmarkResults::StopBenchmark(this: &g_BenchmarkResults);
}

//------------------------------------------------------------------------------
// Address: 0x1006E190
// Name: public: void CBenchmarkResults::StartBenchmark(class CCommand const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBenchmarkResults::StartBenchmark(CBenchmarkResults *this, const CCommand *args)
{
  const char *v3; // ebx

  v3 = "results.txt";
  if ( args->m_nArgc > 1 )
    v3 = args->m_ppArgv[1];
  if ( COM_IsValidPath(pszFilename: v3) )
  {
    this->m_bIsTestRunning = true;
    V_strncpy(pDest: this->m_szFilename, pSrc: v3, maxLen: 256);
    V_DefaultExtension(path: this->m_szFilename, extension: ".txt", pathStringLength: 256);
    ConVar::SetValue(this: (ConVar *)&host_framerate.IConVar, value: 1.0 / host_state.interval_per_tick);
    this->m_iStartFrame = host_framecount;
    this->m_flStartTime = (int)realtime;
  }
  else
  {
    ConMsg(a1: "bench_start %s: invalid path.\n", v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1006E240
// Name: public: void CBenchmarkResults::Upload(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBenchmarkResults::Upload(CBenchmarkResults *this)
{
  char *m_szFilename; // edi
  CSteam3Client *v2; // eax
  unsigned int v3; // eax
  unsigned __int16 v4; // si
  KeyValues *v5; // eax
  KeyValues *v6; // esi
  IBaseFileSystem *v7; // eax
  const char *v8; // eax
  char szFilename[256]; // [esp+4h] [ebp-114h] BYREF
  netadr_s netadr_CserIP; // [esp+104h] [ebp-14h] BYREF
  int cserPort; // [esp+110h] [ebp-8h] BYREF
  unsigned int cserIP; // [esp+114h] [ebp-4h] BYREF

  m_szFilename = this->m_szFilename;
  if ( this->m_szFilename[0] != 0 && Steam3Client()->m_pSteamUtils != nullptr )
  {
    cserIP = 0;
    cserPort = 0;
    do
    {
      v2 = Steam3Client();
      v2->m_pSteamUtils->GetCSERIPPort(this: v2->m_pSteamUtils, a2: &cserIP, a3: (unsigned __int16 *)&cserPort);
      v3 = cserIP;
      if ( cserIP != 0 )
        break;
      Sys_Sleep(msec: 10);
      v3 = cserIP;
    }
    while ( cserIP == 0 );
    v4 = cserPort;
    netadr_s::SetIP(this: &netadr_CserIP, unIP: v3);
    netadr_s::SetPort(this: &netadr_CserIP, newport: v4);
    netadr_s::SetType(this: &netadr_CserIP, newtype: NA_IP);
    V_snprintf(pDest: szFilename, maxLen: 256, pFormat: "%s\\%s", "results", m_szFilename);
    v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v5 != nullptr )
      v6 = KeyValues::KeyValues(this: v5, setName: "benchmark");
    else
      v6 = nullptr;
    if ( g_pFileSystem != nullptr )
      v7 = &g_pFileSystem->IBaseFileSystem;
    else
      v7 = nullptr;
    if ( KeyValues::LoadFromFile(
           this: v6,
           filesystem: v7,
           resourceName: szFilename,
           pathID: "MOD",
           pfnEvaluateSymbolProc: nullptr) )
    {
      v8 = netadr_s::ToString(this: &netadr_CserIP, baseOnly: false);
      UploadData(cserIP: v8, tablename: "benchmark", fields: v6);
    }
    KeyValues::deleteThis(this: v6);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1006E350
// Name: bench_start
// Source: json
//------------------------------------------------------------------------------
void __cdecl bench_start(const CCommand *args)
{
  CBenchmarkResults::StartBenchmark(this: &g_BenchmarkResults, args);
}

//------------------------------------------------------------------------------
// Address: 0x1006E370
// Name: bench_upload
// Source: json
//------------------------------------------------------------------------------
void __cdecl bench_upload()
{
  CBenchmarkResults::Upload(this: &g_BenchmarkResults);
}

//------------------------------------------------------------------------------
// Address: 0x10312990
// Name: _dynamic_initializer_for__bench_start_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__bench_start_command__()
{
  ConCommand::ConCommand(
    this: &bench_start_command,
    pName: "bench_start",
    callback: (void (__cdecl *)())bench_start,
    pHelpString: "Starts gathering of info. Arguments: filename to write results into",
    flags: 0x4000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__bench_start_command__);
}

//------------------------------------------------------------------------------
// Address: 0x103129C0
// Name: _dynamic_initializer_for__bench_end_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__bench_end_command__()
{
  ConCommand::ConCommand(
    this: &bench_end_command,
    pName: "bench_end",
    callback: bench_end,
    pHelpString: "Ends gathering of info.",
    flags: 0x4000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__bench_end_command__);
}

//------------------------------------------------------------------------------
// Address: 0x103129F0
// Name: _dynamic_initializer_for__bench_upload_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__bench_upload_command__()
{
  ConCommand::ConCommand(
    this: &bench_upload_command,
    pName: "bench_upload",
    callback: bench_upload,
    pHelpString: "Uploads most recent benchmark stats to the Valve servers.",
    flags: 0x4000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__bench_upload_command__);
}

//------------------------------------------------------------------------------
// Address: 0x10322300
// Name: _dynamic_atexit_destructor_for__bench_start_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__bench_start_command__()
{
  ConCommand::~ConCommand(this: &bench_start_command);
}

//------------------------------------------------------------------------------
// Address: 0x10322310
// Name: _dynamic_atexit_destructor_for__bench_end_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__bench_end_command__()
{
  ConCommand::~ConCommand(this: &bench_end_command);
}

//------------------------------------------------------------------------------
// Address: 0x10322320
// Name: _dynamic_atexit_destructor_for__bench_upload_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__bench_upload_command__()
{
  ConCommand::~ConCommand(this: &bench_upload_command);
}

//------------------------------------------------------------------------------
// Address: 0x1006E380
// Name: __CreateCEngineClientIVEngineClient_interface
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CEngineClient *__cdecl _CreateCEngineClientIVEngineClient_interface()
{
  return &s_VEngineClient;
}

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x1006DCF0
// Name: public: void CBenchmarkResults::StopBenchmark(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBenchmarkResults::StopBenchmark(CBenchmarkResults *this)
{
  double v2; // st7
  KeyValues *v3; // eax
  KeyValues *v4; // esi
  int value; // eax
  IBaseFileSystem *v6; // eax
  char szFilename[256]; // [esp+8h] [ebp-104h] BYREF
  float framerate; // [esp+108h] [ebp-4h]

  this->m_bIsTestRunning = false;
  CLoaderMemAlloc::CrtIsValidPointer(this: (ConVar *)&host_framerate.IConVar, value: 0);
  v2 = (double)(host_framecount - this->m_iStartFrame) / (realtime - (double)this->m_flStartTime);
  framerate = v2;
  _Msg(a1: "Average framerate: %.2f\n", v2);
  g_pFileSystem->CreateDirHierarchy(this: g_pFileSystem, a2: "results", a3: "MOD");
  V_snprintf(pDest: szFilename, maxLen: 256, pFormat: "%s\\%s", "results", this->m_szFilename);
  v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v3 != nullptr )
    v4 = KeyValues::KeyValues(this: v3, setName: "benchmark");
  else
    v4 = nullptr;
  KeyValues::SetFloat(this: v4, keyName: "framerate", value: framerate);
  value = build_number();
  KeyValues::SetInt(this: v4, keyName: "build", value);
  GetMaterialSystemConfigForBenchmarkUpload(dataToUpload: v4);
  if ( g_pFileSystem != nullptr )
    v6 = &g_pFileSystem->IBaseFileSystem;
  else
    v6 = nullptr;
  KeyValues::SaveToFile(this: v4, filesystem: v6, resourceName: szFilename, pathID: "MOD");
  KeyValues::deleteThis(this: v4);
}

//------------------------------------------------------------------------------
// Address: 0x1006DE00
// Name: bench_end
// Source: json
//------------------------------------------------------------------------------
void __cdecl bench_end()
{
  CBenchmarkResults::StopBenchmark(this: &g_BenchmarkResults);
}

//------------------------------------------------------------------------------
// Address: 0x1006DE10
// Name: public: void CBenchmarkResults::StartBenchmark(class CCommand const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBenchmarkResults::StartBenchmark(CBenchmarkResults *this, const CCommand *args)
{
  const char *v3; // ebx

  v3 = "results.txt";
  if ( args->m_nArgc > 1 )
    v3 = args->m_ppArgv[1];
  if ( COM_IsValidPath(pszFilename: v3) )
  {
    this->m_bIsTestRunning = true;
    V_strncpy(pDest: this->m_szFilename, pSrc: v3, maxLen: 256);
    V_DefaultExtension(path: this->m_szFilename, extension: ".txt", pathStringLength: 256);
    ConVar::SetValue(this: (ConVar *)&host_framerate.IConVar, value: 1.0 / host_state.interval_per_tick);
    this->m_iStartFrame = host_framecount;
    this->m_flStartTime = (int)realtime;
  }
  else
  {
    ConMsg(a1: "bench_start %s: invalid path.\n", v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1006DEC0
// Name: public: void CBenchmarkResults::Upload(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBenchmarkResults::Upload(CBenchmarkResults *this)
{
  char *m_szFilename; // edi
  CSteam3Client *v2; // eax
  unsigned int v3; // eax
  unsigned __int16 v4; // si
  KeyValues *v5; // eax
  KeyValues *v6; // esi
  IBaseFileSystem *v7; // eax
  const char *v8; // eax
  char szFilename[256]; // [esp+4h] [ebp-114h] BYREF
  netadr_s netadr_CserIP; // [esp+104h] [ebp-14h] BYREF
  int cserPort; // [esp+110h] [ebp-8h] BYREF
  unsigned int cserIP; // [esp+114h] [ebp-4h] BYREF

  m_szFilename = this->m_szFilename;
  if ( this->m_szFilename[0] != 0 && Steam3Client()->m_pSteamUtils != nullptr )
  {
    cserIP = 0;
    cserPort = 0;
    do
    {
      v2 = Steam3Client();
      v2->m_pSteamUtils->GetCSERIPPort(this: v2->m_pSteamUtils, a2: &cserIP, a3: (unsigned __int16 *)&cserPort);
      v3 = cserIP;
      if ( cserIP != 0 )
        break;
      Sys_Sleep(msec: 10);
      v3 = cserIP;
    }
    while ( cserIP == 0 );
    v4 = cserPort;
    netadr_s::SetIP(this: &netadr_CserIP, unIP: v3);
    netadr_s::SetPort(this: &netadr_CserIP, newport: v4);
    netadr_s::SetType(this: &netadr_CserIP, newtype: NA_IP);
    V_snprintf(pDest: szFilename, maxLen: 256, pFormat: "%s\\%s", "results", m_szFilename);
    v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v5 != nullptr )
      v6 = KeyValues::KeyValues(this: v5, setName: "benchmark");
    else
      v6 = nullptr;
    if ( g_pFileSystem != nullptr )
      v7 = &g_pFileSystem->IBaseFileSystem;
    else
      v7 = nullptr;
    if ( KeyValues::LoadFromFile(
           this: v6,
           filesystem: v7,
           resourceName: szFilename,
           pathID: "MOD",
           pfnEvaluateSymbolProc: nullptr) )
    {
      v8 = netadr_s::ToString(this: &netadr_CserIP, baseOnly: false);
      UploadData(cserIP: v8, tablename: "benchmark", fields: v6);
    }
    KeyValues::deleteThis(this: v6);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1006DFD0
// Name: bench_start
// Source: json
//------------------------------------------------------------------------------
void __cdecl bench_start(const CCommand *args)
{
  CBenchmarkResults::StartBenchmark(this: &g_BenchmarkResults, args);
}

//------------------------------------------------------------------------------
// Address: 0x1006DFF0
// Name: bench_upload
// Source: json
//------------------------------------------------------------------------------
void __cdecl bench_upload()
{
  CBenchmarkResults::Upload(this: &g_BenchmarkResults);
}

//------------------------------------------------------------------------------
// Address: 0x10312B70
// Name: _dynamic_initializer_for__bench_start_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__bench_start_command__()
{
  ConCommand::ConCommand(
    this: &bench_start_command,
    pName: "bench_start",
    callback: bench_start,
    pHelpString: "Starts gathering of info. Arguments: filename to write results into",
    flags: 0x4000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__bench_start_command__);
}

//------------------------------------------------------------------------------
// Address: 0x10312BA0
// Name: _dynamic_initializer_for__bench_end_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__bench_end_command__()
{
  ConCommand::ConCommand(
    this: &bench_end_command,
    pName: "bench_end",
    callback: (void (__cdecl *)(const CCommand *))bench_end,
    pHelpString: "Ends gathering of info.",
    flags: 0x4000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__bench_end_command__);
}

//------------------------------------------------------------------------------
// Address: 0x10312BD0
// Name: _dynamic_initializer_for__bench_upload_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__bench_upload_command__()
{
  ConCommand::ConCommand(
    this: &bench_upload_command,
    pName: "bench_upload",
    callback: (void (__cdecl *)(const CCommand *))bench_upload,
    pHelpString: "Uploads most recent benchmark stats to the Valve servers.",
    flags: 0x4000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__bench_upload_command__);
}

//------------------------------------------------------------------------------
// Address: 0x103224D0
// Name: _dynamic_atexit_destructor_for__bench_start_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__bench_start_command__()
{
  ConCommand::~ConCommand(this: &bench_start_command);
}

//------------------------------------------------------------------------------
// Address: 0x103224E0
// Name: _dynamic_atexit_destructor_for__bench_end_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__bench_end_command__()
{
  ConCommand::~ConCommand(this: &bench_end_command);
}

//------------------------------------------------------------------------------
// Address: 0x103224F0
// Name: _dynamic_atexit_destructor_for__bench_upload_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__bench_upload_command__()
{
  ConCommand::~ConCommand(this: &bench_upload_command);
}

} // namespace engine_xlsp
