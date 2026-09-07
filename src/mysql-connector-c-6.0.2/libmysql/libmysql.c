// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: mysql-connector-c-6.0.2/libmysql/libmysql.c
// Functions: 26
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x004094E0
// Name: _cli_read_change_user_result
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl cli_read_change_user_result(_IMAGE_SECTION_HEADER *buff, unsigned __int8 *to)
{
  int v2; // eax

  v2 = cli_safe_read(net: buff);
  if ( v2 == -1 )
    return true;
  if ( v2 == 1 && *(_BYTE *)buff->SizeOfRawData == 0xFE && (buff[18].SizeOfRawData & 0x8000) != 0 )
  {
    scramble_323(to);
    if ( (unsigned __int8)my_net_write(result: buff) == 0 && (unsigned __int8)net_flush(a1: buff) == 0 )
      return cli_safe_read(net: buff) == -1;
    set_mysql_error(a1: buff, a2: 2013, a3: unknown_sqlstate);
    return true;
  }
  return false;
}

//------------------------------------------------------------------------------
// Address: 0x00409580
// Name: _read_user_name
// Source: json
//------------------------------------------------------------------------------
void __thiscall read_user_name(const char *name, char *namea)
{
  const char *v2; // eax

  v2 = getenv(option: "USER");
  if ( v2 == nullptr )
    v2 = "ODBC";
  strmake(dst: namea, src: (tagShutdownType)v2, length: 0x40u);
}

