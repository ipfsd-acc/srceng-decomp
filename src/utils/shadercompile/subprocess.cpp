// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/shadercompile/subprocess.cpp
// Functions: 13
// ============================================================

#include "utils\shadercompile\subprocess.h"

//------------------------------------------------------------------------------
// Address: 0x10010800
// Name: public: SubProcessKernelObjects::SubProcessKernelObjects(void)
// Source: json
//------------------------------------------------------------------------------
SubProcessKernelObjects *__thiscall SubProcessKernelObjects::SubProcessKernelObjects(SubProcessKernelObjects *this)
{
  this->m_hMemorySection = nullptr;
  this->m_hMutex = nullptr;
  *(_QWORD *)this->m_hEvent = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10010820
// Name: public: void __near * SubProcessKernelObjects_Memory::Lock(void)
// Source: json
//------------------------------------------------------------------------------
void *__thiscall SubProcessKernelObjects_Memory::Lock(SubProcessKernelObjects_Memory *this)
{
  DWORD v2; // eax
  DWORD CurrentThreadId; // eax
  _DWORD *v4; // eax
  SubProcessKernelObjects *m_pObjs; // edx
  SubProcessKernelObjects *v6; // eax
  void *result; // eax
  unsigned int v8; // [esp-4h] [ebp-114h]
  char chMsg[256]; // [esp+Ch] [ebp-104h] BYREF
  unsigned int iWaitAttempt; // [esp+10Ch] [ebp-4h]

  iWaitAttempt = 0;
  while ( 1 )
  {
    v2 = WaitForSingleObject(hHandle: this->m_pObjs->m_hEvent[this->m_pObjs->m_dwCookie], dwMilliseconds: 0x2710u);
    if ( v2 == 0 )
      break;
    if ( v2 != 258 )
    {
      OutputDebugStringA(lpOutputString: "WAIT failure in Memory::Lock\n");
      SetLastError(dwErrCode: 0x14u);
      return nullptr;
    }
    v8 = iWaitAttempt;
    CurrentThreadId = GetCurrentThreadId();
    sprintf(string: chMsg, format: "th%08X> WAIT_TIMEOUT in Memory::Lock (attempt %d).\n", CurrentThreadId, v8);
    OutputDebugStringA(lpOutputString: chMsg);
LABEL_7:
    if ( ++iWaitAttempt >= 0xD )
    {
      OutputDebugStringA(lpOutputString: "Ran out of wait attempts in Memory::Lock\n");
      SetLastError(dwErrCode: 0x15u);
      return nullptr;
    }
  }
  v4 = MapViewOfFile(
         hFileMappingObject: this->m_pObjs->m_hMemorySection,
         dwDesiredAccess: 0xF001Fu,
         dwFileOffsetHigh: 0,
         dwFileOffsetLow: 0,
         dwNumberOfBytesToMap: 0);
  m_pObjs = this->m_pObjs;
  this->m_pLockData = v4;
  if ( *v4 == m_pObjs->m_dwCookie )
  {
    UnmapViewOfFile(lpBaseAddress: v4);
    v6 = this->m_pObjs;
    this->m_pLockData = nullptr;
    SetEvent(hEvent: v6->m_hEvent[v6->m_dwCookie == 0]);
    Sleep(dwMilliseconds: 1u);
    goto LABEL_7;
  }
  *v4 = m_pObjs->m_dwCookie;
  result = (char *)this->m_pLockData + 8;
  this->m_pMemory = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10010940
// Name: public: int SubProcessKernelObjects_Memory::Unlock(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall SubProcessKernelObjects_Memory::Unlock(SubProcessKernelObjects_Memory *this)
{
  if ( this->m_pLockData == nullptr )
    return 0;
  UnmapViewOfFile(lpBaseAddress: this->m_pLockData);
  this->m_pMemory = nullptr;
  this->m_pLockData = nullptr;
  SetEvent(hEvent: this->m_pObjs->m_hEvent[this->m_pObjs->m_dwCookie == 0]);
  Sleep(dwMilliseconds: 1u);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10010990
// Name: public: CSubProcessResponse::CSubProcessResponse(void const __near *)
// Source: json
//------------------------------------------------------------------------------
CSubProcessResponse *__thiscall CSubProcessResponse::CSubProcessResponse(
        CSubProcessResponse *this,
        unsigned int *pvMemory)
{
  unsigned int v3; // edx

  this->m_pvMemory = pvMemory;
  this->__vftable = (CSubProcessResponse_vtbl *)&CSubProcessResponse::`vftable';
  this->m_dwResult = *pvMemory;
  v3 = pvMemory[1];
  this->m_dwResultBufferLength = v3;
  this->m_pvResultBuffer = pvMemory + 2;
  this->m_szListing = *((_BYTE *)pvMemory + v3 + 8) != 0 ? (char *)pvMemory + v3 + 8 : nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100109D0
// Name: public: virtual bool CSubProcessResponse::Succeeded(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CSubProcessResponse::Succeeded(CSubProcessResponse *this)
{
  return this->m_dwResult == 1;
}

//------------------------------------------------------------------------------
// Address: 0x100109E0
// Name: public: virtual unsigned int CSubProcessResponse::GetResultBufferLen(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CSubProcessResponse::GetResultBufferLen(CSubProcessResponse *this)
{
  if ( this->Succeeded(this) )
    return this->m_dwResultBufferLength;
  else
    return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10010A00
// Name: public: virtual void const __near * CSubProcessResponse::GetResultBuffer(void)
// Source: json
//------------------------------------------------------------------------------
const void *__thiscall CSubProcessResponse::GetResultBuffer(CSubProcessResponse *this)
{
  if ( this->Succeeded(this) )
    return this->m_pvResultBuffer;
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10010A20
// Name: public: virtual char const __near * CSubProcessResponse::GetListing(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CSubProcessResponse::GetListing(CSubProcessResponse *this)
{
  const char *result; // eax

  result = this->m_szListing;
  if ( result == nullptr || *result == 0 )
    return nullptr;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10010A30
// Name: void ShaderCompile_Subprocess_ExceptionHandler(unsigned long,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ShaderCompile_Subprocess_ExceptionHandler(UINT exceptionCode)
{
  HANDLE CurrentProcess; // eax

  CurrentProcess = GetCurrentProcess();
  TerminateProcess(hProcess: CurrentProcess, uExitCode: exceptionCode);
}

//------------------------------------------------------------------------------
// Address: 0x10010A50
// Name: public: SubProcessKernelObjects::~SubProcessKernelObjects(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall SubProcessKernelObjects::~SubProcessKernelObjects(SubProcessKernelObjects *this)
{
  void **m_hEvent; // esi
  int i; // edi

  if ( this->m_hMemorySection != nullptr )
    CloseHandle(hObject: this->m_hMemorySection);
  if ( this->m_hMutex != nullptr )
    CloseHandle(hObject: this->m_hMutex);
  m_hEvent = this->m_hEvent;
  for ( i = 2; i != 0; --i )
  {
    if ( *m_hEvent != nullptr )
      CloseHandle(hObject: *m_hEvent);
    ++m_hEvent;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10010A90
// Name: protected: int SubProcessKernelObjects::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall SubProcessKernelObjects::Create(SubProcessKernelObjects *this, const char *szBaseName)
{
  HANDLE FileMappingA; // eax
  int v5; // esi
  void **m_hEvent; // edi
  char chBufferName[256]; // [esp+Ch] [ebp-104h] BYREF
  SubProcessKernelObjects *v9; // [esp+10Ch] [ebp-4h]
  const char *szBaseNamea; // [esp+118h] [ebp+8h]

  v9 = this;
  memset(chBufferName, 0, sizeof(chBufferName));
  sprintf(string: chBufferName, format: "%s_msec", szBaseName);
  FileMappingA = CreateFileMappingA(
                   hFile: (HANDLE)0xFFFFFFFF,
                   lpFileMappingAttributes: nullptr,
                   flProtect: 4u,
                   dwMaximumSizeHigh: 0,
                   dwMaximumSizeLow: 0x400000u,
                   lpName: chBufferName);
  this->m_hMemorySection = FileMappingA;
  if ( FileMappingA != nullptr && GetLastError() == 183 )
  {
    CloseHandle(hObject: this->m_hMemorySection);
    this->m_hMemorySection = nullptr;
  }
  sprintf(string: chBufferName, format: "%s_mtx", szBaseName);
  this->m_hMutex = CreateMutexA(lpMutexAttributes: nullptr, bInitialOwner: false, lpName: chBufferName);
  v5 = 0;
  m_hEvent = this->m_hEvent;
  szBaseNamea = (const char *)m_hEvent;
  do
  {
    sprintf(string: chBufferName, format: "%s_evt%d", szBaseName, v5);
    *m_hEvent++ = CreateEventA(
                    lpEventAttributes: nullptr,
                    bManualReset: false,
                    bInitialState: v5++ != 0,
                    lpName: chBufferName);
  }
  while ( v5 < 2 );
  return v9->m_hMemorySection != nullptr && v9->m_hMutex != nullptr && szBaseNamea != nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10010BB0
// Name: protected: int SubProcessKernelObjects::Open(char const __near *)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall SubProcessKernelObjects::Open(SubProcessKernelObjects *this, const char *szBaseName)
{
  int v4; // esi
  void **m_hEvent; // edi
  char chBufferName[256]; // [esp+Ch] [ebp-104h] BYREF
  SubProcessKernelObjects *v8; // [esp+10Ch] [ebp-4h]
  const char *szBaseNamea; // [esp+118h] [ebp+8h]

  v8 = this;
  memset(chBufferName, 0, sizeof(chBufferName));
  sprintf(string: chBufferName, format: "%s_msec", szBaseName);
  this->m_hMemorySection = OpenFileMappingA(dwDesiredAccess: 0xF001Fu, bInheritHandle: false, lpName: chBufferName);
  sprintf(string: chBufferName, format: "%s_mtx", szBaseName);
  this->m_hMutex = OpenMutexA(dwDesiredAccess: 0x1F0001u, bInheritHandle: false, lpName: chBufferName);
  v4 = 0;
  m_hEvent = this->m_hEvent;
  szBaseNamea = (const char *)m_hEvent;
  do
  {
    sprintf(string: chBufferName, format: "%s_evt%d", szBaseName, v4);
    *m_hEvent = OpenEventA(dwDesiredAccess: 0x1F0003u, bInheritHandle: false, lpName: chBufferName);
    ++v4;
    ++m_hEvent;
  }
  while ( v4 < 2 );
  return v8->m_hMemorySection != nullptr && v8->m_hMutex != nullptr && szBaseNamea != nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10010CA0
// Name: int ShaderCompile_Subprocess_Main(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ShaderCompile_Subprocess_Main(const char *szSubProcessData)
{
  int i; // esi
  char *v3; // esi
  unsigned int v4; // eax
  CmdSink::IResponse *v5; // ecx
  unsigned int v6; // edi
  unsigned __int8 *v7; // esi
  unsigned __int8 *v8; // eax
  unsigned __int8 *v9; // esi
  const char *v10; // eax
  char v11; // cl
  bool v12; // zf
  int j; // esi
  void *m_pLockData; // eax
  int k; // esi
  SubProcessKernelObjects_Open objs; // [esp+Ch] [ebp-24h] BYREF
  SubProcessKernelObjects_Memory shrmem; // [esp+20h] [ebp-10h] BYREF
  CmdSink::IResponse *pResponse; // [esp+2Ch] [ebp-4h] BYREF

  SetupToolsMinidumpHandler(fn: (void (__cdecl *)(unsigned int, void *))ShaderCompile_Subprocess_ExceptionHandler);
  memset(&objs, 0, 16);
  SubProcessKernelObjects::Open(this: &objs, szBaseName: szSubProcessData);
  objs.m_dwCookie = 0;
  if ( objs.m_hMemorySection == nullptr )
    goto LABEL_4;
  if ( objs.m_hMutex == nullptr )
  {
    CloseHandle(hObject: objs.m_hMemorySection);
LABEL_4:
    if ( objs.m_hMutex != nullptr )
      CloseHandle(hObject: objs.m_hMutex);
    for ( i = 0; i < 2; ++i )
    {
      if ( objs.m_hEvent[i] != nullptr )
        CloseHandle(hObject: objs.m_hEvent[i]);
    }
    return -1;
  }
  shrmem.m_pObjs = &objs;
  shrmem.m_pMemory = nullptr;
  shrmem.m_pLockData = nullptr;
  v3 = (char *)SubProcessKernelObjects_Memory::Lock(this: &shrmem);
  if ( v3 == nullptr )
  {
LABEL_23:
    if ( shrmem.m_pLockData != nullptr )
    {
      UnmapViewOfFile(lpBaseAddress: shrmem.m_pLockData);
      SetEvent(hEvent: shrmem.m_pObjs->m_hEvent[shrmem.m_pObjs->m_dwCookie == 0]);
      Sleep(dwMilliseconds: 1u);
    }
    if ( objs.m_hMemorySection != nullptr )
      CloseHandle(hObject: objs.m_hMemorySection);
    if ( objs.m_hMutex != nullptr )
      CloseHandle(hObject: objs.m_hMutex);
    for ( j = 0; j < 2; ++j )
    {
      if ( objs.m_hEvent[j] != nullptr )
        CloseHandle(hObject: objs.m_hEvent[j]);
    }
    return -2;
  }
  while ( 1 )
  {
    if ( _V_stricmp(s1: "keepalive", s2: v3) == 0 )
      goto LABEL_19;
    if ( _V_stricmp(s1: "quit", s2: v3) == 0 )
      break;
    pResponse = nullptr;
    if ( InterceptFxc::TryExecuteCommand(pCommand: v3, ppResponse: &pResponse) != 0 )
    {
      *(_DWORD *)v3 = pResponse->Succeeded(this: pResponse);
      v4 = pResponse->GetResultBufferLen(this: pResponse);
      v5 = pResponse;
      v6 = v4;
      *((_DWORD *)v3 + 1) = v4;
      v7 = (unsigned __int8 *)(v3 + 8);
      v8 = (unsigned __int8 *)v5->GetResultBuffer(this: v5);
      memcpy(dst: v7, src: v8, count: v6);
      v9 = &v7[v6];
      v10 = pResponse->GetListing(this: pResponse);
      if ( v10 != nullptr )
      {
        do
        {
          v11 = *v10;
          *v9++ = *v10++;
        }
        while ( v11 != 0 );
      }
      else
      {
        *v9 = 0;
      }
      goto LABEL_20;
    }
LABEL_19:
    *(_QWORD *)v3 = 0;
    *((_QWORD *)v3 + 1) = 0;
LABEL_20:
    if ( shrmem.m_pLockData != nullptr )
    {
      UnmapViewOfFile(lpBaseAddress: shrmem.m_pLockData);
      v12 = shrmem.m_pObjs->m_dwCookie == 0;
      shrmem.m_pMemory = nullptr;
      shrmem.m_pLockData = nullptr;
      SetEvent(hEvent: shrmem.m_pObjs->m_hEvent[v12]);
      Sleep(dwMilliseconds: 1u);
    }
    v3 = (char *)SubProcessKernelObjects_Memory::Lock(this: &shrmem);
    if ( v3 == nullptr )
      goto LABEL_23;
  }
  m_pLockData = shrmem.m_pLockData;
  *(_QWORD *)v3 = 0;
  *((_QWORD *)v3 + 1) = 0;
  if ( m_pLockData != nullptr )
  {
    UnmapViewOfFile(lpBaseAddress: m_pLockData);
    SetEvent(hEvent: shrmem.m_pObjs->m_hEvent[shrmem.m_pObjs->m_dwCookie == 0]);
    Sleep(dwMilliseconds: 1u);
  }
  if ( objs.m_hMemorySection != nullptr )
    CloseHandle(hObject: objs.m_hMemorySection);
  if ( objs.m_hMutex != nullptr )
    CloseHandle(hObject: objs.m_hMutex);
  for ( k = 0; k < 2; ++k )
  {
    if ( objs.m_hEvent[k] != nullptr )
      CloseHandle(hObject: objs.m_hEvent[k]);
  }
  return 0;
}
