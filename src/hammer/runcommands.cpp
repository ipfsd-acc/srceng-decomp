// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: hammer/runcommands.cpp
// Functions: 9
// ============================================================

#include "hammer\runcommands.h"

//------------------------------------------------------------------------------
// Address: 0x1009EFF0
// Name: bool IsRunningCommands(void)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl IsRunningCommands()
{
  return s_bRunsCommands;
}

//------------------------------------------------------------------------------
// Address: 0x1009F000
// Name: void FixGameVars(char __near *,char __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl FixGameVars(char *pszSrc, char *pszDst, int bUseQuotes)
{
  char *v3; // esi
  int v4; // ebx
  char *v5; // edi
  char *v6; // eax
  int v7; // edx
  char v8; // cl
  char *v9; // eax
  int v10; // edx
  char v11; // cl
  char *v12; // eax
  int v13; // edx
  char v14; // cl
  char *m_szGameExeDir; // ecx
  char *v16; // edx
  char v17; // al
  char *szBSPDir; // ecx
  char *v19; // edx
  char v20; // al
  char *szBSP; // ecx
  char *v22; // edx
  char v23; // al
  char *szVIS; // ecx
  char *v25; // edx
  char v26; // al
  char *szLIGHT; // ecx
  char *v28; // edx
  char v29; // al
  char *szExecutable; // ecx
  char *v31; // edx
  char v32; // al
  char *m_szModDir; // ecx
  char *v34; // edx
  char v35; // al

  v3 = pszDst;
  v4 = 0;
  v5 = pszSrc;
  if ( *pszSrc == 0 )
  {
    *pszDst = 0;
    return;
  }
  do
  {
    if ( *v5 != 36 )
    {
      if ( *v5 == 32 && v4 != 0 )
      {
        v4 = 0;
        *v3++ = 34;
      }
      *v3 = *v5;
      goto LABEL_52;
    }
    if ( v5[1] == 36 )
    {
      *v3 = 36;
LABEL_52:
      ++v3;
      ++v5;
      continue;
    }
    ++v5;
    if ( v4 == 0 && bUseQuotes != 0 )
    {
      *v3++ = 34;
      v4 = 1;
    }
    if ( V_strncasecmp(s1: v5, s2: "file", n: 4) != 0 )
    {
      if ( V_strncasecmp(s1: v5, s2: "ext", n: 3) != 0 )
      {
        if ( V_strncasecmp(s1: v5, s2: "path", n: 4) != 0 )
        {
          if ( V_strncasecmp(s1: v5, s2: "exedir", n: 6) != 0 )
          {
            if ( V_strncasecmp(s1: v5, s2: "bspdir", n: 6) != 0 )
            {
              if ( V_strncasecmp(s1: v5, s2: "bsp_exe", n: 7) != 0 )
              {
                if ( V_strncasecmp(s1: v5, s2: "vis_exe", n: 7) != 0 )
                {
                  if ( V_strncasecmp(s1: v5, s2: "light_exe", n: 9) != 0 )
                  {
                    if ( V_strncasecmp(s1: v5, s2: "game_exe", n: 8) != 0 )
                    {
                      if ( V_strncasecmp(s1: v5, s2: "gamedir", n: 7) == 0 )
                      {
                        v5 += 7;
                        m_szModDir = g_pGameConfig->m_szModDir;
                        v34 = v3;
                        do
                        {
                          v35 = *m_szModDir;
                          *v34++ = *m_szModDir++;
                        }
                        while ( v35 != 0 );
                        v3 += strlen(v3);
                      }
                    }
                    else
                    {
                      v5 += 8;
                      szExecutable = g_pGameConfig->szExecutable;
                      v31 = v3;
                      do
                      {
                        v32 = *szExecutable;
                        *v31++ = *szExecutable++;
                      }
                      while ( v32 != 0 );
                      v3 += strlen(v3);
                    }
                  }
                  else
                  {
                    v5 += 9;
                    szLIGHT = g_pGameConfig->szLIGHT;
                    v28 = v3;
                    do
                    {
                      v29 = *szLIGHT;
                      *v28++ = *szLIGHT++;
                    }
                    while ( v29 != 0 );
                    v3 += strlen(v3);
                  }
                }
                else
                {
                  v5 += 7;
                  szVIS = g_pGameConfig->szVIS;
                  v25 = v3;
                  do
                  {
                    v26 = *szVIS;
                    *v25++ = *szVIS++;
                  }
                  while ( v26 != 0 );
                  v3 += strlen(v3);
                }
              }
              else
              {
                v5 += 7;
                szBSP = g_pGameConfig->szBSP;
                v22 = v3;
                do
                {
                  v23 = *szBSP;
                  *v22++ = *szBSP++;
                }
                while ( v23 != 0 );
                v3 += strlen(v3);
              }
            }
            else
            {
              v5 += 6;
              szBSPDir = g_pGameConfig->szBSPDir;
              v19 = v3;
              do
              {
                v20 = *szBSPDir;
                *v19++ = *szBSPDir++;
              }
              while ( v20 != 0 );
              v3 += strlen(v3);
            }
          }
          else
          {
            v5 += 6;
            m_szGameExeDir = g_pGameConfig->m_szGameExeDir;
            v16 = v3;
            do
            {
              v17 = *m_szGameExeDir;
              *v16++ = *m_szGameExeDir++;
            }
            while ( v17 != 0 );
            v3 += strlen(v3);
          }
        }
        else
        {
          v12 = pszDocPath;
          v5 += 4;
          v13 = v3 - pszDocPath;
          do
          {
            v14 = *v12;
            v12[v13] = *v12;
            ++v12;
          }
          while ( v14 != 0 );
          v3 += strlen(v3);
        }
      }
      else
      {
        v9 = pszDocExt;
        v5 += 3;
        v10 = v3 - pszDocExt;
        do
        {
          v11 = *v9;
          v9[v10] = *v9;
          ++v9;
        }
        while ( v11 != 0 );
        v3 += strlen(v3);
      }
    }
    else
    {
      v6 = pszDocName;
      v5 += 4;
      v7 = v3 - pszDocName;
      do
      {
        v8 = *v6;
        v6[v7] = *v6;
        ++v6;
      }
      while ( v8 != 0 );
      v3 += strlen(v3);
    }
  }
  while ( *v5 != 0 );
  if ( v4 != 0 )
    *(_WORD *)v3 = 34;
  else
    *v3 = 0;
}

