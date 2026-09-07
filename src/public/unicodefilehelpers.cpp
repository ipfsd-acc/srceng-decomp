// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: public/unicodefilehelpers.cpp
// Functions: 5
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x0041A720
// Name: wchar_t __near * ReadUnicodeToken(wchar_t __near *,wchar_t __near *,int,bool __near &)
// Source: json
//------------------------------------------------------------------------------
wchar_t *__cdecl ReadUnicodeToken(wchar_t *start, wchar_t *token, int tokenBufferSize, bool *quoted)
{
  wchar_t *i; // esi
  wchar_t *v5; // edi
  int v6; // edx
  int v7; // eax
  unsigned __int16 j; // ax
  int v9; // ecx
  int v11; // ebx

  for ( i = start; *i != 0; ++i )
  {
    if ( iswspace(c: *i) == 0 )
      break;
  }
  v5 = token;
  v6 = 0;
  *quoted = false;
  *token = 0;
  v7 = *i;
  if ( (_WORD)v7 != 0 )
  {
    if ( v7 == 34 )
    {
      ++i;
      *quoted = true;
      for ( j = *i; j != 0; ++v6 )
      {
        if ( j == 34 )
          goto LABEL_15;
        if ( v6 >= tokenBufferSize - 1 )
          break;
        if ( j == 92 )
        {
          v9 = i[1];
          if ( v9 == 110 )
          {
            ++i;
            j = 10;
          }
          else if ( v9 == 34 )
          {
            ++i;
            *v5 = 34;
            goto LABEL_13;
          }
        }
        *v5 = j;
LABEL_13:
        j = i[1];
        ++i;
        ++v5;
      }
      if ( *i == 34 )
      {
LABEL_15:
        *v5 = 0;
        return i + 1;
      }
    }
    else
    {
      v11 = 0;
      do
      {
        if ( iswspace(c: *i) != 0 )
          break;
        if ( v11 >= tokenBufferSize - 1 )
          break;
        *v5++ = *i++;
        ++v11;
      }
      while ( *i != 0 );
    }
    *v5 = 0;
  }
  return i;
}

//------------------------------------------------------------------------------
// Address: 0x0041A820
// Name: wchar_t __near * ReadUnicodeTokenNoSpecial(wchar_t __near *,wchar_t __near *,int,bool __near &)
// Source: json
//------------------------------------------------------------------------------
wchar_t *__cdecl ReadUnicodeTokenNoSpecial(wchar_t *start, wchar_t *token, int tokenBufferSize, bool *quoted)
{
  wchar_t *i; // esi
  wchar_t *v5; // edi
  int v6; // eax
  __int16 v7; // ax
  int v8; // ecx
  int v10; // ebx

  for ( i = start; *i != 0; ++i )
  {
    if ( iswspace(c: *i) == 0 )
      break;
  }
  v5 = token;
  *quoted = false;
  *token = 0;
  v6 = *i;
  if ( (_WORD)v6 != 0 )
  {
    if ( v6 == 34 )
    {
      ++i;
      *quoted = true;
      v7 = *i;
      v8 = 0;
      if ( *i != 0 )
      {
        while ( v7 != 34 )
        {
          if ( v8 < tokenBufferSize - 1 )
          {
            if ( v7 == 92 && i[1] == 34 )
            {
              ++i;
              v7 = 34;
            }
            ++i;
            *v5 = v7;
            v7 = *i;
            ++v5;
            ++v8;
            if ( *i != 0 )
              continue;
          }
          goto LABEL_13;
        }
        goto LABEL_14;
      }
LABEL_13:
      if ( *i == 34 )
      {
LABEL_14:
        *v5 = 0;
        return i + 1;
      }
    }
    else
    {
      v10 = 0;
      do
      {
        if ( iswspace(c: *i) != 0 )
          break;
        if ( v10 >= tokenBufferSize - 1 )
          break;
        *v5++ = *i++;
        ++v10;
      }
      while ( *i != 0 );
    }
    *v5 = 0;
  }
  return i;
}

