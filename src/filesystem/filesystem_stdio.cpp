// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: filesystem/filesystem_stdio.cpp
// Functions: 59
// ============================================================

#include "filesystem\filesystem_stdio.h"

//------------------------------------------------------------------------------
// Address: 0x100025D0
// Name: public: virtual long CWin32ReadOnlyFile::FS_ftell(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CWin32ReadOnlyFile::FS_ftell(CIoStats *this)
{
  return this->m_nTimeInFileSeek.m_value;
}

//------------------------------------------------------------------------------
// Address: 0x10014C00
// Name: void __near * MemAlloc_AllocAlignedUnattributed(unsigned int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void *__cdecl MemAlloc_AllocAlignedUnattributed(unsigned int size, unsigned int align)
{
  unsigned int v2; // eax
  void *result; // eax
  unsigned int v4; // esi

  v2 = align;
  if ( ((align - 1) & align) != 0 )
    return nullptr;
  if ( align <= 4 )
    v2 = 4;
  v4 = v2 - 1;
  result = _g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: size + v2 - 1 + 4);
  if ( result != nullptr )
  {
    *(_DWORD *)((~v4 & ((unsigned int)result + v4 + 4)) - 4) = result;
    return (void *)(~v4 & ((unsigned int)result + v4 + 4));
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10014C50
// Name: public: struct TSLNodeBase_t __near * CTSListBase::Push(struct TSLNodeBase_t __near *)
// Source: json
//------------------------------------------------------------------------------
TSLNodeBase_t *__thiscall CTSListBase::Push(CTSListBase *this, TSLNodeBase_t *pNode)
{
  TSLNodeBase_t *Next; // edi
  int DepthAndSequence; // [esp-4h] [ebp-10h]
  int v6; // [esp-4h] [ebp-10h]

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
      v6 = this->m_Head.value32.DepthAndSequence;
      pNode->Next = this->m_Head.value.Next;
    }
    while ( (unsigned __int8)_ThreadInterlockedAssignIf64(a1: this, a2: pNode, a3: v6 + 65537, a4: Next, a5: v6) == 0 );
  }
  return Next;
}

//------------------------------------------------------------------------------
// Address: 0x10014CB0
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
// Address: 0x10014CF0
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
// Address: 0x10014D30
// Name: public: virtual int CStdFilesystemFile::FS_GetSectorSize(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CStdFilesystemFile::FS_GetSectorSize(CStdFilesystemFile *this)
{
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10014D40
// Name: public: virtual bool CWin32ReadOnlyFile::FS_setmode(enum FileMode_t)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CWin32ReadOnlyFile::FS_setmode(CWin32ReadOnlyFile *this, FileMode_t mode)
{
  _Error(a1: "Can't set mode, open a second file in right mode\n");
  return false;
}

//------------------------------------------------------------------------------
// Address: 0x10014D60
// Name: public: virtual int CWin32ReadOnlyFile::FS_GetSectorSize(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CWin32ReadOnlyFile::FS_GetSectorSize(CWin32ReadOnlyFile *this)
{
  return this->m_SectorSize;
}

//------------------------------------------------------------------------------
// Address: 0x10014DB0
// Name: public: virtual void __near * CFileSystem_Stdio::QueryInterface(char const __near *)
// Source: json
//------------------------------------------------------------------------------
IBaseFileSystem *__thiscall CFileSystem_Stdio::QueryInterface(CFileSystem_Stdio *this, const char *pInterfaceName)
{
  int v3; // eax

  v3 = _V_strlen(str: "VFileSystem017");
  if ( V_strncmp(s1: pInterfaceName, s2: "VFileSystem017", count: v3 + 1) != 0 )
    return CBaseFileSystem::QueryInterface(this, pInterfaceName);
  else
    return (IBaseFileSystem *)this;
}

//------------------------------------------------------------------------------
// Address: 0x10014DF0
// Name: public: virtual bool CFileSystem_Stdio::GetOptimalIOConstraints(void __near *,unsigned int __near *,unsigned int __near *,unsigned int __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CFileSystem_Stdio::GetOptimalIOConstraints(
        CFileSystem_Stdio *this,
        CFileHandle *hFile,
        unsigned int *pOffsetAlign,
        unsigned int *pSizeAlign,
        unsigned int *pBufferAlign)
{
  const char *CommandLine; // eax
  unsigned int SectorSize; // edi
  CPackFileHandle *m_pPackFileHandle; // esi

  if ( hFile == nullptr )
    goto LABEL_12;
  if ( hFile->m_VPKHandle.m_nFileNumber != -1 )
    return false;
  if ( (_S1_0 & 1) != 0 )
  {
    if ( byte_10052CE0 == 0 )
      goto LABEL_12;
LABEL_9:
    SectorSize = CFileHandle::GetSectorSize(this: hFile);
    if ( SectorSize != 0 )
    {
      m_pPackFileHandle = hFile->m_pPackFileHandle;
      if ( m_pPackFileHandle == nullptr
        || (m_pPackFileHandle->m_nBase
          + m_pPackFileHandle->m_pOwner->GetPackFileBaseOffset(this: m_pPackFileHandle->m_pOwner))
         % SectorSize == 0 )
      {
        goto LABEL_13;
      }
    }
    goto LABEL_12;
  }
  _S1_0 |= 1u;
  CommandLine = (const char *)_Plat_GetCommandLine(a1: this);
  if ( V_stristr(pStr: CommandLine, pSearch: "-unbuffered_io") != nullptr )
  {
    byte_10052CE0 = 1;
    goto LABEL_9;
  }
  byte_10052CE0 = 0;
LABEL_12:
  SectorSize = 1;
LABEL_13:
  if ( pOffsetAlign != nullptr )
    *pOffsetAlign = SectorSize;
  if ( pSizeAlign != nullptr )
    *pSizeAlign = SectorSize;
  if ( pBufferAlign != nullptr )
    *pBufferAlign = SectorSize;
  return SectorSize > 1;
}

//------------------------------------------------------------------------------
// Address: 0x10014EB0
// Name: public: virtual void CFileSystem_Stdio::FreeOptimalReadBuffer(void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFileSystem_Stdio::FreeOptimalReadBuffer(CFileSystem_Stdio *this, unsigned int p)
{
  const char *CommandLine; // eax

  if ( (_S1_0 & 1) != 0 )
  {
    if ( byte_10052CE0 == 0 )
      goto LABEL_9;
  }
  else
  {
    _S1_0 |= 1u;
    CommandLine = (const char *)_Plat_GetCommandLine(a1: this);
    if ( V_stristr(pStr: CommandLine, pSearch: "-unbuffered_io") == nullptr )
    {
      byte_10052CE0 = 0;
LABEL_9:
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)p);
      return;
    }
    byte_10052CE0 = 1;
  }
  if ( p != 0 )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: *(void **)((p & 0xFFFFFFFC) - 4));
}

//------------------------------------------------------------------------------
// Address: 0x10014F30
// Name: protected: virtual void CFileSystem_Stdio::FS_setbufsize(struct _iobuf __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFileSystem_Stdio::FS_setbufsize(CFileSystem_Stdio *this, _iobuf *fp, unsigned int nBytes)
{
  (*((void (__thiscall **)(_iobuf *, unsigned int))fp->_ptr + 1))(a1: fp, a2: nBytes);
}

//------------------------------------------------------------------------------
// Address: 0x10014F50
// Name: protected: virtual void CFileSystem_Stdio::FS_fclose(struct _iobuf __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFileSystem_Stdio::FS_fclose(CFileSystem_Stdio *this, _iobuf *fp)
{
  (*((void (__thiscall **)(_iobuf *))fp->_ptr + 2))(a1: fp);
  (*(void (__thiscall **)(_iobuf *, int))fp->_ptr)(a1: fp, a2: 1);
}

//------------------------------------------------------------------------------
// Address: 0x10014F70
// Name: protected: virtual void CFileSystem_Stdio::FS_fseek(struct _iobuf __near *,__int64,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFileSystem_Stdio::FS_fseek(CFileSystem_Stdio *this, _iobuf *fp, __int64 pos, int seekType)
{
  (*((void (__thiscall **)(_iobuf *, _DWORD, _DWORD, int))fp->_ptr + 3))(
    a1: fp,
    a2: pos,
    a3: HIDWORD(pos),
    a4: seekType);
}

//------------------------------------------------------------------------------
// Address: 0x10014F90
// Name: protected: virtual long CFileSystem_Stdio::FS_ftell(struct _iobuf __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CFileSystem_Stdio::FS_ftell(CFileSystem_Stdio *this, _iobuf *fp)
{
  return (*((int (__thiscall **)(_iobuf *))fp->_ptr + 4))(a1: fp);
}

//------------------------------------------------------------------------------
// Address: 0x10014FB0
// Name: protected: virtual int CFileSystem_Stdio::FS_feof(struct _iobuf __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CFileSystem_Stdio::FS_feof(CFileSystem_Stdio *this, _iobuf *fp)
{
  return (*((int (__thiscall **)(_iobuf *))fp->_ptr + 5))(a1: fp);
}

//------------------------------------------------------------------------------
// Address: 0x10014FD0
// Name: protected: virtual unsigned int CFileSystem_Stdio::FS_fread(void __near *,unsigned int,unsigned int,struct _iobuf __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CFileSystem_Stdio::FS_fread(
        CFileSystem_Stdio *this,
        void *dest,
        unsigned int destSize,
        unsigned int size,
        _iobuf *fp)
{
  int v6; // edi

  v6 = (*((int (__thiscall **)(_iobuf *, void *, unsigned int, unsigned int))fp->_ptr + 6))(
         a1: fp,
         a2: dest,
         a3: destSize,
         a4: size);
  CBaseFileSystem::Trace_FRead(this, size: v6, fp);
  return v6;
}

//------------------------------------------------------------------------------
// Address: 0x10015010
// Name: protected: virtual unsigned int CFileSystem_Stdio::FS_fwrite(void const __near *,unsigned int,struct _iobuf __near *)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CFileSystem_Stdio::FS_fwrite(
        CFileSystem_Stdio *this,
        const void *src,
        unsigned int size,
        _iobuf *fp)
{
  return (*((unsigned int (__thiscall **)(_iobuf *, const void *, unsigned int))fp->_ptr + 7))(
           a1: fp,
           a2: src,
           a3: size);
}

//------------------------------------------------------------------------------
// Address: 0x10015030
// Name: protected: virtual bool CFileSystem_Stdio::FS_setmode(struct _iobuf __near *,enum FileMode_t)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CFileSystem_Stdio::FS_setmode(CFileSystem_Stdio *this, _iobuf *fp, FileMode_t mode)
{
  return (*((bool (__thiscall **)(_iobuf *, FileMode_t))fp->_ptr + 8))(a1: fp, a2: mode);
}

//------------------------------------------------------------------------------
// Address: 0x10015050
// Name: protected: virtual unsigned int CFileSystem_Stdio::FS_vfprintf(struct _iobuf __near *,char const __near *,char __near *)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CFileSystem_Stdio::FS_vfprintf(
        CFileSystem_Stdio *this,
        _iobuf *fp,
        const char *fmt,
        char *list)
{
  return (*((unsigned int (__thiscall **)(_iobuf *, const char *, char *))fp->_ptr + 9))(a1: fp, a2: fmt, a3: list);
}