//------------------------------------------------------------------------------
// Address: 0x1009F340
// Name: RemoveQuotes
// Source: json
//------------------------------------------------------------------------------
void __usercall RemoveQuotes(char *pBuf@<esi>)
{
  char *v1; // eax
  char v2; // cl

  if ( *pBuf == 34 )
  {
    v1 = pBuf + 1;
    do
    {
      v2 = *v1;
      *(v1 - 1) = *v1;
      ++v1;
    }
    while ( v2 != 0 );
  }
  if ( pBuf[strlen(pBuf) - 1] == 34 )
    pBuf[strlen(pBuf) - 1] = 0;
}

//------------------------------------------------------------------------------
// Address: 0x1009F450
// Name: public: CCommandExecuter::~CCommandExecuter(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCommandExecuter::~CCommandExecuter(CCommandExecuter *this)
{
  CUtlVector<ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>> *,CUtlMemory<ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>> *,int>>::PurgeAndDeleteElements(this: &this->m_Commands);
  this->m_Commands.m_Size = 0;
  if ( this->m_Commands.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Commands.m_Memory.m_pMemory != nullptr )
    {
      free(pMem: this->m_Commands.m_Memory.m_pMemory);
      this->m_Commands.m_Memory.m_pMemory = nullptr;
    }
    this->m_Commands.m_Memory.m_nAllocationCount = 0;
  }
  this->m_Commands.m_pElements = this->m_Commands.m_Memory.m_pMemory;
  if ( this->m_Commands.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Commands.m_Memory.m_pMemory != nullptr )
    {
      free(pMem: this->m_Commands.m_Memory.m_pMemory);
      this->m_Commands.m_Memory.m_pMemory = nullptr;
    }
    this->m_Commands.m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1009F4E0
