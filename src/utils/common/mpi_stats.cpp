// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/common/mpi_stats.cpp
// Functions: 25
// ============================================================

#include "utils\common\mpi_stats.h"

//------------------------------------------------------------------------------
// Address: 0x10012800
// Name: public: virtual int ISQLDBCommand::GetID(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall ISQLDBCommand::GetID(ConVar *this)
{
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10012810
// Name: public: virtual void ISQLDBCommand::GetDebugInfo(char __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ISQLDBCommand::GetDebugInfo(ISQLDBCommand *this, char *buf, int bufSize)
{
  *buf = 0;
}

//------------------------------------------------------------------------------
// Address: 0x10012820
// Name: char __near * FormatStringForSQL(char const __near *)
// Source: json
//------------------------------------------------------------------------------
char *__cdecl FormatStringForSQL(const char *pText)
{
  const char *v1; // edi
  char v2; // al
  int v3; // esi
  const char *i; // ecx
  char *result; // eax
  int v6; // ecx

  v1 = pText;
  v2 = *pText;
  v3 = 0;
  for ( i = pText; v2 != 0; ++v3 )
  {
    if ( v2 == 34 || v2 == 92 )
      ++v3;
    v2 = *++i;
  }
  result = (char *)MemAlloc_Alloc(nSize: v3 + 1);
  v6 = 0;
  if ( v3 <= 0 )
  {
    result[v3] = 0;
  }
  else
  {
    do
    {
      if ( *v1 == 34 || *v1 == 92 )
        result[v6++] = 92;
      result[v6++] = *v1++;
    }
    while ( v6 < v3 );
    result[v3] = 0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10012890
// Name: void VMPI_Stats_InstallSpewHook(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl VMPI_Stats_InstallSpewHook()
{
  _LoggingSystem_RegisterLoggingListener(a1: &g_VMPIStatsLoggingListener);
}

//------------------------------------------------------------------------------
// Address: 0x100128A0
// Name: void UnloadMySQLWrapper(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl UnloadMySQLWrapper()
{
  if ( g_hMySQLDLL != nullptr )
  {
    if ( g_pSQL != nullptr )
    {
      g_pSQL->Release(this: g_pSQL);
      g_pSQL = nullptr;
    }
    Sys_UnloadModule(pModule: g_hMySQLDLL);
    g_hMySQLDLL = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100128E0
// Name: bool LoadMySQLWrapper(char const __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl LoadMySQLWrapper(const char *pHostName, const char *pDBName, const char *pUserName)
{
  if ( g_hMySQLDLL != nullptr )
  {
    if ( g_pSQL != nullptr )
    {
      g_pSQL->Release(this: g_pSQL);
      g_pSQL = nullptr;
    }
    Sys_UnloadModule(pModule: g_hMySQLDLL);
    g_hMySQLDLL = nullptr;
  }
  if ( !Sys_LoadInterface(
          pModuleName: "mysql_wrapper",
          pInterfaceVersionName: "MySQLWrapper001",
          pOutModule: &g_hMySQLDLL,
          pOutInterface: (void **)&g_pSQL) )
    return 0;
  if ( !g_pSQL->InitMySQL(this: g_pSQL, a2: pDBName, a3: pHostName, a4: pUserName, a5: defaultValue) )
  {
    UnloadMySQLWrapper();
    return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10012970
// Name: ReadStringFromFile
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl ReadStringFromFile(_iobuf *fp, char *pStr, int strSize)
{
  int i; // esi

  for ( i = 0; i < strSize - 2; ++i )
  {
    if ( fread(buffer: &pStr[i], elementSize: 1u, count: 1u, stream: fp) != 1 )
      break;
    if ( pStr[i] == 10 )
      break;
  }
  pStr[i] = 0;
  return i != 0;
}

//------------------------------------------------------------------------------
// Address: 0x100129C0
// Name: void GetDBInfo(char const __near *,class CDBInfo __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GetDBInfo(const char *pDBInfoFilename, CDBInfo *pInfo)
{
  HMODULE ModuleHandleA; // eax
  _iobuf *v3; // esi
  char baseExeFilename[512]; // [esp+Ch] [ebp-400h] BYREF
  char dbInfoFilename[512]; // [esp+20Ch] [ebp-200h] BYREF

  ModuleHandleA = GetModuleHandleA(lpModuleName: nullptr);
  if ( GetModuleFileNameA(hModule: ModuleHandleA, lpFilename: baseExeFilename, nSize: 0x200u) == 0 )
    _Error(a1: "GetModuleFileName failed.");
  V_strncpy(pDest: dbInfoFilename, pSrc: baseExeFilename, maxLen: 512);
  V_StripFilename(path: dbInfoFilename);
  if ( dbInfoFilename[0] == 0 )
    V_strncpy(pDest: dbInfoFilename, pSrc: ".", maxLen: 512);
  V_strncat(pDest: dbInfoFilename, pSrc: "/", destBufferSize: 0x200u, max_chars_to_copy: -1);
  V_strncat(pDest: dbInfoFilename, pSrc: pDBInfoFilename, destBufferSize: 0x200u, max_chars_to_copy: -1);
  v3 = fopen(file: dbInfoFilename, mode: "rt");
  if ( v3 == nullptr )
    _Error(a1: "Can't open %s for database info.\n", dbInfoFilename);
  if ( !ReadStringFromFile(fp: v3, pStr: pInfo->m_HostName, strSize: 128)
    || !ReadStringFromFile(fp: v3, pStr: pInfo->m_DBName, strSize: 128)
    || !ReadStringFromFile(fp: v3, pStr: pInfo->m_UserName, strSize: 128) )
  {
    _Error(a1: "%s is not a valid database info file.\n", dbInfoFilename);
  }
  fclose(stream: v3);
}

//------------------------------------------------------------------------------
// Address: 0x10012B10
// Name: void RunJobWatchApp(char __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl RunJobWatchApp(char *pCmdLine)
{
  char *v1; // esi
  char *v2; // eax
  const char *ParamString; // eax
  char dirName[512]; // [esp+0h] [ebp-254h] BYREF
  _STARTUPINFOA StartupInfo; // [esp+200h] [ebp-54h] BYREF
  _PROCESS_INFORMATION pi; // [esp+244h] [ebp-10h] BYREF

  memset(dst: (unsigned __int8 *)&StartupInfo, value: 0, count: sizeof(StartupInfo));
  StartupInfo.cb = 68;
  memset(&pi, 0, sizeof(pi));
  if ( GetModuleFileNameA(hModule: nullptr, lpFilename: dirName, nSize: 0x200u) != 0 )
  {
    v1 = _V_strrchr(s: dirName, c: 92);
    v2 = _V_strrchr(s: dirName, c: 47);
    if ( v1 != nullptr )
    {
      if ( v1 > v2 )
        goto LABEL_7;
    }
    else if ( v2 == nullptr )
    {
      return;
    }
    v1 = v2;
LABEL_7:
    *v1 = 0;
    if ( !CreateProcessA(
            lpApplicationName: nullptr,
            lpCommandLine: pCmdLine,
            lpProcessAttributes: nullptr,
            lpThreadAttributes: nullptr,
            bInheritHandles: true,
            dwCreationFlags: 0,
            lpEnvironment: nullptr,
            lpCurrentDirectory: dirName,
            lpStartupInfo: &StartupInfo,
            lpProcessInformation: &pi) )
    {
      ParamString = VMPI_GetParamString(eParam: mpi_Job_Watch);
      _Warning(a1: "%s - error launching '%s'\n", ParamString, pCmdLine);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10012BE0
// Name: public: virtual void CSQLDBCommandBase::deleteThis(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSQLDBCommandBase::deleteThis(CSQLDBCommandBase *this)
{
  if ( this != nullptr )
    ((void (__thiscall *)(CSQLDBCommandBase *, int))this->dtr_ISQLDBCommand)(a1: this, a2: 1);
}

//------------------------------------------------------------------------------
// Address: 0x10012C30
// Name: public: virtual int CSQLDBCommand_WorkerStats::RunCommand(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CSQLDBCommand_WorkerStats::RunCommand(CSQLDBCommand_WorkerStats *this)
{
  int CurrentNumberOfConnections; // edi
  int v2; // esi
  bool IsProcConnected; // al
  int NumWorkUnitsCompleted; // [esp-8h] [ebp-810h]
  unsigned int JobWorkerID; // [esp-4h] [ebp-80Ch]
  char query[2048]; // [esp+8h] [ebp-800h] BYREF

  CurrentNumberOfConnections = VMPI_GetCurrentNumberOfConnections();
  V_snprintf(
    pDest: query,
    maxLen: 2048,
    pFormat: "update job_master_start set NumWorkers=%d where JobID=%lu",
    CurrentNumberOfConnections,
    g_JobPrimaryID);
  g_pSQL->Execute(this: g_pSQL, a2: query);
  v2 = 1;
  if ( CurrentNumberOfConnections <= 1 )
    return 1;
  do
  {
    if ( VMPI_GetJobWorkerID(iProc: v2) != -1 )
    {
      JobWorkerID = VMPI_GetJobWorkerID(iProc: v2);
      NumWorkUnitsCompleted = VMPI_GetNumWorkUnitsCompleted(iProc: v2);
      IsProcConnected = VMPI_IsProcConnected(procID: v2);
      V_snprintf(
        pDest: query,
        maxLen: 2048,
        pFormat: "update job_worker_start set WorkerState=%d, NumWorkUnits=%d where JobWorkerID=%lu",
        IsProcConnected,
        NumWorkUnitsCompleted,
        JobWorkerID);
      g_pSQL->Execute(this: g_pSQL, a2: query);
    }
    ++v2;
  }
  while ( v2 < CurrentNumberOfConnections );
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10012D30
// Name: void PerfThread_AddGraphEntry(unsigned long,unsigned long __near &,unsigned long __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl PerfThread_AddGraphEntry(unsigned int startTicks, unsigned int *lastSent, unsigned int *lastReceived)
{
  int v3; // ebx
  int v4; // edi
  ISQLDBCommand *v5; // esi
  ISQLDBCommand_vtbl *v6; // edi
  ISQLDBCommand_vtbl *v7; // ebx
  DWORD TickCount; // eax
  unsigned int curSent; // [esp+Ch] [ebp-8h]
  unsigned int curReceived; // [esp+10h] [ebp-4h]

  v3 = g_nBytesSent + g_nMulticastBytesSent;
  v4 = g_nBytesReceived + g_nMulticastBytesReceived;
  curSent = g_nBytesSent + g_nMulticastBytesSent;
  curReceived = g_nBytesReceived + g_nMulticastBytesReceived;
  v5 = (ISQLDBCommand *)MemAlloc_Alloc(nSize: 0x10u);
  if ( v5 != nullptr )
  {
    v6 = (ISQLDBCommand_vtbl *)(v4 - *lastReceived);
    v7 = (ISQLDBCommand_vtbl *)(v3 - *lastSent);
    TickCount = GetTickCount();
    v5[1].__vftable = v7;
    v3 = curSent;
    v5[2].__vftable = v6;
    v4 = curReceived;
    v5->__vftable = (ISQLDBCommand_vtbl *)&CSQLDBCommand_GraphEntry::`vftable';
    v5[3].__vftable = (ISQLDBCommand_vtbl *)(TickCount - startTicks);
  }
  else
  {
    v5 = nullptr;
  }
  CMySqlDatabase::AddCommandToQueue(this: g_pDB, cmd: v5, replyTarget: nullptr, returnState: 0);
  *lastSent = v3;
  *lastReceived = v4;
}

//------------------------------------------------------------------------------
// Address: 0x10012DC0
// Name: void VMPI_Stats_Term(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl VMPI_Stats_Term()
{
  ISQLDBCommand *v0; // eax
  DWORD TickCount; // edi
  CMySqlDatabase *v2; // esi

  if ( g_pDB != nullptr )
  {
    SetEvent(hEvent: g_hPerfThreadExitEvent);
    WaitForSingleObject(hHandle: g_hPerfThread, dwMilliseconds: 0xFFFFFFFF);
    CloseHandle(hObject: g_hPerfThreadExitEvent);
    g_hPerfThreadExitEvent = nullptr;
    CloseHandle(hObject: g_hPerfThread);
    g_hPerfThread = nullptr;
    if ( g_bMaster )
    {
      v0 = (ISQLDBCommand *)MemAlloc_Alloc(nSize: 4u);
      if ( v0 != nullptr )
        v0->__vftable = (ISQLDBCommand_vtbl *)&CSQLDBCommand_JobMasterEnd::`vftable';
      else
        v0 = nullptr;
      CMySqlDatabase::AddCommandToQueue(this: g_pDB, cmd: v0, replyTarget: nullptr, returnState: 0);
    }
    TickCount = GetTickCount();
    if ( GetTickCount() - TickCount < 0x3E8 )
    {
      while ( g_pDB->QueriesInOutQueue(this: g_pDB) != 0 && GetTickCount() - TickCount < 0x3E8 )
        ;
    }
    v2 = g_pDB;
    if ( g_pDB != nullptr )
    {
      CMySqlDatabase::~CMySqlDatabase(this: g_pDB);
      free(pMem: v2);
    }
    g_pDB = nullptr;
    if ( g_hMySQLDLL != nullptr )
    {
      if ( g_pSQL != nullptr )
      {
        g_pSQL->Release(this: g_pSQL);
        g_pSQL = nullptr;
      }
      Sys_UnloadModule(pModule: g_hMySQLDLL);
      g_hMySQLDLL = nullptr;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10012F60
// Name: public: int CMySQLQuery::Execute(class IMySQL __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CMySQLQuery::Execute(CMySQLQuery *this, IMySQL *pDB)
{
  int v3; // eax
  bool v4; // sf
  int v5; // ebx

  v3 = pDB->Execute(this: pDB, a2: this->m_QueryText.m_Memory.m_pMemory);
  v4 = this->m_QueryText.m_Memory.m_nGrowSize < 0;
  v5 = v3;
  this->m_QueryText.m_Size = 0;
  if ( !v4 )
  {
    if ( this->m_QueryText.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_QueryText.m_Memory.m_pMemory);
      this->m_QueryText.m_Memory.m_pMemory = nullptr;
    }
    this->m_QueryText.m_Memory.m_nAllocationCount = 0;
  }
  this->m_QueryText.m_pElements = this->m_QueryText.m_Memory.m_pMemory;
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x10012FC0
// Name: public: virtual void CLoggingListener_VMPIStats::Log(struct LoggingContext_t const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLoggingListener_VMPIStats::Log(
        CLoggingListener_VMPIStats *this,
        const LoggingContext_t *pContext,
        const char *pMessage)
{
  CCriticalSectionLock csLock; // [esp+4h] [ebp-8h] BYREF

  CCriticalSectionLock::CCriticalSectionLock(this: &csLock, pCS: &g_SpewTextCS);
  CCriticalSectionLock::Lock(this: &csLock);
  CUtlVector<char,CUtlMemory<char,int>>::InsertMultipleBefore(
    this: &g_SpewText,
    elem: g_SpewText.m_Size,
    num: strlen(pMessage),
    pToInsert: pMessage);
  CCriticalSectionLock::Unlock(this: &csLock);
  CCriticalSectionLock::~CCriticalSectionLock(this: &csLock);
}

//------------------------------------------------------------------------------
// Address: 0x10013020
// Name: void PerfThread_SendSpewText(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl PerfThread_SendSpewText()
{
  int m_Size; // eax
  int v1; // esi
  char *m_pMemory; // ecx
  int v3; // eax
  ISQLDBCommand *v4; // esi
  const char *ParamString; // eax
  ISQLDBCommand *v6; // eax
  char *v7; // [esp-8h] [ebp-210h]
  char msg[512]; // [esp+0h] [ebp-208h] BYREF
  CCriticalSectionLock csLock; // [esp+200h] [ebp-8h] BYREF

  CCriticalSectionLock::CCriticalSectionLock(this: &csLock, pCS: &g_SpewTextCS);
  CCriticalSectionLock::Lock(this: &csLock);
  m_Size = g_SpewText.m_Size;
  if ( g_SpewText.m_Size > 0 )
  {
    v1 = g_SpewText.m_Size;
    if ( g_SpewText.m_Size + 1 > g_SpewText.m_Memory.m_nAllocationCount )
    {
      CUtlMemory<char,int>::Grow(
        this: (CUtlMemory<unsigned char,int> *)&g_SpewText,
        num: g_SpewText.m_Size - g_SpewText.m_Memory.m_nAllocationCount + 1);
      m_Size = g_SpewText.m_Size;
    }
    m_pMemory = g_SpewText.m_Memory.m_pMemory;
    g_SpewText.m_Size = m_Size + 1;
    v3 = m_Size - v1;
    g_SpewText.m_pElements = g_SpewText.m_Memory.m_pMemory;
    if ( v3 > 0 )
    {
      _V_memmove(dest: &g_SpewText.m_Memory.m_pMemory[v1 + 1], src: &g_SpewText.m_Memory.m_pMemory[v1], count: v3);
      m_pMemory = g_SpewText.m_Memory.m_pMemory;
    }
    if ( &m_pMemory[v1] != nullptr )
      m_pMemory[v1] = 0;
    if ( g_bMPI_StatsTextOutput )
    {
      v4 = (ISQLDBCommand *)MemAlloc_Alloc(nSize: 8u);
      if ( v4 != nullptr )
      {
        v7 = g_SpewText.m_Memory.m_pMemory;
        v4->__vftable = (ISQLDBCommand_vtbl *)&CSQLDBCommand_TextMessage::`vftable';
        v4[1].__vftable = (ISQLDBCommand_vtbl *)FormatStringForSQL(pText: v7);
LABEL_15:
        CMySqlDatabase::AddCommandToQueue(this: g_pDB, cmd: v4, replyTarget: nullptr, returnState: 0);
        goto LABEL_16;
      }
    }
    else
    {
      if ( !bFirst )
      {
LABEL_16:
        g_SpewText.m_Size = 0;
        goto LABEL_17;
      }
      ParamString = VMPI_GetParamString(eParam: mpi_Stats_TextOutput);
      V_snprintf(pDest: msg, maxLen: 512, pFormat: "%s not enabled", ParamString);
      bFirst = false;
      v6 = (ISQLDBCommand *)MemAlloc_Alloc(nSize: 8u);
      v4 = v6;
      if ( v6 != nullptr )
      {
        v6->__vftable = (ISQLDBCommand_vtbl *)&CSQLDBCommand_TextMessage::`vftable';
        v6[1].__vftable = (ISQLDBCommand_vtbl *)FormatStringForSQL(pText: msg);
        goto LABEL_15;
      }
    }
    v4 = nullptr;
    goto LABEL_15;
  }
LABEL_17:
  CCriticalSectionLock::Unlock(this: &csLock);
  CCriticalSectionLock::~CCriticalSectionLock(this: &csLock);
}

//------------------------------------------------------------------------------
// Address: 0x10013160
// Name: unsigned long PerfThreadFn(void __near *)
// Source: json
//------------------------------------------------------------------------------
unsigned int __stdcall PerfThreadFn(void *pParameter)
{
  unsigned int v1; // edi
  unsigned int v2; // ebx
  ISQLDBCommand *v3; // esi
  DWORD TickCount; // eax
  ISQLDBCommand_vtbl *v5; // edx
  ISQLDBCommand_vtbl *v6; // eax
  ISQLDBCommand *v7; // eax
  DWORD startTicks; // [esp+0h] [ebp-Ch]
  unsigned int lastSent; // [esp+4h] [ebp-8h] BYREF
  unsigned int lastReceived; // [esp+8h] [ebp-4h] BYREF

  lastSent = 0;
  lastReceived = 0;
  startTicks = GetTickCount();
  while ( WaitForSingleObject(hHandle: g_hPerfThreadExitEvent, dwMilliseconds: 0x3E8u) != 0 )
  {
    v1 = g_nBytesSent + g_nMulticastBytesSent;
    v2 = g_nBytesReceived + g_nMulticastBytesReceived;
    v3 = (ISQLDBCommand *)MemAlloc_Alloc(nSize: 0x10u);
    if ( v3 != nullptr )
    {
      TickCount = GetTickCount();
      v5 = (ISQLDBCommand_vtbl *)(v1 - lastSent);
      v3[3].__vftable = (ISQLDBCommand_vtbl *)(TickCount - startTicks);
      v6 = (ISQLDBCommand_vtbl *)(v2 - lastReceived);
      v3->__vftable = (ISQLDBCommand_vtbl *)&CSQLDBCommand_GraphEntry::`vftable';
      v3[1].__vftable = v5;
      v3[2].__vftable = v6;
    }
    else
    {
      v3 = nullptr;
    }
    CMySqlDatabase::AddCommandToQueue(this: g_pDB, cmd: v3, replyTarget: nullptr, returnState: 0);
    lastSent = v1;
    lastReceived = v2;
    PerfThread_SendSpewText();
    if ( g_bMaster )
    {
      v7 = (ISQLDBCommand *)MemAlloc_Alloc(nSize: 4u);
      if ( v7 != nullptr )
        v7->__vftable = (ISQLDBCommand_vtbl *)&CSQLDBCommand_WorkerStats::`vftable';
      else
        v7 = nullptr;
      CMySqlDatabase::AddCommandToQueue(this: g_pDB, cmd: v7, replyTarget: nullptr, returnState: 0);
    }
  }
  PerfThread_SendSpewText();
  PerfThread_AddGraphEntry(startTicks, &lastSent, &lastReceived);
  SetEvent(hEvent: g_hPerfThreadExitEvent);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10013280
// Name: public: void CMySQLQuery::Format(char const __near *,...)
// Source: json
//------------------------------------------------------------------------------
void CMySQLQuery::Format(CMySQLQuery *this, const char *pFormat, ...)
{
  int m_nAllocationCount; // eax
  char *m_pMemory; // eax
  int v4; // ecx
  int m_Size; // edi
  bool v6; // zf
  int v7; // edi
  int v8; // eax
  char *v9; // ecx
  int v10; // eax
  va_list ap; // [esp+18h] [ebp+10h] BYREF

  va_start(ap, pFormat);
  m_nAllocationCount = this->m_QueryText.m_Memory.m_nAllocationCount;
  this->m_QueryText.m_Size = 0;
  if ( m_nAllocationCount < 1024 )
    CUtlMemory<char,int>::Grow((CUtlMemory<unsigned char,int> *)this, num: 1024 - m_nAllocationCount);
  this->m_QueryText.m_Size += 1024;
  m_pMemory = this->m_QueryText.m_Memory.m_pMemory;
  v4 = this->m_QueryText.m_Size - 1024;
  this->m_QueryText.m_pElements = this->m_QueryText.m_Memory.m_pMemory;
  if ( v4 > 0 )
    _V_memmove(dest: m_pMemory + 1024, src: m_pMemory, count: v4);
  while ( _vsnprintf(string: this->m_QueryText.m_Memory.m_pMemory, count: this->m_QueryText.m_Size, format: pFormat, ap) < 0 )
  {
    m_Size = this->m_QueryText.m_Size;
    v6 = m_Size == -1024;
    v7 = m_Size + 1024;
    this->m_QueryText.m_Size = 0;
    if ( !v6 )
    {
      v8 = this->m_QueryText.m_Memory.m_nAllocationCount;
      if ( v7 > v8 )
        CUtlMemory<char,int>::Grow((CUtlMemory<unsigned char,int> *)this, num: v7 - v8);
      this->m_QueryText.m_Size += v7;
      v9 = this->m_QueryText.m_Memory.m_pMemory;
      v10 = this->m_QueryText.m_Size - v7;
      this->m_QueryText.m_pElements = this->m_QueryText.m_Memory.m_pMemory;
      if ( v10 > 0 && v7 > 0 )
        _V_memmove(dest: &v9[v7], src: v9, count: v10);
    }
  }
  this->m_QueryText.m_Memory.m_pMemory[this->m_QueryText.m_Size - 1] = 0;
}

//------------------------------------------------------------------------------
// Address: 0x10013360
// Name: public: virtual int CSQLDBCommand_JobMasterEnd::RunCommand(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CSQLDBCommand_JobMasterEnd::RunCommand(CSQLDBCommand_JobMasterEnd *this)
{
  char *m_pMemory; // esi
  DWORD TickCount; // eax
  char *v3; // esi
  CMySQLQuery query; // [esp+8h] [ebp-14h] BYREF

  memset(&query, 0, sizeof(query));
  CMySQLQuery::Format(
    this: &query,
    pFormat: "insert into job_master_end values ( %lu, %d, %d, \"no errors\" )",
    g_JobPrimaryID,
    g_nWorkersConnected,
    g_nWorkersDisconnected);
  m_pMemory = query.m_QueryText.m_Memory.m_pMemory;
  g_pSQL->Execute(this: g_pSQL, a2: query.m_QueryText.m_Memory.m_pMemory);
  query.m_QueryText.m_Size = 0;
  if ( query.m_QueryText.m_Memory.m_nGrowSize >= 0 )
  {
    if ( m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
      m_pMemory = nullptr;
      query.m_QueryText.m_Memory.m_pMemory = nullptr;
    }
    query.m_QueryText.m_Memory.m_nAllocationCount = 0;
  }
  query.m_QueryText.m_pElements = m_pMemory;
  TickCount = GetTickCount();
  CMySQLQuery::Format(
    this: &query,
    pFormat: "update job_master_start set RunningTimeMS=%lu where JobID=%lu",
    TickCount - g_StatsStartTime,
    g_JobPrimaryID);
  v3 = query.m_QueryText.m_Memory.m_pMemory;
  g_pSQL->Execute(this: g_pSQL, a2: query.m_QueryText.m_Memory.m_pMemory);
  query.m_QueryText.m_Size = 0;
  if ( query.m_QueryText.m_Memory.m_nGrowSize >= 0 )
  {
    if ( v3 != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v3);
      v3 = nullptr;
      query.m_QueryText.m_Memory.m_pMemory = nullptr;
    }
    query.m_QueryText.m_Memory.m_nAllocationCount = 0;
  }
  query.m_QueryText.m_pElements = v3;
  CUtlVector<dleafambientlighting_t,CUtlMemory<dleafambientlighting_t,int>>::~CUtlVector<dleafambientlighting_t,CUtlMemory<dleafambientlighting_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&query);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10013450
// Name: void UpdateJobWorkerRunningTime(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl UpdateJobWorkerRunningTime()
{
  DWORD v0; // esi
  char *m_pMemory; // esi
  char curStage[256]; // [esp+8h] [ebp-114h] BYREF
  CMySQLQuery query; // [esp+108h] [ebp-14h] BYREF

  v0 = GetTickCount() - g_StatsStartTime;
  VMPI_GetCurrentStage(pOut: curStage, strLen: 256);
  memset(&query, 0, sizeof(query));
  CMySQLQuery::Format(
    this: &query,
    pFormat: "update job_worker_start set RunningTimeMS=%lu, CurrentStage=\"%s\", Thread0WU=%d, Thread1WU=%d, Thread2WU=%d, Thread"
    "3WU=%d where JobWorkerID=%lu",
    v0,
    curStage,
    LODWORD(g_ThreadWUs[0]),
    dword_10137360,
    dword_10137368,
    dword_10137370,
    g_JobWorkerID);
  m_pMemory = query.m_QueryText.m_Memory.m_pMemory;
  g_pSQL->Execute(this: g_pSQL, a2: query.m_QueryText.m_Memory.m_pMemory);
  query.m_QueryText.m_Size = 0;
  if ( query.m_QueryText.m_Memory.m_nGrowSize >= 0 )
  {
    if ( m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
      m_pMemory = nullptr;
      query.m_QueryText.m_Memory.m_pMemory = nullptr;
    }
    query.m_QueryText.m_Memory.m_nAllocationCount = 0;
  }
  query.m_QueryText.m_pElements = m_pMemory;
  CUtlVector<dleafambientlighting_t,CUtlMemory<dleafambientlighting_t,int>>::~CUtlVector<dleafambientlighting_t,CUtlMemory<dleafambientlighting_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&query);
}

//------------------------------------------------------------------------------
// Address: 0x10013510
// Name: public: virtual int CSQLDBCommand_GraphEntry::RunCommand(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CSQLDBCommand_GraphEntry::RunCommand(CSQLDBCommand_GraphEntry *this)
{
  char *m_pMemory; // esi
  unsigned int m_msTime; // [esp-Ch] [ebp-28h]
  unsigned int m_nBytesSent; // [esp-8h] [ebp-24h]
  unsigned int m_nBytesReceived; // [esp-4h] [ebp-20h]
  CMySQLQuery query; // [esp+8h] [ebp-14h] BYREF

  m_nBytesReceived = this->m_nBytesReceived;
  m_nBytesSent = this->m_nBytesSent;
  m_msTime = this->m_msTime;
  memset(&query, 0, sizeof(query));
  CMySQLQuery::Format(
    this: &query,
    pFormat: "insert into graph_entry (JobWorkerID, MSSinceJobStart, BytesSent, BytesReceived) values ( %lu, %lu, %lu, %lu )",
    g_JobWorkerID,
    m_msTime,
    m_nBytesSent,
    m_nBytesReceived);
  m_pMemory = query.m_QueryText.m_Memory.m_pMemory;
  g_pSQL->Execute(this: g_pSQL, a2: query.m_QueryText.m_Memory.m_pMemory);
  query.m_QueryText.m_Size = 0;
  if ( query.m_QueryText.m_Memory.m_nGrowSize >= 0 )
  {
    if ( m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
      m_pMemory = nullptr;
      query.m_QueryText.m_Memory.m_pMemory = nullptr;
    }
    query.m_QueryText.m_Memory.m_nAllocationCount = 0;
  }
  query.m_QueryText.m_pElements = m_pMemory;
  UpdateJobWorkerRunningTime();
  ++g_CurrentMessageIndex;
  CUtlVector<dleafambientlighting_t,CUtlMemory<dleafambientlighting_t,int>>::~CUtlVector<dleafambientlighting_t,CUtlMemory<dleafambientlighting_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&query);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100135B0
// Name: public: virtual int CSQLDBCommand_TextMessage::RunCommand(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CSQLDBCommand_TextMessage::RunCommand(CSQLDBCommand_TextMessage *this)
{
  char *m_pMemory; // esi
  char *m_pText; // [esp-4h] [ebp-20h]
  CMySQLQuery query; // [esp+8h] [ebp-14h] BYREF

  m_pText = this->m_pText;
  memset(&query, 0, sizeof(query));
  CMySQLQuery::Format(
    this: &query,
    pFormat: "insert into text_messages (JobWorkerID, MessageIndex, Text) values ( %lu, %lu, \"%s\" )",
    g_JobWorkerID,
    g_CurrentMessageIndex,
    m_pText);
  m_pMemory = query.m_QueryText.m_Memory.m_pMemory;
  g_pSQL->Execute(this: g_pSQL, a2: query.m_QueryText.m_Memory.m_pMemory);
  query.m_QueryText.m_Size = 0;
  if ( query.m_QueryText.m_Memory.m_nGrowSize >= 0 )
  {
    if ( m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
      m_pMemory = nullptr;
      query.m_QueryText.m_Memory.m_pMemory = nullptr;
    }
    query.m_QueryText.m_Memory.m_nAllocationCount = 0;
  }
  ++g_CurrentMessageIndex;
  query.m_QueryText.m_pElements = m_pMemory;
  CUtlVector<dleafambientlighting_t,CUtlMemory<dleafambientlighting_t,int>>::~CUtlVector<dleafambientlighting_t,CUtlMemory<dleafambientlighting_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&query);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10013640
// Name: bool VMPI_Stats_Init_Worker(char const __near *,char const __near *,char const __near *,unsigned long)
// Source: json
//------------------------------------------------------------------------------
char __cdecl VMPI_Stats_Init_Worker(
        unsigned int pHostName,
        const char *pDBName,
        const char *pUserName,
        unsigned int DBJobID)
{
  DWORD TickCount; // eax
  const char *v5; // esi
  CMySqlDatabase *v6; // eax
  CMySqlDatabase *v7; // ecx
  char *m_pMemory; // esi
  unsigned int (__thiscall *InsertID)(IMySQL *); // eax
  CMySqlDatabase *v10; // esi
  CMySqlDatabase *v12; // esi
  CMySQLQuery query; // [esp+8h] [ebp-14h] BYREF

  TickCount = GetTickCount();
  v5 = (const char *)pHostName;
  g_StatsStartTime = TickCount;
  if ( pHostName == 0 )
    goto LABEL_7;
  v6 = (CMySqlDatabase *)MemAlloc_Alloc(nSize: 0xBCu);
  if ( v6 != nullptr )
  {
    v7 = CMySqlDatabase::CMySqlDatabase(this: v6);
    g_pDB = v7;
    if ( v7 != nullptr )
    {
      if ( CMySqlDatabase::Initialize(this: v7) && LoadMySQLWrapper(pHostName: v5, pDBName, pUserName) != 0 )
      {
        pHostName = 16;
        GetComputerNameA(lpBuffer: g_MachineName, nSize: &pHostName);
LABEL_7:
        g_JobPrimaryID = DBJobID;
        g_JobWorkerID = 0;
        memset(&query, 0, sizeof(query));
        CMySQLQuery::Format(
          this: &query,
          pFormat: "insert into job_worker_start ( JobID, CurrentStage, IsMaster, MachineName ) values ( %lu, \"none\", %d, \"%s\" )",
          DBJobID,
          g_bMaster,
          g_MachineName);
        m_pMemory = query.m_QueryText.m_Memory.m_pMemory;
        g_pSQL->Execute(this: g_pSQL, a2: query.m_QueryText.m_Memory.m_pMemory);
        query.m_QueryText.m_Size = 0;
        if ( query.m_QueryText.m_Memory.m_nGrowSize >= 0 )
        {
          if ( m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
            m_pMemory = nullptr;
            query.m_QueryText.m_Memory.m_pMemory = nullptr;
          }
          query.m_QueryText.m_Memory.m_nAllocationCount = 0;
        }
        InsertID = g_pSQL->InsertID;
        query.m_QueryText.m_pElements = m_pMemory;
        g_JobWorkerID = InsertID(this: g_pSQL);
        if ( g_JobWorkerID != 0 )
        {
          g_hPerfThreadExitEvent = CreateEventA(
                                     lpEventAttributes: nullptr,
                                     bManualReset: false,
                                     bInitialState: false,
                                     lpName: nullptr);
          g_hPerfThread = CreateThread(
                            lpThreadAttributes: nullptr,
                            dwStackSize: 0,
                            lpStartAddress: PerfThreadFn,
                            lpParameter: nullptr,
                            dwCreationFlags: 0,
                            lpThreadId: &g_PerfThreadID);
          CUtlVector<dleafambientlighting_t,CUtlMemory<dleafambientlighting_t,int>>::~CUtlVector<dleafambientlighting_t,CUtlMemory<dleafambientlighting_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&query);
          return 1;
        }
        else
        {
          v10 = g_pDB;
          if ( g_pDB != nullptr )
          {
            CMySqlDatabase::~CMySqlDatabase(this: g_pDB);
            free(pMem: v10);
          }
          g_pDB = nullptr;
          CUtlVector<dleafambientlighting_t,CUtlMemory<dleafambientlighting_t,int>>::~CUtlVector<dleafambientlighting_t,CUtlMemory<dleafambientlighting_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&query);
          return 0;
        }
      }
      v7 = g_pDB;
    }
  }
  else
  {
    v7 = nullptr;
    g_pDB = nullptr;
  }
  v12 = v7;
  if ( v7 != nullptr )
  {
    CMySqlDatabase::~CMySqlDatabase(this: v7);
    free(pMem: v12);
  }
  g_pDB = nullptr;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x100137F0
// Name: bool VMPI_Stats_Init_Master(char const __near *,char const __near *,char const __near *,char const __near *,unsigned long __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl VMPI_Stats_Init_Master(
        const char *pHostName,
        const char *pDBName,
        const char *pUserName,
        const char *pBSPFilename,
        unsigned int *pDBJobID)
{
  CMySqlDatabase *v5; // eax
  CMySqlDatabase *v6; // ecx
  unsigned int v7; // eax
  CMySqlDatabase *v8; // edi
  char inited; // bl
  CMySqlDatabase *v11; // edi
  CMySQLQuery query; // [esp+8h] [ebp-18h] BYREF
  unsigned int size; // [esp+1Ch] [ebp-4h] BYREF

  g_bMaster = true;
  v5 = (CMySqlDatabase *)MemAlloc_Alloc(nSize: 0xBCu);
  if ( v5 != nullptr )
  {
    v6 = CMySqlDatabase::CMySqlDatabase(this: v5);
    g_pDB = v6;
    if ( v6 != nullptr )
    {
      if ( CMySqlDatabase::Initialize(this: v6) && LoadMySQLWrapper(pHostName, pDBName, pUserName) != 0 )
      {
        size = 16;
        GetComputerNameA(lpBuffer: g_MachineName, nSize: &size);
        V_FileBase(in: pBSPFilename, out: g_BSPFilename, maxlen: 256);
        g_JobPrimaryID = 0;
        memset(&query, 0, sizeof(query));
        CMySQLQuery::Format(
          this: &query,
          pFormat: "insert into job_master_start ( BSPFilename, StartTime, MachineName, RunningTimeMS ) values ( \"%s\", null, \"%s\", %lu )",
          g_BSPFilename,
          g_MachineName,
          -19088643);
        CMySQLQuery::Execute(this: &query, pDB: g_pSQL);
        v7 = g_pSQL->InsertID(this: g_pSQL);
        g_JobPrimaryID = v7;
        if ( v7 != 0 )
        {
          *pDBJobID = v7;
          inited = VMPI_Stats_Init_Worker(pHostName: 0, pDBName: nullptr, pUserName: nullptr, DBJobID: g_JobPrimaryID);
          CUtlVector<dleafambientlighting_t,CUtlMemory<dleafambientlighting_t,int>>::~CUtlVector<dleafambientlighting_t,CUtlMemory<dleafambientlighting_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&query);
          return inited;
        }
        else
        {
          v8 = g_pDB;
          if ( g_pDB != nullptr )
          {
            CMySqlDatabase::~CMySqlDatabase(this: g_pDB);
            free(pMem: v8);
          }
          g_pDB = nullptr;
          CUtlVector<dleafambientlighting_t,CUtlMemory<dleafambientlighting_t,int>>::~CUtlVector<dleafambientlighting_t,CUtlMemory<dleafambientlighting_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&query);
          return 0;
        }
      }
      v6 = g_pDB;
    }
  }
  else
  {
    v6 = nullptr;
    g_pDB = nullptr;
  }
  v11 = v6;
  if ( v6 != nullptr )
  {
    CMySqlDatabase::~CMySqlDatabase(this: v6);
    free(pMem: v11);
  }
  g_pDB = nullptr;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10013970
// Name: void StatsDB_InitStatsDatabase(int,char __near * __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl StatsDB_InitStatsDatabase(int argc, char **argv, const char *pDBInfoFilename)
{
  unsigned int v3; // esi
  char cmdLine[2048]; // [esp+0h] [ebp-984h] BYREF
  CDBInfo dbInfo; // [esp+800h] [ebp-184h] BYREF
  unsigned int jobPrimaryID; // [esp+980h] [ebp-4h] BYREF

  if ( g_bMPI_Stats || VMPI_IsParamUsed(eParam: mpi_Job_Watch) )
  {
    if ( g_bMPIMaster )
    {
      GetDBInfo(pDBInfoFilename, pInfo: &dbInfo);
      if ( VMPI_Stats_Init_Master(
             pHostName: dbInfo.m_HostName,
             pDBName: dbInfo.m_DBName,
             pUserName: dbInfo.m_UserName,
             pBSPFilename: argv[argc - 1],
             pDBJobID: &jobPrimaryID) == 0 )
      {
        _Warning(
          a1: "VMPI_Stats_Init_Master( %s, %s, %s ) failed.\n",
          dbInfo.m_HostName,
          dbInfo.m_DBName,
          dbInfo.m_UserName);
        dbInfo.m_HostName[0] = 0;
      }
      v3 = jobPrimaryID;
      V_snprintf(pDest: cmdLine, maxLen: 2048, pFormat: "vmpi_job_watch -JobID %d", jobPrimaryID);
      _Msg(a1: "\nTo watch this job, run this command line:\n%s\n\n", cmdLine);
      if ( VMPI_IsParamUsed(eParam: mpi_Job_Watch) )
        RunJobWatchApp(pCmdLine: cmdLine);
      SendDBInfo(pInfo: &dbInfo, jobPrimaryID: v3);
    }
    else
    {
      RecvDBInfo(pInfo: &dbInfo, pJobPrimaryID: &jobPrimaryID);
      if ( dbInfo.m_HostName[0] != 0
        && VMPI_Stats_Init_Worker(
             pHostName: (unsigned int)&dbInfo,
             pDBName: dbInfo.m_DBName,
             pUserName: dbInfo.m_UserName,
             DBJobID: jobPrimaryID) == 0 )
      {
        _Error(
          a1: "VMPI_Stats_Init_Worker( %s, %s, %d ) failed.\n",
          dbInfo.m_HostName,
          dbInfo.m_DBName,
          dbInfo.m_UserName);
      }
    }
  }
}

// ============================================================
// Overlay from vvis_dll (Missing functions)
// ============================================================
namespace vvis_dll {

//------------------------------------------------------------------------------
// Address: 0x1000D280
// Name: public: virtual int ISQLDBCommand::GetID(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall ISQLDBCommand::GetID(ConVar *this)
{
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1000D290
// Name: public: virtual void ISQLDBCommand::GetDebugInfo(char __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ISQLDBCommand::GetDebugInfo(ISQLDBCommand *this, char *buf, int bufSize)
{
  *buf = 0;
}

//------------------------------------------------------------------------------
// Address: 0x1000D2A0
// Name: char __near * FormatStringForSQL(char const __near *)
// Source: json
//------------------------------------------------------------------------------
char *__cdecl FormatStringForSQL(const char *pText)
{
  const char *v1; // edi
  char v2; // al
  int v3; // esi
  const char *i; // ecx
  char *result; // eax
  int v6; // ecx

  v1 = pText;
  v2 = *pText;
  v3 = 0;
  for ( i = pText; v2 != 0; ++v3 )
  {
    if ( v2 == 34 || v2 == 92 )
      ++v3;
    v2 = *++i;
  }
  result = (char *)operator new(size: v3 + 1);
  v6 = 0;
  if ( v3 <= 0 )
  {
    result[v3] = 0;
  }
  else
  {
    do
    {
      if ( *v1 == 34 || *v1 == 92 )
        result[v6++] = 92;
      result[v6++] = *v1++;
    }
    while ( v6 < v3 );
    result[v3] = 0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1000D310
// Name: void VMPI_Stats_InstallSpewHook(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl VMPI_Stats_InstallSpewHook()
{
  _LoggingSystem_RegisterLoggingListener(a1: &g_VMPIStatsLoggingListener);
}

//------------------------------------------------------------------------------
// Address: 0x1000D320
// Name: void UnloadMySQLWrapper(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl UnloadMySQLWrapper()
{
  if ( g_hMySQLDLL != nullptr )
  {
    if ( g_pSQL != nullptr )
    {
      g_pSQL->Release(this: g_pSQL);
      g_pSQL = nullptr;
    }
    Sys_UnloadModule(pModule: g_hMySQLDLL);
    g_hMySQLDLL = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000D360
// Name: bool LoadMySQLWrapper(char const __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl LoadMySQLWrapper(const char *pHostName, const char *pDBName, const char *pUserName)
{
  if ( g_hMySQLDLL != nullptr )
  {
    if ( g_pSQL != nullptr )
    {
      g_pSQL->Release(this: g_pSQL);
      g_pSQL = nullptr;
    }
    Sys_UnloadModule(pModule: g_hMySQLDLL);
    g_hMySQLDLL = nullptr;
  }
  if ( !Sys_LoadInterface(
          pModuleName: "mysql_wrapper",
          pInterfaceVersionName: "MySQLWrapper001",
          pOutModule: &g_hMySQLDLL,
          pOutInterface: (void **)&g_pSQL) )
    return 0;
  if ( !g_pSQL->InitMySQL(this: g_pSQL, a2: pDBName, a3: pHostName, a4: pUserName, a5: defaultValue) )
  {
    UnloadMySQLWrapper();
    return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1000D3F0
// Name: ReadStringFromFile
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl ReadStringFromFile(_iobuf *fp, char *pStr, int strSize)
{
  int i; // esi

  for ( i = 0; i < strSize - 2; ++i )
  {
    if ( fread(buffer: &pStr[i], elementSize: 1u, count: 1u, stream: fp) != 1 )
      break;
    if ( pStr[i] == 10 )
      break;
  }
  pStr[i] = 0;
  return i != 0;
}

//------------------------------------------------------------------------------
// Address: 0x1000D440
// Name: void GetDBInfo(char const __near *,class CDBInfo __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GetDBInfo(const char *pDBInfoFilename, CDBInfo *pInfo)
{
  HMODULE ModuleHandleA; // eax
  _iobuf *v3; // esi
  char baseExeFilename[512]; // [esp+Ch] [ebp-400h] BYREF
  char dbInfoFilename[512]; // [esp+20Ch] [ebp-200h] BYREF

  ModuleHandleA = GetModuleHandleA(lpModuleName: nullptr);
  if ( GetModuleFileNameA(hModule: ModuleHandleA, lpFilename: baseExeFilename, nSize: 0x200u) == 0 )
    _Error(a1: "GetModuleFileName failed.");
  V_strncpy(pDest: dbInfoFilename, pSrc: baseExeFilename, maxLen: 512);
  V_StripFilename(path: dbInfoFilename);
  if ( dbInfoFilename[0] == 0 )
    V_strncpy(pDest: dbInfoFilename, pSrc: ".", maxLen: 512);
  V_strncat(pDest: dbInfoFilename, pSrc: "/", destBufferSize: 0x200u, max_chars_to_copy: -1);
  V_strncat(pDest: dbInfoFilename, pSrc: pDBInfoFilename, destBufferSize: 0x200u, max_chars_to_copy: -1);
  v3 = fopen(file: dbInfoFilename, mode: "rt");
  if ( v3 == nullptr )
    _Error(a1: "Can't open %s for database info.\n", dbInfoFilename);
  if ( !ReadStringFromFile(fp: v3, pStr: pInfo->m_HostName, strSize: 128)
    || !ReadStringFromFile(fp: v3, pStr: pInfo->m_DBName, strSize: 128)
    || !ReadStringFromFile(fp: v3, pStr: pInfo->m_UserName, strSize: 128) )
  {
    _Error(a1: "%s is not a valid database info file.\n", dbInfoFilename);
  }
  fclose(stream: v3);
}

//------------------------------------------------------------------------------
// Address: 0x1000D590
// Name: void RunJobWatchApp(char __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl RunJobWatchApp(char *pCmdLine)
{
  char *v1; // esi
  char *v2; // eax
  const char *ParamString; // eax
  char dirName[512]; // [esp+0h] [ebp-254h] BYREF
  _STARTUPINFOA StartupInfo; // [esp+200h] [ebp-54h] BYREF
  _PROCESS_INFORMATION pi; // [esp+244h] [ebp-10h] BYREF

  memset(dst: (unsigned __int8 *)&StartupInfo, value: 0, count: sizeof(StartupInfo));
  StartupInfo.cb = 68;
  memset(&pi, 0, sizeof(pi));
  if ( GetModuleFileNameA(hModule: nullptr, lpFilename: dirName, nSize: 0x200u) != 0 )
  {
    v1 = _V_strrchr(s: dirName, c: 92);
    v2 = _V_strrchr(s: dirName, c: 47);
    if ( v1 != nullptr )
    {
      if ( v1 > v2 )
        goto LABEL_7;
    }
    else if ( v2 == nullptr )
    {
      return;
    }
    v1 = v2;
LABEL_7:
    *v1 = 0;
    if ( !CreateProcessA(
            lpApplicationName: nullptr,
            lpCommandLine: pCmdLine,
            lpProcessAttributes: nullptr,
            lpThreadAttributes: nullptr,
            bInheritHandles: true,
            dwCreationFlags: 0,
            lpEnvironment: nullptr,
            lpCurrentDirectory: dirName,
            lpStartupInfo: &StartupInfo,
            lpProcessInformation: &pi) )
    {
      ParamString = VMPI_GetParamString(eParam: mpi_Job_Watch);
      _Warning(a1: "%s - error launching '%s'\n", ParamString, pCmdLine);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000D660
// Name: unsigned long StatsDB_GetUniqueJobID(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __cdecl StatsDB_GetUniqueJobID()
{
  return g_JobPrimaryID;
}

//------------------------------------------------------------------------------
// Address: 0x1000D670
// Name: public: virtual void CSQLDBCommandBase::deleteThis(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSQLDBCommandBase::deleteThis(CSQLDBCommandBase *this)
{
  if ( this != nullptr )
    ((void (__thiscall *)(CSQLDBCommandBase *, int))this->dtr_ISQLDBCommand)(a1: this, a2: 1);
}

//------------------------------------------------------------------------------
// Address: 0x1000D6C0
// Name: public: virtual int CSQLDBCommand_WorkerStats::RunCommand(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CSQLDBCommand_WorkerStats::RunCommand(CSQLDBCommand_WorkerStats *this)
{
  int CurrentNumberOfConnections; // edi
  int v2; // esi
  bool IsProcConnected; // al
  int NumWorkUnitsCompleted; // [esp-8h] [ebp-810h]
  unsigned int JobWorkerID; // [esp-4h] [ebp-80Ch]
  char query[2048]; // [esp+8h] [ebp-800h] BYREF

  CurrentNumberOfConnections = VMPI_GetCurrentNumberOfConnections();
  V_snprintf(
    pDest: query,
    maxLen: 2048,
    pFormat: "update job_master_start set NumWorkers=%d where JobID=%lu",
    CurrentNumberOfConnections,
    g_JobPrimaryID);
  g_pSQL->Execute(this: g_pSQL, a2: query);
  v2 = 1;
  if ( CurrentNumberOfConnections <= 1 )
    return 1;
  do
  {
    if ( VMPI_GetJobWorkerID(iProc: v2) != -1 )
    {
      JobWorkerID = VMPI_GetJobWorkerID(iProc: v2);
      NumWorkUnitsCompleted = VMPI_GetNumWorkUnitsCompleted(iProc: v2);
      IsProcConnected = VMPI_IsProcConnected(procID: v2);
      V_snprintf(
        pDest: query,
        maxLen: 2048,
        pFormat: "update job_worker_start set WorkerState=%d, NumWorkUnits=%d where JobWorkerID=%lu",
        IsProcConnected,
        NumWorkUnitsCompleted,
        JobWorkerID);
      g_pSQL->Execute(this: g_pSQL, a2: query);
    }
    ++v2;
  }
  while ( v2 < CurrentNumberOfConnections );
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1000D7C0
// Name: void PerfThread_AddGraphEntry(unsigned long,unsigned long __near &,unsigned long __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl PerfThread_AddGraphEntry(unsigned int startTicks, unsigned int *lastSent, unsigned int *lastReceived)
{
  int v3; // ebx
  int v4; // edi
  ISQLDBCommand *v5; // esi
  ISQLDBCommand_vtbl *v6; // edi
  ISQLDBCommand_vtbl *v7; // ebx
  DWORD TickCount; // eax
  unsigned int curSent; // [esp+Ch] [ebp-8h]
  unsigned int curReceived; // [esp+10h] [ebp-4h]

  v3 = g_nBytesSent + g_nMulticastBytesSent;
  v4 = g_nBytesReceived + g_nMulticastBytesReceived;
  curSent = g_nBytesSent + g_nMulticastBytesSent;
  curReceived = g_nBytesReceived + g_nMulticastBytesReceived;
  v5 = (ISQLDBCommand *)operator new(size: 0x10u);
  if ( v5 != nullptr )
  {
    v6 = (ISQLDBCommand_vtbl *)(v4 - *lastReceived);
    v7 = (ISQLDBCommand_vtbl *)(v3 - *lastSent);
    TickCount = GetTickCount();
    v5[1].__vftable = v7;
    v3 = curSent;
    v5[2].__vftable = v6;
    v4 = curReceived;
    v5->__vftable = (ISQLDBCommand_vtbl *)&CSQLDBCommand_GraphEntry::`vftable';
    v5[3].__vftable = (ISQLDBCommand_vtbl *)(TickCount - startTicks);
  }
  else
  {
    v5 = nullptr;
  }
  CMySqlDatabase::AddCommandToQueue(this: g_pDB, cmd: v5, replyTarget: nullptr, returnState: 0);
  *lastSent = v3;
  *lastReceived = v4;
}

//------------------------------------------------------------------------------
// Address: 0x1000D850
// Name: void VMPI_Stats_Term(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl VMPI_Stats_Term()
{
  ISQLDBCommand *v0; // eax
  DWORD TickCount; // edi
  CMySqlDatabase *v2; // esi

  if ( g_pDB != nullptr )
  {
    SetEvent(hEvent: g_hPerfThreadExitEvent);
    WaitForSingleObject(hHandle: g_hPerfThread, dwMilliseconds: 0xFFFFFFFF);
    CloseHandle(hObject: g_hPerfThreadExitEvent);
    g_hPerfThreadExitEvent = nullptr;
    CloseHandle(hObject: g_hPerfThread);
    g_hPerfThread = nullptr;
    if ( g_bMaster )
    {
      v0 = (ISQLDBCommand *)operator new(size: 4u);
      if ( v0 != nullptr )
        v0->__vftable = (ISQLDBCommand_vtbl *)&CSQLDBCommand_JobMasterEnd::`vftable';
      else
        v0 = nullptr;
      CMySqlDatabase::AddCommandToQueue(this: g_pDB, cmd: v0, replyTarget: nullptr, returnState: 0);
    }
    TickCount = GetTickCount();
    if ( GetTickCount() - TickCount < 0x3E8 )
    {
      while ( g_pDB->QueriesInOutQueue(this: g_pDB) != 0 && GetTickCount() - TickCount < 0x3E8 )
        ;
    }
    v2 = g_pDB;
    if ( g_pDB != nullptr )
    {
      CMySqlDatabase::~CMySqlDatabase(this: g_pDB);
      operator delete(p: v2);
    }
    g_pDB = nullptr;
    if ( g_hMySQLDLL != nullptr )
    {
      if ( g_pSQL != nullptr )
      {
        g_pSQL->Release(this: g_pSQL);
        g_pSQL = nullptr;
      }
      Sys_UnloadModule(pModule: g_hMySQLDLL);
      g_hMySQLDLL = nullptr;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000D960
// Name: public: int CMySQLQuery::Execute(class IMySQL __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CMySQLQuery::Execute(CMySQLQuery *this, IMySQL *pDB)
{
  int v3; // eax
  bool v4; // sf
  int v5; // ebx

  v3 = pDB->Execute(this: pDB, a2: this->m_QueryText.m_Memory.m_pMemory);
  v4 = this->m_QueryText.m_Memory.m_nGrowSize < 0;
  v5 = v3;
  this->m_QueryText.m_Size = 0;
  if ( !v4 )
  {
    if ( this->m_QueryText.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_QueryText.m_Memory.m_pMemory);
      this->m_QueryText.m_Memory.m_pMemory = nullptr;
    }
    this->m_QueryText.m_Memory.m_nAllocationCount = 0;
  }
  this->m_QueryText.m_pElements = this->m_QueryText.m_Memory.m_pMemory;
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x1000D9C0
// Name: public: virtual void CLoggingListener_VMPIStats::Log(struct LoggingContext_t const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLoggingListener_VMPIStats::Log(
        CLoggingListener_VMPIStats *this,
        const LoggingContext_t *pContext,
        const char *pMessage)
{
  CCriticalSectionLock csLock; // [esp+4h] [ebp-8h] BYREF

  CCriticalSectionLock::CCriticalSectionLock(this: &csLock, pCS: &g_SpewTextCS);
  CCriticalSectionLock::Lock(this: &csLock);
  CUtlVector<char,CUtlMemory<char,int>>::InsertMultipleBefore(
    this: &g_SpewText,
    elem: g_SpewText.m_Size,
    num: strlen(pMessage),
    pToInsert: pMessage);
  CCriticalSectionLock::Unlock(this: &csLock);
  CCriticalSectionLock::~CCriticalSectionLock(this: &csLock);
}

//------------------------------------------------------------------------------
// Address: 0x1000DA20
// Name: void PerfThread_SendSpewText(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl PerfThread_SendSpewText()
{
  int m_Size; // eax
  int v1; // esi
  char *m_pMemory; // ecx
  int v3; // eax
  ISQLDBCommand *v4; // esi
  const char *ParamString; // eax
  ISQLDBCommand *v6; // eax
  char *v7; // [esp-8h] [ebp-210h]
  char msg[512]; // [esp+0h] [ebp-208h] BYREF
  CCriticalSectionLock csLock; // [esp+200h] [ebp-8h] BYREF

  CCriticalSectionLock::CCriticalSectionLock(this: &csLock, pCS: &g_SpewTextCS);
  CCriticalSectionLock::Lock(this: &csLock);
  m_Size = g_SpewText.m_Size;
  if ( g_SpewText.m_Size > 0 )
  {
    v1 = g_SpewText.m_Size;
    if ( g_SpewText.m_Size + 1 > g_SpewText.m_Memory.m_nAllocationCount )
    {
      CUtlMemory<char,int>::Grow(
        this: (CUtlMemory<unsigned char,int> *)&g_SpewText,
        num: g_SpewText.m_Size - g_SpewText.m_Memory.m_nAllocationCount + 1);
      m_Size = g_SpewText.m_Size;
    }
    m_pMemory = g_SpewText.m_Memory.m_pMemory;
    g_SpewText.m_Size = m_Size + 1;
    v3 = m_Size - v1;
    g_SpewText.m_pElements = g_SpewText.m_Memory.m_pMemory;
    if ( v3 > 0 )
    {
      _V_memmove(dest: &g_SpewText.m_Memory.m_pMemory[v1 + 1], src: &g_SpewText.m_Memory.m_pMemory[v1], count: v3);
      m_pMemory = g_SpewText.m_Memory.m_pMemory;
    }
    if ( &m_pMemory[v1] != nullptr )
      m_pMemory[v1] = 0;
    if ( g_bMPI_StatsTextOutput )
    {
      v4 = (ISQLDBCommand *)operator new(size: 8u);
      if ( v4 != nullptr )
      {
        v7 = g_SpewText.m_Memory.m_pMemory;
        v4->__vftable = (ISQLDBCommand_vtbl *)&CSQLDBCommand_TextMessage::`vftable';
        v4[1].__vftable = (ISQLDBCommand_vtbl *)FormatStringForSQL(pText: v7);
LABEL_15:
        CMySqlDatabase::AddCommandToQueue(this: g_pDB, cmd: v4, replyTarget: nullptr, returnState: 0);
        goto LABEL_16;
      }
    }
    else
    {
      if ( !bFirst )
      {
LABEL_16:
        g_SpewText.m_Size = 0;
        goto LABEL_17;
      }
      ParamString = VMPI_GetParamString(eParam: mpi_Stats_TextOutput);
      V_snprintf(pDest: msg, maxLen: 512, pFormat: "%s not enabled", ParamString);
      bFirst = false;
      v6 = (ISQLDBCommand *)operator new(size: 8u);
      v4 = v6;
      if ( v6 != nullptr )
      {
        v6->__vftable = (ISQLDBCommand_vtbl *)&CSQLDBCommand_TextMessage::`vftable';
        v6[1].__vftable = (ISQLDBCommand_vtbl *)FormatStringForSQL(pText: msg);
        goto LABEL_15;
      }
    }
    v4 = nullptr;
    goto LABEL_15;
  }
LABEL_17:
  CCriticalSectionLock::Unlock(this: &csLock);
  CCriticalSectionLock::~CCriticalSectionLock(this: &csLock);
}

//------------------------------------------------------------------------------
// Address: 0x1000DB60
// Name: unsigned long PerfThreadFn(void __near *)
// Source: json
//------------------------------------------------------------------------------
unsigned int __stdcall PerfThreadFn(void *pParameter)
{
  unsigned int v1; // edi
  unsigned int v2; // ebx
  ISQLDBCommand *v3; // esi
  DWORD TickCount; // eax
  ISQLDBCommand_vtbl *v5; // edx
  ISQLDBCommand_vtbl *v6; // eax
  ISQLDBCommand *v7; // eax
  DWORD startTicks; // [esp+0h] [ebp-Ch]
  unsigned int lastSent; // [esp+4h] [ebp-8h] BYREF
  unsigned int lastReceived; // [esp+8h] [ebp-4h] BYREF

  lastSent = 0;
  lastReceived = 0;
  startTicks = GetTickCount();
  while ( WaitForSingleObject(hHandle: g_hPerfThreadExitEvent, dwMilliseconds: 0x3E8u) != 0 )
  {
    v1 = g_nBytesSent + g_nMulticastBytesSent;
    v2 = g_nBytesReceived + g_nMulticastBytesReceived;
    v3 = (ISQLDBCommand *)operator new(size: 0x10u);
    if ( v3 != nullptr )
    {
      TickCount = GetTickCount();
      v5 = (ISQLDBCommand_vtbl *)(v1 - lastSent);
      v3[3].__vftable = (ISQLDBCommand_vtbl *)(TickCount - startTicks);
      v6 = (ISQLDBCommand_vtbl *)(v2 - lastReceived);
      v3->__vftable = (ISQLDBCommand_vtbl *)&CSQLDBCommand_GraphEntry::`vftable';
      v3[1].__vftable = v5;
      v3[2].__vftable = v6;
    }
    else
    {
      v3 = nullptr;
    }
    CMySqlDatabase::AddCommandToQueue(this: g_pDB, cmd: v3, replyTarget: nullptr, returnState: 0);
    lastSent = v1;
    lastReceived = v2;
    PerfThread_SendSpewText();
    if ( g_bMaster )
    {
      v7 = (ISQLDBCommand *)operator new(size: 4u);
      if ( v7 != nullptr )
        v7->__vftable = (ISQLDBCommand_vtbl *)&CSQLDBCommand_WorkerStats::`vftable';
      else
        v7 = nullptr;
      CMySqlDatabase::AddCommandToQueue(this: g_pDB, cmd: v7, replyTarget: nullptr, returnState: 0);
    }
  }
  PerfThread_SendSpewText();
  PerfThread_AddGraphEntry(startTicks, &lastSent, &lastReceived);
  SetEvent(hEvent: g_hPerfThreadExitEvent);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1000DC80
// Name: public: void CMySQLQuery::Format(char const __near *,...)
// Source: json
//------------------------------------------------------------------------------
void CMySQLQuery::Format(CMySQLQuery *this, const char *pFormat, ...)
{
  int m_nAllocationCount; // eax
  char *m_pMemory; // eax
  int v4; // ecx
  int m_Size; // edi
  bool v6; // zf
  int v7; // edi
  int v8; // eax
  char *v9; // ecx
  int v10; // eax
  va_list ap; // [esp+18h] [ebp+10h] BYREF

  va_start(ap, pFormat);
  m_nAllocationCount = this->m_QueryText.m_Memory.m_nAllocationCount;
  this->m_QueryText.m_Size = 0;
  if ( m_nAllocationCount < 1024 )
    CUtlMemory<char,int>::Grow((CUtlMemory<unsigned char,int> *)this, num: 1024 - m_nAllocationCount);
  this->m_QueryText.m_Size += 1024;
  m_pMemory = this->m_QueryText.m_Memory.m_pMemory;
  v4 = this->m_QueryText.m_Size - 1024;
  this->m_QueryText.m_pElements = this->m_QueryText.m_Memory.m_pMemory;
  if ( v4 > 0 )
    _V_memmove(dest: m_pMemory + 1024, src: m_pMemory, count: v4);
  while ( _vsnprintf(string: this->m_QueryText.m_Memory.m_pMemory, count: this->m_QueryText.m_Size, format: pFormat, ap) < 0 )
  {
    m_Size = this->m_QueryText.m_Size;
    v6 = m_Size == -1024;
    v7 = m_Size + 1024;
    this->m_QueryText.m_Size = 0;
    if ( !v6 )
    {
      v8 = this->m_QueryText.m_Memory.m_nAllocationCount;
      if ( v7 > v8 )
        CUtlMemory<char,int>::Grow((CUtlMemory<unsigned char,int> *)this, num: v7 - v8);
      this->m_QueryText.m_Size += v7;
      v9 = this->m_QueryText.m_Memory.m_pMemory;
      v10 = this->m_QueryText.m_Size - v7;
      this->m_QueryText.m_pElements = this->m_QueryText.m_Memory.m_pMemory;
      if ( v10 > 0 && v7 > 0 )
        _V_memmove(dest: &v9[v7], src: v9, count: v10);
    }
  }
  this->m_QueryText.m_Memory.m_pMemory[this->m_QueryText.m_Size - 1] = 0;
}

//------------------------------------------------------------------------------
// Address: 0x1000DD60
// Name: public: virtual int CSQLDBCommand_JobMasterEnd::RunCommand(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CSQLDBCommand_JobMasterEnd::RunCommand(CSQLDBCommand_JobMasterEnd *this)
{
  char *m_pMemory; // esi
  DWORD TickCount; // eax
  char *v3; // esi
  CMySQLQuery query; // [esp+8h] [ebp-14h] BYREF

  memset(&query, 0, sizeof(query));
  CMySQLQuery::Format(
    this: &query,
    pFormat: "insert into job_master_end values ( %lu, %d, %d, \"no errors\" )",
    g_JobPrimaryID,
    g_nWorkersConnected,
    g_nWorkersDisconnected);
  m_pMemory = query.m_QueryText.m_Memory.m_pMemory;
  g_pSQL->Execute(this: g_pSQL, a2: query.m_QueryText.m_Memory.m_pMemory);
  query.m_QueryText.m_Size = 0;
  if ( query.m_QueryText.m_Memory.m_nGrowSize >= 0 )
  {
    if ( m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
      m_pMemory = nullptr;
      query.m_QueryText.m_Memory.m_pMemory = nullptr;
    }
    query.m_QueryText.m_Memory.m_nAllocationCount = 0;
  }
  query.m_QueryText.m_pElements = m_pMemory;
  TickCount = GetTickCount();
  CMySQLQuery::Format(
    this: &query,
    pFormat: "update job_master_start set RunningTimeMS=%lu where JobID=%lu",
    TickCount - g_StatsStartTime,
    g_JobPrimaryID);
  v3 = query.m_QueryText.m_Memory.m_pMemory;
  g_pSQL->Execute(this: g_pSQL, a2: query.m_QueryText.m_Memory.m_pMemory);
  query.m_QueryText.m_Size = 0;
  if ( query.m_QueryText.m_Memory.m_nGrowSize >= 0 )
  {
    if ( v3 != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v3);
      v3 = nullptr;
      query.m_QueryText.m_Memory.m_pMemory = nullptr;
    }
    query.m_QueryText.m_Memory.m_nAllocationCount = 0;
  }
  query.m_QueryText.m_pElements = v3;
  CUtlVector<dleafambientlighting_t,CUtlMemory<dleafambientlighting_t,int>>::~CUtlVector<dleafambientlighting_t,CUtlMemory<dleafambientlighting_t,int>>(this: (CUtlVector<CFileResponse,CUtlMemory<CFileResponse,int> > *)&query);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1000DE50
// Name: void UpdateJobWorkerRunningTime(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl UpdateJobWorkerRunningTime()
{
  DWORD v0; // esi
  char *m_pMemory; // esi
  char curStage[256]; // [esp+8h] [ebp-114h] BYREF
  CMySQLQuery query; // [esp+108h] [ebp-14h] BYREF

  v0 = GetTickCount() - g_StatsStartTime;
  VMPI_GetCurrentStage(pOut: curStage, strLen: 256);
  memset(&query, 0, sizeof(query));
  CMySQLQuery::Format(
    this: &query,
    pFormat: "update job_worker_start set RunningTimeMS=%lu, CurrentStage=\"%s\", Thread0WU=%d, Thread1WU=%d, Thread2WU=%d, Thread"
    "3WU=%d where JobWorkerID=%lu",
    v0,
    curStage,
    LODWORD(g_ThreadWUs[0]),
    dword_10088328,
    dword_10088330,
    dword_10088338,
    g_JobWorkerID);
  m_pMemory = query.m_QueryText.m_Memory.m_pMemory;
  g_pSQL->Execute(this: g_pSQL, a2: query.m_QueryText.m_Memory.m_pMemory);
  query.m_QueryText.m_Size = 0;
  if ( query.m_QueryText.m_Memory.m_nGrowSize >= 0 )
  {
    if ( m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
      m_pMemory = nullptr;
      query.m_QueryText.m_Memory.m_pMemory = nullptr;
    }
    query.m_QueryText.m_Memory.m_nAllocationCount = 0;
  }
  query.m_QueryText.m_pElements = m_pMemory;
  CUtlVector<dleafambientlighting_t,CUtlMemory<dleafambientlighting_t,int>>::~CUtlVector<dleafambientlighting_t,CUtlMemory<dleafambientlighting_t,int>>(this: (CUtlVector<CFileResponse,CUtlMemory<CFileResponse,int> > *)&query);
}

//------------------------------------------------------------------------------
// Address: 0x1000DF10
// Name: public: virtual int CSQLDBCommand_GraphEntry::RunCommand(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CSQLDBCommand_GraphEntry::RunCommand(CSQLDBCommand_GraphEntry *this)
{
  char *m_pMemory; // esi
  unsigned int m_msTime; // [esp-Ch] [ebp-28h]
  unsigned int m_nBytesSent; // [esp-8h] [ebp-24h]
  unsigned int m_nBytesReceived; // [esp-4h] [ebp-20h]
  CMySQLQuery query; // [esp+8h] [ebp-14h] BYREF

  m_nBytesReceived = this->m_nBytesReceived;
  m_nBytesSent = this->m_nBytesSent;
  m_msTime = this->m_msTime;
  memset(&query, 0, sizeof(query));
  CMySQLQuery::Format(
    this: &query,
    pFormat: "insert into graph_entry (JobWorkerID, MSSinceJobStart, BytesSent, BytesReceived) values ( %lu, %lu, %lu, %lu )",
    g_JobWorkerID,
    m_msTime,
    m_nBytesSent,
    m_nBytesReceived);
  m_pMemory = query.m_QueryText.m_Memory.m_pMemory;
  g_pSQL->Execute(this: g_pSQL, a2: query.m_QueryText.m_Memory.m_pMemory);
  query.m_QueryText.m_Size = 0;
  if ( query.m_QueryText.m_Memory.m_nGrowSize >= 0 )
  {
    if ( m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
      m_pMemory = nullptr;
      query.m_QueryText.m_Memory.m_pMemory = nullptr;
    }
    query.m_QueryText.m_Memory.m_nAllocationCount = 0;
  }
  query.m_QueryText.m_pElements = m_pMemory;
  UpdateJobWorkerRunningTime();
  ++g_CurrentMessageIndex;
  CUtlVector<dleafambientlighting_t,CUtlMemory<dleafambientlighting_t,int>>::~CUtlVector<dleafambientlighting_t,CUtlMemory<dleafambientlighting_t,int>>(this: (CUtlVector<CFileResponse,CUtlMemory<CFileResponse,int> > *)&query);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1000DFB0
// Name: public: virtual int CSQLDBCommand_TextMessage::RunCommand(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CSQLDBCommand_TextMessage::RunCommand(CSQLDBCommand_TextMessage *this)
{
  char *m_pMemory; // esi
  char *m_pText; // [esp-4h] [ebp-20h]
  CMySQLQuery query; // [esp+8h] [ebp-14h] BYREF

  m_pText = this->m_pText;
  memset(&query, 0, sizeof(query));
  CMySQLQuery::Format(
    this: &query,
    pFormat: "insert into text_messages (JobWorkerID, MessageIndex, Text) values ( %lu, %lu, \"%s\" )",
    g_JobWorkerID,
    g_CurrentMessageIndex,
    m_pText);
  m_pMemory = query.m_QueryText.m_Memory.m_pMemory;
  g_pSQL->Execute(this: g_pSQL, a2: query.m_QueryText.m_Memory.m_pMemory);
  query.m_QueryText.m_Size = 0;
  if ( query.m_QueryText.m_Memory.m_nGrowSize >= 0 )
  {
    if ( m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
      m_pMemory = nullptr;
      query.m_QueryText.m_Memory.m_pMemory = nullptr;
    }
    query.m_QueryText.m_Memory.m_nAllocationCount = 0;
  }
  ++g_CurrentMessageIndex;
  query.m_QueryText.m_pElements = m_pMemory;
  CUtlVector<dleafambientlighting_t,CUtlMemory<dleafambientlighting_t,int>>::~CUtlVector<dleafambientlighting_t,CUtlMemory<dleafambientlighting_t,int>>(this: (CUtlVector<CFileResponse,CUtlMemory<CFileResponse,int> > *)&query);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1000E040
// Name: bool VMPI_Stats_Init_Worker(char const __near *,char const __near *,char const __near *,unsigned long)
// Source: json
//------------------------------------------------------------------------------
char __cdecl VMPI_Stats_Init_Worker(
        unsigned int pHostName,
        const char *pDBName,
        const char *pUserName,
        unsigned int DBJobID)
{
  DWORD TickCount; // eax
  const char *v5; // esi
  CMySqlDatabase *v6; // eax
  CMySqlDatabase *v7; // ecx
  char *m_pMemory; // esi
  unsigned int (__thiscall *InsertID)(IMySQL *); // eax
  CMySqlDatabase *v10; // esi
  CMySqlDatabase *v12; // esi
  CMySQLQuery query; // [esp+8h] [ebp-14h] BYREF

  TickCount = GetTickCount();
  v5 = (const char *)pHostName;
  g_StatsStartTime = TickCount;
  if ( pHostName == 0 )
    goto LABEL_7;
  v6 = (CMySqlDatabase *)operator new(size: 0xBCu);
  if ( v6 != nullptr )
  {
    v7 = CMySqlDatabase::CMySqlDatabase(this: v6);
    g_pDB = v7;
    if ( v7 != nullptr )
    {
      if ( CMySqlDatabase::Initialize(this: v7) && LoadMySQLWrapper(pHostName: v5, pDBName, pUserName) != 0 )
      {
        pHostName = 16;
        GetComputerNameA(lpBuffer: g_MachineName, nSize: &pHostName);
LABEL_7:
        g_JobPrimaryID = DBJobID;
        g_JobWorkerID = 0;
        memset(&query, 0, sizeof(query));
        CMySQLQuery::Format(
          this: &query,
          pFormat: "insert into job_worker_start ( JobID, CurrentStage, IsMaster, MachineName ) values ( %lu, \"none\", %d, \"%s\" )",
          DBJobID,
          g_bMaster,
          g_MachineName);
        m_pMemory = query.m_QueryText.m_Memory.m_pMemory;
        g_pSQL->Execute(this: g_pSQL, a2: query.m_QueryText.m_Memory.m_pMemory);
        query.m_QueryText.m_Size = 0;
        if ( query.m_QueryText.m_Memory.m_nGrowSize >= 0 )
        {
          if ( m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
            m_pMemory = nullptr;
            query.m_QueryText.m_Memory.m_pMemory = nullptr;
          }
          query.m_QueryText.m_Memory.m_nAllocationCount = 0;
        }
        InsertID = g_pSQL->InsertID;
        query.m_QueryText.m_pElements = m_pMemory;
        g_JobWorkerID = InsertID(this: g_pSQL);
        if ( g_JobWorkerID != 0 )
        {
          g_hPerfThreadExitEvent = CreateEventA(
                                     lpEventAttributes: nullptr,
                                     bManualReset: false,
                                     bInitialState: false,
                                     lpName: nullptr);
          g_hPerfThread = CreateThread(
                            lpThreadAttributes: nullptr,
                            dwStackSize: 0,
                            lpStartAddress: PerfThreadFn,
                            lpParameter: nullptr,
                            dwCreationFlags: 0,
                            lpThreadId: &g_PerfThreadID);
          CUtlVector<dleafambientlighting_t,CUtlMemory<dleafambientlighting_t,int>>::~CUtlVector<dleafambientlighting_t,CUtlMemory<dleafambientlighting_t,int>>(this: (CUtlVector<CFileResponse,CUtlMemory<CFileResponse,int> > *)&query);
          return 1;
        }
        else
        {
          v10 = g_pDB;
          if ( g_pDB != nullptr )
          {
            CMySqlDatabase::~CMySqlDatabase(this: g_pDB);
            operator delete(p: v10);
          }
          g_pDB = nullptr;
          CUtlVector<dleafambientlighting_t,CUtlMemory<dleafambientlighting_t,int>>::~CUtlVector<dleafambientlighting_t,CUtlMemory<dleafambientlighting_t,int>>(this: (CUtlVector<CFileResponse,CUtlMemory<CFileResponse,int> > *)&query);
          return 0;
        }
      }
      v7 = g_pDB;
    }
  }
  else
  {
    v7 = nullptr;
    g_pDB = nullptr;
  }
  v12 = v7;
  if ( v7 != nullptr )
  {
    CMySqlDatabase::~CMySqlDatabase(this: v7);
    operator delete(p: v12);
  }
  g_pDB = nullptr;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1000E1F0
// Name: bool VMPI_Stats_Init_Master(char const __near *,char const __near *,char const __near *,char const __near *,unsigned long __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl VMPI_Stats_Init_Master(
        const char *pHostName,
        const char *pDBName,
        const char *pUserName,
        const char *pBSPFilename,
        unsigned int *pDBJobID)
{
  CMySqlDatabase *v5; // eax
  CMySqlDatabase *v6; // ecx
  unsigned int v7; // eax
  CMySqlDatabase *v8; // edi
  char inited; // bl
  CMySqlDatabase *v11; // edi
  CMySQLQuery query; // [esp+8h] [ebp-18h] BYREF
  unsigned int size; // [esp+1Ch] [ebp-4h] BYREF

  g_bMaster = true;
  v5 = (CMySqlDatabase *)operator new(size: 0xBCu);
  if ( v5 != nullptr )
  {
    v6 = CMySqlDatabase::CMySqlDatabase(this: v5);
    g_pDB = v6;
    if ( v6 != nullptr )
    {
      if ( CMySqlDatabase::Initialize(this: v6) && LoadMySQLWrapper(pHostName, pDBName, pUserName) != 0 )
      {
        size = 16;
        GetComputerNameA(lpBuffer: g_MachineName, nSize: &size);
        V_FileBase(in: pBSPFilename, out: g_BSPFilename, maxlen: 256);
        g_JobPrimaryID = 0;
        memset(&query, 0, sizeof(query));
        CMySQLQuery::Format(
          this: &query,
          pFormat: "insert into job_master_start ( BSPFilename, StartTime, MachineName, RunningTimeMS ) values ( \"%s\", null, \"%s\", %lu )",
          g_BSPFilename,
          g_MachineName,
          -19088643);
        CMySQLQuery::Execute(this: &query, pDB: g_pSQL);
        v7 = g_pSQL->InsertID(this: g_pSQL);
        g_JobPrimaryID = v7;
        if ( v7 != 0 )
        {
          *pDBJobID = v7;
          inited = VMPI_Stats_Init_Worker(pHostName: 0, pDBName: nullptr, pUserName: nullptr, DBJobID: g_JobPrimaryID);
          CUtlVector<dleafambientlighting_t,CUtlMemory<dleafambientlighting_t,int>>::~CUtlVector<dleafambientlighting_t,CUtlMemory<dleafambientlighting_t,int>>(this: (CUtlVector<CFileResponse,CUtlMemory<CFileResponse,int> > *)&query);
          return inited;
        }
        else
        {
          v8 = g_pDB;
          if ( g_pDB != nullptr )
          {
            CMySqlDatabase::~CMySqlDatabase(this: g_pDB);
            operator delete(p: v8);
          }
          g_pDB = nullptr;
          CUtlVector<dleafambientlighting_t,CUtlMemory<dleafambientlighting_t,int>>::~CUtlVector<dleafambientlighting_t,CUtlMemory<dleafambientlighting_t,int>>(this: (CUtlVector<CFileResponse,CUtlMemory<CFileResponse,int> > *)&query);
          return 0;
        }
      }
      v6 = g_pDB;
    }
  }
  else
  {
    v6 = nullptr;
    g_pDB = nullptr;
  }
  v11 = v6;
  if ( v6 != nullptr )
  {
    CMySqlDatabase::~CMySqlDatabase(this: v6);
    operator delete(p: v11);
  }
  g_pDB = nullptr;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1000E370
// Name: void StatsDB_InitStatsDatabase(int,char __near * __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl StatsDB_InitStatsDatabase(int argc, char **argv, const char *pDBInfoFilename)
{
  unsigned int v3; // esi
  char cmdLine[2048]; // [esp+0h] [ebp-984h] BYREF
  CDBInfo dbInfo; // [esp+800h] [ebp-184h] BYREF
  unsigned int jobPrimaryID; // [esp+980h] [ebp-4h] BYREF

  if ( g_bMPI_Stats || VMPI_IsParamUsed(eParam: mpi_Job_Watch) )
  {
    if ( g_bMPIMaster )
    {
      GetDBInfo(pDBInfoFilename, pInfo: &dbInfo);
      if ( VMPI_Stats_Init_Master(
             pHostName: dbInfo.m_HostName,
             pDBName: dbInfo.m_DBName,
             pUserName: dbInfo.m_UserName,
             pBSPFilename: argv[argc - 1],
             pDBJobID: &jobPrimaryID) == 0 )
      {
        _Warning(
          a1: "VMPI_Stats_Init_Master( %s, %s, %s ) failed.\n",
          dbInfo.m_HostName,
          dbInfo.m_DBName,
          dbInfo.m_UserName);
        dbInfo.m_HostName[0] = 0;
      }
      v3 = jobPrimaryID;
      V_snprintf(pDest: cmdLine, maxLen: 2048, pFormat: "vmpi_job_watch -JobID %d", jobPrimaryID);
      _Msg(a1: "\nTo watch this job, run this command line:\n%s\n\n", cmdLine);
      if ( VMPI_IsParamUsed(eParam: mpi_Job_Watch) )
        RunJobWatchApp(pCmdLine: cmdLine);
      SendDBInfo(pInfo: &dbInfo, jobPrimaryID: v3);
    }
    else
    {
      RecvDBInfo(pInfo: &dbInfo, pJobPrimaryID: &jobPrimaryID);
      if ( dbInfo.m_HostName[0] != 0
        && VMPI_Stats_Init_Worker(
             pHostName: (unsigned int)&dbInfo,
             pDBName: dbInfo.m_DBName,
             pUserName: dbInfo.m_UserName,
             DBJobID: jobPrimaryID) == 0 )
      {
        _Error(
          a1: "VMPI_Stats_Init_Worker( %s, %s, %d ) failed.\n",
          dbInfo.m_HostName,
          dbInfo.m_DBName,
          dbInfo.m_UserName);
      }
    }
  }
}

} // namespace vvis_dll
