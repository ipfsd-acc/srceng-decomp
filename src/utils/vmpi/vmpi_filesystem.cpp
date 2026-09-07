// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/vmpi/vmpi_filesystem.cpp
// Functions: 154
// ============================================================

#include "utils\vmpi\vmpi_filesystem.h"

//------------------------------------------------------------------------------
// Address: 0x100216E0
// Name: void __near * GetVMPIFileSystem(void)
// Source: json
//------------------------------------------------------------------------------
IBaseFileSystem *__cdecl GetVMPIFileSystem()
{
  if ( g_pBaseVMPIFileSystem != nullptr )
    return &g_pBaseVMPIFileSystem->IBaseFileSystem;
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x100216F0
// Name: void __near * GetFullFileSystem(void)
// Source: json
//------------------------------------------------------------------------------
IFileSystem *__cdecl GetFullFileSystem()
{
  return g_pOriginalPassThruFileSystem;
}

//------------------------------------------------------------------------------
// Address: 0x10021700
// Name: class IFileSystem __near * VMPI_FileSystem_Init(int,class IFileSystem __near *)
// Source: json
//------------------------------------------------------------------------------
CBaseVMPIFileSystem *__cdecl VMPI_FileSystem_Init(unsigned int maxMemoryUsage, IFileSystem *pPassThru)
{
  g_pOriginalPassThruFileSystem = pPassThru;
  if ( g_bMPIMaster )
    CreateMasterVMPIFileSystem(maxMemoryUsage, pPassThru);
  else
    CreateWorkerVMPIFileSystem();
  return g_pBaseVMPIFileSystem;
}

//------------------------------------------------------------------------------
// Address: 0x10021740
// Name: class IFileSystem __near * VMPI_FileSystem_Term(void)
// Source: json
//------------------------------------------------------------------------------
IFileSystem *__cdecl VMPI_FileSystem_Term()
{
  IFileSystem *result; // eax

  if ( g_pBaseVMPIFileSystem != nullptr )
  {
    g_pBaseVMPIFileSystem->Release(this: g_pBaseVMPIFileSystem);
    g_pBaseVMPIFileSystem = nullptr;
    if ( g_iVMPIVerboseLevel >= 1 )
    {
      if ( g_bMPIMaster )
        _Msg(a1: "Multicast send: %dk\n", (g_nMulticastBytesSent + 511) / 1024);
      else
        _Msg(a1: "Multicast recv: %dk\n", (g_nMulticastBytesReceived + 511) / 1024);
    }
  }
  result = g_pOriginalPassThruFileSystem;
  g_pOriginalPassThruFileSystem = nullptr;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100217D0
// Name: bool FileSystemRecv(class MessageBuffer __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl FileSystemRecv(MessageBuffer *pBuf, int iSource, int iPacketID)
{
  return g_pBaseVMPIFileSystem != nullptr
      && g_pBaseVMPIFileSystem->HandleFileSystemPacket(
           this: g_pBaseVMPIFileSystem,
           a2: pBuf,
           a3: iSource,
           a4: iPacketID);
}

//------------------------------------------------------------------------------
// Address: 0x10021800
// Name: public: void CVMPIFile_Memory::Init(char const __near *,long,char)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVMPIFile_Memory::Init(CVMPIFile_Memory *this, const char *pData, int len, char chMode)
{
  this->m_pData = pData;
  this->m_DataLen = len;
  this->m_iCurPos = 0;
  this->m_chMode = chMode;
}

//------------------------------------------------------------------------------
// Address: 0x10021830
// Name: public: virtual void CVMPIFile_Memory::Seek(int,enum FileSystemSeek_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVMPIFile_Memory::Seek(CVMPIFile_Memory *this, int pos, FileSystemSeek_t seekType)
{
  if ( seekType != FILESYSTEM_SEEK_HEAD )
  {
    if ( seekType == FILESYSTEM_SEEK_CURRENT )
      this->m_iCurPos += pos;
    else
      this->m_iCurPos = this->m_DataLen - pos;
  }
  else
  {
    this->m_iCurPos = pos;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10021890
// Name: public: virtual int CVMPIFile_Memory::Read(void __near *,int)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CVMPIFile_Memory::Read(CVMPIFile_Memory *this, unsigned __int8 *pOutput, int size)
{
  int m_iCurPos; // ecx
  unsigned int v5; // esi
  signed int v6; // eax
  signed int v8; // edi
  unsigned __int8 *v9; // esi
  int v10; // eax
  unsigned int v11; // edi
  int v12; // eax
  unsigned __int8 *v13; // ecx
  int v14; // eax
  int iRead; // [esp+8h] [ebp-8h]
  int len; // [esp+Ch] [ebp-4h]
  int lena; // [esp+Ch] [ebp-4h]

  m_iCurPos = this->m_iCurPos;
  v5 = size;
  v6 = this->m_DataLen - m_iCurPos;
  if ( v6 < size )
    v5 = this->m_DataLen - m_iCurPos;
  if ( this->m_chMode == 116 )
  {
    v8 = this->m_DataLen - m_iCurPos;
    v9 = (unsigned __int8 *)&this->m_pData[m_iCurPos];
    iRead = 0;
    len = v8;
    memchr(buf: v9, chr: 0xDu, cnt: v6);
    if ( v10 != 0 )
    {
      while ( 1 )
      {
        v11 = size;
        v12 = v10 - (_DWORD)v9;
        if ( size >= v12 )
          v11 = v12;
        memcpy(dst: pOutput, src: v9, count: v11);
        this->m_iCurPos += v11;
        lena = len - v11;
        iRead += v11;
        v9 += v11;
        v13 = &pOutput[v11];
        size -= v11;
        if ( size == 0 )
          break;
        if ( lena == 0 )
        {
          v8 = 0;
          goto LABEL_16;
        }
        v14 = lena;
        if ( lena > 1 && v9[1] == 10 )
        {
          ++v9;
          ++this->m_iCurPos;
          v14 = lena - 1;
        }
        ++iRead;
        --size;
        *v13 = *v9;
        ++this->m_iCurPos;
        ++v9;
        len = v14 - 1;
        pOutput = v13 + 1;
        memchr(buf: v9, chr: 0xDu, cnt: v14 - 1);
        if ( v10 == 0 )
        {
          v8 = len;
          goto LABEL_15;
        }
      }
    }
    else
    {
LABEL_15:
      v13 = pOutput;
LABEL_16:
      if ( size != 0 && v8 != 0 )
      {
        if ( size < v8 )
          v8 = size;
        memcpy(dst: v13, src: v9, count: v8);
        this->m_iCurPos += v8;
        iRead += v8;
      }
    }
    return iRead;
  }
  else
  {
    memcpy(dst: pOutput, src: (unsigned __int8 *)&this->m_pData[m_iCurPos], count: v5);
    this->m_iCurPos += v5;
    return v5;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100219B0
// Name: public: virtual int CVMPIFile_Memory::Write(void const __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CVMPIFile_Memory::Write(CVMPIFile_Memory *this, const void *pInput, const void *size)
{
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x100219C0
// Name: public: virtual CBaseVMPIFileSystem::~CBaseVMPIFileSystem(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseVMPIFileSystem::~CBaseVMPIFileSystem(CBaseVMPIFileSystem *this)
{
  this->CFileSystemPassThru::CInternalFileSystemPassThru<IFileSystem>::IFileSystem::IAppSystem::__vftable = (CBaseVMPIFileSystem_vtbl *)&CBaseVMPIFileSystem::`vftable'{for `IAppSystem'};
  this->CFileSystemPassThru::CInternalFileSystemPassThru<IFileSystem>::IFileSystem::IBaseFileSystem::__vftable = (IBaseFileSystem_vtbl *)&CBaseVMPIFileSystem::`vftable'{for `IBaseFileSystem'};
}

//------------------------------------------------------------------------------
// Address: 0x100219D0
// Name: public: virtual bool CFileSystemPassThru::Connect(void __near * (*)(char const __near *,int __near *))
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CFileSystemPassThru::Connect(CFileSystemPassThru *this, void *(__cdecl *factory)(const char *, int *))
{
  return this->m_pFileSystemPassThru->Connect(this: this->m_pFileSystemPassThru, a2: factory);
}

//------------------------------------------------------------------------------
// Address: 0x100219E0
// Name: public: virtual void CFileSystemPassThru::Disconnect(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFileSystemPassThru::Disconnect(CFileSystemPassThru *this)
{
  this->m_pFileSystemPassThru->Disconnect(this: this->m_pFileSystemPassThru);
}

//------------------------------------------------------------------------------
// Address: 0x100219F0
// Name: public: virtual void __near * CFileSystemPassThru::QueryInterface(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void *__thiscall CFileSystemPassThru::QueryInterface(CFileSystemPassThru *this, const char *pInterfaceName)
{
  return this->m_pFileSystemPassThru->QueryInterface(this: this->m_pFileSystemPassThru, a2: pInterfaceName);
}

//------------------------------------------------------------------------------
// Address: 0x10021A00
// Name: public: virtual enum InitReturnVal_t CFileSystemPassThru::Init(void)
// Source: json
//------------------------------------------------------------------------------
InitReturnVal_t __thiscall CFileSystemPassThru::Init(CFileSystemPassThru *this)
{
  return this->m_pFileSystemPassThru->Init(this: this->m_pFileSystemPassThru);
}

//------------------------------------------------------------------------------
// Address: 0x10021A10
// Name: public: virtual void CFileSystemPassThru::Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFileSystemPassThru::Shutdown(CFileSystemPassThru *this)
{
  this->m_pFileSystemPassThru->Shutdown(this: this->m_pFileSystemPassThru);
}

//------------------------------------------------------------------------------
// Address: 0x10021A20
// Name: public: virtual struct AppSystemInfo_t const __near * CFileSystemPassThru::GetDependencies(void)
// Source: json
//------------------------------------------------------------------------------
const AppSystemInfo_t *__thiscall CFileSystemPassThru::GetDependencies(CFileSystemPassThru *this)
{
  return this->m_pFileSystemPassThru->GetDependencies(this: this->m_pFileSystemPassThru);
}

//------------------------------------------------------------------------------
// Address: 0x10021A30
// Name: public: virtual enum AppSystemTier_t CFileSystemPassThru::GetTier(void)
// Source: json
//------------------------------------------------------------------------------
AppSystemTier_t __thiscall CFileSystemPassThru::GetTier(CFileSystemPassThru *this)
{
  return this->m_pFileSystemPassThru->GetTier(this: this->m_pFileSystemPassThru);
}

//------------------------------------------------------------------------------
// Address: 0x10021A40
// Name: public: virtual void CFileSystemPassThru::Reconnect(void __near * (*)(char const __near *,int __near *),char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFileSystemPassThru::Reconnect(
        CFileSystemPassThru *this,
        void *(__cdecl *factory)(const char *, int *),
        const char *pInterfaceName)
{
  this->m_pFileSystemPassThru->Reconnect(this: this->m_pFileSystemPassThru, a2: factory, a3: pInterfaceName);
}

//------------------------------------------------------------------------------
// Address: 0x10021A50
// Name: public: virtual void CFileSystemPassThru::RemoveAllSearchPaths(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFileSystemPassThru::RemoveAllSearchPaths(CFileSystemPassThru *this)
{
  this->m_pFileSystemPassThru->RemoveAllSearchPaths(this: this->m_pFileSystemPassThru);
}

//------------------------------------------------------------------------------
// Address: 0x10021A60
// Name: public: virtual void CFileSystemPassThru::AddSearchPath(char const __near *,char const __near *,enum SearchPathAdd_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFileSystemPassThru::AddSearchPath(
        CFileSystemPassThru *this,
        const char *pPath,
        const char *pathID,
        SearchPathAdd_t addType)
{
  this->m_pFileSystemPassThru->AddSearchPath(this: this->m_pFileSystemPassThru, a2: pPath, a3: pathID, a4: addType);
}

//------------------------------------------------------------------------------
// Address: 0x10021A70
// Name: public: virtual bool CFileSystemPassThru::RemoveSearchPath(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CFileSystemPassThru::RemoveSearchPath(CFileSystemPassThru *this, const char *pPath, const char *pathID)
{
  return this->m_pFileSystemPassThru->RemoveSearchPath(this: this->m_pFileSystemPassThru, a2: pPath, a3: pathID);
}

//------------------------------------------------------------------------------
// Address: 0x10021A80
// Name: public: virtual void CFileSystemPassThru::RemoveFile(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFileSystemPassThru::RemoveFile(
        CFileSystemPassThru *this,
        const char *pRelativePath,
        const char *pathID)
{
  this->m_pFileSystemPassThru->RemoveFile(this: this->m_pFileSystemPassThru, a2: pRelativePath, a3: pathID);
}

//------------------------------------------------------------------------------
// Address: 0x10021A90
// Name: public: virtual bool CFileSystemPassThru::RenameFile(char const __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CFileSystemPassThru::RenameFile(
        CFileSystemPassThru *this,
        const char *pOldPath,
        const char *pNewPath,
        const char *pathID)
{
  return this->m_pFileSystemPassThru->RenameFile(
           this: this->m_pFileSystemPassThru,
           a2: pOldPath,
           a3: pNewPath,
           a4: pathID);
}

//------------------------------------------------------------------------------
// Address: 0x10021AA0
// Name: public: virtual void CFileSystemPassThru::CreateDirHierarchy(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFileSystemPassThru::CreateDirHierarchy(
        CFileSystemPassThru *this,
        const char *path,
        const char *pathID)
{
  this->m_pFileSystemPassThru->CreateDirHierarchy(this: this->m_pFileSystemPassThru, a2: path, a3: pathID);
}

//------------------------------------------------------------------------------
// Address: 0x10021AB0
// Name: public: virtual bool CFileSystemPassThru::IsDirectory(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CFileSystemPassThru::IsDirectory(CFileSystemPassThru *this, const char *pFileName, const char *pathID)
{
  return this->m_pFileSystemPassThru->IsDirectory(this: this->m_pFileSystemPassThru, a2: pFileName, a3: pathID);
}

//------------------------------------------------------------------------------
// Address: 0x10021AC0
// Name: public: virtual void CFileSystemPassThru::FileTimeToString(char __near *,int,long)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFileSystemPassThru::FileTimeToString(
        CFileSystemPassThru *this,
        char *pStrip,
        int maxCharsIncludingTerminator,
        int fileTime)
{
  this->m_pFileSystemPassThru->FileTimeToString(
    this: this->m_pFileSystemPassThru,
    a2: pStrip,
    a3: maxCharsIncludingTerminator,
    a4: fileTime);
}

//------------------------------------------------------------------------------
// Address: 0x10021AD0
// Name: public: virtual void CFileSystemPassThru::SetBufferSize(void __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFileSystemPassThru::SetBufferSize(CFileSystemPassThru *this, void *file, unsigned int nBytes)
{
  this->m_pFileSystemPassThru->SetBufferSize(this: this->m_pFileSystemPassThru, a2: file, a3: nBytes);
}

//------------------------------------------------------------------------------
// Address: 0x10021AE0
// Name: public: virtual bool CFileSystemPassThru::IsOk(void __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CFileSystemPassThru::IsOk(CFileSystemPassThru *this, void *file)
{
  return this->m_pFileSystemPassThru->IsOk(this: this->m_pFileSystemPassThru, a2: file);
}

//------------------------------------------------------------------------------
// Address: 0x10021AF0
// Name: public: virtual bool CFileSystemPassThru::EndOfFile(void __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CFileSystemPassThru::EndOfFile(CFileSystemPassThru *this, void *file)
{
  return this->m_pFileSystemPassThru->EndOfFile(this: this->m_pFileSystemPassThru, a2: file);
}

//------------------------------------------------------------------------------
// Address: 0x10021B00
// Name: public: virtual char __near * CFileSystemPassThru::ReadLine(char __near *,int,void __near *)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CFileSystemPassThru::ReadLine(CFileSystemPassThru *this, char *pOutput, int maxChars, void *file)
{
  return this->m_pFileSystemPassThru->ReadLine(this: this->m_pFileSystemPassThru, a2: pOutput, a3: maxChars, a4: file);
}

//------------------------------------------------------------------------------
// Address: 0x10021B10
// Name: public: virtual int CFileSystemPassThru::FPrintf(void __near *,char const __near *,...)
// Source: json
//------------------------------------------------------------------------------
int CFileSystemPassThru::FPrintf(CFileSystemPassThru *this, void *file, char *pFormat, ...)
{
  char string[8192]; // [esp+0h] [ebp-2000h] BYREF
  va_list ap; // [esp+2014h] [ebp+14h] BYREF

  va_start(ap, pFormat);
  _vsnprintf(string, count: 0x2000u, format: pFormat, ap);
  return this->m_pFileSystemPassThru->FPrintf(this: this->m_pFileSystemPassThru, a2: file, a3: "%s", string);
}

//------------------------------------------------------------------------------
// Address: 0x10021B60
// Name: public: virtual class CSysModule __near * CFileSystemPassThru::LoadModule(char const __near *,char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
struct CSysModule *__thiscall CFileSystemPassThru::LoadModule(
        CFileSystemPassThru *this,
        const char *pFileName,
        const char *pPathID,
        BOOL bValidatedDllOnly)
{
  return this->m_pFileSystemPassThru->LoadModule(
           this: this->m_pFileSystemPassThru,
           a2: pFileName,
           a3: pPathID,
           a4: bValidatedDllOnly);
}

//------------------------------------------------------------------------------
// Address: 0x10021B70
// Name: public: virtual void CFileSystemPassThru::UnloadModule(class CSysModule __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFileSystemPassThru::UnloadModule(CFileSystemPassThru *this, struct CSysModule *pModule)
{
  this->m_pFileSystemPassThru->UnloadModule(this: this->m_pFileSystemPassThru, a2: pModule);
}

//------------------------------------------------------------------------------
// Address: 0x10021B80
// Name: public: virtual char const __near * CFileSystemPassThru::FindFirst(char const __near *,int __near *)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CFileSystemPassThru::FindFirst(CFileSystemPassThru *this, const char *pWildCard, int *pHandle)
{
  return this->m_pFileSystemPassThru->FindFirst(this: this->m_pFileSystemPassThru, a2: pWildCard, a3: pHandle);
}

//------------------------------------------------------------------------------
// Address: 0x10021B90
// Name: public: virtual char const __near * CFileSystemPassThru::FindNext(int)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CFileSystemPassThru::FindNext(CFileSystemPassThru *this, int handle)
{
  return this->m_pFileSystemPassThru->FindNext(this: this->m_pFileSystemPassThru, a2: handle);
}

//------------------------------------------------------------------------------
// Address: 0x10021BA0
// Name: public: virtual bool CFileSystemPassThru::FindIsDirectory(int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CFileSystemPassThru::FindIsDirectory(CFileSystemPassThru *this, int handle)
{
  return this->m_pFileSystemPassThru->FindIsDirectory(this: this->m_pFileSystemPassThru, a2: handle);
}

//------------------------------------------------------------------------------
// Address: 0x10021BC0
// Name: public: virtual void CFileSystemPassThru::FindClose(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFileSystemPassThru::FindClose(CFileSystemPassThru *this, int handle)
{
  this->m_pFileSystemPassThru->FindClose(this: this->m_pFileSystemPassThru, a2: handle);
}

//------------------------------------------------------------------------------
// Address: 0x10021BE0
// Name: public: virtual void CFileSystemPassThru::FindFileAbsoluteList(class CUtlVector<class CUtlString,class CUtlMemory<class CUtlString,int>> __near &,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFileSystemPassThru::FindFileAbsoluteList(
        CFileSystemPassThru *this,
        CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *outAbsolutePathNames,
        const char *pWildCard,
        const char *pPathID)
{
  this->m_pFileSystemPassThru->FindFileAbsoluteList(
    this: this->m_pFileSystemPassThru,
    a2: outAbsolutePathNames,
    a3: pWildCard,
    a4: pPathID);
}

//------------------------------------------------------------------------------
// Address: 0x10021C00
// Name: public: virtual char const __near * CFileSystemPassThru::GetLocalPath(char const __near *,char __near *,int)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CFileSystemPassThru::GetLocalPath(
        CFileSystemPassThru *this,
        const char *pFileName,
        char *pLocalPath,
        int localPathBufferSize)
{
  return this->m_pFileSystemPassThru->GetLocalPath(
           this: this->m_pFileSystemPassThru,
           a2: pFileName,
           a3: pLocalPath,
           a4: localPathBufferSize);
}

//------------------------------------------------------------------------------
// Address: 0x10021C20
// Name: public: virtual bool CFileSystemPassThru::FullPathToRelativePath(char const __near *,char __near *,int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CFileSystemPassThru::FullPathToRelativePath(
        CFileSystemPassThru *this,
        const char *pFullpath,
        char *pRelative,
        int maxlen)
{
  return this->m_pFileSystemPassThru->FullPathToRelativePath(
           this: this->m_pFileSystemPassThru,
           a2: pFullpath,
           a3: pRelative,
           a4: maxlen);
}

//------------------------------------------------------------------------------
// Address: 0x10021C40
// Name: public: virtual bool CFileSystemPassThru::GetCurrentDirectory(char __near *,int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CFileSystemPassThru::GetCurrentDirectory(CFileSystemPassThru *this, char *pDirectory, int maxlen)
{
  return this->m_pFileSystemPassThru->GetCurrentDirectoryA(
           this: this->m_pFileSystemPassThru,
           a2: pDirectory,
           a3: maxlen);
}

//------------------------------------------------------------------------------
// Address: 0x10021C60
// Name: public: virtual void CFileSystemPassThru::PrintOpenedFiles(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFileSystemPassThru::PrintOpenedFiles(CFileSystemPassThru *this)
{
  this->m_pFileSystemPassThru->PrintOpenedFiles(this: this->m_pFileSystemPassThru);
}

//------------------------------------------------------------------------------
// Address: 0x10021C70
// Name: public: virtual void CFileSystemPassThru::PrintSearchPaths(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFileSystemPassThru::PrintSearchPaths(CFileSystemPassThru *this)
{
  this->m_pFileSystemPassThru->PrintSearchPaths(this: this->m_pFileSystemPassThru);
}

//------------------------------------------------------------------------------
// Address: 0x10021C80
// Name: public: virtual void CFileSystemPassThru::SetWarningFunc(void (*)(char const __near *,...))
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFileSystemPassThru::SetWarningFunc(CFileSystemPassThru *this, void (*pfnWarning)(const char *, ...))
{
  this->m_pFileSystemPassThru->SetWarningFunc(this: this->m_pFileSystemPassThru, a2: pfnWarning);
}

//------------------------------------------------------------------------------
// Address: 0x10021CA0
// Name: public: virtual void CFileSystemPassThru::SetWarningLevel(enum FileWarningLevel_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFileSystemPassThru::SetWarningLevel(CFileSystemPassThru *this, FileWarningLevel_t level)
{
  this->m_pFileSystemPassThru->SetWarningLevel(this: this->m_pFileSystemPassThru, a2: level);
}

//------------------------------------------------------------------------------
// Address: 0x10021CC0
// Name: public: virtual void CFileSystemPassThru::AddLoggingFunc(void (*)(char const __near *,char const __near *))
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFileSystemPassThru::AddLoggingFunc(
        CFileSystemPassThru *this,
        void (__cdecl *pfnLogFunc)(const char *, const char *))
{
  this->m_pFileSystemPassThru->AddLoggingFunc(this: this->m_pFileSystemPassThru, a2: pfnLogFunc);
}

//------------------------------------------------------------------------------
// Address: 0x10021CE0
// Name: public: virtual void CFileSystemPassThru::RemoveLoggingFunc(void (*)(char const __near *,char const __near *))
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFileSystemPassThru::RemoveLoggingFunc(
        CFileSystemPassThru *this,
        void (__cdecl *logFunc)(const char *, const char *))
{
  this->m_pFileSystemPassThru->RemoveLoggingFunc(this: this->m_pFileSystemPassThru, a2: logFunc);
}

//------------------------------------------------------------------------------
// Address: 0x10021D00
// Name: public: virtual enum FSAsyncStatus_t CFileSystemPassThru::AsyncReadMultiple(struct FileAsyncRequest_t const __near *,int,struct FSAsyncControl_t__ __near * __near *)
// Source: json
//------------------------------------------------------------------------------
FSAsyncStatus_t __thiscall CFileSystemPassThru::AsyncReadMultiple(
        CFileSystemPassThru *this,
        const FileAsyncRequest_t *pRequests,
        int nRequests,
        FSAsyncControl_t__ **pControls)
{
  return this->m_pFileSystemPassThru->AsyncReadMultiple(
           this: this->m_pFileSystemPassThru,
           a2: pRequests,
           a3: nRequests,
           a4: pControls);
}

//------------------------------------------------------------------------------
// Address: 0x10021D20
// Name: public: virtual enum FSAsyncStatus_t CFileSystemPassThru::AsyncReadMultipleCreditAlloc(struct FileAsyncRequest_t const __near *,int,char const __near *,int,struct FSAsyncControl_t__ __near * __near *)
// Source: json
//------------------------------------------------------------------------------
FSAsyncStatus_t __thiscall CFileSystemPassThru::AsyncReadMultipleCreditAlloc(
        CFileSystemPassThru *this,
        const FileAsyncRequest_t *pRequests,
        int nRequests,
        const char *pszFile,
        int line,
        FSAsyncControl_t__ **pControls)
{
  return this->m_pFileSystemPassThru->AsyncReadMultipleCreditAlloc(
           this: this->m_pFileSystemPassThru,
           a2: pRequests,
           a3: nRequests,
           a4: pszFile,
           a5: line,
           a6: pControls);
}

//------------------------------------------------------------------------------
// Address: 0x10021D40
// Name: public: virtual enum FSAsyncStatus_t CFileSystemPassThru::AsyncDirectoryScan(char const __near *,bool,void __near *,void (*)(void __near *,char __near *,char __near *),void (*)(void __near *,enum FSAsyncStatus_t),struct FSAsyncControl_t__ __near * __near *)
// Source: json
//------------------------------------------------------------------------------
FSAsyncStatus_t __thiscall CFileSystemPassThru::AsyncDirectoryScan(
        CFileSystemPassThru *this,
        const char *pSearchSpec,
        BOOL recurseFolders,
        void *pContext,
        void (__cdecl *pfnAdd)(void *, char *, char *),
        void (__cdecl *pfnDone)(void *, FSAsyncStatus_t),
        FSAsyncControl_t__ **pControl)
{
  return this->m_pFileSystemPassThru->AsyncDirectoryScan(
           this: this->m_pFileSystemPassThru,
           a2: pSearchSpec,
           a3: recurseFolders,
           a4: pContext,
           a5: pfnAdd,
           a6: pfnDone,
           a7: pControl);
}

//------------------------------------------------------------------------------
// Address: 0x10021D60
// Name: public: virtual enum FSAsyncStatus_t CFileSystemPassThru::AsyncFinish(struct FSAsyncControl_t__ __near *,bool)
// Source: json
//------------------------------------------------------------------------------
FSAsyncStatus_t __thiscall CFileSystemPassThru::AsyncFinish(
        CFileSystemPassThru *this,
        FSAsyncControl_t__ *hControl,
        BOOL wait)
{
  return this->m_pFileSystemPassThru->AsyncFinish(this: this->m_pFileSystemPassThru, a2: hControl, a3: wait);
}

//------------------------------------------------------------------------------
// Address: 0x10021D80
// Name: public: virtual enum FSAsyncStatus_t CFileSystemPassThru::AsyncGetResult(struct FSAsyncControl_t__ __near *,void __near * __near *,int __near *)
// Source: json
//------------------------------------------------------------------------------
FSAsyncStatus_t __thiscall CFileSystemPassThru::AsyncGetResult(
        CFileSystemPassThru *this,
        FSAsyncControl_t__ *hControl,
        void **ppData,
        int *pSize)
{
  return this->m_pFileSystemPassThru->AsyncGetResult(
           this: this->m_pFileSystemPassThru,
           a2: hControl,
           a3: ppData,
           a4: pSize);
}

//------------------------------------------------------------------------------
// Address: 0x10021DA0
// Name: public: virtual enum FSAsyncStatus_t CFileSystemPassThru::AsyncAbort(struct FSAsyncControl_t__ __near *)
// Source: json
//------------------------------------------------------------------------------
FSAsyncStatus_t __thiscall CFileSystemPassThru::AsyncAbort(CFileSystemPassThru *this, FSAsyncControl_t__ *hControl)
{
  return this->m_pFileSystemPassThru->AsyncAbort(this: this->m_pFileSystemPassThru, a2: hControl);
}

//------------------------------------------------------------------------------
// Address: 0x10021DC0
// Name: public: virtual enum FSAsyncStatus_t CFileSystemPassThru::AsyncStatus(struct FSAsyncControl_t__ __near *)
// Source: json
//------------------------------------------------------------------------------
FSAsyncStatus_t __thiscall CFileSystemPassThru::AsyncStatus(CFileSystemPassThru *this, FSAsyncControl_t__ *hControl)
{
  return this->m_pFileSystemPassThru->AsyncStatus(this: this->m_pFileSystemPassThru, a2: hControl);
}

//------------------------------------------------------------------------------
// Address: 0x10021DE0
// Name: public: virtual enum FSAsyncStatus_t CFileSystemPassThru::AsyncFlush(void)
// Source: json
//------------------------------------------------------------------------------
FSAsyncStatus_t __thiscall CFileSystemPassThru::AsyncFlush(CFileSystemPassThru *this)
{
  return this->m_pFileSystemPassThru->AsyncFlush(this: this->m_pFileSystemPassThru);
}

//------------------------------------------------------------------------------
// Address: 0x10021DF0
// Name: public: virtual void CFileSystemPassThru::AsyncAddRef(struct FSAsyncControl_t__ __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFileSystemPassThru::AsyncAddRef(CFileSystemPassThru *this, FSAsyncControl_t__ *hControl)
{
  this->m_pFileSystemPassThru->AsyncAddRef(this: this->m_pFileSystemPassThru, a2: hControl);
}

//------------------------------------------------------------------------------
// Address: 0x10021E10
// Name: public: virtual void CFileSystemPassThru::AsyncRelease(struct FSAsyncControl_t__ __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFileSystemPassThru::AsyncRelease(CFileSystemPassThru *this, FSAsyncControl_t__ *hControl)
{
  this->m_pFileSystemPassThru->AsyncRelease(this: this->m_pFileSystemPassThru, a2: hControl);
}

//------------------------------------------------------------------------------
// Address: 0x10021E30
// Name: public: virtual enum FSAsyncStatus_t CFileSystemPassThru::AsyncBeginRead(char const __near *,struct FSAsyncFile_t__ __near * __near *)
// Source: json
//------------------------------------------------------------------------------
FSAsyncStatus_t __thiscall CFileSystemPassThru::AsyncBeginRead(
        CFileSystemPassThru *this,
        const char *pszFile,
        FSAsyncFile_t__ **phFile)
{
  return this->m_pFileSystemPassThru->AsyncBeginRead(this: this->m_pFileSystemPassThru, a2: pszFile, a3: phFile);
}

//------------------------------------------------------------------------------
// Address: 0x10021E50
// Name: public: virtual enum FSAsyncStatus_t CFileSystemPassThru::AsyncEndRead(struct FSAsyncFile_t__ __near *)
// Source: json
//------------------------------------------------------------------------------
FSAsyncStatus_t __thiscall CFileSystemPassThru::AsyncEndRead(CFileSystemPassThru *this, FSAsyncFile_t__ *hFile)
{
  return this->m_pFileSystemPassThru->AsyncEndRead(this: this->m_pFileSystemPassThru, a2: hFile);
}

//------------------------------------------------------------------------------
// Address: 0x10021E70
// Name: public: virtual struct FileSystemStatistics const __near * CFileSystemPassThru::GetFilesystemStatistics(void)
// Source: json
//------------------------------------------------------------------------------
const FileSystemStatistics *__thiscall CFileSystemPassThru::GetFilesystemStatistics(CFileSystemPassThru *this)
{
  return this->m_pFileSystemPassThru->GetFilesystemStatistics(this: this->m_pFileSystemPassThru);
}

//------------------------------------------------------------------------------
// Address: 0x10021E80
// Name: public: virtual int CFileSystemPassThru::WaitForResources(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CFileSystemPassThru::WaitForResources(CFileSystemPassThru *this, const char *resourcelist)
{
  return this->m_pFileSystemPassThru->WaitForResources(this: this->m_pFileSystemPassThru, a2: resourcelist);
}

//------------------------------------------------------------------------------
// Address: 0x10021EA0
// Name: public: virtual bool CFileSystemPassThru::GetWaitForResourcesProgress(int,float __near *,bool __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CFileSystemPassThru::GetWaitForResourcesProgress(
        CFileSystemPassThru *this,
        int handle,
        float *progress,
        bool *complete)
{
  return this->m_pFileSystemPassThru->GetWaitForResourcesProgress(
           this: this->m_pFileSystemPassThru,
           a2: handle,
           a3: progress,
           a4: complete);
}

//------------------------------------------------------------------------------
// Address: 0x10021EC0
// Name: public: virtual void CFileSystemPassThru::CancelWaitForResources(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFileSystemPassThru::CancelWaitForResources(CFileSystemPassThru *this, int handle)
{
  this->m_pFileSystemPassThru->CancelWaitForResources(this: this->m_pFileSystemPassThru, a2: handle);
}

//------------------------------------------------------------------------------
// Address: 0x10021EE0
// Name: public: virtual int CFileSystemPassThru::HintResourceNeed(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CFileSystemPassThru::HintResourceNeed(
        CFileSystemPassThru *this,
        const char *hintlist,
        int forgetEverything)
{
  return this->m_pFileSystemPassThru->HintResourceNeed(
           this: this->m_pFileSystemPassThru,
           a2: hintlist,
           a3: forgetEverything);
}

//------------------------------------------------------------------------------
// Address: 0x10021F00
// Name: public: virtual bool CFileSystemPassThru::IsFileImmediatelyAvailable(char const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CFileSystemPassThru::IsFileImmediatelyAvailable(CFileSystemPassThru *this, const char *pFileName)
{
  return this->m_pFileSystemPassThru->IsFileImmediatelyAvailable(this: this->m_pFileSystemPassThru, a2: pFileName);
}

//------------------------------------------------------------------------------
// Address: 0x10021F20
// Name: public: virtual void CFileSystemPassThru::GetLocalCopy(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFileSystemPassThru::GetLocalCopy(CFileSystemPassThru *this, const char *pFileName)
{
  this->m_pFileSystemPassThru->GetLocalCopy(this: this->m_pFileSystemPassThru, a2: pFileName);
}

//------------------------------------------------------------------------------
// Address: 0x10021F40
// Name: public: virtual void __near * CFileSystemPassThru::FindOrAddFileName(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void *__thiscall CFileSystemPassThru::FindOrAddFileName(CFileSystemPassThru *this, const char *pFileName)
{
  return this->m_pFileSystemPassThru->FindOrAddFileName(this: this->m_pFileSystemPassThru, a2: pFileName);
}

//------------------------------------------------------------------------------
// Address: 0x10021F60
// Name: public: virtual void __near * CFileSystemPassThru::FindFileName(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void *__thiscall CFileSystemPassThru::FindFileName(CFileSystemPassThru *this, const char *pFileName)
{
  return this->m_pFileSystemPassThru->FindFileName(this: this->m_pFileSystemPassThru, a2: pFileName);
}

//------------------------------------------------------------------------------
// Address: 0x10021F80
// Name: public: virtual bool CFileSystemPassThru::String(void __near * const __near &,char __near *,int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CFileSystemPassThru::String(CFileSystemPassThru *this, void *const *handle, char *buf, int buflen)
{
  return this->m_pFileSystemPassThru->String(this: this->m_pFileSystemPassThru, a2: handle, a3: buf, a4: buflen);
}

//------------------------------------------------------------------------------
// Address: 0x10021FA0
// Name: public: virtual bool CFileSystemPassThru::IsOk2(void __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CFileSystemPassThru::IsOk2(CFileSystemPassThru *this, void *file)
{
  return this->IsOk(this, a2: file);
}

//------------------------------------------------------------------------------
// Address: 0x10021FB0
// Name: public: virtual void CFileSystemPassThru::RemoveSearchPaths(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFileSystemPassThru::RemoveSearchPaths(CFileSystemPassThru *this, const char *szPathID)
{
  this->m_pFileSystemPassThru->RemoveSearchPaths(this: this->m_pFileSystemPassThru, a2: szPathID);
}

//------------------------------------------------------------------------------
// Address: 0x10021FC0
// Name: public: virtual bool CFileSystemPassThru::IsSteam(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CFileSystemPassThru::IsSteam(CFileSystemPassThru *this)
{
  return this->m_pFileSystemPassThru->IsSteam(this: this->m_pFileSystemPassThru);
}

//------------------------------------------------------------------------------
// Address: 0x10021FD0
// Name: public: virtual enum FilesystemMountRetval_t CFileSystemPassThru::MountSteamContent(int)
// Source: json
//------------------------------------------------------------------------------
FilesystemMountRetval_t __thiscall CFileSystemPassThru::MountSteamContent(CFileSystemPassThru *this, int nExtraAppId)
{
  return this->m_pFileSystemPassThru->MountSteamContent(this: this->m_pFileSystemPassThru, a2: nExtraAppId);
}

//------------------------------------------------------------------------------
// Address: 0x10021FE0
// Name: public: virtual char const __near * CFileSystemPassThru::FindFirstEx(char const __near *,char const __near *,int __near *)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CFileSystemPassThru::FindFirstEx(
        CFileSystemPassThru *this,
        const char *pWildCard,
        const char *pPathID,
        int *pHandle)
{
  return this->m_pFileSystemPassThru->FindFirstEx(
           this: this->m_pFileSystemPassThru,
           a2: pWildCard,
           a3: pPathID,
           a4: pHandle);
}

//------------------------------------------------------------------------------
// Address: 0x10022000
// Name: public: virtual void CFileSystemPassThru::MarkPathIDByRequestOnly(char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFileSystemPassThru::MarkPathIDByRequestOnly(
        CFileSystemPassThru *this,
        const char *pPathID,
        BOOL bRequestOnly)
{
  this->m_pFileSystemPassThru->MarkPathIDByRequestOnly(this: this->m_pFileSystemPassThru, a2: pPathID, a3: bRequestOnly);
}

//------------------------------------------------------------------------------
// Address: 0x10022010
// Name: public: virtual bool CFileSystemPassThru::AddPackFile(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CFileSystemPassThru::AddPackFile(CFileSystemPassThru *this, const char *fullpath, const char *pathID)
{
  return this->m_pFileSystemPassThru->AddPackFile(this: this->m_pFileSystemPassThru, a2: fullpath, a3: pathID);
}

//------------------------------------------------------------------------------
// Address: 0x10022020
// Name: public: virtual enum FSAsyncStatus_t CFileSystemPassThru::AsyncAppend(char const __near *,void const __near *,int,bool,struct FSAsyncControl_t__ __near * __near *)
// Source: json
//------------------------------------------------------------------------------
FSAsyncStatus_t __thiscall CFileSystemPassThru::AsyncAppend(
        CFileSystemPassThru *this,
        const char *pFileName,
        const void *pSrc,
        int nSrcBytes,
        BOOL bFreeMemory,
        FSAsyncControl_t__ **pControl)
{
  return this->m_pFileSystemPassThru->AsyncAppend(
           this: this->m_pFileSystemPassThru,
           a2: pFileName,
           a3: pSrc,
           a4: nSrcBytes,
           a5: bFreeMemory,
           a6: pControl);
}

//------------------------------------------------------------------------------
// Address: 0x10022040
// Name: public: virtual enum FSAsyncStatus_t CFileSystemPassThru::AsyncWrite(char const __near *,void const __near *,int,bool,bool,struct FSAsyncControl_t__ __near * __near *)
// Source: json
//------------------------------------------------------------------------------
FSAsyncStatus_t __thiscall CFileSystemPassThru::AsyncWrite(
        CFileSystemPassThru *this,
        const char *pFileName,
        const void *pSrc,
        int nSrcBytes,
        BOOL bFreeMemory,
        BOOL bAppend,
        FSAsyncControl_t__ **pControl)
{
  return this->m_pFileSystemPassThru->AsyncWrite(
           this: this->m_pFileSystemPassThru,
           a2: pFileName,
           a3: pSrc,
           a4: nSrcBytes,
           a5: bFreeMemory,
           a6: bAppend,
           a7: pControl);
}

//------------------------------------------------------------------------------
// Address: 0x10022060
// Name: public: virtual enum FSAsyncStatus_t CFileSystemPassThru::AsyncWriteFile(char const __near *,class CUtlBuffer const __near *,int,bool,bool,struct FSAsyncControl_t__ __near * __near *)
// Source: json
//------------------------------------------------------------------------------
FSAsyncStatus_t __thiscall CFileSystemPassThru::AsyncWriteFile(
        CFileSystemPassThru *this,
        const char *pFileName,
        const CUtlBuffer *pSrc,
        int nSrcBytes,
        BOOL bFreeMemory,
        BOOL bAppend,
        FSAsyncControl_t__ **pControl)
{
  return this->m_pFileSystemPassThru->AsyncWriteFile(
           this: this->m_pFileSystemPassThru,
           a2: pFileName,
           a3: pSrc,
           a4: nSrcBytes,
           a5: bFreeMemory,
           a6: bAppend,
           a7: pControl);
}

//------------------------------------------------------------------------------
// Address: 0x10022080
// Name: public: virtual enum FSAsyncStatus_t CFileSystemPassThru::AsyncAppendFile(char const __near *,char const __near *,struct FSAsyncControl_t__ __near * __near *)
// Source: json
//------------------------------------------------------------------------------
FSAsyncStatus_t __thiscall CFileSystemPassThru::AsyncAppendFile(
        CFileSystemPassThru *this,
        const char *pDestFileName,
        const char *pSrcFileName,
        FSAsyncControl_t__ **pControl)
{
  return this->m_pFileSystemPassThru->AsyncAppendFile(
           this: this->m_pFileSystemPassThru,
           a2: pDestFileName,
           a3: pSrcFileName,
           a4: pControl);
}

//------------------------------------------------------------------------------
// Address: 0x100220A0
// Name: public: virtual void CFileSystemPassThru::AsyncFinishAll(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFileSystemPassThru::AsyncFinishAll(CFileSystemPassThru *this, int iToPriority)
{
  this->m_pFileSystemPassThru->AsyncFinishAll(this: this->m_pFileSystemPassThru, a2: iToPriority);
}

//------------------------------------------------------------------------------
// Address: 0x100220C0
// Name: public: virtual void CFileSystemPassThru::AsyncFinishAllWrites(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFileSystemPassThru::AsyncFinishAllWrites(CFileSystemPassThru *this)
{
  this->m_pFileSystemPassThru->AsyncFinishAllWrites(this: this->m_pFileSystemPassThru);
}

//------------------------------------------------------------------------------
// Address: 0x100220D0
// Name: public: virtual enum FSAsyncStatus_t CFileSystemPassThru::AsyncSetPriority(struct FSAsyncControl_t__ __near *,int)
// Source: json
//------------------------------------------------------------------------------
FSAsyncStatus_t __thiscall CFileSystemPassThru::AsyncSetPriority(
        CFileSystemPassThru *this,
        FSAsyncControl_t__ *hControl,
        int newPriority)
{
  return this->m_pFileSystemPassThru->AsyncSetPriority(this: this->m_pFileSystemPassThru, a2: hControl, a3: newPriority);
}

//------------------------------------------------------------------------------
// Address: 0x100220F0
// Name: public: virtual bool CFileSystemPassThru::AsyncSuspend(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CFileSystemPassThru::AsyncSuspend(CFileSystemPassThru *this)
{
  return this->m_pFileSystemPassThru->AsyncSuspend(this: this->m_pFileSystemPassThru);
}

//------------------------------------------------------------------------------
// Address: 0x10022100
// Name: public: virtual bool CFileSystemPassThru::AsyncResume(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CFileSystemPassThru::AsyncResume(CFileSystemPassThru *this)
{
  return this->m_pFileSystemPassThru->AsyncResume(this: this->m_pFileSystemPassThru);
}

//------------------------------------------------------------------------------
// Address: 0x10022110
// Name: public: virtual char const __near * CFileSystemPassThru::RelativePathToFullPath(char const __near *,char const __near *,char __near *,int,enum PathTypeFilter_t,unsigned int __near *)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CFileSystemPassThru::RelativePathToFullPath(
        CFileSystemPassThru *this,
        const char *pFileName,
        const char *pPathID,
        char *pLocalPath,
        int localPathBufferSize,
        PathTypeFilter_t pathFilter,
        unsigned int *pPathType)
{
  return this->m_pFileSystemPassThru->RelativePathToFullPath(
           this: this->m_pFileSystemPassThru,
           a2: pFileName,
           a3: pPathID,
           a4: pLocalPath,
           a5: localPathBufferSize,
           a6: pathFilter,
           a7: pPathType);
}

//------------------------------------------------------------------------------
// Address: 0x10022120
// Name: public: virtual int CFileSystemPassThru::GetSearchPath(char const __near *,bool,char __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CFileSystemPassThru::GetSearchPath(
        CFileSystemPassThru *this,
        const char *pathID,
        BOOL bGetPackFiles,
        char *pPath,
        int nMaxLen)
{
  return this->m_pFileSystemPassThru->GetSearchPath(
           this: this->m_pFileSystemPassThru,
           a2: pathID,
           a3: bGetPackFiles,
           a4: pPath,
           a5: nMaxLen);
}

//------------------------------------------------------------------------------
// Address: 0x10022130
// Name: public: virtual void __near * CFileSystemPassThru::OpenEx(char const __near *,char const __near *,unsigned int,char const __near *,char __near * __near *)
// Source: json
//------------------------------------------------------------------------------
void *__thiscall CFileSystemPassThru::OpenEx(
        CFileSystemPassThru *this,
        const char *pFileName,
        const char *pOptions,
        unsigned int flags,
        const char *pathID,
        char **ppszResolvedFilename)
{
  return this->m_pFileSystemPassThru->OpenEx(
           this: this->m_pFileSystemPassThru,
           a2: pFileName,
           a3: pOptions,
           a4: flags,
           a5: pathID,
           a6: ppszResolvedFilename);
}

//------------------------------------------------------------------------------
// Address: 0x10022150
// Name: public: virtual int CFileSystemPassThru::ReadEx(void __near *,int,int,void __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CFileSystemPassThru::ReadEx(
        CFileSystemPassThru *this,
        void *pOutput,
        int destSize,
        int size,
        void *file)
{
  return this->m_pFileSystemPassThru->ReadEx(
           this: this->m_pFileSystemPassThru,
           a2: pOutput,
           a3: destSize,
           a4: size,
           a5: file);
}

//------------------------------------------------------------------------------
// Address: 0x10022170
// Name: public: virtual int CFileSystemPassThru::ReadFileEx(char const __near *,char const __near *,void __near * __near *,bool,bool,int,int,void __near * (*)(char const __near *,unsigned int))
// Source: json
//------------------------------------------------------------------------------
int __thiscall CFileSystemPassThru::ReadFileEx(
        CFileSystemPassThru *this,
        const char *pFileName,
        const char *pPath,
        void **ppBuf,
        BOOL bNullTerminate,
        BOOL bOptimalAlloc,
        int nMaxBytes,
        int nStartingByte,
        void *(__cdecl *pfnAlloc)(const char *, unsigned int))
{
  return this->m_pFileSystemPassThru->ReadFileEx(
           this: this->m_pFileSystemPassThru,
           a2: pFileName,
           a3: pPath,
           a4: ppBuf,
           a5: bNullTerminate,
           a6: bOptimalAlloc,
           a7: nMaxBytes,
           a8: nStartingByte,
           a9: pfnAlloc);
}

//------------------------------------------------------------------------------
// Address: 0x10022190
// Name: public: virtual class KeyValues __near * CFileSystemPassThru::LoadKeyValues(enum IFileSystem::KeyValuesPreloadType_t,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
KeyValues *__thiscall CFileSystemPassThru::LoadKeyValues(
        CFileSystemPassThru *this,
        IFileSystem::KeyValuesPreloadType_t type,
        const char *filename,
        const char *pPathID)
{
  return this->m_pFileSystemPassThru->LoadKeyValues_2(
           this: this->m_pFileSystemPassThru,
           a2: type,
           a3: filename,
           a4: pPathID);
}

//------------------------------------------------------------------------------
// Address: 0x100221B0
// Name: public: virtual bool CFileSystemPassThru::LoadKeyValues(class KeyValues __near &,enum IFileSystem::KeyValuesPreloadType_t,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CFileSystemPassThru::LoadKeyValues(
        CFileSystemPassThru *this,
        KeyValues *head,
        IFileSystem::KeyValuesPreloadType_t type,
        const char *filename,
        const char *pPathID)
{
  return this->m_pFileSystemPassThru->LoadKeyValues(
           this: this->m_pFileSystemPassThru,
           a2: head,
           a3: type,
           a4: filename,
           a5: pPathID);
}

//------------------------------------------------------------------------------
// Address: 0x100221D0
// Name: public: virtual bool CFileSystemPassThru::GetFileTypeForFullPath(char const __near *,wchar_t __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CFileSystemPassThru::GetFileTypeForFullPath(
        CFileSystemPassThru *this,
        const char *pFullPath,
        wchar_t *buf,
        unsigned int bufSizeInBytes)
{
  return this->m_pFileSystemPassThru->GetFileTypeForFullPath(
           this: this->m_pFileSystemPassThru,
           a2: pFullPath,
           a3: buf,
           a4: bufSizeInBytes);
}

//------------------------------------------------------------------------------
// Address: 0x100221F0
// Name: public: virtual bool CFileSystemPassThru::GetOptimalIOConstraints(void __near *,unsigned int __near *,unsigned int __near *,unsigned int __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CFileSystemPassThru::GetOptimalIOConstraints(
        CFileSystemPassThru *this,
        void *hFile,
        unsigned int *pOffsetAlign,
        unsigned int *pSizeAlign,
        unsigned int *pBufferAlign)
{
  return this->m_pFileSystemPassThru->GetOptimalIOConstraints(
           this: this->m_pFileSystemPassThru,
           a2: hFile,
           a3: pOffsetAlign,
           a4: pSizeAlign,
           a5: pBufferAlign);
}

//------------------------------------------------------------------------------
// Address: 0x10022210
// Name: public: virtual void __near * CFileSystemPassThru::AllocOptimalReadBuffer(void __near *,unsigned int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void *__thiscall CFileSystemPassThru::AllocOptimalReadBuffer(
        CFileSystemPassThru *this,
        void *hFile,
        unsigned int nSize,
        unsigned int nOffset)
{
  return this->m_pFileSystemPassThru->AllocOptimalReadBuffer(
           this: this->m_pFileSystemPassThru,
           a2: hFile,
           a3: nOffset,
           a4: nSize);
}

//------------------------------------------------------------------------------
// Address: 0x10022230
// Name: public: virtual void CFileSystemPassThru::FreeOptimalReadBuffer(void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFileSystemPassThru::FreeOptimalReadBuffer(CFileSystemPassThru *this, void *p)
{
  this->m_pFileSystemPassThru->FreeOptimalReadBuffer(this: this->m_pFileSystemPassThru, a2: p);
}

//------------------------------------------------------------------------------
// Address: 0x10022250
// Name: public: virtual void CFileSystemPassThru::BeginMapAccess(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFileSystemPassThru::BeginMapAccess(CFileSystemPassThru *this)
{
  this->m_pFileSystemPassThru->BeginMapAccess(this: this->m_pFileSystemPassThru);
}

//------------------------------------------------------------------------------
// Address: 0x10022260
// Name: public: virtual void CFileSystemPassThru::EndMapAccess(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFileSystemPassThru::EndMapAccess(CFileSystemPassThru *this)
{
  this->m_pFileSystemPassThru->EndMapAccess(this: this->m_pFileSystemPassThru);
}

//------------------------------------------------------------------------------
// Address: 0x10022270
// Name: public: virtual bool CFileSystemPassThru::ReadToBuffer(void __near *,class CUtlBuffer __near &,int,void __near * (*)(char const __near *,unsigned int))
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CFileSystemPassThru::ReadToBuffer(
        CFileSystemPassThru *this,
        void *hFile,
        CUtlBuffer *buf,
        int nMaxBytes,
        void *(__cdecl *pfnAlloc)(const char *, unsigned int))
{
  return this->m_pFileSystemPassThru->ReadToBuffer(
           this: this->m_pFileSystemPassThru,
           a2: hFile,
           a3: buf,
           a4: nMaxBytes,
           a5: pfnAlloc);
}

//------------------------------------------------------------------------------
// Address: 0x10022290
// Name: public: virtual bool CFileSystemPassThru::FullPathToRelativePathEx(char const __near *,char const __near *,char __near *,int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CFileSystemPassThru::FullPathToRelativePathEx(
        CFileSystemPassThru *this,
        const char *pFullPath,
        const char *pPathId,
        char *pRelative,
        int nMaxLen)
{
  return this->m_pFileSystemPassThru->FullPathToRelativePathEx(
           this: this->m_pFileSystemPassThru,
           a2: pFullPath,
           a3: pPathId,
           a4: pRelative,
           a5: nMaxLen);
}

//------------------------------------------------------------------------------
// Address: 0x100222B0
// Name: public: virtual int CFileSystemPassThru::GetPathIndex(void __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CFileSystemPassThru::GetPathIndex(CFileSystemPassThru *this, void *const *handle)
{
  return this->m_pFileSystemPassThru->GetPathIndex(this: this->m_pFileSystemPassThru, a2: handle);
}

//------------------------------------------------------------------------------
// Address: 0x100222D0
// Name: public: virtual long CFileSystemPassThru::GetPathTime(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CFileSystemPassThru::GetPathTime(CFileSystemPassThru *this, const char *pPath, const char *pPathID)
{
  return this->m_pFileSystemPassThru->GetPathTime(this: this->m_pFileSystemPassThru, a2: pPath, a3: pPathID);
}

//------------------------------------------------------------------------------
// Address: 0x100222F0
// Name: public: virtual enum DVDMode_t CFileSystemPassThru::GetDVDMode(void)
// Source: json
//------------------------------------------------------------------------------
DVDMode_t __thiscall CFileSystemPassThru::GetDVDMode(CFileSystemPassThru *this)
{
  return this->m_pFileSystemPassThru->GetDVDMode(this: this->m_pFileSystemPassThru);
}

//------------------------------------------------------------------------------
// Address: 0x10022300
// Name: public: virtual void CFileSystemPassThru::EnableWhitelistFileTracking(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFileSystemPassThru::EnableWhitelistFileTracking(CFileSystemPassThru *this, BOOL bEnable)
{
  this->m_pFileSystemPassThru->EnableWhitelistFileTracking(this: this->m_pFileSystemPassThru, a2: bEnable);
}

//------------------------------------------------------------------------------
// Address: 0x10022320
// Name: public: virtual void CFileSystemPassThru::RegisterFileWhitelist(class IFileList __near *,class IFileList __near *,class IFileList __near * __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFileSystemPassThru::RegisterFileWhitelist(
        CFileSystemPassThru *this,
        struct IFileList *pForceMatchList,
        struct IFileList *pAllowFromDiskList,
        struct IFileList **pFilesToReload)
{
  this->m_pFileSystemPassThru->RegisterFileWhitelist(
    this: this->m_pFileSystemPassThru,
    a2: pForceMatchList,
    a3: pAllowFromDiskList,
    a4: pFilesToReload);
}

//------------------------------------------------------------------------------
// Address: 0x10022340
// Name: public: virtual void CFileSystemPassThru::MarkAllCRCsUnverified(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFileSystemPassThru::MarkAllCRCsUnverified(CFileSystemPassThru *this)
{
  this->m_pFileSystemPassThru->MarkAllCRCsUnverified(this: this->m_pFileSystemPassThru);
}

//------------------------------------------------------------------------------
// Address: 0x10022350
// Name: public: virtual void CFileSystemPassThru::CacheFileCRCs(char const __near *,enum ECacheCRCType,class IFileList __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFileSystemPassThru::CacheFileCRCs(
        CFileSystemPassThru *this,
        const char *pPathname,
        ECacheCRCType eType,
        struct IFileList *pFilter)
{
  this->m_pFileSystemPassThru->CacheFileCRCs(this: this->m_pFileSystemPassThru, a2: pPathname, a3: eType, a4: pFilter);
}

//------------------------------------------------------------------------------
// Address: 0x10022370
// Name: public: virtual enum EFileCRCStatus CFileSystemPassThru::CheckCachedFileCRC(char const __near *,char const __near *,unsigned long __near *)
// Source: json
//------------------------------------------------------------------------------
EFileCRCStatus __thiscall CFileSystemPassThru::CheckCachedFileCRC(
        CFileSystemPassThru *this,
        const char *pPathID,
        const char *pRelativeFilename,
        unsigned int *pCRC)
{
  return this->m_pFileSystemPassThru->CheckCachedFileCRC(
           this: this->m_pFileSystemPassThru,
           a2: pPathID,
           a3: pRelativeFilename,
           a4: pCRC);
}

//------------------------------------------------------------------------------
// Address: 0x10022390
// Name: public: virtual int CFileSystemPassThru::GetUnverifiedCRCFiles(class CUnverifiedCRCFile __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CFileSystemPassThru::GetUnverifiedCRCFiles(
        CFileSystemPassThru *this,
        CUnverifiedCRCFile *pFiles,
        int nMaxFiles)
{
  return this->m_pFileSystemPassThru->GetUnverifiedCRCFiles(
           this: this->m_pFileSystemPassThru,
           a2: pFiles,
           a3: nMaxFiles);
}

//------------------------------------------------------------------------------
// Address: 0x100223B0
// Name: public: virtual int CFileSystemPassThru::GetWhitelistSpewFlags(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CFileSystemPassThru::GetWhitelistSpewFlags(CFileSystemPassThru *this)
{
  return this->m_pFileSystemPassThru->GetWhitelistSpewFlags(this: this->m_pFileSystemPassThru);
}

//------------------------------------------------------------------------------
// Address: 0x100223C0
// Name: public: virtual void CFileSystemPassThru::SetWhitelistSpewFlags(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFileSystemPassThru::SetWhitelistSpewFlags(CFileSystemPassThru *this, int spewFlags)
{
  this->m_pFileSystemPassThru->SetWhitelistSpewFlags(this: this->m_pFileSystemPassThru, a2: spewFlags);
}

//------------------------------------------------------------------------------
// Address: 0x100223E0
// Name: public: virtual void CFileSystemPassThru::InstallDirtyDiskReportFunc(void (*)(void))
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFileSystemPassThru::InstallDirtyDiskReportFunc(CFileSystemPassThru *this, void (__cdecl *func)())
{
  this->m_pFileSystemPassThru->InstallDirtyDiskReportFunc(this: this->m_pFileSystemPassThru, a2: func);
}

//------------------------------------------------------------------------------
// Address: 0x10022400
// Name: public: virtual bool CFileSystemPassThru::IsLaunchedFromXboxHDD(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CFileSystemPassThru::IsLaunchedFromXboxHDD(CFileSystemPassThru *this)
{
  return this->m_pFileSystemPassThru->IsLaunchedFromXboxHDD(this: this->m_pFileSystemPassThru);
}

//------------------------------------------------------------------------------
// Address: 0x10022410
// Name: public: virtual bool CFileSystemPassThru::IsInstalledToXboxHDDCache(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CFileSystemPassThru::IsInstalledToXboxHDDCache(CFileSystemPassThru *this)
{
  return this->m_pFileSystemPassThru->IsInstalledToXboxHDDCache(this: this->m_pFileSystemPassThru);
}

//------------------------------------------------------------------------------
// Address: 0x10022420
// Name: public: virtual bool CFileSystemPassThru::IsDVDHosted(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CFileSystemPassThru::IsDVDHosted(CFileSystemPassThru *this)
{
  return this->m_pFileSystemPassThru->IsDVDHosted(this: this->m_pFileSystemPassThru);
}

//------------------------------------------------------------------------------
// Address: 0x10022430
// Name: public: virtual bool CFileSystemPassThru::IsInstallAllowed(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CFileSystemPassThru::IsInstallAllowed(CFileSystemPassThru *this)
{
  return this->m_pFileSystemPassThru->IsInstallAllowed(this: this->m_pFileSystemPassThru);
}

//------------------------------------------------------------------------------
// Address: 0x10022440
// Name: public: virtual int CFileSystemPassThru::GetSearchPathID(char __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CFileSystemPassThru::GetSearchPathID(CFileSystemPassThru *this, char *pPath, int nMaxLen)
{
  return this->m_pFileSystemPassThru->GetSearchPathID(this: this->m_pFileSystemPassThru, a2: pPath, a3: nMaxLen);
}

//------------------------------------------------------------------------------
// Address: 0x10022460
// Name: public: virtual bool CFileSystemPassThru::FixupSearchPathsAfterInstall(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CFileSystemPassThru::FixupSearchPathsAfterInstall(CFileSystemPassThru *this)
{
  return this->m_pFileSystemPassThru->FixupSearchPathsAfterInstall(this: this->m_pFileSystemPassThru);
}

//------------------------------------------------------------------------------
// Address: 0x10022470
// Name: public: virtual void (*CFileSystemPassThru::GetDirtyDiskReportFunc(void))(void)
// Source: json
//------------------------------------------------------------------------------
void (__cdecl *__thiscall CFileSystemPassThru::GetDirtyDiskReportFunc(CFileSystemPassThru *this))()
{
  return this->m_pFileSystemPassThru->GetDirtyDiskReportFunc(this: this->m_pFileSystemPassThru);
}

//------------------------------------------------------------------------------
// Address: 0x10022480
// Name: public: virtual void CFileSystemPassThru::AddVPKFile(char const __near *,enum SearchPathAdd_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFileSystemPassThru::AddVPKFile(
        CFileSystemPassThru *this,
        const char *pPkName,
        SearchPathAdd_t addType)
{
  this->m_pFileSystemPassThru->AddVPKFile(this: this->m_pFileSystemPassThru, a2: pPkName, a3: addType);
}

//------------------------------------------------------------------------------
// Address: 0x100224A0
// Name: public: virtual void CFileSystemPassThru::RemoveVPKFile(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFileSystemPassThru::RemoveVPKFile(CFileSystemPassThru *this, const char *pPkName)
{
  this->m_pFileSystemPassThru->RemoveVPKFile(this: this->m_pFileSystemPassThru, a2: pPkName);
}

//------------------------------------------------------------------------------
// Address: 0x100224C0
// Name: public: virtual void CFileSystemPassThru::GetVPKFileNames(class CUtlVector<class CUtlString,class CUtlMemory<class CUtlString,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFileSystemPassThru::GetVPKFileNames(
        CFileSystemPassThru *this,
        CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *destVector)
{
  this->m_pFileSystemPassThru->GetVPKFileNames(this: this->m_pFileSystemPassThru, a2: destVector);
}

//------------------------------------------------------------------------------
// Address: 0x100224E0
// Name: public: virtual void CFileSystemPassThru::RemoveAllMapSearchPaths(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFileSystemPassThru::RemoveAllMapSearchPaths(CFileSystemPassThru *this)
{
  this->m_pFileSystemPassThru->RemoveAllMapSearchPaths(this: this->m_pFileSystemPassThru);
}

//------------------------------------------------------------------------------
// Address: 0x100224F0
// Name: public: virtual void CFileSystemPassThru::SyncDvdDevCache(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFileSystemPassThru::SyncDvdDevCache(CFileSystemPassThru *this)
{
  this->m_pFileSystemPassThru->SyncDvdDevCache(this: this->m_pFileSystemPassThru);
}

//------------------------------------------------------------------------------
// Address: 0x10022500
// Name: public: virtual bool CFileSystemPassThru::GetStringFromKVPool(unsigned long,unsigned int,char __near *,int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CFileSystemPassThru::GetStringFromKVPool(
        CFileSystemPassThru *this,
        unsigned int poolKey,
        unsigned int key,
        char *pOutBuff,
        int buflen)
{
  return this->m_pFileSystemPassThru->GetStringFromKVPool(
           this: this->m_pFileSystemPassThru,
           a2: poolKey,
           a3: key,
           a4: pOutBuff,
           a5: buflen);
}

//------------------------------------------------------------------------------
// Address: 0x10022520
// Name: public: virtual bool CFileSystemPassThru::DiscoverDLC(int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CFileSystemPassThru::DiscoverDLC(CFileSystemPassThru *this, int iController)
{
  return this->m_pFileSystemPassThru->DiscoverDLC(this: this->m_pFileSystemPassThru, a2: iController);
}

//------------------------------------------------------------------------------
// Address: 0x10022540
// Name: public: virtual int CFileSystemPassThru::IsAnyDLCPresent(bool __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CFileSystemPassThru::IsAnyDLCPresent(CFileSystemPassThru *this, bool *pbDLCSearchPathMounted)
{
  return this->m_pFileSystemPassThru->IsAnyDLCPresent(this: this->m_pFileSystemPassThru, a2: pbDLCSearchPathMounted);
}

//------------------------------------------------------------------------------
// Address: 0x10022560
// Name: public: virtual bool CFileSystemPassThru::GetAnyDLCInfo(int,unsigned int __near *,wchar_t __near *,int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CFileSystemPassThru::GetAnyDLCInfo(
        CFileSystemPassThru *this,
        int iDLC,
        unsigned int *pLicenseMask,
        wchar_t *pTitleBuff,
        int nOutTitleSize)
{
  return this->m_pFileSystemPassThru->GetAnyDLCInfo(
           this: this->m_pFileSystemPassThru,
           a2: iDLC,
           a3: pLicenseMask,
           a4: pTitleBuff,
           a5: nOutTitleSize);
}

//------------------------------------------------------------------------------
// Address: 0x10022580
// Name: public: virtual int CFileSystemPassThru::IsAnyCorruptDLC(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CFileSystemPassThru::IsAnyCorruptDLC(CFileSystemPassThru *this)
{
  return this->m_pFileSystemPassThru->IsAnyCorruptDLC(this: this->m_pFileSystemPassThru);
}

//------------------------------------------------------------------------------
// Address: 0x10022590
// Name: public: virtual bool CFileSystemPassThru::GetAnyCorruptDLCInfo(int,wchar_t __near *,int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CFileSystemPassThru::GetAnyCorruptDLCInfo(
        CFileSystemPassThru *this,
        int iCorruptDLC,
        wchar_t *pTitleBuff,
        int nOutTitleSize)
{
  return this->m_pFileSystemPassThru->GetAnyCorruptDLCInfo(
           this: this->m_pFileSystemPassThru,
           a2: iCorruptDLC,
           a3: pTitleBuff,
           a4: nOutTitleSize);
}

//------------------------------------------------------------------------------
// Address: 0x100225B0
// Name: public: virtual bool CFileSystemPassThru::AddDLCSearchPaths(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CFileSystemPassThru::AddDLCSearchPaths(CFileSystemPassThru *this)
{
  return this->m_pFileSystemPassThru->AddDLCSearchPaths(this: this->m_pFileSystemPassThru);
}

//------------------------------------------------------------------------------
// Address: 0x100225C0
// Name: public: virtual bool CFileSystemPassThru::IsSpecificDLCPresent(unsigned int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CFileSystemPassThru::IsSpecificDLCPresent(CFileSystemPassThru *this, unsigned int nDLCPackage)
{
  return this->m_pFileSystemPassThru->IsSpecificDLCPresent(this: this->m_pFileSystemPassThru, a2: nDLCPackage);
}

//------------------------------------------------------------------------------
// Address: 0x100225E0
// Name: public: virtual void CFileSystemPassThru::SetIODelayAlarm(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFileSystemPassThru::SetIODelayAlarm(CFileSystemPassThru *this, float flThreshhold)
{
  ((void (__stdcall *)(_DWORD))this->m_pFileSystemPassThru->SetIODelayAlarm)(a1: LODWORD(flThreshhold));
}

//------------------------------------------------------------------------------
// Address: 0x10022600
// Name: public: virtual bool CFileSystemPassThru::AddXLSPUpdateSearchPath(void const __near *,int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CFileSystemPassThru::AddXLSPUpdateSearchPath(CFileSystemPassThru *this, const void *pData, int nSize)
{
  return this->m_pFileSystemPassThru->AddXLSPUpdateSearchPath(this: this->m_pFileSystemPassThru, a2: pData, a3: nSize);
}

//------------------------------------------------------------------------------
// Address: 0x10022620
// Name: public: virtual class IIoStats __near * CFileSystemPassThru::GetIoStats(void)
// Source: json
//------------------------------------------------------------------------------
IIoStats *__thiscall CFileSystemPassThru::GetIoStats(CFileSystemPassThru *this)
{
  return this->m_pFileSystemPassThru->GetIoStats(this: this->m_pFileSystemPassThru);
}

//------------------------------------------------------------------------------
// Address: 0x10022660
// Name: public: virtual void CBaseVMPIFileSystem::Release(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseVMPIFileSystem::Release(CBaseVMPIFileSystem *this)
{
  if ( this != nullptr )
    ((void (__thiscall *)(CBaseVMPIFileSystem *, int))this->dtr_CBaseVMPIFileSystem)(a1: this, a2: 1);
}

//------------------------------------------------------------------------------
// Address: 0x10022680
// Name: public: virtual void CBaseVMPIFileSystem::Close(void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseVMPIFileSystem::Close(CBaseVMPIFileSystem *this, void (__thiscall ***file)(_DWORD))
{
  if ( file != nullptr )
    (**file)(a1: file);
}

//------------------------------------------------------------------------------
// Address: 0x100226A0
// Name: public: virtual int CBaseVMPIFileSystem::Read(void __near *,int,void __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBaseVMPIFileSystem::Read(CBaseVMPIFileSystem *this, void *pOutput, int size, void *file)
{
  return (*(int (__thiscall **)(void *, void *, int))(*(_DWORD *)file + 20))(a1: file, a2: pOutput, a3: size);
}

//------------------------------------------------------------------------------
// Address: 0x100226C0
// Name: public: virtual int CBaseVMPIFileSystem::Write(void const __near *,int,void __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBaseVMPIFileSystem::Write(CBaseVMPIFileSystem *this, const void *pInput, int size, void *file)
{
  return (*(int (__thiscall **)(void *, const void *, int))(*(_DWORD *)file + 24))(a1: file, a2: pInput, a3: size);
}

//------------------------------------------------------------------------------
// Address: 0x100226E0
// Name: public: virtual void CBaseVMPIFileSystem::Seek(void __near *,int,enum FileSystemSeek_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseVMPIFileSystem::Seek(CBaseVMPIFileSystem *this, void *file, int pos, FileSystemSeek_t seekType)
{
  (*(void (__thiscall **)(void *, int, FileSystemSeek_t))(*(_DWORD *)file + 4))(a1: file, a2: pos, a3: seekType);
}

//------------------------------------------------------------------------------
// Address: 0x10022700
// Name: public: virtual unsigned int CBaseVMPIFileSystem::Tell(void __near *)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CBaseVMPIFileSystem::Tell(CBaseVMPIFileSystem *this, void *file)
{
  return (*(unsigned int (__thiscall **)(void *))(*(_DWORD *)file + 8))(a1: file);
}

//------------------------------------------------------------------------------
// Address: 0x10022720
// Name: public: virtual unsigned int CBaseVMPIFileSystem::Size(void __near *)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CBaseVMPIFileSystem::Size(CBaseVMPIFileSystem *this, void *file)
{
  return (*(unsigned int (__thiscall **)(void *))(*(_DWORD *)file + 12))(a1: file);
}

//------------------------------------------------------------------------------
// Address: 0x10022740
// Name: public: virtual unsigned int CBaseVMPIFileSystem::Size(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBaseVMPIFileSystem::Size(CBaseVMPIFileSystem *this, const char *pFilename, const char *pathID)
{
  int result; // eax
  unsigned int v5; // edi
  int v6; // ebx

  result = ((int (__thiscall *)(CBaseVMPIFileSystem *, const char *, const char *, _DWORD))this->QueryInterface)(
             a1: this,
             a2: pFilename,
             a3: "rb",
             a4: 0);
  v5 = result;
  if ( result != 0 )
  {
    v6 = ((int (__thiscall *)(CBaseVMPIFileSystem *, int))this->Reconnect)(a1: this, a2: result);
    ((void (__thiscall *)(CBaseVMPIFileSystem *, unsigned int))this->Init)(a1: this, a2: v5);
    return v6;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10022790
// Name: public: virtual bool CBaseVMPIFileSystem::FileExists(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CBaseVMPIFileSystem::FileExists(CBaseVMPIFileSystem *this, const char *pFileName, const char *pPathID)
{
  int v4; // eax

  v4 = ((int (__thiscall *)(CBaseVMPIFileSystem *, const char *, const char *, _DWORD))this->QueryInterface)(
         a1: this,
         a2: pFileName,
         a3: "rb",
         a4: 0);
  if ( v4 == 0 )
    return 0;
  ((void (__thiscall *)(CBaseVMPIFileSystem *, int))this->Init)(a1: this, a2: v4);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100227D0
// Name: public: virtual void CBaseVMPIFileSystem::Flush(void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseVMPIFileSystem::Flush(CBaseVMPIFileSystem *this, void *file)
{
  (*(void (__thiscall **)(void *))(*(_DWORD *)file + 16))(a1: file);
}

//------------------------------------------------------------------------------
// Address: 0x100227F0
// Name: public: virtual bool CBaseVMPIFileSystem::Precache(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CBaseVMPIFileSystem::Precache(CBaseVMPIFileSystem *this, const char *pFileName, const char *pPathID)
{
  return false;
}

//------------------------------------------------------------------------------
// Address: 0x10022810
// Name: public: virtual void __near * CInternalFileSystemPassThru<class IFileSystem>::Open(char const __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void *__thiscall CInternalFileSystemPassThru<IFileSystem>::Open(
        CInternalFileSystemPassThru<IFileSystem> *this,
        const char *pFileName,
        const char *pOptions,
        const char *pathID)
{
  return (*((void *(__thiscall **)(IBaseFileSystem_vtbl *, const char *, const char *, const char *))this->Read + 2))(
           a1: this->IFileSystem::IBaseFileSystem::__vftable,
           a2: pFileName,
           a3: pOptions,
           a4: pathID);
}

//------------------------------------------------------------------------------
// Address: 0x10022820
// Name: public: virtual bool CInternalFileSystemPassThru<class IFileSystem>::IsFileWritable(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CInternalFileSystemPassThru<IFileSystem>::IsFileWritable(
        CInternalFileSystemPassThru<IFileSystem> *this,
        const char *pFileName,
        const char *pPathID)
{
  return (*((bool (__thiscall **)(IBaseFileSystem_vtbl *, const char *, const char *))this->Read + 11))(
           a1: this->IFileSystem::IBaseFileSystem::__vftable,
           a2: pFileName,
           a3: pPathID);
}

//------------------------------------------------------------------------------
// Address: 0x10022830
// Name: public: virtual bool CInternalFileSystemPassThru<class IFileSystem>::SetFileWritable(char const __near *,bool,char const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __userpurge CInternalFileSystemPassThru<IFileSystem>::SetFileWritable@<al>(
        CInternalFileSystemPassThru<IFileSystem> *this@<ecx>,
        const char *pFileName,
        bool writable,
        const char *pPathID)
{
  return (*((bool (__thiscall **)(IBaseFileSystem_vtbl *, const char *))this->Read + 12))(
           a1: this->IFileSystem::IBaseFileSystem::__vftable,
           a2: pFileName);
}

//------------------------------------------------------------------------------
// Address: 0x10022840
// Name: public: virtual long CInternalFileSystemPassThru<class IFileSystem>::GetFileTime(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CInternalFileSystemPassThru<IFileSystem>::GetFileTime(
        CInternalFileSystemPassThru<IFileSystem> *this,
        const char *pFileName,
        const char *pPathID)
{
  return (*((int (__thiscall **)(IBaseFileSystem_vtbl *, const char *, const char *))this->Read + 13))(
           a1: this->IFileSystem::IBaseFileSystem::__vftable,
           a2: pFileName,
           a3: pPathID);
}

//------------------------------------------------------------------------------
// Address: 0x10022850
// Name: public: virtual bool CInternalFileSystemPassThru<class IFileSystem>::UnzipFile(char const __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CInternalFileSystemPassThru<IFileSystem>::UnzipFile(
        CInternalFileSystemPassThru<IFileSystem> *this,
        const char *pFileName,
        const char *pPath,
        const char *pDestination)
{
  return (*((bool (__thiscall **)(IBaseFileSystem_vtbl *, const char *, const char *, const char *))this->Read + 16))(
           a1: this->IFileSystem::IBaseFileSystem::__vftable,
           a2: pFileName,
           a3: pPath,
           a4: pDestination);
}

//------------------------------------------------------------------------------
// Address: 0x10022860
// Name: public: virtual void CFileSystemPassThru::InitPassThru(class IFileSystem __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFileSystemPassThru::InitPassThru(
        CFileSystemPassThru *this,
        IFileSystem *pFileSystemPassThru,
        bool bBaseOnly)
{
  if ( !bBaseOnly )
    this->m_pFileSystemPassThru = pFileSystemPassThru;
  if ( pFileSystemPassThru != nullptr )
    this->m_pBaseFileSystemPassThru = &pFileSystemPassThru->IBaseFileSystem;
  else
    this->m_pBaseFileSystemPassThru = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10022890
// Name: public: virtual bool CBaseVMPIFileSystem::ReadFile(char const __near *,char const __near *,class CUtlBuffer __near &,int,int,void __near * (*)(char const __near *,unsigned int))
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CBaseVMPIFileSystem::ReadFile(
        CBaseVMPIFileSystem *this,
        const char *pFileName,
        const char *pPath,
        CUtlBuffer *buf,
        int nMaxBytes,
        int nStartingByte,
        void *(__cdecl *pfnAlloc)(const char *, unsigned int))
{
  const char *v9; // eax
  int v10; // ebx
  int v12; // eax
  int nBytesRead; // [esp+1Ch] [ebp+10h]
  int nBytesReada; // [esp+1Ch] [ebp+10h]

  v9 = "rt";
  if ( (buf->m_Flags & 1) == 0 )
    v9 = "rb";
  v10 = ((int (__thiscall *)(CBaseVMPIFileSystem *, const char *, const char *, const char *))this->QueryInterface)(
          a1: this,
          a2: pFileName,
          a3: v9,
          a4: pPath);
  if ( v10 == 0 )
    return false;
  v12 = ((int (__thiscall *)(CBaseVMPIFileSystem *, int))this->Reconnect)(a1: this, a2: v10);
  nBytesRead = v12;
  if ( nMaxBytes > 0 && nMaxBytes < v12 )
  {
    nBytesRead = nMaxBytes;
    v12 = nMaxBytes;
  }
  CUtlBuffer::EnsureCapacity(this: buf, num: v12 + buf->m_Put);
  if ( nStartingByte != 0 )
    ((void (__thiscall *)(CBaseVMPIFileSystem *, int, int, _DWORD))this->Shutdown)(
      a1: this,
      a2: v10,
      a3: nStartingByte,
      a4: 0);
  nBytesReada = ((int (__thiscall *)(CBaseVMPIFileSystem *, unsigned __int8 *, int, int))this->Connect)(
                  a1: this,
                  a2: &buf->m_Memory.m_pMemory[buf->m_Put - buf->m_nOffset],
                  a3: nBytesRead,
                  a4: v10);
  CUtlBuffer::SeekPut(this: buf, type: SEEK_CURRENT, offset: nBytesReada);
  ((void (__thiscall *)(CBaseVMPIFileSystem *, int))this->Init)(a1: this, a2: v10);
  return nBytesReada != 0;
}

//------------------------------------------------------------------------------
// Address: 0x10022950
// Name: public: virtual bool CBaseVMPIFileSystem::WriteFile(char const __near *,char const __near *,class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CBaseVMPIFileSystem::WriteFile(
        CBaseVMPIFileSystem *this,
        const char *pFileName,
        const char *pPath,
        CUtlBuffer *buf)
{
  const char *v5; // eax
  int v6; // edi
  int v8; // ebx

  v5 = "wt";
  if ( (buf->m_Flags & 1) == 0 )
    v5 = "wb";
  v6 = ((int (__thiscall *)(CBaseVMPIFileSystem *, const char *, const char *, const char *))this->QueryInterface)(
         a1: this,
         a2: pFileName,
         a3: v5,
         a4: pPath);
  if ( v6 == 0 )
    return false;
  v8 = ((int (__thiscall *)(CBaseVMPIFileSystem *, unsigned __int8 *, int, int))this->Disconnect)(
         a1: this,
         a2: buf->m_Memory.m_pMemory,
         a3: buf->m_nMaxPut,
         a4: v6);
  ((void (__thiscall *)(CBaseVMPIFileSystem *, int))this->Init)(a1: this, a2: v6);
  return v8 != 0;
}

// ============================================================
// Overlay from texturecompile_dll (Missing functions)
// ============================================================
namespace texturecompile_dll {

//------------------------------------------------------------------------------
// Address: 0x1000B870
// Name: void __near * GetVMPIFileSystem(void)
// Source: json
//------------------------------------------------------------------------------
IBaseFileSystem *__cdecl GetVMPIFileSystem()
{
  if ( g_pBaseVMPIFileSystem != nullptr )
    return &g_pBaseVMPIFileSystem->IBaseFileSystem;
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1000B880
// Name: void __near * GetFullFileSystem(void)
// Source: json
//------------------------------------------------------------------------------
IFileSystem *__cdecl GetFullFileSystem()
{
  return g_pOriginalPassThruFileSystem;
}

//------------------------------------------------------------------------------
// Address: 0x1000B890
// Name: class IFileSystem __near * VMPI_FileSystem_Init(int,class IFileSystem __near *)
// Source: json
//------------------------------------------------------------------------------
CBaseVMPIFileSystem *__cdecl VMPI_FileSystem_Init(unsigned int maxMemoryUsage, IFileSystem *pPassThru)
{
  g_pOriginalPassThruFileSystem = pPassThru;
  if ( g_bMPIMaster )
    CreateMasterVMPIFileSystem(maxMemoryUsage, pPassThru);
  else
    CreateWorkerVMPIFileSystem();
  return g_pBaseVMPIFileSystem;
}

//------------------------------------------------------------------------------
// Address: 0x1000B8D0
// Name: class IFileSystem __near * VMPI_FileSystem_Term(void)
// Source: json
//------------------------------------------------------------------------------
IFileSystem *__cdecl VMPI_FileSystem_Term()
{
  IFileSystem *result; // eax

  if ( g_pBaseVMPIFileSystem != nullptr )
  {
    g_pBaseVMPIFileSystem->Release(this: g_pBaseVMPIFileSystem);
    g_pBaseVMPIFileSystem = nullptr;
    if ( g_iVMPIVerboseLevel >= 1 )
    {
      if ( g_bMPIMaster )
        _Msg(a1: "Multicast send: %dk\n", (g_nMulticastBytesSent + 511) / 1024);
      else
        _Msg(a1: "Multicast recv: %dk\n", (g_nMulticastBytesReceived + 511) / 1024);
    }
  }
  result = g_pOriginalPassThruFileSystem;
  g_pOriginalPassThruFileSystem = nullptr;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1000B960
// Name: bool FileSystemRecv(class MessageBuffer __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl FileSystemRecv(MessageBuffer *pBuf, int iSource, int iPacketID)
{
  return g_pBaseVMPIFileSystem != nullptr
      && g_pBaseVMPIFileSystem->HandleFileSystemPacket(
           this: g_pBaseVMPIFileSystem,
           a2: pBuf,
           a3: iSource,
           a4: iPacketID);
}

//------------------------------------------------------------------------------
// Address: 0x1000B990
// Name: public: void CVMPIFile_Memory::Init(char const __near *,long,char)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVMPIFile_Memory::Init(CVMPIFile_Memory *this, const char *pData, int len, char chMode)
{
  this->m_pData = pData;
  this->m_DataLen = len;
  this->m_iCurPos = 0;
  this->m_chMode = chMode;
}

//------------------------------------------------------------------------------
// Address: 0x1000B9B0
// Name: public: virtual void CVMPIFile_Memory::Seek(int,enum FileSystemSeek_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVMPIFile_Memory::Seek(CVMPIFile_Memory *this, int pos, FileSystemSeek_t seekType)
{
  if ( seekType != FILESYSTEM_SEEK_HEAD )
  {
    if ( seekType == FILESYSTEM_SEEK_CURRENT )
      this->m_iCurPos += pos;
    else
      this->m_iCurPos = this->m_DataLen - pos;
  }
  else
  {
    this->m_iCurPos = pos;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000B9E0
// Name: public: virtual int CVMPIFile_Memory::Read(void __near *,int)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CVMPIFile_Memory::Read(CVMPIFile_Memory *this, unsigned __int8 *pOutput, int size)
{
  int m_iCurPos; // ecx
  unsigned int v5; // esi
  signed int v6; // eax
  signed int v8; // edi
  unsigned __int8 *v9; // esi
  int v10; // eax
  unsigned int v11; // edi
  int v12; // eax
  unsigned __int8 *v13; // ecx
  int v14; // eax
  int iRead; // [esp+8h] [ebp-8h]
  int len; // [esp+Ch] [ebp-4h]
  int lena; // [esp+Ch] [ebp-4h]

  m_iCurPos = this->m_iCurPos;
  v5 = size;
  v6 = this->m_DataLen - m_iCurPos;
  if ( v6 < size )
    v5 = this->m_DataLen - m_iCurPos;
  if ( this->m_chMode == 116 )
  {
    v8 = this->m_DataLen - m_iCurPos;
    v9 = (unsigned __int8 *)&this->m_pData[m_iCurPos];
    iRead = 0;
    len = v8;
    memchr(buf: v9, chr: 0xDu, cnt: v6);
    if ( v10 != 0 )
    {
      while ( 1 )
      {
        v11 = size;
        v12 = v10 - (_DWORD)v9;
        if ( size >= v12 )
          v11 = v12;
        memcpy(dst: pOutput, src: v9, count: v11);
        this->m_iCurPos += v11;
        lena = len - v11;
        iRead += v11;
        v9 += v11;
        v13 = &pOutput[v11];
        size -= v11;
        if ( size == 0 )
          break;
        if ( lena == 0 )
        {
          v8 = 0;
          goto LABEL_16;
        }
        v14 = lena;
        if ( lena > 1 && v9[1] == 10 )
        {
          ++v9;
          ++this->m_iCurPos;
          v14 = lena - 1;
        }
        ++iRead;
        --size;
        *v13 = *v9;
        ++this->m_iCurPos;
        ++v9;
        len = v14 - 1;
        pOutput = v13 + 1;
        memchr(buf: v9, chr: 0xDu, cnt: v14 - 1);
        if ( v10 == 0 )
        {
          v8 = len;
          goto LABEL_15;
        }
      }
    }
    else
    {
LABEL_15:
      v13 = pOutput;
LABEL_16:
      if ( size != 0 && v8 != 0 )
      {
        if ( size < v8 )
          v8 = size;
        memcpy(dst: v13, src: v9, count: v8);
        this->m_iCurPos += v8;
        iRead += v8;
      }
    }
    return iRead;
  }
  else
  {
    memcpy(dst: pOutput, src: (unsigned __int8 *)&this->m_pData[m_iCurPos], count: v5);
    this->m_iCurPos += v5;
    return v5;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000BB00
// Name: public: virtual int CVMPIFile_Memory::Write(void const __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CVMPIFile_Memory::Write(CVMPIFile_Memory *this, const void *pInput, const void *size)
{
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1000BB10
// Name: public: virtual CBaseVMPIFileSystem::~CBaseVMPIFileSystem(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseVMPIFileSystem::~CBaseVMPIFileSystem(CBaseVMPIFileSystem *this)
{
  this->CFileSystemPassThru::CInternalFileSystemPassThru<IFileSystem>::IFileSystem::IAppSystem::__vftable = (CBaseVMPIFileSystem_vtbl *)&CBaseVMPIFileSystem::`vftable'{for `IAppSystem'};
  this->CFileSystemPassThru::CInternalFileSystemPassThru<IFileSystem>::IFileSystem::IBaseFileSystem::__vftable = (IBaseFileSystem_vtbl *)&CBaseVMPIFileSystem::`vftable'{for `IBaseFileSystem'};
}

//------------------------------------------------------------------------------
// Address: 0x1000BB20
// Name: public: virtual bool CFileSystemPassThru::Connect(void __near * (*)(char const __near *,int __near *))
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CFileSystemPassThru::Connect(CFileSystemPassThru *this, void *(__cdecl *factory)(const char *, int *))
{
  return this->m_pFileSystemPassThru->Connect(this: this->m_pFileSystemPassThru, a2: factory);
}

//------------------------------------------------------------------------------
// Address: 0x1000BB30
// Name: public: virtual void CFileSystemPassThru::Disconnect(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFileSystemPassThru::Disconnect(CFileSystemPassThru *this)
{
  this->m_pFileSystemPassThru->Disconnect(this: this->m_pFileSystemPassThru);
}

//------------------------------------------------------------------------------
// Address: 0x1000BB40
// Name: public: virtual void __near * CFileSystemPassThru::QueryInterface(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void *__thiscall CFileSystemPassThru::QueryInterface(CFileSystemPassThru *this, const char *pInterfaceName)
{
  return this->m_pFileSystemPassThru->QueryInterface(this: this->m_pFileSystemPassThru, a2: pInterfaceName);
}

//------------------------------------------------------------------------------
// Address: 0x1000BB50
// Name: public: virtual enum InitReturnVal_t CFileSystemPassThru::Init(void)
// Source: json
//------------------------------------------------------------------------------
InitReturnVal_t __thiscall CFileSystemPassThru::Init(CFileSystemPassThru *this)
{
  return this->m_pFileSystemPassThru->Init(this: this->m_pFileSystemPassThru);
}

//------------------------------------------------------------------------------
// Address: 0x1000BB60
// Name: public: virtual void CFileSystemPassThru::Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFileSystemPassThru::Shutdown(CFileSystemPassThru *this)
{
  this->m_pFileSystemPassThru->Shutdown(this: this->m_pFileSystemPassThru);
}

//------------------------------------------------------------------------------
// Address: 0x1000BB70
// Name: public: virtual struct AppSystemInfo_t const __near * CFileSystemPassThru::GetDependencies(void)
// Source: json
//------------------------------------------------------------------------------
const AppSystemInfo_t *__thiscall CFileSystemPassThru::GetDependencies(CFileSystemPassThru *this)
{
  return this->m_pFileSystemPassThru->GetDependencies(this: this->m_pFileSystemPassThru);
}

//------------------------------------------------------------------------------
// Address: 0x1000BB80
// Name: public: virtual enum AppSystemTier_t CFileSystemPassThru::GetTier(void)
// Source: json
//------------------------------------------------------------------------------
AppSystemTier_t __thiscall CFileSystemPassThru::GetTier(CFileSystemPassThru *this)
{
  return this->m_pFileSystemPassThru->GetTier(this: this->m_pFileSystemPassThru);
}

//------------------------------------------------------------------------------
// Address: 0x1000BB90
// Name: public: virtual void CFileSystemPassThru::Reconnect(void __near * (*)(char const __near *,int __near *),char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFileSystemPassThru::Reconnect(
        CFileSystemPassThru *this,
        void *(__cdecl *factory)(const char *, int *),
        const char *pInterfaceName)
{
  this->m_pFileSystemPassThru->Reconnect(this: this->m_pFileSystemPassThru, a2: factory, a3: pInterfaceName);
}

//------------------------------------------------------------------------------
// Address: 0x1000BBA0
// Name: public: virtual void CFileSystemPassThru::RemoveAllSearchPaths(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFileSystemPassThru::RemoveAllSearchPaths(CFileSystemPassThru *this)
{
  this->m_pFileSystemPassThru->RemoveAllSearchPaths(this: this->m_pFileSystemPassThru);
}

//------------------------------------------------------------------------------
// Address: 0x1000BBB0
// Name: public: virtual void CFileSystemPassThru::AddSearchPath(char const __near *,char const __near *,enum SearchPathAdd_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFileSystemPassThru::AddSearchPath(
        CFileSystemPassThru *this,
        const char *pPath,
        const char *pathID,
        SearchPathAdd_t addType)
{
  this->m_pFileSystemPassThru->AddSearchPath(this: this->m_pFileSystemPassThru, a2: pPath, a3: pathID, a4: addType);
}

//------------------------------------------------------------------------------
// Address: 0x1000BBC0
// Name: public: virtual bool CFileSystemPassThru::RemoveSearchPath(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CFileSystemPassThru::RemoveSearchPath(CFileSystemPassThru *this, const char *pPath, const char *pathID)
{
  return this->m_pFileSystemPassThru->RemoveSearchPath(this: this->m_pFileSystemPassThru, a2: pPath, a3: pathID);
}

//------------------------------------------------------------------------------
// Address: 0x1000BBD0
// Name: public: virtual void CFileSystemPassThru::RemoveFile(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFileSystemPassThru::RemoveFile(
        CFileSystemPassThru *this,
        const char *pRelativePath,
        const char *pathID)
{
  this->m_pFileSystemPassThru->RemoveFile(this: this->m_pFileSystemPassThru, a2: pRelativePath, a3: pathID);
}

//------------------------------------------------------------------------------
// Address: 0x1000BBE0
// Name: public: virtual bool CFileSystemPassThru::RenameFile(char const __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CFileSystemPassThru::RenameFile(
        CFileSystemPassThru *this,
        const char *pOldPath,
        const char *pNewPath,
        const char *pathID)
{
  return this->m_pFileSystemPassThru->RenameFile(
           this: this->m_pFileSystemPassThru,
           a2: pOldPath,
           a3: pNewPath,
           a4: pathID);
}

//------------------------------------------------------------------------------
// Address: 0x1000BBF0
// Name: public: virtual void CFileSystemPassThru::CreateDirHierarchy(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFileSystemPassThru::CreateDirHierarchy(
        CFileSystemPassThru *this,
        const char *path,
        const char *pathID)
{
  this->m_pFileSystemPassThru->CreateDirHierarchy(this: this->m_pFileSystemPassThru, a2: path, a3: pathID);
}

//------------------------------------------------------------------------------
// Address: 0x1000BC00
// Name: public: virtual bool CFileSystemPassThru::IsDirectory(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CFileSystemPassThru::IsDirectory(CFileSystemPassThru *this, const char *pFileName, const char *pathID)
{
  return this->m_pFileSystemPassThru->IsDirectory(this: this->m_pFileSystemPassThru, a2: pFileName, a3: pathID);
}

//------------------------------------------------------------------------------
// Address: 0x1000BC10
// Name: public: virtual void CFileSystemPassThru::FileTimeToString(char __near *,int,long)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFileSystemPassThru::FileTimeToString(
        CFileSystemPassThru *this,
        char *pStrip,
        int maxCharsIncludingTerminator,
        int fileTime)
{
  this->m_pFileSystemPassThru->FileTimeToString(
    this: this->m_pFileSystemPassThru,
    a2: pStrip,
    a3: maxCharsIncludingTerminator,
    a4: fileTime);
}

//------------------------------------------------------------------------------
// Address: 0x1000BC20
// Name: public: virtual void CFileSystemPassThru::SetBufferSize(void __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFileSystemPassThru::SetBufferSize(CFileSystemPassThru *this, void *file, unsigned int nBytes)
{
  this->m_pFileSystemPassThru->SetBufferSize(this: this->m_pFileSystemPassThru, a2: file, a3: nBytes);
}

//------------------------------------------------------------------------------
// Address: 0x1000BC30
// Name: public: virtual bool CFileSystemPassThru::IsOk(void __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CFileSystemPassThru::IsOk(CFileSystemPassThru *this, void *file)
{
  return this->m_pFileSystemPassThru->IsOk(this: this->m_pFileSystemPassThru, a2: file);
}

//------------------------------------------------------------------------------
// Address: 0x1000BC40
// Name: public: virtual bool CFileSystemPassThru::EndOfFile(void __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CFileSystemPassThru::EndOfFile(CFileSystemPassThru *this, void *file)
{
  return this->m_pFileSystemPassThru->EndOfFile(this: this->m_pFileSystemPassThru, a2: file);
}

//------------------------------------------------------------------------------
// Address: 0x1000BC50
// Name: public: virtual char __near * CFileSystemPassThru::ReadLine(char __near *,int,void __near *)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CFileSystemPassThru::ReadLine(CFileSystemPassThru *this, char *pOutput, int maxChars, void *file)
{
  return this->m_pFileSystemPassThru->ReadLine(this: this->m_pFileSystemPassThru, a2: pOutput, a3: maxChars, a4: file);
}

//------------------------------------------------------------------------------
// Address: 0x1000BC60
// Name: public: virtual int CFileSystemPassThru::FPrintf(void __near *,char const __near *,...)
// Source: json
//------------------------------------------------------------------------------
int CFileSystemPassThru::FPrintf(CFileSystemPassThru *this, void *file, char *pFormat, ...)
{
  char string[8192]; // [esp+0h] [ebp-2000h] BYREF
  va_list ap; // [esp+2014h] [ebp+14h] BYREF

  va_start(ap, pFormat);
  _vsnprintf(string, count: 0x2000u, format: pFormat, ap);
  return this->m_pFileSystemPassThru->FPrintf(this: this->m_pFileSystemPassThru, a2: file, a3: "%s", string);
}

//------------------------------------------------------------------------------
// Address: 0x1000BCB0
// Name: public: virtual class CSysModule __near * CFileSystemPassThru::LoadModule(char const __near *,char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
struct CSysModule *__thiscall CFileSystemPassThru::LoadModule(
        CFileSystemPassThru *this,
        const char *pFileName,
        const char *pPathID,
        BOOL bValidatedDllOnly)
{
  return this->m_pFileSystemPassThru->LoadModule(
           this: this->m_pFileSystemPassThru,
           a2: pFileName,
           a3: pPathID,
           a4: bValidatedDllOnly);
}

//------------------------------------------------------------------------------
// Address: 0x1000BCC0
// Name: public: virtual void CFileSystemPassThru::UnloadModule(class CSysModule __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFileSystemPassThru::UnloadModule(CFileSystemPassThru *this, struct CSysModule *pModule)
{
  this->m_pFileSystemPassThru->UnloadModule(this: this->m_pFileSystemPassThru, a2: pModule);
}

//------------------------------------------------------------------------------
// Address: 0x1000BCD0
// Name: public: virtual char const __near * CFileSystemPassThru::FindFirst(char const __near *,int __near *)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CFileSystemPassThru::FindFirst(CFileSystemPassThru *this, const char *pWildCard, int *pHandle)
{
  return this->m_pFileSystemPassThru->FindFirst(this: this->m_pFileSystemPassThru, a2: pWildCard, a3: pHandle);
}

//------------------------------------------------------------------------------
// Address: 0x1000BCE0
// Name: public: virtual char const __near * CFileSystemPassThru::FindNext(int)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CFileSystemPassThru::FindNext(CFileSystemPassThru *this, int handle)
{
  return this->m_pFileSystemPassThru->FindNext(this: this->m_pFileSystemPassThru, a2: handle);
}

//------------------------------------------------------------------------------
// Address: 0x1000BCF0
// Name: public: virtual bool CFileSystemPassThru::FindIsDirectory(int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CFileSystemPassThru::FindIsDirectory(CFileSystemPassThru *this, int handle)
{
  return this->m_pFileSystemPassThru->FindIsDirectory(this: this->m_pFileSystemPassThru, a2: handle);
}

//------------------------------------------------------------------------------
// Address: 0x1000BD10
// Name: public: virtual void CFileSystemPassThru::FindClose(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFileSystemPassThru::FindClose(CFileSystemPassThru *this, int handle)
{
  this->m_pFileSystemPassThru->FindClose(this: this->m_pFileSystemPassThru, a2: handle);
}

//------------------------------------------------------------------------------
// Address: 0x1000BD30
// Name: public: virtual void CFileSystemPassThru::FindFileAbsoluteList(class CUtlVector<class CUtlString,class CUtlMemory<class CUtlString,int>> __near &,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFileSystemPassThru::FindFileAbsoluteList(
        CFileSystemPassThru *this,
        CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *outAbsolutePathNames,
        const char *pWildCard,
        const char *pPathID)
{
  this->m_pFileSystemPassThru->FindFileAbsoluteList(
    this: this->m_pFileSystemPassThru,
    a2: outAbsolutePathNames,
    a3: pWildCard,
    a4: pPathID);
}

//------------------------------------------------------------------------------
// Address: 0x1000BD50
// Name: public: virtual char const __near * CFileSystemPassThru::GetLocalPath(char const __near *,char __near *,int)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CFileSystemPassThru::GetLocalPath(
        CFileSystemPassThru *this,
        const char *pFileName,
        char *pLocalPath,
        int localPathBufferSize)
{
  return this->m_pFileSystemPassThru->GetLocalPath(
           this: this->m_pFileSystemPassThru,
           a2: pFileName,
           a3: pLocalPath,
           a4: localPathBufferSize);
}

//------------------------------------------------------------------------------
// Address: 0x1000BD70
// Name: public: virtual bool CFileSystemPassThru::FullPathToRelativePath(char const __near *,char __near *,int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CFileSystemPassThru::FullPathToRelativePath(
        CFileSystemPassThru *this,
        const char *pFullpath,
        char *pRelative,
        int maxlen)
{
  return this->m_pFileSystemPassThru->FullPathToRelativePath(
           this: this->m_pFileSystemPassThru,
           a2: pFullpath,
           a3: pRelative,
           a4: maxlen);
}

//------------------------------------------------------------------------------
// Address: 0x1000BD90
// Name: public: virtual bool CFileSystemPassThru::GetCurrentDirectory(char __near *,int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CFileSystemPassThru::GetCurrentDirectory(CFileSystemPassThru *this, char *pDirectory, int maxlen)
{
  return this->m_pFileSystemPassThru->GetCurrentDirectoryA(
           this: this->m_pFileSystemPassThru,
           a2: pDirectory,
           a3: maxlen);
}

//------------------------------------------------------------------------------
// Address: 0x1000BDB0
// Name: public: virtual void CFileSystemPassThru::PrintOpenedFiles(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFileSystemPassThru::PrintOpenedFiles(CFileSystemPassThru *this)
{
  this->m_pFileSystemPassThru->PrintOpenedFiles(this: this->m_pFileSystemPassThru);
}

//------------------------------------------------------------------------------
// Address: 0x1000BDC0
// Name: public: virtual void CFileSystemPassThru::PrintSearchPaths(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFileSystemPassThru::PrintSearchPaths(CFileSystemPassThru *this)
{
  this->m_pFileSystemPassThru->PrintSearchPaths(this: this->m_pFileSystemPassThru);
}

//------------------------------------------------------------------------------
// Address: 0x1000BDD0
// Name: public: virtual void CFileSystemPassThru::SetWarningFunc(void (*)(char const __near *,...))
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFileSystemPassThru::SetWarningFunc(CFileSystemPassThru *this, void (*pfnWarning)(const char *, ...))
{
  this->m_pFileSystemPassThru->SetWarningFunc(this: this->m_pFileSystemPassThru, a2: pfnWarning);
}

//------------------------------------------------------------------------------
// Address: 0x1000BDF0
// Name: public: virtual void CFileSystemPassThru::SetWarningLevel(enum FileWarningLevel_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFileSystemPassThru::SetWarningLevel(CFileSystemPassThru *this, FileWarningLevel_t level)
{
  this->m_pFileSystemPassThru->SetWarningLevel(this: this->m_pFileSystemPassThru, a2: level);
}

//------------------------------------------------------------------------------
// Address: 0x1000BE10
// Name: public: virtual void CFileSystemPassThru::AddLoggingFunc(void (*)(char const __near *,char const __near *))
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFileSystemPassThru::AddLoggingFunc(
        CFileSystemPassThru *this,
        void (__cdecl *pfnLogFunc)(const char *, const char *))
{
  this->m_pFileSystemPassThru->AddLoggingFunc(this: this->m_pFileSystemPassThru, a2: pfnLogFunc);
}

//------------------------------------------------------------------------------
// Address: 0x1000BE30
// Name: public: virtual void CFileSystemPassThru::RemoveLoggingFunc(void (*)(char const __near *,char const __near *))
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFileSystemPassThru::RemoveLoggingFunc(
        CFileSystemPassThru *this,
        void (__cdecl *logFunc)(const char *, const char *))
{
  this->m_pFileSystemPassThru->RemoveLoggingFunc(this: this->m_pFileSystemPassThru, a2: logFunc);
}

//------------------------------------------------------------------------------
// Address: 0x1000BE50
// Name: public: virtual enum FSAsyncStatus_t CFileSystemPassThru::AsyncReadMultiple(struct FileAsyncRequest_t const __near *,int,struct FSAsyncControl_t__ __near * __near *)
// Source: json
//------------------------------------------------------------------------------
FSAsyncStatus_t __thiscall CFileSystemPassThru::AsyncReadMultiple(
        CFileSystemPassThru *this,
        const FileAsyncRequest_t *pRequests,
        int nRequests,
        FSAsyncControl_t__ **pControls)
{
  return this->m_pFileSystemPassThru->AsyncReadMultiple(
           this: this->m_pFileSystemPassThru,
           a2: pRequests,
           a3: nRequests,
           a4: pControls);
}

//------------------------------------------------------------------------------
// Address: 0x1000BE70
// Name: public: virtual enum FSAsyncStatus_t CFileSystemPassThru::AsyncReadMultipleCreditAlloc(struct FileAsyncRequest_t const __near *,int,char const __near *,int,struct FSAsyncControl_t__ __near * __near *)
// Source: json
//------------------------------------------------------------------------------
FSAsyncStatus_t __thiscall CFileSystemPassThru::AsyncReadMultipleCreditAlloc(
        CFileSystemPassThru *this,
        const FileAsyncRequest_t *pRequests,
        int nRequests,
        const char *pszFile,
        int line,
        FSAsyncControl_t__ **pControls)
{
  return this->m_pFileSystemPassThru->AsyncReadMultipleCreditAlloc(
           this: this->m_pFileSystemPassThru,
           a2: pRequests,
           a3: nRequests,
           a4: pszFile,
           a5: line,
           a6: pControls);
}

//------------------------------------------------------------------------------
// Address: 0x1000BE90
// Name: public: virtual enum FSAsyncStatus_t CFileSystemPassThru::AsyncDirectoryScan(char const __near *,bool,void __near *,void (*)(void __near *,char __near *,char __near *),void (*)(void __near *,enum FSAsyncStatus_t),struct FSAsyncControl_t__ __near * __near *)
// Source: json
//------------------------------------------------------------------------------
FSAsyncStatus_t __thiscall CFileSystemPassThru::AsyncDirectoryScan(
        CFileSystemPassThru *this,
        const char *pSearchSpec,
        BOOL recurseFolders,
        void *pContext,
        void (__cdecl *pfnAdd)(void *, char *, char *),
        void (__cdecl *pfnDone)(void *, FSAsyncStatus_t),
        FSAsyncControl_t__ **pControl)
{
  return this->m_pFileSystemPassThru->AsyncDirectoryScan(
           this: this->m_pFileSystemPassThru,
           a2: pSearchSpec,
           a3: recurseFolders,
           a4: pContext,
           a5: pfnAdd,
           a6: pfnDone,
           a7: pControl);
}

//------------------------------------------------------------------------------
// Address: 0x1000BEB0
// Name: public: virtual enum FSAsyncStatus_t CFileSystemPassThru::AsyncFinish(struct FSAsyncControl_t__ __near *,bool)
// Source: json
//------------------------------------------------------------------------------
FSAsyncStatus_t __thiscall CFileSystemPassThru::AsyncFinish(
        CFileSystemPassThru *this,
        FSAsyncControl_t__ *hControl,
        BOOL wait)
{
  return this->m_pFileSystemPassThru->AsyncFinish(this: this->m_pFileSystemPassThru, a2: hControl, a3: wait);
}

//------------------------------------------------------------------------------
// Address: 0x1000BED0
// Name: public: virtual enum FSAsyncStatus_t CFileSystemPassThru::AsyncGetResult(struct FSAsyncControl_t__ __near *,void __near * __near *,int __near *)
// Source: json
//------------------------------------------------------------------------------
FSAsyncStatus_t __thiscall CFileSystemPassThru::AsyncGetResult(
        CFileSystemPassThru *this,
        FSAsyncControl_t__ *hControl,
        void **ppData,
        int *pSize)
{
  return this->m_pFileSystemPassThru->AsyncGetResult(
           this: this->m_pFileSystemPassThru,
           a2: hControl,
           a3: ppData,
           a4: pSize);
}

//------------------------------------------------------------------------------
// Address: 0x1000BEF0
// Name: public: virtual enum FSAsyncStatus_t CFileSystemPassThru::AsyncAbort(struct FSAsyncControl_t__ __near *)
// Source: json
//------------------------------------------------------------------------------
FSAsyncStatus_t __thiscall CFileSystemPassThru::AsyncAbort(CFileSystemPassThru *this, FSAsyncControl_t__ *hControl)
{
  return this->m_pFileSystemPassThru->AsyncAbort(this: this->m_pFileSystemPassThru, a2: hControl);
}

//------------------------------------------------------------------------------
// Address: 0x1000BF10
// Name: public: virtual enum FSAsyncStatus_t CFileSystemPassThru::AsyncStatus(struct FSAsyncControl_t__ __near *)
// Source: json
//------------------------------------------------------------------------------
FSAsyncStatus_t __thiscall CFileSystemPassThru::AsyncStatus(CFileSystemPassThru *this, FSAsyncControl_t__ *hControl)
{
  return this->m_pFileSystemPassThru->AsyncStatus(this: this->m_pFileSystemPassThru, a2: hControl);
}

//------------------------------------------------------------------------------
// Address: 0x1000BF30
// Name: public: virtual enum FSAsyncStatus_t CFileSystemPassThru::AsyncFlush(void)
// Source: json
//------------------------------------------------------------------------------
FSAsyncStatus_t __thiscall CFileSystemPassThru::AsyncFlush(CFileSystemPassThru *this)
{
  return this->m_pFileSystemPassThru->AsyncFlush(this: this->m_pFileSystemPassThru);
}

//------------------------------------------------------------------------------
// Address: 0x1000BF40
// Name: public: virtual void CFileSystemPassThru::AsyncAddRef(struct FSAsyncControl_t__ __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFileSystemPassThru::AsyncAddRef(CFileSystemPassThru *this, FSAsyncControl_t__ *hControl)
{
  this->m_pFileSystemPassThru->AsyncAddRef(this: this->m_pFileSystemPassThru, a2: hControl);
}

//------------------------------------------------------------------------------
// Address: 0x1000BF60
// Name: public: virtual void CFileSystemPassThru::AsyncRelease(struct FSAsyncControl_t__ __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFileSystemPassThru::AsyncRelease(CFileSystemPassThru *this, FSAsyncControl_t__ *hControl)
{
  this->m_pFileSystemPassThru->AsyncRelease(this: this->m_pFileSystemPassThru, a2: hControl);
}

//------------------------------------------------------------------------------
// Address: 0x1000BF80
// Name: public: virtual enum FSAsyncStatus_t CFileSystemPassThru::AsyncBeginRead(char const __near *,struct FSAsyncFile_t__ __near * __near *)
// Source: json
//------------------------------------------------------------------------------
FSAsyncStatus_t __thiscall CFileSystemPassThru::AsyncBeginRead(
        CFileSystemPassThru *this,
        const char *pszFile,
        FSAsyncFile_t__ **phFile)
{
  return this->m_pFileSystemPassThru->AsyncBeginRead(this: this->m_pFileSystemPassThru, a2: pszFile, a3: phFile);
}

//------------------------------------------------------------------------------
// Address: 0x1000BFA0
// Name: public: virtual enum FSAsyncStatus_t CFileSystemPassThru::AsyncEndRead(struct FSAsyncFile_t__ __near *)
// Source: json
//------------------------------------------------------------------------------
FSAsyncStatus_t __thiscall CFileSystemPassThru::AsyncEndRead(CFileSystemPassThru *this, FSAsyncFile_t__ *hFile)
{
  return this->m_pFileSystemPassThru->AsyncEndRead(this: this->m_pFileSystemPassThru, a2: hFile);
}

//------------------------------------------------------------------------------
// Address: 0x1000BFC0
// Name: public: virtual struct FileSystemStatistics const __near * CFileSystemPassThru::GetFilesystemStatistics(void)
// Source: json
//------------------------------------------------------------------------------
const FileSystemStatistics *__thiscall CFileSystemPassThru::GetFilesystemStatistics(CFileSystemPassThru *this)
{
  return this->m_pFileSystemPassThru->GetFilesystemStatistics(this: this->m_pFileSystemPassThru);
}

//------------------------------------------------------------------------------
// Address: 0x1000BFD0
// Name: public: virtual int CFileSystemPassThru::WaitForResources(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CFileSystemPassThru::WaitForResources(CFileSystemPassThru *this, const char *resourcelist)
{
  return this->m_pFileSystemPassThru->WaitForResources(this: this->m_pFileSystemPassThru, a2: resourcelist);
}

//------------------------------------------------------------------------------
// Address: 0x1000BFF0
// Name: public: virtual bool CFileSystemPassThru::GetWaitForResourcesProgress(int,float __near *,bool __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CFileSystemPassThru::GetWaitForResourcesProgress(
        CFileSystemPassThru *this,
        int handle,
        float *progress,
        bool *complete)
{
  return this->m_pFileSystemPassThru->GetWaitForResourcesProgress(
           this: this->m_pFileSystemPassThru,
           a2: handle,
           a3: progress,
           a4: complete);
}

//------------------------------------------------------------------------------
// Address: 0x1000C010
// Name: public: virtual void CFileSystemPassThru::CancelWaitForResources(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFileSystemPassThru::CancelWaitForResources(CFileSystemPassThru *this, int handle)
{
  this->m_pFileSystemPassThru->CancelWaitForResources(this: this->m_pFileSystemPassThru, a2: handle);
}

//------------------------------------------------------------------------------
// Address: 0x1000C030
// Name: public: virtual int CFileSystemPassThru::HintResourceNeed(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CFileSystemPassThru::HintResourceNeed(
        CFileSystemPassThru *this,
        const char *hintlist,
        int forgetEverything)
{
  return this->m_pFileSystemPassThru->HintResourceNeed(
           this: this->m_pFileSystemPassThru,
           a2: hintlist,
           a3: forgetEverything);
}

//------------------------------------------------------------------------------
// Address: 0x1000C050
// Name: public: virtual bool CFileSystemPassThru::IsFileImmediatelyAvailable(char const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CFileSystemPassThru::IsFileImmediatelyAvailable(CFileSystemPassThru *this, const char *pFileName)
{
  return this->m_pFileSystemPassThru->IsFileImmediatelyAvailable(this: this->m_pFileSystemPassThru, a2: pFileName);
}

//------------------------------------------------------------------------------
// Address: 0x1000C070
// Name: public: virtual void CFileSystemPassThru::GetLocalCopy(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFileSystemPassThru::GetLocalCopy(CFileSystemPassThru *this, const char *pFileName)
{
  this->m_pFileSystemPassThru->GetLocalCopy(this: this->m_pFileSystemPassThru, a2: pFileName);
}

//------------------------------------------------------------------------------
// Address: 0x1000C090
// Name: public: virtual void __near * CFileSystemPassThru::FindOrAddFileName(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void *__thiscall CFileSystemPassThru::FindOrAddFileName(CFileSystemPassThru *this, const char *pFileName)
{
  return this->m_pFileSystemPassThru->FindOrAddFileName(this: this->m_pFileSystemPassThru, a2: pFileName);
}

//------------------------------------------------------------------------------
// Address: 0x1000C0B0
// Name: public: virtual void __near * CFileSystemPassThru::FindFileName(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void *__thiscall CFileSystemPassThru::FindFileName(CFileSystemPassThru *this, const char *pFileName)
{
  return this->m_pFileSystemPassThru->FindFileName(this: this->m_pFileSystemPassThru, a2: pFileName);
}

//------------------------------------------------------------------------------
// Address: 0x1000C0D0
// Name: public: virtual bool CFileSystemPassThru::String(void __near * const __near &,char __near *,int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CFileSystemPassThru::String(CFileSystemPassThru *this, void *const *handle, char *buf, int buflen)
{
  return this->m_pFileSystemPassThru->String(this: this->m_pFileSystemPassThru, a2: handle, a3: buf, a4: buflen);
}

//------------------------------------------------------------------------------
// Address: 0x1000C0F0
// Name: public: virtual bool CFileSystemPassThru::IsOk2(void __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CFileSystemPassThru::IsOk2(CFileSystemPassThru *this, void *file)
{
  return this->IsOk(this, a2: file);
}

//------------------------------------------------------------------------------
// Address: 0x1000C100
// Name: public: virtual void CFileSystemPassThru::RemoveSearchPaths(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFileSystemPassThru::RemoveSearchPaths(CFileSystemPassThru *this, const char *szPathID)
{
  this->m_pFileSystemPassThru->RemoveSearchPaths(this: this->m_pFileSystemPassThru, a2: szPathID);
}

//------------------------------------------------------------------------------
// Address: 0x1000C110
// Name: public: virtual bool CFileSystemPassThru::IsSteam(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CFileSystemPassThru::IsSteam(CFileSystemPassThru *this)
{
  return this->m_pFileSystemPassThru->IsSteam(this: this->m_pFileSystemPassThru);
}

//------------------------------------------------------------------------------
// Address: 0x1000C120
// Name: public: virtual enum FilesystemMountRetval_t CFileSystemPassThru::MountSteamContent(int)
// Source: json
//------------------------------------------------------------------------------
FilesystemMountRetval_t __thiscall CFileSystemPassThru::MountSteamContent(CFileSystemPassThru *this, int nExtraAppId)
{
  return this->m_pFileSystemPassThru->MountSteamContent(this: this->m_pFileSystemPassThru, a2: nExtraAppId);
}

//------------------------------------------------------------------------------
// Address: 0x1000C130
// Name: public: virtual char const __near * CFileSystemPassThru::FindFirstEx(char const __near *,char const __near *,int __near *)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CFileSystemPassThru::FindFirstEx(
        CFileSystemPassThru *this,
        const char *pWildCard,
        const char *pPathID,
        int *pHandle)
{
  return this->m_pFileSystemPassThru->FindFirstEx(
           this: this->m_pFileSystemPassThru,
           a2: pWildCard,
           a3: pPathID,
           a4: pHandle);
}

//------------------------------------------------------------------------------
// Address: 0x1000C150
// Name: public: virtual void CFileSystemPassThru::MarkPathIDByRequestOnly(char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFileSystemPassThru::MarkPathIDByRequestOnly(
        CFileSystemPassThru *this,
        const char *pPathID,
        BOOL bRequestOnly)
{
  this->m_pFileSystemPassThru->MarkPathIDByRequestOnly(this: this->m_pFileSystemPassThru, a2: pPathID, a3: bRequestOnly);
}

//------------------------------------------------------------------------------
// Address: 0x1000C160
// Name: public: virtual bool CFileSystemPassThru::AddPackFile(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CFileSystemPassThru::AddPackFile(CFileSystemPassThru *this, const char *fullpath, const char *pathID)
{
  return this->m_pFileSystemPassThru->AddPackFile(this: this->m_pFileSystemPassThru, a2: fullpath, a3: pathID);
}

//------------------------------------------------------------------------------
// Address: 0x1000C170
// Name: public: virtual enum FSAsyncStatus_t CFileSystemPassThru::AsyncAppend(char const __near *,void const __near *,int,bool,struct FSAsyncControl_t__ __near * __near *)
// Source: json
//------------------------------------------------------------------------------
FSAsyncStatus_t __thiscall CFileSystemPassThru::AsyncAppend(
        CFileSystemPassThru *this,
        const char *pFileName,
        const void *pSrc,
        int nSrcBytes,
        BOOL bFreeMemory,
        FSAsyncControl_t__ **pControl)
{
  return this->m_pFileSystemPassThru->AsyncAppend(
           this: this->m_pFileSystemPassThru,
           a2: pFileName,
           a3: pSrc,
           a4: nSrcBytes,
           a5: bFreeMemory,
           a6: pControl);
}

//------------------------------------------------------------------------------
// Address: 0x1000C190
// Name: public: virtual enum FSAsyncStatus_t CFileSystemPassThru::AsyncWrite(char const __near *,void const __near *,int,bool,bool,struct FSAsyncControl_t__ __near * __near *)
// Source: json
//------------------------------------------------------------------------------
FSAsyncStatus_t __thiscall CFileSystemPassThru::AsyncWrite(
        CFileSystemPassThru *this,
        const char *pFileName,
        const void *pSrc,
        int nSrcBytes,
        BOOL bFreeMemory,
        BOOL bAppend,
        FSAsyncControl_t__ **pControl)
{
  return this->m_pFileSystemPassThru->AsyncWrite(
           this: this->m_pFileSystemPassThru,
           a2: pFileName,
           a3: pSrc,
           a4: nSrcBytes,
           a5: bFreeMemory,
           a6: bAppend,
           a7: pControl);
}

//------------------------------------------------------------------------------
// Address: 0x1000C1B0
// Name: public: virtual enum FSAsyncStatus_t CFileSystemPassThru::AsyncWriteFile(char const __near *,class CUtlBuffer const __near *,int,bool,bool,struct FSAsyncControl_t__ __near * __near *)
// Source: json
//------------------------------------------------------------------------------
FSAsyncStatus_t __thiscall CFileSystemPassThru::AsyncWriteFile(
        CFileSystemPassThru *this,
        const char *pFileName,
        const CUtlBuffer *pSrc,
        int nSrcBytes,
        BOOL bFreeMemory,
        BOOL bAppend,
        FSAsyncControl_t__ **pControl)
{
  return this->m_pFileSystemPassThru->AsyncWriteFile(
           this: this->m_pFileSystemPassThru,
           a2: pFileName,
           a3: pSrc,
           a4: nSrcBytes,
           a5: bFreeMemory,
           a6: bAppend,
           a7: pControl);
}

//------------------------------------------------------------------------------
// Address: 0x1000C1D0
// Name: public: virtual enum FSAsyncStatus_t CFileSystemPassThru::AsyncAppendFile(char const __near *,char const __near *,struct FSAsyncControl_t__ __near * __near *)
// Source: json
//------------------------------------------------------------------------------
FSAsyncStatus_t __thiscall CFileSystemPassThru::AsyncAppendFile(
        CFileSystemPassThru *this,
        const char *pDestFileName,
        const char *pSrcFileName,
        FSAsyncControl_t__ **pControl)
{
  return this->m_pFileSystemPassThru->AsyncAppendFile(
           this: this->m_pFileSystemPassThru,
           a2: pDestFileName,
           a3: pSrcFileName,
           a4: pControl);
}

//------------------------------------------------------------------------------
// Address: 0x1000C1F0
// Name: public: virtual void CFileSystemPassThru::AsyncFinishAll(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFileSystemPassThru::AsyncFinishAll(CFileSystemPassThru *this, int iToPriority)
{
  this->m_pFileSystemPassThru->AsyncFinishAll(this: this->m_pFileSystemPassThru, a2: iToPriority);
}

//------------------------------------------------------------------------------
// Address: 0x1000C210
// Name: public: virtual void CFileSystemPassThru::AsyncFinishAllWrites(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFileSystemPassThru::AsyncFinishAllWrites(CFileSystemPassThru *this)
{
  this->m_pFileSystemPassThru->AsyncFinishAllWrites(this: this->m_pFileSystemPassThru);
}

//------------------------------------------------------------------------------
// Address: 0x1000C220
// Name: public: virtual enum FSAsyncStatus_t CFileSystemPassThru::AsyncSetPriority(struct FSAsyncControl_t__ __near *,int)
// Source: json
//------------------------------------------------------------------------------
FSAsyncStatus_t __thiscall CFileSystemPassThru::AsyncSetPriority(
        CFileSystemPassThru *this,
        FSAsyncControl_t__ *hControl,
        int newPriority)
{
  return this->m_pFileSystemPassThru->AsyncSetPriority(this: this->m_pFileSystemPassThru, a2: hControl, a3: newPriority);
}

//------------------------------------------------------------------------------
// Address: 0x1000C240
// Name: public: virtual bool CFileSystemPassThru::AsyncSuspend(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CFileSystemPassThru::AsyncSuspend(CFileSystemPassThru *this)
{
  return this->m_pFileSystemPassThru->AsyncSuspend(this: this->m_pFileSystemPassThru);
}

//------------------------------------------------------------------------------
// Address: 0x1000C250
// Name: public: virtual bool CFileSystemPassThru::AsyncResume(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CFileSystemPassThru::AsyncResume(CFileSystemPassThru *this)
{
  return this->m_pFileSystemPassThru->AsyncResume(this: this->m_pFileSystemPassThru);
}

//------------------------------------------------------------------------------
// Address: 0x1000C260
// Name: public: virtual char const __near * CFileSystemPassThru::RelativePathToFullPath(char const __near *,char const __near *,char __near *,int,enum PathTypeFilter_t,unsigned int __near *)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CFileSystemPassThru::RelativePathToFullPath(
        CFileSystemPassThru *this,
        const char *pFileName,
        const char *pPathID,
        char *pLocalPath,
        int localPathBufferSize,
        PathTypeFilter_t pathFilter,
        unsigned int *pPathType)
{
  return this->m_pFileSystemPassThru->RelativePathToFullPath(
           this: this->m_pFileSystemPassThru,
           a2: pFileName,
           a3: pPathID,
           a4: pLocalPath,
           a5: localPathBufferSize,
           a6: pathFilter,
           a7: pPathType);
}

//------------------------------------------------------------------------------
// Address: 0x1000C270
// Name: public: virtual int CFileSystemPassThru::GetSearchPath(char const __near *,bool,char __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CFileSystemPassThru::GetSearchPath(
        CFileSystemPassThru *this,
        const char *pathID,
        BOOL bGetPackFiles,
        char *pPath,
        int nMaxLen)
{
  return this->m_pFileSystemPassThru->GetSearchPath(
           this: this->m_pFileSystemPassThru,
           a2: pathID,
           a3: bGetPackFiles,
           a4: pPath,
           a5: nMaxLen);
}

//------------------------------------------------------------------------------
// Address: 0x1000C280
// Name: public: virtual void __near * CFileSystemPassThru::OpenEx(char const __near *,char const __near *,unsigned int,char const __near *,char __near * __near *)
// Source: json
//------------------------------------------------------------------------------
void *__thiscall CFileSystemPassThru::OpenEx(
        CFileSystemPassThru *this,
        const char *pFileName,
        const char *pOptions,
        unsigned int flags,
        const char *pathID,
        char **ppszResolvedFilename)
{
  return this->m_pFileSystemPassThru->OpenEx(
           this: this->m_pFileSystemPassThru,
           a2: pFileName,
           a3: pOptions,
           a4: flags,
           a5: pathID,
           a6: ppszResolvedFilename);
}

//------------------------------------------------------------------------------
// Address: 0x1000C2A0
// Name: public: virtual int CFileSystemPassThru::ReadEx(void __near *,int,int,void __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CFileSystemPassThru::ReadEx(
        CFileSystemPassThru *this,
        void *pOutput,
        int destSize,
        int size,
        void *file)
{
  return this->m_pFileSystemPassThru->ReadEx(
           this: this->m_pFileSystemPassThru,
           a2: pOutput,
           a3: destSize,
           a4: size,
           a5: file);
}

//------------------------------------------------------------------------------
// Address: 0x1000C2C0
// Name: public: virtual int CFileSystemPassThru::ReadFileEx(char const __near *,char const __near *,void __near * __near *,bool,bool,int,int,void __near * (*)(char const __near *,unsigned int))
// Source: json
//------------------------------------------------------------------------------
int __thiscall CFileSystemPassThru::ReadFileEx(
        CFileSystemPassThru *this,
        const char *pFileName,
        const char *pPath,
        void **ppBuf,
        BOOL bNullTerminate,
        BOOL bOptimalAlloc,
        int nMaxBytes,
        int nStartingByte,
        void *(__cdecl *pfnAlloc)(const char *, unsigned int))
{
  return this->m_pFileSystemPassThru->ReadFileEx(
           this: this->m_pFileSystemPassThru,
           a2: pFileName,
           a3: pPath,
           a4: ppBuf,
           a5: bNullTerminate,
           a6: bOptimalAlloc,
           a7: nMaxBytes,
           a8: nStartingByte,
           a9: pfnAlloc);
}

//------------------------------------------------------------------------------
// Address: 0x1000C2F0
// Name: public: virtual class KeyValues __near * CFileSystemPassThru::LoadKeyValues(enum IFileSystem::KeyValuesPreloadType_t,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
KeyValues *__thiscall CFileSystemPassThru::LoadKeyValues(
        CFileSystemPassThru *this,
        IFileSystem::KeyValuesPreloadType_t type,
        const char *filename,
        const char *pPathID)
{
  return this->m_pFileSystemPassThru->LoadKeyValues_2(
           this: this->m_pFileSystemPassThru,
           a2: type,
           a3: filename,
           a4: pPathID);
}

//------------------------------------------------------------------------------
// Address: 0x1000C310
// Name: public: virtual bool CFileSystemPassThru::LoadKeyValues(class KeyValues __near &,enum IFileSystem::KeyValuesPreloadType_t,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CFileSystemPassThru::LoadKeyValues(
        CFileSystemPassThru *this,
        KeyValues *head,
        IFileSystem::KeyValuesPreloadType_t type,
        const char *filename,
        const char *pPathID)
{
  return this->m_pFileSystemPassThru->LoadKeyValues(
           this: this->m_pFileSystemPassThru,
           a2: head,
           a3: type,
           a4: filename,
           a5: pPathID);
}

//------------------------------------------------------------------------------
// Address: 0x1000C330
// Name: public: virtual bool CFileSystemPassThru::GetFileTypeForFullPath(char const __near *,wchar_t __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CFileSystemPassThru::GetFileTypeForFullPath(
        CFileSystemPassThru *this,
        const char *pFullPath,
        wchar_t *buf,
        unsigned int bufSizeInBytes)
{
  return this->m_pFileSystemPassThru->GetFileTypeForFullPath(
           this: this->m_pFileSystemPassThru,
           a2: pFullPath,
           a3: buf,
           a4: bufSizeInBytes);
}

//------------------------------------------------------------------------------
// Address: 0x1000C350
// Name: public: virtual bool CFileSystemPassThru::GetOptimalIOConstraints(void __near *,unsigned int __near *,unsigned int __near *,unsigned int __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CFileSystemPassThru::GetOptimalIOConstraints(
        CFileSystemPassThru *this,
        void *hFile,
        unsigned int *pOffsetAlign,
        unsigned int *pSizeAlign,
        unsigned int *pBufferAlign)
{
  return this->m_pFileSystemPassThru->GetOptimalIOConstraints(
           this: this->m_pFileSystemPassThru,
           a2: hFile,
           a3: pOffsetAlign,
           a4: pSizeAlign,
           a5: pBufferAlign);
}

//------------------------------------------------------------------------------
// Address: 0x1000C370
// Name: public: virtual void __near * CFileSystemPassThru::AllocOptimalReadBuffer(void __near *,unsigned int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void *__thiscall CFileSystemPassThru::AllocOptimalReadBuffer(
        CFileSystemPassThru *this,
        void *hFile,
        unsigned int nSize,
        unsigned int nOffset)
{
  return this->m_pFileSystemPassThru->AllocOptimalReadBuffer(
           this: this->m_pFileSystemPassThru,
           a2: hFile,
           a3: nOffset,
           a4: nSize);
}

//------------------------------------------------------------------------------
// Address: 0x1000C390
// Name: public: virtual void CFileSystemPassThru::FreeOptimalReadBuffer(void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFileSystemPassThru::FreeOptimalReadBuffer(CFileSystemPassThru *this, void *p)
{
  this->m_pFileSystemPassThru->FreeOptimalReadBuffer(this: this->m_pFileSystemPassThru, a2: p);
}

//------------------------------------------------------------------------------
// Address: 0x1000C3B0
// Name: public: virtual void CFileSystemPassThru::BeginMapAccess(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFileSystemPassThru::BeginMapAccess(CFileSystemPassThru *this)
{
  this->m_pFileSystemPassThru->BeginMapAccess(this: this->m_pFileSystemPassThru);
}

//------------------------------------------------------------------------------
// Address: 0x1000C3C0
// Name: public: virtual void CFileSystemPassThru::EndMapAccess(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFileSystemPassThru::EndMapAccess(CFileSystemPassThru *this)
{
  this->m_pFileSystemPassThru->EndMapAccess(this: this->m_pFileSystemPassThru);
}

//------------------------------------------------------------------------------
// Address: 0x1000C3D0
// Name: public: virtual bool CFileSystemPassThru::ReadToBuffer(void __near *,class CUtlBuffer __near &,int,void __near * (*)(char const __near *,unsigned int))
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CFileSystemPassThru::ReadToBuffer(
        CFileSystemPassThru *this,
        void *hFile,
        CUtlBuffer *buf,
        int nMaxBytes,
        void *(__cdecl *pfnAlloc)(const char *, unsigned int))
{
  return this->m_pFileSystemPassThru->ReadToBuffer(
           this: this->m_pFileSystemPassThru,
           a2: hFile,
           a3: buf,
           a4: nMaxBytes,
           a5: pfnAlloc);
}

//------------------------------------------------------------------------------
// Address: 0x1000C3F0
// Name: public: virtual bool CFileSystemPassThru::FullPathToRelativePathEx(char const __near *,char const __near *,char __near *,int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CFileSystemPassThru::FullPathToRelativePathEx(
        CFileSystemPassThru *this,
        const char *pFullPath,
        const char *pPathId,
        char *pRelative,
        int nMaxLen)
{
  return this->m_pFileSystemPassThru->FullPathToRelativePathEx(
           this: this->m_pFileSystemPassThru,
           a2: pFullPath,
           a3: pPathId,
           a4: pRelative,
           a5: nMaxLen);
}

//------------------------------------------------------------------------------
// Address: 0x1000C410
// Name: public: virtual int CFileSystemPassThru::GetPathIndex(void __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CFileSystemPassThru::GetPathIndex(CFileSystemPassThru *this, void *const *handle)
{
  return this->m_pFileSystemPassThru->GetPathIndex(this: this->m_pFileSystemPassThru, a2: handle);
}

//------------------------------------------------------------------------------
// Address: 0x1000C430
// Name: public: virtual long CFileSystemPassThru::GetPathTime(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CFileSystemPassThru::GetPathTime(CFileSystemPassThru *this, const char *pPath, const char *pPathID)
{
  return this->m_pFileSystemPassThru->GetPathTime(this: this->m_pFileSystemPassThru, a2: pPath, a3: pPathID);
}

//------------------------------------------------------------------------------
// Address: 0x1000C450
// Name: public: virtual enum DVDMode_t CFileSystemPassThru::GetDVDMode(void)
// Source: json
//------------------------------------------------------------------------------
DVDMode_t __thiscall CFileSystemPassThru::GetDVDMode(CFileSystemPassThru *this)
{
  return this->m_pFileSystemPassThru->GetDVDMode(this: this->m_pFileSystemPassThru);
}

//------------------------------------------------------------------------------
// Address: 0x1000C460
// Name: public: virtual void CFileSystemPassThru::EnableWhitelistFileTracking(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFileSystemPassThru::EnableWhitelistFileTracking(CFileSystemPassThru *this, BOOL bEnable)
{
  this->m_pFileSystemPassThru->EnableWhitelistFileTracking(this: this->m_pFileSystemPassThru, a2: bEnable);
}

//------------------------------------------------------------------------------
// Address: 0x1000C480
// Name: public: virtual void CFileSystemPassThru::RegisterFileWhitelist(class IFileList __near *,class IFileList __near *,class IFileList __near * __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFileSystemPassThru::RegisterFileWhitelist(
        CFileSystemPassThru *this,
        struct IFileList *pForceMatchList,
        struct IFileList *pAllowFromDiskList,
        struct IFileList **pFilesToReload)
{
  this->m_pFileSystemPassThru->RegisterFileWhitelist(
    this: this->m_pFileSystemPassThru,
    a2: pForceMatchList,
    a3: pAllowFromDiskList,
    a4: pFilesToReload);
}

//------------------------------------------------------------------------------
// Address: 0x1000C4A0
// Name: public: virtual void CFileSystemPassThru::MarkAllCRCsUnverified(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFileSystemPassThru::MarkAllCRCsUnverified(CFileSystemPassThru *this)
{
  this->m_pFileSystemPassThru->MarkAllCRCsUnverified(this: this->m_pFileSystemPassThru);
}

//------------------------------------------------------------------------------
// Address: 0x1000C4B0
// Name: public: virtual void CFileSystemPassThru::CacheFileCRCs(char const __near *,enum ECacheCRCType,class IFileList __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFileSystemPassThru::CacheFileCRCs(
        CFileSystemPassThru *this,
        const char *pPathname,
        ECacheCRCType eType,
        struct IFileList *pFilter)
{
  this->m_pFileSystemPassThru->CacheFileCRCs(this: this->m_pFileSystemPassThru, a2: pPathname, a3: eType, a4: pFilter);
}

//------------------------------------------------------------------------------
// Address: 0x1000C4D0
// Name: public: virtual enum EFileCRCStatus CFileSystemPassThru::CheckCachedFileCRC(char const __near *,char const __near *,unsigned long __near *)
// Source: json
//------------------------------------------------------------------------------
EFileCRCStatus __thiscall CFileSystemPassThru::CheckCachedFileCRC(
        CFileSystemPassThru *this,
        const char *pPathID,
        const char *pRelativeFilename,
        unsigned int *pCRC)
{
  return this->m_pFileSystemPassThru->CheckCachedFileCRC(
           this: this->m_pFileSystemPassThru,
           a2: pPathID,
           a3: pRelativeFilename,
           a4: pCRC);
}

//------------------------------------------------------------------------------
// Address: 0x1000C4F0
// Name: public: virtual int CFileSystemPassThru::GetUnverifiedCRCFiles(class CUnverifiedCRCFile __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CFileSystemPassThru::GetUnverifiedCRCFiles(
        CFileSystemPassThru *this,
        CUnverifiedCRCFile *pFiles,
        int nMaxFiles)
{
  return this->m_pFileSystemPassThru->GetUnverifiedCRCFiles(
           this: this->m_pFileSystemPassThru,
           a2: pFiles,
           a3: nMaxFiles);
}

//------------------------------------------------------------------------------
// Address: 0x1000C510
// Name: public: virtual int CFileSystemPassThru::GetWhitelistSpewFlags(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CFileSystemPassThru::GetWhitelistSpewFlags(CFileSystemPassThru *this)
{
  return this->m_pFileSystemPassThru->GetWhitelistSpewFlags(this: this->m_pFileSystemPassThru);
}

//------------------------------------------------------------------------------
// Address: 0x1000C520
// Name: public: virtual void CFileSystemPassThru::SetWhitelistSpewFlags(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFileSystemPassThru::SetWhitelistSpewFlags(CFileSystemPassThru *this, int spewFlags)
{
  this->m_pFileSystemPassThru->SetWhitelistSpewFlags(this: this->m_pFileSystemPassThru, a2: spewFlags);
}

//------------------------------------------------------------------------------
// Address: 0x1000C540
// Name: public: virtual void CFileSystemPassThru::InstallDirtyDiskReportFunc(void (*)(void))
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFileSystemPassThru::InstallDirtyDiskReportFunc(CFileSystemPassThru *this, void (__cdecl *func)())
{
  this->m_pFileSystemPassThru->InstallDirtyDiskReportFunc(this: this->m_pFileSystemPassThru, a2: func);
}

//------------------------------------------------------------------------------
// Address: 0x1000C560
// Name: public: virtual bool CFileSystemPassThru::IsLaunchedFromXboxHDD(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CFileSystemPassThru::IsLaunchedFromXboxHDD(CFileSystemPassThru *this)
{
  return this->m_pFileSystemPassThru->IsLaunchedFromXboxHDD(this: this->m_pFileSystemPassThru);
}

//------------------------------------------------------------------------------
// Address: 0x1000C570
// Name: public: virtual bool CFileSystemPassThru::IsInstalledToXboxHDDCache(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CFileSystemPassThru::IsInstalledToXboxHDDCache(CFileSystemPassThru *this)
{
  return this->m_pFileSystemPassThru->IsInstalledToXboxHDDCache(this: this->m_pFileSystemPassThru);
}

//------------------------------------------------------------------------------
// Address: 0x1000C580
// Name: public: virtual bool CFileSystemPassThru::IsDVDHosted(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CFileSystemPassThru::IsDVDHosted(CFileSystemPassThru *this)
{
  return this->m_pFileSystemPassThru->IsDVDHosted(this: this->m_pFileSystemPassThru);
}

//------------------------------------------------------------------------------
// Address: 0x1000C590
// Name: public: virtual bool CFileSystemPassThru::IsInstallAllowed(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CFileSystemPassThru::IsInstallAllowed(CFileSystemPassThru *this)
{
  return this->m_pFileSystemPassThru->IsInstallAllowed(this: this->m_pFileSystemPassThru);
}

//------------------------------------------------------------------------------
// Address: 0x1000C5A0
// Name: public: virtual int CFileSystemPassThru::GetSearchPathID(char __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CFileSystemPassThru::GetSearchPathID(CFileSystemPassThru *this, char *pPath, int nMaxLen)
{
  return this->m_pFileSystemPassThru->GetSearchPathID(this: this->m_pFileSystemPassThru, a2: pPath, a3: nMaxLen);
}

//------------------------------------------------------------------------------
// Address: 0x1000C5C0
// Name: public: virtual bool CFileSystemPassThru::FixupSearchPathsAfterInstall(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CFileSystemPassThru::FixupSearchPathsAfterInstall(CFileSystemPassThru *this)
{
  return this->m_pFileSystemPassThru->FixupSearchPathsAfterInstall(this: this->m_pFileSystemPassThru);
}

//------------------------------------------------------------------------------
// Address: 0x1000C5D0
// Name: public: virtual void (*CFileSystemPassThru::GetDirtyDiskReportFunc(void))(void)
// Source: json
//------------------------------------------------------------------------------
void (__cdecl *__thiscall CFileSystemPassThru::GetDirtyDiskReportFunc(CFileSystemPassThru *this))()
{
  return this->m_pFileSystemPassThru->GetDirtyDiskReportFunc(this: this->m_pFileSystemPassThru);
}

//------------------------------------------------------------------------------
// Address: 0x1000C5E0
// Name: public: virtual void CFileSystemPassThru::AddVPKFile(char const __near *,enum SearchPathAdd_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFileSystemPassThru::AddVPKFile(
        CFileSystemPassThru *this,
        const char *pPkName,
        SearchPathAdd_t addType)
{
  this->m_pFileSystemPassThru->AddVPKFile(this: this->m_pFileSystemPassThru, a2: pPkName, a3: addType);
}

//------------------------------------------------------------------------------
// Address: 0x1000C600
// Name: public: virtual void CFileSystemPassThru::RemoveVPKFile(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFileSystemPassThru::RemoveVPKFile(CFileSystemPassThru *this, const char *pPkName)
{
  this->m_pFileSystemPassThru->RemoveVPKFile(this: this->m_pFileSystemPassThru, a2: pPkName);
}

//------------------------------------------------------------------------------
// Address: 0x1000C620
// Name: public: virtual void CFileSystemPassThru::GetVPKFileNames(class CUtlVector<class CUtlString,class CUtlMemory<class CUtlString,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFileSystemPassThru::GetVPKFileNames(
        CFileSystemPassThru *this,
        CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *destVector)
{
  this->m_pFileSystemPassThru->GetVPKFileNames(this: this->m_pFileSystemPassThru, a2: destVector);
}

//------------------------------------------------------------------------------
// Address: 0x1000C640
// Name: public: virtual void CFileSystemPassThru::RemoveAllMapSearchPaths(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFileSystemPassThru::RemoveAllMapSearchPaths(CFileSystemPassThru *this)
{
  this->m_pFileSystemPassThru->RemoveAllMapSearchPaths(this: this->m_pFileSystemPassThru);
}

//------------------------------------------------------------------------------
// Address: 0x1000C650
// Name: public: virtual void CFileSystemPassThru::SyncDvdDevCache(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFileSystemPassThru::SyncDvdDevCache(CFileSystemPassThru *this)
{
  this->m_pFileSystemPassThru->SyncDvdDevCache(this: this->m_pFileSystemPassThru);
}

//------------------------------------------------------------------------------
// Address: 0x1000C660
// Name: public: virtual bool CFileSystemPassThru::GetStringFromKVPool(unsigned long,unsigned int,char __near *,int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CFileSystemPassThru::GetStringFromKVPool(
        CFileSystemPassThru *this,
        unsigned int poolKey,
        unsigned int key,
        char *pOutBuff,
        int buflen)
{
  return this->m_pFileSystemPassThru->GetStringFromKVPool(
           this: this->m_pFileSystemPassThru,
           a2: poolKey,
           a3: key,
           a4: pOutBuff,
           a5: buflen);
}

//------------------------------------------------------------------------------
// Address: 0x1000C680
// Name: public: virtual bool CFileSystemPassThru::DiscoverDLC(int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CFileSystemPassThru::DiscoverDLC(CFileSystemPassThru *this, int iController)
{
  return this->m_pFileSystemPassThru->DiscoverDLC(this: this->m_pFileSystemPassThru, a2: iController);
}

//------------------------------------------------------------------------------
// Address: 0x1000C6A0
// Name: public: virtual int CFileSystemPassThru::IsAnyDLCPresent(bool __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CFileSystemPassThru::IsAnyDLCPresent(CFileSystemPassThru *this, bool *pbDLCSearchPathMounted)
{
  return this->m_pFileSystemPassThru->IsAnyDLCPresent(this: this->m_pFileSystemPassThru, a2: pbDLCSearchPathMounted);
}

//------------------------------------------------------------------------------
// Address: 0x1000C6C0
// Name: public: virtual bool CFileSystemPassThru::GetAnyDLCInfo(int,unsigned int __near *,wchar_t __near *,int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CFileSystemPassThru::GetAnyDLCInfo(
        CFileSystemPassThru *this,
        int iDLC,
        unsigned int *pLicenseMask,
        wchar_t *pTitleBuff,
        int nOutTitleSize)
{
  return this->m_pFileSystemPassThru->GetAnyDLCInfo(
           this: this->m_pFileSystemPassThru,
           a2: iDLC,
           a3: pLicenseMask,
           a4: pTitleBuff,
           a5: nOutTitleSize);
}

//------------------------------------------------------------------------------
// Address: 0x1000C6E0
// Name: public: virtual int CFileSystemPassThru::IsAnyCorruptDLC(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CFileSystemPassThru::IsAnyCorruptDLC(CFileSystemPassThru *this)
{
  return this->m_pFileSystemPassThru->IsAnyCorruptDLC(this: this->m_pFileSystemPassThru);
}

//------------------------------------------------------------------------------
// Address: 0x1000C6F0
// Name: public: virtual bool CFileSystemPassThru::GetAnyCorruptDLCInfo(int,wchar_t __near *,int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CFileSystemPassThru::GetAnyCorruptDLCInfo(
        CFileSystemPassThru *this,
        int iCorruptDLC,
        wchar_t *pTitleBuff,
        int nOutTitleSize)
{
  return this->m_pFileSystemPassThru->GetAnyCorruptDLCInfo(
           this: this->m_pFileSystemPassThru,
           a2: iCorruptDLC,
           a3: pTitleBuff,
           a4: nOutTitleSize);
}

//------------------------------------------------------------------------------
// Address: 0x1000C710
// Name: public: virtual bool CFileSystemPassThru::AddDLCSearchPaths(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CFileSystemPassThru::AddDLCSearchPaths(CFileSystemPassThru *this)
{
  return this->m_pFileSystemPassThru->AddDLCSearchPaths(this: this->m_pFileSystemPassThru);
}

//------------------------------------------------------------------------------
// Address: 0x1000C720
// Name: public: virtual bool CFileSystemPassThru::IsSpecificDLCPresent(unsigned int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CFileSystemPassThru::IsSpecificDLCPresent(CFileSystemPassThru *this, unsigned int nDLCPackage)
{
  return this->m_pFileSystemPassThru->IsSpecificDLCPresent(this: this->m_pFileSystemPassThru, a2: nDLCPackage);
}

//------------------------------------------------------------------------------
// Address: 0x1000C740
// Name: public: virtual void CFileSystemPassThru::SetIODelayAlarm(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFileSystemPassThru::SetIODelayAlarm(CFileSystemPassThru *this, float flThreshhold)
{
  ((void (__stdcall *)(_DWORD))this->m_pFileSystemPassThru->SetIODelayAlarm)(a1: LODWORD(flThreshhold));
}

//------------------------------------------------------------------------------
// Address: 0x1000C760
// Name: public: virtual bool CFileSystemPassThru::AddXLSPUpdateSearchPath(void const __near *,int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CFileSystemPassThru::AddXLSPUpdateSearchPath(CFileSystemPassThru *this, const void *pData, int nSize)
{
  return this->m_pFileSystemPassThru->AddXLSPUpdateSearchPath(this: this->m_pFileSystemPassThru, a2: pData, a3: nSize);
}

//------------------------------------------------------------------------------
// Address: 0x1000C7B0
// Name: public: virtual void CBaseVMPIFileSystem::Release(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseVMPIFileSystem::Release(CBaseVMPIFileSystem *this)
{
  if ( this != nullptr )
    ((void (__thiscall *)(CBaseVMPIFileSystem *, int))this->dtr_CBaseVMPIFileSystem)(a1: this, a2: 1);
}

//------------------------------------------------------------------------------
// Address: 0x1000C7D0
// Name: public: virtual void CBaseVMPIFileSystem::Close(void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseVMPIFileSystem::Close(CBaseVMPIFileSystem *this, void (__thiscall ***file)(_DWORD))
{
  if ( file != nullptr )
    (**file)(a1: file);
}

//------------------------------------------------------------------------------
// Address: 0x1000C7F0
// Name: public: virtual int CBaseVMPIFileSystem::Read(void __near *,int,void __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBaseVMPIFileSystem::Read(CBaseVMPIFileSystem *this, void *pOutput, int size, void *file)
{
  return (*(int (__thiscall **)(void *, void *, int))(*(_DWORD *)file + 20))(a1: file, a2: pOutput, a3: size);
}

//------------------------------------------------------------------------------
// Address: 0x1000C810
// Name: public: virtual int CBaseVMPIFileSystem::Write(void const __near *,int,void __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBaseVMPIFileSystem::Write(CBaseVMPIFileSystem *this, const void *pInput, int size, void *file)
{
  return (*(int (__thiscall **)(void *, const void *, int))(*(_DWORD *)file + 24))(a1: file, a2: pInput, a3: size);
}

//------------------------------------------------------------------------------
// Address: 0x1000C830
// Name: public: virtual void CBaseVMPIFileSystem::Seek(void __near *,int,enum FileSystemSeek_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseVMPIFileSystem::Seek(CBaseVMPIFileSystem *this, void *file, int pos, FileSystemSeek_t seekType)
{
  (*(void (__thiscall **)(void *, int, FileSystemSeek_t))(*(_DWORD *)file + 4))(a1: file, a2: pos, a3: seekType);
}

//------------------------------------------------------------------------------
// Address: 0x1000C850
// Name: public: virtual unsigned int CBaseVMPIFileSystem::Tell(void __near *)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CBaseVMPIFileSystem::Tell(CBaseVMPIFileSystem *this, void *file)
{
  return (*(unsigned int (__thiscall **)(void *))(*(_DWORD *)file + 8))(a1: file);
}

//------------------------------------------------------------------------------
// Address: 0x1000C870
// Name: public: virtual unsigned int CBaseVMPIFileSystem::Size(void __near *)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CBaseVMPIFileSystem::Size(CBaseVMPIFileSystem *this, void *file)
{
  return (*(unsigned int (__thiscall **)(void *))(*(_DWORD *)file + 12))(a1: file);
}

//------------------------------------------------------------------------------
// Address: 0x1000C890
// Name: public: virtual unsigned int CBaseVMPIFileSystem::Size(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBaseVMPIFileSystem::Size(CBaseVMPIFileSystem *this, const char *pFilename, const char *pathID)
{
  int result; // eax
  unsigned int v5; // edi
  int v6; // ebx

  result = ((int (__thiscall *)(CBaseVMPIFileSystem *, const char *, const char *, _DWORD))this->QueryInterface)(
             a1: this,
             a2: pFilename,
             a3: "rb",
             a4: 0);
  v5 = result;
  if ( result != 0 )
  {
    v6 = ((int (__thiscall *)(CBaseVMPIFileSystem *, int))this->Reconnect)(a1: this, a2: result);
    ((void (__thiscall *)(CBaseVMPIFileSystem *, unsigned int))this->Init)(a1: this, a2: v5);
    return v6;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1000C8E0
// Name: public: virtual bool CBaseVMPIFileSystem::FileExists(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CBaseVMPIFileSystem::FileExists(CBaseVMPIFileSystem *this, const char *pFileName, const char *pPathID)
{
  int v4; // eax

  v4 = ((int (__thiscall *)(CBaseVMPIFileSystem *, const char *, const char *, _DWORD))this->QueryInterface)(
         a1: this,
         a2: pFileName,
         a3: "rb",
         a4: 0);
  if ( v4 == 0 )
    return 0;
  ((void (__thiscall *)(CBaseVMPIFileSystem *, int))this->Init)(a1: this, a2: v4);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1000C920
// Name: public: virtual void CBaseVMPIFileSystem::Flush(void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseVMPIFileSystem::Flush(CBaseVMPIFileSystem *this, void *file)
{
  (*(void (__thiscall **)(void *))(*(_DWORD *)file + 16))(a1: file);
}

//------------------------------------------------------------------------------
// Address: 0x1000C940
// Name: public: virtual bool CBaseVMPIFileSystem::Precache(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CBaseVMPIFileSystem::Precache(CBaseVMPIFileSystem *this, const char *pFileName, const char *pPathID)
{
  return false;
}

//------------------------------------------------------------------------------
// Address: 0x1000C950
// Name: public: virtual void CInternalFileSystemPassThru<class IFileSystem>::InitPassThru(class IBaseFileSystem __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInternalFileSystemPassThru<IFileSystem>::InitPassThru(
        CInternalFileSystemPassThru<IFileSystem> *this,
        IBaseFileSystem *pBaseFileSystemPassThru)
{
  this->m_pBaseFileSystemPassThru = pBaseFileSystemPassThru;
}

//------------------------------------------------------------------------------
// Address: 0x1000C960
// Name: public: virtual void __near * CInternalFileSystemPassThru<class IFileSystem>::Open(char const __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void *__thiscall CInternalFileSystemPassThru<IFileSystem>::Open(
        CInternalFileSystemPassThru<IFileSystem> *this,
        const char *pFileName,
        const char *pOptions,
        const char *pathID)
{
  return (*((void *(__thiscall **)(IBaseFileSystem_vtbl *, const char *, const char *, const char *))this->Read + 2))(
           a1: this->IFileSystem::IBaseFileSystem::__vftable,
           a2: pFileName,
           a3: pOptions,
           a4: pathID);
}

//------------------------------------------------------------------------------
// Address: 0x1000C970
// Name: public: virtual bool CInternalFileSystemPassThru<class IFileSystem>::IsFileWritable(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CInternalFileSystemPassThru<IFileSystem>::IsFileWritable(
        CInternalFileSystemPassThru<IFileSystem> *this,
        const char *pFileName,
        const char *pPathID)
{
  return (*((bool (__thiscall **)(IBaseFileSystem_vtbl *, const char *, const char *))this->Read + 11))(
           a1: this->IFileSystem::IBaseFileSystem::__vftable,
           a2: pFileName,
           a3: pPathID);
}

//------------------------------------------------------------------------------
// Address: 0x1000C980
// Name: public: virtual bool CInternalFileSystemPassThru<class IFileSystem>::SetFileWritable(char const __near *,bool,char const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __userpurge CInternalFileSystemPassThru<IFileSystem>::SetFileWritable@<al>(
        CInternalFileSystemPassThru<IFileSystem> *this@<ecx>,
        const char *pFileName,
        bool writable,
        const char *pPathID)
{
  return (*((bool (__thiscall **)(IBaseFileSystem_vtbl *, const char *))this->Read + 12))(
           a1: this->IFileSystem::IBaseFileSystem::__vftable,
           a2: pFileName);
}

//------------------------------------------------------------------------------
// Address: 0x1000C990
// Name: public: virtual long CInternalFileSystemPassThru<class IFileSystem>::GetFileTime(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CInternalFileSystemPassThru<IFileSystem>::GetFileTime(
        CInternalFileSystemPassThru<IFileSystem> *this,
        const char *pFileName,
        const char *pPathID)
{
  return (*((int (__thiscall **)(IBaseFileSystem_vtbl *, const char *, const char *))this->Read + 13))(
           a1: this->IFileSystem::IBaseFileSystem::__vftable,
           a2: pFileName,
           a3: pPathID);
}

//------------------------------------------------------------------------------
// Address: 0x1000C9A0
// Name: public: virtual bool CInternalFileSystemPassThru<class IFileSystem>::UnzipFile(char const __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CInternalFileSystemPassThru<IFileSystem>::UnzipFile(
        CInternalFileSystemPassThru<IFileSystem> *this,
        const char *pFileName,
        const char *pPath,
        const char *pDestination)
{
  return (*((bool (__thiscall **)(IBaseFileSystem_vtbl *, const char *, const char *, const char *))this->Read + 16))(
           a1: this->IFileSystem::IBaseFileSystem::__vftable,
           a2: pFileName,
           a3: pPath,
           a4: pDestination);
}

//------------------------------------------------------------------------------
// Address: 0x1000C9B0
// Name: public: virtual void CFileSystemPassThru::InitPassThru(class IFileSystem __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFileSystemPassThru::InitPassThru(
        CFileSystemPassThru *this,
        IFileSystem *pFileSystemPassThru,
        bool bBaseOnly)
{
  if ( !bBaseOnly )
    this->m_pFileSystemPassThru = pFileSystemPassThru;
  if ( pFileSystemPassThru != nullptr )
    this->m_pBaseFileSystemPassThru = &pFileSystemPassThru->IBaseFileSystem;
  else
    this->m_pBaseFileSystemPassThru = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1000C9E0
// Name: public: virtual bool CBaseVMPIFileSystem::ReadFile(char const __near *,char const __near *,class CUtlBuffer __near &,int,int,void __near * (*)(char const __near *,unsigned int))
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CBaseVMPIFileSystem::ReadFile(
        CBaseVMPIFileSystem *this,
        const char *pFileName,
        const char *pPath,
        CUtlBuffer *buf,
        int nMaxBytes,
        int nStartingByte,
        void *(__cdecl *pfnAlloc)(const char *, unsigned int))
{
  const char *v9; // eax
  int v10; // ebx
  int v12; // eax
  int nBytesRead; // [esp+1Ch] [ebp+10h]
  int nBytesReada; // [esp+1Ch] [ebp+10h]

  v9 = "rt";
  if ( (buf->m_Flags & 1) == 0 )
    v9 = "rb";
  v10 = ((int (__thiscall *)(CBaseVMPIFileSystem *, const char *, const char *, const char *))this->QueryInterface)(
          a1: this,
          a2: pFileName,
          a3: v9,
          a4: pPath);
  if ( v10 == 0 )
    return false;
  v12 = ((int (__thiscall *)(CBaseVMPIFileSystem *, int))this->Reconnect)(a1: this, a2: v10);
  nBytesRead = v12;
  if ( nMaxBytes > 0 && nMaxBytes < v12 )
  {
    nBytesRead = nMaxBytes;
    v12 = nMaxBytes;
  }
  CUtlBuffer::EnsureCapacity(this: buf, num: v12 + buf->m_Put);
  if ( nStartingByte != 0 )
    ((void (__thiscall *)(CBaseVMPIFileSystem *, int, int, _DWORD))this->Shutdown)(
      a1: this,
      a2: v10,
      a3: nStartingByte,
      a4: 0);
  nBytesReada = ((int (__thiscall *)(CBaseVMPIFileSystem *, unsigned __int8 *, int, int))this->Connect)(
                  a1: this,
                  a2: &buf->m_Memory.m_pMemory[buf->m_Put - buf->m_nOffset],
                  a3: nBytesRead,
                  a4: v10);
  CUtlBuffer::SeekPut(this: buf, type: SEEK_CURRENT, offset: nBytesReada);
  ((void (__thiscall *)(CBaseVMPIFileSystem *, int))this->Init)(a1: this, a2: v10);
  return nBytesReada != 0;
}

//------------------------------------------------------------------------------
// Address: 0x1000CAA0
// Name: public: virtual bool CBaseVMPIFileSystem::WriteFile(char const __near *,char const __near *,class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CBaseVMPIFileSystem::WriteFile(
        CBaseVMPIFileSystem *this,
        const char *pFileName,
        const char *pPath,
        CUtlBuffer *buf)
{
  const char *v5; // eax
  int v6; // edi
  int v8; // ebx

  v5 = "wt";
  if ( (buf->m_Flags & 1) == 0 )
    v5 = "wb";
  v6 = ((int (__thiscall *)(CBaseVMPIFileSystem *, const char *, const char *, const char *))this->QueryInterface)(
         a1: this,
         a2: pFileName,
         a3: v5,
         a4: pPath);
  if ( v6 == 0 )
    return false;
  v8 = ((int (__thiscall *)(CBaseVMPIFileSystem *, unsigned __int8 *, int, int))this->Disconnect)(
         a1: this,
         a2: buf->m_Memory.m_pMemory,
         a3: buf->m_nMaxPut,
         a4: v6);
  ((void (__thiscall *)(CBaseVMPIFileSystem *, int))this->Init)(a1: this, a2: v6);
  return v8 != 0;
}

} // namespace texturecompile_dll

// ============================================================
// Overlay from vrad_dll (Missing functions)
// ============================================================
namespace vrad_dll {

//------------------------------------------------------------------------------
// Address: 0x10089D90
// Name: void __near * GetVMPIFileSystem(void)
// Source: json
//------------------------------------------------------------------------------
IBaseFileSystem *__cdecl GetVMPIFileSystem()
{
  if ( g_pBaseVMPIFileSystem != nullptr )
    return &g_pBaseVMPIFileSystem->IBaseFileSystem;
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10089DA0
// Name: void __near * GetFullFileSystem(void)
// Source: json
//------------------------------------------------------------------------------
IFileSystem *__cdecl GetFullFileSystem()
{
  return g_pOriginalPassThruFileSystem;
}

//------------------------------------------------------------------------------
// Address: 0x10089DB0
// Name: class IFileSystem __near * VMPI_FileSystem_Init(int,class IFileSystem __near *)
// Source: json
//------------------------------------------------------------------------------
CBaseVMPIFileSystem *__cdecl VMPI_FileSystem_Init(int maxMemoryUsage, IFileSystem *pPassThru)
{
  g_pOriginalPassThruFileSystem = pPassThru;
  if ( g_bMPIMaster )
    CreateMasterVMPIFileSystem(maxMemoryUsage, pPassThru);
  else
    CreateWorkerVMPIFileSystem();
  return g_pBaseVMPIFileSystem;
}

//------------------------------------------------------------------------------
// Address: 0x10089DF0
// Name: class IFileSystem __near * VMPI_FileSystem_Term(void)
// Source: json
//------------------------------------------------------------------------------
IFileSystem *__cdecl VMPI_FileSystem_Term()
{
  IFileSystem *result; // eax

  if ( g_pBaseVMPIFileSystem != nullptr )
  {
    g_pBaseVMPIFileSystem->Release(this: g_pBaseVMPIFileSystem);
    g_pBaseVMPIFileSystem = nullptr;
    if ( g_iVMPIVerboseLevel >= 1 )
    {
      if ( g_bMPIMaster )
        _Msg(a1: "Multicast send: %dk\n", (g_nMulticastBytesSent + 511) / 1024);
      else
        _Msg(a1: "Multicast recv: %dk\n", (g_nMulticastBytesReceived + 511) / 1024);
    }
  }
  result = g_pOriginalPassThruFileSystem;
  g_pOriginalPassThruFileSystem = nullptr;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10089E80
// Name: void VMPI_FileSystem_CreateVirtualFile(char const __near *,void const __near *,unsigned long)
// Source: json
//------------------------------------------------------------------------------
void __cdecl VMPI_FileSystem_CreateVirtualFile(const char *pFilename, const void *pData, unsigned int fileLength)
{
  g_pBaseVMPIFileSystem->CreateVirtualFile(this: g_pBaseVMPIFileSystem, a2: pFilename, a3: pData, a4: fileLength);
}

//------------------------------------------------------------------------------
// Address: 0x10089EB0
// Name: bool FileSystemRecv(class MessageBuffer __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl FileSystemRecv(MessageBuffer *pBuf, int iSource, int iPacketID)
{
  return g_pBaseVMPIFileSystem != nullptr
      && g_pBaseVMPIFileSystem->HandleFileSystemPacket(
           this: g_pBaseVMPIFileSystem,
           a2: pBuf,
           a3: iSource,
           a4: iPacketID);
}

//------------------------------------------------------------------------------
// Address: 0x10089EE0
// Name: public: void CVMPIFile_Memory::Init(char const __near *,long,char)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVMPIFile_Memory::Init(CVMPIFile_Memory *this, const char *pData, int len, char chMode)
{
  this->m_pData = pData;
  this->m_DataLen = len;
  this->m_iCurPos = 0;
  this->m_chMode = chMode;
}

//------------------------------------------------------------------------------
// Address: 0x10089F10
// Name: public: virtual void CVMPIFile_Memory::Seek(int,enum FileSystemSeek_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVMPIFile_Memory::Seek(CVMPIFile_Memory *this, int pos, FileSystemSeek_t seekType)
{
  if ( seekType != FILESYSTEM_SEEK_HEAD )
  {
    if ( seekType == FILESYSTEM_SEEK_CURRENT )
      this->m_iCurPos += pos;
    else
      this->m_iCurPos = this->m_DataLen - pos;
  }
  else
  {
    this->m_iCurPos = pos;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10089F40
// Name: public: virtual int CVMPIFile_Memory::Read(void __near *,int)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CVMPIFile_Memory::Read(CVMPIFile_Memory *this, unsigned __int8 *pOutput, int size)
{
  int m_iCurPos; // ecx
  unsigned int v5; // esi
  signed int v6; // eax
  signed int v8; // edi
  unsigned __int8 *v9; // esi
  int v10; // eax
  unsigned int v11; // edi
  int v12; // eax
  unsigned __int8 *v13; // ecx
  int v14; // eax
  int iRead; // [esp+8h] [ebp-8h]
  int len; // [esp+Ch] [ebp-4h]
  int lena; // [esp+Ch] [ebp-4h]

  m_iCurPos = this->m_iCurPos;
  v5 = size;
  v6 = this->m_DataLen - m_iCurPos;
  if ( v6 < size )
    v5 = this->m_DataLen - m_iCurPos;
  if ( this->m_chMode == 116 )
  {
    v8 = this->m_DataLen - m_iCurPos;
    v9 = (unsigned __int8 *)&this->m_pData[m_iCurPos];
    iRead = 0;
    len = v8;
    memchr(buf: v9, chr: 0xDu, cnt: v6);
    if ( v10 != 0 )
    {
      while ( 1 )
      {
        v11 = size;
        v12 = v10 - (_DWORD)v9;
        if ( size >= v12 )
          v11 = v12;
        memcpy(dst: pOutput, src: v9, count: v11);
        this->m_iCurPos += v11;
        lena = len - v11;
        iRead += v11;
        v9 += v11;
        v13 = &pOutput[v11];
        size -= v11;
        if ( size == 0 )
          break;
        if ( lena == 0 )
        {
          v8 = 0;
          goto LABEL_16;
        }
        v14 = lena;
        if ( lena > 1 && v9[1] == 10 )
        {
          ++v9;
          ++this->m_iCurPos;
          v14 = lena - 1;
        }
        ++iRead;
        --size;
        *v13 = *v9;
        ++this->m_iCurPos;
        ++v9;
        len = v14 - 1;
        pOutput = v13 + 1;
        memchr(buf: v9, chr: 0xDu, cnt: v14 - 1);
        if ( v10 == 0 )
        {
          v8 = len;
          goto LABEL_15;
        }
      }
    }
    else
    {
LABEL_15:
      v13 = pOutput;
LABEL_16:
      if ( size != 0 && v8 != 0 )
      {
        if ( size < v8 )
          v8 = size;
        memcpy(dst: v13, src: v9, count: v8);
        this->m_iCurPos += v8;
        iRead += v8;
      }
    }
    return iRead;
  }
  else
  {
    memcpy(dst: pOutput, src: (unsigned __int8 *)&this->m_pData[m_iCurPos], count: v5);
    this->m_iCurPos += v5;
    return v5;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1008A060
// Name: public: virtual int CVMPIFile_Memory::Write(void const __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CVMPIFile_Memory::Write(CVMPIFile_Memory *this, const void *pInput, const void *size)
{
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1008A070
// Name: public: virtual CBaseVMPIFileSystem::~CBaseVMPIFileSystem(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseVMPIFileSystem::~CBaseVMPIFileSystem(CBaseVMPIFileSystem *this)
{
  this->CFileSystemPassThru::CInternalFileSystemPassThru<IFileSystem>::IFileSystem::IAppSystem::__vftable = (CBaseVMPIFileSystem_vtbl *)&CBaseVMPIFileSystem::`vftable'{for `IAppSystem'};
  this->CFileSystemPassThru::CInternalFileSystemPassThru<IFileSystem>::IFileSystem::IBaseFileSystem::__vftable = (IBaseFileSystem_vtbl *)&CBaseVMPIFileSystem::`vftable'{for `IBaseFileSystem'};
}

//------------------------------------------------------------------------------
// Address: 0x1008A080
// Name: public: virtual bool CFileSystemPassThru::Connect(void __near * (*)(char const __near *,int __near *))
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CFileSystemPassThru::Connect(CFileSystemPassThru *this, void *(__cdecl *factory)(const char *, int *))
{
  return this->m_pFileSystemPassThru->Connect(this: this->m_pFileSystemPassThru, a2: factory);
}

//------------------------------------------------------------------------------
// Address: 0x1008A090
// Name: public: virtual void CFileSystemPassThru::Disconnect(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFileSystemPassThru::Disconnect(CFileSystemPassThru *this)
{
  this->m_pFileSystemPassThru->Disconnect(this: this->m_pFileSystemPassThru);
}

//------------------------------------------------------------------------------
// Address: 0x1008A0A0
// Name: public: virtual void __near * CFileSystemPassThru::QueryInterface(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void *__thiscall CFileSystemPassThru::QueryInterface(CFileSystemPassThru *this, const char *pInterfaceName)
{
  return this->m_pFileSystemPassThru->QueryInterface(this: this->m_pFileSystemPassThru, a2: pInterfaceName);
}

//------------------------------------------------------------------------------
// Address: 0x1008A0B0
// Name: public: virtual enum InitReturnVal_t CFileSystemPassThru::Init(void)
// Source: json
//------------------------------------------------------------------------------
InitReturnVal_t __thiscall CFileSystemPassThru::Init(CFileSystemPassThru *this)
{
  return this->m_pFileSystemPassThru->Init(this: this->m_pFileSystemPassThru);
}

//------------------------------------------------------------------------------
// Address: 0x1008A0C0
// Name: public: virtual void CFileSystemPassThru::Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFileSystemPassThru::Shutdown(CFileSystemPassThru *this)
{
  this->m_pFileSystemPassThru->Shutdown(this: this->m_pFileSystemPassThru);
}

//------------------------------------------------------------------------------
// Address: 0x1008A0D0
// Name: public: virtual struct AppSystemInfo_t const __near * CFileSystemPassThru::GetDependencies(void)
// Source: json
//------------------------------------------------------------------------------
const AppSystemInfo_t *__thiscall CFileSystemPassThru::GetDependencies(CFileSystemPassThru *this)
{
  return this->m_pFileSystemPassThru->GetDependencies(this: this->m_pFileSystemPassThru);
}

//------------------------------------------------------------------------------
// Address: 0x1008A0E0
// Name: public: virtual enum AppSystemTier_t CFileSystemPassThru::GetTier(void)
// Source: json
//------------------------------------------------------------------------------
AppSystemTier_t __thiscall CFileSystemPassThru::GetTier(CFileSystemPassThru *this)
{
  return this->m_pFileSystemPassThru->GetTier(this: this->m_pFileSystemPassThru);
}

//------------------------------------------------------------------------------
// Address: 0x1008A0F0
// Name: public: virtual void CFileSystemPassThru::Reconnect(void __near * (*)(char const __near *,int __near *),char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFileSystemPassThru::Reconnect(
        CFileSystemPassThru *this,
        void *(__cdecl *factory)(const char *, int *),
        const char *pInterfaceName)
{
  this->m_pFileSystemPassThru->Reconnect(this: this->m_pFileSystemPassThru, a2: factory, a3: pInterfaceName);
}

//------------------------------------------------------------------------------
// Address: 0x1008A100
// Name: public: virtual void CFileSystemPassThru::RemoveAllSearchPaths(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFileSystemPassThru::RemoveAllSearchPaths(CFileSystemPassThru *this)
{
  this->m_pFileSystemPassThru->RemoveAllSearchPaths(this: this->m_pFileSystemPassThru);
}

//------------------------------------------------------------------------------
// Address: 0x1008A110
// Name: public: virtual void CFileSystemPassThru::AddSearchPath(char const __near *,char const __near *,enum SearchPathAdd_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFileSystemPassThru::AddSearchPath(
        CFileSystemPassThru *this,
        const char *pPath,
        const char *pathID,
        SearchPathAdd_t addType)
{
  this->m_pFileSystemPassThru->AddSearchPath(this: this->m_pFileSystemPassThru, a2: pPath, a3: pathID, a4: addType);
}

//------------------------------------------------------------------------------
// Address: 0x1008A120
// Name: public: virtual bool CFileSystemPassThru::RemoveSearchPath(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CFileSystemPassThru::RemoveSearchPath(CFileSystemPassThru *this, const char *pPath, const char *pathID)
{
  return this->m_pFileSystemPassThru->RemoveSearchPath(this: this->m_pFileSystemPassThru, a2: pPath, a3: pathID);
}

//------------------------------------------------------------------------------
// Address: 0x1008A130
// Name: public: virtual void CFileSystemPassThru::RemoveFile(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFileSystemPassThru::RemoveFile(
        CFileSystemPassThru *this,
        const char *pRelativePath,
        const char *pathID)
{
  this->m_pFileSystemPassThru->RemoveFile(this: this->m_pFileSystemPassThru, a2: pRelativePath, a3: pathID);
}

//------------------------------------------------------------------------------
// Address: 0x1008A140
// Name: public: virtual bool CFileSystemPassThru::RenameFile(char const __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CFileSystemPassThru::RenameFile(
        CFileSystemPassThru *this,
        const char *pOldPath,
        const char *pNewPath,
        const char *pathID)
{
  return this->m_pFileSystemPassThru->RenameFile(
           this: this->m_pFileSystemPassThru,
           a2: pOldPath,
           a3: pNewPath,
           a4: pathID);
}

//------------------------------------------------------------------------------
// Address: 0x1008A150
// Name: public: virtual void CFileSystemPassThru::CreateDirHierarchy(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFileSystemPassThru::CreateDirHierarchy(
        CFileSystemPassThru *this,
        const char *path,
        const char *pathID)
{
  this->m_pFileSystemPassThru->CreateDirHierarchy(this: this->m_pFileSystemPassThru, a2: path, a3: pathID);
}

//------------------------------------------------------------------------------
// Address: 0x1008A160
// Name: public: virtual bool CFileSystemPassThru::IsDirectory(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CFileSystemPassThru::IsDirectory(CFileSystemPassThru *this, const char *pFileName, const char *pathID)
{
  return this->m_pFileSystemPassThru->IsDirectory(this: this->m_pFileSystemPassThru, a2: pFileName, a3: pathID);
}

//------------------------------------------------------------------------------
// Address: 0x1008A170
// Name: public: virtual void CFileSystemPassThru::FileTimeToString(char __near *,int,long)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFileSystemPassThru::FileTimeToString(
        CFileSystemPassThru *this,
        char *pStrip,
        int maxCharsIncludingTerminator,
        int fileTime)
{
  this->m_pFileSystemPassThru->FileTimeToString(
    this: this->m_pFileSystemPassThru,
    a2: pStrip,
    a3: maxCharsIncludingTerminator,
    a4: fileTime);
}

//------------------------------------------------------------------------------
// Address: 0x1008A180
// Name: public: virtual void CFileSystemPassThru::SetBufferSize(void __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFileSystemPassThru::SetBufferSize(CFileSystemPassThru *this, void *file, unsigned int nBytes)
{
  this->m_pFileSystemPassThru->SetBufferSize(this: this->m_pFileSystemPassThru, a2: file, a3: nBytes);
}

//------------------------------------------------------------------------------
// Address: 0x1008A190
// Name: public: virtual bool CFileSystemPassThru::IsOk(void __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CFileSystemPassThru::IsOk(CFileSystemPassThru *this, void *file)
{
  return this->m_pFileSystemPassThru->IsOk(this: this->m_pFileSystemPassThru, a2: file);
}

//------------------------------------------------------------------------------
// Address: 0x1008A1A0
// Name: public: virtual bool CFileSystemPassThru::EndOfFile(void __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CFileSystemPassThru::EndOfFile(CFileSystemPassThru *this, void *file)
{
  return this->m_pFileSystemPassThru->EndOfFile(this: this->m_pFileSystemPassThru, a2: file);
}

//------------------------------------------------------------------------------
// Address: 0x1008A1B0
// Name: public: virtual char __near * CFileSystemPassThru::ReadLine(char __near *,int,void __near *)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CFileSystemPassThru::ReadLine(CFileSystemPassThru *this, char *pOutput, int maxChars, void *file)
{
  return this->m_pFileSystemPassThru->ReadLine(this: this->m_pFileSystemPassThru, a2: pOutput, a3: maxChars, a4: file);
}

//------------------------------------------------------------------------------
// Address: 0x1008A1C0
// Name: public: virtual int CFileSystemPassThru::FPrintf(void __near *,char const __near *,...)
// Source: json
//------------------------------------------------------------------------------
int CFileSystemPassThru::FPrintf(CFileSystemPassThru *this, void *file, char *pFormat, ...)
{
  char string[8192]; // [esp+0h] [ebp-2000h] BYREF
  va_list ap; // [esp+2014h] [ebp+14h] BYREF

  va_start(ap, pFormat);
  _vsnprintf(string, count: 0x2000u, format: pFormat, ap);
  return this->m_pFileSystemPassThru->FPrintf(this: this->m_pFileSystemPassThru, a2: file, a3: "%s", string);
}

//------------------------------------------------------------------------------
// Address: 0x1008A210
// Name: public: virtual class CSysModule __near * CFileSystemPassThru::LoadModule(char const __near *,char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
struct CSysModule *__thiscall CFileSystemPassThru::LoadModule(
        CFileSystemPassThru *this,
        const char *pFileName,
        const char *pPathID,
        BOOL bValidatedDllOnly)
{
  return this->m_pFileSystemPassThru->LoadModule(
           this: this->m_pFileSystemPassThru,
           a2: pFileName,
           a3: pPathID,
           a4: bValidatedDllOnly);
}

//------------------------------------------------------------------------------
// Address: 0x1008A220
// Name: public: virtual void CFileSystemPassThru::UnloadModule(class CSysModule __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFileSystemPassThru::UnloadModule(CFileSystemPassThru *this, struct CSysModule *pModule)
{
  this->m_pFileSystemPassThru->UnloadModule(this: this->m_pFileSystemPassThru, a2: pModule);
}

//------------------------------------------------------------------------------
// Address: 0x1008A230
// Name: public: virtual char const __near * CFileSystemPassThru::FindFirst(char const __near *,int __near *)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CFileSystemPassThru::FindFirst(CFileSystemPassThru *this, const char *pWildCard, int *pHandle)
{
  return this->m_pFileSystemPassThru->FindFirst(this: this->m_pFileSystemPassThru, a2: pWildCard, a3: pHandle);
}

//------------------------------------------------------------------------------
// Address: 0x1008A240
// Name: public: virtual char const __near * CFileSystemPassThru::FindNext(int)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CFileSystemPassThru::FindNext(CFileSystemPassThru *this, int handle)
{
  return this->m_pFileSystemPassThru->FindNext(this: this->m_pFileSystemPassThru, a2: handle);
}

//------------------------------------------------------------------------------
// Address: 0x1008A250
// Name: public: virtual bool CFileSystemPassThru::FindIsDirectory(int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CFileSystemPassThru::FindIsDirectory(CFileSystemPassThru *this, int handle)
{
  return this->m_pFileSystemPassThru->FindIsDirectory(this: this->m_pFileSystemPassThru, a2: handle);
}

//------------------------------------------------------------------------------
// Address: 0x1008A270
// Name: public: virtual void CFileSystemPassThru::FindClose(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFileSystemPassThru::FindClose(CFileSystemPassThru *this, int handle)
{
  this->m_pFileSystemPassThru->FindClose(this: this->m_pFileSystemPassThru, a2: handle);
}

//------------------------------------------------------------------------------
// Address: 0x1008A290
// Name: public: virtual void CFileSystemPassThru::FindFileAbsoluteList(class CUtlVector<class CUtlString,class CUtlMemory<class CUtlString,int>> __near &,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFileSystemPassThru::FindFileAbsoluteList(
        CFileSystemPassThru *this,
        CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *outAbsolutePathNames,
        const char *pWildCard,
        const char *pPathID)
{
  this->m_pFileSystemPassThru->FindFileAbsoluteList(
    this: this->m_pFileSystemPassThru,
    a2: outAbsolutePathNames,
    a3: pWildCard,
    a4: pPathID);
}

//------------------------------------------------------------------------------
// Address: 0x1008A2B0
// Name: public: virtual char const __near * CFileSystemPassThru::GetLocalPath(char const __near *,char __near *,int)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CFileSystemPassThru::GetLocalPath(
        CFileSystemPassThru *this,
        const char *pFileName,
        char *pLocalPath,
        int localPathBufferSize)
{
  return this->m_pFileSystemPassThru->GetLocalPath(
           this: this->m_pFileSystemPassThru,
           a2: pFileName,
           a3: pLocalPath,
           a4: localPathBufferSize);
}

//------------------------------------------------------------------------------
// Address: 0x1008A2D0
// Name: public: virtual bool CFileSystemPassThru::FullPathToRelativePath(char const __near *,char __near *,int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CFileSystemPassThru::FullPathToRelativePath(
        CFileSystemPassThru *this,
        const char *pFullpath,
        char *pRelative,
        int maxlen)
{
  return this->m_pFileSystemPassThru->FullPathToRelativePath(
           this: this->m_pFileSystemPassThru,
           a2: pFullpath,
           a3: pRelative,
           a4: maxlen);
}

//------------------------------------------------------------------------------
// Address: 0x1008A2F0
// Name: public: virtual void CFileSystemPassThru::PrintOpenedFiles(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFileSystemPassThru::PrintOpenedFiles(CFileSystemPassThru *this)
{
  this->m_pFileSystemPassThru->PrintOpenedFiles(this: this->m_pFileSystemPassThru);
}

//------------------------------------------------------------------------------
// Address: 0x1008A300
// Name: public: virtual void CFileSystemPassThru::PrintSearchPaths(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFileSystemPassThru::PrintSearchPaths(CFileSystemPassThru *this)
{
  this->m_pFileSystemPassThru->PrintSearchPaths(this: this->m_pFileSystemPassThru);
}

//------------------------------------------------------------------------------
// Address: 0x1008A310
// Name: public: virtual void CFileSystemPassThru::SetWarningFunc(void (*)(char const __near *,...))
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFileSystemPassThru::SetWarningFunc(CFileSystemPassThru *this, void (*pfnWarning)(const char *, ...))
{
  this->m_pFileSystemPassThru->SetWarningFunc(this: this->m_pFileSystemPassThru, a2: pfnWarning);
}

//------------------------------------------------------------------------------
// Address: 0x1008A330
// Name: public: virtual void CFileSystemPassThru::SetWarningLevel(enum FileWarningLevel_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFileSystemPassThru::SetWarningLevel(CFileSystemPassThru *this, FileWarningLevel_t level)
{
  this->m_pFileSystemPassThru->SetWarningLevel(this: this->m_pFileSystemPassThru, a2: level);
}

//------------------------------------------------------------------------------
// Address: 0x1008A350
// Name: public: virtual void CFileSystemPassThru::AddLoggingFunc(void (*)(char const __near *,char const __near *))
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFileSystemPassThru::AddLoggingFunc(
        CFileSystemPassThru *this,
        void (__cdecl *pfnLogFunc)(const char *, const char *))
{
  this->m_pFileSystemPassThru->AddLoggingFunc(this: this->m_pFileSystemPassThru, a2: pfnLogFunc);
}

//------------------------------------------------------------------------------
// Address: 0x1008A370
// Name: public: virtual void CFileSystemPassThru::RemoveLoggingFunc(void (*)(char const __near *,char const __near *))
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFileSystemPassThru::RemoveLoggingFunc(
        CFileSystemPassThru *this,
        void (__cdecl *logFunc)(const char *, const char *))
{
  this->m_pFileSystemPassThru->RemoveLoggingFunc(this: this->m_pFileSystemPassThru, a2: logFunc);
}

//------------------------------------------------------------------------------
// Address: 0x1008A390
// Name: public: virtual enum FSAsyncStatus_t CFileSystemPassThru::AsyncReadMultiple(struct FileAsyncRequest_t const __near *,int,struct FSAsyncControl_t__ __near * __near *)
// Source: json
//------------------------------------------------------------------------------
FSAsyncStatus_t __thiscall CFileSystemPassThru::AsyncReadMultiple(
        CFileSystemPassThru *this,
        const FileAsyncRequest_t *pRequests,
        int nRequests,
        FSAsyncControl_t__ **pControls)
{
  return this->m_pFileSystemPassThru->AsyncReadMultiple(
           this: this->m_pFileSystemPassThru,
           a2: pRequests,
           a3: nRequests,
           a4: pControls);
}

//------------------------------------------------------------------------------
// Address: 0x1008A3B0
// Name: public: virtual enum FSAsyncStatus_t CFileSystemPassThru::AsyncReadMultipleCreditAlloc(struct FileAsyncRequest_t const __near *,int,char const __near *,int,struct FSAsyncControl_t__ __near * __near *)
// Source: json
//------------------------------------------------------------------------------
FSAsyncStatus_t __thiscall CFileSystemPassThru::AsyncReadMultipleCreditAlloc(
        CFileSystemPassThru *this,
        const FileAsyncRequest_t *pRequests,
        int nRequests,
        const char *pszFile,
        int line,
        FSAsyncControl_t__ **pControls)
{
  return this->m_pFileSystemPassThru->AsyncReadMultipleCreditAlloc(
           this: this->m_pFileSystemPassThru,
           a2: pRequests,
           a3: nRequests,
           a4: pszFile,
           a5: line,
           a6: pControls);
}

//------------------------------------------------------------------------------
// Address: 0x1008A3D0
// Name: public: virtual enum FSAsyncStatus_t CFileSystemPassThru::AsyncDirectoryScan(char const __near *,bool,void __near *,void (*)(void __near *,char __near *,char __near *),void (*)(void __near *,enum FSAsyncStatus_t),struct FSAsyncControl_t__ __near * __near *)
// Source: json
//------------------------------------------------------------------------------
FSAsyncStatus_t __thiscall CFileSystemPassThru::AsyncDirectoryScan(
        CFileSystemPassThru *this,
        const char *pSearchSpec,
        BOOL recurseFolders,
        void *pContext,
        void (__cdecl *pfnAdd)(void *, char *, char *),
        void (__cdecl *pfnDone)(void *, FSAsyncStatus_t),
        FSAsyncControl_t__ **pControl)
{
  return this->m_pFileSystemPassThru->AsyncDirectoryScan(
           this: this->m_pFileSystemPassThru,
           a2: pSearchSpec,
           a3: recurseFolders,
           a4: pContext,
           a5: pfnAdd,
           a6: pfnDone,
           a7: pControl);
}

//------------------------------------------------------------------------------
// Address: 0x1008A3F0
// Name: public: virtual enum FSAsyncStatus_t CFileSystemPassThru::AsyncFinish(struct FSAsyncControl_t__ __near *,bool)
// Source: json
//------------------------------------------------------------------------------
FSAsyncStatus_t __thiscall CFileSystemPassThru::AsyncFinish(
        CFileSystemPassThru *this,
        FSAsyncControl_t__ *hControl,
        BOOL wait)
{
  return this->m_pFileSystemPassThru->AsyncFinish(this: this->m_pFileSystemPassThru, a2: hControl, a3: wait);
}

//------------------------------------------------------------------------------
// Address: 0x1008A410
// Name: public: virtual enum FSAsyncStatus_t CFileSystemPassThru::AsyncGetResult(struct FSAsyncControl_t__ __near *,void __near * __near *,int __near *)
// Source: json
//------------------------------------------------------------------------------
FSAsyncStatus_t __thiscall CFileSystemPassThru::AsyncGetResult(
        CFileSystemPassThru *this,
        FSAsyncControl_t__ *hControl,
        void **ppData,
        int *pSize)
{
  return this->m_pFileSystemPassThru->AsyncGetResult(
           this: this->m_pFileSystemPassThru,
           a2: hControl,
           a3: ppData,
           a4: pSize);
}

//------------------------------------------------------------------------------
// Address: 0x1008A430
// Name: public: virtual enum FSAsyncStatus_t CFileSystemPassThru::AsyncAbort(struct FSAsyncControl_t__ __near *)
// Source: json
//------------------------------------------------------------------------------
FSAsyncStatus_t __thiscall CFileSystemPassThru::AsyncAbort(CFileSystemPassThru *this, FSAsyncControl_t__ *hControl)
{
  return this->m_pFileSystemPassThru->AsyncAbort(this: this->m_pFileSystemPassThru, a2: hControl);
}

//------------------------------------------------------------------------------
// Address: 0x1008A450
// Name: public: virtual enum FSAsyncStatus_t CFileSystemPassThru::AsyncStatus(struct FSAsyncControl_t__ __near *)
// Source: json
//------------------------------------------------------------------------------
FSAsyncStatus_t __thiscall CFileSystemPassThru::AsyncStatus(CFileSystemPassThru *this, FSAsyncControl_t__ *hControl)
{
  return this->m_pFileSystemPassThru->AsyncStatus(this: this->m_pFileSystemPassThru, a2: hControl);
}

//------------------------------------------------------------------------------
// Address: 0x1008A470
// Name: public: virtual enum FSAsyncStatus_t CFileSystemPassThru::AsyncFlush(void)
// Source: json
//------------------------------------------------------------------------------
FSAsyncStatus_t __thiscall CFileSystemPassThru::AsyncFlush(CFileSystemPassThru *this)
{
  return this->m_pFileSystemPassThru->AsyncFlush(this: this->m_pFileSystemPassThru);
}

//------------------------------------------------------------------------------
// Address: 0x1008A480
// Name: public: virtual void CFileSystemPassThru::AsyncAddRef(struct FSAsyncControl_t__ __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFileSystemPassThru::AsyncAddRef(CFileSystemPassThru *this, FSAsyncControl_t__ *hControl)
{
  this->m_pFileSystemPassThru->AsyncAddRef(this: this->m_pFileSystemPassThru, a2: hControl);
}

//------------------------------------------------------------------------------
// Address: 0x1008A4A0
// Name: public: virtual void CFileSystemPassThru::AsyncRelease(struct FSAsyncControl_t__ __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFileSystemPassThru::AsyncRelease(CFileSystemPassThru *this, FSAsyncControl_t__ *hControl)
{
  this->m_pFileSystemPassThru->AsyncRelease(this: this->m_pFileSystemPassThru, a2: hControl);
}

//------------------------------------------------------------------------------
// Address: 0x1008A4C0
// Name: public: virtual enum FSAsyncStatus_t CFileSystemPassThru::AsyncBeginRead(char const __near *,struct FSAsyncFile_t__ __near * __near *)
// Source: json
//------------------------------------------------------------------------------
FSAsyncStatus_t __thiscall CFileSystemPassThru::AsyncBeginRead(
        CFileSystemPassThru *this,
        const char *pszFile,
        FSAsyncFile_t__ **phFile)
{
  return this->m_pFileSystemPassThru->AsyncBeginRead(this: this->m_pFileSystemPassThru, a2: pszFile, a3: phFile);
}

//------------------------------------------------------------------------------
// Address: 0x1008A4E0
// Name: public: virtual enum FSAsyncStatus_t CFileSystemPassThru::AsyncEndRead(struct FSAsyncFile_t__ __near *)
// Source: json
//------------------------------------------------------------------------------
FSAsyncStatus_t __thiscall CFileSystemPassThru::AsyncEndRead(CFileSystemPassThru *this, FSAsyncFile_t__ *hFile)
{
  return this->m_pFileSystemPassThru->AsyncEndRead(this: this->m_pFileSystemPassThru, a2: hFile);
}

//------------------------------------------------------------------------------
// Address: 0x1008A500
// Name: public: virtual struct FileSystemStatistics const __near * CFileSystemPassThru::GetFilesystemStatistics(void)
// Source: json
//------------------------------------------------------------------------------
const FileSystemStatistics *__thiscall CFileSystemPassThru::GetFilesystemStatistics(CFileSystemPassThru *this)
{
  return this->m_pFileSystemPassThru->GetFilesystemStatistics(this: this->m_pFileSystemPassThru);
}

//------------------------------------------------------------------------------
// Address: 0x1008A510
// Name: public: virtual int CFileSystemPassThru::WaitForResources(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CFileSystemPassThru::WaitForResources(CFileSystemPassThru *this, const char *resourcelist)
{
  return this->m_pFileSystemPassThru->WaitForResources(this: this->m_pFileSystemPassThru, a2: resourcelist);
}

//------------------------------------------------------------------------------
// Address: 0x1008A530
// Name: public: virtual bool CFileSystemPassThru::GetWaitForResourcesProgress(int,float __near *,bool __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CFileSystemPassThru::GetWaitForResourcesProgress(
        CFileSystemPassThru *this,
        int handle,
        float *progress,
        bool *complete)
{
  return this->m_pFileSystemPassThru->GetWaitForResourcesProgress(
           this: this->m_pFileSystemPassThru,
           a2: handle,
           a3: progress,
           a4: complete);
}

//------------------------------------------------------------------------------
// Address: 0x1008A550
// Name: public: virtual void CFileSystemPassThru::CancelWaitForResources(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFileSystemPassThru::CancelWaitForResources(CFileSystemPassThru *this, int handle)
{
  this->m_pFileSystemPassThru->CancelWaitForResources(this: this->m_pFileSystemPassThru, a2: handle);
}

//------------------------------------------------------------------------------
// Address: 0x1008A570
// Name: public: virtual int CFileSystemPassThru::HintResourceNeed(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CFileSystemPassThru::HintResourceNeed(
        CFileSystemPassThru *this,
        const char *hintlist,
        int forgetEverything)
{
  return this->m_pFileSystemPassThru->HintResourceNeed(
           this: this->m_pFileSystemPassThru,
           a2: hintlist,
           a3: forgetEverything);
}

//------------------------------------------------------------------------------
// Address: 0x1008A590
// Name: public: virtual bool CFileSystemPassThru::IsFileImmediatelyAvailable(char const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CFileSystemPassThru::IsFileImmediatelyAvailable(CFileSystemPassThru *this, const char *pFileName)
{
  return this->m_pFileSystemPassThru->IsFileImmediatelyAvailable(this: this->m_pFileSystemPassThru, a2: pFileName);
}

//------------------------------------------------------------------------------
// Address: 0x1008A5B0
// Name: public: virtual void CFileSystemPassThru::GetLocalCopy(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFileSystemPassThru::GetLocalCopy(CFileSystemPassThru *this, const char *pFileName)
{
  this->m_pFileSystemPassThru->GetLocalCopy(this: this->m_pFileSystemPassThru, a2: pFileName);
}

//------------------------------------------------------------------------------
// Address: 0x1008A5D0
// Name: public: virtual void __near * CFileSystemPassThru::FindOrAddFileName(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void *__thiscall CFileSystemPassThru::FindOrAddFileName(CFileSystemPassThru *this, const char *pFileName)
{
  return this->m_pFileSystemPassThru->FindOrAddFileName(this: this->m_pFileSystemPassThru, a2: pFileName);
}

//------------------------------------------------------------------------------
// Address: 0x1008A5F0
// Name: public: virtual void __near * CFileSystemPassThru::FindFileName(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void *__thiscall CFileSystemPassThru::FindFileName(CFileSystemPassThru *this, const char *pFileName)
{
  return this->m_pFileSystemPassThru->FindFileName(this: this->m_pFileSystemPassThru, a2: pFileName);
}

//------------------------------------------------------------------------------
// Address: 0x1008A610
// Name: public: virtual bool CFileSystemPassThru::String(void __near * const __near &,char __near *,int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CFileSystemPassThru::String(CFileSystemPassThru *this, void *const *handle, char *buf, int buflen)
{
  return this->m_pFileSystemPassThru->String(this: this->m_pFileSystemPassThru, a2: handle, a3: buf, a4: buflen);
}

//------------------------------------------------------------------------------
// Address: 0x1008A630
// Name: public: virtual bool CFileSystemPassThru::IsOk2(void __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CFileSystemPassThru::IsOk2(CFileSystemPassThru *this, void *file)
{
  return this->IsOk(this, a2: file);
}

//------------------------------------------------------------------------------
// Address: 0x1008A640
// Name: public: virtual void CFileSystemPassThru::RemoveSearchPaths(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFileSystemPassThru::RemoveSearchPaths(CFileSystemPassThru *this, const char *szPathID)
{
  this->m_pFileSystemPassThru->RemoveSearchPaths(this: this->m_pFileSystemPassThru, a2: szPathID);
}

//------------------------------------------------------------------------------
// Address: 0x1008A650
// Name: public: virtual bool CFileSystemPassThru::IsSteam(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CFileSystemPassThru::IsSteam(CFileSystemPassThru *this)
{
  return this->m_pFileSystemPassThru->IsSteam(this: this->m_pFileSystemPassThru);
}

//------------------------------------------------------------------------------
// Address: 0x1008A660
// Name: public: virtual enum FilesystemMountRetval_t CFileSystemPassThru::MountSteamContent(int)
// Source: json
//------------------------------------------------------------------------------
FilesystemMountRetval_t __thiscall CFileSystemPassThru::MountSteamContent(CFileSystemPassThru *this, int nExtraAppId)
{
  return this->m_pFileSystemPassThru->MountSteamContent(this: this->m_pFileSystemPassThru, a2: nExtraAppId);
}

//------------------------------------------------------------------------------
// Address: 0x1008A670
// Name: public: virtual char const __near * CFileSystemPassThru::FindFirstEx(char const __near *,char const __near *,int __near *)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CFileSystemPassThru::FindFirstEx(
        CFileSystemPassThru *this,
        const char *pWildCard,
        const char *pPathID,
        int *pHandle)
{
  return this->m_pFileSystemPassThru->FindFirstEx(
           this: this->m_pFileSystemPassThru,
           a2: pWildCard,
           a3: pPathID,
           a4: pHandle);
}

//------------------------------------------------------------------------------
// Address: 0x1008A690
// Name: public: virtual void CFileSystemPassThru::MarkPathIDByRequestOnly(char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFileSystemPassThru::MarkPathIDByRequestOnly(
        CFileSystemPassThru *this,
        const char *pPathID,
        BOOL bRequestOnly)
{
  this->m_pFileSystemPassThru->MarkPathIDByRequestOnly(this: this->m_pFileSystemPassThru, a2: pPathID, a3: bRequestOnly);
}

//------------------------------------------------------------------------------
// Address: 0x1008A6A0
// Name: public: virtual bool CFileSystemPassThru::AddPackFile(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CFileSystemPassThru::AddPackFile(CFileSystemPassThru *this, const char *fullpath, const char *pathID)
{
  return this->m_pFileSystemPassThru->AddPackFile(this: this->m_pFileSystemPassThru, a2: fullpath, a3: pathID);
}

//------------------------------------------------------------------------------
// Address: 0x1008A6B0
// Name: public: virtual enum FSAsyncStatus_t CFileSystemPassThru::AsyncAppend(char const __near *,void const __near *,int,bool,struct FSAsyncControl_t__ __near * __near *)
// Source: json
//------------------------------------------------------------------------------
FSAsyncStatus_t __thiscall CFileSystemPassThru::AsyncAppend(
        CFileSystemPassThru *this,
        const char *pFileName,
        const void *pSrc,
        int nSrcBytes,
        BOOL bFreeMemory,
        FSAsyncControl_t__ **pControl)
{
  return this->m_pFileSystemPassThru->AsyncAppend(
           this: this->m_pFileSystemPassThru,
           a2: pFileName,
           a3: pSrc,
           a4: nSrcBytes,
           a5: bFreeMemory,
           a6: pControl);
}

//------------------------------------------------------------------------------
// Address: 0x1008A6D0
// Name: public: virtual enum FSAsyncStatus_t CFileSystemPassThru::AsyncWrite(char const __near *,void const __near *,int,bool,bool,struct FSAsyncControl_t__ __near * __near *)
// Source: json
//------------------------------------------------------------------------------
FSAsyncStatus_t __thiscall CFileSystemPassThru::AsyncWrite(
        CFileSystemPassThru *this,
        const char *pFileName,
        const void *pSrc,
        int nSrcBytes,
        BOOL bFreeMemory,
        BOOL bAppend,
        FSAsyncControl_t__ **pControl)
{
  return this->m_pFileSystemPassThru->AsyncWrite(
           this: this->m_pFileSystemPassThru,
           a2: pFileName,
           a3: pSrc,
           a4: nSrcBytes,
           a5: bFreeMemory,
           a6: bAppend,
           a7: pControl);
}

//------------------------------------------------------------------------------
// Address: 0x1008A6F0
// Name: public: virtual enum FSAsyncStatus_t CFileSystemPassThru::AsyncWriteFile(char const __near *,class CUtlBuffer const __near *,int,bool,bool,struct FSAsyncControl_t__ __near * __near *)
// Source: json
//------------------------------------------------------------------------------
FSAsyncStatus_t __thiscall CFileSystemPassThru::AsyncWriteFile(
        CFileSystemPassThru *this,
        const char *pFileName,
        const CUtlBuffer *pSrc,
        int nSrcBytes,
        BOOL bFreeMemory,
        BOOL bAppend,
        FSAsyncControl_t__ **pControl)
{
  return this->m_pFileSystemPassThru->AsyncWriteFile(
           this: this->m_pFileSystemPassThru,
           a2: pFileName,
           a3: pSrc,
           a4: nSrcBytes,
           a5: bFreeMemory,
           a6: bAppend,
           a7: pControl);
}

//------------------------------------------------------------------------------
// Address: 0x1008A710
// Name: public: virtual enum FSAsyncStatus_t CFileSystemPassThru::AsyncAppendFile(char const __near *,char const __near *,struct FSAsyncControl_t__ __near * __near *)
// Source: json
//------------------------------------------------------------------------------
FSAsyncStatus_t __thiscall CFileSystemPassThru::AsyncAppendFile(
        CFileSystemPassThru *this,
        const char *pDestFileName,
        const char *pSrcFileName,
        FSAsyncControl_t__ **pControl)
{
  return this->m_pFileSystemPassThru->AsyncAppendFile(
           this: this->m_pFileSystemPassThru,
           a2: pDestFileName,
           a3: pSrcFileName,
           a4: pControl);
}

//------------------------------------------------------------------------------
// Address: 0x1008A730
// Name: public: virtual void CFileSystemPassThru::AsyncFinishAll(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFileSystemPassThru::AsyncFinishAll(CFileSystemPassThru *this, int iToPriority)
{
  this->m_pFileSystemPassThru->AsyncFinishAll(this: this->m_pFileSystemPassThru, a2: iToPriority);
}

//------------------------------------------------------------------------------
// Address: 0x1008A750
// Name: public: virtual void CFileSystemPassThru::AsyncFinishAllWrites(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFileSystemPassThru::AsyncFinishAllWrites(CFileSystemPassThru *this)
{
  this->m_pFileSystemPassThru->AsyncFinishAllWrites(this: this->m_pFileSystemPassThru);
}

//------------------------------------------------------------------------------
// Address: 0x1008A760
// Name: public: virtual enum FSAsyncStatus_t CFileSystemPassThru::AsyncSetPriority(struct FSAsyncControl_t__ __near *,int)
// Source: json
//------------------------------------------------------------------------------
FSAsyncStatus_t __thiscall CFileSystemPassThru::AsyncSetPriority(
        CFileSystemPassThru *this,
        FSAsyncControl_t__ *hControl,
        int newPriority)
{
  return this->m_pFileSystemPassThru->AsyncSetPriority(this: this->m_pFileSystemPassThru, a2: hControl, a3: newPriority);
}

//------------------------------------------------------------------------------
// Address: 0x1008A780
// Name: public: virtual bool CFileSystemPassThru::AsyncSuspend(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CFileSystemPassThru::AsyncSuspend(CFileSystemPassThru *this)
{
  return this->m_pFileSystemPassThru->AsyncSuspend(this: this->m_pFileSystemPassThru);
}

//------------------------------------------------------------------------------
// Address: 0x1008A790
// Name: public: virtual bool CFileSystemPassThru::AsyncResume(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CFileSystemPassThru::AsyncResume(CFileSystemPassThru *this)
{
  return this->m_pFileSystemPassThru->AsyncResume(this: this->m_pFileSystemPassThru);
}

//------------------------------------------------------------------------------
// Address: 0x1008A7A0
// Name: public: virtual char const __near * CFileSystemPassThru::RelativePathToFullPath(char const __near *,char const __near *,char __near *,int,enum PathTypeFilter_t,unsigned int __near *)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CFileSystemPassThru::RelativePathToFullPath(
        CFileSystemPassThru *this,
        const char *pFileName,
        const char *pPathID,
        char *pLocalPath,
        int localPathBufferSize,
        PathTypeFilter_t pathFilter,
        unsigned int *pPathType)
{
  return this->m_pFileSystemPassThru->RelativePathToFullPath(
           this: this->m_pFileSystemPassThru,
           a2: pFileName,
           a3: pPathID,
           a4: pLocalPath,
           a5: localPathBufferSize,
           a6: pathFilter,
           a7: pPathType);
}

//------------------------------------------------------------------------------
// Address: 0x1008A7B0
// Name: public: virtual int CFileSystemPassThru::GetSearchPath(char const __near *,bool,char __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CFileSystemPassThru::GetSearchPath(
        CFileSystemPassThru *this,
        const char *pathID,
        BOOL bGetPackFiles,
        char *pPath,
        int nMaxLen)
{
  return this->m_pFileSystemPassThru->GetSearchPath(
           this: this->m_pFileSystemPassThru,
           a2: pathID,
           a3: bGetPackFiles,
           a4: pPath,
           a5: nMaxLen);
}

//------------------------------------------------------------------------------
// Address: 0x1008A7C0
// Name: public: virtual void __near * CFileSystemPassThru::OpenEx(char const __near *,char const __near *,unsigned int,char const __near *,char __near * __near *)
// Source: json
//------------------------------------------------------------------------------
void *__thiscall CFileSystemPassThru::OpenEx(
        CFileSystemPassThru *this,
        const char *pFileName,
        const char *pOptions,
        unsigned int flags,
        const char *pathID,
        char **ppszResolvedFilename)
{
  return this->m_pFileSystemPassThru->OpenEx(
           this: this->m_pFileSystemPassThru,
           a2: pFileName,
           a3: pOptions,
           a4: flags,
           a5: pathID,
           a6: ppszResolvedFilename);
}

//------------------------------------------------------------------------------
// Address: 0x1008A7E0
// Name: public: virtual int CFileSystemPassThru::ReadEx(void __near *,int,int,void __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CFileSystemPassThru::ReadEx(
        CFileSystemPassThru *this,
        void *pOutput,
        int destSize,
        int size,
        void *file)
{
  return this->m_pFileSystemPassThru->ReadEx(
           this: this->m_pFileSystemPassThru,
           a2: pOutput,
           a3: destSize,
           a4: size,
           a5: file);
}

//------------------------------------------------------------------------------
// Address: 0x1008A800
// Name: public: virtual int CFileSystemPassThru::ReadFileEx(char const __near *,char const __near *,void __near * __near *,bool,bool,int,int,void __near * (*)(char const __near *,unsigned int))
// Source: json
//------------------------------------------------------------------------------
int __thiscall CFileSystemPassThru::ReadFileEx(
        CFileSystemPassThru *this,
        const char *pFileName,
        const char *pPath,
        void **ppBuf,
        BOOL bNullTerminate,
        BOOL bOptimalAlloc,
        int nMaxBytes,
        int nStartingByte,
        void *(__cdecl *pfnAlloc)(const char *, unsigned int))
{
  return this->m_pFileSystemPassThru->ReadFileEx(
           this: this->m_pFileSystemPassThru,
           a2: pFileName,
           a3: pPath,
           a4: ppBuf,
           a5: bNullTerminate,
           a6: bOptimalAlloc,
           a7: nMaxBytes,
           a8: nStartingByte,
           a9: pfnAlloc);
}

//------------------------------------------------------------------------------
// Address: 0x1008A830
// Name: public: virtual class KeyValues __near * CFileSystemPassThru::LoadKeyValues(enum IFileSystem::KeyValuesPreloadType_t,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
KeyValues *__thiscall CFileSystemPassThru::LoadKeyValues(
        CFileSystemPassThru *this,
        IFileSystem::KeyValuesPreloadType_t type,
        const char *filename,
        const char *pPathID)
{
  return this->m_pFileSystemPassThru->LoadKeyValues_2(
           this: this->m_pFileSystemPassThru,
           a2: type,
           a3: filename,
           a4: pPathID);
}

//------------------------------------------------------------------------------
// Address: 0x1008A850
// Name: public: virtual bool CFileSystemPassThru::LoadKeyValues(class KeyValues __near &,enum IFileSystem::KeyValuesPreloadType_t,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CFileSystemPassThru::LoadKeyValues(
        CFileSystemPassThru *this,
        KeyValues *head,
        IFileSystem::KeyValuesPreloadType_t type,
        const char *filename,
        const char *pPathID)
{
  return this->m_pFileSystemPassThru->LoadKeyValues(
           this: this->m_pFileSystemPassThru,
           a2: head,
           a3: type,
           a4: filename,
           a5: pPathID);
}

//------------------------------------------------------------------------------
// Address: 0x1008A870
// Name: public: virtual bool CFileSystemPassThru::GetFileTypeForFullPath(char const __near *,wchar_t __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CFileSystemPassThru::GetFileTypeForFullPath(
        CFileSystemPassThru *this,
        const char *pFullPath,
        wchar_t *buf,
        unsigned int bufSizeInBytes)
{
  return this->m_pFileSystemPassThru->GetFileTypeForFullPath(
           this: this->m_pFileSystemPassThru,
           a2: pFullPath,
           a3: buf,
           a4: bufSizeInBytes);
}

//------------------------------------------------------------------------------
// Address: 0x1008A890
// Name: public: virtual bool CFileSystemPassThru::GetOptimalIOConstraints(void __near *,unsigned int __near *,unsigned int __near *,unsigned int __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CFileSystemPassThru::GetOptimalIOConstraints(
        CFileSystemPassThru *this,
        void *hFile,
        unsigned int *pOffsetAlign,
        unsigned int *pSizeAlign,
        unsigned int *pBufferAlign)
{
  return this->m_pFileSystemPassThru->GetOptimalIOConstraints(
           this: this->m_pFileSystemPassThru,
           a2: hFile,
           a3: pOffsetAlign,
           a4: pSizeAlign,
           a5: pBufferAlign);
}

//------------------------------------------------------------------------------
// Address: 0x1008A8B0
// Name: public: virtual void __near * CFileSystemPassThru::AllocOptimalReadBuffer(void __near *,unsigned int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void *__thiscall CFileSystemPassThru::AllocOptimalReadBuffer(
        CFileSystemPassThru *this,
        void *hFile,
        unsigned int nSize,
        unsigned int nOffset)
{
  return this->m_pFileSystemPassThru->AllocOptimalReadBuffer(
           this: this->m_pFileSystemPassThru,
           a2: hFile,
           a3: nOffset,
           a4: nSize);
}

//------------------------------------------------------------------------------
// Address: 0x1008A8D0
// Name: public: virtual void CFileSystemPassThru::FreeOptimalReadBuffer(void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFileSystemPassThru::FreeOptimalReadBuffer(CFileSystemPassThru *this, void *p)
{
  this->m_pFileSystemPassThru->FreeOptimalReadBuffer(this: this->m_pFileSystemPassThru, a2: p);
}

//------------------------------------------------------------------------------
// Address: 0x1008A8F0
// Name: public: virtual void CFileSystemPassThru::BeginMapAccess(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFileSystemPassThru::BeginMapAccess(CFileSystemPassThru *this)
{
  this->m_pFileSystemPassThru->BeginMapAccess(this: this->m_pFileSystemPassThru);
}

//------------------------------------------------------------------------------
// Address: 0x1008A900
// Name: public: virtual void CFileSystemPassThru::EndMapAccess(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFileSystemPassThru::EndMapAccess(CFileSystemPassThru *this)
{
  this->m_pFileSystemPassThru->EndMapAccess(this: this->m_pFileSystemPassThru);
}

//------------------------------------------------------------------------------
// Address: 0x1008A910
// Name: public: virtual bool CFileSystemPassThru::ReadToBuffer(void __near *,class CUtlBuffer __near &,int,void __near * (*)(char const __near *,unsigned int))
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CFileSystemPassThru::ReadToBuffer(
        CFileSystemPassThru *this,
        void *hFile,
        CUtlBuffer *buf,
        int nMaxBytes,
        void *(__cdecl *pfnAlloc)(const char *, unsigned int))
{
  return this->m_pFileSystemPassThru->ReadToBuffer(
           this: this->m_pFileSystemPassThru,
           a2: hFile,
           a3: buf,
           a4: nMaxBytes,
           a5: pfnAlloc);
}

//------------------------------------------------------------------------------
// Address: 0x1008A930
// Name: public: virtual bool CFileSystemPassThru::FullPathToRelativePathEx(char const __near *,char const __near *,char __near *,int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CFileSystemPassThru::FullPathToRelativePathEx(
        CFileSystemPassThru *this,
        const char *pFullPath,
        const char *pPathId,
        char *pRelative,
        int nMaxLen)
{
  return this->m_pFileSystemPassThru->FullPathToRelativePathEx(
           this: this->m_pFileSystemPassThru,
           a2: pFullPath,
           a3: pPathId,
           a4: pRelative,
           a5: nMaxLen);
}

//------------------------------------------------------------------------------
// Address: 0x1008A950
// Name: public: virtual int CFileSystemPassThru::GetPathIndex(void __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CFileSystemPassThru::GetPathIndex(CFileSystemPassThru *this, void *const *handle)
{
  return this->m_pFileSystemPassThru->GetPathIndex(this: this->m_pFileSystemPassThru, a2: handle);
}

//------------------------------------------------------------------------------
// Address: 0x1008A970
// Name: public: virtual long CFileSystemPassThru::GetPathTime(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CFileSystemPassThru::GetPathTime(CFileSystemPassThru *this, const char *pPath, const char *pPathID)
{
  return this->m_pFileSystemPassThru->GetPathTime(this: this->m_pFileSystemPassThru, a2: pPath, a3: pPathID);
}

//------------------------------------------------------------------------------
// Address: 0x1008A990
// Name: public: virtual enum DVDMode_t CFileSystemPassThru::GetDVDMode(void)
// Source: json
//------------------------------------------------------------------------------
DVDMode_t __thiscall CFileSystemPassThru::GetDVDMode(CFileSystemPassThru *this)
{
  return this->m_pFileSystemPassThru->GetDVDMode(this: this->m_pFileSystemPassThru);
}

//------------------------------------------------------------------------------
// Address: 0x1008A9A0
// Name: public: virtual void CFileSystemPassThru::EnableWhitelistFileTracking(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFileSystemPassThru::EnableWhitelistFileTracking(CFileSystemPassThru *this, BOOL bEnable)
{
  this->m_pFileSystemPassThru->EnableWhitelistFileTracking(this: this->m_pFileSystemPassThru, a2: bEnable);
}

//------------------------------------------------------------------------------
// Address: 0x1008A9C0
// Name: public: virtual void CFileSystemPassThru::RegisterFileWhitelist(class IFileList __near *,class IFileList __near *,class IFileList __near * __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFileSystemPassThru::RegisterFileWhitelist(
        CFileSystemPassThru *this,
        struct IFileList *pForceMatchList,
        struct IFileList *pAllowFromDiskList,
        struct IFileList **pFilesToReload)
{
  this->m_pFileSystemPassThru->RegisterFileWhitelist(
    this: this->m_pFileSystemPassThru,
    a2: pForceMatchList,
    a3: pAllowFromDiskList,
    a4: pFilesToReload);
}

//------------------------------------------------------------------------------
// Address: 0x1008A9E0
// Name: public: virtual void CFileSystemPassThru::MarkAllCRCsUnverified(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFileSystemPassThru::MarkAllCRCsUnverified(CFileSystemPassThru *this)
{
  this->m_pFileSystemPassThru->MarkAllCRCsUnverified(this: this->m_pFileSystemPassThru);
}

//------------------------------------------------------------------------------
// Address: 0x1008A9F0
// Name: public: virtual void CFileSystemPassThru::CacheFileCRCs(char const __near *,enum ECacheCRCType,class IFileList __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFileSystemPassThru::CacheFileCRCs(
        CFileSystemPassThru *this,
        const char *pPathname,
        ECacheCRCType eType,
        struct IFileList *pFilter)
{
  this->m_pFileSystemPassThru->CacheFileCRCs(this: this->m_pFileSystemPassThru, a2: pPathname, a3: eType, a4: pFilter);
}

//------------------------------------------------------------------------------
// Address: 0x1008AA10
// Name: public: virtual enum EFileCRCStatus CFileSystemPassThru::CheckCachedFileCRC(char const __near *,char const __near *,unsigned long __near *)
// Source: json
//------------------------------------------------------------------------------
EFileCRCStatus __thiscall CFileSystemPassThru::CheckCachedFileCRC(
        CFileSystemPassThru *this,
        const char *pPathID,
        const char *pRelativeFilename,
        unsigned int *pCRC)
{
  return this->m_pFileSystemPassThru->CheckCachedFileCRC(
           this: this->m_pFileSystemPassThru,
           a2: pPathID,
           a3: pRelativeFilename,
           a4: pCRC);
}

//------------------------------------------------------------------------------
// Address: 0x1008AA30
// Name: public: virtual int CFileSystemPassThru::GetUnverifiedCRCFiles(class CUnverifiedCRCFile __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CFileSystemPassThru::GetUnverifiedCRCFiles(
        CFileSystemPassThru *this,
        CUnverifiedCRCFile *pFiles,
        int nMaxFiles)
{
  return this->m_pFileSystemPassThru->GetUnverifiedCRCFiles(
           this: this->m_pFileSystemPassThru,
           a2: pFiles,
           a3: nMaxFiles);
}

//------------------------------------------------------------------------------
// Address: 0x1008AA50
// Name: public: virtual int CFileSystemPassThru::GetWhitelistSpewFlags(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CFileSystemPassThru::GetWhitelistSpewFlags(CFileSystemPassThru *this)
{
  return this->m_pFileSystemPassThru->GetWhitelistSpewFlags(this: this->m_pFileSystemPassThru);
}

//------------------------------------------------------------------------------
// Address: 0x1008AA60
// Name: public: virtual void CFileSystemPassThru::SetWhitelistSpewFlags(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFileSystemPassThru::SetWhitelistSpewFlags(CFileSystemPassThru *this, int spewFlags)
{
  this->m_pFileSystemPassThru->SetWhitelistSpewFlags(this: this->m_pFileSystemPassThru, a2: spewFlags);
}

//------------------------------------------------------------------------------
// Address: 0x1008AA80
// Name: public: virtual void CFileSystemPassThru::InstallDirtyDiskReportFunc(void (*)(void))
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFileSystemPassThru::InstallDirtyDiskReportFunc(CFileSystemPassThru *this, void (__cdecl *func)())
{
  this->m_pFileSystemPassThru->InstallDirtyDiskReportFunc(this: this->m_pFileSystemPassThru, a2: func);
}

//------------------------------------------------------------------------------
// Address: 0x1008AAA0
// Name: public: virtual bool CFileSystemPassThru::IsLaunchedFromXboxHDD(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CFileSystemPassThru::IsLaunchedFromXboxHDD(CFileSystemPassThru *this)
{
  return this->m_pFileSystemPassThru->IsLaunchedFromXboxHDD(this: this->m_pFileSystemPassThru);
}

//------------------------------------------------------------------------------
// Address: 0x1008AAB0
// Name: public: virtual bool CFileSystemPassThru::IsInstalledToXboxHDDCache(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CFileSystemPassThru::IsInstalledToXboxHDDCache(CFileSystemPassThru *this)
{
  return this->m_pFileSystemPassThru->IsInstalledToXboxHDDCache(this: this->m_pFileSystemPassThru);
}

//------------------------------------------------------------------------------
// Address: 0x1008AAC0
// Name: public: virtual bool CFileSystemPassThru::IsDVDHosted(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CFileSystemPassThru::IsDVDHosted(CFileSystemPassThru *this)
{
  return this->m_pFileSystemPassThru->IsDVDHosted(this: this->m_pFileSystemPassThru);
}

//------------------------------------------------------------------------------
// Address: 0x1008AAD0
// Name: public: virtual bool CFileSystemPassThru::IsInstallAllowed(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CFileSystemPassThru::IsInstallAllowed(CFileSystemPassThru *this)
{
  return this->m_pFileSystemPassThru->IsInstallAllowed(this: this->m_pFileSystemPassThru);
}

//------------------------------------------------------------------------------
// Address: 0x1008AAE0
// Name: public: virtual int CFileSystemPassThru::GetSearchPathID(char __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CFileSystemPassThru::GetSearchPathID(CFileSystemPassThru *this, char *pPath, int nMaxLen)
{
  return this->m_pFileSystemPassThru->GetSearchPathID(this: this->m_pFileSystemPassThru, a2: pPath, a3: nMaxLen);
}

//------------------------------------------------------------------------------
// Address: 0x1008AB00
// Name: public: virtual bool CFileSystemPassThru::FixupSearchPathsAfterInstall(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CFileSystemPassThru::FixupSearchPathsAfterInstall(CFileSystemPassThru *this)
{
  return this->m_pFileSystemPassThru->FixupSearchPathsAfterInstall(this: this->m_pFileSystemPassThru);
}

//------------------------------------------------------------------------------
// Address: 0x1008AB10
// Name: public: virtual void (*CFileSystemPassThru::GetDirtyDiskReportFunc(void))(void)
// Source: json
//------------------------------------------------------------------------------
void (__cdecl *__thiscall CFileSystemPassThru::GetDirtyDiskReportFunc(CFileSystemPassThru *this))()
{
  return this->m_pFileSystemPassThru->GetDirtyDiskReportFunc(this: this->m_pFileSystemPassThru);
}

//------------------------------------------------------------------------------
// Address: 0x1008AB20
// Name: public: virtual void CFileSystemPassThru::AddVPKFile(char const __near *,enum SearchPathAdd_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFileSystemPassThru::AddVPKFile(
        CFileSystemPassThru *this,
        const char *pPkName,
        SearchPathAdd_t addType)
{
  this->m_pFileSystemPassThru->AddVPKFile(this: this->m_pFileSystemPassThru, a2: pPkName, a3: addType);
}

//------------------------------------------------------------------------------
// Address: 0x1008AB40
// Name: public: virtual void CFileSystemPassThru::RemoveVPKFile(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFileSystemPassThru::RemoveVPKFile(CFileSystemPassThru *this, const char *pPkName)
{
  this->m_pFileSystemPassThru->RemoveVPKFile(this: this->m_pFileSystemPassThru, a2: pPkName);
}

//------------------------------------------------------------------------------
// Address: 0x1008AB60
// Name: public: virtual void CFileSystemPassThru::GetVPKFileNames(class CUtlVector<class CUtlString,class CUtlMemory<class CUtlString,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFileSystemPassThru::GetVPKFileNames(
        CFileSystemPassThru *this,
        CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *destVector)
{
  this->m_pFileSystemPassThru->GetVPKFileNames(this: this->m_pFileSystemPassThru, a2: destVector);
}

//------------------------------------------------------------------------------
// Address: 0x1008AB80
// Name: public: virtual void CFileSystemPassThru::RemoveAllMapSearchPaths(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFileSystemPassThru::RemoveAllMapSearchPaths(CFileSystemPassThru *this)
{
  this->m_pFileSystemPassThru->RemoveAllMapSearchPaths(this: this->m_pFileSystemPassThru);
}

//------------------------------------------------------------------------------
// Address: 0x1008AB90
// Name: public: virtual void CFileSystemPassThru::SyncDvdDevCache(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFileSystemPassThru::SyncDvdDevCache(CFileSystemPassThru *this)
{
  this->m_pFileSystemPassThru->SyncDvdDevCache(this: this->m_pFileSystemPassThru);
}

//------------------------------------------------------------------------------
// Address: 0x1008ABA0
// Name: public: virtual bool CFileSystemPassThru::GetStringFromKVPool(unsigned long,unsigned int,char __near *,int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CFileSystemPassThru::GetStringFromKVPool(
        CFileSystemPassThru *this,
        unsigned int poolKey,
        unsigned int key,
        char *pOutBuff,
        int buflen)
{
  return this->m_pFileSystemPassThru->GetStringFromKVPool(
           this: this->m_pFileSystemPassThru,
           a2: poolKey,
           a3: key,
           a4: pOutBuff,
           a5: buflen);
}

//------------------------------------------------------------------------------
// Address: 0x1008ABC0
// Name: public: virtual bool CFileSystemPassThru::DiscoverDLC(int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CFileSystemPassThru::DiscoverDLC(CFileSystemPassThru *this, int iController)
{
  return this->m_pFileSystemPassThru->DiscoverDLC(this: this->m_pFileSystemPassThru, a2: iController);
}

//------------------------------------------------------------------------------
// Address: 0x1008ABE0
// Name: public: virtual int CFileSystemPassThru::IsAnyDLCPresent(bool __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CFileSystemPassThru::IsAnyDLCPresent(CFileSystemPassThru *this, bool *pbDLCSearchPathMounted)
{
  return this->m_pFileSystemPassThru->IsAnyDLCPresent(this: this->m_pFileSystemPassThru, a2: pbDLCSearchPathMounted);
}

//------------------------------------------------------------------------------
// Address: 0x1008AC00
// Name: public: virtual bool CFileSystemPassThru::GetAnyDLCInfo(int,unsigned int __near *,wchar_t __near *,int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CFileSystemPassThru::GetAnyDLCInfo(
        CFileSystemPassThru *this,
        int iDLC,
        unsigned int *pLicenseMask,
        wchar_t *pTitleBuff,
        int nOutTitleSize)
{
  return this->m_pFileSystemPassThru->GetAnyDLCInfo(
           this: this->m_pFileSystemPassThru,
           a2: iDLC,
           a3: pLicenseMask,
           a4: pTitleBuff,
           a5: nOutTitleSize);
}

//------------------------------------------------------------------------------
// Address: 0x1008AC20
// Name: public: virtual int CFileSystemPassThru::IsAnyCorruptDLC(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CFileSystemPassThru::IsAnyCorruptDLC(CFileSystemPassThru *this)
{
  return this->m_pFileSystemPassThru->IsAnyCorruptDLC(this: this->m_pFileSystemPassThru);
}

//------------------------------------------------------------------------------
// Address: 0x1008AC30
// Name: public: virtual bool CFileSystemPassThru::GetAnyCorruptDLCInfo(int,wchar_t __near *,int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CFileSystemPassThru::GetAnyCorruptDLCInfo(
        CFileSystemPassThru *this,
        int iCorruptDLC,
        wchar_t *pTitleBuff,
        int nOutTitleSize)
{
  return this->m_pFileSystemPassThru->GetAnyCorruptDLCInfo(
           this: this->m_pFileSystemPassThru,
           a2: iCorruptDLC,
           a3: pTitleBuff,
           a4: nOutTitleSize);
}

//------------------------------------------------------------------------------
// Address: 0x1008AC50
// Name: public: virtual bool CFileSystemPassThru::AddDLCSearchPaths(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CFileSystemPassThru::AddDLCSearchPaths(CFileSystemPassThru *this)
{
  return this->m_pFileSystemPassThru->AddDLCSearchPaths(this: this->m_pFileSystemPassThru);
}

//------------------------------------------------------------------------------
// Address: 0x1008AC60
// Name: public: virtual bool CFileSystemPassThru::IsSpecificDLCPresent(unsigned int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CFileSystemPassThru::IsSpecificDLCPresent(CFileSystemPassThru *this, unsigned int nDLCPackage)
{
  return this->m_pFileSystemPassThru->IsSpecificDLCPresent(this: this->m_pFileSystemPassThru, a2: nDLCPackage);
}

//------------------------------------------------------------------------------
// Address: 0x1008AC80
// Name: public: virtual void CFileSystemPassThru::SetIODelayAlarm(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFileSystemPassThru::SetIODelayAlarm(CFileSystemPassThru *this, float flThreshhold)
{
  ((void (__stdcall *)(_DWORD))this->m_pFileSystemPassThru->SetIODelayAlarm)(a1: LODWORD(flThreshhold));
}

//------------------------------------------------------------------------------
// Address: 0x1008ACA0
// Name: public: virtual bool CFileSystemPassThru::AddXLSPUpdateSearchPath(void const __near *,int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CFileSystemPassThru::AddXLSPUpdateSearchPath(CFileSystemPassThru *this, const void *pData, int nSize)
{
  return this->m_pFileSystemPassThru->AddXLSPUpdateSearchPath(this: this->m_pFileSystemPassThru, a2: pData, a3: nSize);
}

//------------------------------------------------------------------------------
// Address: 0x1008ACC0
// Name: public: virtual class IIoStats __near * CFileSystemPassThru::GetIoStats(void)
// Source: json
//------------------------------------------------------------------------------
IIoStats *__thiscall CFileSystemPassThru::GetIoStats(CFileSystemPassThru *this)
{
  return this->m_pFileSystemPassThru->GetIoStats(this: this->m_pFileSystemPassThru);
}

//------------------------------------------------------------------------------
// Address: 0x1008AD00
// Name: public: virtual void CBaseVMPIFileSystem::Release(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseVMPIFileSystem::Release(CBaseVMPIFileSystem *this)
{
  if ( this != nullptr )
    ((void (__thiscall *)(CBaseVMPIFileSystem *, int))this->dtr_CBaseVMPIFileSystem)(a1: this, a2: 1);
}

//------------------------------------------------------------------------------
// Address: 0x1008AD20
// Name: public: virtual void CBaseVMPIFileSystem::Close(void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseVMPIFileSystem::Close(CBaseVMPIFileSystem *this, void (__thiscall ***file)(_DWORD))
{
  if ( file != nullptr )
    (**file)(a1: file);
}

//------------------------------------------------------------------------------
// Address: 0x1008AD40
// Name: public: virtual int CBaseVMPIFileSystem::Read(void __near *,int,void __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBaseVMPIFileSystem::Read(CBaseVMPIFileSystem *this, void *pOutput, int size, void *file)
{
  return (*(int (__thiscall **)(void *, void *, int))(*(_DWORD *)file + 20))(a1: file, a2: pOutput, a3: size);
}

//------------------------------------------------------------------------------
// Address: 0x1008AD60
// Name: public: virtual int CBaseVMPIFileSystem::Write(void const __near *,int,void __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBaseVMPIFileSystem::Write(CBaseVMPIFileSystem *this, const void *pInput, int size, void *file)
{
  return (*(int (__thiscall **)(void *, const void *, int))(*(_DWORD *)file + 24))(a1: file, a2: pInput, a3: size);
}

//------------------------------------------------------------------------------
// Address: 0x1008AD80
// Name: public: virtual void CBaseVMPIFileSystem::Seek(void __near *,int,enum FileSystemSeek_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseVMPIFileSystem::Seek(CBaseVMPIFileSystem *this, void *file, int pos, FileSystemSeek_t seekType)
{
  (*(void (__thiscall **)(void *, int, FileSystemSeek_t))(*(_DWORD *)file + 4))(a1: file, a2: pos, a3: seekType);
}

//------------------------------------------------------------------------------
// Address: 0x1008ADA0
// Name: public: virtual unsigned int CBaseVMPIFileSystem::Tell(void __near *)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CBaseVMPIFileSystem::Tell(CBaseVMPIFileSystem *this, void *file)
{
  return (*(unsigned int (__thiscall **)(void *))(*(_DWORD *)file + 8))(a1: file);
}

//------------------------------------------------------------------------------
// Address: 0x1008ADC0
// Name: public: virtual unsigned int CBaseVMPIFileSystem::Size(void __near *)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CBaseVMPIFileSystem::Size(CBaseVMPIFileSystem *this, void *file)
{
  return (*(unsigned int (__thiscall **)(void *))(*(_DWORD *)file + 12))(a1: file);
}

//------------------------------------------------------------------------------
// Address: 0x1008ADE0
// Name: public: virtual unsigned int CBaseVMPIFileSystem::Size(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBaseVMPIFileSystem::Size(CBaseVMPIFileSystem *this, const char *pFilename, const char *pathID)
{
  int result; // eax
  unsigned int v5; // edi
  int v6; // ebx

  result = ((int (__thiscall *)(CBaseVMPIFileSystem *, const char *, const char *, _DWORD))this->QueryInterface)(
             a1: this,
             a2: pFilename,
             a3: "rb",
             a4: 0);
  v5 = result;
  if ( result != 0 )
  {
    v6 = ((int (__thiscall *)(CBaseVMPIFileSystem *, int))this->Reconnect)(a1: this, a2: result);
    ((void (__thiscall *)(CBaseVMPIFileSystem *, unsigned int))this->Init)(a1: this, a2: v5);
    return v6;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1008AE30
// Name: public: virtual bool CBaseVMPIFileSystem::FileExists(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CBaseVMPIFileSystem::FileExists(CBaseVMPIFileSystem *this, const char *pFileName, const char *pPathID)
{
  int v4; // eax

  v4 = ((int (__thiscall *)(CBaseVMPIFileSystem *, const char *, const char *, _DWORD))this->QueryInterface)(
         a1: this,
         a2: pFileName,
         a3: "rb",
         a4: 0);
  if ( v4 == 0 )
    return 0;
  ((void (__thiscall *)(CBaseVMPIFileSystem *, int))this->Init)(a1: this, a2: v4);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1008AE70
// Name: public: virtual void CBaseVMPIFileSystem::Flush(void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseVMPIFileSystem::Flush(CBaseVMPIFileSystem *this, void *file)
{
  (*(void (__thiscall **)(void *))(*(_DWORD *)file + 16))(a1: file);
}

//------------------------------------------------------------------------------
// Address: 0x1008AE90
// Name: public: virtual bool CBaseVMPIFileSystem::Precache(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CBaseVMPIFileSystem::Precache(CBaseVMPIFileSystem *this, const char *pFileName, const char *pPathID)
{
  return false;
}

//------------------------------------------------------------------------------
// Address: 0x1008AEA0
// Name: public: virtual void CInternalFileSystemPassThru<class IFileSystem>::InitPassThru(class IBaseFileSystem __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInternalFileSystemPassThru<IFileSystem>::InitPassThru(
        CInternalFileSystemPassThru<IFileSystem> *this,
        IBaseFileSystem *pBaseFileSystemPassThru)
{
  this->m_pBaseFileSystemPassThru = pBaseFileSystemPassThru;
}

//------------------------------------------------------------------------------
// Address: 0x1008AEB0
// Name: public: virtual void __near * CInternalFileSystemPassThru<class IFileSystem>::Open(char const __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void *__thiscall CInternalFileSystemPassThru<IFileSystem>::Open(
        CInternalFileSystemPassThru<IFileSystem> *this,
        const char *pFileName,
        const char *pOptions,
        const char *pathID)
{
  return (*((void *(__thiscall **)(IBaseFileSystem_vtbl *, const char *, const char *, const char *))this->Read + 2))(
           a1: this->IFileSystem::IBaseFileSystem::__vftable,
           a2: pFileName,
           a3: pOptions,
           a4: pathID);
}

//------------------------------------------------------------------------------
// Address: 0x1008AEC0
// Name: public: virtual bool CInternalFileSystemPassThru<class IFileSystem>::IsFileWritable(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CInternalFileSystemPassThru<IFileSystem>::IsFileWritable(
        CInternalFileSystemPassThru<IFileSystem> *this,
        const char *pFileName,
        const char *pPathID)
{
  return (*((bool (__thiscall **)(IBaseFileSystem_vtbl *, const char *, const char *))this->Read + 11))(
           a1: this->IFileSystem::IBaseFileSystem::__vftable,
           a2: pFileName,
           a3: pPathID);
}

//------------------------------------------------------------------------------
// Address: 0x1008AED0
// Name: public: virtual bool CInternalFileSystemPassThru<class IFileSystem>::SetFileWritable(char const __near *,bool,char const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __userpurge CInternalFileSystemPassThru<IFileSystem>::SetFileWritable@<al>(
        CInternalFileSystemPassThru<IFileSystem> *this@<ecx>,
        const char *pFileName,
        bool writable,
        const char *pPathID)
{
  return (*((bool (__thiscall **)(IBaseFileSystem_vtbl *, const char *))this->Read + 12))(
           a1: this->IFileSystem::IBaseFileSystem::__vftable,
           a2: pFileName);
}

//------------------------------------------------------------------------------
// Address: 0x1008AEE0
// Name: public: virtual long CInternalFileSystemPassThru<class IFileSystem>::GetFileTime(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CInternalFileSystemPassThru<IFileSystem>::GetFileTime(
        CInternalFileSystemPassThru<IFileSystem> *this,
        const char *pFileName,
        const char *pPathID)
{
  return (*((int (__thiscall **)(IBaseFileSystem_vtbl *, const char *, const char *))this->Read + 13))(
           a1: this->IFileSystem::IBaseFileSystem::__vftable,
           a2: pFileName,
           a3: pPathID);
}

//------------------------------------------------------------------------------
// Address: 0x1008AEF0
// Name: public: virtual bool CInternalFileSystemPassThru<class IFileSystem>::UnzipFile(char const __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CInternalFileSystemPassThru<IFileSystem>::UnzipFile(
        CInternalFileSystemPassThru<IFileSystem> *this,
        const char *pFileName,
        const char *pPath,
        const char *pDestination)
{
  return (*((bool (__thiscall **)(IBaseFileSystem_vtbl *, const char *, const char *, const char *))this->Read + 16))(
           a1: this->IFileSystem::IBaseFileSystem::__vftable,
           a2: pFileName,
           a3: pPath,
           a4: pDestination);
}

//------------------------------------------------------------------------------
// Address: 0x1008AF00
// Name: public: virtual void CFileSystemPassThru::InitPassThru(class IFileSystem __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFileSystemPassThru::InitPassThru(
        CFileSystemPassThru *this,
        IFileSystem *pFileSystemPassThru,
        bool bBaseOnly)
{
  if ( !bBaseOnly )
    this->m_pFileSystemPassThru = pFileSystemPassThru;
  if ( pFileSystemPassThru != nullptr )
    this->m_pBaseFileSystemPassThru = &pFileSystemPassThru->IBaseFileSystem;
  else
    this->m_pBaseFileSystemPassThru = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1008AF30
// Name: public: virtual bool CBaseVMPIFileSystem::ReadFile(char const __near *,char const __near *,class CUtlBuffer __near &,int,int,void __near * (*)(char const __near *,unsigned int))
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CBaseVMPIFileSystem::ReadFile(
        CBaseVMPIFileSystem *this,
        const char *pFileName,
        const char *pPath,
        CUtlBuffer *buf,
        int nMaxBytes,
        int nStartingByte,
        void *(__cdecl *pfnAlloc)(const char *, unsigned int))
{
  const char *v9; // eax
  int v10; // ebx
  int v12; // eax
  int nBytesRead; // [esp+1Ch] [ebp+10h]
  int nBytesReada; // [esp+1Ch] [ebp+10h]

  v9 = "rt";
  if ( (buf->m_Flags & 1) == 0 )
    v9 = "rb";
  v10 = ((int (__thiscall *)(CBaseVMPIFileSystem *, const char *, const char *, const char *))this->QueryInterface)(
          a1: this,
          a2: pFileName,
          a3: v9,
          a4: pPath);
  if ( v10 == 0 )
    return false;
  v12 = ((int (__thiscall *)(CBaseVMPIFileSystem *, int))this->Reconnect)(a1: this, a2: v10);
  nBytesRead = v12;
  if ( nMaxBytes > 0 && nMaxBytes < v12 )
  {
    nBytesRead = nMaxBytes;
    v12 = nMaxBytes;
  }
  CUtlBuffer::EnsureCapacity(this: buf, num: v12 + buf->m_Put);
  if ( nStartingByte != 0 )
    ((void (__thiscall *)(CBaseVMPIFileSystem *, int, int, _DWORD))this->Shutdown)(
      a1: this,
      a2: v10,
      a3: nStartingByte,
      a4: 0);
  nBytesReada = ((int (__thiscall *)(CBaseVMPIFileSystem *, unsigned __int8 *, int, int))this->Connect)(
                  a1: this,
                  a2: &buf->m_Memory.m_pMemory[buf->m_Put - buf->m_nOffset],
                  a3: nBytesRead,
                  a4: v10);
  CUtlBuffer::SeekPut(this: buf, type: SEEK_CURRENT, offset: nBytesReada);
  ((void (__thiscall *)(CBaseVMPIFileSystem *, int))this->Init)(a1: this, a2: v10);
  return nBytesReada != 0;
}

//------------------------------------------------------------------------------
// Address: 0x1008AFF0
// Name: public: virtual bool CBaseVMPIFileSystem::WriteFile(char const __near *,char const __near *,class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CBaseVMPIFileSystem::WriteFile(
        CBaseVMPIFileSystem *this,
        const char *pFileName,
        const char *pPath,
        CUtlBuffer *buf)
{
  const char *v5; // eax
  int v6; // edi
  int v8; // ebx

  v5 = "wt";
  if ( (buf->m_Flags & 1) == 0 )
    v5 = "wb";
  v6 = ((int (__thiscall *)(CBaseVMPIFileSystem *, const char *, const char *, const char *))this->QueryInterface)(
         a1: this,
         a2: pFileName,
         a3: v5,
         a4: pPath);
  if ( v6 == 0 )
    return false;
  v8 = ((int (__thiscall *)(CBaseVMPIFileSystem *, unsigned __int8 *, int, int))this->Disconnect)(
         a1: this,
         a2: buf->m_Memory.m_pMemory,
         a3: buf->m_nMaxPut,
         a4: v6);
  ((void (__thiscall *)(CBaseVMPIFileSystem *, int))this->Init)(a1: this, a2: v6);
  return v8 != 0;
}

//------------------------------------------------------------------------------
// Address: 0x1008DA80
// Name: public: virtual bool CFileSystemPassThru::GetCurrentDirectory(char __near *,int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CFileSystemPassThru::GetCurrentDirectory(CFileSystemPassThru *this, char *pDirectory, int maxlen)
{
  return this->m_pFileSystemPassThru->GetCurrentDirectory(this: this->m_pFileSystemPassThru, a2: pDirectory, a3: maxlen);
}

} // namespace vrad_dll

// ============================================================
// Overlay from vvis_dll (Missing functions)
// ============================================================
namespace vvis_dll {

//------------------------------------------------------------------------------
// Address: 0x100287B0
// Name: void __near * GetVMPIFileSystem(void)
// Source: json
//------------------------------------------------------------------------------
IBaseFileSystem *__cdecl GetVMPIFileSystem()
{
  if ( g_pBaseVMPIFileSystem != nullptr )
    return &g_pBaseVMPIFileSystem->IBaseFileSystem;
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x100287C0
// Name: void __near * GetFullFileSystem(void)
// Source: json
//------------------------------------------------------------------------------
IFileSystem *__cdecl GetFullFileSystem()
{
  return g_pOriginalPassThruFileSystem;
}

//------------------------------------------------------------------------------
// Address: 0x100287D0
// Name: class IFileSystem __near * VMPI_FileSystem_Init(int,class IFileSystem __near *)
// Source: json
//------------------------------------------------------------------------------
CBaseVMPIFileSystem *__cdecl VMPI_FileSystem_Init(unsigned int maxMemoryUsage, IFileSystem *pPassThru)
{
  g_pOriginalPassThruFileSystem = pPassThru;
  if ( g_bMPIMaster )
    CreateMasterVMPIFileSystem(maxMemoryUsage, pPassThru);
  else
    CreateWorkerVMPIFileSystem();
  return g_pBaseVMPIFileSystem;
}

//------------------------------------------------------------------------------
// Address: 0x10028810
// Name: class IFileSystem __near * VMPI_FileSystem_Term(void)
// Source: json
//------------------------------------------------------------------------------
IFileSystem *__cdecl VMPI_FileSystem_Term()
{
  IFileSystem *result; // eax

  if ( g_pBaseVMPIFileSystem != nullptr )
  {
    g_pBaseVMPIFileSystem->Release(this: g_pBaseVMPIFileSystem);
    g_pBaseVMPIFileSystem = nullptr;
    if ( g_iVMPIVerboseLevel >= 1 )
    {
      if ( g_bMPIMaster )
        _Msg(a1: "Multicast send: %dk\n", (g_nMulticastBytesSent + 511) / 1024);
      else
        _Msg(a1: "Multicast recv: %dk\n", (g_nMulticastBytesReceived + 511) / 1024);
    }
  }
  result = g_pOriginalPassThruFileSystem;
  g_pOriginalPassThruFileSystem = nullptr;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100288A0
// Name: void VMPI_FileSystem_CreateVirtualFile(char const __near *,void const __near *,unsigned long)
// Source: json
//------------------------------------------------------------------------------
void __cdecl VMPI_FileSystem_CreateVirtualFile(const char *pFilename, const void *pData, unsigned int fileLength)
{
  g_pBaseVMPIFileSystem->CreateVirtualFile(this: g_pBaseVMPIFileSystem, a2: pFilename, a3: pData, a4: fileLength);
}

//------------------------------------------------------------------------------
// Address: 0x100288D0
// Name: bool FileSystemRecv(class MessageBuffer __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl FileSystemRecv(MessageBuffer *pBuf, int iSource, int iPacketID)
{
  return g_pBaseVMPIFileSystem != nullptr
      && g_pBaseVMPIFileSystem->HandleFileSystemPacket(
           this: g_pBaseVMPIFileSystem,
           a2: pBuf,
           a3: iSource,
           a4: iPacketID);
}

//------------------------------------------------------------------------------
// Address: 0x10028900
// Name: public: void CVMPIFile_Memory::Init(char const __near *,long,char)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVMPIFile_Memory::Init(CVMPIFile_Memory *this, const char *pData, int len, char chMode)
{
  this->m_pData = pData;
  this->m_DataLen = len;
  this->m_iCurPos = 0;
  this->m_chMode = chMode;
}

//------------------------------------------------------------------------------
// Address: 0x10028920
// Name: public: virtual void CVMPIFile_Memory::Close(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVMPIFile_Memory::Close(CVMPIFile_Memory *this)
{
  operator delete(p: this);
}

//------------------------------------------------------------------------------
// Address: 0x10028930
// Name: public: virtual void CVMPIFile_Memory::Seek(int,enum FileSystemSeek_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVMPIFile_Memory::Seek(CVMPIFile_Memory *this, int pos, FileSystemSeek_t seekType)
{
  if ( seekType != FILESYSTEM_SEEK_HEAD )
  {
    if ( seekType == FILESYSTEM_SEEK_CURRENT )
      this->m_iCurPos += pos;
    else
      this->m_iCurPos = this->m_DataLen - pos;
  }
  else
  {
    this->m_iCurPos = pos;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10028970
// Name: public: virtual int CVMPIFile_Memory::Read(void __near *,int)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CVMPIFile_Memory::Read(CVMPIFile_Memory *this, unsigned __int8 *pOutput, int size)
{
  int m_iCurPos; // ecx
  unsigned int v5; // esi
  signed int v6; // eax
  signed int v8; // edi
  unsigned __int8 *v9; // esi
  int v10; // eax
  unsigned int v11; // edi
  int v12; // eax
  unsigned __int8 *v13; // ecx
  int v14; // eax
  int iRead; // [esp+8h] [ebp-8h]
  int len; // [esp+Ch] [ebp-4h]
  int lena; // [esp+Ch] [ebp-4h]

  m_iCurPos = this->m_iCurPos;
  v5 = size;
  v6 = this->m_DataLen - m_iCurPos;
  if ( v6 < size )
    v5 = this->m_DataLen - m_iCurPos;
  if ( this->m_chMode == 116 )
  {
    v8 = this->m_DataLen - m_iCurPos;
    v9 = (unsigned __int8 *)&this->m_pData[m_iCurPos];
    iRead = 0;
    len = v8;
    memchr(buf: v9, chr: 0xDu, cnt: v6);
    if ( v10 != 0 )
    {
      while ( 1 )
      {
        v11 = size;
        v12 = v10 - (_DWORD)v9;
        if ( size >= v12 )
          v11 = v12;
        memcpy(dst: pOutput, src: v9, count: v11);
        this->m_iCurPos += v11;
        lena = len - v11;
        iRead += v11;
        v9 += v11;
        v13 = &pOutput[v11];
        size -= v11;
        if ( size == 0 )
          break;
        if ( lena == 0 )
        {
          v8 = 0;
          goto LABEL_16;
        }
        v14 = lena;
        if ( lena > 1 && v9[1] == 10 )
        {
          ++v9;
          ++this->m_iCurPos;
          v14 = lena - 1;
        }
        ++iRead;
        --size;
        *v13 = *v9;
        ++this->m_iCurPos;
        ++v9;
        len = v14 - 1;
        pOutput = v13 + 1;
        memchr(buf: v9, chr: 0xDu, cnt: v14 - 1);
        if ( v10 == 0 )
        {
          v8 = len;
          goto LABEL_15;
        }
      }
    }
    else
    {
LABEL_15:
      v13 = pOutput;
LABEL_16:
      if ( size != 0 && v8 != 0 )
      {
        if ( size < v8 )
          v8 = size;
        memcpy(dst: v13, src: v9, count: v8);
        this->m_iCurPos += v8;
        iRead += v8;
      }
    }
    return iRead;
  }
  else
  {
    memcpy(dst: pOutput, src: (unsigned __int8 *)&this->m_pData[m_iCurPos], count: v5);
    this->m_iCurPos += v5;
    return v5;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10028A90
// Name: public: virtual int CVMPIFile_Memory::Write(void const __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CVMPIFile_Memory::Write(CVMPIFile_Memory *this, const void *pInput, const void *size)
{
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10028AA0
// Name: public: virtual CBaseVMPIFileSystem::~CBaseVMPIFileSystem(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseVMPIFileSystem::~CBaseVMPIFileSystem(CBaseVMPIFileSystem *this)
{
  this->CFileSystemPassThru::CInternalFileSystemPassThru<IFileSystem>::IFileSystem::IAppSystem::__vftable = (CBaseVMPIFileSystem_vtbl *)&CBaseVMPIFileSystem::`vftable'{for `IAppSystem'};
  this->CFileSystemPassThru::CInternalFileSystemPassThru<IFileSystem>::IFileSystem::IBaseFileSystem::__vftable = (IBaseFileSystem_vtbl *)&CBaseVMPIFileSystem::`vftable'{for `IBaseFileSystem'};
}

//------------------------------------------------------------------------------
// Address: 0x10028AB0
// Name: public: virtual bool CFileSystemPassThru::Connect(void __near * (*)(char const __near *,int __near *))
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CFileSystemPassThru::Connect(CFileSystemPassThru *this, void *(__cdecl *factory)(const char *, int *))
{
  return this->m_pFileSystemPassThru->Connect(this: this->m_pFileSystemPassThru, a2: factory);
}

//------------------------------------------------------------------------------
// Address: 0x10028AC0
// Name: public: virtual void CFileSystemPassThru::Disconnect(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFileSystemPassThru::Disconnect(CFileSystemPassThru *this)
{
  this->m_pFileSystemPassThru->Disconnect(this: this->m_pFileSystemPassThru);
}

//------------------------------------------------------------------------------
// Address: 0x10028AD0
// Name: public: virtual void __near * CFileSystemPassThru::QueryInterface(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void *__thiscall CFileSystemPassThru::QueryInterface(CFileSystemPassThru *this, const char *pInterfaceName)
{
  return this->m_pFileSystemPassThru->QueryInterface(this: this->m_pFileSystemPassThru, a2: pInterfaceName);
}

//------------------------------------------------------------------------------
// Address: 0x10028AE0
// Name: public: virtual enum InitReturnVal_t CFileSystemPassThru::Init(void)
// Source: json
//------------------------------------------------------------------------------
InitReturnVal_t __thiscall CFileSystemPassThru::Init(CFileSystemPassThru *this)
{
  return this->m_pFileSystemPassThru->Init(this: this->m_pFileSystemPassThru);
}

//------------------------------------------------------------------------------
// Address: 0x10028AF0
// Name: public: virtual void CFileSystemPassThru::Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFileSystemPassThru::Shutdown(CFileSystemPassThru *this)
{
  this->m_pFileSystemPassThru->Shutdown(this: this->m_pFileSystemPassThru);
}

//------------------------------------------------------------------------------
// Address: 0x10028B00
// Name: public: virtual struct AppSystemInfo_t const __near * CFileSystemPassThru::GetDependencies(void)
// Source: json
//------------------------------------------------------------------------------
const AppSystemInfo_t *__thiscall CFileSystemPassThru::GetDependencies(CFileSystemPassThru *this)
{
  return this->m_pFileSystemPassThru->GetDependencies(this: this->m_pFileSystemPassThru);
}

//------------------------------------------------------------------------------
// Address: 0x10028B10
// Name: public: virtual enum AppSystemTier_t CFileSystemPassThru::GetTier(void)
// Source: json
//------------------------------------------------------------------------------
AppSystemTier_t __thiscall CFileSystemPassThru::GetTier(CFileSystemPassThru *this)
{
  return this->m_pFileSystemPassThru->GetTier(this: this->m_pFileSystemPassThru);
}

//------------------------------------------------------------------------------
// Address: 0x10028B20
// Name: public: virtual void CFileSystemPassThru::Reconnect(void __near * (*)(char const __near *,int __near *),char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFileSystemPassThru::Reconnect(
        CFileSystemPassThru *this,
        void *(__cdecl *factory)(const char *, int *),
        const char *pInterfaceName)
{
  this->m_pFileSystemPassThru->Reconnect(this: this->m_pFileSystemPassThru, a2: factory, a3: pInterfaceName);
}

//------------------------------------------------------------------------------
// Address: 0x10028B30
// Name: public: virtual void CFileSystemPassThru::RemoveAllSearchPaths(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFileSystemPassThru::RemoveAllSearchPaths(CFileSystemPassThru *this)
{
  this->m_pFileSystemPassThru->RemoveAllSearchPaths(this: this->m_pFileSystemPassThru);
}

//------------------------------------------------------------------------------
// Address: 0x10028B40
// Name: public: virtual void CFileSystemPassThru::AddSearchPath(char const __near *,char const __near *,enum SearchPathAdd_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFileSystemPassThru::AddSearchPath(
        CFileSystemPassThru *this,
        const char *pPath,
        const char *pathID,
        SearchPathAdd_t addType)
{
  this->m_pFileSystemPassThru->AddSearchPath(this: this->m_pFileSystemPassThru, a2: pPath, a3: pathID, a4: addType);
}

//------------------------------------------------------------------------------
// Address: 0x10028B50
// Name: public: virtual bool CFileSystemPassThru::RemoveSearchPath(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CFileSystemPassThru::RemoveSearchPath(CFileSystemPassThru *this, const char *pPath, const char *pathID)
{
  return this->m_pFileSystemPassThru->RemoveSearchPath(this: this->m_pFileSystemPassThru, a2: pPath, a3: pathID);
}

//------------------------------------------------------------------------------
// Address: 0x10028B60
// Name: public: virtual void CFileSystemPassThru::RemoveFile(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFileSystemPassThru::RemoveFile(
        CFileSystemPassThru *this,
        const char *pRelativePath,
        const char *pathID)
{
  this->m_pFileSystemPassThru->RemoveFile(this: this->m_pFileSystemPassThru, a2: pRelativePath, a3: pathID);
}

//------------------------------------------------------------------------------
// Address: 0x10028B70
// Name: public: virtual bool CFileSystemPassThru::RenameFile(char const __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CFileSystemPassThru::RenameFile(
        CFileSystemPassThru *this,
        const char *pOldPath,
        const char *pNewPath,
        const char *pathID)
{
  return this->m_pFileSystemPassThru->RenameFile(
           this: this->m_pFileSystemPassThru,
           a2: pOldPath,
           a3: pNewPath,
           a4: pathID);
}

//------------------------------------------------------------------------------
// Address: 0x10028B80
// Name: public: virtual void CFileSystemPassThru::CreateDirHierarchy(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFileSystemPassThru::CreateDirHierarchy(
        CFileSystemPassThru *this,
        const char *path,
        const char *pathID)
{
  this->m_pFileSystemPassThru->CreateDirHierarchy(this: this->m_pFileSystemPassThru, a2: path, a3: pathID);
}

//------------------------------------------------------------------------------
// Address: 0x10028B90
// Name: public: virtual bool CFileSystemPassThru::IsDirectory(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CFileSystemPassThru::IsDirectory(CFileSystemPassThru *this, const char *pFileName, const char *pathID)
{
  return this->m_pFileSystemPassThru->IsDirectory(this: this->m_pFileSystemPassThru, a2: pFileName, a3: pathID);
}

//------------------------------------------------------------------------------
// Address: 0x10028BA0
// Name: public: virtual void CFileSystemPassThru::FileTimeToString(char __near *,int,long)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFileSystemPassThru::FileTimeToString(
        CFileSystemPassThru *this,
        char *pStrip,
        int maxCharsIncludingTerminator,
        int fileTime)
{
  this->m_pFileSystemPassThru->FileTimeToString(
    this: this->m_pFileSystemPassThru,
    a2: pStrip,
    a3: maxCharsIncludingTerminator,
    a4: fileTime);
}

//------------------------------------------------------------------------------
// Address: 0x10028BB0
// Name: public: virtual void CFileSystemPassThru::SetBufferSize(void __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFileSystemPassThru::SetBufferSize(CFileSystemPassThru *this, void *file, unsigned int nBytes)
{
  this->m_pFileSystemPassThru->SetBufferSize(this: this->m_pFileSystemPassThru, a2: file, a3: nBytes);
}

//------------------------------------------------------------------------------
// Address: 0x10028BC0
// Name: public: virtual bool CFileSystemPassThru::IsOk(void __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CFileSystemPassThru::IsOk(CFileSystemPassThru *this, void *file)
{
  return this->m_pFileSystemPassThru->IsOk(this: this->m_pFileSystemPassThru, a2: file);
}

//------------------------------------------------------------------------------
// Address: 0x10028BD0
// Name: public: virtual bool CFileSystemPassThru::EndOfFile(void __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CFileSystemPassThru::EndOfFile(CFileSystemPassThru *this, void *file)
{
  return this->m_pFileSystemPassThru->EndOfFile(this: this->m_pFileSystemPassThru, a2: file);
}

//------------------------------------------------------------------------------
// Address: 0x10028BE0
// Name: public: virtual char __near * CFileSystemPassThru::ReadLine(char __near *,int,void __near *)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CFileSystemPassThru::ReadLine(CFileSystemPassThru *this, char *pOutput, int maxChars, void *file)
{
  return this->m_pFileSystemPassThru->ReadLine(this: this->m_pFileSystemPassThru, a2: pOutput, a3: maxChars, a4: file);
}

//------------------------------------------------------------------------------
// Address: 0x10028BF0
// Name: public: virtual int CFileSystemPassThru::FPrintf(void __near *,char const __near *,...)
// Source: json
//------------------------------------------------------------------------------
int CFileSystemPassThru::FPrintf(CFileSystemPassThru *this, void *file, char *pFormat, ...)
{
  char string[8192]; // [esp+0h] [ebp-2000h] BYREF
  va_list ap; // [esp+2014h] [ebp+14h] BYREF

  va_start(ap, pFormat);
  _vsnprintf(string, count: 0x2000u, format: pFormat, ap);
  return this->m_pFileSystemPassThru->FPrintf(this: this->m_pFileSystemPassThru, a2: file, a3: "%s", string);
}

//------------------------------------------------------------------------------
// Address: 0x10028C40
// Name: public: virtual class CSysModule __near * CFileSystemPassThru::LoadModule(char const __near *,char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
struct CSysModule *__thiscall CFileSystemPassThru::LoadModule(
        CFileSystemPassThru *this,
        const char *pFileName,
        const char *pPathID,
        BOOL bValidatedDllOnly)
{
  return this->m_pFileSystemPassThru->LoadModule(
           this: this->m_pFileSystemPassThru,
           a2: pFileName,
           a3: pPathID,
           a4: bValidatedDllOnly);
}

//------------------------------------------------------------------------------
// Address: 0x10028C50
// Name: public: virtual void CFileSystemPassThru::UnloadModule(class CSysModule __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFileSystemPassThru::UnloadModule(CFileSystemPassThru *this, struct CSysModule *pModule)
{
  this->m_pFileSystemPassThru->UnloadModule(this: this->m_pFileSystemPassThru, a2: pModule);
}

//------------------------------------------------------------------------------
// Address: 0x10028C60
// Name: public: virtual char const __near * CFileSystemPassThru::FindFirst(char const __near *,int __near *)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CFileSystemPassThru::FindFirst(CFileSystemPassThru *this, const char *pWildCard, int *pHandle)
{
  return this->m_pFileSystemPassThru->FindFirst(this: this->m_pFileSystemPassThru, a2: pWildCard, a3: pHandle);
}

//------------------------------------------------------------------------------
// Address: 0x10028C70
// Name: public: virtual char const __near * CFileSystemPassThru::FindNext(int)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CFileSystemPassThru::FindNext(CFileSystemPassThru *this, int handle)
{
  return this->m_pFileSystemPassThru->FindNext(this: this->m_pFileSystemPassThru, a2: handle);
}

//------------------------------------------------------------------------------
// Address: 0x10028C80
// Name: public: virtual bool CFileSystemPassThru::FindIsDirectory(int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CFileSystemPassThru::FindIsDirectory(CFileSystemPassThru *this, int handle)
{
  return this->m_pFileSystemPassThru->FindIsDirectory(this: this->m_pFileSystemPassThru, a2: handle);
}

//------------------------------------------------------------------------------
// Address: 0x10028CA0
// Name: public: virtual void CFileSystemPassThru::FindClose(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFileSystemPassThru::FindClose(CFileSystemPassThru *this, int handle)
{
  this->m_pFileSystemPassThru->FindClose(this: this->m_pFileSystemPassThru, a2: handle);
}

//------------------------------------------------------------------------------
// Address: 0x10028CC0
// Name: public: virtual void CFileSystemPassThru::FindFileAbsoluteList(class CUtlVector<class CUtlString,class CUtlMemory<class CUtlString,int>> __near &,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFileSystemPassThru::FindFileAbsoluteList(
        CFileSystemPassThru *this,
        CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *outAbsolutePathNames,
        const char *pWildCard,
        const char *pPathID)
{
  this->m_pFileSystemPassThru->FindFileAbsoluteList(
    this: this->m_pFileSystemPassThru,
    a2: outAbsolutePathNames,
    a3: pWildCard,
    a4: pPathID);
}

//------------------------------------------------------------------------------
// Address: 0x10028CE0
// Name: public: virtual char const __near * CFileSystemPassThru::GetLocalPath(char const __near *,char __near *,int)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CFileSystemPassThru::GetLocalPath(
        CFileSystemPassThru *this,
        const char *pFileName,
        char *pLocalPath,
        int localPathBufferSize)
{
  return this->m_pFileSystemPassThru->GetLocalPath(
           this: this->m_pFileSystemPassThru,
           a2: pFileName,
           a3: pLocalPath,
           a4: localPathBufferSize);
}

//------------------------------------------------------------------------------
// Address: 0x10028D00
// Name: public: virtual bool CFileSystemPassThru::FullPathToRelativePath(char const __near *,char __near *,int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CFileSystemPassThru::FullPathToRelativePath(
        CFileSystemPassThru *this,
        const char *pFullpath,
        char *pRelative,
        int maxlen)
{
  return this->m_pFileSystemPassThru->FullPathToRelativePath(
           this: this->m_pFileSystemPassThru,
           a2: pFullpath,
           a3: pRelative,
           a4: maxlen);
}

//------------------------------------------------------------------------------
// Address: 0x10028D20
// Name: public: virtual void CFileSystemPassThru::PrintOpenedFiles(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFileSystemPassThru::PrintOpenedFiles(CFileSystemPassThru *this)
{
  this->m_pFileSystemPassThru->PrintOpenedFiles(this: this->m_pFileSystemPassThru);
}

//------------------------------------------------------------------------------
// Address: 0x10028D30
// Name: public: virtual void CFileSystemPassThru::PrintSearchPaths(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFileSystemPassThru::PrintSearchPaths(CFileSystemPassThru *this)
{
  this->m_pFileSystemPassThru->PrintSearchPaths(this: this->m_pFileSystemPassThru);
}

//------------------------------------------------------------------------------
// Address: 0x10028D40
// Name: public: virtual void CFileSystemPassThru::SetWarningFunc(void (*)(char const __near *,...))
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFileSystemPassThru::SetWarningFunc(CFileSystemPassThru *this, void (*pfnWarning)(const char *, ...))
{
  this->m_pFileSystemPassThru->SetWarningFunc(this: this->m_pFileSystemPassThru, a2: pfnWarning);
}

//------------------------------------------------------------------------------
// Address: 0x10028D60
// Name: public: virtual void CFileSystemPassThru::SetWarningLevel(enum FileWarningLevel_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFileSystemPassThru::SetWarningLevel(CFileSystemPassThru *this, FileWarningLevel_t level)
{
  this->m_pFileSystemPassThru->SetWarningLevel(this: this->m_pFileSystemPassThru, a2: level);
}

//------------------------------------------------------------------------------
// Address: 0x10028D80
// Name: public: virtual void CFileSystemPassThru::AddLoggingFunc(void (*)(char const __near *,char const __near *))
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFileSystemPassThru::AddLoggingFunc(
        CFileSystemPassThru *this,
        void (__cdecl *pfnLogFunc)(const char *, const char *))
{
  this->m_pFileSystemPassThru->AddLoggingFunc(this: this->m_pFileSystemPassThru, a2: pfnLogFunc);
}

//------------------------------------------------------------------------------
// Address: 0x10028DA0
// Name: public: virtual void CFileSystemPassThru::RemoveLoggingFunc(void (*)(char const __near *,char const __near *))
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFileSystemPassThru::RemoveLoggingFunc(
        CFileSystemPassThru *this,
        void (__cdecl *logFunc)(const char *, const char *))
{
  this->m_pFileSystemPassThru->RemoveLoggingFunc(this: this->m_pFileSystemPassThru, a2: logFunc);
}

//------------------------------------------------------------------------------
// Address: 0x10028DC0
// Name: public: virtual enum FSAsyncStatus_t CFileSystemPassThru::AsyncReadMultiple(struct FileAsyncRequest_t const __near *,int,struct FSAsyncControl_t__ __near * __near *)
// Source: json
//------------------------------------------------------------------------------
FSAsyncStatus_t __thiscall CFileSystemPassThru::AsyncReadMultiple(
        CFileSystemPassThru *this,
        const FileAsyncRequest_t *pRequests,
        int nRequests,
        FSAsyncControl_t__ **pControls)
{
  return this->m_pFileSystemPassThru->AsyncReadMultiple(
           this: this->m_pFileSystemPassThru,
           a2: pRequests,
           a3: nRequests,
           a4: pControls);
}

//------------------------------------------------------------------------------
// Address: 0x10028DE0
// Name: public: virtual enum FSAsyncStatus_t CFileSystemPassThru::AsyncReadMultipleCreditAlloc(struct FileAsyncRequest_t const __near *,int,char const __near *,int,struct FSAsyncControl_t__ __near * __near *)
// Source: json
//------------------------------------------------------------------------------
FSAsyncStatus_t __thiscall CFileSystemPassThru::AsyncReadMultipleCreditAlloc(
        CFileSystemPassThru *this,
        const FileAsyncRequest_t *pRequests,
        int nRequests,
        const char *pszFile,
        int line,
        FSAsyncControl_t__ **pControls)
{
  return this->m_pFileSystemPassThru->AsyncReadMultipleCreditAlloc(
           this: this->m_pFileSystemPassThru,
           a2: pRequests,
           a3: nRequests,
           a4: pszFile,
           a5: line,
           a6: pControls);
}

//------------------------------------------------------------------------------
// Address: 0x10028E00
// Name: public: virtual enum FSAsyncStatus_t CFileSystemPassThru::AsyncDirectoryScan(char const __near *,bool,void __near *,void (*)(void __near *,char __near *,char __near *),void (*)(void __near *,enum FSAsyncStatus_t),struct FSAsyncControl_t__ __near * __near *)
// Source: json
//------------------------------------------------------------------------------
FSAsyncStatus_t __thiscall CFileSystemPassThru::AsyncDirectoryScan(
        CFileSystemPassThru *this,
        const char *pSearchSpec,
        BOOL recurseFolders,
        void *pContext,
        void (__cdecl *pfnAdd)(void *, char *, char *),
        void (__cdecl *pfnDone)(void *, FSAsyncStatus_t),
        FSAsyncControl_t__ **pControl)
{
  return this->m_pFileSystemPassThru->AsyncDirectoryScan(
           this: this->m_pFileSystemPassThru,
           a2: pSearchSpec,
           a3: recurseFolders,
           a4: pContext,
           a5: pfnAdd,
           a6: pfnDone,
           a7: pControl);
}

//------------------------------------------------------------------------------
// Address: 0x10028E20
// Name: public: virtual enum FSAsyncStatus_t CFileSystemPassThru::AsyncFinish(struct FSAsyncControl_t__ __near *,bool)
// Source: json
//------------------------------------------------------------------------------
FSAsyncStatus_t __thiscall CFileSystemPassThru::AsyncFinish(
        CFileSystemPassThru *this,
        FSAsyncControl_t__ *hControl,
        BOOL wait)
{
  return this->m_pFileSystemPassThru->AsyncFinish(this: this->m_pFileSystemPassThru, a2: hControl, a3: wait);
}

//------------------------------------------------------------------------------
// Address: 0x10028E40
// Name: public: virtual enum FSAsyncStatus_t CFileSystemPassThru::AsyncGetResult(struct FSAsyncControl_t__ __near *,void __near * __near *,int __near *)
// Source: json
//------------------------------------------------------------------------------
FSAsyncStatus_t __thiscall CFileSystemPassThru::AsyncGetResult(
        CFileSystemPassThru *this,
        FSAsyncControl_t__ *hControl,
        void **ppData,
        int *pSize)
{
  return this->m_pFileSystemPassThru->AsyncGetResult(
           this: this->m_pFileSystemPassThru,
           a2: hControl,
           a3: ppData,
           a4: pSize);
}

//------------------------------------------------------------------------------
// Address: 0x10028E60
// Name: public: virtual enum FSAsyncStatus_t CFileSystemPassThru::AsyncAbort(struct FSAsyncControl_t__ __near *)
// Source: json
//------------------------------------------------------------------------------
FSAsyncStatus_t __thiscall CFileSystemPassThru::AsyncAbort(CFileSystemPassThru *this, FSAsyncControl_t__ *hControl)
{
  return this->m_pFileSystemPassThru->AsyncAbort(this: this->m_pFileSystemPassThru, a2: hControl);
}

//------------------------------------------------------------------------------
// Address: 0x10028E80
// Name: public: virtual enum FSAsyncStatus_t CFileSystemPassThru::AsyncStatus(struct FSAsyncControl_t__ __near *)
// Source: json
//------------------------------------------------------------------------------
FSAsyncStatus_t __thiscall CFileSystemPassThru::AsyncStatus(CFileSystemPassThru *this, FSAsyncControl_t__ *hControl)
{
  return this->m_pFileSystemPassThru->AsyncStatus(this: this->m_pFileSystemPassThru, a2: hControl);
}

//------------------------------------------------------------------------------
// Address: 0x10028EA0
// Name: public: virtual enum FSAsyncStatus_t CFileSystemPassThru::AsyncFlush(void)
// Source: json
//------------------------------------------------------------------------------
FSAsyncStatus_t __thiscall CFileSystemPassThru::AsyncFlush(CFileSystemPassThru *this)
{
  return this->m_pFileSystemPassThru->AsyncFlush(this: this->m_pFileSystemPassThru);
}

//------------------------------------------------------------------------------
// Address: 0x10028EB0
// Name: public: virtual void CFileSystemPassThru::AsyncAddRef(struct FSAsyncControl_t__ __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFileSystemPassThru::AsyncAddRef(CFileSystemPassThru *this, FSAsyncControl_t__ *hControl)
{
  this->m_pFileSystemPassThru->AsyncAddRef(this: this->m_pFileSystemPassThru, a2: hControl);
}

//------------------------------------------------------------------------------
// Address: 0x10028ED0
// Name: public: virtual void CFileSystemPassThru::AsyncRelease(struct FSAsyncControl_t__ __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFileSystemPassThru::AsyncRelease(CFileSystemPassThru *this, FSAsyncControl_t__ *hControl)
{
  this->m_pFileSystemPassThru->AsyncRelease(this: this->m_pFileSystemPassThru, a2: hControl);
}

//------------------------------------------------------------------------------
// Address: 0x10028EF0
// Name: public: virtual enum FSAsyncStatus_t CFileSystemPassThru::AsyncBeginRead(char const __near *,struct FSAsyncFile_t__ __near * __near *)
// Source: json
//------------------------------------------------------------------------------
FSAsyncStatus_t __thiscall CFileSystemPassThru::AsyncBeginRead(
        CFileSystemPassThru *this,
        const char *pszFile,
        FSAsyncFile_t__ **phFile)
{
  return this->m_pFileSystemPassThru->AsyncBeginRead(this: this->m_pFileSystemPassThru, a2: pszFile, a3: phFile);
}

//------------------------------------------------------------------------------
// Address: 0x10028F10
// Name: public: virtual enum FSAsyncStatus_t CFileSystemPassThru::AsyncEndRead(struct FSAsyncFile_t__ __near *)
// Source: json
//------------------------------------------------------------------------------
FSAsyncStatus_t __thiscall CFileSystemPassThru::AsyncEndRead(CFileSystemPassThru *this, FSAsyncFile_t__ *hFile)
{
  return this->m_pFileSystemPassThru->AsyncEndRead(this: this->m_pFileSystemPassThru, a2: hFile);
}

//------------------------------------------------------------------------------
// Address: 0x10028F30
// Name: public: virtual struct FileSystemStatistics const __near * CFileSystemPassThru::GetFilesystemStatistics(void)
// Source: json
//------------------------------------------------------------------------------
const FileSystemStatistics *__thiscall CFileSystemPassThru::GetFilesystemStatistics(CFileSystemPassThru *this)
{
  return this->m_pFileSystemPassThru->GetFilesystemStatistics(this: this->m_pFileSystemPassThru);
}

//------------------------------------------------------------------------------
// Address: 0x10028F40
// Name: public: virtual int CFileSystemPassThru::WaitForResources(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CFileSystemPassThru::WaitForResources(CFileSystemPassThru *this, const char *resourcelist)
{
  return this->m_pFileSystemPassThru->WaitForResources(this: this->m_pFileSystemPassThru, a2: resourcelist);
}

//------------------------------------------------------------------------------
// Address: 0x10028F60
// Name: public: virtual bool CFileSystemPassThru::GetWaitForResourcesProgress(int,float __near *,bool __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CFileSystemPassThru::GetWaitForResourcesProgress(
        CFileSystemPassThru *this,
        int handle,
        float *progress,
        bool *complete)
{
  return this->m_pFileSystemPassThru->GetWaitForResourcesProgress(
           this: this->m_pFileSystemPassThru,
           a2: handle,
           a3: progress,
           a4: complete);
}

//------------------------------------------------------------------------------
// Address: 0x10028F80
// Name: public: virtual void CFileSystemPassThru::CancelWaitForResources(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFileSystemPassThru::CancelWaitForResources(CFileSystemPassThru *this, int handle)
{
  this->m_pFileSystemPassThru->CancelWaitForResources(this: this->m_pFileSystemPassThru, a2: handle);
}

//------------------------------------------------------------------------------
// Address: 0x10028FA0
// Name: public: virtual int CFileSystemPassThru::HintResourceNeed(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CFileSystemPassThru::HintResourceNeed(
        CFileSystemPassThru *this,
        const char *hintlist,
        int forgetEverything)
{
  return this->m_pFileSystemPassThru->HintResourceNeed(
           this: this->m_pFileSystemPassThru,
           a2: hintlist,
           a3: forgetEverything);
}

//------------------------------------------------------------------------------
// Address: 0x10028FC0
// Name: public: virtual bool CFileSystemPassThru::IsFileImmediatelyAvailable(char const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CFileSystemPassThru::IsFileImmediatelyAvailable(CFileSystemPassThru *this, const char *pFileName)
{
  return this->m_pFileSystemPassThru->IsFileImmediatelyAvailable(this: this->m_pFileSystemPassThru, a2: pFileName);
}

//------------------------------------------------------------------------------
// Address: 0x10028FE0
// Name: public: virtual void CFileSystemPassThru::GetLocalCopy(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFileSystemPassThru::GetLocalCopy(CFileSystemPassThru *this, const char *pFileName)
{
  this->m_pFileSystemPassThru->GetLocalCopy(this: this->m_pFileSystemPassThru, a2: pFileName);
}

//------------------------------------------------------------------------------
// Address: 0x10029000
// Name: public: virtual void __near * CFileSystemPassThru::FindOrAddFileName(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void *__thiscall CFileSystemPassThru::FindOrAddFileName(CFileSystemPassThru *this, const char *pFileName)
{
  return this->m_pFileSystemPassThru->FindOrAddFileName(this: this->m_pFileSystemPassThru, a2: pFileName);
}

//------------------------------------------------------------------------------
// Address: 0x10029020
// Name: public: virtual void __near * CFileSystemPassThru::FindFileName(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void *__thiscall CFileSystemPassThru::FindFileName(CFileSystemPassThru *this, const char *pFileName)
{
  return this->m_pFileSystemPassThru->FindFileName(this: this->m_pFileSystemPassThru, a2: pFileName);
}

//------------------------------------------------------------------------------
// Address: 0x10029040
// Name: public: virtual bool CFileSystemPassThru::String(void __near * const __near &,char __near *,int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CFileSystemPassThru::String(CFileSystemPassThru *this, void *const *handle, char *buf, int buflen)
{
  return this->m_pFileSystemPassThru->String(this: this->m_pFileSystemPassThru, a2: handle, a3: buf, a4: buflen);
}

//------------------------------------------------------------------------------
// Address: 0x10029060
// Name: public: virtual bool CFileSystemPassThru::IsOk2(void __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CFileSystemPassThru::IsOk2(CFileSystemPassThru *this, void *file)
{
  return this->IsOk(this, a2: file);
}

//------------------------------------------------------------------------------
// Address: 0x10029070
// Name: public: virtual void CFileSystemPassThru::RemoveSearchPaths(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFileSystemPassThru::RemoveSearchPaths(CFileSystemPassThru *this, const char *szPathID)
{
  this->m_pFileSystemPassThru->RemoveSearchPaths(this: this->m_pFileSystemPassThru, a2: szPathID);
}

//------------------------------------------------------------------------------
// Address: 0x10029080
// Name: public: virtual bool CFileSystemPassThru::IsSteam(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CFileSystemPassThru::IsSteam(CFileSystemPassThru *this)
{
  return this->m_pFileSystemPassThru->IsSteam(this: this->m_pFileSystemPassThru);
}

//------------------------------------------------------------------------------
// Address: 0x10029090
// Name: public: virtual enum FilesystemMountRetval_t CFileSystemPassThru::MountSteamContent(int)
// Source: json
//------------------------------------------------------------------------------
FilesystemMountRetval_t __thiscall CFileSystemPassThru::MountSteamContent(CFileSystemPassThru *this, int nExtraAppId)
{
  return this->m_pFileSystemPassThru->MountSteamContent(this: this->m_pFileSystemPassThru, a2: nExtraAppId);
}

//------------------------------------------------------------------------------
// Address: 0x100290A0
// Name: public: virtual char const __near * CFileSystemPassThru::FindFirstEx(char const __near *,char const __near *,int __near *)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CFileSystemPassThru::FindFirstEx(
        CFileSystemPassThru *this,
        const char *pWildCard,
        const char *pPathID,
        int *pHandle)
{
  return this->m_pFileSystemPassThru->FindFirstEx(
           this: this->m_pFileSystemPassThru,
           a2: pWildCard,
           a3: pPathID,
           a4: pHandle);
}

//------------------------------------------------------------------------------
// Address: 0x100290C0
// Name: public: virtual void CFileSystemPassThru::MarkPathIDByRequestOnly(char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFileSystemPassThru::MarkPathIDByRequestOnly(
        CFileSystemPassThru *this,
        const char *pPathID,
        BOOL bRequestOnly)
{
  this->m_pFileSystemPassThru->MarkPathIDByRequestOnly(this: this->m_pFileSystemPassThru, a2: pPathID, a3: bRequestOnly);
}

//------------------------------------------------------------------------------
// Address: 0x100290D0
// Name: public: virtual bool CFileSystemPassThru::AddPackFile(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CFileSystemPassThru::AddPackFile(CFileSystemPassThru *this, const char *fullpath, const char *pathID)
{
  return this->m_pFileSystemPassThru->AddPackFile(this: this->m_pFileSystemPassThru, a2: fullpath, a3: pathID);
}

//------------------------------------------------------------------------------
// Address: 0x100290E0
// Name: public: virtual enum FSAsyncStatus_t CFileSystemPassThru::AsyncAppend(char const __near *,void const __near *,int,bool,struct FSAsyncControl_t__ __near * __near *)
// Source: json
//------------------------------------------------------------------------------
FSAsyncStatus_t __thiscall CFileSystemPassThru::AsyncAppend(
        CFileSystemPassThru *this,
        const char *pFileName,
        const void *pSrc,
        int nSrcBytes,
        BOOL bFreeMemory,
        FSAsyncControl_t__ **pControl)
{
  return this->m_pFileSystemPassThru->AsyncAppend(
           this: this->m_pFileSystemPassThru,
           a2: pFileName,
           a3: pSrc,
           a4: nSrcBytes,
           a5: bFreeMemory,
           a6: pControl);
}

//------------------------------------------------------------------------------
// Address: 0x10029100
// Name: public: virtual enum FSAsyncStatus_t CFileSystemPassThru::AsyncWrite(char const __near *,void const __near *,int,bool,bool,struct FSAsyncControl_t__ __near * __near *)
// Source: json
//------------------------------------------------------------------------------
FSAsyncStatus_t __thiscall CFileSystemPassThru::AsyncWrite(
        CFileSystemPassThru *this,
        const char *pFileName,
        const void *pSrc,
        int nSrcBytes,
        BOOL bFreeMemory,
        BOOL bAppend,
        FSAsyncControl_t__ **pControl)
{
  return this->m_pFileSystemPassThru->AsyncWrite(
           this: this->m_pFileSystemPassThru,
           a2: pFileName,
           a3: pSrc,
           a4: nSrcBytes,
           a5: bFreeMemory,
           a6: bAppend,
           a7: pControl);
}

//------------------------------------------------------------------------------
// Address: 0x10029120
// Name: public: virtual enum FSAsyncStatus_t CFileSystemPassThru::AsyncWriteFile(char const __near *,class CUtlBuffer const __near *,int,bool,bool,struct FSAsyncControl_t__ __near * __near *)
// Source: json
//------------------------------------------------------------------------------
FSAsyncStatus_t __thiscall CFileSystemPassThru::AsyncWriteFile(
        CFileSystemPassThru *this,
        const char *pFileName,
        const CUtlBuffer *pSrc,
        int nSrcBytes,
        BOOL bFreeMemory,
        BOOL bAppend,
        FSAsyncControl_t__ **pControl)
{
  return this->m_pFileSystemPassThru->AsyncWriteFile(
           this: this->m_pFileSystemPassThru,
           a2: pFileName,
           a3: pSrc,
           a4: nSrcBytes,
           a5: bFreeMemory,
           a6: bAppend,
           a7: pControl);
}

//------------------------------------------------------------------------------
// Address: 0x10029140
// Name: public: virtual enum FSAsyncStatus_t CFileSystemPassThru::AsyncAppendFile(char const __near *,char const __near *,struct FSAsyncControl_t__ __near * __near *)
// Source: json
//------------------------------------------------------------------------------
FSAsyncStatus_t __thiscall CFileSystemPassThru::AsyncAppendFile(
        CFileSystemPassThru *this,
        const char *pDestFileName,
        const char *pSrcFileName,
        FSAsyncControl_t__ **pControl)
{
  return this->m_pFileSystemPassThru->AsyncAppendFile(
           this: this->m_pFileSystemPassThru,
           a2: pDestFileName,
           a3: pSrcFileName,
           a4: pControl);
}

//------------------------------------------------------------------------------
// Address: 0x10029160
// Name: public: virtual void CFileSystemPassThru::AsyncFinishAll(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFileSystemPassThru::AsyncFinishAll(CFileSystemPassThru *this, int iToPriority)
{
  this->m_pFileSystemPassThru->AsyncFinishAll(this: this->m_pFileSystemPassThru, a2: iToPriority);
}

//------------------------------------------------------------------------------
// Address: 0x10029180
// Name: public: virtual void CFileSystemPassThru::AsyncFinishAllWrites(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFileSystemPassThru::AsyncFinishAllWrites(CFileSystemPassThru *this)
{
  this->m_pFileSystemPassThru->AsyncFinishAllWrites(this: this->m_pFileSystemPassThru);
}

//------------------------------------------------------------------------------
// Address: 0x10029190
// Name: public: virtual enum FSAsyncStatus_t CFileSystemPassThru::AsyncSetPriority(struct FSAsyncControl_t__ __near *,int)
// Source: json
//------------------------------------------------------------------------------
FSAsyncStatus_t __thiscall CFileSystemPassThru::AsyncSetPriority(
        CFileSystemPassThru *this,
        FSAsyncControl_t__ *hControl,
        int newPriority)
{
  return this->m_pFileSystemPassThru->AsyncSetPriority(this: this->m_pFileSystemPassThru, a2: hControl, a3: newPriority);
}

//------------------------------------------------------------------------------
// Address: 0x100291B0
// Name: public: virtual bool CFileSystemPassThru::AsyncSuspend(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CFileSystemPassThru::AsyncSuspend(CFileSystemPassThru *this)
{
  return this->m_pFileSystemPassThru->AsyncSuspend(this: this->m_pFileSystemPassThru);
}

//------------------------------------------------------------------------------
// Address: 0x100291C0
// Name: public: virtual bool CFileSystemPassThru::AsyncResume(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CFileSystemPassThru::AsyncResume(CFileSystemPassThru *this)
{
  return this->m_pFileSystemPassThru->AsyncResume(this: this->m_pFileSystemPassThru);
}

//------------------------------------------------------------------------------
// Address: 0x100291D0
// Name: public: virtual char const __near * CFileSystemPassThru::RelativePathToFullPath(char const __near *,char const __near *,char __near *,int,enum PathTypeFilter_t,unsigned int __near *)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CFileSystemPassThru::RelativePathToFullPath(
        CFileSystemPassThru *this,
        const char *pFileName,
        const char *pPathID,
        char *pLocalPath,
        int localPathBufferSize,
        PathTypeFilter_t pathFilter,
        unsigned int *pPathType)
{
  return this->m_pFileSystemPassThru->RelativePathToFullPath(
           this: this->m_pFileSystemPassThru,
           a2: pFileName,
           a3: pPathID,
           a4: pLocalPath,
           a5: localPathBufferSize,
           a6: pathFilter,
           a7: pPathType);
}

//------------------------------------------------------------------------------
// Address: 0x100291E0
// Name: public: virtual int CFileSystemPassThru::GetSearchPath(char const __near *,bool,char __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CFileSystemPassThru::GetSearchPath(
        CFileSystemPassThru *this,
        const char *pathID,
        BOOL bGetPackFiles,
        char *pPath,
        int nMaxLen)
{
  return this->m_pFileSystemPassThru->GetSearchPath(
           this: this->m_pFileSystemPassThru,
           a2: pathID,
           a3: bGetPackFiles,
           a4: pPath,
           a5: nMaxLen);
}

//------------------------------------------------------------------------------
// Address: 0x100291F0
// Name: public: virtual void __near * CFileSystemPassThru::OpenEx(char const __near *,char const __near *,unsigned int,char const __near *,char __near * __near *)
// Source: json
//------------------------------------------------------------------------------
void *__thiscall CFileSystemPassThru::OpenEx(
        CFileSystemPassThru *this,
        const char *pFileName,
        const char *pOptions,
        unsigned int flags,
        const char *pathID,
        char **ppszResolvedFilename)
{
  return this->m_pFileSystemPassThru->OpenEx(
           this: this->m_pFileSystemPassThru,
           a2: pFileName,
           a3: pOptions,
           a4: flags,
           a5: pathID,
           a6: ppszResolvedFilename);
}

//------------------------------------------------------------------------------
// Address: 0x10029210
// Name: public: virtual int CFileSystemPassThru::ReadEx(void __near *,int,int,void __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CFileSystemPassThru::ReadEx(
        CFileSystemPassThru *this,
        void *pOutput,
        int destSize,
        int size,
        void *file)
{
  return this->m_pFileSystemPassThru->ReadEx(
           this: this->m_pFileSystemPassThru,
           a2: pOutput,
           a3: destSize,
           a4: size,
           a5: file);
}

//------------------------------------------------------------------------------
// Address: 0x10029230
// Name: public: virtual int CFileSystemPassThru::ReadFileEx(char const __near *,char const __near *,void __near * __near *,bool,bool,int,int,void __near * (*)(char const __near *,unsigned int))
// Source: json
//------------------------------------------------------------------------------
int __thiscall CFileSystemPassThru::ReadFileEx(
        CFileSystemPassThru *this,
        const char *pFileName,
        const char *pPath,
        void **ppBuf,
        BOOL bNullTerminate,
        BOOL bOptimalAlloc,
        int nMaxBytes,
        int nStartingByte,
        void *(__cdecl *pfnAlloc)(const char *, unsigned int))
{
  return this->m_pFileSystemPassThru->ReadFileEx(
           this: this->m_pFileSystemPassThru,
           a2: pFileName,
           a3: pPath,
           a4: ppBuf,
           a5: bNullTerminate,
           a6: bOptimalAlloc,
           a7: nMaxBytes,
           a8: nStartingByte,
           a9: pfnAlloc);
}

//------------------------------------------------------------------------------
// Address: 0x10029250
// Name: public: virtual void CVMPIFile_Memory::Flush(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVMPIFile_Memory::Flush(CFileSystemPassThru *this)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x10029260
// Name: public: virtual class KeyValues __near * CFileSystemPassThru::LoadKeyValues(enum IFileSystem::KeyValuesPreloadType_t,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
KeyValues *__thiscall CFileSystemPassThru::LoadKeyValues(
        CFileSystemPassThru *this,
        IFileSystem::KeyValuesPreloadType_t type,
        const char *filename,
        const char *pPathID)
{
  return this->m_pFileSystemPassThru->LoadKeyValues_2(
           this: this->m_pFileSystemPassThru,
           a2: type,
           a3: filename,
           a4: pPathID);
}

//------------------------------------------------------------------------------
// Address: 0x10029280
// Name: public: virtual bool CFileSystemPassThru::LoadKeyValues(class KeyValues __near &,enum IFileSystem::KeyValuesPreloadType_t,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CFileSystemPassThru::LoadKeyValues(
        CFileSystemPassThru *this,
        KeyValues *head,
        IFileSystem::KeyValuesPreloadType_t type,
        const char *filename,
        const char *pPathID)
{
  return this->m_pFileSystemPassThru->LoadKeyValues(
           this: this->m_pFileSystemPassThru,
           a2: head,
           a3: type,
           a4: filename,
           a5: pPathID);
}

//------------------------------------------------------------------------------
// Address: 0x100292A0
// Name: public: virtual bool CFileSystemPassThru::GetFileTypeForFullPath(char const __near *,wchar_t __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CFileSystemPassThru::GetFileTypeForFullPath(
        CFileSystemPassThru *this,
        const char *pFullPath,
        wchar_t *buf,
        unsigned int bufSizeInBytes)
{
  return this->m_pFileSystemPassThru->GetFileTypeForFullPath(
           this: this->m_pFileSystemPassThru,
           a2: pFullPath,
           a3: buf,
           a4: bufSizeInBytes);
}

//------------------------------------------------------------------------------
// Address: 0x100292C0
// Name: public: virtual bool CFileSystemPassThru::GetOptimalIOConstraints(void __near *,unsigned int __near *,unsigned int __near *,unsigned int __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CFileSystemPassThru::GetOptimalIOConstraints(
        CFileSystemPassThru *this,
        void *hFile,
        unsigned int *pOffsetAlign,
        unsigned int *pSizeAlign,
        unsigned int *pBufferAlign)
{
  return this->m_pFileSystemPassThru->GetOptimalIOConstraints(
           this: this->m_pFileSystemPassThru,
           a2: hFile,
           a3: pOffsetAlign,
           a4: pSizeAlign,
           a5: pBufferAlign);
}

//------------------------------------------------------------------------------
// Address: 0x100292E0
// Name: public: virtual void __near * CFileSystemPassThru::AllocOptimalReadBuffer(void __near *,unsigned int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void *__thiscall CFileSystemPassThru::AllocOptimalReadBuffer(
        CFileSystemPassThru *this,
        void *hFile,
        unsigned int nSize,
        unsigned int nOffset)
{
  return this->m_pFileSystemPassThru->AllocOptimalReadBuffer(
           this: this->m_pFileSystemPassThru,
           a2: hFile,
           a3: nOffset,
           a4: nSize);
}

//------------------------------------------------------------------------------
// Address: 0x10029300
// Name: public: virtual void CFileSystemPassThru::FreeOptimalReadBuffer(void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFileSystemPassThru::FreeOptimalReadBuffer(CFileSystemPassThru *this, void *p)
{
  this->m_pFileSystemPassThru->FreeOptimalReadBuffer(this: this->m_pFileSystemPassThru, a2: p);
}

//------------------------------------------------------------------------------
// Address: 0x10029320
// Name: public: virtual void CFileSystemPassThru::BeginMapAccess(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFileSystemPassThru::BeginMapAccess(CFileSystemPassThru *this)
{
  this->m_pFileSystemPassThru->BeginMapAccess(this: this->m_pFileSystemPassThru);
}

//------------------------------------------------------------------------------
// Address: 0x10029330
// Name: public: virtual void CFileSystemPassThru::EndMapAccess(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFileSystemPassThru::EndMapAccess(CFileSystemPassThru *this)
{
  this->m_pFileSystemPassThru->EndMapAccess(this: this->m_pFileSystemPassThru);
}

//------------------------------------------------------------------------------
// Address: 0x10029340
// Name: public: virtual bool CFileSystemPassThru::ReadToBuffer(void __near *,class CUtlBuffer __near &,int,void __near * (*)(char const __near *,unsigned int))
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CFileSystemPassThru::ReadToBuffer(
        CFileSystemPassThru *this,
        void *hFile,
        CUtlBuffer *buf,
        int nMaxBytes,
        void *(__cdecl *pfnAlloc)(const char *, unsigned int))
{
  return this->m_pFileSystemPassThru->ReadToBuffer(
           this: this->m_pFileSystemPassThru,
           a2: hFile,
           a3: buf,
           a4: nMaxBytes,
           a5: pfnAlloc);
}

//------------------------------------------------------------------------------
// Address: 0x10029360
// Name: public: virtual bool CFileSystemPassThru::FullPathToRelativePathEx(char const __near *,char const __near *,char __near *,int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CFileSystemPassThru::FullPathToRelativePathEx(
        CFileSystemPassThru *this,
        const char *pFullPath,
        const char *pPathId,
        char *pRelative,
        int nMaxLen)
{
  return this->m_pFileSystemPassThru->FullPathToRelativePathEx(
           this: this->m_pFileSystemPassThru,
           a2: pFullPath,
           a3: pPathId,
           a4: pRelative,
           a5: nMaxLen);
}

//------------------------------------------------------------------------------
// Address: 0x10029380
// Name: public: virtual int CFileSystemPassThru::GetPathIndex(void __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CFileSystemPassThru::GetPathIndex(CFileSystemPassThru *this, void *const *handle)
{
  return this->m_pFileSystemPassThru->GetPathIndex(this: this->m_pFileSystemPassThru, a2: handle);
}

//------------------------------------------------------------------------------
// Address: 0x100293A0
// Name: public: virtual long CFileSystemPassThru::GetPathTime(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CFileSystemPassThru::GetPathTime(CFileSystemPassThru *this, const char *pPath, const char *pPathID)
{
  return this->m_pFileSystemPassThru->GetPathTime(this: this->m_pFileSystemPassThru, a2: pPath, a3: pPathID);
}

//------------------------------------------------------------------------------
// Address: 0x100293C0
// Name: public: virtual enum DVDMode_t CFileSystemPassThru::GetDVDMode(void)
// Source: json
//------------------------------------------------------------------------------
DVDMode_t __thiscall CFileSystemPassThru::GetDVDMode(CFileSystemPassThru *this)
{
  return this->m_pFileSystemPassThru->GetDVDMode(this: this->m_pFileSystemPassThru);
}

//------------------------------------------------------------------------------
// Address: 0x100293D0
// Name: public: virtual void CFileSystemPassThru::EnableWhitelistFileTracking(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFileSystemPassThru::EnableWhitelistFileTracking(CFileSystemPassThru *this, BOOL bEnable)
{
  this->m_pFileSystemPassThru->EnableWhitelistFileTracking(this: this->m_pFileSystemPassThru, a2: bEnable);
}

//------------------------------------------------------------------------------
// Address: 0x100293F0
// Name: public: virtual void CFileSystemPassThru::RegisterFileWhitelist(class IFileList __near *,class IFileList __near *,class IFileList __near * __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFileSystemPassThru::RegisterFileWhitelist(
        CFileSystemPassThru *this,
        struct IFileList *pForceMatchList,
        struct IFileList *pAllowFromDiskList,
        struct IFileList **pFilesToReload)
{
  this->m_pFileSystemPassThru->RegisterFileWhitelist(
    this: this->m_pFileSystemPassThru,
    a2: pForceMatchList,
    a3: pAllowFromDiskList,
    a4: pFilesToReload);
}

//------------------------------------------------------------------------------
// Address: 0x10029410
// Name: public: virtual void CFileSystemPassThru::MarkAllCRCsUnverified(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFileSystemPassThru::MarkAllCRCsUnverified(CFileSystemPassThru *this)
{
  this->m_pFileSystemPassThru->MarkAllCRCsUnverified(this: this->m_pFileSystemPassThru);
}

//------------------------------------------------------------------------------
// Address: 0x10029420
// Name: public: virtual void CFileSystemPassThru::CacheFileCRCs(char const __near *,enum ECacheCRCType,class IFileList __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFileSystemPassThru::CacheFileCRCs(
        CFileSystemPassThru *this,
        const char *pPathname,
        ECacheCRCType eType,
        struct IFileList *pFilter)
{
  this->m_pFileSystemPassThru->CacheFileCRCs(this: this->m_pFileSystemPassThru, a2: pPathname, a3: eType, a4: pFilter);
}

//------------------------------------------------------------------------------
// Address: 0x10029440
// Name: public: virtual enum EFileCRCStatus CFileSystemPassThru::CheckCachedFileCRC(char const __near *,char const __near *,unsigned long __near *)
// Source: json
//------------------------------------------------------------------------------
EFileCRCStatus __thiscall CFileSystemPassThru::CheckCachedFileCRC(
        CFileSystemPassThru *this,
        const char *pPathID,
        const char *pRelativeFilename,
        unsigned int *pCRC)
{
  return this->m_pFileSystemPassThru->CheckCachedFileCRC(
           this: this->m_pFileSystemPassThru,
           a2: pPathID,
           a3: pRelativeFilename,
           a4: pCRC);
}

//------------------------------------------------------------------------------
// Address: 0x10029460
// Name: public: virtual int CFileSystemPassThru::GetUnverifiedCRCFiles(class CUnverifiedCRCFile __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CFileSystemPassThru::GetUnverifiedCRCFiles(
        CFileSystemPassThru *this,
        CUnverifiedCRCFile *pFiles,
        int nMaxFiles)
{
  return this->m_pFileSystemPassThru->GetUnverifiedCRCFiles(
           this: this->m_pFileSystemPassThru,
           a2: pFiles,
           a3: nMaxFiles);
}

//------------------------------------------------------------------------------
// Address: 0x10029480
// Name: public: virtual int CFileSystemPassThru::GetWhitelistSpewFlags(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CFileSystemPassThru::GetWhitelistSpewFlags(CFileSystemPassThru *this)
{
  return this->m_pFileSystemPassThru->GetWhitelistSpewFlags(this: this->m_pFileSystemPassThru);
}

//------------------------------------------------------------------------------
// Address: 0x10029490
// Name: public: virtual void CFileSystemPassThru::SetWhitelistSpewFlags(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFileSystemPassThru::SetWhitelistSpewFlags(CFileSystemPassThru *this, int spewFlags)
{
  this->m_pFileSystemPassThru->SetWhitelistSpewFlags(this: this->m_pFileSystemPassThru, a2: spewFlags);
}

//------------------------------------------------------------------------------
// Address: 0x100294B0
// Name: public: virtual void CFileSystemPassThru::InstallDirtyDiskReportFunc(void (*)(void))
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFileSystemPassThru::InstallDirtyDiskReportFunc(CFileSystemPassThru *this, void (__cdecl *func)())
{
  this->m_pFileSystemPassThru->InstallDirtyDiskReportFunc(this: this->m_pFileSystemPassThru, a2: func);
}

//------------------------------------------------------------------------------
// Address: 0x100294D0
// Name: public: virtual bool CFileSystemPassThru::IsLaunchedFromXboxHDD(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CFileSystemPassThru::IsLaunchedFromXboxHDD(CFileSystemPassThru *this)
{
  return this->m_pFileSystemPassThru->IsLaunchedFromXboxHDD(this: this->m_pFileSystemPassThru);
}

//------------------------------------------------------------------------------
// Address: 0x100294E0
// Name: public: virtual bool CFileSystemPassThru::IsInstalledToXboxHDDCache(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CFileSystemPassThru::IsInstalledToXboxHDDCache(CFileSystemPassThru *this)
{
  return this->m_pFileSystemPassThru->IsInstalledToXboxHDDCache(this: this->m_pFileSystemPassThru);
}

//------------------------------------------------------------------------------
// Address: 0x100294F0
// Name: public: virtual bool CFileSystemPassThru::IsDVDHosted(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CFileSystemPassThru::IsDVDHosted(CFileSystemPassThru *this)
{
  return this->m_pFileSystemPassThru->IsDVDHosted(this: this->m_pFileSystemPassThru);
}

//------------------------------------------------------------------------------
// Address: 0x10029500
// Name: public: virtual bool CFileSystemPassThru::IsInstallAllowed(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CFileSystemPassThru::IsInstallAllowed(CFileSystemPassThru *this)
{
  return this->m_pFileSystemPassThru->IsInstallAllowed(this: this->m_pFileSystemPassThru);
}

//------------------------------------------------------------------------------
// Address: 0x10029510
// Name: public: virtual int CFileSystemPassThru::GetSearchPathID(char __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CFileSystemPassThru::GetSearchPathID(CFileSystemPassThru *this, char *pPath, int nMaxLen)
{
  return this->m_pFileSystemPassThru->GetSearchPathID(this: this->m_pFileSystemPassThru, a2: pPath, a3: nMaxLen);
}

//------------------------------------------------------------------------------
// Address: 0x10029530
// Name: public: virtual bool CFileSystemPassThru::FixupSearchPathsAfterInstall(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CFileSystemPassThru::FixupSearchPathsAfterInstall(CFileSystemPassThru *this)
{
  return this->m_pFileSystemPassThru->FixupSearchPathsAfterInstall(this: this->m_pFileSystemPassThru);
}

//------------------------------------------------------------------------------
// Address: 0x10029540
// Name: public: virtual void (*CFileSystemPassThru::GetDirtyDiskReportFunc(void))(void)
// Source: json
//------------------------------------------------------------------------------
void (__cdecl *__thiscall CFileSystemPassThru::GetDirtyDiskReportFunc(CFileSystemPassThru *this))()
{
  return this->m_pFileSystemPassThru->GetDirtyDiskReportFunc(this: this->m_pFileSystemPassThru);
}

//------------------------------------------------------------------------------
// Address: 0x10029550
// Name: public: virtual void CFileSystemPassThru::AddVPKFile(char const __near *,enum SearchPathAdd_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFileSystemPassThru::AddVPKFile(
        CFileSystemPassThru *this,
        const char *pPkName,
        SearchPathAdd_t addType)
{
  this->m_pFileSystemPassThru->AddVPKFile(this: this->m_pFileSystemPassThru, a2: pPkName, a3: addType);
}

//------------------------------------------------------------------------------
// Address: 0x10029570
// Name: public: virtual void CFileSystemPassThru::RemoveVPKFile(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFileSystemPassThru::RemoveVPKFile(CFileSystemPassThru *this, const char *pPkName)
{
  this->m_pFileSystemPassThru->RemoveVPKFile(this: this->m_pFileSystemPassThru, a2: pPkName);
}

//------------------------------------------------------------------------------
// Address: 0x10029590
// Name: public: virtual void CFileSystemPassThru::GetVPKFileNames(class CUtlVector<class CUtlString,class CUtlMemory<class CUtlString,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFileSystemPassThru::GetVPKFileNames(
        CFileSystemPassThru *this,
        CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *destVector)
{
  this->m_pFileSystemPassThru->GetVPKFileNames(this: this->m_pFileSystemPassThru, a2: destVector);
}

//------------------------------------------------------------------------------
// Address: 0x100295B0
// Name: public: virtual void CFileSystemPassThru::RemoveAllMapSearchPaths(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFileSystemPassThru::RemoveAllMapSearchPaths(CFileSystemPassThru *this)
{
  this->m_pFileSystemPassThru->RemoveAllMapSearchPaths(this: this->m_pFileSystemPassThru);
}

//------------------------------------------------------------------------------
// Address: 0x100295C0
// Name: public: virtual void CFileSystemPassThru::SyncDvdDevCache(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFileSystemPassThru::SyncDvdDevCache(CFileSystemPassThru *this)
{
  this->m_pFileSystemPassThru->SyncDvdDevCache(this: this->m_pFileSystemPassThru);
}

//------------------------------------------------------------------------------
// Address: 0x100295D0
// Name: public: virtual bool CFileSystemPassThru::GetStringFromKVPool(unsigned long,unsigned int,char __near *,int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CFileSystemPassThru::GetStringFromKVPool(
        CFileSystemPassThru *this,
        unsigned int poolKey,
        unsigned int key,
        char *pOutBuff,
        int buflen)
{
  return this->m_pFileSystemPassThru->GetStringFromKVPool(
           this: this->m_pFileSystemPassThru,
           a2: poolKey,
           a3: key,
           a4: pOutBuff,
           a5: buflen);
}

//------------------------------------------------------------------------------
// Address: 0x100295F0
// Name: public: virtual bool CFileSystemPassThru::DiscoverDLC(int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CFileSystemPassThru::DiscoverDLC(CFileSystemPassThru *this, int iController)
{
  return this->m_pFileSystemPassThru->DiscoverDLC(this: this->m_pFileSystemPassThru, a2: iController);
}

//------------------------------------------------------------------------------
// Address: 0x10029610
// Name: public: virtual int CFileSystemPassThru::IsAnyDLCPresent(bool __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CFileSystemPassThru::IsAnyDLCPresent(CFileSystemPassThru *this, bool *pbDLCSearchPathMounted)
{
  return this->m_pFileSystemPassThru->IsAnyDLCPresent(this: this->m_pFileSystemPassThru, a2: pbDLCSearchPathMounted);
}

//------------------------------------------------------------------------------
// Address: 0x10029630
// Name: public: virtual bool CFileSystemPassThru::GetAnyDLCInfo(int,unsigned int __near *,wchar_t __near *,int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CFileSystemPassThru::GetAnyDLCInfo(
        CFileSystemPassThru *this,
        int iDLC,
        unsigned int *pLicenseMask,
        wchar_t *pTitleBuff,
        int nOutTitleSize)
{
  return this->m_pFileSystemPassThru->GetAnyDLCInfo(
           this: this->m_pFileSystemPassThru,
           a2: iDLC,
           a3: pLicenseMask,
           a4: pTitleBuff,
           a5: nOutTitleSize);
}

//------------------------------------------------------------------------------
// Address: 0x10029650
// Name: public: virtual int CFileSystemPassThru::IsAnyCorruptDLC(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CFileSystemPassThru::IsAnyCorruptDLC(CFileSystemPassThru *this)
{
  return this->m_pFileSystemPassThru->IsAnyCorruptDLC(this: this->m_pFileSystemPassThru);
}

//------------------------------------------------------------------------------
// Address: 0x10029660
// Name: public: virtual bool CFileSystemPassThru::GetAnyCorruptDLCInfo(int,wchar_t __near *,int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CFileSystemPassThru::GetAnyCorruptDLCInfo(
        CFileSystemPassThru *this,
        int iCorruptDLC,
        wchar_t *pTitleBuff,
        int nOutTitleSize)
{
  return this->m_pFileSystemPassThru->GetAnyCorruptDLCInfo(
           this: this->m_pFileSystemPassThru,
           a2: iCorruptDLC,
           a3: pTitleBuff,
           a4: nOutTitleSize);
}

//------------------------------------------------------------------------------
// Address: 0x10029680
// Name: public: virtual bool CFileSystemPassThru::AddDLCSearchPaths(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CFileSystemPassThru::AddDLCSearchPaths(CFileSystemPassThru *this)
{
  return this->m_pFileSystemPassThru->AddDLCSearchPaths(this: this->m_pFileSystemPassThru);
}

//------------------------------------------------------------------------------
// Address: 0x10029690
// Name: public: virtual bool CFileSystemPassThru::IsSpecificDLCPresent(unsigned int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CFileSystemPassThru::IsSpecificDLCPresent(CFileSystemPassThru *this, unsigned int nDLCPackage)
{
  return this->m_pFileSystemPassThru->IsSpecificDLCPresent(this: this->m_pFileSystemPassThru, a2: nDLCPackage);
}

//------------------------------------------------------------------------------
// Address: 0x100296B0
// Name: public: virtual void CFileSystemPassThru::SetIODelayAlarm(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFileSystemPassThru::SetIODelayAlarm(CFileSystemPassThru *this, float flThreshhold)
{
  ((void (__stdcall *)(_DWORD))this->m_pFileSystemPassThru->SetIODelayAlarm)(a1: LODWORD(flThreshhold));
}

//------------------------------------------------------------------------------
// Address: 0x100296D0
// Name: public: virtual bool CFileSystemPassThru::AddXLSPUpdateSearchPath(void const __near *,int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CFileSystemPassThru::AddXLSPUpdateSearchPath(CFileSystemPassThru *this, const void *pData, int nSize)
{
  return this->m_pFileSystemPassThru->AddXLSPUpdateSearchPath(this: this->m_pFileSystemPassThru, a2: pData, a3: nSize);
}

//------------------------------------------------------------------------------
// Address: 0x100296F0
// Name: public: virtual class IIoStats __near * CFileSystemPassThru::GetIoStats(void)
// Source: json
//------------------------------------------------------------------------------
IIoStats *__thiscall CFileSystemPassThru::GetIoStats(CFileSystemPassThru *this)
{
  return this->m_pFileSystemPassThru->GetIoStats(this: this->m_pFileSystemPassThru);
}

//------------------------------------------------------------------------------
// Address: 0x10029730
// Name: public: virtual void CBaseVMPIFileSystem::Release(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseVMPIFileSystem::Release(CBaseVMPIFileSystem *this)
{
  if ( this != nullptr )
    ((void (__thiscall *)(CBaseVMPIFileSystem *, int))this->dtr_CBaseVMPIFileSystem)(a1: this, a2: 1);
}

//------------------------------------------------------------------------------
// Address: 0x10029750
// Name: public: virtual void CBaseVMPIFileSystem::Close(void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseVMPIFileSystem::Close(CBaseVMPIFileSystem *this, void (__thiscall ***file)(_DWORD))
{
  if ( file != nullptr )
    (**file)(a1: file);
}

//------------------------------------------------------------------------------
// Address: 0x10029770
// Name: public: virtual int CBaseVMPIFileSystem::Read(void __near *,int,void __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBaseVMPIFileSystem::Read(CBaseVMPIFileSystem *this, void *pOutput, int size, void *file)
{
  return (*(int (__thiscall **)(void *, void *, int))(*(_DWORD *)file + 20))(a1: file, a2: pOutput, a3: size);
}

//------------------------------------------------------------------------------
// Address: 0x10029790
// Name: public: virtual int CBaseVMPIFileSystem::Write(void const __near *,int,void __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBaseVMPIFileSystem::Write(CBaseVMPIFileSystem *this, const void *pInput, int size, void *file)
{
  return (*(int (__thiscall **)(void *, const void *, int))(*(_DWORD *)file + 24))(a1: file, a2: pInput, a3: size);
}

//------------------------------------------------------------------------------
// Address: 0x100297B0
// Name: public: virtual void CBaseVMPIFileSystem::Seek(void __near *,int,enum FileSystemSeek_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseVMPIFileSystem::Seek(CBaseVMPIFileSystem *this, void *file, int pos, FileSystemSeek_t seekType)
{
  (*(void (__thiscall **)(void *, int, FileSystemSeek_t))(*(_DWORD *)file + 4))(a1: file, a2: pos, a3: seekType);
}

//------------------------------------------------------------------------------
// Address: 0x100297D0
// Name: public: virtual unsigned int CBaseVMPIFileSystem::Tell(void __near *)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CBaseVMPIFileSystem::Tell(CBaseVMPIFileSystem *this, void *file)
{
  return (*(unsigned int (__thiscall **)(void *))(*(_DWORD *)file + 8))(a1: file);
}

//------------------------------------------------------------------------------
// Address: 0x100297F0
// Name: public: virtual unsigned int CBaseVMPIFileSystem::Size(void __near *)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CBaseVMPIFileSystem::Size(CBaseVMPIFileSystem *this, void *file)
{
  return (*(unsigned int (__thiscall **)(void *))(*(_DWORD *)file + 12))(a1: file);
}

//------------------------------------------------------------------------------
// Address: 0x10029810
// Name: public: virtual unsigned int CBaseVMPIFileSystem::Size(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBaseVMPIFileSystem::Size(CBaseVMPIFileSystem *this, const char *pFilename, const char *pathID)
{
  int result; // eax
  unsigned int v5; // edi
  int v6; // ebx

  result = ((int (__thiscall *)(CBaseVMPIFileSystem *, const char *, const char *, _DWORD))this->QueryInterface)(
             a1: this,
             a2: pFilename,
             a3: "rb",
             a4: 0);
  v5 = result;
  if ( result != 0 )
  {
    v6 = ((int (__thiscall *)(CBaseVMPIFileSystem *, int))this->Reconnect)(a1: this, a2: result);
    ((void (__thiscall *)(CBaseVMPIFileSystem *, unsigned int))this->Init)(a1: this, a2: v5);
    return v6;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10029860
// Name: public: virtual bool CBaseVMPIFileSystem::FileExists(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CBaseVMPIFileSystem::FileExists(CBaseVMPIFileSystem *this, const char *pFileName, const char *pPathID)
{
  int v4; // eax

  v4 = ((int (__thiscall *)(CBaseVMPIFileSystem *, const char *, const char *, _DWORD))this->QueryInterface)(
         a1: this,
         a2: pFileName,
         a3: "rb",
         a4: 0);
  if ( v4 == 0 )
    return 0;
  ((void (__thiscall *)(CBaseVMPIFileSystem *, int))this->Init)(a1: this, a2: v4);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100298A0
// Name: public: virtual void CBaseVMPIFileSystem::Flush(void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseVMPIFileSystem::Flush(CBaseVMPIFileSystem *this, void *file)
{
  (*(void (__thiscall **)(void *))(*(_DWORD *)file + 16))(a1: file);
}

//------------------------------------------------------------------------------
// Address: 0x100298C0
// Name: public: virtual bool CBaseVMPIFileSystem::Precache(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CBaseVMPIFileSystem::Precache(CBaseVMPIFileSystem *this, const char *pFileName, const char *pPathID)
{
  return false;
}

//------------------------------------------------------------------------------
// Address: 0x100298D0
// Name: public: virtual void CInternalFileSystemPassThru<class IFileSystem>::InitPassThru(class IBaseFileSystem __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInternalFileSystemPassThru<IFileSystem>::InitPassThru(
        CInternalFileSystemPassThru<IFileSystem> *this,
        IBaseFileSystem *pBaseFileSystemPassThru)
{
  this->m_pBaseFileSystemPassThru = pBaseFileSystemPassThru;
}

//------------------------------------------------------------------------------
// Address: 0x100298E0
// Name: public: virtual void __near * CInternalFileSystemPassThru<class IFileSystem>::Open(char const __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void *__thiscall CInternalFileSystemPassThru<IFileSystem>::Open(
        CInternalFileSystemPassThru<IFileSystem> *this,
        const char *pFileName,
        const char *pOptions,
        const char *pathID)
{
  return (*((void *(__thiscall **)(IBaseFileSystem_vtbl *, const char *, const char *, const char *))this->Read + 2))(
           a1: this->IFileSystem::IBaseFileSystem::__vftable,
           a2: pFileName,
           a3: pOptions,
           a4: pathID);
}

//------------------------------------------------------------------------------
// Address: 0x100298F0
// Name: public: virtual bool CInternalFileSystemPassThru<class IFileSystem>::IsFileWritable(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CInternalFileSystemPassThru<IFileSystem>::IsFileWritable(
        CInternalFileSystemPassThru<IFileSystem> *this,
        const char *pFileName,
        const char *pPathID)
{
  return (*((bool (__thiscall **)(IBaseFileSystem_vtbl *, const char *, const char *))this->Read + 11))(
           a1: this->IFileSystem::IBaseFileSystem::__vftable,
           a2: pFileName,
           a3: pPathID);
}

//------------------------------------------------------------------------------
// Address: 0x10029900
// Name: public: virtual bool CInternalFileSystemPassThru<class IFileSystem>::SetFileWritable(char const __near *,bool,char const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __userpurge CInternalFileSystemPassThru<IFileSystem>::SetFileWritable@<al>(
        CInternalFileSystemPassThru<IFileSystem> *this@<ecx>,
        const char *pFileName,
        bool writable,
        const char *pPathID)
{
  return (*((bool (__thiscall **)(IBaseFileSystem_vtbl *, const char *))this->Read + 12))(
           a1: this->IFileSystem::IBaseFileSystem::__vftable,
           a2: pFileName);
}

//------------------------------------------------------------------------------
// Address: 0x10029910
// Name: public: virtual long CInternalFileSystemPassThru<class IFileSystem>::GetFileTime(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CInternalFileSystemPassThru<IFileSystem>::GetFileTime(
        CInternalFileSystemPassThru<IFileSystem> *this,
        const char *pFileName,
        const char *pPathID)
{
  return (*((int (__thiscall **)(IBaseFileSystem_vtbl *, const char *, const char *))this->Read + 13))(
           a1: this->IFileSystem::IBaseFileSystem::__vftable,
           a2: pFileName,
           a3: pPathID);
}

//------------------------------------------------------------------------------
// Address: 0x10029920
// Name: public: virtual bool CInternalFileSystemPassThru<class IFileSystem>::UnzipFile(char const __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CInternalFileSystemPassThru<IFileSystem>::UnzipFile(
        CInternalFileSystemPassThru<IFileSystem> *this,
        const char *pFileName,
        const char *pPath,
        const char *pDestination)
{
  return (*((bool (__thiscall **)(IBaseFileSystem_vtbl *, const char *, const char *, const char *))this->Read + 16))(
           a1: this->IFileSystem::IBaseFileSystem::__vftable,
           a2: pFileName,
           a3: pPath,
           a4: pDestination);
}

//------------------------------------------------------------------------------
// Address: 0x10029930
// Name: public: virtual void CFileSystemPassThru::InitPassThru(class IFileSystem __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFileSystemPassThru::InitPassThru(
        CFileSystemPassThru *this,
        IFileSystem *pFileSystemPassThru,
        bool bBaseOnly)
{
  if ( !bBaseOnly )
    this->m_pFileSystemPassThru = pFileSystemPassThru;
  if ( pFileSystemPassThru != nullptr )
    this->m_pBaseFileSystemPassThru = &pFileSystemPassThru->IBaseFileSystem;
  else
    this->m_pBaseFileSystemPassThru = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10029960
// Name: public: virtual bool CBaseVMPIFileSystem::ReadFile(char const __near *,char const __near *,class CUtlBuffer __near &,int,int,void __near * (*)(char const __near *,unsigned int))
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CBaseVMPIFileSystem::ReadFile(
        CBaseVMPIFileSystem *this,
        const char *pFileName,
        const char *pPath,
        CUtlBuffer *buf,
        int nMaxBytes,
        int nStartingByte,
        void *(__cdecl *pfnAlloc)(const char *, unsigned int))
{
  const char *v9; // eax
  int v10; // ebx
  int v12; // eax
  int nBytesRead; // [esp+1Ch] [ebp+10h]
  int nBytesReada; // [esp+1Ch] [ebp+10h]

  v9 = "rt";
  if ( (buf->m_Flags & 1) == 0 )
    v9 = "rb";
  v10 = ((int (__thiscall *)(CBaseVMPIFileSystem *, const char *, const char *, const char *))this->QueryInterface)(
          a1: this,
          a2: pFileName,
          a3: v9,
          a4: pPath);
  if ( v10 == 0 )
    return false;
  v12 = ((int (__thiscall *)(CBaseVMPIFileSystem *, int))this->Reconnect)(a1: this, a2: v10);
  nBytesRead = v12;
  if ( nMaxBytes > 0 && nMaxBytes < v12 )
  {
    nBytesRead = nMaxBytes;
    v12 = nMaxBytes;
  }
  CUtlBuffer::EnsureCapacity(this: buf, num: v12 + buf->m_Put);
  if ( nStartingByte != 0 )
    ((void (__thiscall *)(CBaseVMPIFileSystem *, int, int, _DWORD))this->Shutdown)(
      a1: this,
      a2: v10,
      a3: nStartingByte,
      a4: 0);
  nBytesReada = ((int (__thiscall *)(CBaseVMPIFileSystem *, unsigned __int8 *, int, int))this->Connect)(
                  a1: this,
                  a2: &buf->m_Memory.m_pMemory[buf->m_Put - buf->m_nOffset],
                  a3: nBytesRead,
                  a4: v10);
  CUtlBuffer::SeekPut(this: buf, type: SEEK_CURRENT, offset: nBytesReada);
  ((void (__thiscall *)(CBaseVMPIFileSystem *, int))this->Init)(a1: this, a2: v10);
  return nBytesReada != 0;
}

//------------------------------------------------------------------------------
// Address: 0x10029A20
// Name: public: virtual bool CBaseVMPIFileSystem::WriteFile(char const __near *,char const __near *,class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CBaseVMPIFileSystem::WriteFile(
        CBaseVMPIFileSystem *this,
        const char *pFileName,
        const char *pPath,
        CUtlBuffer *buf)
{
  const char *v5; // eax
  int v6; // edi
  int v8; // ebx

  v5 = "wt";
  if ( (buf->m_Flags & 1) == 0 )
    v5 = "wb";
  v6 = ((int (__thiscall *)(CBaseVMPIFileSystem *, const char *, const char *, const char *))this->QueryInterface)(
         a1: this,
         a2: pFileName,
         a3: v5,
         a4: pPath);
  if ( v6 == 0 )
    return false;
  v8 = ((int (__thiscall *)(CBaseVMPIFileSystem *, unsigned __int8 *, int, int))this->Disconnect)(
         a1: this,
         a2: buf->m_Memory.m_pMemory,
         a3: buf->m_nMaxPut,
         a4: v6);
  ((void (__thiscall *)(CBaseVMPIFileSystem *, int))this->Init)(a1: this, a2: v6);
  return v8 != 0;
}

//------------------------------------------------------------------------------
// Address: 0x1002CED0
// Name: public: virtual bool CFileSystemPassThru::GetCurrentDirectory(char __near *,int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CFileSystemPassThru::GetCurrentDirectory(CFileSystemPassThru *this, char *pDirectory, int maxlen)
{
  return this->m_pFileSystemPassThru->GetCurrentDirectoryA(
           this: this->m_pFileSystemPassThru,
           a2: pDirectory,
           a3: maxlen);
}

} // namespace vvis_dll
