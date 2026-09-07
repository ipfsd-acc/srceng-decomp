// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: mysql-connector-c-6.0.2/libmysql/password.c
// Functions: 4
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x0040F080
// Name: _hash_password
// Source: json
//------------------------------------------------------------------------------
int __cdecl hash_password(int *a1, unsigned __int8 *a2, int a3)
{
  unsigned __int8 *v3; // esi
  unsigned int v4; // ebx
  int v5; // eax
  int v6; // edi
  int v7; // edx
  unsigned __int8 v8; // cl
  int result; // eax
  unsigned int i; // [esp+14h] [ebp+8h]

  v3 = a2;
  v4 = (unsigned int)&a2[a3];
  v5 = 1345345333;
  v6 = 7;
  v7 = 305419889;
  for ( i = v4; (unsigned int)v3 < v4; ++v3 )
  {
    v8 = *v3;
    if ( *v3 != 32 && v8 != 9 )
    {
      v5 ^= (v5 << 8) + v8 * (v6 + (v5 & 0x3F));
      v7 += v5 ^ (v7 << 8);
      v4 = i;
      v6 += v8;
    }
  }
  result = v5 & 0x7FFFFFFF;
  *a1 = result;
  a1[1] = v7 & 0x7FFFFFFF;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0040F100
// Name: _scramble_323
// Source: json
//------------------------------------------------------------------------------
void __cdecl scramble_323(char *to, unsigned __int8 *message, unsigned __int8 *password)
{
  unsigned __int8 *v3; // edi
  char *v4; // esi
  __int32 v5; // ebx
  double v6; // st7
  double v7; // st7
  int v8; // eax
  int v9[2]; // [esp+1Ch] [ebp-2Ch] BYREF
  tagShutdownType message_end; // [esp+24h] [ebp-24h]
  int v11[2]; // [esp+28h] [ebp-20h] BYREF
  _BYTE v12[24]; // [esp+30h] [ebp-18h] BYREF

  if ( password != nullptr )
  {
    if ( *password != 0 )
    {
      v3 = (unsigned __int8 *)to;
      message_end = (tagShutdownType)(message + 8);
      v4 = to;
      v9[0] = (int)(password + 1);
      hash_password(a1: v11, a2: password, a3: strlen((const char *)password));
      hash_password(a1: v9, a2: message, a3: 8);
      my_rnd_init(a1: v12, a2: v11[0] ^ v9[0], a3: v11[1] ^ v9[1]);
      if ( (unsigned int)message < message_end )
      {
        v5 = message_end - (_DWORD)message;
        do
        {
          v6 = my_rnd(a1: v12);
          *v3++ = (int)(floor(X: v6 * 31.0) + 64.0);
          --v5;
        }
        while ( v5 != 0 );
      }
      v7 = my_rnd(a1: v12);
      v8 = (int)floor(X: v7 * 31.0);
      if ( to != (char *)v3 )
      {
        do
          *v4++ ^= v8;
        while ( v4 != (char *)v3 );
      }
      *v3 = 0;
    }
    else
    {
      *to = 0;
    }
  }
  else
  {
    *to = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040F210
// Name: my_crypt
// Source: json
//------------------------------------------------------------------------------
_BYTE *__usercall my_crypt@<eax>(_BYTE *result@<eax>, int a2@<edx>, _BYTE *a3@<ecx>, _BYTE *a4)
{
  _BYTE *i; // edi
  char v6; // dl

  for ( i = &result[a2]; result < i; ++a4 )
  {
    v6 = *a4 ^ *result++;
    *a3++ = v6;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0040F230
// Name: _scramble
// Source: json
//------------------------------------------------------------------------------
_BYTE *__cdecl scramble(char *to, tagShutdownType message, const char *password)
{
  _BYTE v4[104]; // [esp+Ch] [ebp-94h] BYREF
  _BYTE v5[20]; // [esp+74h] [ebp-2Ch] BYREF
  _BYTE v6[20]; // [esp+88h] [ebp-18h] BYREF

  mysql_sha1_reset(a1: v4);
  mysql_sha1_input(a1: v4, a2: password, a3: strlen(password));
  mysql_sha1_result(a1: v4, a2: v5);
  mysql_sha1_reset(a1: v4);
  mysql_sha1_input(a1: v4, a2: v5, a3: 20);
  mysql_sha1_result(a1: v4, a2: v6);
  mysql_sha1_reset(a1: v4);
  mysql_sha1_input(a1: v4, a2: message, a3: 20);
  mysql_sha1_input(a1: v4, a2: v6, a3: 20);
  mysql_sha1_result(a1: v4, a2: to);
  return my_crypt(result: to, a2: 20, a3: to, a4: v5);
}
