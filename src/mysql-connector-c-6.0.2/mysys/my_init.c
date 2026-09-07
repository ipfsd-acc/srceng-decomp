// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: mysql-connector-c-6.0.2/mysys/my_init.c
// Functions: 5
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x00414410
// Name: atoi_octal
// Source: json
//------------------------------------------------------------------------------
_BYTE *__fastcall atoi_octal(_BYTE *a1)
{
  unsigned __int8 i; // al
  _BYTE *v3; // [esp+0h] [ebp-4h]

  v3 = a1;
  for ( i = *a1; i != 0; i = *++a1 )
  {
    if ( (*((_BYTE *)off_4904A8 + i + 1) & 8) == 0 )
      break;
  }
  str2int();
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x00414460
// Name: my_win_init
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
int my_win_init()
{
  int result; // eax
  DWORD v1; // esi
  LSTATUS i; // eax
  char *v3; // eax
  struct _FILETIME type; // [esp+10h] [ebp-A20h] OVERLAPPED BYREF
  unsigned int key_data_len; // [esp+18h] [ebp-A18h] BYREF
  unsigned int key_name_len; // [esp+1Ch] [ebp-A14h] BYREF
  LARGE_INTEGER PerformanceCount; // [esp+20h] [ebp-A10h] BYREF
  int (__stdcall *key_name[64])(_EXCEPTION_POINTERS *); // [esp+28h] [ebp-A08h] BYREF
  unsigned __int8 Data[1024]; // [esp+128h] [ebp-908h] BYREF
  char dst[1284]; // [esp+528h] [ebp-508h] BYREF

  _set_invalid_parameter_handler(pNew: (void (__cdecl *)(const wchar_t *, const wchar_t *, const wchar_t *, unsigned int, unsigned int))vio_ignore_timeout);
  _tzset();
  if ( QueryPerformanceFrequency(lpFrequency: &query_performance_frequency) )
  {
    GetSystemTimeAsFileTime(lpSystemTimeAsFileTime: &type);
    query_performance_offset = *(_QWORD *)&type - 116444736000000000LL;
    QueryPerformanceCounter(lpPerformanceCount: &PerformanceCount);
    type.dwHighDateTime = (unsigned __int64)(PerformanceCount.QuadPart
                                           / (unsigned __int64)query_performance_frequency.QuadPart) >> 32;
    query_performance_offset -= 10000000
                              * (PerformanceCount.QuadPart
                               / (unsigned __int64)query_performance_frequency.QuadPart)
                              + 10000000
                              * (PerformanceCount.QuadPart % (unsigned __int64)query_performance_frequency.QuadPart)
                              / query_performance_frequency.QuadPart;
  }
  else
  {
    query_performance_frequency.QuadPart = 0;
  }
  result = RegOpenKeyExA(
             hKey: HKEY_LOCAL_MACHINE,
             lpSubKey: "SOFTWARE\\MySQL",
             ulOptions: 0,
             samDesired: 0x20019u,
             phkResult: (PHKEY)&PerformanceCount);
  if ( result == 0 )
  {
    v1 = 0;
    key_name_len = 255;
    key_data_len = 1023;
    for ( i = RegEnumValueA(
                hKey: (HKEY)PerformanceCount.LowPart,
                dwIndex: 0,
                lpValueName: (LPSTR)key_name,
                lpcchValueName: &key_name_len,
                lpReserved: nullptr,
                lpType: &type.dwLowDateTime,
                lpData: Data,
                lpcbData: &key_data_len);
          i != 259;
          i = RegEnumValueA(
                hKey: (HKEY)PerformanceCount.LowPart,
                dwIndex: v1,
                lpValueName: (LPSTR)key_name,
                lpcchValueName: &key_name_len,
                lpReserved: nullptr,
                lpType: &type.dwLowDateTime,
                lpData: Data,
                lpcbData: &key_data_len) )
    {
      ++v1;
      if ( i != 234 )
      {
        if ( i != 0 )
          return RegCloseKey(hKey: (HKEY)PerformanceCount.LowPart);
        if ( type.dwLowDateTime == 1 )
        {
          strxmov(dst, src: (int)key_name, a3: (int)"=");
          v3 = _strdup(string: dst);
          _putenv(option: v3);
        }
      }
      key_name_len = 255;
      key_data_len = 1023;
    }
    return RegCloseKey(hKey: (HKEY)PerformanceCount.LowPart);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00414650
// Name: win32_have_tcpip
// Source: json
//------------------------------------------------------------------------------
char win32_have_tcpip()
{
  HKEY phkResult; // [esp+4h] [ebp-4h] BYREF

  if ( RegOpenKeyExA(
         hKey: HKEY_LOCAL_MACHINE,
         lpSubKey: "SYSTEM\\CurrentControlSet\\Services\\Tcpip\\Parameters",
         ulOptions: 0,
         samDesired: 0x20019u,
         &phkResult) != 0
    && RegOpenKeyExA(
         hKey: HKEY_LOCAL_MACHINE,
         lpSubKey: "SYSTEM\\CurrentControlSet\\Services\\Winsock2\\Parameters",
         ulOptions: 0,
         samDesired: 0x20019u,
         &phkResult) != 0
    && RegOpenKeyExA(
         hKey: HKEY_LOCAL_MACHINE,
         lpSubKey: "SYSTEM\\CurrentControlSet\\Services\\Winsock\\Parameters",
         ulOptions: 0,
         samDesired: 0x20019u,
         &phkResult) != 0
    && (getenv(option: "HAVE_TCPIP") == nullptr
     || LOBYTE(`WspiapiFreeAddrInfo'::`2'::pfFreeAddrInfo.InInitializationOrderModuleList.Flink) != 0) )
  {
    return 0;
  }
  RegCloseKey(hKey: phkResult);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x004146E0
// Name: win32_init_tcp_ip
// Source: json
//------------------------------------------------------------------------------
char win32_init_tcp_ip()
{
  WSAData WSAData; // [esp+0h] [ebp-194h] BYREF

  if ( win32_have_tcpip() != 0 )
  {
    if ( WSAStartup(wVersionRequested: 2u, lpWSAData: &WSAData) == 0 && WSAData.wVersion == 2
      || (WSACleanup(), WSAStartup(wVersionRequested: 2u, lpWSAData: &WSAData) == 0) )
    {
      LOBYTE(`WspiapiFreeAddrInfo'::`2'::pfFreeAddrInfo.InInitializationOrderModuleList.Flink) = 1;
    }
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x00414760
// Name: _my_init
// Source: json
//------------------------------------------------------------------------------
char my_init()
{
  int v1; // ecx
  char *v2; // eax
  char *v3; // eax
  char *v4; // eax

  if ( BYTE1(`WspiapiFreeAddrInfo'::`2'::pfFreeAddrInfo.InInitializationOrderModuleList.Flink) == 0 )
  {
    ++`WspiapiFreeAddrInfo'::`2'::pfFreeAddrInfo.InInitializationOrderModuleList.Blink;
    BYTE1(`WspiapiFreeAddrInfo'::`2'::pfFreeAddrInfo.InInitializationOrderModuleList.Flink) = 1;
    my_umask = 432;
    my_umask_dir = 448;
    vio_ignore_timeout();
    my_progname_short = (tagShutdownType)"unknown";
    if ( my_progname != IdleShutdown )
      my_progname_short = my_progname + dirname_length(string: (unsigned __int8 *)my_progname);
    vio_ignore_timeout();
    if ( (unsigned __int8)my_thread_global_init() != 0 )
      return 1;
    if ( home_dir == nullptr )
    {
      my_win_init();
      home_dir = getenv(option: "HOME");
      if ( home_dir != nullptr )
      {
        intern_filename(to: v1);
        home_dir = v2;
      }
      v3 = getenv(option: "UMASK");
      if ( v3 != nullptr )
        my_umask = (unsigned int)atoi_octal(a1: v3) | 0x180;
      v4 = getenv(option: "UMASK_DIR");
      if ( v4 != nullptr )
        my_umask_dir = (unsigned int)atoi_octal(a1: v4) | 0x1C0;
    }
    win32_init_tcp_ip();
  }
  return 0;
}
