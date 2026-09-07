// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/classcheck/classcheck_util.cpp
// Functions: 10
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x004058E0
// Name: void vprint(int,char const __near *,...)
// Source: json
//------------------------------------------------------------------------------
void vprint(int depth, char *fmt, ...)
{
  _iobuf *v2; // esi
  int v3; // edi
  char *i; // edi
  char string[8192]; // [esp+8h] [ebp-2000h] BYREF
  va_list ap; // [esp+2018h] [ebp+10h] BYREF

  va_start(ap, fmt);
  vsprintf(string, format: fmt, ap);
  v2 = nullptr;
  if ( processor->GetLogFile(this: processor) )
    v2 = fopen(file: "log.txt", mode: "ab");
  v3 = depth;
  while ( v3 > 0 )
  {
    --v3;
    printf(format: "  ");
    OutputDebugStringA(lpOutputString: "  ");
    if ( v2 != nullptr )
      fprintf(str: v2, format: "  ");
  }
  printf(format: string);
  OutputDebugStringA(lpOutputString: string);
  if ( v2 != nullptr )
  {
    for ( i = string; *i != 0; fputc(ch: *i++, str: v2) )
    {
      if ( *i == 10 )
        fputc(ch: 13, str: v2);
    }
    fclose(stream: v2);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004059D0
// Name: void CC_UngetToken(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CC_UngetToken()
{
  s_com_token_unget = true;
}

//------------------------------------------------------------------------------
// Address: 0x004059E0
// Name: bool CC_IsBreakChar(char)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl CC_IsBreakChar(char ch)
{
  bool result; // al

  result = false;
  switch ( ch )
  {
    case '\'':
    case '(':
    case ')':
    case ',':
    case '/':
    case ';':
    case '<':
    case '>':
    case '[':
    case ']':
    case '{':
    case '}':
      goto $LN4_0;
    case ':':
      if ( !com_ignorecolons )
$LN4_0:
        result = true;
      break;
    default:
      return result;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00405A70
// Name: char __near * CC_ParseToken(char __near *)
// Source: json
//------------------------------------------------------------------------------
char *__cdecl CC_ParseToken(char *data)
{
  char *result; // eax
  char *v2; // edx
  int v3; // esi
  int v4; // ebx
  char j; // al
  char i; // al
  char v7; // bl
  char *v8; // edx
  bool v9; // cl
  int v10; // eax
  bool v11; // cl

  if ( s_com_token_unget )
  {
    s_com_token_unget = false;
    return data;
  }
  v2 = data;
  v3 = 0;
  com_token[0] = 0;
  if ( data == nullptr )
    return nullptr;
  while ( 1 )
  {
    v4 = *v2;
    if ( v4 <= 32 )
      break;
LABEL_10:
    if ( com_ignoreinlinecomment )
    {
      if ( v4 != 47 )
        goto LABEL_30;
LABEL_18:
      if ( v2[1] != 42 )
      {
LABEL_30:
        if ( *v2 == 76 && (result = v2 + 1, v2[1] == 34) )
        {
          com_token[0] = v4;
        }
        else if ( v4 == 34 )
        {
          v8 = v2 + 1;
          v9 = false;
          do
          {
            v10 = *v8++;
            if ( v10 == 34 )
            {
              if ( !v9 )
                goto $LN3_0;
              v9 = false;
            }
            else
            {
              if ( v10 == 0 && (unsigned int)v3 < 0x3FF )
                goto $LN3_0;
              v9 = !v9 && v10 == 92;
            }
            com_token[v3++] = v10;
          }
          while ( v3 < 1024 );
          byte_42500F[v3] = 0;
          return v8;
        }
        else if ( CC_IsBreakChar(ch: v4) )
        {
          com_token[0] = v4;
          byte_425011 = 0;
          return v8 + 1;
        }
        else
        {
          v11 = com_ignorecolons;
          while ( 2 )
          {
            ++v8;
            com_token[v3] = v4;
            v4 = *v8;
            ++v3;
            switch ( (char)v4 )
            {
              case '\'':
              case '(':
              case ')':
              case ',':
              case '/':
              case ';':
              case '<':
              case '>':
              case '[':
              case ']':
              case '{':
              case '}':
                break;
              case ':':
                if ( v11 )
                  goto LABEL_50;
                break;
              default:
LABEL_50:
                if ( v4 > 32 && (unsigned int)v3 < 0x3FF )
                  continue;
                break;
            }
            break;
          }
$LN3_0:
          com_token[v3] = 0;
          return v8;
        }
        return result;
      }
      for ( i = *v2; i != 0; i = *++v2 )
      {
        v7 = v2[1];
        if ( v7 == 0 || i == 42 && v7 == 47 )
          break;
        if ( i == 10 )
          ++linesprocessed;
      }
      if ( *v2 == 42 && v2[1] == 47 )
        v2 += 2;
    }
    else
    {
      if ( v4 != 47 )
        goto LABEL_30;
      if ( v2[1] != 47 )
        goto LABEL_18;
      for ( j = *v2; j != 0; j = *++v2 )
      {
        if ( j == 10 )
          break;
      }
    }
  }
  while ( v4 != 0 )
  {
    if ( v4 == 10 )
      ++linesprocessed;
    v4 = *++v2;
    if ( v4 > 32 )
      goto LABEL_10;
  }
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x00405CA0
// Name: unsigned char __near * COM_LoadFile(char const __near *,int __near *)
// Source: json
//------------------------------------------------------------------------------
_iobuf *__cdecl COM_LoadFile(const char *name, int *len)
{
  _iobuf *result; // eax
  _iobuf *v3; // esi
  void *v4; // ebx

  result = fopen(file: name, mode: "rb");
  v3 = result;
  if ( result != nullptr )
  {
    fseek(stream: result, offset: 0, whence: 2);
    *len = ftell(stream: v3);
    fseek(stream: v3, offset: 0, whence: 0);
    v4 = operator new(nSize: *len + 1);
    fread(buffer: v4, elementSize: *len, count: 1u, stream: v3);
    fclose(stream: v3);
    *((_BYTE *)v4 + *len) = 0;
    return (_iobuf *)v4;
  }
  else
  {
    *len = 0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00405D20
// Name: void COM_FreeFile(unsigned char __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl COM_FreeFile(unsigned __int8 *buffer)
{
  free(pMem: buffer);
}

//------------------------------------------------------------------------------
// Address: 0x00405D30
// Name: bool COM_DirectoryExists(char const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl COM_DirectoryExists(const char *dir)
{
  return _access(path: dir, amode: 0) == 0;
}

//------------------------------------------------------------------------------
// Address: 0x00405D50
// Name: char __near * CC_ParseUntilEndOfLine(char __near *)
// Source: json
//------------------------------------------------------------------------------
char *__cdecl CC_ParseUntilEndOfLine(char *input)
{
  char *result; // eax
  char i; // cl

  result = input;
  for ( i = *input; i != 0; i = *++result )
  {
    if ( i == 10 )
      break;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00405D70
// Name: char __near * CC_RawParseChar(char __near *,char const __near *,char __near *)
// Source: json
//------------------------------------------------------------------------------
char *__cdecl CC_RawParseChar(char *input, const char *ch, char *breakchar)
{
  int v3; // edi
  char *result; // eax
  int v5; // esi
  int v6; // ecx
  char i; // cl
  char j; // cl
  char v9; // dl
  bool v10; // dl
  int v11; // ecx
  unsigned int v12; // kr00_4
  int v13; // ecx

  v3 = strlen(ch);
  result = input;
LABEL_2:
  while ( 2 )
  {
    if ( s_com_token_unget )
    {
      s_com_token_unget = false;
      goto LABEL_53;
    }
    v5 = 0;
    com_token[0] = 0;
    if ( result == nullptr )
      goto LABEL_5;
    while ( 1 )
    {
      while ( 1 )
      {
        v6 = *result;
        if ( v6 <= 32 )
        {
          while ( v6 != 0 )
          {
            if ( v6 == 10 )
              ++linesprocessed;
            v6 = *++result;
            if ( v6 > 32 )
              goto LABEL_11;
          }
LABEL_5:
          result = nullptr;
          goto LABEL_53;
        }
LABEL_11:
        if ( com_ignoreinlinecomment )
          break;
        if ( v6 != 47 )
          goto LABEL_30;
        if ( result[1] != 47 )
          goto LABEL_19;
        for ( i = *result; i != 0; i = *++result )
        {
          if ( i == 10 )
            break;
        }
      }
      if ( v6 != 47 )
        break;
LABEL_19:
      if ( result[1] != 42 )
        break;
      for ( j = *result; j != 0; j = *++result )
      {
        v9 = result[1];
        if ( v9 == 0 || j == 42 && v9 == 47 )
          break;
        if ( j == 10 )
          ++linesprocessed;
      }
      if ( *result == 42 && result[1] == 47 )
        result += 2;
    }
LABEL_30:
    if ( *result == 76 && result[1] == 34 )
    {
      com_token[0] = v6;
      ++result;
      goto LABEL_53;
    }
    if ( v6 != 34 )
    {
      switch ( (char)v6 )
      {
        case '\'':
        case '(':
        case ')':
        case ',':
        case '/':
        case ';':
        case '<':
        case '>':
        case '[':
        case ']':
        case '{':
        case '}':
          goto $LN93;
        case ':':
          if ( com_ignorecolons )
            goto LABEL_48;
$LN93:
          com_token[0] = v6;
          byte_425011 = 0;
          ++result;
          goto LABEL_53;
        default:
LABEL_48:
          while ( 2 )
          {
            ++result;
            com_token[v5] = v6;
            v6 = *result;
            ++v5;
            switch ( (char)v6 )
            {
              case '\'':
              case '(':
              case ')':
              case ',':
              case '/':
              case ';':
              case '<':
              case '>':
              case '[':
              case ']':
              case '{':
              case '}':
                goto $LN14;
              case ':':
                if ( com_ignorecolons )
                  goto LABEL_50;
                break;
              default:
LABEL_50:
                if ( v6 > 32 && (unsigned int)v5 < 0x3FF )
                  continue;
                break;
            }
            goto $LN14;
          }
      }
    }
    ++result;
    v10 = false;
    while ( 2 )
    {
      v11 = *result++;
      if ( v11 == 34 )
      {
        if ( !v10 )
          break;
        v10 = false;
        goto LABEL_43;
      }
      if ( v11 != 0 || (unsigned int)v5 >= 0x3FF )
      {
        v10 = !v10 && v11 == 92;
LABEL_43:
        com_token[v5++] = v11;
        if ( v5 >= 1024 )
        {
          byte_42500F[v5] = 0;
          goto LABEL_53;
        }
        continue;
      }
      break;
    }
$LN14:
    com_token[v5] = 0;
LABEL_53:
    v12 = strlen(com_token);
    if ( v12 != 0 )
    {
      if ( v12 == 1 )
      {
        v13 = 0;
        if ( v3 > 0 )
        {
          while ( com_token[0] != ch[v13] )
          {
            if ( ++v13 >= v3 )
              goto LABEL_2;
          }
          *breakchar = ch[v13];
          return result;
        }
      }
      continue;
    }
    return result;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00406050
// Name: char __near * CC_DiscardUntilMatchingCharIncludingNesting(char __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
char *__cdecl CC_DiscardUntilMatchingCharIncludingNesting(char *input, const char *pairing)
{
  char *result; // eax
  int v3; // esi
  int v4; // ecx
  char j; // cl
  char i; // cl
  char v7; // dl
  bool v8; // dl
  int v9; // ecx
  unsigned int v10; // kr00_4
  int nestcount; // [esp+Ch] [ebp-4h]

  result = input;
  nestcount = 1;
  do
  {
    if ( s_com_token_unget )
    {
      s_com_token_unget = false;
      goto LABEL_53;
    }
    v3 = 0;
    com_token[0] = 0;
    if ( result == nullptr )
      goto LABEL_5;
    while ( 1 )
    {
      v4 = *result;
      if ( v4 <= 32 )
        break;
LABEL_11:
      if ( com_ignoreinlinecomment )
      {
        if ( v4 != 47 )
          goto LABEL_30;
LABEL_19:
        if ( result[1] != 42 )
        {
LABEL_30:
          if ( *result != 76 || result[1] != 34 )
          {
            if ( v4 != 34 )
            {
              switch ( (char)v4 )
              {
                case '\'':
                case '(':
                case ')':
                case ',':
                case '/':
                case ';':
                case '<':
                case '>':
                case '[':
                case ']':
                case '{':
                case '}':
                  goto $LN88;
                case ':':
                  if ( com_ignorecolons )
                    goto LABEL_48;
$LN88:
                  com_token[0] = v4;
                  byte_425011 = 0;
                  ++result;
                  goto LABEL_53;
                default:
LABEL_48:
                  while ( 2 )
                  {
                    ++result;
                    com_token[v3] = v4;
                    v4 = *result;
                    ++v3;
                    switch ( (char)v4 )
                    {
                      case '\'':
                      case '(':
                      case ')':
                      case ',':
                      case '/':
                      case ';':
                      case '<':
                      case '>':
                      case '[':
                      case ']':
                      case '{':
                      case '}':
                        goto $LN13_0;
                      case ':':
                        if ( com_ignorecolons )
                          goto LABEL_50;
                        break;
                      default:
LABEL_50:
                        if ( v4 > 32 && (unsigned int)v3 < 0x3FF )
                          continue;
                        break;
                    }
                    goto $LN13_0;
                  }
              }
            }
            ++result;
            v8 = false;
            while ( 1 )
            {
              v9 = *result++;
              if ( v9 == 34 )
              {
                if ( !v8 )
                  goto $LN13_0;
                v8 = false;
              }
              else
              {
                if ( v9 == 0 && (unsigned int)v3 < 0x3FF )
                {
$LN13_0:
                  com_token[v3] = 0;
                  goto LABEL_53;
                }
                v8 = !v8 && v9 == 92;
              }
              com_token[v3++] = v9;
              if ( v3 >= 1024 )
              {
                byte_42500F[v3] = 0;
                goto LABEL_53;
              }
            }
          }
          com_token[0] = v4;
          ++result;
          goto LABEL_53;
        }
        for ( i = *result; i != 0; i = *++result )
        {
          v7 = result[1];
          if ( v7 == 0 || i == 42 && v7 == 47 )
            break;
          if ( i == 10 )
            ++linesprocessed;
        }
        if ( *result == 42 && result[1] == 47 )
          result += 2;
      }
      else
      {
        if ( v4 != 47 )
          goto LABEL_30;
        if ( result[1] != 47 )
          goto LABEL_19;
        for ( j = *result; j != 0; j = *++result )
        {
          if ( j == 10 )
            break;
        }
      }
    }
    while ( v4 != 0 )
    {
      if ( v4 == 10 )
        ++linesprocessed;
      v4 = *++result;
      if ( v4 > 32 )
        goto LABEL_11;
    }
LABEL_5:
    result = nullptr;
LABEL_53:
    v10 = strlen(com_token);
    if ( v10 == 0 )
      break;
    if ( v10 == 1 )
    {
      if ( com_token[0] == *pairing )
      {
        ++nestcount;
      }
      else if ( com_token[0] == pairing[1] )
      {
        --nestcount;
      }
    }
  }
  while ( nestcount != 0 );
  return result;
}
