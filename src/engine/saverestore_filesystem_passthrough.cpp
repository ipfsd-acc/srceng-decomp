// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: engine/saverestore_filesystem_passthrough.cpp
// Functions: 26
// ============================================================

#include "engine\saverestore_filesystem_passthrough.h"

//------------------------------------------------------------------------------
// Address: 0x101D2190
// Name: public: virtual bool CSaveRestoreFileSystemPassthrough::FileExists(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CSaveRestoreFileSystemPassthrough::FileExists(
        CSaveRestoreFileSystemPassthrough *this,
        const char *pFileName,
        const char *pPathID)
{
  return g_pFileSystem->FileExists(this: &g_pFileSystem->IBaseFileSystem, a2: pFileName, a3: pPathID);
}

//------------------------------------------------------------------------------
// Address: 0x101D21B0
// Name: public: virtual void CSaveRestoreFileSystemPassthrough::RemoveFile(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSaveRestoreFileSystemPassthrough::RemoveFile(
        CSaveRestoreFileSystemPassthrough *this,
        const char *pRelativePath,
        const char *pathID)
{
  g_pFileSystem->RemoveFile(this: g_pFileSystem, a2: pRelativePath, a3: pathID);
}

//------------------------------------------------------------------------------
// Address: 0x101D21D0
// Name: public: virtual void CSaveRestoreFileSystemPassthrough::RenameFile(char const __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSaveRestoreFileSystemPassthrough::RenameFile(
        CSaveRestoreFileSystemPassthrough *this,
        const char *pOldPath,
        const char *pNewPath,
        const char *pathID)
{
  g_pFileSystem->RenameFile(this: g_pFileSystem, a2: pOldPath, a3: pNewPath, a4: pathID);
}

//------------------------------------------------------------------------------
// Address: 0x101D21F0
// Name: public: virtual void CSaveRestoreFileSystemPassthrough::AsyncFinishAllWrites(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSaveRestoreFileSystemPassthrough::AsyncFinishAllWrites(CSaveRestoreFileSystemPassthrough *this)
{
  g_pFileSystem->AsyncFinishAllWrites(this: g_pFileSystem);
}

//------------------------------------------------------------------------------
// Address: 0x101D2200
// Name: public: virtual void __near * CSaveRestoreFileSystemPassthrough::Open(char const __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void *__thiscall CSaveRestoreFileSystemPassthrough::Open(
        CSaveRestoreFileSystemPassthrough *this,
        const char *pFullName,
        const char *pOptions,
        const char *pathID)
{
  return g_pFileSystem->OpenEx(this: g_pFileSystem, a2: pFullName, a3: pOptions, a4: 4u, a5: pathID, a6: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x101D2230
// Name: public: virtual void CSaveRestoreFileSystemPassthrough::Close(void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSaveRestoreFileSystemPassthrough::Close(CSaveRestoreFileSystemPassthrough *this, void *hSaveFile)
{
  g_pFileSystem->Close(this: &g_pFileSystem->IBaseFileSystem, a2: hSaveFile);
}

//------------------------------------------------------------------------------
// Address: 0x101D2250
// Name: public: virtual int CSaveRestoreFileSystemPassthrough::Read(void __near *,int,void __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CSaveRestoreFileSystemPassthrough::Read(
        CSaveRestoreFileSystemPassthrough *this,
        void *pOutput,
        int size,
        void *hFile)
{
  return g_pFileSystem->Read(this: &g_pFileSystem->IBaseFileSystem, a2: pOutput, a3: size, a4: hFile);
}

//------------------------------------------------------------------------------
// Address: 0x101D2270
// Name: public: virtual int CSaveRestoreFileSystemPassthrough::Write(void const __near *,int,void __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CSaveRestoreFileSystemPassthrough::Write(
        CSaveRestoreFileSystemPassthrough *this,
        const void *pInput,
        int size,
        void *hFile)
{
  return g_pFileSystem->Write(this: &g_pFileSystem->IBaseFileSystem, a2: pInput, a3: size, a4: hFile);
}

//------------------------------------------------------------------------------
// Address: 0x101D2290
// Name: public: virtual void CSaveRestoreFileSystemPassthrough::Seek(void __near *,int,enum FileSystemSeek_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSaveRestoreFileSystemPassthrough::Seek(
        CSaveRestoreFileSystemPassthrough *this,
        void *hFile,
        int pos,
        FileSystemSeek_t method)
{
  g_pFileSystem->Seek(this: &g_pFileSystem->IBaseFileSystem, a2: hFile, a3: pos, a4: method);
}

//------------------------------------------------------------------------------
// Address: 0x101D22B0
// Name: public: virtual unsigned int CSaveRestoreFileSystemPassthrough::Tell(void __near *)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CSaveRestoreFileSystemPassthrough::Tell(CSaveRestoreFileSystemPassthrough *this, void *hFile)
{
  return g_pFileSystem->Tell(this: &g_pFileSystem->IBaseFileSystem, a2: hFile);
}

//------------------------------------------------------------------------------
// Address: 0x101D22D0
// Name: public: virtual unsigned int CSaveRestoreFileSystemPassthrough::Size(void __near *)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CSaveRestoreFileSystemPassthrough::Size(CSaveRestoreFileSystemPassthrough *this, void *hFile)
{
  return g_pFileSystem->Size_2(this: &g_pFileSystem->IBaseFileSystem, a2: hFile);
}

//------------------------------------------------------------------------------
// Address: 0x101D22F0
// Name: public: virtual unsigned int CSaveRestoreFileSystemPassthrough::Size(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CSaveRestoreFileSystemPassthrough::Size(
        CSaveRestoreFileSystemPassthrough *this,
        const char *pFileName,
        const char *pPathID)
{
  return g_pFileSystem->Size(this: &g_pFileSystem->IBaseFileSystem, a2: pFileName, a3: pPathID);
}

//------------------------------------------------------------------------------
// Address: 0x101D2310
// Name: public: virtual enum FSAsyncStatus_t CSaveRestoreFileSystemPassthrough::AsyncFinish(struct FSAsyncControl_t__ __near *,bool)
// Source: json
//------------------------------------------------------------------------------
FSAsyncStatus_t __thiscall CSaveRestoreFileSystemPassthrough::AsyncFinish(
        CSaveRestoreFileSystemPassthrough *this,
        FSAsyncControl_t__ *hControl,
        BOOL wait)
{
  return g_pFileSystem->AsyncFinish(this: g_pFileSystem, a2: hControl, a3: wait);
}

//------------------------------------------------------------------------------
// Address: 0x101D2330
// Name: public: virtual void CSaveRestoreFileSystemPassthrough::AsyncRelease(struct FSAsyncControl_t__ __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSaveRestoreFileSystemPassthrough::AsyncRelease(
        CSaveRestoreFileSystemPassthrough *this,
        FSAsyncControl_t__ *hControl)
{
  g_pFileSystem->AsyncRelease(this: g_pFileSystem, a2: hControl);
}

//------------------------------------------------------------------------------
// Address: 0x101D2350
// Name: public: virtual enum FSAsyncStatus_t CSaveRestoreFileSystemPassthrough::AsyncAppend(char const __near *,void const __near *,int,bool,struct FSAsyncControl_t__ __near * __near *)
// Source: json
//------------------------------------------------------------------------------
FSAsyncStatus_t __thiscall CSaveRestoreFileSystemPassthrough::AsyncAppend(
        CSaveRestoreFileSystemPassthrough *this,
        const char *pFileName,
        const void *pSrc,
        int nSrcBytes,
        BOOL bFreeMemory,
        FSAsyncControl_t__ **pControl)
{
  return g_pFileSystem->AsyncAppend(
           this: g_pFileSystem,
           a2: pFileName,
           a3: pSrc,
           a4: nSrcBytes,
           a5: bFreeMemory,
           a6: pControl);
}

