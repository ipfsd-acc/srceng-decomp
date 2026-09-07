// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/vmpi/vmpi_logfile.cpp
// Functions: 2
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x10028580
// Name: bool VMPI_IsLogFileEnabled(void)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl VMPI_IsLogFileEnabled()
{
  if ( bChecked )
    return g_szVMPILogFilename[0] != 0;
  bChecked = true;
  if ( access(path: "c:\\vmpi_log_enable.txt", amode: 0) != 0 )
    return false;
  strncpy(dest: (unsigned __int8 *)g_szVMPILogFilename, source: "c:\\vmpi.log", count: 0x104u);
  byte_1017224B = 0;
  return true;
}

//------------------------------------------------------------------------------
// Address: 0x100285E0
// Name: void VMPI_WriteToLogFile(char const __near *,...)
// Source: json
//------------------------------------------------------------------------------
void VMPI_WriteToLogFile(const char *pMsg, ...)
{
  tm *v1; // eax
  unsigned __int8 *v2; // eax
  _BYTE *v3; // eax
  HMODULE ModuleHandleA; // eax
  _iobuf *v5; // edi
  unsigned int v6; // kr00_4
  unsigned int v7; // kr04_4
  int v8; // esi
  char baseExeFilename[512]; // [esp+0h] [ebp-42Ch] BYREF
  char timeString[512]; // [esp+200h] [ebp-22Ch] BYREF
  __int64 aclock; // [esp+400h] [ebp-2Ch] BYREF
  tm newtime; // [esp+408h] [ebp-24h] BYREF
  va_list ap; // [esp+438h] [ebp+Ch] BYREF

  va_start(ap, pMsg);
  if ( VMPI_IsLogFileEnabled() )
  {
    _time64(timeptr: &aclock);
    v1 = _localtime64(ptime: &aclock);
    if ( v1 != nullptr )
      newtime = *v1;
    else
      memset(&newtime, 0, sizeof(newtime));
    v2 = (unsigned __int8 *)asctime(tb: &newtime);
    strncpy(dest: (unsigned __int8 *)timeString, source: v2, count: 0x200u);
    timeString[511] = 0;
    strstr(str1: (unsigned __int8 *)timeString, str2: "\n");
    if ( v3 != nullptr )
      *v3 = 0;
    ModuleHandleA = GetModuleHandleA(lpModuleName: nullptr);
    if ( GetModuleFileNameA(hModule: ModuleHandleA, lpFilename: baseExeFilename, nSize: 0x200u) == 0 )
    {
      strncpy(dest: (unsigned __int8 *)baseExeFilename, source: "<unknown exe>", count: 0x200u);
      baseExeFilename[511] = 0;
    }
    v5 = fopen(file: (_iobuf *)g_szVMPILogFilename, mode: "at");
    if ( v5 != nullptr )
    {
      fprintf(str: v5, format: "[%s, %s]\n", timeString, baseExeFilename);
      v6 = strlen(timeString);
      v7 = strlen(baseExeFilename);
      v8 = v7 + v6 + 4;
      if ( v7 + v6 != -4 )
      {
        do
        {
          fprintf(str: v5, format: "-");
          --v8;
        }
        while ( v8 != 0 );
      }
      fprintf(str: v5, format: "\n");
      vfprintf(str: v5, format: pMsg, ap);
      fprintf(str: v5, format: "\n");
      fflush(stream: v5);
      fclose(stream: v5);
    }
  }
}

