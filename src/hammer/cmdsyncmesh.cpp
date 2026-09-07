// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: hammer/cmdsyncmesh.cpp
// Functions: 206
// ============================================================

#include "hammer\cmdsyncmesh.h"

//------------------------------------------------------------------------------
// Address: 0x1000DE30
// Name: void ATL::AtlThrowImpl(long)
// Source: json
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x1000DE50
// Name: struct ATL::ATLSTRINGRESOURCEIMAGE const __near * ATL::_AtlGetStringResourceImage(struct HINSTANCE__ __near *,struct HRSRC__ __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
ATL::ATLSTRINGRESOURCEIMAGE *__cdecl ATL::_AtlGetStringResourceImage(
        HINSTANCE__ *hInstance,
        HRSRC__ *hResource,
        char id)
{
  ATL::ATLSTRINGRESOURCEIMAGE *result; // eax
  _WORD *v4; // esi
  unsigned int v5; // eax
  int v6; // ecx

  result = (ATL::ATLSTRINGRESOURCEIMAGE *)LoadResource(hModule: hInstance, hResInfo: hResource);
  if ( result != nullptr )
  {
    v4 = LockResource(hResData: result);
    if ( v4 == nullptr )
      return nullptr;
    v5 = (unsigned int)v4 + SizeofResource(hModule: hInstance, hResInfo: hResource);
    v6 = id & 0xF;
    if ( (id & 0xF) != 0 )
    {
      while ( (unsigned int)v4 < v5 )
      {
        --v6;
        v4 += (unsigned __int16)*v4 + 1;
        if ( v6 == 0 )
          goto LABEL_6;
      }
      return nullptr;
    }
LABEL_6:
    if ( (unsigned int)v4 >= v5 )
      return nullptr;
    return *v4 != 0 ? (ATL::ATLSTRINGRESOURCEIMAGE *)v4 : nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1000DEC0
// Name: struct ATL::ATLSTRINGRESOURCEIMAGE const __near * ATL::AtlGetStringResourceImage(struct HINSTANCE__ __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
ATL::ATLSTRINGRESOURCEIMAGE *__cdecl ATL::AtlGetStringResourceImage(HINSTANCE__ *hInstance, unsigned int id)
{
  ATL::ATLSTRINGRESOURCEIMAGE *result; // eax

  result = (ATL::ATLSTRINGRESOURCEIMAGE *)FindResourceW(
                                            hModule: hInstance,
                                            lpName: (LPCWSTR)(unsigned __int16)((id >> 4) + 1),
                                            lpType: (LPCWSTR)6);
  if ( result != nullptr )
    return ATL::_AtlGetStringResourceImage(hInstance, hResource: (HRSRC__ *)result, id);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1000DF00
// Name: public: char const __near * CEditGameClass::GetKeyValue(char const __near *,int __near *)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CEditGameClass::GetKeyValue(CEditGameClass *this, const char *pszKey, int *piIndex)
{
  return WCKeyValuesT<WCKVBase_Dict>::GetValue(this: &this->m_KeyValues, pszKey, piIndex);
}

//------------------------------------------------------------------------------
// Address: 0x1000DF10
// Name: public: bool CEditGameClass::IsClass(char const __near *)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CEditGameClass::IsClass(CEditGameClass *this, const char *pszClass)
{
  if ( pszClass == nullptr )
    return this->m_pClass != nullptr;
  return this->m_pClass != nullptr && _V_stricmp(s1: pszClass, s2: this->m_szClass) == 0;
}

//------------------------------------------------------------------------------
// Address: 0x1000DF50
// Name: public: static class CMapDoc __near * CMapDoc::GetActiveMapDoc(void)
// Source: json
//------------------------------------------------------------------------------
CMapDoc *__cdecl CMapDoc::GetActiveMapDoc()
{
  return CMapDoc::m_pMapDoc;
}

//------------------------------------------------------------------------------
// Address: 0x1000DF60
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
    v2 = (char *)&var;
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
// Address: 0x1000DFD0
// Name: public: int CValveIpcMgr::Iterator::IsValid(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CValveIpcMgr::Iterator::IsValid(CValveIpcMgr::Iterator *this)
{
  GUID *v1; // eax
  unsigned int v2; // edx
  int v3; // ecx

  if ( this->m_szServerName == nullptr || *this->m_szServerName == 0 )
    return 0;
  v1 = &GUID_NULL;
  v2 = 16;
  v3 = (char *)&this->m_uuid - (char *)&GUID_NULL;
  while ( *(unsigned int *)((char *)&v1->Data1 + v3) == v1->Data1 )
  {
    v2 -= 4;
    v1 = (GUID *)((char *)v1 + 4);
    if ( v2 < 4 )
      return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1000E010
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
    v9.m_szServerName = (char *)&var;
    v6 = &v9;
  }
  v7 = *(_DWORD *)&v6->m_uuid.Data4[4];
  *(_QWORD *)&result->m_szServerName = *(_QWORD *)&v6->m_szServerName;
  *(_QWORD *)&result->m_uuid.Data2 = *(_QWORD *)&v6->m_uuid.Data2;
  *(_DWORD *)&result->m_uuid.Data4[4] = v7;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1000E0B0
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
// Address: 0x1000E110
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
// Address: 0x1000E160
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
// Address: 0x1000E220
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
      v13.m_szServerName = (char *)&var;
      memmove(dst: v9, src: (unsigned __int8 *)&var, count: 1u);
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
// Address: 0x1000E440
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
  itNext.m_szServerName = (char *)&var;
  CValveIpcMgr::Iterator::WriteIntoMemory(this: &itNext, pMemory: (char *)m_szServerName);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1000E5B0
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
// Address: 0x1000E600
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
  v4 = (char *)operator new[](nSize: v3 + 1);
  this->m_szServerName = v4;
  v5 = szServerName;
  if ( szServerName == nullptr )
    v5 = &var;
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
// Address: 0x1000E680
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
// Address: 0x1000E6D0
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
// Address: 0x1000E760
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
// Address: 0x1000E7F0
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
// Address: 0x1000E890
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
// Address: 0x1000E910
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
  v4 = (char *)operator new[](nSize: v3 + 1);
  this->m_szServerName = v4;
  v5 = szServerName;
  if ( szServerName == nullptr )
    v5 = &var;
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
// Address: 0x1000E970
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
// Address: 0x1000E9C0
// Name: void SwitchActiveWindow(struct HWND__ __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SwitchActiveWindow(HWND__ *hWndActivate)
{
  HWND ForegroundWindow; // eax
  DWORD WindowThreadProcessId; // esi
  DWORD v3; // eax
  DWORD v4; // edi

  ForegroundWindow = GetForegroundWindow();
  if ( hWndActivate != ForegroundWindow )
  {
    WindowThreadProcessId = GetWindowThreadProcessId(hWnd: ForegroundWindow, lpdwProcessId: nullptr);
    v3 = GetWindowThreadProcessId(hWnd: hWndActivate, lpdwProcessId: nullptr);
    v4 = v3;
    if ( v3 != WindowThreadProcessId )
      AttachThreadInput(idAttach: WindowThreadProcessId, idAttachTo: v3, fAttach: true);
    SetForegroundWindow(hWnd: hWndActivate);
    BringWindowToTop(hWnd: hWndActivate);
    if ( v4 != WindowThreadProcessId )
      AttachThreadInput(idAttach: WindowThreadProcessId, idAttachTo: v4, fAttach: false);
    if ( IsIconic(hWnd: hWndActivate) )
      ShowWindow(hWnd: hWndActivate, nCmdShow: 9);
    else
      ShowWindow(hWnd: hWndActivate, nCmdShow: 5);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000EA40
// Name: class CWnd __near * AfxGetMainWnd(void)
// Source: json
//------------------------------------------------------------------------------
CWnd *__stdcall AfxGetMainWnd()
{
  CWinThread *Thread; // eax

  Thread = AfxGetThread();
  if ( Thread != nullptr )
    return Thread->GetMainWnd(this: Thread);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1000EA60
// Name: protected: int CToolHandler_SyncMesh::CreateTempDoc(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CToolHandler_SyncMesh::CreateTempDoc(CToolHandler_SyncMesh *this)
{
  CDocTemplate *NextDocTemplate; // eax
  CMapDoc_Friendly *v4; // eax
  __POSITION *pos; // [esp+4h] [ebp-4h] BYREF

  pos = CWinApp::GetFirstDocTemplatePosition(this: this->m_pApp);
  if ( pos == nullptr )
    return false;
  NextDocTemplate = CWinApp::GetNextDocTemplate(this: this->m_pApp, rPosition: &pos);
  if ( NextDocTemplate == nullptr )
    return false;
  v4 = (CMapDoc_Friendly *)NextDocTemplate->OpenDocumentFile(this: NextDocTemplate, a2: nullptr, a3: 1);
  this->m_pTempDoc = v4;
  return v4 != nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1000EAC0
// Name: protected: int CToolHandler_SyncMesh::PasteSelToTempDoc(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CToolHandler_SyncMesh::PasteSelToTempDoc(CToolHandler_SyncMesh *this)
{
  CMapDoc_Friendly *m_pTempDoc; // ecx
  bool m_bSnapToGrid; // bl
  CMapDoc_Friendly *v4; // ecx
  QAngle v6[2]; // [esp-18h] [ebp-44h] BYREF
  Vector vecSelCenter; // [esp+8h] [ebp-24h] BYREF
  __int64 v8; // [esp+14h] [ebp-18h]
  int v9; // [esp+1Ch] [ebp-10h]
  Vector vecPasteOffset; // [esp+20h] [ebp-Ch] BYREF

  m_pTempDoc = this->m_pTempDoc;
  m_bSnapToGrid = m_pTempDoc->m_bSnapToGrid;
  if ( m_bSnapToGrid )
    CMapDoc::OnMapSnaptogrid(this: m_pTempDoc);
  CSelection::GetBoundsCenter(this: this->m_pSelection, vecCenter: &vecSelCenter);
  vecPasteOffset.x = -vecSelCenter.x;
  vecPasteOffset.y = -vecSelCenter.y;
  vecPasteOffset.z = -vecSelCenter.z;
  if ( !s_opt_maya_bMeshAtOrigin )
    memset(&vecPasteOffset, 0, sizeof(vecPasteOffset));
  v4 = this->m_pTempDoc;
  v9 = 0;
  v8 = 0;
  memset(v6, 0, 12);
  CMapDoc::Paste(
    this: v4,
    pClipboard: this->m_pCopiedObjects,
    pDestWorld: v4->m_pWorld,
    vecOffset: vecPasteOffset,
    vecRotate: v6[0],
    pParent: nullptr,
    bMakeEntityNamesUnique: false,
    pszEntityNamePrefix: nullptr);
  if ( m_bSnapToGrid )
    CMapDoc::OnMapSnaptogrid(this: this->m_pTempDoc);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1000EBB0
// Name: protected: int CToolHandler_SyncMesh::CloseTempDoc(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CToolHandler_SyncMesh::CloseTempDoc(CToolHandler_SyncMesh *this)
{
  IHammerClipboard *m_pCopiedObjects; // ecx
  CMapDoc_Friendly *m_pTempDoc; // ecx

  m_pCopiedObjects = this->m_pCopiedObjects;
  if ( m_pCopiedObjects != nullptr )
  {
    m_pCopiedObjects->Destroy(this: m_pCopiedObjects);
    this->m_pCopiedObjects = nullptr;
  }
  m_pTempDoc = this->m_pTempDoc;
  if ( m_pTempDoc != nullptr )
  {
    m_pTempDoc->SetModifiedFlag(this: m_pTempDoc, a2: 0);
    CDocument::OnFileClose(this: this->m_pTempDoc);
  }
  if ( this->m_pView != nullptr )
    CMapDoc::SetActiveView(this: this->m_pDoc, pViewActivate: this->m_pView);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1000EC10
// Name: protected: virtual int CTextureBrowser_Async::DoModal(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CTextureBrowser_Async::DoModal(CTextureBrowser_Async *this)
{
  int v2; // edi

  v2 = CDialog::DoModal(this);
  this->OnResult(this, a2: v2);
  ((void (__thiscall *)(CTextureBrowser_Async *, int))this->dtr_CObject)(a1: this, a2: 1);
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x1000EC40
// Name: public: virtual char const __near * CSyncMesh_SaveLoadHandler::GetCustomSectionName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CSyncMesh_SaveLoadHandler::GetCustomSectionName(CSyncMesh_SaveLoadHandler *this)
{
  return "meshdata";
}

//------------------------------------------------------------------------------
// Address: 0x1000EC50
// Name: public: CAutoLockT<class CThreadFastMutex>::~CAutoLockT<class CThreadFastMutex>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAutoLockT<CThreadFastMutex>::~CAutoLockT<CThreadFastMutex>(CAutoLockT<CThreadFastMutex> *this)
{
  CThreadFastMutex *m_lock; // eax

  m_lock = this->m_lock;
  if ( this->m_lock->m_depth-- == 1 )
    _InterlockedExchange((volatile __int32 *)m_lock, 0);
}

//------------------------------------------------------------------------------
// Address: 0x1000EC70
// Name: public: CAutoPushPop<int>::~CAutoPushPop<int>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAutoPushPop<int>::~CAutoPushPop<int>(CAutoPushPop<int> *this)
{
  *this->m_rVar = this->m_valPop;
}

//------------------------------------------------------------------------------
// Address: 0x1000ED50
// Name: private: void ATL::CSimpleStringT<char,0>::SetLength(int)
// Source: json
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x1000ED80
// Name: public: static void ATL::ChTraitsCRT<char>::ConvertToBaseType(char __near *,int,wchar_t const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ATL::ChTraitsCRT<char>::ConvertToBaseType(
        char *pszDest,
        int nDestLength,
        const wchar_t *pszSrc,
        int nSrcLength)
{
  WideCharToMultiByte(
    CodePage: 3u,
    dwFlags: 0,
    lpWideCharStr: pszSrc,
    cchWideChar: nSrcLength,
    lpMultiByteStr: pszDest,
    cbMultiByte: nDestLength,
    lpDefaultChar: nullptr,
    lpUsedDefaultChar: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x1000EDB0
// Name: protected: static void ATL::CSimpleStringT<char,0>::ThrowMemoryException(void)
// Source: json
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x1000EDC0
// Name: private: static struct ATL::CStringData __near * ATL::CSimpleStringT<char,0>::CloneData(struct ATL::CStringData __near *)
// Source: json
//------------------------------------------------------------------------------
ATL::CStringData *__cdecl ATL::CSimpleStringT<char,0>::CloneData(ATL::CStringData *pData)
{
  ATL::IAtlStringMgr *v1; // eax
  int v3; // eax
  int v4; // edi

  v1 = pData->pStringMgr->Clone(this: pData->pStringMgr);
  if ( pData->nRefs >= 0 && v1 == pData->pStringMgr )
  {
    _InterlockedExchangeAdd(&pData->nRefs, 1u);
    return pData;
  }
  else
  {
    v3 = v1->Allocate(this: v1, a2: pData->nDataLength, a3: 1);
    v4 = v3;
    if ( v3 == 0 )
      ATL::CSimpleStringT<char,0>::ThrowMemoryException();
    *(_DWORD *)(v3 + 4) = pData->nDataLength;
    memcpy_s(dst: (void *)(v3 + 16), sizeInBytes: pData->nDataLength + 1, src: &pData[1], count: pData->nDataLength + 1);
    return (ATL::CStringData *)v4;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000EE30
// Name: public: static int ATL::ChTraitsCRT<char>::GetBaseTypeLength(wchar_t const __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ATL::ChTraitsCRT<char>::GetBaseTypeLength(const wchar_t *pszSource, int nLength)
{
  return WideCharToMultiByte(
           CodePage: 3u,
           dwFlags: 0,
           lpWideCharStr: pszSource,
           cchWideChar: nLength,
           lpMultiByteStr: nullptr,
           cbMultiByte: 0,
           lpDefaultChar: nullptr,
           lpUsedDefaultChar: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x1000EE50
// Name: private: void ATL::CSimpleStringT<char,0>::Fork(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ATL::CSimpleStringT<char,0>::Fork(ATL::CSimpleStringT<char,0> *this, int nLength)
{
  int v2; // ebx
  volatile signed __int32 *v3; // esi
  int (__thiscall ***v4)(_DWORD, int, int); // eax
  int v5; // edi
  int v6; // eax

  v2 = *((_DWORD *)this->m_pszData - 3);
  v3 = (volatile signed __int32 *)(this->m_pszData - 16);
  v4 = (int (__thiscall ***)(_DWORD, int, int))(*(int (__thiscall **)(volatile signed __int32))(**(_DWORD **)v3 + 16))(a1: *v3);
  v5 = (**v4)(a1: v4, a2: nLength, a3: 1);
  if ( v5 == 0 )
    ATL::CSimpleStringT<char,0>::ThrowMemoryException();
  v6 = nLength;
  if ( v2 < nLength )
    v6 = v2;
  memcpy_s(dst: (void *)(v5 + 16), sizeInBytes: v6 + 1, src: (const void *)(v3 + 4), count: v6 + 1);
  *(_DWORD *)(v5 + 4) = v2;
  if ( _InterlockedDecrement(v3 + 3) <= 0 )
    (*(void (__stdcall **)(volatile signed __int32 *))(**(_DWORD **)v3 + 4))(a1: v3);
  this->m_pszData = (char *)(v5 + 16);
}

//------------------------------------------------------------------------------
// Address: 0x1000EED0
// Name: private: void ATL::CSimpleStringT<char,0>::Reallocate(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ATL::CSimpleStringT<char,0>::Reallocate(ATL::CSimpleStringT<char,0> *this, int nLength)
{
  char *m_pszData; // eax
  int v4; // ecx
  char *v5; // eax
  int v6; // eax

  m_pszData = this->m_pszData;
  v4 = *((_DWORD *)this->m_pszData - 4);
  v5 = m_pszData - 16;
  if ( *((_DWORD *)v5 + 2) >= nLength
    || nLength <= 0
    || (v6 = (*(int (__thiscall **)(int, char *, int, int))(*(_DWORD *)v4 + 8))(a1: v4, a2: v5, a3: nLength, a4: 1)) == 0 )
  {
    ATL::CSimpleStringT<char,0>::ThrowMemoryException(a1: v4);
  }
  this->m_pszData = (char *)(v6 + 16);
}

//------------------------------------------------------------------------------
// Address: 0x1000EF10
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
// Address: 0x1000EF70
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
// Address: 0x1000F030
// Name: public: int CValveIpcServer::Unregister(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CValveIpcServer::Unregister(CValveIpcServer *this)
{
  unsigned __int8 **p_m_szServerUID; // ebx
  void *m_hThread; // eax
  void *m_hServerPipe; // eax
  RPC_CSTR *v6; // esi
  char *m_pBufferWrite; // [esp-8h] [ebp-30h]
  char *m_pBufferRead; // [esp-4h] [ebp-2Ch]
  CValveIpcMgr mgr; // [esp+Ch] [ebp-1Ch] BYREF
  RPC_CSTR *String; // [esp+18h] [ebp-10h]
  int v11; // [esp+24h] [ebp-4h]

  p_m_szServerUID = &this->m_szServerUID;
  String = &this->m_szServerUID;
  if ( this->m_szServerUID == nullptr )
    return 0;
  memset(&mgr, 0, sizeof(mgr));
  v11 = 0;
  if ( CValveIpcMgr::Init(this: &mgr, dwTimeout: 0x1388u) != 0 )
    CValveIpcMgr::UnregisterServer(this: &mgr, szServerUID: *p_m_szServerUID);
  v11 = -1;
  if ( mgr.m_pMemory != nullptr )
  {
    UnmapViewOfFile(lpBaseAddress: mgr.m_pMemory);
    mgr.m_pMemory = nullptr;
  }
  if ( mgr.m_hMemorySegment != nullptr )
  {
    CloseHandle(hObject: mgr.m_hMemorySegment);
    mgr.m_hMemorySegment = nullptr;
  }
  if ( mgr.m_hMutex != nullptr )
  {
    ReleaseMutex(hMutex: mgr.m_hMutex);
    CloseHandle(hObject: mgr.m_hMutex);
    mgr.m_hMutex = nullptr;
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
  operator delete(p: m_pBufferRead);
  m_pBufferWrite = this->m_pBufferWrite;
  this->m_pBufferRead = nullptr;
  this->m_cbBufferWrite = 0;
  operator delete(p: m_pBufferWrite);
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
// Address: 0x1000F170
// Name: public: static unsigned long CValveIpcServer::RunDelegate(void __near *)
// Source: json
//------------------------------------------------------------------------------
unsigned int __stdcall CValveIpcServer::RunDelegate(CValveIpcServer *lpvParam)
{
  return CValveIpcServer::RunImpl(this: lpvParam);
}

//------------------------------------------------------------------------------
// Address: 0x1000F180
// Name: public: CValveIpcClient::~CValveIpcClient(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CValveIpcClient::~CValveIpcClient(CValveIpcClient *this)
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
    operator delete(p: this->m_szServerName);
    this->m_szServerName = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000F1D0
// Name: public: int CValveIpcClient::Connect(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CValveIpcClient::Connect(CValveIpcClient *this)
{
  const char **p_m_szServerUID; // esi
  HANDLE v3; // eax
  HANDLE FileA; // eax
  char chPipeName[260]; // [esp+Ch] [ebp-224h] BYREF
  char chAliveName[260]; // [esp+110h] [ebp-120h] BYREF
  unsigned int dwPipeMode; // [esp+214h] [ebp-1Ch] BYREF
  CValveIpcMgr mgr; // [esp+218h] [ebp-18h] BYREF
  int v10; // [esp+22Ch] [ebp-4h]

  p_m_szServerUID = (const char **)&this->m_szServerUID;
  if ( this->m_szServerUID != nullptr )
    return 1;
  memset(&mgr, 0, sizeof(mgr));
  v10 = 0;
  if ( CValveIpcMgr::Init(this: &mgr, dwTimeout: 0x1388u) == 0
    || CValveIpcMgr::DiscoverServer(
         this: &mgr,
         szServerName: this->m_szServerName,
         pszServerUID: (unsigned __int8 **)p_m_szServerUID) == 0 )
  {
LABEL_6:
    v10 = -1;
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
  v10 = -1;
  CValveIpcMgr::~CValveIpcMgr(this: &mgr);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1000F300
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
    operator delete(p: this->m_szServerName);
    this->m_szServerName = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000F380
// Name: public: char __near * ATL::CSimpleStringT<char,0>::GetBuffer(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall ATL::CSimpleStringT<char,0>::GetBuffer(ATL::CSimpleStringT<char,0> *this)
{
  char *result; // eax

  result = this->m_pszData;
  if ( *((int *)this->m_pszData - 1) > 1 )
  {
    ATL::CSimpleStringT<char,0>::Fork(this, nLength: *((_DWORD *)result - 3));
    return this->m_pszData;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1000F3A0
// Name: void IntrusiveList::RemoveFromDList<class CUtlReference<class CMapClass>>(class CUtlReference<class CMapClass> __near * __near &,class CUtlReference<class CMapClass> __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl IntrusiveList::RemoveFromDList<CUtlReference<CMapClass>>(
        CUtlReference<CMapClass> **head,
        CUtlReference<CMapClass> *which)
{
  CUtlReference<CMapClass> *m_pPrev; // ecx
  CUtlReference<CMapClass> *m_pNext; // ecx

  m_pPrev = which->m_pPrev;
  if ( m_pPrev != nullptr )
  {
    m_pPrev->m_pNext = which->m_pNext;
    if ( which->m_pNext != nullptr )
    {
      which->m_pNext->m_pPrev = which->m_pPrev;
      which->m_pPrev = nullptr;
      which->m_pNext = nullptr;
      return;
    }
  }
  else if ( *head == which )
  {
    m_pNext = which->m_pNext;
    *head = which->m_pNext;
    if ( m_pNext != nullptr )
      m_pNext->m_pPrev = nullptr;
  }
  which->m_pPrev = nullptr;
  which->m_pNext = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1000F400
// Name: protected: bool CUtlBuffer::GetTypeText<int>(int __near &,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CUtlBuffer::GetTypeText<int>(CUtlBuffer *this, int *value, int nRadix)
{
  char *v5; // esi
  int nLength; // [esp+4h] [ebp-8h] BYREF
  char *pEnd; // [esp+8h] [ebp-4h] BYREF

  nLength = 128;
  if ( !CUtlBuffer::CheckArbitraryPeekGet(this, nOffset: 0, nIncrement: &nLength) )
  {
    *value = 0;
    return 0;
  }
  pEnd = (char *)&this->m_Memory.m_pMemory[this->m_Get - this->m_nOffset];
  v5 = pEnd;
  *value = strtol(nptr: pEnd, endptr: &pEnd, ibase: nRadix);
  if ( pEnd == v5 )
    return 0;
  this->m_Get += pEnd - v5;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1000F470
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
// Address: 0x1000F500
// Name: public: ATL::CSimpleStringT<char,0>::CSimpleStringT<char,0>(struct ATL::IAtlStringMgr __near *)
// Source: json
//------------------------------------------------------------------------------
ATL::CSimpleStringT<char,0> *__thiscall ATL::CSimpleStringT<char,0>::CSimpleStringT<char,0>(
        ATL::CSimpleStringT<char,0> *this,
        ATL::IAtlStringMgr *pStringMgr)
{
  if ( pStringMgr == nullptr )
    ATL::AtlThrowImpl(hr: -2147467259);
  this->m_pszData = (char *)&pStringMgr->GetNilString(this: pStringMgr)[1];
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1000F530
// Name: public: ATL::CSimpleStringT<char,0>::CSimpleStringT<char,0>(char const __near *,int,struct ATL::IAtlStringMgr __near *)
// Source: json
//------------------------------------------------------------------------------
ATL::CSimpleStringT<char,0> *__thiscall ATL::CSimpleStringT<char,0>::CSimpleStringT<char,0>(
        ATL::CSimpleStringT<char,0> *this,
        const char *pchSrc,
        int nLength,
        ATL::IAtlStringMgr *pStringMgr)
{
  int v5; // eax
  int v6; // ecx
  char *v7; // eax

  if ( pStringMgr == nullptr )
    ATL::AtlThrowImpl(hr: -2147467259);
  if ( pchSrc == nullptr && nLength != 0 )
    goto LABEL_5;
  v5 = ((int (__stdcall *)(int, int))pStringMgr->Allocate)(a1: nLength, a2: 1);
  if ( v5 == 0 )
    ATL::CSimpleStringT<char,0>::ThrowMemoryException(a1: v6);
  v7 = (char *)(v5 + 16);
  this->m_pszData = v7;
  if ( nLength < 0 || nLength > *((_DWORD *)v7 - 2) )
LABEL_5:
    ATL::AtlThrowImpl(hr: -2147024809);
  *((_DWORD *)v7 - 3) = nLength;
  this->m_pszData[nLength] = 0;
  memcpy_s(dst: this->m_pszData, sizeInBytes: nLength, src: pchSrc, count: nLength);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1000F5B0
// Name: public: void ATL::CSimpleStringT<char,0>::Empty(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ATL::CSimpleStringT<char,0>::Empty(ATL::CSimpleStringT<char,0> *this)
{
  char *m_pszData; // ecx
  volatile signed __int32 *v3; // eax
  int v4; // edi

  m_pszData = this->m_pszData;
  v3 = (volatile signed __int32 *)(m_pszData - 16);
  v4 = *((_DWORD *)m_pszData - 4);
  if ( *((_DWORD *)m_pszData - 3) != 0 )
  {
    if ( *((int *)v3 + 3) >= 0 )
    {
      if ( _InterlockedDecrement(v3 + 3) <= 0 )
        (*(void (__stdcall **)(volatile signed __int32 *))(**(_DWORD **)v3 + 4))(a1: v3);
      this->m_pszData = (char *)((*(int (__thiscall **)(int))(*(_DWORD *)v4 + 12))(a1: v4) + 16);
    }
    else
    {
      if ( *((int *)m_pszData - 2) < 0 )
        ATL::AtlThrowImpl(hr: -2147024809);
      *((_DWORD *)m_pszData - 3) = 0;
      *this->m_pszData = 0;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000F610
// Name: private: void ATL::CSimpleStringT<char,0>::PrepareWrite2(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ATL::CSimpleStringT<char,0>::PrepareWrite2(ATL::CSimpleStringT<char,0> *this, int nLength)
{
  char *m_pszData; // eax
  int v3; // edi
  int v4; // eax
  int v5; // esi

  m_pszData = this->m_pszData;
  v3 = nLength;
  if ( *((_DWORD *)this->m_pszData - 3) > nLength )
    v3 = *((_DWORD *)this->m_pszData - 3);
  if ( *((int *)m_pszData - 1) <= 1 )
  {
    v4 = *((_DWORD *)m_pszData - 2);
    if ( v4 < v3 )
    {
      if ( v4 <= 0x40000000 )
      {
        v5 = v4 / 2 + v4;
        if ( v5 < v3 )
          v5 = v3;
      }
      else
      {
        v5 = v4 + 0x100000;
        if ( v4 + 0x100000 < v3 )
          v5 = v3;
      }
      ATL::CSimpleStringT<char,0>::Reallocate(this, nLength: v5);
    }
  }
  else
  {
    ATL::CSimpleStringT<char,0>::Fork(this, nLength: v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000F680
// Name: public: CValveIpcServer::~CValveIpcServer(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CValveIpcServer::~CValveIpcServer(CValveIpcServer *this)
{
  this->__vftable = (CValveIpcServer_vtbl *)&CValveIpcServer::`vftable';
  CValveIpcServer::Unregister(this);
  if ( this->m_szServerName != nullptr )
  {
    operator delete(p: this->m_szServerName);
    this->m_szServerName = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000F6B0
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
  unsigned __int8 *v10; // [esp-4h] [ebp-230h]
  char chPipeName[260]; // [esp+Ch] [ebp-220h] BYREF
  char chAliveName[260]; // [esp+110h] [ebp-11Ch] BYREF
  CValveIpcMgr mgr; // [esp+214h] [ebp-18h] BYREF
  int v14; // [esp+228h] [ebp-4h]

  p_m_szServerUID = &this->m_szServerUID;
  if ( this->m_szServerUID != nullptr )
    return 1;
  memset(&mgr, 0, sizeof(mgr));
  v14 = 0;
  if ( CValveIpcMgr::Init(this: &mgr, dwTimeout: 0x1388u) == 0
    || CValveIpcMgr::RegisterServer(this: &mgr, szServerName: this->m_szServerName, pszServerUID: p_m_szServerUID) == 0 )
  {
LABEL_6:
    v14 = -1;
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
        v8 = (char *)operator new[](nSize: 0x10000u);
        this->m_pBufferRead = v8;
        if ( v8 != nullptr )
        {
          v9 = (char *)operator new[](nSize: 0x10000u);
          this->m_pBufferWrite = v9;
          if ( v9 != nullptr )
          {
            v14 = -1;
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
// Address: 0x1000F820
// Name: public: static void CHammerIpcServer::AppShutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CHammerIpcServer::AppShutdown()
{
  CValveIpcServer::Unregister(this: &g_HammerIpcServer);
}

//------------------------------------------------------------------------------
// Address: 0x1000F830
// Name: public: CValveIpcServerUtl::~CValveIpcServerUtl(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CValveIpcServerUtl::~CValveIpcServerUtl(CValveIpcServerUtl *this)
{
  this->__vftable = (CValveIpcServerUtl_vtbl *)&CValveIpcServer::`vftable';
  CValveIpcServer::Unregister(this);
  if ( this->m_szServerName != nullptr )
  {
    operator delete(p: this->m_szServerName);
    this->m_szServerName = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000F890
// Name: protected: int CToolHandler_SyncMesh::Setup(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CToolHandler_SyncMesh::Setup(CToolHandler_SyncMesh *this)
{
  CWinApp *m_pCurrentWinApp; // eax
  CMapDoc *v3; // ecx
  CMapView *ActiveMapView; // eax
  CSelection *m_pSelection; // ecx

  m_pCurrentWinApp = AfxGetModuleState()->m_pCurrentWinApp;
  this->m_pApp = m_pCurrentWinApp;
  if ( m_pCurrentWinApp == nullptr )
    return 0;
  v3 = CMapDoc::m_pMapDoc;
  this->m_pDoc = (CMapDoc_Friendly *)CMapDoc::m_pMapDoc;
  if ( v3 == nullptr )
    return 0;
  ActiveMapView = CMapDoc::GetActiveMapView(this: v3);
  this->m_pView = ActiveMapView;
  if ( ActiveMapView == nullptr )
    return 0;
  m_pSelection = this->m_pDoc->m_pSelection;
  this->m_pSelection = m_pSelection;
  if ( m_pSelection == nullptr
    || CSelection::IsEmpty(this: m_pSelection)
    || CToolManager::GetActiveTool(this: this->m_pSelection) < 1 )
  {
    return 0;
  }
  this->m_pTempDoc = nullptr;
  this->m_pCopiedObjects = nullptr;
  ATL::CSimpleStringT<char,0>::Empty(this: &this->m_strTempFileName);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1000F910
// Name: public: CPlainAutoPtr<char>::~CPlainAutoPtr<char>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPlainAutoPtr<char>::~CPlainAutoPtr<char>(CPlainAutoPtr<char> *this)
{
  char *m_p; // [esp-4h] [ebp-4h]

  m_p = this->m_p;
  this->m_p = nullptr;
  operator delete(p: m_p);
}

//------------------------------------------------------------------------------
// Address: 0x1000F920
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
// Address: 0x1000FA20
// Name: private: char __near * ATL::CSimpleStringT<char,0>::PrepareWrite(int)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall ATL::CSimpleStringT<char,0>::PrepareWrite(ATL::CSimpleStringT<char,0> *this, int nLength)
{
  if ( nLength < 0 )
    ATL::AtlThrowImpl(hr: -2147024809);
  if ( ((*((_DWORD *)this->m_pszData - 2) - nLength) | (1 - *((_DWORD *)this->m_pszData - 1))) < 0 )
    ATL::CSimpleStringT<char,0>::PrepareWrite2(this, nLength);
  return this->m_pszData;
}

//------------------------------------------------------------------------------
// Address: 0x1000FA60
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
// Address: 0x1000FAD0
// Name: public: CUtlBuffer::~CUtlBuffer(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlBuffer::~CUtlBuffer(CUtlBuffer *this)
{
  if ( this->m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      free(pMem: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000FB30
// Name: int ComputeFileHash(char const __near *)
// Source: json
//------------------------------------------------------------------------------
unsigned int __cdecl ComputeFileHash(const char *pszFilename)
{
  unsigned int v1; // edi
  CUtlBuffer bufFile; // [esp+4h] [ebp-3Ch] BYREF
  int v4; // [esp+3Ch] [ebp-4h]

  CUtlBuffer::CUtlBuffer(this: &bufFile, growSize: 0, initSize: 0, nFlags: 0);
  v4 = 0;
  if ( g_pFileSystem->ReadFile(
         this: g_pFileSystem,
         a2: pszFilename,
         a3: nullptr,
         a4: &bufFile,
         a5: 0,
         a6: 0,
         a7: nullptr) )
  {
    v1 = HashBlock(pKey: bufFile.m_Memory.m_pMemory, size: bufFile.m_Put);
    v4 = -1;
    if ( bufFile.m_Memory.m_nGrowSize >= 0 )
    {
      if ( bufFile.m_Memory.m_pMemory != nullptr )
      {
        free(pMem: bufFile.m_Memory.m_pMemory);
        bufFile.m_Memory.m_pMemory = nullptr;
      }
      bufFile.m_Memory.m_nAllocationCount = 0;
    }
    return v1;
  }
  else
  {
    v4 = -1;
    if ( bufFile.m_Memory.m_nGrowSize >= 0 )
    {
      if ( bufFile.m_Memory.m_pMemory != nullptr )
      {
        free(pMem: bufFile.m_Memory.m_pMemory);
        bufFile.m_Memory.m_pMemory = nullptr;
      }
      bufFile.m_Memory.m_nAllocationCount = 0;
    }
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000FBF0
// Name: public: CToolHandler_SyncMesh::~CToolHandler_SyncMesh(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CToolHandler_SyncMesh::~CToolHandler_SyncMesh(CToolHandler_SyncMesh *this)
{
  volatile signed __int32 *v2; // eax
  volatile signed __int32 *v3; // eax
  volatile signed __int32 *v4; // eax
  volatile signed __int32 *v5; // eax
  volatile signed __int32 *v6; // eax
  volatile signed __int32 *v7; // eax
  volatile signed __int32 *v8; // eax

  v2 = (volatile signed __int32 *)(this->m_strMdlFileName.m_pszData - 16);
  if ( _InterlockedDecrement(v2 + 3) <= 0 )
    (*(void (__stdcall **)(volatile signed __int32 *))(**(_DWORD **)v2 + 4))(a1: v2);
  v3 = (volatile signed __int32 *)(this->m_strDmxFileName.m_pszData - 16);
  if ( _InterlockedDecrement(v3 + 3) <= 0 )
    (*(void (__stdcall **)(volatile signed __int32 *))(**(_DWORD **)v3 + 4))(a1: v3);
  v4 = (volatile signed __int32 *)(this->m_strReqDmxFileName.m_pszData - 16);
  if ( _InterlockedDecrement(v4 + 3) <= 0 )
    (*(void (__stdcall **)(volatile signed __int32 *))(**(_DWORD **)v4 + 4))(a1: v4);
  v5 = (volatile signed __int32 *)(this->m_strReqCookie.m_pszData - 16);
  if ( _InterlockedDecrement(v5 + 3) <= 0 )
    (*(void (__stdcall **)(volatile signed __int32 *))(**(_DWORD **)v5 + 4))(a1: v5);
  v6 = (volatile signed __int32 *)(this->m_strCookie.m_pszData - 16);
  if ( _InterlockedDecrement(v6 + 3) <= 0 )
    (*(void (__stdcall **)(volatile signed __int32 *))(**(_DWORD **)v6 + 4))(a1: v6);
  v7 = (volatile signed __int32 *)(this->m_strMayaRequest.m_pszData - 16);
  if ( _InterlockedDecrement(v7 + 3) <= 0 )
    (*(void (__stdcall **)(volatile signed __int32 *))(**(_DWORD **)v7 + 4))(a1: v7);
  v8 = (volatile signed __int32 *)(this->m_strTempFileName.m_pszData - 16);
  if ( _InterlockedDecrement(v8 + 3) <= 0 )
    (*(void (__stdcall **)(volatile signed __int32 *))(**(_DWORD **)v8 + 4))(a1: v8);
  CSelection::~CSelection(this: &this->m_origSelection);
}

//------------------------------------------------------------------------------
// Address: 0x1000FD80
// Name: public: static void CHammerIpcServer::AppInit(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CHammerIpcServer::AppInit()
{
  CValveIpcServer::EnsureRegisteredAndRunning(this: &g_HammerIpcServer);
}

//------------------------------------------------------------------------------
// Address: 0x1000FD90
// Name: public: CUtlInplaceBuffer::~CUtlInplaceBuffer(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlInplaceBuffer::~CUtlInplaceBuffer(CUtlInplaceBuffer *this)
{
  if ( this->m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      free(pMem: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000FDF0
// Name: protected: virtual void CTextureBrowser_Async::OnResult(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTextureBrowser_Async::OnResult(CTextureBrowser_Async *this, int nModalResult)
{
  CUtlBuffer res; // [esp+4h] [ebp-78h] BYREF
  CUtlBuffer cmd; // [esp+34h] [ebp-48h] BYREF
  CValveIpcClientUtl ipc; // [esp+64h] [ebp-18h] BYREF
  int v6; // [esp+78h] [ebp-4h]

  CValveIpcClient::CValveIpcClient(this: &ipc, szServerName: "MAYA_VST_UIHOOK_IPC_SERVER");
  v6 = 1;
  if ( CValveIpcClient::Connect(this: &ipc) != 0 )
  {
    CUtlBuffer::CUtlBuffer(this: &cmd, growSize: 0, initSize: 0, nFlags: 0);
    LOBYTE(v6) = 2;
    CUtlBuffer::PutString(this: &cmd, pString: "textureSelected");
    if ( nModalResult == 1 )
      CUtlBuffer::PutString(this: &cmd, pString: this->m_cTextureWindow.szCurTexture);
    else
      CUtlBuffer::PutString(this: &cmd, pString: &var);
    CUtlBuffer::CUtlBuffer(this: &res, growSize: 0, initSize: 0, nFlags: 0);
    LOBYTE(v6) = 3;
    CUtlBuffer::EnsureCapacity(this: &res, num: 520);
    nModalResult = res.m_Memory.m_nAllocationCount;
    if ( ipc.m_szServerUID != nullptr
      && ipc.m_hClientPipe != nullptr
      && (TransactNamedPipe(
            hNamedPipe: ipc.m_hClientPipe,
            lpInBuffer: cmd.m_Memory.m_pMemory,
            nInBufferSize: cmd.m_Put,
            lpOutBuffer: res.m_Memory.m_pMemory,
            nOutBufferSize: res.m_Memory.m_nAllocationCount,
            lpBytesRead: (LPDWORD)&nModalResult,
            lpOverlapped: nullptr)
       || GetLastError() == 234) )
    {
      CUtlBuffer::SeekPut(this: &res, type: SEEK_HEAD, offset: nModalResult);
    }
    LOBYTE(v6) = 2;
    if ( res.m_Memory.m_nGrowSize >= 0 )
    {
      if ( res.m_Memory.m_pMemory != nullptr )
      {
        free(pMem: res.m_Memory.m_pMemory);
        res.m_Memory.m_pMemory = nullptr;
      }
      res.m_Memory.m_nAllocationCount = 0;
    }
    LOBYTE(v6) = 1;
    if ( cmd.m_Memory.m_nGrowSize >= 0 )
    {
      if ( cmd.m_Memory.m_pMemory != nullptr )
      {
        free(pMem: cmd.m_Memory.m_pMemory);
        cmd.m_Memory.m_pMemory = nullptr;
      }
      cmd.m_Memory.m_nAllocationCount = 0;
    }
    v6 = -1;
    CValveIpcClientUtl::~CValveIpcClientUtl(this: &ipc);
  }
  else
  {
    v6 = -1;
    CValveIpcClientUtl::~CValveIpcClientUtl(this: &ipc);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10010100
// Name: public: CArrayAutoPtr<char>::~CArrayAutoPtr<char>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CArrayAutoPtr<char>::~CArrayAutoPtr<char>(CArrayAutoPtr<char> *this)
{
  char *v2; // [esp-8h] [ebp-1Ch]
  char *m_p; // [esp-4h] [ebp-18h]

  m_p = this->m_p;
  this->m_p = nullptr;
  operator delete(p: m_p);
  v2 = this->m_p;
  this->m_p = nullptr;
  operator delete(p: v2);
}

//------------------------------------------------------------------------------
// Address: 0x10010220
// Name: public: void ATL::CSimpleStringT<char,0>::SetString(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ATL::CSimpleStringT<char,0>::SetString(
        ATL::CSimpleStringT<char,0> *this,
        const char *pszSrc,
        int nLength)
{
  const char *v5; // ecx
  unsigned int v6; // edi
  char *m_pszData; // eax
  unsigned int nOldLength; // [esp+14h] [ebp+Ch]

  if ( nLength != 0 )
  {
    v5 = pszSrc;
    if ( pszSrc == nullptr )
      goto LABEL_4;
    v6 = pszSrc - this->m_pszData;
    nOldLength = *((_DWORD *)this->m_pszData - 3);
    if ( nLength < 0 )
      ATL::AtlThrowImpl(hr: -2147024809);
    if ( ((*((_DWORD *)this->m_pszData - 2) - nLength) | (1 - *((_DWORD *)this->m_pszData - 1))) < 0 )
    {
      ATL::CSimpleStringT<char,0>::PrepareWrite2(this, nLength);
      v5 = pszSrc;
    }
    m_pszData = this->m_pszData;
    if ( v6 > nOldLength )
      memcpy_s(dst: m_pszData, sizeInBytes: *((_DWORD *)m_pszData - 2), src: v5, count: nLength);
    else
      memmove_s(dst: m_pszData, sizeInBytes: *((_DWORD *)m_pszData - 2), src: &m_pszData[v6], count: nLength);
    if ( nLength > *((_DWORD *)this->m_pszData - 2) )
LABEL_4:
      ATL::AtlThrowImpl(hr: -2147024809);
    *((_DWORD *)this->m_pszData - 3) = nLength;
    this->m_pszData[nLength] = 0;
  }
  else
  {
    ATL::CSimpleStringT<char,0>::Empty(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10010340
// Name: public: int CUtlBuffer::GetInt(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlBuffer::GetInt(CUtlBuffer *this)
{
  unsigned __int8 *v2; // eax
  int result; // eax
  char *v4; // edi
  int nIncrement; // [esp+4h] [ebp-Ch] BYREF
  int i; // [esp+8h] [ebp-8h] BYREF
  char *endptr; // [esp+Ch] [ebp-4h] BYREF

  if ( (this->m_Flags & 1) == 0 )
  {
    if ( CUtlBuffer::CheckGet(this, nSize: 4) )
    {
      v2 = &this->m_Memory.m_pMemory[-this->m_nOffset];
      if ( (*(_BYTE *)&this->m_Byteswap & 1) != 0 )
      {
        CByteswap::SwapBufferToTargetEndian<int>(
          this: &this->m_Byteswap,
          outputBuffer: &i,
          inputBuffer: (int *)&v2[this->m_Get],
          count: 1);
        this->m_Get += 4;
        return i;
      }
      else
      {
        result = *(_DWORD *)&v2[this->m_Get];
        this->m_Get += 4;
      }
      return result;
    }
    return 0;
  }
  nIncrement = 128;
  if ( !CUtlBuffer::CheckArbitraryPeekGet(this, nOffset: 0, &nIncrement) )
    return 0;
  endptr = (char *)&this->m_Memory.m_pMemory[this->m_Get - this->m_nOffset];
  v4 = endptr;
  result = strtol(nptr: endptr, &endptr, ibase: 10);
  if ( endptr != v4 )
    this->m_Get += endptr - v4;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100103E0
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
  CUtlBuffer cmd; // [esp+8h] [ebp-6Ch] BYREF
  CUtlBuffer res; // [esp+38h] [ebp-3Ch] BYREF
  int v9; // [esp+70h] [ebp-4h]

  CUtlBuffer::CUtlBuffer(this: &cmd, pBuffer: bufCommand, nSize: numCommandBytes, nFlags: 8);
  v9 = 0;
  CUtlBuffer::CUtlBuffer(this: &res, pBuffer: bufResult, nSize: 0x10000, nFlags: 0);
  LOBYTE(v9) = 1;
  if ( this->ExecuteCommand_2(this, a2: &cmd, a3: &res) != 0 )
  {
    *numResultBytes = res.m_Put;
    LOBYTE(v9) = 0;
    if ( res.m_Memory.m_nGrowSize >= 0 )
    {
      if ( res.m_Memory.m_pMemory != nullptr )
      {
        free(pMem: res.m_Memory.m_pMemory);
        res.m_Memory.m_pMemory = nullptr;
      }
      res.m_Memory.m_nAllocationCount = 0;
    }
    v9 = -1;
    if ( cmd.m_Memory.m_nGrowSize >= 0 )
    {
      if ( cmd.m_Memory.m_pMemory != nullptr )
      {
        free(pMem: cmd.m_Memory.m_pMemory);
        cmd.m_Memory.m_pMemory = nullptr;
      }
      cmd.m_Memory.m_nAllocationCount = 0;
    }
    return 1;
  }
  else
  {
    LOBYTE(v9) = 0;
    if ( res.m_Memory.m_nGrowSize >= 0 )
    {
      if ( res.m_Memory.m_pMemory != nullptr )
      {
        free(pMem: res.m_Memory.m_pMemory);
        res.m_Memory.m_pMemory = nullptr;
      }
      res.m_Memory.m_nAllocationCount = 0;
    }
    v9 = -1;
    if ( cmd.m_Memory.m_nGrowSize >= 0 )
    {
      if ( cmd.m_Memory.m_pMemory != nullptr )
      {
        free(pMem: cmd.m_Memory.m_pMemory);
        cmd.m_Memory.m_pMemory = nullptr;
      }
      cmd.m_Memory.m_nAllocationCount = 0;
    }
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10010640
// Name: public: void ATL::CSimpleStringT<char,0>::Append(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ATL::CSimpleStringT<char,0>::Append(ATL::CSimpleStringT<char,0> *this, char *pszSrc, int nLength)
{
  signed int v4; // edi
  unsigned int v5; // ebx
  int v6; // edi
  char *m_pszData; // eax
  const char *v8; // ecx
  unsigned int nOldLength; // [esp+8h] [ebp-8h]
  unsigned int nOffset; // [esp+Ch] [ebp-4h]

  v4 = *((_DWORD *)this->m_pszData - 3);
  nOffset = pszSrc - this->m_pszData;
  nOldLength = v4;
  if ( nLength < 0 )
    goto LABEL_2;
  if ( pszSrc != nullptr )
    v5 = strnlen(str: pszSrc, maxsize: nLength);
  else
    v5 = 0;
  if ( (int)(0x7FFFFFFF - v5) < v4 )
    ATL::AtlThrowImpl(hr: -2147024809);
  v6 = v5 + v4;
  if ( v6 < 0 )
    ATL::AtlThrowImpl(hr: -2147024809);
  if ( ((*((_DWORD *)this->m_pszData - 2) - v6) | (1 - *((_DWORD *)this->m_pszData - 1))) < 0 )
    ATL::CSimpleStringT<char,0>::PrepareWrite2(this, nLength: v6);
  m_pszData = this->m_pszData;
  v8 = nOffset > nOldLength ? pszSrc : &m_pszData[nOffset];
  memcpy_s(dst: &m_pszData[nOldLength], sizeInBytes: v5, src: v8, count: v5);
  if ( v6 > *((_DWORD *)this->m_pszData - 2) )
LABEL_2:
    ATL::AtlThrowImpl(hr: -2147024809);
  *((_DWORD *)this->m_pszData - 3) = v6;
  this->m_pszData[v6] = 0;
}

//------------------------------------------------------------------------------
// Address: 0x10010700
// Name: protected: static void ATL::CSimpleStringT<char,0>::Concatenate(class ATL::CSimpleStringT<char,0> __near &,char const __near *,int,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ATL::CSimpleStringT<char,0>::Concatenate(
        ATL::CSimpleStringT<char,0> *strResult,
        const char *psz1,
        char *nLength1,
        const char *psz2,
        unsigned int nLength2)
{
  char *v6; // esi
  char *pszBuffer; // [esp+1Ch] [ebp+10h]

  v6 = &nLength1[nLength2];
  if ( (int)&nLength1[nLength2] < 0 )
    goto LABEL_2;
  if ( ((*((_DWORD *)strResult->m_pszData - 2) - (int)v6) | (1 - *((_DWORD *)strResult->m_pszData - 1))) < 0 )
    ATL::CSimpleStringT<char,0>::PrepareWrite2(this: strResult, nLength: (int)&nLength1[nLength2]);
  pszBuffer = strResult->m_pszData;
  memcpy_s(dst: strResult->m_pszData, sizeInBytes: (unsigned int)nLength1, src: psz1, count: (unsigned int)nLength1);
  memcpy_s(dst: &pszBuffer[(_DWORD)nLength1], sizeInBytes: nLength2, src: psz2, count: nLength2);
  if ( (int)v6 > *((_DWORD *)strResult->m_pszData - 2) )
LABEL_2:
    ATL::AtlThrowImpl(hr: -2147024809);
  *((_DWORD *)strResult->m_pszData - 3) = v6;
  v6[(unsigned int)strResult->m_pszData] = 0;
}

//------------------------------------------------------------------------------
// Address: 0x100108D0
// Name: public: class ATL::CSimpleStringT<char,0> __near & ATL::CSimpleStringT<char,0>::operator=(class ATL::CSimpleStringT<char,0> const __near &)
// Source: json
//------------------------------------------------------------------------------
ATL::CSimpleStringT<char,0> *__thiscall ATL::CSimpleStringT<char,0>::operator=(
        ATL::CSimpleStringT<char,0> *this,
        ATL::CStringData *strSrc)
{
  ATL::CStringData *v3; // eax
  volatile signed __int32 *v4; // esi
  ATL::CStringData *pNewData; // [esp+10h] [ebp+8h]

  v3 = (ATL::CStringData *)&strSrc->pStringMgr[-4];
  v4 = (volatile signed __int32 *)(this->m_pszData - 16);
  if ( v3 == (ATL::CStringData *)v4 )
    return this;
  if ( *((int *)v4 + 3) < 0 || v3->pStringMgr != (ATL::IAtlStringMgr *)*v4 )
  {
    ATL::CSimpleStringT<char,0>::SetString(
      this,
      pszSrc: (const char *)strSrc->pStringMgr,
      nLength: (int)strSrc->pStringMgr[-3].__vftable);
    return this;
  }
  pNewData = ATL::CSimpleStringT<char,0>::CloneData(pData: v3);
  if ( _InterlockedDecrement(v4 + 3) <= 0 )
    (*(void (__stdcall **)(volatile signed __int32 *))(**(_DWORD **)v4 + 4))(a1: v4);
  this->m_pszData = (char *)&pNewData[1];
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10010940
// Name: public: void ATL::CSimpleStringT<char,0>::SetString(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ATL::CSimpleStringT<char,0>::SetString(ATL::CSimpleStringT<char,0> *this, const char *pszSrc)
{
  if ( pszSrc != nullptr )
    ATL::CSimpleStringT<char,0>::SetString(this, pszSrc, nLength: strlen(pszSrc));
  else
    ATL::CSimpleStringT<char,0>::SetString(this, pszSrc: nullptr, nLength: 0);
}

//------------------------------------------------------------------------------
// Address: 0x100109A0
// Name: protected: int CToolHandler_SyncMesh::NotifyMaya(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CToolHandler_SyncMesh::NotifyMaya(CToolHandler_SyncMesh *this)
{
  int v2; // eax
  int Int; // eax
  char chErrorString[260]; // [esp+4h] [ebp-180h] BYREF
  CUtlBuffer cmd; // [esp+108h] [ebp-7Ch] BYREF
  CUtlBuffer res; // [esp+138h] [ebp-4Ch] BYREF
  CValveIpcClientUtl ipc; // [esp+168h] [ebp-1Ch] BYREF
  DWORD BytesRead; // [esp+174h] [ebp-10h] BYREF
  int v10; // [esp+180h] [ebp-4h]

  CValveIpcClient::CValveIpcClient(this: &ipc, szServerName: "MAYA_VST_UIHOOK_IPC_SERVER");
  v10 = 1;
  if ( CValveIpcClient::Connect(this: &ipc) != 0 )
  {
LABEL_4:
    v2 = atoi(nptr: this->m_strCookie.m_pszData);
    ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::Format(
      this: &this->m_strCookie,
      pszFormat: "%d",
      v2 + 1);
    CUtlBuffer::CUtlBuffer(this: &cmd, growSize: 0, initSize: 0, nFlags: 0);
    LOBYTE(v10) = 2;
    CUtlBuffer::PutString(this: &cmd, pString: this->m_strMayaRequest.m_pszData);
    CUtlBuffer::PutString(this: &cmd, pString: this->m_strCookie.m_pszData);
    CUtlBuffer::PutString(this: &cmd, pString: this->m_strTempFileName.m_pszData);
    CUtlBuffer::CUtlBuffer(this: &res, growSize: 0, initSize: 0, nFlags: 0);
    LOBYTE(v10) = 3;
    CUtlBuffer::EnsureCapacity(this: &res, num: 520);
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
      Int = CUtlBuffer::GetInt(this: &res);
      if ( Int == 0 )
      {
        memset(chErrorString, 0, sizeof(chErrorString));
        sprintf(string: chErrorString, format: "Generic Error");
        CUtlBuffer::GetString(this: &res, pString: chErrorString, nMaxChars: 259);
        AfxMessageBox(lpszText: chErrorString, nType: 0x10u, nIDHelp: 0);
        LOBYTE(v10) = 2;
        CUtlBuffer::~CUtlBuffer(this: &res);
        LOBYTE(v10) = 1;
        CUtlBuffer::~CUtlBuffer(this: &cmd);
LABEL_21:
        v10 = -1;
        CValveIpcClientUtl::~CValveIpcClientUtl(this: &ipc);
        return 0;
      }
      if ( Int == 1 )
      {
        LOBYTE(v10) = 2;
        CUtlBuffer::~CUtlBuffer(this: &res);
        LOBYTE(v10) = 1;
        CUtlBuffer::~CUtlBuffer(this: &cmd);
        v10 = -1;
        CValveIpcClientUtl::~CValveIpcClientUtl(this: &ipc);
        return 1;
      }
    }
    AfxMessageBox(
      lpszText: "Cannot communicate with Maya.\nMake sure you have Maya running and proper plug-ins loaded and try again.",
      nType: 0x10u,
      nIDHelp: 0);
    LOBYTE(v10) = 2;
    if ( res.m_Memory.m_nGrowSize >= 0 )
    {
      if ( res.m_Memory.m_pMemory != nullptr )
      {
        free(pMem: res.m_Memory.m_pMemory);
        res.m_Memory.m_pMemory = nullptr;
      }
      res.m_Memory.m_nAllocationCount = 0;
    }
    LOBYTE(v10) = 1;
    if ( cmd.m_Memory.m_nGrowSize >= 0 )
    {
      if ( cmd.m_Memory.m_pMemory != nullptr )
      {
        free(pMem: cmd.m_Memory.m_pMemory);
        cmd.m_Memory.m_pMemory = nullptr;
      }
      cmd.m_Memory.m_nAllocationCount = 0;
    }
    goto LABEL_21;
  }
  while ( AfxMessageBox(
            lpszText: "Cannot connect to Maya.\nMake sure you have Maya running and proper plug-ins loaded and try again.",
            nType: 0x35u,
            nIDHelp: 0) == 4 )
  {
    if ( CValveIpcClient::Connect(this: &ipc) != 0 )
      goto LABEL_4;
  }
  v10 = -1;
  CValveIpcClientUtl::~CValveIpcClientUtl(this: &ipc);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10010DA0
// Name: public: void ATL::CSimpleStringT<char,0>::Append(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ATL::CSimpleStringT<char,0>::Append(ATL::CSimpleStringT<char,0> *this, char *pszSrc)
{
  if ( pszSrc != nullptr )
    ATL::CSimpleStringT<char,0>::Append(this, pszSrc, nLength: strlen(pszSrc));
  else
    ATL::CSimpleStringT<char,0>::Append(this, pszSrc: nullptr, nLength: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10010DE0
// Name: public: CWaitCursor::~CWaitCursor(void)
// Source: json
//------------------------------------------------------------------------------
// bad sp value at call has been detected, the output may be wrong!
void __thiscall CWaitCursor::~CWaitCursor(CWaitCursor *this)
{
  AFX_MODULE_STATE *ModuleState; // eax
  int v2; // [esp+0h] [ebp-224h] BYREF
  int *v3; // [esp+214h] [ebp-10h]
  int v4; // [esp+220h] [ebp-4h]

  v3 = &v2;
  v4 = 0;
  ModuleState = AfxGetModuleState();
  CCmdTarget::EndWaitCursor(this: ModuleState->m_pCurrentWinApp);
}

//------------------------------------------------------------------------------
// Address: 0x10010F70
// Name: protected: int CToolHandler_SyncMesh::CanExecute(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CToolHandler_SyncMesh::CanExecute(CToolHandler_SyncMesh *this)
{
  CMainFrame *MainWnd; // eax
  CToolManager *v4; // eax
  const CUtlReferenceVector<CMapClass> *List; // edi
  int i; // esi
  CMapClass *m_pObject; // eax
  CUtlReference<CMapClass> *v8; // ecx
  CMapClass *v9; // ebx
  CUtlReference<CMapClass> *m_pHead; // [esp+4h] [ebp-18h] BYREF
  CUtlReference<CMapClass> *v11; // [esp+8h] [ebp-14h]
  CMapClass *v12; // [esp+Ch] [ebp-10h]
  int v13; // [esp+18h] [ebp-4h]

  MainWnd = GetMainWnd();
  if ( CMainFrame::IsShellSessionActive(this: MainWnd) )
    return 0;
  v4 = ToolManager();
  if ( CToolManager::GetActiveToolID(this: v4) == TOOL_FACEEDIT_MATERIAL )
    return 0;
  List = CSelection::GetList(this: this->m_pSelection);
  for ( i = 0; i < List->m_Size; ++i )
  {
    m_pObject = List->m_Memory.m_pMemory[i >> (*((int *)&List->m_Memory + 2) >> 27)][i
                                                                                   & ((32
                                                                                     * *((_DWORD *)&List->m_Memory + 2)) >> 5)].m_pObject;
    if ( m_pObject != nullptr )
    {
      v12 = List->m_Memory.m_pMemory[i >> (*((int *)&List->m_Memory + 2) >> 27)][i
                                                                               & ((32 * *((_DWORD *)&List->m_Memory + 2)) >> 5)].m_pObject;
      m_pHead = m_pObject->m_References.m_pHead;
      v8 = m_pObject->m_References.m_pHead;
      if ( v8 != nullptr )
        v8->m_pPrev = (CUtlReference<CMapClass> *)&m_pHead;
      v11 = nullptr;
      m_pObject->m_References.m_pHead = (CUtlReference<CMapClass> *)&m_pHead;
    }
    v9 = v12;
    v13 = -1;
    if ( v12 != nullptr )
    {
      if ( v11 != nullptr )
      {
        v11->m_pNext = m_pHead;
        if ( m_pHead != nullptr )
          m_pHead->m_pPrev = v11;
      }
      else if ( (CUtlReference<CMapClass> **)v12->m_References.m_pHead == &m_pHead )
      {
        v12->m_References.m_pHead = m_pHead;
        if ( m_pHead != nullptr )
          m_pHead->m_pPrev = nullptr;
      }
      v11 = nullptr;
      m_pHead = nullptr;
      v12 = nullptr;
    }
    v9->GetType(this: v9);
    if ( v9->IsMapClass(this: v9, a2: CMapEntity::__Type) != 0 )
    {
      if ( v9[1].m_References.m_pHead == nullptr || _V_stricmp(s1: "prop_static", s2: (const char *)&v9[1].___u2) != 0 )
        return 0;
    }
    else if ( v9->IsMapClass(this: v9, a2: CMapSolid::__Type) == 0 )
    {
      return 0;
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10011110
// Name: protected: int CToolHandler_SyncMesh::DmxDeleteOrigObjects(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CToolHandler_SyncMesh::DmxDeleteOrigObjects(CToolHandler_SyncMesh *this)
{
  CMapDoc_Friendly *m_pDoc; // ecx
  CHistory *History; // eax
  const CUtlReferenceVector<CMapClass> *v5; // edi
  int i; // esi
  CMapClass *m_pObject; // eax
  CUtlReference<CMapClass> *v8; // ecx
  CMapClass *v9; // edx
  CToolHandler_SyncMesh *v10; // esi
  const CUtlReferenceVector<CMapClass> *List; // [esp-14h] [ebp-34h]
  CUtlReference<CMapClass> *m_pHead; // [esp+4h] [ebp-1Ch] BYREF
  CUtlReference<CMapClass> *v13; // [esp+8h] [ebp-18h]
  CMapClass *pObject; // [esp+Ch] [ebp-14h]
  CToolHandler_SyncMesh *v15; // [esp+10h] [ebp-10h]
  int v16; // [esp+1Ch] [ebp-4h]

  m_pDoc = this->m_pDoc;
  v15 = this;
  if ( m_pDoc != this->m_origSelection.m_pDocument )
    return 0;
  if ( s_opt_maya_bReplaceSelection )
  {
    CMapDoc::OnEditDelete(this: m_pDoc);
  }
  else
  {
    List = CSelection::GetList(this: this->m_pSelection);
    History = GetHistory();
    CHistory::MarkUndoPosition(this: History, pSelection: List, pszName: "Delete", bFromOpposite: 0);
    v5 = CSelection::GetList(this: &this->m_origSelection);
    for ( i = 0; i < v5->m_Size; ++i )
    {
      m_pObject = v5->m_Memory.m_pMemory[i >> ((unsigned __int64)*((int *)&v5->m_Memory + 2) >> 27)][i & ((32 * *((_DWORD *)&v5->m_Memory + 2)) >> 5)].m_pObject;
      if ( m_pObject != nullptr )
      {
        pObject = v5->m_Memory.m_pMemory[i >> ((unsigned __int64)*((int *)&v5->m_Memory + 2) >> 27)][i & ((32 * *((_DWORD *)&v5->m_Memory + 2)) >> 5)].m_pObject;
        m_pHead = m_pObject->m_References.m_pHead;
        v8 = m_pObject->m_References.m_pHead;
        if ( v8 != nullptr )
          v8->m_pPrev = (CUtlReference<CMapClass> *)&m_pHead;
        v13 = nullptr;
        m_pObject->m_References.m_pHead = (CUtlReference<CMapClass> *)&m_pHead;
      }
      v9 = pObject;
      v16 = -1;
      if ( pObject != nullptr )
      {
        if ( v13 != nullptr )
        {
          v13->m_pNext = m_pHead;
          if ( m_pHead != nullptr )
            m_pHead->m_pPrev = v13;
        }
        else if ( (CUtlReference<CMapClass> **)pObject->m_References.m_pHead == &m_pHead )
        {
          pObject->m_References.m_pHead = m_pHead;
          if ( m_pHead != nullptr )
            m_pHead->m_pPrev = nullptr;
        }
        v13 = nullptr;
        m_pHead = nullptr;
        pObject = nullptr;
      }
      CMapDoc::DeleteObject(this: v15->m_pDoc, pObject: v9);
    }
    v10 = v15;
    CSelection::RemoveAll(this: v15->m_pSelection);
    v10->m_pDoc->SetModifiedFlag(this: v10->m_pDoc, a2: 1);
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10011270
// Name: public: virtual CTextureBrowser::~CTextureBrowser(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTextureBrowser::~CTextureBrowser(CTextureBrowser *this)
{
  CUtlPriorityQueue<TranslucentObjects_s,CDefUtlPriorityQueueLessFunc<TranslucentObjects_s>,CUtlMemory<TranslucentObjects_s,int>>::~CUtlPriorityQueue<TranslucentObjects_s,CDefUtlPriorityQueueLessFunc<TranslucentObjects_s>,CUtlMemory<TranslucentObjects_s,int>>(this: &this->m_TextureSubList);
  CButton::~CButton(this: &this->m_ShowErrors);
  CButton::~CButton(this: &this->m_FilterEnvMask);
  CButton::~CButton(this: &this->m_FilterSelfIllum);
  CButton::~CButton(this: &this->m_FilterTranslucent);
  CButton::~CButton(this: &this->m_FilterOpaque);
  CComboBox::~CComboBox(this: &this->m_cKeywords);
  CComboBox::~CComboBox(this: &this->m_cFilter);
  CButton::~CButton(this: &this->m_cUsed);
  CStatic::~CStatic(this: &this->m_cCurDescription);
  CStatic::~CStatic(this: &this->m_cCurName);
  CComboBox::~CComboBox(this: &this->m_cSizeList);
  CTextureWindow::~CTextureWindow(this: &this->m_cTextureWindow);
  CDialog::~CDialog(this);
}

//------------------------------------------------------------------------------
// Address: 0x10011490
// Name: int PrepareEmptyTempHammerDir(class ATL::CStringT<char,class StrTraitMFC<char,class ATL::ChTraitsCRT<char>>> __near &)
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl PrepareEmptyTempHammerDir(ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *sPath)
{
  const char *v1; // eax
  CWinThread *Thread; // eax
  int v4; // eax
  char *m_pszData; // eax
  char *v6; // edi
  _SHFILEOPSTRUCTA sfo; // [esp+4h] [ebp-30h] BYREF
  CArrayAutoPtr<char> bufPathCopy; // [esp+24h] [ebp-10h]
  int v9; // [esp+30h] [ebp-4h]

  v1 = getenv(option: "VPROJECT");
  if ( v1 == nullptr )
    return false;
  ATL::CSimpleStringT<char,0>::SetString(this: sPath, pszSrc: v1, nLength: strlen(v1));
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::Replace(this: sPath, chOld: 92, chNew: 47);
  ATL::CSimpleStringT<char,0>::Append(this: sPath, pszSrc: "/models/.hammer.tmp", nLength: 19);
  if ( access(path: sPath->m_pszData, amode: 0) == 0 )
  {
    memset(&sfo, 0, sizeof(sfo));
    Thread = AfxGetThread();
    if ( Thread != nullptr && (v4 = (int)Thread->GetMainWnd(this: Thread)) != 0 )
      sfo.hwnd = *(HWND__ **)(v4 + 32);
    else
      sfo.hwnd = nullptr;
    m_pszData = sPath->m_pszData;
    sfo.wFunc = 3;
    sfo.fFlags = 1044;
    v6 = (char *)operator new[](nSize: *((_DWORD *)m_pszData - 3) + 10);
    bufPathCopy.m_p = v6;
    v9 = 1;
    sprintf(string: v6, format: "%s/*.*%c%c", sPath->m_pszData, 0, 0);
    V_FixSlashes(pname: v6, separator: 92);
    sfo.pFrom = v6;
    if ( SHFileOperationA(lpFileOp: &sfo) != 0 )
    {
      v9 = 2;
      bufPathCopy.m_p = nullptr;
      operator delete(p: v6);
      v9 = -1;
      bufPathCopy.m_p = nullptr;
      operator delete(p: nullptr);
      return false;
    }
    v9 = 3;
    bufPathCopy.m_p = nullptr;
    operator delete(p: v6);
    v9 = -1;
    bufPathCopy.m_p = nullptr;
    operator delete(p: nullptr);
  }
  return mkdir(path: sPath->m_pszData) == 0 || *_errno() == 17;
}

//------------------------------------------------------------------------------
// Address: 0x10011640
// Name: int GetMdlCacheDir(class ATL::CStringT<char,class StrTraitMFC<char,class ATL::ChTraitsCRT<char>>> __near &)
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl GetMdlCacheDir(ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *sPath)
{
  const char *v1; // eax
  BOOL result; // eax

  v1 = getenv(option: "VPROJECT");
  result = false;
  if ( v1 != nullptr )
  {
    ATL::CSimpleStringT<char,0>::SetString(this: sPath, pszSrc: v1, nLength: strlen(v1));
    ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::Replace(this: sPath, chOld: 92, chNew: 47);
    ATL::CSimpleStringT<char,0>::Append(this: sPath, pszSrc: "/models/.hammer.mdlcache", nLength: 24);
    if ( mkdir(path: sPath->m_pszData) == 0 || *_errno() == 17 )
      return true;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10011790
// Name: public: virtual int CToolHandler_SyncMesh::UpdateCmdUI(class CCmdUI __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CToolHandler_SyncMesh::UpdateCmdUI(CToolHandler_SyncMesh *this, CCmdUI *pCmdUI)
{
  CWinThread *Thread; // eax
  int v4; // eax

  Thread = AfxGetThread();
  if ( Thread != nullptr && (v4 = (int)Thread->GetMainWnd(this: Thread)) != 0 )
    s_hMainWnd = *(HWND *)(v4 + 32);
  else
    s_hMainWnd = nullptr;
  if ( CToolHandler_SyncMesh::Setup(this) != 0 && CToolHandler_SyncMesh::CanExecute(this) != 0 )
  {
    pCmdUI->Enable(this: pCmdUI, a2: 1);
    return 1;
  }
  else
  {
    pCmdUI->Enable(this: pCmdUI, a2: 0);
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10011810
// Name: protected: int CToolHandler_SyncMesh::CreateTempFileName(void)
// Source: json
//------------------------------------------------------------------------------
int __usercall CToolHandler_SyncMesh::CreateTempFileName@<eax>(CToolHandler_SyncMesh *this@<ecx>, int a2@<edi>)
{
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *SystemTempDir; // eax
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *v4; // eax
  char *v5; // eax
  char *v6; // eax
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > v8; // [esp+4h] [ebp-14h] BYREF
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > v9; // [esp+8h] [ebp-10h] BYREF
  int v10; // [esp+14h] [ebp-4h]

  SystemTempDir = GetSystemTempDir(a1: a2, a2: (int)this, result: &v8);
  v10 = 0;
  v4 = ATL::operator+(a1: a2, a2: (int)this, result: &v9, str1: SystemTempDir, psz2: "/hammer_geom.vmf");
  LOBYTE(v10) = 1;
  ATL::CSimpleStringT<char,0>::operator=(this: &this->m_strTempFileName, strSrc: (ATL::CStringData *)v4);
  LOBYTE(v10) = 0;
  v5 = v9.m_pszData - 16;
  if ( _InterlockedDecrement((volatile signed __int32 *)v9.m_pszData - 1) <= 0 )
    (*(void (__thiscall **)(_DWORD, char *))(**(_DWORD **)v5 + 4))(a1: *(_DWORD *)v5, a2: v5);
  v10 = -1;
  v6 = v8.m_pszData - 16;
  if ( _InterlockedDecrement((volatile signed __int32 *)v8.m_pszData - 1) <= 0 )
    (*(void (__thiscall **)(_DWORD, char *))(**(_DWORD **)v6 + 4))(a1: *(_DWORD *)v6, a2: v6);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100118C0
// Name: protected: int CToolHandler_SyncMesh::ExportTempDoc(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CToolHandler_SyncMesh::ExportTempDoc(CToolHandler_SyncMesh *this)
{
  int v1; // edi
  int result; // eax

  v1 = bSaveVisiblesOnly;
  bSaveVisiblesOnly = 0;
  result = this->m_pTempDoc->OnSaveDocument(this: this->m_pTempDoc, a2: this->m_strTempFileName.m_pszData);
  if ( result != 0 )
  {
    ATL::CSimpleStringT<char,0>::SetString(this: &this->m_strMayaRequest, pszSrc: "hammerBrush", nLength: 11);
    result = 1;
  }
  bSaveVisiblesOnly = v1;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10011960
// Name: public: int CToolHandler_SyncMesh::RequestDmxLoad(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CToolHandler_SyncMesh::RequestDmxLoad(
        CToolHandler_SyncMesh *this,
        const char *pszCookie,
        const char *pszDmxFile)
{
  CThreadFastMutex *p_m_mtxRequest; // esi
  DWORD CurrentThreadId; // eax
  int v7; // eax
  int v8; // eax

  if ( _V_stricmp(s1: pszCookie, s2: this->m_strCookie.m_pszData) != 0 )
    return 0;
  p_m_mtxRequest = &this->m_mtxRequest;
  CurrentThreadId = GetCurrentThreadId();
  if ( CurrentThreadId != this->m_mtxRequest.m_ownerID
    && _InterlockedCompareExchange((volatile signed __int32 *)p_m_mtxRequest, CurrentThreadId, 0) != 0 )
  {
    _mm_pause();
    CThreadFastMutex::Lock(a1: &this->m_mtxRequest, a2: CurrentThreadId, a3: 0);
  }
  else
  {
    ++this->m_mtxRequest.m_depth;
  }
  if ( pszDmxFile != nullptr )
    v7 = strlen(pszDmxFile);
  else
    v7 = 0;
  ATL::CSimpleStringT<char,0>::SetString(this: &this->m_strReqDmxFileName, pszSrc: pszDmxFile, nLength: v7);
  if ( pszCookie != nullptr )
    v8 = strlen(pszCookie);
  else
    v8 = 0;
  ATL::CSimpleStringT<char,0>::SetString(this: &this->m_strReqCookie, pszSrc: pszCookie, nLength: v8);
  if ( this->m_mtxRequest.m_depth-- == 1 )
    _InterlockedExchange((volatile __int32 *)p_m_mtxRequest, 0);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10011A70
// Name: protected: int CToolHandler_SyncMesh::DmxPrepareModelFiles(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CToolHandler_SyncMesh::DmxPrepareModelFiles(CToolHandler_SyncMesh *this)
{
  const char *v3; // edi
  ATL::IAtlStringMgr *StringManager; // eax
  char *v5; // eax
  int v6; // esi
  char *v7; // eax
  _iobuf *v8; // eax
  _iobuf *v9; // esi
  char *m_pszData; // eax
  CHAR *v11; // esi
  char *v12; // eax
  _STARTUPINFOA StartupInfo; // [esp+4h] [ebp-7Ch] BYREF
  _PROCESS_INFORMATION pi; // [esp+48h] [ebp-38h] BYREF
  CToolHandler_SyncMesh *v15; // [esp+58h] [ebp-28h]
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > sMdl; // [esp+5Ch] [ebp-24h] BYREF
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > sDmx; // [esp+60h] [ebp-20h] BYREF
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > sQc; // [esp+64h] [ebp-1Ch] BYREF
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > sExeName; // [esp+68h] [ebp-18h] BYREF
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > sMdlCmdLine; // [esp+6Ch] [ebp-14h] BYREF
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > sPath; // [esp+70h] [ebp-10h] BYREF
  int v22; // [esp+7Ch] [ebp-4h]

  v15 = this;
  if ( !s_opt_vmf_bStoreMdl )
    return 1;
  v3 = getenv(option: "VPROJECT");
  StringManager = AfxGetStringManager();
  if ( StringManager == nullptr )
    ATL::AtlThrowImpl(hr: -2147467259);
  sPath.m_pszData = (char *)&StringManager->GetNilString(this: StringManager)[1];
  v22 = 1;
  if ( !PrepareEmptyTempHammerDir(&sPath) )
  {
    v22 = -1;
    v5 = sPath.m_pszData - 16;
    v6 = _InterlockedDecrement((volatile signed __int32 *)sPath.m_pszData - 1);
    goto LABEL_7;
  }
  ATL::operator+(a1: (int)v3, a2: (int)this, result: &sDmx, str1: &sPath, psz2: "/mayamesh.dmx");
  LOBYTE(v22) = 3;
  if ( !CopyFileA(
          lpExistingFileName: this->m_strDmxFileName.m_pszData,
          lpNewFileName: sDmx.m_pszData,
          bFailIfExists: false) )
  {
    LOBYTE(v22) = 1;
    v7 = sDmx.m_pszData - 16;
    if ( _InterlockedDecrement((volatile signed __int32 *)sDmx.m_pszData - 1) <= 0 )
      (*(void (__stdcall **)(char *))(**(_DWORD **)v7 + 4))(a1: v7);
    v22 = -1;
    v5 = sPath.m_pszData - 16;
    v6 = _InterlockedDecrement((volatile signed __int32 *)sPath.m_pszData - 1);
LABEL_7:
    if ( v6 <= 0 )
    {
      (*(void (__stdcall **)(char *))(**(_DWORD **)v5 + 4))(a1: v5);
      return 0;
    }
    return 0;
  }
  ATL::operator+(a1: (int)v3, a2: (int)this, result: &sQc, str1: &sPath, psz2: "/mayamesh.qc");
  LOBYTE(v22) = 6;
  v8 = fopen(file: sQc.m_pszData, mode: "wt");
  v9 = v8;
  if ( v8 != nullptr )
  {
    fprintf(
      str: v8,
      format: " $modelname .hammer.tmp/studiomdl.mdl \n"
      " $scale 1.0 \n"
      " $body \"Body\" \"mayamesh.dmx\" \n"
      " $staticprop \n"
      " $upaxis y \n"
      " $sequence  \"idle\" \"mayamesh\" fps 30 \n"
      " $collisionmodel \"mayamesh.dmx\" { $automass $concave }\n");
    fclose(stream: v9);
    ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>(this: &sExeName);
    LOBYTE(v22) = 7;
    ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::Format(
      this: &sExeName,
      pszFormat: "%s/../bin/studiomdl.exe",
      v3);
    ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>(this: &sMdlCmdLine);
    LOBYTE(v22) = 8;
    ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::Format(
      this: &sMdlCmdLine,
      pszFormat: "%s/../bin/studiomdl.exe -nop4 -fastbuild \"%s\"",
      v3,
      sQc.m_pszData);
    memset(dst: (unsigned __int8 *)&StartupInfo, value: 0, count: sizeof(StartupInfo));
    m_pszData = sMdlCmdLine.m_pszData;
    StartupInfo.cb = 68;
    StartupInfo.dwFlags = 1;
    StartupInfo.wShowWindow = 0;
    memset(&pi, 0, sizeof(pi));
    if ( *((int *)sMdlCmdLine.m_pszData - 1) > 1 )
    {
      ATL::CSimpleStringT<char,0>::Fork(this: &sMdlCmdLine, nLength: *((_DWORD *)sMdlCmdLine.m_pszData - 3));
      m_pszData = sMdlCmdLine.m_pszData;
    }
    v11 = m_pszData;
    v12 = sExeName.m_pszData;
    if ( *((int *)sExeName.m_pszData - 1) > 1 )
    {
      ATL::CSimpleStringT<char,0>::Fork(this: &sExeName, nLength: *((_DWORD *)sExeName.m_pszData - 3));
      v12 = sExeName.m_pszData;
    }
    CreateProcessA(
      lpApplicationName: v12,
      lpCommandLine: v11,
      lpProcessAttributes: nullptr,
      lpThreadAttributes: nullptr,
      bInheritHandles: false,
      dwCreationFlags: 0,
      lpEnvironment: nullptr,
      lpCurrentDirectory: nullptr,
      lpStartupInfo: &StartupInfo,
      lpProcessInformation: &pi);
    if ( pi.hThread != nullptr )
    {
      CloseHandle(hObject: pi.hThread);
      pi.hThread = nullptr;
    }
    if ( pi.hProcess != nullptr )
    {
      WaitForSingleObject(hHandle: pi.hProcess, dwMilliseconds: 0xFFFFFFFF);
      CloseHandle(hObject: pi.hProcess);
      pi.hProcess = nullptr;
    }
    ATL::operator+(a1: (int)CloseHandle, a2: -1, result: &sMdl, str1: &sPath, psz2: "/studiomdl.mdl");
    LOBYTE(v22) = 9;
    if ( access(path: sMdl.m_pszData, amode: 4) == 0 )
    {
      ATL::CSimpleStringT<char,0>::operator=(this: &v15->m_strMdlFileName, strSrc: (ATL::CStringData *)&sMdl);
      LOBYTE(v22) = 8;
      ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::~CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>(this: &sMdl);
      LOBYTE(v22) = 7;
      ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::~CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>(this: &sMdlCmdLine);
      LOBYTE(v22) = 6;
      ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::~CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>(this: &sExeName);
      LOBYTE(v22) = 3;
      ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::~CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>(this: &sQc);
      LOBYTE(v22) = 1;
      ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::~CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>(this: &sDmx);
      v22 = -1;
      ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::~CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>(this: &sPath);
      return 1;
    }
    LOBYTE(v22) = 8;
    ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::~CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>(this: &sMdl);
    LOBYTE(v22) = 7;
    ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::~CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>(this: &sMdlCmdLine);
    LOBYTE(v22) = 6;
    ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::~CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>(this: &sExeName);
    LOBYTE(v22) = 3;
    ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::~CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>(this: &sQc);
    LOBYTE(v22) = 1;
    ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::~CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>(this: &sDmx);
    v22 = -1;
  }
  else
  {
    LOBYTE(v22) = 3;
    ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::~CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>(this: &sQc);
    LOBYTE(v22) = 1;
    ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::~CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>(this: &sDmx);
    v22 = -1;
  }
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::~CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>(this: &sPath);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10011E00
// Name: protected: int CToolHandler_SyncMesh::DmxCreateStaticProp(void)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
unsigned int __usercall CToolHandler_SyncMesh::DmxCreateStaticProp@<eax>(
        CToolHandler_SyncMesh *this@<ecx>,
        int a2@<edi>)
{
  CMapDoc_Friendly *m_pDocument; // eax
  unsigned int result; // eax
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *p_m_strDmxFileName; // ebx
  int v5; // esi
  int v6; // eax
  int v7; // eax
  int v8; // esi
  const char **v9; // edi
  int v10; // eax
  ATL::IAtlStringMgr *StringManager; // eax
  volatile signed __int32 *v12; // eax
  bool v13; // cc
  ATL::IAtlStringMgr *v14; // eax
  unsigned int v15; // kr00_4
  unsigned int i; // edi
  const char *v17; // esi
  int v18; // eax
  int v19; // eax
  float v20; // edi
  _iobuf *v21; // eax
  _iobuf *v22; // esi
  ATL::IAtlStringMgr *v23; // eax
  int v24; // eax
  int v25; // eax
  int v26; // eax
  int v27; // eax
  int v28; // eax
  int v29; // edi
  const char *v30; // esi
  volatile signed __int32 *v31; // esi
  int v32; // eax
  int v33; // eax
  ATL::IAtlStringMgr *v34; // eax
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *OtherFileName; // eax
  const char *v36; // esi
  int v37; // eax
  volatile signed __int32 *v38; // esi
  int v39; // eax
  int v40; // eax
  volatile signed __int32 *v41; // esi
  float v42; // xmm2_4
  float v43; // xmm0_4
  float v44; // xmm1_4
  CMapEntity *Entity; // eax
  int v46; // eax
  int v47; // eax
  char *v49; // [esp+Ch] [ebp-50h]
  const char *v50; // [esp+10h] [ebp-4Ch] BYREF
  __int64 v51; // [esp+14h] [ebp-48h]
  const char *v52; // [esp+1Ch] [ebp-40h]
  float v53[3]; // [esp+20h] [ebp-3Ch] BYREF
  int y; // [esp+2Ch] [ebp-30h]
  float z; // [esp+30h] [ebp-2Ch]
  char *szNewExt; // [esp+34h] [ebp-28h]
  int arrV[4]; // [esp+38h] [ebp-24h] BYREF
  float vecDmxOffset[3]; // [esp+48h] [ebp-14h] BYREF
  int arrRequired_4; // [esp+58h] [ebp-4h] OVERLAPPED

  m_pDocument = (CMapDoc_Friendly *)this->m_origSelection.m_pDocument;
  szNewExt = (char *)this;
  if ( this->m_pDoc != m_pDocument )
    return 0;
  p_m_strDmxFileName = &this->m_strDmxFileName;
  result = ComputeFileHash(pszFilename: this->m_strDmxFileName.m_pszData);
  v5 = result;
  arrV[0] = result;
  if ( result != 0 )
  {
    v6 = *((_DWORD *)p_m_strDmxFileName->m_pszData - 3);
    memset(v53, 0, sizeof(v53));
    if ( v6 > 37 )
    {
      v7 = v6 - 37;
      if ( v7 < 0 || v7 > *((_DWORD *)p_m_strDmxFileName->m_pszData - 3) )
        ATL::AtlThrowImpl(hr: -2147024809);
      if ( p_m_strDmxFileName->m_pszData[v7] == 64 )
      {
        v8 = 0;
        v51 = 0;
        v52 = nullptr;
        v9 = &v50;
        do
        {
          ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::Mid(
            this: p_m_strDmxFileName,
            result: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&arrV[1],
            iFirst: v8 + *((_DWORD *)p_m_strDmxFileName->m_pszData - 3) - 36,
            nCount: 8);
          arrRequired_4 = 0;
          *v9 = (const char *)strtoul(nptr: (const char *)arrV[1], endptr: nullptr, ibase: 16);
          arrRequired_4 = -1;
          v10 = arrV[1] - 16;
          if ( _InterlockedDecrement((volatile signed __int32 *)(arrV[1] - 16 + 12)) <= 0 )
            (*(void (__stdcall **)(int))(**(_DWORD **)v10 + 4))(a1: v10);
          v8 += 8;
          ++v9;
        }
        while ( v8 < 32 );
        v5 = arrV[0];
        *(_QWORD *)v53 = v51;
        LODWORD(v53[2]) = v52;
      }
    }
    StringManager = AfxGetStringManager();
    if ( StringManager == nullptr )
      ATL::AtlThrowImpl(hr: -2147467259);
    LODWORD(vecDmxOffset[1]) = ((int (__thiscall *)(ATL::IAtlStringMgr *, int))StringManager->GetNilString)(
                                 a1: StringManager,
                                 a2)
                             + 16;
    arrRequired_4 = 3;
    if ( !GetMdlCacheDir(sPath: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&vecDmxOffset[1]) )
    {
      arrRequired_4 = -1;
      v12 = (volatile signed __int32 *)(LODWORD(vecDmxOffset[1]) - 16);
      v13 = _InterlockedDecrement((volatile signed __int32 *)(LODWORD(vecDmxOffset[1]) - 16 + 12)) <= 0;
LABEL_72:
      if ( v13 )
        (*(void (__stdcall **)(volatile signed __int32 *))(**(_DWORD **)v12 + 4))(a1: v12);
      return 0;
    }
    v14 = AfxGetStringManager();
    if ( v14 == nullptr )
      ATL::AtlThrowImpl(hr: -2147467259);
    LODWORD(vecDmxOffset[0]) = &v14->GetNilString(this: v14)[1];
    LOBYTE(arrRequired_4) = 6;
    ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::Format(
      this: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)vecDmxOffset,
      pszFormat: "%s/%08X.mdl",
      (const char *)LODWORD(vecDmxOffset[1]),
      v5);
    v15 = strlen(getenv(option: "VPROJECT"));
    ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::Mid(
      this: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)vecDmxOffset,
      result: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&arrV[3],
      iFirst: v15 + 1);
    LOBYTE(arrRequired_4) = 7;
    if ( s_opt_vmf_bStoreMdl )
    {
      v49 = ".mdl";
      v50 = ".vvd";
      LODWORD(v51) = ".dx90.vtx";
      HIDWORD(v51) = ".phy";
      v52 = ".ss2";
      y = 65793;
      LOBYTE(z) = 0;
      for ( i = 0; i < 5; ++i )
      {
        v17 = (&v49)[i];
        GetOtherFileName(
          a1: i,
          result: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&arrV[1],
          sFile: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)szNewExt + 52,
          szNewExt: v17,
          nCurExtLen: 4);
        LOBYTE(arrRequired_4) = 8;
        GetOtherFileName(
          a1: i,
          result: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&arrV[2],
          sFile: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)vecDmxOffset,
          szNewExt: v17,
          nCurExtLen: 4);
        LOBYTE(arrRequired_4) = 9;
        CopyFileA(lpExistingFileName: (LPCSTR)arrV[1], lpNewFileName: (LPCSTR)arrV[2], bFailIfExists: false);
        if ( access(path: (const char *)arrV[2], amode: 4) != 0 && *((_BYTE *)&y + i) != 0 )
        {
          LOBYTE(arrRequired_4) = 8;
          v24 = arrV[2] - 16;
          if ( _InterlockedDecrement((volatile signed __int32 *)(arrV[2] - 16 + 12)) <= 0 )
            (*(void (__stdcall **)(int))(**(_DWORD **)v24 + 4))(a1: v24);
          LOBYTE(arrRequired_4) = 7;
          v25 = arrV[1] - 16;
          if ( _InterlockedDecrement((volatile signed __int32 *)(arrV[1] - 16 + 12)) <= 0 )
            (*(void (__stdcall **)(int))(**(_DWORD **)v25 + 4))(a1: v25);
          LOBYTE(arrRequired_4) = 6;
          v26 = arrV[3] - 16;
          if ( _InterlockedDecrement((volatile signed __int32 *)(arrV[3] - 16 + 12)) <= 0 )
            (*(void (__stdcall **)(int))(**(_DWORD **)v26 + 4))(a1: v26);
          LOBYTE(arrRequired_4) = 3;
          v27 = LODWORD(vecDmxOffset[0]) - 16;
          if ( _InterlockedDecrement((volatile signed __int32 *)(LODWORD(vecDmxOffset[0]) - 16 + 12)) <= 0 )
            (*(void (__stdcall **)(int))(**(_DWORD **)v27 + 4))(a1: v27);
          arrRequired_4 = -1;
          v12 = (volatile signed __int32 *)(LODWORD(vecDmxOffset[1]) - 16);
          goto LABEL_71;
        }
        LOBYTE(arrRequired_4) = 8;
        v18 = arrV[2] - 16;
        if ( _InterlockedDecrement((volatile signed __int32 *)(arrV[2] - 16 + 12)) <= 0 )
          (*(void (__stdcall **)(int))(**(_DWORD **)v18 + 4))(a1: v18);
        LOBYTE(arrRequired_4) = 7;
        v19 = arrV[1] - 16;
        if ( _InterlockedDecrement((volatile signed __int32 *)(arrV[1] - 16 + 12)) <= 0 )
          (*(void (__stdcall **)(int))(**(_DWORD **)v19 + 4))(a1: v19);
      }
      v20 = vecDmxOffset[0];
      v21 = fopen(file: (const char *)LODWORD(vecDmxOffset[0]), mode: "r+b");
      v22 = v21;
      if ( v21 != nullptr )
      {
        fseek(stream: v21, offset: 12, whence: 0);
        fprintf(str: v22, format: "%s%c%c", (const char *)(arrV[3] + 7), 0, 0);
        fclose(stream: v22);
        goto LABEL_31;
      }
      LOBYTE(arrRequired_4) = 6;
      v28 = arrV[3] - 16;
      if ( _InterlockedDecrement((volatile signed __int32 *)(arrV[3] - 16 + 12)) <= 0 )
        (*(void (__stdcall **)(int))(**(_DWORD **)v28 + 4))(a1: v28);
      LOBYTE(arrRequired_4) = 3;
      if ( _InterlockedDecrement((volatile signed __int32 *)(LODWORD(v20) - 16 + 12)) <= 0 )
        (*(void (__thiscall **)(_DWORD, int))(**(_DWORD **)(LODWORD(v20) - 16) + 4))(
          a1: *(_DWORD *)(LODWORD(v20) - 16),
          a2: LODWORD(v20) - 16);
      arrRequired_4 = -1;
      v12 = (volatile signed __int32 *)(LODWORD(vecDmxOffset[1]) - 16);
      goto LABEL_71;
    }
LABEL_31:
    if ( s_opt_vmf_bStoreDmx )
    {
      v23 = AfxGetStringManager();
      if ( v23 == nullptr )
        ATL::AtlThrowImpl(hr: -2147467259);
      arrV[1] = (int)&v23->GetNilString(this: v23)[1];
      LOBYTE(arrRequired_4) = 21;
      v29 = LODWORD(vecDmxOffset[1]);
      ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::Format(
        this: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&arrV[1],
        pszFormat: "%s/%08X.dmx",
        (const char *)LODWORD(vecDmxOffset[1]),
        arrV[0]);
      v30 = (const char *)arrV[1];
      CopyFileA(lpExistingFileName: p_m_strDmxFileName->m_pszData, lpNewFileName: (LPCSTR)arrV[1], bFailIfExists: false);
      if ( access(path: v30, amode: 4) != 0 )
      {
        LOBYTE(arrRequired_4) = 7;
        v31 = (volatile signed __int32 *)(v30 - 16);
        if ( _InterlockedDecrement(v31 + 3) <= 0 )
          (*(void (__stdcall **)(volatile signed __int32 *))(**(_DWORD **)v31 + 4))(a1: v31);
        LOBYTE(arrRequired_4) = 6;
        v32 = arrV[3] - 16;
        if ( _InterlockedDecrement((volatile signed __int32 *)(arrV[3] - 16 + 12)) <= 0 )
          (*(void (__stdcall **)(int))(**(_DWORD **)v32 + 4))(a1: v32);
        LOBYTE(arrRequired_4) = 3;
        v33 = LODWORD(vecDmxOffset[0]) - 16;
        if ( _InterlockedDecrement((volatile signed __int32 *)(LODWORD(vecDmxOffset[0]) - 16 + 12)) <= 0 )
          (*(void (__stdcall **)(int))(**(_DWORD **)v33 + 4))(a1: v33);
LABEL_70:
        arrRequired_4 = -1;
        v12 = (volatile signed __int32 *)(v29 - 16);
LABEL_71:
        v13 = _InterlockedDecrement(v12 + 3) <= 0;
        goto LABEL_72;
      }
      LOBYTE(arrRequired_4) = 7;
      if ( _InterlockedDecrement((volatile signed __int32 *)v30 - 1) <= 0 )
        (*(void (__thiscall **)(_DWORD, const char *))(**((_DWORD **)v30 - 4) + 4))(
          a1: *((_DWORD *)v30 - 4),
          a2: v30 - 16);
    }
    if ( s_opt_vmf_bStoreMa )
    {
      v34 = AfxGetStringManager();
      if ( v34 == nullptr )
        ATL::AtlThrowImpl(hr: -2147467259);
      arrV[1] = (int)&v34->GetNilString(this: v34)[1];
      LOBYTE(arrRequired_4) = 28;
      v29 = LODWORD(vecDmxOffset[1]);
      ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::Format(
        this: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&arrV[1],
        pszFormat: "%s/%08X.ma",
        (const char *)LODWORD(vecDmxOffset[1]),
        arrV[0]);
      OtherFileName = GetOtherFileName(
                        a1: v29,
                        result: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)arrV,
                        sFile: p_m_strDmxFileName,
                        szNewExt: ".ma",
                        nCurExtLen: 4);
      LOBYTE(arrRequired_4) = 29;
      v36 = (const char *)arrV[1];
      CopyFileA(lpExistingFileName: OtherFileName->m_pszData, lpNewFileName: (LPCSTR)arrV[1], bFailIfExists: false);
      LOBYTE(arrRequired_4) = 28;
      v37 = arrV[0] - 16;
      if ( _InterlockedDecrement((volatile signed __int32 *)(arrV[0] - 16 + 12)) <= 0 )
        (*(void (__stdcall **)(int))(**(_DWORD **)v37 + 4))(a1: v37);
      if ( access(path: v36, amode: 4) != 0 )
      {
        LOBYTE(arrRequired_4) = 7;
        v38 = (volatile signed __int32 *)(v36 - 16);
        if ( _InterlockedDecrement(v38 + 3) <= 0 )
          (*(void (__stdcall **)(volatile signed __int32 *))(**(_DWORD **)v38 + 4))(a1: v38);
        LOBYTE(arrRequired_4) = 6;
        v39 = arrV[3] - 16;
        if ( _InterlockedDecrement((volatile signed __int32 *)(arrV[3] - 16 + 12)) <= 0 )
          (*(void (__stdcall **)(int))(**(_DWORD **)v39 + 4))(a1: v39);
        LOBYTE(arrRequired_4) = 3;
        v40 = LODWORD(vecDmxOffset[0]) - 16;
        if ( _InterlockedDecrement((volatile signed __int32 *)(LODWORD(vecDmxOffset[0]) - 16 + 12)) <= 0 )
          (*(void (__stdcall **)(int))(**(_DWORD **)v40 + 4))(a1: v40);
        goto LABEL_70;
      }
      LOBYTE(arrRequired_4) = 7;
      v41 = (volatile signed __int32 *)(v36 - 16);
      if ( _InterlockedDecrement(v41 + 3) <= 0 )
        (*(void (__stdcall **)(volatile signed __int32 *))(**(_DWORD **)v41 + 4))(a1: v41);
    }
    else
    {
      v29 = LODWORD(vecDmxOffset[1]);
    }
    v42 = v53[0];
    v43 = v53[1];
    v44 = v53[2];
    if ( s_opt_maya_bMeshAtOrigin )
    {
      v42 = v53[0] + *((float *)szNewExt + 38);
      v43 = *((float *)szNewExt + 39) + v53[1];
      v44 = *((float *)szNewExt + 40) + v53[2];
    }
    Entity = CMapDoc::CreateEntity(
               this: *((CMapDoc **)szNewExt + 2),
               pszClassName: "prop_static",
               x: v42,
               y: v43,
               z: v44);
    Entity->SetKeyValue(this: &Entity->CEditGameClass, a2: "model", a3: (const char *)arrV[3]);
    LOBYTE(arrRequired_4) = 6;
    v46 = arrV[3] - 16;
    if ( _InterlockedDecrement((volatile signed __int32 *)(arrV[3] - 16 + 12)) <= 0 )
      (*(void (__stdcall **)(int))(**(_DWORD **)v46 + 4))(a1: v46);
    LOBYTE(arrRequired_4) = 3;
    v47 = LODWORD(vecDmxOffset[0]) - 16;
    if ( _InterlockedDecrement((volatile signed __int32 *)(LODWORD(vecDmxOffset[0]) - 16 + 12)) <= 0 )
      (*(void (__stdcall **)(int))(**(_DWORD **)v47 + 4))(a1: v47);
    arrRequired_4 = -1;
    if ( _InterlockedDecrement((volatile signed __int32 *)(v29 - 16 + 12)) <= 0 )
      (*(void (__thiscall **)(_DWORD, int))(**(_DWORD **)(v29 - 16) + 4))(a1: *(_DWORD *)(v29 - 16), a2: v29 - 16);
    return 1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100125A0
// Name: public: CTextureBrowser_Async::CTextureBrowser_Async(void)
// Source: json
//------------------------------------------------------------------------------
CTextureBrowser_Async *__thiscall CTextureBrowser_Async::CTextureBrowser_Async(CTextureBrowser_Async *this)
{
  CWinThread *Thread; // eax
  CWnd *v3; // eax

  Thread = AfxGetThread();
  if ( Thread != nullptr )
    v3 = Thread->GetMainWnd(this: Thread);
  else
    v3 = nullptr;
  CTextureBrowser::CTextureBrowser(this, pParent: v3);
  this->__vftable = (CTextureBrowser_Async_vtbl *)&CTextureBrowser_Async::`vftable';
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10012610
// Name: public: virtual int CDialog::Create(unsigned int,class CWnd __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDialog::Create(CDialog *this, unsigned __int16 nIDTemplate, CWnd *pParentWnd)
{
  return CDialog::Create(this, lpszTemplateName: (const char *)nIDTemplate, pParentWnd);
}

//------------------------------------------------------------------------------
// Address: 0x10012680
// Name: public: virtual enum ChunkFileResult_t CSyncMesh_SaveLoadHandler::SaveVMF(class CChunkFile __near *,class IMapEntity_SaveInfo_t __near *)
// Source: json
//------------------------------------------------------------------------------
ChunkFileResult_t __thiscall CSyncMesh_SaveLoadHandler::SaveVMF(
        CSyncMesh_SaveLoadHandler *this,
        CChunkFile *pFile,
        IMapEntity_SaveInfo_t *pSaveInfo)
{
  IMapEntity_Type_t *m_pEntity; // eax
  const char *Value; // eax
  const char *v7; // esi
  unsigned int v8; // kr00_4
  const ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *v9; // eax
  ChunkFileResult_t v10; // esi
  char szModelHash[16]; // [esp+8h] [ebp-28h] BYREF
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > v12; // [esp+18h] [ebp-18h] BYREF
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > sMdlRelPath; // [esp+1Ch] [ebp-14h] BYREF
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > sMdlPath; // [esp+20h] [ebp-10h] BYREF
  int v15; // [esp+2Ch] [ebp-4h]

  m_pEntity = this->m_pEntity;
  if ( m_pEntity->m_pClass == nullptr || _V_stricmp(s1: "prop_static", s2: m_pEntity->m_szClass) != 0 )
    return ChunkFile_Ok;
  Value = WCKeyValuesT<WCKVBase_Dict>::GetValue(this: &this->m_pEntity->m_KeyValues, pszKey: "model", piIndex: nullptr);
  v7 = Value;
  if ( Value == nullptr || *Value == 0 )
    return ChunkFile_Ok;
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>(this: &sMdlPath);
  v15 = 0;
  if ( !GetMdlCacheDir(sPath: &sMdlPath) )
  {
LABEL_9:
    v15 = -1;
    ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::~CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>(this: &sMdlPath);
    return ChunkFile_Ok;
  }
  v8 = strlen(getenv(option: "VPROJECT"));
  v9 = ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::Mid(this: &sMdlPath, result: &v12, iFirst: v8 + 1);
  LOBYTE(v15) = 1;
  ATL::operator+(a1: (int)this, a2: (int)v7, result: &sMdlRelPath, str1: v9, psz2: "/");
  LOBYTE(v15) = 3;
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::~CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>(this: &v12);
  if ( StringAfterPrefix(str: v7, prefix: sMdlRelPath.m_pszData) == nullptr )
  {
    LOBYTE(v15) = 0;
    ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::~CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>(this: &sMdlRelPath);
    goto LABEL_9;
  }
  memset(szModelHash, 0, sizeof(szModelHash));
  sprintf(string: szModelHash, format: "%.8s", &v7[*((_DWORD *)sMdlRelPath.m_pszData - 3)]);
  v10 = CVmfMeshDataSupport_SaveLoadHandler::WriteDataChunk(this, pFile, szHash: szModelHash);
  LOBYTE(v15) = 0;
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::~CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>(this: &sMdlRelPath);
  v15 = -1;
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::~CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>(this: &sMdlPath);
  return v10;
}

//------------------------------------------------------------------------------
// Address: 0x10012820
// Name: protected: virtual enum ChunkFileResult_t CSyncMesh_SaveLoadHandler::OnFileDataLoaded(class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CSyncMesh_SaveLoadHandler::OnFileDataLoaded(CSyncMesh_SaveLoadHandler *this, CUtlBuffer *bufData)
{
  int v3; // esi
  char *sPrefix; // edi
  char *v5; // esi
  ATL::IAtlStringMgr *StringManager; // eax
  char *m_pszData; // edi
  const char *v8; // eax
  int v9; // eax
  _iobuf *v10; // esi
  const char *arrFiles[7]; // [esp+Ch] [ebp-48h]
  const char *arrNames[7]; // [esp+28h] [ebp-2Ch]
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > sSaveFileName; // [esp+44h] [ebp-10h] BYREF
  int v15; // [esp+50h] [ebp-4h]

  arrFiles[0] = ".ma";
  arrFiles[1] = ".dmx";
  arrFiles[2] = ".mdl";
  arrFiles[3] = ".vvd";
  arrFiles[4] = ".dx90.vtx";
  arrFiles[5] = ".phy";
  arrFiles[6] = ".ss2";
  arrNames[0] = "maa";
  arrNames[1] = "dmx";
  arrNames[2] = "mdl";
  arrNames[3] = "vvd";
  arrNames[4] = "vtx";
  arrNames[5] = "phy";
  arrNames[6] = "ss2";
  v3 = 0;
  sPrefix = this->m_hLoadHeader.sPrefix;
  while ( _V_stricmp(s1: sPrefix, s2: arrNames[v3]) != 0 )
  {
    if ( (unsigned int)++v3 >= 7 )
      return 1;
  }
  v5 = (char *)arrFiles[v3];
  if ( v5 == nullptr )
    return 1;
  StringManager = AfxGetStringManager();
  if ( StringManager == nullptr )
    ATL::AtlThrowImpl(hr: -2147467259);
  m_pszData = (char *)&StringManager->GetNilString(this: StringManager)[1];
  sSaveFileName.m_pszData = m_pszData;
  v15 = 1;
  v8 = getenv(option: "VPROJECT");
  if ( v8 != nullptr )
  {
    ATL::CSimpleStringT<char,0>::SetString(this: &sSaveFileName, pszSrc: v8, nLength: strlen(v8));
    ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::Replace(this: &sSaveFileName, chOld: 92, chNew: 47);
    ATL::CSimpleStringT<char,0>::Append(this: &sSaveFileName, pszSrc: "/models/.hammer.mdlcache", nLength: 24);
    m_pszData = sSaveFileName.m_pszData;
    if ( mkdir(path: sSaveFileName.m_pszData) == 0 || *_errno() == 17 )
    {
      ATL::CSimpleStringT<char,0>::Append(this: &sSaveFileName, pszSrc: "/", nLength: 1);
      v9 = this == (CSyncMesh_SaveLoadHandler *)-12 ? 0 : strlen(this->m_hLoadHeader.sHash);
      ATL::CSimpleStringT<char,0>::Append(this: &sSaveFileName, pszSrc: this->m_hLoadHeader.sHash, nLength: v9);
      ATL::CSimpleStringT<char,0>::Append(this: &sSaveFileName, pszSrc: v5, nLength: strlen(v5));
      m_pszData = sSaveFileName.m_pszData;
      v10 = fopen(file: sSaveFileName.m_pszData, mode: "wb");
      if ( v10 != nullptr )
      {
        fwrite(buffer: bufData->m_Memory.m_pMemory, size: 1u, count: bufData->m_Put, stream: v10);
        fclose(stream: v10);
        v15 = -1;
        if ( _InterlockedDecrement((volatile signed __int32 *)m_pszData - 1) <= 0 )
          (*(void (__thiscall **)(_DWORD, char *))(**((_DWORD **)m_pszData - 4) + 4))(
            a1: *((_DWORD *)m_pszData - 4),
            a2: m_pszData - 16);
        return 0;
      }
    }
  }
  v15 = -1;
  if ( _InterlockedDecrement((volatile signed __int32 *)m_pszData - 1) <= 0 )
    (*(void (__thiscall **)(_DWORD, char *))(**((_DWORD **)m_pszData - 4) + 4))(
      a1: *((_DWORD *)m_pszData - 4),
      a2: m_pszData - 16);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10012B10
// Name: public: int CToolHandler_SyncMesh::RequestTexture(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CToolHandler_SyncMesh::RequestTexture(CToolHandler_SyncMesh *this, const char *pszTextureString)
{
  AFX_MODULE_STATE *StaticModuleState; // eax
  CThreadFastMutex *p_m_mtxRequest; // esi
  DWORD CurrentThreadId; // eax
  bool v7; // zf
  CTextureBrowser_Async *v8; // eax
  CTextureBrowser_Async *v9; // edi
  AFX_MAINTAIN_STATE2 _ctlState; // [esp+4h] [ebp-1Ch] BYREF
  void *pData; // [esp+Ch] [ebp-14h]
  CAutoLockT<CThreadFastMutex> generated_id_2; // [esp+10h] [ebp-10h]
  int v13; // [esp+1Ch] [ebp-4h]

  StaticModuleState = AfxGetStaticModuleState();
  AFX_MAINTAIN_STATE2::AFX_MAINTAIN_STATE2(this: &_ctlState, pNewState: StaticModuleState);
  v13 = 0;
  if ( GetLastActivePopup(hWnd: s_hMainWnd) != s_hMainWnd )
    goto LABEL_2;
  p_m_mtxRequest = &this->m_mtxRequest;
  generated_id_2.m_lock = &this->m_mtxRequest;
  CurrentThreadId = GetCurrentThreadId();
  if ( CurrentThreadId != this->m_mtxRequest.m_ownerID
    && _InterlockedCompareExchange((volatile signed __int32 *)p_m_mtxRequest, CurrentThreadId, 0) != 0 )
  {
    _mm_pause();
    CThreadFastMutex::Lock(a1: &this->m_mtxRequest, a2: CurrentThreadId, a3: 0);
  }
  else
  {
    ++this->m_mtxRequest.m_depth;
  }
  LOBYTE(v13) = 1;
  if ( this->m_pAsyncDialogRequest != nullptr )
  {
    LOBYTE(v13) = 0;
    v7 = this->m_mtxRequest.m_depth-- == 1;
    if ( v7 )
      _InterlockedExchange((volatile __int32 *)p_m_mtxRequest, 0);
LABEL_2:
    v13 = -1;
    AFX_MAINTAIN_STATE2::~AFX_MAINTAIN_STATE2(this: &_ctlState);
    return 0;
  }
  v8 = (CTextureBrowser_Async *)operator new(nSize: 0xD00u);
  pData = v8;
  LOBYTE(v13) = 2;
  if ( v8 != nullptr )
    v9 = CTextureBrowser_Async::CTextureBrowser_Async(this: v8);
  else
    v9 = nullptr;
  LOBYTE(v13) = 1;
  if ( v9 == nullptr )
  {
    LOBYTE(v13) = 0;
    v7 = this->m_mtxRequest.m_depth-- == 1;
    if ( v7 )
      _InterlockedExchange((volatile __int32 *)p_m_mtxRequest, 0);
    goto LABEL_2;
  }
  this->m_pAsyncDialogRequest = v9;
  CTextureBrowser::SetTextureFormat(this: v9, eTextureFormat: tfVMT);
  if ( pszTextureString != nullptr )
    CTextureBrowser::SetInitialTexture(this: v9, pszTexture: pszTextureString);
  LOBYTE(v13) = 0;
  v7 = this->m_mtxRequest.m_depth-- == 1;
  if ( v7 )
    _InterlockedExchange((volatile __int32 *)p_m_mtxRequest, 0);
  v13 = -1;
  AFX_MAINTAIN_STATE2::~AFX_MAINTAIN_STATE2(this: &_ctlState);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10012CB0
// Name: protected: int CToolHandler_SyncMesh::ProcessDmxRequest(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CToolHandler_SyncMesh::ProcessDmxRequest(CToolHandler_SyncMesh *this)
{
  AFX_MODULE_STATE *ModuleState; // eax
  const char *i; // eax
  int v4; // eax
  CUtlInplaceBuffer bufIndex; // [esp+Ch] [ebp-40h] BYREF
  CWaitCursor curWait; // [esp+3Fh] [ebp-Dh] BYREF
  int v8; // [esp+48h] [ebp-4h]

  ModuleState = AfxGetModuleState();
  CCmdTarget::BeginWaitCursor(this: ModuleState->m_pCurrentWinApp);
  v8 = 0;
  CUtlInplaceBuffer::CUtlInplaceBuffer(this: &bufIndex, growSize: 0, initSize: 0, nFlags: 1);
  LOBYTE(v8) = 1;
  if ( CToolHandler_SyncMesh::DmxDeleteOrigObjects(this) != 0
    && g_pFileSystem->ReadFile(
         this: g_pFileSystem,
         a2: this->m_strDmxFileName.m_pszData,
         a3: nullptr,
         a4: &bufIndex,
         a5: 0,
         a6: 0,
         a7: nullptr) )
  {
    for ( i = CUtlInplaceBuffer::InplaceGetLinePtr(this: &bufIndex);
          i != nullptr;
          i = CUtlInplaceBuffer::InplaceGetLinePtr(this: &bufIndex) )
    {
      if ( *i != 0 )
      {
        ATL::CSimpleStringT<char,0>::SetString(this: &this->m_strDmxFileName, pszSrc: i, nLength: strlen(i));
        ATL::CSimpleStringT<char,0>::Append(this: &this->m_strDmxFileName, pszSrc: ".dmx", nLength: 4);
        if ( CToolHandler_SyncMesh::DmxPrepareModelFiles(this) != 0 )
          CToolHandler_SyncMesh::DmxCreateStaticProp(this, a2: (int)this);
      }
    }
    v4 = atoi(nptr: this->m_strCookie.m_pszData);
    ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::Format(
      this: &this->m_strCookie,
      pszFormat: "%d",
      v4 + 1);
  }
  else
  {
    AfxMessageBox(lpszText: "Failed to apply Maya-edited geometry", nType: 0x10u, nIDHelp: 0);
  }
  LOBYTE(v8) = 0;
  if ( bufIndex.m_Memory.m_nGrowSize >= 0 )
  {
    if ( bufIndex.m_Memory.m_pMemory != nullptr )
    {
      free(pMem: bufIndex.m_Memory.m_pMemory);
      bufIndex.m_Memory.m_pMemory = nullptr;
    }
    bufIndex.m_Memory.m_nAllocationCount = 0;
  }
  v8 = -1;
  CWaitCursor::~CWaitCursor(this: &curWait);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10012E00
// Name: public: virtual int CHammerIpcServer::ExecuteCommand(class CUtlBuffer __near &,class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CHammerIpcServer::ExecuteCommand(CHammerIpcServer *this, CUtlBuffer *cmd, CUtlBuffer *res)
{
  CUtlBuffer *v3; // esi
  CUtlBuffer *v4; // esi
  int *p_m_nOffset; // eax
  bool v6; // cc
  CUtlBuffer *v8; // esi
  char szCmd[260]; // [esp+4h] [ebp-110h] BYREF
  int v10; // [esp+110h] [ebp-4h]

  memset(szCmd, 0, sizeof(szCmd));
  v3 = cmd;
  CUtlBuffer::GetString(this: cmd, pString: szCmd, nMaxChars: 259);
  if ( _V_stricmp(s1: szCmd, s2: "mayaDmx") == 0 )
  {
    CUtlBuffer::GetString(this: v3, pString: szCmd, nMaxChars: 259);
    ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>(
      this: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&cmd,
      pszSrc: szCmd);
    v10 = 0;
    CUtlBuffer::GetString(this: v3, pString: szCmd, nMaxChars: 259);
    if ( CToolHandler_SyncMesh::RequestDmxLoad(
           this: &g_ToolHandlerSyncMesh,
           pszCookie: (const char *)cmd,
           pszDmxFile: szCmd) != 0 )
    {
      if ( (res->m_Flags & 1) != 0 )
        CUtlBuffer::Printf(this: res, pFmt: "%d", 1);
      else
        CUtlBuffer::PutTypeBin<int>(this: res, src: 1);
      v10 = -1;
      p_m_nOffset = &cmd[-1].m_nOffset;
      v6 = _InterlockedDecrement((volatile signed __int32 *)&cmd[-1].m_Byteswap) <= 0;
    }
    else
    {
      v4 = res;
      if ( (res->m_Flags & 1) != 0 )
        CUtlBuffer::Printf(this: res, pFmt: "%d", 0);
      else
        CUtlBuffer::PutTypeBin<int>(this: res, src: 0);
      CUtlBuffer::PutString(this: v4, pString: "Invalid mesh synchronization request!");
      v10 = -1;
      p_m_nOffset = &cmd[-1].m_nOffset;
      v6 = _InterlockedDecrement((volatile signed __int32 *)&cmd[-1].m_Byteswap) <= 0;
    }
    if ( v6 )
      (*(void (__stdcall **)(int *))(*(_DWORD *)*p_m_nOffset + 4))(a1: p_m_nOffset);
    return 1;
  }
  if ( _V_stricmp(s1: szCmd, s2: "textureBrowse") == 0 )
  {
    CUtlBuffer::GetString(this: v3, pString: szCmd, nMaxChars: 259);
    if ( CToolHandler_SyncMesh::RequestTexture(this: &g_ToolHandlerSyncMesh, pszTextureString: szCmd) != 0 )
    {
      if ( (res->m_Flags & 1) != 0 )
        CUtlBuffer::Printf(this: res, pFmt: "%d", 1);
      else
        CUtlBuffer::PutTypeBin<int>(this: res, src: 1);
    }
    else
    {
      v8 = res;
      if ( (res->m_Flags & 1) != 0 )
        CUtlBuffer::Printf(this: res, pFmt: "%d", 0);
      else
        CUtlBuffer::PutTypeBin<int>(this: res, src: 0);
      CUtlBuffer::PutString(this: v8, pString: "Cannot request texture!");
    }
    return 1;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10013030
// Name: protected: virtual enum ChunkFileResult_t CSyncMesh_SaveLoadHandler::OnFileDataWriting(class CChunkFile __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __userpurge CSyncMesh_SaveLoadHandler::OnFileDataWriting@<eax>(
        CSyncMesh_SaveLoadHandler *this@<ecx>,
        int a2@<edi>,
        CChunkFile *pFile,
        const char *szHash)
{
  const char *Value; // esi
  ATL::IAtlStringMgr *StringManager; // eax
  unsigned int v6; // kr00_4
  const ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *v7; // eax
  char *v8; // eax
  int v9; // edi
  const ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *v10; // esi
  const ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *v11; // eax
  const ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *v12; // eax
  const ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *v13; // eax
  char *v14; // eax
  char *v15; // eax
  char *v16; // eax
  char *v17; // eax
  ChunkFileResult_t v18; // esi
  char *v19; // eax
  char *v20; // eax
  char *v21; // eax
  char *v23; // eax
  char *v24; // eax
  char *v25; // eax
  char *v26; // eax
  char *v27; // eax
  char *v28; // eax
  const char *arrFiles[7]; // [esp+Ch] [ebp-B4h]
  const char *arrNames[7]; // [esp+28h] [ebp-98h]
  CUtlBuffer bufFile; // [esp+44h] [ebp-7Ch] BYREF
  char szModelHash[16]; // [esp+74h] [ebp-4Ch] BYREF
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > v33; // [esp+84h] [ebp-3Ch] BYREF
  CVmfMeshDataSupport_SaveLoadHandler *v34; // [esp+88h] [ebp-38h]
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > v35; // [esp+8Ch] [ebp-34h] BYREF
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > v36; // [esp+90h] [ebp-30h] BYREF
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > v37; // [esp+94h] [ebp-2Ch] BYREF
  bool bOptNames[8]; // [esp+98h] [ebp-28h]
  bool bOptRequired[6]; // [esp+A0h] [ebp-20h]
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > sMdlRelPath; // [esp+A8h] [ebp-18h] BYREF
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > sMdlPath; // [esp+ACh] [ebp-14h] BYREF
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > sSrc; // [esp+B0h] [ebp-10h] BYREF
  int v43; // [esp+BCh] [ebp-4h]

  v34 = this;
  Value = WCKeyValuesT<WCKVBase_Dict>::GetValue(this: &this->m_pEntity->m_KeyValues, pszKey: "model", piIndex: nullptr);
  StringManager = AfxGetStringManager();
  if ( StringManager == nullptr )
    ATL::AtlThrowImpl(hr: -2147467259);
  sMdlPath.m_pszData = (char *)&StringManager->GetNilString(this: StringManager)[1];
  v43 = 1;
  GetMdlCacheDir(sPath: &sMdlPath);
  v6 = strlen(getenv(option: "VPROJECT"));
  v7 = ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::Mid(this: &sMdlPath, result: &sSrc, iFirst: v6 + 1);
  LOBYTE(v43) = 2;
  ATL::operator+(a1: a2, a2: (int)Value, result: &sMdlRelPath, str1: v7, psz2: "/");
  LOBYTE(v43) = 4;
  v8 = sSrc.m_pszData - 16;
  if ( _InterlockedDecrement((volatile signed __int32 *)sSrc.m_pszData - 1) <= 0 )
    (*(void (__stdcall **)(char *))(**(_DWORD **)v8 + 4))(a1: v8);
  memset(szModelHash, 0, sizeof(szModelHash));
  sprintf(string: szModelHash, format: "%.8s", &Value[*((_DWORD *)sMdlRelPath.m_pszData - 3)]);
  bOptNames[0] = s_opt_vmf_bStoreMa;
  arrFiles[0] = ".ma";
  arrFiles[1] = ".dmx";
  arrFiles[2] = ".mdl";
  arrFiles[3] = ".vvd";
  arrFiles[4] = ".dx90.vtx";
  arrFiles[5] = ".phy";
  arrFiles[6] = ".ss2";
  arrNames[0] = "maa";
  arrNames[1] = "dmx";
  arrNames[2] = "mdl";
  arrNames[3] = "vvd";
  arrNames[4] = "vtx";
  arrNames[5] = "phy";
  arrNames[6] = "ss2";
  bOptNames[1] = s_opt_vmf_bStoreDmx;
  bOptNames[2] = s_opt_vmf_bStoreMdl;
  bOptNames[3] = s_opt_vmf_bStoreMdl;
  bOptNames[4] = s_opt_vmf_bStoreMdl;
  bOptNames[5] = s_opt_vmf_bStoreMdl;
  bOptNames[6] = s_opt_vmf_bStoreMdl;
  *(_DWORD *)bOptRequired = 16843009;
  *(_WORD *)&bOptRequired[4] = 1;
  v9 = 0;
  while ( !bOptNames[v9] )
  {
LABEL_29:
    if ( (unsigned int)++v9 >= 7 )
    {
      LOBYTE(v43) = 1;
      v20 = sMdlRelPath.m_pszData - 16;
      if ( _InterlockedDecrement((volatile signed __int32 *)sMdlRelPath.m_pszData - 1) <= 0 )
        (*(void (__stdcall **)(char *))(**(_DWORD **)v20 + 4))(a1: v20);
      v43 = -1;
      v21 = sMdlPath.m_pszData - 16;
      if ( _InterlockedDecrement((volatile signed __int32 *)sMdlPath.m_pszData - 1) <= 0 )
        (*(void (__stdcall **)(char *))(**(_DWORD **)v21 + 4))(a1: v21);
      return 0;
    }
  }
  v10 = ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>(
          this: &v37,
          pszSrc: szModelHash);
  LOBYTE(v43) = 6;
  v11 = ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>(
          this: &v36,
          pszSrc: "/");
  LOBYTE(v43) = 7;
  v12 = ATL::operator+(result: &v35, str1: &sMdlPath, str2: v11);
  LOBYTE(v43) = 8;
  v13 = ATL::operator+(result: &v33, str1: v12, str2: v10);
  LOBYTE(v43) = 9;
  ATL::operator+(a1: v9, a2: (int)v10, result: &sSrc, str1: v13, psz2: arrFiles[v9]);
  LOBYTE(v43) = 11;
  v14 = v33.m_pszData - 16;
  if ( _InterlockedDecrement((volatile signed __int32 *)v33.m_pszData - 1) <= 0 )
    (*(void (__stdcall **)(char *))(**(_DWORD **)v14 + 4))(a1: v14);
  LOBYTE(v43) = 13;
  v15 = v35.m_pszData - 16;
  if ( _InterlockedDecrement((volatile signed __int32 *)v35.m_pszData - 1) <= 0 )
    (*(void (__stdcall **)(char *))(**(_DWORD **)v15 + 4))(a1: v15);
  LOBYTE(v43) = 15;
  v16 = v36.m_pszData - 16;
  if ( _InterlockedDecrement((volatile signed __int32 *)v36.m_pszData - 1) <= 0 )
    (*(void (__stdcall **)(char *))(**(_DWORD **)v16 + 4))(a1: v16);
  LOBYTE(v43) = 17;
  v17 = v37.m_pszData - 16;
  if ( _InterlockedDecrement((volatile signed __int32 *)v37.m_pszData - 1) <= 0 )
    (*(void (__stdcall **)(char *))(**(_DWORD **)v17 + 4))(a1: v17);
  CUtlBuffer::CUtlBuffer(this: &bufFile, growSize: 0, initSize: 0, nFlags: 0);
  LOBYTE(v43) = 19;
  if ( !g_pFileSystem->ReadFile(
          this: g_pFileSystem,
          a2: sSrc.m_pszData,
          a3: nullptr,
          a4: &bufFile,
          a5: 0,
          a6: 0,
          a7: nullptr) )
  {
    if ( bOptRequired[v9] )
    {
      LOBYTE(v43) = 17;
      if ( bufFile.m_Memory.m_nGrowSize >= 0 )
      {
        if ( bufFile.m_Memory.m_pMemory != nullptr )
        {
          free(pMem: bufFile.m_Memory.m_pMemory);
          bufFile.m_Memory.m_pMemory = nullptr;
        }
        bufFile.m_Memory.m_nAllocationCount = 0;
      }
      LOBYTE(v43) = 4;
      v23 = sSrc.m_pszData - 16;
      if ( _InterlockedDecrement((volatile signed __int32 *)sSrc.m_pszData - 1) <= 0 )
        (*(void (__stdcall **)(char *))(**(_DWORD **)v23 + 4))(a1: v23);
      LOBYTE(v43) = 1;
      v24 = sMdlRelPath.m_pszData - 16;
      if ( _InterlockedDecrement((volatile signed __int32 *)sMdlRelPath.m_pszData - 1) <= 0 )
        (*(void (__stdcall **)(char *))(**(_DWORD **)v24 + 4))(a1: v24);
      v43 = -1;
      v25 = sMdlPath.m_pszData - 16;
      if ( _InterlockedDecrement((volatile signed __int32 *)sMdlPath.m_pszData - 1) <= 0 )
        (*(void (__stdcall **)(char *))(**(_DWORD **)v25 + 4))(a1: v25);
      return 2;
    }
    LOBYTE(v43) = 17;
    if ( bufFile.m_Memory.m_nGrowSize >= 0 )
    {
      if ( bufFile.m_Memory.m_pMemory != nullptr )
      {
        free(pMem: bufFile.m_Memory.m_pMemory);
        bufFile.m_Memory.m_pMemory = nullptr;
      }
      bufFile.m_Memory.m_nAllocationCount = 0;
    }
    goto LABEL_27;
  }
  v18 = CVmfMeshDataSupport_SaveLoadHandler::WriteBufferData(
          this: v34,
          pFile,
          bufData: &bufFile,
          szPrefix: arrNames[v9]);
  if ( v18 == ChunkFile_Ok )
  {
    LOBYTE(v43) = 17;
    if ( bufFile.m_Memory.m_nGrowSize >= 0 )
    {
      if ( bufFile.m_Memory.m_pMemory != nullptr )
      {
        free(pMem: bufFile.m_Memory.m_pMemory);
        bufFile.m_Memory.m_pMemory = nullptr;
      }
      bufFile.m_Memory.m_nAllocationCount = 0;
    }
LABEL_27:
    LOBYTE(v43) = 4;
    v19 = sSrc.m_pszData - 16;
    if ( _InterlockedDecrement((volatile signed __int32 *)sSrc.m_pszData - 1) <= 0 )
      (*(void (__stdcall **)(char *))(**(_DWORD **)v19 + 4))(a1: v19);
    goto LABEL_29;
  }
  LOBYTE(v43) = 17;
  if ( bufFile.m_Memory.m_nGrowSize >= 0 )
  {
    if ( bufFile.m_Memory.m_pMemory != nullptr )
    {
      free(pMem: bufFile.m_Memory.m_pMemory);
      bufFile.m_Memory.m_pMemory = nullptr;
    }
    bufFile.m_Memory.m_nAllocationCount = 0;
  }
  LOBYTE(v43) = 4;
  v26 = sSrc.m_pszData - 16;
  if ( _InterlockedDecrement((volatile signed __int32 *)sSrc.m_pszData - 1) <= 0 )
    (*(void (__stdcall **)(char *))(**(_DWORD **)v26 + 4))(a1: v26);
  LOBYTE(v43) = 1;
  v27 = sMdlRelPath.m_pszData - 16;
  if ( _InterlockedDecrement((volatile signed __int32 *)sMdlRelPath.m_pszData - 1) <= 0 )
    (*(void (__stdcall **)(char *))(**(_DWORD **)v27 + 4))(a1: v27);
  v43 = -1;
  v28 = sMdlPath.m_pszData - 16;
  if ( _InterlockedDecrement((volatile signed __int32 *)sMdlPath.m_pszData - 1) <= 0 )
    (*(void (__stdcall **)(char *))(**(_DWORD **)v28 + 4))(a1: v28);
  return v18;
}

//------------------------------------------------------------------------------
// Address: 0x10013560
// Name: public: void CToolHandler_SyncMesh::AppMainLoopIdle(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CToolHandler_SyncMesh::AppMainLoopIdle(CToolHandler_SyncMesh *this)
{
  CWinThread *Thread; // eax
  int v3; // eax
  CThreadFastMutex *p_m_mtxRequest; // esi
  DWORD CurrentThreadId; // eax
  CDialog *m_pAsyncDialogRequest; // ebx

  Thread = AfxGetThread();
  if ( Thread != nullptr && (v3 = (int)Thread->GetMainWnd(this: Thread)) != 0 )
    s_hMainWnd = *(HWND *)(v3 + 32);
  else
    s_hMainWnd = nullptr;
  p_m_mtxRequest = &this->m_mtxRequest;
  CurrentThreadId = GetCurrentThreadId();
  if ( CurrentThreadId != this->m_mtxRequest.m_ownerID
    && _InterlockedCompareExchange((volatile signed __int32 *)p_m_mtxRequest, CurrentThreadId, 0) != 0 )
  {
    _mm_pause();
    CThreadFastMutex::Lock(a1: &this->m_mtxRequest, a2: CurrentThreadId, a3: 0);
  }
  else
  {
    ++this->m_mtxRequest.m_depth;
  }
  if ( *((_DWORD *)this->m_strReqDmxFileName.m_pszData - 3) != 0 )
  {
    ATL::CSimpleStringT<char,0>::operator=(
      this: &this->m_strDmxFileName,
      strSrc: (ATL::CStringData *)&this->m_strReqDmxFileName);
    ATL::CSimpleStringT<char,0>::Empty(this: &this->m_strReqDmxFileName);
    ATL::CSimpleStringT<char,0>::Empty(this: &this->m_strReqCookie);
  }
  m_pAsyncDialogRequest = this->m_pAsyncDialogRequest;
  if ( m_pAsyncDialogRequest == nullptr )
    m_pAsyncDialogRequest = nullptr;
  if ( this->m_mtxRequest.m_depth-- == 1 )
    _InterlockedExchange((volatile __int32 *)p_m_mtxRequest, 0);
  if ( *((_DWORD *)this->m_strDmxFileName.m_pszData - 3) != 0 )
  {
    CToolHandler_SyncMesh::ProcessDmxRequest(this);
    ATL::CSimpleStringT<char,0>::Empty(this: &this->m_strDmxFileName);
    SwitchActiveWindow(hWndActivate: s_hMainWnd);
  }
  if ( m_pAsyncDialogRequest != nullptr )
  {
    SwitchActiveWindow(hWndActivate: s_hMainWnd);
    m_pAsyncDialogRequest->DoModal(this: m_pAsyncDialogRequest);
    this->m_pAsyncDialogRequest = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100137A0
// Name: AppMainLoopIdle_Delegate
// Source: json
//------------------------------------------------------------------------------
void __cdecl AppMainLoopIdle_Delegate()
{
  CToolHandler_SyncMesh::AppMainLoopIdle(this: &g_ToolHandlerSyncMesh);
}

//------------------------------------------------------------------------------
// Address: 0x100137B0
// Name: public: CToolHandler_SyncMesh::CToolHandler_SyncMesh(void)
// Source: json
//------------------------------------------------------------------------------
CToolHandler_SyncMesh *__thiscall CToolHandler_SyncMesh::CToolHandler_SyncMesh(CToolHandler_SyncMesh *this)
{
  ATL::IAtlStringMgr *StringManager; // eax
  ATL::IAtlStringMgr *v3; // eax
  ATL::IAtlStringMgr *v4; // eax
  ATL::IAtlStringMgr *v5; // eax
  ATL::IAtlStringMgr *v6; // eax
  ATL::IAtlStringMgr *v7; // eax
  ATL::IAtlStringMgr *v8; // eax

  this->__vftable = (CToolHandler_SyncMesh_vtbl *)&CToolHandler_SyncMesh::`vftable';
  CSelection::CSelection(this: &this->m_origSelection);
  StringManager = AfxGetStringManager();
  if ( StringManager == nullptr )
    ATL::AtlThrowImpl(hr: -2147467259);
  this->m_strTempFileName.m_pszData = (char *)&StringManager->GetNilString(this: StringManager)[1];
  v3 = AfxGetStringManager();
  if ( v3 == nullptr )
    ATL::AtlThrowImpl(hr: -2147467259);
  this->m_strMayaRequest.m_pszData = (char *)&v3->GetNilString(this: v3)[1];
  v4 = AfxGetStringManager();
  if ( v4 == nullptr )
    ATL::AtlThrowImpl(hr: -2147467259);
  this->m_strCookie.m_pszData = (char *)&v4->GetNilString(this: v4)[1];
  v5 = AfxGetStringManager();
  if ( v5 == nullptr )
    ATL::AtlThrowImpl(hr: -2147467259);
  this->m_strReqCookie.m_pszData = (char *)&v5->GetNilString(this: v5)[1];
  v6 = AfxGetStringManager();
  if ( v6 == nullptr )
    ATL::AtlThrowImpl(hr: -2147467259);
  this->m_strReqDmxFileName.m_pszData = (char *)&v6->GetNilString(this: v6)[1];
  this->m_mtxRequest.m_ownerID = 0;
  this->m_mtxRequest.m_depth = 0;
  v7 = AfxGetStringManager();
  if ( v7 == nullptr )
    ATL::AtlThrowImpl(hr: -2147467259);
  this->m_strDmxFileName.m_pszData = (char *)&v7->GetNilString(this: v7)[1];
  v8 = AfxGetStringManager();
  if ( v8 == nullptr )
    ATL::AtlThrowImpl(hr: -2147467259);
  this->m_strMdlFileName.m_pszData = (char *)&v8->GetNilString(this: v8)[1];
  this->m_pApp = nullptr;
  this->m_pDoc = nullptr;
  this->m_pView = nullptr;
  this->m_pSelection = nullptr;
  this->m_pCopiedObjects = nullptr;
  this->m_pTempDoc = nullptr;
  this->m_pAsyncDialogRequest = nullptr;
  AppRegisterMessageLoopFn(fn: AppMainLoopIdle_Delegate);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100139B0
// Name: public: class CSelection __near & CSelection::operator=(class CSelection const __near &)
// Source: json
//------------------------------------------------------------------------------
CSelection *__thiscall CSelection::operator=(CSelection *this, const CSelection *__that)
{
  this->m_pDocument = __that->m_pDocument;
  this->m_eSelectMode = __that->m_eSelectMode;
  CUtlVector<CUtlReference<CMapClass>,CUtlBlockMemory<CUtlReference<CMapClass>,int>>::operator=(
    this: &this->m_SelectionList,
    other: &__that->m_SelectionList);
  this->m_bBoundsDirty = __that->m_bBoundsDirty;
  this->m_Bounds.bmins = __that->m_Bounds.bmins;
  this->m_Bounds.bmaxs = __that->m_Bounds.bmaxs;
  this->m_LastValidBounds.bmins = __that->m_LastValidBounds.bmins;
  this->m_LastValidBounds.bmaxs = __that->m_LastValidBounds.bmaxs;
  this->m_vecLogicalMins = __that->m_vecLogicalMins;
  this->m_vecLogicalMaxs = __that->m_vecLogicalMaxs;
  CUtlVector<CUtlReference<CMapClass>,CUtlBlockMemory<CUtlReference<CMapClass>,int>>::operator=(
    this: &this->m_HitList,
    other: &__that->m_HitList);
  this->m_iCurHit = __that->m_iCurHit;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10013A60
// Name: public: virtual int CToolHandler_SyncMesh::Execute(unsigned int)
// Source: json
//------------------------------------------------------------------------------
int __userpurge CToolHandler_SyncMesh::Execute@<eax>(
        CToolHandler_SyncMesh *this@<ecx>,
        int a2@<edi>,
        unsigned int uMsg)
{
  IHammerClipboard *Instance; // eax
  CMapDoc_Friendly *m_pDoc; // ecx
  BOOL v7; // edi
  CToolManager *v8; // eax

  if ( CToolHandler_SyncMesh::Setup(this) == 0 || CToolHandler_SyncMesh::CanExecute(this) == 0 )
    return 0;
  CSelection::operator=(this: &this->m_origSelection, __that: this->m_pSelection);
  CSelection::GetBoundsCenter(this: this->m_pSelection, vecCenter: &this->m_vecSelectionCenter);
  Instance = IHammerClipboard::CreateInstance();
  m_pDoc = this->m_pDoc;
  this->m_pCopiedObjects = Instance;
  CMapDoc::Copy(this: m_pDoc, pClipboard: Instance);
  v7 = CToolHandler_SyncMesh::CreateTempDoc(this)
    && CToolHandler_SyncMesh::PasteSelToTempDoc(this) != 0
    && CToolHandler_SyncMesh::CreateTempFileName(this, a2) != 0
    && CToolHandler_SyncMesh::ExportTempDoc(this) != 0;
  CToolHandler_SyncMesh::CloseTempDoc(this);
  if ( v7 )
    CToolHandler_SyncMesh::NotifyMaya(this);
  else
    AfxMessageBox(lpszText: "Failed to prepare mesh for Maya", nType: 0x10u, nIDHelp: 0);
  v8 = ToolManager();
  CToolManager::SetTool(this: v8, eNewTool: TOOL_POINTER);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100BC6D0
// Name: public: virtual CAutoSelComboBox::~CAutoSelComboBox(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAutoSelComboBox::~CAutoSelComboBox(CAutoSelComboBox *this)
{
  CComboBox::~CComboBox(this);
}

//------------------------------------------------------------------------------
// Address: 0x1031F460
// Name: public: virtual void CVmfMeshDataSupport_SaveLoadHandler::SetCurrentEntity(class IMapEntity_Type_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVmfMeshDataSupport_SaveLoadHandler::SetCurrentEntity(VControlsListPanel *this, int itemID)
{
  this->m_nClickRow = itemID;
}

//------------------------------------------------------------------------------
// Address: 0x10333701
// Name: public: static int ATL::ChTraitsCRT<char>::GetBaseTypeLength(wchar_t const __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ATL::ChTraitsCRT<char>::GetBaseTypeLength(const wchar_t *pszSource)
{
  return WideCharToMultiByte(
           CodePage: 3u,
           dwFlags: 0,
           lpWideCharStr: pszSource,
           cchWideChar: -1,
           lpMultiByteStr: nullptr,
           cbMultiByte: 0,
           lpDefaultChar: nullptr,
           lpUsedDefaultChar: nullptr)
       - 1;
}

//------------------------------------------------------------------------------
// Address: 0x1033A6F0
// Name: public: static wchar_t __near * ATL::ChTraitsCRT<char>::AllocSysString(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
wchar_t *__cdecl ATL::ChTraitsCRT<char>::AllocSysString(const char *pchData, int nDataLength)
{
  wchar_t *v2; // eax
  wchar_t *v3; // ebx
  UINT nLen; // [esp+Ch] [ebp-4h]

  nLen = MultiByteToWideChar(
           CodePage: 3u,
           dwFlags: 0,
           lpMultiByteStr: pchData,
           cbMultiByte: nDataLength,
           lpWideCharStr: nullptr,
           cchWideChar: 0);
  v2 = SysAllocStringLen(strIn: nullptr, ui: nLen);
  v3 = v2;
  if ( v2 != nullptr )
    MultiByteToWideChar(
      CodePage: 3u,
      dwFlags: 0,
      lpMultiByteStr: pchData,
      cbMultiByte: nDataLength,
      lpWideCharStr: v2,
      cchWideChar: nLen);
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x10344CEA
// Name: public: static int ATL::ChTraitsCRT<wchar_t>::GetBaseTypeLength(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ATL::ChTraitsCRT<wchar_t>::GetBaseTypeLength(const char *pszSrc)
{
  return MultiByteToWideChar(
           CodePage: 3u,
           dwFlags: 0,
           lpMultiByteStr: pszSrc,
           cbMultiByte: -1,
           lpWideCharStr: nullptr,
           cchWideChar: 0)
       - 1;
}

//------------------------------------------------------------------------------
// Address: 0x10344D04
// Name: public: static void ATL::ChTraitsCRT<wchar_t>::ConvertToBaseType(wchar_t __near *,int,wchar_t const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ATL::ChTraitsCRT<wchar_t>::ConvertToBaseType(
        wchar_t *pszDest,
        unsigned int nDestLength,
        const wchar_t *pszSrc,
        unsigned int nSrcLength)
{
  unsigned int v4; // eax

  v4 = nSrcLength;
  if ( nSrcLength == -1 )
    v4 = wcslen(wcs: pszSrc) + 1;
  ATL::Checked::wmemcpy_s(_S1: pszDest, _N1: nDestLength, _S2: pszSrc, _N: v4);
}

//------------------------------------------------------------------------------
// Address: 0x103489FB
// Name: public: virtual CDialog::~CDialog(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDialog::~CDialog(CDialog *this)
{
  this->__vftable = (CDialog_vtbl *)&CDialog::`vftable';
  if ( this->m_hWnd != nullptr )
    CWnd::DestroyWindow(this);
  CWnd::~CWnd(this);
}

//------------------------------------------------------------------------------
// Address: 0x10348A32
// Name: public: void CDialog::Initialize(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDialog::Initialize(CDialog *this)
{
  this->m_nIDHelp = 0;
  this->m_lpszTemplateName = nullptr;
  this->m_hDialogTemplate = nullptr;
  this->m_lpDialogTemplate = nullptr;
  this->m_lpDialogInit = nullptr;
  this->m_pParentWnd = nullptr;
  this->m_hWndTop = nullptr;
  this->m_pOccDialogInfo = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10348A5C
// Name: protected: void CDialog::OnPaint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDialog::OnPaint(CDialog *this)
{
  CPaintDC v2; // [esp+10h] [ebp-64h] BYREF
  int v3; // [esp+70h] [ebp-4h]

  CPaintDC::CPaintDC(this: &v2, pWnd: this);
  v3 = 0;
  if ( CWnd::PaintWindowlessControls(this, pDC: &v2) == 0 )
    CWnd::Default(this);
  v3 = -1;
  CPaintDC::~CPaintDC(this: &v2);
}

//------------------------------------------------------------------------------
// Address: 0x10348A9F
// Name: protected: virtual int CDialog::SetOccDialogInfo(struct _AFX_OCC_DIALOG_INFO __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDialog::SetOccDialogInfo(CDialog *this, _AFX_OCC_DIALOG_INFO *pOccDialogInfo)
{
  this->m_pOccDialogInfo = pOccDialogInfo;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10348AB4
// Name: protected: virtual struct _AFX_OCC_DIALOG_INFO __near * CDialog::GetOccDialogInfo(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CDialog::GetOccDialogInfo(CBasePane *this)
{
  return this->m_dwStyle;
}

//------------------------------------------------------------------------------
// Address: 0x10348ABB
// Name: public: CDialog::CDialog(unsigned int,class CWnd __near *)
// Source: json
//------------------------------------------------------------------------------
CDialog *__thiscall CDialog::CDialog(CDialog *this, unsigned int nIDTemplate, CWnd *pParentWnd)
{
  CWnd::CWnd(this);
  this->__vftable = (CDialog_vtbl *)&CDialog::`vftable';
  CDialog::Initialize(this);
  this->m_pParentWnd = pParentWnd;
  this->m_nIDHelp = nIDTemplate;
  this->m_lpszTemplateName = (const char *)(unsigned __int16)nIDTemplate;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10348AF1
// Name: public: void CDialog::EndDialog(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDialog::EndDialog(CDialog *this, int nResult)
{
  if ( (this->m_nFlags & 0x18) != 0 )
    this->EndModalLoop(this, a2: nResult);
  EndDialog(hDlg: this->m_hWnd, nResult);
}

//------------------------------------------------------------------------------
// Address: 0x10348B1F
// Name: protected: virtual void CDialog::OnOK(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDialog::OnOK(CDialog *this)
{
  if ( CWnd::UpdateData(this, bSaveAndValidate: 1) != 0 )
    CDialog::EndDialog(this, nResult: 1);
}

//------------------------------------------------------------------------------
// Address: 0x10348B3A
// Name: protected: virtual void CDialog::OnCancel(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDialog::OnCancel(CDialog *this)
{
  CDialog::EndDialog(this, nResult: 2);
}

//------------------------------------------------------------------------------
// Address: 0x10348B42
// Name: protected: long CDialog::OnHelpHitTest(unsigned int,long)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CDialog::OnHelpHitTest(CDialog *this, unsigned int __formal, unsigned int __formala)
{
  unsigned int m_nIDHelp; // eax

  m_nIDHelp = this->m_nIDHelp;
  if ( m_nIDHelp != 0 )
    return m_nIDHelp + 0x20000;
  else
    return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10348B55
// Name: public: virtual struct CRuntimeClass __near * CDialog::GetRuntimeClass(void)const
// Source: json
//------------------------------------------------------------------------------
CRuntimeClass *__thiscall CDialog::GetRuntimeClass(CDialog *this)
{
  return &CDialog::classCDialog;
}

//------------------------------------------------------------------------------
// Address: 0x10348B81
// Name: public: virtual int CDialog::PreTranslateMessage(struct tagMSG __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDialog::PreTranslateMessage(CDialog *this, tagMSG *pMsg)
{
  CFrameWnd *TopLevelFrame; // eax
  unsigned int wParam; // eax
  HWND DlgItem; // eax

  if ( CWnd::PreTranslateMessage(this, pMsg) != 0 )
    return 1;
  TopLevelFrame = CWnd::GetTopLevelFrame(this);
  if ( TopLevelFrame != nullptr && TopLevelFrame->m_bHelpMode != 0 )
    return 0;
  if ( pMsg->message == 256 )
  {
    wParam = pMsg->wParam;
    if ( (wParam == 27 || wParam == 3)
      && (GetWindowLongA(hWnd: pMsg->hwnd, nIndex: -16) & 4) != 0
      && _AfxCompareClassName(hWnd: pMsg->hwnd, lpszClassName: "Edit") != 0 )
    {
      DlgItem = GetDlgItem(hDlg: this->m_hWnd, nIDDlgItem: 2);
      if ( DlgItem == nullptr || IsWindowEnabled(hWnd: DlgItem) )
      {
        SendMessageA(hWnd: this->m_hWnd, Msg: 0x111u, wParam: 2u, lParam: 0);
        return 1;
      }
    }
  }
  return CWnd::PreTranslateInput(this, lpMsg: pMsg);
}

//------------------------------------------------------------------------------
// Address: 0x10348C2A
// Name: public: virtual int CDialog::OnCmdMsg(unsigned int,int,void __near *,struct AFX_CMDHANDLERINFO __near *)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CDialog::OnCmdMsg(
        CDialog *this,
        unsigned int nID,
        int nCode,
        void *pExtra,
        AFX_CMDHANDLERINFO *pHandlerInfo)
{
  BOOL result; // eax
  HWND Parent; // eax
  CWnd *v8; // eax
  CWinThread *Thread; // eax

  result = true;
  if ( CCmdTarget::OnCmdMsg(this, nID, nCode, pExtra, pHandlerInfo) == 0 )
  {
    if ( nCode != 0 && nCode != -1 )
      return false;
    if ( (nID & 0x8000) == 0 || nID >= 0xF000 )
      return false;
    Parent = GetParent(hWnd: this->m_hWnd);
    v8 = CWnd::FromHandle(hWnd: Parent);
    if ( v8 == nullptr || v8->OnCmdMsg(this: v8, a2: nID, a3: nCode, a4: pExtra, a5: pHandlerInfo) == 0 )
    {
      Thread = AfxGetThread();
      if ( Thread == nullptr || Thread->OnCmdMsg(this: Thread, a2: nID, a3: nCode, a4: pExtra, a5: pHandlerInfo) == 0 )
        return false;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10348CB4
// Name: public: CDialog::CDialog(void)
// Source: json
//------------------------------------------------------------------------------
CDialog *__thiscall CDialog::CDialog(CDialog *this)
{
  CWnd::CWnd(this);
  this->__vftable = (CDialog_vtbl *)&CDialog::`vftable';
  CDialog::Initialize(this);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10348CF0
// Name: protected: int CDialog::OnQueryEndSession(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDialog::OnQueryEndSession(CDialog *this)
{
  CDialog **m_pCurrentWinApp; // esi

  m_pCurrentWinApp = (CDialog **)AfxGetModuleState()->m_pCurrentWinApp;
  if ( m_pCurrentWinApp != nullptr
    && m_pCurrentWinApp[8] == this
    && (AfxGetThreadState()->m_lastSentMsg.lParam & 1) != 0 )
  {
    return ((int (__thiscall *)(CDialog **))LODWORD((*m_pCurrentWinApp)[1].m_ulGestureArg))(a1: m_pCurrentWinApp);
  }
  else
  {
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10348D24
// Name: protected: void CDialog::OnEndSession(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDialog::OnEndSession(CDialog *this, int bEnding)
{
  CDialog **m_pCurrentWinApp; // esi
  int v4; // eax

  if ( bEnding != 0 )
  {
    m_pCurrentWinApp = (CDialog **)AfxGetModuleState()->m_pCurrentWinApp;
    if ( m_pCurrentWinApp != nullptr
      && m_pCurrentWinApp[8] == this
      && (AfxGetThreadState()->m_lastSentMsg.lParam & 1) != 0 )
    {
      v4 = ((int (__thiscall *)(CDialog **))(*m_pCurrentWinApp)[1].m_pCtrlCont)(a1: m_pCurrentWinApp);
      if ( v4 != 0 )
        (*(void (__thiscall **)(int, int))(*(_DWORD *)v4 + 52))(a1: v4, a2: 1);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10348D6C
// Name: protected: struct HWND__ __near * CDialog::PreModal(void)
// Source: json
//------------------------------------------------------------------------------
HWND__ *__thiscall CDialog::PreModal(CDialog *this)
{
  CWinApp *m_pCurrentWinApp; // eax
  CWnd *m_pParentWnd; // eax
  HWND__ *SafeOwner; // edi

  m_pCurrentWinApp = AfxGetModuleState()->m_pCurrentWinApp;
  if ( m_pCurrentWinApp != nullptr )
    CWinApp::EnableModeless(this: m_pCurrentWinApp, bEnable: 0);
  m_pParentWnd = this->m_pParentWnd;
  if ( m_pParentWnd != nullptr )
    m_pParentWnd = (CWnd *)m_pParentWnd->m_hWnd;
  SafeOwner = CWnd::GetSafeOwner_(hParent: (HWND__ *)m_pParentWnd, pWndTop: &this->m_hWndTop);
  AfxHookWindowCreate(pWnd: this);
  return SafeOwner;
}

//------------------------------------------------------------------------------
// Address: 0x10348DAE
// Name: protected: void CDialog::PostModal(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDialog::PostModal(CDialog *this)
{
  CWinApp *m_pCurrentWinApp; // eax

  AfxUnhookWindowCreate();
  CWnd::Detach(this);
  if ( IsWindow(hWnd: this->m_hWndTop) )
    EnableWindow(hWnd: this->m_hWndTop, bEnable: true);
  this->m_hWndTop = nullptr;
  m_pCurrentWinApp = AfxGetModuleState()->m_pCurrentWinApp;
  if ( m_pCurrentWinApp != nullptr )
    CWinApp::EnableModeless(this: m_pCurrentWinApp, bEnable: 1);
}

//------------------------------------------------------------------------------
// Address: 0x10348DFB
// Name: protected: long CDialog::HandleSetFont(unsigned int,long)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDialog::HandleSetFont(CDialog *this, void *wParam, int __formal)
{
  CFont *v4; // eax

  v4 = (CFont *)CGdiObject::FromHandle(h: wParam);
  this->OnSetFont(this, a2: v4);
  return CWnd::Default(this);
}

//------------------------------------------------------------------------------
// Address: 0x10348E22
// Name: protected: long CDialog::HandleInitDialog(unsigned int,long)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDialog::HandleInitDialog(CDialog *this, unsigned int __formal, unsigned int __formala)
{
  COccManager *m_pOccManager; // ecx
  void *m_lpDialogInit; // edx
  int v6; // eax
  int v8; // edi
  COleControlContainer *m_pCtrlCont; // eax
  HWND NextDlgTabItem; // eax
  CWnd *v11; // eax
  _AFX_OCC_DIALOG_INFO *m_pOccDialogInfo; // [esp-4h] [ebp-Ch]

  this->PreInitDialog(this);
  m_pOccManager = AfxGetModuleState()->m_pOccManager;
  if ( m_pOccManager != nullptr
    && this->m_pOccDialogInfo != nullptr
    && ((m_lpDialogInit = this->m_lpDialogInit, m_pOccDialogInfo = this->m_pOccDialogInfo, m_lpDialogInit == nullptr)
      ? (v6 = m_pOccManager->CreateDlgControls_2(
                this: m_pOccManager,
                a2: this,
                a3: this->m_lpszTemplateName,
                a4: m_pOccDialogInfo))
      : (v6 = m_pOccManager->CreateDlgControls(this: m_pOccManager, a2: this, a3: m_lpDialogInit, a4: m_pOccDialogInfo)),
        v6 == 0) )
  {
    CDialog::EndDialog(this, nResult: -1);
    return 0;
  }
  else
  {
    v8 = CWnd::Default(this);
    if ( v8 != 0 && (this->m_nFlags & 0x100) != 0 )
    {
      m_pCtrlCont = this->m_pCtrlCont;
      if ( m_pCtrlCont != nullptr )
        m_pCtrlCont->m_pSiteFocus = nullptr;
      NextDlgTabItem = GetNextDlgTabItem(hDlg: this->m_hWnd, hCtl: nullptr, bPrevious: false);
      v11 = CWnd::FromHandle(hWnd: NextDlgTabItem);
      if ( v11 != nullptr )
      {
        CWnd::SetFocus(this: v11);
        return 0;
      }
    }
    return v8;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10348F14
// Name: public: virtual int CDialog::OnInitDialog(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDialog::OnInitDialog(CDialog *this)
{
  int v2; // eax
  CDialog *v3; // ecx
  int updated; // eax
  CWnd *DlgItem; // esi
  int v7; // eax

  if ( this->m_lpDialogInit != nullptr )
    v2 = CWnd::ExecuteDlgInit(this, lpResource: this->m_lpDialogInit);
  else
    v2 = CWnd::ExecuteDlgInit(this, lpszResourceName: this->m_lpszTemplateName);
  v3 = this;
  if ( v2 != 0 && (updated = CWnd::UpdateData(this, bSaveAndValidate: 0), v3 = this, updated != 0) )
  {
    DlgItem = CWnd::GetDlgItem(this, nID: 57670);
    if ( DlgItem != nullptr )
    {
      v7 = AfxHelpEnabled();
      CWnd::ShowWindow(this: DlgItem, nCmdShow: v7 != 0 ? 5 : 0);
    }
    return 1;
  }
  else
  {
    CDialog::EndDialog(this: v3, nResult: -1);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10348F7A
// Name: public: virtual int CDialog::CheckAutoCenter(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDialog::CheckAutoCenter(CDialog *this)
{
  _DWORD *p_style; // esi
  HINSTANCE__ *m_hCurrentResourceHandle; // ebx
  HRSRC ResourceA; // eax
  int v5; // ebx
  int v6; // edx
  __int16 v7; // ax
  __int16 v8; // cx
  void *hDialogTemplate; // [esp+Ch] [ebp-4h]

  p_style = &this->m_lpDialogTemplate->style;
  hDialogTemplate = this->m_hDialogTemplate;
  if ( this->m_lpszTemplateName != nullptr )
  {
    m_hCurrentResourceHandle = AfxGetModuleState()->m_hCurrentResourceHandle;
    ResourceA = FindResourceA(hModule: m_hCurrentResourceHandle, lpName: this->m_lpszTemplateName, lpType: (LPCSTR)5);
    hDialogTemplate = LoadResource(hModule: m_hCurrentResourceHandle, hResInfo: ResourceA);
  }
  if ( hDialogTemplate != nullptr )
    p_style = LockResource(hResData: hDialogTemplate);
  v5 = 1;
  if ( p_style != nullptr )
  {
    v6 = *p_style;
    if ( *((_WORD *)p_style + 1) == 0xFFFF )
    {
      v6 = p_style[3];
      v7 = *((_WORD *)p_style + 9);
      v8 = *((_WORD *)p_style + 10);
    }
    else
    {
      v7 = *((_WORD *)p_style + 5);
      v8 = *((_WORD *)p_style + 6);
    }
    if ( (v6 & 0x1801) != 0 || v7 != 0 || v8 != 0 )
      v5 = 0;
  }
  if ( this->m_lpszTemplateName != nullptr )
    FreeResource(hResData: hDialogTemplate);
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x1034901A
// Name: protected: long CDialog::OnCommandHelp(unsigned int,long)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDialog::OnCommandHelp(CDialog *this, unsigned int __formal, int lParam)
{
  int v3; // esi
  unsigned int m_nIDHelp; // eax
  CWinApp *m_pCurrentWinApp; // eax

  v3 = lParam;
  if ( lParam == 0 )
  {
    m_nIDHelp = this->m_nIDHelp;
    if ( m_nIDHelp == 0 )
      return 0;
    v3 = m_nIDHelp + 0x20000;
    if ( m_nIDHelp == -131072 )
      return 0;
  }
  m_pCurrentWinApp = AfxGetModuleState()->m_pCurrentWinApp;
  if ( m_pCurrentWinApp != nullptr )
    m_pCurrentWinApp->WinHelpInternal(this: m_pCurrentWinApp, a2: v3, a3: 1u);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1034905D
// Name: protected: virtual struct AFX_MSGMAP const __near * CDialog::GetMessageMap(void)const
// Source: json
//------------------------------------------------------------------------------
const AFX_MSGMAP *__thiscall CDialog::GetMessageMap(CDialog *this)
{
  return &messageMap_15;
}

//------------------------------------------------------------------------------
// Address: 0x10349222
// Name: public: virtual int CDialog::DoModal(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDialog::DoModal(CDialog *this)
{
  HINSTANCE__ *m_hCurrentResourceHandle; // edi
  CWnd *MainWnd; // ebx
  HRSRC ResourceA; // eax
  CWnd *v6; // eax
  unsigned int v7; // edi
  int bEnableParent; // [esp+14h] [ebp-2Ch]
  int bEnableMainWnd; // [esp+18h] [ebp-28h]
  const DLGTEMPLATE *lpDialogTemplate; // [esp+24h] [ebp-1Ch]
  void *hDialogTemplate; // [esp+28h] [ebp-18h]
  HWND__ *hWndParent; // [esp+2Ch] [ebp-14h]

  lpDialogTemplate = this->m_lpDialogTemplate;
  hDialogTemplate = this->m_hDialogTemplate;
  m_hCurrentResourceHandle = AfxGetModuleState()->m_hCurrentResourceHandle;
  MainWnd = nullptr;
  if ( this->m_lpszTemplateName != nullptr )
  {
    m_hCurrentResourceHandle = AfxGetModuleState()->m_hCurrentResourceHandle;
    ResourceA = FindResourceA(hModule: m_hCurrentResourceHandle, lpName: this->m_lpszTemplateName, lpType: (LPCSTR)5);
    hDialogTemplate = LoadResource(hModule: m_hCurrentResourceHandle, hResInfo: ResourceA);
  }
  if ( hDialogTemplate != nullptr )
    lpDialogTemplate = (const DLGTEMPLATE *)LockResource(hResData: hDialogTemplate);
  if ( lpDialogTemplate == nullptr )
    return -1;
  hWndParent = CDialog::PreModal(this);
  AfxUnhookWindowCreate();
  bEnableMainWnd = 0;
  bEnableParent = 0;
  if ( hWndParent != nullptr && hWndParent != GetDesktopWindow() && IsWindowEnabled(hWnd: hWndParent) )
  {
    EnableWindow(hWnd: hWndParent, bEnable: false);
    bEnableParent = 1;
    MainWnd = AfxGetMainWnd();
    if ( MainWnd != nullptr && MainWnd->IsFrameWnd(this: MainWnd) != 0 && CWnd::IsWindowEnabled(this: MainWnd) != 0 )
    {
      CWnd::EnableWindow(this: MainWnd, bEnable: 0);
      bEnableMainWnd = 1;
    }
  }
  AfxHookWindowCreate(pWnd: this);
  v6 = CWnd::FromHandle(hWnd: hWndParent);
  if ( CWnd::CreateDlgIndirect(this, lpDialogTemplate, pParentWnd: v6, hInst: m_hCurrentResourceHandle) != 0 )
  {
    if ( (this->m_nFlags & 0x10) != 0 )
    {
      v7 = 4;
      if ( (CWnd::GetStyle(this) & 0x100) != 0 )
        v7 = 5;
      CWnd::RunModalLoop(this, dwFlags: v7);
    }
    if ( this->m_hWnd != nullptr )
      CWnd::SetWindowPos(this, pWndInsertAfter: nullptr, x: 0, y: 0, cx: 0, cy: 0, nFlags: 0x97u);
  }
  if ( bEnableMainWnd != 0 )
    CWnd::EnableWindow(this: MainWnd, bEnable: 1);
  if ( bEnableParent != 0 )
    EnableWindow(hWnd: hWndParent, bEnable: true);
  if ( hWndParent != nullptr && GetActiveWindow() == this->m_hWnd )
    SetActiveWindow(hWnd: hWndParent);
  this->DestroyWindow(this);
  CDialog::PostModal(this);
  if ( this->m_lpszTemplateName != nullptr )
    FreeResource(hResData: hDialogTemplate);
  return this->m_nModalResult;
}

//------------------------------------------------------------------------------
// Address: 0x103493F1
// Name: protected: int CDialog::CreateIndirect(struct DLGTEMPLATE const __near *,class CWnd __near *,void __near *,struct HINSTANCE__ __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDialog::CreateIndirect(
        CDialog *this,
        const DLGTEMPLATE *lpDialogTemplate,
        CWnd *pParentWnd,
        void *lpDialogInit,
        HINSTANCE__ *hInst)
{
  CWnd *MainWnd; // eax

  MainWnd = pParentWnd;
  if ( pParentWnd == nullptr )
    MainWnd = AfxGetMainWnd();
  this->m_lpDialogInit = lpDialogInit;
  return CWnd::CreateDlgIndirect(this, lpDialogTemplate, pParentWnd: MainWnd, hInst);
}

//------------------------------------------------------------------------------
// Address: 0x10349479
// Name: protected: int CDialog::CreateIndirect(void __near *,class CWnd __near *,struct HINSTANCE__ __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDialog::CreateIndirect(CDialog *this, void *hDialogTemplate, CWnd *pParentWnd, HINSTANCE__ *hInst)
{
  const DLGTEMPLATE *v5; // eax

  v5 = (const DLGTEMPLATE *)LockResource(hResData: hDialogTemplate);
  return CDialog::CreateIndirect(this, lpDialogTemplate: v5, pParentWnd, lpDialogInit: nullptr, hInst);
}

//------------------------------------------------------------------------------
// Address: 0x1034949F
// Name: public: virtual int CDialog::CreateIndirect(struct DLGTEMPLATE const __near *,class CWnd __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDialog::CreateIndirect(
        CDialog *this,
        const DLGTEMPLATE *lpDialogTemplate,
        CWnd *pParentWnd,
        void *lpDialogInit)
{
  return CDialog::CreateIndirect(this, lpDialogTemplate, pParentWnd, lpDialogInit, hInst: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x103494B8
// Name: public: virtual int CDialog::Create(char const __near *,class CWnd __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDialog::Create(CDialog *this, const char *lpszTemplateName, CWnd *pParentWnd)
{
  HINSTANCE__ *m_hCurrentResourceHandle; // esi
  HRSRC ResourceA; // eax
  HGLOBAL Resource; // ebx
  int Indirect; // esi

  this->m_lpszTemplateName = lpszTemplateName;
  if ( ((unsigned int)lpszTemplateName & 0xFFFF0000) == 0 && this->m_nIDHelp == 0 )
    this->m_nIDHelp = (unsigned __int16)lpszTemplateName;
  m_hCurrentResourceHandle = AfxGetModuleState()->m_hCurrentResourceHandle;
  ResourceA = FindResourceA(hModule: m_hCurrentResourceHandle, lpName: lpszTemplateName, lpType: (LPCSTR)5);
  Resource = LoadResource(hModule: m_hCurrentResourceHandle, hResInfo: ResourceA);
  Indirect = CDialog::CreateIndirect(this, hDialogTemplate: Resource, pParentWnd, hInst: m_hCurrentResourceHandle);
  FreeResource(hResData: Resource);
  return Indirect;
}

//------------------------------------------------------------------------------
// Address: 0x10349516
// Name: public: virtual int CDialog::CreateIndirect(void __near *,class CWnd __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDialog::CreateIndirect(CDialog *this, void *hDialogTemplate, CWnd *pParentWnd)
{
  return CDialog::CreateIndirect(this, hDialogTemplate, pParentWnd, hInst: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x103496B7
// Name: public: virtual struct ATL::CStringData __near * CAfxStringMgr::Reallocate(struct ATL::CStringData __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
ATL::CStringData *__thiscall CAfxStringMgr::Reallocate(
        CAfxStringMgr *this,
        ATL::CStringData *pData,
        int nChars,
        int nCharSize)
{
  ATL::CStringData *result; // eax

  if ( nChars < 0 )
    return nullptr;
  result = (ATL::CStringData *)_realloc_crt(ptr: pData, size: nCharSize * (nChars + 1) + 16);
  if ( result == nullptr )
    return nullptr;
  result->nAllocLength = nChars;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1034BFC0
// Name: public: int CStringArray::Append(class CStringArray const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CStringArray::Append(CStringArray *this, const CStringArray *src)
{
  int m_nSize; // ebx

  if ( this == src )
    AfxThrowInvalidArgException();
  m_nSize = this->m_nSize;
  CStringArray::SetSize(this, nNewSize: m_nSize + src->m_nSize, nGrowBy: -1);
  CopyElements(pDest: &this->m_pData[m_nSize], pSrc: src->m_pData, nCount: src->m_nSize);
  return m_nSize;
}

//------------------------------------------------------------------------------
// Address: 0x103B94D3
// Name: public: void CMFCZoomKernel::Empty(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMFCZoomKernel::Empty(CMFCZoomKernel *this)
{
  unsigned int i; // edi
  CMFCZoomKernel::XKernelList *v3; // eax

  if ( this->m_List != nullptr )
  {
    for ( i = 0; i < this->m_Size; ++i )
    {
      v3 = &this->m_List[i];
      if ( v3->count != 0 )
        operator delete(p: v3->stat);
    }
    operator delete(p: this->m_List);
    this->m_List = nullptr;
    this->m_Size = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10414EB3
// Name: public: void COleDataSource::Empty(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COleDataSource::Empty(COleDataSource *this)
{
  int v2; // edi
  unsigned int i; // ebx

  v2 = 0;
  if ( this->m_pDataCache != nullptr )
  {
    for ( i = 0; i < this->m_nSize; ++v2 )
    {
      CoTaskMemFree(pv: this->m_pDataCache[v2].m_formatEtc.ptd);
      ReleaseStgMedium(a1: &this->m_pDataCache[v2].m_stgMedium);
      ++i;
    }
    operator delete(p: this->m_pDataCache);
    this->m_pDataCache = nullptr;
    this->m_nMaxSize = 0;
    this->m_nSize = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10415D7E
// Name: public: int CMFCToolBarDropTarget::Register(class CMFCToolBar __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CMFCToolBarDropTarget::Register(CMFCToolBarDropTarget *this, CMFCToolBar *pOwner)
{
  this->m_pOwner = pOwner;
  return COleDropTarget::Register(this, pWnd: pOwner);
}

//------------------------------------------------------------------------------
// Address: 0x10421499
// Name: public: int COleDropTarget::Register(class CWnd __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall COleDropTarget::Register(COleDropTarget *this, CWnd *pWnd)
{
  IDropTarget *Interface; // eax
  IUnknown *lpUnknown; // [esp+8h] [ebp-4h]

  lpUnknown = CCmdTarget::GetInterface(this, iid: &IID_IUnknown);
  if ( CoLockObjectExternal(pUnk: lpUnknown, fLock: true, fLastUnlockReleases: false) != 0 )
    return 0;
  Interface = (IDropTarget *)CCmdTarget::GetInterface(this, iid: &IID_IDropTarget);
  if ( RegisterDragDrop(hwnd: pWnd->m_hWnd, pDropTarget: Interface) != 0 )
  {
    CoLockObjectExternal(pUnk: lpUnknown, fLock: false, fLastUnlockReleases: false);
    return 0;
  }
  else
  {
    this->m_hWnd = pWnd->m_hWnd;
    pWnd->m_pDropTarget = this;
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1033A735
// Name: unsigned short AfxCtxRegisterClassA(struct tagWNDCLASSA const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned __int16 __cdecl AfxCtxRegisterClassA(const tagWNDCLASSA *lpWndClass)
{
  AFX_MODULE_STATE *ModuleState; // eax
  BOOL v2; // eax
  BOOL v4; // esi
  DWORD LastError; // edi
  unsigned int ulActCtxCookie; // [esp+10h] [ebp-20h] BYREF
  int v7; // [esp+14h] [ebp-1Ch]
  int v8; // [esp+2Ch] [ebp-4h]

  ulActCtxCookie = 0;
  ModuleState = AfxGetModuleState();
  v2 = ActivateActCtx(hActCtx: ModuleState->m_hActCtx, lpCookie: &ulActCtxCookie);
  v7 = 0;
  if ( !v2 )
    return 0;
  v8 = 0;
  v7 = RegisterClassA(lpWndClass);
  v8 = -2;
  v4 = (_WORD)v7 == 0;
  if ( (_WORD)v7 != 0 )
    LastError = 0;
  else
    LastError = GetLastError();
  DeactivateActCtx(dwFlags: 0, ulCookie: ulActCtxCookie);
  if ( v4 )
    SetLastError(dwErrCode: LastError);
  return v7;
}

//------------------------------------------------------------------------------
// Address: 0x1033A7C0
// Name: int AfxCtxGetClassInfoA(struct HINSTANCE__ __near *,char const __near *,struct tagWNDCLASSA __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl AfxCtxGetClassInfoA(HINSTANCE__ *hInstance, const char *lpClassName, tagWNDCLASSA *lpWndClass)
{
  AFX_MODULE_STATE *ModuleState; // eax
  BOOL v4; // eax
  BOOL v6; // esi
  DWORD LastError; // edi
  unsigned int ulActCtxCookie; // [esp+10h] [ebp-20h] BYREF
  int ClassInfoA; // [esp+14h] [ebp-1Ch]
  int v10; // [esp+2Ch] [ebp-4h]

  ulActCtxCookie = 0;
  ModuleState = AfxGetModuleState();
  v4 = ActivateActCtx(hActCtx: ModuleState->m_hActCtx, lpCookie: &ulActCtxCookie);
  ClassInfoA = 0;
  if ( !v4 )
    return 0;
  v10 = 0;
  ClassInfoA = GetClassInfoA(hInstance, lpClassName, lpWndClass);
  v10 = -2;
  v6 = ClassInfoA == 0;
  if ( ClassInfoA != 0 )
    LastError = 0;
  else
    LastError = GetLastError();
  DeactivateActCtx(dwFlags: 0, ulCookie: ulActCtxCookie);
  if ( v6 )
    SetLastError(dwErrCode: LastError);
  return ClassInfoA;
}

//------------------------------------------------------------------------------
// Address: 0x1033A84C
// Name: int AfxCtxGetClassInfoExA(struct HINSTANCE__ __near *,char const __near *,struct tagWNDCLASSEXA __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl AfxCtxGetClassInfoExA(HINSTANCE__ *unnamed1, const char *unnamed2, tagWNDCLASSEXA *unnamed3)
{
  AFX_MODULE_STATE *ModuleState; // eax
  BOOL v4; // eax
  BOOL v6; // esi
  DWORD LastError; // edi
  unsigned int ulActCtxCookie; // [esp+10h] [ebp-20h] BYREF
  int ClassInfo; // [esp+14h] [ebp-1Ch]
  int v10; // [esp+2Ch] [ebp-4h]

  ulActCtxCookie = 0;
  ModuleState = AfxGetModuleState();
  v4 = ActivateActCtx(hActCtx: ModuleState->m_hActCtx, lpCookie: &ulActCtxCookie);
  ClassInfo = 0;
  if ( !v4 )
    return 0;
  v10 = 0;
  ClassInfo = GetClassInfoExA(hInstance: unnamed1, lpszClass: unnamed2, lpwcx: unnamed3);
  v10 = -2;
  v6 = ClassInfo == 0;
  if ( ClassInfo != 0 )
    LastError = 0;
  else
    LastError = GetLastError();
  DeactivateActCtx(dwFlags: 0, ulCookie: ulActCtxCookie);
  if ( v6 )
    SetLastError(dwErrCode: LastError);
  return ClassInfo;
}

//------------------------------------------------------------------------------
// Address: 0x1033A8D8
// Name: int AfxCtxMessageBoxA(struct HWND__ __near *,char const __near *,char const __near *,unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl AfxCtxMessageBoxA(HWND__ *hWnd, const char *lpText, const char *lpCaption, UINT uType)
{
  AFX_MODULE_STATE *ModuleState; // eax
  BOOL v5; // eax
  BOOL v7; // esi
  DWORD LastError; // edi
  unsigned int ulActCtxCookie; // [esp+10h] [ebp-20h] BYREF
  int v10; // [esp+14h] [ebp-1Ch]
  int v11; // [esp+2Ch] [ebp-4h]

  ulActCtxCookie = 0;
  ModuleState = AfxGetModuleState();
  v5 = ActivateActCtx(hActCtx: ModuleState->m_hActCtx, lpCookie: &ulActCtxCookie);
  v10 = 0;
  if ( !v5 )
    return 0;
  v11 = 0;
  v10 = MessageBoxA(hWnd, lpText, lpCaption, uType);
  v11 = -2;
  v7 = v10 == 0;
  if ( v10 != 0 )
    LastError = 0;
  else
    LastError = GetLastError();
  DeactivateActCtx(dwFlags: 0, ulCookie: ulActCtxCookie);
  if ( v7 )
    SetLastError(dwErrCode: LastError);
  return v10;
}

//------------------------------------------------------------------------------
// Address: 0x1033A967
// Name: struct HINSTANCE__ __near * AfxCtxLoadLibraryA(char const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
HINSTANCE__ *__cdecl AfxCtxLoadLibraryA(const char *lpLibFileName)
{
  AFX_MODULE_STATE *ModuleState; // eax
  BOOL v2; // eax
  BOOL v4; // esi
  DWORD LastError; // edi
  unsigned int ulActCtxCookie; // [esp+10h] [ebp-20h] BYREF
  HINSTANCE__ *LibraryA; // [esp+14h] [ebp-1Ch]
  int v8; // [esp+2Ch] [ebp-4h]

  ulActCtxCookie = 0;
  ModuleState = AfxGetModuleState();
  v2 = ActivateActCtx(hActCtx: ModuleState->m_hActCtx, lpCookie: &ulActCtxCookie);
  LibraryA = nullptr;
  if ( !v2 )
    return nullptr;
  v8 = 0;
  LibraryA = LoadLibraryA(lpLibFileName);
  v8 = -2;
  v4 = LibraryA == nullptr;
  if ( LibraryA != nullptr )
    LastError = 0;
  else
    LastError = GetLastError();
  DeactivateActCtx(dwFlags: 0, ulCookie: ulActCtxCookie);
  if ( v4 )
    SetLastError(dwErrCode: LastError);
  return LibraryA;
}

//------------------------------------------------------------------------------
// Address: 0x1033A9ED
// Name: struct HINSTANCE__ __near * AfxCtxLoadLibraryW(wchar_t const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
HINSTANCE__ *__cdecl AfxCtxLoadLibraryW(const wchar_t *lpLibFileName)
{
  AFX_MODULE_STATE *ModuleState; // eax
  BOOL v2; // eax
  BOOL v4; // esi
  DWORD LastError; // edi
  unsigned int ulActCtxCookie; // [esp+10h] [ebp-20h] BYREF
  HINSTANCE__ *LibraryW; // [esp+14h] [ebp-1Ch]
  int v8; // [esp+2Ch] [ebp-4h]

  ulActCtxCookie = 0;
  ModuleState = AfxGetModuleState();
  v2 = ActivateActCtx(hActCtx: ModuleState->m_hActCtx, lpCookie: &ulActCtxCookie);
  LibraryW = nullptr;
  if ( !v2 )
    return nullptr;
  v8 = 0;
  LibraryW = LoadLibraryW(lpLibFileName);
  v8 = -2;
  v4 = LibraryW == nullptr;
  if ( LibraryW != nullptr )
    LastError = 0;
  else
    LastError = GetLastError();
  DeactivateActCtx(dwFlags: 0, ulCookie: ulActCtxCookie);
  if ( v4 )
    SetLastError(dwErrCode: LastError);
  return LibraryW;
}

//------------------------------------------------------------------------------
// Address: 0x1033AA73
// Name: int AfxInvariantStrICmp(char const __near *,char const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl AfxInvariantStrICmp(const char *pszLeft, const char *pszRight)
{
  return CompareStringA(
           Locale: 0x409u,
           dwCmpFlags: 1u,
           lpString1: pszLeft,
           cchCount1: -1,
           lpString2: pszRight,
           cchCount2: -1)
       - 2;
}

//------------------------------------------------------------------------------
// Address: 0x1033AA94
// Name: public: void CInternalGlobalLock::Lock(int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CInternalGlobalLock::Lock(CInternalGlobalLock *this, int nLockType)
{
  int m_nLockType; // ecx

  if ( nLockType != 0x7FFFFFFF )
  {
    if ( this->m_nLockType != 0x7FFFFFFF && this->m_nLockType != nLockType )
LABEL_4:
      AfxThrowInvalidArgException();
    this->m_nLockType = nLockType;
  }
  m_nLockType = this->m_nLockType;
  if ( m_nLockType == 0x7FFFFFFF )
    goto LABEL_4;
  AfxLockGlobals(nLockType: m_nLockType);
}

//------------------------------------------------------------------------------
// Address: 0x1033AAC8
// Name: public: void CInternalGlobalLock::Unlock(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CInternalGlobalLock::Unlock(CInternalGlobalLock *this)
{
  if ( this->m_nLockType != 0x7FFFFFFF )
  {
    AfxUnlockGlobals(nLockType: this->m_nLockType);
    this->m_nLockType = 0x7FFFFFFF;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10348B1B
// Name: public: virtual void CMultiPaneFrameWnd::AdjustLayout(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMultiPaneFrameWnd::AdjustLayout(CMFCRibbonBaseElement *this)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x10348B1C
// Name: public: virtual void CVSListBoxBase::OnAfterMoveItemUp(int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CVSListBoxBase::OnAfterMoveItemUp(CMFCRibbonBaseElement *this, CDC *__formal)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x10348EBC
// Name: int AfxHelpEnabled(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __stdcall AfxHelpEnabled()
{
  CWnd *MainWnd; // eax
  AFX_MODULE_STATE *ModuleState; // eax
  AFX_CMDHANDLERINFO info; // [esp+4h] [ebp-8h] BYREF

  if ( AfxGetModuleState()->m_pCurrentWinApp == nullptr )
    return 0;
  MainWnd = AfxGetMainWnd();
  if ( MainWnd != nullptr && MainWnd->OnCmdMsg(this: MainWnd, a2: 57670u, a3: 0, a4: nullptr, a5: &info) != 0 )
    return 1;
  ModuleState = AfxGetModuleState();
  return ModuleState->m_pCurrentWinApp->OnCmdMsg(
           this: ModuleState->m_pCurrentWinApp,
           a2: 57670u,
           a3: 0,
           a4: nullptr,
           a5: &info);
}

//------------------------------------------------------------------------------
// Address: 0x1034952C
// Name: int AfxLoadString(unsigned int,char __near *,unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __stdcall AfxLoadString(unsigned int nID, char *lpszBuf, unsigned int nMaxBuf)
{
  AFX_MODULE_STATE *ModuleState; // eax
  ATL::ATLSTRINGRESOURCEIMAGE *StringResourceImage; // eax
  int result; // eax

  if ( lpszBuf == nullptr || nMaxBuf == 0 )
    AfxThrowInvalidArgException();
  ModuleState = AfxGetModuleState();
  StringResourceImage = ATL::AtlGetStringResourceImage(hInstance: ModuleState->m_hCurrentResourceHandle, id: nID);
  if ( StringResourceImage != nullptr )
  {
    result = WideCharToMultiByte(
               CodePage: 0,
               dwFlags: 0,
               lpWideCharStr: StringResourceImage->achString,
               cchWideChar: StringResourceImage->nLength,
               lpMultiByteStr: lpszBuf,
               cbMultiByte: nMaxBuf - 1,
               lpDefaultChar: nullptr,
               lpUsedDefaultChar: nullptr);
    lpszBuf[result] = 0;
  }
  else
  {
    *lpszBuf = 0;
    return 0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10349586
// Name: struct HINSTANCE__ __near * AfxFindStringResourceHandle(unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
HINSTANCE__ *__stdcall AfxFindStringResourceHandle(unsigned int __formal)
{
  return AfxGetModuleState()->m_hCurrentResourceHandle;
}

//------------------------------------------------------------------------------
// Address: 0x10349591
// Name: int AfxExtractSubString(class ATL::CStringT<char,class StrTraitMFC<char,class ATL::ChTraitsCRT<char>>> __near &,char const __near *,int,char)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __stdcall AfxExtractSubString(
        ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *rString,
        const char *lpszFullString,
        int iSubString,
        char chSep)
{
  const unsigned __int8 *v4; // esi
  const unsigned __int8 *v6; // eax
  const unsigned __int8 *v7; // eax
  int v8; // eax
  char *BufferSetLength; // eax
  unsigned int v10; // [esp-10h] [ebp-14h]
  unsigned int v11; // [esp-8h] [ebp-Ch]

  v4 = (const unsigned __int8 *)lpszFullString;
  if ( lpszFullString == nullptr )
    return 0;
  if ( iSubString != 0 )
  {
    while ( 1 )
    {
      --iSubString;
      v6 = _mbschr(string: v4, c: chSep);
      if ( v6 == nullptr )
        break;
      v4 = v6 + 1;
      if ( iSubString == 0 )
        goto LABEL_6;
    }
    ATL::CSimpleStringT<char,0>::Empty(this: rString);
    return 0;
  }
  else
  {
LABEL_6:
    v7 = _mbschr(string: v4, c: chSep);
    if ( v7 != nullptr )
      v8 = v7 - v4;
    else
      v8 = lstrlenA(lpString: (LPCSTR)v4);
    v11 = v8;
    v10 = v8;
    BufferSetLength = ATL::CSimpleStringT<char,0>::GetBufferSetLength(this: rString, nLength: v8);
    ATL::Checked::memcpy_s(_S1: BufferSetLength, _S1max: v10, _S2: v4, _N: v11);
    ATL::CSimpleStringT<char,0>::ReleaseBuffer(this: rString, nNewLength: -1);
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10349616
// Name: unsigned int HashKey<char const __near *>(char const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __stdcall HashKey<char const *>(char *key)
{
  unsigned int v2; // esi
  unsigned int v3; // eax
  unsigned int v4; // ecx
  unsigned int v5; // eax
  int v6; // edx
  unsigned int uHashVal; // [esp+14h] [ebp+8h]

  if ( !AfxIsValidString(psz: key, nLength: -1) )
    AfxThrowInvalidArgException();
  uHashVal = -2128831035;
  v2 = 0;
  strlen(buf: (unsigned __int8 *)key);
  v4 = v3;
  v5 = v3 / 0xA + 1;
  if ( v4 != 0 )
  {
    do
    {
      v6 = (16777619 * uHashVal) ^ key[v2];
      v2 += v5;
      uHashVal = v6;
    }
    while ( v2 < v4 );
  }
  return uHashVal;
}

//------------------------------------------------------------------------------
// Address: 0x1034C001
// Name: public: void CStringArray::Copy(class CStringArray const __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CStringArray::Copy(CStringArray *this, const CStringArray *src)
{
  if ( this != src )
  {
    CStringArray::SetSize(this, nNewSize: src->m_nSize, nGrowBy: -1);
    CopyElements(pDest: this->m_pData, pSrc: src->m_pData, nCount: src->m_nSize);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1034C030
// Name: public: void CStringArray::SetAtGrow(int,class ATL::CStringT<char,class StrTraitMFC<char,class ATL::ChTraitsCRT<char>>> const __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CStringArray::SetAtGrow(CStringArray *this, int nIndex, ATL::CStringData *newElement)
{
  int m_nMaxSize; // ecx
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *m_pData; // eax

  if ( nIndex < 0 )
LABEL_2:
    AfxThrowInvalidArgException();
  if ( nIndex >= this->m_nSize )
  {
    m_nMaxSize = this->m_nMaxSize;
    if ( nIndex >= m_nMaxSize )
    {
      m_pData = this->m_pData;
      if ( newElement >= (ATL::CStringData *)m_pData && newElement < (ATL::CStringData *)&m_pData[m_nMaxSize] )
        goto LABEL_2;
    }
    CStringArray::SetSize(this, nNewSize: nIndex + 1, nGrowBy: -1);
  }
  ATL::CSimpleStringT<char,0>::operator=(this: &this->m_pData[nIndex], strSrc: newElement);
}

//------------------------------------------------------------------------------
// Address: 0x1034C082
// Name: public: void CStringArray::InsertAt(int,class ATL::CStringT<char,class StrTraitMFC<char,class ATL::ChTraitsCRT<char>>> const __near &,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CStringArray::InsertAt(CStringArray *this, int nIndex, ATL::CStringData *newElement, int nCount)
{
  int v4; // edi
  int v6; // ebx
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *v7; // ecx

  v4 = nCount;
  CStringArray::InsertEmpty(this, nIndex, nCount);
  if ( nCount != 0 )
  {
    v6 = nIndex;
    do
    {
      v7 = &this->m_pData[v6++];
      ATL::CSimpleStringT<char,0>::operator=(this: v7, strSrc: newElement);
      --v4;
    }
    while ( v4 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1034C0BA
// Name: public: void CStringArray::SetAtGrow(int,char const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CStringArray::SetAtGrow(CStringArray *this, int nIndex, const char *newElement)
{
  if ( nIndex < 0 )
    AfxThrowInvalidArgException();
  if ( nIndex >= this->m_nSize )
    CStringArray::SetSize(this, nNewSize: nIndex + 1, nGrowBy: -1);
  ATL::CSimpleStringT<char,0>::SetString(this: &this->m_pData[nIndex], pszSrc: newElement);
}

//------------------------------------------------------------------------------
// Address: 0x103B9514
// Name: protected: void CMFCScanliner::empty(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCScanliner::empty(CMFCScanliner *this)
{
  this->m_line = nullptr;
  this->m_pitch = 0;
  this->m_start_row = 0;
  this->m_start_col = 0;
  this->m_rows = 0;
  this->m_cols = 0;
  this->m_offset = 0;
  this->m_height = 0;
  this->m_line_begin = nullptr;
  this->m_line_end = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x103B9534
// Name: protected: unsigned char __near * CMFCScanliner::_begin(unsigned char __near *)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned __int8 *__thiscall CMFCScanliner::_begin(CMFCScanliner *this, unsigned __int8 *data)
{
  unsigned int m_start_row; // eax
  unsigned int m_start_col; // edx
  unsigned __int8 *result; // eax

  if ( this->m_offset <= 0 )
    m_start_row = this->m_height - this->m_start_row - 1;
  else
    m_start_row = this->m_start_row;
  m_start_col = this->m_start_col;
  result = &data[this->m_pitch * m_start_row];
  if ( m_start_col != 0 )
    result += m_start_col * this->m_channels;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103B9566
// Name: protected: unsigned char __near * CMFCScanliner::_end(unsigned char __near *)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned __int8 *__thiscall CMFCScanliner::_end(CMFCScanliner *this, unsigned __int8 *data)
{
  unsigned int v2; // eax
  unsigned int m_start_col; // edx
  unsigned __int8 *result; // eax

  if ( this->m_offset <= 0 )
    v2 = this->m_height - this->m_rows - this->m_start_row;
  else
    v2 = this->m_rows + this->m_start_row - 1;
  m_start_col = this->m_start_col;
  result = &data[this->m_pitch * v2];
  if ( m_start_col != 0 )
    result += m_start_col * this->m_channels;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10414F04
// Name: protected: struct AFX_DATACACHE_ENTRY __near * COleDataSource::Lookup(struct tagFORMATETC __near *,enum tagDATADIR)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
AFX_DATACACHE_ENTRY *__thiscall COleDataSource::Lookup(
        COleDataSource *this,
        tagFORMATETC *lpFormatEtc,
        tagDATADIR nDataDir)
{
  AFX_DATACACHE_ENTRY *v4; // eax
  unsigned int dwAspect; // edi
  int lindex; // ecx
  int v7; // edx
  tagDVTARGETDEVICE *ptd; // ecx
  tagDVTARGETDEVICE *v9; // eax
  bool v10; // zf
  AFX_DATACACHE_ENTRY *pLast; // [esp+4h] [ebp-Ch]
  unsigned int nIndex; // [esp+8h] [ebp-8h]
  int v14; // [esp+Ch] [ebp-4h]

  pLast = nullptr;
  nIndex = 0;
  if ( this->m_nSize != 0 )
  {
    v14 = 0;
    do
    {
      v4 = &this->m_pDataCache[v14];
      if ( v4->m_formatEtc.cfFormat == lpFormatEtc->cfFormat && (v4->m_formatEtc.tymed & lpFormatEtc->tymed) != 0 )
      {
        if ( (dwAspect = v4->m_formatEtc.dwAspect) == 2
          || dwAspect == 4
          || v4->m_stgMedium.tymed == 0
          || (lindex = v4->m_formatEtc.lindex, v7 = lpFormatEtc->lindex, lindex == v7)
          || lindex == 0 && v7 == -1
          || lindex == -1 && v7 == 0 )
        {
          if ( dwAspect == lpFormatEtc->dwAspect && v4->m_nDataDir == nDataDir )
          {
            ptd = lpFormatEtc->ptd;
            pLast = &this->m_pDataCache[v14];
            v9 = v4->m_formatEtc.ptd;
            if ( v9 == nullptr )
            {
              v10 = ptd == nullptr;
              goto LABEL_20;
            }
            if ( ptd != nullptr && v9->tdSize == ptd->tdSize )
            {
              v10 = memcmp(lhs: v9, rhs: ptd, siz: v9->tdSize) == 0;
LABEL_20:
              if ( v10 )
                return pLast;
            }
          }
        }
      }
      ++nIndex;
      ++v14;
    }
    while ( nIndex < this->m_nSize );
  }
  return pLast;
}

//------------------------------------------------------------------------------
// Address: 0x10414FC4
// Name: public: virtual int COleDataSource::OnRenderData(struct tagFORMATETC __near *,struct tagSTGMEDIUM __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall COleDataSource::OnRenderData(COleDataSource *this, tagFORMATETC *lpFormatEtc, HBITMAP__ *lpStgMedium)
{
  tagFORMATETC *v4; // eax
  tagSTGMEDIUM *v5; // esi
  COleDataSource_vtbl *v6; // edx
  tagSTGMEDIUM *v7; // eax
  HBITMAP__ *v9; // eax
  bool v10; // zf
  IStream *v11; // eax
  CSharedFile file; // [esp+10h] [ebp-60h] BYREF
  COleStreamFile v13; // [esp+48h] [ebp-28h] BYREF
  int v14; // [esp+6Ch] [ebp-4h]

  v4 = lpFormatEtc;
  v5 = (tagSTGMEDIUM *)lpStgMedium;
  if ( (lpFormatEtc->tymed & 1) != 0 )
  {
    v6 = this->__vftable;
    lpStgMedium = *((HBITMAP__ **)lpStgMedium + 1);
    if ( v6->OnRenderGlobalData(this, a2: lpFormatEtc, a3: (void **)&lpStgMedium) != 0 )
    {
      v7 = (tagSTGMEDIUM *)lpStgMedium;
      v5->tymed = 1;
      v5->hBitmap = (HBITMAP__ *)v7;
      return 1;
    }
    CSharedFile::CSharedFile(this: &file, nAllocFlags: 2u, nGrowBytes: 0x1000u);
    v14 = 0;
    if ( v5->tymed == 1 )
      CSharedFile::SetHandle(this: &file, hGlobalMemory: v5->hBitmap, bAllowGrow: 0);
    if ( this->OnRenderFileData(this, a2: lpFormatEtc, a3: &file) != 0 )
    {
      v5->tymed = 1;
      v9 = (HBITMAP__ *)CSharedFile::Detach(this: &file);
      v14 = -1;
      v5->hBitmap = v9;
      CSharedFile::~CSharedFile(this: &file);
      return 1;
    }
    if ( v5->tymed == 1 )
      CSharedFile::Detach(this: &file);
    v14 = -1;
    CSharedFile::~CSharedFile(this: &file);
    v4 = lpFormatEtc;
  }
  if ( (v4->tymed & 4) != 0 )
  {
    COleStreamFile::COleStreamFile(this: &v13, lpStream: nullptr);
    v10 = v5->tymed == 4;
    v14 = 1;
    if ( v10 )
    {
      COleStreamFile::Attach(this: &v13, lpStream: v5->pstm);
    }
    else if ( !COleStreamFile::CreateMemoryStream(this: &v13, pError: nullptr) )
    {
      AfxThrowMemoryException();
    }
    if ( this->OnRenderFileData(this, a2: lpFormatEtc, a3: &v13) != 0 )
    {
      v5->tymed = 4;
      v11 = COleStreamFile::Detach(this: &v13);
      v14 = -1;
      v5->hBitmap = (HBITMAP__ *)v11;
      COleStreamFile::~COleStreamFile(this: &v13);
      return 1;
    }
    if ( v5->tymed == 4 )
      COleStreamFile::Detach(this: &v13);
    v14 = -1;
    COleStreamFile::~COleStreamFile(this: &v13);
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x104150FF
// Name: protected: virtual struct AFX_INTERFACEMAP const __near * CEnumFormatEtc::GetInterfaceMap(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
const AFX_INTERFACEMAP *__thiscall CEnumFormatEtc::GetInterfaceMap(CEnumFormatEtc *this)
{
  return &CEnumFormatEtc::interfaceMap;
}

//------------------------------------------------------------------------------
// Address: 0x10415105
// Name: public: CEnumFormatEtc::CEnumFormatEtc(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CEnumFormatEtc *__thiscall CEnumFormatEtc::CEnumFormatEtc(CEnumFormatEtc *this)
{
  CEnumArray::CEnumArray(this, nSizeElem: 0x14u, pvEnum: nullptr, nSize: 0, bNeedFree: 1);
  this->m_nMaxSize = 0;
  this->__vftable = (CEnumFormatEtc_vtbl *)&CEnumFormatEtc::`vftable';
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10415125
// Name: public: virtual CEnumFormatEtc::~CEnumFormatEtc(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CEnumFormatEtc::~CEnumFormatEtc(CEnumFormatEtc *this)
{
  unsigned int v2; // ebx
  LPVOID *v3; // edi

  v2 = 0;
  this->__vftable = (CEnumFormatEtc_vtbl *)&CEnumFormatEtc::`vftable';
  if ( this->m_pClonedFrom == nullptr && this->m_nSize != 0 )
  {
    v3 = (LPVOID *)(this->m_pvEnum + 4);
    do
    {
      CoTaskMemFree(pv: *v3);
      ++v2;
      v3 += 5;
    }
    while ( v2 < this->m_nSize );
  }
  CEnumArray::~CEnumArray(this);
}

//------------------------------------------------------------------------------
// Address: 0x1041515F
// Name: protected: virtual int CEnumFormatEtc::OnNext(void __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CEnumFormatEtc::OnNext(CEnumFormatEtc *this, tagDVTARGETDEVICE **pv)
{
  int result; // eax
  tagDVTARGETDEVICE *v3; // eax

  result = CEnumArray::OnNext(this, pv);
  if ( result != 0 )
  {
    if ( pv[1] != nullptr )
    {
      v3 = _AfxOleCopyTargetDevice(ptdSrc: pv[1]);
      pv[1] = v3;
      if ( v3 == nullptr )
        AfxThrowMemoryException();
    }
    return 1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10415193
// Name: protected: virtual struct AFX_INTERFACEMAP const __near * COleDataSource::GetInterfaceMap(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
const AFX_INTERFACEMAP *__thiscall COleDataSource::GetInterfaceMap(COleDataSource *this)
{
  return &COleDataSource::interfaceMap;
}

//------------------------------------------------------------------------------
// Address: 0x10415199
// Name: public: virtual unsigned long COleDataSource::XDataObject::AddRef(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
LONG __stdcall COleDataSource::XDataObject::AddRef(COleDataSource::XDataObject *this)
{
  return CCmdTarget::ExternalAddRef(this: (CCmdTarget *)(this - 12));
}

//------------------------------------------------------------------------------
// Address: 0x104151AD
// Name: public: virtual unsigned long COleDataSource::XDataObject::Release(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
LONG __stdcall COleDataSource::XDataObject::Release(COleDataSource::XDataObject *this)
{
  return CCmdTarget::ExternalRelease(this: (CCmdTarget *)(this - 12));
}

//------------------------------------------------------------------------------
// Address: 0x104151C1
// Name: public: virtual long COleDataSource::XDataObject::QueryInterface(struct _GUID const __near &,void __near * __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
HRESULT __stdcall COleDataSource::XDataObject::QueryInterface(
        COleDataSource::XDataObject *this,
        const _GUID *iid,
        void **ppvObj)
{
  return CCmdTarget::ExternalQueryInterface(this: (CCmdTarget *)(this - 12), iid, ppvObj);
}

//------------------------------------------------------------------------------
// Address: 0x104151DB
// Name: public: virtual long COleDataSource::XDataObject::QueryGetData(struct tagFORMATETC __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
HRESULT __stdcall COleDataSource::XDataObject::QueryGetData(
        COleDataSource::XDataObject *this,
        tagFORMATETC *lpFormatEtc)
{
  if ( lpFormatEtc != nullptr )
    return COleDataSource::Lookup(this: (COleDataSource *)(this - 12), lpFormatEtc, nDataDir: DATADIR_GET) != nullptr
         ? 0
         : -2147221404;
  else
    return -2147024809;
}

//------------------------------------------------------------------------------
// Address: 0x1041520F
// Name: public: virtual long COleDataSource::XDataObject::GetCanonicalFormatEtc(struct tagFORMATETC __near *,struct tagFORMATETC __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
HRESULT __stdcall COleDataSource::XDataObject::GetCanonicalFormatEtc(
        COleDataSource::XDataObject *this,
        COleDataSource::XDataObject *__formal,
        tagFORMATETC *__formala)
{
  return 262448;
}

//------------------------------------------------------------------------------
// Address: 0x10415217
// Name: public: virtual long COleDataSource::XDataObject::DAdvise(struct tagFORMATETC __near *,unsigned long,struct IAdviseSink __near *,unsigned long __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
HRESULT __stdcall COleDataSource::XDataObject::DAdvise(
        COleDataSource::XDataObject *this,
        tagFORMATETC *__formal,
        unsigned int a3,
        IAdviseSink *a4,
        unsigned int *pdwConnection)
{
  *pdwConnection = 0;
  return -2147221501;
}

//------------------------------------------------------------------------------
// Address: 0x1041522B
// Name: public: virtual long COleDataSource::XDataObject::DUnadvise(unsigned long)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
HRESULT __stdcall COleDataSource::XDataObject::DUnadvise(
        COleDataSource::XDataObject *this,
        COleDataSource::XDataObject *__formal)
{
  return -2147221501;
}

//------------------------------------------------------------------------------
// Address: 0x10415233
// Name: public: virtual long COleDataSource::XDataObject::EnumDAdvise(struct IEnumSTATDATA __near * __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
HRESULT __stdcall COleDataSource::XDataObject::EnumDAdvise(
        COleDataSource::XDataObject *this,
        IEnumSTATDATA **ppenumAdvise)
{
  *ppenumAdvise = nullptr;
  return -2147221501;
}

//------------------------------------------------------------------------------
// Address: 0x10415247
// Name: protected: struct AFX_DATACACHE_ENTRY __near * COleDataSource::GetCacheEntry(struct tagFORMATETC __near *,enum tagDATADIR)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
AFX_DATACACHE_ENTRY *__thiscall COleDataSource::GetCacheEntry(
        COleDataSource *this,
        tagFORMATETC *lpFormatEtc,
        tagDATADIR nDataDir)
{
  AFX_DATACACHE_ENTRY *v4; // eax
  AFX_DATACACHE_ENTRY *v5; // ebx
  AFX_DATACACHE_ENTRY *v6; // eax
  AFX_DATACACHE_ENTRY *m_pDataCache; // edx
  AFX_DATACACHE_ENTRY *v8; // ebx
  unsigned int m_nGrowBy; // eax

  v4 = COleDataSource::Lookup(this, lpFormatEtc, nDataDir);
  v5 = v4;
  if ( v4 != nullptr )
  {
    CoTaskMemFree(pv: v4->m_formatEtc.ptd);
    ReleaseStgMedium(a1: &v5->m_stgMedium);
  }
  else
  {
    if ( this->m_pDataCache == nullptr || this->m_nSize == this->m_nMaxSize )
    {
      v6 = (AFX_DATACACHE_ENTRY *)operator new(nSize: 36 * (this->m_nGrowBy + this->m_nMaxSize));
      m_pDataCache = this->m_pDataCache;
      v8 = v6;
      m_nGrowBy = this->m_nGrowBy;
      this->m_nMaxSize += m_nGrowBy;
      if ( m_pDataCache != nullptr )
      {
        ATL::Checked::memcpy_s(
          _S1: v8,
          _S1max: 36 * (m_nGrowBy + this->m_nMaxSize),
          _S2: m_pDataCache,
          _N: 36 * this->m_nSize);
        operator delete(p: this->m_pDataCache);
      }
      this->m_pDataCache = v8;
    }
    v5 = &this->m_pDataCache[this->m_nSize++];
  }
  v5->m_nDataDir = nDataDir;
  qmemcpy(v5, lpFormatEtc, 0x14u);
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x104152FC
// Name: public: void COleDataSource::CacheGlobalData(unsigned short,void __near *,struct tagFORMATETC __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall COleDataSource::CacheGlobalData(
        COleDataSource *this,
        unsigned __int16 cfFormat,
        HBITMAP__ *hGlobal,
        tagFORMATETC *lpFormatEtc)
{
  tagFORMATETC *v5; // eax
  AFX_DATACACHE_ENTRY *CacheEntry; // eax
  tagFORMATETC formatEtc; // [esp+8h] [ebp-14h] BYREF

  v5 = _AfxFillFormatEtc(lpFormatEtc, cfFormat, lpFormatEtcFill: &formatEtc);
  v5->tymed = 1;
  CacheEntry = COleDataSource::GetCacheEntry(this, lpFormatEtc: v5, nDataDir: DATADIR_GET);
  CacheEntry->m_stgMedium.pUnkForRelease = nullptr;
  CacheEntry->m_stgMedium.tymed = 1;
  CacheEntry->m_stgMedium.hBitmap = hGlobal;
}

//------------------------------------------------------------------------------
// Address: 0x1041535A
// Name: public: void CEnumFormatEtc::AddFormat(struct tagFORMATETC const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CEnumFormatEtc::AddFormat(CEnumFormatEtc *this, const tagFORMATETC *lpFormatEtc)
{
  unsigned int m_nSize; // eax
  unsigned __int8 *v4; // eax
  unsigned __int8 *v5; // edi

  m_nSize = this->m_nSize;
  if ( m_nSize == this->m_nMaxSize )
  {
    v4 = (unsigned __int8 *)operator new(nSize: 20 * (m_nSize + 10));
    this->m_nMaxSize += 10;
    v5 = v4;
    ATL::Checked::memcpy_s(_S1: v4, _S1max: 20 * (this->m_nSize + 10), _S2: this->m_pvEnum, _N: 20 * this->m_nSize);
    operator delete(p: this->m_pvEnum);
    this->m_pvEnum = v5;
  }
  *(tagFORMATETC *)&this->m_pvEnum[20 * this->m_nSize++] = *lpFormatEtc;
}

//------------------------------------------------------------------------------
// Address: 0x10415D93
// Name: public: virtual unsigned long CMFCToolBarDropTarget::OnDragEnter(class CWnd __near *,class COleDataObject __near *,unsigned long,class CPoint)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __thiscall CMFCToolBarDropTarget::OnDragEnter(
        CMFCToolBarDropTarget *this,
        CWnd *__formal,
        COleDataObject *pDataObject,
        unsigned int dwKeyState,
        CPoint point)
{
  if ( this->m_pOwner == nullptr )
    AfxThrowInvalidArgException();
  if ( CMFCToolBar::m_bCustomizeMode != 0
    && COleDataObject::IsDataAvailable(this: pDataObject, cfFormat: CMFCToolBarButton::m_cFormat, lpFormatEtc: nullptr) != 0 )
  {
    return ((unsigned int (__thiscall *)(CMFCToolBar *, COleDataObject *, unsigned int, int, int))this->m_pOwner->OnDragEnter)(
             a1: this->m_pOwner,
             a2: pDataObject,
             a3: dwKeyState,
             a4: point.x,
             a5: point.y);
  }
  else
  {
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10415DE4
// Name: public: virtual void CMFCToolBarDropTarget::OnDragLeave(class CWnd __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCToolBarDropTarget::OnDragLeave(CMFCToolBarDropTarget *this, CWnd *__formal)
{
  if ( this->m_pOwner == nullptr )
    AfxThrowInvalidArgException();
  this->m_pOwner->OnDragLeave(this: this->m_pOwner);
}

//------------------------------------------------------------------------------
// Address: 0x10415DFD
// Name: public: virtual unsigned long CMFCToolBarDropTarget::OnDragOver(class CWnd __near *,class COleDataObject __near *,unsigned long,class CPoint)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __thiscall CMFCToolBarDropTarget::OnDragOver(
        CMFCToolBarDropTarget *this,
        CWnd *__formal,
        COleDataObject *pDataObject,
        unsigned int dwKeyState,
        CPoint point)
{
  if ( this->m_pOwner == nullptr )
    AfxThrowInvalidArgException();
  if ( CMFCToolBar::m_bCustomizeMode != 0
    && COleDataObject::IsDataAvailable(this: pDataObject, cfFormat: CMFCToolBarButton::m_cFormat, lpFormatEtc: nullptr) != 0 )
  {
    return ((unsigned int (__thiscall *)(CMFCToolBar *, COleDataObject *, unsigned int, int, int))this->m_pOwner->OnDragOver)(
             a1: this->m_pOwner,
             a2: pDataObject,
             a3: dwKeyState,
             a4: point.x,
             a5: point.y);
  }
  else
  {
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10415E4E
// Name: public: virtual unsigned long CMFCToolBarDropTarget::OnDropEx(class CWnd __near *,class COleDataObject __near *,unsigned long,unsigned long,class CPoint)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __thiscall CMFCToolBarDropTarget::OnDropEx(
        CMFCToolBarDropTarget *this,
        CWnd *__formal,
        COleDataObject *pDataObject,
        unsigned int dropEffect,
        unsigned int a5,
        CPoint point)
{
  if ( this->m_pOwner == nullptr )
    AfxThrowInvalidArgException();
  if ( CMFCToolBar::m_bCustomizeMode != 0
    && COleDataObject::IsDataAvailable(this: pDataObject, cfFormat: CMFCToolBarButton::m_cFormat, lpFormatEtc: nullptr) != 0 )
  {
    return ((int (__thiscall *)(CMFCToolBar *, COleDataObject *, unsigned int, int, int))this->m_pOwner->OnDrop)(
             a1: this->m_pOwner,
             a2: pDataObject,
             a3: dropEffect,
             a4: point.x,
             a5: point.y) != 0
         ? dropEffect
         : 0;
  }
  else
  {
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10415ECD
// Name: public: virtual struct CRuntimeClass __near * CUserTool::GetRuntimeClass(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CRuntimeClass *__thiscall CUserTool::GetRuntimeClass(CUserTool *this)
{
  return &CUserTool::classCUserTool;
}

//------------------------------------------------------------------------------
// Address: 0x10421503
// Name: public: virtual void COleDropTarget::Revoke(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall COleDropTarget::Revoke(COleDropTarget *this)
{
  IUnknown *Interface; // eax

  if ( this->m_hWnd != nullptr )
  {
    RevokeDragDrop(hwnd: this->m_hWnd);
    Interface = CCmdTarget::GetInterface(this, iid: &IID_IUnknown);
    CoLockObjectExternal(pUnk: Interface, fLock: false, fLastUnlockReleases: true);
    CWnd::FromHandle(hWnd: this->m_hWnd)->m_pDropTarget = nullptr;
    this->m_hWnd = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1042153F
// Name: public: virtual unsigned long COleDropTarget::OnDragEnter(class CWnd __near *,class COleDataObject __near *,unsigned long,class CPoint)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall COleDropTarget::OnDragEnter(
        COleDropTarget *this,
        CWnd *pWnd,
        COleDataObject *pDataObject,
        unsigned int dwKeyState,
        CPoint point)
{
  int result; // eax

  result = CObject::IsKindOf(this: pWnd, pClass: &CView::classCView);
  if ( result != 0 )
    return pWnd->__vftable[1].OnCmdMsg(
             this: pWnd,
             a2: (unsigned int)pDataObject,
             a3: dwKeyState,
             a4: (void *)point.x,
             a5: (AFX_CMDHANDLERINFO *)point.y);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10421573
// Name: public: virtual unsigned long COleDropTarget::OnDragOver(class CWnd __near *,class COleDataObject __near *,unsigned long,class CPoint)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall COleDropTarget::OnDragOver(
        COleDropTarget *this,
        CWnd *pWnd,
        COleDataObject *pDataObject,
        unsigned int dwKeyState,
        CPoint point)
{
  int result; // eax

  result = CObject::IsKindOf(this: pWnd, pClass: &CView::classCView);
  if ( result != 0 )
    return ((unsigned int (__thiscall *)(CWnd *, COleDataObject *, unsigned int, int, int))pWnd->__vftable[1].OnFinalRelease)(
             a1: pWnd,
             a2: pDataObject,
             a3: dwKeyState,
             a4: point.x,
             a5: point.y);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104215A7
// Name: public: virtual int COleDropTarget::OnDrop(class CWnd __near *,class COleDataObject __near *,unsigned long,class CPoint)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall COleDropTarget::OnDrop(
        COleDropTarget *this,
        CWnd *pWnd,
        COleDataObject *pDataObject,
        unsigned int dropEffect,
        CPoint point)
{
  int result; // eax

  result = CObject::IsKindOf(this: pWnd, pClass: &CView::classCView);
  if ( result != 0 )
    return ((int (__thiscall *)(CWnd *, COleDataObject *, unsigned int, int, int))pWnd->__vftable[1].GetDispatchIID)(
             a1: pWnd,
             a2: pDataObject,
             a3: dropEffect,
             a4: point.x,
             a5: point.y);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104215DB
// Name: public: virtual unsigned long COleDropTarget::OnDropEx(class CWnd __near *,class COleDataObject __near *,unsigned long,unsigned long,class CPoint)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __thiscall COleDropTarget::OnDropEx(
        COleDropTarget *this,
        CWnd *pWnd,
        COleDataObject *pDataObject,
        unsigned int dropEffect,
        unsigned int dropEffectList,
        CPoint point)
{
  if ( CObject::IsKindOf(this: pWnd, pClass: &CView::classCView) != 0 )
    return ((unsigned int (__thiscall *)(CWnd *, COleDataObject *, unsigned int, unsigned int, int, int))pWnd->__vftable[1].GetTypeInfoCount)(
             a1: pWnd,
             a2: pDataObject,
             a3: dropEffect,
             a4: dropEffectList,
             a5: point.x,
             a6: point.y);
  else
    return -1;
}

//------------------------------------------------------------------------------
// Address: 0x10421617
// Name: public: virtual void COleDropTarget::OnDragLeave(class CWnd __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall COleDropTarget::OnDragLeave(COleDropTarget *this, CWnd *pWnd)
{
  if ( CObject::IsKindOf(this: pWnd, pClass: &CView::classCView) != 0 )
    ((void (__thiscall *)(CWnd *))pWnd->__vftable[1].IsInvokeAllowed)(a1: pWnd);
}

//------------------------------------------------------------------------------
// Address: 0x1042163F
// Name: protected: virtual struct AFX_INTERFACEMAP const __near * COleDropTarget::GetInterfaceMap(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
const AFX_INTERFACEMAP *__thiscall COleDropTarget::GetInterfaceMap(COleDropTarget *this)
{
  return &COleDropTarget::interfaceMap;
}

//------------------------------------------------------------------------------
// Address: 0x10421645
// Name: public: virtual unsigned long COleDropTarget::XDropTarget::AddRef(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
LONG __stdcall COleDropTarget::XDropTarget::AddRef(COleDropTarget::XDropTarget *this)
{
  return CCmdTarget::ExternalAddRef(this: (CCmdTarget *)(this - 13));
}

//------------------------------------------------------------------------------
// Address: 0x10421659
// Name: public: virtual unsigned long COleDropTarget::XDropTarget::Release(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
LONG __stdcall COleDropTarget::XDropTarget::Release(COleDropTarget::XDropTarget *this)
{
  return CCmdTarget::ExternalRelease(this: (CCmdTarget *)(this - 13));
}

//------------------------------------------------------------------------------
// Address: 0x1042166D
// Name: public: virtual long COleDropTarget::XDropTarget::QueryInterface(struct _GUID const __near &,void __near * __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
HRESULT __stdcall COleDropTarget::XDropTarget::QueryInterface(
        COleDropTarget::XDropTarget *this,
        const _GUID *iid,
        void **ppvObj)
{
  return CCmdTarget::ExternalQueryInterface(this: (CCmdTarget *)(this - 13), iid, ppvObj);
}

//------------------------------------------------------------------------------
// Address: 0x10421687
// Name: unsigned long _AfxFilterDropEffect(unsigned long,unsigned long)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __stdcall _AfxFilterDropEffect(unsigned int dropEffect, unsigned int dwEffects)
{
  if ( (dropEffect & dwEffects) != 0 )
    return dropEffect;
  if ( dropEffect == 1 )
  {
    if ( (dwEffects & 2) != 0 )
      return 2;
  }
  else
  {
    if ( dropEffect != 2 )
      return 0;
    if ( (dwEffects & 1) != 0 )
      return 1;
  }
  if ( (dwEffects & 4) != 0 )
    return 4;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x104216C0
// Name: public: virtual unsigned long COleDropTarget::OnDragScroll(class CWnd __near *,unsigned long,class CPoint)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall COleDropTarget::OnDragScroll(COleDropTarget *this, CWnd *pWnd, unsigned int dwKeyState, POINT point)
{
  int result; // eax
  int v6; // eax
  CSplitterWnd *ParentSplitter; // esi
  int v8; // eax
  DWORD TickCount; // eax
  unsigned int v10; // edx
  COleDataObject v11; // [esp+10h] [ebp-4Ch] BYREF
  unsigned int v12; // [esp+20h] [ebp-3Ch]
  CWnd *pWnda; // [esp+24h] [ebp-38h]
  unsigned int v14; // [esp+28h] [ebp-34h]
  tagRECT Rect; // [esp+2Ch] [ebp-30h] BYREF
  tagRECT rc; // [esp+3Ch] [ebp-20h] BYREF
  int v17; // [esp+58h] [ebp-4h]

  pWnda = pWnd;
  if ( CObject::IsKindOf(this: pWnd, pClass: &CView::classCView) == 0 )
    return 0;
  result = ((int (__thiscall *)(CWnd *, unsigned int, int, int))pWnd->__vftable[1].GetTypeLibCache)(
             a1: pWnd,
             a2: dwKeyState,
             a3: point.x,
             a4: point.y);
  if ( result != 0x80000000 )
    return result;
  memset(&Rect, 0, sizeof(Rect));
  GetClientRect(hWnd: pWnd->m_hWnd, lpRect: &Rect);
  rc = Rect;
  v14 = 0xFFFF;
  InflateRect(lprc: &rc, dx: -COleDropTarget::nScrollInset, dy: -COleDropTarget::nScrollInset);
  if ( !PtInRect(lprc: &Rect, pt: point) || PtInRect(lprc: &rc, pt: point) )
  {
LABEL_21:
    if ( this->m_nTimerID != 0xFFFF )
    {
      COleDataObject::COleDataObject(this: &v11);
      v17 = 0;
      COleDataObject::Attach(this: &v11, lpDataObject: this->m_lpDataObject, bAutoRelease: 0);
      ((void (__thiscall *)(COleDropTarget *, CWnd *, COleDataObject *, unsigned int, int, int))this->OnDragEnter)(
        a1: this,
        a2: pWnda,
        a3: &v11,
        a4: dwKeyState,
        a5: point.x,
        a6: point.y);
      v17 = -1;
      this->m_nTimerID = 0xFFFF;
      COleDataObject::Release(this: &v11);
    }
    return 0;
  }
  if ( point.x >= rc.left )
  {
    if ( point.x >= rc.right )
      v14 = 65281;
  }
  else
  {
    v14 = 65280;
  }
  if ( point.y < rc.top )
  {
    v6 = (unsigned __int8)v14;
LABEL_14:
    v14 = v6;
    goto LABEL_15;
  }
  if ( point.y >= rc.bottom )
  {
    v6 = (unsigned __int8)v14 | 0x100;
    goto LABEL_14;
  }
LABEL_15:
  ParentSplitter = CView::GetParentSplitter(pWnd: pWnda, bAnyState: 0);
  if ( ParentSplitter != nullptr )
    v8 = ParentSplitter->DoScroll(this: ParentSplitter, a2: (CView *)pWnda, a3: v14, a4: 0);
  else
    v8 = ((int (__thiscall *)(CWnd *, unsigned int, _DWORD, _DWORD))pWnda->__vftable[1].dtr_CObject)(
           a1: pWnda,
           a2: v14,
           a3: 0,
           a4: 0);
  if ( v8 == 0 )
    v14 = 0xFFFF;
  if ( v14 == 0xFFFF )
    goto LABEL_21;
  TickCount = GetTickCount();
  v10 = v14;
  v12 = TickCount;
  if ( v14 != this->m_nTimerID )
  {
    this->m_dwLastTick = TickCount;
    this->m_nScrollDelay = COleDropTarget::nScrollDelay;
  }
  if ( TickCount - this->m_dwLastTick > this->m_nScrollDelay )
  {
    if ( ParentSplitter != nullptr )
      ParentSplitter->DoScroll(this: ParentSplitter, a2: (CView *)pWnda, a3: v10, a4: 1);
    else
      ((void (__thiscall *)(CWnd *, unsigned int, _DWORD, int))pWnda->__vftable[1].dtr_CObject)(
        a1: pWnda,
        a2: v10,
        a3: 0,
        a4: 1);
    this->m_dwLastTick = v12;
    this->m_nScrollDelay = COleDropTarget::nScrollInterval;
  }
  if ( this->m_nTimerID == 0xFFFF )
    this->OnDragLeave(this, a2: pWnda);
  this->m_nTimerID = v14;
  if ( (dwKeyState & 0xC) == 0xC )
    return -2147483644;
  result = -2147483647;
  if ( (dwKeyState & 8) == 0 )
    return -2147483646;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104218CD
// Name: public: virtual long COleDropTarget::XDropTarget::DragEnter(struct IDataObject __near *,unsigned long,struct _POINTL,unsigned long __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
HRESULT __stdcall COleDropTarget::XDropTarget::DragEnter(
        COleDropTarget::XDropTarget *this,
        IDataObject *lpDataObject,
        unsigned int dwKeyState,
        CPoint pt,
        unsigned int *pdwEffect)
{
  IDataObject_vtbl *v6; // eax
  CWnd *v7; // edi
  unsigned int v8; // eax
  unsigned int *v9; // edx
  HWND__ *v11; // [esp-4h] [ebp-48h]
  COleDataObject dataObject; // [esp+10h] [ebp-34h] BYREF
  AFX_MAINTAIN_STATE2 _ctlState; // [esp+20h] [ebp-24h] BYREF
  CPoint point; // [esp+28h] [ebp-1Ch] BYREF
  int v15; // [esp+40h] [ebp-4h]
  int dropEffect; // [esp+4Ch] [ebp+8h]

  AFX_MAINTAIN_STATE2::AFX_MAINTAIN_STATE2(this: &_ctlState, pNewState: *((AFX_MODULE_STATE **)this - 6));
  v15 = 0;
  if ( lpDataObject != nullptr && pdwEffect != nullptr )
  {
    v6 = lpDataObject->__vftable;
    LOBYTE(v15) = 1;
    v6->AddRef(this: lpDataObject);
    _AfxRelease(lplpUnknown: (IUnknown **)this - 4);
    v11 = *((HWND__ **)this - 5);
    *((_DWORD *)this - 4) = lpDataObject;
    v7 = CWnd::FromHandle(hWnd: v11);
    point = pt;
    ScreenToClient(hWnd: v7->m_hWnd, lpPoint: &point);
    dropEffect = (*(int (__thiscall **)(COleDropTarget::XDropTarget *, CWnd *, unsigned int, int, int))(*((_DWORD *)this - 13) + 104))(
                   a1: this - 13,
                   a2: v7,
                   a3: dwKeyState,
                   a4: point.x,
                   a5: point.y);
    if ( dropEffect >= 0 )
    {
      COleDataObject::COleDataObject(this: &dataObject);
      LOBYTE(v15) = 2;
      COleDataObject::Attach(this: &dataObject, lpDataObject, bAutoRelease: 0);
      dropEffect = (*(int (__thiscall **)(COleDropTarget::XDropTarget *, CWnd *, COleDataObject *, unsigned int, int, int))(*((_DWORD *)this - 13) + 84))(
                     a1: this - 13,
                     a2: v7,
                     a3: &dataObject,
                     a4: dwKeyState,
                     a5: point.x,
                     a6: point.y);
      LOBYTE(v15) = 1;
      COleDataObject::Release(this: &dataObject);
    }
    v8 = _AfxFilterDropEffect(dropEffect, dwEffects: *pdwEffect);
    *v9 = v8;
    v15 = -1;
    AFX_MAINTAIN_STATE2::~AFX_MAINTAIN_STATE2(this: &_ctlState);
    return 0;
  }
  else
  {
    v15 = -1;
    AFX_MAINTAIN_STATE2::~AFX_MAINTAIN_STATE2(this: &_ctlState);
    return -2147024809;
  }
}

//------------------------------------------------------------------------------
// Address: 0x104219E1
// Name: public: virtual long COleDropTarget::XDropTarget::DragOver(unsigned long,struct _POINTL,unsigned long __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
HRESULT __stdcall COleDropTarget::XDropTarget::DragOver(
        COleDropTarget::XDropTarget *this,
        unsigned int dwKeyState,
        CPoint pt,
        unsigned int *pdwEffect)
{
  int v4; // esi
  CWnd *v6; // edi
  signed int v7; // ebx
  unsigned int v8; // eax
  unsigned int *v9; // edx
  IDataObject *v10; // [esp-8h] [ebp-4Ch]
  HWND__ *v11; // [esp-4h] [ebp-48h]
  COleDataObject dataObject; // [esp+10h] [ebp-34h] BYREF
  AFX_MAINTAIN_STATE2 _ctlState; // [esp+20h] [ebp-24h] BYREF
  CPoint point; // [esp+28h] [ebp-1Ch] BYREF
  int v15; // [esp+40h] [ebp-4h]

  AFX_MAINTAIN_STATE2::AFX_MAINTAIN_STATE2(this: &_ctlState, pNewState: *((AFX_MODULE_STATE **)this - 6));
  v15 = 0;
  if ( pdwEffect != nullptr )
  {
    v11 = *((HWND__ **)this - 5);
    LOBYTE(v15) = 1;
    v6 = CWnd::FromHandle(hWnd: v11);
    point = pt;
    ScreenToClient(hWnd: v6->m_hWnd, lpPoint: &point);
    v7 = (*(int (__thiscall **)(COleDropTarget::XDropTarget *, CWnd *, unsigned int, int, int))(*((_DWORD *)this - 13)
                                                                                              + 104))(
           a1: this - 13,
           a2: v6,
           a3: dwKeyState,
           a4: point.x,
           a5: point.y);
    if ( v7 >= 0 )
    {
      COleDataObject::COleDataObject(this: &dataObject);
      v10 = *((IDataObject **)this - 4);
      LOBYTE(v15) = 2;
      COleDataObject::Attach(this: &dataObject, lpDataObject: v10, bAutoRelease: 0);
      v7 = (*(int (__thiscall **)(COleDropTarget::XDropTarget *, CWnd *, COleDataObject *, unsigned int, int, int))(*((_DWORD *)this - 13) + 88))(
             a1: this - 13,
             a2: v6,
             a3: &dataObject,
             a4: dwKeyState,
             a5: point.x,
             a6: point.y);
      LOBYTE(v15) = 1;
      COleDataObject::Release(this: &dataObject);
    }
    v8 = _AfxFilterDropEffect(dropEffect: v7, dwEffects: *pdwEffect);
    *v9 = v8;
    v4 = 0;
  }
  else
  {
    v4 = -2147024809;
  }
  v15 = -1;
  AFX_MAINTAIN_STATE2::~AFX_MAINTAIN_STATE2(this: &_ctlState);
  return v4;
}
