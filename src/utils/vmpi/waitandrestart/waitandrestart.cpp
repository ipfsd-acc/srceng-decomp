// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/vmpi/waitandrestart/waitandrestart.cpp
// Functions: 284
// ============================================================

#include "utils\vmpi\waitandrestart\waitandrestart.h"

//------------------------------------------------------------------------------
// Address: 0x00401220
// Name: _main
// Source: json
//------------------------------------------------------------------------------
int __cdecl main(int argc, const char **argv, const char **envp)
{
  int v3; // edi
  int v4; // esi
  const char **v5; // ebx
  const char *v7; // eax
  bool v8; // zf
  HANDLE v9; // eax
  void *v10; // esi
  DWORD v11; // eax
  int v12; // ebx
  int i; // esi
  DWORD v14; // ebx
  int v15; // esi
  const char **v16; // ebx
  DWORD LastError; // eax
  char commandLine[1024]; // [esp+Ch] [ebp-458h] BYREF
  _STARTUPINFOA StartupInfo; // [esp+40Ch] [ebp-58h] BYREF
  _PROCESS_INFORMATION pi; // [esp+450h] [ebp-14h] BYREF
  const char *pWorkingDir; // [esp+460h] [ebp-4h]

  v3 = argc;
  if ( argc < 4 )
  {
    VMPI_WriteToLogFile(pMsg: "WaitAndRestart run with invalid command line args. Exiting. But first, you get to see the arguments:\n");
    v4 = 0;
    if ( v3 > 0 )
    {
      v5 = argv;
      do
      {
        VMPI_WriteToLogFile(pMsg: "\targv[%d]: %s\n", v4, v5[v4]);
        ++v4;
      }
      while ( v4 < v3 );
    }
    printf(format: "WaitAndRestart <seconds to wait> <working directory> command line...\n");
    return 1;
  }
  v7 = argv[1];
  v8 = *v7 == 42;
  pWorkingDir = argv[2];
  if ( v8 )
  {
    sscanf(string: v7 + 1, format: "%lu", &argc);
    VMPI_WriteToLogFile(pMsg: "Waiting for process %lu to exit. Press a key to cancel...\n", argc);
    v9 = OpenProcess(dwDesiredAccess: 0x100000u, bInheritHandle: false, dwProcessId: argc);
    v10 = v9;
    if ( v9 != nullptr )
    {
      v11 = WaitForSingleObject(hHandle: v9, dwMilliseconds: 0x64u);
      if ( v11 != 0 )
      {
        while ( v11 != 128 )
        {
          if ( kbhit() != 0 )
            return 2;
          v11 = WaitForSingleObject(hHandle: v10, dwMilliseconds: 0x64u);
          if ( v11 == 0 )
            goto LABEL_12;
        }
        VMPI_WriteToLogFile(pMsg: "Got WAIT_ABANDONED (error). Waiting 5 seconds, then continuing.\n");
        Sleep(dwMilliseconds: 0x1388u);
      }
LABEL_12:
      VMPI_WriteToLogFile(pMsg: "Process %lu terminated. Continuing.\n", argc);
      CloseHandle(hObject: v10);
    }
    else
    {
      VMPI_WriteToLogFile(pMsg: "Process %lu not running. Continuing.\n", argc);
      CloseHandle(hObject: nullptr);
    }
    goto LABEL_22;
  }
  v12 = atoi(nptr: v7);
  VMPI_WriteToLogFile(pMsg: "\n\nWaiting for %d seconds to launch ' ", v12);
  VMPI_WriteToLogFile(pMsg: "%s> ", pWorkingDir);
  for ( i = 3; i < v3; ++i )
    VMPI_WriteToLogFile(pMsg: "%s ", argv[i]);
  VMPI_WriteToLogFile(pMsg: "'\n\nPress a key to cancel... ");
  v14 = 1000 * v12;
  argc = GetTickCount();
  if ( GetTickCount() - argc >= v14 )
  {
LABEL_22:
    memset(commandLine, 0, sizeof(commandLine));
    v15 = 3;
    if ( v3 > 3 )
    {
      v16 = argv;
      do
      {
        strcat_s(_Dst: commandLine, _SizeInBytes: 0x400u, _Src: "\"");
        strcat_s(_Dst: commandLine, _SizeInBytes: 0x400u, _Src: v16[v15]);
        strcat_s(_Dst: commandLine, _SizeInBytes: 0x400u, _Src: "\" ");
        ++v15;
      }
      while ( v15 < v3 );
    }
    memset(dst: (unsigned __int8 *)&StartupInfo, value: 0, count: sizeof(StartupInfo));
    StartupInfo.cb = 68;
    memset(&pi, 0, sizeof(pi));
    if ( CreateProcessA(
           lpApplicationName: nullptr,
           lpCommandLine: commandLine,
           lpProcessAttributes: nullptr,
           lpThreadAttributes: nullptr,
           bInheritHandles: false,
           dwCreationFlags: 0,
           lpEnvironment: nullptr,
           lpCurrentDirectory: pWorkingDir,
           lpStartupInfo: &StartupInfo,
           lpProcessInformation: &pi) )
    {
      VMPI_WriteToLogFile(pMsg: "Process started.\n");
      CloseHandle(hObject: pi.hThread);
      CloseHandle(hObject: pi.hProcess);
    }
    else
    {
      LastError = GetLastError();
      FormatMessageA(
        dwFlags: 0x1300u,
        lpSource: nullptr,
        dwMessageId: LastError,
        dwLanguageId: 0x400u,
        lpBuffer: (LPSTR)&argc,
        nSize: 0,
        Arguments: nullptr);
      strncpy(dest: (unsigned __int8 *)dest, source: (unsigned __int8 *)argc, count: 0x800u);
      LocalFree(hMem: (HLOCAL)argc);
      byte_412907 = 0;
      VMPI_WriteToLogFile(pMsg: "CreateProcess error!\n%s", dest);
    }
    return 0;
  }
  while ( kbhit() == 0 )
  {
    Sleep(dwMilliseconds: 0x64u);
    if ( GetTickCount() - argc >= v14 )
      goto LABEL_22;
  }
  return 2;
}