//------------------------------------------------------------------------------
// Address: 0x004095B0
// Name: default_local_infile_init
// Source: json
//------------------------------------------------------------------------------
int __cdecl default_local_infile_init(int *a1, unsigned __int8 *filename)
{
  int v2; // esi
  int v3; // eax
  IRecordInfo *tmp_name; // [esp+Ch] [ebp-204h] BYREF

  v2 = my_malloc(size: 0x20Cu, my_flags: 0);
  *a1 = v2;
  if ( v2 == 0 )
    return 1;
  *(_BYTE *)(v2 + 12) = 0;
  *(_DWORD *)(v2 + 4) = 0;
  *(_DWORD *)(v2 + 8) = filename;
  fn_format(a1: (int)&tmp_name, string: filename, a3: (unsigned __int8 *)defaultValue, a4: (int)defaultValue, a5: 4);
  v3 = my_open(lpFileName: (LPCSTR)&tmp_name, a2: 0, a3: 0);
  *(_DWORD *)v2 = v3;
  if ( v3 < 0 )
  {
    *(_DWORD *)(v2 + 4) = *(_DWORD *)_my_thread_var();
    my_snprintf(result: (_cpinfo *)(v2 + 12));
    return 1;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x00409690
// Name: default_local_infile_read
// Source: json
//------------------------------------------------------------------------------
int __cdecl default_local_infile_read(int a1, LPVOID lpBuffer, unsigned int NumberOfBytesRead)
{
  int result; // eax
  int v4; // edi

  result = my_read(fd: *(_DWORD *)a1, lpBuffer, NumberOfBytesRead, a4: 0);
  v4 = result;
  if ( result < 0 )
  {
    *(_DWORD *)(a1 + 4) = 2;
    _my_thread_var();
    my_snprintf(result: (_cpinfo *)(a1 + 12));
    return v4;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004096F0
// Name: default_local_infile_end
// Source: json
//------------------------------------------------------------------------------
void __cdecl default_local_infile_end(int *ptr)
{
  if ( ptr != nullptr )
  {
    if ( *ptr >= 0 )
      my_close(fd: *ptr, a2: 16);
    my_no_flags_free();
  }
}

//------------------------------------------------------------------------------
// Address: 0x00409720
// Name: default_local_infile_error
// Source: json
//------------------------------------------------------------------------------
int __cdecl default_local_infile_error(int a1, char *dst, unsigned int length)
{
  if ( a1 != 0 )
  {
    strmake(dst, src: (tagShutdownType)(a1 + 12), length);
    return *(_DWORD *)(a1 + 4);
  }
  else
  {
    strmov((int)dst);
    return 2008;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00409760
// Name: _mysql_set_local_infile_default
// Source: json
//------------------------------------------------------------------------------
int __cdecl mysql_set_local_infile_default(_PEB mysql)
{
  *(_DWORD *)(*(_DWORD *)&mysql.InheritedAddressSpace + 872) = default_local_infile_init;
  *(_DWORD *)(*(_DWORD *)&mysql.InheritedAddressSpace + 876) = default_local_infile_read;
  *(_DWORD *)(*(_DWORD *)&mysql.InheritedAddressSpace + 880) = default_local_infile_end;
  *(_DWORD *)(*(_DWORD *)&mysql.InheritedAddressSpace + 884) = default_local_infile_error;
  return *(_DWORD *)&mysql.InheritedAddressSpace;
}

//------------------------------------------------------------------------------
// Address: 0x00409790
// Name: _cli_list_fields
// Source: json
//------------------------------------------------------------------------------
void (__cdecl *__cdecl cli_list_fields(int a1))(int)
{
  void (__cdecl *result)(int); // eax

  result = (void (__cdecl *)(int))cli_read_rows(a1, a2: 0, a3: (*(_DWORD *)(a1 + 736) & 0x200) != 0 ? 8 : 6);
  if ( result != nullptr )
  {
    *(_DWORD *)(a1 + 744) = *((_DWORD *)result + 10);
    return unpack_fields();
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004097F0
// Name: _cli_read_statistics
// Source: json
//------------------------------------------------------------------------------
int __cdecl cli_read_statistics(_PEB mysql)
{
  *(_BYTE *)(*(_DWORD *)(*(_DWORD *)&mysql.InheritedAddressSpace + 724)
           + *(_DWORD *)(*(_DWORD *)&mysql.InheritedAddressSpace + 16)) = 0;
  if ( **(_BYTE **)(*(_DWORD *)&mysql.InheritedAddressSpace + 16) != 0 )
    return *(_DWORD *)(*(_DWORD *)&mysql.InheritedAddressSpace + 16);
  set_mysql_error(a1: *(_DWORD *)&mysql.InheritedAddressSpace, a2: 2009, a3: unknown_sqlstate);
  return *(_DWORD *)&mysql.InheritedAddressSpace + 95;
}

//------------------------------------------------------------------------------
// Address: 0x00409830
// Name: mysql_get_server_info(x)
// Source: json
//------------------------------------------------------------------------------
int __stdcall mysql_get_server_info(const wchar_t *mysql, const wchar_t *mysql_4)
{
  return *((_DWORD *)mysql + 160);
}

//------------------------------------------------------------------------------
// Address: 0x00409840
// Name: mysql_get_client_info()
// Source: json
//------------------------------------------------------------------------------
const char *__stdcall mysql_get_client_info()
{
  return "6.0.0";
}

//------------------------------------------------------------------------------
// Address: 0x00409850
// Name: _my_net_local_init
// Source: json
//------------------------------------------------------------------------------
unsigned int __stdcall my_net_local_init(char *net)
{
  unsigned int result; // eax

  *((_DWORD *)net + 10) = net_buffer_length;
  my_net_set_read_timeout((void (__cdecl *)())net);
  my_net_set_write_timeout((void (__cdecl *)())net);
  *((_DWORD *)net + 16) = 1;
  result = net_buffer_length;
  if ( net_buffer_length <= max_allowed_packet )
    *((_DWORD *)net + 11) = max_allowed_packet;
  else
    *((_DWORD *)net + 11) = net_buffer_length;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004098A0
// Name: mysql_escape_string(x,x,x)
// Source: json
//------------------------------------------------------------------------------
int __stdcall mysql_escape_string(int a1, int a2, int a3)
{
  return escape_string_for_mysql(a1: default_charset_info, a2: a1, a3: 0, a4: a2, a5: a3);
}

//------------------------------------------------------------------------------
// Address: 0x004098D0
// Name: my_realloc_str
// Source: json
//------------------------------------------------------------------------------
char __usercall my_realloc_str@<al>(int a1@<ecx>, _DWORD *a2@<esi>)
{
  int v2; // edi
  char result; // al
  unsigned int v4; // ecx
  int v5; // ecx
  char v6; // bl

  v2 = a2[3] - a2[1];
  result = 0;
  v4 = v2 + a1;
  if ( v4 > a2[10] )
  {
    v6 = net_realloc(a1: a2, a2: v4);
    if ( v6 != 0 )
    {
      strmov(dst: v5);
      strmov(dst: a2[22]);
    }
    a2[3] = v2 + a2[1];
    return v6;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00409930
// Name: _set_stmt_error
// Source: json
//------------------------------------------------------------------------------
void __cdecl set_stmt_error(int a1, int errcode)
{
  int v2; // ecx

  *(_DWORD *)(a1 + 160) = errcode;
  strmov(dst: a1 + 176);
  strmov(dst: v2);
}

//------------------------------------------------------------------------------
// Address: 0x00409970
// Name: _set_stmt_errmsg
// Source: json
//------------------------------------------------------------------------------
void __cdecl set_stmt_errmsg(int a1, int a2)
{
  int v2; // ecx

  *(_DWORD *)(a1 + 160) = *(_DWORD *)(a2 + 88);
  if ( a2 != -95 && *(_BYTE *)(a2 + 95) != 0 )
    strmov(dst: a1 + 176);
  strmov(dst: v2);
}

//------------------------------------------------------------------------------
// Address: 0x004099C0
// Name: _cli_read_prepare_result
// Source: json
//------------------------------------------------------------------------------
char __cdecl cli_read_prepare_result(void *net, _DWORD *a2)
{
  unsigned int v2; // eax
  unsigned __int16 *v4; // ecx
  int v5; // edx
  int v6; // ebx
  int v7; // ebp
  unsigned __int16 *v8; // ecx
  unsigned int v9; // eax
  int v10; // eax
  void (__cdecl *v11)(int); // eax

  v2 = cli_safe_read(net);
  if ( v2 == -1 )
    return 1;
  v4 = *((unsigned __int16 **)net + 4);
  *((_DWORD *)net + 189) = 0;
  v5 = *(_DWORD *)((char *)v4 + 1);
  v4 = (unsigned __int16 *)((char *)v4 + 5);
  a2[36] = v5;
  v6 = *v4;
  v7 = v4[1];
  v8 = v4 + 1;
  if ( v2 >= 0xC )
    *((_DWORD *)net + 189) = *(unsigned __int16 *)((char *)v8 + 3);
  if ( v7 != 0 )
  {
    v9 = (*(int (__cdecl **)(void *, _DWORD, int))(*((_DWORD *)net + 236) + 8))(a1: net, a2: 0, a3: 7);
    if ( v9 == 0 )
      return 1;
    free_rows(cur: v9);
  }
  if ( v6 != 0 )
  {
    v10 = *((_DWORD *)net + 187);
    if ( (v10 & 2) == 0 )
      *((_DWORD *)net + 187) = v10 | 1;
    if ( (*(int (__cdecl **)(void *, _DWORD, int))(*((_DWORD *)net + 236) + 8))(a1: net, a2: 0, a3: 7) == 0 )
      return 1;
    v11 = unpack_fields();
    a2[14] = v11;
    if ( v11 == nullptr )
      return 1;
  }
  a2[42] = v6;
  a2[41] = v7;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x00409AA0
// Name: store_param_type
// Source: json
//------------------------------------------------------------------------------
_WORD **__usercall store_param_type@<eax>(_WORD **result@<eax>, int a2@<ecx>)
{
  *(*result)++ = *(_WORD *)(a2 + 52) | (*(_BYTE *)(a2 + 57) != 0 ? 0x8000 : 0);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00409AC0
// Name: store_param_null
// Source: json
//------------------------------------------------------------------------------
_BYTE *__usercall store_param_null@<eax>(int a1@<eax>, int net)
{
  unsigned int v2; // ecx
  _BYTE *result; // eax

  v2 = *(_DWORD *)(a1 + 44);
  result = (_BYTE *)((v2 >> 3) + *(_DWORD *)(net + 4));
  *result |= 1 << (v2 & 7);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00409AE0
// Name: store_param
// Source: json
//------------------------------------------------------------------------------
char __usercall store_param@<al>(int a1@<ebx>, int a2@<edi>)
{
  _DWORD *v2; // esi

  v2 = *(_DWORD **)(a1 + 44);
  if ( **(_BYTE **)(a2 + 4) != 0 )
  {
    store_param_null(a1: a2, net: *(_DWORD *)(a1 + 44));
    return 0;
  }
  else if ( my_realloc_str(a1: **(_DWORD **)a2, a2: v2) != 0 )
  {
    set_stmt_errmsg(a1, a2: (int)v2);
    return 1;
  }
  else
  {
    (*(void (__cdecl **)(_DWORD *, int))(a2 + 20))(a1: v2, a2);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00409B30
// Name: execute
// Source: json
//------------------------------------------------------------------------------
char __usercall execute@<al>(int a1@<esi>, int a2, int a3)
{
  char v3; // dl
  int v4; // edi
  char v5; // al
  int v7; // [esp+8h] [ebp-10h] BYREF
  char v8; // [esp+Ch] [ebp-Ch]
  int v9; // [esp+Dh] [ebp-Bh]

  v3 = *(_BYTE *)(a1 + 148);
  v4 = *(_DWORD *)(a1 + 44);
  v7 = *(_DWORD *)(a1 + 144);
  v8 = v3;
  v9 = 1;
  if ( (unsigned __int8)cli_advanced_command(a1: v4, a2: 23, a3: &v7, a4: 9, a5: a2, a6: a3, a7: 1) != 0
    || (v5 = (**(int (__cdecl ***)(int))(v4 + 944))(a1: v4)) != 0 )
  {
    v5 = 1;
  }
  *(_DWORD *)(a1 + 128) = *(_DWORD *)(v4 + 696);
  *(_DWORD *)(a1 + 132) = *(_DWORD *)(v4 + 700);
  *(_DWORD *)(a1 + 156) = *(_DWORD *)(v4 + 748);
  *(_DWORD *)(a1 + 136) = *(_DWORD *)(v4 + 704);
  *(_DWORD *)(a1 + 140) = *(_DWORD *)(v4 + 708);
  if ( v5 == 0 )
    return 0;
  set_stmt_errmsg(a1, a2: v4);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00409C10
// Name: _cli_stmt_execute
// Source: json
//------------------------------------------------------------------------------
int __cdecl cli_stmt_execute(_SECURITY_ATTRIBUTES *result)
{
  bool v2; // zf
  int bInheritHandle; // esi
  unsigned int v5; // edi
  _WORD **v6; // ebp
  unsigned int v7; // edi
  unsigned int i; // esi
  unsigned int j; // esi
  int v10; // ebp
  int v11; // eax
  unsigned int v12; // [esp+8h] [ebp-4h]
  int mysql; // [esp+10h] [ebp+4h]
  char mysqla; // [esp+10h] [ebp+4h]

  if ( result[13].bInheritHandle == 0 )
    return execute(a1: (int)result, a2: 0, a3: 0);
  v2 = HIBYTE(result[57].bInheritHandle) == 0;
  bInheritHandle = result[3].bInheritHandle;
  mysql = bInheritHandle;
  if ( v2 )
  {
    set_stmt_error(a1: (int)result, errcode: 2031);
    return 1;
  }
  if ( *(_DWORD *)(bInheritHandle + 896) != 0 || (*(_BYTE *)(bInheritHandle + 748) & 8) != 0 )
  {
    set_stmt_error(a1: (int)result, errcode: 2014);
    return 1;
  }
  net_clear();
  v5 = (unsigned int)(result[13].bInheritHandle + 7) >> 3;
  if ( my_realloc_str(a1: v5 + 1, a2: (_DWORD *)bInheritHandle) != 0 )
  {
    set_stmt_errmsg(a1: (int)result, a2: bInheritHandle);
    return 1;
  }
  v6 = (_WORD **)(bInheritHandle + 12);
  memset(dst: *(unsigned __int8 **)(bInheritHandle + 12), value: 0, count: v5);
  *(_DWORD *)(bInheritHandle + 12) += v5;
  v7 = result[4].nLength + (result[13].bInheritHandle << 6);
  *(_BYTE *)(*(_DWORD *)(bInheritHandle + 12))++ = BYTE2(result[57].bInheritHandle);
  v12 = v7;
  if ( BYTE2(result[57].bInheritHandle) != 0 )
  {
    if ( my_realloc_str(a1: 2 * result[13].bInheritHandle, a2: (_DWORD *)bInheritHandle) != 0 )
    {
      set_stmt_errmsg(a1: (int)result, a2: bInheritHandle);
      return 1;
    }
    for ( i = result[4].nLength; i < v7; i += 64 )
      store_param_type(result: v6, a2: i);
  }
  for ( j = result[4].nLength; j < v7; j += 64 )
  {
    if ( *(_BYTE *)(j + 58) != 0 )
    {
      *(_BYTE *)(j + 58) = 0;
    }
    else
    {
      if ( store_param(a1: (int)result, a2: j) != 0 )
        return 1;
      v7 = v12;
    }
  }
  v10 = (int)*v6 - *(_DWORD *)(mysql + 4);
  v11 = my_memdup(src: *(unsigned __int8 **)(mysql + 4), count: v10, my_flags: 0);
  if ( v11 != 0 )
  {
    mysqla = execute(a1: (int)result, a2: v11, a3: v10);
    BYTE2(result[57].bInheritHandle) = 0;
    my_no_flags_free();
    return mysqla;
  }
  else
  {
    set_stmt_error(a1: (int)result, errcode: 2008);
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00409DF0
// Name: _cli_unbuffered_fetch
// Source: json
//------------------------------------------------------------------------------
int __cdecl cli_unbuffered_fetch(_PEB mysql)
{
  _BYTE *v2; // eax

  if ( cli_safe_read(net: *(void **)&mysql.InheritedAddressSpace) == -1 )
    return 1;
  v2 = *(_BYTE **)(*(_DWORD *)&mysql.InheritedAddressSpace + 16);
  if ( *v2 == 0xFE )
  {
    *(_DWORD *)mysql.Mutant = 0;
    return 0;
  }
  else
  {
    *(_DWORD *)mysql.Mutant = v2 + 1;
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00409E30
// Name: _cli_read_binary_rows
// Source: json
//------------------------------------------------------------------------------
int __usercall cli_read_binary_rows@<eax>(unsigned int a1@<edi>, _SECURITY_ATTRIBUTES *result)
{
  _SECURITY_ATTRIBUTES *v2; // esi
  _DWORD *bInheritHandle; // ebp
  unsigned int v5; // edi
  int v6; // eax
  int v7; // eax
  int v8; // esi
  bool v9; // cf
  unsigned int v10; // [esp-4h] [ebp-18h]
  unsigned int *v11; // [esp+0h] [ebp-14h]
  _OVERLAPPED *v12; // [esp+4h] [ebp-10h]
  _DWORD *p_lpSecurityDescriptor; // [esp+Ch] [ebp-8h]
  unsigned __int8 *cp; // [esp+10h] [ebp-4h]

  v2 = result;
  bInheritHandle = (_DWORD *)result[3].bInheritHandle;
  p_lpSecurityDescriptor = &result[5].lpSecurityDescriptor;
  if ( bInheritHandle != nullptr )
  {
    v10 = a1;
    v5 = cli_safe_read(net: bInheritHandle);
    if ( v5 == -1 )
    {
LABEL_9:
      set_stmt_errmsg(a1: (int)v2, a2: (int)bInheritHandle);
      return 1;
    }
    else
    {
      while ( 1 )
      {
        v6 = bInheritHandle[4];
        cp = (unsigned __int8 *)v6;
        if ( *(_BYTE *)v6 == 0xFE && v5 < 8 )
        {
          *p_lpSecurityDescriptor = 0;
          bInheritHandle[189] = *(unsigned __int16 *)(v6 + 1);
          bInheritHandle[187] = *(unsigned __int16 *)(v6 + 3);
          return 0;
        }
        v7 = alloc_root(mem_root: &result[6], length: (const void *)(v5 + 11), a3: v10, a4: v11, a5: v12);
        v8 = v7;
        if ( v7 == 0 )
          break;
        *(_DWORD *)(v7 + 4) = v7 + 12;
        *p_lpSecurityDescriptor = v7;
        p_lpSecurityDescriptor = (_DWORD *)v7;
        memcpy(dst: *(unsigned __int8 **)(v7 + 4), src: cp + 1, count: v5 - 1);
        *(_DWORD *)(v8 + 8) = v5;
        v9 = __CFADD__(result[8].bInheritHandle++, 1);
        result[9].nLength += v9;
        v5 = cli_safe_read(net: bInheritHandle);
        if ( v5 == -1 )
        {
          v2 = result;
          goto LABEL_9;
        }
      }
      set_stmt_error(a1: (int)result, errcode: 2008);
      return 1;
    }
  }
  else
  {
    set_stmt_error(a1: (int)result, errcode: 2013);
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00409F70
// Name: mysql_server_init(x,x,x)
// Source: json
//------------------------------------------------------------------------------
unsigned int __stdcall mysql_server_init(unsigned int argc, unsigned int argv, int a3)
{
  int v3; // esi
  struct servent *v5; // eax
  const char *v6; // eax
  char *v7; // eax

  v3 = 0;
  if ( mysql_client_init != 0 )
    return (char)my_thread_init();
  mysql_client_init = 1;
  org_my_init_done = BYTE1(`WspiapiFreeAddrInfo'::`2'::pfFreeAddrInfo.InInitializationOrderModuleList.Flink);
  if ( (unsigned __int8)my_init() != 0 )
    return 1;
  init_client_errs();
  if ( mysql_port == 0 )
  {
    mysql_port = 3306;
    v5 = getservbyname(name: "mysql", proto: "tcp");
    if ( v5 != nullptr )
      mysql_port = ntohs(netshort: v5[1].Length);
    v6 = getenv(option: "MYSQL_TCP_PORT");
    if ( v6 != nullptr )
      mysql_port = atoi(nptr: v6);
  }
  if ( mysql_unix_port == nullptr )
  {
    mysql_unix_port = "MySQL";
    v7 = getenv(option: "MYSQL_UNIX_PORT");
    if ( v7 != nullptr )
    {
      mysql_unix_port = v7;
      return 0;
    }
  }
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x0040A040
// Name: _handle_local_infile
// Source: json
//------------------------------------------------------------------------------
// Decompile returned None