// ============================================================
// Overlay from texturecompile_dll (Missing functions)
// ============================================================
namespace texturecompile_dll {

//------------------------------------------------------------------------------
// Address: 0x1000FBA0
// Name: bool VMPI_IsLogFileEnabled(void)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl VMPI_IsLogFileEnabled()
{
  if ( bChecked )
    return g_szVMPILogFilename[0] != 0;
  bChecked = true;
  if ( access(path: "c:\\vmpi_log_enable.txt", amode: 0) != 0 )
    return false;
  strncpy(dest: (unsigned __int8 *)g_szVMPILogFilename, source: "c:\\vmpi.log", count: 0x104u);
  byte_1004FE73 = 0;
  return true;
}

//------------------------------------------------------------------------------
// Address: 0x1000FC00
// Name: void VMPI_WriteToLogFile(char const __near *,...)
// Source: json
//------------------------------------------------------------------------------
void VMPI_WriteToLogFile(const char *pMsg, ...)
{
  tm *v1; // eax
  unsigned __int8 *v2; // eax
  _BYTE *v3; // eax
  HMODULE ModuleHandleA; // eax
  _iobuf *v5; // edi
  unsigned int v6; // kr00_4
  unsigned int v7; // kr04_4
  int v8; // esi
  char baseExeFilename[512]; // [esp+0h] [ebp-42Ch] BYREF
  char timeString[512]; // [esp+200h] [ebp-22Ch] BYREF
  __int64 aclock; // [esp+400h] [ebp-2Ch] BYREF
  tm newtime; // [esp+408h] [ebp-24h] BYREF
  va_list ap; // [esp+438h] [ebp+Ch] BYREF

  va_start(ap, pMsg);
  if ( VMPI_IsLogFileEnabled() )
  {
    _time64(timeptr: &aclock);
    v1 = _localtime64(ptime: &aclock);
    if ( v1 != nullptr )
      newtime = *v1;
    else
      memset(&newtime, 0, sizeof(newtime));
    v2 = (unsigned __int8 *)asctime(tb: &newtime);
    strncpy(dest: (unsigned __int8 *)timeString, source: v2, count: 0x200u);
    timeString[511] = 0;
    strstr(str1: (unsigned __int8 *)timeString, str2: "\n");
    if ( v3 != nullptr )
      *v3 = 0;
    ModuleHandleA = GetModuleHandleA(lpModuleName: nullptr);
    if ( GetModuleFileNameA(hModule: ModuleHandleA, lpFilename: baseExeFilename, nSize: 0x200u) == 0 )
    {
      strncpy(dest: (unsigned __int8 *)baseExeFilename, source: "<unknown exe>", count: 0x200u);
      baseExeFilename[511] = 0;
    }
    v5 = fopen(file: g_szVMPILogFilename, mode: "at");
    if ( v5 != nullptr )
    {
      fprintf(str: v5, format: "[%s, %s]\n", timeString, baseExeFilename);
      v6 = strlen(timeString);
      v7 = strlen(baseExeFilename);
      v8 = v7 + v6 + 4;
      if ( v7 + v6 != -4 )
      {
        do
        {
          fprintf(str: v5, format: "-");
          --v8;
        }
        while ( v8 != 0 );
      }
      fprintf(str: v5, format: "\n");
      vfprintf(str: v5, format: pMsg, ap);
      fprintf(str: v5, format: "\n");
      fflush(stream: v5);
      fclose(stream: v5);
    }
  }
}

} // namespace texturecompile_dll