//------------------------------------------------------------------------------
// Address: 0x10015070
// Name: protected: virtual int CFileSystem_Stdio::FS_ferror(struct _iobuf __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CFileSystem_Stdio::FS_ferror(CFileSystem_Stdio *this, _iobuf *fp)
{
  return (*((int (__thiscall **)(_iobuf *))fp->_ptr + 10))(a1: fp);
}

//------------------------------------------------------------------------------
// Address: 0x10015090
// Name: protected: virtual int CFileSystem_Stdio::FS_fflush(struct _iobuf __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CFileSystem_Stdio::FS_fflush(CFileSystem_Stdio *this, _iobuf *fp)
{
  return (*((int (__thiscall **)(_iobuf *))fp->_ptr + 11))(a1: fp);
}

//------------------------------------------------------------------------------
// Address: 0x100150B0
// Name: protected: virtual char __near * CFileSystem_Stdio::FS_fgets(char __near *,int,struct _iobuf __near *)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CFileSystem_Stdio::FS_fgets(CFileSystem_Stdio *this, char *dest, int destSize, _iobuf *fp)
{
  return (*((char *(__thiscall **)(_iobuf *, char *, int))fp->_ptr + 12))(a1: fp, a2: dest, a3: destSize);
}

//------------------------------------------------------------------------------
// Address: 0x100150D0
// Name: protected: virtual int CFileSystem_Stdio::FS_chmod(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CFileSystem_Stdio::FS_chmod(CFileSystem_Stdio *this, const char *path, int pmode)
{
  if ( path != nullptr )
    return _chmod(path, mode: pmode);
  else
    return -1;
}

//------------------------------------------------------------------------------
// Address: 0x10015100
// Name: protected: virtual int CFileSystem_Stdio::FS_stat(char const __near *,struct _stat32 __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CFileSystem_Stdio::FS_stat(CFileSystem_Stdio *this, const char *path, _stat32 *buf)
{
  if ( path != nullptr )
    return _stat32(name: path, buf);
  else
    return -1;
}

//------------------------------------------------------------------------------
// Address: 0x10015130
// Name: protected: virtual void __near * CFileSystem_Stdio::FS_FindFirstFile(char const __near *,struct _WIN32_FIND_DATAA __near *)
// Source: json
//------------------------------------------------------------------------------
HANDLE __thiscall CFileSystem_Stdio::FS_FindFirstFile(
        CFileSystem_Stdio *this,
        const char *findname,
        _WIN32_FIND_DATAA *dat)
{
  return FindFirstFileA(lpFileName: findname, lpFindFileData: dat);
}

//------------------------------------------------------------------------------
// Address: 0x10015140
// Name: protected: virtual bool CFileSystem_Stdio::FS_FindNextFile(void __near *,struct _WIN32_FIND_DATAA __near *)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CFileSystem_Stdio::FS_FindNextFile(CFileSystem_Stdio *this, void *handle, _WIN32_FIND_DATAA *dat)
{
  return FindNextFileA(hFindFile: handle, lpFindFileData: dat);
}

//------------------------------------------------------------------------------
// Address: 0x10015160
// Name: protected: virtual bool CFileSystem_Stdio::FS_FindClose(void __near *)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CFileSystem_Stdio::FS_FindClose(CFileSystem_Stdio *this, void *handle)
{
  return FindClose(hFindFile: handle);
}

//------------------------------------------------------------------------------
// Address: 0x10015180
// Name: protected: virtual int CFileSystem_Stdio::FS_GetSectorSize(struct _iobuf __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CFileSystem_Stdio::FS_GetSectorSize(CFileSystem_Stdio *this, _iobuf *fp)
{
  return (*((int (__thiscall **)(_iobuf *))fp->_ptr + 13))(a1: fp);
}