// Name: public: void CCommandExecuter::AddCommandVA(char const __near *,...)
// Source: json
//------------------------------------------------------------------------------
void CCommandExecuter::AddCommandVA(CCommandExecuter *this, char *pStr, ...)
{
  ATL::CSimpleStringT<char,0> *v2; // esi
  CAfxStringMgr *StringManager; // eax
  ATL::CSimpleStringT<char,0> *v4; // ebx
  int m_Size; // edi
  int m_nAllocationCount; // eax
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > **m_pMemory; // ecx
  int v8; // eax
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > **v9; // eax
  char pDest[8192]; // [esp+8h] [ebp-2010h] BYREF
  ATL::CSimpleStringT<char,0> *v11; // [esp+2008h] [ebp-10h]
  int v12; // [esp+2014h] [ebp-4h]
  va_list params; // [esp+2028h] [ebp+10h] BYREF

  va_start(params, pStr);
  V_vsnprintf(pDest, maxLen: 0x2000, pFormat: pStr, params);
  v2 = (ATL::CSimpleStringT<char,0> *)operator new(nSize: 4u);
  v11 = v2;
  if ( v2 != nullptr )
  {
    StringManager = AfxGetStringManager();
    if ( StringManager == nullptr )
      ATL::AtlThrowImpl(hr: -2147467259);
    v2->m_pszData = (char *)&StringManager->GetNilString(this: StringManager)[1];
    v12 = -1;
    v4 = v2;
  }
  else
  {
    v4 = nullptr;
  }
  ATL::CSimpleStringT<char,0>::SetString(this: v4, pszSrc: pDest, nLength: strlen(pDest));
  m_Size = this->m_Commands.m_Size;
  m_nAllocationCount = this->m_Commands.m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CVisGroup *,int>::Grow((CUtlMemory<CCullTreeNode *,int> *)this, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Commands.m_Size;
  m_pMemory = this->m_Commands.m_Memory.m_pMemory;
  v8 = this->m_Commands.m_Size - m_Size - 1;
  this->m_Commands.m_pElements = this->m_Commands.m_Memory.m_pMemory;
  if ( v8 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v8);
  v9 = &this->m_Commands.m_Memory.m_pMemory[m_Size];
  if ( v9 != nullptr )
    *v9 = (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)v4;
}

//------------------------------------------------------------------------------
// Address: 0x1009F5F0
// Name: public: void CCommandExecuter::EncodeCommand(char const __near *,class ATL::CStringT<char,class StrTraitMFC<char,class ATL::ChTraitsCRT<char>>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCommandExecuter::EncodeCommand(
        CCommandExecuter *this,
        const char *pCommand,
        ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *out)
{
  signed int v3; // ebx
  char *v4; // esi
  signed int i; // eax
  int v6; // eax

  v3 = std::char_traits<char>::length(str: pCommand);
  v4 = (char *)operator new[](nSize: 2 * v3 + 1);
  for ( i = 0; i < v3; ++i )
  {
    v4[2 * i] = (pCommand[i] & 0xF) + 97;
    v4[2 * i + 1] = ((unsigned __int8)pCommand[i] >> 4) + 97;
  }
  v4[2 * v3] = 0;
  if ( v4 != nullptr )
    v6 = strlen(v4);
  else
    v6 = 0;
  ATL::CSimpleStringT<char,0>::SetString(this: out, pszSrc: v4, nLength: v6);
  operator delete(p: v4);
}

