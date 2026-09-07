// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: mysql-connector-c-6.0.2/mysys/charset.c
// Functions: 20
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x0040FEF0
// Name: _my_charset_same
// Source: json
//------------------------------------------------------------------------------
BOOL __stdcall my_charset_same(const char **cs1, const char **cs2)
{
  return cs1 == cs2 || strcmp(cs1[4], cs2[4]) == 0;
}

//------------------------------------------------------------------------------
// Address: 0x0040FF40
// Name: get_collation_number_internal
// Source: json
//------------------------------------------------------------------------------
int __usercall get_collation_number_internal@<eax>(int a1@<edi>)
{
  unsigned __int8 **v1; // esi
  int v2; // eax

  v1 = &all_charsets;
  while ( 1 )
  {
    if ( *v1 != nullptr )
    {
      v2 = *((_DWORD *)*v1 + 5);
      if ( v2 != 0
        && (*((int (__cdecl **)(LIST_ENTRY32 *, int, int))off_4904F0 + 7))(a1: &my_charset_latin1, a2: v2, a3: a1) == 0 )
      {
        break;
      }
    }
    if ( ++v1 >= (unsigned __int8 **)&THR_LOCK_threads )
      return 0;
  }
  return *(_DWORD *)*v1;
}

//------------------------------------------------------------------------------
// Address: 0x0040FF80
// Name: init_state_maps
// Source: json
//------------------------------------------------------------------------------
char __usercall init_state_maps@<al>(_DWORD *a1@<eax>)
{
  int v2; // eax
  int v4; // esi
  _BYTE *v5; // ecx
  unsigned int i; // ebx
  char v7; // dl
  _BYTE *v8; // edx
  int v9; // esi
  int j; // edi
  bool v11; // bl

  v2 = my_once_alloc(Size: 0x100u, MyFlags: 16);
  a1[17] = v2;
  if ( v2 == 0 )
    return 1;
  v4 = my_once_alloc(Size: 0x100u, MyFlags: 16);
  a1[18] = v4;
  if ( v4 == 0 )
    return 1;
  v5 = (_BYTE *)a1[17];
  for ( i = 0; i < 0x100; ++i )
  {
    v7 = *(_BYTE *)((unsigned __int8)i + a1[8] + 1);
    if ( (v7 & 3) != 0 )
    {
      v5[i] = 2;
    }
    else if ( (v7 & 4) != 0 )
    {
      v5[i] = 14;
    }
    else
    {
      v5[i] = (v7 & 8) != 0 ? 26 : 1;
    }
  }
  v5[124] = 17;
  v5[38] = 17;
  v5[36] = 2;
  v5[95] = 2;
  v5[39] = 10;
  v5[46] = 16;
  v5[33] = 8;
  v5[61] = 8;
  v5[62] = 8;
  v5[60] = 9;
  v5[35] = 11;
  v5[59] = 22;
  v5[58] = 23;
  *v5 = 18;
  v5[92] = 19;
  v5[47] = 20;
  v5[42] = 21;
  v5[64] = 24;
  v5[96] = 27;
  v5[34] = 33;
  v8 = v5;
  v9 = v4 - (_DWORD)v5;
  for ( j = 256; j != 0; --j )
  {
    v11 = *v8 == 2 || *v8 == 14;
    (v8++)[v9] = v11;
  }
  v5[88] = 30;
  v5[120] = 30;
  v5[66] = 31;
  v5[98] = 31;
  v5[78] = 32;
  v5[110] = 32;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x00410090
// Name: simple_cs_init_functions
// Source: json
//------------------------------------------------------------------------------
int __usercall simple_cs_init_functions@<eax>(int result@<eax>)
{
  bool v1; // zf

  v1 = (*(_BYTE *)(result + 12) & 0x10) == 0;
  *(_DWORD *)(result + 100) = my_charset_8bit_handler;
  if ( v1 )
    *(_DWORD *)(result + 104) = my_collation_8bit_simple_ci_handler;
  else
    *(_DWORD *)(result + 104) = my_collation_8bit_bin_handler;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004100B0
// Name: cs_copy_data
// Source: json
//------------------------------------------------------------------------------
int __usercall cs_copy_data@<eax>(int *a1@<edi>, int *a2@<esi>)
{
  int v2; // eax
  unsigned int v3; // eax
  unsigned int v4; // eax
  unsigned int v5; // eax
  unsigned __int8 *v6; // eax
  int v7; // eax
  unsigned __int8 *v8; // eax
  int v9; // eax
  unsigned __int8 *v10; // eax
  int v11; // eax
  unsigned __int8 *v12; // eax
  int v13; // eax
  unsigned __int8 *v14; // eax
  int v15; // eax
  unsigned int v16; // eax

  v2 = *a1;
  if ( *a1 == 0 )
    v2 = *a2;
  *a2 = v2;
  if ( a1[4] != 0 )
  {
    v3 = my_once_strdup();
    a2[4] = v3;
    if ( v3 == 0 )
      return 1;
  }
  if ( a1[5] != 0 )
  {
    v4 = my_once_strdup();
    a2[5] = v4;
    if ( v4 == 0 )
      return 1;
  }
  if ( a1[6] != 0 )
  {
    v5 = my_once_strdup();
    a2[6] = v5;
    if ( v5 == 0 )
      return 1;
  }
  v6 = (unsigned __int8 *)a1[8];
  if ( v6 != nullptr )
  {
    v7 = my_once_memdup(src: v6, count: 0x101u, MyFlags: 16);
    a2[8] = v7;
    if ( v7 == 0 || init_state_maps(a1: a2) != 0 )
      return 1;
  }
  v8 = (unsigned __int8 *)a1[9];
  if ( v8 != nullptr )
  {
    v9 = my_once_memdup(src: v8, count: 0x100u, MyFlags: 16);
    a2[9] = v9;
    if ( v9 == 0 )
      return 1;
  }
  v10 = (unsigned __int8 *)a1[10];
  if ( v10 != nullptr )
  {
    v11 = my_once_memdup(src: v10, count: 0x100u, MyFlags: 16);
    a2[10] = v11;
    if ( v11 == 0 )
      return 1;
  }
  v12 = (unsigned __int8 *)a1[11];
  if ( v12 != nullptr )
  {
    v13 = my_once_memdup(src: v12, count: 0x100u, MyFlags: 16);
    a2[11] = v13;
    if ( v13 == 0 )
      return 1;
  }
  v14 = (unsigned __int8 *)a1[14];
  if ( v14 != nullptr )
  {
    v15 = my_once_memdup(src: v14, count: 0x200u, MyFlags: 16);
    a2[14] = v15;
    if ( v15 == 0 )
      return 1;
  }
  if ( a1[7] != 0 && (v16 = my_once_strdup(), a2[7] = v16, v16 == 0) )
    return 1;
  else
    return 0;
}

//------------------------------------------------------------------------------
// Address: 0x004101E0
// Name: simple_cs_is_full
// Source: json
//------------------------------------------------------------------------------
const char *__usercall simple_cs_is_full@<eax>(int a1@<eax>)
{
  return (const char *)(*(_DWORD *)(a1 + 16) != 0
                     && *(_DWORD *)(a1 + 56) != 0
                     && *(_DWORD *)(a1 + 32) != 0
                     && *(_DWORD *)(a1 + 40) != 0
                     && *(_DWORD *)(a1 + 36) != 0
                     && *(_DWORD *)a1 != 0
                     && *(_DWORD *)(a1 + 20) != 0
                     && (*(_DWORD *)(a1 + 44) != 0 || (*(_BYTE *)(a1 + 12) & 0x10) != 0));
}

//------------------------------------------------------------------------------
// Address: 0x00410220
// Name: copy_uca_collation
// Source: json
//------------------------------------------------------------------------------
int __usercall copy_uca_collation@<eax>(int result@<eax>, int a2@<ecx>)
{
  int v2; // ecx

  *(_DWORD *)(result + 100) = *(_DWORD *)(a2 + 100);
  *(_DWORD *)(result + 104) = *(_DWORD *)(a2 + 104);
  *(_DWORD *)(result + 76) = *(_DWORD *)(a2 + 76);
  *(_WORD *)(result + 92) = *(_WORD *)(a2 + 92);
  *(_WORD *)(result + 94) = *(_WORD *)(a2 + 94);
  *(_DWORD *)(result + 84) = *(_DWORD *)(a2 + 84);
  v2 = *(_DWORD *)(a2 + 88);
  *(_DWORD *)(result + 12) |= 0x2C8u;
  *(_DWORD *)(result + 88) = v2;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00410260
// Name: add_collation
// Source: json
//------------------------------------------------------------------------------
int __cdecl add_collation(int *a1)
{
  int v1; // edi
  int collation_number_internal; // eax
  unsigned __int8 *v3; // eax
  int v4; // eax
  unsigned __int8 *v5; // esi
  unsigned __int8 *v6; // ebx
  LIST_ENTRY32 *v7; // ecx
  int v9; // edx
  _BYTE *v10; // ecx
  unsigned __int8 v11; // al
  unsigned int v12; // eax
  unsigned int v13; // eax
  unsigned int v14; // eax

  v1 = a1[5];
  if ( v1 == 0 )
    return 0;
  if ( *a1 == 0 )
  {
    collation_number_internal = get_collation_number_internal(a1: v1);
    *a1 = collation_number_internal;
    if ( collation_number_internal == 0 )
      return 0;
  }
  if ( (&all_charsets)[*a1] == nullptr )
  {
    (&all_charsets)[*a1] = (unsigned __int8 *)my_once_alloc(Size: 0x6Cu, MyFlags: 0);
    v3 = (&all_charsets)[*a1];
    if ( v3 == nullptr )
      return 1;
    memset(dst: v3, value: 0, count: 0x6Cu);
  }
  v4 = *a1;
  if ( a1[1] == *a1 )
    a1[3] |= 0x20u;
  if ( a1[2] == v4 )
    a1[3] |= 0x10u;
  *((_DWORD *)(&all_charsets)[v4] + 3) |= a1[3];
  v5 = (&all_charsets)[*a1];
  if ( (v5[12] & 1) != 0 )
  {
    *(_DWORD *)v5 = *a1;
    if ( a1[6] == 0 || (v12 = my_once_strdup(), *((_DWORD *)v5 + 6) = v12, v12 != 0) )
    {
      if ( a1[4] == 0 || *((_DWORD *)v5 + 4) != 0 || (v13 = my_once_strdup(), *((_DWORD *)v5 + 4) = v13, v13 != 0) )
      {
        if ( a1[5] == 0 )
          goto LABEL_16;
        if ( *((_DWORD *)v5 + 5) != 0 )
          goto LABEL_16;
        v14 = my_once_strdup();
        *((_DWORD *)v5 + 5) = v14;
        if ( v14 != 0 )
          goto LABEL_16;
      }
    }
  }
  else
  {
    v6 = (&all_charsets)[*a1];
    if ( cs_copy_data(a1, a2: (int *)v5) == 0 )
    {
      v5[98] = 1;
      v5[99] = 1;
      if ( strcmp((const char *)a1[4], "ucs2") == 0 )
      {
        v7 = &my_charset_ucs2_unicode_ci;
      }
      else
      {
        if ( strcmp((const char *)a1[4], "utf8") == 0 )
        {
          copy_uca_collation(result: (int)v6, a2: (int)&my_charset_utf8mb4_unicode_ci);
          *((_DWORD *)v6 + 3) |= 0x208u;
          goto LABEL_16;
        }
        if ( strcmp((const char *)a1[4], "utf8mb3") == 0 )
        {
          copy_uca_collation(result: (int)v6, a2: (int)&my_charset_utf8mb3_unicode_ci);
          *((_DWORD *)v6 + 3) |= 0x208u;
          goto LABEL_16;
        }
        if ( strcmp((const char *)a1[4], "utf16") == 0 )
        {
          v7 = &my_charset_utf16_unicode_ci;
        }
        else
        {
          if ( strcmp((const char *)a1[4], "utf32") != 0 )
          {
            simple_cs_init_functions(result: (int)(&all_charsets)[*a1]);
            *((_DWORD *)v6 + 21) = 1;
            *((_DWORD *)v6 + 22) = 1;
            if ( (unsigned __int8)simple_cs_is_full(a1: (int)(&all_charsets)[*a1]) != 0 )
              *(_DWORD *)(v9 + 12) |= 8u;
            *((_DWORD *)(&all_charsets)[*a1] + 3) |= 0x200u;
            if ( v10 != nullptr )
            {
              v11 = v10[97];
              if ( v10[65] < v11 && v11 < v10[66] )
                *((_DWORD *)(&all_charsets)[*a1] + 3) |= 0x400u;
            }
            if ( (unsigned __int8)my_charset_is_8bit_pure_ascii() != 0 )
              *((_DWORD *)(&all_charsets)[*a1] + 3) |= 0x1000u;
            if ( (unsigned __int8)my_charset_is_ascii_compatible() == 0 )
              *((_DWORD *)(&all_charsets)[*a1] + 3) |= 0x2000u;
            goto LABEL_16;
          }
          v7 = &my_charset_utf32_unicode_ci;
        }
      }
      copy_uca_collation(result: (int)v6, a2: (int)v7);
      *((_DWORD *)v6 + 3) |= 0x2208u;
LABEL_16:
      *a1 = 0;
      a1[1] = 0;
      a1[2] = 0;
      a1[5] = 0;
      a1[11] = 0;
      a1[3] = 0;
      return 0;
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x004105B0
// Name: my_read_charset_file
// Source: json
//------------------------------------------------------------------------------
char __usercall my_read_charset_file@<al>(char *a1@<eax>, __int16 a2@<si>)
{
  unsigned int st_size; // ebp
  unsigned __int8 *v4; // ebx
  signed int v5; // eax
  unsigned int v6; // edi
  unsigned int v7; // ebp
  int v9; // [esp+0h] [ebp-4Ch]
  int v10; // [esp+10h] [ebp-3Ch]
  _stat64 buf; // [esp+14h] [ebp-38h] BYREF

  if ( my_stat(name: a1, &buf, my_flags: v9) == 0 )
    return 1;
  st_size = buf.st_size;
  v10 = buf.st_size;
  if ( LODWORD(buf.st_size) > 0x100000 )
    return 1;
  v4 = my_malloc(size: buf.st_size, my_flags: a2);
  if ( v4 == nullptr )
    return 1;
  v5 = my_open(lpFileName: a1, a2: 0, a3: a2);
  v6 = v5;
  if ( v5 < 0
    || (v7 = my_read(fd: v5, lpBuffer: (char *)v4, NumberOfBytesRead: st_size, a4: a2), my_close(fd: v6, a2), v7 != v10) )
  {
    my_no_flags_free(ptr: v4);
    return 1;
  }
  my_parse_charset_xml(a1: v4, a2: v10, a3: add_collation);
  my_no_flags_free(ptr: v4);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x00410650
// Name: _get_charsets_dir
// Source: json
//------------------------------------------------------------------------------
int __cdecl get_charsets_dir(char *dst)
{
  ExprNode **v1; // ecx
  int v3; // eax

  if ( `WspiapiFreeAddrInfo'::`2'::pfFreeAddrInfo.InLoadOrderModuleList.Flink != nullptr )
  {
    strmake(dst, src: (char *)`WspiapiFreeAddrInfo'::`2'::pfFreeAddrInfo.InLoadOrderModuleList.Flink, length: 0x1FFu);
    return convert_dirname((unsigned __int8 *)dst, src: (unsigned __int8 *)dst, a3: 0);
  }
  else
  {
    test_if_hard_path(dir_name: v1);
    if ( v3 != 0 || is_prefix(result: (_LDBL12 *)&result) != nullptr )
    {
      strxmov(dst, src: (int)&result, a3: (int)"/");
      return convert_dirname((unsigned __int8 *)dst, src: (unsigned __int8 *)dst, a3: 0);
    }
    else
    {
      strxmov(dst, src: (int)"C:/mysql/", a3: (int)"/");
      return convert_dirname((unsigned __int8 *)dst, src: (unsigned __int8 *)dst, a3: 0);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00410710
// Name: _add_compiled_collation
// Source: json
//------------------------------------------------------------------------------
LIST_ENTRY32 *__cdecl add_compiled_collation(LIST_ENTRY32 *a1)
{
  (&all_charsets)[a1->Flink] = (unsigned __int8 *)a1;
  a1[1].Blink |= 0x200u;
  return a1;
}

//------------------------------------------------------------------------------
// Address: 0x00410730
// Name: cs_alloc
// Source: json
//------------------------------------------------------------------------------
int __cdecl cs_alloc(unsigned int Size)
{
  return my_once_alloc(Size, MyFlags: 16);
}

//------------------------------------------------------------------------------
// Address: 0x00410740
// Name: init_available_charsets
// Source: json
//------------------------------------------------------------------------------
char __thiscall init_available_charsets(void *this)
{
  char charset_file; // bl
  unsigned __int8 **v3; // edi
  unsigned __int8 *v4; // eax
  char *charsets_dir; // eax
  void *v6; // ecx
  char dst[524]; // [esp+8h] [ebp-210h] BYREF

  charset_file = 0;
  if ( `WspiapiFreeAddrInfo'::`2'::pfFreeAddrInfo.InLoadOrderModuleList.Blink == nullptr )
  {
    EnterCriticalSection(lpCriticalSection: &THR_LOCK_charset);
    if ( `WspiapiFreeAddrInfo'::`2'::pfFreeAddrInfo.InLoadOrderModuleList.Blink == nullptr )
    {
      memset(dst: (unsigned __int8 *)&all_charsets, value: 0, count: 0x2000u);
      init_compiled_charsets(a1: this);
      v3 = &all_charsets;
      do
      {
        v4 = *v3;
        if ( *v3 != nullptr && *((_DWORD *)v4 + 8) != 0 && init_state_maps(a1: v4) != 0 )
          *v3 = nullptr;
        ++v3;
      }
      while ( v3 < (unsigned __int8 **)&THR_LOCK_threads );
      charsets_dir = (char *)get_charsets_dir(dst);
      strmov(dst: v6, dsta: charsets_dir, src: (char *)&result.ld12[8]);
      charset_file = my_read_charset_file(a1: dst, a2: (__int16)this);
      `WspiapiFreeAddrInfo'::`2'::pfFreeAddrInfo.InLoadOrderModuleList.Blink = (_LIST_ENTRY *)1;
    }
    LeaveCriticalSection(lpCriticalSection: &THR_LOCK_charset);
  }
  return charset_file;
}

//------------------------------------------------------------------------------
// Address: 0x00410820
// Name: _get_collation_number
// Source: json
//------------------------------------------------------------------------------
int __cdecl get_collation_number(int a1)
{
  init_available_charsets(this: nullptr);
  return get_collation_number_internal(a1);
}

//------------------------------------------------------------------------------
// Address: 0x00410840
// Name: _get_charset_number
// Source: json
//------------------------------------------------------------------------------
int __cdecl get_charset_number(int a1, int a2)
{
  unsigned __int8 **v2; // esi
  unsigned __int8 *v3; // eax
  int v4; // ecx

  init_available_charsets(this: nullptr);
  v2 = &all_charsets;
  while ( 1 )
  {
    v3 = *v2;
    if ( *v2 != nullptr )
    {
      v4 = *((_DWORD *)v3 + 4);
      if ( v4 != 0
        && (a2 & *((_DWORD *)v3 + 3)) != 0
        && (*((int (__cdecl **)(LIST_ENTRY32 *, int, int))off_4904F0 + 7))(a1: &my_charset_latin1, a2: v4, a3: a1) == 0 )
      {
        break;
      }
    }
    if ( ++v2 >= (unsigned __int8 **)&THR_LOCK_threads )
      return 0;
  }
  return *(_DWORD *)*v2;
}

//------------------------------------------------------------------------------
// Address: 0x004108A0
// Name: get_internal_charset
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 *__usercall get_internal_charset@<eax>(__int16 a1@<si>, int a2)
{
  unsigned __int8 *v2; // edi
  void *charsets_dir; // eax
  int v4; // eax
  unsigned __int8 (__cdecl **v5)(unsigned __int8 *, int (__cdecl *)(unsigned int)); // eax
  unsigned __int8 (__cdecl **v6)(unsigned __int8 *, int (__cdecl *)(unsigned int)); // eax
  int v8; // [esp-Ch] [ebp-214h]
  char dst[512]; // [esp+4h] [ebp-204h] BYREF

  v2 = (&all_charsets)[a2];
  if ( v2 != nullptr && (*((_DWORD *)v2 + 3) & 0x100) == 0 )
  {
    EnterCriticalSection(lpCriticalSection: &THR_LOCK_charset);
    if ( (v2[12] & 9) == 0 )
    {
      v8 = *((_DWORD *)v2 + 4);
      charsets_dir = (void *)get_charsets_dir(dst);
      strxmov(dst: charsets_dir, src: v8, a3: (int)".xml");
      my_read_charset_file(a1: dst, a2: a1);
    }
    v4 = *((_DWORD *)v2 + 3);
    if ( (v4 & 0x200) != 0 )
    {
      if ( (v4 & 0x100) != 0 )
      {
LABEL_13:
        LeaveCriticalSection(lpCriticalSection: &THR_LOCK_charset);
        return v2;
      }
      v5 = *((unsigned __int8 (__cdecl ***)(unsigned __int8 *, int (__cdecl *)(unsigned int)))v2 + 25);
      if ( *v5 == nullptr || (*v5)(a1: v2, a2: cs_alloc) == 0 )
      {
        v6 = *((unsigned __int8 (__cdecl ***)(unsigned __int8 *, int (__cdecl *)(unsigned int)))v2 + 26);
        if ( *v6 == nullptr || (*v6)(a1: v2, a2: cs_alloc) == 0 )
        {
          *((_DWORD *)v2 + 3) |= 0x100u;
          goto LABEL_13;
        }
      }
    }
    v2 = nullptr;
    goto LABEL_13;
  }
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x00410990
// Name: _get_charset_by_name
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 *__cdecl get_charset_by_name(int ap, __int16 a2)
{
  int collation_number; // eax
  unsigned __int8 *result; // eax
  unsigned __int8 *v4; // esi
  char *charsets_dir; // eax
  void *v6; // ecx
  char dst[524]; // [esp+Ch] [ebp-210h] BYREF

  init_available_charsets(this: nullptr);
  collation_number = get_collation_number(a1: ap);
  if ( collation_number != 0 )
  {
    result = get_internal_charset(a1: a2, a2: collation_number);
    v4 = result;
    if ( result != nullptr )
      return result;
  }
  else
  {
    v4 = nullptr;
  }
  if ( (a2 & 0x10) != 0 )
  {
    charsets_dir = (char *)get_charsets_dir(dst);
    strmov(dst: v6, dsta: charsets_dir, src: (char *)&::result.ld12[8]);
    my_error(a1: 28, a2: 4, ap);
  }
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x00410A30
// Name: _get_charset_by_csname
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 *__cdecl get_charset_by_csname(tagShutdownType cs_name, unsigned int cs_flags, __int16 flags)
{
  int charset_number; // eax
  unsigned __int8 *result; // eax
  unsigned int v5; // esi
  char *charsets_dir; // eax
  void *v7; // ecx
  char dst[524]; // [esp+Ch] [ebp-210h] BYREF

  init_available_charsets(this: nullptr);
  charset_number = get_charset_number(a1: cs_name, a2: cs_flags);
  if ( charset_number != 0 )
  {
    result = get_internal_charset(a1: flags, a2: charset_number);
    v5 = (unsigned int)result;
    if ( result != nullptr )
      return result;
  }
  else
  {
    v5 = 0;
  }
  if ( (flags & 0x10) != 0 )
  {
    charsets_dir = (char *)get_charsets_dir(dst);
    strmov(dst: v7, dsta: charsets_dir, src: (char *)&::result.ld12[8]);
    my_error(a1: 22, a2: 4, ap: cs_name);
  }
  return (unsigned __int8 *)v5;
}

//------------------------------------------------------------------------------
// Address: 0x00410AD0
// Name: _escape_string_for_mysql
// Source: json
//------------------------------------------------------------------------------
int __cdecl escape_string_for_mysql(int a1, char *a2, int a3, unsigned int a4, int a5)
{
  char *v6; // esi
  int v7; // eax
  char *v8; // edi
  unsigned int v9; // ebx
  int v10; // eax
  char v11; // al
  char *v12; // esi
  char v15; // [esp+Ch] [ebp+8h]
  bool v16; // [esp+10h] [ebp+Ch]
  unsigned int v17; // [esp+18h] [ebp+14h]

  v6 = a2;
  if ( a3 != 0 )
    v7 = a3 - 1;
  else
    v7 = 2 * a5;
  v17 = (unsigned int)&a2[v7];
  v8 = (char *)a4;
  v9 = a4 + a5;
  v16 = *(_DWORD *)(*(_DWORD *)(a1 + 100) + 4) != 0;
  v15 = 0;
  if ( a4 >= a4 + a5 )
    goto LABEL_27;
  while ( 1 )
  {
    if ( !v16 )
    {
LABEL_14:
      v11 = *v8;
      switch ( *v8 )
      {
        case 0:
          v11 = 48;
          goto LABEL_12;
        case 10:
          v11 = 110;
          goto LABEL_12;
        case 13:
          v11 = 114;
          goto LABEL_12;
        case 26:
          v11 = 90;
          goto LABEL_12;
        case 34:
          v11 = 34;
          goto LABEL_12;
        case 39:
          v11 = 39;
          goto LABEL_12;
        case 92:
          v11 = 92;
          goto LABEL_12;
        default:
          goto LABEL_22;
      }
    }
    v10 = (*(int (__cdecl **)(int, char *, unsigned int))(*(_DWORD *)(a1 + 100) + 4))(a1, a2: v8, a3: v9);
    if ( v10 != 0 )
    {
      if ( (unsigned int)&v6[v10] > v17 )
        goto LABEL_26;
      do
      {
        --v10;
        *v6++ = *v8++;
      }
      while ( v10 != 0 );
      --v8;
      goto LABEL_24;
    }
    if ( (*(int (__cdecl **)(int, _DWORD))(*(_DWORD *)(a1 + 100) + 8))(a1, a2: *v8) <= 1 )
      goto LABEL_14;
    v11 = *v8;
    if ( *v8 == 0 )
      break;
LABEL_12:
    if ( (unsigned int)(v6 + 2) > v17 )
      goto LABEL_26;
    *v6 = 92;
    v12 = v6 + 1;
    *v12 = v11;
    v6 = v12 + 1;
LABEL_24:
    if ( (unsigned int)++v8 >= v9 )
      goto LABEL_27;
  }
LABEL_22:
  if ( (unsigned int)(v6 + 1) <= v17 )
  {
    *v6++ = v11;
    goto LABEL_24;
  }
LABEL_26:
  v15 = 1;
LABEL_27:
  *v6 = 0;
  if ( v15 != 0 )
    return -1;
  else
    return v6 - a2;
}

//------------------------------------------------------------------------------
// Address: 0x00410C70
// Name: _fs_character_set
// Source: json
//------------------------------------------------------------------------------
LIST_ENTRY32 *fs_character_set()
{
  LIST_ENTRY32 *result; // eax
  bool v1; // zf
  char v2[3]; // [esp+0h] [ebp-10h] BYREF
  int v3; // [esp+3h] [ebp-Dh]
  __int16 v4; // [esp+7h] [ebp-9h]
  char v5; // [esp+9h] [ebp-7h]

  result = (LIST_ENTRY32 *)`WspiapiFreeAddrInfo'::`2'::pfFreeAddrInfo.InMemoryOrderModuleList.Flink;
  if ( `WspiapiFreeAddrInfo'::`2'::pfFreeAddrInfo.InMemoryOrderModuleList.Flink == nullptr )
  {
    strcpy(v2, "cp");
    v3 = 0;
    v4 = 0;
    v5 = 0;
    GetLocaleInfoA(Locale: 0x800u, LCType: 0x1004u, lpLCData: &v2[2], cchData: 7);
    v1 = strcmp(v2, "cp932") == 0;
    result = &my_charset_cp932_japanese_ci;
    if ( !v1 )
      result = &my_charset_bin;
    `WspiapiFreeAddrInfo'::`2'::pfFreeAddrInfo.InMemoryOrderModuleList.Flink = (_LIST_ENTRY *)result;
  }
  return result;
}
