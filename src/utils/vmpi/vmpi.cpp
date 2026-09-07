// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/vmpi/vmpi.cpp
// Functions: 75
// ============================================================

#include "utils\vmpi\vmpi.h"

//------------------------------------------------------------------------------
// Address: 0x1001C470
// Name: public: struct TSLNodeBase_t __near * CTSListBase::Push(struct TSLNodeBase_t __near *)
// Source: json
//------------------------------------------------------------------------------
TSLNodeBase_t *__thiscall CTSListBase::Push(CTSListBase *this, TSLNodeBase_t *pNode)
{
  TSLNodeBase_t *Next; // edi
  TSLNodeBase_t *v5; // [esp-8h] [ebp-14h]
  int DepthAndSequence; // [esp-4h] [ebp-10h]
  int v7; // [esp-4h] [ebp-10h]

  Next = this->m_Head.value.Next;
  DepthAndSequence = this->m_Head.value32.DepthAndSequence;
  pNode->Next = this->m_Head.value.Next;
  if ( (unsigned __int8)_ThreadInterlockedAssignIf64(
                          a1: this,
                          a2: pNode,
                          a3: DepthAndSequence + 65537,
                          a4: Next,
                          a5: DepthAndSequence) == 0 )
  {
    do
    {
      _mm_pause();
      Next = this->m_Head.value.Next;
      v7 = this->m_Head.value32.DepthAndSequence;
      v5 = this->m_Head.value.Next;
      pNode->Next = this->m_Head.value.Next;
    }
    while ( (unsigned __int8)_ThreadInterlockedAssignIf64(a1: this, a2: pNode, a3: v7 + 65537, a4: v5, a5: v7) == 0 );
  }
  return Next;
}

//------------------------------------------------------------------------------
// Address: 0x1001C4D0
// Name: public: struct TSLNodeBase_t __near * CTSListBase::Pop(void)
// Source: json
//------------------------------------------------------------------------------
TSLNodeBase_t *__thiscall CTSListBase::Pop(CTSListBase *this)
{
  TSLNodeBase_t *Next; // esi
  int DepthAndSequence; // eax

  Next = this->m_Head.value.Next;
  DepthAndSequence = this->m_Head.value32.DepthAndSequence;
  if ( this->m_Head.value.Next == nullptr )
    return nullptr;
  while ( (unsigned __int8)_ThreadInterlockedAssignIf64(
                             a1: this,
                             a2: Next->Next,
                             a3: DepthAndSequence - 1,
                             a4: Next,
                             a5: DepthAndSequence) == 0 )
  {
    _mm_pause();
    Next = this->m_Head.value.Next;
    DepthAndSequence = this->m_Head.value32.DepthAndSequence;
    if ( this->m_Head.value.Next == nullptr )
      return nullptr;
  }
  return Next;
}

//------------------------------------------------------------------------------
// Address: 0x1001C510
// Name: public: struct TSLNodeBase_t __near * CTSListBase::Detach(void)
// Source: json
//------------------------------------------------------------------------------
TSLNodeBase_t *__thiscall CTSListBase::Detach(CTSListBase *this)
{
  TSLNodeBase_t *Next; // esi

  while ( 1 )
  {
    _mm_pause();
    Next = this->m_Head.value.Next;
    if ( this->m_Head.value.Next == nullptr )
      break;
    if ( (unsigned __int8)_ThreadInterlockedAssignIf64(
                            a1: this,
                            a2: 0,
                            a3: this->m_Head.value32.DepthAndSequence & 0xFFFF0000,
                            a4: Next,
                            a5: this->m_Head.value32.DepthAndSequence) != 0 )
      return Next;
  }
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1001C550
// Name: public: CVMPIPacketIDReg::CVMPIPacketIDReg(int,int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CVMPIPacketIDReg *__thiscall CVMPIPacketIDReg::CVMPIPacketIDReg(
        CVMPIPacketIDReg *this,
        int nPacketID,
        int nSubPacketID,
        const char *pName)
{
  CVMPIPacketIDReg *v5; // edx

  this->m_nPacketID = nPacketID;
  this->m_nSubPacketID = nSubPacketID;
  v5 = g_pVMPIPacketIDRegHead;
  this->m_pName = pName;
  this->m_pNext = v5;
  g_pVMPIPacketIDRegHead = this;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1001C580
// Name: public: static void CVMPIPacketIDReg::Lookup(int,int,char __near *,int,char __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CVMPIPacketIDReg::Lookup(
        int nPacketID,
        int nSubPacketID,
        char *pPacketIDString,
        int nPacketIDStringSize,
        char *pSubPacketIDString,
        int nSubPacketIDStringSize)
{
  CVMPIPacketIDReg *v6; // eax
  CVMPIPacketIDReg *v7; // eax

  v6 = g_pVMPIPacketIDRegHead;
  if ( g_pVMPIPacketIDRegHead != nullptr )
  {
    while ( v6->m_nPacketID != nPacketID || v6->m_nSubPacketID != -1 )
    {
      v6 = v6->m_pNext;
      if ( v6 == nullptr )
        goto LABEL_5;
    }
    V_strncpy(pDest: pPacketIDString, pSrc: v6->m_pName, maxLen: nPacketIDStringSize);
  }
  else
  {
LABEL_5:
    V_snprintf(pDest: pPacketIDString, maxLen: nPacketIDStringSize, pFormat: "(%d)", nPacketID);
  }
  v7 = g_pVMPIPacketIDRegHead;
  if ( g_pVMPIPacketIDRegHead != nullptr )
  {
    while ( v7->m_nPacketID != nPacketID || v7->m_nSubPacketID != nSubPacketID )
    {
      v7 = v7->m_pNext;
      if ( v7 == nullptr )
        goto LABEL_10;
    }
    V_strncpy(pDest: pSubPacketIDString, pSrc: v7->m_pName, maxLen: nSubPacketIDStringSize);
  }
  else
  {
LABEL_10:
    V_snprintf(pDest: pSubPacketIDString, maxLen: nSubPacketIDStringSize, pFormat: "(%d)", nSubPacketID);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001C620
// Name: void VMPI_SuperSpew(char const __near *,...)
// Source: json
//------------------------------------------------------------------------------
void VMPI_SuperSpew(const char *pMsg, ...)
{
  char str[2048]; // [esp+0h] [ebp-800h] BYREF
  va_list params; // [esp+80Ch] [ebp+Ch] BYREF

  va_start(params, pMsg);
  if ( g_bSuperSpewEnabled )
  {
    V_vsnprintf(pDest: str, maxLen: 0x800u, pFormat: pMsg, params);
    _Msg(a1: "%s", str);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001C670
// Name: public: virtual void CVMPILoggingListener::Log(struct LoggingContext_t const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVMPILoggingListener::Log(
        CVMPILoggingListener *this,
        const LoggingContext_t *pContext,
        const char *pMessage)
{
  VMPI_WriteToLogFile(pMsg: "%s", pMessage);
}

//------------------------------------------------------------------------------
// Address: 0x1001C690
// Name: char const __near * VMPI_FindArg(int,char __near * __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
char *__cdecl VMPI_FindArg(int argc, char **argv, const char *pName, const char *pDefault)
{
  int v4; // esi

  v4 = 0;
  if ( argc <= 0 )
    return nullptr;
  while ( _V_stricmp(s1: argv[v4], s2: pName) != 0 )
  {
    if ( ++v4 >= argc )
      return nullptr;
  }
  if ( v4 + 1 >= argc )
    return (char *)pDefault;
  else
    return argv[v4 + 1];
}

//------------------------------------------------------------------------------
// Address: 0x1001C6E0
// Name: void SetupDependencyFilename(class CDependencyInfo __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SetupDependencyFilename(CDependencyInfo *pInfo, const char *pPatchDirectory)
{
  HMODULE ModuleHandleA; // eax
  const char *v3; // eax
  char baseExeFilename[512]; // [esp+0h] [ebp-200h] BYREF

  ModuleHandleA = GetModuleHandleA(lpModuleName: nullptr);
  if ( GetModuleFileNameA(hModule: ModuleHandleA, lpFilename: baseExeFilename, nSize: 0x200u) == 0 )
    _Error(a1: "GetModuleFileName failed.");
  if ( pPatchDirectory != nullptr )
  {
    V_strncpy(pDest: pInfo->m_DependencyFilesDir, pSrc: pPatchDirectory, maxLen: 260);
  }
  else
  {
    V_strncpy(pDest: pInfo->m_DependencyFilesDir, pSrc: baseExeFilename, maxLen: 260);
    V_StripLastDir(dirName: pInfo->m_DependencyFilesDir, maxlen: 0x104u);
  }
  v3 = V_UnqualifiedFileName(in: baseExeFilename);
  V_strncpy(pDest: pInfo->m_OriginalExeFilename, pSrc: v3, maxLen: 260);
}

//------------------------------------------------------------------------------
// Address: 0x1001C780
// Name: public: void CMasterBroadcaster::Term(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMasterBroadcaster::Term(CMasterBroadcaster *this)
{
  ISocket *m_pSocket; // ecx
  ITCPConnectSocket *m_pDownloaderListenSocket; // ecx

  if ( this->m_hThread != nullptr )
  {
    CEvent::SetEvent(this: &this->m_hShutdownEvent);
    WaitForSingleObject(hHandle: this->m_hThread, dwMilliseconds: 0xFFFFFFFF);
    CloseHandle(hObject: this->m_hThread);
    this->m_hThread = nullptr;
  }
  m_pSocket = this->m_pSocket;
  if ( m_pSocket != nullptr )
  {
    m_pSocket->Release(this: m_pSocket);
    this->m_pSocket = nullptr;
  }
  if ( this->m_pListenSocket != nullptr )
  {
    this->m_pListenSocket->Release(this: this->m_pListenSocket);
    this->m_pListenSocket = nullptr;
  }
  m_pDownloaderListenSocket = this->m_pDownloaderListenSocket;
  if ( m_pDownloaderListenSocket != nullptr )
  {
    m_pDownloaderListenSocket->Release(this: m_pDownloaderListenSocket);
    this->m_pDownloaderListenSocket = nullptr;
  }
  this->m_iDownloaderListenPort = -1;
  this->m_iListenPort = -1;
}

//------------------------------------------------------------------------------
// Address: 0x1001C810
// Name: public: CDispatchReg::CDispatchReg(int,bool (*)(class MessageBuffer __near *,int,int))
// Source: json
//------------------------------------------------------------------------------
CDispatchReg *__thiscall CDispatchReg::CDispatchReg(
        CDispatchReg *this,
        int iPacketID,
        bool (__cdecl *fn)(MessageBuffer *, int, int))
{
  g_VMPIDispatch[iPacketID] = fn;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1001C830
// Name: bool VMPI_CheckForNonSDKExecutables(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl VMPI_CheckForNonSDKExecutables()
{
  HMODULE ModuleHandleA; // eax
  char baseExeFilename[512]; // [esp+0h] [ebp-200h] BYREF

  ModuleHandleA = GetModuleHandleA(lpModuleName: nullptr);
  if ( GetModuleFileNameA(hModule: ModuleHandleA, lpFilename: baseExeFilename, nSize: 0x200u) == 0 )
    _Error(a1: "VMPI_CheckSDKMode -> GetModuleFileName failed.");
  V_StripLastDir(dirName: baseExeFilename, maxlen: 0x200u);
  V_AppendSlash(pStr: baseExeFilename, strSize: 512);
  V_strncat(pDest: baseExeFilename, pSrc: "mysql_wrapper.dll", destBufferSize: 0x200u, max_chars_to_copy: -1);
  return access(path: baseExeFilename, amode: 0) == 0;
}

//------------------------------------------------------------------------------
// Address: 0x1001C8C0
// Name: enum VMPIRunMode VMPI_GetRunMode(void)
// Source: json
//------------------------------------------------------------------------------
VMPIRunMode __cdecl VMPI_GetRunMode()
{
  return g_VMPIRunMode;
}

//------------------------------------------------------------------------------
// Address: 0x1001C8D0
// Name: enum VMPIFileSystemMode VMPI_GetFileSystemMode(void)
// Source: json
//------------------------------------------------------------------------------
VMPIFileSystemMode __cdecl VMPI_GetFileSystemMode()
{
  return g_VMPIFileSystemMode;
}

//------------------------------------------------------------------------------
// Address: 0x1001C8E0
// Name: int VMPI_GetCurrentNumberOfConnections(void)
// Source: json
//------------------------------------------------------------------------------
int __cdecl VMPI_GetCurrentNumberOfConnections()
{
  return g_nConnections;
}

//------------------------------------------------------------------------------
// Address: 0x1001C8F0
// Name: bool VMPI_FilterPacketsForServiceDownloader(class CVMPIConnection __near *,void const __near * const __near *,int const __near *,int)
// Source: json
//------------------------------------------------------------------------------
char __cdecl VMPI_FilterPacketsForServiceDownloader(
        CVMPIConnection *pConnection,
        const void *const *pChunks,
        const int *pChunkLengths,
        int nChunks)
{
  int v4; // eax
  int v5; // ecx
  unsigned __int8 *v7; // eax
  unsigned __int8 v8; // dl
  int v9; // eax
  char szPacketID[64]; // [esp+4h] [ebp-80h] BYREF
  char szSubPacketID[64]; // [esp+44h] [ebp-40h] BYREF

  if ( !pConnection->m_bIsAService )
    return 0;
  v4 = 0;
  if ( nChunks <= 0 )
    return 0;
  while ( 1 )
  {
    v5 = pChunkLengths[v4];
    if ( v5 >= 1 )
      break;
    if ( ++v4 >= nChunks )
      return 0;
  }
  v7 = (unsigned __int8 *)pChunks[v4];
  v8 = *v7;
  if ( *v7 == 27 || v8 == 10 || v8 == 0 )
    return 0;
  if ( g_bSuperSpewEnabled )
  {
    if ( v5 < 2 )
      v9 = -1;
    else
      v9 = v7[1];
    CVMPIPacketIDReg::Lookup(
      nPacketID: v8,
      nSubPacketID: v9,
      pPacketIDString: szPacketID,
      nPacketIDStringSize: 64,
      pSubPacketIDString: szSubPacketID,
      nSubPacketIDStringSize: 64);
    VMPI_SuperSpew(
      pMsg: "VMPI_FilterPacketsForServiceDownloader filtered packetID %s, subPacketID %s\n",
      szPacketID,
      szSubPacketID);
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1001C990
// Name: bool VMPI_IsProcValid(int)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl VMPI_IsProcValid(int procID)
{
  return procID >= 0 && procID < g_nConnections && g_Connections[procID] != nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1001C9C0
// Name: bool VMPI_IsProcConnected(int)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl VMPI_IsProcConnected(int procID)
{
  CVMPIConnection *v1; // eax

  return procID >= 0 && procID < g_nConnections && (v1 = g_Connections[procID]) != nullptr && v1->m_pSocket != nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1001C9F0
// Name: void VMPI_Sleep(unsigned long)
// Source: json
//------------------------------------------------------------------------------
void __cdecl VMPI_Sleep(DWORD ms)
{
  Sleep(dwMilliseconds: ms);
}

//------------------------------------------------------------------------------
// Address: 0x1001CA00
// Name: char const __near * VMPI_GetLocalMachineName(void)
// Source: json
//------------------------------------------------------------------------------
char *__cdecl VMPI_GetLocalMachineName()
{
  bool v0; // zf
  char *result; // eax
  unsigned int len; // [esp+0h] [ebp-4h] BYREF

  len = 16;
  v0 = !GetComputerNameA(lpBuffer: cName, nSize: &len);
  result = cName;
  if ( v0 )
    return "(error in GetComputerName)";
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1001CA30
// Name: bool VMPI_IsSDKMode(void)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl VMPI_IsSDKMode()
{
  if ( g_bVMPISDKModeSet )
    return g_bVMPISDKMode;
  else
    return !VMPI_CheckForNonSDKExecutables();
}

//------------------------------------------------------------------------------
// Address: 0x1001CA50
// Name: char const __near * VMPI_GetParamString(enum EVMPICmdLineParam)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl VMPI_GetParamString(EVMPICmdLineParam eParam)
{
  if ( (unsigned int)(eParam - 1) <= 0x19 )
    return g_VMPIParams[eParam].m_pName;
  _Warning(a1: "Invalid call: VMPI_GetParamString( %d )\n", eParam);
  return "unknown";
}

//------------------------------------------------------------------------------
// Address: 0x1001CA80
// Name: bool VMPI_IsParamUsed(enum EVMPICmdLineParam)
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl VMPI_IsParamUsed(EVMPICmdLineParam eParam)
{
  int v1; // esi

  v1 = _CommandLine();
  if ( (unsigned int)(eParam - 1) <= 0x19 )
    return (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v1 + 40))(a1: v1, a2: g_VMPIParams[eParam].m_pName) != 0;
  _Warning(a1: "Invalid call: VMPI_GetParamString( %d )\n", eParam);
  return (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v1 + 40))(a1: v1, a2: "unknown") != 0;
}

//------------------------------------------------------------------------------
// Address: 0x1001CB80
// Name: void ParseOptions(int,char __near * __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ParseOptions(int argc, char **argv)
{
  char *Arg; // eax
  char *v3; // eax
  char v4; // al

  if ( VMPI_FindArg(argc, argv, pName: g_VMPIParams[18].m_pName, pDefault: setName) != nullptr )
    ThreadedTCP_EnableTimeouts(bEnable: false);
  if ( VMPI_FindArg(argc, argv, pName: g_VMPIParams[19].m_pName, pDefault: setName) != nullptr )
  {
    _Msg(a1: "%s found.\n", g_VMPIParams[19].m_pName);
    g_bSetThreadPriorities = false;
    ThreadedTCP_SetTCPSocketThreadPriorities(bSetTCPSocketThreadPriorities: false);
  }
  if ( VMPI_FindArg(argc, argv, pName: g_VMPIParams[20].m_pName, pDefault: setName) != nullptr )
  {
    _Msg(a1: "%s found.\n", g_VMPIParams[20].m_pName);
    g_bGroupPackets = true;
  }
  Arg = VMPI_FindArg(argc, argv, pName: g_VMPIParams[12].m_pName, pDefault: "1");
  if ( Arg != nullptr )
    MULTICAST_TRANSMIT_RATE = atoi(nptr: Arg) << 10;
  v3 = VMPI_FindArg(argc, argv, pName: g_VMPIParams[13].m_pName, pDefault: "1");
  if ( v3 != nullptr )
  {
    v4 = *v3;
    if ( v4 == 49 )
    {
      g_iVMPIVerboseLevel = 1;
    }
    else if ( v4 == 50 )
    {
      g_iVMPIVerboseLevel = 2;
    }
  }
  if ( VMPI_FindArg(argc, argv, pName: g_VMPIParams[21].m_pName, pDefault: setName) != nullptr )
    g_bMPI_Stats = true;
  if ( VMPI_FindArg(argc, argv, pName: g_VMPIParams[22].m_pName, pDefault: setName) != nullptr )
    g_bMPI_StatsTextOutput = true;
}

//------------------------------------------------------------------------------
// Address: 0x1001CCD0
// Name: void CountActiveConnections(int __near *,int __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CountActiveConnections(int *nRegularWorkers, int *nServiceDownloaders)
{
  int v2; // ebx
  int i; // ecx
  CVMPIConnection *v4; // eax

  *nServiceDownloaders = 0;
  *nRegularWorkers = 0;
  v2 = g_nConnections;
  for ( i = 0; i < v2; ++i )
  {
    if ( i >= 0 && i < g_nConnections )
    {
      v4 = g_Connections[i];
      if ( v4 != nullptr && v4->m_pSocket != nullptr )
      {
        if ( v4->m_bIsAService )
          ++*nServiceDownloaders;
        else
          ++*nRegularWorkers;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001CD30
// Name: void UpdateActiveConnectionsText(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl UpdateActiveConnectionsText()
{
  HWND v0; // esi
  char str[512]; // [esp+0h] [ebp-208h] BYREF
  int nDownloaders; // [esp+200h] [ebp-8h] BYREF
  int nRegularWorkers; // [esp+204h] [ebp-4h] BYREF

  if ( g_bMPIMaster && g_pConsoleWndFn != nullptr )
  {
    v0 = g_pConsoleWndFn();
    if ( v0 != nullptr )
    {
      CountActiveConnections(&nRegularWorkers, nServiceDownloaders: &nDownloaders);
      if ( g_bVMPISDKMode )
        V_snprintf(pDest: str, maxLen: 0x200u, pFormat: "VMPI (SDK) - Workers: %d", nRegularWorkers);
      else
        V_snprintf(
          pDest: str,
          maxLen: 0x200u,
          pFormat: "VMPI - Workers: %d, Downloaders: %d",
          nRegularWorkers,
          nDownloaders);
      SetWindowTextA(hWnd: v0, lpString: str);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001CDD0
// Name: bool SpawnLocalWorker(int,char __near * __near *,int,bool)
// Source: json
//------------------------------------------------------------------------------
char __cdecl SpawnLocalWorker(int argc, char **argv, int iListenPort, bool bShowConsoleWindow)
{
  int i; // ebx
  const char *m_pName; // edi
  int v7; // esi
  char CommandLine[4096]; // [esp+Ch] [ebp-1854h] BYREF
  char pnbuf[1024]; // [esp+100Ch] [ebp-854h] BYREF
  char pStr[512]; // [esp+140Ch] [ebp-454h] BYREF
  char pDest[512]; // [esp+160Ch] [ebp-254h] BYREF
  _STARTUPINFOA dst; // [esp+180Ch] [ebp-54h] BYREF
  _PROCESS_INFORMATION ProcessInformation; // [esp+1850h] [ebp-10h] BYREF

  CommandLine[0] = 0;
  for ( i = 0; i < 9999999; ++i )
  {
    if ( i == 1 )
    {
      V_snprintf(pDest, maxLen: 0x200u, pFormat: "-mpi_worker 127.0.0.1:%d ", iListenPort);
      V_strncat(pDest: CommandLine, pSrc: pDest, destBufferSize: 0x1000u, max_chars_to_copy: -1);
      V_strncat(pDest: CommandLine, pSrc: "-allowdebug ", destBufferSize: 0x1000u, max_chars_to_copy: -1);
      if ( g_bVMPISDKModeSet ? g_bVMPISDKMode : !VMPI_CheckForNonSDKExecutables() )
      {
        m_pName = g_VMPIParams[15].m_pName;
        v7 = 0;
        if ( argc <= 0 )
          goto LABEL_13;
        while ( _V_stricmp(s1: argv[v7], s2: m_pName) != 0 )
        {
          if ( ++v7 >= argc )
            goto LABEL_13;
        }
        if ( v7 + 1 < argc && argv[v7 + 1] == nullptr )
LABEL_13:
          V_strncat(pDest: CommandLine, pSrc: g_VMPIParams[15].m_pName, destBufferSize: 0x1000u, max_chars_to_copy: -1);
      }
    }
    if ( i >= argc )
      break;
    V_snprintf(pDest, maxLen: 0x200u, pFormat: "\"%s\" ", argv[i]);
    V_strncat(pDest: CommandLine, pSrc: pDest, destBufferSize: 0x1000u, max_chars_to_copy: -1);
  }
  if ( _getcwd(pnbuf, maxlen: 1024) != nullptr )
  {
    memset((int)&dst, value: nullptr, count: sizeof(dst));
    dst.cb = 68;
    memset(&ProcessInformation, 0, sizeof(ProcessInformation));
    if ( CreateProcessA(
           lpApplicationName: nullptr,
           lpCommandLine: CommandLine,
           lpProcessAttributes: nullptr,
           lpThreadAttributes: nullptr,
           bInheritHandles: true,
           dwCreationFlags: (bShowConsoleWindow ? 16 : 0x8000000) | 0x40,
           lpEnvironment: nullptr,
           lpCurrentDirectory: pnbuf,
           lpStartupInfo: &dst,
           lpProcessInformation: &ProcessInformation) )
    {
      return 1;
    }
    else
    {
      IP_GetLastErrorString(pStr, maxLen: 1024);
      _Warning(a1: " - ERROR in CreateProcess (%s)!\n", pStr);
      return 0;
    }
  }
  else
  {
    _Warning(a1: "_getcwd() failed.\n");
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001D080
// Name: private: void CMasterBroadcaster::BuildBroadcastPacket(class bf_write __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMasterBroadcaster::BuildBroadcastPacket(CMasterBroadcaster *this, bf_write *buf)
{
  bf_write *v2; // esi
  bool v4; // zf
  const char *v5; // eax
  int i; // ebx

  v2 = buf;
  bf_write::WriteByte(this: buf, val: 5u);
  bf_write::WriteString(this: v2, pStr: this->m_BroadcastInfo.m_Password);
  if ( this->m_BroadcastInfo.m_PatchVersion[0] != 0 )
    bf_write::WriteByte(this: v2, val: 0x4Fu);
  else
    bf_write::WriteByte(this: v2, val: 0x47u);
  bf_write::WriteString(this: v2, pStr: this->m_BroadcastInfo.m_PatchVersion);
  bf_write::WriteLong(this: v2, val: this->m_iListenPort);
  bf_write::WriteLong(this: v2, val: this->m_BroadcastInfo.m_JobID[0]);
  bf_write::WriteLong(this: v2, val: this->m_BroadcastInfo.m_JobID[1]);
  bf_write::WriteLong(this: v2, val: this->m_BroadcastInfo.m_JobID[2]);
  bf_write::WriteLong(this: v2, val: this->m_BroadcastInfo.m_JobID[3]);
  bf_write::WriteWord(this: v2, val: this->m_BroadcastInfo.m_Args.m_Size + 2);
  bf_write::WriteString(this: v2, pStr: this->m_BroadcastInfo.m_WorkerExeFilename);
  bf_write::WriteString(this: v2, pStr: "-mpi_MasterName");
  buf = (bf_write *)16;
  v4 = !GetComputerNameA(lpBuffer: cName, nSize: (LPDWORD)&buf);
  v5 = cName;
  if ( v4 )
    v5 = "(error in GetComputerName)";
  bf_write::WriteString(this: v2, pStr: v5);
  for ( i = 1; i < this->m_BroadcastInfo.m_Args.m_Size; ++i )
    bf_write::WriteString(this: v2, pStr: this->m_BroadcastInfo.m_Args.m_Memory.m_pMemory[i]);
  bf_write::WriteByte(this: v2, val: 1u);
  bf_write::WriteShort(this: v2, val: this->m_iDownloaderListenPort);
}

//------------------------------------------------------------------------------
// Address: 0x1001D1A0
// Name: bool IsValidSDKBinPath(class CUtlVector<char __near *,class CUtlMemory<char __near *,int>> __near &,int __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl IsValidSDKBinPath(CUtlVector<char *,CUtlMemory<char *,int> > *outStrings, int *pError)
{
  int m_Size; // eax
  int i; // edi
  int j; // edi
  char mapsrcFilename[260]; // [esp+8h] [ebp-54Ch] BYREF
  char blobPath[260]; // [esp+10Ch] [ebp-448h] BYREF
  char tempFilename[260]; // [esp+210h] [ebp-344h] BYREF
  char baseSteamPath[260]; // [esp+314h] [ebp-240h] BYREF
  char sourcesdkContentPath[260]; // [esp+418h] [ebp-13Ch] BYREF
  _stat64i32 results; // [esp+51Ch] [ebp-38h] BYREF
  __int64 curTime; // [esp+54Ch] [ebp-8h] BYREF

  *pError = 0;
  m_Size = outStrings->m_Size;
  if ( m_Size >= 9 )
  {
    if ( _V_stricmp(s1: outStrings->m_Memory.m_pMemory[m_Size - 2], s2: "bin") != 0 )
    {
      *pError = 1;
      return 0;
    }
    else if ( _V_stricmp(s1: outStrings->m_Memory.m_pMemory[outStrings->m_Size - 5], s2: "sourcesdk") != 0 )
    {
      *pError = 2;
      return 0;
    }
    else if ( _V_stricmp(s1: outStrings->m_Memory.m_pMemory[outStrings->m_Size - 7], s2: "steamapps") != 0 )
    {
      *pError = 3;
      return 0;
    }
    else
    {
      V_strncpy(pDest: baseSteamPath, pSrc: *(const char **)outStrings->m_Memory.m_pMemory, maxLen: 260);
      for ( i = 1; i < outStrings->m_Size - 7; ++i )
      {
        V_AppendSlash(pStr: baseSteamPath, strSize: 260);
        V_strncat(
          pDest: baseSteamPath,
          pSrc: outStrings->m_Memory.m_pMemory[i],
          destBufferSize: 0x104u,
          max_chars_to_copy: -1);
      }
      V_ComposeFileName(path: baseSteamPath, filename: "ClientRegistry.blob", dest: blobPath, destSize: 260);
      if ( _stat64i32(name: blobPath, buf: &results) != 0 )
      {
        *pError = 4;
        return 0;
      }
      else
      {
        _time64(timeptr: &curTime);
        if ( (int)curTime - LODWORD(results.st_mtime) <= 864000 )
        {
          V_strncpy(pDest: sourcesdkContentPath, pSrc: *(const char **)outStrings->m_Memory.m_pMemory, maxLen: 260);
          for ( j = 1; j < outStrings->m_Size - 5; ++j )
          {
            V_AppendSlash(pStr: sourcesdkContentPath, strSize: 260);
            V_strncat(
              pDest: sourcesdkContentPath,
              pSrc: outStrings->m_Memory.m_pMemory[j],
              destBufferSize: 0x104u,
              max_chars_to_copy: -1);
          }
          V_AppendSlash(pStr: sourcesdkContentPath, strSize: 260);
          V_strncat(
            pDest: sourcesdkContentPath,
            pSrc: "sourcesdk_content",
            destBufferSize: 0x104u,
            max_chars_to_copy: -1);
          V_snprintf(pDest: tempFilename, maxLen: 0x104u, pFormat: "cstrike%cmapsrc", 92);
          V_ComposeFileName(path: sourcesdkContentPath, filename: tempFilename, dest: mapsrcFilename, destSize: 260);
          if ( access(path: mapsrcFilename, amode: 0) != 0 )
          {
            *pError = 6;
            return 0;
          }
          else
          {
            return 1;
          }
        }
        else
        {
          *pError = 5;
          return 0;
        }
      }
    }
  }
  else
  {
    *pError = 0;
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001D420
// Name: void VerifyValidSDKMode(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl VerifyValidSDKMode()
{
  HMODULE ModuleHandleA; // eax
  char baseExeFilename[260]; // [esp+4h] [ebp-124h] BYREF
  CSplitString outStrings; // [esp+108h] [ebp-20h] BYREF
  int err; // [esp+120h] [ebp-8h] BYREF
  char strSlash[4]; // [esp+124h] [ebp-4h] BYREF

  ModuleHandleA = GetModuleHandleA(lpModuleName: nullptr);
  if ( GetModuleFileNameA(hModule: ModuleHandleA, lpFilename: baseExeFilename, nSize: 0x104u) == 0 )
    _Error(a1: "VerifyValidSDKMode: GetModuleFileName failed.");
  V_FixSlashes(pname: baseExeFilename, separator: 92);
  strcpy(strSlash, "\\");
  CSplitString::CSplitString(this: &outStrings, pString: baseExeFilename, pSeparator: strSlash);
  if ( IsValidSDKBinPath(&outStrings, pError: &err) == 0 )
  {
    if ( err == 5 )
    {
      _Error(a1: "VMPI running in SDK mode but Steam hasn't been run recently. Please run Steam and retry.");
      CSplitString::~CSplitString(this: &outStrings);
      return;
    }
    _Error(a1: "VMPI running in SDK mode but incorrect SDK install detected (error %d).", err);
  }
  CSplitString::~CSplitString(this: &outStrings);
}

//------------------------------------------------------------------------------
// Address: 0x1001D4D0
// Name: void VMPI_CheckSDKMode(int,char __near * __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl VMPI_CheckSDKMode(int argc, char **argv)
{
  bool v2; // al

  if ( g_bIsRunningVMPITransfer )
  {
    g_bVMPISDKMode = false;
    g_bVMPISDKModeSet = true;
    return;
  }
  v2 = VMPI_CheckForNonSDKExecutables();
  g_bVMPISDKMode = !v2;
  g_bVMPISDKModeSet = true;
  if ( v2 )
  {
    if ( VMPI_FindArg(argc, argv, pName: g_VMPIParams[15].m_pName, pDefault: setName) != nullptr )
    {
      g_bVMPISDKMode = true;
    }
    else if ( !g_bVMPISDKMode )
    {
      return;
    }
  }
  VerifyValidSDKMode();
  if ( g_bVMPISDKMode )
    _Msg(a1: "VMPI running in SDK mode.\n");
}

//------------------------------------------------------------------------------
// Address: 0x1001D560
// Name: char const __near * VMPI_GetMachineName(int)
// Source: json
//------------------------------------------------------------------------------
char *__cdecl VMPI_GetMachineName(int iProc)
{
  bool v1; // sf
  bool v2; // zf
  char *result; // eax
  CVMPIConnection *v4; // eax
  unsigned int nSize; // [esp+0h] [ebp-4h] BYREF

  if ( g_bMPIMaster )
  {
    v1 = iProc < 0;
    if ( iProc == 0 )
    {
      nSize = 16;
      v2 = !GetComputerNameA(lpBuffer: cName, &nSize);
      result = cName;
      if ( v2 )
        return "(error in GetComputerName)";
      return result;
    }
  }
  else
  {
    v1 = iProc < 0;
  }
  if ( v1 )
    return "invalid index";
  if ( iProc >= g_nConnections )
    return "invalid index";
  v4 = g_Connections[iProc];
  if ( v4 == nullptr )
    return "invalid index";
  else
    return v4->m_MachineName.m_Memory.m_pMemory;
}

//------------------------------------------------------------------------------
// Address: 0x1001D9B0
// Name: public: void CVMPIConnection::HandleDisconnect(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVMPIConnection::HandleDisconnect(CVMPIConnection *this)
{
  int m_Head; // esi
  UtlLinkedListElem_t<void (__cdecl*)(int,char const *),int> *m_pMemory; // eax
  int v4; // esi
  char str[512]; // [esp+4h] [ebp-208h] BYREF
  CCriticalSectionLock csLock; // [esp+204h] [ebp-8h] BYREF

  if ( this->m_pSocket != nullptr )
  {
    CCriticalSectionLock::CCriticalSectionLock(this: &csLock, pCS: &g_ErrorSocketsCS);
    CCriticalSectionLock::Lock(this: &csLock);
    V_strncpy(pDest: str, pSrc: this->m_ErrorString.m_Memory.m_pMemory, maxLen: 512);
    CCriticalSectionLock::Unlock(this: &csLock);
    m_Head = g_DisconnectHandlers.m_Head;
    if ( g_DisconnectHandlers.m_Head != -1 )
    {
      m_pMemory = g_DisconnectHandlers.m_Memory.m_pMemory;
      do
      {
        v4 = m_Head;
        m_pMemory[v4].m_Element(a1: this->m_iConnection, a2: str);
        m_pMemory = g_DisconnectHandlers.m_Memory.m_pMemory;
        m_Head = g_DisconnectHandlers.m_Memory.m_pMemory[v4].m_Next;
      }
      while ( m_Head != -1 );
    }
    this->m_pSocket->Release(this: this->m_pSocket);
    this->m_pSocket = nullptr;
    CCriticalSectionLock::~CCriticalSectionLock(this: &csLock);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001DA60
// Name: bool VMPI_HandleAutoRestart(void)
// Source: json
//------------------------------------------------------------------------------
char __usercall VMPI_HandleAutoRestart@<al>(int a1@<ebp>)
{
  void *v1; // esp
  HANDLE CurrentProcess; // eax
  int v3; // esi
  DWORD PriorityClass; // edi
  char **m_pMemory; // eax
  char v7[8192]; // [esp-2458h] [ebp-2464h] BYREF
  char v8[512]; // [esp-458h] [ebp-464h] BYREF
  char v9[512]; // [esp-258h] [ebp-264h] BYREF
  _STARTUPINFOA v10; // [esp-58h] [ebp-64h] BYREF
  _PROCESS_INFORMATION v11; // [esp-10h] [ebp-1Ch] BYREF
  int v12; // [esp+0h] [ebp-Ch]
  void *v13; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v12 = a1;
  v13 = retaddr;
  v1 = alloca(9304);
  if ( g_OriginalCommandLineParameters.m_Size == 0 )
    return 1;
  _Msg(a1: "%s found. Auto-restarting.\n", g_VMPIParams[6].m_pName);
  CurrentProcess = GetCurrentProcess();
  v3 = 0;
  PriorityClass = GetPriorityClass(hProcess: CurrentProcess);
  for ( v7[0] = 0; v3 < g_OriginalCommandLineParameters.m_Size; ++v3 )
  {
    V_snprintf(pDest: v9, maxLen: 0x200u, pFormat: "\"%s\" ", g_OriginalCommandLineParameters.m_Memory.m_pMemory[v3]);
    V_strncat(pDest: v7, pSrc: v9, destBufferSize: 0x2000u, max_chars_to_copy: -1);
  }
  memset(dst: (int)&v10, value: nullptr, count: sizeof(v10));
  v10.cb = 68;
  v11 = 0;
  if ( CreateProcessA(
         lpApplicationName: nullptr,
         lpCommandLine: v7,
         lpProcessAttributes: nullptr,
         lpThreadAttributes: nullptr,
         bInheritHandles: true,
         dwCreationFlags: PriorityClass | 0x10,
         lpEnvironment: nullptr,
         lpCurrentDirectory: nullptr,
         lpStartupInfo: &v10,
         lpProcessInformation: &v11) )
  {
    m_pMemory = g_OriginalCommandLineParameters.m_Memory.m_pMemory;
    g_OriginalCommandLineParameters.m_Size = 0;
    if ( g_OriginalCommandLineParameters.m_Memory.m_nGrowSize >= 0 )
    {
      if ( g_OriginalCommandLineParameters.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: g_OriginalCommandLineParameters.m_Memory.m_pMemory);
        m_pMemory = nullptr;
        g_OriginalCommandLineParameters.m_Memory.m_pMemory = nullptr;
      }
      g_OriginalCommandLineParameters.m_Memory.m_nAllocationCount = 0;
    }
    g_OriginalCommandLineParameters.m_pElements = m_pMemory;
    return 1;
  }
  IP_GetLastErrorString(pStr: v8, maxLen: 1024);
  _Warning(a1: " - ERROR in CreateProcess (%s)!\n", v8);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1001DBD0
// Name: void VMPI_FlushGroupedPackets(unsigned long)
// Source: json
//------------------------------------------------------------------------------
void __cdecl VMPI_FlushGroupedPackets(unsigned int msInterval)
{
  int v1; // eax
  int i; // ebx
  CVMPIConnection *v3; // esi
  IThreadedTCPSocket *m_pSocket; // ecx
  int j; // edi
  CCriticalSectionLock connectionsLock; // [esp+4h] [ebp-8h] BYREF

  if ( msInterval != 0 )
  {
    v1 = _Plat_MSTime();
    if ( v1 - g_LastFlushGroupedPacketsTime < msInterval )
      return;
    g_LastFlushGroupedPacketsTime = v1;
  }
  CCriticalSectionLock::CCriticalSectionLock(this: &connectionsLock, pCS: &g_ConnectionsCS);
  CCriticalSectionLock::Lock(this: &connectionsLock);
  for ( i = 0; i < g_nConnections; ++i )
  {
    v3 = g_Connections[i];
    if ( v3 != nullptr )
    {
      m_pSocket = v3->m_pSocket;
      if ( m_pSocket != nullptr && v3->m_GroupedChunks.m_Size != 0 )
      {
        m_pSocket->SendChunks(
          this: m_pSocket,
          a2: (const void *const *)v3->m_GroupedChunks.m_Memory.m_pMemory,
          a3: v3->m_GroupedChunkLengths.m_Memory.m_pMemory,
          a4: v3->m_GroupedChunks.m_Size);
        for ( j = 1; j < v3->m_GroupedChunks.m_Size; ++j )
          free(pMem: v3->m_GroupedChunks.m_Memory.m_pMemory[j]);
        v3->m_GroupedChunks.m_Size = 0;
        v3->m_GroupedChunkLengths.m_Size = 0;
      }
    }
  }
  CCriticalSectionLock::~CCriticalSectionLock(this: &connectionsLock);
}

//------------------------------------------------------------------------------
// Address: 0x1001DE20
// Name: public: void CMasterBroadcaster::SetNoTimeoutOption(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMasterBroadcaster::SetNoTimeoutOption(CMasterBroadcaster *this)
{
  int v2; // edi
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  const char *m_pName; // edi
  char **m_pMemory; // eax
  int v7; // ecx
  char **v8; // esi
  CCriticalSectionLock connectionsLock; // [esp+8h] [ebp-8h] BYREF

  CCriticalSectionLock::CCriticalSectionLock(this: &connectionsLock, pCS: &g_ConnectionsCS);
  CCriticalSectionLock::Lock(this: &connectionsLock);
  v2 = 1;
  if ( this->m_BroadcastInfo.m_Args.m_Size <= 1 )
  {
LABEL_4:
    m_Size = this->m_BroadcastInfo.m_Args.m_Size;
    m_nAllocationCount = this->m_BroadcastInfo.m_Args.m_Memory.m_nAllocationCount;
    m_pName = g_VMPIParams[18].m_pName;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<int,int>::Grow(
        this: (CUtlMemory<CTCPPacket *,int> *)&this->m_BroadcastInfo.m_Args,
        num: m_Size - m_nAllocationCount + 1);
    ++this->m_BroadcastInfo.m_Args.m_Size;
    m_pMemory = this->m_BroadcastInfo.m_Args.m_Memory.m_pMemory;
    v7 = this->m_BroadcastInfo.m_Args.m_Size - 2;
    this->m_BroadcastInfo.m_Args.m_pElements = m_pMemory;
    if ( v7 > 0 )
      _V_memmove(dest: (unsigned __int8 *)m_pMemory + 8, src: (unsigned __int8 *)m_pMemory + 4, count: 4 * v7);
    v8 = this->m_BroadcastInfo.m_Args.m_Memory.m_pMemory + 1;
    if ( v8 != nullptr )
      *v8 = (char *)m_pName;
  }
  else
  {
    while ( _V_stricmp(s1: this->m_BroadcastInfo.m_Args.m_Memory.m_pMemory[v2], s2: g_VMPIParams[18].m_pName) != 0 )
    {
      if ( ++v2 >= this->m_BroadcastInfo.m_Args.m_Size )
        goto LABEL_4;
    }
  }
  CCriticalSectionLock::~CCriticalSectionLock(this: &connectionsLock);
}

//------------------------------------------------------------------------------
// Address: 0x1001DEF0
// Name: void VMPI_InviteDebugWorkers(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl VMPI_InviteDebugWorkers()
{
  int v0; // eax
  CCriticalSectionLock v1; // [esp+0h] [ebp-8h] BYREF

  CCriticalSectionLock::CCriticalSectionLock(this: &v1, pCS: &g_ConnectionsCS);
  CCriticalSectionLock::Lock(this: &v1);
  V_strncpy(pDest: g_MasterBroadcaster.m_BroadcastInfo.m_Password, pSrc: "debugworker", maxLen: 256);
  CCriticalSectionLock::~CCriticalSectionLock(this: &v1);
  CMasterBroadcaster::SetNoTimeoutOption(this: &g_MasterBroadcaster);
  ThreadedTCP_EnableTimeouts(bEnable: false);
  CCriticalSectionLock::CCriticalSectionLock(this: &v1, pCS: &g_ConnectionsCS);
  CCriticalSectionLock::Lock(this: &v1);
  v0 = g_MasterBroadcaster.m_nMaxWorkers + 25;
  g_MasterBroadcaster.m_nMaxWorkers = 512;
  if ( v0 <= 512 )
    g_MasterBroadcaster.m_nMaxWorkers = v0;
  CCriticalSectionLock::~CCriticalSectionLock(this: &v1);
}

//------------------------------------------------------------------------------
// Address: 0x1001E0E0
// Name: void ParseDependencyFile(class CDependencyInfo __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ParseDependencyFile(CDependencyInfo *pInfo, char *pDepFilename)
{
  _iobuf *v2; // esi
  int v3; // eax
  char v4; // cl
  bool v5; // zf
  char *v6; // eax
  CDependencyInfo::CDependencyFile *v7; // edi
  char v8; // bl
  char *v9; // eax
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CDependencyInfo::CDependencyFile **m_pMemory; // ecx
  int v13; // eax
  CDependencyInfo::CDependencyFile **v14; // eax
  char fullFilename[260]; // [esp+Ch] [ebp-210h] BYREF
  char tempStr[260]; // [esp+110h] [ebp-10Ch] BYREF
  _iobuf *fp; // [esp+214h] [ebp-8h]
  CDependencyInfo::CDependencyFile *pFile; // [esp+218h] [ebp-4h]

  fp = fopen(file: (_iobuf *)pDepFilename, mode: "rt");
  if ( fp == nullptr )
    _Error(a1: "Can't find %s.", pDepFilename);
  while ( 1 )
  {
    v2 = fp;
    if ( fgets(string: (_iobuf *)tempStr, count: 260, str: fp) == nullptr || tempStr[0] == 0 )
      break;
    v3 = &tempStr[strlen(tempStr) + 1] - &tempStr[1];
    v5 = fullFilename[v3 + 259] == 10;
    v6 = &fullFilename[v3 + 259];
    if ( v5 )
      *v6 = v4;
    v7 = (CDependencyInfo::CDependencyFile *)operator new(nSize: 0x104u);
    pFile = v7;
    v8 = 0;
    strstr(str1: (unsigned __int8 *)tempStr, str2: "optional ");
    if ( v9 == tempStr )
    {
      v8 = 1;
      V_strncpy(pDest: v7->m_Name, pSrc: &tempStr[9], maxLen: 260);
    }
    else
    {
      V_strncpy(pDest: v7->m_Name, pSrc: tempStr, maxLen: 260);
    }
    V_ComposeFileName(path: pInfo->m_DependencyFilesDir, filename: v7->m_Name, dest: fullFilename, destSize: 260);
    if ( access(path: fullFilename, amode: 0) != 0 )
    {
      free(pMem: v7);
      if ( v8 == 0 )
        _Error(a1: "Can't find %s (listed in %s).", fullFilename, pDepFilename);
    }
    else
    {
      m_Size = pInfo->m_Files.m_Size;
      m_nAllocationCount = pInfo->m_Files.m_Memory.m_nAllocationCount;
      if ( m_Size + 1 > m_nAllocationCount )
        CUtlMemory<int,int>::Grow(
          this: (CUtlMemory<CTCPPacket *,int> *)&pInfo->m_Files,
          num: m_Size - m_nAllocationCount + 1);
      ++pInfo->m_Files.m_Size;
      m_pMemory = pInfo->m_Files.m_Memory.m_pMemory;
      v13 = pInfo->m_Files.m_Size - m_Size - 1;
      pInfo->m_Files.m_pElements = m_pMemory;
      if ( v13 > 0 )
        _V_memmove(
          dest: (unsigned __int8 *)&m_pMemory[m_Size + 1],
          src: (unsigned __int8 *)&m_pMemory[m_Size],
          count: 4 * v13);
      v14 = &pInfo->m_Files.m_Memory.m_pMemory[m_Size];
      if ( v14 != nullptr )
        *v14 = pFile;
    }
  }
  fclose(stream: v2);
}

//------------------------------------------------------------------------------
// Address: 0x1001E2A0
// Name: void SetupDependenciesForPatch(class CDependencyInfo __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SetupDependenciesForPatch(CDependencyInfo *pInfo, char *pPatchDirectory)
{
  char *v2; // ebx
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CDependencyInfo::CDependencyFile **m_pMemory; // ecx
  int v6; // eax
  CDependencyInfo::CDependencyFile **v7; // eax
  void *v8; // esi
  char searchStr[260]; // [esp+0h] [ebp-230h] BYREF
  _finddata64i32_t data; // [esp+104h] [ebp-12Ch] BYREF
  int handle; // [esp+22Ch] [ebp-4h]

  V_ComposeFileName(path: pPatchDirectory, filename: "*.*", dest: searchStr, destSize: 260);
  handle = _findfirst64i32(szWild: searchStr, pfd: &data);
  if ( handle != -1 )
  {
    do
    {
      if ( data.name[0] != 46 && (data.attrib & 0x10) == 0 )
      {
        v2 = (char *)operator new(nSize: 0x104u);
        V_strncpy(pDest: v2, pSrc: data.name, maxLen: 260);
        m_Size = pInfo->m_Files.m_Size;
        m_nAllocationCount = pInfo->m_Files.m_Memory.m_nAllocationCount;
        if ( m_Size + 1 > m_nAllocationCount )
          CUtlMemory<int,int>::Grow(
            this: (CUtlMemory<CTCPPacket *,int> *)&pInfo->m_Files,
            num: m_Size - m_nAllocationCount + 1);
        ++pInfo->m_Files.m_Size;
        m_pMemory = pInfo->m_Files.m_Memory.m_pMemory;
        v6 = pInfo->m_Files.m_Size - m_Size - 1;
        pInfo->m_Files.m_pElements = m_pMemory;
        if ( v6 > 0 )
          _V_memmove(
            dest: (unsigned __int8 *)&m_pMemory[m_Size + 1],
            src: (unsigned __int8 *)&m_pMemory[m_Size],
            count: 4 * v6);
        v7 = &pInfo->m_Files.m_Memory.m_pMemory[m_Size];
        if ( v7 != nullptr )
          *v7 = (CDependencyInfo::CDependencyFile *)v2;
      }
      v8 = (void *)handle;
    }
    while ( _findnext64i32(hFile: (void *)handle, pfd: &data) == 0 );
    _findclose(hFile: v8);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001E3D0
// Name: void SetupDependencyInfo(class CDependencyInfo __near *,char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SetupDependencyInfo(CDependencyInfo *pInfo, char *pDependencyFilename, bool bPatchMode)
{
  HMODULE ModuleHandleA; // eax
  const char *v4; // eax
  char Filename[512]; // [esp+4h] [ebp-304h] BYREF
  char depFilename[260]; // [esp+204h] [ebp-104h] BYREF

  if ( bPatchMode )
  {
    SetupDependencyFilename(pInfo, pPatchDirectory: pDependencyFilename);
    SetupDependenciesForPatch(pInfo, pPatchDirectory: pDependencyFilename);
  }
  else
  {
    ModuleHandleA = GetModuleHandleA(lpModuleName: nullptr);
    if ( GetModuleFileNameA(hModule: ModuleHandleA, lpFilename: Filename, nSize: 0x200u) == 0 )
      _Error(a1: "GetModuleFileName failed.");
    V_strncpy(pDest: pInfo->m_DependencyFilesDir, pSrc: Filename, maxLen: 260);
    V_StripLastDir(dirName: pInfo->m_DependencyFilesDir, maxlen: 0x104u);
    v4 = V_UnqualifiedFileName(in: Filename);
    V_strncpy(pDest: pInfo->m_OriginalExeFilename, pSrc: v4, maxLen: 260);
    V_ComposeFileName(
      path: pInfo->m_DependencyFilesDir,
      filename: pDependencyFilename,
      dest: depFilename,
      destSize: 260);
    ParseDependencyFile(pInfo, pDepFilename: depFilename);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001E4A0
// Name: public: CMasterBroadcaster::CMasterBroadcaster(void)
// Source: json
//------------------------------------------------------------------------------
CMasterBroadcaster *__thiscall CMasterBroadcaster::CMasterBroadcaster(CMasterBroadcaster *this)
{
  this->m_BroadcastInfo.m_Args.m_Memory.m_pMemory = nullptr;
  this->m_BroadcastInfo.m_Args.m_Memory.m_nAllocationCount = 0;
  this->m_BroadcastInfo.m_Args.m_Memory.m_nGrowSize = 0;
  this->m_BroadcastInfo.m_Args.m_Size = 0;
  this->m_BroadcastInfo.m_Args.m_pElements = nullptr;
  this->m_PatchWorkerIPs.m_Memory.m_pMemory = nullptr;
  this->m_PatchWorkerIPs.m_Memory.m_nAllocationCount = 0;
  this->m_PatchWorkerIPs.m_Memory.m_nGrowSize = 0;
  this->m_PatchWorkerIPs.m_Size = 0;
  this->m_PatchWorkerIPs.m_pElements = nullptr;
  this->m_ConnectionCreator.__vftable = (CVMPIConnectionCreator_vtbl *)&CVMPIConnectionCreator::`vftable';
  CExpressionEvaluator::CExpressionEvaluator(this: &this->m_hShutdownEvent);
  CExpressionEvaluator::CExpressionEvaluator(this: &this->m_hShutdownReply);
  this->m_pListenSocket = nullptr;
  this->m_pDownloaderListenSocket = nullptr;
  this->m_pSocket = nullptr;
  this->m_iListenPort = -1;
  this->m_iDownloaderListenPort = -1;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1001E520
// Name: private: void CMasterBroadcaster::GetPatchWorkerList(int,char __near * __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMasterBroadcaster::GetPatchWorkerList(CMasterBroadcaster *this, int argc, char **argv)
{
  CUtlMemory<CMasterMulticastThread::CChunkInfo,int> *p_m_PatchWorkerIPs; // esi
  int v5; // edi
  int v6; // eax
  char **v7; // ebx
  CMasterMulticastThread::CChunkInfo *m_pMemory; // edi
  int m_nAllocationCount; // eax
  CMasterMulticastThread::CChunkInfo *v10; // ecx
  int v11; // eax
  CIPAddr *v12; // eax
  CIPAddr addr; // [esp+8h] [ebp-20h] BYREF
  int a; // [esp+10h] [ebp-18h] BYREF
  int b; // [esp+14h] [ebp-14h] BYREF
  int c; // [esp+18h] [ebp-10h] BYREF
  int d; // [esp+1Ch] [ebp-Ch] BYREF
  int workerCount; // [esp+20h] [ebp-8h]
  int i; // [esp+24h] [ebp-4h]
  int iWorker; // [esp+34h] [ebp+Ch]

  p_m_PatchWorkerIPs = (CUtlMemory<CMasterMulticastThread::CChunkInfo,int> *)&this->m_PatchWorkerIPs;
  this->m_PatchWorkerIPs.m_Size = 0;
  if ( this->m_PatchWorkerIPs.m_Memory.m_nGrowSize >= 0 )
  {
    if ( p_m_PatchWorkerIPs->m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: p_m_PatchWorkerIPs->m_pMemory);
      p_m_PatchWorkerIPs->m_pMemory = nullptr;
    }
    p_m_PatchWorkerIPs->m_nAllocationCount = 0;
  }
  p_m_PatchWorkerIPs[1].m_nAllocationCount = (int)p_m_PatchWorkerIPs->m_pMemory;
  i = 0;
  if ( argc - 1 > 0 )
  {
    while ( _V_stricmp(s1: argv[i], s2: "-mpi_PatchWorkers") != 0 )
    {
      if ( ++i >= argc - 1 )
        return;
    }
    v5 = i;
    v6 = atoi(nptr: argv[i + 1]);
    workerCount = v6;
    iWorker = 0;
    if ( v6 > 0 )
    {
      v7 = &argv[i + 2];
      while ( 1 )
      {
        if ( v5 + iWorker + 2 >= argc )
          _Error(a1: "-mpi_PatchWorkers: %d specified for count, but not enough IPs following.\n", v6);
        sscanf(string: *v7, format: "%d.%d.%d.%d", &a, &b, &c, &d);
        CIPAddr::CIPAddr(this: &addr);
        CIPAddr::Init(this: &addr, ip0: a, ip1: b, ip2: c, ip3: d, ipPort: 0);
        m_pMemory = p_m_PatchWorkerIPs[1].m_pMemory;
        m_nAllocationCount = p_m_PatchWorkerIPs->m_nAllocationCount;
        if ( (int)&m_pMemory->m_iChunk + 1 > m_nAllocationCount )
          CUtlMemory<CIPAddr,int>::Grow(
            this: p_m_PatchWorkerIPs,
            num: (int)&m_pMemory->m_iChunk - m_nAllocationCount + 1);
        ++p_m_PatchWorkerIPs[1].m_pMemory;
        v10 = p_m_PatchWorkerIPs->m_pMemory;
        v11 = (char *)p_m_PatchWorkerIPs[1].m_pMemory - (char *)m_pMemory - 1;
        p_m_PatchWorkerIPs[1].m_nAllocationCount = (int)p_m_PatchWorkerIPs->m_pMemory;
        if ( v11 > 0 )
          _V_memmove(
            dest: (unsigned __int8 *)&v10[(int)m_pMemory + 1],
            src: (unsigned __int8 *)&v10[(_DWORD)m_pMemory],
            count: 6 * v11);
        v12 = (CIPAddr *)&p_m_PatchWorkerIPs->m_pMemory[(_DWORD)m_pMemory];
        if ( v12 != nullptr )
          *v12 = addr;
        ++v7;
        if ( ++iWorker >= workerCount )
          break;
        v6 = workerCount;
        v5 = i;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001E6B0
// Name: void VMPI_Finalize(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall VMPI_Finalize(int a1@<ebp>)
{
  int i; // esi
  CVMPIConnection *v2; // eax
  IThreadedTCPSocket *m_pSocket; // ecx
  int m_Head; // esi
  UtlLinkedListElem_t<CTCPPacket *,int> *m_pMemory; // eax
  int v6; // esi
  UtlLinkedListElem_t<CTCPPacket *,int> *v7; // eax
  TSLNodeBase_t *v8; // eax
  TSLNodeBase_t *Next; // esi
  int j; // esi
  char **v11; // eax

  CMasterBroadcaster::Term(this: &g_MasterBroadcaster);
  DistributeWork_Cancel();
  for ( i = 0; i < g_nConnections; ++i )
  {
    v2 = g_Connections[i];
    if ( v2 != nullptr )
    {
      m_pSocket = v2->m_pSocket;
      if ( m_pSocket != nullptr )
      {
        v2->m_pSocket = nullptr;
        m_pSocket->Release(this: m_pSocket);
      }
      else
      {
        ((void (__thiscall *)(CVMPIConnection *, int))v2->dtr_CVMPIConnection)(a1: g_Connections[i], a2: 1);
      }
    }
  }
  m_Head = g_VMPIMessages.m_Head;
  g_nConnections = 0;
  if ( g_VMPIMessages.m_Head != -1 )
  {
    m_pMemory = g_VMPIMessages.m_Memory.m_pMemory;
    do
    {
      v6 = m_Head;
      CTCPPacket::Release(this: (CVMPIFile_Memory *)m_pMemory[v6].m_Element);
      m_pMemory = g_VMPIMessages.m_Memory.m_pMemory;
      m_Head = g_VMPIMessages.m_Memory.m_pMemory[v6].m_Next;
    }
    while ( m_Head != -1 );
  }
  CUtlLinkedList<CPartitionInfo *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CPartitionInfo *,int>,int>>::RemoveAll(this: (CUtlLinkedList<CFileChunkPacket *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CFileChunkPacket *,int>,int> > *)&g_VMPIMessages);
  v7 = g_VMPIMessages.m_Memory.m_pMemory;
  if ( g_VMPIMessages.m_Memory.m_nGrowSize >= 0 )
  {
    if ( g_VMPIMessages.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: g_VMPIMessages.m_Memory.m_pMemory);
      v7 = nullptr;
      g_VMPIMessages.m_Memory.m_pMemory = nullptr;
    }
    g_VMPIMessages.m_Memory.m_nAllocationCount = 0;
  }
  g_VMPIMessages.m_FirstFree = -1;
  g_VMPIMessages.m_NumAlloced = 0;
  g_VMPIMessages.m_LastAlloc.index = -1;
  g_VMPIMessages.m_pElements = v7;
  CUtlLinkedList<CUtlVector<char,CUtlMemory<char,int>> *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlVector<char,CUtlMemory<char,int>> *,unsigned short>,unsigned short>>::PurgeAndDeleteElements(this: &g_PersistentPackets);
  v8 = CTSListBase::Detach(this: &g_DispatchBuffers);
  if ( v8 != nullptr )
  {
    do
    {
      Next = v8->Next;
      free(pMem: v8);
      v8 = Next;
    }
    while ( Next != nullptr );
  }
  if ( g_hKernel32DLL != nullptr )
  {
    FreeLibrary(hLibModule: g_hKernel32DLL);
    g_hKernel32DLL = nullptr;
  }
  for ( j = 0; j < g_WorkerCommandLine.m_Size; ++j )
    free(pMem: g_WorkerCommandLine.m_Memory.m_pMemory[j]);
  v11 = g_WorkerCommandLine.m_Memory.m_pMemory;
  g_WorkerCommandLine.m_Size = 0;
  if ( g_WorkerCommandLine.m_Memory.m_nGrowSize >= 0 )
  {
    if ( g_WorkerCommandLine.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: g_WorkerCommandLine.m_Memory.m_pMemory);
      v11 = nullptr;
      g_WorkerCommandLine.m_Memory.m_pMemory = nullptr;
    }
    g_WorkerCommandLine.m_Memory.m_nAllocationCount = 0;
  }
  g_WorkerCommandLine.m_pElements = v11;
  VMPI_HandleAutoRestart(a1);
}

//------------------------------------------------------------------------------
// Address: 0x1001E830
// Name: void VMPI_GroupPackets(class CVMPIConnection __near *,void const __near * const __near *,int const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl VMPI_GroupPackets(CVMPIConnection *pConn, const void *const *pChunks, char *pChunkLengths, int nChunks)
{
  int m_Size; // edi
  int m_nAllocationCount; // eax
  void **m_pMemory; // ecx
  int v7; // eax
  void **v8; // eax
  int v9; // edi
  int v10; // eax
  int *v11; // ecx
  int v12; // eax
  int *v13; // eax
  int v14; // ebx
  unsigned int *v15; // esi
  int v16; // ecx
  int v17; // edx
  int v18; // edi
  int v19; // eax
  int v20; // edi
  char *v21; // eax
  int v22; // edi
  int v23; // eax
  int v24; // edi
  int v25; // eax
  void **v26; // ecx
  int v27; // eax
  void **v28; // edi
  int v29; // edi
  int v30; // eax
  int *v31; // ecx
  int v32; // eax
  int *v33; // edi
  CCriticalSectionLock connectionsLock; // [esp+Ch] [ebp-10h] BYREF
  int v35; // [esp+14h] [ebp-8h]
  int i; // [esp+18h] [ebp-4h]
  char *pOut; // [esp+30h] [ebp+14h]

  CCriticalSectionLock::CCriticalSectionLock(this: &connectionsLock, pCS: &g_ConnectionsCS);
  CCriticalSectionLock::Lock(this: &connectionsLock);
  if ( pConn->m_GroupedChunks.m_Size == 0 )
  {
    m_Size = pConn->m_GroupedChunks.m_Size;
    m_nAllocationCount = pConn->m_GroupedChunks.m_Memory.m_nAllocationCount;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<int,int>::Grow(
        this: (CUtlMemory<CTCPPacket *,int> *)&pConn->m_GroupedChunks,
        num: m_Size - m_nAllocationCount + 1);
    ++pConn->m_GroupedChunks.m_Size;
    m_pMemory = pConn->m_GroupedChunks.m_Memory.m_pMemory;
    v7 = pConn->m_GroupedChunks.m_Size - m_Size - 1;
    pConn->m_GroupedChunks.m_pElements = m_pMemory;
    if ( v7 > 0 )
      _V_memmove(
        dest: (unsigned __int8 *)&m_pMemory[m_Size + 1],
        src: (unsigned __int8 *)&m_pMemory[m_Size],
        count: 4 * v7);
    v8 = &pConn->m_GroupedChunks.m_Memory.m_pMemory[m_Size];
    if ( v8 != nullptr )
      *v8 = g_GroupedPacketHeader;
    v9 = pConn->m_GroupedChunkLengths.m_Size;
    v10 = pConn->m_GroupedChunkLengths.m_Memory.m_nAllocationCount;
    if ( v9 + 1 > v10 )
      CUtlMemory<int,int>::Grow(this: (CUtlMemory<CTCPPacket *,int> *)&pConn->m_GroupedChunkLengths, num: v9 - v10 + 1);
    ++pConn->m_GroupedChunkLengths.m_Size;
    v11 = pConn->m_GroupedChunkLengths.m_Memory.m_pMemory;
    v12 = pConn->m_GroupedChunkLengths.m_Size - v9 - 1;
    pConn->m_GroupedChunkLengths.m_pElements = v11;
    if ( v12 > 0 )
      _V_memmove(dest: (unsigned __int8 *)&v11[v9 + 1], src: (unsigned __int8 *)&v11[v9], count: 4 * v12);
    v13 = &pConn->m_GroupedChunkLengths.m_Memory.m_pMemory[v9];
    if ( v13 != nullptr )
      *v13 = 2;
  }
  v14 = nChunks;
  v15 = (unsigned int *)pChunkLengths;
  v16 = 0;
  v17 = 0;
  v18 = 0;
  v19 = 0;
  if ( nChunks >= 2 )
  {
    do
    {
      v16 += *(_DWORD *)&pChunkLengths[4 * v19];
      v17 += *(_DWORD *)&pChunkLengths[4 * v19 + 4];
      v19 += 2;
    }
    while ( v19 < nChunks - 1 );
    v14 = nChunks;
  }
  if ( v19 < v14 )
    v18 = *(_DWORD *)&pChunkLengths[4 * v19];
  v20 = v17 + v16 + v18;
  v35 = v20 + 4;
  v21 = (char *)operator new(nSize: v20 + 4);
  *(_DWORD *)v21 = v20;
  pOut = v21;
  v22 = 4;
  if ( v14 > 0 )
  {
    v23 = (char *)pChunks - pChunkLengths;
    for ( i = (char *)pChunks - pChunkLengths; ; v23 = i )
    {
      memcpy(dst: (unsigned __int8 *)&pOut[v22], src: *(unsigned __int8 **)((char *)v15 + v23), count: *v15);
      v22 += *v15++;
      if ( --v14 == 0 )
        break;
    }
  }
  v24 = pConn->m_GroupedChunks.m_Size;
  v25 = pConn->m_GroupedChunks.m_Memory.m_nAllocationCount;
  if ( v24 + 1 > v25 )
    CUtlMemory<int,int>::Grow(this: (CUtlMemory<CTCPPacket *,int> *)&pConn->m_GroupedChunks, num: v24 - v25 + 1);
  ++pConn->m_GroupedChunks.m_Size;
  v26 = pConn->m_GroupedChunks.m_Memory.m_pMemory;
  v27 = pConn->m_GroupedChunks.m_Size - v24 - 1;
  pConn->m_GroupedChunks.m_pElements = v26;
  if ( v27 > 0 )
    _V_memmove(dest: (unsigned __int8 *)&v26[v24 + 1], src: (unsigned __int8 *)&v26[v24], count: 4 * v27);
  v28 = &pConn->m_GroupedChunks.m_Memory.m_pMemory[v24];
  if ( v28 != nullptr )
    *v28 = pOut;
  v29 = pConn->m_GroupedChunkLengths.m_Size;
  v30 = pConn->m_GroupedChunkLengths.m_Memory.m_nAllocationCount;
  if ( v29 + 1 > v30 )
    CUtlMemory<int,int>::Grow(this: (CUtlMemory<CTCPPacket *,int> *)&pConn->m_GroupedChunkLengths, num: v29 - v30 + 1);
  ++pConn->m_GroupedChunkLengths.m_Size;
  v31 = pConn->m_GroupedChunkLengths.m_Memory.m_pMemory;
  v32 = pConn->m_GroupedChunkLengths.m_Size - v29 - 1;
  pConn->m_GroupedChunkLengths.m_pElements = v31;
  if ( v32 > 0 )
    _V_memmove(dest: (unsigned __int8 *)&v31[v29 + 1], src: (unsigned __int8 *)&v31[v29], count: 4 * v32);
  v33 = &pConn->m_GroupedChunkLengths.m_Memory.m_pMemory[v29];
  if ( v33 != nullptr )
    *v33 = v35;
  CCriticalSectionLock::~CCriticalSectionLock(this: &connectionsLock);
}

//------------------------------------------------------------------------------
// Address: 0x1001EA40
// Name: void VMPI_SetupAutoRestartParameters(int,char __near * __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl VMPI_SetupAutoRestartParameters(int argc, char **argv)
{
  int v2; // edi
  const char *v3; // ebx
  unsigned int v4; // esi
  char *v5; // [esp+4h] [ebp-4h]

  if ( VMPI_FindArg(argc, argv, pName: g_VMPIParams[6].m_pName, pDefault: setName) != nullptr )
  {
    v2 = 0;
    g_OriginalCommandLineParameters.m_Size = 0;
    CUtlVector<char *,CUtlMemory<char *,int>>::InsertMultipleBefore(
      this: (CUtlVector<int,CUtlMemory<int,int> > *)&g_OriginalCommandLineParameters,
      elem: 0,
      num: argc);
    if ( argc > 0 )
    {
      do
      {
        v3 = argv[v2];
        v4 = _V_strlen(str: v3) + 1;
        v5 = (char *)operator new(nSize: v4);
        V_strncpy(pDest: v5, pSrc: v3, maxLen: v4);
        g_OriginalCommandLineParameters.m_Memory.m_pMemory[v2++] = v5;
      }
      while ( v2 < argc );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001EC30
// Name: void InternalHandleSocketErrors(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InternalHandleSocketErrors()
{
  int v0; // esi
  int m_Head; // eax
  CVMPIConnection **m_pMemory; // ebx
  UtlLinkedListElem_t<CVMPIConnection *,int> *v3; // edx
  CVMPIConnection **v4; // ecx
  int v5; // eax
  UtlLinkedListElem_t<CVMPIConnection *,int> *v6; // eax
  int m_Size; // edi
  CUtlVector<CVMPIConnection *,CUtlMemory<CVMPIConnection *,int> > errorSockets; // [esp+Ch] [ebp-1Ch] BYREF
  CCriticalSectionLock csLock; // [esp+20h] [ebp-8h] BYREF

  v0 = 0;
  memset(&errorSockets, 0, sizeof(errorSockets));
  CCriticalSectionLock::CCriticalSectionLock(this: &csLock, pCS: &g_ErrorSocketsCS);
  CCriticalSectionLock::Lock(this: &csLock);
  CUtlVector<char *,CUtlMemory<char *,int>>::InsertMultipleBefore(
    this: (CUtlVector<int,CUtlMemory<int,int> > *)&errorSockets,
    elem: 0,
    num: g_ErrorSockets.m_ElementCount);
  m_Head = g_ErrorSockets.m_Head;
  m_pMemory = errorSockets.m_Memory.m_pMemory;
  if ( g_ErrorSockets.m_Head != -1 )
  {
    v3 = g_ErrorSockets.m_Memory.m_pMemory;
    v4 = errorSockets.m_Memory.m_pMemory;
    do
    {
      v5 = m_Head;
      *v4 = v3[v5].m_Element;
      v3 = g_ErrorSockets.m_Memory.m_pMemory;
      m_Head = g_ErrorSockets.m_Memory.m_pMemory[v5].m_Next;
      ++v4;
    }
    while ( m_Head != -1 );
  }
  CUtlLinkedList<CPartitionInfo *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CPartitionInfo *,int>,int>>::RemoveAll(this: (CUtlLinkedList<CFileChunkPacket *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CFileChunkPacket *,int>,int> > *)&g_ErrorSockets);
  v6 = g_ErrorSockets.m_Memory.m_pMemory;
  if ( g_ErrorSockets.m_Memory.m_nGrowSize >= 0 )
  {
    if ( g_ErrorSockets.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: g_ErrorSockets.m_Memory.m_pMemory);
      v6 = nullptr;
      g_ErrorSockets.m_Memory.m_pMemory = nullptr;
    }
    g_ErrorSockets.m_Memory.m_nAllocationCount = 0;
  }
  g_ErrorSockets.m_FirstFree = -1;
  g_ErrorSockets.m_NumAlloced = 0;
  g_ErrorSockets.m_LastAlloc.index = -1;
  g_ErrorSockets.m_pElements = v6;
  CCriticalSectionLock::Unlock(this: &csLock);
  m_Size = errorSockets.m_Size;
  if ( errorSockets.m_Size > 0 )
  {
    do
    {
      CVMPIConnection::HandleDisconnect(this: m_pMemory[v0]);
      m_pMemory[v0]->Release(this: m_pMemory[v0], a2: true);
      ++v0;
    }
    while ( v0 < m_Size );
  }
  UpdateActiveConnectionsText();
  CCriticalSectionLock::~CCriticalSectionLock(this: &csLock);
  if ( errorSockets.m_Memory.m_nGrowSize >= 0 && m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x1001ED50
// Name: void VMPI_HandleSocketErrors(unsigned long)
// Source: json
//------------------------------------------------------------------------------
void __cdecl VMPI_HandleSocketErrors(DWORD timeout)
{
  void *UserData; // eax

  UserData = CTCPPacket::GetUserData(this: &g_ErrorSocketsEvent);
  if ( WaitForSingleObject(hHandle: UserData, dwMilliseconds: timeout) == 0 )
    InternalHandleSocketErrors();
}

//------------------------------------------------------------------------------
// Address: 0x1001ED80
// Name: bool VMPI_GetNextMessage(class MessageBuffer __near *,int __near *,unsigned long)
// Source: json
//------------------------------------------------------------------------------
char __cdecl VMPI_GetNextMessage(MessageBuffer *pBuf, int *pSource, CTCPPacket *startTimeout)
{
  DWORD v3; // eax
  CTCPPacket *v4; // eax
  int m_Head; // edi
  int v7; // esi
  CTCPPacket *m_Element; // ebx
  int i; // eax
  signed int m_Size; // esi
  int j; // edi
  unsigned int v12; // ebx
  unsigned __int8 *v13; // eax
  int v14; // edx
  CTCPPacket *v15; // edi
  unsigned int v16; // ecx
  CTCPPacket **m_pMemory; // edx
  CTCPPacket **v18; // eax
  CTCPPacket **v19; // edi
  int v20; // edi
  int v21; // ebx
  CTCPPacket *v22; // esi
  int m_Len; // eax
  int v24; // ecx
  int v25; // eax
  char szPacketID[64]; // [esp+Ch] [ebp-ACh] BYREF
  char szSubPacketID[64]; // [esp+4Ch] [ebp-6Ch] BYREF
  void *handles[2]; // [esp+8Ch] [ebp-2Ch] BYREF
  CCriticalSectionLock csLock; // [esp+94h] [ebp-24h] BYREF
  CUtlVector<CTCPPacket *,CUtlMemory<CTCPPacket *,int> > groupedPackets; // [esp+9Ch] [ebp-1Ch] BYREF
  int iCurOffset; // [esp+B0h] [ebp-8h]
  unsigned int startTime; // [esp+B4h] [ebp-4h]
  CVMPIFile_Memory *pPacket; // [esp+C8h] [ebp+10h]

  handles[0] = CTCPPacket::GetUserData(this: &g_ErrorSocketsEvent);
  handles[1] = CTCPPacket::GetUserData(this: &g_VMPIMessagesEvent);
  startTime = _Plat_MSTime();
  v3 = WaitForMultipleObjects(nCount: 2u, lpHandles: handles, bWaitAll: false, dwMilliseconds: (DWORD)startTimeout);
  if ( v3 == 258 )
    return 0;
  while ( v3 == 0 )
  {
    InternalHandleSocketErrors();
    v4 = (CTCPPacket *)(_Plat_MSTime() - startTime);
    if ( v4 >= startTimeout )
      return 0;
    v3 = WaitForMultipleObjects(
           nCount: 2u,
           lpHandles: handles,
           bWaitAll: false,
           dwMilliseconds: (char *)startTimeout - (char *)v4);
    if ( v3 == 258 )
      return 0;
  }
  if ( v3 != 1 )
  {
    _Error(a1: "VMPI_GetNextMessage: WaitForSingleObject returned %lu", v3);
    return 0;
  }
  CCriticalSectionLock::CCriticalSectionLock(this: &csLock, pCS: &g_VMPIMessagesCS);
  CCriticalSectionLock::Lock(this: &csLock);
  m_Head = g_VMPIMessages.m_Head;
  v7 = g_VMPIMessages.m_Head;
  m_Element = g_VMPIMessages.m_Memory.m_pMemory[g_VMPIMessages.m_Head].m_Element;
  pPacket = (CVMPIFile_Memory *)m_Element;
  CUtlLinkedList<CThreadedTCPSocket::SendData_t *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CThreadedTCPSocket::SendData_t *,int>,int>>::Unlink(
    this: (CUtlLinkedList<CFileChunkPacket *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CFileChunkPacket *,int>,int> > *)&g_VMPIMessages,
    elem: g_VMPIMessages.m_Head);
  g_VMPIMessages.m_Memory.m_pMemory[v7].m_Next = g_VMPIMessages.m_FirstFree;
  g_VMPIMessages.m_FirstFree = m_Head;
  for ( i = m_Element->m_Len; i >= 6; m_Element = v22 )
  {
    if ( m_Element->m_Data[0] != 27 || m_Element->m_Data[1] != 4 )
      break;
    m_Size = 0;
    memset(&groupedPackets, 0, sizeof(groupedPackets));
    for ( j = 2; ; j = iCurOffset )
    {
      v12 = *(_DWORD *)&m_Element->m_Data[j];
      if ( (int)(v12 + j) > i )
        _Error(a1: "Invalid chunked packet\n");
      iCurOffset = j + 4;
      v13 = (unsigned __int8 *)operator new(nSize: v12 + 11);
      v14 = iCurOffset;
      v15 = (CTCPPacket *)v13;
      *((_DWORD *)v13 + 1) = v12;
      *(_DWORD *)v13 = pPacket->__vftable;
      memcpy(dst: v13 + 8, src: (unsigned __int8 *)&pPacket->m_DataLen + v14, count: v12);
      v16 = m_Size;
      startTime = m_Size;
      if ( m_Size + 1 > groupedPackets.m_Memory.m_nAllocationCount )
      {
        CUtlMemory<int,int>::Grow(
          this: &groupedPackets.m_Memory,
          num: m_Size - groupedPackets.m_Memory.m_nAllocationCount + 1);
        m_Size = groupedPackets.m_Size;
        v16 = startTime;
      }
      m_pMemory = groupedPackets.m_Memory.m_pMemory;
      groupedPackets.m_Size = ++m_Size;
      groupedPackets.m_pElements = groupedPackets.m_Memory.m_pMemory;
      if ( (int)(m_Size - v16 - 1) > 0 )
      {
        _V_memmove(
          dest: (unsigned __int8 *)&groupedPackets.m_Memory.m_pMemory[v16 + 1],
          src: (unsigned __int8 *)&groupedPackets.m_Memory.m_pMemory[v16],
          count: 4 * (m_Size - v16 - 1));
        m_pMemory = groupedPackets.m_Memory.m_pMemory;
        v16 = startTime;
      }
      v18 = &m_pMemory[v16];
      if ( v18 != nullptr )
        *v18 = v15;
      i = (int)pPacket->m_pData;
      iCurOffset += v12;
      if ( iCurOffset + 4 > i )
        break;
      m_Element = (CTCPPacket *)pPacket;
    }
    if ( m_Size > 0 )
    {
      v19 = &groupedPackets.m_Memory.m_pMemory[m_Size - 1];
      do
      {
        CUtlLinkedList<CTCPPacket *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CTCPPacket *,int>,int>>::AddToHead(
          this: &g_VMPIMessages,
          src: v19--);
        --m_Size;
      }
      while ( m_Size != 0 );
    }
    CTCPPacket::Release(this: pPacket);
    CUtlVector<CWorkerAccumState<CThreadNullMutex>::SubProcess *,CUtlMemory<CWorkerAccumState<CThreadNullMutex>::SubProcess *,int>>::~CUtlVector<CWorkerAccumState<CThreadNullMutex>::SubProcess *,CUtlMemory<CWorkerAccumState<CThreadNullMutex>::SubProcess *,int>>(this: (CUtlVector<CFileResponse,CUtlMemory<CFileResponse,int> > *)&groupedPackets);
    v20 = g_VMPIMessages.m_Head;
    v21 = g_VMPIMessages.m_Head;
    v22 = g_VMPIMessages.m_Memory.m_pMemory[g_VMPIMessages.m_Head].m_Element;
    pPacket = (CVMPIFile_Memory *)v22;
    CUtlLinkedList<CThreadedTCPSocket::SendData_t *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CThreadedTCPSocket::SendData_t *,int>,int>>::Unlink(
      this: (CUtlLinkedList<CFileChunkPacket *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CFileChunkPacket *,int>,int> > *)&g_VMPIMessages,
      elem: g_VMPIMessages.m_Head);
    g_VMPIMessages.m_Memory.m_pMemory[v21].m_Next = g_VMPIMessages.m_FirstFree;
    g_VMPIMessages.m_FirstFree = v20;
    i = v22->m_Len;
  }
  if ( g_VMPIMessages.m_ElementCount > 0 )
    CEvent::SetEvent(this: &g_VMPIMessagesEvent);
  CCriticalSectionLock::Unlock(this: &csLock);
  MessageBuffer::setLen(this: pBuf, nlen: m_Element->m_Len);
  memcpy(dst: (unsigned __int8 *)pBuf->data, src: (unsigned __int8 *)m_Element->m_Data, count: m_Element->m_Len);
  if ( g_bSuperSpewEnabled )
  {
    m_Len = m_Element->m_Len;
    if ( m_Len < 2 )
      v24 = -1;
    else
      v24 = pBuf->data[1];
    if ( m_Len < 1 )
      v25 = -1;
    else
      v25 = *pBuf->data;
    CVMPIPacketIDReg::Lookup(
      nPacketID: v25,
      nSubPacketID: v24,
      pPacketIDString: szPacketID,
      nPacketIDStringSize: 64,
      pSubPacketIDString: szSubPacketID,
      nSubPacketIDStringSize: 64);
    VMPI_SuperSpew(pMsg: "Received a packet (packetID %s, subPacketID %s)\n", szPacketID, szSubPacketID);
  }
  *pSource = (int)CTCPPacket::GetUserData(this: (CEvent *)m_Element);
  ++g_nMessagesReceived;
  g_nBytesReceived += m_Element->m_Len + 4;
  CTCPPacket::Release(this: (CVMPIFile_Memory *)m_Element);
  CCriticalSectionLock::~CCriticalSectionLock(this: &csLock);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1001F0D0
// Name: bool VMPI_DispatchNextMessage(unsigned long)
// Source: json
//------------------------------------------------------------------------------
char __cdecl VMPI_DispatchNextMessage(CTCPPacket *timeout)
{
  TSLNodeBase_t *v1; // eax
  MessageBuffer *v2; // esi
  MessageBuffer *v3; // eax
  char v4; // bl
  char v5; // al
  TSLNodeBase_t *v6; // eax
  int iSource; // [esp+Ch] [ebp-4h] BYREF

  v1 = CTSListBase::Pop(this: &g_DispatchBuffers);
  if ( v1 != nullptr )
  {
    v2 = *((MessageBuffer **)&v1->Next + 1);
    free(pMem: v1);
  }
  else
  {
    v3 = (MessageBuffer *)operator new(nSize: 0x10u);
    if ( v3 != nullptr )
      v2 = MessageBuffer::MessageBuffer(this: v3);
    else
      v2 = nullptr;
  }
  v4 = 1;
  if ( VMPI_GetNextMessage(pBuf: v2, pSource: &iSource, startTimeout: timeout) != 0 )
  {
    while ( 1 )
    {
      if ( (int)ConCommandBase::GetName(this: (CVMPIFile_Memory *)v2) >= 1 )
      {
        v5 = *v2->data;
        if ( (unsigned __int8)v5 < 0x20u
          && g_VMPIDispatch[v5] != nullptr
          && g_VMPIDispatch[v5](a1: v2, a2: iSource, a3: v5) )
        {
          break;
        }
      }
      if ( VMPI_GetNextMessage(pBuf: v2, pSource: &iSource, startTimeout: timeout) == 0 )
        goto LABEL_12;
    }
  }
  else
  {
LABEL_12:
    v4 = 0;
  }
  v6 = (TSLNodeBase_t *)operator new(nSize: 8u);
  if ( v6 != nullptr )
  {
    *((_DWORD *)&v6->Next + 1) = v2;
    CTSListBase::Push(this: &g_DispatchBuffers, pNode: v6);
  }
  else
  {
    CTSListBase::Push(this: &g_DispatchBuffers, pNode: nullptr);
  }
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x1001F1C0
// Name: bool VMPI_SendChunks(void const __near * const __near *,int const __near *,int,int,int)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl VMPI_SendChunks(
        const void *const *pChunks,
        int *pChunkLengths,
        int nChunks,
        int iDest,
        char fVMPISendFlags)
{
  int i; // esi
  CUtlVector<char,CUtlMemory<char,int> > *v7; // ebx
  int j; // esi
  CUtlVector<char,CUtlMemory<char,int> > *v9; // eax
  int *v10; // esi
  unsigned __int16 v11; // ax
  int v12; // esi
  UtlLinkedListElem_t<CUtlVector<char,CUtlMemory<char,int> > *,unsigned short> *v13; // eax
  int v14; // ecx
  int v15; // eax
  CVMPIConnection *v16; // ebx
  IThreadedTCPSocket *m_pSocket; // ecx
  CCriticalSectionLock v18; // [esp+Ch] [ebp-10h] BYREF
  CCriticalSectionLock csLock; // [esp+14h] [ebp-8h] BYREF
  int iDesta; // [esp+30h] [ebp+14h]

  if ( iDest == -2 )
  {
    CCriticalSectionLock::CCriticalSectionLock(this: &csLock, pCS: &g_ConnectionsCS);
    CCriticalSectionLock::Lock(this: &csLock);
    for ( i = 0; i < g_nConnections; ++i )
      VMPI_SendChunks(pChunks, pChunkLengths, nChunks, iDest: i, fVMPISendFlags: 0);
    CCriticalSectionLock::~CCriticalSectionLock(this: &csLock);
    return true;
  }
  if ( iDest == -3 )
  {
    CCriticalSectionLock::CCriticalSectionLock(this: &v18, pCS: &g_ConnectionsCS);
    CCriticalSectionLock::Lock(this: &v18);
    CCriticalSectionLock::CCriticalSectionLock(this: &csLock, pCS: &g_PersistentPacketsCS);
    CCriticalSectionLock::Lock(this: &csLock);
    v7 = nullptr;
    for ( j = 0; j < g_nConnections; ++j )
      VMPI_SendChunks(pChunks, pChunkLengths, nChunks, iDest: j, fVMPISendFlags: 0);
    v9 = (CUtlVector<char,CUtlMemory<char,int> > *)operator new(nSize: 0x14u);
    if ( v9 != nullptr )
    {
      v9->m_Memory.m_pMemory = nullptr;
      v9->m_Memory.m_nAllocationCount = 0;
      v9->m_Memory.m_nGrowSize = 0;
      v9->m_Size = 0;
      v9->m_pElements = nullptr;
      v7 = v9;
    }
    if ( nChunks > 0 )
    {
      v10 = pChunkLengths;
      for ( iDesta = nChunks; iDesta != 0; --iDesta )
      {
        CUtlVector<char,CUtlMemory<char,int>>::InsertMultipleBefore(
          this: v7,
          elem: v7->m_Size,
          num: *v10,
          pToInsert: *(const char **)((char *)v10 + (char *)pChunks - (char *)pChunkLengths));
        ++v10;
      }
    }
    v11 = CUtlLinkedList<CUtlVector<char,CUtlMemory<char,int>> *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlVector<char,CUtlMemory<char,int>> *,unsigned short>,unsigned short>>::AllocInternal(
            this: &g_PersistentPackets,
            multilist: false);
    v12 = v11;
    if ( v11 != 0xFFFF )
    {
      CUtlLinkedList<CUtlVector<char,CUtlMemory<char,int>> *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlVector<char,CUtlMemory<char,int>> *,unsigned short>,unsigned short>>::LinkBefore(
        this: &g_PersistentPackets,
        before: 0xFFFFu,
        elem: v11);
      v13 = &g_PersistentPackets.m_Memory.m_pMemory[v12];
      if ( v13 != nullptr )
        v13->m_Element = v7;
    }
    CCriticalSectionLock::~CCriticalSectionLock(this: &csLock);
    CCriticalSectionLock::~CCriticalSectionLock(this: &v18);
    return true;
  }
  else
  {
    ++g_nMessagesSent;
    v14 = g_nBytesSent + 4;
    v15 = 0;
    g_nBytesSent += 4;
    if ( nChunks > 0 )
    {
      do
      {
        v14 += pChunkLengths[v15++];
        g_nBytesSent = v14;
      }
      while ( v15 < nChunks );
    }
    v16 = g_Connections[iDest];
    if ( v16 == nullptr )
      return false;
    if ( VMPI_FilterPacketsForServiceDownloader(pConnection: v16, pChunks, pChunkLengths, nChunks) != 0 )
      return true;
    m_pSocket = v16->m_pSocket;
    if ( m_pSocket != nullptr )
    {
      if ( g_bGroupPackets && (fVMPISendFlags & 1) != 0 )
      {
        VMPI_GroupPackets(pConn: v16, pChunks, (char *)pChunkLengths, nChunks);
        return true;
      }
      else
      {
        return m_pSocket->SendChunks(this: m_pSocket, a2: pChunks, a3: pChunkLengths, a4: nChunks);
      }
    }
    else
    {
      return false;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001F3C0
// Name: bool VMPI_Send2Chunks(void const __near *,int,void const __near *,int,int,int)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl VMPI_Send2Chunks(
        const void *pChunk1,
        int chunk1Len,
        const void *pChunk2,
        int chunk2Len,
        int iDest,
        char fVMPISendFlags)
{
  const void *pChunks[2]; // [esp+0h] [ebp-10h] BYREF
  int len[2]; // [esp+8h] [ebp-8h] BYREF

  pChunks[1] = pChunk2;
  pChunks[0] = pChunk1;
  len[0] = chunk1Len;
  len[1] = chunk2Len;
  return VMPI_SendChunks(pChunks, pChunkLengths: len, nChunks: 2, iDest, fVMPISendFlags);
}

//------------------------------------------------------------------------------
// Address: 0x1001F400
// Name: bool VMPI_Send3Chunks(void const __near *,int,void const __near *,int,void const __near *,int,int,int)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl VMPI_Send3Chunks(
        const void *pChunk1,
        int chunk1Len,
        const void *pChunk2,
        int chunk2Len,
        const void *pChunk3,
        int chunk3Len,
        int iDest,
        char fVMPISendFlags)
{
  const void *pChunks[3]; // [esp+0h] [ebp-18h] BYREF
  int len[3]; // [esp+Ch] [ebp-Ch] BYREF

  pChunks[0] = pChunk1;
  pChunks[1] = pChunk2;
  len[0] = chunk1Len;
  pChunks[2] = pChunk3;
  len[1] = chunk2Len;
  len[2] = chunk3Len;
  return VMPI_SendChunks(pChunks, pChunkLengths: len, nChunks: 3, iDest, fVMPISendFlags);
}

//------------------------------------------------------------------------------
// Address: 0x1001F450
// Name: void VMPI_AddDisconnectHandler(void (*)(int,char const __near *))
// Source: json
//------------------------------------------------------------------------------
void __cdecl VMPI_AddDisconnectHandler(void (__cdecl *handler)(int, const char *))
{
  CUtlLinkedList<void (__cdecl *)(int,char const *),int,0,int,CUtlMemory<UtlLinkedListElem_t<void (__cdecl *)(int,char const *),int>,int>>::AddToTail(
    this: &g_DisconnectHandlers,
    src: &handler);
}

//------------------------------------------------------------------------------
// Address: 0x1001F470
// Name: void VMPI_SetMachineName(int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl VMPI_SetMachineName(int iProc, const char *pName)
{
  CVMPIConnection *v2; // esi

  if ( iProc >= 0 && iProc < g_nConnections )
  {
    v2 = g_Connections[iProc];
    if ( v2 != nullptr )
    {
      CUtlVector<char,CUtlMemory<char,int>>::CopyArray(this: &v2->m_MachineName, pArray: pName, size: strlen(pName) + 1);
      v2->m_bNameSet = true;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001F4C0
// Name: public: CVMPIConnection::CVMPIConnection(int)
// Source: json
//------------------------------------------------------------------------------
CVMPIConnection *__thiscall CVMPIConnection::CVMPIConnection(CVMPIConnection *this, int iConnection)
{
  char str[512]; // [esp+Ch] [ebp-200h] BYREF

  this->__vftable = (CVMPIConnection_vtbl *)&CVMPIConnection::`vftable';
  this->m_GroupedChunkLengths.m_Memory.m_pMemory = nullptr;
  this->m_GroupedChunkLengths.m_Memory.m_nAllocationCount = 0;
  this->m_GroupedChunkLengths.m_Memory.m_nGrowSize = 0;
  this->m_GroupedChunkLengths.m_Size = 0;
  this->m_GroupedChunkLengths.m_pElements = nullptr;
  this->m_GroupedChunks.m_Memory.m_pMemory = nullptr;
  this->m_GroupedChunks.m_Memory.m_nAllocationCount = 0;
  this->m_GroupedChunks.m_Memory.m_nGrowSize = 0;
  this->m_GroupedChunks.m_Size = 0;
  this->m_GroupedChunks.m_pElements = nullptr;
  this->m_MachineName.m_Memory.m_pMemory = nullptr;
  this->m_MachineName.m_Memory.m_nAllocationCount = 0;
  this->m_MachineName.m_Memory.m_nGrowSize = 0;
  this->m_MachineName.m_Size = 0;
  this->m_MachineName.m_pElements = nullptr;
  this->m_ErrorString.m_Memory.m_pMemory = nullptr;
  this->m_ErrorString.m_Memory.m_nAllocationCount = 0;
  this->m_ErrorString.m_Memory.m_nGrowSize = 0;
  this->m_ErrorString.m_Size = 0;
  this->m_ErrorString.m_pElements = nullptr;
  this->m_iConnection = iConnection;
  this->m_pSocket = nullptr;
  this->m_bIsAService = false;
  V_snprintf(pDest: str, maxLen: 0x200u, pFormat: "%d", iConnection);
  CUtlVector<char,CUtlMemory<char,int>>::CopyArray(this: &this->m_MachineName, pArray: str, size: strlen(str) + 1);
  *(_WORD *)&this->m_bNameSet = 0;
  this->m_JobWorkerID = -1;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1001F580
// Name: public: virtual void CVMPIConnection::Init(class IThreadedTCPSocket __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVMPIConnection::Init(CVMPIConnection *this, IThreadedTCPSocket *pSocket)
{
  this->m_pSocket = pSocket;
}

//------------------------------------------------------------------------------
// Address: 0x1001F590
// Name: public: virtual int CVMPIConnection::GetConnectionID(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CVMPIConnection::GetConnectionID(CVMPIConnection *this)
{
  return this->m_iConnection;
}

//------------------------------------------------------------------------------
// Address: 0x1001F5A0
// Name: public: virtual void CVMPIConnection::Release(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVMPIConnection::Release(CVMPIConnection *this, bool bForce)
{
  int m_iConnection; // esi
  CVMPIConnection *v3; // ecx

  if ( !this->m_bInErrorState || bForce )
  {
    m_iConnection = this->m_iConnection;
    this->m_pSocket = nullptr;
    v3 = g_Connections[m_iConnection];
    if ( v3 != nullptr )
      ((void (__thiscall *)(CVMPIConnection *, int))v3->dtr_CVMPIConnection)(a1: v3, a2: 1);
    g_Connections[m_iConnection] = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001F840
// Name: public: virtual void CVMPIConnection::OnPacketReceived(class CTCPPacket __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVMPIConnection::OnPacketReceived(CVMPIConnection *this, CTCPPacket *pPacket)
{
  CCriticalSectionLock csLock; // [esp+0h] [ebp-8h] BYREF

  CTCPPacket::SetUserData(this: pPacket, userData: this->m_iConnection);
  CCriticalSectionLock::CCriticalSectionLock(this: &csLock, pCS: &g_VMPIMessagesCS);
  CCriticalSectionLock::Lock(this: &csLock);
  CUtlLinkedList<CTCPPacket *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CTCPPacket *,int>,int>>::AddToTail(
    this: &g_VMPIMessages,
    src: &pPacket);
  if ( g_VMPIMessages.m_ElementCount == 1 )
    CEvent::SetEvent(this: &g_VMPIMessagesEvent);
  CCriticalSectionLock::~CCriticalSectionLock(this: &csLock);
}

//------------------------------------------------------------------------------
// Address: 0x1001F8A0
// Name: public: virtual void CVMPIConnection::OnError(int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVMPIConnection::OnError(CVMPIConnection *this, int errorCode, const char *pErrorString)
{
  const char *v3; // edi
  CCriticalSectionLock csLock; // [esp+8h] [ebp-8h] BYREF

  v3 = pErrorString;
  if ( !g_bMPIMaster )
    _Msg(a1: "%s - CVMPIConnection::OnError( %s )\n", this->m_MachineName.m_Memory.m_pMemory, pErrorString);
  CCriticalSectionLock::CCriticalSectionLock(this: &csLock, pCS: &g_ErrorSocketsCS);
  CCriticalSectionLock::Lock(this: &csLock);
  if ( !this->m_bInErrorState )
  {
    this->m_bInErrorState = true;
    CUtlVector<char,CUtlMemory<char,int>>::CopyArray(this: &this->m_ErrorString, pArray: v3, size: strlen(v3) + 1);
    pErrorString = (const char *)this;
    CUtlLinkedList<CVMPIConnection *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CVMPIConnection *,int>,int>>::AddToTail(
      this: &g_ErrorSockets,
      src: (CVMPIConnection **)&pErrorString);
    CEvent::SetEvent(this: &g_ErrorSocketsEvent);
    InterlockedIncrement(lpAddend: &this->m_ErrorSignal);
  }
  CCriticalSectionLock::~CCriticalSectionLock(this: &csLock);
}

//------------------------------------------------------------------------------
// Address: 0x1001F940
// Name: public: virtual class ITCPSocketHandler __near * CVMPIConnectionCreator::CreateNewHandler(void)
// Source: json
//------------------------------------------------------------------------------
CVMPIConnection *__thiscall CVMPIConnectionCreator::CreateNewHandler(CVMPIConnectionCreator *this)
{
  int v1; // edi
  CVMPIConnection *v2; // eax
  CVMPIConnection *result; // eax
  _DWORD *v4; // eax
  _DWORD *v5; // esi
  int v6; // edi
  int v7; // ecx
  char pDest[512]; // [esp+8h] [ebp-204h] BYREF
  int i; // [esp+208h] [ebp-4h]

  v1 = 0;
  if ( g_nConnections <= 0 )
  {
LABEL_4:
    v2 = (CVMPIConnection *)operator new(nSize: 0x6Cu);
    if ( v2 != nullptr )
      result = CVMPIConnection::CVMPIConnection(this: v2, iConnection: g_nConnections);
    else
      result = nullptr;
    v7 = g_nConnections;
    g_Connections[g_nConnections] = result;
    g_nConnections = v7 + 1;
  }
  else
  {
    while ( g_Connections[v1] != nullptr )
    {
      if ( ++v1 >= g_nConnections )
        goto LABEL_4;
    }
    i = v1;
    v4 = operator new(nSize: 0x6Cu);
    v5 = v4;
    if ( v4 != nullptr )
    {
      *v4 = &CVMPIConnection::`vftable';
      v4[3] = 0;
      v4[4] = 0;
      v4[5] = 0;
      v4[6] = 0;
      v4[7] = 0;
      v4[8] = 0;
      v4[9] = 0;
      v4[10] = 0;
      v4[11] = 0;
      v4[12] = 0;
      v4[13] = 0;
      v4[14] = 0;
      v4[15] = 0;
      v4[16] = 0;
      v4[17] = 0;
      v4[18] = 0;
      v4[19] = 0;
      v4[20] = 0;
      v4[21] = 0;
      v4[22] = 0;
      v4[24] = v1;
      v4[25] = 0;
      *((_BYTE *)v4 + 8) = 0;
      V_snprintf(pDest, maxLen: 0x200u, pFormat: "%d", v1);
      CUtlVector<char,CUtlMemory<char,int>>::CopyArray(
        this: (CUtlVector<char,CUtlMemory<char,int> > *)(v5 + 13),
        pArray: pDest,
        size: strlen(pDest) + 1);
      v6 = i;
      *((_WORD *)v5 + 52) = 0;
      v5[1] = -1;
      g_Connections[v6] = (CVMPIConnection *)v5;
      return (CVMPIConnection *)v5;
    }
    else
    {
      g_Connections[v1] = nullptr;
      return nullptr;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1001FA90
// Name: bool VMPI_InternalDispatchFn(class MessageBuffer __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
char __cdecl VMPI_InternalDispatchFn(CVMPIFile_Memory *pBuf, int iSource)
{
  char v2; // al
  bool v4; // al
  unsigned int v5; // esi
  char *v6; // edi
  int m_Size; // eax
  int v8; // esi
  char **m_pMemory; // ecx
  int v10; // eax
  char **v11; // eax
  char pOut[4096]; // [esp+4h] [ebp-1008h] BYREF
  int i; // [esp+1004h] [ebp-8h]
  int p; // [esp+1008h] [ebp-4h] BYREF

  if ( (int)ConCommandBase::GetName(this: pBuf) < 2 )
    return 0;
  v2 = BYTE1(pBuf->Close);
  switch ( v2 )
  {
    case 1:
      if ( (int)ConCommandBase::GetName(this: pBuf) >= 3 )
      {
        VMPI_SuperSpew(pMsg: "Received SUBPACKET_MACHINE_NAME (%s).\n", (const char *)&pBuf->Close + 2);
        VMPI_SetMachineName(iProc: iSource, pName: (const char *)&pBuf->Close + 2);
        return 1;
      }
      VMPI_SuperSpew(pMsg: "Received invalid SUBPACKET_MACHINE_NAME packet (not long enough!)\n");
      return 0;
    case 3:
      if ( g_bVMPISDKModeSet )
        v4 = g_bVMPISDKMode;
      else
        v4 = !VMPI_CheckForNonSDKExecutables();
      if ( !v4 )
        _Warning(a1: "Worker %d is running in SDK mode (and the master is not)!\n", iSource);
      return 1;
    case 2:
      MessageBuffer::setOffset(this: (MessageBuffer *)pBuf, noffset: 2);
      MessageBuffer::read(this: (MessageBuffer *)pBuf, &p, bytes: 4);
      for ( i = 0; i < p; ++i )
      {
        if ( MessageBuffer::ReadString(this: (MessageBuffer *)pBuf, pOut, bufferLength: 4096) == -1 )
          _Error(a1: "Error in ReadString() while reading command line.");
        v5 = _V_strlen(str: pOut) + 1;
        v6 = (char *)operator new(nSize: v5);
        V_strncpy(pDest: v6, pSrc: pOut, maxLen: v5);
        m_Size = g_WorkerCommandLine.m_Size;
        v8 = g_WorkerCommandLine.m_Size;
        if ( g_WorkerCommandLine.m_Size + 1 > g_WorkerCommandLine.m_Memory.m_nAllocationCount )
        {
          CUtlMemory<int,int>::Grow(
            this: (CUtlMemory<CTCPPacket *,int> *)&g_WorkerCommandLine,
            num: g_WorkerCommandLine.m_Size - g_WorkerCommandLine.m_Memory.m_nAllocationCount + 1);
          m_Size = g_WorkerCommandLine.m_Size;
        }
        m_pMemory = g_WorkerCommandLine.m_Memory.m_pMemory;
        g_WorkerCommandLine.m_Size = m_Size + 1;
        v10 = m_Size - v8;
        g_WorkerCommandLine.m_pElements = g_WorkerCommandLine.m_Memory.m_pMemory;
        if ( v10 > 0 )
        {
          _V_memmove(
            dest: (unsigned __int8 *)&g_WorkerCommandLine.m_Memory.m_pMemory[v8 + 1],
            src: (unsigned __int8 *)&g_WorkerCommandLine.m_Memory.m_pMemory[v8],
            count: 4 * v10);
          m_pMemory = g_WorkerCommandLine.m_Memory.m_pMemory;
        }
        v11 = &m_pMemory[v8];
        if ( v11 != nullptr )
          *v11 = v6;
      }
      g_bReceivedWorkerCommandLine = true;
      return 1;
    default:
      break;
  }
  if ( v2 != 6 )
  {
    if ( v2 == 5 )
    {
      g_bTimingWaitDone = true;
      return 1;
    }
    return 0;
  }
  MessageBuffer::setOffset(this: (MessageBuffer *)pBuf, noffset: 2);
  if ( MessageBuffer::ReadString(this: (MessageBuffer *)pBuf, pOut: g_MasterExeName, bufferLength: 260) == -1 )
    _Error(a1: "Error in ReadString() while reading VMPI_INTERNAL_SUBPACKET_VERIFY_EXE_NAME.");
  VMPI_SuperSpew(pMsg: "Received SUBPACKET_VERIFY_EXE_NAME (%s).\n", g_MasterExeName);
  g_bReceivedMasterExeName = true;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1001FCB0
// Name: void VMPI_ReceiveExeName(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl VMPI_ReceiveExeName()
{
  TSLHead_t m_Head; // kr00_8
  MessageBuffer *v1; // eax
  MessageBuffer *v2; // edi
  char v3; // al
  TSLNodeBase_t **v4; // eax
  TSLNodeBase_t **v5; // esi
  HMODULE ModuleHandleA; // eax
  int v7; // [esp-18h] [ebp-22Ch]
  int v8; // [esp-18h] [ebp-22Ch]
  TSLHead_t v9; // [esp-14h] [ebp-228h]
  TSLHead_t v10; // [esp-14h] [ebp-228h]
  char baseExeFilename[260]; // [esp+0h] [ebp-214h] BYREF
  char fileBase[260]; // [esp+104h] [ebp-110h] BYREF
  double startTime; // [esp+208h] [ebp-Ch]
  int pSource; // [esp+210h] [ebp-4h] BYREF

  startTime = _Plat_FloatTime();
  while ( !g_bReceivedMasterExeName )
  {
    if ( _Plat_FloatTime() - startTime > 30.0 )
      _Error(a1: "VMPI_ReceiveExeName: timeout.");
    m_Head = g_DispatchBuffers.m_Head;
    if ( g_DispatchBuffers.m_Head.value.Next == nullptr )
      goto LABEL_7;
    while ( (unsigned __int8)_ThreadInterlockedAssignIf64(
                               a1: &g_DispatchBuffers,
                               a2: m_Head.value.Next->Next,
                               a3: m_Head.value32.DepthAndSequence - 1,
                               a4: m_Head.value.Next,
                               a5: m_Head.value32.DepthAndSequence) == 0 )
    {
      _mm_pause();
      m_Head = g_DispatchBuffers.m_Head;
      if ( g_DispatchBuffers.m_Head.value.Next == nullptr )
        goto LABEL_7;
    }
    if ( m_Head.value.Next != nullptr )
    {
      v2 = *((MessageBuffer **)&m_Head.value.Next->Next + 1);
      free(pMem: m_Head.value.Next);
    }
    else
    {
LABEL_7:
      v1 = (MessageBuffer *)operator new(nSize: 0x10u);
      if ( v1 != nullptr )
        v2 = MessageBuffer::MessageBuffer(this: v1);
      else
        v2 = nullptr;
    }
    while ( VMPI_GetNextMessage(pBuf: v2, &pSource, startTimeout: (CTCPPacket *)0x2710) != 0 )
    {
      if ( (int)ConCommandBase::GetName(this: (CVMPIFile_Memory *)v2) >= 1 )
      {
        v3 = *v2->data;
        if ( (unsigned __int8)v3 < 0x20u
          && g_VMPIDispatch[v3] != nullptr
          && g_VMPIDispatch[v3](a1: v2, a2: pSource, a3: v3) )
        {
          break;
        }
      }
    }
    v4 = (TSLNodeBase_t **)operator new(nSize: 8u);
    if ( v4 != nullptr )
    {
      v4[1] = (TSLNodeBase_t *)v2;
      v5 = v4;
    }
    else
    {
      v5 = nullptr;
    }
    v9 = g_DispatchBuffers.m_Head;
    v7 = g_DispatchBuffers.m_Head.value32.DepthAndSequence + 65537;
    *v5 = g_DispatchBuffers.m_Head.value.Next;
    if ( (unsigned __int8)_ThreadInterlockedAssignIf64(
                            a1: &g_DispatchBuffers,
                            a2: v5,
                            a3: v7,
                            a4: v9.value.Next,
                            a5: v9.value32.DepthAndSequence) == 0 )
    {
      do
      {
        _mm_pause();
        v10 = g_DispatchBuffers.m_Head;
        v8 = g_DispatchBuffers.m_Head.value32.DepthAndSequence + 65537;
        *v5 = g_DispatchBuffers.m_Head.value.Next;
      }
      while ( (unsigned __int8)_ThreadInterlockedAssignIf64(
                                 a1: &g_DispatchBuffers,
                                 a2: v5,
                                 a3: v8,
                                 a4: v10.value.Next,
                                 a5: v10.value32.DepthAndSequence) == 0 );
    }
  }
  ModuleHandleA = GetModuleHandleA(lpModuleName: nullptr);
  if ( GetModuleFileNameA(hModule: ModuleHandleA, lpFilename: baseExeFilename, nSize: 0x104u) == 0 )
    _Error(a1: "VMPI_CheckSDKMode -> GetModuleFileName failed.");
  V_FileBase(in: baseExeFilename, out: fileBase, maxlen: 260);
  if ( _V_stricmp(s1: fileBase, s2: "vmpi_transfer") != 0 && _V_stricmp(s1: fileBase, s2: g_MasterExeName) != 0 )
    _Error(
      a1: "VMPI_ReceiveExeName: mismatched exe names (master: %s, me: %s).\n"
      "This usually just means the master finished a job like vvis really fast and started a vrad immediately, and an old"
      " vvis worker connected to the new vrad job.",
      g_MasterExeName,
      fileBase);
}

//------------------------------------------------------------------------------
// Address: 0x1001FEE0
// Name: bool VMPI_SendData(void __near *,int,int,int)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl VMPI_SendData(void *pData, int nBytes, int iDest, char fVMPISendFlags)
{
  return VMPI_SendChunks(
           pChunks: (const void *const *)&pData,
           pChunkLengths: &nBytes,
           nChunks: 1,
           iDest,
           fVMPISendFlags);
}

//------------------------------------------------------------------------------
// Address: 0x1001FF00
// Name: void VMPI_SendMachineNameTo(int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl VMPI_SendMachineNameTo(int iProc)
{
  const char *v1; // esi
  unsigned __int8 packetData[768]; // [esp+4h] [ebp-308h] BYREF
  void *pChunks; // [esp+304h] [ebp-8h] BYREF
  unsigned int nSize; // [esp+308h] [ebp-4h] BYREF

  nSize = 16;
  v1 = cName;
  if ( !GetComputerNameA(lpBuffer: cName, &nSize) )
    v1 = "(error in GetComputerName)";
  VMPI_SuperSpew(pMsg: "Sent SUBPACKET_MACHINE_NAME (%s).\n", v1);
  *(_WORD *)packetData = 283;
  V_strncpy(pDest: (char *)&packetData[2], pSrc: v1, maxLen: 766);
  nSize = strlen(v1) + 3;
  pChunks = packetData;
  VMPI_SendChunks(
    (const void *const *)&pChunks,
    pChunkLengths: (int *)&nSize,
    nChunks: 1,
    iDest: iProc,
    fVMPISendFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1001FFA0
// Name: void VMPI_SendCommandLine(int,char __near * __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl VMPI_SendCommandLine(int argc, char **argv)
{
  int v2; // esi
  char **v3; // edi
  MessageBuffer mb; // [esp+4h] [ebp-1Ch] BYREF
  void *pChunks; // [esp+14h] [ebp-Ch] BYREF
  int pChunkLengths; // [esp+18h] [ebp-8h] BYREF
  char cPacketHeader[2]; // [esp+1Ch] [ebp-4h] BYREF

  MessageBuffer::MessageBuffer(this: &mb);
  *(_WORD *)cPacketHeader = 539;
  MessageBuffer::write(this: &mb, p: cPacketHeader, bytes: 2);
  MessageBuffer::write(this: &mb, p: &argc, bytes: 4);
  v2 = 0;
  if ( argc > 0 )
  {
    v3 = argv;
    do
      MessageBuffer::WriteString(this: &mb, pString: v3[v2++]);
    while ( v2 < argc );
  }
  pChunkLengths = ConCommandBase::GetName(this: (CVMPIFile_Memory *)&mb);
  pChunks = mb.data;
  VMPI_SendChunks((const void *const *)&pChunks, &pChunkLengths, nChunks: 1, iDest: -3, fVMPISendFlags: 0);
  MessageBuffer::~MessageBuffer(this: &mb);
}

//------------------------------------------------------------------------------
// Address: 0x10020030
// Name: void VMPI_ReceiveCommandLine(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl VMPI_ReceiveCommandLine()
{
  CVMPIConnection *v0; // esi
  IThreadedTCPSocket *m_pSocket; // ecx
  double startTime; // [esp+4h] [ebp-10h] BYREF
  int pChunkLengths; // [esp+Ch] [ebp-8h] BYREF
  unsigned __int8 chData[2]; // [esp+10h] [ebp-4h] BYREF

  ++g_nMessagesSent;
  HIDWORD(startTime) = chData;
  v0 = g_Connections[0];
  *(_WORD *)chData = 795;
  pChunkLengths = 2;
  g_nBytesSent += 6;
  if ( g_Connections[0] != nullptr
    && VMPI_FilterPacketsForServiceDownloader(
         pConnection: g_Connections[0],
         pChunks: (const void *const *)&startTime + 1,
         &pChunkLengths,
         nChunks: 1) == 0 )
  {
    m_pSocket = v0->m_pSocket;
    if ( m_pSocket != nullptr )
      m_pSocket->SendChunks(this: m_pSocket, a2: (const void *const *)&startTime + 1, a3: &pChunkLengths, a4: 1);
  }
  startTime = _Plat_FloatTime();
  while ( !g_bReceivedWorkerCommandLine )
  {
    if ( _Plat_FloatTime() - startTime > 30.0 )
      _Error(a1: "VMPI_ReceiveCommandLine: timeout. Is the master running in SDK mode?");
    VMPI_DispatchNextMessage(timeout: (CTCPPacket *)0x2710);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100200F0
// Name: void VMPI_SendExeName(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl VMPI_SendExeName()
{
  HMODULE ModuleHandleA; // eax
  char baseExeFilename[260]; // [esp+0h] [ebp-224h] BYREF
  char fileBase[260]; // [esp+104h] [ebp-120h] BYREF
  MessageBuffer mb; // [esp+208h] [ebp-1Ch] BYREF
  int pChunkLengths; // [esp+218h] [ebp-Ch] BYREF
  void *pChunks; // [esp+21Ch] [ebp-8h] BYREF
  char cPacketHeader[2]; // [esp+220h] [ebp-4h] BYREF

  MessageBuffer::MessageBuffer(this: &mb);
  *(_WORD *)cPacketHeader = 1563;
  MessageBuffer::write(this: &mb, p: cPacketHeader, bytes: 2);
  ModuleHandleA = GetModuleHandleA(lpModuleName: nullptr);
  if ( GetModuleFileNameA(hModule: ModuleHandleA, lpFilename: baseExeFilename, nSize: 0x104u) == 0 )
    _Error(a1: "VMPI_CheckSDKMode -> GetModuleFileName failed.");
  V_FileBase(in: baseExeFilename, out: fileBase, maxlen: 260);
  MessageBuffer::WriteString(this: &mb, pString: fileBase);
  VMPI_SuperSpew(pMsg: "Sending SUBPACKET_VERIFY_EXE_NAME (%s).\n", fileBase);
  pChunkLengths = ConCommandBase::GetName(this: (CVMPIFile_Memory *)&mb);
  pChunks = mb.data;
  VMPI_SendChunks((const void *const *)&pChunks, &pChunkLengths, nChunks: 1, iDest: -3, fVMPISendFlags: 0);
  MessageBuffer::~MessageBuffer(this: &mb);
}

//------------------------------------------------------------------------------
// Address: 0x100201C0
// Name: private: void CMasterBroadcaster::ThreadFn(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMasterBroadcaster::ThreadFn(CMasterBroadcaster *this)
{
  void *UserData; // eax
  int v3; // edi
  int v4; // ebx
  int v5; // edi
  unsigned int v6; // edx
  ITCPConnectSocket *m_pListenSocket; // ecx
  bool v8; // al
  IThreadedTCPSocket *v9; // edx
  ITCPConnectSocket *m_pDownloaderListenSocket; // ecx
  IThreadedTCPSocket *v11; // edi
  int v12; // eax
  CVMPIConnection *v13; // ecx
  CVMPIConnection *v14; // edi
  ITCPSocketHandler *(__thiscall *GetHandler)(IThreadedTCPSocket *); // eax
  int *v16; // eax
  int m_Next; // edx
  UtlLinkedListElem_t<CUtlVector<char,CUtlMemory<char,int> > *,unsigned short> *m_pMemory; // edi
  int v19; // ebx
  CUtlVector<char,CUtlMemory<char,int> > *m_Element; // edi
  unsigned __int8 *m_Size; // ecx
  int v22; // edx
  int v23; // eax
  int v24; // edi
  void *v25; // eax
  char pData[768]; // [esp+4h] [ebp-3E8h] BYREF
  char pPacketIDString[64]; // [esp+304h] [ebp-E8h] BYREF
  char pSubPacketIDString[64]; // [esp+344h] [ebp-A8h] BYREF
  char v29; // [esp+384h] [ebp-68h] BYREF
  int v30; // [esp+388h] [ebp-64h]
  bf_write buf; // [esp+38Ch] [ebp-60h] BYREF
  CCriticalSectionLock v32; // [esp+3A4h] [ebp-48h] BYREF
  CCriticalSectionLock v33; // [esp+3ACh] [ebp-40h] BYREF
  char *v34; // [esp+3B4h] [ebp-38h]
  void *pChunks; // [esp+3B8h] [ebp-34h] BYREF
  int v36; // [esp+3BCh] [ebp-30h]
  int pChunkLengths; // [esp+3C0h] [ebp-2Ch] BYREF
  int nServiceDownloaders; // [esp+3C4h] [ebp-28h] BYREF
  unsigned int startTime; // [esp+3C8h] [ebp-24h]
  CCriticalSectionLock v40; // [esp+3CCh] [ebp-20h] BYREF
  int v41; // [esp+3D4h] [ebp-18h] BYREF
  __int16 v42; // [esp+3D8h] [ebp-14h]
  int nRegularWorkers; // [esp+3DCh] [ebp-10h] BYREF
  int v44; // [esp+3E0h] [ebp-Ch]
  IThreadedTCPSocket *v45; // [esp+3E4h] [ebp-8h] BYREF
  int v46; // [esp+3E8h] [ebp-4h]

  UserData = CTCPPacket::GetUserData(this: &this->m_hShutdownEvent);
  if ( WaitForSingleObject(hHandle: UserData, dwMilliseconds: 0x14u) == 258 )
  {
    do
    {
      startTime = GetTickCount();
      while ( 1 )
      {
        CCriticalSectionLock::CCriticalSectionLock(this: &v40, pCS: &g_ConnectionsCS);
        CCriticalSectionLock::Lock(this: &v40);
        CountActiveConnections(&nRegularWorkers, &nServiceDownloaders);
        if ( nRegularWorkers >= this->m_nMaxWorkers )
          break;
        if ( this->m_pSocket != nullptr )
        {
          v44 = _Plat_MSTime();
          if ( v44 - this->m_LastSendTime >= 0x258 )
          {
            bf_write::bf_write(this: &buf, pDebugName: "packetBuf", pData, nBytes: 768, nBits: -1);
            CMasterBroadcaster::BuildBroadcastPacket(this, &buf);
            v3 = 23397;
            v46 = 23397;
            do
            {
              if ( this->m_bPatching )
              {
                v4 = 0;
                if ( this->m_PatchWorkerIPs.m_Size > 0 )
                {
                  v5 = 0;
                  do
                  {
                    v41 = *(_DWORD *)this->m_PatchWorkerIPs.m_Memory.m_pMemory[v5].ip;
                    v42 = v46;
                    if ( !this->m_pSocket->SendTo(
                            this: this->m_pSocket,
                            a2: (const CIPAddr *)&v41,
                            a3: buf.m_pData,
                            a4: (buf.m_iCurBit + 7) >> 3) )
                      VMPI_WriteToLogFile(pMsg: "Error in SendTo trying to send patch request packet!\n");
                    _ThreadSleep(a1: 2);
                    ++v4;
                    ++v5;
                  }
                  while ( v4 < this->m_PatchWorkerIPs.m_Size );
                  v3 = v46;
                }
              }
              else
              {
                this->m_pSocket->Broadcast(this: this->m_pSocket, a2: buf.m_pData, a3: (buf.m_iCurBit + 7) >> 3, a4: v3);
              }
              v46 = ++v3;
            }
            while ( v3 <= 23412 );
            this->m_PatchWorkerIPs.m_Size = 0;
            if ( this->m_PatchWorkerIPs.m_Memory.m_nGrowSize >= 0 )
            {
              if ( this->m_PatchWorkerIPs.m_Memory.m_pMemory != nullptr )
              {
                _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)this->m_PatchWorkerIPs.m_Memory.m_pMemory);
                this->m_PatchWorkerIPs.m_Memory.m_pMemory = nullptr;
              }
              this->m_PatchWorkerIPs.m_Memory.m_nAllocationCount = 0;
            }
            v6 = v44;
            this->m_PatchWorkerIPs.m_pElements = this->m_PatchWorkerIPs.m_Memory.m_pMemory;
            this->m_LastSendTime = v6;
          }
        }
        m_pListenSocket = this->m_pListenSocket;
        v45 = nullptr;
        v8 = m_pListenSocket->Update(this: m_pListenSocket, a2: &v45, a3: 0);
        v9 = v45;
        if ( !v8 || v45 == nullptr )
        {
          m_pDownloaderListenSocket = this->m_pDownloaderListenSocket;
          if ( m_pDownloaderListenSocket != nullptr && nServiceDownloaders < this->m_nMaxWorkers - nRegularWorkers + 8 )
          {
            v8 = m_pDownloaderListenSocket->Update(this: m_pDownloaderListenSocket, a2: &v45, a3: 0);
            v9 = v45;
          }
        }
        if ( !v8 || v9 == nullptr )
          break;
        v9->GetRemoteAddr(this: v9, result: (CIPAddr *)&v29);
        if ( (unsigned __int16)(v30 - 22351) <= 9u )
        {
          v11 = v45;
          CCriticalSectionLock::CCriticalSectionLock(this: &v33, pCS: &g_ConnectionsCS);
          v12 = 0;
          if ( g_nConnections <= 0 )
          {
LABEL_33:
            CCriticalSectionLock::~CCriticalSectionLock(this: &v33);
          }
          else
          {
            while ( 1 )
            {
              v13 = g_Connections[v12];
              if ( v13 != nullptr && v13->m_pSocket == v11 )
                break;
              if ( ++v12 >= g_nConnections )
                goto LABEL_33;
            }
            v14 = g_Connections[v12];
            CCriticalSectionLock::~CCriticalSectionLock(this: &v33);
            if ( v14 != nullptr )
              v14->m_bIsAService = true;
          }
        }
        CCriticalSectionLock::CCriticalSectionLock(this: &v32, pCS: &g_PersistentPacketsCS);
        CCriticalSectionLock::Lock(this: &v32);
        GetHandler = v45->GetHandler;
        v46 = 1;
        v16 = (int *)GetHandler(this: v45);
        LOWORD(m_Next) = g_PersistentPackets.m_Head;
        v44 = (int)v16;
        if ( g_PersistentPackets.m_Head != 0xFFFF )
        {
          m_pMemory = g_PersistentPackets.m_Memory.m_pMemory;
          while ( 1 )
          {
            v19 = (unsigned __int16)m_Next;
            m_Element = m_pMemory[v19].m_Element;
            m_Size = (unsigned __int8 *)m_Element->m_Size;
            v34 = m_Element->m_Memory.m_pMemory;
            v22 = *v16;
            v36 = (int)m_Size;
            v23 = (*(int (__thiscall **)(int *))(v22 + 16))(a1: v16);
            pChunkLengths = v36;
            pChunks = v34;
            VMPI_SendChunks((const void *const *)&pChunks, &pChunkLengths, nChunks: 1, iDest: v23, fVMPISendFlags: 0);
            if ( g_bSuperSpewEnabled )
            {
              if ( m_Element->m_Size <= 2 )
              {
                VMPI_SuperSpew(pMsg: "Sending a really short persistent packet (%d bytes).\n", m_Element->m_Size);
              }
              else
              {
                CVMPIPacketIDReg::Lookup(
                  nPacketID: *(unsigned __int8 *)m_Element->m_Memory.m_pMemory,
                  nSubPacketID: *((unsigned __int8 *)m_Element->m_Memory.m_pMemory + 1),
                  pPacketIDString,
                  nPacketIDStringSize: 64,
                  pSubPacketIDString,
                  nSubPacketIDStringSize: 64);
                v24 = v46;
                VMPI_SuperSpew(
                  pMsg: "Sending persistent packet %d. PacketID: %s, SubPacketID: %s.\n",
                  v46,
                  pPacketIDString,
                  pSubPacketIDString);
                v46 = v24 + 1;
              }
            }
            m_pMemory = g_PersistentPackets.m_Memory.m_pMemory;
            m_Next = g_PersistentPackets.m_Memory.m_pMemory[v19].m_Next;
            if ( m_Next == 0xFFFF )
              break;
            v16 = (int *)v44;
          }
        }
        UpdateActiveConnectionsText();
        CCriticalSectionLock::~CCriticalSectionLock(this: &v32);
        CCriticalSectionLock::~CCriticalSectionLock(this: &v40);
        if ( GetTickCount() - startTime >= 0x1F4 )
          goto LABEL_47;
      }
      CCriticalSectionLock::~CCriticalSectionLock(this: &v40);
LABEL_47:
      v25 = CTCPPacket::GetUserData(this: &this->m_hShutdownEvent);
    }
    while ( WaitForSingleObject(hHandle: v25, dwMilliseconds: 0x14u) == 258 );
  }
  CEvent::SetEvent(this: &this->m_hShutdownReply);
}

//------------------------------------------------------------------------------
// Address: 0x100205B0
// Name: private: static unsigned long CMasterBroadcaster::StaticThreadFn(void __near *)
// Source: json
//------------------------------------------------------------------------------
unsigned int __stdcall CMasterBroadcaster::StaticThreadFn(CMasterBroadcaster *lpParameter)
{
  CMasterBroadcaster::ThreadFn(this: lpParameter);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x100205D0
// Name: void VMPI_HandleTimingWait_Master(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl VMPI_HandleTimingWait_Master()
{
  int v0; // eax
  void *pChunks; // [esp+0h] [ebp-Ch] BYREF
  int pChunkLengths; // [esp+4h] [ebp-8h] BYREF
  unsigned __int8 cPacket[2]; // [esp+8h] [ebp-4h] BYREF

  v0 = _CommandLine();
  if ( (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v0 + 40))(a1: v0, a2: g_VMPIParams[9].m_pName) != 0 )
  {
    _Msg(a1: "-mpi_TimingWait specified. Waiting for a keypress to continue... ");
    getch();
    _Msg(a1: "\n");
    *(_WORD *)cPacket = 1307;
    pChunkLengths = 2;
    pChunks = cPacket;
    VMPI_SendChunks((const void *const *)&pChunks, &pChunkLengths, nChunks: 1, iDest: -3, fVMPISendFlags: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10020640
// Name: bool MPI_Init_Worker(int __near &,char __near * __near * __near &,class CIPAddr const __near &,bool)
// Source: json
//------------------------------------------------------------------------------
char __cdecl MPI_Init_Worker(
        int *argc,
        char ***argv,
        const CIPAddr *masterAddr,
        IThreadedTCPSocket *bConnectingAsService)
{
  int v4; // edi
  ITCPConnectSocket *v5; // esi
  const CIPAddr *v6; // eax
  void (*v7)(const char *, ...); // edi
  bool (__thiscall *Update)(ITCPConnectSocket *, IThreadedTCPSocket **, unsigned int); // edx
  void (__thiscall ***v9)(_DWORD, int, char **); // eax
  int i; // esi
  int v11; // eax
  int v13; // eax
  int v14; // esi
  int flSeconds; // [esp+0h] [ebp-34h]
  CWaitTimer wait; // [esp+14h] [ebp-20h] BYREF
  CIPAddr v17; // [esp+1Eh] [ebp-16h] BYREF
  CVMPIConnectionCreator connectionCreator; // [esp+24h] [ebp-10h] BYREF
  int nAttempts; // [esp+28h] [ebp-Ch]
  int iFirstPort; // [esp+2Ch] [ebp-8h]
  int iLastPort; // [esp+30h] [ebp-4h]

  v4 = 22340;
  g_bMPIMaster = false;
  connectionCreator.__vftable = (CVMPIConnectionCreator_vtbl *)&CVMPIConnectionCreator::`vftable';
  iFirstPort = 22340;
  iLastPort = 22350;
  if ( (_BYTE)bConnectingAsService != 0 )
  {
    iFirstPort = 22351;
    v4 = 22351;
    iLastPort = 22360;
  }
  nAttempts = 1;
  while ( 2 )
  {
    v5 = nullptr;
    if ( v4 > iLastPort )
    {
LABEL_8:
      flSeconds = v4;
      v7 = (void (*)(const char *, ...))_Error;
      _Error(a1: "Can't bind a port in range [%d, %d].", flSeconds, iLastPort);
    }
    else
    {
      while ( 1 )
      {
        v6 = CIPAddr::CIPAddr(this: &v17, ip0: 0, ip1: 0, ip2: 0, ip3: 0, ipPort: v4);
        v5 = ThreadedTCP_CreateConnector(addr: masterAddr, localAddr: v6, pHandlerCreator: &connectionCreator);
        if ( v5 != nullptr )
          break;
        if ( ++v4 > iLastPort )
        {
          v4 = iFirstPort;
          goto LABEL_8;
        }
      }
      v7 = (void (*)(const char *, ...))_Error;
    }
    CWaitTimer::CWaitTimer(this: &wait, flSeconds: 3.0);
    while ( 1 )
    {
      Update = v5->Update;
      bConnectingAsService = nullptr;
      if ( Update(this: v5, a2: &bConnectingAsService, a3: 100u) )
      {
        if ( bConnectingAsService != nullptr )
        {
          VMPI_SendMachineNameTo(iProc: 0);
          VMPI_ReceiveExeName();
          if ( g_bVMPISDKMode )
          {
            VMPI_ReceiveCommandLine();
            v9 = (void (__thiscall ***)(_DWORD, int, char **))_CommandLine();
            (**v9)(a1: v9, a2: g_WorkerCommandLine.m_Size, a3: g_WorkerCommandLine.m_Memory.m_pMemory);
            *argc = g_WorkerCommandLine.m_Size;
            *argv = g_WorkerCommandLine.m_Memory.m_pMemory;
          }
          ParseOptions(argc: g_WorkerCommandLine.m_Size, argv: g_WorkerCommandLine.m_Memory.m_pMemory);
          for ( i = 0; i < g_WorkerCommandLine.m_Size; ++i )
            _Msg(a1: "arg %d: %s\n", i, g_WorkerCommandLine.m_Memory.m_pMemory[i]);
          v11 = _CommandLine();
          if ( (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v11 + 40))(a1: v11, a2: g_VMPIParams[9].m_pName) != 0 )
          {
            _Msg(a1: "-mpi_TimingWait specified. Waiting for master to start...");
            while ( !g_bTimingWaitDone )
              VMPI_DispatchNextMessage(timeout: (CTCPPacket *)0x32);
            _Msg(a1: "\n ");
          }
          return 1;
        }
      }
      else
      {
        v5->Release(this: v5);
        v7(a1: "ITCPConnectSocket::Update() errored out");
      }
      if ( !CWaitTimer::ShouldKeepWaiting(this: &wait) )
        break;
      Sleep(dwMilliseconds: 0x64u);
    }
    v5->Release(this: v5);
    v13 = _CommandLine();
    if ( (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v13 + 40))(a1: v13, a2: g_VMPIParams[5].m_pName) != 0 )
    {
      v14 = nAttempts;
      _Msg(
        a1: "%s found. Retrying connection to %d.%d.%d.%d:%d (attempt %d).\n",
        g_VMPIParams[5].m_pName,
        masterAddr->ip[0],
        masterAddr->ip[1],
        masterAddr->ip[2],
        masterAddr->ip[3],
        masterAddr->port,
        nAttempts);
      v4 = iFirstPort;
      nAttempts = v14 + 1;
      continue;
    }
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100208A0
// Name: public: bool CMasterBroadcaster::Init(int,char __near * __near *,char const __near *,int,enum VMPIRunMode,bool)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CMasterBroadcaster::Init(
        CMasterBroadcaster *this,
        int argc,
        char **argv,
        char *pDependencyFilename,
        int nMaxWorkers,
        VMPIRunMode runMode,
        bool bPatchMode)
{
  VMPIRunMode v7; // eax
  char *Arg; // eax
  unsigned int v10; // eax
  int v11; // esi
  ITCPConnectSocket *Listener; // eax
  int j; // esi
  ITCPConnectSocket *v14; // eax
  bool v15; // zf
  ISocket *IPSocket; // eax
  int v17; // esi
  const char *v18; // esi
  long double v19; // st7
  int v20; // esi
  const char *v21; // eax
  bool v22; // sf
  unsigned int v23; // edi
  int m_Size; // edi
  int m_nAllocationCount; // eax
  char **m_pMemory; // ecx
  int v27; // eax
  char **v28; // edi
  unsigned int v29; // edi
  int v30; // eax
  int v31; // ecx
  char **v32; // eax
  int v33; // ecx
  char **v34; // eax
  int v35; // eax
  int v36; // ecx
  char **v37; // eax
  int v38; // ecx
  unsigned int v39; // edi
  int v40; // eax
  int v41; // ecx
  char **v42; // eax
  int v43; // ecx
  int v44; // eax
  int v45; // ecx
  char **v46; // eax
  int v47; // ecx
  unsigned int v48; // edi
  int v49; // eax
  int v50; // ecx
  char **v51; // eax
  int v52; // ecx
  HANDLE Thread; // eax
  CDependencyInfo::CDependencyFile **v54; // eax
  char *v56; // esi
  CDependencyInfo::CDependencyFile **v57; // eax
  unsigned __int16 m_iListenPort; // [esp-Ch] [ebp-23Ch]
  unsigned __int64 v59; // [esp-8h] [ebp-238h]
  unsigned __int64 v60; // [esp-8h] [ebp-238h]
  CDependencyInfo dependencyInfo; // [esp+Ch] [ebp-224h] BYREF
  CCycleCount cnt; // [esp+228h] [ebp-8h]
  char *pDependencyFilenamea; // [esp+240h] [ebp+10h]
  CDependencyInfo::CDependencyFile *pDependencyFilenameb; // [esp+240h] [ebp+10h]
  float id; // [esp+244h] [ebp+14h]
  int i; // [esp+244h] [ebp+14h]
  char *ia; // [esp+244h] [ebp+14h]
  int ib; // [esp+244h] [ebp+14h]
  char *ic; // [esp+244h] [ebp+14h]

  v7 = runMode;
  this->m_RunMode = runMode;
  this->m_nMaxWorkers = nMaxWorkers;
  memset(&dependencyInfo.m_Files, 0, sizeof(dependencyInfo.m_Files));
  if ( v7 == VMPI_RUN_NETWORKED && !g_bVMPISDKMode )
    SetupDependencyInfo(pInfo: &dependencyInfo, pDependencyFilename, bPatchMode);
  this->m_pListenSocket = nullptr;
  this->m_pDownloaderListenSocket = nullptr;
  Arg = VMPI_FindArg(argc, argv, pName: g_VMPIParams[3].m_pName, pDefault: setName);
  if ( Arg != nullptr )
  {
    v10 = atoi(nptr: Arg);
    this->m_iListenPort = v10;
    m_iListenPort = this->m_iListenPort;
    this->m_iDownloaderListenPort = v10 + 1;
    this->m_pListenSocket = ThreadedTCP_CreateListener(
                              pHandlerCreator: &this->m_ConnectionCreator,
                              port: m_iListenPort,
                              nQueueLength: 5);
    if ( !g_bVMPISDKMode )
      this->m_pDownloaderListenSocket = ThreadedTCP_CreateListener(
                                          pHandlerCreator: &this->m_ConnectionCreator,
                                          port: this->m_iDownloaderListenPort,
                                          nQueueLength: 5);
  }
  else
  {
    cnt.m_Int64 = __rdtsc();
    HIDWORD(v59) = HIDWORD(_g_ClockSpeed);
    LODWORD(v59) = _g_ClockSpeed;
    srand(seed: 1000000 * cnt.m_Int64 / v59);
    v11 = 23311;
    while ( 1 )
    {
      this->m_iListenPort = v11;
      Listener = ThreadedTCP_CreateListener(pHandlerCreator: &this->m_ConnectionCreator, port: v11, nQueueLength: 5);
      this->m_pListenSocket = Listener;
      if ( Listener != nullptr )
        break;
      if ( ++v11 > 23330 )
        goto LABEL_16;
    }
    if ( !g_bVMPISDKMode )
    {
      for ( j = this->m_iListenPort + 1; j <= 23330; ++j )
      {
        this->m_iDownloaderListenPort = j;
        if ( j != this->m_iListenPort )
        {
          v14 = ThreadedTCP_CreateListener(pHandlerCreator: &this->m_ConnectionCreator, port: j, nQueueLength: 5);
          this->m_pDownloaderListenSocket = v14;
          if ( v14 != nullptr )
            break;
        }
      }
    }
  }
LABEL_16:
  if ( this->m_pListenSocket == nullptr || !g_bVMPISDKMode && this->m_pDownloaderListenSocket == nullptr )
    _Error(a1: "Can't bind a listen socket in port range [%d, %d].", 21140, 21145);
  v15 = this->m_RunMode == VMPI_RUN_NETWORKED;
  this->m_bPatching = false;
  if ( v15 && !g_bVMPISDKMode )
  {
    IPSocket = CreateIPSocket();
    this->m_pSocket = IPSocket;
    if ( !IPSocket->BindToAny(this: IPSocket, a2: 0) )
      _Error(a1: "MPI_Init_Master: can't bind a socket");
    if ( bPatchMode )
    {
      v17 = 0;
      this->m_bPatching = true;
      if ( argc <= 0 )
      {
LABEL_28:
        v18 = nullptr;
      }
      else
      {
        while ( _V_stricmp(s1: argv[v17], s2: "-mpi_PatchVersion") != 0 )
        {
          if ( ++v17 >= argc )
            goto LABEL_28;
        }
        if ( v17 + 1 >= argc )
          v18 = "0";
        else
          v18 = argv[v17 + 1];
      }
      v19 = atof(nptr: v18);
      if ( v19 <= 0.0 || (id = v19) >= 32767.0 )
        _Error(a1: "-mpi_PatchVersion <val> -  val must be between 1.0 and 32767.0");
      V_strncpy(pDest: this->m_BroadcastInfo.m_PatchVersion, pSrc: v18, maxLen: 32);
    }
    else
    {
      this->m_BroadcastInfo.m_PatchVersion[0] = 0;
    }
    Sleep(dwMilliseconds: 1u);
    cnt.m_Int64 = __rdtsc();
    HIDWORD(v60) = HIDWORD(_g_ClockSpeed);
    LODWORD(v60) = _g_ClockSpeed;
    this->m_BroadcastInfo.m_JobID[0] = 1000000 * cnt.m_Int64 / v60;
    Sleep(dwMilliseconds: 1u);
    cnt.m_Int64 = __rdtsc();
    HIDWORD(v60) = HIDWORD(_g_ClockSpeed);
    LODWORD(v60) = _g_ClockSpeed;
    this->m_BroadcastInfo.m_JobID[1] = 1000000 * cnt.m_Int64 / v60;
    Sleep(dwMilliseconds: 1u);
    cnt.m_Int64 = __rdtsc();
    HIDWORD(v60) = HIDWORD(_g_ClockSpeed);
    LODWORD(v60) = _g_ClockSpeed;
    this->m_BroadcastInfo.m_JobID[2] = 1000000 * cnt.m_Int64 / v60;
    Sleep(dwMilliseconds: 1u);
    cnt.m_Int64 = __rdtsc();
    HIDWORD(v60) = HIDWORD(_g_ClockSpeed);
    LODWORD(v60) = _g_ClockSpeed;
    v20 = 0;
    this->m_BroadcastInfo.m_JobID[3] = 1000000 * cnt.m_Int64 / v60;
    if ( argc <= 0 )
      goto LABEL_40;
    while ( _V_stricmp(s1: argv[v20], s2: "-mpi_pw") != 0 )
    {
      if ( ++v20 >= argc )
        goto LABEL_40;
    }
    if ( v20 + 1 >= argc )
    {
      v21 = setName;
      goto LABEL_41;
    }
    v56 = argv[v20 + 1];
    if ( v56 != nullptr )
      v21 = v56;
    else
LABEL_40:
      v21 = setName;
LABEL_41:
    V_strncpy(pDest: this->m_BroadcastInfo.m_Password, pSrc: v21, maxLen: 256);
    V_strncpy(pDest: this->m_BroadcastInfo.m_WorkerExeFilename, pSrc: dependencyInfo.m_OriginalExeFilename, maxLen: 260);
    v22 = this->m_BroadcastInfo.m_Args.m_Memory.m_nGrowSize < 0;
    this->m_BroadcastInfo.m_Args.m_Size = 0;
    if ( !v22 )
    {
      if ( this->m_BroadcastInfo.m_Args.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_BroadcastInfo.m_Args.m_Memory.m_pMemory);
        this->m_BroadcastInfo.m_Args.m_Memory.m_pMemory = nullptr;
      }
      this->m_BroadcastInfo.m_Args.m_Memory.m_nAllocationCount = 0;
    }
    this->m_BroadcastInfo.m_Args.m_pElements = this->m_BroadcastInfo.m_Args.m_Memory.m_pMemory;
    for ( i = 1; i < argc; ++i )
    {
      pDependencyFilenamea = argv[i];
      v23 = _V_strlen(str: pDependencyFilenamea) + 1;
      HIDWORD(cnt.m_Int64) = operator new(nSize: v23);
      V_strncpy(pDest: (char *)HIDWORD(cnt.m_Int64), pSrc: pDependencyFilenamea, maxLen: v23);
      m_Size = this->m_BroadcastInfo.m_Args.m_Size;
      m_nAllocationCount = this->m_BroadcastInfo.m_Args.m_Memory.m_nAllocationCount;
      if ( m_Size + 1 > m_nAllocationCount )
        CUtlMemory<int,int>::Grow(
          this: (CUtlMemory<CTCPPacket *,int> *)&this->m_BroadcastInfo.m_Args,
          num: m_Size - m_nAllocationCount + 1);
      ++this->m_BroadcastInfo.m_Args.m_Size;
      m_pMemory = this->m_BroadcastInfo.m_Args.m_Memory.m_pMemory;
      v27 = this->m_BroadcastInfo.m_Args.m_Size - m_Size - 1;
      this->m_BroadcastInfo.m_Args.m_pElements = m_pMemory;
      if ( v27 > 0 )
        _V_memmove(
          dest: (unsigned __int8 *)&m_pMemory[m_Size + 1],
          src: (unsigned __int8 *)&m_pMemory[m_Size],
          count: 4 * v27);
      v28 = &this->m_BroadcastInfo.m_Args.m_Memory.m_pMemory[m_Size];
      if ( v28 != nullptr )
        *v28 = (char *)HIDWORD(cnt.m_Int64);
    }
    v29 = _V_strlen(str: this->m_BroadcastInfo.m_WorkerExeFilename) + 1;
    ia = (char *)operator new(nSize: v29);
    V_strncpy(pDest: ia, pSrc: this->m_BroadcastInfo.m_WorkerExeFilename, maxLen: v29);
    v30 = this->m_BroadcastInfo.m_Args.m_Size;
    v31 = this->m_BroadcastInfo.m_Args.m_Memory.m_nAllocationCount;
    if ( v30 + 1 > v31 )
      CUtlMemory<int,int>::Grow(this: (CUtlMemory<CTCPPacket *,int> *)&this->m_BroadcastInfo.m_Args, num: v30 - v31 + 1);
    ++this->m_BroadcastInfo.m_Args.m_Size;
    v32 = this->m_BroadcastInfo.m_Args.m_Memory.m_pMemory;
    v33 = this->m_BroadcastInfo.m_Args.m_Size - 1;
    this->m_BroadcastInfo.m_Args.m_pElements = v32;
    if ( v33 > 0 )
      _V_memmove(dest: (unsigned __int8 *)v32 + 4, src: (unsigned __int8 *)v32, count: 4 * v33);
    v34 = this->m_BroadcastInfo.m_Args.m_Memory.m_pMemory;
    if ( v34 != nullptr )
      *v34 = ia;
    for ( ib = 0; ib < dependencyInfo.m_Files.m_Size; ++ib )
    {
      v35 = this->m_BroadcastInfo.m_Args.m_Size;
      v36 = this->m_BroadcastInfo.m_Args.m_Memory.m_nAllocationCount;
      if ( v35 + 1 > v36 )
        CUtlMemory<int,int>::Grow(
          this: (CUtlMemory<CTCPPacket *,int> *)&this->m_BroadcastInfo.m_Args,
          num: v35 - v36 + 1);
      ++this->m_BroadcastInfo.m_Args.m_Size;
      v37 = this->m_BroadcastInfo.m_Args.m_Memory.m_pMemory;
      v38 = this->m_BroadcastInfo.m_Args.m_Size - 2;
      this->m_BroadcastInfo.m_Args.m_pElements = v37;
      if ( v38 > 0 )
        _V_memmove(dest: (unsigned __int8 *)v37 + 8, src: (unsigned __int8 *)v37 + 4, count: 4 * v38);
      if ( this->m_BroadcastInfo.m_Args.m_Memory.m_pMemory != (char **)-4 )
        *((_DWORD *)this->m_BroadcastInfo.m_Args.m_Memory.m_pMemory + 1) = "-mpi_file";
      pDependencyFilenameb = dependencyInfo.m_Files.m_Memory.m_pMemory[ib];
      v39 = _V_strlen(str: pDependencyFilenameb->m_Name) + 1;
      HIDWORD(cnt.m_Int64) = operator new(nSize: v39);
      V_strncpy(pDest: (char *)HIDWORD(cnt.m_Int64), pSrc: pDependencyFilenameb->m_Name, maxLen: v39);
      v40 = this->m_BroadcastInfo.m_Args.m_Size;
      v41 = this->m_BroadcastInfo.m_Args.m_Memory.m_nAllocationCount;
      if ( v40 + 1 > v41 )
        CUtlMemory<int,int>::Grow(
          this: (CUtlMemory<CTCPPacket *,int> *)&this->m_BroadcastInfo.m_Args,
          num: v40 - v41 + 1);
      ++this->m_BroadcastInfo.m_Args.m_Size;
      v42 = this->m_BroadcastInfo.m_Args.m_Memory.m_pMemory;
      v43 = this->m_BroadcastInfo.m_Args.m_Size - 3;
      this->m_BroadcastInfo.m_Args.m_pElements = v42;
      if ( v43 > 0 )
        _V_memmove(dest: (unsigned __int8 *)v42 + 12, src: (unsigned __int8 *)v42 + 8, count: 4 * v43);
      if ( this->m_BroadcastInfo.m_Args.m_Memory.m_pMemory != (char **)-8 )
        *((_DWORD *)this->m_BroadcastInfo.m_Args.m_Memory.m_pMemory + 2) = HIDWORD(cnt.m_Int64);
    }
    v44 = this->m_BroadcastInfo.m_Args.m_Size;
    v45 = this->m_BroadcastInfo.m_Args.m_Memory.m_nAllocationCount;
    if ( v44 + 1 > v45 )
      CUtlMemory<int,int>::Grow(this: (CUtlMemory<CTCPPacket *,int> *)&this->m_BroadcastInfo.m_Args, num: v44 - v45 + 1);
    ++this->m_BroadcastInfo.m_Args.m_Size;
    v46 = this->m_BroadcastInfo.m_Args.m_Memory.m_pMemory;
    v47 = this->m_BroadcastInfo.m_Args.m_Size - 2;
    this->m_BroadcastInfo.m_Args.m_pElements = v46;
    if ( v47 > 0 )
      _V_memmove(dest: (unsigned __int8 *)v46 + 8, src: (unsigned __int8 *)v46 + 4, count: 4 * v47);
    if ( this->m_BroadcastInfo.m_Args.m_Memory.m_pMemory != (char **)-4 )
      *((_DWORD *)this->m_BroadcastInfo.m_Args.m_Memory.m_pMemory + 1) = "-mpi_filebase";
    v48 = _V_strlen(str: dependencyInfo.m_DependencyFilesDir) + 1;
    ic = (char *)operator new(nSize: v48);
    V_strncpy(pDest: ic, pSrc: dependencyInfo.m_DependencyFilesDir, maxLen: v48);
    v49 = this->m_BroadcastInfo.m_Args.m_Size;
    v50 = this->m_BroadcastInfo.m_Args.m_Memory.m_nAllocationCount;
    if ( v49 + 1 > v50 )
      CUtlMemory<int,int>::Grow(this: (CUtlMemory<CTCPPacket *,int> *)&this->m_BroadcastInfo.m_Args, num: v49 - v50 + 1);
    ++this->m_BroadcastInfo.m_Args.m_Size;
    v51 = this->m_BroadcastInfo.m_Args.m_Memory.m_pMemory;
    v52 = this->m_BroadcastInfo.m_Args.m_Size - 3;
    this->m_BroadcastInfo.m_Args.m_pElements = v51;
    if ( v52 > 0 )
      _V_memmove(dest: (unsigned __int8 *)v51 + 12, src: (unsigned __int8 *)v51 + 8, count: 4 * v52);
    if ( this->m_BroadcastInfo.m_Args.m_Memory.m_pMemory != (char **)-8 )
      *((_DWORD *)this->m_BroadcastInfo.m_Args.m_Memory.m_pMemory + 2) = ic;
    if ( bPatchMode )
      CMasterBroadcaster::GetPatchWorkerList(this, argc, argv);
  }
  this->m_ConnectionCreator.CreateNewHandler(this: &this->m_ConnectionCreator);
  this->m_LastSendTime = _Plat_MSTime() - 1200;
  CEvent::Init(this: &this->m_hShutdownEvent, bManualReset: false, bInitialState: false);
  CEvent::Init(this: &this->m_hShutdownReply, bManualReset: false, bInitialState: false);
  runMode = VMPI_RUN_NETWORKED;
  Thread = CreateThread(
             lpThreadAttributes: nullptr,
             dwStackSize: 0,
             lpStartAddress: (LPTHREAD_START_ROUTINE)CMasterBroadcaster::StaticThreadFn,
             lpParameter: this,
             dwCreationFlags: 0,
             lpThreadId: (LPDWORD)&runMode);
  this->m_hThread = Thread;
  if ( Thread != nullptr )
  {
    SetThreadPriority(hThread: Thread, nPriority: 2);
    v54 = dependencyInfo.m_Files.m_Memory.m_pMemory;
    dependencyInfo.m_Files.m_Size = 0;
    if ( dependencyInfo.m_Files.m_Memory.m_nGrowSize >= 0 )
    {
      if ( dependencyInfo.m_Files.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: dependencyInfo.m_Files.m_Memory.m_pMemory);
        v54 = nullptr;
        dependencyInfo.m_Files.m_Memory.m_pMemory = nullptr;
      }
      dependencyInfo.m_Files.m_Memory.m_nAllocationCount = 0;
    }
    dependencyInfo.m_Files.m_pElements = v54;
    if ( dependencyInfo.m_Files.m_Memory.m_nGrowSize >= 0 && v54 != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v54);
    return 1;
  }
  else
  {
    v57 = dependencyInfo.m_Files.m_Memory.m_pMemory;
    dependencyInfo.m_Files.m_Size = 0;
    if ( dependencyInfo.m_Files.m_Memory.m_nGrowSize >= 0 )
    {
      if ( dependencyInfo.m_Files.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: dependencyInfo.m_Files.m_Memory.m_pMemory);
        v57 = nullptr;
        dependencyInfo.m_Files.m_Memory.m_pMemory = nullptr;
      }
      dependencyInfo.m_Files.m_Memory.m_nAllocationCount = 0;
    }
    dependencyInfo.m_Files.m_pElements = v57;
    if ( dependencyInfo.m_Files.m_Memory.m_nGrowSize >= 0 && v57 != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v57);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100211C0
// Name: bool InitMaster(int,char __near * __near *,char const __near *,enum VMPIRunMode,bool)
// Source: json
//------------------------------------------------------------------------------
char __cdecl InitMaster(int argc, char **argv, char *pDependencyFilename, VMPIRunMode runMode, bool bPatchMode)
{
  char *Arg; // eax
  signed int v6; // ebx
  bool v7; // al
  char result; // al
  char v9; // bl

  Arg = VMPI_FindArg(argc, argv, pName: g_VMPIParams[10].m_pName, pDefault: setName);
  if ( Arg != nullptr )
  {
    v6 = atoi(nptr: Arg);
    _Warning(a1: "%s: waiting for %d processes to join.\n", g_VMPIParams[10].m_pName, v6);
    if ( v6 >= 2 )
    {
      if ( v6 > 512 )
        v6 = 512;
    }
    else
    {
      v6 = 2;
    }
  }
  else
  {
    v6 = 32;
  }
  g_bMPIMaster = true;
  g_nMaxWorkerCount = v6;
  if ( argc <= 0 )
    _Error(a1: "MPI_Init_Master: argc <= 0!");
  ParseOptions(argc, argv);
  VMPI_SendExeName();
  if ( g_bVMPISDKModeSet )
    v7 = g_bVMPISDKMode;
  else
    v7 = !VMPI_CheckForNonSDKExecutables();
  if ( v7 )
    VMPI_SendCommandLine(argc, argv);
  result = CMasterBroadcaster::Init(
             this: &g_MasterBroadcaster,
             argc,
             argv,
             pDependencyFilename,
             nMaxWorkers: v6,
             runMode,
             bPatchMode);
  if ( result != 0 )
  {
    if ( runMode == VMPI_RUN_LOCAL )
    {
      v9 = SpawnLocalWorker(argc, argv, iListenPort: g_MasterBroadcaster.m_iListenPort, bShowConsoleWindow: false);
      VMPI_HandleTimingWait_Master();
      return v9;
    }
    else
    {
      if ( VMPI_FindArg(argc, argv, pName: g_VMPIParams[11].m_pName, pDefault: setName) != nullptr )
      {
        _Msg(a1: "%s found. Spawning a local worker automatically.\n", g_VMPIParams[11].m_pName);
        SpawnLocalWorker(argc: 1, argv, iListenPort: g_MasterBroadcaster.m_iListenPort, bShowConsoleWindow: true);
      }
      VMPI_HandleTimingWait_Master();
      return 1;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10021310
// Name: bool VMPI_Init(int __near &,char __near * __near * __near &,char const __near *,void (*)(int,char const __near *),enum VMPIRunMode,bool)
// Source: json
//------------------------------------------------------------------------------
char __cdecl VMPI_Init(
        int *argc,
        char ***argv,
        char *pDependencyFilename,
        void (__cdecl *handler)(int, const char *),
        VMPIRunMode runMode,
        IThreadedTCPSocket *bConnectingAsService)
{
  HMODULE LibraryA; // eax
  char *Arg; // ebx
  CIPAddr addr; // [esp+0h] [ebp-8h] BYREF

  if ( VMPI_IsLogFileEnabled() )
    _LoggingSystem_RegisterLoggingListener(a1: &g_VMPILoggingListener);
  if ( handler != nullptr )
    CUtlLinkedList<void (__cdecl *)(int,char const *),int,0,int,CUtlMemory<UtlLinkedListElem_t<void (__cdecl *)(int,char const *),int>,int>>::AddToTail(
      this: &g_DisconnectHandlers,
      src: &handler);
  VMPI_SetupAutoRestartParameters(argc: *argc, argv: *argv);
  VMPI_CheckSDKMode(argc: *argc, argv: *argv);
  g_bUseMPI = true;
  g_VMPIRunMode = runMode;
  CEvent::Init(this: &g_VMPIMessagesEvent, bManualReset: false, bInitialState: false);
  CEvent::Init(this: &g_ErrorSocketsEvent, bManualReset: false, bInitialState: false);
  LibraryA = LoadLibraryA(lpLibFileName: "kernel32.dll");
  g_hKernel32DLL = LibraryA;
  if ( LibraryA != nullptr )
    g_pConsoleWndFn = (HWND__ *(__cdecl *)())GetProcAddress(hModule: LibraryA, lpProcName: "GetConsoleWindow");
  Arg = VMPI_FindArg(argc: *argc, argv: *argv, pName: g_VMPIParams[2].m_pName, pDefault: nullptr);
  if ( Arg != nullptr )
  {
    CIPAddr::CIPAddr(this: &addr);
    addr.port = 23311;
    if ( !ConvertStringToIPAddr(pStr: Arg, pOut: &addr) )
      _Error(a1: "Unable to parse or resolve master IP (%s).\n", Arg);
    return MPI_Init_Worker(argc, argv, masterAddr: &addr, bConnectingAsService);
  }
  else if ( pDependencyFilename != nullptr )
  {
    return InitMaster(argc: *argc, argv: *argv, pDependencyFilename, runMode, bPatchMode: false);
  }
  else
  {
    _Error(a1: "VMPI started as master, but no dependency filename specified.\n");
    return 0;
  }
}

// ============================================================
// Overlay from texturecompile_dll (Missing functions)
// ============================================================
namespace texturecompile_dll {

//------------------------------------------------------------------------------
// Address: 0x10003D30
// Name: public: void CUtlMemory<int,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<int,int>::Grow(CUtlMemory<CTCPPacket *,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  CTCPPacket **m_pMemory; // edx
  unsigned int v7; // [esp-4h] [ebp-Ch]

  m_nGrowSize = this->m_nGrowSize;
  if ( m_nGrowSize >= 0 )
  {
    m_nAllocationCount = this->m_nAllocationCount;
    v5 = m_nAllocationCount + num;
    if ( m_nGrowSize != 0 )
    {
      m_nAllocationCount = m_nGrowSize * ((v5 - 1) / m_nGrowSize + 1);
    }
    else
    {
      if ( m_nAllocationCount == 0 )
        m_nAllocationCount = 8;
      if ( m_nAllocationCount >= v5 )
        goto LABEL_13;
      do
        m_nAllocationCount *= 2;
      while ( m_nAllocationCount < v5 );
    }
    if ( m_nAllocationCount < v5 )
    {
      if ( m_nAllocationCount != 0 || v5 > -1 )
      {
        do
          m_nAllocationCount = (v5 + m_nAllocationCount) / 2;
        while ( m_nAllocationCount < v5 );
      }
      else
      {
        m_nAllocationCount = -1;
      }
    }
LABEL_13:
    m_pMemory = this->m_pMemory;
    this->m_nAllocationCount = m_nAllocationCount;
    v7 = 4 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (CTCPPacket **)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (CTCPPacket **)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10006620
// Name: public: struct TSLNodeBase_t __near * CTSListBase::Push(struct TSLNodeBase_t __near *)
// Source: json
//------------------------------------------------------------------------------
TSLNodeBase_t *__thiscall CTSListBase::Push(CTSListBase *this, TSLNodeBase_t *pNode)
{
  TSLNodeBase_t *Next; // edi
  TSLNodeBase_t *v5; // [esp-8h] [ebp-14h]
  int DepthAndSequence; // [esp-4h] [ebp-10h]
  int v7; // [esp-4h] [ebp-10h]

  Next = this->m_Head.value.Next;
  DepthAndSequence = this->m_Head.value32.DepthAndSequence;
  pNode->Next = this->m_Head.value.Next;
  if ( (unsigned __int8)_ThreadInterlockedAssignIf64(
                          a1: this,
                          a2: pNode,
                          a3: DepthAndSequence + 65537,
                          a4: Next,
                          a5: DepthAndSequence) == 0 )
  {
    do
    {
      _mm_pause();
      Next = this->m_Head.value.Next;
      v7 = this->m_Head.value32.DepthAndSequence;
      v5 = this->m_Head.value.Next;
      pNode->Next = this->m_Head.value.Next;
    }
    while ( (unsigned __int8)_ThreadInterlockedAssignIf64(a1: this, a2: pNode, a3: v7 + 65537, a4: v5, a5: v7) == 0 );
  }
  return Next;
}

//------------------------------------------------------------------------------
// Address: 0x10006680
// Name: public: struct TSLNodeBase_t __near * CTSListBase::Pop(void)
// Source: json
//------------------------------------------------------------------------------
TSLNodeBase_t *__thiscall CTSListBase::Pop(CTSListBase *this)
{
  TSLNodeBase_t *Next; // esi
  int DepthAndSequence; // eax

  Next = this->m_Head.value.Next;
  DepthAndSequence = this->m_Head.value32.DepthAndSequence;
  if ( this->m_Head.value.Next == nullptr )
    return nullptr;
  while ( (unsigned __int8)_ThreadInterlockedAssignIf64(
                             a1: this,
                             a2: Next->Next,
                             a3: DepthAndSequence - 1,
                             a4: Next,
                             a5: DepthAndSequence) == 0 )
  {
    _mm_pause();
    Next = this->m_Head.value.Next;
    DepthAndSequence = this->m_Head.value32.DepthAndSequence;
    if ( this->m_Head.value.Next == nullptr )
      return nullptr;
  }
  return Next;
}

//------------------------------------------------------------------------------
// Address: 0x100066C0
// Name: public: struct TSLNodeBase_t __near * CTSListBase::Detach(void)
// Source: json
//------------------------------------------------------------------------------
TSLNodeBase_t *__thiscall CTSListBase::Detach(CTSListBase *this)
{
  TSLNodeBase_t *Next; // esi

  while ( 1 )
  {
    _mm_pause();
    Next = this->m_Head.value.Next;
    if ( this->m_Head.value.Next == nullptr )
      break;
    if ( (unsigned __int8)_ThreadInterlockedAssignIf64(
                            a1: this,
                            a2: 0,
                            a3: this->m_Head.value32.DepthAndSequence & 0xFFFF0000,
                            a4: Next,
                            a5: this->m_Head.value32.DepthAndSequence) != 0 )
      return Next;
  }
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10006700
// Name: public: CVMPIPacketIDReg::CVMPIPacketIDReg(int,int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CVMPIPacketIDReg *__thiscall CVMPIPacketIDReg::CVMPIPacketIDReg(
        CVMPIPacketIDReg *this,
        int nPacketID,
        int nSubPacketID,
        const char *pName)
{
  CVMPIPacketIDReg *v5; // edx

  this->m_nPacketID = nPacketID;
  this->m_nSubPacketID = nSubPacketID;
  v5 = g_pVMPIPacketIDRegHead;
  this->m_pName = pName;
  this->m_pNext = v5;
  g_pVMPIPacketIDRegHead = this;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10006730
// Name: public: static void CVMPIPacketIDReg::Lookup(int,int,char __near *,int,char __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CVMPIPacketIDReg::Lookup(
        int nPacketID,
        int nSubPacketID,
        char *pPacketIDString,
        int nPacketIDStringSize,
        char *pSubPacketIDString,
        int nSubPacketIDStringSize)
{
  CVMPIPacketIDReg *v6; // eax
  CVMPIPacketIDReg *v7; // eax

  v6 = g_pVMPIPacketIDRegHead;
  if ( g_pVMPIPacketIDRegHead != nullptr )
  {
    while ( v6->m_nPacketID != nPacketID || v6->m_nSubPacketID != -1 )
    {
      v6 = v6->m_pNext;
      if ( v6 == nullptr )
        goto LABEL_5;
    }
    V_strncpy(pDest: pPacketIDString, pSrc: (char *)v6->m_pName, maxLen: nPacketIDStringSize);
  }
  else
  {
LABEL_5:
    V_snprintf(pDest: pPacketIDString, maxLen: nPacketIDStringSize, pFormat: "(%d)", nPacketID);
  }
  v7 = g_pVMPIPacketIDRegHead;
  if ( g_pVMPIPacketIDRegHead != nullptr )
  {
    while ( v7->m_nPacketID != nPacketID || v7->m_nSubPacketID != nSubPacketID )
    {
      v7 = v7->m_pNext;
      if ( v7 == nullptr )
        goto LABEL_10;
    }
    V_strncpy(pDest: pSubPacketIDString, pSrc: (char *)v7->m_pName, maxLen: nSubPacketIDStringSize);
  }
  else
  {
LABEL_10:
    V_snprintf(pDest: pSubPacketIDString, maxLen: nSubPacketIDStringSize, pFormat: "(%d)", nSubPacketID);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100067D0
// Name: void VMPI_SuperSpew(char const __near *,...)
// Source: json
//------------------------------------------------------------------------------
void VMPI_SuperSpew(const char *pMsg, ...)
{
  char str[2048]; // [esp+0h] [ebp-800h] BYREF
  va_list params; // [esp+80Ch] [ebp+Ch] BYREF

  va_start(params, pMsg);
  if ( g_bSuperSpewEnabled )
  {
    V_vsnprintf(pDest: str, maxLen: 0x800u, pFormat: pMsg, params);
    _Msg(a1: "%s", str);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10006820
// Name: public: virtual void CVMPILoggingListener::Log(struct LoggingContext_t const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVMPILoggingListener::Log(
        CVMPILoggingListener *this,
        const LoggingContext_t *pContext,
        const char *pMessage)
{
  VMPI_WriteToLogFile(pMsg: "%s", pMessage);
}

//------------------------------------------------------------------------------
// Address: 0x10006840
// Name: char const __near * VMPI_FindArg(int,char __near * __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
char *__cdecl VMPI_FindArg(int argc, char **argv, const char *pName, const char *pDefault)
{
  int v4; // esi

  v4 = 0;
  if ( argc <= 0 )
    return nullptr;
  while ( _V_stricmp(s1: argv[v4], s2: pName) != 0 )
  {
    if ( ++v4 >= argc )
      return nullptr;
  }
  if ( v4 + 1 >= argc )
    return (char *)pDefault;
  else
    return argv[v4 + 1];
}

//------------------------------------------------------------------------------
// Address: 0x10006890
// Name: void SetupDependencyFilename(class CDependencyInfo __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SetupDependencyFilename(CDependencyInfo *pInfo, char *pPatchDirectory)
{
  HMODULE ModuleHandleA; // eax
  char *v3; // eax
  char baseExeFilename[512]; // [esp+0h] [ebp-200h] BYREF

  ModuleHandleA = GetModuleHandleA(lpModuleName: nullptr);
  if ( GetModuleFileNameA(hModule: ModuleHandleA, lpFilename: baseExeFilename, nSize: 0x200u) == 0 )
    _Error(a1: "GetModuleFileName failed.");
  if ( pPatchDirectory != nullptr )
  {
    V_strncpy(pDest: pInfo->m_DependencyFilesDir, pSrc: pPatchDirectory, maxLen: 260);
  }
  else
  {
    V_strncpy(pDest: pInfo->m_DependencyFilesDir, pSrc: baseExeFilename, maxLen: 260);
    V_StripLastDir(dirName: pInfo->m_DependencyFilesDir, maxlen: 0x104u);
  }
  v3 = (char *)V_UnqualifiedFileName(in: baseExeFilename);
  V_strncpy(pDest: pInfo->m_OriginalExeFilename, pSrc: v3, maxLen: 260);
}

//------------------------------------------------------------------------------
// Address: 0x10006930
// Name: public: void CMasterBroadcaster::Term(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMasterBroadcaster::Term(CMasterBroadcaster *this)
{
  ISocket *m_pSocket; // ecx
  ITCPConnectSocket *m_pDownloaderListenSocket; // ecx

  if ( this->m_hThread != nullptr )
  {
    CEvent::SetEvent(this: &this->m_hShutdownEvent);
    WaitForSingleObject(hHandle: this->m_hThread, dwMilliseconds: 0xFFFFFFFF);
    CloseHandle(hObject: this->m_hThread);
    this->m_hThread = nullptr;
  }
  m_pSocket = this->m_pSocket;
  if ( m_pSocket != nullptr )
  {
    m_pSocket->Release(this: m_pSocket);
    this->m_pSocket = nullptr;
  }
  if ( this->m_pListenSocket != nullptr )
  {
    this->m_pListenSocket->Release(this: this->m_pListenSocket);
    this->m_pListenSocket = nullptr;
  }
  m_pDownloaderListenSocket = this->m_pDownloaderListenSocket;
  if ( m_pDownloaderListenSocket != nullptr )
  {
    m_pDownloaderListenSocket->Release(this: m_pDownloaderListenSocket);
    this->m_pDownloaderListenSocket = nullptr;
  }
  this->m_iDownloaderListenPort = -1;
  this->m_iListenPort = -1;
}

//------------------------------------------------------------------------------
// Address: 0x100069C0
// Name: public: CDispatchReg::CDispatchReg(int,bool (*)(class MessageBuffer __near *,int,int))
// Source: json
//------------------------------------------------------------------------------
CDispatchReg *__thiscall CDispatchReg::CDispatchReg(
        CDispatchReg *this,
        int iPacketID,
        bool (__cdecl *fn)(MessageBuffer *, int, int))
{
  g_VMPIDispatch[iPacketID] = fn;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100069E0
// Name: bool VMPI_CheckForNonSDKExecutables(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl VMPI_CheckForNonSDKExecutables()
{
  HMODULE ModuleHandleA; // eax
  char baseExeFilename[512]; // [esp+0h] [ebp-200h] BYREF

  ModuleHandleA = GetModuleHandleA(lpModuleName: nullptr);
  if ( GetModuleFileNameA(hModule: ModuleHandleA, lpFilename: baseExeFilename, nSize: 0x200u) == 0 )
    _Error(a1: "VMPI_CheckSDKMode -> GetModuleFileName failed.");
  V_StripLastDir(dirName: baseExeFilename, maxlen: 0x200u);
  V_AppendSlash(pStr: baseExeFilename, strSize: 512);
  V_strncat(pDest: baseExeFilename, pSrc: "mysql_wrapper.dll", destBufferSize: 0x200u, max_chars_to_copy: -1);
  return access(path: baseExeFilename, amode: 0) == 0;
}

//------------------------------------------------------------------------------
// Address: 0x10006A70
// Name: enum VMPIRunMode VMPI_GetRunMode(void)
// Source: json
//------------------------------------------------------------------------------
VMPIRunMode __cdecl VMPI_GetRunMode()
{
  return g_VMPIRunMode;
}

//------------------------------------------------------------------------------
// Address: 0x10006A80
// Name: enum VMPIFileSystemMode VMPI_GetFileSystemMode(void)
// Source: json
//------------------------------------------------------------------------------
VMPIFileSystemMode __cdecl VMPI_GetFileSystemMode()
{
  return g_VMPIFileSystemMode;
}

//------------------------------------------------------------------------------
// Address: 0x10006A90
// Name: int VMPI_GetCurrentNumberOfConnections(void)
// Source: json
//------------------------------------------------------------------------------
int __cdecl VMPI_GetCurrentNumberOfConnections()
{
  return g_nConnections;
}

//------------------------------------------------------------------------------
// Address: 0x10006AA0
// Name: bool VMPI_FilterPacketsForServiceDownloader(class CVMPIConnection __near *,void const __near * const __near *,int const __near *,int)
// Source: json
//------------------------------------------------------------------------------
char __cdecl VMPI_FilterPacketsForServiceDownloader(
        CVMPIConnection *pConnection,
        const void *const *pChunks,
        const int *pChunkLengths,
        int nChunks)
{
  int v4; // eax
  int v5; // ecx
  unsigned __int8 *v7; // eax
  unsigned __int8 v8; // dl
  int v9; // eax
  char szPacketID[64]; // [esp+4h] [ebp-80h] BYREF
  char szSubPacketID[64]; // [esp+44h] [ebp-40h] BYREF

  if ( !pConnection->m_bIsAService )
    return 0;
  v4 = 0;
  if ( nChunks <= 0 )
    return 0;
  while ( 1 )
  {
    v5 = pChunkLengths[v4];
    if ( v5 >= 1 )
      break;
    if ( ++v4 >= nChunks )
      return 0;
  }
  v7 = (unsigned __int8 *)pChunks[v4];
  v8 = *v7;
  if ( *v7 == 27 || v8 == 10 || v8 == 0 )
    return 0;
  if ( g_bSuperSpewEnabled )
  {
    if ( v5 < 2 )
      v9 = -1;
    else
      v9 = v7[1];
    CVMPIPacketIDReg::Lookup(
      nPacketID: v8,
      nSubPacketID: v9,
      pPacketIDString: szPacketID,
      nPacketIDStringSize: 64,
      pSubPacketIDString: szSubPacketID,
      nSubPacketIDStringSize: 64);
    VMPI_SuperSpew(
      pMsg: "VMPI_FilterPacketsForServiceDownloader filtered packetID %s, subPacketID %s\n",
      szPacketID,
      szSubPacketID);
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10006B40
// Name: bool VMPI_IsProcValid(int)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl VMPI_IsProcValid(int procID)
{
  return procID >= 0 && procID < g_nConnections && g_Connections[procID] != nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10006B70
// Name: bool VMPI_IsProcConnected(int)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl VMPI_IsProcConnected(int procID)
{
  CVMPIConnection *v1; // eax

  return procID >= 0 && procID < g_nConnections && (v1 = g_Connections[procID]) != nullptr && v1->m_pSocket != nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10006BA0
// Name: void VMPI_Sleep(unsigned long)
// Source: json
//------------------------------------------------------------------------------
void __cdecl VMPI_Sleep(DWORD ms)
{
  Sleep(dwMilliseconds: ms);
}

//------------------------------------------------------------------------------
// Address: 0x10006BB0
// Name: bool VMPI_IsSDKMode(void)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl VMPI_IsSDKMode()
{
  if ( g_bVMPISDKModeSet )
    return g_bVMPISDKMode;
  else
    return !VMPI_CheckForNonSDKExecutables();
}

//------------------------------------------------------------------------------
// Address: 0x10006BD0
// Name: char const __near * VMPI_GetParamString(enum EVMPICmdLineParam)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl VMPI_GetParamString(EVMPICmdLineParam eParam)
{
  if ( (unsigned int)(eParam - 1) <= 0x19 )
    return g_VMPIParams[eParam].m_pName;
  _Warning(a1: "Invalid call: VMPI_GetParamString( %d )\n", eParam);
  return "unknown";
}

//------------------------------------------------------------------------------
// Address: 0x10006C00
// Name: bool VMPI_IsParamUsed(enum EVMPICmdLineParam)
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl VMPI_IsParamUsed(EVMPICmdLineParam eParam)
{
  int v1; // esi

  v1 = _CommandLine();
  if ( (unsigned int)(eParam - 1) <= 0x19 )
    return (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v1 + 40))(a1: v1, a2: g_VMPIParams[eParam].m_pName) != 0;
  _Warning(a1: "Invalid call: VMPI_GetParamString( %d )\n", eParam);
  return (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v1 + 40))(a1: v1, a2: "unknown") != 0;
}

//------------------------------------------------------------------------------
// Address: 0x10006C60
// Name: void ParseOptions(int,char __near * __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ParseOptions(int argc, char **argv)
{
  char *Arg; // eax
  char *v3; // eax
  char v4; // al

  if ( VMPI_FindArg(argc, argv, pName: g_VMPIParams[18].m_pName, pDefault: setName) != nullptr )
    ThreadedTCP_EnableTimeouts(bEnable: false);
  if ( VMPI_FindArg(argc, argv, pName: g_VMPIParams[19].m_pName, pDefault: setName) != nullptr )
  {
    _Msg(a1: "%s found.\n", g_VMPIParams[19].m_pName);
    g_bSetThreadPriorities = false;
    ThreadedTCP_SetTCPSocketThreadPriorities(bSetTCPSocketThreadPriorities: false);
  }
  if ( VMPI_FindArg(argc, argv, pName: g_VMPIParams[20].m_pName, pDefault: setName) != nullptr )
  {
    _Msg(a1: "%s found.\n", g_VMPIParams[20].m_pName);
    g_bGroupPackets = true;
  }
  Arg = VMPI_FindArg(argc, argv, pName: g_VMPIParams[12].m_pName, pDefault: "1");
  if ( Arg != nullptr )
    MULTICAST_TRANSMIT_RATE = atoi(nptr: Arg) << 10;
  v3 = VMPI_FindArg(argc, argv, pName: g_VMPIParams[13].m_pName, pDefault: "1");
  if ( v3 != nullptr )
  {
    v4 = *v3;
    if ( v4 == 49 )
    {
      g_iVMPIVerboseLevel = 1;
    }
    else if ( v4 == 50 )
    {
      g_iVMPIVerboseLevel = 2;
    }
  }
  if ( VMPI_FindArg(argc, argv, pName: g_VMPIParams[21].m_pName, pDefault: setName) != nullptr )
    g_bMPI_Stats = true;
  if ( VMPI_FindArg(argc, argv, pName: g_VMPIParams[22].m_pName, pDefault: setName) != nullptr )
    g_bMPI_StatsTextOutput = true;
}

//------------------------------------------------------------------------------
// Address: 0x10006DB0
// Name: void CountActiveConnections(int __near *,int __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CountActiveConnections(int *nRegularWorkers, int *nServiceDownloaders)
{
  int v2; // ebx
  int i; // ecx
  CVMPIConnection *v4; // eax

  *nServiceDownloaders = 0;
  *nRegularWorkers = 0;
  v2 = g_nConnections;
  for ( i = 0; i < v2; ++i )
  {
    if ( i >= 0 && i < g_nConnections )
    {
      v4 = g_Connections[i];
      if ( v4 != nullptr && v4->m_pSocket != nullptr )
      {
        if ( v4->m_bIsAService )
          ++*nServiceDownloaders;
        else
          ++*nRegularWorkers;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10006E10
// Name: void UpdateActiveConnectionsText(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl UpdateActiveConnectionsText()
{
  HWND v0; // esi
  char str[512]; // [esp+0h] [ebp-208h] BYREF
  int nDownloaders; // [esp+200h] [ebp-8h] BYREF
  int nRegularWorkers; // [esp+204h] [ebp-4h] BYREF

  if ( g_bMPIMaster && g_pConsoleWndFn != nullptr )
  {
    v0 = g_pConsoleWndFn();
    if ( v0 != nullptr )
    {
      CountActiveConnections(&nRegularWorkers, nServiceDownloaders: &nDownloaders);
      if ( g_bVMPISDKMode )
        V_snprintf(pDest: str, maxLen: 0x200u, pFormat: "VMPI (SDK) - Workers: %d", nRegularWorkers);
      else
        V_snprintf(
          pDest: str,
          maxLen: 0x200u,
          pFormat: "VMPI - Workers: %d, Downloaders: %d",
          nRegularWorkers,
          nDownloaders);
      SetWindowTextA(hWnd: v0, lpString: str);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10006EB0
// Name: bool SpawnLocalWorker(int,char __near * __near *,int,bool)
// Source: json
//------------------------------------------------------------------------------
char __cdecl SpawnLocalWorker(int argc, char **argv, int iListenPort, bool bShowConsoleWindow)
{
  int i; // ebx
  const char *m_pName; // edi
  int v7; // esi
  char CommandLine[4096]; // [esp+Ch] [ebp-1854h] BYREF
  char pnbuf[1024]; // [esp+100Ch] [ebp-854h] BYREF
  char pStr[512]; // [esp+140Ch] [ebp-454h] BYREF
  char pDest[512]; // [esp+160Ch] [ebp-254h] BYREF
  _STARTUPINFOA dst; // [esp+180Ch] [ebp-54h] BYREF
  _PROCESS_INFORMATION ProcessInformation; // [esp+1850h] [ebp-10h] BYREF

  CommandLine[0] = 0;
  for ( i = 0; i < 9999999; ++i )
  {
    if ( i == 1 )
    {
      V_snprintf(pDest, maxLen: 0x200u, pFormat: "-mpi_worker 127.0.0.1:%d ", iListenPort);
      V_strncat(pDest: CommandLine, pSrc: pDest, destBufferSize: 0x1000u, max_chars_to_copy: -1);
      V_strncat(pDest: CommandLine, pSrc: "-allowdebug ", destBufferSize: 0x1000u, max_chars_to_copy: -1);
      if ( g_bVMPISDKModeSet ? g_bVMPISDKMode : !VMPI_CheckForNonSDKExecutables() )
      {
        m_pName = g_VMPIParams[15].m_pName;
        v7 = 0;
        if ( argc <= 0 )
          goto LABEL_13;
        while ( _V_stricmp(s1: argv[v7], s2: m_pName) != 0 )
        {
          if ( ++v7 >= argc )
            goto LABEL_13;
        }
        if ( v7 + 1 < argc && argv[v7 + 1] == nullptr )
LABEL_13:
          V_strncat(pDest: CommandLine, pSrc: g_VMPIParams[15].m_pName, destBufferSize: 0x1000u, max_chars_to_copy: -1);
      }
    }
    if ( i >= argc )
      break;
    V_snprintf(pDest, maxLen: 0x200u, pFormat: "\"%s\" ", argv[i]);
    V_strncat(pDest: CommandLine, pSrc: pDest, destBufferSize: 0x1000u, max_chars_to_copy: -1);
  }
  if ( _getcwd(pnbuf, maxlen: 1024) != nullptr )
  {
    memset((unsigned __int8 *)&dst, value: 0, count: sizeof(dst));
    dst.cb = 68;
    memset(&ProcessInformation, 0, sizeof(ProcessInformation));
    if ( CreateProcessA(
           lpApplicationName: nullptr,
           lpCommandLine: CommandLine,
           lpProcessAttributes: nullptr,
           lpThreadAttributes: nullptr,
           bInheritHandles: true,
           dwCreationFlags: (bShowConsoleWindow ? 16 : 0x8000000) | 0x40,
           lpEnvironment: nullptr,
           lpCurrentDirectory: pnbuf,
           lpStartupInfo: &dst,
           lpProcessInformation: &ProcessInformation) )
    {
      return 1;
    }
    else
    {
      IP_GetLastErrorString(pStr, maxLen: 1024);
      _Warning(a1: " - ERROR in CreateProcess (%s)!\n", pStr);
      return 0;
    }
  }
  else
  {
    _Warning(a1: "_getcwd() failed.\n");
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10007160
// Name: private: void CMasterBroadcaster::BuildBroadcastPacket(class bf_write __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMasterBroadcaster::BuildBroadcastPacket(CMasterBroadcaster *this, bf_write *buf)
{
  bf_write *v2; // esi
  bool v4; // zf
  const char *v5; // eax
  int i; // ebx

  v2 = buf;
  bf_write::WriteByte(this: buf, val: 5u);
  bf_write::WriteString(this: v2, pStr: this->m_BroadcastInfo.m_Password);
  if ( this->m_BroadcastInfo.m_PatchVersion[0] != 0 )
    bf_write::WriteByte(this: v2, val: 0x4Fu);
  else
    bf_write::WriteByte(this: v2, val: 0x47u);
  bf_write::WriteString(this: v2, pStr: this->m_BroadcastInfo.m_PatchVersion);
  bf_write::WriteLong(this: v2, val: this->m_iListenPort);
  bf_write::WriteLong(this: v2, val: this->m_BroadcastInfo.m_JobID[0]);
  bf_write::WriteLong(this: v2, val: this->m_BroadcastInfo.m_JobID[1]);
  bf_write::WriteLong(this: v2, val: this->m_BroadcastInfo.m_JobID[2]);
  bf_write::WriteLong(this: v2, val: this->m_BroadcastInfo.m_JobID[3]);
  bf_write::WriteWord(this: v2, val: this->m_BroadcastInfo.m_Args.m_Size + 2);
  bf_write::WriteString(this: v2, pStr: this->m_BroadcastInfo.m_WorkerExeFilename);
  bf_write::WriteString(this: v2, pStr: "-mpi_MasterName");
  buf = (bf_write *)16;
  v4 = !GetComputerNameA(lpBuffer: Buffer, nSize: (LPDWORD)&buf);
  v5 = Buffer;
  if ( v4 )
    v5 = "(error in GetComputerName)";
  bf_write::WriteString(this: v2, pStr: v5);
  for ( i = 1; i < this->m_BroadcastInfo.m_Args.m_Size; ++i )
    bf_write::WriteString(this: v2, pStr: this->m_BroadcastInfo.m_Args.m_Memory.m_pMemory[i]);
  bf_write::WriteByte(this: v2, val: 1u);
  bf_write::WriteShort(this: v2, val: this->m_iDownloaderListenPort);
}

//------------------------------------------------------------------------------
// Address: 0x10007280
// Name: bool IsValidSDKBinPath(class CUtlVector<char __near *,class CUtlMemory<char __near *,int>> __near &,int __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl IsValidSDKBinPath(CUtlVector<char *,CUtlMemory<char *,int> > *outStrings, int *pError)
{
  int m_Size; // eax
  int i; // edi
  int j; // edi
  char mapsrcFilename[260]; // [esp+8h] [ebp-54Ch] BYREF
  char blobPath[260]; // [esp+10Ch] [ebp-448h] BYREF
  char tempFilename[260]; // [esp+210h] [ebp-344h] BYREF
  char baseSteamPath[260]; // [esp+314h] [ebp-240h] BYREF
  char sourcesdkContentPath[260]; // [esp+418h] [ebp-13Ch] BYREF
  _stat64i32 results; // [esp+51Ch] [ebp-38h] BYREF
  __int64 curTime; // [esp+54Ch] [ebp-8h] BYREF

  *pError = 0;
  m_Size = outStrings->m_Size;
  if ( m_Size >= 9 )
  {
    if ( _V_stricmp(s1: outStrings->m_Memory.m_pMemory[m_Size - 2], s2: "bin") != 0 )
    {
      *pError = 1;
      return 0;
    }
    else if ( _V_stricmp(s1: outStrings->m_Memory.m_pMemory[outStrings->m_Size - 5], s2: "sourcesdk") != 0 )
    {
      *pError = 2;
      return 0;
    }
    else if ( _V_stricmp(s1: outStrings->m_Memory.m_pMemory[outStrings->m_Size - 7], s2: "steamapps") != 0 )
    {
      *pError = 3;
      return 0;
    }
    else
    {
      V_strncpy(pDest: baseSteamPath, pSrc: *outStrings->m_Memory.m_pMemory, maxLen: 260);
      for ( i = 1; i < outStrings->m_Size - 7; ++i )
      {
        V_AppendSlash(pStr: baseSteamPath, strSize: 260);
        V_strncat(
          pDest: baseSteamPath,
          pSrc: outStrings->m_Memory.m_pMemory[i],
          destBufferSize: 0x104u,
          max_chars_to_copy: -1);
      }
      V_ComposeFileName(path: baseSteamPath, filename: "ClientRegistry.blob", dest: blobPath, destSize: 260);
      if ( _stat64i32(name: blobPath, buf: &results) != 0 )
      {
        *pError = 4;
        return 0;
      }
      else
      {
        _time64(timeptr: &curTime);
        if ( (int)curTime - LODWORD(results.st_mtime) <= 864000 )
        {
          V_strncpy(pDest: sourcesdkContentPath, pSrc: *outStrings->m_Memory.m_pMemory, maxLen: 260);
          for ( j = 1; j < outStrings->m_Size - 5; ++j )
          {
            V_AppendSlash(pStr: sourcesdkContentPath, strSize: 260);
            V_strncat(
              pDest: sourcesdkContentPath,
              pSrc: outStrings->m_Memory.m_pMemory[j],
              destBufferSize: 0x104u,
              max_chars_to_copy: -1);
          }
          V_AppendSlash(pStr: sourcesdkContentPath, strSize: 260);
          V_strncat(
            pDest: sourcesdkContentPath,
            pSrc: "sourcesdk_content",
            destBufferSize: 0x104u,
            max_chars_to_copy: -1);
          V_snprintf(pDest: tempFilename, maxLen: 0x104u, pFormat: "cstrike%cmapsrc", 92);
          V_ComposeFileName(path: sourcesdkContentPath, filename: tempFilename, dest: mapsrcFilename, destSize: 260);
          if ( access(path: mapsrcFilename, amode: 0) != 0 )
          {
            *pError = 6;
            return 0;
          }
          else
          {
            return 1;
          }
        }
        else
        {
          *pError = 5;
          return 0;
        }
      }
    }
  }
  else
  {
    *pError = 0;
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10007500
// Name: void VerifyValidSDKMode(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl VerifyValidSDKMode()
{
  HMODULE ModuleHandleA; // eax
  char baseExeFilename[260]; // [esp+4h] [ebp-124h] BYREF
  CSplitString outStrings; // [esp+108h] [ebp-20h] BYREF
  int err; // [esp+120h] [ebp-8h] BYREF
  char strSlash[4]; // [esp+124h] [ebp-4h] BYREF

  ModuleHandleA = GetModuleHandleA(lpModuleName: nullptr);
  if ( GetModuleFileNameA(hModule: ModuleHandleA, lpFilename: baseExeFilename, nSize: 0x104u) == 0 )
    _Error(a1: "VerifyValidSDKMode: GetModuleFileName failed.");
  V_FixSlashes(pname: baseExeFilename, separator: 92);
  strcpy(strSlash, "\\");
  CSplitString::CSplitString(this: &outStrings, pString: baseExeFilename, pSeparator: strSlash);
  if ( IsValidSDKBinPath(&outStrings, pError: &err) == 0 )
  {
    if ( err == 5 )
    {
      _Error(a1: "VMPI running in SDK mode but Steam hasn't been run recently. Please run Steam and retry.");
      CSplitString::~CSplitString(this: &outStrings);
      return;
    }
    _Error(a1: "VMPI running in SDK mode but incorrect SDK install detected (error %d).", err);
  }
  CSplitString::~CSplitString(this: &outStrings);
}

//------------------------------------------------------------------------------
// Address: 0x100075B0
// Name: void VMPI_CheckSDKMode(int,char __near * __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl VMPI_CheckSDKMode(int argc, char **argv)
{
  bool v2; // al

  if ( g_bIsRunningVMPITransfer )
  {
    g_bVMPISDKMode = false;
    g_bVMPISDKModeSet = true;
    return;
  }
  v2 = VMPI_CheckForNonSDKExecutables();
  g_bVMPISDKMode = !v2;
  g_bVMPISDKModeSet = true;
  if ( v2 )
  {
    if ( VMPI_FindArg(argc, argv, pName: g_VMPIParams[15].m_pName, pDefault: setName) != nullptr )
    {
      g_bVMPISDKMode = true;
    }
    else if ( !g_bVMPISDKMode )
    {
      return;
    }
  }
  VerifyValidSDKMode();
  if ( g_bVMPISDKMode )
    _Msg(a1: "VMPI running in SDK mode.\n");
}

//------------------------------------------------------------------------------
// Address: 0x10007640
// Name: char const __near * VMPI_GetMachineName(int)
// Source: json
//------------------------------------------------------------------------------
char *__cdecl VMPI_GetMachineName(int iProc)
{
  bool v1; // sf
  bool v2; // zf
  char *result; // eax
  CVMPIConnection *v4; // eax
  unsigned int nSize; // [esp+0h] [ebp-4h] BYREF

  if ( g_bMPIMaster )
  {
    v1 = iProc < 0;
    if ( iProc == 0 )
    {
      nSize = 16;
      v2 = !GetComputerNameA(lpBuffer: Buffer, &nSize);
      result = Buffer;
      if ( v2 )
        return "(error in GetComputerName)";
      return result;
    }
  }
  else
  {
    v1 = iProc < 0;
  }
  if ( v1 )
    return "invalid index";
  if ( iProc >= g_nConnections )
    return "invalid index";
  v4 = g_Connections[iProc];
  if ( v4 == nullptr )
    return "invalid index";
  else
    return v4->m_MachineName.m_Memory.m_pMemory;
}

//------------------------------------------------------------------------------
// Address: 0x10007B60
// Name: public: void CVMPIConnection::HandleDisconnect(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVMPIConnection::HandleDisconnect(CVMPIConnection *this)
{
  int m_Head; // esi
  UtlLinkedListElem_t<void (__cdecl*)(int,char const *),int> *m_pMemory; // eax
  int v4; // esi
  char str[512]; // [esp+4h] [ebp-208h] BYREF
  CCriticalSectionLock csLock; // [esp+204h] [ebp-8h] BYREF

  if ( this->m_pSocket != nullptr )
  {
    CCriticalSectionLock::CCriticalSectionLock(this: &csLock, pCS: &g_ErrorSocketsCS);
    CCriticalSectionLock::Lock(this: &csLock);
    V_strncpy(pDest: str, pSrc: this->m_ErrorString.m_Memory.m_pMemory, maxLen: 512);
    CCriticalSectionLock::Unlock(this: &csLock);
    m_Head = g_DisconnectHandlers.m_Head;
    if ( g_DisconnectHandlers.m_Head != -1 )
    {
      m_pMemory = g_DisconnectHandlers.m_Memory.m_pMemory;
      do
      {
        v4 = m_Head;
        m_pMemory[v4].m_Element(a1: this->m_iConnection, a2: str);
        m_pMemory = g_DisconnectHandlers.m_Memory.m_pMemory;
        m_Head = g_DisconnectHandlers.m_Memory.m_pMemory[v4].m_Next;
      }
      while ( m_Head != -1 );
    }
    this->m_pSocket->Release(this: this->m_pSocket);
    this->m_pSocket = nullptr;
    CCriticalSectionLock::~CCriticalSectionLock(this: &csLock);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10007C10
// Name: bool VMPI_HandleAutoRestart(void)
// Source: json
//------------------------------------------------------------------------------
char __usercall VMPI_HandleAutoRestart@<al>(int a1@<ebp>)
{
  void *v1; // esp
  HANDLE CurrentProcess; // eax
  int v3; // esi
  DWORD PriorityClass; // edi
  char **m_pMemory; // eax
  char v7[8192]; // [esp-2458h] [ebp-2464h] BYREF
  char v8[512]; // [esp-458h] [ebp-464h] BYREF
  char v9[512]; // [esp-258h] [ebp-264h] BYREF
  _STARTUPINFOA v10; // [esp-58h] [ebp-64h] BYREF
  _PROCESS_INFORMATION v11; // [esp-10h] [ebp-1Ch] BYREF
  int v12; // [esp+0h] [ebp-Ch]
  void *v13; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v12 = a1;
  v13 = retaddr;
  v1 = alloca(9304);
  if ( g_OriginalCommandLineParameters.m_Size == 0 )
    return 1;
  _Msg(a1: "%s found. Auto-restarting.\n", g_VMPIParams[6].m_pName);
  CurrentProcess = GetCurrentProcess();
  v3 = 0;
  PriorityClass = GetPriorityClass(hProcess: CurrentProcess);
  for ( v7[0] = 0; v3 < g_OriginalCommandLineParameters.m_Size; ++v3 )
  {
    V_snprintf(pDest: v9, maxLen: 0x200u, pFormat: "\"%s\" ", g_OriginalCommandLineParameters.m_Memory.m_pMemory[v3]);
    V_strncat(pDest: v7, pSrc: v9, destBufferSize: 0x2000u, max_chars_to_copy: -1);
  }
  memset(dst: (unsigned __int8 *)&v10, value: 0, count: sizeof(v10));
  v10.cb = 68;
  v11 = 0;
  if ( CreateProcessA(
         lpApplicationName: nullptr,
         lpCommandLine: v7,
         lpProcessAttributes: nullptr,
         lpThreadAttributes: nullptr,
         bInheritHandles: true,
         dwCreationFlags: PriorityClass | 0x10,
         lpEnvironment: nullptr,
         lpCurrentDirectory: nullptr,
         lpStartupInfo: &v10,
         lpProcessInformation: &v11) )
  {
    m_pMemory = g_OriginalCommandLineParameters.m_Memory.m_pMemory;
    g_OriginalCommandLineParameters.m_Size = 0;
    if ( g_OriginalCommandLineParameters.m_Memory.m_nGrowSize >= 0 )
    {
      if ( g_OriginalCommandLineParameters.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: g_OriginalCommandLineParameters.m_Memory.m_pMemory);
        m_pMemory = nullptr;
        g_OriginalCommandLineParameters.m_Memory.m_pMemory = nullptr;
      }
      g_OriginalCommandLineParameters.m_Memory.m_nAllocationCount = 0;
    }
    g_OriginalCommandLineParameters.m_pElements = m_pMemory;
    return 1;
  }
  IP_GetLastErrorString(pStr: v8, maxLen: 1024);
  _Warning(a1: " - ERROR in CreateProcess (%s)!\n", v8);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10007D80
// Name: void VMPI_FlushGroupedPackets(unsigned long)
// Source: json
//------------------------------------------------------------------------------
void __cdecl VMPI_FlushGroupedPackets(unsigned int msInterval)
{
  int v1; // eax
  int i; // ebx
  CVMPIConnection *v3; // esi
  IThreadedTCPSocket *m_pSocket; // ecx
  int j; // edi
  CCriticalSectionLock connectionsLock; // [esp+4h] [ebp-8h] BYREF

  if ( msInterval != 0 )
  {
    v1 = _Plat_MSTime();
    if ( v1 - g_LastFlushGroupedPacketsTime < msInterval )
      return;
    g_LastFlushGroupedPacketsTime = v1;
  }
  CCriticalSectionLock::CCriticalSectionLock(this: &connectionsLock, pCS: &g_ConnectionsCS);
  CCriticalSectionLock::Lock(this: &connectionsLock);
  for ( i = 0; i < g_nConnections; ++i )
  {
    v3 = g_Connections[i];
    if ( v3 != nullptr )
    {
      m_pSocket = v3->m_pSocket;
      if ( m_pSocket != nullptr && v3->m_GroupedChunks.m_Size != 0 )
      {
        m_pSocket->SendChunks(
          this: m_pSocket,
          a2: (const void *const *)v3->m_GroupedChunks.m_Memory.m_pMemory,
          a3: v3->m_GroupedChunkLengths.m_Memory.m_pMemory,
          a4: v3->m_GroupedChunks.m_Size);
        for ( j = 1; j < v3->m_GroupedChunks.m_Size; ++j )
          free(pMem: v3->m_GroupedChunks.m_Memory.m_pMemory[j]);
        v3->m_GroupedChunks.m_Size = 0;
        v3->m_GroupedChunkLengths.m_Size = 0;
      }
    }
  }
  CCriticalSectionLock::~CCriticalSectionLock(this: &connectionsLock);
}

//------------------------------------------------------------------------------
// Address: 0x10007FD0
// Name: public: void CMasterBroadcaster::SetNoTimeoutOption(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMasterBroadcaster::SetNoTimeoutOption(CMasterBroadcaster *this)
{
  int v2; // edi
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  const char *m_pName; // edi
  char **m_pMemory; // eax
  int v7; // ecx
  char **v8; // esi
  CCriticalSectionLock connectionsLock; // [esp+8h] [ebp-8h] BYREF

  CCriticalSectionLock::CCriticalSectionLock(this: &connectionsLock, pCS: &g_ConnectionsCS);
  CCriticalSectionLock::Lock(this: &connectionsLock);
  v2 = 1;
  if ( this->m_BroadcastInfo.m_Args.m_Size <= 1 )
  {
LABEL_4:
    m_Size = this->m_BroadcastInfo.m_Args.m_Size;
    m_nAllocationCount = this->m_BroadcastInfo.m_Args.m_Memory.m_nAllocationCount;
    m_pName = g_VMPIParams[18].m_pName;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<int,int>::Grow(
        this: (CUtlMemory<CTCPPacket *,int> *)&this->m_BroadcastInfo.m_Args,
        num: m_Size - m_nAllocationCount + 1);
    ++this->m_BroadcastInfo.m_Args.m_Size;
    m_pMemory = this->m_BroadcastInfo.m_Args.m_Memory.m_pMemory;
    v7 = this->m_BroadcastInfo.m_Args.m_Size - 2;
    this->m_BroadcastInfo.m_Args.m_pElements = m_pMemory;
    if ( v7 > 0 )
      _V_memmove(dest: (unsigned __int8 *)m_pMemory + 8, src: (unsigned __int8 *)m_pMemory + 4, count: 4 * v7);
    v8 = this->m_BroadcastInfo.m_Args.m_Memory.m_pMemory + 1;
    if ( v8 != nullptr )
      *v8 = (char *)m_pName;
  }
  else
  {
    while ( _V_stricmp(s1: this->m_BroadcastInfo.m_Args.m_Memory.m_pMemory[v2], s2: g_VMPIParams[18].m_pName) != 0 )
    {
      if ( ++v2 >= this->m_BroadcastInfo.m_Args.m_Size )
        goto LABEL_4;
    }
  }
  CCriticalSectionLock::~CCriticalSectionLock(this: &connectionsLock);
}

//------------------------------------------------------------------------------
// Address: 0x100080A0
// Name: void VMPI_InviteDebugWorkers(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl VMPI_InviteDebugWorkers()
{
  int v0; // eax
  CCriticalSectionLock v1; // [esp+0h] [ebp-8h] BYREF

  CCriticalSectionLock::CCriticalSectionLock(this: &v1, pCS: &g_ConnectionsCS);
  CCriticalSectionLock::Lock(this: &v1);
  V_strncpy(pDest: g_MasterBroadcaster.m_BroadcastInfo.m_Password, pSrc: "debugworker", maxLen: 256);
  CCriticalSectionLock::~CCriticalSectionLock(this: &v1);
  CMasterBroadcaster::SetNoTimeoutOption(this: &g_MasterBroadcaster);
  ThreadedTCP_EnableTimeouts(bEnable: false);
  CCriticalSectionLock::CCriticalSectionLock(this: &v1, pCS: &g_ConnectionsCS);
  CCriticalSectionLock::Lock(this: &v1);
  v0 = g_MasterBroadcaster.m_nMaxWorkers + 25;
  g_MasterBroadcaster.m_nMaxWorkers = 512;
  if ( v0 <= 512 )
    g_MasterBroadcaster.m_nMaxWorkers = v0;
  CCriticalSectionLock::~CCriticalSectionLock(this: &v1);
}

//------------------------------------------------------------------------------
// Address: 0x10008290
// Name: void ParseDependencyFile(class CDependencyInfo __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ParseDependencyFile(CDependencyInfo *pInfo, const char *pDepFilename)
{
  _iobuf *v2; // esi
  int v3; // eax
  char v4; // cl
  bool v5; // zf
  char *v6; // eax
  CDependencyInfo::CDependencyFile *v7; // edi
  char v8; // bl
  char *v9; // eax
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CDependencyInfo::CDependencyFile **m_pMemory; // ecx
  int v13; // eax
  CDependencyInfo::CDependencyFile **v14; // eax
  char fullFilename[260]; // [esp+Ch] [ebp-210h] BYREF
  char tempStr[260]; // [esp+110h] [ebp-10Ch] BYREF
  _iobuf *fp; // [esp+214h] [ebp-8h]
  CDependencyInfo::CDependencyFile *pFile; // [esp+218h] [ebp-4h]

  fp = fopen(file: pDepFilename, mode: "rt");
  if ( fp == nullptr )
    _Error(a1: "Can't find %s.", pDepFilename);
  while ( 1 )
  {
    v2 = fp;
    if ( fgets(string: tempStr, count: 260, str: fp) == nullptr || tempStr[0] == 0 )
      break;
    v3 = &tempStr[strlen(tempStr) + 1] - &tempStr[1];
    v5 = fullFilename[v3 + 259] == 10;
    v6 = &fullFilename[v3 + 259];
    if ( v5 )
      *v6 = v4;
    v7 = (CDependencyInfo::CDependencyFile *)operator new(nSize: 0x104u);
    pFile = v7;
    v8 = 0;
    strstr(str1: (unsigned __int8 *)tempStr, str2: "optional ");
    if ( v9 == tempStr )
    {
      v8 = 1;
      V_strncpy(pDest: v7->m_Name, pSrc: &tempStr[9], maxLen: 260);
    }
    else
    {
      V_strncpy(pDest: v7->m_Name, pSrc: tempStr, maxLen: 260);
    }
    V_ComposeFileName(path: pInfo->m_DependencyFilesDir, filename: v7->m_Name, dest: fullFilename, destSize: 260);
    if ( access(path: fullFilename, amode: 0) != 0 )
    {
      free(pMem: v7);
      if ( v8 == 0 )
        _Error(a1: "Can't find %s (listed in %s).", fullFilename, pDepFilename);
    }
    else
    {
      m_Size = pInfo->m_Files.m_Size;
      m_nAllocationCount = pInfo->m_Files.m_Memory.m_nAllocationCount;
      if ( m_Size + 1 > m_nAllocationCount )
        CUtlMemory<int,int>::Grow(
          this: (CUtlMemory<CTCPPacket *,int> *)&pInfo->m_Files,
          num: m_Size - m_nAllocationCount + 1);
      ++pInfo->m_Files.m_Size;
      m_pMemory = pInfo->m_Files.m_Memory.m_pMemory;
      v13 = pInfo->m_Files.m_Size - m_Size - 1;
      pInfo->m_Files.m_pElements = m_pMemory;
      if ( v13 > 0 )
        _V_memmove(
          dest: (unsigned __int8 *)&m_pMemory[m_Size + 1],
          src: (unsigned __int8 *)&m_pMemory[m_Size],
          count: 4 * v13);
      v14 = &pInfo->m_Files.m_Memory.m_pMemory[m_Size];
      if ( v14 != nullptr )
        *v14 = pFile;
    }
  }
  fclose(stream: v2);
}

//------------------------------------------------------------------------------
// Address: 0x10008450
// Name: void SetupDependenciesForPatch(class CDependencyInfo __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SetupDependenciesForPatch(CDependencyInfo *pInfo, char *pPatchDirectory)
{
  char *v2; // ebx
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CDependencyInfo::CDependencyFile **m_pMemory; // ecx
  int v6; // eax
  CDependencyInfo::CDependencyFile **v7; // eax
  int v8; // esi
  char searchStr[260]; // [esp+0h] [ebp-230h] BYREF
  _finddata64i32_t data; // [esp+104h] [ebp-12Ch] BYREF
  int handle; // [esp+22Ch] [ebp-4h]

  V_ComposeFileName(path: pPatchDirectory, filename: "*.*", dest: searchStr, destSize: 260);
  handle = _findfirst64i32(szWild: searchStr, pfd: &data);
  if ( handle != -1 )
  {
    do
    {
      if ( data.name[0] != 46 && (data.attrib & 0x10) == 0 )
      {
        v2 = (char *)operator new(nSize: 0x104u);
        V_strncpy(pDest: v2, pSrc: data.name, maxLen: 260);
        m_Size = pInfo->m_Files.m_Size;
        m_nAllocationCount = pInfo->m_Files.m_Memory.m_nAllocationCount;
        if ( m_Size + 1 > m_nAllocationCount )
          CUtlMemory<int,int>::Grow(
            this: (CUtlMemory<CTCPPacket *,int> *)&pInfo->m_Files,
            num: m_Size - m_nAllocationCount + 1);
        ++pInfo->m_Files.m_Size;
        m_pMemory = pInfo->m_Files.m_Memory.m_pMemory;
        v6 = pInfo->m_Files.m_Size - m_Size - 1;
        pInfo->m_Files.m_pElements = m_pMemory;
        if ( v6 > 0 )
          _V_memmove(
            dest: (unsigned __int8 *)&m_pMemory[m_Size + 1],
            src: (unsigned __int8 *)&m_pMemory[m_Size],
            count: 4 * v6);
        v7 = &pInfo->m_Files.m_Memory.m_pMemory[m_Size];
        if ( v7 != nullptr )
          *v7 = (CDependencyInfo::CDependencyFile *)v2;
      }
      v8 = handle;
    }
    while ( _findnext64i32(hFile: handle, pfd: &data) == 0 );
    _findclose(hFile: v8);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10008580
// Name: void SetupDependencyInfo(class CDependencyInfo __near *,char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SetupDependencyInfo(CDependencyInfo *pInfo, char *pDependencyFilename, bool bPatchMode)
{
  HMODULE ModuleHandleA; // eax
  char *v4; // eax
  char Filename[512]; // [esp+4h] [ebp-304h] BYREF
  char depFilename[260]; // [esp+204h] [ebp-104h] BYREF

  if ( bPatchMode )
  {
    SetupDependencyFilename(pInfo, pPatchDirectory: pDependencyFilename);
    SetupDependenciesForPatch(pInfo, pPatchDirectory: pDependencyFilename);
  }
  else
  {
    ModuleHandleA = GetModuleHandleA(lpModuleName: nullptr);
    if ( GetModuleFileNameA(hModule: ModuleHandleA, lpFilename: Filename, nSize: 0x200u) == 0 )
      _Error(a1: "GetModuleFileName failed.");
    V_strncpy(pDest: pInfo->m_DependencyFilesDir, pSrc: Filename, maxLen: 260);
    V_StripLastDir(dirName: pInfo->m_DependencyFilesDir, maxlen: 0x104u);
    v4 = (char *)V_UnqualifiedFileName(in: Filename);
    V_strncpy(pDest: pInfo->m_OriginalExeFilename, pSrc: v4, maxLen: 260);
    V_ComposeFileName(
      path: pInfo->m_DependencyFilesDir,
      filename: pDependencyFilename,
      dest: depFilename,
      destSize: 260);
    ParseDependencyFile(pInfo, pDepFilename: depFilename);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10008650
// Name: public: CMasterBroadcaster::CMasterBroadcaster(void)
// Source: json
//------------------------------------------------------------------------------
CMasterBroadcaster *__thiscall CMasterBroadcaster::CMasterBroadcaster(CMasterBroadcaster *this)
{
  this->m_BroadcastInfo.m_Args.m_Memory.m_pMemory = nullptr;
  this->m_BroadcastInfo.m_Args.m_Memory.m_nAllocationCount = 0;
  this->m_BroadcastInfo.m_Args.m_Memory.m_nGrowSize = 0;
  this->m_BroadcastInfo.m_Args.m_Size = 0;
  this->m_BroadcastInfo.m_Args.m_pElements = nullptr;
  this->m_PatchWorkerIPs.m_Memory.m_pMemory = nullptr;
  this->m_PatchWorkerIPs.m_Memory.m_nAllocationCount = 0;
  this->m_PatchWorkerIPs.m_Memory.m_nGrowSize = 0;
  this->m_PatchWorkerIPs.m_Size = 0;
  this->m_PatchWorkerIPs.m_pElements = nullptr;
  this->m_ConnectionCreator.__vftable = (CVMPIConnectionCreator_vtbl *)&CVMPIConnectionCreator::`vftable';
  CExpressionEvaluator::CExpressionEvaluator(this: &this->m_hShutdownEvent);
  CExpressionEvaluator::CExpressionEvaluator(this: &this->m_hShutdownReply);
  this->m_pListenSocket = nullptr;
  this->m_pDownloaderListenSocket = nullptr;
  this->m_pSocket = nullptr;
  this->m_iListenPort = -1;
  this->m_iDownloaderListenPort = -1;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100086D0
// Name: private: void CMasterBroadcaster::GetPatchWorkerList(int,char __near * __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMasterBroadcaster::GetPatchWorkerList(CMasterBroadcaster *this, int argc, char **argv)
{
  CUtlMemory<CMasterMulticastThread::CChunkInfo,int> *p_m_PatchWorkerIPs; // esi
  int v5; // edi
  int v6; // eax
  const char **v7; // ebx
  CMasterMulticastThread::CChunkInfo *m_pMemory; // edi
  int m_nAllocationCount; // eax
  CMasterMulticastThread::CChunkInfo *v10; // ecx
  int v11; // eax
  CIPAddr *v12; // eax
  CIPAddr addr; // [esp+8h] [ebp-20h] BYREF
  int a; // [esp+10h] [ebp-18h] BYREF
  int b; // [esp+14h] [ebp-14h] BYREF
  int c; // [esp+18h] [ebp-10h] BYREF
  int d; // [esp+1Ch] [ebp-Ch] BYREF
  int workerCount; // [esp+20h] [ebp-8h]
  int i; // [esp+24h] [ebp-4h]
  int iWorker; // [esp+34h] [ebp+Ch]

  p_m_PatchWorkerIPs = (CUtlMemory<CMasterMulticastThread::CChunkInfo,int> *)&this->m_PatchWorkerIPs;
  this->m_PatchWorkerIPs.m_Size = 0;
  if ( this->m_PatchWorkerIPs.m_Memory.m_nGrowSize >= 0 )
  {
    if ( p_m_PatchWorkerIPs->m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: p_m_PatchWorkerIPs->m_pMemory);
      p_m_PatchWorkerIPs->m_pMemory = nullptr;
    }
    p_m_PatchWorkerIPs->m_nAllocationCount = 0;
  }
  p_m_PatchWorkerIPs[1].m_nAllocationCount = (int)p_m_PatchWorkerIPs->m_pMemory;
  i = 0;
  if ( argc - 1 > 0 )
  {
    while ( _V_stricmp(s1: argv[i], s2: "-mpi_PatchWorkers") != 0 )
    {
      if ( ++i >= argc - 1 )
        return;
    }
    v5 = i;
    v6 = atoi(nptr: argv[i + 1]);
    workerCount = v6;
    iWorker = 0;
    if ( v6 > 0 )
    {
      v7 = (const char **)&argv[i + 2];
      while ( 1 )
      {
        if ( v5 + iWorker + 2 >= argc )
          _Error(a1: "-mpi_PatchWorkers: %d specified for count, but not enough IPs following.\n", v6);
        sscanf(string: *v7, format: "%d.%d.%d.%d", &a, &b, &c, &d);
        CIPAddr::CIPAddr(this: &addr);
        CIPAddr::Init(this: &addr, ip0: a, ip1: b, ip2: c, ip3: d, ipPort: 0);
        m_pMemory = p_m_PatchWorkerIPs[1].m_pMemory;
        m_nAllocationCount = p_m_PatchWorkerIPs->m_nAllocationCount;
        if ( (int)&m_pMemory->m_iChunk + 1 > m_nAllocationCount )
          CUtlMemory<CIPAddr,int>::Grow(
            this: p_m_PatchWorkerIPs,
            num: (int)&m_pMemory->m_iChunk - m_nAllocationCount + 1);
        ++p_m_PatchWorkerIPs[1].m_pMemory;
        v10 = p_m_PatchWorkerIPs->m_pMemory;
        v11 = (char *)p_m_PatchWorkerIPs[1].m_pMemory - (char *)m_pMemory - 1;
        p_m_PatchWorkerIPs[1].m_nAllocationCount = (int)p_m_PatchWorkerIPs->m_pMemory;
        if ( v11 > 0 )
          _V_memmove(
            dest: (unsigned __int8 *)&v10[(int)m_pMemory + 1],
            src: (unsigned __int8 *)&v10[(_DWORD)m_pMemory],
            count: 6 * v11);
        v12 = (CIPAddr *)&p_m_PatchWorkerIPs->m_pMemory[(_DWORD)m_pMemory];
        if ( v12 != nullptr )
          *v12 = addr;
        ++v7;
        if ( ++iWorker >= workerCount )
          break;
        v6 = workerCount;
        v5 = i;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10008860
// Name: void VMPI_Finalize(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall VMPI_Finalize(int a1@<ebp>)
{
  int i; // esi
  CVMPIConnection *v2; // eax
  IThreadedTCPSocket *m_pSocket; // ecx
  int m_Head; // esi
  UtlLinkedListElem_t<CTCPPacket *,int> *m_pMemory; // eax
  int v6; // esi
  UtlLinkedListElem_t<CTCPPacket *,int> *v7; // eax
  TSLNodeBase_t *v8; // eax
  TSLNodeBase_t *Next; // esi
  int j; // esi
  char **v11; // eax

  CMasterBroadcaster::Term(this: &g_MasterBroadcaster);
  DistributeWork_Cancel();
  for ( i = 0; i < g_nConnections; ++i )
  {
    v2 = g_Connections[i];
    if ( v2 != nullptr )
    {
      m_pSocket = v2->m_pSocket;
      if ( m_pSocket != nullptr )
      {
        v2->m_pSocket = nullptr;
        m_pSocket->Release(this: m_pSocket);
      }
      else
      {
        ((void (__thiscall *)(CVMPIConnection *, int))v2->dtr_CVMPIConnection)(a1: g_Connections[i], a2: 1);
      }
    }
  }
  m_Head = g_VMPIMessages.m_Head;
  g_nConnections = 0;
  if ( g_VMPIMessages.m_Head != -1 )
  {
    m_pMemory = g_VMPIMessages.m_Memory.m_pMemory;
    do
    {
      v6 = m_Head;
      CTCPPacket::Release(this: (CVMPIFile_Memory *)m_pMemory[v6].m_Element);
      m_pMemory = g_VMPIMessages.m_Memory.m_pMemory;
      m_Head = g_VMPIMessages.m_Memory.m_pMemory[v6].m_Next;
    }
    while ( m_Head != -1 );
  }
  CUtlLinkedList<CPartitionInfo *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CPartitionInfo *,int>,int>>::RemoveAll(this: (CUtlLinkedList<CFileChunkPacket *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CFileChunkPacket *,int>,int> > *)&g_VMPIMessages);
  v7 = g_VMPIMessages.m_Memory.m_pMemory;
  if ( g_VMPIMessages.m_Memory.m_nGrowSize >= 0 )
  {
    if ( g_VMPIMessages.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: g_VMPIMessages.m_Memory.m_pMemory);
      v7 = nullptr;
      g_VMPIMessages.m_Memory.m_pMemory = nullptr;
    }
    g_VMPIMessages.m_Memory.m_nAllocationCount = 0;
  }
  g_VMPIMessages.m_FirstFree = -1;
  g_VMPIMessages.m_NumAlloced = 0;
  g_VMPIMessages.m_LastAlloc.index = -1;
  g_VMPIMessages.m_pElements = v7;
  CUtlLinkedList<CUtlVector<char,CUtlMemory<char,int>> *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlVector<char,CUtlMemory<char,int>> *,unsigned short>,unsigned short>>::PurgeAndDeleteElements(this: &g_PersistentPackets);
  v8 = CTSListBase::Detach(this: &g_DispatchBuffers);
  if ( v8 != nullptr )
  {
    do
    {
      Next = v8->Next;
      free(pMem: v8);
      v8 = Next;
    }
    while ( Next != nullptr );
  }
  if ( g_hKernel32DLL != nullptr )
  {
    FreeLibrary(hLibModule: g_hKernel32DLL);
    g_hKernel32DLL = nullptr;
  }
  for ( j = 0; j < g_WorkerCommandLine.m_Size; ++j )
    free(pMem: g_WorkerCommandLine.m_Memory.m_pMemory[j]);
  v11 = g_WorkerCommandLine.m_Memory.m_pMemory;
  g_WorkerCommandLine.m_Size = 0;
  if ( g_WorkerCommandLine.m_Memory.m_nGrowSize >= 0 )
  {
    if ( g_WorkerCommandLine.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: g_WorkerCommandLine.m_Memory.m_pMemory);
      v11 = nullptr;
      g_WorkerCommandLine.m_Memory.m_pMemory = nullptr;
    }
    g_WorkerCommandLine.m_Memory.m_nAllocationCount = 0;
  }
  g_WorkerCommandLine.m_pElements = v11;
  VMPI_HandleAutoRestart(a1);
}

//------------------------------------------------------------------------------
// Address: 0x100089E0
// Name: void VMPI_GroupPackets(class CVMPIConnection __near *,void const __near * const __near *,int const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl VMPI_GroupPackets(CVMPIConnection *pConn, const void *const *pChunks, char *pChunkLengths, int nChunks)
{
  int m_Size; // edi
  int m_nAllocationCount; // eax
  void **m_pMemory; // ecx
  int v7; // eax
  void **v8; // eax
  int v9; // edi
  int v10; // eax
  int *v11; // ecx
  int v12; // eax
  int *v13; // eax
  int v14; // ebx
  unsigned int *v15; // esi
  int v16; // ecx
  int v17; // edx
  int v18; // edi
  int v19; // eax
  int v20; // edi
  char *v21; // eax
  int v22; // edi
  int v23; // eax
  int v24; // edi
  int v25; // eax
  void **v26; // ecx
  int v27; // eax
  void **v28; // edi
  int v29; // edi
  int v30; // eax
  int *v31; // ecx
  int v32; // eax
  int *v33; // edi
  CCriticalSectionLock connectionsLock; // [esp+Ch] [ebp-10h] BYREF
  int v35; // [esp+14h] [ebp-8h]
  int i; // [esp+18h] [ebp-4h]
  char *pOut; // [esp+30h] [ebp+14h]

  CCriticalSectionLock::CCriticalSectionLock(this: &connectionsLock, pCS: &g_ConnectionsCS);
  CCriticalSectionLock::Lock(this: &connectionsLock);
  if ( pConn->m_GroupedChunks.m_Size == 0 )
  {
    m_Size = pConn->m_GroupedChunks.m_Size;
    m_nAllocationCount = pConn->m_GroupedChunks.m_Memory.m_nAllocationCount;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<int,int>::Grow(
        this: (CUtlMemory<CTCPPacket *,int> *)&pConn->m_GroupedChunks,
        num: m_Size - m_nAllocationCount + 1);
    ++pConn->m_GroupedChunks.m_Size;
    m_pMemory = pConn->m_GroupedChunks.m_Memory.m_pMemory;
    v7 = pConn->m_GroupedChunks.m_Size - m_Size - 1;
    pConn->m_GroupedChunks.m_pElements = m_pMemory;
    if ( v7 > 0 )
      _V_memmove(
        dest: (unsigned __int8 *)&m_pMemory[m_Size + 1],
        src: (unsigned __int8 *)&m_pMemory[m_Size],
        count: 4 * v7);
    v8 = &pConn->m_GroupedChunks.m_Memory.m_pMemory[m_Size];
    if ( v8 != nullptr )
      *v8 = g_GroupedPacketHeader;
    v9 = pConn->m_GroupedChunkLengths.m_Size;
    v10 = pConn->m_GroupedChunkLengths.m_Memory.m_nAllocationCount;
    if ( v9 + 1 > v10 )
      CUtlMemory<int,int>::Grow(this: (CUtlMemory<CTCPPacket *,int> *)&pConn->m_GroupedChunkLengths, num: v9 - v10 + 1);
    ++pConn->m_GroupedChunkLengths.m_Size;
    v11 = pConn->m_GroupedChunkLengths.m_Memory.m_pMemory;
    v12 = pConn->m_GroupedChunkLengths.m_Size - v9 - 1;
    pConn->m_GroupedChunkLengths.m_pElements = v11;
    if ( v12 > 0 )
      _V_memmove(dest: (unsigned __int8 *)&v11[v9 + 1], src: (unsigned __int8 *)&v11[v9], count: 4 * v12);
    v13 = &pConn->m_GroupedChunkLengths.m_Memory.m_pMemory[v9];
    if ( v13 != nullptr )
      *v13 = 2;
  }
  v14 = nChunks;
  v15 = (unsigned int *)pChunkLengths;
  v16 = 0;
  v17 = 0;
  v18 = 0;
  v19 = 0;
  if ( nChunks >= 2 )
  {
    do
    {
      v16 += *(_DWORD *)&pChunkLengths[4 * v19];
      v17 += *(_DWORD *)&pChunkLengths[4 * v19 + 4];
      v19 += 2;
    }
    while ( v19 < nChunks - 1 );
    v14 = nChunks;
  }
  if ( v19 < v14 )
    v18 = *(_DWORD *)&pChunkLengths[4 * v19];
  v20 = v17 + v16 + v18;
  v35 = v20 + 4;
  v21 = (char *)operator new(nSize: v20 + 4);
  *(_DWORD *)v21 = v20;
  pOut = v21;
  v22 = 4;
  if ( v14 > 0 )
  {
    v23 = (char *)pChunks - pChunkLengths;
    for ( i = (char *)pChunks - pChunkLengths; ; v23 = i )
    {
      memcpy(dst: (unsigned __int8 *)&pOut[v22], src: *(unsigned __int8 **)((char *)v15 + v23), count: *v15);
      v22 += *v15++;
      if ( --v14 == 0 )
        break;
    }
  }
  v24 = pConn->m_GroupedChunks.m_Size;
  v25 = pConn->m_GroupedChunks.m_Memory.m_nAllocationCount;
  if ( v24 + 1 > v25 )
    CUtlMemory<int,int>::Grow(this: (CUtlMemory<CTCPPacket *,int> *)&pConn->m_GroupedChunks, num: v24 - v25 + 1);
  ++pConn->m_GroupedChunks.m_Size;
  v26 = pConn->m_GroupedChunks.m_Memory.m_pMemory;
  v27 = pConn->m_GroupedChunks.m_Size - v24 - 1;
  pConn->m_GroupedChunks.m_pElements = v26;
  if ( v27 > 0 )
    _V_memmove(dest: (unsigned __int8 *)&v26[v24 + 1], src: (unsigned __int8 *)&v26[v24], count: 4 * v27);
  v28 = &pConn->m_GroupedChunks.m_Memory.m_pMemory[v24];
  if ( v28 != nullptr )
    *v28 = pOut;
  v29 = pConn->m_GroupedChunkLengths.m_Size;
  v30 = pConn->m_GroupedChunkLengths.m_Memory.m_nAllocationCount;
  if ( v29 + 1 > v30 )
    CUtlMemory<int,int>::Grow(this: (CUtlMemory<CTCPPacket *,int> *)&pConn->m_GroupedChunkLengths, num: v29 - v30 + 1);
  ++pConn->m_GroupedChunkLengths.m_Size;
  v31 = pConn->m_GroupedChunkLengths.m_Memory.m_pMemory;
  v32 = pConn->m_GroupedChunkLengths.m_Size - v29 - 1;
  pConn->m_GroupedChunkLengths.m_pElements = v31;
  if ( v32 > 0 )
    _V_memmove(dest: (unsigned __int8 *)&v31[v29 + 1], src: (unsigned __int8 *)&v31[v29], count: 4 * v32);
  v33 = &pConn->m_GroupedChunkLengths.m_Memory.m_pMemory[v29];
  if ( v33 != nullptr )
    *v33 = v35;
  CCriticalSectionLock::~CCriticalSectionLock(this: &connectionsLock);
}

//------------------------------------------------------------------------------
// Address: 0x10008BF0
// Name: void VMPI_SetupAutoRestartParameters(int,char __near * __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl VMPI_SetupAutoRestartParameters(int argc, char **argv)
{
  int v2; // edi
  char *v3; // ebx
  unsigned int v4; // esi
  char *v5; // [esp+4h] [ebp-4h]

  if ( VMPI_FindArg(argc, argv, pName: g_VMPIParams[6].m_pName, pDefault: setName) != nullptr )
  {
    v2 = 0;
    g_OriginalCommandLineParameters.m_Size = 0;
    CUtlVector<char *,CUtlMemory<char *,int>>::InsertMultipleBefore(
      this: (CUtlVector<int,CUtlMemory<int,int> > *)&g_OriginalCommandLineParameters,
      elem: 0,
      num: argc);
    if ( argc > 0 )
    {
      do
      {
        v3 = argv[v2];
        v4 = _V_strlen(str: v3) + 1;
        v5 = (char *)operator new(nSize: v4);
        V_strncpy(pDest: v5, pSrc: v3, maxLen: v4);
        g_OriginalCommandLineParameters.m_Memory.m_pMemory[v2++] = v5;
      }
      while ( v2 < argc );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10008DE0
// Name: void InternalHandleSocketErrors(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InternalHandleSocketErrors()
{
  int v0; // esi
  int m_Head; // eax
  CVMPIConnection **m_pMemory; // ebx
  UtlLinkedListElem_t<CVMPIConnection *,int> *v3; // edx
  CVMPIConnection **v4; // ecx
  int v5; // eax
  UtlLinkedListElem_t<CVMPIConnection *,int> *v6; // eax
  int m_Size; // edi
  CUtlVector<CVMPIConnection *,CUtlMemory<CVMPIConnection *,int> > errorSockets; // [esp+Ch] [ebp-1Ch] BYREF
  CCriticalSectionLock csLock; // [esp+20h] [ebp-8h] BYREF

  v0 = 0;
  memset(&errorSockets, 0, sizeof(errorSockets));
  CCriticalSectionLock::CCriticalSectionLock(this: &csLock, pCS: &g_ErrorSocketsCS);
  CCriticalSectionLock::Lock(this: &csLock);
  CUtlVector<char *,CUtlMemory<char *,int>>::InsertMultipleBefore(
    this: (CUtlVector<int,CUtlMemory<int,int> > *)&errorSockets,
    elem: 0,
    num: g_ErrorSockets.m_ElementCount);
  m_Head = g_ErrorSockets.m_Head;
  m_pMemory = errorSockets.m_Memory.m_pMemory;
  if ( g_ErrorSockets.m_Head != -1 )
  {
    v3 = g_ErrorSockets.m_Memory.m_pMemory;
    v4 = errorSockets.m_Memory.m_pMemory;
    do
    {
      v5 = m_Head;
      *v4 = v3[v5].m_Element;
      v3 = g_ErrorSockets.m_Memory.m_pMemory;
      m_Head = g_ErrorSockets.m_Memory.m_pMemory[v5].m_Next;
      ++v4;
    }
    while ( m_Head != -1 );
  }
  CUtlLinkedList<CPartitionInfo *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CPartitionInfo *,int>,int>>::RemoveAll(this: (CUtlLinkedList<CFileChunkPacket *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CFileChunkPacket *,int>,int> > *)&g_ErrorSockets);
  v6 = g_ErrorSockets.m_Memory.m_pMemory;
  if ( g_ErrorSockets.m_Memory.m_nGrowSize >= 0 )
  {
    if ( g_ErrorSockets.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: g_ErrorSockets.m_Memory.m_pMemory);
      v6 = nullptr;
      g_ErrorSockets.m_Memory.m_pMemory = nullptr;
    }
    g_ErrorSockets.m_Memory.m_nAllocationCount = 0;
  }
  g_ErrorSockets.m_FirstFree = -1;
  g_ErrorSockets.m_NumAlloced = 0;
  g_ErrorSockets.m_LastAlloc.index = -1;
  g_ErrorSockets.m_pElements = v6;
  CCriticalSectionLock::Unlock(this: &csLock);
  m_Size = errorSockets.m_Size;
  if ( errorSockets.m_Size > 0 )
  {
    do
    {
      CVMPIConnection::HandleDisconnect(this: m_pMemory[v0]);
      m_pMemory[v0]->Release(this: m_pMemory[v0], a2: true);
      ++v0;
    }
    while ( v0 < m_Size );
  }
  UpdateActiveConnectionsText();
  CCriticalSectionLock::~CCriticalSectionLock(this: &csLock);
  if ( errorSockets.m_Memory.m_nGrowSize >= 0 && m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x10008F00
// Name: void VMPI_HandleSocketErrors(unsigned long)
// Source: json
//------------------------------------------------------------------------------
void __cdecl VMPI_HandleSocketErrors(DWORD timeout)
{
  void *UserData; // eax

  UserData = CTCPPacket::GetUserData(this: &g_ErrorSocketsEvent);
  if ( WaitForSingleObject(hHandle: UserData, dwMilliseconds: timeout) == 0 )
    InternalHandleSocketErrors();
}

//------------------------------------------------------------------------------
// Address: 0x10008F40
// Name: bool VMPI_GetNextMessage(class MessageBuffer __near *,int __near *,unsigned long)
// Source: json
//------------------------------------------------------------------------------
char __cdecl VMPI_GetNextMessage(MessageBuffer *pBuf, int *pSource, CTCPPacket *startTimeout)
{
  DWORD v3; // eax
  CTCPPacket *v4; // eax
  int m_Head; // edi
  int v7; // esi
  CTCPPacket *m_Element; // ebx
  int i; // eax
  signed int m_Size; // esi
  int j; // edi
  unsigned int v12; // ebx
  unsigned __int8 *v13; // eax
  int v14; // edx
  CTCPPacket *v15; // edi
  unsigned int v16; // ecx
  CTCPPacket **m_pMemory; // edx
  CTCPPacket **v18; // eax
  CTCPPacket **v19; // edi
  int v20; // edi
  int v21; // ebx
  CTCPPacket *v22; // esi
  int m_Len; // eax
  int v24; // ecx
  int v25; // eax
  char szPacketID[64]; // [esp+Ch] [ebp-ACh] BYREF
  char szSubPacketID[64]; // [esp+4Ch] [ebp-6Ch] BYREF
  void *handles[2]; // [esp+8Ch] [ebp-2Ch] BYREF
  CCriticalSectionLock csLock; // [esp+94h] [ebp-24h] BYREF
  CUtlVector<CTCPPacket *,CUtlMemory<CTCPPacket *,int> > groupedPackets; // [esp+9Ch] [ebp-1Ch] BYREF
  int iCurOffset; // [esp+B0h] [ebp-8h]
  unsigned int startTime; // [esp+B4h] [ebp-4h]
  CVMPIFile_Memory *pPacket; // [esp+C8h] [ebp+10h]

  handles[0] = CTCPPacket::GetUserData(this: &g_ErrorSocketsEvent);
  handles[1] = CTCPPacket::GetUserData(this: &g_VMPIMessagesEvent);
  startTime = _Plat_MSTime();
  v3 = WaitForMultipleObjects(nCount: 2u, lpHandles: handles, bWaitAll: false, dwMilliseconds: (DWORD)startTimeout);
  if ( v3 == 258 )
    return 0;
  while ( v3 == 0 )
  {
    InternalHandleSocketErrors();
    v4 = (CTCPPacket *)(_Plat_MSTime() - startTime);
    if ( v4 >= startTimeout )
      return 0;
    v3 = WaitForMultipleObjects(
           nCount: 2u,
           lpHandles: handles,
           bWaitAll: false,
           dwMilliseconds: (char *)startTimeout - (char *)v4);
    if ( v3 == 258 )
      return 0;
  }
  if ( v3 != 1 )
  {
    _Error(a1: "VMPI_GetNextMessage: WaitForSingleObject returned %lu", v3);
    return 0;
  }
  CCriticalSectionLock::CCriticalSectionLock(this: &csLock, pCS: &g_VMPIMessagesCS);
  CCriticalSectionLock::Lock(this: &csLock);
  m_Head = g_VMPIMessages.m_Head;
  v7 = g_VMPIMessages.m_Head;
  m_Element = g_VMPIMessages.m_Memory.m_pMemory[g_VMPIMessages.m_Head].m_Element;
  pPacket = (CVMPIFile_Memory *)m_Element;
  CUtlLinkedList<CThreadedTCPSocket::SendData_t *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CThreadedTCPSocket::SendData_t *,int>,int>>::Unlink(
    this: (CUtlLinkedList<CFileChunkPacket *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CFileChunkPacket *,int>,int> > *)&g_VMPIMessages,
    elem: g_VMPIMessages.m_Head);
  g_VMPIMessages.m_Memory.m_pMemory[v7].m_Next = g_VMPIMessages.m_FirstFree;
  g_VMPIMessages.m_FirstFree = m_Head;
  for ( i = m_Element->m_Len; i >= 6; m_Element = v22 )
  {
    if ( m_Element->m_Data[0] != 27 || m_Element->m_Data[1] != 4 )
      break;
    m_Size = 0;
    memset(&groupedPackets, 0, sizeof(groupedPackets));
    for ( j = 2; ; j = iCurOffset )
    {
      v12 = *(_DWORD *)&m_Element->m_Data[j];
      if ( (int)(v12 + j) > i )
        _Error(a1: "Invalid chunked packet\n");
      iCurOffset = j + 4;
      v13 = (unsigned __int8 *)operator new(nSize: v12 + 11);
      v14 = iCurOffset;
      v15 = (CTCPPacket *)v13;
      *((_DWORD *)v13 + 1) = v12;
      *(_DWORD *)v13 = pPacket->__vftable;
      memcpy(dst: v13 + 8, src: (unsigned __int8 *)&pPacket->m_DataLen + v14, count: v12);
      v16 = m_Size;
      startTime = m_Size;
      if ( m_Size + 1 > groupedPackets.m_Memory.m_nAllocationCount )
      {
        CUtlMemory<int,int>::Grow(
          this: &groupedPackets.m_Memory,
          num: m_Size - groupedPackets.m_Memory.m_nAllocationCount + 1);
        m_Size = groupedPackets.m_Size;
        v16 = startTime;
      }
      m_pMemory = groupedPackets.m_Memory.m_pMemory;
      groupedPackets.m_Size = ++m_Size;
      groupedPackets.m_pElements = groupedPackets.m_Memory.m_pMemory;
      if ( (int)(m_Size - v16 - 1) > 0 )
      {
        _V_memmove(
          dest: (unsigned __int8 *)&groupedPackets.m_Memory.m_pMemory[v16 + 1],
          src: (unsigned __int8 *)&groupedPackets.m_Memory.m_pMemory[v16],
          count: 4 * (m_Size - v16 - 1));
        m_pMemory = groupedPackets.m_Memory.m_pMemory;
        v16 = startTime;
      }
      v18 = &m_pMemory[v16];
      if ( v18 != nullptr )
        *v18 = v15;
      i = (int)pPacket->m_pData;
      iCurOffset += v12;
      if ( iCurOffset + 4 > i )
        break;
      m_Element = (CTCPPacket *)pPacket;
    }
    if ( m_Size > 0 )
    {
      v19 = &groupedPackets.m_Memory.m_pMemory[m_Size - 1];
      do
      {
        CUtlLinkedList<CTCPPacket *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CTCPPacket *,int>,int>>::AddToHead(
          this: &g_VMPIMessages,
          src: v19--);
        --m_Size;
      }
      while ( m_Size != 0 );
    }
    CTCPPacket::Release(this: pPacket);
    CUtlVector<CMasterMulticastThread::CChunkInfo,CUtlMemory<CMasterMulticastThread::CChunkInfo,int>>::~CUtlVector<CMasterMulticastThread::CChunkInfo,CUtlMemory<CMasterMulticastThread::CChunkInfo,int>>(this: (CUtlVector<CFileResponse,CUtlMemory<CFileResponse,int> > *)&groupedPackets);
    v20 = g_VMPIMessages.m_Head;
    v21 = g_VMPIMessages.m_Head;
    v22 = g_VMPIMessages.m_Memory.m_pMemory[g_VMPIMessages.m_Head].m_Element;
    pPacket = (CVMPIFile_Memory *)v22;
    CUtlLinkedList<CThreadedTCPSocket::SendData_t *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CThreadedTCPSocket::SendData_t *,int>,int>>::Unlink(
      this: (CUtlLinkedList<CFileChunkPacket *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CFileChunkPacket *,int>,int> > *)&g_VMPIMessages,
      elem: g_VMPIMessages.m_Head);
    g_VMPIMessages.m_Memory.m_pMemory[v21].m_Next = g_VMPIMessages.m_FirstFree;
    g_VMPIMessages.m_FirstFree = v20;
    i = v22->m_Len;
  }
  if ( g_VMPIMessages.m_ElementCount > 0 )
    CEvent::SetEvent(this: &g_VMPIMessagesEvent);
  CCriticalSectionLock::Unlock(this: &csLock);
  MessageBuffer::setLen(this: pBuf, nlen: m_Element->m_Len);
  memcpy(dst: (unsigned __int8 *)pBuf->data, src: (unsigned __int8 *)m_Element->m_Data, count: m_Element->m_Len);
  if ( g_bSuperSpewEnabled )
  {
    m_Len = m_Element->m_Len;
    if ( m_Len < 2 )
      v24 = -1;
    else
      v24 = pBuf->data[1];
    if ( m_Len < 1 )
      v25 = -1;
    else
      v25 = *pBuf->data;
    CVMPIPacketIDReg::Lookup(
      nPacketID: v25,
      nSubPacketID: v24,
      pPacketIDString: szPacketID,
      nPacketIDStringSize: 64,
      pSubPacketIDString: szSubPacketID,
      nSubPacketIDStringSize: 64);
    VMPI_SuperSpew(pMsg: "Received a packet (packetID %s, subPacketID %s)\n", szPacketID, szSubPacketID);
  }
  *pSource = (int)CTCPPacket::GetUserData(this: (CEvent *)m_Element);
  ++g_nMessagesReceived;
  g_nBytesReceived += m_Element->m_Len + 4;
  CTCPPacket::Release(this: (CVMPIFile_Memory *)m_Element);
  CCriticalSectionLock::~CCriticalSectionLock(this: &csLock);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10009290
// Name: bool VMPI_DispatchNextMessage(unsigned long)
// Source: json
//------------------------------------------------------------------------------
char __cdecl VMPI_DispatchNextMessage(CTCPPacket *timeout)
{
  TSLNodeBase_t *v1; // eax
  MessageBuffer *v2; // esi
  MessageBuffer *v3; // eax
  char v4; // bl
  char v5; // al
  TSLNodeBase_t *v6; // eax
  int iSource; // [esp+Ch] [ebp-4h] BYREF

  v1 = CTSListBase::Pop(this: &g_DispatchBuffers);
  if ( v1 != nullptr )
  {
    v2 = *((MessageBuffer **)&v1->Next + 1);
    free(pMem: v1);
  }
  else
  {
    v3 = (MessageBuffer *)operator new(nSize: 0x10u);
    if ( v3 != nullptr )
      v2 = MessageBuffer::MessageBuffer(this: v3);
    else
      v2 = nullptr;
  }
  v4 = 1;
  if ( VMPI_GetNextMessage(pBuf: v2, pSource: &iSource, startTimeout: timeout) != 0 )
  {
    while ( 1 )
    {
      if ( ConCommandBase::GetName(this: (CVMPIFile_Memory *)v2) >= 1 )
      {
        v5 = *v2->data;
        if ( (unsigned __int8)v5 < 0x20u
          && g_VMPIDispatch[v5] != nullptr
          && g_VMPIDispatch[v5](a1: v2, a2: iSource, a3: v5) )
        {
          break;
        }
      }
      if ( VMPI_GetNextMessage(pBuf: v2, pSource: &iSource, startTimeout: timeout) == 0 )
        goto LABEL_12;
    }
  }
  else
  {
LABEL_12:
    v4 = 0;
  }
  v6 = (TSLNodeBase_t *)operator new(nSize: 8u);
  if ( v6 != nullptr )
  {
    *((_DWORD *)&v6->Next + 1) = v2;
    CTSListBase::Push(this: &g_DispatchBuffers, pNode: v6);
  }
  else
  {
    CTSListBase::Push(this: &g_DispatchBuffers, pNode: nullptr);
  }
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x10009380
// Name: bool VMPI_SendChunks(void const __near * const __near *,int const __near *,int,int,int)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl VMPI_SendChunks(
        const void *const *pChunks,
        int *pChunkLengths,
        int nChunks,
        int iDest,
        char fVMPISendFlags)
{
  int i; // esi
  CUtlVector<char,CUtlMemory<char,int> > *v7; // ebx
  int j; // esi
  CUtlVector<char,CUtlMemory<char,int> > *v9; // eax
  int *v10; // esi
  unsigned __int16 v11; // ax
  int v12; // esi
  UtlLinkedListElem_t<CUtlVector<char,CUtlMemory<char,int> > *,unsigned short> *v13; // eax
  int v14; // ecx
  int v15; // eax
  CVMPIConnection *v16; // ebx
  IThreadedTCPSocket *m_pSocket; // ecx
  CCriticalSectionLock v18; // [esp+Ch] [ebp-10h] BYREF
  CCriticalSectionLock csLock; // [esp+14h] [ebp-8h] BYREF
  int iDesta; // [esp+30h] [ebp+14h]

  if ( iDest == -2 )
  {
    CCriticalSectionLock::CCriticalSectionLock(this: &csLock, pCS: &g_ConnectionsCS);
    CCriticalSectionLock::Lock(this: &csLock);
    for ( i = 0; i < g_nConnections; ++i )
      VMPI_SendChunks(pChunks, pChunkLengths, nChunks, iDest: i, fVMPISendFlags: 0);
    CCriticalSectionLock::~CCriticalSectionLock(this: &csLock);
    return true;
  }
  if ( iDest == -3 )
  {
    CCriticalSectionLock::CCriticalSectionLock(this: &v18, pCS: &g_ConnectionsCS);
    CCriticalSectionLock::Lock(this: &v18);
    CCriticalSectionLock::CCriticalSectionLock(this: &csLock, pCS: &g_PersistentPacketsCS);
    CCriticalSectionLock::Lock(this: &csLock);
    v7 = nullptr;
    for ( j = 0; j < g_nConnections; ++j )
      VMPI_SendChunks(pChunks, pChunkLengths, nChunks, iDest: j, fVMPISendFlags: 0);
    v9 = (CUtlVector<char,CUtlMemory<char,int> > *)operator new(nSize: 0x14u);
    if ( v9 != nullptr )
    {
      v9->m_Memory.m_pMemory = nullptr;
      v9->m_Memory.m_nAllocationCount = 0;
      v9->m_Memory.m_nGrowSize = 0;
      v9->m_Size = 0;
      v9->m_pElements = nullptr;
      v7 = v9;
    }
    if ( nChunks > 0 )
    {
      v10 = pChunkLengths;
      for ( iDesta = nChunks; iDesta != 0; --iDesta )
      {
        CUtlVector<char,CUtlMemory<char,int>>::InsertMultipleBefore(
          this: v7,
          elem: v7->m_Size,
          num: *v10,
          pToInsert: *(const char **)((char *)v10 + (char *)pChunks - (char *)pChunkLengths));
        ++v10;
      }
    }
    v11 = CUtlLinkedList<CUtlVector<char,CUtlMemory<char,int>> *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlVector<char,CUtlMemory<char,int>> *,unsigned short>,unsigned short>>::AllocInternal(
            this: &g_PersistentPackets,
            multilist: false);
    v12 = v11;
    if ( v11 != 0xFFFF )
    {
      CUtlLinkedList<CUtlVector<char,CUtlMemory<char,int>> *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlVector<char,CUtlMemory<char,int>> *,unsigned short>,unsigned short>>::LinkBefore(
        this: &g_PersistentPackets,
        before: 0xFFFFu,
        elem: v11);
      v13 = &g_PersistentPackets.m_Memory.m_pMemory[v12];
      if ( v13 != nullptr )
        v13->m_Element = v7;
    }
    CCriticalSectionLock::~CCriticalSectionLock(this: &csLock);
    CCriticalSectionLock::~CCriticalSectionLock(this: &v18);
    return true;
  }
  else
  {
    ++g_nMessagesSent;
    v14 = g_nBytesSent + 4;
    v15 = 0;
    g_nBytesSent += 4;
    if ( nChunks > 0 )
    {
      do
      {
        v14 += pChunkLengths[v15++];
        g_nBytesSent = v14;
      }
      while ( v15 < nChunks );
    }
    v16 = g_Connections[iDest];
    if ( v16 == nullptr )
      return false;
    if ( VMPI_FilterPacketsForServiceDownloader(pConnection: v16, pChunks, pChunkLengths, nChunks) != 0 )
      return true;
    m_pSocket = v16->m_pSocket;
    if ( m_pSocket != nullptr )
    {
      if ( g_bGroupPackets && (fVMPISendFlags & 1) != 0 )
      {
        VMPI_GroupPackets(pConn: v16, pChunks, (char *)pChunkLengths, nChunks);
        return true;
      }
      else
      {
        return m_pSocket->SendChunks(this: m_pSocket, a2: pChunks, a3: pChunkLengths, a4: nChunks);
      }
    }
    else
    {
      return false;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10009580
// Name: bool VMPI_Send2Chunks(void const __near *,int,void const __near *,int,int,int)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl VMPI_Send2Chunks(
        const void *pChunk1,
        int chunk1Len,
        const void *pChunk2,
        int chunk2Len,
        int iDest,
        char fVMPISendFlags)
{
  const void *pChunks[2]; // [esp+0h] [ebp-10h] BYREF
  int len[2]; // [esp+8h] [ebp-8h] BYREF

  pChunks[1] = pChunk2;
  pChunks[0] = pChunk1;
  len[0] = chunk1Len;
  len[1] = chunk2Len;
  return VMPI_SendChunks(pChunks, pChunkLengths: len, nChunks: 2, iDest, fVMPISendFlags);
}

//------------------------------------------------------------------------------
// Address: 0x100095C0
// Name: void VMPI_AddDisconnectHandler(void (*)(int,char const __near *))
// Source: json
//------------------------------------------------------------------------------
void __cdecl VMPI_AddDisconnectHandler(void (__cdecl *handler)(int, const char *))
{
  CUtlLinkedList<void (__cdecl *)(int,char const *),int,0,int,CUtlMemory<UtlLinkedListElem_t<void (__cdecl *)(int,char const *),int>,int>>::AddToTail(
    this: &g_DisconnectHandlers,
    src: &handler);
}

//------------------------------------------------------------------------------
// Address: 0x100095E0
// Name: void VMPI_SetMachineName(int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl VMPI_SetMachineName(int iProc, const char *pName)
{
  CVMPIConnection *v2; // esi

  if ( iProc >= 0 && iProc < g_nConnections )
  {
    v2 = g_Connections[iProc];
    if ( v2 != nullptr )
    {
      CUtlVector<char,CUtlMemory<char,int>>::CopyArray(this: &v2->m_MachineName, pArray: pName, size: strlen(pName) + 1);
      v2->m_bNameSet = true;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10009630
// Name: public: CVMPIConnection::CVMPIConnection(int)
// Source: json
//------------------------------------------------------------------------------
CVMPIConnection *__thiscall CVMPIConnection::CVMPIConnection(CVMPIConnection *this, int iConnection)
{
  char str[512]; // [esp+Ch] [ebp-200h] BYREF

  this->__vftable = (CVMPIConnection_vtbl *)&CVMPIConnection::`vftable';
  this->m_GroupedChunkLengths.m_Memory.m_pMemory = nullptr;
  this->m_GroupedChunkLengths.m_Memory.m_nAllocationCount = 0;
  this->m_GroupedChunkLengths.m_Memory.m_nGrowSize = 0;
  this->m_GroupedChunkLengths.m_Size = 0;
  this->m_GroupedChunkLengths.m_pElements = nullptr;
  this->m_GroupedChunks.m_Memory.m_pMemory = nullptr;
  this->m_GroupedChunks.m_Memory.m_nAllocationCount = 0;
  this->m_GroupedChunks.m_Memory.m_nGrowSize = 0;
  this->m_GroupedChunks.m_Size = 0;
  this->m_GroupedChunks.m_pElements = nullptr;
  this->m_MachineName.m_Memory.m_pMemory = nullptr;
  this->m_MachineName.m_Memory.m_nAllocationCount = 0;
  this->m_MachineName.m_Memory.m_nGrowSize = 0;
  this->m_MachineName.m_Size = 0;
  this->m_MachineName.m_pElements = nullptr;
  this->m_ErrorString.m_Memory.m_pMemory = nullptr;
  this->m_ErrorString.m_Memory.m_nAllocationCount = 0;
  this->m_ErrorString.m_Memory.m_nGrowSize = 0;
  this->m_ErrorString.m_Size = 0;
  this->m_ErrorString.m_pElements = nullptr;
  this->m_iConnection = iConnection;
  this->m_pSocket = nullptr;
  this->m_bIsAService = false;
  V_snprintf(pDest: str, maxLen: 0x200u, pFormat: "%d", iConnection);
  CUtlVector<char,CUtlMemory<char,int>>::CopyArray(this: &this->m_MachineName, pArray: str, size: strlen(str) + 1);
  *(_WORD *)&this->m_bNameSet = 0;
  this->m_JobWorkerID = -1;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100096F0
// Name: public: virtual void CVMPIConnection::Init(class IThreadedTCPSocket __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVMPIConnection::Init(CVMPIConnection *this, IThreadedTCPSocket *pSocket)
{
  this->m_pSocket = pSocket;
}

//------------------------------------------------------------------------------
// Address: 0x10009700
// Name: public: virtual int CVMPIConnection::GetConnectionID(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CVMPIConnection::GetConnectionID(CVMPIConnection *this)
{
  return this->m_iConnection;
}

//------------------------------------------------------------------------------
// Address: 0x10009710
// Name: public: virtual void CVMPIConnection::Release(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVMPIConnection::Release(CVMPIConnection *this, bool bForce)
{
  int m_iConnection; // esi
  CVMPIConnection *v3; // ecx

  if ( !this->m_bInErrorState || bForce )
  {
    m_iConnection = this->m_iConnection;
    this->m_pSocket = nullptr;
    v3 = g_Connections[m_iConnection];
    if ( v3 != nullptr )
      ((void (__thiscall *)(CVMPIConnection *, int))v3->dtr_CVMPIConnection)(a1: v3, a2: 1);
    g_Connections[m_iConnection] = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100099B0
// Name: public: virtual void CVMPIConnection::OnPacketReceived(class CTCPPacket __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVMPIConnection::OnPacketReceived(CVMPIConnection *this, CTCPPacket *pPacket)
{
  CCriticalSectionLock csLock; // [esp+0h] [ebp-8h] BYREF

  CTCPPacket::SetUserData(this: pPacket, userData: this->m_iConnection);
  CCriticalSectionLock::CCriticalSectionLock(this: &csLock, pCS: &g_VMPIMessagesCS);
  CCriticalSectionLock::Lock(this: &csLock);
  CUtlLinkedList<CTCPPacket *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CTCPPacket *,int>,int>>::AddToTail(
    this: &g_VMPIMessages,
    src: &pPacket);
  if ( g_VMPIMessages.m_ElementCount == 1 )
    CEvent::SetEvent(this: &g_VMPIMessagesEvent);
  CCriticalSectionLock::~CCriticalSectionLock(this: &csLock);
}

//------------------------------------------------------------------------------
// Address: 0x10009A10
// Name: public: virtual void CVMPIConnection::OnError(int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVMPIConnection::OnError(CVMPIConnection *this, int errorCode, const char *pErrorString)
{
  const char *v3; // edi
  CCriticalSectionLock csLock; // [esp+8h] [ebp-8h] BYREF

  v3 = pErrorString;
  if ( !g_bMPIMaster )
    _Msg(a1: "%s - CVMPIConnection::OnError( %s )\n", this->m_MachineName.m_Memory.m_pMemory, pErrorString);
  CCriticalSectionLock::CCriticalSectionLock(this: &csLock, pCS: &g_ErrorSocketsCS);
  CCriticalSectionLock::Lock(this: &csLock);
  if ( !this->m_bInErrorState )
  {
    this->m_bInErrorState = true;
    CUtlVector<char,CUtlMemory<char,int>>::CopyArray(this: &this->m_ErrorString, pArray: v3, size: strlen(v3) + 1);
    pErrorString = (const char *)this;
    CUtlLinkedList<CVMPIConnection *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CVMPIConnection *,int>,int>>::AddToTail(
      this: &g_ErrorSockets,
      src: (CVMPIConnection **)&pErrorString);
    CEvent::SetEvent(this: &g_ErrorSocketsEvent);
    InterlockedIncrement(lpAddend: &this->m_ErrorSignal);
  }
  CCriticalSectionLock::~CCriticalSectionLock(this: &csLock);
}

//------------------------------------------------------------------------------
// Address: 0x10009AB0
// Name: public: virtual class ITCPSocketHandler __near * CVMPIConnectionCreator::CreateNewHandler(void)
// Source: json
//------------------------------------------------------------------------------
CVMPIConnection *__thiscall CVMPIConnectionCreator::CreateNewHandler(CVMPIConnectionCreator *this)
{
  int v1; // edi
  CVMPIConnection *v2; // eax
  CVMPIConnection *result; // eax
  _DWORD *v4; // eax
  _DWORD *v5; // esi
  int v6; // edi
  int v7; // ecx
  char pDest[512]; // [esp+8h] [ebp-204h] BYREF
  int i; // [esp+208h] [ebp-4h]

  v1 = 0;
  if ( g_nConnections <= 0 )
  {
LABEL_4:
    v2 = (CVMPIConnection *)operator new(nSize: 0x6Cu);
    if ( v2 != nullptr )
      result = CVMPIConnection::CVMPIConnection(this: v2, iConnection: g_nConnections);
    else
      result = nullptr;
    v7 = g_nConnections;
    g_Connections[g_nConnections] = result;
    g_nConnections = v7 + 1;
  }
  else
  {
    while ( g_Connections[v1] != nullptr )
    {
      if ( ++v1 >= g_nConnections )
        goto LABEL_4;
    }
    i = v1;
    v4 = operator new(nSize: 0x6Cu);
    v5 = v4;
    if ( v4 != nullptr )
    {
      *v4 = &CVMPIConnection::`vftable';
      v4[3] = 0;
      v4[4] = 0;
      v4[5] = 0;
      v4[6] = 0;
      v4[7] = 0;
      v4[8] = 0;
      v4[9] = 0;
      v4[10] = 0;
      v4[11] = 0;
      v4[12] = 0;
      v4[13] = 0;
      v4[14] = 0;
      v4[15] = 0;
      v4[16] = 0;
      v4[17] = 0;
      v4[18] = 0;
      v4[19] = 0;
      v4[20] = 0;
      v4[21] = 0;
      v4[22] = 0;
      v4[24] = v1;
      v4[25] = 0;
      *((_BYTE *)v4 + 8) = 0;
      V_snprintf(pDest, maxLen: 0x200u, pFormat: "%d", v1);
      CUtlVector<char,CUtlMemory<char,int>>::CopyArray(
        this: (CUtlVector<char,CUtlMemory<char,int> > *)(v5 + 13),
        pArray: pDest,
        size: strlen(pDest) + 1);
      v6 = i;
      *((_WORD *)v5 + 52) = 0;
      v5[1] = -1;
      g_Connections[v6] = (CVMPIConnection *)v5;
      return (CVMPIConnection *)v5;
    }
    else
    {
      g_Connections[v1] = nullptr;
      return nullptr;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10009C00
// Name: bool VMPI_InternalDispatchFn(class MessageBuffer __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
char __cdecl VMPI_InternalDispatchFn(CVMPIFile_Memory *pBuf, int iSource)
{
  char v2; // al
  bool v4; // al
  unsigned int v5; // esi
  char *v6; // edi
  int m_Size; // eax
  int v8; // esi
  char **m_pMemory; // ecx
  int v10; // eax
  char **v11; // eax
  char pOut[4096]; // [esp+4h] [ebp-1008h] BYREF
  int i; // [esp+1004h] [ebp-8h]
  int p; // [esp+1008h] [ebp-4h] BYREF

  if ( ConCommandBase::GetName(this: pBuf) < 2 )
    return 0;
  v2 = BYTE1(pBuf->Close);
  switch ( v2 )
  {
    case 1:
      if ( ConCommandBase::GetName(this: pBuf) >= 3 )
      {
        VMPI_SuperSpew(pMsg: "Received SUBPACKET_MACHINE_NAME (%s).\n", (const char *)&pBuf->Close + 2);
        VMPI_SetMachineName(iProc: iSource, pName: (const char *)&pBuf->Close + 2);
        return 1;
      }
      VMPI_SuperSpew(pMsg: "Received invalid SUBPACKET_MACHINE_NAME packet (not long enough!)\n");
      return 0;
    case 3:
      if ( g_bVMPISDKModeSet )
        v4 = g_bVMPISDKMode;
      else
        v4 = !VMPI_CheckForNonSDKExecutables();
      if ( !v4 )
        _Warning(a1: "Worker %d is running in SDK mode (and the master is not)!\n", iSource);
      return 1;
    case 2:
      MessageBuffer::setOffset(this: (MessageBuffer *)pBuf, noffset: 2);
      MessageBuffer::read(this: (MessageBuffer *)pBuf, &p, bytes: 4);
      for ( i = 0; i < p; ++i )
      {
        if ( MessageBuffer::ReadString(this: (MessageBuffer *)pBuf, pOut, bufferLength: 4096) == -1 )
          _Error(a1: "Error in ReadString() while reading command line.");
        v5 = _V_strlen(str: pOut) + 1;
        v6 = (char *)operator new(nSize: v5);
        V_strncpy(pDest: v6, pSrc: pOut, maxLen: v5);
        m_Size = g_WorkerCommandLine.m_Size;
        v8 = g_WorkerCommandLine.m_Size;
        if ( g_WorkerCommandLine.m_Size + 1 > g_WorkerCommandLine.m_Memory.m_nAllocationCount )
        {
          CUtlMemory<int,int>::Grow(
            this: (CUtlMemory<CTCPPacket *,int> *)&g_WorkerCommandLine,
            num: g_WorkerCommandLine.m_Size - g_WorkerCommandLine.m_Memory.m_nAllocationCount + 1);
          m_Size = g_WorkerCommandLine.m_Size;
        }
        m_pMemory = g_WorkerCommandLine.m_Memory.m_pMemory;
        g_WorkerCommandLine.m_Size = m_Size + 1;
        v10 = m_Size - v8;
        g_WorkerCommandLine.m_pElements = g_WorkerCommandLine.m_Memory.m_pMemory;
        if ( v10 > 0 )
        {
          _V_memmove(
            dest: (unsigned __int8 *)&g_WorkerCommandLine.m_Memory.m_pMemory[v8 + 1],
            src: (unsigned __int8 *)&g_WorkerCommandLine.m_Memory.m_pMemory[v8],
            count: 4 * v10);
          m_pMemory = g_WorkerCommandLine.m_Memory.m_pMemory;
        }
        v11 = &m_pMemory[v8];
        if ( v11 != nullptr )
          *v11 = v6;
      }
      g_bReceivedWorkerCommandLine = true;
      return 1;
    default:
      break;
  }
  if ( v2 != 6 )
  {
    if ( v2 == 5 )
    {
      g_bTimingWaitDone = true;
      return 1;
    }
    return 0;
  }
  MessageBuffer::setOffset(this: (MessageBuffer *)pBuf, noffset: 2);
  if ( MessageBuffer::ReadString(this: (MessageBuffer *)pBuf, pOut: g_MasterExeName, bufferLength: 260) == -1 )
    _Error(a1: "Error in ReadString() while reading VMPI_INTERNAL_SUBPACKET_VERIFY_EXE_NAME.");
  VMPI_SuperSpew(pMsg: "Received SUBPACKET_VERIFY_EXE_NAME (%s).\n", g_MasterExeName);
  g_bReceivedMasterExeName = true;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10009E20
// Name: void VMPI_ReceiveExeName(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl VMPI_ReceiveExeName()
{
  TSLHead_t m_Head; // kr00_8
  MessageBuffer *v1; // eax
  MessageBuffer *v2; // edi
  char v3; // al
  TSLNodeBase_t **v4; // eax
  TSLNodeBase_t **v5; // esi
  HMODULE ModuleHandleA; // eax
  int v7; // [esp-18h] [ebp-22Ch]
  int v8; // [esp-18h] [ebp-22Ch]
  TSLHead_t v9; // [esp-14h] [ebp-228h]
  TSLHead_t v10; // [esp-14h] [ebp-228h]
  char baseExeFilename[260]; // [esp+0h] [ebp-214h] BYREF
  char fileBase[260]; // [esp+104h] [ebp-110h] BYREF
  double startTime; // [esp+208h] [ebp-Ch]
  int pSource; // [esp+210h] [ebp-4h] BYREF

  startTime = _Plat_FloatTime();
  while ( !g_bReceivedMasterExeName )
  {
    if ( _Plat_FloatTime() - startTime > 30.0 )
      _Error(a1: "VMPI_ReceiveExeName: timeout.");
    m_Head = g_DispatchBuffers.m_Head;
    if ( g_DispatchBuffers.m_Head.value.Next == nullptr )
      goto LABEL_7;
    while ( (unsigned __int8)_ThreadInterlockedAssignIf64(
                               a1: &g_DispatchBuffers,
                               a2: m_Head.value.Next->Next,
                               a3: m_Head.value32.DepthAndSequence - 1,
                               a4: m_Head.value.Next,
                               a5: m_Head.value32.DepthAndSequence) == 0 )
    {
      _mm_pause();
      m_Head = g_DispatchBuffers.m_Head;
      if ( g_DispatchBuffers.m_Head.value.Next == nullptr )
        goto LABEL_7;
    }
    if ( m_Head.value.Next != nullptr )
    {
      v2 = *((MessageBuffer **)&m_Head.value.Next->Next + 1);
      free(pMem: m_Head.value.Next);
    }
    else
    {
LABEL_7:
      v1 = (MessageBuffer *)operator new(nSize: 0x10u);
      if ( v1 != nullptr )
        v2 = MessageBuffer::MessageBuffer(this: v1);
      else
        v2 = nullptr;
    }
    while ( VMPI_GetNextMessage(pBuf: v2, &pSource, startTimeout: (CTCPPacket *)0x2710) != 0 )
    {
      if ( ConCommandBase::GetName(this: (CVMPIFile_Memory *)v2) >= 1 )
      {
        v3 = *v2->data;
        if ( (unsigned __int8)v3 < 0x20u
          && g_VMPIDispatch[v3] != nullptr
          && g_VMPIDispatch[v3](a1: v2, a2: pSource, a3: v3) )
        {
          break;
        }
      }
    }
    v4 = (TSLNodeBase_t **)operator new(nSize: 8u);
    if ( v4 != nullptr )
    {
      v4[1] = (TSLNodeBase_t *)v2;
      v5 = v4;
    }
    else
    {
      v5 = nullptr;
    }
    v9 = g_DispatchBuffers.m_Head;
    v7 = g_DispatchBuffers.m_Head.value32.DepthAndSequence + 65537;
    *v5 = g_DispatchBuffers.m_Head.value.Next;
    if ( (unsigned __int8)_ThreadInterlockedAssignIf64(
                            a1: &g_DispatchBuffers,
                            a2: v5,
                            a3: v7,
                            a4: v9.value.Next,
                            a5: v9.value32.DepthAndSequence) == 0 )
    {
      do
      {
        _mm_pause();
        v10 = g_DispatchBuffers.m_Head;
        v8 = g_DispatchBuffers.m_Head.value32.DepthAndSequence + 65537;
        *v5 = g_DispatchBuffers.m_Head.value.Next;
      }
      while ( (unsigned __int8)_ThreadInterlockedAssignIf64(
                                 a1: &g_DispatchBuffers,
                                 a2: v5,
                                 a3: v8,
                                 a4: v10.value.Next,
                                 a5: v10.value32.DepthAndSequence) == 0 );
    }
  }
  ModuleHandleA = GetModuleHandleA(lpModuleName: nullptr);
  if ( GetModuleFileNameA(hModule: ModuleHandleA, lpFilename: baseExeFilename, nSize: 0x104u) == 0 )
    _Error(a1: "VMPI_CheckSDKMode -> GetModuleFileName failed.");
  V_FileBase(in: baseExeFilename, out: fileBase, maxlen: 260);
  if ( _V_stricmp(s1: fileBase, s2: "vmpi_transfer") != 0 && _V_stricmp(s1: fileBase, s2: g_MasterExeName) != 0 )
    _Error(
      a1: "VMPI_ReceiveExeName: mismatched exe names (master: %s, me: %s).\n"
      "This usually just means the master finished a job like vvis really fast and started a vrad immediately, and an old"
      " vvis worker connected to the new vrad job.",
      g_MasterExeName,
      fileBase);
}

//------------------------------------------------------------------------------
// Address: 0x1000A050
// Name: bool VMPI_SendData(void __near *,int,int,int)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl VMPI_SendData(void *pData, int nBytes, int iDest, char fVMPISendFlags)
{
  return VMPI_SendChunks(
           pChunks: (const void *const *)&pData,
           pChunkLengths: &nBytes,
           nChunks: 1,
           iDest,
           fVMPISendFlags);
}

//------------------------------------------------------------------------------
// Address: 0x1000A070
// Name: void VMPI_SendMachineNameTo(int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl VMPI_SendMachineNameTo(int iProc)
{
  char *v1; // esi
  unsigned __int8 packetData[512]; // [esp+4h] [ebp-208h] BYREF
  void *pChunks; // [esp+204h] [ebp-8h] BYREF
  unsigned int nSize; // [esp+208h] [ebp-4h] BYREF

  nSize = 16;
  v1 = Buffer;
  if ( !GetComputerNameA(lpBuffer: Buffer, &nSize) )
    v1 = "(error in GetComputerName)";
  VMPI_SuperSpew(pMsg: "Sent SUBPACKET_MACHINE_NAME (%s).\n", v1);
  *(_WORD *)packetData = 283;
  V_strncpy(pDest: (char *)&packetData[2], pSrc: v1, maxLen: 510);
  nSize = strlen(v1) + 3;
  pChunks = packetData;
  VMPI_SendChunks(
    (const void *const *)&pChunks,
    pChunkLengths: (int *)&nSize,
    nChunks: 1,
    iDest: iProc,
    fVMPISendFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1000A110
// Name: void VMPI_SendCommandLine(int,char __near * __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl VMPI_SendCommandLine(int argc, char **argv)
{
  int v2; // esi
  char **v3; // edi
  MessageBuffer mb; // [esp+4h] [ebp-1Ch] BYREF
  void *pChunks; // [esp+14h] [ebp-Ch] BYREF
  int pChunkLengths; // [esp+18h] [ebp-8h] BYREF
  char cPacketHeader[2]; // [esp+1Ch] [ebp-4h] BYREF

  MessageBuffer::MessageBuffer(this: &mb);
  *(_WORD *)cPacketHeader = 539;
  MessageBuffer::write(this: &mb, p: cPacketHeader, bytes: 2);
  MessageBuffer::write(this: &mb, p: &argc, bytes: 4);
  v2 = 0;
  if ( argc > 0 )
  {
    v3 = argv;
    do
      MessageBuffer::WriteString(this: &mb, pString: v3[v2++]);
    while ( v2 < argc );
  }
  pChunkLengths = ConCommandBase::GetName(this: (CVMPIFile_Memory *)&mb);
  pChunks = mb.data;
  VMPI_SendChunks((const void *const *)&pChunks, &pChunkLengths, nChunks: 1, iDest: -3, fVMPISendFlags: 0);
  MessageBuffer::~MessageBuffer(this: &mb);
}

//------------------------------------------------------------------------------
// Address: 0x1000A1A0
// Name: void VMPI_ReceiveCommandLine(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl VMPI_ReceiveCommandLine()
{
  CVMPIConnection *v0; // esi
  IThreadedTCPSocket *m_pSocket; // ecx
  double startTime; // [esp+4h] [ebp-10h] BYREF
  int pChunkLengths; // [esp+Ch] [ebp-8h] BYREF
  unsigned __int8 chData[2]; // [esp+10h] [ebp-4h] BYREF

  ++g_nMessagesSent;
  HIDWORD(startTime) = chData;
  v0 = g_Connections[0];
  *(_WORD *)chData = 795;
  pChunkLengths = 2;
  g_nBytesSent += 6;
  if ( g_Connections[0] != nullptr
    && VMPI_FilterPacketsForServiceDownloader(
         pConnection: g_Connections[0],
         pChunks: (const void *const *)&startTime + 1,
         &pChunkLengths,
         nChunks: 1) == 0 )
  {
    m_pSocket = v0->m_pSocket;
    if ( m_pSocket != nullptr )
      m_pSocket->SendChunks(this: m_pSocket, a2: (const void *const *)&startTime + 1, a3: &pChunkLengths, a4: 1);
  }
  startTime = _Plat_FloatTime();
  while ( !g_bReceivedWorkerCommandLine )
  {
    if ( _Plat_FloatTime() - startTime > 30.0 )
      _Error(a1: "VMPI_ReceiveCommandLine: timeout. Is the master running in SDK mode?");
    VMPI_DispatchNextMessage(timeout: (CTCPPacket *)0x2710);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000A260
// Name: void VMPI_SendExeName(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl VMPI_SendExeName()
{
  HMODULE ModuleHandleA; // eax
  char baseExeFilename[260]; // [esp+0h] [ebp-224h] BYREF
  char fileBase[260]; // [esp+104h] [ebp-120h] BYREF
  MessageBuffer mb; // [esp+208h] [ebp-1Ch] BYREF
  int pChunkLengths; // [esp+218h] [ebp-Ch] BYREF
  void *pChunks; // [esp+21Ch] [ebp-8h] BYREF
  char cPacketHeader[2]; // [esp+220h] [ebp-4h] BYREF

  MessageBuffer::MessageBuffer(this: &mb);
  *(_WORD *)cPacketHeader = 1563;
  MessageBuffer::write(this: &mb, p: cPacketHeader, bytes: 2);
  ModuleHandleA = GetModuleHandleA(lpModuleName: nullptr);
  if ( GetModuleFileNameA(hModule: ModuleHandleA, lpFilename: baseExeFilename, nSize: 0x104u) == 0 )
    _Error(a1: "VMPI_CheckSDKMode -> GetModuleFileName failed.");
  V_FileBase(in: baseExeFilename, out: fileBase, maxlen: 260);
  MessageBuffer::WriteString(this: &mb, pString: fileBase);
  VMPI_SuperSpew(pMsg: "Sending SUBPACKET_VERIFY_EXE_NAME (%s).\n", fileBase);
  pChunkLengths = ConCommandBase::GetName(this: (CVMPIFile_Memory *)&mb);
  pChunks = mb.data;
  VMPI_SendChunks((const void *const *)&pChunks, &pChunkLengths, nChunks: 1, iDest: -3, fVMPISendFlags: 0);
  MessageBuffer::~MessageBuffer(this: &mb);
}

//------------------------------------------------------------------------------
// Address: 0x1000A330
// Name: private: void CMasterBroadcaster::ThreadFn(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMasterBroadcaster::ThreadFn(CMasterBroadcaster *this)
{
  void *UserData; // eax
  int v3; // edi
  int v4; // ebx
  int v5; // edi
  unsigned int v6; // edx
  ITCPConnectSocket *m_pListenSocket; // ecx
  bool v8; // al
  IThreadedTCPSocket *v9; // edx
  ITCPConnectSocket *m_pDownloaderListenSocket; // ecx
  IThreadedTCPSocket *v11; // edi
  int v12; // eax
  CVMPIConnection *v13; // ecx
  CVMPIConnection *v14; // edi
  ITCPSocketHandler *(__thiscall *GetHandler)(IThreadedTCPSocket *); // eax
  int *v16; // eax
  int m_Next; // edx
  UtlLinkedListElem_t<CUtlVector<char,CUtlMemory<char,int> > *,unsigned short> *m_pMemory; // edi
  int v19; // ebx
  CUtlVector<char,CUtlMemory<char,int> > *m_Element; // edi
  unsigned __int8 *m_Size; // ecx
  int v22; // edx
  int v23; // eax
  int v24; // edi
  void *v25; // eax
  char pData[512]; // [esp+4h] [ebp-2E8h] BYREF
  char pPacketIDString[64]; // [esp+204h] [ebp-E8h] BYREF
  char pSubPacketIDString[64]; // [esp+244h] [ebp-A8h] BYREF
  char v29; // [esp+284h] [ebp-68h] BYREF
  int v30; // [esp+288h] [ebp-64h]
  bf_write buf; // [esp+28Ch] [ebp-60h] BYREF
  CCriticalSectionLock v32; // [esp+2A4h] [ebp-48h] BYREF
  CCriticalSectionLock v33; // [esp+2ACh] [ebp-40h] BYREF
  char *v34; // [esp+2B4h] [ebp-38h]
  void *pChunks; // [esp+2B8h] [ebp-34h] BYREF
  int v36; // [esp+2BCh] [ebp-30h]
  int pChunkLengths; // [esp+2C0h] [ebp-2Ch] BYREF
  int nServiceDownloaders; // [esp+2C4h] [ebp-28h] BYREF
  unsigned int startTime; // [esp+2C8h] [ebp-24h]
  CCriticalSectionLock v40; // [esp+2CCh] [ebp-20h] BYREF
  int v41; // [esp+2D4h] [ebp-18h] BYREF
  __int16 v42; // [esp+2D8h] [ebp-14h]
  int nRegularWorkers; // [esp+2DCh] [ebp-10h] BYREF
  int v44; // [esp+2E0h] [ebp-Ch]
  IThreadedTCPSocket *v45; // [esp+2E4h] [ebp-8h] BYREF
  int v46; // [esp+2E8h] [ebp-4h]

  UserData = CTCPPacket::GetUserData(this: &this->m_hShutdownEvent);
  if ( WaitForSingleObject(hHandle: UserData, dwMilliseconds: 0x14u) == 258 )
  {
    do
    {
      startTime = GetTickCount();
      while ( 1 )
      {
        CCriticalSectionLock::CCriticalSectionLock(this: &v40, pCS: &g_ConnectionsCS);
        CCriticalSectionLock::Lock(this: &v40);
        CountActiveConnections(&nRegularWorkers, &nServiceDownloaders);
        if ( nRegularWorkers >= this->m_nMaxWorkers )
          break;
        if ( this->m_pSocket != nullptr )
        {
          v44 = _Plat_MSTime();
          if ( v44 - this->m_LastSendTime >= 0x258 )
          {
            bf_write::bf_write(this: &buf, pDebugName: "packetBuf", pData, nBytes: 512, nBits: -1);
            CMasterBroadcaster::BuildBroadcastPacket(this, &buf);
            v3 = 23397;
            v46 = 23397;
            do
            {
              if ( this->m_bPatching )
              {
                v4 = 0;
                if ( this->m_PatchWorkerIPs.m_Size > 0 )
                {
                  v5 = 0;
                  do
                  {
                    v41 = *(_DWORD *)this->m_PatchWorkerIPs.m_Memory.m_pMemory[v5].ip;
                    v42 = v46;
                    if ( !this->m_pSocket->SendTo(
                            this: this->m_pSocket,
                            a2: (const CIPAddr *)&v41,
                            a3: buf.m_pData,
                            a4: (buf.m_iCurBit + 7) >> 3) )
                      VMPI_WriteToLogFile(pMsg: "Error in SendTo trying to send patch request packet!\n");
                    _ThreadSleep(a1: 2);
                    ++v4;
                    ++v5;
                  }
                  while ( v4 < this->m_PatchWorkerIPs.m_Size );
                  v3 = v46;
                }
              }
              else
              {
                this->m_pSocket->Broadcast(this: this->m_pSocket, a2: buf.m_pData, a3: (buf.m_iCurBit + 7) >> 3, a4: v3);
              }
              v46 = ++v3;
            }
            while ( v3 <= 23412 );
            this->m_PatchWorkerIPs.m_Size = 0;
            if ( this->m_PatchWorkerIPs.m_Memory.m_nGrowSize >= 0 )
            {
              if ( this->m_PatchWorkerIPs.m_Memory.m_pMemory != nullptr )
              {
                _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)this->m_PatchWorkerIPs.m_Memory.m_pMemory);
                this->m_PatchWorkerIPs.m_Memory.m_pMemory = nullptr;
              }
              this->m_PatchWorkerIPs.m_Memory.m_nAllocationCount = 0;
            }
            v6 = v44;
            this->m_PatchWorkerIPs.m_pElements = this->m_PatchWorkerIPs.m_Memory.m_pMemory;
            this->m_LastSendTime = v6;
          }
        }
        m_pListenSocket = this->m_pListenSocket;
        v45 = nullptr;
        v8 = m_pListenSocket->Update(this: m_pListenSocket, a2: &v45, a3: 0);
        v9 = v45;
        if ( !v8 || v45 == nullptr )
        {
          m_pDownloaderListenSocket = this->m_pDownloaderListenSocket;
          if ( m_pDownloaderListenSocket != nullptr && nServiceDownloaders < this->m_nMaxWorkers - nRegularWorkers + 8 )
          {
            v8 = m_pDownloaderListenSocket->Update(this: m_pDownloaderListenSocket, a2: &v45, a3: 0);
            v9 = v45;
          }
        }
        if ( !v8 || v9 == nullptr )
          break;
        v9->GetRemoteAddr(this: v9, result: (CIPAddr *)&v29);
        if ( (unsigned __int16)(v30 - 22351) <= 9u )
        {
          v11 = v45;
          CCriticalSectionLock::CCriticalSectionLock(this: &v33, pCS: &g_ConnectionsCS);
          v12 = 0;
          if ( g_nConnections <= 0 )
          {
LABEL_33:
            CCriticalSectionLock::~CCriticalSectionLock(this: &v33);
          }
          else
          {
            while ( 1 )
            {
              v13 = g_Connections[v12];
              if ( v13 != nullptr && v13->m_pSocket == v11 )
                break;
              if ( ++v12 >= g_nConnections )
                goto LABEL_33;
            }
            v14 = g_Connections[v12];
            CCriticalSectionLock::~CCriticalSectionLock(this: &v33);
            if ( v14 != nullptr )
              v14->m_bIsAService = true;
          }
        }
        CCriticalSectionLock::CCriticalSectionLock(this: &v32, pCS: &g_PersistentPacketsCS);
        CCriticalSectionLock::Lock(this: &v32);
        GetHandler = v45->GetHandler;
        v46 = 1;
        v16 = (int *)GetHandler(this: v45);
        LOWORD(m_Next) = g_PersistentPackets.m_Head;
        v44 = (int)v16;
        if ( g_PersistentPackets.m_Head != 0xFFFF )
        {
          m_pMemory = g_PersistentPackets.m_Memory.m_pMemory;
          while ( 1 )
          {
            v19 = (unsigned __int16)m_Next;
            m_Element = m_pMemory[v19].m_Element;
            m_Size = (unsigned __int8 *)m_Element->m_Size;
            v34 = m_Element->m_Memory.m_pMemory;
            v22 = *v16;
            v36 = (int)m_Size;
            v23 = (*(int (__thiscall **)(int *))(v22 + 16))(a1: v16);
            pChunkLengths = v36;
            pChunks = v34;
            VMPI_SendChunks((const void *const *)&pChunks, &pChunkLengths, nChunks: 1, iDest: v23, fVMPISendFlags: 0);
            if ( g_bSuperSpewEnabled )
            {
              if ( m_Element->m_Size <= 2 )
              {
                VMPI_SuperSpew(pMsg: "Sending a really short persistent packet (%d bytes).\n", m_Element->m_Size);
              }
              else
              {
                CVMPIPacketIDReg::Lookup(
                  nPacketID: *(unsigned __int8 *)m_Element->m_Memory.m_pMemory,
                  nSubPacketID: *((unsigned __int8 *)m_Element->m_Memory.m_pMemory + 1),
                  pPacketIDString,
                  nPacketIDStringSize: 64,
                  pSubPacketIDString,
                  nSubPacketIDStringSize: 64);
                v24 = v46;
                VMPI_SuperSpew(
                  pMsg: "Sending persistent packet %d. PacketID: %s, SubPacketID: %s.\n",
                  v46,
                  pPacketIDString,
                  pSubPacketIDString);
                v46 = v24 + 1;
              }
            }
            m_pMemory = g_PersistentPackets.m_Memory.m_pMemory;
            m_Next = g_PersistentPackets.m_Memory.m_pMemory[v19].m_Next;
            if ( m_Next == 0xFFFF )
              break;
            v16 = (int *)v44;
          }
        }
        UpdateActiveConnectionsText();
        CCriticalSectionLock::~CCriticalSectionLock(this: &v32);
        CCriticalSectionLock::~CCriticalSectionLock(this: &v40);
        if ( GetTickCount() - startTime >= 0x1F4 )
          goto LABEL_47;
      }
      CCriticalSectionLock::~CCriticalSectionLock(this: &v40);
LABEL_47:
      v25 = CTCPPacket::GetUserData(this: &this->m_hShutdownEvent);
    }
    while ( WaitForSingleObject(hHandle: v25, dwMilliseconds: 0x14u) == 258 );
  }
  CEvent::SetEvent(this: &this->m_hShutdownReply);
}

//------------------------------------------------------------------------------
// Address: 0x1000A720
// Name: private: static unsigned long CMasterBroadcaster::StaticThreadFn(void __near *)
// Source: json
//------------------------------------------------------------------------------
unsigned int __stdcall CMasterBroadcaster::StaticThreadFn(CMasterBroadcaster *lpParameter)
{
  CMasterBroadcaster::ThreadFn(this: lpParameter);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1000A740
// Name: void VMPI_HandleTimingWait_Master(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl VMPI_HandleTimingWait_Master()
{
  int v0; // eax
  void *pChunks; // [esp+0h] [ebp-Ch] BYREF
  int pChunkLengths; // [esp+4h] [ebp-8h] BYREF
  unsigned __int8 cPacket[2]; // [esp+8h] [ebp-4h] BYREF

  v0 = _CommandLine();
  if ( (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v0 + 40))(a1: v0, a2: g_VMPIParams[9].m_pName) != 0 )
  {
    _Msg(a1: "-mpi_TimingWait specified. Waiting for a keypress to continue... ");
    getch();
    _Msg(a1: "\n");
    *(_WORD *)cPacket = 1307;
    pChunkLengths = 2;
    pChunks = cPacket;
    VMPI_SendChunks((const void *const *)&pChunks, &pChunkLengths, nChunks: 1, iDest: -3, fVMPISendFlags: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000A7B0
// Name: bool MPI_Init_Worker(int __near &,char __near * __near * __near &,class CIPAddr const __near &,bool)
// Source: json
//------------------------------------------------------------------------------
char __cdecl MPI_Init_Worker(
        int *argc,
        char ***argv,
        const CIPAddr *masterAddr,
        IThreadedTCPSocket *bConnectingAsService)
{
  int v4; // edi
  ITCPConnectSocket *v5; // esi
  const CIPAddr *v6; // eax
  void (*v7)(const char *, ...); // edi
  bool (__thiscall *Update)(ITCPConnectSocket *, IThreadedTCPSocket **, unsigned int); // edx
  void (__thiscall ***v9)(_DWORD, int, char **); // eax
  int i; // esi
  int v11; // eax
  int v13; // eax
  int v14; // esi
  int flSeconds; // [esp+0h] [ebp-34h]
  CWaitTimer wait; // [esp+14h] [ebp-20h] BYREF
  CIPAddr v17; // [esp+1Eh] [ebp-16h] BYREF
  CVMPIConnectionCreator connectionCreator; // [esp+24h] [ebp-10h] BYREF
  int nAttempts; // [esp+28h] [ebp-Ch]
  int iFirstPort; // [esp+2Ch] [ebp-8h]
  int iLastPort; // [esp+30h] [ebp-4h]

  v4 = 22340;
  g_bMPIMaster = false;
  connectionCreator.__vftable = (CVMPIConnectionCreator_vtbl *)&CVMPIConnectionCreator::`vftable';
  iFirstPort = 22340;
  iLastPort = 22350;
  if ( (_BYTE)bConnectingAsService != 0 )
  {
    iFirstPort = 22351;
    v4 = 22351;
    iLastPort = 22360;
  }
  nAttempts = 1;
  while ( 2 )
  {
    v5 = nullptr;
    if ( v4 > iLastPort )
    {
LABEL_8:
      flSeconds = v4;
      v7 = (void (*)(const char *, ...))_Error;
      _Error(a1: "Can't bind a port in range [%d, %d].", flSeconds, iLastPort);
    }
    else
    {
      while ( 1 )
      {
        v6 = CIPAddr::CIPAddr(this: &v17, ip0: 0, ip1: 0, ip2: 0, ip3: 0, ipPort: v4);
        v5 = ThreadedTCP_CreateConnector(addr: masterAddr, localAddr: v6, pHandlerCreator: &connectionCreator);
        if ( v5 != nullptr )
          break;
        if ( ++v4 > iLastPort )
        {
          v4 = iFirstPort;
          goto LABEL_8;
        }
      }
      v7 = (void (*)(const char *, ...))_Error;
    }
    CWaitTimer::CWaitTimer(this: &wait, flSeconds: 3.0);
    while ( 1 )
    {
      Update = v5->Update;
      bConnectingAsService = nullptr;
      if ( Update(this: v5, a2: &bConnectingAsService, a3: 100u) )
      {
        if ( bConnectingAsService != nullptr )
        {
          VMPI_SendMachineNameTo(iProc: 0);
          VMPI_ReceiveExeName();
          if ( g_bVMPISDKMode )
          {
            VMPI_ReceiveCommandLine();
            v9 = (void (__thiscall ***)(_DWORD, int, char **))_CommandLine();
            (**v9)(a1: v9, a2: g_WorkerCommandLine.m_Size, a3: g_WorkerCommandLine.m_Memory.m_pMemory);
            *argc = g_WorkerCommandLine.m_Size;
            *argv = g_WorkerCommandLine.m_Memory.m_pMemory;
          }
          ParseOptions(argc: g_WorkerCommandLine.m_Size, argv: g_WorkerCommandLine.m_Memory.m_pMemory);
          for ( i = 0; i < g_WorkerCommandLine.m_Size; ++i )
            _Msg(a1: "arg %d: %s\n", i, g_WorkerCommandLine.m_Memory.m_pMemory[i]);
          v11 = _CommandLine();
          if ( (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v11 + 40))(a1: v11, a2: g_VMPIParams[9].m_pName) != 0 )
          {
            _Msg(a1: "-mpi_TimingWait specified. Waiting for master to start...");
            while ( !g_bTimingWaitDone )
              VMPI_DispatchNextMessage(timeout: (CTCPPacket *)0x32);
            _Msg(a1: "\n ");
          }
          return 1;
        }
      }
      else
      {
        v5->Release(this: v5);
        v7(a1: "ITCPConnectSocket::Update() errored out");
      }
      if ( !CWaitTimer::ShouldKeepWaiting(this: &wait) )
        break;
      Sleep(dwMilliseconds: 0x64u);
    }
    v5->Release(this: v5);
    v13 = _CommandLine();
    if ( (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v13 + 40))(a1: v13, a2: g_VMPIParams[5].m_pName) != 0 )
    {
      v14 = nAttempts;
      _Msg(
        a1: "%s found. Retrying connection to %d.%d.%d.%d:%d (attempt %d).\n",
        g_VMPIParams[5].m_pName,
        masterAddr->ip[0],
        masterAddr->ip[1],
        masterAddr->ip[2],
        masterAddr->ip[3],
        masterAddr->port,
        nAttempts);
      v4 = iFirstPort;
      nAttempts = v14 + 1;
      continue;
    }
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000AA10
// Name: public: bool CMasterBroadcaster::Init(int,char __near * __near *,char const __near *,int,enum VMPIRunMode,bool)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CMasterBroadcaster::Init(
        CMasterBroadcaster *this,
        int argc,
        char **argv,
        char *pDependencyFilename,
        int nMaxWorkers,
        VMPIRunMode runMode,
        bool bPatchMode)
{
  VMPIRunMode v7; // eax
  char *Arg; // eax
  int v10; // eax
  int v11; // esi
  ITCPConnectSocket *Listener; // eax
  int j; // esi
  ITCPConnectSocket *v14; // eax
  bool v15; // zf
  ISocket *IPSocket; // eax
  int v17; // esi
  char *v18; // esi
  long double v19; // st7
  int v20; // esi
  char *v21; // eax
  bool v22; // sf
  unsigned int v23; // edi
  int m_Size; // edi
  int m_nAllocationCount; // eax
  char **m_pMemory; // ecx
  int v27; // eax
  char **v28; // edi
  unsigned int v29; // edi
  int v30; // eax
  int v31; // ecx
  char **v32; // eax
  int v33; // ecx
  char **v34; // eax
  int v35; // eax
  int v36; // ecx
  char **v37; // eax
  int v38; // ecx
  unsigned int v39; // edi
  int v40; // eax
  int v41; // ecx
  char **v42; // eax
  int v43; // ecx
  int v44; // eax
  int v45; // ecx
  char **v46; // eax
  int v47; // ecx
  unsigned int v48; // edi
  int v49; // eax
  int v50; // ecx
  char **v51; // eax
  int v52; // ecx
  HANDLE Thread; // eax
  CDependencyInfo::CDependencyFile **v54; // eax
  char *v56; // esi
  CDependencyInfo::CDependencyFile **v57; // eax
  unsigned __int16 m_iListenPort; // [esp-Ch] [ebp-23Ch]
  unsigned __int64 v59; // [esp-8h] [ebp-238h]
  unsigned __int64 v60; // [esp-8h] [ebp-238h]
  CDependencyInfo dependencyInfo; // [esp+Ch] [ebp-224h] BYREF
  CCycleCount cnt; // [esp+228h] [ebp-8h]
  char *pDependencyFilenamea; // [esp+240h] [ebp+10h]
  CDependencyInfo::CDependencyFile *pDependencyFilenameb; // [esp+240h] [ebp+10h]
  float id; // [esp+244h] [ebp+14h]
  int i; // [esp+244h] [ebp+14h]
  char *ia; // [esp+244h] [ebp+14h]
  int ib; // [esp+244h] [ebp+14h]
  char *ic; // [esp+244h] [ebp+14h]

  v7 = runMode;
  this->m_RunMode = runMode;
  this->m_nMaxWorkers = nMaxWorkers;
  memset(&dependencyInfo.m_Files, 0, sizeof(dependencyInfo.m_Files));
  if ( v7 == VMPI_RUN_NETWORKED && !g_bVMPISDKMode )
    SetupDependencyInfo(pInfo: &dependencyInfo, pDependencyFilename, bPatchMode);
  this->m_pListenSocket = nullptr;
  this->m_pDownloaderListenSocket = nullptr;
  Arg = VMPI_FindArg(argc, argv, pName: g_VMPIParams[3].m_pName, pDefault: setName);
  if ( Arg != nullptr )
  {
    v10 = atoi(nptr: Arg);
    this->m_iListenPort = v10;
    m_iListenPort = this->m_iListenPort;
    this->m_iDownloaderListenPort = v10 + 1;
    this->m_pListenSocket = ThreadedTCP_CreateListener(
                              pHandlerCreator: &this->m_ConnectionCreator,
                              port: m_iListenPort,
                              nQueueLength: 5);
    if ( !g_bVMPISDKMode )
      this->m_pDownloaderListenSocket = ThreadedTCP_CreateListener(
                                          pHandlerCreator: &this->m_ConnectionCreator,
                                          port: this->m_iDownloaderListenPort,
                                          nQueueLength: 5);
  }
  else
  {
    cnt.m_Int64 = __rdtsc();
    HIDWORD(v59) = HIDWORD(_g_ClockSpeed);
    LODWORD(v59) = _g_ClockSpeed;
    srand(seed: 1000000 * cnt.m_Int64 / v59);
    v11 = 23311;
    while ( 1 )
    {
      this->m_iListenPort = v11;
      Listener = ThreadedTCP_CreateListener(pHandlerCreator: &this->m_ConnectionCreator, port: v11, nQueueLength: 5);
      this->m_pListenSocket = Listener;
      if ( Listener != nullptr )
        break;
      if ( ++v11 > 23330 )
        goto LABEL_16;
    }
    if ( !g_bVMPISDKMode )
    {
      for ( j = this->m_iListenPort + 1; j <= 23330; ++j )
      {
        this->m_iDownloaderListenPort = j;
        if ( j != this->m_iListenPort )
        {
          v14 = ThreadedTCP_CreateListener(pHandlerCreator: &this->m_ConnectionCreator, port: j, nQueueLength: 5);
          this->m_pDownloaderListenSocket = v14;
          if ( v14 != nullptr )
            break;
        }
      }
    }
  }
LABEL_16:
  if ( this->m_pListenSocket == nullptr || !g_bVMPISDKMode && this->m_pDownloaderListenSocket == nullptr )
    _Error(a1: "Can't bind a listen socket in port range [%d, %d].", 21140, 21145);
  v15 = this->m_RunMode == VMPI_RUN_NETWORKED;
  this->m_bPatching = false;
  if ( v15 && !g_bVMPISDKMode )
  {
    IPSocket = CreateIPSocket();
    this->m_pSocket = IPSocket;
    if ( !IPSocket->BindToAny(this: IPSocket, a2: 0) )
      _Error(a1: "MPI_Init_Master: can't bind a socket");
    if ( bPatchMode )
    {
      v17 = 0;
      this->m_bPatching = true;
      if ( argc <= 0 )
      {
LABEL_28:
        v18 = nullptr;
      }
      else
      {
        while ( _V_stricmp(s1: argv[v17], s2: "-mpi_PatchVersion") != 0 )
        {
          if ( ++v17 >= argc )
            goto LABEL_28;
        }
        if ( v17 + 1 >= argc )
          v18 = "0";
        else
          v18 = argv[v17 + 1];
      }
      v19 = atof(nptr: v18);
      if ( v19 <= 0.0 || (id = v19) >= 32767.0 )
        _Error(a1: "-mpi_PatchVersion <val> -  val must be between 1.0 and 32767.0");
      V_strncpy(pDest: this->m_BroadcastInfo.m_PatchVersion, pSrc: v18, maxLen: 32);
    }
    else
    {
      this->m_BroadcastInfo.m_PatchVersion[0] = 0;
    }
    Sleep(dwMilliseconds: 1u);
    cnt.m_Int64 = __rdtsc();
    HIDWORD(v60) = HIDWORD(_g_ClockSpeed);
    LODWORD(v60) = _g_ClockSpeed;
    this->m_BroadcastInfo.m_JobID[0] = 1000000 * cnt.m_Int64 / v60;
    Sleep(dwMilliseconds: 1u);
    cnt.m_Int64 = __rdtsc();
    HIDWORD(v60) = HIDWORD(_g_ClockSpeed);
    LODWORD(v60) = _g_ClockSpeed;
    this->m_BroadcastInfo.m_JobID[1] = 1000000 * cnt.m_Int64 / v60;
    Sleep(dwMilliseconds: 1u);
    cnt.m_Int64 = __rdtsc();
    HIDWORD(v60) = HIDWORD(_g_ClockSpeed);
    LODWORD(v60) = _g_ClockSpeed;
    this->m_BroadcastInfo.m_JobID[2] = 1000000 * cnt.m_Int64 / v60;
    Sleep(dwMilliseconds: 1u);
    cnt.m_Int64 = __rdtsc();
    HIDWORD(v60) = HIDWORD(_g_ClockSpeed);
    LODWORD(v60) = _g_ClockSpeed;
    v20 = 0;
    this->m_BroadcastInfo.m_JobID[3] = 1000000 * cnt.m_Int64 / v60;
    if ( argc <= 0 )
      goto LABEL_40;
    while ( _V_stricmp(s1: argv[v20], s2: "-mpi_pw") != 0 )
    {
      if ( ++v20 >= argc )
        goto LABEL_40;
    }
    if ( v20 + 1 >= argc )
    {
      v21 = (char *)setName;
      goto LABEL_41;
    }
    v56 = argv[v20 + 1];
    if ( v56 != nullptr )
      v21 = v56;
    else
LABEL_40:
      v21 = (char *)setName;
LABEL_41:
    V_strncpy(pDest: this->m_BroadcastInfo.m_Password, pSrc: v21, maxLen: 256);
    V_strncpy(pDest: this->m_BroadcastInfo.m_WorkerExeFilename, pSrc: dependencyInfo.m_OriginalExeFilename, maxLen: 260);
    v22 = this->m_BroadcastInfo.m_Args.m_Memory.m_nGrowSize < 0;
    this->m_BroadcastInfo.m_Args.m_Size = 0;
    if ( !v22 )
    {
      if ( this->m_BroadcastInfo.m_Args.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_BroadcastInfo.m_Args.m_Memory.m_pMemory);
        this->m_BroadcastInfo.m_Args.m_Memory.m_pMemory = nullptr;
      }
      this->m_BroadcastInfo.m_Args.m_Memory.m_nAllocationCount = 0;
    }
    this->m_BroadcastInfo.m_Args.m_pElements = this->m_BroadcastInfo.m_Args.m_Memory.m_pMemory;
    for ( i = 1; i < argc; ++i )
    {
      pDependencyFilenamea = argv[i];
      v23 = _V_strlen(str: pDependencyFilenamea) + 1;
      HIDWORD(cnt.m_Int64) = operator new(nSize: v23);
      V_strncpy(pDest: (char *)HIDWORD(cnt.m_Int64), pSrc: pDependencyFilenamea, maxLen: v23);
      m_Size = this->m_BroadcastInfo.m_Args.m_Size;
      m_nAllocationCount = this->m_BroadcastInfo.m_Args.m_Memory.m_nAllocationCount;
      if ( m_Size + 1 > m_nAllocationCount )
        CUtlMemory<int,int>::Grow(
          this: (CUtlMemory<CTCPPacket *,int> *)&this->m_BroadcastInfo.m_Args,
          num: m_Size - m_nAllocationCount + 1);
      ++this->m_BroadcastInfo.m_Args.m_Size;
      m_pMemory = this->m_BroadcastInfo.m_Args.m_Memory.m_pMemory;
      v27 = this->m_BroadcastInfo.m_Args.m_Size - m_Size - 1;
      this->m_BroadcastInfo.m_Args.m_pElements = m_pMemory;
      if ( v27 > 0 )
        _V_memmove(
          dest: (unsigned __int8 *)&m_pMemory[m_Size + 1],
          src: (unsigned __int8 *)&m_pMemory[m_Size],
          count: 4 * v27);
      v28 = &this->m_BroadcastInfo.m_Args.m_Memory.m_pMemory[m_Size];
      if ( v28 != nullptr )
        *v28 = (char *)HIDWORD(cnt.m_Int64);
    }
    v29 = _V_strlen(str: this->m_BroadcastInfo.m_WorkerExeFilename) + 1;
    ia = (char *)operator new(nSize: v29);
    V_strncpy(pDest: ia, pSrc: this->m_BroadcastInfo.m_WorkerExeFilename, maxLen: v29);
    v30 = this->m_BroadcastInfo.m_Args.m_Size;
    v31 = this->m_BroadcastInfo.m_Args.m_Memory.m_nAllocationCount;
    if ( v30 + 1 > v31 )
      CUtlMemory<int,int>::Grow(this: (CUtlMemory<CTCPPacket *,int> *)&this->m_BroadcastInfo.m_Args, num: v30 - v31 + 1);
    ++this->m_BroadcastInfo.m_Args.m_Size;
    v32 = this->m_BroadcastInfo.m_Args.m_Memory.m_pMemory;
    v33 = this->m_BroadcastInfo.m_Args.m_Size - 1;
    this->m_BroadcastInfo.m_Args.m_pElements = v32;
    if ( v33 > 0 )
      _V_memmove(dest: (unsigned __int8 *)v32 + 4, src: (unsigned __int8 *)v32, count: 4 * v33);
    v34 = this->m_BroadcastInfo.m_Args.m_Memory.m_pMemory;
    if ( v34 != nullptr )
      *v34 = ia;
    for ( ib = 0; ib < dependencyInfo.m_Files.m_Size; ++ib )
    {
      v35 = this->m_BroadcastInfo.m_Args.m_Size;
      v36 = this->m_BroadcastInfo.m_Args.m_Memory.m_nAllocationCount;
      if ( v35 + 1 > v36 )
        CUtlMemory<int,int>::Grow(
          this: (CUtlMemory<CTCPPacket *,int> *)&this->m_BroadcastInfo.m_Args,
          num: v35 - v36 + 1);
      ++this->m_BroadcastInfo.m_Args.m_Size;
      v37 = this->m_BroadcastInfo.m_Args.m_Memory.m_pMemory;
      v38 = this->m_BroadcastInfo.m_Args.m_Size - 2;
      this->m_BroadcastInfo.m_Args.m_pElements = v37;
      if ( v38 > 0 )
        _V_memmove(dest: (unsigned __int8 *)v37 + 8, src: (unsigned __int8 *)v37 + 4, count: 4 * v38);
      if ( this->m_BroadcastInfo.m_Args.m_Memory.m_pMemory != (char **)-4 )
        *((_DWORD *)this->m_BroadcastInfo.m_Args.m_Memory.m_pMemory + 1) = "-mpi_file";
      pDependencyFilenameb = dependencyInfo.m_Files.m_Memory.m_pMemory[ib];
      v39 = _V_strlen(str: pDependencyFilenameb->m_Name) + 1;
      HIDWORD(cnt.m_Int64) = operator new(nSize: v39);
      V_strncpy(pDest: (char *)HIDWORD(cnt.m_Int64), pSrc: pDependencyFilenameb->m_Name, maxLen: v39);
      v40 = this->m_BroadcastInfo.m_Args.m_Size;
      v41 = this->m_BroadcastInfo.m_Args.m_Memory.m_nAllocationCount;
      if ( v40 + 1 > v41 )
        CUtlMemory<int,int>::Grow(
          this: (CUtlMemory<CTCPPacket *,int> *)&this->m_BroadcastInfo.m_Args,
          num: v40 - v41 + 1);
      ++this->m_BroadcastInfo.m_Args.m_Size;
      v42 = this->m_BroadcastInfo.m_Args.m_Memory.m_pMemory;
      v43 = this->m_BroadcastInfo.m_Args.m_Size - 3;
      this->m_BroadcastInfo.m_Args.m_pElements = v42;
      if ( v43 > 0 )
        _V_memmove(dest: (unsigned __int8 *)v42 + 12, src: (unsigned __int8 *)v42 + 8, count: 4 * v43);
      if ( this->m_BroadcastInfo.m_Args.m_Memory.m_pMemory != (char **)-8 )
        *((_DWORD *)this->m_BroadcastInfo.m_Args.m_Memory.m_pMemory + 2) = HIDWORD(cnt.m_Int64);
    }
    v44 = this->m_BroadcastInfo.m_Args.m_Size;
    v45 = this->m_BroadcastInfo.m_Args.m_Memory.m_nAllocationCount;
    if ( v44 + 1 > v45 )
      CUtlMemory<int,int>::Grow(this: (CUtlMemory<CTCPPacket *,int> *)&this->m_BroadcastInfo.m_Args, num: v44 - v45 + 1);
    ++this->m_BroadcastInfo.m_Args.m_Size;
    v46 = this->m_BroadcastInfo.m_Args.m_Memory.m_pMemory;
    v47 = this->m_BroadcastInfo.m_Args.m_Size - 2;
    this->m_BroadcastInfo.m_Args.m_pElements = v46;
    if ( v47 > 0 )
      _V_memmove(dest: (unsigned __int8 *)v46 + 8, src: (unsigned __int8 *)v46 + 4, count: 4 * v47);
    if ( this->m_BroadcastInfo.m_Args.m_Memory.m_pMemory != (char **)-4 )
      *((_DWORD *)this->m_BroadcastInfo.m_Args.m_Memory.m_pMemory + 1) = "-mpi_filebase";
    v48 = _V_strlen(str: dependencyInfo.m_DependencyFilesDir) + 1;
    ic = (char *)operator new(nSize: v48);
    V_strncpy(pDest: ic, pSrc: dependencyInfo.m_DependencyFilesDir, maxLen: v48);
    v49 = this->m_BroadcastInfo.m_Args.m_Size;
    v50 = this->m_BroadcastInfo.m_Args.m_Memory.m_nAllocationCount;
    if ( v49 + 1 > v50 )
      CUtlMemory<int,int>::Grow(this: (CUtlMemory<CTCPPacket *,int> *)&this->m_BroadcastInfo.m_Args, num: v49 - v50 + 1);
    ++this->m_BroadcastInfo.m_Args.m_Size;
    v51 = this->m_BroadcastInfo.m_Args.m_Memory.m_pMemory;
    v52 = this->m_BroadcastInfo.m_Args.m_Size - 3;
    this->m_BroadcastInfo.m_Args.m_pElements = v51;
    if ( v52 > 0 )
      _V_memmove(dest: (unsigned __int8 *)v51 + 12, src: (unsigned __int8 *)v51 + 8, count: 4 * v52);
    if ( this->m_BroadcastInfo.m_Args.m_Memory.m_pMemory != (char **)-8 )
      *((_DWORD *)this->m_BroadcastInfo.m_Args.m_Memory.m_pMemory + 2) = ic;
    if ( bPatchMode )
      CMasterBroadcaster::GetPatchWorkerList(this, argc, argv);
  }
  this->m_ConnectionCreator.CreateNewHandler(this: &this->m_ConnectionCreator);
  this->m_LastSendTime = _Plat_MSTime() - 1200;
  CEvent::Init(this: &this->m_hShutdownEvent, bManualReset: false, bInitialState: false);
  CEvent::Init(this: &this->m_hShutdownReply, bManualReset: false, bInitialState: false);
  runMode = VMPI_RUN_NETWORKED;
  Thread = CreateThread(
             lpThreadAttributes: nullptr,
             dwStackSize: 0,
             lpStartAddress: (LPTHREAD_START_ROUTINE)CMasterBroadcaster::StaticThreadFn,
             lpParameter: this,
             dwCreationFlags: 0,
             lpThreadId: (LPDWORD)&runMode);
  this->m_hThread = Thread;
  if ( Thread != nullptr )
  {
    SetThreadPriority(hThread: Thread, nPriority: 2);
    v54 = dependencyInfo.m_Files.m_Memory.m_pMemory;
    dependencyInfo.m_Files.m_Size = 0;
    if ( dependencyInfo.m_Files.m_Memory.m_nGrowSize >= 0 )
    {
      if ( dependencyInfo.m_Files.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: dependencyInfo.m_Files.m_Memory.m_pMemory);
        v54 = nullptr;
        dependencyInfo.m_Files.m_Memory.m_pMemory = nullptr;
      }
      dependencyInfo.m_Files.m_Memory.m_nAllocationCount = 0;
    }
    dependencyInfo.m_Files.m_pElements = v54;
    if ( dependencyInfo.m_Files.m_Memory.m_nGrowSize >= 0 && v54 != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v54);
    return 1;
  }
  else
  {
    v57 = dependencyInfo.m_Files.m_Memory.m_pMemory;
    dependencyInfo.m_Files.m_Size = 0;
    if ( dependencyInfo.m_Files.m_Memory.m_nGrowSize >= 0 )
    {
      if ( dependencyInfo.m_Files.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: dependencyInfo.m_Files.m_Memory.m_pMemory);
        v57 = nullptr;
        dependencyInfo.m_Files.m_Memory.m_pMemory = nullptr;
      }
      dependencyInfo.m_Files.m_Memory.m_nAllocationCount = 0;
    }
    dependencyInfo.m_Files.m_pElements = v57;
    if ( dependencyInfo.m_Files.m_Memory.m_nGrowSize >= 0 && v57 != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v57);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000B330
// Name: bool InitMaster(int,char __near * __near *,char const __near *,enum VMPIRunMode,bool)
// Source: json
//------------------------------------------------------------------------------
char __cdecl InitMaster(int argc, char **argv, char *pDependencyFilename, VMPIRunMode runMode, bool bPatchMode)
{
  char *Arg; // eax
  int v6; // ebx
  bool v7; // al
  char result; // al
  char v9; // bl

  Arg = VMPI_FindArg(argc, argv, pName: g_VMPIParams[10].m_pName, pDefault: setName);
  if ( Arg != nullptr )
  {
    v6 = atoi(nptr: Arg);
    _Warning(a1: "%s: waiting for %d processes to join.\n", g_VMPIParams[10].m_pName, v6);
    if ( v6 >= 2 )
    {
      if ( v6 > 512 )
        v6 = 512;
    }
    else
    {
      v6 = 2;
    }
  }
  else
  {
    v6 = 32;
  }
  g_bMPIMaster = true;
  g_nMaxWorkerCount = v6;
  if ( argc <= 0 )
    _Error(a1: "MPI_Init_Master: argc <= 0!");
  ParseOptions(argc, argv);
  VMPI_SendExeName();
  if ( g_bVMPISDKModeSet )
    v7 = g_bVMPISDKMode;
  else
    v7 = !VMPI_CheckForNonSDKExecutables();
  if ( v7 )
    VMPI_SendCommandLine(argc, argv);
  result = CMasterBroadcaster::Init(
             this: &g_MasterBroadcaster,
             argc,
             argv,
             pDependencyFilename,
             nMaxWorkers: v6,
             runMode,
             bPatchMode);
  if ( result != 0 )
  {
    if ( runMode == VMPI_RUN_LOCAL )
    {
      v9 = SpawnLocalWorker(argc, argv, iListenPort: g_MasterBroadcaster.m_iListenPort, bShowConsoleWindow: false);
      VMPI_HandleTimingWait_Master();
      return v9;
    }
    else
    {
      if ( VMPI_FindArg(argc, argv, pName: g_VMPIParams[11].m_pName, pDefault: setName) != nullptr )
      {
        _Msg(a1: "%s found. Spawning a local worker automatically.\n", g_VMPIParams[11].m_pName);
        SpawnLocalWorker(argc: 1, argv, iListenPort: g_MasterBroadcaster.m_iListenPort, bShowConsoleWindow: true);
      }
      VMPI_HandleTimingWait_Master();
      return 1;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1000B480
// Name: bool VMPI_Init(int __near &,char __near * __near * __near &,char const __near *,void (*)(int,char const __near *),enum VMPIRunMode,bool)
// Source: json
//------------------------------------------------------------------------------
char __cdecl VMPI_Init(
        int *argc,
        char ***argv,
        char *pDependencyFilename,
        void (__cdecl *handler)(int, const char *),
        VMPIRunMode runMode,
        IThreadedTCPSocket *bConnectingAsService)
{
  HMODULE LibraryA; // eax
  char *Arg; // ebx
  CIPAddr addr; // [esp+0h] [ebp-8h] BYREF

  if ( VMPI_IsLogFileEnabled() )
    _LoggingSystem_RegisterLoggingListener(a1: &g_VMPILoggingListener);
  if ( handler != nullptr )
    CUtlLinkedList<void (__cdecl *)(int,char const *),int,0,int,CUtlMemory<UtlLinkedListElem_t<void (__cdecl *)(int,char const *),int>,int>>::AddToTail(
      this: &g_DisconnectHandlers,
      src: &handler);
  VMPI_SetupAutoRestartParameters(argc: *argc, argv: *argv);
  VMPI_CheckSDKMode(argc: *argc, argv: *argv);
  g_bUseMPI = true;
  g_VMPIRunMode = runMode;
  CEvent::Init(this: &g_VMPIMessagesEvent, bManualReset: false, bInitialState: false);
  CEvent::Init(this: &g_ErrorSocketsEvent, bManualReset: false, bInitialState: false);
  LibraryA = LoadLibraryA(lpLibFileName: "kernel32.dll");
  g_hKernel32DLL = LibraryA;
  if ( LibraryA != nullptr )
    g_pConsoleWndFn = (HWND__ *(__cdecl *)())GetProcAddress(hModule: LibraryA, lpProcName: "GetConsoleWindow");
  Arg = VMPI_FindArg(argc: *argc, argv: *argv, pName: g_VMPIParams[2].m_pName, pDefault: nullptr);
  if ( Arg != nullptr )
  {
    CIPAddr::CIPAddr(this: &addr);
    addr.port = 23311;
    if ( !ConvertStringToIPAddr(pStr: Arg, pOut: &addr) )
      _Error(a1: "Unable to parse or resolve master IP (%s).\n", Arg);
    return MPI_Init_Worker(argc, argv, masterAddr: &addr, bConnectingAsService);
  }
  else if ( pDependencyFilename != nullptr )
  {
    return InitMaster(argc: *argc, argv: *argv, pDependencyFilename, runMode, bPatchMode: false);
  }
  else
  {
    _Error(a1: "VMPI started as master, but no dependency filename specified.\n");
    return 0;
  }
}

} // namespace texturecompile_dll

// ============================================================
// Overlay from vrad_dll (Missing functions)
// ============================================================
namespace vrad_dll {

//------------------------------------------------------------------------------
// Address: 0x10083E10
// Name: public: CVMPIPacketIDReg::CVMPIPacketIDReg(int,int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CVMPIPacketIDReg *__thiscall CVMPIPacketIDReg::CVMPIPacketIDReg(
        CVMPIPacketIDReg *this,
        int nPacketID,
        int nSubPacketID,
        const char *pName)
{
  CVMPIPacketIDReg *v5; // edx

  this->m_nPacketID = nPacketID;
  this->m_nSubPacketID = nSubPacketID;
  v5 = g_pVMPIPacketIDRegHead;
  this->m_pName = pName;
  this->m_pNext = v5;
  g_pVMPIPacketIDRegHead = this;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10083E40
// Name: public: static void CVMPIPacketIDReg::Lookup(int,int,char __near *,int,char __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CVMPIPacketIDReg::Lookup(
        int nPacketID,
        int nSubPacketID,
        char *pPacketIDString,
        int nPacketIDStringSize,
        char *pSubPacketIDString,
        int nSubPacketIDStringSize)
{
  CVMPIPacketIDReg *v6; // eax
  CVMPIPacketIDReg *v7; // eax

  v6 = g_pVMPIPacketIDRegHead;
  if ( g_pVMPIPacketIDRegHead != nullptr )
  {
    while ( v6->m_nPacketID != nPacketID || v6->m_nSubPacketID != -1 )
    {
      v6 = v6->m_pNext;
      if ( v6 == nullptr )
        goto LABEL_5;
    }
    V_strncpy(pDest: pPacketIDString, pSrc: (char *)v6->m_pName, maxLen: nPacketIDStringSize);
  }
  else
  {
LABEL_5:
    V_snprintf(pDest: pPacketIDString, maxLen: nPacketIDStringSize, pFormat: "(%d)", nPacketID);
  }
  v7 = g_pVMPIPacketIDRegHead;
  if ( g_pVMPIPacketIDRegHead != nullptr )
  {
    while ( v7->m_nPacketID != nPacketID || v7->m_nSubPacketID != nSubPacketID )
    {
      v7 = v7->m_pNext;
      if ( v7 == nullptr )
        goto LABEL_10;
    }
    V_strncpy(pDest: pSubPacketIDString, pSrc: (char *)v7->m_pName, maxLen: nSubPacketIDStringSize);
  }
  else
  {
LABEL_10:
    V_snprintf(pDest: pSubPacketIDString, maxLen: nSubPacketIDStringSize, pFormat: "(%d)", nSubPacketID);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10083EE0
// Name: void VMPI_SuperSpew(char const __near *,...)
// Source: json
//------------------------------------------------------------------------------
void VMPI_SuperSpew(const char *pMsg, ...)
{
  char str[2048]; // [esp+0h] [ebp-800h] BYREF
  va_list params; // [esp+80Ch] [ebp+Ch] BYREF

  va_start(params, pMsg);
  if ( g_bSuperSpewEnabled )
  {
    V_vsnprintf(pDest: str, maxLen: 0x800u, pFormat: pMsg, params);
    _Msg(a1: "%s", str);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10083F30
// Name: public: virtual void CVMPILoggingListener::Log(struct LoggingContext_t const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVMPILoggingListener::Log(
        CVMPILoggingListener *this,
        const LoggingContext_t *pContext,
        const char *pMessage)
{
  VMPI_WriteToLogFile(pMsg: "%s", pMessage);
}

//------------------------------------------------------------------------------
// Address: 0x10083F50
// Name: char const __near * VMPI_FindArg(int,char __near * __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
char *__cdecl VMPI_FindArg(int argc, char **argv, const char *pName, const char *pDefault)
{
  int v4; // esi

  v4 = 0;
  if ( argc <= 0 )
    return nullptr;
  while ( _V_stricmp(s1: argv[v4], s2: pName) != 0 )
  {
    if ( ++v4 >= argc )
      return nullptr;
  }
  if ( v4 + 1 >= argc )
    return (char *)pDefault;
  else
    return argv[v4 + 1];
}

//------------------------------------------------------------------------------
// Address: 0x10083FA0
// Name: void SetupDependencyFilename(class CDependencyInfo __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SetupDependencyFilename(CDependencyInfo *pInfo, char *pPatchDirectory)
{
  HMODULE ModuleHandleA; // eax
  char *v3; // eax
  char baseExeFilename[512]; // [esp+0h] [ebp-200h] BYREF

  ModuleHandleA = GetModuleHandleA(lpModuleName: nullptr);
  if ( GetModuleFileNameA(hModule: ModuleHandleA, lpFilename: baseExeFilename, nSize: 0x200u) == 0 )
    _Error(a1: "GetModuleFileName failed.");
  if ( pPatchDirectory != nullptr )
  {
    V_strncpy(pDest: pInfo->m_DependencyFilesDir, pSrc: pPatchDirectory, maxLen: 260);
  }
  else
  {
    V_strncpy(pDest: pInfo->m_DependencyFilesDir, pSrc: baseExeFilename, maxLen: 260);
    V_StripLastDir(dirName: pInfo->m_DependencyFilesDir, maxlen: 0x104u);
  }
  v3 = (char *)V_UnqualifiedFileName(in: baseExeFilename);
  V_strncpy(pDest: pInfo->m_OriginalExeFilename, pSrc: v3, maxLen: 260);
}

//------------------------------------------------------------------------------
// Address: 0x10084040
// Name: public: void CMasterBroadcaster::Term(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMasterBroadcaster::Term(CMasterBroadcaster *this)
{
  ISocket *m_pSocket; // ecx
  ITCPConnectSocket *m_pDownloaderListenSocket; // ecx

  if ( this->m_hThread != nullptr )
  {
    CEvent::SetEvent(this: &this->m_hShutdownEvent);
    WaitForSingleObject(hHandle: this->m_hThread, dwMilliseconds: 0xFFFFFFFF);
    CloseHandle(hObject: this->m_hThread);
    this->m_hThread = nullptr;
  }
  m_pSocket = this->m_pSocket;
  if ( m_pSocket != nullptr )
  {
    m_pSocket->Release(this: m_pSocket);
    this->m_pSocket = nullptr;
  }
  if ( this->m_pListenSocket != nullptr )
  {
    this->m_pListenSocket->Release(this: this->m_pListenSocket);
    this->m_pListenSocket = nullptr;
  }
  m_pDownloaderListenSocket = this->m_pDownloaderListenSocket;
  if ( m_pDownloaderListenSocket != nullptr )
  {
    m_pDownloaderListenSocket->Release(this: m_pDownloaderListenSocket);
    this->m_pDownloaderListenSocket = nullptr;
  }
  this->m_iDownloaderListenPort = -1;
  this->m_iListenPort = -1;
}

//------------------------------------------------------------------------------
// Address: 0x100840D0
// Name: public: CDispatchReg::CDispatchReg(int,bool (*)(class MessageBuffer __near *,int,int))
// Source: json
//------------------------------------------------------------------------------
CDispatchReg *__thiscall CDispatchReg::CDispatchReg(
        CDispatchReg *this,
        int iPacketID,
        bool (__cdecl *fn)(MessageBuffer *, int, int))
{
  g_VMPIDispatch[iPacketID] = fn;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100840F0
// Name: bool VMPI_CheckForNonSDKExecutables(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl VMPI_CheckForNonSDKExecutables()
{
  HMODULE ModuleHandleA; // eax
  char baseExeFilename[512]; // [esp+0h] [ebp-200h] BYREF

  ModuleHandleA = GetModuleHandleA(lpModuleName: nullptr);
  if ( GetModuleFileNameA(hModule: ModuleHandleA, lpFilename: baseExeFilename, nSize: 0x200u) == 0 )
    _Error(a1: "VMPI_CheckSDKMode -> GetModuleFileName failed.");
  V_StripLastDir(dirName: baseExeFilename, maxlen: 0x200u);
  V_AppendSlash(pStr: baseExeFilename, strSize: 512);
  V_strncat(pDest: baseExeFilename, pSrc: "mysql_wrapper.dll", destBufferSize: 0x200u, max_chars_to_copy: -1);
  return access(path: baseExeFilename, amode: 0) == 0;
}

//------------------------------------------------------------------------------
// Address: 0x10084180
// Name: enum VMPIRunMode VMPI_GetRunMode(void)
// Source: json
//------------------------------------------------------------------------------
VMPIRunMode __cdecl VMPI_GetRunMode()
{
  return g_VMPIRunMode;
}

//------------------------------------------------------------------------------
// Address: 0x10084190
// Name: enum VMPIFileSystemMode VMPI_GetFileSystemMode(void)
// Source: json
//------------------------------------------------------------------------------
VMPIFileSystemMode __cdecl VMPI_GetFileSystemMode()
{
  return g_VMPIFileSystemMode;
}

//------------------------------------------------------------------------------
// Address: 0x100841A0
// Name: int VMPI_GetCurrentNumberOfConnections(void)
// Source: json
//------------------------------------------------------------------------------
int __cdecl VMPI_GetCurrentNumberOfConnections()
{
  return g_nConnections;
}

//------------------------------------------------------------------------------
// Address: 0x100841B0
// Name: bool VMPI_FilterPacketsForServiceDownloader(class CVMPIConnection __near *,void const __near * const __near *,int const __near *,int)
// Source: json
//------------------------------------------------------------------------------
char __cdecl VMPI_FilterPacketsForServiceDownloader(
        CVMPIConnection *pConnection,
        const void *const *pChunks,
        const int *pChunkLengths,
        int nChunks)
{
  int v4; // eax
  int v5; // ecx
  unsigned __int8 *v7; // eax
  unsigned __int8 v8; // dl
  int v9; // eax
  char szPacketID[64]; // [esp+4h] [ebp-80h] BYREF
  char szSubPacketID[64]; // [esp+44h] [ebp-40h] BYREF

  if ( !pConnection->m_bIsAService )
    return 0;
  v4 = 0;
  if ( nChunks <= 0 )
    return 0;
  while ( 1 )
  {
    v5 = pChunkLengths[v4];
    if ( v5 >= 1 )
      break;
    if ( ++v4 >= nChunks )
      return 0;
  }
  v7 = (unsigned __int8 *)pChunks[v4];
  v8 = *v7;
  if ( *v7 == 27 || v8 == 10 || v8 == 0 )
    return 0;
  if ( g_bSuperSpewEnabled )
  {
    if ( v5 < 2 )
      v9 = -1;
    else
      v9 = v7[1];
    CVMPIPacketIDReg::Lookup(
      nPacketID: v8,
      nSubPacketID: v9,
      pPacketIDString: szPacketID,
      nPacketIDStringSize: 64,
      pSubPacketIDString: szSubPacketID,
      nSubPacketIDStringSize: 64);
    VMPI_SuperSpew(
      pMsg: "VMPI_FilterPacketsForServiceDownloader filtered packetID %s, subPacketID %s\n",
      szPacketID,
      szSubPacketID);
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10084250
// Name: bool VMPI_IsProcValid(int)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl VMPI_IsProcValid(int procID)
{
  return procID >= 0 && procID < g_nConnections && g_Connections[procID] != nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10084280
// Name: bool VMPI_IsProcConnected(int)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl VMPI_IsProcConnected(int procID)
{
  CVMPIConnection *v1; // eax

  return procID >= 0 && procID < g_nConnections && (v1 = g_Connections[procID]) != nullptr && v1->m_pSocket != nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x100842B0
// Name: void VMPI_Sleep(unsigned long)
// Source: json
//------------------------------------------------------------------------------
void __cdecl VMPI_Sleep(DWORD ms)
{
  Sleep(dwMilliseconds: ms);
}

//------------------------------------------------------------------------------
// Address: 0x100842C0
// Name: unsigned long VMPI_GetJobWorkerID(int)
// Source: json
//------------------------------------------------------------------------------
unsigned int __cdecl VMPI_GetJobWorkerID(int iProc)
{
  return g_Connections[iProc]->m_JobWorkerID;
}

//------------------------------------------------------------------------------
// Address: 0x100842E0
// Name: void VMPI_GetCurrentStage(char __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl VMPI_GetCurrentStage(char *pOut, int strLen)
{
  CCriticalSectionLock csLock; // [esp+0h] [ebp-8h] BYREF

  CCriticalSectionLock::CCriticalSectionLock(this: &csLock, pCS: &g_CurrentStageCS);
  CCriticalSectionLock::Lock(this: &csLock);
  V_strncpy(pDest: pOut, pSrc: g_CurrentStageString, maxLen: strLen);
  CCriticalSectionLock::~CCriticalSectionLock(this: &csLock);
}

//------------------------------------------------------------------------------
// Address: 0x10084320
// Name: void VMPI_SetCurrentStage(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl VMPI_SetCurrentStage(char *pCurStage)
{
  CCriticalSectionLock csLock; // [esp+0h] [ebp-8h] BYREF

  CCriticalSectionLock::CCriticalSectionLock(this: &csLock, pCS: &g_CurrentStageCS);
  CCriticalSectionLock::Lock(this: &csLock);
  V_strncpy(pDest: g_CurrentStageString, pSrc: pCurStage, maxLen: 128);
  CCriticalSectionLock::~CCriticalSectionLock(this: &csLock);
}

//------------------------------------------------------------------------------
// Address: 0x10084360
// Name: bool VMPI_IsSDKMode(void)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl VMPI_IsSDKMode()
{
  if ( g_bVMPISDKModeSet )
    return g_bVMPISDKMode;
  else
    return !VMPI_CheckForNonSDKExecutables();
}

//------------------------------------------------------------------------------
// Address: 0x10084380
// Name: char const __near * VMPI_GetParamString(enum EVMPICmdLineParam)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl VMPI_GetParamString(EVMPICmdLineParam eParam)
{
  if ( (unsigned int)(eParam - 1) <= 0x19 )
    return g_VMPIParams[eParam].m_pName;
  _Warning(a1: "Invalid call: VMPI_GetParamString( %d )\n");
  return "unknown";
}

//------------------------------------------------------------------------------
// Address: 0x100843B0
// Name: bool VMPI_IsParamUsed(enum EVMPICmdLineParam)
// Source: json
//------------------------------------------------------------------------------
BOOL __fastcall VMPI_IsParamUsed(int a1, int a2, EVMPICmdLineParam eParam)
{
  int v3; // esi

  v3 = _CommandLine(a1, a2);
  if ( (unsigned int)(eParam - 1) <= 0x19 )
    return (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v3 + 40))(a1: v3, a2: g_VMPIParams[eParam].m_pName) != 0;
  _Warning(a1: "Invalid call: VMPI_GetParamString( %d )\n");
  return (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v3 + 40))(a1: v3, a2: "unknown") != 0;
}

//------------------------------------------------------------------------------
// Address: 0x10084410
// Name: void ParseOptions(int,char __near * __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ParseOptions(int argc, char **argv)
{
  char *Arg; // eax
  char *v3; // eax
  char v4; // al

  if ( VMPI_FindArg(argc, argv, pName: g_VMPIParams[18].m_pName, pDefault: defaultValue) != nullptr )
    ThreadedTCP_EnableTimeouts(bEnable: false);
  if ( VMPI_FindArg(argc, argv, pName: g_VMPIParams[19].m_pName, pDefault: defaultValue) != nullptr )
  {
    _Msg(a1: "%s found.\n", g_VMPIParams[19].m_pName);
    g_bSetThreadPriorities = false;
    ThreadedTCP_SetTCPSocketThreadPriorities(bSetTCPSocketThreadPriorities: false);
  }
  if ( VMPI_FindArg(argc, argv, pName: g_VMPIParams[20].m_pName, pDefault: defaultValue) != nullptr )
  {
    _Msg(a1: "%s found.\n", g_VMPIParams[20].m_pName);
    g_bGroupPackets = true;
  }
  Arg = VMPI_FindArg(argc, argv, pName: g_VMPIParams[12].m_pName, pDefault: "1");
  if ( Arg != nullptr )
    MULTICAST_TRANSMIT_RATE = atoi(nptr: Arg) << 10;
  v3 = VMPI_FindArg(argc, argv, pName: g_VMPIParams[13].m_pName, pDefault: "1");
  if ( v3 != nullptr )
  {
    v4 = *v3;
    if ( v4 == 49 )
    {
      g_iVMPIVerboseLevel = 1;
    }
    else if ( v4 == 50 )
    {
      g_iVMPIVerboseLevel = 2;
    }
  }
  if ( VMPI_FindArg(argc, argv, pName: g_VMPIParams[21].m_pName, pDefault: defaultValue) != nullptr )
    g_bMPI_Stats = true;
  if ( VMPI_FindArg(argc, argv, pName: g_VMPIParams[22].m_pName, pDefault: defaultValue) != nullptr )
    g_bMPI_StatsTextOutput = true;
}

//------------------------------------------------------------------------------
// Address: 0x10084560
// Name: void CountActiveConnections(int __near *,int __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CountActiveConnections(int *nRegularWorkers, int *nServiceDownloaders)
{
  int v2; // ebx
  int i; // ecx
  CVMPIConnection *v4; // eax

  *nServiceDownloaders = 0;
  *nRegularWorkers = 0;
  v2 = g_nConnections;
  for ( i = 0; i < v2; ++i )
  {
    if ( i >= 0 && i < g_nConnections )
    {
      v4 = g_Connections[i];
      if ( v4 != nullptr && v4->m_pSocket != nullptr )
      {
        if ( v4->m_bIsAService )
          ++*nServiceDownloaders;
        else
          ++*nRegularWorkers;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100845C0
// Name: void UpdateActiveConnectionsText(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl UpdateActiveConnectionsText()
{
  HWND v0; // esi
  char str[512]; // [esp+0h] [ebp-208h] BYREF
  int nDownloaders; // [esp+200h] [ebp-8h] BYREF
  int nRegularWorkers; // [esp+204h] [ebp-4h] BYREF

  if ( g_bMPIMaster && g_pConsoleWndFn != nullptr )
  {
    v0 = g_pConsoleWndFn();
    if ( v0 != nullptr )
    {
      CountActiveConnections(&nRegularWorkers, nServiceDownloaders: &nDownloaders);
      if ( g_bVMPISDKMode )
        V_snprintf(pDest: str, maxLen: 0x200u, pFormat: "VMPI (SDK) - Workers: %d", nRegularWorkers);
      else
        V_snprintf(
          pDest: str,
          maxLen: 0x200u,
          pFormat: "VMPI - Workers: %d, Downloaders: %d",
          nRegularWorkers,
          nDownloaders);
      SetWindowTextA(hWnd: v0, lpString: str);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10084660
// Name: bool SpawnLocalWorker(int,char __near * __near *,int,bool)
// Source: json
//------------------------------------------------------------------------------
char __cdecl SpawnLocalWorker(int argc, char **argv, int iListenPort, bool bShowConsoleWindow)
{
  int i; // ebx
  const char *m_pName; // edi
  int v7; // esi
  char CommandLine[4096]; // [esp+Ch] [ebp-1854h] BYREF
  char pnbuf[1024]; // [esp+100Ch] [ebp-854h] BYREF
  char pStr[512]; // [esp+140Ch] [ebp-454h] BYREF
  char pDest[512]; // [esp+160Ch] [ebp-254h] BYREF
  _STARTUPINFOA dst; // [esp+180Ch] [ebp-54h] BYREF
  _PROCESS_INFORMATION ProcessInformation; // [esp+1850h] [ebp-10h] BYREF

  CommandLine[0] = 0;
  for ( i = 0; i < 9999999; ++i )
  {
    if ( i == 1 )
    {
      V_snprintf(pDest, maxLen: 0x200u, pFormat: "-mpi_worker 127.0.0.1:%d ", iListenPort);
      V_strncat(pDest: CommandLine, pSrc: pDest, destBufferSize: 0x1000u, max_chars_to_copy: -1);
      V_strncat(pDest: CommandLine, pSrc: "-allowdebug ", destBufferSize: 0x1000u, max_chars_to_copy: -1);
      if ( g_bVMPISDKModeSet ? g_bVMPISDKMode : !VMPI_CheckForNonSDKExecutables() )
      {
        m_pName = g_VMPIParams[15].m_pName;
        v7 = 0;
        if ( argc <= 0 )
          goto LABEL_13;
        while ( _V_stricmp(s1: argv[v7], s2: m_pName) != 0 )
        {
          if ( ++v7 >= argc )
            goto LABEL_13;
        }
        if ( v7 + 1 < argc && argv[v7 + 1] == nullptr )
LABEL_13:
          V_strncat(pDest: CommandLine, pSrc: g_VMPIParams[15].m_pName, destBufferSize: 0x1000u, max_chars_to_copy: -1);
      }
    }
    if ( i >= argc )
      break;
    V_snprintf(pDest, maxLen: 0x200u, pFormat: "\"%s\" ", argv[i]);
    V_strncat(pDest: CommandLine, pSrc: pDest, destBufferSize: 0x1000u, max_chars_to_copy: -1);
  }
  if ( _getcwd(pnbuf, maxlen: 1024) != nullptr )
  {
    memset((unsigned __int8 *)&dst, value: 0, count: sizeof(dst));
    dst.cb = 68;
    memset(&ProcessInformation, 0, sizeof(ProcessInformation));
    if ( CreateProcessA(
           lpApplicationName: nullptr,
           lpCommandLine: CommandLine,
           lpProcessAttributes: nullptr,
           lpThreadAttributes: nullptr,
           bInheritHandles: true,
           dwCreationFlags: (bShowConsoleWindow ? 16 : 0x8000000) | 0x40,
           lpEnvironment: nullptr,
           lpCurrentDirectory: pnbuf,
           lpStartupInfo: &dst,
           lpProcessInformation: &ProcessInformation) )
    {
      return 1;
    }
    else
    {
      IP_GetLastErrorString(pStr, maxLen: 1024);
      _Warning(a1: " - ERROR in CreateProcess (%s)!\n");
      return 0;
    }
  }
  else
  {
    _Warning(a1: "_getcwd() failed.\n");
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10084860
// Name: private: void CMasterBroadcaster::BuildBroadcastPacket(class bf_write __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMasterBroadcaster::BuildBroadcastPacket(CMasterBroadcaster *this, bf_write *buf)
{
  bf_write *v2; // esi
  bool v4; // zf
  const char *v5; // eax
  int i; // ebx

  v2 = buf;
  bf_write::WriteByte(this: buf, val: 5u);
  bf_write::WriteString(this: v2, pStr: this->m_BroadcastInfo.m_Password);
  if ( this->m_BroadcastInfo.m_PatchVersion[0] != 0 )
    bf_write::WriteByte(this: v2, val: 0x4Fu);
  else
    bf_write::WriteByte(this: v2, val: 0x47u);
  bf_write::WriteString(this: v2, pStr: this->m_BroadcastInfo.m_PatchVersion);
  bf_write::WriteLong(this: v2, val: this->m_iListenPort);
  bf_write::WriteLong(this: v2, val: this->m_BroadcastInfo.m_JobID[0]);
  bf_write::WriteLong(this: v2, val: this->m_BroadcastInfo.m_JobID[1]);
  bf_write::WriteLong(this: v2, val: this->m_BroadcastInfo.m_JobID[2]);
  bf_write::WriteLong(this: v2, val: this->m_BroadcastInfo.m_JobID[3]);
  bf_write::WriteWord(this: v2, val: this->m_BroadcastInfo.m_Args.m_Size + 2);
  bf_write::WriteString(this: v2, pStr: this->m_BroadcastInfo.m_WorkerExeFilename);
  bf_write::WriteString(this: v2, pStr: "-mpi_MasterName");
  buf = (bf_write *)16;
  v4 = !GetComputerNameA(lpBuffer: Buffer, nSize: (LPDWORD)&buf);
  v5 = Buffer;
  if ( v4 )
    v5 = "(error in GetComputerName)";
  bf_write::WriteString(this: v2, pStr: v5);
  for ( i = 1; i < this->m_BroadcastInfo.m_Args.m_Size; ++i )
    bf_write::WriteString(this: v2, pStr: this->m_BroadcastInfo.m_Args.m_Memory.m_pMemory[i]);
  bf_write::WriteByte(this: v2, val: 1u);
  bf_write::WriteShort(this: v2, val: this->m_iDownloaderListenPort);
}

//------------------------------------------------------------------------------
// Address: 0x10084980
// Name: bool IsValidSDKBinPath(class CUtlVector<char __near *,class CUtlMemory<char __near *,int>> __near &,int __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl IsValidSDKBinPath(CUtlVector<char *,CUtlMemory<char *,int> > *outStrings, int *pError)
{
  int m_Size; // eax
  int i; // edi
  int j; // edi
  char mapsrcFilename[260]; // [esp+8h] [ebp-54Ch] BYREF
  char blobPath[260]; // [esp+10Ch] [ebp-448h] BYREF
  char tempFilename[260]; // [esp+210h] [ebp-344h] BYREF
  char baseSteamPath[260]; // [esp+314h] [ebp-240h] BYREF
  char sourcesdkContentPath[260]; // [esp+418h] [ebp-13Ch] BYREF
  _stat64i32 results; // [esp+51Ch] [ebp-38h] BYREF
  __int64 curTime; // [esp+54Ch] [ebp-8h] BYREF

  *pError = 0;
  m_Size = outStrings->m_Size;
  if ( m_Size >= 9 )
  {
    if ( _V_stricmp(s1: outStrings->m_Memory.m_pMemory[m_Size - 2], s2: "bin") != 0 )
    {
      *pError = 1;
      return 0;
    }
    else if ( _V_stricmp(s1: outStrings->m_Memory.m_pMemory[outStrings->m_Size - 5], s2: "sourcesdk") != 0 )
    {
      *pError = 2;
      return 0;
    }
    else if ( _V_stricmp(s1: outStrings->m_Memory.m_pMemory[outStrings->m_Size - 7], s2: "steamapps") != 0 )
    {
      *pError = 3;
      return 0;
    }
    else
    {
      V_strncpy(pDest: baseSteamPath, pSrc: *outStrings->m_Memory.m_pMemory, maxLen: 260);
      for ( i = 1; i < outStrings->m_Size - 7; ++i )
      {
        V_AppendSlash(pStr: baseSteamPath, strSize: 260);
        V_strncat(
          pDest: baseSteamPath,
          pSrc: outStrings->m_Memory.m_pMemory[i],
          destBufferSize: 0x104u,
          max_chars_to_copy: -1);
      }
      V_ComposeFileName(path: baseSteamPath, filename: "ClientRegistry.blob", dest: blobPath, destSize: 260);
      if ( _stat64i32(name: blobPath, buf: &results) != 0 )
      {
        *pError = 4;
        return 0;
      }
      else
      {
        _time64(timeptr: &curTime);
        if ( (int)curTime - LODWORD(results.st_mtime) <= 864000 )
        {
          V_strncpy(pDest: sourcesdkContentPath, pSrc: *outStrings->m_Memory.m_pMemory, maxLen: 260);
          for ( j = 1; j < outStrings->m_Size - 5; ++j )
          {
            V_AppendSlash(pStr: sourcesdkContentPath, strSize: 260);
            V_strncat(
              pDest: sourcesdkContentPath,
              pSrc: outStrings->m_Memory.m_pMemory[j],
              destBufferSize: 0x104u,
              max_chars_to_copy: -1);
          }
          V_AppendSlash(pStr: sourcesdkContentPath, strSize: 260);
          V_strncat(
            pDest: sourcesdkContentPath,
            pSrc: "sourcesdk_content",
            destBufferSize: 0x104u,
            max_chars_to_copy: -1);
          V_snprintf(pDest: tempFilename, maxLen: 0x104u, pFormat: "cstrike%cmapsrc", 92);
          V_ComposeFileName(path: sourcesdkContentPath, filename: tempFilename, dest: mapsrcFilename, destSize: 260);
          if ( access(path: mapsrcFilename, amode: 0) != 0 )
          {
            *pError = 6;
            return 0;
          }
          else
          {
            return 1;
          }
        }
        else
        {
          *pError = 5;
          return 0;
        }
      }
    }
  }
  else
  {
    *pError = 0;
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10084C00
// Name: void VerifyValidSDKMode(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl VerifyValidSDKMode()
{
  HMODULE ModuleHandleA; // eax
  char baseExeFilename[260]; // [esp+4h] [ebp-124h] BYREF
  CSplitString outStrings; // [esp+108h] [ebp-20h] BYREF
  int err; // [esp+120h] [ebp-8h] BYREF
  char strSlash[4]; // [esp+124h] [ebp-4h] BYREF

  ModuleHandleA = GetModuleHandleA(lpModuleName: nullptr);
  if ( GetModuleFileNameA(hModule: ModuleHandleA, lpFilename: baseExeFilename, nSize: 0x104u) == 0 )
    _Error(a1: "VerifyValidSDKMode: GetModuleFileName failed.");
  V_FixSlashes(pname: baseExeFilename, separator: 92);
  strcpy(strSlash, "\\");
  CSplitString::CSplitString(this: &outStrings, pString: baseExeFilename, pSeparator: strSlash);
  if ( IsValidSDKBinPath(&outStrings, pError: &err) == 0 )
  {
    if ( err == 5 )
    {
      _Error(a1: "VMPI running in SDK mode but Steam hasn't been run recently. Please run Steam and retry.");
      CSplitString::~CSplitString(this: &outStrings);
      return;
    }
    _Error(a1: "VMPI running in SDK mode but incorrect SDK install detected (error %d).", err);
  }
  CSplitString::~CSplitString(this: &outStrings);
}

//------------------------------------------------------------------------------
// Address: 0x10084CB0
// Name: void VMPI_CheckSDKMode(int,char __near * __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl VMPI_CheckSDKMode(int argc, char **argv)
{
  bool v2; // al

  if ( g_bIsRunningVMPITransfer )
  {
    g_bVMPISDKMode = false;
    g_bVMPISDKModeSet = true;
    return;
  }
  v2 = VMPI_CheckForNonSDKExecutables();
  g_bVMPISDKMode = !v2;
  g_bVMPISDKModeSet = true;
  if ( v2 )
  {
    if ( VMPI_FindArg(argc, argv, pName: g_VMPIParams[15].m_pName, pDefault: defaultValue) != nullptr )
    {
      g_bVMPISDKMode = true;
    }
    else if ( !g_bVMPISDKMode )
    {
      return;
    }
  }
  VerifyValidSDKMode();
  if ( g_bVMPISDKMode )
    _Msg(a1: "VMPI running in SDK mode.\n");
}

//------------------------------------------------------------------------------
// Address: 0x10084D40
// Name: char const __near * VMPI_GetMachineName(int)
// Source: json
//------------------------------------------------------------------------------
char *__cdecl VMPI_GetMachineName(int iProc)
{
  bool v1; // sf
  bool v2; // zf
  char *result; // eax
  CVMPIConnection *v4; // eax
  unsigned int nSize; // [esp+0h] [ebp-4h] BYREF

  if ( g_bMPIMaster )
  {
    v1 = iProc < 0;
    if ( iProc == 0 )
    {
      nSize = 16;
      v2 = !GetComputerNameA(lpBuffer: Buffer, &nSize);
      result = Buffer;
      if ( v2 )
        return "(error in GetComputerName)";
      return result;
    }
  }
  else
  {
    v1 = iProc < 0;
  }
  if ( v1 )
    return "invalid index";
  if ( iProc >= g_nConnections )
    return "invalid index";
  v4 = g_Connections[iProc];
  if ( v4 == nullptr )
    return "invalid index";
  else
    return v4->m_MachineName.m_Memory.m_pMemory;
}

//------------------------------------------------------------------------------
// Address: 0x100851F0
// Name: public: void CVMPIConnection::HandleDisconnect(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVMPIConnection::HandleDisconnect(CVMPIConnection *this)
{
  int m_Head; // esi
  UtlLinkedListElem_t<void (__cdecl*)(int,char const *),int> *m_pMemory; // eax
  int v4; // esi
  char str[512]; // [esp+4h] [ebp-208h] BYREF
  CCriticalSectionLock csLock; // [esp+204h] [ebp-8h] BYREF

  if ( this->m_pSocket != nullptr )
  {
    CCriticalSectionLock::CCriticalSectionLock(this: &csLock, pCS: &g_ErrorSocketsCS);
    CCriticalSectionLock::Lock(this: &csLock);
    V_strncpy(pDest: str, pSrc: this->m_ErrorString.m_Memory.m_pMemory, maxLen: 512);
    CCriticalSectionLock::Unlock(this: &csLock);
    m_Head = g_DisconnectHandlers.m_Head;
    if ( g_DisconnectHandlers.m_Head != -1 )
    {
      m_pMemory = g_DisconnectHandlers.m_Memory.m_pMemory;
      do
      {
        v4 = m_Head;
        m_pMemory[v4].m_Element(a1: this->m_iConnection, a2: str);
        m_pMemory = g_DisconnectHandlers.m_Memory.m_pMemory;
        m_Head = g_DisconnectHandlers.m_Memory.m_pMemory[v4].m_Next;
      }
      while ( m_Head != -1 );
    }
    this->m_pSocket->Release(this: this->m_pSocket);
    this->m_pSocket = nullptr;
    CCriticalSectionLock::~CCriticalSectionLock(this: &csLock);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100852A0
// Name: bool VMPI_HandleAutoRestart(void)
// Source: json
//------------------------------------------------------------------------------
char __usercall VMPI_HandleAutoRestart@<al>(int a1@<ebp>)
{
  void *v1; // esp
  HANDLE CurrentProcess; // eax
  int v3; // esi
  DWORD PriorityClass; // edi
  char **m_pMemory; // eax
  char v7[8192]; // [esp-2458h] [ebp-2464h] BYREF
  char v8; // [esp-458h] [ebp-464h] BYREF
  char v9[512]; // [esp-258h] [ebp-264h] BYREF
  _STARTUPINFOA v10; // [esp-58h] [ebp-64h] BYREF
  _PROCESS_INFORMATION v11; // [esp-10h] [ebp-1Ch] BYREF
  int v12; // [esp+0h] [ebp-Ch]
  void *v13; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v12 = a1;
  v13 = retaddr;
  v1 = alloca(9304);
  if ( g_OriginalCommandLineParameters.m_Size == 0 )
    return 1;
  _Msg(a1: "%s found. Auto-restarting.\n", g_VMPIParams[6].m_pName);
  CurrentProcess = GetCurrentProcess();
  v3 = 0;
  PriorityClass = GetPriorityClass(hProcess: CurrentProcess);
  for ( v7[0] = 0; v3 < g_OriginalCommandLineParameters.m_Size; ++v3 )
  {
    V_snprintf(pDest: v9, maxLen: 0x200u, pFormat: "\"%s\" ", g_OriginalCommandLineParameters.m_Memory.m_pMemory[v3]);
    V_strncat(pDest: v7, pSrc: v9, destBufferSize: 0x2000u, max_chars_to_copy: -1);
  }
  memset(dst: (unsigned __int8 *)&v10, value: 0, count: sizeof(v10));
  v10.cb = 68;
  v11 = 0;
  if ( CreateProcessA(
         lpApplicationName: nullptr,
         lpCommandLine: v7,
         lpProcessAttributes: nullptr,
         lpThreadAttributes: nullptr,
         bInheritHandles: true,
         dwCreationFlags: PriorityClass | 0x10,
         lpEnvironment: nullptr,
         lpCurrentDirectory: nullptr,
         lpStartupInfo: &v10,
         lpProcessInformation: &v11) )
  {
    m_pMemory = g_OriginalCommandLineParameters.m_Memory.m_pMemory;
    g_OriginalCommandLineParameters.m_Size = 0;
    if ( g_OriginalCommandLineParameters.m_Memory.m_nGrowSize >= 0 )
    {
      if ( g_OriginalCommandLineParameters.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: g_OriginalCommandLineParameters.m_Memory.m_pMemory);
        m_pMemory = nullptr;
        g_OriginalCommandLineParameters.m_Memory.m_pMemory = nullptr;
      }
      g_OriginalCommandLineParameters.m_Memory.m_nAllocationCount = 0;
    }
    g_OriginalCommandLineParameters.m_pElements = m_pMemory;
    return 1;
  }
  IP_GetLastErrorString(pStr: &v8, maxLen: 1024);
  _Warning(a1: " - ERROR in CreateProcess (%s)!\n");
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10085410
// Name: void VMPI_FlushGroupedPackets(unsigned long)
// Source: json
//------------------------------------------------------------------------------
void __cdecl VMPI_FlushGroupedPackets(unsigned int msInterval)
{
  int v1; // eax
  int i; // ebx
  CVMPIConnection *v3; // esi
  IThreadedTCPSocket *m_pSocket; // ecx
  int j; // edi
  CCriticalSectionLock connectionsLock; // [esp+4h] [ebp-8h] BYREF

  if ( msInterval != 0 )
  {
    v1 = _Plat_MSTime();
    if ( v1 - g_LastFlushGroupedPacketsTime < msInterval )
      return;
    g_LastFlushGroupedPacketsTime = v1;
  }
  CCriticalSectionLock::CCriticalSectionLock(this: &connectionsLock, pCS: &g_ConnectionsCS);
  CCriticalSectionLock::Lock(this: &connectionsLock);
  for ( i = 0; i < g_nConnections; ++i )
  {
    v3 = g_Connections[i];
    if ( v3 != nullptr )
    {
      m_pSocket = v3->m_pSocket;
      if ( m_pSocket != nullptr && v3->m_GroupedChunks.m_Size != 0 )
      {
        m_pSocket->SendChunks(
          this: m_pSocket,
          a2: (const void *const *)v3->m_GroupedChunks.m_Memory.m_pMemory,
          a3: v3->m_GroupedChunkLengths.m_Memory.m_pMemory,
          a4: v3->m_GroupedChunks.m_Size);
        for ( j = 1; j < v3->m_GroupedChunks.m_Size; ++j )
          free(pMem: v3->m_GroupedChunks.m_Memory.m_pMemory[j]);
        v3->m_GroupedChunks.m_Size = 0;
        v3->m_GroupedChunkLengths.m_Size = 0;
      }
    }
  }
  CCriticalSectionLock::~CCriticalSectionLock(this: &connectionsLock);
}

//------------------------------------------------------------------------------
// Address: 0x100854D0
// Name: public: void CMasterBroadcaster::SetNoTimeoutOption(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMasterBroadcaster::SetNoTimeoutOption(CMasterBroadcaster *this)
{
  int v2; // edi
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  const char *m_pName; // edi
  char **m_pMemory; // eax
  int v7; // ecx
  char **v8; // esi
  CCriticalSectionLock connectionsLock; // [esp+8h] [ebp-8h] BYREF

  CCriticalSectionLock::CCriticalSectionLock(this: &connectionsLock, pCS: &g_ConnectionsCS);
  CCriticalSectionLock::Lock(this: &connectionsLock);
  v2 = 1;
  if ( this->m_BroadcastInfo.m_Args.m_Size <= 1 )
  {
LABEL_4:
    m_Size = this->m_BroadcastInfo.m_Args.m_Size;
    m_nAllocationCount = this->m_BroadcastInfo.m_Args.m_Memory.m_nAllocationCount;
    m_pName = g_VMPIParams[18].m_pName;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<int,int>::Grow(
        this: (CUtlMemory<S3RGBA,int> *)&this->m_BroadcastInfo.m_Args,
        num: m_Size - m_nAllocationCount + 1);
    ++this->m_BroadcastInfo.m_Args.m_Size;
    m_pMemory = this->m_BroadcastInfo.m_Args.m_Memory.m_pMemory;
    v7 = this->m_BroadcastInfo.m_Args.m_Size - 2;
    this->m_BroadcastInfo.m_Args.m_pElements = m_pMemory;
    if ( v7 > 0 )
      _V_memmove(dest: (unsigned __int8 *)m_pMemory + 8, src: (unsigned __int8 *)m_pMemory + 4, count: 4 * v7);
    v8 = this->m_BroadcastInfo.m_Args.m_Memory.m_pMemory + 1;
    if ( v8 != nullptr )
      *v8 = (char *)m_pName;
  }
  else
  {
    while ( _V_stricmp(s1: this->m_BroadcastInfo.m_Args.m_Memory.m_pMemory[v2], s2: g_VMPIParams[18].m_pName) != 0 )
    {
      if ( ++v2 >= this->m_BroadcastInfo.m_Args.m_Size )
        goto LABEL_4;
    }
  }
  CCriticalSectionLock::~CCriticalSectionLock(this: &connectionsLock);
}

//------------------------------------------------------------------------------
// Address: 0x100855A0
// Name: void VMPI_InviteDebugWorkers(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl VMPI_InviteDebugWorkers()
{
  int v0; // eax
  CCriticalSectionLock v1; // [esp+0h] [ebp-8h] BYREF

  CCriticalSectionLock::CCriticalSectionLock(this: &v1, pCS: &g_ConnectionsCS);
  CCriticalSectionLock::Lock(this: &v1);
  V_strncpy(pDest: g_MasterBroadcaster.m_BroadcastInfo.m_Password, pSrc: "debugworker", maxLen: 256);
  CCriticalSectionLock::~CCriticalSectionLock(this: &v1);
  CMasterBroadcaster::SetNoTimeoutOption(this: &g_MasterBroadcaster);
  ThreadedTCP_EnableTimeouts(bEnable: false);
  CCriticalSectionLock::CCriticalSectionLock(this: &v1, pCS: &g_ConnectionsCS);
  CCriticalSectionLock::Lock(this: &v1);
  v0 = g_MasterBroadcaster.m_nMaxWorkers + 25;
  g_MasterBroadcaster.m_nMaxWorkers = 512;
  if ( v0 <= 512 )
    g_MasterBroadcaster.m_nMaxWorkers = v0;
  CCriticalSectionLock::~CCriticalSectionLock(this: &v1);
}

//------------------------------------------------------------------------------
// Address: 0x10085790
// Name: void ParseDependencyFile(class CDependencyInfo __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ParseDependencyFile(CDependencyInfo *pInfo, const char *pDepFilename)
{
  _iobuf *v2; // esi
  int v3; // eax
  char v4; // cl
  bool v5; // zf
  char *v6; // eax
  CDependencyInfo::CDependencyFile *v7; // edi
  char v8; // bl
  char *v9; // eax
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CDependencyInfo::CDependencyFile **m_pMemory; // ecx
  int v13; // eax
  CDependencyInfo::CDependencyFile **v14; // eax
  char fullFilename[260]; // [esp+Ch] [ebp-210h] BYREF
  char tempStr[260]; // [esp+110h] [ebp-10Ch] BYREF
  _iobuf *fp; // [esp+214h] [ebp-8h]
  CDependencyInfo::CDependencyFile *pFile; // [esp+218h] [ebp-4h]

  fp = fopen(file: pDepFilename, mode: "rt");
  if ( fp == nullptr )
    _Error(a1: "Can't find %s.", pDepFilename);
  while ( 1 )
  {
    v2 = fp;
    if ( fgets(string: tempStr, count: 260, str: fp) == nullptr || tempStr[0] == 0 )
      break;
    v3 = &tempStr[strlen(tempStr) + 1] - &tempStr[1];
    v5 = fullFilename[v3 + 259] == 10;
    v6 = &fullFilename[v3 + 259];
    if ( v5 )
      *v6 = v4;
    v7 = (CDependencyInfo::CDependencyFile *)MemAlloc_Alloc(nSize: 0x104u);
    pFile = v7;
    v8 = 0;
    strstr(str1: (unsigned __int8 *)tempStr, str2: "optional ");
    if ( v9 == tempStr )
    {
      v8 = 1;
      V_strncpy(pDest: v7->m_Name, pSrc: &tempStr[9], maxLen: 260);
    }
    else
    {
      V_strncpy(pDest: v7->m_Name, pSrc: tempStr, maxLen: 260);
    }
    V_ComposeFileName(path: pInfo->m_DependencyFilesDir, filename: v7->m_Name, dest: fullFilename, destSize: 260);
    if ( access(path: fullFilename, amode: 0) != 0 )
    {
      free(pMem: v7);
      if ( v8 == 0 )
        _Error(a1: "Can't find %s (listed in %s).", fullFilename, pDepFilename);
    }
    else
    {
      m_Size = pInfo->m_Files.m_Size;
      m_nAllocationCount = pInfo->m_Files.m_Memory.m_nAllocationCount;
      if ( m_Size + 1 > m_nAllocationCount )
        CUtlMemory<int,int>::Grow(this: (CUtlMemory<S3RGBA,int> *)&pInfo->m_Files, num: m_Size - m_nAllocationCount + 1);
      ++pInfo->m_Files.m_Size;
      m_pMemory = pInfo->m_Files.m_Memory.m_pMemory;
      v13 = pInfo->m_Files.m_Size - m_Size - 1;
      pInfo->m_Files.m_pElements = m_pMemory;
      if ( v13 > 0 )
        _V_memmove(
          dest: (unsigned __int8 *)&m_pMemory[m_Size + 1],
          src: (unsigned __int8 *)&m_pMemory[m_Size],
          count: 4 * v13);
      v14 = &pInfo->m_Files.m_Memory.m_pMemory[m_Size];
      if ( v14 != nullptr )
        *v14 = pFile;
    }
  }
  fclose(stream: v2);
}

//------------------------------------------------------------------------------
// Address: 0x10085950
// Name: void SetupDependenciesForPatch(class CDependencyInfo __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SetupDependenciesForPatch(CDependencyInfo *pInfo, char *pPatchDirectory)
{
  char *v2; // ebx
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CDependencyInfo::CDependencyFile **m_pMemory; // ecx
  int v6; // eax
  CDependencyInfo::CDependencyFile **v7; // eax
  int v8; // esi
  char searchStr[260]; // [esp+0h] [ebp-230h] BYREF
  _finddata64i32_t data; // [esp+104h] [ebp-12Ch] BYREF
  int handle; // [esp+22Ch] [ebp-4h]

  V_ComposeFileName(path: pPatchDirectory, filename: "*.*", dest: searchStr, destSize: 260);
  handle = _findfirst64i32(szWild: searchStr, pfd: &data);
  if ( handle != -1 )
  {
    do
    {
      if ( data.name[0] != 46 && (data.attrib & 0x10) == 0 )
      {
        v2 = (char *)MemAlloc_Alloc(nSize: 0x104u);
        V_strncpy(pDest: v2, pSrc: data.name, maxLen: 260);
        m_Size = pInfo->m_Files.m_Size;
        m_nAllocationCount = pInfo->m_Files.m_Memory.m_nAllocationCount;
        if ( m_Size + 1 > m_nAllocationCount )
          CUtlMemory<int,int>::Grow(
            this: (CUtlMemory<S3RGBA,int> *)&pInfo->m_Files,
            num: m_Size - m_nAllocationCount + 1);
        ++pInfo->m_Files.m_Size;
        m_pMemory = pInfo->m_Files.m_Memory.m_pMemory;
        v6 = pInfo->m_Files.m_Size - m_Size - 1;
        pInfo->m_Files.m_pElements = m_pMemory;
        if ( v6 > 0 )
          _V_memmove(
            dest: (unsigned __int8 *)&m_pMemory[m_Size + 1],
            src: (unsigned __int8 *)&m_pMemory[m_Size],
            count: 4 * v6);
        v7 = &pInfo->m_Files.m_Memory.m_pMemory[m_Size];
        if ( v7 != nullptr )
          *v7 = (CDependencyInfo::CDependencyFile *)v2;
      }
      v8 = handle;
    }
    while ( _findnext64i32(hFile: handle, pfd: &data) == 0 );
    _findclose(hFile: v8);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10085A80
// Name: void SetupDependencyInfo(class CDependencyInfo __near *,char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SetupDependencyInfo(CDependencyInfo *pInfo, char *pDependencyFilename, bool bPatchMode)
{
  HMODULE ModuleHandleA; // eax
  char *v4; // eax
  char Filename[512]; // [esp+4h] [ebp-304h] BYREF
  char depFilename[260]; // [esp+204h] [ebp-104h] BYREF

  if ( bPatchMode )
  {
    SetupDependencyFilename(pInfo, pPatchDirectory: pDependencyFilename);
    SetupDependenciesForPatch(pInfo, pPatchDirectory: pDependencyFilename);
  }
  else
  {
    ModuleHandleA = GetModuleHandleA(lpModuleName: nullptr);
    if ( GetModuleFileNameA(hModule: ModuleHandleA, lpFilename: Filename, nSize: 0x200u) == 0 )
      _Error(a1: "GetModuleFileName failed.");
    V_strncpy(pDest: pInfo->m_DependencyFilesDir, pSrc: Filename, maxLen: 260);
    V_StripLastDir(dirName: pInfo->m_DependencyFilesDir, maxlen: 0x104u);
    v4 = (char *)V_UnqualifiedFileName(in: Filename);
    V_strncpy(pDest: pInfo->m_OriginalExeFilename, pSrc: v4, maxLen: 260);
    V_ComposeFileName(
      path: pInfo->m_DependencyFilesDir,
      filename: pDependencyFilename,
      dest: depFilename,
      destSize: 260);
    ParseDependencyFile(pInfo, pDepFilename: depFilename);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10085B50
// Name: public: CMasterBroadcaster::CMasterBroadcaster(void)
// Source: json
//------------------------------------------------------------------------------
CMasterBroadcaster *__thiscall CMasterBroadcaster::CMasterBroadcaster(CMasterBroadcaster *this)
{
  this->m_BroadcastInfo.m_Args.m_Memory.m_pMemory = nullptr;
  this->m_BroadcastInfo.m_Args.m_Memory.m_nAllocationCount = 0;
  this->m_BroadcastInfo.m_Args.m_Memory.m_nGrowSize = 0;
  this->m_BroadcastInfo.m_Args.m_Size = 0;
  this->m_BroadcastInfo.m_Args.m_pElements = nullptr;
  this->m_PatchWorkerIPs.m_Memory.m_pMemory = nullptr;
  this->m_PatchWorkerIPs.m_Memory.m_nAllocationCount = 0;
  this->m_PatchWorkerIPs.m_Memory.m_nGrowSize = 0;
  this->m_PatchWorkerIPs.m_Size = 0;
  this->m_PatchWorkerIPs.m_pElements = nullptr;
  this->m_ConnectionCreator.__vftable = (CVMPIConnectionCreator_vtbl *)&CVMPIConnectionCreator::`vftable';
  CExpressionEvaluator::CExpressionEvaluator(this: &this->m_hShutdownEvent);
  CExpressionEvaluator::CExpressionEvaluator(this: &this->m_hShutdownReply);
  this->m_pListenSocket = nullptr;
  this->m_pDownloaderListenSocket = nullptr;
  this->m_pSocket = nullptr;
  this->m_iListenPort = -1;
  this->m_iDownloaderListenPort = -1;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10085BD0
// Name: private: void CMasterBroadcaster::GetPatchWorkerList(int,char __near * __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMasterBroadcaster::GetPatchWorkerList(CMasterBroadcaster *this, int argc, char **argv)
{
  CUtlMemory<CMasterMulticastThread::CChunkInfo,int> *p_m_PatchWorkerIPs; // esi
  int v5; // edi
  int v6; // eax
  const char **v7; // ebx
  CMasterMulticastThread::CChunkInfo *m_pMemory; // edi
  int m_nAllocationCount; // eax
  CMasterMulticastThread::CChunkInfo *v10; // ecx
  int v11; // eax
  CIPAddr *v12; // eax
  CIPAddr addr; // [esp+8h] [ebp-20h] BYREF
  int a; // [esp+10h] [ebp-18h] BYREF
  int b; // [esp+14h] [ebp-14h] BYREF
  int c; // [esp+18h] [ebp-10h] BYREF
  int d; // [esp+1Ch] [ebp-Ch] BYREF
  int workerCount; // [esp+20h] [ebp-8h]
  int i; // [esp+24h] [ebp-4h]
  int iWorker; // [esp+34h] [ebp+Ch]

  p_m_PatchWorkerIPs = (CUtlMemory<CMasterMulticastThread::CChunkInfo,int> *)&this->m_PatchWorkerIPs;
  this->m_PatchWorkerIPs.m_Size = 0;
  if ( this->m_PatchWorkerIPs.m_Memory.m_nGrowSize >= 0 )
  {
    if ( p_m_PatchWorkerIPs->m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: p_m_PatchWorkerIPs->m_pMemory);
      p_m_PatchWorkerIPs->m_pMemory = nullptr;
    }
    p_m_PatchWorkerIPs->m_nAllocationCount = 0;
  }
  p_m_PatchWorkerIPs[1].m_nAllocationCount = (int)p_m_PatchWorkerIPs->m_pMemory;
  i = 0;
  if ( argc - 1 > 0 )
  {
    while ( _V_stricmp(s1: argv[i], s2: "-mpi_PatchWorkers") != 0 )
    {
      if ( ++i >= argc - 1 )
        return;
    }
    v5 = i;
    v6 = atoi(nptr: argv[i + 1]);
    workerCount = v6;
    iWorker = 0;
    if ( v6 > 0 )
    {
      v7 = (const char **)&argv[i + 2];
      while ( 1 )
      {
        if ( v5 + iWorker + 2 >= argc )
          _Error(a1: "-mpi_PatchWorkers: %d specified for count, but not enough IPs following.\n", v6);
        sscanf(string: *v7, format: "%d.%d.%d.%d", &a, &b, &c, &d);
        CIPAddr::CIPAddr(this: &addr);
        CIPAddr::Init(this: &addr, ip0: a, ip1: b, ip2: c, ip3: d, ipPort: 0);
        m_pMemory = p_m_PatchWorkerIPs[1].m_pMemory;
        m_nAllocationCount = p_m_PatchWorkerIPs->m_nAllocationCount;
        if ( (int)&m_pMemory->m_iChunk + 1 > m_nAllocationCount )
          CUtlMemory<CIPAddr,int>::Grow(
            this: p_m_PatchWorkerIPs,
            num: (int)&m_pMemory->m_iChunk - m_nAllocationCount + 1);
        ++p_m_PatchWorkerIPs[1].m_pMemory;
        v10 = p_m_PatchWorkerIPs->m_pMemory;
        v11 = (char *)p_m_PatchWorkerIPs[1].m_pMemory - (char *)m_pMemory - 1;
        p_m_PatchWorkerIPs[1].m_nAllocationCount = (int)p_m_PatchWorkerIPs->m_pMemory;
        if ( v11 > 0 )
          _V_memmove(
            dest: (unsigned __int8 *)&v10[(int)m_pMemory + 1],
            src: (unsigned __int8 *)&v10[(_DWORD)m_pMemory],
            count: 6 * v11);
        v12 = (CIPAddr *)&p_m_PatchWorkerIPs->m_pMemory[(_DWORD)m_pMemory];
        if ( v12 != nullptr )
          *v12 = addr;
        ++v7;
        if ( ++iWorker >= workerCount )
          break;
        v6 = workerCount;
        v5 = i;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10085D60
// Name: void VMPI_Finalize(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall VMPI_Finalize(int a1@<ebp>)
{
  int i; // esi
  CVMPIConnection *v2; // eax
  IThreadedTCPSocket *m_pSocket; // ecx
  int m_Head; // esi
  UtlLinkedListElem_t<CTCPPacket *,int> *m_pMemory; // eax
  int v6; // esi
  UtlLinkedListElem_t<CTCPPacket *,int> *v7; // eax
  TSLNodeBase_t *v8; // eax
  TSLNodeBase_t *Next; // esi
  int j; // esi
  char **v11; // eax

  CMasterBroadcaster::Term(this: &g_MasterBroadcaster);
  DistributeWork_Cancel();
  for ( i = 0; i < g_nConnections; ++i )
  {
    v2 = g_Connections[i];
    if ( v2 != nullptr )
    {
      m_pSocket = v2->m_pSocket;
      if ( m_pSocket != nullptr )
      {
        v2->m_pSocket = nullptr;
        m_pSocket->Release(this: m_pSocket);
      }
      else
      {
        ((void (__thiscall *)(CVMPIConnection *, int))v2->dtr_CVMPIConnection)(a1: g_Connections[i], a2: 1);
      }
    }
  }
  m_Head = g_VMPIMessages.m_Head;
  g_nConnections = 0;
  if ( g_VMPIMessages.m_Head != -1 )
  {
    m_pMemory = g_VMPIMessages.m_Memory.m_pMemory;
    do
    {
      v6 = m_Head;
      CTCPPacket::Release(this: (CVMPIFile_Memory *)m_pMemory[v6].m_Element);
      m_pMemory = g_VMPIMessages.m_Memory.m_pMemory;
      m_Head = g_VMPIMessages.m_Memory.m_pMemory[v6].m_Next;
    }
    while ( m_Head != -1 );
  }
  CUtlLinkedList<CPartitionInfo *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CPartitionInfo *,int>,int>>::RemoveAll(this: (CUtlLinkedList<CFileChunkPacket *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CFileChunkPacket *,int>,int> > *)&g_VMPIMessages);
  v7 = g_VMPIMessages.m_Memory.m_pMemory;
  if ( g_VMPIMessages.m_Memory.m_nGrowSize >= 0 )
  {
    if ( g_VMPIMessages.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: g_VMPIMessages.m_Memory.m_pMemory);
      v7 = nullptr;
      g_VMPIMessages.m_Memory.m_pMemory = nullptr;
    }
    g_VMPIMessages.m_Memory.m_nAllocationCount = 0;
  }
  g_VMPIMessages.m_FirstFree = -1;
  g_VMPIMessages.m_NumAlloced = 0;
  g_VMPIMessages.m_LastAlloc.index = -1;
  g_VMPIMessages.m_pElements = v7;
  CUtlLinkedList<CUtlVector<char,CUtlMemory<char,int>> *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlVector<char,CUtlMemory<char,int>> *,unsigned short>,unsigned short>>::PurgeAndDeleteElements(this: &g_PersistentPackets);
  v8 = CTSListBase::Detach(this: &g_DispatchBuffers);
  if ( v8 != nullptr )
  {
    do
    {
      Next = v8->Next;
      free(pMem: v8);
      v8 = Next;
    }
    while ( Next != nullptr );
  }
  if ( g_hKernel32DLL != nullptr )
  {
    FreeLibrary(hLibModule: g_hKernel32DLL);
    g_hKernel32DLL = nullptr;
  }
  for ( j = 0; j < g_WorkerCommandLine.m_Size; ++j )
    free(pMem: g_WorkerCommandLine.m_Memory.m_pMemory[j]);
  v11 = g_WorkerCommandLine.m_Memory.m_pMemory;
  g_WorkerCommandLine.m_Size = 0;
  if ( g_WorkerCommandLine.m_Memory.m_nGrowSize >= 0 )
  {
    if ( g_WorkerCommandLine.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: g_WorkerCommandLine.m_Memory.m_pMemory);
      v11 = nullptr;
      g_WorkerCommandLine.m_Memory.m_pMemory = nullptr;
    }
    g_WorkerCommandLine.m_Memory.m_nAllocationCount = 0;
  }
  g_WorkerCommandLine.m_pElements = v11;
  VMPI_HandleAutoRestart(a1);
}

//------------------------------------------------------------------------------
// Address: 0x10085EE0
// Name: void VMPI_GroupPackets(class CVMPIConnection __near *,void const __near * const __near *,int const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl VMPI_GroupPackets(CVMPIConnection *pConn, const void *const *pChunks, char *pChunkLengths, int nChunks)
{
  int m_Size; // edi
  int m_nAllocationCount; // eax
  void **m_pMemory; // ecx
  int v7; // eax
  void **v8; // eax
  int v9; // edi
  int v10; // eax
  int *v11; // ecx
  int v12; // eax
  int *v13; // eax
  int v14; // ebx
  unsigned int *v15; // esi
  int v16; // ecx
  int v17; // edx
  int v18; // edi
  int v19; // eax
  int v20; // edi
  char *v21; // eax
  int v22; // edi
  int v23; // eax
  int v24; // edi
  int v25; // eax
  void **v26; // ecx
  int v27; // eax
  void **v28; // edi
  int v29; // edi
  int v30; // eax
  int *v31; // ecx
  int v32; // eax
  int *v33; // edi
  CCriticalSectionLock connectionsLock; // [esp+Ch] [ebp-10h] BYREF
  int v35; // [esp+14h] [ebp-8h]
  int i; // [esp+18h] [ebp-4h]
  char *pOut; // [esp+30h] [ebp+14h]

  CCriticalSectionLock::CCriticalSectionLock(this: &connectionsLock, pCS: &g_ConnectionsCS);
  CCriticalSectionLock::Lock(this: &connectionsLock);
  if ( pConn->m_GroupedChunks.m_Size == 0 )
  {
    m_Size = pConn->m_GroupedChunks.m_Size;
    m_nAllocationCount = pConn->m_GroupedChunks.m_Memory.m_nAllocationCount;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<int,int>::Grow(
        this: (CUtlMemory<S3RGBA,int> *)&pConn->m_GroupedChunks,
        num: m_Size - m_nAllocationCount + 1);
    ++pConn->m_GroupedChunks.m_Size;
    m_pMemory = pConn->m_GroupedChunks.m_Memory.m_pMemory;
    v7 = pConn->m_GroupedChunks.m_Size - m_Size - 1;
    pConn->m_GroupedChunks.m_pElements = m_pMemory;
    if ( v7 > 0 )
      _V_memmove(
        dest: (unsigned __int8 *)&m_pMemory[m_Size + 1],
        src: (unsigned __int8 *)&m_pMemory[m_Size],
        count: 4 * v7);
    v8 = &pConn->m_GroupedChunks.m_Memory.m_pMemory[m_Size];
    if ( v8 != nullptr )
      *v8 = g_GroupedPacketHeader;
    v9 = pConn->m_GroupedChunkLengths.m_Size;
    v10 = pConn->m_GroupedChunkLengths.m_Memory.m_nAllocationCount;
    if ( v9 + 1 > v10 )
      CUtlMemory<int,int>::Grow(this: (CUtlMemory<S3RGBA,int> *)&pConn->m_GroupedChunkLengths, num: v9 - v10 + 1);
    ++pConn->m_GroupedChunkLengths.m_Size;
    v11 = pConn->m_GroupedChunkLengths.m_Memory.m_pMemory;
    v12 = pConn->m_GroupedChunkLengths.m_Size - v9 - 1;
    pConn->m_GroupedChunkLengths.m_pElements = v11;
    if ( v12 > 0 )
      _V_memmove(dest: (unsigned __int8 *)&v11[v9 + 1], src: (unsigned __int8 *)&v11[v9], count: 4 * v12);
    v13 = &pConn->m_GroupedChunkLengths.m_Memory.m_pMemory[v9];
    if ( v13 != nullptr )
      *v13 = 2;
  }
  v14 = nChunks;
  v15 = (unsigned int *)pChunkLengths;
  v16 = 0;
  v17 = 0;
  v18 = 0;
  v19 = 0;
  if ( nChunks >= 2 )
  {
    do
    {
      v16 += *(_DWORD *)&pChunkLengths[4 * v19];
      v17 += *(_DWORD *)&pChunkLengths[4 * v19 + 4];
      v19 += 2;
    }
    while ( v19 < nChunks - 1 );
    v14 = nChunks;
  }
  if ( v19 < v14 )
    v18 = *(_DWORD *)&pChunkLengths[4 * v19];
  v20 = v17 + v16 + v18;
  v35 = v20 + 4;
  v21 = (char *)MemAlloc_Alloc(nSize: v20 + 4);
  *(_DWORD *)v21 = v20;
  pOut = v21;
  v22 = 4;
  if ( v14 > 0 )
  {
    v23 = (char *)pChunks - pChunkLengths;
    for ( i = (char *)pChunks - pChunkLengths; ; v23 = i )
    {
      memcpy(dst: (unsigned __int8 *)&pOut[v22], src: *(unsigned __int8 **)((char *)v15 + v23), count: *v15);
      v22 += *v15++;
      if ( --v14 == 0 )
        break;
    }
  }
  v24 = pConn->m_GroupedChunks.m_Size;
  v25 = pConn->m_GroupedChunks.m_Memory.m_nAllocationCount;
  if ( v24 + 1 > v25 )
    CUtlMemory<int,int>::Grow(this: (CUtlMemory<S3RGBA,int> *)&pConn->m_GroupedChunks, num: v24 - v25 + 1);
  ++pConn->m_GroupedChunks.m_Size;
  v26 = pConn->m_GroupedChunks.m_Memory.m_pMemory;
  v27 = pConn->m_GroupedChunks.m_Size - v24 - 1;
  pConn->m_GroupedChunks.m_pElements = v26;
  if ( v27 > 0 )
    _V_memmove(dest: (unsigned __int8 *)&v26[v24 + 1], src: (unsigned __int8 *)&v26[v24], count: 4 * v27);
  v28 = &pConn->m_GroupedChunks.m_Memory.m_pMemory[v24];
  if ( v28 != nullptr )
    *v28 = pOut;
  v29 = pConn->m_GroupedChunkLengths.m_Size;
  v30 = pConn->m_GroupedChunkLengths.m_Memory.m_nAllocationCount;
  if ( v29 + 1 > v30 )
    CUtlMemory<int,int>::Grow(this: (CUtlMemory<S3RGBA,int> *)&pConn->m_GroupedChunkLengths, num: v29 - v30 + 1);
  ++pConn->m_GroupedChunkLengths.m_Size;
  v31 = pConn->m_GroupedChunkLengths.m_Memory.m_pMemory;
  v32 = pConn->m_GroupedChunkLengths.m_Size - v29 - 1;
  pConn->m_GroupedChunkLengths.m_pElements = v31;
  if ( v32 > 0 )
    _V_memmove(dest: (unsigned __int8 *)&v31[v29 + 1], src: (unsigned __int8 *)&v31[v29], count: 4 * v32);
  v33 = &pConn->m_GroupedChunkLengths.m_Memory.m_pMemory[v29];
  if ( v33 != nullptr )
    *v33 = v35;
  CCriticalSectionLock::~CCriticalSectionLock(this: &connectionsLock);
}

//------------------------------------------------------------------------------
// Address: 0x100860F0
// Name: void VMPI_SetupAutoRestartParameters(int,char __near * __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl VMPI_SetupAutoRestartParameters(int argc, char **argv)
{
  int v2; // edi
  char *v3; // ebx
  unsigned int v4; // esi
  char *v5; // [esp+4h] [ebp-4h]

  if ( VMPI_FindArg(argc, argv, pName: g_VMPIParams[6].m_pName, pDefault: defaultValue) != nullptr )
  {
    v2 = 0;
    g_OriginalCommandLineParameters.m_Size = 0;
    CUtlVector<dfacebrushlist_t,CUtlMemory<dfacebrushlist_t,int>>::InsertMultipleBefore(
      this: (CUtlVector<S3RGBA,CUtlMemory<S3RGBA,int> > *)&g_OriginalCommandLineParameters,
      elem: 0,
      num: argc);
    if ( argc > 0 )
    {
      do
      {
        v3 = argv[v2];
        v4 = _V_strlen(str: v3) + 1;
        v5 = (char *)MemAlloc_Alloc(nSize: v4);
        V_strncpy(pDest: v5, pSrc: v3, maxLen: v4);
        g_OriginalCommandLineParameters.m_Memory.m_pMemory[v2++] = v5;
      }
      while ( v2 < argc );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10086270
// Name: void InternalHandleSocketErrors(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InternalHandleSocketErrors()
{
  int v0; // esi
  int m_Head; // eax
  CVMPIConnection **m_pMemory; // ebx
  UtlLinkedListElem_t<CVMPIConnection *,int> *v3; // edx
  CVMPIConnection **v4; // ecx
  int v5; // eax
  UtlLinkedListElem_t<CVMPIConnection *,int> *v6; // eax
  int m_Size; // edi
  CUtlVector<CVMPIConnection *,CUtlMemory<CVMPIConnection *,int> > errorSockets; // [esp+Ch] [ebp-1Ch] BYREF
  CCriticalSectionLock csLock; // [esp+20h] [ebp-8h] BYREF

  v0 = 0;
  memset(&errorSockets, 0, sizeof(errorSockets));
  CCriticalSectionLock::CCriticalSectionLock(this: &csLock, pCS: &g_ErrorSocketsCS);
  CCriticalSectionLock::Lock(this: &csLock);
  CUtlVector<dfacebrushlist_t,CUtlMemory<dfacebrushlist_t,int>>::InsertMultipleBefore(
    this: (CUtlVector<S3RGBA,CUtlMemory<S3RGBA,int> > *)&errorSockets,
    elem: 0,
    num: g_ErrorSockets.m_ElementCount);
  m_Head = g_ErrorSockets.m_Head;
  m_pMemory = errorSockets.m_Memory.m_pMemory;
  if ( g_ErrorSockets.m_Head != -1 )
  {
    v3 = g_ErrorSockets.m_Memory.m_pMemory;
    v4 = errorSockets.m_Memory.m_pMemory;
    do
    {
      v5 = m_Head;
      *v4 = v3[v5].m_Element;
      v3 = g_ErrorSockets.m_Memory.m_pMemory;
      m_Head = g_ErrorSockets.m_Memory.m_pMemory[v5].m_Next;
      ++v4;
    }
    while ( m_Head != -1 );
  }
  CUtlLinkedList<CPartitionInfo *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CPartitionInfo *,int>,int>>::RemoveAll(this: (CUtlLinkedList<CFileChunkPacket *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CFileChunkPacket *,int>,int> > *)&g_ErrorSockets);
  v6 = g_ErrorSockets.m_Memory.m_pMemory;
  if ( g_ErrorSockets.m_Memory.m_nGrowSize >= 0 )
  {
    if ( g_ErrorSockets.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: g_ErrorSockets.m_Memory.m_pMemory);
      v6 = nullptr;
      g_ErrorSockets.m_Memory.m_pMemory = nullptr;
    }
    g_ErrorSockets.m_Memory.m_nAllocationCount = 0;
  }
  g_ErrorSockets.m_FirstFree = -1;
  g_ErrorSockets.m_NumAlloced = 0;
  g_ErrorSockets.m_LastAlloc.index = -1;
  g_ErrorSockets.m_pElements = v6;
  CCriticalSectionLock::Unlock(this: &csLock);
  m_Size = errorSockets.m_Size;
  if ( errorSockets.m_Size > 0 )
  {
    do
    {
      CVMPIConnection::HandleDisconnect(this: m_pMemory[v0]);
      m_pMemory[v0]->Release(this: m_pMemory[v0], a2: true);
      ++v0;
    }
    while ( v0 < m_Size );
  }
  UpdateActiveConnectionsText();
  CCriticalSectionLock::~CCriticalSectionLock(this: &csLock);
  if ( errorSockets.m_Memory.m_nGrowSize >= 0 && m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x10086390
// Name: bool VMPI_GetNextMessage(class MessageBuffer __near *,int __near *,unsigned long)
// Source: json
//------------------------------------------------------------------------------
char __cdecl VMPI_GetNextMessage(MessageBuffer *pBuf, int *pSource, CTCPPacket *startTimeout)
{
  DWORD v3; // eax
  CTCPPacket *v4; // eax
  int m_Head; // edi
  int v7; // esi
  CTCPPacket *m_Element; // ebx
  int i; // eax
  signed int m_Size; // esi
  int j; // edi
  unsigned int v12; // ebx
  unsigned __int8 *v13; // eax
  int v14; // edx
  CTCPPacket *v15; // edi
  unsigned int v16; // ecx
  CTCPPacket **m_pMemory; // edx
  CTCPPacket **v18; // eax
  CTCPPacket *const *v19; // edi
  int v20; // edi
  int v21; // ebx
  CTCPPacket *v22; // esi
  int m_Len; // eax
  int v24; // ecx
  int v25; // eax
  char szPacketID[64]; // [esp+Ch] [ebp-ACh] BYREF
  char szSubPacketID[64]; // [esp+4Ch] [ebp-6Ch] BYREF
  void *handles[2]; // [esp+8Ch] [ebp-2Ch] BYREF
  CCriticalSectionLock csLock; // [esp+94h] [ebp-24h] BYREF
  CUtlVector<CTCPPacket *,CUtlMemory<CTCPPacket *,int> > groupedPackets; // [esp+9Ch] [ebp-1Ch] BYREF
  int iCurOffset; // [esp+B0h] [ebp-8h]
  unsigned int startTime; // [esp+B4h] [ebp-4h]
  CVMPIFile_Memory *pPacket; // [esp+C8h] [ebp+10h]

  handles[0] = CTCPPacket::GetUserData(this: &g_ErrorSocketsEvent);
  handles[1] = CTCPPacket::GetUserData(this: &g_VMPIMessagesEvent);
  startTime = _Plat_MSTime();
  v3 = WaitForMultipleObjects(nCount: 2u, lpHandles: handles, bWaitAll: false, dwMilliseconds: (DWORD)startTimeout);
  if ( v3 == 258 )
    return 0;
  while ( v3 == 0 )
  {
    InternalHandleSocketErrors();
    v4 = (CTCPPacket *)(_Plat_MSTime() - startTime);
    if ( v4 >= startTimeout )
      return 0;
    v3 = WaitForMultipleObjects(
           nCount: 2u,
           lpHandles: handles,
           bWaitAll: false,
           dwMilliseconds: (char *)startTimeout - (char *)v4);
    if ( v3 == 258 )
      return 0;
  }
  if ( v3 != 1 )
  {
    _Error(a1: "VMPI_GetNextMessage: WaitForSingleObject returned %lu", v3);
    return 0;
  }
  CCriticalSectionLock::CCriticalSectionLock(this: &csLock, pCS: &g_VMPIMessagesCS);
  CCriticalSectionLock::Lock(this: &csLock);
  m_Head = g_VMPIMessages.m_Head;
  v7 = g_VMPIMessages.m_Head;
  m_Element = g_VMPIMessages.m_Memory.m_pMemory[g_VMPIMessages.m_Head].m_Element;
  pPacket = (CVMPIFile_Memory *)m_Element;
  CUtlLinkedList<CThreadedTCPSocket::SendData_t *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CThreadedTCPSocket::SendData_t *,int>,int>>::Unlink(
    this: (CUtlLinkedList<CFileChunkPacket *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CFileChunkPacket *,int>,int> > *)&g_VMPIMessages,
    elem: g_VMPIMessages.m_Head);
  g_VMPIMessages.m_Memory.m_pMemory[v7].m_Next = g_VMPIMessages.m_FirstFree;
  g_VMPIMessages.m_FirstFree = m_Head;
  for ( i = m_Element->m_Len; i >= 6; m_Element = v22 )
  {
    if ( m_Element->m_Data[0] != 27 || m_Element->m_Data[1] != 4 )
      break;
    m_Size = 0;
    memset(&groupedPackets, 0, sizeof(groupedPackets));
    for ( j = 2; ; j = iCurOffset )
    {
      v12 = *(_DWORD *)&m_Element->m_Data[j];
      if ( (int)(v12 + j) > i )
        _Error(a1: "Invalid chunked packet\n");
      iCurOffset = j + 4;
      v13 = (unsigned __int8 *)MemAlloc_Alloc(nSize: v12 + 11);
      v14 = iCurOffset;
      v15 = (CTCPPacket *)v13;
      *((_DWORD *)v13 + 1) = v12;
      *(_DWORD *)v13 = pPacket->__vftable;
      memcpy(dst: v13 + 8, src: (unsigned __int8 *)&pPacket->m_DataLen + v14, count: v12);
      v16 = m_Size;
      startTime = m_Size;
      if ( m_Size + 1 > groupedPackets.m_Memory.m_nAllocationCount )
      {
        CUtlMemory<int,int>::Grow(
          this: (CUtlMemory<S3RGBA,int> *)&groupedPackets,
          num: m_Size - groupedPackets.m_Memory.m_nAllocationCount + 1);
        m_Size = groupedPackets.m_Size;
        v16 = startTime;
      }
      m_pMemory = groupedPackets.m_Memory.m_pMemory;
      groupedPackets.m_Size = ++m_Size;
      groupedPackets.m_pElements = groupedPackets.m_Memory.m_pMemory;
      if ( (int)(m_Size - v16 - 1) > 0 )
      {
        _V_memmove(
          dest: (unsigned __int8 *)&groupedPackets.m_Memory.m_pMemory[v16 + 1],
          src: (unsigned __int8 *)&groupedPackets.m_Memory.m_pMemory[v16],
          count: 4 * (m_Size - v16 - 1));
        m_pMemory = groupedPackets.m_Memory.m_pMemory;
        v16 = startTime;
      }
      v18 = &m_pMemory[v16];
      if ( v18 != nullptr )
        *v18 = v15;
      i = (int)pPacket->m_pData;
      iCurOffset += v12;
      if ( iCurOffset + 4 > i )
        break;
      m_Element = (CTCPPacket *)pPacket;
    }
    if ( m_Size > 0 )
    {
      v19 = &groupedPackets.m_Memory.m_pMemory[m_Size - 1];
      do
      {
        CUtlLinkedList<CTCPPacket *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CTCPPacket *,int>,int>>::AddToHead(
          this: &g_VMPIMessages,
          src: v19--);
        --m_Size;
      }
      while ( m_Size != 0 );
    }
    CTCPPacket::Release(this: pPacket);
    CUtlVector<dleafambientlighting_t,CUtlMemory<dleafambientlighting_t,int>>::~CUtlVector<dleafambientlighting_t,CUtlMemory<dleafambientlighting_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&groupedPackets);
    v20 = g_VMPIMessages.m_Head;
    v21 = g_VMPIMessages.m_Head;
    v22 = g_VMPIMessages.m_Memory.m_pMemory[g_VMPIMessages.m_Head].m_Element;
    pPacket = (CVMPIFile_Memory *)v22;
    CUtlLinkedList<CThreadedTCPSocket::SendData_t *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CThreadedTCPSocket::SendData_t *,int>,int>>::Unlink(
      this: (CUtlLinkedList<CFileChunkPacket *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CFileChunkPacket *,int>,int> > *)&g_VMPIMessages,
      elem: g_VMPIMessages.m_Head);
    g_VMPIMessages.m_Memory.m_pMemory[v21].m_Next = g_VMPIMessages.m_FirstFree;
    g_VMPIMessages.m_FirstFree = v20;
    i = v22->m_Len;
  }
  if ( g_VMPIMessages.m_ElementCount > 0 )
    CEvent::SetEvent(this: &g_VMPIMessagesEvent);
  CCriticalSectionLock::Unlock(this: &csLock);
  MessageBuffer::setLen(this: pBuf, nlen: m_Element->m_Len);
  memcpy(dst: (unsigned __int8 *)pBuf->data, src: (unsigned __int8 *)m_Element->m_Data, count: m_Element->m_Len);
  if ( g_bSuperSpewEnabled )
  {
    m_Len = m_Element->m_Len;
    if ( m_Len < 2 )
      v24 = -1;
    else
      v24 = pBuf->data[1];
    if ( m_Len < 1 )
      v25 = -1;
    else
      v25 = *pBuf->data;
    CVMPIPacketIDReg::Lookup(
      nPacketID: v25,
      nSubPacketID: v24,
      pPacketIDString: szPacketID,
      nPacketIDStringSize: 64,
      pSubPacketIDString: szSubPacketID,
      nSubPacketIDStringSize: 64);
    VMPI_SuperSpew(pMsg: "Received a packet (packetID %s, subPacketID %s)\n", szPacketID, szSubPacketID);
  }
  *pSource = (int)CTCPPacket::GetUserData(this: (CEvent *)m_Element);
  ++g_nMessagesReceived;
  g_nBytesReceived += m_Element->m_Len + 4;
  CTCPPacket::Release(this: (CVMPIFile_Memory *)m_Element);
  CCriticalSectionLock::~CCriticalSectionLock(this: &csLock);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100866E0
// Name: bool VMPI_DispatchNextMessage(unsigned long)
// Source: json
//------------------------------------------------------------------------------
char __cdecl VMPI_DispatchNextMessage(CTCPPacket *timeout)
{
  TSLNodeBase_t *v1; // eax
  MessageBuffer *v2; // esi
  MessageBuffer *v3; // eax
  char v4; // bl
  char v5; // al
  TSLNodeBase_t *v6; // eax
  int iSource; // [esp+Ch] [ebp-4h] BYREF

  v1 = CTSListBase::Pop(this: &g_DispatchBuffers);
  if ( v1 != nullptr )
  {
    v2 = *((MessageBuffer **)&v1->Next + 1);
    free(pMem: v1);
  }
  else
  {
    v3 = (MessageBuffer *)MemAlloc_Alloc(nSize: 0x10u);
    if ( v3 != nullptr )
      v2 = MessageBuffer::MessageBuffer(this: v3);
    else
      v2 = nullptr;
  }
  v4 = 1;
  if ( VMPI_GetNextMessage(pBuf: v2, pSource: &iSource, startTimeout: timeout) != 0 )
  {
    while ( 1 )
    {
      if ( ConCommandBase::GetName(this: (CVTFTexture *)v2) >= 1 )
      {
        v5 = *v2->data;
        if ( (unsigned __int8)v5 < 0x20u
          && g_VMPIDispatch[v5] != nullptr
          && g_VMPIDispatch[v5](a1: v2, a2: iSource, a3: v5) )
        {
          break;
        }
      }
      if ( VMPI_GetNextMessage(pBuf: v2, pSource: &iSource, startTimeout: timeout) == 0 )
        goto LABEL_12;
    }
  }
  else
  {
LABEL_12:
    v4 = 0;
  }
  v6 = (TSLNodeBase_t *)MemAlloc_Alloc(nSize: 8u);
  if ( v6 != nullptr )
  {
    *((_DWORD *)&v6->Next + 1) = v2;
    CTSListBase::Push(this: &g_DispatchBuffers, pNode: v6);
  }
  else
  {
    CTSListBase::Push(this: &g_DispatchBuffers, pNode: nullptr);
  }
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x100867D0
// Name: bool VMPI_SendChunks(void const __near * const __near *,int const __near *,int,int,int)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl VMPI_SendChunks(
        const void *const *pChunks,
        int *pChunkLengths,
        int nChunks,
        int iDest,
        char fVMPISendFlags)
{
  int i; // esi
  CUtlVector<char,CUtlMemory<char,int> > *v7; // ebx
  int j; // esi
  CUtlVector<char,CUtlMemory<char,int> > *v9; // eax
  int *v10; // esi
  unsigned __int16 v11; // ax
  int v12; // esi
  UtlLinkedListElem_t<CUtlVector<char,CUtlMemory<char,int> > *,unsigned short> *v13; // eax
  int v14; // ecx
  int v15; // eax
  CVMPIConnection *v16; // ebx
  IThreadedTCPSocket *m_pSocket; // ecx
  CCriticalSectionLock v18; // [esp+Ch] [ebp-10h] BYREF
  CCriticalSectionLock csLock; // [esp+14h] [ebp-8h] BYREF
  int iDesta; // [esp+30h] [ebp+14h]

  if ( iDest == -2 )
  {
    CCriticalSectionLock::CCriticalSectionLock(this: &csLock, pCS: &g_ConnectionsCS);
    CCriticalSectionLock::Lock(this: &csLock);
    for ( i = 0; i < g_nConnections; ++i )
      VMPI_SendChunks(pChunks, pChunkLengths, nChunks, iDest: i, fVMPISendFlags: 0);
    CCriticalSectionLock::~CCriticalSectionLock(this: &csLock);
    return true;
  }
  if ( iDest == -3 )
  {
    CCriticalSectionLock::CCriticalSectionLock(this: &v18, pCS: &g_ConnectionsCS);
    CCriticalSectionLock::Lock(this: &v18);
    CCriticalSectionLock::CCriticalSectionLock(this: &csLock, pCS: &g_PersistentPacketsCS);
    CCriticalSectionLock::Lock(this: &csLock);
    v7 = nullptr;
    for ( j = 0; j < g_nConnections; ++j )
      VMPI_SendChunks(pChunks, pChunkLengths, nChunks, iDest: j, fVMPISendFlags: 0);
    v9 = (CUtlVector<char,CUtlMemory<char,int> > *)MemAlloc_Alloc(nSize: 0x14u);
    if ( v9 != nullptr )
    {
      v9->m_Memory.m_pMemory = nullptr;
      v9->m_Memory.m_nAllocationCount = 0;
      v9->m_Memory.m_nGrowSize = 0;
      v9->m_Size = 0;
      v9->m_pElements = nullptr;
      v7 = v9;
    }
    if ( nChunks > 0 )
    {
      v10 = pChunkLengths;
      for ( iDesta = nChunks; iDesta != 0; --iDesta )
      {
        CUtlVector<char,CUtlMemory<char,int>>::InsertMultipleBefore(
          this: v7,
          elem: v7->m_Size,
          num: *v10,
          pToInsert: *(const char **)((char *)v10 + (char *)pChunks - (char *)pChunkLengths));
        ++v10;
      }
    }
    v11 = CUtlLinkedList<CUtlVector<char,CUtlMemory<char,int>> *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlVector<char,CUtlMemory<char,int>> *,unsigned short>,unsigned short>>::AllocInternal(
            this: &g_PersistentPackets,
            multilist: false);
    v12 = v11;
    if ( v11 != 0xFFFF )
    {
      CUtlLinkedList<void (__cdecl *)(void),unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<void (__cdecl *)(void),unsigned short>,unsigned short>>::LinkBefore(
        this: &g_PersistentPackets,
        before: 0xFFFFu,
        elem: v11);
      v13 = &g_PersistentPackets.m_Memory.m_pMemory[v12];
      if ( v13 != nullptr )
        v13->m_Element = v7;
    }
    CCriticalSectionLock::~CCriticalSectionLock(this: &csLock);
    CCriticalSectionLock::~CCriticalSectionLock(this: &v18);
    return true;
  }
  else
  {
    ++g_nMessagesSent;
    v14 = g_nBytesSent + 4;
    v15 = 0;
    g_nBytesSent += 4;
    if ( nChunks > 0 )
    {
      do
      {
        v14 += pChunkLengths[v15++];
        g_nBytesSent = v14;
      }
      while ( v15 < nChunks );
    }
    v16 = g_Connections[iDest];
    if ( v16 == nullptr )
      return false;
    if ( VMPI_FilterPacketsForServiceDownloader(pConnection: v16, pChunks, pChunkLengths, nChunks) != 0 )
      return true;
    m_pSocket = v16->m_pSocket;
    if ( m_pSocket != nullptr )
    {
      if ( g_bGroupPackets && (fVMPISendFlags & 1) != 0 )
      {
        VMPI_GroupPackets(pConn: v16, pChunks, (char *)pChunkLengths, nChunks);
        return true;
      }
      else
      {
        return m_pSocket->SendChunks(this: m_pSocket, a2: pChunks, a3: pChunkLengths, a4: nChunks);
      }
    }
    else
    {
      return false;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100869D0
// Name: bool VMPI_Send2Chunks(void const __near *,int,void const __near *,int,int,int)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl VMPI_Send2Chunks(
        const void *pChunk1,
        int chunk1Len,
        const void *pChunk2,
        int chunk2Len,
        int iDest,
        char fVMPISendFlags)
{
  const void *pChunks[2]; // [esp+0h] [ebp-10h] BYREF
  int len[2]; // [esp+8h] [ebp-8h] BYREF

  pChunks[1] = pChunk2;
  pChunks[0] = pChunk1;
  len[0] = chunk1Len;
  len[1] = chunk2Len;
  return VMPI_SendChunks(pChunks, pChunkLengths: len, nChunks: 2, iDest, fVMPISendFlags);
}

//------------------------------------------------------------------------------
// Address: 0x10086A10
// Name: bool VMPI_Send3Chunks(void const __near *,int,void const __near *,int,void const __near *,int,int,int)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl VMPI_Send3Chunks(
        const void *pChunk1,
        int chunk1Len,
        const void *pChunk2,
        int chunk2Len,
        const void *pChunk3,
        int chunk3Len,
        int iDest,
        char fVMPISendFlags)
{
  const void *pChunks[3]; // [esp+0h] [ebp-18h] BYREF
  int len[3]; // [esp+Ch] [ebp-Ch] BYREF

  pChunks[0] = pChunk1;
  pChunks[1] = pChunk2;
  len[0] = chunk1Len;
  pChunks[2] = pChunk3;
  len[1] = chunk2Len;
  len[2] = chunk3Len;
  return VMPI_SendChunks(pChunks, pChunkLengths: len, nChunks: 3, iDest, fVMPISendFlags);
}

//------------------------------------------------------------------------------
// Address: 0x10086A60
// Name: void VMPI_AddDisconnectHandler(void (*)(int,char const __near *))
// Source: json
//------------------------------------------------------------------------------
void __cdecl VMPI_AddDisconnectHandler(void (__cdecl *handler)(int, const char *))
{
  CUtlLinkedList<void (__cdecl *)(int,char const *),int,0,int,CUtlMemory<UtlLinkedListElem_t<void (__cdecl *)(int,char const *),int>,int>>::AddToTail(
    this: &g_DisconnectHandlers,
    src: &handler);
}

//------------------------------------------------------------------------------
// Address: 0x10086A80
// Name: void VMPI_SetMachineName(int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl VMPI_SetMachineName(int iProc, const char *pName)
{
  CVMPIConnection *v2; // esi

  if ( iProc >= 0 && iProc < g_nConnections )
  {
    v2 = g_Connections[iProc];
    if ( v2 != nullptr )
    {
      CUtlVector<char,CUtlMemory<char,int>>::CopyArray(
        this: (CUtlVector<unsigned char,CUtlMemory<unsigned char,int> > *)&v2->m_MachineName,
        pArray: (const unsigned __int8 *)pName,
        size: strlen(pName) + 1);
      v2->m_bNameSet = true;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10086AD0
// Name: public: CVMPIConnection::CVMPIConnection(int)
// Source: json
//------------------------------------------------------------------------------
CVMPIConnection *__thiscall CVMPIConnection::CVMPIConnection(CVMPIConnection *this, int iConnection)
{
  char str[512]; // [esp+Ch] [ebp-200h] BYREF

  this->__vftable = (CVMPIConnection_vtbl *)&CVMPIConnection::`vftable';
  this->m_GroupedChunkLengths.m_Memory.m_pMemory = nullptr;
  this->m_GroupedChunkLengths.m_Memory.m_nAllocationCount = 0;
  this->m_GroupedChunkLengths.m_Memory.m_nGrowSize = 0;
  this->m_GroupedChunkLengths.m_Size = 0;
  this->m_GroupedChunkLengths.m_pElements = nullptr;
  this->m_GroupedChunks.m_Memory.m_pMemory = nullptr;
  this->m_GroupedChunks.m_Memory.m_nAllocationCount = 0;
  this->m_GroupedChunks.m_Memory.m_nGrowSize = 0;
  this->m_GroupedChunks.m_Size = 0;
  this->m_GroupedChunks.m_pElements = nullptr;
  this->m_MachineName.m_Memory.m_pMemory = nullptr;
  this->m_MachineName.m_Memory.m_nAllocationCount = 0;
  this->m_MachineName.m_Memory.m_nGrowSize = 0;
  this->m_MachineName.m_Size = 0;
  this->m_MachineName.m_pElements = nullptr;
  this->m_ErrorString.m_Memory.m_pMemory = nullptr;
  this->m_ErrorString.m_Memory.m_nAllocationCount = 0;
  this->m_ErrorString.m_Memory.m_nGrowSize = 0;
  this->m_ErrorString.m_Size = 0;
  this->m_ErrorString.m_pElements = nullptr;
  this->m_iConnection = iConnection;
  this->m_pSocket = nullptr;
  this->m_bIsAService = false;
  V_snprintf(pDest: str, maxLen: 0x200u, pFormat: "%d", iConnection);
  CUtlVector<char,CUtlMemory<char,int>>::CopyArray(
    this: (CUtlVector<unsigned char,CUtlMemory<unsigned char,int> > *)&this->m_MachineName,
    pArray: (const unsigned __int8 *)str,
    size: strlen(str) + 1);
  *(_WORD *)&this->m_bNameSet = 0;
  this->m_JobWorkerID = -1;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10086B90
// Name: public: virtual void CVMPIConnection::Init(class IThreadedTCPSocket __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVMPIConnection::Init(CVMPIConnection *this, IThreadedTCPSocket *pSocket)
{
  this->m_pSocket = pSocket;
}

//------------------------------------------------------------------------------
// Address: 0x10086BA0
// Name: public: virtual int CVMPIConnection::GetConnectionID(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CVMPIConnection::GetConnectionID(CVMPIConnection *this)
{
  return this->m_iConnection;
}

//------------------------------------------------------------------------------
// Address: 0x10086BB0
// Name: public: virtual void CVMPIConnection::Release(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVMPIConnection::Release(CVMPIConnection *this, bool bForce)
{
  int m_iConnection; // esi
  CVMPIConnection *v3; // ecx

  if ( !this->m_bInErrorState || bForce )
  {
    m_iConnection = this->m_iConnection;
    this->m_pSocket = nullptr;
    v3 = g_Connections[m_iConnection];
    if ( v3 != nullptr )
      ((void (__thiscall *)(CVMPIConnection *, int))v3->dtr_CVMPIConnection)(a1: v3, a2: 1);
    g_Connections[m_iConnection] = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10086E50
// Name: public: virtual void CVMPIConnection::OnPacketReceived(class CTCPPacket __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVMPIConnection::OnPacketReceived(CVMPIConnection *this, CTCPPacket *pPacket)
{
  CCriticalSectionLock csLock; // [esp+0h] [ebp-8h] BYREF

  CTCPPacket::SetUserData(this: pPacket, userData: this->m_iConnection);
  CCriticalSectionLock::CCriticalSectionLock(this: &csLock, pCS: &g_VMPIMessagesCS);
  CCriticalSectionLock::Lock(this: &csLock);
  CUtlLinkedList<CTCPPacket *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CTCPPacket *,int>,int>>::AddToTail(
    this: &g_VMPIMessages,
    src: &pPacket);
  if ( g_VMPIMessages.m_ElementCount == 1 )
    CEvent::SetEvent(this: &g_VMPIMessagesEvent);
  CCriticalSectionLock::~CCriticalSectionLock(this: &csLock);
}

//------------------------------------------------------------------------------
// Address: 0x10086EB0
// Name: public: virtual void CVMPIConnection::OnError(int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVMPIConnection::OnError(CVMPIConnection *this, int errorCode, const char *pErrorString)
{
  const unsigned __int8 *v3; // edi
  CCriticalSectionLock csLock; // [esp+8h] [ebp-8h] BYREF

  v3 = (const unsigned __int8 *)pErrorString;
  if ( !g_bMPIMaster )
    _Msg(a1: "%s - CVMPIConnection::OnError( %s )\n", this->m_MachineName.m_Memory.m_pMemory, pErrorString);
  CCriticalSectionLock::CCriticalSectionLock(this: &csLock, pCS: &g_ErrorSocketsCS);
  CCriticalSectionLock::Lock(this: &csLock);
  if ( !this->m_bInErrorState )
  {
    this->m_bInErrorState = true;
    CUtlVector<char,CUtlMemory<char,int>>::CopyArray(
      this: (CUtlVector<unsigned char,CUtlMemory<unsigned char,int> > *)&this->m_ErrorString,
      pArray: v3,
      size: strlen((const char *)v3) + 1);
    pErrorString = (const char *)this;
    CUtlLinkedList<CVMPIConnection *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CVMPIConnection *,int>,int>>::AddToTail(
      this: &g_ErrorSockets,
      src: (CVMPIConnection *const *)&pErrorString);
    CEvent::SetEvent(this: &g_ErrorSocketsEvent);
    InterlockedIncrement(lpAddend: &this->m_ErrorSignal);
  }
  CCriticalSectionLock::~CCriticalSectionLock(this: &csLock);
}

//------------------------------------------------------------------------------
// Address: 0x10086F50
// Name: public: virtual class ITCPSocketHandler __near * CVMPIConnectionCreator::CreateNewHandler(void)
// Source: json
//------------------------------------------------------------------------------
CVMPIConnection *__thiscall CVMPIConnectionCreator::CreateNewHandler(CVMPIConnectionCreator *this)
{
  int v1; // edi
  CVMPIConnection *v2; // eax
  CVMPIConnection *result; // eax
  _DWORD *v4; // eax
  _DWORD *v5; // esi
  int v6; // edi
  int v7; // ecx
  char pDest[512]; // [esp+8h] [ebp-204h] BYREF
  int i; // [esp+208h] [ebp-4h]

  v1 = 0;
  if ( g_nConnections <= 0 )
  {
LABEL_4:
    v2 = (CVMPIConnection *)MemAlloc_Alloc(nSize: 0x6Cu);
    if ( v2 != nullptr )
      result = CVMPIConnection::CVMPIConnection(this: v2, iConnection: g_nConnections);
    else
      result = nullptr;
    v7 = g_nConnections;
    g_Connections[g_nConnections] = result;
    g_nConnections = v7 + 1;
  }
  else
  {
    while ( g_Connections[v1] != nullptr )
    {
      if ( ++v1 >= g_nConnections )
        goto LABEL_4;
    }
    i = v1;
    v4 = MemAlloc_Alloc(nSize: 0x6Cu);
    v5 = v4;
    if ( v4 != nullptr )
    {
      *v4 = &CVMPIConnection::`vftable';
      v4[3] = 0;
      v4[4] = 0;
      v4[5] = 0;
      v4[6] = 0;
      v4[7] = 0;
      v4[8] = 0;
      v4[9] = 0;
      v4[10] = 0;
      v4[11] = 0;
      v4[12] = 0;
      v4[13] = 0;
      v4[14] = 0;
      v4[15] = 0;
      v4[16] = 0;
      v4[17] = 0;
      v4[18] = 0;
      v4[19] = 0;
      v4[20] = 0;
      v4[21] = 0;
      v4[22] = 0;
      v4[24] = v1;
      v4[25] = 0;
      *((_BYTE *)v4 + 8) = 0;
      V_snprintf(pDest, maxLen: 0x200u, pFormat: "%d", v1);
      CUtlVector<char,CUtlMemory<char,int>>::CopyArray(
        this: (CUtlVector<unsigned char,CUtlMemory<unsigned char,int> > *)(v5 + 13),
        pArray: (const unsigned __int8 *)pDest,
        size: strlen(pDest) + 1);
      v6 = i;
      *((_WORD *)v5 + 52) = 0;
      v5[1] = -1;
      g_Connections[v6] = (CVMPIConnection *)v5;
      return (CVMPIConnection *)v5;
    }
    else
    {
      g_Connections[v1] = nullptr;
      return nullptr;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100870A0
// Name: bool VMPI_InternalDispatchFn(class MessageBuffer __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
char __cdecl VMPI_InternalDispatchFn(CVTFTexture *pBuf, int iSource)
{
  char v2; // al
  bool v4; // al
  unsigned int v5; // esi
  char *v6; // edi
  int m_Size; // eax
  int v8; // esi
  char **m_pMemory; // ecx
  int v10; // eax
  char **v11; // eax
  char pOut[4096]; // [esp+4h] [ebp-1008h] BYREF
  int i; // [esp+1004h] [ebp-8h]
  int p; // [esp+1008h] [ebp-4h] BYREF

  if ( ConCommandBase::GetName(this: pBuf) < 2 )
    return 0;
  v2 = BYTE1(pBuf->dtr_IVTFTexture);
  switch ( v2 )
  {
    case 1:
      if ( ConCommandBase::GetName(this: pBuf) >= 3 )
      {
        VMPI_SuperSpew(pMsg: "Received SUBPACKET_MACHINE_NAME (%s).\n", (const char *)&pBuf->dtr_IVTFTexture + 2);
        VMPI_SetMachineName(iProc: iSource, pName: (const char *)&pBuf->dtr_IVTFTexture + 2);
        return 1;
      }
      VMPI_SuperSpew(pMsg: "Received invalid SUBPACKET_MACHINE_NAME packet (not long enough!)\n");
      return 0;
    case 3:
      if ( g_bVMPISDKModeSet )
        v4 = g_bVMPISDKMode;
      else
        v4 = !VMPI_CheckForNonSDKExecutables();
      if ( !v4 )
        _Warning(a1: "Worker %d is running in SDK mode (and the master is not)!\n");
      return 1;
    case 2:
      MessageBuffer::setOffset(this: (MessageBuffer *)pBuf, noffset: 2);
      MessageBuffer::read(this: (MessageBuffer *)pBuf, (unsigned __int8 *)&p, bytes: 4u);
      for ( i = 0; i < p; ++i )
      {
        if ( MessageBuffer::ReadString(this: (MessageBuffer *)pBuf, pOut, bufferLength: 4096) == -1 )
          _Error(a1: "Error in ReadString() while reading command line.");
        v5 = _V_strlen(str: pOut) + 1;
        v6 = (char *)MemAlloc_Alloc(nSize: v5);
        V_strncpy(pDest: v6, pSrc: pOut, maxLen: v5);
        m_Size = g_WorkerCommandLine.m_Size;
        v8 = g_WorkerCommandLine.m_Size;
        if ( g_WorkerCommandLine.m_Size + 1 > g_WorkerCommandLine.m_Memory.m_nAllocationCount )
        {
          CUtlMemory<int,int>::Grow(
            this: (CUtlMemory<S3RGBA,int> *)&g_WorkerCommandLine,
            num: g_WorkerCommandLine.m_Size - g_WorkerCommandLine.m_Memory.m_nAllocationCount + 1);
          m_Size = g_WorkerCommandLine.m_Size;
        }
        m_pMemory = g_WorkerCommandLine.m_Memory.m_pMemory;
        g_WorkerCommandLine.m_Size = m_Size + 1;
        v10 = m_Size - v8;
        g_WorkerCommandLine.m_pElements = g_WorkerCommandLine.m_Memory.m_pMemory;
        if ( v10 > 0 )
        {
          _V_memmove(
            dest: (unsigned __int8 *)&g_WorkerCommandLine.m_Memory.m_pMemory[v8 + 1],
            src: (unsigned __int8 *)&g_WorkerCommandLine.m_Memory.m_pMemory[v8],
            count: 4 * v10);
          m_pMemory = g_WorkerCommandLine.m_Memory.m_pMemory;
        }
        v11 = &m_pMemory[v8];
        if ( v11 != nullptr )
          *v11 = v6;
      }
      g_bReceivedWorkerCommandLine = true;
      return 1;
    default:
      break;
  }
  if ( v2 != 6 )
  {
    if ( v2 == 5 )
    {
      g_bTimingWaitDone = true;
      return 1;
    }
    return 0;
  }
  MessageBuffer::setOffset(this: (MessageBuffer *)pBuf, noffset: 2);
  if ( MessageBuffer::ReadString(this: (MessageBuffer *)pBuf, pOut: g_MasterExeName, bufferLength: 260) == -1 )
    _Error(a1: "Error in ReadString() while reading VMPI_INTERNAL_SUBPACKET_VERIFY_EXE_NAME.");
  VMPI_SuperSpew(pMsg: "Received SUBPACKET_VERIFY_EXE_NAME (%s).\n", g_MasterExeName);
  g_bReceivedMasterExeName = true;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100872C0
// Name: void VMPI_ReceiveExeName(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl VMPI_ReceiveExeName()
{
  TSLHead_t m_Head; // kr00_8
  MessageBuffer *v1; // eax
  MessageBuffer *v2; // edi
  char v3; // al
  TSLNodeBase_t **v4; // eax
  TSLNodeBase_t **v5; // esi
  HMODULE ModuleHandleA; // eax
  int v7; // [esp-18h] [ebp-22Ch]
  int v8; // [esp-18h] [ebp-22Ch]
  TSLHead_t v9; // [esp-14h] [ebp-228h]
  TSLHead_t v10; // [esp-14h] [ebp-228h]
  char baseExeFilename[260]; // [esp+0h] [ebp-214h] BYREF
  char fileBase[260]; // [esp+104h] [ebp-110h] BYREF
  double startTime; // [esp+208h] [ebp-Ch]
  int pSource; // [esp+210h] [ebp-4h] BYREF

  startTime = _Plat_FloatTime();
  while ( !g_bReceivedMasterExeName )
  {
    if ( _Plat_FloatTime() - startTime > 30.0 )
      _Error(a1: "VMPI_ReceiveExeName: timeout.");
    m_Head = g_DispatchBuffers.m_Head;
    if ( g_DispatchBuffers.m_Head.value.Next == nullptr )
      goto LABEL_7;
    while ( (unsigned __int8)_ThreadInterlockedAssignIf64(
                               a1: &g_DispatchBuffers,
                               a2: m_Head.value.Next->Next,
                               a3: m_Head.value32.DepthAndSequence - 1,
                               a4: m_Head.value.Next,
                               a5: m_Head.value32.DepthAndSequence) == 0 )
    {
      _mm_pause();
      m_Head = g_DispatchBuffers.m_Head;
      if ( g_DispatchBuffers.m_Head.value.Next == nullptr )
        goto LABEL_7;
    }
    if ( m_Head.value.Next != nullptr )
    {
      v2 = *((MessageBuffer **)&m_Head.value.Next->Next + 1);
      free(pMem: m_Head.value.Next);
    }
    else
    {
LABEL_7:
      v1 = (MessageBuffer *)MemAlloc_Alloc(nSize: 0x10u);
      if ( v1 != nullptr )
        v2 = MessageBuffer::MessageBuffer(this: v1);
      else
        v2 = nullptr;
    }
    while ( VMPI_GetNextMessage(pBuf: v2, &pSource, startTimeout: (CTCPPacket *)0x2710) != 0 )
    {
      if ( ConCommandBase::GetName(this: (CVTFTexture *)v2) >= 1 )
      {
        v3 = *v2->data;
        if ( (unsigned __int8)v3 < 0x20u
          && g_VMPIDispatch[v3] != nullptr
          && g_VMPIDispatch[v3](a1: v2, a2: pSource, a3: v3) )
        {
          break;
        }
      }
    }
    v4 = (TSLNodeBase_t **)MemAlloc_Alloc(nSize: 8u);
    if ( v4 != nullptr )
    {
      v4[1] = (TSLNodeBase_t *)v2;
      v5 = v4;
    }
    else
    {
      v5 = nullptr;
    }
    v9 = g_DispatchBuffers.m_Head;
    v7 = g_DispatchBuffers.m_Head.value32.DepthAndSequence + 65537;
    *v5 = g_DispatchBuffers.m_Head.value.Next;
    if ( (unsigned __int8)_ThreadInterlockedAssignIf64(
                            a1: &g_DispatchBuffers,
                            a2: v5,
                            a3: v7,
                            a4: v9.value.Next,
                            a5: v9.value32.DepthAndSequence) == 0 )
    {
      do
      {
        _mm_pause();
        v10 = g_DispatchBuffers.m_Head;
        v8 = g_DispatchBuffers.m_Head.value32.DepthAndSequence + 65537;
        *v5 = g_DispatchBuffers.m_Head.value.Next;
      }
      while ( (unsigned __int8)_ThreadInterlockedAssignIf64(
                                 a1: &g_DispatchBuffers,
                                 a2: v5,
                                 a3: v8,
                                 a4: v10.value.Next,
                                 a5: v10.value32.DepthAndSequence) == 0 );
    }
  }
  ModuleHandleA = GetModuleHandleA(lpModuleName: nullptr);
  if ( GetModuleFileNameA(hModule: ModuleHandleA, lpFilename: baseExeFilename, nSize: 0x104u) == 0 )
    _Error(a1: "VMPI_CheckSDKMode -> GetModuleFileName failed.");
  V_FileBase(in: baseExeFilename, out: fileBase, maxlen: 260);
  if ( _V_stricmp(s1: fileBase, s2: "vmpi_transfer") != 0 && _V_stricmp(s1: fileBase, s2: g_MasterExeName) != 0 )
    _Error(
      a1: "VMPI_ReceiveExeName: mismatched exe names (master: %s, me: %s).\n"
      "This usually just means the master finished a job like vvis really fast and started a vrad immediately, and an old"
      " vvis worker connected to the new vrad job.",
      g_MasterExeName,
      fileBase);
}

//------------------------------------------------------------------------------
// Address: 0x100874F0
// Name: bool VMPI_SendData(void __near *,int,int,int)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl VMPI_SendData(void *pData, int nBytes, int iDest, char fVMPISendFlags)
{
  return VMPI_SendChunks(
           pChunks: (const void *const *)&pData,
           pChunkLengths: &nBytes,
           nChunks: 1,
           iDest,
           fVMPISendFlags);
}

//------------------------------------------------------------------------------
// Address: 0x10087510
// Name: void VMPI_SendMachineNameTo(int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl VMPI_SendMachineNameTo(int iProc)
{
  char *v1; // esi
  unsigned __int8 packetData[768]; // [esp+4h] [ebp-308h] BYREF
  void *pChunks; // [esp+304h] [ebp-8h] BYREF
  unsigned int nSize; // [esp+308h] [ebp-4h] BYREF

  nSize = 16;
  v1 = Buffer;
  if ( !GetComputerNameA(lpBuffer: Buffer, &nSize) )
    v1 = "(error in GetComputerName)";
  VMPI_SuperSpew(pMsg: "Sent SUBPACKET_MACHINE_NAME (%s).\n", v1);
  *(_WORD *)packetData = 283;
  V_strncpy(pDest: (char *)&packetData[2], pSrc: v1, maxLen: 766);
  nSize = strlen(v1) + 3;
  pChunks = packetData;
  VMPI_SendChunks(
    (const void *const *)&pChunks,
    pChunkLengths: (int *)&nSize,
    nChunks: 1,
    iDest: iProc,
    fVMPISendFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x100875B0
// Name: void VMPI_SendCommandLine(int,char __near * __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl VMPI_SendCommandLine(int argc, char **argv)
{
  int v2; // esi
  char **v3; // edi
  MessageBuffer mb; // [esp+4h] [ebp-1Ch] BYREF
  void *pChunks; // [esp+14h] [ebp-Ch] BYREF
  int pChunkLengths; // [esp+18h] [ebp-8h] BYREF
  unsigned __int8 cPacketHeader[4]; // [esp+1Ch] [ebp-4h] BYREF

  MessageBuffer::MessageBuffer(this: &mb);
  *(_WORD *)cPacketHeader = 539;
  MessageBuffer::write(this: &mb, p: cPacketHeader, bytes: 2u);
  MessageBuffer::write(this: &mb, p: (unsigned __int8 *)&argc, bytes: 4u);
  v2 = 0;
  if ( argc > 0 )
  {
    v3 = argv;
    do
      MessageBuffer::WriteString(this: &mb, pString: v3[v2++]);
    while ( v2 < argc );
  }
  pChunkLengths = ConCommandBase::GetName(this: (CVTFTexture *)&mb);
  pChunks = mb.data;
  VMPI_SendChunks((const void *const *)&pChunks, &pChunkLengths, nChunks: 1, iDest: -3, fVMPISendFlags: 0);
  MessageBuffer::~MessageBuffer(this: &mb);
}

//------------------------------------------------------------------------------
// Address: 0x10087640
// Name: void VMPI_ReceiveCommandLine(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl VMPI_ReceiveCommandLine()
{
  CVMPIConnection *v0; // esi
  IThreadedTCPSocket *m_pSocket; // ecx
  double startTime; // [esp+4h] [ebp-10h] BYREF
  int pChunkLengths; // [esp+Ch] [ebp-8h] BYREF
  unsigned __int8 chData[2]; // [esp+10h] [ebp-4h] BYREF

  ++g_nMessagesSent;
  HIDWORD(startTime) = chData;
  v0 = g_Connections[0];
  *(_WORD *)chData = 795;
  pChunkLengths = 2;
  g_nBytesSent += 6;
  if ( g_Connections[0] != nullptr
    && VMPI_FilterPacketsForServiceDownloader(
         pConnection: g_Connections[0],
         pChunks: (const void *const *)&startTime + 1,
         &pChunkLengths,
         nChunks: 1) == 0 )
  {
    m_pSocket = v0->m_pSocket;
    if ( m_pSocket != nullptr )
      m_pSocket->SendChunks(this: m_pSocket, a2: (const void *const *)&startTime + 1, a3: &pChunkLengths, a4: 1);
  }
  startTime = _Plat_FloatTime();
  while ( !g_bReceivedWorkerCommandLine )
  {
    if ( _Plat_FloatTime() - startTime > 30.0 )
      _Error(a1: "VMPI_ReceiveCommandLine: timeout. Is the master running in SDK mode?");
    VMPI_DispatchNextMessage(timeout: (CTCPPacket *)0x2710);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10087700
// Name: void VMPI_SendExeName(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl VMPI_SendExeName()
{
  HMODULE ModuleHandleA; // eax
  char baseExeFilename[260]; // [esp+0h] [ebp-224h] BYREF
  char fileBase[260]; // [esp+104h] [ebp-120h] BYREF
  MessageBuffer mb; // [esp+208h] [ebp-1Ch] BYREF
  int pChunkLengths; // [esp+218h] [ebp-Ch] BYREF
  void *pChunks; // [esp+21Ch] [ebp-8h] BYREF
  unsigned __int8 cPacketHeader[4]; // [esp+220h] [ebp-4h] BYREF

  MessageBuffer::MessageBuffer(this: &mb);
  *(_WORD *)cPacketHeader = 1563;
  MessageBuffer::write(this: &mb, p: cPacketHeader, bytes: 2u);
  ModuleHandleA = GetModuleHandleA(lpModuleName: nullptr);
  if ( GetModuleFileNameA(hModule: ModuleHandleA, lpFilename: baseExeFilename, nSize: 0x104u) == 0 )
    _Error(a1: "VMPI_CheckSDKMode -> GetModuleFileName failed.");
  V_FileBase(in: baseExeFilename, out: fileBase, maxlen: 260);
  MessageBuffer::WriteString(this: &mb, pString: fileBase);
  VMPI_SuperSpew(pMsg: "Sending SUBPACKET_VERIFY_EXE_NAME (%s).\n", fileBase);
  pChunkLengths = ConCommandBase::GetName(this: (CVTFTexture *)&mb);
  pChunks = mb.data;
  VMPI_SendChunks((const void *const *)&pChunks, &pChunkLengths, nChunks: 1, iDest: -3, fVMPISendFlags: 0);
  MessageBuffer::~MessageBuffer(this: &mb);
}

//------------------------------------------------------------------------------
// Address: 0x100877D0
// Name: private: void CMasterBroadcaster::ThreadFn(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMasterBroadcaster::ThreadFn(CMasterBroadcaster *this)
{
  void *UserData; // eax
  int v3; // edi
  int v4; // ebx
  int v5; // edi
  unsigned int v6; // edx
  ITCPConnectSocket *m_pListenSocket; // ecx
  bool v8; // al
  IThreadedTCPSocket *v9; // edx
  ITCPConnectSocket *m_pDownloaderListenSocket; // ecx
  IThreadedTCPSocket *v11; // edi
  int v12; // eax
  CVMPIConnection *v13; // ecx
  CVMPIConnection *v14; // edi
  ITCPSocketHandler *(__thiscall *GetHandler)(IThreadedTCPSocket *); // eax
  int *v16; // eax
  int m_Next; // edx
  UtlLinkedListElem_t<CUtlVector<char,CUtlMemory<char,int> > *,unsigned short> *m_pMemory; // edi
  int v19; // ebx
  CUtlVector<char,CUtlMemory<char,int> > *m_Element; // edi
  unsigned __int8 *m_Size; // ecx
  int v22; // edx
  int v23; // eax
  int v24; // edi
  void *v25; // eax
  char pData[768]; // [esp+4h] [ebp-3E8h] BYREF
  char pPacketIDString[64]; // [esp+304h] [ebp-E8h] BYREF
  char pSubPacketIDString[64]; // [esp+344h] [ebp-A8h] BYREF
  char v29; // [esp+384h] [ebp-68h] BYREF
  int v30; // [esp+388h] [ebp-64h]
  bf_write buf; // [esp+38Ch] [ebp-60h] BYREF
  CCriticalSectionLock v32; // [esp+3A4h] [ebp-48h] BYREF
  CCriticalSectionLock v33; // [esp+3ACh] [ebp-40h] BYREF
  char *v34; // [esp+3B4h] [ebp-38h]
  void *pChunks; // [esp+3B8h] [ebp-34h] BYREF
  int v36; // [esp+3BCh] [ebp-30h]
  int pChunkLengths; // [esp+3C0h] [ebp-2Ch] BYREF
  int nServiceDownloaders; // [esp+3C4h] [ebp-28h] BYREF
  unsigned int startTime; // [esp+3C8h] [ebp-24h]
  CCriticalSectionLock v40; // [esp+3CCh] [ebp-20h] BYREF
  int v41; // [esp+3D4h] [ebp-18h] BYREF
  __int16 v42; // [esp+3D8h] [ebp-14h]
  int nRegularWorkers; // [esp+3DCh] [ebp-10h] BYREF
  int v44; // [esp+3E0h] [ebp-Ch]
  IThreadedTCPSocket *v45; // [esp+3E4h] [ebp-8h] BYREF
  int v46; // [esp+3E8h] [ebp-4h]

  UserData = CTCPPacket::GetUserData(this: &this->m_hShutdownEvent);
  if ( WaitForSingleObject(hHandle: UserData, dwMilliseconds: 0x14u) == 258 )
  {
    do
    {
      startTime = GetTickCount();
      while ( 1 )
      {
        CCriticalSectionLock::CCriticalSectionLock(this: &v40, pCS: &g_ConnectionsCS);
        CCriticalSectionLock::Lock(this: &v40);
        CountActiveConnections(&nRegularWorkers, &nServiceDownloaders);
        if ( nRegularWorkers >= this->m_nMaxWorkers )
          break;
        if ( this->m_pSocket != nullptr )
        {
          v44 = _Plat_MSTime();
          if ( v44 - this->m_LastSendTime >= 0x258 )
          {
            bf_write::bf_write(this: &buf, pDebugName: "packetBuf", pData, nBytes: 768, nBits: -1);
            CMasterBroadcaster::BuildBroadcastPacket(this, &buf);
            v3 = 23397;
            v46 = 23397;
            do
            {
              if ( this->m_bPatching )
              {
                v4 = 0;
                if ( this->m_PatchWorkerIPs.m_Size > 0 )
                {
                  v5 = 0;
                  do
                  {
                    v41 = *(_DWORD *)this->m_PatchWorkerIPs.m_Memory.m_pMemory[v5].ip;
                    v42 = v46;
                    if ( !this->m_pSocket->SendTo(
                            this: this->m_pSocket,
                            a2: (const CIPAddr *)&v41,
                            a3: buf.m_pData,
                            a4: (buf.m_iCurBit + 7) >> 3) )
                      VMPI_WriteToLogFile(pMsg: "Error in SendTo trying to send patch request packet!\n");
                    _ThreadSleep(a1: 2);
                    ++v4;
                    ++v5;
                  }
                  while ( v4 < this->m_PatchWorkerIPs.m_Size );
                  v3 = v46;
                }
              }
              else
              {
                this->m_pSocket->Broadcast(this: this->m_pSocket, a2: buf.m_pData, a3: (buf.m_iCurBit + 7) >> 3, a4: v3);
              }
              v46 = ++v3;
            }
            while ( v3 <= 23412 );
            this->m_PatchWorkerIPs.m_Size = 0;
            if ( this->m_PatchWorkerIPs.m_Memory.m_nGrowSize >= 0 )
            {
              if ( this->m_PatchWorkerIPs.m_Memory.m_pMemory != nullptr )
              {
                _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)this->m_PatchWorkerIPs.m_Memory.m_pMemory);
                this->m_PatchWorkerIPs.m_Memory.m_pMemory = nullptr;
              }
              this->m_PatchWorkerIPs.m_Memory.m_nAllocationCount = 0;
            }
            v6 = v44;
            this->m_PatchWorkerIPs.m_pElements = this->m_PatchWorkerIPs.m_Memory.m_pMemory;
            this->m_LastSendTime = v6;
          }
        }
        m_pListenSocket = this->m_pListenSocket;
        v45 = nullptr;
        v8 = m_pListenSocket->Update(this: m_pListenSocket, a2: &v45, a3: 0);
        v9 = v45;
        if ( !v8 || v45 == nullptr )
        {
          m_pDownloaderListenSocket = this->m_pDownloaderListenSocket;
          if ( m_pDownloaderListenSocket != nullptr && nServiceDownloaders < this->m_nMaxWorkers - nRegularWorkers + 8 )
          {
            v8 = m_pDownloaderListenSocket->Update(this: m_pDownloaderListenSocket, a2: &v45, a3: 0);
            v9 = v45;
          }
        }
        if ( !v8 || v9 == nullptr )
          break;
        v9->GetRemoteAddr(this: v9, result: (CIPAddr *)&v29);
        if ( (unsigned __int16)(v30 - 22351) <= 9u )
        {
          v11 = v45;
          CCriticalSectionLock::CCriticalSectionLock(this: &v33, pCS: &g_ConnectionsCS);
          v12 = 0;
          if ( g_nConnections <= 0 )
          {
LABEL_33:
            CCriticalSectionLock::~CCriticalSectionLock(this: &v33);
          }
          else
          {
            while ( 1 )
            {
              v13 = g_Connections[v12];
              if ( v13 != nullptr && v13->m_pSocket == v11 )
                break;
              if ( ++v12 >= g_nConnections )
                goto LABEL_33;
            }
            v14 = g_Connections[v12];
            CCriticalSectionLock::~CCriticalSectionLock(this: &v33);
            if ( v14 != nullptr )
              v14->m_bIsAService = true;
          }
        }
        CCriticalSectionLock::CCriticalSectionLock(this: &v32, pCS: &g_PersistentPacketsCS);
        CCriticalSectionLock::Lock(this: &v32);
        GetHandler = v45->GetHandler;
        v46 = 1;
        v16 = (int *)GetHandler(this: v45);
        LOWORD(m_Next) = g_PersistentPackets.m_Head;
        v44 = (int)v16;
        if ( g_PersistentPackets.m_Head != 0xFFFF )
        {
          m_pMemory = g_PersistentPackets.m_Memory.m_pMemory;
          while ( 1 )
          {
            v19 = (unsigned __int16)m_Next;
            m_Element = m_pMemory[v19].m_Element;
            m_Size = (unsigned __int8 *)m_Element->m_Size;
            v34 = m_Element->m_Memory.m_pMemory;
            v22 = *v16;
            v36 = (int)m_Size;
            v23 = (*(int (__thiscall **)(int *))(v22 + 16))(a1: v16);
            pChunkLengths = v36;
            pChunks = v34;
            VMPI_SendChunks((const void *const *)&pChunks, &pChunkLengths, nChunks: 1, iDest: v23, fVMPISendFlags: 0);
            if ( g_bSuperSpewEnabled )
            {
              if ( m_Element->m_Size <= 2 )
              {
                VMPI_SuperSpew(pMsg: "Sending a really short persistent packet (%d bytes).\n", m_Element->m_Size);
              }
              else
              {
                CVMPIPacketIDReg::Lookup(
                  nPacketID: *(unsigned __int8 *)m_Element->m_Memory.m_pMemory,
                  nSubPacketID: *((unsigned __int8 *)m_Element->m_Memory.m_pMemory + 1),
                  pPacketIDString,
                  nPacketIDStringSize: 64,
                  pSubPacketIDString,
                  nSubPacketIDStringSize: 64);
                v24 = v46;
                VMPI_SuperSpew(
                  pMsg: "Sending persistent packet %d. PacketID: %s, SubPacketID: %s.\n",
                  v46,
                  pPacketIDString,
                  pSubPacketIDString);
                v46 = v24 + 1;
              }
            }
            m_pMemory = g_PersistentPackets.m_Memory.m_pMemory;
            m_Next = g_PersistentPackets.m_Memory.m_pMemory[v19].m_Next;
            if ( m_Next == 0xFFFF )
              break;
            v16 = (int *)v44;
          }
        }
        UpdateActiveConnectionsText();
        CCriticalSectionLock::~CCriticalSectionLock(this: &v32);
        CCriticalSectionLock::~CCriticalSectionLock(this: &v40);
        if ( GetTickCount() - startTime >= 0x1F4 )
          goto LABEL_47;
      }
      CCriticalSectionLock::~CCriticalSectionLock(this: &v40);
LABEL_47:
      v25 = CTCPPacket::GetUserData(this: &this->m_hShutdownEvent);
    }
    while ( WaitForSingleObject(hHandle: v25, dwMilliseconds: 0x14u) == 258 );
  }
  CEvent::SetEvent(this: &this->m_hShutdownReply);
}

//------------------------------------------------------------------------------
// Address: 0x10087BC0
// Name: private: static unsigned long CMasterBroadcaster::StaticThreadFn(void __near *)
// Source: json
//------------------------------------------------------------------------------
unsigned int __stdcall CMasterBroadcaster::StaticThreadFn(CMasterBroadcaster *lpParameter)
{
  CMasterBroadcaster::ThreadFn(this: lpParameter);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10087BE0
// Name: void VMPI_HandleTimingWait_Master(void)
// Source: json
//------------------------------------------------------------------------------
void __fastcall VMPI_HandleTimingWait_Master(int a1, int a2)
{
  int v2; // eax
  void *pChunks; // [esp+0h] [ebp-Ch] BYREF
  int pChunkLengths; // [esp+4h] [ebp-8h] BYREF
  unsigned __int8 cPacket[2]; // [esp+8h] [ebp-4h] BYREF

  v2 = _CommandLine(a1, a2);
  if ( (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v2 + 40))(a1: v2, a2: g_VMPIParams[9].m_pName) != 0 )
  {
    _Msg(a1: "-mpi_TimingWait specified. Waiting for a keypress to continue... ");
    getch();
    _Msg(a1: "\n");
    *(_WORD *)cPacket = 1307;
    pChunkLengths = 2;
    pChunks = cPacket;
    VMPI_SendChunks((const void *const *)&pChunks, &pChunkLengths, nChunks: 1, iDest: -3, fVMPISendFlags: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10087C50
// Name: bool MPI_Init_Worker(int __near &,char __near * __near * __near &,class CIPAddr const __near &,bool)
// Source: json
//------------------------------------------------------------------------------
char __cdecl MPI_Init_Worker(
        int *argc,
        char ***argv,
        const CIPAddr *masterAddr,
        IThreadedTCPSocket *bConnectingAsService)
{
  int v4; // edi
  ITCPConnectSocket *v5; // esi
  const CIPAddr *v6; // eax
  void (*v7)(const char *, ...); // edi
  bool (__thiscall *Update)(ITCPConnectSocket *, IThreadedTCPSocket **, unsigned int); // edx
  int v9; // edx
  int v10; // ecx
  void (__thiscall ***v11)(_DWORD, int, char **); // eax
  int v12; // edx
  int v13; // ecx
  int i; // esi
  int v15; // eax
  int v17; // edx
  int v18; // ecx
  int v19; // eax
  int v20; // esi
  int flSeconds; // [esp+0h] [ebp-34h]
  CWaitTimer wait; // [esp+14h] [ebp-20h] BYREF
  CIPAddr v23; // [esp+1Eh] [ebp-16h] BYREF
  CVMPIConnectionCreator connectionCreator; // [esp+24h] [ebp-10h] BYREF
  int nAttempts; // [esp+28h] [ebp-Ch]
  int iFirstPort; // [esp+2Ch] [ebp-8h]
  int iLastPort; // [esp+30h] [ebp-4h]

  v4 = 22340;
  g_bMPIMaster = false;
  connectionCreator.__vftable = (CVMPIConnectionCreator_vtbl *)&CVMPIConnectionCreator::`vftable';
  iFirstPort = 22340;
  iLastPort = 22350;
  if ( (_BYTE)bConnectingAsService != 0 )
  {
    iFirstPort = 22351;
    v4 = 22351;
    iLastPort = 22360;
  }
  nAttempts = 1;
  while ( 2 )
  {
    v5 = nullptr;
    if ( v4 > iLastPort )
    {
LABEL_8:
      flSeconds = v4;
      v7 = (void (*)(const char *, ...))_Error;
      _Error(a1: "Can't bind a port in range [%d, %d].", flSeconds, iLastPort);
    }
    else
    {
      while ( 1 )
      {
        v6 = CIPAddr::CIPAddr(this: &v23, ip0: 0, ip1: 0, ip2: 0, ip3: 0, ipPort: v4);
        v5 = ThreadedTCP_CreateConnector(addr: masterAddr, localAddr: v6, pHandlerCreator: &connectionCreator);
        if ( v5 != nullptr )
          break;
        if ( ++v4 > iLastPort )
        {
          v4 = iFirstPort;
          goto LABEL_8;
        }
      }
      v7 = (void (*)(const char *, ...))_Error;
    }
    CWaitTimer::CWaitTimer(this: &wait, flSeconds: 3.0);
    while ( 1 )
    {
      Update = v5->Update;
      bConnectingAsService = nullptr;
      if ( Update(this: v5, a2: &bConnectingAsService, a3: 100u) )
      {
        if ( bConnectingAsService != nullptr )
        {
          VMPI_SendMachineNameTo(iProc: 0);
          VMPI_ReceiveExeName();
          if ( g_bVMPISDKMode )
          {
            VMPI_ReceiveCommandLine();
            v11 = (void (__thiscall ***)(_DWORD, int, char **))_CommandLine(a1: v10, a2: v9);
            (**v11)(a1: v11, a2: g_WorkerCommandLine.m_Size, a3: g_WorkerCommandLine.m_Memory.m_pMemory);
            *argc = g_WorkerCommandLine.m_Size;
            *argv = g_WorkerCommandLine.m_Memory.m_pMemory;
          }
          ParseOptions(argc: g_WorkerCommandLine.m_Size, argv: g_WorkerCommandLine.m_Memory.m_pMemory);
          for ( i = 0; i < g_WorkerCommandLine.m_Size; ++i )
            _Msg(a1: "arg %d: %s\n", i, g_WorkerCommandLine.m_Memory.m_pMemory[i]);
          v15 = _CommandLine(a1: v13, a2: v12);
          if ( (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v15 + 40))(a1: v15, a2: g_VMPIParams[9].m_pName) != 0 )
          {
            _Msg(a1: "-mpi_TimingWait specified. Waiting for master to start...");
            while ( !g_bTimingWaitDone )
              VMPI_DispatchNextMessage(timeout: (CTCPPacket *)0x32);
            _Msg(a1: "\n ");
          }
          return 1;
        }
      }
      else
      {
        v5->Release(this: v5);
        v7(a1: "ITCPConnectSocket::Update() errored out");
      }
      if ( !CWaitTimer::ShouldKeepWaiting(this: &wait) )
        break;
      Sleep(dwMilliseconds: 0x64u);
    }
    v5->Release(this: v5);
    v19 = _CommandLine(a1: v18, a2: v17);
    if ( (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v19 + 40))(a1: v19, a2: g_VMPIParams[5].m_pName) != 0 )
    {
      v20 = nAttempts;
      _Msg(
        a1: "%s found. Retrying connection to %d.%d.%d.%d:%d (attempt %d).\n",
        g_VMPIParams[5].m_pName,
        masterAddr->ip[0],
        masterAddr->ip[1],
        masterAddr->ip[2],
        masterAddr->ip[3],
        masterAddr->port,
        nAttempts);
      v4 = iFirstPort;
      nAttempts = v20 + 1;
      continue;
    }
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10087EC0
// Name: public: bool CMasterBroadcaster::Init(int,char __near * __near *,char const __near *,int,enum VMPIRunMode,bool)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CMasterBroadcaster::Init(
        CMasterBroadcaster *this,
        int argc,
        char **argv,
        char *pDependencyFilename,
        int nMaxWorkers,
        VMPIRunMode runMode,
        bool bPatchMode)
{
  VMPIRunMode v7; // eax
  char *Arg; // eax
  int v10; // eax
  int v11; // esi
  ITCPConnectSocket *Listener; // eax
  int j; // esi
  ITCPConnectSocket *v14; // eax
  bool v15; // zf
  ISocket *IPSocket; // eax
  int v17; // esi
  char *v18; // esi
  long double v19; // st7
  int v20; // esi
  char *v21; // eax
  bool v22; // sf
  unsigned int v23; // edi
  int m_Size; // edi
  int m_nAllocationCount; // eax
  char **m_pMemory; // ecx
  int v27; // eax
  char **v28; // edi
  unsigned int v29; // edi
  int v30; // eax
  int v31; // ecx
  char **v32; // eax
  int v33; // ecx
  char **v34; // eax
  int v35; // eax
  int v36; // ecx
  char **v37; // eax
  int v38; // ecx
  unsigned int v39; // edi
  int v40; // eax
  int v41; // ecx
  char **v42; // eax
  int v43; // ecx
  int v44; // eax
  int v45; // ecx
  char **v46; // eax
  int v47; // ecx
  unsigned int v48; // edi
  int v49; // eax
  int v50; // ecx
  char **v51; // eax
  int v52; // ecx
  HANDLE Thread; // eax
  CDependencyInfo::CDependencyFile **v54; // eax
  char *v56; // esi
  CDependencyInfo::CDependencyFile **v57; // eax
  unsigned __int16 m_iListenPort; // [esp-Ch] [ebp-23Ch]
  unsigned __int64 v59; // [esp-8h] [ebp-238h]
  unsigned __int64 v60; // [esp-8h] [ebp-238h]
  CDependencyInfo dependencyInfo; // [esp+Ch] [ebp-224h] BYREF
  CCycleCount cnt; // [esp+228h] [ebp-8h]
  char *pDependencyFilenamea; // [esp+240h] [ebp+10h]
  CDependencyInfo::CDependencyFile *pDependencyFilenameb; // [esp+240h] [ebp+10h]
  float id; // [esp+244h] [ebp+14h]
  int i; // [esp+244h] [ebp+14h]
  char *ia; // [esp+244h] [ebp+14h]
  int ib; // [esp+244h] [ebp+14h]
  char *ic; // [esp+244h] [ebp+14h]

  v7 = runMode;
  this->m_RunMode = runMode;
  this->m_nMaxWorkers = nMaxWorkers;
  memset(&dependencyInfo.m_Files, 0, sizeof(dependencyInfo.m_Files));
  if ( v7 == VMPI_RUN_NETWORKED && !g_bVMPISDKMode )
    SetupDependencyInfo(pInfo: &dependencyInfo, pDependencyFilename, bPatchMode);
  this->m_pListenSocket = nullptr;
  this->m_pDownloaderListenSocket = nullptr;
  Arg = VMPI_FindArg(argc, argv, pName: g_VMPIParams[3].m_pName, pDefault: defaultValue);
  if ( Arg != nullptr )
  {
    v10 = atoi(nptr: Arg);
    this->m_iListenPort = v10;
    m_iListenPort = this->m_iListenPort;
    this->m_iDownloaderListenPort = v10 + 1;
    this->m_pListenSocket = ThreadedTCP_CreateListener(
                              pHandlerCreator: &this->m_ConnectionCreator,
                              port: m_iListenPort,
                              nQueueLength: 5);
    if ( !g_bVMPISDKMode )
      this->m_pDownloaderListenSocket = ThreadedTCP_CreateListener(
                                          pHandlerCreator: &this->m_ConnectionCreator,
                                          port: this->m_iDownloaderListenPort,
                                          nQueueLength: 5);
  }
  else
  {
    cnt.m_Int64 = __rdtsc();
    HIDWORD(v59) = HIDWORD(_g_ClockSpeed);
    LODWORD(v59) = _g_ClockSpeed;
    srand(seed: 1000000 * cnt.m_Int64 / v59);
    v11 = 23311;
    while ( 1 )
    {
      this->m_iListenPort = v11;
      Listener = ThreadedTCP_CreateListener(pHandlerCreator: &this->m_ConnectionCreator, port: v11, nQueueLength: 5);
      this->m_pListenSocket = Listener;
      if ( Listener != nullptr )
        break;
      if ( ++v11 > 23330 )
        goto LABEL_16;
    }
    if ( !g_bVMPISDKMode )
    {
      for ( j = this->m_iListenPort + 1; j <= 23330; ++j )
      {
        this->m_iDownloaderListenPort = j;
        if ( j != this->m_iListenPort )
        {
          v14 = ThreadedTCP_CreateListener(pHandlerCreator: &this->m_ConnectionCreator, port: j, nQueueLength: 5);
          this->m_pDownloaderListenSocket = v14;
          if ( v14 != nullptr )
            break;
        }
      }
    }
  }
LABEL_16:
  if ( this->m_pListenSocket == nullptr || !g_bVMPISDKMode && this->m_pDownloaderListenSocket == nullptr )
    _Error(a1: "Can't bind a listen socket in port range [%d, %d].", 21140, 21145);
  v15 = this->m_RunMode == VMPI_RUN_NETWORKED;
  this->m_bPatching = false;
  if ( v15 && !g_bVMPISDKMode )
  {
    IPSocket = CreateIPSocket();
    this->m_pSocket = IPSocket;
    if ( !IPSocket->BindToAny(this: IPSocket, a2: 0) )
      _Error(a1: "MPI_Init_Master: can't bind a socket");
    if ( bPatchMode )
    {
      v17 = 0;
      this->m_bPatching = true;
      if ( argc <= 0 )
      {
LABEL_28:
        v18 = nullptr;
      }
      else
      {
        while ( _V_stricmp(s1: argv[v17], s2: "-mpi_PatchVersion") != 0 )
        {
          if ( ++v17 >= argc )
            goto LABEL_28;
        }
        if ( v17 + 1 >= argc )
          v18 = "0";
        else
          v18 = argv[v17 + 1];
      }
      v19 = atof(nptr: v18);
      if ( v19 <= 0.0 || (id = v19) >= 32767.0 )
        _Error(a1: "-mpi_PatchVersion <val> -  val must be between 1.0 and 32767.0");
      V_strncpy(pDest: this->m_BroadcastInfo.m_PatchVersion, pSrc: v18, maxLen: 32);
    }
    else
    {
      this->m_BroadcastInfo.m_PatchVersion[0] = 0;
    }
    Sleep(dwMilliseconds: 1u);
    cnt.m_Int64 = __rdtsc();
    HIDWORD(v60) = HIDWORD(_g_ClockSpeed);
    LODWORD(v60) = _g_ClockSpeed;
    this->m_BroadcastInfo.m_JobID[0] = 1000000 * cnt.m_Int64 / v60;
    Sleep(dwMilliseconds: 1u);
    cnt.m_Int64 = __rdtsc();
    HIDWORD(v60) = HIDWORD(_g_ClockSpeed);
    LODWORD(v60) = _g_ClockSpeed;
    this->m_BroadcastInfo.m_JobID[1] = 1000000 * cnt.m_Int64 / v60;
    Sleep(dwMilliseconds: 1u);
    cnt.m_Int64 = __rdtsc();
    HIDWORD(v60) = HIDWORD(_g_ClockSpeed);
    LODWORD(v60) = _g_ClockSpeed;
    this->m_BroadcastInfo.m_JobID[2] = 1000000 * cnt.m_Int64 / v60;
    Sleep(dwMilliseconds: 1u);
    cnt.m_Int64 = __rdtsc();
    HIDWORD(v60) = HIDWORD(_g_ClockSpeed);
    LODWORD(v60) = _g_ClockSpeed;
    v20 = 0;
    this->m_BroadcastInfo.m_JobID[3] = 1000000 * cnt.m_Int64 / v60;
    if ( argc <= 0 )
      goto LABEL_40;
    while ( _V_stricmp(s1: argv[v20], s2: "-mpi_pw") != 0 )
    {
      if ( ++v20 >= argc )
        goto LABEL_40;
    }
    if ( v20 + 1 >= argc )
    {
      v21 = (char *)defaultValue;
      goto LABEL_41;
    }
    v56 = argv[v20 + 1];
    if ( v56 != nullptr )
      v21 = v56;
    else
LABEL_40:
      v21 = (char *)defaultValue;
LABEL_41:
    V_strncpy(pDest: this->m_BroadcastInfo.m_Password, pSrc: v21, maxLen: 256);
    V_strncpy(pDest: this->m_BroadcastInfo.m_WorkerExeFilename, pSrc: dependencyInfo.m_OriginalExeFilename, maxLen: 260);
    v22 = this->m_BroadcastInfo.m_Args.m_Memory.m_nGrowSize < 0;
    this->m_BroadcastInfo.m_Args.m_Size = 0;
    if ( !v22 )
    {
      if ( this->m_BroadcastInfo.m_Args.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_BroadcastInfo.m_Args.m_Memory.m_pMemory);
        this->m_BroadcastInfo.m_Args.m_Memory.m_pMemory = nullptr;
      }
      this->m_BroadcastInfo.m_Args.m_Memory.m_nAllocationCount = 0;
    }
    this->m_BroadcastInfo.m_Args.m_pElements = this->m_BroadcastInfo.m_Args.m_Memory.m_pMemory;
    for ( i = 1; i < argc; ++i )
    {
      pDependencyFilenamea = argv[i];
      v23 = _V_strlen(str: pDependencyFilenamea) + 1;
      HIDWORD(cnt.m_Int64) = MemAlloc_Alloc(nSize: v23);
      V_strncpy(pDest: (char *)HIDWORD(cnt.m_Int64), pSrc: pDependencyFilenamea, maxLen: v23);
      m_Size = this->m_BroadcastInfo.m_Args.m_Size;
      m_nAllocationCount = this->m_BroadcastInfo.m_Args.m_Memory.m_nAllocationCount;
      if ( m_Size + 1 > m_nAllocationCount )
        CUtlMemory<int,int>::Grow(
          this: (CUtlMemory<S3RGBA,int> *)&this->m_BroadcastInfo.m_Args,
          num: m_Size - m_nAllocationCount + 1);
      ++this->m_BroadcastInfo.m_Args.m_Size;
      m_pMemory = this->m_BroadcastInfo.m_Args.m_Memory.m_pMemory;
      v27 = this->m_BroadcastInfo.m_Args.m_Size - m_Size - 1;
      this->m_BroadcastInfo.m_Args.m_pElements = m_pMemory;
      if ( v27 > 0 )
        _V_memmove(
          dest: (unsigned __int8 *)&m_pMemory[m_Size + 1],
          src: (unsigned __int8 *)&m_pMemory[m_Size],
          count: 4 * v27);
      v28 = &this->m_BroadcastInfo.m_Args.m_Memory.m_pMemory[m_Size];
      if ( v28 != nullptr )
        *v28 = (char *)HIDWORD(cnt.m_Int64);
    }
    v29 = _V_strlen(str: this->m_BroadcastInfo.m_WorkerExeFilename) + 1;
    ia = (char *)MemAlloc_Alloc(nSize: v29);
    V_strncpy(pDest: ia, pSrc: this->m_BroadcastInfo.m_WorkerExeFilename, maxLen: v29);
    v30 = this->m_BroadcastInfo.m_Args.m_Size;
    v31 = this->m_BroadcastInfo.m_Args.m_Memory.m_nAllocationCount;
    if ( v30 + 1 > v31 )
      CUtlMemory<int,int>::Grow(this: (CUtlMemory<S3RGBA,int> *)&this->m_BroadcastInfo.m_Args, num: v30 - v31 + 1);
    ++this->m_BroadcastInfo.m_Args.m_Size;
    v32 = this->m_BroadcastInfo.m_Args.m_Memory.m_pMemory;
    v33 = this->m_BroadcastInfo.m_Args.m_Size - 1;
    this->m_BroadcastInfo.m_Args.m_pElements = v32;
    if ( v33 > 0 )
      _V_memmove(dest: (unsigned __int8 *)v32 + 4, src: (unsigned __int8 *)v32, count: 4 * v33);
    v34 = this->m_BroadcastInfo.m_Args.m_Memory.m_pMemory;
    if ( v34 != nullptr )
      *v34 = ia;
    for ( ib = 0; ib < dependencyInfo.m_Files.m_Size; ++ib )
    {
      v35 = this->m_BroadcastInfo.m_Args.m_Size;
      v36 = this->m_BroadcastInfo.m_Args.m_Memory.m_nAllocationCount;
      if ( v35 + 1 > v36 )
        CUtlMemory<int,int>::Grow(this: (CUtlMemory<S3RGBA,int> *)&this->m_BroadcastInfo.m_Args, num: v35 - v36 + 1);
      ++this->m_BroadcastInfo.m_Args.m_Size;
      v37 = this->m_BroadcastInfo.m_Args.m_Memory.m_pMemory;
      v38 = this->m_BroadcastInfo.m_Args.m_Size - 2;
      this->m_BroadcastInfo.m_Args.m_pElements = v37;
      if ( v38 > 0 )
        _V_memmove(dest: (unsigned __int8 *)v37 + 8, src: (unsigned __int8 *)v37 + 4, count: 4 * v38);
      if ( this->m_BroadcastInfo.m_Args.m_Memory.m_pMemory != (char **)-4 )
        *((_DWORD *)this->m_BroadcastInfo.m_Args.m_Memory.m_pMemory + 1) = "-mpi_file";
      pDependencyFilenameb = dependencyInfo.m_Files.m_Memory.m_pMemory[ib];
      v39 = _V_strlen(str: pDependencyFilenameb->m_Name) + 1;
      HIDWORD(cnt.m_Int64) = MemAlloc_Alloc(nSize: v39);
      V_strncpy(pDest: (char *)HIDWORD(cnt.m_Int64), pSrc: pDependencyFilenameb->m_Name, maxLen: v39);
      v40 = this->m_BroadcastInfo.m_Args.m_Size;
      v41 = this->m_BroadcastInfo.m_Args.m_Memory.m_nAllocationCount;
      if ( v40 + 1 > v41 )
        CUtlMemory<int,int>::Grow(this: (CUtlMemory<S3RGBA,int> *)&this->m_BroadcastInfo.m_Args, num: v40 - v41 + 1);
      ++this->m_BroadcastInfo.m_Args.m_Size;
      v42 = this->m_BroadcastInfo.m_Args.m_Memory.m_pMemory;
      v43 = this->m_BroadcastInfo.m_Args.m_Size - 3;
      this->m_BroadcastInfo.m_Args.m_pElements = v42;
      if ( v43 > 0 )
        _V_memmove(dest: (unsigned __int8 *)v42 + 12, src: (unsigned __int8 *)v42 + 8, count: 4 * v43);
      if ( this->m_BroadcastInfo.m_Args.m_Memory.m_pMemory != (char **)-8 )
        *((_DWORD *)this->m_BroadcastInfo.m_Args.m_Memory.m_pMemory + 2) = HIDWORD(cnt.m_Int64);
    }
    v44 = this->m_BroadcastInfo.m_Args.m_Size;
    v45 = this->m_BroadcastInfo.m_Args.m_Memory.m_nAllocationCount;
    if ( v44 + 1 > v45 )
      CUtlMemory<int,int>::Grow(this: (CUtlMemory<S3RGBA,int> *)&this->m_BroadcastInfo.m_Args, num: v44 - v45 + 1);
    ++this->m_BroadcastInfo.m_Args.m_Size;
    v46 = this->m_BroadcastInfo.m_Args.m_Memory.m_pMemory;
    v47 = this->m_BroadcastInfo.m_Args.m_Size - 2;
    this->m_BroadcastInfo.m_Args.m_pElements = v46;
    if ( v47 > 0 )
      _V_memmove(dest: (unsigned __int8 *)v46 + 8, src: (unsigned __int8 *)v46 + 4, count: 4 * v47);
    if ( this->m_BroadcastInfo.m_Args.m_Memory.m_pMemory != (char **)-4 )
      *((_DWORD *)this->m_BroadcastInfo.m_Args.m_Memory.m_pMemory + 1) = "-mpi_filebase";
    v48 = _V_strlen(str: dependencyInfo.m_DependencyFilesDir) + 1;
    ic = (char *)MemAlloc_Alloc(nSize: v48);
    V_strncpy(pDest: ic, pSrc: dependencyInfo.m_DependencyFilesDir, maxLen: v48);
    v49 = this->m_BroadcastInfo.m_Args.m_Size;
    v50 = this->m_BroadcastInfo.m_Args.m_Memory.m_nAllocationCount;
    if ( v49 + 1 > v50 )
      CUtlMemory<int,int>::Grow(this: (CUtlMemory<S3RGBA,int> *)&this->m_BroadcastInfo.m_Args, num: v49 - v50 + 1);
    ++this->m_BroadcastInfo.m_Args.m_Size;
    v51 = this->m_BroadcastInfo.m_Args.m_Memory.m_pMemory;
    v52 = this->m_BroadcastInfo.m_Args.m_Size - 3;
    this->m_BroadcastInfo.m_Args.m_pElements = v51;
    if ( v52 > 0 )
      _V_memmove(dest: (unsigned __int8 *)v51 + 12, src: (unsigned __int8 *)v51 + 8, count: 4 * v52);
    if ( this->m_BroadcastInfo.m_Args.m_Memory.m_pMemory != (char **)-8 )
      *((_DWORD *)this->m_BroadcastInfo.m_Args.m_Memory.m_pMemory + 2) = ic;
    if ( bPatchMode )
      CMasterBroadcaster::GetPatchWorkerList(this, argc, argv);
  }
  this->m_ConnectionCreator.CreateNewHandler(this: &this->m_ConnectionCreator);
  this->m_LastSendTime = _Plat_MSTime() - 1200;
  CEvent::Init(this: &this->m_hShutdownEvent, bManualReset: false, bInitialState: false);
  CEvent::Init(this: &this->m_hShutdownReply, bManualReset: false, bInitialState: false);
  runMode = VMPI_RUN_NETWORKED;
  Thread = CreateThread(
             lpThreadAttributes: nullptr,
             dwStackSize: 0,
             lpStartAddress: (LPTHREAD_START_ROUTINE)CMasterBroadcaster::StaticThreadFn,
             lpParameter: this,
             dwCreationFlags: 0,
             lpThreadId: (LPDWORD)&runMode);
  this->m_hThread = Thread;
  if ( Thread != nullptr )
  {
    SetThreadPriority(hThread: Thread, nPriority: 2);
    v54 = dependencyInfo.m_Files.m_Memory.m_pMemory;
    dependencyInfo.m_Files.m_Size = 0;
    if ( dependencyInfo.m_Files.m_Memory.m_nGrowSize >= 0 )
    {
      if ( dependencyInfo.m_Files.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: dependencyInfo.m_Files.m_Memory.m_pMemory);
        v54 = nullptr;
        dependencyInfo.m_Files.m_Memory.m_pMemory = nullptr;
      }
      dependencyInfo.m_Files.m_Memory.m_nAllocationCount = 0;
    }
    dependencyInfo.m_Files.m_pElements = v54;
    if ( dependencyInfo.m_Files.m_Memory.m_nGrowSize >= 0 && v54 != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v54);
    return 1;
  }
  else
  {
    v57 = dependencyInfo.m_Files.m_Memory.m_pMemory;
    dependencyInfo.m_Files.m_Size = 0;
    if ( dependencyInfo.m_Files.m_Memory.m_nGrowSize >= 0 )
    {
      if ( dependencyInfo.m_Files.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: dependencyInfo.m_Files.m_Memory.m_pMemory);
        v57 = nullptr;
        dependencyInfo.m_Files.m_Memory.m_pMemory = nullptr;
      }
      dependencyInfo.m_Files.m_Memory.m_nAllocationCount = 0;
    }
    dependencyInfo.m_Files.m_pElements = v57;
    if ( dependencyInfo.m_Files.m_Memory.m_nGrowSize >= 0 && v57 != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v57);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100887E0
// Name: bool InitMaster(int,char __near * __near *,char const __near *,enum VMPIRunMode,bool)
// Source: json
//------------------------------------------------------------------------------
char __cdecl InitMaster(int argc, char **argv, char *pDependencyFilename, VMPIRunMode runMode, bool bPatchMode)
{
  char *Arg; // eax
  int v6; // ebx
  bool v7; // al
  char result; // al
  char v9; // bl
  int v10; // edx
  int v11; // ecx
  int v12; // edx
  int v13; // ecx

  Arg = VMPI_FindArg(argc, argv, pName: g_VMPIParams[10].m_pName, pDefault: defaultValue);
  if ( Arg != nullptr )
  {
    v6 = atoi(nptr: Arg);
    _Warning(a1: "%s: waiting for %d processes to join.\n");
    if ( v6 >= 2 )
    {
      if ( v6 > 512 )
        v6 = 512;
    }
    else
    {
      v6 = 2;
    }
  }
  else
  {
    v6 = 32;
  }
  g_bMPIMaster = true;
  g_nMaxWorkerCount = v6;
  if ( argc <= 0 )
    _Error(a1: "MPI_Init_Master: argc <= 0!");
  ParseOptions(argc, argv);
  VMPI_SendExeName();
  if ( g_bVMPISDKModeSet )
    v7 = g_bVMPISDKMode;
  else
    v7 = !VMPI_CheckForNonSDKExecutables();
  if ( v7 )
    VMPI_SendCommandLine(argc, argv);
  result = CMasterBroadcaster::Init(
             this: &g_MasterBroadcaster,
             argc,
             argv,
             pDependencyFilename,
             nMaxWorkers: v6,
             runMode,
             bPatchMode);
  if ( result != 0 )
  {
    if ( runMode == VMPI_RUN_LOCAL )
    {
      v9 = SpawnLocalWorker(argc, argv, iListenPort: g_MasterBroadcaster.m_iListenPort, bShowConsoleWindow: false);
      VMPI_HandleTimingWait_Master(a1: v11, a2: v10);
      return v9;
    }
    else
    {
      if ( VMPI_FindArg(argc, argv, pName: g_VMPIParams[11].m_pName, pDefault: defaultValue) != nullptr )
      {
        _Msg(a1: "%s found. Spawning a local worker automatically.\n", g_VMPIParams[11].m_pName);
        SpawnLocalWorker(argc: 1, argv, iListenPort: g_MasterBroadcaster.m_iListenPort, bShowConsoleWindow: true);
      }
      VMPI_HandleTimingWait_Master(a1: v13, a2: v12);
      return 1;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10088930
// Name: bool VMPI_Init(int __near &,char __near * __near * __near &,char const __near *,void (*)(int,char const __near *),enum VMPIRunMode,bool)
// Source: json
//------------------------------------------------------------------------------
char __cdecl VMPI_Init(
        int *argc,
        char ***argv,
        char *pDependencyFilename,
        void (__cdecl *handler)(int, const char *),
        VMPIRunMode runMode,
        IThreadedTCPSocket *bConnectingAsService)
{
  HMODULE LibraryA; // eax
  char *Arg; // ebx
  CIPAddr addr; // [esp+0h] [ebp-8h] BYREF

  if ( VMPI_IsLogFileEnabled() )
    _LoggingSystem_RegisterLoggingListener(a1: &g_VMPILoggingListener);
  if ( handler != nullptr )
    CUtlLinkedList<void (__cdecl *)(int,char const *),int,0,int,CUtlMemory<UtlLinkedListElem_t<void (__cdecl *)(int,char const *),int>,int>>::AddToTail(
      this: &g_DisconnectHandlers,
      src: &handler);
  VMPI_SetupAutoRestartParameters(argc: *argc, argv: *argv);
  VMPI_CheckSDKMode(argc: *argc, argv: *argv);
  g_bUseMPI = true;
  g_VMPIRunMode = runMode;
  CEvent::Init(this: &g_VMPIMessagesEvent, bManualReset: false, bInitialState: false);
  CEvent::Init(this: &g_ErrorSocketsEvent, bManualReset: false, bInitialState: false);
  LibraryA = LoadLibraryA(lpLibFileName: "kernel32.dll");
  g_hKernel32DLL = LibraryA;
  if ( LibraryA != nullptr )
    g_pConsoleWndFn = (HWND__ *(__cdecl *)())GetProcAddress(hModule: LibraryA, lpProcName: "GetConsoleWindow");
  Arg = VMPI_FindArg(argc: *argc, argv: *argv, pName: g_VMPIParams[2].m_pName, pDefault: nullptr);
  if ( Arg != nullptr )
  {
    CIPAddr::CIPAddr(this: &addr);
    addr.port = 23311;
    if ( !ConvertStringToIPAddr(pStr: Arg, pOut: &addr) )
      _Error(a1: "Unable to parse or resolve master IP (%s).\n", Arg);
    return MPI_Init_Worker(argc, argv, masterAddr: &addr, bConnectingAsService);
  }
  else if ( pDependencyFilename != nullptr )
  {
    return InitMaster(argc: *argc, argv: *argv, pDependencyFilename, runMode, bPatchMode: false);
  }
  else
  {
    _Error(a1: "VMPI started as master, but no dependency filename specified.\n");
    return 0;
  }
}

} // namespace vrad_dll

// ============================================================
// Overlay from vvis_dll (Missing functions)
// ============================================================
namespace vvis_dll {

//------------------------------------------------------------------------------
// Address: 0x100222E0
// Name: public: struct TSLNodeBase_t __near * CTSListBase::Push(struct TSLNodeBase_t __near *)
// Source: json
//------------------------------------------------------------------------------
TSLNodeBase_t *__thiscall CTSListBase::Push(CTSListBase *this, TSLNodeBase_t *pNode)
{
  TSLNodeBase_t *Next; // edi
  TSLNodeBase_t *v5; // [esp-8h] [ebp-14h]
  int DepthAndSequence; // [esp-4h] [ebp-10h]
  int v7; // [esp-4h] [ebp-10h]

  Next = this->m_Head.value.Next;
  DepthAndSequence = this->m_Head.value32.DepthAndSequence;
  pNode->Next = this->m_Head.value.Next;
  if ( (unsigned __int8)_ThreadInterlockedAssignIf64(
                          a1: this,
                          a2: pNode,
                          a3: DepthAndSequence + 65537,
                          a4: Next,
                          a5: DepthAndSequence) == 0 )
  {
    do
    {
      _mm_pause();
      Next = this->m_Head.value.Next;
      v7 = this->m_Head.value32.DepthAndSequence;
      v5 = this->m_Head.value.Next;
      pNode->Next = this->m_Head.value.Next;
    }
    while ( (unsigned __int8)_ThreadInterlockedAssignIf64(a1: this, a2: pNode, a3: v7 + 65537, a4: v5, a5: v7) == 0 );
  }
  return Next;
}

//------------------------------------------------------------------------------
// Address: 0x10022340
// Name: public: struct TSLNodeBase_t __near * CTSListBase::Pop(void)
// Source: json
//------------------------------------------------------------------------------
TSLNodeBase_t *__thiscall CTSListBase::Pop(CTSListBase *this)
{
  TSLNodeBase_t *Next; // esi
  int DepthAndSequence; // eax

  Next = this->m_Head.value.Next;
  DepthAndSequence = this->m_Head.value32.DepthAndSequence;
  if ( this->m_Head.value.Next == nullptr )
    return nullptr;
  while ( (unsigned __int8)_ThreadInterlockedAssignIf64(
                             a1: this,
                             a2: Next->Next,
                             a3: DepthAndSequence - 1,
                             a4: Next,
                             a5: DepthAndSequence) == 0 )
  {
    _mm_pause();
    Next = this->m_Head.value.Next;
    DepthAndSequence = this->m_Head.value32.DepthAndSequence;
    if ( this->m_Head.value.Next == nullptr )
      return nullptr;
  }
  return Next;
}

//------------------------------------------------------------------------------
// Address: 0x10022380
// Name: public: struct TSLNodeBase_t __near * CTSListBase::Detach(void)
// Source: json
//------------------------------------------------------------------------------
TSLNodeBase_t *__thiscall CTSListBase::Detach(CTSListBase *this)
{
  TSLNodeBase_t *Next; // esi

  while ( 1 )
  {
    _mm_pause();
    Next = this->m_Head.value.Next;
    if ( this->m_Head.value.Next == nullptr )
      break;
    if ( (unsigned __int8)_ThreadInterlockedAssignIf64(
                            a1: this,
                            a2: 0,
                            a3: this->m_Head.value32.DepthAndSequence & 0xFFFF0000,
                            a4: Next,
                            a5: this->m_Head.value32.DepthAndSequence) != 0 )
      return Next;
  }
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x100223C0
// Name: public: CVMPIPacketIDReg::CVMPIPacketIDReg(int,int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CVMPIPacketIDReg *__thiscall CVMPIPacketIDReg::CVMPIPacketIDReg(
        CVMPIPacketIDReg *this,
        int nPacketID,
        int nSubPacketID,
        const char *pName)
{
  CVMPIPacketIDReg *v5; // edx

  this->m_nPacketID = nPacketID;
  this->m_nSubPacketID = nSubPacketID;
  v5 = g_pVMPIPacketIDRegHead;
  this->m_pName = pName;
  this->m_pNext = v5;
  g_pVMPIPacketIDRegHead = this;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100223F0
// Name: public: static void CVMPIPacketIDReg::Lookup(int,int,char __near *,int,char __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CVMPIPacketIDReg::Lookup(
        int nPacketID,
        int nSubPacketID,
        char *pPacketIDString,
        int nPacketIDStringSize,
        char *pSubPacketIDString,
        int nSubPacketIDStringSize)
{
  CVMPIPacketIDReg *v6; // eax
  CVMPIPacketIDReg *v7; // eax

  v6 = g_pVMPIPacketIDRegHead;
  if ( g_pVMPIPacketIDRegHead != nullptr )
  {
    while ( v6->m_nPacketID != nPacketID || v6->m_nSubPacketID != -1 )
    {
      v6 = v6->m_pNext;
      if ( v6 == nullptr )
        goto LABEL_5;
    }
    V_strncpy(pDest: pPacketIDString, pSrc: (char *)v6->m_pName, maxLen: nPacketIDStringSize);
  }
  else
  {
LABEL_5:
    V_snprintf(pDest: pPacketIDString, maxLen: nPacketIDStringSize, pFormat: "(%d)", nPacketID);
  }
  v7 = g_pVMPIPacketIDRegHead;
  if ( g_pVMPIPacketIDRegHead != nullptr )
  {
    while ( v7->m_nPacketID != nPacketID || v7->m_nSubPacketID != nSubPacketID )
    {
      v7 = v7->m_pNext;
      if ( v7 == nullptr )
        goto LABEL_10;
    }
    V_strncpy(pDest: pSubPacketIDString, pSrc: (char *)v7->m_pName, maxLen: nSubPacketIDStringSize);
  }
  else
  {
LABEL_10:
    V_snprintf(pDest: pSubPacketIDString, maxLen: nSubPacketIDStringSize, pFormat: "(%d)", nSubPacketID);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10022490
// Name: void VMPI_SuperSpew(char const __near *,...)
// Source: json
//------------------------------------------------------------------------------
void VMPI_SuperSpew(const char *pMsg, ...)
{
  char str[2048]; // [esp+0h] [ebp-800h] BYREF
  va_list params; // [esp+80Ch] [ebp+Ch] BYREF

  va_start(params, pMsg);
  if ( g_bSuperSpewEnabled )
  {
    V_vsnprintf(pDest: str, maxLen: 0x800u, pFormat: pMsg, params);
    _Msg(a1: "%s", str);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100224E0
// Name: public: virtual void CVMPILoggingListener::Log(struct LoggingContext_t const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVMPILoggingListener::Log(
        CVMPILoggingListener *this,
        const LoggingContext_t *pContext,
        const char *pMessage)
{
  VMPI_WriteToLogFile(pMsg: "%s", pMessage);
}

//------------------------------------------------------------------------------
// Address: 0x10022500
// Name: char const __near * VMPI_FindArg(int,char __near * __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
char *__cdecl VMPI_FindArg(int argc, char **argv, const char *pName, const char *pDefault)
{
  int v4; // esi

  v4 = 0;
  if ( argc <= 0 )
    return nullptr;
  while ( _V_stricmp(s1: argv[v4], s2: pName) != 0 )
  {
    if ( ++v4 >= argc )
      return nullptr;
  }
  if ( v4 + 1 >= argc )
    return (char *)pDefault;
  else
    return argv[v4 + 1];
}

//------------------------------------------------------------------------------
// Address: 0x10022550
// Name: void SetupDependencyFilename(class CDependencyInfo __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SetupDependencyFilename(CDependencyInfo *pInfo, char *pPatchDirectory)
{
  HMODULE ModuleHandleA; // eax
  char *v3; // eax
  char baseExeFilename[512]; // [esp+0h] [ebp-200h] BYREF

  ModuleHandleA = GetModuleHandleA(lpModuleName: nullptr);
  if ( GetModuleFileNameA(hModule: ModuleHandleA, lpFilename: baseExeFilename, nSize: 0x200u) == 0 )
    _Error(a1: "GetModuleFileName failed.");
  if ( pPatchDirectory != nullptr )
  {
    V_strncpy(pDest: pInfo->m_DependencyFilesDir, pSrc: pPatchDirectory, maxLen: 260);
  }
  else
  {
    V_strncpy(pDest: pInfo->m_DependencyFilesDir, pSrc: baseExeFilename, maxLen: 260);
    V_StripLastDir(dirName: pInfo->m_DependencyFilesDir, maxlen: 0x104u);
  }
  v3 = (char *)V_UnqualifiedFileName(in: baseExeFilename);
  V_strncpy(pDest: pInfo->m_OriginalExeFilename, pSrc: v3, maxLen: 260);
}

//------------------------------------------------------------------------------
// Address: 0x100225F0
// Name: public: void CMasterBroadcaster::Term(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMasterBroadcaster::Term(CMasterBroadcaster *this)
{
  ISocket *m_pSocket; // ecx
  ITCPConnectSocket *m_pDownloaderListenSocket; // ecx

  if ( this->m_hThread != nullptr )
  {
    CEvent::SetEvent(this: &this->m_hShutdownEvent);
    WaitForSingleObject(hHandle: this->m_hThread, dwMilliseconds: 0xFFFFFFFF);
    CloseHandle(hObject: this->m_hThread);
    this->m_hThread = nullptr;
  }
  m_pSocket = this->m_pSocket;
  if ( m_pSocket != nullptr )
  {
    m_pSocket->Release(this: m_pSocket);
    this->m_pSocket = nullptr;
  }
  if ( this->m_pListenSocket != nullptr )
  {
    this->m_pListenSocket->Release(this: this->m_pListenSocket);
    this->m_pListenSocket = nullptr;
  }
  m_pDownloaderListenSocket = this->m_pDownloaderListenSocket;
  if ( m_pDownloaderListenSocket != nullptr )
  {
    m_pDownloaderListenSocket->Release(this: m_pDownloaderListenSocket);
    this->m_pDownloaderListenSocket = nullptr;
  }
  this->m_iDownloaderListenPort = -1;
  this->m_iListenPort = -1;
}

//------------------------------------------------------------------------------
// Address: 0x10022680
// Name: public: CDispatchReg::CDispatchReg(int,bool (*)(class MessageBuffer __near *,int,int))
// Source: json
//------------------------------------------------------------------------------
CDispatchReg *__thiscall CDispatchReg::CDispatchReg(
        CDispatchReg *this,
        int iPacketID,
        bool (__cdecl *fn)(MessageBuffer *, int, int))
{
  g_VMPIDispatch[iPacketID] = fn;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100226A0
// Name: bool VMPI_CheckForNonSDKExecutables(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl VMPI_CheckForNonSDKExecutables()
{
  HMODULE ModuleHandleA; // eax
  char baseExeFilename[512]; // [esp+0h] [ebp-200h] BYREF

  ModuleHandleA = GetModuleHandleA(lpModuleName: nullptr);
  if ( GetModuleFileNameA(hModule: ModuleHandleA, lpFilename: baseExeFilename, nSize: 0x200u) == 0 )
    _Error(a1: "VMPI_CheckSDKMode -> GetModuleFileName failed.");
  V_StripLastDir(dirName: baseExeFilename, maxlen: 0x200u);
  V_AppendSlash(pStr: baseExeFilename, strSize: 512);
  V_strncat(pDest: baseExeFilename, pSrc: "mysql_wrapper.dll", destBufferSize: 0x200u, max_chars_to_copy: -1);
  return access(path: baseExeFilename, amode: 0) == 0;
}

//------------------------------------------------------------------------------
// Address: 0x10022730
// Name: enum VMPIRunMode VMPI_GetRunMode(void)
// Source: json
//------------------------------------------------------------------------------
VMPIRunMode __cdecl VMPI_GetRunMode()
{
  return g_VMPIRunMode;
}

//------------------------------------------------------------------------------
// Address: 0x10022740
// Name: enum VMPIFileSystemMode VMPI_GetFileSystemMode(void)
// Source: json
//------------------------------------------------------------------------------
VMPIFileSystemMode __cdecl VMPI_GetFileSystemMode()
{
  return g_VMPIFileSystemMode;
}

//------------------------------------------------------------------------------
// Address: 0x10022750
// Name: int VMPI_GetCurrentNumberOfConnections(void)
// Source: json
//------------------------------------------------------------------------------
int __cdecl VMPI_GetCurrentNumberOfConnections()
{
  return g_nConnections;
}

//------------------------------------------------------------------------------
// Address: 0x10022760
// Name: bool VMPI_FilterPacketsForServiceDownloader(class CVMPIConnection __near *,void const __near * const __near *,int const __near *,int)
// Source: json
//------------------------------------------------------------------------------
char __cdecl VMPI_FilterPacketsForServiceDownloader(
        CVMPIConnection *pConnection,
        const void *const *pChunks,
        const int *pChunkLengths,
        int nChunks)
{
  int v4; // eax
  int v5; // ecx
  unsigned __int8 *v7; // eax
  unsigned __int8 v8; // dl
  int v9; // eax
  char szPacketID[64]; // [esp+4h] [ebp-80h] BYREF
  char szSubPacketID[64]; // [esp+44h] [ebp-40h] BYREF

  if ( !pConnection->m_bIsAService )
    return 0;
  v4 = 0;
  if ( nChunks <= 0 )
    return 0;
  while ( 1 )
  {
    v5 = pChunkLengths[v4];
    if ( v5 >= 1 )
      break;
    if ( ++v4 >= nChunks )
      return 0;
  }
  v7 = (unsigned __int8 *)pChunks[v4];
  v8 = *v7;
  if ( *v7 == 27 || v8 == 10 || v8 == 0 )
    return 0;
  if ( g_bSuperSpewEnabled )
  {
    if ( v5 < 2 )
      v9 = -1;
    else
      v9 = v7[1];
    CVMPIPacketIDReg::Lookup(
      nPacketID: v8,
      nSubPacketID: v9,
      pPacketIDString: szPacketID,
      nPacketIDStringSize: 64,
      pSubPacketIDString: szSubPacketID,
      nSubPacketIDStringSize: 64);
    VMPI_SuperSpew(
      pMsg: "VMPI_FilterPacketsForServiceDownloader filtered packetID %s, subPacketID %s\n",
      szPacketID,
      szSubPacketID);
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10022800
// Name: bool VMPI_IsProcValid(int)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl VMPI_IsProcValid(int procID)
{
  return procID >= 0 && procID < g_nConnections && g_Connections[procID] != nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10022830
// Name: bool VMPI_IsProcConnected(int)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl VMPI_IsProcConnected(int procID)
{
  CVMPIConnection *v1; // eax

  return procID >= 0 && procID < g_nConnections && (v1 = g_Connections[procID]) != nullptr && v1->m_pSocket != nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10022860
// Name: void VMPI_Sleep(unsigned long)
// Source: json
//------------------------------------------------------------------------------
void __cdecl VMPI_Sleep(DWORD ms)
{
  Sleep(dwMilliseconds: ms);
}

//------------------------------------------------------------------------------
// Address: 0x10022870
// Name: unsigned long VMPI_GetJobWorkerID(int)
// Source: json
//------------------------------------------------------------------------------
unsigned int __cdecl VMPI_GetJobWorkerID(int iProc)
{
  return g_Connections[iProc]->m_JobWorkerID;
}

//------------------------------------------------------------------------------
// Address: 0x10022890
// Name: void VMPI_GetCurrentStage(char __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl VMPI_GetCurrentStage(char *pOut, int strLen)
{
  CCriticalSectionLock csLock; // [esp+0h] [ebp-8h] BYREF

  CCriticalSectionLock::CCriticalSectionLock(this: &csLock, pCS: &g_CurrentStageCS);
  CCriticalSectionLock::Lock(this: &csLock);
  V_strncpy(pDest: pOut, pSrc: g_CurrentStageString, maxLen: strLen);
  CCriticalSectionLock::~CCriticalSectionLock(this: &csLock);
}

//------------------------------------------------------------------------------
// Address: 0x100228D0
// Name: void VMPI_SetCurrentStage(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl VMPI_SetCurrentStage(char *pCurStage)
{
  CCriticalSectionLock csLock; // [esp+0h] [ebp-8h] BYREF

  CCriticalSectionLock::CCriticalSectionLock(this: &csLock, pCS: &g_CurrentStageCS);
  CCriticalSectionLock::Lock(this: &csLock);
  V_strncpy(pDest: g_CurrentStageString, pSrc: pCurStage, maxLen: 128);
  CCriticalSectionLock::~CCriticalSectionLock(this: &csLock);
}

//------------------------------------------------------------------------------
// Address: 0x10022910
// Name: bool VMPI_IsSDKMode(void)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl VMPI_IsSDKMode()
{
  if ( g_bVMPISDKModeSet )
    return g_bVMPISDKMode;
  else
    return !VMPI_CheckForNonSDKExecutables();
}

//------------------------------------------------------------------------------
// Address: 0x10022930
// Name: char const __near * VMPI_GetParamString(enum EVMPICmdLineParam)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl VMPI_GetParamString(EVMPICmdLineParam eParam)
{
  if ( (unsigned int)(eParam - 1) <= 0x19 )
    return g_VMPIParams[eParam].m_pName;
  _Warning(a1: "Invalid call: VMPI_GetParamString( %d )\n", eParam);
  return "unknown";
}

//------------------------------------------------------------------------------
// Address: 0x10022960
// Name: bool VMPI_IsParamUsed(enum EVMPICmdLineParam)
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl VMPI_IsParamUsed(EVMPICmdLineParam eParam)
{
  int v1; // esi

  v1 = _CommandLine();
  if ( (unsigned int)(eParam - 1) <= 0x19 )
    return (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v1 + 40))(a1: v1, a2: g_VMPIParams[eParam].m_pName) != 0;
  _Warning(a1: "Invalid call: VMPI_GetParamString( %d )\n", eParam);
  return (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v1 + 40))(a1: v1, a2: "unknown") != 0;
}

//------------------------------------------------------------------------------
// Address: 0x100229C0
// Name: void ParseOptions(int,char __near * __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ParseOptions(int argc, char **argv)
{
  char *Arg; // eax
  char *v3; // eax
  char v4; // al

  if ( VMPI_FindArg(argc, argv, pName: g_VMPIParams[18].m_pName, pDefault: defaultValue) != nullptr )
    ThreadedTCP_EnableTimeouts(bEnable: false);
  if ( VMPI_FindArg(argc, argv, pName: g_VMPIParams[19].m_pName, pDefault: defaultValue) != nullptr )
  {
    _Msg(a1: "%s found.\n", g_VMPIParams[19].m_pName);
    g_bSetThreadPriorities = false;
    ThreadedTCP_SetTCPSocketThreadPriorities(bSetTCPSocketThreadPriorities: false);
  }
  if ( VMPI_FindArg(argc, argv, pName: g_VMPIParams[20].m_pName, pDefault: defaultValue) != nullptr )
  {
    _Msg(a1: "%s found.\n", g_VMPIParams[20].m_pName);
    g_bGroupPackets = true;
  }
  Arg = VMPI_FindArg(argc, argv, pName: g_VMPIParams[12].m_pName, pDefault: "1");
  if ( Arg != nullptr )
    MULTICAST_TRANSMIT_RATE = atoi(nptr: Arg) << 10;
  v3 = VMPI_FindArg(argc, argv, pName: g_VMPIParams[13].m_pName, pDefault: "1");
  if ( v3 != nullptr )
  {
    v4 = *v3;
    if ( v4 == 49 )
    {
      g_iVMPIVerboseLevel = 1;
    }
    else if ( v4 == 50 )
    {
      g_iVMPIVerboseLevel = 2;
    }
  }
  if ( VMPI_FindArg(argc, argv, pName: g_VMPIParams[21].m_pName, pDefault: defaultValue) != nullptr )
    g_bMPI_Stats = true;
  if ( VMPI_FindArg(argc, argv, pName: g_VMPIParams[22].m_pName, pDefault: defaultValue) != nullptr )
    g_bMPI_StatsTextOutput = true;
}

//------------------------------------------------------------------------------
// Address: 0x10022B10
// Name: void CountActiveConnections(int __near *,int __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CountActiveConnections(int *nRegularWorkers, int *nServiceDownloaders)
{
  int v2; // ebx
  int i; // ecx
  CVMPIConnection *v4; // eax

  *nServiceDownloaders = 0;
  *nRegularWorkers = 0;
  v2 = g_nConnections;
  for ( i = 0; i < v2; ++i )
  {
    if ( i >= 0 && i < g_nConnections )
    {
      v4 = g_Connections[i];
      if ( v4 != nullptr && v4->m_pSocket != nullptr )
      {
        if ( v4->m_bIsAService )
          ++*nServiceDownloaders;
        else
          ++*nRegularWorkers;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10022B70
// Name: void UpdateActiveConnectionsText(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl UpdateActiveConnectionsText()
{
  HWND v0; // esi
  char str[512]; // [esp+0h] [ebp-208h] BYREF
  int nDownloaders; // [esp+200h] [ebp-8h] BYREF
  int nRegularWorkers; // [esp+204h] [ebp-4h] BYREF

  if ( g_bMPIMaster && g_pConsoleWndFn != nullptr )
  {
    v0 = g_pConsoleWndFn();
    if ( v0 != nullptr )
    {
      CountActiveConnections(&nRegularWorkers, nServiceDownloaders: &nDownloaders);
      if ( g_bVMPISDKMode )
        V_snprintf(pDest: str, maxLen: 0x200u, pFormat: "VMPI (SDK) - Workers: %d", nRegularWorkers);
      else
        V_snprintf(
          pDest: str,
          maxLen: 0x200u,
          pFormat: "VMPI - Workers: %d, Downloaders: %d",
          nRegularWorkers,
          nDownloaders);
      SetWindowTextA(hWnd: v0, lpString: str);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10022C10
// Name: bool SpawnLocalWorker(int,char __near * __near *,int,bool)
// Source: json
//------------------------------------------------------------------------------
char __cdecl SpawnLocalWorker(int argc, char **argv, int iListenPort, bool bShowConsoleWindow)
{
  int i; // ebx
  const char *m_pName; // edi
  int v7; // esi
  char CommandLine[4096]; // [esp+Ch] [ebp-1854h] BYREF
  char pnbuf[1024]; // [esp+100Ch] [ebp-854h] BYREF
  char pStr[512]; // [esp+140Ch] [ebp-454h] BYREF
  char pDest[512]; // [esp+160Ch] [ebp-254h] BYREF
  _STARTUPINFOA dst; // [esp+180Ch] [ebp-54h] BYREF
  _PROCESS_INFORMATION ProcessInformation; // [esp+1850h] [ebp-10h] BYREF

  CommandLine[0] = 0;
  for ( i = 0; i < 9999999; ++i )
  {
    if ( i == 1 )
    {
      V_snprintf(pDest, maxLen: 0x200u, pFormat: "-mpi_worker 127.0.0.1:%d ", iListenPort);
      V_strncat(pDest: CommandLine, pSrc: pDest, destBufferSize: 0x1000u, max_chars_to_copy: -1);
      V_strncat(pDest: CommandLine, pSrc: "-allowdebug ", destBufferSize: 0x1000u, max_chars_to_copy: -1);
      if ( g_bVMPISDKModeSet ? g_bVMPISDKMode : !VMPI_CheckForNonSDKExecutables() )
      {
        m_pName = g_VMPIParams[15].m_pName;
        v7 = 0;
        if ( argc <= 0 )
          goto LABEL_13;
        while ( _V_stricmp(s1: argv[v7], s2: m_pName) != 0 )
        {
          if ( ++v7 >= argc )
            goto LABEL_13;
        }
        if ( v7 + 1 < argc && argv[v7 + 1] == nullptr )
LABEL_13:
          V_strncat(pDest: CommandLine, pSrc: g_VMPIParams[15].m_pName, destBufferSize: 0x1000u, max_chars_to_copy: -1);
      }
    }
    if ( i >= argc )
      break;
    V_snprintf(pDest, maxLen: 0x200u, pFormat: "\"%s\" ", argv[i]);
    V_strncat(pDest: CommandLine, pSrc: pDest, destBufferSize: 0x1000u, max_chars_to_copy: -1);
  }
  if ( _getcwd(pnbuf, maxlen: 1024) != nullptr )
  {
    memset((unsigned __int8 *)&dst, value: 0, count: sizeof(dst));
    dst.cb = 68;
    memset(&ProcessInformation, 0, sizeof(ProcessInformation));
    if ( CreateProcessA(
           lpApplicationName: nullptr,
           lpCommandLine: CommandLine,
           lpProcessAttributes: nullptr,
           lpThreadAttributes: nullptr,
           bInheritHandles: true,
           dwCreationFlags: (bShowConsoleWindow ? 16 : 0x8000000) | 0x40,
           lpEnvironment: nullptr,
           lpCurrentDirectory: pnbuf,
           lpStartupInfo: &dst,
           lpProcessInformation: &ProcessInformation) )
    {
      return 1;
    }
    else
    {
      IP_GetLastErrorString(pStr, maxLen: 1024);
      _Warning(a1: " - ERROR in CreateProcess (%s)!\n", pStr);
      return 0;
    }
  }
  else
  {
    _Warning(a1: "_getcwd() failed.\n");
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10022EB0
// Name: private: void CMasterBroadcaster::BuildBroadcastPacket(class bf_write __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMasterBroadcaster::BuildBroadcastPacket(CMasterBroadcaster *this, bf_write *buf)
{
  bf_write *v2; // esi
  bool v4; // zf
  const char *v5; // eax
  int i; // ebx

  v2 = buf;
  bf_write::WriteByte(this: buf, val: 5u);
  bf_write::WriteString(this: v2, pStr: this->m_BroadcastInfo.m_Password);
  if ( this->m_BroadcastInfo.m_PatchVersion[0] != 0 )
    bf_write::WriteByte(this: v2, val: 0x4Fu);
  else
    bf_write::WriteByte(this: v2, val: 0x47u);
  bf_write::WriteString(this: v2, pStr: this->m_BroadcastInfo.m_PatchVersion);
  bf_write::WriteLong(this: v2, val: this->m_iListenPort);
  bf_write::WriteLong(this: v2, val: this->m_BroadcastInfo.m_JobID[0]);
  bf_write::WriteLong(this: v2, val: this->m_BroadcastInfo.m_JobID[1]);
  bf_write::WriteLong(this: v2, val: this->m_BroadcastInfo.m_JobID[2]);
  bf_write::WriteLong(this: v2, val: this->m_BroadcastInfo.m_JobID[3]);
  bf_write::WriteWord(this: v2, val: this->m_BroadcastInfo.m_Args.m_Size + 2);
  bf_write::WriteString(this: v2, pStr: this->m_BroadcastInfo.m_WorkerExeFilename);
  bf_write::WriteString(this: v2, pStr: "-mpi_MasterName");
  buf = (bf_write *)16;
  v4 = !GetComputerNameA(lpBuffer: Buffer, nSize: (LPDWORD)&buf);
  v5 = Buffer;
  if ( v4 )
    v5 = "(error in GetComputerName)";
  bf_write::WriteString(this: v2, pStr: v5);
  for ( i = 1; i < this->m_BroadcastInfo.m_Args.m_Size; ++i )
    bf_write::WriteString(this: v2, pStr: this->m_BroadcastInfo.m_Args.m_Memory.m_pMemory[i]);
  bf_write::WriteByte(this: v2, val: 1u);
  bf_write::WriteShort(this: v2, val: this->m_iDownloaderListenPort);
}

//------------------------------------------------------------------------------
// Address: 0x10022FD0
// Name: bool IsValidSDKBinPath(class CUtlVector<char __near *,class CUtlMemory<char __near *,int>> __near &,int __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl IsValidSDKBinPath(CUtlVector<char *,CUtlMemory<char *,int> > *outStrings, int *pError)
{
  int m_Size; // eax
  int i; // edi
  int j; // edi
  char mapsrcFilename[260]; // [esp+8h] [ebp-54Ch] BYREF
  char blobPath[260]; // [esp+10Ch] [ebp-448h] BYREF
  char tempFilename[260]; // [esp+210h] [ebp-344h] BYREF
  char baseSteamPath[260]; // [esp+314h] [ebp-240h] BYREF
  char sourcesdkContentPath[260]; // [esp+418h] [ebp-13Ch] BYREF
  _stat64i32 results; // [esp+51Ch] [ebp-38h] BYREF
  __int64 curTime; // [esp+54Ch] [ebp-8h] BYREF

  *pError = 0;
  m_Size = outStrings->m_Size;
  if ( m_Size >= 9 )
  {
    if ( _V_stricmp(s1: outStrings->m_Memory.m_pMemory[m_Size - 2], s2: "bin") != 0 )
    {
      *pError = 1;
      return 0;
    }
    else if ( _V_stricmp(s1: outStrings->m_Memory.m_pMemory[outStrings->m_Size - 5], s2: "sourcesdk") != 0 )
    {
      *pError = 2;
      return 0;
    }
    else if ( _V_stricmp(s1: outStrings->m_Memory.m_pMemory[outStrings->m_Size - 7], s2: "steamapps") != 0 )
    {
      *pError = 3;
      return 0;
    }
    else
    {
      V_strncpy(pDest: baseSteamPath, pSrc: *outStrings->m_Memory.m_pMemory, maxLen: 260);
      for ( i = 1; i < outStrings->m_Size - 7; ++i )
      {
        V_AppendSlash(pStr: baseSteamPath, strSize: 260);
        V_strncat(
          pDest: baseSteamPath,
          pSrc: outStrings->m_Memory.m_pMemory[i],
          destBufferSize: 0x104u,
          max_chars_to_copy: -1);
      }
      V_ComposeFileName(path: baseSteamPath, filename: "ClientRegistry.blob", dest: blobPath, destSize: 260);
      if ( _stat64i32(name: blobPath, buf: &results) != 0 )
      {
        *pError = 4;
        return 0;
      }
      else
      {
        _time64(timeptr: &curTime);
        if ( (int)curTime - LODWORD(results.st_mtime) <= 864000 )
        {
          V_strncpy(pDest: sourcesdkContentPath, pSrc: *outStrings->m_Memory.m_pMemory, maxLen: 260);
          for ( j = 1; j < outStrings->m_Size - 5; ++j )
          {
            V_AppendSlash(pStr: sourcesdkContentPath, strSize: 260);
            V_strncat(
              pDest: sourcesdkContentPath,
              pSrc: outStrings->m_Memory.m_pMemory[j],
              destBufferSize: 0x104u,
              max_chars_to_copy: -1);
          }
          V_AppendSlash(pStr: sourcesdkContentPath, strSize: 260);
          V_strncat(
            pDest: sourcesdkContentPath,
            pSrc: "sourcesdk_content",
            destBufferSize: 0x104u,
            max_chars_to_copy: -1);
          V_snprintf(pDest: tempFilename, maxLen: 0x104u, pFormat: "cstrike%cmapsrc", 92);
          V_ComposeFileName(path: sourcesdkContentPath, filename: tempFilename, dest: mapsrcFilename, destSize: 260);
          if ( access(path: mapsrcFilename, amode: 0) != 0 )
          {
            *pError = 6;
            return 0;
          }
          else
          {
            return 1;
          }
        }
        else
        {
          *pError = 5;
          return 0;
        }
      }
    }
  }
  else
  {
    *pError = 0;
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10023250
// Name: void VerifyValidSDKMode(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl VerifyValidSDKMode()
{
  HMODULE ModuleHandleA; // eax
  char baseExeFilename[260]; // [esp+4h] [ebp-124h] BYREF
  CSplitString outStrings; // [esp+108h] [ebp-20h] BYREF
  int err; // [esp+120h] [ebp-8h] BYREF
  char strSlash[4]; // [esp+124h] [ebp-4h] BYREF

  ModuleHandleA = GetModuleHandleA(lpModuleName: nullptr);
  if ( GetModuleFileNameA(hModule: ModuleHandleA, lpFilename: baseExeFilename, nSize: 0x104u) == 0 )
    _Error(a1: "VerifyValidSDKMode: GetModuleFileName failed.");
  V_FixSlashes(pname: baseExeFilename, separator: 92);
  strcpy(strSlash, "\\");
  CSplitString::CSplitString(this: &outStrings, pString: baseExeFilename, pSeparator: strSlash);
  if ( IsValidSDKBinPath(&outStrings, pError: &err) == 0 )
  {
    if ( err == 5 )
    {
      _Error(a1: "VMPI running in SDK mode but Steam hasn't been run recently. Please run Steam and retry.");
      CSplitString::~CSplitString(this: &outStrings);
      return;
    }
    _Error(a1: "VMPI running in SDK mode but incorrect SDK install detected (error %d).", err);
  }
  CSplitString::~CSplitString(this: &outStrings);
}

//------------------------------------------------------------------------------
// Address: 0x10023300
// Name: void VMPI_CheckSDKMode(int,char __near * __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl VMPI_CheckSDKMode(int argc, char **argv)
{
  bool v2; // al

  if ( g_bIsRunningVMPITransfer )
  {
    g_bVMPISDKMode = false;
    g_bVMPISDKModeSet = true;
    return;
  }
  v2 = VMPI_CheckForNonSDKExecutables();
  g_bVMPISDKMode = !v2;
  g_bVMPISDKModeSet = true;
  if ( v2 )
  {
    if ( VMPI_FindArg(argc, argv, pName: g_VMPIParams[15].m_pName, pDefault: defaultValue) != nullptr )
    {
      g_bVMPISDKMode = true;
    }
    else if ( !g_bVMPISDKMode )
    {
      return;
    }
  }
  VerifyValidSDKMode();
  if ( g_bVMPISDKMode )
    _Msg(a1: "VMPI running in SDK mode.\n");
}

//------------------------------------------------------------------------------
// Address: 0x10023390
// Name: char const __near * VMPI_GetMachineName(int)
// Source: json
//------------------------------------------------------------------------------
char *__cdecl VMPI_GetMachineName(int iProc)
{
  bool v1; // sf
  bool v2; // zf
  char *result; // eax
  CVMPIConnection *v4; // eax
  unsigned int nSize; // [esp+0h] [ebp-4h] BYREF

  if ( g_bMPIMaster )
  {
    v1 = iProc < 0;
    if ( iProc == 0 )
    {
      nSize = 16;
      v2 = !GetComputerNameA(lpBuffer: Buffer, &nSize);
      result = Buffer;
      if ( v2 )
        return "(error in GetComputerName)";
      return result;
    }
  }
  else
  {
    v1 = iProc < 0;
  }
  if ( v1 )
    return "invalid index";
  if ( iProc >= g_nConnections )
    return "invalid index";
  v4 = g_Connections[iProc];
  if ( v4 == nullptr )
    return "invalid index";
  else
    return v4->m_MachineName.m_Memory.m_pMemory;
}

//------------------------------------------------------------------------------
// Address: 0x100238B0
// Name: public: void CVMPIConnection::HandleDisconnect(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVMPIConnection::HandleDisconnect(CVMPIConnection *this)
{
  int m_Head; // esi
  UtlLinkedListElem_t<void (__cdecl*)(int,char const *),int> *m_pMemory; // eax
  int v4; // esi
  char str[512]; // [esp+4h] [ebp-208h] BYREF
  CCriticalSectionLock csLock; // [esp+204h] [ebp-8h] BYREF

  if ( this->m_pSocket != nullptr )
  {
    CCriticalSectionLock::CCriticalSectionLock(this: &csLock, pCS: &g_ErrorSocketsCS);
    CCriticalSectionLock::Lock(this: &csLock);
    V_strncpy(pDest: str, pSrc: this->m_ErrorString.m_Memory.m_pMemory, maxLen: 512);
    CCriticalSectionLock::Unlock(this: &csLock);
    m_Head = g_DisconnectHandlers.m_Head;
    if ( g_DisconnectHandlers.m_Head != -1 )
    {
      m_pMemory = g_DisconnectHandlers.m_Memory.m_pMemory;
      do
      {
        v4 = m_Head;
        m_pMemory[v4].m_Element(a1: this->m_iConnection, a2: str);
        m_pMemory = g_DisconnectHandlers.m_Memory.m_pMemory;
        m_Head = g_DisconnectHandlers.m_Memory.m_pMemory[v4].m_Next;
      }
      while ( m_Head != -1 );
    }
    this->m_pSocket->Release(this: this->m_pSocket);
    this->m_pSocket = nullptr;
    CCriticalSectionLock::~CCriticalSectionLock(this: &csLock);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10023960
// Name: bool VMPI_HandleAutoRestart(void)
// Source: json
//------------------------------------------------------------------------------
char __usercall VMPI_HandleAutoRestart@<al>(int a1@<ebp>)
{
  void *v1; // esp
  HANDLE CurrentProcess; // eax
  int v3; // esi
  DWORD PriorityClass; // edi
  char **m_pMemory; // eax
  char v7[8192]; // [esp-2458h] [ebp-2464h] BYREF
  char v8[512]; // [esp-458h] [ebp-464h] BYREF
  char v9[512]; // [esp-258h] [ebp-264h] BYREF
  _STARTUPINFOA v10; // [esp-58h] [ebp-64h] BYREF
  _PROCESS_INFORMATION v11; // [esp-10h] [ebp-1Ch] BYREF
  int v12; // [esp+0h] [ebp-Ch]
  void *v13; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v12 = a1;
  v13 = retaddr;
  v1 = alloca(9304);
  if ( g_OriginalCommandLineParameters.m_Size == 0 )
    return 1;
  _Msg(a1: "%s found. Auto-restarting.\n", g_VMPIParams[6].m_pName);
  CurrentProcess = GetCurrentProcess();
  v3 = 0;
  PriorityClass = GetPriorityClass(hProcess: CurrentProcess);
  for ( v7[0] = 0; v3 < g_OriginalCommandLineParameters.m_Size; ++v3 )
  {
    V_snprintf(pDest: v9, maxLen: 0x200u, pFormat: "\"%s\" ", g_OriginalCommandLineParameters.m_Memory.m_pMemory[v3]);
    V_strncat(pDest: v7, pSrc: v9, destBufferSize: 0x2000u, max_chars_to_copy: -1);
  }
  memset(dst: (unsigned __int8 *)&v10, value: 0, count: sizeof(v10));
  v10.cb = 68;
  v11 = 0;
  if ( CreateProcessA(
         lpApplicationName: nullptr,
         lpCommandLine: v7,
         lpProcessAttributes: nullptr,
         lpThreadAttributes: nullptr,
         bInheritHandles: true,
         dwCreationFlags: PriorityClass | 0x10,
         lpEnvironment: nullptr,
         lpCurrentDirectory: nullptr,
         lpStartupInfo: &v10,
         lpProcessInformation: &v11) )
  {
    m_pMemory = g_OriginalCommandLineParameters.m_Memory.m_pMemory;
    g_OriginalCommandLineParameters.m_Size = 0;
    if ( g_OriginalCommandLineParameters.m_Memory.m_nGrowSize >= 0 )
    {
      if ( g_OriginalCommandLineParameters.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: g_OriginalCommandLineParameters.m_Memory.m_pMemory);
        m_pMemory = nullptr;
        g_OriginalCommandLineParameters.m_Memory.m_pMemory = nullptr;
      }
      g_OriginalCommandLineParameters.m_Memory.m_nAllocationCount = 0;
    }
    g_OriginalCommandLineParameters.m_pElements = m_pMemory;
    return 1;
  }
  IP_GetLastErrorString(pStr: v8, maxLen: 1024);
  _Warning(a1: " - ERROR in CreateProcess (%s)!\n", v8);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10023AD0
// Name: void VMPI_FlushGroupedPackets(unsigned long)
// Source: json
//------------------------------------------------------------------------------
void __cdecl VMPI_FlushGroupedPackets(unsigned int msInterval)
{
  int v1; // eax
  int i; // ebx
  CVMPIConnection *v3; // esi
  IThreadedTCPSocket *m_pSocket; // ecx
  int j; // edi
  CCriticalSectionLock connectionsLock; // [esp+4h] [ebp-8h] BYREF

  if ( msInterval != 0 )
  {
    v1 = _Plat_MSTime();
    if ( v1 - g_LastFlushGroupedPacketsTime < msInterval )
      return;
    g_LastFlushGroupedPacketsTime = v1;
  }
  CCriticalSectionLock::CCriticalSectionLock(this: &connectionsLock, pCS: &g_ConnectionsCS);
  CCriticalSectionLock::Lock(this: &connectionsLock);
  for ( i = 0; i < g_nConnections; ++i )
  {
    v3 = g_Connections[i];
    if ( v3 != nullptr )
    {
      m_pSocket = v3->m_pSocket;
      if ( m_pSocket != nullptr && v3->m_GroupedChunks.m_Size != 0 )
      {
        m_pSocket->SendChunks(
          this: m_pSocket,
          a2: (const void *const *)v3->m_GroupedChunks.m_Memory.m_pMemory,
          a3: v3->m_GroupedChunkLengths.m_Memory.m_pMemory,
          a4: v3->m_GroupedChunks.m_Size);
        for ( j = 1; j < v3->m_GroupedChunks.m_Size; ++j )
          free(pBlock: v3->m_GroupedChunks.m_Memory.m_pMemory[j]);
        v3->m_GroupedChunks.m_Size = 0;
        v3->m_GroupedChunkLengths.m_Size = 0;
      }
    }
  }
  CCriticalSectionLock::~CCriticalSectionLock(this: &connectionsLock);
}

//------------------------------------------------------------------------------
// Address: 0x10023C20
// Name: public: void CMasterBroadcaster::SetNoTimeoutOption(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMasterBroadcaster::SetNoTimeoutOption(CMasterBroadcaster *this)
{
  int v2; // edi
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  const char *m_pName; // edi
  char **m_pMemory; // eax
  int v7; // ecx
  char **v8; // esi
  CCriticalSectionLock connectionsLock; // [esp+8h] [ebp-8h] BYREF

  CCriticalSectionLock::CCriticalSectionLock(this: &connectionsLock, pCS: &g_ConnectionsCS);
  CCriticalSectionLock::Lock(this: &connectionsLock);
  v2 = 1;
  if ( this->m_BroadcastInfo.m_Args.m_Size <= 1 )
  {
LABEL_4:
    m_Size = this->m_BroadcastInfo.m_Args.m_Size;
    m_nAllocationCount = this->m_BroadcastInfo.m_Args.m_Memory.m_nAllocationCount;
    m_pName = g_VMPIParams[18].m_pName;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<int,int>::Grow(
        this: (CUtlMemory<CTCPPacket *,int> *)&this->m_BroadcastInfo.m_Args,
        num: m_Size - m_nAllocationCount + 1);
    ++this->m_BroadcastInfo.m_Args.m_Size;
    m_pMemory = this->m_BroadcastInfo.m_Args.m_Memory.m_pMemory;
    v7 = this->m_BroadcastInfo.m_Args.m_Size - 2;
    this->m_BroadcastInfo.m_Args.m_pElements = m_pMemory;
    if ( v7 > 0 )
      _V_memmove(dest: (unsigned __int8 *)m_pMemory + 8, src: (unsigned __int8 *)m_pMemory + 4, count: 4 * v7);
    v8 = this->m_BroadcastInfo.m_Args.m_Memory.m_pMemory + 1;
    if ( v8 != nullptr )
      *v8 = (char *)m_pName;
  }
  else
  {
    while ( _V_stricmp(s1: this->m_BroadcastInfo.m_Args.m_Memory.m_pMemory[v2], s2: g_VMPIParams[18].m_pName) != 0 )
    {
      if ( ++v2 >= this->m_BroadcastInfo.m_Args.m_Size )
        goto LABEL_4;
    }
  }
  CCriticalSectionLock::~CCriticalSectionLock(this: &connectionsLock);
}

//------------------------------------------------------------------------------
// Address: 0x10023CF0
// Name: void VMPI_InviteDebugWorkers(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl VMPI_InviteDebugWorkers()
{
  int v0; // eax
  CCriticalSectionLock v1; // [esp+0h] [ebp-8h] BYREF

  CCriticalSectionLock::CCriticalSectionLock(this: &v1, pCS: &g_ConnectionsCS);
  CCriticalSectionLock::Lock(this: &v1);
  V_strncpy(pDest: g_MasterBroadcaster.m_BroadcastInfo.m_Password, pSrc: "debugworker", maxLen: 256);
  CCriticalSectionLock::~CCriticalSectionLock(this: &v1);
  CMasterBroadcaster::SetNoTimeoutOption(this: &g_MasterBroadcaster);
  ThreadedTCP_EnableTimeouts(bEnable: false);
  CCriticalSectionLock::CCriticalSectionLock(this: &v1, pCS: &g_ConnectionsCS);
  CCriticalSectionLock::Lock(this: &v1);
  v0 = g_MasterBroadcaster.m_nMaxWorkers + 25;
  g_MasterBroadcaster.m_nMaxWorkers = 512;
  if ( v0 <= 512 )
    g_MasterBroadcaster.m_nMaxWorkers = v0;
  CCriticalSectionLock::~CCriticalSectionLock(this: &v1);
}

//------------------------------------------------------------------------------
// Address: 0x10023E60
// Name: void ParseDependencyFile(class CDependencyInfo __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ParseDependencyFile(CDependencyInfo *pInfo, const char *pDepFilename)
{
  _iobuf *v2; // esi
  int v3; // eax
  char v4; // cl
  bool v5; // zf
  char *v6; // eax
  CDependencyInfo::CDependencyFile *v7; // edi
  char v8; // bl
  char *v9; // eax
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CDependencyInfo::CDependencyFile **m_pMemory; // ecx
  int v13; // eax
  CDependencyInfo::CDependencyFile **v14; // eax
  char fullFilename[260]; // [esp+Ch] [ebp-210h] BYREF
  char tempStr[260]; // [esp+110h] [ebp-10Ch] BYREF
  _iobuf *fp; // [esp+214h] [ebp-8h]
  CDependencyInfo::CDependencyFile *pFile; // [esp+218h] [ebp-4h]

  fp = fopen(file: pDepFilename, mode: "rt");
  if ( fp == nullptr )
    _Error(a1: "Can't find %s.", pDepFilename);
  while ( 1 )
  {
    v2 = fp;
    if ( fgets(string: tempStr, count: 260, str: fp) == nullptr || tempStr[0] == 0 )
      break;
    v3 = &tempStr[strlen(tempStr) + 1] - &tempStr[1];
    v5 = fullFilename[v3 + 259] == 10;
    v6 = &fullFilename[v3 + 259];
    if ( v5 )
      *v6 = v4;
    v7 = (CDependencyInfo::CDependencyFile *)operator new(size: 0x104u);
    pFile = v7;
    v8 = 0;
    strstr(str1: (unsigned __int8 *)tempStr, str2: "optional ");
    if ( v9 == tempStr )
    {
      v8 = 1;
      V_strncpy(pDest: v7->m_Name, pSrc: &tempStr[9], maxLen: 260);
    }
    else
    {
      V_strncpy(pDest: v7->m_Name, pSrc: tempStr, maxLen: 260);
    }
    V_ComposeFileName(path: pInfo->m_DependencyFilesDir, filename: v7->m_Name, dest: fullFilename, destSize: 260);
    if ( access(path: fullFilename, amode: 0) != 0 )
    {
      operator delete(p: v7);
      if ( v8 == 0 )
        _Error(a1: "Can't find %s (listed in %s).", fullFilename, pDepFilename);
    }
    else
    {
      m_Size = pInfo->m_Files.m_Size;
      m_nAllocationCount = pInfo->m_Files.m_Memory.m_nAllocationCount;
      if ( m_Size + 1 > m_nAllocationCount )
        CUtlMemory<int,int>::Grow(
          this: (CUtlMemory<CTCPPacket *,int> *)&pInfo->m_Files,
          num: m_Size - m_nAllocationCount + 1);
      ++pInfo->m_Files.m_Size;
      m_pMemory = pInfo->m_Files.m_Memory.m_pMemory;
      v13 = pInfo->m_Files.m_Size - m_Size - 1;
      pInfo->m_Files.m_pElements = m_pMemory;
      if ( v13 > 0 )
        _V_memmove(
          dest: (unsigned __int8 *)&m_pMemory[m_Size + 1],
          src: (unsigned __int8 *)&m_pMemory[m_Size],
          count: 4 * v13);
      v14 = &pInfo->m_Files.m_Memory.m_pMemory[m_Size];
      if ( v14 != nullptr )
        *v14 = pFile;
    }
  }
  fclose(stream: v2);
}

//------------------------------------------------------------------------------
// Address: 0x10024020
// Name: void SetupDependenciesForPatch(class CDependencyInfo __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SetupDependenciesForPatch(CDependencyInfo *pInfo, char *pPatchDirectory)
{
  char *v2; // ebx
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CDependencyInfo::CDependencyFile **m_pMemory; // ecx
  int v6; // eax
  CDependencyInfo::CDependencyFile **v7; // eax
  int v8; // esi
  char searchStr[260]; // [esp+0h] [ebp-230h] BYREF
  _finddata64i32_t data; // [esp+104h] [ebp-12Ch] BYREF
  int handle; // [esp+22Ch] [ebp-4h]

  V_ComposeFileName(path: pPatchDirectory, filename: "*.*", dest: searchStr, destSize: 260);
  handle = _findfirst64i32(szWild: searchStr, pfd: &data);
  if ( handle != -1 )
  {
    do
    {
      if ( data.name[0] != 46 && (data.attrib & 0x10) == 0 )
      {
        v2 = (char *)operator new(size: 0x104u);
        V_strncpy(pDest: v2, pSrc: data.name, maxLen: 260);
        m_Size = pInfo->m_Files.m_Size;
        m_nAllocationCount = pInfo->m_Files.m_Memory.m_nAllocationCount;
        if ( m_Size + 1 > m_nAllocationCount )
          CUtlMemory<int,int>::Grow(
            this: (CUtlMemory<CTCPPacket *,int> *)&pInfo->m_Files,
            num: m_Size - m_nAllocationCount + 1);
        ++pInfo->m_Files.m_Size;
        m_pMemory = pInfo->m_Files.m_Memory.m_pMemory;
        v6 = pInfo->m_Files.m_Size - m_Size - 1;
        pInfo->m_Files.m_pElements = m_pMemory;
        if ( v6 > 0 )
          _V_memmove(
            dest: (unsigned __int8 *)&m_pMemory[m_Size + 1],
            src: (unsigned __int8 *)&m_pMemory[m_Size],
            count: 4 * v6);
        v7 = &pInfo->m_Files.m_Memory.m_pMemory[m_Size];
        if ( v7 != nullptr )
          *v7 = (CDependencyInfo::CDependencyFile *)v2;
      }
      v8 = handle;
    }
    while ( _findnext64i32(hFile: handle, pfd: &data) == 0 );
    _findclose(hFile: v8);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10024150
// Name: void SetupDependencyInfo(class CDependencyInfo __near *,char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SetupDependencyInfo(CDependencyInfo *pInfo, char *pDependencyFilename, bool bPatchMode)
{
  HMODULE ModuleHandleA; // eax
  char *v4; // eax
  char Filename[512]; // [esp+4h] [ebp-304h] BYREF
  char depFilename[260]; // [esp+204h] [ebp-104h] BYREF

  if ( bPatchMode )
  {
    SetupDependencyFilename(pInfo, pPatchDirectory: pDependencyFilename);
    SetupDependenciesForPatch(pInfo, pPatchDirectory: pDependencyFilename);
  }
  else
  {
    ModuleHandleA = GetModuleHandleA(lpModuleName: nullptr);
    if ( GetModuleFileNameA(hModule: ModuleHandleA, lpFilename: Filename, nSize: 0x200u) == 0 )
      _Error(a1: "GetModuleFileName failed.");
    V_strncpy(pDest: pInfo->m_DependencyFilesDir, pSrc: Filename, maxLen: 260);
    V_StripLastDir(dirName: pInfo->m_DependencyFilesDir, maxlen: 0x104u);
    v4 = (char *)V_UnqualifiedFileName(in: Filename);
    V_strncpy(pDest: pInfo->m_OriginalExeFilename, pSrc: v4, maxLen: 260);
    V_ComposeFileName(
      path: pInfo->m_DependencyFilesDir,
      filename: pDependencyFilename,
      dest: depFilename,
      destSize: 260);
    ParseDependencyFile(pInfo, pDepFilename: depFilename);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10024220
// Name: public: CMasterBroadcaster::CMasterBroadcaster(void)
// Source: json
//------------------------------------------------------------------------------
CMasterBroadcaster *__thiscall CMasterBroadcaster::CMasterBroadcaster(CMasterBroadcaster *this)
{
  this->m_BroadcastInfo.m_Args.m_Memory.m_pMemory = nullptr;
  this->m_BroadcastInfo.m_Args.m_Memory.m_nAllocationCount = 0;
  this->m_BroadcastInfo.m_Args.m_Memory.m_nGrowSize = 0;
  this->m_BroadcastInfo.m_Args.m_Size = 0;
  this->m_BroadcastInfo.m_Args.m_pElements = nullptr;
  this->m_PatchWorkerIPs.m_Memory.m_pMemory = nullptr;
  this->m_PatchWorkerIPs.m_Memory.m_nAllocationCount = 0;
  this->m_PatchWorkerIPs.m_Memory.m_nGrowSize = 0;
  this->m_PatchWorkerIPs.m_Size = 0;
  this->m_PatchWorkerIPs.m_pElements = nullptr;
  this->m_ConnectionCreator.__vftable = (CVMPIConnectionCreator_vtbl *)&CVMPIConnectionCreator::`vftable';
  CExpressionEvaluator::CExpressionEvaluator(this: &this->m_hShutdownEvent);
  CExpressionEvaluator::CExpressionEvaluator(this: &this->m_hShutdownReply);
  this->m_pListenSocket = nullptr;
  this->m_pDownloaderListenSocket = nullptr;
  this->m_pSocket = nullptr;
  this->m_iListenPort = -1;
  this->m_iDownloaderListenPort = -1;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100242A0
// Name: private: void CMasterBroadcaster::GetPatchWorkerList(int,char __near * __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMasterBroadcaster::GetPatchWorkerList(CMasterBroadcaster *this, int argc, char **argv)
{
  CUtlMemory<CMasterMulticastThread::CChunkInfo,int> *p_m_PatchWorkerIPs; // esi
  int v5; // edi
  int v6; // eax
  const char **v7; // ebx
  CMasterMulticastThread::CChunkInfo *m_pMemory; // edi
  int m_nAllocationCount; // eax
  CMasterMulticastThread::CChunkInfo *v10; // ecx
  int v11; // eax
  CIPAddr *v12; // eax
  CIPAddr addr; // [esp+8h] [ebp-20h] BYREF
  int a; // [esp+10h] [ebp-18h] BYREF
  int b; // [esp+14h] [ebp-14h] BYREF
  int c; // [esp+18h] [ebp-10h] BYREF
  int d; // [esp+1Ch] [ebp-Ch] BYREF
  int workerCount; // [esp+20h] [ebp-8h]
  int i; // [esp+24h] [ebp-4h]
  int iWorker; // [esp+34h] [ebp+Ch]

  p_m_PatchWorkerIPs = (CUtlMemory<CMasterMulticastThread::CChunkInfo,int> *)&this->m_PatchWorkerIPs;
  this->m_PatchWorkerIPs.m_Size = 0;
  if ( this->m_PatchWorkerIPs.m_Memory.m_nGrowSize >= 0 )
  {
    if ( p_m_PatchWorkerIPs->m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: p_m_PatchWorkerIPs->m_pMemory);
      p_m_PatchWorkerIPs->m_pMemory = nullptr;
    }
    p_m_PatchWorkerIPs->m_nAllocationCount = 0;
  }
  p_m_PatchWorkerIPs[1].m_nAllocationCount = (int)p_m_PatchWorkerIPs->m_pMemory;
  i = 0;
  if ( argc - 1 > 0 )
  {
    while ( _V_stricmp(s1: argv[i], s2: "-mpi_PatchWorkers") != 0 )
    {
      if ( ++i >= argc - 1 )
        return;
    }
    v5 = i;
    v6 = atoi(nptr: argv[i + 1]);
    workerCount = v6;
    iWorker = 0;
    if ( v6 > 0 )
    {
      v7 = (const char **)&argv[i + 2];
      while ( 1 )
      {
        if ( v5 + iWorker + 2 >= argc )
          _Error(a1: "-mpi_PatchWorkers: %d specified for count, but not enough IPs following.\n", v6);
        sscanf(string: *v7, format: "%d.%d.%d.%d", &a, &b, &c, &d);
        CIPAddr::CIPAddr(this: &addr);
        CIPAddr::Init(this: &addr, ip0: a, ip1: b, ip2: c, ip3: d, ipPort: 0);
        m_pMemory = p_m_PatchWorkerIPs[1].m_pMemory;
        m_nAllocationCount = p_m_PatchWorkerIPs->m_nAllocationCount;
        if ( (int)&m_pMemory->m_iChunk + 1 > m_nAllocationCount )
          CUtlMemory<CIPAddr,int>::Grow(
            this: p_m_PatchWorkerIPs,
            num: (int)&m_pMemory->m_iChunk - m_nAllocationCount + 1);
        ++p_m_PatchWorkerIPs[1].m_pMemory;
        v10 = p_m_PatchWorkerIPs->m_pMemory;
        v11 = (char *)p_m_PatchWorkerIPs[1].m_pMemory - (char *)m_pMemory - 1;
        p_m_PatchWorkerIPs[1].m_nAllocationCount = (int)p_m_PatchWorkerIPs->m_pMemory;
        if ( v11 > 0 )
          _V_memmove(
            dest: (unsigned __int8 *)&v10[(int)m_pMemory + 1],
            src: (unsigned __int8 *)&v10[(_DWORD)m_pMemory],
            count: 6 * v11);
        v12 = (CIPAddr *)&p_m_PatchWorkerIPs->m_pMemory[(_DWORD)m_pMemory];
        if ( v12 != nullptr )
          *v12 = addr;
        ++v7;
        if ( ++iWorker >= workerCount )
          break;
        v6 = workerCount;
        v5 = i;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10024430
// Name: void VMPI_Finalize(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall VMPI_Finalize(int a1@<ebp>)
{
  int i; // esi
  CVMPIConnection *v2; // eax
  IThreadedTCPSocket *m_pSocket; // ecx
  int m_Head; // esi
  UtlLinkedListElem_t<CTCPPacket *,int> *m_pMemory; // eax
  int v6; // esi
  UtlLinkedListElem_t<CTCPPacket *,int> *v7; // eax
  TSLNodeBase_t *v8; // eax
  TSLNodeBase_t *Next; // esi
  int j; // esi
  char **v11; // eax

  CMasterBroadcaster::Term(this: &g_MasterBroadcaster);
  DistributeWork_Cancel();
  for ( i = 0; i < g_nConnections; ++i )
  {
    v2 = g_Connections[i];
    if ( v2 != nullptr )
    {
      m_pSocket = v2->m_pSocket;
      if ( m_pSocket != nullptr )
      {
        v2->m_pSocket = nullptr;
        m_pSocket->Release(this: m_pSocket);
      }
      else
      {
        ((void (__thiscall *)(CVMPIConnection *, int))v2->dtr_CVMPIConnection)(a1: g_Connections[i], a2: 1);
      }
    }
  }
  m_Head = g_VMPIMessages.m_Head;
  g_nConnections = 0;
  if ( g_VMPIMessages.m_Head != -1 )
  {
    m_pMemory = g_VMPIMessages.m_Memory.m_pMemory;
    do
    {
      v6 = m_Head;
      CTCPPacket::Release(this: m_pMemory[v6].m_Element);
      m_pMemory = g_VMPIMessages.m_Memory.m_pMemory;
      m_Head = g_VMPIMessages.m_Memory.m_pMemory[v6].m_Next;
    }
    while ( m_Head != -1 );
  }
  CUtlLinkedList<CPartitionInfo *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CPartitionInfo *,int>,int>>::RemoveAll(this: (CUtlLinkedList<CFileChunkPacket *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CFileChunkPacket *,int>,int> > *)&g_VMPIMessages);
  v7 = g_VMPIMessages.m_Memory.m_pMemory;
  if ( g_VMPIMessages.m_Memory.m_nGrowSize >= 0 )
  {
    if ( g_VMPIMessages.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: g_VMPIMessages.m_Memory.m_pMemory);
      v7 = nullptr;
      g_VMPIMessages.m_Memory.m_pMemory = nullptr;
    }
    g_VMPIMessages.m_Memory.m_nAllocationCount = 0;
  }
  g_VMPIMessages.m_FirstFree = -1;
  g_VMPIMessages.m_NumAlloced = 0;
  g_VMPIMessages.m_LastAlloc.index = -1;
  g_VMPIMessages.m_pElements = v7;
  CUtlLinkedList<CUtlVector<char,CUtlMemory<char,int>> *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlVector<char,CUtlMemory<char,int>> *,unsigned short>,unsigned short>>::PurgeAndDeleteElements(this: &g_PersistentPackets);
  v8 = CTSListBase::Detach(this: &g_DispatchBuffers);
  if ( v8 != nullptr )
  {
    do
    {
      Next = v8->Next;
      operator delete(p: v8);
      v8 = Next;
    }
    while ( Next != nullptr );
  }
  if ( g_hKernel32DLL != nullptr )
  {
    FreeLibrary(hLibModule: g_hKernel32DLL);
    g_hKernel32DLL = nullptr;
  }
  for ( j = 0; j < g_WorkerCommandLine.m_Size; ++j )
    operator delete(p: g_WorkerCommandLine.m_Memory.m_pMemory[j]);
  v11 = g_WorkerCommandLine.m_Memory.m_pMemory;
  g_WorkerCommandLine.m_Size = 0;
  if ( g_WorkerCommandLine.m_Memory.m_nGrowSize >= 0 )
  {
    if ( g_WorkerCommandLine.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: g_WorkerCommandLine.m_Memory.m_pMemory);
      v11 = nullptr;
      g_WorkerCommandLine.m_Memory.m_pMemory = nullptr;
    }
    g_WorkerCommandLine.m_Memory.m_nAllocationCount = 0;
  }
  g_WorkerCommandLine.m_pElements = v11;
  VMPI_HandleAutoRestart(a1);
}

//------------------------------------------------------------------------------
// Address: 0x100245B0
// Name: void VMPI_GroupPackets(class CVMPIConnection __near *,void const __near * const __near *,int const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl VMPI_GroupPackets(CVMPIConnection *pConn, const void *const *pChunks, char *pChunkLengths, int nChunks)
{
  int m_Size; // edi
  int m_nAllocationCount; // eax
  void **m_pMemory; // ecx
  int v7; // eax
  void **v8; // eax
  int v9; // edi
  int v10; // eax
  int *v11; // ecx
  int v12; // eax
  int *v13; // eax
  int v14; // ebx
  unsigned int *v15; // esi
  int v16; // ecx
  int v17; // edx
  int v18; // edi
  int v19; // eax
  int v20; // edi
  char *v21; // eax
  int v22; // edi
  int v23; // eax
  int v24; // edi
  int v25; // eax
  void **v26; // ecx
  int v27; // eax
  void **v28; // edi
  int v29; // edi
  int v30; // eax
  int *v31; // ecx
  int v32; // eax
  int *v33; // edi
  CCriticalSectionLock connectionsLock; // [esp+Ch] [ebp-10h] BYREF
  int v35; // [esp+14h] [ebp-8h]
  int i; // [esp+18h] [ebp-4h]
  char *pOut; // [esp+30h] [ebp+14h]

  CCriticalSectionLock::CCriticalSectionLock(this: &connectionsLock, pCS: &g_ConnectionsCS);
  CCriticalSectionLock::Lock(this: &connectionsLock);
  if ( pConn->m_GroupedChunks.m_Size == 0 )
  {
    m_Size = pConn->m_GroupedChunks.m_Size;
    m_nAllocationCount = pConn->m_GroupedChunks.m_Memory.m_nAllocationCount;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<int,int>::Grow(
        this: (CUtlMemory<CTCPPacket *,int> *)&pConn->m_GroupedChunks,
        num: m_Size - m_nAllocationCount + 1);
    ++pConn->m_GroupedChunks.m_Size;
    m_pMemory = pConn->m_GroupedChunks.m_Memory.m_pMemory;
    v7 = pConn->m_GroupedChunks.m_Size - m_Size - 1;
    pConn->m_GroupedChunks.m_pElements = m_pMemory;
    if ( v7 > 0 )
      _V_memmove(
        dest: (unsigned __int8 *)&m_pMemory[m_Size + 1],
        src: (unsigned __int8 *)&m_pMemory[m_Size],
        count: 4 * v7);
    v8 = &pConn->m_GroupedChunks.m_Memory.m_pMemory[m_Size];
    if ( v8 != nullptr )
      *v8 = g_GroupedPacketHeader;
    v9 = pConn->m_GroupedChunkLengths.m_Size;
    v10 = pConn->m_GroupedChunkLengths.m_Memory.m_nAllocationCount;
    if ( v9 + 1 > v10 )
      CUtlMemory<int,int>::Grow(this: (CUtlMemory<CTCPPacket *,int> *)&pConn->m_GroupedChunkLengths, num: v9 - v10 + 1);
    ++pConn->m_GroupedChunkLengths.m_Size;
    v11 = pConn->m_GroupedChunkLengths.m_Memory.m_pMemory;
    v12 = pConn->m_GroupedChunkLengths.m_Size - v9 - 1;
    pConn->m_GroupedChunkLengths.m_pElements = v11;
    if ( v12 > 0 )
      _V_memmove(dest: (unsigned __int8 *)&v11[v9 + 1], src: (unsigned __int8 *)&v11[v9], count: 4 * v12);
    v13 = &pConn->m_GroupedChunkLengths.m_Memory.m_pMemory[v9];
    if ( v13 != nullptr )
      *v13 = 2;
  }
  v14 = nChunks;
  v15 = (unsigned int *)pChunkLengths;
  v16 = 0;
  v17 = 0;
  v18 = 0;
  v19 = 0;
  if ( nChunks >= 2 )
  {
    do
    {
      v16 += *(_DWORD *)&pChunkLengths[4 * v19];
      v17 += *(_DWORD *)&pChunkLengths[4 * v19 + 4];
      v19 += 2;
    }
    while ( v19 < nChunks - 1 );
    v14 = nChunks;
  }
  if ( v19 < v14 )
    v18 = *(_DWORD *)&pChunkLengths[4 * v19];
  v20 = v17 + v16 + v18;
  v35 = v20 + 4;
  v21 = (char *)operator new(size: v20 + 4);
  *(_DWORD *)v21 = v20;
  pOut = v21;
  v22 = 4;
  if ( v14 > 0 )
  {
    v23 = (char *)pChunks - pChunkLengths;
    for ( i = (char *)pChunks - pChunkLengths; ; v23 = i )
    {
      memcpy(dst: (unsigned __int8 *)&pOut[v22], src: *(unsigned __int8 **)((char *)v15 + v23), count: *v15);
      v22 += *v15++;
      if ( --v14 == 0 )
        break;
    }
  }
  v24 = pConn->m_GroupedChunks.m_Size;
  v25 = pConn->m_GroupedChunks.m_Memory.m_nAllocationCount;
  if ( v24 + 1 > v25 )
    CUtlMemory<int,int>::Grow(this: (CUtlMemory<CTCPPacket *,int> *)&pConn->m_GroupedChunks, num: v24 - v25 + 1);
  ++pConn->m_GroupedChunks.m_Size;
  v26 = pConn->m_GroupedChunks.m_Memory.m_pMemory;
  v27 = pConn->m_GroupedChunks.m_Size - v24 - 1;
  pConn->m_GroupedChunks.m_pElements = v26;
  if ( v27 > 0 )
    _V_memmove(dest: (unsigned __int8 *)&v26[v24 + 1], src: (unsigned __int8 *)&v26[v24], count: 4 * v27);
  v28 = &pConn->m_GroupedChunks.m_Memory.m_pMemory[v24];
  if ( v28 != nullptr )
    *v28 = pOut;
  v29 = pConn->m_GroupedChunkLengths.m_Size;
  v30 = pConn->m_GroupedChunkLengths.m_Memory.m_nAllocationCount;
  if ( v29 + 1 > v30 )
    CUtlMemory<int,int>::Grow(this: (CUtlMemory<CTCPPacket *,int> *)&pConn->m_GroupedChunkLengths, num: v29 - v30 + 1);
  ++pConn->m_GroupedChunkLengths.m_Size;
  v31 = pConn->m_GroupedChunkLengths.m_Memory.m_pMemory;
  v32 = pConn->m_GroupedChunkLengths.m_Size - v29 - 1;
  pConn->m_GroupedChunkLengths.m_pElements = v31;
  if ( v32 > 0 )
    _V_memmove(dest: (unsigned __int8 *)&v31[v29 + 1], src: (unsigned __int8 *)&v31[v29], count: 4 * v32);
  v33 = &pConn->m_GroupedChunkLengths.m_Memory.m_pMemory[v29];
  if ( v33 != nullptr )
    *v33 = v35;
  CCriticalSectionLock::~CCriticalSectionLock(this: &connectionsLock);
}

//------------------------------------------------------------------------------
// Address: 0x100247C0
// Name: void VMPI_SetupAutoRestartParameters(int,char __near * __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl VMPI_SetupAutoRestartParameters(int argc, char **argv)
{
  int v2; // edi
  char *v3; // ebx
  int v4; // esi
  char *v5; // [esp+4h] [ebp-4h]

  if ( VMPI_FindArg(argc, argv, pName: g_VMPIParams[6].m_pName, pDefault: defaultValue) != nullptr )
  {
    v2 = 0;
    g_OriginalCommandLineParameters.m_Size = 0;
    CUtlVector<dfacebrushlist_t,CUtlMemory<dfacebrushlist_t,int>>::InsertMultipleBefore(
      this: (CUtlVector<CVMPIConnection *,CUtlMemory<CVMPIConnection *,int> > *)&g_OriginalCommandLineParameters,
      elem: 0,
      num: argc);
    if ( argc > 0 )
    {
      do
      {
        v3 = argv[v2];
        v4 = _V_strlen(str: v3) + 1;
        v5 = (char *)operator new(size: v4);
        V_strncpy(pDest: v5, pSrc: v3, maxLen: v4);
        g_OriginalCommandLineParameters.m_Memory.m_pMemory[v2++] = v5;
      }
      while ( v2 < argc );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10024940
// Name: void InternalHandleSocketErrors(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InternalHandleSocketErrors()
{
  int v0; // esi
  int m_Head; // eax
  CVMPIConnection **m_pMemory; // ebx
  UtlLinkedListElem_t<CVMPIConnection *,int> *v3; // edx
  CVMPIConnection **v4; // ecx
  int v5; // eax
  UtlLinkedListElem_t<CVMPIConnection *,int> *v6; // eax
  int m_Size; // edi
  CUtlVector<CVMPIConnection *,CUtlMemory<CVMPIConnection *,int> > errorSockets; // [esp+Ch] [ebp-1Ch] BYREF
  CCriticalSectionLock csLock; // [esp+20h] [ebp-8h] BYREF

  v0 = 0;
  memset(&errorSockets, 0, sizeof(errorSockets));
  CCriticalSectionLock::CCriticalSectionLock(this: &csLock, pCS: &g_ErrorSocketsCS);
  CCriticalSectionLock::Lock(this: &csLock);
  CUtlVector<dfacebrushlist_t,CUtlMemory<dfacebrushlist_t,int>>::InsertMultipleBefore(
    this: &errorSockets,
    elem: 0,
    num: g_ErrorSockets.m_ElementCount);
  m_Head = g_ErrorSockets.m_Head;
  m_pMemory = errorSockets.m_Memory.m_pMemory;
  if ( g_ErrorSockets.m_Head != -1 )
  {
    v3 = g_ErrorSockets.m_Memory.m_pMemory;
    v4 = errorSockets.m_Memory.m_pMemory;
    do
    {
      v5 = m_Head;
      *v4 = v3[v5].m_Element;
      v3 = g_ErrorSockets.m_Memory.m_pMemory;
      m_Head = g_ErrorSockets.m_Memory.m_pMemory[v5].m_Next;
      ++v4;
    }
    while ( m_Head != -1 );
  }
  CUtlLinkedList<CPartitionInfo *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CPartitionInfo *,int>,int>>::RemoveAll(this: (CUtlLinkedList<CFileChunkPacket *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CFileChunkPacket *,int>,int> > *)&g_ErrorSockets);
  v6 = g_ErrorSockets.m_Memory.m_pMemory;
  if ( g_ErrorSockets.m_Memory.m_nGrowSize >= 0 )
  {
    if ( g_ErrorSockets.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: g_ErrorSockets.m_Memory.m_pMemory);
      v6 = nullptr;
      g_ErrorSockets.m_Memory.m_pMemory = nullptr;
    }
    g_ErrorSockets.m_Memory.m_nAllocationCount = 0;
  }
  g_ErrorSockets.m_FirstFree = -1;
  g_ErrorSockets.m_NumAlloced = 0;
  g_ErrorSockets.m_LastAlloc.index = -1;
  g_ErrorSockets.m_pElements = v6;
  CCriticalSectionLock::Unlock(this: &csLock);
  m_Size = errorSockets.m_Size;
  if ( errorSockets.m_Size > 0 )
  {
    do
    {
      CVMPIConnection::HandleDisconnect(this: m_pMemory[v0]);
      m_pMemory[v0]->Release(this: m_pMemory[v0], a2: true);
      ++v0;
    }
    while ( v0 < m_Size );
  }
  UpdateActiveConnectionsText();
  CCriticalSectionLock::~CCriticalSectionLock(this: &csLock);
  if ( errorSockets.m_Memory.m_nGrowSize >= 0 && m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x10024A60
// Name: bool VMPI_GetNextMessage(class MessageBuffer __near *,int __near *,unsigned long)
// Source: json
//------------------------------------------------------------------------------
char __cdecl VMPI_GetNextMessage(MessageBuffer *pBuf, int *pSource, CTCPPacket *startTimeout)
{
  DWORD v3; // eax
  CTCPPacket *v4; // eax
  int m_Head; // edi
  int v7; // esi
  CTCPPacket *m_Element; // ebx
  int i; // eax
  signed int m_Size; // esi
  int j; // edi
  unsigned int v12; // ebx
  unsigned __int8 *v13; // eax
  int v14; // edx
  CTCPPacket *v15; // edi
  unsigned int v16; // ecx
  CTCPPacket **m_pMemory; // edx
  CTCPPacket **v18; // eax
  CTCPPacket **v19; // edi
  int v20; // edi
  int v21; // ebx
  CTCPPacket *v22; // esi
  int m_Len; // eax
  int v24; // ecx
  int v25; // eax
  char szPacketID[64]; // [esp+Ch] [ebp-ACh] BYREF
  char szSubPacketID[64]; // [esp+4Ch] [ebp-6Ch] BYREF
  void *handles[2]; // [esp+8Ch] [ebp-2Ch] BYREF
  CCriticalSectionLock csLock; // [esp+94h] [ebp-24h] BYREF
  CUtlVector<CTCPPacket *,CUtlMemory<CTCPPacket *,int> > groupedPackets; // [esp+9Ch] [ebp-1Ch] BYREF
  int iCurOffset; // [esp+B0h] [ebp-8h]
  unsigned int startTime; // [esp+B4h] [ebp-4h]
  CTCPPacket *pPacket; // [esp+C8h] [ebp+10h]

  handles[0] = CTCPPacket::GetUserData(this: &g_ErrorSocketsEvent);
  handles[1] = CTCPPacket::GetUserData(this: &g_VMPIMessagesEvent);
  startTime = _Plat_MSTime();
  v3 = WaitForMultipleObjects(nCount: 2u, lpHandles: handles, bWaitAll: false, dwMilliseconds: (DWORD)startTimeout);
  if ( v3 == 258 )
    return 0;
  while ( v3 == 0 )
  {
    InternalHandleSocketErrors();
    v4 = (CTCPPacket *)(_Plat_MSTime() - startTime);
    if ( v4 >= startTimeout )
      return 0;
    v3 = WaitForMultipleObjects(
           nCount: 2u,
           lpHandles: handles,
           bWaitAll: false,
           dwMilliseconds: (char *)startTimeout - (char *)v4);
    if ( v3 == 258 )
      return 0;
  }
  if ( v3 != 1 )
  {
    _Error(a1: "VMPI_GetNextMessage: WaitForSingleObject returned %lu", v3);
    return 0;
  }
  CCriticalSectionLock::CCriticalSectionLock(this: &csLock, pCS: &g_VMPIMessagesCS);
  CCriticalSectionLock::Lock(this: &csLock);
  m_Head = g_VMPIMessages.m_Head;
  v7 = g_VMPIMessages.m_Head;
  m_Element = g_VMPIMessages.m_Memory.m_pMemory[g_VMPIMessages.m_Head].m_Element;
  pPacket = m_Element;
  CUtlLinkedList<CThreadedTCPSocket::SendData_t *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CThreadedTCPSocket::SendData_t *,int>,int>>::Unlink(
    this: (CUtlLinkedList<CFileChunkPacket *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CFileChunkPacket *,int>,int> > *)&g_VMPIMessages,
    elem: g_VMPIMessages.m_Head);
  g_VMPIMessages.m_Memory.m_pMemory[v7].m_Next = g_VMPIMessages.m_FirstFree;
  g_VMPIMessages.m_FirstFree = m_Head;
  for ( i = m_Element->m_Len; i >= 6; m_Element = v22 )
  {
    if ( m_Element->m_Data[0] != 27 || m_Element->m_Data[1] != 4 )
      break;
    m_Size = 0;
    memset(&groupedPackets, 0, sizeof(groupedPackets));
    for ( j = 2; ; j = iCurOffset )
    {
      v12 = *(_DWORD *)&m_Element->m_Data[j];
      if ( (int)(v12 + j) > i )
        _Error(a1: "Invalid chunked packet\n");
      iCurOffset = j + 4;
      v13 = (unsigned __int8 *)malloc(size: v12 + 11);
      v14 = iCurOffset;
      v15 = (CTCPPacket *)v13;
      *((_DWORD *)v13 + 1) = v12;
      *(_DWORD *)v13 = pPacket->m_UserData;
      memcpy(dst: v13 + 8, src: (unsigned __int8 *)&pPacket->m_Data[v14], count: v12);
      v16 = m_Size;
      startTime = m_Size;
      if ( m_Size + 1 > groupedPackets.m_Memory.m_nAllocationCount )
      {
        CUtlMemory<int,int>::Grow(
          this: &groupedPackets.m_Memory,
          num: m_Size - groupedPackets.m_Memory.m_nAllocationCount + 1);
        m_Size = groupedPackets.m_Size;
        v16 = startTime;
      }
      m_pMemory = groupedPackets.m_Memory.m_pMemory;
      groupedPackets.m_Size = ++m_Size;
      groupedPackets.m_pElements = groupedPackets.m_Memory.m_pMemory;
      if ( (int)(m_Size - v16 - 1) > 0 )
      {
        _V_memmove(
          dest: (unsigned __int8 *)&groupedPackets.m_Memory.m_pMemory[v16 + 1],
          src: (unsigned __int8 *)&groupedPackets.m_Memory.m_pMemory[v16],
          count: 4 * (m_Size - v16 - 1));
        m_pMemory = groupedPackets.m_Memory.m_pMemory;
        v16 = startTime;
      }
      v18 = &m_pMemory[v16];
      if ( v18 != nullptr )
        *v18 = v15;
      i = pPacket->m_Len;
      iCurOffset += v12;
      if ( iCurOffset + 4 > i )
        break;
      m_Element = pPacket;
    }
    if ( m_Size > 0 )
    {
      v19 = &groupedPackets.m_Memory.m_pMemory[m_Size - 1];
      do
      {
        CUtlLinkedList<CTCPPacket *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CTCPPacket *,int>,int>>::AddToHead(
          this: &g_VMPIMessages,
          src: v19--);
        --m_Size;
      }
      while ( m_Size != 0 );
    }
    CTCPPacket::Release(this: pPacket);
    CUtlVector<dleafambientlighting_t,CUtlMemory<dleafambientlighting_t,int>>::~CUtlVector<dleafambientlighting_t,CUtlMemory<dleafambientlighting_t,int>>(this: (CUtlVector<CFileResponse,CUtlMemory<CFileResponse,int> > *)&groupedPackets);
    v20 = g_VMPIMessages.m_Head;
    v21 = g_VMPIMessages.m_Head;
    v22 = g_VMPIMessages.m_Memory.m_pMemory[g_VMPIMessages.m_Head].m_Element;
    pPacket = v22;
    CUtlLinkedList<CThreadedTCPSocket::SendData_t *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CThreadedTCPSocket::SendData_t *,int>,int>>::Unlink(
      this: (CUtlLinkedList<CFileChunkPacket *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CFileChunkPacket *,int>,int> > *)&g_VMPIMessages,
      elem: g_VMPIMessages.m_Head);
    g_VMPIMessages.m_Memory.m_pMemory[v21].m_Next = g_VMPIMessages.m_FirstFree;
    g_VMPIMessages.m_FirstFree = v20;
    i = v22->m_Len;
  }
  if ( g_VMPIMessages.m_ElementCount > 0 )
    CEvent::SetEvent(this: &g_VMPIMessagesEvent);
  CCriticalSectionLock::Unlock(this: &csLock);
  MessageBuffer::setLen(this: pBuf, nlen: m_Element->m_Len);
  memcpy(dst: (unsigned __int8 *)pBuf->data, src: (unsigned __int8 *)m_Element->m_Data, count: m_Element->m_Len);
  if ( g_bSuperSpewEnabled )
  {
    m_Len = m_Element->m_Len;
    if ( m_Len < 2 )
      v24 = -1;
    else
      v24 = pBuf->data[1];
    if ( m_Len < 1 )
      v25 = -1;
    else
      v25 = *pBuf->data;
    CVMPIPacketIDReg::Lookup(
      nPacketID: v25,
      nSubPacketID: v24,
      pPacketIDString: szPacketID,
      nPacketIDStringSize: 64,
      pSubPacketIDString: szSubPacketID,
      nSubPacketIDStringSize: 64);
    VMPI_SuperSpew(pMsg: "Received a packet (packetID %s, subPacketID %s)\n", szPacketID, szSubPacketID);
  }
  *pSource = (int)CTCPPacket::GetUserData(this: (CEvent *)m_Element);
  ++g_nMessagesReceived;
  g_nBytesReceived += m_Element->m_Len + 4;
  CTCPPacket::Release(this: m_Element);
  CCriticalSectionLock::~CCriticalSectionLock(this: &csLock);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10024DB0
// Name: bool VMPI_DispatchNextMessage(unsigned long)
// Source: json
//------------------------------------------------------------------------------
char __cdecl VMPI_DispatchNextMessage(CTCPPacket *timeout)
{
  TSLNodeBase_t *v1; // eax
  MessageBuffer *v2; // esi
  MessageBuffer *v3; // eax
  char v4; // bl
  char v5; // al
  TSLNodeBase_t *v6; // eax
  int iSource; // [esp+Ch] [ebp-4h] BYREF

  v1 = CTSListBase::Pop(this: &g_DispatchBuffers);
  if ( v1 != nullptr )
  {
    v2 = *((MessageBuffer **)&v1->Next + 1);
    operator delete(p: v1);
  }
  else
  {
    v3 = (MessageBuffer *)operator new(size: 0x10u);
    if ( v3 != nullptr )
      v2 = MessageBuffer::MessageBuffer(this: v3);
    else
      v2 = nullptr;
  }
  v4 = 1;
  if ( VMPI_GetNextMessage(pBuf: v2, pSource: &iSource, startTimeout: timeout) != 0 )
  {
    while ( 1 )
    {
      if ( ConCommandBase::GetName(this: (CVMPIFile_Memory *)v2) >= 1 )
      {
        v5 = *v2->data;
        if ( (unsigned __int8)v5 < 0x20u
          && g_VMPIDispatch[v5] != nullptr
          && g_VMPIDispatch[v5](a1: v2, a2: iSource, a3: v5) )
        {
          break;
        }
      }
      if ( VMPI_GetNextMessage(pBuf: v2, pSource: &iSource, startTimeout: timeout) == 0 )
        goto LABEL_12;
    }
  }
  else
  {
LABEL_12:
    v4 = 0;
  }
  v6 = (TSLNodeBase_t *)operator new(size: 8u);
  if ( v6 != nullptr )
  {
    *((_DWORD *)&v6->Next + 1) = v2;
    CTSListBase::Push(this: &g_DispatchBuffers, pNode: v6);
  }
  else
  {
    CTSListBase::Push(this: &g_DispatchBuffers, pNode: nullptr);
  }
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x10024EA0
// Name: bool VMPI_SendChunks(void const __near * const __near *,int const __near *,int,int,int)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl VMPI_SendChunks(
        const void *const *pChunks,
        int *pChunkLengths,
        int nChunks,
        int iDest,
        char fVMPISendFlags)
{
  int i; // esi
  CUtlVector<char,CUtlMemory<char,int> > *v7; // ebx
  int j; // esi
  CUtlVector<char,CUtlMemory<char,int> > *v9; // eax
  int *v10; // esi
  unsigned __int16 v11; // ax
  int v12; // esi
  UtlLinkedListElem_t<CUtlVector<char,CUtlMemory<char,int> > *,unsigned short> *v13; // eax
  int v14; // ecx
  int v15; // eax
  CVMPIConnection *v16; // ebx
  IThreadedTCPSocket *m_pSocket; // ecx
  CCriticalSectionLock v18; // [esp+Ch] [ebp-10h] BYREF
  CCriticalSectionLock csLock; // [esp+14h] [ebp-8h] BYREF
  int iDesta; // [esp+30h] [ebp+14h]

  if ( iDest == -2 )
  {
    CCriticalSectionLock::CCriticalSectionLock(this: &csLock, pCS: &g_ConnectionsCS);
    CCriticalSectionLock::Lock(this: &csLock);
    for ( i = 0; i < g_nConnections; ++i )
      VMPI_SendChunks(pChunks, pChunkLengths, nChunks, iDest: i, fVMPISendFlags: 0);
    CCriticalSectionLock::~CCriticalSectionLock(this: &csLock);
    return true;
  }
  if ( iDest == -3 )
  {
    CCriticalSectionLock::CCriticalSectionLock(this: &v18, pCS: &g_ConnectionsCS);
    CCriticalSectionLock::Lock(this: &v18);
    CCriticalSectionLock::CCriticalSectionLock(this: &csLock, pCS: &g_PersistentPacketsCS);
    CCriticalSectionLock::Lock(this: &csLock);
    v7 = nullptr;
    for ( j = 0; j < g_nConnections; ++j )
      VMPI_SendChunks(pChunks, pChunkLengths, nChunks, iDest: j, fVMPISendFlags: 0);
    v9 = (CUtlVector<char,CUtlMemory<char,int> > *)operator new(size: 0x14u);
    if ( v9 != nullptr )
    {
      v9->m_Memory.m_pMemory = nullptr;
      v9->m_Memory.m_nAllocationCount = 0;
      v9->m_Memory.m_nGrowSize = 0;
      v9->m_Size = 0;
      v9->m_pElements = nullptr;
      v7 = v9;
    }
    if ( nChunks > 0 )
    {
      v10 = pChunkLengths;
      for ( iDesta = nChunks; iDesta != 0; --iDesta )
      {
        CUtlVector<char,CUtlMemory<char,int>>::InsertMultipleBefore(
          this: v7,
          elem: v7->m_Size,
          num: *v10,
          pToInsert: *(const char **)((char *)v10 + (char *)pChunks - (char *)pChunkLengths));
        ++v10;
      }
    }
    v11 = CUtlLinkedList<CUtlVector<char,CUtlMemory<char,int>> *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlVector<char,CUtlMemory<char,int>> *,unsigned short>,unsigned short>>::AllocInternal(
            this: &g_PersistentPackets,
            multilist: false);
    v12 = v11;
    if ( v11 != 0xFFFF )
    {
      CUtlLinkedList<void (__cdecl *)(void),unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<void (__cdecl *)(void),unsigned short>,unsigned short>>::LinkBefore(
        this: &g_PersistentPackets,
        before: 0xFFFFu,
        elem: v11);
      v13 = &g_PersistentPackets.m_Memory.m_pMemory[v12];
      if ( v13 != nullptr )
        v13->m_Element = v7;
    }
    CCriticalSectionLock::~CCriticalSectionLock(this: &csLock);
    CCriticalSectionLock::~CCriticalSectionLock(this: &v18);
    return true;
  }
  else
  {
    ++g_nMessagesSent;
    v14 = g_nBytesSent + 4;
    v15 = 0;
    g_nBytesSent += 4;
    if ( nChunks > 0 )
    {
      do
      {
        v14 += pChunkLengths[v15++];
        g_nBytesSent = v14;
      }
      while ( v15 < nChunks );
    }
    v16 = g_Connections[iDest];
    if ( v16 == nullptr )
      return false;
    if ( VMPI_FilterPacketsForServiceDownloader(pConnection: v16, pChunks, pChunkLengths, nChunks) != 0 )
      return true;
    m_pSocket = v16->m_pSocket;
    if ( m_pSocket != nullptr )
    {
      if ( g_bGroupPackets && (fVMPISendFlags & 1) != 0 )
      {
        VMPI_GroupPackets(pConn: v16, pChunks, (char *)pChunkLengths, nChunks);
        return true;
      }
      else
      {
        return m_pSocket->SendChunks(this: m_pSocket, a2: pChunks, a3: pChunkLengths, a4: nChunks);
      }
    }
    else
    {
      return false;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100250A0
// Name: bool VMPI_Send2Chunks(void const __near *,int,void const __near *,int,int,int)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl VMPI_Send2Chunks(
        const void *pChunk1,
        int chunk1Len,
        const void *pChunk2,
        int chunk2Len,
        int iDest,
        char fVMPISendFlags)
{
  const void *pChunks[2]; // [esp+0h] [ebp-10h] BYREF
  int len[2]; // [esp+8h] [ebp-8h] BYREF

  pChunks[1] = pChunk2;
  pChunks[0] = pChunk1;
  len[0] = chunk1Len;
  len[1] = chunk2Len;
  return VMPI_SendChunks(pChunks, pChunkLengths: len, nChunks: 2, iDest, fVMPISendFlags);
}

//------------------------------------------------------------------------------
// Address: 0x100250E0
// Name: bool VMPI_Send3Chunks(void const __near *,int,void const __near *,int,void const __near *,int,int,int)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl VMPI_Send3Chunks(
        const void *pChunk1,
        int chunk1Len,
        const void *pChunk2,
        int chunk2Len,
        const void *pChunk3,
        int chunk3Len,
        int iDest,
        char fVMPISendFlags)
{
  const void *pChunks[3]; // [esp+0h] [ebp-18h] BYREF
  int len[3]; // [esp+Ch] [ebp-Ch] BYREF

  pChunks[0] = pChunk1;
  pChunks[1] = pChunk2;
  len[0] = chunk1Len;
  pChunks[2] = pChunk3;
  len[1] = chunk2Len;
  len[2] = chunk3Len;
  return VMPI_SendChunks(pChunks, pChunkLengths: len, nChunks: 3, iDest, fVMPISendFlags);
}

//------------------------------------------------------------------------------
// Address: 0x10025130
// Name: void VMPI_AddDisconnectHandler(void (*)(int,char const __near *))
// Source: json
//------------------------------------------------------------------------------
void __cdecl VMPI_AddDisconnectHandler(void (__cdecl *handler)(int, const char *))
{
  CUtlLinkedList<void (__cdecl *)(int,char const *),int,0,int,CUtlMemory<UtlLinkedListElem_t<void (__cdecl *)(int,char const *),int>,int>>::AddToTail(
    this: &g_DisconnectHandlers,
    src: &handler);
}

//------------------------------------------------------------------------------
// Address: 0x10025150
// Name: void VMPI_SetMachineName(int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl VMPI_SetMachineName(int iProc, const char *pName)
{
  CVMPIConnection *v2; // esi

  if ( iProc >= 0 && iProc < g_nConnections )
  {
    v2 = g_Connections[iProc];
    if ( v2 != nullptr )
    {
      CUtlVector<char,CUtlMemory<char,int>>::CopyArray(this: &v2->m_MachineName, pArray: pName, size: strlen(pName) + 1);
      v2->m_bNameSet = true;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100251A0
// Name: public: CVMPIConnection::CVMPIConnection(int)
// Source: json
//------------------------------------------------------------------------------
CVMPIConnection *__thiscall CVMPIConnection::CVMPIConnection(CVMPIConnection *this, int iConnection)
{
  char str[512]; // [esp+Ch] [ebp-200h] BYREF

  this->__vftable = (CVMPIConnection_vtbl *)&CVMPIConnection::`vftable';
  this->m_GroupedChunkLengths.m_Memory.m_pMemory = nullptr;
  this->m_GroupedChunkLengths.m_Memory.m_nAllocationCount = 0;
  this->m_GroupedChunkLengths.m_Memory.m_nGrowSize = 0;
  this->m_GroupedChunkLengths.m_Size = 0;
  this->m_GroupedChunkLengths.m_pElements = nullptr;
  this->m_GroupedChunks.m_Memory.m_pMemory = nullptr;
  this->m_GroupedChunks.m_Memory.m_nAllocationCount = 0;
  this->m_GroupedChunks.m_Memory.m_nGrowSize = 0;
  this->m_GroupedChunks.m_Size = 0;
  this->m_GroupedChunks.m_pElements = nullptr;
  this->m_MachineName.m_Memory.m_pMemory = nullptr;
  this->m_MachineName.m_Memory.m_nAllocationCount = 0;
  this->m_MachineName.m_Memory.m_nGrowSize = 0;
  this->m_MachineName.m_Size = 0;
  this->m_MachineName.m_pElements = nullptr;
  this->m_ErrorString.m_Memory.m_pMemory = nullptr;
  this->m_ErrorString.m_Memory.m_nAllocationCount = 0;
  this->m_ErrorString.m_Memory.m_nGrowSize = 0;
  this->m_ErrorString.m_Size = 0;
  this->m_ErrorString.m_pElements = nullptr;
  this->m_iConnection = iConnection;
  this->m_pSocket = nullptr;
  this->m_bIsAService = false;
  V_snprintf(pDest: str, maxLen: 0x200u, pFormat: "%d", iConnection);
  CUtlVector<char,CUtlMemory<char,int>>::CopyArray(this: &this->m_MachineName, pArray: str, size: strlen(str) + 1);
  *(_WORD *)&this->m_bNameSet = 0;
  this->m_JobWorkerID = -1;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10025260
// Name: public: virtual void CVMPIConnection::Init(class IThreadedTCPSocket __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVMPIConnection::Init(CVMPIConnection *this, IThreadedTCPSocket *pSocket)
{
  this->m_pSocket = pSocket;
}

//------------------------------------------------------------------------------
// Address: 0x10025270
// Name: public: virtual int CVMPIConnection::GetConnectionID(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CVMPIConnection::GetConnectionID(CVMPIConnection *this)
{
  return this->m_iConnection;
}

//------------------------------------------------------------------------------
// Address: 0x10025280
// Name: public: virtual void CVMPIConnection::Release(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVMPIConnection::Release(CVMPIConnection *this, bool bForce)
{
  int m_iConnection; // esi
  CVMPIConnection *v3; // ecx

  if ( !this->m_bInErrorState || bForce )
  {
    m_iConnection = this->m_iConnection;
    this->m_pSocket = nullptr;
    v3 = g_Connections[m_iConnection];
    if ( v3 != nullptr )
      ((void (__thiscall *)(CVMPIConnection *, int))v3->dtr_CVMPIConnection)(a1: v3, a2: 1);
    g_Connections[m_iConnection] = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10025520
// Name: public: virtual void CVMPIConnection::OnPacketReceived(class CTCPPacket __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVMPIConnection::OnPacketReceived(CVMPIConnection *this, CTCPPacket *pPacket)
{
  CCriticalSectionLock csLock; // [esp+0h] [ebp-8h] BYREF

  CTCPPacket::SetUserData(this: pPacket, userData: this->m_iConnection);
  CCriticalSectionLock::CCriticalSectionLock(this: &csLock, pCS: &g_VMPIMessagesCS);
  CCriticalSectionLock::Lock(this: &csLock);
  CUtlLinkedList<CTCPPacket *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CTCPPacket *,int>,int>>::AddToTail(
    this: &g_VMPIMessages,
    src: &pPacket);
  if ( g_VMPIMessages.m_ElementCount == 1 )
    CEvent::SetEvent(this: &g_VMPIMessagesEvent);
  CCriticalSectionLock::~CCriticalSectionLock(this: &csLock);
}

//------------------------------------------------------------------------------
// Address: 0x10025580
// Name: public: virtual void CVMPIConnection::OnError(int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVMPIConnection::OnError(CVMPIConnection *this, int errorCode, const char *pErrorString)
{
  const char *v3; // edi
  CCriticalSectionLock csLock; // [esp+8h] [ebp-8h] BYREF

  v3 = pErrorString;
  if ( !g_bMPIMaster )
    _Msg(a1: "%s - CVMPIConnection::OnError( %s )\n", this->m_MachineName.m_Memory.m_pMemory, pErrorString);
  CCriticalSectionLock::CCriticalSectionLock(this: &csLock, pCS: &g_ErrorSocketsCS);
  CCriticalSectionLock::Lock(this: &csLock);
  if ( !this->m_bInErrorState )
  {
    this->m_bInErrorState = true;
    CUtlVector<char,CUtlMemory<char,int>>::CopyArray(this: &this->m_ErrorString, pArray: v3, size: strlen(v3) + 1);
    pErrorString = (const char *)this;
    CUtlLinkedList<CVMPIConnection *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CVMPIConnection *,int>,int>>::AddToTail(
      this: &g_ErrorSockets,
      src: (CVMPIConnection **)&pErrorString);
    CEvent::SetEvent(this: &g_ErrorSocketsEvent);
    InterlockedIncrement(lpAddend: &this->m_ErrorSignal);
  }
  CCriticalSectionLock::~CCriticalSectionLock(this: &csLock);
}

//------------------------------------------------------------------------------
// Address: 0x10025620
// Name: public: virtual class ITCPSocketHandler __near * CVMPIConnectionCreator::CreateNewHandler(void)
// Source: json
//------------------------------------------------------------------------------
CVMPIConnection *__thiscall CVMPIConnectionCreator::CreateNewHandler(CVMPIConnectionCreator *this)
{
  int v1; // edi
  CVMPIConnection *v2; // eax
  CVMPIConnection *result; // eax
  _DWORD *v4; // eax
  _DWORD *v5; // esi
  int v6; // edi
  int v7; // ecx
  char pDest[512]; // [esp+8h] [ebp-204h] BYREF
  int i; // [esp+208h] [ebp-4h]

  v1 = 0;
  if ( g_nConnections <= 0 )
  {
LABEL_4:
    v2 = (CVMPIConnection *)operator new(size: 0x6Cu);
    if ( v2 != nullptr )
      result = CVMPIConnection::CVMPIConnection(this: v2, iConnection: g_nConnections);
    else
      result = nullptr;
    v7 = g_nConnections;
    g_Connections[g_nConnections] = result;
    g_nConnections = v7 + 1;
  }
  else
  {
    while ( g_Connections[v1] != nullptr )
    {
      if ( ++v1 >= g_nConnections )
        goto LABEL_4;
    }
    i = v1;
    v4 = operator new(size: 0x6Cu);
    v5 = v4;
    if ( v4 != nullptr )
    {
      *v4 = &CVMPIConnection::`vftable';
      v4[3] = 0;
      v4[4] = 0;
      v4[5] = 0;
      v4[6] = 0;
      v4[7] = 0;
      v4[8] = 0;
      v4[9] = 0;
      v4[10] = 0;
      v4[11] = 0;
      v4[12] = 0;
      v4[13] = 0;
      v4[14] = 0;
      v4[15] = 0;
      v4[16] = 0;
      v4[17] = 0;
      v4[18] = 0;
      v4[19] = 0;
      v4[20] = 0;
      v4[21] = 0;
      v4[22] = 0;
      v4[24] = v1;
      v4[25] = 0;
      *((_BYTE *)v4 + 8) = 0;
      V_snprintf(pDest, maxLen: 0x200u, pFormat: "%d", v1);
      CUtlVector<char,CUtlMemory<char,int>>::CopyArray(
        this: (CUtlVector<char,CUtlMemory<char,int> > *)(v5 + 13),
        pArray: pDest,
        size: strlen(pDest) + 1);
      v6 = i;
      *((_WORD *)v5 + 52) = 0;
      v5[1] = -1;
      g_Connections[v6] = (CVMPIConnection *)v5;
      return (CVMPIConnection *)v5;
    }
    else
    {
      g_Connections[v1] = nullptr;
      return nullptr;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10025770
// Name: bool VMPI_InternalDispatchFn(class MessageBuffer __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
char __cdecl VMPI_InternalDispatchFn(CVMPIFile_Memory *pBuf, int iSource)
{
  char v2; // al
  bool v4; // al
  int v5; // esi
  char *v6; // edi
  int m_Size; // eax
  int v8; // esi
  char **m_pMemory; // ecx
  int v10; // eax
  char **v11; // eax
  char pOut[4096]; // [esp+4h] [ebp-1008h] BYREF
  int i; // [esp+1004h] [ebp-8h]
  int p; // [esp+1008h] [ebp-4h] BYREF

  if ( ConCommandBase::GetName(this: pBuf) < 2 )
    return 0;
  v2 = BYTE1(pBuf->Close);
  switch ( v2 )
  {
    case 1:
      if ( ConCommandBase::GetName(this: pBuf) >= 3 )
      {
        VMPI_SuperSpew(pMsg: "Received SUBPACKET_MACHINE_NAME (%s).\n", (const char *)&pBuf->Close + 2);
        VMPI_SetMachineName(iProc: iSource, pName: (const char *)&pBuf->Close + 2);
        return 1;
      }
      VMPI_SuperSpew(pMsg: "Received invalid SUBPACKET_MACHINE_NAME packet (not long enough!)\n");
      return 0;
    case 3:
      if ( g_bVMPISDKModeSet )
        v4 = g_bVMPISDKMode;
      else
        v4 = !VMPI_CheckForNonSDKExecutables();
      if ( !v4 )
        _Warning(a1: "Worker %d is running in SDK mode (and the master is not)!\n", iSource);
      return 1;
    case 2:
      MessageBuffer::setOffset(this: (MessageBuffer *)pBuf, noffset: 2);
      MessageBuffer::read(this: (MessageBuffer *)pBuf, &p, bytes: 4);
      for ( i = 0; i < p; ++i )
      {
        if ( MessageBuffer::ReadString(this: (MessageBuffer *)pBuf, pOut, bufferLength: 4096) == -1 )
          _Error(a1: "Error in ReadString() while reading command line.");
        v5 = _V_strlen(str: pOut) + 1;
        v6 = (char *)operator new(size: v5);
        V_strncpy(pDest: v6, pSrc: pOut, maxLen: v5);
        m_Size = g_WorkerCommandLine.m_Size;
        v8 = g_WorkerCommandLine.m_Size;
        if ( g_WorkerCommandLine.m_Size + 1 > g_WorkerCommandLine.m_Memory.m_nAllocationCount )
        {
          CUtlMemory<int,int>::Grow(
            this: (CUtlMemory<CTCPPacket *,int> *)&g_WorkerCommandLine,
            num: g_WorkerCommandLine.m_Size - g_WorkerCommandLine.m_Memory.m_nAllocationCount + 1);
          m_Size = g_WorkerCommandLine.m_Size;
        }
        m_pMemory = g_WorkerCommandLine.m_Memory.m_pMemory;
        g_WorkerCommandLine.m_Size = m_Size + 1;
        v10 = m_Size - v8;
        g_WorkerCommandLine.m_pElements = g_WorkerCommandLine.m_Memory.m_pMemory;
        if ( v10 > 0 )
        {
          _V_memmove(
            dest: (unsigned __int8 *)&g_WorkerCommandLine.m_Memory.m_pMemory[v8 + 1],
            src: (unsigned __int8 *)&g_WorkerCommandLine.m_Memory.m_pMemory[v8],
            count: 4 * v10);
          m_pMemory = g_WorkerCommandLine.m_Memory.m_pMemory;
        }
        v11 = &m_pMemory[v8];
        if ( v11 != nullptr )
          *v11 = v6;
      }
      g_bReceivedWorkerCommandLine = true;
      return 1;
    default:
      break;
  }
  if ( v2 != 6 )
  {
    if ( v2 == 5 )
    {
      g_bTimingWaitDone = true;
      return 1;
    }
    return 0;
  }
  MessageBuffer::setOffset(this: (MessageBuffer *)pBuf, noffset: 2);
  if ( MessageBuffer::ReadString(this: (MessageBuffer *)pBuf, pOut: g_MasterExeName, bufferLength: 260) == -1 )
    _Error(a1: "Error in ReadString() while reading VMPI_INTERNAL_SUBPACKET_VERIFY_EXE_NAME.");
  VMPI_SuperSpew(pMsg: "Received SUBPACKET_VERIFY_EXE_NAME (%s).\n", g_MasterExeName);
  g_bReceivedMasterExeName = true;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10025990
// Name: void VMPI_ReceiveExeName(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl VMPI_ReceiveExeName()
{
  TSLHead_t m_Head; // kr00_8
  MessageBuffer *v1; // eax
  MessageBuffer *v2; // edi
  char v3; // al
  TSLNodeBase_t **v4; // eax
  TSLNodeBase_t **v5; // esi
  HMODULE ModuleHandleA; // eax
  int v7; // [esp-18h] [ebp-22Ch]
  int v8; // [esp-18h] [ebp-22Ch]
  TSLHead_t v9; // [esp-14h] [ebp-228h]
  TSLHead_t v10; // [esp-14h] [ebp-228h]
  char baseExeFilename[260]; // [esp+0h] [ebp-214h] BYREF
  char fileBase[260]; // [esp+104h] [ebp-110h] BYREF
  double startTime; // [esp+208h] [ebp-Ch]
  int pSource; // [esp+210h] [ebp-4h] BYREF

  startTime = _Plat_FloatTime();
  while ( !g_bReceivedMasterExeName )
  {
    if ( _Plat_FloatTime() - startTime > 30.0 )
      _Error(a1: "VMPI_ReceiveExeName: timeout.");
    m_Head = g_DispatchBuffers.m_Head;
    if ( g_DispatchBuffers.m_Head.value.Next == nullptr )
      goto LABEL_7;
    while ( (unsigned __int8)_ThreadInterlockedAssignIf64(
                               a1: &g_DispatchBuffers,
                               a2: m_Head.value.Next->Next,
                               a3: m_Head.value32.DepthAndSequence - 1,
                               a4: m_Head.value.Next,
                               a5: m_Head.value32.DepthAndSequence) == 0 )
    {
      _mm_pause();
      m_Head = g_DispatchBuffers.m_Head;
      if ( g_DispatchBuffers.m_Head.value.Next == nullptr )
        goto LABEL_7;
    }
    if ( m_Head.value.Next != nullptr )
    {
      v2 = *((MessageBuffer **)&m_Head.value.Next->Next + 1);
      operator delete(p: m_Head.value.Next);
    }
    else
    {
LABEL_7:
      v1 = (MessageBuffer *)operator new(size: 0x10u);
      if ( v1 != nullptr )
        v2 = MessageBuffer::MessageBuffer(this: v1);
      else
        v2 = nullptr;
    }
    while ( VMPI_GetNextMessage(pBuf: v2, &pSource, startTimeout: (CTCPPacket *)0x2710) != 0 )
    {
      if ( ConCommandBase::GetName(this: (CVMPIFile_Memory *)v2) >= 1 )
      {
        v3 = *v2->data;
        if ( (unsigned __int8)v3 < 0x20u
          && g_VMPIDispatch[v3] != nullptr
          && g_VMPIDispatch[v3](a1: v2, a2: pSource, a3: v3) )
        {
          break;
        }
      }
    }
    v4 = (TSLNodeBase_t **)operator new(size: 8u);
    if ( v4 != nullptr )
    {
      v4[1] = (TSLNodeBase_t *)v2;
      v5 = v4;
    }
    else
    {
      v5 = nullptr;
    }
    v9 = g_DispatchBuffers.m_Head;
    v7 = g_DispatchBuffers.m_Head.value32.DepthAndSequence + 65537;
    *v5 = g_DispatchBuffers.m_Head.value.Next;
    if ( (unsigned __int8)_ThreadInterlockedAssignIf64(
                            a1: &g_DispatchBuffers,
                            a2: v5,
                            a3: v7,
                            a4: v9.value.Next,
                            a5: v9.value32.DepthAndSequence) == 0 )
    {
      do
      {
        _mm_pause();
        v10 = g_DispatchBuffers.m_Head;
        v8 = g_DispatchBuffers.m_Head.value32.DepthAndSequence + 65537;
        *v5 = g_DispatchBuffers.m_Head.value.Next;
      }
      while ( (unsigned __int8)_ThreadInterlockedAssignIf64(
                                 a1: &g_DispatchBuffers,
                                 a2: v5,
                                 a3: v8,
                                 a4: v10.value.Next,
                                 a5: v10.value32.DepthAndSequence) == 0 );
    }
  }
  ModuleHandleA = GetModuleHandleA(lpModuleName: nullptr);
  if ( GetModuleFileNameA(hModule: ModuleHandleA, lpFilename: baseExeFilename, nSize: 0x104u) == 0 )
    _Error(a1: "VMPI_CheckSDKMode -> GetModuleFileName failed.");
  V_FileBase(in: baseExeFilename, out: fileBase, maxlen: 260);
  if ( _V_stricmp(s1: fileBase, s2: "vmpi_transfer") != 0 && _V_stricmp(s1: fileBase, s2: g_MasterExeName) != 0 )
    _Error(
      a1: "VMPI_ReceiveExeName: mismatched exe names (master: %s, me: %s).\n"
      "This usually just means the master finished a job like vvis really fast and started a vrad immediately, and an old"
      " vvis worker connected to the new vrad job.",
      g_MasterExeName,
      fileBase);
}

//------------------------------------------------------------------------------
// Address: 0x10025BC0
// Name: bool VMPI_SendData(void __near *,int,int,int)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl VMPI_SendData(void *pData, int nBytes, int iDest, char fVMPISendFlags)
{
  return VMPI_SendChunks(
           pChunks: (const void *const *)&pData,
           pChunkLengths: &nBytes,
           nChunks: 1,
           iDest,
           fVMPISendFlags);
}

//------------------------------------------------------------------------------
// Address: 0x10025BE0
// Name: void VMPI_SendMachineNameTo(int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl VMPI_SendMachineNameTo(int iProc)
{
  char *v1; // esi
  unsigned __int8 packetData[768]; // [esp+4h] [ebp-308h] BYREF
  void *pChunks; // [esp+304h] [ebp-8h] BYREF
  unsigned int nSize; // [esp+308h] [ebp-4h] BYREF

  nSize = 16;
  v1 = Buffer;
  if ( !GetComputerNameA(lpBuffer: Buffer, &nSize) )
    v1 = "(error in GetComputerName)";
  VMPI_SuperSpew(pMsg: "Sent SUBPACKET_MACHINE_NAME (%s).\n", v1);
  *(_WORD *)packetData = 283;
  V_strncpy(pDest: (char *)&packetData[2], pSrc: v1, maxLen: 766);
  nSize = strlen(v1) + 3;
  pChunks = packetData;
  VMPI_SendChunks(
    (const void *const *)&pChunks,
    pChunkLengths: (int *)&nSize,
    nChunks: 1,
    iDest: iProc,
    fVMPISendFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10025C80
// Name: void VMPI_SendCommandLine(int,char __near * __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl VMPI_SendCommandLine(int argc, char **argv)
{
  int v2; // esi
  char **v3; // edi
  MessageBuffer mb; // [esp+4h] [ebp-1Ch] BYREF
  void *pChunks; // [esp+14h] [ebp-Ch] BYREF
  int pChunkLengths; // [esp+18h] [ebp-8h] BYREF
  char cPacketHeader[2]; // [esp+1Ch] [ebp-4h] BYREF

  MessageBuffer::MessageBuffer(this: &mb);
  *(_WORD *)cPacketHeader = 539;
  MessageBuffer::write(this: &mb, p: cPacketHeader, bytes: 2);
  MessageBuffer::write(this: &mb, p: &argc, bytes: 4);
  v2 = 0;
  if ( argc > 0 )
  {
    v3 = argv;
    do
      MessageBuffer::WriteString(this: &mb, pString: v3[v2++]);
    while ( v2 < argc );
  }
  pChunkLengths = ConCommandBase::GetName(this: (CVMPIFile_Memory *)&mb);
  pChunks = mb.data;
  VMPI_SendChunks((const void *const *)&pChunks, &pChunkLengths, nChunks: 1, iDest: -3, fVMPISendFlags: 0);
  MessageBuffer::~MessageBuffer(this: &mb);
}

//------------------------------------------------------------------------------
// Address: 0x10025D10
// Name: void VMPI_ReceiveCommandLine(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl VMPI_ReceiveCommandLine()
{
  CVMPIConnection *v0; // esi
  IThreadedTCPSocket *m_pSocket; // ecx
  double startTime; // [esp+4h] [ebp-10h] BYREF
  int pChunkLengths; // [esp+Ch] [ebp-8h] BYREF
  unsigned __int8 chData[2]; // [esp+10h] [ebp-4h] BYREF

  ++g_nMessagesSent;
  HIDWORD(startTime) = chData;
  v0 = g_Connections[0];
  *(_WORD *)chData = 795;
  pChunkLengths = 2;
  g_nBytesSent += 6;
  if ( g_Connections[0] != nullptr
    && VMPI_FilterPacketsForServiceDownloader(
         pConnection: g_Connections[0],
         pChunks: (const void *const *)&startTime + 1,
         &pChunkLengths,
         nChunks: 1) == 0 )
  {
    m_pSocket = v0->m_pSocket;
    if ( m_pSocket != nullptr )
      m_pSocket->SendChunks(this: m_pSocket, a2: (const void *const *)&startTime + 1, a3: &pChunkLengths, a4: 1);
  }
  startTime = _Plat_FloatTime();
  while ( !g_bReceivedWorkerCommandLine )
  {
    if ( _Plat_FloatTime() - startTime > 30.0 )
      _Error(a1: "VMPI_ReceiveCommandLine: timeout. Is the master running in SDK mode?");
    VMPI_DispatchNextMessage(timeout: (CTCPPacket *)0x2710);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10025DD0
// Name: void VMPI_SendExeName(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl VMPI_SendExeName()
{
  HMODULE ModuleHandleA; // eax
  char baseExeFilename[260]; // [esp+0h] [ebp-224h] BYREF
  char fileBase[260]; // [esp+104h] [ebp-120h] BYREF
  MessageBuffer mb; // [esp+208h] [ebp-1Ch] BYREF
  int pChunkLengths; // [esp+218h] [ebp-Ch] BYREF
  void *pChunks; // [esp+21Ch] [ebp-8h] BYREF
  char cPacketHeader[2]; // [esp+220h] [ebp-4h] BYREF

  MessageBuffer::MessageBuffer(this: &mb);
  *(_WORD *)cPacketHeader = 1563;
  MessageBuffer::write(this: &mb, p: cPacketHeader, bytes: 2);
  ModuleHandleA = GetModuleHandleA(lpModuleName: nullptr);
  if ( GetModuleFileNameA(hModule: ModuleHandleA, lpFilename: baseExeFilename, nSize: 0x104u) == 0 )
    _Error(a1: "VMPI_CheckSDKMode -> GetModuleFileName failed.");
  V_FileBase(in: baseExeFilename, out: fileBase, maxlen: 260);
  MessageBuffer::WriteString(this: &mb, pString: fileBase);
  VMPI_SuperSpew(pMsg: "Sending SUBPACKET_VERIFY_EXE_NAME (%s).\n", fileBase);
  pChunkLengths = ConCommandBase::GetName(this: (CVMPIFile_Memory *)&mb);
  pChunks = mb.data;
  VMPI_SendChunks((const void *const *)&pChunks, &pChunkLengths, nChunks: 1, iDest: -3, fVMPISendFlags: 0);
  MessageBuffer::~MessageBuffer(this: &mb);
}

//------------------------------------------------------------------------------
// Address: 0x10025EA0
// Name: private: void CMasterBroadcaster::ThreadFn(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMasterBroadcaster::ThreadFn(CMasterBroadcaster *this)
{
  void *UserData; // eax
  int v3; // edi
  int v4; // ebx
  int v5; // edi
  unsigned int v6; // edx
  ITCPConnectSocket *m_pListenSocket; // ecx
  bool v8; // al
  IThreadedTCPSocket *v9; // edx
  ITCPConnectSocket *m_pDownloaderListenSocket; // ecx
  IThreadedTCPSocket *v11; // edi
  int v12; // eax
  CVMPIConnection *v13; // ecx
  CVMPIConnection *v14; // edi
  ITCPSocketHandler *(__thiscall *GetHandler)(IThreadedTCPSocket *); // eax
  int *v16; // eax
  int m_Next; // edx
  UtlLinkedListElem_t<CUtlVector<char,CUtlMemory<char,int> > *,unsigned short> *m_pMemory; // edi
  int v19; // ebx
  CUtlVector<char,CUtlMemory<char,int> > *m_Element; // edi
  unsigned __int8 *m_Size; // ecx
  int v22; // edx
  int v23; // eax
  int v24; // edi
  void *v25; // eax
  char pData[768]; // [esp+4h] [ebp-3E8h] BYREF
  char pPacketIDString[64]; // [esp+304h] [ebp-E8h] BYREF
  char pSubPacketIDString[64]; // [esp+344h] [ebp-A8h] BYREF
  char v29; // [esp+384h] [ebp-68h] BYREF
  int v30; // [esp+388h] [ebp-64h]
  bf_write buf; // [esp+38Ch] [ebp-60h] BYREF
  CCriticalSectionLock v32; // [esp+3A4h] [ebp-48h] BYREF
  CCriticalSectionLock v33; // [esp+3ACh] [ebp-40h] BYREF
  char *v34; // [esp+3B4h] [ebp-38h]
  void *pChunks; // [esp+3B8h] [ebp-34h] BYREF
  int v36; // [esp+3BCh] [ebp-30h]
  int pChunkLengths; // [esp+3C0h] [ebp-2Ch] BYREF
  int nServiceDownloaders; // [esp+3C4h] [ebp-28h] BYREF
  unsigned int startTime; // [esp+3C8h] [ebp-24h]
  CCriticalSectionLock v40; // [esp+3CCh] [ebp-20h] BYREF
  int v41; // [esp+3D4h] [ebp-18h] BYREF
  __int16 v42; // [esp+3D8h] [ebp-14h]
  int nRegularWorkers; // [esp+3DCh] [ebp-10h] BYREF
  int v44; // [esp+3E0h] [ebp-Ch]
  IThreadedTCPSocket *v45; // [esp+3E4h] [ebp-8h] BYREF
  int v46; // [esp+3E8h] [ebp-4h]

  UserData = CTCPPacket::GetUserData(this: &this->m_hShutdownEvent);
  if ( WaitForSingleObject(hHandle: UserData, dwMilliseconds: 0x14u) == 258 )
  {
    do
    {
      startTime = GetTickCount();
      while ( 1 )
      {
        CCriticalSectionLock::CCriticalSectionLock(this: &v40, pCS: &g_ConnectionsCS);
        CCriticalSectionLock::Lock(this: &v40);
        CountActiveConnections(&nRegularWorkers, &nServiceDownloaders);
        if ( nRegularWorkers >= this->m_nMaxWorkers )
          break;
        if ( this->m_pSocket != nullptr )
        {
          v44 = _Plat_MSTime();
          if ( v44 - this->m_LastSendTime >= 0x258 )
          {
            bf_write::bf_write(this: &buf, pDebugName: "packetBuf", pData, nBytes: 768, nBits: -1);
            CMasterBroadcaster::BuildBroadcastPacket(this, &buf);
            v3 = 23397;
            v46 = 23397;
            do
            {
              if ( this->m_bPatching )
              {
                v4 = 0;
                if ( this->m_PatchWorkerIPs.m_Size > 0 )
                {
                  v5 = 0;
                  do
                  {
                    v41 = *(_DWORD *)this->m_PatchWorkerIPs.m_Memory.m_pMemory[v5].ip;
                    v42 = v46;
                    if ( !this->m_pSocket->SendTo(
                            this: this->m_pSocket,
                            a2: (const CIPAddr *)&v41,
                            a3: buf.m_pData,
                            a4: (buf.m_iCurBit + 7) >> 3) )
                      VMPI_WriteToLogFile(pMsg: "Error in SendTo trying to send patch request packet!\n");
                    _ThreadSleep(a1: 2);
                    ++v4;
                    ++v5;
                  }
                  while ( v4 < this->m_PatchWorkerIPs.m_Size );
                  v3 = v46;
                }
              }
              else
              {
                this->m_pSocket->Broadcast(this: this->m_pSocket, a2: buf.m_pData, a3: (buf.m_iCurBit + 7) >> 3, a4: v3);
              }
              v46 = ++v3;
            }
            while ( v3 <= 23412 );
            this->m_PatchWorkerIPs.m_Size = 0;
            if ( this->m_PatchWorkerIPs.m_Memory.m_nGrowSize >= 0 )
            {
              if ( this->m_PatchWorkerIPs.m_Memory.m_pMemory != nullptr )
              {
                _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)this->m_PatchWorkerIPs.m_Memory.m_pMemory);
                this->m_PatchWorkerIPs.m_Memory.m_pMemory = nullptr;
              }
              this->m_PatchWorkerIPs.m_Memory.m_nAllocationCount = 0;
            }
            v6 = v44;
            this->m_PatchWorkerIPs.m_pElements = this->m_PatchWorkerIPs.m_Memory.m_pMemory;
            this->m_LastSendTime = v6;
          }
        }
        m_pListenSocket = this->m_pListenSocket;
        v45 = nullptr;
        v8 = m_pListenSocket->Update(this: m_pListenSocket, a2: &v45, a3: 0);
        v9 = v45;
        if ( !v8 || v45 == nullptr )
        {
          m_pDownloaderListenSocket = this->m_pDownloaderListenSocket;
          if ( m_pDownloaderListenSocket != nullptr && nServiceDownloaders < this->m_nMaxWorkers - nRegularWorkers + 8 )
          {
            v8 = m_pDownloaderListenSocket->Update(this: m_pDownloaderListenSocket, a2: &v45, a3: 0);
            v9 = v45;
          }
        }
        if ( !v8 || v9 == nullptr )
          break;
        v9->GetRemoteAddr(this: v9, result: (CIPAddr *)&v29);
        if ( (unsigned __int16)(v30 - 22351) <= 9u )
        {
          v11 = v45;
          CCriticalSectionLock::CCriticalSectionLock(this: &v33, pCS: &g_ConnectionsCS);
          v12 = 0;
          if ( g_nConnections <= 0 )
          {
LABEL_33:
            CCriticalSectionLock::~CCriticalSectionLock(this: &v33);
          }
          else
          {
            while ( 1 )
            {
              v13 = g_Connections[v12];
              if ( v13 != nullptr && v13->m_pSocket == v11 )
                break;
              if ( ++v12 >= g_nConnections )
                goto LABEL_33;
            }
            v14 = g_Connections[v12];
            CCriticalSectionLock::~CCriticalSectionLock(this: &v33);
            if ( v14 != nullptr )
              v14->m_bIsAService = true;
          }
        }
        CCriticalSectionLock::CCriticalSectionLock(this: &v32, pCS: &g_PersistentPacketsCS);
        CCriticalSectionLock::Lock(this: &v32);
        GetHandler = v45->GetHandler;
        v46 = 1;
        v16 = (int *)GetHandler(this: v45);
        LOWORD(m_Next) = g_PersistentPackets.m_Head;
        v44 = (int)v16;
        if ( g_PersistentPackets.m_Head != 0xFFFF )
        {
          m_pMemory = g_PersistentPackets.m_Memory.m_pMemory;
          while ( 1 )
          {
            v19 = (unsigned __int16)m_Next;
            m_Element = m_pMemory[v19].m_Element;
            m_Size = (unsigned __int8 *)m_Element->m_Size;
            v34 = m_Element->m_Memory.m_pMemory;
            v22 = *v16;
            v36 = (int)m_Size;
            v23 = (*(int (__thiscall **)(int *))(v22 + 16))(a1: v16);
            pChunkLengths = v36;
            pChunks = v34;
            VMPI_SendChunks((const void *const *)&pChunks, &pChunkLengths, nChunks: 1, iDest: v23, fVMPISendFlags: 0);
            if ( g_bSuperSpewEnabled )
            {
              if ( m_Element->m_Size <= 2 )
              {
                VMPI_SuperSpew(pMsg: "Sending a really short persistent packet (%d bytes).\n", m_Element->m_Size);
              }
              else
              {
                CVMPIPacketIDReg::Lookup(
                  nPacketID: *(unsigned __int8 *)m_Element->m_Memory.m_pMemory,
                  nSubPacketID: *((unsigned __int8 *)m_Element->m_Memory.m_pMemory + 1),
                  pPacketIDString,
                  nPacketIDStringSize: 64,
                  pSubPacketIDString,
                  nSubPacketIDStringSize: 64);
                v24 = v46;
                VMPI_SuperSpew(
                  pMsg: "Sending persistent packet %d. PacketID: %s, SubPacketID: %s.\n",
                  v46,
                  pPacketIDString,
                  pSubPacketIDString);
                v46 = v24 + 1;
              }
            }
            m_pMemory = g_PersistentPackets.m_Memory.m_pMemory;
            m_Next = g_PersistentPackets.m_Memory.m_pMemory[v19].m_Next;
            if ( m_Next == 0xFFFF )
              break;
            v16 = (int *)v44;
          }
        }
        UpdateActiveConnectionsText();
        CCriticalSectionLock::~CCriticalSectionLock(this: &v32);
        CCriticalSectionLock::~CCriticalSectionLock(this: &v40);
        if ( GetTickCount() - startTime >= 0x1F4 )
          goto LABEL_47;
      }
      CCriticalSectionLock::~CCriticalSectionLock(this: &v40);
LABEL_47:
      v25 = CTCPPacket::GetUserData(this: &this->m_hShutdownEvent);
    }
    while ( WaitForSingleObject(hHandle: v25, dwMilliseconds: 0x14u) == 258 );
  }
  CEvent::SetEvent(this: &this->m_hShutdownReply);
}

//------------------------------------------------------------------------------
// Address: 0x10026290
// Name: private: static unsigned long CMasterBroadcaster::StaticThreadFn(void __near *)
// Source: json
//------------------------------------------------------------------------------
unsigned int __stdcall CMasterBroadcaster::StaticThreadFn(CMasterBroadcaster *lpParameter)
{
  CMasterBroadcaster::ThreadFn(this: lpParameter);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x100262B0
// Name: void VMPI_HandleTimingWait_Master(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl VMPI_HandleTimingWait_Master()
{
  int v0; // eax
  void *pChunks; // [esp+0h] [ebp-Ch] BYREF
  int pChunkLengths; // [esp+4h] [ebp-8h] BYREF
  unsigned __int8 cPacket[2]; // [esp+8h] [ebp-4h] BYREF

  v0 = _CommandLine();
  if ( (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v0 + 40))(a1: v0, a2: g_VMPIParams[9].m_pName) != 0 )
  {
    _Msg(a1: "-mpi_TimingWait specified. Waiting for a keypress to continue... ");
    getch();
    _Msg(a1: "\n");
    *(_WORD *)cPacket = 1307;
    pChunkLengths = 2;
    pChunks = cPacket;
    VMPI_SendChunks((const void *const *)&pChunks, &pChunkLengths, nChunks: 1, iDest: -3, fVMPISendFlags: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10026320
// Name: bool MPI_Init_Worker(int __near &,char __near * __near * __near &,class CIPAddr const __near &,bool)
// Source: json
//------------------------------------------------------------------------------
char __cdecl MPI_Init_Worker(
        int *argc,
        char ***argv,
        const CIPAddr *masterAddr,
        IThreadedTCPSocket *bConnectingAsService)
{
  int v4; // edi
  ITCPConnectSocket *v5; // esi
  const CIPAddr *v6; // eax
  void (*v7)(const char *, ...); // edi
  bool (__thiscall *Update)(ITCPConnectSocket *, IThreadedTCPSocket **, unsigned int); // edx
  void (__thiscall ***v9)(_DWORD, int, char **); // eax
  int i; // esi
  int v11; // eax
  int v13; // eax
  int v14; // esi
  int flSeconds; // [esp+0h] [ebp-34h]
  CWaitTimer wait; // [esp+14h] [ebp-20h] BYREF
  CIPAddr v17; // [esp+1Eh] [ebp-16h] BYREF
  CVMPIConnectionCreator connectionCreator; // [esp+24h] [ebp-10h] BYREF
  int nAttempts; // [esp+28h] [ebp-Ch]
  int iFirstPort; // [esp+2Ch] [ebp-8h]
  int iLastPort; // [esp+30h] [ebp-4h]

  v4 = 22340;
  g_bMPIMaster = false;
  connectionCreator.__vftable = (CVMPIConnectionCreator_vtbl *)&CVMPIConnectionCreator::`vftable';
  iFirstPort = 22340;
  iLastPort = 22350;
  if ( (_BYTE)bConnectingAsService != 0 )
  {
    iFirstPort = 22351;
    v4 = 22351;
    iLastPort = 22360;
  }
  nAttempts = 1;
  while ( 2 )
  {
    v5 = nullptr;
    if ( v4 > iLastPort )
    {
LABEL_8:
      flSeconds = v4;
      v7 = (void (*)(const char *, ...))_Error;
      _Error(a1: "Can't bind a port in range [%d, %d].", flSeconds, iLastPort);
    }
    else
    {
      while ( 1 )
      {
        v6 = CIPAddr::CIPAddr(this: &v17, ip0: 0, ip1: 0, ip2: 0, ip3: 0, ipPort: v4);
        v5 = ThreadedTCP_CreateConnector(addr: masterAddr, localAddr: v6, pHandlerCreator: &connectionCreator);
        if ( v5 != nullptr )
          break;
        if ( ++v4 > iLastPort )
        {
          v4 = iFirstPort;
          goto LABEL_8;
        }
      }
      v7 = (void (*)(const char *, ...))_Error;
    }
    CWaitTimer::CWaitTimer(this: &wait, flSeconds: 3.0);
    while ( 1 )
    {
      Update = v5->Update;
      bConnectingAsService = nullptr;
      if ( Update(this: v5, a2: &bConnectingAsService, a3: 100u) )
      {
        if ( bConnectingAsService != nullptr )
        {
          VMPI_SendMachineNameTo(iProc: 0);
          VMPI_ReceiveExeName();
          if ( g_bVMPISDKMode )
          {
            VMPI_ReceiveCommandLine();
            v9 = (void (__thiscall ***)(_DWORD, int, char **))_CommandLine();
            (**v9)(a1: v9, a2: g_WorkerCommandLine.m_Size, a3: g_WorkerCommandLine.m_Memory.m_pMemory);
            *argc = g_WorkerCommandLine.m_Size;
            *argv = g_WorkerCommandLine.m_Memory.m_pMemory;
          }
          ParseOptions(argc: g_WorkerCommandLine.m_Size, argv: g_WorkerCommandLine.m_Memory.m_pMemory);
          for ( i = 0; i < g_WorkerCommandLine.m_Size; ++i )
            _Msg(a1: "arg %d: %s\n", i, g_WorkerCommandLine.m_Memory.m_pMemory[i]);
          v11 = _CommandLine();
          if ( (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v11 + 40))(a1: v11, a2: g_VMPIParams[9].m_pName) != 0 )
          {
            _Msg(a1: "-mpi_TimingWait specified. Waiting for master to start...");
            while ( !g_bTimingWaitDone )
              VMPI_DispatchNextMessage(timeout: (CTCPPacket *)0x32);
            _Msg(a1: "\n ");
          }
          return 1;
        }
      }
      else
      {
        v5->Release(this: v5);
        v7(a1: "ITCPConnectSocket::Update() errored out");
      }
      if ( !CWaitTimer::ShouldKeepWaiting(this: &wait) )
        break;
      Sleep(dwMilliseconds: 0x64u);
    }
    v5->Release(this: v5);
    v13 = _CommandLine();
    if ( (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v13 + 40))(a1: v13, a2: g_VMPIParams[5].m_pName) != 0 )
    {
      v14 = nAttempts;
      _Msg(
        a1: "%s found. Retrying connection to %d.%d.%d.%d:%d (attempt %d).\n",
        g_VMPIParams[5].m_pName,
        masterAddr->ip[0],
        masterAddr->ip[1],
        masterAddr->ip[2],
        masterAddr->ip[3],
        masterAddr->port,
        nAttempts);
      v4 = iFirstPort;
      nAttempts = v14 + 1;
      continue;
    }
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10026580
// Name: public: bool CMasterBroadcaster::Init(int,char __near * __near *,char const __near *,int,enum VMPIRunMode,bool)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CMasterBroadcaster::Init(
        CMasterBroadcaster *this,
        int argc,
        char **argv,
        char *pDependencyFilename,
        int nMaxWorkers,
        VMPIRunMode runMode,
        bool bPatchMode)
{
  VMPIRunMode v7; // eax
  char *Arg; // eax
  int v10; // eax
  int v11; // esi
  ITCPConnectSocket *Listener; // eax
  int j; // esi
  ITCPConnectSocket *v14; // eax
  bool v15; // zf
  ISocket *IPSocket; // eax
  int v17; // esi
  char *v18; // esi
  long double v19; // st7
  int v20; // esi
  char *v21; // eax
  bool v22; // sf
  int v23; // edi
  int m_Size; // edi
  int m_nAllocationCount; // eax
  char **m_pMemory; // ecx
  int v27; // eax
  char **v28; // edi
  int v29; // edi
  int v30; // eax
  int v31; // ecx
  char **v32; // eax
  int v33; // ecx
  char **v34; // eax
  int v35; // eax
  int v36; // ecx
  char **v37; // eax
  int v38; // ecx
  int v39; // edi
  int v40; // eax
  int v41; // ecx
  char **v42; // eax
  int v43; // ecx
  int v44; // eax
  int v45; // ecx
  char **v46; // eax
  int v47; // ecx
  int v48; // edi
  int v49; // eax
  int v50; // ecx
  char **v51; // eax
  int v52; // ecx
  HANDLE Thread; // eax
  CDependencyInfo::CDependencyFile **v54; // eax
  char *v56; // esi
  CDependencyInfo::CDependencyFile **v57; // eax
  unsigned __int16 m_iListenPort; // [esp-Ch] [ebp-23Ch]
  unsigned __int64 v59; // [esp-8h] [ebp-238h]
  unsigned __int64 v60; // [esp-8h] [ebp-238h]
  CDependencyInfo dependencyInfo; // [esp+Ch] [ebp-224h] BYREF
  CCycleCount cnt; // [esp+228h] [ebp-8h]
  char *pDependencyFilenamea; // [esp+240h] [ebp+10h]
  CDependencyInfo::CDependencyFile *pDependencyFilenameb; // [esp+240h] [ebp+10h]
  float id; // [esp+244h] [ebp+14h]
  int i; // [esp+244h] [ebp+14h]
  char *ia; // [esp+244h] [ebp+14h]
  int ib; // [esp+244h] [ebp+14h]
  char *ic; // [esp+244h] [ebp+14h]

  v7 = runMode;
  this->m_RunMode = runMode;
  this->m_nMaxWorkers = nMaxWorkers;
  memset(&dependencyInfo.m_Files, 0, sizeof(dependencyInfo.m_Files));
  if ( v7 == VMPI_RUN_NETWORKED && !g_bVMPISDKMode )
    SetupDependencyInfo(pInfo: &dependencyInfo, pDependencyFilename, bPatchMode);
  this->m_pListenSocket = nullptr;
  this->m_pDownloaderListenSocket = nullptr;
  Arg = VMPI_FindArg(argc, argv, pName: g_VMPIParams[3].m_pName, pDefault: defaultValue);
  if ( Arg != nullptr )
  {
    v10 = atoi(nptr: Arg);
    this->m_iListenPort = v10;
    m_iListenPort = this->m_iListenPort;
    this->m_iDownloaderListenPort = v10 + 1;
    this->m_pListenSocket = ThreadedTCP_CreateListener(
                              pHandlerCreator: &this->m_ConnectionCreator,
                              port: m_iListenPort,
                              nQueueLength: 5);
    if ( !g_bVMPISDKMode )
      this->m_pDownloaderListenSocket = ThreadedTCP_CreateListener(
                                          pHandlerCreator: &this->m_ConnectionCreator,
                                          port: this->m_iDownloaderListenPort,
                                          nQueueLength: 5);
  }
  else
  {
    cnt.m_Int64 = __rdtsc();
    HIDWORD(v59) = HIDWORD(_g_ClockSpeed);
    LODWORD(v59) = _g_ClockSpeed;
    srand(seed: 1000000 * cnt.m_Int64 / v59);
    v11 = 23311;
    while ( 1 )
    {
      this->m_iListenPort = v11;
      Listener = ThreadedTCP_CreateListener(pHandlerCreator: &this->m_ConnectionCreator, port: v11, nQueueLength: 5);
      this->m_pListenSocket = Listener;
      if ( Listener != nullptr )
        break;
      if ( ++v11 > 23330 )
        goto LABEL_16;
    }
    if ( !g_bVMPISDKMode )
    {
      for ( j = this->m_iListenPort + 1; j <= 23330; ++j )
      {
        this->m_iDownloaderListenPort = j;
        if ( j != this->m_iListenPort )
        {
          v14 = ThreadedTCP_CreateListener(pHandlerCreator: &this->m_ConnectionCreator, port: j, nQueueLength: 5);
          this->m_pDownloaderListenSocket = v14;
          if ( v14 != nullptr )
            break;
        }
      }
    }
  }
LABEL_16:
  if ( this->m_pListenSocket == nullptr || !g_bVMPISDKMode && this->m_pDownloaderListenSocket == nullptr )
    _Error(a1: "Can't bind a listen socket in port range [%d, %d].", 21140, 21145);
  v15 = this->m_RunMode == VMPI_RUN_NETWORKED;
  this->m_bPatching = false;
  if ( v15 && !g_bVMPISDKMode )
  {
    IPSocket = CreateIPSocket();
    this->m_pSocket = IPSocket;
    if ( !IPSocket->BindToAny(this: IPSocket, a2: 0) )
      _Error(a1: "MPI_Init_Master: can't bind a socket");
    if ( bPatchMode )
    {
      v17 = 0;
      this->m_bPatching = true;
      if ( argc <= 0 )
      {
LABEL_28:
        v18 = nullptr;
      }
      else
      {
        while ( _V_stricmp(s1: argv[v17], s2: "-mpi_PatchVersion") != 0 )
        {
          if ( ++v17 >= argc )
            goto LABEL_28;
        }
        if ( v17 + 1 >= argc )
          v18 = "0";
        else
          v18 = argv[v17 + 1];
      }
      v19 = atof(nptr: v18);
      if ( v19 <= 0.0 || (id = v19) >= 32767.0 )
        _Error(a1: "-mpi_PatchVersion <val> -  val must be between 1.0 and 32767.0");
      V_strncpy(pDest: this->m_BroadcastInfo.m_PatchVersion, pSrc: v18, maxLen: 32);
    }
    else
    {
      this->m_BroadcastInfo.m_PatchVersion[0] = 0;
    }
    Sleep(dwMilliseconds: 1u);
    cnt.m_Int64 = __rdtsc();
    HIDWORD(v60) = HIDWORD(_g_ClockSpeed);
    LODWORD(v60) = _g_ClockSpeed;
    this->m_BroadcastInfo.m_JobID[0] = 1000000 * cnt.m_Int64 / v60;
    Sleep(dwMilliseconds: 1u);
    cnt.m_Int64 = __rdtsc();
    HIDWORD(v60) = HIDWORD(_g_ClockSpeed);
    LODWORD(v60) = _g_ClockSpeed;
    this->m_BroadcastInfo.m_JobID[1] = 1000000 * cnt.m_Int64 / v60;
    Sleep(dwMilliseconds: 1u);
    cnt.m_Int64 = __rdtsc();
    HIDWORD(v60) = HIDWORD(_g_ClockSpeed);
    LODWORD(v60) = _g_ClockSpeed;
    this->m_BroadcastInfo.m_JobID[2] = 1000000 * cnt.m_Int64 / v60;
    Sleep(dwMilliseconds: 1u);
    cnt.m_Int64 = __rdtsc();
    HIDWORD(v60) = HIDWORD(_g_ClockSpeed);
    LODWORD(v60) = _g_ClockSpeed;
    v20 = 0;
    this->m_BroadcastInfo.m_JobID[3] = 1000000 * cnt.m_Int64 / v60;
    if ( argc <= 0 )
      goto LABEL_40;
    while ( _V_stricmp(s1: argv[v20], s2: "-mpi_pw") != 0 )
    {
      if ( ++v20 >= argc )
        goto LABEL_40;
    }
    if ( v20 + 1 >= argc )
    {
      v21 = (char *)defaultValue;
      goto LABEL_41;
    }
    v56 = argv[v20 + 1];
    if ( v56 != nullptr )
      v21 = v56;
    else
LABEL_40:
      v21 = (char *)defaultValue;
LABEL_41:
    V_strncpy(pDest: this->m_BroadcastInfo.m_Password, pSrc: v21, maxLen: 256);
    V_strncpy(pDest: this->m_BroadcastInfo.m_WorkerExeFilename, pSrc: dependencyInfo.m_OriginalExeFilename, maxLen: 260);
    v22 = this->m_BroadcastInfo.m_Args.m_Memory.m_nGrowSize < 0;
    this->m_BroadcastInfo.m_Args.m_Size = 0;
    if ( !v22 )
    {
      if ( this->m_BroadcastInfo.m_Args.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_BroadcastInfo.m_Args.m_Memory.m_pMemory);
        this->m_BroadcastInfo.m_Args.m_Memory.m_pMemory = nullptr;
      }
      this->m_BroadcastInfo.m_Args.m_Memory.m_nAllocationCount = 0;
    }
    this->m_BroadcastInfo.m_Args.m_pElements = this->m_BroadcastInfo.m_Args.m_Memory.m_pMemory;
    for ( i = 1; i < argc; ++i )
    {
      pDependencyFilenamea = argv[i];
      v23 = _V_strlen(str: pDependencyFilenamea) + 1;
      HIDWORD(cnt.m_Int64) = operator new(size: v23);
      V_strncpy(pDest: (char *)HIDWORD(cnt.m_Int64), pSrc: pDependencyFilenamea, maxLen: v23);
      m_Size = this->m_BroadcastInfo.m_Args.m_Size;
      m_nAllocationCount = this->m_BroadcastInfo.m_Args.m_Memory.m_nAllocationCount;
      if ( m_Size + 1 > m_nAllocationCount )
        CUtlMemory<int,int>::Grow(
          this: (CUtlMemory<CTCPPacket *,int> *)&this->m_BroadcastInfo.m_Args,
          num: m_Size - m_nAllocationCount + 1);
      ++this->m_BroadcastInfo.m_Args.m_Size;
      m_pMemory = this->m_BroadcastInfo.m_Args.m_Memory.m_pMemory;
      v27 = this->m_BroadcastInfo.m_Args.m_Size - m_Size - 1;
      this->m_BroadcastInfo.m_Args.m_pElements = m_pMemory;
      if ( v27 > 0 )
        _V_memmove(
          dest: (unsigned __int8 *)&m_pMemory[m_Size + 1],
          src: (unsigned __int8 *)&m_pMemory[m_Size],
          count: 4 * v27);
      v28 = &this->m_BroadcastInfo.m_Args.m_Memory.m_pMemory[m_Size];
      if ( v28 != nullptr )
        *v28 = (char *)HIDWORD(cnt.m_Int64);
    }
    v29 = _V_strlen(str: this->m_BroadcastInfo.m_WorkerExeFilename) + 1;
    ia = (char *)operator new(size: v29);
    V_strncpy(pDest: ia, pSrc: this->m_BroadcastInfo.m_WorkerExeFilename, maxLen: v29);
    v30 = this->m_BroadcastInfo.m_Args.m_Size;
    v31 = this->m_BroadcastInfo.m_Args.m_Memory.m_nAllocationCount;
    if ( v30 + 1 > v31 )
      CUtlMemory<int,int>::Grow(this: (CUtlMemory<CTCPPacket *,int> *)&this->m_BroadcastInfo.m_Args, num: v30 - v31 + 1);
    ++this->m_BroadcastInfo.m_Args.m_Size;
    v32 = this->m_BroadcastInfo.m_Args.m_Memory.m_pMemory;
    v33 = this->m_BroadcastInfo.m_Args.m_Size - 1;
    this->m_BroadcastInfo.m_Args.m_pElements = v32;
    if ( v33 > 0 )
      _V_memmove(dest: (unsigned __int8 *)v32 + 4, src: (unsigned __int8 *)v32, count: 4 * v33);
    v34 = this->m_BroadcastInfo.m_Args.m_Memory.m_pMemory;
    if ( v34 != nullptr )
      *v34 = ia;
    for ( ib = 0; ib < dependencyInfo.m_Files.m_Size; ++ib )
    {
      v35 = this->m_BroadcastInfo.m_Args.m_Size;
      v36 = this->m_BroadcastInfo.m_Args.m_Memory.m_nAllocationCount;
      if ( v35 + 1 > v36 )
        CUtlMemory<int,int>::Grow(
          this: (CUtlMemory<CTCPPacket *,int> *)&this->m_BroadcastInfo.m_Args,
          num: v35 - v36 + 1);
      ++this->m_BroadcastInfo.m_Args.m_Size;
      v37 = this->m_BroadcastInfo.m_Args.m_Memory.m_pMemory;
      v38 = this->m_BroadcastInfo.m_Args.m_Size - 2;
      this->m_BroadcastInfo.m_Args.m_pElements = v37;
      if ( v38 > 0 )
        _V_memmove(dest: (unsigned __int8 *)v37 + 8, src: (unsigned __int8 *)v37 + 4, count: 4 * v38);
      if ( this->m_BroadcastInfo.m_Args.m_Memory.m_pMemory != (char **)-4 )
        *((_DWORD *)this->m_BroadcastInfo.m_Args.m_Memory.m_pMemory + 1) = "-mpi_file";
      pDependencyFilenameb = dependencyInfo.m_Files.m_Memory.m_pMemory[ib];
      v39 = _V_strlen(str: pDependencyFilenameb->m_Name) + 1;
      HIDWORD(cnt.m_Int64) = operator new(size: v39);
      V_strncpy(pDest: (char *)HIDWORD(cnt.m_Int64), pSrc: pDependencyFilenameb->m_Name, maxLen: v39);
      v40 = this->m_BroadcastInfo.m_Args.m_Size;
      v41 = this->m_BroadcastInfo.m_Args.m_Memory.m_nAllocationCount;
      if ( v40 + 1 > v41 )
        CUtlMemory<int,int>::Grow(
          this: (CUtlMemory<CTCPPacket *,int> *)&this->m_BroadcastInfo.m_Args,
          num: v40 - v41 + 1);
      ++this->m_BroadcastInfo.m_Args.m_Size;
      v42 = this->m_BroadcastInfo.m_Args.m_Memory.m_pMemory;
      v43 = this->m_BroadcastInfo.m_Args.m_Size - 3;
      this->m_BroadcastInfo.m_Args.m_pElements = v42;
      if ( v43 > 0 )
        _V_memmove(dest: (unsigned __int8 *)v42 + 12, src: (unsigned __int8 *)v42 + 8, count: 4 * v43);
      if ( this->m_BroadcastInfo.m_Args.m_Memory.m_pMemory != (char **)-8 )
        *((_DWORD *)this->m_BroadcastInfo.m_Args.m_Memory.m_pMemory + 2) = HIDWORD(cnt.m_Int64);
    }
    v44 = this->m_BroadcastInfo.m_Args.m_Size;
    v45 = this->m_BroadcastInfo.m_Args.m_Memory.m_nAllocationCount;
    if ( v44 + 1 > v45 )
      CUtlMemory<int,int>::Grow(this: (CUtlMemory<CTCPPacket *,int> *)&this->m_BroadcastInfo.m_Args, num: v44 - v45 + 1);
    ++this->m_BroadcastInfo.m_Args.m_Size;
    v46 = this->m_BroadcastInfo.m_Args.m_Memory.m_pMemory;
    v47 = this->m_BroadcastInfo.m_Args.m_Size - 2;
    this->m_BroadcastInfo.m_Args.m_pElements = v46;
    if ( v47 > 0 )
      _V_memmove(dest: (unsigned __int8 *)v46 + 8, src: (unsigned __int8 *)v46 + 4, count: 4 * v47);
    if ( this->m_BroadcastInfo.m_Args.m_Memory.m_pMemory != (char **)-4 )
      *((_DWORD *)this->m_BroadcastInfo.m_Args.m_Memory.m_pMemory + 1) = "-mpi_filebase";
    v48 = _V_strlen(str: dependencyInfo.m_DependencyFilesDir) + 1;
    ic = (char *)operator new(size: v48);
    V_strncpy(pDest: ic, pSrc: dependencyInfo.m_DependencyFilesDir, maxLen: v48);
    v49 = this->m_BroadcastInfo.m_Args.m_Size;
    v50 = this->m_BroadcastInfo.m_Args.m_Memory.m_nAllocationCount;
    if ( v49 + 1 > v50 )
      CUtlMemory<int,int>::Grow(this: (CUtlMemory<CTCPPacket *,int> *)&this->m_BroadcastInfo.m_Args, num: v49 - v50 + 1);
    ++this->m_BroadcastInfo.m_Args.m_Size;
    v51 = this->m_BroadcastInfo.m_Args.m_Memory.m_pMemory;
    v52 = this->m_BroadcastInfo.m_Args.m_Size - 3;
    this->m_BroadcastInfo.m_Args.m_pElements = v51;
    if ( v52 > 0 )
      _V_memmove(dest: (unsigned __int8 *)v51 + 12, src: (unsigned __int8 *)v51 + 8, count: 4 * v52);
    if ( this->m_BroadcastInfo.m_Args.m_Memory.m_pMemory != (char **)-8 )
      *((_DWORD *)this->m_BroadcastInfo.m_Args.m_Memory.m_pMemory + 2) = ic;
    if ( bPatchMode )
      CMasterBroadcaster::GetPatchWorkerList(this, argc, argv);
  }
  this->m_ConnectionCreator.CreateNewHandler(this: &this->m_ConnectionCreator);
  this->m_LastSendTime = _Plat_MSTime() - 1200;
  CEvent::Init(this: &this->m_hShutdownEvent, bManualReset: false, bInitialState: false);
  CEvent::Init(this: &this->m_hShutdownReply, bManualReset: false, bInitialState: false);
  runMode = VMPI_RUN_NETWORKED;
  Thread = CreateThread(
             lpThreadAttributes: nullptr,
             dwStackSize: 0,
             lpStartAddress: (LPTHREAD_START_ROUTINE)CMasterBroadcaster::StaticThreadFn,
             lpParameter: this,
             dwCreationFlags: 0,
             lpThreadId: (LPDWORD)&runMode);
  this->m_hThread = Thread;
  if ( Thread != nullptr )
  {
    SetThreadPriority(hThread: Thread, nPriority: 2);
    v54 = dependencyInfo.m_Files.m_Memory.m_pMemory;
    dependencyInfo.m_Files.m_Size = 0;
    if ( dependencyInfo.m_Files.m_Memory.m_nGrowSize >= 0 )
    {
      if ( dependencyInfo.m_Files.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: dependencyInfo.m_Files.m_Memory.m_pMemory);
        v54 = nullptr;
        dependencyInfo.m_Files.m_Memory.m_pMemory = nullptr;
      }
      dependencyInfo.m_Files.m_Memory.m_nAllocationCount = 0;
    }
    dependencyInfo.m_Files.m_pElements = v54;
    if ( dependencyInfo.m_Files.m_Memory.m_nGrowSize >= 0 && v54 != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v54);
    return 1;
  }
  else
  {
    v57 = dependencyInfo.m_Files.m_Memory.m_pMemory;
    dependencyInfo.m_Files.m_Size = 0;
    if ( dependencyInfo.m_Files.m_Memory.m_nGrowSize >= 0 )
    {
      if ( dependencyInfo.m_Files.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: dependencyInfo.m_Files.m_Memory.m_pMemory);
        v57 = nullptr;
        dependencyInfo.m_Files.m_Memory.m_pMemory = nullptr;
      }
      dependencyInfo.m_Files.m_Memory.m_nAllocationCount = 0;
    }
    dependencyInfo.m_Files.m_pElements = v57;
    if ( dependencyInfo.m_Files.m_Memory.m_nGrowSize >= 0 && v57 != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v57);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10026EA0
// Name: bool InitMaster(int,char __near * __near *,char const __near *,enum VMPIRunMode,bool)
// Source: json
//------------------------------------------------------------------------------
char __cdecl InitMaster(int argc, char **argv, char *pDependencyFilename, VMPIRunMode runMode, bool bPatchMode)
{
  char *Arg; // eax
  int v6; // ebx
  bool v7; // al
  char result; // al
  char v9; // bl

  Arg = VMPI_FindArg(argc, argv, pName: g_VMPIParams[10].m_pName, pDefault: defaultValue);
  if ( Arg != nullptr )
  {
    v6 = atoi(nptr: Arg);
    _Warning(a1: "%s: waiting for %d processes to join.\n", g_VMPIParams[10].m_pName, v6);
    if ( v6 >= 2 )
    {
      if ( v6 > 512 )
        v6 = 512;
    }
    else
    {
      v6 = 2;
    }
  }
  else
  {
    v6 = 32;
  }
  g_bMPIMaster = true;
  g_nMaxWorkerCount = v6;
  if ( argc <= 0 )
    _Error(a1: "MPI_Init_Master: argc <= 0!");
  ParseOptions(argc, argv);
  VMPI_SendExeName();
  if ( g_bVMPISDKModeSet )
    v7 = g_bVMPISDKMode;
  else
    v7 = !VMPI_CheckForNonSDKExecutables();
  if ( v7 )
    VMPI_SendCommandLine(argc, argv);
  result = CMasterBroadcaster::Init(
             this: &g_MasterBroadcaster,
             argc,
             argv,
             pDependencyFilename,
             nMaxWorkers: v6,
             runMode,
             bPatchMode);
  if ( result != 0 )
  {
    if ( runMode == VMPI_RUN_LOCAL )
    {
      v9 = SpawnLocalWorker(argc, argv, iListenPort: g_MasterBroadcaster.m_iListenPort, bShowConsoleWindow: false);
      VMPI_HandleTimingWait_Master();
      return v9;
    }
    else
    {
      if ( VMPI_FindArg(argc, argv, pName: g_VMPIParams[11].m_pName, pDefault: defaultValue) != nullptr )
      {
        _Msg(a1: "%s found. Spawning a local worker automatically.\n", g_VMPIParams[11].m_pName);
        SpawnLocalWorker(argc: 1, argv, iListenPort: g_MasterBroadcaster.m_iListenPort, bShowConsoleWindow: true);
      }
      VMPI_HandleTimingWait_Master();
      return 1;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10026FF0
// Name: bool VMPI_Init(int __near &,char __near * __near * __near &,char const __near *,void (*)(int,char const __near *),enum VMPIRunMode,bool)
// Source: json
//------------------------------------------------------------------------------
char __cdecl VMPI_Init(
        int *argc,
        char ***argv,
        char *pDependencyFilename,
        void (__cdecl *handler)(int, const char *),
        VMPIRunMode runMode,
        IThreadedTCPSocket *bConnectingAsService)
{
  HMODULE LibraryA; // eax
  char *Arg; // ebx
  CIPAddr addr; // [esp+0h] [ebp-8h] BYREF

  if ( VMPI_IsLogFileEnabled() )
    _LoggingSystem_RegisterLoggingListener(a1: &g_VMPILoggingListener);
  if ( handler != nullptr )
    CUtlLinkedList<void (__cdecl *)(int,char const *),int,0,int,CUtlMemory<UtlLinkedListElem_t<void (__cdecl *)(int,char const *),int>,int>>::AddToTail(
      this: &g_DisconnectHandlers,
      src: &handler);
  VMPI_SetupAutoRestartParameters(argc: *argc, argv: *argv);
  VMPI_CheckSDKMode(argc: *argc, argv: *argv);
  g_bUseMPI = true;
  g_VMPIRunMode = runMode;
  CEvent::Init(this: &g_VMPIMessagesEvent, bManualReset: false, bInitialState: false);
  CEvent::Init(this: &g_ErrorSocketsEvent, bManualReset: false, bInitialState: false);
  LibraryA = LoadLibraryA(lpLibFileName: "kernel32.dll");
  g_hKernel32DLL = LibraryA;
  if ( LibraryA != nullptr )
    g_pConsoleWndFn = (HWND__ *(__cdecl *)())GetProcAddress(hModule: LibraryA, lpProcName: "GetConsoleWindow");
  Arg = VMPI_FindArg(argc: *argc, argv: *argv, pName: g_VMPIParams[2].m_pName, pDefault: nullptr);
  if ( Arg != nullptr )
  {
    CIPAddr::CIPAddr(this: &addr);
    addr.port = 23311;
    if ( !ConvertStringToIPAddr(pStr: Arg, pOut: &addr) )
      _Error(a1: "Unable to parse or resolve master IP (%s).\n", Arg);
    return MPI_Init_Worker(argc, argv, masterAddr: &addr, bConnectingAsService);
  }
  else if ( pDependencyFilename != nullptr )
  {
    return InitMaster(argc: *argc, argv: *argv, pDependencyFilename, runMode, bPatchMode: false);
  }
  else
  {
    _Error(a1: "VMPI started as master, but no dependency filename specified.\n");
    return 0;
  }
}

} // namespace vvis_dll