// ============================================================
// Overlay from vmpi_service (Missing functions)
// ============================================================
namespace vmpi_service {

//------------------------------------------------------------------------------
// Address: 0x00405B00
// Name: bool VMPI_IsLogFileEnabled(void)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl VMPI_IsLogFileEnabled()
{
  if ( bChecked )
    return g_szVMPILogFilename[0] != 0;
  bChecked = true;
  if ( access(path: "c:\\vmpi_log_enable.txt", amode: 0) != 0 )
    return false;
  strncpy(dest: (unsigned __int8 *)g_szVMPILogFilename, source: "c:\\vmpi.log", count: 0x104u);
  byte_42113B = 0;
  return true;
}

//------------------------------------------------------------------------------
// Address: 0x00405B60
// Name: void VMPI_WriteToLogFile(char const __near *,...)
// Source: json
//------------------------------------------------------------------------------
void VMPI_WriteToLogFile(const char *pMsg, ...)
{
  tm *v1; // eax
  unsigned __int8 *v2; // eax
  _BYTE *v3; // eax
  HMODULE ModuleHandleA; // eax
  _iobuf *v5; // edi
  unsigned int v6; // kr00_4
  unsigned int v7; // kr04_4
  int v8; // esi
  char baseExeFilename[512]; // [esp+0h] [ebp-42Ch] BYREF
  char timeString[512]; // [esp+200h] [ebp-22Ch] BYREF
  __int64 aclock; // [esp+400h] [ebp-2Ch] BYREF
  tm newtime; // [esp+408h] [ebp-24h] BYREF
  va_list ap; // [esp+438h] [ebp+Ch] BYREF

  va_start(ap, pMsg);
  if ( VMPI_IsLogFileEnabled() )
  {
    _time64(timeptr: &aclock);
    v1 = _localtime64(ptime: &aclock);
    if ( v1 != nullptr )
      newtime = *v1;
    else
      memset(&newtime, 0, sizeof(newtime));
    v2 = (unsigned __int8 *)asctime(tb: &newtime);
    strncpy(dest: (unsigned __int8 *)timeString, source: v2, count: 0x200u);
    timeString[511] = 0;
    strstr(str1: (unsigned __int8 *)timeString, str2: "\n");
    if ( v3 != nullptr )
      *v3 = 0;
    ModuleHandleA = GetModuleHandleA(lpModuleName: nullptr);
    if ( GetModuleFileNameA(hModule: ModuleHandleA, lpFilename: baseExeFilename, nSize: 0x200u) == 0 )
    {
      strncpy(dest: (unsigned __int8 *)baseExeFilename, source: "<unknown exe>", count: 0x200u);
      baseExeFilename[511] = 0;
    }
    v5 = fopen(file: g_szVMPILogFilename, mode: "at");
    if ( v5 != nullptr )
    {
      fprintf(str: v5, format: "[%s, %s]\n", timeString, baseExeFilename);
      v6 = strlen(timeString);
      v7 = strlen(baseExeFilename);
      v8 = v7 + v6 + 4;
      if ( v7 + v6 != -4 )
      {
        do
        {
          fprintf(str: v5, format: "-");
          --v8;
        }
        while ( v8 != 0 );
      }
      fprintf(str: v5, format: "\n");
      vfprintf(str: v5, format: pMsg, ap);
      fprintf(str: v5, format: "\n");
      fflush(stream: v5);
      fclose(stream: v5);
    }
  }
}

} // namespace vmpi_service

// ============================================================
// Overlay from vmpi_service_ui (Missing functions)
// ============================================================
namespace vmpi_service_ui {

//------------------------------------------------------------------------------
// Address: 0x004042C0
// Name: bool VMPI_IsLogFileEnabled(void)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl VMPI_IsLogFileEnabled()
{
  if ( bChecked )
    return g_szVMPILogFilename[0] != 0;
  bChecked = true;
  if ( access(path: "c:\\vmpi_log_enable.txt", amode: 0) != 0 )
    return false;
  strncpy(dest: (unsigned __int8 *)g_szVMPILogFilename, source: "c:\\vmpi.log", count: 0x104u);
  byte_41B7AB = 0;
  return true;
}

//------------------------------------------------------------------------------
// Address: 0x00404320
// Name: void VMPI_WriteToLogFile(char const __near *,...)
// Source: json
//------------------------------------------------------------------------------
void VMPI_WriteToLogFile(const char *pMsg, ...)
{
  tm *v1; // eax
  unsigned __int8 *v2; // eax
  _BYTE *v3; // eax
  HMODULE ModuleHandleA; // eax
  _iobuf *v5; // edi
  unsigned int v6; // kr00_4
  unsigned int v7; // kr04_4
  int v8; // esi
  char baseExeFilename[512]; // [esp+0h] [ebp-42Ch] BYREF
  char timeString[512]; // [esp+200h] [ebp-22Ch] BYREF
  __int64 aclock; // [esp+400h] [ebp-2Ch] BYREF
  tm newtime; // [esp+408h] [ebp-24h] BYREF
  va_list ap; // [esp+438h] [ebp+Ch] BYREF

  va_start(ap, pMsg);
  if ( VMPI_IsLogFileEnabled() )
  {
    _time64(timeptr: &aclock);
    v1 = _localtime64(ptime: &aclock);
    if ( v1 != nullptr )
      newtime = *v1;
    else
      memset(&newtime, 0, sizeof(newtime));
    v2 = (unsigned __int8 *)asctime(tb: &newtime);
    strncpy(dest: (unsigned __int8 *)timeString, source: v2, count: 0x200u);
    timeString[511] = 0;
    strstr(str1: (unsigned __int8 *)timeString, str2: "\n");
    if ( v3 != nullptr )
      *v3 = 0;
    ModuleHandleA = GetModuleHandleA(lpModuleName: nullptr);
    if ( GetModuleFileNameA(hModule: ModuleHandleA, lpFilename: baseExeFilename, nSize: 0x200u) == 0 )
    {
      strncpy(dest: (unsigned __int8 *)baseExeFilename, source: "<unknown exe>", count: 0x200u);
      baseExeFilename[511] = 0;
    }
    v5 = fopen(file: g_szVMPILogFilename, mode: "at");
    if ( v5 != nullptr )
    {
      fprintf(str: v5, format: "[%s, %s]\n", timeString, baseExeFilename);
      v6 = strlen(timeString);
      v7 = strlen(baseExeFilename);
      v8 = v7 + v6 + 4;
      if ( v7 + v6 != -4 )
      {
        do
        {
          fprintf(str: v5, format: "-");
          --v8;
        }
        while ( v8 != 0 );
      }
      fprintf(str: v5, format: "\n");
      vfprintf(str: v5, format: pMsg, ap);
      fprintf(str: v5, format: "\n");
      fflush(stream: v5);
      fclose(stream: v5);
    }
  }
}

} // namespace vmpi_service_ui