//------------------------------------------------------------------------------
// Address: 0x101D2370
// Name: public: virtual enum FSAsyncStatus_t CSaveRestoreFileSystemPassthrough::AsyncAppendFile(char const __near *,char const __near *,struct FSAsyncControl_t__ __near * __near *)
// Source: json
//------------------------------------------------------------------------------
FSAsyncStatus_t __thiscall CSaveRestoreFileSystemPassthrough::AsyncAppendFile(
        CSaveRestoreFileSystemPassthrough *this,
        const char *pDestFileName,
        const char *pSrcFileName,
        FSAsyncControl_t__ **pControl)
{
  return g_pFileSystem->AsyncAppendFile(this: g_pFileSystem, a2: pDestFileName, a3: pSrcFileName, a4: pControl);
}

//------------------------------------------------------------------------------
// Address: 0x101D2390
// Name: public: virtual int CSaveRestoreFileSystemPassthrough::DirectoryCount(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CSaveRestoreFileSystemPassthrough::DirectoryCount(
        CSaveRestoreFileSystemPassthrough *this,
        const char *pPath)
{
  int v2; // esi

  v2 = 0;
  if ( Sys_FindFirstEx(pWildcard: pPath, pPathID: "DEFAULT_WRITE_PATH", basename: nullptr, namelength: 0) != nullptr )
  {
    do
      ++v2;
    while ( Sys_FindNext(basename: nullptr, namelength: 0) != nullptr );
  }
  Sys_FindClose();
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x101D23D0
// Name: public: virtual void CSaveRestoreFileSystemPassthrough::DirectoryClear(char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSaveRestoreFileSystemPassthrough::DirectoryClear(
        CSaveRestoreFileSystemPassthrough *this,
        const char *pPath,
        bool bIsXSave)
{
  const char *i; // eax
  const char *v4; // eax
  int v5; // eax
  int v6; // [esp-Ch] [ebp-110h]
  const char *v7; // [esp-4h] [ebp-108h]
  const char *v8; // [esp-4h] [ebp-108h]
  char szPath[260]; // [esp+0h] [ebp-104h] BYREF

  for ( i = Sys_FindFirstEx(pWildcard: pPath, pPathID: "DEFAULT_WRITE_PATH", basename: nullptr, namelength: 0);
        i != nullptr;
        i = Sys_FindNext(basename: nullptr, namelength: 0) )
  {
    v7 = i;
    if ( bIsXSave )
    {
      szPath[0] = 0;
      v6 = 260 - _V_strlen(str: szPath);
      v5 = _V_strlen(str: szPath);
      V_snprintf(pDest: &szPath[v5], maxLen: v6, pFormat: "//mod/%s", v7);
    }
    else
    {
      v4 = (const char *)((int (__thiscall *)(ISaveRestore *, const char *))saverestore->GetSaveDir)(
                           a1: saverestore,
                           a2: i);
      V_snprintf(pDest: szPath, maxLen: 260, pFormat: "%s%s", v4, v8);
    }
    g_pFileSystem->RemoveFile(this: g_pFileSystem, a2: szPath, a3: "MOD");
  }
  Sys_FindClose();
}

//------------------------------------------------------------------------------
// Address: 0x101D24A0
// Name: public: virtual void CSaveRestoreFileSystemPassthrough::AuditFiles(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSaveRestoreFileSystemPassthrough::AuditFiles(CSaveRestoreFileSystemPassthrough *this)
{
  _Msg(a1: "Not using save-in-memory path!\n");
}

//------------------------------------------------------------------------------
// Address: 0x101D24B0
// Name: public: virtual bool CSaveRestoreFileSystemPassthrough::LoadFileFromDisk(char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CSaveRestoreFileSystemPassthrough::LoadFileFromDisk(
        CSaveRestoreFileSystemPassthrough *this,
        const char *pFilename)
{
  _Msg(a1: "Not using save-in-memory path!\n");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101D24D0
// Name: private: static bool CSaveRestoreFileSystemPassthrough::FileCopy(void __near *,void __near *,int)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl CSaveRestoreFileSystemPassthrough::FileCopy(void *pOutput, void *pInput, int fileSize)
{
  int v3; // edi
  void *v4; // ebx
  int v5; // esi
  int v6; // eax
  bool success; // [esp+Bh] [ebp-1h]

  v3 = fileSize;
  v4 = _g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 0x100000);
  success = true;
  if ( fileSize > 0 )
  {
    while ( 1 )
    {
      v5 = 0x100000;
      if ( v3 <= 0x100000 )
        v5 = v3;
      v6 = g_pSaveRestoreFileSystem->Read(this: g_pSaveRestoreFileSystem, a2: v4, a3: v5, a4: pInput);
      if ( v6 < v5 )
        break;
      g_pSaveRestoreFileSystem->Write(this: g_pSaveRestoreFileSystem, a2: v4, a3: v6, a4: pOutput);
      v3 -= v5;
      if ( v3 <= 0 )
        goto LABEL_8;
    }
    _Warning(a1: "Unexpected end of file expanding save game\n");
    success = false;
  }
LABEL_8:
  _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v4);
  return success;
}

