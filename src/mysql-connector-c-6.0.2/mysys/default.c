// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: mysql-connector-c-6.0.2/mysys/default.c
// Functions: 13
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x00414E10
// Name: handle_default_option
// Source: json
//------------------------------------------------------------------------------
int __cdecl handle_default_option(int a1, char *a2, int element)
{
  char *v3; // edi
  void *v5; // ecx

  v3 = (char *)element;
  if ( element == 0 )
    return 0;
  if ( find_type(x: a2, a2: *(_DWORD *)(a1 + 8), full_name: 3u) != 0 )
  {
    element = (int)alloc_root(mem_root: *(int **)a1, length: (const void *)(strlen(v3) + 1));
    if ( element == 0 || insert_dynamic(array: *(_DWORD **)(a1 + 4), (unsigned __int8 *)&element) != 0 )
      return 1;
    strmov(dst: v5, dsta: (char *)element, src: v3);
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x00414E90
// Name: _get_defaults_options
// Source: json
//------------------------------------------------------------------------------
int __cdecl get_defaults_options(int a1, _LDBL12 **a2, _DWORD *a3, _DWORD *a4, _DWORD *a5)
{
  int v5; // ebp
  int v6; // esi

  v5 = 0;
  v6 = a1;
  *a5 = 0;
  *a4 = 0;
  *a3 = 0;
  while ( v6 >= 2 )
  {
    if ( v6 == v5 )
      return a1 - v6;
    ++a2;
    v5 = v6;
    if ( *a3 != 0 || is_prefix(result: *a2) == nullptr )
    {
      if ( *a4 != 0 || is_prefix(result: *a2) == nullptr )
      {
        if ( *a5 != 0 || is_prefix(result: *a2) == nullptr )
          continue;
        *a5 = *a2 + 2;
      }
      else
      {
        *a4 = (char *)*a2 + 22;
      }
    }
    else
    {
      *a3 = (char *)*a2 + 16;
    }
    --v6;
  }
  return a1 - v6;
}

//------------------------------------------------------------------------------
// Address: 0x00414F60
// Name: _free_defaults
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
_DWORD *__cdecl free_defaults(int a1)
{
  _BYTE ptr[32]; // [esp+8h] [ebp-20h] OVERLAPPED BYREF

  qmemcpy(ptr, (const void *)(a1 - 32), sizeof(ptr));
  return free_root(a1: ptr, MyFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x00414F90
// Name: get_argument
// Source: json
//------------------------------------------------------------------------------
const char *__usercall get_argument@<eax>(int a1@<eax>, int a2@<ecx>, const char *a3, const char *a4, int a5)
{
  int v5; // edx
  const char *result; // eax
  int v7; // ecx
  unsigned int v8; // ecx
  int v9; // edx
  const char *v10; // ecx
  int v11; // edx
  _iobuf *v12; // eax

  v5 = *(unsigned __int8 *)(a1 + a2 - 1);
  result = (const char *)(a1 + a2 - 1);
  if ( (*((_BYTE *)off_4904A8 + v5 + 1) & 8) != 0 )
  {
    do
      v7 = *(unsigned __int8 *)++result;
    while ( (*((_BYTE *)off_4904A8 + v7 + 1) & 8) != 0 );
  }
  v8 = strlen(result);
  v9 = (unsigned __int8)result[v8 - 2];
  v10 = &result[v8 - 1];
  if ( (*((_BYTE *)off_4904A8 + v9 + 1) & 8) != 0 )
  {
    do
      v11 = *((unsigned __int8 *)v10-- - 2);
    while ( (*((_BYTE *)off_4904A8 + v11 + 1) & 8) != 0 );
  }
  *v10 = 0;
  if ( v10 <= result )
  {
    v12 = __iob_func();
    fprintf(str: v12 + 2, format: "error: Wrong '!%s' directive in config file: %s at line %d\n", a3, a4, a5);
    return nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00415020
// Name: remove_end_comment
// Source: json
//------------------------------------------------------------------------------
char *__usercall remove_end_comment@<eax>(char *a1@<eax>)
{
  char v2; // al
  char v3; // dl
  char v4; // cl

  v2 = 0;
  v3 = 0;
  if ( *a1 == 0 )
    return a1;
  while ( 1 )
  {
    v4 = *a1;
    if ( (*a1 == 39 || v4 == 34) && v2 == 0 )
    {
      if ( v3 == 0 )
      {
        v3 = *a1;
        goto LABEL_7;
      }
      if ( v3 == v4 )
        break;
    }
LABEL_7:
    if ( v3 == 0 )
      goto LABEL_8;
    if ( v4 == 92 && v2 == 0 )
    {
      v2 = 1;
      goto LABEL_10;
    }
LABEL_9:
    v2 = 0;
LABEL_10:
    if ( *++a1 == 0 )
      return a1;
  }
  v3 = 0;
LABEL_8:
  if ( v4 != 35 )
    goto LABEL_9;
  *a1 = 0;
  return a1;
}

//------------------------------------------------------------------------------
// Address: 0x00415080
// Name: add_directory
// Source: json
//------------------------------------------------------------------------------
int __usercall add_directory@<eax>(int a1@<edi>, int *a2@<esi>, int a3)
{
  unsigned int v3; // eax
  unsigned __int8 *v4; // eax
  unsigned __int8 v6[512]; // [esp+0h] [ebp-204h] BYREF

  v3 = normalize_dirname(a1: v6, a2: a3);
  v4 = strmake_root(mem_root: a2, str: v6, len: v3);
  if ( v4 == nullptr )
    return 1;
  array_append_string_unique(a1: v4, a2: a1, a3: 7);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x00415100
// Name: my_get_system_windows_directory
// Source: json
//------------------------------------------------------------------------------
UINT __usercall my_get_system_windows_directory@<eax>(UINT a1@<eax>, char *a2@<edi>)
{
  HMODULE ModuleHandleA; // eax
  UINT (__stdcall *GetSystemWindowsDirectoryA)(LPSTR, UINT); // eax
  UINT SystemDirectoryA; // esi

  ModuleHandleA = GetModuleHandleA(lpModuleName: "kernel32.dll");
  GetSystemWindowsDirectoryA = (UINT (__stdcall *)(LPSTR, UINT))GetProcAddress(
                                                                  hModule: ModuleHandleA,
                                                                  lpProcName: "GetSystemWindowsDirectoryA");
  if ( GetSystemWindowsDirectoryA != nullptr )
    return GetSystemWindowsDirectoryA(lpBuffer: a2, uSize: a1);
  SystemDirectoryA = GetSystemDirectoryA(lpBuffer: a2, uSize: a1);
  if ( SystemDirectoryA > 8 && _stricmp(dst: &a2[SystemDirectoryA - 8], src: "\\System32") == 0 )
  {
    SystemDirectoryA -= 8;
    a2[SystemDirectoryA] = 0;
  }
  return SystemDirectoryA;
}

//------------------------------------------------------------------------------
// Address: 0x00415160
// Name: my_get_module_parent
// Source: json
//------------------------------------------------------------------------------
DWORD __usercall my_get_module_parent@<eax>(char *a1@<esi>)
{
  ioinfo *v1; // edi
  DWORD result; // eax
  ioinfo *v3; // eax
  DWORD v4; // [esp+0h] [ebp-8h]

  v1 = nullptr;
  result = GetModuleFileNameA(hModule: nullptr, lpFilename: a1, nSize: v4);
  if ( result == 0 )
    return result;
  v3 = strend(result: (ioinfo *)a1);
  if ( v3 <= (ioinfo *)a1 )
    return (DWORD)a1;
  while ( LOBYTE(v3->osfhnd) != 92 )
  {
LABEL_6:
    v3 = (ioinfo *)((char *)v3 - 1);
    if ( v3 <= (ioinfo *)a1 )
      return (DWORD)a1;
  }
  if ( v1 == nullptr )
  {
    v1 = v3;
    goto LABEL_6;
  }
  BYTE1(v3->osfhnd) = 0;
  return (DWORD)a1;
}

//------------------------------------------------------------------------------
// Address: 0x004151A0
// Name: init_default_directories
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 *__cdecl init_default_directories(int *mem_root)
{
  unsigned __int8 *v1; // ebx
  unsigned __int8 *result; // eax
  char *v3; // eax
  _OVERLAPPED *v4; // [esp+8h] [ebp-208h]
  _OVERLAPPED *v5; // [esp+8h] [ebp-208h]
  char Buffer[512]; // [esp+Ch] [ebp-204h] BYREF

  v4 = nullptr;
  v1 = alloc_root(mem_root, length: (const void *)0x1C);
  result = nullptr;
  if ( v1 != nullptr )
  {
    *(_DWORD *)v1 = 0;
    *((_DWORD *)v1 + 1) = 0;
    *((_DWORD *)v1 + 2) = 0;
    *((_DWORD *)v1 + 3) = 0;
    *((_DWORD *)v1 + 4) = 0;
    *((_DWORD *)v1 + 5) = 0;
    *((_DWORD *)v1 + 6) = 0;
    if ( my_get_system_windows_directory(a1: 0x200u, a2: Buffer) != 0 )
      v4 = (_OVERLAPPED *)add_directory(a1: (int)v1, a2: mem_root, a3: (int)Buffer);
    if ( GetWindowsDirectoryA(lpBuffer: Buffer, uSize: 0x200u) != 0 )
      v4 = (_OVERLAPPED *)((char *)v4 + add_directory(a1: (int)v1, a2: mem_root, a3: (int)Buffer));
    v5 = (_OVERLAPPED *)((char *)v4 + add_directory(a1: (int)v1, a2: mem_root, a3: (int)"C:/"));
    if ( my_get_module_parent(a1: Buffer) != 0 )
      v5 = (_OVERLAPPED *)((char *)v5 + add_directory(a1: (int)v1, a2: mem_root, a3: (int)Buffer));
    v3 = getenv(option: "MYSQL_HOME");
    if ( v3 != nullptr )
      v5 = (_OVERLAPPED *)((char *)v5 + add_directory(a1: (int)v1, a2: mem_root, a3: (int)v3));
    return (int)v5 + add_directory(a1: (int)v1, a2: mem_root, a3: (int)defaultValue) > 0 ? nullptr : v1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004152E0
// Name: search_default_file_with_ext
// Source: json
//------------------------------------------------------------------------------
int __cdecl search_default_file_with_ext(
        int (__cdecl *a1)(void *, char *, char *),
        void *a2,
        unsigned __int8 *a3,
        int a4,
        char *src,
        int a6)
{
  void *v6; // ecx
  unsigned int v7; // edx
  char *v8; // eax
  _iobuf *v9; // eax
  _iobuf *v10; // esi
  char *v12; // esi
  int v13; // eax
  char v14; // al
  unsigned int v15; // eax
  int v16; // edx
  char *v17; // eax
  int v18; // edx
  _iobuf *v19; // eax
  int v20; // edx
  int v21; // esi
  int v22; // eax
  const char *argument; // eax
  int v24; // eax
  _DWORD *v25; // ebx
  ioinfo **v26; // edi
  ioinfo *v27; // eax
  const char *v28; // edx
  const char *v29; // ebp
  int (__stdcall *v30)(unsigned int, unsigned int, const wchar_t *, int, char *, int, const char *, int *); // esi
  const char *v31; // eax
  unsigned __int8 *v32; // esi
  _BYTE *v33; // eax
  int v34; // edx
  unsigned int v35; // eax
  char *v36; // ebp
  int v37; // eax
  void *v38; // ecx
  int v39; // edx
  char *v40; // eax
  int v41; // eax
  ioinfo *v42; // edi
  int v43; // edx
  ioinfo *v44; // ebx
  void *v45; // ecx
  int v46; // edx
  char osfhnd; // al
  char *v48; // eax
  _BYTE *v49; // eax
  _BYTE *i; // eax
  int v51; // ecx
  _iobuf *v52; // eax
  const char *v53; // [esp-Ch] [ebp-3448h]
  int v54; // [esp-4h] [ebp-3440h]
  char v55; // [esp+13h] [ebp-3429h]
  int v56; // [esp+14h] [ebp-3428h]
  _iobuf *str; // [esp+20h] [ebp-341Ch]
  unsigned int v58; // [esp+24h] [ebp-3418h]
  unsigned __int8 *v59; // [esp+28h] [ebp-3414h]
  char filename[524]; // [esp+2Ch] [ebp-3410h] BYREF
  char v61[512]; // [esp+238h] [ebp-3204h] BYREF
  char v62[4096]; // [esp+438h] [ebp-3004h] BYREF
  char dst[4096]; // [esp+1438h] [ebp-2004h] BYREF
  char string[4096]; // [esp+2438h] [ebp-1004h] BYREF

  v6 = a2;
  v7 = 0;
  v56 = 0;
  v55 = 0;
  if ( a3 != nullptr )
    v7 = strlen((const char *)a3);
  if ( v7 + strlen(src) >= 0x1FD )
    return 0;
  if ( a3 != nullptr )
  {
    v8 = (char *)convert_dirname(dst: (unsigned __int8 *)filename, src: a3, a3: 0);
    if ( *a3 == 126 )
      *v8++ = 46;
    strxmov(dst: v8, (tagShutdownType)src);
  }
  else
  {
    strmov(dst: v6, dsta: filename, src);
  }
  fn_format(
    a1: filename,
    string: (unsigned __int8 *)filename,
    a3: (unsigned __int8 *)defaultValue,
    a4: (char *)defaultValue,
    a5: 4);
  v9 = (_iobuf *)my_fopen((tagShutdownType)filename, a2: 0, a3: 0);
  v10 = v9;
  str = v9;
  if ( v9 == nullptr )
    return 1;
  if ( fgets(string, count: 4095, str: v9) == nullptr )
  {
LABEL_85:
    my_fclose(a1: v10, a2: 0);
    return 0;
  }
  while ( 1 )
  {
    ++v56;
    v12 = string;
    if ( (*((_BYTE *)off_4904A8 + (unsigned __int8)string[0] + 1) & 8) != 0 )
    {
      do
        v13 = (unsigned __int8)*++v12;
      while ( (*((_BYTE *)off_4904A8 + v13 + 1) & 8) != 0 );
    }
    v14 = *v12;
    if ( *v12 == 35 || v14 == 59 || v14 == 0 )
      goto LABEL_83;
    if ( v14 == 33 )
    {
      if ( a6 < 10 )
      {
        v20 = (unsigned __int8)v12[1];
        v21 = (int)(v12 + 1);
        if ( (*((_BYTE *)off_4904A8 + v20 + 1) & 8) != 0 )
        {
          do
            v22 = *(unsigned __int8 *)++v21;
          while ( (*((_BYTE *)off_4904A8 + v22 + 1) & 8) != 0 );
        }
        if ( strncmp(first: (const char *)v21, last: "includedir", count: 0xAu) == 0
          && (*((_BYTE *)off_4904A8 + *(unsigned __int8 *)(v21 + 10) + 1) & 8) != 0 )
        {
          argument = get_argument(a1: v21, a2: 11, a3: "includedir", a4: filename, a5: v56);
          v59 = (unsigned __int8 *)argument;
          if ( argument == nullptr )
            goto LABEL_90;
          v24 = my_dir(src: (tagShutdownType)argument, my_flags: 16);
          v25 = (_DWORD *)v24;
          if ( v24 == 0 )
            goto LABEL_90;
          v58 = 0;
          if ( *(_DWORD *)(v24 + 4) != 0 )
          {
            do
            {
              v26 = (ioinfo **)(*v25 + 8 * v58);
              v27 = fn_ext(result: *v26);
              v28 = *(const char **)f_extensions;
              v29 = (const char *)v27;
              v30 = f_extensions;
              if ( *(_DWORD *)f_extensions != 0 )
              {
                while ( strcmp(v29, v28) != 0 )
                {
                  v28 = *((const char **)v30 + 1);
                  v30 = (int (__stdcall *)(unsigned int, unsigned int, const wchar_t *, int, char *, int, const char *, int *))((char *)v30 + 4);
                  if ( v28 == nullptr )
                    goto LABEL_35;
                }
                if ( *(_DWORD *)v30 != 0 )
                {
                  fn_format(a1: v61, string: (unsigned __int8 *)*v26, a3: v59, a4: (char *)defaultValue, a5: 68);
                  search_default_file_with_ext(
                    (int)a1,
                    (int)a2,
                    a3: (unsigned __int8 *)defaultValue,
                    a4: (int)defaultValue,
                    src: (int)v61,
                    a6: a6 + 1);
                }
              }
LABEL_35:
              ++v58;
            }
            while ( v58 < v25[1] );
          }
          my_dirend(a1: v25);
        }
        else if ( strncmp(first: (const char *)v21, last: "include", count: 7u) == 0
               && (*((_BYTE *)off_4904A8 + *(unsigned __int8 *)(v21 + 7) + 1) & 8) != 0 )
        {
          v31 = get_argument(a1: v21, a2: 8, a3: "include", a4: filename, a5: v56);
          if ( v31 == nullptr )
            goto LABEL_90;
          search_default_file_with_ext(
            (int)a1,
            (int)a2,
            a3: (unsigned __int8 *)defaultValue,
            a4: (int)defaultValue,
            src: (int)v31,
            a6: a6 + 1);
        }
      }
      else
      {
        v15 = strlen(v12);
        v16 = (unsigned __int8)v12[v15 - 2];
        v17 = &v12[v15 - 1];
        if ( (*((_BYTE *)off_4904A8 + v16 + 1) & 8) != 0 )
        {
          do
          {
            v18 = (unsigned __int8)*(v17 - 2);
            --v17;
          }
          while ( (*((_BYTE *)off_4904A8 + v18 + 1) & 8) != 0 );
        }
        *v17 = 0;
        v19 = __iob_func();
        fprintf(
          str: v19 + 2,
          format: "Warning: skipping '%s' directive as maximum includerecursion level was reached in file %s at line %d\n",
          v12,
          filename,
          v56);
      }
      goto LABEL_83;
    }
    if ( v14 != 91 )
      break;
    v32 = (unsigned __int8 *)(v12 + 1);
    v55 = 1;
    strchr(string: v32, chr: 0x5Du);
    if ( v33 == nullptr )
    {
      v54 = v56;
      v53 = "error: Wrong group definition in config file: %s at line %d\n";
      goto LABEL_89;
    }
    if ( (*((_BYTE *)off_4904A8 + (unsigned __int8)*(v33 - 1) + 1) & 8) != 0 )
    {
      do
      {
        v34 = (unsigned __int8)*(v33 - 2);
        --v33;
      }
      while ( (*((_BYTE *)off_4904A8 + v34 + 1) & 8) != 0 );
    }
    *v33 = 0;
    v35 = v33 - v32 + 1;
    if ( v35 >= 0xFFF )
      v35 = 4095;
    strmake(dst, src: (char *)v32, length: v35);
    a1(a1: a2, a2: dst, a3: nullptr);
LABEL_83:
    if ( fgets(string, count: 4095, str) == nullptr )
    {
      v10 = str;
      goto LABEL_85;
    }
  }
  if ( v55 != 0 )
  {
    v36 = remove_end_comment(a1: v12);
    strchr(string: (unsigned __int8 *)v12, chr: 0x3Du);
    if ( v37 != 0 )
      v36 = (char *)v37;
    v38 = (void *)(unsigned __int8)*(v36 - 1);
    if ( (*((_BYTE *)off_4904A8 + (_DWORD)v38 + 1) & 8) != 0 )
    {
      do
      {
        v39 = (unsigned __int8)*(v36 - 2);
        --v36;
      }
      while ( (*((_BYTE *)off_4904A8 + v39 + 1) & 8) != 0 );
    }
    if ( v37 != 0 )
    {
      v42 = (ioinfo *)(v37 + 1);
      if ( (*((_BYTE *)off_4904A8 + *(unsigned __int8 *)(v37 + 1) + 1) & 8) != 0 )
      {
        do
        {
          v43 = BYTE1(v42->osfhnd);
          v42 = (ioinfo *)((char *)v42 + 1);
        }
        while ( (*((_BYTE *)off_4904A8 + v43 + 1) & 8) != 0 );
      }
      v44 = strend(result: v42);
      v45 = (void *)*((unsigned __int8 *)&v44[-1].dbcsBufferUsed + 7);
      if ( (*((_BYTE *)off_4904A8 + (_DWORD)v45 + 1) & 8) != 0 )
      {
        do
        {
          v46 = *((unsigned __int8 *)&v44[-1].dbcsBufferUsed + 6);
          v44 = (ioinfo *)((char *)v44 - 1);
        }
        while ( (*((_BYTE *)off_4904A8 + v46 + 1) & 8) != 0 );
      }
      if ( v44 < v42 )
        v44 = v42;
      osfhnd = v42->osfhnd;
      if ( LOBYTE(v42->osfhnd) == 34 || osfhnd == 39 )
      {
        v45 = (char *)&v42->osfhnd + 1;
        if ( (ioinfo *)((char *)&v42->osfhnd + 1) < v44 && osfhnd == *((_BYTE *)&v44[-1].dbcsBufferUsed + 7) )
        {
          v42 = (ioinfo *)((char *)v42 + 1);
          v44 = (ioinfo *)((char *)v44 - 1);
        }
      }
      strmov(dst: v45, dsta: v62, src: "--");
      v49 = (_BYTE *)strnmov(dst: v48, src: (tagShutdownType)v12, n: v36 - v12);
      *v49 = 61;
      for ( i = v49 + 1; v42 != v44; ++i )
      {
        if ( LOBYTE(v42->osfhnd) != 92 || v42 == (ioinfo *)((char *)&v44[-1].dbcsBufferUsed + 7) )
        {
          *i = v42->osfhnd;
        }
        else
        {
          v51 = SBYTE1(v42->osfhnd);
          v42 = (ioinfo *)((char *)v42 + 1);
          switch ( v51 )
          {
            case '"':
              *i = 34;
              break;
            case '\'':
              *i = 39;
              break;
            case '\\':
              *i = 92;
              break;
            case 'b':
              *i = 8;
              break;
            case 'n':
              *i = 10;
              break;
            case 'r':
              *i = 13;
              break;
            case 's':
              *i = 32;
              break;
            case 't':
              *i = 9;
              break;
            default:
              *i++ = 92;
              *i = v42->osfhnd;
              break;
          }
        }
        v42 = (ioinfo *)((char *)v42 + 1);
      }
      *i = 0;
      v41 = a1(a1: a2, a2: dst, a3: v62);
    }
    else
    {
      strmov(dst: v38, dsta: v62, src: "--");
      strmake(dst: v40, src: v12, length: v36 - v12);
      v41 = a1(a1: a2, a2: dst, a3: v62);
    }
    if ( v41 != 0 )
      goto LABEL_90;
    goto LABEL_83;
  }
  v54 = v56;
  v53 = "error: Found option without preceding group in config file: %s at line: %d\n";
LABEL_89:
  v52 = __iob_func();
  fprintf(str: v52 + 2, format: v53, filename, v54);
LABEL_90:
  my_fclose(a1: str, a2: 0);
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004159D0
// Name: search_default_file
// Source: json
//------------------------------------------------------------------------------
int __usercall search_default_file@<eax>(
        unsigned __int8 *a1@<ebx>,
        char *a2@<edi>,
        int (__cdecl *a3)(void *, char *, char *),
        void *a4)
{
  int *v4; // esi
  int result; // eax
  ioinfo *v6; // [esp+0h] [ebp-14h]
  _DWORD v7[2]; // [esp+Ch] [ebp-8h] BYREF

  v7[0] = defaultValue;
  v7[1] = 0;
  v4 = v7;
  if ( LOBYTE(fn_ext(result: v6)->osfhnd) == 0 )
    v4 = (int *)f_extensions;
  if ( *v4 == 0 )
    return 0;
  while ( 1 )
  {
    result = search_default_file_with_ext(a1: a3, a2: a4, a3: a1, a4: *v4, src: a2, a6: 0);
    if ( result < 0 )
      break;
    if ( *++v4 == 0 )
      return 0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00415A30
// Name: _my_search_option_files
// Source: json
//------------------------------------------------------------------------------
int __cdecl my_search_option_files(
        unsigned __int8 *string,
        int src,
        unsigned int count,
        char *a4,
        int a5,
        int a6,
        unsigned __int8 **a7)
{
  char *v7; // esi
  const char *v8; // eax
  char *v9; // edi
  int (__cdecl *v10)(void *, char *, char *); // ebp
  unsigned int v11; // ebx
  int **v12; // esi
  int *v13; // ebp
  unsigned __int8 *v14; // ecx
  int v16; // edi
  const char *v17; // eax
  unsigned int v18; // ebx
  unsigned __int8 *v19; // esi
  char *v20; // eax
  int v21; // eax
  int v22; // eax
  bool v23; // zf
  unsigned __int8 **v24; // edi
  int v25; // eax
  _iobuf *v26; // eax
  _iobuf *v27; // eax
  const char *v28; // [esp-4h] [ebp-14h]

  v7 = a4;
  *(_DWORD *)v7 += get_defaults_options(
                     a1: *(_DWORD *)src - *(_DWORD *)a4,
                     a2: (_LDBL12 **)(*(_DWORD *)count + 4 * *(_DWORD *)a4),
                     a3: &src,
                     &a4,
                     a5: &my_defaults_group_suffix);
  v8 = (const char *)my_defaults_group_suffix;
  if ( my_defaults_group_suffix == IdleShutdown )
  {
    v8 = getenv(option: "MYSQL_GROUP_SUFFIX");
    my_defaults_group_suffix = (tagShutdownType)v8;
  }
  if ( a4 != nullptr )
    my_defaults_extra_file = a4;
  v9 = (char *)src;
  if ( src != 0 )
    `WspiapiFreeAddrInfo'::`2'::pfFreeAddrInfo.EntryInProgress = (void *)src;
  v10 = (int (__cdecl *)(void *, char *, char *))a5;
  if ( v8 != nullptr && (int (__cdecl *)(int, char *, int))a5 == handle_default_option )
  {
    v11 = strlen(v8);
    v12 = (int **)a6;
    v13 = *(int **)(a6 + 8);
    v14 = alloc_root(mem_root: *(int **)a6, length: (const void *)(8 * *v13 + 4));
    a4 = (char *)v14;
    if ( v14 == nullptr )
      return 2;
    v16 = 0;
    if ( *v13 != 0 )
    {
      count = v11 + 1;
      do
      {
        v17 = *(const char **)(v13[2] + 4 * v16);
        *(_DWORD *)&v14[4 * v16] = v17;
        v18 = strlen(v17);
        v19 = alloc_root(mem_root: *v12, length: (const void *)(v18 + count));
        if ( v19 == nullptr )
          return 2;
        v20 = a4;
        *(_DWORD *)&a4[4 * v16 + 4 * *v13] = v19;
        memcpy(dst: v19, src: *(unsigned __int8 **)&v20[4 * v16], count: v18);
        memcpy(dst: &v19[v18], src: (unsigned __int8 *)my_defaults_group_suffix, count);
        v12 = (int **)a6;
        v14 = (unsigned __int8 *)a4;
      }
      while ( ++v16 < (unsigned int)*v13 );
    }
    v9 = (char *)src;
    v21 = 2 * *v13;
    *v13 = v21;
    v13[2] = (int)v14;
    v10 = (int (__cdecl *)(void *, char *, char *))a5;
    *(_DWORD *)&v14[4 * v21] = 0;
  }
  else
  {
    v12 = (int **)a6;
  }
  if ( v9 != nullptr )
  {
    v22 = search_default_file_with_ext(
            a1: v10,
            a2: v12,
            a3: (unsigned __int8 *)defaultValue,
            a4: (int)defaultValue,
            src: v9,
            a6: 0);
    if ( v22 < 0 )
      goto LABEL_35;
    if ( v22 > 0 )
    {
      v28 = v9;
      goto LABEL_34;
    }
    return 0;
  }
  if ( dirname_length(string) != 0 )
  {
    if ( search_default_file(a1: nullptr, a2: (char *)string, a3: v10, a4: v12) < 0 )
      goto LABEL_35;
    return 0;
  }
  v23 = *a7 == nullptr;
  v24 = a7;
  a4 = (char *)a7;
  if ( v23 )
    return 0;
  while ( **v24 != 0 )
  {
    if ( search_default_file(a1: *v24, a2: (char *)string, a3: v10, a4: v12) < 0 )
      goto LABEL_35;
    v24 = (unsigned __int8 **)a4;
LABEL_31:
    v23 = *++v24 == nullptr;
    a4 = (char *)v24;
    if ( v23 )
      return 0;
  }
  if ( my_defaults_extra_file == nullptr )
    goto LABEL_31;
  v25 = search_default_file_with_ext(
          a1: v10,
          a2: v12,
          a3: (unsigned __int8 *)defaultValue,
          a4: (int)defaultValue,
          src: my_defaults_extra_file,
          a6: 0);
  if ( v25 >= 0 )
  {
    if ( v25 <= 0 )
      goto LABEL_31;
    v28 = my_defaults_extra_file;
LABEL_34:
    v26 = __iob_func();
    fprintf(str: v26 + 2, format: "Could not open required defaults file: %s\n", v28);
  }
LABEL_35:
  v27 = __iob_func();
  fprintf(str: v27 + 2, format: "Fatal error in defaults handling. Program aborted\n");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00415C90
// Name: _my_load_defaults
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
int __cdecl my_load_defaults(
        unsigned __int8 *conf_file,
        _DWORD *a2,
        int *argc,
        _PEB_FREE_BLOCK *argv,
        unsigned __int8 **a5)
{
  unsigned __int8 *inited; // edi
  unsigned int v6; // edx
  unsigned __int8 *v7; // eax
  _PEB_FREE_BLOCK *v8; // edx
  unsigned int i; // ecx
  int result; // eax
  _DWORD *v11; // eax
  int (__stdcall *v12)(unsigned int, unsigned int, const char *, int, unsigned __int16 *, int); // ecx
  int v13; // eax
  int v14; // ecx
  unsigned __int8 *v15; // eax
  char *v16; // edi
  _iobuf *v17; // eax
  _PEB_FREE_BLOCK *v18; // esi
  unsigned int v19; // eax
  int v20; // eax
  int j; // esi
  char found_print_defaults; // [esp+13h] [ebp-61h]
  unsigned int args_used; // [esp+14h] [ebp-60h] BYREF
  char *ptr; // [esp+18h] [ebp-5Ch]
  unsigned __int8 *v25; // [esp+1Ch] [ebp-58h]
  int error; // [esp+20h] [ebp-54h]
  _DWORD v27[3]; // [esp+24h] [ebp-50h] BYREF
  int (__stdcall *group)(unsigned int, unsigned int, const char *, int, unsigned __int16 *, int); // [esp+30h] [ebp-44h] BYREF
  const char *v29; // [esp+34h] [ebp-40h]
  _DWORD *v30; // [esp+38h] [ebp-3Ch]
  void *(__stdcall *args)(const char *, unsigned int, unsigned int, _SECURITY_ATTRIBUTES *, unsigned int, unsigned int, void *); // [esp+40h] [ebp-34h] BYREF
  int v32; // [esp+44h] [ebp-30h]
  _BYTE alloc[32]; // [esp+54h] [ebp-20h] OVERLAPPED BYREF

  found_print_defaults = 0;
  args_used = 0;
  init_alloc_root(result: (_stat64 *)alloc, block_size: 0x200u, pre_alloc_size: 0);
  inited = init_default_directories(mem_root: (int *)alloc);
  v25 = inited;
  if ( inited == nullptr )
    goto err_2;
  v6 = *argc;
  if ( *argc >= 2 && strcmp((const char *)argv->Next->Size, "--no-defaults") == 0 )
  {
    v7 = alloc_root(mem_root: (int *)alloc, length: (const void *)(4 * v6 + 36));
    if ( v7 != nullptr )
    {
      v8 = (_PEB_FREE_BLOCK *)(v7 + 32);
      *((_DWORD *)v7 + 8) = argv->Next->Next;
      *((_DWORD *)v7 + 9) = args_separator;
      for ( i = 2; i < *argc; ++i )
        *((_DWORD *)&v8->Next + i) = *((_DWORD *)&argv->Next->Next + i);
      *((_DWORD *)&v8->Next + i) = 0;
      argv->Next = v8;
      qmemcpy(v7, alloc, 32);
      if ( a5 != nullptr )
        *a5 = v25;
      return 0;
    }
err_2:
    v17 = __iob_func();
    fprintf(str: v17 + 2, format: "Fatal error in defaults handling. Program aborted\n");
    exit(code: 1);
  }
  v11 = a2;
  v12 = nullptr;
  group = nullptr;
  v29 = "defaults";
  v30 = a2;
  if ( *a2 != 0 )
  {
    do
    {
      ++v11;
      v12 = (int (__stdcall *)(unsigned int, unsigned int, const char *, int, unsigned __int16 *, int))((char *)v12 + 1);
    }
    while ( *v11 != 0 );
    group = v12;
  }
  if ( init_dynamic_array2(a1: (unsigned __int8 **)&args, a2: (unsigned __int8 *)4, a3: nullptr, a4: v6, a5: 0x20u) != 0 )
    goto err_2;
  v27[0] = alloc;
  v27[1] = &args;
  v27[2] = &group;
  v13 = my_search_option_files(
          string: conf_file,
          src: (int)argc,
          count: (unsigned int)argv,
          a4: (char *)&args_used,
          a5: (int)handle_default_option,
          a6: (int)v27,
          a7: (unsigned __int8 **)inited);
  v14 = v32 + *argc;
  error = v13;
  v15 = alloc_root(mem_root: (int *)alloc, length: (const void *)(4 * v14 + 40));
  v16 = (char *)v15;
  ptr = (char *)v15;
  if ( v15 == nullptr )
    goto err_2;
  v18 = (_PEB_FREE_BLOCK *)(v15 + 32);
  *((_DWORD *)v15 + 8) = argv->Next->Next;
  memcpy(dst: v15 + 36, src: (unsigned __int8 *)args, count: 4 * v32);
  v19 = args_used;
  *argc -= args_used;
  argv->Next = (_PEB_FREE_BLOCK *)((char *)argv->Next + 4 * v19);
  if ( *argc >= 2 )
  {
    v20 = strcmp((const char *)argv->Next->Size, "--print-defaults");
    v16 = ptr;
    if ( v20 == 0 )
    {
      --*argc;
      argv->Next = (_PEB_FREE_BLOCK *)((char *)argv->Next + 4);
      found_print_defaults = 1;
    }
  }
  *(&v18->Size + v32) = args_separator;
  if ( *argc != 0 )
    memcpy(
      dst: (unsigned __int8 *)&v18[1].Next + 4 * v32,
      src: (unsigned __int8 *)&argv->Next->Size,
      count: 4 * *argc - 4);
  *(&v18->Size + v32 + *argc) = 0;
  *argc += v32 + 1;
  argv->Next = v18;
  qmemcpy(v16, alloc, 32);
  delete_dynamic(a1: (int)&args);
  if ( found_print_defaults != 0 )
  {
    printf(format: "%s would have been started with the following arguments:\n", argv->Next->Next);
    for ( j = 1; j < *argc; ++j )
    {
      if ( *((_DWORD *)&argv->Next->Next + j) != args_separator )
        printf(format: "%s ", *((const char **)&argv->Next->Next + j));
    }
    puts(string: defaultValue);
    exit(code: 0);
  }
  result = error;
  if ( error == 0 && a5 != nullptr )
    *a5 = v25;
  return result;
}
