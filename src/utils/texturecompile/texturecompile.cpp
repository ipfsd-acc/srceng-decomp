// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/texturecompile/texturecompile.cpp
// Functions: 44
// ============================================================

#include "utils\texturecompile\texturecompile.h"

//------------------------------------------------------------------------------
// Address: 0x10001310
// Name: public: void CUtlVector<char,class CUtlMemory<char,int>>::Purge(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<char,CUtlMemory<char,int>>::Purge(CUtlVector<char,CUtlMemory<char,int> > *this)
{
  bool v2; // sf
  char *m_pMemory; // ecx

  v2 = this->m_Memory.m_nGrowSize < 0;
  this->m_Size = 0;
  if ( v2 )
  {
    this->m_pElements = this->m_Memory.m_pMemory;
  }
  else
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    m_pMemory = this->m_Memory.m_pMemory;
    this->m_Memory.m_nAllocationCount = 0;
    this->m_pElements = m_pMemory;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10001720
// Name: bool StartWorkDispatch(class MessageBuffer __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
char __cdecl StartWorkDispatch()
{
  g_bGotStartWorkPacket = true;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10001730
// Name: void DebugOut(char const __near *,...)
// Source: json
//------------------------------------------------------------------------------
void DebugOut(const char *pMsg, ...)
{
  char msg[2048]; // [esp+0h] [ebp-800h] BYREF
  va_list ap; // [esp+80Ch] [ebp+Ch] BYREF

  va_start(ap, pMsg);
  _vsnprintf(string: msg, count: 0x800u, format: pMsg, ap);
  if ( g_bVerbose )
    _Msg(a1: "%s", msg);
}

//------------------------------------------------------------------------------
// Address: 0x10001780
// Name: void MyDisconnectHandler(int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MyDisconnectHandler()
{
  HANDLE CurrentProcess; // eax

  if ( !g_bMPIMaster )
  {
    _Msg(a1: "Master disconnected.\n ");
    DebugOut(pMsg: "Master disconnected.\n");
    CurrentProcess = GetCurrentProcess();
    TerminateProcess(hProcess: CurrentProcess, uExitCode: 1u);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100017C0
// Name: void VTFNameToTGAName(char const __near *,char __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl VTFNameToTGAName(const char *pSrcName, char *pDstName)
{
  const char *v2; // eax
  const char *v3; // edi

  *pDstName = 0;
  v2 = V_stristr(pStr: pSrcName, pSearch: "materials");
  v3 = v2;
  if ( v2 != nullptr )
    V_strncpy(pDest: pDstName, pSrc: pSrcName, maxLen: v2 - pSrcName + 1);
  V_strncat(pDest: pDstName, pSrc: "materialsrc", destBufferSize: 0x104u, max_chars_to_copy: -1);
  V_strncat(pDest: pDstName, pSrc: v3 + 9, destBufferSize: 0x104u, max_chars_to_copy: -1);
  V_StripExtension(in: pDstName, out: pDstName, outSize: strlen(pDstName));
  V_strncat(pDest: pDstName, pSrc: ".tga", destBufferSize: 0x104u, max_chars_to_copy: -1);
}

//------------------------------------------------------------------------------
// Address: 0x10001850
// Name: void MakeDirHier(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MakeDirHier(const char *pPath)
{
  unsigned int i; // esi
  char v2; // al
  char temp[1028]; // [esp+4h] [ebp-404h] BYREF

  V_strncpy(pDest: temp, pSrc: pPath, maxLen: 1024);
  for ( i = 0; i < strlen(temp); ++i )
  {
    v2 = temp[i];
    if ( v2 == 47 || v2 == 92 )
    {
      temp[i] = 0;
      mkdir(path: temp);
      temp[i] = 92;
    }
  }
  mkdir(path: temp);
}

//------------------------------------------------------------------------------
// Address: 0x100018F0
// Name: void SetupPaths(int,char __near * __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SetupPaths(int argc, char **argv)
{
  void (__thiscall ***v2)(_DWORD, int, char **); // eax
  int v3; // eax
  char *v4; // ecx
  char *v5; // edx
  char v6; // al
  int v7; // eax
  int v8; // eax
  char tmp[260]; // [esp+0h] [ebp-104h] BYREF

  GetTempPathA(nBufferLength: 0x104u, lpBuffer: g_WorkerTempPath);
  strcat(g_WorkerTempPath, "texturecompiletemp\\");
  sprintf(string: tmp, format: "rd /s /q \"%s\"", g_WorkerTempPath);
  system(command: tmp);
  mkdir(path: g_WorkerTempPath);
  v2 = (void (__thiscall ***)(_DWORD, int, char **))_CommandLine();
  (**v2)(a1: v2, a2: argc, a3: argv);
  v3 = _CommandLine();
  g_pGameDir = (const char *)(*(int (__thiscall **)(int, const char *, const char *))(*(_DWORD *)v3 + 32))(
                               a1: v3,
                               a2: "-gamedir",
                               a3: setName);
  v4 = *argv;
  v5 = g_ExeDir;
  do
  {
    v6 = *v4;
    *v5++ = *v4++;
  }
  while ( v6 != 0 );
  V_StripFilename(path: g_ExeDir);
  V_FixSlashes(pname: g_ExeDir, separator: 92);
  v7 = _CommandLine();
  g_pTextureOutputDir = (const char *)(*(int (__thiscall **)(int, const char *, const char *))(*(_DWORD *)v7 + 32))(
                                        a1: v7,
                                        a2: "-textureoutputdir",
                                        a3: setName);
  v8 = _CommandLine();
  g_bVerbose = (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v8 + 40))(a1: v8, a2: "-verbose") != 0;
}

//------------------------------------------------------------------------------
// Address: 0x10001A20
// Name: public: void CUtlMemory<bool,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<bool,int>::Grow(CUtlMemory<unsigned char,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  unsigned __int8 *m_pMemory; // edx

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
      this->m_pMemory = (unsigned __int8 *)_g_pMemAlloc->Realloc_2(
                                             this: _g_pMemAlloc,
                                             a2: m_pMemory,
                                             a3: m_nAllocationCount);
    else
      this->m_pMemory = (unsigned __int8 *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: m_nAllocationCount);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10001B50
// Name: void Worker_GetLocalCopyOfBinary(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Worker_GetLocalCopyOfBinary(char *pFilename)
{
  _iobuf *v1; // eax
  _iobuf *v2; // esi
  _iobuf *v3; // eax
  int v4; // edi
  int v5; // ebx
  _iobuf *v6; // esi
  char *v7; // [esp-4h] [ebp-244h]
  char tmpFilename[260]; // [esp+8h] [ebp-238h] BYREF
  char newFilename[260]; // [esp+10Ch] [ebp-134h] BYREF
  CUtlBuffer fileBuf; // [esp+210h] [ebp-30h] BYREF

  CUtlBuffer::CUtlBuffer(this: &fileBuf, growSize: 0, initSize: 0, nFlags: 0);
  sprintf(string: tmpFilename, format: "%s\\%s", g_ExeDir, pFilename);
  printf(format: "trying to open: %s\n", tmpFilename);
  v1 = fopen(file: tmpFilename, mode: "rb");
  v2 = v1;
  if ( v1 == nullptr )
  {
    v7 = pFilename;
    goto LABEL_3;
  }
  fseek(stream: v1, offset: 0, whence: 2);
  v4 = ftell(stream: v2);
  fseek(stream: v2, offset: 0, whence: 0);
  CUtlBuffer::EnsureCapacity(this: &fileBuf, num: v4);
  v5 = fread(buffer: fileBuf.m_Memory.m_pMemory, elementSize: 1u, count: v4, stream: v2);
  fclose(stream: v2);
  CUtlBuffer::SeekPut(this: &fileBuf, type: SEEK_HEAD, offset: v5);
  sprintf(string: newFilename, format: "%s%s", g_WorkerTempPath, pFilename);
  DebugOut(pMsg: "this is fucked \"%s\"\n", newFilename);
  v6 = fopen(file: newFilename, mode: "wb");
  if ( v6 == nullptr )
  {
    v7 = newFilename;
LABEL_3:
    v3 = __iob_func();
    fprintf(str: v3 + 2, format: "Can't open %s!\n", v7);
    exit(code: -1);
  }
  fwrite(buffer: fileBuf.m_Memory.m_pMemory, size: 1u, count: v4, stream: v6);
  fclose(stream: v6);
  if ( fileBuf.m_Memory.m_nGrowSize >= 0 && fileBuf.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: fileBuf.m_Memory.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x10001CB0
// Name: void Master_ReceiveWorkUnitFn(unsigned __int64,class MessageBuffer __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Master_ReceiveWorkUnitFn(unsigned __int64 iWorkUnit, MessageBuffer *pBuf)
{
  int v2; // edi
  MessageBuffer *v3; // ebx
  _iobuf *v4; // esi
  CUtlBuffer fileData; // [esp+0h] [ebp-34h] BYREF
  int m_Size; // [esp+30h] [ebp-4h]

  DebugOut(pMsg: "Master_ReceiveWorkUnitFn\n");
  m_Size = g_CompileCommands.m_Size;
  if ( g_CompileCommands.m_Size >= (int)iWorkUnit * g_nTexturesPerWorkUnit + g_nTexturesPerWorkUnit )
    m_Size = iWorkUnit * g_nTexturesPerWorkUnit + g_nTexturesPerWorkUnit;
  v2 = iWorkUnit * g_nTexturesPerWorkUnit;
  if ( (int)iWorkUnit * g_nTexturesPerWorkUnit < m_Size )
  {
    v3 = pBuf;
    do
    {
      MessageBuffer::read(this: v3, p: (char *)&iWorkUnit + 4, bytes: 4);
      if ( HIDWORD(iWorkUnit) != 0 )
      {
        CUtlBuffer::CUtlBuffer(this: &fileData, growSize: 0, initSize: 0, nFlags: 0);
        CUtlBuffer::EnsureCapacity(this: &fileData, num: SHIDWORD(iWorkUnit));
        MessageBuffer::read(this: v3, p: fileData.m_Memory.m_pMemory, bytes: SHIDWORD(iWorkUnit));
        _Warning(a1: "%s\n", g_CompileCommands.m_Memory.m_pMemory[v2]);
        v4 = fopen(file: g_CompileCommands.m_Memory.m_pMemory[v2], mode: "wb");
        if ( v4 == nullptr )
          _Error(a1: "Can't open %s for writing.\n", g_CompileCommands.m_Memory.m_pMemory[v2]);
        fwrite(buffer: fileData.m_Memory.m_pMemory, size: 1u, count: HIDWORD(iWorkUnit), stream: v4);
        fclose(stream: v4);
        if ( fileData.m_Memory.m_nGrowSize >= 0 && fileData.m_Memory.m_pMemory != nullptr )
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: fileData.m_Memory.m_pMemory);
      }
      ++v2;
    }
    while ( v2 < m_Size );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10001DD0
// Name: void Worker_ReadFilesToCopy(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Worker_ReadFilesToCopy()
{
  void *v0; // eax
  void *v1; // edi
  _iobuf *v2; // eax
  char *v3; // esi
  unsigned int v4; // kr00_4
  char v5; // cl
  char *v6; // eax
  const char *v7; // edi
  int m_Size; // eax
  int v9; // esi
  SourceTargetPair_t *m_pMemory; // ecx
  int v11; // eax
  SourceTargetPair_t *v12; // ebx
  char *v13; // eax
  char *v14; // eax
  char filename[1024]; // [esp+4h] [ebp-808h] BYREF
  char buf[1024]; // [esp+404h] [ebp-408h] BYREF
  char *v17; // [esp+804h] [ebp-8h]
  void *fp; // [esp+808h] [ebp-4h]

  sprintf(string: filename, format: "%s\\filestocopy.txt", g_pGameDir);
  DebugOut(pMsg: "using \"%s\" as filestocopy\n", filename);
  v0 = g_pFileSystem->Open(this: g_pFileSystem, a2: filename, a3: "r", a4: 0);
  v1 = v0;
  fp = v0;
  if ( v0 == nullptr )
  {
    v2 = __iob_func();
    fprintf(str: v2 + 2, format: "Can't open uniquefilestocopy.txt!\n");
    exit(code: -1);
  }
  if ( CmdLib_FGets(pOut: buf, outSize: 1024, hFile: v0) != nullptr )
  {
    v3 = &filename[1023];
    v17 = &filename[1023];
    do
    {
      v4 = strlen(buf);
      v5 = v3[v4];
      if ( v5 == 13 || v5 == 10 )
        v3[v4] = 0;
      v6 = V_stristr(pStr: buf, pSearch: "*");
      if ( v6 != nullptr )
      {
        *v6 = 0;
        v7 = v6 + 1;
        m_Size = g_SourceTargetPairs.m_Size;
        v9 = g_SourceTargetPairs.m_Size;
        if ( g_SourceTargetPairs.m_Size + 1 > g_SourceTargetPairs.m_Memory.m_nAllocationCount )
        {
          CUtlMemory<CTransmitRateMgr::CMachineRecord,int>::Grow(
            this: (CUtlMemory<CTransmitRateMgr::CMachineRecord,int> *)&g_SourceTargetPairs,
            num: g_SourceTargetPairs.m_Size - g_SourceTargetPairs.m_Memory.m_nAllocationCount + 1);
          m_Size = g_SourceTargetPairs.m_Size;
        }
        m_pMemory = g_SourceTargetPairs.m_Memory.m_pMemory;
        g_SourceTargetPairs.m_Size = m_Size + 1;
        v11 = m_Size - v9;
        g_SourceTargetPairs.m_pElements = g_SourceTargetPairs.m_Memory.m_pMemory;
        if ( v11 > 0 )
        {
          _V_memmove(
            dest: &g_SourceTargetPairs.m_Memory.m_pMemory[v9 + 1],
            src: &g_SourceTargetPairs.m_Memory.m_pMemory[v9],
            count: 8 * v11);
          m_pMemory = g_SourceTargetPairs.m_Memory.m_pMemory;
        }
        v12 = &m_pMemory[v9];
        if ( v7 != nullptr && (v13 = (char *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: strlen(v7) + 1)) != nullptr )
          strcpy(v13, v7);
        else
          v13 = nullptr;
        v12->pSrcName = v13;
        v14 = (char *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: strlen(buf) + 1);
        if ( v14 != nullptr )
          strcpy(v14, buf);
        else
          v14 = nullptr;
        v3 = v17;
        v1 = fp;
        v12->pTargetName = v14;
      }
    }
    while ( CmdLib_FGets(pOut: buf, outSize: 1024, hFile: v1) != nullptr );
  }
  g_pFileSystem->Close(this: g_pFileSystem, a2: v1);
}

//------------------------------------------------------------------------------
// Address: 0x10001FF0
// Name: void Worker_GetFileFromMaster(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Worker_GetFileFromMaster(const char *pFileName)
{
  char *m_pMemory; // ebx
  void *v2; // edi
  int v3; // esi
  int m_Size; // eax
  _iobuf *v5; // edi
  char filename[1024]; // [esp+Ch] [ebp-818h] BYREF
  char path[1024]; // [esp+40Ch] [ebp-418h] BYREF
  CUtlVector<char,CUtlMemory<char,int> > fileBuf; // [esp+80Ch] [ebp-18h] BYREF
  bool bZeroLength; // [esp+823h] [ebp-1h]

  DebugOut(pMsg: "Worker_GetFileFromMaster: \"%s\"\n", pFileName);
  m_pMemory = nullptr;
  v2 = g_pFileSystem->Open(this: g_pFileSystem, a2: pFileName, a3: "rb", a4: 0);
  bZeroLength = false;
  if ( v2 == nullptr )
  {
    bZeroLength = true;
    _Warning(a1: "zero length file: \"%s\"\n", pFileName);
  }
  v3 = 0;
  memset(&fileBuf, 0, sizeof(fileBuf));
  if ( !bZeroLength )
  {
    v3 = g_pFileSystem->Size_2(this: g_pFileSystem, a2: v2);
    m_Size = 0;
    fileBuf.m_Size = 0;
    if ( v3 != 0 )
    {
      if ( v3 > 0 )
      {
        CUtlMemory<bool,int>::Grow(this: (CUtlMemory<unsigned char,int> *)&fileBuf, num: v3);
        m_Size = fileBuf.m_Size;
        m_pMemory = fileBuf.m_Memory.m_pMemory;
      }
      fileBuf.m_Size = v3 + m_Size;
      fileBuf.m_pElements = m_pMemory;
      if ( m_Size > 0 && v3 > 0 )
        _V_memmove(dest: &m_pMemory[v3], src: m_pMemory, count: m_Size);
    }
    g_pFileSystem->Read(this: g_pFileSystem, a2: m_pMemory, a3: v3, a4: v2);
    g_pFileSystem->Close(this: g_pFileSystem, a2: v2);
  }
  sprintf(string: path, format: "%s%s", g_WorkerTempPath, pFileName + 3);
  V_StripFilename(path);
  MakeDirHier(pPath: path);
  sprintf(string: filename, format: "%s%s", g_WorkerTempPath, pFileName + 3);
  v5 = fopen(file: filename, mode: "wb");
  if ( v5 == nullptr )
    _Error(a1: "Couldn't open \"%s\"\n", filename);
  if ( !bZeroLength )
    fwrite(buffer: m_pMemory, size: 1u, count: v3, stream: v5);
  fclose(stream: v5);
  CUtlVector<CMasterMulticastThread::CChunkInfo,CUtlMemory<CMasterMulticastThread::CChunkInfo,int>>::~CUtlVector<CMasterMulticastThread::CChunkInfo,CUtlMemory<CMasterMulticastThread::CChunkInfo,int>>(this: (CUtlVector<CFileResponse,CUtlMemory<CFileResponse,int> > *)&fileBuf);
}

//------------------------------------------------------------------------------
// Address: 0x10002170
// Name: void Shared_ParseListOfCompileCommands(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Shared_ParseListOfCompileCommands()
{
  void *v0; // eax
  void *v1; // esi
  _iobuf *v2; // eax
  char *v3; // edi
  int m_Size; // eax
  int v5; // esi
  char **m_pMemory; // ecx
  int v7; // eax
  char fileListFileName[1024]; // [esp+4h] [ebp-804h] BYREF
  char buf[1024]; // [esp+404h] [ebp-404h] BYREF
  void *fp; // [esp+804h] [ebp-4h]

  sprintf(string: fileListFileName, format: "%s\\texturelist.txt", g_pGameDir);
  v0 = g_pFileSystem->Open(this: g_pFileSystem, a2: fileListFileName, a3: "r", a4: 0);
  v1 = v0;
  fp = v0;
  if ( v0 == nullptr )
  {
    DebugOut(pMsg: "Can't open %s!\n", fileListFileName);
    v2 = __iob_func();
    fprintf(str: v2 + 2, format: "Can't open %s!\n", fileListFileName);
    exit(code: -1);
  }
  if ( CmdLib_FGets(pOut: buf, outSize: 1023, hFile: v0) != nullptr )
  {
    do
    {
      v3 = (char *)operator new(nSize: strlen(buf) + 1);
      strcpy(v3, buf);
      v3[strlen(v3) - 2] = 0;
      m_Size = g_CompileCommands.m_Size;
      v5 = g_CompileCommands.m_Size;
      if ( g_CompileCommands.m_Size + 1 > g_CompileCommands.m_Memory.m_nAllocationCount )
      {
        CUtlMemory<int,int>::Grow(
          this: (CUtlMemory<CTCPPacket *,int> *)&g_CompileCommands,
          num: g_CompileCommands.m_Size - g_CompileCommands.m_Memory.m_nAllocationCount + 1);
        m_Size = g_CompileCommands.m_Size;
      }
      m_pMemory = g_CompileCommands.m_Memory.m_pMemory;
      g_CompileCommands.m_Size = m_Size + 1;
      v7 = m_Size - v5;
      g_CompileCommands.m_pElements = g_CompileCommands.m_Memory.m_pMemory;
      if ( v7 > 0 )
      {
        _V_memmove(
          dest: &g_CompileCommands.m_Memory.m_pMemory[v5 + 1],
          src: &g_CompileCommands.m_Memory.m_pMemory[v5],
          count: 4 * v7);
        m_pMemory = g_CompileCommands.m_Memory.m_pMemory;
      }
      m_pMemory[v5] = v3;
    }
    while ( CmdLib_FGets(pOut: buf, outSize: 1023, hFile: fp) != nullptr );
    v1 = fp;
  }
  g_pFileSystem->Close(this: g_pFileSystem, a2: v1);
  DebugOut(pMsg: "%d compiles\n", g_CompileCommands.m_Size);
}

//------------------------------------------------------------------------------
// Address: 0x10002310
// Name: public: void CUtlVector<bool,class CUtlMemory<bool,int>>::EnsureCount(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<bool,CUtlMemory<bool,int>>::EnsureCount(
        CUtlVector<bool,CUtlMemory<bool,int> > *this,
        int num)
{
  int m_Size; // eax
  int v4; // edi
  int v5; // ebx
  int m_nAllocationCount; // eax
  bool *m_pMemory; // ecx
  int v8; // eax

  m_Size = this->m_Size;
  if ( m_Size < num )
  {
    v4 = num - m_Size;
    v5 = this->m_Size;
    if ( num != m_Size )
    {
      m_nAllocationCount = this->m_Memory.m_nAllocationCount;
      if ( v5 + v4 > m_nAllocationCount )
        CUtlMemory<bool,int>::Grow((CUtlMemory<unsigned char,int> *)this, num: v4 + v5 - m_nAllocationCount);
      this->m_Size += v4;
      m_pMemory = this->m_Memory.m_pMemory;
      v8 = this->m_Size - v5 - v4;
      this->m_pElements = this->m_Memory.m_pMemory;
      if ( v8 > 0 && v4 > 0 )
        _V_memmove(dest: &m_pMemory[v5 + v4], src: &m_pMemory[v5], count: v8);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10002370
// Name: void Worker_GetSourceFiles(int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Worker_GetSourceFiles(int iWorkUnit)
{
  int v2; // eax
  int v3; // ebx
  int m_Size; // eax
  const char *v5; // edi
  int v6; // esi
  int iWorkUnita; // [esp+10h] [ebp+8h]

  DebugOut(pMsg: "Worker_GetSourceFiles( %d )\n", iWorkUnit);
  v2 = iWorkUnit * g_nTexturesPerWorkUnit;
  iWorkUnita = g_CompileCommands.m_Size;
  if ( g_CompileCommands.m_Size >= iWorkUnit * g_nTexturesPerWorkUnit + g_nTexturesPerWorkUnit )
    iWorkUnita = iWorkUnit * g_nTexturesPerWorkUnit + g_nTexturesPerWorkUnit;
  v3 = iWorkUnit * g_nTexturesPerWorkUnit;
  if ( v2 < iWorkUnita )
  {
    m_Size = g_SourceTargetPairs.m_Size;
    do
    {
      v5 = g_CompileCommands.m_Memory.m_pMemory[v3];
      v6 = 0;
      if ( m_Size > 0 )
      {
        do
        {
          if ( _V_stricmp(s1: v5, s2: g_SourceTargetPairs.m_Memory.m_pMemory[v6].pTargetName) == 0 )
            Worker_GetFileFromMaster(pFileName: g_SourceTargetPairs.m_Memory.m_pMemory[v6].pSrcName);
          m_Size = g_SourceTargetPairs.m_Size;
          ++v6;
        }
        while ( v6 < g_SourceTargetPairs.m_Size );
      }
      ++v3;
    }
    while ( v3 < iWorkUnita );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10002400
// Name: bool ErrMsgDispatch(class MessageBuffer __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
char __cdecl ErrMsgDispatch(MessageBuffer *pBuf)
{
  MessageBuffer *v1; // edi
  int v2; // esi
  _iobuf *v3; // eax
  const char *v5; // [esp-Ch] [ebp-Ch]

  if ( (_S1_0 & 1) == 0 )
  {
    _S1_0 |= 1u;
    errorMessages.m_Vector.m_Memory.m_pMemory = nullptr;
    errorMessages.m_Vector.m_Memory.m_nAllocationCount = 0;
    errorMessages.m_Vector.m_Memory.m_nGrowSize = 32;
    errorMessages.m_Vector.m_Size = 0;
    errorMessages.m_Vector.m_pElements = nullptr;
    CUtlSymbolTable::CUtlSymbolTable(
      this: &errorMessages.m_SymbolTable,
      growSize: 0,
      initSize: 32,
      caseInsensitive: true);
    atexit(func: ErrMsgDispatch_::_2_::_dynamic_atexit_destructor_for__errorMessages__);
  }
  v1 = pBuf;
  if ( CUtlSymbolTable::Find(
         this: &errorMessages.m_SymbolTable,
         result: (CUtlSymbol *)&pBuf + 1,
         pString: (const char *)pBuf->data + 1)->m_Id == 0xFFFF )
  {
    CUtlSymbolTable::AddString(
      this: &errorMessages.m_SymbolTable,
      result: (CUtlSymbol *)&pBuf,
      pString: (const char *)v1->data + 1);
    v2 = (unsigned __int16)pBuf;
    if ( errorMessages.m_Vector.m_Size <= (unsigned __int16)pBuf )
      CUtlVector<bool,CUtlMemory<bool,int>>::EnsureCount(this: &errorMessages.m_Vector, num: (unsigned __int16)pBuf + 1);
    errorMessages.m_Vector.m_Memory.m_pMemory[v2] = true;
    v5 = v1->data + 1;
    v3 = __iob_func();
    fprintf(str: v3 + 2, format: "ERROR: %s\n", v5);
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100024D0
// Name: bool TextureHadErrorDispatch(class MessageBuffer __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
char __cdecl TextureHadErrorDispatch(MessageBuffer *pBuf)
{
  int v1; // esi

  CUtlSymbolTable::AddString(
    this: &g_Master_TextureHadError.m_SymbolTable,
    result: (CUtlSymbol *)&pBuf,
    pString: (const char *)pBuf->data + 1);
  v1 = (unsigned __int16)pBuf;
  if ( g_Master_TextureHadError.m_Vector.m_Size > (unsigned __int16)pBuf )
  {
    g_Master_TextureHadError.m_Vector.m_Memory.m_pMemory[(unsigned __int16)pBuf] = true;
  }
  else
  {
    CUtlVector<bool,CUtlMemory<bool,int>>::EnsureCount(
      this: &g_Master_TextureHadError.m_Vector,
      num: (unsigned __int16)pBuf + 1);
    g_Master_TextureHadError.m_Vector.m_Memory.m_pMemory[v1] = true;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10002530
// Name: void Worker_ProcessWorkUnitFn(int,unsigned __int64,class MessageBuffer __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Worker_ProcessWorkUnitFn(int iThread, unsigned __int64 iWorkUnit, MessageBuffer *pBuf)
{
  int v3; // edi
  _iobuf *v4; // eax
  _iobuf *v5; // esi
  int v6; // ebx
  MessageBuffer *v7; // esi
  char tganame[1024]; // [esp+8h] [ebp-C38h] BYREF
  char cmdline[1024]; // [esp+408h] [ebp-838h] BYREF
  char localVTFName[1024]; // [esp+808h] [ebp-438h] BYREF
  CUtlBuffer buf; // [esp+C08h] [ebp-38h] BYREF
  int p; // [esp+C38h] [ebp-8h] BYREF
  int m_Size; // [esp+C3Ch] [ebp-4h]

  DebugOut(pMsg: "Worker_ProcessWorkUnitFn textures/workunit=%d\n", g_nTexturesPerWorkUnit);
  Worker_GetSourceFiles(iWorkUnit);
  v3 = iWorkUnit * g_nTexturesPerWorkUnit;
  m_Size = g_CompileCommands.m_Size;
  if ( g_CompileCommands.m_Size >= (int)iWorkUnit * g_nTexturesPerWorkUnit + g_nTexturesPerWorkUnit )
    m_Size = iWorkUnit * g_nTexturesPerWorkUnit + g_nTexturesPerWorkUnit;
  for ( ; v3 < m_Size; ++v3 )
  {
    DebugOut(pMsg: "texture to compile: \"%s\"\n", g_CompileCommands.m_Memory.m_pMemory[v3]);
    VTFNameToTGAName(pSrcName: g_CompileCommands.m_Memory.m_pMemory[v3], pDstName: tganame);
    sprintf(
      string: cmdline,
      format: "vtex -allowdebug -vproject \"%s%s\" -mkdir -nopause \"%s%s\"",
      g_WorkerTempPath,
      g_pGameDir + 3,
      g_WorkerTempPath,
      &tganame[3]);
    DebugOut(pMsg: cmdline);
    DebugOut(pMsg: "\n");
    system(command: cmdline);
    sprintf(
      string: localVTFName,
      format: "%s%s",
      g_WorkerTempPath,
      (const char *)g_CompileCommands.m_Memory.m_pMemory[v3] + 3);
    DebugOut(pMsg: "local: \"%s\"\n", localVTFName);
    v4 = fopen(file: localVTFName, mode: "rb");
    v5 = v4;
    if ( v4 != nullptr )
    {
      fseek(stream: v4, offset: 0, whence: 2);
      HIDWORD(iWorkUnit) = ftell(stream: v5);
      fseek(stream: v5, offset: 0, whence: 0);
      CUtlBuffer::CUtlBuffer(this: &buf, growSize: 0, initSize: 0, nFlags: 0);
      CUtlBuffer::EnsureCapacity(this: &buf, num: SHIDWORD(iWorkUnit));
      v6 = fread(buffer: buf.m_Memory.m_pMemory, elementSize: 1u, count: HIDWORD(iWorkUnit), stream: v5);
      fclose(stream: v5);
      CUtlBuffer::SeekPut(this: &buf, type: SEEK_HEAD, offset: v6);
      v7 = pBuf;
      MessageBuffer::write(this: pBuf, p: (char *)&iWorkUnit + 4, bytes: 4);
      MessageBuffer::write(this: v7, p: buf.m_Memory.m_pMemory, bytes: SHIDWORD(iWorkUnit));
      if ( buf.m_Memory.m_nGrowSize >= 0 && buf.m_Memory.m_pMemory != nullptr )
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: buf.m_Memory.m_pMemory);
    }
    else
    {
      p = 0;
      MessageBuffer::write(this: pBuf, &p, bytes: 4);
    }
    VMPI_HandleSocketErrors(timeout: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10002720
// Name: int TextureCompile_Main(int,char __near * __near * const)
// Source: json
//------------------------------------------------------------------------------
int __cdecl TextureCompile_Main(int argc, char **argv)
{
  int m_Size; // edi
  _iobuf *v3; // eax
  _iobuf *v4; // eax
  char dest[260]; // [esp+Ch] [ebp-21Ch] BYREF
  char path[260]; // [esp+110h] [ebp-118h] BYREF
  MessageBuffer buf; // [esp+214h] [ebp-14h] BYREF
  char packetID; // [esp+227h] [ebp-1h] BYREF

  InstallSpewFunction();
  g_bSuppressPrintfOutput = false;
  g_flStartTime = _Plat_FloatTime();
  numthreads = 1;
  SetupPaths(argc, argv);
  DebugOut(pMsg: "Before VMPI_Init\n");
  g_bSuppressPrintfOutput = true;
  if ( !VMPI_Init(
          &argc,
          &argv,
          pDependencyFilename: "dependency_info_texturecompile.txt",
          handler: (void (__cdecl *)(int, const char *))MyDisconnectHandler,
          runMode: VMPI_RUN_NETWORKED,
          bConnectingAsService: false) )
  {
    g_bSuppressPrintfOutput = false;
    DebugOut(pMsg: "MPI_Init failed.\n");
    _Error(a1: "MPI_Init failed.");
  }
  g_bSuppressPrintfOutput = false;
  DebugOut(pMsg: "After VMPI_Init\n");
  CmdLib_InitFileSystem(pFilename: ".", maxMemoryUsage: 50000000);
  DebugOut(pMsg: "After VMPI_FileSystem_Init\n");
  Shared_ParseListOfCompileCommands();
  DebugOut(pMsg: "After Shared_ParseListOfCompileCommands\n");
  m_Size = g_CompileCommands.m_Size;
  g_nTexturesPerWorkUnit = 1;
  DebugOut(pMsg: "Before conditional\n");
  if ( g_bMPIMaster )
  {
    DebugOut(pMsg: "Before STARTWORK_PACKETID\n");
    packetID = 5;
    VMPI_SendData(pData: &packetID, nBytes: 1, iDest: -3, fVMPISendFlags: 0);
    DebugOut(pMsg: "Before DistributeWork\n");
    DistributeWork(
      nWorkUnits: m_Size + 1,
      processFn: nullptr,
      receiveFn: (void (__cdecl *)(unsigned __int64, MessageBuffer *, int))Master_ReceiveWorkUnitFn);
  }
  else
  {
    MessageBuffer::MessageBuffer(this: &buf);
    DebugOut(pMsg: "Before VMPI_DispatchUntil\n");
    while ( !g_bGotStartWorkPacket )
      VMPI_DispatchNextMessage(timeout: 0xFFFFFFFF);
    DebugOut(pMsg: "after VMPI_DispatchUntil\n");
    Worker_ReadFilesToCopy();
    DebugOut(pMsg: "Before _chdir\n");
    _chdir(path: g_WorkerTempPath);
    sprintf(string: path, format: "%s%s\\bin\\server.dll", g_WorkerTempPath, g_pGameDir + 3);
    _Warning(a1: "TouchFile: %s\n", path);
    _V_strcpy(dest, src: path);
    V_StripFilename(path: dest);
    MakeDirHier(pPath: dest);
    v3 = fopen(file: path, mode: "wb");
    fclose(stream: v3);
    sprintf(string: path, format: "%s%s\\bin\\client.dll", g_WorkerTempPath, g_pGameDir + 3);
    _Warning(a1: "TouchFile: %s\n", path);
    _V_strcpy(dest, src: path);
    V_StripFilename(path: dest);
    MakeDirHier(pPath: dest);
    v4 = fopen(file: path, mode: "wb");
    fclose(stream: v4);
    Worker_GetLocalCopyOfBinary(pFilename: "vtex.exe");
    Worker_GetLocalCopyOfBinary(pFilename: "vtex_dll.dll");
    Worker_GetLocalCopyOfBinary(pFilename: "vstdlib.dll");
    Worker_GetLocalCopyOfBinary(pFilename: "tier0.dll");
    DebugOut(pMsg: "Before DistributeWork\n");
    DistributeWork(nWorkUnits: m_Size + 1, processFn: Worker_ProcessWorkUnitFn, receiveFn: nullptr);
    MessageBuffer::~MessageBuffer(this: &buf);
  }
  DebugOut(pMsg: "Before VMPI_Finalize\n");
  g_bSuppressPrintfOutput = true;
  VMPI_FileSystem_Term();
  VMPI_Finalize();
  g_bSuppressPrintfOutput = false;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10002A00
// Name: private: virtual int CTextureCompileDLL::main(int,char __near * __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CTextureCompileDLL::main(CTextureCompileDLL *this, int argc, char **argv)
{
  return TextureCompile_Main(argc, argv);
}

//------------------------------------------------------------------------------
// Address: 0x100070B0
// Name: public: void CUtlMemory<struct UtlLinkedListElem_t<class CUtlVector<char,class CUtlMemory<char,int>> __near *,unsigned short>,unsigned short>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<UtlLinkedListElem_t<CUtlVector<char,CUtlMemory<char,int>> *,unsigned short>,unsigned short>::Grow(
        CUtlMemory<UtlLinkedListElem_t<CUtlVector<char,CUtlMemory<char,int> > *,unsigned short>,unsigned short> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  UtlLinkedListElem_t<CUtlVector<char,CUtlMemory<char,int> > *,unsigned short> *m_pMemory; // edx
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
        m_nAllocationCount = 4;
      for ( ; m_nAllocationCount < v5; m_nAllocationCount *= 2 )
        ;
    }
    if ( (unsigned __int16)m_nAllocationCount < v5 )
    {
      if ( (_WORD)m_nAllocationCount != 0 || v5 > 0xFFFF )
      {
        if ( (unsigned __int16)v5 != v5 )
          return;
        do
          m_nAllocationCount = (v5 + m_nAllocationCount) / 2;
        while ( (unsigned __int16)m_nAllocationCount < v5 );
      }
      else
      {
        --m_nAllocationCount;
      }
    }
    m_pMemory = this->m_pMemory;
    this->m_nAllocationCount = m_nAllocationCount;
    v7 = 8 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (UtlLinkedListElem_t<CUtlVector<char,CUtlMemory<char,int> > *,unsigned short> *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (UtlLinkedListElem_t<CUtlVector<char,CUtlMemory<char,int> > *,unsigned short> *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10007E40
// Name: public: int CUtlVector<char,class CUtlMemory<char,int>>::InsertMultipleBefore(int,int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<char,CUtlMemory<char,int>>::InsertMultipleBefore(
        CUtlVector<char,CUtlMemory<char,int> > *this,
        int elem,
        int num,
        const char *pToInsert)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  char *m_pMemory; // ecx
  int v9; // eax
  int i; // ecx
  char *v11; // eax

  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<bool,int>::Grow((CUtlMemory<unsigned char,int> *)this, num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v9 = this->m_Size - elem - num;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v9 > 0 && num > 0 )
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: v9);
  if ( pToInsert != nullptr )
  {
    for ( i = 0; i < num; ++i )
    {
      v11 = &this->m_Memory.m_pMemory[i + elem];
      if ( v11 != nullptr )
        *v11 = pToInsert[i];
    }
  }
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x10007F60
// Name: public: int CUtlVector<char __near *,class CUtlMemory<char __near *,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<char *,CUtlMemory<char *,int>>::InsertMultipleBefore(
        CUtlVector<int,CUtlMemory<int,int> > *this,
        int elem,
        int num)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  int *m_pMemory; // ecx
  int v8; // eax
  int v9; // eax

  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<int,int>::Grow((CUtlMemory<CTCPPacket *,int> *)this, num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v8 = this->m_Size;
  this->m_pElements = this->m_Memory.m_pMemory;
  v9 = v8 - elem - num;
  if ( v9 > 0 && num > 0 )
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: 4 * v9);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x10008D70
// Name: public: void CUtlVector<char,class CUtlMemory<char,int>>::CopyArray(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<char,CUtlMemory<char,int>>::CopyArray(
        CUtlVector<char,CUtlMemory<char,int> > *this,
        const char *pArray,
        int size)
{
  int m_nAllocationCount; // eax
  char *m_pMemory; // ecx
  int v6; // eax
  int i; // eax

  this->m_Size = 0;
  if ( size != 0 )
  {
    m_nAllocationCount = this->m_Memory.m_nAllocationCount;
    if ( size > m_nAllocationCount )
      CUtlMemory<bool,int>::Grow((CUtlMemory<unsigned char,int> *)this, num: size - m_nAllocationCount);
    this->m_Size += size;
    m_pMemory = this->m_Memory.m_pMemory;
    v6 = this->m_Size - size;
    this->m_pElements = this->m_Memory.m_pMemory;
    if ( v6 > 0 && size > 0 )
      _V_memmove(dest: &m_pMemory[size], src: m_pMemory, count: v6);
  }
  for ( i = 0; i < size; ++i )
    this->m_Memory.m_pMemory[i] = pArray[i];
}

//------------------------------------------------------------------------------
// Address: 0x1000D2E0
// Name: public: int CUtlVector<unsigned __int64,class CUtlMemory<unsigned __int64,int>>::InsertBefore(int,unsigned __int64 const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<unsigned __int64,CUtlMemory<unsigned __int64,int>>::InsertBefore(
        CUtlVector<unsigned __int64,CUtlMemory<unsigned __int64,int> > *this,
        int elem,
        unsigned __int64 *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  unsigned __int64 *m_pMemory; // ecx
  int v7; // eax
  unsigned __int64 *v8; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CTransmitRateMgr::CMachineRecord,int>::Grow(
      (CUtlMemory<CTransmitRateMgr::CMachineRecord,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 8 * v7);
  v8 = &this->m_Memory.m_pMemory[elem];
  if ( v8 != nullptr )
    *v8 = *src;
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x1000D350
// Name: public: int CUtlVector<unsigned __int64,class CUtlMemory<unsigned __int64,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<unsigned __int64,CUtlMemory<unsigned __int64,int>>::InsertMultipleBefore(
        CUtlVector<unsigned __int64,CUtlMemory<unsigned __int64,int> > *this,
        int elem,
        int num)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  unsigned __int64 *m_pMemory; // ecx
  int v8; // eax
  int v9; // eax

  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<CTransmitRateMgr::CMachineRecord,int>::Grow(
      (CUtlMemory<CTransmitRateMgr::CMachineRecord,int> *)this,
      num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v8 = this->m_Size;
  this->m_pElements = this->m_Memory.m_pMemory;
  v9 = v8 - elem - num;
  if ( v9 > 0 && num > 0 )
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: 8 * v9);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x1000FF70
// Name: public: void CUtlMemory<class CIPAddr,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<CIPAddr,int>::Grow(CUtlMemory<CMasterMulticastThread::CChunkInfo,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  CMasterMulticastThread::CChunkInfo *m_pMemory; // edx
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
      this->m_pMemory = (CMasterMulticastThread::CChunkInfo *)_g_pMemAlloc->Realloc_2(
                                                                this: _g_pMemAlloc,
                                                                a2: m_pMemory,
                                                                a3: v7);
    else
      this->m_pMemory = (CMasterMulticastThread::CChunkInfo *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100109E0
// Name: public: CUtlVector<class CMasterMulticastThread::CChunkInfo,class CUtlMemory<class CMasterMulticastThread::CChunkInfo,int>>::~CUtlVector<class CMasterMulticastThread::CChunkInfo,class CUtlMemory<class CMasterMulticastThread::CChunkInfo,int>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CMasterMulticastThread::CChunkInfo,CUtlMemory<CMasterMulticastThread::CChunkInfo,int>>::~CUtlVector<CMasterMulticastThread::CChunkInfo,CUtlMemory<CMasterMulticastThread::CChunkInfo,int>>(
        CUtlVector<CFileResponse,CUtlMemory<CFileResponse,int> > *this)
{
  bool v2; // sf
  CFileResponse *m_pMemory; // eax

  v2 = this->m_Memory.m_nGrowSize < 0;
  this->m_Size = 0;
  if ( !v2 )
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
  v2 = this->m_Memory.m_nGrowSize < 0;
  m_pMemory = this->m_Memory.m_pMemory;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( !v2 )
  {
    if ( m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10010A50
// Name: public: int CUtlVector<class CMasterMulticastThread::CChunkInfo,class CUtlMemory<class CMasterMulticastThread::CChunkInfo,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CMasterMulticastThread::CChunkInfo,CUtlMemory<CMasterMulticastThread::CChunkInfo,int>>::InsertMultipleBefore(
        CUtlVector<CMasterMulticastThread::CChunkInfo,CUtlMemory<CMasterMulticastThread::CChunkInfo,int> > *this,
        int elem,
        int num)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CMasterMulticastThread::CChunkInfo *m_pMemory; // ecx
  int v8; // eax
  int v9; // eax

  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<CIPAddr,int>::Grow(this: &this->m_Memory, num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v8 = this->m_Size;
  this->m_pElements = this->m_Memory.m_pMemory;
  v9 = v8 - elem - num;
  if ( v9 > 0 && num > 0 )
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: 6 * v9);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x10010DA0
// Name: public: int CUtlVector<class CTransmitRateMgr::CMachineRecord,class CUtlMemory<class CTransmitRateMgr::CMachineRecord,int>>::AddToTail(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CTransmitRateMgr::CMachineRecord,CUtlMemory<CTransmitRateMgr::CMachineRecord,int>>::AddToTail(
        CUtlVector<CTransmitRateMgr::CMachineRecord,CUtlMemory<CTransmitRateMgr::CMachineRecord,int> > *this)
{
  int m_nAllocationCount; // eax
  int m_Size; // edi
  CTransmitRateMgr::CMachineRecord *m_pMemory; // ecx
  int v5; // eax

  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  m_Size = this->m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CTransmitRateMgr::CMachineRecord,int>::Grow(this: &this->m_Memory, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v5 = this->m_Size - m_Size - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v5 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 8 * v5);
  return m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x10010F70
// Name: public: void CUtlVector<unsigned char,class CUtlMemory<unsigned char,int>>::SetSize(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<unsigned char,CUtlMemory<unsigned char,int>>::SetSize(
        CUtlVector<unsigned char,CUtlMemory<unsigned char,int> > *this,
        int size)
{
  int m_nAllocationCount; // eax
  unsigned __int8 *m_pMemory; // ecx
  int v5; // eax

  this->m_Size = 0;
  if ( size != 0 )
  {
    m_nAllocationCount = this->m_Memory.m_nAllocationCount;
    if ( size > m_nAllocationCount )
      CUtlMemory<bool,int>::Grow(this: &this->m_Memory, num: size - m_nAllocationCount);
    this->m_Size += size;
    m_pMemory = this->m_Memory.m_pMemory;
    v5 = this->m_Size - size;
    this->m_pElements = this->m_Memory.m_pMemory;
    if ( v5 > 0 && size > 0 )
      _V_memmove(dest: &m_pMemory[size], src: m_pMemory, count: v5);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10015120
// Name: public: int CUtlVector<class CFileResponse,class CUtlMemory<class CFileResponse,int>>::InsertBefore(int,class CFileResponse const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CFileResponse,CUtlMemory<CFileResponse,int>>::InsertBefore(
        CUtlVector<CFileResponse,CUtlMemory<CFileResponse,int> > *this,
        int elem,
        const CFileResponse *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CFileResponse *m_pMemory; // ecx
  int v7; // eax
  CFileResponse *v8; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<UtlLinkedListElem_t<CMasterMulticastThread::CMulticastFile *,int>,int>::Grow(
      (CUtlMemory<UtlLinkedListElem_t<CWorkerFile *,int>,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 12 * v7);
  v8 = &this->m_Memory.m_pMemory[elem];
  if ( v8 != nullptr )
    *v8 = *src;
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x10016170
// Name: public: void CUtlMemory<class CWUStatus,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<CWUStatus,int>::Grow(
        CUtlMemory<UtlLinkedListElem_t<unsigned __int64,unsigned __int64>,unsigned __int64> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  UtlLinkedListElem_t<unsigned __int64,unsigned __int64> *m_pMemory; // edx
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
        m_nAllocationCount = 2;
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
    v7 = 24 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (UtlLinkedListElem_t<unsigned __int64,unsigned __int64> *)_g_pMemAlloc->Realloc_2(
                                                                                    this: _g_pMemAlloc,
                                                                                    a2: m_pMemory,
                                                                                    a3: v7);
    else
      this->m_pMemory = (UtlLinkedListElem_t<unsigned __int64,unsigned __int64> *)_g_pMemAlloc->Alloc_2(
                                                                                    this: _g_pMemAlloc,
                                                                                    a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10016720
// Name: public: int CUtlVector<class CWUStatus,class CUtlMemory<class CWUStatus,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CWUStatus,CUtlMemory<CWUStatus,int>>::InsertMultipleBefore(
        CUtlVector<CWUStatus,CUtlMemory<CWUStatus,int> > *this,
        int elem,
        int num)
{
  int v3; // edi
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CWUStatus *m_pMemory; // ecx
  int v9; // eax
  int v10; // ecx
  CWUStatus *v11; // eax

  v3 = num;
  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<CWUStatus,int>::Grow(
      (CUtlMemory<UtlLinkedListElem_t<unsigned __int64,unsigned __int64>,unsigned __int64> *)this,
      num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v9 = this->m_Size - elem - num;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v9 > 0 && num > 0 )
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: 24 * v9);
  if ( num > 0 )
  {
    v10 = elem;
    do
    {
      v11 = &this->m_Memory.m_pMemory[v10];
      if ( v11 != nullptr )
      {
        v11->m_iState = 0;
        *(_QWORD *)&v11->m_Rect.left = 0;
        *(_QWORD *)&v11->m_Rect.right = 0;
      }
      ++v10;
      --v3;
    }
    while ( v3 != 0 );
  }
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x100167D0
// Name: public: int CUtlVector<class CWorkUnitEvent,class CUtlMemory<class CWorkUnitEvent,int>>::InsertBefore(int,class CWorkUnitEvent const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CWorkUnitEvent,CUtlMemory<CWorkUnitEvent,int>>::InsertBefore(
        CUtlVector<CWorkUnitEvent,CUtlMemory<CWorkUnitEvent,int> > *this,
        int elem,
        const CWorkUnitEvent *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CWorkUnitEvent *m_pMemory; // ecx
  int v7; // eax
  CWorkUnitEvent *v8; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<UtlLinkedListElem_t<CWorkUnitInfo,int>,int>::Grow(
      (CUtlMemory<CWorkUnitWalker::CWorkerInfo,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 16 * v7);
  v8 = &this->m_Memory.m_pMemory[elem];
  if ( v8 != nullptr )
    *v8 = *src;
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x100169A0
// Name: public: int CUtlVector<class CWorkUnit,class CUtlMemory<class CWorkUnit,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CWorkUnit,CUtlMemory<CWorkUnit,int>>::InsertMultipleBefore(
        CUtlVector<CWorkUnit,CUtlMemory<CWorkUnit,int> > *this,
        int elem,
        int num)
{
  int v3; // edi
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CWorkUnit *m_pMemory; // ecx
  int v9; // eax
  int v10; // ecx
  CWorkUnit *v11; // eax

  v3 = num;
  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<CWUStatus,int>::Grow(
      (CUtlMemory<UtlLinkedListElem_t<unsigned __int64,unsigned __int64>,unsigned __int64> *)this,
      num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v9 = this->m_Size - elem - num;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v9 <= 0 )
    goto LABEL_8;
  if ( num > 0 )
  {
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: 24 * v9);
LABEL_8:
    if ( num > 0 )
    {
      v10 = elem;
      do
      {
        v11 = &this->m_Memory.m_pMemory[v10];
        if ( v11 != nullptr )
        {
          v11->m_Events.m_Memory.m_pMemory = nullptr;
          v11->m_Events.m_Memory.m_nAllocationCount = 0;
          v11->m_Events.m_Memory.m_nGrowSize = 0;
          v11->m_Events.m_Size = 0;
          v11->m_Events.m_pElements = nullptr;
          v11->m_iWorkerCompleted = -1;
        }
        ++v10;
        --v3;
      }
      while ( v3 != 0 );
    }
  }
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x10016EB0
// Name: public: void CUtlVector<class CWorkUnit,class CUtlMemory<class CWorkUnit,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CWorkUnit,CUtlMemory<CWorkUnit,int>>::RemoveAll(
        CUtlVector<CWorkUnit,CUtlMemory<CWorkUnit,int> > *this)
{
  int v1; // ebx
  int v2; // eax
  char *v3; // esi
  void *v4; // eax
  int v5; // [esp+4h] [ebp-8h]
  CUtlVector<CWorkUnit,CUtlMemory<CWorkUnit,int> > *v6; // [esp+8h] [ebp-4h]

  v1 = this->m_Size - 1;
  v6 = this;
  if ( v1 < 0 )
  {
    this->m_Size = 0;
  }
  else
  {
    v2 = 24 * v1;
    v5 = 24 * v1;
    do
    {
      v3 = (char *)this->m_Memory.m_pMemory + v2;
      *((_DWORD *)v3 + 4) = 0;
      if ( *((int *)v3 + 3) >= 0 )
      {
        if ( *((_DWORD *)v3 + 1) != 0 )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: *((void **)v3 + 1));
          this = v6;
          *((_DWORD *)v3 + 1) = 0;
        }
        *((_DWORD *)v3 + 2) = 0;
      }
      v4 = *((void **)v3 + 1);
      *((_DWORD *)v3 + 5) = v4;
      if ( *((int *)v3 + 3) >= 0 )
      {
        if ( v4 != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v4);
          this = v6;
          *((_DWORD *)v3 + 1) = 0;
        }
        *((_DWORD *)v3 + 2) = 0;
      }
      --v1;
      v2 = v5 - 24;
      v5 -= 24;
    }
    while ( v1 >= 0 );
    this->m_Size = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10016FC0
// Name: public: CUtlVector<class CWorkUnit,class CUtlMemory<class CWorkUnit,int>>::~CUtlVector<class CWorkUnit,class CUtlMemory<class CWorkUnit,int>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CWorkUnit,CUtlMemory<CWorkUnit,int>>::~CUtlVector<CWorkUnit,CUtlMemory<CWorkUnit,int>>(
        CUtlVector<CWorkUnit,CUtlMemory<CWorkUnit,int> > *this)
{
  bool v2; // sf
  CWorkUnit *m_pMemory; // eax

  CUtlVector<CWorkUnit,CUtlMemory<CWorkUnit,int>>::RemoveAll(this);
  if ( this->m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
  v2 = this->m_Memory.m_nGrowSize < 0;
  m_pMemory = this->m_Memory.m_pMemory;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( !v2 )
  {
    if ( m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10017900
// Name: public: int CUtlVector<class CWULookupInfo,class CUtlMemory<class CWULookupInfo,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CWULookupInfo,CUtlMemory<CWULookupInfo,int>>::InsertMultipleBefore(
        CUtlVector<CWULookupInfo,CUtlMemory<CWULookupInfo,int> > *this,
        int elem,
        int num)
{
  int v3; // edi
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CWULookupInfo *m_pMemory; // ecx
  int v9; // eax
  int v10; // ecx
  CWULookupInfo *v11; // eax

  v3 = num;
  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<UtlLinkedListElem_t<CMasterMulticastThread::CMulticastFile *,int>,int>::Grow(
      (CUtlMemory<UtlLinkedListElem_t<CWorkerFile *,int>,int> *)this,
      num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v9 = this->m_Size - elem - num;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v9 <= 0 )
    goto LABEL_8;
  if ( num > 0 )
  {
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: 12 * v9);
LABEL_8:
    if ( num > 0 )
    {
      v10 = elem;
      do
      {
        v11 = &this->m_Memory.m_pMemory[v10];
        if ( v11 != nullptr )
        {
          v11->m_iWUInfo = -1;
          v11->m_iPartition = -222222;
          v11->m_iPartitionListIndex = -1;
        }
        ++v10;
        --v3;
      }
      while ( v3 != 0 );
    }
  }
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x10019C50
// Name: public: class CUtlMemory<struct UtlLinkedListElem_t<unsigned __int64,unsigned __int64>,unsigned __int64>::Iterator_t CUtlMemory<struct UtlLinkedListElem_t<unsigned __int64,unsigned __int64>,unsigned __int64>::Next(class CUtlMemory<struct UtlLinkedListElem_t<unsigned __int64,unsigned __int64>,unsigned __int64>::Iterator_t const __near &)const
// Source: json
//------------------------------------------------------------------------------
CUtlMemory<UtlLinkedListElem_t<unsigned __int64,unsigned __int64>,unsigned __int64>::Iterator_t *__thiscall CUtlMemory<UtlLinkedListElem_t<unsigned __int64,unsigned __int64>,unsigned __int64>::Next(
        CUtlMemory<UtlLinkedListElem_t<unsigned __int64,unsigned __int64>,unsigned __int64> *this,
        CUtlMemory<UtlLinkedListElem_t<unsigned __int64,unsigned __int64>,unsigned __int64>::Iterator_t *result,
        const CUtlMemory<UtlLinkedListElem_t<unsigned __int64,unsigned __int64>,unsigned __int64>::Iterator_t *it)
{
  if ( LODWORD(it->index) + 1 < 0 || LODWORD(it->index) + 1 >= this->m_nAllocationCount )
  {
    result->index = -1;
    return result;
  }
  else
  {
    result->index = it->index + 1;
    return result;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10019F10
// Name: public: void CUtlMemory<struct UtlLinkedListElem_t<class CWorkUnitInfo,int>,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<UtlLinkedListElem_t<CWorkUnitInfo,int>,int>::Grow(
        CUtlMemory<CWorkUnitWalker::CWorkerInfo,int> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  CWorkUnitWalker::CWorkerInfo *m_pMemory; // edx
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
        m_nAllocationCount = 2;
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
    v7 = 16 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (CWorkUnitWalker::CWorkerInfo *)_g_pMemAlloc->Realloc_2(
                                                          this: _g_pMemAlloc,
                                                          a2: m_pMemory,
                                                          a3: v7);
    else
      this->m_pMemory = (CWorkUnitWalker::CWorkerInfo *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001A490
// Name: public: int CUtlVector<class CWorkUnitWalker::CWorkerInfo,class CUtlMemory<class CWorkUnitWalker::CWorkerInfo,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CWorkUnitWalker::CWorkerInfo,CUtlMemory<CWorkUnitWalker::CWorkerInfo,int>>::InsertMultipleBefore(
        CUtlVector<CWorkUnitWalker::CWorkerInfo,CUtlMemory<CWorkUnitWalker::CWorkerInfo,int> > *this,
        int elem,
        int num)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CWorkUnitWalker::CWorkerInfo *m_pMemory; // ecx
  int v8; // eax
  int v9; // eax

  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<UtlLinkedListElem_t<CWorkUnitInfo,int>,int>::Grow(
      this: &this->m_Memory,
      num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v8 = this->m_Size;
  this->m_pElements = this->m_Memory.m_pMemory;
  v9 = v8 - elem - num;
  if ( v9 > 0 && num > 0 )
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: 16 * v9);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x1001ACF0
// Name: public: int CUtlVector<unsigned __int64,class CUtlMemory<unsigned __int64,int>>::InsertMultipleBefore(int,int,unsigned __int64 const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<unsigned __int64,CUtlMemory<unsigned __int64,int>>::InsertMultipleBefore(
        CUtlVector<unsigned __int64,CUtlMemory<unsigned __int64,int> > *this,
        int elem,
        int num,
        const unsigned __int64 *pToInsert)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  unsigned __int64 *m_pMemory; // ecx
  int v9; // ebx
  int v10; // eax
  int v11; // eax
  int v12; // edx
  unsigned __int64 *v13; // ecx

  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<CTransmitRateMgr::CMachineRecord,int>::Grow(
      (CUtlMemory<CTransmitRateMgr::CMachineRecord,int> *)this,
      num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v9 = elem;
  v10 = this->m_Size - elem - num;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v10 > 0 && num > 0 )
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: 8 * v10);
  if ( pToInsert != nullptr )
  {
    v11 = 0;
    if ( num > 0 )
    {
      v12 = elem;
      do
      {
        v13 = &this->m_Memory.m_pMemory[v12];
        if ( v13 != nullptr )
        {
          *(_DWORD *)v13 = pToInsert[v11];
          *((_DWORD *)v13 + 1) = HIDWORD(pToInsert[v11]);
          v9 = elem;
        }
        ++v11;
        ++v12;
      }
      while ( v11 < num );
    }
  }
  return v9;
}

//------------------------------------------------------------------------------
// Address: 0x10001A10
// Name: __CreateCTextureCompileDLLILaunchableDLL_interface
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CTextureCompileDLL *__cdecl _CreateCTextureCompileDLLILaunchableDLL_interface()
{
  return &_g_CTextureCompileDLL_singleton;
}