//------------------------------------------------------------------------------
// Address: 0x00401560
// Name: _strstr
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl strstr(unsigned __int8 *str1, unsigned __int8 *str2)
{
  unsigned __int8 v2; // dl
  unsigned __int8 v4; // dh
  unsigned __int8 *v5; // ecx
  unsigned __int8 *v6; // esi
  char v7; // al
  unsigned __int8 v8; // ah
  unsigned __int8 v9; // al
  unsigned __int8 v10; // al

  v2 = *str2;
  if ( *str2 != 0 )
  {
    v4 = str2[1];
    if ( v4 == 0 )
      JUMPOUT(0x4025C6);
findnext:
    v5 = str2;
    v6 = str1 + 1;
    if ( *str1 == v2 )
      goto first_char_found;
    if ( *str1 != 0 )
    {
      while ( 2 )
      {
        v7 = *v6++;
        while ( v7 == v2 )
        {
first_char_found:
          v7 = *v6++;
          if ( v7 == v4 )
          {
            str1 = v6 - 1;
            while ( 1 )
            {
              v8 = v5[2];
              if ( v8 == 0 )
                break;
              v9 = *v6;
              v6 += 2;
              if ( v9 != v8 )
                goto findnext;
              v10 = v5[3];
              if ( v10 == 0 )
                break;
              v5 += 2;
              if ( v10 != *(v6 - 1) )
                goto findnext;
            }
            return;
          }
        }
        if ( v7 != 0 )
          continue;
        break;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004015E6
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
    _invoke_watson(pszExpression: nullptr, pszFunction: nullptr, pszFile: nullptr, nLine: 0, pReserved: 0);
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
// Address: 0x0040186E
// Name: __localtime64
// Source: linker_block_proximity
//------------------------------------------------------------------------------
tm *__cdecl _localtime64(const __int64 *ptime)
{
  tm *result; // eax

  result = (tm *)__getgmtimebuf();
  if ( result != nullptr )
    return _localtime64_s(ptm: result, ptime) == 0 ? result : nullptr;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00401895
// Name: __time64
// Source: linker_block_proximity
//------------------------------------------------------------------------------
__int64 __cdecl _time64(__int64 *timeptr)
{
  __int64 result; // rax
  FT nt_time; // [esp+0h] [ebp-8h] BYREF

  GetSystemTimeAsFileTime(lpSystemTimeAsFileTime: (LPFILETIME)&nt_time);
  result = (nt_time.ft_scalar - 116444736000000000LL) / 0x989680;
  if ( result > 0x793406FFFLL )
    result = -1;
  if ( timeptr != nullptr )
    *timeptr = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004018F0
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
// Address: 0x00401A14
// Name: __fclose_nolock
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _fclose_nolock(_iobuf *str)
{
  int v1; // edi
  int v3; // eax

  v1 = -1;
  if ( str != nullptr )
  {
    if ( (str->_flag & 0x83) != 0 )
    {
      v1 = _flush(str);
      _freebuf(stream: str);
      v3 = _fileno(stream: str);
      if ( _close(fh: v3) >= 0 )
      {
        if ( str->_tmpfname != nullptr )
        {
          free(pBlock: str->_tmpfname);
          str->_tmpfname = nullptr;
        }
      }
      else
      {
        v1 = -1;
      }
    }
    str->_flag = 0;
    return v1;
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return -1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00401A81
// Name: _fclose
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl fclose(_iobuf *stream)
{
  int v2; // [esp+10h] [ebp-1Ch]

  v2 = -1;
  if ( stream != nullptr )
  {
    if ( (stream->_flag & 0x40) != 0 )
    {
      stream->_flag = 0;
    }
    else
    {
      _lock_file(pf: stream);
      v2 = _fclose_nolock(str: stream);
      _unlock_file(pf: stream);
    }
    return v2;
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return -1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00401AF5
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
      v5 = _fileno(stream: str);
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
// Address: 0x00401B5D
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
  v2 = _fileno(stream: str);
  return -(_commit(filedes: v2) != 0);
}

//------------------------------------------------------------------------------
// Address: 0x00401BA5
// Name: flsall
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl flsall(int flushflag)
{
  int i; // esi
  void **v2; // eax
  _BYTE *v3; // eax
  int v4; // ecx
  int result; // eax
  int err; // [esp+10h] [ebp-24h]
  int count; // [esp+18h] [ebp-1Ch]

  count = 0;
  err = 0;
  _lock(locknum: 1);
  for ( i = 0; i < (int)_nstream; ++i )
  {
    v2 = &__piob[i];
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
        _unlock_file2(i, s: __piob[i]);
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
// Address: 0x00401C7F
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
// Address: 0x00401CD2
// Name: __flushall
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _flushall()
{
  return flsall(flushflag: 1);
}

//------------------------------------------------------------------------------
// Address: 0x00401CDB
// Name: _vfprintf_helper
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl vfprintf_helper(
        int (__cdecl *outfn)(_iobuf *, const char *, localeinfo_struct *, char *),
        _iobuf *str,
        const char *format,
        localeinfo_struct *plocinfo,
        char *ap)
{
  int v6; // eax
  ioinfo *v7; // ecx
  ioinfo *v8; // eax
  int v9; // esi
  int retval; // [esp+10h] [ebp-1Ch]

  retval = 0;
  if ( str != nullptr && format != nullptr )
  {
    _lock_file(pf: str);
    if ( (str->_flag & 0x40) == 0 )
    {
      v6 = _fileno(stream: str);
      if ( v6 == -1 || v6 == -2 )
        v7 = &__badioinfo;
      else
        v7 = &__pioinfo[v6 >> 5][v6 & 0x1F];
      if ( (*((_BYTE *)v7 + 36) & 0x7F) != 0
        || (v6 == -1 || v6 == -2 ? (v8 = &__badioinfo) : (v8 = &__pioinfo[v6 >> 5][v6 & 0x1F]), *((char *)v8 + 36) < 0) )
      {
        *_errno() = 22;
        _invalid_parameter_noinfo();
        retval = -1;
      }
    }
    if ( retval == 0 )
    {
      v9 = _stbuf(str);
      retval = outfn(a1: str, a2: format, a3: plocinfo, a4: ap);
      _ftbuf(flag: v9, str);
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
// Address: 0x00401DE6
// Name: _vfprintf
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl vfprintf(_iobuf *str, const char *format, char *ap)
{
  return vfprintf_helper(outfn: _output_l, str, format, plocinfo: nullptr, ap);
}

//------------------------------------------------------------------------------
// Address: 0x00401E05
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
      v3 = _fileno(stream: str);
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
// Address: 0x00401F11
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
    _local_unwind4(a1: &__security_cookie, a2: &ms_exc.registration, a3: -2);
    return nullptr;
  }
  retval = _openfile(filename: (const char *)file, mode, shflag, str: v5);
  _unlock_file(pf: stream);
  return retval;
}

//------------------------------------------------------------------------------
// Address: 0x00401FCD
// Name: _fopen
// Source: linker_block_proximity
//------------------------------------------------------------------------------
_iobuf *__cdecl fopen(_iobuf *file, const char *mode)
{
  return _fsopen(file, mode, shflag: 64);
}

//------------------------------------------------------------------------------
// Address: 0x00401FE4
// Name: _asctime
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char *__cdecl asctime(const tm *tb)
{
  char *asctimebuf; // edi
  _tiddata *v2; // eax
  _tiddata *v3; // esi
  char *v4; // eax
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
      || (v4 = (char *)_calloc_crt(count: 0x1Au, size: 1u), v3->_asctimebuf = v4, v4 != nullptr) )
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
    && (dword_411658[tm_mon] - _days[tm_mon] >= tm_mday
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
// Address: 0x004021C2
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
// Address: 0x0040222F
// Name: _atol
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl atol(const char *nptr)
{
  return strtol(nptr, endptr: nullptr, ibase: 10);
}

//------------------------------------------------------------------------------
// Address: 0x00402245
// Name: _atoi
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl atoi(const char *nptr)
{
  return atol(nptr);
}

//------------------------------------------------------------------------------
// Address: 0x00402250
// Name: vscan_fn
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall vscan_fn@<eax>(
        char *string@<esi>,
        int (__cdecl *inputfn)(_iobuf *, const unsigned __int8 *, localeinfo_struct *, char *),
        const char *format,
        localeinfo_struct *plocinfo,
        char *arglist)
{
  unsigned int v6; // eax
  _iobuf str; // [esp+4h] [ebp-20h] BYREF

  memset(&str, 0, sizeof(str));
  if ( string != nullptr && format != nullptr )
  {
    strlen(buf: (unsigned __int8 *)string);
    str._flag = 73;
    str._base = string;
    str._ptr = string;
    str._cnt = 0x7FFFFFFF;
    if ( v6 <= 0x7FFFFFFF )
      str._cnt = v6;
    return inputfn(a1: &str, a2: (const unsigned __int8 *)format, a3: plocinfo, a4: arglist);
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return -1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004022BE
// Name: _sscanf
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int sscanf(char *string, const char *format, ...)
{
  va_list arglist; // [esp+14h] [ebp+10h] BYREF

  va_start(arglist, format);
  return vscan_fn(string, inputfn: _input_l, format, plocinfo: nullptr, arglist);
}

//------------------------------------------------------------------------------
// Address: 0x004022E0
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
    _lock_file2(i: 1, s: &v2[1]);
    v3 = __iob_func();
    v4 = _stbuf(str: v3 + 1);
    v5 = __iob_func();
    retval = _output_l(stream: v5 + 1, format, plocinfo: nullptr, argptr);
    v6 = __iob_func();
    _ftbuf(flag: v4, str: v6 + 1);
    v7 = __iob_func();
    _unlock_file2(i: 1, s: &v7[1]);
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
// Address: 0x00402387
// Name: __get_printf_count_output
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL _get_printf_count_output()
{
  return _enable_percent_n == (__security_cookie | 1);
}

//------------------------------------------------------------------------------
// Address: 0x004023A0
// Name: _memset
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl memset(int dst, unsigned __int8 *value, unsigned int count)
{
  unsigned int v3; // edx
  int v4; // eax
  unsigned __int8 *v5; // edi
  int v6; // ecx
  unsigned int v7; // ecx
  unsigned int v8; // ecx

  v3 = count;
  if ( count != 0 )
  {
    LOBYTE(v4) = (_BYTE)value;
    if ( (_BYTE)value != 0 || count < 0x80 || __sse2_available == 0 )
    {
      v5 = (unsigned __int8 *)dst;
      if ( count < 4 )
        goto LABEL_15;
      v6 = -dst & 3;
      if ( v6 != 0 )
      {
        v3 = count - v6;
        do
        {
          *v5++ = (unsigned __int8)value;
          --v6;
        }
        while ( v6 != 0 );
      }
      v4 = 16843009 * (unsigned __int8)value;
      v7 = v3;
      v3 &= 3u;
      v8 = v7 >> 2;
      if ( v8 == 0 || (memset32(v5, v4, v8), v5 += 4 * v8, v3 != 0) )
      {
LABEL_15:
        do
        {
          *v5++ = v4;
          --v3;
        }
        while ( v3 != 0 );
      }
    }
    else
    {
      _VEC_memzero((void *)dst, val: (int)value, len: count);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040241A
// Name: fast_error_exit
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl __noreturn fast_error_exit(int rterrnum)
{
  if ( __error_mode != 2 )
    _FF_MSGBANNER();
  _NMSG_WRITE(rterrnum);
  __crtExitProcess(status: 255);
}

//------------------------------------------------------------------------------
// Address: 0x00402443
// Name: __tmainCRTStartup
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _tmainCRTStartup()
{
  int v0; // eax
  int v1; // eax
  int mainret; // [esp+14h] [ebp-20h]
  int managedapp; // [esp+18h] [ebp-1Ch]

  if ( _NoHeapEnableTerminationOnCorruption == 0 )
    HeapSetInformation(
      HeapHandle: nullptr,
      HeapInformationClass: HeapEnableTerminationOnCorruption,
      HeapInformation: nullptr,
      HeapInformationLength: 0);
  managedapp = *(_WORD *)&MEMORY[0x400000] == 23117
            && *(_DWORD *)(MEMORY[0x40003C] + 0x400000) == 17744
            && *(_WORD *)(MEMORY[0x40003C] + 4194328) == 267
            && *(_DWORD *)(MEMORY[0x40003C] + 4194420) > 0xEu
            && *(_DWORD *)(MEMORY[0x40003C] + 4194536) != 0;
  if ( _heap_init() == 0 )
    fast_error_exit(rterrnum: 28);
  if ( _mtinit() == 0 )
    fast_error_exit(rterrnum: 16);
  _RTC_Initialize();
  if ( _ioinit() < 0 )
    _amsg_exit(rterrnum: 27);
  _acmdln = GetCommandLineA();
  _aenvptr = (char *)__crtGetEnvironmentStringsA();
  if ( _setargv() < 0 )
    _amsg_exit(rterrnum: 8);
  if ( _setenvp() < 0 )
    _amsg_exit(rterrnum: 9);
  v0 = _cinit(initFloatingPrecision: 1);
  if ( v0 != 0 )
    _amsg_exit(rterrnum: v0);
  __initenv = _environ;
  v1 = main(argc: __argc, argv: (const char **)__argv, envp: (const char **)_environ);
  mainret = v1;
  if ( managedapp == 0 )
    exit(code: v1);
  _cexit();
  return mainret;
}

//------------------------------------------------------------------------------
// Address: 0x004025A4
// Name: _mainCRTStartup
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl mainCRTStartup()
{
  __security_init_cookie();
  return _tmainCRTStartup();
}

//------------------------------------------------------------------------------
// Address: 0x004025C0
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
// Address: 0x0040267E
// Name: __initp_misc_invarg
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _initp_misc_invarg(void *enull)
{
  __pInvalidArgHandler = enull;
}

//------------------------------------------------------------------------------
// Address: 0x0040268D
// Name: __call_reportfault
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall _call_reportfault(
        unsigned int a1@<edi>,
        unsigned int a2@<esi>,
        int nDbgHookCode,
        unsigned int dwExceptionCode,
        unsigned int dwExceptionFlags)
{
  unsigned int v5; // ecx
  unsigned int v6; // edx
  unsigned int v7; // kr00_4
  BOOL v8; // edi
  _EXCEPTION_POINTERS ExceptionPointers; // [esp+8h] [ebp-328h] BYREF
  _EXCEPTION_RECORD ExceptionRecord; // [esp+10h] [ebp-320h] BYREF
  _CONTEXT ContextRecord; // [esp+60h] [ebp-2D0h] BYREF
  unsigned int savedregs; // [esp+330h] [ebp+0h]
  void *retaddr; // [esp+334h] [ebp+4h] BYREF

  if ( nDbgHookCode != -1 )
    _crt_debugger_hook(_Reserved: nDbgHookCode);
  memset(dst: (int)&ExceptionRecord.ExceptionFlags, value: nullptr, count: 0x4Cu);
  ExceptionPointers.ExceptionRecord = &ExceptionRecord;
  ExceptionPointers.ContextRecord = &ContextRecord;
  ContextRecord.Eax = (unsigned int)&ContextRecord;
  ContextRecord.Ecx = v5;
  ContextRecord.Edx = v6;
  ContextRecord.Ebx = nDbgHookCode;
  ContextRecord.Esi = a2;
  ContextRecord.Edi = a1;
  LOWORD(ContextRecord.SegSs) = __SS__;
  LOWORD(ContextRecord.SegCs) = __CS__;
  LOWORD(ContextRecord.SegDs) = __DS__;
  LOWORD(ContextRecord.SegEs) = __ES__;
  LOWORD(ContextRecord.SegFs) = __FS__;
  LOWORD(ContextRecord.SegGs) = __GS__;
  v7 = __readeflags();
  ContextRecord.EFlags = v7;
  ContextRecord.Esp = (unsigned int)&retaddr;
  ContextRecord.ContextFlags = 65537;
  ContextRecord.Eip = (unsigned int)retaddr;
  ContextRecord.Ebp = savedregs;
  ExceptionRecord.ExceptionCode = dwExceptionCode;
  ExceptionRecord.ExceptionFlags = dwExceptionFlags;
  ExceptionRecord.ExceptionAddress = retaddr;
  v8 = IsDebuggerPresent();
  SetUnhandledExceptionFilter(lpTopLevelExceptionFilter: nullptr);
  if ( UnhandledExceptionFilter(ExceptionInfo: &ExceptionPointers) == 0 && !v8 && nDbgHookCode != -1 )
    _crt_debugger_hook(_Reserved: nDbgHookCode);
}

//------------------------------------------------------------------------------
// Address: 0x004027B6
// Name: __invoke_watson
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall __noreturn _invoke_watson(unsigned int a1@<edi>)
{
  HANDLE CurrentProcess; // eax

  _call_reportfault(a1, a2: 0xC0000417, nDbgHookCode: 2, dwExceptionCode: 0xC0000417, dwExceptionFlags: 1u);
  CurrentProcess = GetCurrentProcess();
  TerminateProcess(hProcess: CurrentProcess, uExitCode: 0xC0000417);
}

//------------------------------------------------------------------------------
// Address: 0x004027DB
// Name: __invalid_parameter
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall _invalid_parameter(unsigned int a1@<edi>)
{
  void (*v1)(void); // eax

  v1 = (void (*)(void))DecodePointer(Ptr: __pInvalidArgHandler);
  if ( v1 == nullptr )
    _invoke_watson(a1);
  v1();
}

//------------------------------------------------------------------------------
// Address: 0x00402808
// Name: __invalid_parameter_noinfo
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _invalid_parameter_noinfo()
{
  unsigned int v0; // edi

  _invalid_parameter(a1: v0);
}

//------------------------------------------------------------------------------
// Address: 0x00402818
// Name: _tzset_nolock
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall tzset_nolock(unsigned int a1@<edi>)
{
  unsigned __int8 *v1; // eax
  unsigned __int8 *v2; // esi
  int v3; // eax
  int v4; // eax
  int v5; // eax
  int v6; // edi
  int v7; // edi
  int v8; // edi
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
    _invoke_watson(a1);
  }
  lc_cp = ___lc_codepage_func();
  tzapiused = 0;
  a1 = -1;
  dstend.yr = -1;
  dststart.yr = -1;
  v1 = (unsigned __int8 *)_getenv_helper_nolock(option: "TZ");
  v2 = v1;
  if ( v1 == nullptr || *v1 == 0 )
  {
    if ( lastTZ != nullptr )
    {
      free(pBlock: lastTZ);
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
    strcmp(str1: v1, str2: (unsigned __int8 *)lastTZ);
    if ( v3 == 0 )
    {
LABEL_30:
      nochange = 1;
      goto LABEL_31;
    }
    if ( lastTZ != nullptr )
      free(pBlock: lastTZ);
  }
  strlen(buf: v2);
  lastTZ = (char *)_malloc_crt(cb: v4 + 1);
  if ( lastTZ == nullptr )
    goto LABEL_30;
  strlen(buf: v2);
  if ( strcpy_s(_Dst: lastTZ, _SizeInBytes: v5 + 1, _Src: (const char *)v2) != 0 )
    goto LABEL_12;
LABEL_31:
  v6 = timezone;
  *__timezone() = v6;
  v7 = daylight;
  *__daylight() = v7;
  v8 = dstbias;
  *__dstbias() = v8;
  ms_exc.registration.TryLevel = -2;
  _unlock(locknum: 7);
  if ( nochange == 0 )
  {
    a1 = (unsigned int)tzname;
    if ( strncpy_s(_Dst: *tzname, _SizeInBytes: 0x40u, _Src: (const char *)v2, _Count: 3u) != 0 )
      goto LABEL_12;
    v9 = (const char *)(v2 + 3);
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
      if ( strncpy_s(_Dst: *(char **)(a1 + 4), _SizeInBytes: 0x40u, _Src: v9, _Count: 3u) != 0 )
        goto LABEL_12;
    }
    else
    {
      **(_BYTE **)(a1 + 4) = 0;
    }
    v13 = timezone;
    *__timezone() = v13;
    v14 = daylight;
    *__daylight() = v14;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00402D22
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
    _invoke_watson(a1: (unsigned int)tb);
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
// Address: 0x00402EF9
// Name: ___tzset
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall __tzset(unsigned int a1@<edi>)
{
  if ( first_time == 0 )
  {
    _lock(locknum: 6);
    if ( first_time == 0 )
    {
      tzset_nolock(a1);
      ++first_time;
    }
    _unlock(locknum: 6);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00402F48
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
// Address: 0x00402F89
// Name: __gmtime64_s
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _gmtime64_s(tm *ptm, const __int64 *timp)
{
  unsigned int v4; // ecx
  unsigned int v5; // eax
  __int64 v6; // rax
  __int64 v7; // rax
  unsigned int v8; // edi
  int v9; // eax
  int v10; // et0
  int v11; // et0
  unsigned int v12; // edi
  unsigned int v13; // et0
  int *v14; // edx
  int tm_yday; // eax
  int i; // ecx
  int v17; // ecx
  signed __int64 v18; // kr28_8
  __int64 caltim; // [esp+4h] [ebp-10h]
  unsigned int caltim_4; // [esp+8h] [ebp-Ch]
  int v21; // [esp+Ch] [ebp-8h]
  int islpyr; // [esp+10h] [ebp-4h]
  int tmptim; // [esp+1Ch] [ebp+8h]

  islpyr = 0;
  if ( ptm == nullptr || (memset(dst: (int)ptm, value: (unsigned __int8 *)0xFF, count: sizeof(tm)), timp == nullptr) )
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return 22;
  }
  v4 = *(_DWORD *)timp;
  v5 = *((_DWORD *)timp + 1);
  LODWORD(caltim) = *(_DWORD *)timp;
  if ( *timp < -43200 || __SPAIR64__(v5, v4) > 0x7934126CFLL )
  {
    *_errno() = 22;
    return 22;
  }
  v6 = __SPAIR64__(v5, v4) / 31536000;
  v21 = v6 + 69;
  tmptim = v6 + 70;
  v7 = 86400 * (-365LL * (int)v6 - (((int)v6 + 369) / 400 - ((int)v6 + 69) / 100 + ((int)v6 + 69) / 4 - 17));
  HIDWORD(caltim) = *((_DWORD *)timp + 1);
  v8 = v7 + caltim;
  HIDWORD(caltim) = (unsigned __int64)(v7 + caltim) >> 32;
  if ( caltim >= 0 )
  {
    if ( (tmptim % 4 != 0 || tmptim % 100 == 0) && (tmptim + 1900) % 400 != 0 )
      goto LABEL_18;
    goto LABEL_17;
  }
  v9 = v21;
  v10 = (__PAIR64__(HIDWORD(caltim), v8) + 31536000) >> 32;
  v8 += 31536000;
  HIDWORD(caltim) = v10;
  tmptim = v21;
  if ( v21 % 4 == 0 )
  {
    if ( v21 % 100 != 0 )
    {
LABEL_13:
      v11 = (__PAIR64__(HIDWORD(caltim), v8) + 86400) >> 32;
      v8 += 86400;
      HIDWORD(caltim) = v11;
LABEL_17:
      islpyr = 1;
      goto LABEL_18;
    }
    v9 = v21;
  }
  if ( (v9 + 1900) % 400 == 0 )
    goto LABEL_13;
LABEL_18:
  ptm->tm_year = tmptim;
  ptm->tm_yday = __SPAIR64__(HIDWORD(caltim), v8) / 86400;
  v13 = (-86400LL * (int)(__SPAIR64__(HIDWORD(caltim), v8) / 86400) + __PAIR64__(HIDWORD(caltim), v8)) >> 32;
  v12 = __SPAIR64__(HIDWORD(caltim), v8) % 86400;
  caltim_4 = v13;
  v14 = _lpdays;
  if ( islpyr == 0 )
    v14 = _days;
  tm_yday = ptm->tm_yday;
  for ( i = 1; v14[i] < tm_yday; ++i )
    ;
  v17 = i - 1;
  ptm->tm_mon = v17;
  ptm->tm_mday = tm_yday - v14[v17];
  ptm->tm_wday = (int)(*timp / 86400 + 4) % 7;
  ptm->tm_hour = __SPAIR64__(caltim_4, v12) / 3600;
  v18 = -3600LL * (int)(__SPAIR64__(caltim_4, v12) / 3600) + __PAIR64__(caltim_4, v12);
  ptm->tm_min = v18 / 60;
  ptm->tm_sec = v18 % 60;
  ptm->tm_isdst = 0;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x004031C2
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
// Address: 0x004031EF
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
// Address: 0x0040321C
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
// Address: 0x00403249
// Name: ___daylight
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int *__cdecl __daylight()
{
  return &_daylight;
}

//------------------------------------------------------------------------------
// Address: 0x0040324F
// Name: ___dstbias
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int *__cdecl __dstbias()
{
  return &_dstbias;
}

//------------------------------------------------------------------------------
// Address: 0x00403255
// Name: ___timezone
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int *__cdecl __timezone()
{
  return &_timezone;
}

//------------------------------------------------------------------------------
// Address: 0x0040325B
// Name: ___tzname
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char **__cdecl __tzname()
{
  return _tzname;
}

//------------------------------------------------------------------------------
// Address: 0x00403261
// Name: __get_errno_from_oserr
// Source: linker_block_proximity
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
// Address: 0x004032A3
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
// Address: 0x004032B6
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
// Address: 0x004032C9
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
// Address: 0x004032F0
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
// Address: 0x004033A0
// Name: __allrem
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned __int64 __stdcall _allrem(unsigned __int64 a1, __int64 a2)
{
  int v2; // edi
  int v3; // eax
  unsigned __int64 v4; // rtt
  unsigned __int64 result; // rax
  unsigned __int64 v6; // rcx
  unsigned __int64 v7; // rax
  unsigned int v8; // eax
  int v9; // ecx
  bool v10; // cf
  unsigned __int64 v11; // rax

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
    v3 = -HIDWORD(a2) - ((_DWORD)a2 != 0);
    HIDWORD(a2) = v3;
    LODWORD(a2) = -(int)a2;
  }
  if ( v3 == 0 )
  {
    LODWORD(v4) = a1;
    HIDWORD(v4) = HIDWORD(a1) % (unsigned int)a2;
    result = v4 % (unsigned int)a2;
    if ( v2 - 1 < 0 )
      return result;
    return -(__int64)result;
  }
  v6 = __PAIR64__(v3, a2);
  v7 = a1;
  do
  {
    v6 >>= 1;
    v7 >>= 1;
  }
  while ( HIDWORD(v6) != 0 );
  v8 = v7 / (unsigned int)v6;
  v9 = HIDWORD(a2) * v8;
  v11 = (unsigned int)a2 * (unsigned __int64)v8;
  v10 = __CFADD__(v9, HIDWORD(v11));
  HIDWORD(v11) += v9;
  if ( v10 || v11 > a1 )
    v11 -= a2;
  result = v11 - a1;
  if ( v2 - 1 < 0 )
    return -(__int64)result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00403452
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
    v3 = _malloc_crt(cb: 0x24u);
    v1->_gmtimebuf = v3;
    if ( v3 != nullptr )
      return v1->_gmtimebuf;
  }
  *_errno() = 12;
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x00403490
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
// Address: 0x004034F8
// Name: _free
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl free(void *pBlock)
{
  int *v1; // esi
  DWORD LastError; // eax

  if ( pBlock != nullptr && !HeapFree(hHeap: _crtheap, dwFlags: 0, lpMem: pBlock) )
  {
    v1 = _errno();
    LastError = GetLastError();
    *v1 = _get_errno_from_oserr(oserrno: LastError);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00403532
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
// Address: 0x004035CE
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
// Address: 0x00403692
// Name: __fileno
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _fileno(_iobuf *stream)
{
  if ( stream != nullptr )
    return stream->_file;
  *_errno() = 22;
  _invalid_parameter_noinfo();
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004036B8
// Name: __freebuf
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _freebuf(_iobuf *stream)
{
  int flag; // eax

  flag = stream->_flag;
  if ( (flag & 0x83) != 0 && (flag & 8) != 0 )
  {
    free(pBlock: stream->_base);
    stream->_flag &= 0xFFFFFBF7;
    stream->_ptr = nullptr;
    stream->_base = nullptr;
    stream->_cnt = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004036E9
// Name: ___iob_func
// Source: linker_block_proximity
//------------------------------------------------------------------------------
_iobuf *__cdecl __iob_func()
{
  return _iob;
}

//------------------------------------------------------------------------------
// Address: 0x004036EF
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
  v1 = (void **)_calloc_crt(count: v0, size: 4u);
  __piob = v1;
  if ( v1 == nullptr )
  {
    _nstream = 20;
    v1 = (void **)_calloc_crt(count: 0x14u, size: 4u);
    __piob = v1;
    if ( v1 == nullptr )
      return 26;
  }
  v3 = 0;
  v4 = _iob;
  while ( 1 )
  {
    v1[v3++] = v4++;
    if ( (int)v4 >= (int)&locktable )
      break;
    v1 = __piob;
  }
  v5 = 0;
  v6 = &unk_411240;
  do
  {
    osfhnd = __pioinfo[v5 >> 5][v5 & 0x1F].osfhnd;
    if ( osfhnd == -1 || osfhnd == -2 || osfhnd == 0 )
      *v6 = -2;
    v6 += 8;
    ++v5;
  }
  while ( (int)v6 < (int)dword_4112A0 );
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x004037A0
// Name: ___endstdio
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __endstdio()
{
  _flushall();
  if ( _exitflag != 0 )
    _fcloseall();
  free(pBlock: __piob);
}

//------------------------------------------------------------------------------
// Address: 0x004037C0
// Name: __lock_file
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _lock_file(_iobuf *pf)
{
  if ( pf < _iob || pf > &stru_411490 )
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
// Address: 0x00403801
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
// Address: 0x00403833
// Name: __unlock_file
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _unlock_file(_iobuf *pf)
{
  if ( pf < _iob || pf > &stru_411490 )
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
// Address: 0x0040386F
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
// Address: 0x004038E5
// Name: __SEH_epilog4
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void _SEH_epilog4()
{
  __asm { retn }
}

//------------------------------------------------------------------------------
// Address: 0x00403A8F
// Name: __write_nolock
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _write_nolock(int fh, char *buf, unsigned int cnt)
{
  ioinfo **v4; // ebx
  ioinfo *v5; // eax
  int v6; // edi
  char v7; // cl
  BOOL v8; // esi
  UINT ConsoleCP; // eax
  char *v10; // ebx
  char v11; // cl
  ioinfo **v12; // esi
  int v13; // eax
  int v14; // eax
  DWORD v15; // eax
  signed int v16; // esi
  ioinfo *v17; // eax
  int v18; // esi
  ioinfo *v19; // ecx
  char v20; // dl
  char *v21; // ebx
  unsigned int v22; // esi
  unsigned int v23; // ecx
  char *v24; // eax
  char v25; // dl
  signed int v26; // esi
  char *v27; // ebx
  unsigned int v28; // ecx
  char *v29; // eax
  int v30; // edx
  signed int v31; // esi
  unsigned int v32; // ecx
  WCHAR *v33; // eax
  int v34; // edx
  int v35; // esi
  int v36; // ebx
  BOOL v37; // [esp+8h] [ebp-1AE4h]
  unsigned int Mode; // [esp+Ch] [ebp-1AE0h] BYREF
  ioinfo **v39; // [esp+10h] [ebp-1ADCh]
  unsigned int v40; // [esp+14h] [ebp-1AD8h] BYREF
  unsigned int NumberOfBytesWritten; // [esp+18h] [ebp-1AD4h] BYREF
  int v42; // [esp+1Ch] [ebp-1AD0h]
  char *s; // [esp+20h] [ebp-1ACCh]
  unsigned int v44; // [esp+24h] [ebp-1AC8h]
  char v45; // [esp+2Bh] [ebp-1AC1h]
  unsigned int v46; // [esp+2Ch] [ebp-1AC0h]
  wchar_t pwc[2]; // [esp+30h] [ebp-1ABCh] BYREF
  char Buffer[1704]; // [esp+34h] [ebp-1AB8h] BYREF
  char v49[3416]; // [esp+6DCh] [ebp-1410h] BYREF
  WCHAR WideCharStr[854]; // [esp+1434h] [ebp-6B8h] BYREF
  char MultiByteStr[8]; // [esp+1AE0h] [ebp-Ch] BYREF

  s = buf;
  v44 = 0;
  v42 = 0;
  if ( cnt == 0 )
    return 0;
  if ( buf == nullptr )
  {
    *__doserrno() = 0;
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return -1;
  }
  v4 = &__pioinfo[fh >> 5];
  v5 = *v4;
  v6 = (fh & 0x1F) << 6;
  v7 = (char)(2 * *((_BYTE *)*v4 + v6 + 36)) >> 1;
  v39 = v4;
  v45 = v7;
  if ( (v7 == 2 || v7 == 1) && (cnt & 1) != 0 )
  {
    *__doserrno() = 0;
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return -1;
  }
  if ( (*(&v5->osfile + v6) & 0x20) != 0 )
    _lseeki64_nolock(fh, pos: 0, mthd: 2);
  if ( _isatty(fh) != 0 && *(&(*v4)->osfile + v6) < 0 )
  {
    v8 = _getptd()->ptlocinfo->lc_handle[2] == 0;
    if ( GetConsoleMode(hConsoleHandle: *(HANDLE *)((char *)&(*v4)->osfhnd + v6), lpMode: &Mode) && (!v8 || v45 != 0) )
    {
      ConsoleCP = GetConsoleCP();
      v10 = s;
      Mode = ConsoleCP;
      NumberOfBytesWritten = 0;
      v46 = 0;
      while ( 1 )
      {
        if ( v45 != 0 )
        {
          if ( v45 == 1 || v45 == 2 )
          {
            v18 = *(unsigned __int16 *)v10;
            v10 += 2;
            v46 += 2;
            *(_DWORD *)pwc = v18;
            v37 = v18 == 10;
          }
          if ( v45 == 1 || v45 == 2 )
          {
            if ( _putwch_nolock(ch: pwc[0]) != pwc[0] )
              goto LABEL_85;
            v44 += 2;
            if ( v37 )
            {
              wcscpy(pwc, L"\r");
              if ( _putwch_nolock(ch: 0xDu) != pwc[0] )
                goto LABEL_85;
              ++v44;
              ++v42;
            }
          }
          goto LABEL_43;
        }
        v11 = *v10;
        v12 = v39;
        v37 = *v10 == 10;
        v13 = (int)*v39 + v6;
        if ( *(_DWORD *)(v13 + 56) != 0 )
        {
          MultiByteStr[0] = *(_BYTE *)(v13 + 52);
          MultiByteStr[1] = v11;
          *(_DWORD *)(v13 + 56) = 0;
          v14 = mbtowc(pwc, s: MultiByteStr, n: 2u);
        }
        else
        {
          if ( isleadbyte(c: v11) != 0 )
          {
            if ( cnt + s - v10 <= 1 )
            {
              v19 = *v12;
              v20 = *v10;
              ++v44;
              *(&v19->dbcsBuffer + v6) = v20;
              *(int *)((char *)&(*v12)->dbcsBufferUsed + v6) = 1;
              goto LABEL_86;
            }
            if ( mbtowc(pwc, s: v10, n: 2u) == -1 )
              goto LABEL_86;
            ++v10;
            ++v46;
            goto LABEL_27;
          }
          v14 = mbtowc(pwc, s: v10, n: 1u);
        }
        if ( v14 == -1 )
          goto LABEL_86;
LABEL_27:
        ++v10;
        ++v46;
        v15 = WideCharToMultiByte(
                CodePage: Mode,
                dwFlags: 0,
                lpWideCharStr: pwc,
                cchWideChar: 1,
                lpMultiByteStr: MultiByteStr,
                cbMultiByte: 5,
                lpDefaultChar: nullptr,
                lpUsedDefaultChar: nullptr);
        v16 = v15;
        if ( v15 == 0 )
          goto LABEL_86;
        if ( !WriteFile(
                hFile: *(HANDLE *)((char *)&(*v39)->osfhnd + v6),
                lpBuffer: MultiByteStr,
                nNumberOfBytesToWrite: v15,
                lpNumberOfBytesWritten: &NumberOfBytesWritten,
                lpOverlapped: nullptr) )
          goto LABEL_85;
        v44 = v42 + v46;
        if ( (int)NumberOfBytesWritten < v16 )
          goto LABEL_86;
        if ( v37 )
        {
          v17 = *v39;
          MultiByteStr[0] = 13;
          if ( !WriteFile(
                  hFile: *(HANDLE *)((char *)&v17->osfhnd + v6),
                  lpBuffer: MultiByteStr,
                  nNumberOfBytesToWrite: 1u,
                  lpNumberOfBytesWritten: &NumberOfBytesWritten,
                  lpOverlapped: nullptr) )
            goto LABEL_85;
          if ( (int)NumberOfBytesWritten < 1 )
            goto LABEL_86;
          ++v42;
          ++v44;
        }
LABEL_43:
        if ( v46 >= cnt )
          goto LABEL_86;
      }
    }
  }
  if ( *(&(*v4)->osfile + v6) >= 0 )
  {
    if ( WriteFile(
           hFile: (HANDLE)(*v4)[fh & 0x1F].osfhnd,
           lpBuffer: s,
           nNumberOfBytesToWrite: cnt,
           lpNumberOfBytesWritten: &v40,
           lpOverlapped: nullptr) )
    {
      *(_DWORD *)pwc = 0;
      v44 = v40;
      goto LABEL_86;
    }
  }
  else
  {
    *(_DWORD *)pwc = 0;
    if ( v45 != 0 )
    {
      if ( v45 == 2 )
      {
        v27 = s;
        while ( 1 )
        {
          v46 = 0;
          v28 = v27 - s;
          v29 = Buffer;
          do
          {
            if ( v28 >= cnt )
              break;
            v30 = *(unsigned __int16 *)v27;
            v27 += 2;
            v28 += 2;
            Mode = (unsigned int)v27;
            if ( v30 == 10 )
            {
              v42 += 2;
              *(_WORD *)v29 = 13;
              v27 = (char *)Mode;
              v29 += 2;
              v46 += 2;
            }
            v46 += 2;
            *(_WORD *)v29 = v30;
            v29 += 2;
          }
          while ( v46 < 0x13FE );
          v31 = v29 - Buffer;
          if ( !WriteFile(
                  hFile: *(HANDLE *)((char *)&(*v39)->osfhnd + v6),
                  lpBuffer: Buffer,
                  nNumberOfBytesToWrite: v29 - Buffer,
                  lpNumberOfBytesWritten: &v40,
                  lpOverlapped: nullptr) )
            break;
          v44 += v40;
          if ( (int)v40 < v31 || v27 - s >= cnt )
            goto LABEL_86;
        }
      }
      else
      {
        NumberOfBytesWritten = (unsigned int)s;
        while ( 1 )
        {
          v46 = 0;
          v32 = NumberOfBytesWritten - (_DWORD)s;
          v33 = WideCharStr;
          do
          {
            if ( v32 >= cnt )
              break;
            v34 = *(unsigned __int16 *)NumberOfBytesWritten;
            NumberOfBytesWritten += 2;
            v32 += 2;
            if ( v34 == 10 )
            {
              *v33++ = 13;
              v46 += 2;
            }
            v46 += 2;
            *v33++ = v34;
          }
          while ( v46 < 0x6A8 );
          v35 = 0;
          v36 = WideCharToMultiByte(
                  CodePage: 0xFDE9u,
                  dwFlags: 0,
                  lpWideCharStr: WideCharStr,
                  cchWideChar: v33 - WideCharStr,
                  lpMultiByteStr: v49,
                  cbMultiByte: 3413,
                  lpDefaultChar: nullptr,
                  lpUsedDefaultChar: nullptr);
          if ( v36 == 0 )
            break;
          while ( WriteFile(
                    hFile: *(HANDLE *)((char *)&(*v39)->osfhnd + v6),
                    lpBuffer: &v49[v35],
                    nNumberOfBytesToWrite: v36 - v35,
                    lpNumberOfBytesWritten: &v40,
                    lpOverlapped: nullptr) )
          {
            v35 += v40;
            if ( v36 <= v35 )
              goto LABEL_80;
          }
          *(_DWORD *)pwc = GetLastError();
LABEL_80:
          if ( v36 <= v35 )
          {
            v44 = NumberOfBytesWritten - (_DWORD)s;
            if ( NumberOfBytesWritten - (unsigned int)s < cnt )
              continue;
          }
          goto LABEL_86;
        }
      }
    }
    else
    {
      v21 = s;
      while ( 1 )
      {
        v22 = 0;
        v23 = v21 - s;
        v24 = Buffer;
        do
        {
          if ( v23 >= cnt )
            break;
          v25 = *v21++;
          ++v23;
          Mode = (unsigned int)v21;
          if ( v25 == 10 )
          {
            ++v42;
            *v24++ = 13;
            ++v22;
          }
          *v24++ = v25;
          ++v22;
        }
        while ( v22 < 0x13FF );
        v26 = v24 - Buffer;
        if ( !WriteFile(
                hFile: *(HANDLE *)((char *)&(*v39)->osfhnd + v6),
                lpBuffer: Buffer,
                nNumberOfBytesToWrite: v24 - Buffer,
                lpNumberOfBytesWritten: &v40,
                lpOverlapped: nullptr) )
          break;
        v44 += v40;
        if ( (int)v40 < v26 || v21 - s >= cnt )
          goto LABEL_86;
      }
    }
  }
LABEL_85:
  *(_DWORD *)pwc = GetLastError();
LABEL_86:
  if ( v44 == 0 )
  {
    if ( *(_DWORD *)pwc != 0 )
    {
      if ( *(_DWORD *)pwc == 5 )
      {
        *_errno() = 9;
        *__doserrno() = 5;
      }
      else
      {
        _dosmaperr(oserrno: *(unsigned int *)pwc);
      }
    }
    else
    {
      if ( (*(&(*v39)->osfile + v6) & 0x40) != 0 && *s == 26 )
        return 0;
      *_errno() = 28;
      *__doserrno() = 0;
    }
    return -1;
  }
  return v44 - v42;
}

//------------------------------------------------------------------------------
// Address: 0x0040418C
// Name: __write
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _write(int fh, char *buf, unsigned int cnt)
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
    _invalid_parameter_noinfo();
    return -1;
  }
  __lock_fhandle(fh);
  if ( (*(&(*v4)->osfile + v5) & 1) != 0 )
  {
    r = _write_nolock(fh, buf, cnt);
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
// Address: 0x00404260
// Name: __commit
// Source: linker_block_proximity
//------------------------------------------------------------------------------
DWORD __cdecl _commit(int filedes)
{
  ioinfo **v2; // edi
  int v3; // esi
  void *osfhandle; // eax
  DWORD retval; // [esp+14h] [ebp-1Ch]

  if ( filedes == -2 )
  {
    *_errno() = 9;
    return -1;
  }
  if ( filedes < 0
    || filedes >= _nhandle
    || (v2 = &__pioinfo[filedes >> 5], (*(&(*v2)->osfile + (v3 = (filedes & 0x1F) << 6)) & 1) == 0) )
  {
    *_errno() = 9;
    _invalid_parameter_noinfo();
    return -1;
  }
  __lock_fhandle(fh: filedes);
  if ( (*(&(*v2)->osfile + v3) & 1) != 0 )
  {
    osfhandle = (void *)_get_osfhandle(fh: filedes);
    if ( FlushFileBuffers(hFile: osfhandle) )
      retval = 0;
    else
      retval = GetLastError();
    if ( retval == 0 )
      goto good;
    *__doserrno() = retval;
  }
  *_errno() = 9;
  retval = -1;
good:
  _unlock_fhandle(fh: filedes);
  return retval;
}

//------------------------------------------------------------------------------
// Address: 0x00404339
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
// Address: 0x00404383
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
      free(pBlock: v1);
      *v0 = nullptr;
    }
    v0 += 2;
  }
  while ( (int)v0 < (int)&__badioinfo );
  v2 = &locktable;
  do
  {
    if ( *v2 != nullptr && v2[1] == (LPCRITICAL_SECTION)1 )
      DeleteCriticalSection(lpCriticalSection: *v2);
    v2 += 2;
  }
  while ( (int)v2 < (int)&__badioinfo );
}

//------------------------------------------------------------------------------
// Address: 0x004043DA
// Name: __unlock
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _unlock(int locknum)
{
  LeaveCriticalSection(lpCriticalSection: *(&locktable + 2 * locknum));
}

//------------------------------------------------------------------------------
// Address: 0x004043F1
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
  v3 = (_RTL_CRITICAL_SECTION *)_malloc_crt(cb: 0x18u);
  if ( v3 != nullptr )
  {
    _lock(locknum: 10);
    if ( *v1 != nullptr )
    {
      free(pBlock: v3);
    }
    else if ( InitializeCriticalSectionAndSpinCount(lpCriticalSection: v3, dwSpinCount: 0xFA0u) )
    {
      *v1 = v3;
    }
    else
    {
      free(pBlock: v3);
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
// Address: 0x004044B3
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
// Address: 0x004044E6
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

  v1 = _fileno(stream: str);
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
  if ( *v3 != nullptr || (v4 = (char *)_malloc_crt(cb: 0x1000u), *v3 = v4, v4 != nullptr) )
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
// Address: 0x00404582
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
// Address: 0x004045B6
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
  v0 = (ioinfo *)_calloc_crt(count: 0x20u, size: 0x40u);
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
      v4 = (char **)&unk_413684;
      while ( 1 )
      {
        v5 = (char *)_calloc_crt(count: 0x20u, size: 0x40u);
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
// Address: 0x004047FB
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
// Address: 0x00404882
// Name: write_char
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall write_char(int ch@<eax>, _iobuf *f@<ecx>, int *pnumwritten@<esi>)
{
  bool v3; // sf

  if ( ((f->_flag & 0x40) == 0 || f->_base != nullptr)
    && ((v3 = f->_cnt - 1 < 0, --f->_cnt, v3)
      ? (ch = _flsbuf((char)ch, str: f))
      : (*f->_ptr = ch, ++f->_ptr, ch = (unsigned __int8)ch),
        ch == -1) )
  {
    *pnumwritten = -1;
  }
  else
  {
    ++*pnumwritten;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004048B5
// Name: write_string
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall write_string(char *string@<ecx>, _iobuf *f@<edi>, int *pnumwritten@<eax>, int len)
{
  int *v4; // esi
  int *v6; // eax

  v4 = pnumwritten;
  if ( (f->_flag & 0x40) == 0 || f->_base != nullptr )
  {
    while ( len > 0 )
    {
      LOBYTE(pnumwritten) = *string;
      --len;
      write_char(ch: (int)pnumwritten, f, pnumwritten: v4);
      ++string;
      if ( *v4 == -1 )
      {
        v6 = _errno();
        if ( *v6 != 42 )
          return;
        LOBYTE(v6) = 63;
        write_char(ch: (int)v6, f, pnumwritten: v4);
      }
    }
  }
  else
  {
    *pnumwritten += len;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00404905
// Name: __output_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _output_l(_iobuf *stream, const char *format, localeinfo_struct *plocinfo, char *argptr)
{
  int *v4; // ebx
  const char *v5; // edi
  int v7; // eax
  ioinfo *v8; // ecx
  ioinfo *v9; // eax
  char v10; // dl
  STATE v11; // ecx
  char *v12; // edi
  int v13; // eax
  char v14; // al
  bool v15; // zf
  int v16; // eax
  _output_l::__l2::<unnamed_type_buffer> *p_buffer; // edi
  int v18; // ecx
  _output_l::__l2::<unnamed_type_text> v19; // ebx
  char *sz; // eax
  char *v21; // ebx
  __int16 *v22; // eax
  _output_l::__l2::<unnamed_type_text> v23; // ecx
  signed int v24; // eax
  _WORD *v25; // esi
  __int64 v26; // rax
  int *v27; // ebx
  int v28; // esi
  char *v29; // eax
  int v30; // eax
  char *v31; // ebx
  void (__cdecl *v32)(_CRT_DOUBLE *, _output_l::__l2::<unnamed_type_buffer> *, int, int, int, int, _LocaleUpdate *); // eax
  int v33; // ebx
  void (__cdecl *v34)(_output_l::__l2::<unnamed_type_buffer> *, _LocaleUpdate *); // eax
  void (__cdecl *v35)(_output_l::__l2::<unnamed_type_buffer> *, _LocaleUpdate *); // eax
  unsigned int v36; // ebx
  unsigned int v37; // edi
  char *j; // esi
  int v39; // eax
  unsigned __int64 v40; // rcx
  int v41; // ecx
  char *v42; // eax
  _BYTE *v43; // esi
  _BYTE *i; // eax
  int v45; // eax
  int v46; // ebx
  int v47; // edi
  _iobuf *v48; // edi
  int v49; // eax
  int v50; // ebx
  wchar_t *v51; // esi
  int v52; // eax
  int v53; // ebx
  char v54; // al
  int v55; // [esp-14h] [ebp-298h]
  int v56; // [esp-10h] [ebp-294h]
  unsigned __int64 v57; // [esp-10h] [ebp-294h]
  int v58; // [esp-Ch] [ebp-290h]
  int v59; // [esp-8h] [ebp-28Ch]
  wchar_t v60; // [esp-4h] [ebp-288h]
  _CRT_DOUBLE tmp; // [esp+Ch] [ebp-278h] BYREF
  int capexp; // [esp+14h] [ebp-270h]
  STATE state; // [esp+18h] [ebp-26Ch]
  int padding; // [esp+20h] [ebp-264h]
  int retval; // [esp+24h] [ebp-260h] BYREF
  _LocaleUpdate _loc_update; // [esp+28h] [ebp-25Ch] BYREF
  char *heapbuf; // [esp+38h] [ebp-24Ch]
  int hexadd; // [esp+3Ch] [ebp-248h]
  int no_output; // [esp+40h] [ebp-244h]
  _iobuf *f; // [esp+44h] [ebp-240h]
  char *v71; // [esp+48h] [ebp-23Ch]
  int bufferiswide; // [esp+4Ch] [ebp-238h]
  int fldwidth; // [esp+50h] [ebp-234h]
  int prefixlen; // [esp+54h] [ebp-230h]
  char prefix[4]; // [esp+58h] [ebp-22Ch] BYREF
  char *v76; // [esp+5Ch] [ebp-228h]
  int charsout; // [esp+60h] [ebp-224h] BYREF
  int radix; // [esp+64h] [ebp-220h] BYREF
  _output_l::__l2::<unnamed_type_text> text; // [esp+68h] [ebp-21Ch]
  int precision; // [esp+6Ch] [ebp-218h]
  char v81; // [esp+73h] [ebp-211h]
  int flags; // [esp+74h] [ebp-210h]
  _output_l::__l2::<unnamed_type_buffer> buffer; // [esp+78h] [ebp-20Ch] BYREF
  char L_buffer[8]; // [esp+278h] [ebp-Ch] BYREF

  v4 = (int *)argptr;
  v5 = format;
  f = stream;
  v76 = argptr;
  hexadd = 0;
  flags = 0;
  fldwidth = 0;
  precision = 0;
  prefixlen = 0;
  no_output = 0;
  bufferiswide = 0;
  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  if ( stream != nullptr
    && ((stream->_flag & 0x40) != 0
     || ((v7 = _fileno(stream)) == -1 || v7 == -2 ? (v8 = &__badioinfo) : (v8 = &__pioinfo[v7 >> 5][v7 & 0x1F]),
         (*((_BYTE *)v8 + 36) & 0x7F) == 0
      && (v7 == -1 || v7 == -2 ? (v9 = &__badioinfo) : (v9 = &__pioinfo[v7 >> 5][v7 & 0x1F]), *((char *)v9 + 36) >= 0)))
    && format != nullptr )
  {
    v10 = *format;
    v11 = ST_NORMAL;
    charsout = 0;
    radix = 0;
    heapbuf = nullptr;
    v81 = v10;
    if ( v10 != 0 )
    {
      while ( 1 )
      {
        v12 = (char *)(v5 + 1);
        v71 = v12;
        if ( charsout < 0 )
          break;
        if ( (unsigned __int8)(v10 - 32) > 0x58u )
          v13 = 0;
        else
          v13 = byte_40E448[v10] & 0xF;
        state = __lookuptable[8 * v13 + v11] >> 4;
        switch ( state )
        {
          case ST_NORMAL:
            goto NORMAL_STATE;
          case ST_PERCENT:
            precision = -1;
            capexp = 0;
            no_output = 0;
            fldwidth = 0;
            prefixlen = 0;
            flags = 0;
            bufferiswide = 0;
            goto LABEL_224;
          case ST_FLAG:
            switch ( v10 )
            {
              case ' ':
                flags |= 2u;
                break;
              case '#':
                flags |= 0x80u;
                break;
              case '+':
                flags |= 1u;
                break;
              case '-':
                flags |= 4u;
                break;
              case '0':
                flags |= 8u;
                break;
              default:
                break;
            }
            goto LABEL_224;
          case ST_WIDTH:
            if ( v10 == 42 )
            {
              v76 = (char *)(v4 + 1);
              fldwidth = *v4;
              if ( fldwidth < 0 )
              {
                flags |= 4u;
                fldwidth = -fldwidth;
              }
            }
            else
            {
              fldwidth = 10 * fldwidth + v10 - 48;
            }
            goto LABEL_224;
          case ST_DOT:
            precision = 0;
            goto LABEL_224;
          case ST_PRECIS:
            if ( v10 == 42 )
            {
              v76 = (char *)(v4 + 1);
              precision = *v4;
              if ( precision < 0 )
                precision = -1;
            }
            else
            {
              precision = 10 * precision + v10 - 48;
            }
            goto LABEL_224;
          case ST_SIZE:
            switch ( v10 )
            {
              case 'I':
                v14 = *v12;
                if ( *v12 == 54 && v12[1] == 52 )
                {
                  flags |= 0x8000u;
                  v71 = v12 + 2;
                }
                else if ( v14 == 51 && v12[1] == 50 )
                {
                  flags &= ~0x8000u;
                  v71 = v12 + 2;
                }
                else if ( v14 != 100 && v14 != 105 && v14 != 111 && v14 != 117 && v14 != 120 && v14 != 88 )
                {
                  state = ST_NORMAL;
NORMAL_STATE:
                  bufferiswide = 0;
                  v16 = _isleadbyte_l(c: (unsigned __int8)v10, plocinfo: &_loc_update.localeinfo);
                  v15 = v16 == 0;
                  LOBYTE(v16) = v81;
                  if ( !v15 )
                  {
                    write_char(ch: v16, f, pnumwritten: &charsout);
                    LOBYTE(v16) = *v12;
                    v71 = v12 + 1;
                    if ( (_BYTE)v16 == 0 )
                      goto LABEL_2;
                  }
                  write_char(ch: v16, f, pnumwritten: &charsout);
                }
                break;
              case 'h':
                flags |= 0x20u;
                break;
              case 'l':
                if ( *v12 == 108 )
                {
                  flags |= 0x1000u;
                  v71 = v12 + 1;
                }
                else
                {
                  flags |= 0x10u;
                }
                break;
              case 'w':
                flags |= 0x800u;
                break;
              default:
                break;
            }
            goto LABEL_224;
          case ST_TYPE:
            if ( v10 <= 100 )
            {
              if ( v10 == 100 )
              {
LABEL_118:
                flags |= 0x40u;
                goto LABEL_119;
              }
              if ( v10 > 83 )
              {
                if ( v10 == 88 )
                  goto LABEL_140;
                if ( v10 == 90 )
                {
                  v22 = (__int16 *)*v4;
                  v76 = (char *)(v4 + 1);
                  if ( v22 != nullptr && (v23.sz = *(char **)(v22 + 2), v23.sz != nullptr) )
                  {
                    v24 = *v22;
                    text.sz = v23.sz;
                    if ( (flags & 0x800) != 0 )
                    {
                      v24 /= 2;
                      bufferiswide = 1;
                    }
                    else
                    {
                      bufferiswide = 0;
                    }
                  }
                  else
                  {
                    text.sz = __nullstring;
                    strlen(buf: (unsigned __int8 *)__nullstring);
                  }
                  goto LABEL_189;
                }
                if ( v10 != 97 )
                {
                  if ( v10 != 99 )
                    goto LABEL_190;
                  goto LABEL_93;
                }
              }
              else
              {
                if ( v10 == 83 )
                {
                  if ( (flags & 0x830) == 0 )
                    flags |= 0x800u;
                  goto LABEL_83;
                }
                if ( v10 != 65 )
                {
                  if ( v10 != 67 )
                  {
                    if ( v10 != 69 && v10 != 71 )
                      goto LABEL_190;
                    goto LABEL_76;
                  }
                  if ( (flags & 0x830) == 0 )
                    flags |= 0x800u;
LABEL_93:
                  v21 = (char *)(v4 + 1);
                  v76 = v21;
                  if ( (flags & 0x810) != 0 )
                  {
                    if ( wctomb_s(pRetValue: &radix, dst: buffer.sz, sizeInBytes: 0x200u, wchar: *((_WORD *)v21 - 2)) != 0 )
                      no_output = 1;
                  }
                  else
                  {
                    buffer.sz[0] = *(v21 - 4);
                    radix = 1;
                  }
                  text.sz = (char *)&buffer;
                  goto LABEL_190;
                }
LABEL_76:
                v10 += 32;
                capexp = 1;
                v81 = v10;
              }
LABEL_77:
              flags |= 0x40u;
              p_buffer = &buffer;
              text.sz = (char *)&buffer;
              padding = 512;
              if ( precision >= 0 )
              {
                if ( precision != 0 )
                {
                  if ( precision > 512 )
                    precision = 512;
                  if ( precision > 163 )
                  {
                    v28 = precision + 349;
                    v29 = (char *)_malloc_crt(cb: precision + 349);
                    v10 = v81;
                    heapbuf = v29;
                    if ( v29 != nullptr )
                    {
                      text.sz = v29;
                      padding = v28;
                      p_buffer = (_output_l::__l2::<unnamed_type_buffer> *)v29;
                    }
                    else
                    {
                      precision = 163;
                    }
                  }
                }
                else
                {
                  precision = v10 == 103;
                }
              }
              else
              {
                precision = 6;
              }
              v30 = *v4;
              v31 = (char *)(v4 + 2);
              LODWORD(tmp.x) = v30;
              HIDWORD(tmp.x) = *((_DWORD *)v31 - 1);
              v59 = capexp;
              v58 = precision;
              v76 = v31;
              v56 = v10;
              v55 = padding;
              v32 = (void (__cdecl *)(_CRT_DOUBLE *, _output_l::__l2::<unnamed_type_buffer> *, int, int, int, int, _LocaleUpdate *))DecodePointer(Ptr: Ptr);
              v32(a1: &tmp, a2: p_buffer, a3: v55, a4: v56, a5: v58, a6: v59, a7: &_loc_update);
              v33 = flags & 0x80;
              if ( (flags & 0x80) != 0 && precision == 0 )
              {
                v34 = (void (__cdecl *)(_output_l::__l2::<unnamed_type_buffer> *, _LocaleUpdate *))DecodePointer(Ptr: off_411E28);
                v34(a1: p_buffer, a2: &_loc_update);
              }
              if ( v81 == 103 && v33 == 0 )
              {
                v35 = (void (__cdecl *)(_output_l::__l2::<unnamed_type_buffer> *, _LocaleUpdate *))DecodePointer(Ptr: off_411E24);
                v35(a1: p_buffer, a2: &_loc_update);
              }
              if ( p_buffer->sz[0] == 45 )
              {
                flags |= 0x100u;
                p_buffer = (_output_l::__l2::<unnamed_type_buffer> *)((char *)p_buffer + 1);
                text.sz = (char *)p_buffer;
              }
              strlen(buf: (unsigned __int8 *)p_buffer);
              goto LABEL_189;
            }
            if ( v10 > 112 )
            {
              if ( v10 != 115 )
              {
                if ( v10 != 117 )
                {
                  if ( v10 != 120 )
                    goto LABEL_190;
                  hexadd = 39;
                  goto COMMON_HEX;
                }
LABEL_119:
                radix = 10;
                goto COMMON_INT;
              }
LABEL_83:
              v18 = precision;
              if ( precision == -1 )
                v18 = 0x7FFFFFFF;
              v76 = (char *)(v4 + 1);
              v19.sz = (char *)*v4;
              text.sz = v19.sz;
              if ( (flags & 0x810) != 0 )
              {
                if ( v19.sz == nullptr )
                  text.sz = (char *)__wnullstring;
                sz = text.sz;
                bufferiswide = 1;
                while ( v18 != 0 )
                {
                  --v18;
                  if ( *(_WORD *)sz == 0 )
                    break;
                  sz += 2;
                }
                v24 = (sz - text.sz) >> 1;
              }
              else
              {
                if ( v19.sz == nullptr )
                  text.sz = __nullstring;
                for ( i = text.sz; v18 != 0; ++i )
                {
                  --v18;
                  if ( *i == 0 )
                    break;
                }
                v24 = i - text.sz;
              }
LABEL_189:
              radix = v24;
              goto LABEL_190;
            }
            if ( v10 == 112 )
            {
              precision = 8;
LABEL_140:
              hexadd = 7;
COMMON_HEX:
              radix = 16;
              if ( (flags & 0x80u) != 0 )
              {
                prefix[0] = 48;
                prefix[1] = hexadd + 81;
                prefixlen = 2;
              }
              goto COMMON_INT;
            }
            if ( v10 < 101 )
              goto LABEL_190;
            if ( v10 <= 103 )
              goto LABEL_77;
            if ( v10 == 105 )
              goto LABEL_118;
            if ( v10 != 110 )
            {
              if ( v10 != 111 )
                goto LABEL_190;
              radix = 8;
              if ( (flags & 0x80u) != 0 )
                flags |= 0x200u;
COMMON_INT:
              if ( (flags & 0x8000) != 0 || (flags & 0x1000) != 0 )
              {
                v26 = *(_QWORD *)v4;
                v27 = v4 + 2;
              }
              else
              {
                v27 = v4 + 1;
                if ( (flags & 0x20) != 0 )
                {
                  v76 = (char *)v27;
                  if ( (flags & 0x40) != 0 )
                    LODWORD(v26) = *((__int16 *)v27 - 2);
                  else
                    LODWORD(v26) = *((unsigned __int16 *)v27 - 2);
                  v26 = (int)v26;
LABEL_157:
                  if ( (flags & 0x40) != 0 && v26 < 0 )
                  {
                    v26 = -v26;
                    flags |= 0x100u;
                  }
                  v36 = HIDWORD(v26);
                  v37 = v26;
                  if ( (flags & 0x9000) == 0 )
                    v36 = 0;
                  if ( precision >= 0 )
                  {
                    flags &= ~8u;
                    if ( precision > 512 )
                      precision = 512;
                  }
                  else
                  {
                    precision = 1;
                  }
                  if ( (v36 | (unsigned int)v26) == 0 )
                    prefixlen = 0;
                  for ( j = &buffer.sz[511]; ; --j )
                  {
                    v39 = precision--;
                    if ( v39 <= 0 && (v36 | v37) == 0 )
                      break;
                    v57 = __PAIR64__(v36, v37);
                    v40 = __PAIR64__(v36, v37) % radix;
                    v41 = v40 + 48;
                    padding = HIDWORD(v40);
                    v36 = (v57 / radix) >> 32;
                    v37 = v57 / radix;
                    if ( v41 > 57 )
                      LOBYTE(v41) = hexadd + v41;
                    *j = v41;
                  }
                  v42 = (char *)(&buffer.sz[511] - j);
                  v43 = j + 1;
                  radix = (int)v42;
                  text.sz = v43;
                  if ( (flags & 0x200) != 0 && (v42 == nullptr || *v43 != 48) )
                  {
                    *--text.sz = 48;
                    v24 = (signed int)(v42 + 1);
                    goto LABEL_189;
                  }
LABEL_190:
                  if ( no_output != 0 )
                    goto LABEL_222;
                  v45 = flags;
                  if ( (flags & 0x40) != 0 )
                  {
                    if ( (flags & 0x100) != 0 )
                    {
                      prefix[0] = 45;
                      goto LABEL_198;
                    }
                    if ( (flags & 1) != 0 )
                    {
                      prefix[0] = 43;
                      goto LABEL_198;
                    }
                    if ( (flags & 2) != 0 )
                    {
                      prefix[0] = 32;
LABEL_198:
                      prefixlen = 1;
                    }
                  }
                  v46 = fldwidth - radix - prefixlen;
                  padding = v46;
                  if ( (flags & 0xC) == 0 )
                  {
                    v47 = fldwidth - radix - prefixlen;
                    if ( v46 > 0 )
                    {
                      do
                      {
                        LOBYTE(v45) = 32;
                        --v47;
                        write_char(ch: v45, f, pnumwritten: &charsout);
                      }
                      while ( charsout != -1 && v47 > 0 );
                    }
                  }
                  v48 = f;
                  write_string(string: prefix, f, pnumwritten: &charsout, len: prefixlen);
                  if ( (flags & 8) != 0 && (flags & 4) == 0 )
                  {
                    do
                    {
                      if ( v46 <= 0 )
                        break;
                      LOBYTE(v49) = 48;
                      --v46;
                      write_char(ch: v49, f: v48, pnumwritten: &charsout);
                    }
                    while ( charsout != -1 );
                  }
                  v50 = radix;
                  if ( bufferiswide != 0 && radix > 0 )
                  {
                    v51 = (wchar_t *)text.sz;
                    while ( 1 )
                    {
                      v60 = *v51;
                      --v50;
                      ++v51;
                      v52 = wctomb_s(pRetValue: &retval, dst: L_buffer, sizeInBytes: 6u, wchar: v60);
                      if ( v52 != 0 || retval == 0 )
                        break;
                      write_string(string: L_buffer, f: v48, pnumwritten: &charsout, len: retval);
                      if ( v50 == 0 )
                        goto LABEL_217;
                    }
                    charsout = -1;
                  }
                  else
                  {
                    write_string(string: text.sz, f: v48, pnumwritten: &charsout, len: radix);
                  }
LABEL_217:
                  if ( charsout >= 0 && (flags & 4) != 0 )
                  {
                    v53 = padding;
                    do
                    {
                      if ( v53 <= 0 )
                        break;
                      LOBYTE(v52) = 32;
                      --v53;
                      write_char(ch: v52, f: v48, pnumwritten: &charsout);
                    }
                    while ( charsout != -1 );
                  }
                  goto LABEL_222;
                }
                LODWORD(v26) = *(v27 - 1);
                if ( (flags & 0x40) != 0 )
                  v26 = (int)v26;
                else
                  HIDWORD(v26) = 0;
              }
              v76 = (char *)v27;
              goto LABEL_157;
            }
            v25 = (_WORD *)*v4;
            v76 = (char *)(v4 + 1);
            if ( !_get_printf_count_output() )
              goto LABEL_2;
            if ( (flags & 0x20) != 0 )
              *v25 = charsout;
            else
              *(_DWORD *)v25 = charsout;
            no_output = 1;
LABEL_222:
            if ( heapbuf != nullptr )
            {
              free(pBlock: heapbuf);
              heapbuf = nullptr;
            }
LABEL_224:
            v5 = v71;
            v54 = *v71;
            v81 = v54;
            if ( v54 == 0 )
              goto LABEL_226;
            v11 = state;
            v4 = (int *)v76;
            v10 = v54;
            break;
          default:
            goto LABEL_224;
        }
      }
    }
LABEL_226:
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
    return charsout;
  }
  else
  {
LABEL_2:
    *_errno() = 22;
    _invalid_parameter_noinfo();
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
    return -1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004054B1
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
// Address: 0x00405748
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
      v4 = _malloc_crt(cb: 0x38u);
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
          free(pBlock: __piob[i]);
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
// Address: 0x00405880
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
// Address: 0x00405910
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
// Address: 0x00405956
// Name: _seh_longjmp_unwind4(x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __stdcall _seh_longjmp_unwind4(unsigned int Dummy)
{
  _local_unwind4(a1: *(_DWORD **)(Dummy + 40), a2: *(_DWORD *)(Dummy + 24), a3: *(_DWORD *)(Dummy + 28));
}

//------------------------------------------------------------------------------
// Address: 0x00405972
// Name: _EH4_CallFilterFunc(x,x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall _EH4_CallFilterFunc(int (*this)(void))
{
  return this();
}

//------------------------------------------------------------------------------
// Address: 0x00405989
// Name: _EH4_TransferToHandler(x,x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall _EH4_TransferToHandler(int (__fastcall *this)(_DWORD, _DWORD))
{
  _NLG_Notify(a1: 1);
  return this(a1: 0, a2: 0);
}

//------------------------------------------------------------------------------
// Address: 0x004059A2
// Name: _EH4_GlobalUnwind2(x,x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __fastcall _EH4_GlobalUnwind2(PVOID TargetFrame, PEXCEPTION_RECORD ExceptionRecord)
{
  RtlUnwind(TargetFrame, TargetIp: &ReturnPoint, ExceptionRecord, ReturnValue: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x004059BB
// Name: _EH4_LocalUnwind(x,x,x,x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __fastcall _EH4_LocalUnwind(int a1, unsigned int a2, int a3, _DWORD *a4)
{
  return _local_unwind4(a1: a4, a2: a1, a3: a2);
}

//------------------------------------------------------------------------------
// Address: 0x004059D2
// Name: __malloc_crt
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void *__cdecl _malloc_crt(unsigned int cb)
{
  DWORD v1; // esi
  void *v2; // edi
  int v3; // eax

  v1 = 0;
  do
  {
    v2 = malloc(size: cb);
    if ( v2 != nullptr || _maxwait == 0 )
      break;
    Sleep(dwMilliseconds: v1);
    v3 = v1 + 1000;
    if ( v1 + 1000 > _maxwait )
      v3 = -1;
    v1 = v3;
  }
  while ( v3 != -1 );
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x00405A17
// Name: __calloc_crt
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void *__cdecl _calloc_crt(unsigned int count, unsigned int size)
{
  DWORD v2; // esi
  void *v3; // edi
  int v4; // eax

  v2 = 0;
  do
  {
    v3 = _calloc_impl(num: count, size, errno_tmp: nullptr);
    if ( v3 != nullptr || _maxwait == 0 )
      break;
    Sleep(dwMilliseconds: v2);
    v4 = v2 + 1000;
    if ( v2 + 1000 > _maxwait )
      v4 = -1;
    v2 = v4;
  }
  while ( v4 != -1 );
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x00405A63
// Name: __realloc_crt
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void *__cdecl _realloc_crt(void *ptr, unsigned int size)
{
  DWORD v2; // esi
  void *v3; // edi
  int v4; // eax

  v2 = 0;
  do
  {
    v3 = realloc(pBlock: ptr, newsize: size);
    if ( v3 != nullptr || size == 0 || _maxwait == 0 )
      break;
    Sleep(dwMilliseconds: v2);
    v4 = v2 + 1000;
    if ( v2 + 1000 > _maxwait )
      v4 = -1;
    v2 = v4;
  }
  while ( v4 != -1 );
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x00405AB1
// Name: __recalloc_crt
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void *__cdecl _recalloc_crt(void *ptr, unsigned int count, unsigned int size)
{
  DWORD v3; // esi
  void *v4; // edi
  int v5; // eax

  v3 = 0;
  do
  {
    v4 = _recalloc(memblock: ptr, count, size);
    if ( v4 != nullptr || size == 0 || _maxwait == 0 )
      break;
    Sleep(dwMilliseconds: v3);
    v5 = v3 + 1000;
    if ( v3 + 1000 > _maxwait )
      v5 = -1;
    v3 = v5;
  }
  while ( v5 != -1 );
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x00405B03
// Name: __encoded_null
// Source: linker_block_proximity
//------------------------------------------------------------------------------
PVOID _encoded_null()
{
  return EncodePointer(Ptr: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x00405B0C
// Name: __crtTlsAlloc(x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
DWORD __stdcall __crtTlsAlloc(void (__stdcall *lpCallBack)(void *))
{
  return TlsAlloc();
}

//------------------------------------------------------------------------------
// Address: 0x00405B15
// Name: ___set_flsgetvalue
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void *__set_flsgetvalue()
{
  void *Value; // esi

  Value = TlsGetValue(dwTlsIndex: __getvalueindex);
  if ( Value == nullptr )
  {
    Value = DecodePointer(Ptr: gpFlsGetValue);
    TlsSetValue(dwTlsIndex: __getvalueindex, lpTlsValue: Value);
  }
  return Value;
}

//------------------------------------------------------------------------------
// Address: 0x00405B49
// Name: __mtterm
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void _mtterm()
{
  void (__stdcall *v0)(unsigned int); // eax
  unsigned int v1; // [esp-4h] [ebp-4h]

  if ( __flsindex != -1 )
  {
    v1 = __flsindex;
    v0 = (void (__stdcall *)(unsigned int))DecodePointer(Ptr: gpFlsFree);
    v0(a1: v1);
    __flsindex = -1;
  }
  if ( __getvalueindex != -1 )
  {
    TlsFree(dwTlsIndex: __getvalueindex);
    __getvalueindex = -1;
  }
  _mtdeletelocks();
}

//------------------------------------------------------------------------------
// Address: 0x00405B86
// Name: __initptd
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _initptd(_tiddata *ptd, threadlocaleinfostruct *ptloci)
{
  int savedregs; // [esp+28h] [ebp+0h]

  GetModuleHandleW(lpModuleName: L"KERNEL32.DLL");
  ptd->_pxcptacttab = (void *)_XcptActTab;
  ptd->_terrno = 0;
  ptd->_holdrand = 1;
  ptd->_ownlocale = 1;
  ptd->_setloc_data._cachein[0] = 67;
  ptd->_setloc_data._cacheout[0] = 67;
  ptd->ptmbcinfo = &__initialmbcinfo;
  _lock(locknum: 13);
  InterlockedIncrement(lpAddend: &ptd->ptmbcinfo->refcount);
  _unlock(locknum: 13);
  _lock(locknum: 12);
  ptd->ptlocinfo = ptloci;
  if ( ptloci == nullptr )
    ptd->ptlocinfo = __ptlocinfo;
  __addlocaleref(ptloci: ptd->ptlocinfo);
  savedregs = 4217884;
  _unlock(locknum: 12);
}

//------------------------------------------------------------------------------
// Address: 0x00405C3A
// Name: __getptd_noexit
// Source: linker_block_proximity
//------------------------------------------------------------------------------
_tiddata *__cdecl _getptd_noexit()
{
  DWORD LastError; // eax
  DWORD v1; // edi
  int (__stdcall *v2)(unsigned int); // eax
  _tiddata *v3; // esi
  _tiddata *v4; // eax
  int (__stdcall *v5)(unsigned int, _tiddata *); // eax
  DWORD CurrentThreadId; // eax
  unsigned int v8; // [esp-8h] [ebp-10h]
  unsigned int v9; // [esp-4h] [ebp-Ch]
  _tiddata *v10; // [esp-4h] [ebp-Ch]

  LastError = GetLastError();
  v9 = __flsindex;
  v1 = LastError;
  v2 = (int (__stdcall *)(unsigned int))__set_flsgetvalue();
  v3 = (_tiddata *)v2(a1: v9);
  if ( v3 == nullptr )
  {
    v4 = (_tiddata *)_calloc_crt(count: 1u, size: 0x214u);
    v3 = v4;
    if ( v4 != nullptr )
    {
      v10 = v4;
      v8 = __flsindex;
      v5 = (int (__stdcall *)(unsigned int, _tiddata *))DecodePointer(Ptr: gpFlsSetValue);
      if ( v5(a1: v8, a2: v10) != 0 )
      {
        _initptd(ptd: v3, ptloci: nullptr);
        CurrentThreadId = GetCurrentThreadId();
        v3->_thandle = -1;
        v3->_tid = CurrentThreadId;
      }
      else
      {
        free(pBlock: v3);
        v3 = nullptr;
      }
    }
  }
  SetLastError(dwErrCode: v1);
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x00405CB3
// Name: __getptd
// Source: linker_block_proximity
//------------------------------------------------------------------------------
_tiddata *__cdecl _getptd()
{
  _tiddata *result; // eax

  result = _getptd_noexit();
  if ( result == nullptr )
    _amsg_exit(rterrnum: 16);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00405CCD
// Name: _freefls(x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __stdcall _freefls(void *data)
{
  threadmbcinfostruct *v1; // edi
  threadlocaleinfostruct *v2; // edi
  int savedregs; // [esp+28h] [ebp+0h]

  if ( data != nullptr )
  {
    if ( *((_DWORD *)data + 9) != 0 )
      free(pBlock: *((void **)data + 9));
    if ( *((_DWORD *)data + 11) != 0 )
      free(pBlock: *((void **)data + 11));
    if ( *((_DWORD *)data + 13) != 0 )
      free(pBlock: *((void **)data + 13));
    if ( *((_DWORD *)data + 15) != 0 )
      free(pBlock: *((void **)data + 15));
    if ( *((_DWORD *)data + 16) != 0 )
      free(pBlock: *((void **)data + 16));
    if ( *((_DWORD *)data + 17) != 0 )
      free(pBlock: *((void **)data + 17));
    if ( *((_DWORD *)data + 18) != 0 )
      free(pBlock: *((void **)data + 18));
    if ( *((const _XCPT_ACTION **)data + 23) != _XcptActTab )
      free(pBlock: *((void **)data + 23));
    _lock(locknum: 13);
    v1 = *((threadmbcinfostruct **)data + 26);
    if ( v1 != nullptr && InterlockedDecrement(lpAddend: *((volatile LONG **)data + 26)) == 0 && v1 != &__initialmbcinfo )
      free(pBlock: v1);
    _unlock(locknum: 13);
    _lock(locknum: 12);
    v2 = *((threadlocaleinfostruct **)data + 27);
    if ( v2 != nullptr )
    {
      __removelocaleref(ptloci: *((threadlocaleinfostruct **)data + 27));
      if ( v2 != __ptlocinfo && v2 != &__initiallocinfo && v2->refcount == 0 )
        __freetlocinfo(ptloci: v2);
    }
    savedregs = 4218325;
    _unlock(locknum: 12);
    free(pBlock: data);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00405DFC
// Name: __mtinit
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _mtinit()
{
  HMODULE ModuleHandleW; // eax
  HMODULE v1; // edi
  BOOL (__stdcall *FlsFree)(DWORD); // eax
  DWORD v4; // eax
  int (__stdcall *v5)(_DWORD); // eax
  _tiddata *v6; // eax
  _tiddata *v7; // esi
  int (__stdcall *v8)(unsigned int, _tiddata *); // eax
  DWORD CurrentThreadId; // eax
  unsigned int v10; // [esp-Ch] [ebp-10h]
  _tiddata *v11; // [esp-8h] [ebp-Ch]

  ModuleHandleW = GetModuleHandleW(lpModuleName: L"KERNEL32.DLL");
  v1 = ModuleHandleW;
  if ( ModuleHandleW == nullptr )
  {
    _mtterm();
    return 0;
  }
  gpFlsAlloc = GetProcAddress(hModule: ModuleHandleW, lpProcName: "FlsAlloc");
  gpFlsGetValue = GetProcAddress(hModule: v1, lpProcName: "FlsGetValue");
  gpFlsSetValue = GetProcAddress(hModule: v1, lpProcName: "FlsSetValue");
  FlsFree = (BOOL (__stdcall *)(DWORD))GetProcAddress(hModule: v1, lpProcName: "FlsFree");
  gpFlsFree = FlsFree;
  if ( gpFlsAlloc == nullptr || gpFlsGetValue == nullptr || gpFlsSetValue == nullptr || FlsFree == nullptr )
  {
    gpFlsGetValue = TlsGetValue;
    gpFlsAlloc = __crtTlsAlloc;
    gpFlsSetValue = TlsSetValue;
    gpFlsFree = TlsFree;
  }
  v4 = TlsAlloc();
  __getvalueindex = v4;
  if ( v4 != -1 && TlsSetValue(dwTlsIndex: v4, lpTlsValue: gpFlsGetValue) )
  {
    _init_pointers();
    gpFlsAlloc = EncodePointer(Ptr: gpFlsAlloc);
    gpFlsGetValue = EncodePointer(Ptr: gpFlsGetValue);
    gpFlsSetValue = EncodePointer(Ptr: gpFlsSetValue);
    gpFlsFree = EncodePointer(Ptr: gpFlsFree);
    if ( _mtinitlocks() != 0 )
    {
      v5 = (int (__stdcall *)(_DWORD))DecodePointer(Ptr: gpFlsAlloc);
      __flsindex = v5(a1: _freefls);
      if ( __flsindex != -1 )
      {
        v6 = (_tiddata *)_calloc_crt(count: 1u, size: 0x214u);
        v7 = v6;
        if ( v6 != nullptr )
        {
          v11 = v6;
          v10 = __flsindex;
          v8 = (int (__stdcall *)(unsigned int, _tiddata *))DecodePointer(Ptr: gpFlsSetValue);
          if ( v8(a1: v10, a2: v11) != 0 )
          {
            _initptd(ptd: v7, ptloci: nullptr);
            CurrentThreadId = GetCurrentThreadId();
            v7->_thandle = -1;
            v7->_tid = CurrentThreadId;
            return 1;
          }
        }
      }
    }
    _mtterm();
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x00405F77
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
// Address: 0x004061A2
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
// Address: 0x004061D0
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
        goto main_loop_1;
    }
  }
  else
  {
    do
    {
      do
      {
main_loop_1:
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
// Address: 0x0040625B
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
      v6 = (char *)_calloc_crt(count: v5, size: 2u);
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
// Address: 0x004062B2
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
// Address: 0x004062D2
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
// Address: 0x004062E8
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
// Address: 0x00406312
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
    && ((v5 = _fileno(stream)) == -1 || v5 == -2 ? (v6 = &__badioinfo) : (v6 = &__pioinfo[v5 >> 5][v5 & 0x1F]),
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
      v10 = whiteout(counter: &charcount, a2: v65, fileptr);
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
        v18 = whiteout(counter: &charcount, a2: v13, fileptr);
      }
      *(_DWORD *)chr = v18;
      if ( v18 == -1 )
        goto error_return;
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
          memset(dst: (int)AsciiTable, value: nullptr, count: sizeof(AsciiTable));
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
                goto error_return;
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
          goto error_return;
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
            goto error_return;
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
              goto error_return;
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
            goto error_return;
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
              goto error_return;
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
              goto error_return;
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
          v37 = (void (__cdecl *)(int, void *, char *, _LocaleUpdate *))DecodePointer(Ptr: off_411E20);
          v37(a1: v62, a2: v63, a3: v64, a4: &_loc_update);
        }
        goto LABEL_262;
      }
      goto error_return;
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
      goto error_return;
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
      goto error_return;
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
        goto error_return;
      continue;
    }
    break;
  }
  if ( *v9 == 37 && v88[1] == 110 )
  {
    v9 = v88;
    goto LABEL_272;
  }
error_return:
  if ( malloc_FloatStrFlag == 1 )
    free(pBlock: pFloatStr);
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
// Address: 0x00407316
// Name: __VEC_memzero
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char *__fastcall _VEC_memzero(_BYTE *a1, unsigned int a2)
{
  int v2; // eax
  unsigned int v3; // eax
  unsigned int v4; // edx
  char *result; // eax
  unsigned int v6; // edx
  char v7; // al
  unsigned int k; // edx
  int i; // edx
  unsigned int j; // ebx
  unsigned int v11; // [esp-4h] [ebp-Ch]

  v2 = (unsigned __int8)a1 & 0xF;
  if ( ((unsigned __int8)a1 & 0xF) != 0 )
  {
    v11 = a2 - (16 - v2);
    for ( i = (16 - (_BYTE)v2) & 3; i != 0; --i )
      *a1++ = 0;
    for ( j = (unsigned int)(16 - v2) >> 2; j != 0; --j )
    {
      *(_DWORD *)a1 = 0;
      a1 += 4;
    }
    a2 = v11;
  }
  v3 = a2;
  v4 = a2 & 0x7F;
  for ( result = (char *)(v3 >> 7); result != nullptr; --result )
  {
    *(_OWORD *)a1 = 0;
    *((_OWORD *)a1 + 1) = 0;
    *((_OWORD *)a1 + 2) = 0;
    *((_OWORD *)a1 + 3) = 0;
    *((_OWORD *)a1 + 4) = 0;
    *((_OWORD *)a1 + 5) = 0;
    *((_OWORD *)a1 + 6) = 0;
    *((_OWORD *)a1 + 7) = 0;
    a1 += 128;
  }
  if ( v4 != 0 )
  {
    result = (char *)(v4 >> 4);
    if ( v4 >> 4 != 0 )
    {
      do
      {
        *(_OWORD *)a1 = 0;
        a1 += 16;
        --result;
      }
      while ( result != nullptr );
    }
    v6 = v4 & 0xF;
    if ( v6 != 0 )
    {
      v7 = v6;
      for ( k = v6 >> 2; k != 0; --k )
      {
        *(_DWORD *)a1 = 0;
        a1 += 4;
      }
      for ( result = (char *)(v7 & 3); result != nullptr; --result )
        *a1++ = 0;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004073D0
// Name: ___sse2_available_init
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __sse2_available_init()
{
  __sse2_available = IsProcessorFeaturePresent(ProcessorFeature: 0xAu);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x004073E0
// Name: long __CxxUnhandledExceptionFilter(struct _EXCEPTION_POINTERS __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __stdcall __CxxUnhandledExceptionFilter(_EXCEPTION_POINTERS *pPtrs)
{
  _EXCEPTION_RECORD *ExceptionRecord; // eax
  unsigned int v2; // eax

  ExceptionRecord = pPtrs->ExceptionRecord;
  if ( pPtrs->ExceptionRecord->ExceptionCode == -529697949 && ExceptionRecord->NumberParameters == 3 )
  {
    v2 = ExceptionRecord->ExceptionInformation[0];
    if ( v2 == 429065504 || v2 == 429065505 || v2 == 429065506 || v2 == 26820608 )
      terminate();
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x00407422
// Name: ___CxxSetUnhandledExceptionFilter
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl __CxxSetUnhandledExceptionFilter()
{
  SetUnhandledExceptionFilter(lpTopLevelExceptionFilter: __CxxUnhandledExceptionFilter);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x00407430
// Name: ___crtCorExitProcess
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl __crtCorExitProcess(int status)
{
  HMODULE ModuleHandleW; // eax
  FARPROC CorExitProcess; // eax

  ModuleHandleW = GetModuleHandleW(lpModuleName: L"mscoree.dll");
  if ( ModuleHandleW != nullptr )
  {
    CorExitProcess = GetProcAddress(hModule: ModuleHandleW, lpProcName: "CorExitProcess");
    if ( CorExitProcess != nullptr )
      ((void (__stdcall *)(int))CorExitProcess)(a1: status);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040745B
// Name: ___crtExitProcess
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl __noreturn __crtExitProcess(int status)
{
  __crtCorExitProcess(status);
  ExitProcess(uExitCode: status);
}

//------------------------------------------------------------------------------
// Address: 0x00407473
// Name: __lockexit
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void _lockexit()
{
  _lock(locknum: 8);
}

//------------------------------------------------------------------------------
// Address: 0x0040747C
// Name: __unlockexit
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void _unlockexit()
{
  _unlock(locknum: 8);
}

//------------------------------------------------------------------------------
// Address: 0x00407485
// Name: __init_pointers
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void _init_pointers()
{
  PVOID v0; // esi

  v0 = _encoded_null();
  _initp_heap_handler(enull: v0);
  _initp_misc_invarg(enull: v0);
  _initp_misc_purevirt(enull: v0);
  _initp_misc_rand_s(enull: v0);
  _initp_misc_winsig(enull: v0);
  _initp_eh_hooks(enull: v0);
}

//------------------------------------------------------------------------------
// Address: 0x004074B8
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
// Address: 0x004074DC
// Name: __cinit
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _cinit(int initFloatingPrecision)
{
  int result; // eax
  void (**i)(void); // edi

  if ( _FPinit != nullptr && _IsNonwritableInCurrentImage(pTarget: (unsigned __int8 *)&_FPinit) != 0 )
    _FPinit(a1: initFloatingPrecision);
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
      && _IsNonwritableInCurrentImage(pTarget: (unsigned __int8 *)&__dyn_tls_init_callback) != 0 )
    {
      __dyn_tls_init_callback(a1: nullptr, a2: 2u, a3: nullptr);
    }
    return 0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00407573
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
// Address: 0x004076B3
// Name: _exit
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl __noreturn exit(int code)
{
  doexit(code, quick: 0, retcaller: 0);
}

//------------------------------------------------------------------------------
// Address: 0x004076C9
// Name: __exit
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl __noreturn _exit(int code)
{
  doexit(code, quick: 1, retcaller: 0);
}

//------------------------------------------------------------------------------
// Address: 0x004076DF
// Name: __cexit
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _cexit()
{
  doexit(code: 0, quick: 0, retcaller: 1);
}

//------------------------------------------------------------------------------
// Address: 0x004076EE
// Name: __c_exit
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _c_exit()
{
  doexit(code: 0, quick: 1, retcaller: 1);
}

//------------------------------------------------------------------------------
// Address: 0x004076FD
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
// Address: 0x0040771B
// Name: __GET_RTERRMSG
// Source: linker_block_proximity
//------------------------------------------------------------------------------
const wchar_t *__cdecl _GET_RTERRMSG(int rterrnum)
{
  int v1; // eax

  v1 = 0;
  while ( rterrnum != rterrs[v1].rterrno )
  {
    if ( (unsigned int)++v1 >= 0x16 )
      return nullptr;
  }
  return rterrs[v1].rterrtxt;
}

//------------------------------------------------------------------------------
// Address: 0x00407741
// Name: __NMSG_WRITE
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _NMSG_WRITE(int rterrnum)
{
  const wchar_t *v1; // edi
  unsigned int v2; // eax
  HANDLE StdHandle; // eax
  void *v4; // esi
  unsigned int i; // eax
  DWORD v6; // eax
  unsigned int bytes_written; // [esp+Ch] [ebp-1FCh] BYREF
  char buffer[500]; // [esp+10h] [ebp-1F8h] BYREF

  v1 = _GET_RTERRMSG(rterrnum);
  bytes_written = (unsigned int)v1;
  if ( v1 != nullptr )
  {
    if ( _set_error_mode(em: 3) == 1 || _set_error_mode(em: 3) == 0 && __app_type == 1 )
    {
      StdHandle = GetStdHandle(nStdHandle: 0xFFFFFFF4);
      v4 = StdHandle;
      if ( StdHandle != nullptr && StdHandle != (HANDLE)-1 )
      {
        for ( i = 0; i < 0x1F4; ++i )
        {
          buffer[i] = v1[i];
          if ( v1[i] == 0 )
            break;
        }
        buffer[499] = 0;
        strlen(buf: buffer);
        WriteFile(
          hFile: v4,
          lpBuffer: buffer,
          nNumberOfBytesToWrite: v6,
          lpNumberOfBytesWritten: &bytes_written,
          lpOverlapped: nullptr);
      }
    }
    else if ( rterrnum != 252 )
    {
      if ( wcscpy_s(_Dst: outmsg, _SizeInWords: 0x314u, _Src: L"Runtime Error!\n\nProgram: ") != 0
        || (outmsg[285] = 0, GetModuleFileNameW(hModule: nullptr, lpFilename: &outmsg[25], nSize: 0x104u) == 0)
        && wcscpy_s(_Dst: &outmsg[25], _SizeInWords: 0x2FBu, _Src: L"<program name unknown>") != 0
        || wcslen(wcs: &outmsg[25]) + 1 > 0x3C
        && (v2 = wcslen(wcs: &outmsg[25]),
            wcsncpy_s(
              _Dst: (unsigned __int16 *)&gpFlsAlloc + v2,
              _SizeInWords: 763 - (((char *)&gpFlsAlloc + 2 * v2 - (char *)&outmsg[25]) >> 1),
              _Src: L"...",
              _Count: 3u) != 0)
        || wcscat_s(_Dst: outmsg, _SizeInWords: 0x314u, _Src: L"\n\n") != 0
        || wcscat_s(_Dst: outmsg, _SizeInWords: 0x314u, _Src: (const wchar_t *)bytes_written) != 0 )
      {
        _invoke_watson(a1: (unsigned int)outmsg);
      }
      __crtMessageBoxW(lpText: outmsg, lpCaption: L"Microsoft Visual C++ Runtime Library", uType: 0x12010u);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004078F0
// Name: __FF_MSGBANNER
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void _FF_MSGBANNER()
{
  if ( _set_error_mode(em: 3) == 1 || _set_error_mode(em: 3) == 0 && __app_type == 1 )
  {
    _NMSG_WRITE(rterrnum: 252);
    _NMSG_WRITE(rterrnum: 255);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00407929
// Name: __XcptFilter
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _XcptFilter(unsigned int xcptnum, _EXCEPTION_POINTERS *pxcptinfoptrs)
{
  int result; // eax
  _DWORD *v3; // esi
  int *v4; // ecx
  int *v5; // eax
  void (__cdecl *v6)(int); // edx
  int v7; // ebx
  int v8; // ecx
  int i; // ecx
  int v10; // eax
  int v11; // edi

  result = (int)_getptd_noexit();
  v3 = (_DWORD *)result;
  if ( result != 0 )
  {
    v4 = *(int **)(result + 92);
    v5 = v4;
    do
    {
      if ( *v5 == xcptnum )
        break;
      v5 += 3;
    }
    while ( v5 < v4 + 36 );
    if ( v5 >= v4 + 36 || *v5 != xcptnum )
      v5 = nullptr;
    if ( v5 != nullptr && (v6 = (void (__cdecl *)(int))v5[2]) != nullptr )
    {
      if ( v6 == (void (__cdecl *)(int))5 )
      {
        v5[2] = 0;
        return 1;
      }
      else
      {
        if ( v6 != (void (__cdecl *)(int))1 )
        {
          v7 = v3[24];
          v3[24] = pxcptinfoptrs;
          v8 = v5[1];
          if ( v8 == 8 )
          {
            for ( i = 36; i < 144; i += 12 )
              *(_DWORD *)(i + v3[23] + 8) = 0;
            v10 = *v5;
            v11 = v3[25];
            switch ( v10 )
            {
              case -1073741682:
                v3[25] = 131;
                break;
              case -1073741680:
                v3[25] = 129;
                break;
              case -1073741679:
                v3[25] = 132;
                break;
              case -1073741677:
                v3[25] = 133;
                break;
              case -1073741683:
                v3[25] = 130;
                break;
              case -1073741681:
                v3[25] = 134;
                break;
              case -1073741678:
                v3[25] = 138;
                break;
              case -1073741131:
                v3[25] = 141;
                break;
              case -1073741132:
                v3[25] = 142;
                break;
              default:
                break;
            }
            v6(a1: 8);
            v3[25] = v11;
          }
          else
          {
            v5[2] = 0;
            v6(a1: v8);
          }
          v3[24] = v7;
        }
        return -1;
      }
    }
    else
    {
      return 0;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00407A73
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
    v4 = (char **)_calloc_crt(count: v1 + 1, size: 4u);
    _environ = v4;
    if ( v4 != nullptr )
    {
      for ( i = _aenvptr; ; i += v7 )
      {
        if ( *i == 0 )
        {
          free(pBlock: _aenvptr);
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
      v8 = (char *)_calloc_crt(count: v6 + 1, size: 1u);
      *v4 = v8;
      if ( v8 != nullptr )
      {
        if ( strcpy_s(_Dst: v8, _SizeInBytes: v7, _Src: i) != 0 )
          _invoke_watson(a1: (unsigned int)v4);
        ++v4;
        goto LABEL_15;
      }
      free(pBlock: _environ);
      _environ = nullptr;
      return -1;
    }
  }
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00407B4F
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
// Address: 0x00407CE9
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
  v2 = (char **)_malloc_crt(cb: v1);
  if ( v2 == nullptr )
    return -1;
  parse_cmdline(cmdstart, &numchars, argv: v2, args: (char *)&v2[v0], &numargs);
  __argc = numargs - 1;
  __argv = v2;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x00407DA4
// Name: ___crtGetEnvironmentStringsA
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char *__cdecl __crtGetEnvironmentStringsA()
{
  LPWCH EnvironmentStringsW; // eax
  WCHAR *v1; // ebx
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
  if ( v3 != 0 && (v4 = (char *)_malloc_crt(cb: v3), aEnv = v4, v4 != nullptr) )
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
      free(pBlock: aEnv);
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

//------------------------------------------------------------------------------
// Address: 0x00407E3B
// Name: __RTC_Initialize
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _RTC_Initialize()
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x00407E61
// Name: __RTC_Terminate
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _RTC_Terminate()
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x00407E87
// Name: __heap_init
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __cdecl _heap_init()
{
  _crtheap = HeapCreate(flOptions: 0, dwInitialSize: 0x1000u, dwMaximumSize: 0);
  return _crtheap != nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x00407EA5
// Name: ___security_init_cookie
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl __security_init_cookie()
{
  unsigned int v0; // esi
  DWORD v1; // esi
  DWORD v2; // esi
  DWORD v3; // esi
  uintptr_t v4; // esi
  _LARGE_INTEGER perfctr; // [esp+8h] [ebp-10h] BYREF
  FT systime; // [esp+10h] [ebp-8h] BYREF

  systime.ft_scalar = 0;
  if ( __security_cookie == -1153374642 || (__security_cookie & 0xFFFF0000) == 0 )
  {
    GetSystemTimeAsFileTime(lpSystemTimeAsFileTime: (LPFILETIME)&systime);
    v0 = systime.ft_struct.dwLowDateTime ^ systime.ft_struct.dwHighDateTime;
    v1 = GetCurrentProcessId() ^ v0;
    v2 = GetCurrentThreadId() ^ v1;
    v3 = GetTickCount() ^ v2;
    QueryPerformanceCounter(lpPerformanceCount: &perfctr);
    v4 = perfctr.LowPart ^ perfctr.HighPart ^ v3;
    if ( v4 == -1153374642 )
    {
      v4 = -1153374641;
    }
    else if ( (v4 & 0xFFFF0000) == 0 )
    {
      v4 |= (v4 | 0x4711) << 16;
    }
    __security_cookie = v4;
    __security_cookie_complement = ~v4;
  }
  else
  {
    __security_cookie_complement = ~__security_cookie;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00407F40
// Name: __crt_debugger_hook
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _crt_debugger_hook()
{
  _debugger_hook_dummy = 0;
}

//------------------------------------------------------------------------------
// Address: 0x00407F48
// Name: __security_check_cookie(x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __fastcall __security_check_cookie(uintptr_t StackCookie)
{
  if ( StackCookie != __security_cookie )
    __report_gsfailure();
}

//------------------------------------------------------------------------------
// Address: 0x00407F57
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
// Address: 0x0040800C
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
// Address: 0x00408070
// Name: _strcmp
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl strcmp(unsigned __int8 *str1, unsigned __int8 *str2)
{
  unsigned __int8 *v2; // edx
  unsigned __int8 *v3; // ecx
  unsigned int v4; // eax
  unsigned int v5; // eax
  __int16 v6; // ax

  v2 = str1;
  v3 = str2;
  if ( ((unsigned __int8)str1 & 3) != 0 )
  {
    if ( ((unsigned __int8)str1 & 1) == 0 )
      goto doword;
    v2 = str1 + 1;
    if ( *str1 != *str2 )
      return;
    v3 = str2 + 1;
    if ( *str1 == 0 )
      return;
    if ( ((unsigned __int8)v2 & 2) != 0 )
    {
doword:
      v6 = *(_WORD *)v2;
      v2 += 2;
      if ( (_BYTE)v6 != *v3 || (_BYTE)v6 == 0 || HIBYTE(v6) != v3[1] || HIBYTE(v6) == 0 )
        return;
      v3 += 2;
    }
  }
  do
  {
    v4 = *(_DWORD *)v2;
    if ( (unsigned __int8)*(_DWORD *)v2 != *v3 )
      break;
    if ( (_BYTE)v4 == 0 )
      break;
    if ( BYTE1(v4) != v3[1] )
      break;
    if ( BYTE1(v4) == 0 )
      break;
    v5 = HIWORD(v4);
    if ( (_BYTE)v5 != v3[2] )
      break;
    if ( (_BYTE)v5 == 0 )
      break;
    if ( BYTE1(v5) != v3[3] )
      break;
    v3 += 4;
    v2 += 4;
  }
  while ( BYTE1(v5) != 0 );
}

//------------------------------------------------------------------------------
// Address: 0x004080F8
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
// Address: 0x0040817F
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
// Address: 0x004081B0
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
// Address: 0x004081E4
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
// Address: 0x00408265
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
// Address: 0x004082EB
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
// Address: 0x00408354
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
// Address: 0x004083F3
// Name: __unlock_fhandle
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _unlock_fhandle(int fh)
{
  LeaveCriticalSection(lpCriticalSection: &__pioinfo[fh >> 5][fh & 0x1F].lock);
}

//------------------------------------------------------------------------------
// Address: 0x0040841A
// Name: __alloc_osfhnd
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _alloc_osfhnd()
{
  int v0; // edi
  ioinfo *v2; // esi
  ioinfo *v3; // eax
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
      v3 = (ioinfo *)_calloc_crt(count: 0x20u, size: 0x40u);
      if ( v3 != nullptr )
      {
        v4 = &__pioinfo[v0];
        *v4 = v3;
        _nhandle += 32;
        while ( v3 < &(*v4)[32] )
        {
          v3->osfile = 0;
          v3->osfhnd = -1;
          v3->pipech = 10;
          v3->lockinitflag = 0;
          ++v3;
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
// Address: 0x004085B3
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
        free(pBlock: __piob[i]);
        __piob[i] = nullptr;
      }
    }
  }
  _unlock(locknum: 1);
  return count;
}

//------------------------------------------------------------------------------
// Address: 0x00408650
// Name: __ValidateImageBase
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __cdecl _ValidateImageBase(unsigned __int8 *pImageBase)
{
  unsigned __int8 *v2; // eax

  return *(_WORD *)pImageBase == 23117
      && *(_DWORD *)(v2 = &pImageBase[*((_DWORD *)pImageBase + 15)]) == 17744
      && *((_WORD *)v2 + 12) == 267;
}

//------------------------------------------------------------------------------
// Address: 0x00408690
// Name: __FindPESection
// Source: linker_block_proximity
//------------------------------------------------------------------------------
_IMAGE_SECTION_HEADER *__cdecl _FindPESection(unsigned __int8 *pImageBase, unsigned int rva)
{
  unsigned __int8 *v2; // ecx
  unsigned int v3; // esi
  unsigned int v4; // edx
  _IMAGE_SECTION_HEADER *result; // eax
  unsigned int VirtualAddress; // ecx

  v2 = &pImageBase[*((_DWORD *)pImageBase + 15)];
  v3 = *((unsigned __int16 *)v2 + 3);
  v4 = 0;
  result = (_IMAGE_SECTION_HEADER *)&v2[*((unsigned __int16 *)v2 + 10) + 24];
  if ( *((_WORD *)v2 + 3) == 0 )
    return nullptr;
  while ( 1 )
  {
    VirtualAddress = result->VirtualAddress;
    if ( rva >= VirtualAddress && rva < VirtualAddress + result->Misc.PhysicalAddress )
      break;
    ++v4;
    ++result;
    if ( v4 >= v3 )
      return nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004086E0
// Name: __IsNonwritableInCurrentImage
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __cdecl _IsNonwritableInCurrentImage(unsigned __int8 *pTarget)
{
  _IMAGE_SECTION_HEADER *PESection; // eax

  return _ValidateImageBase(pImageBase: (unsigned __int8 *)0x400000)
      && (PESection = _FindPESection(pImageBase: (unsigned __int8 *)0x400000, rva: (unsigned int)(pTarget - 0x400000))) != nullptr
      && (PESection->Characteristics & 0x80000000) == 0;
}

//------------------------------------------------------------------------------
// Address: 0x0040879C
// Name: __putwch_nolock
// Source: linker_block_proximity
//------------------------------------------------------------------------------
wchar_t __cdecl _putwch_nolock(wchar_t ch)
{
  unsigned int cchWritten; // [esp+0h] [ebp-4h] BYREF

  if ( _confh == (HANDLE)-2 )
    __initconout();
  if ( _confh == (HANDLE)-1
    || !WriteConsoleW(
          hConsoleOutput: _confh,
          lpBuffer: &ch,
          nNumberOfCharsToWrite: 1u,
          lpNumberOfCharsWritten: &cchWritten,
          lpReserved: nullptr) )
  {
    return -1;
  }
  else
  {
    return ch;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004087DE
// Name: __mbtowc_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _mbtowc_l(wchar_t *pwc, const char *s, signed int n, localeinfo_struct *plocinfo)
{
  int result; // eax
  threadlocaleinfostruct *locinfo; // eax
  int mb_cur_max; // ecx
  bool v7; // zf
  _LocaleUpdate _loc_update; // [esp+8h] [ebp-10h] BYREF

  if ( s == nullptr || n == 0 )
    return 0;
  if ( *s == 0 )
  {
    if ( pwc != nullptr )
      *pwc = 0;
    return 0;
  }
  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  if ( _loc_update.localeinfo.locinfo->lc_handle[2] == 0 )
  {
    if ( pwc != nullptr )
      *pwc = *(unsigned __int8 *)s;
    goto LABEL_11;
  }
  if ( _isleadbyte_l(c: *(unsigned __int8 *)s, plocinfo: &_loc_update.localeinfo) != 0 )
  {
    locinfo = _loc_update.localeinfo.locinfo;
    mb_cur_max = _loc_update.localeinfo.locinfo->mb_cur_max;
    if ( mb_cur_max > 1
      && n >= mb_cur_max
      && (v7 = MultiByteToWideChar(
                 CodePage: _loc_update.localeinfo.locinfo->lc_codepage,
                 dwFlags: 9u,
                 lpMultiByteStr: s,
                 cbMultiByte: mb_cur_max,
                 lpWideCharStr: pwc,
                 cchWideChar: pwc != nullptr) == 0,
          locinfo = _loc_update.localeinfo.locinfo,
          !v7)
      || (unsigned int)n >= locinfo->mb_cur_max && s[1] != 0 )
    {
      result = locinfo->mb_cur_max;
      if ( _loc_update.updated )
        _loc_update.ptd->_ownlocale &= ~2u;
      return result;
    }
  }
  else if ( MultiByteToWideChar(
              CodePage: _loc_update.localeinfo.locinfo->lc_codepage,
              dwFlags: 9u,
              lpMultiByteStr: s,
              cbMultiByte: 1,
              lpWideCharStr: pwc,
              cchWideChar: pwc != nullptr) != 0 )
  {
LABEL_11:
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
    return 1;
  }
  *_errno() = 42;
  if ( _loc_update.updated )
    _loc_update.ptd->_ownlocale &= ~2u;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004088F4
// Name: _mbtowc
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl mbtowc(wchar_t *pwc, const char *s, unsigned int n)
{
  return _mbtowc_l(pwc, s, n, plocinfo: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x0040890E
// Name: __isleadbyte_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _isleadbyte_l(unsigned __int8 c, localeinfo_struct *plocinfo)
{
  int result; // eax
  _LocaleUpdate _loc_update; // [esp+0h] [ebp-10h] BYREF

  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  result = _loc_update.localeinfo.locinfo->pctype[c] & 0x8000;
  if ( _loc_update.updated )
    _loc_update.ptd->_ownlocale &= ~2u;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00408946
// Name: _isleadbyte
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl isleadbyte(unsigned __int8 c)
{
  return _isleadbyte_l(c, plocinfo: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x00408959
// Name: __isatty
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _isatty(int fh)
{
  if ( fh == -2 )
  {
    *_errno() = 9;
    return 0;
  }
  if ( fh < 0 || fh >= _nhandle )
  {
    *_errno() = 9;
    _invalid_parameter_noinfo();
    return 0;
  }
  return __pioinfo[fh >> 5][fh & 0x1F].osfile & 0x40;
}

//------------------------------------------------------------------------------
// Address: 0x004089AF
// Name: __lseeki64_nolock
// Source: linker_block_proximity
//------------------------------------------------------------------------------
doubleint __cdecl _lseeki64_nolock(int fh, __int64 pos, DWORD mthd)
{
  void *osfhandle; // eax
  DWORD LastError; // eax
  char *p_osfile; // eax
  doubleint newpos; // [esp+8h] [ebp-8h] BYREF

  newpos.bigint = pos;
  osfhandle = (void *)_get_osfhandle(fh);
  if ( osfhandle == (void *)-1 )
  {
    *_errno() = 9;
    return (doubleint)-1LL;
  }
  newpos.twoints.lowerhalf = SetFilePointer(
                               hFile: osfhandle,
                               lDistanceToMove: newpos.twoints.lowerhalf,
                               lpDistanceToMoveHigh: &newpos.twoints.upperhalf,
                               dwMoveMethod: mthd);
  if ( newpos.twoints.lowerhalf == -1 )
  {
    LastError = GetLastError();
    if ( LastError != 0 )
    {
      _dosmaperr(oserrno: LastError);
      return (doubleint)-1LL;
    }
  }
  p_osfile = &__pioinfo[fh >> 5][fh & 0x1F].osfile;
  *p_osfile &= ~2u;
  return newpos;
}

//------------------------------------------------------------------------------
// Address: 0x00408A34
// Name: __lseeki64
// Source: linker_block_proximity
//------------------------------------------------------------------------------
doubleint __cdecl _lseeki64(int fh, __int64 pos, DWORD mthd)
{
  ioinfo **v4; // edi
  int v5; // esi
  __int64 r; // [esp+10h] [ebp-24h]

  if ( fh == -2 )
  {
    *__doserrno() = 0;
    *_errno() = 9;
    return (doubleint)-1LL;
  }
  if ( fh < 0 || fh >= _nhandle || (v4 = &__pioinfo[fh >> 5], v5 = (fh & 0x1F) << 6, (*(&(*v4)->osfile + v5) & 1) == 0) )
  {
    *__doserrno() = 0;
    *_errno() = 9;
    _invalid_parameter_noinfo();
    return (doubleint)-1LL;
  }
  __lock_fhandle(fh);
  if ( (*(&(*v4)->osfile + v5) & 1) != 0 )
  {
    r = _lseeki64_nolock(fh, pos, mthd).bigint;
  }
  else
  {
    *_errno() = 9;
    *__doserrno() = 0;
    r = -1;
  }
  _unlock_fhandle(fh);
  return (doubleint)r;
}

//------------------------------------------------------------------------------
// Address: 0x00408B20
// Name: __chkstk
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void *__usercall _chkstk@<eax>(unsigned int a1@<eax>, int a2@<ecx>)
{
  unsigned int v2; // ecx
  unsigned int i; // eax
  int v5; // [esp-4h] [ebp-4h] BYREF
  _UNKNOWN *retaddr; // [esp+0h] [ebp+0h] BYREF

  v5 = a2;
  v2 = ~((unsigned int)((unsigned int)&retaddr - (unsigned __int64)a1) >> 32) & ((unsigned int)&retaddr - a1);
  for ( i = (unsigned int)&v5 & 0xFFFFF000; v2 < i; i -= 4096 )
    ;
  return retaddr;
}

//------------------------------------------------------------------------------
// Address: 0x00408B4B
// Name: CPtoLCID
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall CPtoLCID@<eax>(int codepage@<eax>)
{
  int v1; // eax
  int v2; // eax
  int v3; // eax

  v1 = codepage - 932;
  if ( v1 == 0 )
    return 1041;
  v2 = v1 - 4;
  if ( v2 == 0 )
    return 2052;
  v3 = v2 - 13;
  if ( v3 == 0 )
    return 1042;
  if ( v3 == 1 )
    return 1028;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x00408B7A
// Name: setSBCS
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall setSBCS(threadmbcinfostruct *ptmbci@<eax>)
{
  unsigned __int8 *mbctype; // eax
  int v3; // ecx
  int i; // edi
  unsigned __int8 *mbcasemap; // eax
  int j; // esi

  memset(dst: (int)ptmbci->mbctype, value: nullptr, count: sizeof(ptmbci->mbctype));
  ptmbci->mbcodepage = 0;
  ptmbci->ismbcodepage = 0;
  ptmbci->mblcid = 0;
  *(_DWORD *)ptmbci->mbulinfo = 0;
  *(_DWORD *)&ptmbci->mbulinfo[2] = 0;
  *(_DWORD *)&ptmbci->mbulinfo[4] = 0;
  mbctype = ptmbci->mbctype;
  v3 = (char *)&__initialmbcinfo - (char *)ptmbci;
  for ( i = 257; i != 0; --i )
  {
    *mbctype = mbctype[v3];
    ++mbctype;
  }
  mbcasemap = ptmbci->mbcasemap;
  for ( j = 256; j != 0; --j )
  {
    *mbcasemap = mbcasemap[v3];
    ++mbcasemap;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00408BDE
// Name: setSBUpLow
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall setSBUpLow(threadmbcinfostruct *ptmbci@<esi>)
{
  unsigned int i; // eax
  unsigned __int8 v2; // al
  unsigned __int8 *v3; // ebx
  unsigned int v4; // ecx
  unsigned int v5; // eax
  int v6; // eax
  unsigned __int16 v7; // cx
  unsigned __int8 v8; // cl
  unsigned int v9; // ecx
  unsigned __int8 *v10; // eax
  unsigned __int8 v11; // dl
  int v12; // [esp+8h] [ebp-51Ch]
  _cpinfo cpinfo; // [esp+Ch] [ebp-518h] BYREF
  unsigned __int16 wVector[256]; // [esp+20h] [ebp-504h] BYREF
  unsigned __int8 upVector[256]; // [esp+220h] [ebp-304h] BYREF
  unsigned __int8 lowVector[256]; // [esp+320h] [ebp-204h] BYREF
  unsigned __int8 sbVector[256]; // [esp+420h] [ebp-104h] BYREF

  if ( GetCPInfo(CodePage: ptmbci->mbcodepage, lpCPInfo: &cpinfo) )
  {
    for ( i = 0; i < 0x100; ++i )
      sbVector[i] = i;
    v2 = cpinfo.LeadByte[0];
    sbVector[0] = 32;
    if ( cpinfo.LeadByte[0] != 0 )
    {
      v3 = &cpinfo.LeadByte[1];
      do
      {
        v4 = v2;
        v5 = *v3;
        if ( v4 <= v5 )
          memset(dst: (int)&sbVector[v4], value: (unsigned __int8 *)0x20, count: v5 - v4 + 1);
        v2 = v3[1];
        v3 += 2;
      }
      while ( v2 != 0 );
    }
    __crtGetStringTypeA(
      plocinfo: nullptr,
      dwInfoType: 1u,
      lpSrcStr: (const char *)sbVector,
      cchSrc: 256,
      lpCharType: wVector,
      code_page: ptmbci->mbcodepage,
      lcid: ptmbci->mblcid,
      bError: 0);
    __crtLCMapStringA(
      plocinfo: nullptr,
      Locale: ptmbci->mblcid,
      dwMapFlags: 0x100u,
      lpSrcStr: (const char *)sbVector,
      cchSrc: 256,
      lpDestStr: (char *)lowVector,
      cchDest: 256,
      code_page: ptmbci->mbcodepage,
      bError: 0);
    __crtLCMapStringA(
      plocinfo: nullptr,
      Locale: ptmbci->mblcid,
      dwMapFlags: 0x200u,
      lpSrcStr: (const char *)sbVector,
      cchSrc: 256,
      lpDestStr: (char *)upVector,
      cchDest: 256,
      code_page: ptmbci->mbcodepage,
      bError: 0);
    v6 = 0;
    while ( 1 )
    {
      v7 = wVector[v6];
      if ( (v7 & 1) != 0 )
      {
        ptmbci->mbctype[v6 + 1] |= 0x10u;
        v8 = lowVector[v6];
      }
      else
      {
        if ( (v7 & 2) == 0 )
        {
          ptmbci->mbcasemap[v6] = 0;
          goto LABEL_16;
        }
        ptmbci->mbctype[v6 + 1] |= 0x20u;
        v8 = upVector[v6];
      }
      ptmbci->mbcasemap[v6] = v8;
LABEL_16:
      if ( (unsigned int)++v6 >= 0x100 )
        return;
    }
  }
  v9 = 0;
  v12 = -97 - (_DWORD)ptmbci->mbcasemap;
  do
  {
    v10 = &ptmbci->mbcasemap[v9];
    if ( (unsigned int)&v10[v12 + 32] <= 0x19 )
    {
      ptmbci->mbctype[v9 + 1] |= 0x10u;
      v11 = v9 + 32;
LABEL_23:
      *v10 = v11;
      goto LABEL_25;
    }
    if ( (unsigned int)&v10[v12] <= 0x19 )
    {
      ptmbci->mbctype[v9 + 1] |= 0x20u;
      v11 = v9 - 32;
      goto LABEL_23;
    }
    *v10 = 0;
LABEL_25:
    ++v9;
  }
  while ( v9 < 0x100 );
}

//------------------------------------------------------------------------------
// Address: 0x00408D6E
// Name: ___updatetmbcinfo
// Source: linker_block_proximity
//------------------------------------------------------------------------------
threadmbcinfostruct *__cdecl __updatetmbcinfo()
{
  _tiddata *v0; // edi
  threadmbcinfostruct *ptmbcinfo; // esi

  v0 = _getptd();
  if ( (__globallocalestatus & v0->_ownlocale) != 0 && v0->ptlocinfo != nullptr )
  {
    ptmbcinfo = v0->ptmbcinfo;
  }
  else
  {
    _lock(locknum: 13);
    ptmbcinfo = v0->ptmbcinfo;
    if ( ptmbcinfo != __ptmbcinfo )
    {
      if ( ptmbcinfo != nullptr
        && InterlockedDecrement(lpAddend: &ptmbcinfo->refcount) == 0
        && ptmbcinfo != &__initialmbcinfo )
      {
        free(pBlock: ptmbcinfo);
      }
      v0->ptmbcinfo = __ptmbcinfo;
      ptmbcinfo = __ptmbcinfo;
      InterlockedIncrement(lpAddend: &__ptmbcinfo->refcount);
    }
    _unlock(locknum: 13);
  }
  if ( ptmbcinfo == nullptr )
    _amsg_exit(rterrnum: 32);
  return ptmbcinfo;
}

//------------------------------------------------------------------------------
// Address: 0x00408E12
// Name: getSystemCP
// Source: linker_block_proximity
//------------------------------------------------------------------------------
UINT __usercall getSystemCP@<eax>(int codepage@<esi>)
{
  UINT result; // eax
  _LocaleUpdate _loc_update; // [esp+4h] [ebp-10h] BYREF

  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo: nullptr);
  fSystemSet = 0;
  switch ( codepage )
  {
    case -2:
      fSystemSet = 1;
      result = GetOEMCP();
      goto LABEL_3;
    case -3:
      fSystemSet = 1;
      result = GetACP();
      goto LABEL_3;
    case -4:
      result = _loc_update.localeinfo.locinfo->lc_codepage;
      fSystemSet = 1;
LABEL_3:
      if ( _loc_update.updated )
        _loc_update.ptd->_ownlocale &= ~2u;
      return result;
    default:
      break;
  }
  if ( _loc_update.updated )
    _loc_update.ptd->_ownlocale &= ~2u;
  return codepage;
}

//------------------------------------------------------------------------------
// Address: 0x00408E8E
// Name: __setmbcp_nolock
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _setmbcp_nolock(int codepage, threadmbcinfostruct *ptmbci)
{
  UINT SystemCP; // edi
  unsigned int i; // eax
  unsigned __int8 *v5; // esi
  unsigned __int8 v6; // cl
  unsigned int k; // eax
  unsigned __int8 *v8; // esi
  unsigned int v9; // eax
  unsigned int v10; // edi
  unsigned __int16 *mbulinfo; // eax
  int v12; // ecx
  unsigned __int16 *v13; // ecx
  int j; // edx
  unsigned __int8 *v15; // eax
  int m; // ecx
  int v17; // edx
  unsigned int irg; // [esp+Ch] [ebp-20h]
  unsigned int icp; // [esp+10h] [ebp-1Ch]
  unsigned int icpa; // [esp+10h] [ebp-1Ch]
  _cpinfo cpinfo; // [esp+14h] [ebp-18h] BYREF
  int codepagea; // [esp+34h] [ebp+8h]

  SystemCP = getSystemCP(codepage);
  codepagea = SystemCP;
  if ( SystemCP != 0 )
  {
    icp = 0;
    for ( i = 0; i < 5; ++i )
    {
      if ( _rgcode_page_info[i].code_page == SystemCP )
      {
        memset(dst: (int)ptmbci->mbctype, value: nullptr, count: sizeof(ptmbci->mbctype));
        irg = 0;
        v8 = _rgcode_page_info[icp].rgrange[0];
        icpa = (unsigned int)v8;
        do
        {
          while ( *v8 != 0 )
          {
            LOBYTE(v9) = v8[1];
            if ( (_BYTE)v9 == 0 )
              break;
            v10 = *v8;
            v9 = (unsigned __int8)v9;
            while ( v10 <= v9 )
            {
              ptmbci->mbctype[v10 + 1] |= _rgctypeflag[irg];
              v9 = v8[1];
              ++v10;
            }
            SystemCP = codepagea;
            v8 += 2;
          }
          ++irg;
          v8 = (unsigned __int8 *)(icpa + 8);
          icpa += 8;
        }
        while ( irg < 4 );
        ptmbci->mbcodepage = SystemCP;
        ptmbci->ismbcodepage = 1;
        ptmbci->mblcid = CPtoLCID(codepage: SystemCP);
        mbulinfo = ptmbci->mbulinfo;
        v13 = (unsigned __int16 *)((char *)_rgcode_page_info[0].mbulinfo + v12);
        for ( j = 6; j != 0; --j )
          *mbulinfo++ = *v13++;
LABEL_26:
        setSBUpLow(ptmbci);
        return 0;
      }
      ++icp;
    }
    if ( SystemCP == 65000 || SystemCP == 65001 || !IsValidCodePage(CodePage: (unsigned __int16)SystemCP) )
      return -1;
    if ( GetCPInfo(CodePage: SystemCP, lpCPInfo: &cpinfo) )
    {
      memset(dst: (int)ptmbci->mbctype, value: nullptr, count: sizeof(ptmbci->mbctype));
      ptmbci->mbcodepage = SystemCP;
      ptmbci->mblcid = 0;
      if ( cpinfo.MaxCharSize <= 1 )
      {
        ptmbci->ismbcodepage = 0;
      }
      else
      {
        if ( cpinfo.LeadByte[0] != 0 )
        {
          v5 = &cpinfo.LeadByte[1];
          do
          {
            v6 = *v5;
            if ( *v5 == 0 )
              break;
            for ( k = *(v5 - 1); k <= v6; ++k )
              ptmbci->mbctype[k + 1] |= 4u;
            v5 += 2;
          }
          while ( *(v5 - 1) != 0 );
        }
        v15 = &ptmbci->mbctype[2];
        for ( m = 254; m != 0; --m )
          *v15++ |= 8u;
        ptmbci->mblcid = CPtoLCID(codepage: ptmbci->mbcodepage);
        ptmbci->ismbcodepage = v17;
      }
      *(_DWORD *)ptmbci->mbulinfo = 0;
      *(_DWORD *)&ptmbci->mbulinfo[2] = 0;
      *(_DWORD *)&ptmbci->mbulinfo[4] = 0;
      goto LABEL_26;
    }
    if ( fSystemSet == 0 )
      return -1;
  }
  setSBCS(ptmbci);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x00409077
// Name: __setmbcp
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _setmbcp(int codepage)
{
  _tiddata *v1; // edi
  threadmbcinfostruct *ptmbcinfo; // ebx
  threadmbcinfostruct *v3; // eax
  threadmbcinfostruct *v4; // ebx
  int v5; // eax
  int i; // eax
  int j; // eax
  int k; // eax
  int retcode; // [esp+14h] [ebp-20h]
  UINT codepagea; // [esp+3Ch] [ebp+8h]

  retcode = -1;
  v1 = _getptd();
  __updatetmbcinfo();
  ptmbcinfo = v1->ptmbcinfo;
  codepagea = getSystemCP(codepage);
  if ( codepagea == ptmbcinfo->mbcodepage )
    return 0;
  v3 = (threadmbcinfostruct *)_malloc_crt(cb: 0x220u);
  v4 = v3;
  if ( v3 != nullptr )
  {
    qmemcpy(v3, v1->ptmbcinfo, sizeof(threadmbcinfostruct));
    v3->refcount = 0;
    v5 = _setmbcp_nolock(codepage: codepagea, ptmbci: v3);
    retcode = v5;
    if ( v5 != 0 )
    {
      if ( v5 == -1 )
      {
        if ( v4 != &__initialmbcinfo )
          free(pBlock: v4);
        *_errno() = 22;
      }
    }
    else
    {
      if ( InterlockedDecrement(lpAddend: &v1->ptmbcinfo->refcount) == 0 && v1->ptmbcinfo != &__initialmbcinfo )
        free(pBlock: v1->ptmbcinfo);
      v1->ptmbcinfo = v4;
      InterlockedIncrement(lpAddend: &v4->refcount);
      if ( (v1->_ownlocale & 2) == 0 && (__globallocalestatus & 1) == 0 )
      {
        _lock(locknum: 13);
        __mbcodepage = v4->mbcodepage;
        __ismbcodepage = v4->ismbcodepage;
        __mblcid = v4->mblcid;
        for ( i = 0; i < 5; ++i )
          __mbulinfo[i] = v4->mbulinfo[i];
        for ( j = 0; j < 257; ++j )
          _mbctype[j] = v4->mbctype[j];
        for ( k = 0; k < 256; ++k )
          _mbcasemap[k] = v4->mbcasemap[k];
        if ( InterlockedDecrement(lpAddend: &__ptmbcinfo->refcount) == 0 && __ptmbcinfo != &__initialmbcinfo )
          free(pBlock: __ptmbcinfo);
        __ptmbcinfo = v4;
        InterlockedIncrement(lpAddend: &v4->refcount);
        _unlock(locknum: 13);
      }
    }
  }
  return retcode;
}

//------------------------------------------------------------------------------
// Address: 0x00409211
// Name: ___initmbctable
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl __initmbctable()
{
  if ( __mbctype_initialized == 0 )
  {
    _setmbcp(codepage: -3);
    __mbctype_initialized = 1;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x0040922F
// Name: ___addlocaleref
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl __addlocaleref(threadlocaleinfostruct *ptloci)
{
  volatile LONG **p_refcount; // ebx
  int ptlocia; // [esp+14h] [ebp+8h]

  InterlockedIncrement(lpAddend: &ptloci->refcount);
  if ( ptloci->lconv_intl_refcount != nullptr )
    InterlockedIncrement(lpAddend: ptloci->lconv_intl_refcount);
  if ( ptloci->lconv_mon_refcount != nullptr )
    InterlockedIncrement(lpAddend: ptloci->lconv_mon_refcount);
  if ( ptloci->lconv_num_refcount != nullptr )
    InterlockedIncrement(lpAddend: ptloci->lconv_num_refcount);
  if ( ptloci->ctype1_refcount != nullptr )
    InterlockedIncrement(lpAddend: ptloci->ctype1_refcount);
  p_refcount = (volatile LONG **)&ptloci->lc_category[0].refcount;
  for ( ptlocia = 6; ptlocia != 0; --ptlocia )
  {
    if ( *(p_refcount - 2) != (volatile LONG *)__clocalestr && *p_refcount != nullptr )
      InterlockedIncrement(lpAddend: *p_refcount);
    if ( *(p_refcount - 1) != nullptr && p_refcount[1] != nullptr )
      InterlockedIncrement(lpAddend: p_refcount[1]);
    p_refcount += 4;
  }
  InterlockedIncrement(lpAddend: &ptloci->lc_time_curr->refcount);
}

//------------------------------------------------------------------------------
// Address: 0x004092BE
// Name: ___removelocaleref
// Source: linker_block_proximity
//------------------------------------------------------------------------------
threadlocaleinfostruct *__cdecl __removelocaleref(threadlocaleinfostruct *ptloci)
{
  volatile LONG **p_refcount; // ebx
  int ptlocia; // [esp+Ch] [ebp+8h]

  if ( ptloci != nullptr )
  {
    InterlockedDecrement(lpAddend: &ptloci->refcount);
    if ( ptloci->lconv_intl_refcount != nullptr )
      InterlockedDecrement(lpAddend: ptloci->lconv_intl_refcount);
    if ( ptloci->lconv_mon_refcount != nullptr )
      InterlockedDecrement(lpAddend: ptloci->lconv_mon_refcount);
    if ( ptloci->lconv_num_refcount != nullptr )
      InterlockedDecrement(lpAddend: ptloci->lconv_num_refcount);
    if ( ptloci->ctype1_refcount != nullptr )
      InterlockedDecrement(lpAddend: ptloci->ctype1_refcount);
    p_refcount = (volatile LONG **)&ptloci->lc_category[0].refcount;
    for ( ptlocia = 6; ptlocia != 0; --ptlocia )
    {
      if ( *(p_refcount - 2) != (volatile LONG *)__clocalestr && *p_refcount != nullptr )
        InterlockedDecrement(lpAddend: *p_refcount);
      if ( *(p_refcount - 1) != nullptr && p_refcount[1] != nullptr )
        InterlockedDecrement(lpAddend: p_refcount[1]);
      p_refcount += 4;
    }
    InterlockedDecrement(lpAddend: &ptloci->lc_time_curr->refcount);
  }
  return ptloci;
}

//------------------------------------------------------------------------------
// Address: 0x00409357
// Name: ___freetlocinfo
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl __freetlocinfo(threadlocaleinfostruct *ptloci)
{
  lconv *lconv; // eax
  int *lconv_intl_refcount; // eax
  int *lconv_mon_refcount; // eax
  int *lconv_num_refcount; // eax
  int *ctype1_refcount; // eax
  __lc_time_data *lc_time_curr; // eax
  void **p_refcount; // edi
  _DWORD *v9; // eax
  int ptlocia; // [esp+14h] [ebp+8h]

  lconv = ptloci->lconv;
  if ( lconv != nullptr && lconv != &__lconv_c )
  {
    lconv_intl_refcount = ptloci->lconv_intl_refcount;
    if ( lconv_intl_refcount != nullptr && *lconv_intl_refcount == 0 )
    {
      lconv_mon_refcount = ptloci->lconv_mon_refcount;
      if ( lconv_mon_refcount != nullptr && *lconv_mon_refcount == 0 )
      {
        free(pBlock: ptloci->lconv_mon_refcount);
        __free_lconv_mon(l: ptloci->lconv);
      }
      lconv_num_refcount = ptloci->lconv_num_refcount;
      if ( lconv_num_refcount != nullptr && *lconv_num_refcount == 0 )
      {
        free(pBlock: ptloci->lconv_num_refcount);
        __free_lconv_num(l: ptloci->lconv);
      }
      free(pBlock: ptloci->lconv_intl_refcount);
      free(pBlock: ptloci->lconv);
    }
  }
  ctype1_refcount = ptloci->ctype1_refcount;
  if ( ctype1_refcount != nullptr && *ctype1_refcount == 0 )
  {
    free(pBlock: ptloci->ctype1 - 127);
    free(pBlock: (void *)(ptloci->pclmap - 128));
    free(pBlock: (void *)(ptloci->pcumap - 128));
    free(pBlock: ptloci->ctype1_refcount);
  }
  lc_time_curr = ptloci->lc_time_curr;
  if ( lc_time_curr != &__lc_time_c && lc_time_curr->refcount == 0 )
  {
    __free_lc_time(lc_time: ptloci->lc_time_curr);
    free(pBlock: ptloci->lc_time_curr);
  }
  p_refcount = (void **)&ptloci->lc_category[0].refcount;
  for ( ptlocia = 6; ptlocia != 0; --ptlocia )
  {
    if ( *(p_refcount - 2) != __clocalestr && *p_refcount != nullptr && *(_DWORD *)*p_refcount == 0 )
      free(pBlock: *p_refcount);
    if ( *(p_refcount - 1) != nullptr )
    {
      v9 = p_refcount[1];
      if ( v9 != nullptr && *v9 == 0 )
        free(pBlock: p_refcount[1]);
    }
    p_refcount += 4;
  }
  free(pBlock: ptloci);
}

//------------------------------------------------------------------------------
// Address: 0x004094A2
// Name: __updatetlocinfoEx_nolock
// Source: linker_block_proximity
//------------------------------------------------------------------------------
threadlocaleinfostruct *__cdecl _updatetlocinfoEx_nolock(
        threadlocaleinfostruct **pptlocid,
        threadlocaleinfostruct *ptlocis)
{
  threadlocaleinfostruct *v2; // esi

  if ( ptlocis == nullptr || pptlocid == nullptr )
    return nullptr;
  v2 = *pptlocid;
  if ( *pptlocid != ptlocis )
  {
    *pptlocid = ptlocis;
    __addlocaleref(ptloci: ptlocis);
    if ( v2 != nullptr )
    {
      __removelocaleref(ptloci: v2);
      if ( v2->refcount == 0 && v2 != &__initiallocinfo )
        __freetlocinfo(ptloci: v2);
    }
  }
  return ptlocis;
}

//------------------------------------------------------------------------------
// Address: 0x004094EF
// Name: ___updatetlocinfo
// Source: linker_block_proximity
//------------------------------------------------------------------------------
threadlocaleinfostruct *__cdecl __updatetlocinfo()
{
  _tiddata *v0; // esi
  threadlocaleinfostruct *ptlocinfo; // esi
  threadlocaleinfostruct *ptloci; // [esp+10h] [ebp-1Ch]

  v0 = _getptd();
  if ( (__globallocalestatus & v0->_ownlocale) != 0 && v0->ptlocinfo != nullptr )
  {
    ptlocinfo = _getptd()->ptlocinfo;
  }
  else
  {
    _lock(locknum: 12);
    ptloci = _updatetlocinfoEx_nolock(pptlocid: &v0->ptlocinfo, ptlocis: __ptlocinfo);
    _unlock(locknum: 12);
    ptlocinfo = ptloci;
  }
  if ( ptlocinfo == nullptr )
    _amsg_exit(rterrnum: 32);
  return ptlocinfo;
}

//------------------------------------------------------------------------------
// Address: 0x00409568
// Name: __flsbuf
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _flsbuf(unsigned __int8 ch, int str)
{
  _iobuf *v2; // esi
  int flag; // eax
  unsigned int v5; // eax
  char *base; // eax
  char *ptr; // edi
  signed int v8; // edi
  ioinfo *v9; // eax
  doubleint v10; // rax
  int written; // [esp+4h] [ebp-4h]

  v2 = (_iobuf *)str;
  str = _fileno(stream: (_iobuf *)str);
  flag = v2->_flag;
  if ( (flag & 0x82) == 0 )
  {
    *_errno() = 9;
LABEL_3:
    v2->_flag |= 0x20u;
    return -1;
  }
  if ( (flag & 0x40) != 0 )
  {
    *_errno() = 34;
    goto LABEL_3;
  }
  if ( (flag & 1) != 0 )
  {
    v2->_cnt = 0;
    if ( (flag & 0x10) == 0 )
    {
      v2->_flag = flag | 0x20;
      return -1;
    }
    v2->_ptr = v2->_base;
    v2->_flag = flag & 0xFFFFFFFE;
  }
  v5 = v2->_flag & 0xFFFFFFED | 2;
  v2->_flag = v5;
  v2->_cnt = 0;
  written = 0;
  if ( (v5 & 0x10C) == 0 && (v2 != &__iob_func()[1] && v2 != &__iob_func()[2] || _isatty(fh: str) == 0) )
    _getbuf(str: v2);
  if ( (v2->_flag & 0x108) != 0 )
  {
    base = v2->_base;
    ptr = v2->_ptr;
    v2->_ptr = base + 1;
    v8 = ptr - base;
    v2->_cnt = v2->_bufsiz - 1;
    if ( v8 <= 0 )
    {
      if ( str == -1 || str == -2 )
        v9 = &__badioinfo;
      else
        v9 = &__pioinfo[str >> 5][str & 0x1F];
      if ( (v9->osfile & 0x20) != 0 )
      {
        v10.bigint = _lseeki64(fh: str, pos: 0, mthd: 2u).bigint;
        if ( (v10.twoints.upperhalf & v10.twoints.lowerhalf) == -1 )
          goto LABEL_27;
      }
    }
    else
    {
      written = _write(fh: str, buf: base, cnt: v8);
    }
    *v2->_base = ch;
  }
  else
  {
    v8 = 1;
    written = _write(fh: str, buf: (char *)&ch, cnt: 1u);
  }
  if ( written != v8 )
  {
LABEL_27:
    v2->_flag |= 0x20u;
    return -1;
  }
  return ch;
}

//------------------------------------------------------------------------------
// Address: 0x004096EF
// Name: __wctomb_s_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _wctomb_s_l(
        int *pRetValue,
        char *dst,
        unsigned int sizeInBytes,
        wchar_t wchar,
        localeinfo_struct *plocinfo)
{
  char *v5; // esi
  unsigned int v6; // edi
  int result; // eax
  int v8; // esi
  int v9; // eax
  _LocaleUpdate _loc_update; // [esp+Ch] [ebp-10h] BYREF

  v5 = dst;
  v6 = sizeInBytes;
  if ( dst == nullptr && sizeInBytes != 0 )
  {
    if ( pRetValue != nullptr )
      *pRetValue = 0;
    return 0;
  }
  if ( pRetValue != nullptr )
    *pRetValue = -1;
  if ( v6 > 0x7FFFFFFF )
  {
    v8 = 22;
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return v8;
  }
  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  if ( _loc_update.localeinfo.locinfo->lc_handle[2] == 0 )
  {
    if ( wchar > 0xFFu )
    {
      if ( v5 != nullptr && v6 != 0 )
        memset(dst: (int)v5, value: nullptr, count: v6);
      goto LABEL_16;
    }
    if ( v5 != nullptr )
    {
      if ( v6 == 0 )
      {
LABEL_21:
        v8 = 34;
        *_errno() = 34;
        _invalid_parameter_noinfo();
        if ( _loc_update.updated )
          _loc_update.ptd->_ownlocale &= ~2u;
        return v8;
      }
      *v5 = wchar;
    }
    if ( pRetValue != nullptr )
      *pRetValue = 1;
LABEL_26:
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
    return 0;
  }
  dst = nullptr;
  v9 = WideCharToMultiByte(
         CodePage: _loc_update.localeinfo.locinfo->lc_codepage,
         dwFlags: 0,
         lpWideCharStr: &wchar,
         cchWideChar: 1,
         lpMultiByteStr: v5,
         cbMultiByte: v6,
         lpDefaultChar: nullptr,
         lpUsedDefaultChar: (LPBOOL)&dst);
  if ( v9 != 0 )
  {
    if ( dst == nullptr )
    {
      if ( pRetValue != nullptr )
        *pRetValue = v9;
      goto LABEL_26;
    }
  }
  else if ( GetLastError() == 122 )
  {
    if ( v5 != nullptr && v6 != 0 )
      memset(dst: (int)v5, value: nullptr, count: v6);
    goto LABEL_21;
  }
LABEL_16:
  *_errno() = 42;
  result = *_errno();
  if ( _loc_update.updated )
    _loc_update.ptd->_ownlocale &= ~2u;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00409844
// Name: _wctomb_s
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl wctomb_s(int *pRetValue, char *dst, unsigned int sizeInBytes, wchar_t wchar)
{
  return _wctomb_s_l(pRetValue, dst, sizeInBytes, wchar, plocinfo: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x00409870
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
// Address: 0x00409905
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
  int v18; // edi
  int v19; // eax
  unsigned int v20; // eax
  unsigned int v21; // eax
  int v22; // edi
  doubleint v23; // rax
  int v24; // eax
  doubleint v25; // rax
  unsigned int v26; // eax
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
    _set_osfhnd(fh: *pfh, value: osfh);
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
        v18 = _lseek_nolock(fh: *pfh, pos: -1, mthd: 2);
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
        if ( _lseeki64_nolock(fh: *pfh, pos: 0, mthd: 2u).bigint != 0 )
        {
          v25.bigint = _lseeki64_nolock(fh: *pfh, pos: 0, mthd: 0).bigint;
          v26 = v25.twoints.upperhalf & v25.twoints.lowerhalf;
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
          if ( _lseeki64_nolock(fh: *pfh, pos: 0, mthd: 2u).bigint != 0 )
          {
            v23.bigint = _lseeki64_nolock(fh: *pfh, pos: 0, mthd: 0).bigint;
            if ( (v23.twoints.upperhalf & v23.twoints.lowerhalf) == -1 )
              goto LABEL_74;
LABEL_109:
            v24 = _read_nolock(fh: *pfh, inputbuf: &bom, cnt: 3u);
            if ( v24 == -1 )
              goto LABEL_74;
            if ( v24 != 2 )
            {
              if ( v24 != 3 )
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
// Address: 0x0040A039
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
    retval = tsopen_nolock(pfh, a2: 0, punlock_flag: &unlock_flag, path, oflag, shflag, pmode);
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
// Address: 0x0040A0FD
// Name: __sopen_s
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _sopen_s(int *pfh, const char *path, int oflag, int shflag, int pmode)
{
  return _sopen_helper(path, oflag, shflag, pmode, pfh, bSecure: 1);
}

//------------------------------------------------------------------------------
// Address: 0x0040A11D
// Name: __mbsnbicmp_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _mbsnbicmp_l(
        const unsigned __int8 *s1,
        const unsigned __int8 *s2,
        unsigned int n,
        localeinfo_struct *plocinfo)
{
  int result; // eax
  const unsigned __int8 *v5; // edi
  int v6; // ecx
  bool v7; // zf
  int v8; // ecx
  unsigned __int16 v9; // si
  unsigned __int8 v10; // dl
  int v11; // ecx
  char *v12; // ecx
  int v13; // ecx
  int v14; // ecx
  int v15; // ecx
  char *v16; // ecx
  _LocaleUpdate _loc_update; // [esp+4h] [ebp-18h] BYREF
  int c1; // [esp+14h] [ebp-8h]
  int c2; // [esp+18h] [ebp-4h]

  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  if ( n == 0 )
  {
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
    return 0;
  }
  if ( _loc_update.localeinfo.mbcinfo->ismbcodepage == 0 )
  {
    result = _strnicmp(dst: (const char *)s1, src: (const char *)s2, count: n);
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
    return result;
  }
  if ( s1 == nullptr )
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
    return 0x7FFFFFFF;
  }
  v5 = s2;
  if ( s2 == nullptr )
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
    return 0x7FFFFFFF;
  }
  while ( 1 )
  {
    v6 = *s1;
    --n;
    ++s1;
    v7 = (_loc_update.localeinfo.mbcinfo->mbctype[(unsigned __int8)v6 + 1] & 4) == 0;
    c1 = v6;
    if ( v7 )
    {
      v12 = (char *)_loc_update.localeinfo.mbcinfo + (unsigned __int16)c1;
      if ( (v12[29] & 0x10) != 0 )
        v13 = (unsigned __int8)v12[285];
      else
        v13 = (unsigned __int16)c1;
      c1 = v13;
      goto LABEL_32;
    }
    if ( n == 0 )
    {
      v8 = *v5;
      v7 = (_loc_update.localeinfo.mbcinfo->mbctype[v8 + 1] & 4) == 0;
      c1 = 0;
      if ( !v7 )
        goto LABEL_51;
      v9 = 0;
      goto LABEL_46;
    }
    if ( *s1 == 0 )
    {
      c1 = 0;
LABEL_32:
      v9 = c1;
      goto LABEL_33;
    }
    v10 = *s1++;
    v11 = (unsigned __int16)(v10 | (unsigned __int16)((_WORD)v6 << 8));
    v9 = v11;
    c1 = v11;
    if ( (unsigned __int16)v11 < _loc_update.localeinfo.mbcinfo->mbulinfo[0]
      || (unsigned __int16)v11 > _loc_update.localeinfo.mbcinfo->mbulinfo[1] )
    {
      if ( (unsigned __int16)v11 >= _loc_update.localeinfo.mbcinfo->mbulinfo[3]
        && (unsigned __int16)v11 <= _loc_update.localeinfo.mbcinfo->mbulinfo[4] )
      {
        v9 = _loc_update.localeinfo.mbcinfo->mbulinfo[5] + v11;
      }
    }
    else
    {
      v9 = _loc_update.localeinfo.mbcinfo->mbulinfo[2] + v11;
    }
LABEL_33:
    v14 = *v5++;
    v7 = (_loc_update.localeinfo.mbcinfo->mbctype[(unsigned __int8)v14 + 1] & 4) == 0;
    c2 = v14;
    if ( v7 )
    {
      v16 = (char *)_loc_update.localeinfo.mbcinfo + (unsigned __int16)c2;
      if ( (v16[29] & 0x10) != 0 )
        v8 = (unsigned __int8)v16[285];
      else
        v8 = (unsigned __int16)c2;
LABEL_46:
      c2 = v8;
      goto LABEL_47;
    }
    if ( n == 0 || (--n, *v5 == 0) )
    {
      c2 = 0;
LABEL_47:
      LOWORD(v15) = c2;
      goto test;
    }
    v15 = (unsigned __int16)(*v5++ | (unsigned __int16)((_WORD)v14 << 8));
    c2 = v15;
    if ( (unsigned __int16)v15 < _loc_update.localeinfo.mbcinfo->mbulinfo[0]
      || (unsigned __int16)v15 > _loc_update.localeinfo.mbcinfo->mbulinfo[1] )
    {
      if ( (unsigned __int16)v15 >= _loc_update.localeinfo.mbcinfo->mbulinfo[3]
        && (unsigned __int16)v15 <= _loc_update.localeinfo.mbcinfo->mbulinfo[4] )
      {
        LOWORD(v15) = _loc_update.localeinfo.mbcinfo->mbulinfo[5] + v15;
      }
    }
    else
    {
      LOWORD(v15) = _loc_update.localeinfo.mbcinfo->mbulinfo[2] + v15;
    }
test:
    if ( (_WORD)v15 != v9 )
      break;
    if ( v9 == 0 || n == 0 )
    {
LABEL_51:
      if ( _loc_update.updated )
        _loc_update.ptd->_ownlocale &= ~2u;
      return 0;
    }
  }
  result = (unsigned __int16)v15 < v9 ? 1 : -1;
  if ( _loc_update.updated )
    _loc_update.ptd->_ownlocale &= ~2u;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0040A321
// Name: __mbsnbicmp
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _mbsnbicmp(const unsigned __int8 *s1, const unsigned __int8 *s2, unsigned int n)
{
  return _mbsnbicmp_l(s1, s2, n, plocinfo: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x0040A33B
// Name: __mbsnbcmp_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _mbsnbcmp_l(
        const unsigned __int8 *s1,
        const unsigned __int8 *s2,
        unsigned int n,
        localeinfo_struct *plocinfo)
{
  int result; // eax
  const unsigned __int8 *v5; // ebx
  const unsigned __int8 *v6; // esi
  unsigned __int16 v7; // cx
  int v8; // eax
  _LocaleUpdate _loc_update; // [esp+0h] [ebp-10h] BYREF

  if ( n == 0 )
    return 0;
  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  if ( _loc_update.localeinfo.mbcinfo->ismbcodepage == 0 )
  {
    result = strncmp(first: (const char *)s1, last: (const char *)s2, count: n);
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
    return result;
  }
  v5 = s1;
  if ( s1 == nullptr )
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
    return 0x7FFFFFFF;
  }
  v6 = s2;
  if ( s2 == nullptr )
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
    return 0x7FFFFFFF;
  }
  while ( 1 )
  {
    v7 = *v5;
    --n;
    ++v5;
    if ( (_loc_update.localeinfo.mbcinfo->mbctype[(unsigned __int8)v7 + 1] & 4) == 0 )
      goto LABEL_24;
    if ( n != 0 )
    {
      if ( *v5 != 0 )
        v7 = *v5++ | (unsigned __int16)(v7 << 8);
      else
        v7 = 0;
LABEL_24:
      LOWORD(v8) = *v6++;
      if ( (_loc_update.localeinfo.mbcinfo->mbctype[(unsigned __int8)v8 + 1] & 4) != 0 )
      {
        if ( n != 0 && (--n, *v6 != 0) )
          LOWORD(v8) = *v6++ | (unsigned __int16)((_WORD)v8 << 8);
        else
          LOWORD(v8) = 0;
      }
      goto test_0;
    }
    v8 = *v6;
    v7 = 0;
    if ( (_loc_update.localeinfo.mbcinfo->mbctype[v8 + 1] & 4) != 0 )
      goto LABEL_17;
test_0:
    if ( (_WORD)v8 != v7 )
      break;
    if ( v7 == 0 || n == 0 )
    {
LABEL_17:
      if ( _loc_update.updated )
        _loc_update.ptd->_ownlocale &= ~2u;
      return 0;
    }
  }
  result = (unsigned __int16)v8 < v7 ? 1 : -1;
  if ( _loc_update.updated )
    _loc_update.ptd->_ownlocale &= ~2u;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0040A487
// Name: __mbsnbcmp
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _mbsnbcmp(const unsigned __int8 *s1, const unsigned __int8 *s2, unsigned int n)
{
  return _mbsnbcmp_l(s1, s2, n, plocinfo: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x0040A4B0
// Name: __global_unwind2
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _global_unwind2(PVOID TargetFrame)
{
  RtlUnwind(TargetFrame, TargetIp: &gu_return, ExceptionRecord: nullptr, ReturnValue: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x0040A4D0
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
// Address: 0x0040A515
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
// Address: 0x0040A599
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
// Address: 0x0040A5BC
// Name: __NLG_Notify1
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __stdcall _NLG_Notify1(int a1)
{
  JUMPOUT(0x40A5D0);
}

//------------------------------------------------------------------------------
// Address: 0x0040A5C5
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
// Address: 0x0040A5E4
// Name: __NLG_Call
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall _NLG_Call@<eax>(int (*a1)(void)@<eax>)
{
  return a1();
}

//------------------------------------------------------------------------------
// Address: 0x0040A5E7
// Name: _malloc
// Source: linker_block_proximity
//------------------------------------------------------------------------------
LPVOID __cdecl malloc(unsigned int size)
{
  SIZE_T v1; // eax
  LPVOID v2; // edi

  if ( size > 0xFFFFFFE0 )
  {
    _callnewh(size);
    *_errno() = 12;
    return nullptr;
  }
  else
  {
    while ( 1 )
    {
      if ( _crtheap == nullptr )
      {
        _FF_MSGBANNER();
        _NMSG_WRITE(rterrnum: 30);
        __crtExitProcess(status: 255);
      }
      v1 = size != 0 ? size : 1;
      v2 = HeapAlloc(hHeap: _crtheap, dwFlags: 0, dwBytes: v1);
      if ( v2 != nullptr )
        return v2;
      if ( _newmode == 0 )
      {
        *_errno() = 12;
LABEL_12:
        *_errno() = 12;
        return v2;
      }
      if ( _callnewh(size) == 0 )
        goto LABEL_12;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040A67B
// Name: __calloc_impl
// Source: linker_block_proximity
//------------------------------------------------------------------------------
LPVOID __cdecl _calloc_impl(unsigned int num, unsigned int size, int *errno_tmp)
{
  LPVOID result; // eax
  SIZE_T v4; // esi

  if ( num != 0 && 0xFFFFFFE0 / num < size )
  {
    *_errno() = 12;
    return nullptr;
  }
  else
  {
    v4 = size * num;
    if ( size * num == 0 )
      v4 = 1;
    while ( 1 )
    {
      result = nullptr;
      if ( v4 <= 0xFFFFFFE0 )
      {
        result = HeapAlloc(hHeap: _crtheap, dwFlags: 8u, dwBytes: v4);
        if ( result != nullptr )
          break;
      }
      if ( _newmode == 0 )
      {
        if ( errno_tmp != nullptr )
          *errno_tmp = 12;
        return result;
      }
      if ( _callnewh(size: v4) == 0 )
      {
        if ( errno_tmp != nullptr )
          *errno_tmp = 12;
        return nullptr;
      }
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0040A6FD
// Name: _realloc
// Source: linker_block_proximity
//------------------------------------------------------------------------------
LPVOID __cdecl realloc(void *pBlock, unsigned int newsize)
{
  unsigned int v3; // esi
  LPVOID v4; // edi
  int *v5; // esi
  DWORD LastError; // eax
  int *v7; // esi
  DWORD v8; // eax

  if ( pBlock == nullptr )
    return malloc(size: newsize);
  v3 = newsize;
  if ( newsize == 0 )
  {
    free(pBlock);
    return nullptr;
  }
  while ( 1 )
  {
    if ( v3 > 0xFFFFFFE0 )
    {
      _callnewh(size: v3);
      *_errno() = 12;
      return nullptr;
    }
    if ( v3 == 0 )
      v3 = 1;
    v4 = HeapReAlloc(hHeap: _crtheap, dwFlags: 0, lpMem: pBlock, dwBytes: v3);
    if ( v4 != nullptr )
      return v4;
    if ( _newmode == 0 )
      break;
    if ( _callnewh(size: v3) == 0 )
    {
      v5 = _errno();
      LastError = GetLastError();
      *v5 = _get_errno_from_oserr(oserrno: LastError);
      return nullptr;
    }
  }
  v7 = _errno();
  v8 = GetLastError();
  *v7 = _get_errno_from_oserr(oserrno: v8);
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x0040A7AA
// Name: __recalloc
// Source: linker_block_proximity
//------------------------------------------------------------------------------
LPVOID __cdecl _recalloc(void *memblock, unsigned int count, unsigned int size)
{
  unsigned int v3; // ebx
  unsigned int v5; // esi
  LPVOID v6; // eax
  LPVOID v7; // edi

  v3 = 0;
  if ( count != 0 && 0xFFFFFFE0 / count < size )
  {
    *_errno() = 12;
    return nullptr;
  }
  else
  {
    v5 = size * count;
    if ( memblock != nullptr )
      v3 = _msize(pblock: memblock);
    v6 = realloc(pBlock: memblock, newsize: v5);
    v7 = v6;
    if ( v6 != nullptr && v3 < v5 )
      memset(dst: (int)v6 + v3, value: nullptr, count: v5 - v3);
    return v7;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040A818
// Name: __isctype_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _isctype_l(int c, int mask, localeinfo_struct *plocinfo)
{
  __int16 v3; // bx
  int v4; // eax
  int v5; // ecx
  int result; // eax
  _LocaleUpdate _loc_update; // [esp+4h] [ebp-18h] BYREF
  char buffer[4]; // [esp+14h] [ebp-8h] BYREF
  unsigned __int16 chartype; // [esp+18h] [ebp-4h] BYREF
  int ca; // [esp+24h] [ebp+8h]

  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  v3 = c;
  if ( (unsigned int)(c + 1) <= 0x100 )
  {
    v4 = _loc_update.localeinfo.locinfo->pctype[c];
    goto LABEL_11;
  }
  ca = c >> 8;
  if ( _isleadbyte_l(c: HIBYTE(v3), plocinfo: &_loc_update.localeinfo) != 0 )
  {
    buffer[0] = ca;
    buffer[1] = v3;
    buffer[2] = 0;
    v5 = 2;
  }
  else
  {
    buffer[0] = v3;
    buffer[1] = 0;
    v5 = 1;
  }
  if ( __crtGetStringTypeA(
         plocinfo: &_loc_update.localeinfo,
         dwInfoType: 1u,
         lpSrcStr: buffer,
         cchSrc: v5,
         lpCharType: &chartype,
         code_page: _loc_update.localeinfo.locinfo->lc_codepage,
         lcid: _loc_update.localeinfo.locinfo->lc_handle[2],
         bError: 1) != 0 )
  {
    v4 = chartype;
LABEL_11:
    result = mask & v4;
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
    return result;
  }
  if ( _loc_update.updated )
    _loc_update.ptd->_ownlocale &= ~2u;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x0040A8D0
// Name: _memcpy
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl memcpy(unsigned __int8 *dst, unsigned __int8 *src, unsigned int count)
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
TrailDown1:
          v7[3] = v6[3];
          break;
        case 2u:
TrailDown2:
          v7[3] = v6[3];
          v7[2] = v6[2];
          break;
        case 3u:
TrailDown3:
          v7[3] = v6[3];
          v7[2] = v6[2];
          v7[1] = v6[1];
          break;
        default:
          __asm { jmp     dword ptr ds:(ByteCopyDown+4)[eax*4] }
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
            goto TrailDown1;
          case 2u:
            goto TrailDown2;
          case 3u:
            goto TrailDown3;
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
            goto TrailDown1;
          case 2u:
            goto TrailDown2;
          case 3u:
            goto TrailDown3;
        }
      }
    }
  }
  else if ( count >= 0x80
         && __sse2_available != 0
         && (v3 = src, v4 = dst, ((unsigned __int8)dst & 0xF) == ((unsigned __int8)src & 0xF)) )
  {
    _VEC_memcpy(dst, src, len: count);
  }
  else
  {
    if ( ((unsigned __int8)v4 & 3) != 0 )
    {
      if ( count >= 4 )
        __asm { jmp     dword ptr ds:(CopyUnwindUp+4)[eax*4] }
      __asm { jmp     dword ptr ds:TrailUp0[ecx*4]; jumptable 0040A929 case 0 }
    }
    v5 = count >> 2;
    switch ( v5 )
    {
      case 0u:
        goto UnwindUp0;
      case 1u:
        goto UnwindUp1;
      case 2u:
        goto UnwindUp2;
      case 3u:
        goto UnwindUp3;
      case 4u:
        goto UnwindUp4;
      case 5u:
        goto UnwindUp5;
      case 6u:
        goto UnwindUp6;
      case 7u:
        *(_DWORD *)&v4[4 * v5 - 28] = *(_DWORD *)&v3[4 * v5 - 28];
UnwindUp6:
        *(_DWORD *)&v4[4 * v5 - 24] = *(_DWORD *)&v3[4 * v5 - 24];
UnwindUp5:
        *(_DWORD *)&v4[4 * v5 - 20] = *(_DWORD *)&v3[4 * v5 - 20];
UnwindUp4:
        *(_DWORD *)&v4[4 * v5 - 16] = *(_DWORD *)&v3[4 * v5 - 16];
UnwindUp3:
        *(_DWORD *)&v4[4 * v5 - 12] = *(_DWORD *)&v3[4 * v5 - 12];
UnwindUp2:
        *(_DWORD *)&v4[4 * v5 - 8] = *(_DWORD *)&v3[4 * v5 - 8];
UnwindUp1:
        *(_DWORD *)&v4[4 * v5 - 4] = *(_DWORD *)&v3[4 * v5 - 4];
        v3 += 4 * v5;
        v4 += 4 * v5;
UnwindUp0:
        switch ( count & 3 )
        {
          case 0u:
            return;
          case 1u:
            goto TrailUp1;
          case 2u:
            goto TrailUp2;
          case 3u:
            goto TrailUp3;
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
TrailUp1:
            *v4 = *v3;
            break;
          case 2u:
TrailUp2:
            *v4 = *v3;
            v4[1] = v3[1];
            break;
          case 3u:
TrailUp3:
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
// Address: 0x0040AC31
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
// Address: 0x0040AC82
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
// Address: 0x0040ACB0
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
// Address: 0x0040AD06
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
// Address: 0x0040AD36
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
// Address: 0x0040AD87
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
// Address: 0x0040ADB5
// Name: __filbuf
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _filbuf(_iobuf *str)
{
  int flag; // eax
  int v2; // eax
  int v3; // eax
  int v4; // eax
  ioinfo **v5; // edi
  ioinfo *v6; // eax
  int v7; // eax
  char *ptr; // ecx
  int result; // eax
  char *base; // [esp-8h] [ebp-Ch]
  unsigned int bufsiz; // [esp-4h] [ebp-8h]

  if ( str == nullptr )
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return -1;
  }
  flag = str->_flag;
  if ( (flag & 0x83) == 0 || (flag & 0x40) != 0 )
    return -1;
  if ( (flag & 2) != 0 )
  {
    str->_flag = flag | 0x20;
    return -1;
  }
  v2 = flag | 1;
  str->_flag = v2;
  if ( (v2 & 0x10C) != 0 )
    str->_ptr = str->_base;
  else
    _getbuf(str);
  bufsiz = str->_bufsiz;
  base = str->_base;
  v3 = _fileno(stream: str);
  v4 = _read(fh: v3, buf: base, cnt: bufsiz);
  str->_cnt = v4;
  if ( v4 == 0 || v4 == -1 )
  {
    str->_flag |= v4 != 0 ? 32 : 16;
    str->_cnt = 0;
    return -1;
  }
  if ( (str->_flag & 0x82) == 0 )
  {
    if ( _fileno(stream: str) == -1 || _fileno(stream: str) == -2 )
    {
      v6 = &__badioinfo;
    }
    else
    {
      v5 = &__pioinfo[_fileno(stream: str) >> 5];
      v6 = &(*v5)[_fileno(stream: str) & 0x1F];
    }
    if ( (v6->osfile & 0x82) == 0x82 )
      str->_flag |= 0x2000u;
  }
  if ( str->_bufsiz == 512 )
  {
    v7 = str->_flag;
    if ( (v7 & 8) != 0 && (v7 & 0x400) == 0 )
      str->_bufsiz = 4096;
  }
  ptr = str->_ptr;
  --str->_cnt;
  result = (unsigned __int8)*ptr;
  str->_ptr = ptr + 1;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0040AED7
// Name: __ungetc_nolock
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _ungetc_nolock(int ch, _iobuf *str)
{
  int v2; // eax
  ioinfo *v3; // ecx
  ioinfo *v4; // eax
  int flag; // eax
  char *v7; // eax
  int v8; // eax

  if ( (str->_flag & 0x40) == 0 )
  {
    v2 = _fileno(stream: str);
    if ( v2 == -1 || v2 == -2 )
      v3 = &__badioinfo;
    else
      v3 = &__pioinfo[v2 >> 5][v2 & 0x1F];
    if ( (*((_BYTE *)v3 + 36) & 0x7F) != 0
      || (v2 == -1 || v2 == -2 ? (v4 = &__badioinfo) : (v4 = &__pioinfo[v2 >> 5][v2 & 0x1F]), *((char *)v4 + 36) < 0) )
    {
      *_errno() = 22;
      _invalid_parameter_noinfo();
      return -1;
    }
  }
  if ( ch == -1 )
    return -1;
  flag = str->_flag;
  if ( (flag & 1) == 0 && ((flag & 0x80u) == 0 || (flag & 2) != 0) )
    return -1;
  if ( str->_base == nullptr )
    _getbuf(str);
  if ( str->_ptr == str->_base )
  {
    if ( str->_cnt != 0 )
      return -1;
    ++str->_ptr;
  }
  v7 = --str->_ptr;
  if ( (str->_flag & 0x40) != 0 )
  {
    if ( *v7 != (_BYTE)ch )
    {
      str->_ptr = v7 + 1;
      return -1;
    }
  }
  else
  {
    *v7 = ch;
  }
  v8 = str->_flag;
  ++str->_cnt;
  str->_flag = v8 & 0xFFFFFFEE | 1;
  return (unsigned __int8)ch;
}

//------------------------------------------------------------------------------
// Address: 0x0040AFBA
// Name: void terminate(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl __noreturn terminate()
{
  void (*v0)(void); // eax

  v0 = (void (*)(void))_getptd()->_terminate;
  if ( v0 != nullptr )
    v0();
  abort();
}

//------------------------------------------------------------------------------
// Address: 0x0040AFF4
// Name: __initp_eh_hooks
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _initp_eh_hooks()
{
  __pInconsistency = (void (__cdecl *)())EncodePointer(Ptr: terminate);
}

//------------------------------------------------------------------------------
// Address: 0x0040B005
// Name: __initp_misc_winsig
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _initp_misc_winsig(void *enull)
{
  ctrlc_action = enull;
  ctrlbreak_action = (void (__cdecl *)(int))enull;
  abort_action = enull;
  term_action = (void (__cdecl *)(int))enull;
}

//------------------------------------------------------------------------------
// Address: 0x0040B023
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
// Address: 0x0040B05A
// Name: ___get_sigabrt
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void (__cdecl *__cdecl __get_sigabrt())(int)
{
  return (void (__cdecl *)(int))DecodePointer(Ptr: abort_action);
}

//------------------------------------------------------------------------------
// Address: 0x0040B067
// Name: _raise
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl raise(int signum)
{
  _tiddata *v1; // edi
  _tiddata *v2; // eax
  int result; // eax
  void (__cdecl **p_XcptAction)(int); // esi
  void (__cdecl *v5)(int); // eax
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
      p_XcptAction = (void (__cdecl **)(int))&ctrlc_action;
      v5 = (void (__cdecl *)(int))ctrlc_action;
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
      p_XcptAction = (void (__cdecl **)(int))&abort_action;
      v5 = (void (__cdecl *)(int))abort_action;
      goto LABEL_18;
    }
  }
LABEL_7:
  v2 = _getptd_noexit();
  v1 = v2;
  if ( v2 == nullptr )
    return -1;
  p_XcptAction = &siglookup(signum, pxcptacttab: (_XCPT_ACTION *)v2->_pxcptacttab)->XcptAction;
  v6 = *p_XcptAction;
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
    goto $LN37_1;
  }
LABEL_33:
  *p_XcptAction = (void (__cdecl *)(int))_encoded_null();
$LN37_1:
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
// Address: 0x0040B20A
// Name: __initp_misc_rand_s
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _initp_misc_rand_s(int (__stdcall *enull)(void *, unsigned int))
{
  g_pfnRtlGenRandom = enull;
}

//------------------------------------------------------------------------------
// Address: 0x0040B219
// Name: __initp_misc_purevirt
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _initp_misc_purevirt(void (__cdecl *enull)())
{
  __pPurecall = enull;
}

//------------------------------------------------------------------------------
// Address: 0x0040B228
// Name: __initp_heap_handler
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _initp_heap_handler(void *enull)
{
  _pnhHeap = enull;
}

//------------------------------------------------------------------------------
// Address: 0x0040B237
// Name: __callnewh
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __cdecl _callnewh(unsigned int size)
{
  int (__cdecl *v1)(unsigned int); // eax

  v1 = (int (__cdecl *)(unsigned int))DecodePointer(Ptr: _pnhHeap);
  return v1 != nullptr && v1(a1: size) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x0040B382
// Name: _atexit
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl atexit(void (__cdecl *func)())
{
  return (_onexit((int (__cdecl *)())func) != nullptr) - 1;
}

//------------------------------------------------------------------------------
// Address: 0x0040B399
// Name: ___crtMessageBoxW
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl __crtMessageBoxW(const wchar_t *lpText, const wchar_t *lpCaption, unsigned int uType)
{
  HMODULE LibraryW; // eax
  HMODULE v4; // ebx
  int (__stdcall *MessageBoxW)(HWND, LPCWSTR, LPCWSTR, UINT); // eax
  HWND (__stdcall *GetActiveWindow)(); // eax
  HWND (__stdcall *GetLastActivePopup)(HWND); // eax
  BOOL (__stdcall *GetUserObjectInformationW)(HANDLE, int, PVOID, DWORD, LPDWORD); // eax
  HWINSTA (__stdcall *GetProcessWindowStation)(); // eax
  int (*v10)(void); // edi
  int (__stdcall *v11)(int, int, tagUSEROBJECTFLAGS *, int, unsigned int *); // eax
  int (__stdcall *v12)(int, int, tagUSEROBJECTFLAGS *, int, unsigned int *); // ebx
  int v13; // eax
  int (*v14)(void); // eax
  int (__stdcall *v15)(HWND__ *); // eax
  int (__stdcall *v16)(HWND__ *, const wchar_t *, const wchar_t *, unsigned int); // eax
  unsigned int nDummy; // [esp+Ch] [ebp-24h] BYREF
  const wchar_t *v19; // [esp+10h] [ebp-20h]
  const wchar_t *v20; // [esp+14h] [ebp-1Ch]
  void *enull; // [esp+18h] [ebp-18h]
  HWND__ *hWndParent; // [esp+1Ch] [ebp-14h]
  tagUSEROBJECTFLAGS uof; // [esp+20h] [ebp-10h] BYREF

  v19 = lpText;
  v20 = lpCaption;
  hWndParent = nullptr;
  enull = _encoded_null();
  if ( pfnMessageBox == nullptr )
  {
    LibraryW = LoadLibraryW(lpLibFileName: L"USER32.DLL");
    v4 = LibraryW;
    if ( LibraryW == nullptr )
      return 0;
    MessageBoxW = (int (__stdcall *)(HWND, LPCWSTR, LPCWSTR, UINT))GetProcAddress(
                                                                     hModule: LibraryW,
                                                                     lpProcName: "MessageBoxW");
    if ( MessageBoxW == nullptr )
      return 0;
    pfnMessageBox = EncodePointer(Ptr: MessageBoxW);
    GetActiveWindow = (HWND (__stdcall *)())GetProcAddress(hModule: v4, lpProcName: "GetActiveWindow");
    pfnGetActiveWindow = EncodePointer(Ptr: GetActiveWindow);
    GetLastActivePopup = (HWND (__stdcall *)(HWND))GetProcAddress(hModule: v4, lpProcName: "GetLastActivePopup");
    pfnGetLastActivePopup = EncodePointer(Ptr: GetLastActivePopup);
    GetUserObjectInformationW = (BOOL (__stdcall *)(HANDLE, int, PVOID, DWORD, LPDWORD))GetProcAddress(
                                                                                          hModule: v4,
                                                                                          lpProcName: "GetUserObjectInformationW");
    pfnGetUserObjectInformation = EncodePointer(Ptr: GetUserObjectInformationW);
    if ( pfnGetUserObjectInformation != nullptr )
    {
      GetProcessWindowStation = (HWINSTA (__stdcall *)())GetProcAddress(
                                                           hModule: v4,
                                                           lpProcName: "GetProcessWindowStation");
      pfnGetProcessWindowStation = EncodePointer(Ptr: GetProcessWindowStation);
    }
  }
  if ( pfnGetProcessWindowStation == enull
    || pfnGetUserObjectInformation == enull
    || (v10 = (int (*)(void))DecodePointer(Ptr: pfnGetProcessWindowStation),
        v11 = (int (__stdcall *)(int, int, tagUSEROBJECTFLAGS *, int, unsigned int *))DecodePointer(Ptr: pfnGetUserObjectInformation),
        v12 = v11,
        v10 == nullptr)
    || v11 == nullptr
    || (v13 = v10()) != 0 && v12(a1: v13, a2: 1, a3: &uof, a4: 12, a5: &nDummy) != 0 && (uof.dwFlags & 1) != 0 )
  {
    if ( pfnGetActiveWindow != enull )
    {
      v14 = (int (*)(void))DecodePointer(Ptr: pfnGetActiveWindow);
      if ( v14 != nullptr )
      {
        hWndParent = (HWND__ *)v14();
        if ( hWndParent != nullptr && pfnGetLastActivePopup != enull )
        {
          v15 = (int (__stdcall *)(HWND__ *))DecodePointer(Ptr: pfnGetLastActivePopup);
          if ( v15 != nullptr )
            hWndParent = (HWND__ *)v15(a1: hWndParent);
        }
      }
    }
  }
  else
  {
    uType |= 0x200000u;
  }
  v16 = (int (__stdcall *)(HWND__ *, const wchar_t *, const wchar_t *, unsigned int))DecodePointer(Ptr: pfnMessageBox);
  if ( v16 != nullptr )
    return v16(a1: hWndParent, a2: v19, a3: v20, a4: uType);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x0040B505
// Name: _wcscat_s
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl wcscat_s(unsigned __int16 *_Dst, unsigned int _SizeInWords, const wchar_t *_Src)
{
  unsigned int v3; // edi
  int v4; // esi
  int result; // eax
  const wchar_t *v6; // ecx
  unsigned __int16 *v7; // edx
  int v8; // edx
  wchar_t v9; // ax

  if ( _Dst == nullptr )
    goto LABEL_3;
  v3 = _SizeInWords;
  if ( _SizeInWords == 0 )
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
      v8 = (char *)v7 - (char *)_Src;
      do
      {
        v9 = *v6;
        *(const wchar_t *)((char *)v6 + v8) = *v6;
        ++v6;
        if ( v9 == 0 )
          break;
        --v3;
      }
      while ( v3 != 0 );
      result = 0;
      if ( v3 == 0 )
      {
        *_Dst = 0;
        *_errno() = 34;
        v4 = 34;
        goto LABEL_4;
      }
      return result;
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
// Address: 0x0040B57A
// Name: _wcsncpy_s
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl wcsncpy_s(unsigned __int16 *_Dst, unsigned int _SizeInWords, const wchar_t *_Src, unsigned int _Count)
{
  unsigned int v4; // ebx
  unsigned int v6; // edi
  int v7; // esi
  const wchar_t *v8; // ecx
  unsigned __int16 *v9; // eax
  wchar_t v10; // ax
  unsigned __int16 v11; // cx

  v4 = _Count;
  if ( _Count != 0 )
  {
    if ( _Dst == nullptr )
    {
LABEL_7:
      v7 = 22;
      *_errno() = 22;
LABEL_8:
      _invalid_parameter_noinfo();
      return v7;
    }
  }
  else if ( _Dst == nullptr )
  {
    if ( _SizeInWords == 0 )
      return 0;
    goto LABEL_7;
  }
  v6 = _SizeInWords;
  if ( _SizeInWords == 0 )
    goto LABEL_7;
  if ( _Count == 0 )
  {
    *_Dst = 0;
    return 0;
  }
  v8 = _Src;
  if ( _Src == nullptr )
  {
    *_Dst = 0;
    goto LABEL_7;
  }
  v9 = _Dst;
  if ( _Count == -1 )
  {
    do
    {
      v10 = *v8;
      *(const wchar_t *)((char *)v8 + (char *)_Dst - (char *)_Src) = *v8;
      ++v8;
      if ( v10 == 0 )
        break;
      --v6;
    }
    while ( v6 != 0 );
  }
  else
  {
    do
    {
      v11 = *(unsigned __int16 *)((char *)v9 + (char *)_Src - (char *)_Dst);
      *v9++ = v11;
      if ( v11 == 0 )
        break;
      if ( --v6 == 0 )
        break;
      --v4;
    }
    while ( v4 != 0 );
    if ( v4 == 0 )
      *v9 = 0;
  }
  if ( v6 != 0 )
    return 0;
  if ( v4 != -1 )
  {
    *_Dst = 0;
    *_errno() = 34;
    v7 = 34;
    goto LABEL_8;
  }
  _Dst[_SizeInWords - 1] = 0;
  return 80;
}

//------------------------------------------------------------------------------
// Address: 0x0040B647
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
// Address: 0x0040B662
// Name: _wcscpy_s
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl wcscpy_s(unsigned __int16 *_Dst, unsigned int _SizeInWords, const wchar_t *_Src)
{
  unsigned int v3; // edi
  int v4; // esi
  int result; // eax
  const wchar_t *v6; // eax
  wchar_t v7; // cx

  if ( _Dst == nullptr )
    goto LABEL_3;
  v3 = _SizeInWords;
  if ( _SizeInWords == 0 )
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
    *(const wchar_t *)((char *)v6 + (char *)_Dst - (char *)_Src) = *v6;
    ++v6;
    if ( v7 == 0 )
      break;
    --v3;
  }
  while ( v3 != 0 );
  result = 0;
  if ( v3 == 0 )
  {
    *_Dst = 0;
    *_errno() = 34;
    v4 = 34;
    goto LABEL_4;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0040B6C5
// Name: __set_error_mode
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _set_error_mode(int em)
{
  int result; // eax

  if ( em >= 0 )
  {
    if ( em <= 2 )
    {
      result = __error_mode;
      __error_mode = em;
      return result;
    }
    if ( em == 3 )
      return __error_mode;
  }
  *_errno() = 22;
  _invalid_parameter_noinfo();
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0040B704
// Name: x_ismbbtype_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl x_ismbbtype_l(localeinfo_struct *plocinfo, unsigned __int8 tst, int cmask, unsigned __int8 kmask)
{
  int result; // eax
  _LocaleUpdate _loc_update; // [esp+0h] [ebp-10h] BYREF

  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  if ( (kmask & _loc_update.localeinfo.mbcinfo->mbctype[tst + 1]) != 0
    || (cmask == 0 ? (result = 0) : (result = (unsigned __int16)(cmask & _loc_update.localeinfo.locinfo->pctype[tst])),
        result != 0) )
  {
    result = 1;
  }
  if ( _loc_update.updated )
    _loc_update.ptd->_ownlocale &= ~2u;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0040B757
// Name: __ismbblead
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _ismbblead(unsigned __int8 tst)
{
  return x_ismbbtype_l(plocinfo: nullptr, tst, cmask: 0, kmask: 4u);
}

//------------------------------------------------------------------------------
// Address: 0x0040B76F
// Name: ___report_gsfailure
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl __noreturn __report_gsfailure()
{
  unsigned int v0; // eax
  unsigned int v1; // edx
  unsigned int v2; // ecx
  unsigned int v3; // ebx
  unsigned int v4; // edi
  unsigned int v5; // esi
  unsigned int v6; // kr00_4
  HANDLE CurrentProcess; // eax
  unsigned int vars0; // [esp+328h] [ebp+0h]
  void *retaddr; // [esp+32Ch] [ebp+4h]
  char v10; // [esp+330h] [ebp+8h] BYREF

  GS_ContextRecord.Eax = v0;
  GS_ContextRecord.Ecx = v2;
  GS_ContextRecord.Edx = v1;
  GS_ContextRecord.Ebx = v3;
  GS_ContextRecord.Esi = v5;
  GS_ContextRecord.Edi = v4;
  LOWORD(GS_ContextRecord.SegSs) = __SS__;
  LOWORD(GS_ContextRecord.SegCs) = __CS__;
  LOWORD(GS_ContextRecord.SegDs) = __DS__;
  LOWORD(GS_ContextRecord.SegEs) = __ES__;
  LOWORD(GS_ContextRecord.SegFs) = __FS__;
  LOWORD(GS_ContextRecord.SegGs) = __GS__;
  v6 = __readeflags();
  GS_ContextRecord.EFlags = v6;
  GS_ContextRecord.Ebp = vars0;
  GS_ContextRecord.Eip = (unsigned int)retaddr;
  GS_ContextRecord.Esp = (unsigned int)&v10;
  GS_ContextRecord.ContextFlags = 65537;
  GS_ExceptionRecord.ExceptionAddress = retaddr;
  GS_ExceptionRecord.ExceptionCode = -1073740791;
  GS_ExceptionRecord.ExceptionFlags = 1;
  DebuggerWasPresent = IsDebuggerPresent();
  _crt_debugger_hook();
  SetUnhandledExceptionFilter(lpTopLevelExceptionFilter: nullptr);
  UnhandledExceptionFilter(ExceptionInfo: &GS_ExceptionPointers);
  if ( DebuggerWasPresent == 0 )
    _crt_debugger_hook();
  CurrentProcess = GetCurrentProcess();
  TerminateProcess(hProcess: CurrentProcess, uExitCode: 0xC0000409);
}

//------------------------------------------------------------------------------
// Address: 0x0040B875
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
// Address: 0x0040B953
// Name: __mbsnbicoll
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _mbsnbicoll(const unsigned __int8 *s1, const unsigned __int8 *s2, unsigned int n)
{
  return _mbsnbicoll_l(s1, s2, n, plocinfo: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x0040B96D
// Name: ___wtomb_environ
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl __wtomb_environ()
{
  LPCWCH *v0; // edi
  const WCHAR *v1; // eax
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
    v3 = (char *)_calloc_crt(count: v2, size: 1u);
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
      free(pBlock: envp);
      return -1;
    }
    if ( __crtsetenv(poption: &envp, primary: 0) < 0 && envp != nullptr )
    {
      free(pBlock: envp);
      envp = nullptr;
    }
    v1 = *++v0;
    if ( *v0 == nullptr )
      return 0;
  }
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0040BA04
// Name: __freea
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _freea(_DWORD *_Memory)
{
  if ( _Memory != nullptr && *(_Memory - 2) == 56797 )
    free(pBlock: _Memory - 2);
}

//------------------------------------------------------------------------------
// Address: 0x0040BA24
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
  WCHAR *v20; // edi
  WCHAR *v21; // eax
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
      v17 = (wchar_t *)malloc(size: 2 * v13 + 8);
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
        v21 = (WCHAR *)malloc(size: 2 * retval + 8);
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
        v20 = (WCHAR *)&v24;
        goto LABEL_39;
      }
    }
  }
LABEL_46:
  _freea(_Memory: inwbuffer);
  return retval;
}

//------------------------------------------------------------------------------
// Address: 0x0040BC0B
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
// Address: 0x0040BC51
// Name: __crtGetStringTypeA_stat
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _crtGetStringTypeA_stat(
        localeinfo_struct *plocinfo,
        DWORD dwInfoType,
        const char *lpSrcStr,
        int cchSrc,
        unsigned __int16 *lpCharType,
        UINT code_page,
        int bError)
{
  wchar_t *v7; // ebx
  int v8; // eax
  int v9; // edi
  unsigned int v11; // eax
  void *v12; // esp
  wchar_t *v13; // eax
  int v14; // eax
  _DWORD v15[3]; // [esp+0h] [ebp-14h] BYREF
  int retval2; // [esp+Ch] [ebp-8h]

  v7 = nullptr;
  retval2 = 0;
  if ( code_page == 0 )
    code_page = plocinfo->locinfo->lc_codepage;
  v8 = MultiByteToWideChar(
         CodePage: code_page,
         dwFlags: 8 * (bError != 0) + 1,
         lpMultiByteStr: lpSrcStr,
         cbMultiByte: cchSrc,
         lpWideCharStr: nullptr,
         cchWideChar: 0);
  v9 = v8;
  if ( v8 == 0 )
    return 0;
  if ( v8 > 0 && (unsigned int)v8 <= 0x7FFFFFF0 )
  {
    v11 = 2 * v8 + 8;
    if ( v11 > 0x400 )
    {
      v13 = (wchar_t *)malloc(size: 2 * v9 + 8);
      if ( v13 != nullptr )
      {
        *(_DWORD *)v13 = 56797;
        goto LABEL_12;
      }
    }
    else
    {
      v12 = alloca(v11);
      v13 = (wchar_t *)v15;
      if ( v15 != nullptr )
      {
        v15[0] = 52428;
LABEL_12:
        v13 += 4;
      }
    }
    v7 = v13;
  }
  if ( v7 == nullptr )
    return 0;
  memset(dst: (int)v7, value: nullptr, count: 2 * v9);
  v14 = MultiByteToWideChar(
          CodePage: code_page,
          dwFlags: 1u,
          lpMultiByteStr: lpSrcStr,
          cbMultiByte: cchSrc,
          lpWideCharStr: v7,
          cchWideChar: v9);
  if ( v14 != 0 )
    retval2 = GetStringTypeW(dwInfoType, lpSrcStr: v7, cchSrc: v14, lpCharType);
  _freea(_Memory: v7);
  return retval2;
}

//------------------------------------------------------------------------------
// Address: 0x0040BD38
// Name: ___crtGetStringTypeA
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl __crtGetStringTypeA(
        localeinfo_struct *plocinfo,
        DWORD dwInfoType,
        const char *lpSrcStr,
        int cchSrc,
        unsigned __int16 *lpCharType,
        UINT code_page,
        int lcid,
        int bError)
{
  int result; // eax
  _LocaleUpdate _loc_update; // [esp+0h] [ebp-10h] BYREF

  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  result = _crtGetStringTypeA_stat(
             plocinfo: &_loc_update.localeinfo,
             dwInfoType,
             lpSrcStr,
             cchSrc,
             lpCharType,
             code_page,
             bError);
  if ( _loc_update.updated )
    _loc_update.ptd->_ownlocale &= ~2u;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0040BD78
// Name: ___initconout
// Source: linker_block_proximity
//------------------------------------------------------------------------------
HANDLE __initconout()
{
  HANDLE result; // eax

  result = CreateFileW(
             lpFileName: L"CONOUT$",
             dwDesiredAccess: 0x40000000u,
             dwShareMode: 3u,
             lpSecurityAttributes: nullptr,
             dwCreationDisposition: 3u,
             dwFlagsAndAttributes: 0,
             hTemplateFile: nullptr);
  _confh = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0040BD97
// Name: ___termconout
// Source: linker_block_proximity
//------------------------------------------------------------------------------
HANDLE __termconout()
{
  HANDLE result; // eax

  result = _confh;
  if ( _confh != (HANDLE)-1 && _confh != (HANDLE)-2 )
    return (HANDLE)CloseHandle(hObject: _confh);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0040BDAE
// Name: ___free_lc_time
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl __free_lc_time(__lc_time_data *lc_time)
{
  if ( lc_time != nullptr )
  {
    free(pBlock: lc_time->wday_abbr[1]);
    free(pBlock: lc_time->wday_abbr[2]);
    free(pBlock: lc_time->wday_abbr[3]);
    free(pBlock: lc_time->wday_abbr[4]);
    free(pBlock: lc_time->wday_abbr[5]);
    free(pBlock: lc_time->wday_abbr[6]);
    free(pBlock: lc_time->wday_abbr[0]);
    free(pBlock: lc_time->wday[1]);
    free(pBlock: lc_time->wday[2]);
    free(pBlock: lc_time->wday[3]);
    free(pBlock: lc_time->wday[4]);
    free(pBlock: lc_time->wday[5]);
    free(pBlock: lc_time->wday[6]);
    free(pBlock: lc_time->wday[0]);
    free(pBlock: lc_time->month_abbr[0]);
    free(pBlock: lc_time->month_abbr[1]);
    free(pBlock: lc_time->month_abbr[2]);
    free(pBlock: lc_time->month_abbr[3]);
    free(pBlock: lc_time->month_abbr[4]);
    free(pBlock: lc_time->month_abbr[5]);
    free(pBlock: lc_time->month_abbr[6]);
    free(pBlock: lc_time->month_abbr[7]);
    free(pBlock: lc_time->month_abbr[8]);
    free(pBlock: lc_time->month_abbr[9]);
    free(pBlock: lc_time->month_abbr[10]);
    free(pBlock: lc_time->month_abbr[11]);
    free(pBlock: lc_time->month[0]);
    free(pBlock: lc_time->month[1]);
    free(pBlock: lc_time->month[2]);
    free(pBlock: lc_time->month[3]);
    free(pBlock: lc_time->month[4]);
    free(pBlock: lc_time->month[5]);
    free(pBlock: lc_time->month[6]);
    free(pBlock: lc_time->month[7]);
    free(pBlock: lc_time->month[8]);
    free(pBlock: lc_time->month[9]);
    free(pBlock: lc_time->month[10]);
    free(pBlock: lc_time->month[11]);
    free(pBlock: lc_time->ampm[0]);
    free(pBlock: lc_time->ampm[1]);
    free(pBlock: lc_time->ww_sdatefmt);
    free(pBlock: lc_time->ww_ldatefmt);
    free(pBlock: lc_time->ww_timefmt);
    free(pBlock: lc_time->_W_wday_abbr[1]);
    free(pBlock: lc_time->_W_wday_abbr[2]);
    free(pBlock: lc_time->_W_wday_abbr[3]);
    free(pBlock: lc_time->_W_wday_abbr[4]);
    free(pBlock: lc_time->_W_wday_abbr[5]);
    free(pBlock: lc_time->_W_wday_abbr[6]);
    free(pBlock: lc_time->_W_wday_abbr[0]);
    free(pBlock: lc_time->_W_wday[1]);
    free(pBlock: lc_time->_W_wday[2]);
    free(pBlock: lc_time->_W_wday[3]);
    free(pBlock: lc_time->_W_wday[4]);
    free(pBlock: lc_time->_W_wday[5]);
    free(pBlock: lc_time->_W_wday[6]);
    free(pBlock: lc_time->_W_wday[0]);
    free(pBlock: lc_time->_W_month_abbr[0]);
    free(pBlock: lc_time->_W_month_abbr[1]);
    free(pBlock: lc_time->_W_month_abbr[2]);
    free(pBlock: lc_time->_W_month_abbr[3]);
    free(pBlock: lc_time->_W_month_abbr[4]);
    free(pBlock: lc_time->_W_month_abbr[5]);
    free(pBlock: lc_time->_W_month_abbr[6]);
    free(pBlock: lc_time->_W_month_abbr[7]);
    free(pBlock: lc_time->_W_month_abbr[8]);
    free(pBlock: lc_time->_W_month_abbr[9]);
    free(pBlock: lc_time->_W_month_abbr[10]);
    free(pBlock: lc_time->_W_month_abbr[11]);
    free(pBlock: lc_time->_W_month[0]);
    free(pBlock: lc_time->_W_month[1]);
    free(pBlock: lc_time->_W_month[2]);
    free(pBlock: lc_time->_W_month[3]);
    free(pBlock: lc_time->_W_month[4]);
    free(pBlock: lc_time->_W_month[5]);
    free(pBlock: lc_time->_W_month[6]);
    free(pBlock: lc_time->_W_month[7]);
    free(pBlock: lc_time->_W_month[8]);
    free(pBlock: lc_time->_W_month[9]);
    free(pBlock: lc_time->_W_month[10]);
    free(pBlock: lc_time->_W_month[11]);
    free(pBlock: lc_time->_W_ampm[0]);
    free(pBlock: lc_time->_W_ampm[1]);
    free(pBlock: lc_time->_W_ww_sdatefmt);
    free(pBlock: lc_time->_W_ww_ldatefmt);
    free(pBlock: lc_time->_W_ww_timefmt);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040C125
// Name: ___free_lconv_num
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl __free_lconv_num(lconv *l)
{
  wchar_t *W_thousands_sep; // esi

  if ( l != nullptr )
  {
    if ( l->decimal_point != __lconv_c.decimal_point )
      free(pBlock: l->decimal_point);
    if ( l->thousands_sep != __lconv_c.thousands_sep )
      free(pBlock: l->thousands_sep);
    if ( l->grouping != __lconv_c.grouping )
      free(pBlock: l->grouping);
    if ( l->_W_decimal_point != __lconv_c._W_decimal_point )
      free(pBlock: l->_W_decimal_point);
    W_thousands_sep = l->_W_thousands_sep;
    if ( W_thousands_sep != __lconv_c._W_thousands_sep )
      free(pBlock: W_thousands_sep);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040C18E
// Name: ___free_lconv_mon
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl __free_lconv_mon(lconv *l)
{
  wchar_t *W_negative_sign; // esi

  if ( l != nullptr )
  {
    if ( l->int_curr_symbol != __lconv_c.int_curr_symbol )
      free(pBlock: l->int_curr_symbol);
    if ( l->currency_symbol != __lconv_c.currency_symbol )
      free(pBlock: l->currency_symbol);
    if ( l->mon_decimal_point != __lconv_c.mon_decimal_point )
      free(pBlock: l->mon_decimal_point);
    if ( l->mon_thousands_sep != __lconv_c.mon_thousands_sep )
      free(pBlock: l->mon_thousands_sep);
    if ( l->mon_grouping != __lconv_c.mon_grouping )
      free(pBlock: l->mon_grouping);
    if ( l->positive_sign != __lconv_c.positive_sign )
      free(pBlock: l->positive_sign);
    if ( l->negative_sign != __lconv_c.negative_sign )
      free(pBlock: l->negative_sign);
    if ( l->_W_int_curr_symbol != __lconv_c._W_int_curr_symbol )
      free(pBlock: l->_W_int_curr_symbol);
    if ( l->_W_currency_symbol != __lconv_c._W_currency_symbol )
      free(pBlock: l->_W_currency_symbol);
    if ( l->_W_mon_decimal_point != __lconv_c._W_mon_decimal_point )
      free(pBlock: l->_W_mon_decimal_point);
    if ( l->_W_mon_thousands_sep != __lconv_c._W_mon_thousands_sep )
      free(pBlock: l->_W_mon_thousands_sep);
    if ( l->_W_positive_sign != __lconv_c._W_positive_sign )
      free(pBlock: l->_W_positive_sign);
    W_negative_sign = l->_W_negative_sign;
    if ( W_negative_sign != __lconv_c._W_negative_sign )
      free(pBlock: W_negative_sign);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040C28C
// Name: __getbuf
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _getbuf(_iobuf *str)
{
  char *v1; // eax
  char *base; // eax

  ++_cflush;
  v1 = (char *)_malloc_crt(cb: 0x1000u);
  str->_base = v1;
  if ( v1 != nullptr )
  {
    str->_flag |= 8u;
    str->_bufsiz = 4096;
  }
  else
  {
    str->_flag |= 4u;
    str->_base = (char *)&str->_charbuf;
    str->_bufsiz = 2;
  }
  base = str->_base;
  str->_cnt = 0;
  str->_ptr = base;
}

//------------------------------------------------------------------------------
// Address: 0x0040C2D5
// Name: __fptrap
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __noreturn _fptrap()
{
  _amsg_exit(rterrnum: 2);
}

//------------------------------------------------------------------------------
// Address: 0x0040C2DE
// Name: __chsize_nolock
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _chsize_nolock(int filedes, __int64 size)
{
  doubleint v2; // rax
  int v3; // edi
  unsigned int v4; // esi
  HANDLE ProcessHeap; // eax
  unsigned int v7; // eax
  int v8; // eax
  bool v9; // of
  unsigned int v10; // kr08_4
  int v11; // esi
  HANDLE v12; // eax
  doubleint v13; // rax
  void *osfhandle; // eax
  unsigned int *v15; // esi
  doubleint v16; // rax
  __int64 place; // [esp+Ch] [ebp-18h]
  __int64 retval; // [esp+14h] [ebp-10h]
  int oldmode; // [esp+1Ch] [ebp-8h]
  char *v20; // [esp+20h] [ebp-4h]

  HIDWORD(retval) = 0;
  place = _lseeki64_nolock(fh: filedes, pos: 0, mthd: 1u).bigint;
  if ( (HIDWORD(place) & (unsigned int)place) == 0xFFFFFFFF )
    return *_errno();
  v2.bigint = _lseeki64_nolock(fh: filedes, pos: 0, mthd: 2u).bigint;
  if ( (v2.twoints.upperhalf & v2.twoints.lowerhalf) == -1 )
    return *_errno();
  v3 = (unsigned __int64)(size - v2.bigint) >> 32;
  v4 = size - v2.twoints.lowerhalf;
  if ( v3 >= 0 && (size >= v2.bigint && (unsigned __int64)(size - v2.bigint) >> 32 != 0 || v4 != 0) )
  {
    ProcessHeap = GetProcessHeap();
    v20 = (char *)HeapAlloc(hHeap: ProcessHeap, dwFlags: 8u, dwBytes: 0x1000u);
    if ( v20 == nullptr )
    {
      *_errno() = 12;
      return *_errno();
    }
    oldmode = _setmode_nolock(fh: filedes, mode: 0x8000);
    while ( 1 )
    {
      v7 = v3 < 0 || v3 <= 0 && v4 < 0x1000 ? v4 : 4096;
      v8 = _write_nolock(fh: filedes, buf: v20, cnt: v7);
      if ( v8 == -1 )
        break;
      v9 = __OFSUB__(__PAIR64__(v3, v4), v8);
      v10 = v4 - v8;
      v3 = (__PAIR64__(v3, v4) - v8) >> 32;
      v4 -= v8;
      if ( v3 < 0 || (v3 < 0) ^ v9 | (v3 == 0) && v10 == 0 )
      {
        v11 = 0;
        goto LABEL_20;
      }
    }
    if ( *__doserrno() == 5 )
      *_errno() = 13;
    v11 = -1;
    HIDWORD(retval) = -1;
LABEL_20:
    _setmode_nolock(fh: filedes, mode: oldmode);
    v12 = GetProcessHeap();
    HeapFree(hHeap: v12, dwFlags: 0, lpMem: v20);
    goto LABEL_28;
  }
  if ( v3 < 0 )
  {
    v13.bigint = _lseeki64_nolock(fh: filedes, pos: size, mthd: 0).bigint;
    if ( (v13.twoints.upperhalf & v13.twoints.lowerhalf) == -1 )
      return *_errno();
    osfhandle = (void *)_get_osfhandle(fh: filedes);
    retval = SetEndOfFile(hFile: osfhandle) - 1;
    if ( (HIDWORD(retval) & (unsigned int)retval) == 0xFFFFFFFF )
    {
      *_errno() = 13;
      v15 = __doserrno();
      *v15 = GetLastError();
      v11 = retval;
LABEL_28:
      if ( (HIDWORD(retval) & v11) == 0xFFFFFFFF )
        return *_errno();
    }
  }
  v16.bigint = _lseeki64_nolock(fh: filedes, pos: place, mthd: 0).bigint;
  if ( (v16.twoints.upperhalf & v16.twoints.lowerhalf) == -1 )
    return *_errno();
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x0040C494
// Name: __read_nolock
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _read_nolock(int fh, char *inputbuf, unsigned int cnt)
{
  unsigned int v3; // edx
  int result; // eax
  ioinfo **v5; // edi
  ioinfo *v6; // eax
  int v7; // esi
  char v8; // cl
  char *v9; // ebx
  char *v10; // ecx
  char *v11; // eax
  char v12; // cl
  bool v13; // zf
  ioinfo *v14; // ecx
  char v15; // cl
  ioinfo *v16; // ecx
  char v17; // cl
  ioinfo *v18; // ecx
  ioinfo *v19; // eax
  char *v20; // eax
  char *v21; // ebx
  char v22; // al
  char *v23; // eax
  char *v24; // ebx
  int v25; // ecx
  int v26; // eax
  char v27; // dl
  char *v28; // ebx
  int v29; // ebx
  DWORD LastError; // eax
  ioinfo *v31; // edx
  BOOL v32; // ecx
  char *v33; // ebx
  int v34; // ecx
  char *v35; // esi
  __int16 v36; // [esp-Ch] [ebp-2Ch]
  unsigned int inputsize; // [esp+4h] [ebp-1Ch]
  int os_read; // [esp+8h] [ebp-18h] BYREF
  int retval; // [esp+Ch] [ebp-14h]
  void *buf; // [esp+10h] [ebp-10h]
  int bytes_read; // [esp+14h] [ebp-Ch]
  wchar_t wpeekchr; // [esp+18h] [ebp-8h] BYREF
  char tmode; // [esp+1Eh] [ebp-2h]
  char peekchr; // [esp+1Fh] [ebp-1h] BYREF
  char *p; // [esp+30h] [ebp+10h]
  char *pa; // [esp+30h] [ebp+10h]

  v3 = cnt;
  retval = -2;
  inputsize = cnt;
  if ( fh == -2 )
  {
    *__doserrno() = 0;
    *_errno() = 9;
    return -1;
  }
  if ( fh < 0 || fh >= _nhandle )
  {
    *__doserrno() = 0;
    *_errno() = 9;
    _invalid_parameter_noinfo();
    return -1;
  }
  v5 = &__pioinfo[fh >> 5];
  v6 = *v5;
  v7 = (fh & 0x1F) << 6;
  v8 = *(&(*v5)->osfile + v7);
  if ( (v8 & 1) == 0 )
  {
    *__doserrno() = 0;
    *_errno() = 9;
LABEL_19:
    _invalid_parameter_noinfo();
    return -1;
  }
  if ( cnt > 0x7FFFFFFF )
    goto LABEL_18;
  bytes_read = 0;
  if ( cnt == 0 || (v8 & 2) != 0 )
    return 0;
  if ( inputbuf == nullptr )
    goto LABEL_18;
  tmode = (char)(2 * *((_BYTE *)v6 + v7 + 36)) >> 1;
  if ( tmode != 1 )
  {
    if ( tmode != 2 )
    {
LABEL_16:
      v9 = inputbuf;
      buf = inputbuf;
      goto LABEL_26;
    }
    if ( (cnt & 1) == 0 )
    {
      cnt &= ~1u;
      goto LABEL_16;
    }
LABEL_18:
    *__doserrno() = 0;
    *_errno() = 22;
    goto LABEL_19;
  }
  if ( (cnt & 1) != 0 )
    goto LABEL_18;
  cnt = 4;
  if ( v3 >> 1 >= 4 )
    cnt = v3 >> 1;
  v9 = (char *)_malloc_crt(cb: cnt);
  buf = v9;
  if ( v9 == nullptr )
  {
    *_errno() = 12;
    *__doserrno() = 8;
    return -1;
  }
  *(doubleint *)&(*v5)->pipech2[v7 + 3] = _lseeki64_nolock(fh, pos: 0, mthd: 1u);
LABEL_26:
  v10 = (char *)*v5 + v7;
  v11 = v9;
  if ( (v10[4] & 0x48) != 0 )
  {
    v12 = v10[5];
    if ( v12 != 10 && cnt != 0 )
    {
      --cnt;
      v13 = tmode == 0;
      *v9 = v12;
      v14 = *v5;
      v11 = v9 + 1;
      bytes_read = 1;
      *(&v14->pipech + v7) = 10;
      if ( !v13 )
      {
        v15 = (*v5)->pipech2[v7];
        if ( v15 != 10 && cnt != 0 )
        {
          *v11 = v15;
          v16 = *v5;
          v11 = v9 + 2;
          --cnt;
          v13 = tmode == 1;
          bytes_read = 2;
          v16->pipech2[v7] = 10;
          if ( v13 )
          {
            v17 = (*v5)->pipech2[v7 + 1];
            if ( v17 != 10 && cnt != 0 )
            {
              *v11 = v17;
              v18 = *v5;
              v11 = v9 + 3;
              --cnt;
              bytes_read = 3;
              v18->pipech2[v7 + 1] = 10;
            }
          }
        }
      }
    }
  }
  if ( !ReadFile(
          hFile: *(HANDLE *)((char *)&(*v5)->osfhnd + v7),
          lpBuffer: v11,
          nNumberOfBytesToRead: cnt,
          lpNumberOfBytesRead: (LPDWORD)&os_read,
          lpOverlapped: nullptr)
    || os_read < 0
    || os_read > cnt )
  {
    LastError = GetLastError();
    if ( LastError == 5 )
    {
      *_errno() = 9;
      *__doserrno() = 5;
      goto LABEL_93;
    }
    if ( LastError == 109 )
    {
      retval = 0;
      goto error_return_0;
    }
    goto LABEL_92;
  }
  v19 = *v5;
  bytes_read += os_read;
  v20 = &v19->osfile + v7;
  if ( *v20 < 0 )
  {
    if ( tmode != 2 )
    {
      if ( os_read != 0 && *v9 == 10 )
        *v20 |= 4u;
      else
        *v20 &= ~4u;
      v21 = (char *)buf;
      p = (char *)buf;
      bytes_read += (int)buf;
      if ( (unsigned int)buf < bytes_read )
      {
        do
        {
          v22 = *p;
          if ( *p == 26 )
          {
            v23 = &(*v5)->osfile + v7;
            if ( (*v23 & 0x40) != 0 )
              *v21++ = *p;
            else
              *v23 |= 2u;
            break;
          }
          if ( v22 == 13 )
          {
            if ( (unsigned int)p < bytes_read - 1 )
            {
              if ( p[1] == 10 )
              {
                p += 2;
                goto LABEL_52;
              }
              ++p;
LABEL_63:
              *v21 = 13;
LABEL_64:
              ++v21;
              continue;
            }
            ++p;
            if ( !ReadFile(
                    hFile: *(HANDLE *)((char *)&(*v5)->osfhnd + v7),
                    lpBuffer: &peekchr,
                    nNumberOfBytesToRead: 1u,
                    lpNumberOfBytesRead: (LPDWORD)&os_read,
                    lpOverlapped: nullptr)
              && GetLastError() != 0
              || os_read == 0 )
            {
              goto LABEL_63;
            }
            if ( (*(&(*v5)->osfile + v7) & 0x48) != 0 )
            {
              if ( peekchr != 10 )
              {
                *v21 = 13;
                *(&(*v5)->pipech + v7) = peekchr;
                goto LABEL_64;
              }
LABEL_52:
              *v21 = 10;
              goto LABEL_64;
            }
            if ( v21 == buf && peekchr == 10 )
              goto LABEL_52;
            _lseeki64_nolock(fh, pos: -1, mthd: 1u);
            if ( peekchr != 10 )
              goto LABEL_63;
          }
          else
          {
            *v21++ = v22;
            ++p;
          }
        }
        while ( (unsigned int)p < bytes_read );
      }
      bytes_read = v21 - (_BYTE *)buf;
      if ( tmode != 1 || v21 == buf )
        goto error_return_0;
      v24 = v21 - 1;
      LOBYTE(v25) = *v24;
      if ( *v24 < 0 )
      {
        v26 = 1;
        v25 = (unsigned __int8)v25;
        while ( _lookuptrailbytes[v25] == 0 && v26 <= 4 && v24 >= buf )
        {
          v25 = (unsigned __int8)*--v24;
          ++v26;
        }
        v27 = *v24;
        if ( _lookuptrailbytes[(unsigned __int8)*v24] == 0 )
        {
          *_errno() = 42;
LABEL_93:
          retval = -1;
          goto error_return_0;
        }
        if ( _lookuptrailbytes[(unsigned __int8)*v24] + 1 == v26 )
        {
          v24 += v26;
        }
        else if ( (*(&(*v5)->osfile + v7) & 0x48) != 0 )
        {
          v28 = v24 + 1;
          *(&(*v5)->pipech + v7) = v27;
          if ( v26 >= 2 )
            (*v5)->pipech2[v7] = *v28++;
          if ( v26 == 3 )
            (*v5)->pipech2[v7 + 1] = *v28++;
          v24 = &v28[-v26];
        }
        else
        {
          _lseeki64_nolock(fh, pos: -v26, mthd: 1u);
        }
      }
      else
      {
        ++v24;
      }
      v29 = v24 - (_BYTE *)buf;
      bytes_read = MultiByteToWideChar(
                     CodePage: 0xFDE9u,
                     dwFlags: 0,
                     lpMultiByteStr: (LPCCH)buf,
                     cbMultiByte: v29,
                     lpWideCharStr: (LPWSTR)inputbuf,
                     cchWideChar: inputsize >> 1);
      if ( bytes_read != 0 )
      {
        v31 = *v5;
        v32 = bytes_read != v29;
        bytes_read *= 2;
        *(int *)((char *)&v31->utf8translations + v7) = v32;
        goto error_return_0;
      }
      LastError = GetLastError();
LABEL_92:
      _dosmaperr(oserrno: LastError);
      goto LABEL_93;
    }
    if ( os_read != 0 && *(_WORD *)v9 == 10 )
      *v20 |= 4u;
    else
      *v20 &= ~4u;
    v33 = (char *)buf;
    pa = (char *)buf;
    bytes_read += (int)buf;
    if ( (unsigned int)buf >= bytes_read )
    {
LABEL_129:
      bytes_read = v33 - (_BYTE *)buf;
      goto error_return_0;
    }
    while ( 1 )
    {
      v34 = *(unsigned __int16 *)pa;
      if ( v34 == 26 )
      {
        v35 = &(*v5)->osfile + v7;
        if ( (*v35 & 0x40) != 0 )
        {
          *(_WORD *)v33 = *(_WORD *)pa;
          v33 += 2;
        }
        else
        {
          *v35 |= 2u;
        }
        goto LABEL_129;
      }
      if ( v34 == 13 )
      {
        if ( (unsigned int)pa < bytes_read - 2 )
        {
          if ( *((_WORD *)pa + 1) == 10 )
          {
            pa += 4;
            goto LABEL_110;
          }
          pa += 2;
LABEL_121:
          v36 = 13;
LABEL_122:
          *(_WORD *)v33 = v36;
          goto LABEL_123;
        }
        pa += 2;
        if ( !ReadFile(
                hFile: *(HANDLE *)((char *)&(*v5)->osfhnd + v7),
                lpBuffer: &wpeekchr,
                nNumberOfBytesToRead: 2u,
                lpNumberOfBytesRead: (LPDWORD)&os_read,
                lpOverlapped: nullptr)
          && GetLastError() != 0
          || os_read == 0 )
        {
          goto LABEL_121;
        }
        if ( (*(&(*v5)->osfile + v7) & 0x48) != 0 )
        {
          if ( wpeekchr != 10 )
          {
            *(_WORD *)v33 = 13;
            *(&(*v5)->pipech + v7) = wpeekchr;
            (*v5)->pipech2[v7] = HIBYTE(wpeekchr);
            (*v5)->pipech2[v7 + 1] = 10;
LABEL_123:
            v33 += 2;
            goto LABEL_124;
          }
LABEL_110:
          v36 = 10;
          goto LABEL_122;
        }
        if ( v33 == buf && wpeekchr == 10 )
          goto LABEL_110;
        _lseeki64_nolock(fh, pos: -2, mthd: 1u);
        if ( wpeekchr != 10 )
          goto LABEL_121;
      }
      else
      {
        *(_WORD *)v33 = v34;
        v33 += 2;
        pa += 2;
      }
LABEL_124:
      if ( (unsigned int)pa >= bytes_read )
        goto LABEL_129;
    }
  }
error_return_0:
  if ( buf != inputbuf )
    free(pBlock: buf);
  result = retval;
  if ( retval == -2 )
    return bytes_read;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0040CA4B
// Name: __read
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _read(int fh, char *buf, unsigned int cnt)
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
// Address: 0x0040CB41
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
// Address: 0x0040CBB6
// Name: __setmode_nolock
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _setmode_nolock(int fh, int mode)
{
  ioinfo **v2; // edx
  int v3; // esi
  char *v4; // ecx
  int v5; // edi
  int v6; // eax
  _BYTE *v7; // ecx
  char v8; // dl

  v2 = &__pioinfo[fh >> 5];
  v3 = (fh & 0x1F) << 6;
  v4 = (char *)*v2 + v3;
  v5 = v4[4] & 0x80;
  v6 = (char)(2 * v4[36]) >> 1;
  if ( mode == 0x4000 )
  {
    v4[4] |= 0x80u;
    *((_BYTE *)*v2 + v3 + 36) &= 0x80u;
  }
  else if ( mode == 0x8000 )
  {
    v4[4] &= ~0x80u;
  }
  else
  {
    if ( mode == 0x10000 || mode == 0x20000 )
    {
      v4[4] |= 0x80u;
      v7 = (char *)*v2 + v3 + 36;
      v8 = *v7 & 0x80 | 2;
    }
    else
    {
      if ( mode != 0x40000 )
        goto LABEL_11;
      v4[4] |= 0x80u;
      v7 = (char *)*v2 + v3 + 36;
      v8 = *v7 & 0x80 | 1;
    }
    *v7 = v8;
  }
LABEL_11:
  if ( v5 != 0 )
    return v6 != 0 ? 0x10000 : 0x4000;
  else
    return 0x8000;
}

//------------------------------------------------------------------------------
// Address: 0x0040CC71
// Name: __get_fmode
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _get_fmode(int *pMode)
{
  if ( pMode != nullptr )
  {
    *pMode = _fmode;
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
// Address: 0x0040CC9E
// Name: __strnicmp_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _strnicmp_l(char *dst, char *src, unsigned int count, localeinfo_struct *plocinfo)
{
  char *v4; // esi
  int v5; // edi
  int v6; // eax
  _LocaleUpdate _loc_update; // [esp+Ch] [ebp-10h] BYREF

  if ( count != 0 )
  {
    _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
    if ( dst != nullptr && (v4 = src, src != nullptr) )
    {
      if ( count <= 0x7FFFFFFF )
      {
        if ( _loc_update.localeinfo.locinfo->lc_handle[2] != 0 )
        {
          do
          {
            v5 = _tolower_l(c: (unsigned __int8)v4[dst - src], plocinfo: &_loc_update.localeinfo);
            v6 = _tolower_l(c: (unsigned __int8)*v4++, plocinfo: &_loc_update.localeinfo);
            --count;
          }
          while ( count != 0 && v5 != 0 && v5 == v6 );
        }
        else
        {
          __ascii_strnicmp(first: (unsigned __int8 *)dst, last: (unsigned __int8 *)src, count);
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
}

//------------------------------------------------------------------------------
// Address: 0x0040CD80
// Name: __strnicmp
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _strnicmp(char *dst, char *src, unsigned int count)
{
  if ( __locale_changed != 0 )
  {
    _strnicmp_l(dst, src, count, plocinfo: nullptr);
  }
  else if ( dst != nullptr && src != nullptr && count <= 0x7FFFFFFF )
  {
    __ascii_strnicmp(first: (unsigned __int8 *)dst, last: (unsigned __int8 *)src, count);
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040CDD3
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
// Address: 0x0040CE93
// Name: __msize
// Source: linker_block_proximity
//------------------------------------------------------------------------------
SIZE_T __cdecl _msize(void *pblock)
{
  if ( pblock != nullptr )
    return HeapSize(hHeap: _crtheap, dwFlags: 0, lpMem: pblock);
  *_errno() = 22;
  _invalid_parameter_noinfo();
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0040CED0
// Name: _strcspn
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl strcspn(unsigned __int8 *string, unsigned __int8 *control)
{
  unsigned int v2; // eax
  int v5; // ecx
  signed __int32 v6[9]; // [esp+0h] [ebp-24h] BYREF

  v2 = 0;
  memset(v6, 0, 32);
  while ( 1 )
  {
    LOBYTE(v2) = *control;
    if ( *control == 0 )
      break;
    ++control;
    _bittestandset(v6, v2);
  }
  v5 = -1;
  do
  {
    ++v5;
    LOBYTE(v2) = *string;
    if ( *string == 0 )
      break;
    ++string;
  }
  while ( !_bittest(v6, v2) );
}

//------------------------------------------------------------------------------
// Address: 0x0040CF20
// Name: _strpbrk
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl strpbrk(unsigned __int8 *string, unsigned __int8 *control)
{
  unsigned int v2; // eax
  signed __int32 v5[9]; // [esp+0h] [ebp-24h] BYREF

  v2 = 0;
  memset(v5, 0, 32);
  while ( 1 )
  {
    LOBYTE(v2) = *control;
    if ( *control == 0 )
      break;
    ++control;
    _bittestandset(v5, v2);
  }
  do
  {
    LOBYTE(v2) = *string;
    if ( *string == 0 )
      break;
    ++string;
  }
  while ( !_bittest(v5, v2) );
}

//------------------------------------------------------------------------------
// Address: 0x0040CF60
// Name: __VEC_memcpy
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
int __usercall _VEC_memcpy@<eax>(unsigned int a1@<ecx>, __m128i *a2@<edi>, const __m128i *a3@<esi>)
{
  int v3; // eax
  unsigned int v4; // edx
  unsigned int v5; // ecx
  unsigned int k; // edx
  __m128i si128; // xmm1
  __m128i v8; // xmm2
  __m128i v9; // xmm3
  __m128i v10; // xmm5
  __m128i v11; // xmm6
  __m128i v12; // xmm7
  unsigned int m; // edx
  unsigned int v14; // ecx
  char v15; // al
  unsigned int n; // ecx
  int ii; // ecx
  unsigned int v19; // eax
  int i; // ecx
  unsigned int j; // eax
  unsigned int v22; // [esp-10h] [ebp-14h]
  int v23; // [esp-Ch] [ebp-10h]

  v3 = (unsigned __int8)a3 & 0xF;
  if ( ((unsigned __int8)a3 & 0xF) != 0 )
  {
    v22 = a1 - (16 - v3);
    v19 = 16 - v3;
    for ( i = v19 & 3; i != 0; --i )
    {
      a2->m128i_i8[0] = a3->m128i_i8[0];
      a3 = (const __m128i *)((char *)a3 + 1);
      a2 = (__m128i *)((char *)a2 + 1);
    }
    for ( j = v19 >> 2; j != 0; --j )
    {
      a2->m128i_i32[0] = a3->m128i_i32[0];
      a3 = (const __m128i *)((char *)a3 + 4);
      a2 = (__m128i *)((char *)a2 + 4);
    }
    a1 = v22;
  }
  v4 = a1;
  v5 = a1 & 0x7F;
  for ( k = v4 >> 7; k != 0; --k )
  {
    si128 = _mm_load_si128(a3 + 1);
    v8 = _mm_load_si128(a3 + 2);
    v9 = _mm_load_si128(a3 + 3);
    *a2 = _mm_load_si128(a3);
    a2[1] = si128;
    a2[2] = v8;
    a2[3] = v9;
    v10 = _mm_load_si128(a3 + 5);
    v11 = _mm_load_si128(a3 + 6);
    v12 = _mm_load_si128(a3 + 7);
    a2[4] = _mm_load_si128(a3 + 4);
    a2[5] = v10;
    a2[6] = v11;
    a2[7] = v12;
    a3 += 8;
    a2 += 8;
  }
  if ( v5 != 0 )
  {
    for ( m = v5 >> 4; m != 0; --m )
      *a2++ = _mm_load_si128(a3++);
    v14 = v5 & 0xF;
    if ( v14 != 0 )
    {
      v15 = v14;
      for ( n = v14 >> 2; n != 0; --n )
      {
        a2->m128i_i32[0] = a3->m128i_i32[0];
        a3 = (const __m128i *)((char *)a3 + 4);
        a2 = (__m128i *)((char *)a2 + 4);
      }
      for ( ii = v15 & 3; ii != 0; --ii )
      {
        a2->m128i_i8[0] = a3->m128i_i8[0];
        a3 = (const __m128i *)((char *)a3 + 1);
        a2 = (__m128i *)((char *)a2 + 1);
      }
    }
  }
  return v23;
}

//------------------------------------------------------------------------------
// Address: 0x0040D063
// Name: _abort
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl __noreturn abort()
{
  unsigned int v0; // edi
  unsigned int v1; // esi

  if ( __get_sigabrt() != nullptr )
    raise(signum: 22);
  if ( (__abort_behavior & 2) != 0 )
    _call_reportfault(a1: v0, a2: v1, nDbgHookCode: 3, dwExceptionCode: 0x40000015u, dwExceptionFlags: 1u);
  _exit(code: 3);
}

//------------------------------------------------------------------------------
// Address: 0x0040D096
// Name: __crtCompareStringA_stat
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __fastcall _crtCompareStringA_stat(
        localeinfo_struct *plocinfo,
        const char *lpString2,
        LCID Locale,
        DWORD dwCmpFlags,
        const char *lpString1,
        int cchCount1,
        int cchCount2,
        UINT code_page)
{
  const char *v8; // eax
  int v9; // edi
  int v11; // ecx
  int v12; // esi
  int v13; // ecx
  const char *v14; // eax
  unsigned __int8 *LeadByte; // eax
  unsigned __int8 v17; // dl
  unsigned __int8 *i; // eax
  unsigned __int8 v19; // dl
  int v20; // eax
  int v21; // ebx
  unsigned int v22; // eax
  void *v23; // esp
  wchar_t *v24; // eax
  int v25; // eax
  int v26; // ebx
  unsigned int v27; // eax
  void *v28; // esp
  WCHAR *v29; // eax
  WCHAR *v30; // edi
  _DWORD v32[3]; // [esp+0h] [ebp-38h] BYREF
  int buff_size1; // [esp+Ch] [ebp-2Ch]
  int retcode; // [esp+10h] [ebp-28h]
  LPCCH lpMultiByteStr; // [esp+14h] [ebp-24h]
  LPCCH v36; // [esp+18h] [ebp-20h]
  wchar_t *wbuffer1; // [esp+1Ch] [ebp-1Ch]
  _cpinfo lpCPInfo; // [esp+20h] [ebp-18h] BYREF

  v8 = lpString1;
  v9 = cchCount1;
  lpMultiByteStr = lpString1;
  v36 = lpString2;
  if ( cchCount1 <= 0 )
  {
    if ( cchCount1 < -1 )
      return 0;
  }
  else
  {
    v11 = cchCount1;
    while ( 1 )
    {
      --v11;
      if ( *v8 == 0 )
        break;
      ++v8;
      if ( v11 == 0 )
      {
        v11 = -1;
        break;
      }
    }
    v9 = -1 - v11 + cchCount1;
    cchCount1 = v9;
  }
  v12 = cchCount2;
  if ( cchCount2 <= 0 )
  {
    if ( cchCount2 < -1 )
      return 0;
  }
  else
  {
    v13 = cchCount2;
    v14 = lpString2;
    while ( 1 )
    {
      --v13;
      if ( *v14 == 0 )
        break;
      ++v14;
      if ( v13 == 0 )
      {
        v13 = -1;
        break;
      }
    }
    v12 = -1 - v13 + cchCount2;
    cchCount2 = v12;
  }
  retcode = 0;
  if ( code_page == 0 )
    code_page = plocinfo->locinfo->lc_codepage;
  if ( v9 != 0 && v12 != 0 )
    goto LABEL_44;
  if ( v9 == v12 )
    return 2;
  if ( v12 > 1 )
    return 1;
  if ( v9 > 1 )
    return 3;
  if ( !GetCPInfo(CodePage: code_page, &lpCPInfo) )
    return 0;
  if ( v9 > 0 )
  {
    if ( lpCPInfo.MaxCharSize >= 2 )
    {
      LeadByte = lpCPInfo.LeadByte;
      if ( lpCPInfo.LeadByte[0] != 0 )
      {
        while ( 1 )
        {
          v17 = LeadByte[1];
          if ( v17 == 0 )
            break;
          if ( (unsigned int)*lpMultiByteStr >= *LeadByte && (unsigned int)*lpMultiByteStr <= v17 )
            return 2;
          LeadByte += 2;
          if ( *LeadByte == 0 )
            return 3;
        }
      }
    }
    return 3;
  }
  if ( v12 > 0 )
  {
    if ( lpCPInfo.MaxCharSize >= 2 )
    {
      for ( i = lpCPInfo.LeadByte; *i != 0; i += 2 )
      {
        v19 = i[1];
        if ( v19 == 0 )
          break;
        if ( (unsigned int)*v36 >= *i && (unsigned int)*v36 <= v19 )
          return 2;
      }
    }
    return 1;
  }
LABEL_44:
  v20 = MultiByteToWideChar(
          CodePage: code_page,
          dwFlags: 9u,
          lpMultiByteStr,
          cbMultiByte: v9,
          lpWideCharStr: nullptr,
          cchWideChar: 0);
  v21 = v20;
  buff_size1 = v20;
  if ( v20 == 0 )
    return 0;
  if ( v20 > 0 && 0xFFFFFFE0 / v20 >= 2 )
  {
    v22 = 2 * v20 + 8;
    if ( v22 > 0x400 )
    {
      v24 = (wchar_t *)malloc(size: 2 * v21 + 8);
      if ( v24 != nullptr )
      {
        *(_DWORD *)v24 = 56797;
        goto LABEL_52;
      }
    }
    else
    {
      v23 = alloca(v22);
      v24 = (wchar_t *)v32;
      if ( v32 != nullptr )
      {
        v32[0] = 52428;
LABEL_52:
        v24 += 4;
      }
    }
    wbuffer1 = v24;
    goto LABEL_55;
  }
  wbuffer1 = nullptr;
LABEL_55:
  if ( wbuffer1 == nullptr )
    return 0;
  if ( MultiByteToWideChar(
         CodePage: code_page,
         dwFlags: 1u,
         lpMultiByteStr,
         cbMultiByte: cchCount1,
         lpWideCharStr: wbuffer1,
         cchWideChar: v21) != 0 )
  {
    v25 = MultiByteToWideChar(
            CodePage: code_page,
            dwFlags: 9u,
            lpMultiByteStr: v36,
            cbMultiByte: cchCount2,
            lpWideCharStr: nullptr,
            cchWideChar: 0);
    v26 = v25;
    if ( v25 != 0 )
    {
      if ( v25 <= 0 || 0xFFFFFFE0 / v25 < 2 )
      {
        v30 = nullptr;
LABEL_68:
        if ( v30 != nullptr )
        {
          if ( MultiByteToWideChar(
                 CodePage: code_page,
                 dwFlags: 1u,
                 lpMultiByteStr: v36,
                 cbMultiByte: cchCount2,
                 lpWideCharStr: v30,
                 cchWideChar: v26) != 0 )
            retcode = CompareStringW(
                        Locale,
                        dwCmpFlags,
                        lpString1: wbuffer1,
                        cchCount1: buff_size1,
                        lpString2: v30,
                        cchCount2: v26);
          _freea(_Memory: v30);
        }
        goto error_cleanup_0;
      }
      v27 = 2 * v25 + 8;
      if ( v27 > 0x400 )
      {
        v29 = (WCHAR *)malloc(size: 2 * v26 + 8);
        if ( v29 != nullptr )
        {
          *(_DWORD *)v29 = 56797;
          goto LABEL_65;
        }
      }
      else
      {
        v28 = alloca(v27);
        v29 = (WCHAR *)v32;
        if ( v32 != nullptr )
        {
          v32[0] = 52428;
LABEL_65:
          v29 += 4;
        }
      }
      v30 = v29;
      goto LABEL_68;
    }
  }
error_cleanup_0:
  _freea(_Memory: wbuffer1);
  return retcode;
}

//------------------------------------------------------------------------------
// Address: 0x0040D304
// Name: ___crtCompareStringA
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl __crtCompareStringA(
        localeinfo_struct *plocinfo,
        LCID Locale,
        DWORD dwCmpFlags,
        const char *lpString1,
        int cchCount1,
        const char *lpString2,
        int cchCount2,
        UINT code_page)
{
  int result; // eax
  _LocaleUpdate _loc_update; // [esp+0h] [ebp-10h] BYREF

  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  result = _crtCompareStringA_stat(
             plocinfo: &_loc_update.localeinfo,
             lpString2,
             Locale,
             dwCmpFlags,
             lpString1,
             cchCount1,
             cchCount2,
             code_page);
  if ( _loc_update.updated )
    _loc_update.ptd->_ownlocale &= ~2u;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0040D346
// Name: __strnicoll_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _strnicoll_l(char *_string1, char *_string2, unsigned int count, localeinfo_struct *plocinfo)
{
  LCID v4; // ecx
  _LocaleUpdate _loc_update; // [esp+4h] [ebp-10h] BYREF

  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  if ( count == 0 )
  {
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
    return;
  }
  if ( _string1 != nullptr && _string2 != nullptr )
  {
    if ( count > 0x7FFFFFFF )
    {
      *_errno() = 22;
      _invalid_parameter_noinfo();
      goto LABEL_16;
    }
    v4 = _loc_update.localeinfo.locinfo->lc_handle[1];
    if ( v4 != 0 )
    {
      if ( __crtCompareStringA(
             plocinfo: &_loc_update.localeinfo,
             Locale: v4,
             dwCmpFlags: 0x1001u,
             lpString1: _string1,
             cchCount1: count,
             lpString2: _string2,
             cchCount2: count,
             code_page: _loc_update.localeinfo.locinfo->lc_collate_cp) == 0 )
      {
        *_errno() = 22;
LABEL_16:
        if ( _loc_update.updated )
          _loc_update.ptd->_ownlocale &= ~2u;
        return;
      }
    }
    else
    {
      _strnicmp_l(dst: _string1, src: _string2, count, plocinfo: &_loc_update.localeinfo);
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
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040D430
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
// Address: 0x0040D482
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
    v4 = (char **)_calloc_crt(count: (unsigned int)result + 1, size: 4u);
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
// Address: 0x0040D4E2
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
      v7 = (char **)_malloc_crt(cb: 4u);
      _environ = v7;
      if ( v7 == nullptr )
        return -1;
      *v7 = nullptr;
      if ( _wenviron == nullptr )
      {
        v8 = (unsigned __int16 **)_malloc_crt(cb: 4u);
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
    free(pBlock: option);
    *poption = nullptr;
    return 0;
  }
  v12 = &v9[v10];
  free(pBlock: *v12);
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
    v16 = (char *)_calloc_crt(count: v15 + 2, size: 1u);
    if ( v16 != nullptr )
    {
      strlen(buf: option);
      if ( strcpy_s(_Dst: v16, _SizeInBytes: v17 + 2, _Src: option) != 0 )
        _invoke_watson(a1: (unsigned int)v16);
      v18 = &equal[v16 - option];
      *v18 = 0;
      if ( !SetEnvironmentVariableA(lpName: v16, lpValue: !remove ? v18 + 1 : nullptr) )
      {
        retval = -1;
        *_errno() = 42;
      }
      free(pBlock: v16);
    }
  }
  if ( remove )
  {
    free(pBlock: option);
    *poption = nullptr;
  }
  return retval;
}

//------------------------------------------------------------------------------
// Address: 0x0040D730
// Name: __alloca_probe_16
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void *__usercall _alloca_probe_16@<eax>(int a1@<eax>, int a2@<ecx>)
{
  char v2; // sp
  int v3; // ecx

  v3 = (v2 + 8 - (_BYTE)a1) & 0xF;
  return _chkstk(a1: __CFADD__(v3, a1) ? -1 : v3 + a1, a2);
}

//------------------------------------------------------------------------------
// Address: 0x0040D75C
// Name: __tolower_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __cdecl _tolower_l(unsigned int c, localeinfo_struct *plocinfo)
{
  threadlocaleinfostruct *locinfo; // ecx
  int v4; // eax
  unsigned int result; // eax
  int v6; // ecx
  int v7; // eax
  bool v8; // zf
  _LocaleUpdate _loc_update; // [esp+8h] [ebp-18h] BYREF
  char outbuffer[4]; // [esp+18h] [ebp-8h] BYREF
  char inbuffer[4]; // [esp+1Ch] [ebp-4h] BYREF
  int ca; // [esp+28h] [ebp+8h]

  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  if ( c >= 0x100 )
  {
    if ( _loc_update.localeinfo.locinfo->mb_cur_max > 1
      && (ca = (int)c >> 8, _isleadbyte_l(c: BYTE1(c), plocinfo: &_loc_update.localeinfo) != 0) )
    {
      inbuffer[0] = ca;
      inbuffer[1] = c;
      inbuffer[2] = 0;
      v6 = 2;
    }
    else
    {
      *_errno() = 42;
      inbuffer[0] = c;
      inbuffer[1] = 0;
      v6 = 1;
    }
    v7 = __crtLCMapStringA(
           plocinfo: &_loc_update.localeinfo,
           Locale: _loc_update.localeinfo.locinfo->lc_handle[2],
           dwMapFlags: 0x100u,
           lpSrcStr: inbuffer,
           cchSrc: v6,
           lpDestStr: outbuffer,
           cchDest: 3,
           code_page: _loc_update.localeinfo.locinfo->lc_codepage,
           bError: 1);
    if ( v7 != 0 )
    {
      v8 = v7 == 1;
      result = (unsigned __int8)outbuffer[0];
      if ( !v8 )
        result = (unsigned __int8)outbuffer[1] | ((unsigned __int8)outbuffer[0] << 8);
      goto LABEL_17;
    }
  }
  else
  {
    locinfo = _loc_update.localeinfo.locinfo;
    if ( _loc_update.localeinfo.locinfo->mb_cur_max <= 1 )
    {
      v4 = _loc_update.localeinfo.locinfo->pctype[c] & 1;
    }
    else
    {
      v4 = _isctype_l(c, mask: 1, plocinfo: &_loc_update.localeinfo);
      locinfo = _loc_update.localeinfo.locinfo;
    }
    if ( v4 != 0 )
    {
      result = locinfo->pclmap[c];
LABEL_17:
      if ( _loc_update.updated )
        _loc_update.ptd->_ownlocale &= ~2u;
      return result;
    }
  }
  if ( _loc_update.updated )
    _loc_update.ptd->_ownlocale &= ~2u;
  return c;
}

//------------------------------------------------------------------------------
// Address: 0x0040D880
// Name: ___ascii_strnicmp
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl __ascii_strnicmp(unsigned __int8 *first, unsigned __int8 *last, unsigned int count)
{
  unsigned int i; // ecx
  unsigned __int8 v6; // ah
  unsigned __int8 v7; // al

  for ( i = count; i != 0; --i )
  {
    v6 = *first;
    v7 = *last;
    if ( *first == 0 || v7 == 0 )
      break;
    ++first;
    ++last;
    if ( v6 >= 0x41u && v6 <= 0x5Au )
      v6 += 32;
    if ( v7 >= 0x41u && v7 <= 0x5Au )
      v7 += 32;
    if ( v6 != v7 )
      break;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040D8E1
// Name: __strdup
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char *__cdecl _strdup(char *string)
{
  int v2; // eax
  unsigned int v3; // esi
  char *v4; // eax
  unsigned int v5; // edi

  if ( string == nullptr )
    return nullptr;
  strlen(buf: string);
  v3 = v2 + 1;
  v4 = (char *)malloc(size: v2 + 1);
  v5 = (unsigned int)v4;
  if ( v4 == nullptr )
    return nullptr;
  if ( strcpy_s(_Dst: v4, _SizeInBytes: v3, _Src: string) != 0 )
    _invoke_watson(a1: v5);
  return (char *)v5;
}

//------------------------------------------------------------------------------
// Address: 0x0040D933
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
// Address: 0x0040D9E3
// Name: __mbschr
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _mbschr(char *string, unsigned int c)
{
  _mbschr_l(string, c, plocinfo: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x0040D9FA
// Name: RtlUnwind(x,x,x,x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
void __stdcall RtlUnwind(PVOID TargetFrame, PVOID TargetIp, PEXCEPTION_RECORD ExceptionRecord, PVOID ReturnValue)
{
  __imp__RtlUnwind@16(TargetFrame, TargetIp, ExceptionRecord, ReturnValue);
}

//------------------------------------------------------------------------------
// Address: 0x0040DA00
// Name: __access_s
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _access_s(const char *path, int amode)
{
  DWORD FileAttributesA; // eax
  DWORD LastError; // eax

  if ( path == nullptr || (amode & 0xFFFFFFF9) != 0 )
  {
    *__doserrno() = 0;
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return 22;
  }
  FileAttributesA = GetFileAttributesA(lpFileName: path);
  if ( FileAttributesA == -1 )
  {
    LastError = GetLastError();
    _dosmaperr(oserrno: LastError);
    return *_errno();
  }
  if ( (FileAttributesA & 0x10) == 0 && (FileAttributesA & 1) != 0 && (amode & 2) != 0 )
  {
    *__doserrno() = 5;
    *_errno() = 13;
    return *_errno();
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x0040DA7F
// Name: _access
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl access(const char *path, int amode)
{
  return -(_access_s(path, amode) != 0);
}

//------------------------------------------------------------------------------
// Address: 0x0040DA97
// Name: __getextendedkeycode
// Source: linker_block_proximity
//------------------------------------------------------------------------------
const NormKeyVals *__cdecl _getextendedkeycode(_KEY_EVENT_RECORD *pKE)
{
  unsigned int dwControlKeyState; // ebx
  const NormKeyVals *result; // eax
  int v3; // ecx
  unsigned int v4; // esi
  int v5; // ecx
  int wVirtualScanCode; // eax

  dwControlKeyState = pKE->dwControlKeyState;
  if ( (dwControlKeyState & 0x100) != 0 )
  {
    result = nullptr;
    v3 = 0;
    v4 = 0;
    while ( EnhancedKeys[v4].ScanCode != pKE->wVirtualScanCode )
    {
      ++v4;
      ++v3;
      if ( v4 >= 12 )
        return result;
    }
    v5 = v3;
    if ( (dwControlKeyState & 3) != 0 )
      return (const NormKeyVals *)&EnhancedKeys[v5].AltChars;
    if ( (dwControlKeyState & 0xC) != 0 )
      return (const NormKeyVals *)&EnhancedKeys[v5].CtrlChars;
    if ( (dwControlKeyState & 0x10) != 0 )
      return (const NormKeyVals *)&EnhancedKeys[v5].ShiftChars;
    return (const NormKeyVals *)&EnhancedKeys[v5].RegChars;
  }
  else
  {
    wVirtualScanCode = pKE->wVirtualScanCode;
    if ( (dwControlKeyState & 3) != 0 )
    {
      result = (const NormKeyVals *)&NormalKeys[wVirtualScanCode].AltChars;
    }
    else if ( (dwControlKeyState & 0xC) != 0 )
    {
      result = (const NormKeyVals *)&NormalKeys[wVirtualScanCode].CtrlChars;
    }
    else if ( (dwControlKeyState & 0x10) != 0 )
    {
      result = (const NormKeyVals *)&NormalKeys[wVirtualScanCode].ShiftChars;
    }
    else
    {
      result = &NormalKeys[wVirtualScanCode];
    }
    if ( result->RegChars.LeadChar != 0 && result->RegChars.LeadChar != 0xE0 || result->RegChars.SecondChar == 0 )
      return nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0040DB4A
// Name: __kbhit_nolock
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _kbhit_nolock()
{
  void *v1; // esp
  _INPUT_RECORD *v2; // eax
  _INPUT_RECORD *v3; // ebx
  unsigned int v4; // edi
  _KEY_EVENT_RECORD *p_KeyEvent; // esi
  _DWORD v6[3]; // [esp+0h] [ebp-1Ch] BYREF
  int ret; // [esp+Ch] [ebp-10h]
  unsigned int NumPeeked; // [esp+10h] [ebp-Ch] BYREF
  unsigned int NumPending; // [esp+14h] [ebp-8h] BYREF

  ret = 0;
  if ( chbuf != -1 )
    return 1;
  if ( _coninpfh == (HANDLE)-2 )
    __initconin();
  if ( _coninpfh == (HANDLE)-1
    || !GetNumberOfConsoleInputEvents(hConsoleInput: _coninpfh, lpNumberOfEvents: &NumPending)
    || NumPending == 0 )
  {
    return 0;
  }
  if ( 0xFFFFFFE0 / NumPending >= 0x14 )
  {
    if ( 20 * NumPending + 8 > 0x400 )
    {
      v2 = (_INPUT_RECORD *)malloc(size: 20 * NumPending + 8);
      if ( v2 != nullptr )
      {
        *(_DWORD *)&v2->EventType = 56797;
        goto LABEL_14;
      }
    }
    else
    {
      v1 = alloca(20 * NumPending + 8);
      v2 = (_INPUT_RECORD *)v6;
      if ( v6 != nullptr )
      {
        v6[0] = 52428;
LABEL_14:
        v2 = (_INPUT_RECORD *)((char *)v2 + 8);
      }
    }
    v3 = v2;
    goto LABEL_17;
  }
  v3 = nullptr;
LABEL_17:
  if ( v3 == nullptr )
    return 0;
  if ( PeekConsoleInputA(hConsoleInput: _coninpfh, lpBuffer: v3, nLength: NumPending, lpNumberOfEventsRead: &NumPeeked) )
  {
    v4 = NumPeeked;
    if ( NumPeeked != 0 && NumPeeked <= NumPending )
    {
      p_KeyEvent = &v3->Event.KeyEvent;
      do
      {
        if ( LOWORD(p_KeyEvent[-1].dwControlKeyState) == 1
          && p_KeyEvent->bKeyDown != 0
          && (p_KeyEvent->uChar.AsciiChar != 0 || _getextendedkeycode(pKE: p_KeyEvent) != nullptr) )
        {
          ret = 1;
        }
        --v4;
        p_KeyEvent = (_KEY_EVENT_RECORD *)((char *)p_KeyEvent + 20);
        NumPeeked = v4;
      }
      while ( v4 != 0 );
    }
  }
  _freea(_Memory: v3);
  return ret;
}

//------------------------------------------------------------------------------
// Address: 0x0040DC72
// Name: _kbhit
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl kbhit()
{
  int retval; // [esp+10h] [ebp-1Ch]

  _lock(locknum: 3);
  retval = _kbhit_nolock();
  _unlock(locknum: 3);
  return retval;
}

//------------------------------------------------------------------------------
// Address: 0x0040DCB0
// Name: ___initconin
// Source: linker_block_proximity
//------------------------------------------------------------------------------
HANDLE __initconin()
{
  HANDLE result; // eax

  result = CreateFileW(
             lpFileName: L"CONIN$",
             dwDesiredAccess: 0xC0000000,
             dwShareMode: 3u,
             lpSecurityAttributes: nullptr,
             dwCreationDisposition: 3u,
             dwFlagsAndAttributes: 0,
             hTemplateFile: nullptr);
  _coninpfh = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0040DCCF
// Name: ___termconin
// Source: linker_block_proximity
//------------------------------------------------------------------------------
HANDLE __termconin()
{
  HANDLE result; // eax

  result = _coninpfh;
  if ( _coninpfh != (HANDLE)-1 && _coninpfh != (HANDLE)-2 )
    return (HANDLE)CloseHandle(hObject: _coninpfh);
  return result;
}