// ============================================================
// Overlay from vrad_dll (Missing functions)
// ============================================================
namespace vrad_dll {

//------------------------------------------------------------------------------
// Address: 0x1008CEA0
// Name: bool VMPI_IsLogFileEnabled(void)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl VMPI_IsLogFileEnabled()
{
  if ( bChecked )
    return g_szVMPILogFilename[0] != 0;
  bChecked = true;
  if ( access(path: "c:\\vmpi_log_enable.txt", amode: 0) != 0 )
    return false;
  strncpy(dest: (unsigned __int8 *)g_szVMPILogFilename, source: "c:\\vmpi.log", count: 0x104u);
  byte_1527C55B = 0;
  return true;
}

//------------------------------------------------------------------------------
// Address: 0x1008CF00
// Name: void VMPI_WriteToLogFile(char const __near *,...)
// Source: json
//------------------------------------------------------------------------------
void VMPI_WriteToLogFile(const char *pMsg, ...)
{
  tm *v1; // eax
  unsigned __int8 *v2; // eax
  _BYTE *v3; // eax
  HMODULE ModuleHandleA; // eax
  _iobuf *v5; // edi
  unsigned int v6; // kr00_4
  unsigned int v7; // kr04_4
  int v8; // esi
  char baseExeFilename[512]; // [esp+0h] [ebp-42Ch] BYREF
  char timeString[512]; // [esp+200h] [ebp-22Ch] BYREF
  __int64 aclock; // [esp+400h] [ebp-2Ch] BYREF
  tm newtime; // [esp+408h] [ebp-24h] BYREF
  va_list ap; // [esp+438h] [ebp+Ch] BYREF

  va_start(ap, pMsg);
  if ( VMPI_IsLogFileEnabled() )
  {
    _time64(timeptr: &aclock);
    v1 = _localtime64(ptime: &aclock);
    if ( v1 != nullptr )
      newtime = *v1;
    else
      memset(&newtime, 0, sizeof(newtime));
    v2 = (unsigned __int8 *)asctime(tb: &newtime);
    strncpy(dest: (unsigned __int8 *)timeString, source: v2, count: 0x200u);
    timeString[511] = 0;
    strstr(str1: (unsigned __int8 *)timeString, str2: "\n");
    if ( v3 != nullptr )
      *v3 = 0;
    ModuleHandleA = GetModuleHandleA(lpModuleName: nullptr);
    if ( GetModuleFileNameA(hModule: ModuleHandleA, lpFilename: baseExeFilename, nSize: 0x200u) == 0 )
    {
      strncpy(dest: (unsigned __int8 *)baseExeFilename, source: "<unknown exe>", count: 0x200u);
      baseExeFilename[511] = 0;
    }
    v5 = fopen(file: g_szVMPILogFilename, mode: "at");
    if ( v5 != nullptr )
    {
      fprintf(str: v5, format: "[%s, %s]\n", timeString, baseExeFilename);
      v6 = strlen(timeString);
      v7 = strlen(baseExeFilename);
      v8 = v7 + v6 + 4;
      if ( v7 + v6 != -4 )
      {
        do
        {
          fprintf(str: v5, format: "-");
          --v8;
        }
        while ( v8 != 0 );
      }
      fprintf(str: v5, format: "\n");
      vfprintf(str: v5, format: pMsg, ap);
      fprintf(str: v5, format: "\n");
      fflush(stream: v5);
      fclose(stream: v5);
    }
  }
}

} // namespace vrad_dll

