// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/shadercompile/shadercompile.cpp
// Functions: 191
// ============================================================

#include "utils\shadercompile\shadercompile.h"

//------------------------------------------------------------------------------
// Address: 0x10008BA0
// Name: char __near * PrettyPrintNumber(unsigned __int64)
// Source: json
//------------------------------------------------------------------------------
char *__cdecl PrettyPrintNumber(unsigned __int64 k)
{
  unsigned int v1; // ebx
  char *v2; // esi
  unsigned __int64 v3; // rax
  int v4; // edi
  char *result; // eax
  unsigned __int64 j; // [esp+8h] [ebp-8h]

  v1 = k;
  v2 = &chCompileString[47];
  j = 0;
  if ( k != 0 )
  {
    do
    {
      if ( j != 0 && j % 3 == 0 )
        *v2-- = 44;
      v3 = __PAIR64__(HIDWORD(k), v1) / 0xA;
      v4 = (__PAIR64__(HIDWORD(k), v1) / 0xA) >> 32;
      --v2;
      HIDWORD(k) = v4;
      ++j;
      v2[1] = v1 - 10 * v3 + 48;
      v1 = v3;
    }
    while ( v4 != 0 || (_DWORD)v3 != 0 );
  }
  result = v2 + 1;
  if ( v2[1] == 0 )
    v2[1] = 0;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10008C50
// Name: CompareDynamicComboIDs
// Source: json
//------------------------------------------------------------------------------
int __cdecl CompareDynamicComboIDs(CByteCodeBlock *const *pA, CByteCodeBlock *const *pB)
{
  unsigned int m_nComboID; // edx
  unsigned int m_nComboID_high; // eax
  unsigned int v4; // esi
  unsigned int v5; // ecx

  m_nComboID = (*pA)->m_nComboID;
  m_nComboID_high = HIDWORD((*pA)->m_nComboID);
  v4 = (*pB)->m_nComboID;
  v5 = HIDWORD((*pB)->m_nComboID);
  if ( m_nComboID_high > v5 )
    return 1;
  if ( m_nComboID_high < v5 || m_nComboID < v4 )
    return -1;
  return __PAIR64__(m_nComboID_high, m_nComboID) > __PAIR64__(v5, v4);
}

//------------------------------------------------------------------------------
// Address: 0x10008CA0
// Name: public: void CompilerMsgInfo::SetMsgReportedCommand(char const __near *,int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CompilerMsgInfo::SetMsgReportedCommand(
        CompilerMsgInfo *this,
        const char *szCommand,
        int numTimesReported,
        const char *szMachineName)
{
  if ( this->m_numTimesReported != 0 )
  {
    this->m_numTimesReported += numTimesReported;
  }
  else
  {
    CUtlString::operator=(this: &this->m_sFirstCommand, src: szCommand);
    if ( szMachineName != nullptr )
      CUtlString::operator=(this: &this->m_sFirstMachineName, src: szMachineName);
    this->m_numTimesReported += numTimesReported;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10008CF0
// Name: bool StartWorkDispatch(class MessageBuffer __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
char __cdecl StartWorkDispatch()
{
  g_bGotStartWorkPacket = true;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10008D00
// Name: char __near * FindNext(char __near *,char __near *)
// Source: json
//------------------------------------------------------------------------------
char *__cdecl FindNext(char *szString, char *szSearchSet)
{
  bool v3; // bl
  char *v4; // esi
  unsigned __int8 i; // al
  char *v6; // eax
  char *szNext; // [esp+10h] [ebp+8h]

  v3 = szString == nullptr;
  szNext = nullptr;
  if ( !v3 )
  {
    v4 = szSearchSet;
    if ( szSearchSet != nullptr )
    {
      for ( i = *szSearchSet; i != 0; ++v4 )
      {
        strchr(string: szString, chr: i);
        if ( v6 != nullptr )
        {
          if ( !v3 || szNext >= v6 )
            szNext = v6;
          v3 = true;
        }
        i = v4[1];
      }
    }
  }
  if ( v3 )
    return szNext;
  else
    return &szString[strlen(szString)];
}

//------------------------------------------------------------------------------
// Address: 0x10008D70
// Name: char __near * FindLast(char __near *,char __near *)
// Source: json
//------------------------------------------------------------------------------
char *__cdecl FindLast(char *szString, char *szSearchSet)
{
  bool v3; // zf
  bool v4; // bl
  char *v5; // esi
  unsigned __int8 i; // al
  char *v7; // eax
  char *szNext; // [esp+10h] [ebp+8h]

  v3 = szString == nullptr;
  v4 = szString != nullptr;
  szNext = nullptr;
  if ( !v3 )
  {
    v5 = szSearchSet;
    if ( szSearchSet != nullptr )
    {
      for ( i = *szSearchSet; i != 0; ++v5 )
      {
        strrchr(string: (unsigned __int8 *)szString, chr: i);
        if ( v7 != nullptr )
        {
          if ( !v4 || szNext <= v7 )
            szNext = v7;
          v4 = true;
        }
        i = v5[1];
      }
    }
  }
  if ( v4 )
    return szNext;
  else
    return &szString[strlen(szString)];
}

//------------------------------------------------------------------------------
// Address: 0x10008DE0
// Name: void DebugOut(char const __near *,...)
// Source: json
//------------------------------------------------------------------------------
void DebugOut(const char *pMsg, ...)
{
  char msg[2048]; // [esp+0h] [ebp-800h] BYREF
  va_list ap; // [esp+80Ch] [ebp+Ch] BYREF

  va_start(ap, pMsg);
  if ( g_bVerbose )
  {
    _vsnprintf(string: msg, count: 0x800u, format: pMsg, ap);
    _Msg(a1: "%s", msg);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10008E30
// Name: void Vmpi_Worker_DefaultDisconnectHandler(int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Vmpi_Worker_DefaultDisconnectHandler()
{
  HANDLE CurrentProcess; // eax

  _Msg(a1: "Master disconnected.\n ");
  DebugOut(pMsg: "Master disconnected.\n");
  CurrentProcess = GetCurrentProcess();
  TerminateProcess(hProcess: CurrentProcess, uExitCode: 1u);
}

//------------------------------------------------------------------------------
// Address: 0x10008E60
// Name: void MyDisconnectHandler(int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MyDisconnectHandler(int procID, const char *pReason)
{
  if ( !g_bMPIMaster && g_fnDisconnectHandler != nullptr )
    g_fnDisconnectHandler(a1: procID, a2: pReason);
}

//------------------------------------------------------------------------------
// Address: 0x10008E80
// Name: CompareComboIds
// Source: json
//------------------------------------------------------------------------------
int __cdecl CompareComboIds(const StaticComboAuxInfo_t *pA, const StaticComboAuxInfo_t *pB)
{
  if ( pB->m_nStaticComboID <= pA->m_nStaticComboID )
    return pB->m_nStaticComboID < pA->m_nStaticComboID;
  else
    return -1;
}

//------------------------------------------------------------------------------
// Address: 0x10008EA0
// Name: void GetVCSFilenames(char __near *,struct ShaderInfo_t const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GetVCSFilenames(char *pszMainOutFileName, const ShaderInfo_t *si)
{
  char *v2; // eax
  _stat64i32 buf; // [esp+4h] [ebp-30h] BYREF

  sprintf(string: pszMainOutFileName, format: "%s\\shaders\\fxc", g_pShaderPath);
  if ( _stat64i32(name: pszMainOutFileName, &buf) == -1 )
  {
    printf(format: "mkdir %s\n", pszMainOutFileName);
    _mkdir(path: pszMainOutFileName);
  }
  strcat(pszMainOutFileName, "\\");
  qmemcpy(
    &pszMainOutFileName[strlen(pszMainOutFileName)],
    si->m_pShaderName,
    &si->m_pShaderName[strlen(si->m_pShaderName) + 1] - si->m_pShaderName);
  if ( g_bIsX360 )
  {
    v2 = &pszMainOutFileName[strlen(pszMainOutFileName)];
    *(_DWORD *)v2 = *(_DWORD *)a360;
  }
  else
  {
    if ( !g_bIsPS3 )
      goto LABEL_8;
    v2 = &pszMainOutFileName[strlen(pszMainOutFileName)];
    *(_DWORD *)v2 = *(_DWORD *)aPs3_1;
  }
  v2[4] = 0;
LABEL_8:
  strcat(pszMainOutFileName, ".vcs");
  if ( _stat64i32(name: pszMainOutFileName, &buf) != -1 && SLOBYTE(buf.st_mode) >= 0 )
  {
    printf(format: "Warning: making %s writable!\n", pszMainOutFileName);
    _chmod(path: pszMainOutFileName, mode: 128);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10008FE0
// Name: void MySystem(char const __near * const,struct CmdSink::IResponse __near * __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MySystem(char *pCommand, CmdSink::IResponse **ppResponse)
{
  DWORD CurrentProcessId; // eax
  _iobuf *v3; // esi
  DWORD CurrentThreadId; // [esp-8h] [ebp-C4h]
  char szTempFileName[100]; // [esp+4h] [ebp-B8h] BYREF
  _STARTUPINFOA StartupInfo; // [esp+68h] [ebp-54h] BYREF
  _PROCESS_INFORMATION pi; // [esp+ACh] [ebp-10h] BYREF

  if ( InterceptFxc::TryExecuteCommand(pCommand, ppResponse) != 0 )
  {
    Sleep(dwMilliseconds: 0);
  }
  else
  {
    unlink(path: "shader.o");
    CurrentThreadId = GetCurrentThreadId();
    CurrentProcessId = GetCurrentProcessId();
    sprintf(string: szTempFileName, format: "sc%d_%d.bat", CurrentProcessId, CurrentThreadId);
    v3 = fopen(file: (_iobuf *)szTempFileName, mode: "w");
    fprintf(str: v3, format: "%s\n", pCommand);
    fclose(stream: v3);
    memset(dst: (int)&StartupInfo, value: nullptr, count: sizeof(StartupInfo));
    StartupInfo.cb = 68;
    memset(&pi, 0, sizeof(pi));
    if ( !CreateProcessA(
            lpApplicationName: nullptr,
            lpCommandLine: szTempFileName,
            lpProcessAttributes: nullptr,
            lpThreadAttributes: nullptr,
            bInheritHandles: false,
            dwCreationFlags: 0x8000040u,
            lpEnvironment: nullptr,
            lpCurrentDirectory: g_WorkerTempPath,
            lpStartupInfo: &StartupInfo,
            lpProcessInformation: &pi) )
      _Error(a1: "CreateProcess failed.");
    WaitForSingleObject(hHandle: pi.hProcess, dwMilliseconds: 0xFFFFFFFF);
    CloseHandle(hObject: pi.hProcess);
    CloseHandle(hObject: pi.hThread);
    unlink(path: szTempFileName);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100090F0
// Name: void Shader_ParseShaderInfoFromCompileCommands(struct CfgProcessor::CfgEntryInfo const __near *,struct ShaderInfo_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Shader_ParseShaderInfoFromCompileCommands(
        const CfgProcessor::CfgEntryInfo *pEntry,
        ShaderInfo_t *shaderInfo)
{
  CfgProcessor::<unnamed_type_ComboHandle> *Combo; // eax
  int v3; // eax
  int v4; // esi
  char *v5; // eax
  int v6; // eax
  int v7; // eax
  int v8; // ebx
  char *m_szShaderModel; // esi
  char *v10; // ebx
  char v11; // dl
  unsigned __int8 *v12; // [esp-20h] [ebp-1028h]
  char pchBuffer[4096]; // [esp+0h] [ebp-1008h] BYREF
  CfgProcessor::<unnamed_type_ComboHandle> *rhComboFree; // [esp+1000h] [ebp-8h] BYREF
  char *v15; // [esp+1004h] [ebp-4h]

  Combo = (CfgProcessor::<unnamed_type_ComboHandle> *)CfgProcessor::Combo_GetCombo(iCommandNumber: pEntry->m_iCommandStart);
  rhComboFree = Combo;
  if ( Combo != nullptr )
  {
    CfgProcessor::Combo_FormatCommand(hCombo: Combo, pchBuffer);
    memset(dst: (int)shaderInfo, value: nullptr, count: sizeof(ShaderInfo_t));
    if ( g_bIsPS3 )
    {
      strstr(str1: (unsigned __int8 *)pchBuffer, str2: "-DCENTROIDMASK=");
      v4 = v3;
      strstr(str1: (unsigned __int8 *)pchBuffer, str2: "-DFLAGS=0x");
      v12 = "-DSHADER_MODEL_";
    }
    else
    {
      strstr(str1: (unsigned __int8 *)pchBuffer, str2: "/DCENTROIDMASK=");
      v4 = v6;
      strstr(str1: (unsigned __int8 *)pchBuffer, str2: "/DFLAGS=0x");
      v12 = "/DSHADER_MODEL_";
    }
    v15 = v5;
    strstr(str1: (unsigned __int8 *)pchBuffer, str2: v12);
    v8 = v7;
    if ( v4 != 0 && v15 != nullptr && v7 != 0 )
    {
      sscanf(string: (char *)(v4 + 15), format: "%u", &shaderInfo->m_CentroidMask);
      sscanf(string: v15 + 10, format: "%x", &shaderInfo->m_Flags);
      m_szShaderModel = shaderInfo->m_szShaderModel;
      v10 = (char *)(v8 + 15);
      v15 = &shaderInfo->m_szShaderModel[11];
      if ( shaderInfo->m_szShaderModel < &shaderInfo->m_szShaderModel[11] )
      {
        while ( 1 )
        {
          v11 = *v10++;
          *m_szShaderModel = v11;
          if ( v11 == 0 || isspace(c: v11) != 0 || *m_szShaderModel == 61 )
            break;
          if ( ++m_szShaderModel >= v15 )
            goto LABEL_15;
        }
        *m_szShaderModel = 0;
      }
LABEL_15:
      shaderInfo->m_nShaderCombo = 0;
      shaderInfo->m_nTotalShaderCombos = pEntry->m_numCombos;
      shaderInfo->m_nDynamicCombos = pEntry->m_numDynamicCombos;
      shaderInfo->m_nStaticCombo = 0;
      shaderInfo->m_pShaderName = pEntry->m_szName;
      shaderInfo->m_pShaderSrc = pEntry->m_szShaderFileName;
      CfgProcessor::Combo_Free(&rhComboFree);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10009280
// Name: void SetupExeDir(int,char __near * __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SetupExeDir(int argc, char **argv)
{
  char *v2; // ecx
  char *v3; // edx
  char v4; // al

  v2 = *argv;
  v3 = g_ExeDir;
  do
  {
    v4 = *v2;
    *v3++ = *v2++;
  }
  while ( v4 != 0 );
  V_StripFilename(path: g_ExeDir);
  if ( g_ExeDir[0] == 0 )
    V_strncpy(pDest: g_ExeDir, pSrc: ".\\", maxLen: 260);
  V_FixSlashes(pname: g_ExeDir, separator: 92);
}

//------------------------------------------------------------------------------
// Address: 0x100092E0
// Name: void SetupPaths(int,char __near * __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SetupPaths(int argc, char **argv)
{
  void (__thiscall ***v2)(_DWORD, int, char **); // eax
  int v3; // eax
  int v4; // eax
  char tmp[260]; // [esp+0h] [ebp-104h] BYREF

  GetTempPathA(nBufferLength: 0x104u, lpBuffer: g_WorkerTempPath);
  strcat(g_WorkerTempPath, "shadercompiletemp\\");
  sprintf(string: tmp, format: "rd /s /q \"%s\"", g_WorkerTempPath);
  system(command: tmp);
  _mkdir(path: g_WorkerTempPath);
  v2 = (void (__thiscall ***)(_DWORD, int, char **))_CommandLine();
  (**v2)(a1: v2, a2: argc, a3: argv);
  v3 = _CommandLine();
  g_pShaderPath = (const char *)(*(int (__thiscall **)(int, const char *, const char *))(*(_DWORD *)v3 + 32))(
                                  a1: v3,
                                  a2: "-shaderpath",
                                  a3: setName);
  v4 = _CommandLine();
  g_bVerbose = (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v4 + 40))(a1: v4, a2: "-verbose") != 0;
}

//------------------------------------------------------------------------------
// Address: 0x100093F0
// Name: private: static void CWorkerAccumState<class CThreadFastMutex>::Special_DisconnectHandler(int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CWorkerAccumState<CThreadFastMutex>::Special_DisconnectHandler()
{
  `CWorkerAccumState<CThreadFastMutex>::DisconnectState'::`2'::sb = 1;
}

//------------------------------------------------------------------------------
// Address: 0x10009400
// Name: private: static void CWorkerAccumState<class CThreadNullMutex>::Special_DisconnectHandler(int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CWorkerAccumState<CThreadNullMutex>::Special_DisconnectHandler()
{
  `CWorkerAccumState<CThreadNullMutex>::DisconnectState'::`2'::sb = 1;
}

//------------------------------------------------------------------------------
// Address: 0x10009570
// Name: FlushCombos
// Source: json
//------------------------------------------------------------------------------
void __usercall FlushCombos(
        CUtlBuffer *pDynamicComboBuffer@<esi>,
        unsigned int *pnTotalFlushedSize,
        MessageBuffer *pBuf)
{
  unsigned int m_Put; // eax
  unsigned __int8 *v4; // edi
  unsigned int v5; // eax
  unsigned int v6; // ecx
  unsigned int v7; // eax
  int lFlagSize; // [esp+8h] [ebp-8h] BYREF
  unsigned int nCompressedSize; // [esp+Ch] [ebp-4h] BYREF

  m_Put = pDynamicComboBuffer->m_Put;
  if ( m_Put != 0 )
  {
    v4 = LZMA_Compress(
           pInput: pDynamicComboBuffer->m_Memory.m_pMemory,
           inputSize: m_Put,
           pOutputSize: &nCompressedSize,
           dictionarySize: 0x12u);
    if ( v4 != nullptr )
    {
      v7 = nCompressedSize | 0x40000000;
      if ( g_bIsX360 || g_bIsPS3 )
        v7 = _byteswap_ulong(nCompressedSize | 0x40000000);
      lFlagSize = v7;
      MessageBuffer::write(this: pBuf, p: &lFlagSize, bytes: 4);
      MessageBuffer::write(this: pBuf, p: v4, bytes: nCompressedSize);
      free(pMem: v4);
      v6 = nCompressedSize;
    }
    else
    {
      v5 = pDynamicComboBuffer->m_Put | 0x80000000;
      if ( g_bIsX360 || g_bIsPS3 )
        v5 = _byteswap_ulong(pDynamicComboBuffer->m_Put | 0x80000000);
      lFlagSize = v5;
      MessageBuffer::write(this: pBuf, p: &lFlagSize, bytes: 4);
      MessageBuffer::write(this: pBuf, p: pDynamicComboBuffer->m_Memory.m_pMemory, bytes: pDynamicComboBuffer->m_Put);
      v6 = pDynamicComboBuffer->m_Put;
    }
    *pnTotalFlushedSize += v6 + 4;
    pDynamicComboBuffer->m_Get = 0;
    pDynamicComboBuffer->m_Put = 0;
    pDynamicComboBuffer->m_Error = 0;
    pDynamicComboBuffer->m_nOffset = 0;
    pDynamicComboBuffer->m_nMaxPut = -1;
    CUtlBuffer::AddNullTermination(this: pDynamicComboBuffer, nPut: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10009700
// Name: public: void CByteswap::SwapBufferToTargetEndian<unsigned int>(unsigned int __near *,unsigned int __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapBufferToTargetEndian<unsigned int>(
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
// Address: 0x10009790
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
// Address: 0x100098C0
// Name: public: void CUtlIntrusiveDList<struct CStaticCombo>::RemoveNode(struct CStaticCombo __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlIntrusiveDList<CStaticCombo>::RemoveNode(
        CUtlIntrusiveDList<CStaticCombo> *this,
        CStaticCombo *which)
{
  CStaticCombo *m_pPrev; // edx
  CStaticCombo *m_pNext; // edx

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
  else if ( this->m_pHead == which )
  {
    m_pNext = which->m_pNext;
    this->m_pHead = which->m_pNext;
    if ( m_pNext != nullptr )
      m_pNext->m_pPrev = nullptr;
  }
  which->m_pPrev = nullptr;
  which->m_pNext = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10009A90
// Name: public: void CWorkerAccumState<class CThreadFastMutex>::RangeBegin(unsigned __int64,unsigned __int64)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWorkerAccumState<CThreadFastMutex>::RangeBegin(
        CWorkerAccumState<CThreadFastMutex> *this,
        unsigned __int64 iFirstCommand,
        unsigned __int64 iEndCommand)
{
  int i; // edi
  CWorkerAccumState<CThreadFastMutex>::SubProcess *v5; // eax
  char *v6; // eax
  SubProcessKernelObjects_Memory shrmem; // [esp+Ch] [ebp-Ch] BYREF

  LODWORD(this->m_iFirstCommand) = iFirstCommand;
  LODWORD(this->m_iNextCommand) = iFirstCommand;
  LODWORD(this->m_iLastFinished) = iFirstCommand;
  HIDWORD(this->m_iFirstCommand) = HIDWORD(iFirstCommand);
  HIDWORD(this->m_iNextCommand) = HIDWORD(iFirstCommand);
  this->m_iEndCommand = iEndCommand;
  HIDWORD(this->m_iLastFinished) = HIDWORD(iFirstCommand);
  this->m_hCombo = nullptr;
  CfgProcessor::Combo_GetNext(
    riCommandNumber: &this->m_iNextCommand,
    rhCombo: (ConfigurationProcessing::ComboHandleImpl **)&this->m_hCombo,
    iCommandEnd: iEndCommand);
  g_fnDisconnectHandler = (void (__cdecl *)(int, const char *))CWorkerAccumState<CThreadFastMutex>::Special_DisconnectHandler;
  for ( i = 0; i < this->m_arrSubProcessInfos.m_Size; ++i )
  {
    v5 = this->m_arrSubProcessInfos.m_Memory.m_pMemory[i];
    if ( v5 != nullptr )
    {
      shrmem.m_pObjs = v5->pCommObjs;
      shrmem.m_pMemory = nullptr;
      shrmem.m_pLockData = nullptr;
      v6 = (char *)SubProcessKernelObjects_Memory::Lock(this: &shrmem);
      if ( v6 != nullptr )
      {
        strcpy(v6, "keepalive");
        SubProcessKernelObjects_Memory::Unlock(this: &shrmem);
      }
      SubProcessKernelObjects_Memory::Unlock(this: &shrmem);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10009B50
// Name: public: void CWorkerAccumState<class CThreadNullMutex>::RangeBegin(unsigned __int64,unsigned __int64)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWorkerAccumState<CThreadNullMutex>::RangeBegin(
        CWorkerAccumState<CThreadNullMutex> *this,
        unsigned __int64 iFirstCommand,
        unsigned __int64 iEndCommand)
{
  int i; // edi
  CWorkerAccumState<CThreadNullMutex>::SubProcess *v5; // eax
  char *v6; // eax
  SubProcessKernelObjects_Memory shrmem; // [esp+Ch] [ebp-Ch] BYREF

  LODWORD(this->m_iFirstCommand) = iFirstCommand;
  LODWORD(this->m_iNextCommand) = iFirstCommand;
  LODWORD(this->m_iLastFinished) = iFirstCommand;
  HIDWORD(this->m_iFirstCommand) = HIDWORD(iFirstCommand);
  HIDWORD(this->m_iNextCommand) = HIDWORD(iFirstCommand);
  this->m_iEndCommand = iEndCommand;
  HIDWORD(this->m_iLastFinished) = HIDWORD(iFirstCommand);
  this->m_hCombo = nullptr;
  CfgProcessor::Combo_GetNext(
    riCommandNumber: &this->m_iNextCommand,
    rhCombo: (ConfigurationProcessing::ComboHandleImpl **)&this->m_hCombo,
    iCommandEnd: iEndCommand);
  g_fnDisconnectHandler = (void (__cdecl *)(int, const char *))CWorkerAccumState<CThreadNullMutex>::Special_DisconnectHandler;
  for ( i = 0; i < this->m_arrSubProcessInfos.m_Size; ++i )
  {
    v5 = this->m_arrSubProcessInfos.m_Memory.m_pMemory[i];
    if ( v5 != nullptr )
    {
      shrmem.m_pObjs = v5->pCommObjs;
      shrmem.m_pMemory = nullptr;
      shrmem.m_pLockData = nullptr;
      v6 = (char *)SubProcessKernelObjects_Memory::Lock(this: &shrmem);
      if ( v6 != nullptr )
      {
        strcpy(v6, "keepalive");
        SubProcessKernelObjects_Memory::Unlock(this: &shrmem);
      }
      SubProcessKernelObjects_Memory::Unlock(this: &shrmem);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10009C10
// Name: protected: void CUtlBuffer::PutTypeBin<int>(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlBuffer::PutTypeBin<int>(CUtlBuffer *this, int src)
{
  if ( CUtlBuffer::CheckPut(this, nSize: 4) )
  {
    if ( (*(_BYTE *)&this->m_Byteswap & 1) != 0 )
      CByteswap::SwapBufferToTargetEndian<unsigned int>(
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
// Address: 0x10009D10
// Name: public: virtual int CRefCounted1<class CFunctor,class CRefCountServiceBase<1,class CRefMT>>::AddRef(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>::AddRef(
        CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT> > *this)
{
  return _InterlockedIncrement(&this->m_iRefs);
}

//------------------------------------------------------------------------------
// Address: 0x10009D20
// Name: public: virtual int CRefCounted1<class CFunctor,class CRefCountServiceBase<1,class CRefMT>>::Release(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>::Release(
        CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT> > *this)
{
  CRefCountServiceBase<1,CRefMT> *v1; // esi
  int result; // eax

  v1 = &this->CRefCountServiceBase<1,CRefMT>;
  result = _InterlockedDecrement(&this->m_iRefs);
  if ( result == 0 )
  {
    if ( v1->OnFinalRelease(this: v1) )
      ((void (__thiscall *)(CRefCountServiceBase<1,CRefMT> *, int))v1->dtr_CRefCountServiceBase<1,CRefMT>)(
        a1: v1,
        a2: 1);
    return 0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10009D50
// Name: public: virtual void CMemberFunctor0<class CParallelProcessorBase<class CWorkerAccumState<class CThreadFastMutex>> __near *,void (CParallelProcessorBase<class CWorkerAccumState<class CThreadFastMutex>>::*)(void),class CRefCounted1<class CFunctor,class CRefCountServiceBase<1,class CRefMT>>,class CFuncMemPolicyNone>::operator()(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMemberFunctor0<CParallelProcessorBase<CWorkerAccumState<CThreadFastMutex>> *,void (__thiscall CParallelProcessorBase<CWorkerAccumState<CThreadFastMutex>>::*)(void),CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>,CFuncMemPolicyNone>::operator()(
        CMemberFunctor0<CParallelProcessorBase<CWorkerAccumState<CThreadFastMutex> > *,void (__thiscall CParallelProcessorBase<CWorkerAccumState<CThreadFastMutex> >::*)(void),CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT> >,CFuncMemPolicyNone> *this)
{
  this->m_Proxy.m_pfnProxied(this: this->m_Proxy.m_pObject);
}

//------------------------------------------------------------------------------
// Address: 0x10009D90
// Name: void Worker_GetLocalCopyOfBinary(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Worker_GetLocalCopyOfBinary(char *pFilename)
{
  _iobuf *v1; // eax
  _iobuf *v2; // esi
  _iobuf *v3; // eax
  int v4; // edi
  unsigned int v5; // ebx
  _iobuf *v6; // eax
  _iobuf *v7; // esi
  char *v8; // [esp-4h] [ebp-244h]
  char tmpFilename[260]; // [esp+8h] [ebp-238h] BYREF
  char newFilename[260]; // [esp+10Ch] [ebp-134h] BYREF
  CUtlBuffer fileBuf; // [esp+210h] [ebp-30h] BYREF

  CUtlBuffer::CUtlBuffer(this: &fileBuf, growSize: 0, initSize: 0, nFlags: 0);
  sprintf(string: tmpFilename, format: "%s\\%s", g_ExeDir, pFilename);
  if ( g_bVerbose )
    printf(format: "trying to open: %s\n", tmpFilename);
  v1 = fopen(file: (_iobuf *)tmpFilename, mode: "rb");
  v2 = v1;
  if ( v1 == nullptr )
  {
    v8 = pFilename;
    goto LABEL_5;
  }
  fseek(stream: v1, offset: 0, whence: 2u);
  v4 = ftell(stream: v2);
  fseek(stream: v2, offset: 0, whence: 0);
  CUtlBuffer::EnsureCapacity(this: &fileBuf, num: v4);
  v5 = fread(buffer: (char *)fileBuf.m_Memory.m_pMemory, elementSize: 1u, count: v4, stream: v2);
  fclose(stream: v2);
  CUtlBuffer::SeekPut(this: &fileBuf, type: SEEK_HEAD, offset: v5);
  sprintf(string: newFilename, format: "%s%s", g_WorkerTempPath, pFilename);
  v6 = fopen(file: (_iobuf *)newFilename, mode: "wb");
  v7 = v6;
  if ( v6 == nullptr )
  {
    v8 = newFilename;
LABEL_5:
    v3 = __iob_func();
    fprintf(str: v3 + 2, format: "Can't open %s!\n", v8);
    exit(code: -1);
  }
  fwrite(buffer: fileBuf.m_Memory.m_pMemory, size: 1u, count: v4, stream: v6);
  fclose(stream: v7);
  fopen(file: (_iobuf *)newFilename, mode: "r");
  if ( fileBuf.m_Memory.m_nGrowSize >= 0 && fileBuf.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: fileBuf.m_Memory.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x10009F10
// Name: void Shared_ParseListOfCompileCommands(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Shared_ParseListOfCompileCommands()
{
  _iobuf *v0; // eax
  CfgProcessor::CfgEntryInfo *m_p; // eax
  bool v2; // zf
  const char *v3; // eax
  char fileListFileName[1024]; // [esp+20h] [ebp-438h] BYREF
  CUtlInplaceBuffer bffr; // [esp+420h] [ebp-38h] BYREF
  double tt_start; // [esp+450h] [ebp-8h]

  tt_start = _Plat_FloatTime();
  memset(fileListFileName, 0, sizeof(fileListFileName));
  sprintf(string: fileListFileName, format: "%s\\filelist.txt", g_pShaderPath);
  CUtlInplaceBuffer::CUtlInplaceBuffer(this: &bffr, growSize: 0, initSize: 0, nFlags: 1);
  if ( !g_pFileSystem->ReadFile(
          this: g_pFileSystem,
          a2: fileListFileName,
          a3: nullptr,
          a4: &bffr,
          a5: 0,
          a6: 0,
          a7: nullptr) )
  {
    DebugOut(pMsg: "Can't open %s!\n", fileListFileName);
    v0 = __iob_func();
    fprintf(str: v0 + 2, format: "Can't open %s!\n", fileListFileName);
    exit(code: -1);
  }
  CfgProcessor::ReadConfiguration(fInputStream: &bffr);
  CfgProcessor::DescribeConfiguration(rarrEntries: &`anonymous namespace'::g_arrCompileEntries);
  m_p = `anonymous namespace'::g_arrCompileEntries.m_p;
  if ( `anonymous namespace'::g_arrCompileEntries.m_p != nullptr )
  {
    do
    {
      if ( m_p->m_szName == nullptr )
        break;
      ++`anonymous namespace'::g_numShaders;
      `anonymous namespace'::g_numStaticCombos += m_p->m_numStaticCombos;
      v2 = &m_p[1] == nullptr;
      ++m_p;
      `anonymous namespace'::g_numCompileCommands = m_p[-1].m_iCommandEnd;
    }
    while ( !v2 );
  }
  _Plat_FloatTime();
  v3 = PrettyPrintNumber(k: `anonymous namespace'::g_numCompileCommands);
  _Msg(a1: "\rCompiling %s commands.         \r", v3);
  if ( bffr.m_Memory.m_nGrowSize >= 0 && bffr.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: bffr.m_Memory.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x1000A070
// Name: public: void CUtlNodeHash<struct CStaticCombo,7097,unsigned __int64>::DeleteByKey(unsigned __int64)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlNodeHash<CStaticCombo,7097,unsigned __int64>::DeleteByKey(
        CUtlNodeHash<CStaticCombo,7097,unsigned __int64> *this,
        unsigned __int64 nMatchKey)
{
  CUtlIntrusiveDList<CStaticCombo> *v3; // ecx
  CStaticCombo *m_pHead; // eax

  v3 = &this->m_HashChains[(unsigned int)nMatchKey % 0x1BB9];
  m_pHead = v3->m_pHead;
  if ( v3->m_pHead != nullptr )
  {
    while ( m_pHead->m_nStaticComboID != nMatchKey )
    {
      m_pHead = m_pHead->m_pNext;
      if ( m_pHead == nullptr )
        return;
    }
    CUtlIntrusiveDList<CStaticCombo>::RemoveNode(this: v3, which: m_pHead);
    --this->m_nNumNodes;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000A2F0
// Name: OutputDynamicCombo
// Source: json
//------------------------------------------------------------------------------
void __usercall OutputDynamicCombo(
        CUtlBuffer *pDynamicComboBuffer@<eax>,
        MessageBuffer *pBuf@<edx>,
        int nComboSize@<edi>,
        unsigned int *pnTotalFlushedSize,
        unsigned __int64 nComboID,
        unsigned __int8 *pComboCode)
{
  if ( pDynamicComboBuffer->m_Put + nComboSize + 16 >= 0x20000 )
    FlushCombos(pDynamicComboBuffer, pnTotalFlushedSize, pBuf);
  if ( (pDynamicComboBuffer->m_Flags & 1) != 0 )
    CUtlBuffer::Printf(this: pDynamicComboBuffer, pFmt: "%d", (_DWORD)nComboID);
  else
    CUtlBuffer::PutTypeBin<int>(this: pDynamicComboBuffer, src: nComboID);
  if ( (pDynamicComboBuffer->m_Flags & 1) != 0 )
    CUtlBuffer::Printf(this: pDynamicComboBuffer, pFmt: "%d", nComboSize);
  else
    CUtlBuffer::PutTypeBin<int>(this: pDynamicComboBuffer, src: nComboSize);
  CUtlBuffer::Put(this: pDynamicComboBuffer, pMem: pComboCode, size: nComboSize);
}

//------------------------------------------------------------------------------
// Address: 0x1000A380
// Name: public: CDistributeShaderCompileMaster::~CDistributeShaderCompileMaster(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDistributeShaderCompileMaster::~CDistributeShaderCompileMaster(CDistributeShaderCompileMaster *this)
{
  void *m_hEvent; // [esp-4h] [ebp-Ch]

  m_hEvent = this->m_hEvent;
  this->__vftable = (CDistributeShaderCompileMaster_vtbl *)&CDistributeShaderCompileMaster::`vftable';
  this->m_bRunning = 0;
  SetEvent(hEvent: m_hEvent);
  WaitForSingleObject(hHandle: this->m_hThread, dwMilliseconds: 0xFFFFFFFF);
  CloseHandle(hObject: this->m_hThread);
  CloseHandle(hObject: this->m_hEvent);
  CUtlVector<CWorkerAccumState<CThreadNullMutex>::SubProcess *,CUtlMemory<CWorkerAccumState<CThreadNullMutex>::SubProcess *,int>>::~CUtlVector<CWorkerAccumState<CThreadNullMutex>::SubProcess *,CUtlMemory<CWorkerAccumState<CThreadNullMutex>::SubProcess *,int>>(this: (CUtlVector<CFileResponse,CUtlMemory<CFileResponse,int> > *)&this->m_arrShaderNamesToWrite);
}

//------------------------------------------------------------------------------
// Address: 0x1000A3D0
// Name: public: CWorkerAccumState<class CThreadFastMutex>::CWorkerAccumState<class CThreadFastMutex>(class CThreadFastMutex __near *)
// Source: json
//------------------------------------------------------------------------------
CWorkerAccumState<CThreadFastMutex> *__thiscall CWorkerAccumState<CThreadFastMutex>::CWorkerAccumState<CThreadFastMutex>(
        CWorkerAccumState<CThreadFastMutex> *this,
        CThreadFastMutex *pMutex)
{
  this->m_nActive.m_value = 0;
  _InterlockedExchange(&this->m_nActive.m_value, 0);
  this->m_pMutex = pMutex;
  GenericThreadLocals::CThreadLocalBase::CThreadLocalBase(this: &this->m_lpSubProcessInfo);
  this->m_arrSubProcessInfos.m_Memory.m_pMemory = nullptr;
  this->m_arrSubProcessInfos.m_Memory.m_nAllocationCount = 0;
  this->m_arrSubProcessInfos.m_Memory.m_nGrowSize = 0;
  this->m_arrSubProcessInfos.m_Size = 0;
  this->m_arrSubProcessInfos.m_pElements = nullptr;
  this->m_iFirstCommand = 0;
  this->m_iNextCommand = 0;
  this->m_iEndCommand = 0;
  this->m_iLastFinished = 0;
  this->m_hCombo = nullptr;
  this->m_fnOldDisconnectHandler = g_fnDisconnectHandler;
  this->m_autoRestoreDisconnectHandler.m_rVar = &g_fnDisconnectHandler;
  this->m_autoRestoreDisconnectHandler.m_valPop = g_fnDisconnectHandler;
  `CWorkerAccumState<CThreadFastMutex>::DisconnectState'::`2'::sb = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1000A450
// Name: public: CWorkerAccumState<class CThreadNullMutex>::CWorkerAccumState<class CThreadNullMutex>(class CThreadNullMutex __near *)
// Source: json
//------------------------------------------------------------------------------
CWorkerAccumState<CThreadNullMutex> *__thiscall CWorkerAccumState<CThreadNullMutex>::CWorkerAccumState<CThreadNullMutex>(
        CWorkerAccumState<CThreadNullMutex> *this,
        CThreadNullMutex *pMutex)
{
  this->m_nActive.m_value = 0;
  _InterlockedExchange(&this->m_nActive.m_value, 0);
  this->m_pMutex = pMutex;
  GenericThreadLocals::CThreadLocalBase::CThreadLocalBase(this: &this->m_lpSubProcessInfo);
  this->m_arrSubProcessInfos.m_Memory.m_pMemory = nullptr;
  this->m_arrSubProcessInfos.m_Memory.m_nAllocationCount = 0;
  this->m_arrSubProcessInfos.m_Memory.m_nGrowSize = 0;
  this->m_arrSubProcessInfos.m_Size = 0;
  this->m_arrSubProcessInfos.m_pElements = nullptr;
  this->m_iFirstCommand = 0;
  this->m_iNextCommand = 0;
  this->m_iEndCommand = 0;
  this->m_iLastFinished = 0;
  this->m_hCombo = nullptr;
  this->m_fnOldDisconnectHandler = g_fnDisconnectHandler;
  this->m_autoRestoreDisconnectHandler.m_rVar = &g_fnDisconnectHandler;
  this->m_autoRestoreDisconnectHandler.m_valPop = g_fnDisconnectHandler;
  `CWorkerAccumState<CThreadNullMutex>::DisconnectState'::`2'::sb = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1000A4D0
// Name: protected: void CWorkerAccumState<class CThreadFastMutex>::QuitSubs(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWorkerAccumState<CThreadFastMutex>::QuitSubs(CWorkerAccumState<CThreadFastMutex> *this)
{
  CWorkerAccumState<CThreadFastMutex> *v1; // edi
  int m_Size; // eax
  DWORD v3; // esi
  int m_nAllocationCount; // ebx
  void *(__thiscall *Alloc_2)(IMemAlloc *, unsigned int); // edx
  int v6; // ecx
  CWorkerAccumState<CThreadFastMutex>::SubProcess *v7; // eax
  char *v8; // eax
  DWORD v9; // edi
  void **m_pMemory; // ebx
  void **v11; // eax
  int i; // ebx
  CWorkerAccumState<CThreadFastMutex>::SubProcess *v13; // esi
  SubProcessKernelObjects *pCommObjs; // edi
  HANDLE CurrentProcess; // eax
  CUtlVector<void *,CUtlMemory<void *,int> > m_arrWait; // [esp+Ch] [ebp-2Ch] BYREF
  SubProcessKernelObjects_Memory shrmem; // [esp+20h] [ebp-18h] BYREF
  CWorkerAccumState<CThreadFastMutex>::SubProcess *pSp; // [esp+2Ch] [ebp-Ch]
  CWorkerAccumState<CThreadFastMutex> *v19; // [esp+30h] [ebp-8h]
  int k; // [esp+34h] [ebp-4h]

  v1 = this;
  m_Size = this->m_arrSubProcessInfos.m_Size;
  v3 = 0;
  m_nAllocationCount = 0;
  v19 = this;
  memset(&m_arrWait, 0, 16);
  if ( m_Size > 0 )
  {
    Alloc_2 = _g_pMemAlloc->Alloc_2;
    m_arrWait.m_Memory.m_nAllocationCount = m_Size;
    m_nAllocationCount = m_Size;
    m_arrWait.m_Memory.m_pMemory = (void **)Alloc_2(this: _g_pMemAlloc, a2: 4 * m_Size);
  }
  v6 = 0;
  m_arrWait.m_pElements = m_arrWait.m_Memory.m_pMemory;
  k = 0;
  if ( v1->m_arrSubProcessInfos.m_Size > 0 )
  {
    do
    {
      v7 = v1->m_arrSubProcessInfos.m_Memory.m_pMemory[v6];
      pSp = v7;
      if ( v7 != nullptr )
      {
        shrmem.m_pObjs = v7->pCommObjs;
        shrmem.m_pMemory = nullptr;
        shrmem.m_pLockData = nullptr;
        v8 = (char *)SubProcessKernelObjects_Memory::Lock(this: &shrmem);
        if ( v8 != nullptr )
        {
          strcpy(v8, "quit");
          SubProcessKernelObjects_Memory::Unlock(this: &shrmem);
        }
        v9 = v3;
        if ( (int)(v3 + 1) > m_nAllocationCount )
        {
          CUtlMemory<int,int>::Grow(this: (CUtlMemory<CTCPPacket *,int> *)&m_arrWait, num: v3 - m_nAllocationCount + 1);
          v3 = m_arrWait.m_Size;
        }
        m_pMemory = m_arrWait.m_Memory.m_pMemory;
        m_arrWait.m_Size = ++v3;
        m_arrWait.m_pElements = m_arrWait.m_Memory.m_pMemory;
        if ( (int)(v3 - v9 - 1) > 0 )
          _V_memmove(
            dest: &m_arrWait.m_Memory.m_pMemory[v9 + 1],
            src: &m_arrWait.m_Memory.m_pMemory[v9],
            count: 4 * (v3 - v9 - 1));
        v11 = &m_pMemory[v9];
        if ( v11 != nullptr )
          *v11 = pSp->pi.hProcess;
        SubProcessKernelObjects_Memory::Unlock(this: &shrmem);
        v1 = v19;
        m_nAllocationCount = m_arrWait.m_Memory.m_nAllocationCount;
        v6 = k;
      }
      k = ++v6;
    }
    while ( v6 < v1->m_arrSubProcessInfos.m_Size );
    if ( v3 != 0
      && WaitForMultipleObjects(
           nCount: v3,
           lpHandles: m_arrWait.m_Memory.m_pMemory,
           bWaitAll: true,
           dwMilliseconds: 0x7D0u) == 258 )
    {
      _Warning(a1: "Timed out while waiting for sub-processes to shut down!\n");
    }
  }
  for ( i = 0; i < v1->m_arrSubProcessInfos.m_Size; ++i )
  {
    v13 = v1->m_arrSubProcessInfos.m_Memory.m_pMemory[i];
    if ( v13 != nullptr )
    {
      CloseHandle(hObject: v13->pi.hThread);
      CloseHandle(hObject: v13->pi.hProcess);
      pCommObjs = v13->pCommObjs;
      if ( pCommObjs != nullptr )
      {
        SubProcessKernelObjects::~SubProcessKernelObjects(this: v13->pCommObjs);
        free(pMem: pCommObjs);
      }
      free(pMem: v13);
      v1 = v19;
    }
  }
  if ( `CWorkerAccumState<CThreadFastMutex>::DisconnectState'::`2'::sb != 0 )
  {
    _Msg(a1: "Master disconnected.\n ");
    DebugOut(pMsg: "Master disconnected.\n");
    CurrentProcess = GetCurrentProcess();
    TerminateProcess(hProcess: CurrentProcess, uExitCode: 1u);
  }
  if ( m_arrWait.m_Memory.m_nGrowSize >= 0 && m_arrWait.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_arrWait.m_Memory.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x1000A6B0
// Name: protected: void CWorkerAccumState<class CThreadNullMutex>::QuitSubs(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWorkerAccumState<CThreadNullMutex>::QuitSubs(CWorkerAccumState<CThreadNullMutex> *this)
{
  CWorkerAccumState<CThreadNullMutex> *v1; // edi
  int m_Size; // eax
  DWORD v3; // esi
  int m_nAllocationCount; // ebx
  void *(__thiscall *Alloc_2)(IMemAlloc *, unsigned int); // edx
  int v6; // ecx
  CWorkerAccumState<CThreadNullMutex>::SubProcess *v7; // eax
  char *v8; // eax
  DWORD v9; // edi
  void **m_pMemory; // ebx
  void **v11; // eax
  int i; // ebx
  CWorkerAccumState<CThreadNullMutex>::SubProcess *v13; // esi
  SubProcessKernelObjects *pCommObjs; // edi
  HANDLE CurrentProcess; // eax
  CUtlVector<void *,CUtlMemory<void *,int> > m_arrWait; // [esp+Ch] [ebp-2Ch] BYREF
  SubProcessKernelObjects_Memory shrmem; // [esp+20h] [ebp-18h] BYREF
  CWorkerAccumState<CThreadNullMutex>::SubProcess *pSp; // [esp+2Ch] [ebp-Ch]
  CWorkerAccumState<CThreadNullMutex> *v19; // [esp+30h] [ebp-8h]
  int k; // [esp+34h] [ebp-4h]

  v1 = this;
  m_Size = this->m_arrSubProcessInfos.m_Size;
  v3 = 0;
  m_nAllocationCount = 0;
  v19 = this;
  memset(&m_arrWait, 0, 16);
  if ( m_Size > 0 )
  {
    Alloc_2 = _g_pMemAlloc->Alloc_2;
    m_arrWait.m_Memory.m_nAllocationCount = m_Size;
    m_nAllocationCount = m_Size;
    m_arrWait.m_Memory.m_pMemory = (void **)Alloc_2(this: _g_pMemAlloc, a2: 4 * m_Size);
  }
  v6 = 0;
  m_arrWait.m_pElements = m_arrWait.m_Memory.m_pMemory;
  k = 0;
  if ( v1->m_arrSubProcessInfos.m_Size > 0 )
  {
    do
    {
      v7 = v1->m_arrSubProcessInfos.m_Memory.m_pMemory[v6];
      pSp = v7;
      if ( v7 != nullptr )
      {
        shrmem.m_pObjs = v7->pCommObjs;
        shrmem.m_pMemory = nullptr;
        shrmem.m_pLockData = nullptr;
        v8 = (char *)SubProcessKernelObjects_Memory::Lock(this: &shrmem);
        if ( v8 != nullptr )
        {
          strcpy(v8, "quit");
          SubProcessKernelObjects_Memory::Unlock(this: &shrmem);
        }
        v9 = v3;
        if ( (int)(v3 + 1) > m_nAllocationCount )
        {
          CUtlMemory<int,int>::Grow(this: (CUtlMemory<CTCPPacket *,int> *)&m_arrWait, num: v3 - m_nAllocationCount + 1);
          v3 = m_arrWait.m_Size;
        }
        m_pMemory = m_arrWait.m_Memory.m_pMemory;
        m_arrWait.m_Size = ++v3;
        m_arrWait.m_pElements = m_arrWait.m_Memory.m_pMemory;
        if ( (int)(v3 - v9 - 1) > 0 )
          _V_memmove(
            dest: &m_arrWait.m_Memory.m_pMemory[v9 + 1],
            src: &m_arrWait.m_Memory.m_pMemory[v9],
            count: 4 * (v3 - v9 - 1));
        v11 = &m_pMemory[v9];
        if ( v11 != nullptr )
          *v11 = pSp->pi.hProcess;
        SubProcessKernelObjects_Memory::Unlock(this: &shrmem);
        v1 = v19;
        m_nAllocationCount = m_arrWait.m_Memory.m_nAllocationCount;
        v6 = k;
      }
      k = ++v6;
    }
    while ( v6 < v1->m_arrSubProcessInfos.m_Size );
    if ( v3 != 0
      && WaitForMultipleObjects(
           nCount: v3,
           lpHandles: m_arrWait.m_Memory.m_pMemory,
           bWaitAll: true,
           dwMilliseconds: 0x7D0u) == 258 )
    {
      _Warning(a1: "Timed out while waiting for sub-processes to shut down!\n");
    }
  }
  for ( i = 0; i < v1->m_arrSubProcessInfos.m_Size; ++i )
  {
    v13 = v1->m_arrSubProcessInfos.m_Memory.m_pMemory[i];
    if ( v13 != nullptr )
    {
      CloseHandle(hObject: v13->pi.hThread);
      CloseHandle(hObject: v13->pi.hProcess);
      pCommObjs = v13->pCommObjs;
      if ( pCommObjs != nullptr )
      {
        SubProcessKernelObjects::~SubProcessKernelObjects(this: v13->pCommObjs);
        free(pMem: pCommObjs);
      }
      free(pMem: v13);
      v1 = v19;
    }
  }
  if ( `CWorkerAccumState<CThreadNullMutex>::DisconnectState'::`2'::sb != 0 )
  {
    _Msg(a1: "Master disconnected.\n ");
    DebugOut(pMsg: "Master disconnected.\n");
    CurrentProcess = GetCurrentProcess();
    TerminateProcess(hProcess: CurrentProcess, uExitCode: 1u);
  }
  if ( m_arrWait.m_Memory.m_nGrowSize >= 0 && m_arrWait.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_arrWait.m_Memory.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x1000A940
// Name: public: void CStaticCombo::AddDynamicCombo(unsigned __int64,void const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CStaticCombo::AddDynamicCombo(
        CStaticCombo *this,
        unsigned __int64 nComboID,
        unsigned __int8 *pComboData,
        unsigned int nCodeSize)
{
  _DWORD *v4; // esi
  unsigned int v5; // edi
  unsigned __int8 *v6; // eax
  CByteCodeBlock *v7; // ebx
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CByteCodeBlock **m_pMemory; // ecx
  int v11; // eax
  CByteCodeBlock **v12; // eax

  v4 = operator new(nSize: 0x20u);
  if ( v4 != nullptr )
  {
    v5 = nCodeSize;
    v6 = (unsigned __int8 *)operator new(nSize: nCodeSize);
    v4[7] = v6;
    *((_QWORD *)v4 + 2) = nComboID;
    v4[6] = v5;
    memcpy(dst: v6, src: pComboData, count: v5);
    CRC32_Init(pulCRC: &nCodeSize);
    CRC32_ProcessBuffer(pulCRC: &nCodeSize, pBuffer: pComboData, nBuffer: v5);
    CRC32_Final(pulCRC: &nCodeSize);
    v4[2] = nCodeSize;
    v7 = (CByteCodeBlock *)v4;
  }
  else
  {
    v7 = nullptr;
  }
  m_Size = this->m_DynamicCombos.m_Size;
  m_nAllocationCount = this->m_DynamicCombos.m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<int,int>::Grow(
      this: (CUtlMemory<CTCPPacket *,int> *)&this->m_DynamicCombos,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_DynamicCombos.m_Size;
  m_pMemory = this->m_DynamicCombos.m_Memory.m_pMemory;
  v11 = this->m_DynamicCombos.m_Size - m_Size - 1;
  this->m_DynamicCombos.m_pElements = m_pMemory;
  if ( v11 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v11);
  v12 = &this->m_DynamicCombos.m_Memory.m_pMemory[m_Size];
  if ( v12 != nullptr )
    *v12 = v7;
}

//------------------------------------------------------------------------------
// Address: 0x1000AA10
// Name: protected: void Worker_ProcessCommandRange_Singleton::Startup(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall Worker_ProcessCommandRange_Singleton::Startup(Worker_ProcessCommandRange_Singleton *this)
{
  int CPUInformation; // edi
  int v3; // eax
  IThreadPool *v4; // ecx
  CWorkerAccumState<CThreadFastMutex> *v5; // eax
  CWorkerAccumState<CThreadNullMutex> *v6; // eax

  CPUInformation = _GetCPUInformation();
  if ( *(_BYTE *)(CPUInformation + 5) > 1u )
  {
    v3 = _CommandLine();
    v4 = (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v3 + 40))(a1: v3, a2: "-singlethreaded") != 0
       ? nullptr
       : _g_pThreadPool;
    this->m_MT.pThreadPool = v4;
    if ( v4 != nullptr )
    {
      *((_BYTE *)&this->m_MT.tpsp + 272) &= ~1u;
      this->m_MT.tpsp.nThreads = *(unsigned __int8 *)(CPUInformation + 5) - 1;
      if ( v4->Start_2(this: v4, a2: &this->m_MT.tpsp) )
      {
        if ( this->m_MT.pThreadPool->NumThreads(this: this->m_MT.pThreadPool) >= 1 )
        {
          _InterlockedExchange(
            (volatile __int32 *)&Threading::g_mtxGlobal.m_pUseMtx,
            (__int32)Threading::g_mtxGlobal.m_pMtx);
          v5 = (CWorkerAccumState<CThreadFastMutex> *)operator new(nSize: 0x50u);
          if ( v5 != nullptr )
            this->m_MT.pWorkerObj = CWorkerAccumState<CThreadFastMutex>::CWorkerAccumState<CThreadFastMutex>(
                                      this: v5,
                                      pMutex: &this->m_MT.mtx);
          else
            this->m_MT.pWorkerObj = nullptr;
          return;
        }
        this->m_MT.pThreadPool->Stop(this: this->m_MT.pThreadPool, a2: -1);
      }
      this->m_MT.pThreadPool = nullptr;
    }
  }
  v6 = (CWorkerAccumState<CThreadNullMutex> *)operator new(nSize: 0x50u);
  if ( v6 != nullptr )
    this->m_ST.pWorkerObj = CWorkerAccumState<CThreadNullMutex>::CWorkerAccumState<CThreadNullMutex>(
                              this: v6,
                              pMutex: &this->m_ST.mtx);
  else
    this->m_ST.pWorkerObj = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1000AB00
// Name: void Worker_GetLocalCopyOfShaders(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Worker_GetLocalCopyOfShaders()
{
  _iobuf *v0; // eax
  char *i; // esi
  unsigned __int8 *v2; // eax
  IMemAlloc *v3; // ecx
  unsigned int v4; // eax
  unsigned int v5; // edi
  unsigned int v6; // eax
  int v7; // eax
  _iobuf *v8; // eax
  _iobuf *v9; // edi
  _iobuf *v10; // edi
  int m_Size; // eax
  int v12; // esi
  _iobuf **m_pMemory; // ecx
  int v14; // eax
  _iobuf **v15; // eax
  char filename[1024]; // [esp+4h] [ebp-564h] BYREF
  char justFilename[260]; // [esp+404h] [ebp-164h] BYREF
  CUtlInplaceBuffer bffr; // [esp+508h] [ebp-60h] BYREF
  CUtlBuffer fileBuf; // [esp+538h] [ebp-30h] BYREF

  sprintf(string: filename, format: "%s\\uniquefilestocopy.txt", g_pShaderPath);
  CUtlInplaceBuffer::CUtlInplaceBuffer(this: &bffr, growSize: 0, initSize: 0, nFlags: 1);
  if ( !g_pFileSystem->ReadFile(this: g_pFileSystem, a2: filename, a3: nullptr, a4: &bffr, a5: 0, a6: 0, a7: nullptr) )
  {
    v0 = __iob_func();
    fprintf(str: v0 + 2, format: "Can't open uniquefilestocopy.txt!\n");
    exit(code: -1);
  }
  for ( i = CUtlInplaceBuffer::InplaceGetLinePtr(this: &bffr);
        i != nullptr;
        i = CUtlInplaceBuffer::InplaceGetLinePtr(this: &bffr) )
  {
    sprintf(string: filename, format: "%s\\%s", g_pShaderPath, i);
    if ( g_bVerbose )
      printf(format: "getting local copy of shader: \"%s\" (\"%s\")\n", i, filename);
    CUtlBuffer::CUtlBuffer(this: &fileBuf, growSize: 0, initSize: 0, nFlags: 0);
    if ( g_pFileSystem->ReadFile(
           this: g_pFileSystem,
           a2: filename,
           a3: nullptr,
           a4: &fileBuf,
           a5: 0,
           a6: 0,
           a7: nullptr) )
    {
      strrchr(string: (unsigned __int8 *)i, chr: 0x2Fu);
      v5 = v4;
      strrchr(string: (unsigned __int8 *)i, chr: 0x5Cu);
      if ( v5 <= v6 )
        strrchr(string: (unsigned __int8 *)i, chr: 0x5Cu);
      else
        strrchr(string: (unsigned __int8 *)i, chr: 0x2Fu);
      if ( v7 != 0 )
        V_strncpy(pDest: justFilename, pSrc: (const char *)(v7 + 1), maxLen: 260);
      else
        V_strncpy(pDest: justFilename, pSrc: i, maxLen: 260);
      sprintf(string: filename, format: "%s%s", g_WorkerTempPath, justFilename);
      if ( g_bVerbose )
        printf(format: "creating \"%s\"\n", filename);
      v8 = fopen(file: (_iobuf *)filename, mode: "wb");
      v9 = v8;
      if ( v8 != nullptr )
      {
        fwrite(buffer: fileBuf.m_Memory.m_pMemory, size: 1u, count: fileBuf.m_nMaxPut - fileBuf.m_Get, stream: v8);
        fclose(stream: v9);
        if ( (_S2_1 & 1) == 0 )
        {
          _S2_1 |= 1u;
          s_arrHackedFiles.m_Memory.m_pMemory = nullptr;
          s_arrHackedFiles.m_Memory.m_nAllocationCount = 0;
          s_arrHackedFiles.m_Memory.m_nGrowSize = 0;
          s_arrHackedFiles.m_Size = 0;
          s_arrHackedFiles.m_pElements = nullptr;
          atexit(func: Worker_GetLocalCopyOfShaders_::_20_::_dynamic_atexit_destructor_for__s_arrHackedFiles__);
        }
        if ( (_S2_1 & 2) == 0 )
        {
          _S2_1 |= 2u;
          atexit(func: Worker_GetLocalCopyOfShaders_::_21_::_dynamic_atexit_destructor_for__s_autoCloseHackedFiles__);
        }
        v10 = fopen(file: (_iobuf *)filename, mode: "r");
        m_Size = s_arrHackedFiles.m_Size;
        v12 = s_arrHackedFiles.m_Size;
        if ( s_arrHackedFiles.m_Size + 1 > s_arrHackedFiles.m_Memory.m_nAllocationCount )
        {
          CUtlMemory<int,int>::Grow(
            this: (CUtlMemory<CTCPPacket *,int> *)&s_arrHackedFiles,
            num: s_arrHackedFiles.m_Size - s_arrHackedFiles.m_Memory.m_nAllocationCount + 1);
          m_Size = s_arrHackedFiles.m_Size;
        }
        m_pMemory = s_arrHackedFiles.m_Memory.m_pMemory;
        s_arrHackedFiles.m_Size = m_Size + 1;
        v14 = m_Size - v12;
        s_arrHackedFiles.m_pElements = s_arrHackedFiles.m_Memory.m_pMemory;
        if ( v14 > 0 )
        {
          _V_memmove(
            dest: &s_arrHackedFiles.m_Memory.m_pMemory[v12 + 1],
            src: &s_arrHackedFiles.m_Memory.m_pMemory[v12],
            count: 4 * v14);
          m_pMemory = s_arrHackedFiles.m_Memory.m_pMemory;
        }
        v15 = &m_pMemory[v12];
        if ( v15 != nullptr )
          *v15 = v10;
      }
      else
      {
        _Error(a1: "Can't open '%s' for writing.", i);
      }
      if ( fileBuf.m_Memory.m_nGrowSize < 0 )
        continue;
      v2 = fileBuf.m_Memory.m_pMemory;
      if ( fileBuf.m_Memory.m_pMemory == nullptr )
        continue;
      v3 = _g_pMemAlloc;
    }
    else
    {
      _Warning(a1: "Can't find \"%s\"\n", filename);
      if ( fileBuf.m_Memory.m_nGrowSize < 0 )
        continue;
      v2 = fileBuf.m_Memory.m_pMemory;
      if ( fileBuf.m_Memory.m_pMemory == nullptr )
        continue;
      v3 = _g_pMemAlloc;
    }
    v3->Free_2(this: v3, a2: v2);
  }
  if ( bffr.m_Memory.m_nGrowSize >= 0 && bffr.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: bffr.m_Memory.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x1000AE20
// Name: public: virtual void CDistributeShaderCompileMaster::OnWorkUnitsCompleted(unsigned __int64)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDistributeShaderCompileMaster::OnWorkUnitsCompleted(
        CDistributeShaderCompileMaster *this,
        unsigned __int64 numWorkUnits)
{
  CDistributeShaderCompileMaster *v2; // edi
  CfgProcessor::CfgEntryInfo *m_p; // esi
  unsigned __int64 i; // kr00_8
  unsigned int m_numStaticCombos_high; // ecx
  unsigned int m_numStaticCombos; // edx
  unsigned __int64 v7; // rax
  CThreadFastMutex *p_m_mtx; // ebx
  DWORD CurrentThreadId; // ecx
  const CfgProcessor::CfgEntryInfo *m_pAnalyzeShaders; // eax
  CUtlMemory<CTCPPacket *,int> *p_m_arrShaderNamesToWrite; // esi
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CTCPPacket **m_pMemory; // ecx
  int v15; // eax
  CTCPPacket **v16; // edi
  const CfgProcessor::CfgEntryInfo *numWorkUnits_4; // [esp+1Ch] [ebp+Ch]

  v2 = this;
  _InterlockedExchange((volatile __int32 *)&Threading::g_mtxGlobal.m_pUseMtx, (__int32)Threading::g_mtxGlobal.m_pMtx);
  m_p = `anonymous namespace'::g_arrCompileEntries.m_p;
  `anonymous namespace'::g_numCompletedStaticCombos = `anonymous namespace'::g_nStaticCombosPerWorkUnit * numWorkUnits;
  for ( i = `anonymous namespace'::g_nStaticCombosPerWorkUnit * numWorkUnits; m_p != nullptr; ++m_p )
  {
    if ( m_p->m_szName == nullptr )
      break;
    m_numStaticCombos_high = HIDWORD(m_p->m_numStaticCombos);
    m_numStaticCombos = m_p->m_numStaticCombos;
    if ( i < __PAIR64__(m_numStaticCombos_high, m_numStaticCombos) )
      break;
    i -= __PAIR64__(m_numStaticCombos_high, m_numStaticCombos);
  }
  v7 = m_p->m_iCommandStart + m_p->m_numDynamicCombos * i;
  `anonymous namespace'::g_numCommandsCompleted = v7;
  if ( v2->m_pAnalyzeShaders->m_szName != nullptr )
  {
    while ( v2->m_pAnalyzeShaders->m_iCommandEnd <= __PAIR64__(
                                                      HIDWORD(v7),
                                                      `anonymous namespace'::g_numCommandsCompleted) )
    {
      p_m_mtx = &v2->m_mtx;
      CurrentThreadId = GetCurrentThreadId();
      if ( CurrentThreadId != v2->m_mtx.m_ownerID
        && _InterlockedCompareExchange((volatile signed __int32 *)p_m_mtx, CurrentThreadId, 0) != 0 )
      {
        _mm_pause();
        CThreadFastMutex::Lock(a1: &v2->m_mtx, a2: CurrentThreadId, a3: 0);
      }
      else
      {
        ++v2->m_mtx.m_depth;
      }
      m_pAnalyzeShaders = v2->m_pAnalyzeShaders;
      p_m_arrShaderNamesToWrite = (CUtlMemory<CTCPPacket *,int> *)&v2->m_arrShaderNamesToWrite;
      m_Size = v2->m_arrShaderNamesToWrite.m_Size;
      numWorkUnits_4 = m_pAnalyzeShaders;
      m_nAllocationCount = p_m_arrShaderNamesToWrite->m_nAllocationCount;
      if ( m_Size + 1 > m_nAllocationCount )
        CUtlMemory<int,int>::Grow(this: p_m_arrShaderNamesToWrite, num: m_Size - m_nAllocationCount + 1);
      ++p_m_arrShaderNamesToWrite[1].m_pMemory;
      m_pMemory = p_m_arrShaderNamesToWrite->m_pMemory;
      v15 = (int)p_m_arrShaderNamesToWrite[1].m_pMemory - m_Size - 1;
      p_m_arrShaderNamesToWrite[1].m_nAllocationCount = (int)p_m_arrShaderNamesToWrite->m_pMemory;
      if ( v15 > 0 )
        _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v15);
      v16 = &p_m_arrShaderNamesToWrite->m_pMemory[m_Size];
      if ( v16 != nullptr )
        *v16 = (CTCPPacket *)numWorkUnits_4->m_szName;
      SetEvent(hEvent: this->m_hEvent);
      if ( p_m_mtx->m_depth-- == 1 )
        _InterlockedExchange((volatile __int32 *)p_m_mtx, 0);
      ++this->m_pAnalyzeShaders;
      if ( this->m_pAnalyzeShaders->m_szName == nullptr )
        break;
      HIDWORD(v7) = HIDWORD(`anonymous namespace'::g_numCommandsCompleted);
      v2 = this;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000B010
// Name: protected: void CWorkerAccumState<class CThreadFastMutex>::PrepareSubProcess(struct CWorkerAccumState<class CThreadFastMutex>::SubProcess __near * __near *,class SubProcessKernelObjects __near * __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWorkerAccumState<CThreadFastMutex>::PrepareSubProcess(
        CWorkerAccumState<CThreadFastMutex> *this,
        CWorkerAccumState<CThreadFastMutex>::SubProcess **ppSp,
        SubProcessKernelObjects **ppCommObjs)
{
  GenericThreadLocals::CThreadLocal<CWorkerAccumState<CThreadFastMutex>::SubProcess *> *p_m_lpSubProcessInfo; // esi
  CWorkerAccumState<CThreadFastMutex>::SubProcess *v4; // edi
  __int64 v5; // kr00_8
  SubProcessKernelObjects *v6; // eax
  SubProcessKernelObjects *v7; // esi
  int m_nAllocationCount; // esi
  DWORD CurrentThreadId; // eax
  CUtlMemory<CTCPPacket *,int> *v10; // esi
  signed int m_pMemory; // ebx
  int v12; // eax
  CTCPPacket **v13; // ecx
  int v14; // eax
  CWorkerAccumState<CThreadFastMutex>::SubProcess **v15; // eax
  int v16; // eax
  char chCommandLine[256]; // [esp+8h] [ebp-180h] BYREF
  _STARTUPINFOA StartupInfo; // [esp+108h] [ebp-80h] BYREF
  char chBaseNameBuffer[52]; // [esp+14Ch] [ebp-3Ch] BYREF
  SubProcessKernelObjects *pCommObjs; // [esp+180h] [ebp-8h]
  CUtlMemory<CTCPPacket *,int> *v22; // [esp+184h] [ebp-4h]

  p_m_lpSubProcessInfo = &this->m_lpSubProcessInfo;
  v22 = (CUtlMemory<CTCPPacket *,int> *)this;
  v4 = (CWorkerAccumState<CThreadFastMutex>::SubProcess *)GenericThreadLocals::CThreadLocalBase::Get(this: &this->m_lpSubProcessInfo);
  if ( v4 != nullptr )
  {
    pCommObjs = v4->pCommObjs;
  }
  else
  {
    v4 = (CWorkerAccumState<CThreadFastMutex>::SubProcess *)operator new(nSize: 0x28u);
    GenericThreadLocals::CThreadLocalBase::Set(this: p_m_lpSubProcessInfo, a2: v4);
    v4->dwSvcThreadId = GetCurrentThreadId();
    v5 = _time64(timeptr: nullptr);
    pCommObjs = (SubProcessKernelObjects *)HIDWORD(v5);
    GetCurrentProcessId();
    sprintf(string: chBaseNameBuffer, format: "SHCMPL_SUB_%08X_%08X_%08X", v4->dwSvcThreadId, (_DWORD)v5, HIDWORD(v5));
    v6 = (SubProcessKernelObjects *)operator new(nSize: 0x14u);
    v7 = v6;
    if ( v6 != nullptr )
    {
      SubProcessKernelObjects::SubProcessKernelObjects(this: v6);
      SubProcessKernelObjects::Create(this: v7, szBaseName: chBaseNameBuffer);
      v7->m_dwCookie = 1;
    }
    else
    {
      v7 = nullptr;
    }
    v4->pCommObjs = v7;
    pCommObjs = v7;
    *(_QWORD *)&v4->pi.hProcess = 0;
    *(_QWORD *)&v4->pi.dwProcessId = 0;
    memset(dst: (int)&StartupInfo, value: nullptr, count: sizeof(StartupInfo));
    StartupInfo.cb = 68;
    sprintf(
      string: chCommandLine,
      format: "\"%s\\shadercompile.exe\" -subprocess %s",
      g_WorkerTempPath,
      chBaseNameBuffer);
    CreateProcessA(
      lpApplicationName: nullptr,
      lpCommandLine: chCommandLine,
      lpProcessAttributes: nullptr,
      lpThreadAttributes: nullptr,
      bInheritHandles: false,
      dwCreationFlags: 0x8000000u,
      lpEnvironment: nullptr,
      lpCurrentDirectory: g_WorkerTempPath,
      lpStartupInfo: &StartupInfo,
      lpProcessInformation: &v4->pi);
    m_nAllocationCount = v22->m_nAllocationCount;
    CurrentThreadId = GetCurrentThreadId();
    if ( CurrentThreadId != *(_DWORD *)m_nAllocationCount
      && _InterlockedCompareExchange((volatile signed __int32 *)m_nAllocationCount, CurrentThreadId, 0) != 0 )
    {
      _mm_pause();
      CThreadFastMutex::Lock(a1: m_nAllocationCount, a2: CurrentThreadId, a3: 0);
    }
    else
    {
      ++*(_DWORD *)(m_nAllocationCount + 4);
    }
    v10 = v22;
    m_pMemory = (signed int)v22[2].m_pMemory;
    v12 = v22[1].m_nAllocationCount;
    if ( m_pMemory + 1 > v12 )
      CUtlMemory<int,int>::Grow(this: v22 + 1, num: m_pMemory - v12 + 1);
    ++v10[2].m_pMemory;
    v13 = v10[1].m_pMemory;
    v14 = (int)v10[2].m_pMemory - m_pMemory - 1;
    v10[2].m_nAllocationCount = (int)v13;
    if ( v14 > 0 )
      _V_memmove(dest: &v13[m_pMemory + 1], src: &v13[m_pMemory], count: 4 * v14);
    v15 = (CWorkerAccumState<CThreadFastMutex>::SubProcess **)&v10[1].m_pMemory[m_pMemory];
    if ( v15 != nullptr )
      *v15 = v4;
    v4->dwIndex = m_pMemory;
    v16 = v10->m_nAllocationCount;
    if ( (*(_DWORD *)(v16 + 4))-- == 1 )
      _InterlockedExchange((volatile __int32 *)v16, 0);
  }
  if ( ppSp != nullptr )
    *ppSp = v4;
  if ( ppCommObjs != nullptr )
    *ppCommObjs = pCommObjs;
}

//------------------------------------------------------------------------------
// Address: 0x1000B1E0
// Name: public: Worker_ProcessCommandRange_Singleton::Worker_ProcessCommandRange_Singleton(void)
// Source: json
//------------------------------------------------------------------------------
Worker_ProcessCommandRange_Singleton *__thiscall Worker_ProcessCommandRange_Singleton::Worker_ProcessCommandRange_Singleton(
        Worker_ProcessCommandRange_Singleton *this)
{
  bool v2; // zf
  unsigned int i; // eax

  this->m_MT.mtx.m_ownerID = 0;
  this->m_MT.mtx.m_depth = 0;
  this->m_MT.pWorkerObj = nullptr;
  this->m_MT.pThreadPool = nullptr;
  *((_BYTE *)&this->m_MT.tpsp + 272) &= 0xFCu;
  v2 = (*((_BYTE *)&this->m_MT.tpsp + 272) & 2) == 0;
  this->m_MT.tpsp.nThreads = -1;
  this->m_MT.tpsp.fDistribute = TRS_NONE;
  this->m_MT.tpsp.nStackSize = -1;
  this->m_MT.tpsp.iThreadPriority = -32768;
  if ( !v2 )
  {
    for ( i = 0; i < 64; ++i )
      this->m_MT.tpsp.iAffinityTable[i] = *(_DWORD *)(i * 4);
  }
  this->m_ST.pWorkerObj = nullptr;
  `Worker_ProcessCommandRange_Singleton::Instance'::`2'::s_ptr = this;
  Worker_ProcessCommandRange_Singleton::Startup(this);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1000B250
// Name: public: void CUtlNodeHash<struct CStaticCombo,7097,unsigned __int64>::Purge(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlNodeHash<CStaticCombo,7097,unsigned __int64>::Purge(
        CUtlNodeHash<CStaticCombo,7097,unsigned __int64> *this)
{
  CUtlIntrusiveDList<CStaticCombo> *m_HashChains; // eax
  CStaticCombo *m_pHead; // edi
  CByteCodeBlock **m_pMemory; // eax
  bool v4; // zf
  unsigned __int8 *v5; // [esp-8h] [ebp-20h]
  unsigned __int8 *m_p; // [esp-4h] [ebp-1Ch]
  CStaticCombo *m_pNext; // [esp+Ch] [ebp-Ch]
  int v8; // [esp+10h] [ebp-8h]
  CUtlIntrusiveDList<CStaticCombo> *v9; // [esp+14h] [ebp-4h]

  m_HashChains = this->m_HashChains;
  this->m_nNumNodes = 0;
  v9 = this->m_HashChains;
  v8 = 7097;
  do
  {
    if ( m_HashChains->m_pHead != nullptr )
    {
      do
      {
        m_pHead = m_HashChains->m_pHead;
        m_pNext = m_HashChains->m_pHead->m_pNext;
        if ( m_HashChains->m_pHead != nullptr )
        {
          CUtlVector<CByteCodeBlock *,CUtlMemory<CByteCodeBlock *,int>>::PurgeAndDeleteElements(this: &m_pHead->m_DynamicCombos);
          m_p = m_pHead->m_abPackedCode.m_p;
          m_pHead->m_abPackedCode.m_p = nullptr;
          free(pMem: m_p);
          v5 = m_pHead->m_abPackedCode.m_p;
          m_pHead->m_abPackedCode.m_p = nullptr;
          free(pMem: v5);
          m_pHead->m_DynamicCombos.m_Size = 0;
          if ( m_pHead->m_DynamicCombos.m_Memory.m_nGrowSize >= 0 )
          {
            if ( m_pHead->m_DynamicCombos.m_Memory.m_pMemory != nullptr )
            {
              _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pHead->m_DynamicCombos.m_Memory.m_pMemory);
              m_pHead->m_DynamicCombos.m_Memory.m_pMemory = nullptr;
            }
            m_pHead->m_DynamicCombos.m_Memory.m_nAllocationCount = 0;
          }
          m_pMemory = m_pHead->m_DynamicCombos.m_Memory.m_pMemory;
          m_pHead->m_DynamicCombos.m_pElements = m_pMemory;
          if ( m_pHead->m_DynamicCombos.m_Memory.m_nGrowSize >= 0 )
          {
            if ( m_pMemory != nullptr )
            {
              _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
              m_pHead->m_DynamicCombos.m_Memory.m_pMemory = nullptr;
            }
            m_pHead->m_DynamicCombos.m_Memory.m_nAllocationCount = 0;
          }
          free(pMem: m_pHead);
          m_HashChains = v9;
        }
        m_HashChains->m_pHead = m_pNext;
      }
      while ( m_pNext != nullptr );
    }
    ++m_HashChains;
    v4 = v8-- == 1;
    v9 = m_HashChains;
  }
  while ( !v4 );
}

//------------------------------------------------------------------------------
// Address: 0x1000B3C0
// Name: struct CStaticCombo __near * StaticComboFromDictAdd(char const __near *,unsigned __int64)
// Source: json
//------------------------------------------------------------------------------
CStaticCombo *__cdecl StaticComboFromDictAdd(const char *pszShaderName, unsigned __int64 nStaticComboId)
{
  int m_Id; // esi
  CUtlNodeHash<CStaticCombo,7097,unsigned __int64> **v3; // ebx
  CUtlNodeHash<CStaticCombo,7097,unsigned __int64> *v4; // edx
  CStaticCombo *result; // eax
  _DWORD *v6; // eax
  _DWORD *v7; // esi
  CUtlNodeHash<CStaticCombo,7097,unsigned __int64> *v8; // edi
  unsigned int v9; // eax
  CUtlSymbol v10; // [esp+Ch] [ebp-4h] BYREF

  CUtlSymbolTable::AddString(this: &g_ShaderByteCode.m_SymbolTable, result: &v10, pString: pszShaderName);
  m_Id = v10.m_Id;
  if ( g_ShaderByteCode.m_Vector.m_Size <= v10.m_Id && g_ShaderByteCode.m_Vector.m_Size < v10.m_Id + 1 )
    CUtlVector<CUtlNodeHash<CStaticCombo,7097,unsigned __int64> *,CUtlMemory<CUtlNodeHash<CStaticCombo,7097,unsigned __int64> *,int>>::InsertMultipleBefore(
      this: &g_ShaderByteCode.m_Vector,
      elem: g_ShaderByteCode.m_Vector.m_Size,
      num: v10.m_Id + 1 - g_ShaderByteCode.m_Vector.m_Size);
  v3 = &g_ShaderByteCode.m_Vector.m_Memory.m_pMemory[m_Id];
  if ( *v3 == nullptr )
  {
    v4 = (CUtlNodeHash<CStaticCombo,7097,unsigned __int64> *)operator new(nSize: 0x6EE8u);
    if ( v4 != nullptr )
    {
      memset(v4->m_HashChains, 0, sizeof(v4->m_HashChains));
      v4->m_nNumNodes = 0;
    }
    else
    {
      v4 = nullptr;
    }
    *v3 = v4;
  }
  result = (*v3)->m_HashChains[(unsigned int)nStaticComboId % 0x1BB9].m_pHead;
  if ( result != nullptr )
  {
    while ( result->m_nStaticComboID != nStaticComboId )
    {
      result = result->m_pNext;
      if ( result == nullptr )
        goto LABEL_12;
    }
  }
  else
  {
LABEL_12:
    v6 = operator new(nSize: 0x28u);
    if ( v6 != nullptr )
    {
      v6[4] = 0;
      v6[5] = 0;
      v6[6] = 0;
      v6[7] = 0;
      v6[8] = 0;
      v6[9] = 0;
      *((_QWORD *)v6 + 1) = nStaticComboId;
      v7 = v6;
    }
    else
    {
      v7 = nullptr;
    }
    v8 = *v3;
    v9 = (unsigned int)&(*v3)->m_HashChains[v7[2] % 0x1BB9u];
    *v7 = *(_DWORD *)v9;
    if ( *(_DWORD *)v9 != 0 )
      *(_DWORD *)(*(_DWORD *)v9 + 4) = v7;
    v7[1] = 0;
    *(_DWORD *)v9 = v7;
    ++v8->m_nNumNodes;
    return (CStaticCombo *)v7;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1000B4F0
// Name: struct CStaticCombo __near * StaticComboFromDict(char const __near *,unsigned __int64)
// Source: json
//------------------------------------------------------------------------------
CStaticCombo *__cdecl StaticComboFromDict(const char *pszShaderName, unsigned __int64 nStaticComboId)
{
  int m_Id; // esi
  CUtlNodeHash<CStaticCombo,7097,unsigned __int64> *v3; // esi
  CStaticCombo *result; // eax
  CUtlSymbol v5; // [esp+4h] [ebp-4h] BYREF

  CUtlSymbolTable::AddString(this: &g_ShaderByteCode.m_SymbolTable, result: &v5, pString: pszShaderName);
  m_Id = v5.m_Id;
  if ( g_ShaderByteCode.m_Vector.m_Size <= v5.m_Id && g_ShaderByteCode.m_Vector.m_Size < v5.m_Id + 1 )
    CUtlVector<CUtlNodeHash<CStaticCombo,7097,unsigned __int64> *,CUtlMemory<CUtlNodeHash<CStaticCombo,7097,unsigned __int64> *,int>>::InsertMultipleBefore(
      this: &g_ShaderByteCode.m_Vector,
      elem: g_ShaderByteCode.m_Vector.m_Size,
      num: v5.m_Id + 1 - g_ShaderByteCode.m_Vector.m_Size);
  v3 = g_ShaderByteCode.m_Vector.m_Memory.m_pMemory[m_Id];
  if ( v3 == nullptr )
    return nullptr;
  result = v3->m_HashChains[(unsigned int)nStaticComboId % 0x1BB9].m_pHead;
  if ( result == nullptr )
    return nullptr;
  while ( result->m_nStaticComboID != nStaticComboId )
  {
    result = result->m_pNext;
    if ( result == nullptr )
      return nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1000B580
// Name: bool ShaderHadErrorDispatch(class MessageBuffer __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
char __cdecl ShaderHadErrorDispatch(MessageBuffer *pBuf)
{
  int m_Id; // esi
  CUtlSymbol v3; // [esp+0h] [ebp-4h] BYREF

  if ( Threading::g_mtxGlobal.m_pUseMtx.m_value != nullptr )
    EnterCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)Threading::g_mtxGlobal.m_pUseMtx.m_value);
  CUtlSymbolTable::AddString(
    this: &g_Master_ShaderHadError.m_SymbolTable,
    result: &v3,
    pString: (const char *)pBuf->data + 1);
  m_Id = v3.m_Id;
  if ( g_Master_ShaderHadError.m_Vector.m_Size <= v3.m_Id )
    CUtlVector<bool,CUtlMemory<bool,int>>::EnsureCount(this: &g_Master_ShaderHadError.m_Vector, num: v3.m_Id + 1);
  g_Master_ShaderHadError.m_Vector.m_Memory.m_pMemory[m_Id] = true;
  if ( Threading::g_mtxGlobal.m_pUseMtx.m_value != nullptr )
    LeaveCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)Threading::g_mtxGlobal.m_pUseMtx.m_value);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1000B5F0
// Name: void Master_ReceiveWorkUnitFn(unsigned __int64,class MessageBuffer __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Master_ReceiveWorkUnitFn(unsigned __int64 iWorkUnit, MessageBuffer *pBuf)
{
  unsigned int v2; // edi
  CfgProcessor::CfgEntryInfo *m_p; // eax
  unsigned __int64 i; // kr08_8
  unsigned int m_numStaticCombos_high; // esi
  unsigned int m_numStaticCombos; // ebx
  int v7; // esi
  __int64 v8; // kr10_8
  unsigned int v9; // ebx
  unsigned int v10; // ecx
  int v11; // ecx
  const char *v12; // ecx
  __int64 v13; // rax
  unsigned int v14; // ebx
  int v15; // ecx
  const char *m_szName; // edi
  int m_Id; // edi
  CStaticCombo *v18; // edi
  unsigned __int8 *v19; // eax
  const char *v20; // ecx
  unsigned __int8 *v21; // edi
  unsigned int v22; // eax
  bool v23; // cf
  int v24; // ecx
  unsigned int v25; // ebx
  int v26; // eax
  unsigned __int8 *v27; // [esp-1Ch] [ebp-84h]
  ShaderInfo_t siLastShaderInfo; // [esp+0h] [ebp-68h] BYREF
  unsigned __int64 nComboOfTheEntry; // [esp+40h] [ebp-28h]
  unsigned __int64 comboEnd; // [esp+48h] [ebp-20h]
  unsigned __int64 iCombo; // [esp+50h] [ebp-18h]
  const char *chShaderName; // [esp+58h] [ebp-10h]
  const char *chLastShaderName; // [esp+5Ch] [ebp-Ch]
  int len; // [esp+60h] [ebp-8h] BYREF
  CUtlSymbol result; // [esp+64h] [ebp-4h] BYREF
  CfgProcessor::CfgEntryInfo *v36; // [esp+74h] [ebp+Ch]

  if ( Threading::g_mtxGlobal.m_pUseMtx.m_value != nullptr )
    EnterCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)Threading::g_mtxGlobal.m_pUseMtx.m_value);
  v2 = (`anonymous namespace'::g_nStaticCombosPerWorkUnit * iWorkUnit) >> 32;
  LODWORD(iCombo) = `anonymous namespace'::g_nStaticCombosPerWorkUnit * iWorkUnit;
  comboEnd = `anonymous namespace'::g_nStaticCombosPerWorkUnit * iWorkUnit
           + `anonymous namespace'::g_nStaticCombosPerWorkUnit;
  if ( `anonymous namespace'::g_numStaticCombos < comboEnd )
    comboEnd = `anonymous namespace'::g_numStaticCombos;
  chLastShaderName = setName;
  memset(dst: (int)&siLastShaderInfo, value: nullptr, count: sizeof(siLastShaderInfo));
  m_p = `anonymous namespace'::g_arrCompileEntries.m_p;
  siLastShaderInfo.m_pShaderName = setName;
  for ( i = __PAIR64__((`anonymous namespace'::g_nStaticCombosPerWorkUnit * iWorkUnit) >> 32, iCombo); m_p != nullptr; ++m_p )
  {
    if ( m_p->m_szName == nullptr )
      break;
    m_numStaticCombos_high = HIDWORD(m_p->m_numStaticCombos);
    m_numStaticCombos = m_p->m_numStaticCombos;
    if ( i < __PAIR64__(m_numStaticCombos_high, m_numStaticCombos) )
      break;
    i -= __PAIR64__(m_numStaticCombos_high, m_numStaticCombos);
  }
  v36 = m_p;
  v8 = m_p->m_numStaticCombos - i - 1;
  v7 = HIDWORD(v8);
  HIDWORD(nComboOfTheEntry) = HIDWORD(v8);
  v9 = v8;
  v10 = v2;
  if ( __PAIR64__(v2, iCombo) < comboEnd )
  {
    do
    {
      v11 = (__PAIR64__(v10, iCombo) + 1) >> 32;
      LODWORD(iCombo) = iCombo + 1;
      HIDWORD(iCombo) = v11;
      MessageBuffer::read(this: pBuf, p: &len, bytes: 4);
      v12 = (const char *)len;
      if ( len > 0 )
      {
        m_szName = v36->m_szName;
        chShaderName = m_szName;
        if ( chLastShaderName != m_szName )
        {
          Shader_ParseShaderInfoFromCompileCommands(pEntry: v36, shaderInfo: &siLastShaderInfo);
          chLastShaderName = m_szName;
          CUtlSymbolTable::AddString(this: &g_ShaderToShaderInfo.m_SymbolTable, &result, pString: m_szName);
          m_Id = result.m_Id;
          if ( g_ShaderToShaderInfo.m_Vector.m_Size <= result.m_Id
            && g_ShaderToShaderInfo.m_Vector.m_Size < result.m_Id + 1 )
          {
            CUtlVector<ShaderInfo_t,CUtlMemory<ShaderInfo_t,int>>::InsertMultipleBefore(
              this: &g_ShaderToShaderInfo.m_Vector,
              elem: g_ShaderToShaderInfo.m_Vector.m_Size,
              num: result.m_Id + 1 - g_ShaderToShaderInfo.m_Vector.m_Size);
          }
          g_ShaderToShaderInfo.m_Vector.m_Memory.m_pMemory[m_Id] = siLastShaderInfo;
          v12 = (const char *)len;
          m_szName = chShaderName;
          v7 = HIDWORD(nComboOfTheEntry);
        }
        chShaderName = v12;
        v18 = StaticComboFromDictAdd(pszShaderName: m_szName, nStaticComboId: __PAIR64__(v7, v9));
        v27 = v18->m_abPackedCode.m_p;
        v18->m_abPackedCode.m_p = nullptr;
        free(pMem: v27);
        if ( chShaderName != nullptr )
        {
          v19 = (unsigned __int8 *)operator new(nSize: (unsigned int)(chShaderName + 4));
          v20 = chShaderName;
          v18->m_abPackedCode.m_p = v19;
          *(_DWORD *)v19 = v20;
        }
        v21 = v18->m_abPackedCode.m_p;
        if ( v21 != nullptr && v21 != (unsigned __int8 *)-4 )
          MessageBuffer::read(this: pBuf, p: v21 + 4, bytes: len);
      }
      else
      {
        `anonymous namespace'::g_numSkippedStaticCombos += -len;
        v13 = -len - 1;
        if ( v13 >= 0 && (v13 >= 0 && -len - 1 < 0 || -len != 1) )
        {
          while ( 1 )
          {
            if ( v13 <= __PAIR64__(v7, v9) )
            {
              v7 = (__PAIR64__(v7, v9) - v13) >> 32;
              v9 -= v13;
              iCombo += v13;
              goto LABEL_19;
            }
            v13 += -1LL - __PAIR64__(v7, v9);
            iCombo += __PAIR64__(v7, v9) + 1;
            v14 = v36[1].m_numStaticCombos;
            ++v36;
            v15 = (__PAIR64__(HIDWORD(v36->m_numStaticCombos), v14) - 1) >> 32;
            v9 = v14 - 1;
            HIDWORD(nComboOfTheEntry) = v15;
            if ( v13 <= 0 )
              break;
            v7 = HIDWORD(nComboOfTheEntry);
          }
          v7 = HIDWORD(nComboOfTheEntry);
        }
LABEL_19:
        if ( iCombo >= comboEnd )
          break;
      }
      v22 = v9;
      v23 = v9-- != 0;
      v24 = v7;
      v7 = v23 + v7 - 1;
      HIDWORD(nComboOfTheEntry) = v7;
      if ( (v24 | v22) == 0 )
      {
        v25 = v36[1].m_numStaticCombos;
        ++v36;
        v26 = (__PAIR64__(HIDWORD(v36->m_numStaticCombos), v25) - 1) >> 32;
        v9 = v25 - 1;
        HIDWORD(nComboOfTheEntry) = v26;
        v7 = v26;
      }
      v10 = HIDWORD(iCombo);
    }
    while ( iCombo < comboEnd );
  }
  if ( Threading::g_mtxGlobal.m_pUseMtx.m_value != nullptr )
    LeaveCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)Threading::g_mtxGlobal.m_pUseMtx.m_value);
}

//------------------------------------------------------------------------------
// Address: 0x1000B8B0
// Name: unsigned int AssembleWorkerReplyPackage(struct CfgProcessor::CfgEntryInfo const __near *,unsigned __int64,class MessageBuffer __near *)
// Source: json
//------------------------------------------------------------------------------
unsigned int __cdecl AssembleWorkerReplyPackage(
        const CfgProcessor::CfgEntryInfo *pEntry,
        unsigned __int64 nComboOfEntry,
        MessageBuffer *pBuf)
{
  unsigned int v3; // edi
  CStaticCombo *v4; // ebx
  int m_Id; // esi
  CUtlNodeHash<CStaticCombo,7097,unsigned __int64> *v6; // esi
  bool v7; // al
  int v8; // esi
  CByteCodeBlock *v9; // eax
  CUtlIntrusiveDList<CStaticCombo> *v10; // ecx
  CStaticCombo *m_pHead; // eax
  const char *m_szName; // [esp-10h] [ebp-50h]
  CUtlBuffer ubDynamicComboBuffer; // [esp+0h] [ebp-40h] BYREF
  CUtlNodeHash<CStaticCombo,7097,unsigned __int64> *pByteCodeArray; // [esp+30h] [ebp-10h]
  unsigned int nBytesWritten; // [esp+34h] [ebp-Ch] BYREF
  CStaticCombo *pStComboRec; // [esp+38h] [ebp-8h]
  CUtlSymbol v18; // [esp+3Ch] [ebp-4h] BYREF

  if ( Threading::g_mtxGlobal.m_pUseMtx.m_value != nullptr )
    EnterCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)Threading::g_mtxGlobal.m_pUseMtx.m_value);
  v3 = nComboOfEntry;
  v4 = StaticComboFromDict(pszShaderName: pEntry->m_szName, nStaticComboId: nComboOfEntry);
  m_szName = pEntry->m_szName;
  pStComboRec = v4;
  CUtlSymbolTable::AddString(this: &g_ShaderByteCode.m_SymbolTable, result: &v18, pString: m_szName);
  m_Id = v18.m_Id;
  if ( g_ShaderByteCode.m_Vector.m_Size <= v18.m_Id && g_ShaderByteCode.m_Vector.m_Size < v18.m_Id + 1 )
    CUtlVector<CUtlNodeHash<CStaticCombo,7097,unsigned __int64> *,CUtlMemory<CUtlNodeHash<CStaticCombo,7097,unsigned __int64> *,int>>::InsertMultipleBefore(
      this: &g_ShaderByteCode.m_Vector,
      elem: g_ShaderByteCode.m_Vector.m_Size,
      num: v18.m_Id + 1 - g_ShaderByteCode.m_Vector.m_Size);
  v6 = g_ShaderByteCode.m_Vector.m_Memory.m_pMemory[m_Id];
  pByteCodeArray = v6;
  if ( Threading::g_mtxGlobal.m_pUseMtx.m_value != nullptr )
    LeaveCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)Threading::g_mtxGlobal.m_pUseMtx.m_value);
  nBytesWritten = 0;
  if ( v4 != nullptr && v4->m_DynamicCombos.m_Size != 0 )
  {
    CUtlBuffer::CUtlBuffer(this: &ubDynamicComboBuffer, growSize: 0, initSize: 0, nFlags: 0);
    v7 = g_bIsX360 || g_bIsPS3;
    CUtlBuffer::SetBigEndian(this: &ubDynamicComboBuffer, bigEndian: v7);
    CUtlVector<CByteCodeBlock *,CUtlMemory<CByteCodeBlock *,int>>::Sort(
      this: &v4->m_DynamicCombos,
      pfnCompare: (int (__cdecl *)(const void *, const void *))CompareDynamicComboIDs);
    v8 = 0;
    if ( pStComboRec->m_DynamicCombos.m_Size > 0 )
    {
      do
      {
        v9 = v4->m_DynamicCombos.m_Memory.m_pMemory[v8];
        OutputDynamicCombo(
          pDynamicComboBuffer: &ubDynamicComboBuffer,
          pBuf,
          nComboSize: v9->m_nCodeSize,
          pnTotalFlushedSize: &nBytesWritten,
          nComboID: v9->m_nComboID,
          pComboCode: v9->m_ByteCode);
        ++v8;
      }
      while ( v8 < pStComboRec->m_DynamicCombos.m_Size );
      v3 = nComboOfEntry;
    }
    FlushCombos(pDynamicComboBuffer: &ubDynamicComboBuffer, pnTotalFlushedSize: &nBytesWritten, pBuf);
    if ( ubDynamicComboBuffer.m_Memory.m_nGrowSize >= 0 && ubDynamicComboBuffer.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: ubDynamicComboBuffer.m_Memory.m_pMemory);
    v4 = pStComboRec;
    v6 = pByteCodeArray;
  }
  *(float *)&pByteCodeArray = _Plat_FloatTime();
  if ( Threading::g_mtxGlobal.m_pUseMtx.m_value != nullptr )
    EnterCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)Threading::g_mtxGlobal.m_pUseMtx.m_value);
  if ( v4 != nullptr )
  {
    v10 = &v6->m_HashChains[v3 % 0x1BB9];
    m_pHead = v10->m_pHead;
    if ( v10->m_pHead != nullptr )
    {
      while ( m_pHead->m_nStaticComboID != __PAIR64__(HIDWORD(nComboOfEntry), v3) )
      {
        m_pHead = m_pHead->m_pNext;
        if ( m_pHead == nullptr )
          goto LABEL_28;
      }
      CUtlIntrusiveDList<CStaticCombo>::RemoveNode(this: v10, which: m_pHead);
      --v6->m_nNumNodes;
    }
  }
LABEL_28:
  if ( COERCE_FLOAT(COERCE_UNSIGNED_INT(*(float *)&pByteCodeArray - s_fLastInfoTime) & _mask__AbsFloat_) > 1.0 )
  {
    _Msg(a1: "\rCompiling  %s  [ %2d remaining ] ...         \r", pEntry->m_szName, v3);
    LODWORD(s_fLastInfoTime) = pByteCodeArray;
  }
  if ( Threading::g_mtxGlobal.m_pUseMtx.m_value != nullptr )
    LeaveCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)Threading::g_mtxGlobal.m_pUseMtx.m_value);
  return nBytesWritten;
}

//------------------------------------------------------------------------------
// Address: 0x1000BAC0
// Name: unsigned int CopyWorkerReplyPackage(struct CfgProcessor::CfgEntryInfo const __near *,unsigned __int64,class MessageBuffer __near *,int)
// Source: json
//------------------------------------------------------------------------------
unsigned int __cdecl CopyWorkerReplyPackage(
        const CfgProcessor::CfgEntryInfo *pEntry,
        unsigned __int64 nComboOfEntry,
        MessageBuffer *pBuf,
        int nSkipsSoFar)
{
  CStaticCombo *v4; // ebx
  int m_Id; // esi
  CUtlNodeHash<CStaticCombo,7097,unsigned __int64> *v6; // esi
  unsigned int *m_p; // eax
  unsigned int result; // eax
  unsigned __int8 *v9; // ecx
  const void *v10; // ecx
  int len; // [esp+0h] [ebp-8h] BYREF
  CUtlSymbol v12; // [esp+4h] [ebp-4h] BYREF

  if ( Threading::g_mtxGlobal.m_pUseMtx.m_value != nullptr )
    EnterCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)Threading::g_mtxGlobal.m_pUseMtx.m_value);
  v4 = StaticComboFromDict(pszShaderName: pEntry->m_szName, nStaticComboId: nComboOfEntry);
  CUtlSymbolTable::AddString(this: &g_ShaderByteCode.m_SymbolTable, result: &v12, pString: pEntry->m_szName);
  m_Id = v12.m_Id;
  if ( g_ShaderByteCode.m_Vector.m_Size <= v12.m_Id && g_ShaderByteCode.m_Vector.m_Size < v12.m_Id + 1 )
    CUtlVector<CUtlNodeHash<CStaticCombo,7097,unsigned __int64> *,CUtlMemory<CUtlNodeHash<CStaticCombo,7097,unsigned __int64> *,int>>::InsertMultipleBefore(
      this: &g_ShaderByteCode.m_Vector,
      elem: g_ShaderByteCode.m_Vector.m_Size,
      num: v12.m_Id + 1 - g_ShaderByteCode.m_Vector.m_Size);
  v6 = g_ShaderByteCode.m_Vector.m_Memory.m_pMemory[m_Id];
  if ( Threading::g_mtxGlobal.m_pUseMtx.m_value != nullptr )
    LeaveCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)Threading::g_mtxGlobal.m_pUseMtx.m_value);
  if ( v4 != nullptr && (m_p = (unsigned int *)v4->m_abPackedCode.m_p) != nullptr )
    result = *m_p;
  else
    result = 0;
  len = result;
  if ( result != 0 )
  {
    if ( nSkipsSoFar != 0 )
      MessageBuffer::write(this: pBuf, p: &nSkipsSoFar, bytes: 4);
    MessageBuffer::write(this: pBuf, p: &len, bytes: 4);
    result = len;
    if ( len != 0 )
    {
      v9 = v4->m_abPackedCode.m_p;
      if ( v9 != nullptr )
        v10 = v9 + 4;
      else
        v10 = nullptr;
      MessageBuffer::write(this: pBuf, p: v10, bytes: len);
      result = len;
    }
  }
  if ( v4 != nullptr )
  {
    if ( Threading::g_mtxGlobal.m_pUseMtx.m_value != nullptr )
      EnterCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)Threading::g_mtxGlobal.m_pUseMtx.m_value);
    CUtlNodeHash<CStaticCombo,7097,unsigned __int64>::DeleteByKey(this: v6, nMatchKey: nComboOfEntry);
    if ( Threading::g_mtxGlobal.m_pUseMtx.m_value != nullptr )
      LeaveCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)Threading::g_mtxGlobal.m_pUseMtx.m_value);
    return len;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1000BBE0
// Name: protected: void Worker_ProcessCommandRange_Singleton::Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall Worker_ProcessCommandRange_Singleton::Shutdown(Worker_ProcessCommandRange_Singleton *this)
{
  CWorkerAccumState<CThreadFastMutex> *pWorkerObj; // edi
  CWorkerAccumState<CThreadNullMutex> *v3; // esi

  if ( this->m_MT.pThreadPool != nullptr )
  {
    pWorkerObj = this->m_MT.pWorkerObj;
    if ( pWorkerObj != nullptr )
    {
      CWorkerAccumState<CThreadFastMutex>::QuitSubs(this: this->m_MT.pWorkerObj);
      *pWorkerObj->m_autoRestoreDisconnectHandler.m_rVar = pWorkerObj->m_autoRestoreDisconnectHandler.m_valPop;
      CUtlVector<CWorkerAccumState<CThreadNullMutex>::SubProcess *,CUtlMemory<CWorkerAccumState<CThreadNullMutex>::SubProcess *,int>>::~CUtlVector<CWorkerAccumState<CThreadNullMutex>::SubProcess *,CUtlMemory<CWorkerAccumState<CThreadNullMutex>::SubProcess *,int>>(this: (CUtlVector<CFileResponse,CUtlMemory<CFileResponse,int> > *)&pWorkerObj->m_arrSubProcessInfos);
      GenericThreadLocals::CThreadLocalBase::~CThreadLocalBase(this: &pWorkerObj->m_lpSubProcessInfo);
      free(pMem: pWorkerObj);
    }
    this->m_MT.pThreadPool->Stop(this: this->m_MT.pThreadPool, a2: -1);
    this->m_MT.pThreadPool = nullptr;
  }
  else
  {
    v3 = this->m_ST.pWorkerObj;
    if ( v3 != nullptr )
    {
      CWorkerAccumState<CThreadNullMutex>::QuitSubs(this: v3);
      *v3->m_autoRestoreDisconnectHandler.m_rVar = v3->m_autoRestoreDisconnectHandler.m_valPop;
      CUtlVector<CWorkerAccumState<CThreadNullMutex>::SubProcess *,CUtlMemory<CWorkerAccumState<CThreadNullMutex>::SubProcess *,int>>::~CUtlVector<CWorkerAccumState<CThreadNullMutex>::SubProcess *,CUtlMemory<CWorkerAccumState<CThreadNullMutex>::SubProcess *,int>>(this: (CUtlVector<CFileResponse,CUtlMemory<CFileResponse,int> > *)&v3->m_arrSubProcessInfos);
      GenericThreadLocals::CThreadLocalBase::~CThreadLocalBase(this: &v3->m_lpSubProcessInfo);
      free(pMem: v3);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000BC70
// Name: public: class CompilerMsgInfo __near & CUtlStringMap<class CompilerMsgInfo>::operator[](char const __near *)
// Source: json
//------------------------------------------------------------------------------
CompilerMsgInfo *__thiscall CUtlStringMap<CompilerMsgInfo>::operator[](
        CUtlStringMap<CompilerMsgInfo> *this,
        const char *pString)
{
  int v3; // edi
  int m_Size; // ecx

  CUtlSymbolTable::AddString(this: &this->m_SymbolTable, result: (CUtlSymbol *)&pString, pString);
  v3 = (unsigned __int16)pString;
  m_Size = this->m_Vector.m_Size;
  if ( m_Size <= (unsigned __int16)pString && m_Size < (unsigned __int16)pString + 1 )
    CUtlVector<CompilerMsgInfo,CUtlMemory<CompilerMsgInfo,int>>::InsertMultipleBefore(
      this: &this->m_Vector,
      elem: m_Size,
      num: (unsigned __int16)pString + 1 - m_Size);
  return &this->m_Vector.m_Memory.m_pMemory[v3];
}

//------------------------------------------------------------------------------
// Address: 0x1000BCC0
// Name: protected: void CWorkerAccumState<class CThreadFastMutex>::TryToPackageData(unsigned __int64)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWorkerAccumState<CThreadFastMutex>::TryToPackageData(
        CWorkerAccumState<CThreadFastMutex> *this,
        unsigned __int64 iCommandNumber)
{
  CThreadFastMutex *m_pMutex; // edi
  DWORD CurrentThreadId; // ecx
  unsigned __int64 v5; // kr00_8
  int v6; // ecx
  unsigned int m_iLastFinished_high; // eax
  CThreadFastMutex *v8; // esi
  bool v9; // zf
  const CfgProcessor::CfgEntryInfo *EntryInfo; // edi
  unsigned __int64 v11; // rax
  int v12; // esi
  int v13; // ebx
  CStaticCombo *v14; // esi
  unsigned __int8 *v15; // eax
  unsigned int v16; // edx
  unsigned __int8 *v17; // esi
  void *v18; // esi
  int v19; // eax
  bool v20; // cf
  int v21; // ecx
  CfgProcessor::<unnamed_type_ComboHandle> *Combo; // eax
  CThreadFastMutex *v23; // esi
  unsigned __int8 *m_p; // [esp-10h] [ebp-48h]
  MessageBuffer mbPacked; // [esp+Ch] [ebp-2Ch] BYREF
  unsigned __int64 iLastFinished; // [esp+1Ch] [ebp-1Ch]
  unsigned __int64 nComboBegin; // [esp+24h] [ebp-14h]
  unsigned int nPackedLength; // [esp+2Ch] [ebp-Ch]
  CfgProcessor::<unnamed_type_ComboHandle> *hChEnd; // [esp+30h] [ebp-8h] BYREF
  CfgProcessor::<unnamed_type_ComboHandle> *hChBegin; // [esp+34h] [ebp-4h] BYREF
  const CfgProcessor::CfgEntryInfo *pInfoEnd_4; // [esp+44h] [ebp+Ch]

  m_pMutex = this->m_pMutex;
  CurrentThreadId = GetCurrentThreadId();
  if ( CurrentThreadId != m_pMutex->m_ownerID
    && _InterlockedCompareExchange((volatile signed __int32 *)m_pMutex, CurrentThreadId, 0) != 0 )
  {
    _mm_pause();
    CThreadFastMutex::Lock(a1: m_pMutex, a2: CurrentThreadId, a3: 0);
  }
  else
  {
    ++m_pMutex->m_depth;
  }
  v5 = iCommandNumber + 1;
  v6 = 0;
  if ( this->m_arrSubProcessInfos.m_Size > 0 )
  {
    nPackedLength = (unsigned int)this->m_arrSubProcessInfos.m_Memory.m_pMemory;
    while ( *(_DWORD *)nPackedLength == 0 || *(_QWORD *)(*(_DWORD *)nPackedLength + 8) >= iCommandNumber )
    {
      nPackedLength += 4;
      if ( ++v6 >= this->m_arrSubProcessInfos.m_Size )
        goto LABEL_12;
    }
    v5 = 0;
  }
LABEL_12:
  m_iLastFinished_high = HIDWORD(this->m_iLastFinished);
  LODWORD(iLastFinished) = this->m_iLastFinished;
  if ( v5 <= __PAIR64__(m_iLastFinished_high, iLastFinished) )
  {
    v23 = this->m_pMutex;
    v9 = v23->m_depth-- == 1;
    if ( v9 )
      _InterlockedExchange((volatile __int32 *)v23, 0);
  }
  else
  {
    this->m_iLastFinished = v5;
    v8 = this->m_pMutex;
    v9 = v8->m_depth-- == 1;
    if ( v9 )
      _InterlockedExchange((volatile __int32 *)v8, 0);
    hChBegin = (CfgProcessor::<unnamed_type_ComboHandle> *)CfgProcessor::Combo_GetCombo(iCommandNumber: __PAIR64__(m_iLastFinished_high, iLastFinished));
    hChEnd = (CfgProcessor::<unnamed_type_ComboHandle> *)CfgProcessor::Combo_GetCombo(iCommandNumber: v5);
    EntryInfo = CfgProcessor::Combo_GetEntryInfo(hCombo: hChBegin);
    pInfoEnd_4 = CfgProcessor::Combo_GetEntryInfo(hCombo: hChEnd);
    v11 = CfgProcessor::Combo_GetComboNum(hCombo: hChBegin) / EntryInfo->m_numDynamicCombos;
    v12 = HIDWORD(v11);
    HIDWORD(nComboBegin) = HIDWORD(v11);
    v13 = v11;
    iLastFinished = CfgProcessor::Combo_GetComboNum(hCombo: hChEnd) / pInfoEnd_4->m_numDynamicCombos;
    while ( EntryInfo->m_iCommandStart < pInfoEnd_4->m_iCommandStart || __PAIR64__(v12, v13) > iLastFinished )
    {
      MessageBuffer::MessageBuffer(this: &mbPacked);
      nPackedLength = AssembleWorkerReplyPackage(
                        pEntry: EntryInfo,
                        nComboOfEntry: __PAIR64__(v12, v13),
                        pBuf: &mbPacked);
      if ( nPackedLength != 0 )
      {
        if ( Threading::g_mtxGlobal.m_pUseMtx.m_value != nullptr )
          EnterCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)Threading::g_mtxGlobal.m_pUseMtx.m_value);
        v14 = StaticComboFromDictAdd(pszShaderName: EntryInfo->m_szName, nStaticComboId: __PAIR64__(v12, v13));
        m_p = v14->m_abPackedCode.m_p;
        v14->m_abPackedCode.m_p = nullptr;
        free(pMem: m_p);
        v15 = (unsigned __int8 *)operator new(nSize: nPackedLength + 4);
        v16 = nPackedLength;
        v14->m_abPackedCode.m_p = v15;
        *(_DWORD *)v15 = v16;
        v17 = v14->m_abPackedCode.m_p;
        if ( v17 != nullptr )
          v18 = v17 + 4;
        else
          v18 = nullptr;
        if ( Threading::g_mtxGlobal.m_pUseMtx.m_value != nullptr )
          LeaveCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)Threading::g_mtxGlobal.m_pUseMtx.m_value);
        if ( v18 != nullptr )
          MessageBuffer::read(this: &mbPacked, p: v18, bytes: nPackedLength);
        v12 = HIDWORD(nComboBegin);
      }
      v19 = v13;
      v20 = v13-- != 0;
      v21 = v12;
      v12 = v20 + v12 - 1;
      HIDWORD(nComboBegin) = v12;
      if ( (v21 | v19) == 0 )
      {
        CfgProcessor::Combo_Free(rhComboFree: &hChBegin);
        Combo = (CfgProcessor::<unnamed_type_ComboHandle> *)CfgProcessor::Combo_GetCombo(iCommandNumber: EntryInfo->m_iCommandEnd);
        hChBegin = Combo;
        if ( Combo != nullptr )
        {
          EntryInfo = CfgProcessor::Combo_GetEntryInfo(hCombo: Combo);
          v13 = LODWORD(EntryInfo->m_numStaticCombos) - 1;
          HIDWORD(nComboBegin) = (EntryInfo->m_numStaticCombos - 1) >> 32;
          v12 = HIDWORD(nComboBegin);
        }
      }
      MessageBuffer::~MessageBuffer(this: &mbPacked);
    }
    CfgProcessor::Combo_Free(rhComboFree: &hChBegin);
    CfgProcessor::Combo_Free(rhComboFree: &hChEnd);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000BF40
// Name: protected: void CWorkerAccumState<class CThreadNullMutex>::TryToPackageData(unsigned __int64)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWorkerAccumState<CThreadNullMutex>::TryToPackageData(
        CWorkerAccumState<CThreadNullMutex> *this,
        unsigned __int64 iCommandNumber)
{
  unsigned __int64 v2; // rdi
  int v3; // edx
  const CfgProcessor::CfgEntryInfo *EntryInfo; // edi
  unsigned __int64 v5; // rax
  int v6; // esi
  int v7; // ebx
  CStaticCombo *v8; // esi
  unsigned __int8 *v9; // eax
  unsigned int v10; // edx
  unsigned __int8 *v11; // esi
  void *v12; // esi
  int v13; // eax
  bool v14; // cf
  int v15; // ecx
  CfgProcessor::<unnamed_type_ComboHandle> *Combo; // eax
  unsigned __int8 *m_p; // [esp-10h] [ebp-48h]
  unsigned __int64 m_iLastFinished; // [esp-8h] [ebp-40h]
  MessageBuffer mbPacked; // [esp+Ch] [ebp-2Ch] BYREF
  unsigned __int64 nComboEnd; // [esp+1Ch] [ebp-1Ch]
  unsigned __int64 nComboBegin; // [esp+24h] [ebp-14h]
  CfgProcessor::<unnamed_type_ComboHandle> *hChEnd; // [esp+2Ch] [ebp-Ch] BYREF
  unsigned int nPackedLength; // [esp+30h] [ebp-8h]
  const CfgProcessor::CfgEntryInfo *pInfoEnd; // [esp+34h] [ebp-4h]

  v2 = iCommandNumber + 1;
  v3 = 0;
  if ( this->m_arrSubProcessInfos.m_Size > 0 )
  {
    pInfoEnd = (const CfgProcessor::CfgEntryInfo *)this->m_arrSubProcessInfos.m_Memory.m_pMemory;
    while ( pInfoEnd->m_szName == nullptr || *((_QWORD *)pInfoEnd->m_szName + 1) >= iCommandNumber )
    {
      pInfoEnd = (const CfgProcessor::CfgEntryInfo *)((char *)pInfoEnd + 4);
      if ( ++v3 >= this->m_arrSubProcessInfos.m_Size )
        goto LABEL_8;
    }
    HIDWORD(iCommandNumber) = 0;
    v2 = 0;
  }
LABEL_8:
  if ( v2 > this->m_iLastFinished )
  {
    m_iLastFinished = this->m_iLastFinished;
    this->m_iLastFinished = v2;
    HIDWORD(iCommandNumber) = CfgProcessor::Combo_GetCombo(iCommandNumber: m_iLastFinished);
    hChEnd = (CfgProcessor::<unnamed_type_ComboHandle> *)CfgProcessor::Combo_GetCombo(iCommandNumber: v2);
    EntryInfo = CfgProcessor::Combo_GetEntryInfo(hCombo: (CfgProcessor::<unnamed_type_ComboHandle> *)HIDWORD(iCommandNumber));
    pInfoEnd = CfgProcessor::Combo_GetEntryInfo(hCombo: hChEnd);
    v5 = CfgProcessor::Combo_GetComboNum(hCombo: (CfgProcessor::<unnamed_type_ComboHandle> *)HIDWORD(iCommandNumber))
       / EntryInfo->m_numDynamicCombos;
    v6 = HIDWORD(v5);
    HIDWORD(nComboBegin) = HIDWORD(v5);
    v7 = v5;
    nComboEnd = CfgProcessor::Combo_GetComboNum(hCombo: hChEnd) / pInfoEnd->m_numDynamicCombos;
    while ( EntryInfo->m_iCommandStart < pInfoEnd->m_iCommandStart || __PAIR64__(v6, v7) > nComboEnd )
    {
      MessageBuffer::MessageBuffer(this: &mbPacked);
      nPackedLength = AssembleWorkerReplyPackage(pEntry: EntryInfo, nComboOfEntry: __PAIR64__(v6, v7), pBuf: &mbPacked);
      if ( nPackedLength != 0 )
      {
        if ( Threading::g_mtxGlobal.m_pUseMtx.m_value != nullptr )
          EnterCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)Threading::g_mtxGlobal.m_pUseMtx.m_value);
        v8 = StaticComboFromDictAdd(pszShaderName: EntryInfo->m_szName, nStaticComboId: __PAIR64__(v6, v7));
        m_p = v8->m_abPackedCode.m_p;
        v8->m_abPackedCode.m_p = nullptr;
        free(pMem: m_p);
        v9 = (unsigned __int8 *)operator new(nSize: nPackedLength + 4);
        v10 = nPackedLength;
        v8->m_abPackedCode.m_p = v9;
        *(_DWORD *)v9 = v10;
        v11 = v8->m_abPackedCode.m_p;
        if ( v11 != nullptr )
          v12 = v11 + 4;
        else
          v12 = nullptr;
        if ( Threading::g_mtxGlobal.m_pUseMtx.m_value != nullptr )
          LeaveCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)Threading::g_mtxGlobal.m_pUseMtx.m_value);
        if ( v12 != nullptr )
          MessageBuffer::read(this: &mbPacked, p: v12, bytes: nPackedLength);
        v6 = HIDWORD(nComboBegin);
      }
      v13 = v7;
      v14 = v7-- != 0;
      v15 = v6;
      v6 = v14 + v6 - 1;
      HIDWORD(nComboBegin) = v6;
      if ( (v15 | v13) == 0 )
      {
        CfgProcessor::Combo_Free(rhComboFree: (CfgProcessor::<unnamed_type_ComboHandle> **)&iCommandNumber + 1);
        Combo = (CfgProcessor::<unnamed_type_ComboHandle> *)CfgProcessor::Combo_GetCombo(iCommandNumber: EntryInfo->m_iCommandEnd);
        HIDWORD(iCommandNumber) = Combo;
        if ( Combo != nullptr )
        {
          EntryInfo = CfgProcessor::Combo_GetEntryInfo(hCombo: Combo);
          v7 = LODWORD(EntryInfo->m_numStaticCombos) - 1;
          HIDWORD(nComboBegin) = (EntryInfo->m_numStaticCombos - 1) >> 32;
          v6 = HIDWORD(nComboBegin);
        }
      }
      MessageBuffer::~MessageBuffer(this: &mbPacked);
    }
    CfgProcessor::Combo_Free(rhComboFree: (CfgProcessor::<unnamed_type_ComboHandle> **)&iCommandNumber + 1);
    CfgProcessor::Combo_Free(rhComboFree: &hChEnd);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000C170
// Name: void ErrMsgDispatchMsgLine(char const __near *,char __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ErrMsgDispatchMsgLine(const char *szCommand, char *szMsgLine, const char *szShaderName)
{
  char *v3; // esi
  char *Next; // eax
  char *v5; // edi
  char *Last; // eax
  const char *v7; // edi
  int v8; // esi
  CompilerMsgInfo *v9; // esi
  const char *LocalMachineName; // edi

  v3 = szMsgLine;
  if ( isalpha(c: (unsigned __int8)*szMsgLine) != 0 && v3[1] == 58 )
    v3 += 2;
  Next = FindNext(szString: v3, szSearchSet: ":");
  v5 = Next;
  if ( *Next == 58 )
  {
    *Next = 0;
    Last = FindLast(szString: v3, szSearchSet: "\\/");
    if ( Last != nullptr && *Last != 0 )
    {
      *Last = 0;
      v3 = Last + 1;
    }
    *v5 = 58;
  }
  v7 = szShaderName;
  if ( szShaderName != nullptr )
  {
    if ( *v3 == 40 )
    {
LABEL_13:
      sprintf(string: chFitLongMsgLine, format: "%s%s", v7, v3);
      v3 = chFitLongMsgLine;
      goto LABEL_14;
    }
    if ( strncmp(first: v3, last: "memory(", count: 7u) == 0 )
    {
      v3 += 6;
      goto LABEL_13;
    }
  }
LABEL_14:
  CUtlSymbolTable::AddString(
    this: &g_Master_CompilerMsgInfo.m_SymbolTable,
    result: (CUtlSymbol *)&szMsgLine,
    pString: v3);
  v8 = (unsigned __int16)szMsgLine;
  if ( g_Master_CompilerMsgInfo.m_Vector.m_Size <= (unsigned __int16)szMsgLine
    && g_Master_CompilerMsgInfo.m_Vector.m_Size < (unsigned __int16)szMsgLine + 1 )
  {
    CUtlVector<CompilerMsgInfo,CUtlMemory<CompilerMsgInfo,int>>::InsertMultipleBefore(
      this: &g_Master_CompilerMsgInfo.m_Vector,
      elem: g_Master_CompilerMsgInfo.m_Vector.m_Size,
      num: (unsigned __int16)szMsgLine + 1 - g_Master_CompilerMsgInfo.m_Vector.m_Size);
  }
  v9 = &g_Master_CompilerMsgInfo.m_Vector.m_Memory.m_pMemory[v8];
  LocalMachineName = VMPI_GetLocalMachineName();
  if ( v9->m_numTimesReported == 0 )
  {
    CUtlString::operator=(this: &v9->m_sFirstCommand, src: szCommand);
    if ( LocalMachineName != nullptr )
      CUtlString::operator=(this: &v9->m_sFirstMachineName, src: LocalMachineName);
  }
  ++v9->m_numTimesReported;
}

//------------------------------------------------------------------------------
// Address: 0x1000C270
// Name: void ErrMsgDispatchInt(char __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ErrMsgDispatchInt(char *szMessage, const char *szShaderName)
{
  char *v2; // ebx
  char *Next; // esi
  char v4; // al
  char *v5; // esi
  char *v6; // edi
  char *v7; // eax
  char v8; // dl
  char chTerminator_3; // [esp+13h] [ebp+Bh]

  v2 = szMessage;
  if ( szMessage != nullptr && *szMessage != 0 )
  {
    do
    {
      if ( isspace(c: *v2) == 0 )
        break;
      ++v2;
    }
    while ( *v2 != 0 );
  }
  Next = FindNext(szString: v2, szSearchSet: "\r\n");
  v4 = *Next;
  *Next = 0;
  v5 = Next + 1;
  if ( v4 != 0 )
  {
    do
    {
      v6 = v5;
      if ( v5 != nullptr && *v5 != 0 )
      {
        do
        {
          if ( isspace(c: (unsigned __int8)*v6) == 0 )
            break;
          ++v6;
        }
        while ( *v6 != 0 );
      }
      v7 = FindNext(szString: v6, szSearchSet: "\r\n");
      v8 = *v7;
      *v7 = 0;
      v5 = v7 + 1;
      chTerminator_3 = v8;
      if ( *v6 != 0 )
      {
        *FindNext(szString: v2, szSearchSet: ">") = 0;
        ErrMsgDispatchMsgLine(szCommand: v2, szMsgLine: v6, szShaderName);
      }
    }
    while ( chTerminator_3 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000C320
// Name: bool ErrMsgDispatch(class MessageBuffer __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
char __cdecl ErrMsgDispatch(MessageBuffer *pBuf, int iSource)
{
  char *v2; // ebx
  char *Next; // eax
  const char *v5; // edi
  char *v6; // eax
  const char *v7; // esi
  char *v8; // eax
  CompilerMsgInfo *v9; // eax
  unsigned int v10; // [esp-14h] [ebp-14h]
  const char *MachineName; // [esp-10h] [ebp-10h]

  if ( Threading::g_mtxGlobal.m_pUseMtx.m_value != nullptr )
    EnterCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)Threading::g_mtxGlobal.m_pUseMtx.m_value);
  v2 = pBuf->data + 1;
  Next = FindNext(szString: v2, szSearchSet: "\n");
  if ( *Next != 0 )
  {
    *Next = 0;
    v5 = Next + 1;
    v6 = FindNext(szString: Next + 1, szSearchSet: "\n");
    if ( *v6 != 0 )
    {
      *v6 = 0;
      v7 = v6 + 1;
      v8 = FindNext(szString: v6 + 1, szSearchSet: "\n");
      if ( *v8 != 0 )
      {
        *v8 = 0;
        MachineName = VMPI_GetMachineName(iProc: iSource);
        v10 = atoi(nptr: v7);
        v9 = CUtlStringMap<CompilerMsgInfo>::operator[](this: &g_Master_CompilerMsgInfo, pString: v2);
        CompilerMsgInfo::SetMsgReportedCommand(
          this: v9,
          szCommand: v5,
          numTimesReported: v10,
          szMachineName: MachineName);
      }
    }
    if ( Threading::g_mtxGlobal.m_pUseMtx.m_value != nullptr )
      LeaveCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)Threading::g_mtxGlobal.m_pUseMtx.m_value);
  }
  else if ( Threading::g_mtxGlobal.m_pUseMtx.m_value != nullptr )
  {
    LeaveCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)Threading::g_mtxGlobal.m_pUseMtx.m_value);
    return 1;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1000C440
// Name: public: void CWorkerAccumState<class CThreadFastMutex>::HandleCommandResponse(struct CfgProcessor::_unnamed_type_ComboHandle_ __near *,struct CmdSink::IResponse __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWorkerAccumState<CThreadFastMutex>::HandleCommandResponse(
        CWorkerAccumState<CThreadFastMutex> *this,
        CfgProcessor::<unnamed_type_ComboHandle> *hCombo,
        const CfgProcessor::CfgEntryInfo *pResponse)
{
  CmdSink::CResponseFiles *v3; // esi
  CmdSink::CResponseFiles *v4; // eax
  CfgProcessor::<unnamed_type_ComboHandle> *v5; // edi
  unsigned __int64 ComboNum; // kr00_8
  unsigned __int64 CommandNum; // rax
  int v8; // ebx
  int v9; // edi
  const char **p_m_szName; // ebx
  CStaticCombo *v11; // eax
  int v12; // edi
  int v13; // eax
  char *v14; // edi
  unsigned __int64 v15; // [esp-10h] [ebp-174h]
  unsigned __int8 *v16; // [esp-8h] [ebp-16Ch]
  unsigned int v17; // [esp-4h] [ebp-168h]
  char chUnreportedListing[256]; // [esp+Ch] [ebp-158h] BYREF
  char chCommandNumber[52]; // [esp+10Ch] [ebp-58h] BYREF
  CUtlBinaryBlock errMsg; // [esp+140h] [ebp-24h] BYREF
  CWorkerAccumState<CThreadFastMutex> *v21; // [esp+150h] [ebp-14h]
  unsigned __int64 nStComboIdx; // [esp+154h] [ebp-10h]
  unsigned __int64 iCommandNumber; // [esp+15Ch] [ebp-8h]

  v21 = this;
  VMPI_HandleSocketErrors(timeout: 0);
  v3 = (CmdSink::CResponseFiles *)pResponse;
  if ( pResponse == nullptr )
  {
    v4 = (CmdSink::CResponseFiles *)operator new(nSize: 0x280u);
    if ( v4 != nullptr )
      v3 = CmdSink::CResponseFiles::CResponseFiles(this: v4, szFileResult: "shader.o", szFileListing: "output.txt");
    else
      v3 = nullptr;
  }
  v5 = hCombo;
  pResponse = CfgProcessor::Combo_GetEntryInfo(hCombo);
  ComboNum = CfgProcessor::Combo_GetComboNum(hCombo: v5);
  CommandNum = CfgProcessor::Combo_GetCommandNum(hCombo);
  HIDWORD(iCommandNumber) = HIDWORD(CommandNum);
  HIDWORD(CommandNum) = v3->__vftable;
  LODWORD(iCommandNumber) = CommandNum;
  if ( (*(unsigned __int8 (__thiscall **)(CmdSink::CResponseFiles *))(HIDWORD(CommandNum) + 8))(a1: v3) != 0 )
  {
    if ( Threading::g_mtxGlobal.m_pUseMtx.m_value != nullptr )
      EnterCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)Threading::g_mtxGlobal.m_pUseMtx.m_value);
    nStComboIdx = ComboNum / pResponse->m_numDynamicCombos;
    v8 = (ComboNum - pResponse->m_numDynamicCombos * nStComboIdx) >> 32;
    v9 = ComboNum - LODWORD(pResponse->m_numDynamicCombos) * nStComboIdx;
    v17 = v3->GetResultBufferLen(this: v3);
    v16 = (unsigned __int8 *)v3->GetResultBuffer(this: v3);
    HIDWORD(v15) = v8;
    p_m_szName = &pResponse->m_szName;
    LODWORD(v15) = v9;
    v11 = StaticComboFromDictAdd(pszShaderName: pResponse->m_szName, nStaticComboId: nStComboIdx);
    CStaticCombo::AddDynamicCombo(this: v11, nComboID: v15, pComboData: v16, nCodeSize: v17);
    if ( Threading::g_mtxGlobal.m_pUseMtx.m_value != nullptr )
      LeaveCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)Threading::g_mtxGlobal.m_pUseMtx.m_value);
  }
  else
  {
    p_m_szName = &pResponse->m_szName;
  }
  if ( !v3->Succeeded(this: v3) )
  {
    if ( Threading::g_mtxGlobal.m_pUseMtx.m_value != nullptr )
      EnterCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)Threading::g_mtxGlobal.m_pUseMtx.m_value);
    CUtlSymbolTable::AddString(
      this: &g_Master_ShaderHadError.m_SymbolTable,
      result: (CUtlSymbol *)&hCombo,
      pString: *p_m_szName);
    v12 = (unsigned __int16)hCombo;
    if ( g_Master_ShaderHadError.m_Vector.m_Size <= (unsigned __int16)hCombo )
      CUtlVector<bool,CUtlMemory<bool,int>>::EnsureCount(
        this: &g_Master_ShaderHadError.m_Vector,
        num: (unsigned __int16)hCombo + 1);
    g_Master_ShaderHadError.m_Vector.m_Memory.m_pMemory[v12] = true;
    if ( Threading::g_mtxGlobal.m_pUseMtx.m_value != nullptr )
      LeaveCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)Threading::g_mtxGlobal.m_pUseMtx.m_value);
  }
  v13 = (int)v3->GetListing(this: v3);
  v14 = (char *)v13;
  if ( !g_bSuppressWarnings && v13 != 0 || !v3->Succeeded(this: v3) )
  {
    sprintf(string: chCommandNumber, format: "%I64u", iCommandNumber);
    if ( v14 == nullptr )
    {
      sprintf(
        string: chUnreportedListing,
        format: "(0): error 0000: Compiler failed without error description, latest version of fxc.exe might give a description.",
        chCommandNumber);
      v14 = chUnreportedListing;
    }
    CUtlBinaryBlock::CUtlBinaryBlock(this: &errMsg, growSize: 0, initSize: 0);
    CUtlBinaryBlock::SetLength(this: &errMsg, nLength: strlen(v14) + strlen(chCommandNumber) + 3);
    sprintf(string: (char *)errMsg.m_Memory.m_pMemory, format: "%s\n%s\n", chCommandNumber, v14);
    if ( Threading::g_mtxGlobal.m_pUseMtx.m_value != nullptr )
      EnterCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)Threading::g_mtxGlobal.m_pUseMtx.m_value);
    ErrMsgDispatchInt(szMessage: (char *)errMsg.m_Memory.m_pMemory, szShaderName: p_m_szName[1]);
    if ( Threading::g_mtxGlobal.m_pUseMtx.m_value != nullptr )
      LeaveCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)Threading::g_mtxGlobal.m_pUseMtx.m_value);
    errMsg.m_nActualLength = 0;
    if ( errMsg.m_Memory.m_nGrowSize >= 0 && errMsg.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: errMsg.m_Memory.m_pMemory);
  }
  CWorkerAccumState<CThreadFastMutex>::TryToPackageData(this: v21, iCommandNumber);
}

//------------------------------------------------------------------------------
// Address: 0x1000C6D0
// Name: public: void CWorkerAccumState<class CThreadNullMutex>::HandleCommandResponse(struct CfgProcessor::_unnamed_type_ComboHandle_ __near *,struct CmdSink::IResponse __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWorkerAccumState<CThreadNullMutex>::HandleCommandResponse(
        CWorkerAccumState<CThreadNullMutex> *this,
        CfgProcessor::<unnamed_type_ComboHandle> *hCombo,
        const CfgProcessor::CfgEntryInfo *pResponse)
{
  CmdSink::CResponseFiles *v3; // esi
  CmdSink::CResponseFiles *v4; // eax
  CfgProcessor::<unnamed_type_ComboHandle> *v5; // edi
  unsigned __int64 ComboNum; // kr00_8
  unsigned __int64 CommandNum; // rax
  int v8; // ebx
  int v9; // edi
  const char **p_m_szName; // ebx
  CStaticCombo *v11; // eax
  int v12; // edi
  int v13; // eax
  char *v14; // edi
  unsigned __int64 v15; // [esp-10h] [ebp-174h]
  unsigned __int8 *v16; // [esp-8h] [ebp-16Ch]
  unsigned int v17; // [esp-4h] [ebp-168h]
  char chUnreportedListing[256]; // [esp+Ch] [ebp-158h] BYREF
  char chCommandNumber[52]; // [esp+10Ch] [ebp-58h] BYREF
  CUtlBinaryBlock errMsg; // [esp+140h] [ebp-24h] BYREF
  CWorkerAccumState<CThreadNullMutex> *v21; // [esp+150h] [ebp-14h]
  unsigned __int64 nStComboIdx; // [esp+154h] [ebp-10h]
  unsigned __int64 iCommandNumber; // [esp+15Ch] [ebp-8h]

  v21 = this;
  VMPI_HandleSocketErrors(timeout: 0);
  v3 = (CmdSink::CResponseFiles *)pResponse;
  if ( pResponse == nullptr )
  {
    v4 = (CmdSink::CResponseFiles *)operator new(nSize: 0x280u);
    if ( v4 != nullptr )
      v3 = CmdSink::CResponseFiles::CResponseFiles(this: v4, szFileResult: "shader.o", szFileListing: "output.txt");
    else
      v3 = nullptr;
  }
  v5 = hCombo;
  pResponse = CfgProcessor::Combo_GetEntryInfo(hCombo);
  ComboNum = CfgProcessor::Combo_GetComboNum(hCombo: v5);
  CommandNum = CfgProcessor::Combo_GetCommandNum(hCombo);
  HIDWORD(iCommandNumber) = HIDWORD(CommandNum);
  HIDWORD(CommandNum) = v3->__vftable;
  LODWORD(iCommandNumber) = CommandNum;
  if ( (*(unsigned __int8 (__thiscall **)(CmdSink::CResponseFiles *))(HIDWORD(CommandNum) + 8))(a1: v3) != 0 )
  {
    if ( Threading::g_mtxGlobal.m_pUseMtx.m_value != nullptr )
      EnterCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)Threading::g_mtxGlobal.m_pUseMtx.m_value);
    nStComboIdx = ComboNum / pResponse->m_numDynamicCombos;
    v8 = (ComboNum - pResponse->m_numDynamicCombos * nStComboIdx) >> 32;
    v9 = ComboNum - LODWORD(pResponse->m_numDynamicCombos) * nStComboIdx;
    v17 = v3->GetResultBufferLen(this: v3);
    v16 = (unsigned __int8 *)v3->GetResultBuffer(this: v3);
    HIDWORD(v15) = v8;
    p_m_szName = &pResponse->m_szName;
    LODWORD(v15) = v9;
    v11 = StaticComboFromDictAdd(pszShaderName: pResponse->m_szName, nStaticComboId: nStComboIdx);
    CStaticCombo::AddDynamicCombo(this: v11, nComboID: v15, pComboData: v16, nCodeSize: v17);
    if ( Threading::g_mtxGlobal.m_pUseMtx.m_value != nullptr )
      LeaveCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)Threading::g_mtxGlobal.m_pUseMtx.m_value);
  }
  else
  {
    p_m_szName = &pResponse->m_szName;
  }
  if ( !v3->Succeeded(this: v3) )
  {
    if ( Threading::g_mtxGlobal.m_pUseMtx.m_value != nullptr )
      EnterCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)Threading::g_mtxGlobal.m_pUseMtx.m_value);
    CUtlSymbolTable::AddString(
      this: &g_Master_ShaderHadError.m_SymbolTable,
      result: (CUtlSymbol *)&hCombo,
      pString: *p_m_szName);
    v12 = (unsigned __int16)hCombo;
    if ( g_Master_ShaderHadError.m_Vector.m_Size <= (unsigned __int16)hCombo )
      CUtlVector<bool,CUtlMemory<bool,int>>::EnsureCount(
        this: &g_Master_ShaderHadError.m_Vector,
        num: (unsigned __int16)hCombo + 1);
    g_Master_ShaderHadError.m_Vector.m_Memory.m_pMemory[v12] = true;
    if ( Threading::g_mtxGlobal.m_pUseMtx.m_value != nullptr )
      LeaveCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)Threading::g_mtxGlobal.m_pUseMtx.m_value);
  }
  v13 = (int)v3->GetListing(this: v3);
  v14 = (char *)v13;
  if ( !g_bSuppressWarnings && v13 != 0 || !v3->Succeeded(this: v3) )
  {
    sprintf(string: chCommandNumber, format: "%I64u", iCommandNumber);
    if ( v14 == nullptr )
    {
      sprintf(
        string: chUnreportedListing,
        format: "(0): error 0000: Compiler failed without error description, latest version of fxc.exe might give a description.",
        chCommandNumber);
      v14 = chUnreportedListing;
    }
    CUtlBinaryBlock::CUtlBinaryBlock(this: &errMsg, growSize: 0, initSize: 0);
    CUtlBinaryBlock::SetLength(this: &errMsg, nLength: strlen(v14) + strlen(chCommandNumber) + 3);
    sprintf(string: (char *)errMsg.m_Memory.m_pMemory, format: "%s\n%s\n", chCommandNumber, v14);
    if ( Threading::g_mtxGlobal.m_pUseMtx.m_value != nullptr )
      EnterCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)Threading::g_mtxGlobal.m_pUseMtx.m_value);
    ErrMsgDispatchInt(szMessage: (char *)errMsg.m_Memory.m_pMemory, szShaderName: p_m_szName[1]);
    if ( Threading::g_mtxGlobal.m_pUseMtx.m_value != nullptr )
      LeaveCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)Threading::g_mtxGlobal.m_pUseMtx.m_value);
    errMsg.m_nActualLength = 0;
    if ( errMsg.m_Memory.m_nGrowSize >= 0 && errMsg.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: errMsg.m_Memory.m_pMemory);
  }
  CWorkerAccumState<CThreadNullMutex>::TryToPackageData(this: v21, iCommandNumber);
}

//------------------------------------------------------------------------------
// Address: 0x1000C960
// Name: WriteShaderFiles
// Source: json
//------------------------------------------------------------------------------
void __cdecl WriteShaderFiles(const char *pShaderName)
{
  int m_Id; // esi
  const char *v2; // esi
  int v3; // esi
  int v4; // esi
  CfgProcessor::CfgEntryInfo *m_p; // esi
  const char *m_szName; // eax
  int v7; // edi
  CUtlNodeHash<CStaticCombo,7097,unsigned __int64> *v8; // esi
  int v9; // ecx
  int *p_m_nGrowSize; // eax
  CStaticCombo **p_m_pHead; // esi
  CStaticCombo *v12; // eax
  CStaticCombo *j; // ecx
  int *v14; // eax
  int v15; // edi
  const void *v16; // esi
  int v17; // eax
  StaticComboAuxInfo_t *v18; // edi
  unsigned __int8 *v19; // ecx
  int v20; // edx
  unsigned __int8 *v21; // esi
  int v22; // eax
  unsigned int v23; // eax
  unsigned __int8 *v24; // esi
  _DWORD *v25; // ecx
  int m_Size; // esi
  StaticComboAuxInfo_t *m_pMemory; // edi
  StaticComboAuxInfo_t *v28; // esi
  int v29; // edi
  int v30; // eax
  int *v31; // esi
  int v32; // ebx
  int v33; // eax
  _DWORD *v34; // edi
  bool v35; // zf
  int v36; // edi
  bool v37; // al
  int v38; // eax
  unsigned int m_nStaticComboID; // edi
  int v40; // esi
  int v41; // eax
  StaticComboAliasRecord_t *v42; // eax
  int v43; // ebx
  int v44; // esi
  StaticComboAliasRecord_t *v45; // ebx
  unsigned int v46; // esi
  unsigned int m_nSourceStaticCombo; // esi
  StaticComboAuxInfo_t *v48; // edi
  CUtlNodeHash<CStaticCombo,7097,unsigned __int64> *v49; // ebx
  unsigned int v50; // ecx
  CStaticCombo *m_pHead; // eax
  int *v52; // eax
  _iobuf *v53; // edi
  unsigned __int8 *v54; // esi
  int k; // ebx
  CUtlNodeHash<CStaticCombo,7097,unsigned __int64> *v56; // esi
  char *v57; // esi
  int m; // ebx
  void *v59; // eax
  int v60; // [esp-Ch] [ebp-7E8h]
  CUtlVector<int,CUtlMemory<int,int> > comboIndicesHashedByCRC32[73]; // [esp+4h] [ebp-7D8h] BYREF
  char v62; // [esp+5B8h] [ebp-224h] BYREF
  char szVCSfilename[260]; // [esp+5BCh] [ebp-220h] BYREF
  char chShaderName[36]; // [esp+6C0h] [ebp-11Ch] BYREF
  StaticComboAuxInfo_t Hdr; // [esp+6E4h] [ebp-F8h] BYREF
  ShaderInfo_t shaderInfo; // [esp+6F4h] [ebp-E8h] BYREF
  __int64 m_nStaticComboID_low; // [esp+734h] [ebp-A8h]
  unsigned __int64 v68; // [esp+73Ch] [ebp-A0h]
  int v69; // [esp+744h] [ebp-98h] BYREF
  int inputBuffer; // [esp+748h] [ebp-94h] BYREF
  CUtlNodeHash<CStaticCombo,7097,unsigned __int64> *pByteCodeArray; // [esp+74Ch] [ebp-90h]
  CUtlVector<StaticComboAliasRecord_t,CUtlMemory<StaticComboAliasRecord_t,int> > duplicateCombos; // [esp+750h] [ebp-8Ch] BYREF
  CUtlStreamBuffer ShaderFile; // [esp+764h] [ebp-78h] BYREF
  _DWORD *v74; // [esp+7A4h] [ebp-38h] BYREF
  int i; // [esp+7A8h] [ebp-34h] BYREF
  CUtlSymbol v76[2]; // [esp+7ACh] [ebp-30h] BYREF
  CUtlSymbol v77[2]; // [esp+7B0h] [ebp-2Ch] BYREF
  CUtlSymbol v78[2]; // [esp+7B4h] [ebp-28h] BYREF
  int m_nFileOffset; // [esp+7B8h] [ebp-24h] BYREF
  CUtlVector<StaticComboAuxInfo_t,CUtlMemory<StaticComboAuxInfo_t,int> > StaticComboHeaders; // [esp+7BCh] [ebp-20h] BYREF
  unsigned int pulCRC; // [esp+7D0h] [ebp-Ch] BYREF
  bool bShaderFailed; // [esp+7D7h] [ebp-5h]
  CStaticCombo *pStatic; // [esp+7D8h] [ebp-4h] BYREF

  if ( CUtlSymbolTable::Find(
         this: &g_Master_ShaderWrittenToDisk.m_SymbolTable,
         result: (CUtlSymbol *)&v74 + 1,
         pString: pShaderName)->m_Id != 0xFFFF )
    return;
  CUtlSymbolTable::AddString(this: &g_Master_ShaderWrittenToDisk.m_SymbolTable, result: v78, pString: pShaderName);
  m_Id = v78[0].m_Id;
  if ( g_Master_ShaderWrittenToDisk.m_Vector.m_Size <= v78[0].m_Id )
    CUtlVector<bool,CUtlMemory<bool,int>>::EnsureCount(
      this: &g_Master_ShaderWrittenToDisk.m_Vector,
      num: v78[0].m_Id + 1);
  g_Master_ShaderWrittenToDisk.m_Vector.m_Memory.m_pMemory[m_Id] = true;
  v2 = "Removing failed";
  bShaderFailed = CUtlSymbolTable::Find(
                    this: &g_Master_ShaderHadError.m_SymbolTable,
                    result: (CUtlSymbol *)&pStatic + 1,
                    pString: pShaderName)->m_Id != 0xFFFF;
  if ( !bShaderFailed )
    v2 = "Writing";
  if ( `anonymous namespace'::g_numCommandsCompleted >= `anonymous namespace'::g_numCompileCommands )
  {
    V_snprintf(pDest: chShaderName, maxLen: 29, pFormat: "%s...", pShaderName);
    sprintf(string: &chShaderName[28], format: "...");
    _Msg(a1: "\r%s %s   \r", v2, chShaderName);
  }
  else
  {
    _Msg(a1: "\b%c", chProgress[++iProgressSymbol % 4]);
  }
  if ( Threading::g_mtxGlobal.m_pUseMtx.m_value != nullptr )
    EnterCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)Threading::g_mtxGlobal.m_pUseMtx.m_value);
  CUtlSymbolTable::AddString(this: &g_ShaderByteCode.m_SymbolTable, result: v76, pString: pShaderName);
  v3 = v76[0].m_Id;
  if ( g_ShaderByteCode.m_Vector.m_Size <= v76[0].m_Id && g_ShaderByteCode.m_Vector.m_Size < v76[0].m_Id + 1 )
    CUtlVector<CUtlNodeHash<CStaticCombo,7097,unsigned __int64> *,CUtlMemory<CUtlNodeHash<CStaticCombo,7097,unsigned __int64> *,int>>::InsertMultipleBefore(
      this: &g_ShaderByteCode.m_Vector,
      elem: g_ShaderByteCode.m_Vector.m_Size,
      num: v76[0].m_Id + 1 - g_ShaderByteCode.m_Vector.m_Size);
  pByteCodeArray = g_ShaderByteCode.m_Vector.m_Memory.m_pMemory[v3];
  g_ShaderByteCode.m_Vector.m_Memory.m_pMemory[v3] = nullptr;
  CUtlSymbolTable::AddString(this: &g_ShaderToShaderInfo.m_SymbolTable, result: v77, pString: pShaderName);
  v4 = v77[0].m_Id;
  if ( g_ShaderToShaderInfo.m_Vector.m_Size <= v77[0].m_Id && g_ShaderToShaderInfo.m_Vector.m_Size < v77[0].m_Id + 1 )
    CUtlVector<ShaderInfo_t,CUtlMemory<ShaderInfo_t,int>>::InsertMultipleBefore(
      this: &g_ShaderToShaderInfo.m_Vector,
      elem: g_ShaderToShaderInfo.m_Vector.m_Size,
      num: v77[0].m_Id + 1 - g_ShaderToShaderInfo.m_Vector.m_Size);
  shaderInfo = g_ShaderToShaderInfo.m_Vector.m_Memory.m_pMemory[v4];
  if ( shaderInfo.m_pShaderName == nullptr )
  {
    m_p = `anonymous namespace'::g_arrCompileEntries.m_p;
    m_szName = `anonymous namespace'::g_arrCompileEntries.m_p->m_szName;
    if ( `anonymous namespace'::g_arrCompileEntries.m_p->m_szName != nullptr )
    {
      while ( strcmp(m_szName, pShaderName) != 0 )
      {
        m_szName = m_p[1].m_szName;
        ++m_p;
        if ( m_szName == nullptr )
          goto LABEL_26;
      }
      Shader_ParseShaderInfoFromCompileCommands(pEntry: m_p, &shaderInfo);
      CUtlSymbolTable::AddString(
        this: &g_ShaderToShaderInfo.m_SymbolTable,
        result: (CUtlSymbol *)&i,
        pString: pShaderName);
      v7 = (unsigned __int16)i;
      if ( g_ShaderToShaderInfo.m_Vector.m_Size <= (unsigned __int16)i
        && g_ShaderToShaderInfo.m_Vector.m_Size < (unsigned __int16)i + 1 )
      {
        CUtlVector<ShaderInfo_t,CUtlMemory<ShaderInfo_t,int>>::InsertMultipleBefore(
          this: &g_ShaderToShaderInfo.m_Vector,
          elem: g_ShaderToShaderInfo.m_Vector.m_Size,
          num: (unsigned __int16)i + 1 - g_ShaderToShaderInfo.m_Vector.m_Size);
      }
      g_ShaderToShaderInfo.m_Vector.m_Memory.m_pMemory[v7] = shaderInfo;
    }
  }
LABEL_26:
  if ( Threading::g_mtxGlobal.m_pUseMtx.m_value != nullptr )
    LeaveCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)Threading::g_mtxGlobal.m_pUseMtx.m_value);
  if ( shaderInfo.m_pShaderName != nullptr )
  {
    GetVCSFilenames(pszMainOutFileName: szVCSfilename, si: &shaderInfo);
    if ( bShaderFailed )
    {
      DebugOut(pMsg: "Removing failed shader file \"%s\".\n", szVCSfilename);
      unlink(path: szVCSfilename);
      return;
    }
    v8 = pByteCodeArray;
    if ( pByteCodeArray != nullptr )
    {
      DebugOut(
        pMsg: "%s : %I64u combos centroid mask: 0x%x numDynamicCombos: %I64u flags: 0x%x\n",
        pShaderName,
        shaderInfo.m_nTotalShaderCombos,
        shaderInfo.m_CentroidMask,
        shaderInfo.m_nDynamicCombos,
        shaderInfo.m_Flags);
      v60 = v8->m_nNumNodes + 1;
      memset(&StaticComboHeaders, 0, sizeof(StaticComboHeaders));
      CUtlVector<StaticComboAuxInfo_t,CUtlMemory<StaticComboAuxInfo_t,int>>::EnsureCapacity(
        this: &StaticComboHeaders,
        num: v60);
      v9 = 72;
      p_m_nGrowSize = &comboIndicesHashedByCRC32[0].m_Memory.m_nGrowSize;
      do
      {
        *(p_m_nGrowSize - 2) = 0;
        *(p_m_nGrowSize - 1) = 0;
        *p_m_nGrowSize = 0;
        p_m_nGrowSize[1] = 0;
        p_m_nGrowSize[2] = 0;
        p_m_nGrowSize += 5;
        --v9;
      }
      while ( v9 >= 0 );
      p_m_pHead = &v8->m_HashChains[0].m_pHead;
      memset(&duplicateCombos, 0, sizeof(duplicateCombos));
      *(_DWORD *)&v76[0].m_Id = p_m_pHead;
      *(_DWORD *)&v78[0].m_Id = 7097;
      while ( 1 )
      {
        v12 = *p_m_pHead;
        pStatic = v12;
        if ( v12 == nullptr )
          goto LABEL_81;
        for ( j = v12; j != nullptr; pStatic = j )
        {
          v14 = (int *)j->m_abPackedCode.m_p;
          if ( v14 == nullptr || *v14 == 0 )
            goto LABEL_80;
          m_nStaticComboID_low = LODWORD(j->m_nStaticComboID);
          v15 = *v14;
          v16 = v14 + 1;
          CRC32_Init(&pulCRC);
          CRC32_ProcessBuffer(&pulCRC, pBuffer: v16, nBuffer: v15);
          CRC32_Final(&pulCRC);
          *(_DWORD *)&v77[0].m_Id = 20 * (pulCRC % 0x49);
          v17 = *(int *)((char *)&comboIndicesHashedByCRC32[0].m_Size + *(_DWORD *)&v77[0].m_Id);
          v68 = __PAIR64__((unsigned int)pStatic, pulCRC);
          i = 0;
          inputBuffer = v17;
          if ( v17 <= 0 )
          {
LABEL_68:
            m_Size = StaticComboHeaders.m_Size;
            if ( StaticComboHeaders.m_Size + 1 > StaticComboHeaders.m_Memory.m_nAllocationCount )
              CUtlMemory<UtlLinkedListElem_t<CWorkUnitInfo,int>,int>::Grow(
                this: (CUtlMemory<CWorkUnitWalker::CWorkerInfo,int> *)&StaticComboHeaders,
                num: StaticComboHeaders.m_Size - StaticComboHeaders.m_Memory.m_nAllocationCount + 1);
            m_pMemory = StaticComboHeaders.m_Memory.m_pMemory;
            ++StaticComboHeaders.m_Size;
            StaticComboHeaders.m_pElements = StaticComboHeaders.m_Memory.m_pMemory;
            if ( StaticComboHeaders.m_Size - m_Size - 1 > 0 )
              _V_memmove(
                dest: &StaticComboHeaders.m_Memory.m_pMemory[m_Size + 1],
                src: &StaticComboHeaders.m_Memory.m_pMemory[m_Size],
                count: 16 * (StaticComboHeaders.m_Size - m_Size - 1));
            v28 = &m_pMemory[m_Size];
            if ( v28 != nullptr )
            {
              v28->StaticComboRecord_t = (StaticComboRecord_t)m_nStaticComboID_low;
              *(_QWORD *)&v28->m_nCRC32 = v68;
            }
            v29 = *(int *)((char *)&comboIndicesHashedByCRC32[0].m_Size + *(_DWORD *)&v77[0].m_Id);
            v30 = *(int *)((char *)&comboIndicesHashedByCRC32[0].m_Memory.m_nAllocationCount + *(_DWORD *)&v77[0].m_Id);
            v31 = (int *)((char *)comboIndicesHashedByCRC32 + *(_DWORD *)&v77[0].m_Id);
            if ( v29 + 1 > v30 )
              CUtlMemory<int,int>::Grow(
                this: (CUtlMemory<CTCPPacket *,int> *)((char *)comboIndicesHashedByCRC32 + *(_DWORD *)&v77[0].m_Id),
                num: v29 - v30 + 1);
            ++v31[3];
            v32 = *v31;
            v33 = v31[3] - v29 - 1;
            v31[4] = *v31;
            if ( v33 > 0 )
              _V_memmove(dest: (void *)(v32 + 4 * v29 + 4), src: (const void *)(v32 + 4 * v29), count: 4 * v33);
            v34 = (_DWORD *)(v32 + 4 * v29);
            if ( v34 != nullptr )
              *v34 = StaticComboHeaders.m_Size - 1;
            goto LABEL_80;
          }
          v74 = *(int **)((char *)&comboIndicesHashedByCRC32[0].m_Memory.m_pMemory + *(_DWORD *)&v77[0].m_Id);
          while ( 1 )
          {
            v18 = &StaticComboHeaders.m_Memory.m_pMemory[*v74];
            if ( v18->m_nCRC32 == pulCRC )
            {
              v19 = v18->m_pByteCode->m_abPackedCode.m_p;
              v20 = v19 != nullptr ? *(_DWORD *)v19 : 0;
              v21 = pStatic->m_abPackedCode.m_p;
              v22 = v21 != nullptr ? *(_DWORD *)v21 : 0;
              if ( v20 == v22 )
              {
                if ( v19 != nullptr )
                  v23 = *(_DWORD *)v19;
                else
                  v23 = 0;
                if ( v21 != nullptr )
                  v24 = v21 + 4;
                else
                  v24 = nullptr;
                if ( v19 != nullptr )
                  v25 = v19 + 4;
                else
                  v25 = nullptr;
                if ( v23 >= 4 )
                {
                  while ( *v25 == *(_DWORD *)v24 )
                  {
                    v23 -= 4;
                    v24 += 4;
                    ++v25;
                    if ( v23 < 4 )
                      goto LABEL_61;
                  }
                  goto LABEL_67;
                }
LABEL_61:
                if ( v23 == 0
                  || *v24 == *(_BYTE *)v25
                  && (v23 <= 1 || v24[1] == *((_BYTE *)v25 + 1) && (v23 <= 2 || v24[2] == *((_BYTE *)v25 + 2))) )
                {
                  break;
                }
              }
            }
LABEL_67:
            ++v74;
            if ( ++i >= inputBuffer )
              goto LABEL_68;
          }
          v38 = duplicateCombos.m_Size;
          m_nStaticComboID = v18->m_nStaticComboID;
          v40 = duplicateCombos.m_Size;
          if ( duplicateCombos.m_Size + 1 > duplicateCombos.m_Memory.m_nAllocationCount )
          {
            CUtlMemory<CTransmitRateMgr::CMachineRecord,int>::Grow(
              this: (CUtlMemory<CTransmitRateMgr::CMachineRecord,int> *)&duplicateCombos,
              num: duplicateCombos.m_Size - duplicateCombos.m_Memory.m_nAllocationCount + 1);
            v38 = duplicateCombos.m_Size;
          }
          duplicateCombos.m_Size = v38 + 1;
          v41 = v38 - v40;
          duplicateCombos.m_pElements = duplicateCombos.m_Memory.m_pMemory;
          if ( v41 > 0 )
            _V_memmove(
              dest: &duplicateCombos.m_Memory.m_pMemory[v40 + 1],
              src: &duplicateCombos.m_Memory.m_pMemory[v40],
              count: 8 * v41);
          v42 = &duplicateCombos.m_Memory.m_pMemory[v40];
          if ( v42 != nullptr )
          {
            v42->m_nStaticComboID = m_nStaticComboID_low;
            v42->m_nSourceStaticCombo = m_nStaticComboID;
          }
LABEL_80:
          j = pStatic->m_pNext;
        }
LABEL_81:
        p_m_pHead = (CStaticCombo **)(*(_DWORD *)&v76[0].m_Id + 4);
        v35 = (*(_DWORD *)&v78[0].m_Id)-- == 1;
        *(_DWORD *)&v76[0].m_Id += 4;
        if ( v35 )
        {
          v36 = 0;
          Hdr.m_nStaticComboID = -1;
          Hdr.m_nFileOffset = 0;
          CUtlVector<StaticComboAuxInfo_t,CUtlMemory<StaticComboAuxInfo_t,int>>::InsertBefore(
            this: (CUtlVector<CWorkUnitEvent,CUtlMemory<CWorkUnitEvent,int> > *)&StaticComboHeaders,
            elem: StaticComboHeaders.m_Size,
            src: (const CWorkUnitEvent *)&Hdr);
          CUtlVector<StaticComboAuxInfo_t,CUtlMemory<StaticComboAuxInfo_t,int>>::Sort(
            this: &StaticComboHeaders,
            pfnCompare: (int (__cdecl *)(const void *, const void *))CompareComboIds);
          CUtlStreamBuffer::CUtlStreamBuffer(
            this: &ShaderFile,
            pFileName: szVCSfilename,
            pPath: nullptr,
            nFlags: 0,
            bDelayOpen: false,
            nOpenFileFlags: 0);
          v37 = g_bIsX360 || g_bIsPS3;
          CUtlBuffer::SetBigEndian(this: &ShaderFile, bigEndian: v37);
          if ( (ShaderFile.m_Flags & 1) != 0 )
            CUtlBuffer::Printf(this: &ShaderFile, pFmt: "%d", 6);
          else
            CUtlBuffer::PutTypeBin<int>(this: &ShaderFile, src: 6);
          if ( (ShaderFile.m_Flags & 1) != 0 )
            CUtlBuffer::Printf(this: &ShaderFile, pFmt: "%d", LODWORD(shaderInfo.m_nTotalShaderCombos));
          else
            CUtlBuffer::PutTypeBin<int>(this: &ShaderFile, src: shaderInfo.m_nTotalShaderCombos);
          if ( (ShaderFile.m_Flags & 1) != 0 )
            CUtlBuffer::Printf(this: &ShaderFile, pFmt: "%d", LODWORD(shaderInfo.m_nDynamicCombos));
          else
            CUtlBuffer::PutTypeBin<int>(this: &ShaderFile, src: shaderInfo.m_nDynamicCombos);
          if ( (ShaderFile.m_Flags & 1) != 0 )
            CUtlBuffer::Printf(this: &ShaderFile, pFmt: "%u", shaderInfo.m_Flags);
          else
            CUtlBuffer::PutTypeBin<int>(this: &ShaderFile, src: shaderInfo.m_Flags);
          if ( (ShaderFile.m_Flags & 1) != 0 )
            CUtlBuffer::Printf(this: &ShaderFile, pFmt: "%u", shaderInfo.m_CentroidMask);
          else
            CUtlBuffer::PutTypeBin<int>(this: &ShaderFile, src: shaderInfo.m_CentroidMask);
          v43 = StaticComboHeaders.m_Size;
          if ( (ShaderFile.m_Flags & 1) != 0 )
            CUtlBuffer::Printf(this: &ShaderFile, pFmt: "%u", StaticComboHeaders.m_Size);
          else
            CUtlBuffer::PutTypeBin<int>(this: &ShaderFile, src: StaticComboHeaders.m_Size);
          if ( (ShaderFile.m_Flags & 1) != 0 )
            CUtlBuffer::Printf(this: &ShaderFile, pFmt: "%u", 0);
          else
            CUtlBuffer::PutTypeBin<int>(this: &ShaderFile, src: 0);
          pStatic = (CStaticCombo *)ShaderFile.m_Put;
          CUtlBuffer::Put(this: &ShaderFile, pMem: StaticComboHeaders.m_Memory.m_pMemory, size: 8 * v43);
          v44 = duplicateCombos.m_Size;
          if ( (ShaderFile.m_Flags & 1) != 0 )
            CUtlBuffer::Printf(this: &ShaderFile, pFmt: "%u", duplicateCombos.m_Size);
          else
            CUtlBuffer::PutTypeBin<int>(this: &ShaderFile, src: duplicateCombos.m_Size);
          CUtlVector<StaticComboAliasRecord_t,CUtlMemory<StaticComboAliasRecord_t,int>>::Sort(
            this: &duplicateCombos,
            pfnCompare: (int (__cdecl *)(const void *, const void *))CompareComboIds);
          if ( v44 > 0 )
          {
            v45 = duplicateCombos.m_Memory.m_pMemory;
            do
            {
              v46 = v45[v36].m_nStaticComboID;
              if ( (ShaderFile.m_Flags & 1) != 0 )
              {
                CUtlBuffer::Printf(this: &ShaderFile, pFmt: "%u", v45[v36].m_nStaticComboID);
              }
              else
              {
                inputBuffer = v45[v36].m_nStaticComboID;
                if ( CUtlBuffer::CheckPut(this: &ShaderFile, nSize: 4) )
                {
                  if ( (*(_BYTE *)&ShaderFile.m_Byteswap & 1) != 0 )
                    CByteswap::SwapBufferToTargetEndian<unsigned int>(
                      this: &ShaderFile.m_Byteswap,
                      outputBuffer: (int *)&ShaderFile.m_Memory.m_pMemory[ShaderFile.m_Put - ShaderFile.m_nOffset],
                      &inputBuffer,
                      count: 1);
                  else
                    *(_DWORD *)&ShaderFile.m_Memory.m_pMemory[ShaderFile.m_Put - ShaderFile.m_nOffset] = v46;
                  ShaderFile.m_Put += 4;
                  CUtlBuffer::AddNullTermination(this: &ShaderFile, nPut: ShaderFile.m_Put);
                }
              }
              m_nSourceStaticCombo = v45[v36].m_nSourceStaticCombo;
              if ( (ShaderFile.m_Flags & 1) != 0 )
              {
                CUtlBuffer::Printf(this: &ShaderFile, pFmt: "%u", v45[v36].m_nSourceStaticCombo);
              }
              else
              {
                v69 = v45[v36].m_nSourceStaticCombo;
                if ( CUtlBuffer::CheckPut(this: &ShaderFile, nSize: 4) )
                {
                  if ( (*(_BYTE *)&ShaderFile.m_Byteswap & 1) != 0 )
                    CByteswap::SwapBufferToTargetEndian<unsigned int>(
                      this: &ShaderFile.m_Byteswap,
                      outputBuffer: (int *)&ShaderFile.m_Memory.m_pMemory[ShaderFile.m_Put - ShaderFile.m_nOffset],
                      inputBuffer: &v69,
                      count: 1);
                  else
                    *(_DWORD *)&ShaderFile.m_Memory.m_pMemory[ShaderFile.m_Put - ShaderFile.m_nOffset] = m_nSourceStaticCombo;
                  ShaderFile.m_Put += 4;
                  CUtlBuffer::AddNullTermination(this: &ShaderFile, nPut: ShaderFile.m_Put);
                }
              }
              ++v36;
            }
            while ( v36 < duplicateCombos.m_Size );
            v43 = StaticComboHeaders.m_Size;
          }
          if ( v43 > 0 )
          {
            v48 = StaticComboHeaders.m_Memory.m_pMemory;
            v49 = pByteCodeArray;
            pulCRC = StaticComboHeaders.m_Size;
            do
            {
              v50 = v48->m_nStaticComboID;
              v48->m_nFileOffset = ShaderFile.m_Put;
              if ( v50 != -1 )
              {
                m_pHead = v49->m_HashChains[v50 % 0x1BB9].m_pHead;
                if ( m_pHead != nullptr )
                {
                  while ( LODWORD(m_pHead->m_nStaticComboID) != v50 || HIDWORD(m_pHead->m_nStaticComboID) != 0 )
                  {
                    m_pHead = m_pHead->m_pNext;
                    if ( m_pHead == nullptr )
                      goto LABEL_141;
                  }
                }
                else
                {
LABEL_141:
                  m_pHead = nullptr;
                }
                v52 = (int *)m_pHead->m_abPackedCode.m_p;
                if ( v52 != nullptr && *v52 != 0 )
                  CUtlBuffer::Put(this: &ShaderFile, pMem: v52 + 1, size: *v52);
                if ( (ShaderFile.m_Flags & 1) != 0 )
                {
                  CUtlBuffer::Printf(this: &ShaderFile, pFmt: "%d", -1);
                }
                else
                {
                  m_nFileOffset = -1;
                  if ( CUtlBuffer::CheckPut(this: &ShaderFile, nSize: 4) )
                  {
                    if ( (*(_BYTE *)&ShaderFile.m_Byteswap & 1) != 0 )
                      CByteswap::SwapBufferToTargetEndian<unsigned int>(
                        this: &ShaderFile.m_Byteswap,
                        outputBuffer: (int *)&ShaderFile.m_Memory.m_pMemory[ShaderFile.m_Put - ShaderFile.m_nOffset],
                        inputBuffer: &m_nFileOffset,
                        count: 1);
                    else
                      *(_DWORD *)&ShaderFile.m_Memory.m_pMemory[ShaderFile.m_Put - ShaderFile.m_nOffset] = -1;
                    ShaderFile.m_Put += 4;
                    CUtlBuffer::AddNullTermination(this: &ShaderFile, nPut: ShaderFile.m_Put);
                  }
                }
              }
              if ( g_bIsX360 || g_bIsPS3 )
              {
                m_nFileOffset = v48->m_nFileOffset;
                v48->m_nFileOffset = _byteswap_ulong(m_nFileOffset);
                m_nFileOffset = v48->m_nStaticComboID;
                v48->m_nStaticComboID = _byteswap_ulong(m_nFileOffset);
              }
              ++v48;
              --pulCRC;
            }
            while ( pulCRC != 0 );
          }
          CUtlStreamBuffer::Close(this: &ShaderFile);
          v53 = fopen(file: (_iobuf *)szVCSfilename, mode: "rb+");
          if ( v53 == nullptr )
            printf(format: " failed to re-open %s\n", szVCSfilename);
          fseek(stream: v53, offset: (int)pStatic, whence: 0);
          if ( StaticComboHeaders.m_Size > 0 )
          {
            v54 = (unsigned __int8 *)StaticComboHeaders.m_Memory.m_pMemory;
            for ( k = StaticComboHeaders.m_Size; k != 0; --k )
            {
              fwrite(buffer: v54, size: 4u, count: 1u, stream: v53);
              fwrite(buffer: v54 + 4, size: 4u, count: 1u, stream: v53);
              v54 += 16;
            }
          }
          fclose(stream: v53);
          v56 = pByteCodeArray;
          CUtlNodeHash<CStaticCombo,7097,unsigned __int64>::Purge(this: pByteCodeArray);
          free(pMem: v56);
          if ( `anonymous namespace'::g_numCommandsCompleted >= `anonymous namespace'::g_numCompileCommands )
            _Msg(a1: "\r                                                                \r");
          CUtlStreamBuffer::~CUtlStreamBuffer(this: &ShaderFile);
          if ( duplicateCombos.m_Memory.m_nGrowSize >= 0 && duplicateCombos.m_Memory.m_pMemory != nullptr )
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: duplicateCombos.m_Memory.m_pMemory);
          v57 = &v62;
          for ( m = 72; m >= 0; --m )
          {
            v57 -= 20;
            *((_DWORD *)v57 + 3) = 0;
            if ( *((int *)v57 + 2) >= 0 )
            {
              if ( *(_DWORD *)v57 != 0 )
              {
                _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: *(void **)v57);
                *(_DWORD *)v57 = 0;
              }
              *((_DWORD *)v57 + 1) = 0;
            }
            v59 = *(void **)v57;
            *((_DWORD *)v57 + 4) = *(_DWORD *)v57;
            if ( *((int *)v57 + 2) >= 0 )
            {
              if ( v59 != nullptr )
              {
                _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v59);
                *(_DWORD *)v57 = 0;
              }
              *((_DWORD *)v57 + 1) = 0;
            }
          }
          if ( StaticComboHeaders.m_Memory.m_nGrowSize >= 0 && StaticComboHeaders.m_Memory.m_pMemory != nullptr )
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: StaticComboHeaders.m_Memory.m_pMemory);
          return;
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000D530
// Name: private: void CDistributeShaderCompileMaster::ThreadProc(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDistributeShaderCompileMaster::ThreadProc(CDistributeShaderCompileMaster *this)
{
  DWORD CurrentThreadId; // eax
  const char *v3; // eax
  int numShadersWritten; // [esp+4h] [ebp-4h]

  while ( this->m_bRunning != 0 )
  {
    WaitForSingleObject(hHandle: this->m_hEvent, dwMilliseconds: 0xFFFFFFFF);
    for ( numShadersWritten = 0; ; ++numShadersWritten )
    {
      CurrentThreadId = GetCurrentThreadId();
      if ( CurrentThreadId != this->m_mtx.m_ownerID
        && _InterlockedCompareExchange((volatile signed __int32 *)&this->m_mtx, CurrentThreadId, 0) != 0 )
      {
        _mm_pause();
        CThreadFastMutex::Lock(a1: &this->m_mtx, a2: CurrentThreadId, a3: 0);
      }
      else
      {
        ++this->m_mtx.m_depth;
      }
      v3 = nullptr;
      if ( this->m_arrShaderNamesToWrite.m_Size <= numShadersWritten )
        this->m_arrShaderNamesToWrite.m_Size = 0;
      else
        v3 = this->m_arrShaderNamesToWrite.m_Memory.m_pMemory[numShadersWritten];
      if ( this->m_mtx.m_depth-- == 1 )
        _InterlockedExchange((volatile __int32 *)&this->m_mtx, 0);
      if ( v3 == nullptr )
        break;
      WriteShaderFiles(pShaderName: v3);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000D5D0
// Name: public: void CWorkerAccumState<class CThreadFastMutex>::ExecuteCompileCommandThreaded(struct CfgProcessor::_unnamed_type_ComboHandle_ __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWorkerAccumState<CThreadFastMutex>::ExecuteCompileCommandThreaded(
        CWorkerAccumState<CThreadFastMutex> *this,
        CfgProcessor::<unnamed_type_ComboHandle> *hCombo)
{
  char *v3; // eax
  const void *v4; // esi
  HANDLE CurrentProcess; // eax
  CfgProcessor::CfgEntryInfo *v6; // eax
  CSubProcessResponse *v7; // eax
  SubProcessKernelObjects_Memory shrmem; // [esp+8h] [ebp-10h] BYREF
  SubProcessKernelObjects *pCommObjs; // [esp+14h] [ebp-4h] BYREF

  pCommObjs = nullptr;
  CWorkerAccumState<CThreadFastMutex>::PrepareSubProcess(this, ppSp: nullptr, ppCommObjs: &pCommObjs);
  shrmem.m_pObjs = pCommObjs;
  shrmem.m_pMemory = nullptr;
  shrmem.m_pLockData = nullptr;
  v3 = (char *)SubProcessKernelObjects_Memory::Lock(this: &shrmem);
  CfgProcessor::Combo_FormatCommand(hCombo, pchBuffer: v3);
  SubProcessKernelObjects_Memory::Unlock(this: &shrmem);
  v4 = SubProcessKernelObjects_Memory::Lock(this: &shrmem);
  if ( v4 != nullptr )
  {
    v7 = (CSubProcessResponse *)operator new(nSize: 0x18u);
    if ( v7 != nullptr )
    {
      v6 = (CfgProcessor::CfgEntryInfo *)CSubProcessResponse::CSubProcessResponse(this: v7, pvMemory: v4);
      goto LABEL_7;
    }
LABEL_6:
    v6 = nullptr;
    goto LABEL_7;
  }
  CurrentProcess = GetCurrentProcess();
  TerminateProcess(hProcess: CurrentProcess, uExitCode: 1u);
  v6 = (CfgProcessor::CfgEntryInfo *)operator new(nSize: 4u);
  if ( v6 == nullptr )
    goto LABEL_6;
  v6->m_szName = (const char *)&CmdSink::CResponseError::`vftable';
LABEL_7:
  CWorkerAccumState<CThreadFastMutex>::HandleCommandResponse(this, hCombo, pResponse: v6);
  SubProcessKernelObjects_Memory::Unlock(this: &shrmem);
  SubProcessKernelObjects_Memory::Unlock(this: &shrmem);
}

//------------------------------------------------------------------------------
// Address: 0x1000D690
// Name: private: static unsigned long CDistributeShaderCompileMaster::ThreadProcAdapter(void __near *)
// Source: json
//------------------------------------------------------------------------------
unsigned int __stdcall CDistributeShaderCompileMaster::ThreadProcAdapter(CDistributeShaderCompileMaster *pvArg)
{
  CDistributeShaderCompileMaster::ThreadProc(this: pvArg);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1000D6B0
// Name: public: CDistributeShaderCompileMaster::CDistributeShaderCompileMaster(void)
// Source: json
//------------------------------------------------------------------------------
CDistributeShaderCompileMaster *__thiscall CDistributeShaderCompileMaster::CDistributeShaderCompileMaster(
        CDistributeShaderCompileMaster *this)
{
  this->__vftable = (CDistributeShaderCompileMaster_vtbl *)&CDistributeShaderCompileMaster::`vftable';
  this->m_hThread = nullptr;
  this->m_hEvent = nullptr;
  this->m_mtx.m_ownerID = 0;
  this->m_mtx.m_depth = 0;
  this->m_bRunning = 1;
  this->m_arrShaderNamesToWrite.m_Memory.m_pMemory = nullptr;
  this->m_arrShaderNamesToWrite.m_Memory.m_nAllocationCount = 0;
  this->m_arrShaderNamesToWrite.m_Memory.m_nGrowSize = 0;
  this->m_arrShaderNamesToWrite.m_Size = 0;
  this->m_arrShaderNamesToWrite.m_pElements = nullptr;
  this->m_hEvent = CreateEventA(lpEventAttributes: nullptr, bManualReset: false, bInitialState: false, lpName: nullptr);
  this->m_hThread = CreateThread(
                      lpThreadAttributes: nullptr,
                      dwStackSize: 0,
                      lpStartAddress: (LPTHREAD_START_ROUTINE)CDistributeShaderCompileMaster::ThreadProcAdapter,
                      lpParameter: this,
                      dwCreationFlags: 0,
                      lpThreadId: nullptr);
  this->m_pAnalyzeShaders = `anonymous namespace'::g_arrCompileEntries.m_p;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1000D710
// Name: public: bool CWorkerAccumState<class CThreadNullMutex>::OnProcessST(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CWorkerAccumState<CThreadNullMutex>::OnProcessST(CWorkerAccumState<CThreadNullMutex> *this)
{
  CfgProcessor::<unnamed_type_ComboHandle> *m_hCombo; // esi
  CfgProcessor::<unnamed_type_ComboHandle> **p_m_hCombo; // ebx
  char pchBuffer[4096]; // [esp+Ch] [ebp-1004h] BYREF
  CmdSink::IResponse *ppResponse; // [esp+100Ch] [ebp-4h] BYREF

  m_hCombo = this->m_hCombo;
  p_m_hCombo = &this->m_hCombo;
  if ( m_hCombo != nullptr )
  {
    do
    {
      ppResponse = nullptr;
      CfgProcessor::Combo_FormatCommand(hCombo: m_hCombo, pchBuffer);
      DebugOut(pMsg: "running: \"%s\"\n", pchBuffer);
      MySystem(pCommand: pchBuffer, &ppResponse);
      CWorkerAccumState<CThreadNullMutex>::HandleCommandResponse(
        this,
        hCombo: m_hCombo,
        pResponse: (const CfgProcessor::CfgEntryInfo *)ppResponse);
      CfgProcessor::Combo_GetNext(
        riCommandNumber: &this->m_iNextCommand,
        rhCombo: (ConfigurationProcessing::ComboHandleImpl **)p_m_hCombo,
        iCommandEnd: this->m_iEndCommand);
      m_hCombo = *p_m_hCombo;
    }
    while ( *p_m_hCombo != nullptr );
  }
  return false;
}

//------------------------------------------------------------------------------
// Address: 0x1000D7A0
// Name: private: void CParallelProcessorBase<class CWorkerAccumState<class CThreadFastMutex>>::DoExecute(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CParallelProcessorBase<CWorkerAccumState<CThreadFastMutex>>::DoExecute(
        CParallelProcessorBase<CWorkerAccumState<CThreadFastMutex> > *this)
{
  int v2; // edi
  DWORD CurrentThreadId; // ecx
  int v4; // eax
  bool v5; // zf
  int v6; // edi
  DWORD v7; // eax
  unsigned __int64 CommandNum; // rax
  int v9; // eax
  unsigned __int64 riCommandNumber; // [esp+Ch] [ebp-14h] BYREF
  CWorkerAccumState<CThreadFastMutex>::SubProcess *ppSp; // [esp+18h] [ebp-8h] BYREF
  CfgProcessor::<unnamed_type_ComboHandle> *hComboDst; // [esp+1Ch] [ebp-4h] BYREF

  v2 = *((_DWORD *)this + 1);
  CurrentThreadId = GetCurrentThreadId();
  if ( CurrentThreadId != *(_DWORD *)v2
    && _InterlockedCompareExchange((volatile signed __int32 *)v2, CurrentThreadId, 0) != 0 )
  {
    _mm_pause();
    CThreadFastMutex::Lock(a1: v2, a2: CurrentThreadId, a3: 0);
  }
  else
  {
    ++*(_DWORD *)(v2 + 4);
  }
  if ( *((_DWORD *)this + 16) != 0 )
    hComboDst = (CfgProcessor::<unnamed_type_ComboHandle> *)CfgProcessor::Combo_Alloc(hComboCopyFrom: *((CfgProcessor::<unnamed_type_ComboHandle> **)this + 16));
  else
    hComboDst = nullptr;
  v4 = *((_DWORD *)this + 1);
  v5 = (*(_DWORD *)(v4 + 4))-- == 1;
  if ( v5 )
    _InterlockedExchange((volatile __int32 *)v4, 0);
  riCommandNumber = -1;
  ppSp = nullptr;
  CWorkerAccumState<CThreadFastMutex>::PrepareSubProcess(
    (CWorkerAccumState<CThreadFastMutex> *)this,
    &ppSp,
    ppCommObjs: nullptr);
  while ( 1 )
  {
    v6 = *((_DWORD *)this + 1);
    v7 = GetCurrentThreadId();
    if ( v7 != *(_DWORD *)v6 && _InterlockedCompareExchange((volatile signed __int32 *)v6, v7, 0) != 0 )
    {
      _mm_pause();
      CThreadFastMutex::Lock(a1: v6, a2: v7, a3: 0);
    }
    else
    {
      ++*(_DWORD *)(v6 + 4);
    }
    if ( `CWorkerAccumState<CThreadFastMutex>::DisconnectState'::`2'::sb != 0 )
      CfgProcessor::Combo_Free(rhComboFree: (CfgProcessor::<unnamed_type_ComboHandle> **)this + 16);
    if ( *((_DWORD *)this + 16) != 0 )
    {
      CfgProcessor::Combo_Assign(hComboDst, hComboSrc: *((CfgProcessor::<unnamed_type_ComboHandle> **)this + 16));
      CommandNum = CfgProcessor::Combo_GetCommandNum(hCombo: hComboDst);
      ppSp->iRunningCommand = CommandNum;
      CfgProcessor::Combo_GetNext(
        &riCommandNumber,
        rhCombo: (ConfigurationProcessing::ComboHandleImpl **)this + 16,
        iCommandEnd: *((_QWORD *)this + 6));
    }
    else
    {
      CfgProcessor::Combo_Free(rhComboFree: &hComboDst);
      riCommandNumber = -1;
      ppSp->iRunningCommand = -1;
    }
    v9 = *((_DWORD *)this + 1);
    v5 = (*(_DWORD *)(v9 + 4))-- == 1;
    if ( v5 )
      _InterlockedExchange((volatile __int32 *)v9, 0);
    if ( hComboDst == nullptr )
      break;
    CWorkerAccumState<CThreadFastMutex>::ExecuteCompileCommandThreaded(
      (CWorkerAccumState<CThreadFastMutex> *)this,
      hCombo: hComboDst);
  }
  CfgProcessor::Combo_Free(rhComboFree: &hComboDst);
  _InterlockedExchangeAdd(&this->m_nActive.m_value, 0xFFFFFFFF);
}

//------------------------------------------------------------------------------
// Address: 0x1000D910
// Name: protected: void CParallelProcessorBase<class CWorkerAccumState<class CThreadFastMutex>>::Run(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CParallelProcessorBase<CWorkerAccumState<CThreadFastMutex>>::Run(
        CParallelProcessorBase<CWorkerAccumState<CThreadFastMutex> > *this,
        int nMaxParallel,
        int threadOverride)
{
  int v4; // ebx
  int v5; // eax
  CFunctor *v6; // eax

  v4 = _g_pThreadPool->NumIdleThreads(this: _g_pThreadPool);
  if ( nMaxParallel < v4 )
    v4 = nMaxParallel;
  if ( v4 <= 0 )
  {
    v5 = threadOverride;
  }
  else
  {
    do
    {
      v5 = threadOverride;
      --v4;
      if ( threadOverride == -1 || v4 == threadOverride - 1 )
      {
        _InterlockedExchangeAdd(&this->m_nActive.m_value, 1u);
        v6 = (CFunctor *)operator new(nSize: 0x18u);
        if ( v6 != nullptr )
        {
          v6[1].m_nUserID = 1;
          v6->__vftable = (CFunctor_vtbl *)&CMemberFunctor0<CParallelProcessorBase<CWorkerAccumState<CThreadFastMutex>> *,void (__thiscall CParallelProcessorBase<CWorkerAccumState<CThreadFastMutex>>::*)(void),CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>,CFuncMemPolicyNone>::`vftable'{for `CFunctor'};
          v6[1].__vftable = (CFunctor_vtbl *)&CMemberFunctor0<CParallelProcessorBase<CWorkerAccumState<CThreadFastMutex>> *,void (__thiscall CParallelProcessorBase<CWorkerAccumState<CThreadFastMutex>>::*)(void),CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>,CFuncMemPolicyNone>::`vftable'{for `CRefCountServiceBase<1,CRefMT>'};
          v6[2].__vftable = (CFunctor_vtbl *)CParallelProcessorBase<CWorkerAccumState<CThreadFastMutex>>::DoExecute;
          v6[2].m_nUserID = (unsigned int)this;
        }
        else
        {
          v6 = nullptr;
        }
        _g_pThreadPool->AddFunctorInternal(
          this: _g_pThreadPool,
          a2: v6,
          a3: (CJob **)&nMaxParallel,
          a4: nullptr,
          a5: 8u);
        (*(void (__thiscall **)(int))(*(_DWORD *)nMaxParallel + 4))(a1: nMaxParallel);
        v5 = threadOverride;
      }
    }
    while ( v4 > 0 );
  }
  if ( v5 == -1 || v5 == 0 )
  {
    _InterlockedExchangeAdd(&this->m_nActive.m_value, 1u);
    CParallelProcessorBase<CWorkerAccumState<CThreadFastMutex>>::DoExecute(this);
  }
  while ( this->m_nActive.m_value != 0 )
    _mm_pause();
}

//------------------------------------------------------------------------------
// Address: 0x1000D9E0
// Name: public: void Worker_ProcessCommandRange_Singleton::ProcessCommandRange(unsigned __int64,unsigned __int64)
// Source: json
//------------------------------------------------------------------------------
void __thiscall Worker_ProcessCommandRange_Singleton::ProcessCommandRange(
        Worker_ProcessCommandRange_Singleton *this,
        unsigned __int64 shaderStart,
        unsigned __int64 shaderEnd)
{
  CWorkerAccumState<CThreadFastMutex> *pWorkerObj; // esi
  CWorkerAccumState<CThreadNullMutex> *v4; // esi

  if ( this->m_MT.pThreadPool != nullptr )
  {
    pWorkerObj = this->m_MT.pWorkerObj;
    CWorkerAccumState<CThreadFastMutex>::RangeBegin(
      this: pWorkerObj,
      iFirstCommand: shaderStart,
      iEndCommand: shaderEnd);
    CParallelProcessorBase<CWorkerAccumState<CThreadFastMutex>>::Run(
      this: pWorkerObj,
      nMaxParallel: 0x7FFFFFFF,
      threadOverride: -1);
    if ( `CWorkerAccumState<CThreadFastMutex>::DisconnectState'::`2'::sb != 0 )
      CWorkerAccumState<CThreadFastMutex>::QuitSubs(this: pWorkerObj);
    else
      CWorkerAccumState<CThreadFastMutex>::TryToPackageData(
        this: pWorkerObj,
        iCommandNumber: pWorkerObj->m_iEndCommand - 1);
    g_fnDisconnectHandler = pWorkerObj->m_fnOldDisconnectHandler;
  }
  else
  {
    v4 = this->m_ST.pWorkerObj;
    CWorkerAccumState<CThreadNullMutex>::RangeBegin(this: v4, iFirstCommand: shaderStart, iEndCommand: shaderEnd);
    CWorkerAccumState<CThreadNullMutex>::OnProcessST(this: v4);
    if ( `CWorkerAccumState<CThreadNullMutex>::DisconnectState'::`2'::sb != 0 )
      CWorkerAccumState<CThreadNullMutex>::QuitSubs(this: v4);
    else
      CWorkerAccumState<CThreadNullMutex>::TryToPackageData(this: v4, iCommandNumber: v4->m_iEndCommand - 1);
    g_fnDisconnectHandler = v4->m_fnOldDisconnectHandler;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000DAC0
// Name: void Worker_ProcessWorkUnitFn(int,unsigned __int64,class MessageBuffer __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Worker_ProcessWorkUnitFn(int iThread, unsigned __int64 iWorkUnit, MessageBuffer *pBuf)
{
  unsigned __int64 v3; // kr00_8
  CfgProcessor::CfgEntryInfo *i; // edi
  unsigned int m_numStaticCombos_high; // edx
  unsigned int m_numStaticCombos; // esi
  unsigned __int64 v7; // rax
  CfgProcessor::CfgEntryInfo *m_p; // esi
  unsigned __int64 v9; // rcx
  unsigned __int64 v10; // rdi
  int v11; // ecx
  unsigned int m_nActualLength; // ebx
  int v13; // ecx
  int v14; // esi
  const char *v15; // edi
  unsigned int v16; // esi
  int v17; // esi
  const char *v18; // edi
  CompilerMsgInfo *v19; // esi
  const char *v20; // ebx
  CompilerMsgInfo *m_pMemory; // eax
  unsigned __int64 m_numDynamicCombos; // [esp-18h] [ebp-88h]
  char chNumReported[64]; // [esp+Ch] [ebp-64h] BYREF
  CUtlBinaryBlock v24; // [esp+4Ch] [ebp-24h] BYREF
  unsigned __int64 comboEnd; // [esp+5Ch] [ebp-14h]
  int kEnd; // [esp+64h] [ebp-Ch]
  signed int m_NumElements; // [esp+68h] [ebp-8h]
  int k; // [esp+6Ch] [ebp-4h]

  *(_QWORD *)&v24.m_Memory.m_nGrowSize = `anonymous namespace'::g_nStaticCombosPerWorkUnit * iWorkUnit;
  comboEnd = `anonymous namespace'::g_nStaticCombosPerWorkUnit * iWorkUnit
           + `anonymous namespace'::g_nStaticCombosPerWorkUnit;
  v3 = comboEnd;
  if ( `anonymous namespace'::g_numStaticCombos < comboEnd )
  {
    comboEnd = `anonymous namespace'::g_numStaticCombos;
    v3 = `anonymous namespace'::g_numStaticCombos;
  }
  for ( i = `anonymous namespace'::g_arrCompileEntries.m_p;
        i != nullptr;
        v3 -= __PAIR64__(m_numStaticCombos_high, m_numStaticCombos) )
  {
    if ( i->m_szName == nullptr )
      break;
    m_numStaticCombos_high = HIDWORD(i->m_numStaticCombos);
    m_numStaticCombos = i->m_numStaticCombos;
    if ( v3 < __PAIR64__(m_numStaticCombos_high, m_numStaticCombos) )
      break;
    ++i;
  }
  m_p = `anonymous namespace'::g_arrCompileEntries.m_p;
  v7 = i->m_iCommandStart + i->m_numDynamicCombos * v3;
  LODWORD(v9) = `anonymous namespace'::g_nStaticCombosPerWorkUnit * iWorkUnit;
  HIDWORD(v9) = v24.m_nActualLength;
  kEnd = `anonymous namespace'::g_nStaticCombosPerWorkUnit * iWorkUnit;
  if ( `anonymous namespace'::g_arrCompileEntries.m_p != nullptr )
  {
    do
    {
      if ( m_p->m_szName == nullptr )
        break;
      if ( v9 < m_p->m_numStaticCombos )
        break;
      v9 -= m_p->m_numStaticCombos;
      ++m_p;
    }
    while ( m_p != nullptr );
    kEnd = v9;
  }
  m_numDynamicCombos = m_p->m_numDynamicCombos;
  k = (int)m_p;
  Worker_ProcessCommandRange_Singleton::ProcessCommandRange(
    this: `Worker_ProcessCommandRange_Singleton::Instance'::`2'::s_ptr,
    shaderStart: m_p->m_iCommandStart + m_numDynamicCombos * v9,
    shaderEnd: v7);
  v10 = m_p->m_numStaticCombos - __PAIR64__(HIDWORD(v9), kEnd) - 1;
  v11 = 0;
  HIDWORD(iWorkUnit) = 0;
  kEnd = v24.m_Memory.m_nGrowSize;
  m_nActualLength = v24.m_nActualLength;
  if ( *(_QWORD *)&v24.m_Memory.m_nGrowSize < comboEnd )
  {
    do
    {
      if ( CopyWorkerReplyPackage(
             pEntry: (const CfgProcessor::CfgEntryInfo *)k,
             nComboOfEntry: v10,
             pBuf,
             nSkipsSoFar: v11) != 0 )
        v11 = 0;
      else
        v11 = HIDWORD(iWorkUnit) - 1;
      HIDWORD(iWorkUnit) = v11;
      if ( v10 == 0 )
      {
        v10 = *(_QWORD *)(k + 72);
        k += 48;
      }
      --v10;
      m_nActualLength = (__PAIR64__(m_nActualLength, kEnd++) + 1) >> 32;
    }
    while ( __PAIR64__(m_nActualLength, kEnd) < comboEnd );
    if ( v11 != 0 )
      MessageBuffer::write(this: pBuf, p: (char *)&iWorkUnit + 4, bytes: 4);
  }
  if ( g_bIsPS3 )
  {
    PS3SendShaderCompileLogContentsToMaster();
    if ( g_bGeneratePS3DebugInfo )
      SendSubDirectoryToMaster(pStartingPath: "cgc-capture");
  }
  LOWORD(v13) = 0;
  k = 0;
  m_NumElements = g_Master_ShaderHadError.m_SymbolTable.m_Lookup.m_NumElements;
  if ( g_Master_ShaderHadError.m_SymbolTable.m_Lookup.m_NumElements != 0 )
  {
    do
    {
      v14 = (unsigned __int16)v13;
      v15 = CUtlSymbolTable::String(this: &g_Master_ShaderHadError.m_SymbolTable, id: (CUtlSymbol)v13);
      if ( g_Master_ShaderHadError.m_Vector.m_Memory.m_pMemory[v14] )
      {
        v16 = strlen(v15);
        CUtlBinaryBlock::CUtlBinaryBlock(this: &v24, growSize: 0, initSize: 0);
        CUtlBinaryBlock::SetLength(this: &v24, nLength: v16 + 2);
        sprintf(string: (char *)v24.m_Memory.m_pMemory, format: "%c%s", 8, v15);
        VMPI_SendData(pData: v24.m_Memory.m_pMemory, nBytes: v24.m_nActualLength, iDest: 0, fVMPISendFlags: 0);
        VMPI_HandleSocketErrors(timeout: 0);
        v24.m_nActualLength = 0;
        if ( v24.m_Memory.m_nGrowSize >= 0 )
        {
          if ( v24.m_Memory.m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v24.m_Memory.m_pMemory);
            v24.m_Memory.m_pMemory = nullptr;
          }
          v24.m_Memory.m_nAllocationCount = 0;
        }
      }
      v13 = k + 1;
      k = v13;
    }
    while ( v13 < m_NumElements );
  }
  k = 0;
  HIDWORD(comboEnd) = g_Master_CompilerMsgInfo.m_SymbolTable.m_Lookup.m_NumElements;
  if ( g_Master_CompilerMsgInfo.m_SymbolTable.m_Lookup.m_NumElements != 0 )
  {
    do
    {
      v17 = (unsigned __int16)k;
      v18 = CUtlSymbolTable::String(this: &g_Master_CompilerMsgInfo.m_SymbolTable, id: (CUtlSymbol)k);
      v19 = &g_Master_CompilerMsgInfo.m_Vector.m_Memory.m_pMemory[v17];
      v20 = CUtlString::Get(this: &v19->m_sFirstCommand);
      sprintf(string: chNumReported, format: "%d", v19->m_numTimesReported);
      CUtlBinaryBlock::CUtlBinaryBlock(this: &v24, growSize: 0, initSize: 0);
      m_NumElements = strlen(v18);
      CUtlBinaryBlock::SetLength(this: &v24, nLength: strlen(v20) + strlen(chNumReported) + m_NumElements + 5);
      sprintf(string: (char *)v24.m_Memory.m_pMemory, format: "%c%s\n%s\n%s\n", 7, v18, v20, chNumReported);
      VMPI_SendData(pData: v24.m_Memory.m_pMemory, nBytes: v24.m_nActualLength, iDest: 0, fVMPISendFlags: 0);
      VMPI_HandleSocketErrors(timeout: 0);
      v24.m_nActualLength = 0;
      if ( v24.m_Memory.m_nGrowSize >= 0 )
      {
        if ( v24.m_Memory.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v24.m_Memory.m_pMemory);
          v24.m_Memory.m_pMemory = nullptr;
        }
        v24.m_Memory.m_nAllocationCount = 0;
      }
      ++k;
    }
    while ( k < SHIDWORD(comboEnd) );
  }
  CUtlVector<CompilerMsgInfo,CUtlMemory<CompilerMsgInfo,int>>::RemoveAll(this: &g_Master_CompilerMsgInfo.m_Vector);
  m_pMemory = g_Master_CompilerMsgInfo.m_Vector.m_Memory.m_pMemory;
  if ( g_Master_CompilerMsgInfo.m_Vector.m_Memory.m_nGrowSize >= 0 )
  {
    if ( g_Master_CompilerMsgInfo.m_Vector.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: g_Master_CompilerMsgInfo.m_Vector.m_Memory.m_pMemory);
      m_pMemory = nullptr;
      g_Master_CompilerMsgInfo.m_Vector.m_Memory.m_pMemory = nullptr;
    }
    g_Master_CompilerMsgInfo.m_Vector.m_Memory.m_nAllocationCount = 0;
  }
  g_Master_CompilerMsgInfo.m_Vector.m_pElements = m_pMemory;
  CUtlSymbolTable::RemoveAll(this: &g_Master_CompilerMsgInfo.m_SymbolTable);
}

//------------------------------------------------------------------------------
// Address: 0x1000DEA0
// Name: void CompileShaders_NoVMPI(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CompileShaders_NoVMPI()
{
  CfgProcessor::CfgEntryInfo *m_p; // ebx
  int m_Id; // edi
  int m_iCommandEnd_high; // eax
  bool v3; // zf
  const char *m_szName; // [esp-Ch] [ebp-180h]
  Worker_ProcessCommandRange_Singleton pcr; // [esp+4h] [ebp-170h] BYREF
  ShaderInfo_t siLastShaderInfo; // [esp+130h] [ebp-44h] BYREF
  CUtlSymbol result; // [esp+170h] [ebp-4h] BYREF

  Worker_ProcessCommandRange_Singleton::Worker_ProcessCommandRange_Singleton(this: &pcr);
  m_p = `anonymous namespace'::g_arrCompileEntries.m_p;
  if ( `anonymous namespace'::g_arrCompileEntries.m_p != nullptr )
  {
    do
    {
      if ( m_p->m_szName == nullptr )
        break;
      memset(dst: (int)&siLastShaderInfo, value: nullptr, count: sizeof(siLastShaderInfo));
      Shader_ParseShaderInfoFromCompileCommands(pEntry: m_p, shaderInfo: &siLastShaderInfo);
      CUtlSymbolTable::AddString(this: &g_ShaderToShaderInfo.m_SymbolTable, &result, pString: m_p->m_szName);
      m_Id = result.m_Id;
      if ( g_ShaderToShaderInfo.m_Vector.m_Size <= result.m_Id && g_ShaderToShaderInfo.m_Vector.m_Size < result.m_Id + 1 )
        CUtlVector<ShaderInfo_t,CUtlMemory<ShaderInfo_t,int>>::InsertMultipleBefore(
          this: &g_ShaderToShaderInfo.m_Vector,
          elem: g_ShaderToShaderInfo.m_Vector.m_Size,
          num: result.m_Id + 1 - g_ShaderToShaderInfo.m_Vector.m_Size);
      g_ShaderToShaderInfo.m_Vector.m_Memory.m_pMemory[m_Id] = siLastShaderInfo;
      Worker_ProcessCommandRange_Singleton::ProcessCommandRange(
        this: `Worker_ProcessCommandRange_Singleton::Instance'::`2'::s_ptr,
        shaderStart: m_p->m_iCommandStart,
        shaderEnd: m_p->m_iCommandEnd);
      m_szName = m_p->m_szName;
      `anonymous namespace'::g_numCommandsCompleted = `anonymous namespace'::g_numCompileCommands;
      WriteShaderFiles(pShaderName: m_szName);
      LODWORD(`anonymous namespace'::g_numCommandsCompleted) = m_p->m_iCommandEnd;
      m_iCommandEnd_high = HIDWORD(m_p->m_iCommandEnd);
      v3 = &m_p[1] == nullptr;
      ++m_p;
      HIDWORD(`anonymous namespace'::g_numCommandsCompleted) = m_iCommandEnd_high;
    }
    while ( !v3 );
  }
  _Msg(a1: "\r                                                  \r");
  `Worker_ProcessCommandRange_Singleton::Instance'::`2'::s_ptr = nullptr;
  Worker_ProcessCommandRange_Singleton::Shutdown(this: &pcr);
}

//------------------------------------------------------------------------------
// Address: 0x1000DFC0
// Name: int ShaderCompile_Main(int,char __near * __near * const)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ShaderCompile_Main(__int64 argc)
{
  int v1; // eax
  int v2; // edi
  int v3; // eax
  const char *v4; // eax
  int v6; // eax
  int v7; // eax
  int v8; // eax
  int v9; // eax
  int v10; // eax
  int v11; // eax
  bool v12; // bl
  int v13; // eax
  int v14; // eax
  int v15; // ecx
  unsigned int v16; // eax
  void (*v17)(const char *, ...); // ebx
  const char *v18; // eax
  const char *v19; // eax
  const char *v20; // eax
  DWORD CurrentThreadId; // esi
  DWORD v22; // esi
  DWORD TickCount; // eax
  const char *v24; // eax
  const char *v25; // eax
  const char *v26; // eax
  const char *v27; // eax
  int m_NumElements; // edi
  int v29; // esi
  const char *v30; // eax
  char *v31; // eax
  unsigned int v32; // eax
  int v33; // ecx
  int v34; // esi
  const char *v35; // ebx
  CompilerMsgInfo *v36; // esi
  const char *v37; // edi
  int m_numTimesReported; // eax
  const CfgProcessor::CfgEntryInfo *EntryInfo; // esi
  char *v40; // eax
  char *v41; // esi
  const char *v42; // eax
  const char *v43; // edi
  char *v44; // eax
  int v45; // eax
  char *v46; // eax
  char *v47; // ebx
  char *v48; // eax
  char *v49; // edi
  unsigned int v50; // eax
  int v51; // ebx
  int v52; // edi
  const char *v53; // eax
  char pchBuffer[4096]; // [esp+30h] [ebp-1224h] BYREF
  char v55[52]; // [esp+1030h] [ebp-224h] BYREF
  Worker_ProcessCommandRange_Singleton v56; // [esp+1064h] [ebp-1F0h] BYREF
  CDistributeShaderCompileMaster v57; // [esp+1190h] [ebp-C4h] BYREF
  char v58[52]; // [esp+11C0h] [ebp-94h] BYREF
  char string[52]; // [esp+11F4h] [ebp-60h] BYREF
  int v60; // [esp+1228h] [ebp-2Ch]
  MessageBuffer v61; // [esp+122Ch] [ebp-28h] BYREF
  int v62; // [esp+123Ch] [ebp-18h]
  CfgProcessor::<unnamed_type_ComboHandle> *rhCombo; // [esp+1240h] [ebp-14h] BYREF
  unsigned __int64 k; // [esp+1244h] [ebp-10h] BYREF
  char *v65; // [esp+124Ch] [ebp-8h]
  bool v66; // [esp+1252h] [ebp-2h]
  char pData; // [esp+1253h] [ebp-1h] BYREF

  InstallSpewFunction();
  g_bSuppressPrintfOutput = false;
  g_flStartTime = _Plat_FloatTime();
  numthreads = 1;
  v1 = _CommandLine();
  v2 = (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v1 + 40))(a1: v1, a2: "-subprocess");
  if ( v2 != 0 )
  {
    v3 = _CommandLine();
    v4 = (const char *)(*(int (__thiscall **)(int, int))(*(_DWORD *)v3 + 44))(a1: v3, a2: v2 + 1);
    return ShaderCompile_Subprocess_Main(szSubProcessData: v4);
  }
  SetupExeDir(argc, argv: (char **)HIDWORD(argc));
  v6 = _CommandLine();
  g_bIsX360 = (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v6 + 40))(a1: v6, a2: "-x360") != 0;
  v7 = _CommandLine();
  g_bIsPS3 = (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v7 + 40))(a1: v7, a2: "-ps3") != 0;
  v8 = _CommandLine();
  g_bGeneratePS3DebugInfo = (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v8 + 40))(a1: v8, a2: "-ps3debug") != 0;
  v9 = _CommandLine();
  g_bOptimizePS3ShaderScheduling = (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v9 + 40))(
                                     a1: v9,
                                     a2: "-ps3optimizeschedules") != 0;
  v10 = _CommandLine();
  v11 = (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v10 + 40))(a1: v10, a2: "-nompi");
  v12 = v11 == 0;
  v66 = v11 == 0;
  if ( v11 == 0 )
  {
    DebugOut(pMsg: "Before VMPI_Init\n");
    g_bSuppressPrintfOutput = true;
    if ( !VMPI_Init(
            (int *)&argc,
            argv: (char ***)&argc + 1,
            pDependencyFilename: "dependency_info_shadercompile.txt",
            handler: MyDisconnectHandler,
            runMode: VMPI_RUN_NETWORKED,
            bConnectingAsService: false) )
    {
      g_bSuppressPrintfOutput = false;
      DebugOut(pMsg: "MPI_Init failed.\n");
      _Error(a1: "MPI_Init failed.");
    }
    VMPI_SetWorkUnitsPartitionSize(numWusToDeal: 32);
  }
  SetupPaths(argc, argv: (char **)HIDWORD(argc));
  g_bSuppressPrintfOutput = false;
  DebugOut(pMsg: "After VMPI_Init\n");
  if ( !v12 || g_bMPIMaster )
    SetupDefaultToolsMinidumpHandler();
  else
    SetupToolsMinidumpHandler(fn: VMPI_ExceptionFilter);
  v13 = _CommandLine();
  v14 = (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v13 + 40))(a1: v13, a2: "-game");
  FileSystem_Init(pBSPFilename: nullptr, maxMemoryUsage: 0, initType: (FSInitType_t)(v14 == 0), bOnlyUseFilename: false);
  DebugOut(pMsg: "After VMPI_FileSystem_Init\n");
  Shared_ParseListOfCompileCommands();
  DebugOut(pMsg: "After Shared_ParseListOfCompileCommands\n");
  if ( v12 )
  {
    if ( `anonymous namespace'::g_numStaticCombos != 0 )
    {
      if ( HIDWORD(`anonymous namespace'::g_numStaticCombos) != 0 )
        goto LABEL_24;
      if ( (unsigned int)`anonymous namespace'::g_numStaticCombos <= 0x400 )
      {
        v15 = 1;
LABEL_16:
        v16 = 0;
        `anonymous namespace'::g_nStaticCombosPerWorkUnit = (unsigned int)v15;
LABEL_17:
        k = `anonymous namespace'::g_numStaticCombos / __PAIR64__(v16, v15) + 1;
        goto LABEL_18;
      }
      if ( `anonymous namespace'::g_numStaticCombos > 0x2800 )
      {
LABEL_24:
        v15 = 10;
        goto LABEL_16;
      }
      v15 = `anonymous namespace'::g_numStaticCombos >> 10;
      v16 = HIDWORD(`anonymous namespace'::g_numStaticCombos) >> 10;
      `anonymous namespace'::g_nStaticCombosPerWorkUnit = `anonymous namespace'::g_numStaticCombos >> 10;
      if ( `anonymous namespace'::g_numStaticCombos >> 10 != 0 )
        goto LABEL_17;
    }
    k = 1;
    `anonymous namespace'::g_nStaticCombosPerWorkUnit = `anonymous namespace'::g_numStaticCombos;
LABEL_18:
    DebugOut(pMsg: "Before conditional\n");
    v17 = (void (*)(const char *, ...))_Msg;
    if ( g_bMPIMaster )
    {
      if ( g_bIsPS3 && g_bGeneratePS3DebugInfo )
        InitializePS3ShaderDebugPackFiles();
      DebugOut(pMsg: "Before STARTWORK_PACKETID\n");
      pData = 5;
      VMPI_SendData(&pData, nBytes: 1, iDest: -3, fVMPISendFlags: 0);
      CDistributeShaderCompileMaster::CDistributeShaderCompileMaster(this: &v57);
      g_pDistributeWorkCallbacks = &v57;
      v18 = PrettyPrintNumber(k: `anonymous namespace'::g_numCompileCommands);
      sprintf(string, format: "%s", v18);
      v19 = PrettyPrintNumber(k: `anonymous namespace'::g_numStaticCombos);
      sprintf(string: v55, format: "%s", v19);
      v20 = PrettyPrintNumber(k);
      sprintf(string: v58, format: "%s", v20);
      _Msg(a1: "\rCompiling %s commands in %s work units.\n", string, v58);
      DebugOut(pMsg: "Before DistributeWork\n");
      DistributeWork(
        nWorkUnits: k,
        processFn: nullptr,
        receiveFn: (void (__cdecl *)(unsigned __int64, MessageBuffer *, int))Master_ReceiveWorkUnitFn);
      g_pDistributeWorkCallbacks = nullptr;
      CDistributeShaderCompileMaster::~CDistributeShaderCompileMaster(this: &v57);
      g_bSuppressPrintfOutput = false;
    }
    else
    {
      MessageBuffer::MessageBuffer(this: &v61);
      DebugOut(pMsg: "Before VMPI_DispatchUntil\n");
      while ( !g_bGotStartWorkPacket )
        VMPI_DispatchNextMessage(timeout: 0xFFFFFFFF);
      DebugOut(pMsg: "after VMPI_DispatchUntil\n");
      DebugOut(pMsg: "Before Worker_GetLocalCopyOfShaders\n");
      Worker_GetLocalCopyOfShaders();
      DebugOut(pMsg: "Before Worker_GetLocalCopyOfBinaries\n");
      Worker_GetLocalCopyOfBinary(pFilename: "mysql_wrapper.dll");
      Worker_GetLocalCopyOfBinary(pFilename: "vstdlib.dll");
      Worker_GetLocalCopyOfBinary(pFilename: "tier0.dll");
      DebugOut(pMsg: "Before _chdir\n");
      _chdir(path: g_WorkerTempPath);
      if ( g_bIsPS3 )
      {
        if ( GetEnvironmentVariableA(
               lpName: "PS3COMPILELOG",
               lpBuffer: (LPSTR)&v56.m_MT.tpsp.iAffinityTable[2],
               nSize: 0x104u) == 0 )
        {
          CurrentThreadId = GetCurrentThreadId();
          v22 = GetCurrentProcessId() ^ CurrentThreadId;
          TickCount = GetTickCount();
          sprintf_s(
            string: (char *)&v56.m_MT.tpsp.iAffinityTable[2],
            sizeInBytes: 0x104u,
            format: "%s__ps3compilelog%08X__.tmp",
            g_WorkerTempPath,
            (char *)&k + v22 + TickCount);
          unlink(path: (const char *)&v56.m_MT.tpsp.iAffinityTable[2]);
          SetEnvironmentVariableA(lpName: "PS3COMPILELOG", lpValue: (LPCSTR)&v56.m_MT.tpsp.iAffinityTable[2]);
        }
        v24 = "1";
        if ( !g_bOptimizePS3ShaderScheduling )
          v24 = "0";
        SetEnvironmentVariableA(lpName: "PS3FINDOPTIMALSCHEDULES", lpValue: v24);
        v25 = setName;
        if ( !g_bOptimizePS3ShaderScheduling )
          v25 = "ps3optimalschedules.bin";
        SetEnvironmentVariableA(lpName: "PS3OPTIMALSCHEDULESFILE", lpValue: v25);
        if ( g_bGeneratePS3DebugInfo )
          SetEnvironmentVariableA(lpName: "SCECGC_CAPTUREDIR", lpValue: g_WorkerTempPath);
      }
      DebugOut(pMsg: "Before DistributeWork\n");
      Worker_ProcessCommandRange_Singleton::Worker_ProcessCommandRange_Singleton(this: &v56);
      DistributeWork(nWorkUnits: k, processFn: Worker_ProcessWorkUnitFn, receiveFn: nullptr);
      `Worker_ProcessCommandRange_Singleton::Instance'::`2'::s_ptr = nullptr;
      Worker_ProcessCommandRange_Singleton::Shutdown(this: &v56);
      MessageBuffer::~MessageBuffer(this: &v61);
      g_bSuppressPrintfOutput = false;
    }
    goto LABEL_40;
  }
  Worker_GetLocalCopyOfShaders();
  Worker_GetLocalCopyOfBinary(pFilename: "mysql_wrapper.dll");
  Worker_GetLocalCopyOfBinary(pFilename: "vstdlib.dll");
  Worker_GetLocalCopyOfBinary(pFilename: "tier0.dll");
  _chdir(path: g_WorkerTempPath);
  v26 = PrettyPrintNumber(k: `anonymous namespace'::g_numCompileCommands);
  sprintf(string: v58, format: "%s", v26);
  v27 = PrettyPrintNumber(k: `anonymous namespace'::g_numStaticCombos);
  sprintf(string, format: "%s", v27);
  v17 = (void (*)(const char *, ...))_Msg;
  _Msg(a1: "\rCompiling %s commands in %s static combos.\n", v58, string);
  CompileShaders_NoVMPI();
LABEL_40:
  v17(a1: "\r                                                                \r");
  if ( g_bMPIMaster || !v66 )
  {
    m_NumElements = g_ShaderByteCode.m_SymbolTable.m_Lookup.m_NumElements;
    v29 = 0;
    if ( g_ShaderByteCode.m_SymbolTable.m_Lookup.m_NumElements != 0 )
    {
      do
      {
        v30 = CUtlSymbolTable::String(this: &g_ShaderByteCode.m_SymbolTable, id: (CUtlSymbol)v29);
        WriteShaderFiles(pShaderName: v30);
        ++v29;
      }
      while ( v29 < m_NumElements );
    }
    if ( getenv(option: "VALVE_VERBOSE_COMBO_ERRORS") == nullptr
      || (v31 = getenv(option: "VALVE_VERBOSE_COMBO_ERRORS"), v32 = atoi(nptr: v31), pData = 1, v32 == 0) )
    {
      pData = 0;
    }
    LOWORD(v33) = 0;
    v62 = 0;
    HIDWORD(k) = g_Master_CompilerMsgInfo.m_SymbolTable.m_Lookup.m_NumElements;
    if ( g_Master_CompilerMsgInfo.m_SymbolTable.m_Lookup.m_NumElements != 0 )
    {
      do
      {
        v34 = (unsigned __int16)v33;
        v35 = CUtlSymbolTable::String(this: &g_Master_CompilerMsgInfo.m_SymbolTable, id: (CUtlSymbol)v33);
        v36 = &g_Master_CompilerMsgInfo.m_Vector.m_Memory.m_pMemory[v34];
        v37 = CUtlString::Get(this: &v36->m_sFirstCommand);
        v65 = (char *)CUtlString::Get(this: &v36->m_sFirstMachineName);
        m_numTimesReported = v36->m_numTimesReported;
        EntryInfo = nullptr;
        v60 = m_numTimesReported;
        *(_QWORD *)&v61.offset = _strtoui64(nptr: v37, endptr: nullptr, ibase: 10);
        rhCombo = nullptr;
        if ( CfgProcessor::Combo_GetNext(
               riCommandNumber: (unsigned __int64 *)&v61.offset,
               (ConfigurationProcessing::ComboHandleImpl **)&rhCombo,
               iCommandEnd: `anonymous namespace'::g_numCompileCommands) != nullptr )
        {
          CfgProcessor::Combo_FormatCommand(hCombo: rhCombo, pchBuffer);
          EntryInfo = CfgProcessor::Combo_GetEntryInfo(hCombo: rhCombo);
          CfgProcessor::Combo_Free(rhComboFree: &rhCombo);
        }
        else
        {
          sprintf(string: pchBuffer, format: "cmd # %s", v37);
        }
        _Msg(a1: "\n%s\n", v35);
        _Msg(a1: "    Reported %d time(s), first machine \"%s\", example command:\n", v60, v65);
        if ( pData != 0 )
        {
          _Msg(a1: "    Verbose Description:\n");
          if ( EntryInfo != nullptr )
          {
            _Msg(a1: "        Src File: %s\n", EntryInfo->m_szShaderFileName);
            _Msg(a1: "        Tgt File: %s\n", EntryInfo->m_szName);
          }
          if ( g_bIsPS3 )
          {
            strstr(str1: (unsigned __int8 *)pchBuffer, str2: "-DSHADERCOMBO=");
            v41 = v40;
            strstr(str1: (unsigned __int8 *)pchBuffer, str2: "-Dmain");
          }
          else
          {
            strstr(str1: (unsigned __int8 *)pchBuffer, str2: "/DSHADERCOMBO=");
            v41 = v44;
            strstr(str1: (unsigned __int8 *)pchBuffer, str2: "/Dmain");
          }
          v43 = v42;
          v65 = (char *)v42;
          if ( v41 != nullptr )
          {
            v41 += 14;
            strchr(string: v41, chr: 0x20u);
            if ( v45 != 0 )
              _Msg(a1: "        Combo # : %.*s\n", v45 - (_DWORD)v41, v41);
          }
          if ( v43 == nullptr )
          {
            v43 = &pchBuffer[strlen(pchBuffer)];
            v65 = (char *)v43;
          }
          if ( v41 != nullptr )
          {
            while ( *v41 != 0 )
            {
              if ( isspace(c: *v41) != 0 )
              {
                while ( *v41 != 0 )
                {
                  if ( isspace(c: *v41) == 0 )
                  {
                    while ( *v41 != 0 && v41 < v43 )
                    {
                      if ( g_bIsPS3 )
                        strstr(str1: (unsigned __int8 *)v41, str2: "-D");
                      else
                        strstr(str1: (unsigned __int8 *)v41, str2: "/D");
                      v47 = v46;
                      if ( v46 == nullptr )
                        break;
                      if ( v46 >= v43 )
                        break;
                      strchr(string: v46, chr: 0x3Du);
                      v49 = v48;
                      if ( v48 == nullptr || v48 >= v65 )
                        break;
                      strchr(string: v48, chr: 0x20u);
                      v41 = (char *)v50;
                      if ( v50 == 0 || v50 >= (unsigned int)v65 )
                        v41 = v65;
                      _Msg(a1: "                  %.*s %.*s\n", v41 - v49 - 1, v49 + 1, v49 - v47 - 2, v47 + 2);
                      if ( v41 == nullptr )
                        break;
                      v43 = v65;
                    }
                    goto LABEL_85;
                  }
                  if ( ++v41 == nullptr )
                    goto LABEL_85;
                }
                break;
              }
              if ( ++v41 == nullptr )
                break;
            }
          }
        }
LABEL_85:
        _Msg(a1: "    %s\n", pchBuffer);
        v33 = v62 + 1;
        v62 = v33;
      }
      while ( v33 < SHIDWORD(k) );
    }
    v51 = g_Master_ShaderHadError.m_SymbolTable.m_Lookup.m_NumElements;
    v52 = 0;
    if ( g_Master_ShaderHadError.m_SymbolTable.m_Lookup.m_NumElements != 0 )
    {
      do
      {
        v53 = CUtlSymbolTable::String(this: &g_Master_ShaderHadError.m_SymbolTable, id: (CUtlSymbol)v52);
        if ( g_Master_ShaderHadError.m_Vector.m_Memory.m_pMemory[(unsigned __int16)v52] )
          _Msg(a1: "FAILED:    %s\n", v53);
        ++v52;
      }
      while ( v52 < v51 );
    }
    *(double *)&v61.offset = _Plat_FloatTime();
    GetHourMinuteSecondsString(
      nInputSeconds: (int)(*(double *)&v61.offset - g_flStartTime),
      pOut: pchBuffer,
      outLen: 4096);
    DebugOut(pMsg: "%s elapsed\n", pchBuffer);
    DebugOut(pMsg: "Precise timing = %.5f\n", (double)(*(double *)&v61.offset - g_flStartTime));
    if ( v66 )
    {
      VMPI_FileSystem_Term();
      DebugOut(pMsg: "Before VMPI_Finalize\n");
      VMPI_Finalize();
    }
    if ( g_bIsPS3 && g_bGeneratePS3DebugInfo )
      ExpandPS3DebugInfo();
  }
  return g_Master_ShaderHadError.m_SymbolTable.m_Lookup.m_NumElements;
}

//------------------------------------------------------------------------------
// Address: 0x1000E9F0
// Name: private: virtual int CShaderCompileDLL::main(int,char __near * __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CShaderCompileDLL::main(CLaunchableDLL *this, unsigned int argc, char **argv)
{
  return ShaderCompile_Main(argc: __SPAIR64__((unsigned int)argv, argc));
}

//------------------------------------------------------------------------------
// Address: 0x1000EFC0
// Name: public: void CUtlMemory<bool,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<bool,int>::Grow(CUtlMemory<char,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  char *m_pMemory; // edx

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
        m_nAllocationCount = 32;
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
    if ( m_pMemory != nullptr )
      this->m_pMemory = (char *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: m_nAllocationCount);
    else
      this->m_pMemory = (char *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: m_nAllocationCount);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1004F720
// Name: protected: virtual bool CRefCountServiceBase<1,class CRefMT>::OnFinalRelease(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CRefCountServiceBase<1,CRefMT>::OnFinalRelease(ConCommandBase *this)
{
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10050E80
// Name: Threading::Private::_dynamic_initializer_for__g_mtxSyncObjMT__
// Source: json
//------------------------------------------------------------------------------
int Threading::Private::_dynamic_initializer_for__g_mtxSyncObjMT__()
{
  CThreadMutex::CThreadMutex(this: &Threading::Private::g_mtxSyncObjMT);
  return atexit(func: Threading::Private::_dynamic_atexit_destructor_for__g_mtxSyncObjMT__);
}

//------------------------------------------------------------------------------
// Address: 0x10050EA0
// Name: Threading::_dynamic_initializer_for__g_mtxGlobal__
// Source: json
//------------------------------------------------------------------------------
void Threading::_dynamic_initializer_for__g_mtxGlobal__()
{
  Threading::g_mtxGlobal.m_pUseMtx.m_value = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10051A00
// Name: Threading::Private::_dynamic_atexit_destructor_for__g_mtxSyncObjMT__
// Source: json
//------------------------------------------------------------------------------
void __cdecl Threading::Private::_dynamic_atexit_destructor_for__g_mtxSyncObjMT__()
{
  CThreadMutex::~CThreadMutex(this: &Threading::Private::g_mtxSyncObjMT);
}

//------------------------------------------------------------------------------
// Address: 0x100093D0
// Name: __CreateCShaderCompileDLLIShaderCompileDLL_interface
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CShaderCompileDLL *__cdecl _CreateCShaderCompileDLLIShaderCompileDLL_interface()
{
  return &_g_CShaderCompileDLL_singleton;
}

//------------------------------------------------------------------------------
// Address: 0x100093E0
// Name: __CreateCLaunchableDLLILaunchableDLL_interface
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CLaunchableDLL *__cdecl _CreateCLaunchableDLLILaunchableDLL_interface()
{
  return &_g_CLaunchableDLL_singleton;
}

//------------------------------------------------------------------------------
// Address: 0x10050EB0
// Name: _dynamic_initializer_for__g_StartWorkReg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDispatchReg *dynamic_initializer_for__g_StartWorkReg__()
{
  return CDispatchReg::CDispatchReg(
           this: &g_StartWorkReg,
           iPacketID: 5,
           fn: (bool (__cdecl *)(MessageBuffer *, int, int))StartWorkDispatch);
}

//------------------------------------------------------------------------------
// Address: 0x10050ED0
// Name: _dynamic_initializer_for__g_PS3ShaderDebugInfoReg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDispatchReg *dynamic_initializer_for__g_PS3ShaderDebugInfoReg__()
{
  return CDispatchReg::CDispatchReg(
           this: &g_PS3ShaderDebugInfoReg,
           iPacketID: 6,
           fn: (bool (__cdecl *)(MessageBuffer *, int, int))PS3ShaderDebugInfoDispatch);
}

//------------------------------------------------------------------------------
// Address: 0x10050EF0
// Name: _dynamic_initializer_for__g_PS3ShaderCompileLogReg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDispatchReg *dynamic_initializer_for__g_PS3ShaderCompileLogReg__()
{
  return CDispatchReg::CDispatchReg(
           this: &g_PS3ShaderCompileLogReg,
           iPacketID: 11,
           fn: (bool (__cdecl *)(MessageBuffer *, int, int))PS3ShaderCompileLogDispatch);
}

//------------------------------------------------------------------------------
// Address: 0x10050F10
// Name: _dynamic_initializer_for__g_ErrMsgReg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDispatchReg *dynamic_initializer_for__g_ErrMsgReg__()
{
  return CDispatchReg::CDispatchReg(
           this: &g_ErrMsgReg,
           iPacketID: 7,
           fn: (bool (__cdecl *)(MessageBuffer *, int, int))ErrMsgDispatch);
}

//------------------------------------------------------------------------------
// Address: 0x10050F30
// Name: _dynamic_initializer_for__g_ShaderHadErrorReg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDispatchReg *dynamic_initializer_for__g_ShaderHadErrorReg__()
{
  return CDispatchReg::CDispatchReg(
           this: &g_ShaderHadErrorReg,
           iPacketID: 8,
           fn: (bool (__cdecl *)(MessageBuffer *, int, int))ShaderHadErrorDispatch);
}

//------------------------------------------------------------------------------
// Address: 0x10050F50
// Name: _dynamic_initializer_for____g_CreateCShaderCompileDLLIShaderCompileDLL_reg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
InterfaceReg *dynamic_initializer_for____g_CreateCShaderCompileDLLIShaderCompileDLL_reg__()
{
  return InterfaceReg::InterfaceReg(
           this: &_g_CreateCShaderCompileDLLIShaderCompileDLL_reg,
           fn: (void *(__cdecl *)())_CreateCShaderCompileDLLIShaderCompileDLL_interface,
           pName: "shadercompiledll_0");
}

//------------------------------------------------------------------------------
// Address: 0x10050F70
// Name: _dynamic_initializer_for____g_CreateCLaunchableDLLILaunchableDLL_reg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
InterfaceReg *dynamic_initializer_for____g_CreateCLaunchableDLLILaunchableDLL_reg__()
{
  return InterfaceReg::InterfaceReg(
           this: &_g_CreateCLaunchableDLLILaunchableDLL_reg,
           fn: (void *(__cdecl *)())_CreateCLaunchableDLLILaunchableDLL_interface,
           pName: "launchable_dll_1");
}

//------------------------------------------------------------------------------
// Address: 0x10050F90
// Name: _dynamic_initializer_for__g_PS3DebugInfoFileSet__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_PS3DebugInfoFileSet__()
{
  g_PS3DebugInfoFileSet.m_Lookup.m_Elements.m_pMemory = (UtlRBTreeNode_t<CUtlSymbolTableLargeBaseTreeEntry_t *,int> *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 320);
  g_PS3DebugInfoFileSet.m_Lookup.m_Root = -1;
  g_PS3DebugInfoFileSet.m_Lookup.m_NumElements = 0;
  g_PS3DebugInfoFileSet.m_Lookup.m_FirstFree = -1;
  g_PS3DebugInfoFileSet.m_Lookup.m_LastAlloc.index = -1;
  g_PS3DebugInfoFileSet.m_Lookup.m_pElements = g_PS3DebugInfoFileSet.m_Lookup.m_Elements.m_pMemory;
  g_PS3DebugInfoFileSet.m_StringPools.m_Memory.m_pMemory = nullptr;
  g_PS3DebugInfoFileSet.m_StringPools.m_Memory.m_nAllocationCount = 0;
  g_PS3DebugInfoFileSet.m_StringPools.m_Memory.m_nGrowSize = 8;
  g_PS3DebugInfoFileSet.m_StringPools.m_Size = 0;
  g_PS3DebugInfoFileSet.m_StringPools.m_pElements = nullptr;
  return atexit(func: dynamic_atexit_destructor_for__g_PS3DebugInfoFileSet__);
}

//------------------------------------------------------------------------------
// Address: 0x10051000
// Name: _dynamic_initializer_for__g_CritInit__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void dynamic_initializer_for__g_CritInit__()
{
  InitializeCriticalSection(lpCriticalSection: &crit);
}

//------------------------------------------------------------------------------
// Address: 0x10051010
// Name: _dynamic_initializer_for__g_SharedDispatchReg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDispatchReg *dynamic_initializer_for__g_SharedDispatchReg__()
{
  return CDispatchReg::CDispatchReg(this: &g_SharedDispatchReg, iPacketID: 10, fn: SharedDispatch);
}

//------------------------------------------------------------------------------
// Address: 0x10051030
// Name: _dynamic_initializer_for__g_VMPIPacketIDReg_VMPI_SHARED_PACKET_ID__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CVMPIPacketIDReg *dynamic_initializer_for__g_VMPIPacketIDReg_VMPI_SHARED_PACKET_ID__()
{
  return CVMPIPacketIDReg::CVMPIPacketIDReg(
           this: &g_VMPIPacketIDReg_VMPI_SHARED_PACKET_ID,
           nPacketID: 10,
           nSubPacketID: -1,
           pName: "VMPI_SHARED_PACKET_ID");
}

//------------------------------------------------------------------------------
// Address: 0x10051050
// Name: _dynamic_initializer_for__g_VMPISubPacketIDReg_VMPI_SUBPACKETID_DIRECTORIES__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CVMPIPacketIDReg *dynamic_initializer_for__g_VMPISubPacketIDReg_VMPI_SUBPACKETID_DIRECTORIES__()
{
  return CVMPIPacketIDReg::CVMPIPacketIDReg(
           this: &g_VMPISubPacketIDReg_VMPI_SUBPACKETID_DIRECTORIES,
           nPacketID: 10,
           nSubPacketID: 0,
           pName: "VMPI_SUBPACKETID_DIRECTORIES");
}

//------------------------------------------------------------------------------
// Address: 0x10051070
// Name: _dynamic_initializer_for__g_VMPISubPacketIDReg_VMPI_SUBPACKETID_DBINFO__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CVMPIPacketIDReg *dynamic_initializer_for__g_VMPISubPacketIDReg_VMPI_SUBPACKETID_DBINFO__()
{
  return CVMPIPacketIDReg::CVMPIPacketIDReg(
           this: &g_VMPISubPacketIDReg_VMPI_SUBPACKETID_DBINFO,
           nPacketID: 10,
           nSubPacketID: 1,
           pName: "VMPI_SUBPACKETID_DBINFO");
}

//------------------------------------------------------------------------------
// Address: 0x10051090
// Name: _dynamic_initializer_for__g_VMPISubPacketIDReg_VMPI_SUBPACKETID_CRASH__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CVMPIPacketIDReg *dynamic_initializer_for__g_VMPISubPacketIDReg_VMPI_SUBPACKETID_CRASH__()
{
  return CVMPIPacketIDReg::CVMPIPacketIDReg(
           this: &g_VMPISubPacketIDReg_VMPI_SUBPACKETID_CRASH,
           nPacketID: 10,
           nSubPacketID: 3,
           pName: "VMPI_SUBPACKETID_CRASH");
}

//------------------------------------------------------------------------------
// Address: 0x100510B0
// Name: _dynamic_initializer_for__g_VMPISubPacketIDReg_VMPI_SUBPACKETID_MULTICAST_ADDR__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CVMPIPacketIDReg *dynamic_initializer_for__g_VMPISubPacketIDReg_VMPI_SUBPACKETID_MULTICAST_ADDR__()
{
  return CVMPIPacketIDReg::CVMPIPacketIDReg(
           this: &g_VMPISubPacketIDReg_VMPI_SUBPACKETID_MULTICAST_ADDR,
           nPacketID: 10,
           nSubPacketID: 4,
           pName: "VMPI_SUBPACKETID_MULTICAST_ADDR");
}

//------------------------------------------------------------------------------
// Address: 0x100510D0
// Name: NCompress::NLZMA::_dynamic_initializer_for__g_FastPosInit__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void NCompress::NLZMA::_dynamic_initializer_for__g_FastPosInit__()
{
  NCompress::NLZMA::CFastPosInit::Init(this: &NCompress::NLZMA::g_FastPosInit);
}

//------------------------------------------------------------------------------
// Address: 0x100510E0
// Name: NCompress::NRangeCoder::_dynamic_initializer_for__g_PriceTables__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
static void __cdecl NCompress::NRangeCoder::_dynamic_initializer_for__g_PriceTables__()
{
  NCompress::NRangeCoder::CPriceTables::Init();
}

//------------------------------------------------------------------------------
// Address: 0x100510F0
// Name: _dynamic_initializer_for__g_CRCTableInit__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
static void __cdecl dynamic_initializer_for__g_CRCTableInit__()
{
  CCRC::InitTable();
}

//------------------------------------------------------------------------------
// Address: 0x10051100
// Name: _dynamic_initializer_for__s_StringCharConversion__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char **dynamic_initializer_for__s_StringCharConversion__()
{
  char **result; // eax
  int v1; // edx
  char v2; // cl

  CUtlCharConversion::CUtlCharConversion(
    this: &s_StringCharConversion,
    nEscapeChar: 92,
    pDelimiter: "\"",
    nCount: 11,
    pArray: s_pConversionArrays_StringCharConversion);
  s_StringCharConversion.__vftable = (CUtlCStringConversion_vtbl *)&CUtlCStringConversion::`vftable';
  memset(
    dst: (int)s_StringCharConversion.m_pConversion,
    value: nullptr,
    count: sizeof(s_StringCharConversion.m_pConversion));
  result = &s_pConversionArrays_StringCharConversion[0].m_pReplacementString;
  do
  {
    v1 = **result;
    v2 = *((_BYTE *)result - 4);
    result += 2;
    s_StringCharConversion.m_pConversion[v1] = v2;
  }
  while ( (int)result < (int)&s_pConversionArrays_NoEscConversion[0].m_pReplacementString );
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10051160
// Name: _dynamic_initializer_for__s_NoEscConversion__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CUtlCharConversion *dynamic_initializer_for__s_NoEscConversion__()
{
  CUtlCharConversion *result; // eax

  result = CUtlCharConversion::CUtlCharConversion(
             this: &s_NoEscConversion,
             nEscapeChar: 127,
             pDelimiter: "\"",
             nCount: 1,
             pArray: s_pConversionArrays_NoEscConversion);
  s_NoEscConversion.__vftable = (CUtlNoEscConversion_vtbl *)&CUtlNoEscConversion::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10051190
// Name: _dynamic_initializer_for__g_CleanupSymbolTable__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CleanupSymbolTable__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CleanupSymbolTable__);
}

//------------------------------------------------------------------------------
// Address: 0x100511A0
// Name: _dynamic_initializer_for__g_VMPIPacketIDReg_VMPI_INTERNAL_PACKET_ID__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CVMPIPacketIDReg *dynamic_initializer_for__g_VMPIPacketIDReg_VMPI_INTERNAL_PACKET_ID__()
{
  CVMPIPacketIDReg *result; // eax

  result = g_pVMPIPacketIDRegHead;
  g_VMPIPacketIDReg_VMPI_INTERNAL_PACKET_ID.m_pNext = g_pVMPIPacketIDRegHead;
  g_pVMPIPacketIDRegHead = &g_VMPIPacketIDReg_VMPI_INTERNAL_PACKET_ID;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100511C0
// Name: _dynamic_initializer_for__g_VMPISubPacketIDReg_VMPI_INTERNAL_SUBPACKET_MACHINE_NAME__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CVMPIPacketIDReg *dynamic_initializer_for__g_VMPISubPacketIDReg_VMPI_INTERNAL_SUBPACKET_MACHINE_NAME__()
{
  CVMPIPacketIDReg *result; // eax

  result = g_pVMPIPacketIDRegHead;
  g_VMPISubPacketIDReg_VMPI_INTERNAL_SUBPACKET_MACHINE_NAME.m_pNext = g_pVMPIPacketIDRegHead;
  g_pVMPIPacketIDRegHead = &g_VMPISubPacketIDReg_VMPI_INTERNAL_SUBPACKET_MACHINE_NAME;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100511E0
// Name: _dynamic_initializer_for__g_VMPISubPacketIDReg_VMPI_INTERNAL_SUBPACKET_COMMAND_LINE__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CVMPIPacketIDReg *dynamic_initializer_for__g_VMPISubPacketIDReg_VMPI_INTERNAL_SUBPACKET_COMMAND_LINE__()
{
  CVMPIPacketIDReg *result; // eax

  result = g_pVMPIPacketIDRegHead;
  g_VMPISubPacketIDReg_VMPI_INTERNAL_SUBPACKET_COMMAND_LINE.m_pNext = g_pVMPIPacketIDRegHead;
  g_pVMPIPacketIDRegHead = &g_VMPISubPacketIDReg_VMPI_INTERNAL_SUBPACKET_COMMAND_LINE;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10051200
// Name: _dynamic_initializer_for__g_VMPISubPacketIDReg_VMPI_INTERNAL_SUBPACKET_WAITING_FOR_COMMAND_LINE__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CVMPIPacketIDReg *dynamic_initializer_for__g_VMPISubPacketIDReg_VMPI_INTERNAL_SUBPACKET_WAITING_FOR_COMMAND_LINE__()
{
  CVMPIPacketIDReg *result; // eax

  result = g_pVMPIPacketIDRegHead;
  g_VMPISubPacketIDReg_VMPI_INTERNAL_SUBPACKET_WAITING_FOR_COMMAND_LINE.m_pNext = g_pVMPIPacketIDRegHead;
  g_pVMPIPacketIDRegHead = &g_VMPISubPacketIDReg_VMPI_INTERNAL_SUBPACKET_WAITING_FOR_COMMAND_LINE;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10051220
// Name: _dynamic_initializer_for__g_VMPISubPacketIDReg_VMPI_INTERNAL_SUBPACKET_GROUPED_PACKET__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CVMPIPacketIDReg *dynamic_initializer_for__g_VMPISubPacketIDReg_VMPI_INTERNAL_SUBPACKET_GROUPED_PACKET__()
{
  CVMPIPacketIDReg *result; // eax

  result = g_pVMPIPacketIDRegHead;
  g_VMPISubPacketIDReg_VMPI_INTERNAL_SUBPACKET_GROUPED_PACKET.m_pNext = g_pVMPIPacketIDRegHead;
  g_pVMPIPacketIDRegHead = &g_VMPISubPacketIDReg_VMPI_INTERNAL_SUBPACKET_GROUPED_PACKET;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10051240
// Name: _dynamic_initializer_for__g_VMPISubPacketIDReg_VMPI_INTERNAL_SUBPACKET_TIMING_WAIT_DONE__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CVMPIPacketIDReg *dynamic_initializer_for__g_VMPISubPacketIDReg_VMPI_INTERNAL_SUBPACKET_TIMING_WAIT_DONE__()
{
  CVMPIPacketIDReg *result; // eax

  result = g_pVMPIPacketIDRegHead;
  g_VMPISubPacketIDReg_VMPI_INTERNAL_SUBPACKET_TIMING_WAIT_DONE.m_pNext = g_pVMPIPacketIDRegHead;
  g_pVMPIPacketIDRegHead = &g_VMPISubPacketIDReg_VMPI_INTERNAL_SUBPACKET_TIMING_WAIT_DONE;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10051260
// Name: _dynamic_initializer_for__g_VMPISubPacketIDReg_VMPI_INTERNAL_SUBPACKET_VERIFY_EXE_NAME__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CVMPIPacketIDReg *dynamic_initializer_for__g_VMPISubPacketIDReg_VMPI_INTERNAL_SUBPACKET_VERIFY_EXE_NAME__()
{
  CVMPIPacketIDReg *result; // eax

  result = g_pVMPIPacketIDRegHead;
  g_VMPISubPacketIDReg_VMPI_INTERNAL_SUBPACKET_VERIFY_EXE_NAME.m_pNext = g_pVMPIPacketIDRegHead;
  g_pVMPIPacketIDRegHead = &g_VMPISubPacketIDReg_VMPI_INTERNAL_SUBPACKET_VERIFY_EXE_NAME;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10051280
// Name: _dynamic_initializer_for__g_PersistentPacketsCS__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_PersistentPacketsCS__()
{
  CCriticalSection::CCriticalSection(this: &g_PersistentPacketsCS);
  return atexit(func: dynamic_atexit_destructor_for__g_PersistentPacketsCS__);
}

//------------------------------------------------------------------------------
// Address: 0x100512A0
// Name: _dynamic_initializer_for__g_PersistentPackets__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_PersistentPackets__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_PersistentPackets__);
}

//------------------------------------------------------------------------------
// Address: 0x100512B0
// Name: _dynamic_initializer_for__g_OriginalCommandLineParameters__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_OriginalCommandLineParameters__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_OriginalCommandLineParameters__);
}

//------------------------------------------------------------------------------
// Address: 0x100512C0
// Name: _dynamic_initializer_for__g_VMPIMessagesCS__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_VMPIMessagesCS__()
{
  CCriticalSection::CCriticalSection(this: &g_VMPIMessagesCS);
  return atexit(func: dynamic_atexit_destructor_for__g_VMPIMessagesCS__);
}

//------------------------------------------------------------------------------
// Address: 0x100512E0
// Name: _dynamic_initializer_for__g_VMPIMessages__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_VMPIMessages__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_VMPIMessages__);
}

//------------------------------------------------------------------------------
// Address: 0x100512F0
// Name: _dynamic_initializer_for__g_VMPIMessagesEvent__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_VMPIMessagesEvent__()
{
  CExpressionEvaluator::CExpressionEvaluator(this: &g_VMPIMessagesEvent);
  return atexit(func: dynamic_atexit_destructor_for__g_VMPIMessagesEvent__);
}

//------------------------------------------------------------------------------
// Address: 0x10051310
// Name: _dynamic_initializer_for__g_ErrorSockets__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_ErrorSockets__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_ErrorSockets__);
}

//------------------------------------------------------------------------------
// Address: 0x10051320
// Name: _dynamic_initializer_for__g_ErrorSocketsEvent__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_ErrorSocketsEvent__()
{
  CExpressionEvaluator::CExpressionEvaluator(this: &g_ErrorSocketsEvent);
  return atexit(func: dynamic_atexit_destructor_for__g_ErrorSocketsEvent__);
}

//------------------------------------------------------------------------------
// Address: 0x10051340
// Name: _dynamic_initializer_for__g_ErrorSocketsCS__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_ErrorSocketsCS__()
{
  CCriticalSection::CCriticalSection(this: &g_ErrorSocketsCS);
  return atexit(func: dynamic_atexit_destructor_for__g_ErrorSocketsCS__);
}

//------------------------------------------------------------------------------
// Address: 0x10051360
// Name: _dynamic_initializer_for__g_ConnectionsCS__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_ConnectionsCS__()
{
  CCriticalSection::CCriticalSection(this: &g_ConnectionsCS);
  return atexit(func: dynamic_atexit_destructor_for__g_ConnectionsCS__);
}

//------------------------------------------------------------------------------
// Address: 0x10051380
// Name: _dynamic_initializer_for__g_DispatchBuffers__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_DispatchBuffers__()
{
  if ( ((unsigned __int8)&g_DispatchBuffers & 7) != 0 )
  {
    _Error(a1: "CTSListBase: Misaligned list\n");
    __debugbreak();
  }
  g_DispatchBuffers = 0;
  return atexit(func: dynamic_atexit_destructor_for__g_DispatchBuffers__);
}

//------------------------------------------------------------------------------
// Address: 0x100513B0
// Name: _dynamic_initializer_for__g_DisconnectHandlers__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_DisconnectHandlers__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_DisconnectHandlers__);
}

//------------------------------------------------------------------------------
// Address: 0x100513C0
// Name: _dynamic_initializer_for__g_CurrentStageCS__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CurrentStageCS__()
{
  CCriticalSection::CCriticalSection(this: &g_CurrentStageCS);
  return atexit(func: dynamic_atexit_destructor_for__g_CurrentStageCS__);
}

//------------------------------------------------------------------------------
// Address: 0x100513E0
// Name: _dynamic_initializer_for__g_WorkerCommandLine__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_WorkerCommandLine__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_WorkerCommandLine__);
}

//------------------------------------------------------------------------------
// Address: 0x100513F0
// Name: _dynamic_initializer_for__g_VMPIInternalDispatchReg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void dynamic_initializer_for__g_VMPIInternalDispatchReg__()
{
  dword_1016FF2C = (int)VMPI_InternalDispatchFn;
}

//------------------------------------------------------------------------------
// Address: 0x10051400
// Name: _dynamic_initializer_for__g_MasterBroadcaster__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_MasterBroadcaster__()
{
  CMasterBroadcaster::CMasterBroadcaster(this: &g_MasterBroadcaster);
  return atexit(func: dynamic_atexit_destructor_for__g_MasterBroadcaster__);
}

//------------------------------------------------------------------------------
// Address: 0x10051420
// Name: _dynamic_initializer_for____g_CreateIBaseFileSystem_reg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
InterfaceReg *dynamic_initializer_for____g_CreateIBaseFileSystem_reg__()
{
  return InterfaceReg::InterfaceReg(
           this: &_g_CreateIBaseFileSystem_reg,
           fn: GetVMPIFileSystem,
           pName: "VBaseFileSystem011");
}

//------------------------------------------------------------------------------
// Address: 0x10051440
// Name: _dynamic_initializer_for____g_CreateIFileSystem_reg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
InterfaceReg *dynamic_initializer_for____g_CreateIFileSystem_reg__()
{
  return InterfaceReg::InterfaceReg(this: &_g_CreateIFileSystem_reg, fn: GetFullFileSystem, pName: "VFileSystem017");
}

//------------------------------------------------------------------------------
// Address: 0x10051460
// Name: _dynamic_initializer_for__g_DispatchReg_FileSystem__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDispatchReg *dynamic_initializer_for__g_DispatchReg_FileSystem__()
{
  return CDispatchReg::CDispatchReg(this: &g_DispatchReg_FileSystem, iPacketID: 0, fn: FileSystemRecv);
}

//------------------------------------------------------------------------------
// Address: 0x10051480
// Name: _dynamic_initializer_for__g_VMPIPacketIDReg_VMPI_PACKETID_FILESYSTEM__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CVMPIPacketIDReg *dynamic_initializer_for__g_VMPIPacketIDReg_VMPI_PACKETID_FILESYSTEM__()
{
  return CVMPIPacketIDReg::CVMPIPacketIDReg(
           this: &g_VMPIPacketIDReg_VMPI_PACKETID_FILESYSTEM,
           nPacketID: 0,
           nSubPacketID: -1,
           pName: "VMPI_PACKETID_FILESYSTEM");
}

//------------------------------------------------------------------------------
// Address: 0x100514A0
// Name: _dynamic_initializer_for__g_VMPIPacketIDReg_VMPI_DISTRIBUTEWORK_PACKETID__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CVMPIPacketIDReg *dynamic_initializer_for__g_VMPIPacketIDReg_VMPI_DISTRIBUTEWORK_PACKETID__()
{
  return CVMPIPacketIDReg::CVMPIPacketIDReg(
           this: &g_VMPIPacketIDReg_VMPI_DISTRIBUTEWORK_PACKETID,
           nPacketID: 2,
           nSubPacketID: -1,
           pName: "VMPI_DISTRIBUTEWORK_PACKETID");
}

//------------------------------------------------------------------------------
// Address: 0x100514C0
// Name: _dynamic_initializer_for__g_VMPISubPacketIDReg_DW_SUBPACKETID_MASTER_READY__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CVMPIPacketIDReg *dynamic_initializer_for__g_VMPISubPacketIDReg_DW_SUBPACKETID_MASTER_READY__()
{
  return CVMPIPacketIDReg::CVMPIPacketIDReg(
           this: &g_VMPISubPacketIDReg_DW_SUBPACKETID_MASTER_READY,
           nPacketID: 2,
           nSubPacketID: 0,
           pName: "DW_SUBPACKETID_MASTER_READY");
}

//------------------------------------------------------------------------------
// Address: 0x100514E0
// Name: _dynamic_initializer_for__g_VMPISubPacketIDReg_DW_SUBPACKETID_WORKER_READY__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CVMPIPacketIDReg *dynamic_initializer_for__g_VMPISubPacketIDReg_DW_SUBPACKETID_WORKER_READY__()
{
  return CVMPIPacketIDReg::CVMPIPacketIDReg(
           this: &g_VMPISubPacketIDReg_DW_SUBPACKETID_WORKER_READY,
           nPacketID: 2,
           nSubPacketID: 1,
           pName: "DW_SUBPACKETID_WORKER_READY");
}

//------------------------------------------------------------------------------
// Address: 0x10051500
// Name: _dynamic_initializer_for__g_VMPISubPacketIDReg_DW_SUBPACKETID_MASTER_FINISHED__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CVMPIPacketIDReg *dynamic_initializer_for__g_VMPISubPacketIDReg_DW_SUBPACKETID_MASTER_FINISHED__()
{
  return CVMPIPacketIDReg::CVMPIPacketIDReg(
           this: &g_VMPISubPacketIDReg_DW_SUBPACKETID_MASTER_FINISHED,
           nPacketID: 2,
           nSubPacketID: 2,
           pName: "DW_SUBPACKETID_MASTER_FINISHED");
}

//------------------------------------------------------------------------------
// Address: 0x10051520
// Name: _dynamic_initializer_for__g_VMPISubPacketIDReg_DW_SUBPACKETID_WU_RESULTS__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CVMPIPacketIDReg *dynamic_initializer_for__g_VMPISubPacketIDReg_DW_SUBPACKETID_WU_RESULTS__()
{
  return CVMPIPacketIDReg::CVMPIPacketIDReg(
           this: &g_VMPISubPacketIDReg_DW_SUBPACKETID_WU_RESULTS,
           nPacketID: 2,
           nSubPacketID: 4,
           pName: "DW_SUBPACKETID_WU_RESULTS");
}

//------------------------------------------------------------------------------
// Address: 0x10051540
// Name: _dynamic_initializer_for__g_VMPISubPacketIDReg_DW_SUBPACKETID_WU_STARTED__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CVMPIPacketIDReg *dynamic_initializer_for__g_VMPISubPacketIDReg_DW_SUBPACKETID_WU_STARTED__()
{
  return CVMPIPacketIDReg::CVMPIPacketIDReg(
           this: &g_VMPISubPacketIDReg_DW_SUBPACKETID_WU_STARTED,
           nPacketID: 2,
           nSubPacketID: 6,
           pName: "DW_SUBPACKETID_WU_STARTED");
}

//------------------------------------------------------------------------------
// Address: 0x10051560
// Name: _dynamic_initializer_for__g_DistributeWorkReg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDispatchReg *dynamic_initializer_for__g_DistributeWorkReg__()
{
  return CDispatchReg::CDispatchReg(this: &g_DistributeWorkReg, iPacketID: 2, fn: DistributeWorkDispatch);
}

//------------------------------------------------------------------------------
// Address: 0x10051580
// Name: _dynamic_initializer_for__g_DSInfo__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_DSInfo__()
{
  CCriticalSection::CCriticalSection(this: &g_DSInfo.m_WorkerInfo.m_WorkUnitsRunningCS);
  return atexit(func: dynamic_atexit_destructor_for__g_DSInfo__);
}

//------------------------------------------------------------------------------
// Address: 0x100515A0
// Name: _dynamic_initializer_for__g_wuCountByProcess__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_wuCountByProcess__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_wuCountByProcess__);
}

//------------------------------------------------------------------------------
// Address: 0x100515B0
// Name: _dynamic_initializer_for__g_MasterWorkUnitCompletedList__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_MasterWorkUnitCompletedList__()
{
  CCriticalSection::CCriticalSection(this: &g_MasterWorkUnitCompletedList);
  g_MasterWorkUnitCompletedList.m_Data.m_CompletedWUs.m_Memory.m_pMemory = nullptr;
  g_MasterWorkUnitCompletedList.m_Data.m_CompletedWUs.m_Memory.m_nAllocationCount = 0;
  g_MasterWorkUnitCompletedList.m_Data.m_CompletedWUs.m_Memory.m_nGrowSize = 0;
  g_MasterWorkUnitCompletedList.m_Data.m_CompletedWUs.m_Size = 0;
  g_MasterWorkUnitCompletedList.m_Data.m_CompletedWUs.m_pElements = nullptr;
  return atexit(func: dynamic_atexit_destructor_for__g_MasterWorkUnitCompletedList__);
}

//------------------------------------------------------------------------------
// Address: 0x100515F0
// Name: _dynamic_initializer_for__g_MasterWorkUnitsTracker__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_MasterWorkUnitsTracker__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_MasterWorkUnitsTracker__);
}

//------------------------------------------------------------------------------
// Address: 0x10051600
// Name: _dynamic_initializer_for__g_VMPISubPacketIDReg_VMPI_FSPACKETID_FILE_REQUEST__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CVMPIPacketIDReg *dynamic_initializer_for__g_VMPISubPacketIDReg_VMPI_FSPACKETID_FILE_REQUEST__()
{
  return CVMPIPacketIDReg::CVMPIPacketIDReg(
           this: &g_VMPISubPacketIDReg_VMPI_FSPACKETID_FILE_REQUEST,
           nPacketID: 0,
           nSubPacketID: 1,
           pName: "VMPI_FSPACKETID_FILE_REQUEST");
}

//------------------------------------------------------------------------------
// Address: 0x10051620
// Name: _dynamic_initializer_for__g_VMPISubPacketIDReg_VMPI_FSPACKETID_FILE_RESPONSE__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CVMPIPacketIDReg *dynamic_initializer_for__g_VMPISubPacketIDReg_VMPI_FSPACKETID_FILE_RESPONSE__()
{
  return CVMPIPacketIDReg::CVMPIPacketIDReg(
           this: &g_VMPISubPacketIDReg_VMPI_FSPACKETID_FILE_RESPONSE,
           nPacketID: 0,
           nSubPacketID: 2,
           pName: "VMPI_FSPACKETID_FILE_RESPONSE");
}

//------------------------------------------------------------------------------
// Address: 0x10051640
// Name: _dynamic_initializer_for__g_VMPISubPacketIDReg_VMPI_FSPACKETID_CHUNK_RECEIVED__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CVMPIPacketIDReg *dynamic_initializer_for__g_VMPISubPacketIDReg_VMPI_FSPACKETID_CHUNK_RECEIVED__()
{
  return CVMPIPacketIDReg::CVMPIPacketIDReg(
           this: &g_VMPISubPacketIDReg_VMPI_FSPACKETID_CHUNK_RECEIVED,
           nPacketID: 0,
           nSubPacketID: 3,
           pName: "VMPI_FSPACKETID_CHUNK_RECEIVED");
}

//------------------------------------------------------------------------------
// Address: 0x10051660
// Name: _dynamic_initializer_for__g_VMPISubPacketIDReg_VMPI_FSPACKETID_FILE_RECEIVED__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CVMPIPacketIDReg *dynamic_initializer_for__g_VMPISubPacketIDReg_VMPI_FSPACKETID_FILE_RECEIVED__()
{
  return CVMPIPacketIDReg::CVMPIPacketIDReg(
           this: &g_VMPISubPacketIDReg_VMPI_FSPACKETID_FILE_RECEIVED,
           nPacketID: 0,
           nSubPacketID: 4,
           pName: "VMPI_FSPACKETID_FILE_RECEIVED");
}

//------------------------------------------------------------------------------
// Address: 0x10051680
// Name: _dynamic_initializer_for__g_VMPISubPacketIDReg_VMPI_FSPACKETID_MULTICAST_ADDR__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CVMPIPacketIDReg *dynamic_initializer_for__g_VMPISubPacketIDReg_VMPI_FSPACKETID_MULTICAST_ADDR__()
{
  return CVMPIPacketIDReg::CVMPIPacketIDReg(
           this: &g_VMPISubPacketIDReg_VMPI_FSPACKETID_MULTICAST_ADDR,
           nPacketID: 0,
           nSubPacketID: 5,
           pName: "VMPI_FSPACKETID_MULTICAST_ADDR");
}

//------------------------------------------------------------------------------
// Address: 0x100516A0
// Name: _dynamic_initializer_for__g_VMPISubPacketIDReg_VMPI_FSPACKETID_FILE_CHUNK__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CVMPIPacketIDReg *dynamic_initializer_for__g_VMPISubPacketIDReg_VMPI_FSPACKETID_FILE_CHUNK__()
{
  return CVMPIPacketIDReg::CVMPIPacketIDReg(
           this: &g_VMPISubPacketIDReg_VMPI_FSPACKETID_FILE_CHUNK,
           nPacketID: 0,
           nSubPacketID: 6,
           pName: "VMPI_FSPACKETID_FILE_CHUNK");
}

//------------------------------------------------------------------------------
// Address: 0x100516C0
// Name: _dynamic_initializer_for__g_Starter__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_Starter__()
{
  WSAData WSAData; // [esp+0h] [ebp-190h] BYREF

  return WSAStartup(wVersionRequested: 0x202u, lpWSAData: &WSAData);
}

//------------------------------------------------------------------------------
// Address: 0x100516E0
// Name: _dynamic_initializer_for__g_MulticastIP__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CIPAddr *dynamic_initializer_for__g_MulticastIP__()
{
  return CIPAddr::CIPAddr(this: &g_MulticastIP);
}

//------------------------------------------------------------------------------
// Address: 0x100516F0
// Name: _dynamic_initializer_for__g_FileResponsesCS__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_FileResponsesCS__()
{
  CCriticalSection::CCriticalSection(this: &g_FileResponsesCS);
  return atexit(func: dynamic_atexit_destructor_for__g_FileResponsesCS__);
}

//------------------------------------------------------------------------------
// Address: 0x10051710
// Name: _dynamic_initializer_for__g_FileResponses__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_FileResponses__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_FileResponses__);
}

//------------------------------------------------------------------------------
// Address: 0x10051720
// Name: _dynamic_initializer_for__g_FileChunkPackets__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_FileChunkPackets__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_FileChunkPackets__);
}

//------------------------------------------------------------------------------
// Address: 0x10051730
// Name: _dynamic_initializer_for__g_WorkUnits__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_WorkUnits__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_WorkUnits__);
}

//------------------------------------------------------------------------------
// Address: 0x10051740
// Name: _dynamic_initializer_for__g_WUStatus__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_WUStatus__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_WUStatus__);
}

//------------------------------------------------------------------------------
// Address: 0x10051750
// Name: _dynamic_initializer_for__g_BitWriteMasksInit__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CBitWriteMasksInit *dynamic_initializer_for__g_BitWriteMasksInit__()
{
  return CBitWriteMasksInit::CBitWriteMasksInit(this: &g_BitWriteMasksInit);
}

//------------------------------------------------------------------------------
// Address: 0x10051760
// Name: _dynamic_initializer_for__g_ExpressionEvaluator__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_ExpressionEvaluator__()
{
  CExpressionEvaluator::CExpressionEvaluator(this: (CEvent *)&g_ExpressionEvaluator);
  return atexit(func: dynamic_atexit_destructor_for__g_ExpressionEvaluator__);
}

//------------------------------------------------------------------------------
// Address: 0x10051780
// Name: _dynamic_initializer_for__g_KVMutex__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_KVMutex__()
{
  g_KVMutex.m_ownerID = 0;
  g_KVMutex.m_depth = 0;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10051790
// Name: _dynamic_initializer_for__s_EmptyConVar__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_EmptyConVar__()
{
  CEmptyConVar::CEmptyConVar(this: &s_EmptyConVar);
  return atexit(func: dynamic_atexit_destructor_for__s_EmptyConVar__);
}

//------------------------------------------------------------------------------
// Address: 0x100517B0
// Name: _dynamic_atexit_destructor_for__g_comboEmission__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_comboEmission__()
{
  if ( g_comboEmission.m_sSuffix._Myres >= 0x10 )
    free(pMem: g_comboEmission.m_sSuffix._Bx._Ptr);
  g_comboEmission.m_sSuffix._Myres = 15;
  g_comboEmission.m_sSuffix._Mysize = 0;
  g_comboEmission.m_sSuffix._Bx._Buf[0] = 0;
  if ( g_comboEmission.m_sPrefix._Myres >= 0x10 )
    free(pMem: g_comboEmission.m_sPrefix._Bx._Ptr);
  g_comboEmission.m_sPrefix._Mysize = 0;
  g_comboEmission.m_sPrefix._Bx._Buf[0] = 0;
  g_comboEmission.m_sPrefix._Myres = 15;
}

//------------------------------------------------------------------------------
// Address: 0x10051A10
// Name: _Worker_GetLocalCopyOfShaders_::_21_::_dynamic_atexit_destructor_for__s_autoCloseHackedFiles__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl Worker_GetLocalCopyOfShaders_::_21_::_dynamic_atexit_destructor_for__s_autoCloseHackedFiles__()
{
  int i; // esi

  for ( i = 0; i < s_arrHackedFiles.m_Size; ++i )
    fclose(stream: s_arrHackedFiles.m_Memory.m_pMemory[i]);
}

//------------------------------------------------------------------------------
// Address: 0x10051A40
// Name: _anonymous_namespace_::_dynamic_atexit_destructor_for__g_arrCompileEntries__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl anonymous_namespace_::_dynamic_atexit_destructor_for__g_arrCompileEntries__()
{
  CfgProcessor::CfgEntryInfo *v0; // [esp-8h] [ebp-8h]
  CfgProcessor::CfgEntryInfo *m_p; // [esp-4h] [ebp-4h]

  m_p = `anonymous namespace'::g_arrCompileEntries.m_p;
  `anonymous namespace'::g_arrCompileEntries.m_p = nullptr;
  free(pMem: m_p);
  v0 = `anonymous namespace'::g_arrCompileEntries.m_p;
  `anonymous namespace'::g_arrCompileEntries.m_p = nullptr;
  free(pMem: v0);
}

//------------------------------------------------------------------------------
// Address: 0x10051A70
// Name: _dynamic_atexit_destructor_for__g_Master_ShaderWrittenToDisk__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_Master_ShaderWrittenToDisk__()
{
  CUtlSymbolTable::~CUtlSymbolTable(this: &g_Master_ShaderWrittenToDisk.m_SymbolTable);
  CUtlVector<CWorkerAccumState<CThreadNullMutex>::SubProcess *,CUtlMemory<CWorkerAccumState<CThreadNullMutex>::SubProcess *,int>>::~CUtlVector<CWorkerAccumState<CThreadNullMutex>::SubProcess *,CUtlMemory<CWorkerAccumState<CThreadNullMutex>::SubProcess *,int>>(this: (CUtlVector<CFileResponse,CUtlMemory<CFileResponse,int> > *)&g_Master_ShaderWrittenToDisk);
}

//------------------------------------------------------------------------------
// Address: 0x10051A90
// Name: _Worker_GetLocalCopyOfShaders_::_20_::_dynamic_atexit_destructor_for__s_arrHackedFiles__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl Worker_GetLocalCopyOfShaders_::_20_::_dynamic_atexit_destructor_for__s_arrHackedFiles__()
{
  CUtlVector<CWorkerAccumState<CThreadNullMutex>::SubProcess *,CUtlMemory<CWorkerAccumState<CThreadNullMutex>::SubProcess *,int>>::~CUtlVector<CWorkerAccumState<CThreadNullMutex>::SubProcess *,CUtlMemory<CWorkerAccumState<CThreadNullMutex>::SubProcess *,int>>(this: (CUtlVector<CFileResponse,CUtlMemory<CFileResponse,int> > *)&s_arrHackedFiles);
}

//------------------------------------------------------------------------------
// Address: 0x10051AA0
// Name: _dynamic_atexit_destructor_for__g_ShaderToShaderInfo__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_ShaderToShaderInfo__()
{
  CUtlSymbolTable::~CUtlSymbolTable(this: &g_ShaderToShaderInfo.m_SymbolTable);
  CUtlVector<CWorkerAccumState<CThreadNullMutex>::SubProcess *,CUtlMemory<CWorkerAccumState<CThreadNullMutex>::SubProcess *,int>>::~CUtlVector<CWorkerAccumState<CThreadNullMutex>::SubProcess *,CUtlMemory<CWorkerAccumState<CThreadNullMutex>::SubProcess *,int>>(this: (CUtlVector<CFileResponse,CUtlMemory<CFileResponse,int> > *)&g_ShaderToShaderInfo);
}

//------------------------------------------------------------------------------
// Address: 0x10051AC0
// Name: _dynamic_atexit_destructor_for__g_Master_ShaderHadError__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_Master_ShaderHadError__()
{
  CUtlSymbolTable::~CUtlSymbolTable(this: &g_Master_ShaderHadError.m_SymbolTable);
  CUtlVector<CWorkerAccumState<CThreadNullMutex>::SubProcess *,CUtlMemory<CWorkerAccumState<CThreadNullMutex>::SubProcess *,int>>::~CUtlVector<CWorkerAccumState<CThreadNullMutex>::SubProcess *,CUtlMemory<CWorkerAccumState<CThreadNullMutex>::SubProcess *,int>>(this: (CUtlVector<CFileResponse,CUtlMemory<CFileResponse,int> > *)&g_Master_ShaderHadError);
}

//------------------------------------------------------------------------------
// Address: 0x10051AE0
// Name: _dynamic_atexit_destructor_for__g_ShaderByteCode__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_ShaderByteCode__()
{
  CUtlSymbolTable::~CUtlSymbolTable(this: &g_ShaderByteCode.m_SymbolTable);
  CUtlVector<CWorkerAccumState<CThreadNullMutex>::SubProcess *,CUtlMemory<CWorkerAccumState<CThreadNullMutex>::SubProcess *,int>>::~CUtlVector<CWorkerAccumState<CThreadNullMutex>::SubProcess *,CUtlMemory<CWorkerAccumState<CThreadNullMutex>::SubProcess *,int>>(this: (CUtlVector<CFileResponse,CUtlMemory<CFileResponse,int> > *)&g_ShaderByteCode);
}

//------------------------------------------------------------------------------
// Address: 0x10051B00
// Name: _dynamic_atexit_destructor_for__g_Master_CompilerMsgInfo__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_Master_CompilerMsgInfo__()
{
  CUtlSymbolTable::~CUtlSymbolTable(this: &g_Master_CompilerMsgInfo.m_SymbolTable);
  CUtlVector<CompilerMsgInfo,CUtlMemory<CompilerMsgInfo,int>>::~CUtlVector<CompilerMsgInfo,CUtlMemory<CompilerMsgInfo,int>>(this: &g_Master_CompilerMsgInfo.m_Vector);
}

//------------------------------------------------------------------------------
// Address: 0x10051B20
// Name: _dynamic_atexit_destructor_for__g_PS3DebugInfoFileSet__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_PS3DebugInfoFileSet__()
{
  CUtlSymbolTableLargeBase<CNonThreadsafeTree<1>,1>::RemoveAll(this: &g_PS3DebugInfoFileSet);
  CUtlVector<CWorkerAccumState<CThreadNullMutex>::SubProcess *,CUtlMemory<CWorkerAccumState<CThreadNullMutex>::SubProcess *,int>>::~CUtlVector<CWorkerAccumState<CThreadNullMutex>::SubProcess *,CUtlMemory<CWorkerAccumState<CThreadNullMutex>::SubProcess *,int>>(this: (CUtlVector<CFileResponse,CUtlMemory<CFileResponse,int> > *)&g_PS3DebugInfoFileSet.m_StringPools);
  CUtlRBTree<CUtlSymbolTableLargeBaseTreeEntry_t *,int,CTreeEntryLess<CNonThreadsafeTree<1>,1>,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTableLargeBaseTreeEntry_t *,int>,int>>::~CUtlRBTree<CUtlSymbolTableLargeBaseTreeEntry_t *,int,CTreeEntryLess<CNonThreadsafeTree<1>,1>,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTableLargeBaseTreeEntry_t *,int>,int>>(this: &g_PS3DebugInfoFileSet.m_Lookup);
}

//------------------------------------------------------------------------------
// Address: 0x10051B40
// Name: _dynamic_atexit_destructor_for__g_CleanupSymbolTable__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CleanupSymbolTable__()
{
  CUtlSymbolTableMT *v0; // esi

  v0 = CUtlSymbol::s_pSymbolTable;
  if ( CUtlSymbol::s_pSymbolTable != nullptr )
  {
    CUtlSymbolTable::RemoveAll(this: CUtlSymbol::s_pSymbolTable);
    CUtlVector<CWorkerAccumState<CThreadNullMutex>::SubProcess *,CUtlMemory<CWorkerAccumState<CThreadNullMutex>::SubProcess *,int>>::~CUtlVector<CWorkerAccumState<CThreadNullMutex>::SubProcess *,CUtlMemory<CWorkerAccumState<CThreadNullMutex>::SubProcess *,int>>(this: (CUtlVector<CFileResponse,CUtlMemory<CFileResponse,int> > *)&v0->m_StringPools);
    CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::~CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>(this: &v0->m_Lookup);
    free(pMem: v0);
  }
  CUtlSymbol::s_pSymbolTable = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10051B80
// Name: _dynamic_atexit_destructor_for__g_PersistentPacketsCS__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_PersistentPacketsCS__()
{
  CCriticalSection::~CCriticalSection(this: &g_PersistentPacketsCS);
}

//------------------------------------------------------------------------------
// Address: 0x10051B90
// Name: _dynamic_atexit_destructor_for__g_VMPIMessagesCS__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_VMPIMessagesCS__()
{
  CCriticalSection::~CCriticalSection(this: &g_VMPIMessagesCS);
}

//------------------------------------------------------------------------------
// Address: 0x10051BA0
// Name: _dynamic_atexit_destructor_for__g_VMPIMessagesEvent__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_VMPIMessagesEvent__()
{
  CEvent::~CEvent(this: &g_VMPIMessagesEvent);
}

//------------------------------------------------------------------------------
// Address: 0x10051BB0
// Name: _dynamic_atexit_destructor_for__g_ErrorSocketsEvent__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_ErrorSocketsEvent__()
{
  CEvent::~CEvent(this: &g_ErrorSocketsEvent);
}

//------------------------------------------------------------------------------
// Address: 0x10051BC0
// Name: _dynamic_atexit_destructor_for__g_ErrorSocketsCS__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_ErrorSocketsCS__()
{
  CCriticalSection::~CCriticalSection(this: &g_ErrorSocketsCS);
}

//------------------------------------------------------------------------------
// Address: 0x10051BD0
// Name: _dynamic_atexit_destructor_for__g_ConnectionsCS__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_ConnectionsCS__()
{
  CCriticalSection::~CCriticalSection(this: &g_ConnectionsCS);
}

//------------------------------------------------------------------------------
// Address: 0x10051BE0
// Name: _dynamic_atexit_destructor_for__g_CurrentStageCS__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CurrentStageCS__()
{
  CCriticalSection::~CCriticalSection(this: &g_CurrentStageCS);
}

//------------------------------------------------------------------------------
// Address: 0x10051BF0
// Name: _dynamic_atexit_destructor_for__g_DispatchBuffers__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_DispatchBuffers__()
{
  TSLNodeBase_t *v0; // eax
  TSLNodeBase_t *Next; // esi

  v0 = CTSListBase::Detach(this: &g_DispatchBuffers);
  if ( v0 != nullptr )
  {
    do
    {
      Next = v0->Next;
      free(pMem: v0);
      v0 = Next;
    }
    while ( Next != nullptr );
  }
  CTSListBase::Detach(this: &g_DispatchBuffers);
}

//------------------------------------------------------------------------------
// Address: 0x10051C20
// Name: _dynamic_atexit_destructor_for__g_PersistentPackets__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_PersistentPackets__()
{
  CUtlLinkedList<CUtlVector<char,CUtlMemory<char,int>> *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlVector<char,CUtlMemory<char,int>> *,unsigned short>,unsigned short>>::RemoveAll(this: &g_PersistentPackets);
  if ( g_PersistentPackets.m_Memory.m_nGrowSize >= 0 )
  {
    if ( g_PersistentPackets.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: g_PersistentPackets.m_Memory.m_pMemory);
      g_PersistentPackets.m_Memory.m_pMemory = nullptr;
    }
    g_PersistentPackets.m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10051C70
// Name: _dynamic_atexit_destructor_for__g_OriginalCommandLineParameters__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_OriginalCommandLineParameters__()
{
  CUtlVector<CWorkerAccumState<CThreadNullMutex>::SubProcess *,CUtlMemory<CWorkerAccumState<CThreadNullMutex>::SubProcess *,int>>::~CUtlVector<CWorkerAccumState<CThreadNullMutex>::SubProcess *,CUtlMemory<CWorkerAccumState<CThreadNullMutex>::SubProcess *,int>>(this: (CUtlVector<CFileResponse,CUtlMemory<CFileResponse,int> > *)&g_OriginalCommandLineParameters);
}

//------------------------------------------------------------------------------
// Address: 0x10051C80
// Name: _dynamic_atexit_destructor_for__g_VMPIMessages__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_VMPIMessages__()
{
  CUtlLinkedList<CPartitionInfo *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CPartitionInfo *,int>,int>>::RemoveAll(this: (CUtlLinkedList<CFileChunkPacket *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CFileChunkPacket *,int>,int> > *)&g_VMPIMessages);
  if ( g_VMPIMessages.m_Memory.m_nGrowSize >= 0 )
  {
    if ( g_VMPIMessages.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: g_VMPIMessages.m_Memory.m_pMemory);
      g_VMPIMessages.m_Memory.m_pMemory = nullptr;
    }
    g_VMPIMessages.m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10051CD0
// Name: _dynamic_atexit_destructor_for__g_ErrorSockets__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_ErrorSockets__()
{
  CUtlLinkedList<CPartitionInfo *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CPartitionInfo *,int>,int>>::RemoveAll(this: (CUtlLinkedList<CFileChunkPacket *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CFileChunkPacket *,int>,int> > *)&g_ErrorSockets);
  if ( g_ErrorSockets.m_Memory.m_nGrowSize >= 0 )
  {
    if ( g_ErrorSockets.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: g_ErrorSockets.m_Memory.m_pMemory);
      g_ErrorSockets.m_Memory.m_pMemory = nullptr;
    }
    g_ErrorSockets.m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10051D20
// Name: _dynamic_atexit_destructor_for__g_DisconnectHandlers__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_DisconnectHandlers__()
{
  CUtlLinkedList<CPartitionInfo *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CPartitionInfo *,int>,int>>::RemoveAll(this: (CUtlLinkedList<CFileChunkPacket *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CFileChunkPacket *,int>,int> > *)&g_DisconnectHandlers);
  if ( g_DisconnectHandlers.m_Memory.m_nGrowSize >= 0 )
  {
    if ( g_DisconnectHandlers.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: g_DisconnectHandlers.m_Memory.m_pMemory);
      g_DisconnectHandlers.m_Memory.m_pMemory = nullptr;
    }
    g_DisconnectHandlers.m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10051D70
// Name: _dynamic_atexit_destructor_for__g_WorkerCommandLine__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_WorkerCommandLine__()
{
  CUtlVector<CWorkerAccumState<CThreadNullMutex>::SubProcess *,CUtlMemory<CWorkerAccumState<CThreadNullMutex>::SubProcess *,int>>::~CUtlVector<CWorkerAccumState<CThreadNullMutex>::SubProcess *,CUtlMemory<CWorkerAccumState<CThreadNullMutex>::SubProcess *,int>>(this: (CUtlVector<CFileResponse,CUtlMemory<CFileResponse,int> > *)&g_WorkerCommandLine);
}

//------------------------------------------------------------------------------
// Address: 0x10051D80
// Name: _dynamic_atexit_destructor_for__g_MasterBroadcaster__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_MasterBroadcaster__()
{
  CMasterBroadcaster::Term(this: &g_MasterBroadcaster);
  CEvent::~CEvent(this: &g_MasterBroadcaster.m_hShutdownReply);
  CEvent::~CEvent(this: &g_MasterBroadcaster.m_hShutdownEvent);
  CUtlVector<CWorkerAccumState<CThreadNullMutex>::SubProcess *,CUtlMemory<CWorkerAccumState<CThreadNullMutex>::SubProcess *,int>>::~CUtlVector<CWorkerAccumState<CThreadNullMutex>::SubProcess *,CUtlMemory<CWorkerAccumState<CThreadNullMutex>::SubProcess *,int>>(this: (CUtlVector<CFileResponse,CUtlMemory<CFileResponse,int> > *)&g_MasterBroadcaster.m_PatchWorkerIPs);
  CUtlVector<CWorkerAccumState<CThreadNullMutex>::SubProcess *,CUtlMemory<CWorkerAccumState<CThreadNullMutex>::SubProcess *,int>>::~CUtlVector<CWorkerAccumState<CThreadNullMutex>::SubProcess *,CUtlMemory<CWorkerAccumState<CThreadNullMutex>::SubProcess *,int>>(this: (CUtlVector<CFileResponse,CUtlMemory<CFileResponse,int> > *)&g_MasterBroadcaster.m_BroadcastInfo.m_Args);
}

//------------------------------------------------------------------------------
// Address: 0x10051DC0
// Name: _dynamic_atexit_destructor_for__g_wuCountByProcess__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_wuCountByProcess__()
{
  CUtlVector<CWorkerAccumState<CThreadNullMutex>::SubProcess *,CUtlMemory<CWorkerAccumState<CThreadNullMutex>::SubProcess *,int>>::~CUtlVector<CWorkerAccumState<CThreadNullMutex>::SubProcess *,CUtlMemory<CWorkerAccumState<CThreadNullMutex>::SubProcess *,int>>(this: (CUtlVector<CFileResponse,CUtlMemory<CFileResponse,int> > *)&g_wuCountByProcess);
}

//------------------------------------------------------------------------------
// Address: 0x10051DD0
// Name: _dynamic_atexit_destructor_for__g_MasterWorkUnitCompletedList__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_MasterWorkUnitCompletedList__()
{
  CUtlVector<CWorkerAccumState<CThreadNullMutex>::SubProcess *,CUtlMemory<CWorkerAccumState<CThreadNullMutex>::SubProcess *,int>>::~CUtlVector<CWorkerAccumState<CThreadNullMutex>::SubProcess *,CUtlMemory<CWorkerAccumState<CThreadNullMutex>::SubProcess *,int>>(this: (CUtlVector<CFileResponse,CUtlMemory<CFileResponse,int> > *)&g_MasterWorkUnitCompletedList.m_Data);
  CCriticalSection::~CCriticalSection(this: &g_MasterWorkUnitCompletedList);
}

//------------------------------------------------------------------------------
// Address: 0x10051DF0
// Name: _dynamic_atexit_destructor_for__g_DSInfo__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_DSInfo__()
{
  CCriticalSection::~CCriticalSection(this: &g_DSInfo.m_WorkerInfo.m_WorkUnitsRunningCS);
  CUtlVector<CWorkerAccumState<CThreadNullMutex>::SubProcess *,CUtlMemory<CWorkerAccumState<CThreadNullMutex>::SubProcess *,int>>::~CUtlVector<CWorkerAccumState<CThreadNullMutex>::SubProcess *,CUtlMemory<CWorkerAccumState<CThreadNullMutex>::SubProcess *,int>>(this: (CUtlVector<CFileResponse,CUtlMemory<CFileResponse,int> > *)&g_DSInfo.m_WorkerInfo.m_WorkUnitsRunning);
}

//------------------------------------------------------------------------------
// Address: 0x10051E10
// Name: _dynamic_atexit_destructor_for__g_MasterWorkUnitsTracker__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_MasterWorkUnitsTracker__()
{
  CUtlVector<CWorkerAccumState<CThreadNullMutex>::SubProcess *,CUtlMemory<CWorkerAccumState<CThreadNullMutex>::SubProcess *,int>>::~CUtlVector<CWorkerAccumState<CThreadNullMutex>::SubProcess *,CUtlMemory<CWorkerAccumState<CThreadNullMutex>::SubProcess *,int>>(this: (CUtlVector<CFileResponse,CUtlMemory<CFileResponse,int> > *)&g_MasterWorkUnitsTracker);
}

//------------------------------------------------------------------------------
// Address: 0x10051E20
// Name: _dynamic_atexit_destructor_for__g_FileResponsesCS__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_FileResponsesCS__()
{
  CCriticalSection::~CCriticalSection(this: &g_FileResponsesCS);
}

//------------------------------------------------------------------------------
// Address: 0x10051E30
// Name: _dynamic_atexit_destructor_for__g_FileResponses__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_FileResponses__()
{
  CUtlVector<CWorkerAccumState<CThreadNullMutex>::SubProcess *,CUtlMemory<CWorkerAccumState<CThreadNullMutex>::SubProcess *,int>>::~CUtlVector<CWorkerAccumState<CThreadNullMutex>::SubProcess *,CUtlMemory<CWorkerAccumState<CThreadNullMutex>::SubProcess *,int>>(this: &g_FileResponses);
}

//------------------------------------------------------------------------------
// Address: 0x10051E40
// Name: _dynamic_atexit_destructor_for__g_FileChunkPackets__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_FileChunkPackets__()
{
  CUtlLinkedList<CPartitionInfo *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CPartitionInfo *,int>,int>>::RemoveAll(this: &g_FileChunkPackets);
  if ( g_FileChunkPackets.m_Memory.m_nGrowSize >= 0 )
  {
    if ( g_FileChunkPackets.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: g_FileChunkPackets.m_Memory.m_pMemory);
      g_FileChunkPackets.m_Memory.m_pMemory = nullptr;
    }
    g_FileChunkPackets.m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10051E90
// Name: _dynamic_atexit_destructor_for__g_WUStatus__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_WUStatus__()
{
  CUtlVector<CWorkerAccumState<CThreadNullMutex>::SubProcess *,CUtlMemory<CWorkerAccumState<CThreadNullMutex>::SubProcess *,int>>::~CUtlVector<CWorkerAccumState<CThreadNullMutex>::SubProcess *,CUtlMemory<CWorkerAccumState<CThreadNullMutex>::SubProcess *,int>>(this: (CUtlVector<CFileResponse,CUtlMemory<CFileResponse,int> > *)&g_WUStatus);
}

//------------------------------------------------------------------------------
// Address: 0x10051EA0
// Name: _dynamic_atexit_destructor_for__g_WorkUnits__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_WorkUnits__()
{
  CUtlVector<CWorkUnit,CUtlMemory<CWorkUnit,int>>::~CUtlVector<CWorkUnit,CUtlMemory<CWorkUnit,int>>(this: &g_WorkUnits);
}

//------------------------------------------------------------------------------
// Address: 0x10051EB0
// Name: _dynamic_atexit_destructor_for__g_ExpressionEvaluator__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_ExpressionEvaluator__()
{
  CExpressionEvaluator::~CExpressionEvaluator(this: &g_ExpressionEvaluator);
}

//------------------------------------------------------------------------------
// Address: 0x10051EC0
// Name: _dynamic_atexit_destructor_for__s_EmptyConVar__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_EmptyConVar__()
{
  s_EmptyConVar.ConVar::ConCommandBase::__vftable = (CEmptyConVar_vtbl *)&ConVar::`vftable'{for `ConCommandBase'};
  s_EmptyConVar.ConVar::IConVar::__vftable = (IConVar_vtbl *)&ConVar::`vftable'{for `IConVar'};
  if ( s_EmptyConVar.m_Value.m_pszString != nullptr )
  {
    free(pMem: s_EmptyConVar.m_Value.m_pszString);
    s_EmptyConVar.m_Value.m_pszString = nullptr;
  }
  CUtlVector<CWorkerAccumState<CThreadNullMutex>::SubProcess *,CUtlMemory<CWorkerAccumState<CThreadNullMutex>::SubProcess *,int>>::~CUtlVector<CWorkerAccumState<CThreadNullMutex>::SubProcess *,CUtlMemory<CWorkerAccumState<CThreadNullMutex>::SubProcess *,int>>(this: (CUtlVector<CFileResponse,CUtlMemory<CFileResponse,int> > *)&s_EmptyConVar.m_fnChangeCallbacks);
  s_EmptyConVar.ConVar::ConCommandBase::__vftable = (CEmptyConVar_vtbl *)&ConCommandBase::`vftable';
}
