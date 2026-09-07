// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: mysql-connector-c-6.0.2/mysys/my_winerr.c
// Functions: 161
// ============================================================

#include "mysql-connector-c-6.0.2\mysys\my_winerr.h"

//------------------------------------------------------------------------------
// Address: 0x0042F710
// Name: get_errno_from_oserr
// Source: json
//------------------------------------------------------------------------------
int __thiscall get_errno_from_oserr(char *this)
{
  unsigned int i; // eax

  for ( i = 0; i < 0x2D; ++i )
  {
    if ( this == *(char **)((char *)&loc_4CF467 + 8 * i + 1) )
      return dword_4CF46C[2 * i];
  }
  if ( (unsigned int)(this - 19) > 0x11 )
    return (unsigned int)(this - 188) > 0xE ? 22 : 8;
  else
    return 13;
}

//------------------------------------------------------------------------------
// Address: 0x0042F750
// Name: _my_osmaperr
// Source: json
//------------------------------------------------------------------------------
void __thiscall my_osmaperr(ExprNode *oserrno, char *oserrnoa)
{
  int errno_from_oserr; // esi

  errno_from_oserr = get_errno_from_oserr(this: oserrnoa);
  *_errno() = errno_from_oserr;
}

//------------------------------------------------------------------------------
// Address: 0x0045B714
// Name: __get_errno_from_oserr
// Source: json
//------------------------------------------------------------------------------
int __cdecl _get_errno_from_oserr(unsigned int oserrno)
{
  unsigned int i; // ecx

  for ( i = 0; i < 0x2D; ++i )
  {
    if ( oserrno == errtable[i].oscode )
      return errtable[i].errnocode;
  }
  if ( oserrno - 19 > 0x11 )
    return oserrno - 188 > 0xE ? 22 : 8;
  else
    return 13;
}

//------------------------------------------------------------------------------
// Address: 0x0045B756
// Name: __errno
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int *__cdecl _errno()
{
  _tiddata *v0; // eax

  v0 = _getptd_noexit();
  if ( v0 != nullptr )
    return &v0->_terrno;
  else
    return &ErrnoNoMem;
}

//------------------------------------------------------------------------------
// Address: 0x0045B769
// Name: ___doserrno
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int *__cdecl __doserrno()
{
  _tiddata *v0; // eax

  v0 = _getptd_noexit();
  if ( v0 != nullptr )
    return &v0->_tdoserrno;
  else
    return &DoserrorNoMem;
}

//------------------------------------------------------------------------------
// Address: 0x0045B77C
// Name: __dosmaperr
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _dosmaperr(unsigned int oserrno)
{
  int errno_from_oserr; // esi

  *__doserrno() = oserrno;
  errno_from_oserr = _get_errno_from_oserr(oserrno);
  *_errno() = errno_from_oserr;
}

