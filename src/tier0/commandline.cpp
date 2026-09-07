// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: tier0/commandline.cpp
// Functions: 19
// ============================================================

#include "tier0\commandline.h"

//------------------------------------------------------------------------------
// Address: 0x10001B90
// Name: char __near * MemAlloc_StrDup(char const __near *)
// Source: json
//------------------------------------------------------------------------------
char *__cdecl MemAlloc_StrDup(const char *pString)
{
  char *result; // eax

  if ( pString == nullptr )
    return nullptr;
  result = (char *)g_pMemAlloc->Alloc_2(this: g_pMemAlloc, a2: strlen(pString) + 1);
  if ( result == nullptr )
    return nullptr;
  strcpy(result, pString);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10001BE0
// Name: _CommandLine
// Source: json
//------------------------------------------------------------------------------
CCommandLine *__cdecl CommandLine()
{
  return &g_CmdLine;
}

//------------------------------------------------------------------------------
// Address: 0x10001BF0
// Name: private: void CCommandLine::LoadParametersFromFile(char const __near * __near &,char __near * __near &,int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCommandLine::LoadParametersFromFile(
        CCommandLine *this,
        const char **pSrc,
        char **pDst,
        int maxDestLen,
        bool bInQuotes)
{
  const char *v6; // eax
  char *v7; // edi
  char v8; // dl
  int v9; // eax
  _iobuf *v10; // eax
  _iobuf *v11; // edi
  char i; // al
  char szFileName[260]; // [esp+4h] [ebp-104h] BYREF
  char *pDestStart; // [esp+114h] [ebp+Ch]
  int bInQuotesa; // [esp+11Ch] [ebp+14h]

  pDestStart = *pDst;
  if ( maxDestLen >= 3 )
  {
    v6 = ++*pSrc;
    v7 = szFileName;
    v8 = 32;
    if ( bInQuotes )
      v8 = 34;
    if ( *v6 != 0 )
    {
      bInQuotesa = 0;
      do
      {
        if ( *v6 == v8 )
          break;
        *v7++ = *v6++;
        ++bInQuotesa;
        *pSrc = v6;
        if ( bInQuotesa >= 259 )
          break;
      }
      while ( *v6 != 0 );
    }
    v9 = (int)*pSrc;
    *v7 = 0;
    if ( *(_BYTE *)v9 != 0 )
      *pSrc = (const char *)(v9 + 1);
    v10 = fopen(file: szFileName, mode: "r");
    v11 = v10;
    if ( v10 != nullptr )
    {
      for ( i = fgetc(stream: v10); i != -1; i = fgetc(stream: v11) )
      {
        if ( i == 10 )
          i = 32;
        *(*pDst)++ = i;
        if ( *pDst - pDestStart >= maxDestLen - 2 )
          break;
      }
      *(*pDst)++ = 32;
      fclose(stream: v11);
    }
    else
    {
      printf(format: "Parameter file '%s' not found, skipping...", szFileName);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10001CF0
// Name: public: virtual void CCommandLine::CreateCmdLine(int,char __near * __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCommandLine::CreateCmdLine(CCommandLine *this, int argc, char **argv)
{
  int v3; // esi
  char cmdline[2048]; // [esp+8h] [ebp-804h] BYREF
  CCommandLine *v5; // [esp+808h] [ebp-4h]

  v3 = 0;
  v5 = this;
  cmdline[0] = 0;
  cmdline[2047] = 0;
  if ( argc > 0 )
  {
    do
    {
      strncat(Destination: cmdline, Source: "\"", Count: 0x7FFu);
      strncat(Destination: cmdline, Source: argv[v3], Count: 0x7FFu);
      strncat(Destination: cmdline, Source: "\"", Count: 0x7FFu);
      strncat(Destination: cmdline, Source: " ", Count: 0x7FFu);
      ++v3;
    }
    while ( v3 < argc );
    this = v5;
  }
  this->CreateCmdLine_2(this, a2: cmdline);
}

//------------------------------------------------------------------------------
// Address: 0x10001E60
// Name: public: virtual char const __near * CCommandLine::CheckParm(char const __near *,char const __near * __near *)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CCommandLine::CheckParm(CCommandLine *this, const char *psz, const char **ppszValue)
{
  const char *result; // eax

  if ( ppszValue != nullptr )
    *ppszValue = nullptr;
  result = (const char *)this->FindParm(this, a2: psz);
  if ( result != nullptr )
  {
    if ( ppszValue != nullptr )
    {
      if ( (int)(result + 1) >= this->m_nParmCount )
      {
        *ppszValue = nullptr;
        return this->m_ppParms[(_DWORD)result];
      }
      *ppszValue = this->m_ppParms[(_DWORD)result + 1];
    }
    return this->m_ppParms[(_DWORD)result];
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10001EC0
// Name: private: void CCommandLine::AddArgument(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCommandLine::AddArgument(CCommandLine *this, char *pFirst, const char *pLast)
{
  unsigned int v4; // edi

  if ( pLast != pFirst )
  {
    if ( this->m_nParmCount >= 256 )
      Error(pMsgFormat: "CCommandLine::AddArgument: exceeded %d parameters", 256);
    v4 = pLast - pFirst + 1;
    this->m_ppParms[this->m_nParmCount] = (char *)operator new(size: v4);
    memcpy(
      dst: (unsigned __int8 *)this->m_ppParms[this->m_nParmCount],
      src: (unsigned __int8 *)pFirst,
      count: pLast - pFirst);
    this->m_ppParms[this->m_nParmCount++][v4 - 1] = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10001F30
// Name: public: virtual int CCommandLine::ParmCount(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CCommandLine::ParmCount(CCommandLine *this)
{
  return this->m_nParmCount;
}

//------------------------------------------------------------------------------
// Address: 0x10001F40
// Name: public: virtual int CCommandLine::FindParm(char const __near *)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CCommandLine::FindParm(CCommandLine *this, const char *psz)
{
  int v3; // esi
  const char **i; // edi

  v3 = 1;
  if ( this->m_nParmCount <= 1 )
    return 0;
  for ( i = (const char **)&this->m_ppParms[1]; V_tier0_stricmp(s1: psz, s2: *i) != 0; ++i )
  {
    if ( ++v3 >= this->m_nParmCount )
      return 0;
  }
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x10001F90
// Name: public: virtual char const __near * CCommandLine::GetParm(int)const
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CCommandLine::GetParm(CCommandLine *this, int nIndex)
{
  if ( nIndex < 0 || nIndex >= this->m_nParmCount )
    return (char *)&unk_1002C436;
  else
    return this->m_ppParms[nIndex];
}

//------------------------------------------------------------------------------
// Address: 0x10001FB0
// Name: public: virtual void CCommandLine::SetParm(int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCommandLine::SetParm(CCommandLine *this, int nIndex, const char *pParm)
{
  if ( pParm != nullptr && nIndex >= 0 && nIndex < this->m_nParmCount )
  {
    if ( this->m_ppParms[nIndex] != nullptr )
      operator delete(p: this->m_ppParms[nIndex]);
    this->m_ppParms[nIndex] = MemAlloc_StrDup(pString: pParm);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10001FF0
// Name: public: virtual char const __near * CCommandLine::ParmValue(char const __near *,char const __near *)const
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CCommandLine::ParmValue(CCommandLine *this, const char *psz, const char *pDefaultVal)
{
  int v4; // eax
  char *result; // eax

  v4 = this->FindParm(this, a2: psz);
  if ( v4 == 0 )
    return (char *)pDefaultVal;
  if ( v4 == this->m_nParmCount - 1 )
    return (char *)pDefaultVal;
  result = this->m_ppParms[v4 + 1];
  if ( *result == 45 || *result == 43 )
    return (char *)pDefaultVal;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10002030
// Name: public: virtual int CCommandLine::ParmValue(char const __near *,int)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CCommandLine::ParmValue(CCommandLine *this, const char *psz, int nDefaultVal)
{
  int v4; // eax
  const char *v5; // eax

  v4 = this->FindParm(this, a2: psz);
  if ( v4 == 0 )
    return nDefaultVal;
  if ( v4 == this->m_nParmCount - 1 )
    return nDefaultVal;
  v5 = this->m_ppParms[v4 + 1];
  if ( *v5 == 45 || *v5 == 43 )
    return nDefaultVal;
  else
    return atoi(nptr: v5);
}

//------------------------------------------------------------------------------
// Address: 0x10002080
// Name: public: virtual float CCommandLine::ParmValue(char const __near *,float)const
// Source: json
//------------------------------------------------------------------------------
long double __thiscall CCommandLine::ParmValue(CCommandLine *this, const char *psz, float flDefaultVal)
{
  int v4; // eax
  const char *v5; // eax

  v4 = this->FindParm(this, a2: psz);
  if ( v4 == 0 )
    return flDefaultVal;
  if ( v4 == this->m_nParmCount - 1 )
    return flDefaultVal;
  v5 = this->m_ppParms[v4 + 1];
  if ( *v5 == 45 || *v5 == 43 )
    return flDefaultVal;
  else
    return atof(nptr: v5);
}

//------------------------------------------------------------------------------
// Address: 0x100020D0
// Name: public: virtual CCommandLine::~CCommandLine(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCommandLine::~CCommandLine(CCommandLine *this)
{
  int v2; // ebx
  void **m_ppParms; // esi
  char *m_pszCmdLine; // [esp-4h] [ebp-Ch]

  v2 = 0;
  this->__vftable = (CCommandLine_vtbl *)&CCommandLine::`vftable';
  if ( this->m_nParmCount > 0 )
  {
    m_ppParms = (void **)this->m_ppParms;
    do
    {
      operator delete(p: *m_ppParms);
      *m_ppParms = nullptr;
      ++v2;
      ++m_ppParms;
    }
    while ( v2 < this->m_nParmCount );
  }
  m_pszCmdLine = this->m_pszCmdLine;
  this->m_nParmCount = 0;
  operator delete(p: m_pszCmdLine);
}

//------------------------------------------------------------------------------
// Address: 0x10002120
// Name: private: void CCommandLine::ParseCommandLine(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCommandLine::ParseCommandLine(CCommandLine *this)
{
  int v2; // ebx
  void **m_ppParms; // esi
  char *m_pszCmdLine; // esi
  char *v5; // ebx
  char i; // al
  char v7; // al
  unsigned int v8; // esi
  bool bInQuotes; // [esp+Fh] [ebp-1h]

  v2 = 0;
  if ( this->m_nParmCount > 0 )
  {
    m_ppParms = (void **)this->m_ppParms;
    do
    {
      operator delete(p: *m_ppParms);
      *m_ppParms = nullptr;
      ++v2;
      ++m_ppParms;
    }
    while ( v2 < this->m_nParmCount );
  }
  m_pszCmdLine = this->m_pszCmdLine;
  v5 = nullptr;
  this->m_nParmCount = 0;
  if ( m_pszCmdLine != nullptr )
  {
    for ( i = *m_pszCmdLine; i != 0; i = *++m_pszCmdLine )
    {
      if ( i < 9 || i > 13 && i != 32 )
        break;
    }
    v7 = *m_pszCmdLine;
    bInQuotes = false;
    if ( *m_pszCmdLine != 0 )
    {
      do
      {
        if ( bInQuotes )
        {
          if ( v7 == 34 )
          {
            CCommandLine::AddArgument(this, pFirst: v5, pLast: m_pszCmdLine);
            v5 = nullptr;
            bInQuotes = false;
          }
        }
        else if ( v5 != nullptr )
        {
          if ( v7 >= 9 && (v7 <= 13 || v7 == 32) )
          {
            CCommandLine::AddArgument(this, pFirst: v5, pLast: m_pszCmdLine);
            v5 = nullptr;
          }
        }
        else if ( v7 == 34 )
        {
          bInQuotes = true;
          v5 = m_pszCmdLine + 1;
        }
        else if ( v7 < 9 || v7 > 13 && v7 != 32 )
        {
          v5 = m_pszCmdLine;
        }
        v7 = *++m_pszCmdLine;
      }
      while ( v7 != 0 );
      if ( v5 != nullptr && m_pszCmdLine != v5 )
      {
        if ( this->m_nParmCount >= 256 )
          Error(pMsgFormat: "CCommandLine::AddArgument: exceeded %d parameters", 256);
        v8 = m_pszCmdLine - v5 + 1;
        this->m_ppParms[this->m_nParmCount] = (char *)operator new(size: v8);
        memcpy(dst: (unsigned __int8 *)this->m_ppParms[this->m_nParmCount], src: (unsigned __int8 *)v5, count: v8 - 1);
        this->m_ppParms[this->m_nParmCount++][v8 - 1] = 0;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10002290
// Name: public: virtual void CCommandLine::CreateCmdLine(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCommandLine::CreateCmdLine(CCommandLine *this, char *commandline)
{
  CCommandLine *v2; // ebx
  char *m_pszCmdLine; // eax
  char *v4; // edi
  char *v5; // edx
  char *v6; // eax
  char *v7; // esi
  char v8; // bl
  char v9; // cl
  int v10; // ecx
  bool v11; // zf
  unsigned int v12; // kr00_4
  unsigned __int8 *v13; // eax
  unsigned __int8 src[4096]; // [esp+8h] [ebp-1010h] BYREF
  char *pDst; // [esp+1008h] [ebp-10h] BYREF
  CCommandLine *v16; // [esp+100Ch] [ebp-Ch]
  char *pSrc; // [esp+1010h] [ebp-8h] BYREF
  bool bInQuotes[4]; // [esp+1014h] [ebp-4h]

  v2 = this;
  m_pszCmdLine = this->m_pszCmdLine;
  v16 = this;
  if ( m_pszCmdLine != nullptr )
    operator delete(p: m_pszCmdLine);
  v4 = commandline;
  v5 = (char *)src;
  v6 = commandline;
  v7 = nullptr;
  v11 = *commandline == 0;
  pDst = (char *)src;
  pSrc = commandline;
  bInQuotes[0] = false;
  if ( !v11 )
  {
    while ( 1 )
    {
      v8 = *v6;
      if ( *v6 == 34 && (v6 == v4 || (v9 = *(v6 - 1)) != 47 && v9 != 92) )
      {
        v7 = v6 + 1;
        bInQuotes[0] = !bInQuotes[0];
      }
      if ( v8 != 64 )
      {
LABEL_18:
        if ( (unsigned int)(v5 - (char *)src) >= 0xFFF )
          goto LABEL_21;
        v4 = commandline;
        *v5++ = v8;
        ++v6;
        pDst = v5;
        pSrc = v6;
        goto LABEL_20;
      }
      if ( v6 != v4 )
      {
        if ( bInQuotes[0] )
        {
          v11 = v6 == v7;
        }
        else
        {
          v10 = *(v6 - 1);
          if ( v10 < 9 )
            goto LABEL_18;
          if ( v10 <= 13 )
            goto LABEL_17;
          v11 = v10 == 32;
        }
        if ( !v11 )
          goto LABEL_18;
      }
LABEL_17:
      CCommandLine::LoadParametersFromFile(
        this: v16,
        (const char **)&pSrc,
        &pDst,
        maxDestLen: (char *)&pDst - v5,
        bInQuotes: bInQuotes[0]);
      v5 = pDst;
      v6 = pSrc;
LABEL_20:
      if ( *v6 == 0 )
      {
LABEL_21:
        v2 = v16;
        break;
      }
    }
  }
  *v5 = 0;
  v12 = strlen((const char *)src);
  v13 = (unsigned __int8 *)operator new(size: v12 + 1);
  v2->m_pszCmdLine = (char *)v13;
  memcpy(dst: v13, src, count: v12 + 1);
  CCommandLine::ParseCommandLine(this: v2);
}

//------------------------------------------------------------------------------
// Address: 0x100023C0
// Name: public: virtual void CCommandLine::RemoveParm(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCommandLine::RemoveParm(CCommandLine *this, const char *pszParm)
{
  CCommandLine *v2; // ebx
  char *m_pszCmdLine; // eax
  char *v4; // edi
  unsigned int v5; // ebx
  char *v6; // eax
  char *v7; // esi
  unsigned __int8 *v8; // eax
  unsigned __int8 v9; // cl
  unsigned __int8 v10; // cl
  unsigned int v11; // edi
  const char *v12; // ecx
  unsigned int i; // eax
  char *p; // [esp+8h] [ebp-8h]
  bool bHadQuote; // [esp+Fh] [ebp-1h]

  v2 = this;
  m_pszCmdLine = this->m_pszCmdLine;
  if ( m_pszCmdLine == nullptr )
    return;
  v4 = this->m_pszCmdLine;
  p = v4;
  if ( *m_pszCmdLine == 0 )
    goto LABEL_27;
  do
  {
    v5 = strlen(v4);
    v6 = stristr(pStr: v4, pSearch: pszParm);
    v7 = v6;
    if ( v6 == nullptr )
      break;
    v8 = (unsigned __int8 *)(v6 + 1);
    bHadQuote = false;
    if ( v7 > this->m_pszCmdLine )
      bHadQuote = *(v7 - 1) == 34;
    if ( v7 == (char *)-1 )
      goto LABEL_19;
    while ( 1 )
    {
      v9 = *v8;
      if ( *v8 == 0 || v9 == 32 || v9 == 34 )
        break;
      if ( ++v8 == nullptr )
        goto LABEL_19;
    }
    if ( v8 - (unsigned __int8 *)v7 <= strlen(pszParm) )
    {
      do
      {
        v10 = *v8;
        if ( *v8 == 0 )
          break;
        if ( v10 == 45 )
          break;
        if ( v10 == 43 )
          break;
        ++v8;
      }
      while ( v8 != nullptr );
      v4 = p;
LABEL_19:
      if ( bHadQuote )
        --v7;
      if ( v8 != nullptr && *v8 != 0 )
      {
        v11 = (unsigned int)&v4[v5 - (_DWORD)v8];
        memmove(dst: (unsigned __int8 *)v7, src: v8, count: v11);
        v7[v11] = 0;
        v4 = p;
      }
      else
      {
        memset(dst: (unsigned __int8 *)v7, value: 0, count: v8 - (unsigned __int8 *)v7);
      }
      continue;
    }
    p = (char *)v8;
    v4 = (char *)v8;
  }
  while ( *v4 != 0 );
  v2 = this;
LABEL_27:
  v12 = v2->m_pszCmdLine;
  for ( i = strlen(v12); i != 0; i = strlen(v12) )
  {
    if ( v12[i - 1] != 32 )
      break;
    v12[i - 1] = 0;
    v12 = v2->m_pszCmdLine;
  }
  CCommandLine::ParseCommandLine(this: v2);
}

//------------------------------------------------------------------------------
// Address: 0x10002500
// Name: public: virtual void CCommandLine::AppendParm(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCommandLine::AppendParm(CCommandLine *this, const char *pszParm, const char *pszValues)
{
  CCommandLine *v3; // edi
  unsigned int v4; // esi
  unsigned int v5; // esi
  char *v6; // eax
  const char *v7; // ecx
  char *v8; // edx
  char v9; // al
  char *v10; // edi
  char v11; // al
  unsigned int v12; // esi
  unsigned __int8 *v13; // ebx
  char *m_pszCmdLine; // ecx
  unsigned __int8 *v15; // edx
  char v16; // al

  v3 = this;
  v4 = strlen(pszParm);
  if ( pszValues != nullptr )
    v4 += strlen(pszValues) + 1;
  v5 = v4 + 1;
  if ( v3->m_pszCmdLine != nullptr )
  {
    v3->RemoveParm(this: v3, a2: pszParm);
    v12 = v5 + strlen(v3->m_pszCmdLine) + 2;
    v13 = (unsigned __int8 *)operator new(size: v12);
    memset(dst: v13, value: 0, count: v12);
    m_pszCmdLine = v3->m_pszCmdLine;
    v15 = v13;
    do
    {
      v16 = *m_pszCmdLine;
      *v15++ = *m_pszCmdLine++;
    }
    while ( v16 != 0 );
    strcat((char *)v13, " ");
    strcat((char *)v13, pszParm);
    if ( pszValues != nullptr )
    {
      strcat((char *)v13, " ");
      strcat((char *)v13, pszValues);
    }
    operator delete(p: this->m_pszCmdLine);
    this->m_pszCmdLine = (char *)v13;
    CCommandLine::ParseCommandLine(this);
  }
  else
  {
    v6 = (char *)operator new(size: v5);
    v3->m_pszCmdLine = v6;
    v7 = pszParm;
    v8 = v6;
    do
    {
      v9 = *v7;
      *v8++ = *v7++;
    }
    while ( v9 != 0 );
    if ( pszValues != nullptr )
    {
      v10 = v3->m_pszCmdLine - 1;
      do
        v11 = *++v10;
      while ( v11 != 0 );
      strcpy(v10, " ");
      strcat(this->m_pszCmdLine, pszValues);
      v3 = this;
    }
    CCommandLine::ParseCommandLine(this: v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10001DA0
// Name: _stristr
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char *__usercall stristr@<eax>(char *pStr@<eax>, const char *pSearch)
{
  const char *v2; // esi
  char *v3; // edi
  int v4; // ebx
  unsigned __int8 v5; // al
  _BYTE *v6; // esi
  int v7; // edi
  int v8; // ebx
  char *pLetter; // [esp+8h] [ebp-4h]

  v2 = pSearch;
  v3 = pStr;
  if ( pStr == nullptr || pSearch == nullptr )
    return nullptr;
  pLetter = pStr;
  if ( *pStr != 0 )
  {
    while ( 1 )
    {
      v4 = tolower(c: (unsigned __int8)*v3);
      if ( v4 == tolower(c: *(unsigned __int8 *)v2) )
        break;
LABEL_14:
      pLetter = ++v3;
      if ( *v3 == 0 )
        return nullptr;
    }
    v5 = v2[1];
    v6 = v2 + 1;
    if ( v5 == 0 )
      return v3;
    v7 = v3 - v6;
    while ( v6[v7 + 1] != 0 )
    {
      v8 = tolower(c: v5);
      if ( tolower(c: (unsigned __int8)v6[v7 + 1]) != v8 )
      {
        if ( *v6 == 0 )
          return pLetter;
        v2 = pSearch;
        v3 = pLetter;
        goto LABEL_14;
      }
      v5 = *++v6;
      if ( v5 == 0 )
        return pLetter;
    }
  }
  return nullptr;
}
