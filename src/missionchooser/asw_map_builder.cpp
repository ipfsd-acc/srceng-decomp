// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: missionchooser/asw_map_builder.cpp
// Functions: 23
// ============================================================

#include "missionchooser\asw_map_builder.h"

//------------------------------------------------------------------------------
// Address: 0x10002E50
// Name: public: virtual bool CASW_Map_Builder::IsBuildingMission(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CASW_Map_Builder::IsBuildingMission(CASW_Map_Builder *this)
{
  return this->m_iBuildStage != STAGE_NONE;
}

//------------------------------------------------------------------------------
// Address: 0x10002E60
// Name: private: void CASW_Map_Builder::FinishExecution(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CASW_Map_Builder::FinishExecution(CASW_Map_Builder *this)
{
  MapBuildStage m_iBuildStage; // eax
  const char *String; // eax
  const char *v4; // eax
  void *m_hChildStderrWr; // [esp-4h] [ebp-20Ch]
  char buffer[512]; // [esp+8h] [ebp-200h] BYREF

  m_hChildStderrWr = this->m_hChildStderrWr;
  this->m_bRunningProcess = false;
  CloseHandle(hObject: m_hChildStderrWr);
  CloseHandle(hObject: this->m_hChildStdinRd);
  CloseHandle(hObject: this->m_hChildStdinWr);
  CloseHandle(hObject: this->m_hChildStdoutRd);
  CloseHandle(hObject: this->m_hChildStdoutWr);
  m_iBuildStage = this->m_iBuildStage;
  if ( m_iBuildStage == STAGE_VBSP && this->m_iProcessReturnValue == 0 )
  {
    String = KeyValues::GetString(this: this->m_pMapBuilderOptions, keyName: "vvis", defaultValue: szDescription);
    V_snprintf(pDest: buffer, maxLen: 512, pFormat: "-game ..\\ %s %s", String, this->m_szLayoutName);
    CASW_Map_Builder::Execute(this, pszCmd: "bin/vvis.exe", pszCmdLine: buffer);
    this->m_iBuildStage = STAGE_VVIS;
    return;
  }
  if ( m_iBuildStage == STAGE_VVIS && this->m_iProcessReturnValue == 0 )
  {
    if ( KeyValues::FindKey(this: this->m_pMapBuilderOptions, keyName: "vrad", bCreate: false) != nullptr )
    {
      v4 = KeyValues::GetString(this: this->m_pMapBuilderOptions, keyName: "vrad", defaultValue: szDescription);
      V_snprintf(pDest: buffer, maxLen: 512, pFormat: "-low -game ..\\ %s %s", v4, this->m_szLayoutName);
      CASW_Map_Builder::Execute(this, pszCmd: "bin/vrad.exe", pszCmdLine: buffer);
      this->m_iBuildStage = STAGE_VRAD;
      return;
    }
    goto LABEL_10;
  }
  if ( m_iBuildStage == STAGE_VRAD && this->m_iProcessReturnValue == 0 )
  {
LABEL_10:
    this->m_iBuildStage = STAGE_NONE;
    _Msg(a1: "Map Build finished!\n");
    this->m_flProgress = 1.0;
    V_snprintf(pDest: this->m_szStatusMessage, maxLen: 128, pFormat: "Build complete!");
  }
}