//------------------------------------------------------------------------------
// Address: 0x0045B79F
// Name: __read_nolock
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x0045BD56
// Name: __read
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _read(int fh, void *buf, unsigned int cnt)
{
  ioinfo **v4; // edi
  int v5; // esi
  int r; // [esp+14h] [ebp-1Ch]

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
LABEL_7:
    _invalid_parameter_noinfo();
    return -1;
  }
  if ( cnt > 0x7FFFFFFF )
  {
    *__doserrno() = 0;
    *_errno() = 22;
    goto LABEL_7;
  }
  __lock_fhandle(fh);
  if ( (*(&(*v4)->osfile + v5) & 1) != 0 )
  {
    r = _read_nolock(fh, inputbuf: buf, cnt);
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
// Address: 0x0045BE4C
// Name: __tell
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _tell(int filedes)
{
  return _lseek(fh: filedes, pos: 0, mthd: 1);
}

//------------------------------------------------------------------------------
// Address: 0x0045BE62
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
// Address: 0x0045BED7
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
// Address: 0x0045BFAB
// Name: int _open(char const __near *,int,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _open(const char *path, int oflag, int pmode)
{
  int fh; // [esp+0h] [ebp-4h] BYREF

  if ( _sopen_helper(path, oflag, shflag: 64, pmode, pfh: &fh, bSecure: 0) != 0 )
    return -1;
  else
    return fh;
}

//------------------------------------------------------------------------------
// Address: 0x0045BFE0
// Name: _memset
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall memset(__int128 a1@<xmm0>, int dst, unsigned __int8 value, unsigned int count)
{
  unsigned int v4; // edx
  int v5; // eax
  unsigned __int8 *v6; // edi
  int v7; // ecx
  unsigned int v8; // ecx
  unsigned int v9; // ecx

  v4 = count;
  if ( count != 0 )
  {
    LOBYTE(v5) = value;
    if ( value != 0 || count < 0x80 || __sse2_available == 0 )
    {
      v6 = (unsigned __int8 *)dst;
      if ( count < 4 )
        goto LABEL_15;
      v7 = -dst & 3;
      if ( v7 != 0 )
      {
        v4 = count - v7;
        do
        {
          *v6++ = value;
          --v7;
        }
        while ( v7 != 0 );
      }
      v5 = 16843009 * value;
      v8 = v4;
      v4 &= 3u;
      v9 = v8 >> 2;
      if ( v9 == 0 || (memset32(v6, v5, v9), v6 += 4 * v9, v4 != 0) )
      {
LABEL_15:
        do
        {
          *v6++ = v5;
          --v4;
        }
        while ( v4 != 0 );
      }
    }
    else
    {
      _VEC_memzero(a1: count, _ECX: (_BYTE *)dst, _XMM0: a1);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0045C05A
// Name: ___crtCorExitProcess
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl __crtCorExitProcess(int status)
{
  HMODULE ModuleHandleW; // eax
  void (__stdcall *CorExitProcess)(int); // eax

  ModuleHandleW = GetModuleHandleW(lpModuleName: L"mscoree.dll");
  if ( ModuleHandleW != nullptr )
  {
    CorExitProcess = (void (__stdcall *)(int))GetProcAddress(hModule: ModuleHandleW, lpProcName: "CorExitProcess");
    if ( CorExitProcess != nullptr )
      CorExitProcess(a1: status);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0045C085
// Name: ___crtExitProcess
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl __noreturn __crtExitProcess(int status)
{
  __crtCorExitProcess(status);
  ExitProcess(uExitCode: status);
}

//------------------------------------------------------------------------------
// Address: 0x0045C09D
// Name: __lockexit
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void _lockexit()
{
  _lock(locknum: 8);
}

//------------------------------------------------------------------------------
// Address: 0x0045C0A6
// Name: __unlockexit
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void _unlockexit()
{
  _unlock(locknum: 8);
}

//------------------------------------------------------------------------------
// Address: 0x0045C0AF
// Name: __init_pointers
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void _init_pointers()
{
  int (__cdecl *v0)(unsigned int); // esi

  v0 = (int (__cdecl *)(unsigned int))_encoded_null();
  _initp_heap_handler(enull: v0);
  _initp_misc_invarg(enull: v0);
  _initp_misc_purevirt(enull: v0);
  _initp_misc_rand_s(enull: (int (__stdcall *)(void *, unsigned int))v0);
  _initp_misc_winsig(enull: v0);
  _initp_eh_hooks();
}

//------------------------------------------------------------------------------
// Address: 0x0045C0E2
// Name: __initterm_e
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _initterm_e(int (__cdecl **pfbegin)(), int (__cdecl **pfend)())
{
  int result; // eax

  result = 0;
  while ( pfbegin < pfend && result == 0 )
  {
    if ( *pfbegin != nullptr )
      result = (*pfbegin)();
    ++pfbegin;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0045C106
// Name: __cinit
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _cinit(int initFloatingPrecision)
{
  int result; // eax
  void (**i)(void); // edi

  if ( _fpmath != nullptr && _IsNonwritableInCurrentImage(pTarget: (unsigned __int8 *)&_FPinit) )
    _fpmath(initPrecision: initFloatingPrecision);
  _initp_misc_cfltcvt_tab();
  result = _initterm_e(pfbegin: __xi_a, pfend: __xi_z);
  if ( result == 0 )
  {
    atexit(func: _RTC_Terminate);
    for ( i = __xc_a; i < __xc_z; ++i )
    {
      if ( *i != nullptr )
        (*i)();
    }
    if ( __dyn_tls_init_callback != nullptr
      && _IsNonwritableInCurrentImage(pTarget: (unsigned __int8 *)&__dyn_tls_init_callback) )
    {
      __dyn_tls_init_callback(a1: nullptr, a2: 2u, a3: nullptr);
    }
    return 0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0045C19D
// Name: doexit
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl doexit(int code, int quick, int retcaller)
{
  PVOID *v3; // ebx
  PVOID *v4; // edi
  void (*v5)(void); // ebx
  void (__cdecl **v6)(); // ebx
  void (__cdecl **v7)(); // eax
  void (__cdecl **onexitbegin)(); // [esp+10h] [ebp-30h]
  void (__cdecl **onexitend_saved)(); // [esp+18h] [ebp-28h]
  void (__cdecl **onexitbegin_saved)(); // [esp+1Ch] [ebp-24h]
  void (**j)(void); // [esp+20h] [ebp-20h]
  void (**i)(void); // [esp+24h] [ebp-1Ch]

  _lock(locknum: 8);
  if ( _C_Exit_Done != 1 )
  {
    _C_Termination_Done = 1;
    _exitflag = retcaller;
    if ( quick == 0 )
    {
      v3 = (PVOID *)DecodePointer(Ptr: __onexitbegin);
      onexitbegin = (void (__cdecl **)())v3;
      if ( v3 != nullptr )
      {
        v4 = (PVOID *)DecodePointer(Ptr: __onexitend);
        onexitbegin_saved = (void (__cdecl **)())v3;
        onexitend_saved = (void (__cdecl **)())v4;
        while ( --v4 >= v3 )
        {
          if ( *v4 != _encoded_null() )
          {
            if ( v4 < v3 )
              break;
            v5 = (void (*)(void))DecodePointer(Ptr: *v4);
            *v4 = _encoded_null();
            v5();
            v6 = (void (__cdecl **)())DecodePointer(Ptr: __onexitbegin);
            v7 = (void (__cdecl **)())DecodePointer(Ptr: __onexitend);
            if ( onexitbegin_saved != v6 || onexitend_saved != v7 )
            {
              onexitbegin_saved = v6;
              onexitbegin = v6;
              onexitend_saved = v7;
              v4 = (PVOID *)v7;
            }
            v3 = (PVOID *)onexitbegin;
          }
        }
      }
      for ( i = __xp_a; i < __xp_z; ++i )
      {
        if ( *i != nullptr )
          (*i)();
      }
    }
    for ( j = __xt_a; j < __xt_z; ++j )
    {
      if ( *j != nullptr )
        (*j)();
    }
  }
  if ( retcaller != 0 )
    _unlock(locknum: 8);
  if ( retcaller == 0 )
  {
    _C_Exit_Done = 1;
    _unlock(locknum: 8);
    __crtExitProcess(status: code);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0045C2DD
// Name: _exit
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl __noreturn exit(int code)
{
  doexit(code, quick: 0, retcaller: 0);
}

//------------------------------------------------------------------------------
// Address: 0x0045C2F3
// Name: __exit
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl __noreturn _exit(int code)
{
  doexit(code, quick: 1, retcaller: 0);
}

//------------------------------------------------------------------------------
// Address: 0x0045C309
// Name: __cexit
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _cexit()
{
  doexit(code: 0, quick: 0, retcaller: 1);
}

//------------------------------------------------------------------------------
// Address: 0x0045C318
// Name: __c_exit
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _c_exit()
{
  doexit(code: 0, quick: 1, retcaller: 1);
}

//------------------------------------------------------------------------------
// Address: 0x0045C327
// Name: __amsg_exit
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl __noreturn _amsg_exit(int rterrnum)
{
  _FF_MSGBANNER();
  _NMSG_WRITE(rterrnum);
  _exit(code: 255);
}

//------------------------------------------------------------------------------
// Address: 0x0045C345
// Name: _fprintf
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int fprintf(_iobuf *str, const char *format, ...)
{
  int v3; // eax
  ioinfo *v4; // ecx
  ioinfo *v5; // eax
  int v6; // esi
  int retval; // [esp+10h] [ebp-1Ch]
  va_list argptr; // [esp+3Ch] [ebp+10h] BYREF

  va_start(argptr, format);
  retval = 0;
  if ( str != nullptr && format != nullptr )
  {
    _lock_file(pf: str);
    if ( (str->_flag & 0x40) == 0 )
    {
      v3 = fileno(stream: str);
      if ( v3 == -1 || v3 == -2 )
        v4 = &__badioinfo;
      else
        v4 = &__pioinfo[v3 >> 5][v3 & 0x1F];
      if ( (*((_BYTE *)v4 + 36) & 0x7F) != 0
        || (v3 == -1 || v3 == -2 ? (v5 = &__badioinfo) : (v5 = &__pioinfo[v3 >> 5][v3 & 0x1F]), *((char *)v5 + 36) < 0) )
      {
        *_errno() = 22;
        _invalid_parameter_noinfo();
        retval = -1;
      }
    }
    if ( retval == 0 )
    {
      v6 = _stbuf(str);
      retval = _output_l(stream: str, format, plocinfo: nullptr, argptr);
      _ftbuf(flag: v6, str);
    }
    _unlock_file(pf: str);
    return retval;
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return -1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0045C451
// Name: __strdate_s
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _strdate_s(char *buffer, unsigned int sizeInChars)
{
  int *v2; // eax
  int v4; // edx
  int wMonth; // eax
  int wDay; // edi
  int v7; // [esp-4h] [ebp-1Ch]
  _SYSTEMTIME dt; // [esp+4h] [ebp-14h] BYREF

  if ( buffer == nullptr || sizeInChars == 0 )
  {
    v2 = _errno();
    v7 = 22;
LABEL_4:
    *v2 = v7;
    _invalid_parameter_noinfo();
    return v7;
  }
  *buffer = 0;
  if ( sizeInChars < 9 )
  {
    v2 = _errno();
    v7 = 34;
    goto LABEL_4;
  }
  GetLocalTime(lpSystemTime: &dt);
  v4 = dt.wYear % 100;
  wMonth = dt.wMonth;
  wDay = dt.wDay;
  buffer[5] = 47;
  buffer[2] = 47;
  buffer[8] = 0;
  *buffer = wMonth / 10 + 48;
  buffer[1] = wMonth % 10 + 48;
  buffer[3] = wDay / 10 + 48;
  buffer[4] = wDay % 10 + 48;
  buffer[6] = v4 / 10 + 48;
  buffer[7] = v4 % 10 + 48;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x0045C509
// Name: __strdate
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char *__cdecl _strdate(char *buffer)
{
  return _strdate_s(buffer, sizeInChars: 9u) == 0 ? buffer : nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x0045C525
// Name: __strtime_s
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _strtime_s(char *buffer, unsigned int sizeInChars)
{
  int *v2; // eax
  char v4; // al
  char v5; // dl
  int wMinute; // edi
  int wSecond; // ebx
  int v8; // [esp-4h] [ebp-1Ch]
  _SYSTEMTIME dt; // [esp+4h] [ebp-14h] BYREF

  if ( buffer == nullptr || sizeInChars == 0 )
  {
    v2 = _errno();
    v8 = 22;
LABEL_4:
    *v2 = v8;
    _invalid_parameter_noinfo();
    return v8;
  }
  *buffer = 0;
  if ( sizeInChars < 9 )
  {
    v2 = _errno();
    v8 = 34;
    goto LABEL_4;
  }
  GetLocalTime(lpSystemTime: &dt);
  v4 = dt.wHour / 10;
  v5 = dt.wHour % 10;
  wMinute = dt.wMinute;
  wSecond = dt.wSecond;
  buffer[5] = 58;
  buffer[2] = 58;
  buffer[8] = 0;
  *buffer = v4 + 48;
  buffer[1] = v5 + 48;
  buffer[3] = wMinute / 10 + 48;
  buffer[4] = wMinute % 10 + 48;
  buffer[6] = wSecond / 10 + 48;
  buffer[7] = wSecond % 10 + 48;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x0045C5D3
// Name: __strtime
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char *__cdecl _strtime(char *buffer)
{
  return _strtime_s(buffer, sizeInChars: 9u) == 0 ? buffer : nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x0045C5EF
// Name: __get_sys_err_msg
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char *__cdecl _get_sys_err_msg(int m)
{
  int v1; // esi

  v1 = m;
  if ( m < 0 || m >= *__sys_nerr() )
    v1 = *__sys_nerr();
  return __sys_errlist()[v1];
}

//------------------------------------------------------------------------------
// Address: 0x0045C617
// Name: _strerror
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char *__cdecl strerror(int errnum)
{
  _tiddata *v1; // eax
  _tiddata *v2; // esi
  unsigned __int8 *v4; // eax
  char *errmsg; // esi
  char *sys_err_msg; // eax

  v1 = _getptd_noexit();
  v2 = v1;
  if ( v1 == nullptr )
    return "Visual C++ CRT: Not enough memory to complete call to strerror.";
  if ( v1->_errmsg == nullptr )
  {
    v4 = calloc(count: 0x86u, size: 1u);
    v2->_errmsg = (char *)v4;
    if ( v4 == nullptr )
      return "Visual C++ CRT: Not enough memory to complete call to strerror.";
  }
  errmsg = v2->_errmsg;
  sys_err_msg = _get_sys_err_msg(m: errnum);
  if ( strcpy_s(_Dst: errmsg, _SizeInBytes: 0x86u, _Src: sys_err_msg) != 0 )
    _invoke_watson(pszExpression: nullptr, pszFunction: nullptr, pszFile: nullptr, nLine: 0, pReserved: 0);
  return errmsg;
}

//------------------------------------------------------------------------------
// Address: 0x0045C681
// Name: __fsopen
// Source: linker_block_proximity
//------------------------------------------------------------------------------
_iobuf *__cdecl _fsopen(_iobuf *file, const char *mode, int shflag)
{
  _iobuf *v5; // eax
  _iobuf *retval; // [esp+10h] [ebp-1Ch]
  CPPEH_RECORD ms_exc; // [esp+14h] [ebp-18h] BYREF
  _iobuf *stream; // [esp+34h] [ebp+8h]

  if ( file == nullptr || mode == nullptr || *mode == 0 )
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return nullptr;
  }
  v5 = _getstream();
  stream = v5;
  if ( v5 == nullptr )
  {
    *_errno() = 24;
    return nullptr;
  }
  ms_exc.registration.TryLevel = 0;
  if ( LOBYTE(file->_ptr) == 0 )
  {
    *_errno() = 22;
    _local_unwind4(a1: &__security_cookie, a2: (int)&ms_exc.registration, a3: 0xFFFFFFFE);
    return nullptr;
  }
  retval = _openfile(filename: (const char *)file, mode, shflag, str: v5);
  _unlock_file(pf: stream);
  return retval;
}

//------------------------------------------------------------------------------
// Address: 0x0045C73D
// Name: _fopen
// Source: linker_block_proximity
//------------------------------------------------------------------------------
_iobuf *__cdecl fopen(_iobuf *file, const char *mode)
{
  return _fsopen(file, mode, shflag: 64);
}

//------------------------------------------------------------------------------
// Address: 0x0045C760
// Name: __alloca_probe_16
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int _alloca_probe_16()
{
  return _chkstk();
}

//------------------------------------------------------------------------------
// Address: 0x0045C78C
// Name: _asctime
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char *__cdecl asctime(const tm *tb)
{
  char *asctimebuf; // edi
  _tiddata *v2; // eax
  _tiddata *v3; // esi
  unsigned __int8 *v4; // eax
  char *v5; // ecx
  int tm_mon; // edi
  int tm_mday; // edx
  int tm_wday; // eax
  int v10; // edx
  int i; // eax
  char v12; // dl
  char v13; // dl
  char v14; // dl
  char v15; // dl
  char v16; // dl
  int v17; // edx
  char *p; // [esp+10h] [ebp-4h]

  asctimebuf = buf;
  p = buf;
  v2 = _getptd_noexit();
  v3 = v2;
  if ( v2 != nullptr )
  {
    if ( v2->_asctimebuf != nullptr
      || (v4 = calloc(count: 0x1Au, size: 1u), v3->_asctimebuf = (char *)v4, v4 != nullptr) )
    {
      asctimebuf = v3->_asctimebuf;
      p = asctimebuf;
    }
  }
  v5 = asctimebuf;
  if ( asctimebuf != nullptr
    && (*asctimebuf = 0, tb != nullptr)
    && tb->tm_year >= 0
    && (unsigned int)(tm_mon = tb->tm_mon) < 0xC
    && tb->tm_hour < 0x18u
    && tb->tm_min < 0x3Cu
    && tb->tm_sec < 0x3Cu
    && (tm_mday = tb->tm_mday) >= 1
    && (dword_5A62E8[tm_mon] - _days[tm_mon] >= tm_mday
     || ((tb->tm_year + 1900) % 4 == 0 && (tb->tm_year + 1900) % 100 != 0 || (tb->tm_year + 1900) % 400 == 0)
     && tm_mon == 1
     && tb->tm_mday <= 29)
    && (unsigned int)(tm_wday = tb->tm_wday) <= 6 )
  {
    v10 = 3 * tm_wday;
    for ( i = 0; i < 3; ++i )
    {
      *v5 = __dnames[v10 + i];
      p[i + 4] = __mnames[3 * tm_mon + i];
      ++v5;
    }
    *v5 = 32;
    v5[4] = 32;
    v12 = tb->tm_mday % 10;
    v5[5] = tb->tm_mday / 10 + 48;
    v5[6] = v12 + 48;
    v5[7] = 32;
    v13 = tb->tm_hour % 10;
    v5[8] = tb->tm_hour / 10 + 48;
    v5[9] = v13 + 48;
    v5[10] = 58;
    v14 = tb->tm_min % 10;
    v5[11] = tb->tm_min / 10 + 48;
    v5[12] = v14 + 48;
    v5[13] = 58;
    v15 = tb->tm_sec % 10;
    v5[14] = tb->tm_sec / 10 + 48;
    v5[15] = v15 + 48;
    v5[16] = 32;
    v16 = (tb->tm_year / 100 + 19) % 10;
    v5[17] = (tb->tm_year / 100 + 19) / 10 + 48;
    v5[18] = v16 + 48;
    v17 = tb->tm_year % 100;
    v5[19] = v17 / 10 + 48;
    v5[20] = v17 % 10 + 48;
    *(_WORD *)(v5 + 21) = 10;
    return p;
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0045C970
// Name: _strncpy
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl strncpy(unsigned __int8 *dest, unsigned __int8 *source, unsigned int count)
{
  unsigned int v3; // ecx
  unsigned int v4; // ebx
  unsigned __int8 *v5; // esi
  unsigned int v7; // ecx
  unsigned __int8 v8; // al
  unsigned int v9; // ecx
  int v10; // eax
  int v11; // edx

  v3 = count;
  if ( count == 0 )
    return;
  v4 = count;
  v5 = source;
  if ( ((unsigned __int8)source & 3) == 0 )
  {
    v7 = count >> 2;
    if ( count >> 2 != 0 )
      goto main_loop_entrance;
copy_tail_loop:
    while ( 1 )
    {
      v8 = *v5++;
      *dest++ = v8;
      if ( v8 == 0 )
        break;
      if ( --v4 == 0 )
        return;
    }
    while ( --v4 != 0 )
finish_loop:
      *dest++ = v8;
    return;
  }
  do
  {
    v8 = *v5++;
    *dest++ = v8;
    if ( --v3 == 0 )
      return;
    if ( v8 == 0 )
    {
      while ( ((unsigned __int8)dest & 3) != 0 )
      {
        *dest++ = 0;
        if ( --v3 == 0 )
          return;
      }
      v4 = v3;
      v9 = v3 >> 2;
      if ( v9 == 0 )
        goto finish_loop;
      goto fill_dwords_with_EOS;
    }
  }
  while ( ((unsigned __int8)v5 & 3) != 0 );
  LOBYTE(v4) = v3;
  v7 = v3 >> 2;
  if ( v7 == 0 )
  {
tail_loop_start:
    v4 &= 3u;
    if ( v4 != 0 )
      goto copy_tail_loop;
    return;
  }
  while ( 1 )
  {
main_loop_entrance:
    v10 = (*(_DWORD *)v5 + 2130640639) ^ ~*(_DWORD *)v5;
    v11 = *(_DWORD *)v5;
    v5 += 4;
    if ( (v10 & 0x81010100) != 0 )
    {
      if ( (_BYTE)v11 == 0 )
        break;
      if ( BYTE1(v11) == 0 )
      {
        *(_DWORD *)dest = (unsigned __int8)v11;
        goto fill_with_EOS_dwords;
      }
      if ( (v11 & 0xFF0000) == 0 )
      {
        *(_DWORD *)dest = (unsigned __int16)v11;
        goto fill_with_EOS_dwords;
      }
      if ( (v11 & 0xFF000000) == 0 )
      {
        *(_DWORD *)dest = v11;
        goto fill_with_EOS_dwords;
      }
    }
    *(_DWORD *)dest = v11;
    dest += 4;
    if ( --v7 == 0 )
      goto tail_loop_start;
  }
  *(_DWORD *)dest = 0;
fill_with_EOS_dwords:
  dest += 4;
  v8 = 0;
  v9 = v7 - 1;
  if ( v9 != 0 )
  {
fill_dwords_with_EOS:
    v8 = 0;
    do
    {
      *(_DWORD *)dest = 0;
      dest += 4;
      --v9;
    }
    while ( v9 != 0 );
  }
  v4 &= 3u;
  if ( v4 != 0 )
    goto finish_loop;
}

//------------------------------------------------------------------------------
// Address: 0x0045CA94
// Name: _sprintf
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int sprintf(char *string, const char *format, ...)
{
  int v3; // eax
  bool v4; // sf
  int v5; // esi
  _iobuf str; // [esp+8h] [ebp-20h] BYREF
  va_list argptr; // [esp+38h] [ebp+10h] BYREF

  va_start(argptr, format);
  memset(&str, 0, sizeof(str));
  if ( format != nullptr && string != nullptr )
  {
    str._base = string;
    str._ptr = string;
    str._cnt = 0x7FFFFFFF;
    str._flag = 66;
    v3 = _output_l(stream: &str, format, plocinfo: nullptr, argptr);
    v4 = --str._cnt < 0;
    v5 = v3;
    if ( v4 )
      _flsbuf(ch: 0, (int)&str);
    else
      *str._ptr = 0;
    return v5;
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return -1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0045CB18
// Name: _sprintf_s
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int sprintf_s(char *string, unsigned int sizeInBytes, const char *format, ...)
{
  va_list ap; // [esp+14h] [ebp+14h] BYREF

  va_start(ap, format);
  return _vsprintf_s_l(string, sizeInBytes, format, plocinfo: nullptr, ap);
}

//------------------------------------------------------------------------------
// Address: 0x0045CB40
// Name: __ftol2_sse
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall _ftol2_sse@<eax>(double a1@<st0>)
{
  if ( __sse2_available != 0 )
    return _ftol2_pentium4();
  else
    return _ftol2(a1);
}

//------------------------------------------------------------------------------
// Address: 0x0045CB49
// Name: __ftol2_pentium4
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall _ftol2_pentium4@<eax>(double a1@<st0>)
{
  int result; // eax
  double v2; // [esp+0h] [ebp-8h]

  v2 = a1;
  __asm { cvttsd2si eax, [esp+8+var_8] }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0045CB5C
// Name: __ftol2_sse_excpt
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall _ftol2_sse_excpt@<eax>(double a1@<st0>)
{
  char v2; // [esp+0h] [ebp-4h]

  if ( __sse2_available != 0 && (v2 & 0x7F) == 0x7F )
    return _ftol2_pentium4(a1);
  else
    return _ftol2(a1);
}

//------------------------------------------------------------------------------
// Address: 0x0045CB76
// Name: __ftol2
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __usercall _ftol2@<eax>(double a1@<st0>)
{
  int v1; // edx
  unsigned int result; // eax
  float v3; // [esp+0h] [ebp-20h]
  int v4; // [esp+18h] [ebp-8h]

  *(float *)&v4 = a1;
  v1 = v4;
  result = (__int64)a1;
  if ( result != 0 || ((v1 = (unsigned __int64)(__int64)a1 >> 32) & 0x7FFFFFFF) != 0 )
  {
    if ( v1 >= 0 )
    {
      v3 = a1 - (double)(__int64)a1;
      result -= __CFADD__(LODWORD(v3), 0x7FFFFFFF);
    }
    else
    {
      return (__PAIR64__(result, -(float)(a1 - (double)(__int64)a1)) + 0x7FFFFFFF) >> 32;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0045CD0E
// Name: _atexit
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl atexit(void (__cdecl *func)())
{
  return (_onexit((int (__cdecl *)())func) != nullptr) - 1;
}

//------------------------------------------------------------------------------
// Address: 0x0045CD25
// Name: __vsnprintf_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _vsnprintf_l(char *string, unsigned int count, const char *format, localeinfo_struct *plocinfo, char *ap)
{
  int result; // eax
  int v6; // edi
  _iobuf str; // [esp+4h] [ebp-20h] BYREF

  memset(&str, 0, sizeof(str));
  if ( format != nullptr && (count == 0 || string != nullptr) )
  {
    str._cnt = 0x7FFFFFFF;
    if ( count <= 0x7FFFFFFF )
      str._cnt = count;
    str._flag = 66;
    str._base = string;
    str._ptr = string;
    result = _output_l(stream: &str, format, plocinfo, argptr: ap);
    v6 = result;
    if ( string != nullptr )
    {
      if ( --str._cnt < 0 )
        _flsbuf(ch: 0, (int)&str);
      else
        *str._ptr = 0;
      return v6;
    }
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return -1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0045CDD1
// Name: __vsnprintf
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _vsnprintf(char *string, unsigned int count, const char *format, char *ap)
{
  return _vsnprintf_l(string, count, format, plocinfo: nullptr, ap);
}

//------------------------------------------------------------------------------
// Address: 0x0045CDEE
// Name: __aligned_offset_malloc
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void *__cdecl _aligned_offset_malloc(unsigned int size, unsigned int align, unsigned int offset)
{
  unsigned int v3; // esi
  unsigned int v5; // esi
  unsigned int v6; // edi
  int v7; // ebx
  void *v8; // eax
  void *v9; // ecx
  int v10; // esi

  v3 = align;
  if ( ((align - 1) & align) != 0 || offset != 0 && offset >= size )
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return nullptr;
  }
  if ( align <= 4 )
    v3 = 4;
  v5 = v3 - 1;
  v6 = -offset & 3;
  v7 = v6 + v5 + 4;
  if ( size > v7 + size )
  {
    *_errno() = 12;
    return nullptr;
  }
  v8 = operator new(nSize: v7 + size);
  v9 = v8;
  if ( v8 == nullptr )
    return nullptr;
  v10 = ~v5;
  *(_DWORD *)((v10 & ((unsigned int)v9 + v7 + offset)) - offset - v6 - 4) = v9;
  return (void *)((v10 & ((unsigned int)v8 + v7 + offset)) - offset);
}

//------------------------------------------------------------------------------
// Address: 0x0045CE86
// Name: __aligned_free
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _aligned_free(unsigned int memblock)
{
  if ( memblock != 0 )
    free(pMem: *(void **)((memblock & 0xFFFFFFFC) - 4));
}

//------------------------------------------------------------------------------
// Address: 0x0045CEA0
// Name: __aligned_malloc
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void *__cdecl _aligned_malloc(unsigned int size, unsigned int alignment)
{
  return _aligned_offset_malloc(size, align: alignment, offset: 0);
}

//------------------------------------------------------------------------------
// Address: 0x0045CEB7
// Name: fast_error_exit
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl __noreturn fast_error_exit(int rterrnum)
{
  if ( __error_mode == 1 )
    _FF_MSGBANNER();
  _NMSG_WRITE(rterrnum);
  __crtExitProcess(status: 255);
}

//------------------------------------------------------------------------------
// Address: 0x0045CEE0
// Name: __tmainCRTStartup
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _tmainCRTStartup()
{
  int v0; // eax
  char *v1; // eax
  int wShowWindow; // ecx
  HMODULE v3; // eax
  _STARTUPINFOW StartupInfo; // [esp+10h] [ebp-68h] BYREF
  int mainret; // [esp+58h] [ebp-20h]
  int managedapp; // [esp+5Ch] [ebp-1Ch]
  CPPEH_RECORD ms_exc; // [esp+60h] [ebp-18h]

  GetStartupInfoW(lpStartupInfo: &StartupInfo);
  if ( _NoHeapEnableTerminationOnCorruption == 0 )
    HeapSetInformation(
      HeapHandle: nullptr,
      HeapInformationClass: HeapEnableTerminationOnCorruption,
      HeapInformation: nullptr,
      HeapInformationLength: 0);
  managedapp = LOWORD(MEMORY[0x400000].unused) == 23117
            && *(_DWORD *)(MEMORY[0x40003C] + 0x400000) == 17744
            && *(_WORD *)(MEMORY[0x40003C] + 4194328) == 267
            && *(_DWORD *)(MEMORY[0x40003C] + 4194420) > 0xEu
            && *(_DWORD *)(MEMORY[0x40003C] + 4194536) != 0;
  if ( !_heap_init() )
    fast_error_exit(rterrnum: 28);
  if ( _mtinit() == 0 )
    fast_error_exit(rterrnum: 16);
  _RTC_Initialize();
  ms_exc.registration.TryLevel = 0;
  if ( _ioinit() < 0 )
    _amsg_exit(rterrnum: 27);
  _acmdln = GetCommandLineA();
  _aenvptr = __crtGetEnvironmentStringsA();
  if ( _setargv() < 0 )
    _amsg_exit(rterrnum: 8);
  if ( _setenvp() < 0 )
    _amsg_exit(rterrnum: 9);
  v0 = _cinit(initFloatingPrecision: 1);
  if ( v0 != 0 )
    _amsg_exit(rterrnum: v0);
  v1 = (char *)_wincmdln();
  if ( (StartupInfo.dwFlags & 1) != 0 )
    wShowWindow = StartupInfo.wShowWindow;
  else
    wShowWindow = 10;
  v3 = WinMain(hInstance: (HINSTANCE)0x400000, hPrevInstance: nullptr, pCmdLine: v1, nCmdShow: wShowWindow);
  mainret = (int)v3;
  if ( managedapp == 0 )
    exit(code: (int)v3);
  _cexit();
  return mainret;
}

//------------------------------------------------------------------------------
// Address: 0x0045D04D
// Name: _WinMainCRTStartup
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl WinMainCRTStartup()
{
  __security_init_cookie();
  return _tmainCRTStartup();
}

//------------------------------------------------------------------------------
// Address: 0x0045D057
// Name: __initp_misc_winsig
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _initp_misc_winsig(void *enull)
{
  ctrlc_action = enull;
  ctrlbreak_action = enull;
  abort_action = enull;
  term_action = enull;
}

//------------------------------------------------------------------------------
// Address: 0x0045D075
// Name: ctrlevent_capture
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __stdcall ctrlevent_capture(unsigned int CtrlType)
{
  PVOID *v1; // esi
  void (__cdecl *v2)(int); // eax
  int sigcode; // [esp+10h] [ebp-20h]
  void (__cdecl *ctrl_action)(int); // [esp+14h] [ebp-1Ch]

  _lock(locknum: 0);
  if ( CtrlType != 0 )
  {
    v1 = &ctrlbreak_action;
    v2 = (void (__cdecl *)(int))DecodePointer(Ptr: ctrlbreak_action);
    ctrl_action = v2;
    sigcode = 21;
  }
  else
  {
    v1 = &ctrlc_action;
    v2 = (void (__cdecl *)(int))DecodePointer(Ptr: ctrlc_action);
    ctrl_action = v2;
    sigcode = 2;
  }
  if ( (unsigned int)v2 >= 2 )
    *v1 = _encoded_null();
  _unlock(locknum: 0);
  if ( ctrl_action == nullptr )
    return 0;
  if ( ctrl_action != (void (__cdecl *)(int))1 )
    ctrl_action(a1: sigcode);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0045D111
// Name: siglookup
// Source: linker_block_proximity
//------------------------------------------------------------------------------
_XCPT_ACTION *__usercall siglookup@<eax>(int signum@<edx>, _XCPT_ACTION *pxcptacttab)
{
  _XCPT_ACTION *result; // eax

  result = pxcptacttab;
  do
  {
    if ( result->SigNum == signum )
      break;
    ++result;
  }
  while ( result < &pxcptacttab[12] );
  if ( result >= &pxcptacttab[12] || result->SigNum != signum )
    return nullptr;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0045D148
// Name: ___get_sigabrt
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void (__cdecl *__cdecl __get_sigabrt())(int)
{
  return (void (__cdecl *)(int))DecodePointer(Ptr: abort_action);
}

//------------------------------------------------------------------------------
// Address: 0x0045D155
// Name: _signal
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl signal(int signum, void (__cdecl *sigact)(int))
{
  void (__cdecl *v2)(int); // esi
  _tiddata *v3; // eax
  _tiddata *v4; // esi
  unsigned __int8 *v5; // eax
  _XCPT_ACTION *v6; // eax
  int *p_SigNum; // eax
  unsigned int *v8; // esi
  int SetConsoleCtrlError; // [esp+10h] [ebp-20h]
  void (__cdecl *oldsigact)(int); // [esp+14h] [ebp-1Ch]

  SetConsoleCtrlError = 0;
  v2 = sigact;
  if ( sigact == (void (__cdecl *)(int))4 || sigact == (void (__cdecl *)(int))3 )
    goto sigreterror;
  if ( signum == 2 || signum == 21 || signum == 22 || signum == 6 || signum == 15 )
  {
    _lock(locknum: 0);
    if ( (signum == 2 || signum == 21) && ConsoleCtrlHandler_Installed == 0 )
    {
      if ( SetConsoleCtrlHandler(HandlerRoutine: ctrlevent_capture, Add: true) )
      {
        ConsoleCtrlHandler_Installed = 1;
      }
      else
      {
        v8 = __doserrno();
        *v8 = GetLastError();
        SetConsoleCtrlError = 1;
        v2 = sigact;
      }
    }
    switch ( signum )
    {
      case 2:
        oldsigact = (void (__cdecl *)(int))DecodePointer(Ptr: ctrlc_action);
        if ( v2 != (void (__cdecl *)(int))2 )
          ctrlc_action = EncodePointer(Ptr: v2);
        break;
      case 6:
        goto LABEL_31;
      case 15:
        oldsigact = (void (__cdecl *)(int))DecodePointer(Ptr: term_action);
        if ( v2 != (void (__cdecl *)(int))2 )
          term_action = EncodePointer(Ptr: v2);
        break;
      case 21:
        oldsigact = (void (__cdecl *)(int))DecodePointer(Ptr: ctrlbreak_action);
        if ( v2 != (void (__cdecl *)(int))2 )
          ctrlbreak_action = EncodePointer(Ptr: v2);
        break;
      default:
LABEL_31:
        oldsigact = (void (__cdecl *)(int))DecodePointer(Ptr: abort_action);
        if ( v2 != (void (__cdecl *)(int))2 )
          abort_action = EncodePointer(Ptr: v2);
        break;
    }
    _unlock(locknum: 0);
    if ( SetConsoleCtrlError == 0 )
      return (int)oldsigact;
    goto sigreterror;
  }
  if ( signum != 8 && signum != 4 && signum != 11 )
    goto sigreterror;
  v3 = _getptd_noexit();
  v4 = v3;
  if ( v3 == nullptr )
    goto sigreterror;
  if ( v3->_pxcptacttab == _XcptActTab )
  {
    v5 = (unsigned __int8 *)operator new(nSize: 0x90u);
    v4->_pxcptacttab = v5;
    if ( v5 == nullptr )
      goto sigreterror;
    memcpy(dst: v5, src: (unsigned __int8 *)_XcptActTab, count: 0x90u);
  }
  v6 = siglookup(signum, pxcptacttab: (_XCPT_ACTION *)v4->_pxcptacttab);
  if ( v6 != nullptr )
  {
    oldsigact = v6->XcptAction;
    if ( sigact != (void (__cdecl *)(int))2 )
    {
      p_SigNum = &v6->SigNum;
      do
      {
        if ( *p_SigNum != signum )
          break;
        p_SigNum[1] = (int)sigact;
        p_SigNum += 3;
      }
      while ( (char *)(p_SigNum - 1) < (char *)v4->_pxcptacttab + 144 );
    }
    return (int)oldsigact;
  }
sigreterror:
  if ( signum != 1 && signum != 3 && signum != 13 && (signum <= 15 || signum > 17) )
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
  }
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0045D395
// Name: _raise
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl raise(int signum)
{
  _tiddata *v1; // edi
  _tiddata *v2; // eax
  int result; // eax
  PVOID *p_XcptAction; // esi
  PVOID v5; // eax
  void (__cdecl *v6)(int); // eax
  int oldfpecode; // [esp+10h] [ebp-30h]
  _EXCEPTION_POINTERS *oldpxcptinfoptrs; // [esp+14h] [ebp-2Ch]
  int indx; // [esp+1Ch] [ebp-24h]
  void (__cdecl *sigact)(int); // [esp+20h] [ebp-20h]
  int siglock; // [esp+24h] [ebp-1Ch]

  v1 = nullptr;
  siglock = 0;
  if ( signum > 11 )
  {
    if ( signum == 15 )
    {
      p_XcptAction = &term_action;
      v5 = term_action;
      goto LABEL_18;
    }
    if ( signum == 21 )
    {
      p_XcptAction = &ctrlbreak_action;
      v5 = ctrlbreak_action;
      goto LABEL_18;
    }
    if ( signum != 22 )
      goto LABEL_14;
    goto LABEL_15;
  }
  if ( signum != 11 )
  {
    if ( signum == 2 )
    {
      p_XcptAction = &ctrlc_action;
      v5 = ctrlc_action;
LABEL_18:
      siglock = 1;
      v6 = (void (__cdecl *)(int))DecodePointer(Ptr: v5);
      goto LABEL_19;
    }
    if ( signum != 4 )
    {
      if ( signum != 6 )
      {
        if ( signum == 8 )
          goto LABEL_7;
LABEL_14:
        *_errno() = 22;
        _invalid_parameter_noinfo();
        return -1;
      }
LABEL_15:
      p_XcptAction = &abort_action;
      v5 = abort_action;
      goto LABEL_18;
    }
  }
LABEL_7:
  v2 = _getptd_noexit();
  v1 = v2;
  if ( v2 == nullptr )
    return -1;
  p_XcptAction = (PVOID *)&siglookup(signum, pxcptacttab: (_XCPT_ACTION *)v2->_pxcptacttab)->XcptAction;
  v6 = (void (__cdecl *)(int))*p_XcptAction;
LABEL_19:
  sigact = v6;
  result = 0;
  if ( sigact == (void (__cdecl *)(int))1 )
    return result;
  if ( sigact == nullptr )
    _exit(code: 3);
  if ( siglock != 0 )
    _lock(locknum: 0);
  if ( signum == 8 || signum == 11 || signum == 4 )
  {
    oldpxcptinfoptrs = (_EXCEPTION_POINTERS *)v1->_tpxcptinfoptrs;
    v1->_tpxcptinfoptrs = nullptr;
    if ( signum != 8 )
      goto LABEL_33;
    oldfpecode = v1->_tfpecode;
    v1->_tfpecode = 140;
  }
  if ( signum == 8 )
  {
    for ( indx = 3; indx < 12; ++indx )
      *((_DWORD *)v1->_pxcptacttab + 3 * indx + 2) = 0;
    goto $LN37_0;
  }
LABEL_33:
  *p_XcptAction = _encoded_null();
$LN37_0:
  if ( siglock != 0 )
    _unlock(locknum: 0);
  if ( signum == 8 )
    ((void (__cdecl *)(int, int))sigact)(a1: 8, a2: v1->_tfpecode);
  else
    sigact(a1: signum);
  if ( signum == 8 || signum == 11 || signum == 4 )
  {
    v1->_tpxcptinfoptrs = oldpxcptinfoptrs;
    if ( signum == 8 )
      v1->_tfpecode = oldfpecode;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x0045D538
// Name: __security_check_cookie(x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __fastcall __security_check_cookie(uintptr_t StackCookie)
{
  if ( StackCookie != __security_cookie )
    __report_gsfailure();
}

//------------------------------------------------------------------------------
// Address: 0x0045D547
// Name: __getenv_helper_nolock
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char *__cdecl _getenv_helper_nolock(char *option)
{
  char **v1; // esi
  unsigned int v3; // eax
  unsigned int v4; // edi
  unsigned int v5; // eax

  v1 = _environ;
  if ( __env_initialized == 0 )
    return nullptr;
  if ( _environ != nullptr || _wenviron != nullptr && __wtomb_environ() == 0 && (v1 = _environ, _environ != nullptr) )
  {
    if ( option != nullptr )
    {
      strlen(buf: option);
      v4 = v3;
      while ( *v1 != nullptr )
      {
        strlen(buf: *v1);
        if ( v5 > v4
          && (*v1)[v4] == 61
          && _mbsnbicoll(s1: (const unsigned __int8 *)*v1, s2: (const unsigned __int8 *)option, n: v4) == 0 )
        {
          return &(*v1)[v4 + 1];
        }
        ++v1;
      }
    }
  }
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x0045D5CE
// Name: _getenv
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char *__cdecl getenv(char *option)
{
  char *retval; // [esp+14h] [ebp-1Ch]

  if ( option != nullptr && strnlen(str: option, maxsize: 0x7FFFu) < 0x7FFF )
  {
    _lock(locknum: 7);
    retval = _getenv_helper_nolock(option);
    _unlock(locknum: 7);
    return retval;
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0045D650
// Name: _floor
// Source: linker_block_proximity
//------------------------------------------------------------------------------
double __cdecl floor(double X)
{
  int v1; // eax
  bool v2; // zf
  char v4; // [esp+0h] [ebp-8h]

  if ( __use_sse2_mathfcns == 0 )
    return _floor_default(x: X);
  v1 = _mm_getcsr() & 0x7F80;
  v2 = v1 == 8064;
  if ( v1 == 8064 )
    v2 = (v4 & 0x7F) == 127;
  if ( v2 )
    return _floor_pentium4(X);
  else
    return _floor_default(x: X);
}

//------------------------------------------------------------------------------
// Address: 0x0045D690
// Name: __floor_pentium4
// Source: linker_block_proximity
//------------------------------------------------------------------------------
double __cdecl _floor_pentium4(double a1)
{
  __asm { movq    xmm0, [esp+arg_0] }
  _XMM2 = *(_OWORD *)&Bns;
  _XMM1 = _XMM0;
  __asm
  {
    psrlq   xmm0, 34h ; '4'
    movd    eax, xmm0
    andpd   xmm0, ds:_S
    psubd   xmm2, xmm0
    psrlq   xmm1, xmm2
  }
  if ( (_EAX & 0x800) != 0 )
  {
    __asm
    {
      movq    xmm0, [esp+arg_0]
      psllq   xmm1, xmm2
    }
    _XMM3 = _XMM0;
    __asm { cmpltpd xmm0, xmm1 }
    if ( _EAX < 3071 )
    {
      __asm
      {
        cmpltpd xmm3, ds:_NegZero
        orpd    xmm3, ds:_NegZero
        andpd   xmm3, ds:_NegOne
        movq    [esp+arg_0], xmm3
      }
      return a1;
    }
    else
    {
      if ( _EAX > 3122 )
        return a1;
      __asm
      {
        andpd   xmm0, ds:_One
        subsd   xmm1, xmm0
        movq    [esp+arg_0], xmm1
      }
      return a1;
    }
  }
  else
  {
    if ( _EAX >= 1023 )
    {
      __asm { psllq   xmm1, xmm2 }
      if ( _EAX <= 1074 )
      {
        __asm { movq    [esp+arg_0], xmm1 }
        return a1;
      }
      return a1;
    }
    return 0.0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0045D771
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
// Address: 0x0045D7D0
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
// Address: 0x0045D885
// Name: public: _LocaleUpdate::_LocaleUpdate(struct localeinfo_struct __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
_LocaleUpdate *__thiscall _LocaleUpdate::_LocaleUpdate(_LocaleUpdate *this, localeinfo_struct *plocinfo)
{
  _tiddata *v3; // eax
  _tiddata *ptd; // eax

  this->updated = false;
  if ( plocinfo != nullptr )
  {
    this->localeinfo = *plocinfo;
  }
  else
  {
    v3 = _getptd();
    this->ptd = v3;
    this->localeinfo.locinfo = v3->ptlocinfo;
    this->localeinfo.mbcinfo = v3->ptmbcinfo;
    if ( this->localeinfo.locinfo != __ptlocinfo && (__globallocalestatus & v3->_ownlocale) == 0 )
      this->localeinfo.locinfo = __updatetlocinfo();
    if ( this->localeinfo.mbcinfo != __ptmbcinfo && (__globallocalestatus & this->ptd->_ownlocale) == 0 )
      this->localeinfo.mbcinfo = __updatetmbcinfo();
    ptd = this->ptd;
    if ( (ptd->_ownlocale & 2) == 0 )
    {
      ptd->_ownlocale |= 2u;
      this->updated = true;
    }
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0045D90C
// Name: strtoxl
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __cdecl strtoxl(
        localeinfo_struct *plocinfo,
        const char *nptr,
        const char **endptr,
        unsigned int ibase,
        int flags)
{
  threadlocaleinfostruct *locinfo; // ecx
  unsigned __int8 v7; // bl
  const char *i; // edi
  int v9; // eax
  unsigned int v10; // eax
  const unsigned __int16 *pctype; // esi
  unsigned int v12; // ecx
  int v13; // ecx
  const char *v14; // edi
  _LocaleUpdate _loc_update; // [esp+4h] [ebp-1Ch] BYREF
  unsigned int v16; // [esp+18h] [ebp-8h]
  unsigned int number; // [esp+1Ch] [ebp-4h]

  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  if ( endptr != nullptr )
    *endptr = nptr;
  if ( nptr == nullptr || ibase != 0 && ((int)ibase < 2 || (int)ibase > 36) )
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
    return 0;
  }
  number = 0;
  locinfo = _loc_update.localeinfo.locinfo;
  v7 = *nptr;
  for ( i = nptr + 1; ; ++i )
  {
    if ( locinfo->mb_cur_max <= 1 )
    {
      v9 = locinfo->pctype[v7] & 8;
    }
    else
    {
      v9 = _isctype_l(c: v7, mask: 8, plocinfo: &_loc_update.localeinfo);
      locinfo = _loc_update.localeinfo.locinfo;
    }
    if ( v9 == 0 )
      break;
    v7 = *i;
  }
  if ( v7 == 45 )
  {
    flags |= 2u;
  }
  else if ( v7 != 43 )
  {
    goto LABEL_20;
  }
  v7 = *i++;
LABEL_20:
  if ( ibase != 0 )
  {
    if ( ibase != 16 || v7 != 48 )
      goto LABEL_32;
  }
  else
  {
    if ( v7 != 48 )
    {
      ibase = 10;
      goto LABEL_32;
    }
    if ( *i != 120 && *i != 88 )
    {
      ibase = 8;
      goto LABEL_32;
    }
    ibase = 16;
  }
  if ( *i == 120 || *i == 88 )
  {
    v7 = i[1];
    i += 2;
  }
LABEL_32:
  v10 = 0xFFFFFFFF / ibase;
  pctype = locinfo->pctype;
  v16 = 0xFFFFFFFF % ibase;
  while ( 1 )
  {
    if ( (pctype[v7] & 4) != 0 )
    {
      v12 = (char)v7 - 48;
    }
    else
    {
      if ( (pctype[v7] & 0x103) == 0 )
        break;
      v13 = (char)v7;
      if ( (unsigned __int8)(v7 - 97) <= 0x19u )
        v13 = (char)v7 - 32;
      v12 = v13 - 55;
    }
    if ( v12 >= ibase )
      break;
    flags |= 8u;
    if ( number < v10 || number == v10 && v12 <= v16 )
    {
      number = v12 + ibase * number;
    }
    else
    {
      flags |= 4u;
      if ( endptr == nullptr )
        break;
    }
    v7 = *i++;
  }
  v14 = i - 1;
  if ( (flags & 8) != 0 )
  {
    if ( (flags & 4) != 0
      || (flags & 1) == 0 && ((flags & 2) != 0 && number > 0x80000000 || (flags & 2) == 0 && number > 0x7FFFFFFF) )
    {
      *_errno() = 34;
      if ( (flags & 1) != 0 )
        number = -1;
      else
        number = ((flags & 2) != 0) + 0x7FFFFFFF;
    }
  }
  else
  {
    if ( endptr != nullptr )
      v14 = nptr;
    number = 0;
  }
  if ( endptr != nullptr )
    *endptr = v14;
  if ( (flags & 2) != 0 )
    number = -number;
  if ( _loc_update.updated )
    _loc_update.ptd->_ownlocale &= ~2u;
  return number;
}

//------------------------------------------------------------------------------
// Address: 0x0045DB37
// Name: _strtol
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __cdecl strtol(const char *nptr, char **endptr, unsigned int ibase)
{
  if ( __locale_changed != 0 )
    return strtoxl(plocinfo: nullptr, nptr, (const char **)endptr, ibase, flags: 0);
  else
    return strtoxl(plocinfo: &__initiallocalestructinfo, nptr, (const char **)endptr, ibase, flags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x0045DB62
// Name: _strtoul
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __cdecl strtoul(const char *nptr, char **endptr, unsigned int ibase)
{
  if ( __locale_changed != 0 )
    return strtoxl(plocinfo: nullptr, nptr, (const char **)endptr, ibase, flags: 1);
  else
    return strtoxl(plocinfo: &__initiallocalestructinfo, nptr, (const char **)endptr, ibase, flags: 1);
}

//------------------------------------------------------------------------------
// Address: 0x0045DBA0
// Name: _strchr
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl strchr(char *string, unsigned __int8 chr)
{
  char *v2; // edx
  char v3; // cl
  int v4; // ecx
  int v5; // esi
  int v6; // eax
  unsigned int v7; // eax
  unsigned int v8; // eax
  unsigned int v9; // eax

  v2 = string;
  if ( ((unsigned __int8)string & 3) != 0 )
  {
    while ( 1 )
    {
      v3 = *v2++;
      if ( v3 == chr || v3 == 0 )
        break;
      if ( ((unsigned __int8)v2 & 3) == 0 )
        goto main_loop_0;
    }
  }
  else
  {
    do
    {
main_loop_0:
      while ( 1 )
      {
        v4 = ((chr << 8) | chr | (((chr << 8) | chr) << 16)) ^ *(_DWORD *)v2;
        v5 = *(_DWORD *)v2 + 2130640639;
        v6 = v5 ^ ~*(_DWORD *)v2;
        v2 += 4;
        if ( (((v4 + 2130640639) ^ ~v4) & 0x81010100) != 0 )
          break;
        v7 = v6 & 0x81010100;
        if ( v7 != 0 && ((v7 & 0x1010100) != 0 || (v5 & 0x80000000) == 0) )
          return;
      }
      v8 = *((_DWORD *)v2 - 1);
      if ( (_BYTE)v8 == chr )
        break;
      if ( (_BYTE)v8 == 0 )
        break;
      if ( BYTE1(v8) == chr )
        break;
      if ( BYTE1(v8) == 0 )
        break;
      v9 = HIWORD(v8);
      if ( (_BYTE)v9 == chr )
        break;
    }
    while ( (_BYTE)v9 != 0 && BYTE1(v9) != chr && BYTE1(v9) != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x0045DC5E
// Name: _strcat_s
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl strcat_s(char *_Dst, unsigned int _SizeInBytes, const char *_Src)
{
  unsigned int v3; // edi
  int v4; // esi
  const char *v6; // edx
  char *v7; // esi
  int v8; // esi
  char v9; // al

  if ( _Dst == nullptr )
    goto LABEL_3;
  v3 = _SizeInBytes;
  if ( _SizeInBytes == 0 )
    goto LABEL_3;
  v6 = _Src;
  if ( _Src != nullptr )
  {
    v7 = _Dst;
    do
    {
      if ( *v7 == 0 )
        break;
      ++v7;
      --v3;
    }
    while ( v3 != 0 );
    if ( v3 != 0 )
    {
      v8 = v7 - _Src;
      do
      {
        v9 = *v6;
        v6[v8] = *v6;
        ++v6;
        if ( v9 == 0 )
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
  }
  *_Dst = 0;
LABEL_3:
  v4 = 22;
  *_errno() = 22;
LABEL_4:
  _invalid_parameter_noinfo();
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x0045DCCB
// Name: ___iob_func
// Source: linker_block_proximity
//------------------------------------------------------------------------------
_iobuf *__cdecl __iob_func()
{
  return _iob;
}

//------------------------------------------------------------------------------
// Address: 0x0045DCD1
// Name: ___initstdio
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl __initstdio()
{
  unsigned int v0; // eax
  void **v1; // eax
  int v3; // edx
  _iobuf *v4; // ecx
  int v5; // edx
  _DWORD *v6; // ecx
  int osfhnd; // eax

  v0 = _nstream;
  if ( _nstream == 0 )
  {
    v0 = 512;
LABEL_5:
    _nstream = v0;
    goto LABEL_6;
  }
  if ( (int)_nstream < 20 )
  {
    v0 = 20;
    goto LABEL_5;
  }
LABEL_6:
  v1 = (void **)calloc(count: v0, size: 4u);
  __piob = v1;
  if ( v1 == nullptr )
  {
    _nstream = 20;
    v1 = (void **)calloc(count: 0x14u, size: 4u);
    __piob = v1;
    if ( v1 == nullptr )
      return 26;
  }
  v3 = 0;
  v4 = _iob;
  while ( 1 )
  {
    v1[v3++] = v4++;
    if ( (int)v4 >= (int)&__abort_behavior )
      break;
    v1 = __piob;
  }
  v5 = 0;
  v6 = &unk_5A5CA0;
  do
  {
    osfhnd = __pioinfo[v5 >> 5][v5 & 0x1F].osfhnd;
    if ( osfhnd == -1 || osfhnd == -2 || osfhnd == 0 )
      *v6 = -2;
    v6 += 8;
    ++v5;
  }
  while ( (int)v6 < (int)dword_5A5D00 );
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x0045DD82
// Name: ___endstdio
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __endstdio()
{
  _flushall();
  if ( _exitflag != 0 )
    _fcloseall();
  free(pMem: __piob);
}

//------------------------------------------------------------------------------
// Address: 0x0045DDA2
// Name: __lock_file
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _lock_file(_iobuf *pf)
{
  if ( pf < _iob || pf > &stru_5A5EF0 )
  {
    EnterCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)&pf[1]);
  }
  else
  {
    _lock(locknum: pf - _iob + 16);
    pf->_flag |= 0x8000u;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0045DDE3
// Name: __lock_file2
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _lock_file2(int i, char *s)
{
  if ( i >= 20 )
  {
    EnterCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)(s + 32));
  }
  else
  {
    _lock(locknum: i + 16);
    *((_DWORD *)s + 3) |= 0x8000u;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0045DE15
// Name: __unlock_file
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _unlock_file(_iobuf *pf)
{
  if ( pf < _iob || pf > &stru_5A5EF0 )
  {
    LeaveCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)&pf[1]);
  }
  else
  {
    pf->_flag &= ~0x8000u;
    _unlock(locknum: pf - _iob + 16);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0045DE51
// Name: __unlock_file2
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _unlock_file2(int i, char *s)
{
  if ( i >= 20 )
  {
    LeaveCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)(s + 32));
  }
  else
  {
    *((_DWORD *)s + 3) &= ~0x8000u;
    _unlock(locknum: i + 16);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0045DE80
// Name: __aulldiv
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __stdcall _aulldiv(unsigned __int64 a1, __int64 a2)
{
  unsigned __int64 v3; // rtt
  unsigned int v4; // ecx
  unsigned int v5; // ebx
  unsigned __int64 v6; // rax
  char v7; // cf
  unsigned int v8; // esi
  unsigned __int64 v9; // rax

  if ( HIDWORD(a2) != 0 )
  {
    v4 = HIDWORD(a2);
    v5 = a2;
    v6 = a1;
    do
    {
      v7 = v4 & 1;
      v4 >>= 1;
      v5 = (v5 >> 1) | (v7 << 31);
      v6 >>= 1;
    }
    while ( v4 != 0 );
    v8 = v6 / v5;
    v9 = v8 * (unsigned __int64)(unsigned int)a2;
    if ( __CFADD__(HIDWORD(a2) * v8, HIDWORD(v9)) || (HIDWORD(v9) = (a2 * (unsigned __int64)v8) >> 32, v9 > a1) )
      --v8;
    return v8;
  }
  else
  {
    LODWORD(v3) = a1;
    HIDWORD(v3) = HIDWORD(a1) % (unsigned int)a2;
    return v3 / (unsigned int)a2;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0045DEF0
// Name: __alldiv
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __stdcall _alldiv(unsigned __int64 a1, __int64 a2)
{
  int v2; // edi
  int v3; // eax
  unsigned __int64 v4; // rtt
  __int64 v5; // rax
  unsigned __int64 v6; // rcx
  unsigned __int64 v7; // rax
  unsigned int v8; // esi
  unsigned __int64 v9; // rax

  v2 = 0;
  if ( (a1 & 0x8000000000000000uLL) != 0LL )
  {
    v2 = 1;
    HIDWORD(a1) = -HIDWORD(a1) - ((_DWORD)a1 != 0);
    LODWORD(a1) = -(int)a1;
  }
  v3 = HIDWORD(a2);
  if ( a2 < 0 )
  {
    ++v2;
    v3 = -HIDWORD(a2) - ((_DWORD)a2 != 0);
    HIDWORD(a2) = v3;
    LODWORD(a2) = -(int)a2;
  }
  if ( v3 != 0 )
  {
    v6 = __PAIR64__(v3, a2);
    v7 = a1;
    do
    {
      v6 >>= 1;
      v7 >>= 1;
    }
    while ( HIDWORD(v6) != 0 );
    v8 = v7 / (unsigned int)v6;
    v9 = v8 * (unsigned __int64)(unsigned int)a2;
    if ( __CFADD__(HIDWORD(a2) * v8, HIDWORD(v9)) || (HIDWORD(v9) = (a2 * (unsigned __int64)v8) >> 32, v9 > a1) )
      --v8;
    v5 = v8;
  }
  else
  {
    LODWORD(v4) = a1;
    HIDWORD(v4) = HIDWORD(a1) % (unsigned int)a2;
    LODWORD(v5) = v4 / (unsigned int)a2;
    HIDWORD(v5) = HIDWORD(a1) / (unsigned int)a2;
  }
  if ( v2 == 1 )
    return -v5;
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x0045DF9A
// Name: _abort
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl __noreturn abort()
{
  if ( __get_sigabrt() != nullptr )
    raise(signum: 22);
  if ( (__abort_behavior & 2) != 0 )
    _call_reportfault(nDbgHookCode: 3, dwExceptionCode: 0x40000015u, dwExceptionFlags: 1u);
  _exit(code: 3);
}

//------------------------------------------------------------------------------
// Address: 0x0045DFCD
// Name: __set_abort_behavior
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __cdecl _set_abort_behavior(unsigned int flags, unsigned int mask)
{
  unsigned int result; // eax

  result = __abort_behavior;
  __abort_behavior = mask & flags | __abort_behavior & ~mask;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0045DFF0
// Name: _memmove
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl memmove(unsigned __int8 *dst, unsigned __int8 *src, unsigned int count)
{
  unsigned __int8 *v3; // esi
  unsigned __int8 *v4; // edi
  unsigned int v5; // ecx
  unsigned __int8 *v6; // esi
  unsigned __int8 *v7; // edi
  unsigned int v8; // ecx

  v3 = src;
  v4 = dst;
  if ( dst > src && dst < &src[count] )
  {
    v6 = &src[count - 4];
    v7 = &dst[count - 4];
    if ( ((unsigned __int8)v7 & 3) != 0 )
    {
      switch ( count )
      {
        case 0u:
          return;
        case 1u:
TrailDown1_0:
          v7[3] = v6[3];
          break;
        case 2u:
TrailDown2_0:
          v7[3] = v6[3];
          v7[2] = v6[2];
          break;
        case 3u:
TrailDown3_0:
          v7[3] = v6[3];
          v7[2] = v6[2];
          v7[1] = v6[1];
          break;
        default:
          __asm { jmp     dword ptr ds:(ByteCopyDown_0+4)[eax*4] }
          return;
      }
    }
    else
    {
      v8 = count >> 2;
      if ( count >> 2 < 8 )
      {
        switch ( count & 3 )
        {
          case 0u:
            return;
          case 1u:
            goto TrailDown1_0;
          case 2u:
            goto TrailDown2_0;
          case 3u:
            goto TrailDown3_0;
        }
      }
      else
      {
        while ( v8 != 0 )
        {
          *(_DWORD *)v7 = *(_DWORD *)v6;
          v6 -= 4;
          v7 -= 4;
          --v8;
        }
        switch ( count & 3 )
        {
          case 0u:
            return;
          case 1u:
            goto TrailDown1_0;
          case 2u:
            goto TrailDown2_0;
          case 3u:
            goto TrailDown3_0;
        }
      }
    }
  }
  else if ( count >= 0x80
         && __sse2_available != 0
         && (v3 = src, v4 = dst, ((unsigned __int8)dst & 0xF) == ((unsigned __int8)src & 0xF)) )
  {
    _VEC_memcpy(a1: count, _EDI: dst, _ESI: src);
  }
  else
  {
    if ( ((unsigned __int8)v4 & 3) != 0 )
    {
      if ( count >= 4 )
        __asm { jmp     dword ptr ds:(CopyUnwindUp_0+4)[eax*4] }
      __asm { jmp     dword ptr ds:TrailUp0_0[ecx*4]; jumptable 0045E049 case 0 }
    }
    v5 = count >> 2;
    switch ( v5 )
    {
      case 0u:
        goto UnwindUp0_0;
      case 1u:
        goto UnwindUp1_0;
      case 2u:
        goto UnwindUp2_0;
      case 3u:
        goto UnwindUp3_0;
      case 4u:
        goto UnwindUp4_0;
      case 5u:
        goto UnwindUp5_0;
      case 6u:
        goto UnwindUp6_0;
      case 7u:
        *(_DWORD *)&v4[4 * v5 - 28] = *(_DWORD *)&v3[4 * v5 - 28];
UnwindUp6_0:
        *(_DWORD *)&v4[4 * v5 - 24] = *(_DWORD *)&v3[4 * v5 - 24];
UnwindUp5_0:
        *(_DWORD *)&v4[4 * v5 - 20] = *(_DWORD *)&v3[4 * v5 - 20];
UnwindUp4_0:
        *(_DWORD *)&v4[4 * v5 - 16] = *(_DWORD *)&v3[4 * v5 - 16];
UnwindUp3_0:
        *(_DWORD *)&v4[4 * v5 - 12] = *(_DWORD *)&v3[4 * v5 - 12];
UnwindUp2_0:
        *(_DWORD *)&v4[4 * v5 - 8] = *(_DWORD *)&v3[4 * v5 - 8];
UnwindUp1_0:
        *(_DWORD *)&v4[4 * v5 - 4] = *(_DWORD *)&v3[4 * v5 - 4];
        v3 += 4 * v5;
        v4 += 4 * v5;
UnwindUp0_0:
        switch ( count & 3 )
        {
          case 0u:
            return;
          case 1u:
            goto TrailUp1_0;
          case 2u:
            goto TrailUp2_0;
          case 3u:
            goto TrailUp3_0;
        }
      default:
        qmemcpy(v4, v3, 4 * v5);
        v3 += 4 * v5;
        v4 += 4 * v5;
        switch ( count & 3 )
        {
          case 0u:
            return;
          case 1u:
TrailUp1_0:
            *v4 = *v3;
            break;
          case 2u:
TrailUp2_0:
            *v4 = *v3;
            v4[1] = v3[1];
            break;
          case 3u:
TrailUp3_0:
            *v4 = *v3;
            v4[1] = v3[1];
            v4[2] = v3[2];
            break;
        }
        break;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0045E351
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
// Address: 0x0045E370
// Name: __allmul
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned __int64 __stdcall _allmul(__int64 a1, __int64 a2)
{
  if ( (HIDWORD(a1) | HIDWORD(a2)) != 0 )
    return a1 * a2;
  else
    return (unsigned int)a2 * (unsigned __int64)(unsigned int)a1;
}

//------------------------------------------------------------------------------
// Address: 0x0045E3B0
// Name: __aullrem
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned __int64 __stdcall _aullrem(unsigned __int64 a1, __int64 a2)
{
  unsigned __int64 v2; // rtt
  unsigned int v4; // ecx
  unsigned int v5; // ebx
  unsigned __int64 v6; // rax
  bool v7; // cf
  int v8; // ecx
  unsigned __int64 v9; // rax

  if ( HIDWORD(a2) != 0 )
  {
    v4 = HIDWORD(a2);
    v5 = a2;
    v6 = a1;
    do
    {
      v7 = v4 & 1;
      v4 >>= 1;
      v5 = (v5 >> 1) | (v7 << 31);
      v6 >>= 1;
    }
    while ( v4 != 0 );
    v8 = HIDWORD(a2) * (v6 / v5);
    v9 = (unsigned int)a2 * (unsigned __int64)(unsigned int)(v6 / v5);
    v7 = __CFADD__(v8, HIDWORD(v9));
    HIDWORD(v9) += v8;
    if ( v7 || v9 > a1 )
      v9 -= a2;
    return a1 - v9;
  }
  else
  {
    LODWORD(v2) = a1;
    HIDWORD(v2) = HIDWORD(a1) % (unsigned int)a2;
    return v2 % (unsigned int)a2;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0045E430
// Name: __aulldvrm
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __stdcall _aulldvrm(unsigned __int64 a1, __int64 a2)
{
  unsigned __int64 v2; // rtt
  unsigned int v3; // esi
  unsigned int v4; // ecx
  unsigned int v5; // ebx
  unsigned __int64 v6; // rax
  char v7; // cf
  unsigned __int64 v8; // rax

  if ( HIDWORD(a2) != 0 )
  {
    v4 = HIDWORD(a2);
    v5 = a2;
    v6 = a1;
    do
    {
      v7 = v4 & 1;
      v4 >>= 1;
      v5 = (v5 >> 1) | (v7 << 31);
      v6 >>= 1;
    }
    while ( v4 != 0 );
    v3 = v6 / v5;
    v8 = v3 * (unsigned __int64)(unsigned int)a2;
    if ( __CFADD__(HIDWORD(a2) * v3, HIDWORD(v8)) || (HIDWORD(v8) = (a2 * (unsigned __int64)v3) >> 32, v8 > a1) )
      --v3;
  }
  else
  {
    LODWORD(v2) = a1;
    HIDWORD(v2) = HIDWORD(a1) % (unsigned int)a2;
    return v2 / (unsigned int)a2;
  }
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x0045E4C5
// Name: _tzset_nolock
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void tzset_nolock()
{
  unsigned __int8 *v0; // eax
  char *v1; // esi
  int v2; // eax
  int v3; // eax
  int v4; // eax
  int v5; // edi
  int v6; // edi
  int v7; // edi
  char **v8; // edi
  const char *v9; // esi
  char v10; // al
  int v11; // eax
  int v12; // eax
  int v13; // esi
  int v14; // esi
  int negdiff; // [esp+14h] [ebp-38h]
  UINT lc_cp; // [esp+18h] [ebp-34h]
  int defused; // [esp+1Ch] [ebp-30h] BYREF
  int nochange; // [esp+20h] [ebp-2Ch]
  int dstbias; // [esp+24h] [ebp-28h] BYREF
  int daylight; // [esp+28h] [ebp-24h] BYREF
  char **tzname; // [esp+2Ch] [ebp-20h]
  int timezone; // [esp+30h] [ebp-1Ch] BYREF
  CPPEH_RECORD ms_exc; // [esp+34h] [ebp-18h]

  negdiff = 0;
  nochange = 0;
  timezone = 0;
  daylight = 0;
  dstbias = 0;
  _lock(locknum: 7);
  ms_exc.registration.TryLevel = 0;
  tzname = __tzname();
  if ( _get_timezone(_Timezone: &timezone) != 0
    || _get_daylight(_Daylight: &daylight) != 0
    || _get_dstbias(_Daylight_savings_bias: &dstbias) != 0 )
  {
LABEL_12:
    _invoke_watson(pszExpression: nullptr, pszFunction: nullptr, pszFile: nullptr, nLine: 0, pReserved: 0);
  }
  lc_cp = ___lc_codepage_func();
  tzapiused = 0;
  dstend.yr = -1;
  dststart.yr = -1;
  v0 = (unsigned __int8 *)_getenv_helper_nolock(option: "TZ");
  v1 = (char *)v0;
  if ( v0 == nullptr || *v0 == 0 )
  {
    if ( lastTZ != nullptr )
    {
      free(pMem: lastTZ);
      lastTZ = nullptr;
    }
    if ( GetTimeZoneInformation(lpTimeZoneInformation: &tzinfo) != -1 )
    {
      tzapiused = 1;
      timezone = 60 * tzinfo.Bias;
      if ( tzinfo.StandardDate.wMonth != 0 )
        timezone = 60 * tzinfo.StandardBias + 60 * tzinfo.Bias;
      if ( tzinfo.DaylightDate.wMonth != 0 && tzinfo.DaylightBias != 0 )
      {
        daylight = 1;
        dstbias = 60 * (tzinfo.DaylightBias - tzinfo.StandardBias);
      }
      else
      {
        daylight = 0;
        dstbias = 0;
      }
      if ( WideCharToMultiByte(
             CodePage: lc_cp,
             dwFlags: 0,
             lpWideCharStr: tzinfo.StandardName,
             cchWideChar: -1,
             lpMultiByteStr: *tzname,
             cbMultiByte: 63,
             lpDefaultChar: nullptr,
             lpUsedDefaultChar: &defused) == 0
        || defused != 0 )
      {
        **tzname = 0;
      }
      else
      {
        (*tzname)[63] = 0;
      }
      if ( WideCharToMultiByte(
             CodePage: lc_cp,
             dwFlags: 0,
             lpWideCharStr: tzinfo.DaylightName,
             cchWideChar: -1,
             lpMultiByteStr: tzname[1],
             cbMultiByte: 63,
             lpDefaultChar: nullptr,
             lpUsedDefaultChar: &defused) == 0
        || defused != 0 )
      {
        *tzname[1] = 0;
      }
      else
      {
        tzname[1][63] = 0;
      }
    }
    goto LABEL_30;
  }
  if ( lastTZ != nullptr )
  {
    strcmp(str1: v0, str2: (unsigned __int8 *)lastTZ);
    if ( v2 == 0 )
    {
LABEL_30:
      nochange = 1;
      goto LABEL_31;
    }
    if ( lastTZ != nullptr )
      free(pMem: lastTZ);
  }
  strlen(buf: v1);
  lastTZ = (char *)operator new(nSize: v3 + 1);
  if ( lastTZ == nullptr )
    goto LABEL_30;
  strlen(buf: v1);
  if ( strcpy_s(_Dst: lastTZ, _SizeInBytes: v4 + 1, _Src: v1) != 0 )
    goto LABEL_12;
LABEL_31:
  v5 = timezone;
  *__timezone() = v5;
  v6 = daylight;
  *__daylight() = v6;
  v7 = dstbias;
  *__dstbias() = v7;
  ms_exc.registration.TryLevel = -2;
  _unlock(locknum: 7);
  if ( nochange == 0 )
  {
    v8 = tzname;
    if ( strncpy_s(_Dst: *tzname, _SizeInBytes: 0x40u, _Src: v1, _Count: 3u) != 0 )
      goto LABEL_12;
    v9 = v1 + 3;
    if ( *v9 == 45 )
    {
      negdiff = 1;
      ++v9;
    }
    timezone = 3600 * atol(nptr: v9);
    while ( 1 )
    {
      v10 = *v9;
      if ( *v9 != 43 && (v10 < 48 || v10 > 57) )
        break;
      ++v9;
    }
    if ( *v9 == 58 )
    {
      v11 = atol(nptr: ++v9);
      timezone += 60 * v11;
      while ( *v9 >= 48 && *v9 <= 57 )
        ++v9;
      if ( *v9 == 58 )
      {
        v12 = atol(nptr: ++v9);
        timezone += v12;
        while ( *v9 >= 48 && *v9 <= 57 )
          ++v9;
      }
    }
    if ( negdiff != 0 )
      timezone = -timezone;
    daylight = *v9;
    if ( daylight != 0 )
    {
      if ( strncpy_s(_Dst: v8[1], _SizeInBytes: 0x40u, _Src: v9, _Count: 3u) != 0 )
        goto LABEL_12;
    }
    else
    {
      *v8[1] = 0;
    }
    v13 = timezone;
    *__timezone() = v13;
    v14 = daylight;
    *__daylight() = v14;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0045E9CF
// Name: _isindst_nolock
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall isindst_nolock@<eax>(tm *tb@<edi>)
{
  int result; // eax
  int tm_year; // edx
  int v3; // eax
  int v4; // ecx
  int tm_yday; // edx
  int v6; // eax
  int endmonth; // [esp+4h] [ebp-Ch]
  int endweek; // [esp+8h] [ebp-8h]
  int daylight; // [esp+Ch] [ebp-4h] BYREF

  daylight = 0;
  result = _get_daylight(_Daylight: &daylight);
  if ( result != 0 )
    _invoke_watson(pszExpression: nullptr, pszFunction: nullptr, pszFile: nullptr, nLine: 0, pReserved: 0);
  if ( daylight != 0 )
  {
    tm_year = tb->tm_year;
    if ( tm_year != dststart.yr || tm_year != dstend.yr )
    {
      if ( tzapiused != 0 )
      {
        if ( tzinfo.DaylightDate.wYear != 0 )
          cvtdate(
            trantype: 1,
            datetype: 0,
            year: tm_year,
            month: tzinfo.DaylightDate.wMonth,
            week: 0,
            dayofweek: 0,
            date: tzinfo.DaylightDate.wDay,
            hour: tzinfo.DaylightDate.wHour,
            min: tzinfo.DaylightDate.wMinute,
            sec: tzinfo.DaylightDate.wSecond,
            msec: tzinfo.DaylightDate.wMilliseconds);
        else
          cvtdate(
            trantype: 1,
            datetype: 1,
            year: tm_year,
            month: tzinfo.DaylightDate.wMonth,
            week: tzinfo.DaylightDate.wDay,
            dayofweek: tzinfo.DaylightDate.wDayOfWeek,
            date: 0,
            hour: tzinfo.DaylightDate.wHour,
            min: tzinfo.DaylightDate.wMinute,
            sec: tzinfo.DaylightDate.wSecond,
            msec: tzinfo.DaylightDate.wMilliseconds);
        if ( tzinfo.StandardDate.wYear != 0 )
          cvtdate(
            trantype: 0,
            datetype: 0,
            year: tb->tm_year,
            month: tzinfo.StandardDate.wMonth,
            week: 0,
            dayofweek: 0,
            date: tzinfo.StandardDate.wDay,
            hour: tzinfo.StandardDate.wHour,
            min: tzinfo.StandardDate.wMinute,
            sec: tzinfo.StandardDate.wSecond,
            msec: tzinfo.StandardDate.wMilliseconds);
        else
          cvtdate(
            trantype: 0,
            datetype: 1,
            year: tb->tm_year,
            month: tzinfo.StandardDate.wMonth,
            week: tzinfo.StandardDate.wDay,
            dayofweek: tzinfo.StandardDate.wDayOfWeek,
            date: 0,
            hour: tzinfo.StandardDate.wHour,
            min: tzinfo.StandardDate.wMinute,
            sec: tzinfo.StandardDate.wSecond,
            msec: tzinfo.StandardDate.wMilliseconds);
      }
      else
      {
        v3 = 3;
        v4 = 2;
        endmonth = 11;
        endweek = 1;
        if ( tm_year < 107 )
        {
          v3 = 4;
          v4 = 1;
          endmonth = 10;
          endweek = 5;
        }
        cvtdate(
          trantype: 1,
          datetype: 1,
          year: tm_year,
          month: v3,
          week: v4,
          dayofweek: 0,
          date: 0,
          hour: 2,
          min: 0,
          sec: 0,
          msec: 0);
        cvtdate(
          trantype: 0,
          datetype: 1,
          year: tb->tm_year,
          month: endmonth,
          week: endweek,
          dayofweek: 0,
          date: 0,
          hour: 2,
          min: 0,
          sec: 0,
          msec: 0);
      }
    }
    tm_yday = tb->tm_yday;
    if ( dststart.yd >= dstend.yd )
    {
      if ( tm_yday < dstend.yd || tm_yday > dststart.yd )
        return 1;
      if ( tm_yday <= dstend.yd || tm_yday >= dststart.yd )
        goto LABEL_28;
    }
    else if ( tm_yday >= dststart.yd && tm_yday <= dstend.yd )
    {
      if ( tm_yday > dststart.yd && tm_yday < dstend.yd )
        return 1;
LABEL_28:
      v6 = 1000 * (tb->tm_sec + 60 * (tb->tm_min + 60 * tb->tm_hour));
      if ( tm_yday == dststart.yd )
        return v6 >= dststart.ms;
      else
        return v6 < dstend.ms;
    }
    return 0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0045EBA6
// Name: ___tzset
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __tzset()
{
  if ( first_time == 0 )
  {
    _lock(locknum: 6);
    if ( first_time == 0 )
    {
      tzset_nolock();
      ++first_time;
    }
    _unlock(locknum: 6);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0045EBF5
// Name: __tzset
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _tzset()
{
  _lock(locknum: 6);
  tzset_nolock();
  _unlock(locknum: 6);
}

//------------------------------------------------------------------------------
// Address: 0x0045EC2D
// Name: __isindst
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _isindst(tm *tb)
{
  int retval; // [esp+10h] [ebp-1Ch]

  _lock(locknum: 6);
  retval = isindst_nolock(tb);
  _unlock(locknum: 6);
  return retval;
}

//------------------------------------------------------------------------------
// Address: 0x0045EC6E
// Name: __initp_misc_invarg
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _initp_misc_invarg(void *enull)
{
  __pInvalidArgHandler = enull;
}

//------------------------------------------------------------------------------
// Address: 0x0045EC7D
// Name: __call_reportfault
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall _call_reportfault(
        unsigned int a1@<edi>,
        unsigned int a2@<esi>,
        __int128 a3@<xmm0>,
        unsigned int nDbgHookCode,
        unsigned int dwExceptionCode,
        unsigned int dwExceptionFlags)
{
  unsigned int v6; // ecx
  unsigned int v7; // edx
  unsigned int v8; // kr00_4
  BOOL v9; // edi
  _EXCEPTION_POINTERS ExceptionPointers; // [esp+8h] [ebp-328h] BYREF
  _EXCEPTION_RECORD ExceptionRecord; // [esp+10h] [ebp-320h] BYREF
  _CONTEXT ContextRecord; // [esp+60h] [ebp-2D0h] BYREF
  unsigned int savedregs; // [esp+330h] [ebp+0h]
  void *retaddr; // [esp+334h] [ebp+4h] BYREF

  if ( nDbgHookCode != -1 )
    _crt_debugger_hook();
  memset(a1: a3, dst: (int)&ExceptionRecord.ExceptionFlags, value: 0, count: 0x4Cu);
  ExceptionPointers.ExceptionRecord = &ExceptionRecord;
  ExceptionPointers.ContextRecord = &ContextRecord;
  ContextRecord.Eax = (unsigned int)&ContextRecord;
  ContextRecord.Ecx = v6;
  ContextRecord.Edx = v7;
  ContextRecord.Ebx = nDbgHookCode;
  ContextRecord.Esi = a2;
  ContextRecord.Edi = a1;
  LOWORD(ContextRecord.SegSs) = __SS__;
  LOWORD(ContextRecord.SegCs) = __CS__;
  LOWORD(ContextRecord.SegDs) = __DS__;
  LOWORD(ContextRecord.SegEs) = __ES__;
  LOWORD(ContextRecord.SegFs) = __FS__;
  LOWORD(ContextRecord.SegGs) = __GS__;
  v8 = __readeflags();
  ContextRecord.EFlags = v8;
  ContextRecord.Esp = (unsigned int)&retaddr;
  ContextRecord.ContextFlags = 65537;
  ContextRecord.Eip = (unsigned int)retaddr;
  ContextRecord.Ebp = savedregs;
  ExceptionRecord.ExceptionCode = dwExceptionCode;
  ExceptionRecord.ExceptionFlags = dwExceptionFlags;
  ExceptionRecord.ExceptionAddress = retaddr;
  v9 = IsDebuggerPresent();
  SetUnhandledExceptionFilter(lpTopLevelExceptionFilter: nullptr);
  if ( UnhandledExceptionFilter(ExceptionInfo: &ExceptionPointers) == 0 && !v9 && nDbgHookCode != -1 )
    _crt_debugger_hook();
}

//------------------------------------------------------------------------------
// Address: 0x0045EDA6
// Name: __set_invalid_parameter_handler
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void (__cdecl *__cdecl _set_invalid_parameter_handler(
        void (__cdecl *pNew)(const wchar_t *, const wchar_t *, const wchar_t *, unsigned int, unsigned int)))(const wchar_t *, const wchar_t *, const wchar_t *, unsigned int, unsigned int)
{
  PVOID v1; // esi

  v1 = DecodePointer(Ptr: __pInvalidArgHandler);
  __pInvalidArgHandler = EncodePointer(Ptr: pNew);
  return (void (__cdecl *)(const wchar_t *, const wchar_t *, const wchar_t *, unsigned int, unsigned int))v1;
}

//------------------------------------------------------------------------------
// Address: 0x0045EDCD
// Name: __invoke_watson
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall __noreturn _invoke_watson(unsigned int a1@<edi>, __int128 a2@<xmm0>)
{
  HANDLE CurrentProcess; // eax

  _call_reportfault(a1, a2: 0xC0000417, a3: a2, nDbgHookCode: 2u, dwExceptionCode: 0xC0000417, dwExceptionFlags: 1u);
  CurrentProcess = GetCurrentProcess();
  TerminateProcess(hProcess: CurrentProcess, uExitCode: 0xC0000417);
}

//------------------------------------------------------------------------------
// Address: 0x0045EDF2
// Name: __invalid_parameter
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall _invalid_parameter(unsigned int a1@<edi>, __int128 a2@<xmm0>)
{
  void (*v2)(void); // eax

  v2 = (void (*)(void))DecodePointer(Ptr: __pInvalidArgHandler);
  if ( v2 == nullptr )
    _invoke_watson(a1, a2);
  v2();
}

//------------------------------------------------------------------------------
// Address: 0x0045EE1F
// Name: __invalid_parameter_noinfo
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _invalid_parameter_noinfo()
{
  unsigned int v0; // edi
  __int128 v1; // xmm0

  _invalid_parameter(a1: v0, a2: v1);
}

//------------------------------------------------------------------------------
// Address: 0x0045EE2F
// Name: _strncmp
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl strncmp(const char *first, const char *last, unsigned int count)
{
  const char *v4; // ecx
  const char *v5; // eax
  char v6; // dl
  char v7; // dl
  char v8; // dl
  char v9; // dl
  int v10; // eax
  int v11; // ecx
  unsigned int i; // esi
  unsigned int n; // [esp+4h] [ebp-4h]

  n = 0;
  if ( count == 0 )
    return 0;
  if ( count <= 4 )
  {
    v4 = last;
    v5 = first;
LABEL_20:
    for ( i = n; ; ++i )
    {
      if ( i >= count )
        return 0;
      if ( *v5 == 0 || *v5 != *v4 )
        break;
      ++v5;
      ++v4;
    }
    v10 = *(unsigned __int8 *)v5;
    v11 = *(unsigned __int8 *)v4;
  }
  else
  {
    v4 = last;
    v5 = first;
    while ( 1 )
    {
      v6 = *v5;
      v5 += 4;
      v4 += 4;
      if ( v6 == 0 || v6 != *(v4 - 4) )
        break;
      v7 = *(v5 - 3);
      if ( v7 == 0 || v7 != *(v4 - 3) )
      {
        v10 = *((unsigned __int8 *)v5 - 3);
        v11 = *((unsigned __int8 *)v4 - 3);
        return v10 - v11;
      }
      v8 = *(v5 - 2);
      if ( v8 == 0 || v8 != *(v4 - 2) )
      {
        v10 = *((unsigned __int8 *)v5 - 2);
        v11 = *((unsigned __int8 *)v4 - 2);
        return v10 - v11;
      }
      v9 = *(v5 - 1);
      if ( v9 == 0 || v9 != *(v4 - 1) )
      {
        v10 = *((unsigned __int8 *)v5 - 1);
        v11 = *((unsigned __int8 *)v4 - 1);
        return v10 - v11;
      }
      n += 4;
      if ( n >= count - 4 )
        goto LABEL_20;
    }
    v10 = *((unsigned __int8 *)v5 - 4);
    v11 = *((unsigned __int8 *)v4 - 4);
  }
  return v10 - v11;
}

//------------------------------------------------------------------------------
// Address: 0x0045EEEF
// Name: _fgets
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char *__cdecl fgets(_iobuf *string, int count, _iobuf *str)
{
  char *v3; // edi
  int v5; // eax
  ioinfo *v6; // ecx
  ioinfo *v7; // eax
  int v9; // eax
  char *retval; // [esp+18h] [ebp-1Ch]

  v3 = (char *)string;
  retval = (char *)string;
  if ( string == nullptr && count != 0 || count < 0 || str == nullptr )
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return nullptr;
  }
  if ( count == 0 )
    return nullptr;
  _lock_file(pf: str);
  if ( (str->_flag & 0x40) == 0 )
  {
    v5 = fileno(stream: str);
    if ( v5 == -1 || v5 == -2 )
      v6 = &__badioinfo;
    else
      v6 = &__pioinfo[v5 >> 5][v5 & 0x1F];
    if ( (*((_BYTE *)v6 + 36) & 0x7F) != 0
      || (v5 == -1 || v5 == -2 ? (v7 = &__badioinfo) : (v7 = &__pioinfo[v5 >> 5][v5 & 0x1F]), *((char *)v7 + 36) < 0) )
    {
      *_errno() = 22;
      _invalid_parameter_noinfo();
      retval = nullptr;
    }
  }
  if ( retval != nullptr )
  {
    do
    {
      if ( --count == 0 )
        break;
      if ( --str->_cnt < 0 )
        v9 = _filbuf(str);
      else
        v9 = *(unsigned __int8 *)str->_ptr++;
      if ( v9 == -1 )
      {
        if ( v3 == (char *)string )
        {
          retval = nullptr;
          goto done;
        }
        break;
      }
      *v3++ = v9;
    }
    while ( (_BYTE)v9 != 10 );
    *v3 = 0;
  }
done:
  _unlock_file(pf: str);
  return retval;
}

//------------------------------------------------------------------------------
// Address: 0x0045F027
// Name: _fputs
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl fputs(char *string, _iobuf *stream)
{
  int v3; // eax
  ioinfo *v4; // ecx
  ioinfo *v5; // eax
  unsigned int v6; // eax
  int v7; // esi
  unsigned int ndone; // [esp+10h] [ebp-20h]
  unsigned int length; // [esp+14h] [ebp-1Ch]

  if ( string != nullptr
    && stream != nullptr
    && ((stream->_flag & 0x40) != 0
     || ((v3 = fileno(stream)) == -1 || v3 == -2 ? (v4 = &__badioinfo) : (v4 = &__pioinfo[v3 >> 5][v3 & 0x1F]),
         (*((_BYTE *)v4 + 36) & 0x7F) == 0
      && (v3 == -1 || v3 == -2 ? (v5 = &__badioinfo) : (v5 = &__pioinfo[v3 >> 5][v3 & 0x1F]), *((char *)v5 + 36) >= 0))) )
  {
    strlen(buf: string);
    length = v6;
    _lock_file(pf: stream);
    v7 = _stbuf(str: stream);
    ndone = _fwrite_nolock(buffer: string, size: 1u, num: length, stream);
    _ftbuf(flag: v7, str: stream);
    _unlock_file(pf: stream);
    return (ndone == length) - 1;
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return -1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0045F12D
// Name: _puts
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl puts(char *string)
{
  _iobuf *v2; // eax
  int v3; // eax
  ioinfo *v4; // ecx
  ioinfo *v5; // eax
  _iobuf *v6; // eax
  _iobuf *v7; // eax
  int v8; // edi
  unsigned int v9; // eax
  unsigned int v10; // esi
  _iobuf *v11; // eax
  _iobuf *v12; // eax
  _iobuf *v14; // eax
  _iobuf *v15; // eax
  _iobuf *v16; // eax
  _iobuf *v17; // eax
  int retval; // [esp+10h] [ebp-1Ch]

  retval = -1;
  if ( string != nullptr
    && (((v2 = __iob_func() + 1)->_flag & 0x40) != 0
     || ((v3 = fileno(stream: v2)) == -1 || v3 == -2 ? (v4 = &__badioinfo) : (v4 = &__pioinfo[v3 >> 5][v3 & 0x1F]),
         (*((_BYTE *)v4 + 36) & 0x7F) == 0
      && (v3 == -1 || v3 == -2 ? (v5 = &__badioinfo) : (v5 = &__pioinfo[v3 >> 5][v3 & 0x1F]), *((char *)v5 + 36) >= 0))) )
  {
    v6 = __iob_func();
    _lock_file2(i: 1, s: (char *)&v6[1]);
    v7 = __iob_func();
    v8 = _stbuf(str: v7 + 1);
    strlen(buf: string);
    v10 = v9;
    v11 = __iob_func();
    if ( _fwrite_nolock(buffer: string, size: 1u, num: v10, stream: v11 + 1) == v10 )
    {
      v12 = __iob_func();
      if ( --v12[1]._cnt < 0 )
      {
        v15 = __iob_func();
        _flsbuf(ch: 0xAu, str: (int)&v15[1]);
      }
      else
      {
        v14 = __iob_func();
        *v14[1]._ptr++ = 10;
      }
      retval = 0;
    }
    v16 = __iob_func();
    _ftbuf(flag: v8, str: v16 + 1);
    v17 = __iob_func();
    _unlock_file2(i: 1, s: (char *)&v17[1]);
    return retval;
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return -1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0045F27C
// Name: _fputc
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl fputc(unsigned __int8 ch, _iobuf *str)
{
  int v3; // eax
  ioinfo *v4; // ecx
  ioinfo *v5; // eax
  int v7; // eax
  int retval; // [esp+10h] [ebp-1Ch]

  retval = 0;
  if ( str != nullptr )
  {
    _lock_file(pf: str);
    if ( (str->_flag & 0x40) == 0 )
    {
      v3 = fileno(stream: str);
      if ( v3 == -1 || v3 == -2 )
        v4 = &__badioinfo;
      else
        v4 = &__pioinfo[v3 >> 5][v3 & 0x1F];
      if ( (*((_BYTE *)v4 + 36) & 0x7F) != 0
        || (v3 == -1 || v3 == -2 ? (v5 = &__badioinfo) : (v5 = &__pioinfo[v3 >> 5][v3 & 0x1F]), *((char *)v5 + 36) < 0) )
      {
        *_errno() = 22;
        _invalid_parameter_noinfo();
        retval = -1;
      }
    }
    if ( retval == 0 )
    {
      if ( --str->_cnt < 0 )
      {
        v7 = _flsbuf(ch, (int)str);
      }
      else
      {
        *str->_ptr = ch;
        v7 = ch;
        ++str->_ptr;
      }
      retval = v7;
    }
    _unlock_file(pf: str);
    return retval;
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return -1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0045F378
// Name: _printf
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int printf(const char *format, ...)
{
  _iobuf *v2; // eax
  _iobuf *v3; // eax
  int v4; // edi
  _iobuf *v5; // eax
  _iobuf *v6; // eax
  _iobuf *v7; // eax
  int retval; // [esp+10h] [ebp-1Ch]
  va_list argptr; // [esp+38h] [ebp+Ch] BYREF

  va_start(argptr, format);
  if ( format != nullptr )
  {
    v2 = __iob_func();
    _lock_file2(i: 1, s: (char *)&v2[1]);
    v3 = __iob_func();
    v4 = _stbuf(str: v3 + 1);
    v5 = __iob_func();
    retval = _output_l(stream: v5 + 1, format, plocinfo: nullptr, argptr);
    v6 = __iob_func();
    _ftbuf(flag: v4, str: v6 + 1);
    v7 = __iob_func();
    _unlock_file2(i: 1, s: (char *)&v7[1]);
    return retval;
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return -1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0045F41F
// Name: __get_printf_count_output
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL _get_printf_count_output()
{
  return _enable_percent_n == (__security_cookie | 1);
}

//------------------------------------------------------------------------------
// Address: 0x0045F435
// Name: __fread_nolock_s
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __usercall _fread_nolock_s@<eax>(
        __int128 a1@<xmm0>,
        unsigned __int8 *buffer,
        unsigned int bufferSize,
        unsigned int elementSize,
        unsigned int num,
        _iobuf *stream)
{
  unsigned int v7; // edi
  unsigned int v8; // ebx
  int cnt; // eax
  unsigned int v10; // edi
  unsigned int v11; // edx
  int v12; // eax
  unsigned int v13; // eax
  int v14; // eax
  int v15; // eax
  int v16; // eax
  unsigned __int8 *v17; // ecx
  unsigned int v18; // [esp-4h] [ebp-20h]
  unsigned int streambufsize; // [esp+10h] [ebp-Ch]
  unsigned __int8 *data; // [esp+14h] [ebp-8h]
  unsigned int dataSize; // [esp+18h] [ebp-4h]

  data = buffer;
  dataSize = bufferSize;
  if ( elementSize == 0 || num == 0 )
    return 0;
  if ( buffer != nullptr )
  {
    if ( stream != nullptr && num <= 0xFFFFFFFF / elementSize )
      goto LABEL_13;
    if ( bufferSize != -1 )
      memset(a1, dst: (int)buffer, value: 0, count: bufferSize);
    if ( stream != nullptr && num <= 0xFFFFFFFF / elementSize )
    {
LABEL_13:
      v7 = num * elementSize;
      v8 = num * elementSize;
      if ( (stream->_flag & 0x10C) != 0 )
        streambufsize = stream->_bufsiz;
      else
        streambufsize = 4096;
      if ( v7 == 0 )
        return num;
      while ( 1 )
      {
        if ( (stream->_flag & 0x10C) != 0 )
        {
          cnt = stream->_cnt;
          if ( cnt != 0 )
          {
            if ( cnt < 0 )
              goto LABEL_44;
            v10 = v8;
            if ( v8 >= cnt )
              v10 = stream->_cnt;
            if ( v10 > dataSize )
              goto LABEL_41;
            memcpy_s(dst: data, sizeInBytes: dataSize, src: (unsigned __int8 *)stream->_ptr, count: v10);
            stream->_cnt -= v10;
            stream->_ptr += v10;
            data += v10;
            v8 -= v10;
            dataSize -= v10;
            v7 = num * elementSize;
            goto LABEL_39;
          }
        }
        if ( v8 < streambufsize )
          break;
        if ( streambufsize != 0 )
        {
          if ( v8 <= 0x7FFFFFFF )
          {
            v11 = v8 % streambufsize;
            v12 = v8;
          }
          else
          {
            v11 = 0x7FFFFFFF % streambufsize;
            v12 = 0x7FFFFFFF;
          }
          v13 = v12 - v11;
        }
        else
        {
          v13 = 0x7FFFFFFF;
          if ( v8 <= 0x7FFFFFFF )
            v13 = v8;
        }
        if ( v13 > dataSize )
          goto LABEL_41;
        v18 = v13;
        v14 = fileno(stream);
        v15 = _read(fh: v14, buf: data, cnt: v18);
        if ( v15 == 0 )
        {
          stream->_flag |= 0x10u;
          return (v7 - v8) / elementSize;
        }
        if ( v15 == -1 )
        {
LABEL_44:
          stream->_flag |= 0x20u;
          return (v7 - v8) / elementSize;
        }
        data += v15;
        v8 -= v15;
        dataSize -= v15;
LABEL_39:
        if ( v8 == 0 )
          return num;
      }
      v16 = _filbuf(str: stream);
      if ( v16 == -1 )
        return (v7 - v8) / elementSize;
      if ( dataSize != 0 )
      {
        v17 = data++;
        *v17 = v16;
        --v8;
        --dataSize;
        streambufsize = stream->_bufsiz;
        goto LABEL_39;
      }
LABEL_41:
      if ( bufferSize != -1 )
        memset(a1, dst: (int)buffer, value: 0, count: bufferSize);
      *_errno() = 34;
LABEL_5:
      _invalid_parameter_noinfo();
      return 0;
    }
  }
  *_errno() = 22;
  goto LABEL_5;
}

//------------------------------------------------------------------------------
// Address: 0x0045F5F1
// Name: _fread_s
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __usercall fread_s@<eax>(
        __int128 a1@<xmm0>,
        unsigned __int8 *buffer,
        unsigned int bufferSize,
        unsigned int elementSize,
        unsigned int count,
        _iobuf *stream)
{
  unsigned int retval; // [esp+10h] [ebp-1Ch]

  if ( elementSize == 0 || count == 0 )
    return 0;
  if ( stream == nullptr )
  {
    if ( bufferSize != -1 )
      memset(a1, dst: (int)buffer, value: 0, count: bufferSize);
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return 0;
  }
  _lock_file(pf: stream);
  retval = _fread_nolock_s(a1, buffer, bufferSize, elementSize, num: count, stream);
  _unlock_file(pf: stream);
  return retval;
}

//------------------------------------------------------------------------------
// Address: 0x0045F67F
// Name: _fread
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __usercall fread@<eax>(
        __int128 a1@<xmm0>,
        unsigned __int8 *buffer,
        unsigned int elementSize,
        unsigned int count,
        _iobuf *stream)
{
  return fread_s(a1, buffer, bufferSize: 0xFFFFFFFF, elementSize, count, stream);
}

//------------------------------------------------------------------------------
// Address: 0x0045F69C
// Name: _rewind
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl rewind(_iobuf *str)
{
  int v1; // edi
  ioinfo *v2; // eax
  int flag; // eax

  if ( str != nullptr )
  {
    v1 = fileno(stream: str);
    _lock_file(pf: str);
    _flush(str);
    str->_flag &= 0xFFFFFFCF;
    if ( v1 == -1 || v1 == -2 )
      v2 = &__badioinfo;
    else
      v2 = &__pioinfo[v1 >> 5][v1 & 0x1F];
    v2->osfile &= ~2u;
    flag = str->_flag;
    if ( (flag & 0x80u) != 0 )
      str->_flag = flag & 0xFFFFFFFC;
    if ( _lseek(fh: v1, pos: 0, mthd: 0) == -1 )
      str->_flag |= 0x20u;
    _unlock_file(pf: str);
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
  }
}

//------------------------------------------------------------------------------
// Address: 0x0045F75A
// Name: __ftell_nolock
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _ftell_nolock(_iobuf *str)
{
  int v3; // eax
  int v4; // esi
  signed int v5; // eax
  int flag; // edx
  char *ptr; // eax
  char *base; // ecx
  char *v9; // ebx
  char *v10; // edx
  int cnt; // edx
  ioinfo **v12; // ebx
  int v13; // esi
  char *v14; // eax
  char *v15; // ecx
  bool v16; // zf
  int bufsiz; // eax
  int v18; // ecx
  unsigned int offset; // [esp+8h] [ebp-Ch]
  int fd; // [esp+Ch] [ebp-8h]
  LONG filepos; // [esp+10h] [ebp-4h]
  unsigned int rdcnt; // [esp+1Ch] [ebp+8h]

  if ( str == nullptr )
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return -1;
  }
  v3 = fileno(stream: str);
  v4 = v3;
  fd = v3;
  if ( str->_cnt < 0 )
    str->_cnt = 0;
  v5 = _lseek(fh: v3, pos: 0, mthd: 1u);
  filepos = v5;
  if ( v5 < 0 )
    return -1;
  flag = str->_flag;
  if ( (flag & 0x108) == 0 )
    return v5 - str->_cnt;
  ptr = str->_ptr;
  base = str->_base;
  v9 = (char *)(str->_ptr - base);
  offset = (unsigned int)v9;
  if ( (flag & 3) != 0 )
  {
    if ( __pioinfo[v4 >> 5][v4 & 0x1F].osfile < 0 )
    {
      v10 = str->_base;
      if ( base < ptr )
      {
        do
        {
          if ( *v10 == 10 )
            ++v9;
          ++v10;
        }
        while ( v10 < ptr );
        offset = (unsigned int)v9;
      }
    }
  }
  else if ( (flag & 0x80u) == 0 )
  {
    *_errno() = 22;
    return -1;
  }
  if ( filepos == 0 )
    return (int)v9;
  if ( (str->_flag & 1) == 0 )
    return filepos + offset;
  cnt = str->_cnt;
  if ( cnt != 0 )
  {
    v12 = &__pioinfo[fd >> 5];
    rdcnt = cnt + ptr - base;
    v13 = (fd & 0x1F) << 6;
    if ( *(&(*v12)->osfile + v13) >= 0 )
    {
LABEL_39:
      filepos -= rdcnt;
      return filepos + offset;
    }
    if ( _lseek(fh: fd, pos: 0, mthd: 2u) == filepos )
    {
      v14 = str->_base;
      v15 = &v14[rdcnt];
      while ( v14 < v15 )
      {
        if ( *v14 == 10 )
          ++rdcnt;
        ++v14;
      }
      v16 = (str->_flag & 0x2000) == 0;
LABEL_37:
      if ( !v16 )
        ++rdcnt;
      goto LABEL_39;
    }
    if ( (_lseek(fh: fd, pos: filepos, mthd: 0) & 0x80000000) == 0 )
    {
      bufsiz = 512;
      if ( rdcnt > 0x200 || ((v18 = str->_flag) & 8) == 0 || (v18 & 0x400) != 0 )
        bufsiz = str->_bufsiz;
      rdcnt = bufsiz;
      v16 = (*(&(*v12)->osfile + v13) & 4) == 0;
      goto LABEL_37;
    }
    return -1;
  }
  offset = 0;
  return filepos + offset;
}

//------------------------------------------------------------------------------
// Address: 0x0045F8EE
// Name: _ftell
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl ftell(_iobuf *stream)
{
  int retval; // [esp+10h] [ebp-1Ch]

  if ( stream != nullptr )
  {
    _lock_file(pf: stream);
    retval = _ftell_nolock(str: stream);
    _unlock_file(pf: stream);
    return retval;
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return -1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0045F953
// Name: __fseek_nolock
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _fseek_nolock(_iobuf *str, LONG offset, DWORD whence)
{
  int flag; // eax
  int v5; // eax
  int v6; // eax

  flag = str->_flag;
  if ( (flag & 0x83) != 0 )
  {
    str->_flag = flag & 0xFFFFFFEF;
    if ( whence == 1 )
    {
      offset += _ftell_nolock(str);
      whence = 0;
    }
    _flush(str);
    v5 = str->_flag;
    if ( (v5 & 0x80u) == 0 )
    {
      if ( (v5 & 1) != 0 && (v5 & 8) != 0 && (v5 & 0x400) == 0 )
        str->_bufsiz = 512;
    }
    else
    {
      str->_flag = v5 & 0xFFFFFFFC;
    }
    v6 = fileno(stream: str);
    return (_lseek(fh: v6, pos: offset, mthd: whence) != -1) - 1;
  }
  else
  {
    *_errno() = 22;
    return -1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0045F9DD
// Name: _fseek
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl fseek(_iobuf *stream, LONG offset, DWORD whence)
{
  int retval; // [esp+10h] [ebp-1Ch]

  if ( stream != nullptr && whence <= 2 )
  {
    _lock_file(pf: stream);
    retval = _fseek_nolock(str: stream, offset, whence);
    _unlock_file(pf: stream);
    return retval;
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return -1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0045FA59
// Name: _feof
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl feof(_iobuf *stream)
{
  if ( stream != nullptr )
    return stream->_flag & 0x10;
  *_errno() = 22;
  _invalid_parameter_noinfo();
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x0045FA90
// Name: _strncat
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char *__cdecl strncat(char *Destination, const char *Source, size_t Count)
{
  size_t v3; // ecx
  char *v4; // edi
  char v5; // al
  int v6; // eax
  int v7; // eax
  char *v8; // edi
  const char *v9; // esi
  char v10; // bl
  size_t v11; // ecx
  int v12; // edx
  char v13; // dl
  int v15; // eax

  v3 = Count;
  if ( Count == 0 )
    return Destination;
  v4 = Destination;
  if ( ((unsigned __int8)Destination & 3) == 0 )
    goto find_end_of_front_string_loop;
  do
  {
    v5 = *v4++;
    if ( v5 == 0 )
    {
start_byte_3:
      v8 = v4 - 1;
      goto copy_start;
    }
  }
  while ( ((unsigned __int8)v4 & 3) != 0 );
  while ( 1 )
  {
    do
    {
find_end_of_front_string_loop:
      v6 = (*(_DWORD *)v4 + 2130640639) ^ ~*(_DWORD *)v4;
      v4 += 4;
    }
    while ( (v6 & 0x81010100) == 0 );
    v7 = *((_DWORD *)v4 - 1);
    if ( (_BYTE)v7 == 0 )
      break;
    if ( BYTE1(v7) == 0 )
    {
      v8 = v4 - 3;
      goto copy_start;
    }
    if ( (v7 & 0xFF0000) == 0 )
    {
      v8 = v4 - 2;
      goto copy_start;
    }
    if ( (v7 & 0xFF000000) == 0 )
      goto start_byte_3;
  }
  v8 = v4 - 4;
copy_start:
  v9 = Source;
  if ( ((unsigned __int8)Source & 3) == 0 )
  {
    v10 = Count;
    v11 = Count >> 2;
    if ( Count >> 2 != 0 )
      goto main_loop_entrance_0;
tail_loop_start_0:
    v3 = v10 & 3;
    if ( (v10 & 3) != 0 )
    {
      while ( 1 )
      {
        v13 = *v9++;
        *v8++ = v13;
        if ( v13 == 0 )
          break;
        if ( --v3 == 0 )
          goto empty_counter;
      }
    }
    else
    {
empty_counter:
      *v8 = v3;
    }
    return Destination;
  }
  do
  {
    LOBYTE(v12) = *v9++;
    if ( (_BYTE)v12 == 0 )
    {
LABEL_26:
      *v8 = v12;
      return Destination;
    }
    *v8++ = v12;
    if ( --v3 == 0 )
      goto empty_counter;
  }
  while ( ((unsigned __int8)v9 & 3) != 0 );
  v10 = v3;
  v11 = v3 >> 2;
  if ( v11 == 0 )
    goto tail_loop_start_0;
  while ( 1 )
  {
main_loop_entrance_0:
    v15 = (*(_DWORD *)v9 + 2130640639) ^ ~*(_DWORD *)v9;
    v12 = *(_DWORD *)v9;
    v9 += 4;
    if ( (v15 & 0x81010100) != 0 )
    {
      if ( (_BYTE)v12 == 0 )
        goto LABEL_26;
      if ( BYTE1(v12) == 0 )
        break;
      if ( (v12 & 0xFF0000) == 0 )
      {
        *(_WORD *)v8 = v12;
        v8[2] = 0;
        return Destination;
      }
      if ( (v12 & 0xFF000000) == 0 )
      {
        *(_DWORD *)v8 = v12;
        return Destination;
      }
    }
    *(_DWORD *)v8 = v12;
    v8 += 4;
    if ( --v11 == 0 )
      goto tail_loop_start_0;
  }
  *(_WORD *)v8 = (unsigned __int8)v12;
  return Destination;
}

//------------------------------------------------------------------------------
// Address: 0x0045FBC5
// Name: __flush
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _flush(_iobuf *str)
{
  int flag; // eax
  int v2; // ebx
  char *base; // eax
  char *v4; // edi
  int v5; // eax
  int v6; // eax
  char *v7; // eax
  char *v9; // [esp-Ch] [ebp-14h]
  char *v10; // [esp-8h] [ebp-10h]

  flag = str->_flag;
  v2 = 0;
  if ( (flag & 3) == 2 && (flag & 0x108) != 0 )
  {
    base = str->_base;
    v4 = (char *)(str->_ptr - base);
    if ( (int)v4 > 0 )
    {
      v10 = (char *)(str->_ptr - base);
      v9 = str->_base;
      v5 = fileno(stream: str);
      if ( (char *)_write(fh: v5, buf: v9, cnt: (unsigned int)v10) == v4 )
      {
        v6 = str->_flag;
        if ( (v6 & 0x80u) != 0 )
          str->_flag = v6 & 0xFFFFFFFD;
      }
      else
      {
        str->_flag |= 0x20u;
        v2 = -1;
      }
    }
  }
  v7 = str->_base;
  str->_cnt = 0;
  str->_ptr = v7;
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x0045FC2D
// Name: __fflush_nolock
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _fflush_nolock(_iobuf *str)
{
  int v2; // eax

  if ( str == nullptr )
    return flsall(flushflag: 0);
  if ( _flush(str) != 0 )
    return -1;
  if ( (str->_flag & 0x4000) == 0 )
    return 0;
  v2 = fileno(stream: str);
  return -(_commit(filedes: v2) != 0);
}

//------------------------------------------------------------------------------
// Address: 0x0045FC75
// Name: flsall
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl flsall(int flushflag)
{
  int i; // esi
  char **v2; // eax
  char *v3; // eax
  int v4; // ecx
  int result; // eax
  int err; // [esp+10h] [ebp-24h]
  int count; // [esp+18h] [ebp-1Ch]

  count = 0;
  err = 0;
  _lock(locknum: 1);
  for ( i = 0; i < (int)_nstream; ++i )
  {
    v2 = (char **)&__piob[i];
    if ( *v2 != nullptr )
    {
      v3 = *v2;
      if ( (v3[12] & 0x83) != 0 )
      {
        _lock_file2(i, s: v3);
        v4 = *((_DWORD *)__piob[i] + 3);
        if ( (v4 & 0x83) != 0 )
        {
          if ( flushflag == 1 )
          {
            if ( _fflush_nolock(str: (_iobuf *)__piob[i]) != -1 )
              ++count;
          }
          else if ( flushflag == 0 && (v4 & 2) != 0 && _fflush_nolock(str: (_iobuf *)__piob[i]) == -1 )
          {
            err = -1;
          }
        }
        _unlock_file2(i, s: (char *)__piob[i]);
      }
    }
  }
  _unlock(locknum: 1);
  result = count;
  if ( flushflag != 1 )
    return err;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0045FD4F
// Name: _fflush
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl fflush(_iobuf *stream)
{
  int rc; // [esp+10h] [ebp-1Ch]

  if ( stream == nullptr )
    return flsall(flushflag: 0);
  _lock_file(pf: stream);
  rc = _fflush_nolock(str: stream);
  _unlock_file(pf: stream);
  return rc;
}

//------------------------------------------------------------------------------
// Address: 0x0045FDA2
// Name: __flushall
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _flushall()
{
  return flsall(flushflag: 1);
}

//------------------------------------------------------------------------------
// Address: 0x0045FDAB
// Name: __gmtime64_s
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall _gmtime64_s@<eax>(__int128 a1@<xmm0>, tm *ptm, const __int64 *timp)
{
  unsigned int v5; // ecx
  unsigned int v6; // eax
  __int64 v7; // rax
  __int64 v8; // rax
  unsigned int v9; // edi
  int v10; // eax
  int v11; // et0
  int v12; // et0
  unsigned int v13; // edi
  unsigned int v14; // et0
  int *v15; // edx
  int tm_yday; // eax
  int i; // ecx
  int v18; // ecx
  signed __int64 v19; // kr28_8
  __int64 caltim; // [esp+4h] [ebp-10h]
  unsigned int caltim_4; // [esp+8h] [ebp-Ch]
  int v22; // [esp+Ch] [ebp-8h]
  int islpyr; // [esp+10h] [ebp-4h]
  int tmptim; // [esp+1Ch] [ebp+8h]

  islpyr = 0;
  if ( ptm == nullptr || (memset(a1, dst: (int)ptm, value: 0xFFu, count: 0x24u), timp == nullptr) )
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return 22;
  }
  v5 = *(_DWORD *)timp;
  v6 = *((_DWORD *)timp + 1);
  LODWORD(caltim) = *(_DWORD *)timp;
  if ( *timp < -43200 || __SPAIR64__(v6, v5) > 0x7934126CFLL )
  {
    *_errno() = 22;
    return 22;
  }
  v7 = __SPAIR64__(v6, v5) / 31536000;
  v22 = v7 + 69;
  tmptim = v7 + 70;
  v8 = 86400 * (-365LL * (int)v7 - (((int)v7 + 369) / 400 - ((int)v7 + 69) / 100 + ((int)v7 + 69) / 4 - 17));
  HIDWORD(caltim) = *((_DWORD *)timp + 1);
  v9 = v8 + caltim;
  HIDWORD(caltim) = (unsigned __int64)(v8 + caltim) >> 32;
  if ( caltim >= 0 )
  {
    if ( (tmptim % 4 != 0 || tmptim % 100 == 0) && (tmptim + 1900) % 400 != 0 )
      goto LABEL_18;
    goto LABEL_17;
  }
  v10 = v22;
  v11 = (__PAIR64__(HIDWORD(caltim), v9) + 31536000) >> 32;
  v9 += 31536000;
  HIDWORD(caltim) = v11;
  tmptim = v22;
  if ( v22 % 4 == 0 )
  {
    if ( v22 % 100 != 0 )
    {
LABEL_13:
      v12 = (__PAIR64__(HIDWORD(caltim), v9) + 86400) >> 32;
      v9 += 86400;
      HIDWORD(caltim) = v12;
LABEL_17:
      islpyr = 1;
      goto LABEL_18;
    }
    v10 = v22;
  }
  if ( (v10 + 1900) % 400 == 0 )
    goto LABEL_13;
LABEL_18:
  ptm->tm_year = tmptim;
  ptm->tm_yday = __SPAIR64__(HIDWORD(caltim), v9) / 86400;
  v14 = (-86400LL * (int)(__SPAIR64__(HIDWORD(caltim), v9) / 86400) + __PAIR64__(HIDWORD(caltim), v9)) >> 32;
  v13 = __SPAIR64__(HIDWORD(caltim), v9) % 86400;
  caltim_4 = v14;
  v15 = _lpdays;
  if ( islpyr == 0 )
    v15 = _days;
  tm_yday = ptm->tm_yday;
  for ( i = 1; v15[i] < tm_yday; ++i )
    ;
  v18 = i - 1;
  ptm->tm_mon = v18;
  ptm->tm_mday = tm_yday - v15[v18];
  ptm->tm_wday = (int)(*timp / 86400 + 4) % 7;
  ptm->tm_hour = __SPAIR64__(caltim_4, v13) / 3600;
  v19 = -3600LL * (int)(__SPAIR64__(caltim_4, v13) / 3600) + __PAIR64__(caltim_4, v13);
  ptm->tm_min = v19 / 60;
  ptm->tm_sec = v19 % 60;
  ptm->tm_isdst = 0;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x0045FFE4
// Name: __gmtime64
// Source: linker_block_proximity
//------------------------------------------------------------------------------
tm *__usercall _gmtime64@<eax>(__int128 a1@<xmm0>, const __int64 *timp)
{
  tm *result; // eax

  result = (tm *)__getgmtimebuf();
  if ( result != nullptr )
    return _gmtime64_s(a1, ptm: result, timp) == 0 ? result : nullptr;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0046000B
// Name: __umask_s
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _umask_s(int mode, int *poldmode)
{
  if ( poldmode == nullptr || (*poldmode = _umaskval, (mode & 0xFFFFFE7F) != 0) )
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return 22;
  }
  else
  {
    _umaskval = mode & 0x180;
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0046004C
// Name: __umask
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _umask(__int16 mode)
{
  int oldmode; // [esp+0h] [ebp-4h] BYREF

  oldmode = 0;
  _umask_s(mode: mode & 0x180, poldmode: &oldmode);
  return oldmode;
}

//------------------------------------------------------------------------------
// Address: 0x0046006F
// Name: __set_osfhnd
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _set_osfhnd(int fh, void *value)
{
  ioinfo **v2; // edi
  int v3; // esi

  if ( fh >= 0
    && fh < _nhandle
    && (v2 = &__pioinfo[fh >> 5], *(int *)((char *)&(*v2)->osfhnd + (v3 = (fh & 0x1F) << 6)) == -1) )
  {
    if ( __app_type == 1 )
    {
      if ( fh != 0 )
      {
        if ( fh == 1 )
        {
          SetStdHandle(nStdHandle: 0xFFFFFFF5, hHandle: value);
        }
        else if ( fh == 2 )
        {
          SetStdHandle(nStdHandle: 0xFFFFFFF4, hHandle: value);
        }
      }
      else
      {
        SetStdHandle(nStdHandle: 0xFFFFFFF6, hHandle: value);
      }
    }
    *(int *)((char *)&(*v2)->osfhnd + v3) = (int)value;
    return 0;
  }
  else
  {
    *_errno() = 9;
    *__doserrno() = 0;
    return -1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004600F0
// Name: __free_osfhnd
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _free_osfhnd(int fh)
{
  ioinfo **v1; // edi
  int v2; // esi

  if ( fh < 0
    || fh >= _nhandle
    || (v1 = &__pioinfo[fh >> 5], v2 = (fh & 0x1F) << 6, (*(&(*v1)->osfile + v2) & 1) == 0)
    || (*v1)[fh & 0x1F].osfhnd == -1 )
  {
    *_errno() = 9;
    *__doserrno() = 0;
    return -1;
  }
  else
  {
    if ( __app_type == 1 )
    {
      if ( fh != 0 )
      {
        if ( fh == 1 )
        {
          SetStdHandle(nStdHandle: 0xFFFFFFF5, hHandle: nullptr);
        }
        else if ( fh == 2 )
        {
          SetStdHandle(nStdHandle: 0xFFFFFFF4, hHandle: nullptr);
        }
      }
      else
      {
        SetStdHandle(nStdHandle: 0xFFFFFFF6, hHandle: nullptr);
      }
    }
    *(int *)((char *)&(*v1)->osfhnd + v2) = -1;
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00460176
// Name: __get_osfhandle
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _get_osfhandle(int fh)
{
  ioinfo *v2; // ecx
  int v3; // eax

  if ( fh == -2 )
  {
    *__doserrno() = 0;
    *_errno() = 9;
    return -1;
  }
  if ( fh < 0 || fh >= _nhandle || (v2 = __pioinfo[fh >> 5], (*(&v2->osfile + (v3 = (fh & 0x1F) << 6)) & 1) == 0) )
  {
    *__doserrno() = 0;
    *_errno() = 9;
    _invalid_parameter_noinfo();
    return -1;
  }
  return *(int *)((char *)&v2->osfhnd + v3);
}

//------------------------------------------------------------------------------
// Address: 0x004601DF
// Name: ___lock_fhandle
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __cdecl __lock_fhandle(int fh)
{
  ioinfo *v1; // esi
  BOOL retval; // [esp+10h] [ebp-1Ch]

  v1 = &__pioinfo[fh >> 5][fh & 0x1F];
  retval = true;
  if ( v1->lockinitflag == 0 )
  {
    _lock(locknum: 10);
    if ( v1->lockinitflag == 0 )
    {
      retval = InitializeCriticalSectionAndSpinCount(lpCriticalSection: &v1->lock, dwSpinCount: 0xFA0u);
      ++v1->lockinitflag;
    }
    _unlock(locknum: 10);
  }
  if ( retval )
    EnterCriticalSection(lpCriticalSection: &__pioinfo[fh >> 5][fh & 0x1F].lock);
  return retval;
}

//------------------------------------------------------------------------------
// Address: 0x0046027E
// Name: __unlock_fhandle
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _unlock_fhandle(int fh)
{
  LeaveCriticalSection(lpCriticalSection: &__pioinfo[fh >> 5][fh & 0x1F].lock);
}

//------------------------------------------------------------------------------
// Address: 0x004602A5
// Name: __alloc_osfhnd
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _alloc_osfhnd()
{
  int v0; // edi
  ioinfo *v2; // esi
  unsigned __int8 *v3; // eax
  ioinfo **v4; // ecx
  int failed; // [esp+14h] [ebp-24h]
  int fh; // [esp+1Ch] [ebp-1Ch]

  fh = -1;
  v0 = 0;
  failed = 0;
  if ( _mtinitlocknum(locknum: 11) == 0 )
    return -1;
  _lock(locknum: 11);
  while ( v0 < 64 )
  {
    v2 = __pioinfo[v0];
    if ( v2 == nullptr )
    {
      v3 = calloc(count: 0x20u, size: 0x40u);
      if ( v3 != nullptr )
      {
        v4 = &__pioinfo[v0];
        *v4 = (ioinfo *)v3;
        _nhandle += 32;
        while ( v3 < (unsigned __int8 *)&(*v4)[32] )
        {
          v3[4] = 0;
          *(_DWORD *)v3 = -1;
          v3[5] = 10;
          *((_DWORD *)v3 + 2) = 0;
          v3 += 64;
        }
        fh = 32 * v0;
        __pioinfo[(32 * v0) >> 5]->osfile = 1;
        if ( !__lock_fhandle(fh: 32 * v0) )
          fh = -1;
      }
      break;
    }
    while ( v2 < &__pioinfo[v0][32] )
    {
      if ( (v2->osfile & 1) == 0 )
      {
        if ( v2->lockinitflag == 0 )
        {
          _lock(locknum: 10);
          if ( v2->lockinitflag == 0 )
          {
            if ( InitializeCriticalSectionAndSpinCount(lpCriticalSection: &v2->lock, dwSpinCount: 0xFA0u) )
              ++v2->lockinitflag;
            else
              failed = 1;
          }
          _unlock(locknum: 10);
        }
        if ( failed == 0 )
        {
          EnterCriticalSection(lpCriticalSection: &v2->lock);
          if ( (v2->osfile & 1) == 0 )
          {
            v2->osfile = 1;
            v2->osfhnd = -1;
            fh = 32 * v0 + v2 - __pioinfo[v0];
            break;
          }
          LeaveCriticalSection(lpCriticalSection: &v2->lock);
        }
      }
      ++v2;
    }
    if ( fh != -1 )
      break;
    ++v0;
  }
  _unlock(locknum: 11);
  return fh;
}

//------------------------------------------------------------------------------
// Address: 0x0046043E
// Name: __close_nolock
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _close_nolock(int fh)
{
  int osfhandle; // edi
  void *v2; // eax
  DWORD LastError; // edi

  if ( _get_osfhandle(fh) == -1
    || (fh == 1 && (__pioinfo[0][2].osfile & 1) != 0 || fh == 2 && (__pioinfo[0][1].osfile & 1) != 0)
    && (osfhandle = _get_osfhandle(fh: 2), _get_osfhandle(fh: 1) == osfhandle)
    || (v2 = (void *)_get_osfhandle(fh), CloseHandle(hObject: v2)) )
  {
    LastError = 0;
  }
  else
  {
    LastError = GetLastError();
  }
  _free_osfhnd(fh);
  __pioinfo[fh >> 5][fh & 0x1F].osfile = 0;
  if ( LastError == 0 )
    return 0;
  _dosmaperr(oserrno: LastError);
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004604DA
// Name: __close
// Source: linker_block_proximity
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
// Address: 0x0046059E
// Name: __fstat64
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall _fstat64@<eax>(__int128 a1@<xmm0>, int fildes, _stat64 *buf)
{
  int v4; // edi
  DWORD v5; // eax
  DWORD LastError; // eax
  unsigned __int16 v7; // cx
  unsigned int v8; // ecx
  unsigned __int16 st_mode; // ax
  unsigned __int16 v10; // ax
  int v11; // edx
  int v12; // edx
  int v13; // edx
  _FILETIME LocalFTime; // [esp+14h] [ebp-74h] BYREF
  int fildesa; // [esp+1Ch] [ebp-6Ch]
  unsigned int ulAvail; // [esp+20h] [ebp-68h] BYREF
  int retval; // [esp+24h] [ebp-64h]
  _BY_HANDLE_FILE_INFORMATION bhfi; // [esp+28h] [ebp-60h] BYREF
  _SYSTEMTIME SystemTime; // [esp+5Ch] [ebp-2Ch] BYREF
  CPPEH_RECORD ms_exc; // [esp+70h] [ebp-18h]

  fildesa = fildes;
  retval = 0;
  if ( buf == nullptr )
  {
    *__doserrno() = 0;
    *_errno() = 22;
LABEL_3:
    _invalid_parameter_noinfo();
    return -1;
  }
  memset(a1, dst: (int)buf, value: 0, count: 0x38u);
  if ( fildes == -2 )
  {
    *__doserrno() = 0;
    *_errno() = 9;
    return -1;
  }
  if ( fildes < 0
    || fildes >= _nhandle
    || (ulAvail = (unsigned int)&__pioinfo[fildes >> 5],
        v4 = (fildes & 0x1F) << 6,
        (*(_BYTE *)(*(_DWORD *)ulAvail + v4 + 4) & 1) == 0) )
  {
    *__doserrno() = 0;
    *_errno() = 9;
    goto LABEL_3;
  }
  __lock_fhandle(fh: fildesa);
  ms_exc.registration.TryLevel = 0;
  if ( (*(_BYTE *)(*(_DWORD *)ulAvail + v4 + 4) & 1) == 0 )
    goto LABEL_12;
  v5 = GetFileType(hFile: *(HANDLE *)(*(_DWORD *)ulAvail + ((fildes & 0x1F) << 6))) & 0xFFFF7FFF;
  switch ( v5 )
  {
    case 1u:
      buf->st_mode = 0;
      buf->st_gid = 0;
      buf->st_uid = 0;
      buf->st_ino = 0;
      buf->st_nlink = 1;
      if ( GetFileInformationByHandle(
             hFile: *(HANDLE *)(*(_DWORD *)ulAvail + ((fildes & 0x1F) << 6)),
             lpFileInformation: &bhfi) )
      {
        st_mode = buf->st_mode;
        if ( (bhfi.dwFileAttributes & 1) != 0 )
          v10 = st_mode | 0x124;
        else
          v10 = st_mode | 0x1B6;
        buf->st_mode = v10;
        if ( bhfi.ftLastWriteTime.dwLowDateTime != 0 || bhfi.ftLastWriteTime.dwHighDateTime != 0 )
        {
          if ( !FileTimeToLocalFileTime(lpFileTime: &bhfi.ftLastWriteTime, lpLocalFileTime: &LocalFTime)
            || !FileTimeToSystemTime(lpFileTime: &LocalFTime, lpSystemTime: &SystemTime) )
          {
            goto LABEL_13;
          }
          LODWORD(buf->st_mtime) = __loctotime64_t(
                                     yr: SystemTime.wYear,
                                     mo: SystemTime.wMonth,
                                     dy: SystemTime.wDay,
                                     hr: SystemTime.wHour,
                                     mn: SystemTime.wMinute,
                                     sc: SystemTime.wSecond,
                                     dstflag: -1);
          HIDWORD(buf->st_mtime) = v11;
        }
        else
        {
          buf->st_mtime = 0;
        }
        if ( bhfi.ftLastAccessTime.dwLowDateTime != 0 || bhfi.ftLastAccessTime.dwHighDateTime != 0 )
        {
          if ( !FileTimeToLocalFileTime(lpFileTime: &bhfi.ftLastAccessTime, lpLocalFileTime: &LocalFTime)
            || !FileTimeToSystemTime(lpFileTime: &LocalFTime, lpSystemTime: &SystemTime) )
          {
            goto LABEL_13;
          }
          LODWORD(buf->st_atime) = __loctotime64_t(
                                     yr: SystemTime.wYear,
                                     mo: SystemTime.wMonth,
                                     dy: SystemTime.wDay,
                                     hr: SystemTime.wHour,
                                     mn: SystemTime.wMinute,
                                     sc: SystemTime.wSecond,
                                     dstflag: -1);
          HIDWORD(buf->st_atime) = v12;
        }
        else
        {
          buf->st_atime = buf->st_mtime;
        }
        if ( bhfi.ftCreationTime.dwLowDateTime != 0 || bhfi.ftCreationTime.dwHighDateTime != 0 )
        {
          if ( !FileTimeToLocalFileTime(lpFileTime: &bhfi.ftCreationTime, lpLocalFileTime: &LocalFTime)
            || !FileTimeToSystemTime(lpFileTime: &LocalFTime, lpSystemTime: &SystemTime) )
          {
            goto LABEL_13;
          }
          LODWORD(buf->st_ctime) = __loctotime64_t(
                                     yr: SystemTime.wYear,
                                     mo: SystemTime.wMonth,
                                     dy: SystemTime.wDay,
                                     hr: SystemTime.wHour,
                                     mn: SystemTime.wMinute,
                                     sc: SystemTime.wSecond,
                                     dstflag: -1);
          HIDWORD(buf->st_ctime) = v13;
        }
        else
        {
          buf->st_ctime = buf->st_mtime;
        }
        buf->st_size = bhfi.nFileSizeLow + __PAIR64__(bhfi.nFileSizeHigh, 0);
        buf->st_mode |= 0x8000u;
        buf->st_dev = 0;
        buf->st_rdev = 0;
        goto done_0;
      }
      goto LABEL_19;
    case 2u:
      v7 = 0x2000;
      goto LABEL_22;
    case 3u:
      v7 = 4096;
LABEL_22:
      buf->st_mode = v7;
      v8 = fildesa;
      buf->st_dev = fildesa;
      buf->st_rdev = v8;
      buf->st_nlink = 1;
      buf->st_ino = 0;
      buf->st_gid = 0;
      buf->st_uid = 0;
      buf->st_ctime = 0;
      buf->st_mtime = 0;
      buf->st_atime = 0;
      if ( v5 == 2
        || !PeekNamedPipe(
              hNamedPipe: *(HANDLE *)(*(_DWORD *)ulAvail + ((fildes & 0x1F) << 6)),
              lpBuffer: nullptr,
              nBufferSize: 0,
              lpBytesRead: nullptr,
              lpTotalBytesAvail: &ulAvail,
              lpBytesLeftThisMessage: nullptr) )
      {
        buf->st_size = 0;
      }
      else
      {
        buf->st_size = (int)ulAvail;
      }
      goto done_0;
    default:
      break;
  }
  if ( v5 != 0 )
  {
LABEL_19:
    LastError = GetLastError();
    _dosmaperr(oserrno: LastError);
    goto LABEL_13;
  }
LABEL_12:
  *_errno() = 9;
LABEL_13:
  retval = -1;
done_0:
  ms_exc.registration.TryLevel = -2;
  _unlock_fhandle(fh: fildesa);
  return retval;
}

//------------------------------------------------------------------------------
// Address: 0x00460903
// Name: IsRootUNCName
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __usercall IsRootUNCName@<eax>(const char *path@<esi>)
{
  unsigned int v1; // eax
  char v2; // al
  char v3; // al
  const char *v4; // eax
  char v5; // cl
  char *v6; // eax
  char v7; // cl
  char *v9; // [esp+0h] [ebp-4h]

  strlen(buf: v9);
  if ( v1 < 5 || *path != 92 && *path != 47 )
    return false;
  v2 = path[1];
  if ( v2 != 92 && v2 != 47 )
    return false;
  v3 = path[2];
  if ( v3 == 92 )
    return false;
  if ( v3 == 47 )
    return false;
  v4 = path + 3;
  v5 = path[3];
  if ( v5 == 0 )
    return false;
  do
  {
    if ( v5 == 92 )
      break;
    if ( v5 == 47 )
      break;
    v5 = *++v4;
  }
  while ( *v4 != 0 );
  if ( *v4 == 0 )
    return false;
  v6 = (char *)(v4 + 1);
  if ( *v6 == 0 )
    return false;
  v7 = *v6;
  do
  {
    if ( v7 == 92 )
      break;
    if ( v7 == 47 )
      break;
    v7 = *++v6;
  }
  while ( *v6 != 0 );
  return *v6 == 0 || v6[1] == 0;
}

//------------------------------------------------------------------------------
// Address: 0x0046097D
// Name: _fullpath_helper
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char *__cdecl fullpath_helper(char *buf, const char *path, DWORD sz, char **pBuf)
{
  int v4; // esi
  char *v5; // edi
  int *v6; // eax
  char *result; // eax

  v4 = *_errno();
  *_errno() = 0;
  v5 = _fullpath(UserBuf: buf, path, maxlen: sz);
  v6 = _errno();
  if ( v5 != nullptr )
  {
    *v6 = v4;
    return v5;
  }
  else if ( *v6 == 34 )
  {
    *_errno() = v4;
    result = _fullpath(UserBuf: nullptr, path, maxlen: 0);
    *pBuf = result;
  }
  else
  {
    return nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004609DD
// Name: __stat64
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall _stat64@<eax>(__int128 a1@<xmm0>, char *name, _stat64 *buf)
{
  const char *dwHighDateTime; // esi
  int v4; // eax
  unsigned int v5; // eax
  int v6; // eax
  char *v7; // eax
  const char *v8; // esi
  int v9; // eax
  __int64 v10; // rax
  int v11; // esi
  int v13; // edx
  int v14; // edx
  int v15; // edx
  unsigned int nFileSizeHigh; // ecx
  DWORD LastError; // eax
  int drive; // [esp+Ch] [ebp-268h]
  _FILETIME LocalFTime; // [esp+10h] [ebp-264h] BYREF
  int fd; // [esp+18h] [ebp-25Ch] BYREF
  _WIN32_FIND_DATAA findbuf; // [esp+1Ch] [ebp-258h] BYREF
  _SYSTEMTIME SystemTime; // [esp+15Ch] [ebp-118h] BYREF
  char pathbuf[260]; // [esp+16Ch] [ebp-108h] BYREF

  dwHighDateTime = name;
  LocalFTime.dwHighDateTime = (unsigned int)name;
  if ( name != nullptr && buf != nullptr )
  {
    _mbspbrk(string: (unsigned __int8 *)name, charset: "?*");
    if ( v4 != 0 )
    {
LABEL_5:
      *_errno() = 2;
      *__doserrno() = 2;
      return -1;
    }
    if ( name[1] == 58 )
    {
      if ( *name != 0 && name[2] == 0 )
        goto LABEL_5;
      v5 = _mbctolower(c: *name) - 96;
    }
    else
    {
      v5 = _getdrive();
    }
    drive = v5;
    fd = (int)FindFirstFileExA(
                lpFileName: name,
                fInfoLevelId: FindExInfoStandard,
                lpFindFileData: &findbuf,
                fSearchOp: FindExSearchNameMatch,
                lpSearchFilter: nullptr,
                dwAdditionalFlags: 0);
    if ( fd == -1 )
    {
      fd = 0;
      _mbspbrk(string: (unsigned __int8 *)name, charset: "./\\");
      if ( v6 == 0 )
        goto LABEL_5;
      v7 = fullpath_helper(buf: pathbuf, path: name, sz: 0x104u, pBuf: (char **)&fd);
      v8 = v7;
      if ( v7 == nullptr
        || (strlen(buf: v7), v9 != 3) && !IsRootUNCName(path: v8)
        || GetDriveTypeA(lpRootPathName: v8) <= 1 )
      {
        if ( fd != 0 )
          free(pMem: (void *)fd);
        goto LABEL_5;
      }
      if ( fd != 0 )
        free(pMem: (void *)fd);
      findbuf.dwFileAttributes = 16;
      findbuf.nFileSizeHigh = 0;
      findbuf.nFileSizeLow = 0;
      findbuf.cFileName[0] = 0;
      LODWORD(v10) = __loctotime64_t(yr: 1980, mo: 1, dy: 1, hr: 0, mn: 0, sc: 0, dstflag: -1);
      dwHighDateTime = (const char *)LocalFTime.dwHighDateTime;
      buf->st_mtime = v10;
      buf->st_atime = v10;
      buf->st_ctime = v10;
LABEL_46:
      buf->st_mode = __dtoxmode(attr: findbuf.dwFileAttributes, name: dwHighDateTime);
      buf->st_nlink = 1;
      nFileSizeHigh = findbuf.nFileSizeHigh;
      LODWORD(buf->st_size) = findbuf.nFileSizeLow;
      buf->st_ino = 0;
      buf->st_gid = 0;
      buf->st_uid = 0;
      buf->st_dev = drive - 1;
      buf->st_rdev = drive - 1;
      HIDWORD(buf->st_size) = nFileSizeHigh;
      return 0;
    }
    if ( (findbuf.dwFileAttributes & 0x400) != 0 && findbuf.dwReserved0 == -1610612724 )
    {
      fd = -1;
      if ( _sopen_s(pfh: &fd, path: name, oflag: 0, shflag: 64, pmode: 0) == 0 && fd != -1 )
      {
        v11 = _fstat64(a1, fildes: fd, buf);
        _close(fh: fd);
        return v11;
      }
      goto LABEL_5;
    }
    if ( findbuf.ftLastWriteTime.dwLowDateTime != 0 || findbuf.ftLastWriteTime.dwHighDateTime != 0 )
    {
      if ( !FileTimeToLocalFileTime(lpFileTime: &findbuf.ftLastWriteTime, lpLocalFileTime: &LocalFTime)
        || !FileTimeToSystemTime(lpFileTime: &LocalFTime, lpSystemTime: &SystemTime) )
      {
        goto LABEL_47;
      }
      LODWORD(buf->st_mtime) = __loctotime64_t(
                                 yr: SystemTime.wYear,
                                 mo: SystemTime.wMonth,
                                 dy: SystemTime.wDay,
                                 hr: SystemTime.wHour,
                                 mn: SystemTime.wMinute,
                                 sc: SystemTime.wSecond,
                                 dstflag: -1);
      HIDWORD(buf->st_mtime) = v13;
    }
    else
    {
      buf->st_mtime = 0;
    }
    if ( findbuf.ftLastAccessTime.dwLowDateTime != 0 || findbuf.ftLastAccessTime.dwHighDateTime != 0 )
    {
      if ( !FileTimeToLocalFileTime(lpFileTime: &findbuf.ftLastAccessTime, lpLocalFileTime: &LocalFTime)
        || !FileTimeToSystemTime(lpFileTime: &LocalFTime, lpSystemTime: &SystemTime) )
      {
        goto LABEL_47;
      }
      LODWORD(buf->st_atime) = __loctotime64_t(
                                 yr: SystemTime.wYear,
                                 mo: SystemTime.wMonth,
                                 dy: SystemTime.wDay,
                                 hr: SystemTime.wHour,
                                 mn: SystemTime.wMinute,
                                 sc: SystemTime.wSecond,
                                 dstflag: -1);
      HIDWORD(buf->st_atime) = v14;
    }
    else
    {
      buf->st_atime = buf->st_mtime;
    }
    if ( findbuf.ftCreationTime.dwLowDateTime == 0 && findbuf.ftCreationTime.dwHighDateTime == 0 )
    {
      buf->st_ctime = buf->st_mtime;
LABEL_45:
      FindClose(hFindFile: (HANDLE)fd);
      goto LABEL_46;
    }
    if ( FileTimeToLocalFileTime(lpFileTime: &findbuf.ftCreationTime, lpLocalFileTime: &LocalFTime)
      && FileTimeToSystemTime(lpFileTime: &LocalFTime, lpSystemTime: &SystemTime) )
    {
      LODWORD(buf->st_ctime) = __loctotime64_t(
                                 yr: SystemTime.wYear,
                                 mo: SystemTime.wMonth,
                                 dy: SystemTime.wDay,
                                 hr: SystemTime.wHour,
                                 mn: SystemTime.wMinute,
                                 sc: SystemTime.wSecond,
                                 dstflag: -1);
      HIDWORD(buf->st_ctime) = v15;
      goto LABEL_45;
    }
LABEL_47:
    LastError = GetLastError();
    _dosmaperr(oserrno: LastError);
    FindClose(hFindFile: (HANDLE)fd);
    return -1;
  }
  *__doserrno() = 0;
  *_errno() = 22;
  _invalid_parameter_noinfo();
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00460E27
// Name: __isdigit_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _isdigit_l(int c, localeinfo_struct *plocinfo)
{
  int result; // eax
  _LocaleUpdate _loc_update; // [esp+0h] [ebp-10h] BYREF

  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  if ( _loc_update.localeinfo.locinfo->mb_cur_max <= 1 )
    result = _loc_update.localeinfo.locinfo->pctype[c] & 4;
  else
    result = _isctype_l(c, mask: 4, plocinfo: &_loc_update.localeinfo);
  if ( _loc_update.updated )
    _loc_update.ptd->_ownlocale &= ~2u;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00460E78
// Name: _isdigit
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl isdigit(int c)
{
  if ( __locale_changed != 0 )
    return _isdigit_l(c, plocinfo: nullptr);
  else
    return __initiallocinfo.pctype[c] & 4;
}

//------------------------------------------------------------------------------
// Address: 0x00460EA6
// Name: __isxdigit_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _isxdigit_l(int c, localeinfo_struct *plocinfo)
{
  int result; // eax
  _LocaleUpdate _loc_update; // [esp+0h] [ebp-10h] BYREF

  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  if ( _loc_update.localeinfo.locinfo->mb_cur_max <= 1 )
    result = _loc_update.localeinfo.locinfo->pctype[c] & 0x80;
  else
    result = _isctype_l(c, mask: 128, plocinfo: &_loc_update.localeinfo);
  if ( _loc_update.updated )
    _loc_update.ptd->_ownlocale &= ~2u;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00460EFC
// Name: _isxdigit
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl isxdigit(int c)
{
  if ( __locale_changed != 0 )
    return _isxdigit_l(c, plocinfo: nullptr);
  else
    return __initiallocinfo.pctype[c] & 0x80;
}

//------------------------------------------------------------------------------
// Address: 0x00460F2C
// Name: __isspace_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _isspace_l(int c, localeinfo_struct *plocinfo)
{
  int result; // eax
  _LocaleUpdate _loc_update; // [esp+0h] [ebp-10h] BYREF

  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  if ( _loc_update.localeinfo.locinfo->mb_cur_max <= 1 )
    result = _loc_update.localeinfo.locinfo->pctype[c] & 8;
  else
    result = _isctype_l(c, mask: 8, plocinfo: &_loc_update.localeinfo);
  if ( _loc_update.updated )
    _loc_update.ptd->_ownlocale &= ~2u;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00460F7D
// Name: _isspace
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl isspace(int c)
{
  if ( __locale_changed != 0 )
    return _isspace_l(c, plocinfo: nullptr);
  else
    return __initiallocinfo.pctype[c] & 8;
}

//------------------------------------------------------------------------------
// Address: 0x00460FAB
// Name: __isalnum_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _isalnum_l(int c, localeinfo_struct *plocinfo)
{
  int result; // eax
  _LocaleUpdate _loc_update; // [esp+0h] [ebp-10h] BYREF

  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  if ( _loc_update.localeinfo.locinfo->mb_cur_max <= 1 )
    result = _loc_update.localeinfo.locinfo->pctype[c] & 0x107;
  else
    result = _isctype_l(c, mask: 263, plocinfo: &_loc_update.localeinfo);
  if ( _loc_update.updated )
    _loc_update.ptd->_ownlocale &= ~2u;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00461001
// Name: _isalnum
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl isalnum(int c)
{
  if ( __locale_changed != 0 )
    return _isalnum_l(c, plocinfo: nullptr);
  else
    return __initiallocinfo.pctype[c] & 0x107;
}

//------------------------------------------------------------------------------
// Address: 0x00461031
// Name: __iscntrl_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _iscntrl_l(int c, localeinfo_struct *plocinfo)
{
  int result; // eax
  _LocaleUpdate _loc_update; // [esp+0h] [ebp-10h] BYREF

  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  if ( _loc_update.localeinfo.locinfo->mb_cur_max <= 1 )
    result = _loc_update.localeinfo.locinfo->pctype[c] & 0x20;
  else
    result = _isctype_l(c, mask: 32, plocinfo: &_loc_update.localeinfo);
  if ( _loc_update.updated )
    _loc_update.ptd->_ownlocale &= ~2u;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00461082
// Name: _iscntrl
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl iscntrl(int c)
{
  if ( __locale_changed != 0 )
    return _iscntrl_l(c, plocinfo: nullptr);
  else
    return __initiallocinfo.pctype[c] & 0x20;
}

//------------------------------------------------------------------------------
// Address: 0x004610B0
// Name: shortsort
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall shortsort(
        char *hi@<eax>,
        char *lo,
        unsigned int width,
        int (__cdecl *comp)(const void *, const void *))
{
  char *v4; // edx
  char *v5; // edi
  unsigned int v6; // ecx
  char *v7; // esi
  char *v8; // ebx
  unsigned int v9; // esi
  char *v10; // eax
  int v11; // ecx
  char v12; // dl

  v4 = lo;
  v5 = hi;
  if ( hi > lo )
  {
    v6 = width;
    do
    {
      v7 = &lo[width];
      v8 = v4;
      if ( &lo[width] <= v5 )
      {
        do
        {
          if ( comp(a1: v7, a2: v8) > 0 )
            v8 = v7;
          v7 += width;
        }
        while ( v7 <= v5 );
        v6 = width;
        v4 = lo;
      }
      v9 = v6;
      v10 = v5;
      if ( v8 != v5 && v6 != 0 )
      {
        v11 = v8 - v5;
        do
        {
          v12 = v10[v11];
          v10[v11] = *v10;
          *v10++ = v12;
          --v9;
        }
        while ( v9 != 0 );
        v6 = width;
        v4 = lo;
      }
      v5 -= v6;
    }
    while ( v5 > v4 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00461140
// Name: _qsort
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl qsort(char *base, unsigned int num, unsigned int width, int (__cdecl *comp)(const void *, const void *))
{
  char *v4; // edi
  unsigned int v5; // ebx
  char *v6; // esi
  unsigned int v7; // eax
  char *v8; // ebx
  unsigned int v9; // edx
  char *v10; // eax
  int v11; // ecx
  unsigned int v12; // ecx
  char *v13; // eax
  int v14; // edi
  unsigned int v15; // ecx
  char *v16; // eax
  int v17; // edi
  unsigned int v18; // edx
  char *v19; // eax
  int v20; // ecx
  char *v21; // eax
  char *v22; // edx
  int v23; // ecx
  int v24; // ecx
  int v25; // eax
  char *v26; // edx
  char *v27; // eax
  char *histk[30]; // [esp+8h] [ebp-100h]
  char *lostk[30]; // [esp+80h] [ebp-88h]
  unsigned int v30; // [esp+F8h] [ebp-10h]
  int stkptr; // [esp+FCh] [ebp-Ch]
  char *hi; // [esp+100h] [ebp-8h]
  char *lo; // [esp+104h] [ebp-4h]
  char base_3; // [esp+113h] [ebp+Bh]
  char base_3a; // [esp+113h] [ebp+Bh]
  char base_3b; // [esp+113h] [ebp+Bh]
  char base_3c; // [esp+113h] [ebp+Bh]

  v4 = base;
  if ( base == nullptr && num != 0 )
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return;
  }
  v5 = width;
  if ( width == 0 || comp == nullptr )
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return;
  }
  if ( num >= 2 )
  {
    v6 = &base[width * (num - 1)];
    stkptr = 0;
    lo = base;
    hi = v6;
    while ( 1 )
    {
      v7 = (v6 - v4) / v5 + 1;
      if ( v7 <= 8 )
      {
        shortsort(hi: v6, lo: v4, width: v5, comp);
        goto LABEL_57;
      }
      v8 = &v4[(v7 >> 1) * v5];
      if ( comp(a1: v4, a2: v8) > 0 )
      {
        v9 = width;
        v10 = v8;
        if ( v4 != v8 )
        {
          v11 = v4 - v8;
          do
          {
            v30 = v9 - 1;
            base_3 = v10[v11];
            v10[v11] = *v10;
            *v10 = base_3;
            v9 = v30;
            ++v10;
          }
          while ( v30 != 0 );
        }
      }
      if ( comp(a1: v4, a2: v6) > 0 )
      {
        v12 = width;
        v13 = v6;
        if ( v4 != v6 )
        {
          v14 = v4 - v6;
          do
          {
            base_3a = v13[v14];
            v13[v14] = *v13;
            *v13++ = base_3a;
            --v12;
          }
          while ( v12 != 0 );
          v4 = lo;
        }
      }
      if ( comp(a1: v8, a2: v6) > 0 )
      {
        v15 = width;
        v16 = v6;
        if ( v8 != v6 )
        {
          v17 = v8 - v6;
          do
          {
            base_3b = v16[v17];
            v16[v17] = *v16;
            *v16++ = base_3b;
            --v15;
          }
          while ( v15 != 0 );
          v4 = lo;
        }
      }
      while ( 1 )
      {
        if ( v8 > v4 )
        {
          while ( 1 )
          {
            v4 += width;
            if ( v4 >= v8 )
              break;
            if ( comp(a1: v4, a2: v8) > 0 )
            {
              if ( v8 > v4 )
                goto LABEL_32;
              goto LABEL_30;
            }
          }
        }
        do
LABEL_30:
          v4 += width;
        while ( v4 <= hi && comp(a1: v4, a2: v8) <= 0 );
        do
LABEL_32:
          v6 -= width;
        while ( v6 > v8 && comp(a1: v6, a2: v8) > 0 );
        if ( v4 > v6 )
          break;
        v18 = width;
        v19 = v6;
        if ( v4 != v6 )
        {
          v20 = v4 - v6;
          do
          {
            v30 = v18 - 1;
            base_3c = v19[v20];
            v19[v20] = *v19;
            *v19 = base_3c;
            v18 = v30;
            ++v19;
          }
          while ( v30 != 0 );
        }
        if ( v8 == v6 )
          v8 = v4;
      }
      v6 += width;
      if ( v8 >= v6 )
        goto LABEL_44;
      do
      {
        v6 -= width;
        if ( v6 <= v8 )
          goto LABEL_44;
      }
      while ( comp(a1: v6, a2: v8) == 0 );
      if ( v8 < v6 )
      {
LABEL_46:
        v21 = lo;
      }
      else
      {
LABEL_44:
        while ( 1 )
        {
          v6 -= width;
          v21 = lo;
          if ( v6 <= lo )
            break;
          if ( comp(a1: v6, a2: v8) != 0 )
            goto LABEL_46;
        }
      }
      v22 = hi;
      if ( v6 - v21 < hi - v4 )
      {
        if ( v4 < hi )
        {
          v24 = stkptr;
          lostk[stkptr] = v4;
          histk[v24] = v22;
          stkptr = v24 + 1;
        }
        if ( v21 >= v6 )
          goto LABEL_56;
        v4 = lo;
        v5 = width;
        hi = v6;
      }
      else
      {
        if ( v21 < v6 )
        {
          v23 = stkptr;
          lostk[stkptr] = v21;
          histk[v23] = v6;
          stkptr = v23 + 1;
        }
        if ( v4 >= v22 )
        {
LABEL_56:
          v5 = width;
LABEL_57:
          v25 = --stkptr;
          if ( stkptr < 0 )
            return;
          v26 = lostk[v25];
          v27 = histk[v25];
          lo = v26;
          hi = v27;
          v6 = v27;
          v4 = v26;
        }
        else
        {
          v6 = hi;
          v5 = width;
          lo = v4;
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004613CB
// Name: ___time64_t_from_ft
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl __time64_t_from_ft(_FILETIME *pft)
{
  _FILETIME lft; // [esp+0h] [ebp-1Ch] BYREF
  _SYSTEMTIME st; // [esp+8h] [ebp-14h] BYREF

  if ( (pft->dwLowDateTime != 0 || pft->dwHighDateTime != 0)
    && FileTimeToLocalFileTime(lpFileTime: pft, lpLocalFileTime: &lft)
    && FileTimeToSystemTime(lpFileTime: &lft, lpSystemTime: &st) )
  {
    return __loctotime64_t(
             yr: st.wYear,
             mo: st.wMonth,
             dy: st.wDay,
             hr: st.wHour,
             mn: st.wMinute,
             sc: st.wSecond,
             dstflag: 0);
  }
  else
  {
    return -1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00461447
// Name: __findfirst64i32
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall _findfirst64i32@<eax>(__int128 a1@<xmm0>, const char *szWild, _finddata64i32_t *pfd)
{
  HANDLE FirstFile; // ebx
  DWORD LastError; // eax
  int v6; // edx
  int v7; // edx
  int v8; // edx
  _WIN32_FIND_DATAA wfd; // [esp+8h] [ebp-144h] BYREF

  if ( pfd == nullptr || szWild == nullptr )
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return -1;
  }
  FirstFile = FindFirstFileExA(
                lpFileName: szWild,
                fInfoLevelId: FindExInfoStandard,
                lpFindFileData: &wfd,
                fSearchOp: FindExSearchNameMatch,
                lpSearchFilter: nullptr,
                dwAdditionalFlags: 0);
  if ( FirstFile == (HANDLE)-1 )
  {
    LastError = GetLastError();
    if ( LastError >= 2 )
    {
      if ( LastError <= 3 )
        goto LABEL_13;
      if ( LastError == 8 )
      {
        *_errno() = 12;
        return -1;
      }
      if ( LastError == 18 )
      {
LABEL_13:
        *_errno() = 2;
        return -1;
      }
    }
    *_errno() = 22;
    return -1;
  }
  pfd->attrib = wfd.dwFileAttributes != 128 ? wfd.dwFileAttributes : 0;
  LODWORD(pfd->time_create) = __time64_t_from_ft(pft: &wfd.ftCreationTime);
  HIDWORD(pfd->time_create) = v6;
  LODWORD(pfd->time_access) = __time64_t_from_ft(pft: &wfd.ftLastAccessTime);
  HIDWORD(pfd->time_access) = v7;
  LODWORD(pfd->time_write) = __time64_t_from_ft(pft: &wfd.ftLastWriteTime);
  pfd->size = wfd.nFileSizeLow;
  HIDWORD(pfd->time_write) = v8;
  if ( strcpy_s(_Dst: pfd->name, _SizeInBytes: 0x104u, _Src: wfd.cFileName) != 0 )
    _invoke_watson(a1: 0, a2: a1);
  return (int)FirstFile;
}

//------------------------------------------------------------------------------
// Address: 0x0046156E
// Name: __findnext64i32
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall _findnext64i32@<eax>(__int128 a1@<xmm0>, void *hFile, _finddata64i32_t *pfd)
{
  int result; // eax
  DWORD LastError; // eax
  int v5; // edx
  int v6; // edx
  int v7; // edx
  _WIN32_FIND_DATAA wfd; // [esp+4h] [ebp-144h] BYREF

  if ( hFile == (void *)-1 )
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return -1;
  }
  if ( pfd == nullptr )
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return -1;
  }
  if ( !FindNextFileA(hFindFile: hFile, lpFindFileData: &wfd) )
  {
    LastError = GetLastError();
    if ( LastError >= 2 )
    {
      if ( LastError <= 3 )
        goto LABEL_14;
      if ( LastError == 8 )
      {
        *_errno() = 12;
        return -1;
      }
      if ( LastError == 18 )
      {
LABEL_14:
        *_errno() = 2;
        return -1;
      }
    }
    *_errno() = 22;
    return -1;
  }
  pfd->attrib = wfd.dwFileAttributes != 128 ? wfd.dwFileAttributes : 0;
  LODWORD(pfd->time_create) = __time64_t_from_ft(pft: &wfd.ftCreationTime);
  HIDWORD(pfd->time_create) = v5;
  LODWORD(pfd->time_access) = __time64_t_from_ft(pft: &wfd.ftLastAccessTime);
  HIDWORD(pfd->time_access) = v6;
  LODWORD(pfd->time_write) = __time64_t_from_ft(pft: &wfd.ftLastWriteTime);
  pfd->size = wfd.nFileSizeLow;
  HIDWORD(pfd->time_write) = v7;
  result = strcpy_s(_Dst: pfd->name, _SizeInBytes: 0x104u, _Src: wfd.cFileName);
  if ( result != 0 )
    _invoke_watson(a1: 0, a2: a1);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0046169C
// Name: __findclose
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _findclose(void *hFile)
{
  if ( FindClose(hFindFile: hFile) )
    return 0;
  *_errno() = 22;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0046185F
// Name: __fwrite_nolock
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __cdecl _fwrite_nolock(unsigned __int8 *buffer, unsigned int size, unsigned int num, _iobuf *stream)
{
  unsigned int v5; // edi
  unsigned int v6; // ebx
  int cnt; // eax
  unsigned int v8; // edi
  unsigned int v9; // edi
  int v10; // eax
  unsigned int v11; // eax
  unsigned int v12; // ecx
  unsigned int v13; // eax
  unsigned int bufsize; // [esp+10h] [ebp-8h]
  unsigned __int8 *data; // [esp+14h] [ebp-4h]

  if ( size == 0 || num == 0 )
    return 0;
  if ( stream == nullptr || buffer == nullptr || num > 0xFFFFFFFF / size )
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return 0;
  }
  v5 = num * size;
  data = buffer;
  v6 = num * size;
  if ( (stream->_flag & 0x10C) != 0 )
    bufsize = stream->_bufsiz;
  else
    bufsize = 4096;
  if ( v5 == 0 )
    return num;
  while ( 1 )
  {
    if ( (stream->_flag & 0x108) != 0 )
    {
      cnt = stream->_cnt;
      if ( cnt != 0 )
      {
        if ( cnt < 0 )
        {
          stream->_flag |= 0x20u;
LABEL_34:
          v13 = v5;
          return (v13 - v6) / size;
        }
        v8 = v6;
        if ( v6 >= cnt )
          v8 = stream->_cnt;
        memcpy(dst: (unsigned __int8 *)stream->_ptr, src: data, count: v8);
        stream->_cnt -= v8;
        stream->_ptr += v8;
        v6 -= v8;
        data += v8;
        goto LABEL_27;
      }
    }
    if ( v6 >= bufsize )
      break;
    if ( _flsbuf(ch: *data, str: (int)stream) == -1 )
      goto LABEL_34;
    ++data;
    --v6;
    bufsize = stream->_bufsiz;
    if ( (int)bufsize <= 0 )
      bufsize = 1;
LABEL_31:
    if ( v6 == 0 )
      return num;
  }
  if ( (stream->_flag & 0x108) != 0 && _flush(str: stream) != 0 )
    goto LABEL_34;
  v9 = v6;
  if ( bufsize != 0 )
    v9 = v6 - v6 % bufsize;
  v10 = fileno(stream);
  v11 = _write(fh: v10, buf: data, cnt: v9);
  if ( v11 != -1 )
  {
    v12 = v9;
    if ( v11 <= v9 )
      v12 = v11;
    data += v12;
    v6 -= v12;
    if ( v11 >= v9 )
    {
LABEL_27:
      v5 = num * size;
      goto LABEL_31;
    }
  }
  stream->_flag |= 0x20u;
  v13 = num * size;
  return (v13 - v6) / size;
}

//------------------------------------------------------------------------------
// Address: 0x004619C0
// Name: __aullshr
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned __int64 __usercall _aullshr@<edx:eax>(unsigned __int64 a1@<edx:eax>, unsigned __int8 a2@<cl>)
{
  if ( a2 >= 0x40u )
    return 0;
  else
    return a1 >> a2;
}

//------------------------------------------------------------------------------
// Address: 0x004619E0
// Name: _pow
// Source: linker_block_proximity
//------------------------------------------------------------------------------
double __cdecl pow(double X, double Y)
{
  int v2; // eax
  bool v3; // zf
  char v5; // [esp+0h] [ebp-8h]

  if ( __use_sse2_mathfcns != 0 )
  {
    v2 = _mm_getcsr() & 0x7F80;
    v3 = v2 == 8064;
    if ( v2 == 8064 )
      v3 = (v5 & 0x7F) == 127;
    if ( v3 )
      JUMPOUT(0x46AF49);
  }
  JUMPOUT(0x461A74);
}

//------------------------------------------------------------------------------
// Address: 0x00461A20
// Name: __CIpow
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _CIpow(int a1, int a2, int a3, int a4)
{
  int v6; // eax
  bool v7; // zf
  char v8; // [esp+0h] [ebp-8h]

  if ( __use_sse2_mathfcns == 0 )
    goto __CIpow;
  v6 = _mm_getcsr() & 0x7F80;
  v7 = v6 == 8064;
  if ( v6 == 8064 )
    v7 = (v8 & 0x7F) == 127;
  if ( v7 )
    _CIpow_pentium4();
  else
__CIpow:
    _CIpow_default(a1, a2, a3, a4);
}

//------------------------------------------------------------------------------
// Address: 0x00461A5B
// Name: __CIpow_default
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void _CIpow_default()
{
  JUMPOUT(0x461A7D);
}

//------------------------------------------------------------------------------
// Address: 0x00461C70
// Name: _log
// Source: linker_block_proximity
//------------------------------------------------------------------------------
double __cdecl log(double X)
{
  int v1; // eax
  bool v2; // zf
  char v4; // [esp+0h] [ebp-8h]

  if ( __use_sse2_mathfcns != 0 )
  {
    v1 = _mm_getcsr() & 0x7F80;
    v2 = v1 == 8064;
    if ( v1 == 8064 )
      v2 = (v4 & 0x7F) == 127;
    if ( v2 )
      JUMPOUT(0x46C208);
  }
  JUMPOUT(0x461CFF);
}

//------------------------------------------------------------------------------
// Address: 0x00461CB0
// Name: __CIlog
// Source: linker_block_proximity
//------------------------------------------------------------------------------
double __usercall _CIlog@<st0>(double x@<st0>, int a2, int a3)
{
  int v3; // eax
  bool v4; // zf
  char v5; // [esp+0h] [ebp-8h]

  if ( __use_sse2_mathfcns == 0 )
    goto __CIlog;
  v3 = _mm_getcsr() & 0x7F80;
  v4 = v3 == 8064;
  if ( v3 == 8064 )
    v4 = (v5 & 0x7F) == 127;
  if ( v4 )
    _CIlog_pentium4(a1: x);
  else
__CIlog:
    _CIlog_default(a1: a2, a2: a3);
  return x;
}

//------------------------------------------------------------------------------
// Address: 0x00461CEB
// Name: __CIlog_default
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// Decompile returned None
