// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: engine/baseautocompletefilelist.cpp
// Functions: 1
// ============================================================

#include "engine\baseautocompletefilelist.h"

//------------------------------------------------------------------------------
// Address: 0x10134700
// Name: public: int CBaseAutoCompleteFileList::AutoCompletionFunc(char const __near *,char (__near * const)[64])
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBaseAutoCompleteFileList::AutoCompletionFunc(
        CBaseAutoCompleteFileList *this,
        char *partial,
        char (*commands)[64])
{
  char *v3; // ebx
  const char *m_pszCommandName; // esi
  const char *m_pszSubDir; // eax
  int m_Size; // ebx
  CUtlSymbol *m_pMemory; // edi
  const char *First; // esi
  int v10; // eax
  int v11; // esi
  CUtlSymbol *v12; // eax
  const char *Next; // eax
  int v14; // edi
  char *v15; // esi
  const char *v16; // eax
  const char *v17; // eax
  const char *v18; // ecx
  char sz[96]; // [esp+Ch] [ebp-118h] BYREF
  char searchpath[96]; // [esp+6Ch] [ebp-B8h] BYREF
  CUtlSymbolTable entries; // [esp+CCh] [ebp-58h] BYREF
  char *v23; // [esp+104h] [ebp-20h]
  const char *cmdname; // [esp+108h] [ebp-1Ch]
  CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int> > symbols; // [esp+10Ch] [ebp-18h] BYREF
  char *substring; // [esp+120h] [ebp-4h]

  v3 = partial;
  m_pszCommandName = this->m_pszCommandName;
  cmdname = m_pszCommandName;
  substring = partial;
  if ( _V_strstr(s1: partial, search: m_pszCommandName) != nullptr )
    substring = &v3[strlen(m_pszCommandName) + 1];
  m_pszSubDir = this->m_pszSubDir;
  m_Size = 0;
  if ( m_pszSubDir != nullptr && *m_pszSubDir != 0 && V_strcasecmp(s1: m_pszSubDir, s2: "NULL") != 0 )
    V_snprintf(pDest: searchpath, maxLen: 96, pFormat: "%s/*.%s", this->m_pszSubDir, this->m_pszExtension);
  else
    V_snprintf(pDest: searchpath, maxLen: 96, pFormat: "*.%s", this->m_pszExtension);
  CUtlSymbolTable::CUtlSymbolTable(this: &entries, growSize: 0, initSize: 0, caseInsensitive: true);
  m_pMemory = nullptr;
  memset(&symbols, 0, sizeof(symbols));
  First = Sys_FindFirst(path: searchpath, basename: nullptr, namelength: 0);
  if ( First != nullptr )
  {
    do
    {
      V_snprintf(pDest: sz, maxLen: 96, pFormat: "%s", First);
      if ( *substring == 0 || (v23 = substring + 1, V_strncasecmp(s1: First, s2: substring, n: strlen(substring)) == 0) )
      {
        CUtlSymbolTable::AddString(this: &entries, result: (CUtlSymbol *)&partial, pString: First);
        v10 = 0;
        if ( m_Size <= 0 )
          goto LABEL_16;
        while ( m_pMemory[v10].m_Id != (_WORD)partial )
        {
          if ( ++v10 >= m_Size )
            goto LABEL_16;
        }
        if ( v10 == -1 )
        {
LABEL_16:
          v11 = m_Size;
          if ( m_Size + 1 > symbols.m_Memory.m_nAllocationCount )
          {
            CUtlMemory<wchar_t,int>::Grow(
              this: (CUtlMemory<wchar_t,int> *)&symbols,
              num: m_Size - symbols.m_Memory.m_nAllocationCount + 1);
            m_Size = symbols.m_Size;
            m_pMemory = symbols.m_Memory.m_pMemory;
          }
          symbols.m_Size = ++m_Size;
          symbols.m_pElements = m_pMemory;
          if ( m_Size - v11 - 1 > 0 )
            _V_memmove(dest: &m_pMemory[v11 + 1], src: &m_pMemory[v11], count: 2 * (m_Size - v11 - 1));
          v12 = &m_pMemory[v11];
          if ( v12 != nullptr )
            v12->m_Id = (unsigned __int16)partial;
        }
      }
      Next = Sys_FindNext(basename: nullptr, namelength: 0);
      First = Next;
    }
    while ( m_Size < 64 && Next != nullptr );
  }
  Sys_FindClose();
  v14 = 0;
  if ( m_Size > 0 )
  {
    v15 = (char *)commands;
    partial = nullptr;
    do
    {
      v16 = CUtlSymbolTable::String(this: &entries, id: symbols.m_Memory.m_pMemory[v14]);
      V_snprintf(pDest: v15, maxLen: 64, pFormat: "%s %s", cmdname, v16);
      v17 = &partial[strlen(v15)];
      ++v14;
      v18 = partial + 64;
      v15 += 64;
      (*commands)[(_DWORD)v17 - 4] = 0;
      partial = (char *)v18;
    }
    while ( v14 < m_Size );
  }
  if ( symbols.m_Memory.m_nGrowSize >= 0 && symbols.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: symbols.m_Memory.m_pMemory);
  CUtlSymbolTable::~CUtlSymbolTable(this: &entries);
  return m_Size;
}

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x10134740
// Name: public: int CBaseAutoCompleteFileList::AutoCompletionFunc(char const __near *,char (__near * const)[64])
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBaseAutoCompleteFileList::AutoCompletionFunc(
        CBaseAutoCompleteFileList *this,
        char *partial,
        char (*commands)[64])
{
  char *v3; // ebx
  const char *m_pszCommandName; // esi
  const char *m_pszSubDir; // eax
  int m_Size; // ebx
  CUtlSymbol *m_pMemory; // edi
  const char *First; // esi
  int v10; // eax
  int v11; // esi
  CUtlSymbol *v12; // eax
  const char *Next; // eax
  int v14; // edi
  char *v15; // esi
  const char *v16; // eax
  const char *v17; // eax
  const char *v18; // ecx
  char sz[96]; // [esp+Ch] [ebp-118h] BYREF
  char searchpath[96]; // [esp+6Ch] [ebp-B8h] BYREF
  CUtlSymbolTable entries; // [esp+CCh] [ebp-58h] BYREF
  char *v23; // [esp+104h] [ebp-20h]
  const char *cmdname; // [esp+108h] [ebp-1Ch]
  CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int> > symbols; // [esp+10Ch] [ebp-18h] BYREF
  char *substring; // [esp+120h] [ebp-4h]

  v3 = partial;
  m_pszCommandName = this->m_pszCommandName;
  cmdname = m_pszCommandName;
  substring = partial;
  if ( _V_strstr(s1: partial, search: m_pszCommandName) != nullptr )
    substring = &v3[strlen(m_pszCommandName) + 1];
  m_pszSubDir = this->m_pszSubDir;
  m_Size = 0;
  if ( m_pszSubDir != nullptr && *m_pszSubDir != 0 && V_strcasecmp(s1: m_pszSubDir, s2: "NULL") != 0 )
    V_snprintf(pDest: searchpath, maxLen: 96, pFormat: "%s/*.%s", this->m_pszSubDir, this->m_pszExtension);
  else
    V_snprintf(pDest: searchpath, maxLen: 96, pFormat: "*.%s", this->m_pszExtension);
  CUtlSymbolTable::CUtlSymbolTable(this: &entries, growSize: 0, initSize: 0, caseInsensitive: true);
  m_pMemory = nullptr;
  memset(&symbols, 0, sizeof(symbols));
  First = Sys_FindFirst(path: searchpath, basename: nullptr, namelength: 0);
  if ( First != nullptr )
  {
    do
    {
      V_snprintf(pDest: sz, maxLen: 96, pFormat: "%s", First);
      if ( *substring == 0 || (v23 = substring + 1, V_strncasecmp(s1: First, s2: substring, n: strlen(substring)) == 0) )
      {
        CUtlSymbolTable::AddString(this: &entries, result: (CUtlSymbol *)&partial, pString: First);
        v10 = 0;
        if ( m_Size <= 0 )
          goto LABEL_16;
        while ( m_pMemory[v10].m_Id != (_WORD)partial )
        {
          if ( ++v10 >= m_Size )
            goto LABEL_16;
        }
        if ( v10 == -1 )
        {
LABEL_16:
          v11 = m_Size;
          if ( m_Size + 1 > symbols.m_Memory.m_nAllocationCount )
          {
            CUtlMemory<wchar_t,int>::Grow(
              this: (CUtlMemory<wchar_t,int> *)&symbols,
              num: m_Size - symbols.m_Memory.m_nAllocationCount + 1);
            m_Size = symbols.m_Size;
            m_pMemory = symbols.m_Memory.m_pMemory;
          }
          symbols.m_Size = ++m_Size;
          symbols.m_pElements = m_pMemory;
          if ( m_Size - v11 - 1 > 0 )
            _V_memmove(dest: &m_pMemory[v11 + 1], src: &m_pMemory[v11], count: 2 * (m_Size - v11 - 1));
          v12 = &m_pMemory[v11];
          if ( v12 != nullptr )
            v12->m_Id = (unsigned __int16)partial;
        }
      }
      Next = Sys_FindNext(basename: nullptr, namelength: 0);
      First = Next;
    }
    while ( m_Size < 64 && Next != nullptr );
  }
  Sys_FindClose();
  v14 = 0;
  if ( m_Size > 0 )
  {
    v15 = (char *)commands;
    partial = nullptr;
    do
    {
      v16 = CUtlSymbolTable::String(this: &entries, id: symbols.m_Memory.m_pMemory[v14]);
      V_snprintf(pDest: v15, maxLen: 64, pFormat: "%s %s", cmdname, v16);
      v17 = &partial[strlen(v15)];
      ++v14;
      v18 = partial + 64;
      v15 += 64;
      (*commands)[(_DWORD)v17 - 4] = 0;
      partial = (char *)v18;
    }
    while ( v14 < m_Size );
  }
  if ( symbols.m_Memory.m_nGrowSize >= 0 && symbols.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: symbols.m_Memory.m_pMemory);
  CUtlSymbolTable::~CUtlSymbolTable(this: &entries);
  return m_Size;
}

} // namespace engine_xlsp
