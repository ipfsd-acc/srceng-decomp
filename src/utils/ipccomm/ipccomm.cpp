// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/ipccomm/ipccomm.cpp
// Functions: 14
// ============================================================

#include "utils\ipccomm\ipccomm.h"

//------------------------------------------------------------------------------
// Address: 0x00401000
// Name: public: CValveIpcMgr::Iterator::Iterator(char __near *)
// Source: json
//------------------------------------------------------------------------------
CValveIpcMgr::Iterator *__thiscall CValveIpcMgr::Iterator::Iterator(CValveIpcMgr::Iterator *this, char *m_pMemory)
{
  char *v2; // esi
  CValveIpcMgr::Iterator *result; // eax
  unsigned int v4; // edx

  v2 = m_pMemory;
  result = this;
  if ( m_pMemory == nullptr )
    v2 = (char *)&unk_40D18C;
  this->m_szServerName = v2;
  if ( *v2 != 0 )
  {
    v4 = strlen(v2);
    *(_QWORD *)&result->m_uuid.Data1 = *(_QWORD *)&v2[v4 + 1];
    *(_QWORD *)result->m_uuid.Data4 = *(_QWORD *)&v2[v4 + 9];
  }
  else
  {
    this->m_uuid = GUID_NULL;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00401070
// Name: public: class CValveIpcMgr::Iterator CValveIpcMgr::Iterator::Next(void)const
// Source: json
//------------------------------------------------------------------------------
CValveIpcMgr::Iterator *__thiscall CValveIpcMgr::Iterator::Next(
        CValveIpcMgr::Iterator *this,
        CValveIpcMgr::Iterator *result)
{
  char *m_szServerName; // esi
  GUID *v3; // eax
  unsigned int v4; // edx
  int v5; // ecx
  CValveIpcMgr::Iterator *v6; // eax
  int v7; // edx
  CValveIpcMgr::Iterator v9; // [esp+8h] [ebp-14h] BYREF

  m_szServerName = this->m_szServerName;
  if ( this->m_szServerName != nullptr && *m_szServerName != 0 )
  {
    v3 = &GUID_NULL;
    v4 = 16;
    v5 = (char *)&this->m_uuid - (char *)&GUID_NULL;
    while ( *(unsigned int *)((char *)&v3->Data1 + v5) == v3->Data1 )
    {
      v4 -= 4;
      v3 = (GUID *)((char *)v3 + 4);
      if ( v4 < 4 )
        goto LABEL_6;
    }
    v6 = CValveIpcMgr::Iterator::Iterator(this: &v9, m_pMemory: &m_szServerName[strlen(m_szServerName) + 17]);
  }
  else
  {
LABEL_6:
    memset((void *)&v9.m_uuid, 0, sizeof(v9.m_uuid));
    v9.m_szServerName = (char *)&unk_40D18C;
    v6 = &v9;
  }
  v7 = *(_DWORD *)&v6->m_uuid.Data4[4];
  *(_QWORD *)&result->m_szServerName = *(_QWORD *)&v6->m_szServerName;
  *(_QWORD *)&result->m_uuid.Data2 = *(_QWORD *)&v6->m_uuid.Data2;
  *(_DWORD *)&result->m_uuid.Data4[4] = v7;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00401110
// Name: private: int CValveIpcMgr::Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CValveIpcMgr::Shutdown(CValveIpcMgr *this)
{
  if ( this->m_pMemory != nullptr )
  {
    UnmapViewOfFile(lpBaseAddress: this->m_pMemory);
    this->m_pMemory = nullptr;
  }
  if ( this->m_hMemorySegment != nullptr )
  {
    CloseHandle(hObject: this->m_hMemorySegment);
    this->m_hMemorySegment = nullptr;
  }
  if ( this->m_hMutex != nullptr )
  {
    ReleaseMutex(hMutex: this->m_hMutex);
    CloseHandle(hObject: this->m_hMutex);
    this->m_hMutex = nullptr;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00401160
// Name: public: int CValveIpcMgr::DiscoverServer(char const __near *,unsigned char __near * __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CValveIpcMgr::DiscoverServer(
        CValveIpcMgr *this,
        const char *szServerName,
        unsigned __int8 **pszServerUID)
{
  unsigned int v3; // eax
  int i; // ecx
  CValveIpcMgr::Iterator v6; // [esp+4h] [ebp-28h] BYREF
  CValveIpcMgr::Iterator it; // [esp+18h] [ebp-14h] BYREF

  if ( szServerName == nullptr || *szServerName == 0 )
    return 0;
  CValveIpcMgr::Iterator::Iterator(this: &it, m_pMemory: this->m_pMemory);
  while ( 1 )
  {
    if ( it.m_szServerName == nullptr || *it.m_szServerName == 0 )
      return 0;
    v3 = 16;
    for ( i = 0; *(unsigned int *)((char *)&it.m_uuid.Data1 + i) == *(unsigned int *)((char *)&GUID_NULL.Data1 + i); i += 4 )
    {
      v3 -= 4;
      if ( v3 < 4 )
        return 0;
    }
    if ( _V_stricmp(s1: szServerName, s2: it.m_szServerName) == 0 )
      break;
    it = *CValveIpcMgr::Iterator::Next(this: &it, result: &v6);
  }
  if ( pszServerUID != nullptr )
    UuidToStringA(Uuid: &it.m_uuid, StringUuid: pszServerUID);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00401220
// Name: public: CValveIpcClient::CValveIpcClient(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CValveIpcClient *__thiscall CValveIpcClient::CValveIpcClient(CValveIpcClient *this, const char *szServerName)
{
  unsigned int v3; // eax
  char *v4; // eax
  const char *v5; // ecx
  char *v6; // edx
  char v7; // al

  if ( szServerName != nullptr )
    v3 = strlen(szServerName);
  else
    v3 = 0;
  v4 = (char *)operator new(nSize: v3 + 1);
  this->m_szServerName = v4;
  v5 = szServerName;
  if ( szServerName == nullptr )
    v5 = (const char *)&unk_40D18C;
  v6 = v4;
  do
  {
    v7 = *v5;
    *v6++ = *v5++;
  }
  while ( v7 != 0 );
  this->m_szServerUID = nullptr;
  this->m_hClientPipe = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00401280
// Name: public: int CValveIpcClient::Disconnect(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CValveIpcClient::Disconnect(CValveIpcClient *this)
{
  unsigned __int8 **p_m_szServerUID; // edi

  p_m_szServerUID = &this->m_szServerUID;
  if ( this->m_szServerUID == nullptr )
    return 0;
  if ( this->m_hClientPipe != nullptr )
  {
    CloseHandle(hObject: this->m_hClientPipe);
    this->m_hClientPipe = nullptr;
  }
  if ( *p_m_szServerUID != nullptr )
  {
    RpcStringFreeA(String: p_m_szServerUID);
    *p_m_szServerUID = nullptr;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x004012D0
// Name: char const __near * IsOption(char const __near * __near &,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl IsOption(const char **pszParse, const char *pOptShort, const char *pOptLong)
{
  const char *v3; // esi
  int v5; // ecx

  v3 = StringAfterPrefix(str: *pszParse, prefix: pOptShort);
  if ( v3 == nullptr )
  {
    if ( pOptLong == nullptr )
      return nullptr;
    v3 = StringAfterPrefix(str: *pszParse, prefix: pOptLong);
    if ( v3 == nullptr )
      return nullptr;
  }
  if ( isspace(c: *v3) != 0 )
  {
    do
      v5 = *++v3;
    while ( isspace(c: v5) != 0 );
  }
  *pszParse = v3;
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x00401340
// Name: bool Option(char const __near * __near &)
// Source: json
//------------------------------------------------------------------------------
char __cdecl Option(const char **pszParse)
{
  const char *v2; // eax
  const char *v3; // edi
  int v4; // eax
  char *i; // ebx

  if ( IsOption(pszParse, pOptShort: "e ", pOptLong: "engine ") != nullptr )
  {
    strcpy(g_options.chServerName, "ENGINE_IPC_SERVER");
    g_options.cmdType = COMMAND_ENGINE;
    return 1;
  }
  else if ( IsOption(pszParse, pOptShort: "v ", pOptLong: "hlmv ") != nullptr )
  {
    strcpy(g_options.chServerName, "HLMV_IPC_SERVER");
    g_options.cmdType = COMMAND_HLMV;
    return 1;
  }
  else
  {
    v2 = StringAfterPrefix(str: *pszParse, prefix: "srv ");
    v3 = v2;
    if ( v2 != nullptr )
    {
      if ( isspace(c: *v2) != 0 )
      {
        do
          v4 = *++v3;
        while ( isspace(c: v4) != 0 );
      }
      *pszParse = v3;
      for ( i = g_options.chServerName; **pszParse != 0; *i++ = *(*pszParse)++ )
      {
        if ( isspace(c: **pszParse) != 0 )
          break;
      }
      *i = 0;
      return 1;
    }
    else
    {
      return 0;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00401460
// Name: protected: CValveIpcMgr::~CValveIpcMgr(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CValveIpcMgr::~CValveIpcMgr(CValveIpcMgr *this)
{
  if ( this->m_pMemory != nullptr )
  {
    UnmapViewOfFile(lpBaseAddress: this->m_pMemory);
    this->m_pMemory = nullptr;
  }
  if ( this->m_hMemorySegment != nullptr )
  {
    CloseHandle(hObject: this->m_hMemorySegment);
    this->m_hMemorySegment = nullptr;
  }
  if ( this->m_hMutex != nullptr )
  {
    ReleaseMutex(hMutex: this->m_hMutex);
    CloseHandle(hObject: this->m_hMutex);
    this->m_hMutex = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004014B0
// Name: public: int CValveIpcMgr::Init(unsigned long)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CValveIpcMgr::Init(CValveIpcMgr *this, DWORD dwTimeout)
{
  HANDLE MutexA; // eax
  DWORD v5; // eax
  DWORD v6; // edi
  HANDLE FileMappingA; // eax
  char *v8; // eax

  if ( this->m_pMemory != nullptr )
    return 1;
  MutexA = CreateMutexA(lpMutexAttributes: nullptr, bInitialOwner: false, lpName: "VALVE_IPC_MGR__MTX_1");
  this->m_hMutex = MutexA;
  if ( MutexA != nullptr )
  {
    v5 = WaitForSingleObject(hHandle: MutexA, dwMilliseconds: dwTimeout);
    v6 = v5;
    if ( v5 == 0 || v5 == 128 )
    {
      FileMappingA = CreateFileMappingA(
                       hFile: (HANDLE)0xFFFFFFFF,
                       lpFileMappingAttributes: nullptr,
                       flProtect: 4u,
                       dwMaximumSizeHigh: 0,
                       dwMaximumSizeLow: 0x40000u,
                       lpName: "VALVE_IPC_MGR__MEM_1");
      this->m_hMemorySegment = FileMappingA;
      if ( FileMappingA != nullptr )
      {
        v8 = (char *)MapViewOfFile(
                       hFileMappingObject: FileMappingA,
                       dwDesiredAccess: 0xF001Fu,
                       dwFileOffsetHigh: 0,
                       dwFileOffsetLow: 0,
                       dwNumberOfBytesToMap: 0);
        if ( v8 != nullptr )
        {
          this->m_pMemory = v8;
          return 1;
        }
      }
    }
    if ( v6 == 0 || v6 == 128 )
    {
      ReleaseMutex(hMutex: this->m_hMutex);
      CloseHandle(hObject: this->m_hMutex);
      this->m_hMutex = nullptr;
    }
  }
  CValveIpcMgr::Shutdown(this);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x00401570
// Name: public: int CValveIpcClient::Connect(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CValveIpcClient::Connect(CValveIpcClient *this)
{
  const char **p_m_szServerUID; // esi
  HANDLE v3; // eax
  HANDLE FileA; // eax
  char chPipeName[260]; // [esp+8h] [ebp-218h] BYREF
  char chAliveName[260]; // [esp+10Ch] [ebp-114h] BYREF
  unsigned int dwPipeMode; // [esp+210h] [ebp-10h] BYREF
  CValveIpcMgr mgr; // [esp+214h] [ebp-Ch] BYREF

  p_m_szServerUID = (const char **)&this->m_szServerUID;
  if ( this->m_szServerUID != nullptr )
    return 1;
  memset(&mgr, 0, sizeof(mgr));
  if ( CValveIpcMgr::Init(this: &mgr, dwTimeout: 0x1388u) == 0
    || CValveIpcMgr::DiscoverServer(
         this: &mgr,
         szServerName: this->m_szServerName,
         pszServerUID: (unsigned __int8 **)p_m_szServerUID) == 0 )
  {
LABEL_6:
    CValveIpcMgr::~CValveIpcMgr(this: &mgr);
    return 0;
  }
  sprintf(string: chAliveName, format: "%s_ALIVE_1", *p_m_szServerUID);
  v3 = OpenMutexA(dwDesiredAccess: 0x1F0001u, bInheritHandle: false, lpName: chAliveName);
  if ( v3 == nullptr
    || (CloseHandle(hObject: v3),
        sprintf(string: chPipeName, format: "\\\\.\\pipe\\%s_PIPE_1", *p_m_szServerUID),
        FileA = CreateFileA(
                  lpFileName: chPipeName,
                  dwDesiredAccess: 0xC0000000,
                  dwShareMode: 0,
                  lpSecurityAttributes: nullptr,
                  dwCreationDisposition: 3u,
                  dwFlagsAndAttributes: 0x80000000,
                  hTemplateFile: nullptr),
        this->m_hClientPipe = FileA,
        FileA == nullptr) )
  {
    CValveIpcClient::Disconnect(this);
    goto LABEL_6;
  }
  dwPipeMode = 2;
  SetNamedPipeHandleState(
    hNamedPipe: FileA,
    lpMode: &dwPipeMode,
    lpMaxCollectionCount: nullptr,
    lpCollectDataTimeout: nullptr);
  CValveIpcMgr::~CValveIpcMgr(this: &mgr);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00401680
// Name: public: CValveIpcClientUtl::~CValveIpcClientUtl(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CValveIpcClientUtl::~CValveIpcClientUtl(CValveIpcClientUtl *this)
{
  unsigned __int8 **p_m_szServerUID; // edi

  p_m_szServerUID = &this->m_szServerUID;
  if ( this->m_szServerUID != nullptr )
  {
    if ( this->m_hClientPipe != nullptr )
    {
      CloseHandle(hObject: this->m_hClientPipe);
      this->m_hClientPipe = nullptr;
    }
    if ( *p_m_szServerUID != nullptr )
    {
      RpcStringFreeA(String: p_m_szServerUID);
      *p_m_szServerUID = nullptr;
    }
  }
  if ( this->m_szServerName != nullptr )
  {
    free(pMem: this->m_szServerName);
    this->m_szServerName = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004016D0
// Name: int OnEngineCommand(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl OnEngineCommand(const char *pszCommand)
{
  CUtlBuffer cmd; // [esp+8h] [ebp-70h] BYREF
  CUtlBuffer res; // [esp+38h] [ebp-40h] BYREF
  CValveIpcClientUtl ipc; // [esp+68h] [ebp-10h] BYREF
  unsigned int BytesRead; // [esp+74h] [ebp-4h] BYREF

  CValveIpcClient::CValveIpcClient(this: &ipc, szServerName: g_options.chServerName);
  _Msg(a1: "Connecting to \"%s\"... ", g_options.chServerName);
  if ( CValveIpcClient::Connect(this: &ipc) != 0 )
  {
    _Msg(a1: "ok.\n");
    CUtlBuffer::CUtlBuffer(this: &cmd, growSize: 0, initSize: 0, nFlags: 0);
    CUtlBuffer::CUtlBuffer(this: &res, growSize: 0, initSize: 0, nFlags: 0);
    CUtlBuffer::Put(this: &cmd, pMem: pszCommand, size: strlen(pszCommand) + 1);
    CUtlBuffer::EnsureCapacity(this: &res, num: 520);
    _Msg(a1: "Transmitting command... ");
    BytesRead = res.m_Memory.m_nAllocationCount;
    if ( ipc.m_szServerUID != nullptr
      && ipc.m_hClientPipe != nullptr
      && (TransactNamedPipe(
            hNamedPipe: ipc.m_hClientPipe,
            lpInBuffer: cmd.m_Memory.m_pMemory,
            nInBufferSize: cmd.m_Put,
            lpOutBuffer: res.m_Memory.m_pMemory,
            nOutBufferSize: res.m_Memory.m_nAllocationCount,
            lpBytesRead: &BytesRead,
            lpOverlapped: nullptr)
       || GetLastError() == 234) )
    {
      CUtlBuffer::SeekPut(this: &res, type: SEEK_HEAD, offset: BytesRead);
      _Msg(a1: "ok.\n\n");
      _Msg(a1: "%.*s", res.m_Put, (const char *)res.m_Memory.m_pMemory);
      _Msg(a1: "\n\n");
      if ( res.m_Memory.m_nGrowSize >= 0 )
      {
        if ( res.m_Memory.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: res.m_Memory.m_pMemory);
          res.m_Memory.m_pMemory = nullptr;
        }
        res.m_Memory.m_nAllocationCount = 0;
      }
      if ( cmd.m_Memory.m_nGrowSize >= 0 )
      {
        if ( cmd.m_Memory.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: cmd.m_Memory.m_pMemory);
          cmd.m_Memory.m_pMemory = nullptr;
        }
        cmd.m_Memory.m_nAllocationCount = 0;
      }
      CValveIpcClientUtl::~CValveIpcClientUtl(this: &ipc);
      return 0;
    }
    else
    {
      _Msg(a1: "Failed to transmit ipc command to server!\n");
      if ( res.m_Memory.m_nGrowSize >= 0 )
      {
        if ( res.m_Memory.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: res.m_Memory.m_pMemory);
          res.m_Memory.m_pMemory = nullptr;
        }
        res.m_Memory.m_nAllocationCount = 0;
      }
      if ( cmd.m_Memory.m_nGrowSize >= 0 )
      {
        if ( cmd.m_Memory.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: cmd.m_Memory.m_pMemory);
          cmd.m_Memory.m_pMemory = nullptr;
        }
        cmd.m_Memory.m_nAllocationCount = 0;
      }
      CValveIpcClientUtl::~CValveIpcClientUtl(this: &ipc);
      return 3;
    }
  }
  else
  {
    _Msg(a1: "IPC server is not available!\n");
    if ( ipc.m_szServerUID != nullptr )
    {
      if ( ipc.m_hClientPipe != nullptr )
      {
        CloseHandle(hObject: ipc.m_hClientPipe);
        ipc.m_hClientPipe = nullptr;
      }
      if ( ipc.m_szServerUID != nullptr )
      {
        RpcStringFreeA(String: &ipc.m_szServerUID);
        ipc.m_szServerUID = nullptr;
      }
    }
    if ( ipc.m_szServerName != nullptr )
      free(pMem: ipc.m_szServerName);
    return 2;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004018E0
// Name: _main
// Source: json
//------------------------------------------------------------------------------
int __cdecl main(int argc, const char **argv, const char **envp)
{
  unsigned __int8 *CommandLineA; // edi
  int v4; // eax
  int v5; // esi
  int v6; // eax
  const char *v7; // esi
  int v8; // eax
  int v10; // eax
  const char *v11; // [esp-4h] [ebp-10h]
  const char *pszParse; // [esp+8h] [ebp-4h] BYREF

  CommandLineA = (unsigned __int8 *)GetCommandLineA();
  strstr(str1: CommandLineA, str2: "--");
  v5 = v4;
  if ( v4 != 0 )
  {
    while ( 1 )
    {
      v6 = *(char *)(v5 + 2);
      v7 = (const char *)(v5 + 2);
      pszParse = v7;
      if ( isspace(c: v6) != 0 )
        break;
      if ( Option(&pszParse) == 0 )
      {
        _Msg(
          a1: "Error: Failed parsing command line at pos %d at \"%.*s\"\n",
          pszParse - (const char *)CommandLineA,
          10,
          pszParse);
        _Msg(a1: "\n");
        _Msg(a1: "  ipccomm [OPTIONS] [--svr SERVER_NAME] -- COMMANDS\n");
        _Msg(a1: "    OPTIONS:\n");
        _Msg(a1: "      --e or --engine  send command to engine.dll\n");
        _Msg(a1: "      --v or --hlmv    send command to hlmv.exe\n");
        _Msg(a1: "\n");
        return 1;
      }
      strstr(str1: (unsigned __int8 *)pszParse, str2: "--");
      v5 = v8;
      if ( v8 == 0 )
        goto LABEL_5;
    }
    while ( v7 != nullptr && *v7 != 0 )
    {
      v10 = *++v7;
      if ( isspace(c: v10) == 0 )
      {
        if ( *v7 == 0 )
          break;
        if ( (unsigned int)(g_options.cmdType - 1) <= 1 )
          return OnEngineCommand(pszCommand: v7);
        v11 = "Error: Failed to determine ipc command recipient type!\n";
        goto LABEL_6;
      }
    }
  }
LABEL_5:
  v11 = "Error: Empty command!\n";
LABEL_6:
  _Msg(a1: v11);
  _Msg(a1: "\n");
  _Msg(a1: "  ipccomm [OPTIONS] [--svr SERVER_NAME] -- COMMANDS\n");
  _Msg(a1: "    OPTIONS:\n");
  _Msg(a1: "      --e or --engine  send command to engine.dll\n");
  _Msg(a1: "      --v or --hlmv    send command to hlmv.exe\n");
  _Msg(a1: "\n");
  return 1;
}