//------------------------------------------------------------------------------
// Address: 0x10002FF0
// Name: private: void CASW_Map_Builder::UpdateProgress(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CASW_Map_Builder::UpdateProgress(CASW_Map_Builder *this)
{
  int v2; // eax
  int i; // edx
  int v4; // esi

  v2 = _V_strlen(str: this->m_szProcessBuffer);
  for ( i = 0; i < v2; ++i )
  {
    this->m_szOutputBuffer[this->m_iOutputBufferPos] = this->m_szProcessBuffer[i];
    if ( ++this->m_iOutputBufferPos >= 4096 )
    {
      qmemcpy(this->m_szOutputBuffer, &this->m_szOutputBuffer[2048], 0x800u);
      this->m_iOutputBufferPos = 2048;
    }
  }
  v4 = 13;
  if ( this->m_iCurrentBuildSearch < 13 )
  {
    while ( _V_strstr(s1: this->m_szOutputBuffer, search: s_szProgressTerms[v4]) == nullptr )
    {
      if ( --v4 <= this->m_iCurrentBuildSearch )
        return;
    }
    this->m_iCurrentBuildSearch = v4;
    this->m_flProgress = (float)v4 * 0.071428575;
    if ( _V_strlen(str: s_szStatusLabels[v4]) > 0 )
      V_snprintf(pDest: this->m_szStatusMessage, maxLen: 128, pFormat: "%s", s_szStatusLabels[v4]);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100030F0
// Name: public: virtual void CASW_Map_Builder::ScheduleMapBuild(char const __near *,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CASW_Map_Builder::ScheduleMapBuild(CASW_Map_Builder *this, const char *pszMap, float fTime)
{
  const char *v4; // eax

  if ( this->m_iBuildStage != STAGE_NONE )
  {
    if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_TilegenGeneral, a2: 1) != 0 )
      _LoggingSystem_Log(
        a1: LOG_TilegenGeneral,
        a2: 1,
        a3: "Map builder is currently busy, ignoring request to schedule map build for map '%s'",
        pszMap);
  }
  else
  {
    v4 = V_UnqualifiedFileName(in: pszMap);
    V_strncpy(pDest: this->m_szLayoutName, pSrc: v4, maxLen: 260);
    V_SetExtension(path: this->m_szLayoutName, extension: "layout", pathStringLength: 260);
    this->m_flStartProcessingTime = fTime;
    this->m_bStartedGeneration = false;
    this->m_iBuildStage = STAGE_MAP_BUILD_SCHEDULED;
    this->m_flProgress = 0.0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100031A0
// Name: public: virtual void CASW_Map_Builder::ScheduleMapGeneration(char const __near *,float,class KeyValues __near *,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CASW_Map_Builder::ScheduleMapGeneration(
        CASW_Map_Builder *this,
        const char *pszMap,
        float fTime,
        KeyValues *pMissionSettings,
        KeyValues *pMissionDefinition)
{
  const char *v6; // eax

  if ( this->m_iBuildStage != STAGE_NONE )
  {
    if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_TilegenGeneral, a2: 1) != 0 )
      _LoggingSystem_Log(
        a1: LOG_TilegenGeneral,
        a2: 1,
        a3: "Map builder is currently busy, ignoring request to schedule map generation for map '%s'",
        pszMap);
  }
  else
  {
    v6 = V_UnqualifiedFileName(in: pszMap);
    V_strncpy(pDest: this->m_szLayoutName, pSrc: v6, maxLen: 260);
    V_SetExtension(path: this->m_szLayoutName, extension: "layout", pathStringLength: 260);
    this->m_flStartProcessingTime = fTime;
    this->m_pMissionSettings = pMissionSettings;
    this->m_pMissionDefinition = pMissionDefinition;
    this->m_iBuildStage = STAGE_GENERATE;
    this->m_bStartedGeneration = false;
    this->m_nLevelGenerationRetryCount = 0;
    this->m_flProgress = 0.0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100032B0
// Name: public: CASW_Map_Builder::CASW_Map_Builder(void)
// Source: json
//------------------------------------------------------------------------------
CASW_Map_Builder *__thiscall CASW_Map_Builder::CASW_Map_Builder(CASW_Map_Builder *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // eax
  IBaseFileSystem *v4; // ecx
  CWorkerThread *v5; // eax
  CMapBuilderWorkerThread *v6; // edi
  CMapBuilderWorkerThread *v7; // ecx

  this->__vftable = (CASW_Map_Builder_vtbl *)&CASW_Map_Builder::`vftable';
  this->m_nVBSP2Progress.m_value = 0;
  this->m_flStartProcessingTime = 0.0;
  this->m_iBuildStage = STAGE_NONE;
  this->m_bStartedGeneration = false;
  this->m_flProgress = 0.0;
  this->m_pGeneratedMapLayout = nullptr;
  this->m_pBuildingMapLayout = nullptr;
  this->m_pLayoutSystem = nullptr;
  this->m_nLevelGenerationRetryCount = 0;
  this->m_pMissionSettings = nullptr;
  this->m_pMissionDefinition = nullptr;
  this->m_pWorkerThread = nullptr;
  this->m_szLayoutName[0] = 0;
  this->m_iCurrentBuildSearch = 0;
  *(_WORD *)&this->m_bRunningProcess = 0;
  V_snprintf(pDest: this->m_szStatusMessage, maxLen: 128, pFormat: "Generating map...");
  v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v2 != nullptr )
    v3 = KeyValues::KeyValues(this: v2, setName: "map_builder_options");
  else
    v3 = nullptr;
  this->m_pMapBuilderOptions = v3;
  if ( g_pFullFileSystem != nullptr )
    v4 = &g_pFullFileSystem->IBaseFileSystem;
  else
    v4 = nullptr;
  KeyValues::LoadFromFile(
    this: v3,
    filesystem: v4,
    resourceName: "resource/map_builder_options.txt",
    pathID: "GAME",
    pfnEvaluateSymbolProc: nullptr);
  v5 = (CWorkerThread *)operator new(nSize: 0x84u);
  v6 = (CMapBuilderWorkerThread *)v5;
  if ( v5 != nullptr )
  {
    CWorkerThread::CWorkerThread(this: v5);
    v6->__vftable = (CMapBuilderWorkerThread_vtbl *)&CMapBuilderWorkerThread::`vftable';
    v6->m_pMapBuilder = this;
    v7 = v6;
  }
  else
  {
    v7 = nullptr;
  }
  this->m_pWorkerThread = v7;
  v7->Start(this: v7, a2: 0, a3: PRIORITY_DEFAULT);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100033C0
// Name: public: virtual float CASW_Map_Builder::GetProgress(void)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CASW_Map_Builder::GetProgress(CASW_Map_Builder *this)
{
  return this->m_flProgress;
}

//------------------------------------------------------------------------------
// Address: 0x100033D0
// Name: public: virtual char const __near * CASW_Map_Builder::GetStatusMessage(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CASW_Map_Builder::GetStatusMessage(CASW_Map_Builder *this)
{
  return this->m_szStatusMessage;
}

//------------------------------------------------------------------------------
// Address: 0x100033E0
// Name: public: virtual char const __near * CASW_Map_Builder::GetMapName(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CASW_Map_Builder::GetMapName(CASW_Map_Builder *this)
{
  return this->m_szLayoutName;
}

//------------------------------------------------------------------------------
// Address: 0x100033F0
// Name: private: void CASW_Map_Builder::ProcessExecution(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CASW_Map_Builder::ProcessExecution(CASW_Map_Builder *this)
{
  DWORD v2; // eax
  void *m_hChildStdoutRd; // [esp-18h] [ebp-28h]
  unsigned int dwRead; // [esp+8h] [ebp-8h] BYREF
  unsigned int dwCount; // [esp+Ch] [ebp-4h] BYREF

  m_hChildStdoutRd = this->m_hChildStdoutRd;
  dwCount = 0;
  dwRead = 0;
  PeekNamedPipe(
    hNamedPipe: m_hChildStdoutRd,
    lpBuffer: nullptr,
    nBufferSize: 0,
    lpBytesRead: nullptr,
    lpTotalBytesAvail: &dwCount,
    lpBytesLeftThisMessage: nullptr);
  v2 = dwCount;
  if ( dwCount != 0 )
  {
    if ( dwCount >= 0xFFF )
    {
      v2 = 4095;
      dwCount = 4095;
    }
    ReadFile(
      hFile: this->m_hChildStdoutRd,
      lpBuffer: this->m_szProcessBuffer,
      nNumberOfBytesToRead: v2,
      lpNumberOfBytesRead: &dwRead,
      lpOverlapped: nullptr);
  }
  if ( dwRead != 0 )
  {
    this->m_szProcessBuffer[dwRead] = 0;
    CASW_Map_Builder::UpdateProgress(this);
    _Msg(a1: this->m_szProcessBuffer);
  }
  else if ( WaitForSingleObject(hHandle: this->m_hProcess, dwMilliseconds: 0x3E8u) != 258 )
  {
    if ( this->m_bFinishedExecution )
    {
      this->m_iProcessReturnValue = 0;
      CASW_Map_Builder::FinishExecution(this);
    }
    else
    {
      this->m_bFinishedExecution = true;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100034C0
// Name: private: void CASW_Map_Builder::UpdateVBSP2Progress(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CASW_Map_Builder::UpdateVBSP2Progress(CASW_Map_Builder *this)
{
  volatile int m_value; // edi
  float v3; // xmm0_4
  int v4; // eax
  CMapLayout *m_pBuildingMapLayout; // ecx

  m_value = this->m_nVBSP2Progress.m_value;
  if ( m_value == 100 )
    v3 = 1.0;
  else
    v3 = (float)m_value * 0.0099999998;
  this->m_flProgress = v3;
  v4 = 5;
  while ( m_value < g_ProgressAmounts[v4] )
  {
    if ( --v4 < 0 )
      goto LABEL_9;
  }
  V_strncpy(pDest: this->m_szStatusMessage, pSrc: g_ProgressLabels[v4], maxLen: 128);
LABEL_9:
  if ( m_value == 100 )
  {
    m_pBuildingMapLayout = this->m_pBuildingMapLayout;
    if ( m_pBuildingMapLayout != nullptr )
      ((void (__thiscall *)(CMapLayout *, int))m_pBuildingMapLayout->dtr_CMapLayout)(a1: m_pBuildingMapLayout, a2: 1);
    this->m_pBuildingMapLayout = nullptr;
    this->m_iBuildStage = STAGE_NONE;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100035F0
// Name: private: void CASW_Map_Builder::Execute(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CASW_Map_Builder::Execute(CASW_Map_Builder *this, const char *pszCmd, const char *pszCmdLine)
{
  void **p_m_hChildStdoutWr; // edi
  HANDLE v5; // eax
  void *m_hChildStderrWr; // ecx
  void *v7; // edx
  void (__stdcall *v8)(HANDLE); // esi
  void *v9; // [esp-18h] [ebp-490h]
  HANDLE CurrentProcess; // [esp-14h] [ebp-48Ch]
  char dirbuffer[512]; // [esp+Ch] [ebp-46Ch] BYREF
  char cmdbuffer[512]; // [esp+20Ch] [ebp-26Ch] BYREF
  _STARTUPINFOA StartupInfo; // [esp+40Ch] [ebp-6Ch] BYREF
  _PROCESS_INFORMATION pi; // [esp+450h] [ebp-28h] BYREF
  _SECURITY_ATTRIBUTES saAttr; // [esp+460h] [ebp-18h] BYREF
  void **p_m_hChildStdinWr; // [esp+46Ch] [ebp-Ch]
  void **p_m_hChildStdinRd; // [esp+470h] [ebp-8h]
  void **p_m_hChildStdoutRd; // [esp+474h] [ebp-4h]

  p_m_hChildStdoutWr = &this->m_hChildStdoutWr;
  this->m_bFinishedExecution = false;
  this->m_iProcessReturnValue = -1;
  saAttr.nLength = 12;
  saAttr.bInheritHandle = 1;
  saAttr.lpSecurityDescriptor = nullptr;
  p_m_hChildStdoutRd = &this->m_hChildStdoutRd;
  if ( CreatePipe(
         hReadPipe: &this->m_hChildStdoutRd,
         hWritePipe: &this->m_hChildStdoutWr,
         lpPipeAttributes: &saAttr,
         nSize: 0) )
  {
    p_m_hChildStdinWr = &this->m_hChildStdinWr;
    p_m_hChildStdinRd = &this->m_hChildStdinRd;
    if ( CreatePipe(
           hReadPipe: &this->m_hChildStdinRd,
           hWritePipe: &this->m_hChildStdinWr,
           lpPipeAttributes: &saAttr,
           nSize: 0) )
    {
      CurrentProcess = GetCurrentProcess();
      v9 = *p_m_hChildStdoutWr;
      v5 = GetCurrentProcess();
      if ( DuplicateHandle(
             hSourceProcessHandle: v5,
             hSourceHandle: v9,
             hTargetProcessHandle: CurrentProcess,
             lpTargetHandle: &this->m_hChildStderrWr,
             dwDesiredAccess: 0,
             bInheritHandle: true,
             dwOptions: 2u) )
      {
        memset(dst: (unsigned __int8 *)&StartupInfo, value: 0, count: sizeof(StartupInfo));
        m_hChildStderrWr = this->m_hChildStderrWr;
        v7 = *p_m_hChildStdoutWr;
        StartupInfo.hStdInput = *p_m_hChildStdinRd;
        StartupInfo.hStdError = m_hChildStderrWr;
        StartupInfo.cb = 68;
        StartupInfo.dwFlags = 256;
        StartupInfo.hStdOutput = v7;
        V_snprintf(pDest: cmdbuffer, maxLen: 512, pFormat: "%s %s", pszCmd, pszCmdLine);
        _Msg(a1: "Sending command %s\n", cmdbuffer);
        V_snprintf(pDest: dirbuffer, maxLen: 512, pFormat: "%s/maps", "infested");
        _Msg(a1: "  from directory %s\n", dirbuffer);
        if ( CreateProcessA(
               lpApplicationName: pszCmd,
               lpCommandLine: cmdbuffer,
               lpProcessAttributes: nullptr,
               lpThreadAttributes: nullptr,
               bInheritHandles: true,
               dwCreationFlags: 0x4008u,
               lpEnvironment: nullptr,
               lpCurrentDirectory: dirbuffer,
               lpStartupInfo: &StartupInfo,
               lpProcessInformation: &pi) )
        {
          this->m_hProcess = pi.hProcess;
          *(_WORD *)&this->m_bRunningProcess = 1;
          CASW_Map_Builder::ProcessExecution(this);
        }
        else
        {
          _Msg(a1: "* Could not execute the command:\r\n   %s\r\n", cmdbuffer);
          this->m_bRunningProcess = false;
          CASW_Map_Builder::FinishExecution(this);
        }
        return;
      }
      v8 = (void (__stdcall *)(HANDLE))CloseHandle;
      CloseHandle(hObject: *p_m_hChildStdinRd);
      CloseHandle(hObject: *p_m_hChildStdinWr);
    }
    else
    {
      v8 = (void (__stdcall *)(HANDLE))CloseHandle;
    }
    v8(hObject: *p_m_hChildStdoutRd);
    v8(hObject: *p_m_hChildStdoutWr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100037E0
// Name: private: void CASW_Map_Builder::BuildMap(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CASW_Map_Builder::BuildMap(CASW_Map_Builder *this)
{
  char *m_szLayoutName; // ebx
  VMFExporter *v3; // edi
  CMapLayout *m_pBuildingMapLayout; // ecx
  CMapLayout *v5; // eax
  CMapLayout *v6; // eax
  CMapLayout *v7; // ecx
  VMFExporter *v8; // eax
  CMapLayout *v9; // ecx
  CMapLayout *v10; // ecx
  KeyValues *m_pMapBuilderOptions; // ecx
  const char *String; // eax
  char buffer[512]; // [esp+Ch] [ebp-40Ch] BYREF
  char layoutFilename[260]; // [esp+20Ch] [ebp-20Ch] BYREF
  char vmfFilename[263]; // [esp+310h] [ebp-108h] BYREF
  bool bSuccess; // [esp+417h] [ebp-1h]

  m_szLayoutName = this->m_szLayoutName;
  V_snprintf(pDest: layoutFilename, maxLen: 260, pFormat: "maps\\%s", this->m_szLayoutName);
  V_strncpy(pDest: vmfFilename, pSrc: m_szLayoutName, maxLen: 260);
  V_SetExtension(path: vmfFilename, extension: "vmf", pathStringLength: 260);
  v3 = nullptr;
  if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_TilegenGeneral, a2: 0) != 0 )
    _LoggingSystem_Log(
      a1: LOG_TilegenGeneral,
      a2: 0,
      a3: "Building map from layout: %s, emitting map file: %s\n",
      layoutFilename,
      vmfFilename);
  CLevelTheme::LoadLevelThemes();
  m_pBuildingMapLayout = this->m_pBuildingMapLayout;
  if ( m_pBuildingMapLayout != nullptr )
    ((void (__thiscall *)(CMapLayout *, int))m_pBuildingMapLayout->dtr_CMapLayout)(a1: m_pBuildingMapLayout, a2: 1);
  v5 = (CMapLayout *)operator new(nSize: 0xE264u);
  if ( v5 != nullptr )
    v6 = CMapLayout::CMapLayout(this: v5, pGenerationOptions: nullptr);
  else
    v6 = nullptr;
  this->m_pBuildingMapLayout = v6;
  if ( CMapLayout::LoadMapLayout(this: v6, filename: layoutFilename) )
  {
    v8 = (VMFExporter *)operator new(nSize: 0x1BCu);
    if ( v8 != nullptr )
      v3 = VMFExporter::VMFExporter(this: v8);
    bSuccess = VMFExporter::ExportVMF(
                 this: v3,
                 pLayout: this->m_pBuildingMapLayout,
                 mapname: m_szLayoutName,
                 bPopupWarnings: false);
    if ( v3 != nullptr )
      ((void (__thiscall *)(VMFExporter *, int))v3->dtr_VMFExporter)(a1: v3, a2: 1);
    if ( !bSuccess )
    {
      if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_TilegenGeneral, a2: 1) != 0 )
        _LoggingSystem_Log(
          a1: LOG_TilegenGeneral,
          a2: 1,
          a3: "Failed to create VMF from layout '%s'.\n",
          m_szLayoutName);
      v9 = this->m_pBuildingMapLayout;
      if ( v9 != nullptr )
        ((void (__thiscall *)(CMapLayout *, int))v9->dtr_CMapLayout)(a1: v9, a2: 1);
      this->m_pBuildingMapLayout = nullptr;
    }
    if ( asw_vbsp2.m_pParent != nullptr && asw_vbsp2.m_pParent->m_Value.m_nValue != 0 )
    {
      this->m_iBuildStage = STAGE_VBSP2;
      _InterlockedExchange(&this->m_nVBSP2Progress.m_value, 0);
      V_strncpy(pDest: this->m_szVBSP2MapName, pSrc: vmfFilename, maxLen: 260);
      CWorkerThread::CallWorker(this: this->m_pWorkerThread, a2: 0, a3: 0, a4: true);
    }
    else
    {
      v10 = this->m_pBuildingMapLayout;
      if ( v10 != nullptr )
        ((void (__thiscall *)(CMapLayout *, int))v10->dtr_CMapLayout)(a1: v10, a2: 1);
      m_pMapBuilderOptions = this->m_pMapBuilderOptions;
      this->m_pBuildingMapLayout = nullptr;
      this->m_iBuildStage = STAGE_VBSP;
      String = KeyValues::GetString(this: m_pMapBuilderOptions, keyName: "vbsp", defaultValue: szDescription);
      V_snprintf(pDest: buffer, maxLen: 512, pFormat: "-game ..\\ %s %s", String, vmfFilename);
      CASW_Map_Builder::Execute(this, pszCmd: "bin/vbsp.exe", pszCmdLine: buffer);
      this->m_iCurrentBuildSearch = 0;
      this->m_iOutputBufferPos = 0;
      _V_memset(dest: this->m_szOutputBuffer, fill: 0, count: 4096);
    }
  }
  else
  {
    v7 = this->m_pBuildingMapLayout;
    if ( v7 != nullptr )
      ((void (__thiscall *)(CMapLayout *, int))v7->dtr_CMapLayout)(a1: v7, a2: 1);
    this->m_pBuildingMapLayout = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10003A50
// Name: public: virtual void CASW_Map_Builder::Update(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CASW_Map_Builder::Update(CASW_Map_Builder *this, float flEngineTime)
{
  MapBuildStage m_iBuildStage; // eax
  CMapLayout *v4; // ecx
  CLayoutSystem *v5; // edi
  CLayoutSystem *v6; // eax
  CLayoutSystem *v7; // eax
  CMapLayout *v8; // edi
  KeyValues *Copy; // eax
  CMapLayout *v10; // eax
  CLayoutSystem *v11; // ecx
  CLayoutSystem *m_pLayoutSystem; // ecx
  CLayoutSystem *v13; // ecx
  int m_nValue; // eax
  int v15; // eax
  CMapLayout *m_pGeneratedMapLayout; // ecx
  char layoutFilename[260]; // [esp+8h] [ebp-104h] BYREF

  if ( this->m_bRunningProcess )
  {
    CASW_Map_Builder::ProcessExecution(this);
  }
  else
  {
    m_iBuildStage = this->m_iBuildStage;
    if ( m_iBuildStage == STAGE_MAP_BUILD_SCHEDULED )
    {
      if ( flEngineTime > this->m_flStartProcessingTime )
        CASW_Map_Builder::BuildMap(this);
    }
    else if ( m_iBuildStage == STAGE_VBSP2 )
    {
      CASW_Map_Builder::UpdateVBSP2Progress(this);
    }
    else if ( m_iBuildStage == STAGE_GENERATE && flEngineTime > this->m_flStartProcessingTime )
    {
      if ( this->m_bStartedGeneration )
      {
        m_pLayoutSystem = this->m_pLayoutSystem;
        if ( m_pLayoutSystem->m_bGenerating )
        {
          CLayoutSystem::ExecuteIteration(this: m_pLayoutSystem);
          v13 = this->m_pLayoutSystem;
          if ( v13->m_bLayoutError )
          {
            if ( tilegen_retry_count.m_pParent != nullptr )
              m_nValue = tilegen_retry_count.m_pParent->m_Value.m_nValue;
            else
              m_nValue = 0;
            if ( this->m_nLevelGenerationRetryCount >= m_nValue || v13->m_nRandomSeed != 0 )
            {
              if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_TilegenGeneral, a2: 1) != 0 )
              {
                if ( tilegen_retry_count.m_pParent != nullptr )
                  v15 = tilegen_retry_count.m_pParent->m_Value.m_nValue;
                else
                  v15 = 0;
                _LoggingSystem_Log(
                  a1: LOG_TilegenGeneral,
                  a2: 1,
                  a3: "Failed to generate valid map layout after %d tries...\n",
                  v15);
              }
              this->m_iBuildStage = STAGE_NONE;
            }
            else
            {
              if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_TilegenGeneral, a2: 0) != 0 )
                _LoggingSystem_Log(a1: LOG_TilegenGeneral, a2: 0, a3: "Retrying layout generation...\n");
              CMapLayout::Clear(this: this->m_pGeneratedMapLayout);
              CLayoutSystem::BeginGeneration(this: this->m_pLayoutSystem, pMapLayout: this->m_pGeneratedMapLayout);
              ++this->m_nLevelGenerationRetryCount;
            }
          }
        }
        else
        {
          if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_TilegenGeneral, a2: 0) != 0 )
            _LoggingSystem_Log(a1: LOG_TilegenGeneral, a2: 0, a3: "Map layout generated\n");
          this->m_iBuildStage = STAGE_NONE;
          V_snprintf(pDest: layoutFilename, maxLen: 260, pFormat: "maps\\%s", this->m_szLayoutName);
          CMapLayout::SaveMapLayout(this: this->m_pGeneratedMapLayout, filename: layoutFilename);
          m_pGeneratedMapLayout = this->m_pGeneratedMapLayout;
          if ( m_pGeneratedMapLayout != nullptr )
            ((void (__thiscall *)(CMapLayout *, int))m_pGeneratedMapLayout->dtr_CMapLayout)(
              a1: m_pGeneratedMapLayout,
              a2: 1);
          this->m_pGeneratedMapLayout = nullptr;
          CASW_Map_Builder::BuildMap(this);
        }
      }
      else
      {
        v4 = this->m_pGeneratedMapLayout;
        if ( v4 != nullptr )
          ((void (__thiscall *)(CMapLayout *, int))v4->dtr_CMapLayout)(a1: v4, a2: 1);
        v5 = this->m_pLayoutSystem;
        if ( v5 != nullptr )
        {
          CLayoutSystem::~CLayoutSystem(this: this->m_pLayoutSystem);
          free(pMem: v5);
        }
        v6 = (CLayoutSystem *)operator new(nSize: 0x154u);
        if ( v6 != nullptr )
          v7 = CLayoutSystem::CLayoutSystem(this: v6);
        else
          v7 = nullptr;
        this->m_pLayoutSystem = v7;
        AddListeners(pLayoutSystem: v7);
        v8 = (CMapLayout *)operator new(nSize: 0xE264u);
        if ( v8 != nullptr )
        {
          Copy = KeyValues::MakeCopy(this: this->m_pMissionSettings);
          v10 = CMapLayout::CMapLayout(this: v8, pGenerationOptions: Copy);
        }
        else
        {
          v10 = nullptr;
        }
        v11 = this->m_pLayoutSystem;
        this->m_pGeneratedMapLayout = v10;
        if ( CLayoutSystem::LoadFromKeyValues(this: v11, pKeyValues: this->m_pMissionDefinition) )
        {
          CLayoutSystem::BeginGeneration(this: this->m_pLayoutSystem, pMapLayout: this->m_pGeneratedMapLayout);
          this->m_bStartedGeneration = true;
        }
        else
        {
          if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_TilegenLayoutSystem, a2: 1) != 0 )
            _LoggingSystem_Log(
              a1: LOG_TilegenLayoutSystem,
              a2: 1,
              a3: "Failed to load mission from key values definition.\n");
          this->m_iBuildStage = STAGE_NONE;
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10003E00
// Name: AddFuncInstance
// Source: json
//------------------------------------------------------------------------------
void __usercall AddFuncInstance(
        CInstanceSpawn *pInstanceSpawn@<esi>,
        CSimpleMapFile *pInstanceMapFile,
        const Vector *vPosition)
{
  MapEntityKeyValuePair_t *m_pMemory; // edi
  int v4; // edx
  int v5; // eax
  MapEntityKeyValuePair_t *v6; // ecx
  float z; // edx
  QAngle v8; // [esp-20h] [ebp-48h] BYREF
  Vector v9; // [esp-14h] [ebp-3Ch]
  int m_Size; // [esp-4h] [ebp-2Ch]
  CUtlVector<MapEntityKeyValuePair_t,CUtlMemory<MapEntityKeyValuePair_t,int> > replacePairs; // [esp+8h] [ebp-20h] BYREF
  __int64 v12; // [esp+1Ch] [ebp-Ch]
  int v13; // [esp+24h] [ebp-4h]

  m_Size = pInstanceSpawn->m_AdditionalKeyValues.m_Size;
  memset(&replacePairs, 0, sizeof(replacePairs));
  CUtlVector<dbrush_t,CUtlMemory<dbrush_t,int>>::InsertMultipleBefore(
    this: (CUtlVector<Vector,CUtlMemory<Vector,int> > *)&replacePairs,
    elem: 0,
    num: m_Size);
  m_pMemory = replacePairs.m_Memory.m_pMemory;
  v4 = 0;
  if ( pInstanceSpawn->m_AdditionalKeyValues.m_Size > 0 )
  {
    v5 = 0;
    v6 = replacePairs.m_Memory.m_pMemory;
    do
    {
      v6->m_pKey = pInstanceSpawn->m_AdditionalKeyValues.m_Memory.m_pMemory[v5].m_Key;
      v6->m_pValue = pInstanceSpawn->m_AdditionalKeyValues.m_Memory.m_pMemory[v5].m_Value;
      ++v4;
      ++v5;
      ++v6;
    }
    while ( v4 < pInstanceSpawn->m_AdditionalKeyValues.m_Size );
  }
  z = vPosition->z;
  v13 = 0;
  v12 = 0;
  *(_QWORD *)&v9.x = *(_QWORD *)&vPosition->x;
  v9.z = z;
  memset(&v8, 0, sizeof(v8));
  CSimpleMapFile::AddFuncInstance(
    this: pInstanceMapFile,
    pFilename: pInstanceSpawn->m_InstanceFilename,
    angles: v8,
    vOrigin: v9,
    pExtraKeyValues: m_pMemory,
    nExtraKeyValues: replacePairs.m_Size);
  if ( replacePairs.m_Memory.m_nGrowSize >= 0 && m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x10003EE0
// Name: FixupInstance
// Source: json
//------------------------------------------------------------------------------
void __cdecl FixupInstance(
        CMapLayout *pContext,
        CSimpleMapFile *pInstanceMapFile,
        MapEntityKeyValuePair_t *pFuncInstanceKeyValuePairs,
        int nNumKeyValuePairs)
{
  MapEntityKeyValuePair_t *Pair; // eax
  int m_Size; // ebx
  int Entity; // esi
  int v7; // edi
  Vector *m_pMemory; // ecx
  Vector *v9; // eax
  int v10; // eoff
  int v11; // edi
  CMapLayout *v12; // eax
  CInstanceSpawn *v13; // esi
  CUtlVector<Vector,CUtlMemory<Vector,int> > infoNodeLocations; // [esp+4h] [ebp-1Ch] BYREF
  int nPlacedRoomIndex; // [esp+18h] [ebp-8h]
  int i; // [esp+1Ch] [ebp-4h]
  CMapLayout *pMapLayout; // [esp+28h] [ebp+8h]

  pMapLayout = (CMapLayout *)pContext->m_pRoomGrid[18][52];
  Pair = FindPair(pKeyName: "PlacedRoomIndex", pPairs: pFuncInstanceKeyValuePairs, nNumPairs: nNumKeyValuePairs);
  m_Size = 0;
  if ( Pair != nullptr )
  {
    nPlacedRoomIndex = atoi(nptr: Pair->m_pValue);
    memset(&infoNodeLocations, 0, sizeof(infoNodeLocations));
    Entity = CSimpleMapFile::FindEntity(
               this: pInstanceMapFile,
               pClassName: "info_node",
               pKeyName: nullptr,
               pValue: nullptr,
               nStartingIndex: 0);
    if ( Entity != -1 )
    {
      do
      {
        i = (int)&pInstanceMapFile->m_Entities.m_Memory.m_pMemory[Entity];
        v7 = m_Size;
        if ( m_Size + 1 > infoNodeLocations.m_Memory.m_nAllocationCount )
        {
          CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int>::Grow(
            this: (CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int> *)&infoNodeLocations,
            num: m_Size - infoNodeLocations.m_Memory.m_nAllocationCount + 1);
          m_Size = infoNodeLocations.m_Size;
        }
        m_pMemory = infoNodeLocations.m_Memory.m_pMemory;
        infoNodeLocations.m_Size = ++m_Size;
        infoNodeLocations.m_pElements = infoNodeLocations.m_Memory.m_pMemory;
        if ( m_Size - v7 - 1 > 0 )
        {
          _V_memmove(
            dest: &infoNodeLocations.m_Memory.m_pMemory[v7 + 1],
            src: &infoNodeLocations.m_Memory.m_pMemory[v7],
            count: 12 * (m_Size - v7 - 1));
          m_pMemory = infoNodeLocations.m_Memory.m_pMemory;
        }
        v9 = &m_pMemory[v7];
        if ( v9 != nullptr )
        {
          v10 = i;
          *(_QWORD *)&v9->x = *(_QWORD *)i;
          v9->z = *(float *)(v10 + 8);
        }
        Entity = CSimpleMapFile::FindEntity(
                   this: pInstanceMapFile,
                   pClassName: "info_node",
                   pKeyName: nullptr,
                   pValue: nullptr,
                   nStartingIndex: Entity + 1);
      }
      while ( Entity != -1 );
      v11 = 0;
      if ( m_Size != 0 )
      {
        v12 = pMapLayout;
        for ( i = 0; i < v12->m_InstanceSpawns.m_Size; ++i )
        {
          v13 = &v12->m_InstanceSpawns.m_Memory.m_pMemory[v11];
          if ( v13->m_nPlacedRoomIndex == nPlacedRoomIndex && v13->m_InstanceSpawningMethod == ISM_ADD_AT_RANDOM_NODE )
          {
            AddFuncInstance(
              pInstanceSpawn: v13,
              pInstanceMapFile,
              vPosition: &infoNodeLocations.m_Memory.m_pMemory[v13->m_nRandomSeed % m_Size]);
            v12 = pMapLayout;
          }
          ++v11;
        }
      }
    }
    CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&infoNodeLocations);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100042E0
// Name: public: CSimpleMapFile::~CSimpleMapFile(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSimpleMapFile::~CSimpleMapFile(CSimpleMapFile *this)
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&this->m_MaterialInfos);
  CStringPool::~CStringPool(this: &this->m_KeyValueStringPool);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&this->m_KeyValuePairs);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&this->m_TextureData);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&this->m_TextureInfos);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&this->m_BrushTextures);
  CUtlVector<MapBrushSide_t,CUtlMemory<MapBrushSide_t,int>>::~CUtlVector<MapBrushSide_t,CUtlMemory<MapBrushSide_t,int>>(this: &this->m_BrushSides);
  CUtlVector<CMapDisplacement,CUtlMemory<CMapDisplacement,int>>::~CUtlVector<CMapDisplacement,CUtlMemory<CMapDisplacement,int>>(this: &this->m_Displacements);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&this->m_Brushes);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&this->m_Entities);
  this->m_PlaneHash.m_Planes.__vftable = (CCopyableUtlVector<HashedPlane_t>_vtbl *)&CCopyableUtlVector<HashedPlane_t>::`vftable';
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&this->m_PlaneHash.m_Planes.CUtlVector<HashedPlane_t,CUtlMemory<HashedPlane_t,int> >);
}

//------------------------------------------------------------------------------
// Address: 0x10004370
// Name: public: virtual int CMapBuilderWorkerThread::Run(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CMapBuilderWorkerThread::Run(CMapBuilderWorkerThread *this)
{
  CSimpleBSPFile *v2; // eax
  CSimpleBSPFile *v3; // edi
  CSimpleMapFile *v4; // edi
  char bspFilename[260]; // [esp+4h] [ebp-24Ch] BYREF
  char filename[260]; // [esp+108h] [ebp-148h] BYREF
  CUtlStreamBuffer outputBSPFile; // [esp+20Ch] [ebp-44h] BYREF
  CSimpleMapFile *pSimpleMapFile; // [esp+24Ch] [ebp-4h] BYREF

  CWorkerThread::WaitForCall(this, a2: nullptr);
  while ( CWorkerThread::GetCallParam(this) != 1 )
  {
    V_snprintf(pDest: filename, maxLen: 260, pFormat: "maps\\%s", this->m_pMapBuilder->m_szVBSP2MapName);
    _InterlockedExchange(&this->m_pMapBuilder->m_nVBSP2Progress.m_value, 1);
    CSimpleMapFile::LoadFromFile(
      pFileSystem: g_pFullFileSystem,
      pVMFFilename: filename,
      ppNewMapFile: &pSimpleMapFile,
      instanceFlags: NO_FLAGS);
    _InterlockedExchange(&this->m_pMapBuilder->m_nVBSP2Progress.m_value, 15);
    CSimpleMapFile::ResolveInstances(
      this: pSimpleMapFile,
      instanceFlags: CONVERT_STRUCTURAL_TO_DETAIL,
      pPostLoadInstanceHandler: (void (__cdecl *)(void *, CSimpleMapFile *, MapEntityKeyValuePair_t *, int))FixupInstance,
      pHandlerContext: this->m_pMapBuilder);
    _InterlockedExchange(&this->m_pMapBuilder->m_nVBSP2Progress.m_value, 30);
    V_strncpy(pDest: bspFilename, pSrc: filename, maxLen: 260);
    V_SetExtension(path: bspFilename, extension: ".bsp", pathStringLength: 260);
    CUtlStreamBuffer::CUtlStreamBuffer(
      this: &outputBSPFile,
      pFileName: bspFilename,
      pPath: nullptr,
      nFlags: 0,
      bDelayOpen: false,
      nOpenFileFlags: 0);
    v2 = (CSimpleBSPFile *)operator new(nSize: 0x1074u);
    if ( v2 != nullptr )
      v3 = CSimpleBSPFile::CSimpleBSPFile(this: v2);
    else
      v3 = nullptr;
    CSimpleBSPFile::CreateFromMapFile(this: v3, pMapFile: pSimpleMapFile);
    _InterlockedExchange(&this->m_pMapBuilder->m_nVBSP2Progress.m_value, 70);
    SaveToFile(pOutputBuffer: &outputBSPFile, pBSPFile: v3);
    CUtlStreamBuffer::Close(this: &outputBSPFile);
    if ( v3 != nullptr )
    {
      CSimpleBSPFile::~CSimpleBSPFile(this: v3);
      free(pMem: v3);
    }
    v4 = pSimpleMapFile;
    if ( pSimpleMapFile != nullptr )
    {
      CSimpleMapFile::~CSimpleMapFile(this: pSimpleMapFile);
      free(pMem: v4);
    }
    _InterlockedExchange(&this->m_pMapBuilder->m_nVBSP2Progress.m_value, 100);
    CWorkerThread::Reply(this, a2: 0);
    CUtlStreamBuffer::~CUtlStreamBuffer(this: &outputBSPFile);
    CWorkerThread::WaitForCall(this, a2: nullptr);
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1005237C
// Name: ?Start@CThread@@UAE_NIW4ThreadPriorityEnum_t@1@@Z_0
// Source: rtti_class
//------------------------------------------------------------------------------
// attributes: thunk
bool __thiscall CThread::Start(CThread *this, unsigned int a2, enum CThread::ThreadPriorityEnum_t a3)
{
  return __imp_?Start@CThread@@UAE_NIW4ThreadPriorityEnum_t@1@@Z(this, a2, a3);
}

//------------------------------------------------------------------------------
// Address: 0x10052382
// Name: ?Init@CThread@@MAE_NXZ_0
// Source: rtti_class
//------------------------------------------------------------------------------
// attributes: thunk
bool __thiscall CThread::Init(CThread *this)
{
  return __imp_?Init@CThread@@MAE_NXZ(this);
}

//------------------------------------------------------------------------------
// Address: 0x10052388
// Name: ?OnExit@CThread@@MAEXXZ_0
// Source: rtti_class
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall CThread::OnExit(CThread *this)
{
  __imp_?OnExit@CThread@@MAEXXZ(this);
}

//------------------------------------------------------------------------------
// Address: 0x1005238E
// Name: ?WaitForCreateComplete@CThread@@MAE_NPAVCThreadEvent@@@Z_0
// Source: rtti_class
//------------------------------------------------------------------------------
// attributes: thunk
bool __thiscall CThread::WaitForCreateComplete(CThread *this, struct CThreadEvent *a2)
{
  return __imp_?WaitForCreateComplete@CThread@@MAE_NPAVCThreadEvent@@@Z(this, a2);
}

//------------------------------------------------------------------------------
// Address: 0x10052394
// Name: ?GetThreadProc@CThread@@MAEP6GKPAX@ZXZ_0
// Source: rtti_class
//------------------------------------------------------------------------------
// attributes: thunk
unsigned int (__stdcall *__thiscall CThread::GetThreadProc(CThread *this))(void *)
{
  return __imp_?GetThreadProc@CThread@@MAEP6GKPAX@ZXZ(this);
}
