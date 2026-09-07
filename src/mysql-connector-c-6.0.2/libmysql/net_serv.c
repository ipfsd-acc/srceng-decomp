// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: mysql-connector-c-6.0.2/libmysql/net_serv.c
// Functions: 14
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x0040E650
// Name: _my_net_init
// Source: json
//------------------------------------------------------------------------------
char __cdecl my_net_init(int net, int net_4)
{
  int v2; // eax

  *(_DWORD *)net = net_4;
  my_net_local_init((char *)net);
  v2 = my_malloc(size: *(_DWORD *)(net + 40) + 7, my_flags: 16);
  *(_DWORD *)(net + 4) = v2;
  if ( v2 == 0 )
    return 1;
  *(_DWORD *)(net + 8) = v2 + *(_DWORD *)(net + 40);
  *(_BYTE *)(net + 92) = 0;
  *(_DWORD *)(net + 72) = 0;
  *(_DWORD *)(net + 52) = 0;
  *(_DWORD *)(net + 48) = 0;
  *(_DWORD *)(net + 16) = v2;
  *(_DWORD *)(net + 12) = v2;
  *(_BYTE *)(net + 95) = 0;
  *(_BYTE *)(net + 80) = 0;
  *(_BYTE *)(net + 76) = 0;
  *(_DWORD *)(net + 24) = 0;
  *(_DWORD *)(net + 36) = 0;
  *(_DWORD *)(net + 88) = 0;
  *(_DWORD *)(net + 84) = 0;
  if ( net_4 != 0 )
  {
    *(_DWORD *)(net + 20) = yaX509_STORE_CTX_get_error(a1: net_4);
    (*(void (__cdecl **)(int))(net_4 + 352))(a1: net_4);
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x0040E6D0
// Name: _net_end
// Source: json
//------------------------------------------------------------------------------
int __stdcall net_end(const char *net)
{
  int result; // eax

  result = my_no_flags_free();
  *((_DWORD *)net + 1) = 0;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0040E6F0
// Name: _net_realloc
// Source: json
//------------------------------------------------------------------------------
char __cdecl net_realloc(int a1, unsigned int a2)
{
  unsigned int v3; // edi
  int v4; // eax

  if ( a2 < *(_DWORD *)(a1 + 44) )
  {
    v3 = (a2 + 4095) & 0xFFFFF000;
    v4 = my_realloc(ptr: *(void **)(a1 + 4), size: v3 + 7, my_flags: 16);
    if ( v4 != 0 )
    {
      *(_DWORD *)(a1 + 12) = v4;
      *(_DWORD *)(a1 + 4) = v4;
      *(_DWORD *)(a1 + 40) = v3;
      *(_DWORD *)(a1 + 8) = v3 + v4;
      return 0;
    }
    else
    {
      *(_BYTE *)(a1 + 92) = 1;
      *(_DWORD *)(a1 + 88) = 1041;
      return 1;
    }
  }
  else
  {
    *(_BYTE *)(a1 + 92) = 1;
    *(_DWORD *)(a1 + 88) = 1153;
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040E760
// Name: net_data_is_ready
// Source: json
//------------------------------------------------------------------------------
BOOL __usercall net_data_is_ready@<eax>(SOCKET a1@<esi>)
{
  int v1; // eax
  struct timeval timeout; // [esp+0h] [ebp-10Ch] BYREF
  fd_set readfds; // [esp+8h] [ebp-104h] BYREF

  readfds.fd_array[0] = a1;
  readfds.fd_count = 1;
  timeout.tv_usec = 0;
  timeout.tv_sec = 0;
  v1 = select(nfds: a1 + 1, &readfds, writefds: nullptr, exceptfds: nullptr, &timeout);
  if ( v1 < 0 )
    return false;
  if ( v1 != 0 )
    return __WSAFDIsSet(fd: a1, a2: &readfds) != 0;
  return false;
}

//------------------------------------------------------------------------------
// Address: 0x0040E7E0
// Name: _net_clear
// Source: json
//------------------------------------------------------------------------------
void __cdecl net_clear(SOCKET **clear_buffer, char a2)
{
  SOCKET *v2; // edx

  if ( a2 != 0 && net_data_is_ready(a1: **clear_buffer) > 0 )
  {
    while ( ((int (__cdecl *)(SOCKET *, SOCKET *, SOCKET *))(*clear_buffer)[83])(
              a1: *clear_buffer,
              a2: clear_buffer[1],
              a3: clear_buffer[10]) > 0 )
    {
      if ( net_data_is_ready(a1: **clear_buffer) <= 0 )
        goto LABEL_7;
    }
    *((_BYTE *)clear_buffer + 92) = 2;
  }
LABEL_7:
  v2 = clear_buffer[1];
  clear_buffer[13] = nullptr;
  clear_buffer[12] = nullptr;
  clear_buffer[3] = v2;
}

//------------------------------------------------------------------------------
// Address: 0x0040E850
// Name: _net_real_write
// Source: json
//------------------------------------------------------------------------------
int __cdecl net_real_write(_DWORD *a1, unsigned __int8 *src, unsigned int count)
{
  _DWORD *v3; // esi
  bool v5; // zf
  int v6; // edi
  unsigned __int8 *v7; // ebx
  unsigned __int8 *v8; // edi
  unsigned __int8 *v9; // ebp
  int v10; // eax
  char v11; // al

  v3 = a1;
  (*(void (__cdecl **)(_DWORD))(*a1 + 344))(a1: *a1);
  if ( *((_BYTE *)v3 + 92) == 2 )
    return -1;
  v5 = *((_BYTE *)v3 + 80) == 0;
  *((_BYTE *)v3 + 76) = 2;
  if ( v5 )
  {
    v7 = src;
  }
  else
  {
    v6 = my_malloc(size: count + 7, my_flags: 16);
    if ( v6 == 0 )
    {
      *((_BYTE *)v3 + 92) = 2;
      v3[22] = 1041;
      *((_BYTE *)v3 + 76) = 0;
      return 1;
    }
    memcpy(dst: (unsigned __int8 *)(v6 + 7), src, count);
    if ( (unsigned __int8)my_compress(dst: (unsigned __int8 *)(v6 + 7), a2: (int)&count, a3: (int)&a1) != 0 )
      a1 = nullptr;
    *(_WORD *)(v6 + 4) = (_WORD)a1;
    *(_BYTE *)(v6 + 6) = BYTE2(a1);
    *(_WORD *)v6 = count;
    *(_BYTE *)(v6 + 2) = BYTE2(count);
    *(_BYTE *)(v6 + 3) = *((_BYTE *)v3 + 52);
    ++v3[13];
    count += 7;
    v7 = (unsigned __int8 *)v6;
  }
  v8 = &v7[count];
  v9 = v7;
  if ( v7 != &v7[count] )
  {
    while ( 1 )
    {
      v10 = (*(int (__cdecl **)(_DWORD, unsigned __int8 *, int))(*v3 + 336))(a1: *v3, a2: v9, a3: v8 - v9);
      if ( v10 <= 0 )
        break;
      v9 += v10;
      if ( v9 == v8 )
        goto LABEL_15;
    }
    v11 = (*(int (__cdecl **)(_DWORD))(*v3 + 364))(a1: *v3);
    *((_BYTE *)v3 + 92) = 2;
    v3[22] = (v11 != 0) + 1160;
  }
LABEL_15:
  if ( *((_BYTE *)v3 + 80) != 0 )
    my_no_flags_free();
  *((_BYTE *)v3 + 76) = 0;
  return v9 != v8;
}

//------------------------------------------------------------------------------
// Address: 0x0040E9B0
// Name: my_real_read
// Source: json
//------------------------------------------------------------------------------
int __usercall my_real_read@<eax>(_DWORD *a1@<esi>, int *a2)
{
  unsigned int v2; // ebx
  int v3; // edi
  int v4; // edi
  int v5; // ebp
  int v6; // eax
  int v7; // eax
  int v8; // ecx
  char v9; // dl
  int v10; // ecx
  bool v11; // zf
  int v12; // eax
  int v13; // edx
  int v14; // ecx
  unsigned int v15; // eax
  int v17; // eax
  BOOL v18; // ecx
  int v19; // [esp+Ch] [ebp-4h]

  v2 = -1;
  (*(void (__cdecl **)(_DWORD))(*a1 + 344))(a1: *a1);
  v3 = -(*((_BYTE *)a1 + 80) != 0);
  *a2 = 0;
  v4 = (v3 & 3) + 4;
  v5 = a1[9] + a1[1];
  *((_BYTE *)a1 + 76) = 1;
  v19 = 0;
  while ( v4 == 0 )
  {
LABEL_5:
    if ( v19 == 0 )
    {
      v7 = a1[1];
      v8 = a1[9];
      v9 = *(_BYTE *)(v8 + v7 + 3);
      v10 = v7 + v8;
      if ( v9 != *((_BYTE *)a1 + 48) )
        goto LABEL_18;
      ++a1[12];
      v11 = *((_BYTE *)a1 + 80) == 0;
      a1[13] = a1[12];
      if ( !v11 )
        *a2 = *(_DWORD *)(v10 + 4) & 0xFFFFFF;
      v12 = a1[9];
      v13 = a1[1];
      v2 = *(_DWORD *)(v12 + v13) & 0xFFFFFF;
      if ( v2 == 0 )
        goto LABEL_19;
      v14 = *a2;
      if ( v2 > *a2 )
        v14 = *(_DWORD *)(v12 + v13) & 0xFFFFFF;
      v15 = v14 + v12;
      if ( v15 >= a1[10] && net_realloc((int)a1, a2: v15) != 0 )
      {
LABEL_18:
        v2 = -1;
LABEL_19:
        *((_BYTE *)a1 + 76) = 0;
        return v2;
      }
      v5 = a1[9] + a1[1];
      v4 = v2;
    }
    if ( (unsigned int)++v19 >= 2 )
    {
      *((_BYTE *)a1 + 76) = 0;
      return v2;
    }
  }
  while ( 1 )
  {
    v6 = (*(int (__cdecl **)(_DWORD, int, int))(*a1 + 332))(a1: *a1, a2: v5, a3: v4);
    if ( v6 <= 0 )
      break;
    v4 -= v6;
    v5 += v6;
    if ( v4 == 0 )
      goto LABEL_5;
  }
  (*(void (__cdecl **)(_DWORD))(*a1 + 364))(a1: *a1);
  v17 = *a1;
  *((_BYTE *)a1 + 92) = 2;
  v18 = (*(unsigned __int8 (__cdecl **)(int))(v17 + 368))(a1: v17) != 0;
  *((_BYTE *)a1 + 76) = 0;
  a1[22] = v18 + 1158;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0040EB00
// Name: _my_net_read
// Source: json
//------------------------------------------------------------------------------
int __stdcall my_net_read(unsigned int net)
{
  _DWORD *v1; // esi
  int result; // eax
  int v3; // ebx
  int v4; // edi
  int v5; // ecx
  int v6; // eax
  unsigned int v7; // ebp
  int v8; // ebx
  int v9; // edi
  int v10; // eax
  int v11; // eax
  int v12; // eax
  int v13; // ecx
  int v14; // ebx
  unsigned int multi_byte_packet; // [esp+Ch] [ebp-Ch]
  unsigned int read_length; // [esp+10h] [ebp-8h]
  unsigned __int8 *v17; // [esp+14h] [ebp-4h]

  v1 = (_DWORD *)net;
  if ( *(_BYTE *)(net + 80) == 0 )
  {
    result = my_real_read(a1: (_DWORD *)net, a2: (int *)&net);
    if ( result == 0xFFFFFF )
    {
      v3 = v1[9];
      v4 = 0;
      do
      {
        v1[9] += result;
        v4 += result;
        result = my_real_read(a1: v1, a2: (int *)&net);
      }
      while ( result == 0xFFFFFF );
      if ( result != -1 )
        result += v4;
      v1[9] = v3;
    }
    v5 = v1[9] + v1[1];
    v1[4] = v5;
    if ( result != -1 )
      *(_BYTE *)(v5 + result) = 0;
    return result;
  }
  v6 = *(_DWORD *)(net + 24);
  v7 = 0;
  multi_byte_packet = 0;
  if ( v6 != 0 )
  {
    v7 = *(_DWORD *)(net + 32);
    v8 = v7 - v6;
    v9 = v8;
    *(_BYTE *)(v8 + *(_DWORD *)(net + 4)) = *(_BYTE *)(net + 77);
  }
  else
  {
    v9 = 0;
    v8 = 0;
  }
  while ( 1 )
  {
    while ( v7 - v8 >= 4 )
    {
      v17 = (unsigned __int8 *)(v8 + v1[1]);
      v10 = *(_DWORD *)v17 & 0xFFFFFF;
      read_length = v10;
      if ( v10 == 0 )
      {
        v8 += 4;
LABEL_29:
        v12 = v1[1];
        v1[8] = v7;
        v13 = v12 + v9 + 4;
        v1[6] = v7 - v8;
        v14 = v8 - v9 - multi_byte_packet - 4;
        v1[4] = v13;
        *((_BYTE *)v1 + 77) = *(_BYTE *)(v13 + v14);
        *(_BYTE *)(v13 + v14) = 0;
        return v14;
      }
      if ( v10 + 4 > v7 - v8 )
        break;
      if ( multi_byte_packet != 0 )
      {
        memmove(dst: &v17[v9], src: &v17[v9 + 4], count: v7 - v8);
        v8 += read_length;
        v10 = read_length;
        v7 -= 4;
      }
      else
      {
        v8 += v10 + 4;
      }
      if ( v10 != 0xFFFFFF )
      {
        multi_byte_packet = 0;
        goto LABEL_29;
      }
      multi_byte_packet = 4;
      if ( v9 != 0 )
      {
        v7 -= v9;
        memmove(dst: (unsigned __int8 *)v1[1], src: (unsigned __int8 *)(v1[1] + v9), count: v7);
        v8 -= v9;
        v9 = 0;
      }
    }
    if ( v9 != 0 )
    {
      v7 -= v9;
      memmove(dst: (unsigned __int8 *)v1[1], src: (unsigned __int8 *)(v1[1] + v9), count: v7);
      v8 -= v9;
      v9 = 0;
    }
    v1[9] = v7;
    v11 = my_real_read(a1: v1, a2: (int *)&net);
    if ( v11 == -1 )
      return -1;
    if ( (unsigned __int8)my_uncompress(dst: (unsigned __int8 *)(v1[9] + v1[1]), a2: v11, count: (unsigned int)&net) != 0 )
      break;
    v7 += net;
  }
  *((_BYTE *)v1 + 92) = 2;
  v1[22] = 1157;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0040ECD0
// Name: _my_net_set_read_timeout
// Source: json
//------------------------------------------------------------------------------
int __cdecl my_net_set_read_timeout(void (__cdecl *net)(), int a2)
{
  int result; // eax

  *((_DWORD *)net + 15) = a2;
  result = *(_DWORD *)net;
  if ( *(_DWORD *)net != 0 )
    return (*(int (__cdecl **)(int, _DWORD, int))(result + 376))(a1: result, a2: 0, a3: a2);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0040ED00
// Name: _my_net_set_write_timeout
// Source: json
//------------------------------------------------------------------------------
int __cdecl my_net_set_write_timeout(void (__cdecl *net)(), int a2)
{
  int result; // eax

  *((_DWORD *)net + 14) = a2;
  result = *(_DWORD *)net;
  if ( *(_DWORD *)net != 0 )
    return (*(int (__cdecl **)(int, int, int))(result + 376))(a1: result, a2: 1, a3: a2);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0040ED30
// Name: _net_flush
// Source: json
//------------------------------------------------------------------------------
bool __cdecl net_flush(int net)
{
  unsigned __int8 *v1; // edx
  unsigned __int8 *v2; // ecx
  bool result; // al

  v1 = *(unsigned __int8 **)(net + 4);
  v2 = *(unsigned __int8 **)(net + 12);
  result = false;
  if ( v1 != v2 )
  {
    result = net_real_write(a1: (_DWORD *)net, src: v1, count: v2 - v1) != 0;
    *(_DWORD *)(net + 12) = *(_DWORD *)(net + 4);
  }
  if ( *(_BYTE *)(net + 80) != 0 )
    *(_DWORD *)(net + 48) = *(_DWORD *)(net + 52);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0040ED70
// Name: net_write_buff
// Source: json
//------------------------------------------------------------------------------
bool __usercall net_write_buff@<al>(unsigned int a1@<eax>, int a2@<esi>, unsigned __int8 *src)
{
  unsigned __int8 *v3; // ebp
  unsigned __int8 *v5; // eax
  unsigned int v6; // edi

  v3 = src;
  if ( *(_BYTE *)(a2 + 80) != 0 && *(_DWORD *)(a2 + 40) > 0xFFFFFFu )
  {
    v5 = *(unsigned __int8 **)(a2 + 12);
    v6 = *(_DWORD *)(a2 + 4) - (_DWORD)v5 + 0xFFFFFF;
  }
  else
  {
    v5 = *(unsigned __int8 **)(a2 + 12);
    v6 = *(_DWORD *)(a2 + 8) - (_DWORD)v5;
  }
  if ( a1 > v6 )
  {
    if ( v5 != *(unsigned __int8 **)(a2 + 4) )
    {
      memcpy(dst: v5, src, count: v6);
      if ( net_real_write(
             a1: (_DWORD *)a2,
             src: *(unsigned __int8 **)(a2 + 4),
             count: *(_DWORD *)(a2 + 12) + v6 - *(_DWORD *)(a2 + 4)) != 0 )
        return true;
      v3 = &src[v6];
      *(_DWORD *)(a2 + 12) = *(_DWORD *)(a2 + 4);
      a1 -= v6;
    }
    if ( *(_BYTE *)(a2 + 80) != 0 && a1 > 0xFFFFFF )
    {
      while ( net_real_write(a1: (_DWORD *)a2, src: v3, count: 0xFFFFFFu) == 0 )
      {
        a1 -= 0xFFFFFF;
        v3 += 0xFFFFFF;
        if ( a1 <= 0xFFFFFF )
          goto LABEL_14;
      }
      return true;
    }
LABEL_14:
    if ( a1 > *(_DWORD *)(a2 + 40) )
      return net_real_write(a1: (_DWORD *)a2, src: v3, count: a1) != 0;
  }
  memcpy(dst: *(unsigned __int8 **)(a2 + 12), src: v3, count: a1);
  *(_DWORD *)(a2 + 12) += a1;
  return false;
}

//------------------------------------------------------------------------------
// Address: 0x0040EE50
// Name: _my_net_write
// Source: json
//------------------------------------------------------------------------------
bool __cdecl my_net_write(const LoggingContext_t *result, unsigned __int8 *a2, unsigned int len)
{
  _IMAGE_SECTION_HEADER *v3; // esi
  unsigned int v5; // ebx
  unsigned __int8 *i; // edi
  char PhysicalAddress; // al
  char v8; // cl

  v3 = (_IMAGE_SECTION_HEADER *)result;
  if ( result->m_ChannelID == 0 )
    return false;
  v5 = len;
  for ( i = a2; v5 >= 0xFFFFFF; i += 0xFFFFFF )
  {
    PhysicalAddress = v3[1].Misc.PhysicalAddress;
    ++v3[1].Misc.PhysicalAddress;
    HIBYTE(result) = PhysicalAddress;
    LOWORD(result) = -1;
    BYTE2(result) = -1;
    if ( net_write_buff(a1: 4u, a2: (int)v3, src: (unsigned __int8 *)&result)
      || net_write_buff(a1: 0xFFFFFFu, a2: (int)v3, src: i) )
    {
      return true;
    }
    v5 -= 0xFFFFFF;
  }
  v8 = v3[1].Misc.PhysicalAddress;
  ++v3[1].Misc.PhysicalAddress;
  BYTE2(result) = BYTE2(v5);
  LOWORD(result) = v5;
  HIBYTE(result) = v8;
  if ( net_write_buff(a1: 4u, a2: (int)v3, src: (unsigned __int8 *)&result) )
    return true;
  return net_write_buff(a1: v5, a2: (int)v3, src: i);
}

//------------------------------------------------------------------------------
// Address: 0x0040EF20
// Name: _net_write_command
// Source: json
//------------------------------------------------------------------------------
bool __cdecl net_write_command(
        int command,
        char a2,
        unsigned __int8 *header,
        unsigned int head_len,
        unsigned __int8 *packet,
        unsigned int len)
{
  unsigned int v6; // ebp
  unsigned int v7; // edi
  unsigned int v8; // ebx
  unsigned int v9; // eax
  unsigned int v10; // edi
  char v11; // cl
  char v12; // cl
  bool result; // al
  CCountedStringPoolBase<unsigned int>::<unnamed_tag> buff; // [esp+18h] [ebp-Ch] BYREF
  char v16; // [esp+1Ch] [ebp-8h]

  v6 = head_len;
  v7 = len;
  v8 = len + head_len + 1;
  v9 = 5;
  v16 = a2;
  if ( v8 >= 0xFFFFFF )
  {
    v10 = 16777214 - head_len;
    while ( 1 )
    {
      v11 = *(_BYTE *)(command + 48);
      ++*(_DWORD *)(command + 48);
      LOWORD(buff) = -1;
      BYTE2(buff) = -1;
      HIBYTE(buff) = v11;
      if ( net_write_buff(a1: v9, a2: command, src: (unsigned __int8 *)&buff)
        || net_write_buff(a1: v6, a2: command, src: header)
        || net_write_buff(a1: v10, a2: command, src: packet) )
      {
        return true;
      }
      packet += v10;
      v8 -= 0xFFFFFF;
      v10 = 0xFFFFFF;
      v6 = 0;
      v9 = 4;
      if ( v8 < 0xFFFFFF )
      {
        v7 = v8;
        break;
      }
    }
  }
  v12 = *(_BYTE *)(command + 48);
  ++*(_DWORD *)(command + 48);
  LOWORD(buff) = v8;
  BYTE2(buff) = BYTE2(v8);
  HIBYTE(buff) = v12;
  if ( net_write_buff(a1: v9, a2: command, src: (unsigned __int8 *)&buff)
    || v6 != 0 && net_write_buff(a1: v6, a2: command, src: header) )
  {
    return true;
  }
  if ( net_write_buff(a1: v7, a2: command, src: packet) )
    return true;
  result = net_flush(net: command);
  if ( result )
    return true;
  return result;
}