//------------------------------------------------------------------------------
// Address: 0x1009F670
// Name: public: void CCommandExecuter::AddCommandWithArgList(char __near * __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCommandExecuter::AddCommandWithArgList(CCommandExecuter *this, char **ppParms)
{
  ATL::CSimpleStringT<char,0> *v3; // esi
  CAfxStringMgr *StringManager; // eax
  ATL::CSimpleStringT<char,0> *v5; // ebx
  char **v6; // esi
  char *i; // eax
  int m_Size; // esi
  int m_nAllocationCount; // eax
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > **m_pMemory; // ecx
  int v11; // eax
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > **v12; // esi

  v3 = (ATL::CSimpleStringT<char,0> *)operator new(nSize: 4u);
  if ( v3 != nullptr )
  {
    StringManager = AfxGetStringManager();
    if ( StringManager == nullptr )
      ATL::AtlThrowImpl(hr: -2147467259);
    v3->m_pszData = (char *)&StringManager->GetNilString(this: StringManager)[1];
    v5 = v3;
  }
  else
  {
    v5 = nullptr;
  }
  v6 = ppParms;
  for ( i = *ppParms; i != nullptr; ++v6 )
  {
    ATL::CSimpleStringT<char,0>::Append(this: v5, pszSrc: i, nLength: strlen(i));
    ATL::CSimpleStringT<char,0>::Append(this: v5, pszSrc: " ", nLength: 1);
    i = v6[1];
  }
  m_Size = this->m_Commands.m_Size;
  m_nAllocationCount = this->m_Commands.m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CVisGroup *,int>::Grow((CUtlMemory<CCullTreeNode *,int> *)this, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Commands.m_Size;
  m_pMemory = this->m_Commands.m_Memory.m_pMemory;
  v11 = this->m_Commands.m_Size - m_Size - 1;
  this->m_Commands.m_pElements = this->m_Commands.m_Memory.m_pMemory;
  if ( v11 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v11);
  v12 = &this->m_Commands.m_Memory.m_pMemory[m_Size];
  if ( v12 != nullptr )
    *v12 = (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)v5;
}

//------------------------------------------------------------------------------
// Address: 0x1009F780
// Name: public: void CCommandExecuter::Launch(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCommandExecuter::Launch(CCommandExecuter *this)
{
  int v1; // ebx
  CAfxStringMgr *StringManager; // eax
  char *m_pszData; // esi
  char *v5; // eax
  char szFilename[260]; // [esp+8h] [ebp-16Ch] BYREF
  _STARTUPINFOA StartupInfo; // [esp+10Ch] [ebp-68h] BYREF
  _PROCESS_INFORMATION pi; // [esp+150h] [ebp-24h] BYREF
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > encodedCommand; // [esp+160h] [ebp-14h] BYREF
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > fullCommand; // [esp+164h] [ebp-10h] BYREF
  int v11; // [esp+170h] [ebp-4h]

  v1 = 0;
  GetModuleFileNameA(hModule: nullptr, lpFilename: szFilename, nSize: 0x104u);
  V_StripLastDir(dirName: szFilename, maxlen: 260);
  V_AppendSlash(pStr: szFilename, strSize: 260);
  if ( LOBYTE(AfxGetModuleState()->m_pCurrentWinApp[4].m_dwRef) != 0 )
  {
    V_strncat(pDest: szFilename, pSrc: "bin", destBufferSize: 0x104u, max_chars_to_copy: -1);
    V_AppendSlash(pStr: szFilename, strSize: 260);
  }
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>(
    this: &fullCommand,
    pszSrc: szFilename);
  v11 = 0;
  ATL::CSimpleStringT<char,0>::Append(this: &fullCommand, pszSrc: "hammer_run_map_launcher.exe ", nLength: 28);
  if ( this->m_bWaitForKeypress )
    ATL::CSimpleStringT<char,0>::Append(this: &fullCommand, pszSrc: "-WaitForKeypress ", nLength: 17);
  if ( this->m_Commands.m_Size > 0 )
  {
    do
    {
      StringManager = AfxGetStringManager();
      if ( StringManager == nullptr )
        ATL::AtlThrowImpl(hr: -2147467259);
      encodedCommand.m_pszData = (char *)&StringManager->GetNilString(this: StringManager)[1];
      LOBYTE(v11) = 2;
      CCommandExecuter::EncodeCommand(
        this,
        pCommand: this->m_Commands.m_Memory.m_pMemory[v1]->m_pszData,
        out: &encodedCommand);
      m_pszData = encodedCommand.m_pszData;
      ATL::CSimpleStringT<char,0>::Append(
        this: &fullCommand,
        pszSrc: encodedCommand.m_pszData,
        nLength: *((_DWORD *)encodedCommand.m_pszData - 3));
      ATL::CSimpleStringT<char,0>::Append(this: &fullCommand, pszSrc: " ", nLength: 1);
      LOBYTE(v11) = 0;
      if ( _InterlockedDecrement((volatile signed __int32 *)m_pszData - 1) <= 0 )
        (*(void (__thiscall **)(_DWORD, char *))(**((_DWORD **)m_pszData - 4) + 4))(
          a1: *((_DWORD *)m_pszData - 4),
          a2: m_pszData - 16);
      ++v1;
    }
    while ( v1 < this->m_Commands.m_Size );
  }
  memset(dst: (unsigned __int8 *)&StartupInfo, value: 0, count: sizeof(StartupInfo));
  StartupInfo.cb = 68;
  CreateProcessA(
    lpApplicationName: nullptr,
    lpCommandLine: fullCommand.m_pszData,
    lpProcessAttributes: nullptr,
    lpThreadAttributes: nullptr,
    bInheritHandles: false,
    dwCreationFlags: 0x10u,
    lpEnvironment: nullptr,
    lpCurrentDirectory: nullptr,
    lpStartupInfo: &StartupInfo,
    lpProcessInformation: &pi);
  v11 = -1;
  v5 = fullCommand.m_pszData - 16;
  if ( _InterlockedDecrement((volatile signed __int32 *)fullCommand.m_pszData - 1) <= 0 )
    (*(void (__stdcall **)(char *))(**(_DWORD **)v5 + 4))(a1: v5);
}

//------------------------------------------------------------------------------
// Address: 0x1009F960
// Name: bool RunCommands(class CArray<struct CCOMMAND,struct CCOMMAND __near &> __near &,char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
char __cdecl RunCommands(CArray<CCOMMAND,CCOMMAND &> *Commands, const char *pszOrigDocName, bool bWaitForKeypress)
{
  _BYTE *v3; // eax
  _BYTE *v4; // esi
  unsigned int v5; // eax
  unsigned int v6; // eax
  unsigned __int8 *v7; // eax
  unsigned __int8 v8; // cl
  _BYTE *v9; // eax
  unsigned __int8 *v10; // ecx
  unsigned __int8 v11; // dl
  _BYTE *v12; // eax
  _BYTE *v13; // esi
  unsigned int v14; // eax
  unsigned int v15; // eax
  char *v16; // eax
  char v17; // cl
  _BYTE *v18; // eax
  char *v19; // ecx
  char v20; // dl
  CArray<CCOMMAND,CCOMMAND &> *v21; // edx
  int m_nSize; // esi
  int v23; // eax
  int v24; // ecx
  char *v25; // esi
  int v26; // edi
  char *v27; // eax
  int v28; // edx
  int v29; // eax
  char *v30; // edi
  char *v31; // esi
  char *v32; // esi
  char *v33; // edi
  char *v34; // esi
  char *v35; // esi
  CGridNav *m_pGridNav; // edi
  char *v37; // esi
  char *v38; // eax
  char v39; // cl
  unsigned int v40; // kr00_4
  int m_nGrowSize; // esi
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > **m_pMemory; // eax
  char pszDst[1300]; // [esp+8h] [ebp-10ECh] BYREF
  char v45[1300]; // [esp+51Ch] [ebp-BD8h] BYREF
  char pnbuf[260]; // [esp+A30h] [ebp-6C4h] BYREF
  unsigned __int8 v47[260]; // [esp+B34h] [ebp-5C0h] BYREF
  unsigned __int8 v48[260]; // [esp+C38h] [ebp-4BCh] BYREF
  CHAR szShortPath[260]; // [esp+D3Ch] [ebp-3B8h] BYREF
  char pDest; // [esp+E40h] [ebp-2B4h] BYREF
  _BYTE v51[3]; // [esp+E41h] [ebp-2B3h] BYREF
  CHAR Buffer[260]; // [esp+F44h] [ebp-1B0h] BYREF
  char *ppParms; // [esp+1048h] [ebp-ACh] BYREF
  char *pBuf; // [esp+104Ch] [ebp-A8h]
  char *s2; // [esp+1050h] [ebp-A4h]
  int v56; // [esp+10C8h] [ebp-2Ch]
  int v57; // [esp+10CCh] [ebp-28h]
  CCommandExecuter v58; // [esp+10D0h] [ebp-24h] BYREF
  int v59; // [esp+10F0h] [ebp-4h]
  int v60; // [esp+1104h] [ebp+10h]

  s_bRunsCommands = true;
  _getcwd(pnbuf, maxlen: 260);
  memset(Buffer, 0, sizeof(Buffer));
  memset(v47, 0, sizeof(v47));
  memset(v48, 0, sizeof(v48));
  memset(szShortPath, 0, sizeof(szShortPath));
  GetFullPathNameA(lpFileName: pszOrigDocName, nBufferLength: 0x104u, lpBuffer: Buffer, lpFilePart: nullptr);
  GetShortPathNameA(lpszLongPath: pszOrigDocName, lpszShortPath: szShortPath, cchBuffer: 0x104u);
  strrchr(string: (unsigned __int8 *)Buffer, chr: 0x2Eu);
  v4 = v3;
  if ( v3 != nullptr )
  {
    strrchr(string: (unsigned __int8 *)Buffer, chr: 0x5Cu);
    if ( v5 < (unsigned int)v4 )
    {
      strrchr(string: (unsigned __int8 *)Buffer, chr: 0x2Fu);
      if ( v6 < (unsigned int)v4 )
      {
        v7 = v4 + 1;
        do
        {
          v8 = *v7;
          v7[v48 - (v4 + 1)] = *v7;
          ++v7;
        }
        while ( v8 != 0 );
        *v4 = 0;
      }
    }
  }
  strrchr(string: (unsigned __int8 *)Buffer, chr: 0x5Cu);
  if ( v9 != nullptr || (strrchr(string: (unsigned __int8 *)Buffer, chr: 0x2Fu), v9 != nullptr) )
  {
    v10 = v9 + 1;
    do
    {
      v11 = *v10;
      v10[v47 - (v9 + 1)] = *v10;
      ++v10;
    }
    while ( v11 != 0 );
    *v9 = 0;
  }
  strrchr(string: (unsigned __int8 *)szShortPath, chr: 0x2Eu);
  v13 = v12;
  if ( v12 != nullptr )
  {
    strrchr(string: (unsigned __int8 *)szShortPath, chr: 0x5Cu);
    if ( v14 < (unsigned int)v13 )
    {
      strrchr(string: (unsigned __int8 *)szShortPath, chr: 0x2Fu);
      if ( v15 < (unsigned int)v13 )
      {
        v16 = v13 + 1;
        do
        {
          v17 = *v16;
          v16[&pDest - (v13 + 1)] = *v16;
          ++v16;
        }
        while ( v17 != 0 );
        *v13 = 0;
      }
    }
  }
  strrchr(string: (unsigned __int8 *)szShortPath, chr: 0x5Cu);
  if ( v18 != nullptr || (strrchr(string: (unsigned __int8 *)szShortPath, chr: 0x2Fu), v18 != nullptr) )
  {
    v19 = v18 + 1;
    do
    {
      v20 = *v19;
      v19[&pDest - (v18 + 1)] = *v19;
      ++v19;
    }
    while ( v20 != 0 );
    *v18 = 0;
  }
  memset(&v58, 0, 20);
  v58.m_bWaitForKeypress = bWaitForKeypress;
  v59 = 2;
  v21 = Commands;
  m_nSize = Commands->m_nSize;
  v23 = 0;
  if ( m_nSize != 0 )
  {
    v24 = 0;
    while ( 1 )
    {
      v56 = m_nSize - 1;
      if ( v23 < 0 || v23 >= v21->m_nSize )
        AfxThrowInvalidArgException();
      v25 = (char *)v21->m_pData + v24;
      v60 = v23 + 1;
      v57 = v24 + 804;
      if ( (v25[8] != 0 || *((_DWORD *)v25 + 1) != 0) && *(_DWORD *)v25 != 0 )
      {
        pszDocName = (char *)v47;
        pszDocExt = (char *)v48;
        pszDocPath = Buffer;
        FixGameVars(pszSrc: v25 + 8, pszDst, bUseQuotes: 1);
        FixGameVars(pszSrc: v25 + 268, pszDst: v45, bUseQuotes: 1);
        v26 = 0;
        ppParms = pszDst;
        v27 = v45;
        v28 = 1;
        if ( v45[0] != 0 )
        {
          do
          {
            (&ppParms)[v28++] = v27;
            if ( *v27 == 0 )
              break;
            while ( *v27 != 32 )
            {
              if ( *v27 == 34 )
              {
                do
                  ++v27;
                while ( *v27 != 34 );
                if ( v27[1] == 0 )
                  v26 = 1;
                v27[1] = 0;
                for ( v27 += 2; *v27 == 32; ++v27 )
                  ;
                goto LABEL_42;
              }
              if ( *++v27 == 0 )
                goto LABEL_44;
            }
            for ( *v27++ = 0; *v27 == 32; ++v27 )
              ;
LABEL_42:
            ;
          }
          while ( *v27 != 0 && v26 == 0 );
        }
LABEL_44:
        v29 = *((_DWORD *)v25 + 1);
        (&ppParms)[v28] = nullptr;
        if ( v29 != 0 )
        {
          if ( v29 == 257 && v28 == 3 )
          {
            v30 = pBuf;
            RemoveQuotes(pBuf);
            v31 = s2;
            RemoveQuotes(pBuf: s2);
            if ( _V_stricmp(s1: v30, s2: v31) != 0 )
              CCommandExecuter::AddCommandVA(this: &v58, pStr: "copy \"%s\" \"%s\"", v30, v31);
          }
          else if ( v29 == 258 && v28 == 2 )
          {
            v32 = pBuf;
            RemoveQuotes(pBuf);
            CCommandExecuter::AddCommandVA(this: &v58, pStr: "del \"%s\"", v32);
          }
          else if ( v29 == 259 && v28 == 3 )
          {
            v33 = pBuf;
            RemoveQuotes(pBuf);
            v34 = s2;
            RemoveQuotes(pBuf: s2);
            CCommandExecuter::AddCommandVA(this: &v58, pStr: "ren \"%s\" \"%s\"", v33, v34);
          }
          else if ( v29 == 256 && v28 == 2 )
          {
            v35 = pBuf;
            RemoveQuotes(pBuf);
            CCommandExecuter::AddCommandVA(this: &v58, pStr: "cd \"%s\"", v35);
          }
          else if ( v29 == 260 && v28 == 2 && CMapDoc::m_pMapDoc != nullptr )
          {
            m_pGridNav = CMapDoc::m_pMapDoc->m_pGridNav;
            if ( m_pGridNav != nullptr && CGridNav::sm_bEnabled )
            {
              v37 = pBuf;
              RemoveQuotes(pBuf);
              CGridNav::GenerateGridNavFile(this: m_pGridNav, a2: 0, pFileFullPath: v37);
            }
          }
        }
        else
        {
          V_strncpy(&pDest, pSrc: pszDst, maxLen: 260);
          if ( pDest == 34 )
          {
            v38 = v51;
            do
            {
              v39 = *v38;
              *(v38 - 1) = *v38;
              ++v38;
            }
            while ( v39 != 0 );
          }
          v40 = strlen(&pDest);
          if ( szShortPath[v40 + 259] == 34 )
            szShortPath[v40 + 259] = 0;
          V_StripFilename(path: &pDest);
          CCommandExecuter::AddCommandVA(this: &v58, pStr: "cd \"%s\"", &pDest);
          CCommandExecuter::AddCommandWithArgList(this: &v58, &ppParms);
        }
      }
      m_nSize = v56;
      if ( v56 == 0 )
        break;
      v21 = Commands;
      v24 = v57;
      v23 = v60;
    }
  }
  CCommandExecuter::Launch(this: &v58);
  s_bRunsCommands = false;
  v59 = 3;
  CUtlVector<ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>> *,CUtlMemory<ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>> *,int>>::PurgeAndDeleteElements(this: &v58.m_Commands);
  v59 = 4;
  m_nGrowSize = v58.m_Commands.m_Memory.m_nGrowSize;
  m_pMemory = v58.m_Commands.m_Memory.m_pMemory;
  v58.m_Commands.m_Size = 0;
  if ( v58.m_Commands.m_Memory.m_nGrowSize >= 0 )
  {
    if ( v58.m_Commands.m_Memory.m_pMemory != nullptr )
    {
      free(pMem: v58.m_Commands.m_Memory.m_pMemory);
      m_pMemory = nullptr;
      v58.m_Commands.m_Memory.m_pMemory = nullptr;
    }
    v58.m_Commands.m_Memory.m_nAllocationCount = 0;
  }
  v58.m_Commands.m_pElements = m_pMemory;
  v59 = -1;
  if ( m_nGrowSize >= 0 )
  {
    if ( m_pMemory != nullptr )
    {
      free(pMem: m_pMemory);
      v58.m_Commands.m_Memory.m_pMemory = nullptr;
    }
    v58.m_Commands.m_Memory.m_nAllocationCount = 0;
  }
  return 1;
}
