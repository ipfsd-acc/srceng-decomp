// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/hammer_run_map_launcher/hammer_run_map_launcher.cpp
// Functions: 8
// ============================================================

#include "utils\hammer_run_map_launcher\hammer_run_map_launcher.h"

//------------------------------------------------------------------------------
// Address: 0x00401000
// Name: RemoveQuotes
// Source: json
//------------------------------------------------------------------------------
void __usercall RemoveQuotes(char *pBuf@<esi>)
{
  unsigned int v1; // eax

  if ( *pBuf == 34 )
  {
    v1 = _V_strlen(str: pBuf);
    memmove(dst: (unsigned __int8 *)pBuf, src: (unsigned __int8 *)pBuf + 1, count: v1);
  }
  if ( pBuf[_V_strlen(str: pBuf) - 1] == 34 )
    pBuf[_V_strlen(str: pBuf) - 1] = 0;
}

//------------------------------------------------------------------------------
// Address: 0x00401040
// Name: int mychdir(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl mychdir(const char *pszDir)
{
  int v1; // edi
  int v2; // eax

  v1 = _getdrive();
  if ( pszDir[1] == 58 )
  {
    v2 = toupper(c: *pszDir);
    if ( _chdrive(drive: v2 - 64) == -1 )
      return -1;
  }
  if ( _chdir(path: pszDir) == -1 )
  {
    _chdrive(drive: v1);
    return -1;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x004010A0
// Name: char __near * DecodeCommand(char const __near *)
// Source: json
//------------------------------------------------------------------------------
char *__cdecl DecodeCommand(const char *pSignedCommand)
{
  unsigned int v1; // eax
  char *result; // eax
  int v3; // ecx
  unsigned int v4; // esi
  unsigned int i; // ecx

  v1 = strlen(pSignedCommand);
  if ( (v1 & 1) != 0 )
    return nullptr;
  v3 = 0;
  if ( v1 != 0 )
  {
    while ( (unsigned __int8)pSignedCommand[v3] < 0x71u )
    {
      if ( ++v3 >= v1 )
        goto LABEL_6;
    }
    return nullptr;
  }
LABEL_6:
  v4 = v1 >> 1;
  result = (char *)operator new(size: (v1 >> 1) + 1);
  for ( i = 0; i < v4; ++i )
    result[i] = (pSignedCommand[2 * i] - 97) | (16 * pSignedCommand[2 * i + 1] - 16);
  result[v4] = 0;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00401130
// Name: public: void CUtlMemory<char __near *,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<char *,int>::Grow(CUtlMemory<char *,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  char **m_pMemory; // edx
  unsigned int v7; // [esp-4h] [ebp-Ch]

  m_nGrowSize = this->m_nGrowSize;
  if ( m_nGrowSize >= 0 )
  {
    m_nAllocationCount = this->m_nAllocationCount;
    v5 = m_nAllocationCount + num;
    if ( m_nGrowSize != 0 )
    {
      m_nAllocationCount = m_nGrowSize * ((v5 - 1) / m_nGrowSize + 1);
    }
    else
    {
      if ( m_nAllocationCount == 0 )
        m_nAllocationCount = 8;
      if ( m_nAllocationCount >= v5 )
        goto LABEL_13;
      do
        m_nAllocationCount *= 2;
      while ( m_nAllocationCount < v5 );
    }
    if ( m_nAllocationCount < v5 )
    {
      if ( m_nAllocationCount != 0 || v5 > -1 )
      {
        do
          m_nAllocationCount = (v5 + m_nAllocationCount) / 2;
        while ( m_nAllocationCount < v5 );
      }
      else
      {
        m_nAllocationCount = -1;
      }
    }
LABEL_13:
    m_pMemory = this->m_pMemory;
    this->m_nAllocationCount = m_nAllocationCount;
    v7 = 4 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (char **)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (char **)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004011C0
// Name: public: CUtlVector<char __near *,class CUtlMemory<char __near *,int>>::~CUtlVector<char __near *,class CUtlMemory<char __near *,int>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<char *,CUtlMemory<char *,int>>::~CUtlVector<char *,CUtlMemory<char *,int>>(
        CUtlVector<char *,CUtlMemory<char *,int> > *this)
{
  bool v2; // sf
  char **m_pMemory; // eax

  v2 = this->m_Memory.m_nGrowSize < 0;
  this->m_Size = 0;
  if ( !v2 )
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
  v2 = this->m_Memory.m_nGrowSize < 0;
  m_pMemory = this->m_Memory.m_pMemory;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( !v2 )
  {
    if ( m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00401230
// Name: void ParseParms(char __near *,class CUtlVector<char __near *,class CUtlMemory<char __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ParseParms(char *pInput, CUtlVector<char *,CUtlMemory<char *,int> > *parms)
{
  char *v2; // esi
  int m_Size; // edi
  int m_nAllocationCount; // eax
  char **m_pMemory; // ecx
  int v6; // eax
  char **v7; // edi
  int bDone; // [esp+4h] [ebp-4h]

  v2 = pInput;
  bDone = 0;
  if ( *pInput != 0 )
  {
    do
    {
      m_Size = parms->m_Size;
      m_nAllocationCount = parms->m_Memory.m_nAllocationCount;
      if ( m_Size + 1 > m_nAllocationCount )
        CUtlMemory<char *,int>::Grow(this: &parms->m_Memory, num: m_Size - m_nAllocationCount + 1);
      ++parms->m_Size;
      m_pMemory = parms->m_Memory.m_pMemory;
      v6 = parms->m_Size - m_Size - 1;
      parms->m_pElements = parms->m_Memory.m_pMemory;
      if ( v6 > 0 )
        _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v6);
      v7 = &parms->m_Memory.m_pMemory[m_Size];
      if ( v7 != nullptr )
        *v7 = v2;
      if ( *v2 == 0 )
        break;
      while ( *v2 != 32 )
      {
        if ( *v2 == 34 )
        {
          do
            ++v2;
          while ( *v2 != 34 );
          if ( v2[1] == 0 )
            bDone = 1;
          v2[1] = 0;
          for ( v2 += 2; *v2 == 32; ++v2 )
            ;
          goto LABEL_18;
        }
        if ( *++v2 == 0 )
          return;
      }
      for ( *v2++ = 0; *v2 == 32; ++v2 )
        ;
LABEL_18:
      ;
    }
    while ( *v2 != 0 && bDone == 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00401310
// Name: int LaunchSomething(char __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl LaunchSomething(char *pCommandLine)
{
  int m_Size; // esi
  char **m_pMemory; // edi
  unsigned __int8 *v4; // ebx
  unsigned int v5; // eax
  int v6; // esi
  int v7; // esi
  int v8; // esi
  int v9; // esi
  int v10; // ebx
  int v11; // esi
  char **v12; // ebx
  int v13; // esi
  CUtlVector<char *,CUtlMemory<char *,int> > parms; // [esp+8h] [ebp-14h] BYREF

  memset(&parms, 0, sizeof(parms));
  ParseParms(pInput: pCommandLine, &parms);
  m_Size = parms.m_Size;
  if ( parms.m_Size != 0 )
  {
    m_pMemory = parms.m_Memory.m_pMemory;
    v4 = (unsigned __int8 *)*parms.m_Memory.m_pMemory;
    if ( **parms.m_Memory.m_pMemory == 34 )
    {
      v5 = _V_strlen(str: *(const char **)parms.m_Memory.m_pMemory);
      memmove(dst: v4, src: v4 + 1, count: v5);
    }
    if ( v4[_V_strlen(str: (const char *)v4) - 1] == 34 )
      v4[_V_strlen(str: (const char *)v4) - 1] = 0;
    if ( _V_stricmp(s1: *m_pMemory, s2: "copy") != 0 || m_Size != 3 )
    {
      if ( _V_stricmp(s1: *m_pMemory, s2: "ren") != 0 || m_Size != 3 )
      {
        if ( _V_stricmp(s1: *m_pMemory, s2: "del") != 0 || m_Size != 2 )
        {
          if ( _V_stricmp(s1: *m_pMemory, s2: "cd") != 0 || m_Size != 2 )
          {
            v10 = m_Size;
            if ( m_Size + 1 > parms.m_Memory.m_nAllocationCount )
            {
              CUtlMemory<char *,int>::Grow(this: &parms.m_Memory, num: m_Size - parms.m_Memory.m_nAllocationCount + 1);
              m_Size = parms.m_Size;
              m_pMemory = parms.m_Memory.m_pMemory;
            }
            parms.m_Size = m_Size + 1;
            v11 = m_Size - v10;
            parms.m_pElements = m_pMemory;
            if ( v11 > 0 )
              _V_memmove(dest: &m_pMemory[v10 + 1], src: &m_pMemory[v10], count: 4 * v11);
            v12 = &m_pMemory[v10];
            if ( v12 != nullptr )
              *v12 = nullptr;
            v13 = _spawnv(modeflag: 0, pathname: *m_pMemory, argv: (const char *const *)m_pMemory);
            CUtlVector<char *,CUtlMemory<char *,int>>::~CUtlVector<char *,CUtlMemory<char *,int>>(this: &parms);
            return v13;
          }
          else
          {
            RemoveQuotes(pBuf: m_pMemory[1]);
            v9 = mychdir(pszDir: m_pMemory[1]);
            CUtlVector<char *,CUtlMemory<char *,int>>::~CUtlVector<char *,CUtlMemory<char *,int>>(this: &parms);
            return v9;
          }
        }
        else
        {
          RemoveQuotes(pBuf: m_pMemory[1]);
          v8 = -DeleteFileA(lpFileName: m_pMemory[1]);
          CUtlVector<char *,CUtlMemory<char *,int>>::~CUtlVector<char *,CUtlMemory<char *,int>>(this: &parms);
          return v8 + 1;
        }
      }
      else
      {
        RemoveQuotes(pBuf: m_pMemory[1]);
        RemoveQuotes(pBuf: m_pMemory[2]);
        v7 = -(rename(oldname: m_pMemory[1], newname: m_pMemory[2]) != 0);
        CUtlVector<char *,CUtlMemory<char *,int>>::~CUtlVector<char *,CUtlMemory<char *,int>>(this: &parms);
        return v7 + 1;
      }
    }
    else
    {
      RemoveQuotes(pBuf: m_pMemory[1]);
      RemoveQuotes(pBuf: m_pMemory[2]);
      v6 = -CopyFileA(lpExistingFileName: m_pMemory[1], lpNewFileName: m_pMemory[2], bFailIfExists: false);
      CUtlVector<char *,CUtlMemory<char *,int>>::~CUtlVector<char *,CUtlMemory<char *,int>>(this: &parms);
      return v6 + 1;
    }
  }
  else
  {
    CUtlVector<char *,CUtlMemory<char *,int>>::~CUtlVector<char *,CUtlMemory<char *,int>>(this: &parms);
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00401520
// Name: _main
// Source: json
//------------------------------------------------------------------------------
int __cdecl main(int argc, const char **argv, const char **envp)
{
  int v3; // ebx
  char *v4; // esi
  int returnValue; // [esp+Ch] [ebp-8h]
  bool bWaitForKeypress; // [esp+13h] [ebp-1h]

  returnValue = 0;
  bWaitForKeypress = false;
  if ( argc >= 2 )
    bWaitForKeypress = _V_stricmp(s1: argv[1], s2: "-WaitForKeyPress") == 0;
  v3 = bWaitForKeypress + 1;
  if ( v3 < argc )
  {
    while ( 1 )
    {
      v4 = DecodeCommand(pSignedCommand: argv[v3]);
      if ( v4 == nullptr )
        break;
      _Msg(a1: "\n-------------------------------------------------------------------------------\n");
      _Msg(a1: "Running command: %s\n", v4);
      _Msg(a1: "-------------------------------------------------------------------------------\n\n");
      returnValue = LaunchSomething(pCommandLine: v4);
      operator delete(p: v4);
      if ( returnValue == 0 && ++v3 < argc )
        continue;
      goto LABEL_9;
    }
    _Msg(a1: "Can't decode command %s!\n", argv[v3]);
    returnValue = 1;
  }
LABEL_9:
  if ( bWaitForKeypress )
  {
    _Msg(a1: "Finished. Press a key to close. ");
    getch();
  }
  return returnValue;
}
