// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/overwatch/overwatchlib/overwatch_internal.cpp
// Functions: 11
// ============================================================

#include "utils\overwatch\overwatchlib\overwatch_internal.h"

//------------------------------------------------------------------------------
// Address: 0x004023E0
// Name: public: CSharedMemoryMgr::CSharedMemoryMgr(void)
// Source: json
//------------------------------------------------------------------------------
CSharedMemoryMgr *__thiscall CSharedMemoryMgr::CSharedMemoryMgr(CSharedMemoryMgr *this)
{
  this->m_pStart = nullptr;
  this->m_pEnd = nullptr;
  this->m_nBytes = 0;
  this->m_hSharedData = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004023F0
// Name: public: bool CSharedMemoryMgr::IsValid(void)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CSharedMemoryMgr::IsValid(CSharedMemoryMgr *this)
{
  return this->m_pStart != nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x00402400
// Name: public: CSharedMemoryMgr::~CSharedMemoryMgr(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSharedMemoryMgr::~CSharedMemoryMgr(CSharedMemoryMgr *this)
{
  if ( this->m_hSharedData != nullptr )
    CloseHandle(hObject: this->m_hSharedData);
  this->m_hSharedData = nullptr;
  this->m_nBytes = 0;
  this->m_pStart = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x00402430
// Name: public: CLinearMemoryAllocator::CLinearMemoryAllocator(void)
// Source: json
//------------------------------------------------------------------------------
CLinearMemoryAllocator *__thiscall CLinearMemoryAllocator::CLinearMemoryAllocator(CLinearMemoryAllocator *this)
{
  this->m_pBase = nullptr;
  this->m_nCurOffset = 0;
  this->m_nMaxBytes = 0;
  this->m_bAutoFree = false;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00402440
// Name: public: void CLinearMemoryAllocator::Init(void __near *,unsigned int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLinearMemoryAllocator::Init(
        CLinearMemoryAllocator *this,
        unsigned __int8 *pBase,
        unsigned int nMaxBytes,
        bool bAutoFree)
{
  this->m_pBase = pBase;
  this->m_nMaxBytes = nMaxBytes;
  this->m_nCurOffset = 0;
  this->m_bAutoFree = bAutoFree;
}

//------------------------------------------------------------------------------
// Address: 0x00402460
// Name: public: char __near * CLinearMemoryAllocator::CopyString(char const __near *)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CLinearMemoryAllocator::CopyString(CLinearMemoryAllocator *this, const char *pStr)
{
  int v2; // edx
  unsigned int v3; // eax
  char *v4; // esi

  v2 = strlen(pStr) + 1;
  v3 = 4 * ((this->m_nCurOffset + 3) >> 2);
  v4 = (char *)&this->m_pBase[v3];
  this->m_nCurOffset = v2 + v3;
  V_strncpy(pDest: v4, pSrc: pStr, maxLen: v2);
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x004024B0
// Name: public: bool CSharedMemoryMgr::Create(char const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CSharedMemoryMgr::Create(CSharedMemoryMgr *this, const char *pSharedName, DWORD nBytes)
{
  HANDLE FileMappingA; // eax
  unsigned __int8 *v5; // eax

  if ( this->m_hSharedData != nullptr )
    CloseHandle(hObject: this->m_hSharedData);
  this->m_hSharedData = nullptr;
  this->m_nBytes = 0;
  this->m_pStart = nullptr;
  FileMappingA = CreateFileMappingA(
                   hFile: (HANDLE)0xFFFFFFFF,
                   lpFileMappingAttributes: nullptr,
                   flProtect: 4u,
                   dwMaximumSizeHigh: 0,
                   dwMaximumSizeLow: nBytes,
                   lpName: pSharedName);
  this->m_hSharedData = FileMappingA;
  if ( FileMappingA == nullptr )
    return 0;
  v5 = (unsigned __int8 *)MapViewOfFile(
                            hFileMappingObject: FileMappingA,
                            dwDesiredAccess: 6u,
                            dwFileOffsetHigh: 0,
                            dwFileOffsetLow: 0,
                            dwNumberOfBytesToMap: nBytes);
  this->m_pStart = v5;
  if ( v5 == nullptr )
  {
    if ( this->m_hSharedData != nullptr )
      CloseHandle(hObject: this->m_hSharedData);
    this->m_hSharedData = nullptr;
    this->m_nBytes = 0;
    this->m_pStart = nullptr;
    return 0;
  }
  this->m_nBytes = nBytes;
  this->m_pEnd = &v5[nBytes];
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00402530
// Name: public: bool CSharedMemoryMgr::Open(char const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CSharedMemoryMgr::Open(CSharedMemoryMgr *this, const char *pSharedName, SIZE_T nBytes)
{
  HANDLE v4; // eax
  unsigned __int8 *v6; // eax

  if ( this->m_hSharedData != nullptr )
    CloseHandle(hObject: this->m_hSharedData);
  this->m_hSharedData = nullptr;
  this->m_nBytes = 0;
  this->m_pStart = nullptr;
  v4 = OpenFileMappingA(dwDesiredAccess: 6u, bInheritHandle: false, lpName: pSharedName);
  this->m_hSharedData = v4;
  if ( v4 == nullptr )
    return 0;
  v6 = (unsigned __int8 *)MapViewOfFile(
                            hFileMappingObject: v4,
                            dwDesiredAccess: 6u,
                            dwFileOffsetHigh: 0,
                            dwFileOffsetLow: 0,
                            dwNumberOfBytesToMap: nBytes);
  this->m_pStart = v6;
  if ( v6 != nullptr )
  {
    this->m_nBytes = nBytes;
    this->m_pEnd = &v6[nBytes];
    return 1;
  }
  else
  {
    if ( this->m_hSharedData != nullptr )
      CloseHandle(hObject: this->m_hSharedData);
    this->m_hSharedData = nullptr;
    this->m_nBytes = 0;
    this->m_pStart = nullptr;
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004025B0
// Name: public: class CWatchedDir __near * CWatchedDir::FastFindChildDir(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CWatchedDir *__thiscall CWatchedDir::FastFindChildDir(CWatchedDir *this, const char *pShortName)
{
  int m_nOffset; // eax
  char *v3; // esi
  int v4; // eax
  const char *v5; // eax
  int v6; // eax

  m_nOffset = this->m_pFirstChildDir.m_nOffset;
  if ( this->m_pFirstChildDir.m_nOffset == 0 )
    return nullptr;
  v3 = (char *)this + m_nOffset;
  if ( (CWatchedDir *)((char *)this + m_nOffset) == nullptr )
    return nullptr;
  while ( 1 )
  {
    v4 = *((_DWORD *)v3 + 5);
    v5 = v4 != 0 ? &v3[v4 + 20] : nullptr;
    if ( _stricmp(dst: v5, src: pShortName) == 0 )
      break;
    v6 = *((_DWORD *)v3 + 1);
    if ( v6 != 0 )
    {
      v3 += v6 + 4;
      if ( v3 != nullptr )
        continue;
    }
    return nullptr;
  }
  return (CWatchedDir *)v3;
}

//------------------------------------------------------------------------------
// Address: 0x00402600
// Name: public: class CWatchedDir __near * CWatchedDir::FindChildDir(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CWatchedDir *__thiscall CWatchedDir::FindChildDir(CWatchedDir *this, char *pLongDirName)
{
  unsigned __int8 *v2; // eax
  const char *v4; // edi
  unsigned int v5; // esi
  signed int v7; // edi
  char dst[260]; // [esp+Ch] [ebp-208h] BYREF
  char pShortName[260]; // [esp+110h] [ebp-104h] BYREF

  v2 = (unsigned __int8 *)pLongDirName;
  v4 = pLongDirName;
  if ( *pLongDirName == 0 )
    return this;
  do
  {
    if ( *v4 == 47 || *v4 == 92 )
    {
      if ( v4 != (const char *)v2 )
      {
        v5 = v4 - (const char *)v2;
        if ( v4 - (const char *)v2 >= 259 )
          v5 = 259;
        memcpy((unsigned __int8 *)dst, src: v2, count: v5);
        dst[v5] = 0;
        this = CWatchedDir::FastFindChildDir(this, pShortName: dst);
      }
      if ( this == nullptr )
        return nullptr;
      v2 = (unsigned __int8 *)(v4 + 1);
    }
    ++v4;
  }
  while ( *v4 != 0 );
  if ( v4 == (const char *)v2 )
    return this;
  v7 = v4 - (const char *)v2;
  if ( v7 >= 259 )
    v7 = 259;
  memcpy(dst: (unsigned __int8 *)pShortName, src: v2, count: v7);
  pShortName[v7] = 0;
  return CWatchedDir::FastFindChildDir(this, pShortName);
}

//------------------------------------------------------------------------------
// Address: 0x004026D0
// Name: public: CLinearMemoryAllocator::~CLinearMemoryAllocator(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLinearMemoryAllocator::~CLinearMemoryAllocator(CLinearMemoryAllocator *this)
{
  if ( this->m_bAutoFree )
  {
    free(pMem: this->m_pBase);
    this->m_pBase = nullptr;
    this->m_bAutoFree = false;
  }
  this->m_nCurOffset = 0;
  this->m_nMaxBytes = 0;
}

// ============================================================
// Overlay from overwatch_service (Missing functions)
// ============================================================
namespace overwatch_service {

//------------------------------------------------------------------------------
// Address: 0x00403530
// Name: public: CSharedMemoryMgr::CSharedMemoryMgr(void)
// Source: json
//------------------------------------------------------------------------------
CSharedMemoryMgr *__thiscall CSharedMemoryMgr::CSharedMemoryMgr(CSharedMemoryMgr *this)
{
  this->m_pStart = nullptr;
  this->m_pEnd = nullptr;
  this->m_nBytes = 0;
  this->m_hSharedData = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00403540
// Name: unsigned int SuperFastHash(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
unsigned int __cdecl SuperFastHash(const char *data, int len)
{
  int v2; // ecx
  const char *v3; // eax
  int v4; // edx
  int i; // esi
  unsigned int v6; // ecx
  unsigned int v7; // ecx
  unsigned int v8; // edx
  unsigned int v9; // ecx
  unsigned int v10; // ecx
  unsigned int v11; // ecx

  v2 = len;
  if ( len > 0 )
  {
    v3 = data;
    if ( data != nullptr )
    {
      v4 = len >> 2;
      for ( i = len & 3; v4 > 0; v2 = (v6 >> 11) + v6 )
      {
        v6 = ((*((unsigned __int16 *)v3 + 2) ^ (32 * (*(unsigned __int16 *)v3 + v2))) << 11)
           ^ (*(unsigned __int16 *)v3 + v2);
        --v4;
        v3 += 4;
      }
      if ( i != 1 )
      {
        if ( i == 2 )
        {
          v9 = ((*(unsigned __int16 *)v3 + v2) << 11) ^ (*(unsigned __int16 *)v3 + v2);
          v2 = (v9 >> 17) + v9;
        }
        else if ( i == 3 )
        {
          v7 = (((*(unsigned __int16 *)v3 + v2) ^ (4 * v3[2])) << 16) ^ (*(unsigned __int16 *)v3 + v2);
          v8 = v7 >> 11;
LABEL_11:
          v2 = v8 + v7;
        }
        v10 = (((8 * v2) ^ (unsigned int)v2) >> 5) + ((8 * v2) ^ v2);
        v11 = (((((16 * v10) ^ v10) >> 17) + ((16 * v10) ^ v10)) << 25)
            ^ ((((16 * v10) ^ v10) >> 17) + ((16 * v10) ^ v10));
        return v11 + (v11 >> 6);
      }
      v7 = ((*v3 + v2) << 10) ^ (*v3 + v2);
      v8 = v7 >> 1;
      goto LABEL_11;
    }
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x00403620
// Name: public: unsigned int COverwatchHeader::HashFilename(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall COverwatchHeader::HashFilename(COverwatchHeader *this, const char *pFilename, int nChars)
{
  char szLowerCase[264]; // [esp+0h] [ebp-108h] BYREF

  V_strncpy(pDest: &szLowerCase[4], pSrc: pFilename, maxLen: 260);
  strlwr(string: &szLowerCase[4]);
  return SuperFastHash(data: &szLowerCase[4], len: nChars) & 0x1FFF;
}

//------------------------------------------------------------------------------
// Address: 0x00403670
// Name: public: void COverwatchHeader::GetFilenameComponents(char const __near *,char const __near * __near *,int __near *,int __near *,char const __near * __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COverwatchHeader::GetFilenameComponents(
        COverwatchHeader *this,
        char *pFullFilename,
        const char **pShortFilename,
        int *pnShortFilenameChars,
        int *pnLongDirNameChars,
        const char **pExtension)
{
  char v6; // cl
  const char *v7; // edx
  const char *v8; // eax
  const char **v9; // ecx
  const char *v10; // eax
  char v11; // cl

  v6 = *pFullFilename;
  v7 = nullptr;
  v8 = pFullFilename;
  if ( *pFullFilename == 0 )
    goto LABEL_8;
  do
  {
    if ( v6 == 47 || v6 == 92 )
      v7 = v8;
    v6 = *++v8;
  }
  while ( v6 != 0 );
  if ( v7 != nullptr )
  {
    v9 = pShortFilename;
    *pShortFilename = v7 + 1;
    *pnLongDirNameChars = v7 - pFullFilename;
  }
  else
  {
LABEL_8:
    v9 = pShortFilename;
    *pShortFilename = pFullFilename;
    *pnLongDirNameChars = 0;
  }
  *pnShortFilenameChars = v8 - *v9;
  v10 = *v9;
  v11 = **v9;
  if ( v11 == 0 )
    goto LABEL_14;
  while ( v11 != 46 )
  {
    v11 = *++v10;
    if ( v11 == 0 )
    {
      *pExtension = (const char *)&unk_40E3AE;
      return;
    }
  }
  *pExtension = v10 + 1;
  if ( *v10 == 0 )
LABEL_14:
    *pExtension = (const char *)&unk_40E3AE;
}

//------------------------------------------------------------------------------
// Address: 0x00403700
// Name: public: CLinearMemoryAllocator::CLinearMemoryAllocator(void)
// Source: json
//------------------------------------------------------------------------------
CLinearMemoryAllocator *__thiscall CLinearMemoryAllocator::CLinearMemoryAllocator(CLinearMemoryAllocator *this)
{
  this->m_pBase = nullptr;
  this->m_nCurOffset = 0;
  this->m_nMaxBytes = 0;
  this->m_bAutoFree = false;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00403710
// Name: public: void CLinearMemoryAllocator::Init(void __near *,unsigned int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLinearMemoryAllocator::Init(
        CLinearMemoryAllocator *this,
        unsigned __int8 *pBase,
        unsigned int nMaxBytes,
        bool bAutoFree)
{
  this->m_pBase = pBase;
  this->m_nMaxBytes = nMaxBytes;
  this->m_nCurOffset = 0;
  this->m_bAutoFree = bAutoFree;
}

//------------------------------------------------------------------------------
// Address: 0x00403730
// Name: public: char __near * CLinearMemoryAllocator::CopyString(char const __near *)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CLinearMemoryAllocator::CopyString(CLinearMemoryAllocator *this, const char *pStr)
{
  int v2; // edx
  unsigned int v3; // eax
  char *v4; // esi

  v2 = strlen(pStr) + 1;
  v3 = 4 * ((this->m_nCurOffset + 3) >> 2);
  v4 = (char *)&this->m_pBase[v3];
  this->m_nCurOffset = v2 + v3;
  V_strncpy(pDest: v4, pSrc: pStr, maxLen: v2);
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x00403780
// Name: public: CSharedMemoryMgr::~CSharedMemoryMgr(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSharedMemoryMgr::~CSharedMemoryMgr(CSharedMemoryMgr *this)
{
  if ( this->m_hSharedData != nullptr )
    CloseHandle(hObject: this->m_hSharedData);
  this->m_hSharedData = nullptr;
  this->m_nBytes = 0;
  this->m_pStart = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x004037B0
// Name: public: bool CSharedMemoryMgr::Create(char const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CSharedMemoryMgr::Create(CSharedMemoryMgr *this, const char *pSharedName, DWORD nBytes)
{
  HANDLE FileMappingA; // eax
  unsigned __int8 *v5; // eax

  if ( this->m_hSharedData != nullptr )
    CloseHandle(hObject: this->m_hSharedData);
  this->m_hSharedData = nullptr;
  this->m_nBytes = 0;
  this->m_pStart = nullptr;
  FileMappingA = CreateFileMappingA(
                   hFile: (HANDLE)0xFFFFFFFF,
                   lpFileMappingAttributes: nullptr,
                   flProtect: 4u,
                   dwMaximumSizeHigh: 0,
                   dwMaximumSizeLow: nBytes,
                   lpName: pSharedName);
  this->m_hSharedData = FileMappingA;
  if ( FileMappingA == nullptr )
    return 0;
  v5 = (unsigned __int8 *)MapViewOfFile(
                            hFileMappingObject: FileMappingA,
                            dwDesiredAccess: 6u,
                            dwFileOffsetHigh: 0,
                            dwFileOffsetLow: 0,
                            dwNumberOfBytesToMap: nBytes);
  this->m_pStart = v5;
  if ( v5 == nullptr )
  {
    if ( this->m_hSharedData != nullptr )
      CloseHandle(hObject: this->m_hSharedData);
    this->m_hSharedData = nullptr;
    this->m_nBytes = 0;
    this->m_pStart = nullptr;
    return 0;
  }
  this->m_nBytes = nBytes;
  this->m_pEnd = &v5[nBytes];
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00403830
// Name: public: bool CSharedMemoryMgr::Open(char const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CSharedMemoryMgr::Open(CSharedMemoryMgr *this, const char *pSharedName, SIZE_T nBytes)
{
  HANDLE v4; // eax
  unsigned __int8 *v6; // eax

  if ( this->m_hSharedData != nullptr )
    CloseHandle(hObject: this->m_hSharedData);
  this->m_hSharedData = nullptr;
  this->m_nBytes = 0;
  this->m_pStart = nullptr;
  v4 = OpenFileMappingA(dwDesiredAccess: 6u, bInheritHandle: false, lpName: pSharedName);
  this->m_hSharedData = v4;
  if ( v4 == nullptr )
    return 0;
  v6 = (unsigned __int8 *)MapViewOfFile(
                            hFileMappingObject: v4,
                            dwDesiredAccess: 6u,
                            dwFileOffsetHigh: 0,
                            dwFileOffsetLow: 0,
                            dwNumberOfBytesToMap: nBytes);
  this->m_pStart = v6;
  if ( v6 != nullptr )
  {
    this->m_nBytes = nBytes;
    this->m_pEnd = &v6[nBytes];
    return 1;
  }
  else
  {
    if ( this->m_hSharedData != nullptr )
      CloseHandle(hObject: this->m_hSharedData);
    this->m_hSharedData = nullptr;
    this->m_nBytes = 0;
    this->m_pStart = nullptr;
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004038B0
// Name: public: bool CWatchedDirectoryRoot::ShouldIgnoreExtension(char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CWatchedDirectoryRoot::ShouldIgnoreExtension(CWatchedDirectoryRoot *this, const char *pExt)
{
  unsigned int v3; // eax
  COffsetPtr<CIgnoreExtension> *p_m_pUnhashedIgnoreExtensions; // eax
  int m_nOffset; // ecx
  _DWORD *v6; // esi
  int v7; // eax
  const char *v8; // eax

  v3 = tolower(c: *pExt) - 97;
  if ( v3 < 0x1A )
    p_m_pUnhashedIgnoreExtensions = &this->m_pHashedIgnoreExtensions[v3];
  else
    p_m_pUnhashedIgnoreExtensions = &this->m_pUnhashedIgnoreExtensions;
  m_nOffset = p_m_pUnhashedIgnoreExtensions->m_nOffset;
  if ( p_m_pUnhashedIgnoreExtensions->m_nOffset == 0 )
    return 0;
  v6 = (int *)((char *)&p_m_pUnhashedIgnoreExtensions->m_nOffset + m_nOffset);
  if ( (COffsetPtr<CIgnoreExtension> *)((char *)p_m_pUnhashedIgnoreExtensions + m_nOffset) == nullptr )
    return 0;
  while ( 1 )
  {
    v7 = v6[1];
    v8 = v7 != 0 ? (char *)v6 + v7 + 4 : nullptr;
    if ( _stricmp(dst: v8, src: pExt) == 0 )
      break;
    if ( *v6 != 0 )
    {
      v6 = (_DWORD *)((char *)v6 + *v6);
      if ( v6 != nullptr )
        continue;
    }
    return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00403920
// Name: public: void CWatchedDir::Init(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWatchedDir::Init(CWatchedDir *this)
{
  this->m_pFirstChildDir.m_nOffset = 0;
  this->m_pNextChildDir.m_nOffset = 0;
  this->m_pFirstFile.m_nOffset = 0;
  this->m_bUpToDate = false;
  this->m_pShortName.m_nOffset = 0;
  this->m_pLongName.m_nOffset = 0;
  this->m_pWatchedDirectoryRoot.m_nOffset = 0;
}

//------------------------------------------------------------------------------
// Address: 0x00403940
// Name: public: class CWatchedDir __near * CWatchedDir::FastFindChildDir(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CWatchedDir *__thiscall CWatchedDir::FastFindChildDir(CWatchedDir *this, const char *pShortName)
{
  int m_nOffset; // eax
  char *v3; // esi
  int v4; // eax
  const char *v5; // eax
  int v6; // eax

  m_nOffset = this->m_pFirstChildDir.m_nOffset;
  if ( this->m_pFirstChildDir.m_nOffset == 0 )
    return nullptr;
  v3 = (char *)this + m_nOffset;
  if ( (CWatchedDir *)((char *)this + m_nOffset) == nullptr )
    return nullptr;
  while ( 1 )
  {
    v4 = *((_DWORD *)v3 + 5);
    v5 = v4 != 0 ? &v3[v4 + 20] : nullptr;
    if ( _stricmp(dst: v5, src: pShortName) == 0 )
      break;
    v6 = *((_DWORD *)v3 + 1);
    if ( v6 != 0 )
    {
      v3 += v6 + 4;
      if ( v3 != nullptr )
        continue;
    }
    return nullptr;
  }
  return (CWatchedDir *)v3;
}

//------------------------------------------------------------------------------
// Address: 0x00403990
// Name: public: class CWatchedDir __near * CWatchedDir::FindChildDir(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CWatchedDir *__thiscall CWatchedDir::FindChildDir(CWatchedDir *this, char *pLongDirName)
{
  unsigned __int8 *v2; // eax
  const char *v4; // edi
  unsigned int v5; // esi
  signed int v7; // edi
  char dst[260]; // [esp+Ch] [ebp-208h] BYREF
  char pShortName[260]; // [esp+110h] [ebp-104h] BYREF

  v2 = (unsigned __int8 *)pLongDirName;
  v4 = pLongDirName;
  if ( *pLongDirName == 0 )
    return this;
  do
  {
    if ( *v4 == 47 || *v4 == 92 )
    {
      if ( v4 != (const char *)v2 )
      {
        v5 = v4 - (const char *)v2;
        if ( v4 - (const char *)v2 >= 259 )
          v5 = 259;
        memcpy((unsigned __int8 *)dst, src: v2, count: v5);
        dst[v5] = 0;
        this = CWatchedDir::FastFindChildDir(this, pShortName: dst);
      }
      if ( this == nullptr )
        return nullptr;
      v2 = (unsigned __int8 *)(v4 + 1);
    }
    ++v4;
  }
  while ( *v4 != 0 );
  if ( v4 == (const char *)v2 )
    return this;
  v7 = v4 - (const char *)v2;
  if ( v7 >= 259 )
    v7 = 259;
  memcpy(dst: (unsigned __int8 *)pShortName, src: v2, count: v7);
  pShortName[v7] = 0;
  return CWatchedDir::FastFindChildDir(this, pShortName);
}

//------------------------------------------------------------------------------
// Address: 0x00403A60
// Name: public: void COverwatchHeader::Init(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COverwatchHeader::Init(COverwatchHeader *this)
{
  this->m_nAppSignals = 0;
  this->m_pFirstWatchedDirectoryRoot.m_nOffset = 0;
  memset(this->m_Hash, 0, sizeof(this->m_Hash));
  this->m_RootDir.m_pFirstChildDir.m_nOffset = 0;
  this->m_RootDir.m_pNextChildDir.m_nOffset = 0;
  this->m_RootDir.m_pFirstFile.m_nOffset = 0;
  this->m_RootDir.m_bUpToDate = false;
  this->m_RootDir.m_pShortName.m_nOffset = 0;
  this->m_RootDir.m_pLongName.m_nOffset = 0;
  this->m_RootDir.m_pWatchedDirectoryRoot.m_nOffset = 0;
}

//------------------------------------------------------------------------------
// Address: 0x00403AB0
// Name: public: class CWatchedFile __near * COverwatchHeader::LookupFile(char const __near *,int,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
CWatchedFile *__thiscall COverwatchHeader::LookupFile(
        COverwatchHeader *this,
        const char *pShortFilename,
        int nShortFilenameChars,
        const char *pLongDirName,
        int nLongDirNameChars)
{
  unsigned int v6; // eax
  int m_nOffset; // ecx
  COffsetPtr<CWatchedFile> *v8; // eax
  char *v9; // esi
  int v10; // eax
  int v11; // eax
  int v12; // ecx
  const char *v13; // eax
  int v14; // eax
  char pDest[260]; // [esp+10h] [ebp-104h] BYREF

  V_strncpy(pDest, pSrc: pShortFilename, maxLen: 260);
  strlwr(string: pDest);
  v6 = SuperFastHash(data: pDest, len: nShortFilenameChars) & 0x1FFF;
  m_nOffset = this->m_Hash[v6].m_nOffset;
  v8 = &this->m_Hash[v6];
  if ( m_nOffset == 0 )
    return nullptr;
  v9 = (char *)v8 + m_nOffset;
  if ( (COffsetPtr<CWatchedFile> *)((char *)v8 + m_nOffset) == nullptr )
    return nullptr;
  while ( 1 )
  {
    if ( _stricmp(dst: v9 + 36, src: pShortFilename) == 0 )
    {
      v10 = *((_DWORD *)v9 + 6);
      v11 = v10 != 0 ? (int)&v9[v10 + 24] : 0;
      v12 = *(_DWORD *)(v11 + 24);
      v13 = v12 != 0 ? (const char *)(v12 + v11 + 24) : nullptr;
      if ( V_strncasecmp(s1: v13, s2: pLongDirName, n: nLongDirNameChars) == 0 )
        break;
    }
    v14 = *((_DWORD *)v9 + 4);
    if ( v14 != 0 )
    {
      v9 += v14 + 16;
      if ( v9 != nullptr )
        continue;
    }
    return nullptr;
  }
  return (CWatchedFile *)v9;
}

//------------------------------------------------------------------------------
// Address: 0x00403B90
// Name: public: CLinearMemoryAllocator::~CLinearMemoryAllocator(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLinearMemoryAllocator::~CLinearMemoryAllocator(CLinearMemoryAllocator *this)
{
  if ( this->m_bAutoFree )
  {
    free(pMem: this->m_pBase);
    this->m_pBase = nullptr;
    this->m_bAutoFree = false;
  }
  this->m_nCurOffset = 0;
  this->m_nMaxBytes = 0;
}

//------------------------------------------------------------------------------
// Address: 0x00403BC0
// Name: public: void CWatchedDirectoryRoot::Init(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWatchedDirectoryRoot::Init(CWatchedDirectoryRoot *this)
{
  this->m_pFirstChildDir.m_nOffset = 0;
  this->m_pNextChildDir.m_nOffset = 0;
  this->m_pFirstFile.m_nOffset = 0;
  this->m_bUpToDate = false;
  this->m_pShortName.m_nOffset = 0;
  this->m_pLongName.m_nOffset = 0;
  this->m_pWatchedDirectoryRoot.m_nOffset = 0;
  this->m_pHashedIgnoreExtensions[0].m_nOffset = 0;
  this->m_pHashedIgnoreExtensions[1].m_nOffset = 0;
  this->m_pHashedIgnoreExtensions[2].m_nOffset = 0;
  this->m_pHashedIgnoreExtensions[3].m_nOffset = 0;
  this->m_pHashedIgnoreExtensions[4].m_nOffset = 0;
  this->m_pHashedIgnoreExtensions[5].m_nOffset = 0;
  this->m_pHashedIgnoreExtensions[6].m_nOffset = 0;
  this->m_pHashedIgnoreExtensions[7].m_nOffset = 0;
  this->m_pHashedIgnoreExtensions[8].m_nOffset = 0;
  this->m_pHashedIgnoreExtensions[9].m_nOffset = 0;
  this->m_pHashedIgnoreExtensions[10].m_nOffset = 0;
  this->m_pHashedIgnoreExtensions[11].m_nOffset = 0;
  this->m_pHashedIgnoreExtensions[12].m_nOffset = 0;
  this->m_pHashedIgnoreExtensions[13].m_nOffset = 0;
  this->m_pHashedIgnoreExtensions[14].m_nOffset = 0;
  this->m_pHashedIgnoreExtensions[15].m_nOffset = 0;
  this->m_pHashedIgnoreExtensions[16].m_nOffset = 0;
  this->m_pHashedIgnoreExtensions[17].m_nOffset = 0;
  this->m_pHashedIgnoreExtensions[18].m_nOffset = 0;
  this->m_pHashedIgnoreExtensions[19].m_nOffset = 0;
  this->m_pHashedIgnoreExtensions[20].m_nOffset = 0;
  this->m_pHashedIgnoreExtensions[21].m_nOffset = 0;
  this->m_pHashedIgnoreExtensions[22].m_nOffset = 0;
  this->m_pHashedIgnoreExtensions[23].m_nOffset = 0;
  this->m_pHashedIgnoreExtensions[24].m_nOffset = 0;
  this->m_pHashedIgnoreExtensions[25].m_nOffset = 0;
  this->m_pUnhashedIgnoreExtensions.m_nOffset = 0;
}

//------------------------------------------------------------------------------
// Address: 0x00403C40
// Name: public: void CWatchedDirectoryRoot::AddIgnoreExtension(class CIgnoreExtension __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWatchedDirectoryRoot::AddIgnoreExtension(CWatchedDirectoryRoot *this, CIgnoreExtension *pIgnoreExt)
{
  int m_nOffset; // eax
  char *v4; // eax
  unsigned int v5; // eax
  int v6; // eax
  COffsetPtr<CIgnoreExtension> *p_m_pUnhashedIgnoreExtensions; // ecx
  char *v8; // eax
  int v9; // ecx
  COffsetPtr<CIgnoreExtension> *v10; // eax
  char *v11; // ecx

  m_nOffset = pIgnoreExt->m_pExtension.m_nOffset;
  if ( m_nOffset != 0 )
    v4 = (char *)&pIgnoreExt->m_pExtension + m_nOffset;
  else
    v4 = nullptr;
  v5 = tolower(c: *v4) - 97;
  if ( v5 < 0x1A )
  {
    v9 = this->m_pHashedIgnoreExtensions[v5].m_nOffset;
    v10 = &this->m_pHashedIgnoreExtensions[v5];
    if ( v9 != 0 && (v11 = (char *)v10 + v9) != nullptr )
    {
      pIgnoreExt->m_pNext.m_nOffset = v11 - (char *)pIgnoreExt;
      v10->m_nOffset = (char *)pIgnoreExt - (char *)v10;
    }
    else
    {
      pIgnoreExt->m_pNext.m_nOffset = 0;
      v10->m_nOffset = (char *)pIgnoreExt - (char *)v10;
    }
  }
  else
  {
    v6 = this->m_pUnhashedIgnoreExtensions.m_nOffset;
    p_m_pUnhashedIgnoreExtensions = &this->m_pUnhashedIgnoreExtensions;
    if ( v6 != 0 && (v8 = (char *)p_m_pUnhashedIgnoreExtensions + v6) != nullptr )
    {
      pIgnoreExt->m_pNext.m_nOffset = v8 - (char *)pIgnoreExt;
      p_m_pUnhashedIgnoreExtensions->m_nOffset = (char *)pIgnoreExt - (char *)p_m_pUnhashedIgnoreExtensions;
    }
    else
    {
      pIgnoreExt->m_pNext.m_nOffset = 0;
      p_m_pUnhashedIgnoreExtensions->m_nOffset = (char *)pIgnoreExt - (char *)p_m_pUnhashedIgnoreExtensions;
    }
  }
}

} // namespace overwatch_service