//------------------------------------------------------------------------------
// Address: 0x100151A0
// Name: public: virtual bool CFileSystem_Stdio::IsFileImmediatelyAvailable(char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CFileSystem_Stdio::IsFileImmediatelyAvailable(CFileSystem_Stdio *this, const char *pFileName)
{
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100151B0
// Name: public: virtual int CFileSystem_Stdio::WaitForResources(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CFileSystem_Stdio::WaitForResources(CBaseFileSystem *this, _iobuf *__formal)
{
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100151C0
// Name: public: virtual bool CFileSystem_Stdio::GetWaitForResourcesProgress(int,float __near *,bool __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CFileSystem_Stdio::GetWaitForResourcesProgress(
        CFileSystem_Stdio *this,
        int handle,
        float *progress,
        bool *complete)
{
  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "GetWaitForResourcesProgress (stdio)",
    a3: 0,
    a4: "FileSystem",
    a5: false,
    a6: 4);
  *progress = 0.0;
  *complete = true;
  CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10015210
// Name: public: virtual int CFileSystem_Stdio::HintResourceNeed(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CFileSystem_Stdio::HintResourceNeed(
        CFileSystem_Stdio *this,
        const char *hintlist,
        const char *forgetEverything)
{
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10015220
// Name: public: virtual void CStdioFile::FS_setbufsize(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CStdioFile::FS_setbufsize(CStdioFile *this, unsigned int nBytes)
{
  if ( nBytes != 0 )
  {
    setvbuf(str: this->m_pFile, buffer: nullptr, type: 0, size: 0x8000u);
  }
  else
  {
    setvbuf(str: this->m_pFile, buffer: nullptr, type: 4, size: 0);
    this->m_pFile->_bufsiz = 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10015270
// Name: public: virtual void CStdioFile::FS_fclose(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CStdioFile::FS_fclose(CStdioFile *this)
{
  fclose(stream: this->m_pFile);
}

//------------------------------------------------------------------------------
// Address: 0x10015280
// Name: public: virtual void CStdioFile::FS_fseek(__int64,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CStdioFile::FS_fseek(CStdioFile *this, __int64 pos, int seekType)
{
  __int64 i; // rdi

  for ( i = pos; i > 0x7FFFFFFF; seekType = 1 )
  {
    fseek(stream: this->m_pFile, offset: 0x7FFFFFFF, whence: seekType);
    i -= 0x7FFFFFFF;
  }
  for ( ; i < (__int64)0xFFFFFFFF80000000uLL; seekType = 1 )
  {
    fseek(stream: this->m_pFile, offset: 0x80000000, whence: seekType);
    i += 0x80000000LL;
  }
  fseek(stream: this->m_pFile, offset: i, whence: seekType);
}

//------------------------------------------------------------------------------
// Address: 0x10015330
// Name: public: virtual long CStdioFile::FS_ftell(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CStdioFile::FS_ftell(CStdioFile *this)
{
  return ftell(stream: this->m_pFile);
}

//------------------------------------------------------------------------------
// Address: 0x10015340
// Name: public: virtual int CStdioFile::FS_feof(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CStdioFile::FS_feof(CStdioFile *this)
{
  return feof(stream: this->m_pFile);
}

//------------------------------------------------------------------------------
// Address: 0x10015350
// Name: public: virtual unsigned int CStdioFile::FS_fread(void __near *,unsigned int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CStdioFile::FS_fread(CStdioFile *this, void *dest, unsigned int destSize, unsigned int size)
{
  return fread(buffer: dest, elementSize: 1u, count: size, stream: this->m_pFile);
}

//------------------------------------------------------------------------------
// Address: 0x10015370
// Name: public: virtual unsigned int CStdioFile::FS_fwrite(void const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CStdioFile::FS_fwrite(CStdioFile *this, char *src, unsigned int size)
{
  unsigned int v3; // edi
  char *v4; // ebx
  unsigned int v5; // esi
  unsigned int total; // [esp+10h] [ebp+8h]

  v3 = size;
  if ( size <= 0x40000 )
    return fwrite(buffer: src, size: 1u, count: size, stream: this->m_pFile);
  v4 = src;
  total = 0;
  do
  {
    v5 = v3;
    if ( v3 >= 0x40000 )
      v5 = 0x40000;
    total += fwrite(buffer: v4, size: 1u, count: v5, stream: this->m_pFile);
    v4 += v5;
    v3 -= v5;
  }
  while ( v3 != 0 );
  return total;
}

//------------------------------------------------------------------------------
// Address: 0x100153F0
// Name: public: virtual bool CStdioFile::FS_setmode(enum FileMode_t)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CStdioFile::FS_setmode(CStdioFile *this, FileMode_t mode)
{
  int v2; // eax

  v2 = _fileno(stream: this->m_pFile);
  return _setmode(fh: v2, mode: mode != FM_BINARY ? 0x4000 : 0x8000) != -1;
}

//------------------------------------------------------------------------------
// Address: 0x10015430
// Name: public: virtual unsigned int CStdioFile::FS_vfprintf(char const __near *,char __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CStdioFile::FS_vfprintf(CStdioFile *this, const char *fmt, char *list)
{
  return vfprintf(str: this->m_pFile, format: fmt, ap: list);
}

//------------------------------------------------------------------------------
// Address: 0x10015450
// Name: public: virtual int CStdioFile::FS_ferror(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CStdioFile::FS_ferror(CStdioFile *this)
{
  return ferror(stream: this->m_pFile);
}

//------------------------------------------------------------------------------
// Address: 0x10015460
// Name: public: virtual int CStdioFile::FS_fflush(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CStdioFile::FS_fflush(CStdioFile *this)
{
  return fflush(stream: this->m_pFile);
}

//------------------------------------------------------------------------------
// Address: 0x10015470
// Name: public: virtual char __near * CStdioFile::FS_fgets(char __near *,int)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CStdioFile::FS_fgets(CStdioFile *this, char *dest, int destSize)
{
  return fgets(string: dest, count: destSize, str: this->m_pFile);
}

//------------------------------------------------------------------------------
// Address: 0x10015490
// Name: int GetSectorSize(char const __near *)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl GetSectorSize(unsigned int pszFilename)
{
  char *v1; // edi
  char v2; // cl
  char v3; // al
  char v4; // bl
  unsigned int v5; // esi
  char volume; // al
  const char *result; // eax
  char v8; // dl
  int v9; // [esp-Ch] [ebp-218h]
  char szAbsoluteFilename[512]; // [esp+4h] [ebp-208h] BYREF
  unsigned int ignored; // [esp+204h] [ebp-8h] BYREF
  char root[4]; // [esp+208h] [ebp-4h] BYREF

  v1 = (char *)pszFilename;
  v2 = *(_BYTE *)pszFilename;
  if ( *(_BYTE *)pszFilename == 0 )
    return nullptr;
  v3 = *(_BYTE *)(pszFilename + 1);
  if ( v3 == 0 || v2 == 92 && v3 == 92 )
    return nullptr;
  if ( v2 == 47 && v3 == 47 )
    return nullptr;
  if ( v3 != 58 )
  {
    V_MakeAbsolutePath(pOut: szAbsoluteFilename, outLen: 512, pPath: (const char *)pszFilename, pStartingDir: nullptr);
    v1 = szAbsoluteFilename;
  }
  v9 = *v1;
  pszFilename = 1;
  v4 = tolower(c: v9);
  v5 = 0;
  while ( 1 )
  {
    volume = cachedSizes[v5].volume;
    if ( volume == 0 )
    {
LABEL_13:
      result = (const char *)pszFilename;
      goto LABEL_14;
    }
    if ( volume == v4 )
      break;
    if ( ++v5 >= 4 )
      goto LABEL_13;
  }
  result = (const char *)dword_10052CEC[2 * v5];
  pszFilename = (unsigned int)result;
LABEL_14:
  if ( result == (const char *)1 )
  {
    v8 = *v1;
    strcpy(root, "X:\\");
    root[0] = v8;
    result = (const char *)GetDiskFreeSpaceA(
                             lpRootPathName: root,
                             lpSectorsPerCluster: &ignored,
                             lpBytesPerSector: &pszFilename,
                             lpNumberOfFreeClusters: &ignored,
                             lpTotalNumberOfClusters: &ignored);
    if ( result != nullptr )
      result = (const char *)pszFilename;
    if ( v5 < 4 )
    {
      cachedSizes[v5].volume = v4;
      dword_10052CEC[2 * v5] = (int)result;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10015590
// Name: public: virtual void CWin32ReadOnlyFile::FS_fclose(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWin32ReadOnlyFile::FS_fclose(CWin32ReadOnlyFile *this)
{
  void *m_hFileBuffered; // esi

  if ( this->m_hFileUnbuffered != (void *)-1 )
    CloseHandle(hObject: this->m_hFileUnbuffered);
  m_hFileBuffered = this->m_hFileBuffered;
  if ( m_hFileBuffered != (void *)-1 )
    CloseHandle(hObject: m_hFileBuffered);
}

//------------------------------------------------------------------------------
// Address: 0x100155C0
// Name: public: virtual void CWin32ReadOnlyFile::FS_fseek(__int64,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWin32ReadOnlyFile::FS_fseek(CWin32ReadOnlyFile *this, __int64 pos, int seekType)
{
  bool v3; // cf

  if ( seekType != 0 )
  {
    if ( seekType == 1 )
    {
      v3 = __CFADD__((_DWORD)pos, this->m_ReadPos);
      LODWORD(this->m_ReadPos) += pos;
      HIDWORD(this->m_ReadPos) += HIDWORD(pos) + v3;
    }
    else if ( seekType == 2 )
    {
      this->m_ReadPos = this->m_Size - pos;
    }
  }
  else
  {
    this->m_ReadPos = pos;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10015610
// Name: public: virtual int CWin32ReadOnlyFile::FS_feof(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CWin32ReadOnlyFile::FS_feof(CWin32ReadOnlyFile *this)
{
  return this->m_ReadPos >= this->m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x10015630
// Name: public: virtual char __near * CWin32ReadOnlyFile::FS_fgets(char __near *,int)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CWin32ReadOnlyFile::FS_fgets(CWin32ReadOnlyFile *this, char *dest, unsigned int destSize)
{
  char *result; // eax
  int v5; // esi
  int v6; // eax
  int v7; // eax
  char *v8; // eax
  int nStartPos; // [esp+4h] [ebp-4h]
  int destSizea; // [esp+14h] [ebp+Ch]

  if ( this->FS_feof(this) != 0 )
    return nullptr;
  nStartPos = this->m_ReadPos;
  result = (char *)this->FS_fread(this, a2: dest, a3: destSize, a4: destSize);
  v5 = (int)result;
  if ( result != nullptr )
  {
    v6 = destSize - 1;
    destSizea = v6;
    if ( v5 < v6 )
      v6 = v5;
    dest[v6] = 0;
    strchr(string: (unsigned __int8 *)dest, chr: 0xAu);
    if ( v7 != 0 )
    {
      v8 = (char *)(v7 + 1);
      *v8 = 0;
    }
    else
    {
      if ( v5 >= destSizea )
        v5 = destSizea;
      v8 = &dest[v5];
    }
    this->m_ReadPos = v8 - dest + nStartPos + 1;
    return dest;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10015700
// Name: public: virtual void __near * CFileSystem_Stdio::AllocOptimalReadBuffer(void __near *,unsigned int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void *__thiscall CFileSystem_Stdio::AllocOptimalReadBuffer(
        CFileSystem_Stdio *this,
        CFileHandle *hFile,
        unsigned int nSize,
        unsigned int nOffset)
{
  const char *CommandLine; // eax
  unsigned int v5; // ebx
  unsigned int SectorSize; // esi
  CPackFileHandle *m_pPackFileHandle; // edi

  if ( (_S1_0 & 1) != 0 )
  {
    if ( byte_10052CE0 == 0 )
      return _g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: nSize);
  }
  else
  {
    _S1_0 |= 1u;
    CommandLine = (const char *)_Plat_GetCommandLine(a1: this);
    if ( V_stristr(pStr: CommandLine, pSearch: "-unbuffered_io") == nullptr )
    {
      byte_10052CE0 = 0;
      return _g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: nSize);
    }
    byte_10052CE0 = 1;
  }
  if ( hFile != nullptr )
  {
    v5 = nSize;
    SectorSize = CFileHandle::GetSectorSize(this: hFile);
    if ( nSize == 0 )
      v5 = CFileHandle::Size(this: hFile);
    m_pPackFileHandle = hFile->m_pPackFileHandle;
    if ( m_pPackFileHandle != nullptr )
      nOffset += LODWORD(m_pPackFileHandle->m_nBase)
               + m_pPackFileHandle->m_pOwner->GetPackFileBaseOffset(this: m_pPackFileHandle->m_pOwner);
  }
  else
  {
    v5 = nSize;
    SectorSize = 4;
  }
  if ( nOffset % SectorSize != 0 )
    return MemAlloc_AllocAlignedUnattributed(size: v5, align: 4u);
  else
    return MemAlloc_AllocAlignedUnattributed(size: ~(SectorSize - 1) & (SectorSize + v5 - 1), align: SectorSize);
}

//------------------------------------------------------------------------------
// Address: 0x100157F0
// Name: public: static class CStdioFile __near * CStdioFile::FS_fopen(char const __near *,char const __near *,__int64 __near *)
// Source: json
//------------------------------------------------------------------------------
CStdioFile *__cdecl CStdioFile::FS_fopen(const char *filename, char *options, __int64 *size)
{
  _iobuf *v3; // esi
  bool v4; // bl
  int v5; // eax
  int v6; // eax
  CStdioFile *result; // eax
  _stat32 buf; // [esp+Ch] [ebp-24h] BYREF

  v3 = fopen(file: filename, mode: options);
  if ( v3 == nullptr )
    return nullptr;
  if ( size != nullptr && _stat32(name: filename, &buf) == 0 )
    *size = buf.st_size;
  v4 = false;
  strchr(string: (unsigned __int8 *)options, chr: 0x77u);
  if ( v5 != 0 || (strchr(string: (unsigned __int8 *)options, chr: 0x61u), v6 != 0) )
    v4 = true;
  result = (CStdioFile *)operator new(nSize: 0xCu);
  if ( result == nullptr )
    return nullptr;
  result->m_pFile = v3;
  result->m_bWriteable = v4;
  result->__vftable = (CStdioFile_vtbl *)&CStdioFile::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10015880
// Name: public: static class CWin32ReadOnlyFile __near * CWin32ReadOnlyFile::FS_fopen(char const __near *,char const __near *,__int64 __near *)
// Source: json
//------------------------------------------------------------------------------
CWin32ReadOnlyFile *__cdecl CWin32ReadOnlyFile::FS_fopen(const char *filename, const char *options, __int64 *size)
{
  int v3; // ecx
  const char *CommandLine; // eax
  char v5; // cl
  int m_nValue; // eax
  bool v7; // dl
  int v8; // edi
  int v9; // eax
  HANDLE FileA; // eax
  int v11; // esi
  DWORD v12; // eax
  int v13; // esi
  CWin32ReadOnlyFile *result; // eax
  int v15; // ecx
  int v16; // edx
  _LARGE_INTEGER v17; // [esp+0h] [ebp-20h] BYREF
  _LARGE_INTEGER FileSize; // [esp+8h] [ebp-18h] BYREF
  __int64 fileSize; // [esp+10h] [ebp-10h]
  int sectorSize; // [esp+18h] [ebp-8h]
  bool bOverlapped; // [esp+1Fh] [ebp-1h]

  sectorSize = 0;
  if ( (_S1_0 & 1) != 0 )
  {
    if ( byte_10052CE0 == 0 )
      goto LABEL_4;
  }
  else
  {
    _S1_0 |= 1u;
    CommandLine = (const char *)_Plat_GetCommandLine(a1: v3);
    if ( V_stristr(pStr: CommandLine, pSearch: "-unbuffered_io") == nullptr )
    {
      byte_10052CE0 = 0;
LABEL_4:
      v5 = 0;
      goto LABEL_5;
    }
    byte_10052CE0 = 1;
  }
  if ( filesystem_unbuffered_io.m_pParent == nullptr )
    goto LABEL_4;
  if ( filesystem_unbuffered_io.m_pParent->m_Value.m_nValue == 0 )
    goto LABEL_4;
  sectorSize = (int)GetSectorSize(pszFilename: (unsigned int)filename);
  if ( sectorSize == 0 )
    goto LABEL_4;
  v5 = 1;
LABEL_5:
  if ( filesystem_use_overlapped_io.m_pParent != nullptr )
    m_nValue = filesystem_use_overlapped_io.m_pParent->m_Value.m_nValue;
  else
    m_nValue = 0;
  v7 = m_nValue != 0;
  v8 = -1;
  bOverlapped = m_nValue != 0;
  fileSize = 0;
  if ( v5 != 0 )
  {
    v9 = 128;
    if ( v7 )
      v9 = 1073741952;
    FileA = CreateFileA(
              lpFileName: filename,
              dwDesiredAccess: 0x80000000,
              dwShareMode: 1u,
              lpSecurityAttributes: nullptr,
              dwCreationDisposition: 3u,
              dwFlagsAndAttributes: v9 | 0x20000000,
              hTemplateFile: nullptr);
    v11 = (int)FileA;
    if ( FileA != (HANDLE)-1 )
    {
      if ( !GetFileSizeEx(hFile: FileA, lpFileSize: &FileSize) )
      {
        CloseHandle(hObject: (HANDLE)v11);
        v11 = -1;
      }
      fileSize = FileSize.QuadPart;
    }
    v8 = v11;
    if ( v11 == -1 )
      return nullptr;
    v7 = bOverlapped;
  }
  v12 = 128;
  if ( v7 )
    v12 = 1073741952;
  v13 = (int)CreateFileA(
               lpFileName: filename,
               dwDesiredAccess: 0x80000000,
               dwShareMode: 1u,
               lpSecurityAttributes: nullptr,
               dwCreationDisposition: 3u,
               dwFlagsAndAttributes: v12,
               hTemplateFile: nullptr);
  if ( v13 != -1 )
  {
    if ( fileSize == 0 )
    {
      if ( !GetFileSizeEx(hFile: (HANDLE)v13, lpFileSize: &v17) )
      {
        CloseHandle(hObject: (HANDLE)v13);
        v13 = -1;
      }
      fileSize = v17.QuadPart;
    }
    if ( v13 != -1 )
    {
      if ( size != nullptr )
        *size = fileSize;
      result = (CWin32ReadOnlyFile *)operator new(nSize: 0x30u);
      if ( result == nullptr )
        return nullptr;
      v15 = sectorSize;
      if ( sectorSize == 0 )
        v15 = 1;
      LODWORD(result->m_Size) = fileSize;
      v16 = HIDWORD(fileSize);
      LODWORD(result->m_ReadPos) = 0;
      HIDWORD(result->m_ReadPos) = 0;
      result->m_hFileUnbuffered = (void *)v8;
      result->m_hFileBuffered = (void *)v13;
      result->__vftable = (CWin32ReadOnlyFile_vtbl *)&CWin32ReadOnlyFile::`vftable';
      HIDWORD(result->m_Size) = v16;
      result->m_Mutex.m_ownerID = 0;
      result->m_Mutex.m_depth = 0;
      result->m_SectorSize = v15;
      result->m_bOverlapped = bOverlapped;
      return result;
    }
  }
  if ( v8 != -1 )
    CloseHandle(hObject: (HANDLE)v8);
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10015A60
// Name: protected: virtual struct _iobuf __near * CFileSystem_Stdio::FS_fopen(char const __near *,char const __near *,unsigned int,__int64 __near *,class CFileLoadInfo __near *)
// Source: json
//------------------------------------------------------------------------------
CStdioFile *__thiscall CFileSystem_Stdio::FS_fopen(
        CFileSystem_Stdio *this,
        const char *filename,
        char *options,
        unsigned int flags,
        __int64 *size,
        CFileLoadInfo *pInfo)
{
  if ( pInfo != nullptr )
    pInfo->m_bLoadedFromSteamCache = false;
  if ( *options == 114
    && options[1] == 98
    && options[2] == 0
    && filesystem_native.m_pParent != nullptr
    && filesystem_native.m_pParent->m_Value.m_nValue != 0 )
  {
    return (CStdioFile *)CWin32ReadOnlyFile::FS_fopen(filename, options, size);
  }
  else
  {
    return CStdioFile::FS_fopen(filename, options, size);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10015AC0
// Name: public: virtual unsigned int CWin32ReadOnlyFile::FS_fread(void __near *,unsigned int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CWin32ReadOnlyFile::FS_fread(
        CWin32ReadOnlyFile *this,
        unsigned __int8 *dest,
        unsigned int destSize,
        unsigned int size)
{
  CWin32ReadOnlyFile *v4; // esi
  void *m_hFileUnbuffered; // edi
  void *m_hFileBuffered; // edx
  __int64 v7; // rcx
  unsigned int m_SectorSize; // esi
  unsigned int v9; // ecx
  bool v10; // zf
  TSLNodeBase_t *v11; // eax
  char *v12; // eax
  TSLNodeBase_t *v13; // edi
  int m_nValue; // eax
  unsigned int v15; // edi
  DWORD v16; // esi
  HANDLE v17; // edi
  BOOL v18; // eax
  char v19; // bl
  DWORD LastError; // eax
  int v21; // eax
  unsigned __int8 *v23; // [esp-14h] [ebp-805Ch]
  _BYTE v24[32769]; // [esp+7h] [ebp-8041h] BYREF
  _OVERLAPPED Overlapped; // [esp+8008h] [ebp-40h] BYREF
  __int64 v26; // [esp+801Ch] [ebp-2Ch]
  unsigned int NumberOfBytesRead; // [esp+8024h] [ebp-24h] BYREF
  CThreadEvent *v28; // [esp+8028h] [ebp-20h]
  __int64 v29; // [esp+802Ch] [ebp-1Ch]
  unsigned __int8 *v30; // [esp+8034h] [ebp-14h]
  unsigned int v31; // [esp+8038h] [ebp-10h]
  HANDLE hFile; // [esp+803Ch] [ebp-Ch]
  signed int v33; // [esp+8040h] [ebp-8h]
  CWin32ReadOnlyFile *v34; // [esp+8044h] [ebp-4h]
  unsigned int v35; // [esp+8054h] [ebp+Ch]

  v4 = this;
  v34 = this;
  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "CWin32ReadOnlyFile::FS_fread",
    a3: 0,
    a4: "FileSystem",
    a5: false,
    a6: 4);
  if ( size == 0 || (m_hFileUnbuffered = v4->m_hFileUnbuffered) == (void *)-1 && v4->m_hFileBuffered == (void *)-1 )
  {
    CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
    return 0;
  }
  v28 = nullptr;
  if ( destSize == -1 )
    destSize = size;
  m_hFileBuffered = v4->m_hFileBuffered;
  v33 = size;
  HIDWORD(v7) = HIDWORD(v4->m_ReadPos);
  v30 = dest;
  LODWORD(v7) = v4->m_ReadPos;
  hFile = m_hFileBuffered;
  v26 = v7;
  if ( m_hFileUnbuffered != (void *)-1 )
  {
    m_SectorSize = v4->m_SectorSize;
    if ( (unsigned int)dest % m_SectorSize == 0 && destSize % m_SectorSize == 0 && v7 % (int)m_SectorSize == 0 )
    {
      v33 = ~(m_SectorSize - 1) & (m_SectorSize + size - 1);
LABEL_13:
      hFile = m_hFileUnbuffered;
      goto LABEL_14;
    }
    v9 = ~(m_SectorSize - 1)
       & (m_SectorSize + LODWORD(v34->m_ReadPos) - (~(m_SectorSize - 1) & v34->m_ReadPos) + size - 1);
    if ( v9 <= 0x8000 - m_SectorSize )
    {
      v26 = ~(m_SectorSize - 1) & v34->m_ReadPos;
      v33 = v9;
      v30 = (unsigned __int8 *)(~(m_SectorSize - 1) & (unsigned int)&v24[m_SectorSize]);
      goto LABEL_13;
    }
LABEL_14:
    v4 = v34;
  }
  v10 = !v4->m_bOverlapped;
  memset(&Overlapped, 0, sizeof(Overlapped));
  if ( !v10 )
  {
    v11 = CTSListBase::Pop(this: &g_ThreadIOEvents.m_Events);
    if ( v11 == nullptr )
    {
      v12 = (char *)operator new(nSize: 0x10u);
      v13 = (TSLNodeBase_t *)v12;
      if ( v12 != nullptr )
      {
        CThreadEvent::CThreadEvent(this: (CThreadEvent *)(v12 + 4), a2: false);
        v11 = v13;
      }
      else
      {
        v11 = nullptr;
      }
    }
    v28 = (CThreadEvent *)(&v11->Next + 1);
    Overlapped.hEvent = *((void **)&v11->Next + 1);
  }
  if ( (_S2 & 1) == 0 )
  {
    _S2 |= 1u;
    if ( filesystem_max_stdio_read.m_pParent != nullptr )
      m_nValue = filesystem_max_stdio_read.m_pParent->m_Value.m_nValue;
    else
      m_nValue = 0;
    MAX_READ = m_nValue << 20;
  }
  v15 = 0;
  v35 = 0;
  v31 = 0;
  v29 = v26;
  while ( v33 > 0 )
  {
    v16 = MAX_READ;
    if ( v33 < (int)MAX_READ )
      v16 = v33;
    *(_QWORD *)&Overlapped.Offset = v29;
    v23 = &v30[v15];
    v17 = hFile;
    NumberOfBytesRead = 0;
    v18 = ReadFile(
            hFile,
            lpBuffer: v23,
            nNumberOfBytesToRead: v16,
            lpNumberOfBytesRead: &NumberOfBytesRead,
            lpOverlapped: &Overlapped);
    v19 = v18;
    if ( !v18 )
    {
      if ( v34->m_bOverlapped == v19 || GetLastError() != 997 )
        goto LABEL_37;
      v19 = 1;
    }
    if ( GetOverlappedResult(
           hFile: v17,
           lpOverlapped: &Overlapped,
           lpNumberOfBytesTransferred: &NumberOfBytesRead,
           bWait: true) )
    {
      v35 += NumberOfBytesRead;
      v33 -= v16;
      v29 += NumberOfBytesRead;
      if ( v19 != 0 )
        goto LABEL_27;
    }
    else
    {
      v19 = 0;
    }
LABEL_37:
    LastError = GetLastError();
    if ( LastError == 1450 && (int)MAX_READ > 0x10000 )
    {
      MAX_READ = (int)MAX_READ / 2;
      DevMsg(a1: "ERROR_NO_SYSTEM_RESOURCES: Reducing max read to %d bytes\n", MAX_READ);
    }
    else
    {
      DevMsg(a1: "Unknown read error %d\n", LastError);
      if ( v19 == 0 )
      {
        v4 = v34;
        goto LABEL_50;
      }
    }
LABEL_27:
    v15 = v35;
    v4 = v34;
  }
  if ( v15 != 0 && hFile == v4->m_hFileUnbuffered && v30 != dest )
  {
    v21 = LODWORD(v4->m_ReadPos) - v26;
    v15 -= v21;
    if ( v15 != 0 )
      memcpy(dst: dest, src: &v30[v21], count: size);
  }
  v31 = v15;
  if ( v15 >= size )
    v31 = size;
LABEL_50:
  if ( v4->m_bOverlapped )
  {
    CThreadEvent::Reset(this: v28);
    CTSListBase::Push(this: &g_ThreadIOEvents.m_Events, pNode: (TSLNodeBase_t *)&v28[-1].m_bCreatedHandle);
  }
  v4->m_ReadPos += v31;
  CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
  return v31;
}

//------------------------------------------------------------------------------
// Address: 0x10015E00
// Name: public: CTSPool<class CThreadEvent>::~CTSPool<class CThreadEvent>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTSPool<CThreadEvent>::~CTSPool<CThreadEvent>(CTSPool<CThreadEvent> *this)
{
  TSLNodeBase_t *Next; // esi
  int DepthAndSequence; // eax

  while ( 1 )
  {
    Next = this->m_Head.value.Next;
    DepthAndSequence = this->m_Head.value32.DepthAndSequence;
    if ( this->m_Head.value.Next == nullptr )
      break;
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
        goto LABEL_4;
    }
    CThreadSyncObject::~CThreadSyncObject(this: (CThreadSyncObject *)(&Next->Next + 1));
    free(pMem: Next);
  }
LABEL_4:
  CTSListBase::Detach(this);
}

//------------------------------------------------------------------------------
// Address: 0x10014D70
// Name: __CreateCFileSystem_StdioIFileSystem_interface
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CFileSystem_Stdio *__cdecl _CreateCFileSystem_StdioIFileSystem_interface()
{
  return &g_FileSystem_Stdio;
}

//------------------------------------------------------------------------------
// Address: 0x10014D80
// Name: __CreateCFileSystem_StdioIBaseFileSystem_interface
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IBaseFileSystem *__cdecl _CreateCFileSystem_StdioIBaseFileSystem_interface()
{
  return &g_FileSystem_Stdio.IBaseFileSystem;
}

//------------------------------------------------------------------------------
// Address: 0x10014D90
// Name: __CreateCAsyncFileSystemIAsyncFileSystem_interface
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CAsyncFileSystem *__cdecl _CreateCAsyncFileSystemIAsyncFileSystem_interface()
{
  return &g_FileSystem_Async;
}

// ============================================================
// Overlay from dedicated (Missing functions)
// ============================================================
namespace dedicated {

//------------------------------------------------------------------------------
// Address: 0x100055D0
// Name: public: virtual int CFileSystem_Stdio::WaitForResources(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __stdcall CFileSystem_Stdio::WaitForResources(unsigned int CtrlType)
{
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10018860
// Name: void __near * MemAlloc_AllocAlignedUnattributed(unsigned int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void *__cdecl MemAlloc_AllocAlignedUnattributed(unsigned int size, unsigned int align)
{
  unsigned int v2; // eax
  void *result; // eax
  unsigned int v4; // esi

  v2 = align;
  if ( ((align - 1) & align) != 0 )
    return nullptr;
  if ( align <= 4 )
    v2 = 4;
  v4 = v2 - 1;
  result = _g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: size + v2 - 1 + 4);
  if ( result != nullptr )
  {
    *(_DWORD *)((~v4 & ((unsigned int)result + v4 + 4)) - 4) = result;
    return (void *)(~v4 & ((unsigned int)result + v4 + 4));
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100188B0
// Name: public: struct TSLNodeBase_t __near * CTSListBase::Push(struct TSLNodeBase_t __near *)
// Source: json
//------------------------------------------------------------------------------
TSLNodeBase_t *__thiscall CTSListBase::Push(CTSListBase *this, TSLNodeBase_t *pNode)
{
  TSLNodeBase_t *Next; // edi
  int DepthAndSequence; // [esp-4h] [ebp-10h]
  int v6; // [esp-4h] [ebp-10h]

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
      v6 = this->m_Head.value32.DepthAndSequence;
      pNode->Next = this->m_Head.value.Next;
    }
    while ( (unsigned __int8)_ThreadInterlockedAssignIf64(a1: this, a2: pNode, a3: v6 + 65537, a4: Next, a5: v6) == 0 );
  }
  return Next;
}

//------------------------------------------------------------------------------
// Address: 0x10018910
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
// Address: 0x10018950
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
// Address: 0x10018990
// Name: __heapmin
// Source: rtti_class
//------------------------------------------------------------------------------
int __cdecl _heapmin()
{
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100189D0
// Name: public: virtual bool CWin32ReadOnlyFile::FS_setmode(enum FileMode_t)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CWin32ReadOnlyFile::FS_setmode(CWin32ReadOnlyFile *this, FileMode_t mode)
{
  _Error(a1: "Can't set mode, open a second file in right mode\n");
  return false;
}

//------------------------------------------------------------------------------
// Address: 0x100189F0
// Name: public: virtual int CWin32ReadOnlyFile::FS_GetSectorSize(void)
// Source: json
//------------------------------------------------------------------------------
vgui::DragDrop_t *__thiscall CWin32ReadOnlyFile::FS_GetSectorSize(vgui::Panel *this)
{
  return this->m_pDragDrop;
}

//------------------------------------------------------------------------------
// Address: 0x10018A00
// Name: class CBaseFileSystem __near * BaseFileSystem_Stdio(void)
// Source: json
//------------------------------------------------------------------------------
CFileSystem_Stdio *__cdecl BaseFileSystem_Stdio()
{
  return &g_FileSystem_Stdio;
}

//------------------------------------------------------------------------------
// Address: 0x10018A20
// Name: public: virtual void __near * CFileSystem_Stdio::QueryInterface(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CFileSystem_Stdio *__thiscall CFileSystem_Stdio::QueryInterface(CFileSystem_Stdio *this, const char *pInterfaceName)
{
  int v3; // eax

  v3 = _V_strlen(str: "VFileSystem017");
  if ( V_strncmp(s1: pInterfaceName, s2: "VFileSystem017", count: v3 + 1) != 0 )
    return (CFileSystem_Stdio *)CBaseFileSystem::QueryInterface(this, pInterfaceName);
  else
    return this;
}

//------------------------------------------------------------------------------
// Address: 0x10018A60
// Name: public: virtual bool CFileSystem_Stdio::GetOptimalIOConstraints(void __near *,unsigned int __near *,unsigned int __near *,unsigned int __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CFileSystem_Stdio::GetOptimalIOConstraints(
        CFileSystem_Stdio *this,
        CFileHandle *hFile,
        unsigned int *pOffsetAlign,
        unsigned int *pSizeAlign,
        unsigned int *pBufferAlign)
{
  const char *CommandLine; // eax
  unsigned int SectorSize; // edi
  CPackFileHandle *m_pPackFileHandle; // esi

  if ( hFile == nullptr )
    goto LABEL_12;
  if ( hFile->m_VPKHandle.m_nFileNumber != -1 )
    return false;
  if ( (_S1_0 & 1) != 0 )
  {
    if ( byte_100F6058 == 0 )
      goto LABEL_12;
LABEL_9:
    SectorSize = CFileHandle::GetSectorSize(this: hFile);
    if ( SectorSize != 0 )
    {
      m_pPackFileHandle = hFile->m_pPackFileHandle;
      if ( m_pPackFileHandle == nullptr
        || (m_pPackFileHandle->m_nBase
          + m_pPackFileHandle->m_pOwner->GetPackFileBaseOffset(this: m_pPackFileHandle->m_pOwner))
         % SectorSize == 0 )
      {
        goto LABEL_13;
      }
    }
    goto LABEL_12;
  }
  _S1_0 |= 1u;
  CommandLine = (const char *)_Plat_GetCommandLine(a1: this);
  if ( V_stristr(pStr: CommandLine, pSearch: "-unbuffered_io") != nullptr )
  {
    byte_100F6058 = 1;
    goto LABEL_9;
  }
  byte_100F6058 = 0;
LABEL_12:
  SectorSize = 1;
LABEL_13:
  if ( pOffsetAlign != nullptr )
    *pOffsetAlign = SectorSize;
  if ( pSizeAlign != nullptr )
    *pSizeAlign = SectorSize;
  if ( pBufferAlign != nullptr )
    *pBufferAlign = SectorSize;
  return SectorSize > 1;
}

//------------------------------------------------------------------------------
// Address: 0x10018B20
// Name: public: virtual void CFileSystem_Stdio::FreeOptimalReadBuffer(void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFileSystem_Stdio::FreeOptimalReadBuffer(CFileSystem_Stdio *this, unsigned int p)
{
  const char *CommandLine; // eax

  if ( (_S1_0 & 1) != 0 )
  {
    if ( byte_100F6058 == 0 )
      goto LABEL_9;
  }
  else
  {
    _S1_0 |= 1u;
    CommandLine = (const char *)_Plat_GetCommandLine(a1: this);
    if ( V_stristr(pStr: CommandLine, pSearch: "-unbuffered_io") == nullptr )
    {
      byte_100F6058 = 0;
LABEL_9:
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)p);
      return;
    }
    byte_100F6058 = 1;
  }
  if ( p != 0 )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: *(void **)((p & 0xFFFFFFFC) - 4));
}

//------------------------------------------------------------------------------
// Address: 0x10018BA0
// Name: protected: virtual void CFileSystem_Stdio::FS_setbufsize(struct _iobuf __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFileSystem_Stdio::FS_setbufsize(CFileSystem_Stdio *this, _iobuf *fp, unsigned int nBytes)
{
  (*((void (__thiscall **)(_iobuf *, unsigned int))fp->_ptr + 1))(a1: fp, a2: nBytes);
}

//------------------------------------------------------------------------------
// Address: 0x10018BC0
// Name: protected: virtual void CFileSystem_Stdio::FS_fclose(struct _iobuf __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFileSystem_Stdio::FS_fclose(CFileSystem_Stdio *this, _iobuf *fp)
{
  (*((void (__thiscall **)(_iobuf *))fp->_ptr + 2))(a1: fp);
  (*(void (__thiscall **)(_iobuf *, int))fp->_ptr)(a1: fp, a2: 1);
}

//------------------------------------------------------------------------------
// Address: 0x10018BE0
// Name: protected: virtual void CFileSystem_Stdio::FS_fseek(struct _iobuf __near *,__int64,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFileSystem_Stdio::FS_fseek(CFileSystem_Stdio *this, _iobuf *fp, __int64 pos, int seekType)
{
  (*((void (__thiscall **)(_iobuf *, _DWORD, _DWORD, int))fp->_ptr + 3))(
    a1: fp,
    a2: pos,
    a3: HIDWORD(pos),
    a4: seekType);
}

//------------------------------------------------------------------------------
// Address: 0x10018C00
// Name: protected: virtual long CFileSystem_Stdio::FS_ftell(struct _iobuf __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CFileSystem_Stdio::FS_ftell(CFileSystem_Stdio *this, _iobuf *fp)
{
  return (*((int (__thiscall **)(_iobuf *))fp->_ptr + 4))(a1: fp);
}

//------------------------------------------------------------------------------
// Address: 0x10018C20
// Name: protected: virtual int CFileSystem_Stdio::FS_feof(struct _iobuf __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CFileSystem_Stdio::FS_feof(CFileSystem_Stdio *this, _iobuf *fp)
{
  return (*((int (__thiscall **)(_iobuf *))fp->_ptr + 5))(a1: fp);
}

//------------------------------------------------------------------------------
// Address: 0x10018C40
// Name: protected: virtual unsigned int CFileSystem_Stdio::FS_fread(void __near *,unsigned int,unsigned int,struct _iobuf __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CFileSystem_Stdio::FS_fread(
        CFileSystem_Stdio *this,
        void *dest,
        unsigned int destSize,
        unsigned int size,
        _iobuf *fp)
{
  int v6; // edi

  v6 = (*((int (__thiscall **)(_iobuf *, void *, unsigned int, unsigned int))fp->_ptr + 6))(
         a1: fp,
         a2: dest,
         a3: destSize,
         a4: size);
  CBaseFileSystem::Trace_FRead(this, size: v6, fp);
  return v6;
}

//------------------------------------------------------------------------------
// Address: 0x10018C80
// Name: protected: virtual unsigned int CFileSystem_Stdio::FS_fwrite(void const __near *,unsigned int,struct _iobuf __near *)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CFileSystem_Stdio::FS_fwrite(
        CFileSystem_Stdio *this,
        const void *src,
        unsigned int size,
        _iobuf *fp)
{
  return (*((unsigned int (__thiscall **)(_iobuf *, const void *, unsigned int))fp->_ptr + 7))(
           a1: fp,
           a2: src,
           a3: size);
}

//------------------------------------------------------------------------------
// Address: 0x10018CA0
// Name: protected: virtual bool CFileSystem_Stdio::FS_setmode(struct _iobuf __near *,enum FileMode_t)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CFileSystem_Stdio::FS_setmode(CFileSystem_Stdio *this, _iobuf *fp, FileMode_t mode)
{
  return (*((bool (__thiscall **)(_iobuf *, FileMode_t))fp->_ptr + 8))(a1: fp, a2: mode);
}

//------------------------------------------------------------------------------
// Address: 0x10018CC0
// Name: protected: virtual unsigned int CFileSystem_Stdio::FS_vfprintf(struct _iobuf __near *,char const __near *,char __near *)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CFileSystem_Stdio::FS_vfprintf(
        CFileSystem_Stdio *this,
        _iobuf *fp,
        const char *fmt,
        char *list)
{
  return (*((unsigned int (__thiscall **)(_iobuf *, const char *, char *))fp->_ptr + 9))(a1: fp, a2: fmt, a3: list);
}

//------------------------------------------------------------------------------
// Address: 0x10018CE0
// Name: protected: virtual int CFileSystem_Stdio::FS_ferror(struct _iobuf __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CFileSystem_Stdio::FS_ferror(CFileSystem_Stdio *this, _iobuf *fp)
{
  return (*((int (__thiscall **)(_iobuf *))fp->_ptr + 10))(a1: fp);
}

//------------------------------------------------------------------------------
// Address: 0x10018D00
// Name: protected: virtual int CFileSystem_Stdio::FS_fflush(struct _iobuf __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CFileSystem_Stdio::FS_fflush(CFileSystem_Stdio *this, _iobuf *fp)
{
  return (*((int (__thiscall **)(_iobuf *))fp->_ptr + 11))(a1: fp);
}

//------------------------------------------------------------------------------
// Address: 0x10018D20
// Name: protected: virtual char __near * CFileSystem_Stdio::FS_fgets(char __near *,int,struct _iobuf __near *)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CFileSystem_Stdio::FS_fgets(CFileSystem_Stdio *this, char *dest, int destSize, _iobuf *fp)
{
  return (*((char *(__thiscall **)(_iobuf *, char *, int))fp->_ptr + 12))(a1: fp, a2: dest, a3: destSize);
}

//------------------------------------------------------------------------------
// Address: 0x10018D40
// Name: protected: virtual int CFileSystem_Stdio::FS_chmod(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CFileSystem_Stdio::FS_chmod(CFileSystem_Stdio *this, const char *path, int pmode)
{
  if ( path != nullptr )
    return _chmod(path, mode: pmode);
  else
    return -1;
}

//------------------------------------------------------------------------------
// Address: 0x10018D70
// Name: protected: virtual int CFileSystem_Stdio::FS_stat(char const __near *,struct _stat64i32 __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CFileSystem_Stdio::FS_stat(CFileSystem_Stdio *this, const char *path, _stat64i32 *buf)
{
  if ( path != nullptr )
    return _stat64i32(name: path, buf);
  else
    return -1;
}

//------------------------------------------------------------------------------
// Address: 0x10018DA0
// Name: protected: virtual void __near * CFileSystem_Stdio::FS_FindFirstFile(char const __near *,struct _WIN32_FIND_DATAA __near *)
// Source: json
//------------------------------------------------------------------------------
HANDLE __thiscall CFileSystem_Stdio::FS_FindFirstFile(
        CFileSystem_Stdio *this,
        const char *findname,
        _WIN32_FIND_DATAA *dat)
{
  return FindFirstFileA(lpFileName: findname, lpFindFileData: dat);
}

//------------------------------------------------------------------------------
// Address: 0x10018DB0
// Name: protected: virtual bool CFileSystem_Stdio::FS_FindNextFile(void __near *,struct _WIN32_FIND_DATAA __near *)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CFileSystem_Stdio::FS_FindNextFile(CFileSystem_Stdio *this, void *handle, _WIN32_FIND_DATAA *dat)
{
  return FindNextFileA(hFindFile: handle, lpFindFileData: dat);
}

//------------------------------------------------------------------------------
// Address: 0x10018DD0
// Name: protected: virtual bool CFileSystem_Stdio::FS_FindClose(void __near *)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CFileSystem_Stdio::FS_FindClose(CFileSystem_Stdio *this, void *handle)
{
  return FindClose(hFindFile: handle);
}

//------------------------------------------------------------------------------
// Address: 0x10018DF0
// Name: protected: virtual int CFileSystem_Stdio::FS_GetSectorSize(struct _iobuf __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CFileSystem_Stdio::FS_GetSectorSize(CFileSystem_Stdio *this, _iobuf *fp)
{
  return (*((int (__thiscall **)(_iobuf *))fp->_ptr + 13))(a1: fp);
}

//------------------------------------------------------------------------------
// Address: 0x10018E10
// Name: public: virtual bool CFileSystem_Stdio::IsFileImmediatelyAvailable(char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CFileSystem_Stdio::IsFileImmediatelyAvailable(
        CBaseAppSystem<IDedicatedExports> *this,
        void *(__cdecl *factory)(const char *, int *))
{
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10018E20
// Name: public: virtual bool CFileSystem_Stdio::GetWaitForResourcesProgress(int,float __near *,bool __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CFileSystem_Stdio::GetWaitForResourcesProgress(
        CFileSystem_Stdio *this,
        int handle,
        float *progress,
        bool *complete)
{
  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "GetWaitForResourcesProgress (stdio)",
    a3: 0,
    a4: "FileSystem",
    a5: false,
    a6: 4);
  *progress = 0.0;
  *complete = true;
  CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10018E70
// Name: public: virtual int CFileSystem_Stdio::HintResourceNeed(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CFileSystem_Stdio::HintResourceNeed(
        CFileSystem_Stdio *this,
        const char *hintlist,
        const char *forgetEverything)
{
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10018E80
// Name: public: virtual void CStdioFile::FS_setbufsize(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CStdioFile::FS_setbufsize(CStdioFile *this, unsigned int nBytes)
{
  if ( nBytes != 0 )
  {
    setvbuf(str: this->m_pFile, buffer: nullptr, type: 0, size: 0x8000u);
  }
  else
  {
    setvbuf(str: this->m_pFile, buffer: nullptr, type: 4, size: 0);
    this->m_pFile->_bufsiz = 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10018ED0
// Name: public: virtual void CStdioFile::FS_fclose(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CStdioFile::FS_fclose(CStdioFile *this)
{
  fclose(stream: this->m_pFile);
}

//------------------------------------------------------------------------------
// Address: 0x10018EE0
// Name: public: virtual void CStdioFile::FS_fseek(__int64,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CStdioFile::FS_fseek(CStdioFile *this, __int64 pos, int seekType)
{
  __int64 i; // rdi

  for ( i = pos; i > 0x7FFFFFFF; seekType = 1 )
  {
    fseek(stream: this->m_pFile, offset: 0x7FFFFFFF, whence: seekType);
    i -= 0x7FFFFFFF;
  }
  for ( ; i < (__int64)0xFFFFFFFF80000000uLL; seekType = 1 )
  {
    fseek(stream: this->m_pFile, offset: 0x80000000, whence: seekType);
    i += 0x80000000LL;
  }
  fseek(stream: this->m_pFile, offset: i, whence: seekType);
}

//------------------------------------------------------------------------------
// Address: 0x10018F90
// Name: public: virtual long CStdioFile::FS_ftell(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CStdioFile::FS_ftell(CStdioFile *this)
{
  return ftell(stream: this->m_pFile);
}

//------------------------------------------------------------------------------
// Address: 0x10018FA0
// Name: public: virtual int CStdioFile::FS_feof(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CStdioFile::FS_feof(CStdioFile *this)
{
  return feof(stream: this->m_pFile);
}

//------------------------------------------------------------------------------
// Address: 0x10018FB0
// Name: public: virtual unsigned int CStdioFile::FS_fread(void __near *,unsigned int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CStdioFile::FS_fread(CStdioFile *this, void *dest, unsigned int destSize, unsigned int size)
{
  return fread(buffer: dest, elementSize: 1u, count: size, stream: this->m_pFile);
}

//------------------------------------------------------------------------------
// Address: 0x10018FD0
// Name: public: virtual unsigned int CStdioFile::FS_fwrite(void const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CStdioFile::FS_fwrite(CStdioFile *this, char *src, unsigned int size)
{
  unsigned int v3; // edi
  char *v4; // ebx
  unsigned int v5; // esi
  unsigned int total; // [esp+10h] [ebp+8h]

  v3 = size;
  if ( size <= 0x40000 )
    return fwrite(buffer: src, size: 1u, count: size, stream: this->m_pFile);
  v4 = src;
  total = 0;
  do
  {
    v5 = v3;
    if ( v3 >= 0x40000 )
      v5 = 0x40000;
    total += fwrite(buffer: v4, size: 1u, count: v5, stream: this->m_pFile);
    v4 += v5;
    v3 -= v5;
  }
  while ( v3 != 0 );
  return total;
}

//------------------------------------------------------------------------------
// Address: 0x10019050
// Name: public: virtual bool CStdioFile::FS_setmode(enum FileMode_t)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CStdioFile::FS_setmode(CStdioFile *this, FileMode_t mode)
{
  int v2; // eax

  v2 = _fileno(stream: this->m_pFile);
  return _setmode(fh: v2, mode: mode != FM_BINARY ? 0x4000 : 0x8000) != -1;
}

//------------------------------------------------------------------------------
// Address: 0x10019090
// Name: public: virtual unsigned int CStdioFile::FS_vfprintf(char const __near *,char __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CStdioFile::FS_vfprintf(CStdioFile *this, const char *fmt, char *list)
{
  return vfprintf(str: this->m_pFile, format: fmt, ap: list);
}

//------------------------------------------------------------------------------
// Address: 0x100190B0
// Name: public: virtual int CStdioFile::FS_ferror(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CStdioFile::FS_ferror(CStdioFile *this)
{
  return ferror(stream: this->m_pFile);
}

//------------------------------------------------------------------------------
// Address: 0x100190C0
// Name: public: virtual int CStdioFile::FS_fflush(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CStdioFile::FS_fflush(CStdioFile *this)
{
  return fflush(stream: this->m_pFile);
}

//------------------------------------------------------------------------------
// Address: 0x100190D0
// Name: public: virtual char __near * CStdioFile::FS_fgets(char __near *,int)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CStdioFile::FS_fgets(CStdioFile *this, char *dest, int destSize)
{
  return fgets(string: dest, count: destSize, str: this->m_pFile);
}

//------------------------------------------------------------------------------
// Address: 0x100190F0
// Name: int GetSectorSize(char const __near *)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl GetSectorSize(unsigned int pszFilename)
{
  char *v1; // edi
  char v2; // cl
  char v3; // al
  char v4; // bl
  unsigned int v5; // esi
  char volume; // al
  const char *result; // eax
  char v8; // dl
  int v9; // [esp-Ch] [ebp-218h]
  char szAbsoluteFilename[512]; // [esp+4h] [ebp-208h] BYREF
  unsigned int ignored; // [esp+204h] [ebp-8h] BYREF
  char root[4]; // [esp+208h] [ebp-4h] BYREF

  v1 = (char *)pszFilename;
  v2 = *(_BYTE *)pszFilename;
  if ( *(_BYTE *)pszFilename == 0 )
    return nullptr;
  v3 = *(_BYTE *)(pszFilename + 1);
  if ( v3 == 0 || v2 == 92 && v3 == 92 )
    return nullptr;
  if ( v2 == 47 && v3 == 47 )
    return nullptr;
  if ( v3 != 58 )
  {
    V_MakeAbsolutePath(pOut: szAbsoluteFilename, outLen: 512, pPath: (const char *)pszFilename, pStartingDir: nullptr);
    v1 = szAbsoluteFilename;
  }
  v9 = *v1;
  pszFilename = 1;
  v4 = tolower(c: v9);
  v5 = 0;
  while ( 1 )
  {
    volume = cachedSizes[v5].volume;
    if ( volume == 0 )
    {
LABEL_13:
      result = (const char *)pszFilename;
      goto LABEL_14;
    }
    if ( volume == v4 )
      break;
    if ( ++v5 >= 4 )
      goto LABEL_13;
  }
  result = (const char *)dword_100F6064[2 * v5];
  pszFilename = (unsigned int)result;
LABEL_14:
  if ( result == (const char *)1 )
  {
    v8 = *v1;
    strcpy(root, "X:\\");
    root[0] = v8;
    result = (const char *)GetDiskFreeSpaceA(
                             lpRootPathName: root,
                             lpSectorsPerCluster: &ignored,
                             lpBytesPerSector: &pszFilename,
                             lpNumberOfFreeClusters: &ignored,
                             lpTotalNumberOfClusters: &ignored);
    if ( result != nullptr )
      result = (const char *)pszFilename;
    if ( v5 < 4 )
    {
      cachedSizes[v5].volume = v4;
      dword_100F6064[2 * v5] = (int)result;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100191F0
// Name: public: virtual void CWin32ReadOnlyFile::FS_fclose(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWin32ReadOnlyFile::FS_fclose(CWin32ReadOnlyFile *this)
{
  void *m_hFileBuffered; // esi

  if ( this->m_hFileUnbuffered != (void *)-1 )
    CloseHandle(hObject: this->m_hFileUnbuffered);
  m_hFileBuffered = this->m_hFileBuffered;
  if ( m_hFileBuffered != (void *)-1 )
    CloseHandle(hObject: m_hFileBuffered);
}

//------------------------------------------------------------------------------
// Address: 0x10019220
// Name: public: virtual void CWin32ReadOnlyFile::FS_fseek(__int64,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWin32ReadOnlyFile::FS_fseek(CWin32ReadOnlyFile *this, __int64 pos, int seekType)
{
  bool v3; // cf

  if ( seekType != 0 )
  {
    if ( seekType == 1 )
    {
      v3 = __CFADD__((_DWORD)pos, this->m_ReadPos);
      LODWORD(this->m_ReadPos) += pos;
      HIDWORD(this->m_ReadPos) += HIDWORD(pos) + v3;
    }
    else if ( seekType == 2 )
    {
      this->m_ReadPos = this->m_Size - pos;
    }
  }
  else
  {
    this->m_ReadPos = pos;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10019270
// Name: public: virtual long CWin32ReadOnlyFile::FS_ftell(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CWin32ReadOnlyFile::FS_ftell(CIoStats *this)
{
  return this->m_nTimeInFileSeek.m_value;
}

//------------------------------------------------------------------------------
// Address: 0x10019280
// Name: public: virtual int CWin32ReadOnlyFile::FS_feof(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CWin32ReadOnlyFile::FS_feof(CWin32ReadOnlyFile *this)
{
  return this->m_ReadPos >= this->m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x100192A0
// Name: public: virtual char __near * CWin32ReadOnlyFile::FS_fgets(char __near *,int)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CWin32ReadOnlyFile::FS_fgets(CWin32ReadOnlyFile *this, char *dest, unsigned int destSize)
{
  char *result; // eax
  int v5; // esi
  int v6; // eax
  int v7; // eax
  char *v8; // eax
  int nStartPos; // [esp+4h] [ebp-4h]
  int destSizea; // [esp+14h] [ebp+Ch]

  if ( this->FS_feof(this) != 0 )
    return nullptr;
  nStartPos = this->m_ReadPos;
  result = (char *)this->FS_fread(this, a2: dest, a3: destSize, a4: destSize);
  v5 = (int)result;
  if ( result != nullptr )
  {
    v6 = destSize - 1;
    destSizea = v6;
    if ( v5 < v6 )
      v6 = v5;
    dest[v6] = 0;
    strchr(string: (unsigned __int8 *)dest, chr: 0xAu);
    if ( v7 != 0 )
    {
      v8 = (char *)(v7 + 1);
      *v8 = 0;
    }
    else
    {
      if ( v5 >= destSizea )
        v5 = destSizea;
      v8 = &dest[v5];
    }
    this->m_ReadPos = v8 - dest + nStartPos + 1;
    return dest;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10019340
// Name: public: virtual void __near * CFileSystem_Stdio::AllocOptimalReadBuffer(void __near *,unsigned int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void *__thiscall CFileSystem_Stdio::AllocOptimalReadBuffer(
        CFileSystem_Stdio *this,
        CFileHandle *hFile,
        unsigned int nSize,
        unsigned int nOffset)
{
  const char *CommandLine; // eax
  unsigned int v5; // ebx
  unsigned int SectorSize; // esi
  CPackFileHandle *m_pPackFileHandle; // edi

  if ( (_S1_0 & 1) != 0 )
  {
    if ( byte_100F6058 == 0 )
      return _g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: nSize);
  }
  else
  {
    _S1_0 |= 1u;
    CommandLine = (const char *)_Plat_GetCommandLine(a1: this);
    if ( V_stristr(pStr: CommandLine, pSearch: "-unbuffered_io") == nullptr )
    {
      byte_100F6058 = 0;
      return _g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: nSize);
    }
    byte_100F6058 = 1;
  }
  if ( hFile != nullptr )
  {
    v5 = nSize;
    SectorSize = CFileHandle::GetSectorSize(this: hFile);
    if ( nSize == 0 )
      v5 = CFileHandle::Size(this: hFile);
    m_pPackFileHandle = hFile->m_pPackFileHandle;
    if ( m_pPackFileHandle != nullptr )
      nOffset += LODWORD(m_pPackFileHandle->m_nBase)
               + m_pPackFileHandle->m_pOwner->GetPackFileBaseOffset(this: m_pPackFileHandle->m_pOwner);
  }
  else
  {
    v5 = nSize;
    SectorSize = 4;
  }
  if ( nOffset % SectorSize != 0 )
    return MemAlloc_AllocAlignedUnattributed(size: v5, align: 4u);
  else
    return MemAlloc_AllocAlignedUnattributed(size: ~(SectorSize - 1) & (SectorSize + v5 - 1), align: SectorSize);
}

//------------------------------------------------------------------------------
// Address: 0x10019430
// Name: public: static class CStdioFile __near * CStdioFile::FS_fopen(char const __near *,char const __near *,__int64 __near *)
// Source: json
//------------------------------------------------------------------------------
CStdioFile *__cdecl CStdioFile::FS_fopen(const char *filename, char *options, __int64 *size)
{
  _iobuf *v3; // esi
  bool v4; // bl
  int v5; // eax
  int v6; // eax
  CStdioFile *result; // eax
  _stat64i32 buf; // [esp+Ch] [ebp-30h] BYREF

  v3 = fopen(file: filename, mode: options);
  if ( v3 == nullptr )
    return nullptr;
  if ( size != nullptr && _stat64i32(name: filename, &buf) == 0 )
    *size = buf.st_size;
  v4 = false;
  strchr(string: (unsigned __int8 *)options, chr: 0x77u);
  if ( v5 != 0 || (strchr(string: (unsigned __int8 *)options, chr: 0x61u), v6 != 0) )
    v4 = true;
  result = (CStdioFile *)operator new(nSize: 0xCu);
  if ( result == nullptr )
    return nullptr;
  result->m_pFile = v3;
  result->m_bWriteable = v4;
  result->__vftable = (CStdioFile_vtbl *)&CStdioFile::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100194C0
// Name: public: static class CWin32ReadOnlyFile __near * CWin32ReadOnlyFile::FS_fopen(char const __near *,char const __near *,__int64 __near *)
// Source: json
//------------------------------------------------------------------------------
CWin32ReadOnlyFile *__cdecl CWin32ReadOnlyFile::FS_fopen(const char *filename, const char *options, __int64 *size)
{
  int v3; // ecx
  const char *CommandLine; // eax
  char v5; // cl
  int m_nValue; // eax
  bool v7; // dl
  int v8; // edi
  int v9; // eax
  HANDLE FileA; // eax
  int v11; // esi
  DWORD v12; // eax
  int v13; // esi
  CWin32ReadOnlyFile *result; // eax
  int v15; // ecx
  int v16; // edx
  _LARGE_INTEGER v17; // [esp+0h] [ebp-20h] BYREF
  _LARGE_INTEGER FileSize; // [esp+8h] [ebp-18h] BYREF
  __int64 fileSize; // [esp+10h] [ebp-10h]
  int sectorSize; // [esp+18h] [ebp-8h]
  bool bOverlapped; // [esp+1Fh] [ebp-1h]

  sectorSize = 0;
  if ( (_S1_0 & 1) != 0 )
  {
    if ( byte_100F6058 == 0 )
      goto LABEL_4;
  }
  else
  {
    _S1_0 |= 1u;
    CommandLine = (const char *)_Plat_GetCommandLine(a1: v3);
    if ( V_stristr(pStr: CommandLine, pSearch: "-unbuffered_io") == nullptr )
    {
      byte_100F6058 = 0;
LABEL_4:
      v5 = 0;
      goto LABEL_5;
    }
    byte_100F6058 = 1;
  }
  if ( filesystem_unbuffered_io.m_pParent == nullptr )
    goto LABEL_4;
  if ( filesystem_unbuffered_io.m_pParent->m_Value.m_nValue == 0 )
    goto LABEL_4;
  sectorSize = (int)GetSectorSize(pszFilename: (unsigned int)filename);
  if ( sectorSize == 0 )
    goto LABEL_4;
  v5 = 1;
LABEL_5:
  if ( filesystem_use_overlapped_io.m_pParent != nullptr )
    m_nValue = filesystem_use_overlapped_io.m_pParent->m_Value.m_nValue;
  else
    m_nValue = 0;
  v7 = m_nValue != 0;
  v8 = -1;
  bOverlapped = m_nValue != 0;
  fileSize = 0;
  if ( v5 != 0 )
  {
    v9 = 128;
    if ( v7 )
      v9 = 1073741952;
    FileA = CreateFileA(
              lpFileName: filename,
              dwDesiredAccess: 0x80000000,
              dwShareMode: 1u,
              lpSecurityAttributes: nullptr,
              dwCreationDisposition: 3u,
              dwFlagsAndAttributes: v9 | 0x20000000,
              hTemplateFile: nullptr);
    v11 = (int)FileA;
    if ( FileA != (HANDLE)-1 )
    {
      if ( !GetFileSizeEx(hFile: FileA, lpFileSize: &FileSize) )
      {
        CloseHandle(hObject: (HANDLE)v11);
        v11 = -1;
      }
      fileSize = FileSize.QuadPart;
    }
    v8 = v11;
    if ( v11 == -1 )
      return nullptr;
    v7 = bOverlapped;
  }
  v12 = 128;
  if ( v7 )
    v12 = 1073741952;
  v13 = (int)CreateFileA(
               lpFileName: filename,
               dwDesiredAccess: 0x80000000,
               dwShareMode: 1u,
               lpSecurityAttributes: nullptr,
               dwCreationDisposition: 3u,
               dwFlagsAndAttributes: v12,
               hTemplateFile: nullptr);
  if ( v13 != -1 )
  {
    if ( fileSize == 0 )
    {
      if ( !GetFileSizeEx(hFile: (HANDLE)v13, lpFileSize: &v17) )
      {
        CloseHandle(hObject: (HANDLE)v13);
        v13 = -1;
      }
      fileSize = v17.QuadPart;
    }
    if ( v13 != -1 )
    {
      if ( size != nullptr )
        *size = fileSize;
      result = (CWin32ReadOnlyFile *)operator new(nSize: 0x30u);
      if ( result == nullptr )
        return nullptr;
      v15 = sectorSize;
      if ( sectorSize == 0 )
        v15 = 1;
      LODWORD(result->m_Size) = fileSize;
      v16 = HIDWORD(fileSize);
      LODWORD(result->m_ReadPos) = 0;
      HIDWORD(result->m_ReadPos) = 0;
      result->m_hFileUnbuffered = (void *)v8;
      result->m_hFileBuffered = (void *)v13;
      result->__vftable = (CWin32ReadOnlyFile_vtbl *)&CWin32ReadOnlyFile::`vftable';
      HIDWORD(result->m_Size) = v16;
      result->m_Mutex.m_ownerID = 0;
      result->m_Mutex.m_depth = 0;
      result->m_SectorSize = v15;
      result->m_bOverlapped = bOverlapped;
      return result;
    }
  }
  if ( v8 != -1 )
    CloseHandle(hObject: (HANDLE)v8);
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x100196A0
// Name: protected: virtual struct _iobuf __near * CFileSystem_Stdio::FS_fopen(char const __near *,char const __near *,unsigned int,__int64 __near *,class CFileLoadInfo __near *)
// Source: json
//------------------------------------------------------------------------------
CStdioFile *__thiscall CFileSystem_Stdio::FS_fopen(
        CFileSystem_Stdio *this,
        const char *filename,
        char *options,
        unsigned int flags,
        __int64 *size,
        CFileLoadInfo *pInfo)
{
  if ( pInfo != nullptr )
    pInfo->m_bLoadedFromSteamCache = false;
  if ( *options == 114
    && options[1] == 98
    && options[2] == 0
    && filesystem_native.m_pParent != nullptr
    && filesystem_native.m_pParent->m_Value.m_nValue != 0 )
  {
    return (CStdioFile *)CWin32ReadOnlyFile::FS_fopen(filename, options, size);
  }
  else
  {
    return CStdioFile::FS_fopen(filename, options, size);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10019700
// Name: public: virtual unsigned int CWin32ReadOnlyFile::FS_fread(void __near *,unsigned int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CWin32ReadOnlyFile::FS_fread(
        CWin32ReadOnlyFile *this,
        unsigned __int8 *dest,
        unsigned int destSize,
        unsigned int size)
{
  CWin32ReadOnlyFile *v4; // esi
  void *m_hFileUnbuffered; // edi
  void *m_hFileBuffered; // edx
  __int64 v7; // rcx
  unsigned int m_SectorSize; // esi
  unsigned int v9; // ecx
  bool v10; // zf
  TSLNodeBase_t *v11; // eax
  char *v12; // eax
  TSLNodeBase_t *v13; // edi
  int m_nValue; // eax
  unsigned int v15; // edi
  DWORD v16; // esi
  HANDLE v17; // edi
  BOOL v18; // eax
  char v19; // bl
  DWORD LastError; // eax
  int v21; // eax
  unsigned __int8 *v23; // [esp-14h] [ebp-805Ch]
  _BYTE v24[32769]; // [esp+7h] [ebp-8041h] BYREF
  _OVERLAPPED Overlapped; // [esp+8008h] [ebp-40h] BYREF
  __int64 v26; // [esp+801Ch] [ebp-2Ch]
  unsigned int NumberOfBytesRead; // [esp+8024h] [ebp-24h] BYREF
  CThreadEvent *v28; // [esp+8028h] [ebp-20h]
  __int64 v29; // [esp+802Ch] [ebp-1Ch]
  unsigned __int8 *v30; // [esp+8034h] [ebp-14h]
  unsigned int v31; // [esp+8038h] [ebp-10h]
  HANDLE hFile; // [esp+803Ch] [ebp-Ch]
  signed int v33; // [esp+8040h] [ebp-8h]
  CWin32ReadOnlyFile *v34; // [esp+8044h] [ebp-4h]
  unsigned int v35; // [esp+8054h] [ebp+Ch]

  v4 = this;
  v34 = this;
  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "CWin32ReadOnlyFile::FS_fread",
    a3: 0,
    a4: "FileSystem",
    a5: false,
    a6: 4);
  if ( size == 0 || (m_hFileUnbuffered = v4->m_hFileUnbuffered) == (void *)-1 && v4->m_hFileBuffered == (void *)-1 )
  {
    CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
    return 0;
  }
  v28 = nullptr;
  if ( destSize == -1 )
    destSize = size;
  m_hFileBuffered = v4->m_hFileBuffered;
  v33 = size;
  HIDWORD(v7) = HIDWORD(v4->m_ReadPos);
  v30 = dest;
  LODWORD(v7) = v4->m_ReadPos;
  hFile = m_hFileBuffered;
  v26 = v7;
  if ( m_hFileUnbuffered != (void *)-1 )
  {
    m_SectorSize = v4->m_SectorSize;
    if ( (unsigned int)dest % m_SectorSize == 0 && destSize % m_SectorSize == 0 && v7 % (int)m_SectorSize == 0 )
    {
      v33 = ~(m_SectorSize - 1) & (m_SectorSize + size - 1);
LABEL_13:
      hFile = m_hFileUnbuffered;
      goto LABEL_14;
    }
    v9 = ~(m_SectorSize - 1)
       & (m_SectorSize + LODWORD(v34->m_ReadPos) - (~(m_SectorSize - 1) & v34->m_ReadPos) + size - 1);
    if ( v9 <= 0x8000 - m_SectorSize )
    {
      v26 = ~(m_SectorSize - 1) & v34->m_ReadPos;
      v33 = v9;
      v30 = (unsigned __int8 *)(~(m_SectorSize - 1) & (unsigned int)&v24[m_SectorSize]);
      goto LABEL_13;
    }
LABEL_14:
    v4 = v34;
  }
  v10 = !v4->m_bOverlapped;
  memset(&Overlapped, 0, sizeof(Overlapped));
  if ( !v10 )
  {
    v11 = CTSListBase::Pop(this: &g_ThreadIOEvents.m_Events);
    if ( v11 == nullptr )
    {
      v12 = (char *)operator new(nSize: 0x10u);
      v13 = (TSLNodeBase_t *)v12;
      if ( v12 != nullptr )
      {
        CThreadEvent::CThreadEvent(this: (CThreadEvent *)(v12 + 4), a2: false);
        v11 = v13;
      }
      else
      {
        v11 = nullptr;
      }
    }
    v28 = (CThreadEvent *)(&v11->Next + 1);
    Overlapped.hEvent = *((void **)&v11->Next + 1);
  }
  if ( (_S2 & 1) == 0 )
  {
    _S2 |= 1u;
    if ( filesystem_max_stdio_read.m_pParent != nullptr )
      m_nValue = filesystem_max_stdio_read.m_pParent->m_Value.m_nValue;
    else
      m_nValue = 0;
    MAX_READ = m_nValue << 20;
  }
  v15 = 0;
  v35 = 0;
  v31 = 0;
  v29 = v26;
  while ( v33 > 0 )
  {
    v16 = MAX_READ;
    if ( v33 < (int)MAX_READ )
      v16 = v33;
    *(_QWORD *)&Overlapped.Offset = v29;
    v23 = &v30[v15];
    v17 = hFile;
    NumberOfBytesRead = 0;
    v18 = ReadFile(
            hFile,
            lpBuffer: v23,
            nNumberOfBytesToRead: v16,
            lpNumberOfBytesRead: &NumberOfBytesRead,
            lpOverlapped: &Overlapped);
    v19 = v18;
    if ( !v18 )
    {
      if ( v34->m_bOverlapped == v19 || GetLastError() != 997 )
        goto LABEL_37;
      v19 = 1;
    }
    if ( GetOverlappedResult(
           hFile: v17,
           lpOverlapped: &Overlapped,
           lpNumberOfBytesTransferred: &NumberOfBytesRead,
           bWait: true) )
    {
      v35 += NumberOfBytesRead;
      v33 -= v16;
      v29 += NumberOfBytesRead;
      if ( v19 != 0 )
        goto LABEL_27;
    }
    else
    {
      v19 = 0;
    }
LABEL_37:
    LastError = GetLastError();
    if ( LastError == 1450 && (int)MAX_READ > 0x10000 )
    {
      MAX_READ = (int)MAX_READ / 2;
      DevMsg(a1: "ERROR_NO_SYSTEM_RESOURCES: Reducing max read to %d bytes\n", MAX_READ);
    }
    else
    {
      DevMsg(a1: "Unknown read error %d\n", LastError);
      if ( v19 == 0 )
      {
        v4 = v34;
        goto LABEL_50;
      }
    }
LABEL_27:
    v15 = v35;
    v4 = v34;
  }
  if ( v15 != 0 && hFile == v4->m_hFileUnbuffered && v30 != dest )
  {
    v21 = LODWORD(v4->m_ReadPos) - v26;
    v15 -= v21;
    if ( v15 != 0 )
      memcpy(dst: dest, src: &v30[v21], count: size);
  }
  v31 = v15;
  if ( v15 >= size )
    v31 = size;
LABEL_50:
  if ( v4->m_bOverlapped )
  {
    CThreadEvent::Reset(this: v28);
    CTSListBase::Push(this: &g_ThreadIOEvents.m_Events, pNode: (TSLNodeBase_t *)&v28[-1].m_bCreatedHandle);
  }
  v4->m_ReadPos += v31;
  CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
  return v31;
}

//------------------------------------------------------------------------------
// Address: 0x10019A40
// Name: public: CTSPool<class CThreadEvent>::~CTSPool<class CThreadEvent>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTSPool<CThreadEvent>::~CTSPool<CThreadEvent>(CTSPool<CThreadEvent> *this)
{
  TSLNodeBase_t *Next; // esi
  int DepthAndSequence; // eax

  while ( 1 )
  {
    Next = this->m_Head.value.Next;
    DepthAndSequence = this->m_Head.value32.DepthAndSequence;
    if ( this->m_Head.value.Next == nullptr )
      break;
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
        goto LABEL_4;
    }
    CThreadSyncObject::~CThreadSyncObject(this: (CThreadSyncObject *)(&Next->Next + 1));
    free(pMem: Next);
  }
LABEL_4:
  CTSListBase::Detach(this);
}

//------------------------------------------------------------------------------
// Address: 0x10018A10
// Name: __CreateCAsyncFileSystemIAsyncFileSystem_interface
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CAsyncFileSystem *__cdecl _CreateCAsyncFileSystemIAsyncFileSystem_interface()
{
  return &g_FileSystem_Async;
}

} // namespace dedicated