//------------------------------------------------------------------------------
// Address: 0x0041A910
// Name: wchar_t __near * ReadToEndOfLine(wchar_t __near *)
// Source: json
//------------------------------------------------------------------------------
wchar_t *__cdecl ReadToEndOfLine(wchar_t *start)
{
  wchar_t *result; // eax
  wchar_t v2; // cx
  int v3; // ecx

  result = start;
  v2 = *start;
  if ( *start != 0 )
  {
    do
    {
      if ( v2 == 13 )
        goto LABEL_7;
      if ( v2 == 10 )
        break;
      v2 = result[1];
      ++result;
    }
    while ( v2 != 0 );
    while ( 1 )
    {
      v3 = *result;
      if ( v3 != 13 && v3 != 10 )
        break;
LABEL_7:
      ++result;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0041A950
// Name: void WriteUnicodeString(class CUtlBuffer __near &,wchar_t const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl WriteUnicodeString(CUtlBuffer *buf, const wchar_t *string, int addQuotes)
{
  const wchar_t *i; // ebx
  wchar_t v4; // di

  if ( (_BYTE)addQuotes != 0 )
  {
    if ( (buf->m_Flags & 1) != 0 )
      CUtlBuffer::Printf(this: buf, pFmt: "%hu", 34);
    else
      CUtlBuffer::PutTypeBin<unsigned short>(this: buf, src: 0x22u);
  }
  for ( i = string; *i != 0; ++i )
  {
    if ( (_BYTE)addQuotes != 0 && *i == 34 )
    {
      if ( (buf->m_Flags & 1) != 0 )
        CUtlBuffer::Printf(this: buf, pFmt: "%hu", 92);
      else
        CUtlBuffer::PutTypeBin<unsigned short>(this: buf, src: 0x5Cu);
    }
    v4 = *i;
    if ( (buf->m_Flags & 1) != 0 )
    {
      CUtlBuffer::Printf(this: buf, pFmt: "%hu", *i);
    }
    else
    {
      string = (const wchar_t *)*i;
      if ( CUtlBuffer::CheckPut(this: buf, nSize: 2) )
      {
        if ( (*(_BYTE *)&buf->m_Byteswap & 1) != 0 )
          CByteswap::SwapBufferToTargetEndian<unsigned short>(
            this: &buf->m_Byteswap,
            outputBuffer: &buf->m_Memory.m_pMemory[buf->m_Put - buf->m_nOffset],
            inputBuffer: (unsigned __int8 *)&string,
            count: 1);
        else
          *(_WORD *)&buf->m_Memory.m_pMemory[buf->m_Put - buf->m_nOffset] = v4;
        buf->m_Put += 2;
        CUtlBuffer::AddNullTermination(this: buf, nPut: buf->m_Put);
      }
    }
  }
  if ( (_BYTE)addQuotes != 0 )
  {
    if ( (buf->m_Flags & 1) != 0 )
    {
      CUtlBuffer::Printf(this: buf, pFmt: "%hu", 34);
    }
    else
    {
      addQuotes = 34;
      if ( CUtlBuffer::CheckPut(this: buf, nSize: 2) )
      {
        if ( (*(_BYTE *)&buf->m_Byteswap & 1) != 0 )
          CByteswap::SwapBufferToTargetEndian<unsigned short>(
            this: &buf->m_Byteswap,
            outputBuffer: &buf->m_Memory.m_pMemory[buf->m_Put - buf->m_nOffset],
            inputBuffer: (unsigned __int8 *)&addQuotes,
            count: 1);
        else
          *(_WORD *)&buf->m_Memory.m_pMemory[buf->m_Put - buf->m_nOffset] = 34;
        buf->m_Put += 2;
        CUtlBuffer::AddNullTermination(this: buf, nPut: buf->m_Put);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041AAD0
// Name: void WriteAsciiStringAsUnicode(class CUtlBuffer __near &,char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl WriteAsciiStringAsUnicode(CUtlBuffer *buf, const char *string, int addQuotes)
{
  const char *i; // ebx
  unsigned __int16 v4; // ax
  unsigned __int16 v5; // di

  if ( (_BYTE)addQuotes != 0 )
  {
    if ( (buf->m_Flags & 1) != 0 )
      CUtlBuffer::Printf(this: buf, pFmt: "%hu", 34);
    else
      CUtlBuffer::PutTypeBin<unsigned short>(this: buf, src: 0x22u);
  }
  for ( i = string; *i != 0; ++i )
  {
    if ( (_BYTE)addQuotes != 0 && *i == 34 )
    {
      if ( (buf->m_Flags & 1) != 0 )
        CUtlBuffer::Printf(this: buf, pFmt: "%hu", 92);
      else
        CUtlBuffer::PutTypeBin<unsigned short>(this: buf, src: 0x5Cu);
    }
    v4 = *i;
    v5 = v4;
    if ( (buf->m_Flags & 1) != 0 )
    {
      CUtlBuffer::Printf(this: buf, pFmt: "%hu", v4);
    }
    else
    {
      string = (const char *)v4;
      if ( CUtlBuffer::CheckPut(this: buf, nSize: 2) )
      {
        if ( (*(_BYTE *)&buf->m_Byteswap & 1) != 0 )
          CByteswap::SwapBufferToTargetEndian<unsigned short>(
            this: &buf->m_Byteswap,
            outputBuffer: &buf->m_Memory.m_pMemory[buf->m_Put - buf->m_nOffset],
            inputBuffer: (unsigned __int8 *)&string,
            count: 1);
        else
          *(_WORD *)&buf->m_Memory.m_pMemory[buf->m_Put - buf->m_nOffset] = v5;
        buf->m_Put += 2;
        CUtlBuffer::AddNullTermination(this: buf, nPut: buf->m_Put);
      }
    }
  }
  if ( (_BYTE)addQuotes != 0 )
  {
    if ( (buf->m_Flags & 1) != 0 )
    {
      CUtlBuffer::Printf(this: buf, pFmt: "%hu", 34);
    }
    else
    {
      addQuotes = 34;
      if ( CUtlBuffer::CheckPut(this: buf, nSize: 2) )
      {
        if ( (*(_BYTE *)&buf->m_Byteswap & 1) != 0 )
          CByteswap::SwapBufferToTargetEndian<unsigned short>(
            this: &buf->m_Byteswap,
            outputBuffer: &buf->m_Memory.m_pMemory[buf->m_Put - buf->m_nOffset],
            inputBuffer: (unsigned __int8 *)&addQuotes,
            count: 1);
        else
          *(_WORD *)&buf->m_Memory.m_pMemory[buf->m_Put - buf->m_nOffset] = 34;
        buf->m_Put += 2;
        CUtlBuffer::AddNullTermination(this: buf, nPut: buf->m_Put);
      }
    }
  }
}

// ============================================================
// Overlay from localize (Missing functions)
// ============================================================
namespace localize {

//------------------------------------------------------------------------------
// Address: 0x100055D0
// Name: wchar_t __near * ReadUnicodeToken(wchar_t __near *,wchar_t __near *,int,bool __near &)
// Source: json
//------------------------------------------------------------------------------
wchar_t *__cdecl ReadUnicodeToken(wchar_t *start, wchar_t *token, int tokenBufferSize, bool *quoted)
{
  wchar_t *i; // esi
  wchar_t *v5; // edi
  int v6; // edx
  int v7; // eax
  unsigned __int16 j; // ax
  int v9; // ecx
  int v11; // ebx

  for ( i = start; *i != 0; ++i )
  {
    if ( iswspace(c: *i) == 0 )
      break;
  }
  v5 = token;
  v6 = 0;
  *quoted = false;
  *token = 0;
  v7 = *i;
  if ( (_WORD)v7 != 0 )
  {
    if ( v7 == 34 )
    {
      ++i;
      *quoted = true;
      for ( j = *i; j != 0; ++v6 )
      {
        if ( j == 34 )
          goto LABEL_15;
        if ( v6 >= tokenBufferSize - 1 )
          break;
        if ( j == 92 )
        {
          v9 = i[1];
          if ( v9 == 110 )
          {
            ++i;
            j = 10;
          }
          else if ( v9 == 34 )
          {
            ++i;
            *v5 = 34;
            goto LABEL_13;
          }
        }
        *v5 = j;
LABEL_13:
        j = i[1];
        ++i;
        ++v5;
      }
      if ( *i == 34 )
      {
LABEL_15:
        *v5 = 0;
        return i + 1;
      }
    }
    else
    {
      v11 = 0;
      do
      {
        if ( iswspace(c: *i) != 0 )
          break;
        if ( v11 >= tokenBufferSize - 1 )
          break;
        *v5++ = *i++;
        ++v11;
      }
      while ( *i != 0 );
    }
    *v5 = 0;
  }
  return i;
}

//------------------------------------------------------------------------------
// Address: 0x100056D0
// Name: wchar_t __near * ReadToEndOfLine(wchar_t __near *)
// Source: json
//------------------------------------------------------------------------------
wchar_t *__cdecl ReadToEndOfLine(wchar_t *start)
{
  wchar_t *result; // eax
  wchar_t v2; // cx
  int v3; // ecx

  result = start;
  v2 = *start;
  if ( *start != 0 )
  {
    do
    {
      if ( v2 == 13 )
        goto LABEL_7;
      if ( v2 == 10 )
        break;
      v2 = result[1];
      ++result;
    }
    while ( v2 != 0 );
    while ( 1 )
    {
      v3 = *result;
      if ( v3 != 13 && v3 != 10 )
        break;
LABEL_7:
      ++result;
    }
  }
  return result;
}

} // namespace localize

// ============================================================
// Overlay from makegamedata (Missing functions)
// ============================================================
namespace makegamedata {

//------------------------------------------------------------------------------
// Address: 0x0042C730
// Name: wchar_t __near * ReadUnicodeToken(wchar_t __near *,wchar_t __near *,int,bool __near &)
// Source: json
//------------------------------------------------------------------------------
wchar_t *__cdecl ReadUnicodeToken(wchar_t *start, wchar_t *token, int tokenBufferSize, bool *quoted)
{
  wchar_t *i; // esi
  wchar_t *v5; // edi
  int v6; // edx
  int v7; // eax
  unsigned __int16 j; // ax
  int v9; // ecx
  int v11; // ebx

  for ( i = start; *i != 0; ++i )
  {
    if ( iswspace(c: *i) == 0 )
      break;
  }
  v5 = token;
  v6 = 0;
  *quoted = false;
  *token = 0;
  v7 = *i;
  if ( (_WORD)v7 != 0 )
  {
    if ( v7 == 34 )
    {
      ++i;
      *quoted = true;
      for ( j = *i; j != 0; ++v6 )
      {
        if ( j == 34 )
          goto LABEL_15;
        if ( v6 >= tokenBufferSize - 1 )
          break;
        if ( j == 92 )
        {
          v9 = i[1];
          if ( v9 == 110 )
          {
            ++i;
            j = 10;
          }
          else if ( v9 == 34 )
          {
            ++i;
            *v5 = 34;
            goto LABEL_13;
          }
        }
        *v5 = j;
LABEL_13:
        j = i[1];
        ++i;
        ++v5;
      }
      if ( *i == 34 )
      {
LABEL_15:
        *v5 = 0;
        return i + 1;
      }
    }
    else
    {
      v11 = 0;
      do
      {
        if ( iswspace(c: *i) != 0 )
          break;
        if ( v11 >= tokenBufferSize - 1 )
          break;
        *v5++ = *i++;
        ++v11;
      }
      while ( *i != 0 );
    }
    *v5 = 0;
  }
  return i;
}

//------------------------------------------------------------------------------
// Address: 0x0042C830
// Name: wchar_t __near * ReadUnicodeTokenNoSpecial(wchar_t __near *,wchar_t __near *,int,bool __near &)
// Source: json
//------------------------------------------------------------------------------
wchar_t *__cdecl ReadUnicodeTokenNoSpecial(wchar_t *start, wchar_t *token, int tokenBufferSize, bool *quoted)
{
  wchar_t *i; // esi
  wchar_t *v5; // edi
  int v6; // eax
  __int16 v7; // ax
  int v8; // ecx
  int v10; // ebx

  for ( i = start; *i != 0; ++i )
  {
    if ( iswspace(c: *i) == 0 )
      break;
  }
  v5 = token;
  *quoted = false;
  *token = 0;
  v6 = *i;
  if ( (_WORD)v6 != 0 )
  {
    if ( v6 == 34 )
    {
      ++i;
      *quoted = true;
      v7 = *i;
      v8 = 0;
      if ( *i != 0 )
      {
        while ( v7 != 34 )
        {
          if ( v8 < tokenBufferSize - 1 )
          {
            if ( v7 == 92 && i[1] == 34 )
            {
              ++i;
              v7 = 34;
            }
            ++i;
            *v5 = v7;
            v7 = *i;
            ++v5;
            ++v8;
            if ( *i != 0 )
              continue;
          }
          goto LABEL_13;
        }
        goto LABEL_14;
      }
LABEL_13:
      if ( *i == 34 )
      {
LABEL_14:
        *v5 = 0;
        return i + 1;
      }
    }
    else
    {
      v10 = 0;
      do
      {
        if ( iswspace(c: *i) != 0 )
          break;
        if ( v10 >= tokenBufferSize - 1 )
          break;
        *v5++ = *i++;
        ++v10;
      }
      while ( *i != 0 );
    }
    *v5 = 0;
  }
  return i;
}

//------------------------------------------------------------------------------
// Address: 0x0042C920
// Name: wchar_t __near * ReadToEndOfLine(wchar_t __near *)
// Source: json
//------------------------------------------------------------------------------
wchar_t *__cdecl ReadToEndOfLine(wchar_t *start)
{
  wchar_t *result; // eax
  wchar_t v2; // cx
  int v3; // ecx

  result = start;
  v2 = *start;
  if ( *start != 0 )
  {
    do
    {
      if ( v2 == 13 )
        goto LABEL_7;
      if ( v2 == 10 )
        break;
      v2 = result[1];
      ++result;
    }
    while ( v2 != 0 );
    while ( 1 )
    {
      v3 = *result;
      if ( v3 != 13 && v3 != 10 )
        break;
LABEL_7:
      ++result;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0042C960
// Name: void WriteUnicodeString(class CUtlBuffer __near &,wchar_t const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl WriteUnicodeString(CUtlBuffer *buf, const wchar_t *string, int addQuotes)
{
  const wchar_t *i; // ebx
  wchar_t v4; // di

  if ( (_BYTE)addQuotes != 0 )
  {
    if ( (buf->m_Flags & 1) != 0 )
      CUtlBuffer::Printf(this: buf, pFmt: "%hu", 34);
    else
      CUtlBuffer::PutTypeBin<short>(this: buf, src: 0x22u);
  }
  for ( i = string; *i != 0; ++i )
  {
    if ( (_BYTE)addQuotes != 0 && *i == 34 )
    {
      if ( (buf->m_Flags & 1) != 0 )
        CUtlBuffer::Printf(this: buf, pFmt: "%hu", 92);
      else
        CUtlBuffer::PutTypeBin<short>(this: buf, src: 0x5Cu);
    }
    v4 = *i;
    if ( (buf->m_Flags & 1) != 0 )
    {
      CUtlBuffer::Printf(this: buf, pFmt: "%hu", *i);
    }
    else
    {
      string = (const wchar_t *)*i;
      if ( CUtlBuffer::CheckPut(this: buf, nSize: 2) )
      {
        if ( (*(_BYTE *)&buf->m_Byteswap & 1) != 0 )
          CByteswap::SwapBufferToTargetEndian<unsigned short>(
            this: &buf->m_Byteswap,
            outputBuffer: &buf->m_Memory.m_pMemory[buf->m_Put - buf->m_nOffset],
            inputBuffer: (unsigned __int8 *)&string,
            count: 1);
        else
          *(_WORD *)&buf->m_Memory.m_pMemory[buf->m_Put - buf->m_nOffset] = v4;
        buf->m_Put += 2;
        CUtlBuffer::AddNullTermination(this: buf, nPut: buf->m_Put);
      }
    }
  }
  if ( (_BYTE)addQuotes != 0 )
  {
    if ( (buf->m_Flags & 1) != 0 )
    {
      CUtlBuffer::Printf(this: buf, pFmt: "%hu", 34);
    }
    else
    {
      addQuotes = 34;
      if ( CUtlBuffer::CheckPut(this: buf, nSize: 2) )
      {
        if ( (*(_BYTE *)&buf->m_Byteswap & 1) != 0 )
          CByteswap::SwapBufferToTargetEndian<unsigned short>(
            this: &buf->m_Byteswap,
            outputBuffer: &buf->m_Memory.m_pMemory[buf->m_Put - buf->m_nOffset],
            inputBuffer: (unsigned __int8 *)&addQuotes,
            count: 1);
        else
          *(_WORD *)&buf->m_Memory.m_pMemory[buf->m_Put - buf->m_nOffset] = 34;
        buf->m_Put += 2;
        CUtlBuffer::AddNullTermination(this: buf, nPut: buf->m_Put);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0042CAE0
// Name: void WriteAsciiStringAsUnicode(class CUtlBuffer __near &,char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl WriteAsciiStringAsUnicode(CUtlBuffer *buf, const char *string, int addQuotes)
{
  const char *i; // ebx
  unsigned __int16 v4; // ax
  unsigned __int16 v5; // di

  if ( (_BYTE)addQuotes != 0 )
  {
    if ( (buf->m_Flags & 1) != 0 )
      CUtlBuffer::Printf(this: buf, pFmt: "%hu", 34);
    else
      CUtlBuffer::PutTypeBin<short>(this: buf, src: 0x22u);
  }
  for ( i = string; *i != 0; ++i )
  {
    if ( (_BYTE)addQuotes != 0 && *i == 34 )
    {
      if ( (buf->m_Flags & 1) != 0 )
        CUtlBuffer::Printf(this: buf, pFmt: "%hu", 92);
      else
        CUtlBuffer::PutTypeBin<short>(this: buf, src: 0x5Cu);
    }
    v4 = *i;
    v5 = v4;
    if ( (buf->m_Flags & 1) != 0 )
    {
      CUtlBuffer::Printf(this: buf, pFmt: "%hu", v4);
    }
    else
    {
      string = (const char *)v4;
      if ( CUtlBuffer::CheckPut(this: buf, nSize: 2) )
      {
        if ( (*(_BYTE *)&buf->m_Byteswap & 1) != 0 )
          CByteswap::SwapBufferToTargetEndian<unsigned short>(
            this: &buf->m_Byteswap,
            outputBuffer: &buf->m_Memory.m_pMemory[buf->m_Put - buf->m_nOffset],
            inputBuffer: (unsigned __int8 *)&string,
            count: 1);
        else
          *(_WORD *)&buf->m_Memory.m_pMemory[buf->m_Put - buf->m_nOffset] = v5;
        buf->m_Put += 2;
        CUtlBuffer::AddNullTermination(this: buf, nPut: buf->m_Put);
      }
    }
  }
  if ( (_BYTE)addQuotes != 0 )
  {
    if ( (buf->m_Flags & 1) != 0 )
    {
      CUtlBuffer::Printf(this: buf, pFmt: "%hu", 34);
    }
    else
    {
      addQuotes = 34;
      if ( CUtlBuffer::CheckPut(this: buf, nSize: 2) )
      {
        if ( (*(_BYTE *)&buf->m_Byteswap & 1) != 0 )
          CByteswap::SwapBufferToTargetEndian<unsigned short>(
            this: &buf->m_Byteswap,
            outputBuffer: &buf->m_Memory.m_pMemory[buf->m_Put - buf->m_nOffset],
            inputBuffer: (unsigned __int8 *)&addQuotes,
            count: 1);
        else
          *(_WORD *)&buf->m_Memory.m_pMemory[buf->m_Put - buf->m_nOffset] = 34;
        buf->m_Put += 2;
        CUtlBuffer::AddNullTermination(this: buf, nPut: buf->m_Put);
      }
    }
  }
}

} // namespace makegamedata