//------------------------------------------------------------------------------
// Address: 0x101D2570
// Name: public: CSaveRestoreFileSystemPassthrough::CSaveRestoreFileSystemPassthrough(void)
// Source: json
//------------------------------------------------------------------------------
CSaveRestoreFileSystemPassthrough *__thiscall CSaveRestoreFileSystemPassthrough::CSaveRestoreFileSystemPassthrough(
        CSaveRestoreFileSystemPassthrough *this)
{
  this->__vftable = (CSaveRestoreFileSystemPassthrough_vtbl *)&CSaveRestoreFileSystemPassthrough::`vftable';
  this->m_iContainerOpens = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x101D2580
// Name: public: virtual enum FSAsyncStatus_t CSaveRestoreFileSystemPassthrough::AsyncWrite(char const __near *,void const __near *,int,bool,bool,struct FSAsyncControl_t__ __near * __near *)
// Source: json
//------------------------------------------------------------------------------
FSAsyncStatus_t __thiscall CSaveRestoreFileSystemPassthrough::AsyncWrite(
        CSaveRestoreFileSystemPassthrough *this,
        const char *pFileName,
        const void *pSrc,
        int nSrcBytes,
        BOOL bFreeMemory,
        BOOL bAppend,
        FSAsyncControl_t__ **pControl)
{
  if ( save_spew.m_pParent != nullptr && save_spew.m_pParent->m_Value.m_nValue != 0 )
    _Msg(a1: "AsyncWrite (%s/%d)...\n", pFileName, nSrcBytes);
  return g_pFileSystem->AsyncWrite(
           this: g_pFileSystem,
           a2: pFileName,
           a3: pSrc,
           a4: nSrcBytes,
           a5: bFreeMemory,
           a6: bAppend,
           a7: pControl);
}

//------------------------------------------------------------------------------
// Address: 0x101D25E0
// Name: public: virtual bool CSaveRestoreFileSystemPassthrough::DirectoryExtract(void __near *,int,bool)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CSaveRestoreFileSystemPassthrough::DirectoryExtract(
        CSaveRestoreFileSystemPassthrough *this,
        int pFile,
        int fileCount,
        bool bIsXSave)
{
  bool v4; // bl
  void *v5; // edi
  const char *v6; // eax
  int v7; // eax
  void *v8; // esi
  int v10; // [esp-Ch] [ebp-224h]
  const char *v11; // [esp-4h] [ebp-21Ch]
  char fileName[260]; // [esp+Ch] [ebp-20Ch] BYREF
  char szName[260]; // [esp+110h] [ebp-108h] BYREF
  int i; // [esp+214h] [ebp-4h]

  v4 = true;
  i = 0;
  if ( fileCount > 0 )
  {
    v5 = (void *)pFile;
    while ( v4 )
    {
      if ( g_pSaveRestoreFileSystem->Read(this: g_pSaveRestoreFileSystem, a2: fileName, a3: 260, a4: v5) != 260
        || g_pSaveRestoreFileSystem->Read(this: g_pSaveRestoreFileSystem, a2: &pFile, a3: 4, a4: v5) != 4
        || pFile == 0 )
      {
        return false;
      }
      if ( bIsXSave )
      {
        szName[0] = 0;
        v10 = 260 - _V_strlen(str: szName);
        v7 = _V_strlen(str: szName);
        V_snprintf(pDest: &szName[v7], maxLen: v10, pFormat: "//mod/%s", fileName);
      }
      else
      {
        v6 = (const char *)((int (__thiscall *)(ISaveRestore *, char *))saverestore->GetSaveDir)(
                             a1: saverestore,
                             a2: fileName);
        V_snprintf(pDest: szName, maxLen: 260, pFormat: "%s%s", v6, v11);
      }
      V_FixSlashes(pname: szName, separator: 92);
      v8 = (void *)g_pSaveRestoreFileSystem->Open(this: g_pSaveRestoreFileSystem, a2: szName, a3: "wb", a4: "MOD");
      if ( v8 == nullptr )
        return false;
      v4 = CSaveRestoreFileSystemPassthrough::FileCopy(pOutput: v8, pInput: v5, fileSize: pFile);
      g_pSaveRestoreFileSystem->Close(this: g_pSaveRestoreFileSystem, a2: v8);
      if ( ++i >= fileCount )
        return v4;
    }
  }
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x101D2750
// Name: public: void CUtlMemory<struct CSaveRestoreFileSystemPassthrough::filelistelem_t,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<CSaveRestoreFileSystemPassthrough::filelistelem_t,int>::Grow(
        CUtlMemory<CSaveRestoreFileSystemPassthrough::filelistelem_t,int> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  CSaveRestoreFileSystemPassthrough::filelistelem_t *m_pMemory; // edx
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
        m_nAllocationCount = 1;
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
    v7 = 260 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (CSaveRestoreFileSystemPassthrough::filelistelem_t *)_g_pMemAlloc->Realloc_2(
                                                                               this: _g_pMemAlloc,
                                                                               a2: m_pMemory,
                                                                               a3: v7);
    else
      this->m_pMemory = (CSaveRestoreFileSystemPassthrough::filelistelem_t *)_g_pMemAlloc->Alloc_2(
                                                                               this: _g_pMemAlloc,
                                                                               a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101D27F0
// Name: public: virtual void CSaveRestoreFileSystemPassthrough::DirectoryCopy(char const __near *,char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CSaveRestoreFileSystemPassthrough::DirectoryCopy(
        CSaveRestoreFileSystemPassthrough *this@<ecx>,
        int a2@<ebx>,
        int a3@<edi>,
        const char *pPath,
        const char *pDestFileName,
        bool bIsXSave)
{
  ConVar *m_pParent; // eax
  CSaveRestoreFileSystemPassthrough::filelistelem_t *v7; // esi
  int m_Size; // edi
  const char *First; // ebx
  int v10; // esi
  CSaveRestoreFileSystemPassthrough::filelistelem_t *m_pMemory; // ecx
  unsigned __int8 *v12; // esi
  const char *v14; // eax
  int v15; // eax
  CSaveRestoreFileSystemPassthrough::filelistelem_t *v16; // eax
  int *v17; // eax
  bool v18; // zf
  int v19; // [esp-14h] [ebp-238h]
  const char *v20; // [esp-Ch] [ebp-230h]
  char basefindfn[260]; // [esp+4h] [ebp-220h] BYREF
  char szName[260]; // [esp+108h] [ebp-11Ch] BYREF
  int v25; // [esp+20Ch] [ebp-18h]
  CUtlVector<CSaveRestoreFileSystemPassthrough::filelistelem_t,CUtlMemory<CSaveRestoreFileSystemPassthrough::filelistelem_t,int> > list; // [esp+210h] [ebp-14h] BYREF
  const char *pPatha; // [esp+22Ch] [ebp+8h]
  int fileSize; // [esp+230h] [ebp+Ch]

  m_pParent = save_spew.m_pParent;
  v7 = nullptr;
  if ( save_spew.m_pParent != nullptr && save_spew.m_pParent->m_Value.m_nValue != 0 )
  {
    _Msg(a1: "DirectoryCopy....\n");
    m_pParent = save_spew.m_pParent;
  }
  m_Size = 0;
  memset(&list, 0, sizeof(list));
  if ( m_pParent != nullptr && m_pParent->m_Value.m_nValue != 0 )
    _Msg(a1: "DirectoryCopy: AsyncFinishAllWrites\n");
  g_pFileSystem->AsyncFinishAllWrites(this: g_pFileSystem);
  First = Sys_FindFirstEx(pWildcard: pPath, pPathID: "DEFAULT_WRITE_PATH", basename: basefindfn, namelength: 260);
  if ( First != nullptr )
  {
    do
    {
      v10 = m_Size;
      if ( m_Size + 1 > list.m_Memory.m_nAllocationCount )
      {
        CUtlMemory<CSaveRestoreFileSystemPassthrough::filelistelem_t,int>::Grow(
          this: &list.m_Memory,
          num: m_Size - list.m_Memory.m_nAllocationCount + 1);
        m_Size = list.m_Size;
      }
      m_pMemory = list.m_Memory.m_pMemory;
      list.m_Size = ++m_Size;
      list.m_pElements = list.m_Memory.m_pMemory;
      if ( m_Size - v10 - 1 > 0 )
      {
        _V_memmove(
          dest: &list.m_Memory.m_pMemory[v10 + 1],
          src: &list.m_Memory.m_pMemory[v10],
          count: 260 * (m_Size - v10 - 1));
        m_pMemory = list.m_Memory.m_pMemory;
      }
      v12 = (unsigned __int8 *)&m_pMemory[v10];
      memset(dst: v12, value: 0, count: 0x104u);
      V_strncpy(pDest: (char *)v12, pSrc: First, maxLen: 260);
      First = Sys_FindNext(basename: basefindfn, namelength: 260);
    }
    while ( First != nullptr );
    v7 = list.m_Memory.m_pMemory;
  }
  Sys_FindClose();
  if ( m_Size > 0 )
  {
    pPatha = (const char *)v7;
    v25 = m_Size;
    do
    {
      if ( bIsXSave )
      {
        szName[0] = 0;
        v19 = 260 - _V_strlen(str: szName);
        v15 = _V_strlen(str: szName);
        V_snprintf(pDest: &szName[v15], maxLen: v19, pFormat: "//mod/%s", v7->szFileName);
      }
      else
      {
        v14 = (const char *)((int (__thiscall *)(ISaveRestore *, CSaveRestoreFileSystemPassthrough::filelistelem_t *))saverestore->GetSaveDir)(
                              a1: saverestore,
                              a2: v7);
        V_snprintf(pDest: szName, maxLen: 260, pFormat: "%s%s", v14, v20);
      }
      V_FixSlashes(pname: szName, separator: 92);
      fileSize = g_pFileSystem->Size(this: &g_pFileSystem->IBaseFileSystem, a2: szName, a3: nullptr);
      if ( fileSize != 0 )
      {
        if ( save_spew.m_pParent != nullptr && save_spew.m_pParent->m_Value.m_nValue != 0 )
          _Msg(a1: "DirectoryCopy: AsyncAppend %s, %s\n", szName, pDestFileName);
        v16 = (CSaveRestoreFileSystemPassthrough::filelistelem_t *)MemAlloc_Alloc(nSize: 0x104u);
        qmemcpy(v16, v7, sizeof(CSaveRestoreFileSystemPassthrough::filelistelem_t));
        ((void (__thiscall *)(IFileSystem *, const char *, CSaveRestoreFileSystemPassthrough::filelistelem_t *, int, int, _DWORD, int, int))g_pFileSystem->AsyncAppend)(
          a1: g_pFileSystem,
          a2: pDestFileName,
          a3: v16,
          a4: 260,
          a5: 1,
          a6: 0,
          a7: a3,
          a8: a2);
        v17 = (int *)MemAlloc_Alloc(nSize: 4u);
        if ( v17 != nullptr )
          *v17 = fileSize;
        else
          v17 = nullptr;
        a2 = 0;
        a3 = 1;
        ((void (__thiscall *)(IFileSystem *, const char *, int *, int))g_pFileSystem->AsyncAppend)(
          a1: g_pFileSystem,
          a2: pDestFileName,
          a3: v17,
          a4: 4);
        g_pFileSystem->AsyncAppendFile(this: g_pFileSystem, a2: pDestFileName, a3: szName, a4: nullptr);
        v7 = (CSaveRestoreFileSystemPassthrough::filelistelem_t *)pPatha;
      }
      ++v7;
      v18 = v25-- == 1;
      pPatha = (const char *)v7;
    }
    while ( !v18 );
    v7 = list.m_Memory.m_pMemory;
  }
  if ( list.m_Memory.m_nGrowSize >= 0 && v7 != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v7);
}

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x101D25B0
// Name: public: virtual bool CSaveRestoreFileSystemPassthrough::FileExists(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CSaveRestoreFileSystemPassthrough::FileExists(
        CSaveRestoreFileSystemPassthrough *this,
        const char *pFileName,
        const char *pPathID)
{
  return g_pFileSystem->FileExists(this: &g_pFileSystem->IBaseFileSystem, a2: pFileName, a3: pPathID);
}

//------------------------------------------------------------------------------
// Address: 0x101D25D0
// Name: public: virtual void CSaveRestoreFileSystemPassthrough::RemoveFile(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSaveRestoreFileSystemPassthrough::RemoveFile(
        CSaveRestoreFileSystemPassthrough *this,
        const char *pRelativePath,
        const char *pathID)
{
  g_pFileSystem->RemoveFile(this: g_pFileSystem, a2: pRelativePath, a3: pathID);
}

//------------------------------------------------------------------------------
// Address: 0x101D25F0
// Name: public: virtual void CSaveRestoreFileSystemPassthrough::RenameFile(char const __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSaveRestoreFileSystemPassthrough::RenameFile(
        CSaveRestoreFileSystemPassthrough *this,
        const char *pOldPath,
        const char *pNewPath,
        const char *pathID)
{
  g_pFileSystem->RenameFile(this: g_pFileSystem, a2: pOldPath, a3: pNewPath, a4: pathID);
}

//------------------------------------------------------------------------------
// Address: 0x101D2610
// Name: public: virtual void CSaveRestoreFileSystemPassthrough::AsyncFinishAllWrites(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSaveRestoreFileSystemPassthrough::AsyncFinishAllWrites(CSaveRestoreFileSystemPassthrough *this)
{
  g_pFileSystem->AsyncFinishAllWrites(this: g_pFileSystem);
}

//------------------------------------------------------------------------------
// Address: 0x101D2620
// Name: public: virtual void __near * CSaveRestoreFileSystemPassthrough::Open(char const __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void *__thiscall CSaveRestoreFileSystemPassthrough::Open(
        CSaveRestoreFileSystemPassthrough *this,
        const char *pFullName,
        const char *pOptions,
        const char *pathID)
{
  return g_pFileSystem->OpenEx(this: g_pFileSystem, a2: pFullName, a3: pOptions, a4: 4u, a5: pathID, a6: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x101D2650
// Name: public: virtual void CSaveRestoreFileSystemPassthrough::Close(void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSaveRestoreFileSystemPassthrough::Close(CSaveRestoreFileSystemPassthrough *this, void *hSaveFile)
{
  g_pFileSystem->Close(this: &g_pFileSystem->IBaseFileSystem, a2: hSaveFile);
}

//------------------------------------------------------------------------------
// Address: 0x101D2670
// Name: public: virtual int CSaveRestoreFileSystemPassthrough::Read(void __near *,int,void __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CSaveRestoreFileSystemPassthrough::Read(
        CSaveRestoreFileSystemPassthrough *this,
        void *pOutput,
        int size,
        void *hFile)
{
  return g_pFileSystem->Read(this: &g_pFileSystem->IBaseFileSystem, a2: pOutput, a3: size, a4: hFile);
}

//------------------------------------------------------------------------------
// Address: 0x101D2690
// Name: public: virtual int CSaveRestoreFileSystemPassthrough::Write(void const __near *,int,void __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CSaveRestoreFileSystemPassthrough::Write(
        CSaveRestoreFileSystemPassthrough *this,
        const void *pInput,
        int size,
        void *hFile)
{
  return g_pFileSystem->Write(this: &g_pFileSystem->IBaseFileSystem, a2: pInput, a3: size, a4: hFile);
}

//------------------------------------------------------------------------------
// Address: 0x101D26B0
// Name: public: virtual void CSaveRestoreFileSystemPassthrough::Seek(void __near *,int,enum FileSystemSeek_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSaveRestoreFileSystemPassthrough::Seek(
        CSaveRestoreFileSystemPassthrough *this,
        void *hFile,
        int pos,
        FileSystemSeek_t method)
{
  g_pFileSystem->Seek(this: &g_pFileSystem->IBaseFileSystem, a2: hFile, a3: pos, a4: method);
}

//------------------------------------------------------------------------------
// Address: 0x101D26D0
// Name: public: virtual unsigned int CSaveRestoreFileSystemPassthrough::Tell(void __near *)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CSaveRestoreFileSystemPassthrough::Tell(CSaveRestoreFileSystemPassthrough *this, void *hFile)
{
  return g_pFileSystem->Tell(this: &g_pFileSystem->IBaseFileSystem, a2: hFile);
}

//------------------------------------------------------------------------------
// Address: 0x101D26F0
// Name: public: virtual unsigned int CSaveRestoreFileSystemPassthrough::Size(void __near *)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CSaveRestoreFileSystemPassthrough::Size(CSaveRestoreFileSystemPassthrough *this, void *hFile)
{
  return g_pFileSystem->Size_2(this: &g_pFileSystem->IBaseFileSystem, a2: hFile);
}

//------------------------------------------------------------------------------
// Address: 0x101D2710
// Name: public: virtual unsigned int CSaveRestoreFileSystemPassthrough::Size(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CSaveRestoreFileSystemPassthrough::Size(
        CSaveRestoreFileSystemPassthrough *this,
        const char *pFileName,
        const char *pPathID)
{
  return g_pFileSystem->Size(this: &g_pFileSystem->IBaseFileSystem, a2: pFileName, a3: pPathID);
}

//------------------------------------------------------------------------------
// Address: 0x101D2730
// Name: public: virtual enum FSAsyncStatus_t CSaveRestoreFileSystemPassthrough::AsyncFinish(struct FSAsyncControl_t__ __near *,bool)
// Source: json
//------------------------------------------------------------------------------
FSAsyncStatus_t __thiscall CSaveRestoreFileSystemPassthrough::AsyncFinish(
        CSaveRestoreFileSystemPassthrough *this,
        FSAsyncControl_t__ *hControl,
        BOOL wait)
{
  return g_pFileSystem->AsyncFinish(this: g_pFileSystem, a2: hControl, a3: wait);
}

//------------------------------------------------------------------------------
// Address: 0x101D2770
// Name: public: virtual enum FSAsyncStatus_t CSaveRestoreFileSystemPassthrough::AsyncAppend(char const __near *,void const __near *,int,bool,struct FSAsyncControl_t__ __near * __near *)
// Source: json
//------------------------------------------------------------------------------
FSAsyncStatus_t __thiscall CSaveRestoreFileSystemPassthrough::AsyncAppend(
        CSaveRestoreFileSystemPassthrough *this,
        const char *pFileName,
        const void *pSrc,
        int nSrcBytes,
        BOOL bFreeMemory,
        FSAsyncControl_t__ **pControl)
{
  return g_pFileSystem->AsyncAppend(
           this: g_pFileSystem,
           a2: pFileName,
           a3: pSrc,
           a4: nSrcBytes,
           a5: bFreeMemory,
           a6: pControl);
}

//------------------------------------------------------------------------------
// Address: 0x101D2790
// Name: public: virtual enum FSAsyncStatus_t CSaveRestoreFileSystemPassthrough::AsyncAppendFile(char const __near *,char const __near *,struct FSAsyncControl_t__ __near * __near *)
// Source: json
//------------------------------------------------------------------------------
FSAsyncStatus_t __thiscall CSaveRestoreFileSystemPassthrough::AsyncAppendFile(
        CSaveRestoreFileSystemPassthrough *this,
        const char *pDestFileName,
        const char *pSrcFileName,
        FSAsyncControl_t__ **pControl)
{
  return g_pFileSystem->AsyncAppendFile(this: g_pFileSystem, a2: pDestFileName, a3: pSrcFileName, a4: pControl);
}

//------------------------------------------------------------------------------
// Address: 0x101D27B0
// Name: public: virtual int CSaveRestoreFileSystemPassthrough::DirectoryCount(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CSaveRestoreFileSystemPassthrough::DirectoryCount(
        CSaveRestoreFileSystemPassthrough *this,
        const char *pPath)
{
  int v2; // esi

  v2 = 0;
  if ( Sys_FindFirstEx(pWildcard: pPath, pPathID: "DEFAULT_WRITE_PATH", basename: nullptr, namelength: 0) != nullptr )
  {
    do
      ++v2;
    while ( Sys_FindNext(basename: nullptr, namelength: 0) != nullptr );
  }
  Sys_FindClose();
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x101D28C0
// Name: public: virtual void CSaveRestoreFileSystemPassthrough::AuditFiles(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSaveRestoreFileSystemPassthrough::AuditFiles(CSaveRestoreFileSystemPassthrough *this)
{
  _Msg(a1: "Not using save-in-memory path!\n");
}

//------------------------------------------------------------------------------
// Address: 0x101D28D0
// Name: public: virtual bool CSaveRestoreFileSystemPassthrough::LoadFileFromDisk(char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CSaveRestoreFileSystemPassthrough::LoadFileFromDisk(
        CSaveRestoreFileSystemPassthrough *this,
        const char *pFilename)
{
  _Msg(a1: "Not using save-in-memory path!\n");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101D28F0
// Name: private: static bool CSaveRestoreFileSystemPassthrough::FileCopy(void __near *,void __near *,int)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl CSaveRestoreFileSystemPassthrough::FileCopy(void *pOutput, void *pInput, int fileSize)
{
  int v3; // edi
  void *v4; // ebx
  int v5; // esi
  int v6; // eax
  bool success; // [esp+Bh] [ebp-1h]

  v3 = fileSize;
  v4 = _g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 0x100000);
  success = true;
  if ( fileSize > 0 )
  {
    while ( 1 )
    {
      v5 = 0x100000;
      if ( v3 <= 0x100000 )
        v5 = v3;
      v6 = g_pSaveRestoreFileSystem->Read(this: g_pSaveRestoreFileSystem, a2: v4, a3: v5, a4: pInput);
      if ( v6 < v5 )
        break;
      g_pSaveRestoreFileSystem->Write(this: g_pSaveRestoreFileSystem, a2: v4, a3: v6, a4: pOutput);
      v3 -= v5;
      if ( v3 <= 0 )
        goto LABEL_8;
    }
    _Warning(a1: "Unexpected end of file expanding save game\n");
    success = false;
  }
LABEL_8:
  _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v4);
  return success;
}

//------------------------------------------------------------------------------
// Address: 0x101D2990
// Name: public: CSaveRestoreFileSystemPassthrough::CSaveRestoreFileSystemPassthrough(void)
// Source: json
//------------------------------------------------------------------------------
CSaveRestoreFileSystemPassthrough *__thiscall CSaveRestoreFileSystemPassthrough::CSaveRestoreFileSystemPassthrough(
        CSaveRestoreFileSystemPassthrough *this)
{
  this->__vftable = (CSaveRestoreFileSystemPassthrough_vtbl *)&CSaveRestoreFileSystemPassthrough::`vftable';
  this->m_iContainerOpens = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x101D29A0
// Name: public: virtual enum FSAsyncStatus_t CSaveRestoreFileSystemPassthrough::AsyncWrite(char const __near *,void const __near *,int,bool,bool,struct FSAsyncControl_t__ __near * __near *)
// Source: json
//------------------------------------------------------------------------------
FSAsyncStatus_t __thiscall CSaveRestoreFileSystemPassthrough::AsyncWrite(
        CSaveRestoreFileSystemPassthrough *this,
        const char *pFileName,
        const void *pSrc,
        int nSrcBytes,
        BOOL bFreeMemory,
        BOOL bAppend,
        FSAsyncControl_t__ **pControl)
{
  if ( save_spew.m_pParent != nullptr && save_spew.m_pParent->m_Value.m_nValue != 0 )
    _Msg(a1: "AsyncWrite (%s/%d)...\n", pFileName, nSrcBytes);
  return g_pFileSystem->AsyncWrite(
           this: g_pFileSystem,
           a2: pFileName,
           a3: pSrc,
           a4: nSrcBytes,
           a5: bFreeMemory,
           a6: bAppend,
           a7: pControl);
}

//------------------------------------------------------------------------------
// Address: 0x101D2A00
// Name: public: virtual bool CSaveRestoreFileSystemPassthrough::DirectoryExtract(void __near *,int,bool)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CSaveRestoreFileSystemPassthrough::DirectoryExtract(
        CSaveRestoreFileSystemPassthrough *this,
        int pFile,
        int fileCount,
        bool bIsXSave)
{
  bool v4; // bl
  void *v5; // edi
  const char *v6; // eax
  int v7; // eax
  void *v8; // esi
  int v10; // [esp-Ch] [ebp-224h]
  const char *v11; // [esp-4h] [ebp-21Ch]
  char fileName[260]; // [esp+Ch] [ebp-20Ch] BYREF
  char szName[260]; // [esp+110h] [ebp-108h] BYREF
  int i; // [esp+214h] [ebp-4h]

  v4 = true;
  i = 0;
  if ( fileCount > 0 )
  {
    v5 = (void *)pFile;
    while ( v4 )
    {
      if ( g_pSaveRestoreFileSystem->Read(this: g_pSaveRestoreFileSystem, a2: fileName, a3: 260, a4: v5) != 260
        || g_pSaveRestoreFileSystem->Read(this: g_pSaveRestoreFileSystem, a2: &pFile, a3: 4, a4: v5) != 4
        || pFile == 0 )
      {
        return false;
      }
      if ( bIsXSave )
      {
        szName[0] = 0;
        v10 = 260 - _V_strlen(str: szName);
        v7 = _V_strlen(str: szName);
        V_snprintf(pDest: &szName[v7], maxLen: v10, pFormat: "//mod/%s", fileName);
      }
      else
      {
        v6 = (const char *)((int (__thiscall *)(ISaveRestore *, char *))saverestore->GetSaveDir)(
                             a1: saverestore,
                             a2: fileName);
        V_snprintf(pDest: szName, maxLen: 260, pFormat: "%s%s", v6, v11);
      }
      V_FixSlashes(pname: szName, separator: 92);
      v8 = (void *)g_pSaveRestoreFileSystem->Open(this: g_pSaveRestoreFileSystem, a2: szName, a3: "wb", a4: "MOD");
      if ( v8 == nullptr )
        return false;
      v4 = CSaveRestoreFileSystemPassthrough::FileCopy(pOutput: v8, pInput: v5, fileSize: pFile);
      g_pSaveRestoreFileSystem->Close(this: g_pSaveRestoreFileSystem, a2: v8);
      if ( ++i >= fileCount )
        return v4;
    }
  }
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x101D2B70
// Name: public: void CUtlMemory<struct CSaveRestoreFileSystemPassthrough::filelistelem_t,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<CSaveRestoreFileSystemPassthrough::filelistelem_t,int>::Grow(
        CUtlMemory<CSaveRestoreFileSystemPassthrough::filelistelem_t,int> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  CSaveRestoreFileSystemPassthrough::filelistelem_t *m_pMemory; // edx
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
        m_nAllocationCount = 1;
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
    v7 = 260 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (CSaveRestoreFileSystemPassthrough::filelistelem_t *)_g_pMemAlloc->Realloc_2(
                                                                               this: _g_pMemAlloc,
                                                                               a2: m_pMemory,
                                                                               a3: v7);
    else
      this->m_pMemory = (CSaveRestoreFileSystemPassthrough::filelistelem_t *)_g_pMemAlloc->Alloc_2(
                                                                               this: _g_pMemAlloc,
                                                                               a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101D2C10
// Name: public: virtual void CSaveRestoreFileSystemPassthrough::DirectoryCopy(char const __near *,char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CSaveRestoreFileSystemPassthrough::DirectoryCopy(
        CSaveRestoreFileSystemPassthrough *this@<ecx>,
        int a2@<ebx>,
        int a3@<edi>,
        const char *pPath,
        const char *pDestFileName,
        bool bIsXSave)
{
  ConVar *m_pParent; // eax
  CSaveRestoreFileSystemPassthrough::filelistelem_t *v7; // esi
  int m_Size; // edi
  const char *First; // ebx
  int v10; // esi
  CSaveRestoreFileSystemPassthrough::filelistelem_t *m_pMemory; // ecx
  unsigned __int8 *v12; // esi
  const char *v14; // eax
  int v15; // eax
  CSaveRestoreFileSystemPassthrough::filelistelem_t *v16; // eax
  int *v17; // eax
  bool v18; // zf
  int v19; // [esp-14h] [ebp-238h]
  const char *v20; // [esp-Ch] [ebp-230h]
  char basefindfn[260]; // [esp+4h] [ebp-220h] BYREF
  char szName[260]; // [esp+108h] [ebp-11Ch] BYREF
  int v25; // [esp+20Ch] [ebp-18h]
  CUtlVector<CSaveRestoreFileSystemPassthrough::filelistelem_t,CUtlMemory<CSaveRestoreFileSystemPassthrough::filelistelem_t,int> > list; // [esp+210h] [ebp-14h] BYREF
  const char *pPatha; // [esp+22Ch] [ebp+8h]
  int fileSize; // [esp+230h] [ebp+Ch]

  m_pParent = save_spew.m_pParent;
  v7 = nullptr;
  if ( save_spew.m_pParent != nullptr && save_spew.m_pParent->m_Value.m_nValue != 0 )
  {
    _Msg(a1: "DirectoryCopy....\n");
    m_pParent = save_spew.m_pParent;
  }
  m_Size = 0;
  memset(&list, 0, sizeof(list));
  if ( m_pParent != nullptr && m_pParent->m_Value.m_nValue != 0 )
    _Msg(a1: "DirectoryCopy: AsyncFinishAllWrites\n");
  g_pFileSystem->AsyncFinishAllWrites(this: g_pFileSystem);
  First = Sys_FindFirstEx(pWildcard: pPath, pPathID: "DEFAULT_WRITE_PATH", basename: basefindfn, namelength: 260);
  if ( First != nullptr )
  {
    do
    {
      v10 = m_Size;
      if ( m_Size + 1 > list.m_Memory.m_nAllocationCount )
      {
        CUtlMemory<CSaveRestoreFileSystemPassthrough::filelistelem_t,int>::Grow(
          this: &list.m_Memory,
          num: m_Size - list.m_Memory.m_nAllocationCount + 1);
        m_Size = list.m_Size;
      }
      m_pMemory = list.m_Memory.m_pMemory;
      list.m_Size = ++m_Size;
      list.m_pElements = list.m_Memory.m_pMemory;
      if ( m_Size - v10 - 1 > 0 )
      {
        _V_memmove(
          dest: &list.m_Memory.m_pMemory[v10 + 1],
          src: &list.m_Memory.m_pMemory[v10],
          count: 260 * (m_Size - v10 - 1));
        m_pMemory = list.m_Memory.m_pMemory;
      }
      v12 = (unsigned __int8 *)&m_pMemory[v10];
      memset(dst: v12, value: 0, count: 0x104u);
      V_strncpy(pDest: (char *)v12, pSrc: First, maxLen: 260);
      First = Sys_FindNext(basename: basefindfn, namelength: 260);
    }
    while ( First != nullptr );
    v7 = list.m_Memory.m_pMemory;
  }
  Sys_FindClose();
  if ( m_Size > 0 )
  {
    pPatha = (const char *)v7;
    v25 = m_Size;
    do
    {
      if ( bIsXSave )
      {
        szName[0] = 0;
        v19 = 260 - _V_strlen(str: szName);
        v15 = _V_strlen(str: szName);
        V_snprintf(pDest: &szName[v15], maxLen: v19, pFormat: "//mod/%s", v7->szFileName);
      }
      else
      {
        v14 = (const char *)((int (__thiscall *)(ISaveRestore *, CSaveRestoreFileSystemPassthrough::filelistelem_t *))saverestore->GetSaveDir)(
                              a1: saverestore,
                              a2: v7);
        V_snprintf(pDest: szName, maxLen: 260, pFormat: "%s%s", v14, v20);
      }
      V_FixSlashes(pname: szName, separator: 92);
      fileSize = g_pFileSystem->Size(this: &g_pFileSystem->IBaseFileSystem, a2: szName, a3: nullptr);
      if ( fileSize != 0 )
      {
        if ( save_spew.m_pParent != nullptr && save_spew.m_pParent->m_Value.m_nValue != 0 )
          _Msg(a1: "DirectoryCopy: AsyncAppend %s, %s\n", szName, pDestFileName);
        v16 = (CSaveRestoreFileSystemPassthrough::filelistelem_t *)MemAlloc_Alloc(nSize: 0x104u);
        qmemcpy(v16, v7, sizeof(CSaveRestoreFileSystemPassthrough::filelistelem_t));
        ((void (__thiscall *)(IFileSystem *, const char *, CSaveRestoreFileSystemPassthrough::filelistelem_t *, int, int, _DWORD, int, int))g_pFileSystem->AsyncAppend)(
          a1: g_pFileSystem,
          a2: pDestFileName,
          a3: v16,
          a4: 260,
          a5: 1,
          a6: 0,
          a7: a3,
          a8: a2);
        v17 = (int *)MemAlloc_Alloc(nSize: 4u);
        if ( v17 != nullptr )
          *v17 = fileSize;
        else
          v17 = nullptr;
        a2 = 0;
        a3 = 1;
        ((void (__thiscall *)(IFileSystem *, const char *, int *, int))g_pFileSystem->AsyncAppend)(
          a1: g_pFileSystem,
          a2: pDestFileName,
          a3: v17,
          a4: 4);
        g_pFileSystem->AsyncAppendFile(this: g_pFileSystem, a2: pDestFileName, a3: szName, a4: nullptr);
        v7 = (CSaveRestoreFileSystemPassthrough::filelistelem_t *)pPatha;
      }
      ++v7;
      v18 = v25-- == 1;
      pPatha = (const char *)v7;
    }
    while ( !v18 );
    v7 = list.m_Memory.m_pMemory;
  }
  if ( list.m_Memory.m_nGrowSize >= 0 && v7 != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v7);
}

//------------------------------------------------------------------------------
// Address: 0x1031BAD0
// Name: _dynamic_initializer_for__save_history_count__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__save_history_count__()
{
  ConVar::ConVar(
    this: &save_history_count,
    pName: "save_history_count",
    pDefaultValue: "1",
    flags: 0,
    pHelpString: "Keep this many old copies in history of autosaves and quicksaves.");
  return atexit(func: dynamic_atexit_destructor_for__save_history_count__);
}

//------------------------------------------------------------------------------
// Address: 0x1031BB30
// Name: _dynamic_initializer_for__save_async__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__save_async__()
{
  ConVar::ConVar(this: &save_async, pName: "save_async", pDefaultValue: "1", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__save_async__);
}

//------------------------------------------------------------------------------
// Address: 0x1031BB60
// Name: _dynamic_initializer_for__save_disable__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__save_disable__()
{
  ConVar::ConVar(this: &save_disable, pName: "save_disable", pDefaultValue: "0", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__save_disable__);
}

//------------------------------------------------------------------------------
// Address: 0x1031BBC0
// Name: _dynamic_initializer_for__save_noxsave__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__save_noxsave__()
{
  ConVar::ConVar(this: &save_noxsave, pName: "save_noxsave", pDefaultValue: "0", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__save_noxsave__);
}

//------------------------------------------------------------------------------
// Address: 0x1031BBF0
// Name: _dynamic_initializer_for__save_screenshot__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__save_screenshot__()
{
  ConVar::ConVar(
    this: &save_screenshot,
    pName: "save_screenshot",
    pDefaultValue: "1",
    flags: 0,
    pHelpString: "0 = none, 1 = non-autosave, 2 = always");
  return atexit(func: dynamic_atexit_destructor_for__save_screenshot__);
}

//------------------------------------------------------------------------------
// Address: 0x1031BC20
// Name: _dynamic_initializer_for__save_spew__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__save_spew__()
{
  ConVar::ConVar(this: &save_spew, pName: "save_spew", pDefaultValue: "0", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__save_spew__);
}

//------------------------------------------------------------------------------
// Address: 0x1031BC50
// Name: _dynamic_initializer_for__save_multiplayer_override__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__save_multiplayer_override__()
{
  ConVar::ConVar(this: &save_multiplayer_override, pName: "save_multiplayer_override", pDefaultValue: "0", flags: 18);
  return atexit(func: dynamic_atexit_destructor_for__save_multiplayer_override__);
}

//------------------------------------------------------------------------------
// Address: 0x1031BC80
// Name: _dynamic_initializer_for__save_console__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__save_console__()
{
  ConVar::ConVar(
    this: &save_console,
    pName: "save_console",
    pDefaultValue: "0",
    flags: 0,
    pHelpString: "Autosave on the PC behaves like it does on the consoles.");
  return atexit(func: dynamic_atexit_destructor_for__save_console__);
}

//------------------------------------------------------------------------------
// Address: 0x1031BCB0
// Name: _dynamic_initializer_for__save_huddelayframes__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__save_huddelayframes__()
{
  ConVar::ConVar(
    this: &save_huddelayframes,
    pName: "save_huddelayframes",
    pDefaultValue: "1",
    flags: 0,
    pHelpString: "Number of frames to defer for drawing the Saving message.");
  return atexit(func: dynamic_atexit_destructor_for__save_huddelayframes__);
}

//------------------------------------------------------------------------------
// Address: 0x1031BD80
// Name: _dynamic_initializer_for__save_asyncdelay__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__save_asyncdelay__()
{
  ConVar::ConVar(
    this: &save_asyncdelay,
    pName: "save_asyncdelay",
    pDefaultValue: "0",
    flags: 0,
    pHelpString: "For testing, adds this many milliseconds of delay to the save operation.");
  return atexit(func: dynamic_atexit_destructor_for__save_asyncdelay__);
}

//------------------------------------------------------------------------------
// Address: 0x1031BDE0
// Name: _dynamic_initializer_for__save_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__save_command__()
{
  ConCommand::ConCommand(
    this: &save_command,
    pName: "save",
    callback: xsave,
    pHelpString: "Saves current game.",
    flags: 0x20000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__save_command__);
}

//------------------------------------------------------------------------------
// Address: 0x1031BFC0
// Name: _dynamic_initializer_for__save_finish_async_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__save_finish_async_command__()
{
  ConCommand::ConCommand(
    this: &save_finish_async_command,
    pName: "save_finish_async",
    callback: (void (__cdecl *)(const CCommand *))CSaveRestore::FinishAsyncSave,
    pHelpString: defaultValue,
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__save_finish_async_command__);
}

//------------------------------------------------------------------------------
// Address: 0x1031D610
// Name: _dynamic_initializer_for__save_in_memory__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__save_in_memory__()
{
  ConVar::ConVar(
    this: &save_in_memory,
    pName: "save_in_memory",
    pDefaultValue: "0",
    flags: 0,
    pHelpString: "Set to 1 to save to memory instead of disk (Xbox 360)",
    callback: (void (__cdecl *)(IConVar *, const char *, float))SaveInMemoryCallback);
  return atexit(func: dynamic_atexit_destructor_for__save_in_memory__);
}

//------------------------------------------------------------------------------
// Address: 0x10325D10
// Name: _dynamic_atexit_destructor_for__save_history_count__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__save_history_count__()
{
  ConVar::~ConVar(this: &save_history_count);
}

//------------------------------------------------------------------------------
// Address: 0x10325D30
// Name: _dynamic_atexit_destructor_for__save_async__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__save_async__()
{
  ConVar::~ConVar(this: &save_async);
}

//------------------------------------------------------------------------------
// Address: 0x10325D40
// Name: _dynamic_atexit_destructor_for__save_disable__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__save_disable__()
{
  ConVar::~ConVar(this: &save_disable);
}

//------------------------------------------------------------------------------
// Address: 0x10325D60
// Name: _dynamic_atexit_destructor_for__save_noxsave__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__save_noxsave__()
{
  ConVar::~ConVar(this: &save_noxsave);
}

//------------------------------------------------------------------------------
// Address: 0x10325D70
// Name: _dynamic_atexit_destructor_for__save_screenshot__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__save_screenshot__()
{
  ConVar::~ConVar(this: &save_screenshot);
}

//------------------------------------------------------------------------------
// Address: 0x10325D80
// Name: _dynamic_atexit_destructor_for__save_spew__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__save_spew__()
{
  ConVar::~ConVar(this: &save_spew);
}

//------------------------------------------------------------------------------
// Address: 0x10325D90
// Name: _dynamic_atexit_destructor_for__save_multiplayer_override__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__save_multiplayer_override__()
{
  ConVar::~ConVar(this: &save_multiplayer_override);
}

//------------------------------------------------------------------------------
// Address: 0x10325DA0
// Name: _dynamic_atexit_destructor_for__save_console__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__save_console__()
{
  ConVar::~ConVar(this: &save_console);
}

//------------------------------------------------------------------------------
// Address: 0x10325DB0
// Name: _dynamic_atexit_destructor_for__save_huddelayframes__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__save_huddelayframes__()
{
  ConVar::~ConVar(this: &save_huddelayframes);
}

//------------------------------------------------------------------------------
// Address: 0x10325DC0
// Name: _dynamic_atexit_destructor_for__save_asyncdelay__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__save_asyncdelay__()
{
  ConVar::~ConVar(this: &save_asyncdelay);
}

//------------------------------------------------------------------------------
// Address: 0x10325DD0
// Name: _dynamic_atexit_destructor_for__save_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__save_command__()
{
  ConCommand::~ConCommand(this: &save_command);
}

//------------------------------------------------------------------------------
// Address: 0x10325E70
// Name: _dynamic_atexit_destructor_for__save_finish_async_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__save_finish_async_command__()
{
  ConCommand::~ConCommand(this: &save_finish_async_command);
}

//------------------------------------------------------------------------------
// Address: 0x10326830
// Name: _dynamic_atexit_destructor_for__save_in_memory__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__save_in_memory__()
{
  ConVar::~ConVar(this: &save_in_memory);
}

//------------------------------------------------------------------------------
// Address: 0x1031BB90
// Name: _dynamic_initializer_for__map_wants_save_disable__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__map_wants_save_disable__()
{
  ConVar::ConVar(this: &map_wants_save_disable, pName: "map_wants_save_disable", pDefaultValue: "0", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__map_wants_save_disable__);
}

//------------------------------------------------------------------------------
// Address: 0x1031BCE0
// Name: _dynamic_initializer_for__g_AsyncSaveCallQueue__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_AsyncSaveCallQueue__()
{
  CTSQueue<int,0,1>::CTSQueue<int,0,1>(this: (CTSQueue<int,0,1> *)&g_AsyncSaveCallQueue);
  g_AsyncSaveCallQueue.m_bNoQueue = false;
  return atexit(func: dynamic_atexit_destructor_for__g_AsyncSaveCallQueue__);
}

//------------------------------------------------------------------------------
// Address: 0x1031BD00
// Name: _dynamic_initializer_for__g_bSaveInProgress__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void dynamic_initializer_for__g_bSaveInProgress__()
{
  g_bSaveInProgress.m_value = 0;
}

//------------------------------------------------------------------------------
// Address: 0x1031BD10
// Name: _dynamic_initializer_for__g_bAutoSaveDangerousInProgress__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void dynamic_initializer_for__g_bAutoSaveDangerousInProgress__()
{
  g_bAutoSaveDangerousInProgress.m_value = 0;
}

//------------------------------------------------------------------------------
// Address: 0x1031BD20
// Name: _dynamic_initializer_for__g_SaveRestore__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_SaveRestore__()
{
  CSaveRestore::CSaveRestore(this: &g_SaveRestore);
  return atexit(func: dynamic_atexit_destructor_for__g_SaveRestore__);
}

//------------------------------------------------------------------------------
// Address: 0x1031BE10
// Name: _dynamic_initializer_for__xsave_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__xsave_command__()
{
  ConCommand::ConCommand(
    this: &xsave_command,
    pName: "xsave",
    callback: xsave,
    pHelpString: "Saves current game to a console storage device.",
    flags: 0x20000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__xsave_command__);
}

//------------------------------------------------------------------------------
// Address: 0x1031BE40
// Name: _dynamic_initializer_for__minisave_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__minisave_command__()
{
  ConCommand::ConCommand(
    this: &minisave_command,
    pName: "minisave",
    callback: minisave,
    pHelpString: "Saves game (for current level only!)",
    flags: 0x20000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__minisave_command__);
}

//------------------------------------------------------------------------------
// Address: 0x1031BE70
// Name: _dynamic_initializer_for___autosave_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for___autosave_command__()
{
  ConCommand::ConCommand(
    this: &autosave_command,
    pName: "_autosave",
    callback: autosave,
    pHelpString: "Autosave",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for___autosave_command__);
}

//------------------------------------------------------------------------------
// Address: 0x1031BEA0
// Name: _dynamic_initializer_for___autosavedangerous_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for___autosavedangerous_command__()
{
  ConCommand::ConCommand(
    this: &autosavedangerous_command,
    pName: "_autosavedangerous",
    callback: autosavedangerous,
    pHelpString: "AutoSaveDangerous",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for___autosavedangerous_command__);
}

//------------------------------------------------------------------------------
// Address: 0x1031BED0
// Name: _dynamic_initializer_for__autosave_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__autosave_command__()
{
  ConCommand::ConCommand(
    this: &autosave_command,
    pName: "autosave",
    callback: autosave,
    pHelpString: "Autosave",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__autosave_command__);
}

//------------------------------------------------------------------------------
// Address: 0x1031BF00
// Name: _dynamic_initializer_for__autosavedangerous_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__autosavedangerous_command__()
{
  ConCommand::ConCommand(
    this: &autosavedangerous_command,
    pName: "autosavedangerous",
    callback: autosavedangerous,
    pHelpString: "AutoSaveDangerous",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__autosavedangerous_command__);
}

//------------------------------------------------------------------------------
// Address: 0x1031BF30
// Name: _dynamic_initializer_for__autosavedangerousissafe_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__autosavedangerousissafe_command__()
{
  ConCommand::ConCommand(
    this: &autosavedangerousissafe_command,
    pName: "autosavedangerousissafe",
    callback: autosavedangerousissafe,
    pHelpString: defaultValue,
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__autosavedangerousissafe_command__);
}

//------------------------------------------------------------------------------
// Address: 0x1031BFF0
// Name: _dynamic_initializer_for__in_forceuser__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__in_forceuser__()
{
  ConVar::ConVar(
    this: &in_forceuser,
    pName: "in_forceuser",
    pDefaultValue: "0",
    flags: 0x4000,
    pHelpString: "Force user input to this split screen player.");
  return atexit(func: dynamic_atexit_destructor_for__in_forceuser__);
}

//------------------------------------------------------------------------------
// Address: 0x1031D640
// Name: _dynamic_initializer_for__audit_save_in_memory_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__audit_save_in_memory_command__()
{
  ConCommand::ConCommand(
    this: &audit_save_in_memory_command,
    pName: "audit_save_in_memory",
    callback: (void (__cdecl *)(const CCommand *))CColorBalanceUIPanel::Init,
    pHelpString: "Audit the memory usage and files in the save-to-memory system",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__audit_save_in_memory_command__);
}

//------------------------------------------------------------------------------
// Address: 0x10325D50
// Name: _dynamic_atexit_destructor_for__map_wants_save_disable__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__map_wants_save_disable__()
{
  ConVar::~ConVar(this: &map_wants_save_disable);
}

//------------------------------------------------------------------------------
// Address: 0x10325DE0
// Name: _dynamic_atexit_destructor_for__xsave_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__xsave_command__()
{
  ConCommand::~ConCommand(this: &xsave_command);
}

//------------------------------------------------------------------------------
// Address: 0x10325DF0
// Name: _dynamic_atexit_destructor_for__minisave_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__minisave_command__()
{
  ConCommand::~ConCommand(this: &minisave_command);
}

//------------------------------------------------------------------------------
// Address: 0x10325E00
// Name: _dynamic_atexit_destructor_for___autosave_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for___autosave_command__()
{
  ConCommand::~ConCommand(this: &autosave_command);
}

//------------------------------------------------------------------------------
// Address: 0x10325E10
// Name: _dynamic_atexit_destructor_for___autosavedangerous_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for___autosavedangerous_command__()
{
  ConCommand::~ConCommand(this: &autosavedangerous_command);
}

//------------------------------------------------------------------------------
// Address: 0x10325E20
// Name: _dynamic_atexit_destructor_for__autosave_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__autosave_command__()
{
  ConCommand::~ConCommand(this: &autosave_command);
}

//------------------------------------------------------------------------------
// Address: 0x10325E30
// Name: _dynamic_atexit_destructor_for__autosavedangerous_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__autosavedangerous_command__()
{
  ConCommand::~ConCommand(this: &autosavedangerous_command);
}

//------------------------------------------------------------------------------
// Address: 0x10325E40
// Name: _dynamic_atexit_destructor_for__autosavedangerousissafe_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__autosavedangerousissafe_command__()
{
  ConCommand::~ConCommand(this: &autosavedangerousissafe_command);
}

//------------------------------------------------------------------------------
// Address: 0x10326840
// Name: _dynamic_atexit_destructor_for__audit_save_in_memory_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__audit_save_in_memory_command__()
{
  ConCommand::~ConCommand(this: &audit_save_in_memory_command);
}

} // namespace engine_xlsp