// ============================================================
// Overlay from vvis_dll (Missing functions)
// ============================================================
namespace vvis_dll {

//------------------------------------------------------------------------------
// Address: 0x1002C2F0
// Name: bool VMPI_IsLogFileEnabled(void)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl VMPI_IsLogFileEnabled()
{
  if ( bChecked )
    return g_szVMPILogFilename[0] != 0;
  bChecked = true;
  if ( access(path: "c:\\vmpi_log_enable.txt", amode: 0) != 0 )
    return false;
  strncpy(dest: (unsigned __int8 *)g_szVMPILogFilename, source: "c:\\vmpi.log", count: 0x104u);
  byte_14022B7B = 0;
  return true;
}

//------------------------------------------------------------------------------
// Address: 0x1002C350
// Name: void VMPI_WriteToLogFile(char const __near *,...)
// Source: json
//------------------------------------------------------------------------------
void VMPI_WriteToLogFile(const char *pMsg, ...)
{
  tm *v1; // eax
  unsigned __int8 *v2; // eax
  _BYTE *v3; // eax
  HMODULE ModuleHandleA; // eax
  _iobuf *v5; // edi
  unsigned int v6; // kr00_4
  unsigned int v7; // kr04_4
  int v8; // esi
  char baseExeFilename[512]; // [esp+0h] [ebp-42Ch] BYREF
  char timeString[512]; // [esp+200h] [ebp-22Ch] BYREF
  __int64 aclock; // [esp+400h] [ebp-2Ch] BYREF
  tm newtime; // [esp+408h] [ebp-24h] BYREF
  va_list ap; // [esp+438h] [ebp+Ch] BYREF

  va_start(ap, pMsg);
  if ( VMPI_IsLogFileEnabled() )
  {
    _time64(timeptr: &aclock);
    v1 = _localtime64(ptime: &aclock);
    if ( v1 != nullptr )
      newtime = *v1;
    else
      memset(&newtime, 0, sizeof(newtime));
    v2 = (unsigned __int8 *)asctime(tb: &newtime);
    strncpy(dest: (unsigned __int8 *)timeString, source: v2, count: 0x200u);
    timeString[511] = 0;
    strstr(str1: (unsigned __int8 *)timeString, str2: "\n");
    if ( v3 != nullptr )
      *v3 = 0;
    ModuleHandleA = GetModuleHandleA(lpModuleName: nullptr);
    if ( GetModuleFileNameA(hModule: ModuleHandleA, lpFilename: baseExeFilename, nSize: 0x200u) == 0 )
    {
      strncpy(dest: (unsigned __int8 *)baseExeFilename, source: "<unknown exe>", count: 0x200u);
      baseExeFilename[511] = 0;
    }
    v5 = fopen(file: g_szVMPILogFilename, mode: "at");
    if ( v5 != nullptr )
    {
      fprintf(str: v5, format: "[%s, %s]\n", timeString, baseExeFilename);
      v6 = strlen(timeString);
      v7 = strlen(baseExeFilename);
      v8 = v7 + v6 + 4;
      if ( v7 + v6 != -4 )
      {
        do
        {
          fprintf(str: v5, format: "-");
          --v8;
        }
        while ( v8 != 0 );
      }
      fprintf(str: v5, format: "\n");
      vfprintf(str: v5, format: pMsg, ap);
      fprintf(str: v5, format: "\n");
      fflush(stream: v5);
      fclose(stream: v5);
    }
  }
}

} // namespace vvis_dll

