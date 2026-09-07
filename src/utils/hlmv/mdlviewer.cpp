// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/hlmv/mdlviewer.cpp
// Functions: 58
// ============================================================

#include "utils\hlmv\mdlviewer.h"

//------------------------------------------------------------------------------
// Address: 0x00401C70
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
    v9.m_szServerName = (char *)WindowName;
    v6 = &v9;
  }
  v7 = *(_DWORD *)&v6->m_uuid.Data4[4];
  *(_QWORD *)&result->m_szServerName = *(_QWORD *)&v6->m_szServerName;
  *(_QWORD *)&result->m_uuid.Data2 = *(_QWORD *)&v6->m_uuid.Data2;
  *(_DWORD *)&result->m_uuid.Data4[4] = v7;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00418150
// Name: bool StringHasPrefixCaseSensitive(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl StringHasPrefixCaseSensitive(const char *str, const char *prefix)
{
  return StringAfterPrefixCaseSensitive(str, prefix) != nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x00418170
// Name: public: virtual bool CTier3DmSteamApp::PreInit(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CTier3DmSteamApp::PreInit(CTier3DmSteamApp *this)
{
  void *(__cdecl *v1)(const char *, int *); // eax
  void *(__cdecl *factory)(const char *, int *); // [esp+0h] [ebp-8h] BYREF
  void *(__cdecl *pFactoryList)(const char *, int *); // [esp+4h] [ebp-4h] BYREF

  pFactoryList = CAppSystemGroup::GetFactory();
  ConnectTier1Libraries(&pFactoryList, nFactoryCount: 1);
  ConVar_Register(nCVarFlag: 0, pAccessor: nullptr);
  ConnectTier2Libraries(&pFactoryList, nFactoryCount: 1);
  v1 = CAppSystemGroup::GetFactory();
  if ( !ConnectDataModel(factory: v1) || InitDataModel() != INIT_OK )
    return 0;
  factory = CAppSystemGroup::GetFactory();
  CDmeFXClip::OnDestruction(pFactoryList: &factory, nFactoryCount: 1);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x004181E0
// Name: public: char __near * CValveIpcMgr::Iterator::WriteIntoMemory(char __near *)const
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CValveIpcMgr::Iterator::WriteIntoMemory(CValveIpcMgr::Iterator *this, char *pMemory)
{
  char *m_szServerName; // ecx
  unsigned int v4; // edi

  m_szServerName = this->m_szServerName;
  v4 = strlen(m_szServerName);
  memmove(dst: (unsigned __int8 *)pMemory, src: (unsigned __int8 *)m_szServerName, count: strlen(m_szServerName) + 1);
  memmove(dst: (unsigned __int8 *)&pMemory[v4 + 1], src: (unsigned __int8 *)&this->m_uuid, count: 0x10u);
  return &pMemory[v4 + 17];
}

//------------------------------------------------------------------------------
// Address: 0x00418240
// Name: public: int CValveIpcServer::IsRunning(void)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CValveIpcServer::IsRunning(CValveIpcServer *this)
{
  return this->m_hThread != nullptr && this->m_bRunning != 0;
}

//------------------------------------------------------------------------------
// Address: 0x00418260
// Name: public: int CValveIpcMgr::RegisterServer(char const __near *,unsigned char __near * __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CValveIpcMgr::RegisterServer(CValveIpcMgr *this, char *szServerName, unsigned __int8 **pszServerUID)
{
  char *v3; // esi
  unsigned int v5; // eax
  int v6; // ecx
  char *m_szServerName; // ebx
  unsigned int v8; // esi
  unsigned __int8 *v9; // esi
  HANDLE v11; // eax
  char chAliveName[260]; // [esp+8h] [ebp-140h] BYREF
  CValveIpcMgr::Iterator v13; // [esp+10Ch] [ebp-3Ch] BYREF
  CValveIpcMgr::Iterator itNewServer; // [esp+120h] [ebp-28h] BYREF
  CValveIpcMgr::Iterator it; // [esp+134h] [ebp-14h] BYREF

  v3 = szServerName;
  if ( szServerName == nullptr || *szServerName == 0 )
    return 0;
  CValveIpcMgr::Iterator::Iterator(this: &it, m_pMemory: this->m_pMemory);
  while ( 1 )
  {
    if ( it.m_szServerName == nullptr || *it.m_szServerName == 0 )
    {
LABEL_9:
      memset((void *)&itNewServer.m_uuid, 0, sizeof(itNewServer.m_uuid));
      itNewServer.m_szServerName = v3;
      UuidCreate(Uuid: &itNewServer.m_uuid);
      m_szServerName = it.m_szServerName;
      if ( &it.m_szServerName[strlen(v3) + 65] > this->m_pMemory + 0x40000 )
        return 0;
      v8 = strlen(itNewServer.m_szServerName);
      memmove(
        dst: (unsigned __int8 *)it.m_szServerName,
        src: (unsigned __int8 *)itNewServer.m_szServerName,
        count: strlen(itNewServer.m_szServerName) + 1);
      v9 = (unsigned __int8 *)&m_szServerName[v8 + 1];
      memmove(dst: v9, src: (unsigned __int8 *)&itNewServer.m_uuid, count: 0x10u);
      v9 += 16;
      memset((void *)&v13.m_uuid, 0, sizeof(v13.m_uuid));
      v13.m_szServerName = (char *)WindowName;
      memmove(dst: v9, src: (unsigned __int8 *)WindowName, count: 1u);
      memmove(dst: v9 + 1, src: (unsigned __int8 *)&v13.m_uuid, count: 0x10u);
      if ( pszServerUID != nullptr )
        UuidToStringA(Uuid: &itNewServer.m_uuid, StringUuid: pszServerUID);
      return 1;
    }
    v5 = 16;
    v6 = 0;
    while ( *(unsigned int *)((char *)&it.m_uuid.Data1 + v6) == *(unsigned int *)((char *)&GUID_NULL.Data1 + v6) )
    {
      v5 -= 4;
      v6 += 4;
      if ( v5 < 4 )
        goto LABEL_9;
    }
    if ( _V_stricmp(s1: v3, s2: it.m_szServerName) == 0 )
      break;
    it = *CValveIpcMgr::Iterator::Next(this: &it, result: &v13);
  }
  UuidToStringA(Uuid: &it.m_uuid, StringUuid: (RPC_CSTR *)&szServerName);
  sprintf(string: chAliveName, format: "%s_ALIVE_1", szServerName);
  RpcStringFreeA(String: (RPC_CSTR *)&szServerName);
  v11 = OpenMutexA(dwDesiredAccess: 0x1F0001u, bInheritHandle: false, lpName: chAliveName);
  if ( v11 == nullptr )
  {
    if ( pszServerUID != nullptr )
    {
      UuidToStringA(Uuid: &it.m_uuid, StringUuid: pszServerUID);
      return 1;
    }
    return 1;
  }
  CloseHandle(hObject: v11);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x00418480
// Name: public: int CValveIpcMgr::UnregisterServer(unsigned char __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CValveIpcMgr::UnregisterServer(CValveIpcMgr *this, unsigned __int8 *szServerUID)
{
  unsigned __int8 *m_szServerName; // ebx
  unsigned int v5; // eax
  int v6; // ecx
  unsigned int v7; // esi
  unsigned __int8 *v8; // esi
  CValveIpcMgr::Iterator itNext; // [esp+4h] [ebp-4Ch] BYREF
  CValveIpcMgr::Iterator itRemaining; // [esp+18h] [ebp-38h] BYREF
  CValveIpcMgr::Iterator it; // [esp+2Ch] [ebp-24h] BYREF
  _GUID uuid; // [esp+40h] [ebp-10h] BYREF

  if ( szServerUID == nullptr )
    return 0;
  if ( *szServerUID == 0 )
    return 0;
  if ( UuidFromStringA(StringUuid: szServerUID, Uuid: &uuid) != 0 )
    return 0;
  CValveIpcMgr::Iterator::Iterator(this: &it, m_pMemory: this->m_pMemory);
  if ( CValveIpcMgr::Iterator::IsValid(this: &it) == 0 )
    return 0;
  while ( UuidEqual(Uuid1: &it.m_uuid, Uuid2: &uuid, Status: (RPC_STATUS *)&szServerUID) == 0 )
  {
    it = *CValveIpcMgr::Iterator::Next(this: &it, result: &itNext);
    if ( CValveIpcMgr::Iterator::IsValid(this: &it) == 0 )
      return 0;
  }
  m_szServerName = (unsigned __int8 *)it.m_szServerName;
  CValveIpcMgr::Iterator::Next(this: &it, result: &itRemaining);
  while ( itRemaining.m_szServerName != nullptr && *itRemaining.m_szServerName != 0 )
  {
    v5 = 16;
    v6 = 0;
    while ( *(unsigned int *)((char *)&itRemaining.m_uuid.Data1 + v6) == *(unsigned int *)((char *)&GUID_NULL.Data1 + v6) )
    {
      v5 -= 4;
      v6 += 4;
      if ( v5 < 4 )
        goto LABEL_14;
    }
    CValveIpcMgr::Iterator::Next(this: &itRemaining, result: &itNext);
    v7 = strlen(itRemaining.m_szServerName);
    memmove(
      dst: m_szServerName,
      src: (unsigned __int8 *)itRemaining.m_szServerName,
      count: strlen(itRemaining.m_szServerName) + 1);
    v8 = &m_szServerName[v7 + 1];
    memmove(dst: v8, src: (unsigned __int8 *)&itRemaining.m_uuid, count: 0x10u);
    itRemaining = itNext;
    m_szServerName = v8 + 16;
  }
LABEL_14:
  memset((void *)&itNext.m_uuid, 0, sizeof(itNext.m_uuid));
  itNext.m_szServerName = (char *)WindowName;
  CValveIpcMgr::Iterator::WriteIntoMemory(this: &itNext, pMemory: (char *)m_szServerName);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x004185F0
// Name: public: void __near * CValveIpcMgr::DuplicateMemorySegmentHandle(void)
// Source: json
//------------------------------------------------------------------------------
void *__thiscall CValveIpcMgr::DuplicateMemorySegmentHandle(CValveIpcMgr *this)
{
  HANDLE v3; // eax
  void *m_hMemorySegment; // [esp-1Ch] [ebp-24h]
  HANDLE CurrentProcess; // [esp-18h] [ebp-20h]
  void *hDup; // [esp+4h] [ebp-4h] BYREF

  if ( this->m_hMemorySegment == nullptr )
    return nullptr;
  hDup = nullptr;
  CurrentProcess = GetCurrentProcess();
  m_hMemorySegment = this->m_hMemorySegment;
  v3 = GetCurrentProcess();
  DuplicateHandle(
    hSourceProcessHandle: v3,
    hSourceHandle: m_hMemorySegment,
    hTargetProcessHandle: CurrentProcess,
    lpTargetHandle: &hDup,
    dwDesiredAccess: 2u,
    bInheritHandle: false,
    dwOptions: 2u);
  return hDup;
}

//------------------------------------------------------------------------------
// Address: 0x00418640
// Name: public: CValveIpcServer::CValveIpcServer(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CValveIpcServer *__thiscall CValveIpcServer::CValveIpcServer(CValveIpcServer *this, const char *szServerName)
{
  unsigned int v3; // eax
  char *v4; // eax
  const char *v5; // ecx
  char *v6; // edx
  char v7; // al

  this->__vftable = (CValveIpcServer_vtbl *)&CValveIpcServer::`vftable';
  if ( szServerName != nullptr )
    v3 = strlen(szServerName);
  else
    v3 = 0;
  v4 = (char *)operator new(nSize: v3 + 1);
  this->m_szServerName = v4;
  v5 = szServerName;
  if ( szServerName == nullptr )
    v5 = WindowName;
  v6 = v4;
  do
  {
    v7 = *v5;
    *v6++ = *v5++;
  }
  while ( v7 != 0 );
  this->m_szServerUID = nullptr;
  this->m_hMemorySegment = nullptr;
  this->m_hServerAlive = nullptr;
  this->m_hServerPipe = nullptr;
  this->m_hPipeEvent = nullptr;
  this->m_hThread = nullptr;
  this->m_bRunning = 0;
  this->m_pBufferRead = nullptr;
  this->m_cbBufferRead = 0;
  this->m_pBufferWrite = nullptr;
  this->m_cbBufferWrite = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004186C0
// Name: protected: int CValveIpcServer::WaitForEvent(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CValveIpcServer::WaitForEvent(CValveIpcServer *this)
{
  DWORD v2; // eax

  if ( this->m_bRunning == 0 )
    return 0;
  while ( 1 )
  {
    v2 = WaitForSingleObject(hHandle: this->m_hPipeEvent, dwMilliseconds: 0x32u);
    if ( v2 == 0 || v2 == 128 )
      break;
    if ( v2 != 258 || this->m_bRunning == 0 )
      return 0;
  }
  ResetEvent(hEvent: this->m_hPipeEvent);
  return this->m_bRunning;
}

//------------------------------------------------------------------------------
// Address: 0x00418710
// Name: protected: int CValveIpcServer::WaitForClient(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CValveIpcServer::WaitForClient(CValveIpcServer *this)
{
  void *m_hPipeEvent; // eax
  DWORD LastError; // eax
  void *m_hServerPipe; // [esp-8h] [ebp-24h]
  _OVERLAPPED ov; // [esp+4h] [ebp-18h] BYREF
  unsigned int dwConnectDummy; // [esp+18h] [ebp-4h] BYREF

  m_hPipeEvent = this->m_hPipeEvent;
  m_hServerPipe = this->m_hServerPipe;
  memset(&ov, 0, 16);
  ov.hEvent = m_hPipeEvent;
  if ( ConnectNamedPipe(hNamedPipe: m_hServerPipe, lpOverlapped: &ov) )
    return false;
  LastError = GetLastError();
  if ( LastError == 535 )
  {
    SetEvent(hEvent: ov.hEvent);
    return true;
  }
  else
  {
    if ( LastError != 997 || CValveIpcServer::WaitForEvent(this) == 0 )
      return false;
    return GetOverlappedResult(
             hFile: this->m_hServerPipe,
             lpOverlapped: &ov,
             lpNumberOfBytesTransferred: &dwConnectDummy,
             bWait: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004187A0
// Name: protected: int CValveIpcServer::WaitForCommand(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CValveIpcServer::WaitForCommand(CValveIpcServer *this)
{
  char *m_pBufferRead; // edx
  unsigned int *p_m_cbBufferRead; // edi
  void *m_hServerPipe; // [esp-14h] [ebp-30h]
  _OVERLAPPED ov; // [esp+8h] [ebp-14h] BYREF

  m_pBufferRead = this->m_pBufferRead;
  p_m_cbBufferRead = &this->m_cbBufferRead;
  ov.hEvent = this->m_hPipeEvent;
  m_hServerPipe = this->m_hServerPipe;
  memset(&ov, 0, 16);
  this->m_cbBufferRead = 0;
  return (ReadFile(
            hFile: m_hServerPipe,
            lpBuffer: m_pBufferRead,
            nNumberOfBytesToRead: 0x10000u,
            lpNumberOfBytesRead: &this->m_cbBufferRead,
            lpOverlapped: &ov)
       || GetLastError() == 997
       && CValveIpcServer::WaitForEvent(this) != 0
       && GetOverlappedResult(
            hFile: this->m_hServerPipe,
            lpOverlapped: &ov,
            lpNumberOfBytesTransferred: &this->m_cbBufferRead,
            bWait: false))
      && *p_m_cbBufferRead != 0;
}

//------------------------------------------------------------------------------
// Address: 0x00418830
// Name: protected: int CValveIpcServer::WaitForResult(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CValveIpcServer::WaitForResult(CValveIpcServer *this)
{
  void *m_hPipeEvent; // eax
  char *m_pBufferWrite; // ecx
  void *m_hServerPipe; // edx
  DWORD m_cbBufferWrite; // [esp-Ch] [ebp-28h]
  _OVERLAPPED ov; // [esp+4h] [ebp-18h] BYREF
  unsigned int cbWrite; // [esp+18h] [ebp-4h] BYREF

  m_hPipeEvent = this->m_hPipeEvent;
  m_pBufferWrite = this->m_pBufferWrite;
  ov.hEvent = nullptr;
  m_hServerPipe = this->m_hServerPipe;
  ov.hEvent = m_hPipeEvent;
  m_cbBufferWrite = this->m_cbBufferWrite;
  memset(&ov, 0, 16);
  if ( WriteFile(
         hFile: m_hServerPipe,
         lpBuffer: m_pBufferWrite,
         nNumberOfBytesToWrite: m_cbBufferWrite,
         lpNumberOfBytesWritten: &cbWrite,
         lpOverlapped: &ov) )
  {
    if ( cbWrite == this->m_cbBufferWrite )
      return 1;
  }
  else if ( GetLastError() == 997
         && CValveIpcServer::WaitForEvent(this) != 0
         && GetOverlappedResult(
              hFile: this->m_hServerPipe,
              lpOverlapped: &ov,
              lpNumberOfBytesTransferred: &cbWrite,
              bWait: false)
         && cbWrite == this->m_cbBufferWrite )
  {
    return 1;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x004188D0
// Name: public: unsigned long CValveIpcServer::RunImpl(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CValveIpcServer::RunImpl(CValveIpcServer *this)
{
  unsigned int *p_m_cbBufferWrite; // edi
  int (__thiscall *ExecuteCommand)(CValveIpcServer *, char *, unsigned int, char *, unsigned int *); // edx
  char *m_pBufferRead; // [esp-18h] [ebp-1Ch]
  unsigned int m_cbBufferRead; // [esp-14h] [ebp-18h]
  char *m_pBufferWrite; // [esp-10h] [ebp-14h]

  while ( CValveIpcServer::WaitForClient(this) )
  {
    if ( CValveIpcServer::WaitForCommand(this) )
    {
      p_m_cbBufferWrite = &this->m_cbBufferWrite;
      do
      {
        m_pBufferWrite = this->m_pBufferWrite;
        m_cbBufferRead = this->m_cbBufferRead;
        ExecuteCommand = this->ExecuteCommand;
        m_pBufferRead = this->m_pBufferRead;
        *p_m_cbBufferWrite = 0;
      }
      while ( ExecuteCommand(
                this,
                a2: m_pBufferRead,
                a3: m_cbBufferRead,
                a4: m_pBufferWrite,
                a5: &this->m_cbBufferWrite) != 0
           && *p_m_cbBufferWrite != 0
           && CValveIpcServer::WaitForResult(this) != 0
           && CValveIpcServer::WaitForCommand(this) );
    }
    DisconnectNamedPipe(hNamedPipe: this->m_hServerPipe);
  }
  this->m_bRunning = 0;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x00418950
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
    v5 = WindowName;
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
// Address: 0x004189B0
// Name: void LoadFileSystemDialogModule(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl LoadFileSystemDialogModule()
{
  struct CSysModule *Module; // eax
  void *(__cdecl *Factory)(const char *, int *); // eax

  Module = Sys_LoadModule(pModuleName: "FileSystemOpenDialog.dll");
  g_pFSDialogModule = Module;
  if ( Module != nullptr )
  {
    Factory = Sys_GetFactory(pModule: Module);
    g_FSDialogFactory = Factory;
    if ( g_pFSDialogModule != nullptr && Factory == nullptr )
    {
      Sys_UnloadModule(pModule: g_pFSDialogModule);
      g_pFSDialogModule = nullptr;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00418A00
// Name: private: void MDLViewer::initRecentFiles(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall MDLViewer::initRecentFiles(MDLViewer *this)
{
  int v2; // esi
  const char *v3; // edi
  unsigned int v4; // kr00_4
  mxMenuBar *mb; // ecx
  int i; // [esp+10h] [ebp-4h]

  v2 = 1008;
  v3 = recentFiles[0];
  for ( i = 8; i != 0; --i )
  {
    v4 = strlen(v3);
    mb = this->mb;
    if ( v4 != 0 )
    {
      mxMenuBar::modify(this: mb, id: v2, newId: v2, newItem: v3);
    }
    else
    {
      mxMenuBar::modify(this: mb, id: v2, newId: v2, newItem: "(empty)");
      mxMenu::setEnabled(this: this->mb, id: v2, b: false);
    }
    v3 += 256;
    ++v2;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00418A70
// Name: private: void MDLViewer::loadRecentFiles(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall MDLViewer::loadRecentFiles(MDLViewer *this)
{
  char *ApplicationPath; // eax
  char *v2; // edx
  char v3; // cl
  char *v4; // eax
  char v5; // cl
  _iobuf *v6; // eax
  _iobuf *v7; // esi
  char v8; // [esp-1h] [ebp-101h] BYREF
  char path[256]; // [esp+0h] [ebp-100h] BYREF

  ApplicationPath = (char *)mx::getApplicationPath();
  v2 = (char *)(path - ApplicationPath);
  do
  {
    v3 = *ApplicationPath;
    ApplicationPath[(_DWORD)v2] = *ApplicationPath;
    ++ApplicationPath;
  }
  while ( v3 != 0 );
  v4 = &v8;
  do
    v5 = *++v4;
  while ( v5 != 0 );
  strcpy(v4, "/hlmv.rf");
  v6 = fopen(file: path, mode: "rb");
  v7 = v6;
  if ( v6 != nullptr )
  {
    fread(buffer: recentFiles, elementSize: 0x800u, count: 1u, stream: v6);
    fclose(stream: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00418B00
// Name: private: void MDLViewer::saveRecentFiles(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall MDLViewer::saveRecentFiles(MDLViewer *this)
{
  char *ApplicationPath; // eax
  char *v2; // edx
  char v3; // cl
  char *v4; // eax
  char v5; // cl
  _iobuf *v6; // eax
  _iobuf *v7; // esi
  char v8; // [esp-1h] [ebp-101h] BYREF
  char path[256]; // [esp+0h] [ebp-100h] BYREF

  ApplicationPath = (char *)mx::getApplicationPath();
  v2 = (char *)(path - ApplicationPath);
  do
  {
    v3 = *ApplicationPath;
    ApplicationPath[(_DWORD)v2] = *ApplicationPath;
    ++ApplicationPath;
  }
  while ( v3 != 0 );
  v4 = &v8;
  do
    v5 = *++v4;
  while ( v5 != 0 );
  strcpy(v4, "/hlmv.rf");
  v6 = fopen(file: path, mode: "wb");
  v7 = v6;
  if ( v6 != nullptr )
  {
    fwrite(buffer: recentFiles, size: 0x800u, count: 1u, stream: v6);
    fclose(stream: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00418B90
// Name: public: void MDLViewer::Refresh(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall MDLViewer::Refresh(MDLViewer *this)
{
  int v2; // eax
  char v3; // cl
  char szFile[260]; // [esp+4h] [ebp-104h] BYREF

  StudioModel::ReleaseStudioModel();
  g_pMDLCache->Flush_2(this: g_pMDLCache, a2: MDLCACHE_FLUSH_ALL);
  if ( recentFiles[0][0] != 0 )
  {
    v2 = 0;
    do
    {
      v3 = recentFiles[0][v2];
      szFile[v2++] = v3;
    }
    while ( v3 != 0 );
    g_pMaterialSystem->ReloadMaterials(this: g_pMaterialSystem, a2: nullptr);
    ControlPanel::loadModel(this: this->d_cpl, filename: szFile);
  }
  if ( (_S1_0 & 1) == 0 )
  {
    _S1_0 |= 1u;
    ConVarRef::ConVarRef(this: &mat_flushshaders_async, pName: "mat_flushshaders_async");
  }
  mat_flushshaders_async.m_pConVar->SetValue_2(this: mat_flushshaders_async.m_pConVar, a2: 1);
}

//------------------------------------------------------------------------------
// Address: 0x00418C30
// Name: public: void MDLViewer::LoadModelFile(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall MDLViewer::LoadModelFile(MDLViewer *this, const char *pszFile, unsigned int slot)
{
  int Model; // eax
  int v5; // eax
  int v6; // eax
  int v7; // esi
  const char *v8; // edi
  CDmeAnimCmd **v9; // edi
  CDmeAnimCmd **v10; // eax
  char v11; // cl
  int v12; // eax
  char v13; // cl
  char filename[1024]; // [esp+Ch] [ebp-400h] BYREF

  strcpy(filename, pszFile);
  Model = ControlPanel::loadModel(this: this->d_cpl, filename, slot);
  if ( Model != 0 )
  {
    v5 = Model - 1;
    if ( v5 != 0 )
    {
      v6 = v5 - 1;
      if ( v6 != 0 )
      {
        if ( v6 == 1 )
          mxMessageBox(parent: this, msg: "Error post-loading model.", title: g_appTitle, style: 8);
      }
      else
      {
        mxMessageBox(parent: this, msg: "Error loading model. The model has no vertices.", title: g_appTitle, style: 8);
      }
    }
    else
    {
      mxMessageBox(parent: this, msg: "Error loading model.", title: g_appTitle, style: 8);
    }
    return;
  }
  if ( slot != -1 )
  {
    v7 = slot + 1414;
    mxMenuBar::modify(this: this->mb, id: v7, newId: v7, newItem: pszFile);
    mxMenu::setEnabled(this: this->mb, id: slot + 1414, b: true);
    goto LABEL_23;
  }
  v7 = 0;
  v8 = recentFiles[0];
  do
  {
    if ( mx_strcasecmp(s1: v8, s2: filename) == 0 )
      break;
    v8 += 256;
    ++v7;
  }
  while ( (int)v8 < (int)&g_pFSDialogModule );
  if ( v7 > 7 )
  {
    v7 = 7;
    goto LABEL_15;
  }
  if ( v7 > 0 )
  {
LABEL_15:
    v9 = &g_CDmeAnimCmdPullInModule + 64 * v7;
    do
    {
      v10 = v9;
      do
      {
        v11 = *(_BYTE *)v10;
        *((_BYTE *)v10 + 256) = *(_BYTE *)v10;
        v10 = (CDmeAnimCmd **)((char *)v10 + 1);
      }
      while ( v11 != 0 );
      --v7;
      v9 -= 64;
    }
    while ( v7 > 0 );
  }
  v12 = 0;
  do
  {
    v13 = filename[v12];
    recentFiles[0][v12++] = v13;
  }
  while ( v13 != 0 );
  MDLViewer::initRecentFiles(this);
  mxWidget::setLabel(this, format: "%s", filename);
LABEL_23:
  if ( g_viewerSettings.dotaMode )
    ControlPanel::dotaView(this: this->d_cpl, a2: v7);
}

//------------------------------------------------------------------------------
// Address: 0x00418DC0
// Name: public: void MDLViewer::SaveScreenShot(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall MDLViewer::SaveScreenShot(MDLViewer *this, const char *pszFile)
{
  int Model; // eax
  char v4; // cl
  char *v5; // eax
  char v6; // cl
  char filename[1024]; // [esp+4h] [ebp-500h] BYREF
  char szScreenShot[256]; // [esp+404h] [ebp-100h] BYREF

  strcpy(filename, pszFile);
  Model = ControlPanel::loadModel(this: this->d_cpl, filename);
  if ( Model == 0 )
  {
    g_viewerSettings.bgColor[0] = 0.45882353;
    g_viewerSettings.bgColor[1] = 0.76862746;
    g_viewerSettings.bgColor[2] = 0.85882354;
    do
    {
      v4 = filename[Model];
      szScreenShot[Model++] = v4;
    }
    while ( v4 != 0 );
    strrchr(string: (unsigned __int8 *)szScreenShot, chr: 0x2Eu);
    if ( v5 == nullptr )
    {
      v5 = &filename[1023];
      do
        v6 = *++v5;
      while ( v6 != 0 );
    }
    strcpy(v5, ".tga");
    ControlPanel::centerView(this: this->d_cpl);
    MatSysWindow::dumpViewport(this: this->d_MatSysWindow, filename: szScreenShot);
  }
  mx::quit();
}

//------------------------------------------------------------------------------
// Address: 0x00418EA0
// Name: public: void MDLViewer::DumpText(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall MDLViewer::DumpText(MDLViewer *this, const char *pszFile)
{
  char filename[1024]; // [esp+4h] [ebp-400h] BYREF

  strcpy(filename, pszFile);
  if ( ControlPanel::loadModel(this: this->d_cpl, filename) == 0 )
  {
    if ( g_pStudioModel->m_bIsTransparent )
      _Msg(a1: "%s is transparent\n", filename);
    if ( g_pStudioModel->m_bHasProxy )
      _Msg(a1: "%s has material proxies\n", filename);
  }
  mx::quit();
}

//------------------------------------------------------------------------------
// Address: 0x00418F30
// Name: private: char const __near * MDLViewer::SteamGetOpenFilename(void)
// Source: json
//------------------------------------------------------------------------------
// bad sp value at call has been detected, the output may be wrong!
char *__usercall MDLViewer::SteamGetOpenFilename@<eax>(MDLViewer *this@<ecx>, int a2@<esi>)
{
  char *result; // eax
  int *v3; // esi
  bool v4; // zf
  int v5; // eax
  char str[512]; // [esp+0h] [ebp-200h] BYREF

  result = (char *)g_FSDialogFactory;
  if ( g_FSDialogFactory != nullptr )
  {
    v3 = (int *)g_FSDialogFactory(a1: "FileSystemOpenDlg003", a2: nullptr);
    if ( v3 != nullptr )
    {
      (*(void (__thiscall **)(int *, void *(__cdecl *)(const char *, int *), _DWORD, int))*v3)(
        a1: v3,
        a2: g_Factory,
        a3: 0,
        a4: a2);
      (*(void (__thiscall **)(int *, const char *))(*v3 + 8))(a1: v3, a2: "*.jpg");
      (*(void (__thiscall **)(int *, const char *))(*v3 + 8))(a1: v3, a2: "*.mdl");
      (*(void (__thiscall **)(int *, const char *, const char *))(*v3 + 12))(a1: v3, a2: "models", a3: "game");
      (*(void (__thiscall **)(int *, int))(*v3 + 16))(a1: v3, a2: 1);
      v4 = (*(unsigned __int8 (__thiscall **)(int *))(*v3 + 24))(a1: v3) == 1;
      v5 = *v3;
      if ( v4 )
      {
        (*(void (__thiscall **)(int *, char *))(v5 + 20))(a1: v3, a2: filename);
        (*(void (__thiscall **)(int *))(*v3 + 4))(a1: v3);
        return filename;
      }
      else
      {
        (*(void (__thiscall **)(int *))(v5 + 4))(a1: v3);
        return nullptr;
      }
    }
    else
    {
      V_snprintf(pDest: str, maxLen: 512, pFormat: "Can't create %s interface.", "FileSystemOpenDlg003");
      MessageBoxA(hWnd: nullptr, lpText: str, lpCaption: "Error", uType: 0);
      return nullptr;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00419020
// Name: public: int MDLViewer::GetCurrentHitboxSet(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall MDLViewer::GetCurrentHitboxSet(MDLViewer *this)
{
  ControlPanel *d_cpl; // ecx

  d_cpl = this->d_cpl;
  if ( d_cpl != nullptr )
    return ControlPanel::GetCurrentHitboxSet(this: d_cpl);
  else
    return 0;
}

//------------------------------------------------------------------------------
// Address: 0x00419030
// Name: public: virtual void CSimpleWindowsLoggingListener::Log(struct LoggingContext_t const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSimpleWindowsLoggingListener::Log(
        CSimpleWindowsLoggingListener *this,
        const LoggingContext_t *pContext,
        const char *pMessage)
{
  int v3; // ecx

  if ( (unsigned __int8)_Plat_IsInDebugSession(a1: this) != 0 )
    _Plat_DebugString(a1: pMessage);
  if ( pContext->m_Severity == LS_ERROR )
  {
    if ( (unsigned __int8)_Plat_IsInDebugSession(a1: v3) != 0 )
      __debugbreak();
    _Plat_MessageBox(a1: "Error", a2: pMessage);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00419080
// Name: public: virtual bool CHLModelViewerApp::Create(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CHLModelViewerApp::Create(CHLModelViewerApp *this)
{
  int v2; // eax
  int v3; // eax
  int v4; // eax
  int Module; // eax
  void *System; // esi
  int v8; // eax
  int v9; // eax
  AppSystemInfo_t appSystems[9]; // [esp+8h] [ebp-4Ch] BYREF
  const char *pArg; // [esp+50h] [ebp-4h] BYREF

  _LoggingSystem_PushLoggingState(a1: 0, a2: 1);
  _LoggingSystem_RegisterLoggingListener(a1: &s_SimpleWindowsLoggingListener);
  v2 = _CommandLine();
  g_dxlevel = (*(int (__thiscall **)(int, const char *, _DWORD))(*(_DWORD *)v2 + 28))(a1: v2, a2: "-dx", a3: 0);
  v3 = _CommandLine();
  v4 = (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v3 + 40))(a1: v3, a2: "-olddialogs");
  appSystems[3].m_pModuleName = "datacache.dll";
  appSystems[4].m_pModuleName = "datacache.dll";
  appSystems[5].m_pModuleName = "datacache.dll";
  g_bOldFileDialogs = v4 != 0;
  appSystems[0].m_pModuleName = "materialsystem.dll";
  appSystems[0].m_pInterfaceName = "VMaterialSystem080";
  appSystems[1].m_pModuleName = "studiorender.dll";
  appSystems[1].m_pInterfaceName = "VStudioRender026";
  appSystems[2].m_pModuleName = "vphysics.dll";
  appSystems[2].m_pInterfaceName = "VPhysics031";
  appSystems[3].m_pInterfaceName = "VDataCache003";
  appSystems[4].m_pInterfaceName = "MDLCache004";
  appSystems[5].m_pInterfaceName = "VStudioDataCache005";
  appSystems[6].m_pModuleName = "soundemittersystem.dll";
  appSystems[6].m_pInterfaceName = "VSoundEmitter003";
  appSystems[7].m_pModuleName = "soundsystem.dll";
  appSystems[7].m_pInterfaceName = "SoundSystem001";
  appSystems[8].m_pModuleName = WindowName;
  appSystems[8].m_pInterfaceName = WindowName;
  if ( !CAppSystemGroup::AddSystems(this, pSystemList: appSystems) )
    return 0;
  CAppSystemGroup::AddSystem(
    this,
    pAppSystem: (IAppSystem *)g_pDataModel.u.m_Id,
    pInterfaceName: "VDataModelVersion001");
  CAppSystemGroup::AddSystem(this, pAppSystem: g_pDmSerializers, pInterfaceName: "VDmSerializers001");
  Module = CAppSystemGroup::LoadModule(this, pDLLName: "p4lib.dll");
  CAppSystemGroup::AddSystem(this, module: Module, pInterfaceName: "VP4002");
  g_pFileSystem = (IFileSystem *)CAppSystemGroup::FindSystem(this, pSystemName: "VFileSystem017");
  g_pStudioDataCache = (IStudioDataCache *)CAppSystemGroup::FindSystem(this, pSystemName: "VStudioDataCache005");
  physcollision = (IPhysicsCollision *)CAppSystemGroup::FindSystem(this, pSystemName: "VPhysicsCollision007");
  physprop = (IPhysicsSurfaceProps *)CAppSystemGroup::FindSystem(this, pSystemName: "VPhysicsSurfaceProps001");
  g_pSoundEmitterBase = (ISoundEmitterSystemBase *)CAppSystemGroup::FindSystem(this, pSystemName: "VSoundEmitter003");
  g_pSoundSystem = (ISoundSystem *)CAppSystemGroup::FindSystem(this, pSystemName: "SoundSystem001");
  System = CAppSystemGroup::FindSystem(this, pSystemName: "VMaterialSystem080");
  if ( System == nullptr )
  {
    _Error(a1: "Unable to connect to necessary interface!\n");
    return 0;
  }
  v8 = _CommandLine();
  (*(void (__thiscall **)(int, const char *, _DWORD))(*(_DWORD *)v8 + 32))(a1: v8, a2: "-shaderdll", a3: 0);
  v9 = _CommandLine();
  (*(void (__thiscall **)(int, const char *, const char **))(*(_DWORD *)v9 + 12))(a1: v9, a2: "-shaderapi", a3: &pArg);
  (*(void (__thiscall **)(void *))(*(_DWORD *)System + 36))(a1: System);
  g_Factory = CAppSystemGroup::GetFactory();
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00419290
// Name: public: virtual void CHLModelViewerApp::Destroy(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHLModelViewerApp::Destroy(CHLModelViewerApp *this)
{
  _LoggingSystem_PopLoggingState(a1: 0);
  g_pFileSystem = nullptr;
  g_pStudioDataCache = nullptr;
  physcollision = nullptr;
  physprop = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x004192C0
// Name: public: virtual bool CHLModelViewerApp::PreInit(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CHLModelViewerApp::PreInit(CHLModelViewerApp *this)
{
  int v3; // ebx
  int v4; // eax
  int v5; // esi
  int v6; // eax
  int v7; // eax
  const char *pAdapterString; // [esp+24h] [ebp-4h] BYREF

  if ( CTier3DmSteamApp::PreInit(this) == 0 )
    return 0;
  if ( g_pFileSystem == nullptr
    || physprop == nullptr
    || physcollision == nullptr
    || g_pMaterialSystem == nullptr
    || g_pStudioRender == nullptr
    || g_pMDLCache == nullptr
    || g_pDataCache == nullptr )
  {
    _Error(a1: "Unable to load required library interface!\n");
  }
  MathLib_Init(
    gamma: 2.2,
    texGamma: 2.2,
    brightness: 0.0,
    overbright: 2,
    bAllow3DNow: false,
    bAllowSSE: false,
    bAllowSSE2: false,
    bAllowMMX: false);
  if ( !CSteamAppSystemGroup::SetupSearchPaths(this, pStartingDir: nullptr, bOnlyUseStartingDir: false, bIsTool: true) )
    return 0;
  v3 = 0;
  v4 = _CommandLine();
  if ( (*(int (__thiscall **)(int, const char *, const char **))(*(_DWORD *)v4 + 12))(
         a1: v4,
         a2: "-adapter",
         a3: &pAdapterString) != 0 )
    v3 = atoi(nptr: pAdapterString);
  v5 = 0;
  v6 = _CommandLine();
  if ( (*(int (__thiscall **)(int, const char *, _DWORD))(*(_DWORD *)v6 + 12))(a1: v6, a2: "-ref", a3: 0) != 0 )
    v5 = 4;
  g_pMaterialSystem->SetAdapter(this: g_pMaterialSystem, a2: v3, a3: v5);
  if ( !g_pFileSystem->IsSteam(this: g_pFileSystem)
    || (v7 = _CommandLine(),
        (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v7 + 40))(a1: v7, a2: "-OldDialogs") != 0) )
  {
    g_bOldFileDialogs = true;
  }
  LoadFileSystemDialogModule();
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00419400
// Name: public: virtual void CHLModelViewerApp::PostShutdown(void)
// Source: json
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x00419440
// Name: CHLModelViewerApp_SuggestGameInfoDirFn
// Source: json
//------------------------------------------------------------------------------
char __cdecl CHLModelViewerApp_SuggestGameInfoDirFn(
        const CFSSteamSetupInfo *pFsSteamSetupInfo,
        char *pchPathBuffer,
        int nBufferLength,
        bool *pbBubbleDirectories)
{
  int v4; // eax
  int v5; // esi
  int v6; // eax
  const char *v7; // eax
  const char *v8; // esi

  v4 = _CommandLine();
  v5 = (*(int (__thiscall **)(int))(*(_DWORD *)v4 + 36))(a1: v4);
  if ( v5 <= 1 )
    return 0;
  v6 = _CommandLine();
  v7 = (const char *)(*(int (__thiscall **)(int, int))(*(_DWORD *)v6 + 44))(a1: v6, a2: v5 - 1);
  v8 = v7;
  if ( v7 == nullptr || V_stristr(pStr: v7, pSearch: ".mdl") == nullptr )
    return 0;
  V_MakeAbsolutePath(pOut: pchPathBuffer, outLen: nBufferLength, pPath: v8, pStartingDir: nullptr);
  if ( pbBubbleDirectories != nullptr )
    *pbBubbleDirectories = true;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x004194B0
// Name: public: int CValveIpcServer::Unregister(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CValveIpcServer::Unregister(CValveIpcServer *this)
{
  unsigned __int8 **p_m_szServerUID; // ebx
  void *m_hThread; // eax
  void *m_hServerPipe; // eax
  RPC_CSTR *v6; // esi
  char *m_pBufferWrite; // [esp-8h] [ebp-24h]
  char *m_pBufferRead; // [esp-4h] [ebp-20h]
  CValveIpcMgr mgr; // [esp+Ch] [ebp-10h] BYREF
  RPC_CSTR *String; // [esp+18h] [ebp-4h]

  p_m_szServerUID = &this->m_szServerUID;
  String = &this->m_szServerUID;
  if ( this->m_szServerUID == nullptr )
    return 0;
  memset(&mgr, 0, sizeof(mgr));
  if ( CValveIpcMgr::Init(this: &mgr, dwTimeout: 0x1388u) != 0 )
    CValveIpcMgr::UnregisterServer(this: &mgr, szServerUID: *p_m_szServerUID);
  if ( mgr.m_pMemory != nullptr )
    UnmapViewOfFile(lpBaseAddress: mgr.m_pMemory);
  if ( mgr.m_hMemorySegment != nullptr )
    CloseHandle(hObject: mgr.m_hMemorySegment);
  if ( mgr.m_hMutex != nullptr )
  {
    ReleaseMutex(hMutex: mgr.m_hMutex);
    CloseHandle(hObject: mgr.m_hMutex);
  }
  m_hThread = this->m_hThread;
  if ( m_hThread != nullptr )
  {
    this->m_bRunning = 0;
    WaitForSingleObject(hHandle: m_hThread, dwMilliseconds: 0xFFFFFFFF);
    CloseHandle(hObject: this->m_hThread);
    this->m_hThread = nullptr;
  }
  m_pBufferRead = this->m_pBufferRead;
  this->m_cbBufferRead = 0;
  free(pMem: m_pBufferRead);
  m_pBufferWrite = this->m_pBufferWrite;
  this->m_pBufferRead = nullptr;
  this->m_cbBufferWrite = 0;
  free(pMem: m_pBufferWrite);
  m_hServerPipe = this->m_hServerPipe;
  this->m_pBufferWrite = nullptr;
  if ( m_hServerPipe != nullptr )
  {
    CloseHandle(hObject: m_hServerPipe);
    this->m_hServerPipe = nullptr;
  }
  if ( this->m_hPipeEvent != nullptr )
  {
    CloseHandle(hObject: this->m_hPipeEvent);
    this->m_hPipeEvent = nullptr;
  }
  if ( this->m_hServerAlive != nullptr )
  {
    CloseHandle(hObject: this->m_hServerAlive);
    this->m_hServerAlive = nullptr;
  }
  if ( this->m_hMemorySegment != nullptr )
  {
    CloseHandle(hObject: this->m_hMemorySegment);
    this->m_hMemorySegment = nullptr;
  }
  v6 = String;
  if ( *String != nullptr )
  {
    RpcStringFreeA(String);
    *v6 = nullptr;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x004195C0
// Name: public: static unsigned long CValveIpcServer::RunDelegate(void __near *)
// Source: json
//------------------------------------------------------------------------------
unsigned int __stdcall CValveIpcServer::RunDelegate(CValveIpcServer *lpvParam)
{
  return CValveIpcServer::RunImpl(this: lpvParam);
}

//------------------------------------------------------------------------------
// Address: 0x004195D0
// Name: public: bool CHlmvIpcServer::HasCommands(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CHlmvIpcServer::HasCommands(CHlmvIpcServer *this)
{
  CThreadFastMutex *p_m_mtx; // esi
  DWORD CurrentThreadId; // ecx
  bool result; // al

  p_m_mtx = &this->m_mtx;
  CurrentThreadId = GetCurrentThreadId();
  if ( CurrentThreadId != p_m_mtx->m_ownerID
    && _InterlockedCompareExchange((volatile signed __int32 *)p_m_mtx, CurrentThreadId, 0) != 0 )
  {
    _mm_pause();
    CThreadFastMutex::Lock(a1: p_m_mtx, a2: CurrentThreadId, a3: 0);
  }
  else
  {
    ++p_m_mtx->m_depth;
  }
  result = this->m_lstCommands.m_Size > 0;
  if ( p_m_mtx->m_depth-- == 1 )
    _InterlockedExchange((volatile __int32 *)p_m_mtx, 0);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00419630
// Name: public: void CByteswap::SwapBufferToTargetEndian<int>(int __near *,int __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapBufferToTargetEndian<int>(
        CByteswap *this,
        int *outputBuffer,
        int *inputBuffer,
        int count)
{
  int v4; // ebx
  int *v5; // edi
  int *v6; // eax
  char *v7; // esi
  char v8; // cl
  char v9; // dl
  char v10; // al
  char v11; // cl

  v4 = count;
  if ( count > 0 )
  {
    v5 = outputBuffer;
    if ( outputBuffer != nullptr )
    {
      v6 = inputBuffer;
      if ( inputBuffer == nullptr )
        v6 = outputBuffer;
      if ( (*(_BYTE *)this & 1) != 0 )
      {
        v7 = (char *)v6 + 2;
        do
        {
          v8 = v7[1];
          v9 = *v7;
          count = *v5;
          v10 = *(v7 - 1);
          BYTE1(count) = v9;
          LOBYTE(count) = v8;
          v11 = *(v7 - 2);
          BYTE2(count) = v10;
          HIBYTE(count) = v11;
          _V_memcpy(dest: v5++, src: &count, count: 4);
          v7 += 4;
          --v4;
        }
        while ( v4 != 0 );
      }
      else if ( v6 != nullptr && outputBuffer != v6 )
      {
        memcpy(dst: (unsigned __int8 *)outputBuffer, src: (unsigned __int8 *)v6, count: 4 * count);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004196C0
// Name: public: void CUtlMemory<struct mx::Accel_t,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<mx::Accel_t,int>::Grow(CUtlMemory<tagACCEL,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  tagACCEL *m_pMemory; // edx
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
        m_nAllocationCount = 6;
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
    v7 = 6 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (tagACCEL *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (tagACCEL *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00419760
// Name: public: int CValveIpcServer::Register(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CValveIpcServer::Register(CValveIpcServer *this)
{
  unsigned __int8 **p_m_szServerUID; // edi
  void *v3; // eax
  HANDLE MutexA; // eax
  HANDLE EventA; // eax
  HANDLE NamedPipeA; // eax
  char *v8; // eax
  char *v9; // eax
  unsigned __int8 *v10; // [esp-4h] [ebp-220h]
  char chPipeName[260]; // [esp+8h] [ebp-214h] BYREF
  char chAliveName[260]; // [esp+10Ch] [ebp-110h] BYREF
  CValveIpcMgr mgr; // [esp+210h] [ebp-Ch] BYREF

  p_m_szServerUID = &this->m_szServerUID;
  if ( this->m_szServerUID != nullptr )
    return 1;
  memset(&mgr, 0, sizeof(mgr));
  if ( CValveIpcMgr::Init(this: &mgr, dwTimeout: 0x1388u) == 0
    || CValveIpcMgr::RegisterServer(this: &mgr, szServerName: this->m_szServerName, pszServerUID: p_m_szServerUID) == 0 )
  {
LABEL_6:
    CValveIpcMgr::~CValveIpcMgr(this: &mgr);
    return 0;
  }
  v3 = CValveIpcMgr::DuplicateMemorySegmentHandle(this: &mgr);
  v10 = *p_m_szServerUID;
  this->m_hMemorySegment = v3;
  sprintf(string: chAliveName, format: "%s_ALIVE_1", (const char *)v10);
  MutexA = CreateMutexA(lpMutexAttributes: nullptr, bInitialOwner: false, lpName: chAliveName);
  this->m_hServerAlive = MutexA;
  if ( MutexA != nullptr )
  {
    EventA = CreateEventA(lpEventAttributes: nullptr, bManualReset: true, bInitialState: false, lpName: nullptr);
    this->m_hPipeEvent = EventA;
    if ( EventA != nullptr )
    {
      sprintf(string: chPipeName, format: "\\\\.\\pipe\\%s_PIPE_1", (const char *)*p_m_szServerUID);
      NamedPipeA = CreateNamedPipeA(
                     lpName: chPipeName,
                     dwOpenMode: 0xC0000003,
                     dwPipeMode: 6u,
                     nMaxInstances: 1u,
                     nOutBufferSize: 0x10000u,
                     nInBufferSize: 0x10000u,
                     nDefaultTimeOut: 0x1388u,
                     lpSecurityAttributes: nullptr);
      this->m_hServerPipe = NamedPipeA;
      if ( NamedPipeA != nullptr )
      {
        v8 = (char *)operator new(nSize: 0x10000u);
        this->m_pBufferRead = v8;
        if ( v8 != nullptr )
        {
          v9 = (char *)operator new(nSize: 0x10000u);
          this->m_pBufferWrite = v9;
          if ( v9 != nullptr )
          {
            CValveIpcMgr::~CValveIpcMgr(this: &mgr);
            return 1;
          }
        }
      }
    }
  }
  CValveIpcServer::Unregister(this);
  goto LABEL_6;
}

//------------------------------------------------------------------------------
// Address: 0x004198A0
// Name: public: char __near * CHlmvIpcServer::GetCommand(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CHlmvIpcServer::GetCommand(CHlmvIpcServer *this)
{
  CThreadFastMutex *p_m_mtx; // esi
  DWORD CurrentThreadId; // ecx
  char *result; // eax

  p_m_mtx = &this->m_mtx;
  CurrentThreadId = GetCurrentThreadId();
  if ( CurrentThreadId != p_m_mtx->m_ownerID
    && _InterlockedCompareExchange((volatile signed __int32 *)p_m_mtx, CurrentThreadId, 0) != 0 )
  {
    _mm_pause();
    CThreadFastMutex::Lock(a1: p_m_mtx, a2: CurrentThreadId, a3: 0);
  }
  else
  {
    ++p_m_mtx->m_depth;
  }
  if ( this->m_lstCommands.m_Size != 0 )
    result = *this->m_lstCommands.m_Memory.m_pMemory;
  else
    result = (char *)WindowName;
  if ( p_m_mtx->m_depth-- == 1 )
    _InterlockedExchange((volatile __int32 *)p_m_mtx, 0);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00419900
// Name: protected: void CUtlBuffer::PutTypeBin<int>(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlBuffer::PutTypeBin<int>(CUtlBuffer *this, int src)
{
  if ( CUtlBuffer::CheckPut(this, nSize: 4) )
  {
    if ( (*(_BYTE *)&this->m_Byteswap & 1) != 0 )
      CByteswap::SwapBufferToTargetEndian<int>(
        this: &this->m_Byteswap,
        outputBuffer: (int *)&this->m_Memory.m_pMemory[this->m_Put - this->m_nOffset],
        inputBuffer: &src,
        count: 1);
    else
      *(_DWORD *)&this->m_Memory.m_pMemory[this->m_Put - this->m_nOffset] = src;
    this->m_Put += 4;
    CUtlBuffer::AddNullTermination(this, nPut: this->m_Put);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00419A90
// Name: public: int CValveIpcServer::EnsureRegisteredAndRunning(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CValveIpcServer::EnsureRegisteredAndRunning(CValveIpcServer *this)
{
  HANDLE Thread; // eax

  if ( this->m_hThread != nullptr && this->m_bRunning != 0 )
    return 1;
  if ( CValveIpcServer::Register(this) != 0 && this->m_hThread == nullptr )
  {
    Thread = CreateThread(
               lpThreadAttributes: nullptr,
               dwStackSize: 0,
               lpStartAddress: (LPTHREAD_START_ROUTINE)CValveIpcServer::RunDelegate,
               lpParameter: this,
               dwCreationFlags: 4u,
               lpThreadId: nullptr);
    this->m_hThread = Thread;
    if ( Thread != nullptr )
    {
      this->m_bRunning = 1;
      ResumeThread(hThread: Thread);
      if ( this->m_hThread != nullptr && this->m_bRunning != 0 )
        return 1;
    }
  }
  CValveIpcServer::Unregister(this);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x00419B70
// Name: public: void MDLViewer::handleIpcCommand(char __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall MDLViewer::handleIpcCommand(MDLViewer *this, char *szCommand)
{
  IMDLCache *v2; // ebx
  const char *v4; // edi
  HWND Handle; // eax
  HWND v6; // esi
  const char *Label; // eax
  const char *v8; // eax
  const char *v9; // edi
  char szFirstPart[32]; // [esp+10h] [ebp-150h] BYREF
  matrix3x4_t mModelToCameraFull; // [esp+30h] [ebp-130h] BYREF
  matrix3x4_t mFinal; // [esp+60h] [ebp-100h] BYREF
  matrix3x4_t mModelToCameraRot; // [esp+90h] [ebp-D0h] BYREF
  matrix3x4_t mModelToCameraTrans; // [esp+C0h] [ebp-A0h] BYREF
  Vector in; // [esp+F0h] [ebp-70h] BYREF
  Vector vCameraPos; // [esp+FCh] [ebp-64h]
  QAngle vMayaRot; // [esp+108h] [ebp-58h] BYREF
  Vector vMayaPos; // [esp+114h] [ebp-4Ch] BYREF
  CUtlString v19; // [esp+120h] [ebp-40h] BYREF
  matrix3x4_t m; // [esp+130h] [ebp-30h] BYREF

  v2 = g_pMDLCache;
  g_pMDLCache->BeginLock(this: g_pMDLCache);
  v4 = szCommand;
  if ( strcmp("reload", szCommand) != 0 )
  {
    if ( V_strncasecmp(s1: "cameraTo", s2: szCommand, n: 8) == 0 )
    {
      sscanf(
        string: v4,
        format: "%s %f %f %f %f %f %f",
        szFirstPart,
        &vMayaPos,
        &vMayaPos.y,
        &vMayaPos.z,
        &vMayaRot,
        &vMayaRot.y,
        &vMayaRot.z);
      v19.m_Storage.m_Memory.m_nAllocationCount = LODWORD(vMayaRot.x) ^ _mask__NegFloat_;
      vCameraPos.x = vMayaPos.z;
      *(float *)&v19.m_Storage.m_Memory.m_nGrowSize = vMayaRot.y + 180.0;
      vCameraPos.y = vMayaPos.x;
      vCameraPos.z = vMayaPos.y;
      v19.m_Storage.m_nActualLength = LODWORD(vMayaRot.z) ^ _mask__NegFloat_;
      SetIdentityMatrix(matrix: &mModelToCameraTrans);
      in.x = -vCameraPos.x;
      in.y = -vCameraPos.y;
      in.z = -vCameraPos.z;
      MatrixSetColumn(&in, column: 3, out: &mModelToCameraTrans);
      AngleMatrix(angles: (const QAngle *)&v19.m_Storage.m_Memory.m_nAllocationCount, matrix: &mModelToCameraRot);
      MatrixTranspose(mat: &mModelToCameraRot);
      ConcatTransforms(in1: &mModelToCameraRot, in2: &mModelToCameraTrans, out: &mModelToCameraFull);
      *(_QWORD *)&m.m_flMatVal[0][0] = 3212836864LL;
      *(_QWORD *)&m.m_flMatVal[0][2] = 0;
      *(_QWORD *)&m.m_flMatVal[1][0] = 0xBF80000000000000uLL;
      memset(&m.m_flMatVal[1][2], 0, 16);
      *(_QWORD *)&m.m_flMatVal[2][2] = 1065353216;
      ConcatTransforms(in1: &m, in2: &mModelToCameraFull, out: &mFinal);
      StudioModel::SetModelTransform(this: g_pStudioModel, mat: &mFinal);
      this->d_MatSysWindow->redraw(this: this->d_MatSysWindow);
      v2->EndLock(this: v2);
      return;
    }
    if ( StringAfterPrefixCaseSensitive(str: v4, prefix: "hlmvModelTransform") != nullptr )
    {
      sscanf(
        string: v4,
        format: "%*s %f %f %f %f %f %f %f %f %f %f %f %f",
        &m,
        &m.m_flMatVal[0][1],
        &m.m_flMatVal[0][2],
        &m.m_flMatVal[0][3],
        m.m_flMatVal[1],
        &m.m_flMatVal[1][1],
        &m.m_flMatVal[1][2],
        &m.m_flMatVal[1][3],
        m.m_flMatVal[2],
        &m.m_flMatVal[2][1],
        &m.m_flMatVal[2][2],
        &m.m_flMatVal[2][3]);
      StudioModel::SetModelTransform(this: g_pStudioModel, mat: &m);
      this->d_MatSysWindow->redraw(this: this->d_MatSysWindow);
      v2->EndLock(this: v2);
      return;
    }
    if ( StringAfterPrefixCaseSensitive(str: v4, prefix: "hlmvForceFrame") != nullptr )
    {
      szCommand = nullptr;
      sscanf(string: v4, format: "%*s %f", &szCommand);
      ControlPanel::SetFrameSlider(this: this->d_cpl, flFrame: *(float *)&szCommand);
      ControlPanel::setFrame(this: this->d_cpl, frame: *(float *)&szCommand);
      ControlPanel::setSpeedScale(this: this->d_cpl, scale: 0.0);
      this->d_MatSysWindow->redraw(this: this->d_MatSysWindow);
      v2->EndLock(this: v2);
      return;
    }
    if ( StringAfterPrefixCaseSensitive(str: v4, prefix: "hlmvLink") != nullptr )
    {
      if ( !g_bHlmvControlled )
      {
        g_bHlmvControlled = true;
        CUtlString::CUtlString(this: &v19, pString: "LINKED: ");
        Label = mxWidget::getLabel(this);
        CUtlString::operator+=(this: &v19, rhs: Label);
        v8 = CUtlString::Get(this: &v19);
        mxWidget::setLabel(this, format: v8);
        CUtlString::~CUtlString(this: &v19);
        v2->EndLock(this: v2);
        return;
      }
    }
    else if ( StringAfterPrefixCaseSensitive(str: v4, prefix: "hlmvUnlink") != nullptr )
    {
      g_bHlmvControlled = false;
      v9 = mxWidget::getLabel(this);
      if ( StringHasPrefixCaseSensitive(str: v9, prefix: "LINKED: ") )
        mxWidget::setLabel(this, format: v9 + 8);
    }
    goto LABEL_18;
  }
  MDLViewer::Refresh(this);
  Handle = (HWND)mxWidget::getHandle(this);
  v6 = Handle;
  if ( Handle == nullptr )
  {
LABEL_18:
    v2->EndLock(this: v2);
    return;
  }
  if ( IsIconic(hWnd: Handle) )
    ShowWindow(hWnd: v6, nCmdShow: 9);
  BringWindowToTop(hWnd: v6);
  SetForegroundWindow(hWnd: v6);
  SetFocus(hWnd: v6);
  v2->EndLock(this: v2);
}

//------------------------------------------------------------------------------
// Address: 0x00419F80
// Name: public: void MDLViewer::SendModelTransformToLinkedHlmv(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall MDLViewer::SendModelTransformToLinkedHlmv(MDLViewer *this)
{
  void *m_hClientPipe; // eax
  CUtlBuffer cmd; // [esp+64h] [ebp-94h] BYREF
  CUtlBuffer res; // [esp+94h] [ebp-64h] BYREF
  matrix3x4_t m; // [esp+C4h] [ebp-34h] BYREF
  unsigned int BytesRead; // [esp+F4h] [ebp-4h] BYREF

  if ( CValveIpcClient::Connect(this: &g_HlmvIpcClient) != 0 )
  {
    StudioModel::GetModelTransform(this: g_pStudioModel, mat: &m);
    CUtlBuffer::CUtlBuffer(this: &cmd, growSize: 0, initSize: 0, nFlags: 0);
    CUtlBuffer::CUtlBuffer(this: &res, growSize: 0, initSize: 0, nFlags: 0);
    CUtlBuffer::Printf(
      this: &cmd,
      pFmt: "%s %f %f %f %f %f %f %f %f %f %f %f %f",
      "hlmvModelTransform",
      m.m_flMatVal[0][0],
      m.m_flMatVal[0][1],
      m.m_flMatVal[0][2],
      m.m_flMatVal[0][3],
      m.m_flMatVal[1][0],
      m.m_flMatVal[1][1],
      m.m_flMatVal[1][2],
      m.m_flMatVal[1][3],
      m.m_flMatVal[2][0],
      m.m_flMatVal[2][1],
      m.m_flMatVal[2][2],
      m.m_flMatVal[2][3]);
    BytesRead = res.m_Memory.m_nAllocationCount;
    if ( g_HlmvIpcClient.m_szServerUID != nullptr )
    {
      m_hClientPipe = g_HlmvIpcClient.m_hClientPipe;
      if ( g_HlmvIpcClient.m_hClientPipe != nullptr )
      {
        if ( TransactNamedPipe(
               hNamedPipe: g_HlmvIpcClient.m_hClientPipe,
               lpInBuffer: cmd.m_Memory.m_pMemory,
               nInBufferSize: cmd.m_Put,
               lpOutBuffer: res.m_Memory.m_pMemory,
               nOutBufferSize: res.m_Memory.m_nAllocationCount,
               lpBytesRead: &BytesRead,
               lpOverlapped: nullptr)
          || GetLastError() == 234 )
        {
          CUtlBuffer::SeekPut(this: &res, type: SEEK_HEAD, offset: BytesRead);
        }
        m_hClientPipe = g_HlmvIpcClient.m_hClientPipe;
      }
      if ( g_HlmvIpcClient.m_szServerUID != nullptr )
      {
        if ( m_hClientPipe != nullptr )
        {
          CloseHandle(hObject: m_hClientPipe);
          g_HlmvIpcClient.m_hClientPipe = nullptr;
        }
        if ( g_HlmvIpcClient.m_szServerUID != nullptr )
        {
          RpcStringFreeA(String: &g_HlmvIpcClient.m_szServerUID);
          g_HlmvIpcClient.m_szServerUID = nullptr;
        }
      }
    }
    if ( res.m_Memory.m_nGrowSize >= 0 )
    {
      if ( res.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: res.m_Memory.m_pMemory);
        res.m_Memory.m_pMemory = nullptr;
      }
      res.m_Memory.m_nAllocationCount = 0;
    }
    if ( cmd.m_Memory.m_nGrowSize >= 0 && cmd.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: cmd.m_Memory.m_pMemory);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041A160
// Name: public: void CHlmvIpcServer::PopCommand(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHlmvIpcServer::PopCommand(CHlmvIpcServer *this)
{
  CThreadFastMutex *p_m_mtx; // edi
  DWORD CurrentThreadId; // ecx

  p_m_mtx = &this->m_mtx;
  CurrentThreadId = GetCurrentThreadId();
  if ( CurrentThreadId != p_m_mtx->m_ownerID
    && _InterlockedCompareExchange((volatile signed __int32 *)p_m_mtx, CurrentThreadId, 0) != 0 )
  {
    _mm_pause();
    CThreadFastMutex::Lock(a1: p_m_mtx, a2: CurrentThreadId, a3: 0);
  }
  else
  {
    ++p_m_mtx->m_depth;
  }
  if ( this->m_lstCommands.m_Size != 0 )
  {
    free(pMem: *(void **)this->m_lstCommands.m_Memory.m_pMemory);
    if ( this->m_lstCommands.m_Size - 1 > 0 )
      _V_memmove(
        dest: this->m_lstCommands.m_Memory.m_pMemory,
        src: this->m_lstCommands.m_Memory.m_pMemory + 1,
        count: 4 * (this->m_lstCommands.m_Size - 1));
    --this->m_lstCommands.m_Size;
  }
  if ( p_m_mtx->m_depth-- == 1 )
    _InterlockedExchange((volatile __int32 *)p_m_mtx, 0);
}

//------------------------------------------------------------------------------
// Address: 0x0041A560
// Name: public: virtual int CValveIpcServerUtl::ExecuteCommand(char __near *,unsigned long,char __near *,unsigned long __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CValveIpcServerUtl::ExecuteCommand(
        CValveIpcServerUtl *this,
        char *bufCommand,
        unsigned int numCommandBytes,
        char *bufResult,
        unsigned int *numResultBytes)
{
  CUtlBuffer cmd; // [esp+8h] [ebp-60h] BYREF
  CUtlBuffer res; // [esp+38h] [ebp-30h] BYREF

  CUtlBuffer::CUtlBuffer(this: &cmd, pBuffer: bufCommand, nSize: numCommandBytes, nFlags: 8);
  CUtlBuffer::CUtlBuffer(this: &res, pBuffer: bufResult, nSize: 0x10000, nFlags: 0);
  if ( this->ExecuteCommand_2(this, a2: &cmd, a3: &res) != 0 )
  {
    *numResultBytes = res.m_Put;
    if ( res.m_Memory.m_nGrowSize >= 0 )
    {
      if ( res.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: res.m_Memory.m_pMemory);
        res.m_Memory.m_pMemory = nullptr;
      }
      res.m_Memory.m_nAllocationCount = 0;
    }
    if ( cmd.m_Memory.m_nGrowSize >= 0 && cmd.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: cmd.m_Memory.m_pMemory);
    return 1;
  }
  else
  {
    if ( res.m_Memory.m_nGrowSize >= 0 )
    {
      if ( res.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: res.m_Memory.m_pMemory);
        res.m_Memory.m_pMemory = nullptr;
      }
      res.m_Memory.m_nAllocationCount = 0;
    }
    if ( cmd.m_Memory.m_nGrowSize >= 0 && cmd.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: cmd.m_Memory.m_pMemory);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041A640
// Name: public: virtual int MDLViewer::handleEvent(class mxEvent __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall MDLViewer::handleEvent(MDLViewer *this, int event)
{
  void (*BeginLock)(void); // edx
  mxEvent *v4; // edi
  int action; // ecx
  char *OpenFileName; // eax
  char *v7; // eax
  unsigned int v8; // ebx
  unsigned int v9; // edx
  char *v10; // ecx
  unsigned int v11; // edx
  char *v12; // ecx
  float *v13; // edi
  unsigned __int8 *SaveFileName; // eax
  char *v15; // edi
  int v16; // eax
  int v17; // edx
  int v18; // ecx
  int v19; // eax
  int v20; // edi
  StudioModel *v21; // ecx
  StudioModel *v22; // ebx
  int v23; // edi
  int width; // ebx
  int height; // edi
  mxEvent *CurrentVersion; // eax
  MatSysWindow *d_MatSysWindow; // ecx
  int i; // edi
  char *Command; // eax
  char *v30; // eax
  BOOL IsRunning; // edi
  _DWORD v33[1068]; // [esp+0h] [ebp-1150h]
  int v34; // [esp+10C0h] [ebp-90h]
  int showActivities; // [esp+10C4h] [ebp-8Ch]
  void *(__cdecl **v36)(const char *, int *); // [esp+10C8h] [ebp-88h]
  int v37; // [esp+10CCh] [ebp-84h]
  CUtlBuffer res; // [esp+10D4h] [ebp-7Ch] BYREF
  CUtlBuffer cmd; // [esp+1104h] [ebp-4Ch] BYREF
  float *cols[4]; // [esp+1134h] [ebp-1Ch]
  CMDLCacheCriticalSection cacheCriticalSection; // [esp+1144h] [ebp-Ch]
  int b; // [esp+1148h] [ebp-8h] BYREF
  int g; // [esp+114Ch] [ebp-4h] BYREF

  BeginLock = (void (*)(void))g_pMDLCache->BeginLock;
  cacheCriticalSection.m_pCache = g_pMDLCache;
  BeginLock();
  v4 = (mxEvent *)event;
  switch ( *(_DWORD *)(event + 4) )
  {
    case 0:
      _Msg(
        a1: "%2.2f %2.2f %2.2f\n",
        g_pStudioModel->m_angles.x,
        g_pStudioModel->m_angles.y,
        g_pStudioModel->m_angles.z);
      action = v4->action;
      if ( action > 1301 )
      {
        switch ( action )
        {
          case 1302:
            mxMessageBox(
              parent: this,
              msg: "Half-Life Model Viewer v2.0 (c) 2004 Valve Corp.\n"
              "Portions (c) 1999 by Mete Ciragan\n"
              "\n"
              "Left-drag inside circle to spin.\n"
              "Left-drag outside circle to rotate.\n"
              "Right-drag to zoom.\n"
              "Shift-left-drag to x-y-pan.\n"
              "Shift-right-drag to z-pan.\n"
              "Ctrl-left-drag to move light.\n"
              "\n"
              "Build:\tJul 15 2011.\n"
              "Email:\tmete@swissquake.ch\n"
              "Web:\thttp://www.swissquake.ch/chumbalum-soft/",
              title: "About Half-Life Model Viewer",
              style: 4);
            break;
          case 1401:
            ControlPanel::setOverlayWireframe(this: this->d_cpl, b: !g_viewerSettings.overlayWireframe);
            break;
          case 1402:
            ControlPanel::setShowAttachments(this: this->d_cpl, b: !g_viewerSettings.showAttachments);
            break;
          case 1403:
            ControlPanel::setShowGround(this: this->d_cpl, b: !g_viewerSettings.showGround);
            break;
          case 1404:
            ControlPanel::setShowHitBoxes(this: this->d_cpl, b: !g_viewerSettings.showHitBoxes);
            break;
          case 1405:
            ControlPanel::setShowBones(this: this->d_cpl, b: !g_viewerSettings.showBones);
            break;
          case 1406:
            ControlPanel::setShowBackground(this: this->d_cpl, b: !g_viewerSettings.showBackground);
            break;
          case 1407:
            ControlPanel::setShowMovement(this: this->d_cpl, b: !g_viewerSettings.showMovement);
            break;
          case 1408:
            ControlPanel::setShowNormals(this: this->d_cpl, b: !g_viewerSettings.showNormals);
            break;
          case 1409:
            ControlPanel::setShowTangentFrame(this: this->d_cpl, b: !g_viewerSettings.showTangentFrame);
            break;
          case 1410:
            ControlPanel::setShowShadow(this: this->d_cpl, b: !g_viewerSettings.showShadow);
            break;
          case 1411:
            ControlPanel::setDisplacementMapping(this: this->d_cpl, b: !g_viewerSettings.enableDisplacementMapping);
            break;
          case 1412:
            if ( mat_tessellationlevel.m_pParent != nullptr )
              ConVar::SetValue(
                this: (ConVar *)&mat_tessellationlevel.IConVar,
                value: mat_tessellationlevel.m_pParent->m_Value.m_nValue + 1);
            else
              ConVar::SetValue(this: (ConVar *)&mat_tessellationlevel.IConVar, value: 1);
            break;
          case 1413:
            if ( mat_tessellationlevel.m_pParent != nullptr )
              ConVar::SetValue(
                this: (ConVar *)&mat_tessellationlevel.IConVar,
                value: mat_tessellationlevel.m_pParent->m_Value.m_nValue - 1);
            else
              ConVar::SetValue(this: (ConVar *)&mat_tessellationlevel.IConVar, value: -1);
            break;
          case 1414:
          case 1415:
          case 1416:
          case 1417:
          case 1418:
          case 1419:
          case 1420:
          case 1421:
          case 1422:
          case 1423:
          case 1424:
          case 1425:
            v20 = action - 1414;
            v21 = g_pStudioExtraModel[action - 1414];
            if ( v21 != nullptr )
            {
              LOBYTE(showActivities) = 0;
              g_viewerSettings.mergeModelFile[v20][0] = 0;
              StudioModel::FreeModel(this: v21, bReleasing: showActivities);
              v22 = g_pStudioExtraModel[v20];
              if ( v22 != nullptr )
              {
                StudioModel::~StudioModel(this: g_pStudioExtraModel[v20]);
                StudioModel::operator delete(pMem: v22);
              }
              g_pStudioExtraModel[v20] = nullptr;
              v23 = v20 + 1414;
              mxMenuBar::modify(this: this->mb, id: v23, newId: v23, newItem: "(empty)");
              mxMenu::setEnabled(this: this->mb, id: v23, b: false);
            }
            break;
          default:
            goto LABEL_112;
        }
        goto LABEL_112;
      }
      if ( action == 1301 )
      {
        ShellExecuteA(
          hwnd: nullptr,
          lpOperation: "open",
          lpFile: "http://www.swissquake.ch/chumbalum-soft/index.html",
          lpParameters: nullptr,
          lpDirectory: nullptr,
          nShowCmd: 5);
        goto LABEL_112;
      }
      switch ( action )
      {
        case 1001:
          OpenFileName = (char *)mxGetOpenFileName(parent: this, path: nullptr, filter: "*.mdl");
          goto LABEL_7;
        case 1002:
        case 1003:
          if ( mxGetOpenFileName(parent: this, path: nullptr, filter: "*.*") != nullptr )
            mxMessageBox(parent: this, msg: "Error loading texture.", title: g_appTitle, style: 8);
          goto LABEL_112;
        case 1004:
          ControlPanel::setShowGround(this: this->d_cpl, b: false);
          goto LABEL_112;
        case 1008:
        case 1009:
        case 1010:
        case 1011:
        case 1012:
        case 1013:
        case 1014:
        case 1015:
          MDLViewer::LoadModelFile(this, pszFile: recentFiles[action - 1008], slot: 0xFFFFFFFF);
          goto LABEL_112;
        case 1016:
          this->redraw(this);
          mx::quit();
          goto LABEL_112;
        case 1017:
          MDLViewer::Refresh(this);
          goto LABEL_112;
        case 1018:
          v7 = (char *)mxGetOpenFileName(parent: this, path: nullptr, filter: "*.mdl");
          if ( v7 == nullptr )
            goto LABEL_112;
          v8 = 0;
          v9 = 0;
          v10 = g_viewerSettings.mergeModelFile[0];
          while ( *v10 != 0 )
          {
            v10 += 256;
            ++v9;
            if ( (int)v10 >= (int)g_viewerSettings.mergeModelFile[12] )
              goto LABEL_15;
          }
          v8 = v9;
LABEL_15:
          strcpy(g_viewerSettings.mergeModelFile[v8], v7);
          goto LABEL_16;
        case 1020:
          OpenFileName = MDLViewer::SteamGetOpenFilename(this, a2: (int)this);
LABEL_7:
          if ( OpenFileName != nullptr )
            MDLViewer::LoadModelFile(this, pszFile: OpenFileName, slot: 0xFFFFFFFF);
          goto LABEL_112;
        case 1021:
          v7 = MDLViewer::SteamGetOpenFilename(this, a2: (int)this);
          if ( v7 == nullptr )
            goto LABEL_112;
          v8 = 0;
          v11 = 0;
          v12 = g_viewerSettings.mergeModelFile[0];
          break;
        case 1101:
        case 1102:
        case 1103:
        case 1104:
          cols[0] = g_viewerSettings.bgColor;
          cols[1] = g_viewerSettings.gColor;
          cols[2] = g_viewerSettings.lColor;
          cols[3] = g_viewerSettings.aColor;
          v13 = (float *)v33[action];
          event = (int)(float)(*v13 * 255.0);
          g = (int)(float)(v13[1] * 255.0);
          b = (int)(float)(v13[2] * 255.0);
          if ( mxChooseColor(parent: this, r: &event, &g, &b) )
          {
            *v13 = (float)event * 0.0039215689;
            v13[1] = (float)g * 0.0039215689;
            v13[2] = (float)b * 0.0039215689;
          }
          goto LABEL_112;
        case 1105:
          if ( !g_viewerSettings.dotaMode )
          {
            ControlPanel::centerView(this: this->d_cpl);
            if ( g_bHlmvMaster )
              goto $LN45;
          }
          goto LABEL_112;
        case 1106:
          if ( !g_viewerSettings.dotaMode )
          {
            ControlPanel::centerVerts(this: this->d_cpl);
            if ( g_bHlmvMaster )
              goto $LN45;
          }
          goto LABEL_112;
        case 1107:
          SaveFileName = (unsigned __int8 *)mxGetSaveFileName(parent: this, path: WindowName, filter: "*.tga");
          v15 = (char *)SaveFileName;
          if ( SaveFileName != nullptr )
          {
            strstr(str1: SaveFileName, str2: str2);
            if ( v16 == 0 )
              strcat(v15, ".tga");
            MatSysWindow::dumpViewport(this: this->d_MatSysWindow, filename: v15);
          }
          goto LABEL_112;
        case 1108:
          CDmeFXClip::OnDestruction(pFactoryList: v36, nFactoryCount: v37);
          goto LABEL_112;
        case 1109:
          if ( !g_viewerSettings.dotaMode )
          {
            ControlPanel::viewmodelView(this: this->d_cpl, a2: (int)this);
            if ( g_bHlmvMaster )
              goto $LN45;
          }
          goto LABEL_112;
        case 1110:
          goto $LN45;
        case 1111:
          if ( g_bHlmvMaster
            || CValveIpcServer::IsRunning(this: &g_HlmvIpcServer)
            || CValveIpcClient::Connect(this: &g_HlmvIpcClient) == 0 )
          {
            goto LABEL_112;
          }
          CUtlBuffer::CUtlBuffer(this: &cmd, growSize: 0, initSize: 0, nFlags: 0);
          CUtlBuffer::CUtlBuffer(this: &res, growSize: 0, initSize: 0, nFlags: 0);
          CUtlBuffer::PutString(this: &cmd, pString: "hlmvLink");
          CUtlBuffer::PutChar(this: &cmd, c: 0);
          if ( CValveIpcClientUtl::ExecuteCommand(this: &g_HlmvIpcClient, &cmd, &res) != 0 )
            g_bHlmvMaster = true;
          CValveIpcClient::Disconnect(this: &g_HlmvIpcClient);
          mxMenu::setChecked(this: this->menuOptions, id: 1111, b: true);
          mxMenu::setEnabled(this: (mxMenuBar *)this->menuOptions, id: 1111, b: false);
          mxMenu::setChecked(this: this->menuOptions, id: 1112, b: false);
          showActivities = 1;
          goto LABEL_59;
        case 1112:
          if ( !g_bHlmvMaster || CValveIpcClient::Connect(this: &g_HlmvIpcClient) == 0 )
            goto LABEL_112;
          CUtlBuffer::CUtlBuffer(this: &cmd, growSize: 0, initSize: 0, nFlags: 0);
          CUtlBuffer::CUtlBuffer(this: &res, growSize: 0, initSize: 0, nFlags: 0);
          CUtlBuffer::PutString(this: &cmd, pString: "hlmvUnlink");
          CUtlBuffer::PutChar(this: &cmd, c: 0);
          CValveIpcClientUtl::ExecuteCommand(this: &g_HlmvIpcClient, &cmd, &res);
          g_bHlmvMaster = false;
          CValveIpcClient::Disconnect(this: &g_HlmvIpcClient);
          mxMenu::setChecked(this: this->menuOptions, id: 1111, b: false);
          mxMenu::setEnabled(this: (mxMenuBar *)this->menuOptions, id: 1111, b: true);
          mxMenu::setChecked(this: this->menuOptions, id: 1112, b: true);
          showActivities = 0;
LABEL_59:
          mxMenu::setEnabled(this: (mxMenuBar *)this->menuOptions, id: 1112, b: showActivities);
          CUtlBuffer::~CUtlBuffer(this: &res);
          CUtlBuffer::~CUtlBuffer(this: &cmd);
          goto LABEL_112;
        case 1201:
          FileAssociation::setAssociation(this: g_FileAssociation, index: 0);
          mxWidget::setVisible(this: g_FileAssociation, b: true);
          goto LABEL_112;
        case 1202:
          ControlPanel::SaveSelectedSequences(this: this->d_cpl);
          g_viewerSettings.showActivities = !g_viewerSettings.showActivities;
          v17 = v4->action;
          showActivities = g_viewerSettings.showActivities;
          v34 = v17;
          goto LABEL_64;
        case 1203:
          ControlPanel::SaveSelectedSequences(this: this->d_cpl);
          g_viewerSettings.showHidden = !g_viewerSettings.showHidden;
          v18 = v4->action;
          showActivities = g_viewerSettings.showHidden;
          v34 = v18;
          goto LABEL_64;
        case 1204:
          ControlPanel::SaveSelectedSequences(this: this->d_cpl);
          g_viewerSettings.showSequenceIndices = !g_viewerSettings.showSequenceIndices;
          v19 = v4->action;
          showActivities = g_viewerSettings.showSequenceIndices;
          v34 = v19;
LABEL_64:
          mxMenu::setChecked(this: this->menuView, id: v34, b: showActivities);
          ControlPanel::initSequenceChoices(this: this->d_cpl, iOnlyInitSlot: -1);
          ControlPanel::resetControlPanel(this: this->d_cpl);
          ControlPanel::RestoreSelectedSequences(this: this->d_cpl);
          goto LABEL_112;
        case 1205:
          g_viewerSettings.sortSequences = !g_viewerSettings.sortSequences;
          mxMenu::setChecked(this: this->menuView, id: v4->action, b: g_viewerSettings.sortSequences);
          ControlPanel::initSequenceChoices(this: this->d_cpl, iOnlyInitSlot: -1);
          ControlPanel::resetControlPanel(this: this->d_cpl);
          goto LABEL_112;
        case 1206:
          g_viewerSettings.dotaMode = !g_viewerSettings.dotaMode;
          mxMenu::setChecked(this: this->menuView, id: 1206, b: g_viewerSettings.dotaMode);
          if ( g_viewerSettings.dotaMode )
            ControlPanel::dotaView(this: this->d_cpl, a2: (int)this);
          if ( g_bHlmvMaster )
$LN45:
            MDLViewer::SendModelTransformToLinkedHlmv(this);
          goto LABEL_112;
        default:
          goto LABEL_112;
      }
      while ( *v12 != 0 )
      {
        v12 += 256;
        ++v11;
        if ( (int)v12 >= (int)g_viewerSettings.mergeModelFile[12] )
          goto LABEL_23;
      }
      v8 = v11;
LABEL_23:
      strcpy(g_viewerSettings.mergeModelFile[v8], v7);
LABEL_16:
      MDLViewer::LoadModelFile(this, pszFile: v7, slot: v8);
      goto LABEL_112;
    case 1:
      g_viewerSettings.xpos = mxWidget::x(this);
      g_viewerSettings.ypos = mxWidget::y(this);
      g_viewerSettings.width = mxWidget::w(this);
      g_viewerSettings.height = mxWidget::h(this);
      width = v4->width;
      height = v4->height;
      CurrentVersion = (mxEvent *)CImportTex::GetCurrentVersion(this: (ConVar *)this->mb);
      showActivities = height - 240;
      d_MatSysWindow = this->d_MatSysWindow;
      event = (int)CurrentVersion;
      mxWidget::setBounds(this: d_MatSysWindow, x: 0, y: (int)CurrentVersion, w: width, h: height - 240);
      mxWidget::setBounds(this: this->d_cpl, x: 0, y: event + height - 240, w: width, h: 240);
      goto LABEL_112;
    case 2:
      if ( CHlmvIpcServer::HasCommands(this: &g_HlmvIpcServer) )
      {
        if ( g_bHlmvControlled )
        {
          for ( i = 0; i < 10; ++i )
          {
            if ( !CHlmvIpcServer::HasCommands(this: &g_HlmvIpcServer) )
              break;
            Command = CHlmvIpcServer::GetCommand(this: &g_HlmvIpcServer);
            MDLViewer::handleIpcCommand(this, szCommand: Command);
            CHlmvIpcServer::PopCommand(this: &g_HlmvIpcServer);
          }
          goto LABEL_101;
        }
        v30 = CHlmvIpcServer::GetCommand(this: &g_HlmvIpcServer);
        MDLViewer::handleIpcCommand(this, szCommand: v30);
        CHlmvIpcServer::PopCommand(this: &g_HlmvIpcServer);
        showActivities = 100;
      }
      else if ( g_HlmvIpcServer.m_hThread != nullptr && g_HlmvIpcServer.m_bRunning != 0 )
      {
        if ( g_bHlmvControlled )
        {
LABEL_101:
          showActivities = 17;
          goto LABEL_111;
        }
        showActivities = 500;
      }
      else
      {
        IsRunning = CValveIpcServer::IsRunning(this: &g_HlmvIpcServer);
        CValveIpcServer::EnsureRegisteredAndRunning(this: &g_HlmvIpcServer);
        if ( !IsRunning && CValveIpcServer::IsRunning(this: &g_HlmvIpcServer) )
        {
          g_bHlmvMaster = false;
          mxMenu::setEnabled(this: (mxMenuBar *)this->menuOptions, id: 1111, b: false);
          mxMenu::setChecked(this: this->menuOptions, id: 1111, b: false);
          mxMenu::setEnabled(this: (mxMenuBar *)this->menuOptions, id: 1112, b: false);
          mxMenu::setChecked(this: this->menuOptions, id: 1111, b: false);
        }
        showActivities = 1000;
      }
LABEL_111:
      mxWindow::setTimer(this, milliSeconds: showActivities);
LABEL_112:
      cacheCriticalSection.m_pCache->EndLock(this: cacheCriticalSection.m_pCache);
      return 1;
    case 0xB:
      this->d_MatSysWindow->handleEvent(this: this->d_MatSysWindow, a2: (mxEvent *)event);
      this->d_cpl->handleEvent(this: this->d_cpl, a2: v4);
      goto LABEL_112;
    case 0xE:
      if ( *(_DWORD *)(event + 12) != 0 )
        mx::setIdleWindow(window: this->d_MatSysWindow);
      else
        mx::setIdleWindow(window: nullptr);
      goto LABEL_112;
    case 0x14:
      g_viewerSettings.xpos = mxWidget::x(this);
      g_viewerSettings.ypos = mxWidget::y(this);
      goto LABEL_112;
    default:
      goto LABEL_112;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041B320
// Name: public: MDLViewer::MDLViewer(void)
// Source: json
//------------------------------------------------------------------------------
MDLViewer *__thiscall MDLViewer::MDLViewer(MDLViewer *this)
{
  mxMenu *v1; // ebx
  mxMenuBar *v3; // eax
  mxMenuBar *v4; // eax
  mxMenu *v5; // eax
  mxMenu *v6; // edi
  mxMenu *v7; // eax
  mxMenu *v8; // eax
  mxMenu *v9; // eax
  mxMenu *v10; // eax
  mxMenu *v11; // eax
  mxMenu *v12; // eax
  mxMenu *v13; // eax
  mxMenu *v14; // ebx
  MatSysWindow *v15; // eax
  MatSysWindow *v16; // eax
  ControlPanel *v17; // eax
  ControlPanel *v18; // eax
  MatSysWindow *d_MatSysWindow; // edx
  FileAssociation *v20; // eax
  int ypos; // eax
  mx::Accel_t *m_pMemory; // ecx
  int m_Size; // edi
  mxMenu *v24; // edx
  int v25; // ebx
  mx::Accel_t *v26; // eax
  HANDLE Thread; // eax
  CUtlVector<mx::Accel_t,CUtlMemory<mx::Accel_t,int> > accelerators; // [esp+Ch] [ebp-24h] BYREF
  mxMenu *menuHelp; // [esp+20h] [ebp-10h]
  mx::Accel_t accel; // [esp+24h] [ebp-Ch]
  int i; // [esp+2Ch] [ebp-4h]

  v1 = nullptr;
  mxWindow::mxWindow(this, parent: nullptr, x: 0, y: 0, w: 0, h: 0, label: g_appTitle, style: 0);
  this->__vftable = (MDLViewer_vtbl *)&MDLViewer::`vftable';
  this->d_MatSysWindow = nullptr;
  this->d_cpl = nullptr;
  v3 = (mxMenuBar *)operator new(nSize: 0xCu);
  if ( v3 != nullptr )
    v4 = mxMenuBar::mxMenuBar(this: v3, parent: this);
  else
    v4 = nullptr;
  this->mb = v4;
  v5 = (mxMenu *)operator new(nSize: 0xCu);
  if ( v5 != nullptr )
    v6 = mxMenu::mxMenu(this: v5);
  else
    v6 = nullptr;
  v7 = (mxMenu *)operator new(nSize: 0xCu);
  if ( v7 != nullptr )
    v8 = mxMenu::mxMenu(this: v7);
  else
    v8 = nullptr;
  this->menuOptions = v8;
  v9 = (mxMenu *)operator new(nSize: 0xCu);
  if ( v9 != nullptr )
    v10 = mxMenu::mxMenu(this: v9);
  else
    v10 = nullptr;
  this->menuView = v10;
  v11 = (mxMenu *)operator new(nSize: 0xCu);
  if ( v11 != nullptr )
    menuHelp = mxMenu::mxMenu(this: v11);
  else
    menuHelp = nullptr;
  mxMenu::addMenu(this: this->mb, item: "File", menu: v6);
  mxMenu::addMenu(this: this->mb, item: "Options", menu: this->menuOptions);
  mxMenu::addMenu(this: this->mb, item: "View", menu: this->menuView);
  mxMenu::addMenu(this: this->mb, item: "Help", menu: menuHelp);
  v12 = (mxMenu *)operator new(nSize: 0xCu);
  if ( v12 != nullptr )
    v1 = mxMenu::mxMenu(this: v12);
  *(_DWORD *)&accel.flags = v1;
  mxMenu::add(this: v1, item: "(empty)", id: 1008);
  mxMenu::add(this: v1, item: "(empty)", id: 1009);
  mxMenu::add(this: v1, item: "(empty)", id: 1010);
  mxMenu::add(this: v1, item: "(empty)", id: 1011);
  mxMenu::add(this: v1, item: "(empty)", id: 1012);
  mxMenu::add(this: v1, item: "(empty)", id: 1013);
  mxMenu::add(this: v1, item: "(empty)", id: 1014);
  mxMenu::add(this: v1, item: "(empty)", id: 1015);
  if ( g_bOldFileDialogs )
  {
    mxMenu::add(this: v6, item: "Load Model...", id: 1001);
    mxMenu::add(this: v6, item: "(Steam) Load Model...", id: 1020);
  }
  else
  {
    mxMenu::add(this: v6, item: "Load Model...", id: 1020);
  }
  mxMenu::add(this: v6, item: "Refresh (F5)", id: 1017);
  mxMenu::addSeparator(this: v6);
  if ( g_bOldFileDialogs )
  {
    mxMenu::add(this: v6, item: "Load Weapon...", id: 1018);
    mxMenu::add(this: v6, item: "(Steam) Load Weapon...", id: 1021);
  }
  else
  {
    mxMenu::add(this: v6, item: "Load Weapon...", id: 1021);
  }
  v13 = (mxMenu *)operator new(nSize: 0xCu);
  if ( v13 != nullptr )
    v14 = mxMenu::mxMenu(this: v13);
  else
    v14 = nullptr;
  mxMenu::add(this: v14, item: "(empty)", id: 1414);
  mxMenu::add(this: v14, item: "(empty)", id: 1415);
  mxMenu::add(this: v14, item: "(empty)", id: 1416);
  mxMenu::add(this: v14, item: "(empty)", id: 1417);
  mxMenu::add(this: v14, item: "(empty)", id: 1418);
  mxMenu::add(this: v14, item: "(empty)", id: 1419);
  mxMenu::add(this: v14, item: "(empty)", id: 1420);
  mxMenu::add(this: v14, item: "(empty)", id: 1421);
  mxMenu::add(this: v14, item: "(empty)", id: 1422);
  mxMenu::add(this: v14, item: "(empty)", id: 1423);
  mxMenu::add(this: v14, item: "(empty)", id: 1424);
  mxMenu::add(this: v14, item: "(empty)", id: 1425);
  for ( i = 1414; i <= 1425; ++i )
    mxMenu::setEnabled(this: (mxMenuBar *)v14, id: i, b: false);
  mxMenu::addMenu(this: (mxMenuBar *)v6, item: "Unload Weapon", menu: v14);
  mxMenu::addSeparator(this: v6);
  mxMenu::add(this: v6, item: "Load Background Texture...", id: 1002);
  mxMenu::add(this: v6, item: "Load Ground Texture...", id: 1003);
  mxMenu::addSeparator(this: v6);
  mxMenu::add(this: v6, item: "Unload Ground Texture", id: 1004);
  mxMenu::addSeparator(this: v6);
  mxMenu::addMenu(this: (mxMenuBar *)v6, item: "Recent Models", menu: *(mxMenu **)&accel.flags);
  mxMenu::addSeparator(this: v6);
  mxMenu::add(this: v6, item: "Exit", id: 1016);
  mxMenu::setEnabled(this: (mxMenuBar *)v6, id: 1002, b: false);
  mxMenu::setEnabled(this: (mxMenuBar *)v6, id: 1003, b: false);
  mxMenu::setEnabled(this: (mxMenuBar *)v6, id: 1004, b: false);
  mxMenu::add(this: this->menuOptions, item: "Background Color...", id: 1101);
  mxMenu::add(this: this->menuOptions, item: "Ground Color...", id: 1102);
  mxMenu::add(this: this->menuOptions, item: "Light Color...", id: 1103);
  mxMenu::add(this: this->menuOptions, item: "Ambient Color...", id: 1104);
  mxMenu::addSeparator(this: this->menuOptions);
  mxMenu::add(this: this->menuOptions, item: "Center View", id: 1105);
  mxMenu::add(this: this->menuOptions, item: "Center Verts", id: 1106);
  mxMenu::add(this: this->menuOptions, item: "Viewmodel Mode", id: 1109);
  mxMenu::addSeparator(this: this->menuOptions);
  mxMenu::add(this: this->menuOptions, item: "Make Screenshot...", id: 1107);
  mxMenu::add(this: this->menuView, item: "File Associations...", id: 1201);
  mxMenu::setEnabled(this: (mxMenuBar *)this->menuView, id: 1201, b: false);
  mxMenu::addSeparator(this: this->menuView);
  mxMenu::add(this: this->menuView, item: "Show Activities", id: 1202);
  mxMenu::add(this: this->menuView, item: "Show hidden", id: 1203);
  mxMenu::add(this: this->menuView, item: "Show sequence numbers", id: 1204);
  mxMenu::add(this: this->menuView, item: "Sort sequences", id: 1205);
  mxMenu::addSeparator(this: this->menuView);
  mxMenu::add(this: this->menuView, item: "DotA View Mode", id: 1206);
  mxMenu::add(this: menuHelp, item: "Goto Homepage...", id: 1301);
  mxMenu::addSeparator(this: menuHelp);
  mxMenu::add(this: menuHelp, item: "About...", id: 1302);
  v15 = (MatSysWindow *)operator new(nSize: 0x20u);
  if ( v15 != nullptr )
    v16 = MatSysWindow::MatSysWindow(this: v15, parent: this, x: 0, y: 0, w: 100, h: 100, label: WindowName, style: 0);
  else
    v16 = nullptr;
  this->d_MatSysWindow = v16;
  v17 = (ControlPanel *)operator new(nSize: 0x448u);
  if ( v17 != nullptr )
    v18 = ControlPanel::ControlPanel(this: v17, parent: this);
  else
    v18 = nullptr;
  d_MatSysWindow = this->d_MatSysWindow;
  this->d_cpl = v18;
  v18->d_MatSysWindow = d_MatSysWindow;
  g_MatSysWindow = this->d_MatSysWindow;
  v20 = (FileAssociation *)operator new(nSize: 0x1168u);
  if ( v20 != nullptr )
    g_FileAssociation = FileAssociation::FileAssociation(this: v20);
  else
    g_FileAssociation = nullptr;
  MDLViewer::loadRecentFiles(this);
  MDLViewer::initRecentFiles(this);
  LoadViewerRootSettings();
  if ( g_viewerSettings.xpos < -16384 )
    g_viewerSettings.xpos = 20;
  ypos = g_viewerSettings.ypos;
  if ( g_viewerSettings.ypos < -16384 )
    ypos = 20;
  g_viewerSettings.ypos = ypos < 0 ? 0 : ypos;
  if ( g_viewerSettings.width < 640 )
    g_viewerSettings.width = 640;
  if ( g_viewerSettings.height < 700 )
    g_viewerSettings.height = 700;
  mxMenu::setChecked(this: this->menuView, id: 1202, b: g_viewerSettings.showActivities);
  mxMenu::setChecked(this: this->menuView, id: 1203, b: g_viewerSettings.showHidden);
  mxMenu::setChecked(this: this->menuView, id: 1204, b: g_viewerSettings.showSequenceIndices);
  mxMenu::setChecked(this: this->menuView, id: 1205, b: g_viewerSettings.sortSequences);
  mxMenu::setChecked(this: this->menuView, id: 1206, b: g_viewerSettings.dotaMode);
  mxWidget::setBounds(
    this,
    x: g_viewerSettings.xpos,
    y: g_viewerSettings.ypos,
    w: g_viewerSettings.width,
    h: g_viewerSettings.height);
  mxWidget::setVisible(this, b: true);
  mxWindow::setTimer(this, milliSeconds: 200);
  m_pMemory = nullptr;
  m_Size = 0;
  v24 = (mxMenu *)accelTable;
  memset(&accelerators, 0, sizeof(accelerators));
  menuHelp = (mxMenu *)accelTable;
  do
  {
    accel.flags = (unsigned __int8)v24->mxWidget::d_this;
    accel.key = (unsigned __int16)v24->__vftable;
    accel.command = HIWORD(v24->__vftable);
    v25 = m_Size;
    if ( m_Size + 1 > accelerators.m_Memory.m_nAllocationCount )
    {
      CUtlMemory<mx::Accel_t,int>::Grow(
        this: (CUtlMemory<tagACCEL,int> *)&accelerators,
        num: m_Size - accelerators.m_Memory.m_nAllocationCount + 1);
      m_Size = accelerators.m_Size;
      m_pMemory = accelerators.m_Memory.m_pMemory;
      v24 = menuHelp;
    }
    accelerators.m_Size = ++m_Size;
    accelerators.m_pElements = m_pMemory;
    if ( m_Size - v25 - 1 > 0 )
    {
      _V_memmove(dest: &m_pMemory[v25 + 1], src: &m_pMemory[v25], count: 6 * (m_Size - v25 - 1));
      m_pMemory = accelerators.m_Memory.m_pMemory;
      v24 = menuHelp;
    }
    v26 = &m_pMemory[v25];
    if ( v26 != nullptr )
      *v26 = accel;
    v24 = (mxMenu *)((char *)v24 + 6);
    menuHelp = v24;
  }
  while ( (int)v24 < (int)&unk_5E24AE );
  mx::createAccleratorTable(numentries: m_Size, entries: m_pMemory);
  if ( g_HlmvIpcServer.m_hThread == nullptr || g_HlmvIpcServer.m_bRunning == 0 )
  {
    if ( CValveIpcServer::Register(this: &g_HlmvIpcServer) == 0
      || g_HlmvIpcServer.m_hThread != nullptr
      || (Thread = CreateThread(
                     lpThreadAttributes: nullptr,
                     dwStackSize: 0,
                     lpStartAddress: (LPTHREAD_START_ROUTINE)CValveIpcServer::RunDelegate,
                     lpParameter: &g_HlmvIpcServer,
                     dwCreationFlags: 4u,
                     lpThreadId: nullptr),
          g_HlmvIpcServer.m_hThread = Thread,
          Thread == nullptr)
      || (g_HlmvIpcServer.m_bRunning = 1, ResumeThread(hThread: Thread), g_HlmvIpcServer.m_hThread == nullptr)
      || g_HlmvIpcServer.m_bRunning == 0 )
    {
      CValveIpcServer::Unregister(this: &g_HlmvIpcServer);
    }
  }
  if ( g_HlmvIpcServer.m_hThread == nullptr || g_HlmvIpcServer.m_bRunning == 0 )
  {
    mxMenu::addSeparator(this: this->menuOptions);
    mxMenu::add(this: this->menuOptions, item: "Link HLMV", id: 1111);
    mxMenu::add(this: this->menuOptions, item: "Unlink HLMV", id: 1112);
    mxMenu::setChecked(this: this->menuOptions, id: 1112, b: true);
    mxMenu::setEnabled(this: (mxMenuBar *)this->menuOptions, id: 1112, b: false);
  }
  if ( accelerators.m_Memory.m_nGrowSize >= 0 && accelerators.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: accelerators.m_Memory.m_pMemory);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0041BB80
// Name: public: virtual int CHLModelViewerApp::Main(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CHLModelViewerApp::Main(CHLModelViewerApp *this)
{
  bool v1; // bl
  int v2; // eax
  MDLViewer *v3; // eax
  MDLViewer *v4; // eax
  int v5; // eax
  int v6; // edi
  int v7; // eax
  const char *v8; // eax
  const char *v9; // edi
  int v10; // eax
  int v11; // eax
  int v12; // esi
  char absPath[260]; // [esp+Ch] [ebp-104h] BYREF

  g_pMaterialSystem->ModInit(this: g_pMaterialSystem);
  g_pDataCache->SetSize(this: g_pDataCache, a2: 0x4000000);
  v1 = g_pFullFileSystem->FileExists(this: &g_pFullFileSystem->IBaseFileSystem, a2: "p4lib.dll", a3: "EXECUTABLE_PATH");
  v2 = _CommandLine();
  if ( (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v2 + 40))(a1: v2, a2: "-nop4") != 0 || !v1 )
    CP4Factory::SetDummyMode(this: g_p4factory, bDummyMode: true);
  CP4Factory::SetOpenFileChangeList(this: g_p4factory, szChangeListName: "HLMV Auto Checkout");
  v3 = (MDLViewer *)operator new(nSize: 0x20u);
  if ( v3 != nullptr )
    v4 = MDLViewer::MDLViewer(this: v3);
  else
    v4 = nullptr;
  g_MDLViewer = v4;
  mxWindow::setMenuBar(this: v4, menuBar: v4->mb);
  StudioModel::Init();
  g_pStudioModel->ModelInit(this: g_pStudioModel);
  StudioModel::ClearLookTargets(this: g_pStudioModel);
  (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 232))(
    a1: g_pDataModel.u,
    a2: 0);
  v5 = _CommandLine();
  v6 = (*(int (__thiscall **)(int))(*(_DWORD *)v5 + 36))(a1: v5);
  if ( v6 > 1 )
  {
    v7 = _CommandLine();
    v8 = (const char *)(*(int (__thiscall **)(int, int))(*(_DWORD *)v7 + 44))(a1: v7, a2: v6 - 1);
    v9 = v8;
    if ( v8 != nullptr && V_stristr(pStr: v8, pSearch: ".mdl") != nullptr )
    {
      V_MakeAbsolutePath(pOut: absPath, outLen: 260, pPath: v9, pStartingDir: nullptr);
      v10 = _CommandLine();
      if ( (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v10 + 40))(a1: v10, a2: "-screenshot") != 0 )
      {
        MDLViewer::SaveScreenShot(this: g_MDLViewer, pszFile: absPath);
      }
      else
      {
        v11 = _CommandLine();
        if ( (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v11 + 40))(a1: v11, a2: "-dump") != 0 )
          MDLViewer::DumpText(this: g_MDLViewer, pszFile: absPath);
        else
          MDLViewer::LoadModelFile(this: g_MDLViewer, pszFile: absPath, slot: 0xFFFFFFFF);
      }
    }
  }
  v12 = mx::run();
  StudioModel::Shutdown();
  g_pMaterialSystem->ModShutdown(this: g_pMaterialSystem);
  return v12;
}

//------------------------------------------------------------------------------
// Address: 0x0041BD40
// Name: public: CHlmvIpcServer::~CHlmvIpcServer(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHlmvIpcServer::~CHlmvIpcServer(CHlmvIpcServer *this)
{
  int v2; // edi
  char **m_pMemory; // eax

  v2 = 0;
  for ( this->__vftable = (CHlmvIpcServer_vtbl *)&CHlmvIpcServer::`vftable'; v2 < this->m_lstCommands.m_Size; ++v2 )
    free(pMem: this->m_lstCommands.m_Memory.m_pMemory[v2]);
  this->m_lstCommands.m_Size = 0;
  if ( this->m_lstCommands.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_lstCommands.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_lstCommands.m_Memory.m_pMemory);
      this->m_lstCommands.m_Memory.m_pMemory = nullptr;
    }
    this->m_lstCommands.m_Memory.m_nAllocationCount = 0;
  }
  this->m_lstCommands.m_pElements = this->m_lstCommands.m_Memory.m_pMemory;
  this->m_lstCommands.m_Size = 0;
  if ( this->m_lstCommands.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_lstCommands.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_lstCommands.m_Memory.m_pMemory);
      this->m_lstCommands.m_Memory.m_pMemory = nullptr;
    }
    this->m_lstCommands.m_Memory.m_nAllocationCount = 0;
  }
  m_pMemory = this->m_lstCommands.m_Memory.m_pMemory;
  this->m_lstCommands.m_pElements = m_pMemory;
  if ( this->m_lstCommands.m_Memory.m_nGrowSize >= 0 )
  {
    if ( m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
      this->m_lstCommands.m_Memory.m_pMemory = nullptr;
    }
    this->m_lstCommands.m_Memory.m_nAllocationCount = 0;
  }
  this->__vftable = (CHlmvIpcServer_vtbl *)&CValveIpcServer::`vftable';
  CValveIpcServer::Unregister(this);
  if ( this->m_szServerName != nullptr )
  {
    free(pMem: this->m_szServerName);
    this->m_szServerName = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041BE10
// Name: public: void CHlmvIpcServer::AppendCommand(char __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHlmvIpcServer::AppendCommand(CHlmvIpcServer *this, char *pszCommand)
{
  CThreadFastMutex *p_m_mtx; // ebx
  DWORD CurrentThreadId; // ecx
  int m_Size; // edi
  int m_nAllocationCount; // eax
  char **m_pMemory; // ecx
  int v8; // eax
  char **v9; // edi

  p_m_mtx = &this->m_mtx;
  CurrentThreadId = GetCurrentThreadId();
  if ( CurrentThreadId != p_m_mtx->m_ownerID
    && _InterlockedCompareExchange((volatile signed __int32 *)p_m_mtx, CurrentThreadId, 0) != 0 )
  {
    _mm_pause();
    CThreadFastMutex::Lock(a1: p_m_mtx, a2: CurrentThreadId, a3: 0);
  }
  else
  {
    ++p_m_mtx->m_depth;
  }
  m_Size = this->m_lstCommands.m_Size;
  m_nAllocationCount = this->m_lstCommands.m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<IDmFormatUpdater *,int>::Grow(
      this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&this->m_lstCommands,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_lstCommands.m_Size;
  m_pMemory = this->m_lstCommands.m_Memory.m_pMemory;
  v8 = this->m_lstCommands.m_Size - m_Size - 1;
  this->m_lstCommands.m_pElements = m_pMemory;
  if ( v8 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v8);
  v9 = &this->m_lstCommands.m_Memory.m_pMemory[m_Size];
  if ( v9 != nullptr )
    *v9 = pszCommand;
  if ( p_m_mtx->m_depth-- == 1 )
    _InterlockedExchange((volatile __int32 *)p_m_mtx, 0);
}

//------------------------------------------------------------------------------
// Address: 0x0041BEB0
// Name: protected: virtual int CHlmvIpcServer::ExecuteCommand(class CUtlBuffer __near &,class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CHlmvIpcServer::ExecuteCommand(CHlmvIpcServer *this, CUtlBuffer *cmd, CUtlBuffer *res)
{
  unsigned __int8 *m_pMemory; // ebx
  signed int v4; // esi
  unsigned __int8 *v6; // edi

  m_pMemory = cmd->m_Memory.m_pMemory;
  v4 = strlen((const char *)cmd->m_Memory.m_pMemory);
  if ( v4 <= 0 )
    return 0;
  while ( isspace(c: (char)m_pMemory[v4 - 1]) != 0 )
  {
    if ( --v4 <= 0 )
      return 0;
  }
  v6 = (unsigned __int8 *)operator new(nSize: v4 + 1);
  memcpy(dst: v6, src: m_pMemory, count: v4);
  v6[v4] = 0;
  CHlmvIpcServer::AppendCommand(this, pszCommand: (char *)v6);
  if ( (res->m_Flags & 1) != 0 )
    CUtlBuffer::Printf(this: res, pFmt: "%d", 0);
  else
    CUtlBuffer::PutTypeBin<int>(this: res, src: 0);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0041BFD0
// Name: public: void CUtlDict<int,unsigned short>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlDict<int,unsigned short>::RemoveAll(CUtlDict<int,unsigned short> *this)
{
  unsigned __int16 i; // si

  for ( i = CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::FirstInorder(this: &this->m_Elements.m_Tree);
        i != 0xFFFF;
        i = CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::NextInorder(
              this: &this->m_Elements.m_Tree,
              i) )
  {
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)this->m_Elements.m_Tree.m_Elements.m_pMemory[i].m_Data.key);
  }
  CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::RemoveAll(this: &this->m_Elements.m_Tree);
}

//------------------------------------------------------------------------------
// Address: 0x0041C030
// Name: _main
// Source: json
//------------------------------------------------------------------------------
int __cdecl main(int argc, const char **argv, const char **envp)
{
  void (__thiscall ***v3)(_DWORD, int, const char **); // eax
  int v4; // esi
  CHLModelViewerApp hlmodelviewerApp; // [esp+108h] [ebp-1DCh] BYREF
  CSteamApplication steamApplication; // [esp+274h] [ebp-70h] BYREF

  v3 = (void (__thiscall ***)(_DWORD, int, const char **))_CommandLine();
  (**v3)(a1: v3, a2: argc, a3: argv);
  mx::init(argc, (char **)argv);
  strlen(mx::getApplicationPath());
  SetSuggestGameInfoDirFn(pfnNewFn: (bool (__cdecl *)(const CFSSteamSetupInfo *, char *, int, bool *))CHLModelViewerApp_SuggestGameInfoDirFn);
  CSteamAppSystemGroup::CSteamAppSystemGroup(this: &hlmodelviewerApp, pFileSystem: nullptr, pAppSystemParent: nullptr);
  hlmodelviewerApp.__vftable = (CHLModelViewerApp_vtbl *)&CHLModelViewerApp::`vftable';
  CSteamApplication::CSteamApplication(this: &steamApplication, pAppSystemGroup: &hlmodelviewerApp);
  v4 = CAppSystemGroup::Run(this: &steamApplication);
  CUtlDict<int,unsigned short>::RemoveAll(this: &steamApplication.m_SystemDict);
  CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::~CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>(this: &steamApplication.m_SystemDict.m_Elements.m_Tree);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&steamApplication.m_NonAppSystemFactories);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&steamApplication.m_Systems);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&steamApplication.m_Modules);
  CUtlDict<int,unsigned short>::RemoveAll(this: &hlmodelviewerApp.m_SystemDict);
  CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::~CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>(this: &hlmodelviewerApp.m_SystemDict.m_Elements.m_Tree);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&hlmodelviewerApp.m_NonAppSystemFactories);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&hlmodelviewerApp.m_Systems);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&hlmodelviewerApp.m_Modules);
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x0042B310
// Name: protected: static void __near * (*CAppSystemGroup::GetFactory(void))(char const __near *,int __near *)
// Source: json
//------------------------------------------------------------------------------
void *(__cdecl *__cdecl CAppSystemGroup::GetFactory())(const char *, int *)
{
  return AppSystemCreateInterfaceFn;
}

//------------------------------------------------------------------------------
// Address: 0x004719B0
// Name: public: void CUtlDict<class CDmElementFactoryHelper __near *,int>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlDict<CDmElementFactoryHelper *,int>::RemoveAll(CUtlDict<CDmElementFactoryHelper *,int> *this)
{
  int i; // esi

  for ( i = CUtlRBTree<CUtlMap<char const *,CDmElementFactoryHelper *,int>::Node_t,int,CUtlMap<char const *,CDmElementFactoryHelper *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CDmElementFactoryHelper *,int>::Node_t,int>,int>>::FirstInorder(this: &this->m_Elements.m_Tree);
        i != -1;
        i = CUtlRBTree<CUtlMap<char const *,CDmElementFactoryHelper *,int>::Node_t,int,CUtlMap<char const *,CDmElementFactoryHelper *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CDmElementFactoryHelper *,int>::Node_t,int>,int>>::NextInorder(
              this: &this->m_Elements.m_Tree,
              i) )
  {
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)this->m_Elements.m_Tree.m_Elements.m_pMemory[i].m_Data.key);
  }
  CUtlRBTree<CUtlMap<char const *,CDmElementFactoryHelper *,int>::Node_t,int,CUtlMap<char const *,CDmElementFactoryHelper *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CDmElementFactoryHelper *,int>::Node_t,int>,int>>::RemoveAll(this: &this->m_Elements.m_Tree);
}

//------------------------------------------------------------------------------
// Address: 0x004733F0
// Name: public: int CUtlDict<class CDmElementFactoryHelper __near *,int>::Insert(char const __near *,class CDmElementFactoryHelper __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlDict<CDmElementFactoryHelper *,int>::Insert(
        CUtlDict<CDmElementFactoryHelper *,int> *this,
        char *pName,
        CDmElementFactoryHelper *const *element)
{
  const char *v3; // edi
  char *v5; // eax

  v3 = pName;
  if ( pName != nullptr && (v5 = (char *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: strlen(pName) + 1)) != nullptr )
    strcpy(v5, v3);
  else
    v5 = nullptr;
  pName = v5;
  return CUtlMap<char const *,CDmElementFactoryHelper *,int>::Insert(
           this: &this->m_Elements,
           key: (const char *const *)&pName,
           insert: element);
}

//------------------------------------------------------------------------------
// Address: 0x00489A00
// Name: public: void CUtlDict<class CDmElement __near *,int>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlDict<CDmElement *,int>::RemoveAll(CUtlDict<CDmElement *,int> *this)
{
  int i; // esi

  for ( i = CUtlRBTree<CUtlMap<char const *,CDmElement *,int>::Node_t,int,CUtlMap<char const *,CDmElement *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CDmElement *,int>::Node_t,int>,int>>::FirstInorder(this: &this->m_Elements.m_Tree);
        i != -1;
        i = CUtlRBTree<CUtlMap<char const *,CDmElement *,int>::Node_t,int,CUtlMap<char const *,CDmElement *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CDmElement *,int>::Node_t,int>,int>>::NextInorder(
              this: &this->m_Elements.m_Tree,
              i) )
  {
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)this->m_Elements.m_Tree.m_Elements.m_pMemory[i].m_Data.key);
  }
  CUtlRBTree<CUtlMap<char const *,CDmElement *,int>::Node_t,int,CUtlMap<char const *,CDmElement *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CDmElement *,int>::Node_t,int>,int>>::RemoveAll(this: &this->m_Elements.m_Tree);
}

//------------------------------------------------------------------------------
// Address: 0x0048B110
// Name: public: int CUtlDict<class CDmElement __near *,int>::Insert(char const __near *,class CDmElement __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlDict<CDmElement *,int>::Insert(
        CUtlDict<CDmElement *,int> *this,
        char *pName,
        CDmElement *const *element)
{
  const char *v3; // edi
  char *v5; // eax

  v3 = pName;
  if ( pName != nullptr && (v5 = (char *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: strlen(pName) + 1)) != nullptr )
    strcpy(v5, v3);
  else
    v5 = nullptr;
  pName = v5;
  return CUtlMap<char const *,CDmElement *,int>::Insert(
           this: &this->m_Elements,
           key: (const char *const *)&pName,
           insert: element);
}

//------------------------------------------------------------------------------
// Address: 0x0041C110
// Name: void __near * operator new(unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void *__cdecl operator new(unsigned int nSize)
{
  return _g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: nSize);
}
