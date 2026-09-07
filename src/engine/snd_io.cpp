// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: engine/snd_io.cpp
// Functions: 92
// ============================================================

#include "engine\snd_io.h"

//------------------------------------------------------------------------------
// Address: 0x1002B570
// Name: public: virtual int COM_IOReadBinary::open(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void *__thiscall COM_IOReadBinary::open(COM_IOReadBinary *this, const char *pFileName)
{
  char namebuffer[512]; // [esp+4h] [ebp-200h] BYREF

  V_strncpy(pDest: namebuffer, pSrc: "sound", maxLen: 512);
  if ( *pFileName != 47 && *pFileName != 92 )
    V_strncat(pDest: namebuffer, pSrc: "/", destBufferSize: 0x200u, max_chars_to_copy: -1);
  V_strncat(pDest: namebuffer, pSrc: pFileName, destBufferSize: 0x200u, max_chars_to_copy: -1);
  return g_pFileSystem->Open(this: &g_pFileSystem->IBaseFileSystem, a2: namebuffer, a3: "rb", a4: "GAME");
}

//------------------------------------------------------------------------------
// Address: 0x1002B600
// Name: public: virtual int COM_IOReadBinary::read(void __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void *__thiscall COM_IOReadBinary::read(COM_IOReadBinary *this, void *pOutput, int size, void *file)
{
  void *result; // eax

  result = file;
  if ( file != nullptr )
    return (void *)g_pFileSystem->Read(this: &g_pFileSystem->IBaseFileSystem, a2: pOutput, a3: size, a4: file);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1002B630
// Name: public: virtual void COM_IOReadBinary::seek(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COM_IOReadBinary::seek(COM_IOReadBinary *this, void *file, int pos)
{
  if ( file != nullptr )
    g_pFileSystem->Seek(this: &g_pFileSystem->IBaseFileSystem, a2: file, a3: pos, a4: FILESYSTEM_SEEK_HEAD);
}

//------------------------------------------------------------------------------
// Address: 0x1002B660
// Name: public: virtual unsigned int COM_IOReadBinary::tell(int)
// Source: json
//------------------------------------------------------------------------------
void *__thiscall COM_IOReadBinary::tell(COM_IOReadBinary *this, void *file)
{
  void *result; // eax

  result = file;
  if ( file != nullptr )
    return (void *)g_pFileSystem->Tell(this: &g_pFileSystem->IBaseFileSystem, a2: file);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1002B690
// Name: public: virtual unsigned int COM_IOReadBinary::size(int)
// Source: json
//------------------------------------------------------------------------------
void *__thiscall COM_IOReadBinary::size(COM_IOReadBinary *this, void *file)
{
  void *result; // eax

  result = file;
  if ( file != nullptr )
    return (void *)g_pFileSystem->Size_2(this: &g_pFileSystem->IBaseFileSystem, a2: file);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1002B6C0
// Name: public: virtual void COM_IOReadBinary::close(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COM_IOReadBinary::close(COM_IOReadBinary *this, void *file)
{
  if ( file != nullptr )
    g_pFileSystem->Close(this: &g_pFileSystem->IBaseFileSystem, a2: file);
}

//------------------------------------------------------------------------------
// Address: 0x102FCDD3
// Name: __close
// Source: json
//------------------------------------------------------------------------------
int __cdecl _close(int fh)
{
  ioinfo **v2; // edi
  int v3; // esi
  int r; // [esp+14h] [ebp-1Ch]

  if ( fh == -2 )
  {
    *__doserrno() = 0;
    *_errno() = 9;
    return -1;
  }
  if ( fh < 0 || fh >= _nhandle || (v2 = &__pioinfo[fh >> 5], v3 = (fh & 0x1F) << 6, (*(&(*v2)->osfile + v3) & 1) == 0) )
  {
    *__doserrno() = 0;
    *_errno() = 9;
    _invalid_parameter_noinfo();
    return -1;
  }
  __lock_fhandle(fh);
  if ( (*(&(*v2)->osfile + v3) & 1) != 0 )
  {
    r = _close_nolock(fh);
  }
  else
  {
    *_errno() = 9;
    r = -1;
  }
  _unlock_fhandle(fh);
  return r;
}

//------------------------------------------------------------------------------
// Address: 0x102FCE97
// Name: __freebuf
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _freebuf(_iobuf *stream)
{
  int flag; // eax

  flag = stream->_flag;
  if ( (flag & 0x83) != 0 && (flag & 8) != 0 )
  {
    free(pMem: stream->_base);
    stream->_flag &= 0xFFFFFBF7;
    stream->_ptr = nullptr;
    stream->_base = nullptr;
    stream->_cnt = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102FCEC8
// Name: __lseek_nolock
// Source: linker_block_proximity
//------------------------------------------------------------------------------
DWORD __cdecl _lseek_nolock(int fh, LONG pos, DWORD mthd)
{
  void *osfhandle; // eax
  DWORD v5; // edi
  DWORD LastError; // eax
  char *p_osfile; // eax

  osfhandle = (void *)_get_osfhandle(fh);
  if ( osfhandle == (void *)-1 )
  {
    *_errno() = 9;
    return -1;
  }
  else
  {
    v5 = SetFilePointer(hFile: osfhandle, lDistanceToMove: pos, lpDistanceToMoveHigh: nullptr, dwMoveMethod: mthd);
    if ( v5 == -1 )
      LastError = GetLastError();
    else
      LastError = 0;
    if ( LastError != 0 )
    {
      _dosmaperr(oserrno: LastError);
      return -1;
    }
    else
    {
      p_osfile = &__pioinfo[fh >> 5][fh & 0x1F].osfile;
      *p_osfile &= ~2u;
      return v5;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102FCF3D
// Name: __lseek
// Source: linker_block_proximity
//------------------------------------------------------------------------------
DWORD __cdecl _lseek(int fh, LONG pos, DWORD mthd)
{
  ioinfo **v4; // edi
  int v5; // esi
  DWORD r; // [esp+14h] [ebp-1Ch]

  if ( fh == -2 )
  {
    *__doserrno() = 0;
    *_errno() = 9;
    return -1;
  }
  if ( fh < 0 || fh >= _nhandle || (v4 = &__pioinfo[fh >> 5], v5 = (fh & 0x1F) << 6, (*(&(*v4)->osfile + v5) & 1) == 0) )
  {
    *__doserrno() = 0;
    *_errno() = 9;
    _invalid_parameter_noinfo();
    return -1;
  }
  __lock_fhandle(fh);
  if ( (*(&(*v4)->osfile + v5) & 1) != 0 )
  {
    r = _lseek_nolock(fh, pos, mthd);
  }
  else
  {
    *_errno() = 9;
    *__doserrno() = 0;
    r = -1;
  }
  _unlock_fhandle(fh);
  return r;
}

//------------------------------------------------------------------------------
// Address: 0x102FD011
// Name: __openfile
// Source: linker_block_proximity
//------------------------------------------------------------------------------
_iobuf *__cdecl _openfile(const char *filename, const char *mode, int shflag, _iobuf *str)
{
  unsigned int v4; // ebx
  const char *v5; // esi
  char v6; // al
  _iobuf *result; // eax
  int v8; // ecx
  const unsigned __int8 *v9; // esi
  signed __int8 v10; // al
  int v11; // eax
  int v12; // eax
  int v13; // eax
  int v14; // eax
  int v15; // eax
  int v16; // eax
  int v17; // eax
  int v18; // eax
  int v19; // eax
  const unsigned __int8 *i; // esi
  int encodingFlag; // [esp+8h] [ebp-10h]
  int commodeset; // [esp+Ch] [ebp-Ch]
  int scanset; // [esp+10h] [ebp-8h]
  unsigned int streamflag; // [esp+14h] [ebp-4h]

  v4 = 0;
  v5 = mode;
  commodeset = 0;
  scanset = 0;
  encodingFlag = 0;
  while ( *v5 == 32 )
    ++v5;
  v6 = *v5;
  if ( *v5 == 97 )
  {
    v4 = 265;
  }
  else
  {
    if ( v6 == 114 )
    {
      streamflag = _commode | 1;
      goto LABEL_12;
    }
    if ( v6 != 119 )
    {
      *_errno() = 22;
      _invalid_parameter_noinfo();
      return nullptr;
    }
    v4 = 769;
  }
  streamflag = _commode | 2;
LABEL_12:
  v8 = 1;
  v9 = (const unsigned __int8 *)(v5 + 1);
  v10 = *v9;
  if ( *v9 == 0 )
    goto LABEL_66;
  while ( v8 != 0 )
  {
    if ( v10 > 83 )
    {
      v16 = v10 - 84;
      if ( v16 == 0 )
      {
        if ( (v4 & 0x1000) == 0 )
        {
          v4 |= 0x1000u;
          goto LABEL_48;
        }
        goto LABEL_46;
      }
      v17 = v16 - 14;
      if ( v17 != 0 )
      {
        v18 = v17 - 1;
        if ( v18 != 0 )
        {
          v19 = v18 - 11;
          if ( v19 != 0 )
          {
            if ( v19 != 6 )
              goto LABEL_68;
            if ( (v4 & 0xC000) != 0 )
              goto LABEL_46;
            v4 |= 0x4000u;
          }
          else
          {
            if ( commodeset != 0 )
              goto LABEL_46;
            streamflag &= ~0x4000u;
            commodeset = 1;
          }
        }
        else
        {
          if ( commodeset != 0 )
            goto LABEL_46;
          streamflag |= 0x4000u;
          commodeset = 1;
        }
      }
      else
      {
        if ( (v4 & 0xC000) != 0 )
          goto LABEL_46;
        v4 |= 0x8000u;
      }
    }
    else if ( v10 == 83 )
    {
      if ( scanset != 0 )
        goto LABEL_46;
      scanset = 1;
      v4 |= 0x20u;
    }
    else
    {
      v11 = v10 - 32;
      if ( v11 != 0 )
      {
        v12 = v11 - 11;
        if ( v12 != 0 )
        {
          v13 = v12 - 1;
          if ( v13 == 0 )
          {
            encodingFlag = 1;
LABEL_46:
            v8 = 0;
            goto LABEL_48;
          }
          v14 = v13 - 24;
          if ( v14 != 0 )
          {
            v15 = v14 - 10;
            if ( v15 != 0 )
            {
              if ( v15 != 4 )
                goto LABEL_68;
              if ( scanset != 0 )
                goto LABEL_46;
              scanset = 1;
              v4 |= 0x10u;
            }
            else
            {
              v4 |= 0x80u;
            }
          }
          else
          {
            if ( (v4 & 0x40) != 0 )
              goto LABEL_46;
            v4 |= 0x40u;
          }
        }
        else
        {
          if ( (v4 & 2) != 0 )
            goto LABEL_46;
          v4 = v4 & 0xFFFFFFFC | 2;
          streamflag = streamflag & 0xFFFFFF7C | 0x80;
        }
      }
    }
LABEL_48:
    v10 = *++v9;
    if ( *v9 == 0 )
      break;
  }
  if ( encodingFlag == 0 )
    goto LABEL_66;
  while ( *v9 == 32 )
    ++v9;
  if ( _mbsnbcmp(s1: "ccs", s2: v9, n: 3u) != 0 )
    goto LABEL_68;
  for ( i = v9 + 3; *i == 32; ++i )
    ;
  if ( *i != 61 )
    goto LABEL_68;
  do
    ++i;
  while ( *i == 32 );
  if ( _mbsnbicmp(s1: i, s2: "UTF-8", n: 5u) == 0 )
  {
    v9 = i + 5;
    v4 |= 0x40000u;
    goto LABEL_66;
  }
  if ( _mbsnbicmp(s1: i, s2: "UTF-16LE", n: 8u) == 0 )
  {
    v9 = i + 8;
    v4 |= 0x20000u;
    goto LABEL_66;
  }
  if ( _mbsnbicmp(s1: i, s2: "UNICODE", n: 7u) != 0 )
    goto LABEL_68;
  v9 = i + 7;
  v4 |= 0x10000u;
LABEL_66:
  while ( *v9 == 32 )
    ++v9;
  if ( *v9 != 0 )
  {
LABEL_68:
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return nullptr;
  }
  if ( _sopen_s(pfh: (int *)&mode, path: filename, oflag: v4, shflag, pmode: 384) != 0 )
    return nullptr;
  ++_cflush;
  result = str;
  str->_flag = streamflag;
  result->_cnt = 0;
  result->_ptr = nullptr;
  result->_base = nullptr;
  result->_tmpfname = nullptr;
  result->_file = (int)mode;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102FD2A8
// Name: __getstream
// Source: linker_block_proximity
//------------------------------------------------------------------------------
_iobuf *__cdecl _getstream()
{
  _DWORD *v0; // edi
  int i; // esi
  void **v2; // eax
  int v3; // eax
  void *v4; // eax

  v0 = nullptr;
  _lock(locknum: 1);
  for ( i = 0; i < (int)_nstream; ++i )
  {
    v2 = &__piob[i];
    if ( *v2 == nullptr )
    {
      v4 = MemAlloc_Alloc(nSize: 0x38u);
      __piob[i] = v4;
      if ( v4 != nullptr )
      {
        if ( InitializeCriticalSectionAndSpinCount(
               lpCriticalSection: (LPCRITICAL_SECTION)((char *)__piob[i] + 32),
               dwSpinCount: 0xFA0u) )
        {
          EnterCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)((char *)__piob[i] + 32));
          v0 = __piob[i];
          v0[3] = 0;
        }
        else
        {
          free(pMem: __piob[i]);
          __piob[i] = nullptr;
        }
      }
      break;
    }
    v3 = *((_DWORD *)*v2 + 3);
    if ( (v3 & 0x83) == 0 && (v3 & 0x8000) == 0 )
    {
      if ( (unsigned int)(i - 3) <= 0x10 && _mtinitlocknum(locknum: i + 16) == 0 )
        break;
      _lock_file2(i, s: (char *)__piob[i]);
      if ( (*((_BYTE *)__piob[i] + 12) & 0x83) == 0 )
      {
        v0 = __piob[i];
        break;
      }
      _unlock_file2(i, s: (char *)__piob[i]);
    }
  }
  if ( v0 != nullptr )
  {
    v0[3] &= 0x8000u;
    v0[1] = 0;
    v0[2] = 0;
    *v0 = 0;
    v0[7] = 0;
    v0[4] = -1;
  }
  _unlock(locknum: 1);
  return (_iobuf *)v0;
}

//------------------------------------------------------------------------------
// Address: 0x102FD3E0
// Name: __local_unwind4
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _local_unwind4(_DWORD *a1, int a2, unsigned int a3)
{
  int result; // eax
  unsigned int v4; // esi
  int v5; // esi
  int v6; // ebx
  _EXCEPTION_REGISTRATION_RECORD *ExceptionList; // [esp-18h] [ebp-28h]
  int (__cdecl *v8)(int, int, int, int); // [esp-14h] [ebp-24h]

  v8 = unwind_handler4;
  ExceptionList = NtCurrentTeb()->NtTib.ExceptionList;
  while ( 1 )
  {
    result = a2;
    v4 = *(_DWORD *)(a2 + 12);
    if ( v4 == -2 || a3 != -2 && v4 <= a3 )
      break;
    v5 = 3 * v4;
    v6 = (*a1 ^ *(_DWORD *)(a2 + 8)) + 4 * v5 + 16;
    *(_DWORD *)(a2 + 12) = *(_DWORD *)((*a1 ^ *(_DWORD *)(a2 + 8)) + 4 * v5 + 0x10);
    if ( *(_DWORD *)(v6 + 4) == 0 )
    {
      _NLG_Notify(a1: 257);
      _NLG_Call(a1: 1, a2: ExceptionList, a3: v8);
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102FD470
// Name: _unwind_handler4
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl unwind_handler4(int a1, int a2, int a3, _DWORD *a4)
{
  int result; // eax

  result = 1;
  if ( (*(_DWORD *)(a1 + 4) & 6) != 0 )
  {
    _local_unwind4(a1: *(_DWORD **)(a2 + 20), a2: *(_DWORD *)(a2 + 16), a3: *(_DWORD *)(a2 + 12));
    *a4 = a2;
    return 3;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102FD4B6
// Name: _seh_longjmp_unwind4(x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __stdcall _seh_longjmp_unwind4(unsigned int Dummy)
{
  _local_unwind4(a1: *(_DWORD **)(Dummy + 40), a2: *(_DWORD *)(Dummy + 24), a3: *(_DWORD *)(Dummy + 28));
}

//------------------------------------------------------------------------------
// Address: 0x102FD4D2
// Name: _EH4_CallFilterFunc(x,x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall _EH4_CallFilterFunc(int (*this)(void))
{
  return this();
}

//------------------------------------------------------------------------------
// Address: 0x102FD4E9
// Name: _EH4_TransferToHandler(x,x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall _EH4_TransferToHandler(int (__fastcall *this)(_DWORD, _DWORD))
{
  _NLG_Notify(a1: 1);
  return this(a1: 0, a2: 0);
}

//------------------------------------------------------------------------------
// Address: 0x102FD502
// Name: _EH4_GlobalUnwind2(x,x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __fastcall _EH4_GlobalUnwind2(PVOID TargetFrame, PEXCEPTION_RECORD ExceptionRecord)
{
  RtlUnwind(TargetFrame, TargetIp: &ReturnPoint_0, ExceptionRecord, ReturnValue: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x102FD51B
// Name: _EH4_LocalUnwind(x,x,x,x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __fastcall _EH4_LocalUnwind(int a1, unsigned int a2, int a3, _DWORD *a4)
{
  return _local_unwind4(a1: a4, a2: a1, a3: a2);
}

//------------------------------------------------------------------------------
// Address: 0x102FD532
// Name: __ioinit
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _ioinit()
{
  unsigned __int8 *v0; // eax
  unsigned __int8 *v2; // eax
  int v3; // ebx
  unsigned __int8 **v4; // edi
  unsigned __int8 *v5; // eax
  unsigned __int8 *v6; // eax
  int i; // edi
  ioinfo *v8; // esi
  int j; // ebx
  ioinfo *v10; // esi
  DWORD v11; // eax
  HANDLE StdHandle; // eax
  int v13; // edi
  DWORD FileType; // eax
  _STARTUPINFOW StartupInfo; // [esp+4h] [ebp-4Ch] BYREF
  int *posfhnd; // [esp+48h] [ebp-8h]
  char *posfile; // [esp+4Ch] [ebp-4h]

  GetStartupInfoW(lpStartupInfo: &StartupInfo);
  v0 = calloc(count: 0x20u, size: 0x40u);
  if ( v0 == nullptr )
    return -1;
  __pioinfo[0] = (ioinfo *)v0;
  _nhandle = 32;
  if ( v0 < v0 + 2048 )
  {
    v2 = v0 + 5;
    do
    {
      *(_DWORD *)(v2 - 5) = -1;
      *(_WORD *)(v2 - 1) = 2560;
      *(_DWORD *)(v2 + 3) = 0;
      *(_WORD *)(v2 + 31) = 2560;
      v2[33] = 10;
      *(_DWORD *)(v2 + 51) = 0;
      v2[47] = 0;
      v2 += 64;
    }
    while ( (ioinfo *)(v2 - 5) < &__pioinfo[0][32] );
  }
  if ( StartupInfo.cbReserved2 != 0 && StartupInfo.lpReserved2 != nullptr )
  {
    v3 = *(_DWORD *)StartupInfo.lpReserved2;
    posfile = (char *)(StartupInfo.lpReserved2 + 4);
    posfhnd = (int *)&StartupInfo.lpReserved2[v3 + 4];
    if ( v3 >= 2048 )
      v3 = 2048;
    if ( (int)_nhandle < v3 )
    {
      v4 = (unsigned __int8 **)&unk_106CF7A4;
      while ( 1 )
      {
        v5 = calloc(count: 0x20u, size: 0x40u);
        if ( v5 == nullptr )
          break;
        _nhandle += 32;
        *v4 = v5;
        if ( v5 < v5 + 2048 )
        {
          v6 = v5 + 5;
          do
          {
            *(_DWORD *)(v6 - 5) = -1;
            *(_DWORD *)(v6 + 3) = 0;
            v6[31] &= 0x80u;
            *(_DWORD *)(v6 + 51) = 0;
            *(_WORD *)(v6 - 1) = 2560;
            *((_WORD *)v6 + 16) = 2570;
            v6[47] = 0;
            v6 += 64;
          }
          while ( v6 - 5 < *v4 + 2048 );
        }
        ++v4;
        if ( (int)_nhandle >= v3 )
          goto LABEL_19;
      }
      v3 = _nhandle;
    }
LABEL_19:
    for ( i = 0; i < v3; ++posfile )
    {
      if ( *posfhnd != -1
        && *posfhnd != -2
        && (*posfile & 1) != 0
        && ((*posfile & 8) != 0 || GetFileType(hFile: (HANDLE)*posfhnd) != 0) )
      {
        v8 = &__pioinfo[i >> 5][i & 0x1F];
        v8->osfhnd = *posfhnd;
        v8->osfile = *posfile;
        if ( !InitializeCriticalSectionAndSpinCount(lpCriticalSection: &v8->lock, dwSpinCount: 0xFA0u) )
          return -1;
        ++v8->lockinitflag;
      }
      ++posfhnd;
      ++i;
    }
  }
  for ( j = 0; j < 3; ++j )
  {
    v10 = &__pioinfo[0][j];
    if ( v10->osfhnd == -1 || v10->osfhnd == -2 )
    {
      v10->osfile = -127;
      if ( j != 0 )
        v11 = -(j != 1) - 11;
      else
        v11 = -10;
      StdHandle = GetStdHandle(nStdHandle: v11);
      v13 = (int)StdHandle;
      if ( StdHandle != (HANDLE)-1 && StdHandle != nullptr && (FileType = GetFileType(hFile: StdHandle)) != 0 )
      {
        v10->osfhnd = v13;
        if ( (unsigned __int8)FileType == 2 )
        {
          v10->osfile |= 0x40u;
        }
        else if ( (unsigned __int8)FileType == 3 )
        {
          v10->osfile |= 8u;
        }
        if ( !InitializeCriticalSectionAndSpinCount(lpCriticalSection: &v10->lock, dwSpinCount: 0xFA0u) )
          return -1;
        ++v10->lockinitflag;
      }
      else
      {
        v10->osfile |= 0x40u;
        v10->osfhnd = -2;
      }
    }
    else
    {
      v10->osfile |= 0x80u;
    }
  }
  SetHandleCount(uNumber: _nhandle);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x102FD777
// Name: __ioterm
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void _ioterm()
{
  void **v0; // edi
  char *v1; // eax
  _RTL_CRITICAL_SECTION *v2; // esi

  v0 = (void **)__pioinfo;
  do
  {
    v1 = (char *)*v0;
    if ( *v0 != nullptr )
    {
      if ( v1 < v1 + 2048 )
      {
        v2 = (_RTL_CRITICAL_SECTION *)(v1 + 12);
        do
        {
          if ( v2[-1].SpinCount != 0 )
            DeleteCriticalSection(lpCriticalSection: v2);
          v2 = (_RTL_CRITICAL_SECTION *)((char *)v2 + 64);
        }
        while ( &v2[-1].OwningThread < (void **)((char *)*v0 + 2048) );
      }
      free(pMem: *v0);
      *v0 = nullptr;
    }
    ++v0;
  }
  while ( (int)v0 < (int)&_pmatherr );
}

//------------------------------------------------------------------------------
// Address: 0x102FD7CA
// Name: __crtLCMapStringA_stat
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _crtLCMapStringA_stat(
        localeinfo_struct *plocinfo,
        LCID Locale,
        DWORD dwMapFlags,
        const char *lpSrcStr,
        int cchSrc,
        char *lpDestStr,
        int cchDest,
        UINT code_page,
        int bError)
{
  const char *v9; // eax
  int v10; // ecx
  int v11; // eax
  int v12; // eax
  int v13; // edi
  unsigned int v15; // eax
  void *v16; // esp
  wchar_t *v17; // eax
  unsigned int v18; // eax
  void *v19; // esp
  wchar_t *v20; // edi
  wchar_t *v21; // eax
  int v22; // eax
  _DWORD v23[2]; // [esp+0h] [ebp-1Ch] BYREF
  int v24; // [esp+8h] [ebp-14h] BYREF
  int inbuff_size; // [esp+Ch] [ebp-10h]
  wchar_t *inwbuffer; // [esp+10h] [ebp-Ch]
  int retval; // [esp+14h] [ebp-8h]

  if ( cchSrc > 0 )
  {
    v9 = lpSrcStr;
    v10 = cchSrc;
    while ( 1 )
    {
      --v10;
      if ( *v9 == 0 )
        break;
      ++v9;
      if ( v10 == 0 )
      {
        v10 = -1;
        break;
      }
    }
    v11 = cchSrc - v10 - 1;
    if ( v11 < cchSrc )
      v11 = cchSrc - v10;
    cchSrc = v11;
  }
  retval = 0;
  if ( code_page == 0 )
    code_page = plocinfo->locinfo->lc_codepage;
  v12 = MultiByteToWideChar(
          CodePage: code_page,
          dwFlags: 8 * (bError != 0) + 1,
          lpMultiByteStr: lpSrcStr,
          cbMultiByte: cchSrc,
          lpWideCharStr: nullptr,
          cchWideChar: 0);
  v13 = v12;
  inbuff_size = v12;
  if ( v12 == 0 )
    return 0;
  if ( v12 > 0 && 0xFFFFFFE0 / v12 >= 2 )
  {
    v15 = 2 * v12 + 8;
    if ( v15 > 0x400 )
    {
      v17 = (wchar_t *)MemAlloc_Alloc(nSize: 2 * v13 + 8);
      if ( v17 != nullptr )
      {
        *(_DWORD *)v17 = 56797;
        goto LABEL_20;
      }
    }
    else
    {
      v16 = alloca(v15);
      v17 = (wchar_t *)v23;
      if ( v23 != nullptr )
      {
        v23[0] = 52428;
LABEL_20:
        v17 += 4;
      }
    }
    inwbuffer = v17;
    goto LABEL_23;
  }
  inwbuffer = nullptr;
LABEL_23:
  if ( inwbuffer == nullptr )
    return 0;
  if ( MultiByteToWideChar(
         CodePage: code_page,
         dwFlags: 1u,
         lpMultiByteStr: lpSrcStr,
         cbMultiByte: cchSrc,
         lpWideCharStr: inwbuffer,
         cchWideChar: v13) != 0 )
  {
    retval = LCMapStringW(Locale, dwMapFlags, lpSrcStr: inwbuffer, cchSrc: v13, lpDestStr: nullptr, cchDest: 0);
    if ( retval != 0 )
    {
      if ( (dwMapFlags & 0x400) != 0 )
      {
        if ( cchDest != 0 && retval <= cchDest )
          LCMapStringW(Locale, dwMapFlags, lpSrcStr: inwbuffer, cchSrc: v13, (LPWSTR)lpDestStr, cchDest);
        goto LABEL_46;
      }
      if ( retval <= 0 || 0xFFFFFFE0 / retval < 2 )
      {
        v20 = nullptr;
LABEL_39:
        if ( v20 != nullptr )
        {
          if ( LCMapStringW(
                 Locale,
                 dwMapFlags,
                 lpSrcStr: inwbuffer,
                 cchSrc: inbuff_size,
                 lpDestStr: v20,
                 cchDest: retval) != 0 )
          {
            if ( cchDest != 0 )
              v22 = WideCharToMultiByte(
                      CodePage: code_page,
                      dwFlags: 0,
                      lpWideCharStr: v20,
                      cchWideChar: retval,
                      lpMultiByteStr: lpDestStr,
                      cbMultiByte: cchDest,
                      lpDefaultChar: nullptr,
                      lpUsedDefaultChar: nullptr);
            else
              v22 = WideCharToMultiByte(
                      CodePage: code_page,
                      dwFlags: 0,
                      lpWideCharStr: v20,
                      cchWideChar: retval,
                      lpMultiByteStr: nullptr,
                      cbMultiByte: 0,
                      lpDefaultChar: nullptr,
                      lpUsedDefaultChar: nullptr);
            retval = v22;
          }
          _freea(_Memory: v20);
        }
        goto LABEL_46;
      }
      v18 = 2 * retval + 8;
      if ( v18 > 0x400 )
      {
        v21 = (wchar_t *)MemAlloc_Alloc(nSize: 2 * retval + 8);
        if ( v21 != nullptr )
        {
          *(_DWORD *)v21 = 56797;
          v21 += 4;
        }
        v20 = v21;
        goto LABEL_39;
      }
      v19 = alloca(v18);
      if ( v23 != nullptr )
      {
        v23[0] = 52428;
        v20 = (wchar_t *)&v24;
        goto LABEL_39;
      }
    }
  }
LABEL_46:
  _freea(_Memory: inwbuffer);
  return retval;
}

//------------------------------------------------------------------------------
// Address: 0x102FD9B1
// Name: ___crtLCMapStringA
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl __crtLCMapStringA(
        localeinfo_struct *plocinfo,
        LCID Locale,
        DWORD dwMapFlags,
        const char *lpSrcStr,
        int cchSrc,
        char *lpDestStr,
        int cchDest,
        UINT code_page,
        int bError)
{
  int result; // eax
  _LocaleUpdate _loc_update; // [esp+0h] [ebp-10h] BYREF

  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  result = _crtLCMapStringA_stat(
             plocinfo: &_loc_update.localeinfo,
             Locale,
             dwMapFlags,
             lpSrcStr,
             cchSrc,
             lpDestStr,
             cchDest,
             code_page,
             bError);
  if ( _loc_update.updated )
    _loc_update.ptd->_ownlocale &= ~2u;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102FDA00
// Name: _strlen
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl strlen(char *buf)
{
  char *v1; // ecx
  char v2; // al
  int v3; // eax
  int v4; // eax

  v1 = buf;
  if ( ((unsigned __int8)buf & 3) != 0 )
  {
    while ( 1 )
    {
      v2 = *v1++;
      if ( v2 == 0 )
        break;
      if ( ((unsigned __int8)v1 & 3) == 0 )
        goto main_loop_2;
    }
  }
  else
  {
    do
    {
      do
      {
main_loop_2:
        v3 = (*(_DWORD *)v1 + 2130640639) ^ ~*(_DWORD *)v1;
        v1 += 4;
      }
      while ( (v3 & 0x81010100) == 0 );
      v4 = *((_DWORD *)v1 - 1);
    }
    while ( (_BYTE)v4 != 0 && BYTE1(v4) != 0 && (v4 & 0xFF0000) != 0 && (v4 & 0xFF000000) != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x102FDA8B
// Name: __input_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _input_l(_iobuf *stream, unsigned __int8 *format, localeinfo_struct *plocinfo, char *arglist)
{
  int result; // eax
  int v5; // eax
  ioinfo *v6; // ecx
  ioinfo *v7; // eax
  unsigned __int8 v8; // al
  const unsigned __int8 *v9; // edi
  int v10; // eax
  int v11; // ebx
  unsigned __int8 v12; // cl
  const unsigned __int8 *v13; // eax
  _WORD *v14; // esi
  unsigned __int8 v15; // al
  int v16; // ebx
  int v17; // eax
  int v18; // edi
  int v19; // ebx
  int v20; // ebx
  int i; // eax
  int v22; // eax
  int v23; // eax
  int j; // eax
  int v25; // eax
  int v26; // eax
  int v27; // eax
  int k; // eax
  int v29; // eax
  void (__cdecl *v30)(int, void *, char *, _LocaleUpdate *); // eax
  _WORD *v31; // edi
  int v32; // eax
  int v33; // eax
  unsigned __int8 *v34; // esi
  unsigned __int8 v35; // dl
  unsigned __int8 v36; // cl
  unsigned int v37; // edi
  int v38; // edx
  unsigned __int8 v39; // al
  int v40; // eax
  unsigned __int64 v41; // kr00_8
  unsigned int v42; // edi
  unsigned int v43; // esi
  int v44; // edi
  int v45; // ebx
  int v46; // eax
  int v47; // eax
  int v48; // ecx
  bool v49; // zf
  int v50; // [esp-14h] [ebp-21Ch]
  void *v51; // [esp-10h] [ebp-218h]
  char *v52; // [esp-Ch] [ebp-214h]
  char *arglistsave; // [esp+8h] [ebp-200h]
  _LocaleUpdate _loc_update; // [esp+Ch] [ebp-1FCh] BYREF
  int wctemp; // [esp+1Ch] [ebp-1ECh] BYREF
  char *v56; // [esp+20h] [ebp-1E8h]
  unsigned int number; // [esp+24h] [ebp-1E4h]
  char temp[4]; // [esp+28h] [ebp-1E0h] BYREF
  unsigned int nFloatStrSz; // [esp+2Ch] [ebp-1DCh] BYREF
  int integer64; // [esp+30h] [ebp-1D8h]
  unsigned __int8 prevchar; // [esp+37h] [ebp-1D1h]
  int malloc_FloatStrFlag; // [esp+38h] [ebp-1D0h] BYREF
  int count; // [esp+3Ch] [ebp-1CCh]
  unsigned __int64 num64; // [esp+40h] [ebp-1C8h]
  void *pointer; // [esp+48h] [ebp-1C0h]
  const unsigned __int8 *v66; // [esp+4Ch] [ebp-1BCh]
  int widthset; // [esp+50h] [ebp-1B8h]
  int comchr; // [esp+54h] [ebp-1B4h]
  char *pFloatStr; // [esp+58h] [ebp-1B0h] BYREF
  int started; // [esp+5Ch] [ebp-1ACh]
  char decimal; // [esp+60h] [ebp-1A8h]
  char negative; // [esp+61h] [ebp-1A7h]
  char fl_wchar_arg; // [esp+62h] [ebp-1A6h]
  char match; // [esp+63h] [ebp-1A5h]
  _iobuf *fileptr; // [esp+64h] [ebp-1A4h]
  char suppress; // [esp+6Bh] [ebp-19Dh]
  int width; // [esp+6Ch] [ebp-19Ch]
  char widechar; // [esp+73h] [ebp-195h]
  char chr[4]; // [esp+74h] [ebp-194h]
  char done_flag; // [esp+7Bh] [ebp-18Dh]
  int charcount; // [esp+7Ch] [ebp-18Ch] BYREF
  unsigned __int8 last; // [esp+83h] [ebp-185h]
  char floatstring[352]; // [esp+84h] [ebp-184h] BYREF
  char AsciiTable[32]; // [esp+1E4h] [ebp-24h] BYREF

  v56 = arglist;
  fileptr = stream;
  pFloatStr = floatstring;
  nFloatStrSz = 350;
  malloc_FloatStrFlag = 0;
  wctemp = 0;
  *(_DWORD *)chr = 0;
  if ( format == nullptr
    || stream == nullptr
    || (stream->_flag & 0x40) == 0
    && ((v5 = fileno(stream)) == -1 || v5 == -2 ? (v6 = &__badioinfo) : (v6 = &__pioinfo[v5 >> 5][v5 & 0x1F]),
        (*((_BYTE *)v6 + 36) & 0x7F) != 0
     || (v5 == -1 || v5 == -2 ? (v7 = &__badioinfo) : (v7 = &__pioinfo[v5 >> 5][v5 & 0x1F]), *((char *)v7 + 36) < 0)) )
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return -1;
  }
  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  v8 = *format;
  match = 0;
  charcount = 0;
  count = 0;
  if ( v8 == 0 )
    goto LABEL_288;
  v9 = format;
  while ( 2 )
  {
    if ( isspace(c: v8) != 0 )
    {
      --charcount;
      v10 = whiteout(counter: &charcount, fileptr);
      if ( v10 != -1 )
        _ungetc_nolock(ch: v10, str: fileptr);
      do
        ++v9;
      while ( isspace(c: *v9) != 0 );
      goto LABEL_272;
    }
    if ( *v9 != 37 )
      goto LABEL_264;
    if ( v9[1] == 37 )
    {
      ++v9;
LABEL_264:
      ++charcount;
      v45 = inc(fileptr);
      v46 = *v9++;
      *(_DWORD *)chr = v45;
      v66 = v9;
      if ( v46 == v45 )
      {
        if ( isleadbyte(c: v45) == 0 )
          goto LABEL_268;
        ++charcount;
        v47 = inc(fileptr);
        v48 = *v9++;
        v66 = v9;
        if ( v48 == v47 )
        {
          --charcount;
          goto LABEL_268;
        }
        if ( v47 != -1 )
          _ungetc_nolock(ch: v47, str: fileptr);
      }
      v49 = v45 == -1;
      goto LABEL_278;
    }
    number = 0;
    prevchar = 0;
    started = 0;
    widthset = 0;
    width = 0;
    decimal = 0;
    negative = 0;
    suppress = 0;
    done_flag = 0;
    fl_wchar_arg = 0;
    widechar = 0;
    last = 1;
    integer64 = 0;
    do
    {
      v11 = *++v9;
      if ( isdigit(c: (unsigned __int8)v11) != 0 )
      {
        ++widthset;
        width = 10 * width + v11 - 48;
        continue;
      }
      if ( v11 > 78 )
      {
        if ( v11 == 104 )
        {
          --last;
          --widechar;
        }
        else
        {
          if ( v11 == 108 )
          {
            v13 = v9 + 1;
            if ( v9[1] == 108 )
              goto LABEL_37;
            ++last;
          }
          else if ( v11 != 119 )
          {
            goto DEFAULT_LABEL;
          }
          ++widechar;
        }
      }
      else
      {
        switch ( v11 )
        {
          case 'N':
            continue;
          case '*':
            ++suppress;
            continue;
          case 'F':
            continue;
          default:
            break;
        }
        if ( v11 != 73 )
        {
          if ( v11 == 76 )
          {
            ++last;
            continue;
          }
DEFAULT_LABEL:
          ++done_flag;
          continue;
        }
        v12 = v9[1];
        if ( v12 == 54 )
        {
          v13 = v9 + 2;
          if ( v9[2] == 52 )
          {
LABEL_37:
            ++integer64;
            v9 = v13;
            num64 = 0;
            continue;
          }
        }
        if ( v12 == 51 && v9[2] == 50 )
        {
          v9 += 2;
          continue;
        }
        if ( v12 != 100 && v12 != 105 && v12 != 111 && v12 != 120 && v12 != 88 )
          goto DEFAULT_LABEL;
      }
    }
    while ( done_flag == 0 );
    v66 = v9;
    if ( suppress != 0 )
    {
      v14 = nullptr;
    }
    else
    {
      v14 = *(_WORD **)v56;
      arglistsave = v56;
      v56 += 4;
    }
    pointer = v14;
    done_flag = 0;
    if ( widechar == 0 )
    {
      v15 = *v9;
      if ( *v9 == 83 || (widechar = -1, v15 == 67) )
        widechar = 1;
    }
    v16 = *v9 | 0x20;
    comchr = v16;
    if ( v16 != 110 )
    {
      if ( v16 == 99 || v16 == 123 )
      {
        ++charcount;
        v17 = inc(fileptr);
      }
      else
      {
        v17 = whiteout(counter: &charcount, fileptr);
      }
      *(_DWORD *)chr = v17;
      if ( v17 == -1 )
        goto error_return_0;
      v14 = pointer;
      v9 = v66;
    }
    if ( widthset != 0 && width == 0 )
      goto LABEL_274;
    if ( v16 > 111 )
    {
      switch ( v16 )
      {
        case 'p':
          last = 1;
          break;
        case 's':
LABEL_129:
          if ( widechar > 0 )
            fl_wchar_arg = 1;
          goto scanit;
        case 'u':
          break;
        case 'x':
          goto LABEL_84;
        case '{':
          if ( widechar > 0 )
            fl_wchar_arg = 1;
          v34 = (unsigned __int8 *)(v9 + 1);
          if ( v9[1] == 94 )
          {
            v34 = (unsigned __int8 *)(v9 + 2);
            decimal = -1;
          }
          memset(dst: (int)AsciiTable, value: nullptr, count: sizeof(AsciiTable));
          if ( *v34 == 93 )
          {
            v35 = 93;
            ++v34;
            AsciiTable[11] = 32;
          }
          else
          {
            v35 = prevchar;
          }
          while ( 1 )
          {
            v39 = *v34;
            if ( *v34 == 93 )
              break;
            ++v34;
            if ( v39 == 45 && v35 != 0 && (v36 = *v34, *v34 != 93) )
            {
              ++v34;
              if ( v35 >= v36 )
              {
                last = v35;
                v35 = v36;
              }
              else
              {
                last = v36;
              }
              if ( v35 < last )
              {
                v37 = v35;
                v38 = (unsigned __int8)(last - v35);
                do
                {
                  AsciiTable[v37 >> 3] |= 1 << (v37 & 7);
                  ++v37;
                  --v38;
                }
                while ( v38 != 0 );
                v16 = comchr;
              }
              AsciiTable[last >> 3] |= 1 << (last & 7);
              v35 = 0;
            }
            else
            {
              v35 = v39;
              AsciiTable[v39 >> 3] |= 1 << (v39 & 7);
              v16 = comchr;
            }
          }
          v66 = v34;
          v14 = pointer;
scanit:
          --charcount;
          v31 = v14;
          if ( *(_DWORD *)chr != -1 )
            _ungetc_nolock(ch: *(int *)chr, str: fileptr);
          while ( 1 )
          {
            if ( widthset != 0 )
            {
              v32 = width--;
              if ( v32 == 0 )
                goto LABEL_202;
            }
            ++charcount;
            v33 = inc(fileptr);
            *(_DWORD *)chr = v33;
            if ( v33 == -1 )
              goto LABEL_200;
            if ( v16 != 99 )
            {
              if ( v16 != 115 )
                goto LABEL_293;
              if ( v33 >= 9 && v33 <= 13 )
              {
LABEL_200:
                --charcount;
                if ( v33 != -1 )
                  _ungetc_nolock(ch: v33, str: fileptr);
LABEL_202:
                if ( v31 != v14 )
                {
                  if ( suppress == 0 )
                  {
                    ++count;
                    if ( v16 != 99 )
                    {
                      if ( fl_wchar_arg != 0 )
                        *(_WORD *)pointer = 0;
                      else
                        *(_BYTE *)pointer = 0;
                    }
                  }
                  goto LABEL_262;
                }
                goto error_return_0;
              }
              if ( v33 == 32 )
              {
LABEL_293:
                if ( v16 != 123 )
                  goto LABEL_200;
                v16 = comchr;
                if ( ((1 << (v33 & 7)) & (decimal ^ AsciiTable[v33 >> 3])) == 0 )
                  goto LABEL_200;
              }
            }
            if ( suppress != 0 )
            {
              v31 = (_WORD *)((char *)v31 + 1);
            }
            else
            {
              if ( fl_wchar_arg != 0 )
              {
                temp[0] = v33;
                if ( isleadbyte(c: v33) != 0 )
                {
                  ++charcount;
                  temp[1] = inc(fileptr);
                }
                wctemp = 63;
                _mbtowc_l(
                  pwc: (wchar_t *)&wctemp,
                  s: temp,
                  n: _loc_update.localeinfo.locinfo->mb_cur_max,
                  plocinfo: &_loc_update.localeinfo);
                *v14++ = wctemp;
              }
              else
              {
                *(_BYTE *)v14 = v33;
                v14 = (_WORD *)((char *)v14 + 1);
              }
              pointer = v14;
            }
          }
        default:
          goto LABEL_153;
      }
LABEL_209:
      v19 = *(_DWORD *)chr;
      if ( *(_DWORD *)chr == 45 )
      {
        negative = 1;
      }
      else if ( *(_DWORD *)chr != 43 )
      {
        goto getnum;
      }
      if ( --width == 0 && widthset != 0 )
      {
        done_flag = 1;
        goto getnum;
      }
      ++charcount;
      v19 = inc(fileptr);
      goto LABEL_216;
    }
    switch ( v16 )
    {
      case 'o':
        goto LABEL_209;
      case 'c':
        if ( widthset == 0 )
        {
          ++width;
          widthset = 1;
        }
        goto LABEL_129;
      case 'd':
        goto LABEL_209;
      default:
        break;
    }
    if ( v16 <= 100 )
      goto LABEL_153;
    if ( v16 <= 103 )
    {
      v20 = 0;
      if ( *(_DWORD *)chr == 45 )
      {
        *pFloatStr = 45;
        v20 = 1;
        goto f_incwidth;
      }
      if ( *(_DWORD *)chr == 43 )
      {
f_incwidth:
        --width;
        ++charcount;
        *(_DWORD *)chr = inc(fileptr);
      }
      if ( widthset == 0 )
        width = -1;
      for ( i = (unsigned __int8)chr[0]; isdigit(c: i) != 0; i = (unsigned __int8)chr[0] )
      {
        v22 = width--;
        if ( v22 == 0 )
          break;
        ++started;
        pFloatStr[v20] = chr[0];
        if ( _check_float_string(
               nFloatStrUsed: ++v20,
               pnFloatStrSz: &nFloatStrSz,
               &pFloatStr,
               floatstring,
               pmalloc_FloatStrFlag: &malloc_FloatStrFlag) == 0 )
          goto error_return_0;
        ++charcount;
        *(_DWORD *)chr = inc(fileptr);
      }
      decimal = *_loc_update.localeinfo.locinfo->lconv->decimal_point;
      if ( decimal == chr[0] )
      {
        v23 = width--;
        if ( v23 != 0 )
        {
          ++charcount;
          *(_DWORD *)chr = inc(fileptr);
          pFloatStr[v20] = decimal;
          if ( _check_float_string(
                 nFloatStrUsed: ++v20,
                 pnFloatStrSz: &nFloatStrSz,
                 &pFloatStr,
                 floatstring,
                 pmalloc_FloatStrFlag: &malloc_FloatStrFlag) == 0 )
            goto error_return_0;
          for ( j = (unsigned __int8)chr[0]; isdigit(c: j) != 0; j = (unsigned __int8)chr[0] )
          {
            v25 = width--;
            if ( v25 == 0 )
              break;
            ++started;
            pFloatStr[v20] = chr[0];
            if ( _check_float_string(
                   nFloatStrUsed: ++v20,
                   pnFloatStrSz: &nFloatStrSz,
                   &pFloatStr,
                   floatstring,
                   pmalloc_FloatStrFlag: &malloc_FloatStrFlag) == 0 )
              goto error_return_0;
            ++charcount;
            *(_DWORD *)chr = inc(fileptr);
          }
        }
      }
      if ( started != 0 && (*(_DWORD *)chr == 101 || *(_DWORD *)chr == 69) )
      {
        v26 = width--;
        if ( v26 != 0 )
        {
          pFloatStr[v20] = 101;
          if ( _check_float_string(
                 nFloatStrUsed: ++v20,
                 pnFloatStrSz: &nFloatStrSz,
                 &pFloatStr,
                 floatstring,
                 pmalloc_FloatStrFlag: &malloc_FloatStrFlag) == 0 )
            goto error_return_0;
          ++charcount;
          *(_DWORD *)chr = inc(fileptr);
          if ( *(_DWORD *)chr == 45 )
          {
            pFloatStr[v20] = 45;
            if ( _check_float_string(
                   nFloatStrUsed: ++v20,
                   pnFloatStrSz: &nFloatStrSz,
                   &pFloatStr,
                   floatstring,
                   pmalloc_FloatStrFlag: &malloc_FloatStrFlag) == 0 )
              goto error_return_0;
f_incwidth2:
            v27 = width--;
            if ( v27 != 0 )
            {
              ++charcount;
              *(_DWORD *)chr = inc(fileptr);
            }
            else
            {
              width = 0;
            }
          }
          else if ( *(_DWORD *)chr == 43 )
          {
            goto f_incwidth2;
          }
          for ( k = (unsigned __int8)chr[0]; isdigit(c: k) != 0; k = (unsigned __int8)chr[0] )
          {
            v29 = width--;
            if ( v29 == 0 )
              break;
            ++started;
            pFloatStr[v20] = chr[0];
            if ( _check_float_string(
                   nFloatStrUsed: ++v20,
                   pnFloatStrSz: &nFloatStrSz,
                   &pFloatStr,
                   floatstring,
                   pmalloc_FloatStrFlag: &malloc_FloatStrFlag) == 0 )
              goto error_return_0;
            ++charcount;
            *(_DWORD *)chr = inc(fileptr);
          }
        }
      }
      --charcount;
      if ( *(_DWORD *)chr != -1 )
        _ungetc_nolock(ch: *(int *)chr, str: fileptr);
      if ( started != 0 )
      {
        if ( suppress == 0 )
        {
          ++count;
          v52 = pFloatStr;
          v51 = pointer;
          pFloatStr[v20] = 0;
          v50 = (char)last - 1;
          v30 = (void (__cdecl *)(int, void *, char *, _LocaleUpdate *))DecodePointer(Ptr: off_1042D240);
          v30(a1: v50, a2: v51, a3: v52, a4: &_loc_update);
        }
        goto LABEL_262;
      }
      goto error_return_0;
    }
    if ( v16 != 105 )
    {
      if ( v16 == 110 )
      {
        v18 = charcount;
        if ( suppress == 0 )
        {
assign_num:
          if ( integer64 != 0 )
          {
            *(_QWORD *)v14 = num64;
          }
          else if ( last != 0 )
          {
            *(_DWORD *)v14 = v18;
          }
          else
          {
            *v14 = v18;
          }
        }
        goto LABEL_262;
      }
LABEL_153:
      if ( *v9 == *(_DWORD *)chr )
      {
        --match;
        if ( suppress == 0 )
          v56 = arglistsave;
        goto LABEL_262;
      }
LABEL_274:
      v49 = *(_DWORD *)chr == -1;
LABEL_278:
      if ( !v49 )
        _ungetc_nolock(ch: *(int *)chr, str: fileptr);
      goto error_return_0;
    }
    comchr = 100;
LABEL_84:
    v19 = *(_DWORD *)chr;
    if ( *(_DWORD *)chr == 45 )
    {
      negative = 1;
      goto x_incwidth;
    }
    if ( *(_DWORD *)chr == 43 )
    {
x_incwidth:
      if ( --width != 0 || widthset == 0 )
      {
        ++charcount;
        v19 = inc(fileptr);
        *(_DWORD *)chr = v19;
      }
      else
      {
        done_flag = 1;
      }
    }
    if ( v19 == 48 )
    {
      ++charcount;
      v40 = inc(fileptr);
      v19 = v40;
      *(_DWORD *)chr = v40;
      if ( (_BYTE)v40 != 120 && (_BYTE)v40 != 88 )
      {
        started = 1;
        if ( comchr != 120 )
        {
          if ( widthset != 0 && --width == 0 )
            ++done_flag;
          comchr = 111;
          goto getnum;
        }
        --charcount;
        if ( v40 != -1 )
          _ungetc_nolock(ch: v40, str: fileptr);
        v19 = 48;
LABEL_216:
        *(_DWORD *)chr = v19;
        goto getnum;
      }
      ++charcount;
      v19 = inc(fileptr);
      *(_DWORD *)chr = v19;
      if ( widthset != 0 )
      {
        width -= 2;
        if ( width < 1 )
          ++done_flag;
      }
      comchr = 120;
    }
getnum:
    if ( integer64 == 0 )
    {
      v18 = number;
      if ( done_flag == 0 )
      {
        while ( 1 )
        {
          if ( comchr == 120 || comchr == 112 )
          {
            if ( isxdigit(c: (unsigned __int8)v19) == 0 )
            {
LABEL_248:
              --charcount;
              if ( v19 != -1 )
                _ungetc_nolock(ch: v19, str: fileptr);
              break;
            }
            v44 = 16 * v18;
            v19 = hextodec(chr: v19);
            *(_DWORD *)chr = v19;
          }
          else
          {
            if ( isdigit(c: (unsigned __int8)v19) == 0 )
              goto LABEL_248;
            if ( comchr == 111 )
            {
              if ( v19 >= 56 )
                goto LABEL_248;
              v44 = 8 * v18;
            }
            else
            {
              v44 = 10 * v18;
            }
          }
          ++started;
          v18 = v44 + v19 - 48;
          if ( widthset != 0 && --width == 0 )
            break;
          ++charcount;
          v19 = inc(fileptr);
          *(_DWORD *)chr = v19;
        }
      }
      if ( negative != 0 )
        v18 = -v18;
      goto LABEL_252;
    }
    if ( done_flag != 0 )
      goto LABEL_233;
    while ( 2 )
    {
      if ( comchr != 120 && comchr != 112 )
      {
        if ( isdigit(c: (unsigned __int8)v19) == 0 )
          break;
        if ( comchr == 111 )
        {
          if ( v19 >= 56 )
            break;
          v41 = 8 * num64;
        }
        else
        {
          v41 = 10 * num64;
        }
        goto LABEL_228;
      }
      if ( isxdigit(c: (unsigned __int8)v19) != 0 )
      {
        v42 = num64 >> 28;
        v43 = 16 * num64;
        v19 = hextodec(chr: v19);
        *(_DWORD *)chr = v19;
        v41 = __PAIR64__(v42, v43);
LABEL_228:
        ++started;
        num64 = v19 - 48 + v41;
        if ( widthset != 0 && --width == 0 )
          goto LABEL_233;
        ++charcount;
        v19 = inc(fileptr);
        *(_DWORD *)chr = v19;
        continue;
      }
      break;
    }
    --charcount;
    if ( v19 != -1 )
      _ungetc_nolock(ch: v19, str: fileptr);
LABEL_233:
    v18 = number;
    if ( negative != 0 )
      num64 = -(__int64)num64;
LABEL_252:
    if ( comchr == 70 )
      started = 0;
    if ( started == 0 )
      goto error_return_0;
    if ( suppress == 0 )
    {
      ++count;
      v14 = pointer;
      goto assign_num;
    }
LABEL_262:
    ++match;
    v9 = ++v66;
LABEL_268:
    if ( *(_DWORD *)chr != -1 )
    {
LABEL_272:
      v8 = *v9;
      if ( *v9 == 0 )
        goto error_return_0;
      continue;
    }
    break;
  }
  if ( *v9 == 37 && v66[1] == 110 )
  {
    v9 = v66;
    goto LABEL_272;
  }
error_return_0:
  if ( malloc_FloatStrFlag == 1 )
    free(pMem: pFloatStr);
  if ( *(_DWORD *)chr == -1 )
  {
    result = count;
    if ( count == 0 && match == 0 )
      result = -1;
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
    return result;
  }
LABEL_288:
  if ( _loc_update.updated )
    _loc_update.ptd->_ownlocale &= ~2u;
  return count;
}

//------------------------------------------------------------------------------
// Address: 0x102FEA8F
// Name: __check_float_string
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall _check_float_string@<eax>(
        unsigned int *pnFloatStrSz@<esi>,
        char **pFloatStr@<edi>,
        unsigned int nFloatStrUsed,
        char *floatstring,
        int *pmalloc_FloatStrFlag)
{
  unsigned int v5; // eax
  unsigned __int8 *v6; // eax
  unsigned __int8 *v8; // eax

  v5 = *pnFloatStrSz;
  if ( nFloatStrUsed == *pnFloatStrSz )
  {
    if ( *pFloatStr == floatstring )
    {
      v6 = calloc(count: v5, size: 2u);
      *pFloatStr = (char *)v6;
      if ( v6 == nullptr )
        return 0;
      *pmalloc_FloatStrFlag = 1;
      memcpy(dst: (unsigned __int8 *)*pFloatStr, src: (unsigned __int8 *)floatstring, count: *pnFloatStrSz);
    }
    else
    {
      v8 = _recalloc_crt(ptr: *pFloatStr, count: v5, size: 2u);
      if ( v8 == nullptr )
        return 0;
      *pFloatStr = (char *)v8;
    }
    *pnFloatStrSz *= 2;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x102FEAE6
// Name: _hextodec
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __cdecl hextodec(unsigned __int8 chr)
{
  bool v1; // zf
  unsigned int result; // eax

  v1 = isdigit(c: chr) == 0;
  result = (char)chr;
  if ( v1 )
    return ((char)chr & 0xFFFFFFDF) - 7;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102FEB06
// Name: _inc
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __fastcall inc(int a1, _iobuf *fileptr)
{
  if ( --fileptr->_cnt < 0 )
    return _filbuf(str: fileptr);
  return *(unsigned __int8 *)fileptr->_ptr++;
}

//------------------------------------------------------------------------------
// Address: 0x102FEB1C
// Name: _whiteout
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall whiteout@<eax>(int *counter@<esi>, int a2@<ecx>, _iobuf *fileptr)
{
  int v3; // ebx
  int v4; // eax
  int v6; // [esp-4h] [ebp-8h]

  do
  {
    ++*counter;
    v3 = inc(a1: a2, fileptr);
    if ( v3 == -1 )
      break;
    v4 = isspace(c: (unsigned __int8)v3);
    a2 = v6;
  }
  while ( v4 != 0 );
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x102FEB46
// Name: __input_s_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _input_s_l(_iobuf *stream, const unsigned __int8 *format, localeinfo_struct *plocinfo, char *arglist)
{
  int result; // eax
  int v5; // eax
  ioinfo *v6; // ecx
  ioinfo *v7; // eax
  unsigned __int8 v8; // al
  int v9; // eax
  const unsigned __int8 *v10; // esi
  const unsigned __int8 *v11; // esi
  int v12; // ebx
  int v13; // eax
  int v14; // ecx
  unsigned __int8 *v15; // eax
  _BYTE *v16; // ebx
  unsigned __int8 v17; // al
  int v18; // edi
  int v19; // eax
  int v20; // ecx
  unsigned int v21; // eax
  unsigned int v22; // eax
  int v23; // ebx
  int v24; // ebx
  int i; // eax
  int v26; // eax
  int v27; // ecx
  int v28; // eax
  int j; // eax
  int v30; // eax
  int v31; // ecx
  int v32; // eax
  int v33; // ecx
  int v34; // ecx
  int v35; // eax
  int k; // eax
  int v37; // eax
  int v38; // ecx
  void (__cdecl *v39)(int, void *, char *, _LocaleUpdate *); // eax
  _BYTE *v40; // esi
  int v41; // eax
  int v42; // eax
  unsigned __int8 *v43; // esi
  unsigned __int8 v44; // dl
  unsigned __int8 v45; // cl
  unsigned int v46; // edi
  int v47; // edx
  unsigned __int8 v48; // al
  int v49; // eax
  int v50; // ecx
  int v51; // eax
  int v52; // ecx
  int v53; // eax
  int v54; // ecx
  unsigned int v55; // eax
  int v56; // ebx
  int v57; // eax
  int v58; // eax
  int v59; // ecx
  bool v60; // zf
  int *v61; // eax
  int v62; // [esp-14h] [ebp-220h]
  void *v63; // [esp-10h] [ebp-21Ch]
  char *v64; // [esp-Ch] [ebp-218h]
  int v65; // [esp-8h] [ebp-214h]
  int v66; // [esp-8h] [ebp-214h]
  int v67; // [esp-8h] [ebp-214h]
  int v68; // [esp-8h] [ebp-214h]
  int v69; // [esp-8h] [ebp-214h]
  int v70; // [esp-8h] [ebp-214h]
  int v71; // [esp-8h] [ebp-214h]
  int v72; // [esp-8h] [ebp-214h]
  int v73; // [esp-8h] [ebp-214h]
  int v74; // [esp-8h] [ebp-214h]
  int v75; // [esp-8h] [ebp-214h]
  _LocaleUpdate _loc_update; // [esp+8h] [ebp-204h] BYREF
  int format_error; // [esp+18h] [ebp-1F4h]
  int wctemp; // [esp+1Ch] [ebp-1F0h] BYREF
  char *arglistsave; // [esp+20h] [ebp-1ECh]
  int comchr; // [esp+24h] [ebp-1E8h]
  char *v81; // [esp+28h] [ebp-1E4h]
  char temp[4]; // [esp+2Ch] [ebp-1E0h] BYREF
  int integer64; // [esp+30h] [ebp-1DCh]
  unsigned int nFloatStrSz; // [esp+34h] [ebp-1D8h] BYREF
  unsigned __int8 prevchar; // [esp+3Bh] [ebp-1D1h]
  int malloc_FloatStrFlag; // [esp+3Ch] [ebp-1D0h] BYREF
  unsigned int array_width; // [esp+40h] [ebp-1CCh]
  int count; // [esp+44h] [ebp-1C8h]
  unsigned int number; // [esp+48h] [ebp-1C4h]
  int widthset; // [esp+4Ch] [ebp-1C0h]
  void *pointer; // [esp+50h] [ebp-1BCh]
  unsigned __int64 num64; // [esp+54h] [ebp-1B8h]
  const unsigned __int8 *v93; // [esp+5Ch] [ebp-1B0h]
  int started; // [esp+60h] [ebp-1ACh]
  char *pFloatStr; // [esp+64h] [ebp-1A8h] BYREF
  char negative; // [esp+68h] [ebp-1A4h]
  char decimal; // [esp+69h] [ebp-1A3h]
  char match; // [esp+6Ah] [ebp-1A2h]
  char fl_wchar_arg; // [esp+6Bh] [ebp-1A1h]
  _iobuf *fileptr; // [esp+6Ch] [ebp-1A0h]
  int width; // [esp+70h] [ebp-19Ch]
  char suppress; // [esp+76h] [ebp-196h]
  char widechar; // [esp+77h] [ebp-195h]
  char chr[4]; // [esp+78h] [ebp-194h]
  char done_flag; // [esp+7Fh] [ebp-18Dh]
  int charcount; // [esp+80h] [ebp-18Ch] BYREF
  unsigned __int8 last; // [esp+87h] [ebp-185h]
  char floatstring[352]; // [esp+88h] [ebp-184h] BYREF
  char AsciiTable[32]; // [esp+1E8h] [ebp-24h] BYREF

  v81 = arglist;
  fileptr = stream;
  v93 = format;
  pFloatStr = floatstring;
  nFloatStrSz = 350;
  malloc_FloatStrFlag = 0;
  wctemp = 0;
  *(_DWORD *)chr = 0;
  format_error = 0;
  if ( format == nullptr
    || stream == nullptr
    || (stream->_flag & 0x40) == 0
    && ((v5 = fileno(stream)) == -1 || v5 == -2 ? (v6 = &__badioinfo) : (v6 = &__pioinfo[v5 >> 5][v5 & 0x1F]),
        (*((_BYTE *)v6 + 36) & 0x7F) != 0
     || (v5 == -1 || v5 == -2 ? (v7 = &__badioinfo) : (v7 = &__pioinfo[v5 >> 5][v5 & 0x1F]), *((char *)v7 + 36) < 0)) )
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return -1;
  }
  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  v8 = *format;
  match = 0;
  charcount = 0;
  count = 0;
  if ( v8 == 0 )
    goto LABEL_307;
  while ( 2 )
  {
    if ( isspace(c: v8) != 0 )
    {
      --charcount;
      v9 = whiteout(counter: &charcount, a2: v65, fileptr);
      if ( v9 != -1 )
        _ungetc_nolock(ch: v9, str: fileptr);
      v10 = v93;
      do
        ++v10;
      while ( isspace(c: *v10) != 0 );
      v93 = v10;
      goto LABEL_279;
    }
    v11 = v93;
    if ( *v93 != 37 )
      goto LABEL_271;
    if ( v93[1] == 37 )
    {
      v11 = v93 + 1;
LABEL_271:
      ++charcount;
      v56 = inc(a1: v65, fileptr);
      v57 = *v11;
      v10 = v11 + 1;
      *(_DWORD *)chr = v56;
      v93 = v10;
      if ( v57 == v56 )
      {
        if ( isleadbyte(c: v56) == 0 )
          goto LABEL_275;
        ++charcount;
        v58 = inc(a1: v75, fileptr);
        v59 = *v10++;
        v93 = v10;
        if ( v59 == v58 )
        {
          --charcount;
          goto LABEL_275;
        }
        if ( v58 != -1 )
          _ungetc_nolock(ch: v58, str: fileptr);
      }
      v60 = v56 == -1;
LABEL_295:
      if ( !v60 )
        _ungetc_nolock(ch: *(int *)chr, str: fileptr);
      goto error_return_1;
    }
    number = 0;
    prevchar = 0;
    started = 0;
    widthset = 0;
    width = 0;
    array_width = 0;
    decimal = 0;
    negative = 0;
    suppress = 0;
    done_flag = 0;
    fl_wchar_arg = 0;
    widechar = 0;
    last = 1;
    integer64 = 0;
    do
    {
      v12 = *++v11;
      v13 = isdigit(c: (unsigned __int8)v12);
      v14 = v66;
      if ( v13 != 0 )
      {
        ++widthset;
        width = 10 * width + v12 - 48;
        continue;
      }
      if ( v12 > 78 )
      {
        if ( v12 == 104 )
        {
          --last;
          --widechar;
        }
        else
        {
          if ( v12 == 108 )
          {
            v15 = (unsigned __int8 *)(v11 + 1);
            if ( v11[1] == 108 )
              goto LABEL_37;
            ++last;
          }
          else if ( v12 != 119 )
          {
            goto DEFAULT_LABEL_0;
          }
          ++widechar;
        }
      }
      else
      {
        switch ( v12 )
        {
          case 'N':
            continue;
          case '*':
            ++suppress;
            continue;
          case 'F':
            continue;
          default:
            break;
        }
        if ( v12 != 73 )
        {
          if ( v12 == 76 )
          {
            ++last;
            continue;
          }
DEFAULT_LABEL_0:
          ++done_flag;
          continue;
        }
        LOBYTE(v14) = v11[1];
        if ( (_BYTE)v14 == 54 )
        {
          v15 = (unsigned __int8 *)(v11 + 2);
          if ( v11[2] == 52 )
          {
LABEL_37:
            ++integer64;
            v11 = v15;
            num64 = 0;
            continue;
          }
        }
        if ( (_BYTE)v14 == 51 && v11[2] == 50 )
        {
          v11 += 2;
          continue;
        }
        if ( (_BYTE)v14 != 100 && (_BYTE)v14 != 105 && (_BYTE)v14 != 111 && (_BYTE)v14 != 120 && (_BYTE)v14 != 88 )
          goto DEFAULT_LABEL_0;
      }
    }
    while ( done_flag == 0 );
    v93 = v11;
    if ( suppress != 0 )
    {
      v16 = nullptr;
    }
    else
    {
      v16 = *(_BYTE **)v81;
      arglistsave = v81;
      v81 += 4;
    }
    pointer = v16;
    done_flag = 0;
    if ( widechar == 0 )
    {
      v17 = *v11;
      if ( *v11 == 83 || (widechar = -1, v17 == 67) )
        widechar = 1;
    }
    v18 = *v11 | 0x20;
    comchr = v18;
    if ( v18 != 110 )
    {
      if ( v18 == 99 || v18 == 123 )
      {
        ++charcount;
        v19 = inc(a1: v14, fileptr);
      }
      else
      {
        v19 = whiteout(counter: &charcount, a2: v14, fileptr);
      }
      *(_DWORD *)chr = v19;
      if ( v19 == -1 )
        goto error_return_1;
      v16 = pointer;
      v11 = v93;
      v18 = comchr;
    }
    v20 = widthset;
    if ( widthset != 0 && width == 0 )
    {
      v60 = *(_DWORD *)chr == -1;
      goto LABEL_295;
    }
    if ( suppress == 0 && (v18 == 99 || v18 == 115 || v18 == 123) )
    {
      v16 = *(_BYTE **)arglistsave;
      arglistsave += 4;
      v81 = arglistsave + 4;
      v21 = *(_DWORD *)arglistsave;
      pointer = v16;
      array_width = v21;
      if ( v21 == 0 )
      {
        if ( widechar <= 0 )
          *v16 = 0;
        else
          *(_WORD *)v16 = 0;
        *_errno() = 12;
        goto error_return_1;
      }
    }
    if ( v18 > 111 )
    {
      if ( v18 == 112 )
      {
        last = 1;
        goto LABEL_218;
      }
      if ( v18 != 115 )
      {
        if ( v18 == 117 )
          goto LABEL_218;
        if ( v18 == 120 )
          goto LABEL_89;
        if ( v18 != 123 )
          goto LABEL_162;
        if ( widechar > 0 )
          fl_wchar_arg = 1;
        v43 = (unsigned __int8 *)(v11 + 1);
        if ( *v43 == 94 )
        {
          ++v43;
          decimal = -1;
        }
        memset(dst: (int)AsciiTable, value: nullptr, count: sizeof(AsciiTable));
        if ( *v43 == 93 )
        {
          v44 = 93;
          ++v43;
          AsciiTable[11] = 32;
        }
        else
        {
          v44 = prevchar;
        }
        while ( 1 )
        {
          v48 = *v43;
          if ( *v43 == 93 )
            break;
          ++v43;
          if ( v48 == 45 && v44 != 0 && (v45 = *v43, *v43 != 93) )
          {
            ++v43;
            if ( v44 >= v45 )
            {
              last = v44;
              v44 = v45;
            }
            else
            {
              last = v45;
            }
            if ( v44 < last )
            {
              v46 = v44;
              v47 = (unsigned __int8)(last - v44);
              do
              {
                AsciiTable[v46 >> 3] |= 1 << (v46 & 7);
                ++v46;
                --v47;
              }
              while ( v47 != 0 );
            }
            v20 = last & 7;
            AsciiTable[last >> 3] |= 1 << v20;
            v44 = 0;
          }
          else
          {
            v44 = v48;
            v20 = v48 & 7;
            AsciiTable[v48 >> 3] |= 1 << (v48 & 7);
          }
        }
        v16 = pointer;
        v18 = comchr;
        v93 = v43;
scanit_0:
        --charcount;
        v40 = v16;
        if ( *(_DWORD *)chr != -1 )
        {
          _ungetc_nolock(ch: *(int *)chr, str: fileptr);
          v20 = v68;
        }
        if ( v18 == 99 )
        {
          while ( 1 )
          {
LABEL_140:
            if ( widthset != 0 )
            {
              v41 = width--;
              if ( v41 == 0 )
                goto LABEL_211;
            }
            ++charcount;
            v42 = inc(a1: v20, fileptr);
            *(_DWORD *)chr = v42;
            if ( v42 == -1 )
              goto LABEL_209;
            if ( v18 != 99 )
            {
              if ( v18 != 115 )
                goto LABEL_312;
              if ( v42 >= 9 && v42 <= 13 )
              {
LABEL_209:
                --charcount;
                if ( v42 != -1 )
                  _ungetc_nolock(ch: v42, str: fileptr);
LABEL_211:
                if ( v40 != v16 )
                {
                  if ( suppress == 0 )
                  {
                    ++count;
                    if ( comchr != 99 )
                    {
                      if ( fl_wchar_arg != 0 )
                        *(_WORD *)pointer = 0;
                      else
                        *(_BYTE *)pointer = 0;
                    }
                  }
                  goto LABEL_269;
                }
                goto error_return_1;
              }
              if ( v42 == 32 )
              {
LABEL_312:
                if ( v18 != 123 )
                  goto LABEL_209;
                v20 = decimal ^ AsciiTable[v42 >> 3];
                if ( ((1 << (v42 & 7)) & v20) == 0 )
                  goto LABEL_209;
                v18 = comchr;
              }
            }
            if ( suppress == 0 )
              break;
            ++v40;
          }
          if ( array_width == 0 )
          {
            v61 = _errno();
            v60 = fl_wchar_arg == 0;
            *v61 = 12;
            if ( v60 )
              *v40 = 0;
            else
              *(_WORD *)v40 = 0;
            goto error_return_1;
          }
          if ( fl_wchar_arg != 0 )
          {
            temp[0] = v42;
            if ( isleadbyte(c: v42) != 0 )
            {
              ++charcount;
              temp[1] = inc(a1: v69, fileptr);
            }
            wctemp = 63;
            _mbtowc_l(
              pwc: (wchar_t *)&wctemp,
              s: temp,
              n: _loc_update.localeinfo.locinfo->mb_cur_max,
              plocinfo: &_loc_update.localeinfo);
            *(_WORD *)v16 = wctemp;
            v16 += 2;
          }
          else
          {
            *v16++ = v42;
          }
          pointer = v16;
        }
        --array_width;
        goto LABEL_140;
      }
LABEL_134:
      if ( widechar > 0 )
        fl_wchar_arg = 1;
      goto scanit_0;
    }
    if ( v18 == 111 )
      goto LABEL_218;
    if ( v18 == 99 )
    {
      if ( widthset == 0 )
      {
        ++width;
        widthset = 1;
      }
      goto LABEL_134;
    }
    if ( v18 != 100 )
    {
      if ( v18 > 100 )
      {
        if ( v18 > 103 )
        {
          if ( v18 != 105 )
          {
            if ( v18 == 110 )
            {
              v22 = charcount;
              if ( suppress == 0 )
              {
assign_num_0:
                if ( integer64 != 0 )
                {
                  *(_QWORD *)v16 = num64;
                }
                else if ( last != 0 )
                {
                  *(_DWORD *)v16 = v22;
                }
                else
                {
                  *(_WORD *)v16 = v22;
                }
              }
              goto LABEL_269;
            }
            goto LABEL_162;
          }
          v18 = 100;
LABEL_89:
          v23 = *(_DWORD *)chr;
          if ( *(_DWORD *)chr == 45 )
          {
            negative = 1;
            goto x_incwidth_0;
          }
          if ( *(_DWORD *)chr == 43 )
          {
x_incwidth_0:
            if ( --width != 0 || widthset == 0 )
            {
              ++charcount;
              v23 = inc(a1: widthset, fileptr);
              *(_DWORD *)chr = v23;
            }
            else
            {
              done_flag = 1;
            }
          }
          if ( v23 == 48 )
          {
            ++charcount;
            v49 = inc(a1: v20, fileptr);
            v23 = v49;
            *(_DWORD *)chr = v49;
            if ( (_BYTE)v49 == 120 || (_BYTE)v49 == 88 )
            {
              ++charcount;
              v23 = inc(a1: v50, fileptr);
              *(_DWORD *)chr = v23;
              if ( widthset != 0 )
              {
                width -= 2;
                if ( width < 1 )
                  ++done_flag;
              }
              v70 = 120;
LABEL_205:
              v18 = v70;
            }
            else
            {
              started = 1;
              if ( v18 != 120 )
              {
                if ( widthset != 0 && --width == 0 )
                  ++done_flag;
                v70 = 111;
                goto LABEL_205;
              }
              --charcount;
              if ( v49 != -1 )
                _ungetc_nolock(ch: v49, str: fileptr);
              v23 = 48;
LABEL_225:
              *(_DWORD *)chr = v23;
            }
          }
          goto getnum_0;
        }
        v24 = 0;
        if ( *(_DWORD *)chr == 45 )
        {
          *pFloatStr = 45;
          v24 = 1;
          goto f_incwidth_0;
        }
        if ( *(_DWORD *)chr == 43 )
        {
f_incwidth_0:
          --width;
          ++charcount;
          *(_DWORD *)chr = inc(a1: v20, fileptr);
        }
        if ( widthset == 0 )
          width = -1;
        for ( i = (unsigned __int8)chr[0]; isdigit(c: i) != 0; i = (unsigned __int8)chr[0] )
        {
          v26 = width--;
          if ( v26 == 0 )
            break;
          ++started;
          pFloatStr[v24] = chr[0];
          if ( _check_float_string(
                 pnFloatStrSz: &nFloatStrSz,
                 &pFloatStr,
                 nFloatStrUsed: ++v24,
                 floatstring,
                 pmalloc_FloatStrFlag: &malloc_FloatStrFlag) == 0 )
            goto error_return_1;
          ++charcount;
          *(_DWORD *)chr = inc(a1: v27, fileptr);
        }
        decimal = *_loc_update.localeinfo.locinfo->lconv->decimal_point;
        if ( decimal == chr[0] )
        {
          v28 = width--;
          if ( v28 != 0 )
          {
            ++charcount;
            *(_DWORD *)chr = inc(a1: v67, fileptr);
            pFloatStr[v24] = decimal;
            if ( _check_float_string(
                   pnFloatStrSz: &nFloatStrSz,
                   &pFloatStr,
                   nFloatStrUsed: ++v24,
                   floatstring,
                   pmalloc_FloatStrFlag: &malloc_FloatStrFlag) == 0 )
              goto error_return_1;
            for ( j = (unsigned __int8)chr[0]; isdigit(c: j) != 0; j = (unsigned __int8)chr[0] )
            {
              v30 = width--;
              if ( v30 == 0 )
                break;
              ++started;
              pFloatStr[v24] = chr[0];
              if ( _check_float_string(
                     pnFloatStrSz: &nFloatStrSz,
                     &pFloatStr,
                     nFloatStrUsed: ++v24,
                     floatstring,
                     pmalloc_FloatStrFlag: &malloc_FloatStrFlag) == 0 )
                goto error_return_1;
              ++charcount;
              *(_DWORD *)chr = inc(a1: v31, fileptr);
            }
          }
        }
        if ( started != 0 && (*(_DWORD *)chr == 101 || *(_DWORD *)chr == 69) )
        {
          v32 = width--;
          if ( v32 != 0 )
          {
            pFloatStr[v24] = 101;
            if ( _check_float_string(
                   pnFloatStrSz: &nFloatStrSz,
                   &pFloatStr,
                   nFloatStrUsed: ++v24,
                   floatstring,
                   pmalloc_FloatStrFlag: &malloc_FloatStrFlag) == 0 )
              goto error_return_1;
            ++charcount;
            *(_DWORD *)chr = inc(a1: v33, fileptr);
            if ( *(_DWORD *)chr == 45 )
            {
              pFloatStr[v24] = 45;
              if ( _check_float_string(
                     pnFloatStrSz: &nFloatStrSz,
                     &pFloatStr,
                     nFloatStrUsed: ++v24,
                     floatstring,
                     pmalloc_FloatStrFlag: &malloc_FloatStrFlag) == 0 )
                goto error_return_1;
f_incwidth2_0:
              v35 = width--;
              if ( v35 != 0 )
              {
                ++charcount;
                *(_DWORD *)chr = inc(a1: v34, fileptr);
              }
              else
              {
                width = 0;
              }
            }
            else if ( *(_DWORD *)chr == 43 )
            {
              goto f_incwidth2_0;
            }
            for ( k = (unsigned __int8)chr[0]; isdigit(c: k) != 0; k = (unsigned __int8)chr[0] )
            {
              v37 = width--;
              if ( v37 == 0 )
                break;
              ++started;
              pFloatStr[v24] = chr[0];
              if ( _check_float_string(
                     pnFloatStrSz: &nFloatStrSz,
                     &pFloatStr,
                     nFloatStrUsed: ++v24,
                     floatstring,
                     pmalloc_FloatStrFlag: &malloc_FloatStrFlag) == 0 )
                goto error_return_1;
              ++charcount;
              *(_DWORD *)chr = inc(a1: v38, fileptr);
            }
          }
        }
        --charcount;
        if ( *(_DWORD *)chr != -1 )
          _ungetc_nolock(ch: *(int *)chr, str: fileptr);
        if ( started != 0 )
        {
          if ( suppress == 0 )
          {
            ++count;
            v64 = pFloatStr;
            v63 = pointer;
            pFloatStr[v24] = 0;
            v62 = (char)last - 1;
            v39 = (void (__cdecl *)(int, void *, char *, _LocaleUpdate *))DecodePointer(Ptr: off_1042D240);
            v39(a1: v62, a2: v63, a3: v64, a4: &_loc_update);
          }
          goto LABEL_269;
        }
        goto error_return_1;
      }
LABEL_162:
      if ( *v11 == *(_DWORD *)chr )
      {
        --match;
        if ( suppress == 0 )
          v81 = arglistsave;
        goto LABEL_269;
      }
      if ( *(_DWORD *)chr != -1 )
        _ungetc_nolock(ch: *(int *)chr, str: fileptr);
      format_error = 1;
      goto error_return_1;
    }
LABEL_218:
    v23 = *(_DWORD *)chr;
    if ( *(_DWORD *)chr == 45 )
    {
      negative = 1;
    }
    else if ( *(_DWORD *)chr != 43 )
    {
      goto getnum_0;
    }
    if ( --width != 0 || widthset == 0 )
    {
      ++charcount;
      v23 = inc(a1: widthset, fileptr);
      goto LABEL_225;
    }
    done_flag = 1;
getnum_0:
    if ( integer64 == 0 )
    {
      if ( done_flag == 0 )
      {
        while ( 1 )
        {
          if ( v18 == 120 || v18 == 112 )
          {
            if ( isxdigit(c: (unsigned __int8)v23) == 0 )
            {
LABEL_257:
              --charcount;
              if ( v23 != -1 )
                _ungetc_nolock(ch: v23, str: fileptr);
              break;
            }
            number *= 16;
            v23 = hextodec(chr: v23);
            v55 = number;
            v54 = v74;
            *(_DWORD *)chr = v23;
          }
          else
          {
            v53 = isdigit(c: (unsigned __int8)v23);
            v54 = v73;
            if ( v53 == 0 )
              goto LABEL_257;
            if ( v18 == 111 )
            {
              if ( v23 >= 56 )
                goto LABEL_257;
              v55 = 8 * number;
            }
            else
            {
              v55 = 10 * number;
            }
          }
          ++started;
          number = v55 + v23 - 48;
          if ( widthset != 0 && --width == 0 )
            break;
          ++charcount;
          v23 = inc(a1: v54, fileptr);
          *(_DWORD *)chr = v23;
        }
      }
      if ( negative != 0 )
        number = -number;
      goto LABEL_261;
    }
    if ( done_flag != 0 )
      goto LABEL_242;
    while ( 2 )
    {
      if ( v18 != 120 && v18 != 112 )
      {
        v51 = isdigit(c: (unsigned __int8)v23);
        v52 = v71;
        if ( v51 == 0 )
          break;
        if ( v18 == 111 )
        {
          if ( v23 >= 56 )
            break;
          v52 = num64 >> 29;
          num64 *= 8LL;
        }
        else
        {
          num64 *= 10LL;
        }
        goto LABEL_237;
      }
      if ( isxdigit(c: (unsigned __int8)v23) != 0 )
      {
        num64 *= 16LL;
        v23 = hextodec(chr: v23);
        v52 = v72;
        *(_DWORD *)chr = v23;
LABEL_237:
        ++started;
        num64 += v23 - 48;
        if ( widthset != 0 && --width == 0 )
          goto LABEL_242;
        ++charcount;
        v23 = inc(a1: v52, fileptr);
        *(_DWORD *)chr = v23;
        continue;
      }
      break;
    }
    --charcount;
    if ( v23 != -1 )
      _ungetc_nolock(ch: v23, str: fileptr);
LABEL_242:
    if ( negative != 0 )
      num64 = -(__int64)num64;
LABEL_261:
    if ( started == 0 )
      goto error_return_1;
    if ( suppress == 0 )
    {
      ++count;
      v16 = pointer;
      v22 = number;
      goto assign_num_0;
    }
LABEL_269:
    ++match;
    v10 = ++v93;
LABEL_275:
    if ( *(_DWORD *)chr != -1 )
    {
LABEL_279:
      v8 = *v10;
      if ( *v10 == 0 )
        goto error_return_1;
      continue;
    }
    break;
  }
  if ( *v10 == 37 && v93[1] == 110 )
  {
    v10 = v93;
    goto LABEL_279;
  }
error_return_1:
  if ( malloc_FloatStrFlag == 1 )
    free(pMem: pFloatStr);
  if ( *(_DWORD *)chr == -1 )
  {
    result = count;
    if ( count == 0 && match == 0 )
      result = -1;
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
    return result;
  }
  if ( format_error == 1 )
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
  }
LABEL_307:
  if ( _loc_update.updated )
    _loc_update.ptd->_ownlocale &= ~2u;
  return count;
}

//------------------------------------------------------------------------------
// Address: 0x102FFC69
// Name: _iswctype
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl iswctype(unsigned __int16 c, unsigned __int16 mask)
{
  unsigned __int16 v3; // ax
  int d; // [esp+0h] [ebp-4h] BYREF

  if ( c == 0xFFFF )
    return 0;
  if ( c >= 0x100u )
  {
    if ( !GetStringTypeW(dwInfoType: 1u, lpSrcStr: &c, cchSrc: 1, lpCharType: (LPWORD)&d) )
      d = 0;
    v3 = d;
  }
  else
  {
    v3 = _pwctype[c];
  }
  return mask & v3;
}

//------------------------------------------------------------------------------
// Address: 0x102FFCBE
// Name: __fullpath
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char *__cdecl _fullpath(char *UserBuf, const char *path, DWORD maxlen)
{
  DWORD FullPathNameA; // eax
  DWORD LastError; // eax
  unsigned int v6; // edi
  unsigned __int8 *v7; // eax
  char *v8; // ebx
  DWORD v9; // eax
  char *pfname; // [esp+Ch] [ebp-4h] BYREF

  if ( path == nullptr || *path == 0 )
    return _getcwd(pnbuf: UserBuf, maxlen);
  if ( UserBuf != nullptr )
  {
    v6 = maxlen;
    if ( maxlen == 0 )
    {
      *_errno() = 22;
      _invalid_parameter_noinfo();
      return nullptr;
    }
    v8 = UserBuf;
  }
  else
  {
    FullPathNameA = GetFullPathNameA(lpFileName: path, nBufferLength: 0, lpBuffer: nullptr, lpFilePart: nullptr);
    if ( FullPathNameA == 0 )
    {
LABEL_5:
      LastError = GetLastError();
      _dosmaperr(oserrno: LastError);
      return nullptr;
    }
    v6 = maxlen;
    if ( maxlen <= FullPathNameA )
      v6 = FullPathNameA;
    v7 = calloc(count: v6, size: 1u);
    v8 = (char *)v7;
    if ( v7 == nullptr )
    {
      *_errno() = 12;
      return nullptr;
    }
  }
  v9 = GetFullPathNameA(lpFileName: path, nBufferLength: v6, lpBuffer: v8, lpFilePart: &pfname);
  if ( v9 >= v6 )
  {
    if ( UserBuf == nullptr )
      free(pMem: v8);
    *_errno() = 34;
    return nullptr;
  }
  if ( v9 == 0 )
  {
    if ( UserBuf == nullptr )
      free(pMem: v8);
    goto LABEL_5;
  }
  return v8;
}

//------------------------------------------------------------------------------
// Address: 0x102FFDB5
// Name: ___dtoxmode
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __cdecl __dtoxmode(char attr, const char *name)
{
  const char *v2; // ecx
  char v3; // dl
  int v4; // edi
  unsigned int v5; // edi
  const unsigned __int8 *v6; // eax
  const unsigned __int8 *v7; // esi

  v2 = name;
  if ( name[1] == 58 )
    v2 = name + 2;
  v3 = *v2;
  if ( (*v2 == 92 || v3 == 47) && v2[1] == 0 || (attr & 0x10) != 0 || (v4 = 0x8000, v3 == 0) )
    v4 = 16448;
  v5 = ~(attr << 7) & 0x80 | 0x100 | v4;
  v6 = _mbsrchr(str: (const unsigned __int8 *)name, c: 0x2Eu);
  v7 = v6;
  if ( v6 != nullptr
    && (_mbsicmp(s1: v6, s2: ".exe") == 0
     || _mbsicmp(s1: v7, s2: ".cmd") == 0
     || _mbsicmp(s1: v7, s2: ".bat") == 0
     || _mbsicmp(s1: v7, s2: ".com") == 0) )
  {
    v5 |= 0x40u;
  }
  return (v5 >> 3) & 0x38 | v5 | (((v5 >> 3) & 0x38 | v5) >> 6) & 7;
}

//------------------------------------------------------------------------------
// Address: 0x102FFE72
// Name: __fstat64i32
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _fstat64i32(int fildes, _stat64i32 *buf)
{
  int v3; // edi
  DWORD v4; // eax
  DWORD LastError; // eax
  unsigned __int16 v6; // cx
  unsigned int v7; // ecx
  BOOL v8; // eax
  unsigned __int16 st_mode; // ax
  unsigned __int16 v10; // ax
  _FILETIME LocalFileTime; // [esp+14h] [ebp-74h] BYREF
  int fh; // [esp+1Ch] [ebp-6Ch]
  unsigned int TotalBytesAvail; // [esp+20h] [ebp-68h] BYREF
  int v14; // [esp+24h] [ebp-64h]
  _BY_HANDLE_FILE_INFORMATION FileInformation; // [esp+28h] [ebp-60h] BYREF
  _SYSTEMTIME SystemTime; // [esp+5Ch] [ebp-2Ch] BYREF
  int v17; // [esp+84h] [ebp-4h]

  fh = fildes;
  v14 = 0;
  if ( buf == nullptr )
  {
    *__doserrno() = 0;
    *_errno() = 22;
LABEL_3:
    _invalid_parameter_noinfo();
    return -1;
  }
  memset(dst: (int)buf, value: nullptr, count: sizeof(_stat64i32));
  if ( fildes == -2 )
  {
    *__doserrno() = 0;
    *_errno() = 9;
    return -1;
  }
  if ( fildes < 0
    || fildes >= _nhandle
    || (TotalBytesAvail = (unsigned int)&__pioinfo[fildes >> 5],
        v3 = (fildes & 0x1F) << 6,
        (*(_BYTE *)(*(_DWORD *)TotalBytesAvail + v3 + 4) & 1) == 0) )
  {
    *__doserrno() = 0;
    *_errno() = 9;
    goto LABEL_3;
  }
  __lock_fhandle(fh);
  v17 = 0;
  if ( (*(_BYTE *)(*(_DWORD *)TotalBytesAvail + v3 + 4) & 1) == 0 )
    goto LABEL_12;
  v4 = GetFileType(hFile: *(HANDLE *)(*(_DWORD *)TotalBytesAvail + ((fildes & 0x1F) << 6))) & 0xFFFF7FFF;
  switch ( v4 )
  {
    case 1u:
      buf->st_mode = 0;
      buf->st_gid = 0;
      buf->st_uid = 0;
      buf->st_ino = 0;
      buf->st_nlink = 1;
      if ( GetFileInformationByHandle(
             hFile: *(HANDLE *)(*(_DWORD *)TotalBytesAvail + ((fildes & 0x1F) << 6)),
             lpFileInformation: &FileInformation) )
      {
        st_mode = buf->st_mode;
        if ( (FileInformation.dwFileAttributes & 1) != 0 )
          v10 = st_mode | 0x124;
        else
          v10 = st_mode | 0x1B6;
        buf->st_mode = v10;
        if ( FileInformation.ftLastWriteTime.dwLowDateTime != 0 || FileInformation.ftLastWriteTime.dwHighDateTime != 0 )
        {
          if ( !FileTimeToLocalFileTime(lpFileTime: &FileInformation.ftLastWriteTime, lpLocalFileTime: &LocalFileTime)
            || !FileTimeToSystemTime(lpFileTime: &LocalFileTime, lpSystemTime: &SystemTime) )
          {
            goto LABEL_13;
          }
          buf->st_mtime = __loctotime64_t(
                            yr: SystemTime.wYear,
                            mo: SystemTime.wMonth,
                            dy: SystemTime.wDay,
                            hr: SystemTime.wHour,
                            mn: SystemTime.wMinute,
                            sc: SystemTime.wSecond,
                            dstflag: -1);
        }
        else
        {
          buf->st_mtime = 0;
        }
        if ( FileInformation.ftLastAccessTime.dwLowDateTime != 0 || FileInformation.ftLastAccessTime.dwHighDateTime != 0 )
        {
          if ( !FileTimeToLocalFileTime(lpFileTime: &FileInformation.ftLastAccessTime, lpLocalFileTime: &LocalFileTime)
            || !FileTimeToSystemTime(lpFileTime: &LocalFileTime, lpSystemTime: &SystemTime) )
          {
            goto LABEL_13;
          }
          buf->st_atime = __loctotime64_t(
                            yr: SystemTime.wYear,
                            mo: SystemTime.wMonth,
                            dy: SystemTime.wDay,
                            hr: SystemTime.wHour,
                            mn: SystemTime.wMinute,
                            sc: SystemTime.wSecond,
                            dstflag: -1);
        }
        else
        {
          buf->st_atime = buf->st_mtime;
        }
        if ( FileInformation.ftCreationTime.dwLowDateTime != 0 || FileInformation.ftCreationTime.dwHighDateTime != 0 )
        {
          if ( !FileTimeToLocalFileTime(lpFileTime: &FileInformation.ftCreationTime, lpLocalFileTime: &LocalFileTime)
            || !FileTimeToSystemTime(lpFileTime: &LocalFileTime, lpSystemTime: &SystemTime) )
          {
            goto LABEL_13;
          }
          buf->st_ctime = __loctotime64_t(
                            yr: SystemTime.wYear,
                            mo: SystemTime.wMonth,
                            dy: SystemTime.wDay,
                            hr: SystemTime.wHour,
                            mn: SystemTime.wMinute,
                            sc: SystemTime.wSecond,
                            dstflag: -1);
        }
        else
        {
          buf->st_ctime = buf->st_mtime;
        }
        buf->st_size = FileInformation.nFileSizeLow;
        buf->st_mode |= 0x8000u;
        buf->st_dev = 0;
        buf->st_rdev = 0;
        goto done;
      }
      goto LABEL_19;
    case 2u:
      v6 = 0x2000;
LABEL_22:
      buf->st_mode = v6;
      v7 = fh;
      buf->st_dev = fh;
      buf->st_rdev = v7;
      buf->st_nlink = 1;
      buf->st_ino = 0;
      buf->st_gid = 0;
      buf->st_uid = 0;
      buf->st_ctime = 0;
      buf->st_mtime = 0;
      buf->st_atime = 0;
      if ( v4 == 2 )
      {
        buf->st_size = 0;
      }
      else
      {
        v8 = PeekNamedPipe(
               hNamedPipe: *(HANDLE *)(*(_DWORD *)TotalBytesAvail + ((fildes & 0x1F) << 6)),
               lpBuffer: nullptr,
               nBufferSize: 0,
               lpBytesRead: nullptr,
               lpTotalBytesAvail: &TotalBytesAvail,
               lpBytesLeftThisMessage: nullptr);
        buf->st_size = v8 ? TotalBytesAvail : 0;
      }
      goto done;
    case 3u:
      v6 = 4096;
      goto LABEL_22;
    default:
      break;
  }
  if ( v4 != 0 )
  {
LABEL_19:
    LastError = GetLastError();
    _dosmaperr(oserrno: LastError);
    goto LABEL_13;
  }
LABEL_12:
  *_errno() = 9;
LABEL_13:
  v14 = -1;
done:
  v17 = -2;
  _unlock_fhandle(fh);
  return v14;
}

//------------------------------------------------------------------------------
// Address: 0x103001C4
// Name: _tsopen_nolock
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall tsopen_nolock@<eax>(
        int *pfh@<eax>,
        unsigned int a2@<edi>,
        int *punlock_flag,
        const char *path,
        int oflag,
        int shflag,
        char pmode)
{
  unsigned int v8; // eax
  int v10; // eax
  char *v11; // eax
  DWORD v12; // eax
  DWORD FileType; // eax
  char *p_osfile; // eax
  DWORD LastError; // esi
  char v16; // cl
  _BYTE *v17; // eax
  signed int v18; // edi
  int v19; // eax
  unsigned int v20; // eax
  unsigned int v21; // eax
  int v22; // edi
  __int64 v23; // rax
  int nolock; // eax
  __int64 v25; // rax
  DWORD v26; // eax
  int v27; // ebx
  int v28; // eax
  _BYTE *v29; // eax
  _BYTE *v30; // eax
  bool v31; // zf
  char *v32; // eax
  HANDLE v33; // eax
  DWORD v34; // eax
  char *v35; // eax
  int v36; // [esp-10h] [ebp-48h]
  DWORD v37; // [esp-Ch] [ebp-44h]
  int v38; // [esp-8h] [ebp-40h]
  _SECURITY_ATTRIBUTES SecurityAttributes; // [esp+8h] [ebp-30h] BYREF
  int fmode; // [esp+14h] [ebp-24h] BYREF
  void *osfh; // [esp+18h] [ebp-20h]
  int bom; // [esp+1Ch] [ebp-1Ch] BYREF
  unsigned int filecreate; // [esp+20h] [ebp-18h]
  unsigned int fileshare; // [esp+24h] [ebp-14h]
  unsigned int fileattrib; // [esp+28h] [ebp-10h]
  unsigned int fileaccess; // [esp+2Ch] [ebp-Ch]
  int retvalue; // [esp+30h] [ebp-8h]
  char inputbuf; // [esp+34h] [ebp-4h] BYREF
  char v49; // [esp+35h] [ebp-3h]
  char tmode; // [esp+36h] [ebp-2h]
  char fileflags; // [esp+37h] [ebp-1h]

  fmode = 0;
  tmode = 0;
  retvalue = 0;
  SecurityAttributes.nLength = 12;
  SecurityAttributes.lpSecurityDescriptor = nullptr;
  if ( (oflag & 0x80u) == 0 )
  {
    SecurityAttributes.bInheritHandle = 1;
    fileflags = 0;
  }
  else
  {
    SecurityAttributes.bInheritHandle = 0;
    fileflags = 16;
  }
  if ( _get_fmode(pMode: &fmode) != 0 )
    _invoke_watson(a1: a2);
  if ( (oflag & 0x8000) == 0 && ((oflag & 0x74000) != 0 || fmode != 0x8000) )
    fileflags |= 0x80u;
  if ( (oflag & 3) != 0 )
  {
    if ( (oflag & 3) != 1 )
    {
      if ( (oflag & 3) != 2 )
        goto LABEL_40;
      goto LABEL_13;
    }
    if ( (oflag & 8) != 0 && (oflag & 0x70000) != 0 )
    {
LABEL_13:
      fileaccess = -1073741824;
      goto LABEL_18;
    }
    fileaccess = 0x40000000;
  }
  else
  {
    fileaccess = 0x80000000;
  }
LABEL_18:
  switch ( shflag )
  {
    case 16:
      fileshare = 0;
      break;
    case 32:
      fileshare = 1;
      break;
    case 48:
      fileshare = 2;
      break;
    case 64:
      fileshare = 3;
      break;
    case 128:
      fileshare = fileaccess == 0x80000000;
      break;
    default:
      goto LABEL_40;
  }
  v8 = oflag & 0x700;
  if ( v8 > 0x400 )
  {
    if ( v8 != 1280 )
    {
      if ( v8 == 1536 )
        goto LABEL_41;
      if ( v8 != 1792 )
        goto LABEL_40;
    }
    filecreate = 1;
    goto LABEL_43;
  }
  if ( (oflag & 0x700) == 0x400 || (oflag & 0x700) == 0 )
  {
    filecreate = 3;
    goto LABEL_43;
  }
  if ( v8 == 256 )
  {
    filecreate = 4;
    goto LABEL_43;
  }
  if ( v8 == 512 )
  {
LABEL_41:
    filecreate = 5;
    goto LABEL_43;
  }
  if ( v8 != 768 )
  {
LABEL_40:
    *__doserrno() = 0;
    *pfh = -1;
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return 22;
  }
  filecreate = 2;
LABEL_43:
  fileattrib = 128;
  if ( (oflag & 0x100) != 0 && (pmode & ~(_BYTE)_umaskval & 0x80u) == 0 )
    fileattrib = 1;
  if ( (oflag & 0x40) != 0 )
  {
    fileattrib |= 0x4000000u;
    fileaccess |= 0x10000u;
    fileshare |= 4u;
  }
  if ( (oflag & 0x1000) != 0 )
    fileattrib |= 0x100u;
  if ( (oflag & 0x20) != 0 )
  {
    fileattrib |= 0x8000000u;
  }
  else if ( (oflag & 0x10) != 0 )
  {
    fileattrib |= 0x10000000u;
  }
  v10 = _alloc_osfhnd();
  *pfh = v10;
  if ( v10 == -1 )
  {
    *__doserrno() = 0;
    *pfh = -1;
    *_errno() = 24;
    return *_errno();
  }
  v37 = fileattrib;
  *punlock_flag = 1;
  osfh = CreateFileA(
           lpFileName: path,
           dwDesiredAccess: fileaccess,
           dwShareMode: fileshare,
           lpSecurityAttributes: &SecurityAttributes,
           dwCreationDisposition: filecreate,
           dwFlagsAndAttributes: v37,
           hTemplateFile: nullptr);
  if ( osfh != (void *)-1
    || (fileaccess & 0xC0000000) == 0xC0000000
    && (oflag & 1) != 0
    && (fileaccess &= ~0x80000000,
        (osfh = CreateFileA(
                  lpFileName: path,
                  dwDesiredAccess: fileaccess,
                  dwShareMode: fileshare,
                  lpSecurityAttributes: &SecurityAttributes,
                  dwCreationDisposition: filecreate,
                  dwFlagsAndAttributes: fileattrib,
                  hTemplateFile: nullptr)) != (void *)-1) )
  {
    FileType = GetFileType(hFile: osfh);
    switch ( FileType )
    {
      case 0u:
        p_osfile = &__pioinfo[*pfh >> 5][*pfh & 0x1F].osfile;
        *p_osfile &= ~1u;
        LastError = GetLastError();
        _dosmaperr(oserrno: LastError);
        CloseHandle(hObject: osfh);
        if ( LastError == 0 )
          *_errno() = 13;
        return *_errno();
      case 2u:
        fileflags |= 0x40u;
        break;
      case 3u:
        fileflags |= 8u;
        break;
      default:
        break;
    }
    _set_osfhnd(fh: *pfh, value: (int)osfh);
    v16 = fileflags | 1;
    __pioinfo[*pfh >> 5][*pfh & 0x1F].osfile = fileflags | 1;
    v17 = (char *)&__pioinfo[*pfh >> 5][*pfh & 0x1F] + 36;
    *v17 &= 0x80u;
    v49 = v16 & 0x48;
    fileflags = v16;
    if ( (v16 & 0x48) == 0 )
    {
      if ( v16 >= 0 )
        goto LABEL_131;
      if ( (oflag & 2) != 0 )
      {
        v18 = _lseek_nolock(fh: *pfh, pos: -1, mthd: 2u);
        if ( v18 == -1 )
        {
          if ( *__doserrno() != 131 )
          {
LABEL_74:
            _close_nolock(fh: *pfh);
            return *_errno();
          }
        }
        else
        {
          v36 = *pfh;
          inputbuf = 0;
          if ( _read_nolock(fh: v36, &inputbuf, cnt: 1u) == 0
            && inputbuf == 26
            && _chsize_nolock(filedes: *pfh, size: v18) == -1
            || _lseek_nolock(fh: *pfh, pos: 0, mthd: 0) == -1 )
          {
            goto LABEL_74;
          }
        }
      }
    }
    if ( fileflags >= 0 )
    {
LABEL_131:
      v29 = (char *)&__pioinfo[*pfh >> 5][*pfh & 0x1F] + 36;
      *v29 ^= (tmode ^ *v29) & 0x7F;
      v30 = (char *)&__pioinfo[*pfh >> 5][*pfh & 0x1F] + 36;
      v31 = v49 == 0;
      *v30 = *v30 & 0x7F | (BYTE2(oflag) << 7);
      if ( v31 && (oflag & 8) != 0 )
      {
        v32 = &__pioinfo[*pfh >> 5][*pfh & 0x1F].osfile;
        *v32 |= 0x20u;
      }
      if ( (fileaccess & 0xC0000000) != 0xC0000000 || (oflag & 1) == 0 )
        return retvalue;
      CloseHandle(hObject: osfh);
      v33 = CreateFileA(
              lpFileName: path,
              dwDesiredAccess: fileaccess & 0x7FFFFFFF,
              dwShareMode: fileshare,
              lpSecurityAttributes: &SecurityAttributes,
              dwCreationDisposition: 3u,
              dwFlagsAndAttributes: fileattrib,
              hTemplateFile: nullptr);
      if ( v33 != (HANDLE)-1 )
      {
        __pioinfo[*pfh >> 5][*pfh & 0x1F].osfhnd = (int)v33;
        return retvalue;
      }
      v34 = GetLastError();
      _dosmaperr(oserrno: v34);
      v35 = &__pioinfo[*pfh >> 5][*pfh & 0x1F].osfile;
      *v35 &= ~1u;
      _free_osfhnd(fh: *pfh);
      return *_errno();
    }
    if ( (oflag & 0x74000) == 0 )
    {
      if ( (fmode & 0x74000) != 0 )
        oflag |= fmode & 0x74000;
      else
        oflag |= 0x4000u;
    }
    v19 = oflag & 0x74000;
    if ( (oflag & 0x74000) == 0x4000 )
    {
      tmode = 0;
      goto LABEL_95;
    }
    if ( v19 == 0x10000 || v19 == 81920 )
    {
      if ( (oflag & 0x301) != 0x301 )
        goto LABEL_95;
    }
    else if ( v19 != 0x20000 && v19 != 147456 )
    {
      if ( v19 == 0x40000 || v19 == 278528 )
        tmode = 1;
LABEL_95:
      if ( (oflag & 0x70000) == 0 )
        goto LABEL_131;
      bom = 0;
      if ( (fileflags & 0x40) != 0 )
        goto LABEL_131;
      v20 = fileaccess & 0xC0000000;
      if ( (fileaccess & 0xC0000000) == 0x40000000 )
      {
        v21 = filecreate;
        if ( filecreate == 0 )
          goto LABEL_131;
        if ( filecreate <= 2 )
          goto LABEL_104;
        if ( filecreate > 4 )
          goto LABEL_103;
        if ( _lseeki64_nolock(fh: *pfh, pos: 0, mthd: 2) != 0 )
        {
          v25 = _lseeki64_nolock(fh: *pfh, pos: 0, mthd: 0);
          v26 = HIDWORD(v25) & v25;
          goto LABEL_119;
        }
      }
      else
      {
        if ( v20 == 0x80000000 )
          goto LABEL_109;
        if ( v20 != -1073741824 )
          goto LABEL_131;
        v21 = filecreate;
        if ( filecreate == 0 )
          goto LABEL_131;
        if ( filecreate > 2 )
        {
          if ( filecreate > 4 )
          {
LABEL_103:
            if ( v21 != 5 )
              goto LABEL_131;
            goto LABEL_104;
          }
          if ( _lseeki64_nolock(fh: *pfh, pos: 0, mthd: 2) != 0 )
          {
            v23 = _lseeki64_nolock(fh: *pfh, pos: 0, mthd: 0);
            if ( (HIDWORD(v23) & (unsigned int)v23) == 0xFFFFFFFF )
              goto LABEL_74;
LABEL_109:
            nolock = _read_nolock(fh: *pfh, inputbuf: (char *)&bom, cnt: 3u);
            if ( nolock == -1 )
              goto LABEL_74;
            if ( nolock != 2 )
            {
              if ( nolock != 3 )
              {
LABEL_126:
                v26 = _lseek_nolock(fh: *pfh, pos: 0, mthd: 0);
LABEL_119:
                if ( v26 == -1 )
                  goto LABEL_74;
                goto LABEL_131;
              }
              if ( bom == 12565487 )
              {
                tmode = 1;
                goto LABEL_131;
              }
            }
            if ( (unsigned __int16)bom == 65534 )
            {
              _close_nolock(fh: *pfh);
              *_errno() = 22;
              return 22;
            }
            if ( (unsigned __int16)bom == 65279 )
            {
              if ( _lseek_nolock(fh: *pfh, pos: 2, mthd: 0) == -1 )
                goto LABEL_74;
              tmode = 2;
              goto LABEL_131;
            }
            goto LABEL_126;
          }
        }
      }
LABEL_104:
      v22 = 0;
      if ( tmode == 1 )
      {
        bom = 12565487;
        v38 = 3;
LABEL_128:
        v27 = v38;
        while ( 1 )
        {
          v28 = _write(fh: *pfh, buf: (char *)&bom + v22, cnt: v27 - v22);
          if ( v28 == -1 )
            goto LABEL_74;
          v22 += v28;
          if ( v27 <= v22 )
            goto LABEL_131;
        }
      }
      if ( tmode == 2 )
      {
        bom = 65279;
        v38 = 2;
        goto LABEL_128;
      }
      goto LABEL_131;
    }
    tmode = 2;
    goto LABEL_95;
  }
  v11 = &__pioinfo[*pfh >> 5][*pfh & 0x1F].osfile;
  *v11 &= ~1u;
  v12 = GetLastError();
  _dosmaperr(oserrno: v12);
  return *_errno();
}

//------------------------------------------------------------------------------
// Address: 0x103008F8
// Name: __sopen_helper
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _sopen_helper(const char *path, int oflag, int shflag, int pmode, int *pfh, int bSecure)
{
  int result; // eax
  char *p_osfile; // eax
  int retval; // [esp+14h] [ebp-20h]
  int unlock_flag[6]; // [esp+18h] [ebp-1Ch] BYREF
  int v10; // [esp+30h] [ebp-4h]

  unlock_flag[0] = 0;
  if ( pfh == nullptr || (*pfh = -1, path == nullptr) || bSecure != 0 && (pmode & 0xFFFFFE7F) != 0 )
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return 22;
  }
  else
  {
    v10 = 0;
    retval = tsopen_nolock(pfh, a2: 0, punlock_flag: unlock_flag, path, oflag, shflag, pmode);
    v10 = -2;
    if ( unlock_flag[0] != 0 )
    {
      if ( retval != 0 )
      {
        p_osfile = &__pioinfo[*pfh >> 5][*pfh & 0x1F].osfile;
        *p_osfile &= ~1u;
      }
      _unlock_fhandle(fh: *pfh);
    }
    result = retval;
    if ( retval != 0 )
      *pfh = -1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103009BC
// Name: __sopen_s
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _sopen_s(int *pfh, const char *path, int oflag, int shflag, int pmode)
{
  return _sopen_helper(path, oflag, shflag, pmode, pfh, bSecure: 1);
}

//------------------------------------------------------------------------------
// Address: 0x103009DC
// Name: ___loctotime64_t
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl __loctotime64_t(int yr, int mo, int dy, unsigned int hr, unsigned int mn, unsigned int sc, int dstflag)
{
  int v7; // ebx
  int v8; // esi
  int *v9; // eax
  int v10; // ecx
  unsigned int v11; // edi
  int timezone; // [esp+Ch] [ebp-40h] BYREF
  int dstbias; // [esp+10h] [ebp-3Ch] BYREF
  int v15; // [esp+14h] [ebp-38h]
  int daylight; // [esp+18h] [ebp-34h] BYREF
  int v17; // [esp+1Ch] [ebp-30h]
  int tmpdays; // [esp+20h] [ebp-2Ch]
  tm tb; // [esp+24h] [ebp-28h] BYREF

  v7 = mo;
  v8 = yr - 1900;
  v15 = mo;
  daylight = 0;
  dstbias = 0;
  timezone = 0;
  if ( yr - 1900 < 70
    || v8 > 1100
    || (unsigned int)(mo - 1) > 0xB
    || hr > 0x17
    || mn > 0x3B
    || sc > 0x3B
    || dy < 1
    || (v9 = &_days[mo], v10 = *(v9 - 1), *v9 - v10 < dy)
    && ((v8 % 4 != 0 || v8 % 100 == 0) && yr % 400 != 0 || (v7 = v15, v15 != 2) || dy > 29) )
  {
    *_errno() = 22;
    return -1;
  }
  else
  {
    tmpdays = dy + v10;
    if ( (v8 % 4 == 0 && v8 % 100 != 0 || yr % 400 == 0) && v7 > 2 )
      ++tmpdays;
    __tzset();
    if ( _get_daylight(_Daylight: &daylight) != 0
      || _get_dstbias(_Daylight_savings_bias: &dstbias) != 0
      || _get_timezone(_Timezone: &timezone) != 0 )
    {
      _invoke_watson(a1: 0x190u);
    }
    v17 = (unsigned __int64)(365 * (v8 - 70LL) + (yr - 1900 + 299) / 400 - (yr - 1901) / 100 + (yr - 1901) / 4 - 17) >> 32;
    tb.tm_yday = tmpdays;
    v11 = sc
        + timezone
        + 60
        * (mn
         + 60
         * (hr + 24 * (tmpdays + 365 * (yr - 1970) + (yr - 1900 + 299) / 400 - (yr - 1901) / 100 + (yr - 1901) / 4 - 17)));
    tb.tm_year = yr - 1900;
    tb.tm_mon = v15 - 1;
    tb.tm_hour = hr;
    tb.tm_min = mn;
    tb.tm_sec = sc;
    if ( dstflag == 1 || dstflag == -1 && daylight != 0 && _isindst(&tb) != 0 )
      v11 += dstbias;
    return v11;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10300C43
// Name: __getdrive
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __cdecl _getdrive()
{
  wchar_t *v0; // ebx
  signed int CurrentDirectoryW; // esi
  unsigned __int8 *v2; // eax
  unsigned int v3; // edi
  unsigned int v4; // eax
  int memfree; // [esp+10h] [ebp-214h]
  wchar_t curdirstr[262]; // [esp+14h] [ebp-210h] BYREF

  memfree = 0;
  v0 = curdirstr;
  CurrentDirectoryW = GetCurrentDirectoryW(nBufferLength: 0x105u, lpBuffer: curdirstr);
  if ( CurrentDirectoryW > 260 )
  {
    v2 = calloc(count: CurrentDirectoryW + 1, size: 2u);
    v0 = (wchar_t *)v2;
    if ( v2 != nullptr )
    {
      memfree = 1;
      CurrentDirectoryW = GetCurrentDirectoryW(nBufferLength: CurrentDirectoryW + 1, lpBuffer: (LPWSTR)v2);
    }
    else
    {
      *_errno() = 12;
      CurrentDirectoryW = 0;
    }
  }
  v3 = 0;
  if ( CurrentDirectoryW != 0 )
  {
    if ( v0[1] == 58 )
    {
      v4 = *v0;
      if ( v4 >= 0x61 && v4 <= 0x7A )
        v4 -= 32;
      v3 = v4 - 64;
    }
  }
  else
  {
    *_errno() = 12;
  }
  if ( memfree != 0 )
    free(pMem: v0);
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x10300D11
// Name: __mbctolower_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _mbctolower_l(unsigned int c, localeinfo_struct *plocinfo)
{
  int result; // eax
  _LocaleUpdate _loc_update; // [esp+4h] [ebp-18h] BYREF
  unsigned __int8 ret[4]; // [esp+14h] [ebp-8h] BYREF
  char val[4]; // [esp+18h] [ebp-4h] BYREF

  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  if ( c <= 0xFF )
  {
    if ( (_loc_update.localeinfo.mbcinfo->mbctype[c + 1] & 0x10) != 0 )
      result = _loc_update.localeinfo.mbcinfo->mbcasemap[c];
    else
      result = c;
LABEL_11:
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
    return result;
  }
  val[0] = BYTE1(c);
  val[1] = c;
  if ( (_loc_update.localeinfo.mbcinfo->mbctype[BYTE1(c) + 1] & 4) != 0
    && __crtLCMapStringA(
         plocinfo: &_loc_update.localeinfo,
         Locale: _loc_update.localeinfo.mbcinfo->mblcid,
         dwMapFlags: 0x100u,
         lpSrcStr: val,
         cchSrc: 2,
         lpDestStr: (char *)ret,
         cchDest: 2,
         code_page: _loc_update.localeinfo.mbcinfo->mbcodepage,
         bError: 1) != 0 )
  {
    result = ret[1] + (ret[0] << 8);
    goto LABEL_11;
  }
  if ( _loc_update.updated )
    _loc_update.ptd->_ownlocale &= ~2u;
  return c;
}

//------------------------------------------------------------------------------
// Address: 0x10300DB7
// Name: __mbctolower
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _mbctolower(unsigned int c)
{
  return _mbctolower_l(c, plocinfo: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x10300DCA
// Name: __mbspbrk_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _mbspbrk_l(unsigned __int8 *string, unsigned __int8 *charset, localeinfo_struct *plocinfo)
{
  unsigned __int8 *v3; // ecx
  unsigned __int8 *i; // eax
  unsigned __int8 v5; // dl
  _LocaleUpdate _loc_update; // [esp+8h] [ebp-10h] BYREF

  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  if ( _loc_update.localeinfo.mbcinfo->ismbcodepage == 0 )
  {
    strpbrk(string, control: charset);
LABEL_22:
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
    return;
  }
  v3 = string;
  if ( string != nullptr && charset != nullptr )
  {
    if ( *string != 0 )
    {
      do
      {
        for ( i = charset; *i != 0; ++i )
        {
          v5 = *i;
          if ( (_loc_update.localeinfo.mbcinfo->mbctype[*i + 1] & 4) != 0 )
          {
            if ( v5 == *v3 && i[1] == v3[1] || i[1] == 0 )
              break;
            ++i;
          }
          else if ( v5 == *v3 )
          {
            break;
          }
        }
        if ( *i != 0 )
          break;
        if ( (_loc_update.localeinfo.mbcinfo->mbctype[*v3 + 1] & 4) != 0 && *++v3 == 0 )
          break;
        ++v3;
      }
      while ( *v3 != 0 );
    }
    goto LABEL_22;
  }
  *_errno() = 22;
  _invalid_parameter_noinfo();
  if ( _loc_update.updated )
    _loc_update.ptd->_ownlocale &= ~2u;
}

//------------------------------------------------------------------------------
// Address: 0x10300E8F
// Name: __mbspbrk
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _mbspbrk(unsigned __int8 *string, unsigned __int8 *charset)
{
  _mbspbrk_l(string, charset, plocinfo: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x10300EA6
// Name: _strcpy_s
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl strcpy_s(char *_Dst, unsigned int _SizeInBytes, const char *_Src)
{
  unsigned int v3; // edi
  int v4; // esi
  const char *v6; // eax
  char v7; // cl

  if ( _Dst == nullptr )
    goto LABEL_3;
  v3 = _SizeInBytes;
  if ( _SizeInBytes == 0 )
    goto LABEL_3;
  v6 = _Src;
  if ( _Src == nullptr )
  {
    *_Dst = 0;
LABEL_3:
    v4 = 22;
    *_errno() = 22;
LABEL_4:
    _invalid_parameter_noinfo();
    return v4;
  }
  do
  {
    v7 = *v6;
    v6[_Dst - _Src] = *v6;
    ++v6;
    if ( v7 == 0 )
      break;
    --v3;
  }
  while ( v3 != 0 );
  if ( v3 == 0 )
  {
    *_Dst = 0;
    *_errno() = 34;
    v4 = 34;
    goto LABEL_4;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10300F3B
// Name: __EH_epilog3
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void _EH_epilog3()
{
  __asm { retn }
}

//------------------------------------------------------------------------------
// Address: 0x10300F4F
// Name: _wcslen
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl wcslen(const wchar_t *wcs)
{
  const wchar_t *v1; // eax
  __int16 v2; // cx

  v1 = wcs;
  do
    v2 = *v1++;
  while ( v2 != 0 );
  return v1 - wcs - 1;
}

//------------------------------------------------------------------------------
// Address: 0x10300F6A
// Name: findenv
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall findenv@<eax>(unsigned int len@<edi>, const char *name)
{
  const unsigned __int8 **i; // esi
  unsigned __int8 v3; // al

  for ( i = (const unsigned __int8 **)_environ; ; ++i )
  {
    if ( *i == nullptr )
      return -(((char *)i - (char *)_environ) >> 2);
    if ( _mbsnbicoll(s1: (const unsigned __int8 *)name, s2: *i, n: len) == 0 )
    {
      v3 = (*i)[len];
      if ( v3 == 61 || v3 == 0 )
        break;
    }
  }
  return ((char *)i - (char *)_environ) >> 2;
}

//------------------------------------------------------------------------------
// Address: 0x10300FBC
// Name: copy_environ
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char **__usercall copy_environ@<eax>(char **oldenviron@<eax>)
{
  char **result; // eax
  char **v3; // ecx
  unsigned __int8 *v4; // esi
  char *v5; // eax
  int v6; // edi
  char **newenviron; // [esp+4h] [ebp-4h]

  result = nullptr;
  v3 = oldenviron;
  if ( oldenviron != nullptr )
  {
    if ( *oldenviron != nullptr )
    {
      do
      {
        ++v3;
        result = (char **)((char *)result + 1);
      }
      while ( *v3 != nullptr );
    }
    v4 = calloc(count: (unsigned int)result + 1, size: 4u);
    newenviron = (char **)v4;
    if ( v4 == nullptr )
      _amsg_exit(rterrnum: 9);
    v5 = *oldenviron;
    if ( *oldenviron != nullptr )
    {
      v6 = (char *)oldenviron - (char *)v4;
      do
      {
        *(_DWORD *)v4 = _strdup(string: v5);
        v4 += 4;
        v5 = *(char **)&v4[v6];
      }
      while ( v5 != nullptr );
    }
    *(_DWORD *)v4 = 0;
    return newenviron;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1030101C
// Name: ___crtsetenv
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl __crtsetenv(char **poption, int primary)
{
  const unsigned __int8 *v3; // esi
  const unsigned __int8 *v4; // eax
  const unsigned __int8 *v5; // edi
  char **v6; // eax
  char **v7; // eax
  unsigned __int16 **v8; // eax
  char **v9; // esi
  int v10; // eax
  unsigned int v11; // edi
  char **v12; // esi
  unsigned __int8 *v13; // eax
  char **v14; // ecx
  int v15; // eax
  unsigned __int8 *v16; // edi
  int v17; // eax
  const char *v18; // eax
  const char *equal; // [esp+4h] [ebp-14h]
  char **env; // [esp+8h] [ebp-10h]
  int retval; // [esp+Ch] [ebp-Ch]
  BOOL remove; // [esp+10h] [ebp-8h]
  char *option; // [esp+14h] [ebp-4h]

  retval = 0;
  if ( poption == nullptr )
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return -1;
  }
  v3 = (const unsigned __int8 *)*poption;
  option = *poption;
  if ( *poption == nullptr )
    goto LABEL_12;
  v4 = _mbschr(string: v3, c: 0x3Du);
  v5 = v4;
  equal = (const char *)v4;
  if ( v4 == nullptr || v3 == v4 )
    goto LABEL_12;
  remove = v4[1] == 0;
  v6 = _environ;
  if ( _environ == __initenv )
  {
    v6 = copy_environ(oldenviron: _environ);
    _environ = v6;
  }
  if ( v6 == nullptr )
  {
    if ( primary != 0 && _wenviron != nullptr )
    {
      if ( __wtomb_environ() != 0 )
      {
LABEL_12:
        *_errno() = 22;
        return -1;
      }
    }
    else
    {
      if ( remove )
        return 0;
      v7 = (char **)MemAlloc_Alloc(nSize: 4u);
      _environ = v7;
      if ( v7 == nullptr )
        return -1;
      *v7 = nullptr;
      if ( _wenviron == nullptr )
      {
        v8 = (unsigned __int16 **)MemAlloc_Alloc(nSize: 4u);
        _wenviron = v8;
        if ( v8 == nullptr )
          return -1;
        *v8 = nullptr;
      }
    }
  }
  v9 = _environ;
  env = _environ;
  if ( _environ == nullptr )
    return -1;
  v10 = findenv(len: v5 - (const unsigned __int8 *)option, name: option);
  v11 = v10;
  if ( v10 < 0 || *v9 == nullptr )
  {
    if ( !remove )
    {
      if ( v10 < 0 )
        v11 = -v10;
      if ( (int)(v11 + 2) <= (int)v11 )
        return -1;
      if ( v11 + 2 >= 0x3FFFFFFF )
        return -1;
      v13 = _recalloc_crt(ptr: _environ, count: 4u, size: v11 + 2);
      if ( v13 == nullptr )
        return -1;
      v14 = (char **)&v13[4 * v11];
      *v14 = option;
      v14[1] = nullptr;
      *poption = nullptr;
      goto LABEL_37;
    }
    free(pMem: option);
    *poption = nullptr;
    return 0;
  }
  v12 = &v9[v10];
  free(pMem: *v12);
  if ( !remove )
  {
    *v12 = option;
    *poption = nullptr;
    goto LABEL_38;
  }
  while ( *v12 != nullptr )
  {
    *v12 = v12[1];
    v12 = &env[++v11];
  }
  if ( v11 < 0x3FFFFFFF )
  {
    v13 = _recalloc_crt(ptr: _environ, count: v11, size: 4u);
    if ( v13 == nullptr )
      goto LABEL_38;
LABEL_37:
    _environ = (char **)v13;
  }
LABEL_38:
  if ( primary != 0 )
  {
    strlen(buf: option);
    v16 = calloc(count: v15 + 2, size: 1u);
    if ( v16 != nullptr )
    {
      strlen(buf: option);
      if ( strcpy_s(_Dst: (char *)v16, _SizeInBytes: v17 + 2, _Src: option) != 0 )
        _invoke_watson(a1: (unsigned int)v16);
      v18 = &equal[v16 - (unsigned __int8 *)option];
      *v18 = 0;
      if ( !SetEnvironmentVariableA(lpName: (LPCSTR)v16, lpValue: !remove ? v18 + 1 : nullptr) )
      {
        retval = -1;
        *_errno() = 42;
      }
      free(pMem: v16);
    }
  }
  if ( remove )
  {
    free(pMem: option);
    *poption = nullptr;
  }
  return retval;
}

//------------------------------------------------------------------------------
// Address: 0x1030125E
// Name: _strnlen
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __cdecl strnlen(const char *str, unsigned int maxsize)
{
  unsigned int result; // eax

  for ( result = 0; result < maxsize; ++str )
  {
    if ( *str == 0 )
      break;
    ++result;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1030127B
// Name: __mbschr_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _mbschr_l(char *string, unsigned int c, localeinfo_struct *plocinfo)
{
  char *v3; // eax
  unsigned __int16 v4; // cx
  _LocaleUpdate _loc_update; // [esp+4h] [ebp-10h] BYREF

  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  v3 = string;
  if ( string != nullptr )
  {
    if ( _loc_update.localeinfo.mbcinfo->ismbcodepage != 0 )
    {
      while ( 1 )
      {
        v4 = (unsigned __int8)*v3;
        if ( *v3 == 0 )
          break;
        if ( (_loc_update.localeinfo.mbcinfo->mbctype[(unsigned __int8)v4 + 1] & 4) != 0 )
        {
          if ( *++v3 == 0 )
            goto LABEL_17;
          if ( c == ((unsigned __int8)*v3 | (v4 << 8)) )
            goto LABEL_15;
        }
        else if ( c == (unsigned __int8)*v3 )
        {
          break;
        }
        ++v3;
      }
      if ( c == (unsigned __int8)*v3 )
        goto LABEL_15;
LABEL_17:
      if ( _loc_update.updated )
        _loc_update.ptd->_ownlocale &= ~2u;
    }
    else
    {
      strchr(string, chr: c);
LABEL_15:
      if ( _loc_update.updated )
        _loc_update.ptd->_ownlocale &= ~2u;
    }
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1030132B
// Name: __mbschr
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _mbschr(char *string, unsigned int c)
{
  _mbschr_l(string, c, plocinfo: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x10301342
// Name: __mtinitlocks
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _mtinitlocks()
{
  int v0; // esi
  _RTL_CRITICAL_SECTION *v1; // edi
  LPCRITICAL_SECTION *v2; // eax

  v0 = 0;
  v1 = lclcritsects;
  while ( 1 )
  {
    if ( *(&locktable + 2 * v0 + 1) == (LPCRITICAL_SECTION)1 )
    {
      v2 = &locktable + 2 * v0;
      *v2 = v1++;
      if ( !InitializeCriticalSectionAndSpinCount(lpCriticalSection: *v2, dwSpinCount: 0xFA0u) )
        break;
    }
    if ( ++v0 >= 36 )
      return 1;
  }
  *(&locktable + 2 * v0) = nullptr;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1030138C
// Name: __mtdeletelocks
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void _mtdeletelocks()
{
  LPCRITICAL_SECTION *v0; // esi
  LPCRITICAL_SECTION v1; // edi
  LPCRITICAL_SECTION *v2; // esi

  v0 = &locktable;
  do
  {
    v1 = *v0;
    if ( *v0 != nullptr && v0[1] != (LPCRITICAL_SECTION)1 )
    {
      DeleteCriticalSection(lpCriticalSection: *v0);
      free(pMem: v1);
      *v0 = nullptr;
    }
    v0 += 2;
  }
  while ( (int)v0 < (int)ext_strings );
  v2 = &locktable;
  do
  {
    if ( *v2 != nullptr && v2[1] == (LPCRITICAL_SECTION)1 )
      DeleteCriticalSection(lpCriticalSection: *v2);
    v2 += 2;
  }
  while ( (int)v2 < (int)ext_strings );
}

//------------------------------------------------------------------------------
// Address: 0x103013E3
// Name: __unlock
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _unlock(int locknum)
{
  LeaveCriticalSection(lpCriticalSection: *(&locktable + 2 * locknum));
}

//------------------------------------------------------------------------------
// Address: 0x103013FA
// Name: __mtinitlocknum
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _mtinitlocknum(int locknum)
{
  LPCRITICAL_SECTION *v1; // esi
  _RTL_CRITICAL_SECTION *v3; // edi
  int retval; // [esp+10h] [ebp-1Ch]

  retval = 1;
  if ( _crtheap == nullptr )
  {
    _FF_MSGBANNER();
    _NMSG_WRITE(rterrnum: 30);
    __crtExitProcess(status: 255);
  }
  v1 = &locktable + 2 * locknum;
  if ( *v1 != nullptr )
    return 1;
  v3 = (_RTL_CRITICAL_SECTION *)MemAlloc_Alloc(nSize: 0x18u);
  if ( v3 != nullptr )
  {
    _lock(locknum: 10);
    if ( *v1 != nullptr )
    {
      free(pMem: v3);
    }
    else if ( InitializeCriticalSectionAndSpinCount(lpCriticalSection: v3, dwSpinCount: 0xFA0u) )
    {
      *v1 = v3;
    }
    else
    {
      free(pMem: v3);
      *_errno() = 12;
      retval = 0;
    }
    _unlock(locknum: 10);
    return retval;
  }
  else
  {
    *_errno() = 12;
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x103014BC
// Name: __lock
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _lock(int locknum)
{
  LPCRITICAL_SECTION *v1; // esi

  v1 = &locktable + 2 * locknum;
  if ( *v1 == nullptr && _mtinitlocknum(locknum) == 0 )
    _amsg_exit(rterrnum: 17);
  EnterCriticalSection(lpCriticalSection: *v1);
}

//------------------------------------------------------------------------------
// Address: 0x103014EF
// Name: __mbsnbicoll_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _mbsnbicoll_l(
        const unsigned __int8 *s1,
        const unsigned __int8 *s2,
        unsigned int n,
        localeinfo_struct *plocinfo)
{
  int result; // eax
  int v5; // eax
  _LocaleUpdate _loc_update; // [esp+4h] [ebp-10h] BYREF

  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  if ( n == 0 )
  {
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
    return 0;
  }
  if ( s1 != nullptr && s2 != nullptr )
  {
    if ( n > 0x7FFFFFFF )
    {
      *_errno() = 22;
      _invalid_parameter_noinfo();
LABEL_15:
      if ( _loc_update.updated )
        _loc_update.ptd->_ownlocale &= ~2u;
      return 0x7FFFFFFF;
    }
    if ( _loc_update.localeinfo.mbcinfo->ismbcodepage != 0 )
    {
      v5 = __crtCompareStringA(
             plocinfo: &_loc_update.localeinfo,
             Locale: _loc_update.localeinfo.mbcinfo->mblcid,
             dwCmpFlags: 0x1001u,
             lpString1: (const char *)s1,
             cchCount1: n,
             lpString2: (const char *)s2,
             cchCount2: n,
             code_page: _loc_update.localeinfo.mbcinfo->mbcodepage);
      if ( v5 == 0 )
        goto LABEL_15;
      result = v5 - 2;
    }
    else
    {
      result = _strnicoll_l(_string1: (const char *)s1, _string2: (const char *)s2, count: n, plocinfo);
    }
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
    return 0x7FFFFFFF;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103015CD
// Name: __mbsnbicoll
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _mbsnbicoll(const unsigned __int8 *s1, const unsigned __int8 *s2, unsigned int n)
{
  return _mbsnbicoll_l(s1, s2, n, plocinfo: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x103015E7
// Name: ___wtomb_environ
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl __wtomb_environ()
{
  LPCWCH *v0; // edi
  const wchar_t *v1; // eax
  unsigned int v2; // eax
  unsigned __int8 *v3; // eax
  int size; // [esp+Ch] [ebp-8h]
  char *envp; // [esp+10h] [ebp-4h] BYREF

  v0 = (LPCWCH *)_wenviron;
  envp = nullptr;
  v1 = *_wenviron;
  if ( *_wenviron == nullptr )
    return 0;
  while ( 1 )
  {
    v2 = WideCharToMultiByte(
           CodePage: 0,
           dwFlags: 0,
           lpWideCharStr: v1,
           cchWideChar: -1,
           lpMultiByteStr: nullptr,
           cbMultiByte: 0,
           lpDefaultChar: nullptr,
           lpUsedDefaultChar: nullptr);
    size = v2;
    if ( v2 == 0 )
      break;
    v3 = calloc(count: v2, size: 1u);
    envp = (char *)v3;
    if ( v3 == nullptr )
      break;
    if ( WideCharToMultiByte(
           CodePage: 0,
           dwFlags: 0,
           lpWideCharStr: *v0,
           cchWideChar: -1,
           lpMultiByteStr: (LPSTR)v3,
           cbMultiByte: size,
           lpDefaultChar: nullptr,
           lpUsedDefaultChar: nullptr) == 0 )
    {
      free(pMem: envp);
      return -1;
    }
    if ( __crtsetenv(poption: &envp, primary: 0) < 0 && envp != nullptr )
    {
      free(pMem: envp);
      envp = nullptr;
    }
    v1 = *++v0;
    if ( *v0 == nullptr )
      return 0;
  }
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x1030167E
// Name: comexecmd
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl comexecmd(int mode, const char *name, const char *const *argv, const char *const *envp)
{
  int v5; // esi
  char *envblk; // [esp+0h] [ebp-8h] BYREF
  char *argblk; // [esp+4h] [ebp-4h] BYREF

  if ( name == nullptr || argv == nullptr )
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return -1;
  }
  if ( _cenvarg(argv, envp, &argblk, &envblk, name) == -1 )
    return -1;
  v5 = _dospawn(mode, name, cmdblk: argblk, envblk);
  free(pMem: argblk);
  free(pMem: envblk);
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x103016F0
// Name: __spawnve
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _spawnve(int mode, char *name, const char *const *argv, const char *const *envp)
{
  char *v4; // edi
  const unsigned __int8 *v6; // esi
  const unsigned __int8 *v7; // eax
  const unsigned __int8 *v8; // eax
  int v9; // eax
  unsigned int v10; // esi
  unsigned __int8 *v11; // eax
  char *v12; // ebx
  int v13; // eax
  unsigned int v14; // esi
  unsigned __int8 *v15; // eax
  char *v16; // ebx
  int v17; // eax
  unsigned int v18; // esi
  int save_errno; // [esp+4h] [ebp-10h]
  int rc; // [esp+8h] [ebp-Ch]
  const char **v21; // [esp+Ch] [ebp-8h]
  char *pathname; // [esp+10h] [ebp-4h]

  v4 = name;
  pathname = name;
  if ( name == nullptr || *name == 0 || argv == nullptr || *argv == nullptr || **(_BYTE **)argv == 0 )
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return -1;
  }
  v6 = _mbsrchr(str: (const unsigned __int8 *)name, c: 0x5Cu);
  v7 = _mbsrchr(str: (const unsigned __int8 *)name, c: 0x2Fu);
  if ( v7 != nullptr )
  {
    if ( v6 == nullptr || v7 > v6 )
      v6 = v7;
  }
  else if ( v6 == nullptr )
  {
    _mbschr(string: name, c: 0x3Au);
    v6 = v8;
    if ( v8 == nullptr )
    {
      strlen(buf: name);
      v10 = v9 + 3;
      v11 = calloc(count: v9 + 3, size: 1u);
      v12 = (char *)v11;
      pathname = (char *)v11;
      if ( v11 == nullptr )
        return -1;
      if ( strcpy_s(_Dst: (char *)v11, _SizeInBytes: v10, _Src: ".\\") != 0
        || strcat_s(_Dst: v12, _SizeInBytes: v10, _Src: name) != 0 )
      {
LABEL_14:
        _invoke_watson(a1: (unsigned int)v4);
      }
      v6 = (const unsigned __int8 *)(v12 + 2);
    }
  }
  rc = -1;
  if ( _mbsrchr(str: v6, c: 0x2Eu) == nullptr )
  {
    strlen(buf: pathname);
    v14 = v13 + 5;
    v15 = calloc(count: v13 + 5, size: 1u);
    v16 = (char *)v15;
    v4 = nullptr;
    if ( v15 == nullptr )
      return -1;
    if ( strcpy_s(_Dst: (char *)v15, _SizeInBytes: v14, _Src: pathname) == 0 )
    {
      strlen(buf: pathname);
      v4 = &v16[v17];
      save_errno = *_errno();
      v18 = (unsigned int)&v16[v14 - (_DWORD)v4];
      v21 = (const char **)&ext_strings[3];
      while ( 1 )
      {
        if ( strcpy_s(_Dst: v4, _SizeInBytes: v18, _Src: *v21) != 0 )
          goto LABEL_14;
        if ( _access_s(path: v16, amode: 0) == 0 )
          break;
        if ( (int)--v21 < (int)ext_strings )
          goto LABEL_30;
      }
      *_errno() = save_errno;
      rc = comexecmd(mode, name: v16, argv, envp);
LABEL_30:
      free(pMem: v16);
      v4 = name;
      goto LABEL_31;
    }
    goto LABEL_14;
  }
  if ( _access_s(path: pathname, amode: 0) == 0 )
    rc = comexecmd(mode, name: pathname, argv, envp);
LABEL_31:
  if ( pathname != v4 )
    free(pMem: pathname);
  return rc;
}

//------------------------------------------------------------------------------
// Address: 0x103018E0
// Name: __global_unwind2
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _global_unwind2(PVOID TargetFrame)
{
  RtlUnwind(TargetFrame, TargetIp: &gu_return, ExceptionRecord: nullptr, ReturnValue: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x10301900
// Name: __unwind_handler
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall _unwind_handler@<eax>(int a1@<ebp>, int a2, int a3, int a4, _DWORD *a5, int a6)
{
  int result; // eax

  result = 1;
  if ( (*(_DWORD *)(a2 + 4) & 6) != 0 )
  {
    _local_unwind2(a1: *(_DWORD *)(a6 + 36), a2: *(_DWORD *)(a6 + 40), a3: a1);
    *a5 = a3;
    return 3;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10301945
// Name: __local_unwind2
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _local_unwind2(int a1, unsigned int a2)
{
  int result; // eax
  int v3; // ebx
  unsigned int v4; // esi
  int v5; // esi
  int v6; // ecx
  int v7; // [esp-14h] [ebp-24h]
  _EXCEPTION_REGISTRATION_RECORD *ExceptionList; // [esp-10h] [ebp-20h]

  ExceptionList = NtCurrentTeb()->NtTib.ExceptionList;
  while ( 1 )
  {
    result = a1;
    v3 = *(_DWORD *)(a1 + 8);
    v4 = *(_DWORD *)(a1 + 12);
    if ( v4 == -1 || a2 != -1 && v4 <= a2 )
      break;
    v5 = 3 * v4;
    *(_DWORD *)(a1 + 12) = *(_DWORD *)(v3 + 4 * v5);
    if ( *(_DWORD *)(v3 + 4 * v5 + 4) == 0 )
    {
      _NLG_Notify(a1: 257);
      _NLG_Call(a1: v6, a2: v7, a3: ExceptionList);
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103019C9
// Name: __abnormal_termination
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _abnormal_termination()
{
  int result; // eax
  _EXCEPTION_REGISTRATION_RECORD *ExceptionList; // ecx

  result = 0;
  ExceptionList = NtCurrentTeb()->NtTib.ExceptionList;
  if ( (int (__usercall *)@<eax>(int@<ebp>, int, int, int, _DWORD *, int))ExceptionList->Handler == _unwind_handler )
    return ExceptionList[1].Next == *((_EXCEPTION_REGISTRATION_RECORD **)ExceptionList[1].Handler + 3);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103019EC
// Name: __NLG_Notify1
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __stdcall _NLG_Notify1(int a1)
{
  JUMPOUT(0x10301A00);
}

//------------------------------------------------------------------------------
// Address: 0x103019F5
// Name: __NLG_Notify
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __userpurge _NLG_Notify@<eax>(unsigned int result@<eax>, unsigned int a2@<ebp>, unsigned int a3)
{
  _NLG_Destination.dwCode = a3;
  _NLG_Destination.uoffDestination = result;
  _NLG_Destination.uoffFramePointer = a2;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10301A14
// Name: __NLG_Call
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall _NLG_Call@<eax>(int (*a1)(void)@<eax>)
{
  return a1();
}

//------------------------------------------------------------------------------
// Address: 0x10301A17
// Name: _rt_probe_read4(x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __stdcall _rt_probe_read4(unsigned int *ptr)
{
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10301A70
// Name: __stbuf
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _stbuf(_iobuf *str)
{
  int v1; // eax
  int v2; // eax
  char **v3; // edi
  char *v4; // eax
  char *v5; // edi

  v1 = fileno(stream: str);
  if ( _isatty(fh: v1) == 0 )
    return 0;
  if ( str == &__iob_func()[1] )
  {
    v2 = 0;
  }
  else
  {
    if ( str != &__iob_func()[2] )
      return 0;
    v2 = 1;
  }
  ++_cflush;
  if ( (str->_flag & 0x10C) != 0 )
    return 0;
  v3 = (char **)&_stdbuf[v2];
  if ( *v3 != nullptr || (v4 = (char *)MemAlloc_Alloc(nSize: 0x1000u), *v3 = v4, v4 != nullptr) )
  {
    v5 = *v3;
    str->_base = v5;
    str->_ptr = v5;
    str->_bufsiz = 4096;
    str->_cnt = 4096;
  }
  else
  {
    str->_base = (char *)&str->_charbuf;
    str->_ptr = (char *)&str->_charbuf;
    str->_bufsiz = 2;
    str->_cnt = 2;
  }
  str->_flag |= 0x1102u;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10301B0C
// Name: __ftbuf
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _ftbuf(int flag, _iobuf *str)
{
  if ( flag != 0 && (str->_flag & 0x1000) != 0 )
  {
    _flush(str);
    str->_flag &= 0xFFFFEEFF;
    str->_bufsiz = 0;
    str->_ptr = nullptr;
    str->_base = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10301B40
// Name: __fcloseall
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _fcloseall()
{
  int i; // edi
  _iobuf *v1; // eax
  int count; // [esp+14h] [ebp-1Ch]

  count = 0;
  _lock(locknum: 1);
  for ( i = 3; i < (int)_nstream; ++i )
  {
    if ( __piob[i] != nullptr )
    {
      v1 = (_iobuf *)__piob[i];
      if ( (v1->_flag & 0x83) != 0 && fclose(stream: v1) != -1 )
        ++count;
      if ( i >= 20 )
      {
        DeleteCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)((char *)__piob[i] + 32));
        free(pMem: __piob[i]);
        __piob[i] = nullptr;
      }
    }
  }
  _unlock(locknum: 1);
  return count;
}

//------------------------------------------------------------------------------
// Address: 0x10301BDC
// Name: _CallDestructExceptionObject
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl CallDestructExceptionObject(_EXCEPTION_RECORD *pExcept)
{
  if ( pExcept->ExceptionCode == -529697949
    && __DestructExceptionObject != nullptr
    && _IsNonwritableInCurrentImage(pTarget: (unsigned __int8 *)&_pDestructExceptionObject) != 0 )
  {
    __DestructExceptionObject((EHExceptionRecord *)pExcept);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10301C20
// Name: ValidateScopeTableHandlers
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall ValidateScopeTableHandlers@<eax>(
        unsigned __int8 *pImageBase@<edi>,
        int dwTryLevel@<ecx>,
        _SCOPETABLE_ENTRY *pScopeTable)
{
  _IMAGE_SECTION_HEADER *PESection; // eax
  int v4; // edx
  _SCOPETABLE_ENTRY *v5; // ebx
  unsigned int v6; // esi
  unsigned int v7; // ecx
  _BYTE *FilterFunc; // ecx
  unsigned int v9; // esi
  unsigned int VirtualAddress; // ecx

  PESection = nullptr;
  v4 = -1;
  if ( dwTryLevel == -1 )
    return 1;
  while ( 1 )
  {
    v5 = &pScopeTable[dwTryLevel];
    v6 = ((char *)v5->HandlerFunc - (char *)pImageBase) & 0xFFFFF000;
    if ( v6 != v4 )
      break;
LABEL_9:
    FilterFunc = v5->FilterFunc;
    if ( FilterFunc != nullptr )
    {
      v9 = (FilterFunc - pImageBase) & 0xFFFFF000;
      if ( v9 != v4 )
      {
        VirtualAddress = PESection->VirtualAddress;
        if ( v9 < VirtualAddress || v9 >= VirtualAddress + PESection->Misc.PhysicalAddress )
        {
          PESection = _FindPESection(pImageBase, rva: v9);
          if ( PESection == nullptr || (PESection->Characteristics & 0x20000000) == 0 )
            return 0;
        }
        v4 = v9;
      }
    }
    dwTryLevel = v5->EnclosingLevel;
    if ( v5->EnclosingLevel == -1 )
      return 1;
  }
  if ( PESection != nullptr && (v7 = PESection->VirtualAddress, v6 >= v7) && v6 < v7 + PESection->Misc.PhysicalAddress
    || (PESection = _FindPESection(pImageBase, rva: ((char *)v5->HandlerFunc - (char *)pImageBase) & 0xFFFFF000)) != nullptr
    && (PESection->Characteristics & 0x20000000) != 0 )
  {
    v4 = v6;
    goto LABEL_9;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10301CE0
// Name: __ValidateEH3RN
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _ValidateEH3RN(_SCOPETABLE_ENTRY *pRN)
{
  _SCOPETABLE_ENTRY *HandlerFunc; // edx
  struct _TEB *v3; // eax
  unsigned int EnclosingLevel; // edi
  int v5; // ebx
  unsigned int v6; // eax
  _SCOPETABLE_ENTRY *v7; // ecx
  _SCOPETABLE_ENTRY *FilterFunc; // eax
  int i; // esi
  unsigned __int8 *pPage; // ebx
  unsigned __int8 *pImageBase; // edi
  int v12; // ecx
  bool v13; // cc
  int j; // eax
  unsigned __int8 *v15; // ecx
  unsigned __int8 *v16; // edx
  unsigned __int8 *AllocationBase; // edi
  _IMAGE_SECTION_HEADER *PESection; // eax
  int v19; // edi
  int v20; // eax
  unsigned __int8 **v21; // ecx
  int v22; // esi
  unsigned __int8 *v23; // ecx
  unsigned __int8 *v24; // edx
  _VALID_PAGE_CACHE *v25; // eax
  int v26; // ebx
  unsigned __int8 *v27; // esi
  unsigned __int8 *v28; // edi
  _MEMORY_BASIC_INFORMATION mbi; // [esp+10h] [ebp-40h] BYREF
  unsigned int dwTryLevel; // [esp+2Ch] [ebp-24h]
  unsigned __int8 *pScopePage; // [esp+30h] [ebp-20h]
  _SCOPETABLE_ENTRY *pScopeTable; // [esp+34h] [ebp-1Ch]
  int v33; // [esp+4Ch] [ebp-4h]

  HandlerFunc = (_SCOPETABLE_ENTRY *)pRN->HandlerFunc;
  pScopeTable = HandlerFunc;
  if ( ((unsigned __int8)HandlerFunc & 3) != 0 )
    return 0;
  v3 = NtCurrentTeb();
  pScopePage = (unsigned __int8 *)v3->NtTib.StackLimit;
  if ( HandlerFunc >= (_SCOPETABLE_ENTRY *)pScopePage && HandlerFunc < v3->NtTib.StackBase )
    return 0;
  EnclosingLevel = pRN[1].EnclosingLevel;
  dwTryLevel = EnclosingLevel;
  if ( EnclosingLevel != -1 )
  {
    v5 = 0;
    v6 = 0;
    v7 = HandlerFunc;
    do
    {
      if ( v7->EnclosingLevel != -1 && v7->EnclosingLevel >= v6 )
        return 0;
      if ( v7->FilterFunc != nullptr )
        v5 = 1;
      ++v6;
      ++v7;
    }
    while ( v6 <= EnclosingLevel );
    if ( v5 == 0
      || (FilterFunc = (_SCOPETABLE_ENTRY *)pRN[-1].FilterFunc) >= (_SCOPETABLE_ENTRY *)pScopePage && FilterFunc < pRN )
    {
      pScopePage = (unsigned __int8 *)((unsigned int)HandlerFunc & 0xFFFFF000);
      for ( i = 0; ; ++i )
      {
        if ( i >= nValidPages )
          goto LABEL_39;
        pPage = rgValidPages[i].pPage;
        pImageBase = rgValidPages[i].pImageBase;
        if ( pPage == (unsigned __int8 *)((unsigned int)HandlerFunc & 0xFFFFF000) )
          break;
      }
      v33 = 0;
      if ( _ValidateImageBase(pImageBase) != 0
        && ValidateScopeTableHandlers(pImageBase, dwTryLevel, pScopeTable) != 0
        && _FindPESection(pImageBase, rva: (char *)pRN->FilterFunc - (char *)pImageBase) != nullptr )
      {
        v33 = -2;
        if ( i > 0 && _InterlockedExchange(&lModifying, 1) == 0 )
        {
          if ( rgValidPages[i].pPage != pScopePage )
          {
            v12 = nValidPages;
            i = nValidPages - 1;
            if ( nValidPages - 1 >= 0 )
            {
              while ( rgValidPages[i].pPage != pScopePage )
              {
                if ( --i < 0 )
                  goto LABEL_29;
              }
              pPage = rgValidPages[i].pPage;
              pImageBase = rgValidPages[i].pImageBase;
LABEL_29:
              v13 = i <= 0;
              if ( i >= 0 )
                goto LABEL_34;
            }
            if ( nValidPages < 16 )
              v12 = ++nValidPages;
            i = v12 - 1;
          }
          v13 = i <= 0;
LABEL_34:
          if ( !v13 )
          {
            for ( j = 0; j <= i; ++j )
            {
              v15 = rgValidPages[j].pPage;
              v16 = rgValidPages[j].pImageBase;
              rgValidPages[j].pPage = pPage;
              rgValidPages[j].pImageBase = pImageBase;
              pPage = v15;
              pImageBase = v16;
            }
          }
LABEL_64:
          _InterlockedExchange(&lModifying, 0);
          return 1;
        }
        return 1;
      }
      v33 = -2;
      HandlerFunc = pScopeTable;
LABEL_39:
      if ( VirtualQuery(lpAddress: HandlerFunc, lpBuffer: &mbi, dwLength: 0x1Cu) == 0 )
        return 1;
      if ( mbi.Type != 0x1000000 )
        return -1;
      AllocationBase = (unsigned __int8 *)mbi.AllocationBase;
      if ( _ValidateImageBase(pImageBase: (unsigned __int8 *)mbi.AllocationBase) == 0 )
        return -1;
      if ( ((mbi.Protect & 0xCC) == 0
         || (PESection = _FindPESection(pImageBase: AllocationBase, rva: (char *)pScopeTable - (char *)AllocationBase)) != nullptr
         && (PESection->Characteristics & 0x80000000) == 0)
        && ValidateScopeTableHandlers(pImageBase: AllocationBase, dwTryLevel, pScopeTable) != 0
        && _FindPESection(pImageBase: AllocationBase, rva: (char *)pRN->FilterFunc - (char *)AllocationBase) != nullptr )
      {
        if ( _InterlockedExchange(&lModifying, 1) != 0 )
          return 1;
        v19 = nValidPages;
        v20 = nValidPages;
        if ( nValidPages > 0 )
        {
          v21 = (unsigned __int8 **)(&nValidPages + 2 * nValidPages);
          do
          {
            if ( *v21 == pScopePage )
              break;
            --v20;
            v21 -= 2;
          }
          while ( v20 > 0 );
        }
        if ( v20 != 0 )
        {
          *(&lModifying + 2 * v20) = (int)mbi.AllocationBase;
        }
        else
        {
          v22 = 15;
          if ( nValidPages <= 15 )
            v22 = nValidPages;
          v23 = pScopePage;
          v24 = (unsigned __int8 *)mbi.AllocationBase;
          if ( v22 >= 0 )
          {
            v25 = rgValidPages;
            v26 = v22 + 1;
            do
            {
              v27 = v25->pPage;
              v28 = v25->pImageBase;
              v25->pPage = v23;
              v25->pImageBase = v24;
              v23 = v27;
              v24 = v28;
              ++v25;
              --v26;
            }
            while ( v26 != 0 );
            v19 = nValidPages;
          }
          if ( v19 < 16 )
            nValidPages = v19 + 1;
        }
        goto LABEL_64;
      }
    }
    return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10302026
// Name: ___getgmtimebuf
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void *__getgmtimebuf()
{
  _tiddata *v0; // eax
  _tiddata *v1; // esi
  void *v3; // eax

  v0 = _getptd_noexit();
  v1 = v0;
  if ( v0 != nullptr )
  {
    if ( v0->_gmtimebuf != nullptr )
      return v1->_gmtimebuf;
    v3 = MemAlloc_Alloc(nSize: 0x24u);
    v1->_gmtimebuf = v3;
    if ( v3 != nullptr )
      return v1->_gmtimebuf;
  }
  *_errno() = 12;
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1030205D
// Name: __localtime64_s
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _localtime64_s(tm *ptm, const __int64 *ptime)
{
  int result; // eax
  int v3; // eax
  __int64 v4; // kr00_8
  __int64 v5; // kr10_8
  __int64 v6; // kr20_8
  __int64 v7; // rax
  int v8; // ecx
  int v9; // edx
  __int64 ltime; // [esp+8h] [ebp-14h] BYREF
  int dstbias; // [esp+10h] [ebp-Ch] BYREF
  int daylight; // [esp+14h] [ebp-8h] BYREF
  int timezone; // [esp+18h] [ebp-4h] BYREF

  daylight = 0;
  dstbias = 0;
  timezone = 0;
  if ( ptm == nullptr )
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return 22;
  }
  memset(dst: (int)ptm, value: (unsigned __int8 *)0xFF, count: sizeof(tm));
  if ( ptime == nullptr )
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return 22;
  }
  if ( *((int *)ptime + 1) < 0 || *ptime > 0x793406FFFLL )
  {
    *_errno() = 22;
    return 22;
  }
  __tzset();
  if ( _get_daylight(_Daylight: &daylight) != 0
    || _get_dstbias(_Daylight_savings_bias: &dstbias) != 0
    || _get_timezone(_Timezone: &timezone) != 0 )
  {
    _invoke_watson(a1: 0);
  }
  if ( *ptime <= 259200 )
  {
    result = _gmtime64_s(ptm, timp: ptime);
    if ( result == 0 )
    {
      if ( daylight != 0 && _isindst(tb: ptm) != 0 )
      {
        v3 = dstbias + timezone;
        ptm->tm_isdst = 1;
        v4 = ptm->tm_sec - (__int64)v3;
      }
      else
      {
        v4 = ptm->tm_sec - (__int64)timezone;
      }
      ptm->tm_sec = v4 % 60;
      if ( v4 % 60 < 0 )
      {
        ptm->tm_sec = v4 % 60 + 60;
        v4 = __PAIR64__((unsigned int)__CFADD__((_DWORD)v4, -60) + HIDWORD(v4) - 1, (int)v4 - 60);
      }
      v5 = ptm->tm_min + v4 / 60;
      ptm->tm_min = v5 % 60;
      if ( v5 % 60 < 0 )
      {
        ptm->tm_min = v5 % 60 + 60;
        v5 -= 60;
      }
      v6 = ptm->tm_hour + v5 / 60;
      ptm->tm_hour = v6 % 24;
      if ( v6 % 24 < 0 )
      {
        ptm->tm_hour = v6 % 24 + 24;
        v6 -= 24;
      }
      v7 = v6 / 24;
      v8 = v6 / 24;
      if ( (((unsigned __int64)(v6 / 24) >> 32) & 0x80000000) != 0LL )
      {
        HIDWORD(v7) = ((int)v7 + ptm->tm_wday + 7) % 7;
        ptm->tm_mday += v7;
        LODWORD(v7) = ptm->tm_mday;
        ptm->tm_wday = HIDWORD(v7);
        if ( (int)v7 <= 0 )
        {
          ptm->tm_yday += v8 + 365;
          --ptm->tm_year;
          ptm->tm_mday = v7 + 31;
          ptm->tm_mon = 11;
          return 0;
        }
      }
      else
      {
        if ( v7 <= 0 )
          return 0;
        v9 = (v8 + ptm->tm_wday) % 7;
        ptm->tm_mday += v8;
        ptm->tm_wday = v9;
      }
      ptm->tm_yday += v8;
      return 0;
    }
  }
  else
  {
    ltime = *ptime - timezone;
    result = _gmtime64_s(ptm, timp: &ltime);
    if ( result == 0 )
    {
      if ( daylight == 0 || _isindst(tb: ptm) == 0 )
        return 0;
      ltime -= dstbias;
      result = _gmtime64_s(ptm, timp: &ltime);
      if ( result == 0 )
      {
        ptm->tm_isdst = 1;
        return 0;
      }
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103022E5
// Name: __get_daylight
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _get_daylight(int *_Daylight)
{
  if ( _Daylight != nullptr )
  {
    *_Daylight = _daylight;
    return 0;
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return 22;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10302312
// Name: __get_dstbias
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _get_dstbias(int *_Daylight_savings_bias)
{
  if ( _Daylight_savings_bias != nullptr )
  {
    *_Daylight_savings_bias = _dstbias;
    return 0;
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return 22;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1030233F
// Name: __get_timezone
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _get_timezone(int *_Timezone)
{
  if ( _Timezone != nullptr )
  {
    *_Timezone = _timezone;
    return 0;
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return 22;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1030236C
// Name: ___daylight
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int *__cdecl __daylight()
{
  return &_daylight;
}

//------------------------------------------------------------------------------
// Address: 0x10302372
// Name: ___dstbias
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int *__cdecl __dstbias()
{
  return &_dstbias;
}

//------------------------------------------------------------------------------
// Address: 0x10302378
// Name: ___timezone
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int *__cdecl __timezone()
{
  return &_timezone;
}

//------------------------------------------------------------------------------
// Address: 0x1030237E
// Name: ___tzname
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char **__cdecl __tzname()
{
  return _tzname;
}

//------------------------------------------------------------------------------
// Address: 0x10302384
// Name: _strncpy_s
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl strncpy_s(char *_Dst, unsigned int _SizeInBytes, const char *_Src, unsigned int _Count)
{
  unsigned int v5; // edi
  int v6; // esi
  const char *v7; // edx
  char *v8; // ecx
  char v9; // cl
  char v10; // dl

  if ( _Count != 0 )
  {
    if ( _Dst == nullptr )
    {
LABEL_7:
      v6 = 22;
      *_errno() = 22;
LABEL_8:
      _invalid_parameter_noinfo();
      return v6;
    }
  }
  else if ( _Dst == nullptr )
  {
    if ( _SizeInBytes == 0 )
      return 0;
    goto LABEL_7;
  }
  v5 = _SizeInBytes;
  if ( _SizeInBytes == 0 )
    goto LABEL_7;
  if ( _Count == 0 )
  {
    *_Dst = 0;
    return 0;
  }
  v7 = _Src;
  if ( _Src == nullptr )
  {
    *_Dst = 0;
    goto LABEL_7;
  }
  v8 = _Dst;
  if ( _Count == -1 )
  {
    do
    {
      v9 = *v7;
      v7[_Dst - _Src] = *v7;
      ++v7;
      if ( v9 == 0 )
        break;
      --v5;
    }
    while ( v5 != 0 );
  }
  else
  {
    do
    {
      v10 = v8[_Src - _Dst];
      *v8++ = v10;
      if ( v10 == 0 )
        break;
      if ( --v5 == 0 )
        break;
      --_Count;
    }
    while ( _Count != 0 );
    if ( _Count == 0 )
      *v8 = 0;
  }
  if ( v5 != 0 )
    return 0;
  if ( _Count != -1 )
  {
    *_Dst = 0;
    *_errno() = 34;
    v6 = 34;
    goto LABEL_8;
  }
  _Dst[_SizeInBytes - 1] = 0;
  return 80;
}

//------------------------------------------------------------------------------
// Address: 0x10302439
// Name: ___init_ctype
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl __init_ctype(threadlocaleinfostruct *ploci)
{
  int v1; // ebx
  unsigned __int8 *v2; // eax
  int j; // eax
  unsigned __int8 *v4; // eax
  int v5; // ecx
  int v6; // edi
  unsigned __int8 *v7; // eax
  unsigned __int8 *v8; // edi
  unsigned __int16 *v9; // ecx
  bool v10; // cc
  unsigned __int8 *v11; // edx
  unsigned __int16 *v12; // ecx
  unsigned __int8 v13; // dl
  unsigned int v14; // ecx
  unsigned __int8 *k; // ecx
  int *v16; // eax
  unsigned int lc_codepage; // [esp-Ch] [ebp-64h]
  localeinfo_struct locinfo; // [esp+Ch] [ebp-4Ch] BYREF
  const unsigned __int8 *v20; // [esp+14h] [ebp-44h]
  const unsigned __int16 *v21; // [esp+18h] [ebp-40h]
  unsigned __int16 *v22; // [esp+1Ch] [ebp-3Ch]
  const unsigned __int8 *v23; // [esp+20h] [ebp-38h]
  unsigned __int8 *v24; // [esp+24h] [ebp-34h]
  int mb_cur_max; // [esp+28h] [ebp-30h]
  int *refcount; // [esp+2Ch] [ebp-2Ch]
  unsigned __int8 *newcumap; // [esp+30h] [ebp-28h]
  unsigned __int8 *cbuffer; // [esp+34h] [ebp-24h]
  int i; // [esp+38h] [ebp-20h]
  unsigned __int16 *newctype1; // [esp+3Ch] [ebp-1Ch]
  _cpinfo lpCPInfo; // [esp+40h] [ebp-18h] BYREF

  v1 = 0;
  refcount = nullptr;
  newctype1 = nullptr;
  i = 0;
  newcumap = nullptr;
  cbuffer = nullptr;
  locinfo.locinfo = ploci;
  locinfo.mbcinfo = nullptr;
  if ( ploci->lc_handle[2] != 0 )
  {
    if ( ploci->lc_codepage == 0
      && __getlocaleinfo(
           plocinfo: &locinfo,
           lc_type: 0,
           localehandle: ploci->lc_id[2].wLanguage,
           fieldtype: 0x1004u,
           address: (void **)&ploci->lc_codepage) != 0 )
    {
      goto error_cleanup_0;
    }
    refcount = (int *)MemAlloc_Alloc(nSize: 4u);
    newctype1 = (unsigned __int16 *)calloc(count: 0x180u, size: 2u);
    i = (int)calloc(count: 0x180u, size: 1u);
    newcumap = calloc(count: 0x180u, size: 1u);
    v2 = calloc(count: 0x101u, size: 1u);
    cbuffer = v2;
    if ( refcount == nullptr )
      goto error_cleanup_0;
    if ( newctype1 == nullptr )
      goto error_cleanup_0;
    if ( v2 == nullptr )
      goto error_cleanup_0;
    if ( i == 0 )
      goto error_cleanup_0;
    if ( newcumap == nullptr )
      goto error_cleanup_0;
    *refcount = 0;
    for ( j = 0; j < 256; ++j )
      cbuffer[j] = j;
    if ( !GetCPInfo(CodePage: ploci->lc_codepage, &lpCPInfo) || lpCPInfo.MaxCharSize > 5 )
      goto error_cleanup_0;
    mb_cur_max = LOWORD(lpCPInfo.MaxCharSize);
    if ( LOWORD(lpCPInfo.MaxCharSize) > 1u && lpCPInfo.LeadByte[0] != 0 )
    {
      v4 = &lpCPInfo.LeadByte[1];
      do
      {
        LOBYTE(v5) = *v4;
        if ( *v4 == 0 )
          break;
        v6 = *(v4 - 1);
        v5 = (unsigned __int8)v5;
        while ( v6 <= v5 )
        {
          cbuffer[v6] = 32;
          v5 = *v4;
          ++v6;
        }
        v4 += 2;
      }
      while ( *(v4 - 1) != 0 );
    }
    lc_codepage = ploci->lc_codepage;
    v21 = newctype1 + 128;
    if ( __crtGetStringTypeA(
           plocinfo: nullptr,
           dwInfoType: 1u,
           lpSrcStr: (const char *)cbuffer,
           cchSrc: 256,
           lpCharType: newctype1 + 128,
           code_page: lc_codepage,
           lcid: 0,
           bError: 0) != 0
      && __crtLCMapStringA(
           plocinfo: nullptr,
           Locale: ploci->lc_handle[2],
           dwMapFlags: 0x100u,
           lpSrcStr: (const char *)cbuffer + 1,
           cchSrc: 255,
           lpDestStr: (char *)(i + 129),
           cchDest: 255,
           code_page: ploci->lc_codepage,
           bError: 0) != 0
      && __crtLCMapStringA(
           plocinfo: nullptr,
           Locale: ploci->lc_handle[2],
           dwMapFlags: 0x200u,
           lpSrcStr: (const char *)cbuffer + 1,
           cchSrc: 255,
           lpDestStr: (char *)newcumap + 129,
           cchDest: 255,
           code_page: ploci->lc_codepage,
           bError: 0) != 0 )
    {
      v7 = (unsigned __int8 *)newctype1;
      v8 = (unsigned __int8 *)i;
      v9 = newctype1 + 127;
      v10 = mb_cur_max <= 1;
      newctype1[127] = 0;
      v11 = newcumap;
      v22 = v9;
      v8[127] = 0;
      v11[127] = 0;
      v8[128] = 0;
      v20 = v8 + 128;
      v23 = v11 + 128;
      v11[128] = 0;
      if ( !v10 && lpCPInfo.LeadByte[0] != 0 )
      {
        v12 = (unsigned __int16 *)&lpCPInfo.LeadByte[1];
        newctype1 = (unsigned __int16 *)&lpCPInfo.LeadByte[1];
        do
        {
          v13 = *(_BYTE *)v12;
          if ( *(_BYTE *)v12 == 0 )
            break;
          v14 = *((unsigned __int8 *)v12 - 1);
          i = v14;
          if ( v14 <= v13 )
          {
            for ( k = &v7[2 * v14 + 256]; ; k = v24 )
            {
              ++i;
              *(_WORD *)k = 0x8000;
              v24 = k + 2;
              if ( i > *(unsigned __int8 *)newctype1 )
                break;
            }
          }
          v12 = newctype1 + 1;
          newctype1 = v12;
        }
        while ( *((_BYTE *)v12 - 1) != 0 );
      }
      memcpy(dst: v7, src: v7 + 512, count: 0xFEu);
      memcpy(dst: v8, src: v8 + 256, count: 0x7Fu);
      memcpy(dst: newcumap, src: newcumap + 256, count: 0x7Fu);
      if ( ploci->ctype1_refcount != nullptr && InterlockedDecrement(lpAddend: ploci->ctype1_refcount) == 0 )
      {
        free(pMem: ploci->ctype1 - 127);
        free(pMem: (void *)(ploci->pclmap - 128));
        free(pMem: (void *)(ploci->pcumap - 128));
        free(pMem: ploci->ctype1_refcount);
      }
      v16 = refcount;
      *refcount = 1;
      ploci->ctype1_refcount = v16;
      ploci->pctype = v21;
      ploci->ctype1 = v22;
      ploci->pclmap = v20;
      ploci->pcumap = v23;
      ploci->mb_cur_max = mb_cur_max;
    }
    else
    {
error_cleanup_0:
      free(pMem: refcount);
      free(pMem: newctype1);
      free(pMem: (void *)i);
      free(pMem: newcumap);
      v1 = 1;
    }
    free(pMem: cbuffer);
    return v1;
  }
  else
  {
    if ( ploci->ctype1_refcount != nullptr )
      InterlockedDecrement(lpAddend: ploci->ctype1_refcount);
    ploci->ctype1_refcount = nullptr;
    ploci->ctype1 = nullptr;
    ploci->pctype = asc_103F99F0;
    ploci->pclmap = &__newclmap[128];
    ploci->pcumap = &__newcumap[128];
    ploci->mb_cur_max = 1;
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x103027E0
// Name: ____lc_codepage_func
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __cdecl ___lc_codepage_func()
{
  _tiddata *v0; // ecx
  threadlocaleinfostruct *ptlocinfo; // eax

  v0 = _getptd();
  ptlocinfo = v0->ptlocinfo;
  if ( ptlocinfo != __ptlocinfo && (__globallocalestatus & v0->_ownlocale) == 0 )
    ptlocinfo = __updatetlocinfo();
  return ptlocinfo->lc_codepage;
}

//------------------------------------------------------------------------------
// Address: 0x10302806
// Name: __setenvp
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _setenvp()
{
  char *v0; // esi
  int v1; // edi
  int v3; // eax
  unsigned __int8 *v4; // edi
  char *i; // esi
  int v6; // eax
  unsigned int v7; // ebx
  unsigned __int8 *v8; // eax

  if ( __mbctype_initialized == 0 )
    __initmbctable();
  v0 = _aenvptr;
  v1 = 0;
  if ( _aenvptr != nullptr )
  {
    while ( *v0 != 0 )
    {
      if ( *v0 != 61 )
        ++v1;
      strlen(buf: v0);
      v0 += v3 + 1;
    }
    v4 = calloc(count: v1 + 1, size: 4u);
    _environ = (char **)v4;
    if ( v4 != nullptr )
    {
      for ( i = _aenvptr; ; i += v7 )
      {
        if ( *i == 0 )
        {
          free(pMem: _aenvptr);
          _aenvptr = nullptr;
          *(_DWORD *)v4 = 0;
          __env_initialized = 1;
          return 0;
        }
        strlen(buf: i);
        v7 = v6 + 1;
        if ( *i != 61 )
          break;
LABEL_15:
        ;
      }
      v8 = calloc(count: v6 + 1, size: 1u);
      *(_DWORD *)v4 = v8;
      if ( v8 != nullptr )
      {
        if ( strcpy_s(_Dst: (char *)v8, _SizeInBytes: v7, _Src: i) != 0 )
          _invoke_watson(a1: (unsigned int)v4);
        v4 += 4;
        goto LABEL_15;
      }
      free(pMem: _environ);
      _environ = nullptr;
      return -1;
    }
  }
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x103028E2
// Name: parse_cmdline
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall parse_cmdline(char *cmdstart@<edx>, int *numchars@<edi>, char **argv, char *args, int *numargs)
{
  int *v5; // ecx
  char *v7; // edx
  char **v8; // ebx
  char v9; // bl
  char *v10; // ecx
  char **v11; // eax
  int v12; // ebx
  unsigned int v13; // ecx
  char v14; // al
  char *v15; // ecx
  char *v16; // ecx
  unsigned int v17; // [esp-4h] [ebp-10h]
  BOOL inquote; // [esp+8h] [ebp-4h]
  BOOL inquotea; // [esp+8h] [ebp-4h]

  v5 = numargs;
  *numchars = 0;
  v7 = args;
  *numargs = 1;
  if ( argv != nullptr )
  {
    v8 = argv++;
    *v8 = args;
  }
  inquote = false;
  do
  {
    if ( *cmdstart == 34 )
    {
      v9 = 34;
      ++cmdstart;
      inquote = !inquote;
    }
    else
    {
      ++*numchars;
      if ( v7 != nullptr )
      {
        *v7 = *cmdstart;
        args = v7 + 1;
      }
      v9 = *cmdstart;
      v17 = (unsigned __int8)*cmdstart++;
      if ( _ismbblead(tst: v17) != 0 )
      {
        ++*numchars;
        if ( args != nullptr )
        {
          v10 = args++;
          *v10 = *cmdstart;
        }
        ++cmdstart;
      }
      v7 = args;
      v5 = numargs;
      if ( v9 == 0 )
      {
        --cmdstart;
        goto LABEL_18;
      }
    }
  }
  while ( inquote || v9 != 32 && v9 != 9 );
  if ( v7 != nullptr )
    *(v7 - 1) = 0;
LABEL_18:
  inquotea = false;
  while ( *cmdstart != 0 )
  {
    while ( *cmdstart == 32 || *cmdstart == 9 )
      ++cmdstart;
    if ( *cmdstart == 0 )
      break;
    if ( argv != nullptr )
    {
      v11 = argv++;
      *v11 = v7;
    }
    ++*v5;
    while ( 1 )
    {
      v12 = 1;
      v13 = 0;
      while ( *cmdstart == 92 )
      {
        ++cmdstart;
        ++v13;
      }
      if ( *cmdstart == 34 )
      {
        if ( (v13 & 1) == 0 )
        {
          if ( inquotea && cmdstart[1] == 34 )
          {
            ++cmdstart;
          }
          else
          {
            v12 = 0;
            inquotea = !inquotea;
          }
        }
        v13 >>= 1;
      }
      if ( v13 != 0 )
      {
        do
        {
          --v13;
          if ( v7 != nullptr )
            *v7++ = 92;
          ++*numchars;
        }
        while ( v13 != 0 );
        args = v7;
      }
      v14 = *cmdstart;
      if ( *cmdstart == 0 || !inquotea && (v14 == 32 || v14 == 9) )
        break;
      if ( v12 != 0 )
      {
        if ( v7 != nullptr )
        {
          if ( _ismbblead(tst: v14) != 0 )
          {
            v15 = args++;
            *v15 = *cmdstart++;
            ++*numchars;
          }
          v16 = args++;
          *v16 = *cmdstart;
        }
        else if ( _ismbblead(tst: v14) != 0 )
        {
          ++cmdstart;
          ++*numchars;
        }
        ++*numchars;
        v7 = args;
      }
      ++cmdstart;
    }
    if ( v7 != nullptr )
    {
      *v7++ = 0;
      args = v7;
    }
    ++*numchars;
    v5 = numargs;
  }
  if ( argv != nullptr )
    *argv = nullptr;
  ++*v5;
}

//------------------------------------------------------------------------------
// Address: 0x10302A7C
// Name: __setargv
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _setargv()
{
  int v0; // edi
  unsigned int v1; // eax
  char **v2; // esi
  int numchars; // [esp+Ch] [ebp-Ch] BYREF
  int numargs; // [esp+10h] [ebp-8h] BYREF
  char *cmdstart; // [esp+14h] [ebp-4h]

  if ( __mbctype_initialized == 0 )
    __initmbctable();
  pgmname[260] = 0;
  GetModuleFileNameA(hModule: nullptr, lpFilename: pgmname, nSize: 0x104u);
  _pgmptr = pgmname;
  if ( _acmdln == nullptr || (cmdstart = _acmdln, *_acmdln == 0) )
    cmdstart = pgmname;
  parse_cmdline(cmdstart, &numchars, argv: nullptr, args: nullptr, &numargs);
  if ( (unsigned int)numargs >= 0x3FFFFFFF )
    return -1;
  if ( numchars == -1 )
    return -1;
  v0 = numargs;
  v1 = 4 * numargs + numchars;
  if ( v1 < numchars )
    return -1;
  v2 = (char **)MemAlloc_Alloc(nSize: v1);
  if ( v2 == nullptr )
    return -1;
  parse_cmdline(cmdstart, &numchars, argv: v2, args: (char *)&v2[v0], &numargs);
  __argc = numargs - 1;
  __argv = v2;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10302B37
// Name: ___crtGetEnvironmentStringsA
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char *__cdecl __crtGetEnvironmentStringsA()
{
  LPWCH EnvironmentStringsW; // eax
  wchar_t *v1; // ebx
  unsigned int v3; // eax
  char *v4; // eax
  int nSizeW; // [esp+8h] [ebp-Ch]
  int nSizeA; // [esp+Ch] [ebp-8h]
  char *aEnv; // [esp+10h] [ebp-4h]

  EnvironmentStringsW = GetEnvironmentStringsW();
  v1 = EnvironmentStringsW;
  if ( EnvironmentStringsW == nullptr )
    return nullptr;
  for ( ; *EnvironmentStringsW != 0; ++EnvironmentStringsW )
  {
    do
      ++EnvironmentStringsW;
    while ( *EnvironmentStringsW != 0 );
  }
  nSizeW = EnvironmentStringsW - v1 + 1;
  v3 = WideCharToMultiByte(
         CodePage: 0,
         dwFlags: 0,
         lpWideCharStr: v1,
         cchWideChar: nSizeW,
         lpMultiByteStr: nullptr,
         cbMultiByte: 0,
         lpDefaultChar: nullptr,
         lpUsedDefaultChar: nullptr);
  nSizeA = v3;
  if ( v3 != 0 && (v4 = (char *)MemAlloc_Alloc(nSize: v3), aEnv = v4, v4 != nullptr) )
  {
    if ( WideCharToMultiByte(
           CodePage: 0,
           dwFlags: 0,
           lpWideCharStr: v1,
           cchWideChar: nSizeW,
           lpMultiByteStr: v4,
           cbMultiByte: nSizeA,
           lpDefaultChar: nullptr,
           lpUsedDefaultChar: nullptr) == 0 )
    {
      free(pMem: aEnv);
      aEnv = nullptr;
    }
    FreeEnvironmentStringsW(penv: v1);
    return aEnv;
  }
  else
  {
    FreeEnvironmentStringsW(penv: v1);
    return nullptr;
  }
}

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x1002B2D0
// Name: public: virtual int COM_IOReadBinary::open(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void *__thiscall COM_IOReadBinary::open(COM_IOReadBinary *this, const char *pFileName)
{
  char namebuffer[512]; // [esp+4h] [ebp-200h] BYREF

  V_strncpy(pDest: namebuffer, pSrc: "sound", maxLen: 512);
  if ( *pFileName != 47 && *pFileName != 92 )
    V_strncat(pDest: namebuffer, pSrc: "/", destBufferSize: 0x200u, max_chars_to_copy: -1);
  V_strncat(pDest: namebuffer, pSrc: pFileName, destBufferSize: 0x200u, max_chars_to_copy: -1);
  return g_pFileSystem->Open(this: &g_pFileSystem->IBaseFileSystem, a2: namebuffer, a3: "rb", a4: "GAME");
}

//------------------------------------------------------------------------------
// Address: 0x1002B360
// Name: public: virtual int COM_IOReadBinary::read(void __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void *__thiscall COM_IOReadBinary::read(COM_IOReadBinary *this, void *pOutput, int size, void *file)
{
  void *result; // eax

  result = file;
  if ( file != nullptr )
    return (void *)g_pFileSystem->Read(this: &g_pFileSystem->IBaseFileSystem, a2: pOutput, a3: size, a4: file);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1002B390
// Name: public: virtual void COM_IOReadBinary::seek(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COM_IOReadBinary::seek(COM_IOReadBinary *this, void *file, int pos)
{
  if ( file != nullptr )
    g_pFileSystem->Seek(this: &g_pFileSystem->IBaseFileSystem, a2: file, a3: pos, a4: FILESYSTEM_SEEK_HEAD);
}

//------------------------------------------------------------------------------
// Address: 0x1002B3C0
// Name: public: virtual unsigned int COM_IOReadBinary::tell(int)
// Source: json
//------------------------------------------------------------------------------
void *__thiscall COM_IOReadBinary::tell(COM_IOReadBinary *this, void *file)
{
  void *result; // eax

  result = file;
  if ( file != nullptr )
    return (void *)g_pFileSystem->Tell(this: &g_pFileSystem->IBaseFileSystem, a2: file);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1002B3F0
// Name: public: virtual unsigned int COM_IOReadBinary::size(int)
// Source: json
//------------------------------------------------------------------------------
void *__thiscall COM_IOReadBinary::size(COM_IOReadBinary *this, void *file)
{
  void *result; // eax

  result = file;
  if ( file != nullptr )
    return (void *)g_pFileSystem->Size_2(this: &g_pFileSystem->IBaseFileSystem, a2: file);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1002B420
// Name: public: virtual void COM_IOReadBinary::close(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COM_IOReadBinary::close(COM_IOReadBinary *this, void *file)
{
  if ( file != nullptr )
    g_pFileSystem->Close(this: &g_pFileSystem->IBaseFileSystem, a2: file);
}

//------------------------------------------------------------------------------
// Address: 0x102FCFB3
// Name: __close
// Source: json
//------------------------------------------------------------------------------
int __cdecl _close(int fh)
{
  ioinfo **v2; // edi
  int v3; // esi
  int r; // [esp+14h] [ebp-1Ch]

  if ( fh == -2 )
  {
    *__doserrno() = 0;
    *_errno() = 9;
    return -1;
  }
  if ( fh < 0 || fh >= _nhandle || (v2 = &__pioinfo[fh >> 5], v3 = (fh & 0x1F) << 6, (*(&(*v2)->osfile + v3) & 1) == 0) )
  {
    *__doserrno() = 0;
    *_errno() = 9;
    _invalid_parameter_noinfo();
    return -1;
  }
  __lock_fhandle(fh);
  if ( (*(&(*v2)->osfile + v3) & 1) != 0 )
  {
    r = _close_nolock(fh);
  }
  else
  {
    *_errno() = 9;
    r = -1;
  }
  _unlock_fhandle(fh);
  return r;
}

//------------------------------------------------------------------------------
// Address: 0x102FD077
// Name: __freebuf
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _freebuf(_iobuf *stream)
{
  int flag; // eax

  flag = stream->_flag;
  if ( (flag & 0x83) != 0 && (flag & 8) != 0 )
  {
    free(pMem: stream->_base);
    stream->_flag &= 0xFFFFFBF7;
    stream->_ptr = nullptr;
    stream->_base = nullptr;
    stream->_cnt = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102FD0A8
// Name: __lseek_nolock
// Source: linker_block_proximity
//------------------------------------------------------------------------------
DWORD __cdecl _lseek_nolock(int fh, LONG pos, DWORD mthd)
{
  void *osfhandle; // eax
  DWORD v5; // edi
  DWORD LastError; // eax
  char *p_osfile; // eax

  osfhandle = (void *)_get_osfhandle(fh);
  if ( osfhandle == (void *)-1 )
  {
    *_errno() = 9;
    return -1;
  }
  else
  {
    v5 = SetFilePointer(hFile: osfhandle, lDistanceToMove: pos, lpDistanceToMoveHigh: nullptr, dwMoveMethod: mthd);
    if ( v5 == -1 )
      LastError = GetLastError();
    else
      LastError = 0;
    if ( LastError != 0 )
    {
      _dosmaperr(oserrno: LastError);
      return -1;
    }
    else
    {
      p_osfile = &__pioinfo[fh >> 5][fh & 0x1F].osfile;
      *p_osfile &= ~2u;
      return v5;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102FD11D
// Name: __lseek
// Source: linker_block_proximity
//------------------------------------------------------------------------------
DWORD __cdecl _lseek(int fh, LONG pos, DWORD mthd)
{
  ioinfo **v4; // edi
  int v5; // esi
  DWORD r; // [esp+14h] [ebp-1Ch]

  if ( fh == -2 )
  {
    *__doserrno() = 0;
    *_errno() = 9;
    return -1;
  }
  if ( fh < 0 || fh >= _nhandle || (v4 = &__pioinfo[fh >> 5], v5 = (fh & 0x1F) << 6, (*(&(*v4)->osfile + v5) & 1) == 0) )
  {
    *__doserrno() = 0;
    *_errno() = 9;
    _invalid_parameter_noinfo();
    return -1;
  }
  __lock_fhandle(fh);
  if ( (*(&(*v4)->osfile + v5) & 1) != 0 )
  {
    r = _lseek_nolock(fh, pos, mthd);
  }
  else
  {
    *_errno() = 9;
    *__doserrno() = 0;
    r = -1;
  }
  _unlock_fhandle(fh);
  return r;
}

//------------------------------------------------------------------------------
// Address: 0x102FD1F1
// Name: __openfile
// Source: linker_block_proximity
//------------------------------------------------------------------------------
_iobuf *__cdecl _openfile(const char *filename, const char *mode, int shflag, _iobuf *str)
{
  unsigned int v4; // ebx
  const char *v5; // esi
  char v6; // al
  _iobuf *result; // eax
  int v8; // ecx
  const unsigned __int8 *v9; // esi
  signed __int8 v10; // al
  int v11; // eax
  int v12; // eax
  int v13; // eax
  int v14; // eax
  int v15; // eax
  int v16; // eax
  int v17; // eax
  int v18; // eax
  int v19; // eax
  const unsigned __int8 *i; // esi
  int encodingFlag; // [esp+8h] [ebp-10h]
  int commodeset; // [esp+Ch] [ebp-Ch]
  int scanset; // [esp+10h] [ebp-8h]
  unsigned int streamflag; // [esp+14h] [ebp-4h]

  v4 = 0;
  v5 = mode;
  commodeset = 0;
  scanset = 0;
  encodingFlag = 0;
  while ( *v5 == 32 )
    ++v5;
  v6 = *v5;
  if ( *v5 == 97 )
  {
    v4 = 265;
  }
  else
  {
    if ( v6 == 114 )
    {
      streamflag = _commode | 1;
      goto LABEL_12;
    }
    if ( v6 != 119 )
    {
      *_errno() = 22;
      _invalid_parameter_noinfo();
      return nullptr;
    }
    v4 = 769;
  }
  streamflag = _commode | 2;
LABEL_12:
  v8 = 1;
  v9 = (const unsigned __int8 *)(v5 + 1);
  v10 = *v9;
  if ( *v9 == 0 )
    goto LABEL_66;
  while ( v8 != 0 )
  {
    if ( v10 > 83 )
    {
      v16 = v10 - 84;
      if ( v16 == 0 )
      {
        if ( (v4 & 0x1000) == 0 )
        {
          v4 |= 0x1000u;
          goto LABEL_48;
        }
        goto LABEL_46;
      }
      v17 = v16 - 14;
      if ( v17 != 0 )
      {
        v18 = v17 - 1;
        if ( v18 != 0 )
        {
          v19 = v18 - 11;
          if ( v19 != 0 )
          {
            if ( v19 != 6 )
              goto LABEL_68;
            if ( (v4 & 0xC000) != 0 )
              goto LABEL_46;
            v4 |= 0x4000u;
          }
          else
          {
            if ( commodeset != 0 )
              goto LABEL_46;
            streamflag &= ~0x4000u;
            commodeset = 1;
          }
        }
        else
        {
          if ( commodeset != 0 )
            goto LABEL_46;
          streamflag |= 0x4000u;
          commodeset = 1;
        }
      }
      else
      {
        if ( (v4 & 0xC000) != 0 )
          goto LABEL_46;
        v4 |= 0x8000u;
      }
    }
    else if ( v10 == 83 )
    {
      if ( scanset != 0 )
        goto LABEL_46;
      scanset = 1;
      v4 |= 0x20u;
    }
    else
    {
      v11 = v10 - 32;
      if ( v11 != 0 )
      {
        v12 = v11 - 11;
        if ( v12 != 0 )
        {
          v13 = v12 - 1;
          if ( v13 == 0 )
          {
            encodingFlag = 1;
LABEL_46:
            v8 = 0;
            goto LABEL_48;
          }
          v14 = v13 - 24;
          if ( v14 != 0 )
          {
            v15 = v14 - 10;
            if ( v15 != 0 )
            {
              if ( v15 != 4 )
                goto LABEL_68;
              if ( scanset != 0 )
                goto LABEL_46;
              scanset = 1;
              v4 |= 0x10u;
            }
            else
            {
              v4 |= 0x80u;
            }
          }
          else
          {
            if ( (v4 & 0x40) != 0 )
              goto LABEL_46;
            v4 |= 0x40u;
          }
        }
        else
        {
          if ( (v4 & 2) != 0 )
            goto LABEL_46;
          v4 = v4 & 0xFFFFFFFC | 2;
          streamflag = streamflag & 0xFFFFFF7C | 0x80;
        }
      }
    }
LABEL_48:
    v10 = *++v9;
    if ( *v9 == 0 )
      break;
  }
  if ( encodingFlag == 0 )
    goto LABEL_66;
  while ( *v9 == 32 )
    ++v9;
  if ( _mbsnbcmp(s1: "ccs", s2: v9, n: 3u) != 0 )
    goto LABEL_68;
  for ( i = v9 + 3; *i == 32; ++i )
    ;
  if ( *i != 61 )
    goto LABEL_68;
  do
    ++i;
  while ( *i == 32 );
  if ( _mbsnbicmp(s1: i, s2: "UTF-8", n: 5u) == 0 )
  {
    v9 = i + 5;
    v4 |= 0x40000u;
    goto LABEL_66;
  }
  if ( _mbsnbicmp(s1: i, s2: "UTF-16LE", n: 8u) == 0 )
  {
    v9 = i + 8;
    v4 |= 0x20000u;
    goto LABEL_66;
  }
  if ( _mbsnbicmp(s1: i, s2: "UNICODE", n: 7u) != 0 )
    goto LABEL_68;
  v9 = i + 7;
  v4 |= 0x10000u;
LABEL_66:
  while ( *v9 == 32 )
    ++v9;
  if ( *v9 != 0 )
  {
LABEL_68:
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return nullptr;
  }
  if ( _sopen_s(pfh: (int *)&mode, path: filename, oflag: v4, shflag, pmode: 384) != 0 )
    return nullptr;
  ++_cflush;
  result = str;
  str->_flag = streamflag;
  result->_cnt = 0;
  result->_ptr = nullptr;
  result->_base = nullptr;
  result->_tmpfname = nullptr;
  result->_file = (int)mode;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102FD488
// Name: __getstream
// Source: linker_block_proximity
//------------------------------------------------------------------------------
_iobuf *__cdecl _getstream()
{
  _DWORD *v0; // edi
  int i; // esi
  void **v2; // eax
  int v3; // eax
  void *v4; // eax

  v0 = nullptr;
  _lock(locknum: 1);
  for ( i = 0; i < (int)_nstream; ++i )
  {
    v2 = &__piob[i];
    if ( *v2 == nullptr )
    {
      v4 = MemAlloc_Alloc(nSize: 0x38u);
      __piob[i] = v4;
      if ( v4 != nullptr )
      {
        if ( InitializeCriticalSectionAndSpinCount(
               lpCriticalSection: (LPCRITICAL_SECTION)((char *)__piob[i] + 32),
               dwSpinCount: 0xFA0u) )
        {
          EnterCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)((char *)__piob[i] + 32));
          v0 = __piob[i];
          v0[3] = 0;
        }
        else
        {
          free(pMem: __piob[i]);
          __piob[i] = nullptr;
        }
      }
      break;
    }
    v3 = *((_DWORD *)*v2 + 3);
    if ( (v3 & 0x83) == 0 && (v3 & 0x8000) == 0 )
    {
      if ( (unsigned int)(i - 3) <= 0x10 && _mtinitlocknum(locknum: i + 16) == 0 )
        break;
      _lock_file2(i, s: __piob[i]);
      if ( (*((_BYTE *)__piob[i] + 12) & 0x83) == 0 )
      {
        v0 = __piob[i];
        break;
      }
      _unlock_file2(i, s: __piob[i]);
    }
  }
  if ( v0 != nullptr )
  {
    v0[3] &= 0x8000u;
    v0[1] = 0;
    v0[2] = 0;
    *v0 = 0;
    v0[7] = 0;
    v0[4] = -1;
  }
  _unlock(locknum: 1);
  return (_iobuf *)v0;
}

//------------------------------------------------------------------------------
// Address: 0x102FD5C0
// Name: __local_unwind4
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _local_unwind4(_DWORD *a1, int a2, unsigned int a3)
{
  int result; // eax
  unsigned int v4; // esi
  int v5; // esi
  int v6; // ebx
  _EXCEPTION_REGISTRATION_RECORD *ExceptionList; // [esp-8h] [ebp-28h]
  int (__cdecl *v8)(int, int, int, int); // [esp-4h] [ebp-24h]

  v8 = unwind_handler4;
  ExceptionList = NtCurrentTeb()->NtTib.ExceptionList;
  while ( 1 )
  {
    result = a2;
    v4 = *(_DWORD *)(a2 + 12);
    if ( v4 == -2 || a3 != -2 && v4 <= a3 )
      break;
    v5 = 3 * v4;
    v6 = (*a1 ^ *(_DWORD *)(a2 + 8)) + 4 * v5 + 16;
    *(_DWORD *)(a2 + 12) = *(_DWORD *)((*a1 ^ *(_DWORD *)(a2 + 8)) + 4 * v5 + 0x10);
    if ( *(_DWORD *)(v6 + 4) == 0 )
    {
      _NLG_Notify(a1: 257);
      _NLG_Call(a1: 1, a2: ExceptionList, a3: v8);
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102FD650
// Name: _unwind_handler4
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl unwind_handler4(int a1, int a2, int a3, _DWORD *a4)
{
  int result; // eax

  result = 1;
  if ( (*(_DWORD *)(a1 + 4) & 6) != 0 )
  {
    _local_unwind4(a1: *(_DWORD **)(a2 + 20), a2: *(_DWORD *)(a2 + 16), a3: *(_DWORD *)(a2 + 12));
    *a4 = a2;
    return 3;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102FD696
// Name: _seh_longjmp_unwind4(x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __stdcall _seh_longjmp_unwind4(unsigned int Dummy)
{
  _local_unwind4(a1: *(_DWORD **)(Dummy + 40), a2: *(_DWORD *)(Dummy + 24), a3: *(_DWORD *)(Dummy + 28));
}

//------------------------------------------------------------------------------
// Address: 0x102FD6B2
// Name: _EH4_CallFilterFunc(x,x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall _EH4_CallFilterFunc(int (*this)(void))
{
  return this();
}

//------------------------------------------------------------------------------
// Address: 0x102FD6C9
// Name: _EH4_TransferToHandler(x,x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall _EH4_TransferToHandler(int (__fastcall *this)(_DWORD, _DWORD))
{
  _NLG_Notify(a1: 1);
  return this(a1: 0, a2: 0);
}

//------------------------------------------------------------------------------
// Address: 0x102FD6E2
// Name: _EH4_GlobalUnwind2(x,x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __fastcall _EH4_GlobalUnwind2(PVOID TargetFrame, PEXCEPTION_RECORD ExceptionRecord)
{
  RtlUnwind(TargetFrame, TargetIp: &ReturnPoint_0, ExceptionRecord, ReturnValue: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x102FD6FB
// Name: _EH4_LocalUnwind(x,x,x,x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __fastcall _EH4_LocalUnwind(int a1, unsigned int a2, int a3, _DWORD *a4)
{
  return _local_unwind4(a1: a4, a2: a1, a3: a2);
}

//------------------------------------------------------------------------------
// Address: 0x102FD712
// Name: __ioinit
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _ioinit()
{
  ioinfo *v0; // eax
  char *p_pipech; // eax
  int v3; // ebx
  char **v4; // edi
  char *v5; // eax
  char *v6; // eax
  int i; // edi
  ioinfo *v8; // esi
  int j; // ebx
  ioinfo *v10; // esi
  DWORD v11; // eax
  HANDLE StdHandle; // eax
  int v13; // edi
  DWORD FileType; // eax
  _STARTUPINFOW StartupInfo; // [esp+4h] [ebp-4Ch] BYREF
  int *posfhnd; // [esp+48h] [ebp-8h]
  char *posfile; // [esp+4Ch] [ebp-4h]

  GetStartupInfoW(lpStartupInfo: &StartupInfo);
  v0 = (ioinfo *)calloc(count: 0x20u, size: 0x40u);
  if ( v0 == nullptr )
    return -1;
  __pioinfo[0] = v0;
  _nhandle = 32;
  if ( v0 < &v0[32] )
  {
    p_pipech = &v0->pipech;
    do
    {
      *(_DWORD *)(p_pipech - 5) = -1;
      *(_WORD *)(p_pipech - 1) = 2560;
      *(_DWORD *)(p_pipech + 3) = 0;
      *(_WORD *)(p_pipech + 31) = 2560;
      p_pipech[33] = 10;
      *(_DWORD *)(p_pipech + 51) = 0;
      p_pipech[47] = 0;
      p_pipech += 64;
    }
    while ( (ioinfo *)(p_pipech - 5) < &__pioinfo[0][32] );
  }
  if ( StartupInfo.cbReserved2 != 0 && StartupInfo.lpReserved2 != nullptr )
  {
    v3 = *(_DWORD *)StartupInfo.lpReserved2;
    posfile = (char *)(StartupInfo.lpReserved2 + 4);
    posfhnd = (int *)&StartupInfo.lpReserved2[v3 + 4];
    if ( v3 >= 2048 )
      v3 = 2048;
    if ( (int)_nhandle < v3 )
    {
      v4 = (char **)&unk_106CF7A4;
      while ( 1 )
      {
        v5 = (char *)calloc(count: 0x20u, size: 0x40u);
        if ( v5 == nullptr )
          break;
        _nhandle += 32;
        *v4 = v5;
        if ( v5 < v5 + 2048 )
        {
          v6 = v5 + 5;
          do
          {
            *(_DWORD *)(v6 - 5) = -1;
            *(_DWORD *)(v6 + 3) = 0;
            v6[31] &= 0x80u;
            *(_DWORD *)(v6 + 51) = 0;
            *(_WORD *)(v6 - 1) = 2560;
            *((_WORD *)v6 + 16) = 2570;
            v6[47] = 0;
            v6 += 64;
          }
          while ( v6 - 5 < *v4 + 2048 );
        }
        ++v4;
        if ( (int)_nhandle >= v3 )
          goto LABEL_19;
      }
      v3 = _nhandle;
    }
LABEL_19:
    for ( i = 0; i < v3; ++posfile )
    {
      if ( *posfhnd != -1
        && *posfhnd != -2
        && (*posfile & 1) != 0
        && ((*posfile & 8) != 0 || GetFileType(hFile: (HANDLE)*posfhnd) != 0) )
      {
        v8 = &__pioinfo[i >> 5][i & 0x1F];
        v8->osfhnd = *posfhnd;
        v8->osfile = *posfile;
        if ( !InitializeCriticalSectionAndSpinCount(lpCriticalSection: &v8->lock, dwSpinCount: 0xFA0u) )
          return -1;
        ++v8->lockinitflag;
      }
      ++posfhnd;
      ++i;
    }
  }
  for ( j = 0; j < 3; ++j )
  {
    v10 = &__pioinfo[0][j];
    if ( v10->osfhnd == -1 || v10->osfhnd == -2 )
    {
      v10->osfile = -127;
      if ( j != 0 )
        v11 = -(j != 1) - 11;
      else
        v11 = -10;
      StdHandle = GetStdHandle(nStdHandle: v11);
      v13 = (int)StdHandle;
      if ( StdHandle != (HANDLE)-1 && StdHandle != nullptr && (FileType = GetFileType(hFile: StdHandle)) != 0 )
      {
        v10->osfhnd = v13;
        if ( (unsigned __int8)FileType == 2 )
        {
          v10->osfile |= 0x40u;
        }
        else if ( (unsigned __int8)FileType == 3 )
        {
          v10->osfile |= 8u;
        }
        if ( !InitializeCriticalSectionAndSpinCount(lpCriticalSection: &v10->lock, dwSpinCount: 0xFA0u) )
          return -1;
        ++v10->lockinitflag;
      }
      else
      {
        v10->osfile |= 0x40u;
        v10->osfhnd = -2;
      }
    }
    else
    {
      v10->osfile |= 0x80u;
    }
  }
  SetHandleCount(uNumber: _nhandle);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x102FD957
// Name: __ioterm
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void _ioterm()
{
  void **v0; // edi
  char *v1; // eax
  _RTL_CRITICAL_SECTION *v2; // esi

  v0 = (void **)__pioinfo;
  do
  {
    v1 = (char *)*v0;
    if ( *v0 != nullptr )
    {
      if ( v1 < v1 + 2048 )
      {
        v2 = (_RTL_CRITICAL_SECTION *)(v1 + 12);
        do
        {
          if ( v2[-1].SpinCount != 0 )
            DeleteCriticalSection(lpCriticalSection: v2);
          v2 = (_RTL_CRITICAL_SECTION *)((char *)v2 + 64);
        }
        while ( &v2[-1].OwningThread < (void **)((char *)*v0 + 2048) );
      }
      free(pMem: *v0);
      *v0 = nullptr;
    }
    ++v0;
  }
  while ( (int)v0 < (int)&_pmatherr );
}

//------------------------------------------------------------------------------
// Address: 0x102FD9AA
// Name: __crtLCMapStringA_stat
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _crtLCMapStringA_stat(
        localeinfo_struct *plocinfo,
        LCID Locale,
        DWORD dwMapFlags,
        const char *lpSrcStr,
        int cchSrc,
        char *lpDestStr,
        int cchDest,
        UINT code_page,
        int bError)
{
  const char *v9; // eax
  int v10; // ecx
  int v11; // eax
  int v12; // eax
  int v13; // edi
  unsigned int v15; // eax
  void *v16; // esp
  wchar_t *v17; // eax
  unsigned int v18; // eax
  void *v19; // esp
  wchar_t *v20; // edi
  wchar_t *v21; // eax
  int v22; // eax
  _DWORD v23[2]; // [esp+0h] [ebp-1Ch] BYREF
  int v24; // [esp+8h] [ebp-14h] BYREF
  int inbuff_size; // [esp+Ch] [ebp-10h]
  wchar_t *inwbuffer; // [esp+10h] [ebp-Ch]
  int retval; // [esp+14h] [ebp-8h]

  if ( cchSrc > 0 )
  {
    v9 = lpSrcStr;
    v10 = cchSrc;
    while ( 1 )
    {
      --v10;
      if ( *v9 == 0 )
        break;
      ++v9;
      if ( v10 == 0 )
      {
        v10 = -1;
        break;
      }
    }
    v11 = cchSrc - v10 - 1;
    if ( v11 < cchSrc )
      v11 = cchSrc - v10;
    cchSrc = v11;
  }
  retval = 0;
  if ( code_page == 0 )
    code_page = plocinfo->locinfo->lc_codepage;
  v12 = MultiByteToWideChar(
          CodePage: code_page,
          dwFlags: 8 * (bError != 0) + 1,
          lpMultiByteStr: lpSrcStr,
          cbMultiByte: cchSrc,
          lpWideCharStr: nullptr,
          cchWideChar: 0);
  v13 = v12;
  inbuff_size = v12;
  if ( v12 == 0 )
    return 0;
  if ( v12 > 0 && 0xFFFFFFE0 / v12 >= 2 )
  {
    v15 = 2 * v12 + 8;
    if ( v15 > 0x400 )
    {
      v17 = (wchar_t *)MemAlloc_Alloc(nSize: 2 * v13 + 8);
      if ( v17 != nullptr )
      {
        *(_DWORD *)v17 = 56797;
        goto LABEL_20;
      }
    }
    else
    {
      v16 = alloca(v15);
      v17 = (wchar_t *)v23;
      if ( v23 != nullptr )
      {
        v23[0] = 52428;
LABEL_20:
        v17 += 4;
      }
    }
    inwbuffer = v17;
    goto LABEL_23;
  }
  inwbuffer = nullptr;
LABEL_23:
  if ( inwbuffer == nullptr )
    return 0;
  if ( MultiByteToWideChar(
         CodePage: code_page,
         dwFlags: 1u,
         lpMultiByteStr: lpSrcStr,
         cbMultiByte: cchSrc,
         lpWideCharStr: inwbuffer,
         cchWideChar: v13) != 0 )
  {
    retval = LCMapStringW(Locale, dwMapFlags, lpSrcStr: inwbuffer, cchSrc: v13, lpDestStr: nullptr, cchDest: 0);
    if ( retval != 0 )
    {
      if ( (dwMapFlags & 0x400) != 0 )
      {
        if ( cchDest != 0 && retval <= cchDest )
          LCMapStringW(Locale, dwMapFlags, lpSrcStr: inwbuffer, cchSrc: v13, (LPWSTR)lpDestStr, cchDest);
        goto LABEL_46;
      }
      if ( retval <= 0 || 0xFFFFFFE0 / retval < 2 )
      {
        v20 = nullptr;
LABEL_39:
        if ( v20 != nullptr )
        {
          if ( LCMapStringW(
                 Locale,
                 dwMapFlags,
                 lpSrcStr: inwbuffer,
                 cchSrc: inbuff_size,
                 lpDestStr: v20,
                 cchDest: retval) != 0 )
          {
            if ( cchDest != 0 )
              v22 = WideCharToMultiByte(
                      CodePage: code_page,
                      dwFlags: 0,
                      lpWideCharStr: v20,
                      cchWideChar: retval,
                      lpMultiByteStr: lpDestStr,
                      cbMultiByte: cchDest,
                      lpDefaultChar: nullptr,
                      lpUsedDefaultChar: nullptr);
            else
              v22 = WideCharToMultiByte(
                      CodePage: code_page,
                      dwFlags: 0,
                      lpWideCharStr: v20,
                      cchWideChar: retval,
                      lpMultiByteStr: nullptr,
                      cbMultiByte: 0,
                      lpDefaultChar: nullptr,
                      lpUsedDefaultChar: nullptr);
            retval = v22;
          }
          _freea(_Memory: v20);
        }
        goto LABEL_46;
      }
      v18 = 2 * retval + 8;
      if ( v18 > 0x400 )
      {
        v21 = (wchar_t *)MemAlloc_Alloc(nSize: 2 * retval + 8);
        if ( v21 != nullptr )
        {
          *(_DWORD *)v21 = 56797;
          v21 += 4;
        }
        v20 = v21;
        goto LABEL_39;
      }
      v19 = alloca(v18);
      if ( v23 != nullptr )
      {
        v23[0] = 52428;
        v20 = (wchar_t *)&v24;
        goto LABEL_39;
      }
    }
  }
LABEL_46:
  _freea(_Memory: inwbuffer);
  return retval;
}

//------------------------------------------------------------------------------
// Address: 0x102FDB91
// Name: ___crtLCMapStringA
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl __crtLCMapStringA(
        localeinfo_struct *plocinfo,
        LCID Locale,
        DWORD dwMapFlags,
        const char *lpSrcStr,
        int cchSrc,
        char *lpDestStr,
        int cchDest,
        UINT code_page,
        int bError)
{
  int result; // eax
  _LocaleUpdate _loc_update; // [esp+0h] [ebp-10h] BYREF

  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  result = _crtLCMapStringA_stat(
             plocinfo: &_loc_update.localeinfo,
             Locale,
             dwMapFlags,
             lpSrcStr,
             cchSrc,
             lpDestStr,
             cchDest,
             code_page,
             bError);
  if ( _loc_update.updated )
    _loc_update.ptd->_ownlocale &= ~2u;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102FDBE0
// Name: _strlen
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl strlen(char *buf)
{
  char *v1; // ecx
  char v2; // al
  int v3; // eax
  int v4; // eax

  v1 = buf;
  if ( ((unsigned __int8)buf & 3) != 0 )
  {
    while ( 1 )
    {
      v2 = *v1++;
      if ( v2 == 0 )
        break;
      if ( ((unsigned __int8)v1 & 3) == 0 )
        goto main_loop_2;
    }
  }
  else
  {
    do
    {
      do
      {
main_loop_2:
        v3 = (*(_DWORD *)v1 + 2130640639) ^ ~*(_DWORD *)v1;
        v1 += 4;
      }
      while ( (v3 & 0x81010100) == 0 );
      v4 = *((_DWORD *)v1 - 1);
    }
    while ( (_BYTE)v4 != 0 && BYTE1(v4) != 0 && (v4 & 0xFF0000) != 0 && (v4 & 0xFF000000) != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x102FDC6B
// Name: __check_float_string
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall _check_float_string@<eax>(
        unsigned int *pnFloatStrSz@<esi>,
        char **pFloatStr@<edi>,
        unsigned int nFloatStrUsed,
        char *floatstring,
        int *pmalloc_FloatStrFlag)
{
  unsigned int v5; // eax
  char *v6; // eax
  char *v8; // eax

  v5 = *pnFloatStrSz;
  if ( nFloatStrUsed == *pnFloatStrSz )
  {
    if ( *pFloatStr == floatstring )
    {
      v6 = (char *)calloc(count: v5, size: 2u);
      *pFloatStr = v6;
      if ( v6 == nullptr )
        return 0;
      *pmalloc_FloatStrFlag = 1;
      memcpy(dst: (unsigned __int8 *)*pFloatStr, src: (unsigned __int8 *)floatstring, count: *pnFloatStrSz);
    }
    else
    {
      v8 = (char *)_recalloc_crt(ptr: *pFloatStr, count: v5, size: 2u);
      if ( v8 == nullptr )
        return 0;
      *pFloatStr = v8;
    }
    *pnFloatStrSz *= 2;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x102FDCC2
// Name: _inc
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __fastcall inc(int a1, _iobuf *fileptr)
{
  if ( --fileptr->_cnt < 0 )
    return _filbuf(str: fileptr);
  return *(unsigned __int8 *)fileptr->_ptr++;
}

//------------------------------------------------------------------------------
// Address: 0x102FDCD8
// Name: __input_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _input_l(_iobuf *stream, unsigned __int8 *format, localeinfo_struct *plocinfo, char *arglist)
{
  int result; // eax
  int v5; // eax
  ioinfo *v6; // ecx
  ioinfo *v7; // eax
  unsigned __int8 v8; // al
  const unsigned __int8 *v9; // edi
  int v10; // eax
  int v11; // ebx
  int v12; // eax
  int v13; // ecx
  const unsigned __int8 *v14; // eax
  _WORD *v15; // esi
  unsigned __int8 v16; // al
  int v17; // ebx
  int v18; // eax
  int v19; // ecx
  int v20; // edi
  int v21; // ebx
  int v22; // ebx
  int i; // eax
  int v24; // eax
  int v25; // ecx
  int v26; // eax
  int j; // eax
  int v28; // eax
  int v29; // ecx
  int v30; // eax
  int v31; // ecx
  int v32; // ecx
  int v33; // eax
  int k; // eax
  int v35; // eax
  int v36; // ecx
  void (__cdecl *v37)(int, void *, char *, _LocaleUpdate *); // eax
  _WORD *v38; // edi
  int v39; // eax
  int v40; // eax
  unsigned __int8 *v41; // esi
  unsigned __int8 v42; // dl
  unsigned __int8 v43; // cl
  unsigned int v44; // edi
  int v45; // edx
  unsigned __int8 v46; // al
  int v47; // eax
  int v48; // ecx
  int v49; // eax
  int v50; // ecx
  unsigned __int64 v51; // kr00_8
  unsigned int v52; // edi
  unsigned int v53; // esi
  int v54; // eax
  int v55; // ecx
  int v56; // edi
  int v57; // ebx
  int v58; // eax
  int v59; // eax
  int v60; // ecx
  bool v61; // zf
  int v62; // [esp-14h] [ebp-21Ch]
  void *v63; // [esp-10h] [ebp-218h]
  char *v64; // [esp-Ch] [ebp-214h]
  int v65; // [esp-8h] [ebp-210h]
  int v66; // [esp-8h] [ebp-210h]
  int v67; // [esp-8h] [ebp-210h]
  int v68; // [esp-8h] [ebp-210h]
  int v69; // [esp-8h] [ebp-210h]
  int v70; // [esp-8h] [ebp-210h]
  int v71; // [esp-8h] [ebp-210h]
  int v72; // [esp-8h] [ebp-210h]
  int v73; // [esp-8h] [ebp-210h]
  int v74; // [esp-8h] [ebp-210h]
  char *arglistsave; // [esp+8h] [ebp-200h]
  _LocaleUpdate _loc_update; // [esp+Ch] [ebp-1FCh] BYREF
  int wctemp; // [esp+1Ch] [ebp-1ECh] BYREF
  char *v78; // [esp+20h] [ebp-1E8h]
  unsigned int number; // [esp+24h] [ebp-1E4h]
  char temp[4]; // [esp+28h] [ebp-1E0h] BYREF
  unsigned int nFloatStrSz; // [esp+2Ch] [ebp-1DCh] BYREF
  int integer64; // [esp+30h] [ebp-1D8h]
  unsigned __int8 prevchar; // [esp+37h] [ebp-1D1h]
  int malloc_FloatStrFlag; // [esp+38h] [ebp-1D0h] BYREF
  int count; // [esp+3Ch] [ebp-1CCh]
  unsigned __int64 num64; // [esp+40h] [ebp-1C8h]
  void *pointer; // [esp+48h] [ebp-1C0h]
  const unsigned __int8 *v88; // [esp+4Ch] [ebp-1BCh]
  int widthset; // [esp+50h] [ebp-1B8h]
  int comchr; // [esp+54h] [ebp-1B4h]
  char *pFloatStr; // [esp+58h] [ebp-1B0h] BYREF
  int started; // [esp+5Ch] [ebp-1ACh]
  char decimal; // [esp+60h] [ebp-1A8h]
  char negative; // [esp+61h] [ebp-1A7h]
  char fl_wchar_arg; // [esp+62h] [ebp-1A6h]
  char match; // [esp+63h] [ebp-1A5h]
  _iobuf *fileptr; // [esp+64h] [ebp-1A4h]
  char suppress; // [esp+6Bh] [ebp-19Dh]
  int width; // [esp+6Ch] [ebp-19Ch]
  char widechar; // [esp+73h] [ebp-195h]
  char chr[4]; // [esp+74h] [ebp-194h]
  char done_flag; // [esp+7Bh] [ebp-18Dh]
  int charcount; // [esp+7Ch] [ebp-18Ch] BYREF
  unsigned __int8 last; // [esp+83h] [ebp-185h]
  char floatstring[352]; // [esp+84h] [ebp-184h] BYREF
  char AsciiTable[32]; // [esp+1E4h] [ebp-24h] BYREF

  v78 = arglist;
  fileptr = stream;
  pFloatStr = floatstring;
  nFloatStrSz = 350;
  malloc_FloatStrFlag = 0;
  wctemp = 0;
  *(_DWORD *)chr = 0;
  if ( format == nullptr
    || stream == nullptr
    || (stream->_flag & 0x40) == 0
    && ((v5 = fileno(stream)) == -1 || v5 == -2 ? (v6 = &__badioinfo) : (v6 = &__pioinfo[v5 >> 5][v5 & 0x1F]),
        (*((_BYTE *)v6 + 36) & 0x7F) != 0
     || (v5 == -1 || v5 == -2 ? (v7 = &__badioinfo) : (v7 = &__pioinfo[v5 >> 5][v5 & 0x1F]), *((char *)v7 + 36) < 0)) )
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return -1;
  }
  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  v8 = *format;
  match = 0;
  charcount = 0;
  count = 0;
  if ( v8 == 0 )
    goto LABEL_288;
  v9 = format;
  while ( 2 )
  {
    if ( isspace(c: v8) != 0 )
    {
      --charcount;
      v10 = whiteout(counter: &charcount, fileptr);
      if ( v10 != -1 )
        _ungetc_nolock(ch: v10, str: fileptr);
      do
        ++v9;
      while ( isspace(c: *v9) != 0 );
      goto LABEL_272;
    }
    if ( *v9 != 37 )
      goto LABEL_264;
    if ( v9[1] == 37 )
    {
      ++v9;
LABEL_264:
      ++charcount;
      v57 = inc(a1: v65, fileptr);
      v58 = *v9++;
      *(_DWORD *)chr = v57;
      v88 = v9;
      if ( v58 == v57 )
      {
        if ( isleadbyte(c: (unsigned __int8)v57) == 0 )
          goto LABEL_268;
        ++charcount;
        v59 = inc(a1: v74, fileptr);
        v60 = *v9++;
        v88 = v9;
        if ( v60 == v59 )
        {
          --charcount;
          goto LABEL_268;
        }
        if ( v59 != -1 )
          _ungetc_nolock(ch: v59, str: fileptr);
      }
      v61 = v57 == -1;
      goto LABEL_278;
    }
    number = 0;
    prevchar = 0;
    started = 0;
    widthset = 0;
    width = 0;
    decimal = 0;
    negative = 0;
    suppress = 0;
    done_flag = 0;
    fl_wchar_arg = 0;
    widechar = 0;
    last = 1;
    integer64 = 0;
    do
    {
      v11 = *++v9;
      v12 = isdigit(c: (unsigned __int8)v11);
      v13 = v66;
      if ( v12 != 0 )
      {
        ++widthset;
        width = 10 * width + v11 - 48;
        continue;
      }
      if ( v11 > 78 )
      {
        if ( v11 == 104 )
        {
          --last;
          --widechar;
        }
        else
        {
          if ( v11 == 108 )
          {
            v14 = v9 + 1;
            if ( v9[1] == 108 )
              goto LABEL_37;
            ++last;
          }
          else if ( v11 != 119 )
          {
            goto DEFAULT_LABEL;
          }
          ++widechar;
        }
      }
      else
      {
        switch ( v11 )
        {
          case 'N':
            continue;
          case '*':
            ++suppress;
            continue;
          case 'F':
            continue;
          default:
            break;
        }
        if ( v11 != 73 )
        {
          if ( v11 == 76 )
          {
            ++last;
            continue;
          }
DEFAULT_LABEL:
          ++done_flag;
          continue;
        }
        LOBYTE(v13) = v9[1];
        if ( (_BYTE)v13 == 54 )
        {
          v14 = v9 + 2;
          if ( v9[2] == 52 )
          {
LABEL_37:
            ++integer64;
            v9 = v14;
            num64 = 0;
            continue;
          }
        }
        if ( (_BYTE)v13 == 51 && v9[2] == 50 )
        {
          v9 += 2;
          continue;
        }
        if ( (_BYTE)v13 != 100 && (_BYTE)v13 != 105 && (_BYTE)v13 != 111 && (_BYTE)v13 != 120 && (_BYTE)v13 != 88 )
          goto DEFAULT_LABEL;
      }
    }
    while ( done_flag == 0 );
    v88 = v9;
    if ( suppress != 0 )
    {
      v15 = nullptr;
    }
    else
    {
      v15 = *(_WORD **)v78;
      arglistsave = v78;
      v78 += 4;
    }
    pointer = v15;
    done_flag = 0;
    if ( widechar == 0 )
    {
      v16 = *v9;
      if ( *v9 == 83 || (widechar = -1, v16 == 67) )
        widechar = 1;
    }
    v17 = *v9 | 0x20;
    comchr = v17;
    if ( v17 != 110 )
    {
      if ( v17 == 99 || v17 == 123 )
      {
        ++charcount;
        v18 = inc(a1: v13, fileptr);
      }
      else
      {
        v18 = whiteout(counter: &charcount, fileptr);
      }
      *(_DWORD *)chr = v18;
      if ( v18 == -1 )
        goto error_return_0;
      v15 = pointer;
      v9 = v88;
    }
    v19 = widthset;
    if ( widthset != 0 && width == 0 )
      goto LABEL_274;
    if ( v17 > 111 )
    {
      switch ( v17 )
      {
        case 'p':
          last = 1;
          break;
        case 's':
LABEL_129:
          if ( widechar > 0 )
            fl_wchar_arg = 1;
          goto scanit;
        case 'u':
          break;
        case 'x':
          goto LABEL_84;
        case '{':
          if ( widechar > 0 )
            fl_wchar_arg = 1;
          v41 = (unsigned __int8 *)(v9 + 1);
          if ( v9[1] == 94 )
          {
            v41 = (unsigned __int8 *)(v9 + 2);
            decimal = -1;
          }
          memset(dst: (unsigned __int8 *)AsciiTable, value: 0, count: sizeof(AsciiTable));
          if ( *v41 == 93 )
          {
            v42 = 93;
            ++v41;
            AsciiTable[11] = 32;
          }
          else
          {
            v42 = prevchar;
          }
          while ( 1 )
          {
            v46 = *v41;
            if ( *v41 == 93 )
              break;
            ++v41;
            if ( v46 == 45 && v42 != 0 && (v43 = *v41, *v41 != 93) )
            {
              ++v41;
              if ( v42 >= v43 )
              {
                last = v42;
                v42 = v43;
              }
              else
              {
                last = v43;
              }
              if ( v42 < last )
              {
                v44 = v42;
                v45 = (unsigned __int8)(last - v42);
                do
                {
                  AsciiTable[v44 >> 3] |= 1 << (v44 & 7);
                  ++v44;
                  --v45;
                }
                while ( v45 != 0 );
                v17 = comchr;
              }
              v19 = last & 7;
              AsciiTable[last >> 3] |= 1 << v19;
              v42 = 0;
            }
            else
            {
              v42 = v46;
              v19 = v46 & 7;
              AsciiTable[v46 >> 3] |= 1 << (v46 & 7);
              v17 = comchr;
            }
          }
          v88 = v41;
          v15 = pointer;
scanit:
          --charcount;
          v38 = v15;
          if ( *(_DWORD *)chr != -1 )
          {
            _ungetc_nolock(ch: *(int *)chr, str: fileptr);
            v19 = v68;
          }
          while ( 1 )
          {
            if ( widthset != 0 )
            {
              v39 = width--;
              if ( v39 == 0 )
                goto LABEL_202;
            }
            ++charcount;
            v40 = inc(a1: v19, fileptr);
            *(_DWORD *)chr = v40;
            if ( v40 == -1 )
              goto LABEL_200;
            if ( v17 != 99 )
            {
              if ( v17 != 115 )
                goto LABEL_293;
              if ( v40 >= 9 && v40 <= 13 )
              {
LABEL_200:
                --charcount;
                if ( v40 != -1 )
                  _ungetc_nolock(ch: v40, str: fileptr);
LABEL_202:
                if ( v38 != v15 )
                {
                  if ( suppress == 0 )
                  {
                    ++count;
                    if ( v17 != 99 )
                    {
                      if ( fl_wchar_arg != 0 )
                        *(_WORD *)pointer = 0;
                      else
                        *(_BYTE *)pointer = 0;
                    }
                  }
                  goto LABEL_262;
                }
                goto error_return_0;
              }
              if ( v40 == 32 )
              {
LABEL_293:
                if ( v17 != 123 )
                  goto LABEL_200;
                v19 = decimal ^ AsciiTable[v40 >> 3];
                v17 = comchr;
                if ( ((1 << (v40 & 7)) & v19) == 0 )
                  goto LABEL_200;
              }
            }
            if ( suppress != 0 )
            {
              v38 = (_WORD *)((char *)v38 + 1);
            }
            else
            {
              if ( fl_wchar_arg != 0 )
              {
                temp[0] = v40;
                if ( isleadbyte(c: (unsigned __int8)v40) != 0 )
                {
                  ++charcount;
                  temp[1] = inc(a1: v69, fileptr);
                }
                wctemp = 63;
                _mbtowc_l(
                  pwc: (wchar_t *)&wctemp,
                  s: temp,
                  n: _loc_update.localeinfo.locinfo->mb_cur_max,
                  plocinfo: &_loc_update.localeinfo);
                *v15++ = wctemp;
              }
              else
              {
                *(_BYTE *)v15 = v40;
                v15 = (_WORD *)((char *)v15 + 1);
              }
              pointer = v15;
            }
          }
        default:
          goto LABEL_153;
      }
LABEL_209:
      v21 = *(_DWORD *)chr;
      if ( *(_DWORD *)chr == 45 )
      {
        negative = 1;
      }
      else if ( *(_DWORD *)chr != 43 )
      {
        goto getnum;
      }
      if ( --width == 0 && widthset != 0 )
      {
        done_flag = 1;
        goto getnum;
      }
      ++charcount;
      v21 = inc(a1: widthset, fileptr);
      goto LABEL_216;
    }
    switch ( v17 )
    {
      case 'o':
        goto LABEL_209;
      case 'c':
        if ( widthset == 0 )
        {
          ++width;
          widthset = 1;
        }
        goto LABEL_129;
      case 'd':
        goto LABEL_209;
      default:
        break;
    }
    if ( v17 <= 100 )
      goto LABEL_153;
    if ( v17 <= 103 )
    {
      v22 = 0;
      if ( *(_DWORD *)chr == 45 )
      {
        *pFloatStr = 45;
        v22 = 1;
        goto f_incwidth;
      }
      if ( *(_DWORD *)chr == 43 )
      {
f_incwidth:
        --width;
        ++charcount;
        *(_DWORD *)chr = inc(a1: v19, fileptr);
      }
      if ( widthset == 0 )
        width = -1;
      for ( i = (unsigned __int8)chr[0]; isdigit(c: i) != 0; i = (unsigned __int8)chr[0] )
      {
        v24 = width--;
        if ( v24 == 0 )
          break;
        ++started;
        pFloatStr[v22] = chr[0];
        if ( _check_float_string(
               pnFloatStrSz: &nFloatStrSz,
               &pFloatStr,
               nFloatStrUsed: ++v22,
               floatstring,
               pmalloc_FloatStrFlag: &malloc_FloatStrFlag) == 0 )
          goto error_return_0;
        ++charcount;
        *(_DWORD *)chr = inc(a1: v25, fileptr);
      }
      decimal = *_loc_update.localeinfo.locinfo->lconv->decimal_point;
      if ( decimal == chr[0] )
      {
        v26 = width--;
        if ( v26 != 0 )
        {
          ++charcount;
          *(_DWORD *)chr = inc(a1: v67, fileptr);
          pFloatStr[v22] = decimal;
          if ( _check_float_string(
                 pnFloatStrSz: &nFloatStrSz,
                 &pFloatStr,
                 nFloatStrUsed: ++v22,
                 floatstring,
                 pmalloc_FloatStrFlag: &malloc_FloatStrFlag) == 0 )
            goto error_return_0;
          for ( j = (unsigned __int8)chr[0]; isdigit(c: j) != 0; j = (unsigned __int8)chr[0] )
          {
            v28 = width--;
            if ( v28 == 0 )
              break;
            ++started;
            pFloatStr[v22] = chr[0];
            if ( _check_float_string(
                   pnFloatStrSz: &nFloatStrSz,
                   &pFloatStr,
                   nFloatStrUsed: ++v22,
                   floatstring,
                   pmalloc_FloatStrFlag: &malloc_FloatStrFlag) == 0 )
              goto error_return_0;
            ++charcount;
            *(_DWORD *)chr = inc(a1: v29, fileptr);
          }
        }
      }
      if ( started != 0 && (*(_DWORD *)chr == 101 || *(_DWORD *)chr == 69) )
      {
        v30 = width--;
        if ( v30 != 0 )
        {
          pFloatStr[v22] = 101;
          if ( _check_float_string(
                 pnFloatStrSz: &nFloatStrSz,
                 &pFloatStr,
                 nFloatStrUsed: ++v22,
                 floatstring,
                 pmalloc_FloatStrFlag: &malloc_FloatStrFlag) == 0 )
            goto error_return_0;
          ++charcount;
          *(_DWORD *)chr = inc(a1: v31, fileptr);
          if ( *(_DWORD *)chr == 45 )
          {
            pFloatStr[v22] = 45;
            if ( _check_float_string(
                   pnFloatStrSz: &nFloatStrSz,
                   &pFloatStr,
                   nFloatStrUsed: ++v22,
                   floatstring,
                   pmalloc_FloatStrFlag: &malloc_FloatStrFlag) == 0 )
              goto error_return_0;
f_incwidth2:
            v33 = width--;
            if ( v33 != 0 )
            {
              ++charcount;
              *(_DWORD *)chr = inc(a1: v32, fileptr);
            }
            else
            {
              width = 0;
            }
          }
          else if ( *(_DWORD *)chr == 43 )
          {
            goto f_incwidth2;
          }
          for ( k = (unsigned __int8)chr[0]; isdigit(c: k) != 0; k = (unsigned __int8)chr[0] )
          {
            v35 = width--;
            if ( v35 == 0 )
              break;
            ++started;
            pFloatStr[v22] = chr[0];
            if ( _check_float_string(
                   pnFloatStrSz: &nFloatStrSz,
                   &pFloatStr,
                   nFloatStrUsed: ++v22,
                   floatstring,
                   pmalloc_FloatStrFlag: &malloc_FloatStrFlag) == 0 )
              goto error_return_0;
            ++charcount;
            *(_DWORD *)chr = inc(a1: v36, fileptr);
          }
        }
      }
      --charcount;
      if ( *(_DWORD *)chr != -1 )
        _ungetc_nolock(ch: *(int *)chr, str: fileptr);
      if ( started != 0 )
      {
        if ( suppress == 0 )
        {
          ++count;
          v64 = pFloatStr;
          v63 = pointer;
          pFloatStr[v22] = 0;
          v62 = (char)last - 1;
          v37 = (void (__cdecl *)(int, void *, char *, _LocaleUpdate *))DecodePointer(Ptr: off_1042D240);
          v37(a1: v62, a2: v63, a3: v64, a4: &_loc_update);
        }
        goto LABEL_262;
      }
      goto error_return_0;
    }
    if ( v17 != 105 )
    {
      if ( v17 == 110 )
      {
        v20 = charcount;
        if ( suppress == 0 )
        {
assign_num:
          if ( integer64 != 0 )
          {
            *(_QWORD *)v15 = num64;
          }
          else if ( last != 0 )
          {
            *(_DWORD *)v15 = v20;
          }
          else
          {
            *v15 = v20;
          }
        }
        goto LABEL_262;
      }
LABEL_153:
      if ( *v9 == *(_DWORD *)chr )
      {
        --match;
        if ( suppress == 0 )
          v78 = arglistsave;
        goto LABEL_262;
      }
LABEL_274:
      v61 = *(_DWORD *)chr == -1;
LABEL_278:
      if ( !v61 )
        _ungetc_nolock(ch: *(int *)chr, str: fileptr);
      goto error_return_0;
    }
    comchr = 100;
LABEL_84:
    v21 = *(_DWORD *)chr;
    if ( *(_DWORD *)chr == 45 )
    {
      negative = 1;
      goto x_incwidth;
    }
    if ( *(_DWORD *)chr == 43 )
    {
x_incwidth:
      if ( --width != 0 || widthset == 0 )
      {
        ++charcount;
        v21 = inc(a1: widthset, fileptr);
        *(_DWORD *)chr = v21;
      }
      else
      {
        done_flag = 1;
      }
    }
    if ( v21 == 48 )
    {
      ++charcount;
      v47 = inc(a1: v19, fileptr);
      v21 = v47;
      *(_DWORD *)chr = v47;
      if ( (_BYTE)v47 != 120 && (_BYTE)v47 != 88 )
      {
        started = 1;
        if ( comchr != 120 )
        {
          if ( widthset != 0 && --width == 0 )
            ++done_flag;
          comchr = 111;
          goto getnum;
        }
        --charcount;
        if ( v47 != -1 )
          _ungetc_nolock(ch: v47, str: fileptr);
        v21 = 48;
LABEL_216:
        *(_DWORD *)chr = v21;
        goto getnum;
      }
      ++charcount;
      v21 = inc(a1: v48, fileptr);
      *(_DWORD *)chr = v21;
      if ( widthset != 0 )
      {
        width -= 2;
        if ( width < 1 )
          ++done_flag;
      }
      comchr = 120;
    }
getnum:
    if ( integer64 == 0 )
    {
      v20 = number;
      if ( done_flag == 0 )
      {
        while ( 1 )
        {
          if ( comchr == 120 || comchr == 112 )
          {
            if ( isxdigit(c: (unsigned __int8)v21) == 0 )
            {
LABEL_248:
              --charcount;
              if ( v21 != -1 )
                _ungetc_nolock(ch: v21, str: fileptr);
              break;
            }
            v56 = 16 * v20;
            v21 = hextodec(chr: v21);
            v55 = v73;
            *(_DWORD *)chr = v21;
          }
          else
          {
            v54 = isdigit(c: (unsigned __int8)v21);
            v55 = v72;
            if ( v54 == 0 )
              goto LABEL_248;
            if ( comchr == 111 )
            {
              if ( v21 >= 56 )
                goto LABEL_248;
              v56 = 8 * v20;
            }
            else
            {
              v56 = 10 * v20;
            }
          }
          ++started;
          v20 = v56 + v21 - 48;
          if ( widthset != 0 && --width == 0 )
            break;
          ++charcount;
          v21 = inc(a1: v55, fileptr);
          *(_DWORD *)chr = v21;
        }
      }
      if ( negative != 0 )
        v20 = -v20;
      goto LABEL_252;
    }
    if ( done_flag != 0 )
      goto LABEL_233;
    while ( 2 )
    {
      if ( comchr != 120 && comchr != 112 )
      {
        v49 = isdigit(c: (unsigned __int8)v21);
        v50 = v70;
        if ( v49 == 0 )
          break;
        if ( comchr == 111 )
        {
          if ( v21 >= 56 )
            break;
          v51 = 8 * num64;
        }
        else
        {
          v51 = 10 * num64;
        }
        goto LABEL_228;
      }
      if ( isxdigit(c: (unsigned __int8)v21) != 0 )
      {
        v52 = num64 >> 28;
        v53 = 16 * num64;
        v21 = hextodec(chr: v21);
        v50 = v71;
        *(_DWORD *)chr = v21;
        v51 = __PAIR64__(v52, v53);
LABEL_228:
        ++started;
        num64 = v21 - 48 + v51;
        if ( widthset != 0 && --width == 0 )
          goto LABEL_233;
        ++charcount;
        v21 = inc(a1: v50, fileptr);
        *(_DWORD *)chr = v21;
        continue;
      }
      break;
    }
    --charcount;
    if ( v21 != -1 )
      _ungetc_nolock(ch: v21, str: fileptr);
LABEL_233:
    v20 = number;
    if ( negative != 0 )
      num64 = -(__int64)num64;
LABEL_252:
    if ( comchr == 70 )
      started = 0;
    if ( started == 0 )
      goto error_return_0;
    if ( suppress == 0 )
    {
      ++count;
      v15 = pointer;
      goto assign_num;
    }
LABEL_262:
    ++match;
    v9 = ++v88;
LABEL_268:
    if ( *(_DWORD *)chr != -1 )
    {
LABEL_272:
      v8 = *v9;
      if ( *v9 == 0 )
        goto error_return_0;
      continue;
    }
    break;
  }
  if ( *v9 == 37 && v88[1] == 110 )
  {
    v9 = v88;
    goto LABEL_272;
  }
error_return_0:
  if ( malloc_FloatStrFlag == 1 )
    free(pMem: pFloatStr);
  if ( *(_DWORD *)chr == -1 )
  {
    result = count;
    if ( count == 0 && match == 0 )
      result = -1;
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
    return result;
  }
LABEL_288:
  if ( _loc_update.updated )
    _loc_update.ptd->_ownlocale &= ~2u;
  return count;
}

//------------------------------------------------------------------------------
// Address: 0x102FECDC
// Name: _hextodec
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __cdecl hextodec(unsigned __int8 chr)
{
  bool v1; // zf
  unsigned int result; // eax

  v1 = isdigit(c: chr) == 0;
  result = (char)chr;
  if ( v1 )
    return ((char)chr & 0xFFFFFFDF) - 7;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102FECFC
// Name: _whiteout
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall whiteout@<eax>(int *counter@<esi>, int a2@<ecx>, _iobuf *fileptr)
{
  int v3; // ebx
  int v4; // eax
  int v6; // [esp-4h] [ebp-8h]

  do
  {
    ++*counter;
    v3 = inc(a1: a2, fileptr);
    if ( v3 == -1 )
      break;
    v4 = isspace(c: (unsigned __int8)v3);
    a2 = v6;
  }
  while ( v4 != 0 );
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x102FED26
// Name: __input_s_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _input_s_l(_iobuf *stream, const unsigned __int8 *format, localeinfo_struct *plocinfo, char *arglist)
{
  int result; // eax
  int v5; // eax
  ioinfo *v6; // ecx
  ioinfo *v7; // eax
  unsigned __int8 v8; // al
  int v9; // eax
  const unsigned __int8 *v10; // esi
  const unsigned __int8 *v11; // esi
  int v12; // ebx
  int v13; // eax
  int v14; // ecx
  unsigned __int8 *v15; // eax
  _BYTE *v16; // ebx
  unsigned __int8 v17; // al
  int v18; // edi
  int v19; // eax
  int v20; // ecx
  unsigned int v21; // eax
  unsigned int v22; // eax
  int v23; // ebx
  int v24; // ebx
  int i; // eax
  int v26; // eax
  int v27; // ecx
  int v28; // eax
  int j; // eax
  int v30; // eax
  int v31; // ecx
  int v32; // eax
  int v33; // ecx
  int v34; // ecx
  int v35; // eax
  int k; // eax
  int v37; // eax
  int v38; // ecx
  void (__cdecl *v39)(int, void *, char *, _LocaleUpdate *); // eax
  _BYTE *v40; // esi
  int v41; // eax
  int v42; // eax
  unsigned __int8 *v43; // esi
  unsigned __int8 v44; // dl
  unsigned __int8 v45; // cl
  unsigned int v46; // edi
  int v47; // edx
  unsigned __int8 v48; // al
  int v49; // eax
  int v50; // ecx
  int v51; // eax
  int v52; // ecx
  int v53; // eax
  int v54; // ecx
  unsigned int v55; // eax
  int v56; // ebx
  int v57; // eax
  int v58; // eax
  int v59; // ecx
  bool v60; // zf
  int *v61; // eax
  int v62; // [esp-14h] [ebp-220h]
  void *v63; // [esp-10h] [ebp-21Ch]
  char *v64; // [esp-Ch] [ebp-218h]
  int v65; // [esp-8h] [ebp-214h]
  int v66; // [esp-8h] [ebp-214h]
  int v67; // [esp-8h] [ebp-214h]
  int v68; // [esp-8h] [ebp-214h]
  int v69; // [esp-8h] [ebp-214h]
  int v70; // [esp-8h] [ebp-214h]
  int v71; // [esp-8h] [ebp-214h]
  int v72; // [esp-8h] [ebp-214h]
  int v73; // [esp-8h] [ebp-214h]
  int v74; // [esp-8h] [ebp-214h]
  int v75; // [esp-8h] [ebp-214h]
  _LocaleUpdate _loc_update; // [esp+8h] [ebp-204h] BYREF
  int format_error; // [esp+18h] [ebp-1F4h]
  int wctemp; // [esp+1Ch] [ebp-1F0h] BYREF
  char *arglistsave; // [esp+20h] [ebp-1ECh]
  int comchr; // [esp+24h] [ebp-1E8h]
  char *v81; // [esp+28h] [ebp-1E4h]
  char temp[4]; // [esp+2Ch] [ebp-1E0h] BYREF
  int integer64; // [esp+30h] [ebp-1DCh]
  unsigned int nFloatStrSz; // [esp+34h] [ebp-1D8h] BYREF
  unsigned __int8 prevchar; // [esp+3Bh] [ebp-1D1h]
  int malloc_FloatStrFlag; // [esp+3Ch] [ebp-1D0h] BYREF
  unsigned int array_width; // [esp+40h] [ebp-1CCh]
  int count; // [esp+44h] [ebp-1C8h]
  unsigned int number; // [esp+48h] [ebp-1C4h]
  int widthset; // [esp+4Ch] [ebp-1C0h]
  void *pointer; // [esp+50h] [ebp-1BCh]
  unsigned __int64 num64; // [esp+54h] [ebp-1B8h]
  const unsigned __int8 *v93; // [esp+5Ch] [ebp-1B0h]
  int started; // [esp+60h] [ebp-1ACh]
  char *pFloatStr; // [esp+64h] [ebp-1A8h] BYREF
  char negative; // [esp+68h] [ebp-1A4h]
  char decimal; // [esp+69h] [ebp-1A3h]
  char match; // [esp+6Ah] [ebp-1A2h]
  char fl_wchar_arg; // [esp+6Bh] [ebp-1A1h]
  _iobuf *fileptr; // [esp+6Ch] [ebp-1A0h]
  int width; // [esp+70h] [ebp-19Ch]
  char suppress; // [esp+76h] [ebp-196h]
  char widechar; // [esp+77h] [ebp-195h]
  char chr[4]; // [esp+78h] [ebp-194h]
  char done_flag; // [esp+7Fh] [ebp-18Dh]
  int charcount; // [esp+80h] [ebp-18Ch] BYREF
  unsigned __int8 last; // [esp+87h] [ebp-185h]
  char floatstring[352]; // [esp+88h] [ebp-184h] BYREF
  char AsciiTable[32]; // [esp+1E8h] [ebp-24h] BYREF

  v81 = arglist;
  fileptr = stream;
  v93 = format;
  pFloatStr = floatstring;
  nFloatStrSz = 350;
  malloc_FloatStrFlag = 0;
  wctemp = 0;
  *(_DWORD *)chr = 0;
  format_error = 0;
  if ( format == nullptr
    || stream == nullptr
    || (stream->_flag & 0x40) == 0
    && ((v5 = fileno(stream)) == -1 || v5 == -2 ? (v6 = &__badioinfo) : (v6 = &__pioinfo[v5 >> 5][v5 & 0x1F]),
        (*((_BYTE *)v6 + 36) & 0x7F) != 0
     || (v5 == -1 || v5 == -2 ? (v7 = &__badioinfo) : (v7 = &__pioinfo[v5 >> 5][v5 & 0x1F]), *((char *)v7 + 36) < 0)) )
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return -1;
  }
  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  v8 = *format;
  match = 0;
  charcount = 0;
  count = 0;
  if ( v8 == 0 )
    goto LABEL_307;
  while ( 2 )
  {
    if ( isspace(c: v8) != 0 )
    {
      --charcount;
      v9 = whiteout(counter: &charcount, a2: v65, fileptr);
      if ( v9 != -1 )
        _ungetc_nolock(ch: v9, str: fileptr);
      v10 = v93;
      do
        ++v10;
      while ( isspace(c: *v10) != 0 );
      v93 = v10;
      goto LABEL_279;
    }
    v11 = v93;
    if ( *v93 != 37 )
      goto LABEL_271;
    if ( v93[1] == 37 )
    {
      v11 = v93 + 1;
LABEL_271:
      ++charcount;
      v56 = inc(a1: v65, fileptr);
      v57 = *v11;
      v10 = v11 + 1;
      *(_DWORD *)chr = v56;
      v93 = v10;
      if ( v57 == v56 )
      {
        if ( isleadbyte(c: (unsigned __int8)v56) == 0 )
          goto LABEL_275;
        ++charcount;
        v58 = inc(a1: v75, fileptr);
        v59 = *v10++;
        v93 = v10;
        if ( v59 == v58 )
        {
          --charcount;
          goto LABEL_275;
        }
        if ( v58 != -1 )
          _ungetc_nolock(ch: v58, str: fileptr);
      }
      v60 = v56 == -1;
LABEL_295:
      if ( !v60 )
        _ungetc_nolock(ch: *(int *)chr, str: fileptr);
      goto error_return_1;
    }
    number = 0;
    prevchar = 0;
    started = 0;
    widthset = 0;
    width = 0;
    array_width = 0;
    decimal = 0;
    negative = 0;
    suppress = 0;
    done_flag = 0;
    fl_wchar_arg = 0;
    widechar = 0;
    last = 1;
    integer64 = 0;
    do
    {
      v12 = *++v11;
      v13 = isdigit(c: (unsigned __int8)v12);
      v14 = v66;
      if ( v13 != 0 )
      {
        ++widthset;
        width = 10 * width + v12 - 48;
        continue;
      }
      if ( v12 > 78 )
      {
        if ( v12 == 104 )
        {
          --last;
          --widechar;
        }
        else
        {
          if ( v12 == 108 )
          {
            v15 = (unsigned __int8 *)(v11 + 1);
            if ( v11[1] == 108 )
              goto LABEL_37;
            ++last;
          }
          else if ( v12 != 119 )
          {
            goto DEFAULT_LABEL_0;
          }
          ++widechar;
        }
      }
      else
      {
        switch ( v12 )
        {
          case 'N':
            continue;
          case '*':
            ++suppress;
            continue;
          case 'F':
            continue;
          default:
            break;
        }
        if ( v12 != 73 )
        {
          if ( v12 == 76 )
          {
            ++last;
            continue;
          }
DEFAULT_LABEL_0:
          ++done_flag;
          continue;
        }
        LOBYTE(v14) = v11[1];
        if ( (_BYTE)v14 == 54 )
        {
          v15 = (unsigned __int8 *)(v11 + 2);
          if ( v11[2] == 52 )
          {
LABEL_37:
            ++integer64;
            v11 = v15;
            num64 = 0;
            continue;
          }
        }
        if ( (_BYTE)v14 == 51 && v11[2] == 50 )
        {
          v11 += 2;
          continue;
        }
        if ( (_BYTE)v14 != 100 && (_BYTE)v14 != 105 && (_BYTE)v14 != 111 && (_BYTE)v14 != 120 && (_BYTE)v14 != 88 )
          goto DEFAULT_LABEL_0;
      }
    }
    while ( done_flag == 0 );
    v93 = v11;
    if ( suppress != 0 )
    {
      v16 = nullptr;
    }
    else
    {
      v16 = *(_BYTE **)v81;
      arglistsave = v81;
      v81 += 4;
    }
    pointer = v16;
    done_flag = 0;
    if ( widechar == 0 )
    {
      v17 = *v11;
      if ( *v11 == 83 || (widechar = -1, v17 == 67) )
        widechar = 1;
    }
    v18 = *v11 | 0x20;
    comchr = v18;
    if ( v18 != 110 )
    {
      if ( v18 == 99 || v18 == 123 )
      {
        ++charcount;
        v19 = inc(a1: v14, fileptr);
      }
      else
      {
        v19 = whiteout(counter: &charcount, a2: v14, fileptr);
      }
      *(_DWORD *)chr = v19;
      if ( v19 == -1 )
        goto error_return_1;
      v16 = pointer;
      v11 = v93;
      v18 = comchr;
    }
    v20 = widthset;
    if ( widthset != 0 && width == 0 )
    {
      v60 = *(_DWORD *)chr == -1;
      goto LABEL_295;
    }
    if ( suppress == 0 && (v18 == 99 || v18 == 115 || v18 == 123) )
    {
      v16 = *(_BYTE **)arglistsave;
      arglistsave += 4;
      v81 = arglistsave + 4;
      v21 = *(_DWORD *)arglistsave;
      pointer = v16;
      array_width = v21;
      if ( v21 == 0 )
      {
        if ( widechar <= 0 )
          *v16 = 0;
        else
          *(_WORD *)v16 = 0;
        *_errno() = 12;
        goto error_return_1;
      }
    }
    if ( v18 > 111 )
    {
      if ( v18 == 112 )
      {
        last = 1;
        goto LABEL_218;
      }
      if ( v18 != 115 )
      {
        if ( v18 == 117 )
          goto LABEL_218;
        if ( v18 == 120 )
          goto LABEL_89;
        if ( v18 != 123 )
          goto LABEL_162;
        if ( widechar > 0 )
          fl_wchar_arg = 1;
        v43 = (unsigned __int8 *)(v11 + 1);
        if ( *v43 == 94 )
        {
          ++v43;
          decimal = -1;
        }
        memset(dst: (unsigned __int8 *)AsciiTable, value: 0, count: sizeof(AsciiTable));
        if ( *v43 == 93 )
        {
          v44 = 93;
          ++v43;
          AsciiTable[11] = 32;
        }
        else
        {
          v44 = prevchar;
        }
        while ( 1 )
        {
          v48 = *v43;
          if ( *v43 == 93 )
            break;
          ++v43;
          if ( v48 == 45 && v44 != 0 && (v45 = *v43, *v43 != 93) )
          {
            ++v43;
            if ( v44 >= v45 )
            {
              last = v44;
              v44 = v45;
            }
            else
            {
              last = v45;
            }
            if ( v44 < last )
            {
              v46 = v44;
              v47 = (unsigned __int8)(last - v44);
              do
              {
                AsciiTable[v46 >> 3] |= 1 << (v46 & 7);
                ++v46;
                --v47;
              }
              while ( v47 != 0 );
            }
            v20 = last & 7;
            AsciiTable[last >> 3] |= 1 << v20;
            v44 = 0;
          }
          else
          {
            v44 = v48;
            v20 = v48 & 7;
            AsciiTable[v48 >> 3] |= 1 << (v48 & 7);
          }
        }
        v16 = pointer;
        v18 = comchr;
        v93 = v43;
scanit_0:
        --charcount;
        v40 = v16;
        if ( *(_DWORD *)chr != -1 )
        {
          _ungetc_nolock(ch: *(int *)chr, str: fileptr);
          v20 = v68;
        }
        if ( v18 == 99 )
        {
          while ( 1 )
          {
LABEL_140:
            if ( widthset != 0 )
            {
              v41 = width--;
              if ( v41 == 0 )
                goto LABEL_211;
            }
            ++charcount;
            v42 = inc(a1: v20, fileptr);
            *(_DWORD *)chr = v42;
            if ( v42 == -1 )
              goto LABEL_209;
            if ( v18 != 99 )
            {
              if ( v18 != 115 )
                goto LABEL_312;
              if ( v42 >= 9 && v42 <= 13 )
              {
LABEL_209:
                --charcount;
                if ( v42 != -1 )
                  _ungetc_nolock(ch: v42, str: fileptr);
LABEL_211:
                if ( v40 != v16 )
                {
                  if ( suppress == 0 )
                  {
                    ++count;
                    if ( comchr != 99 )
                    {
                      if ( fl_wchar_arg != 0 )
                        *(_WORD *)pointer = 0;
                      else
                        *(_BYTE *)pointer = 0;
                    }
                  }
                  goto LABEL_269;
                }
                goto error_return_1;
              }
              if ( v42 == 32 )
              {
LABEL_312:
                if ( v18 != 123 )
                  goto LABEL_209;
                v20 = decimal ^ AsciiTable[v42 >> 3];
                if ( ((1 << (v42 & 7)) & v20) == 0 )
                  goto LABEL_209;
                v18 = comchr;
              }
            }
            if ( suppress == 0 )
              break;
            ++v40;
          }
          if ( array_width == 0 )
          {
            v61 = _errno();
            v60 = fl_wchar_arg == 0;
            *v61 = 12;
            if ( v60 )
              *v40 = 0;
            else
              *(_WORD *)v40 = 0;
            goto error_return_1;
          }
          if ( fl_wchar_arg != 0 )
          {
            temp[0] = v42;
            if ( isleadbyte(c: (unsigned __int8)v42) != 0 )
            {
              ++charcount;
              temp[1] = inc(a1: v69, fileptr);
            }
            wctemp = 63;
            _mbtowc_l(
              pwc: (wchar_t *)&wctemp,
              s: temp,
              n: _loc_update.localeinfo.locinfo->mb_cur_max,
              plocinfo: &_loc_update.localeinfo);
            *(_WORD *)v16 = wctemp;
            v16 += 2;
          }
          else
          {
            *v16++ = v42;
          }
          pointer = v16;
        }
        --array_width;
        goto LABEL_140;
      }
LABEL_134:
      if ( widechar > 0 )
        fl_wchar_arg = 1;
      goto scanit_0;
    }
    if ( v18 == 111 )
      goto LABEL_218;
    if ( v18 == 99 )
    {
      if ( widthset == 0 )
      {
        ++width;
        widthset = 1;
      }
      goto LABEL_134;
    }
    if ( v18 != 100 )
    {
      if ( v18 > 100 )
      {
        if ( v18 > 103 )
        {
          if ( v18 != 105 )
          {
            if ( v18 == 110 )
            {
              v22 = charcount;
              if ( suppress == 0 )
              {
assign_num_0:
                if ( integer64 != 0 )
                {
                  *(_QWORD *)v16 = num64;
                }
                else if ( last != 0 )
                {
                  *(_DWORD *)v16 = v22;
                }
                else
                {
                  *(_WORD *)v16 = v22;
                }
              }
              goto LABEL_269;
            }
            goto LABEL_162;
          }
          v18 = 100;
LABEL_89:
          v23 = *(_DWORD *)chr;
          if ( *(_DWORD *)chr == 45 )
          {
            negative = 1;
            goto x_incwidth_0;
          }
          if ( *(_DWORD *)chr == 43 )
          {
x_incwidth_0:
            if ( --width != 0 || widthset == 0 )
            {
              ++charcount;
              v23 = inc(a1: widthset, fileptr);
              *(_DWORD *)chr = v23;
            }
            else
            {
              done_flag = 1;
            }
          }
          if ( v23 == 48 )
          {
            ++charcount;
            v49 = inc(a1: v20, fileptr);
            v23 = v49;
            *(_DWORD *)chr = v49;
            if ( (_BYTE)v49 == 120 || (_BYTE)v49 == 88 )
            {
              ++charcount;
              v23 = inc(a1: v50, fileptr);
              *(_DWORD *)chr = v23;
              if ( widthset != 0 )
              {
                width -= 2;
                if ( width < 1 )
                  ++done_flag;
              }
              v70 = 120;
LABEL_205:
              v18 = v70;
            }
            else
            {
              started = 1;
              if ( v18 != 120 )
              {
                if ( widthset != 0 && --width == 0 )
                  ++done_flag;
                v70 = 111;
                goto LABEL_205;
              }
              --charcount;
              if ( v49 != -1 )
                _ungetc_nolock(ch: v49, str: fileptr);
              v23 = 48;
LABEL_225:
              *(_DWORD *)chr = v23;
            }
          }
          goto getnum_0;
        }
        v24 = 0;
        if ( *(_DWORD *)chr == 45 )
        {
          *pFloatStr = 45;
          v24 = 1;
          goto f_incwidth_0;
        }
        if ( *(_DWORD *)chr == 43 )
        {
f_incwidth_0:
          --width;
          ++charcount;
          *(_DWORD *)chr = inc(a1: v20, fileptr);
        }
        if ( widthset == 0 )
          width = -1;
        for ( i = (unsigned __int8)chr[0]; isdigit(c: i) != 0; i = (unsigned __int8)chr[0] )
        {
          v26 = width--;
          if ( v26 == 0 )
            break;
          ++started;
          pFloatStr[v24] = chr[0];
          if ( _check_float_string(
                 pnFloatStrSz: &nFloatStrSz,
                 &pFloatStr,
                 nFloatStrUsed: ++v24,
                 floatstring,
                 pmalloc_FloatStrFlag: &malloc_FloatStrFlag) == 0 )
            goto error_return_1;
          ++charcount;
          *(_DWORD *)chr = inc(a1: v27, fileptr);
        }
        decimal = *_loc_update.localeinfo.locinfo->lconv->decimal_point;
        if ( decimal == chr[0] )
        {
          v28 = width--;
          if ( v28 != 0 )
          {
            ++charcount;
            *(_DWORD *)chr = inc(a1: v67, fileptr);
            pFloatStr[v24] = decimal;
            if ( _check_float_string(
                   pnFloatStrSz: &nFloatStrSz,
                   &pFloatStr,
                   nFloatStrUsed: ++v24,
                   floatstring,
                   pmalloc_FloatStrFlag: &malloc_FloatStrFlag) == 0 )
              goto error_return_1;
            for ( j = (unsigned __int8)chr[0]; isdigit(c: j) != 0; j = (unsigned __int8)chr[0] )
            {
              v30 = width--;
              if ( v30 == 0 )
                break;
              ++started;
              pFloatStr[v24] = chr[0];
              if ( _check_float_string(
                     pnFloatStrSz: &nFloatStrSz,
                     &pFloatStr,
                     nFloatStrUsed: ++v24,
                     floatstring,
                     pmalloc_FloatStrFlag: &malloc_FloatStrFlag) == 0 )
                goto error_return_1;
              ++charcount;
              *(_DWORD *)chr = inc(a1: v31, fileptr);
            }
          }
        }
        if ( started != 0 && (*(_DWORD *)chr == 101 || *(_DWORD *)chr == 69) )
        {
          v32 = width--;
          if ( v32 != 0 )
          {
            pFloatStr[v24] = 101;
            if ( _check_float_string(
                   pnFloatStrSz: &nFloatStrSz,
                   &pFloatStr,
                   nFloatStrUsed: ++v24,
                   floatstring,
                   pmalloc_FloatStrFlag: &malloc_FloatStrFlag) == 0 )
              goto error_return_1;
            ++charcount;
            *(_DWORD *)chr = inc(a1: v33, fileptr);
            if ( *(_DWORD *)chr == 45 )
            {
              pFloatStr[v24] = 45;
              if ( _check_float_string(
                     pnFloatStrSz: &nFloatStrSz,
                     &pFloatStr,
                     nFloatStrUsed: ++v24,
                     floatstring,
                     pmalloc_FloatStrFlag: &malloc_FloatStrFlag) == 0 )
                goto error_return_1;
f_incwidth2_0:
              v35 = width--;
              if ( v35 != 0 )
              {
                ++charcount;
                *(_DWORD *)chr = inc(a1: v34, fileptr);
              }
              else
              {
                width = 0;
              }
            }
            else if ( *(_DWORD *)chr == 43 )
            {
              goto f_incwidth2_0;
            }
            for ( k = (unsigned __int8)chr[0]; isdigit(c: k) != 0; k = (unsigned __int8)chr[0] )
            {
              v37 = width--;
              if ( v37 == 0 )
                break;
              ++started;
              pFloatStr[v24] = chr[0];
              if ( _check_float_string(
                     pnFloatStrSz: &nFloatStrSz,
                     &pFloatStr,
                     nFloatStrUsed: ++v24,
                     floatstring,
                     pmalloc_FloatStrFlag: &malloc_FloatStrFlag) == 0 )
                goto error_return_1;
              ++charcount;
              *(_DWORD *)chr = inc(a1: v38, fileptr);
            }
          }
        }
        --charcount;
        if ( *(_DWORD *)chr != -1 )
          _ungetc_nolock(ch: *(int *)chr, str: fileptr);
        if ( started != 0 )
        {
          if ( suppress == 0 )
          {
            ++count;
            v64 = pFloatStr;
            v63 = pointer;
            pFloatStr[v24] = 0;
            v62 = (char)last - 1;
            v39 = (void (__cdecl *)(int, void *, char *, _LocaleUpdate *))DecodePointer(Ptr: off_1042D240);
            v39(a1: v62, a2: v63, a3: v64, a4: &_loc_update);
          }
          goto LABEL_269;
        }
        goto error_return_1;
      }
LABEL_162:
      if ( *v11 == *(_DWORD *)chr )
      {
        --match;
        if ( suppress == 0 )
          v81 = arglistsave;
        goto LABEL_269;
      }
      if ( *(_DWORD *)chr != -1 )
        _ungetc_nolock(ch: *(int *)chr, str: fileptr);
      format_error = 1;
      goto error_return_1;
    }
LABEL_218:
    v23 = *(_DWORD *)chr;
    if ( *(_DWORD *)chr == 45 )
    {
      negative = 1;
    }
    else if ( *(_DWORD *)chr != 43 )
    {
      goto getnum_0;
    }
    if ( --width != 0 || widthset == 0 )
    {
      ++charcount;
      v23 = inc(a1: widthset, fileptr);
      goto LABEL_225;
    }
    done_flag = 1;
getnum_0:
    if ( integer64 == 0 )
    {
      if ( done_flag == 0 )
      {
        while ( 1 )
        {
          if ( v18 == 120 || v18 == 112 )
          {
            if ( isxdigit(c: (unsigned __int8)v23) == 0 )
            {
LABEL_257:
              --charcount;
              if ( v23 != -1 )
                _ungetc_nolock(ch: v23, str: fileptr);
              break;
            }
            number *= 16;
            v23 = hextodec(chr: v23);
            v55 = number;
            v54 = v74;
            *(_DWORD *)chr = v23;
          }
          else
          {
            v53 = isdigit(c: (unsigned __int8)v23);
            v54 = v73;
            if ( v53 == 0 )
              goto LABEL_257;
            if ( v18 == 111 )
            {
              if ( v23 >= 56 )
                goto LABEL_257;
              v55 = 8 * number;
            }
            else
            {
              v55 = 10 * number;
            }
          }
          ++started;
          number = v55 + v23 - 48;
          if ( widthset != 0 && --width == 0 )
            break;
          ++charcount;
          v23 = inc(a1: v54, fileptr);
          *(_DWORD *)chr = v23;
        }
      }
      if ( negative != 0 )
        number = -number;
      goto LABEL_261;
    }
    if ( done_flag != 0 )
      goto LABEL_242;
    while ( 2 )
    {
      if ( v18 != 120 && v18 != 112 )
      {
        v51 = isdigit(c: (unsigned __int8)v23);
        v52 = v71;
        if ( v51 == 0 )
          break;
        if ( v18 == 111 )
        {
          if ( v23 >= 56 )
            break;
          v52 = num64 >> 29;
          num64 *= 8LL;
        }
        else
        {
          num64 *= 10LL;
        }
        goto LABEL_237;
      }
      if ( isxdigit(c: (unsigned __int8)v23) != 0 )
      {
        num64 *= 16LL;
        v23 = hextodec(chr: v23);
        v52 = v72;
        *(_DWORD *)chr = v23;
LABEL_237:
        ++started;
        num64 += v23 - 48;
        if ( widthset != 0 && --width == 0 )
          goto LABEL_242;
        ++charcount;
        v23 = inc(a1: v52, fileptr);
        *(_DWORD *)chr = v23;
        continue;
      }
      break;
    }
    --charcount;
    if ( v23 != -1 )
      _ungetc_nolock(ch: v23, str: fileptr);
LABEL_242:
    if ( negative != 0 )
      num64 = -(__int64)num64;
LABEL_261:
    if ( started == 0 )
      goto error_return_1;
    if ( suppress == 0 )
    {
      ++count;
      v16 = pointer;
      v22 = number;
      goto assign_num_0;
    }
LABEL_269:
    ++match;
    v10 = ++v93;
LABEL_275:
    if ( *(_DWORD *)chr != -1 )
    {
LABEL_279:
      v8 = *v10;
      if ( *v10 == 0 )
        goto error_return_1;
      continue;
    }
    break;
  }
  if ( *v10 == 37 && v93[1] == 110 )
  {
    v10 = v93;
    goto LABEL_279;
  }
error_return_1:
  if ( malloc_FloatStrFlag == 1 )
    free(pMem: pFloatStr);
  if ( *(_DWORD *)chr == -1 )
  {
    result = count;
    if ( count == 0 && match == 0 )
      result = -1;
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
    return result;
  }
  if ( format_error == 1 )
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
  }
LABEL_307:
  if ( _loc_update.updated )
    _loc_update.ptd->_ownlocale &= ~2u;
  return count;
}

//------------------------------------------------------------------------------
// Address: 0x102FFE49
// Name: _iswctype
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl iswctype(unsigned __int16 c, unsigned __int16 mask)
{
  unsigned __int16 v3; // ax
  int d; // [esp+0h] [ebp-4h] BYREF

  if ( c == 0xFFFF )
    return 0;
  if ( c >= 0x100u )
  {
    if ( !GetStringTypeW(dwInfoType: 1u, lpSrcStr: &c, cchSrc: 1, lpCharType: (LPWORD)&d) )
      d = 0;
    v3 = d;
  }
  else
  {
    v3 = _pwctype[c];
  }
  return mask & v3;
}

//------------------------------------------------------------------------------
// Address: 0x102FFE9E
// Name: __fullpath
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char *__cdecl _fullpath(char *UserBuf, const char *path, DWORD maxlen)
{
  DWORD FullPathNameA; // eax
  DWORD LastError; // eax
  unsigned int v6; // edi
  char *v7; // eax
  char *v8; // ebx
  DWORD v9; // eax
  char *pfname; // [esp+Ch] [ebp-4h] BYREF

  if ( path == nullptr || *path == 0 )
    return _getcwd(pnbuf: UserBuf, maxlen);
  if ( UserBuf != nullptr )
  {
    v6 = maxlen;
    if ( maxlen == 0 )
    {
      *_errno() = 22;
      _invalid_parameter_noinfo();
      return nullptr;
    }
    v8 = UserBuf;
  }
  else
  {
    FullPathNameA = GetFullPathNameA(lpFileName: path, nBufferLength: 0, lpBuffer: nullptr, lpFilePart: nullptr);
    if ( FullPathNameA == 0 )
    {
LABEL_5:
      LastError = GetLastError();
      _dosmaperr(oserrno: LastError);
      return nullptr;
    }
    v6 = maxlen;
    if ( maxlen <= FullPathNameA )
      v6 = FullPathNameA;
    v7 = (char *)calloc(count: v6, size: 1u);
    v8 = v7;
    if ( v7 == nullptr )
    {
      *_errno() = 12;
      return nullptr;
    }
  }
  v9 = GetFullPathNameA(lpFileName: path, nBufferLength: v6, lpBuffer: v8, lpFilePart: &pfname);
  if ( v9 >= v6 )
  {
    if ( UserBuf == nullptr )
      free(pMem: v8);
    *_errno() = 34;
    return nullptr;
  }
  if ( v9 == 0 )
  {
    if ( UserBuf == nullptr )
      free(pMem: v8);
    goto LABEL_5;
  }
  return v8;
}

//------------------------------------------------------------------------------
// Address: 0x102FFF95
// Name: ___dtoxmode
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __cdecl __dtoxmode(char attr, const char *name)
{
  const char *v2; // ecx
  char v3; // dl
  int v4; // edi
  unsigned int v5; // edi
  const unsigned __int8 *v6; // eax
  const unsigned __int8 *v7; // esi

  v2 = name;
  if ( name[1] == 58 )
    v2 = name + 2;
  v3 = *v2;
  if ( (*v2 == 92 || v3 == 47) && v2[1] == 0 || (attr & 0x10) != 0 || (v4 = 0x8000, v3 == 0) )
    v4 = 16448;
  v5 = ~(attr << 7) & 0x80 | 0x100 | v4;
  v6 = _mbsrchr(str: (const unsigned __int8 *)name, c: 0x2Eu);
  v7 = v6;
  if ( v6 != nullptr
    && (_mbsicmp(s1: v6, s2: ".exe") == 0
     || _mbsicmp(s1: v7, s2: ".cmd") == 0
     || _mbsicmp(s1: v7, s2: ".bat") == 0
     || _mbsicmp(s1: v7, s2: ".com") == 0) )
  {
    v5 |= 0x40u;
  }
  return (v5 >> 3) & 0x38 | v5 | (((v5 >> 3) & 0x38 | v5) >> 6) & 7;
}

//------------------------------------------------------------------------------
// Address: 0x10300052
// Name: __fstat64i32
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _fstat64i32(int fildes, _stat64i32 *buf)
{
  int v3; // edi
  DWORD v4; // eax
  DWORD LastError; // eax
  unsigned __int16 v6; // cx
  unsigned int v7; // ecx
  BOOL v8; // eax
  unsigned __int16 st_mode; // ax
  unsigned __int16 v10; // ax
  _FILETIME LocalFileTime; // [esp+14h] [ebp-74h] BYREF
  int fh; // [esp+1Ch] [ebp-6Ch]
  unsigned int TotalBytesAvail; // [esp+20h] [ebp-68h] BYREF
  int v14; // [esp+24h] [ebp-64h]
  _BY_HANDLE_FILE_INFORMATION FileInformation; // [esp+28h] [ebp-60h] BYREF
  _SYSTEMTIME SystemTime; // [esp+5Ch] [ebp-2Ch] BYREF
  CPPEH_RECORD ms_exc; // [esp+70h] [ebp-18h]

  fh = fildes;
  v14 = 0;
  if ( buf == nullptr )
  {
    *__doserrno() = 0;
    *_errno() = 22;
LABEL_3:
    _invalid_parameter_noinfo();
    return -1;
  }
  memset(dst: (unsigned __int8 *)buf, value: 0, count: sizeof(_stat64i32));
  if ( fildes == -2 )
  {
    *__doserrno() = 0;
    *_errno() = 9;
    return -1;
  }
  if ( fildes < 0
    || fildes >= _nhandle
    || (TotalBytesAvail = (unsigned int)&__pioinfo[fildes >> 5],
        v3 = (fildes & 0x1F) << 6,
        (*(_BYTE *)(*(_DWORD *)TotalBytesAvail + v3 + 4) & 1) == 0) )
  {
    *__doserrno() = 0;
    *_errno() = 9;
    goto LABEL_3;
  }
  __lock_fhandle(fh);
  ms_exc.registration.TryLevel = 0;
  if ( (*(_BYTE *)(*(_DWORD *)TotalBytesAvail + v3 + 4) & 1) == 0 )
    goto LABEL_12;
  v4 = GetFileType(hFile: *(HANDLE *)(*(_DWORD *)TotalBytesAvail + ((fildes & 0x1F) << 6))) & 0xFFFF7FFF;
  switch ( v4 )
  {
    case 1u:
      buf->st_mode = 0;
      buf->st_gid = 0;
      buf->st_uid = 0;
      buf->st_ino = 0;
      buf->st_nlink = 1;
      if ( GetFileInformationByHandle(
             hFile: *(HANDLE *)(*(_DWORD *)TotalBytesAvail + ((fildes & 0x1F) << 6)),
             lpFileInformation: &FileInformation) )
      {
        st_mode = buf->st_mode;
        if ( (FileInformation.dwFileAttributes & 1) != 0 )
          v10 = st_mode | 0x124;
        else
          v10 = st_mode | 0x1B6;
        buf->st_mode = v10;
        if ( FileInformation.ftLastWriteTime.dwLowDateTime != 0 || FileInformation.ftLastWriteTime.dwHighDateTime != 0 )
        {
          if ( !FileTimeToLocalFileTime(lpFileTime: &FileInformation.ftLastWriteTime, lpLocalFileTime: &LocalFileTime)
            || !FileTimeToSystemTime(lpFileTime: &LocalFileTime, lpSystemTime: &SystemTime) )
          {
            goto LABEL_13;
          }
          buf->st_mtime = __loctotime64_t(
                            yr: SystemTime.wYear,
                            mo: SystemTime.wMonth,
                            dy: SystemTime.wDay,
                            hr: SystemTime.wHour,
                            mn: SystemTime.wMinute,
                            sc: SystemTime.wSecond,
                            dstflag: -1);
        }
        else
        {
          buf->st_mtime = 0;
        }
        if ( FileInformation.ftLastAccessTime.dwLowDateTime != 0 || FileInformation.ftLastAccessTime.dwHighDateTime != 0 )
        {
          if ( !FileTimeToLocalFileTime(lpFileTime: &FileInformation.ftLastAccessTime, lpLocalFileTime: &LocalFileTime)
            || !FileTimeToSystemTime(lpFileTime: &LocalFileTime, lpSystemTime: &SystemTime) )
          {
            goto LABEL_13;
          }
          buf->st_atime = __loctotime64_t(
                            yr: SystemTime.wYear,
                            mo: SystemTime.wMonth,
                            dy: SystemTime.wDay,
                            hr: SystemTime.wHour,
                            mn: SystemTime.wMinute,
                            sc: SystemTime.wSecond,
                            dstflag: -1);
        }
        else
        {
          buf->st_atime = buf->st_mtime;
        }
        if ( FileInformation.ftCreationTime.dwLowDateTime != 0 || FileInformation.ftCreationTime.dwHighDateTime != 0 )
        {
          if ( !FileTimeToLocalFileTime(lpFileTime: &FileInformation.ftCreationTime, lpLocalFileTime: &LocalFileTime)
            || !FileTimeToSystemTime(lpFileTime: &LocalFileTime, lpSystemTime: &SystemTime) )
          {
            goto LABEL_13;
          }
          buf->st_ctime = __loctotime64_t(
                            yr: SystemTime.wYear,
                            mo: SystemTime.wMonth,
                            dy: SystemTime.wDay,
                            hr: SystemTime.wHour,
                            mn: SystemTime.wMinute,
                            sc: SystemTime.wSecond,
                            dstflag: -1);
        }
        else
        {
          buf->st_ctime = buf->st_mtime;
        }
        buf->st_size = FileInformation.nFileSizeLow;
        buf->st_mode |= 0x8000u;
        buf->st_dev = 0;
        buf->st_rdev = 0;
        goto done;
      }
      goto LABEL_19;
    case 2u:
      v6 = 0x2000;
LABEL_22:
      buf->st_mode = v6;
      v7 = fh;
      buf->st_dev = fh;
      buf->st_rdev = v7;
      buf->st_nlink = 1;
      buf->st_ino = 0;
      buf->st_gid = 0;
      buf->st_uid = 0;
      buf->st_ctime = 0;
      buf->st_mtime = 0;
      buf->st_atime = 0;
      if ( v4 == 2 )
      {
        buf->st_size = 0;
      }
      else
      {
        v8 = PeekNamedPipe(
               hNamedPipe: *(HANDLE *)(*(_DWORD *)TotalBytesAvail + ((fildes & 0x1F) << 6)),
               lpBuffer: nullptr,
               nBufferSize: 0,
               lpBytesRead: nullptr,
               lpTotalBytesAvail: &TotalBytesAvail,
               lpBytesLeftThisMessage: nullptr);
        buf->st_size = v8 ? TotalBytesAvail : 0;
      }
      goto done;
    case 3u:
      v6 = 4096;
      goto LABEL_22;
    default:
      break;
  }
  if ( v4 != 0 )
  {
LABEL_19:
    LastError = GetLastError();
    _dosmaperr(oserrno: LastError);
    goto LABEL_13;
  }
LABEL_12:
  *_errno() = 9;
LABEL_13:
  v14 = -1;
done:
  ms_exc.registration.TryLevel = -2;
  _unlock_fhandle(fh);
  return v14;
}

//------------------------------------------------------------------------------
// Address: 0x103003A4
// Name: _tsopen_nolock
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall tsopen_nolock@<eax>(
        int *pfh@<eax>,
        int *punlock_flag,
        const char *path,
        int oflag,
        int shflag,
        char pmode)
{
  unsigned int v7; // eax
  int v9; // eax
  char *v10; // eax
  DWORD v11; // eax
  DWORD FileType; // eax
  char *p_osfile; // eax
  DWORD LastError; // esi
  char v15; // cl
  _BYTE *v16; // eax
  signed int v17; // edi
  int v18; // eax
  unsigned int v19; // eax
  unsigned int v20; // eax
  int v21; // edi
  __int64 v22; // rax
  int nolock; // eax
  __int64 v24; // rax
  DWORD v25; // eax
  int v26; // ebx
  int v27; // eax
  _BYTE *v28; // eax
  _BYTE *v29; // eax
  bool v30; // zf
  char *v31; // eax
  HANDLE v32; // eax
  DWORD v33; // eax
  char *v34; // eax
  int v35; // [esp-10h] [ebp-48h]
  DWORD v36; // [esp-Ch] [ebp-44h]
  int v37; // [esp-8h] [ebp-40h]
  _SECURITY_ATTRIBUTES SecurityAttributes; // [esp+8h] [ebp-30h] BYREF
  int fmode; // [esp+14h] [ebp-24h] BYREF
  void *osfh; // [esp+18h] [ebp-20h]
  int bom; // [esp+1Ch] [ebp-1Ch] BYREF
  unsigned int filecreate; // [esp+20h] [ebp-18h]
  unsigned int fileshare; // [esp+24h] [ebp-14h]
  unsigned int fileattrib; // [esp+28h] [ebp-10h]
  unsigned int fileaccess; // [esp+2Ch] [ebp-Ch]
  int retvalue; // [esp+30h] [ebp-8h]
  char inputbuf; // [esp+34h] [ebp-4h] BYREF
  char v48; // [esp+35h] [ebp-3h]
  char tmode; // [esp+36h] [ebp-2h]
  char fileflags; // [esp+37h] [ebp-1h]

  fmode = 0;
  tmode = 0;
  retvalue = 0;
  SecurityAttributes.nLength = 12;
  SecurityAttributes.lpSecurityDescriptor = nullptr;
  if ( (oflag & 0x80u) == 0 )
  {
    SecurityAttributes.bInheritHandle = 1;
    fileflags = 0;
  }
  else
  {
    SecurityAttributes.bInheritHandle = 0;
    fileflags = 16;
  }
  if ( _get_fmode(pMode: &fmode) != 0 )
    _invoke_watson();
  if ( (oflag & 0x8000) == 0 && ((oflag & 0x74000) != 0 || fmode != 0x8000) )
    fileflags |= 0x80u;
  if ( (oflag & 3) != 0 )
  {
    if ( (oflag & 3) != 1 )
    {
      if ( (oflag & 3) != 2 )
        goto LABEL_40;
      goto LABEL_13;
    }
    if ( (oflag & 8) != 0 && (oflag & 0x70000) != 0 )
    {
LABEL_13:
      fileaccess = -1073741824;
      goto LABEL_18;
    }
    fileaccess = 0x40000000;
  }
  else
  {
    fileaccess = 0x80000000;
  }
LABEL_18:
  switch ( shflag )
  {
    case 16:
      fileshare = 0;
      break;
    case 32:
      fileshare = 1;
      break;
    case 48:
      fileshare = 2;
      break;
    case 64:
      fileshare = 3;
      break;
    case 128:
      fileshare = fileaccess == 0x80000000;
      break;
    default:
      goto LABEL_40;
  }
  v7 = oflag & 0x700;
  if ( v7 > 0x400 )
  {
    if ( v7 != 1280 )
    {
      if ( v7 == 1536 )
        goto LABEL_41;
      if ( v7 != 1792 )
        goto LABEL_40;
    }
    filecreate = 1;
    goto LABEL_43;
  }
  if ( (oflag & 0x700) == 0x400 || (oflag & 0x700) == 0 )
  {
    filecreate = 3;
    goto LABEL_43;
  }
  if ( v7 == 256 )
  {
    filecreate = 4;
    goto LABEL_43;
  }
  if ( v7 == 512 )
  {
LABEL_41:
    filecreate = 5;
    goto LABEL_43;
  }
  if ( v7 != 768 )
  {
LABEL_40:
    *__doserrno() = 0;
    *pfh = -1;
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return 22;
  }
  filecreate = 2;
LABEL_43:
  fileattrib = 128;
  if ( (oflag & 0x100) != 0 && (pmode & ~(_BYTE)_umaskval & 0x80u) == 0 )
    fileattrib = 1;
  if ( (oflag & 0x40) != 0 )
  {
    fileattrib |= 0x4000000u;
    fileaccess |= 0x10000u;
    fileshare |= 4u;
  }
  if ( (oflag & 0x1000) != 0 )
    fileattrib |= 0x100u;
  if ( (oflag & 0x20) != 0 )
  {
    fileattrib |= 0x8000000u;
  }
  else if ( (oflag & 0x10) != 0 )
  {
    fileattrib |= 0x10000000u;
  }
  v9 = _alloc_osfhnd();
  *pfh = v9;
  if ( v9 == -1 )
  {
    *__doserrno() = 0;
    *pfh = -1;
    *_errno() = 24;
    return *_errno();
  }
  v36 = fileattrib;
  *punlock_flag = 1;
  osfh = CreateFileA(
           lpFileName: path,
           dwDesiredAccess: fileaccess,
           dwShareMode: fileshare,
           lpSecurityAttributes: &SecurityAttributes,
           dwCreationDisposition: filecreate,
           dwFlagsAndAttributes: v36,
           hTemplateFile: nullptr);
  if ( osfh != (void *)-1
    || (fileaccess & 0xC0000000) == 0xC0000000
    && (oflag & 1) != 0
    && (fileaccess &= ~0x80000000,
        (osfh = CreateFileA(
                  lpFileName: path,
                  dwDesiredAccess: fileaccess,
                  dwShareMode: fileshare,
                  lpSecurityAttributes: &SecurityAttributes,
                  dwCreationDisposition: filecreate,
                  dwFlagsAndAttributes: fileattrib,
                  hTemplateFile: nullptr)) != (void *)-1) )
  {
    FileType = GetFileType(hFile: osfh);
    switch ( FileType )
    {
      case 0u:
        p_osfile = &__pioinfo[*pfh >> 5][*pfh & 0x1F].osfile;
        *p_osfile &= ~1u;
        LastError = GetLastError();
        _dosmaperr(oserrno: LastError);
        CloseHandle(hObject: osfh);
        if ( LastError == 0 )
          *_errno() = 13;
        return *_errno();
      case 2u:
        fileflags |= 0x40u;
        break;
      case 3u:
        fileflags |= 8u;
        break;
      default:
        break;
    }
    _set_osfhnd(fh: *pfh, value: (int)osfh);
    v15 = fileflags | 1;
    __pioinfo[*pfh >> 5][*pfh & 0x1F].osfile = fileflags | 1;
    v16 = (char *)&__pioinfo[*pfh >> 5][*pfh & 0x1F] + 36;
    *v16 &= 0x80u;
    v48 = v15 & 0x48;
    fileflags = v15;
    if ( (v15 & 0x48) == 0 )
    {
      if ( v15 >= 0 )
        goto LABEL_131;
      if ( (oflag & 2) != 0 )
      {
        v17 = _lseek_nolock(fh: *pfh, pos: -1, mthd: 2u);
        if ( v17 == -1 )
        {
          if ( *__doserrno() != 131 )
          {
LABEL_74:
            _close_nolock(fh: *pfh);
            return *_errno();
          }
        }
        else
        {
          v35 = *pfh;
          inputbuf = 0;
          if ( _read_nolock(fh: v35, &inputbuf, cnt: 1u) == 0
            && inputbuf == 26
            && _chsize_nolock(filedes: *pfh, size: v17) == -1
            || _lseek_nolock(fh: *pfh, pos: 0, mthd: 0) == -1 )
          {
            goto LABEL_74;
          }
        }
      }
    }
    if ( fileflags >= 0 )
    {
LABEL_131:
      v28 = (char *)&__pioinfo[*pfh >> 5][*pfh & 0x1F] + 36;
      *v28 ^= (tmode ^ *v28) & 0x7F;
      v29 = (char *)&__pioinfo[*pfh >> 5][*pfh & 0x1F] + 36;
      v30 = v48 == 0;
      *v29 = *v29 & 0x7F | (BYTE2(oflag) << 7);
      if ( v30 && (oflag & 8) != 0 )
      {
        v31 = &__pioinfo[*pfh >> 5][*pfh & 0x1F].osfile;
        *v31 |= 0x20u;
      }
      if ( (fileaccess & 0xC0000000) != 0xC0000000 || (oflag & 1) == 0 )
        return retvalue;
      CloseHandle(hObject: osfh);
      v32 = CreateFileA(
              lpFileName: path,
              dwDesiredAccess: fileaccess & 0x7FFFFFFF,
              dwShareMode: fileshare,
              lpSecurityAttributes: &SecurityAttributes,
              dwCreationDisposition: 3u,
              dwFlagsAndAttributes: fileattrib,
              hTemplateFile: nullptr);
      if ( v32 != (HANDLE)-1 )
      {
        __pioinfo[*pfh >> 5][*pfh & 0x1F].osfhnd = (int)v32;
        return retvalue;
      }
      v33 = GetLastError();
      _dosmaperr(oserrno: v33);
      v34 = &__pioinfo[*pfh >> 5][*pfh & 0x1F].osfile;
      *v34 &= ~1u;
      _free_osfhnd(fh: *pfh);
      return *_errno();
    }
    if ( (oflag & 0x74000) == 0 )
    {
      if ( (fmode & 0x74000) != 0 )
        oflag |= fmode & 0x74000;
      else
        oflag |= 0x4000u;
    }
    v18 = oflag & 0x74000;
    if ( (oflag & 0x74000) == 0x4000 )
    {
      tmode = 0;
      goto LABEL_95;
    }
    if ( v18 == 0x10000 || v18 == 81920 )
    {
      if ( (oflag & 0x301) != 0x301 )
        goto LABEL_95;
    }
    else if ( v18 != 0x20000 && v18 != 147456 )
    {
      if ( v18 == 0x40000 || v18 == 278528 )
        tmode = 1;
LABEL_95:
      if ( (oflag & 0x70000) == 0 )
        goto LABEL_131;
      bom = 0;
      if ( (fileflags & 0x40) != 0 )
        goto LABEL_131;
      v19 = fileaccess & 0xC0000000;
      if ( (fileaccess & 0xC0000000) == 0x40000000 )
      {
        v20 = filecreate;
        if ( filecreate == 0 )
          goto LABEL_131;
        if ( filecreate <= 2 )
          goto LABEL_104;
        if ( filecreate > 4 )
          goto LABEL_103;
        if ( _lseeki64_nolock(fh: *pfh, pos: 0, mthd: 2) != 0 )
        {
          v24 = _lseeki64_nolock(fh: *pfh, pos: 0, mthd: 0);
          v25 = HIDWORD(v24) & v24;
          goto LABEL_119;
        }
      }
      else
      {
        if ( v19 == 0x80000000 )
          goto LABEL_109;
        if ( v19 != -1073741824 )
          goto LABEL_131;
        v20 = filecreate;
        if ( filecreate == 0 )
          goto LABEL_131;
        if ( filecreate > 2 )
        {
          if ( filecreate > 4 )
          {
LABEL_103:
            if ( v20 != 5 )
              goto LABEL_131;
            goto LABEL_104;
          }
          if ( _lseeki64_nolock(fh: *pfh, pos: 0, mthd: 2) != 0 )
          {
            v22 = _lseeki64_nolock(fh: *pfh, pos: 0, mthd: 0);
            if ( (HIDWORD(v22) & (unsigned int)v22) == 0xFFFFFFFF )
              goto LABEL_74;
LABEL_109:
            nolock = _read_nolock(fh: *pfh, inputbuf: (char *)&bom, cnt: 3u);
            if ( nolock == -1 )
              goto LABEL_74;
            if ( nolock != 2 )
            {
              if ( nolock != 3 )
              {
LABEL_126:
                v25 = _lseek_nolock(fh: *pfh, pos: 0, mthd: 0);
LABEL_119:
                if ( v25 == -1 )
                  goto LABEL_74;
                goto LABEL_131;
              }
              if ( bom == 12565487 )
              {
                tmode = 1;
                goto LABEL_131;
              }
            }
            if ( (unsigned __int16)bom == 65534 )
            {
              _close_nolock(fh: *pfh);
              *_errno() = 22;
              return 22;
            }
            if ( (unsigned __int16)bom == 65279 )
            {
              if ( _lseek_nolock(fh: *pfh, pos: 2, mthd: 0) == -1 )
                goto LABEL_74;
              tmode = 2;
              goto LABEL_131;
            }
            goto LABEL_126;
          }
        }
      }
LABEL_104:
      v21 = 0;
      if ( tmode == 1 )
      {
        bom = 12565487;
        v37 = 3;
LABEL_128:
        v26 = v37;
        while ( 1 )
        {
          v27 = _write(fh: *pfh, buf: (char *)&bom + v21, cnt: v26 - v21);
          if ( v27 == -1 )
            goto LABEL_74;
          v21 += v27;
          if ( v26 <= v21 )
            goto LABEL_131;
        }
      }
      if ( tmode == 2 )
      {
        bom = 65279;
        v37 = 2;
        goto LABEL_128;
      }
      goto LABEL_131;
    }
    tmode = 2;
    goto LABEL_95;
  }
  v10 = &__pioinfo[*pfh >> 5][*pfh & 0x1F].osfile;
  *v10 &= ~1u;
  v11 = GetLastError();
  _dosmaperr(oserrno: v11);
  return *_errno();
}

//------------------------------------------------------------------------------
// Address: 0x10300AD8
// Name: __sopen_helper
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _sopen_helper(const char *path, int oflag, int shflag, int pmode, int *pfh, int bSecure)
{
  int result; // eax
  char *p_osfile; // eax
  int retval; // [esp+14h] [ebp-20h]
  int unlock_flag; // [esp+18h] [ebp-1Ch] BYREF
  CPPEH_RECORD ms_exc; // [esp+1Ch] [ebp-18h]

  unlock_flag = 0;
  if ( pfh == nullptr || (*pfh = -1, path == nullptr) || bSecure != 0 && (pmode & 0xFFFFFE7F) != 0 )
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return 22;
  }
  else
  {
    ms_exc.registration.TryLevel = 0;
    retval = tsopen_nolock(pfh, punlock_flag: &unlock_flag, path, oflag, shflag, pmode);
    ms_exc.registration.TryLevel = -2;
    if ( unlock_flag != 0 )
    {
      if ( retval != 0 )
      {
        p_osfile = &__pioinfo[*pfh >> 5][*pfh & 0x1F].osfile;
        *p_osfile &= ~1u;
      }
      _unlock_fhandle(fh: *pfh);
    }
    result = retval;
    if ( retval != 0 )
      *pfh = -1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10300B9C
// Name: __sopen_s
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _sopen_s(int *pfh, const char *path, int oflag, int shflag, int pmode)
{
  return _sopen_helper(path, oflag, shflag, pmode, pfh, bSecure: 1);
}

//------------------------------------------------------------------------------
// Address: 0x10300BBC
// Name: ___loctotime64_t
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl __loctotime64_t(int yr, int mo, int dy, unsigned int hr, unsigned int mn, unsigned int sc, int dstflag)
{
  int v7; // ebx
  int v8; // esi
  int *v9; // eax
  int v10; // ecx
  unsigned int v11; // edi
  int timezone; // [esp+Ch] [ebp-40h] BYREF
  int dstbias; // [esp+10h] [ebp-3Ch] BYREF
  int v15; // [esp+14h] [ebp-38h]
  int daylight; // [esp+18h] [ebp-34h] BYREF
  int v17; // [esp+1Ch] [ebp-30h]
  int tmpdays; // [esp+20h] [ebp-2Ch]
  tm tb; // [esp+24h] [ebp-28h] BYREF

  v7 = mo;
  v8 = yr - 1900;
  v15 = mo;
  daylight = 0;
  dstbias = 0;
  timezone = 0;
  if ( yr - 1900 < 70
    || v8 > 1100
    || (unsigned int)(mo - 1) > 0xB
    || hr > 0x17
    || mn > 0x3B
    || sc > 0x3B
    || dy < 1
    || (v9 = &_days[mo], v10 = *(v9 - 1), *v9 - v10 < dy)
    && ((v8 % 4 != 0 || v8 % 100 == 0) && yr % 400 != 0 || (v7 = v15, v15 != 2) || dy > 29) )
  {
    *_errno() = 22;
    return -1;
  }
  else
  {
    tmpdays = dy + v10;
    if ( (v8 % 4 == 0 && v8 % 100 != 0 || yr % 400 == 0) && v7 > 2 )
      ++tmpdays;
    __tzset();
    if ( _get_daylight(_Daylight: &daylight) != 0
      || _get_dstbias(_Daylight_savings_bias: &dstbias) != 0
      || _get_timezone(_Timezone: &timezone) != 0 )
    {
      _invoke_watson();
    }
    v17 = (unsigned __int64)(365 * (v8 - 70LL) + (yr - 1900 + 299) / 400 - (yr - 1901) / 100 + (yr - 1901) / 4 - 17) >> 32;
    tb.tm_yday = tmpdays;
    v11 = sc
        + timezone
        + 60
        * (mn
         + 60
         * (hr + 24 * (tmpdays + 365 * (yr - 1970) + (yr - 1900 + 299) / 400 - (yr - 1901) / 100 + (yr - 1901) / 4 - 17)));
    tb.tm_year = yr - 1900;
    tb.tm_mon = v15 - 1;
    tb.tm_hour = hr;
    tb.tm_min = mn;
    tb.tm_sec = sc;
    if ( dstflag == 1 || dstflag == -1 && daylight != 0 && _isindst(&tb) != 0 )
      v11 += dstbias;
    return v11;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10300E23
// Name: __getdrive
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __cdecl _getdrive()
{
  wchar_t *v0; // ebx
  signed int CurrentDirectoryW; // esi
  wchar_t *v2; // eax
  unsigned int v3; // edi
  unsigned int v4; // eax
  int memfree; // [esp+10h] [ebp-214h]
  wchar_t curdirstr[262]; // [esp+14h] [ebp-210h] BYREF

  memfree = 0;
  v0 = curdirstr;
  CurrentDirectoryW = GetCurrentDirectoryW(nBufferLength: 0x105u, lpBuffer: curdirstr);
  if ( CurrentDirectoryW > 260 )
  {
    v2 = (wchar_t *)calloc(count: CurrentDirectoryW + 1, size: 2u);
    v0 = v2;
    if ( v2 != nullptr )
    {
      memfree = 1;
      CurrentDirectoryW = GetCurrentDirectoryW(nBufferLength: CurrentDirectoryW + 1, lpBuffer: v2);
    }
    else
    {
      *_errno() = 12;
      CurrentDirectoryW = 0;
    }
  }
  v3 = 0;
  if ( CurrentDirectoryW != 0 )
  {
    if ( v0[1] == 58 )
    {
      v4 = *v0;
      if ( v4 >= 0x61 && v4 <= 0x7A )
        v4 -= 32;
      v3 = v4 - 64;
    }
  }
  else
  {
    *_errno() = 12;
  }
  if ( memfree != 0 )
    free(pMem: v0);
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x10300EF1
// Name: __mbctolower_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _mbctolower_l(unsigned int c, localeinfo_struct *plocinfo)
{
  int result; // eax
  _LocaleUpdate _loc_update; // [esp+4h] [ebp-18h] BYREF
  unsigned __int8 ret[4]; // [esp+14h] [ebp-8h] BYREF
  char val[4]; // [esp+18h] [ebp-4h] BYREF

  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  if ( c <= 0xFF )
  {
    if ( (_loc_update.localeinfo.mbcinfo->mbctype[c + 1] & 0x10) != 0 )
      result = _loc_update.localeinfo.mbcinfo->mbcasemap[c];
    else
      result = c;
LABEL_11:
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
    return result;
  }
  val[0] = BYTE1(c);
  val[1] = c;
  if ( (_loc_update.localeinfo.mbcinfo->mbctype[BYTE1(c) + 1] & 4) != 0
    && __crtLCMapStringA(
         plocinfo: &_loc_update.localeinfo,
         Locale: _loc_update.localeinfo.mbcinfo->mblcid,
         dwMapFlags: 0x100u,
         lpSrcStr: val,
         cchSrc: 2,
         lpDestStr: (char *)ret,
         cchDest: 2,
         code_page: _loc_update.localeinfo.mbcinfo->mbcodepage,
         bError: 1) != 0 )
  {
    result = ret[1] + (ret[0] << 8);
    goto LABEL_11;
  }
  if ( _loc_update.updated )
    _loc_update.ptd->_ownlocale &= ~2u;
  return c;
}

//------------------------------------------------------------------------------
// Address: 0x10300F97
// Name: __mbctolower
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _mbctolower(unsigned int c)
{
  return _mbctolower_l(c, plocinfo: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x10300FAA
// Name: __mbspbrk_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _mbspbrk_l(unsigned __int8 *string, unsigned __int8 *charset, localeinfo_struct *plocinfo)
{
  unsigned __int8 *v3; // ecx
  unsigned __int8 *i; // eax
  unsigned __int8 v5; // dl
  _LocaleUpdate _loc_update; // [esp+8h] [ebp-10h] BYREF

  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  if ( _loc_update.localeinfo.mbcinfo->ismbcodepage == 0 )
  {
    strpbrk(string, control: charset);
LABEL_22:
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
    return;
  }
  v3 = string;
  if ( string != nullptr && charset != nullptr )
  {
    if ( *string != 0 )
    {
      do
      {
        for ( i = charset; *i != 0; ++i )
        {
          v5 = *i;
          if ( (_loc_update.localeinfo.mbcinfo->mbctype[*i + 1] & 4) != 0 )
          {
            if ( v5 == *v3 && i[1] == v3[1] || i[1] == 0 )
              break;
            ++i;
          }
          else if ( v5 == *v3 )
          {
            break;
          }
        }
        if ( *i != 0 )
          break;
        if ( (_loc_update.localeinfo.mbcinfo->mbctype[*v3 + 1] & 4) != 0 && *++v3 == 0 )
          break;
        ++v3;
      }
      while ( *v3 != 0 );
    }
    goto LABEL_22;
  }
  *_errno() = 22;
  _invalid_parameter_noinfo();
  if ( _loc_update.updated )
    _loc_update.ptd->_ownlocale &= ~2u;
}

//------------------------------------------------------------------------------
// Address: 0x1030106F
// Name: __mbspbrk
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _mbspbrk(unsigned __int8 *string, unsigned __int8 *charset)
{
  _mbspbrk_l(string, charset, plocinfo: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x10301086
// Name: _strcpy_s
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl strcpy_s(char *_Dst, unsigned int _SizeInBytes, const char *_Src)
{
  unsigned int v3; // edi
  int v4; // esi
  const char *v6; // eax
  char v7; // cl

  if ( _Dst == nullptr )
    goto LABEL_3;
  v3 = _SizeInBytes;
  if ( _SizeInBytes == 0 )
    goto LABEL_3;
  v6 = _Src;
  if ( _Src == nullptr )
  {
    *_Dst = 0;
LABEL_3:
    v4 = 22;
    *_errno() = 22;
LABEL_4:
    _invalid_parameter_noinfo();
    return v4;
  }
  do
  {
    v7 = *v6;
    v6[_Dst - _Src] = *v6;
    ++v6;
    if ( v7 == 0 )
      break;
    --v3;
  }
  while ( v3 != 0 );
  if ( v3 == 0 )
  {
    *_Dst = 0;
    *_errno() = 34;
    v4 = 34;
    goto LABEL_4;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1030111B
// Name: __EH_epilog3
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void _EH_epilog3()
{
  __asm { retn }
}

//------------------------------------------------------------------------------
// Address: 0x1030112F
// Name: _wcslen
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl wcslen(const wchar_t *wcs)
{
  const wchar_t *v1; // eax
  __int16 v2; // cx

  v1 = wcs;
  do
    v2 = *v1++;
  while ( v2 != 0 );
  return v1 - wcs - 1;
}

//------------------------------------------------------------------------------
// Address: 0x1030114A
// Name: findenv
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall findenv@<eax>(unsigned int len@<edi>, const char *name)
{
  const unsigned __int8 **i; // esi
  unsigned __int8 v3; // al

  for ( i = (const unsigned __int8 **)_environ; ; ++i )
  {
    if ( *i == nullptr )
      return -(((char *)i - (char *)_environ) >> 2);
    if ( _mbsnbicoll(s1: (const unsigned __int8 *)name, s2: *i, n: len) == 0 )
    {
      v3 = (*i)[len];
      if ( v3 == 61 || v3 == 0 )
        break;
    }
  }
  return ((char *)i - (char *)_environ) >> 2;
}

//------------------------------------------------------------------------------
// Address: 0x1030119C
// Name: copy_environ
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char **__usercall copy_environ@<eax>(const char **oldenviron@<eax>)
{
  char **result; // eax
  const char **v3; // ecx
  char **v4; // esi
  const char *v5; // eax
  char *v6; // edi
  char **newenviron; // [esp+4h] [ebp-4h]

  result = nullptr;
  v3 = oldenviron;
  if ( oldenviron != nullptr )
  {
    if ( *oldenviron != nullptr )
    {
      do
      {
        ++v3;
        result = (char **)((char *)result + 1);
      }
      while ( *v3 != nullptr );
    }
    v4 = (char **)calloc(count: (unsigned int)result + 1, size: 4u);
    newenviron = v4;
    if ( v4 == nullptr )
      _amsg_exit(rterrnum: 9);
    v5 = *oldenviron;
    if ( *oldenviron != nullptr )
    {
      v6 = (char *)((char *)oldenviron - (char *)v4);
      do
      {
        *v4++ = _strdup(string: v5);
        v5 = *(char **)((char *)v4 + (_DWORD)v6);
      }
      while ( v5 != nullptr );
    }
    *v4 = nullptr;
    return newenviron;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103011FC
// Name: ___crtsetenv
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl __crtsetenv(char **poption, int primary)
{
  const unsigned __int8 *v3; // esi
  const unsigned __int8 *v4; // eax
  const unsigned __int8 *v5; // edi
  char **v6; // eax
  char **v7; // eax
  unsigned __int16 **v8; // eax
  char **v9; // esi
  int v10; // eax
  unsigned int v11; // edi
  char **v12; // esi
  char **v13; // eax
  char **v14; // ecx
  int v15; // eax
  char *v16; // edi
  int v17; // eax
  const char *v18; // eax
  const char *equal; // [esp+4h] [ebp-14h]
  char **env; // [esp+8h] [ebp-10h]
  int retval; // [esp+Ch] [ebp-Ch]
  BOOL remove; // [esp+10h] [ebp-8h]
  char *option; // [esp+14h] [ebp-4h]

  retval = 0;
  if ( poption == nullptr )
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return -1;
  }
  v3 = (const unsigned __int8 *)*poption;
  option = *poption;
  if ( *poption == nullptr )
    goto LABEL_12;
  v4 = _mbschr(string: v3, c: 0x3Du);
  v5 = v4;
  equal = (const char *)v4;
  if ( v4 == nullptr || v3 == v4 )
    goto LABEL_12;
  remove = v4[1] == 0;
  v6 = _environ;
  if ( _environ == __initenv )
  {
    v6 = copy_environ(oldenviron: (const char **)_environ);
    _environ = v6;
  }
  if ( v6 == nullptr )
  {
    if ( primary != 0 && _wenviron != nullptr )
    {
      if ( __wtomb_environ() != 0 )
      {
LABEL_12:
        *_errno() = 22;
        return -1;
      }
    }
    else
    {
      if ( remove )
        return 0;
      v7 = (char **)MemAlloc_Alloc(nSize: 4u);
      _environ = v7;
      if ( v7 == nullptr )
        return -1;
      *v7 = nullptr;
      if ( _wenviron == nullptr )
      {
        v8 = (unsigned __int16 **)MemAlloc_Alloc(nSize: 4u);
        _wenviron = v8;
        if ( v8 == nullptr )
          return -1;
        *v8 = nullptr;
      }
    }
  }
  v9 = _environ;
  env = _environ;
  if ( _environ == nullptr )
    return -1;
  v10 = findenv(len: v5 - (const unsigned __int8 *)option, name: option);
  v11 = v10;
  if ( v10 < 0 || *v9 == nullptr )
  {
    if ( !remove )
    {
      if ( v10 < 0 )
        v11 = -v10;
      if ( (int)(v11 + 2) <= (int)v11 )
        return -1;
      if ( v11 + 2 >= 0x3FFFFFFF )
        return -1;
      v13 = (char **)_recalloc_crt(ptr: _environ, count: 4u, size: v11 + 2);
      if ( v13 == nullptr )
        return -1;
      v14 = &v13[v11];
      *v14 = option;
      v14[1] = nullptr;
      *poption = nullptr;
      goto LABEL_37;
    }
    free(pMem: option);
    *poption = nullptr;
    return 0;
  }
  v12 = &v9[v10];
  free(pMem: *v12);
  if ( !remove )
  {
    *v12 = option;
    *poption = nullptr;
    goto LABEL_38;
  }
  while ( *v12 != nullptr )
  {
    *v12 = v12[1];
    v12 = &env[++v11];
  }
  if ( v11 < 0x3FFFFFFF )
  {
    v13 = (char **)_recalloc_crt(ptr: _environ, count: v11, size: 4u);
    if ( v13 == nullptr )
      goto LABEL_38;
LABEL_37:
    _environ = v13;
  }
LABEL_38:
  if ( primary != 0 )
  {
    strlen(buf: option);
    v16 = (char *)calloc(count: v15 + 2, size: 1u);
    if ( v16 != nullptr )
    {
      strlen(buf: option);
      if ( strcpy_s(_Dst: v16, _SizeInBytes: v17 + 2, _Src: option) != 0 )
        _invoke_watson();
      v18 = &equal[v16 - option];
      *v18 = 0;
      if ( !SetEnvironmentVariableA(lpName: v16, lpValue: !remove ? v18 + 1 : nullptr) )
      {
        retval = -1;
        *_errno() = 42;
      }
      free(pMem: v16);
    }
  }
  if ( remove )
  {
    free(pMem: option);
    *poption = nullptr;
  }
  return retval;
}

//------------------------------------------------------------------------------
// Address: 0x1030143E
// Name: _strnlen
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __cdecl strnlen(const char *str, unsigned int maxsize)
{
  unsigned int result; // eax

  for ( result = 0; result < maxsize; ++str )
  {
    if ( *str == 0 )
      break;
    ++result;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1030145B
// Name: __mbschr_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _mbschr_l(unsigned __int8 *string, unsigned int c, localeinfo_struct *plocinfo)
{
  unsigned __int8 *v3; // eax
  unsigned __int16 v4; // cx
  _LocaleUpdate _loc_update; // [esp+4h] [ebp-10h] BYREF

  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  v3 = string;
  if ( string != nullptr )
  {
    if ( _loc_update.localeinfo.mbcinfo->ismbcodepage != 0 )
    {
      while ( 1 )
      {
        v4 = *v3;
        if ( *v3 == 0 )
          break;
        if ( (_loc_update.localeinfo.mbcinfo->mbctype[(unsigned __int8)v4 + 1] & 4) != 0 )
        {
          if ( *++v3 == 0 )
            goto LABEL_17;
          if ( c == (*v3 | (v4 << 8)) )
            goto LABEL_15;
        }
        else if ( c == *v3 )
        {
          break;
        }
        ++v3;
      }
      if ( c == *v3 )
        goto LABEL_15;
LABEL_17:
      if ( _loc_update.updated )
        _loc_update.ptd->_ownlocale &= ~2u;
    }
    else
    {
      strchr(string, chr: c);
LABEL_15:
      if ( _loc_update.updated )
        _loc_update.ptd->_ownlocale &= ~2u;
    }
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1030150B
// Name: __mbschr
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _mbschr(unsigned __int8 *string, unsigned int c)
{
  _mbschr_l(string, c, plocinfo: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x10301522
// Name: __mtinitlocks
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _mtinitlocks()
{
  int v0; // esi
  _RTL_CRITICAL_SECTION *v1; // edi
  LPCRITICAL_SECTION *v2; // eax

  v0 = 0;
  v1 = lclcritsects;
  while ( 1 )
  {
    if ( *(&locktable + 2 * v0 + 1) == (LPCRITICAL_SECTION)1 )
    {
      v2 = &locktable + 2 * v0;
      *v2 = v1++;
      if ( !InitializeCriticalSectionAndSpinCount(lpCriticalSection: *v2, dwSpinCount: 0xFA0u) )
        break;
    }
    if ( ++v0 >= 36 )
      return 1;
  }
  *(&locktable + 2 * v0) = nullptr;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1030156C
// Name: __mtdeletelocks
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void _mtdeletelocks()
{
  LPCRITICAL_SECTION *v0; // esi
  LPCRITICAL_SECTION v1; // edi
  LPCRITICAL_SECTION *v2; // esi

  v0 = &locktable;
  do
  {
    v1 = *v0;
    if ( *v0 != nullptr && v0[1] != (LPCRITICAL_SECTION)1 )
    {
      DeleteCriticalSection(lpCriticalSection: *v0);
      free(pMem: v1);
      *v0 = nullptr;
    }
    v0 += 2;
  }
  while ( (int)v0 < (int)ext_strings );
  v2 = &locktable;
  do
  {
    if ( *v2 != nullptr && v2[1] == (LPCRITICAL_SECTION)1 )
      DeleteCriticalSection(lpCriticalSection: *v2);
    v2 += 2;
  }
  while ( (int)v2 < (int)ext_strings );
}

//------------------------------------------------------------------------------
// Address: 0x103015C3
// Name: __unlock
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _unlock(int locknum)
{
  LeaveCriticalSection(lpCriticalSection: *(&locktable + 2 * locknum));
}

//------------------------------------------------------------------------------
// Address: 0x103015DA
// Name: __mtinitlocknum
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _mtinitlocknum(int locknum)
{
  LPCRITICAL_SECTION *v1; // esi
  _RTL_CRITICAL_SECTION *v3; // edi
  int retval; // [esp+10h] [ebp-1Ch]

  retval = 1;
  if ( _crtheap == nullptr )
  {
    _FF_MSGBANNER();
    _NMSG_WRITE(rterrnum: 30);
    __crtExitProcess(status: 255);
  }
  v1 = &locktable + 2 * locknum;
  if ( *v1 != nullptr )
    return 1;
  v3 = (_RTL_CRITICAL_SECTION *)MemAlloc_Alloc(nSize: 0x18u);
  if ( v3 != nullptr )
  {
    _lock(locknum: 10);
    if ( *v1 != nullptr )
    {
      free(pMem: v3);
    }
    else if ( InitializeCriticalSectionAndSpinCount(lpCriticalSection: v3, dwSpinCount: 0xFA0u) )
    {
      *v1 = v3;
    }
    else
    {
      free(pMem: v3);
      *_errno() = 12;
      retval = 0;
    }
    _unlock(locknum: 10);
    return retval;
  }
  else
  {
    *_errno() = 12;
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1030169C
// Name: __lock
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _lock(int locknum)
{
  LPCRITICAL_SECTION *v1; // esi

  v1 = &locktable + 2 * locknum;
  if ( *v1 == nullptr && _mtinitlocknum(locknum) == 0 )
    _amsg_exit(rterrnum: 17);
  EnterCriticalSection(lpCriticalSection: *v1);
}

//------------------------------------------------------------------------------
// Address: 0x103016CF
// Name: __mbsnbicoll_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _mbsnbicoll_l(
        const unsigned __int8 *s1,
        const unsigned __int8 *s2,
        unsigned int n,
        localeinfo_struct *plocinfo)
{
  int result; // eax
  int v5; // eax
  _LocaleUpdate _loc_update; // [esp+4h] [ebp-10h] BYREF

  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  if ( n == 0 )
  {
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
    return 0;
  }
  if ( s1 != nullptr && s2 != nullptr )
  {
    if ( n > 0x7FFFFFFF )
    {
      *_errno() = 22;
      _invalid_parameter_noinfo();
LABEL_15:
      if ( _loc_update.updated )
        _loc_update.ptd->_ownlocale &= ~2u;
      return 0x7FFFFFFF;
    }
    if ( _loc_update.localeinfo.mbcinfo->ismbcodepage != 0 )
    {
      v5 = __crtCompareStringA(
             plocinfo: &_loc_update.localeinfo,
             Locale: _loc_update.localeinfo.mbcinfo->mblcid,
             dwCmpFlags: 0x1001u,
             lpString1: (const char *)s1,
             cchCount1: n,
             lpString2: (const char *)s2,
             cchCount2: n,
             code_page: _loc_update.localeinfo.mbcinfo->mbcodepage);
      if ( v5 == 0 )
        goto LABEL_15;
      result = v5 - 2;
    }
    else
    {
      result = _strnicoll_l(_string1: (const char *)s1, _string2: (const char *)s2, count: n, plocinfo);
    }
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
    return 0x7FFFFFFF;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103017AD
// Name: __mbsnbicoll
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _mbsnbicoll(const unsigned __int8 *s1, const unsigned __int8 *s2, unsigned int n)
{
  return _mbsnbicoll_l(s1, s2, n, plocinfo: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x103017C7
// Name: ___wtomb_environ
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl __wtomb_environ()
{
  LPCWCH *v0; // edi
  const wchar_t *v1; // eax
  unsigned int v2; // eax
  char *v3; // eax
  int size; // [esp+Ch] [ebp-8h]
  char *envp; // [esp+10h] [ebp-4h] BYREF

  v0 = (LPCWCH *)_wenviron;
  envp = nullptr;
  v1 = *_wenviron;
  if ( *_wenviron == nullptr )
    return 0;
  while ( 1 )
  {
    v2 = WideCharToMultiByte(
           CodePage: 0,
           dwFlags: 0,
           lpWideCharStr: v1,
           cchWideChar: -1,
           lpMultiByteStr: nullptr,
           cbMultiByte: 0,
           lpDefaultChar: nullptr,
           lpUsedDefaultChar: nullptr);
    size = v2;
    if ( v2 == 0 )
      break;
    v3 = (char *)calloc(count: v2, size: 1u);
    envp = v3;
    if ( v3 == nullptr )
      break;
    if ( WideCharToMultiByte(
           CodePage: 0,
           dwFlags: 0,
           lpWideCharStr: *v0,
           cchWideChar: -1,
           lpMultiByteStr: v3,
           cbMultiByte: size,
           lpDefaultChar: nullptr,
           lpUsedDefaultChar: nullptr) == 0 )
    {
      free(pMem: envp);
      return -1;
    }
    if ( __crtsetenv(poption: &envp, primary: 0) < 0 && envp != nullptr )
    {
      free(pMem: envp);
      envp = nullptr;
    }
    v1 = *++v0;
    if ( *v0 == nullptr )
      return 0;
  }
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x1030185E
// Name: comexecmd
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl comexecmd(int mode, const char *name, const char **argv, const char **envp)
{
  int v5; // esi
  char *envblk; // [esp+0h] [ebp-8h] BYREF
  char *argblk; // [esp+4h] [ebp-4h] BYREF

  if ( name == nullptr || argv == nullptr )
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return -1;
  }
  if ( _cenvarg(argv, envp, &argblk, &envblk) == -1 )
    return -1;
  v5 = _dospawn(mode, name, cmdblk: argblk, envblk);
  free(pMem: argblk);
  free(pMem: envblk);
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x103018D0
// Name: __spawnve
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _spawnve(int mode, char *name, const char **argv, const char **envp)
{
  char *v4; // edi
  const unsigned __int8 *v6; // esi
  const unsigned __int8 *v7; // eax
  const unsigned __int8 *v8; // eax
  int v9; // eax
  unsigned int v10; // esi
  char *v11; // eax
  char *v12; // ebx
  int v13; // eax
  unsigned int v14; // esi
  char *v15; // eax
  char *v16; // ebx
  int v17; // eax
  char *v18; // edi
  unsigned int v19; // esi
  int save_errno; // [esp+4h] [ebp-10h]
  int rc; // [esp+8h] [ebp-Ch]
  const char **v22; // [esp+Ch] [ebp-8h]
  char *pathname; // [esp+10h] [ebp-4h]

  v4 = name;
  pathname = name;
  if ( name == nullptr || *name == 0 || argv == nullptr || *argv == nullptr || **argv == 0 )
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return -1;
  }
  v6 = _mbsrchr(str: (const unsigned __int8 *)name, c: 0x5Cu);
  v7 = _mbsrchr(str: (const unsigned __int8 *)name, c: 0x2Fu);
  if ( v7 != nullptr )
  {
    if ( v6 == nullptr || v7 > v6 )
      v6 = v7;
  }
  else if ( v6 == nullptr )
  {
    _mbschr(string: (unsigned __int8 *)name, c: 0x3Au);
    v6 = v8;
    if ( v8 == nullptr )
    {
      strlen(buf: name);
      v10 = v9 + 3;
      v11 = (char *)calloc(count: v9 + 3, size: 1u);
      v12 = v11;
      pathname = v11;
      if ( v11 == nullptr )
        return -1;
      if ( strcpy_s(_Dst: v11, _SizeInBytes: v10, _Src: ".\\") != 0
        || strcat_s(_Dst: v12, _SizeInBytes: v10, _Src: name) != 0 )
      {
LABEL_14:
        _invoke_watson();
      }
      v6 = (const unsigned __int8 *)(v12 + 2);
    }
  }
  rc = -1;
  if ( _mbsrchr(str: v6, c: 0x2Eu) == nullptr )
  {
    strlen(buf: pathname);
    v14 = v13 + 5;
    v15 = (char *)calloc(count: v13 + 5, size: 1u);
    v16 = v15;
    if ( v15 == nullptr )
      return -1;
    if ( strcpy_s(_Dst: v15, _SizeInBytes: v14, _Src: pathname) == 0 )
    {
      strlen(buf: pathname);
      v18 = &v16[v17];
      save_errno = *_errno();
      v19 = (unsigned int)&v16[v14 - (_DWORD)v18];
      v22 = (const char **)&ext_strings[3];
      while ( 1 )
      {
        if ( strcpy_s(_Dst: v18, _SizeInBytes: v19, _Src: *v22) != 0 )
          goto LABEL_14;
        if ( _access_s(path: v16, amode: 0) == 0 )
          break;
        if ( (int)--v22 < (int)ext_strings )
          goto LABEL_30;
      }
      *_errno() = save_errno;
      rc = comexecmd(mode, name: v16, argv, envp);
LABEL_30:
      free(pMem: v16);
      v4 = name;
      goto LABEL_31;
    }
    goto LABEL_14;
  }
  if ( _access_s(path: pathname, amode: 0) == 0 )
    rc = comexecmd(mode, name: pathname, argv, envp);
LABEL_31:
  if ( pathname != v4 )
    free(pMem: pathname);
  return rc;
}

//------------------------------------------------------------------------------
// Address: 0x10301AC0
// Name: __global_unwind2
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _global_unwind2(PVOID TargetFrame)
{
  RtlUnwind(TargetFrame, TargetIp: &gu_return, ExceptionRecord: nullptr, ReturnValue: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x10301AE0
// Name: __unwind_handler
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _unwind_handler(int a1, int a2, int a3, _DWORD *a4, int a5)
{
  int result; // eax

  result = 1;
  if ( (*(_DWORD *)(a1 + 4) & 6) != 0 )
  {
    _local_unwind2(a1: *(_DWORD *)(a5 + 36), a2: *(_DWORD *)(a5 + 40));
    *a4 = a2;
    return 3;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10301B25
// Name: __local_unwind2
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _local_unwind2(int a1, unsigned int a2)
{
  int result; // eax
  int v3; // ebx
  unsigned int v4; // esi
  int v5; // esi
  int v6; // ecx
  int v7; // [esp-4h] [ebp-24h]
  _EXCEPTION_REGISTRATION_RECORD *ExceptionList; // [esp+0h] [ebp-20h]

  ExceptionList = NtCurrentTeb()->NtTib.ExceptionList;
  while ( 1 )
  {
    result = a1;
    v3 = *(_DWORD *)(a1 + 8);
    v4 = *(_DWORD *)(a1 + 12);
    if ( v4 == -1 || a2 != -1 && v4 <= a2 )
      break;
    v5 = 3 * v4;
    *(_DWORD *)(a1 + 12) = *(_DWORD *)(v3 + 4 * v5);
    if ( *(_DWORD *)(v3 + 4 * v5 + 4) == 0 )
    {
      _NLG_Notify(a1: 257);
      _NLG_Call(a1: v6, a2: v7, a3: ExceptionList);
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10301BA9
// Name: __abnormal_termination
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _abnormal_termination()
{
  int result; // eax
  _EXCEPTION_REGISTRATION_RECORD *ExceptionList; // ecx

  result = 0;
  ExceptionList = NtCurrentTeb()->NtTib.ExceptionList;
  if ( (int (__cdecl *)(int, int, int, _DWORD *, int))ExceptionList->Handler == _unwind_handler )
    return ExceptionList[1].Next == *((_EXCEPTION_REGISTRATION_RECORD **)ExceptionList[1].Handler + 3);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10301BCC
// Name: __NLG_Notify1
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __stdcall _NLG_Notify1(int a1)
{
  JUMPOUT(0x10301BE0);
}

//------------------------------------------------------------------------------
// Address: 0x10301BD5
// Name: __NLG_Notify
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __userpurge _NLG_Notify@<eax>(unsigned int result@<eax>, unsigned int a2@<ebp>, unsigned int a3)
{
  _NLG_Destination.dwCode = a3;
  _NLG_Destination.uoffDestination = result;
  _NLG_Destination.uoffFramePointer = a2;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10301BF4
// Name: __NLG_Call
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall _NLG_Call@<eax>(int (*a1)(void)@<eax>)
{
  return a1();
}

//------------------------------------------------------------------------------
// Address: 0x10301BF7
// Name: _rt_probe_read4(x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __stdcall _rt_probe_read4(unsigned int *ptr)
{
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10301C50
// Name: __stbuf
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _stbuf(_iobuf *str)
{
  int v1; // eax
  int v2; // eax
  char **v3; // edi
  char *v4; // eax
  char *v5; // edi

  v1 = fileno(stream: str);
  if ( _isatty(fh: v1) == 0 )
    return 0;
  if ( str == &__iob_func()[1] )
  {
    v2 = 0;
  }
  else
  {
    if ( str != &__iob_func()[2] )
      return 0;
    v2 = 1;
  }
  ++_cflush;
  if ( (str->_flag & 0x10C) != 0 )
    return 0;
  v3 = (char **)&_stdbuf[v2];
  if ( *v3 != nullptr || (v4 = (char *)MemAlloc_Alloc(nSize: 0x1000u), *v3 = v4, v4 != nullptr) )
  {
    v5 = *v3;
    str->_base = v5;
    str->_ptr = v5;
    str->_bufsiz = 4096;
    str->_cnt = 4096;
  }
  else
  {
    str->_base = (char *)&str->_charbuf;
    str->_ptr = (char *)&str->_charbuf;
    str->_bufsiz = 2;
    str->_cnt = 2;
  }
  str->_flag |= 0x1102u;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10301CEC
// Name: __ftbuf
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _ftbuf(int flag, _iobuf *str)
{
  if ( flag != 0 && (str->_flag & 0x1000) != 0 )
  {
    _flush(str);
    str->_flag &= 0xFFFFEEFF;
    str->_bufsiz = 0;
    str->_ptr = nullptr;
    str->_base = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10301D20
// Name: __fcloseall
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _fcloseall()
{
  int i; // edi
  _iobuf *v1; // eax
  int count; // [esp+14h] [ebp-1Ch]

  count = 0;
  _lock(locknum: 1);
  for ( i = 3; i < (int)_nstream; ++i )
  {
    if ( __piob[i] != nullptr )
    {
      v1 = (_iobuf *)__piob[i];
      if ( (v1->_flag & 0x83) != 0 && fclose(stream: v1) != -1 )
        ++count;
      if ( i >= 20 )
      {
        DeleteCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)((char *)__piob[i] + 32));
        free(pMem: __piob[i]);
        __piob[i] = nullptr;
      }
    }
  }
  _unlock(locknum: 1);
  return count;
}

//------------------------------------------------------------------------------
// Address: 0x10301DBC
// Name: _CallDestructExceptionObject
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl CallDestructExceptionObject(_EXCEPTION_RECORD *pExcept)
{
  if ( pExcept->ExceptionCode == -529697949
    && __DestructExceptionObject != nullptr
    && _IsNonwritableInCurrentImage(pTarget: (unsigned __int8 *)&_pDestructExceptionObject) != 0 )
  {
    __DestructExceptionObject((EHExceptionRecord *)pExcept);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10301E00
// Name: ValidateScopeTableHandlers
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall ValidateScopeTableHandlers@<eax>(
        unsigned __int8 *pImageBase@<edi>,
        int dwTryLevel@<ecx>,
        _SCOPETABLE_ENTRY *pScopeTable)
{
  _IMAGE_SECTION_HEADER *PESection; // eax
  int v4; // edx
  _SCOPETABLE_ENTRY *v5; // ebx
  unsigned int v6; // esi
  unsigned int v7; // ecx
  _BYTE *FilterFunc; // ecx
  unsigned int v9; // esi
  unsigned int VirtualAddress; // ecx

  PESection = nullptr;
  v4 = -1;
  if ( dwTryLevel == -1 )
    return 1;
  while ( 1 )
  {
    v5 = &pScopeTable[dwTryLevel];
    v6 = ((char *)v5->HandlerFunc - (char *)pImageBase) & 0xFFFFF000;
    if ( v6 != v4 )
      break;
LABEL_9:
    FilterFunc = v5->FilterFunc;
    if ( FilterFunc != nullptr )
    {
      v9 = (FilterFunc - pImageBase) & 0xFFFFF000;
      if ( v9 != v4 )
      {
        VirtualAddress = PESection->VirtualAddress;
        if ( v9 < VirtualAddress || v9 >= VirtualAddress + PESection->Misc.PhysicalAddress )
        {
          PESection = _FindPESection(pImageBase, rva: v9);
          if ( PESection == nullptr || (PESection->Characteristics & 0x20000000) == 0 )
            return 0;
        }
        v4 = v9;
      }
    }
    dwTryLevel = v5->EnclosingLevel;
    if ( v5->EnclosingLevel == -1 )
      return 1;
  }
  if ( PESection != nullptr && (v7 = PESection->VirtualAddress, v6 >= v7) && v6 < v7 + PESection->Misc.PhysicalAddress
    || (PESection = _FindPESection(pImageBase, rva: ((char *)v5->HandlerFunc - (char *)pImageBase) & 0xFFFFF000)) != nullptr
    && (PESection->Characteristics & 0x20000000) != 0 )
  {
    v4 = v6;
    goto LABEL_9;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10301EC0
// Name: __ValidateEH3RN
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _ValidateEH3RN(_EH3_EXCEPTION_REGISTRATION *pRN)
{
  _SCOPETABLE_ENTRY *ScopeTable; // edx
  struct _TEB *v3; // eax
  DWORD TryLevel; // edi
  int v5; // ebx
  DWORD v6; // eax
  _SCOPETABLE_ENTRY *v7; // ecx
  PSCOPETABLE_ENTRY v8; // eax
  int i; // esi
  unsigned __int8 *pPage; // ebx
  unsigned __int8 *pImageBase; // edi
  int v12; // ecx
  bool v13; // cc
  int j; // eax
  unsigned __int8 *v15; // ecx
  unsigned __int8 *v16; // edx
  unsigned __int8 *AllocationBase; // edi
  _IMAGE_SECTION_HEADER *PESection; // eax
  int v19; // edi
  int v20; // eax
  unsigned __int8 **v21; // ecx
  int v22; // esi
  unsigned __int8 *v23; // ecx
  unsigned __int8 *v24; // edx
  _VALID_PAGE_CACHE *v25; // eax
  int v26; // ebx
  unsigned __int8 *v27; // esi
  unsigned __int8 *v28; // edi
  _MEMORY_BASIC_INFORMATION mbi; // [esp+10h] [ebp-40h] BYREF
  unsigned int dwTryLevel; // [esp+2Ch] [ebp-24h]
  unsigned __int8 *pScopePage; // [esp+30h] [ebp-20h]
  _SCOPETABLE_ENTRY *pScopeTable; // [esp+34h] [ebp-1Ch]
  CPPEH_RECORD ms_exc; // [esp+38h] [ebp-18h]

  ScopeTable = pRN->ScopeTable;
  pScopeTable = ScopeTable;
  if ( ((unsigned __int8)ScopeTable & 3) != 0 )
    return 0;
  v3 = NtCurrentTeb();
  pScopePage = (unsigned __int8 *)v3->NtTib.StackLimit;
  if ( ScopeTable >= (_SCOPETABLE_ENTRY *)pScopePage && ScopeTable < v3->NtTib.StackBase )
    return 0;
  TryLevel = pRN->TryLevel;
  dwTryLevel = TryLevel;
  if ( TryLevel != -1 )
  {
    v5 = 0;
    v6 = 0;
    v7 = ScopeTable;
    do
    {
      if ( v7->EnclosingLevel != -1 && v7->EnclosingLevel >= v6 )
        return 0;
      if ( v7->FilterFunc != nullptr )
        v5 = 1;
      ++v6;
      ++v7;
    }
    while ( v6 <= TryLevel );
    if ( v5 == 0 || (v8 = pRN[-1].ScopeTable) >= (PSCOPETABLE_ENTRY)pScopePage && v8 < (PSCOPETABLE_ENTRY)pRN )
    {
      pScopePage = (unsigned __int8 *)((unsigned int)ScopeTable & 0xFFFFF000);
      for ( i = 0; ; ++i )
      {
        if ( i >= nValidPages )
          goto LABEL_39;
        pPage = rgValidPages[i].pPage;
        pImageBase = rgValidPages[i].pImageBase;
        if ( pPage == (unsigned __int8 *)((unsigned int)ScopeTable & 0xFFFFF000) )
          break;
      }
      ms_exc.registration.TryLevel = 0;
      if ( _ValidateImageBase(pImageBase) != 0
        && ValidateScopeTableHandlers(pImageBase, dwTryLevel, pScopeTable) != 0
        && _FindPESection(pImageBase, rva: (char *)pRN->ExceptionHandler - (char *)pImageBase) != nullptr )
      {
        ms_exc.registration.TryLevel = -2;
        if ( i > 0 && _InterlockedExchange(&lModifying, 1) == 0 )
        {
          if ( rgValidPages[i].pPage != pScopePage )
          {
            v12 = nValidPages;
            i = nValidPages - 1;
            if ( nValidPages - 1 >= 0 )
            {
              while ( rgValidPages[i].pPage != pScopePage )
              {
                if ( --i < 0 )
                  goto LABEL_29;
              }
              pPage = rgValidPages[i].pPage;
              pImageBase = rgValidPages[i].pImageBase;
LABEL_29:
              v13 = i <= 0;
              if ( i >= 0 )
                goto LABEL_34;
            }
            if ( nValidPages < 16 )
              v12 = ++nValidPages;
            i = v12 - 1;
          }
          v13 = i <= 0;
LABEL_34:
          if ( !v13 )
          {
            for ( j = 0; j <= i; ++j )
            {
              v15 = rgValidPages[j].pPage;
              v16 = rgValidPages[j].pImageBase;
              rgValidPages[j].pPage = pPage;
              rgValidPages[j].pImageBase = pImageBase;
              pPage = v15;
              pImageBase = v16;
            }
          }
LABEL_64:
          _InterlockedExchange(&lModifying, 0);
          return 1;
        }
        return 1;
      }
      ms_exc.registration.TryLevel = -2;
      ScopeTable = pScopeTable;
LABEL_39:
      if ( VirtualQuery(lpAddress: ScopeTable, lpBuffer: &mbi, dwLength: 0x1Cu) == 0 )
        return 1;
      if ( mbi.Type != 0x1000000 )
        return -1;
      AllocationBase = (unsigned __int8 *)mbi.AllocationBase;
      if ( _ValidateImageBase(pImageBase: (unsigned __int8 *)mbi.AllocationBase) == 0 )
        return -1;
      if ( ((mbi.Protect & 0xCC) == 0
         || (PESection = _FindPESection(pImageBase: AllocationBase, rva: (char *)pScopeTable - (char *)AllocationBase)) != nullptr
         && (PESection->Characteristics & 0x80000000) == 0)
        && ValidateScopeTableHandlers(pImageBase: AllocationBase, dwTryLevel, pScopeTable) != 0
        && _FindPESection(pImageBase: AllocationBase, rva: (char *)pRN->ExceptionHandler - (char *)AllocationBase) != nullptr )
      {
        if ( _InterlockedExchange(&lModifying, 1) != 0 )
          return 1;
        v19 = nValidPages;
        v20 = nValidPages;
        if ( nValidPages > 0 )
        {
          v21 = (unsigned __int8 **)(&nValidPages + 2 * nValidPages);
          do
          {
            if ( *v21 == pScopePage )
              break;
            --v20;
            v21 -= 2;
          }
          while ( v20 > 0 );
        }
        if ( v20 != 0 )
        {
          *(&lModifying + 2 * v20) = (int)mbi.AllocationBase;
        }
        else
        {
          v22 = 15;
          if ( nValidPages <= 15 )
            v22 = nValidPages;
          v23 = pScopePage;
          v24 = (unsigned __int8 *)mbi.AllocationBase;
          if ( v22 >= 0 )
          {
            v25 = rgValidPages;
            v26 = v22 + 1;
            do
            {
              v27 = v25->pPage;
              v28 = v25->pImageBase;
              v25->pPage = v23;
              v25->pImageBase = v24;
              v23 = v27;
              v24 = v28;
              ++v25;
              --v26;
            }
            while ( v26 != 0 );
            v19 = nValidPages;
          }
          if ( v19 < 16 )
            nValidPages = v19 + 1;
        }
        goto LABEL_64;
      }
    }
    return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10302206
// Name: ___getgmtimebuf
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void *__getgmtimebuf()
{
  _tiddata *v0; // eax
  _tiddata *v1; // esi
  void *v3; // eax

  v0 = _getptd_noexit();
  v1 = v0;
  if ( v0 != nullptr )
  {
    if ( v0->_gmtimebuf != nullptr )
      return v1->_gmtimebuf;
    v3 = MemAlloc_Alloc(nSize: 0x24u);
    v1->_gmtimebuf = v3;
    if ( v3 != nullptr )
      return v1->_gmtimebuf;
  }
  *_errno() = 12;
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1030223D
// Name: __localtime64_s
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _localtime64_s(tm *ptm, const __int64 *ptime)
{
  int result; // eax
  int v3; // eax
  unsigned int v4; // ecx
  int v5; // eax
  __int64 v6; // kr00_8
  __int64 v7; // kr10_8
  __int64 v8; // kr20_8
  __int64 v9; // rax
  int v10; // ecx
  int v11; // edx
  __int64 ltime; // [esp+8h] [ebp-14h] BYREF
  int dstbias; // [esp+10h] [ebp-Ch] BYREF
  int daylight; // [esp+14h] [ebp-8h] BYREF
  int timezone; // [esp+18h] [ebp-4h] BYREF

  daylight = 0;
  dstbias = 0;
  timezone = 0;
  if ( ptm == nullptr )
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return 22;
  }
  memset(dst: (unsigned __int8 *)ptm, value: 0xFFu, count: sizeof(tm));
  if ( ptime == nullptr )
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return 22;
  }
  v3 = *((_DWORD *)ptime + 1);
  v4 = *(_DWORD *)ptime;
  if ( v3 < 0 || __SPAIR64__(v3, v4) > 0x793406FFFLL )
  {
    *_errno() = 22;
    return 22;
  }
  __tzset(a1: v4);
  if ( _get_daylight(_Daylight: &daylight) != 0
    || _get_dstbias(_Daylight_savings_bias: &dstbias) != 0
    || _get_timezone(_Timezone: &timezone) != 0 )
  {
    _invoke_watson();
  }
  if ( *ptime <= 259200 )
  {
    result = _gmtime64_s(ptm, timp: ptime);
    if ( result == 0 )
    {
      if ( daylight != 0 && _isindst(tb: ptm) != 0 )
      {
        v5 = dstbias + timezone;
        ptm->tm_isdst = 1;
        v6 = ptm->tm_sec - (__int64)v5;
      }
      else
      {
        v6 = ptm->tm_sec - (__int64)timezone;
      }
      ptm->tm_sec = v6 % 60;
      if ( v6 % 60 < 0 )
      {
        ptm->tm_sec = v6 % 60 + 60;
        v6 = __PAIR64__((unsigned int)__CFADD__((_DWORD)v6, -60) + HIDWORD(v6) - 1, (int)v6 - 60);
      }
      v7 = ptm->tm_min + v6 / 60;
      ptm->tm_min = v7 % 60;
      if ( v7 % 60 < 0 )
      {
        ptm->tm_min = v7 % 60 + 60;
        v7 -= 60;
      }
      v8 = ptm->tm_hour + v7 / 60;
      ptm->tm_hour = v8 % 24;
      if ( v8 % 24 < 0 )
      {
        ptm->tm_hour = v8 % 24 + 24;
        v8 -= 24;
      }
      v9 = v8 / 24;
      v10 = v8 / 24;
      if ( (((unsigned __int64)(v8 / 24) >> 32) & 0x80000000) != 0LL )
      {
        HIDWORD(v9) = ((int)v9 + ptm->tm_wday + 7) % 7;
        ptm->tm_mday += v9;
        LODWORD(v9) = ptm->tm_mday;
        ptm->tm_wday = HIDWORD(v9);
        if ( (int)v9 <= 0 )
        {
          ptm->tm_yday += v10 + 365;
          --ptm->tm_year;
          ptm->tm_mday = v9 + 31;
          ptm->tm_mon = 11;
          return 0;
        }
      }
      else
      {
        if ( v9 <= 0 )
          return 0;
        v11 = (v10 + ptm->tm_wday) % 7;
        ptm->tm_mday += v10;
        ptm->tm_wday = v11;
      }
      ptm->tm_yday += v10;
      return 0;
    }
  }
  else
  {
    ltime = *ptime - timezone;
    result = _gmtime64_s(ptm, timp: &ltime);
    if ( result == 0 )
    {
      if ( daylight == 0 || _isindst(tb: ptm) == 0 )
        return 0;
      ltime -= dstbias;
      result = _gmtime64_s(ptm, timp: &ltime);
      if ( result == 0 )
      {
        ptm->tm_isdst = 1;
        return 0;
      }
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103024C5
// Name: __get_daylight
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _get_daylight(int *_Daylight)
{
  if ( _Daylight != nullptr )
  {
    *_Daylight = _daylight;
    return 0;
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return 22;
  }
}

//------------------------------------------------------------------------------
// Address: 0x103024F2
// Name: __get_dstbias
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _get_dstbias(int *_Daylight_savings_bias)
{
  if ( _Daylight_savings_bias != nullptr )
  {
    *_Daylight_savings_bias = _dstbias;
    return 0;
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return 22;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1030251F
// Name: __get_timezone
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _get_timezone(int *_Timezone)
{
  if ( _Timezone != nullptr )
  {
    *_Timezone = _timezone;
    return 0;
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return 22;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1030254C
// Name: ___daylight
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int *__cdecl __daylight()
{
  return &_daylight;
}

//------------------------------------------------------------------------------
// Address: 0x10302552
// Name: ___dstbias
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int *__cdecl __dstbias()
{
  return &_dstbias;
}

//------------------------------------------------------------------------------
// Address: 0x10302558
// Name: ___timezone
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int *__cdecl __timezone()
{
  return &_timezone;
}

//------------------------------------------------------------------------------
// Address: 0x1030255E
// Name: ___tzname
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char **__cdecl __tzname()
{
  return _tzname;
}

//------------------------------------------------------------------------------
// Address: 0x10302564
// Name: _strncpy_s
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl strncpy_s(char *_Dst, unsigned int _SizeInBytes, const char *_Src, unsigned int _Count)
{
  unsigned int v5; // edi
  int v6; // esi
  const char *v7; // edx
  char *v8; // ecx
  char v9; // cl
  char v10; // dl

  if ( _Count != 0 )
  {
    if ( _Dst == nullptr )
    {
LABEL_7:
      v6 = 22;
      *_errno() = 22;
LABEL_8:
      _invalid_parameter_noinfo();
      return v6;
    }
  }
  else if ( _Dst == nullptr )
  {
    if ( _SizeInBytes == 0 )
      return 0;
    goto LABEL_7;
  }
  v5 = _SizeInBytes;
  if ( _SizeInBytes == 0 )
    goto LABEL_7;
  if ( _Count == 0 )
  {
    *_Dst = 0;
    return 0;
  }
  v7 = _Src;
  if ( _Src == nullptr )
  {
    *_Dst = 0;
    goto LABEL_7;
  }
  v8 = _Dst;
  if ( _Count == -1 )
  {
    do
    {
      v9 = *v7;
      v7[_Dst - _Src] = *v7;
      ++v7;
      if ( v9 == 0 )
        break;
      --v5;
    }
    while ( v5 != 0 );
  }
  else
  {
    do
    {
      v10 = v8[_Src - _Dst];
      *v8++ = v10;
      if ( v10 == 0 )
        break;
      if ( --v5 == 0 )
        break;
      --_Count;
    }
    while ( _Count != 0 );
    if ( _Count == 0 )
      *v8 = 0;
  }
  if ( v5 != 0 )
    return 0;
  if ( _Count != -1 )
  {
    *_Dst = 0;
    *_errno() = 34;
    v6 = 34;
    goto LABEL_8;
  }
  _Dst[_SizeInBytes - 1] = 0;
  return 80;
}

//------------------------------------------------------------------------------
// Address: 0x10302619
// Name: ___init_ctype
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl __init_ctype(threadlocaleinfostruct *ploci)
{
  int v1; // ebx
  unsigned __int8 *v2; // eax
  int j; // eax
  unsigned __int8 *v4; // eax
  int v5; // ecx
  int v6; // edi
  unsigned __int8 *v7; // eax
  unsigned __int8 *v8; // edi
  unsigned __int16 *v9; // ecx
  bool v10; // cc
  unsigned __int8 *v11; // edx
  unsigned __int16 *v12; // ecx
  unsigned __int8 v13; // dl
  unsigned int v14; // ecx
  unsigned __int8 *k; // ecx
  int *v16; // eax
  unsigned int lc_codepage; // [esp-Ch] [ebp-64h]
  localeinfo_struct locinfo; // [esp+Ch] [ebp-4Ch] BYREF
  const unsigned __int8 *v20; // [esp+14h] [ebp-44h]
  const unsigned __int16 *v21; // [esp+18h] [ebp-40h]
  unsigned __int16 *v22; // [esp+1Ch] [ebp-3Ch]
  const unsigned __int8 *v23; // [esp+20h] [ebp-38h]
  unsigned __int8 *v24; // [esp+24h] [ebp-34h]
  int mb_cur_max; // [esp+28h] [ebp-30h]
  int *refcount; // [esp+2Ch] [ebp-2Ch]
  unsigned __int8 *newcumap; // [esp+30h] [ebp-28h]
  unsigned __int8 *cbuffer; // [esp+34h] [ebp-24h]
  int i; // [esp+38h] [ebp-20h]
  unsigned __int16 *newctype1; // [esp+3Ch] [ebp-1Ch]
  _cpinfo lpCPInfo; // [esp+40h] [ebp-18h] BYREF

  v1 = 0;
  refcount = nullptr;
  newctype1 = nullptr;
  i = 0;
  newcumap = nullptr;
  cbuffer = nullptr;
  locinfo.locinfo = ploci;
  locinfo.mbcinfo = nullptr;
  if ( ploci->lc_handle[2] != 0 )
  {
    if ( ploci->lc_codepage == 0
      && __getlocaleinfo(
           plocinfo: &locinfo,
           lc_type: 0,
           localehandle: ploci->lc_id[2].wLanguage,
           fieldtype: 0x1004u,
           address: &ploci->lc_codepage) != 0 )
    {
      goto error_cleanup_0;
    }
    refcount = (int *)MemAlloc_Alloc(nSize: 4u);
    newctype1 = (unsigned __int16 *)calloc(count: 0x180u, size: 2u);
    i = (int)calloc(count: 0x180u, size: 1u);
    newcumap = (unsigned __int8 *)calloc(count: 0x180u, size: 1u);
    v2 = (unsigned __int8 *)calloc(count: 0x101u, size: 1u);
    cbuffer = v2;
    if ( refcount == nullptr )
      goto error_cleanup_0;
    if ( newctype1 == nullptr )
      goto error_cleanup_0;
    if ( v2 == nullptr )
      goto error_cleanup_0;
    if ( i == 0 )
      goto error_cleanup_0;
    if ( newcumap == nullptr )
      goto error_cleanup_0;
    *refcount = 0;
    for ( j = 0; j < 256; ++j )
      cbuffer[j] = j;
    if ( !GetCPInfo(CodePage: ploci->lc_codepage, &lpCPInfo) || lpCPInfo.MaxCharSize > 5 )
      goto error_cleanup_0;
    mb_cur_max = LOWORD(lpCPInfo.MaxCharSize);
    if ( LOWORD(lpCPInfo.MaxCharSize) > 1u && lpCPInfo.LeadByte[0] != 0 )
    {
      v4 = &lpCPInfo.LeadByte[1];
      do
      {
        LOBYTE(v5) = *v4;
        if ( *v4 == 0 )
          break;
        v6 = *(v4 - 1);
        v5 = (unsigned __int8)v5;
        while ( v6 <= v5 )
        {
          cbuffer[v6] = 32;
          v5 = *v4;
          ++v6;
        }
        v4 += 2;
      }
      while ( *(v4 - 1) != 0 );
    }
    lc_codepage = ploci->lc_codepage;
    v21 = newctype1 + 128;
    if ( __crtGetStringTypeA(
           plocinfo: nullptr,
           dwInfoType: 1u,
           lpSrcStr: (const char *)cbuffer,
           cchSrc: 256,
           lpCharType: newctype1 + 128,
           code_page: lc_codepage,
           lcid: 0,
           bError: 0) != 0
      && __crtLCMapStringA(
           plocinfo: nullptr,
           Locale: ploci->lc_handle[2],
           dwMapFlags: 0x100u,
           lpSrcStr: (const char *)cbuffer + 1,
           cchSrc: 255,
           lpDestStr: (char *)(i + 129),
           cchDest: 255,
           code_page: ploci->lc_codepage,
           bError: 0) != 0
      && __crtLCMapStringA(
           plocinfo: nullptr,
           Locale: ploci->lc_handle[2],
           dwMapFlags: 0x200u,
           lpSrcStr: (const char *)cbuffer + 1,
           cchSrc: 255,
           lpDestStr: (char *)newcumap + 129,
           cchDest: 255,
           code_page: ploci->lc_codepage,
           bError: 0) != 0 )
    {
      v7 = (unsigned __int8 *)newctype1;
      v8 = (unsigned __int8 *)i;
      v9 = newctype1 + 127;
      v10 = mb_cur_max <= 1;
      newctype1[127] = 0;
      v11 = newcumap;
      v22 = v9;
      v8[127] = 0;
      v11[127] = 0;
      v8[128] = 0;
      v20 = v8 + 128;
      v23 = v11 + 128;
      v11[128] = 0;
      if ( !v10 && lpCPInfo.LeadByte[0] != 0 )
      {
        v12 = (unsigned __int16 *)&lpCPInfo.LeadByte[1];
        newctype1 = (unsigned __int16 *)&lpCPInfo.LeadByte[1];
        do
        {
          v13 = *(_BYTE *)v12;
          if ( *(_BYTE *)v12 == 0 )
            break;
          v14 = *((unsigned __int8 *)v12 - 1);
          i = v14;
          if ( v14 <= v13 )
          {
            for ( k = &v7[2 * v14 + 256]; ; k = v24 )
            {
              ++i;
              *(_WORD *)k = 0x8000;
              v24 = k + 2;
              if ( i > *(unsigned __int8 *)newctype1 )
                break;
            }
          }
          v12 = newctype1 + 1;
          newctype1 = v12;
        }
        while ( *((_BYTE *)v12 - 1) != 0 );
      }
      memcpy(dst: v7, src: v7 + 512, count: 0xFEu);
      memcpy(dst: v8, src: v8 + 256, count: 0x7Fu);
      memcpy(dst: newcumap, src: newcumap + 256, count: 0x7Fu);
      if ( ploci->ctype1_refcount != nullptr && InterlockedDecrement(lpAddend: ploci->ctype1_refcount) == 0 )
      {
        free(pMem: ploci->ctype1 - 127);
        free(pMem: (void *)(ploci->pclmap - 128));
        free(pMem: (void *)(ploci->pcumap - 128));
        free(pMem: ploci->ctype1_refcount);
      }
      v16 = refcount;
      *refcount = 1;
      ploci->ctype1_refcount = v16;
      ploci->pctype = v21;
      ploci->ctype1 = v22;
      ploci->pclmap = v20;
      ploci->pcumap = v23;
      ploci->mb_cur_max = mb_cur_max;
    }
    else
    {
error_cleanup_0:
      free(pMem: refcount);
      free(pMem: newctype1);
      free(pMem: (void *)i);
      free(pMem: newcumap);
      v1 = 1;
    }
    free(pMem: cbuffer);
    return v1;
  }
  else
  {
    if ( ploci->ctype1_refcount != nullptr )
      InterlockedDecrement(lpAddend: ploci->ctype1_refcount);
    ploci->ctype1_refcount = nullptr;
    ploci->ctype1 = nullptr;
    ploci->pctype = asc_103F9AC0;
    ploci->pclmap = &__newclmap[128];
    ploci->pcumap = &__newcumap[128];
    ploci->mb_cur_max = 1;
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x103029C0
// Name: ____lc_codepage_func
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __cdecl ___lc_codepage_func()
{
  _tiddata *v0; // ecx
  threadlocaleinfostruct *ptlocinfo; // eax

  v0 = _getptd();
  ptlocinfo = v0->ptlocinfo;
  if ( ptlocinfo != __ptlocinfo && (__globallocalestatus & v0->_ownlocale) == 0 )
    ptlocinfo = __updatetlocinfo();
  return ptlocinfo->lc_codepage;
}

//------------------------------------------------------------------------------
// Address: 0x103029E6
// Name: __setenvp
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _setenvp()
{
  char *v0; // esi
  int v1; // edi
  int v3; // eax
  char **v4; // edi
  char *i; // esi
  int v6; // eax
  unsigned int v7; // ebx
  char *v8; // eax

  if ( __mbctype_initialized == 0 )
    __initmbctable();
  v0 = _aenvptr;
  v1 = 0;
  if ( _aenvptr != nullptr )
  {
    while ( *v0 != 0 )
    {
      if ( *v0 != 61 )
        ++v1;
      strlen(buf: v0);
      v0 += v3 + 1;
    }
    v4 = (char **)calloc(count: v1 + 1, size: 4u);
    _environ = v4;
    if ( v4 != nullptr )
    {
      for ( i = _aenvptr; ; i += v7 )
      {
        if ( *i == 0 )
        {
          free(pMem: _aenvptr);
          _aenvptr = nullptr;
          *v4 = nullptr;
          __env_initialized = 1;
          return 0;
        }
        strlen(buf: i);
        v7 = v6 + 1;
        if ( *i != 61 )
          break;
LABEL_15:
        ;
      }
      v8 = (char *)calloc(count: v6 + 1, size: 1u);
      *v4 = v8;
      if ( v8 != nullptr )
      {
        if ( strcpy_s(_Dst: v8, _SizeInBytes: v7, _Src: i) != 0 )
          _invoke_watson();
        ++v4;
        goto LABEL_15;
      }
      free(pMem: _environ);
      _environ = nullptr;
      return -1;
    }
  }
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x10302AC2
// Name: parse_cmdline
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall parse_cmdline(char *cmdstart@<edx>, int *numchars@<edi>, char **argv, char *args, int *numargs)
{
  int *v5; // ecx
  char *v7; // edx
  char **v8; // ebx
  char v9; // bl
  char *v10; // ecx
  char **v11; // eax
  int v12; // ebx
  unsigned int v13; // ecx
  unsigned __int8 v14; // al
  char *v15; // ecx
  char *v16; // ecx
  unsigned __int8 v17; // [esp-4h] [ebp-10h]
  BOOL inquote; // [esp+8h] [ebp-4h]
  BOOL inquotea; // [esp+8h] [ebp-4h]

  v5 = numargs;
  *numchars = 0;
  v7 = args;
  *numargs = 1;
  if ( argv != nullptr )
  {
    v8 = argv++;
    *v8 = args;
  }
  inquote = false;
  do
  {
    if ( *cmdstart == 34 )
    {
      v9 = 34;
      ++cmdstart;
      inquote = !inquote;
    }
    else
    {
      ++*numchars;
      if ( v7 != nullptr )
      {
        *v7 = *cmdstart;
        args = v7 + 1;
      }
      v9 = *cmdstart;
      v17 = *cmdstart++;
      if ( _ismbblead(tst: v17) != 0 )
      {
        ++*numchars;
        if ( args != nullptr )
        {
          v10 = args++;
          *v10 = *cmdstart;
        }
        ++cmdstart;
      }
      v7 = args;
      v5 = numargs;
      if ( v9 == 0 )
      {
        --cmdstart;
        goto LABEL_18;
      }
    }
  }
  while ( inquote || v9 != 32 && v9 != 9 );
  if ( v7 != nullptr )
    *(v7 - 1) = 0;
LABEL_18:
  inquotea = false;
  while ( *cmdstart != 0 )
  {
    while ( *cmdstart == 32 || *cmdstart == 9 )
      ++cmdstart;
    if ( *cmdstart == 0 )
      break;
    if ( argv != nullptr )
    {
      v11 = argv++;
      *v11 = v7;
    }
    ++*v5;
    while ( 1 )
    {
      v12 = 1;
      v13 = 0;
      while ( *cmdstart == 92 )
      {
        ++cmdstart;
        ++v13;
      }
      if ( *cmdstart == 34 )
      {
        if ( (v13 & 1) == 0 )
        {
          if ( inquotea && cmdstart[1] == 34 )
          {
            ++cmdstart;
          }
          else
          {
            v12 = 0;
            inquotea = !inquotea;
          }
        }
        v13 >>= 1;
      }
      if ( v13 != 0 )
      {
        do
        {
          --v13;
          if ( v7 != nullptr )
            *v7++ = 92;
          ++*numchars;
        }
        while ( v13 != 0 );
        args = v7;
      }
      v14 = *cmdstart;
      if ( *cmdstart == 0 || !inquotea && (v14 == 32 || v14 == 9) )
        break;
      if ( v12 != 0 )
      {
        if ( v7 != nullptr )
        {
          if ( _ismbblead(tst: v14) != 0 )
          {
            v15 = args++;
            *v15 = *cmdstart++;
            ++*numchars;
          }
          v16 = args++;
          *v16 = *cmdstart;
        }
        else if ( _ismbblead(tst: v14) != 0 )
        {
          ++cmdstart;
          ++*numchars;
        }
        ++*numchars;
        v7 = args;
      }
      ++cmdstart;
    }
    if ( v7 != nullptr )
    {
      *v7++ = 0;
      args = v7;
    }
    ++*numchars;
    v5 = numargs;
  }
  if ( argv != nullptr )
    *argv = nullptr;
  ++*v5;
}

//------------------------------------------------------------------------------
// Address: 0x10302C5C
// Name: __setargv
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _setargv()
{
  int v0; // edi
  unsigned int v1; // eax
  char **v2; // esi
  int numchars; // [esp+Ch] [ebp-Ch] BYREF
  int numargs; // [esp+10h] [ebp-8h] BYREF
  char *cmdstart; // [esp+14h] [ebp-4h]

  if ( __mbctype_initialized == 0 )
    __initmbctable();
  pgmname[260] = 0;
  GetModuleFileNameA(hModule: nullptr, lpFilename: pgmname, nSize: 0x104u);
  _pgmptr = pgmname;
  if ( _acmdln == nullptr || (cmdstart = _acmdln, *_acmdln == 0) )
    cmdstart = pgmname;
  parse_cmdline(cmdstart, &numchars, argv: nullptr, args: nullptr, &numargs);
  if ( (unsigned int)numargs >= 0x3FFFFFFF )
    return -1;
  if ( numchars == -1 )
    return -1;
  v0 = numargs;
  v1 = 4 * numargs + numchars;
  if ( v1 < numchars )
    return -1;
  v2 = (char **)MemAlloc_Alloc(nSize: v1);
  if ( v2 == nullptr )
    return -1;
  parse_cmdline(cmdstart, &numchars, argv: v2, args: (char *)&v2[v0], &numargs);
  __argc = numargs - 1;
  __argv = v2;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10302D17
// Name: ___crtGetEnvironmentStringsA
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char *__cdecl __crtGetEnvironmentStringsA()
{
  LPWCH EnvironmentStringsW; // eax
  wchar_t *v1; // ebx
  unsigned int v3; // eax
  char *v4; // eax
  int nSizeW; // [esp+8h] [ebp-Ch]
  int nSizeA; // [esp+Ch] [ebp-8h]
  char *aEnv; // [esp+10h] [ebp-4h]

  EnvironmentStringsW = GetEnvironmentStringsW();
  v1 = EnvironmentStringsW;
  if ( EnvironmentStringsW == nullptr )
    return nullptr;
  for ( ; *EnvironmentStringsW != 0; ++EnvironmentStringsW )
  {
    do
      ++EnvironmentStringsW;
    while ( *EnvironmentStringsW != 0 );
  }
  nSizeW = EnvironmentStringsW - v1 + 1;
  v3 = WideCharToMultiByte(
         CodePage: 0,
         dwFlags: 0,
         lpWideCharStr: v1,
         cchWideChar: nSizeW,
         lpMultiByteStr: nullptr,
         cbMultiByte: 0,
         lpDefaultChar: nullptr,
         lpUsedDefaultChar: nullptr);
  nSizeA = v3;
  if ( v3 != 0 && (v4 = (char *)MemAlloc_Alloc(nSize: v3), aEnv = v4, v4 != nullptr) )
  {
    if ( WideCharToMultiByte(
           CodePage: 0,
           dwFlags: 0,
           lpWideCharStr: v1,
           cchWideChar: nSizeW,
           lpMultiByteStr: v4,
           cbMultiByte: nSizeA,
           lpDefaultChar: nullptr,
           lpUsedDefaultChar: nullptr) == 0 )
    {
      free(pMem: aEnv);
      aEnv = nullptr;
    }
    FreeEnvironmentStringsW(penv: v1);
    return aEnv;
  }
  else
  {
    FreeEnvironmentStringsW(penv: v1);
    return nullptr;
  }
}

} // namespace engine_xlsp