// ============================================================
// Overlay from WaitAndRestart (Missing functions)
// ============================================================
namespace WaitAndRestart {

//------------------------------------------------------------------------------
// Address: 0x00401000
// Name: bool VMPI_IsLogFileEnabled(void)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl VMPI_IsLogFileEnabled()
{
  if ( bChecked )
    return g_szVMPILogFilename[0] != 0;
  bChecked = true;
  if ( access(path: "c:\\vmpi_log_enable.txt", amode: 0) != 0 )
    return false;
  strncpy(dest: (unsigned __int8 *)g_szVMPILogFilename, source: "c:\\vmpi.log", count: 0x104u);
  byte_412103 = 0;
  return true;
}

//------------------------------------------------------------------------------
// Address: 0x00401060
// Name: void VMPI_WriteToLogFile(char const __near *,...)
// Source: json
//------------------------------------------------------------------------------
void VMPI_WriteToLogFile(const char *pMsg, ...)
{
  tm *v1; // eax
  unsigned __int8 *v2; // eax
  _BYTE *v3; // eax
  HMODULE ModuleHandleA; // eax
  _iobuf *v5; // edi
  unsigned int v6; // kr00_4
  unsigned int v7; // kr04_4
  int v8; // esi
  char baseExeFilename[512]; // [esp+0h] [ebp-42Ch] BYREF
  char timeString[512]; // [esp+200h] [ebp-22Ch] BYREF
  __int64 aclock; // [esp+400h] [ebp-2Ch] BYREF
  tm newtime; // [esp+408h] [ebp-24h] BYREF
  va_list ap; // [esp+438h] [ebp+Ch] BYREF

  va_start(ap, pMsg);
  if ( VMPI_IsLogFileEnabled() )
  {
    _time64(timeptr: &aclock);
    v1 = _localtime64(ptime: &aclock);
    if ( v1 != nullptr )
      newtime = *v1;
    else
      memset(&newtime, 0, sizeof(newtime));
    v2 = (unsigned __int8 *)asctime(tb: &newtime);
    strncpy(dest: (unsigned __int8 *)timeString, source: v2, count: 0x200u);
    timeString[511] = 0;
    strstr(str1: (unsigned __int8 *)timeString, str2: "\n");
    if ( v3 != nullptr )
      *v3 = 0;
    ModuleHandleA = GetModuleHandleA(lpModuleName: nullptr);
    if ( GetModuleFileNameA(hModule: ModuleHandleA, lpFilename: baseExeFilename, nSize: 0x200u) == 0 )
    {
      strncpy(dest: (unsigned __int8 *)baseExeFilename, source: "<unknown exe>", count: 0x200u);
      baseExeFilename[511] = 0;
    }
    v5 = fopen(file: g_szVMPILogFilename, mode: "at");
    if ( v5 != nullptr )
    {
      fprintf(str: v5, format: "[%s, %s]\n", timeString, baseExeFilename);
      v6 = strlen(timeString);
      v7 = strlen(baseExeFilename);
      v8 = v7 + v6 + 4;
      if ( v7 + v6 != -4 )
      {
        do
        {
          fprintf(str: v5, format: "-");
          --v8;
        }
        while ( v8 != 0 );
      }
      fprintf(str: v5, format: "\n");
      vfprintf(str: v5, format: pMsg, ap);
      fprintf(str: v5, format: "\n");
      fflush(stream: v5);
      fclose(stream: v5);
    }
  }
}

} // namespace WaitAndRestart
