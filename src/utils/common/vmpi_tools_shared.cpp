// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/common/vmpi_tools_shared.cpp
// Functions: 7
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x10011080
// Name: bool SharedDispatch(class MessageBuffer __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
char __cdecl SharedDispatch(MessageBuffer *pBuf, int iSource)
{
  char *v2; // ebx
  char v4; // al
  int *v5; // ebx
  const char *v6; // eax
  unsigned __int8 *v7; // ebx
  char *v8; // edi
  _BYTE *v9; // eax
  _BYTE *v10; // eax
  int v11; // esi
  const char *MachineName; // eax
  _iobuf *v13; // eax
  _iobuf *v14; // esi
  int v15; // edi
  unsigned int v16; // eax
  int v17; // [esp-24h] [ebp-35Ch]
  int v18; // [esp-20h] [ebp-358h]
  int tm_mday; // [esp-1Ch] [ebp-354h]
  int tm_hour; // [esp-18h] [ebp-350h]
  int tm_min; // [esp-14h] [ebp-34Ch]
  int tm_sec; // [esp-10h] [ebp-348h]
  char chSaveFileName[520]; // [esp+4h] [ebp-334h] BYREF
  char chModuleName[260]; // [esp+20Ch] [ebp-12Ch] BYREF
  tm curTime; // [esp+310h] [ebp-28h] BYREF
  int iFileSize; // [esp+334h] [ebp-4h]
  const char *pModuleName; // [esp+340h] [ebp+8h]

  v2 = pBuf->data + 2;
  if ( pBuf->data[1] != 0 )
  {
    if ( pBuf->data[1] == 1 )
    {
      v16 = *(_DWORD *)(pBuf->data + 386);
      qmemcpy(&g_DBInfo, v2, sizeof(g_DBInfo));
      g_JobPrimaryID = v16;
      g_bReceivedDBInfo = true;
      return 1;
    }
    else if ( pBuf->data[1] == 3 )
    {
      v4 = *v2;
      v5 = (int *)(pBuf->data + 4);
      if ( v4 == 102 )
      {
        iFileSize = *v5;
        v7 = (unsigned __int8 *)(v5 + 1);
        v8 = getenv(option: "TEMP");
        if ( v8 == nullptr )
        {
          v8 = getenv(option: "TMP");
          if ( v8 == nullptr )
            v8 = "c:";
        }
        pModuleName = chModuleName;
        GetModuleFileNameA(hModule: nullptr, lpFilename: chModuleName, nSize: 0x104u);
        strrchr(string: (unsigned __int8 *)chModuleName, chr: 0x2Eu);
        if ( v9 != nullptr )
          *v9 = 0;
        strrchr(string: (unsigned __int8 *)chModuleName, chr: 0x5Cu);
        if ( v10 != nullptr )
        {
          *v10 = 0;
          pModuleName = v10 + 1;
        }
        _Plat_GetLocalTime(a1: &curTime);
        v11 = ++s_numMiniDumps;
        memset(chSaveFileName, 0, sizeof(chSaveFileName));
        tm_sec = curTime.tm_sec;
        tm_min = curTime.tm_min;
        tm_hour = curTime.tm_hour;
        tm_mday = curTime.tm_mday;
        v18 = curTime.tm_mon + 1;
        v17 = curTime.tm_year + 1900;
        MachineName = VMPI_GetMachineName(iProc: iSource);
        sprintf(
          string: chSaveFileName,
          format: "%s\\vmpi_%s_on_%s_%d%.2d%2d%.2d%.2d%.2d_%d.mdmp",
          v8,
          pModuleName,
          MachineName,
          v17,
          v18,
          tm_mday,
          tm_hour,
          tm_min,
          tm_sec,
          v11);
        v13 = fopen(file: (_iobuf *)chSaveFileName, mode: "wb");
        v14 = v13;
        if ( v13 != nullptr )
        {
          v15 = iFileSize;
          fwrite(buffer: v7, size: 1u, count: iFileSize, stream: v13);
          fclose(stream: v14);
          _Warning(a1: "\nSaved worker crash minidump '%s', size %d byte(s).\n", chSaveFileName, v15);
        }
        else
        {
          _Warning(a1: "\nReceived worker crash minidump size %d byte(s), failed to save.\n", iFileSize);
        }
        return 1;
      }
      else
      {
        if ( v4 == 116 )
        {
          v6 = VMPI_GetMachineName(iProc: iSource);
          _Warning(a1: "\nWorker '%s' dead: %s\n", v6, (const char *)v5);
        }
        return 1;
      }
    }
    else
    {
      return 0;
    }
  }
  else
  {
    V_strncpy(pDest: gamedir, pSrc: v2, maxLen: 1024);
    V_strncpy(pDest: qdir, pSrc: &v2[strlen(v2) + 1], maxLen: 1024);
    g_bReceivedDirectoryInfo = true;
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100112C0
// Name: void SendQDirInfo(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SendQDirInfo()
{
  int Name; // eax
  MessageBuffer mb; // [esp+0h] [ebp-14h] BYREF
  char cPacketID[4]; // [esp+10h] [ebp-4h] BYREF

  strcpy(cPacketID, "\n");
  MessageBuffer::MessageBuffer(this: &mb);
  MessageBuffer::write(this: &mb, p: cPacketID, bytes: 2);
  MessageBuffer::write(this: &mb, p: gamedir, bytes: strlen(gamedir) + 1);
  MessageBuffer::write(this: &mb, p: qdir, bytes: strlen(qdir) + 1);
  Name = ConCommandBase::GetName(this: (CVMPIFile_Memory *)&mb);
  VMPI_SendData(pData: mb.data, nBytes: Name, iDest: -3, fVMPISendFlags: 0);
  MessageBuffer::~MessageBuffer(this: &mb);
}

//------------------------------------------------------------------------------
// Address: 0x10011350
// Name: void RecvQDirInfo(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl RecvQDirInfo()
{
  while ( !g_bReceivedDirectoryInfo )
    VMPI_DispatchNextMessage(timeout: 0xFFFFFFFF);
}

//------------------------------------------------------------------------------
// Address: 0x10011380
// Name: int VMPI_SendFileChunk(void const __near *,int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl VMPI_SendFileChunk(const void *pvChunkPrefix, int lenPrefix, const char *ptchFileName)
{
  int v3; // ebx
  HANDLE FileA; // eax
  void *v5; // esi
  HANDLE FileMappingA; // eax
  void *v7; // edi
  const void *v8; // ebx
  DWORD FileSize; // eax
  int iResult; // [esp+8h] [ebp-8h]
  int iMappedFileSize; // [esp+Ch] [ebp-4h] BYREF

  v3 = 0;
  iResult = 0;
  FileA = CreateFileA(
            lpFileName: ptchFileName,
            dwDesiredAccess: 0x80000000,
            dwShareMode: 0,
            lpSecurityAttributes: nullptr,
            dwCreationDisposition: 3u,
            dwFlagsAndAttributes: 0x80u,
            hTemplateFile: nullptr);
  v5 = FileA;
  if ( FileA != nullptr && FileA != (HANDLE)-1 )
  {
    FileMappingA = CreateFileMappingA(
                     hFile: FileA,
                     lpFileMappingAttributes: nullptr,
                     flProtect: 2u,
                     dwMaximumSizeHigh: 0,
                     dwMaximumSizeLow: 0,
                     lpName: nullptr);
    v7 = FileMappingA;
    if ( FileMappingA != nullptr && FileMappingA != (HANDLE)-1 )
    {
      v8 = MapViewOfFile(
             hFileMappingObject: FileMappingA,
             dwDesiredAccess: 4u,
             dwFileOffsetHigh: 0,
             dwFileOffsetLow: 0,
             dwNumberOfBytesToMap: 0);
      if ( v8 != nullptr )
      {
        FileSize = GetFileSize(hFile: v5, lpFileSizeHigh: nullptr);
        iMappedFileSize = FileSize;
        if ( FileSize != -1
          && VMPI_Send3Chunks(
               pChunk1: pvChunkPrefix,
               chunk1Len: lenPrefix,
               pChunk2: &iMappedFileSize,
               chunk2Len: 4,
               pChunk3: v8,
               chunk3Len: FileSize,
               iDest: 0,
               fVMPISendFlags: 0) )
        {
          iResult = iMappedFileSize;
        }
        UnmapViewOfFile(lpBaseAddress: v8);
      }
      CloseHandle(hObject: v7);
      v3 = iResult;
    }
    CloseHandle(hObject: v5);
  }
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x10011440
// Name: void VMPI_HandleCrash(char const __near *,unsigned int,void __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl VMPI_HandleCrash(const char *pMessage, unsigned int uCode, void *pvExceptionInfo, bool bAssert)
{
  char tchMinidumpFileName[260]; // [esp+0h] [ebp-108h] BYREF
  char crashMsg[4]; // [esp+104h] [ebp-4h] BYREF

  if ( InterlockedIncrement(lpAddend: &crashHandlerCount) == 1 )
  {
    _Msg(a1: "\nFAILURE: '%s' (assert: %d)\n", pMessage, bAssert);
    *(_DWORD *)crashMsg = 980681482;
    VMPI_Send2Chunks(
      pChunk1: crashMsg,
      chunk1Len: 4,
      pChunk2: pMessage,
      chunk2Len: strlen(pMessage) + 1,
      iDest: 0,
      fVMPISendFlags: 0);
    if ( pvExceptionInfo != nullptr )
    {
      memset(tchMinidumpFileName, 0, sizeof(tchMinidumpFileName));
      if ( (unsigned __int8)_WriteMiniDumpUsingExceptionInfo(
                              a1: uCode,
                              a2: pvExceptionInfo,
                              a3: 321,
                              a4: tchMinidumpFileName) != 0 )
      {
        crashMsg[2] = 102;
        VMPI_SendFileChunk(pvChunkPrefix: crashMsg, lenPrefix: 4, ptchFileName: tchMinidumpFileName);
        DeleteFileA(lpFileName: tchMinidumpFileName);
      }
    }
    Sleep(dwMilliseconds: 0x1F4u);
  }
  InterlockedDecrement(lpAddend: &crashHandlerCount);
}

//------------------------------------------------------------------------------
// Address: 0x10011520
// Name: long VMPI_SecondExceptionFilter(struct _EXCEPTION_POINTERS __near *)
// Source: json
//------------------------------------------------------------------------------
int __stdcall VMPI_SecondExceptionFilter(_EXCEPTION_POINTERS *ExceptionInfo)
{
  HANDLE CurrentProcess; // eax

  CurrentProcess = GetCurrentProcess();
  TerminateProcess(hProcess: CurrentProcess, uExitCode: 2u);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10011540
// Name: void VMPI_ExceptionFilter(unsigned long,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl VMPI_ExceptionFilter(unsigned int uCode, void *pvExceptionInfo)
{
  int v2; // eax
  char *pReason; // ecx
  HANDLE CurrentProcess; // eax
  char chUnknownBuffer[32]; // [esp+4h] [ebp-C8h] BYREF
  VMPI_ExceptionFilter::__l2::<unnamed_type_errors> errors[21]; // [esp+24h] [ebp-A8h]

  SetUnhandledExceptionFilter(lpTopLevelExceptionFilter: VMPI_SecondExceptionFilter);
  errors[0].pReason = "EXCEPTION_ACCESS_VIOLATION";
  errors[20].pReason = "EXCEPTION_ACCESS_VIOLATION";
  errors[0].code = -1073741819;
  errors[20].code = -1073741819;
  v2 = 0;
  errors[1].code = -1073741684;
  errors[1].pReason = "EXCEPTION_ARRAY_BOUNDS_EXCEEDED";
  errors[2].code = -2147483645;
  errors[2].pReason = "EXCEPTION_BREAKPOINT";
  errors[3].code = -2147483646;
  errors[3].pReason = "EXCEPTION_DATATYPE_MISALIGNMENT";
  errors[4].code = -1073741683;
  errors[4].pReason = "EXCEPTION_FLT_DENORMAL_OPERAND";
  errors[5].code = -1073741682;
  errors[5].pReason = "EXCEPTION_FLT_DIVIDE_BY_ZERO";
  errors[6].code = -1073741681;
  errors[6].pReason = "EXCEPTION_FLT_INEXACT_RESULT";
  errors[7].code = -1073741680;
  errors[7].pReason = "EXCEPTION_FLT_INVALID_OPERATION";
  errors[8].code = -1073741679;
  errors[8].pReason = "EXCEPTION_FLT_OVERFLOW";
  errors[9].code = -1073741678;
  errors[9].pReason = "EXCEPTION_FLT_STACK_CHECK";
  errors[10].code = -1073741677;
  errors[10].pReason = "EXCEPTION_FLT_UNDERFLOW";
  errors[11].code = -1073741795;
  errors[11].pReason = "EXCEPTION_ILLEGAL_INSTRUCTION";
  errors[12].code = -1073741818;
  errors[12].pReason = "EXCEPTION_IN_PAGE_ERROR";
  errors[13].code = -1073741676;
  errors[13].pReason = "EXCEPTION_INT_DIVIDE_BY_ZERO";
  errors[14].code = -1073741675;
  errors[14].pReason = "EXCEPTION_INT_OVERFLOW";
  errors[15].code = -1073741786;
  errors[15].pReason = "EXCEPTION_INVALID_DISPOSITION";
  errors[16].code = -1073741787;
  errors[16].pReason = "EXCEPTION_NONCONTINUABLE_EXCEPTION";
  errors[17].code = -1073741674;
  errors[17].pReason = "EXCEPTION_PRIV_INSTRUCTION";
  errors[18].code = -2147483644;
  errors[18].pReason = "EXCEPTION_SINGLE_STEP";
  errors[19].code = -1073741571;
  errors[19].pReason = "EXCEPTION_STACK_OVERFLOW";
  pReason = nullptr;
  while ( pReason == nullptr )
  {
    if ( errors[v2].code == uCode )
    {
      pReason = errors[v2].pReason;
      if ( pReason != nullptr )
      {
        ++v2;
        break;
      }
    }
    if ( errors[v2 + 1].code == uCode )
    {
      pReason = errors[v2 + 1].pReason;
      if ( pReason != nullptr )
      {
        v2 += 2;
        break;
      }
    }
    if ( errors[v2 + 2].code == uCode )
      pReason = errors[v2 + 2].pReason;
    v2 += 3;
    if ( v2 >= 21 )
      break;
  }
  if ( v2 == 21 )
  {
    sprintf(string: chUnknownBuffer, format: "Error code 0x%08X", uCode);
    pReason = chUnknownBuffer;
  }
  VMPI_HandleCrash(pMessage: pReason, uCode, pvExceptionInfo, bAssert: true);
  CurrentProcess = GetCurrentProcess();
  TerminateProcess(hProcess: CurrentProcess, uExitCode: 1u);
}

// ============================================================
// Overlay from texturecompile_dll (Missing functions)
// ============================================================
namespace texturecompile_dll {

//------------------------------------------------------------------------------
// Address: 0x10002B30
// Name: bool SharedDispatch(class MessageBuffer __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
char __cdecl SharedDispatch(MessageBuffer *pBuf, int iSource)
{
  char *v2; // ebx
  char v4; // al
  int *v5; // ebx
  const char *v6; // eax
  const void *v7; // ebx
  const char *v8; // edi
  _BYTE *v9; // eax
  _BYTE *v10; // eax
  int v11; // esi
  const char *MachineName; // eax
  _iobuf *v13; // eax
  _iobuf *v14; // esi
  int v15; // edi
  unsigned int v16; // eax
  int v17; // [esp-24h] [ebp-35Ch]
  int v18; // [esp-20h] [ebp-358h]
  int tm_mday; // [esp-1Ch] [ebp-354h]
  int tm_hour; // [esp-18h] [ebp-350h]
  int tm_min; // [esp-14h] [ebp-34Ch]
  int tm_sec; // [esp-10h] [ebp-348h]
  char chSaveFileName[520]; // [esp+4h] [ebp-334h] BYREF
  char chModuleName[260]; // [esp+20Ch] [ebp-12Ch] BYREF
  tm curTime; // [esp+310h] [ebp-28h] BYREF
  int iFileSize; // [esp+334h] [ebp-4h]
  const char *pModuleName; // [esp+340h] [ebp+8h]

  v2 = pBuf->data + 2;
  if ( pBuf->data[1] != 0 )
  {
    if ( pBuf->data[1] == 1 )
    {
      v16 = *(_DWORD *)(pBuf->data + 386);
      qmemcpy(&g_DBInfo, v2, sizeof(g_DBInfo));
      g_JobPrimaryID = v16;
      g_bReceivedDBInfo = true;
      return 1;
    }
    else if ( pBuf->data[1] == 3 )
    {
      v4 = *v2;
      v5 = (int *)(pBuf->data + 4);
      if ( v4 == 102 )
      {
        iFileSize = *v5;
        v7 = v5 + 1;
        v8 = getenv(option: "TEMP");
        if ( v8 == nullptr )
        {
          v8 = getenv(option: "TMP");
          if ( v8 == nullptr )
            v8 = "c:";
        }
        pModuleName = chModuleName;
        GetModuleFileNameA(hModule: nullptr, lpFilename: chModuleName, nSize: 0x104u);
        strrchr(string: (unsigned __int8 *)chModuleName, chr: 0x2Eu);
        if ( v9 != nullptr )
          *v9 = 0;
        strrchr(string: (unsigned __int8 *)chModuleName, chr: 0x5Cu);
        if ( v10 != nullptr )
        {
          *v10 = 0;
          pModuleName = v10 + 1;
        }
        _Plat_GetLocalTime(a1: &curTime);
        v11 = ++s_numMiniDumps;
        memset(chSaveFileName, 0, sizeof(chSaveFileName));
        tm_sec = curTime.tm_sec;
        tm_min = curTime.tm_min;
        tm_hour = curTime.tm_hour;
        tm_mday = curTime.tm_mday;
        v18 = curTime.tm_mon + 1;
        v17 = curTime.tm_year + 1900;
        MachineName = VMPI_GetMachineName(iProc: iSource);
        sprintf(
          string: chSaveFileName,
          format: "%s\\vmpi_%s_on_%s_%d%.2d%2d%.2d%.2d%.2d_%d.mdmp",
          v8,
          pModuleName,
          MachineName,
          v17,
          v18,
          tm_mday,
          tm_hour,
          tm_min,
          tm_sec,
          v11);
        v13 = fopen(file: chSaveFileName, mode: "wb");
        v14 = v13;
        if ( v13 != nullptr )
        {
          v15 = iFileSize;
          fwrite(buffer: v7, size: 1u, count: iFileSize, stream: v13);
          fclose(stream: v14);
          _Warning(a1: "\nSaved worker crash minidump '%s', size %d byte(s).\n", chSaveFileName, v15);
        }
        else
        {
          _Warning(a1: "\nReceived worker crash minidump size %d byte(s), failed to save.\n", iFileSize);
        }
        return 1;
      }
      else
      {
        if ( v4 == 116 )
        {
          v6 = VMPI_GetMachineName(iProc: iSource);
          _Warning(a1: "\nWorker '%s' dead: %s\n", v6, (const char *)v5);
        }
        return 1;
      }
    }
    else
    {
      return 0;
    }
  }
  else
  {
    V_strncpy(pDest: gamedir, pSrc: v2, maxLen: 1024);
    V_strncpy(pDest: qdir, pSrc: &v2[strlen(v2) + 1], maxLen: 1024);
    g_bReceivedDirectoryInfo = true;
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10002D70
// Name: void SendQDirInfo(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SendQDirInfo()
{
  int Name; // eax
  MessageBuffer mb; // [esp+0h] [ebp-14h] BYREF
  char cPacketID[4]; // [esp+10h] [ebp-4h] BYREF

  strcpy(cPacketID, "\n");
  MessageBuffer::MessageBuffer(this: &mb);
  MessageBuffer::write(this: &mb, p: cPacketID, bytes: 2);
  MessageBuffer::write(this: &mb, p: gamedir, bytes: strlen(gamedir) + 1);
  MessageBuffer::write(this: &mb, p: qdir, bytes: strlen(qdir) + 1);
  Name = ConCommandBase::GetName(this: (CVMPIFile_Memory *)&mb);
  VMPI_SendData(pData: mb.data, nBytes: Name, iDest: -3, fVMPISendFlags: 0);
  MessageBuffer::~MessageBuffer(this: &mb);
}

//------------------------------------------------------------------------------
// Address: 0x10002E00
// Name: void RecvQDirInfo(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl RecvQDirInfo()
{
  while ( !g_bReceivedDirectoryInfo )
    VMPI_DispatchNextMessage(timeout: 0xFFFFFFFF);
}

} // namespace texturecompile_dll

// ============================================================
// Overlay from vrad_dll (Missing functions)
// ============================================================
namespace vrad_dll {

//------------------------------------------------------------------------------
// Address: 0x1001BA10
// Name: bool SharedDispatch(class MessageBuffer __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
char __cdecl SharedDispatch(MessageBuffer *pBuf, int iSource)
{
  char *v2; // ebx
  char v4; // al
  int *v5; // ebx
  const char *v6; // eax
  const void *v7; // ebx
  const char *v8; // edi
  _BYTE *v9; // eax
  _BYTE *v10; // eax
  int v11; // esi
  const char *MachineName; // eax
  _iobuf *v13; // eax
  _iobuf *v14; // esi
  int v15; // edi
  unsigned int v16; // eax
  int v17; // [esp-24h] [ebp-35Ch]
  int v18; // [esp-20h] [ebp-358h]
  int tm_mday; // [esp-1Ch] [ebp-354h]
  int tm_hour; // [esp-18h] [ebp-350h]
  int tm_min; // [esp-14h] [ebp-34Ch]
  int tm_sec; // [esp-10h] [ebp-348h]
  char chSaveFileName[520]; // [esp+4h] [ebp-334h] BYREF
  char chModuleName[260]; // [esp+20Ch] [ebp-12Ch] BYREF
  tm curTime; // [esp+310h] [ebp-28h] BYREF
  int iFileSize; // [esp+334h] [ebp-4h]
  const char *pModuleName; // [esp+340h] [ebp+8h]

  v2 = pBuf->data + 2;
  if ( pBuf->data[1] != 0 )
  {
    if ( pBuf->data[1] == 1 )
    {
      v16 = *(_DWORD *)(pBuf->data + 386);
      qmemcpy(&g_DBInfo, v2, sizeof(g_DBInfo));
      g_JobPrimaryID = v16;
      g_bReceivedDBInfo = true;
      return 1;
    }
    else if ( pBuf->data[1] == 3 )
    {
      v4 = *v2;
      v5 = (int *)(pBuf->data + 4);
      if ( v4 == 102 )
      {
        iFileSize = *v5;
        v7 = v5 + 1;
        v8 = getenv(option: "TEMP");
        if ( v8 == nullptr )
        {
          v8 = getenv(option: "TMP");
          if ( v8 == nullptr )
            v8 = "c:";
        }
        pModuleName = chModuleName;
        GetModuleFileNameA(hModule: nullptr, lpFilename: chModuleName, nSize: 0x104u);
        strrchr(string: (unsigned __int8 *)chModuleName, chr: 0x2Eu);
        if ( v9 != nullptr )
          *v9 = 0;
        strrchr(string: (unsigned __int8 *)chModuleName, chr: 0x5Cu);
        if ( v10 != nullptr )
        {
          *v10 = 0;
          pModuleName = v10 + 1;
        }
        _Plat_GetLocalTime(a1: &curTime);
        v11 = ++s_numMiniDumps;
        memset(chSaveFileName, 0, sizeof(chSaveFileName));
        tm_sec = curTime.tm_sec;
        tm_min = curTime.tm_min;
        tm_hour = curTime.tm_hour;
        tm_mday = curTime.tm_mday;
        v18 = curTime.tm_mon + 1;
        v17 = curTime.tm_year + 1900;
        MachineName = VMPI_GetMachineName(iProc: iSource);
        sprintf(
          string: chSaveFileName,
          format: "%s\\vmpi_%s_on_%s_%d%.2d%2d%.2d%.2d%.2d_%d.mdmp",
          v8,
          pModuleName,
          MachineName,
          v17,
          v18,
          tm_mday,
          tm_hour,
          tm_min,
          tm_sec,
          v11);
        v13 = fopen(file: chSaveFileName, mode: "wb");
        v14 = v13;
        if ( v13 != nullptr )
        {
          v15 = iFileSize;
          fwrite(buffer: v7, size: 1u, count: iFileSize, stream: v13);
          fclose(stream: v14);
          _Warning(a1: "\nSaved worker crash minidump '%s', size %d byte(s).\n", chSaveFileName, v15);
        }
        else
        {
          _Warning(a1: "\nReceived worker crash minidump size %d byte(s), failed to save.\n", iFileSize);
        }
        return 1;
      }
      else
      {
        if ( v4 == 116 )
        {
          v6 = VMPI_GetMachineName(iProc: iSource);
          _Warning(a1: "\nWorker '%s' dead: %s\n", v6, (const char *)v5);
        }
        return 1;
      }
    }
    else
    {
      return 0;
    }
  }
  else
  {
    V_strncpy(pDest: gamedir, pSrc: v2, maxLen: 1024);
    V_strncpy(pDest: qdir, pSrc: &v2[strlen(v2) + 1], maxLen: 1024);
    g_bReceivedDirectoryInfo = true;
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001BC50
// Name: void SendQDirInfo(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SendQDirInfo()
{
  int Name; // eax
  MessageBuffer mb; // [esp+0h] [ebp-14h] BYREF
  char cPacketID[4]; // [esp+10h] [ebp-4h] BYREF

  strcpy(cPacketID, "\n");
  MessageBuffer::MessageBuffer(this: &mb);
  MessageBuffer::write(this: &mb, p: cPacketID, bytes: 2);
  MessageBuffer::write(this: &mb, p: gamedir, bytes: strlen(gamedir) + 1);
  MessageBuffer::write(this: &mb, p: qdir, bytes: strlen(qdir) + 1);
  Name = ConCommandBase::GetName(this: (CVTFTexture *)&mb);
  VMPI_SendData(pData: mb.data, nBytes: Name, iDest: -3, fVMPISendFlags: 0);
  MessageBuffer::~MessageBuffer(this: &mb);
}

//------------------------------------------------------------------------------
// Address: 0x1001BCE0
// Name: void RecvQDirInfo(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl RecvQDirInfo()
{
  while ( !g_bReceivedDirectoryInfo )
    VMPI_DispatchNextMessage(timeout: 0xFFFFFFFF);
}

//------------------------------------------------------------------------------
// Address: 0x1001BD10
// Name: void SendDBInfo(class CDBInfo const __near *,unsigned long)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SendDBInfo(const CDBInfo *pInfo, unsigned int jobPrimaryID)
{
  const void *pChunks[3]; // [esp+0h] [ebp-1Ch] BYREF
  int chunkLengths[3]; // [esp+Ch] [ebp-10h] BYREF
  char cPacketInfo[2]; // [esp+18h] [ebp-4h] BYREF

  pChunks[0] = cPacketInfo;
  pChunks[1] = pInfo;
  *(_WORD *)cPacketInfo = 266;
  pChunks[2] = &jobPrimaryID;
  chunkLengths[0] = 2;
  chunkLengths[1] = 384;
  chunkLengths[2] = 4;
  VMPI_SendChunks(pChunks, pChunkLengths: chunkLengths, nChunks: 3, iDest: -3, fVMPISendFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1001BD60
// Name: void RecvDBInfo(class CDBInfo __near *,unsigned long __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl RecvDBInfo(CDBInfo *pInfo, unsigned int *pJobPrimaryID)
{
  while ( !g_bReceivedDBInfo )
    VMPI_DispatchNextMessage(timeout: 0xFFFFFFFF);
  *pInfo = g_DBInfo;
  *pJobPrimaryID = g_JobPrimaryID;
}

//------------------------------------------------------------------------------
// Address: 0x1001BDB0
// Name: int VMPI_SendFileChunk(void const __near *,int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl VMPI_SendFileChunk(const void *pvChunkPrefix, int lenPrefix, const char *ptchFileName)
{
  int v3; // ebx
  HANDLE FileA; // eax
  void *v5; // esi
  HANDLE FileMappingA; // eax
  void *v7; // edi
  const void *v8; // ebx
  DWORD FileSize; // eax
  int iResult; // [esp+8h] [ebp-8h]
  int iMappedFileSize; // [esp+Ch] [ebp-4h] BYREF

  v3 = 0;
  iResult = 0;
  FileA = CreateFileA(
            lpFileName: ptchFileName,
            dwDesiredAccess: 0x80000000,
            dwShareMode: 0,
            lpSecurityAttributes: nullptr,
            dwCreationDisposition: 3u,
            dwFlagsAndAttributes: 0x80u,
            hTemplateFile: nullptr);
  v5 = FileA;
  if ( FileA != nullptr && FileA != (HANDLE)-1 )
  {
    FileMappingA = CreateFileMappingA(
                     hFile: FileA,
                     lpFileMappingAttributes: nullptr,
                     flProtect: 2u,
                     dwMaximumSizeHigh: 0,
                     dwMaximumSizeLow: 0,
                     lpName: nullptr);
    v7 = FileMappingA;
    if ( FileMappingA != nullptr && FileMappingA != (HANDLE)-1 )
    {
      v8 = MapViewOfFile(
             hFileMappingObject: FileMappingA,
             dwDesiredAccess: 4u,
             dwFileOffsetHigh: 0,
             dwFileOffsetLow: 0,
             dwNumberOfBytesToMap: 0);
      if ( v8 != nullptr )
      {
        FileSize = GetFileSize(hFile: v5, lpFileSizeHigh: nullptr);
        iMappedFileSize = FileSize;
        if ( FileSize != -1
          && VMPI_Send3Chunks(
               pChunk1: pvChunkPrefix,
               chunk1Len: lenPrefix,
               pChunk2: &iMappedFileSize,
               chunk2Len: 4,
               pChunk3: v8,
               chunk3Len: FileSize,
               iDest: 0,
               fVMPISendFlags: 0) )
        {
          iResult = iMappedFileSize;
        }
        UnmapViewOfFile(lpBaseAddress: v8);
      }
      CloseHandle(hObject: v7);
      v3 = iResult;
    }
    CloseHandle(hObject: v5);
  }
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x1001BE70
// Name: void VMPI_HandleCrash(char const __near *,unsigned int,void __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl VMPI_HandleCrash(const char *pMessage, unsigned int uCode, void *pvExceptionInfo, bool bAssert)
{
  char tchMinidumpFileName[260]; // [esp+0h] [ebp-108h] BYREF
  char crashMsg[4]; // [esp+104h] [ebp-4h] BYREF

  if ( InterlockedIncrement(lpAddend: &crashHandlerCount) == 1 )
  {
    _Msg(a1: "\nFAILURE: '%s' (assert: %d)\n", pMessage, bAssert);
    *(_DWORD *)crashMsg = 980681482;
    VMPI_Send2Chunks(
      pChunk1: crashMsg,
      chunk1Len: 4,
      pChunk2: pMessage,
      chunk2Len: strlen(pMessage) + 1,
      iDest: 0,
      fVMPISendFlags: 0);
    if ( pvExceptionInfo != nullptr )
    {
      memset(tchMinidumpFileName, 0, sizeof(tchMinidumpFileName));
      if ( (unsigned __int8)_WriteMiniDumpUsingExceptionInfo(
                              a1: uCode,
                              a2: pvExceptionInfo,
                              a3: 321,
                              a4: tchMinidumpFileName) != 0 )
      {
        crashMsg[2] = 102;
        VMPI_SendFileChunk(pvChunkPrefix: crashMsg, lenPrefix: 4, ptchFileName: tchMinidumpFileName);
        DeleteFileA(lpFileName: tchMinidumpFileName);
      }
    }
    Sleep(dwMilliseconds: 0x1F4u);
  }
  InterlockedDecrement(lpAddend: &crashHandlerCount);
}

//------------------------------------------------------------------------------
// Address: 0x1001BF50
// Name: long VMPI_SecondExceptionFilter(struct _EXCEPTION_POINTERS __near *)
// Source: json
//------------------------------------------------------------------------------
int __stdcall VMPI_SecondExceptionFilter(_EXCEPTION_POINTERS *ExceptionInfo)
{
  HANDLE CurrentProcess; // eax

  CurrentProcess = GetCurrentProcess();
  TerminateProcess(hProcess: CurrentProcess, uExitCode: 2u);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1001BF70
// Name: void VMPI_ExceptionFilter(unsigned long,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl VMPI_ExceptionFilter(unsigned int uCode, void *pvExceptionInfo)
{
  int v2; // eax
  char *pReason; // ecx
  HANDLE CurrentProcess; // eax
  char chUnknownBuffer[32]; // [esp+4h] [ebp-C8h] BYREF
  VMPI_ExceptionFilter::__l2::<unnamed_type_errors> errors[21]; // [esp+24h] [ebp-A8h]

  SetUnhandledExceptionFilter(lpTopLevelExceptionFilter: VMPI_SecondExceptionFilter);
  errors[0].pReason = "EXCEPTION_ACCESS_VIOLATION";
  errors[20].pReason = "EXCEPTION_ACCESS_VIOLATION";
  errors[0].code = -1073741819;
  errors[20].code = -1073741819;
  v2 = 0;
  errors[1].code = -1073741684;
  errors[1].pReason = "EXCEPTION_ARRAY_BOUNDS_EXCEEDED";
  errors[2].code = -2147483645;
  errors[2].pReason = "EXCEPTION_BREAKPOINT";
  errors[3].code = -2147483646;
  errors[3].pReason = "EXCEPTION_DATATYPE_MISALIGNMENT";
  errors[4].code = -1073741683;
  errors[4].pReason = "EXCEPTION_FLT_DENORMAL_OPERAND";
  errors[5].code = -1073741682;
  errors[5].pReason = "EXCEPTION_FLT_DIVIDE_BY_ZERO";
  errors[6].code = -1073741681;
  errors[6].pReason = "EXCEPTION_FLT_INEXACT_RESULT";
  errors[7].code = -1073741680;
  errors[7].pReason = "EXCEPTION_FLT_INVALID_OPERATION";
  errors[8].code = -1073741679;
  errors[8].pReason = "EXCEPTION_FLT_OVERFLOW";
  errors[9].code = -1073741678;
  errors[9].pReason = "EXCEPTION_FLT_STACK_CHECK";
  errors[10].code = -1073741677;
  errors[10].pReason = "EXCEPTION_FLT_UNDERFLOW";
  errors[11].code = -1073741795;
  errors[11].pReason = "EXCEPTION_ILLEGAL_INSTRUCTION";
  errors[12].code = -1073741818;
  errors[12].pReason = "EXCEPTION_IN_PAGE_ERROR";
  errors[13].code = -1073741676;
  errors[13].pReason = "EXCEPTION_INT_DIVIDE_BY_ZERO";
  errors[14].code = -1073741675;
  errors[14].pReason = "EXCEPTION_INT_OVERFLOW";
  errors[15].code = -1073741786;
  errors[15].pReason = "EXCEPTION_INVALID_DISPOSITION";
  errors[16].code = -1073741787;
  errors[16].pReason = "EXCEPTION_NONCONTINUABLE_EXCEPTION";
  errors[17].code = -1073741674;
  errors[17].pReason = "EXCEPTION_PRIV_INSTRUCTION";
  errors[18].code = -2147483644;
  errors[18].pReason = "EXCEPTION_SINGLE_STEP";
  errors[19].code = -1073741571;
  errors[19].pReason = "EXCEPTION_STACK_OVERFLOW";
  pReason = nullptr;
  while ( pReason == nullptr )
  {
    if ( errors[v2].code == uCode )
    {
      pReason = errors[v2].pReason;
      if ( pReason != nullptr )
      {
        ++v2;
        break;
      }
    }
    if ( errors[v2 + 1].code == uCode )
    {
      pReason = errors[v2 + 1].pReason;
      if ( pReason != nullptr )
      {
        v2 += 2;
        break;
      }
    }
    if ( errors[v2 + 2].code == uCode )
      pReason = errors[v2 + 2].pReason;
    v2 += 3;
    if ( v2 >= 21 )
      break;
  }
  if ( v2 == 21 )
  {
    sprintf(string: chUnknownBuffer, format: "Error code 0x%08X", uCode);
    pReason = chUnknownBuffer;
  }
  VMPI_HandleCrash(pMessage: pReason, uCode, pvExceptionInfo, bAssert: true);
  CurrentProcess = GetCurrentProcess();
  TerminateProcess(hProcess: CurrentProcess, uExitCode: 1u);
}

//------------------------------------------------------------------------------
// Address: 0x1001C160
// Name: void HandleMPIDisconnect(int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl HandleMPIDisconnect(int procID, const char *pReason)
{
  int CurrentNumberOfConnections; // eax
  bool v3; // bl
  int v4; // esi
  const char *MachineName; // eax

  CurrentNumberOfConnections = VMPI_GetCurrentNumberOfConnections();
  v3 = g_bSuppressPrintfOutput;
  v4 = CurrentNumberOfConnections - g_nDisconnects - 1;
  g_bSuppressPrintfOutput = V_stristr(pStr: pReason, pSearch: "invalid packet size") == nullptr;
  MachineName = VMPI_GetMachineName(iProc: procID);
  _Warning(a1: "\n\n--- WARNING: lost connection to '%s' (%s).\n", MachineName, pReason);
  if ( g_bMPIMaster )
  {
    _Warning(a1: "%d workers remain.\n\n", v4);
    ++g_nDisconnects;
  }
  else
  {
    VMPI_HandleAutoRestart();
    _Error(a1: "Worker quitting.");
  }
  g_bSuppressPrintfOutput = v3;
}

} // namespace vrad_dll

// ============================================================
// Overlay from vvis_dll (Missing functions)
// ============================================================
namespace vvis_dll {

//------------------------------------------------------------------------------
// Address: 0x100141E0
// Name: bool SharedDispatch(class MessageBuffer __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
char __cdecl SharedDispatch(MessageBuffer *pBuf, int iSource)
{
  char *v2; // ebx
  char v4; // al
  int *v5; // ebx
  const char *v6; // eax
  const void *v7; // ebx
  const char *v8; // edi
  _BYTE *v9; // eax
  _BYTE *v10; // eax
  int v11; // esi
  const char *MachineName; // eax
  _iobuf *v13; // eax
  _iobuf *v14; // esi
  int v15; // edi
  unsigned int v16; // eax
  int v17; // [esp-24h] [ebp-35Ch]
  int v18; // [esp-20h] [ebp-358h]
  int tm_mday; // [esp-1Ch] [ebp-354h]
  int tm_hour; // [esp-18h] [ebp-350h]
  int tm_min; // [esp-14h] [ebp-34Ch]
  int tm_sec; // [esp-10h] [ebp-348h]
  char chSaveFileName[520]; // [esp+4h] [ebp-334h] BYREF
  char chModuleName[260]; // [esp+20Ch] [ebp-12Ch] BYREF
  tm curTime; // [esp+310h] [ebp-28h] BYREF
  int iFileSize; // [esp+334h] [ebp-4h]
  const char *pModuleName; // [esp+340h] [ebp+8h]

  v2 = pBuf->data + 2;
  if ( pBuf->data[1] != 0 )
  {
    if ( pBuf->data[1] == 1 )
    {
      v16 = *(_DWORD *)(pBuf->data + 386);
      qmemcpy(&g_DBInfo, v2, sizeof(g_DBInfo));
      g_JobPrimaryID = v16;
      g_bReceivedDBInfo = true;
      return 1;
    }
    else if ( pBuf->data[1] == 3 )
    {
      v4 = *v2;
      v5 = (int *)(pBuf->data + 4);
      if ( v4 == 102 )
      {
        iFileSize = *v5;
        v7 = v5 + 1;
        v8 = getenv(option: "TEMP");
        if ( v8 == nullptr )
        {
          v8 = getenv(option: "TMP");
          if ( v8 == nullptr )
            v8 = "c:";
        }
        pModuleName = chModuleName;
        GetModuleFileNameA(hModule: nullptr, lpFilename: chModuleName, nSize: 0x104u);
        strrchr(string: (unsigned __int8 *)chModuleName, chr: 0x2Eu);
        if ( v9 != nullptr )
          *v9 = 0;
        strrchr(string: (unsigned __int8 *)chModuleName, chr: 0x5Cu);
        if ( v10 != nullptr )
        {
          *v10 = 0;
          pModuleName = v10 + 1;
        }
        _Plat_GetLocalTime(a1: &curTime);
        v11 = ++s_numMiniDumps;
        memset(chSaveFileName, 0, sizeof(chSaveFileName));
        tm_sec = curTime.tm_sec;
        tm_min = curTime.tm_min;
        tm_hour = curTime.tm_hour;
        tm_mday = curTime.tm_mday;
        v18 = curTime.tm_mon + 1;
        v17 = curTime.tm_year + 1900;
        MachineName = VMPI_GetMachineName(iProc: iSource);
        sprintf(
          string: chSaveFileName,
          format: "%s\\vmpi_%s_on_%s_%d%.2d%2d%.2d%.2d%.2d_%d.mdmp",
          v8,
          pModuleName,
          MachineName,
          v17,
          v18,
          tm_mday,
          tm_hour,
          tm_min,
          tm_sec,
          v11);
        v13 = fopen(file: chSaveFileName, mode: "wb");
        v14 = v13;
        if ( v13 != nullptr )
        {
          v15 = iFileSize;
          fwrite(buffer: v7, size: 1u, count: iFileSize, stream: v13);
          fclose(stream: v14);
          _Warning(a1: "\nSaved worker crash minidump '%s', size %d byte(s).\n", chSaveFileName, v15);
        }
        else
        {
          _Warning(a1: "\nReceived worker crash minidump size %d byte(s), failed to save.\n", iFileSize);
        }
        return 1;
      }
      else
      {
        if ( v4 == 116 )
        {
          v6 = VMPI_GetMachineName(iProc: iSource);
          _Warning(a1: "\nWorker '%s' dead: %s\n", v6, (const char *)v5);
        }
        return 1;
      }
    }
    else
    {
      return 0;
    }
  }
  else
  {
    V_strncpy(pDest: gamedir, pSrc: v2, maxLen: 1024);
    V_strncpy(pDest: qdir, pSrc: &v2[strlen(v2) + 1], maxLen: 1024);
    g_bReceivedDirectoryInfo = true;
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10014420
// Name: void SendQDirInfo(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SendQDirInfo()
{
  int Name; // eax
  MessageBuffer mb; // [esp+0h] [ebp-14h] BYREF
  char cPacketID[4]; // [esp+10h] [ebp-4h] BYREF

  strcpy(cPacketID, "\n");
  MessageBuffer::MessageBuffer(this: &mb);
  MessageBuffer::write(this: &mb, p: cPacketID, bytes: 2);
  MessageBuffer::write(this: &mb, p: gamedir, bytes: strlen(gamedir) + 1);
  MessageBuffer::write(this: &mb, p: qdir, bytes: strlen(qdir) + 1);
  Name = ConCommandBase::GetName(this: (CVMPIFile_Memory *)&mb);
  VMPI_SendData(pData: mb.data, nBytes: Name, iDest: -3, fVMPISendFlags: 0);
  MessageBuffer::~MessageBuffer(this: &mb);
}

//------------------------------------------------------------------------------
// Address: 0x100144B0
// Name: void RecvQDirInfo(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl RecvQDirInfo()
{
  while ( !g_bReceivedDirectoryInfo )
    VMPI_DispatchNextMessage(timeout: 0xFFFFFFFF);
}

//------------------------------------------------------------------------------
// Address: 0x100144E0
// Name: void SendDBInfo(class CDBInfo const __near *,unsigned long)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SendDBInfo(const CDBInfo *pInfo, unsigned int jobPrimaryID)
{
  const void *pChunks[3]; // [esp+0h] [ebp-1Ch] BYREF
  int chunkLengths[3]; // [esp+Ch] [ebp-10h] BYREF
  char cPacketInfo[2]; // [esp+18h] [ebp-4h] BYREF

  pChunks[0] = cPacketInfo;
  pChunks[1] = pInfo;
  *(_WORD *)cPacketInfo = 266;
  pChunks[2] = &jobPrimaryID;
  chunkLengths[0] = 2;
  chunkLengths[1] = 384;
  chunkLengths[2] = 4;
  VMPI_SendChunks(pChunks, pChunkLengths: chunkLengths, nChunks: 3, iDest: -3, fVMPISendFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10014530
// Name: void RecvDBInfo(class CDBInfo __near *,unsigned long __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl RecvDBInfo(CDBInfo *pInfo, unsigned int *pJobPrimaryID)
{
  while ( !g_bReceivedDBInfo )
    VMPI_DispatchNextMessage(timeout: 0xFFFFFFFF);
  *pInfo = g_DBInfo;
  *pJobPrimaryID = g_JobPrimaryID;
}

//------------------------------------------------------------------------------
// Address: 0x10014580
// Name: int VMPI_SendFileChunk(void const __near *,int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl VMPI_SendFileChunk(const void *pvChunkPrefix, int lenPrefix, const char *ptchFileName)
{
  int v3; // ebx
  HANDLE FileA; // eax
  void *v5; // esi
  HANDLE FileMappingA; // eax
  void *v7; // edi
  const void *v8; // ebx
  DWORD FileSize; // eax
  int iResult; // [esp+8h] [ebp-8h]
  int iMappedFileSize; // [esp+Ch] [ebp-4h] BYREF

  v3 = 0;
  iResult = 0;
  FileA = CreateFileA(
            lpFileName: ptchFileName,
            dwDesiredAccess: 0x80000000,
            dwShareMode: 0,
            lpSecurityAttributes: nullptr,
            dwCreationDisposition: 3u,
            dwFlagsAndAttributes: 0x80u,
            hTemplateFile: nullptr);
  v5 = FileA;
  if ( FileA != nullptr && FileA != (HANDLE)-1 )
  {
    FileMappingA = CreateFileMappingA(
                     hFile: FileA,
                     lpFileMappingAttributes: nullptr,
                     flProtect: 2u,
                     dwMaximumSizeHigh: 0,
                     dwMaximumSizeLow: 0,
                     lpName: nullptr);
    v7 = FileMappingA;
    if ( FileMappingA != nullptr && FileMappingA != (HANDLE)-1 )
    {
      v8 = MapViewOfFile(
             hFileMappingObject: FileMappingA,
             dwDesiredAccess: 4u,
             dwFileOffsetHigh: 0,
             dwFileOffsetLow: 0,
             dwNumberOfBytesToMap: 0);
      if ( v8 != nullptr )
      {
        FileSize = GetFileSize(hFile: v5, lpFileSizeHigh: nullptr);
        iMappedFileSize = FileSize;
        if ( FileSize != -1
          && VMPI_Send3Chunks(
               pChunk1: pvChunkPrefix,
               chunk1Len: lenPrefix,
               pChunk2: &iMappedFileSize,
               chunk2Len: 4,
               pChunk3: v8,
               chunk3Len: FileSize,
               iDest: 0,
               fVMPISendFlags: 0) )
        {
          iResult = iMappedFileSize;
        }
        UnmapViewOfFile(lpBaseAddress: v8);
      }
      CloseHandle(hObject: v7);
      v3 = iResult;
    }
    CloseHandle(hObject: v5);
  }
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x10014640
// Name: void VMPI_HandleCrash(char const __near *,unsigned int,void __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl VMPI_HandleCrash(const char *pMessage, unsigned int uCode, void *pvExceptionInfo, bool bAssert)
{
  char tchMinidumpFileName[260]; // [esp+0h] [ebp-108h] BYREF
  char crashMsg[4]; // [esp+104h] [ebp-4h] BYREF

  if ( InterlockedIncrement(lpAddend: &crashHandlerCount) == 1 )
  {
    _Msg(a1: "\nFAILURE: '%s' (assert: %d)\n", pMessage, bAssert);
    *(_DWORD *)crashMsg = 980681482;
    VMPI_Send2Chunks(
      pChunk1: crashMsg,
      chunk1Len: 4,
      pChunk2: pMessage,
      chunk2Len: strlen(pMessage) + 1,
      iDest: 0,
      fVMPISendFlags: 0);
    if ( pvExceptionInfo != nullptr )
    {
      memset(tchMinidumpFileName, 0, sizeof(tchMinidumpFileName));
      if ( (unsigned __int8)_WriteMiniDumpUsingExceptionInfo(
                              a1: uCode,
                              a2: pvExceptionInfo,
                              a3: 321,
                              a4: tchMinidumpFileName) != 0 )
      {
        crashMsg[2] = 102;
        VMPI_SendFileChunk(pvChunkPrefix: crashMsg, lenPrefix: 4, ptchFileName: tchMinidumpFileName);
        DeleteFileA(lpFileName: tchMinidumpFileName);
      }
    }
    Sleep(dwMilliseconds: 0x1F4u);
  }
  InterlockedDecrement(lpAddend: &crashHandlerCount);
}

//------------------------------------------------------------------------------
// Address: 0x10014720
// Name: long VMPI_SecondExceptionFilter(struct _EXCEPTION_POINTERS __near *)
// Source: json
//------------------------------------------------------------------------------
int __stdcall VMPI_SecondExceptionFilter(_EXCEPTION_POINTERS *ExceptionInfo)
{
  HANDLE CurrentProcess; // eax

  CurrentProcess = GetCurrentProcess();
  TerminateProcess(hProcess: CurrentProcess, uExitCode: 2u);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10014740
// Name: void VMPI_ExceptionFilter(unsigned long,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl VMPI_ExceptionFilter(unsigned int uCode, void *pvExceptionInfo)
{
  int v2; // eax
  char *pReason; // ecx
  HANDLE CurrentProcess; // eax
  char chUnknownBuffer[32]; // [esp+4h] [ebp-C8h] BYREF
  VMPI_ExceptionFilter::__l2::<unnamed_type_errors> errors[21]; // [esp+24h] [ebp-A8h]

  SetUnhandledExceptionFilter(lpTopLevelExceptionFilter: VMPI_SecondExceptionFilter);
  errors[0].pReason = "EXCEPTION_ACCESS_VIOLATION";
  errors[20].pReason = "EXCEPTION_ACCESS_VIOLATION";
  errors[0].code = -1073741819;
  errors[20].code = -1073741819;
  v2 = 0;
  errors[1].code = -1073741684;
  errors[1].pReason = "EXCEPTION_ARRAY_BOUNDS_EXCEEDED";
  errors[2].code = -2147483645;
  errors[2].pReason = "EXCEPTION_BREAKPOINT";
  errors[3].code = -2147483646;
  errors[3].pReason = "EXCEPTION_DATATYPE_MISALIGNMENT";
  errors[4].code = -1073741683;
  errors[4].pReason = "EXCEPTION_FLT_DENORMAL_OPERAND";
  errors[5].code = -1073741682;
  errors[5].pReason = "EXCEPTION_FLT_DIVIDE_BY_ZERO";
  errors[6].code = -1073741681;
  errors[6].pReason = "EXCEPTION_FLT_INEXACT_RESULT";
  errors[7].code = -1073741680;
  errors[7].pReason = "EXCEPTION_FLT_INVALID_OPERATION";
  errors[8].code = -1073741679;
  errors[8].pReason = "EXCEPTION_FLT_OVERFLOW";
  errors[9].code = -1073741678;
  errors[9].pReason = "EXCEPTION_FLT_STACK_CHECK";
  errors[10].code = -1073741677;
  errors[10].pReason = "EXCEPTION_FLT_UNDERFLOW";
  errors[11].code = -1073741795;
  errors[11].pReason = "EXCEPTION_ILLEGAL_INSTRUCTION";
  errors[12].code = -1073741818;
  errors[12].pReason = "EXCEPTION_IN_PAGE_ERROR";
  errors[13].code = -1073741676;
  errors[13].pReason = "EXCEPTION_INT_DIVIDE_BY_ZERO";
  errors[14].code = -1073741675;
  errors[14].pReason = "EXCEPTION_INT_OVERFLOW";
  errors[15].code = -1073741786;
  errors[15].pReason = "EXCEPTION_INVALID_DISPOSITION";
  errors[16].code = -1073741787;
  errors[16].pReason = "EXCEPTION_NONCONTINUABLE_EXCEPTION";
  errors[17].code = -1073741674;
  errors[17].pReason = "EXCEPTION_PRIV_INSTRUCTION";
  errors[18].code = -2147483644;
  errors[18].pReason = "EXCEPTION_SINGLE_STEP";
  errors[19].code = -1073741571;
  errors[19].pReason = "EXCEPTION_STACK_OVERFLOW";
  pReason = nullptr;
  while ( pReason == nullptr )
  {
    if ( errors[v2].code == uCode )
    {
      pReason = errors[v2].pReason;
      if ( pReason != nullptr )
      {
        ++v2;
        break;
      }
    }
    if ( errors[v2 + 1].code == uCode )
    {
      pReason = errors[v2 + 1].pReason;
      if ( pReason != nullptr )
      {
        v2 += 2;
        break;
      }
    }
    if ( errors[v2 + 2].code == uCode )
      pReason = errors[v2 + 2].pReason;
    v2 += 3;
    if ( v2 >= 21 )
      break;
  }
  if ( v2 == 21 )
  {
    sprintf(string: chUnknownBuffer, format: "Error code 0x%08X", uCode);
    pReason = chUnknownBuffer;
  }
  VMPI_HandleCrash(pMessage: pReason, uCode, pvExceptionInfo, bAssert: true);
  CurrentProcess = GetCurrentProcess();
  TerminateProcess(hProcess: CurrentProcess, uExitCode: 1u);
}

//------------------------------------------------------------------------------
// Address: 0x10014930
// Name: void HandleMPIDisconnect(int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl HandleMPIDisconnect(int procID, const char *pReason)
{
  int CurrentNumberOfConnections; // eax
  bool v3; // bl
  int v4; // esi
  const char *MachineName; // eax

  CurrentNumberOfConnections = VMPI_GetCurrentNumberOfConnections();
  v3 = g_bSuppressPrintfOutput;
  v4 = CurrentNumberOfConnections - g_nDisconnects - 1;
  g_bSuppressPrintfOutput = V_stristr(pStr: pReason, pSearch: "invalid packet size") == nullptr;
  MachineName = VMPI_GetMachineName(iProc: procID);
  _Warning(a1: "\n\n--- WARNING: lost connection to '%s' (%s).\n", MachineName, pReason);
  if ( g_bMPIMaster )
  {
    _Warning(a1: "%d workers remain.\n\n", v4);
    ++g_nDisconnects;
  }
  else
  {
    VMPI_HandleAutoRestart();
    _Error(a1: "Worker quitting.");
  }
  g_bSuppressPrintfOutput = v3;
}

} // namespace vvis_dll
