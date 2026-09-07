// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/shared/cstrike15/bot/shared_util.cpp
// Functions: 4
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x101CE7B0
// Name: char __near * SharedVarArgs(char __near *,...)
// Source: json
//------------------------------------------------------------------------------
char *SharedVarArgs(char *format, ...)
{
  va_list ap; // [esp+Ch] [ebp+Ch] BYREF

  va_start(ap, format);
  curstring = (curstring + 1) % 4;
  _vsnprintf(string: string_1[curstring], count: 0x400u, format, ap);
  return string_1[curstring];
}

//------------------------------------------------------------------------------
// Address: 0x101CE800
// Name: char __near * BufPrintf(char __near *,int __near &,char const __near *,...)
// Source: json
//------------------------------------------------------------------------------
char *BufPrintf(char *buf, int *len, const char *fmt, ...)
{
  va_list ap; // [esp+18h] [ebp+14h] BYREF

  va_start(ap, fmt);
  if ( *len <= 0 )
    return nullptr;
  _vsnprintf(string: buf, count: *len, format: fmt, ap);
  *len -= strlen(buf);
  return &buf[strlen(buf)];
}

//------------------------------------------------------------------------------
// Address: 0x101CE850
// Name: char __near * SharedGetToken(void)
// Source: json
//------------------------------------------------------------------------------
char *__cdecl SharedGetToken()
{
  return s_shared_token;
}

//------------------------------------------------------------------------------
// Address: 0x101CE860
// Name: char const __near * SharedParse(char const __near *)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl SharedParse(const char *data)
{
  const char *result; // eax
  int v2; // esi
  int v3; // ecx
  int v4; // edx
  int v5; // ecx
  int v6; // edx

  result = data;
  v2 = 0;
  s_shared_token[0] = 0;
  if ( data != nullptr )
  {
    LOBYTE(v3) = *data;
    while ( 1 )
    {
      v3 = (char)v3;
      if ( (char)v3 <= 32 )
        break;
LABEL_7:
      if ( v3 != 47 || result[1] != 47 )
      {
        v4 = s_shared_quote;
        if ( v3 == s_shared_quote )
        {
          v5 = result[1];
          result += 2;
          if ( v5 != s_shared_quote )
          {
            do
            {
              if ( v5 == 0 )
                break;
              s_shared_token[v2] = v5;
              v5 = *result;
              ++v2;
              ++result;
            }
            while ( v5 != v4 );
          }
          s_shared_token[v2] = 0;
        }
        else if ( v3 == 123 || v3 == 125 || v3 == 41 || v3 == 40 || v3 == 39 || v3 == 44 )
        {
          s_shared_token[1] = 0;
          s_shared_token[0] = v3;
          ++result;
        }
        else
        {
          v6 = s_shared_token - result;
          do
          {
            result[v6] = v3;
            v3 = *++result;
            ++v2;
          }
          while ( v3 != 123 && v3 != 125 && v3 != 41 && v3 != 40 && v3 != 39 && v3 != 44 && v3 > 32 );
          s_shared_token[v2] = 0;
        }
        return result;
      }
      LOBYTE(v3) = *result;
      if ( *result != 0 )
      {
        do
        {
          if ( (_BYTE)v3 == 10 )
            break;
          LOBYTE(v3) = *++result;
        }
        while ( (_BYTE)v3 != 0 );
      }
    }
    while ( v3 != 0 )
    {
      v3 = *++result;
      if ( v3 > 32 )
        goto LABEL_7;
    }
  }
  return nullptr;
}

// ============================================================
// Overlay from server (Missing functions)
// ============================================================
namespace server {

//------------------------------------------------------------------------------
// Address: 0x102D06E0
// Name: char __near * SharedGetToken(void)
// Source: json
//------------------------------------------------------------------------------
char *__cdecl SharedGetToken()
{
  return s_shared_token;
}

//------------------------------------------------------------------------------
// Address: 0x102D06F0
// Name: char const __near * SharedParse(char const __near *)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl SharedParse(const char *data)
{
  const char *result; // eax
  int v2; // esi
  int v3; // ecx
  int v4; // edx
  int v5; // ecx
  int v6; // edx

  result = data;
  v2 = 0;
  s_shared_token[0] = 0;
  if ( data != nullptr )
  {
    LOBYTE(v3) = *data;
    while ( 1 )
    {
      v3 = (char)v3;
      if ( (char)v3 <= 32 )
        break;
LABEL_7:
      if ( v3 != 47 || result[1] != 47 )
      {
        v4 = s_shared_quote;
        if ( v3 == s_shared_quote )
        {
          v5 = result[1];
          result += 2;
          if ( v5 != s_shared_quote )
          {
            do
            {
              if ( v5 == 0 )
                break;
              s_shared_token[v2] = v5;
              v5 = *result;
              ++v2;
              ++result;
            }
            while ( v5 != v4 );
          }
          s_shared_token[v2] = 0;
        }
        else if ( v3 == 123 || v3 == 125 || v3 == 41 || v3 == 40 || v3 == 39 || v3 == 44 )
        {
          s_shared_token[1] = 0;
          s_shared_token[0] = v3;
          ++result;
        }
        else
        {
          v6 = s_shared_token - result;
          do
          {
            result[v6] = v3;
            v3 = *++result;
            ++v2;
          }
          while ( v3 != 123 && v3 != 125 && v3 != 41 && v3 != 40 && v3 != 39 && v3 != 44 && v3 > 32 );
          s_shared_token[v2] = 0;
        }
        return result;
      }
      LOBYTE(v3) = *result;
      if ( *result != 0 )
      {
        do
        {
          if ( (_BYTE)v3 == 10 )
            break;
          LOBYTE(v3) = *++result;
        }
        while ( (_BYTE)v3 != 0 );
      }
    }
    while ( v3 != 0 )
    {
      v3 = *++result;
      if ( v3 > 32 )
        goto LABEL_7;
    }
  }
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x102D07F0
// Name: __CreateCServerGameTagsIServerGameTags_interface_36
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CServerGameTags *__cdecl _CreateCServerGameTagsIServerGameTags_interface_36()
{
  return &_g_CServerGameTags_singleton_36;
}

} // namespace server
